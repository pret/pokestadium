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

s16 JpegUtils_GetHuffmanCodes(u8* codesLengths, u16* codes) {
    s16 idx = 0;
    u16 code = 0;
    u8 lastLen = codesLengths[0];

    while (true) {
        while (true) {
            codes[idx++] = code++;

            if (codesLengths[idx] != lastLen) {
                break;
            }
        }

        if (codesLengths[idx] == 0) {
            break;
        }

        while (true) {
            if (code <<= 1, codesLengths[idx] == ++lastLen) {
                break;
            }
        }
    }

    return idx;
}

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
    if (JpegUtils_GetHuffmanCodes(arg2, arg3) != temp_v0) {
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

s32 JpegUtils_ProcessHuffmanTable(u8* dht, JpegHuffmanTable* ht, u8* codesLengths, u16* codes, u8 count) {
    u8 idx;
    u32 codeCount;

    for (idx = 0; idx < count; idx++) {
        u32 ac = (*dht++ >> 4);

        codeCount = func_8000BF70(dht, &ht[idx], codesLengths, codes, ac);
        if (codeCount == 0) {
            return 1;
        }

        dht += 0x10;
        ht[idx].symbols = dht;
        dht += codeCount;
    }
    return 0;
}

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
    if (JpegUtils_GetHuffmanCodes(arg2, arg3) != temp_v0) {
        return 1;
    }
    func_8000C104((u8*)temp_s0 + 0x10, arg1, arg2, arg3, temp_v0, sp2F);
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/C970/func_8000C1AC.s")
#endif
