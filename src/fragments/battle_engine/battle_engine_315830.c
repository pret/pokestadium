#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/model_animation_events.h"
#include "src/model_renderer.h"

void BattleAnim_StartFreezeStatusAnimation(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    BattleMon* party_pokemon;
    ActivePokemonState* pokemon_state;
    BattleMonRuntime* runtime;
    MovePresentationCue* hit_cue;
    s32 side_index = BattleScene_GetParticipantSideIndex(active_pokemon);

    runtime = &active_pokemon->state.runtime;
    pokemon_state = &active_pokemon->state;
    party_pokemon = &active_pokemon->unk_724->pokemonPicked[pokemon_state->unk_08];
    hit_cue = &sSideBattleCues[side_index]->hitCue;

    if ((party_pokemon->statusCondition & 0x20) && (pokemon_state->flags & 2)) {
        active_pokemon->displayObject.node.renderFlags &= ~0x20;
    }

    if ((runtime->unk_15 & 0x20) && (party_pokemon->statusCondition & 0x20) && !(pokemon_state->flags & 2) &&
        ((active_pokemon->displayObject.transformAnim.frameFixed >> 0x10) >= 3)) {
        ModelAnim_SetAnimation(&active_pokemon->displayObject, hit_cue->id);
        ModelAnim_SetFrame(&active_pokemon->displayObject, 4);
        ModelAnim_SetEventTrack(&active_pokemon->displayObject, hit_cue->unk_01);
        ModelAnim_SetEventFrame(&active_pokemon->displayObject, 3);
        active_pokemon->displayObject.node.renderFlags &= ~0x20;
        Battle_SetRuntimeFlags(active_pokemon, 2);
        BattleAnim_QueueEffectList(1, active_pokemon);
        BattleAnim_PlayBattleSequenceById(active_pokemon, 0x13);
    }
}

void BattleAnim_RestoreBaseModelAnimation(ActivePokemon* arg0) {
    MovePresentationCue* ptr = &sSideBattleCues[BattleScene_GetParticipantSideIndex(arg0)]->idleCues;

    ModelAnim_SetAnimation(&arg0->displayObject, ptr->id);
}

void BattleAnim_ClearFreezeStatusAnimation(ActivePokemon* arg0) {
    if (arg0->state.flags & 2) {
        BattleAnim_StopOwnerCategoryParticles(1, arg0);
        arg0->displayObject.node.renderFlags |= 0x20;
        Battle_ClearRuntimeFlags(arg0, 2);
        BattleAnim_RestoreBaseModelAnimation(arg0);
    }
}

void BattleAnim_ResetFreezeStatusAndRestoreAnimation(ActivePokemon* arg0) {
    BattleMon* ptr = &arg0->unk_724->pokemonPicked[arg0->state.unk_08];

    if (arg0->state.flags & 2) {
        ptr->statusCondition = 0;
        BattleAnim_StopOwnerCategoryParticles(1, arg0);
        arg0->displayObject.node.renderFlags |= 0x20;
        Battle_ClearRuntimeFlags(arg0, 2);
        BattleAnim_RestoreBaseModelAnimation(arg0);
    }
}

void BattleAnim_ClearFreezeStatusAnimationIfThawed(ActivePokemon* arg0) {
    if ((arg0->state.flags & 2) && !(arg0->state.runtime.unk_15 & 0x20)) {
        BattleAnim_StopOwnerCategoryParticles(1, arg0);
        arg0->displayObject.node.renderFlags |= 0x20;
        Battle_ClearRuntimeFlags(arg0, 2);
        BattleAnim_RestoreBaseModelAnimation(arg0);
    }
}

void BattleAnim_UpdateSleepStatusAnimation(ActivePokemon* active_pokemon) {
    ActivePokemonState* pokemon_state = &active_pokemon->state;
    BattleMonRuntime* runtime = &pokemon_state->runtime;
    BattleMon* party_pokemon = &active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08];

    if ((sBattleScene.unk_00->unk_38 != 0xB) || (sBattleScene.unk_00->unk_20 >= 6)) {
        if ((party_pokemon->statusCondition & 7) && (runtime->unk_15 & 7) && !(active_pokemon->state.flags & 1)) {
            BattleAnim_SetModelEventTrackAndState(active_pokemon, BATTLE_CUE_SLEEP_IDLE, 2);
            BattleAnim_QueueEffectList(3, active_pokemon);
            BattleAnim_PlayBattleSequenceById(active_pokemon, 0x32);
            Battle_SetRuntimeFlags(active_pokemon, 1);
        }

        if (!(party_pokemon->statusCondition & 7) && (pokemon_state->flags & 1)) {
            if (sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->wakeUpEventTrack == 0xFF) {
                pokemon_state->unk_36 = 0;
                BattleAnim_SetModelEventTrackFromRow(active_pokemon, BATTLE_CUE_IDLE);
            } else {
                BattleAnim_SetModelEventTrackAndState(active_pokemon, 0xB8, 1);
            }
            BattleAnim_StopOwnerCategoryParticles(3, active_pokemon);
            Battle_ClearRuntimeFlags(active_pokemon, 1);
        }
    }
}

void BattleAnim_EndSleepStatusAnimation(ActivePokemon* arg0) {
    BattleMon* ptr = &arg0->unk_724->pokemonPicked[arg0->state.unk_08];

    if (arg0->state.flags & 1) {
        ptr->statusCondition = 0;
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
    if (arg0->state.flags & 1) {
        BattleAnim_StopOwnerCategoryParticles(3, arg0);
        Battle_ClearRuntimeFlags(arg0, 1);
    }
}
