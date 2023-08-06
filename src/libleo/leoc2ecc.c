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
        p_s -= 4;
        s0 = p_s[0];    
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

void leoC2_4_ecc(void) {
    register u32 s0;
    register u32 R0;
    register u32 R1;
    register u32 R2;
    register u32 R3;
    u8* pointer1;
    u8* pointer2;
    u8* pointer3;
    u8* pointer4;
    u32 aa;
    u32 bb;
    u32 dd;
    u32 ee;
    u32 gg;
    u32 hh;
    u32 pp;
    u32 qq;
    u32 ll;
    u32 ii;
    u32 jj;
    u32 kk;
    u32 byte;
    u32 s;
    u32 a;
    u32 e;
    u32 g;
    u32 p;
    u32 c;
    u32 f;
    u32 o;
    u32 r;
    u32 t;
    u32 u;
    u32 v;
    u32 b;
    u32 d;
    u32 h;
    u32 q;
    u8* p_s;

    ii = 0x58 - LEOc2_param.err_pos[0];
    jj = 0x58 - LEOc2_param.err_pos[1];
    kk = 0x58 - LEOc2_param.err_pos[2];
    ll = 0x58 - LEOc2_param.err_pos[3];

    ii = ganlog[ii];
    jj = ganlog[jj];
    kk = ganlog[kk];
    ll = ganlog[ll];
    s = ganlog[0];

    aa = leoAlpha_div(s, ii);
    bb = leoAlpha_div(s, jj);
    ee = leoAlpha_div(s, kk);
    dd = leoAlpha_div(s, ll);

    a = leoAlpha_mult(bb, ee);
    e = leoAlpha_mult(ee, dd);
    g = leoAlpha_mult(dd, bb);
    p = leoAlpha_mult(dd, aa);
    c = leoAlpha_mult(aa, ee);
    f = leoAlpha_mult(aa, bb);

    b = a ^ e ^ g;
    d = e ^ p ^ c;
    h = p ^ f ^ g;
    q = f ^ a ^ c;
    a = bb ^ ee ^ dd;
    e = ee ^ dd ^ aa;
    g = dd ^ aa ^ bb;
    p = aa ^ bb ^ ee;

    c = leoAlpha_mult(leoAlpha_mult(bb, ee), dd);
    f = leoAlpha_mult(leoAlpha_mult(ee, dd), aa);
    o = leoAlpha_mult(leoAlpha_mult(dd, aa), bb);
    r = leoAlpha_mult(leoAlpha_mult(aa, bb), ee);

    s = leoAlpha_mult(leoAlpha_mult(leoAlpha_div(ii, jj) ^ 1, leoAlpha_div(ii, kk) ^ 1), leoAlpha_div(ii, ll) ^ 1);
    s = leoAlpha_div(1, s);
    t = leoAlpha_mult(leoAlpha_mult(leoAlpha_div(jj, ii) ^ 1, leoAlpha_div(jj, kk) ^ 1), leoAlpha_div(jj, ll) ^ 1);
    t = leoAlpha_div(1, t);
    u = leoAlpha_mult(leoAlpha_mult(leoAlpha_div(kk, ii) ^ 1, leoAlpha_div(kk, jj) ^ 1), leoAlpha_div(kk, ll) ^ 1);
    u = leoAlpha_div(1, u);
    v = leoAlpha_mult(leoAlpha_mult(leoAlpha_div(ll, ii) ^ 1, leoAlpha_div(ll, jj) ^ 1), leoAlpha_div(ll, kk) ^ 1);
    v = leoAlpha_div(1, v);

    aa = glog[leoAlpha_mult(a, s)];
    bb = glog[leoAlpha_mult(b, s)];
    c = leoAlpha_mult(c, s);
    ee = glog[leoAlpha_mult(e, t)];
    dd = glog[leoAlpha_mult(d, t)];
    f = leoAlpha_mult(f, t);
    gg = glog[leoAlpha_mult(g, u)];
    hh = glog[leoAlpha_mult(h, u)];
    o = leoAlpha_mult(o, u);
    pp = glog[leoAlpha_mult(p, v)];
    qq = glog[leoAlpha_mult(q, v)];
    r = leoAlpha_mult(r, v);

    s = glog[s];
    c = glog[c];
    t = glog[t];
    f = glog[f];
    u = glog[u];
    o = glog[o];
    v = glog[v];
    r = glog[r];

    byte = LEOc2_param.bytes;
    
    if (LEOc2_param.err_pos[3] < 0x55) goto c2_4_4;
    pointer4 = &LEO_TempBuffer[sizeof(LEO_TempBuffer)];
    if (LEOc2_param.err_pos[2] < 0x55) goto c2_4_3;
    pointer3 = &LEO_TempBuffer[sizeof(LEO_TempBuffer)];
    if (LEOc2_param.err_pos[1] < 0x55) goto c2_4_2;
    pointer2 = &LEO_TempBuffer[sizeof(LEO_TempBuffer)];
    if (LEOc2_param.err_pos[0] < 0x55) goto c2_4_1;
    return;
    
c2_4_4:
    pointer4 = &LEOc2_param.pntr[(LEOc2_param.err_pos[3] + 1) * byte];
c2_4_3:
    pointer3 = &LEOc2_param.pntr[(LEOc2_param.err_pos[2] + 1) * byte];
c2_4_2:
    pointer2 = &LEOc2_param.pntr[(LEOc2_param.err_pos[1] + 1) * byte];
c2_4_1:
    pointer1 = &LEOc2_param.pntr[(LEOc2_param.err_pos[0] + 1) * byte];
    p_s = LEOc2_param.c2buff_e;

    do {
        p_s -= 4;
        s0 = p_s[0];
        if (!s0) {
            R0 = R1 = R2 = R3 = 0;
        } else {
            s0 = glog[s0];
            R0 = ganlog[s0 + s];
            R1 = ganlog[s0 + t];
            R2 = ganlog[s0 + u];
            R3 = ganlog[s0 + v];
        }
        s0 = p_s[1];
        if (s0) {
            s0 = glog[s0];
            R0 ^= (!a) ? 0 : ganlog[s0 + aa];
            R1 ^= (!e) ? 0 : ganlog[s0 + ee];
            R2 ^= (!g) ? 0 : ganlog[s0 + gg];
            R3 ^= (!p) ? 0 : ganlog[s0 + pp];
        }
        s0 = p_s[2];
        if (s0) {
            s0 = glog[s0];
            R0 ^= (!b) ? 0 : ganlog[s0 + bb];
            R1 ^= (!d) ? 0 : ganlog[s0 + dd];
            R2 ^= (!h) ? 0 : ganlog[s0 + hh];
            R3 ^= (!q) ? 0 : ganlog[s0 + qq];
        }
        s0 = p_s[3];
        if (s0) {
            s0 = glog[s0];
            R0 ^= ganlog[s0 + c];
            R1 ^= ganlog[s0 + f];
            R2 ^= ganlog[s0 + o];
            R3 ^= ganlog[s0 + r];
        }
        pointer1--;
        pointer2--;
        pointer3--;
        pointer4--;
        if (R0) *pointer1 ^= R0;
        if (R1) *pointer2 ^= R1;
        if (R2) *pointer3 ^= R2;
        if (R3) *pointer4 ^= R3;
    } while (--byte != 0);
}

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
