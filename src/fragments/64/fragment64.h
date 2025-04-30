#ifndef _FRAGMENT64_H_
#define _FRAGMENT64_H_

#include "global.h"
#include "src/29BA0.h"

typedef struct unk_D_84803760 {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02[6];
    /* 0x08 */ s8 unk_08[6];
    /* 0x0E */ s8 unk_0E;
    /* 0x0F */ s8 unk_0F;
} unk_D_84803760; // size = 0x10

typedef struct unk_D_848037A0 {
    /* 0x0000 */ s8 unk_0000;
    /* 0x0001 */ s8 unk_0001;
    /* 0x0002 */ s8 unk_0002;
    /* 0x0003 */ s8 unk_0003;
    /* 0x0004 */ char unk0004[1];
    /* 0x0005 */ s8 unk_0005;
    /* 0x0006 */ s8 unk_0006;
    /* 0x0007 */ s8 unk_0007;
    /* 0x0008 */ s8 unk_0008;
    /* 0x0009 */ s8 unk_0009;
    /* 0x000A */ s8 unk_000A;
    /* 0x000B */ s8 unk_000B;
    /* 0x000C */ s8 unk_000C[6];
    /* 0x0012 */ s16 unk_0012;
    /* 0x0014 */ s16 unk_0014;
    /* 0x0016 */ s8 unk_0016;
    /* 0x0017 */ s8 unk_0017;
    /* 0x0018 */ unk_func_80026268_arg0* unk_0018;
    /* 0x001C */ unk_D_800AE540_0004* unk_001C;
    /* 0x0020 */ u16 unk_0020[1][0x640];
    /* 0x0CA0 */ char unk0CA0[0x3E80];
} unk_D_848037A0; // size = 0x4B20

typedef struct unk_D_848035FC {
    /* 0x00 */ Color_RGB8 unk_00;
    /* 0x04 */ u8* unk_04;
} unk_D_848035FC; // size = 0x8

typedef struct unk_D_84803548 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
} unk_D_84803548; // size = 0x4

void func_84800020(void);
void func_84800184(void);
void func_84800458(unk_D_84803760* arg0, unk_D_800AE540_1194* arg1, s32 arg2);
void func_84800530(s32 arg0, s32 arg1, unk_D_84803760* arg2);
s32 func_8480067C(s32 arg0, s32 arg1, s8 arg2, s8 arg3);
void func_848007B8(void);
void func_848009E8(void);
void func_84800C18(s32 arg0, s32 arg1);
void func_84800C68(s32 arg0);
void func_84800CA4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_84800D08(unk_D_848037A0* arg0);
void func_848012A4(s16 arg0, s16 arg1, s16 arg2);
void func_84801340(unk_D_848037A0* arg0);
void func_848015F8(unk_D_848037A0* arg0);
void func_84801800(unk_D_848037A0* arg0);
void func_84801A88(unk_D_848037A0* arg0);
void func_8480218C(unk_D_848037A0* arg0);
void func_8480225C(unk_D_848037A0* arg0);
void func_84802350(void);
s32 func_84802430(unk_D_848037A0* arg0, s8 arg1);
s32 func_8480247C(unk_D_848037A0* arg0);
s32 func_848025A0(unk_D_848037A0* arg0);
void func_84802614(unk_D_848037A0* arg0, s8 arg1, s32 arg2);
void func_84802740(unk_D_848037A0* arg0);
void func_848027F0(Controller* arg0, unk_D_848037A0* arg1);
void func_8480290C(Controller* arg0, unk_D_848037A0* arg1);
void func_84802A44(Controller* arg0, unk_D_848037A0* arg1);
void func_84802A90(Controller* arg0, unk_D_848037A0* arg1);
s32 func_84802B70(s32 arg0, unk_D_848037A0* arg1);
s32 func_84802C40(s32 arg0);
void func_84802D84(unk_D_800AE540_1194* arg0, unk_D_84803760* arg1);
void func_84802DC8(s8* arg0, s32 arg1);
void func_84802E18(void);
void func_84802F7C(s16 arg0, s16 arg1, unk_D_800AE540_0004* arg2, s32 arg3, s32 arg4);
void func_84803110(unk_D_800AE540* arg0);
s32 func_84803368(s32 arg0, s32 arg1);

#endif // _FRAGMENT64_H_
