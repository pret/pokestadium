#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#define BTN_A           0x8000
#define BTN_B           0x4000
#define BTN_Z           0x2000
#define BTN_START       0x1000
#define BTN_DUP         0x0800
#define BTN_DDOWN       0x0400
#define BTN_DLEFT       0x0200
#define BTN_DRIGHT      0x0100
#define BTN_L           0x0020
#define BTN_R           0x0010
#define BTN_CUP         0x0008
#define BTN_CDOWN       0x0004
#define BTN_CLEFT       0x0002
#define BTN_CRIGHT      0x0001

#define BTN_IS_PRESSED(controller, combo) (((controller)->buttonPressed & (combo)) != 0)
#define BTN_IS_DOWN(controller, combo) (((controller)->buttonDown & (combo)) != 0)

typedef struct Controller {
    /* 0x00 */ s16 contId;
    /* 0x02 */ s16 rawStickX;
    /* 0x04 */ s16 rawStickY;
    /* 0x06 */ u16 buttonDown;
    /* 0x08 */ u16 buttonPressed;
    /* 0x0A */ u16 unkA;
    /* 0x0C */ char fillerC[2];
    /* 0x0E */ s16 angle;
    /* 0x10 */ f32 stickMag;
    /* 0x14 */ f32 stickX;
    /* 0x18 */ f32 stickY;
    /* 0x1C */ OSContStatus *statusData;
    /* 0x20 */ OSContPad *controllerData;
} Controller;

extern Controller gControllers[4];
extern OSMesgQueue gSIEventMesgQueue;
extern u8 gControllerBits;
extern u8 gEepromProbe;
extern OSContStatus gControllerStatuses[4];
extern OSContPad gControllerPads[4];
extern OSMesg gSIEventMesgBuf[1];
extern OSMesg gEepromMesgBuf[1];
extern OSMesgQueue gEepromMesgQueue;

extern Controller* gPlayer1Controller;
extern Controller* gPlayer2Controller;
extern Controller* gPlayer3Controller;
extern Controller* gPlayer4Controller;

void Cont_InitControllers(void);
void Cont_AdjustAnalogStick(Controller *controller);
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
