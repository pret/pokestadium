#ifndef _1AB70_H_
#define _1AB70_H_

#include "global.h"
#include "6BC0.h"
#include "29BA0.h"

typedef struct unk_func_88201DA0_034_008 {
    /* 0x00 */ char unk00[0x4];
} unk_func_88201DA0_034_008; // size >= 0x4

typedef struct unk_func_8001B1FC {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk02[0x2];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ char unk0E[0x6];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk18[0x4];
    /* 0x1C */ unk_D_86002F58_004_000_010* unk_1C;
    /* 0x20 */ char unk20[0x8];
    /* 0x28 */ unk_D_80068BB0* unk_28;
    /* 0x2C */ unk_D_80068BB0* unk_2C;
} unk_func_8001B1FC; // size = 0x30

s32 func_8001A024(unk_D_86002F58_004_000_010*, s32, s32, s32);
void func_8001A324(s32, s32, s32, s32);
void func_8001ABAC(s32, s32);
void* func_8001AFD8(s32, s32);
void func_8001B058(void);
void func_8001B0DC(unk_func_88201DA0_034_008*, s32, s32);
unk_func_8001B1FC* func_8001B1FC(unk_D_86002F58_004_000_010*, s32, s32, s32, s32, s32, s32, u8*);
void func_8001B2D8(unk_func_8001B1FC* arg0, unk_func_80026268_arg0* arg1, s32 arg2);
void func_8001B480(void*, s32, s32);
u8* func_8001B9D4(void*);

#endif // _1AB70_H_
