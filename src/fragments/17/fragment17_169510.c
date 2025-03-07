#include "fragment17.h"

void func_86B09B80(Mtx* arg0, MtxF* arg1) {
    arg0->m[0][0] =
        ((s32)(arg1->mf[0][0] * 65536.0f) & 0xFFFF0000) | (((s32)(arg1->mf[0][1] * 65536.0f) >> 0x10) & 0xFFFF);
    arg0->m[0][1] =
        ((s32)(arg1->mf[0][2] * 65536.0f) & 0xFFFF0000) | (((s32)(arg1->mf[0][3] * 65536.0f) >> 0x10) & 0xFFFF);
    arg0->m[0][2] =
        ((s32)(arg1->mf[1][0] * 65536.0f) & 0xFFFF0000) | (((s32)(arg1->mf[1][1] * 65536.0f) >> 0x10) & 0xFFFF);
    arg0->m[0][3] =
        ((s32)(arg1->mf[1][2] * 65536.0f) & 0xFFFF0000) | (((s32)(arg1->mf[1][3] * 65536.0f) >> 0x10) & 0xFFFF);
    arg0->m[1][0] =
        ((s32)(arg1->mf[2][0] * 65536.0f) & 0xFFFF0000) | (((s32)(arg1->mf[2][1] * 65536.0f) >> 0x10) & 0xFFFF);
    arg0->m[1][1] =
        ((s32)(arg1->mf[2][2] * 65536.0f) & 0xFFFF0000) | (((s32)(arg1->mf[2][3] * 65536.0f) >> 0x10) & 0xFFFF);
    arg0->m[1][2] =
        ((s32)(arg1->mf[3][0] * 65536.0f) & 0xFFFF0000) | (((s32)(arg1->mf[3][1] * 65536.0f) >> 0x10) & 0xFFFF);
    arg0->m[1][3] =
        ((s32)(arg1->mf[3][2] * 65536.0f) & 0xFFFF0000) | (((s32)(arg1->mf[3][3] * 65536.0f) >> 0x10) & 0xFFFF);
    arg0->m[2][0] = ((s32)(arg1->mf[0][0] * 65536.0f) << 0x10) | ((s32)(arg1->mf[0][1] * 65536.0f) & 0xFFFF);
    arg0->m[2][1] = ((s32)(arg1->mf[0][2] * 65536.0f) << 0x10) | ((s32)(arg1->mf[0][3] * 65536.0f) & 0xFFFF);
    arg0->m[2][2] = ((s32)(arg1->mf[1][0] * 65536.0f) << 0x10) | ((s32)(arg1->mf[1][1] * 65536.0f) & 0xFFFF);
    arg0->m[2][3] = ((s32)(arg1->mf[1][2] * 65536.0f) << 0x10) | ((s32)(arg1->mf[1][3] * 65536.0f) & 0xFFFF);
    arg0->m[3][0] = ((s32)(arg1->mf[2][0] * 65536.0f) << 0x10) | ((s32)(arg1->mf[2][1] * 65536.0f) & 0xFFFF);
    arg0->m[3][1] = ((s32)(arg1->mf[2][2] * 65536.0f) << 0x10) | ((s32)(arg1->mf[2][3] * 65536.0f) & 0xFFFF);
    arg0->m[3][2] = ((s32)(arg1->mf[3][0] * 65536.0f) << 0x10) | ((s32)(arg1->mf[3][1] * 65536.0f) & 0xFFFF);
    arg0->m[3][3] = ((s32)(arg1->mf[3][2] * 65536.0f) << 0x10) | ((s32)(arg1->mf[3][3] * 65536.0f) & 0xFFFF);
}

void func_86B09EF0(MtxF* arg0, f32 arg1) {
    arg0->mf[0][0] *= arg1;
    arg0->mf[1][0] *= arg1;
    arg0->mf[2][0] *= arg1;

    arg0->mf[0][1] *= arg1;
    arg0->mf[1][1] *= arg1;
    arg0->mf[2][1] *= arg1;

    arg0->mf[0][2] *= arg1;
    arg0->mf[1][2] *= arg1;
    arg0->mf[2][2] *= arg1;
}

#ifdef NON_MATCHING
void func_86B09F64(MtxF* arg0, f32 arg1, f32 arg2, f32 arg3, u16 arg4, u16 arg5) {
    arg0->mf[0][0] = (COSS(arg4) * COSS(arg5)) + (SINS(arg4) * SINS(arg4) * SINS(arg5));
    arg0->mf[1][0] = (-COSS(arg4) * SINS(arg5)) + (SINS(arg4) * SINS(arg4) * COSS(arg5));
    arg0->mf[2][0] = COSS(arg4) * SINS(arg4);
    arg0->mf[3][0] = arg1;

    arg0->mf[0][1] = COSS(arg4) * SINS(arg5);
    arg0->mf[2][1] = -SINS(arg4);
    arg0->mf[1][1] = COSS(arg4) * COSS(arg5);
    arg0->mf[3][1] = arg2;

    arg0->mf[0][2] = (SINS(arg4) * COSS(arg4) * SINS(arg5)) + (-SINS(arg4) * COSS(arg5));
    arg0->mf[1][2] = (SINS(arg4) * COSS(arg4) * COSS(arg5)) + (SINS(arg4) * SINS(arg5));
    arg0->mf[2][2] = COSS(arg4) * COSS(arg4);
    arg0->mf[3][2] = arg3;

    arg0->mf[0][3] = 0.0f;
    arg0->mf[1][3] = 0.0f;
    arg0->mf[2][3] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_169510/func_86B09F64.s")
#endif
