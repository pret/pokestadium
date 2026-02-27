#include "C970.h"

typedef struct unk_func_8000C104_arg1 {
    /* 0x000 */ u8 value;
    /* 0x001 */ u8  pad01[0x0F];
    /* 0x010 */ u16 unk_10;
    /* 0x012 */ u8  pad12[0xEE];
    /* 0x100 */ u16 unk_100;
} unk_func_8000C104_arg1; // size >= 0x102

void JpegUtils_ProcessQuantizationTable(u8* dqt, JpegQuantizationTable* qt, u8 num_tables) {
    u8 i;

    for (i = 0; i < num_tables; i++) {
        u8 j;

        dqt++;
        for (j = 0; j < 64; j++) {
            qt[i].table[j] = *dqt++;
        }
    }
}

s32 JpegUtils_ParseHuffmanCodesLengths(u8* ptr, u8* codesLengths) {
    u8 off = 1;
    s16 count = 0;
    s16 idx = 1;

    while (off < 0x11) {
        while (idx <= ptr[off - 1]) {
            codesLengths[count++] = off;
            idx++;
        }
        idx = 1;
        off++;
    }

    codesLengths[count] = 0;
    return count;
}

#ifdef NON_MATCHING
s16 func_8000BE5C(u8* arg0, u16* arg1) {
    s16 var_v0;
    s16 var_v1;
    s32 temp_t6;
    u8 temp_t0;
    u8 var_a2;
    u8 var_a3;

    var_a2 = *arg0;
    var_v1 = 0;
    var_v0 = 0;
    var_a3 = var_a2;

    while(1) {
        temp_t6 = var_v1 * 2;
        var_v1 += 1;
        arg1[temp_t6] = var_v0;
        temp_t0 = arg0[var_v1];
        var_v0 = (var_v0 + 1) & 0xFFFF;
        if (var_a3 == temp_t0) {
            continue;
        }
        if (temp_t0 != 0) {
            do {
                var_a3 = (var_a2 + 1) & 0xFF;
                var_v0 = (var_v0 * 2) & 0xFFFF;
                var_a2 = var_a3;
            } while (temp_t0 != var_a3);
            continue;
        }
        break;
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/C970/func_8000BE5C.s")
#endif

u16 JpegUtils_SetHuffmanTable(u8* data, JpegHuffmanTable* ht, u16* codes) {
    u8 idx;
    u16 codeOff = 0;

    for (idx = 0; idx < 0x10; idx++) {
        if (data[idx]) {
            ht->codeOffs[idx] = codeOff;
            ht->codesA[idx] = codes[codeOff];
            codeOff += data[idx] - 1;
            ht->codesB[idx] = codes[codeOff];
            codeOff++;
        } else {
            ht->codesB[idx] = 0xFFFF;
        }
    }

    return codeOff;
}

#ifdef NON_MATCHING
s16 func_8000BF70(u8* arg0, JpegHuffmanTable* arg1, u8* arg2, u16* arg3, u8 arg4) {
    s16 temp_v0;

    temp_v0 = JpegUtils_GetHuffmanCodes(arg2, arg3);
    if ((temp_v0 == 0) || ((arg4 != 0) && (temp_v0 >= 0x101)) || ((arg4 == 0) && (temp_v0 >= 0x11))) {
        return 0;
    }
    if (func_8000BE5C(arg2, arg3) != temp_v0) {
        return 0;
    }
    if (temp_v0 != JpegUtils_SetHuffmanTable(arg0, arg1, arg3)) {
        return 0;
    }
    return temp_v0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/C970/func_8000BF70.s")
#endif

#ifdef NON_MATCHING
s32 func_8000C02C(u8* arg0, JpegHuffmanTable* arg1, u8* arg2, u16* arg3, s32 arg4) {
    s32 temp_at;
    s32 temp_lo;
    s32 temp_t8;
    s32 temp_v0;
    s32 var_s1;
    u8* var_s0;
    u8* temp_s0;
    u8* temp_s0_2;

    var_s0 = arg0;
    var_s1 = 0;
    if ((s32) arg4 > 0) {
        while(1) {            
            temp_lo = var_s1 * 0x54;
            temp_s0 = var_s0 + 1;
            temp_v0 = func_8000BF70(temp_s0, &arg1[temp_lo], arg2, arg3, (s32) *var_s0 >> 4);
            temp_s0_2 = temp_s0 + 0x10;
            if (temp_v0 == 0) {
                return 1;
            }
            temp_t8 = (var_s1 + 1) & 0xFF;
            temp_at = temp_t8 < (s32) arg4;
            arg1[temp_lo].symbols = temp_s0_2;
            var_s1 = temp_t8;
            var_s0 = temp_s0_2 + temp_v0;
            if (temp_at == 0) {
                return 0;
            }
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/C970/func_8000C02C.s")
#endif

#ifdef NON_MATCHING
void func_8000C104(u8* arg0, unk_func_8000C104_arg1* arg1, u8* arg2, u16* arg3, s16 arg4, u8 arg5) {
    s16 i;
    u8 temp_v1;

    for (i = 0; i < arg4; i++) {
        temp_v1 = arg0[i];
        if (arg5 != 0) {
            arg1[temp_v1 * 2].unk_100 = arg3[i];
            arg1[temp_v1].value = arg2[i];
        } else {
            arg1[temp_v1 * 2].unk_10 = arg3[i];
            arg1[temp_v1].value = arg2[i];
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/C970/func_8000C104.s")
#endif

#ifdef NON_MATCHING
s32 func_8000C1AC(u8* arg0, unk_func_8000C104_arg1* arg1, u8* arg2, u16* arg3) {
    u8 sp2F;
    s16 sp2C;
    s16 temp_v0;
    u8* temp_s0;

    temp_s0 = arg0 + 1;
    sp2F = (u8) ((s32) *arg0 >> 4);
    temp_v0 = JpegUtils_GetHuffmanCodes(temp_s0, arg2);
    if ((temp_v0 == 0) || ((sp2F != 0) && (temp_v0 >= 0x101)) || ((sp2F == 0) && (temp_v0 >= 0x11))) {
        return 1;
    }
    sp2C = temp_v0;
    if (func_8000BE5C(arg2, arg3) != temp_v0) {
        return 1;
    }
    func_8000C104((u8*)temp_s0 + 0x10, arg1, arg2, arg3, temp_v0, sp2F);
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/C970/func_8000C1AC.s")
#endif
