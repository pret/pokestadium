#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/model_renderer.h"
#include "src/audio_commands.h"
#include "src/3D140.h"
#include "src/audio_fade.h"
#include "src/audio_loop_point.h"
#include "src/cry.h"
#include "src/matrix.h"

Battler* D_84390200;
Battler* D_84390204;
static f32 D_84390208;
static s32 pad_D_84390210[4];
static s32 D_84390220;
static s32 D_84390224;
static s32 D_84390228;
s32 D_8439022C;
s32 D_84390230;
s32 D_84390234;

u8 D_84385B70[] = {
    0x00, 0x03, 0x02, 0x06, 0x07,
};
u8 D_84385B78[] = {
    0x00,
    0x02,
    0x06,
    0x07,
};
u8 D_84385B7C[] = {
    0x02,
    0x06,
    0x07,
};
u8 D_84385B80[] = {
    0x04, 0x05, 0x08, 0x09, 0x0A, 0x0B,
};
u8 D_84385B88[] = {
    0x05,
    0x09,
    0x0A,
    0x0B,
};
u16 D_84385B8C = 0x5F92;
Vec3f D_84385B90 = { 0.0f, 100.0f, 0.0f };
Vec3f D_84385B9C = { 0.0f, 10.0f, 0.0f };

void BattleScene_ApplyModelAnimationSlot5A(Battler* arg0) {
    BattlerState* ptr = &arg0->unk_654;

    if ((arg0->unk_000.objectType == 0x32) && (ptr->unk_34 & 0x4000)) {
        MovePresentationCue* tmp = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[0x5A];

        ModelAnim_SetAnimation(&arg0->unk_000, tmp->unk_00);
        arg0->unk_000.node.renderFlags &= ~0x20;
    }
}

void BattleScene_ResetAnimationStep(void) {
    gBattleScene.unk_00->unk_24 = 0;
}

s32 BattleScene_AdvanceOwnerAnimation(Battler* arg0) {
    BattlerState* ptr = &arg0->unk_654;
    UNUSED s32 pad;
    s32 sp1C = 0;

    if (!(ptr->unk_34 & 0x800)) {
        return 0;
    }

    if (gBattleScene.unk_00->unk_48 == 0x19) {
        return 0;
    }

    if ((ptr->unk_34 & 0x800) && (gBattleScene.unk_00->unk_48 == 0x1C)) {
        return 0;
    }

    switch (gBattleScene.unk_00->unk_24) {
        case 0:
            BattleAnim_BeginSessionRequestForActiveMon(arg0);
            sp1C = 1;
            gBattleScene.unk_00->unk_24++;
            break;

        case 1:
            sp1C = 1;
            if (arg0->unk_720->unk_00 & 0x10) {
                arg0->unk_720->unk_00 &= ~0x90;
                Battle_ReloadModelForActiveMove(arg0);
                BattleScene_ApplyModelAnimationSlot5A(arg0);
                gBattleScene.unk_00->unk_24++;
            }
            break;

        case 2:
            BattleScene_ResetAnimationStep();
            break;
    }
    return sp1C;
}

s32 BattleScene_AdvanceOwnerAnimation98(Battler* arg0) {
    UNUSED s32 pad[2];
    s32 sp1C = 0;

    if (!(arg0->unk_654.unk_34 & 0x800)) {
        return 0;
    }

    switch (gBattleScene.unk_00->unk_24) {
        case 0:
            BattleAnim_BeginSessionRequest(arg0);
            sp1C = 1;
            gBattleScene.unk_00->unk_24++;
            break;

        case 1:
            sp1C = 1;
            if (arg0->unk_720->unk_00 & 0x10) {
                arg0->unk_720->unk_00 &= ~0x90;
                Battle_ReloadNeutralPlaceholderModel(arg0);
                gBattleScene.unk_00->unk_24++;
            }
            break;

        case 2:
            BattleScene_ResetAnimationStep();
            break;
    }
    return sp1C;
}

s32 BattleScene_AdvanceOwnerAnimationAndClearFlags(Battler* arg0) {
    UNUSED s32 pad[2];
    Vec3f sp34;
    s32 var_s0 = 0;

    if (!(arg0->unk_654.unk_34 & 0x1000)) {
        return 0;
    }

    switch (gBattleScene.unk_00->unk_24) {
        case 0:
            BattleAnim_BeginSessionRequestForActiveMon(arg0);
            var_s0 = 1;
            gBattleScene.unk_00->unk_24++;
            break;

        case 1:
            var_s0 = 1;
            if (arg0->unk_720->unk_00 & 0x10) {
                arg0->unk_720->unk_00 &= ~0x90;
                Battle_ReloadModelForActiveMove(arg0);
                Battle_ClearRuntimeFlags(arg0, 0x1800);
                var_s0 = 0;
                BattleScene_ResetAnimationStep();
                gBattleScene.unk_00->unk_24++;
            }
            break;

        case 2:
            BattleScene_ResetAnimationStep();
            BattleAnim_GetOwnerDefaultAnchorPosition(arg0, &sp34);
            BattleAnim_Vec3fCopy(&gBattleScene.unk_00->unk_DC->unk_60.at, &sp34);
            break;
    }
    return var_s0;
}

s32 BattleScene_AdvanceDoublesOwnerAnimation(Battler* arg0) {
    UNUSED s32 pad[2];
    s32 sp1C = 0;

    if (gBattleScene.unk_00->unk_44 != 2) {
        return 0;
    }

    if (!(arg0->unk_654.unk_34 & 0x800)) {
        return 0;
    }

    if ((gBattleScene.unk_00->unk_48 == 0x19) || (gBattleScene.unk_00->unk_48 == 0x1C)) {
        return 0;
    }

    switch (gBattleScene.unk_00->unk_24) {
        case 0:
            BattleAnim_BeginSessionRequestForActiveMon(arg0);
            sp1C = 1;
            gBattleScene.unk_00->unk_24 += 1;
            break;

        case 1:
            sp1C = 1;
            if (arg0->unk_720->unk_00 & 0x10) {
                arg0->unk_720->unk_00 &= ~0x90;
                Battle_ReloadModelForActiveMove(arg0);
                BattleScene_ApplyModelAnimationSlot5A(arg0);
                gBattleScene.unk_00->unk_24 += 1;
            }
            break;

        case 2:
            BattleScene_ResetAnimationStep();
            break;
    }
    return sp1C;
}

s32 BattleScene_AdvanceBothOwnerAnimations(void) {
    UNUSED s32 pad[2];
    s32 sp1C = 0;
    BattlerState* temp_a1 = &D_84390010[0]->unk_654;
    BattlerState* temp_a2 = &D_84390010[1]->unk_654;

    if (gBattleScene.unk_00->unk_44 != 1) {
        return 0;
    }

    if (!(temp_a1->unk_34 & 0x800) && !(temp_a2->unk_34 & 0x800)) {
        return 0;
    }

    switch (gBattleScene.unk_00->unk_24) {
        case 0:
            if (temp_a1->unk_34 & 0x800) {
                BattleAnim_BeginSessionRequest(D_84390010[0]);
            }
            sp1C = 1;
            gBattleScene.unk_00->unk_24 = gBattleScene.unk_00->unk_24 + 1;
            break;

        case 1:
            sp1C = 1;
            if (temp_a1->unk_34 & 0x800) {
                if (D_84390010[0]->unk_720->unk_00 & 0x10) {
                    D_84390010[0]->unk_720->unk_00 &= ~0x90;
                    Battle_ReloadNeutralPlaceholderModel(D_84390010[0]);
                    gBattleScene.unk_00->unk_24 += 1;
                }
            } else {
                gBattleScene.unk_00->unk_24 = gBattleScene.unk_00->unk_24 + 1;
            }
            break;

        case 2:
            if (temp_a2->unk_34 & 0x800) {
                BattleAnim_BeginSessionRequest(D_84390010[1]);
            }
            sp1C = 1;
            gBattleScene.unk_00->unk_24 = gBattleScene.unk_00->unk_24 + 1;
            break;

        case 3:
            sp1C = 1;
            if (temp_a2->unk_34 & 0x800) {
                if (D_84390010[1]->unk_720->unk_00 & 0x10) {
                    D_84390010[1]->unk_720->unk_00 &= ~0x90;
                    Battle_ReloadNeutralPlaceholderModel(D_84390010[1]);
                    gBattleScene.unk_00->unk_24 += 1;
                }
            } else {
                gBattleScene.unk_00->unk_24 = gBattleScene.unk_00->unk_24 + 1;
            }
            break;

        case 4:
            BattleScene_ResetAnimationStep();
            break;
    }

    return sp1C;
}

void BattleScene_ClearInactiveOwnerAnimationFlags(void) {
    BattleMonRuntime* temp_v0 = &D_84390010[0]->unk_654.unk_38;
    BattleMonRuntime* temp_v1 = &D_84390010[1]->unk_654.unk_38;

    if (temp_v0->unk_4F == 0) {
        temp_v0->unk_4C &= ~0x20;
    }

    if (temp_v1->unk_4F == 0) {
        temp_v1->unk_4C &= ~0x20;
    }
}

void func_8431FCC4(void) {
}

s32 BattleScene_AnimateDisplayedHpToRuntime(Battler* arg0) {
    BattleMonRuntime* temp_s1 = &arg0->unk_654.unk_38;
    BattleMon* temp_s2 = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    f32 temp_fs0;
    UNUSED s16 pad;
    s16 sp30;

    if (D_84390288 != 0) {
        return 1;
    }

    if (temp_s2->unk_02 == temp_s1->unk_0C) {
        return 1;
    }

    temp_fs0 = temp_s1->unk_28 / 90.0f;
    sp30 = BattleScene_GetParticipantSideIndex(arg0);
    D_843900A8[sp30] = Math_StepToF(D_843900A8[BattleScene_GetParticipantSideIndex(arg0)], temp_s1->unk_0C, temp_fs0, temp_fs0);
    temp_s2->unk_02 = D_843900A8[BattleScene_GetParticipantSideIndex(arg0)];
    if (temp_s2->unk_02 == temp_s1->unk_0C) {
        temp_fs0 = D_843900A8[BattleScene_GetParticipantSideIndex(arg0)] - temp_s2->unk_02;
        D_843900A8[BattleScene_GetParticipantSideIndex(arg0)] -= temp_fs0;
        if (arg0->unk_000.objectType == 0x98) {
            return 1;
        }
        return 1;
    }
    return 0;
}

void BattleScene_ClearPhaseFlag(void) {
    gBattleScene.unk_00->unk_3C = 0;
}

void BattleScene_SetPhaseFlag(void) {
    gBattleScene.unk_00->unk_3C = 1;
}

void BattleScene_SetPhase(UNUSED unk_D_86002F34_00C* arg0, s32 arg1) {
    gBattleScene.unk_00->unk_38 = arg1;
    gBattleScene.unk_00->unk_20 = 0;
}

void BattleScene_SaveCameraFov(unk_D_86002F34_00C* arg0) {
    gBattleScene.unk_00->unk_60 = arg0->unk_24.fovy;
}

void BattleScene_ResetCameraFov(unk_D_86002F34_00C* arg0) {
    arg0->unk_24.fovy = 30.0f;
    gBattleScene.unk_00->unk_60 = 30.0f;
}

s32 BattleScene_GetAnimationTimingField0D(Battler* arg0) {
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[arg0->unk_654.unk_38.unk_5A - 1];

    return ptr->unk_0D;
}

s32 BattleScene_GetMappedAnimationTimingField0D(Battler* arg0) {
    UNUSED s32 pad;
    s32 sp18 = D_84384670[arg0->unk_654.unk_38.unk_5A - 1];
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp18];

    return ptr->unk_0D;
}

s32 BattleScene_GetAnimationTimingField0E(Battler* arg0) {
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[arg0->unk_654.unk_38.unk_5A - 1];

    return ptr->unk_0E;
}

s32 BattleScene_GetMappedAnimationTimingField0E(Battler* arg0) {
    UNUSED s32 pad;
    s32 sp18 = D_84384670[arg0->unk_654.unk_38.unk_5A - 1];
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp18];

    return ptr->unk_0E;
}

s32 BattleScene_GetCameraShotDuration(Battler* arg0) {
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[arg0->unk_654.unk_38.unk_5A - 1];

    if (ptr->unk_0F == 0) {
        return 0xF;
    }
    return ptr->unk_0F;
}

void Battle_StartTurn(void) {
    s32 sp2C;
    BattlerState* temp_s0;
    BattlerState* temp_s1;
    BattleMonRuntime* ptr;

    temp_s0 = &D_84390010[0]->unk_654;
    temp_s1 = &D_84390010[1]->unk_654;
    BattleScene_SetCameraSubstate(1, 1);

    sp2C = gBattleScene.unk_00->unk_2C;
    gBattleScene.unk_00->unk_2C = Battle_DetermineMoveOrder(D_84390010[0], D_84390010[1]);

    ptr = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;
    if ((ptr->unk_5A & 0xF0) == 0xF0) {
        gBattleScene.unk_00->unk_2C = !gBattleScene.unk_00->unk_2C;
    }

    if (D_84390010[0]->unk_724->unk_000 & 2) {
        if (gBattleScene.unk_00->unk_2C == 0) {
            BattleAI_RecordUsedMove(temp_s0->unk_08, temp_s1->unk_08, 0);
        } else {
            BattleAI_RecordUsedMove(temp_s0->unk_08, temp_s1->unk_08, 1);
        }
    } else if (D_84390010[1]->unk_724->unk_000 & 2) {
        if (gBattleScene.unk_00->unk_2C == 1) {
            BattleAI_RecordUsedMove(temp_s1->unk_08, temp_s0->unk_08, 0);
        } else {
            BattleAI_RecordUsedMove(temp_s1->unk_08, temp_s0->unk_08, 1);
        }
    }

    gBattleScene.unk_00->unk_2A = gBattleScene.unk_00->unk_2C;
    gBattleScene.unk_00->unk_38 = 0;
    temp_s0->unk_30 = 0;
    temp_s1->unk_30 = 0;
    gBattleScene.unk_00->unk_44 = 2;
    Battle_ResolveMonAction();
    gBattleScene.unk_00->unk_2C = sp2C;
}

void BattleScene_InitializeSwitchActions(void) {
    s32 sp2C;
    BattlerState* sp28;
    BattlerState* sp24;

    sp28 = &D_84390010[0]->unk_654;
    sp24 = &D_84390010[1]->unk_654;
    BattleScene_SetCameraSubstate(1, 1);

    sp2C = gBattleScene.unk_00->unk_2C;

    if ((sp28->unk_2D == 0xF) || (sp28->unk_2D == 0x10)) {
        if (D_84390010[0]->unk_724->unk_000 & 2) {
            BattleAI_RecordUsedMove(sp28->unk_08, sp24->unk_08, 2);
        }
        gBattleScene.unk_00->unk_2C = 0;
        gBattleScene.unk_00->unk_2A = 0;
        gBattleScene.unk_00->unk_38 = 0;
        gBattleScene.unk_00->unk_44 = 2;
        func_84373570(D_84390010[0]);
        gBattleScene.unk_00->unk_2C = sp2C;
    } else {
        if (D_84390010[0]->unk_724->unk_000 & 2) {
            BattleAI_RecordUsedMove(sp24->unk_08, sp28->unk_08, 2);
        }
        gBattleScene.unk_00->unk_2C = 1;
        gBattleScene.unk_00->unk_2A = 1;
        gBattleScene.unk_00->unk_38 = 0;
        gBattleScene.unk_00->unk_44 = 2;
        func_84373570(D_84390010[1]);
        gBattleScene.unk_00->unk_2C = sp2C;
    }
}

s32 BattleScene_PrepareReplacementTransition(void) {
    BattlerState* sp24 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;
    BattlerState* temp_a3 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;
    BattlerState* sp20 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654;

    if ((D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_2D == 0xF) || (sp24->unk_2D == 0x10)) {
        if (D_84390010[gBattleScene.unk_00->unk_2C]->unk_724->unk_000 & 2) {
            BattleAI_RecordUsedMove(temp_a3->unk_08, sp20->unk_08, 2);
        }
        Battle_ClearRuntimeFlags(D_84390010[gBattleScene.unk_00->unk_2C], 0x1800);
        gBattleScene.unk_00->unk_20 = 0;
        gBattleScene.unk_00->unk_14 = 0;
        if (sp24->unk_2D == 0x10) {
            gBattleScene.unk_00->unk_38 = 0x12;
        } else {
            BattleAnim_GetOwnerDefaultAnchorPosition(D_84390010[gBattleScene.unk_00->unk_2C], &D_843901B0.unk_00);
            BattleScene_LoadCameraPreset(&D_843848F0, gBattleScene.unk_00->unk_DC, D_84390010[gBattleScene.unk_00->unk_2C]);
            gBattleScene.unk_00->unk_38 = 0xB;
        }
        return 1;
    }

    return 0;
}

void BattleScene_BeginBattlePhase(void) {
    BattlerState* sp1C = &D_84390010[0]->unk_654;
    BattlerState* sp18 = &D_84390010[1]->unk_654;

    if ((BattleScene_IsPresentationCountdownComplete() == 0) && (D_84390134 != 1)) {
        func_8003DB84(1);
    }

    BattleScene_ClearInactiveOwnerAnimationFlags();
    sp1C->unk_10 = 0;
    sp18->unk_10 = 0;

    if ((sp1C->unk_2D == 0x10) || (sp18->unk_2D == 0x10) || (gBattleScene.unk_00->unk_2E == 2)) {
        BattleScene_SetCameraSubstate(1, 0);
    } else {
        BattleScene_SetCameraSubstate(1, 1);
    }

    gBattleScene.unk_00->unk_44 = 1;
    gBattleScene.unk_00->unk_20 += 1;
}

s32 BattleScene_TransitionToPhaseFull(s32 arg0) {
    BattleScene_ClearPhaseFlag();
    BattleScene_ResetCameraFrameCounter();
    gBattleScene.unk_00->unk_48 = 0;
    gBattleScene.unk_00->unk_4C = 0;
    gBattleScene.unk_00->unk_20 = 0;
    gBattleScene.unk_00->unk_14 = 0;
    gBattleScene.unk_00->unk_38 = arg0;
    return 1;
}

s32 BattleScene_TransitionToPhase(s32 arg0) {
    BattleScene_ClearPhaseFlag();
    BattleScene_ResetCameraFrameCounter();
    gBattleScene.unk_00->unk_4C = 0;
    gBattleScene.unk_00->unk_20 = 0;
    gBattleScene.unk_00->unk_14 = 0;
    gBattleScene.unk_00->unk_38 = arg0;
    return 1;
}

s32 BattleScene_TransitionToPhaseDuplicate(s32 arg0) {
    BattleScene_ClearPhaseFlag();
    BattleScene_ResetCameraFrameCounter();
    gBattleScene.unk_00->unk_4C = 0;
    gBattleScene.unk_00->unk_20 = 0;
    gBattleScene.unk_00->unk_14 = 0;
    gBattleScene.unk_00->unk_38 = arg0;
    return 1;
}

void BattleScene_SwitchActiveSideAndSetPhase(unk_D_86002F34_00C* arg0) {
    gBattleScene.unk_00->unk_2C = !gBattleScene.unk_00->unk_2C;
    BattleScene_SetPhase(arg0, 5);
}

void Battle_ActSecondAttacker(u8 arg0) {
    BattlerState* temp_a3;

    gBattleScene.unk_00->unk_2C = !gBattleScene.unk_00->unk_2C;
    temp_a3 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;

    if ((temp_a3->unk_2D == 0xF) || (temp_a3->unk_2D == 0x10)) {
        func_84373570(D_84390010[gBattleScene.unk_00->unk_2C]);
    } else {
        Battle_ResolveMonAction();
    }

    gBattleScene.unk_00->unk_34 = 1;
    gBattleScene.unk_00->unk_A0.z = 0.0f;
    BattleScene_SetPhase(gBattleScene.unk_00->unk_DC, 0x24);
    gBattleScene.unk_00->unk_78 = arg0;
}

void BattleScene_PhaseResumeSaved(void) {
    if (BattleScene_AdvanceOwnerAnimation(D_84390010[gBattleScene.unk_00->unk_2C]) == 0) {
        gBattleScene.unk_00->unk_38 = gBattleScene.unk_00->unk_78;
    }
}

void BattleScene_CleanupActionAndAdvance(void) {
    BattleMonRuntime* sp24;
    BattleMonRuntime* sp20;
    BattlerState* sp1C;

    if (gBattleScene.unk_00->unk_34 == 0) {
        BattleAnim_ClearOverlayFlag(D_84390010[gBattleScene.unk_00->unk_2C]);
        Audio_FadeAndClearStoredSounds();
        BattleScene_ResetAnimationStep();

        sp24 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;
        sp20 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654.unk_38;
        sp1C = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654;

        if ((((sp24->unk_5A & 0xF0) == 0xF0) || ((sp20->unk_5A & 0xF0) == 0xF0)) && (sp1C->unk_2D != 0xF) &&
            (sp1C->unk_2D != 0x10)) {
            gBattleScene.unk_00->unk_20 = 0;
            gBattleScene.unk_00->unk_14 = 0;
            gBattleScene.unk_00->unk_38 = 4;

            if ((sp24->unk_5A & 0xF0) == 0xF0) {
                sp24->unk_5A = 0xA5;
            }

            if ((sp20->unk_5A & 0xF0) == 0xF0) {
                sp20->unk_5A = 0xA5;
            }
        } else {
            Battle_ActSecondAttacker(3);
            gBattleScene.unk_00->unk_20 = 0;
            gBattleScene.unk_00->unk_14 = 0;
        }
    } else {
        sp24 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;
        sp20 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654.unk_38;

        BattleAnim_ClearOverlayFlag(D_84390010[gBattleScene.unk_00->unk_2C]);
        Audio_FadeAndClearStoredSounds();
        BattleScene_ResetAnimationStep();

        gBattleScene.unk_00->unk_20 = 0;
        gBattleScene.unk_00->unk_14 = 0;
        gBattleScene.unk_00->unk_38 = 4;

        if ((sp24->unk_5A & 0xF0) == 0xF0) {
            sp24->unk_5A = 0xA5;
        }

        if ((sp20->unk_5A & 0xF0) == 0xF0) {
            sp20->unk_5A = 0xA5;
        }
    }
}

s32 BattleScene_HandleFaintStatusCompletion(void) {
    BattleMonRuntime* temp_v0 = &D_84390200->unk_654.unk_38;

    if (((temp_v0->unk_4D & 0x80) || (temp_v0->unk_15 & 0x18)) && ((temp_v0->unk_5A & 0xF0) == 0xF0)) {
        BattleAnim_ClearOverlayFlag(D_84390010[gBattleScene.unk_00->unk_2C]);
        Audio_FadeAndClearStoredSounds();
        BattleScene_ResetAnimationStep();
        Battle_ActSecondAttacker(3);
        gBattleScene.unk_00->unk_20 = 0;
        gBattleScene.unk_00->unk_48 = 0;
        gBattleScene.unk_00->unk_14 = 0;
        return 1;
    }
    return 0;
}

void BattleScene_CompleteActionPhase(void) {
    if ((gBattleScene.unk_00->unk_34 == 0) && ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) != 0xF0)) {
        BattleAnim_ClearOverlayFlag(D_84390010[gBattleScene.unk_00->unk_2C]);
        Audio_FadeAndClearStoredSounds();
        BattleScene_ResetAnimationStep();
        Battle_ActSecondAttacker(3);
        gBattleScene.unk_00->unk_20 = 0;
        gBattleScene.unk_00->unk_14 = 0;
    } else if (BattleScene_HandleFaintStatusCompletion() == 0) {
        BattleAnim_ClearOverlayFlag(D_84390010[gBattleScene.unk_00->unk_2C]);
        Audio_FadeAndClearStoredSounds();
        BattleScene_ResetAnimationStep();
        gBattleScene.unk_00->unk_20 = 0;
        gBattleScene.unk_00->unk_14 = 0;
        gBattleScene.unk_00->unk_38 = 4;
    }
}

void BattleScene_ResolveDisplayedHpCompletion(unk_D_86002F34_00C* arg0) {
    if ((D_84390220 == 1) && (D_84390224 == 1)) {
        if (Battle_GetActiveMonHp(D_84390010[gBattleScene.unk_00->unk_2C]) == 0) {
            BattleScene_SwitchActiveSideAndSetPhase(arg0);
        } else if (Battle_GetActiveMonHp(D_84390010[!gBattleScene.unk_00->unk_2C]) == 0) {
            BattleScene_SetPhase(arg0, 5);
        } else {
            BattleScene_CompleteActionPhase();
        }
    }
}

void BattleScene_UpdateDisplayedHpAndTransition(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp1C = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;

    D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[0]);
    D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[1]);
    BattleScene_ClearPhaseFlag();
    BattleScene_ResetCameraFrameCounter();

    if (Battle_GetActiveMonHp(D_84390010[gBattleScene.unk_00->unk_2C]) == 0) {
        BattleScene_SwitchActiveSideAndSetPhase(arg0);
    } else if (Battle_GetActiveMonHp(D_84390010[!gBattleScene.unk_00->unk_2C]) == 0) {
        BattleScene_ResolveDisplayedHpCompletion(arg0);
    } else if (gBattleScene.unk_00->unk_4C == 0xA) {
        BattleScene_TransitionToPhaseDuplicate(0xA);
    } else if (gBattleScene.unk_00->unk_48 == 9) {
        BattleScene_TransitionToPhaseFull(9);
    } else if ((sp1C->unk_15 & 0x18) || (sp1C->unk_4D & 0x80)) {
        BattleScene_TransitionToPhaseFull(6);
    } else {
        BattleScene_ResolveDisplayedHpCompletion(arg0);
    }
}

void BattleScene_WaitForDisplayedHpAnimations(unk_D_86002F34_00C* arg0) {
    if ((D_84390220 == 1) && (D_84390224 == 1)) {
        BattleBox_Close();
        BattleScene_UpdateDisplayedHpAndTransition(arg0);
    }
}

s32 BattleScene_ActionPresentationTransitionCheck(void) {
    switch (gBattleScene.unk_00->unk_48) {
        case 7:
        case 38:
        case 39:
            BattleScene_EnterStateRow(D_84390204, 3);
            return BattleScene_TransitionToPhase(0x25);

        case 30:
            BattleScene_EnterStateRow(D_84390204, 3);
            return BattleScene_TransitionToPhase(0x25);

        case 28:
            return BattleScene_TransitionToPhase(0x25);

        case 21:
            BattleScene_EnterStateRow(D_84390204, 3);
            return BattleScene_TransitionToPhase(0x25);

        case 15:
            return BattleScene_TransitionToPhase(0x25);

        case 25:
            return BattleScene_TransitionToPhase(0x25);

        case 27:
            return BattleScene_TransitionToPhase(0x25);

        case 29:
            BattleScene_EnterStateRow(D_84390204, 3);
            return BattleScene_TransitionToPhase(0x25);

        case 12:
            BattleScene_EnterStateRow(D_84390204, 8);
            return BattleScene_TransitionToPhase(0x25);

        case 13:
            BattleScene_EnterStateRow(D_84390204, 8);
            return BattleScene_TransitionToPhase(0x25);

        case 14:
            BattleScene_EnterStateRow(D_84390204, 8);
            return BattleScene_TransitionToPhase(0x25);

        case 17:
            BattleScene_EnterStateRow(D_84390204, 9);
            return BattleScene_TransitionToPhase(0x25);

        case 31:
            return BattleScene_TransitionToPhase(0x25);
    }
    return 0;
}

s32 BattleScene_ActionPresentationCleanupCheck(void) {
    s32 tmp = gBattleScene.unk_00->unk_48;

    if (tmp != 0x10) {
        if (gBattleScene.unk_00->unk_48 == 0x14) {
            return BattleScene_TransitionToPhaseFull(0x14);
        }
    } else {
        return BattleScene_TransitionToPhaseFull(0x10);
    }

    if ((gBattleMoveFailed != 0) || (gBattleScene.unk_00->unk_48 == 8)) {
        return BattleScene_TransitionToPhaseFull(8);
    }
    return 0;
}

s32 BattleScene_PrepareResidualStatusPresentation(void) {
    s32 idx = gBattleScene.unk_00->unk_2C;
    BattleMonRuntime* temp_v1_2 = &D_84390010[idx]->unk_654.unk_38;

    if (((temp_v1_2->unk_4D & 0x80) || (temp_v1_2->unk_15 & 0x18)) && ((temp_v1_2->unk_5A & 0xF0) == 0xF0)) {
        return BattleScene_TransitionToPhaseFull(0x23);
    }
    return 0;
}

void BattleScene_UpdateActiveOwnerPointers(void) {
    s32 idx;

    D_84390204 = D_84390010[gBattleScene.unk_00->unk_2C];
    idx = gBattleScene.unk_00->unk_2C == 0;
    D_84390200 = D_84390010[idx];
}

void BattleScene_InitializeBattlePresentation(unk_D_86002F34_00C* arg0) {
    func_8003DB84(0);
    BattleScene_SetCameraClipPlanes(arg0, 20.0f, 12800.0f);
    BattleScene_ResetAnimationStep();
    gBattleScene.unk_00->unk_34 = 0;
    BattleScene_ClearPhaseFlag();
    gBattleScene.unk_00->unk_14 = 0;
    Battle_ResetModelToIdleAnim(D_84390010[0]);
    Battle_ResetModelToIdleAnim(D_84390010[1]);
    gBattleScene.unk_00->unk_20++;
}

void BattleScene_SendOutPresentationFinalize(unk_D_86002F34_00C* arg0) {
    BattlerState* temp_t2 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654;
    BattlerState* temp_t1 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;
    s16 sp2E = D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.objectType;
    MovePresentationCue* sp28 = &D_84384570[gBattleScene.unk_00->unk_2C]->unk_A50;
    Battler* sp24 = D_84390010[gBattleScene.unk_00->unk_2C];

    if (((temp_t2->unk_2D == 0x13) && (temp_t1->unk_2D == 0x13)) ||
        ((temp_t2->unk_2D == 0x10) && (temp_t1->unk_2D == 0x13)) ||
        ((temp_t1->unk_2D == 0x10) && (temp_t2->unk_2D == 0x13))) {
        BattleBox_Open(0xE);
        Vec3f_SetComponentsDuplicate(&arg0->unk_60.at, 0.0f, 75.0f, 0.0f);
        Vec3f_SetComponentsDuplicate(&arg0->unk_60.eye, 0.0f, 80.0f, 400.0f);
        Audio_StartBattleMusicSequence();
        gBattleScene.unk_00->unk_20 = 8;
        return;
    }

    if (temp_t1->unk_34 & 0x4008) {
        sp24->unk_000.lodFraction = 0xFF;
        BattleAnim_StopOwnerCategoryParticles(4, sp24);
        sp24->unk_000.position.y = D_84390028[gBattleScene.unk_00->unk_2C].unk_08;
        sp24->unk_000.node.renderFlags &= ~0x2;
        sp24->unk_000.node.renderFlags |= 0x20;
        sp24->unk_000.node.flags |= 1;
        Battle_ClearRuntimeFlags(sp24, 0x4608);
    }

    if (D_84390010[gBattleScene.unk_00->unk_2C]->unk_4B4 == 0xA) {
        BattleScene_SetParticipantModelFlags(D_84390010[gBattleScene.unk_00->unk_2C], 0, 0);
    }

    if (D_84390010[gBattleScene.unk_00->unk_2C]->unk_4B4 == 0xD) {
        BattleScene_SetParticipantModelFlags(D_84390010[gBattleScene.unk_00->unk_2C], 0, 0);
    }

    if (D_84390010[gBattleScene.unk_00->unk_2C]->unk_4B4 == 0x10) {
        BattleScene_SetParticipantModelFlags(D_84390010[gBattleScene.unk_00->unk_2C], 0, 0);
    }

    D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.rotation.x = 0;
    if ((sp2E == 0x32) || (sp2E == 0x33)) {
        D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.node.renderFlags |= 0x20;
        D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.node.flags |= 1;
        ModelAnim_SetAnimation(&D_84390010[gBattleScene.unk_00->unk_2C]->unk_000, sp28->unk_00);
    }

    Battle_ResetModelToIdleAnim(D_84390010[gBattleScene.unk_00->unk_2C]);
    Vec3f_SetComponentsDuplicate(&D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.scale, 1.0f, 1.0f, 1.0f);
    D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.position.y = BattleScene_GetParticipantModelHeight(D_84390010[gBattleScene.unk_00->unk_2C]);
    BattleAnim_GetOwnerDefaultAnchorPosition(D_84390010[gBattleScene.unk_00->unk_2C], &D_843901B0.unk_00);
    BattleScene_LoadCameraPreset(&D_84384AF8, arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
    BattleScene_ApplyCameraPreset(arg0, D_84390010[gBattleScene.unk_00->unk_2C], 1);
    Audio_StartBattleMusicSequence();
    gBattleScene.unk_00->unk_20 = 6;
}

s32 BattleScene_ResetOwnerStatusPresentation(Battler* arg0) {
    UNUSED s32 pad;
    BattlerState* sp28 = &arg0->unk_654;

    gBattleScene.unk_00->unk_54 = 0;
    BattleAnim_ResetFreezeStatusAndRestoreAnimation(arg0);

    if (sp28->unk_34 & 0x200) {
        Battle_ClearRuntimeFlags(arg0, 0x60C);
        return 1;
    }

    if (sp28->unk_34 & 0x4008) {
        arg0->unk_000.lodFraction = 0xFF;
        BattleAnim_StopOwnerCategoryParticles(4, arg0);
        arg0->unk_000.position.y = D_84390028[BattleScene_GetParticipantSideIndex(arg0)].unk_08;
        arg0->unk_000.node.renderFlags &= ~0x2;
        arg0->unk_000.node.renderFlags |= 0x20;
        arg0->unk_000.node.flags |= 1;
        Battle_ClearRuntimeFlags(arg0, 0x4608);
    }

    BattleAnim_EndSleepStatusAnimation(arg0);
    sp28->unk_2E = 0xFF;
    Model_SetMaterialColor(&arg0->unk_000, 0xFF, 0xFF, 0xFF, sp28->unk_2E);
    BattleScene_CleanupParticipantEffectMode(arg0);
    arg0->unk_000.rotation.x = 0;
    return 0;
}

void BattleScene_AdvanceSendOutPreparation(unk_D_86002F34_00C* arg0) {
    if (BattleScene_AdvanceOwnerAnimation(D_84390010[!gBattleScene.unk_00->unk_2C]) == 0) {
        Battle_ClearRuntimeFlags(D_84390010[!gBattleScene.unk_00->unk_2C], 0x1800);
        Audio_FadeAndClearStoredSounds();
        BattleAnim_CleanupEffects(2);
        BattleScene_ResetCameraFrameCounter();
        func_8003F1AC(BattleScene_GetParticipantDisplayPlayerNumber(D_84390010[!gBattleScene.unk_00->unk_2C]));

        if (BattleScene_ResetOwnerStatusPresentation(D_84390010[!gBattleScene.unk_00->unk_2C]) != 0) {
            BattleScene_EnterStateRow(D_84390010[!gBattleScene.unk_00->unk_2C], 0x11);
            BattleScene_ClearCameraOffsetVectors();
            gBattleScene.unk_00->unk_20 = 0xA;
        } else {
            BattleScene_EnterStateRow(D_84390010[!gBattleScene.unk_00->unk_2C], 0);
            BattleScene_ClearCameraOffsetVectors();
            gBattleScene.unk_00->unk_20++;
        }

        BattleScene_SelectCameraShot(D_84390010[!gBattleScene.unk_00->unk_2C], arg0, 3);

        if (BattleScene_IsPartnerPikachu(D_84390010[!gBattleScene.unk_00->unk_2C]) != 0) {
            Cry_Play(0xC8, 1);
        } else {
            Cry_Play(D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.objectType, 1);
        }
    }
}

void BattleScene_AdvanceSendOutCamera(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad[2];
    BattlerState* sp24 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654;
    MovePresentationCue* sp20 = &D_84384570[!gBattleScene.unk_00->unk_2C]->unk_A70;

    if (BattleAnim_IsAssetLoadBusy(D_84390010[!gBattleScene.unk_00->unk_2C]) == 0) {
        if (gBattleScene.unk_00->unk_14 == 0x1D) {
            BattleScene_SelectCameraShot(D_84390010[!gBattleScene.unk_00->unk_2C], arg0, 4);
        }

        if (BattleScene_AdvanceCameraFrameCounterUntil(0x1E) != 0) {
            BattleScene_ApproachCameraZoom(arg0, D_84390010[!gBattleScene.unk_00->unk_2C]);
        }

        if (((sp20->unk_04 >> 1) == (D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.transformAnim.frameFixed >> 0x10)) &&
            (sp24->unk_2D != 0x12)) {
            BattleBox_Open(9);
        }

        if (sp20->unk_0A == ((D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.transformAnim.frameFixed >> 0x10) + 3)) {
            D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.node.renderFlags &= ~0x20;
            Battle_SetRuntimeFlags(D_84390010[!gBattleScene.unk_00->unk_2C], 0x100);
            BattleScene_ResetCameraFrameCounter();
            gBattleScene.unk_00->unk_20 += 1;
        }
        BattleScene_ApproachCameraTarget(arg0, D_84390010[!gBattleScene.unk_00->unk_2C], 0);
    }
}

void BattleScene_AdvanceSendOutCameraClose(unk_D_86002F34_00C* arg0) {
    BattleScene_ApproachCameraTarget(arg0, D_84390010[!gBattleScene.unk_00->unk_2C], 1);
    if (BattleScene_AdvanceCameraFrameCounter(0x19) != 0) {
        Audio_FadeAndClearStoredSounds();
        gBattleScene.unk_00->unk_20++;
    }
}

void BattleScene_FinishSendOutCameraClose(unk_D_86002F34_00C* arg0) {
    BattlerState* temp_s0 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654;

    BattleScene_ApproachCameraTarget(arg0, D_84390010[!gBattleScene.unk_00->unk_2C], 1);

    if (BattleScene_AdvanceCameraFrameCounter(5) != 0) {
        BattleAnim_CleanupEffects(1);
        Audio_FadeCommand(3, 0);

        if (temp_s0->unk_2D != 0x12) {
            temp_s0->unk_2D = 0x10;
        }

        if (temp_s0->unk_2D == 0x12) {
            temp_s0->unk_2D = 0x13;
        }

        gBattleScene.unk_00->unk_20++;
    }
}

void BattleScene_CompleteSendOutPresentation(unk_D_86002F34_00C* arg0) {
    BattlerState* sp24 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654;
    BattlerState* sp20 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;

    if (BattleScene_AdvanceCameraFrameCounter(0xA) != 0) {
        BattleScene_ResetCameraFrameCounter();
        BattleScene_ClearPhaseFlag();
        gBattleScene.unk_00->unk_20++;
        if (sp24->unk_2D == 0x10) {
            gBattleScene.unk_00->unk_14 = 0;
            gBattleScene.unk_00->unk_20 = 0;

            if ((sp20->unk_2D == 0x11) || (sp20->unk_2D == 0x12)) {
                gBattleScene.unk_00->unk_38 = 5;
                gBattleScene.unk_00->unk_2C = !gBattleScene.unk_00->unk_2C;
            } else if ((sp24->unk_2D == 0x13) || (sp20->unk_2D == 0x13)) {
                BattleBox_Open(0xE);
                Vec3f_SetComponentsDuplicate(&arg0->unk_60.at, 0.0f, 75.0f, 0.0f);
                Vec3f_SetComponentsDuplicate(&arg0->unk_60.eye, 0.0f, 80.0f, 400.0f);
                Audio_StartBattleMusicSequence();
                gBattleScene.unk_00->unk_2C = !gBattleScene.unk_00->unk_2C;
                gBattleScene.unk_00->unk_20 = 8;
            } else {
                gBattleScene.unk_00->unk_38 = 4;
            }
        } else if ((sp20->unk_2D == 0x12) || (sp20->unk_2D == 0x11)) {
            gBattleScene.unk_00->unk_14 = 0;
            gBattleScene.unk_00->unk_20 = 0;
            gBattleScene.unk_00->unk_38 = 5;
            gBattleScene.unk_00->unk_2C = !gBattleScene.unk_00->unk_2C;
        } else {
            BattleScene_SendOutPresentationFinalize(arg0);
        }
        Audio_FadeAndClearStoredSounds();
    }
}

void func_84321D34(UNUSED unk_D_86002F34_00C* arg0) {
}

void BattleScene_SetupSendOutOwnerShot(unk_D_86002F34_00C* arg0) {
    Battler* temp_s0;
    UNUSED s32 pad;
    f32 sp44;
    f32 sp40;
    s16 sp3E;
    UNUSED s16 pad2;
    u8 sp3B;
    s16 tmp1;

    temp_s0 = D_84390010[gBattleScene.unk_00->unk_2C];
    sp3B = temp_s0->unk_000.objectType - 1;

    if (BattleScene_AnimateCameraPreset(arg0, temp_s0, 1, 0) != 0) {
        BattleScene_ResetCameraFrameCounter();
        BattleBox_Open(0xE);
        BattleScene_SetCameraClipPlanes(arg0, 10.0f, 12800.0f);
        arg0->unk_24.fovy = 60.0f;
        if ((D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.objectType == 0x5F) && (gBattleScene.unk_00->unk_2C == 1)) {
            sp3B = 0x97;
        }

        sp44 = (D_84384580[gBattleScene.unk_00->unk_2C]->unk_00.y + temp_s0->unk_000.position.y) + D_84384C30[sp3B].z;
        sp40 = ((D_84384580[gBattleScene.unk_00->unk_2C]->unk_00.z + D_84384C30[sp3B].y) * temp_s0->unk_4B0) +
               temp_s0->unk_000.position.x;

        Vec3f_SetComponentsDuplicate(&arg0->unk_60.at, sp40, sp44, temp_s0->unk_000.position.z);

        sp40 = D_84384580[gBattleScene.unk_00->unk_2C]->unk_00.x * D_84384C30[sp3B].x;
        sp3E = D_84384580[gBattleScene.unk_00->unk_2C]->unk_0C;
        tmp1 = (temp_s0->unk_4B0 * D_84384580[gBattleScene.unk_00->unk_2C]->unk_0E) + BattleScene_GetParticipantFacingAngle(temp_s0);
        Camera_ComputeEyeFromAngles(&arg0->unk_60.at, &arg0->unk_60.eye, sp40, sp3E, tmp1);
        gBattleScene.unk_00->unk_20++;
    }
}

void BattleScene_CompleteSendOutCameraFade(UNUSED unk_D_86002F34_00C* arg0) {
    if (BattleScene_AdvanceCameraFrameCounter(0x50) != 0) {
        gBattleScene.unk_00->unk_40 = gBattleScene.unk_00->unk_2C + 1;
        BattleBox_Close();
        Audio_FadeOutAll(0x14);
    }
}

void BattleScene_CompleteSendOutExtendedFade(UNUSED unk_D_86002F34_00C* arg0) {
    if (BattleScene_AdvanceCameraFrameCounter(0x7D) != 0) {
        gBattleScene.unk_00->unk_40 = gBattleScene.unk_00->unk_2C + 1;
        Audio_FadeOutAll(0x14);
    }
}

void BattleScene_AdvanceSendOutFollowupCamera(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad[2];
    BattlerState* sp24 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654;
    MovePresentationCue* sp20 = &D_84384570[!gBattleScene.unk_00->unk_2C]->unk_B10;

    if (BattleAnim_IsAssetLoadBusy(D_84390010[!gBattleScene.unk_00->unk_2C]) == 0) {
        if (gBattleScene.unk_00->unk_14 == 0x1D) {
            BattleScene_SelectCameraShot(D_84390010[!gBattleScene.unk_00->unk_2C], arg0, 4);
        }

        if (BattleScene_AdvanceCameraFrameCounterUntil(0x1E) != 0) {
            BattleScene_ApproachCameraZoom(arg0, D_84390010[!gBattleScene.unk_00->unk_2C]);
        }

        if (((sp20->unk_04 >> 1) == (D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.transformAnim.frameFixed >> 0x10)) &&
            (sp24->unk_2D != 0x12)) {
            BattleBox_Open(9);
        }

        if (sp20->unk_0A == ((D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.transformAnim.frameFixed >> 0x10) + 3)) {
            D_84390010[!gBattleScene.unk_00->unk_2C]->unk_000.node.renderFlags &= ~0x20;
            Battle_SetRuntimeFlags(D_84390010[!gBattleScene.unk_00->unk_2C], 0x100);
            BattleScene_ResetCameraFrameCounter();
            BattleScene_UpdateCameraModelOffset(D_84390010[!gBattleScene.unk_00->unk_2C], arg0);
            gBattleScene.unk_00->unk_20 = 2;
        }

        BattleScene_ApproachCameraTarget(arg0, D_84390010[!gBattleScene.unk_00->unk_2C], 0);
    }
}

void BattleScene_PhaseSendOut(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_AdvanceSendOutPreparation(arg0);
            break;

        case 1:
            BattleScene_AdvanceSendOutCamera(arg0);
            break;

        case 2:
            BattleScene_AdvanceSendOutCameraClose(arg0);
            break;

        case 3:
            BattleScene_FinishSendOutCameraClose(arg0);
            break;

        case 4:
            BattleScene_CompleteSendOutPresentation(arg0);
            break;

        case 5:
            func_84321D34(arg0);
            break;

        case 6:
            BattleScene_SetupSendOutOwnerShot(arg0);
            break;

        case 7:
            BattleScene_CompleteSendOutCameraFade(arg0);
            break;

        case 8:
            BattleScene_CompleteSendOutExtendedFade(arg0);
            break;

        case 10:
            BattleScene_AdvanceSendOutFollowupCamera(arg0);
            break;
    }
}

void BattleScene_CompleteSendOutFollowup(UNUSED unk_D_86002F34_00C* arg0) {
    BattlerState* sp1C = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654;

    if (BattleScene_AdvanceCameraFrameCounter(2) != 0) {
        BattleScene_ResetCameraFrameCounter();
        BattleScene_ClearPhaseFlag();
        gBattleScene.unk_00->unk_20 += 1;
        if (sp1C->unk_2D == 0x10) {
            gBattleScene.unk_00->unk_14 = 0;
            gBattleScene.unk_00->unk_20 = 0;
            gBattleScene.unk_00->unk_38 = 4;
        } else {
            gBattleScene.unk_00->unk_40 = gBattleScene.unk_00->unk_2C + 1;
        }
        Audio_FadeAndClearStoredSounds();
    }
}

void BattleScene_PhaseSendOutAfterFaint(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_AdvanceSendOutPreparation(arg0);
            break;

        case 1:
            BattleScene_AdvanceSendOutCamera(arg0);
            break;

        case 2:
            BattleScene_AdvanceSendOutCameraClose(arg0);
            break;

        case 3:
            BattleScene_FinishSendOutCameraClose(arg0);
            break;

        case 4:
            BattleScene_CompleteSendOutFollowup(arg0);
            break;

        case 5:
            func_84321D34(arg0);
            break;

        case 10:
            BattleScene_AdvanceSendOutFollowupCamera(arg0);
            break;
    }
}

void BattleScene_ResetOwnerPresentationFlags(Battler* arg0) {
    BattlerState* ptr = &arg0->unk_654;

    if (ptr->unk_34 & 0x200) {
        arg0->unk_000.position.y = D_84390028[BattleScene_GetParticipantSideIndex(arg0)].unk_08;
        Battle_ClearRuntimeFlags(arg0, 0x608);
    } else if (ptr->unk_34 & 0x4008) {
        arg0->unk_000.lodFraction = 0xFF;
        BattleAnim_StopOwnerCategoryParticles(4, arg0);
        arg0->unk_000.position.y = D_84390028[BattleScene_GetParticipantSideIndex(arg0)].unk_08;
        arg0->unk_000.node.renderFlags &= ~0x2;
        arg0->unk_000.node.renderFlags |= 0x20;
        arg0->unk_000.node.flags |= 1;
        Battle_ClearRuntimeFlags(arg0, 0x4608);
    }
}

void BattleScene_InitializeIntroCamera(unk_D_86002F34_00C* arg0) {
    s32 sp24;
    BattlerState* sp20 = &D_84390010[0]->unk_654;
    BattlerState* sp1C = &D_84390010[1]->unk_654;

    BattleScene_ClearStateTickCallbacks();
    BattleScene_ResetAnimationStep();

    sp24 = BattleAnim_RandomRange(5);
    if (sp24 >= 5) {
        sp24 = 0;
    }

    if ((sp20->unk_34 & 0x4000) || ((sp1C->unk_34 & 0x4000) != 0)) {
        sp24 = 2;
    } else if ((sp20->unk_34 & 0x200) || (sp1C->unk_34 & 0x200)) {
        sp24 = 4;
    } else if ((sp20->unk_2D == 0x10) || (sp1C->unk_2D == 0x10)) {
        sp24 = 2;
    }

    BattleAnim_Vec3fCopy(&D_843901B0.unk_00, &D_84385B90);
    BattleScene_LoadCameraPresetUnscaled(&D_84384B2C[sp24], arg0);
    BattleScene_ApplyCameraPreset(arg0, D_84390204, 0);
    gBattleScene.unk_00->unk_20++;
}

void BattleScene_AdvanceIntroCamera(unk_D_86002F34_00C* arg0) {
    if (BattleScene_AnimateCameraPreset(arg0, D_84390204, 0, 1) != 0) {
        BattleScene_SetPhase(arg0, 2);
    }
}

void BattleScene_PhaseIntro(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_InitializeIntroCamera(arg0);
            break;

        case 1:
            BattleScene_AdvanceIntroCamera(arg0);
            break;
    }
}

void BattleScene_SetMonMoveResourceFlag(Battler* arg0) {
    arg0->unk_654.unk_30 = 0x800;
}

void BattleScene_PrepareMoveResourcePresentation(UNUSED unk_D_86002F34_00C* arg0) {
    BattleAnim_CleanupEffects(2);
    BattleScene_SetMonMoveResourceFlag(D_84390204);
    BattleScene_LoadMoveResourceList(D_84390204);
}

void BattleScene_SelectActionCameraPreset(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp1C = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;
    BattlerState* sp18 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;
    s32 var_t0;

    if (gBattleScene.unk_00->unk_48 == 0xE) {
        var_t0 = BattleScene_GetMappedAnimationTimingField0D(D_84390010[gBattleScene.unk_00->unk_2C]);
    } else if ((gBattleScene.unk_00->unk_48 == 0x1C) || (gBattleScene.unk_00->unk_48 == 0x11) ||
               (gBattleScene.unk_00->unk_48 == 0x1F)) {
        var_t0 = 0;
    } else {
        var_t0 = BattleScene_GetAnimationTimingField0D(D_84390010[gBattleScene.unk_00->unk_2C]);
    }

    if ((sp1C->unk_5A == 0x3A) || (sp1C->unk_5A == 0x8F)) {
        if ((gBattleScene.unk_00->unk_48 != 0x1C) && (gBattleScene.unk_00->unk_48 != 0x11) &&
            (gBattleScene.unk_00->unk_48 != 0x1F)) {
            var_t0 = 0x16;
        }
    }

    switch (var_t0) {
        case 20:
            BattleScene_SelectCameraPreset(D_84390204, arg0,
                          gBattleScene.unk_00->unk_50 = D_84385B70[BattleAnim_RandomIntWithWarmup(ARRAY_COUNT(D_84385B70))], 1);
            break;

        case 21:
            BattleScene_SelectCameraPreset(D_84390204, arg0,
                          gBattleScene.unk_00->unk_50 = D_84385B78[BattleAnim_RandomIntWithWarmup(ARRAY_COUNT(D_84385B78))], 1);
            break;

        case 22:
            BattleScene_SelectCameraPreset(D_84390204, arg0,
                          gBattleScene.unk_00->unk_50 = D_84385B7C[BattleAnim_RandomIntWithWarmup(ARRAY_COUNT(D_84385B7C))], 1);
            break;

        case 23:
            BattleScene_SelectCameraPreset(D_84390204, arg0,
                          gBattleScene.unk_00->unk_50 = D_84385B80[BattleAnim_RandomIntWithWarmup(ARRAY_COUNT(D_84385B80))], 1);
            break;

        case 24:
            BattleScene_SelectCameraPreset(D_84390204, arg0,
                          gBattleScene.unk_00->unk_50 = D_84385B88[BattleAnim_RandomIntWithWarmup(ARRAY_COUNT(D_84385B88))], 1);
            break;

        default:
            BattleScene_SelectCameraPreset(D_84390204, arg0, gBattleScene.unk_00->unk_50 = var_t0, 1);
            if (sp18->unk_34 & 0x4000) {
                arg0->unk_60.at.y = 0.0f;
            }
            break;
    }
}

s32 BattleScene_AdvanceActionPresentationSetup(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    BattlerState* sp20 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;

    BattleScene_ResetCameraFrameCounter();
    BattleScene_SelectActionCameraPreset(arg0);

    if (BattleScene_ActionPresentationTransitionCheck() != 0) {
        return 0;
    }

    if (gBattleScene.unk_00->unk_48 == 0x14) {
        BattleScene_EnterStateRow(D_84390010[gBattleScene.unk_00->unk_2C], 0x15);
    } else if (gBattleScene.unk_00->unk_48 == 0x18) {
        BattleScene_EnterStateRow(D_84390010[gBattleScene.unk_00->unk_2C], 3);
    } else if (sp20->unk_34 & 0x4400) {
        BattleScene_EnterStateRow(D_84390010[gBattleScene.unk_00->unk_2C], 3);
        BattleScene_SelectCameraPreset(D_84390010[gBattleScene.unk_00->unk_2C], arg0, gBattleScene.unk_00->unk_50 = 2, 1);
    } else {
        BattleScene_EnterStateRow(D_84390010[gBattleScene.unk_00->unk_2C], 3);
    }

    BattleScene_ClearPhaseFlag();
    return 1;
}

void BattleScene_ActionSetupCameraStep(unk_D_86002F34_00C* arg0) {
    BattlerState* sp1C = &D_84390204->unk_654;

    BattleAnim_ApproachF(&arg0->unk_24.fovy, 30.0f, 0.05f);

    switch (gBattleScene.unk_00->unk_3C) {
        case 0:
            BattleScene_CleanupParticipantEffectMode(D_84390010[0]);
            BattleScene_CleanupParticipantEffectMode(D_84390010[1]);

            if ((BattleScene_PrepareReplacementTransition() == 0) && (BattleScene_PrepareResidualStatusPresentation() == 0)) {
                Battle_ClearOpponentHopFlagAndSyncMove(D_84390204);
                BattleScene_PrepareMoveResourcePresentation(arg0);
                BattleScene_SetPhaseFlag();

                if ((gBattleScene.unk_00->unk_34 == 1) && (D_84390200->unk_4C8 == 1)) {
                    BattleScene_ResetOwnerPresentationFlags(D_84390200);
                }

                BattleAnim_GetOwnerDefaultAnchorPosition(D_84390204, &D_843901B0.unk_00);

                if (sp1C->unk_34 & 0x4000) {
                    D_843901B0.unk_00.y = 15.000001f;
                }

                if (gBattleScene.unk_00->unk_34 == 1) {
                    BattleScene_ResetCameraFov(arg0);

                    if ((gBattleScene.unk_00->unk_48 == 0x1C) || (gBattleScene.unk_00->unk_48 == 0x11) ||
                        (gBattleScene.unk_00->unk_48 == 0x1F)) {
                        BattleScene_SelectCameraFollowPreset(D_84390204, arg0, 3);
                    } else {
                        BattleScene_SelectCameraFollowPreset(D_84390204, arg0, 4);
                    }

                    if (sp1C->unk_34 & 0x4000) {
                        arg0->unk_60.at.y = 15.000001f;
                    }
                    Battle_ResetModelToIdleAnim(D_84390204);
                } else if ((gBattleScene.unk_00->unk_48 == 0x1C) || (gBattleScene.unk_00->unk_48 == 0x11) ||
                           (gBattleScene.unk_00->unk_48 == 0x1F)) {
                    BattleScene_LoadCameraPreset(&D_8438498C, arg0, D_84390204);
                } else {
                    BattleScene_LoadCameraPreset(&D_843848F0, arg0, D_84390204);
                }
            }
            break;

        case 1:
            if (BattleAnim_TryRegisterAssetTables(D_84390204) != 0) {
                D_84390234 = D_84390230 = D_8439022C;
                BattleBox_Open(0);
                BattleScene_ResetCameraFrameCounter();
                gBattleScene.unk_00->unk_3C += 1;
            }
            break;

        case 2:
            if (gBattleScene.unk_00->unk_34 == 1) {
                if ((gBattleScene.unk_00->unk_48 == 0x1C) || (gBattleScene.unk_00->unk_48 == 0x11) ||
                    (gBattleScene.unk_00->unk_48 == 0x1F)) {
                    if (BattleScene_AdvanceCameraFrameCounter(0xA) != 0) {
                        BattleScene_ResetCameraFov(arg0);
                        if (BattleScene_AdvanceActionPresentationSetup(arg0) != 0) {
                            gBattleScene.unk_00->unk_20 = 1;
                        }
                    }
                } else if (BattleScene_AdvanceCameraFrameCounter(0x28) != 0) {
                    BattleScene_ResetCameraFov(arg0);
                    if (BattleScene_AdvanceActionPresentationSetup(arg0) != 0) {
                        gBattleScene.unk_00->unk_20 = 1;
                    }
                }
            } else if (BattleScene_AnimateCameraPreset(arg0, D_84390204, 1, 1) != 0) {
                BattleScene_ResetCameraFov(arg0);
                if (BattleScene_AdvanceActionPresentationSetup(arg0) != 0) {
                    gBattleScene.unk_00->unk_20 = 1;
                }
            }
            break;
    }
}

void BattleScene_RefreshActionCameraPreset(unk_D_86002F34_00C* arg0) {
    s32 temp_v0;
    s32 temp_t0;

    if (D_84390230 != D_8439022C) {
        temp_v0 = BattleScene_GetAnimationTimingField0E(D_84390010[gBattleScene.unk_00->unk_2C]) & 0xFFFFFFFF;
        switch (temp_v0) {
            case 20:
                do {
                    temp_t0 = D_84385B70[BattleAnim_RandomIntWithWarmup(5.0f)];
                } while (temp_t0 == gBattleScene.unk_00->unk_50);
                gBattleScene.unk_00->unk_50 = temp_t0;
                BattleScene_SelectCameraPreset(D_84390204, arg0, gBattleScene.unk_00->unk_50, 1);
                break;

            case 21:
                do {
                    temp_t0 = D_84385B78[BattleAnim_RandomIntWithWarmup(4.0f)];
                } while (temp_t0 == gBattleScene.unk_00->unk_50);
                gBattleScene.unk_00->unk_50 = temp_t0;
                BattleScene_SelectCameraPreset(D_84390204, arg0, gBattleScene.unk_00->unk_50, 1);
                break;

            case 22:
                do {
                    temp_t0 = D_84385B7C[BattleAnim_RandomIntWithWarmup(3.0f)];
                } while (temp_t0 == gBattleScene.unk_00->unk_50);
                gBattleScene.unk_00->unk_50 = temp_t0;
                BattleScene_SelectCameraPreset(D_84390204, arg0, gBattleScene.unk_00->unk_50, 1);
                break;

            case 23:
                do {
                    temp_t0 = D_84385B80[BattleAnim_RandomIntWithWarmup(6.0f)];
                } while (temp_t0 == gBattleScene.unk_00->unk_50);
                gBattleScene.unk_00->unk_50 = temp_t0;
                if (1) {}
                if (1) {}
                if (1) {}
                if (1) {}
                BattleScene_SelectCameraPreset(D_84390204, arg0, gBattleScene.unk_00->unk_50, 1);
                break;

            case 24:
                do {
                    temp_t0 = D_84385B88[BattleAnim_RandomIntWithWarmup(4.0f)];
                } while (temp_t0 == gBattleScene.unk_00->unk_50);
                gBattleScene.unk_00->unk_50 = temp_t0;
                BattleScene_SelectCameraPreset(D_84390204, arg0, gBattleScene.unk_00->unk_50, 1);
                break;

            default:
                if (temp_v0 != gBattleScene.unk_00->unk_50) {
                    BattleScene_SelectCameraPreset(D_84390204, arg0, temp_v0, 1);
                }
                break;
        }
    }
}

void BattleScene_SelectActionCameraPresetFromTiming(unk_D_86002F34_00C* arg0, s32 arg1) {
    BattleMonRuntime* sp1C = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;
    s32 sp18;

    if ((gBattleScene.unk_00->unk_50 != 1) && (gBattleScene.unk_00->unk_50 != 4) && (gBattleScene.unk_00->unk_50 != 5) &&
        (gBattleScene.unk_00->unk_50 != 8) && (gBattleScene.unk_00->unk_50 != 9) && (gBattleScene.unk_00->unk_50 != 0xA) &&
        (gBattleScene.unk_00->unk_50 != 0xB)) {
        if (arg1 == 1) {
            sp18 = BattleScene_GetMappedAnimationTimingField0E(D_84390010[gBattleScene.unk_00->unk_2C]);
        } else {
            sp18 = BattleScene_GetAnimationTimingField0E(D_84390010[gBattleScene.unk_00->unk_2C]);
        }

        if ((sp1C->unk_5A == 0x3A) || (sp1C->unk_5A == 0x8F)) {
            sp18 = 0x19;
        }

        if (sp18 == 25) {
            return;
        }

        switch (sp18) {
            case 20:
                gBattleScene.unk_00->unk_50 = D_84385B70[BattleAnim_RandomIntWithWarmup(ARRAY_COUNT(D_84385B70))];
                if (sp18 != gBattleScene.unk_00->unk_50) {
                    BattleScene_SelectCameraPreset(D_84390204, arg0, gBattleScene.unk_00->unk_50, 1);
                }
                break;

            case 21:
                gBattleScene.unk_00->unk_50 = D_84385B78[BattleAnim_RandomIntWithWarmup(ARRAY_COUNT(D_84385B78))];
                if (sp18 != gBattleScene.unk_00->unk_50) {
                    BattleScene_SelectCameraPreset(D_84390204, arg0, gBattleScene.unk_00->unk_50, 1);
                }
                break;

            case 22:
                gBattleScene.unk_00->unk_50 = D_84385B7C[BattleAnim_RandomIntWithWarmup(ARRAY_COUNT(D_84385B7C))];
                if (sp18 != gBattleScene.unk_00->unk_50) {
                    BattleScene_SelectCameraPreset(D_84390204, arg0, gBattleScene.unk_00->unk_50, 1);
                }
                break;

            case 23:
                gBattleScene.unk_00->unk_50 = D_84385B80[BattleAnim_RandomIntWithWarmup(ARRAY_COUNT(D_84385B80))];
                if (sp18 != gBattleScene.unk_00->unk_50) {
                    BattleScene_SelectCameraPreset(D_84390204, arg0, gBattleScene.unk_00->unk_50, 1);
                }
                break;

            case 24:
                gBattleScene.unk_00->unk_50 = D_84385B88[BattleAnim_RandomIntWithWarmup(ARRAY_COUNT(D_84385B88))];
                if (sp18 != gBattleScene.unk_00->unk_50) {
                    BattleScene_SelectCameraPreset(D_84390204, arg0, gBattleScene.unk_00->unk_50, 1);
                }
                break;

            default:
                if (sp18 != gBattleScene.unk_00->unk_50) {
                    if (1) {}
                    BattleScene_SelectCameraPreset(D_84390204, arg0, sp18, 1);
                }
                break;
        }
    }
}

s32 BattleScene_ApplyActionCameraMode(unk_D_86002F34_00C* arg0, s32 arg1) {
    UNUSED s32 pad;
    s32 sp18 = 0;

    switch (gBattleScene.unk_00->unk_50) {
        case 1:
            BattleAnim_ApproachF(&arg0->unk_24.fovy, 60.0f, 0.03f);
            sp18 = 1;
            break;

        case 4:
        case 5:
        case 8:
        case 9:
        case 10:
        case 11:
            BattleScene_AnimateCameraPresetToOwner(arg0, D_84390204);
            sp18 = 1;
            break;

        default:
            if ((D_84390204->unk_4B4 != 6) && (D_84390204->unk_4B4 != 4) && (arg1 != 0)) {
                BattleScene_ReframeAndRecomputeDistance(arg0, D_84390204);
            }
            break;
    }
    return sp18;
}

void BattleScene_CleanupActionPresentation(UNUSED unk_D_86002F34_00C* arg0) {
    BattleScene_CleanupParticipantHideFlag(D_84390204);
    Battle_ClearRuntimeFlags(D_84390204, 0x10);
    if (BattleScene_ActionPresentationCleanupCheck() == 0) {
        gBattleScene.unk_00->unk_20 = 2;
    }
    BattleAnim_CleanupEffects(1);
}

s32 BattleScene_WaitForActionCameraDuration(UNUSED unk_D_86002F34_00C* arg0) {
    if (BattleScene_AdvanceCameraFrameCounter(BattleScene_GetCameraShotDuration(D_84390204)) != 0) {
        return 1;
    }
    return 0;
}

void BattleScene_ActionSetupAnimationDefault(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_3C) {
        case 0:
            BattleScene_ApplyActionCameraMode(arg0, 1);
            if (BattleScene_WaitForActionCameraDuration(arg0) != 0) {
                BattleScene_ResetCameraFrameCounter();
                BattleScene_SetPhaseFlag();
                BattleScene_SelectActionCameraPresetFromTiming(arg0, 0);
            }
            break;

        case 1:
            BattleScene_ApplyActionCameraMode(arg0, 1);
            if (Battle_IsRowAnimationSettled(D_84390204, 0x32) != 0) {
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ClearPhaseFlag();
                BattleScene_CleanupActionPresentation(arg0);
            }
            break;
    }
}

void BattleScene_ActionSetupAnimationVariantA(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_3C) {
        case 0:
            BattleScene_ReframeAndRecomputeDistance(arg0, D_84390204);
            if (Battle_IsRowAnimationSettled(D_84390204, 0x32) != 0) {
                BattleScene_SaveCameraFov(arg0);
                D_84390230--;
                BattleScene_RefreshActionCameraPreset(arg0);
                if ((D_84390230 < 0) || (gBattleMoveFailed != 0)) {
                    D_84390230 = D_8439022C;
                    gBattleScene.unk_00->unk_3C++;
                } else {
                    BattleScene_EnterStateRow(D_84390010[gBattleScene.unk_00->unk_2C], 0x13);
                    Audio_FadeAndClearStoredSounds();
                    BattleAnim_CleanupEffects(1);
                    gBattleScene.unk_00->unk_3C = 0;
                }
            }
            break;

        case 1:
            BattleScene_ReframeAndRecomputeDistance(arg0, D_84390204);
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ClearPhaseFlag();
            gBattleScene.unk_00->unk_48 = 0;
            Audio_FadeAndClearStoredSounds();
            BattleScene_CleanupActionPresentation(arg0);
            break;
    }
}

void BattleScene_ActionSetupAnimationVariantB(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_3C) {
        case 0:
            if (BattleScene_AdvanceCameraFrameCounter(0xF) != 0) {
                BattleAnim_QueueEffectList(7, D_84390204);
                BattleScene_ResetCameraFrameCounter();
                BattleScene_SetPhaseFlag();
                BattleScene_SelectCameraFollowPreset(D_84390204, arg0, 3);
            }
            break;

        case 1:
            BattleScene_ReframeAndRecomputeDistance(arg0, D_84390204);
            if (Battle_IsRowAnimationSettled(D_84390204, 0x1E) != 0) {
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ClearPhaseFlag();
                BattleScene_CleanupActionPresentation(arg0);
            }
            break;
    }
}

void BattleScene_ActionSetupAnimationVariantC(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    BattleMonRuntime* sp18 = &D_84390204->unk_654.unk_38;

    BattleScene_GetParticipantSideIndex(D_84390204);

    switch (gBattleScene.unk_00->unk_3C) {
        case 0:
            BattleScene_ResetCameraFrameCounter();
            BattleScene_SetPhaseFlag();
            Vec3f_SetComponentsDuplicate(&D_843901B0.unk_00, D_84390204->unk_4B0 * -175.0f, 25.0f, 0.0f);
            BattleScene_LoadCameraPreset(&D_84384958, arg0, D_84390204);
            if ((D_84390204->unk_000.objectType != 0x33) && (D_84390204->unk_000.objectType != 0x32)) {
                BattleAnim_PlayMoveEffectScriptA(D_84390204, sp18->unk_5A);
            }
            break;

        case 1:
            if (BattleScene_AnimateCameraPreset(arg0, D_84390204, 1, 0) != 0) {
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ClearPhaseFlag();
                BattleScene_CleanupActionPresentation(arg0);
            }
            break;
    }
}

void BattleScene_ActionSetupAnimationVariantD(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_3C) {
        case 0:
            BattleScene_ResetCameraFrameCounter();
            BattleScene_SetPhaseFlag();
            BattleAnim_GetOwnerDefaultAnchorPosition(D_84390204, &D_843901B0.unk_00);
            BattleScene_LoadCameraPreset(&D_84384924, arg0, D_84390204);
            break;

        case 1:
            BattleScene_AnimateCameraPresetToOwner(arg0, D_84390204);
            if (Battle_IsRowAnimationSettled(D_84390204, 0x1E) != 0) {
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ClearPhaseFlag();
                BattleScene_CleanupActionPresentation(arg0);
            }
            break;
    }
}

void BattleScene_ActionSetupAnimationStep(unk_D_86002F34_00C* arg0) {
    BattlerState* temp_a2 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;
    u32 var_v1 = 0;

    if (gBattleScene.unk_00->unk_48 == 0x18) {
        var_v1 = 0xA;
    } else if (gBattleScene.unk_00->unk_48 == 0x14) {
        var_v1 = 0xB;
    } else if (temp_a2->unk_34 & 0x4000) {
        var_v1 = 0xC;
    } else if (temp_a2->unk_34 & 0x10) {
        var_v1 = 0xC;
    } else if (temp_a2->unk_34 & 0x400) {
        var_v1 = 0xD;
    }

    switch (var_v1) {
        case 0:
            BattleScene_ActionSetupAnimationDefault(arg0);
            break;

        case 10:
            BattleScene_ActionSetupAnimationVariantA(arg0);
            break;

        case 11:
            BattleScene_ActionSetupAnimationVariantB(arg0);
            break;

        case 12:
            BattleScene_ActionSetupAnimationVariantC(arg0);
            break;

        case 13:
            BattleScene_ActionSetupAnimationVariantD(arg0);
            break;

        default:
            BattleScene_ActionSetupAnimationDefault(arg0);
            break;
    }
}

void BattleScene_StopSpecialOwnerAnimation(Battler* arg0) {
    if (arg0->unk_654.unk_38.unk_5A == 0x45) {
        BattleAnim_ResetOwnerFacingAndExitStatusIdle(arg0);
    }
}

s32 BattleScene_IsSpecialOwnerAnimation(Battler* arg0) {
    if (arg0->unk_654.unk_38.unk_5A == 0x53) {
        return 1;
    }
    return 0;
}

void BattleScene_CompleteHpUpdateTransition(unk_D_86002F34_00C* arg0, s32* arg1, s32* arg2) {
    if ((*arg1 == 1) && (*arg2 == 1)) {
        BattleBox_Close();
        Battle_ResetModelToIdleAnim(D_84390204);
        gBattleScene.unk_00->unk_1A = 0;
        BattleScene_ResetCameraFrameCounter();
        BattleScene_ResetCameraSubstepCounter();
        BattleScene_ClearPhaseFlag();
        BattleScene_ResetAnimationStep();
        BattleScene_UpdateDisplayedHpAndTransition(arg0);
    }
}

void BattleScene_RunBasicHpTransition(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_3C) {
        case 0:
            if (BattleScene_AdvanceOwnerAnimation98(D_84390200) == 0) {
                BattleScene_SelectCameraShot(D_84390200, arg0, 0);
                BattleScene_ResetCameraFrameCounter();
                BattleScene_SetPhaseFlag();
                BattleScene_EnterStateRow(D_84390204, 0xE);
                BattleScene_CleanupOpponentSpecialAnimFlag(D_84390200);
                func_84370ADC(D_84390200);
                BattleBox_Open(1);
            }
            break;

        case 1:
            BattleScene_FrameCamera(arg0, D_84390200);
            if ((BattleScene_IsOpponentRowCheckpointReached(D_84390200) != 0) || (BattleScene_AdvanceCameraFrameCounter(0x5A) != 0)) {
                D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
                D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);
                BattleScene_CompleteHpUpdateTransition(arg0, &D_84390220, &D_84390224);
            }
            break;
    }
}

void BattleScene_RunConditionalHpTransition(unk_D_86002F34_00C* arg0) {
    s32 sp1C;

    switch (gBattleScene.unk_00->unk_3C) {
        case 0:
            if (BattleScene_AdvanceOwnerAnimation98(D_84390200) == 0) {
                func_84370ADC(D_84390200);
                BattleScene_SelectCameraShot(D_84390200, arg0, 0);
                BattleScene_ResetCameraFrameCounter();
                BattleScene_SetPhaseFlag();
                BattleScene_EnterStateRow(D_84390204, 0xB);
                BattleScene_CleanupOpponentSpecialAnimFlag(D_84390200);
                BattleBox_Open(1);
            }
            break;

        case 1:
            BattleScene_FrameCamera(arg0, D_84390200);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);
            sp1C = func_84305458(D_84390204);
            if ((sp1C == 2) && ((BattleScene_IsOpponentRowCheckpointReached(D_84390200) != 0) || (BattleScene_AdvanceCameraFrameCounter(0x64) != 0))) {
                BattleScene_CompleteHpUpdateTransition(arg0, &D_84390220, &D_84390224);
            } else if (sp1C == 1) {
                BattleScene_CompleteHpUpdateTransition(arg0, &D_84390220, &D_84390224);
            }
            break;
    }
}

void BattleScene_RunMoveEffectEndHpTransition(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp34 = &D_84390204->unk_654.unk_38;
    UNUSED s32 pad;
    UNUSED s16 pad2;
    s16 sp2C;

    switch (gBattleScene.unk_00->unk_3C) {
        case 0:
            if (BattleScene_AdvanceOwnerAnimation98(D_84390200) == 0) {
                func_84370ADC(D_84390200);
                BattleScene_SelectCameraShot(D_84390200, arg0, 0);
                BattleScene_ResetCameraFrameCounter();
                BattleScene_SetPhaseFlag();
                BattleScene_CleanupOpponentSpecialAnimFlag(D_84390200);
                BattleBox_Open(1);
                sp2C = Battle_GetSideAnimTableFieldB(D_84390200);
                BattleAnim_QueueMoveEffectEnd(sp34->unk_5A, D_84390204, D_84390200, sp2C, Battle_GetSideAnimTableFieldC(D_84390200));
                BattleScene_SetParticipantModelFlags(D_84390200, 0x10, 0);
            }
            break;

        case 1:
            BattleScene_FrameCamera(arg0, D_84390200);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);
            if ((BattleScene_IsOpponentRowCheckpointReached(D_84390200) != 0) || (BattleScene_AdvanceCameraFrameCounter(0x5A) != 0)) {
                BattleScene_CompleteHpUpdateTransition(arg0, &D_84390220, &D_84390224);
            }
            break;
    }
}

void BattleScene_RunActionEffectHpTransition(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp24 = &D_84390200->unk_654.unk_38;
    UNUSED s32 pad;
    s32 sp1C;
    s32 temp_v0;
    s32 var_a0;

    switch (gBattleScene.unk_00->unk_3C) {
        case 0:
            if (BattleScene_AdvanceOwnerAnimation98(D_84390200) == 0) {
                BattleScene_StopSpecialOwnerAnimation(D_84390204);
                BattleBox_Open(1);
                BattleScene_ResetCameraFrameCounter();
                BattleScene_SetPhaseFlag();
                BattleScene_SetDamageShakeAmplitude(D_84390200);
                if (gBattleScene.unk_00->unk_1A == 3) {
                    BattleScene_EnterStateRow(D_84390204, 0xB);
                } else {
                    BattleScene_EnterStateRow(D_84390204, 4);
                }
                BattleScene_SelectCameraShot(D_84390200, arg0, 0);
                func_84370ADC(D_84390200);
                BattleScene_CleanupOpponentSpecialAnimFlag(D_84390200);
                BattleAnim_ClearFreezeStatusAnimationIfThawed(D_84390200);
            }
            break;

        case 1:
            if (BattleScene_AdvanceCameraFrameCounter(5) != 0) {
                BattleScene_ResetOwnerPresentationFlags(D_84390204);
                gBattleScene.unk_00->unk_3C++;
            }
            break;

        case 2:
            BattleScene_ResetAnimationStep();
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);
            if (sp24->unk_0C != 0) {
                if (BattleScene_IsOpponentRowCheckpointReached(D_84390200) != 0) {
                    gBattleScene.unk_00->unk_3C = 4;
                } else if (BattleScene_IsRowAnimWaitComplete(D_84390200, 2) != 0) {
                    gBattleScene.unk_00->unk_3C = 5;
                } else if (BattleScene_FrameCamera(arg0, D_84390200) != 0) {
                    gBattleScene.unk_00->unk_3C = 3;
                }
            } else if (BattleScene_FrameCamera(arg0, D_84390200) != 0) {
                gBattleScene.unk_00->unk_3C = 4;
            }
            break;

        case 3:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);
            BattleScene_FrameCamera(arg0, D_84390200);
            if (BattleScene_IsOpponentRowCheckpointReached(D_84390200) != 0) {
                gBattleScene.unk_00->unk_3C++;
            } else if (BattleScene_IsRowAnimWaitComplete(D_84390200, 0xF) != 0) {
                gBattleScene.unk_00->unk_3C++;
            }
            break;

        case 4:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);
            temp_v0 = BattleScene_FrameCamera(arg0, D_84390200);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (temp_v0 != 0) && (BattleScene_AdvanceCameraFrameCounter(0xF) != 0)) {
                gBattleScene.unk_00->unk_3C = 6;
            }
            break;

        case 5:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);
            sp1C = BattleScene_FrameCamera(arg0, D_84390200);
            if ((BattleScene_IsSpecialOwnerAnimation(D_84390204) != 0) && ((D_843C4DEC < 0xA) || (gBattleMoveFailed != 0)) &&
                !(sp24->unk_15 & 0x20)) {
                var_a0 = 0x5A;
            } else {
                var_a0 = 0xF;
            }

            if ((D_84390220 == 1) && (D_84390224 == 1) && (sp1C != 0) && (BattleScene_AdvanceCameraFrameCounter(var_a0) != 0)) {
                gBattleScene.unk_00->unk_3C++;
            }
            break;

        case 6:
            if (BattleScene_AdvanceOwnerAnimationAndClearFlags(D_84390200) == 0) {
                D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
                D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);
                BattleScene_FrameCamera(arg0, D_84390200);
                BattleScene_CompleteHpUpdateTransition(arg0, &D_84390220, &D_84390224);
            }
            break;
    }
}

void func_84324404(void) {
}

void func_8432440C(void) {
}

void BattleScene_RunRepeatedHitHpTransition(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp24 = &D_84390204->unk_654.unk_38;
    MovePresentationCue* temp_v1 = &D_84384570[BattleScene_GetParticipantSideIndex(D_84390200)]->unk_000[sp24->unk_5A - 1];
    volatile s32 sp1C;
    s32 temp_v0_2;

    if (D_84390200->unk_000.objectType == 0x98) {
        sp1C = 0xF;
    } else if (temp_v1->unk_0A == 0xFF) {
        sp1C = D_84390204->unk_000.transformAnim.data->endFrame - temp_v1->unk_06;
    } else {
        sp1C = temp_v1->unk_0A - temp_v1->unk_06;
    }

    switch (gBattleScene.unk_00->unk_3C) {
        case 0:
            if (BattleScene_AdvanceOwnerAnimation98(D_84390200) == 0) {
                BattleScene_ResetAnimationStep();
                BattleScene_SetDamageShakeAmplitude(D_84390200);
                BattleScene_EnterStateRow(D_84390204, 4);
                D_84390230--;
                BattleScene_SelectCameraShot(D_84390200, arg0, D_84390230 + 1);
                if (D_84390230 < 0) {
                    BattleScene_SelectCameraShot(D_84390200, arg0, D_84390230 + 1);
                    BattleScene_FrameCamera(arg0, D_84390200);
                    func_84370ADC(D_84390200);
                    BattleScene_ResetCameraFrameCounter();
                    gBattleScene.unk_00->unk_3C = 2;
                    BattleScene_CleanupOpponentSpecialAnimFlag(D_84390200);
                    BattleBox_Open(1);
                } else {
                    gBattleScene.unk_00->unk_3C++;
                }
            }
            break;

        case 1:
            BattleScene_ReframeAndRecomputeDistance(arg0, D_84390200);
            if (BattleScene_AdvanceCameraFrameCounter(sp1C) != 0) {
                Audio_FadeAndClearStoredSounds();
                BattleAnim_CleanupEffects(1);
                gBattleScene.unk_00->unk_3C = 0;
            }
            break;

        case 2:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);

            if (sp24->unk_0C != 0) {
                if (BattleScene_IsOpponentRowCheckpointReached(D_84390200) != 0) {
                    gBattleScene.unk_00->unk_3C = 5;
                }

                if (BattleScene_IsRowAnimWaitComplete(D_84390200, 0xF) != 0) {
                    gBattleScene.unk_00->unk_3C = 5;
                }

                if (BattleScene_FrameCamera(arg0, D_84390200) != 0) {
                    gBattleScene.unk_00->unk_3C = 4;
                }
            } else if (BattleScene_FrameCamera(arg0, D_84390200) != 0) {
                BattleScene_ResetCameraFrameCounter();
                gBattleScene.unk_00->unk_3C = 5;
            }
            break;

        case 3:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);

            if (BattleScene_IsOpponentRowCheckpointReached(D_84390200) != 0) {
                gBattleScene.unk_00->unk_3C = 5;
            }

            if (BattleScene_FrameCamera(arg0, D_84390200) != 0) {
                gBattleScene.unk_00->unk_3C = 9;
            }
            break;

        case 4:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);

            if (BattleScene_IsOpponentRowCheckpointReached(D_84390200) != 0) {
                gBattleScene.unk_00->unk_3C = 5;
            }

            BattleScene_FrameCamera(arg0, D_84390200);

            if (BattleScene_IsRowAnimWaitComplete(D_84390200, 0xF) != 0) {
                gBattleScene.unk_00->unk_3C++;
            }
            break;

        case 5:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);
            temp_v0_2 = BattleScene_FrameCamera(arg0, D_84390200);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (temp_v0_2 != 0) && (BattleScene_AdvanceCameraFrameCounter(0xF) != 0)) {
                gBattleScene.unk_00->unk_3C++;
            }
            break;

        case 6:
            if (BattleScene_AdvanceOwnerAnimationAndClearFlags(D_84390200) == 0) {
                D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390200);
                D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390204);
                BattleScene_FrameCamera(arg0, D_84390200);
                BattleScene_CompleteHpUpdateTransition(arg0, &D_84390220, &D_84390224);
            }
            break;
    }
}

void BattleScene_ActionSetupFinalizeStep(unk_D_86002F34_00C* arg0) {
    BattleScene_ResetCameraFov(arg0);
    func_84370ADC(D_84390010[!gBattleScene.unk_00->unk_2C]);
    if (gBattleScene.unk_00->unk_48 == 0x16) {
        BattleScene_RunBasicHpTransition(arg0);
    } else if (gBattleScene.unk_00->unk_48 == 0x20) {
        BattleScene_RunMoveEffectEndHpTransition(arg0);
    } else if (gBattleScene.unk_00->unk_48 == 0x1A) {
        BattleScene_RunConditionalHpTransition(arg0);
    } else if (gBattleScene.unk_00->unk_1A == 1) {
        BattleScene_RunRepeatedHitHpTransition(arg0);
    } else {
        BattleScene_RunActionEffectHpTransition(arg0);
    }
}

void BattleScene_Phase2(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_ActionSetupCameraStep(arg0);
            break;

        case 1:
            BattleScene_ActionSetupAnimationStep(arg0);
            break;

        case 2:
            BattleScene_ActionSetupFinalizeStep(arg0);
            break;
    }
}

void BattleScene_Phase3(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_ActionSetupCameraStep(arg0);
            break;

        case 1:
            BattleScene_ActionSetupAnimationStep(arg0);
            break;

        case 2:
            BattleScene_ActionSetupFinalizeStep(arg0);
            break;
    }
}

s32 BattleScene_PhaseSelectMoveAnim(void) {
    BattleScene_ApplyActionCameraMode(gBattleScene.unk_00->unk_DC, 0);

    if (BattleScene_AdvanceCameraFrameCounter(BattleScene_GetCameraShotDuration(D_84390204)) == 0) {
        return 0;
    }

    if ((gBattleScene.unk_00->unk_48 != 0x1E) && (gBattleScene.unk_00->unk_48 != 0x27)) {
        BattleBox_Open(3);
    }

    if (gBattleScene.unk_00->unk_48 == 0x1B) {
        func_800414B8(BattleScene_GetParticipantDisplayPlayerNumber(D_84390204));
    }

    switch (gBattleScene.unk_00->unk_48) {
        case 7:
            return BattleScene_TransitionToPhaseFull(7);

        case 21:
            return BattleScene_TransitionToPhaseFull(7);

        case 39:
            return BattleScene_TransitionToPhaseFull(7);

        case 27:
            return BattleScene_TransitionToPhaseFull(0x1B);

        case 30:
            return BattleScene_TransitionToPhaseFull(0x1E);

        case 28:
            return BattleScene_TransitionToPhaseFull(0x1C);

        case 15:
            return BattleScene_TransitionToPhaseFull(0xF);

        case 25:
            return BattleScene_TransitionToPhaseFull(0x19);

        case 29:
            return BattleScene_TransitionToPhaseFull(0x1D);

        case 38:
            return BattleScene_TransitionToPhaseFull(0x26);

        case 12:
            return BattleScene_TransitionToPhaseFull(0xC);

        case 13:
            return BattleScene_TransitionToPhaseFull(0xD);

        case 14:
            return BattleScene_TransitionToPhaseFull(0xE);

        case 17:
            return BattleScene_TransitionToPhaseFull(0x11);

        case 31:
            return BattleScene_TransitionToPhaseFull(0x1F);
    }

    return 0;
}

void BattleScene_Phase7(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp1C = &D_84390204->unk_654.unk_38;
    MovePresentationCue* sp18 = &D_84384570[BattleScene_GetParticipantSideIndex(D_84390204)]->unk_000[sp1C->unk_5A - 1];

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_SaveCameraFov(arg0);
            BattleScene_SelectActionCameraPresetFromTiming(arg0, 0);
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ResetCameraSubstepCounter();
            if (sp18->unk_04 < 0x15) {
                func_84370ADC(D_84390204);
            }
            gBattleScene.unk_00->unk_20++;
            break;

        case 1:
            BattleScene_ApplyActionCameraMode(arg0, 1);
            if (D_84390204->unk_4C4 == (sp18->unk_04 + 1)) {
                func_84370ADC(D_84390204);
            }

            if (D_84390204->unk_4C4 >= (sp18->unk_04 + 0xA)) {
                D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
                D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            }

            if ((D_84390204->unk_4C4 == (sp18->unk_04 + 0x12)) && (sp1C->unk_5A == 0x64)) {
                BattleBox_Open(0xF);
            }

            if (Battle_IsRowAnimationSettled(D_84390204, 0x3C) != 0) {
                BattleScene_ResetCameraFrameCounter();
                gBattleScene.unk_00->unk_20++;
            }
            break;

        case 2:
            if (D_84390204->unk_4C4 == (sp18->unk_04 + 1)) {
                func_84370ADC(D_84390204);
            }
            BattleScene_ApplyActionCameraMode(arg0, 1);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (BattleScene_AdvanceCameraFrameCounter(0xF) != 0)) {
                if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                    gBattleScene.unk_00->unk_34 = 3;
                }
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ResetAnimationStep();
                BattleScene_WaitForDisplayedHpAnimations(arg0);
            }
            break;
    }
}

void BattleScene_Phase38(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_SaveCameraFov(arg0);
            BattleScene_SetCameraOwnerShot(arg0, D_84390204);
            BattleScene_UpdateCameraModelOffset(D_84390204, arg0);
            func_84370ADC(D_84390204);
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ResetCameraSubstepCounter();
            gBattleScene.unk_00->unk_20++;
            break;

        case 1:
            if (Battle_IsRowAnimationSettled(D_84390204, 0x3C) != 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                gBattleScene.unk_00->unk_34 = 3;
            }
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ResetAnimationStep();
            BattleScene_WaitForDisplayedHpAnimations(arg0);
            break;
    }
}

void BattleScene_Phase27(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_SaveCameraFov(arg0);
            func_84370ADC(D_84390204);
            BattleScene_SelectActionCameraPresetFromTiming(arg0, 0);
            BattleScene_ResetCameraFrameCounter();
            gBattleScene.unk_00->unk_20++;
            break;

        case 1:
            BattleScene_ApplyActionCameraMode(arg0, 1);
            if (BattleScene_AdvanceCameraFrameCounter(0x28) != 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            BattleScene_ApplyActionCameraMode(arg0, 1);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                gBattleScene.unk_00->unk_34 = 3;
            }
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ResetAnimationStep();
            BattleScene_WaitForDisplayedHpAnimations(arg0);
            break;
    }
}

void BattleScene_Phase30(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp1C = &D_84390200->unk_654.unk_38;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            Battle_ClearRuntimeFlags(D_84390204, 0x1800);
            BattleScene_SaveCameraFov(arg0);
            BattleScene_ResetCameraFrameCounter();
            BattleScene_SelectActionCameraPresetFromTiming(arg0, 0);
            func_84370ADC(D_84390204);
            BattleScene_ResetCameraFrameCounter();
            gBattleScene.unk_00->unk_20++;
            break;

        case 1:
            BattleScene_ApplyActionCameraMode(arg0, 1);
            if (Battle_IsRowAnimationSettled(D_84390204, 0x3C) != 0) {
                BattleScene_ResetCameraFrameCounter();
                gBattleScene.unk_00->unk_20++;
            }
            break;

        case 2:
            if (BattleScene_AdvanceOwnerAnimation98(D_84390200) == 0) {
                BattleAnim_CleanupEffects(1);
                Audio_FadeAndClearStoredSounds();
                BattleScene_SelectCameraShot(D_84390200, arg0, BattleAnim_RandomRange(2));
                BattleScene_EnterStateRow(D_84390204, 4);
                BattleScene_ResetCameraFrameCounter();
                gBattleScene.unk_00->unk_20++;
            }
            break;

        case 3:
            if (BattleScene_AdvanceOwnerAnimationAndClearFlags(D_84390200) == 0) {
                BattleScene_ReframeAndRecomputeDistance(arg0, D_84390200);
                if (gBattleScene.unk_00->unk_14 == 0) {
                    BattleBox_Open(1);
                }
                D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
                D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
                if (BattleScene_AdvanceCameraFrameCounter(0x32) != 0) {
                    gBattleScene.unk_00->unk_20 += 1;
                }
                if (BattleScene_IsOpponentRowCheckpointReached(D_84390200) != 0) {
                    BattleScene_ResetCameraFrameCounter();
                    gBattleScene.unk_00->unk_20++;
                }
            }
            break;

        case 4:
            BattleScene_ReframeAndRecomputeDistance(arg0, D_84390200);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((D_84390224 == 1) && (D_84390220 == 1)) {
                if (sp1C->unk_0C != 0) {
                    BattleAnim_CleanupEffects(1);
                    Audio_FadeAndClearStoredSounds();
                    BattleScene_SelectCameraFollowPreset(D_84390204, arg0, 3);
                    gBattleScene.unk_00->unk_20++;
                } else {
                    if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                        gBattleScene.unk_00->unk_34 = 3;
                    }
                    BattleScene_ResetCameraFrameCounter();
                    BattleScene_ResetAnimationStep();
                    BattleScene_SetPhase(arg0, 5);
                }
            }
            break;

        case 5:
            BattleScene_SelectCameraFollowPreset(D_84390204, arg0, 3);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                gBattleScene.unk_00->unk_34 = 3;
            }
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ResetAnimationStep();
            BattleScene_ResolveDisplayedHpCompletion(arg0);
            break;
    }
}

void BattleScene_Phase28(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_SaveCameraFov(arg0);
            func_84370ADC(D_84390204);
            BattleScene_SelectCameraFollowPreset(D_84390204, arg0, 3);
            BattleScene_ResetCameraFrameCounter();
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            if (BattleScene_AdvanceCameraFrameCounter(0x28) != 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                gBattleScene.unk_00->unk_34 = 3;
            }
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ResetAnimationStep();
            BattleScene_WaitForDisplayedHpAnimations(arg0);
            break;
    }
}

void BattleScene_Phase15(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad[3];
    BattleMonRuntime* sp30 = &D_84390204->unk_654.unk_38;
    BattleMonRuntime* sp2C = &D_84390200->unk_654.unk_38;
    BattlerState* sp28 = &D_84390204->unk_654;
    BattlerState* sp24 = &D_84390200->unk_654;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_SelectActionCameraPresetFromTiming(arg0, 0);
            BattleScene_RecenterCameraOnOwner(arg0, D_84390204);
            if (sp30->unk_4D & 0x10) {
                if (sp2C->unk_4E & 8) {
                    sp28->unk_BC = D_84390204->unk_720->unk_02 = sp24->unk_BE;
                } else if (D_84390200->unk_720->unk_02 == 0x98) {
                    sp28->unk_BC = D_84390204->unk_720->unk_02 = sp2C->unk_0B;
                } else {
                    sp28->unk_BC = D_84390204->unk_720->unk_02 = D_84390200->unk_720->unk_02;
                }
            } else if (sp2C->unk_4E & 8) {
                D_84390204->unk_720->unk_02 = sp24->unk_BE;
            } else if (D_84390200->unk_720->unk_02 == 0x98) {
                D_84390204->unk_720->unk_02 = sp2C->unk_0B;
            } else {
                D_84390204->unk_720->unk_02 = D_84390200->unk_720->unk_02;
            }
            D_84390204->unk_720->unk_04 = &D_84390204->unk_724->unk_01C[D_84390204->unk_654.unk_08];
            D_84390204->unk_720->unk_00 |= 0x80;
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            BattleScene_RecenterCameraOnOwner(arg0, D_84390204);
            if (D_84390204->unk_720->unk_00 & 0x10) {
                D_84390204->unk_720->unk_00 &= ~0x90;
                Battle_LoadOwnerModelForSpecies(D_84390204);
                BattleScene_TickOwnerCameraFraming(D_84390204);
                BattleAnim_PlayMoveEffectScriptA(D_84390204, sp30->unk_5A);
                BattleAnim_PlaySpeciesReactionSound(D_84390204, sp30, 0);
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            BattleScene_RecenterCameraOnOwner(arg0, D_84390204);
            BattleAnim_PlaySpeciesReactionSound(D_84390204, sp30, 0);
            BattleScene_EnterStateRow(D_84390204, 0x12);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 3:
            BattleScene_RecenterCameraOnOwner(arg0, D_84390204);
            D_84390204->unk_728.unk_168->node.flags |= 1;
            D_84390204->unk_728.unk_000.node.flags |= 1;
            BattleScene_TriggerOwnerModelAnimation(D_84390204);
            if (BattleScene_IsRowWaitComplete(D_84390204, 0x32) != 0) {
                BattleScene_ResetAnimationStep();
                BattleScene_UpdateDisplayedHpAndTransition(arg0);
            }
            break;
    }
}

void BattleScene_Phase25(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp1C = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;
    BattlerState* sp18 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_SaveCameraFov(arg0);
            BattleAnim_PlayMoveEffectScriptA(D_84390204, sp1C->unk_5A);
            BattleScene_SelectActionCameraPresetFromTiming(arg0, 0);
            if (!(sp18->unk_34 & 0x800)) {
                BattleAnim_BeginSessionRequest(D_84390204);
            }
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            BattleScene_ApplyActionCameraMode(arg0, 0);
            if (!(sp18->unk_34 & 0x800)) {
                func_84304800(D_84390204);
            }
            if (BattleAnim_IsSessionBusy(D_84390204) == 0) {
                BattleAnim_PlaySpeciesReactionSound(D_84390204, sp1C, 0);
                BattleScene_SelectCameraFollowPreset(D_84390204, arg0, 3);
                BattleScene_ResetCameraFrameCounter();
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            BattleScene_SelectCameraFollowPreset(D_84390204, arg0, 3);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if (BattleScene_AdvanceCameraFrameCounter(0x2E) != 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            if (!(sp18->unk_34 & 0x800)) {
                Battle_SetRuntimeFlags(D_84390204, 0x800);
            }
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                gBattleScene.unk_00->unk_34 = 3;
            }
            BattleScene_ResetAnimationStep();
            BattleScene_WaitForDisplayedHpAnimations(arg0);
            break;
    }
}

s32 BattleScene_EndStatusAnimationsAndCommit(Battler* arg0) {
    BattleAnim_ClearFreezeStatusAnimation(arg0);
    BattleAnim_EndSleepStatusAnimation(arg0);
    func_84370ADC(arg0);
}

void BattleScene_Phase29(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_SaveCameraFov(arg0);
            func_84370ADC(D_84390204);
            BattleScene_SelectActionCameraPresetFromTiming(arg0, 0);
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ResetCameraSubstepCounter();
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            BattleScene_ApplyActionCameraMode(arg0, 1);
            if (Battle_IsRowAnimationSettled(D_84390204, 0x3C) != 0) {
                BattleScene_EndStatusAnimationsAndCommit(D_84390200);
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            BattleScene_ApplyActionCameraMode(arg0, 1);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((D_84390200->unk_654.unk_38.unk_5A & 0xF0) == 0xF0) {
                gBattleScene.unk_00->unk_34 = 3;
            }
            Vec3f_SetComponentsDuplicate(&D_84390204->unk_000.scale, 1.0f, 1.0f, 1.0f);
            Vec3f_SetComponentsDuplicate(&D_84390200->unk_000.scale, 1.0f, 1.0f, 1.0f);
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ResetAnimationStep();
            BattleScene_WaitForDisplayedHpAnimations(arg0);
            break;
    }
}

void BattleScene_Phase12(unk_D_86002F34_00C* arg0) {
    MovePresentationCue* sp4C = &D_84384570[gBattleScene.unk_00->unk_2C]->unk_B00;
    UNUSED s32 pad;
    Vec3f sp3C;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ClearPhaseFlag();
            BattleScene_SelectCameraFollowPreset(D_84390204, arg0, 3);
            BattleScene_ApproachCameraTargetFromOwner(arg0, D_84390204);
            Battle_SetRuntimeFlags(D_84390204, 0x200);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            if (D_84390204->unk_000.position.y >= 100.0f) {
                BattleAnim_GetOwnerDefaultAnchorPosition(D_84390204, &sp3C);
                sp3C.y += BattleAnim_GetOwnerModelHeight(D_84390204);
                D_84390208 = BattleScene_ScaleCameraDistance(D_84390204, 3.0f, 500.0f);
                BattleScene_SetCameraEyeFromPosition(arg0, sp3C, 0x11C6, BattleScene_GetParticipantFacingAngle(D_84390204) - (D_84390204->unk_4B0 * 0x754E),
                              D_84390208, BattleAnim_GetOwnerModelHeight(D_84390204));
                Vec3f_SetComponentsDuplicate(&sp3C, 0.0f, 200.0f, 0.0f);
                BattleAnim_Vec3fCopy(&arg0->unk_60.at, &sp3C);
                BattleAnim_CleanupEffects(2);
                ModelAnim_SetAnimation(&D_84390204->unk_000, sp4C->unk_00);
                arg0->unk_24.fovy = 60.0f;
                gBattleScene.unk_00->unk_20 += 1;
            } else {
                BattleScene_ApproachCameraTargetFromOwner(arg0, D_84390204);
            }
            break;

        case 2:
            BattleAnim_ApproachF(&arg0->unk_24.fovy, 60.0f, 0.2f);
            if (D_84390204->unk_000.position.y >= 200.0f) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (BattleScene_AdvanceCameraFrameCounterUntil(0x1E) != 0)) {
                Battle_SetRuntimeFlags(D_84390010[gBattleScene.unk_00->unk_2C], 4);
                BattleAnim_ClearEffectStateFlag();
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ResetAnimationStep();
                BattleScene_UpdateDisplayedHpAndTransition(arg0);
            }
            break;
    }
}

void BattleScene_Phase13(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    f32 sp28;
    UNUSED s16 pad2;
    u16 sp24 = D_84385B8C;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_SaveCameraFov(arg0);
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ClearPhaseFlag();
            BattleScene_SelectCameraFollowPreset(D_84390204, arg0, 3);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            if (D_84390204->unk_4B8 == 2) {
                BattleScene_UpdateCameraVerticalFraming(arg0, D_84390204);
                D_84390204->unk_000.node.renderFlags &= 0xFFBF;
            }

            if ((D_84390204->unk_000.objectType == 0x32) || (D_84390204->unk_000.objectType == 0x33)) {
                if (BattleScene_IsRowWaitComplete(D_84390204, 0x1E) != 0) {
                    BattleBox_Close();
                    Battle_SetRuntimeFlags(D_84390204, 0x4000);
                    D_84390204->unk_000.node.renderFlags &= 0xFFDF;
                    gBattleScene.unk_00->unk_20 += 1;
                }
            } else if (BattleAnim_IsAssetLoadBusy(D_84390204) == 0) {
                if (BattleScene_ByteArrayContains(D_84390204->unk_000.objectType, (u8*)&sp24, 2) != 0) {
                    sp28 = 10.0f;
                } else {
                    sp28 = 3.5f;
                }

                if (D_84390204->unk_000.position.y <= (-BattleAnim_GetOwnerModelHeight(D_84390204) * sp28)) {
                    Battle_SetRuntimeFlags(D_84390204, 0x4000);
                    D_84390204->unk_000.node.renderFlags &= 0xFFDF;
                    gBattleScene.unk_00->unk_20 += 1;
                }
            }
            break;

        case 2:
            if ((D_84390204->unk_000.objectType != 0x32) && (D_84390204->unk_000.objectType != 0x33)) {
                D_84390204->unk_000.node.renderFlags |= 0x40;
            }
            BattleScene_UpdateCameraVerticalFraming(arg0, D_84390204);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            BattleScene_ResetAnimationStep();
            BattleScene_WaitForDisplayedHpAnimations(arg0);
            break;
    }
}

void BattleScene_Phase14(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_SelectActionCameraPresetFromTiming(arg0, 1);
            BattleScene_SaveCameraFov(arg0);
            BattleScene_ResetCameraFrameCounter();
            BattleScene_ResetCameraSubstepCounter();
            func_84370ADC(D_84390204);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            BattleScene_ApplyActionCameraMode(arg0, 1);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if (BattleScene_IsMoveKeyedRowWaitComplete(D_84390204, 0x1E) != 0) {
                BattleScene_ResetAnimationStep();
                BattleScene_WaitForDisplayedHpAnimations(arg0);
            }
            break;
    }
}

void BattleScene_Phase17(unk_D_86002F34_00C* arg0) {
    BattlerState* sp1C = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_ResetCameraFrameCounter();
            BattleScene_SaveCameraFov(arg0);
            func_84370ADC(D_84390204);
            if (!(sp1C->unk_34 & 2)) {
                BattleScene_SelectActionCameraPresetFromTiming(arg0, 0);
            }
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if (BattleScene_AdvanceCameraFrameCounter(0x3C) != 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            BattleScene_ResetAnimationStep();
            BattleScene_WaitForDisplayedHpAnimations(arg0);
            break;
    }
}

void BattleScene_PhaseFaint(unk_D_86002F34_00C* arg0) {
    BattleScene_ResetCameraFov(arg0);

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            if (BattleScene_AdvanceOwnerAnimation98(D_84390204) == 0) {
                BattleBox_Open(2);
                BattleScene_ResetOwnerPresentationFlags(D_84390204);
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 1:
            BattleScene_ResetAnimationStep();
            BattleScene_ClearStateTickCallbacks();
            BattleScene_EnterStateRow(D_84390204, 0xF);
            BattleScene_SelectCameraShot(D_84390204, arg0, 3);
            BattleScene_SetDamageShakeAmplitude(D_84390204);
            BattleAnim_QueueEffectList(8, D_84390204);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 2:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            BattleScene_FrameCamera(arg0, D_84390204);
            if (BattleScene_IsRowZeroCheckpointReached(D_84390204) != 0) {
                gBattleScene.unk_00->unk_20 += 1;
            } else if (BattleScene_IsRowWaitComplete(D_84390204, 0x32) != 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            BattleScene_FrameCamera(arg0, D_84390204);
            if (BattleScene_AdvanceOwnerAnimationAndClearFlags(D_84390204) == 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 4:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            BattleScene_FrameCamera(arg0, D_84390204);
            BattleScene_ResetAnimationStep();
            BattleScene_UpdateDisplayedHpAndTransition(arg0);
            break;
    }
}

void BattleScene_Phase31(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_SaveCameraFov(arg0);
            func_84370ADC(D_84390204);
            D_84390204->unk_4C8 = 1;
            BattleScene_ResetCameraFrameCounter();
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if (BattleScene_AdvanceCameraFrameCounter(0x3C) != 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            BattleScene_ResetAnimationStep();
            BattleScene_WaitForDisplayedHpAnimations(arg0);
            break;
    }
}

void func_84326A70(void) {
}

void BattleScene_Phase4(UNUSED unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_BeginBattlePhase();

        case 1:
            break;
    }
}

void BattleScene_Phase16(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    s32 idx = gBattleScene.unk_00->unk_2C;
    MovePresentationCue* sp1C = &D_84384570[idx]->unk_A80;

    BattleScene_ResetCameraFov(arg0);

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_ResetAnimationStep();
            BattleBox_Open(2);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            if (BattleScene_AdvanceOwnerAnimation98(D_84390204) == 0) {
                Battle_ResetModelToIdleAnim(D_84390204);
                BattleAnim_CleanupEffects(1);
                BattleScene_EnterStateRow(D_84390204, 0xF);
                BattleScene_SelectCameraShot(D_84390204, arg0, 3);
                BattleScene_SetDamageShakeAmplitude(D_84390204);
                BattleScene_ResetAnimationStep();
                ModelAnim_SetAnimation(&D_84390204->unk_000, sp1C->unk_00);
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            if (BattleScene_AdvanceCameraFrameCounter(0x28) != 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            if (BattleScene_AdvanceOwnerAnimationAndClearFlags(D_84390204) == 0) {
                BattleBox_Close();
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 4:
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((D_84390220 != 0) && (D_84390224 != 0)) {
                BattleScene_ResetAnimationStep();
                BattleScene_UpdateDisplayedHpAndTransition(arg0);
            }
            break;
    }
}

void BattleScene_PhaseMoveFailedMessage(unk_D_86002F34_00C* arg0) {
    BattlerState* sp1C = &D_84390200->unk_654;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            if (BattleScene_AdvanceOwnerAnimation98(D_84390200) == 0) {
                BattleBox_Open(2);
                BattleScene_StopSpecialOwnerAnimation(D_84390204);
                BattleScene_ResetCameraFov(arg0);
                BattleAnim_CleanupEffects(1);

                if (sp1C->unk_34 & 0x200) {
                    BattleScene_SelectCameraShot(D_84390200, arg0, D_84390228 = 2);
                } else {
                    if (D_84390200->unk_000.objectType == 0xF) {
                        BattleScene_SelectCameraShot(D_84390200, arg0, 0);
                    }
                    BattleScene_SelectCameraShot(D_84390200, arg0, D_84390228 = BattleAnim_RandomRange(2));
                }

                BattleScene_EnterStateRow(D_84390204, 0xC);
                BattleScene_ResetCameraFrameCounter();
                BattleAnim_UpdateMoveFailedFlag();
                gBattleScene.unk_00->unk_20 += 1;
                BattleScene_CleanupOpponentAnimationFlags(D_84390200);
            }
            break;

        case 1:
            if ((D_84390200->unk_000.objectType == 0xF) && !(sp1C->unk_34 & 0x200)) {
                BattleScene_FrameCamera(arg0, D_84390200);
            }

            if (BattleScene_AdvanceCameraFrameCounter(0x32) != 0) {
                BattleBox_Close();
                BattleScene_ResetOwnerPresentationFlags(D_84390204);
                BattleScene_CleanupParticipantEffectMode(D_84390204);
                BattleScene_ClearPhaseFlag();
                BattleScene_ResetCameraFrameCounter();
                BattleScene_ResetAnimationStep();
                BattleScene_UpdateDisplayedHpAndTransition(arg0);
            }
            break;
    }
}

void BattleScene_PhaseAttackHit(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp24 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;
    BattleMonRuntime* sp20 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654.unk_38;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            Battle_ResetCryEventIfStruggle(D_84390204);
            BattleScene_SetCameraOwnerStandardShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
            BattleScene_ResetAnimationStep();
            BattleScene_CleanupParticipantEffectMode(D_84390204);
            BattleAnim_CleanupEffects(2);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            if (BattleScene_AdvanceOwnerAnimation(D_84390010[gBattleScene.unk_00->unk_2C]) == 0) {
                Battle_ResetModelToIdleAnim(D_84390204);
                Audio_FadeAndClearStoredSounds();
                BattleAnim_CleanupEffects(1);
                BattleScene_SetCameraOwnerStandardShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
                BattleScene_EnterStateRow(D_84390010[gBattleScene.unk_00->unk_2C], 0xD);

                if (sp24->unk_15 & 0x18) {
                    BattleBox_Open(4);
                    sp24->unk_0C = sp24->unk_0E;
                    sp20->unk_0C = sp20->unk_0E;
                    if (sp24->unk_15 & 0x10) {
                        BattleAnim_QueueEffectList(6, D_84390204);
                    } else {
                        BattleAnim_QueueEffectList(5, D_84390204);
                    }
                    gBattleScene.unk_00->unk_20 += 1;
                } else {
                    BattleBox_Open(5);
                    Audio_PlayCommand(0x22, 0, 0);
                    sp24->unk_0C = sp24->unk_10;
                    sp20->unk_0C = sp20->unk_10;
                    BattleAnim_QueueEffectList(0xA, D_84390204);
                    BattleScene_ResetCameraFrameCounter();
                    gBattleScene.unk_00->unk_20 = 3;
                }
            }
            break;

        case 2:
            BattleScene_SetCameraOwnerStandardShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);

            if ((D_84390220 == 1) && (D_84390224 == 1) && (BattleScene_AdvanceCameraFrameCounterUntil(0x32) != 0)) {
                BattleScene_ResetCameraFrameCounter();
                if (Battle_GetActiveMonHp(D_84390010[gBattleScene.unk_00->unk_2C]) == 0) {
                    BattleScene_ClearPhaseFlag();
                    BattleScene_SetPhase(arg0, 5);
                    gBattleScene.unk_00->unk_2C = !gBattleScene.unk_00->unk_2C;
                } else if (sp24->unk_4D & 0x80) {
                    BattleScene_ResetCameraFrameCounter();
                    Audio_PlayCommand(0x22, 0, 0);
                    sp24->unk_0C = sp24->unk_10;
                    sp20->unk_0C = sp20->unk_10;
                    BattleAnim_QueueEffectList(0xA, D_84390204);
                    gBattleScene.unk_00->unk_20 += 1;
                } else {
                    gBattleScene.unk_00->unk_20 = 4;
                }
            }
            break;

        case 3:
            BattleScene_SetCameraOwnerStandardShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);

            if ((BattleScene_AdvanceCameraFrameCounterUntil(0x32) != 0) && (D_84390220 == 1) && (D_84390224 == 1)) {
                gBattleScene.unk_00->unk_20 += 1;
                BattleScene_ResetCameraFrameCounter();
            }
            break;

        case 4:
            if (BattleScene_AdvanceOwnerAnimationAndClearFlags(D_84390200) == 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 5:
            BattleScene_ResetAnimationStep();
            BattleScene_SetCameraOwnerStandardShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            BattleScene_ResolveDisplayedHpCompletion(arg0);
            break;
    }
}

void BattleScene_PhaseDrainDamage(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp1C = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;
    BattleMonRuntime* sp18 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654.unk_38;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_CleanupParticipantEffectMode(D_84390204);
            BattleAnim_CleanupEffects(2);
            BattleScene_SetCameraOwnerWideShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            if (BattleScene_AdvanceOwnerAnimation(D_84390010[gBattleScene.unk_00->unk_2C]) == 0) {
                Battle_ResetModelToIdleAnim(D_84390204);
                Audio_FadeAndClearStoredSounds();
                BattleAnim_CleanupEffects(1);
                BattleAnim_QueueEffectList(9, D_84390204);
                BattleScene_ResetCameraFrameCounter();
                BattleScene_SetCameraOwnerWideShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
                sp1C->unk_0C = sp1C->unk_12;
                sp18->unk_0C = sp18->unk_12;
                BattleBox_Open(6);
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            if (BattleScene_ApproachCloseCameraShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]) != 0) {
                BattleScene_SelectCameraShot(D_84390204, arg0, 3);
                func_84303E58(D_84390204);
                BattleAnim_PlayBattleSequenceById(D_84390204, 0x1F);
                BattleScene_SetDamageShakeAmplitude(D_84390204);
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            if (BattleScene_AdvanceOwnerAnimationAndClearFlags(D_84390200) == 0) {
                BattleScene_FrameCamera(arg0, D_84390204);
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 4:
            BattleScene_ResetAnimationStep();
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            BattleScene_FrameCamera(arg0, D_84390204);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (BattleScene_AdvanceCameraFrameCounterUntil(0x3C) != 0)) {
                BattleScene_UpdateDisplayedHpAndTransition(arg0);
            }
            break;
    }
}

void BattleScene_Phase10(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_CleanupParticipantEffectMode(D_84390204);
            if (BattleScene_AdvanceOwnerAnimation(D_84390010[gBattleScene.unk_00->unk_2C]) == 0) {
                Battle_ResetModelToIdleAnim(D_84390204);
                Audio_FadeAndClearStoredSounds();
                BattleAnim_CleanupEffects(1);
                BattleScene_ResetCameraFrameCounter();
                BattleAnim_QueueEffectList6(3, D_84390200);
                Audio_PlayCommand(0x23, 0, 0);
                BattleScene_SetCameraOwnerStandardShot(arg0, D_84390200);
                BattleBox_Open(7);
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 1:
            if (BattleScene_AdvanceCameraFrameCounter(0x37) != 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }

        case 2:
            if (BattleScene_AdvanceCameraFrameCounter(0x3C) != 0) {
                BattleScene_UpdateDisplayedHpAndTransition(arg0);
            }
            break;
    }
}

void BattleScene_PhaseAttackHitRecoil(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp24 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;
    BattleMonRuntime* sp20 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654.unk_38;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_CleanupParticipantEffectMode(D_84390204);
            BattleAnim_CleanupEffects(2);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            if (BattleScene_AdvanceOwnerAnimation(D_84390010[gBattleScene.unk_00->unk_2C]) == 0) {
                Battle_ResetModelToIdleAnim(D_84390204);
                Audio_FadeAndClearStoredSounds();
                BattleAnim_CleanupEffects(1);
                BattleScene_SetCameraOwnerStandardShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
                BattleScene_EnterStateRow(D_84390010[gBattleScene.unk_00->unk_2C], 0xD);

                if (sp24->unk_15 & 0x18) {
                    BattleBox_Open(4);
                    sp24->unk_0C = sp24->unk_0E;
                    sp20->unk_0C = sp20->unk_0E;
                    if (sp24->unk_15 & 0x10) {
                        BattleAnim_QueueEffectList(6, D_84390204);
                    } else {
                        BattleAnim_QueueEffectList(5, D_84390204);
                    }
                    gBattleScene.unk_00->unk_20 += 1;
                } else {
                    BattleBox_Open(5);
                    sp24->unk_0C = sp24->unk_10;
                    sp20->unk_0C = sp20->unk_10;
                    BattleAnim_QueueEffectList(0xA, D_84390204);
                    gBattleScene.unk_00->unk_20 = 3;
                }
            }
            break;

        case 2:
            BattleScene_SetCameraOwnerStandardShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((D_84390220 == 1) && (D_84390224 == 1) && (BattleScene_AdvanceCameraFrameCounterUntil(0x32) != 0)) {
                BattleScene_ResetCameraFrameCounter();
                if (Battle_GetActiveMonHp(D_84390010[gBattleScene.unk_00->unk_2C]) == 0) {
                    BattleScene_ClearPhaseFlag();
                    BattleScene_SetPhase(arg0, 5);
                    gBattleScene.unk_00->unk_2C = !gBattleScene.unk_00->unk_2C;
                } else if (sp24->unk_4D & 0x80) {
                    Audio_PlayCommand(0x22, 0, 0);
                    sp24->unk_0C = sp24->unk_10;
                    sp20->unk_0C = sp20->unk_10;
                    BattleAnim_QueueEffectList(0xA, D_84390204);
                    gBattleScene.unk_00->unk_20 += 1;
                } else {
                    gBattleScene.unk_00->unk_20 = 4;
                }
            }
            break;

        case 3:
            BattleScene_SetCameraOwnerStandardShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            if ((BattleScene_AdvanceCameraFrameCounterUntil(0x32) != 0) && (D_84390220 == 1) && (D_84390224 == 1)) {
                gBattleScene.unk_00->unk_20 += 1;
                BattleScene_ResetCameraFrameCounter();
            }
            break;

        case 4:
            if (BattleScene_AdvanceOwnerAnimationAndClearFlags(D_84390200) == 0) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 5:
            BattleScene_ResetAnimationStep();
            BattleScene_SetCameraOwnerStandardShot(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[!gBattleScene.unk_00->unk_2C]);
            BattleScene_ResolveDisplayedHpCompletion(arg0);
            break;
    }
}

void BattleScene_PhaseCheckFaintedEndTurn(unk_D_86002F34_00C* arg0) {
    BattleMonRuntime* sp1C = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;
    BattleMonRuntime* sp18 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654.unk_38;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_CleanupParticipantEffectMode(D_84390204);
            BattleAnim_CleanupEffects(2);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 1:
            Battle_ResetModelToIdleAnim(D_84390204);
            Audio_FadeAndClearStoredSounds();
            BattleAnim_CleanupEffects(1);
            BattleScene_CameraShotTargetClose(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
            BattleScene_EnterStateRow(D_84390010[gBattleScene.unk_00->unk_2C], 0xD);
            sp1C->unk_0C = sp1C->unk_0E;
            sp18->unk_0C = sp18->unk_0E;
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 2:
            BattleScene_CameraShotTargetClose(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390220 = BattleScene_AnimateDisplayedHpToRuntime(D_84390010[gBattleScene.unk_00->unk_2C]);
            D_84390224 = 1;

            if ((D_84390220 == 1) && (D_84390224 == 1) && (BattleScene_AdvanceCameraFrameCounterUntil(0x32) != 0)) {
                BattleScene_ResetCameraFrameCounter();
                if (Battle_GetActiveMonHp(D_84390010[gBattleScene.unk_00->unk_2C]) == 0) {
                    BattleScene_ClearPhaseFlag();
                    BattleScene_SetPhase(arg0, 0x22);
                    gBattleScene.unk_00->unk_2C = !gBattleScene.unk_00->unk_2C;
                } else {
                    BattleScene_CleanupActionAndAdvance();
                }
            }
            break;
    }
}

void BattleScene_ClearMonStatusAnimations(Battler* arg0) {
    BattleAnim_ClearFreezeStatusAnimation(arg0);
    BattleAnim_ClearSleepStatusAnimation(arg0);
}

void BattleScene_PhaseWithdrawFainted(unk_D_86002F34_00C* arg0) {
    BattlerState* sp34 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;
    Battler* temp_s0 = D_84390010[gBattleScene.unk_00->unk_2C];
    BattleMonRuntime* sp2C = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;

    if (gBattleScene.unk_00->unk_2C) {}

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            if (gBattleScene.unk_00->unk_34 == 1) {
                BattleScene_ResetCameraFov(arg0);
                BattleScene_SelectCameraFollowPreset(temp_s0, arg0, 4);
                func_8003F4C0(BattleScene_GetParticipantDisplayPlayerNumber(temp_s0));
                gBattleScene.unk_00->unk_20 += 1;
            } else if (BattleScene_AnimateCameraPreset(arg0, temp_s0, 1, 1) != 0) {
                BattleBox_Open(0xA);
                func_8003F4C0(BattleScene_GetParticipantDisplayPlayerNumber(temp_s0));
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 1:
            BattleScene_ApproachCameraZoom(arg0, temp_s0);
            BattleScene_EnterStateRow(temp_s0, 2);
            BattleScene_ClearMonStatusAnimations(temp_s0);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 2:
            BattleScene_ApproachCameraZoom(arg0, temp_s0);
            if (BattleScene_AdvanceCameraFrameCounter(0x69) != 0) {
                Vec3f_SetComponentsDuplicate(&arg0->unk_60.at, temp_s0->unk_4B0 * -150.0f, 0.0, 0.0f);
                if (gBattleScene.unk_00 && gBattleScene.unk_00) {}
                Vec3f_SetComponentsDuplicate(&arg0->unk_60.eye, temp_s0->unk_4B0 * -50.0f, 5.0f, 0.0f);
                BattleScene_SetParticipantModelFlags(temp_s0, 2, 0);
                BattleAnim_QueueEffectList3(0xD, temp_s0, temp_s0, 0xFF, 0xFF);
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            if (temp_s0->unk_4EC.position.y == 2.5f) {
                temp_s0->unk_4EC.node.renderFlags |= 0x20;
            }

            if (ModelAnim_IsAnimationDone(&temp_s0->unk_4EC) == 1) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 4:
            temp_s0->unk_4EC.node.flags &= ~1;
            temp_s0->unk_720->unk_04 = &temp_s0->unk_720->unk_08[sp34->unk_2C]->unk_01C[sp34->unk_18];
            temp_s0->unk_720->unk_00 |= 0x80;
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 5:
            if (temp_s0->unk_720->unk_00 & 0x10) {
                temp_s0->unk_720->unk_00 &= ~0x90;
                Battle_LoadOwnerModelForSwitchIn(temp_s0);
                BattleScene_TickOwnerCameraFraming(temp_s0);
                D_843900A8[gBattleScene.unk_00->unk_2C] = temp_s0->unk_654.unk_38.unk_0C;
                BattleAnim_QueueEffectList3(3, temp_s0, temp_s0, 0xFF, 0xFF);
                Audio_PlayCommand(2, 0, 0);
                BattleScene_RebindParticipantToSide(temp_s0, sp34->unk_2C);
                arg0->unk_24.fovy = 40.0f;
                BattleBox_Open(0xC);
                Battle_TriggerTrainerPresentationCue(temp_s0);
                gBattleDamage = 0;
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 6:
            BattleScene_EnterStateRow(temp_s0, 0x12);
            BattleScene_SelectCameraFollowPreset(temp_s0, arg0, 3);
            BattleScene_ResetCameraFrameCounter();
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 7:
            BattleScene_ReframeAndRecomputeDistanceForSwitch(arg0, temp_s0);
            if (BattleScene_IsRowWaitCompleteWithEventCount(temp_s0, 0x3C) != 0) {
                Audio_FadeAndClearStoredSounds();
                BattleAnim_CleanupEffects(2);
                BattleScene_ResetCameraFrameCounter();
                Vec3f_SetComponentsDuplicate(&temp_s0->unk_000.scale, 1.0f, 1.0f, 1.0f);
                if (sp2C->unk_5A == 0xFE) {
                    sp2C->unk_5A = 0xA5;
                }
                BattleScene_CleanupActionAndAdvance();
                sp34->unk_34 &= ~0x1800;
                BattleBox_Close();
                gBattleScene.unk_00->unk_54 = !gBattleScene.unk_00->unk_2C + 1;
            }
            break;
    }
}

void BattleScene_PhaseWithdrawSwitch(unk_D_86002F34_00C* arg0) {
    BattlerState* sp3C = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;
    BattlerState* sp38 = &D_84390010[!gBattleScene.unk_00->unk_2C]->unk_654;
    UNUSED s32 pad;
    Battler* temp_s0 = D_84390010[gBattleScene.unk_00->unk_2C];
    BattleMonRuntime* sp2C = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654.unk_38;

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            if (gBattleScene.unk_00->unk_34 == 1) {
                BattleScene_ResetCameraFov(arg0);
                BattleScene_ResetCameraFrameCounter();
                BattleBox_Open(0xB);
                BattleAnim_LoadModeResourceList(temp_s0->unk_720, 3);
                Vec3f_SetComponentsDuplicate(&arg0->unk_60.at, temp_s0->unk_4B0 * -150.0f, 0.0, 0.0f);
                Vec3f_SetComponentsDuplicate(&arg0->unk_60.eye, temp_s0->unk_4B0 * -50.0f, 5.0f, 0.0f);
                Vec3f_SetComponentsDuplicate(&temp_s0->unk_000.position, temp_s0->unk_4B0 * -150.0f, 25.0f, 0.0f);
                gBattleScene.unk_00->unk_20 += 1;
            } else {
                BattleAnim_ApproachF(&arg0->unk_24.fovy, 30.0f, 0.05f);
                if (BattleScene_AnimateCameraIntro(arg0, temp_s0) != 0) {
                    BattleScene_ResetCameraFov(arg0);
                    BattleScene_ResetCameraFrameCounter();
                    BattleBox_Open(0xB);
                    BattleAnim_LoadModeResourceList(temp_s0->unk_720, 3);
                    gBattleScene.unk_00->unk_20 += 1;
                }
            }
            break;

        case 1:
            if (BattleAnim_TryRegisterAssetTables(temp_s0) != 0) {
                temp_s0->unk_720->unk_02 = sp2C->unk_0B;
                BattleScene_SetParticipantModelFlags(temp_s0, 2, 0);
                BattleAnim_QueueEffectList3(0xD, temp_s0, temp_s0, 0xFF, 0xFF);
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 2:
            if (temp_s0->unk_4EC.position.y == 2.5f) {
                temp_s0->unk_4EC.node.renderFlags |= 0x20;
            }

            if (ModelAnim_IsAnimationDone(&temp_s0->unk_4EC) == 1) {
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 3:
            temp_s0->unk_4EC.node.flags &= ~1;
            temp_s0->unk_720->unk_00 |= 0x80;
            temp_s0->unk_720->unk_04 = &temp_s0->unk_720->unk_08[sp3C->unk_2C]->unk_01C[sp3C->unk_18];
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 4:
            if (temp_s0->unk_720->unk_00 & 0x10) {
                temp_s0->unk_720->unk_00 &= ~0x90;
                Battle_LoadOwnerModelForSwitchIn(temp_s0);
                BattleScene_TickOwnerCameraFraming(temp_s0);
                D_843900A8[BattleScene_GetParticipantSideIndex(temp_s0)] = temp_s0->unk_654.unk_38.unk_0C;
                Audio_PlayCommand(2, 0, 0);
                BattleScene_RebindParticipantToSide(temp_s0, sp3C->unk_2C);
                BattleScene_ResetCameraFrameCounter();
                BattleAnim_QueueEffectList3(3, temp_s0, temp_s0, 0xFF, 0xFF);
                arg0->unk_24.fovy = 40.0f;
                Battle_TriggerTrainerPresentationCue(temp_s0);
                gBattleDamage = 0;
                gBattleScene.unk_00->unk_20 += 1;
            }
            break;

        case 5:
            BattleScene_EnterStateRow(temp_s0, 0x12);
            BattleScene_SelectCameraFollowPreset(temp_s0, arg0, 3);
            gBattleScene.unk_00->unk_20 += 1;
            break;

        case 6:
            BattleScene_ReframeAndRecomputeDistanceForSwitch(arg0, temp_s0);
            if (BattleScene_IsRowWaitCompleteWithEventCount(temp_s0, 0x3C) != 0) {
                if ((sp2C->unk_5A & 0xF0) == 0xF0) {
                    sp2C->unk_5A = 0xA5;
                }
                Audio_FadeAndClearStoredSounds();
                BattleAnim_CleanupEffects(2);
                BattleScene_ResetCameraFrameCounter();
                Vec3f_SetComponentsDuplicate(&temp_s0->unk_000.scale, 1.0f, 1.0f, 1.0f);
                if (sp38->unk_2D != 0x10) {
                    gBattleScene.unk_00->unk_34 = 3;
                }
                gBattleScene.unk_00->unk_2E = 2;
                BattleScene_CleanupActionAndAdvance();
                sp3C->unk_34 &= 0xE7FF;
                gBattleScene.unk_00->unk_54 = !gBattleScene.unk_00->unk_2C + 1;
            }
            break;
    }
}

void BattleScene_UpdatePhase(unk_D_86002F34_00C* arg0) {
    BattleScene_UpdateActiveOwnerPointers();

    switch (gBattleScene.unk_00->unk_38) {
        case 0:
            BattleScene_InitializeBattlePresentation(arg0);
            BattleScene_SetPhase(arg0, 1);

        case 1:
            BattleScene_PhaseIntro(arg0);
            break;
        case 2:
            BattleScene_Phase2(arg0);
            break;
        case 3:
            BattleScene_Phase3(arg0);
            break;
        case 4:
            BattleScene_Phase4(arg0);
            break;
        case 7:
            BattleScene_Phase7(arg0);
            break;
        case 38:
            BattleScene_Phase38(arg0);
            break;
        case 27:
            BattleScene_Phase27(arg0);
            break;
        case 30:
            BattleScene_Phase30(arg0);
            break;
        case 29:
            BattleScene_Phase29(arg0);
            break;
        case 28:
            BattleScene_Phase28(arg0);
            break;
        case 25:
            BattleScene_Phase25(arg0);
            break;
        case 12:
            BattleScene_Phase12(arg0);
            break;
        case 13:
            BattleScene_Phase13(arg0);
            break;
        case 14:
            BattleScene_Phase14(arg0);
            break;
        case 15:
            BattleScene_Phase15(arg0);
            break;
        case 17:
            BattleScene_Phase17(arg0);
            break;
        case 31:
            BattleScene_Phase31(arg0);
            break;
        case 20:
            BattleScene_PhaseFaint(arg0);
            break;
        case 8:
            BattleScene_PhaseMoveFailedMessage(arg0);
            break;
        case 10:
            BattleScene_Phase10(arg0);
            break;
        case 6:
            BattleScene_PhaseAttackHit(arg0);
            break;
        case 33:
            BattleScene_PhaseCheckFaintedEndTurn(arg0);
            break;
        case 35:
            BattleScene_PhaseAttackHitRecoil(arg0);
            break;
        case 9:
            BattleScene_PhaseDrainDamage(arg0);
            break;
        case 16:
            BattleScene_Phase16(arg0);
            break;
        case 11:
            BattleScene_PhaseWithdrawFainted(arg0);
            break;
        case 18:
            BattleScene_PhaseWithdrawSwitch(arg0);
            break;
        case 5:
            BattleScene_PhaseSendOut(arg0);
            break;
        case 34:
            BattleScene_PhaseSendOutAfterFaint(arg0);
            break;
        case 36:
            BattleScene_PhaseResumeSaved();
            break;
        case 37:
            BattleScene_PhaseSelectMoveAnim();
            break;
    }
}
