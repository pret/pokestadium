#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/model_animation_events.h"
#include "src/model_renderer.h"

void BattleAnim_StartFreezeStatusAnimation(ActivePokemon* arg0) {
    UNUSED s32 pad[2];
    BattleMon* ptr;
    ActivePokemonState* sp2C;
    BattleMonRuntime* sp28;
    MovePresentationCue* sp20;
    s32 idx = BattleScene_GetParticipantSideIndex(arg0);

    sp28 = &arg0->state.runtime;
    sp2C = &arg0->state;
    ptr = &arg0->unk_724->pokemonPicked[sp2C->unk_08];
    sp20 = &sSideBattleCues[idx]->hitCue;

    if ((ptr->unk_05 & 0x20) && (sp2C->diggingStageMask & 2)) {
        arg0->displayObject.node.renderFlags &= ~0x20;
    }

    if ((sp28->unk_15 & 0x20) && (ptr->unk_05 & 0x20) && !(sp2C->diggingStageMask & 2) &&
        ((arg0->displayObject.transformAnim.frameFixed >> 0x10) >= 3)) {
        ModelAnim_SetAnimation(&arg0->displayObject, sp20->id);
        ModelAnim_SetFrame(&arg0->displayObject, 4);
        ModelAnim_SetEventTrack(&arg0->displayObject, sp20->unk_01);
        ModelAnim_SetEventFrame(&arg0->displayObject, 3);
        arg0->displayObject.node.renderFlags &= ~0x20;
        Battle_SetRuntimeFlags(arg0, 2);
        BattleAnim_QueueEffectList(1, arg0);
        BattleAnim_PlayBattleSequenceById(arg0, 0x13);
    }
}

void BattleAnim_RestoreBaseModelAnimation(ActivePokemon* arg0) {
    MovePresentationCue* ptr = &sSideBattleCues[BattleScene_GetParticipantSideIndex(arg0)]->idleCues;

    ModelAnim_SetAnimation(&arg0->displayObject, ptr->id);
}

void BattleAnim_ClearFreezeStatusAnimation(ActivePokemon* arg0) {
    if (arg0->state.diggingStageMask & 2) {
        BattleAnim_StopOwnerCategoryParticles(1, arg0);
        arg0->displayObject.node.renderFlags |= 0x20;
        Battle_ClearRuntimeFlags(arg0, 2);
        BattleAnim_RestoreBaseModelAnimation(arg0);
    }
}

void BattleAnim_ResetFreezeStatusAndRestoreAnimation(ActivePokemon* arg0) {
    BattleMon* ptr = &arg0->unk_724->pokemonPicked[arg0->state.unk_08];

    if (arg0->state.diggingStageMask & 2) {
        ptr->unk_05 = 0;
        BattleAnim_StopOwnerCategoryParticles(1, arg0);
        arg0->displayObject.node.renderFlags |= 0x20;
        Battle_ClearRuntimeFlags(arg0, 2);
        BattleAnim_RestoreBaseModelAnimation(arg0);
    }
}

void BattleAnim_ClearFreezeStatusAnimationIfThawed(ActivePokemon* arg0) {
    if ((arg0->state.diggingStageMask & 2) && !(arg0->state.runtime.unk_15 & 0x20)) {
        BattleAnim_StopOwnerCategoryParticles(1, arg0);
        arg0->displayObject.node.renderFlags |= 0x20;
        Battle_ClearRuntimeFlags(arg0, 2);
        BattleAnim_RestoreBaseModelAnimation(arg0);
    }
}

void BattleAnim_UpdateSleepStatusAnimation(ActivePokemon* arg0) {
    ActivePokemonState* sp24 = &arg0->state;
    BattleMonRuntime* sp28 = &sp24->runtime;
    BattleMon* sp2C = &arg0->unk_724->pokemonPicked[arg0->state.unk_08];

    if ((sBattleScene.unk_00->unk_38 != 0xB) || (sBattleScene.unk_00->unk_20 >= 6)) {
        if ((sp2C->unk_05 & 7) && (sp28->unk_15 & 7) && !(arg0->state.diggingStageMask & 1)) {
            BattleAnim_SetModelEventTrackAndState(arg0, 0xAF, 2);
            BattleAnim_QueueEffectList(3, arg0);
            BattleAnim_PlayBattleSequenceById(arg0, 0x32);
            Battle_SetRuntimeFlags(arg0, 1);
        }

        if (!(sp2C->unk_05 & 7) && (sp24->diggingStageMask & 1)) {
            if (sSideBattleCues[BattleScene_GetParticipantSideIndex(arg0)]->wakeUpEventTrack == 0xFF) {
                sp24->unk_36 = 0;
                BattleAnim_SetModelEventTrackFromRow(arg0, 0xA5);
            } else {
                BattleAnim_SetModelEventTrackAndState(arg0, 0xB8, 1);
            }
            BattleAnim_StopOwnerCategoryParticles(3, arg0);
            Battle_ClearRuntimeFlags(arg0, 1);
        }
    }
}

void BattleAnim_EndSleepStatusAnimation(ActivePokemon* arg0) {
    BattleMon* ptr = &arg0->unk_724->pokemonPicked[arg0->state.unk_08];

    if (arg0->state.diggingStageMask & 1) {
        ptr->unk_05 = 0;
        if (sSideBattleCues[BattleScene_GetParticipantSideIndex(arg0)]->wakeUpEventTrack == 0xFF) {
            arg0->state.unk_36 = 0;
            BattleAnim_SetModelEventTrackFromRow(arg0, 0xA5);
        } else {
            BattleAnim_SetModelEventTrackAndState(arg0, 0xB8, 1);
        }
        BattleAnim_StopOwnerCategoryParticles(3, arg0);
        Battle_ClearRuntimeFlags(arg0, 1);
    }
}

void BattleAnim_ClearSleepStatusAnimation(ActivePokemon* arg0) {
    if (arg0->state.diggingStageMask & 1) {
        BattleAnim_StopOwnerCategoryParticles(3, arg0);
        Battle_ClearRuntimeFlags(arg0, 1);
    }
}
