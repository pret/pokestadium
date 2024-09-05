#ifndef _FRAGMENT11_H_
#define _FRAGMENT11_H_

#include "global.h"
#include "src/11BA0.h"

typedef struct unk_D_8650A528 {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ s32 unk_004;
    /* 0x008 */ s32 unk_008;
    /* 0x00C */ u8 unk_00C;
    /* 0x00D */ s8 unk_00D;
    /* 0x00E */ s8 unk_00E;
    /* 0x010 */ s16 unk_010;
    /* 0x010 */ s16 unk_012;
    /* 0x014 */ unk_D_86002F58_004_000 unk_014;
    /* 0x17C */ unk_D_86404778_190* unk_17C;
} unk_D_8650A528; // size = 0x180

typedef struct unk_D_8650AB30_000 {
    /* 0x00 */ s8 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
} unk_D_8650AB30_000; // size = 0xC

typedef struct unk_D_8650AB30 {
    /* 0x00 */ unk_D_8650AB30_000 unk_00[12];
} unk_D_8650AB30; // size = 0x90

extern s32 D_86509250;
extern s32 D_86509254;
extern u8 D_8650AD84;
extern u8 D_8650AD85;
extern unk_D_8650A528 D_8650A528[4];
extern unk_D_8650A528* D_8650AB28;
extern unk_D_8650AB30 D_8650AB30[4];
extern unk_D_8650AB30* D_8650AD70;
extern u32 D_86506750[];
extern u32 D_86506F50[];
extern u32 D_86507750[];
extern u32 D_86507F50[];
extern u32 D_86508750[];

s8 func_86501FC0(s32, s32);
void func_86502110(s32 arg0);
void func_86502848(void);
void func_865029C0(void);
void func_86502A68(void);
void func_86502BB8(void);

#endif // _FRAGMENT11_H_
