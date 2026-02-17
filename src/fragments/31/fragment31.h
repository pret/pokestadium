#ifndef _FRAGMENT31_H_
#define _FRAGMENT31_H_

#include "global.h"
#include "30640.h"

typedef struct DisplayListAddresses {
    /* 0x00 */ u32 segments[2];
    /* 0x08 */ u32 textures[1];
} DisplayListAddresses; // size = 0xC

typedef struct DisplayListState {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ DisplayListAddresses* addresses;
    /* 0x18 */ Gfx* gfx;
} DisplayListState; // size = 0x1C

typedef struct unk_arg0_func_81002174 {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ s8 unk_06;
} unk_arg0_func_81002174; // size >= 0x7

typedef struct unk_arg0_func_81002260 {
    /* 0x00 */ char unk00[0x1A];
    /* 0x1A */ s16 unk_1A;
} unk_arg0_func_81002260; // size >= 0x1C

void func_810007A8(unk_D_86002F58_004_000*);
void func_810007F8(void);
void func_81002174(unk_D_83402EE0_00A*);
void func_81002260(unk_arg0_func_81002260*, unk_arg0_func_81002174*);

#endif // _FRAGMENT31_H_
