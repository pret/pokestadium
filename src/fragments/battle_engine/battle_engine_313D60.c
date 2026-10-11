#include "battle_engine.h"
#include "src/geo_node.h"
#include "src/model_animation.h"
#include "src/text_system.h"
#include "src/audio_commands.h"
#include "src/matrix.h"
#include "src/memory.h"
#include "src/util.h"

unk_D_84390240 gBattleScene;
static s32 pad_D_84390280;
static s32 D_84390284;
s32 D_84390288;
static s32 pad_D_84390290[4];

void BattleScene_FinalPresentationFrameActiveOwner(unk_D_86002F34_00C* arg0) {
    f32 sp3C;

    BattleScene_SetCameraClipPlanes(arg0, 20.0f, 12800.0f);
    BattleAnim_GetOwnerDefaultAnchorPosition(D_84390010[D_84390284], &gBattleScene.unk_00->unk_D0);
    sp3C = BattleScene_ScaleCameraDistance(D_84390010[D_84390284], 3.5f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(D_84390010[D_84390284], arg0, gBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(D_84390010[D_84390284]),
                  0.0f, 0.0f);
    BattleScene_SetCameraEyeFromAt(arg0, 0, BattleScene_GetParticipantFacingAngle(D_84390010[D_84390284]), sp3C, 0.0f);

    if (D_84390010[0]) {}
    gBattleScene.unk_00->unk_20 += 1;
    if (D_84390284) {}
}

void BattleScene_FinalPresentationFrameOwner0(unk_D_86002F34_00C* arg0) {
    f32 sp3C;

    BattleScene_SetCameraClipPlanes(arg0, 20.0f, 12800.0f);
    BattleAnim_GetOwnerDefaultAnchorPosition(D_84390010[0], &gBattleScene.unk_00->unk_D0);
    sp3C = BattleScene_ScaleCameraDistance(D_84390010[0], 3.5f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(D_84390010[0], arg0, gBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(*D_84390010), 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromAt(arg0, 0, BattleScene_GetParticipantFacingAngle(*D_84390010), sp3C, 0.0f);

    if (D_84390010[0]) {}
    gBattleScene.unk_00->unk_20 += 1;
}

void BattleScene_RunFinalPresentation(unk_D_86002F34_00C* arg0, UNUSED Battler* arg1, UNUSED Battler* arg2) {
    gBattleScene.unk_00->unk_40 = 0;
    gBattleScene.unk_00->unk_60 = 30.0f;
    gBattleScene.unk_00->unk_6C = 10.0f;

    switch (gBattleScene.unk_00->unk_1C) {
        case 0:
            BattleScene_FinalPresentationFrameActiveOwner(arg0);
            break;

        case 1:
            BattleScene_SelectNextIntroCameraShot(arg0);
            break;

        case 2:
            BattleScene_InitializeBattlePresentation(arg0);
            BattleScene_SetPhase(arg0, 1);
            break;

        case 3:
            BattleScene_FinalPresentationFrameOwner0(arg0);
            break;

        case 4:
            BattleScene_IntroSetupCamera(arg0);
            break;
    }
    gBattleScene.unk_00->unk_DC = arg0;
}

void BattleScene_Init(void) {
    gBattleScene.unk_00 = main_pool_alloc(sizeof(BattleScene), 0);
    bzero(gBattleScene.unk_00, sizeof(BattleScene));
}

void func_843297E8(UNUSED unk_D_86002F34_00C* arg0) {
}

void func_843297F0(UNUSED unk_D_86002F34_00C* arg0) {
}

void BattleScene_AvoidDegenerateCameraLookAt(unk_D_86002F34_00C* arg0) {
    if (BattleAnim_Distance2D(arg0->unk_60.at.x, arg0->unk_60.at.z, arg0->unk_60.eye.x, arg0->unk_60.eye.z) < 0.0001f) {
        arg0->unk_60.at.z += 0.001f;
    }
}

void BattleScene_TickCameraSubstateDefault(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_30) {
        case 0:
            gBattleScene.unk_00->unk_18 = 0;
            break;

        case 1:
            if (gBattleScene.unk_00->unk_44 == 2) {
                BattleScene_ClearBothOwnerActiveFlags();
            }
            gBattleScene.unk_00->unk_30++;
            break;

        case 2:
            if (D_84390010[0]->unk_728.unk_168->unk_1C == -0x48) {
                gBattleScene.unk_00->unk_30++;
            }
            break;

        case 3:
            GeoCamera_SetBackgroundTexture(arg0, 0x12C, 0xA, 2, Util_ConvertAddrToVirtAddr((u32)D_1000000));
            GeoCamera_SetBackground(arg0, 5, 0xA, 0, 0, 0);
            gBattleScene.unk_00->unk_18 = 0;
            gBattleScene.unk_00->unk_30 += 1;

        case 4:
            if (arg0->unk_CC.unk_0A == 0xA) {
                BattleScene_ResetAnimationStep();
                BattleScene_ResetBothParticipantsAnimationState();
                BattleScene_CleanupParticipantEffectMode(D_84390010[0]);
                BattleScene_CleanupParticipantEffectMode(D_84390010[1]);
                gBattleScene.unk_00->unk_30 += 1;
                gBattleScene.unk_00->unk_18 = 1;
            }
            break;

        case 5:
            if ((BattleScene_AdvanceBothOwnerAnimations() == 0) && (BattleScene_AdvanceDoublesOwnerAnimation(D_84390010[gBattleScene.unk_00->unk_2A]) == 0)) {
                if (gBattleScene.unk_00->unk_44 == 1) {
                    BattleAnim_CleanupEffects(2);
                    BattleScene_QuantizePresentationTimer();
                }
                Battle_ResetCryEventIfStruggle(D_84390010[0]);
                Battle_ResetCryEventIfStruggle(D_84390010[1]);
                gBattleScene.unk_00->unk_18 = 2;
                GeoCamera_SetBackgroundTexture(arg0, 0xA, 0x12C, 2, Util_ConvertAddrToVirtAddr((u32)D_1000000));
                GeoCamera_SetBackground(arg0, 4, 0xA, 0, 0, 0);
                arg0->unk_24.fovy = 30.0f;
                gBattleScene.unk_00->unk_60 = 30.0f;
                gBattleScene.unk_00->unk_30 += 1;
            }
            break;

        case 6:
            BattleScene_ResetAnimationStep();
            arg0->unk_24.fovy = 30.0f;
            gBattleScene.unk_00->unk_60 = 30.0f;
            gBattleScene.unk_00->unk_18 = 0;
            if (arg0->unk_CC.unk_0A == 0xA) {
                gBattleScene.unk_00->unk_30 = 0;
                if (gBattleScene.unk_00->unk_44 == 1) {
                    BattleScene_SetBothOwnerActiveFlags();
                }
            }
            break;
    }
}

void BattleScene_TickCameraSubstateStripWipe(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_30) {
        case 0:
            gBattleScene.unk_00->unk_18 = 0;
            break;

        case 1:
            if (gBattleScene.unk_00->unk_44 == 2) {
                BattleScene_ClearBothOwnerActiveFlags();
            }
            gBattleScene.unk_00->unk_30++;
            break;

        case 2:
            if (D_84390010[0]->unk_728.unk_168->unk_1C == -0x48) {
                gBattleScene.unk_00->unk_30++;
            }
            break;

        case 3:
            BattleScene_SetStripWipeState(3, 0x1E);
            BattleScene_UpdateStripWipe();
            gBattleScene.unk_00->unk_18 = 0;
            gBattleScene.unk_00->unk_30 += 1;

        case 4:
            BattleScene_UpdateStripWipe();
            if (BattleScene_GetStripWipeState() == 1) {
                BattleScene_ResetAnimationStep();
                BattleScene_ResetBothParticipantsAnimationState();
                BattleScene_CleanupParticipantEffectMode(D_84390010[0]);
                BattleScene_CleanupParticipantEffectMode(D_84390010[1]);
                gBattleScene.unk_00->unk_30 += 1;
                gBattleScene.unk_00->unk_18 = 1;
            }
            break;

        case 5:
            gBattleScene.unk_00->unk_18 = 1;
            gBattleScene.unk_00->unk_30 += 1;
            break;

        case 6:
            gBattleScene.unk_00->unk_18 = 1;
            gBattleScene.unk_00->unk_30 += 1;
            break;

        case 7:
            gBattleScene.unk_00->unk_18 = 1;
            gBattleScene.unk_00->unk_30 += 1;
            break;

        case 8:
            if ((BattleScene_AdvanceBothOwnerAnimations() == 0) && (BattleScene_AdvanceDoublesOwnerAnimation(D_84390010[gBattleScene.unk_00->unk_2A]) == 0)) {
                if (gBattleScene.unk_00->unk_44 == 1) {
                    BattleAnim_CleanupEffects(2);
                    BattleScene_QuantizePresentationTimer();
                }
                Battle_ResetCryEventIfStruggle(D_84390010[0]);
                Battle_ResetCryEventIfStruggle(D_84390010[1]);
                gBattleScene.unk_00->unk_18 = 2;
                BattleScene_SetStripWipeState(2, 0x1E);
                BattleScene_UpdateStripWipe();
                arg0->unk_24.fovy = 30.0f;
                gBattleScene.unk_00->unk_60 = 30.0f;
                gBattleScene.unk_00->unk_30 += 1;
            }
            break;

        case 9:
            BattleScene_ResetAnimationStep();
            arg0->unk_24.fovy = 30.0f;
            gBattleScene.unk_00->unk_60 = 30.0f;
            gBattleScene.unk_00->unk_18 = 0;
            BattleScene_UpdateStripWipe();
            if (BattleScene_GetStripWipeState() == 0) {
                gBattleScene.unk_00->unk_30 = 0;
                if (gBattleScene.unk_00->unk_44 == 1) {
                    BattleScene_SetBothOwnerActiveFlags();
                }
            }
            break;
    }
}

void BattleScene_TickCameraSubstate(unk_D_86002F34_00C* arg0) {
    if (gBattleScene.unk_00->unk_2E == 0) {
        BattleScene_TickCameraSubstateDefault(arg0);
    } else {
        BattleScene_TickCameraSubstateStripWipe(arg0);
    }
}

u16 BattleScene_IsOwnerInViewWedge(Battler* arg0, unk_D_86002F34_00C* arg1, Battler* a2, s16 arg3, f32 arg4) {
    UNUSED s32 pad[6];
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    UNUSED s32 pad2;
    f32 sp54;
    f32 sp50;
    UNUSED s32 pad3;
    f32 sp48;
    s16 sp46;
    s16 sp44;
    f32 sp40;
    Battler* arg2;
    f32 sp38;
    s32 sp34 = 0;

    BattleAnim_CalculateDistanceAngles(&arg1->unk_60.at, &arg1->unk_60.eye, &sp48, &sp46, &sp44);
    sp40 = (COSS((sp44 - 0x8000)) * 50.0f) + arg1->unk_60.eye.z;
    sp38 = (SINS((sp44 - 0x8000)) * 30.0f) + arg1->unk_60.eye.x;
    sp54 = (COSS(((sp44 - arg3) + 0x8000)) * arg4) + sp40;
    sp60 = (SINS(((sp44 - arg3) + 0x8000)) * arg4) + sp38;
    sp50 = (COSS((sp44 + arg3 + 0x8000)) * arg4) + sp40;
    sp5C = (SINS((sp44 + arg3 + 0x8000)) * arg4) + sp38;

    arg2 = a2;

    sp6C = ((sp54 - arg2->unk_000.position.z) * (sp5C - arg2->unk_000.position.x)) -
           ((sp50 - arg2->unk_000.position.z) * (sp60 - arg2->unk_000.position.x));
    sp68 = ((sp50 - arg2->unk_000.position.z) * (sp38 - arg2->unk_000.position.x)) -
           ((sp40 - arg2->unk_000.position.z) * (sp5C - arg2->unk_000.position.x));
    sp64 = ((sp40 - arg2->unk_000.position.z) * (sp60 - arg2->unk_000.position.x)) -
           ((sp54 - arg2->unk_000.position.z) * (sp38 - arg2->unk_000.position.x));

    if (((sp6C >= 0.0f) && (sp68 >= 0.0f) && (sp64 >= 0.0f)) || ((sp6C <= 0.0f) && (sp68 <= 0.0f) && (sp64 <= 0.0f))) {
        sp34 = 1;
    }
    return sp34;
}

u16 BattleScene_IsOwnerInViewWedgeAlt(Battler* arg0, unk_D_86002F34_00C* arg1, Battler* a2, s16 arg3, f32 arg4) {
    UNUSED s32 pad[6];
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    UNUSED s32 pad2;
    f32 sp7C;
    f32 sp78;
    Battler* arg2;
    f32 sp70;
    s16 sp6E;
    s16 sp6C;
    Vec3f sp60;
    s32 sp5C;

    sp5C = 0;
    BattleAnim_CalculateDistanceAngles(&arg1->unk_60.at, &arg1->unk_60.eye, &sp70, &sp6E, &sp6C);
    sp60.z = (COSS((sp6C - 0x8000)) * 30.0f) + arg1->unk_60.eye.z;
    sp60.x = (SINS((sp6C - 0x8000)) * 30.0f) + arg1->unk_60.eye.x;
    sp7C = (COSS(((sp6C - arg3) + 0x8000)) * arg4) + sp60.z;
    sp88 = (SINS(((sp6C - arg3) + 0x8000)) * arg4) + sp60.x;
    sp78 = (COSS((sp6C + arg3 + 0x8000)) * arg4) + sp60.z;
    sp84 = (SINS((sp6C + arg3 + 0x8000)) * arg4) + sp60.x;

    arg2 = a2;

    sp94 = ((sp7C - arg2->unk_000.position.z) * (sp84 - arg2->unk_000.position.x)) -
           ((sp78 - arg2->unk_000.position.z) * (sp88 - arg2->unk_000.position.x));
    sp90 = ((sp78 - arg2->unk_000.position.z) * (sp60.x - arg2->unk_000.position.x)) -
           ((sp60.z - arg2->unk_000.position.z) * (sp84 - arg2->unk_000.position.x));
    sp8C = ((sp60.z - arg2->unk_000.position.z) * (sp88 - arg2->unk_000.position.x)) -
           ((sp7C - arg2->unk_000.position.z) * (sp60.x - arg2->unk_000.position.x));

    if (((sp94 >= 0.0f) && (sp90 >= 0.0f) && (sp8C >= 0.0f)) || ((sp94 <= 0.0f) && (sp90 <= 0.0f) && (sp8C <= 0.0f))) {
        sp5C = 1;
    }

    sp60.x = a2->unk_000.position.x;
    sp60.y = a2->unk_000.position.y;
    sp60.z = a2->unk_000.position.z;

    if ((BattleScene_GetParticipantModelRadiusScaled(arg0) * 2.5f) >= BattleAnim_Vec3fDistance(arg1->unk_60.eye, sp60)) {
        sp5C = 0;
    }
    return sp5C;
}

void BattleScene_UpdateBothOwnersVisibilityCulling(unk_D_86002F34_00C* arg0) {
    if (BattleScene_IsOwnerInViewWedge(D_84390010[0], arg0, D_84390010[0], 0x2AA8, 2500.0f) != 0) {
        D_84390010[0]->unk_000.node.flags |= 1;
    } else {
        D_84390010[0]->unk_000.node.flags &= ~1;
    }

    if (BattleScene_IsOwnerInViewWedge(D_84390010[1], arg0, D_84390010[1], 0x2AA8, 2500.0f) != 0) {
        D_84390010[1]->unk_000.node.flags |= 1;
    } else {
        D_84390010[1]->unk_000.node.flags &= ~1;
    }
}

void BattleScene_UpdateOpponentVisibilityCulling(unk_D_86002F34_00C* arg0) {
    Battler* sp24 = D_84390010[!gBattleScene.unk_00->unk_2C];

    if (BattleScene_IsOwnerInViewWedgeAlt(sp24, arg0, sp24, 0x2AA8, 2500.0f) != 0) {
        sp24->unk_000.node.flags |= 1;
    } else {
        sp24->unk_000.node.flags &= 0xFFFE;
    }
}

void func_8432A414(void) {
}

void BattleScene_ShowBothOwners(void) {
    D_84390010[0]->unk_000.node.flags |= 1;
    D_84390010[1]->unk_000.node.flags |= 1;
}

void BattleScene_HideOpponentOwner(void) {
    Battle_ResetModelToIdleAnim(D_84390010[!gBattleScene.unk_00->unk_2C]);
    D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
}

void BattleScene_HideActiveOwner(void) {
    D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
    Battle_ResetModelToIdleAnim(D_84390010[gBattleScene.unk_00->unk_2C]);
}

void BattleScene_HideFaintedOwners(void) {
    Battler* ptr1 = D_84390010[0];
    Battler* ptr2 = D_84390010[1];

    if ((ptr1->unk_654.unk_2D == 0x10) || ((ptr1 = D_84390010[0])->unk_654.unk_2D == 0x13)) {
        ptr1->unk_000.node.flags &= ~1;
    }

    if ((ptr2->unk_654.unk_2D == 0x10) || (ptr2->unk_654.unk_2D == 0x13)) {
        ptr2->unk_000.node.flags &= ~1;
    }
}

void BattleScene_UpdateOwnerVisibilitySingle(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    BattlerState* sp40 = &D_84390204->unk_654;
    s32 temp_lo;
    BattlerState* sp38 = &D_84390200->unk_654;
    f32 sp34;
    s16 sp32;
    s16 sp30;

    switch (gBattleScene.unk_00->unk_1C) {
        case 0:
        case 3:
            break;

        case 1:
            BattleScene_ShowBothOwners();

            switch (gBattleScene.unk_00->unk_20) {
                case 12:
                case 13:
                case 14:
                case 15:
                case 21:
                    BattleScene_ShowBothOwners();
                    break;

                case 16:
                case 17:
                case 18:
                case 19:
                    D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                    break;

                default:
                    BattleScene_UpdateOpponentVisibilityCulling(arg0);
                    break;
            }
            break;

        case 2:
            BattleScene_ShowBothOwners();

            switch (gBattleScene.unk_00->unk_38) {
                case 2:
                case 3:
                    switch (gBattleScene.unk_00->unk_20) {
                        case 0:
                            if ((sp40->unk_2D == 0xF) && (gBattleScene.unk_00->unk_34 == 1)) {
                                BattleScene_HideActiveOwner();
                            } else {
                                Vec3f_CalculateDistanceAngles(&gBattleScene.unk_00->unk_B8, &gBattleScene.unk_00->unk_C4, &sp34, &sp32,
                                              &sp30);
                                temp_lo = sp30 / 182;
                                if (((temp_lo == 0x5A) || (temp_lo == -0x5A)) && (gBattleScene.unk_00->unk_34 == 1)) {
                                    BattleScene_HideOpponentOwner();
                                } else {
                                    BattleScene_UpdateOpponentVisibilityCulling(arg0);
                                }
                            }
                            break;

                        case 1:
                            gBattleScene.unk_00->unk_08 = 0;
                            if (!(sp40->unk_34 & 0x4400)) {
                                BattleScene_HideOpponentOwner();
                            }
                            break;

                        case 2:
                            if ((gBattleScene.unk_00->unk_3C == 0) && (gBattleScene.unk_00->unk_24 >= 0) &&
                                (gBattleScene.unk_00->unk_24 < 2) && (sp38->unk_34 & 0x800)) {
                                BattleScene_HideOpponentOwner();
                            } else if (((gBattleScene.unk_00->unk_3C == 0) || (gBattleScene.unk_00->unk_3C == 1)) &&
                                       (gBattleScene.unk_00->unk_48 == 0) && (gBattleScene.unk_00->unk_1A != 1)) {
                                Battle_ResetModelToIdleAnim(D_84390204);
                                D_84390204->unk_000.lodFraction = 0;
                            } else {
                                if (sp40->unk_34 & 0x4000) {
                                    if ((D_84390204->unk_000.objectType != 0x32) &&
                                        (D_84390204->unk_000.objectType != 0x33)) {
                                        D_84390204->unk_000.lodFraction = 0;
                                    } else {
                                        D_84390204->unk_000.lodFraction = 0xFF;
                                    }
                                } else {
                                    D_84390204->unk_000.lodFraction = 0xFF;
                                }
                                BattleScene_HideActiveOwner();
                            }
                            gBattleScene.unk_00->unk_08 = 1;
                            break;
                    }
                    break;

                case 36:
                    if (gBattleScene.unk_00->unk_08 == 1) {
                        BattleScene_HideOpponentOwner();
                    } else if (gBattleScene.unk_00->unk_08 == 2) {
                        D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                    } else if (gBattleScene.unk_00->unk_08 == 3) {
                        D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                    } else if (gBattleScene.unk_00->unk_08 == 4) {
                        D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                    }
                    break;

                case 4:
                    if (gBattleScene.unk_00->unk_08 == 1) {
                        BattleScene_HideActiveOwner();
                    } else if (gBattleScene.unk_00->unk_08 == 2) {
                        D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                    } else if (gBattleScene.unk_00->unk_08 == 3) {
                        D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                    } else if (gBattleScene.unk_00->unk_08 == 4) {
                        D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                    }
                    break;

                case 11:
                    gBattleScene.unk_00->unk_08 = 4;
                    if (gBattleScene.unk_00->unk_34 == 1) {
                        BattleScene_HideOpponentOwner();
                    } else if (gBattleScene.unk_00->unk_20 == 0) {
                        BattleScene_UpdateBothOwnersVisibilityCulling(arg0);
                    } else {
                        BattleScene_HideOpponentOwner();
                    }
                    break;

                case 18:
                    gBattleScene.unk_00->unk_08 = 3;
                    switch (gBattleScene.unk_00->unk_20) {
                        case 0:
                            BattleScene_UpdateBothOwnersVisibilityCulling(arg0);
                            break;

                        default:
                            BattleScene_HideOpponentOwner();
                            break;
                    }
                    break;

                case 12:
                    gBattleScene.unk_00->unk_08 = 0;
                    switch (gBattleScene.unk_00->unk_20) {
                        case 2:
                        case 3:
                        case 4:
                            BattleScene_ShowBothOwners();
                            break;

                        default:
                            BattleScene_HideOpponentOwner();
                            break;
                    }
                    break;

                case 37:
                    gBattleScene.unk_00->unk_08 = 0;
                    BattleScene_HideOpponentOwner();
                    break;

                case 7:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 20:
                case 21:
                case 25:
                case 27:
                case 28:
                case 29:
                case 31:
                case 38:
                    gBattleScene.unk_00->unk_08 = 3;
                    BattleScene_HideOpponentOwner();
                    break;

                case 9:
                case 35:
                    gBattleScene.unk_00->unk_08 = 3;
                    BattleScene_HideOpponentOwner();
                    break;

                case 6:
                    gBattleScene.unk_00->unk_08 = 0;
                    BattleScene_HideOpponentOwner();
                    break;

                case 8:
                case 10:
                    gBattleScene.unk_00->unk_08 = 0;
                    BattleScene_HideActiveOwner();
                    break;

                case 30:
                    gBattleScene.unk_00->unk_08 = 0;

                    switch (gBattleScene.unk_00->unk_20) {
                        case 0:
                        case 1:
                        case 2:
                            BattleScene_HideOpponentOwner();
                            break;

                        default:
                            BattleScene_HideActiveOwner();
                            break;
                    }
                    break;

                case 5:
                case 34:
                    gBattleScene.unk_00->unk_08 = 0;
                    switch (gBattleScene.unk_00->unk_20) {
                        case 0:
                        case 1:
                            D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                            break;
                    }
                    break;
            }
            break;
    }
    BattleScene_HideFaintedOwners();
}

void BattleScene_UpdateOwnerVisibilityDouble(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_1C) {
        case 1:
            BattleScene_ShowBothOwners();

            switch (gBattleScene.unk_00->unk_20) {
                case 12:
                case 13:
                case 14:
                case 15:
                case 21:
                    BattleScene_ShowBothOwners();
                    break;

                case 16:
                case 17:
                case 18:
                case 19:
                    D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                    break;

                default:
                    BattleScene_UpdateOpponentVisibilityCulling(arg0);
                    break;
            }
            break;

        case 2:
            switch (gBattleScene.unk_00->unk_38) {
                case 30:
                    switch (gBattleScene.unk_00->unk_20) {
                        case 0:
                        case 1:
                        case 2:
                        case 5:
                            D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                            D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.node.flags |= 1;
                            break;

                        default:
                            D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                            D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.node.flags |= 1;
                    }
                    break;

                case 5:
                case 34:
                    switch (gBattleScene.unk_00->unk_20) {
                        case 0:
                        case 1:
                            D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.node.flags &= ~1;
                            D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.node.flags |= 1;
                            break;
                    }
                    break;
            }
            break;
    }
    BattleScene_HideFaintedOwners();
}

void BattleScene_Update(unk_D_86002F34_00C* arg0) {
    BattleScene_TickCameraSubstate(arg0);
    BattleScene_ApplyCameraPhaseDefaults();
    BattleScene_UpdateOwnerVisibilitySingle(arg0);

    switch (gBattleScene.unk_00->unk_1C) {
        case 0:
            func_843297E8(arg0);
            break;

        case 1:
            BattleScene_UpdateIntroCameraSequence(arg0);
            break;

        case 2:
            BattleScene_TickPresentationTimer();
            BattleScene_UpdatePhase(arg0);
            break;

        case 3:
            func_843297F0(arg0);
            break;

        case 4:
            BattleScene_UpdateIntroSequence(arg0);
            break;

        default:
            gBattleScene.unk_00->unk_40 = 3;
            break;
    }

    BattleScene_UpdateOwnerVisibilityDouble(arg0);
    BattleScene_TickStateCallbacks();
    BattleAnim_TickParticipantStatusAnimation(D_84390018);
    BattleAnim_TickParticipantStatusAnimation(D_8439001C);
    BattleScene_ApplyCameraShake(arg0);
    BattleScene_ClampCameraEyeFloor(arg0);
    BattleScene_CameraHelperNop(arg0);
    BattleScene_AvoidDegenerateCameraLookAt(arg0);
}

s32 BattleScene_Dispatch(s32 arg0, unk_D_86002F34_00C* arg1) {
    switch (arg0) {
        case 0:
            BattleScene_Init();
            break;

        case 1:
        case 2:
            BattleScene_Update(arg1);
            break;

        case 3:
            BattleScene_RunFinalPresentation(arg1, D_84390010[0], D_84390010[1]);
            break;
    }
    return gBattleScene.unk_00->unk_40;
}
