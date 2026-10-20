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
    D_8439012C = gSessionContext.moveLimitSeconds * 0x1E;
    D_84390130 = gSessionContext.battleLimitMinutes * 0x708;
    D_84390128 = gSessionContext.battleLimitMinutes * 0x708;
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
    if (gSessionContext.timeLimitsEnabled == 0) {
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

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(sActivePokemon[0]); i++) {
        ptr = &sActivePokemon[0]->unk_724->pokemonPicked[i];
        if (ptr->unk_02 != 0) {
            var_s3++;
        }
    }

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(sActivePokemon[1]); i++) {
        ptr = &sActivePokemon[1]->unk_724->pokemonPicked[i];
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

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(sActivePokemon[0]); i++) {
        ptr = &sActivePokemon[0]->unk_724->pokemonPicked[i];
        var_s5 += Battle_ClassifyHpTier(ptr->unk_02, ptr->unk_26);
    }

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(sActivePokemon[1]); i++) {
        ptr = &sActivePokemon[1]->unk_724->pokemonPicked[i];
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

    if (gSessionContext.timeLimitsEnabled == 0) {
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
                    sBattleScene.unk_00->unk_40 = BattleScene_DetermineWinner();
                    Audio_FadeOutAll(0x14);
                }
                break;
        }
    }
    return sp1C;
}

s32 BattleScene_IsActionSelectionTimerExpired(void) {
    if (gSessionContext.timeLimitsEnabled == 0) {
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
    D_84390124 = gSessionContext.moveLimitSeconds * 0x1E;
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

s32 BattleScene_ApplyForcedActionDelay(ActivePokemon* arg0) {
    ActivePokemonState* temp_v1 = &arg0->state;

    if (arg0->state.unk_10 == 3) {
        temp_v1->unk_1E += 0x38E;
        return 1;
    }
    return 0;
}

void BattleScene_SyncActiveHpToPartyState(void) {
    BattleMonRuntime* temp_a2;
    BattleMonRuntime* temp_a3;
    ActivePokemonState* ptr1;
    ActivePokemonState* ptr2;
    BattleMon* ptr3;
    BattleMon* ptr4;

    ptr1 = &sActivePokemon[0]->state;
    ptr2 = &sActivePokemon[1]->state;
    temp_a2 = &sActivePokemon[0]->state.runtime;
    temp_a3 = &sActivePokemon[1]->state.runtime;

    ptr3 = &sActivePokemon[0]->unk_724->pokemonPicked[ptr1->unk_08];
    ptr4 = &sActivePokemon[1]->unk_724->pokemonPicked[ptr2->unk_08];

    if (D_84390288 != 0) {
        D_843900A8[0] = temp_a2->unk_0C = temp_a2->unk_28;
        D_843900A8[1] = temp_a3->unk_0C = temp_a3->unk_28;

        ptr3->unk_02 = temp_a2->unk_28;
        ptr4->unk_02 = temp_a3->unk_28;
    }
}

s32 BattleScene_SelectFallbackWhenNoUsableMoves(ActivePokemon* arg0) {
    s32 i;
    s32 var_v1;
    ActivePokemonState* temp_v1;
    BattleMonRuntime* temp_v0;

    temp_v1 = &arg0->state;
    temp_v0 = &arg0->state.runtime;
    var_v1 = 0;

    if (arg0->state.runtime.unk_52 != 0) {
        for (i = 0; i < 4; i++) {
            if (((temp_v0->unk_52 >> 4) != i) && (temp_v0->moves[i] != 0)) {
                var_v1 |= temp_v0->unk_32[i] & 0x3F;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (temp_v0->moves[i] != 0) {
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

s32 BattleScene_IsMoveUnavailable(ActivePokemon* arg0, s32 arg1) {
    BattleMonRuntime* ptr = &arg0->state.runtime;

    if (!(ptr->unk_32[arg1] & 0x3F)) {
        return 1;
    }

    if ((ptr->unk_52 & 0xF) && (arg1 == (ptr->unk_52 >> 4))) {
        return 1;
    }

    return 0;
}

void BattleScene_AutoSelectAvailableMove(ActivePokemon* arg0) {
    s32 i;
    ActivePokemonState* temp_v0 = &arg0->state;

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

void BattleScene_AutoSelectReplacementMon(ActivePokemon* arg0) {
    s32 i;
    ActivePokemonState* sp1C = &arg0->state;

    for (i = 0; i < arg0->sessionTeams->teamMember[0]->numberOfPokemonBrought; i++) {
        if ((arg0->sessionTeams->teamMember[0]->pokemonPicked[i].unk_02 != 0) && (i != sp1C->unk_08)) {
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

void BattleScene_SelectActiveController(ActivePokemon* arg0) {
    ActivePokemonState* ptr = &arg0->state;

    ptr->unk_2C = ptr->unk_2B;
    ptr->unk_C8 = &gControllers[arg0->sessionTeams->teamMember[ptr->unk_2C]->unk_001];
}

void BattleScene_HandleActionSelectionCancel(s32 arg0) {
    ActivePokemonState* sp2C;
    ActivePokemonState* sp28;
    UNUSED s32 pad;
    Controller* cont;

    sp2C = &sActivePokemon[arg0]->state;
    sp28 = &sActivePokemon[arg0 == 0]->state;
    cont = sp2C->unk_C8;

    if ((sp2C->unk_10 != 3) || !(cont->buttonPressed & 0x20)) {
        return;
    }

    if (sp2C->unk_2D == 0x10) {
        if (sp2C->unk_04 == 2) {
            BattleScene_SelectActiveController(sActivePokemon[arg0]);
        }
        BattleAnim_PlaySoundEffect3();
        sp2C->unk_10 = 2;
    }

    if (sp28->unk_2D != 0x10) {
        if (sp2C->unk_04 == 2) {
            BattleScene_SelectActiveController(sActivePokemon[arg0]);
        }
        BattleAnim_PlaySoundEffect3();
        sp2C->unk_10 = 0;
    }
}

void Battle_InitializeActiveRuntimeState(void) {
    BattleScene_InitializePresentationTimers();
    func_84370B7C(sActivePokemon[0]);
    func_84370B7C(sActivePokemon[1]);

    D_843900A8[0] = sActivePokemon[0]->state.runtime.unk_0C;
    D_843900A8[1] = sActivePokemon[1]->state.runtime.unk_0C;

    Battle_ResetTransientRuntimeState(0, 1);
    Battle_ResetTransientRuntimeState(1, 0);
}

s32 BattleScene_CpuHasNoUsableMoves(ActivePokemon* arg0) {
    BattleMonRuntime* temp_v0 = &arg0->state.runtime;
    s32 i;
    s32 var_v1 = 0;

    if (temp_v0->unk_52 != 0) {
        for (i = 0; i < 4; i++) {
            if (((temp_v0->unk_52 >> 4) != i) && (temp_v0->moves[i] != 0)) {
                var_v1 |= temp_v0->unk_32[i] & 0x3F;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (temp_v0->moves[i] != 0) {
                var_v1 |= temp_v0->unk_32[i] & 0x3F;
            }
        }
    }

    if (var_v1 == 0) {
        return 1;
    }
    return 0;
}

s32 BattleScene_WaitForCpuChoice(ActivePokemon* arg0, ActivePokemon* arg1) {
    UNUSED s32 pad[2];
    ActivePokemonState* sp1C = &arg0->state;
    ActivePokemonState* temp_v0 = &arg1->state;

    if ((arg0->state.unk_2D == 0x10) && (arg1->state.unk_2D == 0x10)) {
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

void BattleScene_CompleteCpuForcedAction(ActivePokemon* arg0, UNUSED ActivePokemon* arg1) {
    ActivePokemonState* ptr = &arg0->state;

    BattleScene_ApplyForcedActionDelay(arg0);
    ptr->unk_2A = 1;
    ptr->unk_04 = 1;
    ptr->unk_0C = ptr->unk_14;
    ptr->unk_10 = 3;
}

void BattleScene_CompleteCpuMoveAction(ActivePokemon* arg0, ActivePokemon* arg1) {
    ActivePokemonState* sp20 = &arg1->state;
    ActivePokemonState* sp1C = &arg0->state;

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

void BattleScene_ApplyCpuChoice(ActivePokemon* arg0, ActivePokemon* arg1) {
    ActivePokemonState* sp18;
    ActivePokemonState* sp14;
    s32 var_v0;

    sp18 = &arg0->state;
    sp14 = &arg1->state;

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

s32 BattleScene_ApplyCpuSwitchChoice(ActivePokemon* arg0, ActivePokemon* arg1) {
    ActivePokemonState* sp1C = &arg0->state;
    ActivePokemonState* sp18 = &arg1->state;

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

void BattleScene_TriggerCpuChoice(UNUSED BattleMonRuntime* arg0, UNUSED BattleMonRuntime* arg1, UNUSED ActivePokemonState* arg2,
                   UNUSED ActivePokemonState* arg3, UNUSED ActivePokemon* arg4) {
    if ((D_84390120 == 1.0f) && (D_8439013C == 0)) {
        D_8439013C = 1;
        D_84390138 = BattleAI_ChooseAction(0);
    }
}

s32 BattleScene_CollectCpuAction(ActivePokemon* arg0, ActivePokemon* arg1) {
    BattleMonRuntime* sp34 = &arg0->state.runtime;
    BattleMonRuntime* sp30 = &arg1->state.runtime;
    ActivePokemonState* sp2C = &arg0->state;
    ActivePokemonState* sp28 = &arg1->state;

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
                        sp34->usedMove = 0xFF;
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

void BattleScene_ForfeitPrompt(ActivePokemon* arg0) {
    ActivePokemonState* sp18 = &arg0->state;
    ActivePokemonState* temp_a0 = &sActivePokemon[BattleScene_GetParticipantSideIndex(arg0) == 0]->state;

    if (arg0->sessionTeams->unk_01 == 1) {
        D_84390148 = &gControllers[arg0->sessionTeams->teamMember[0]->unk_001];
        D_8439014C = &gControllers[arg0->sessionTeams->teamMember[0]->unk_001];
    } else {
        D_84390148 = &gControllers[arg0->sessionTeams->teamMember[0]->unk_001];
        D_8439014C = &gControllers[arg0->sessionTeams->teamMember[1]->unk_001];
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

    if ((sBattleScene.unk_00->unk_40 == 0) &&
        (BTN_IS_PRESSED(D_84390148, BTN_DLEFT) || BTN_IS_PRESSED(D_8439014C, BTN_DLEFT))) {
        sp18->unk_2F = 0;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    if ((sBattleScene.unk_00->unk_40 == 0) &&
        (BTN_IS_PRESSED(D_84390148, BTN_DRIGHT) || BTN_IS_PRESSED(D_8439014C, BTN_DRIGHT))) {
        sp18->unk_2F = 1;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    if ((sp18->unk_2F == 1) && (BTN_IS_PRESSED(D_84390148, BTN_A) || BTN_IS_PRESSED(D_8439014C, BTN_A)) &&
        (sBattleScene.unk_00->unk_40 == 0)) {
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        sBattleScene.unk_00->unk_40 = (BattleScene_GetParticipantSideIndex(arg0) == 0) + 1;
        Audio_FadeOutAll(0x14);
    } else if ((sp18->unk_2F == 0) && (BTN_IS_PRESSED(D_84390148, BTN_A) || BTN_IS_PRESSED(D_8439014C, BTN_A))) {
        sp18->unk_10 = 0;
        sp18->unk_04 = 0;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
}

void BattleScene_CommitPlayerSwitchAction(ActivePokemon* arg0) {
    ActivePokemonState* temp_v0 = &arg0->state;
    BattleMonRuntime* temp_v1 = &sActivePokemon[BattleScene_GetParticipantSideIndex(arg0) == 0]->state.runtime;

    if (temp_v1->unk_4C & 0x20) {
        arg0->state.runtime.usedMove = 0xFF;
    }

    if (temp_v0->unk_2D != 0x10) {
        temp_v0->unk_2D = 0xF;
    }

    temp_v0->unk_1C = 0;
    BattleScene_ClearParticipantMessageBuffer(arg0);
}

s32 BattleScene_ValidateSelectedPartyMember(ActivePokemon* arg0) {
    if (arg0->sessionTeams->teamMember[arg0->state.unk_2C]->pokemonPicked[arg0->state.unk_18].unk_02 != 0) {
        return 1;
    }

    BattleScene_ClearParticipantMessageBuffer(arg0);
    BattleScene_BuildParticipantMessage(arg0, 3);
    BattleAnim_PlaySoundEffect8();
    return 0;
}

void BattleScene_QueuePartySelectionConfirmMessage(ActivePokemon* arg0) {
    BattleScene_ClearParticipantMessageBuffer(arg0);
    BattleScene_BuildParticipantMessage(arg0, 4);
}

void BattleScene_AssignActiveCoopController(ActivePokemon* arg0, s32 arg1) {
    if (arg1 == 1) {
        D_84390148 = &gControllers[arg0->sessionTeams->teamMember[0]->unk_001];
        D_8439014C = &gControllers[arg0->sessionTeams->teamMember[0]->unk_001];
    } else {
        D_84390148 = &gControllers[arg0->sessionTeams->teamMember[0]->unk_001];
        D_8439014C = &gControllers[arg0->sessionTeams->teamMember[1]->unk_001];
    }

    if (arg1 == 1) {
        if (BTN_IS_PRESSED(D_84390148, BTN_A | BTN_B | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
            arg0->state.unk_2C = 0;
            BattleScene_SetParticipantController(arg0, D_84390148);
        } else if (BTN_IS_PRESSED(D_8439014C, BTN_A | BTN_B | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
            BattleScene_SetParticipantController(arg0, D_8439014C);
            arg0->state.unk_2C = 0;
        }
    } else if (BTN_IS_PRESSED(D_84390148, BTN_A | BTN_B | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
        BattleScene_SetParticipantController(arg0, D_84390148);
        arg0->state.unk_2C = 0;
    } else if (BTN_IS_PRESSED(D_8439014C, BTN_A | BTN_B | BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
        BattleScene_SetParticipantController(arg0, D_8439014C);
        arg0->state.unk_2C = 1;
    }
}

void BattleScene_HandlePartySlotCursorInput(ActivePokemon* arg0, Controller* arg1) {
    ActivePokemonState* sp1C;
    TeamRoster* temp_a1;

    sp1C = &arg0->state;

    BattleScene_AssignActiveCoopController(arg0, arg0->sessionTeams->unk_01);
    temp_a1 = arg0->sessionTeams->teamMember[sp1C->unk_2C];
    arg1 = sp1C->unk_C8;

    if (temp_a1->numberOfPokemonBrought < 4) {
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
        } else if (((temp_a1->numberOfPokemonBrought - 1) >= sp1C->unk_18) && (BattleScene_ValidateSelectedPartyMember(arg0) != 0)) {
            BattleAnim_PlaySoundEffect2();
            sp1C->unk_1C = 0;
            sp1C->unk_1E = 0;
            sp1C->unk_10 = 3;
        }
    }
}

void BattleScene_HandlePlayerPartySelection(ActivePokemon* arg0) {
    UNUSED s32 pad;
    s32 idx;
    ActivePokemonState* sp18 = &arg0->state;

    if (arg0->sessionTeams->unk_01 == 1) {
        D_84390148 = &gControllers[arg0->sessionTeams->teamMember[0]->unk_001];
        D_8439014C = &gControllers[arg0->sessionTeams->teamMember[0]->unk_001];
    } else {

        D_84390148 = &gControllers[arg0->sessionTeams->teamMember[sp18->unk_2C]->unk_001];
        idx = sp18->unk_2C == 0;
        D_8439014C = &gControllers[arg0->sessionTeams->teamMember[idx]->unk_001];
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

void BattleScene_CommitSelectedMoveAction(ActivePokemon* arg0) {
    ActivePokemonState* temp_v0 = &arg0->state;
    BattleMonRuntime* temp_v1 = &arg0->state.runtime;

    if (arg0->state.unk_14 != 4) {
        temp_v0->unk_0C = temp_v0->unk_14;
        if (temp_v0->unk_2A == 0) {
            temp_v1->usedMove = temp_v1->moves[temp_v0->unk_0C];
        }
    } else {
        if (temp_v1->unk_4C & 0x20) {
            temp_v0->unk_0C = temp_v0->unk_14;
        } else {
            temp_v0->unk_14 = 0;
            temp_v0->unk_0C = 0;
            temp_v1->usedMove = 0xA5;
        }
    }

    temp_v0->unk_1C = 0;
    BattleScene_ClearParticipantMessageBuffer(arg0);
}

s32 BattleScene_HandleNoUsableMoveSelection(ActivePokemon* arg0) {
    s32 i;
    s32 temp_a1;
    s32 var_v1;
    ActivePokemonState* temp_v0;
    BattleMonRuntime* temp_a0;
    Controller* cont;

    temp_v0 = &arg0->state;
    temp_a0 = &arg0->state.runtime;
    cont = arg0->state.unk_C8;
    var_v1 = 0;

    if (temp_a0->unk_52 != 0) {
        temp_a1 = temp_a0->unk_52 >> 4;
        for (i = 0; i < 4; i++) {
            if ((temp_a1 != i) && (temp_a0->moves[i] != 0)) {
                var_v1 |= temp_a0->unk_32[i] & 0x3F;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (temp_a0->moves[i] != 0) {
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

s32 BattleScene_ValidateSelectedMove(ActivePokemon* arg0) {
    UNUSED s32 pad[2];
    ActivePokemonState* sp24 = &arg0->state;
    BattleMonRuntime* ptr = &arg0->state.runtime;

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

void BattleScene_SelectMoveFromButtons(ActivePokemon* arg0) {
    Controller* cont = arg0->state.unk_C8;

    if ((cont->buttonPressed & 8) != 0) {
        if ((arg0->state.runtime.moves[0] != 0) && (arg0->state.runtime.moves[0] < 0xA6)) {
            arg0->state.unk_14 = 0;
            BattleScene_ValidateSelectedMove(arg0);
            return;
        }
    }

    if ((cont->buttonPressed & 1) != 0) {
        if ((arg0->state.runtime.moves[1] != 0) && (arg0->state.runtime.moves[1] < 0xA6)) {
            arg0->state.unk_14 = 1;
            BattleScene_ValidateSelectedMove(arg0);
            return;
        }
    }

    if ((cont->buttonPressed & 4) != 0) {
        if ((arg0->state.runtime.moves[2] != 0) && (arg0->state.runtime.moves[2] < 0xA6)) {
            arg0->state.unk_14 = 2;
            BattleScene_ValidateSelectedMove(arg0);
            return;
        }
    }

    if ((cont->buttonPressed & 2) != 0) {
        if ((arg0->state.runtime.moves[3] != 0) && (arg0->state.runtime.moves[3] < 0xA6)) {
            arg0->state.unk_14 = 3;
            BattleScene_ValidateSelectedMove(arg0);
            return;
        }
    }

    if ((cont->buttonPressed & 8) || (cont->buttonPressed & 1) || (cont->buttonPressed & 4) ||
        (cont->buttonPressed & 2)) {
        BattleAnim_PlaySoundEffect8();
    }
}

void BattleScene_HandlePlayerMoveSelection(ActivePokemon* arg0) {
    UNUSED s32 pad[2];
    Controller* sp1C = arg0->state.unk_C8;
    ActivePokemonState* temp_v0 = &arg0->state;

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

s32 BattleScene_HandlePlayerMoveSelectionLocked(ActivePokemon* arg0, UNUSED Controller* arg1) {
    arg0->state.unk_2A = 1;
    BattleScene_HandlePlayerMoveSelection(arg0);
    arg0->state.unk_2A = 1;
    return 0;
}

void BattleScene_ConfirmForcedMoveRepeat(ActivePokemon* arg0) {
    ActivePokemonState* ptr = &arg0->state;

    BattleScene_ApplyForcedActionDelay(arg0);
    ptr->unk_2A = 1;
    ptr->unk_10 = 3;
    ptr->unk_0C = ptr->unk_14;
}

void BattleScene_PollActionMenuRequestButtons(ActivePokemon* arg0) {
    ActivePokemonState* temp_v1 = &arg0->state;
    ActivePokemonState* temp_t0 = &sActivePokemon[BattleScene_GetParticipantSideIndex(arg0) == 0]->state;

    if (temp_v1->unk_10 == 0) {
        if (arg0->sessionTeams->unk_01 == 1) {
            D_84390148 = &gControllers[arg0->sessionTeams->teamMember[0]->unk_001];
            D_8439014C = &gControllers[arg0->sessionTeams->teamMember[0]->unk_001];
        } else {
            D_84390148 = &gControllers[arg0->sessionTeams->teamMember[0]->unk_001];
            D_8439014C = &gControllers[arg0->sessionTeams->teamMember[1]->unk_001];
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

s32 BattleScene_HandlePlayerActionInput(ActivePokemon* arg0) {
    BattleScene_GetParticipantSideIndex(arg0);

    if (BattleScene_ApplyForcedActionDelay(arg0) != 0) {
        return 1;
    }

    if (BattleScene_IsActionSelectionTimerExpired() != 0) {
        if (arg0->state.unk_04 == 2) {
            BattleScene_AutoSelectReplacementMon(arg0);
        } else {
            BattleScene_AutoSelectAvailableMove(arg0);
        }
        return 1;
    }

    BattleScene_PollActionMenuRequestButtons(arg0);

    switch (arg0->state.unk_04) {
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

s32 BattleScene_HandlePlayerForcedActionState(ActivePokemon* arg0, ActivePokemon* arg1) {
    ActivePokemonState* sp1C = &arg0->state;
    ActivePokemonState* temp_v0 = &arg1->state;

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
    sActivePokemon[0]->unk_728.unk_168->node.flags |= 1;
    sActivePokemon[0]->unk_728.unk_000.node.flags |= 1;
    sActivePokemon[1]->unk_728.unk_168->node.flags |= 1;
    sActivePokemon[1]->unk_728.unk_000.node.flags |= 1;
}

void BattleScene_HideParticipantOwnerAndSecondaryModels(void) {
    sActivePokemon[0]->unk_728.unk_168->node.flags &= ~1;
    sActivePokemon[0]->unk_728.unk_000.node.flags &= ~1;
    sActivePokemon[1]->unk_728.unk_168->node.flags &= ~1;
    sActivePokemon[1]->unk_728.unk_000.node.flags &= ~1;
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

void BattleScene_CheckForcedActionCondition(ActivePokemon* arg0, ActivePokemon* arg1) {
    BattleMonRuntime* temp_v0 = &arg0->state.runtime;
    BattleMonRuntime* temp_v1 = &arg1->state.runtime;

    if (!(arg0->state.runtime.unk_4D & 0x60)) {
        temp_v0->unk_4C &= ~8;
        temp_v1->unk_4C &= ~8;
        if (temp_v0->unk_4C & 0x12) {
            arg0->state.unk_2A = 1;
        }
    } else {
        arg0->state.unk_2A = 1;
    }
}

void BattleScene_TickAttractModeInput(void) {
    ActivePokemonState* sp24 = &sActivePokemon[0]->state;
    ActivePokemonState* sp20 = &sActivePokemon[1]->state;
    BattleMonRuntime* sp1C = &sActivePokemon[0]->state.runtime;
    BattleMonRuntime* sp18 = &sActivePokemon[1]->state.runtime;
    Controller* cont = &D_84390150;

    BattleScene_AdvanceAttractInputScript();
    BattleScene_CheckForcedActionCondition(sActivePokemon[0], sActivePokemon[1]);
    BattleScene_CheckForcedActionCondition(sActivePokemon[1], sActivePokemon[0]);

    if (cont->buttonPressed & 0x20) {
        BattleScene_ShowParticipantOwnerAndSecondaryModels();
        BattleScene_TriggerOwnerModelAnimation(sActivePokemon[0]);
        BattleScene_TriggerOwnerModelAnimation(sActivePokemon[1]);
    }

    if (cont->buttonPressed & 0x10) {
        BattleScene_HideParticipantOwnerAndSecondaryModels();
    }

    if (cont->buttonPressed & 0x1000) {
        sp24->unk_04 = 0;
        sp20->unk_04 = 0;

        if (sp24->unk_2A == 0) {
            sp1C->usedMove = BattleAI_ResolveRandomMove(0, 0);
        }

        if (sp20->unk_2A == 0) {
            sp18->usedMove = BattleAI_ResolveRandomMove(1, 0);
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
        sBattleScene.unk_00->unk_40 = 3;
    }
}

void BattleScene_CollectPlayerAction(ActivePokemon* arg0, ActivePokemon* arg1) {
    UNUSED s32 pad;
    BattleMonRuntime* sp20 = &arg0->state.runtime;
    BattleMonRuntime* sp1C = &arg1->state.runtime;

    if (BattleScene_HandlePlayerForcedActionState(arg0, arg1) == 0) {
        if (!(sp20->unk_4D & 0x60)) {
            sp20->unk_4C &= ~8;
            sp1C->unk_4C &= ~8;
            if (!(sp20->unk_4C & 0x12)) {
                if (BattleScene_HandlePlayerActionInput(arg0) == 0) {
                    if (!(sp20->unk_15 & 0x27)) {
                        if (!(sp20->unk_4C & 0x21)) {
                            if (sp1C->unk_4C & 0x20) {
                                BattleScene_HandlePlayerMoveSelectionLocked(arg0, arg0->state.unk_C8);
                                sp20->usedMove = 0xFF;
                            } else {
                                BattleScene_HandlePlayerMoveSelection(arg0);
                            }
                        } else {
                            BattleScene_HandlePlayerMoveSelectionLocked(arg0, arg0->state.unk_C8);
                        }
                    } else {
                        BattleScene_HandlePlayerMoveSelectionLocked(arg0, arg0->state.unk_C8);
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
    ActivePokemonState* sp24 = &sActivePokemon[0]->state;
    ActivePokemonState* sp20 = &sActivePokemon[1]->state;
    BattleMonRuntime* sp1C = &sActivePokemon[0]->state.runtime;
    BattleMonRuntime* sp18 = &sActivePokemon[1]->state.runtime;

    if (sActivePokemon[0]->unk_724->unk_000 & 2) {
        D_84390144 = sBattleDamage;
        BattleScene_CollectCpuAction(sActivePokemon[0], sActivePokemon[1]);
        sBattleDamage = D_84390144;
    } else {
        BattleScene_CollectPlayerAction(sActivePokemon[0], sActivePokemon[1]);
    }

    if (sActivePokemon[1]->unk_724->unk_000 & 2) {
        D_84390144 = sBattleDamage;
        BattleScene_CollectCpuAction(sActivePokemon[1], sActivePokemon[0]);
        sBattleDamage = D_84390144;
    } else {
        BattleScene_CollectPlayerAction(sActivePokemon[1], sActivePokemon[0]);
    }

    if ((sp24->unk_10 == 3) && (sp20->unk_10 == 3)) {
        if (BattleScene_IsPresentationCountdownComplete() != 0) {
            D_84390134 = 1;
        }

        if (sp24->unk_04 == 2) {
            BattleScene_CommitPlayerSwitchAction(sActivePokemon[0]);
        } else {
            BattleScene_CommitSelectedMoveAction(sActivePokemon[0]);
        }

        if (sp20->unk_04 == 2) {
            BattleScene_CommitPlayerSwitchAction(sActivePokemon[1]);
        } else {
            BattleScene_CommitSelectedMoveAction(sActivePokemon[1]);
        }

        if ((sp24->unk_04 == 2) || (sp20->unk_04 == 2)) {
            BattleScene_InitializeSwitchActions();
        } else {
            Battle_StartTurn();
        }
    } else {
        if (!(sActivePokemon[0]->unk_724->unk_000 & 2) && !(sp1C->unk_4D & 0x60) && !(sp1C->unk_4C & 0x12)) {
            BattleScene_HandleActionSelectionCancel(0);
        }

        if (!(sActivePokemon[1]->unk_724->unk_000 & 2) && !(sp18->unk_4D & 0x60) && !(sp18->unk_4C & 0x12)) {
            BattleScene_HandleActionSelectionCancel(1);
        }
    }
}

void BattleScene_UpdateActionCollection(void) {
    D_84390288 = 0;
    if (gSessionContext.mode == 0x10) {
        BattleScene_TickAttractModeInput();
    } else {
        BattleScene_CollectActions();
    }
}

void BattleScene_UpdateActionSelectPhase(void) {
    ActivePokemonState* sp1C = &sActivePokemon[0]->state;
    ActivePokemonState* sp18 = &sActivePokemon[1]->state;

    if (BattleScene_UpdateResultPresentation() == 0) {
        sActivePokemon[0]->unk_4C8 = 0;
        sActivePokemon[1]->unk_4C8 = 0;

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
