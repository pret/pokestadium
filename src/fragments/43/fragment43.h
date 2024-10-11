#ifndef _FRAGMENT43_H_
#define _FRAGMENT43_H_

#include "global.h"
#include "30640.h"
#include "src/fragments/31/fragment31.h"

typedef struct unk_D_83402EE0 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ unk_D_83402EE0_00A unk_0A[10];
    /* 0x50 */ Vec3f unk_50;
    /* 0x5C */ Vec3f unk_5C;
    /* 0x68 */ u32 unk_68;
    /* 0x6C */ u8 unk_6C;
    /* 0x6D */ char unk6D[3];
    /* 0x70 */ unk_D_83402EE0_070 unk_70;
} unk_D_83402EE0; // size = 0x8C

extern s32 D_83402E20;
extern s32 D_83402E24;
extern unk_D_83402EE0 D_83402EE0[];

extern unk_D_83407AC8 D_83407AC8;
extern u8 D_83407ACA;

void func_8340051C(void);

#endif // _FRAGMENT43_H_


