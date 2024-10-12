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
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/math_util.h"
#include "src/memory.h"
#include "src/fragments/43/fragment43.h"
#include "src/util.h"

extern u32 D_83407B30;

void func_8002FA40(void) {
    s32 var_s6;
    u32* temp_s0;
    u32 var_s0;
    u32 var_s2;
    u32 sp64;
    u32 var_s5;
    u32 sp5C;
    s32 var_v0;
    u32* val;

    val = &D_83407B30;
    var_s2 = 0;
    var_s5 = 0;

    main_pool_push_state('SNPM');
    func_8004B1CC(0x4B);

    FRAGMENT_LOAD(fragment43)();
    FRAGMENT_LOAD(fragment34);

    do {
        temp_s0 = Util_ConvertAddrToVirtAddr(val);
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_8002FF00.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_8002FF20.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_8003107C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031140.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031204.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031270.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031390.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800314BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_80031660.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800317D8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_8003181C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800318AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/30640/func_800318B8.s")

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
