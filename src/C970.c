#include "C970.h"

typedef struct unk_func_8000C104_arg1 {
    /* 0x000 */ u8 value;
    /* 0x001 */ u8  pad01[0x0F];
    /* 0x010 */ u16 unk_10;
    /* 0x012 */ u8  pad12[0xEE];
    /* 0x100 */ u16 unk_100;
} unk_func_8000C104_arg1; // size >= 0x102

#ifdef NON_MATCHING
void func_8000BD70(u8* in_quantization_tables, u8* out_quantization_tables, s32 num_tables) {
    u8* src;
    u8* dst;
    s32 i;
    s32 j;
    s32 count;

    src = in_quantization_tables;
    count = num_tables & 0xFF;

    for (i = 0; i < count; i++) {
        src++;

        for (j = 0; j < 0x40; j++) {
            dst = out_quantization_tables + (i << 7) + (j * 2);
            *(s16*)dst = (s16)*src;
            src++;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/C970/func_8000BD70.s")
#endif

#ifdef NON_MATCHING
s16 func_8000BDD8(u8* arg0, u16* arg1) {
    s16 var_a2;
    s16 var_v1;
    s8 i;
    s8 var_v0;
    u8* temp_a1;

    var_v0 = 1;
    var_v1 = 0;
    var_a2 = 1;
    for (i = 1; i < 0x11; i = (var_v0 + 1) & 0xFF) {
        temp_a1 = &arg0[i];
        if ((s32) temp_a1[-1] > 0) {
            do {
                arg1[var_v1] = var_v0;
                var_a2 += 1;
                var_v1 += 1;
            } while ((s32) temp_a1[-1] >= var_a2);
            var_a2 = 1;
        }
        var_v0 = i;
    }
    arg1[var_v1] = 0;
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/C970/func_8000BDD8.s")
#endif

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

#ifdef NON_MATCHING
s8 func_8000BEC8(u8* arg0, unk_func_80003680_spB0* arg1, u16* arg2) {
    s32 i;
    s32 temp_t4;
    s8 var_v1;

    var_v1 = 0;
    for (i = 0; i < 16; i = (i + 1) & 0xFF) {
        if (arg0[i] != 0) {
            arg1->unk_00[i] = var_v1;
            arg1->unk_10[i] = arg2[var_v1];
            temp_t4 = ((var_v1 + arg0[i]) - 1) & 0xFFFF;
            var_v1 = (temp_t4 + 1);
            arg1->unk_30[i] = arg2[temp_t4];
        } else {
            arg1->unk_30[i] = 0xFFFF;
        }
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/C970/func_8000BEC8.s")
#endif

#ifdef NON_MATCHING
s16 func_8000BF70(u8* arg0, unk_func_80003680_spB0* arg1, u8* arg2, u16* arg3, u8 arg4) {
    s16 temp_v0;

    temp_v0 = func_8000BDD8(arg2, arg3);
    if ((temp_v0 == 0) || ((arg4 != 0) && (temp_v0 >= 0x101)) || ((arg4 == 0) && (temp_v0 >= 0x11))) {
        return 0;
    }
    if (func_8000BE5C(arg2, arg3) != temp_v0) {
        return 0;
    }
    if (temp_v0 != func_8000BEC8(arg0, arg1, arg3)) {
        return 0;
    }
    return temp_v0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/C970/func_8000BF70.s")
#endif

#ifdef NON_MATCHING
s32 func_8000C02C(u8* arg0, unk_func_80003680_spB0* arg1, u8* arg2, u16* arg3, s32 arg4) {
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
            arg1[temp_lo].unk_50 = temp_s0_2;
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
    temp_v0 = func_8000BDD8(temp_s0, arg2);
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
