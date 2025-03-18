#include "2D340.h"

void func_8002C740(unk_func_88201DA0_038* arg0, unk_func_88201DA0_034* arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->unk_00 = arg1;
    arg0->unk_0C = arg2;
    arg0->unk_04 = arg3;
    arg0->unk_08 = arg4;
}

void func_8002C758(unk_func_8820BE14_06C* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    arg0->unk_00 = mem_pool_alloc(arg3, arg1 * arg2);
    arg0->unk_0C = arg1;
    arg0->unk_04 = arg2;
    arg0->unk_08 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2D340/func_8002C7AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2D340/func_8002C7D4.s")

s32 func_8002C88C(unk_func_8820BE14_06C* arg0, s8* arg1, s32 arg2) {
    s32 var_t1;
    s8* var_t0;
    s8* var_v1;
    s32 i;

    if ((arg0->unk_08 >= arg0->unk_04) || (arg0->unk_08 < arg2)) {
        return 1;
    }

    var_v1 = (s8*)arg0->unk_00 + (arg0->unk_0C * arg0->unk_08);
    var_t0 = var_v1 + arg0->unk_0C;
    var_t1 = (arg0->unk_08 - arg2) * arg0->unk_0C;

    while (var_t1 > 0) {
        *--var_t0 = *--var_v1;
        var_t1--;
    }

    var_v1 = arg1;
    var_t1 = arg0->unk_0C;
    var_t0 = (u8*)arg0->unk_00 + (arg0->unk_0C * arg2);

    while (var_t1 > 0) {
        *var_t0++ = *var_v1++;
        var_t1--;
    }

    arg0->unk_08 += 1;
    return 0;
}

s32 func_8002C990(unk_func_8820BE14_06C* arg0, s32 arg1) {
    s32 var_t0;
    s8* var_a3;
    s8* var_v1;

    if (arg1 >= arg0->unk_08) {
        return 1;
    }

    var_v1 = (s8*)arg0->unk_00 + (arg0->unk_0C * arg1);

    arg0->unk_08--;

    var_a3 = arg0->unk_0C + var_v1;
    var_t0 = (arg0->unk_08 - arg1) * arg0->unk_0C;

    while (var_t0 > 0) {
        *var_v1++ = *var_a3++;
        var_t0--;
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2D340/func_8002CA00.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2D340/func_8002CAAC.s")

s32 func_8002CB58(unk_func_8830867C_04C_030_02C_000_000_00C* arg0, s32 arg1) {
    s16* var_a2;
    s32 var_a3;
    s16* var_v1;

    if (arg1 >= arg0->unk_08) {
        return 1;
    }

    var_v1 = (s16*)arg0->unk_00 + arg1;

    arg0->unk_08--;

    var_a2 = var_v1 + 1;
    var_a3 = arg0->unk_08 - arg1;

    while (var_a3 > 0) {
        *var_v1++ = *var_a2++;
        var_a3--;
    }

    return 0;
}

void func_8002CBB0(unk_func_88205880_A030* arg0, void** arg1, s32 arg2, s32 arg3) {
    arg0->unk_00 = arg1;
    arg0->unk_04 = arg2;
    arg0->unk_08 = arg3;
}

void func_8002CBC0(unk_func_88200FA0_030_038* arg0, s32 arg1, MemoryPool* arg2) {
    arg0->unk_00 = mem_pool_alloc(arg2, arg1 * 4);
    arg0->unk_04 = arg1;
    arg0->unk_08 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2D340/func_8002CC04.s")

void func_8002CC2C(unk_func_88200FA0_030_038* arg0, char* arg1, s32 arg2) {
    s32 var_t1;
    unk_func_88205880_00D0** var_t0;
    unk_func_88205880_00D0** var_v0;

    var_v0 = &arg0->unk_00[arg0->unk_08];
    var_t0 = var_v0 + 1;
    var_t1 = arg0->unk_08 - arg2;

    while (var_t1 > 0) {
        *--var_t0 = *--var_v0;
        var_t1--;
    }

    arg0->unk_00[arg2] = arg1;
    arg0->unk_08++;
}

void func_8002CC80(unk_func_8830867C_02C_0CC* arg0, s32 arg1) {
    s32 var_a2;
    unk_func_8830867C_02C_0CC_000** var_v0;
    unk_func_8830867C_02C_0CC_000** var_v1;

    var_v0 = &arg0->unk_00[arg1];
    var_v1 = var_v0 + 1;

    arg0->unk_08--;

    var_a2 = arg0->unk_08 - arg1;

    while (var_a2 > 0) {
        *var_v0++ = *var_v1++;
        var_a2--;
    }
}

void func_8002CCC4(void** arg0, void** arg1, s32 arg2) {
    s32 i;

    for (i = 0; i < arg2; i++) {
        void* tmp = *arg0;
        *arg0++ = *arg1;
        *arg1++ = tmp;
    }
}

s32* func_8002CD58(s32* arg0, s32* arg1, s32* arg2, s32 (*arg3)(s32, s32)) {
    return (arg3(*arg0, *arg1) < 0)   ? (arg3(*arg1, *arg2) < 0)   ? arg1
                                        : (arg3(*arg0, *arg2) < 0) ? arg2
                                                                   : arg0
           : (arg3(*arg1, *arg2) > 0) ? arg1
           : (arg3(*arg0, *arg2) > 0) ? arg2
                                      : arg0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2D340/func_8002CE34.s")

void func_8002CE34(u8*, s32, s32 (*arg1)(s32, s32));

void func_8002D180(unk_func_8830867C_02C_0CC* arg0, s32 (*arg1)(s32, s32)) {
    func_8002CE34(arg0->unk_00, arg0->unk_08, arg1);
}

void func_8002D1AC(unk_func_8830867C_02C_0CC* arg0, unk_func_8830867C_02C_0CC* arg1,
                   s32 (*arg2)(unk_func_8830867C_02C_0CC_000*, s32*), s32* arg3) {
    s32 var_s2;
    unk_func_8830867C_02C_0CC_000** var_s0;
    unk_func_8830867C_02C_0CC_000** var_s1;

    var_s1 = arg1->unk_00;
    var_s2 = arg0->unk_08;
    var_s0 = arg0->unk_00;

    while (var_s2 > 0) {
        if (arg2(*var_s0, arg3) != 0) {
            *var_s1++ = *var_s0;
        }
        var_s2--;
        var_s0++;
    }

    arg1->unk_08 = ((s32)var_s1 - (s32)arg1->unk_00) >> 2;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2D340/func_8002D248.s")

static u16 D_80075690[0x100] = {
    0,      0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7000, 0x7100, 0x7200, 0xFFFF, 0xFFFF, 0x7500, 0x7600, 0x7700, 0x7800, 0x7900,
    0x7A00, 0x7B00, 0x7C00, 0x7D00, 0x7E00, 0x7F00, 0x3000, 0x3100, 0x3200, 0x3300, 0x3400, 0x3500, 0x3600, 0x3700,
    0x3800, 0x3900, 0x8A00, 0x8B00, 0xFFFF, 0x8D00, 0xFFFF, 0x8F00, 0xFFFF, 0x4100, 0x4200, 0x4300, 0x4400, 0x4500,
    0x4600, 0x4700, 0x4800, 0x4900, 0x4A00, 0x4B00, 0x4C00, 0x4D00, 0x4E00, 0x4F00, 0x5000, 0x5100, 0x5200, 0x5300,
    0x5400, 0x5500, 0x5600, 0x5700, 0x5800, 0x5900, 0x5A00, 0x9B00, 0xFFFF, 0x9D00, 0xFFFF, 0xFFFF, 0xFFFF, 0x4101,
    0x4201, 0x4301, 0x4401, 0x4501, 0x4601, 0x4701, 0x4801, 0x4901, 0x4A01, 0x4B01, 0x4C01, 0x4D01, 0x4E01, 0x4F01,
    0x5001, 0x5101, 0x5201, 0x5301, 0x5401, 0x5501, 0x5601, 0x5701, 0x5801, 0x5901, 0x5A01, 0xFFFF, 0xFFFF, 0xFFFF,
    0xAE00, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xB100, 0xFFFF, 0xFFFF, 0xFFFF, 0xB500, 0xFFFF, 0xFFFF,
    0xFFFF, 0xB900, 0xBA00, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xC700, 0xFFFF, 0xFFFF, 0xCA00, 0xFFFF, 0xFFFF, 0xFFFF, 0xCE00, 0xCF00, 0x4104, 0x4108, 0x410C, 0xFFFF,
    0x4114, 0xFFFF, 0xFFFF, 0x431C, 0x4504, 0x4508, 0x450C, 0x4514, 0x4904, 0x4908, 0x490C, 0x4914, 0xFFFF, 0x4E10,
    0x4F04, 0x4F08, 0x4F0C, 0xFFFF, 0x4F14, 0xD700, 0xFFFF, 0x5504, 0xFFFF, 0x550C, 0x5514, 0xFFFF, 0xFFFF, 0x5305,
    0x4105, 0x4109, 0x410D, 0xFFFF, 0x4115, 0xFFFF, 0xFFFF, 0x431D, 0x4505, 0x4509, 0x450D, 0x4515, 0x4905, 0x4909,
    0x490D, 0x4915, 0xFFFF, 0x4E11, 0x4F05, 0x4F09, 0x4F0D, 0xFFFF, 0x4F15, 0xFFFF, 0xFFFF, 0x5505, 0xFFFF, 0x550D,
    0x5515, 0xFFFF, 0xFFFF, 0xFFFF,
};

#ifdef NON_MATCHING
void func_8002D28C(u16* a0, u8* a1) {
    u8 temp_v1;
    u16* arg0 = a0;
    u8* arg1 = a1;

    do {
        temp_v1 = *arg1++;
        switch (temp_v1) {
            case 0xBC:
                *arg0++ = D_80075690[0x50] + 4;
                *arg0++ = D_80075690[0x4B] + 4;
                break;

            case 0xBD:
                *arg0++ = D_80075690[0x4D] + 4;
                *arg0++ = D_80075690[0x4E] + 4;
                break;

            case 0xDF:
                *arg0++ = D_80075690[temp_v1];
                *arg0++ = D_80075690[temp_v1];
                break;

            default:
                *arg0++ = D_80075690[temp_v1];
                break;
        }
    } while (temp_v1 != 0);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/2D340/func_8002D28C.s")
#endif

s32 func_8002D348(u8* arg0, u8* arg1) {
    static u16 D_80075890[3] = { 0xFF00, 0xFFFC, 0xFFFF };

    u16 sp74[22];
    u16 sp48[22];
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_a2;
    u16* var_a0;
    u16* var_v1;
    s32 i;

    func_8002D28C(&sp74, arg0);
    func_8002D28C(&sp48, arg1);

    for (i = 0; i < 3; i++) {
        var_v1 = sp74;
        var_a0 = sp48;

        while (true) {
            temp_a1 = D_80075890[i] & *var_v1++;
            temp_a2 = D_80075890[i] & *var_a0++;
            temp_a3 = temp_a1 - temp_a2;

            if (temp_a3 != 0) {
                return temp_a3;
            }

            if (temp_a1 == 0) {
                break;
            }
        }
    }

    return 0;
}

void func_8002D3F0(f32* arg0) {
    f32 temp_fv0_2 = sqrtf(SQ(arg0[1]) + SQ(arg0[0]));

    arg0[0] /= temp_fv0_2;
    arg0[1] /= temp_fv0_2;
}

Color_RGBA8 func_8002D444(Color_RGBA8 arg0, f32 arg2) {
    Color_RGBA8 sp14;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;

    var_v1 = (s32)arg0.r * arg2;
    if (var_v1 >= 0x100) {
        var_v1 = 0xFF;
    }

    var_a0 = (s32)arg0.g * arg2;
    if (var_a0 >= 0x100) {
        var_a0 = 0xFF;
    }

    var_a1 = (s32)arg0.b * arg2;
    if (var_a1 >= 0x100) {
        var_a1 = 0xFF;
    }

    sp14.r = var_v1;
    sp14.g = var_a0;
    sp14.b = var_a1;
    sp14.a = arg0.a;
    return sp14;
}
