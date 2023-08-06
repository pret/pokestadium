#include <ultra64.h>
#include "libleo/internal.h"

//Tables to add here
extern u8 ganlog[512];
extern u8 glog[512];

extern u8 LEO_TempBuffer[0xE8];
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

void leoC2_double_ecc(void) {
    register u32 s0;
    register u32 error_k;
    u8* pointer1;
    u8* pointer2;
    u32 k;
    u32 m;
    u32 a;
    u32 d;
    u32 byte;
    u8* p_s;

    k = 0x58 - LEOc2_param.err_pos[0];
    m = 0x58 - LEOc2_param.err_pos[1];
    d = ganlog[k] ^ ganlog[m];
    d = glog[leoAlpha_div(1, d)];
    byte = LEOc2_param.bytes; 

    if (LEOc2_param.err_pos[1] < 0x55) {
        goto c2_2_2;
    }
    pointer2 = &LEO_TempBuffer[sizeof(LEO_TempBuffer)];
    if (LEOc2_param.err_pos[0] < 0x55) {
        goto c2_2_1;
    }
    return;
c2_2_2:
    pointer2 = &LEOc2_param.pntr[(LEOc2_param.err_pos[1] + 1) * byte];
c2_2_1:
    pointer1 = &LEOc2_param.pntr[(LEOc2_param.err_pos[0] + 1) * byte];
    p_s = LEOc2_param.c2buff_e;
    
    do {
        s0 = (p_s -= 4)[0];    
        if (s0 != 0) {
            a = ganlog[m + glog[s0]] ^ p_s[1];
        } else {
            a = p_s[1];
        }
        pointer1--;
        pointer2--;
        if (a != 0) {
            error_k = ganlog[glog[a] + d];
            *pointer1 ^= error_k;
            *pointer2 ^= error_k ^ s0;
        } else {
            *pointer1;
            *pointer2 ^= s0;
        }
    } while (--byte != 0);
}

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
