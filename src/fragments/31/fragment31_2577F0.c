#include "fragment31.h"
#include "32D10.h"
#include "12D80.h"

typedef struct unk_arg1_func_81002530 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
} unk_arg1_func_81002530; // size >= 0x8

typedef struct unk_arg1_func_810027E0 {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ unk_arg1_func_81002530* unk_14;
    /* 0x18 */ Gfx* unk_18;
} unk_arg1_func_810027E0; // size >= 0x1C

void func_81002530(Gfx*, unk_arg1_func_81002530*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2577F0/func_81002530.s")

void func_810027E0(s32 arg0, unk_arg1_func_810027E0* arg1) {
    Gfx* gfx;
    s32 sp18;

    if (arg0 == 2) {
        sp18 = arg1->unk_14;
        gfx = (Gfx*)func_80005F5C(0xF0);
        arg1->unk_18 = gfx;
        func_81002530(gfx, sp18);
    }
}
