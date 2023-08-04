#include <ultra64.h>
#include "libleo/internal.h"

//Tables to add here
extern u8 ganlog[512];
extern u8 glog[512];

extern block_param_form LEOc2_param;
extern u8 LEOC2_Syndrome[2][0xE8*4];

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunknown-pragmas"

#ifdef NON_MATCHING
s32 leoC2_Correction(void) {
    switch (LEOc2_param.err_num) {
        case 1:
            leoC2_single_ecc();
            return 0;
        case 2:
            leoC2_double_ecc();
            return 0;
        case 3:
            leoC2_3_ecc();
            return 0;
        case 4:
            leoC2_4_ecc();
            return 0;
        default:
            return -1;
        case 0:
            return 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leoc2ecc/leoC2_Correction.s")
#endif

void leoC2_single_ecc(void) {
    u8* pointer;
    u32 byte;
    u8* p_s;

    if (LEOc2_param.err_pos[0] < 0x55) {
        byte = LEOc2_param.bytes;
        pointer = &LEOc2_param.pntr[(LEOc2_param.err_pos[0] + 1) * byte];
        p_s = LEOc2_param.c2buff_e;

        do {
            *(--pointer) ^= *(p_s -= 4);
        } while(--byte != 0);
    }
}

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
