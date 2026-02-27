#include "CE80.h"

extern u8* D_800A82D0;
extern s32 D_800A82D4;
extern u8 D_800A82D8;
extern u8 D_800A82D9;
extern u32 D_800A82DC;

#ifdef NON_MATCHING
s32 func_8000C280(unk_func_80003680_sp27* arg0, u32 arg1, u32 arg2, u8 arg3, unk_func_80003680_sp60* arg4) {
    u16 var_v0;
    s16 sp64;
    s16 sp62;
    s16 sp60;
    u32 i;
    s32 sp58;
    JpegHuffmanTable* temp_fp;
    JpegHuffmanTable* temp_s4;
    JpegHuffmanTable* temp_s5;
    JpegHuffmanTable* temp_s7;

    sp58 = 0;
    D_800A82D0 = arg0->unk_00;

    if (arg0->unk_04 == 0) {
        var_v0 = 2;
    } else {
        var_v0 = 4;
        if (arg0->unk_05 == 1) {
            sp58 = 0x80;
        }
    }

    temp_s4 = arg0->unk_08;
    temp_s5 = arg0->unk_0C;
    temp_s7 = arg0->unk_10;
    temp_fp = arg0->unk_14;

    if (arg3 == 0) {
        D_800A82D4 = 0;
        D_800A82D8 = 0x20;
        D_800A82DC = 0;
        D_800A82D9 = 0;
        sp64 = 0;
        sp62 = 0;
        sp60 = 0;
    } else {
        D_800A82D4 = arg4->unk_00;
        D_800A82D8 = arg4->unk_04;
        D_800A82DC = arg4->unk_08;
        D_800A82D9 = arg4->unk_05;
        sp64 = arg4->unk_0C;
        sp62 = arg4->unk_0E;
        sp60 = arg4->unk_10;
    }

    while (arg2) {
        for (i = 0; i < var_v0; i++) {
            if (func_8000C4A8(temp_s4, temp_s5, arg1, &sp64) != 0) {
                return 2;
            }
            arg1 += 0x80;
        }

        if (func_8000C4A8(temp_s7, temp_fp, arg1, &sp62) != 0) {
            return 2;
        }

        arg1 += 0x80;

        if (func_8000C4A8(temp_s7, temp_fp, arg1, &sp60) != 0) {
            return 2;
        }

        arg2--;
        arg1 += 0x80;

        arg1 += (sp58 * 2);
    }

    arg4->unk_00 = D_800A82D4;
    arg4->unk_04 = D_800A82D8;
    arg4->unk_08 = D_800A82DC;
    arg4->unk_05 = D_800A82D9;
    arg4->unk_0C = sp64;
    arg4->unk_0E = sp62;
    arg4->unk_10 = sp60;

    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/CE80/func_8000C280.s")
#endif

#ifdef NON_MATCHING
s32 func_8000C4A8(JpegHuffmanTable* arg0, JpegHuffmanTable* arg1, s16* arg2, s16* arg3) {
    s8 i;
    s8 sp36;
    s16 sp34;
    u32 test;

    if (func_8000C644(arg0, &sp34, &sp36) != 0) {
        return 1;
    }

    *arg3 += sp34;
    *arg2 = *arg3;
    i = 1;

    while (i < 0x40) {
        if (func_8000C644(arg1, &sp34, &sp36) != 0) {
            return 1;
        }

        if (sp34 == 0) {
            if (sp36 == 0xF) {
                while (sp36 >= 0) {
                    sp36--;
                    arg2[i++] = 0;
                }
                continue;
            }

            while (i < 0x40) {
                arg2[i++] = 0;
            }
            break;
        }

        while (sp36-- > 0) {
            arg2[i++] = 0;
        }

        arg2[i++] = sp34;
    }

    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/CE80/func_8000C4A8.s")
#endif

typedef struct sp24_func_8000C644 {
    u16 unk_00;
    u8 unk_02;
} sp24_func_8000C644;

#ifdef NON_MATCHING
s32 func_8000C644(JpegHuffmanTable* arg0, s16* arg1, s8* arg2) {
    u8 i;
    sp24_func_8000C644 sp24;
    s16 temp_v0;

    sp24.unk_00 = 0;
    temp_v0 = func_8000C780(0x10);

    for (i = 0; i < 16; i++) {
        sp24.unk_00 = temp_v0 >> (0xF - i);

        if ((arg0->codesB[i] != 0xFFFF) && !(arg0->codesB[i] < sp24.unk_00)) {
            break;
        }
    }

    if (i >= 16) {
        return 1;
    }

    sp24.unk_02 = *(u8*)(((arg0->codeOffs[i] + sp24.unk_00) - arg0->codesA[i]) + arg0->symbols);
    *arg2 = sp24.unk_02 >> 4;

    D_800A82D8 = (D_800A82D8 + i) - 0xF;
    *arg1 = 0;

    if ((sp24.unk_02 & 0xF) != 0) {
        sp24.unk_02 &= 0xF;

        *arg1 = func_8000C780(sp24.unk_02);
        if (*arg1 < (1 << (sp24.unk_02 + 0x1F))) {
            *arg1 += (-1 << sp24.unk_02) + 1;
        }
    }

    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/CE80/func_8000C644.s")
#endif

#ifdef NON_MATCHING
u16 func_8000C780(u8 arg0) {
    u8 var_v0;
    u8 var_v1;
    u32 ret;

    var_v0 = D_800A82D8 >> 3;

    while (var_v0 > 0) {
        var_v1 = D_800A82D0[D_800A82D4++];

        if ((D_800A82D9 != 0) && (var_v1 == 0)) {
            var_v1 = D_800A82D0[D_800A82D4++];
        }

        if (var_v1 == 0xFF) {
            D_800A82D9 = 1;
        } else {
            D_800A82D9 = 0;
        }

        D_800A82DC <<= 8;
        D_800A82DC |= var_v1;
        D_800A82D8 -= 8;

        var_v0--;
    }

    ret = (D_800A82DC << D_800A82D8);
    D_800A82D8 += arg0;

    ret >>= -arg0;
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/CE80/func_8000C780.s")
#endif
