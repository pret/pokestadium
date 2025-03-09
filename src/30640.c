#include "30640.h"
#include "include/libc/math.h"
#include "src/11BA0.h"
#include "src/12D80.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/geo_layout.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/29BA0.h"
#include "src/3FB0.h"
#include "src/4BDC0.h"
#include "src/F420.h"
#include "src/math_util.h"
#include "src/memory.h"
#include "src/util.h"

extern s32 D_80075F84;
extern unk_func_80031270* D_80075F80;
extern s32 D_80075F90;
extern u32 D_80075FA0[];

void func_800318B8(void);
void func_8340051C(void);

void func_8002FA40(void) {
    s32 var_s6;
    u32* temp_s0;
    u32 var_s0;
    u32 var_s2;
    u32 sp64;
    u32 var_s5;
    u32 sp5C;
    s32 var_v0;
    unk_D_83407B00* val;

    val = &D_83407B30;
    var_s2 = 0;
    var_s5 = 0;

    main_pool_push_state('SNPM');
    func_8004B1CC(0x4B);

    FRAGMENT_LOAD(fragment43)();
    FRAGMENT_LOAD(fragment34);

    do {
        temp_s0 = Util_ConvertAddrToVirtAddr((u32)val);
        var_s6 = 1;

        main_pool_push_state('galy');

        switch (var_s5) {
            case 0:
                var_v0 = 0;
                if (*temp_s0 != 0) {
                    var_s0 = 1;
                } else {

                    switch (var_s2) {
                        case 4:
                            var_s0 = 2;
                            break;

                        default:
                            var_s0 = 0;
                            if (var_s2 == 7) {
                                var_v0 = 1;
                            }
                            break;
                    }
                }
                sp64 = FRAGMENT_LOAD_AND_CALL(fragment42, var_s0, var_v0);
                break;

            case 1:
            case 6:
                FRAGMENT_LOAD(fragment2)();
                // loaded, but doesnt use any GFX from it. speculated to have intended using the
                // button GFX for How to Snap, but it doesnt use them.
                ASSET_LOAD(D_3000000, kids_club_game_ui, 0);
                FRAGMENT_LOAD(fragment3);
                FRAGMENT_LOAD(fragment31);

                // determine if this is "How to Snap" or regular Snap Mode.
                if (var_s5 == 1) {
                    var_s0 = 0;
                } else {
                    var_s0 = 1;
                }

                switch (FRAGMENT_LOAD_AND_CALL(fragment15, var_s0, 0)) {
                    case 1:
                        sp64 = 5;
                        break;

                    case 2:
                        if (var_s0 == 1) {
                            sp64 = 5;
                        } else {
                            sp64 = 2;
                        }
                        break;

                    default:
                        sp64 = 5;
                        break;
                }
                break;

            case 2:
                if (var_s2 == 4) {
                    var_s0 = 0;
                } else {
                    var_s0 = 1;
                }
                sp64 = FRAGMENT_LOAD_AND_CALL(fragment45, var_s0, 0);
                break;

            case 3:
                var_v0 = 1;
                switch (var_s2) {
                    case 4:
                        var_s0 = sp5C;
                        var_v0 = 0;
                        break;

                    case 2:
                        var_s0 = 1;
                        break;

                    default:
                        if (*temp_s0 != 0) {
                            var_s0 = 2;
                        } else {
                            var_s0 = 0;
                        }
                        break;
                }

                sp64 = FRAGMENT_LOAD_AND_CALL(fragment44, var_s0, var_v0);
                if (sp64 == 4) {
                    sp5C = var_s0;
                }
                break;

            case 4:
                FRAGMENT_LOAD_AND_CALL(fragment46, 0, 0);
                sp64 = var_s2;
                break;

            case 5:
                FRAGMENT_LOAD(fragment61);
                switch (var_s2) {
                    case 1:
                        var_s0 = 1;
                        break;

                    case 6:
                        var_s0 = 2;
                        break;

                    default:
                        var_s0 = 0;
                        break;
                }
                sp64 = FRAGMENT_LOAD_AND_CALL(fragment47, var_s0, 0);
                break;

            case 7:
                FRAGMENT_LOAD_AND_CALL(fragment49, 0, 0);
                sp64 = 0;
                break;

            default:
                var_s6 = 0;
                break;
        }

        var_s2 = var_s5;
        var_s5 = sp64;

        main_pool_pop_state('galy');

    } while (var_s6 != 0);

    ((ret_func_80004454)Util_ConvertAddrToVirtAddr(func_8340051C))();

    main_pool_pop_state('SNPM');
}

void func_8002FF00(void) {
    func_800318B8();
}

void func_8002FF20(void) {
    D_80075F90 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_8002FF2C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_8002FF3C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_8002FF7C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_8002FF8C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80030010.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800300CC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_8003013C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800301A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80030210.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80030228.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80030240.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800302A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800303C8.s")

void func_8003107C(unk_D_83402EE0_070* arg0, unk_func_80026268_arg0* arg1) {
    s32 i;

    bzero(arg0, sizeof(unk_D_83402EE0_070));
    arg0->unk_00 = arg1->unk_0E;
    arg0->unk_02 = arg1->unk_00;

    for (i = 0; i < 11; i++) {
        arg0->unk_03[i] = ((s8*)arg1->unk_30)[i];
    }

    for (i = 0; i < 11; i++) {
        arg0->unk_0E[i] = ((s8*)arg1->unk_3B)[i];
    }
}

void func_80031140(unk_func_80026268_arg0* arg0, unk_D_83407AC8* arg1) {
    s32 i;

    bzero(arg0, sizeof(unk_func_80026268_arg0));

    arg0->unk_0E = arg1->unk_00;
    arg0->unk_00 = arg1->unk_02;

    for (i = 0; i < 11; i++) {
        arg0->unk_30[i] = arg1->unk_03[i];
    }

    for (i = 0; i < 11; i++) {
        arg0->unk_3B[i] = arg1->unk_0E[i];
    }
}

void func_80031204(unk_func_80031270* arg0, s16 arg1, s16 arg2) {
    UNUSED s32 pad;
    MemoryBlock* sp18;

    sp18 = func_80002D10(main_pool_get_available(), 0);
    D_80075F80 = arg0;
    arg0->unk_1C = process_geo_layout(sp18, D_80075FA0);
    D_80075F80 = NULL;
    func_80002D60(sp18);
}

unk_func_80031270* func_80031270(s16 arg0, s16 arg1, unk_D_80068BB0* arg2, unk_D_80068BB0* arg3,
                                 unk_D_86002F58_004_000_010* arg4, BinArchive* arg5, unk_D_83403C60* arg6) {
    unk_D_80068BB0* var_v0;
    unk_func_80031270* temp_v0 = main_pool_alloc(sizeof(unk_func_80031270), 0);

    if (temp_v0 != NULL) {
        temp_v0->unk_00 = 0;
        temp_v0->unk_02 = 0;
        temp_v0->unk_04 = arg0;
        temp_v0->unk_06 = arg1;

        if (arg2 != NULL) {
            temp_v0->unk_08 = arg2;
        } else {
            temp_v0->unk_08 = func_80006314(0, 2, arg0, arg1, 0);
        }

        if (arg3 != NULL) {
            temp_v0->unk_0C = arg3;
        } else {
            temp_v0->unk_0C = func_80006314(0, 2, arg0, arg1, 1);
        }

        func_80006414(temp_v0->unk_08, temp_v0->unk_0C);

        temp_v0->unk_10 = arg4;
        temp_v0->unk_14 = arg5;
        temp_v0->unk_18 = arg6;
        temp_v0->unk_34 = 0;

        if (D_80075F90 == 0) {
            D_80075F90 = func_80006314(0, 2, 0xC8, 0x2B, 0);
        }

        func_80031204(temp_v0, arg0, arg1);
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031390.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800314BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031660.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800317D8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_8003181C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800318AC.s")

void func_800318B8(void) {
    D_80075F84 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800318C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800318F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031910.s")

f32 func_80031A6C(f32 arg0) {
    if (arg0 < 0.0) {
        arg0 = -arg0;
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031A94.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031B04.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031B98.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031BE8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031C6C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031DF8.s")

void func_80031EF4(MtxF* arg0, MtxF* arg1) {
    f32 sp24 = sqrtf(SQ(arg1->mf[0][0]) + SQ(arg1->mf[0][1]) + SQ(arg1->mf[0][2]));
    f32 sp20 = sqrtf(SQ(arg1->mf[1][0]) + SQ(arg1->mf[1][1]) + SQ(arg1->mf[1][2]));
    f32 sp1C = sqrtf(SQ(arg1->mf[2][0]) + SQ(arg1->mf[2][1]) + SQ(arg1->mf[2][2]));

    arg0->mf[0][0] = arg1->mf[0][0] * sp24;
    arg0->mf[0][1] = arg1->mf[1][0] * sp24;
    arg0->mf[0][2] = arg1->mf[2][0] * sp24;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = arg1->mf[0][1] * sp20;
    arg0->mf[1][1] = arg1->mf[1][1] * sp20;
    arg0->mf[1][2] = arg1->mf[2][1] * sp20;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2] * sp1C;
    arg0->mf[2][1] = arg1->mf[1][2] * sp1C;
    arg0->mf[2][2] = arg1->mf[2][2] * sp1C;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = 0.0f;
    arg0->mf[3][1] = 0.0f;
    arg0->mf[3][2] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void func_80032034(MtxF* arg0, Vec3f* arg1) {
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    temp_fv0 = arg0->mf[0][0];
    temp_fv1 = arg0->mf[0][1];
    temp_fa1 = arg0->mf[0][2];

    sp30 = arg0->mf[1][0];
    sp2C = arg0->mf[1][1];
    sp28 = arg0->mf[1][2];

    sp24 = arg0->mf[2][0];
    sp20 = arg0->mf[2][1];
    sp1C = arg0->mf[2][2];

    arg1->x = sqrtf(SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa1));
    arg1->y = sqrtf(SQ(sp30) + SQ(sp2C) + SQ(sp28));
    arg1->z = sqrtf(SQ(sp24) + SQ(sp20) + SQ(sp1C));
}
