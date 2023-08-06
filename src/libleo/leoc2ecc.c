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

void leoC2_3_ecc(void) {
    register u32 s0;
    register u32 error_i;
    register u32 error_j;
    register u32 error_k;
    u8* pointer1;
    u8* pointer2;
    u8* pointer3;
    u32 byte;
    u32 ii;
    u32 jj;
    u32 kk;
    u32 c;
    u32 f;
    u32 o;
    u32 b;
    u32 d;
    u32 h;
    u32 a;
    u32 e;
    u32 g;
    u32 p;
    u8* p_s;

    ii = 0x58 - LEOc2_param.err_pos[0];
    jj = 0x58 - LEOc2_param.err_pos[1];
    kk = 0x58 - LEOc2_param.err_pos[2];
    ii = ganlog[ii];
    jj = ganlog[jj];
    kk = ganlog[kk];
    c = leoAlpha_mult(kk, kk);
    f = leoAlpha_mult(jj, jj);
    o = leoAlpha_mult(ii, ii);
    b = c ^ f;
    d = c ^ o;
    h = f ^ o;
    a = leoAlpha_mult(jj, c) ^ leoAlpha_mult(kk, f);
    e = leoAlpha_mult(kk, o) ^ leoAlpha_mult(ii, c);
    g = leoAlpha_mult(jj, o) ^ leoAlpha_mult(ii, f);
    c = jj ^ kk;
    f = kk ^ ii;
    o = ii ^ jj;
    p = a ^ e ^ g;
    p = leoAlpha_div(1, p);
    a = glog[a];
    b = glog[b];
    c = glog[c];
    d = glog[d];
    e = glog[e];
    f = glog[f];
    g = glog[g];
    h = glog[h];
    o = glog[o];
    p = glog[p];
    byte = LEOc2_param.bytes;
    if (LEOc2_param.err_pos[2] < 0x55) goto c2_3_3;
    pointer3 = &LEO_TempBuffer[sizeof(LEO_TempBuffer)];
    if (LEOc2_param.err_pos[1] < 0x55) goto c2_3_2;
    pointer2 = &LEO_TempBuffer[sizeof(LEO_TempBuffer)];
    if (LEOc2_param.err_pos[0] < 0x55) goto c2_3_1;
    return;
c2_3_3:
    pointer3 = &LEOc2_param.pntr[(LEOc2_param.err_pos[2] + 1) * byte];
c2_3_2:
    pointer2 = &LEOc2_param.pntr[(LEOc2_param.err_pos[1] + 1) * byte];
c2_3_1:
    pointer1 = &LEOc2_param.pntr[(LEOc2_param.err_pos[0] + 1) * byte];
    p_s = LEOc2_param.c2buff_e;
    
    do {
        p_s -= 4;
        s0 = p_s[0];
        if (s0) {
            s0 = glog[s0];
            error_i = ganlog[s0 + a];
            error_j = ganlog[s0 + e];
            error_k = ganlog[s0 + g];
        } else {
            error_i = error_j = error_k = 0;
        }
        s0 = p_s[1];
        if (s0) {
            s0 = glog[s0];
            error_i ^= ganlog[s0 + b];
            error_j ^= ganlog[s0 + d];
            error_k ^= ganlog[s0 + h];
        }
        s0 = p_s[2];
        if (s0) {
            s0 = glog[s0];
            error_i ^= ganlog[s0 + c];
            error_j ^= ganlog[s0 + f];
            error_k ^= ganlog[s0 + o];
        }
        pointer1--;
        pointer2--;
        pointer3--;
        if (error_i) {
            *pointer1 ^= ganlog[glog[error_i] + p];
        }
        if (error_j) {
            *pointer2 ^= ganlog[glog[error_j] + p];
        }
        if (error_k) {
            *pointer3 ^= ganlog[glog[error_k] + p];
        }
    } while (--byte != 0);
}

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
