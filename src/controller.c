#include "global.h"
#include "controller.h"
#include "gb_tower.h"
#include "math_util.h"

Controller* gPlayer1Controller = &gControllers[0];
Controller* gPlayer2Controller = &gControllers[1];
Controller* gPlayer3Controller = &gControllers[2];
Controller* gPlayer4Controller = &gControllers[3];

Controller gControllers[4];
OSMesgQueue gSIEventMesgQueue;
u8 gControllerBits;
u8 gEepromProbe;
OSContStatus gControllerStatuses[4];
OSContPad gControllerPads[4];
OSMesg gSIEventMesgBuf[1];
OSMesg gEepromMesgBuf[1];
OSMesgQueue gEepromMesgQueue;

/*
 * Initialize the gControllers structs. Clear each member, then set their cont
 * id and set the status and pads pointers.
 */
void Cont_InitControllers(void) {
    int i;

    // clear each gControllers member.
    for (i = 0; i < MAXCONTROLLERS; i++) {
        bzero((void*)&gControllers[i], sizeof(Controller));
    }

    // Initialize each connected controller.
    for (i = 0; i < MAXCONTROLLERS; i++) {
        // If the bit is set in this bitfield for each iteration, it means
        // the controller is connected. Set the ID and pointers respectively.
        if (gControllerBits & (1 << i)) {
            gControllers[i].contId = (i + 1); // indexed by 1. (cont 1, cont 2, etc)
            gControllers[i].statusData = &gControllerStatuses[i];
            gControllers[i].controllerData = &gControllerPads[i];
        }
    }
}

/*
 * Take the updated controller struct and calculate
 * the new x, y, and distance floats.
 */
void Cont_AdjustAnalogStick(Controller* controller) {
    // reset the controller's x and y floats.
    controller->stickX = 0.0f;
    controller->stickY = 0.0f;

    // modulate the rawStickX and rawStickY to be the new f32 values by adding/subtracting 6.
    if (controller->rawStickX <= -8) {
        controller->stickX = controller->rawStickX + 6;
    }

    if (controller->rawStickX >= 8) {
        controller->stickX = controller->rawStickX - 6;
    }

    if (controller->rawStickY <= -8) {
        controller->stickY = controller->rawStickY + 6;
    }

    if (controller->rawStickY >= 8) {
        controller->stickY = controller->rawStickY - 6;
    }

    // calculate f32 magnitude from the center by vector length.
    controller->stickMag = sqrtf(controller->stickX * controller->stickX + controller->stickY * controller->stickY);

    // magnitude cannot exceed 64.0f: if it does, modify the values appropriately to
    // flatten the values down to the allowed maximum value.
    if (controller->stickMag > 64) {
        controller->stickX *= 64 / controller->stickMag;
        controller->stickY *= 64 / controller->stickMag;
        controller->stickMag = 64;
    }

    if (controller->stickMag > 0.0f) {
        controller->angle = MathUtil_Atan2s(-controller->stickY, controller->stickX);
    }
}

/*
 * Start the reading of the controller inputs into the current structs.
 */
void Cont_StartReadInputs(void) {
    Cont_BlockEepromQueue();
    osContStartReadData(&gSIEventMesgQueue);
}

/*
 * Read in the inputs into the pads and then update the controller structs accordingly based on
 * new button masks and held button masks.
 */
void Cont_ReadInputs(void) {
    s32 i;
    Controller* controller = &gControllers[0];

    osRecvMesg(&gSIEventMesgQueue, NULL, OS_MESG_BLOCK);
    osContGetReadData(&gControllerPads[0]);
    Cont_NoBlockEepromQueue();

    for (i = 0; i < 4; i++, controller++) {
        // if the contId is not 0, it means the controller is initialized.
        if (controller->contId != 0) {
            controller->rawStickX = controller->controllerData->stick_x;
            controller->rawStickY = controller->controllerData->stick_y;
            controller->buttonPressed =
                controller->controllerData->button & (controller->controllerData->button ^ controller->buttonDown);
            controller->unkA = controller->buttonDown & (controller->controllerData->button ^ controller->buttonDown);
            controller->buttonDown = controller->controllerData->button;

            Cont_AdjustAnalogStick(controller);
        } else {
            controller->buttonPressed = 0;
            controller->unkA = 0;
            controller->buttonDown = 0;
        }
    }
    func_8000B330();
}

/*
 * Retrieve the current controller bits.
 */
u8 Cont_GetControllerBits(void) {
    return gControllerBits;
}

/*
 * Check if an EEPROM is connected. Since probe 0x00 is not connected and
 * 0x01 and 0x02 are otherwise, a non-0 probe means it is connected.
 */
s32 Cont_IsEepromPresent(void) {
    return gEepromProbe != 0;
}

/*
 * Attempt to read from EEPROM up to 4 times given a buffer and size and inaddr.
 * A return of 0 indicates success while -1 is an EEPROM error.
 */
s32 Cont_AttemptReadEeprom(u8* buffer, u32 size, s32 inaddr) {
    s32 result = 1;
    if (gEepromProbe) {
        s32 i = 4;
        Cont_BlockEepromQueue();
        do {
            // Get the number of 8-byte buffers to send, since we are sending in 8
            // byte chunks.
            s32 count = size / 8;
            // this value must be a multiple of 8 due to hardware restrictions as
            // specified by http://n64devkit.square7.ch/n64man/os/osEepromLongRead.htm.
            // Force the value to be a multiple of 8 to adhere to the restrictions.
            s32 address = ALIGN8(inaddr);
            i--;
            // once the result is 0 (success), exit from the loop since the write was successful.
            result = osEepromLongRead(&gSIEventMesgQueue, count, buffer, address);
        } while (i > 0 && result);
        Cont_NoBlockEepromQueue();
    }
    return result;
}

/*
 * Attempt to write to EEPROM up to 4 times given a buffer and size and inaddr.
 * A return of 0 indicates success while -1 is an EEPROM error.
 */
s32 Cont_AttemptWriteEeprom(u8* buffer, u32 size, s32 inaddr) {
    s32 result = 1;
    if (gEepromProbe) {
        s32 i = 4;
        Cont_BlockEepromQueue();
        do {
            // Get the number of 8-byte buffers to send, since we are sending in 8
            // byte chunks.
            s32 count = size / 8;
            // this value must be a multiple of 8 due to hardware restrictions as
            // specified by http://n64devkit.square7.ch/n64man/os/osEepromLongRead.htm.
            // Force the value to be a multiple of 8 to adhere to the restrictions.
            s32 address = ALIGN8(inaddr);
            i--;
            // once the result is 0 (success), exit from the loop since the write was successful.
            result = osEepromLongWrite(&gSIEventMesgQueue, count, buffer, address);
        } while (i > 0 && result);
        Cont_NoBlockEepromQueue();
    }
    return result;
}

/*
 * Run a Block Mesg against the Eeprom queue.
 */
void Cont_BlockEepromQueue(void) {
    osRecvMesg(&gEepromMesgQueue, NULL, OS_MESG_BLOCK);
}

/*
 * Run a No Block Mesg against the Eeprom queue.
 */
void Cont_NoBlockEepromQueue(void) {
    osSendMesg(&gEepromMesgQueue, NULL, OS_MESG_NOBLOCK);
}

/*
 * Initialize the Eeprom Mesg queue.
 */
void Cont_InitEepromQueue(void) {
    osCreateMesgQueue(&gEepromMesgQueue, gEepromMesgBuf, 1);
    osSendMesg(&gEepromMesgQueue, NULL, OS_MESG_NOBLOCK);
}

/*
 * Setup the controllers for initial use by initializing the EEPROM queue
 * and SI Event queues. EEPROM probing was handled by game_init.c in Super
 * Mario 64 which also handled the controllers in the same file. Since
 * Nintendo EAD is also credited with co-developing Pokemon Stadium, this
 * organization may be a holdover from that era.
 */
u8 Cont_SetupControllers(void) {
    Cont_InitEepromQueue();
    osCreateMesgQueue(&gSIEventMesgQueue, gSIEventMesgBuf, 1);
    osSetEventMesg(OS_EVENT_SI, &gSIEventMesgQueue, NULL);
    osContInit(&gSIEventMesgQueue, &gControllerBits, &gControllerStatuses[0]);
    gEepromProbe = osEepromProbe(&gSIEventMesgQueue);
    Cont_InitControllers();
    return gControllerBits;
}
