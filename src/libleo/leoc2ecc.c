#include "common.h"

//Tables to add here
extern u8 ganlog[512];
extern u8 glog[512];

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunknown-pragmas"

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leoc2ecc/leoC2_Correction.s")

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leoc2ecc/leoC2_single_ecc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leoc2ecc/leoC2_double_ecc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leoc2ecc/leoC2_3_ecc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leoc2ecc/leoC2_4_ecc.s")

s32 leoAlpha_mult(s32 i, s32 k) {
    if ((i == 0) || (k == 0)) {
        return 0;
    }
    return ganlog[(glog[i] + glog[k])];
}

s32 leoAlpha_div(s32 i, s32 k) {
    if ((i == 0) || (k == 0)) {
        return 0;
    }
    return ganlog[0xFF + (glog[i] - glog[k])];
}
