#ifndef _17300_H_
#define _17300_H_

#include "global.h"

typedef struct unk_D_800ABCC0_008 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
} unk_D_800ABCC0_008; // size = 0xA

typedef struct unk_D_800ABCC0 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ unk_D_86002F58_004_000_040_004* unk_04;
    /* 0x08 */ unk_D_800ABCC0_008* unk_08;
    /* 0x0C */ s16* unk_0C;
    /* 0x10 */ s16* unk_10;
    /* 0x14 */ s16* unk_14;
} unk_D_800ABCC0; // size = 0x18

f32 func_80016700(unk_D_800ABCC0* arg0, s32 arg1);
s16 func_800167B4(unk_D_800ABCC0* arg0, s32 arg1);
f32 func_80016848(unk_D_800ABCC0* arg0, s32 arg1);
f32 func_80016934(Vec3s* arg0, s16 arg1, s16 arg2);
f32 func_80016D20(unk_D_800ABCC0* arg0, s32 arg1);
s16 func_80016DE0(unk_D_800ABCC0* arg0, s32 arg1);
f32 func_80016F20(unk_D_800ABCC0* arg0, s32 arg1);
void func_80017080(void);
void func_80017090(unk_D_86002F58_004_000_040* arg0, u16 arg1, s32 arg2);
void func_80017188(void);
void func_800171A8(Vec3f* arg0, Vec3s* arg1, Vec3f* arg2, s32 arg3);
void func_800173CC(unk_D_86002F58_004_000* arg0);
s32 func_800173DC(unk_D_86002F58_004_000* arg0, s16 arg1, void* arg2, s32 arg3);
s32 func_80017454(unk_D_86002F58_004_000* arg0, s32 arg1);
void func_80017464(unk_D_86002F58_004_000* arg0, s16 arg1);
s32 func_80017484(unk_D_86002F58_004_000* arg0, s16 arg1);
s32 func_800174E4(unk_D_86002F58_004_000* arg0);
s32 func_80017514(unk_D_86002F58_004_000* arg0);


#endif // _17300_H_
