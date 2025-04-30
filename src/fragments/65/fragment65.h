#ifndef _FRAGMENT65_H_
#define _FRAGMENT65_H_

#include "global.h"

typedef struct unk_D_84A03138 {
    /* 0x00 */ u8 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char* unk_08;
} unk_D_84A03138; // size = 0xC

typedef struct unk_D_84A02F00 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s8 unk_14;
    /* 0x15 */ s8 unk_15;
    /* 0x16 */ s8 unk_16;
    /* 0x17 */ s8 unk_17;
    /* 0x18 */ Color_RGBA8 unk_18;
    /* 0x1C */ u8* unk_1C;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ u8* unk_24;
} unk_D_84A02F00; // size = 0x28

void func_84A00020(u8* arg0, u8* arg1, u8 arg2);
void func_84A003BC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8* arg5, f32 arg6);
void func_84A00630(void);
void func_84A00638(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, f32 arg5);
void func_84A008A8(void);
void func_84A00B44(void);
void func_84A00E98(void);
void func_84A00FEC(void);
void func_84A012B8(void);
void func_84A01424(unk_D_84A02F00* arg0, u8 arg1, u8 arg2);
void func_84A01770(unk_D_84A02F00* arg0, u8 arg1, u8 arg2);
void func_84A01BAC(void);
void func_84A01DAC(void);
void func_84A01EE0(void);
s32 func_84A02074(void);
s32 func_84A0207C(void);
void func_84A02304(void);
void func_84A02410(void);
void func_84A02434(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s32 func_84A02580(void);
s32 func_84A02898(void);
s16 func_84A02A34(s16 arg0);
s16 func_84A02B70(s16 arg0);
s32 func_84A02D14(s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT65_H_
