#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

struct Controller {
    /* 0x00 */ s16 contId;
    /* 0x02 */ s16 rawStickX;
    /* 0x04 */ s16 rawStickY;
    /* 0x06 */ u16 buttonDown;
    /* 0x08 */ u16 buttonPressed;
    /* 0x0A */ u16 unkA;
    char fillerC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ float stickMag;
    /* 0x14 */ float stickX;
    /* 0x18 */ float stickY;
    /* 0x1C */ OSContStatus *statusData;
    /* 0x20 */ OSContPad *controllerData;
};

extern struct Controller gControllers[4];
extern OSMesgQueue gSIEventMesgQueue;
extern u8 gControllerBits;
extern u8 gEepromProbe;
extern OSContStatus gControllerStatuses[4];
extern OSContPad gControllerPads[4];
extern OSMesg gSIEventMesgBuf[1];
extern OSMesg gEepromMesgBuf[1];
extern OSMesgQueue gEepromMesgQueue;

void Cont_InitControllers(void);
void Cont_AdjustAnalogStick(struct Controller *controller);
void Cont_StartReadInputs(void);
void Cont_ReadInputs(void);
u8 Cont_GetControllerBits(void);
s32 Cont_IsEepromPresent(void);
s32 Cont_AttemptReadEeprom(u8* buffer, u32 size, s32 inaddr);
s32 Cont_AttemptWriteEeprom(u8* buffer, u32 size, s32 inaddr);
void Cont_BlockEepromQueue(void);
void Cont_NoBlockEepromQueue(void);
void Cont_InitEepromQueue(void);
u8 Cont_SetupControllers(void);

#endif // _CONTROLLER_H_
