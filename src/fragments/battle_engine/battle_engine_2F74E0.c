#include "battle_engine.h"
#include "src/audio_commands.h"
#include "src/3D140.h"
#include "src/audio_sfx.h"
#include "src/audio_loop_point.h"

static f32 D_84390120;
f32 D_84390124;
f32 D_84390128;
static f32 D_8439012C;
static f32 D_84390130;
u8 D_84390134;
static s32 D_84390138;
static s32 D_8439013C;
static s32 pad_D_84390140;
static u16 D_84390144;
static Controller* D_84390148;
static Controller* D_8439014C;
static Controller D_84390150;
s32 D_84390174;
unk_D_84390178 D_84390178;

static u8 D_84385750[] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
};

void BattleScene_InitializePresentationTimers(void) {
    D_8439012C = D_800AE540.unk_11EF * 0x1E;
    D_84390130 = D_800AE540.unk_11EE * 0x708;
    D_84390128 = D_800AE540.unk_11EE * 0x708;
}

void BattleScene_QuantizePresentationTimer(void) {
    s32 tmp = (s32)(D_84390128 / 30.0f) * 0x1E;

    D_84390128 = tmp;
}

s32 BattleScene_TickPresentationTimer(void) {
    if (D_84390128 == 0.0f) {
        return 1;
    }

    D_84390128 -= 1.0f;
    return 0;
}

s32 BattleScene_IsPresentationCountdownComplete(void) {
    if (D_800AE540.unk_11ED == 0) {
        return 0;
    }

    if ((((s32)D_84390128 % 30) == 0) && (D_84390128 != 0.0f)) {
        Audio_PlayCommand(0x3E, 0, 0);
    }

    if (D_84390128 == 0.0f) {
        return 1;
    }
    return 0;
}

s32 Battle_ClassifyHpTier(s32 arg0, s32 arg1) {
    s32 temp_v0 = arg0 * 0x30;

    if (temp_v0 < (arg1 * 0xA)) {
        return 1;
    }

    if (temp_v0 < (arg1 * 0x1B)) {
        return 2;
    }

    return 3;
}

s32 BattleScene_DetermineWinner(void) {
    BattleMon* ptr;
    s32 i;
    s32 var_s3 = 0;
    s32 var_s4 = 0;
    s32 var_s5 = 0;
    s32 var_s6 = 0;

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(D_84390010[0]); i++) {
        ptr = &D_84390010[0]->unk_724->unk_01C[i];
        if (ptr->unk_02 != 0) {
            var_s3++;
        }
    }

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(D_84390010[1]); i++) {
        ptr = &D_84390010[1]->unk_724->unk_01C[i];
        if (ptr->unk_02 != 0) {
            var_s4++;
        }
    }

    if (var_s3 != var_s4) {
        if (var_s4 < var_s3) {
            return 1;
        }
        return 2;
    }

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(D_84390010[0]); i++) {
        ptr = &D_84390010[0]->unk_724->unk_01C[i];
        var_s5 += Battle_ClassifyHpTier(ptr->unk_02, ptr->unk_26);
    }

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(D_84390010[1]); i++) {
        ptr = &D_84390010[1]->unk_724->unk_01C[i];
        var_s6 += Battle_ClassifyHpTier(ptr->unk_02, ptr->unk_26);
    }

    if (var_s5 == var_s6) {
        return 3;
    }

    if (var_s6 < var_s5) {
        return 1;
    }

    if (var_s5 < var_s6) {
        return 2;
    }
}

s32 BattleScene_UpdateResultPresentation(void) {
    s32 sp1C = 0;
    s32 var_v0;

    if (D_800AE540.unk_11ED == 0) {
        return 0;
    }

    if (BattleScene_IsPresentationCountdownComplete() != 0) {
        switch (D_84390134) {
            case 1:
                BattleBox_Open(0xD);
                D_84390134 = 2;
                Audio_PlayCommand(0x3F, 0, 0);
                Audio_StartResultMusicSequence();
                sp1C = 1;
                break;

            case 2:
                sp1C = 1;

                var_v0 = 0;
                if (D_84390120 >= 120.0f) {
                    var_v0 = 1;
                }

                D_84390120 += 1.0f;

                if (var_v0 != 0) {
                    gBattleScene.unk_00->unk_40 = BattleScene_DetermineWinner();
                    Audio_FadeOutAll(0x14);
                }
                break;
        }
    }
    return sp1C;
}

s32 BattleScene_IsActionSelectionTimerExpired(void) {
    if (D_800AE540.unk_11ED == 0) {
        return 0;
    }

    if (D_84390124 == 329.0f) {
        Audio_PlayCommand(0x3C, 0, 0);
    }

    if (D_84390124 == 91.0f) {
        Audio_PlayCommand(0x3D, 3, 0);
    }

    if (D_84390124 == 61.0f) {
        Audio_PlayCommand(0x3D, 2, 0);
    }

    if (D_84390124 == 31.0f) {
        Audio_PlayCommand(0x3D, 1, 0);
    }

    if (D_84390124 == 1.0f) {
        Audio_PlayCommand(0x3D, 0, 0);
    }

    if (D_84390124 == 0.0f) {
        return 1;
    }
    return 0;
}

void BattleScene_ResetActionSelectionTimer(void) {
    D_84390124 = D_800AE540.unk_11EF * 0x1E;
}

s32 BattleScene_TickActionSelectionTimers(void) {
    if (D_84390124 > 0.0f) {
        D_84390124 -= 1.0f;
    }

    if (D_84390120 >= 150.0f) {
        return 1;
    }

    D_84390120 += 1.0f;
    return 0;
}

void BattleScene_ResetActionSelectionTimers(void) {
    D_84390120 = 0.0f;
    BattleScene_ResetActionSelectionTimer();
}

s32 BattleScene_ApplyForcedActionDelay(Battler* arg0) {
    BattlerState* temp_v1 = &arg0->unk_654;

    if (arg0->unk_654.unk_10 == 3) {
        temp_v1->unk_1E += 0x38E;
        return 1;
    }
    return 0;
}

void BattleScene_SyncActiveHpToPartyState(void) {
    BattleMonRuntime* temp_a2;
    BattleMonRuntime* temp_a3;
    BattlerState* ptr1;
    BattlerState* ptr2;
    BattleMon* ptr3;
    BattleMon* ptr4;

    ptr1 = &D_84390010[0]->unk_654;
    ptr2 = &D_84390010[1]->unk_654;
    temp_a2 = &D_84390010[0]->unk_654.unk_38;
    temp_a3 = &D_84390010[1]->unk_654.unk_38;

    ptr3 = &D_84390010[0]->unk_724->unk_01C[ptr1->unk_08];
    ptr4 = &D_84390010[1]->unk_724->unk_01C[ptr2->unk_08];

    if (D_84390288 != 0) {
        D_843900A8[0] = temp_a2->unk_0C = temp_a2->unk_28;
        D_843900A8[1] = temp_a3->unk_0C = temp_a3->unk_28;

        ptr3->unk_02 = temp_a2->unk_28;
        ptr4->unk_02 = temp_a3->unk_28;
    }
}

s32 BattleScene_SelectFallbackWhenNoUsableMoves(Battler* arg0) {
    s32 i;
    s32 var_v1;
    BattlerState* temp_v1;
    BattleMonRuntime* temp_v0;

    temp_v1 = &arg0->unk_654;
    temp_v0 = &arg0->unk_654.unk_38;
    var_v1 = 0;

    if (arg0->unk_654.unk_38.unk_52 != 0) {
        for (i = 0; i < 4; i++) {
            if (((temp_v0->unk_52 >> 4) != i) && (temp_v0->unk_1F[i] != 0)) {
                var_v1 |= temp_v0->unk_32[i] & 0x3F;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (temp_v0->unk_1F[i] != 0) {
                var_v1 |= temp_v0->unk_32[i] & 0x3F;
            }
        }
    }

    if (var_v1 == 0) {
        temp_v1->unk_1E = 0;
        temp_v1->unk_10 = 3;
        temp_v1->unk_14 = 4;
        return 1;
    }
    return 0;
}

s32 BattleScene_IsMoveUnavailable(Battler* arg0, s32 arg1) {
    BattleMonRuntime* ptr = &arg0->unk_654.unk_38;

    if (!(ptr->unk_32[arg1] & 0x3F)) {
        return 1;
    }

    if ((ptr->unk_52 & 0xF) && (arg1 == (ptr->unk_52 >> 4))) {
        return 1;
    }

    return 0;
}

void BattleScene_AutoSelectAvailableMove(Battler* arg0) {
    s32 i;
    BattlerState* temp_v0 = &arg0->unk_654;

    if (BattleScene_SelectFallbackWhenNoUsableMoves(arg0) == 0) {
        for (i = 0; i < 4; i++) {
            if (BattleScene_IsMoveUnavailable(arg0, i) == 0) {
                temp_v0->unk_04 = 1;
                temp_v0->unk_10 = 3;
                temp_v0->unk_14 = i;
                temp_v0->unk_0C = i;
                break;
            }
        }
    }
}

void BattleScene_AutoSelectReplacementMon(Battler* arg0) {
    s32 i;
    BattlerState* sp1C = &arg0->unk_654;

    for (i = 0; i < arg0->unk_720->unk_08[0]->unk_002; i++) {
        if ((arg0->unk_720->unk_08[0]->unk_01C[i].unk_02 != 0) && (i != sp1C->unk_08)) {
            BattleAnim_PlaySoundEffect2();
            sp1C->unk_1C = 0;
            sp1C->unk_1E = 0;
            sp1C->unk_10 = 3;
            sp1C->unk_18 = i;
            return;
        }
    }

    BattleScene_AutoSelectAvailableMove(arg0);
}

void BattleScene_SelectActiveController(Battler* arg0) {
    BattlerState* ptr = &arg0->unk_654;

    ptr->unk_2C = ptr->unk_2B;
    ptr->unk_C8 = &gControllers[arg0->unk_720->unk_08[ptr->unk_2C]->unk_001];
}

void BattleScene_HandleActionSelectionCancel(s32 arg0) {
    BattlerState* sp2C;
    BattlerState* sp28;
    UNUSED s32 pad;
    Controller* cont;

    sp2C = &D_84390010[arg0]->unk_654;
    sp28 = &D_84390010[arg0 == 0]->unk_654;
    cont = sp2C->unk_C8;

    if ((sp2C->unk_10 != 3) || !(cont->buttonPressed & 0x20)) {
        return;
    }

    if (sp2C->unk_2D == 0x10) {
        if (sp2C->unk_04 == 2) {
            BattleScene_SelectActiveController(D_84390010[arg0]);
        }
        BattleAnim_PlaySoundEffect3();
        sp2C->unk_10 = 2;
    }

    if (sp28->unk_2D != 0x10) {
        if (sp2C->unk_04 == 2) {
            BattleScene_SelectActiveController(D_84390010[arg0]);
        }
        BattleAnim_PlaySoundEffect3();
        sp2C->unk_10 = 0;
    }
}

void Battle_InitializeActiveRuntimeState(void) {
    BattleScene_InitializePresentationTimers();
    func_84370B7C(D_84390010[0]);
    func_84370B7C(D_84390010[1]);

    D_843900A8[0] = D_84390010[0]->unk_654.unk_38.unk_0C;
    D_843900A8[1] = D_84390010[1]->unk_654.unk_38.unk_0C;

    Battle_ResetTransientRuntimeState(0, 1);
    Battle_ResetTransientRuntimeState(1, 0);
}

s32 BattleScene_CpuHasNoUsableMoves(Battler* arg0) {
    BattleMonRuntime* temp_v0 = &arg0->unk_654.unk_38;
    s32 i;
    s32 var_v1 = 0;

    if (temp_v0->unk_52 != 0) {
        for (i = 0; i < 4; i++) {
            if (((temp_v0->unk_52 >> 4) != i) && (temp_v0->unk_1F[i] != 0)) {
                var_v1 |= temp_v0->unk_32[i] & 0x3F;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (temp_v0->unk_1F[i] != 0) {
                var_v1 |= temp_v0->unk_32[i] & 0x3F;
            }
        }
    }

    if (var_v1 == 0) {
        return 1;
    }
    return 0;
}

s32 BattleScene_WaitForCpuChoice(Battler* arg0, Battler* arg1) {
    UNUSED s32 pad[2];
    BattlerState* sp1C = &arg0->unk_654;
    BattlerState* temp_v0 = &arg1->unk_654;

    if ((arg0->unk_654.unk_2D == 0x10) && (arg1->unk_654.unk_2D == 0x10)) {
        if (sp1C->unk_10 == 3) {
            BattleScene_ApplyForcedActionDelay(arg0);
            return 1;
        }

        sp1C->unk_04 = 2;
        sp1C->unk_10 = 2;

        if (D_84390120 == 20.0f) {
            BattleAnim_PlaySoundEffect2();
            D_84390138 = BattleAI_ChooseAction(0);
            sp1C->unk_1C = 0;
            sp1C->unk_18 = D_84390138 - 4;
            sp1C->unk_1E = 0;
            sp1C->unk_10 = 3;
            sp1C->unk_04 = 2;
        }
        return 1;
    }

    if (sp1C->unk_2D == 0x10) {
        sp1C->unk_04 = 2;
        sp1C->unk_10 = 2;
        temp_v0->unk_10 = 3;
        temp_v0->unk_04 = 1;

        if (D_84390120 == 20.0f) {
            BattleAnim_PlaySoundEffect2();
            D_84390138 = BattleAI_ChooseAction(0);
            sp1C->unk_1C = 0;
            sp1C->unk_18 = D_84390138 - 4;
            sp1C->unk_1E = 0;
            sp1C->unk_10 = 3;
            sp1C->unk_04 = 2;
        }
        return 1;
    }

    return 0;
}

void BattleScene_CompleteCpuForcedAction(Battler* arg0, UNUSED Battler* arg1) {
    BattlerState* ptr = &arg0->unk_654;

    BattleScene_ApplyForcedActionDelay(arg0);
    ptr->unk_2A = 1;
    ptr->unk_04 = 1;
    ptr->unk_0C = ptr->unk_14;
    ptr->unk_10 = 3;
}

void BattleScene_CompleteCpuMoveAction(Battler* arg0, Battler* arg1) {
    BattlerState* sp20 = &arg1->unk_654;
    BattlerState* sp1C = &arg0->unk_654;

    BattleScene_ApplyForcedActionDelay(arg0);
    sp1C->unk_2A = 1;

    if ((D_84390120 == 30.0f) && (D_84390138 < 4)) {
        BattleAnim_PlaySoundEffect2();
    }

    if ((D_84390138 < 4) && (D_84390120 >= 30.0f)) {
        sp1C->unk_10 = 1;
        sp1C->unk_04 = 1;
    }

    if (((D_84390120 >= 90.0f) || ((sp20->unk_10 == 3) && (D_84390120 >= 10.0f))) && (D_84390138 < 4)) {
        BattleAnim_PlaySoundEffect2();
        sp1C->unk_04 = 1;
        sp1C->unk_10 = 3;
        sp1C->unk_0C = sp1C->unk_14;
    }
}

void BattleScene_ApplyCpuChoice(Battler* arg0, Battler* arg1) {
    BattlerState* sp18;
    BattlerState* sp14;
    s32 var_v0;

    sp18 = &arg0->unk_654;
    sp14 = &arg1->unk_654;

    if ((D_84390120 == 30.0f) && (D_84390138 < 4)) {
        BattleAnim_PlaySoundEffect2();
    }

    if (D_84390138 < 4) {
        if (D_84390120 >= 30.0f) {
            sp18->unk_10 = 1;
            sp18->unk_04 = 1;
        }
    }

    if ((D_84390120 >= 90.0f) || ((sp14->unk_10 == 3) && (D_84390120 >= 10.0f))) {
        if (D_84390138 < 4) {
            BattleAnim_PlaySoundEffect2();
            sp18->unk_04 = 1;
            sp18->unk_10 = 3;
            if (BattleScene_CpuHasNoUsableMoves(arg0) != 0) {
                sp18->unk_14 = 4;
                sp18->unk_0C = 4;
            } else {
                var_v0 = D_84390138;
                sp18->unk_14 = var_v0;
                sp18->unk_0C = var_v0;
            }
        }
    }
}

s32 BattleScene_ApplyCpuSwitchChoice(Battler* arg0, Battler* arg1) {
    BattlerState* sp1C = &arg0->unk_654;
    BattlerState* sp18 = &arg1->unk_654;

    if ((D_84390120 == 30.0f) && (D_84390138 >= 4)) {
        BattleAnim_PlaySoundEffect2();
    }

    if (D_84390120 >= 30.0f) {
        if (D_84390138 >= 4) {
            sp1C->unk_10 = 2;
            sp1C->unk_04 = 2;
        }
    }

    if ((D_84390120 >= 90.0f) || ((sp18->unk_10 == 3) && (D_84390120 >= 10.0f))) {
        if (D_84390138 >= 4) {
            BattleAnim_PlaySoundEffect2();
            sp1C->unk_1C = 0;
            sp1C->unk_18 = D_84390138 - 4;
            sp1C->unk_1E = 0;
            sp1C->unk_10 = 3;
            sp1C->unk_04 = 2;
        }
    }

    if (D_84390138 >= 4) {
        return 1;
    }
    return 0;
}

void BattleScene_TriggerCpuChoice(UNUSED BattleMonRuntime* arg0, UNUSED BattleMonRuntime* arg1, UNUSED BattlerState* arg2,
                   UNUSED BattlerState* arg3, UNUSED Battler* arg4) {
    if ((D_84390120 == 1.0f) && (D_8439013C == 0)) {
        D_8439013C = 1;
        D_84390138 = BattleAI_ChooseAction(0);
    }
}

s32 BattleScene_CollectCpuAction(Battler* arg0, Battler* arg1) {
    BattleMonRuntime* sp34 = &arg0->unk_654.unk_38;
    BattleMonRuntime* sp30 = &arg1->unk_654.unk_38;
    BattlerState* sp2C = &arg0->unk_654;
    BattlerState* sp28 = &arg1->unk_654;

    if (BattleScene_WaitForCpuChoice(arg0, arg1) != 0) {
        return 0;
    }

    if (!(sp34->unk_4D & 0x60)) {
        sp34->unk_4C &= ~8;
        sp30->unk_4C &= ~8;

        if (!(sp34->unk_4C & 0x12)) {
            if (BattleScene_ApplyForcedActionDelay(arg0) != 0) {
                return 0;
            }

            if (D_84390120 == 0.0f) {
                D_8439013C = 0;
                return 0;
            }

            BattleScene_TriggerCpuChoice(sp34, sp30, sp2C, sp28, arg1);

            if (BattleScene_ApplyCpuSwitchChoice(arg0, arg1) != 0) {
                return 0;
            }

            if (!(sp34->unk_15 & 0x27)) {
                if (!(sp34->unk_4C & 0x21)) {
                    if (sp30->unk_4C & 0x20) {
                        BattleScene_CompleteCpuMoveAction(arg0, arg1);
                        sp34->unk_5A = 0xFF;
                    } else if (BattleScene_ApplyForcedActionDelay(arg0) != 0) {
                        return 0;
                    } else {
                        if (D_84390120 == 0.0f) {
                            D_8439013C = 0;
                            return 0;
                        }
                        BattleScene_TriggerCpuChoice(sp34, sp30, sp2C, sp28, arg1);
                        BattleScene_ApplyCpuChoice(arg0, arg1);
                    }
                } else {
                    BattleScene_CompleteCpuMoveAction(arg0, arg1);
                }
            } else {
                BattleScene_CompleteCpuMoveAction(arg0, arg1);
            }
        } else {
            BattleScene_CompleteCpuForcedAction(arg0, arg1);
        }
    } else {
        BattleScene_CompleteCpuForcedAction(arg0, arg1);
    }

    return 0;
}

void BattleScene_ForfeitPrompt(Battler* arg0) {
    BattlerState* sp18 = &arg0->unk_654;
    BattlerState* temp_a0 = &D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_654;

    if (arg0->unk_720->unk_01 == 1) {
        D_84390148 = &gControllers[arg0->unk_720->unk_08[0]->unk_001];
        D_8439014C = &gControllers[arg0->unk_720->unk_08[0]->unk_001];
    } else {
        D_84390148 = &gControllers[arg0->unk_720->unk_08[0]->unk_001];
        D_8439014C = &gControllers[arg0->unk_720->unk_08[1]->unk_001];
    }

    if (temp_a0->unk_10 == 4) {
        sp18->unk_10 = 0;
        sp18->unk_04 = 0;
        return;
    }

    if (sp18->unk_10 != 4) {
        sp18->unk_2F = 0;
    }

    sp18->unk_10 = 4;

    if ((gBattleScene.unk_00->unk_40 == 0) &&
        (BTN_IS_PRESSED(D_84390148, BTN_DLEFT) || BTN_IS_PRESSED(D_8439014C, BTN_DLEFT))) {
        sp18->unk_2F = 0;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    if ((gBattleScene.unk_00->unk_40 == 0) &&
        (BTN_IS_PRESSED(D_84390148, BTN_DRIGHT) || BTN_IS_PRESSED(D_8439014C, BTN_DRIGHT))) {
        sp18->unk_2F = 1;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    if ((sp18->unk_2F == 1) && (BTN_IS_PRESSED(D_84390148, BTN_A) || BTN_IS_PRESSED(D_8439014C, BTN_A)) &&
        (gBattleScene.unk_00->unk_40 == 0)) {
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        gBattleScene.unk_00->unk_40 = (BattleScene_GetParticipantSideIndex(arg0) == 0) + 1;
        Audio_FadeOutAll(0x14);
    } else if ((sp18->unk_2F == 0) && (BTN_IS_PRESSED(D_84390148, BTN_A) || BTN_IS_PRESSED(D_8439014C, BTN_A))) {
        sp18->unk_10 = 0;
        sp18->unk_04 = 0;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
}

void BattleScene_CommitPlayerSwitchAction(Battler* arg0) {
    BattlerState* temp_v0 = &arg0->unk_654;
    BattleMonRuntime* temp_v1 = &D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_654.unk_38;

    if (temp_v1->unk_4C & 0x20) {
        arg0->unk_654.unk_38.unk_5A = 0xFF;
    }

    if (temp_v0->unk_2D != 0x10) {
        temp_v0->unk_2D = 0xF;
    }

    temp_v0->unk_1C = 0;
    BattleScene_ClearParticipantMessageBuffer(arg0);
}

s32 BattleScene_ValidateSelectedPartyMember(Battler* arg0) {
    if (arg0->unk_720->unk_08[arg0->unk_654.unk_2C]->unk_01C[arg0->unk_654.unk_18].unk_02 != 0) {
        return 1;
    }

    BattleScene_ClearParticipantMessageBuffer(arg0);
    BattleScene_BuildParticipantMessage(arg0, 3);
    BattleAnim_PlaySoundEffect8();
    return 0;
}

void BattleScene_QueuePartySelectionConfirmMessage(Battler* arg0) {
    BattleScene_ClearParticipantMessageBuffer(arg0);
    BattleScene_BuildParticipantMessage(arg0, 4);
}

void BattleScene_AssignActiveCoopController(Battler* arg0, s32 arg1) {
    if (arg1 == 1) {
        D_84390148 = &gControllers[arg0->unk_720->unk_08[0]->unk_001];
        D_8439014C = &gControllers[arg0->unk_720->unk_08[0]->unk_001];
    } else {
        D_84390148 = &gControllers[arg0->unk_720->unk_08[0]->unk_001];
        D_8439014C = &gControllers[arg0->unk_720->unk_08[1]->unk_001];
    }

    if (arg1 == 1) {
        if (BTN_IS_PRESSED(D_84390148, BTN_A | BTN_B | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
            arg0->unk_654.unk_2C = 0;
            BattleScene_SetParticipantController(arg0, D_84390148);
        } else if (BTN_IS_PRESSED(D_8439014C, BTN_A | BTN_B | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
            BattleScene_SetParticipantController(arg0, D_8439014C);
            arg0->unk_654.unk_2C = 0;
        }
    } else if (BTN_IS_PRESSED(D_84390148, BTN_A | BTN_B | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
        BattleScene_SetParticipantController(arg0, D_84390148);
        arg0->unk_654.unk_2C = 0;
    } else if (BTN_IS_PRESSED(D_8439014C, BTN_A | BTN_B | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
        BattleScene_SetParticipantController(arg0, D_8439014C);
        arg0->unk_654.unk_2C = 1;
    }
}

void BattleScene_HandlePartySlotCursorInput(Battler* arg0, Controller* arg1) {
    BattlerState* sp1C;
    TeamRoster* temp_a1;

    sp1C = &arg0->unk_654;

    BattleScene_AssignActiveCoopController(arg0, arg0->unk_720->unk_01);
    temp_a1 = arg0->unk_720->unk_08[sp1C->unk_2C];
    arg1 = sp1C->unk_C8;

    if (temp_a1->unk_002 < 4) {
        if (BTN_IS_PRESSED(arg1, BTN_CUP)) {
            sp1C->unk_18 = 0;
        } else if (BTN_IS_PRESSED(arg1, BTN_CRIGHT)) {
            sp1C->unk_18 = 1;
        } else if (BTN_IS_PRESSED(arg1, BTN_CDOWN)) {
            sp1C->unk_18 = 2;
        } else {
            return;
        }
    } else {
        if (BTN_IS_PRESSED(arg1, BTN_CUP)) {
            sp1C->unk_18 = 0;
        }

        if (BTN_IS_PRESSED(arg1, BTN_CLEFT)) {
            sp1C->unk_18 = 1;
        }

        if (BTN_IS_PRESSED(arg1, BTN_B)) {
            sp1C->unk_18 = 2;
        }

        if (BTN_IS_PRESSED(arg1, BTN_CRIGHT)) {
            sp1C->unk_18 = 3;
        }

        if (BTN_IS_PRESSED(arg1, BTN_CDOWN)) {
            sp1C->unk_18 = 4;
        }

        if (BTN_IS_PRESSED(arg1, BTN_A)) {
            sp1C->unk_18 = 5;
        }
    }

    if (BTN_IS_PRESSED(arg1, BTN_A | BTN_B | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
        if ((sp1C->unk_08 == sp1C->unk_18) && (sp1C->unk_2C == sp1C->unk_2B)) {
            if (BattleScene_ValidateSelectedPartyMember(arg0) != 0) {
                BattleAnim_PlaySoundEffect8();
                BattleScene_QueuePartySelectionConfirmMessage(arg0);
            }
        } else if (((temp_a1->unk_002 - 1) >= sp1C->unk_18) && (BattleScene_ValidateSelectedPartyMember(arg0) != 0)) {
            BattleAnim_PlaySoundEffect2();
            sp1C->unk_1C = 0;
            sp1C->unk_1E = 0;
            sp1C->unk_10 = 3;
        }
    }
}

void BattleScene_HandlePlayerPartySelection(Battler* arg0) {
    UNUSED s32 pad;
    s32 idx;
    BattlerState* sp18 = &arg0->unk_654;

    if (arg0->unk_720->unk_01 == 1) {
        D_84390148 = &gControllers[arg0->unk_720->unk_08[0]->unk_001];
        D_8439014C = &gControllers[arg0->unk_720->unk_08[0]->unk_001];
    } else {

        D_84390148 = &gControllers[arg0->unk_720->unk_08[sp18->unk_2C]->unk_001];
        idx = sp18->unk_2C == 0;
        D_8439014C = &gControllers[arg0->unk_720->unk_08[idx]->unk_001];
    }

    if (arg0->unk_8C4.unk_00 != 0) {
        if (sp18->unk_C8->buttonPressed & 0xE03F) {
            BattleScene_ClearParticipantMessageBuffer(arg0);
        }
    } else if (sp18->unk_10 == 0) {
        sp18->unk_10 = 2;
    } else if (((D_84390148->buttonPressed & 0x20) || (D_8439014C->buttonPressed & 0x20)) && (sp18->unk_2D != 0x10) &&
               !(D_84390148->buttonDown & 0x10) && !(D_8439014C->buttonDown & 0x10)) {
        BattleScene_SelectActiveController(arg0);
        BattleAnim_PlaySoundEffect3();
        sp18->unk_10 = 0;
    } else {
        sp18->unk_1C = 0;
        if ((D_84390148->buttonDown & 0x10) || (D_8439014C->buttonDown & 0x10)) {
            if ((D_84390148->buttonPressed & 0x10) || (D_8439014C->buttonPressed & 0x10)) {
                BattleAnim_PlaySoundEffect1();
            }
            sp18->unk_1C = 1;
        }
        BattleScene_HandlePartySlotCursorInput(arg0, sp18->unk_C8);
    }
}

void BattleScene_CommitSelectedMoveAction(Battler* arg0) {
    BattlerState* temp_v0 = &arg0->unk_654;
    BattleMonRuntime* temp_v1 = &arg0->unk_654.unk_38;

    if (arg0->unk_654.unk_14 != 4) {
        temp_v0->unk_0C = temp_v0->unk_14;
        if (temp_v0->unk_2A == 0) {
            temp_v1->unk_5A = temp_v1->unk_1F[temp_v0->unk_0C];
        }
    } else {
        if (temp_v1->unk_4C & 0x20) {
            temp_v0->unk_0C = temp_v0->unk_14;
        } else {
            temp_v0->unk_14 = 0;
            temp_v0->unk_0C = 0;
            temp_v1->unk_5A = 0xA5;
        }
    }

    temp_v0->unk_1C = 0;
    BattleScene_ClearParticipantMessageBuffer(arg0);
}

s32 BattleScene_HandleNoUsableMoveSelection(Battler* arg0) {
    s32 i;
    s32 temp_a1;
    s32 var_v1;
    BattlerState* temp_v0;
    BattleMonRuntime* temp_a0;
    Controller* cont;

    temp_v0 = &arg0->unk_654;
    temp_a0 = &arg0->unk_654.unk_38;
    cont = arg0->unk_654.unk_C8;
    var_v1 = 0;

    if (temp_a0->unk_52 != 0) {
        temp_a1 = temp_a0->unk_52 >> 4;
        for (i = 0; i < 4; i++) {
            if ((temp_a1 != i) && (temp_a0->unk_1F[i] != 0)) {
                var_v1 |= temp_a0->unk_32[i] & 0x3F;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (temp_a0->unk_1F[i] != 0) {
                var_v1 |= temp_a0->unk_32[i] & 0x3F;
            }
        }
    }

    if (var_v1 == 0) {
        if (arg0->unk_8C4.unk_00 == 0) {
            if (temp_v0->unk_10 == 0) {
                temp_v0->unk_10 = 1;
            }
            BattleScene_ClearParticipantMessageBuffer(arg0);
            BattleScene_BuildParticipantMessage(arg0, 0);
        } else if (cont->buttonPressed & 0x20) {
            BattleScene_ClearParticipantMessageBuffer(arg0);
            temp_v0->unk_10 = 0;
            BattleAnim_PlaySoundEffect3();
        } else if (cont->buttonPressed & 0x8000) {
            BattleScene_ClearParticipantMessageBuffer(arg0);
            temp_v0->unk_1E = 0;
            temp_v0->unk_10 = 3;
            temp_v0->unk_14 = 4;
        }
        return 1;
    }
    return 0;
}

s32 BattleScene_ValidateSelectedMove(Battler* arg0) {
    UNUSED s32 pad[2];
    BattlerState* sp24 = &arg0->unk_654;
    BattleMonRuntime* ptr = &arg0->unk_654.unk_38;

    if (!(ptr->unk_32[sp24->unk_14] & 0x3F)) {
        BattleAnim_PlaySoundEffect8();
        BattleScene_ClearParticipantMessageBuffer(arg0);
        BattleScene_BuildParticipantMessage(arg0, 1);
        return 1;
    }

    if ((ptr->unk_52 & 0xF) && (sp24->unk_14 == (ptr->unk_52 >> 4))) {
        BattleAnim_PlaySoundEffect8();
        BattleScene_ClearParticipantMessageBuffer(arg0);
        BattleScene_BuildParticipantMessage(arg0, 2);
        return 1;
    }

    BattleAnim_PlaySoundEffect2();
    sp24->unk_1E = 0;
    sp24->unk_10 = 3;
    sp24->unk_1C = 0;
    return 0;
}

void BattleScene_SelectMoveFromButtons(Battler* arg0) {
    Controller* cont = arg0->unk_654.unk_C8;

    if ((cont->buttonPressed & 8) != 0) {
        if ((arg0->unk_654.unk_38.unk_1F[0] != 0) && (arg0->unk_654.unk_38.unk_1F[0] < 0xA6)) {
            arg0->unk_654.unk_14 = 0;
            BattleScene_ValidateSelectedMove(arg0);
            return;
        }
    }

    if ((cont->buttonPressed & 1) != 0) {
        if ((arg0->unk_654.unk_38.unk_1F[1] != 0) && (arg0->unk_654.unk_38.unk_1F[1] < 0xA6)) {
            arg0->unk_654.unk_14 = 1;
            BattleScene_ValidateSelectedMove(arg0);
            return;
        }
    }

    if ((cont->buttonPressed & 4) != 0) {
        if ((arg0->unk_654.unk_38.unk_1F[2] != 0) && (arg0->unk_654.unk_38.unk_1F[2] < 0xA6)) {
            arg0->unk_654.unk_14 = 2;
            BattleScene_ValidateSelectedMove(arg0);
            return;
        }
    }

    if ((cont->buttonPressed & 2) != 0) {
        if ((arg0->unk_654.unk_38.unk_1F[3] != 0) && (arg0->unk_654.unk_38.unk_1F[3] < 0xA6)) {
            arg0->unk_654.unk_14 = 3;
            BattleScene_ValidateSelectedMove(arg0);
            return;
        }
    }

    if ((cont->buttonPressed & 8) || (cont->buttonPressed & 1) || (cont->buttonPressed & 4) ||
        (cont->buttonPressed & 2)) {
        BattleAnim_PlaySoundEffect8();
    }
}

void BattleScene_HandlePlayerMoveSelection(Battler* arg0) {
    UNUSED s32 pad[2];
    Controller* sp1C = arg0->unk_654.unk_C8;
    BattlerState* temp_v0 = &arg0->unk_654;

    if ((temp_v0->unk_04 == 1) && (BattleScene_HandleNoUsableMoveSelection(arg0) == 0)) {
        if (arg0->unk_8C4.unk_00 != 0) {
            if (BTN_IS_PRESSED(sp1C,
                               BTN_A | BTN_B | BTN_Z | BTN_L | BTN_R | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
                BattleScene_ClearParticipantMessageBuffer(arg0);
            }
        } else {
            if (temp_v0->unk_10 == 0) {
                temp_v0->unk_10 = 1;
            } else if (BTN_IS_PRESSED(sp1C, BTN_L) && !BTN_IS_DOWN(sp1C, BTN_R)) {
                temp_v0->unk_10 = 0;
                BattleAnim_PlaySoundEffect3();
            } else {
                temp_v0->unk_1C = 0;
                if (BTN_IS_DOWN(sp1C, BTN_R)) {
                    temp_v0->unk_1C = 1;
                }

                if (BTN_IS_PRESSED(sp1C, BTN_R)) {
                    BattleAnim_PlaySoundEffect1();
                }

                BattleScene_SelectMoveFromButtons(arg0);
            }
        }
    }
}

s32 BattleScene_HandlePlayerMoveSelectionLocked(Battler* arg0, UNUSED Controller* arg1) {
    arg0->unk_654.unk_2A = 1;
    BattleScene_HandlePlayerMoveSelection(arg0);
    arg0->unk_654.unk_2A = 1;
    return 0;
}

void BattleScene_ConfirmForcedMoveRepeat(Battler* arg0) {
    BattlerState* ptr = &arg0->unk_654;

    BattleScene_ApplyForcedActionDelay(arg0);
    ptr->unk_2A = 1;
    ptr->unk_10 = 3;
    ptr->unk_0C = ptr->unk_14;
}

void BattleScene_PollActionMenuRequestButtons(Battler* arg0) {
    BattlerState* temp_v1 = &arg0->unk_654;
    BattlerState* temp_t0 = &D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_654;

    if (temp_v1->unk_10 == 0) {
        if (arg0->unk_720->unk_01 == 1) {
            D_84390148 = &gControllers[arg0->unk_720->unk_08[0]->unk_001];
            D_8439014C = &gControllers[arg0->unk_720->unk_08[0]->unk_001];
        } else {
            D_84390148 = &gControllers[arg0->unk_720->unk_08[0]->unk_001];
            D_8439014C = &gControllers[arg0->unk_720->unk_08[1]->unk_001];
        }

        if (temp_v1->unk_C8->buttonPressed & 0x8000) {
            temp_v1->unk_04 = 1;
        } else if ((D_84390148->buttonPressed | D_8439014C->buttonPressed) & 0x4000) {
            temp_v1->unk_04 = 2;
        } else if ((D_84390148->buttonPressed | D_8439014C->buttonPressed) & 0x1000) {
            temp_v1->unk_04 = 3;
        } else {
            temp_v1->unk_04 = 0;
        }

        if ((temp_v1->unk_C8->buttonPressed & 0x8000) ||
            (((D_84390148->buttonPressed | D_8439014C->buttonPressed) & 0x4000) != 0) ||
            (((D_84390148->buttonPressed | D_8439014C->buttonPressed) & 0x1000) && (temp_t0->unk_10 != 4))) {
            BattleAnim_PlaySoundEffect2();
        }
    }
}

s32 BattleScene_HandlePlayerActionInput(Battler* arg0) {
    BattleScene_GetParticipantSideIndex(arg0);

    if (BattleScene_ApplyForcedActionDelay(arg0) != 0) {
        return 1;
    }

    if (BattleScene_IsActionSelectionTimerExpired() != 0) {
        if (arg0->unk_654.unk_04 == 2) {
            BattleScene_AutoSelectReplacementMon(arg0);
        } else {
            BattleScene_AutoSelectAvailableMove(arg0);
        }
        return 1;
    }

    BattleScene_PollActionMenuRequestButtons(arg0);

    switch (arg0->unk_654.unk_04) {
        case 2:
            BattleScene_HandlePlayerPartySelection(arg0);
            return 1;

        case 3:
            BattleScene_ForfeitPrompt(arg0);
            return 1;

        case 1:
            break;
    }
    return 0;
}

s32 BattleScene_HandlePlayerForcedActionState(Battler* arg0, Battler* arg1) {
    BattlerState* sp1C = &arg0->unk_654;
    BattlerState* temp_v0 = &arg1->unk_654;

    if ((sp1C->unk_2D == 0x10) && (temp_v0->unk_2D == 0x10)) {
        if (sp1C->unk_10 == 3) {
            BattleScene_ApplyForcedActionDelay(arg0);
            return 1;
        }

        if (BattleScene_IsActionSelectionTimerExpired() != 0) {
            BattleScene_AutoSelectReplacementMon(arg0);
            return 1;
        }

        sp1C->unk_04 = 2;
        sp1C->unk_10 = 2;
        BattleScene_HandlePlayerPartySelection(arg0);
        return 1;
    }

    if (sp1C->unk_2D == 0x10) {
        if (BattleScene_IsActionSelectionTimerExpired() != 0) {
            BattleScene_AutoSelectReplacementMon(arg0);
            return 1;
        }
        sp1C->unk_04 = 2;
        temp_v0->unk_04 = 1;
        sp1C->unk_10 = 2;
        temp_v0->unk_10 = 3;
        BattleScene_HandlePlayerPartySelection(arg0);
        return 1;
    }
    return 0;
}

void BattleScene_ShowParticipantOwnerAndSecondaryModels(void) {
    D_84390010[0]->unk_728.unk_168->node.flags |= 1;
    D_84390010[0]->unk_728.unk_000.node.flags |= 1;
    D_84390010[1]->unk_728.unk_168->node.flags |= 1;
    D_84390010[1]->unk_728.unk_000.node.flags |= 1;
}

void BattleScene_HideParticipantOwnerAndSecondaryModels(void) {
    D_84390010[0]->unk_728.unk_168->node.flags &= ~1;
    D_84390010[0]->unk_728.unk_000.node.flags &= ~1;
    D_84390010[1]->unk_728.unk_168->node.flags &= ~1;
    D_84390010[1]->unk_728.unk_000.node.flags &= ~1;
}

void BattleScene_AdvanceAttractInputScript(void) {
    static u16 D_84385758[][3] = {
        { 0x17C, 0, 0 },        { 0xA, BTN_L, 0 },  { 0xA, BTN_R, 0 }, { 0xC8, BTN_START, 0 },
        { 0xC8, BTN_START, 0 }, { 0xDC, BTN_A, 0 }, { 0, 0, 0 },
    };
    Controller* controller = &D_84390150;

    controller->buttonPressed = 0;

    if (D_84390178.unk_00 == 0) {
        D_84390178.unk_00 = D_84385758[D_84390174][0];
        if (D_84390178.unk_00 != 0) {
            controller->buttonPressed = D_84385758[D_84390174][1];
            controller->buttonDown = D_84385758[D_84390174][2];
            D_84390174++;
        }
    }

    if (D_84390178.unk_00 > 0) {
        D_84390178.unk_00--;
    }
}

void BattleScene_CheckForcedActionCondition(Battler* arg0, Battler* arg1) {
    BattleMonRuntime* temp_v0 = &arg0->unk_654.unk_38;
    BattleMonRuntime* temp_v1 = &arg1->unk_654.unk_38;

    if (!(arg0->unk_654.unk_38.unk_4D & 0x60)) {
        temp_v0->unk_4C &= ~8;
        temp_v1->unk_4C &= ~8;
        if (temp_v0->unk_4C & 0x12) {
            arg0->unk_654.unk_2A = 1;
        }
    } else {
        arg0->unk_654.unk_2A = 1;
    }
}

void BattleScene_TickAttractModeInput(void) {
    BattlerState* sp24 = &D_84390010[0]->unk_654;
    BattlerState* sp20 = &D_84390010[1]->unk_654;
    BattleMonRuntime* sp1C = &D_84390010[0]->unk_654.unk_38;
    BattleMonRuntime* sp18 = &D_84390010[1]->unk_654.unk_38;
    Controller* cont = &D_84390150;

    BattleScene_AdvanceAttractInputScript();
    BattleScene_CheckForcedActionCondition(D_84390010[0], D_84390010[1]);
    BattleScene_CheckForcedActionCondition(D_84390010[1], D_84390010[0]);

    if (cont->buttonPressed & 0x20) {
        BattleScene_ShowParticipantOwnerAndSecondaryModels();
        BattleScene_TriggerOwnerModelAnimation(D_84390010[0]);
        BattleScene_TriggerOwnerModelAnimation(D_84390010[1]);
    }

    if (cont->buttonPressed & 0x10) {
        BattleScene_HideParticipantOwnerAndSecondaryModels();
    }

    if (cont->buttonPressed & 0x1000) {
        sp24->unk_04 = 0;
        sp20->unk_04 = 0;

        if (sp24->unk_2A == 0) {
            sp1C->unk_5A = BattleAI_ResolveRandomMove(0, 0);
        }

        if (sp20->unk_2A == 0) {
            sp18->unk_5A = BattleAI_ResolveRandomMove(1, 0);
        }

        sp24->unk_10 = 3;
        sp20->unk_10 = 3;

        if ((sp24->unk_10 == 3) && (sp20->unk_10 == 3)) {
            Battle_StartTurn();
        }
    }

    BattleScene_SyncActiveHpToPartyState();

    if (cont->buttonPressed & 0x2000) {
        D_84390174 = 0;
        D_84390178.unk_00 = 0;
    }

    if (cont->buttonPressed & 0x8000) {
        gBattleScene.unk_00->unk_40 = 3;
    }
}

void BattleScene_CollectPlayerAction(Battler* arg0, Battler* arg1) {
    UNUSED s32 pad;
    BattleMonRuntime* sp20 = &arg0->unk_654.unk_38;
    BattleMonRuntime* sp1C = &arg1->unk_654.unk_38;

    if (BattleScene_HandlePlayerForcedActionState(arg0, arg1) == 0) {
        if (!(sp20->unk_4D & 0x60)) {
            sp20->unk_4C &= ~8;
            sp1C->unk_4C &= ~8;
            if (!(sp20->unk_4C & 0x12)) {
                if (BattleScene_HandlePlayerActionInput(arg0) == 0) {
                    if (!(sp20->unk_15 & 0x27)) {
                        if (!(sp20->unk_4C & 0x21)) {
                            if (sp1C->unk_4C & 0x20) {
                                BattleScene_HandlePlayerMoveSelectionLocked(arg0, arg0->unk_654.unk_C8);
                                sp20->unk_5A = 0xFF;
                            } else {
                                BattleScene_HandlePlayerMoveSelection(arg0);
                            }
                        } else {
                            BattleScene_HandlePlayerMoveSelectionLocked(arg0, arg0->unk_654.unk_C8);
                        }
                    } else {
                        BattleScene_HandlePlayerMoveSelectionLocked(arg0, arg0->unk_654.unk_C8);
                    }
                }
            } else {
                BattleScene_ConfirmForcedMoveRepeat(arg0);
            }
        } else {
            BattleScene_ConfirmForcedMoveRepeat(arg0);
        }
    }
}

void BattleScene_CollectActions(void) {
    BattlerState* sp24 = &D_84390010[0]->unk_654;
    BattlerState* sp20 = &D_84390010[1]->unk_654;
    BattleMonRuntime* sp1C = &D_84390010[0]->unk_654.unk_38;
    BattleMonRuntime* sp18 = &D_84390010[1]->unk_654.unk_38;

    if (D_84390010[0]->unk_724->unk_000 & 2) {
        D_84390144 = gBattleDamage;
        BattleScene_CollectCpuAction(D_84390010[0], D_84390010[1]);
        gBattleDamage = D_84390144;
    } else {
        BattleScene_CollectPlayerAction(D_84390010[0], D_84390010[1]);
    }

    if (D_84390010[1]->unk_724->unk_000 & 2) {
        D_84390144 = gBattleDamage;
        BattleScene_CollectCpuAction(D_84390010[1], D_84390010[0]);
        gBattleDamage = D_84390144;
    } else {
        BattleScene_CollectPlayerAction(D_84390010[1], D_84390010[0]);
    }

    if ((sp24->unk_10 == 3) && (sp20->unk_10 == 3)) {
        if (BattleScene_IsPresentationCountdownComplete() != 0) {
            D_84390134 = 1;
        }

        if (sp24->unk_04 == 2) {
            BattleScene_CommitPlayerSwitchAction(D_84390010[0]);
        } else {
            BattleScene_CommitSelectedMoveAction(D_84390010[0]);
        }

        if (sp20->unk_04 == 2) {
            BattleScene_CommitPlayerSwitchAction(D_84390010[1]);
        } else {
            BattleScene_CommitSelectedMoveAction(D_84390010[1]);
        }

        if ((sp24->unk_04 == 2) || (sp20->unk_04 == 2)) {
            BattleScene_InitializeSwitchActions();
        } else {
            Battle_StartTurn();
        }
    } else {
        if (!(D_84390010[0]->unk_724->unk_000 & 2) && !(sp1C->unk_4D & 0x60) && !(sp1C->unk_4C & 0x12)) {
            BattleScene_HandleActionSelectionCancel(0);
        }

        if (!(D_84390010[1]->unk_724->unk_000 & 2) && !(sp18->unk_4D & 0x60) && !(sp18->unk_4C & 0x12)) {
            BattleScene_HandleActionSelectionCancel(1);
        }
    }
}

void BattleScene_UpdateActionCollection(void) {
    D_84390288 = 0;
    if (D_800AE540.unk_0000 == 0x10) {
        BattleScene_TickAttractModeInput();
    } else {
        BattleScene_CollectActions();
    }
}

void BattleScene_UpdateActionSelectPhase(void) {
    BattlerState* sp1C = &D_84390010[0]->unk_654;
    BattlerState* sp18 = &D_84390010[1]->unk_654;

    if (BattleScene_UpdateResultPresentation() == 0) {
        D_84390010[0]->unk_4C8 = 0;
        D_84390010[1]->unk_4C8 = 0;

        if (sp1C->unk_2A != 1) {
            sp1C->unk_2A = 0;
        }

        if (sp18->unk_2A != 1) {
            sp18->unk_2A = 0;
        }

        BattleScene_UpdateActionCollection();
        BattleScene_TickPresentationTimer();
        BattleScene_TickActionSelectionTimers();
    }
}
