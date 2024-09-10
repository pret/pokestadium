#include "45720.h"

extern u8 D_800FCEF0[2];
extern u32 D_800FCF00[2];
extern s16 D_800FCF1C[2];

extern s8 D_800785F0;

#pragma GLOBAL_ASM("asm/us/nonmatchings/45720/func_80044B20.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/45720/func_80044CBC.s")

void func_80044D78(u32 arg0, u32 arg1) {
    u32 temp_a0;

    if (arg0 < 2) {
        if (arg1 != 0) {
            D_800FCF1C[arg0] = (f32)D_800FCF00[arg0] / arg1;
        }
        temp_a0 = osSetIntMask(1);
        if (arg1 != 0) {
            D_800FCEF0[arg0] = 5;
        } else {
            D_800FCEF0[arg0] = 1;
        }
        osSetIntMask(temp_a0);
    }
}

s32 func_80044E54(s32 arg0) {
    if (D_800FCEF0[arg0] == 2) {
        return 0;
    }
    return 1;
}

void func_80044E80(s32 arg0) {
    if (arg0 != 0) {
        D_800785F0 = 0;
    } else {
        D_800785F0 = 1;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/45720/func_80044EA4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/45720/func_800455DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/45720/func_800456D0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/45720/func_80045780.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/45720/func_800459E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/45720/func_80045A48.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/45720/func_80045A68.s")
