#ifndef _38BB0_H_
#define _38BB0_H_

#include "global.h"

typedef struct sp38_func_800373D8 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ u32 unk_18;
    /* 0x1C */ u32 unk_1C;
    /* 0x20 */ u32 unk_20;
    /* 0x24 */ u32 unk_24;
    /* 0x28 */ u32 unk_28;
    /* 0x2C */ u32 unk_2C;
} sp38_func_800373D8; // size >= 0x30

extern ALHeap* D_800FC810;

void func_80038B68(sp38_func_800373D8*);
void func_80038E98(s32, s32);
s32 func_80038F30(s32, s32);
s32 func_80039024(s32, s32, s32, s32, u32, s32);
void func_8003916C(s32, s32);
s32 func_80039204(s32);
void func_800392A8(s32, s32);
s32 func_80039354(s32);
void func_800393DC(s32, s32);
void func_80039534(s32, f32);
void func_800395FC(s32, s32);
void func_8003979C(s32, s32);
void func_800397BC(s32);
void func_8003986C(s32);
void func_800398F0(s32);
void func_80039940(void);
s32 func_80039A7C(s32, s32, s32);
void func_80039B88(s32, s32, s32, s32);

#endif // _38BB0_H_
