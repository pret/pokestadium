#include "fragment31.h"
#include "src/6A40.h"
#include "src/12D80.h"

typedef struct unk_arg1_func_81000200 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x04 */ u32 unk_08;
} unk_arg1_func_81000200; // size >= 0xC

typedef struct unk_arg1_func_810002DC {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ unk_arg1_func_81000200* unk_14;
    /* 0x18 */ Gfx* unk_18;
} unk_arg1_func_810002DC; // size >= 0x1C

// Gfx* func_81000200(Gfx* gfx, unk_arg1_func_81000200* arg1, s32 index);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2554C0/func_81000200.s")

void func_810002DC(s32 arg0, unk_arg1_func_810002DC* arg1) {
    Gfx* gfx;
    unk_arg1_func_81000200* sp18;

    if (arg0 == 2) {
        sp18 = arg1->unk_14;
        gfx = func_80005F5C(0x50);
        arg1->unk_18 = gfx;
        func_81000200(gfx, sp18, D_8006F084 & 7);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2554C0/func_81000330.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2554C0/func_81000420.s")
