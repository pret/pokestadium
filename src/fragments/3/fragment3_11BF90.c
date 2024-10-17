#include "fragment3.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/memory.h"

static unk_func_8790002C* D_87906120;

void func_87903600(void) {
    s32 i;
    unk_func_8790002C* ptr;

    D_87906120 = main_pool_alloc(sizeof(unk_func_8790002C) * 3, 0);
    ptr = D_87906120;

    for (i = 0; i < 3; i++, ptr++) {
        func_8001BB58(&ptr->unk_000);
        ptr->unk_168 = func_80019D18(0xAB);
        func_8001BC34(&ptr->unk_000, 0, ptr->unk_23C, ptr->unk_168->unk_08->unk_00[0]);
        func_8001BD04(&ptr->unk_000, 0);
        ptr->unk_000.unk_000.unk_01 &= ~1;
        func_8790060C(ptr);
    }
}

void func_879036B4(unk_func_8790002C* arg0) {
    if (arg0->unk_23E == 1) {
        arg0->unk_000.unk_000.unk_01 |= 1;
        func_879002B8(arg0, 0, -1, 0);
        arg0->unk_23E++;
    }
}

void func_8790370C(void) {
    s32 i;
    unk_func_8790002C* ptr = D_87906120;

    func_8140C5D0();

    for (i = 0; i < 3; i++, ptr++) {
        func_879036B4(ptr);
        func_879003A0(ptr);
        func_87900770(ptr);
        func_87900808(ptr);
    }
}

void func_87903778(unk_func_8790002C* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5, s16 arg6, s16 arg7,
                   s16 arg8) {
    arg0->unk_16C.x = arg1;
    arg0->unk_16C.y = arg1;
    arg0->unk_16C.z = arg1;

    arg0->unk_1A8 = arg2;
    arg0->unk_1AC = arg3;
    arg0->unk_1B0 = arg4;
    arg0->unk_21A = arg5;
    arg0->unk_21C = arg6;
    arg0->unk_21E = arg7;
    arg0->unk_266 = arg8;
    arg0->unk_23E = 1;
}

void func_879037D0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6) {
    unk_func_8790002C* sp34 = D_87906120;

    func_87903778(sp34, arg0, arg1, arg2, arg3, arg4, arg5, arg6, 0);
    sp34->unk_000.unk_000.unk_14 = 0;
}

void func_87903838(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6) {
    unk_func_8790002C* sp34 = &D_87906120[1];

    func_87903778(sp34, arg0, arg1, arg2, arg3, arg4, arg5, arg6, 1);
    sp34->unk_000.unk_000.unk_14 = 1;
}

void func_879038AC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6) {
    unk_func_8790002C* sp34 = &D_87906120[2];

    func_87903778(sp34, arg0, arg1, arg2, arg3, arg4, arg5, arg6, 2);
    sp34->unk_000.unk_000.unk_14 = 2;
}

#ifdef NON_MATCHING
Gfx* func_87903920(Gfx* arg0, arg1_func_87903D64_014* arg1) {
    s32 sp38;
    s32 sp34;
    s32 sp30;

    unk_D_86002F34_000_014_004* sp2C;
    unk_D_86002F34_000_014_004* sp28;
    unk_D_86002F34_000_014_010* sp24;
    unk_D_86002F34_000_014_010* sp20;

    s32 temp_a2;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_t2_3;
    s32 temp_t4;
    s32 var_a0;
    s32 var_v1;
    u32 temp_a3;
    u32 var_v0;
    u8* temp_t1_3;
    u8* temp_v1;
    unk_D_86002F34_000_014_004* var_a1;
    unk_D_86002F34_000_014_004* var_a2;
    unk_D_86002F34_000_014_010* var_a3;
    unk_D_86002F34_000_014_010* var_t0;
    u32 tmp1;
    u32 tmp2;
    u32 tmp3;
    u32 tmp4;
    u32 tmp5;
    u32 tmp6;
    u32 tmp7;
    u32 tmp8;
    u32 tmp9;

    temp_a2 = D_8006F09C->unk_000.unk_14;
    temp_a3 = (D_8006F09C->unk_040.unk_08 >> 0x10) + 1;

    switch (arg1->unk_00) {
        default:
            var_a0 = sp34;
            var_v1 = sp38;
            var_v0 = sp30;
            break;

        case 1:
            if (temp_a3 < 0xF) {
                var_v1 = 0;
                var_v0 = (temp_a3 << 8) / 15;
                var_a0 = 1;
            } else if (temp_a3 < 0x1D) {
                var_v1 = 1;
                var_v0 = ((temp_a3 << 8) - 0xF00) / 14;
                var_a0 = 2;
            } else {
                var_v1 = 2;
                var_a0 = 2;
                var_v0 = 0;
            }
            break;

        case 2:
            if (temp_a3 < 5) {
                var_v1 = 0;
                var_v0 = (temp_a3 << 8) / 5;
                var_a0 = 1;
            } else if (temp_a3 < 0xF) {
                var_v1 = 1;
                var_v0 = ((temp_a3 << 8) - 0x500) / 10;
                var_a0 = 2;
            } else if (temp_a3 < 0x1D) {
                var_v1 = 2;
                var_v0 = ((temp_a3 << 8) - 0xF00) / 14;
                var_a0 = 3;
            } else {
                var_v1 = 3;
                var_a0 = 3;
                var_v0 = 0;
            }
            break;
    }

    switch (temp_a2) {
        default:
            var_t0 = sp20;
            var_a3 = sp24;
            var_a2 = sp28;
            var_a1 = sp2C;
            break;

        case 0:
            var_a3 = &arg1->unk_10[var_v1];
            var_t0 = &arg1->unk_10[var_a0];
            var_a1 = &arg1->unk_04[var_v1];
            var_a2 = &arg1->unk_04[var_a0];
            break;

        case 1:
            var_a3 = &arg1->unk_14[var_v1];
            var_t0 = &arg1->unk_14[var_a0];
            var_a1 = &arg1->unk_08[var_v1];
            var_a2 = &arg1->unk_08[var_a0];
            break;

        case 2:
            var_a3 = &arg1->unk_18[var_v1];
            var_t0 = &arg1->unk_18[var_a0];
            var_a1 = &arg1->unk_0C[var_v1];
            var_a2 = &arg1->unk_0C[var_a0];
            break;
    }

    gDPPipeSync(arg0++);

    tmp5 = ((var_a1->unk_00[4] * (0x100 - var_v0)) + (var_a2->unk_00[4] * var_v0)) >> 8;

    tmp1 = ((var_a1->unk_00[0] * (0x100 - var_v0)) + (var_a2->unk_00[0] * var_v0));
    tmp1 >>= 8;
    tmp2 = ((var_a1->unk_00[1] * (0x100 - var_v0)) + (var_a2->unk_00[1] * var_v0));
    tmp2 >>= 8;
    tmp3 = ((var_a1->unk_00[2] * (0x100 - var_v0)) + (var_a2->unk_00[2] * var_v0));
    tmp3 >>= 8;
    tmp4 = ((var_a1->unk_00[3] * (0x100 - var_v0)) + (var_a2->unk_00[3] * var_v0));
    tmp4 >>= 8;

    tmp6 = ((var_a3->unk_00[0] * (0x100 - var_v0)) + (var_t0->unk_00[0] * var_v0));
    tmp6 >>= 8;
    tmp7 = ((var_a3->unk_00[1] * (0x100 - var_v0)) + (var_t0->unk_00[1] * var_v0));
    tmp7 >>= 8;
    tmp8 = ((var_a3->unk_00[2] * (0x100 - var_v0)) + (var_t0->unk_00[2] * var_v0));
    tmp8 >>= 8;
    tmp9 = ((var_a3->unk_00[3] * (0x100 - var_v0)) + (var_t0->unk_00[3] * var_v0));
    tmp9 >>= 8;

    gDPSetPrimColor(arg0++, 0, tmp5, tmp1, tmp2, tmp3, tmp4);

    gDPSetEnvColor(arg0++, tmp1, tmp2, tmp3, tmp4);

    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/3/fragment3_11BF90/func_87903920.s")
#endif

void func_87903D64(s32 arg0, arg1_func_87903D64* arg1) {
    if (arg0 == 5) {
        arg1_func_87903D64_014* tmp = arg1->unk_14;

        gDisplayListHead = func_87903920(gDisplayListHead, tmp);
    }
}
