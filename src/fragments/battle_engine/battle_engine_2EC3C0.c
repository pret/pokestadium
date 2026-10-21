#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/model_animation_events.h"
#include "src/model_renderer.h"
#include "src/pokemon_stats.h"
#include "src/text_system.h"
#include "src/gb_save.h"
#include "src/audio_commands.h"
#include "src/jpeg_stream.h"
#include "src/audio_fade.h"
#include "src/audio_stored_fade.h"
#include "src/audio_loop_point.h"
#include "src/cry.h"
#include "src/matrix.h"
#include "src/memory.h"
#include "moves.h"
#include "pokemon.h"
#include "status.h"

static PokemonBattleCues sSide1BattleCues;
static PokemonBattleCues sSide2BattleCues;
static SpeciesModelTransform D_8438FF70;
static SpeciesModelTransform D_8438FF90;
static SpeciesModelTransform D_8438FFB0;
static SpeciesModelTransform D_8438FFD0;
static TagTeamPartners D_8438FFF0;
static TagTeamPartners D_84390000;
ActivePokemon* sActivePokemon[2];
ActivePokemon* sSide1ActivePokemon;
ActivePokemon* sSide2ActivePokemon;
static MovePresentationCue* sCurrentAnimation;
unk_D_84390028 D_84390028[2];
static SwayLayoutConfig sDefaultSwayLayout;
static BattleSceneStateTickSlot sBattleSceneStateTickSlots[7];
static s32 sBattleSceneStateTickSlotIndex;
static s32 D_843900A4;
f32 D_843900A8[2];

PokemonBattleCues* sSideBattleCues[] = { &sSide1BattleCues, &sSide2BattleCues };
SpeciesModelTransform* D_84384578[] = {
    &D_8438FF70,
    &D_8438FF90,
};
SpeciesModelTransform* D_84384580[] = {
    &D_8438FFB0,
    &D_8438FFD0,
};
TagTeamPartners* sPlayerTagTeam[] = { &D_8438FFF0, &D_84390000 };
u8 sPokemonWithAlternateSleepIdle[] = { PRIMEAPE, EXEGGUTOR, VOLTORB, KOFFING, WIGGLYTUFF, WEEZING, GOLBAT, VICTREEBEL };
static u8 sPokemonWithAlternateSleepHitReactions[] = { VOLTORB, WEEZING };
static u8 sPokemonWithNewHmInYellow[] = {
    CHARIZARD, BUTTERFREE, VENONAT, VENOMOTH, DIGLETT, DUGTRIO, KABUTOPS, MEWTWO, MEW,
};
// [0] = RedBlueByte, [1] = YellowByte
static u8 sCharizardLearnsFlyInYellow[] = {
    0x06,
    0x2E,
};
static u8 sButterfreeLearnsFlashInYellow[] = {
    0x06,
    0x42,
};
static u8 sVenonatLearnsFlashInYellow[] = {
    0x06,
    0x42,
};
static u8 sVenomothLearnsFlashInYellow[] = {
    0x06,
    0x42,
};
static u8 sDiglettLearnsCutInYellow[] = {
    0x06,
    0x06,
};
static u8 sDugtrioLearnsCutInYellow[] = {
    0x06,
    0x06,
};
static u8 sKabutopsLearnsCutInYellow[] = {
    0x06,
    0x16,
};
static u8 sMewtwoLearnsNothingNewInYellow[] = {
    0x01,
    0x7F,
};
static u8 sMewLearnsNothingNewInYellow[] = {
    0x06,
    0x7F,
};
static u8* sPokemonYellowHmAdditions[] = {
    sCharizardLearnsFlyInYellow, sButterfreeLearnsFlashInYellow, sVenonatLearnsFlashInYellow, sVenomothLearnsFlashInYellow, sDiglettLearnsCutInYellow, sDugtrioLearnsCutInYellow, sKabutopsLearnsCutInYellow, sMewtwoLearnsNothingNewInYellow, sMewLearnsNothingNewInYellow,
};
u8 D_843845F0 = 0x8E;
u8 D_843845F4 = 0x16;
u8 D_843845F8 = 0x53;
u8 D_843845FC[] = { 0x55, 0x54 };

char** sBattleMessagesTable;
char** sPokemonNameTable;
char** sMoveNameTable;
char** sStatusConditionNameTable;
char** sBattleControllerDisconnectedMessage; // Only one entry, hence not a table.

/**
 * Resets all seven state tick slots to the sentinel (no-op) callback.
 */
// called on any fade in battle
void BattleScene_ClearStateTickCallbacks(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        sBattleSceneStateTickSlots[i].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * Queues effect list 3 entry `effect_entry` on the actor's own display object
 * with no anchors (0xFF).
 */
// called on move select... sometimes. called on faint
void BattleScene_QueueRowEffectList3(ActivePokemon* actor, s32 effect_entry) {
    BattleAnim_QueueEffectList3(effect_entry, &actor->displayObject, &actor->displayObject, 0xFF, 0xFF);
}

/**
 * Queues the main move effect script for `move_id`, using the user's move
 * cue anchors and the opposing participant as the fallback owner.
 */
// played on gengar using thunderbolt in bug boy glc fight
void BattleAnim_PlayMoveEffectScript(ActivePokemon* user, s32 move_id) {
    UNUSED s16 pad;
    s16 camera_shot;
    s32 target_side_index;

    target_side_index = BattleScene_GetParticipantSideIndex(user) == 0;
    camera_shot = Battle_GetCameraShotFieldB(user);
    BattleAnim_QueueMoveEffectScript(move_id, user, sActivePokemon[target_side_index], camera_shot, Battle_GetCameraShotFieldC(user));
}

/**
 * Handles charing moves by routing to BattleAnim_SetQueuedEffectList in @src/fragments/battle_engine/battle_engine_309ED0.c
 * to which calls BattleAnim_SetQueuedEffectList unlike BattleAnim_QueueMoveEffectScript
 * Fury Swipes uses this function as a hack to allow it to both spawn the "slashing" animation of other slashing moves
 * while also being a mulithit attack.
 */
// guess: plays during changing moves like skull base
// but for some reason connected to fury swipes too?
void BattleAnim_PlayChargingMoveEffectScript(ActivePokemon* user, s32 move_id) {
    UNUSED s16 pad;
    s16 camera_shot;
    s32 target_side_index;

    target_side_index = BattleScene_GetParticipantSideIndex(user) == 0;
    camera_shot = Battle_GetCameraShotFieldB(user);
    BattleAnim_QueueChargingMoveEffectScript(move_id, user, sActivePokemon[target_side_index], camera_shot, Battle_GetCameraShotFieldC(user));
}

/**
 * Queues the end-of-move effect for `move_id` on the opposing participant,
 * anchored by the user's hit cue fields.
 */
// play on move end
void BattleAnim_PlayMoveEffectEnd(ActivePokemon* user, s32 move_id) {
    UNUSED s16 pad;
    s16 default_anchor; // TODO: more descriptive name
    s32 target_side;

    target_side = BattleScene_GetParticipantSideIndex(user) == 0;
    default_anchor = Battle_GetSideAnimTableFieldB(user);
    BattleAnim_QueueMoveEffectEnd(move_id, sActivePokemon[target_side], user, default_anchor, Battle_GetSideAnimTableFieldC(user));
}

/**
 * State tick: once the participant's assets are registered, resets its
 * animation timer and retires this tick slot.
 */
// play on move end
void BattleScene_TickClearAnimRecordIfLoaded(ActivePokemon* active_pokemon) {
    if (BattleAnim_TryRegisterAssetTables(active_pokemon) != 0) {
        active_pokemon->animationTimer = 0;
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * State tick: once assets are registered, starts the cue selected by the
 * current state row (event track, animation and frame 0) and retires the slot.
 */
// triggers on faint
void BattleScene_TickStartRowAnimRecord(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    s32 row_index = active_pokemon->animationState;
    s32 cue_index = sBattleSceneStateRowTable[row_index].unk_20;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[cue_index];
    if (BattleAnim_TryRegisterAssetTables(active_pokemon) != 0) {
        BattleAnim_SetModelEventTrackAndState(active_pokemon, cue_index, 2);
        active_pokemon->animationTimer = 0;
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
    }
}

/**
 * State tick: retires immediately when the model height is nonzero; otherwise waits for the
 * row cue's animation to finish and queues the row's effect list 3 entry.
 */
// trigger unknown
void BattleScene_TickQueueRowEffectList3AtAnimEnd(ActivePokemon* active_pokemon) {
    s32 row_index = active_pokemon->animationState;
    s32 cue_index = sBattleSceneStateRowTable[row_index].unk_20;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[cue_index];
    if (BattleScene_GetParticipantModelHeight(active_pokemon) != 0.0f) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    } else if ((active_pokemon->animationTimer == (sCurrentAnimation->animationDuration + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleScene_QueueRowEffectList3(active_pokemon, sBattleSceneStateRowTable[row_index].mode);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * Resets the participant's animation timer.
 */
// triggers on waiting for move selection
void BattleScene_ResetStateFrameCounter(ActivePokemon* active_pokemon) {
    active_pokemon->animationTimer = 0;
}

/**
 * Resets the opposing participant's animation timer.
 */
// trigger on up on the dialogue box disappearing after move use
void BattleScene_ResetOpponentStateFrameCounter(ActivePokemon* active_pokemon) {
    sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->animationTimer = 0;
}

/**
 * Sets render flag 0x2 on both participants for the rock-throwing moves
 * (Strength, Rock Slide, Rock Throw).
 */
// trigger on up on the dialogue box disappearing after move use
// used to animate moves that throw rocks
void BattleAnim_SetFlagForRockThrowingMoves(ActivePokemon* active_pokemon) {
    BattleMonRuntime* active_pokemon_runtime = &active_pokemon->state.runtime;

    if (active_pokemon_runtime->usedMove == STRENGTH || active_pokemon_runtime->usedMove == ROCK_SLIDE || active_pokemon_runtime->usedMove == ROCK_THROW) {
        sActivePokemon[0]->displayObject.node.renderFlags |= 2;
        sActivePokemon[1]->displayObject.node.renderFlags |= 2;
    }
}

/**
 * Clears render flag 0x2 on both participants.
 */
// triggers at the end of move animations and at the end of damage animation of using a rock throwing move
void BattleAnim_ClearRockThrowingMoveFlag(ActivePokemon* active_pokemon) {
    sActivePokemon[0]->displayObject.node.renderFlags &= ~2;
    sActivePokemon[1]->displayObject.node.renderFlags &= ~2;
}

/*
    Can only guess the semantic guess is correct
*/
/**
 * Returns the session's asset busy bits (mask 0xD0); nonzero while loading.
 */
s32 BattleAnim_IsAssetLoadBusy(ActivePokemon* active_pokemon) {
    return active_pokemon->sessionTeams->assetIsBusy & 0xD0;
}

/**
 * Polls the background icon load, then returns the asset busy bits (mask 0xC0).
 */
s32 BattleAnim_PollAssetLoadBusyFlags(ActivePokemon* active_pokemon) {
    PokeIcon_PollBackgroundForObject(active_pokemon->sessionTeams);
    return active_pokemon->sessionTeams->assetIsBusy & 0xC0;
}

/**
 * Returns the session's unique status busy bits (mask 0xD0).
 */
s32 BattleAnim_IsSessionBusy(ActivePokemon* active_pokemon) {
    return active_pokemon->sessionTeams->uniqueStatusFlags & 0xD0;
}

/**
 * Registers the session's animation asset tables once loading is idle.
 * Returns 1 if registered, 0 if still busy.
 */
s32 BattleAnim_TryRegisterAssetTables(ActivePokemon* active_pokemon) {
    if (BattleAnim_PollAssetLoadBusyFlags(active_pokemon) == 0) {
        BattleAnim_RegisterAssetTablesForSession(active_pokemon->sessionTeams);
        return 1;
    }
    return 0;
}

/**
 * Loads the resource list for the participant's active animation row.
 */
void BattleScene_LoadMoveResourceList(ActivePokemon* active_pokemon) {
    // FAKE
    if (sBattleScene.unk_00->unk_48 == 0xE) {
        BattleAnim_LoadMoveResourceList(active_pokemon->sessionTeams, BattleScene_GetActiveAnimRowId(active_pokemon));
    } else {
        BattleAnim_LoadMoveResourceList(active_pokemon->sessionTeams, BattleScene_GetActiveAnimRowId(active_pokemon));
    }
}

/**
 * Loads the resource list for the current state row's mode.
 */
void BattleScene_LoadRowResourceList(ActivePokemon* active_pokemon) {
    s32 row_index = active_pokemon->animationState;

    BattleAnim_LoadModeResourceList(active_pokemon->sessionTeams, sBattleSceneStateRowTable[row_index].mode);
}

/**
 * Loads the resource list for the participant's active animation row.
 */
void BattleScene_ReloadMoveResourceList(ActivePokemon* active_pokemon) {
    BattleAnim_LoadMoveResourceList(active_pokemon->sessionTeams, BattleScene_GetActiveAnimRowId(active_pokemon));
}

/**
 * Swaps the participant's display model to the Substitute doll and flags
 * the session for a model reload (0x80).
 */
void Battle_MakeSubstitute(ActivePokemon* active_pokemon) {
    active_pokemon->sessionTeams->displayModel = SUBSTITUTE_DOLL;
    active_pokemon->sessionTeams->uniqueStatusFlags |= 0x80;
}

/**
 * Restores the participant's real display model after Substitute breaks
 * and flags the session for a model reload (0x80).
 */
void BattleScene_DestroySubstitute(ActivePokemon* active_pokemon) {
    active_pokemon->sessionTeams->unk_04 = &active_pokemon->teamRoster->pokemonPicked[active_pokemon->state.rosterIndex];
    active_pokemon->sessionTeams->uniqueStatusFlags |= 0x80;
    active_pokemon->sessionTeams->displayModel = active_pokemon->state.model;
}

/**
 * Returns the index of `lookup_value` in `array`, or -1 if absent.
 */
s32 BattleScene_FindU16InByteArray(u16 lookup_value, u8* array, s32 array_length) {
    s32 lookup_result = 0;

    while (array_length--) {
        if (lookup_value == *array) {
            return lookup_result;
        }
        array++;
        lookup_result++;
    }

    return -1;
}

/**
 * Clears the illegality flag of every move slot that species `pokemon_id`
 * can legally know: starting moves, the Red/Blue-based and Yellow-based
 * learnsets (at or below the current level) and TM/HM compatibility, including
 * the Yellow HM additions.
 */
void Battle_MarkIllegalMoves(ActivePokemon* pokemon, u16 pokemon_id, SpeciesLearnsetBuffer* red_blue_learnset, SpeciesLearnsetBuffer* yellow_learnset) {
    s32 move_index;
    s32 i;
    s32 lookup;
    s32 tm_index;
    u8 tm_hm_flag;
    SpeciesData* species_data;
    BattleMonRuntime* pokemon_runtime;

    pokemon_runtime = &pokemon->state.runtime;

    for (move_index = 0; move_index < 4; move_index++) {
        if (pokemon_runtime->moves[move_index] != 0) {
            species_data = &gSpeciesData[pokemon_id];

            for (i = 0; i < ARRAY_COUNT(species_data->startingMoves); i++) {
                if ((species_data->startingMoves[i] != 0) && (species_data->startingMoves[i] == pokemon_runtime->moves[move_index])) {
                    pokemon->state.moveSlotIllegality[move_index] = 0;
                }
            }

            for (i = 0; i < 10; i++) {
                if ((red_blue_learnset->unk_00[i] != 0) && (pokemon_runtime->unk_26 >= red_blue_learnset->unk_00[i]) &&
                    (red_blue_learnset->unk_0A[i] == pokemon_runtime->moves[move_index])) {
                    pokemon->state.moveSlotIllegality[move_index] = 0;
                }
            }

            for (i = 0; i < 10; i++) {
                if ((yellow_learnset->unk_00[i] != 0) && (pokemon_runtime->unk_26 >= yellow_learnset->unk_00[i]) &&
                    (yellow_learnset->unk_0A[i] == pokemon_runtime->moves[move_index])) {
                    pokemon->state.moveSlotIllegality[move_index] = 0;
                }
            }

            // TM Move lookup
            for (i = 0; i < 55; i++) {
                lookup = BattleScene_FindU16InByteArray(pokemon_id + 1, sPokemonWithNewHmInYellow, 9);
                if (lookup >= 0) {
                    tm_index = i / 8;
                    if (tm_index == sPokemonYellowHmAdditions[lookup][0]) {
                        tm_hm_flag = species_data->tmHmLearnset[tm_index] | sPokemonYellowHmAdditions[lookup][1];
                    } else {
                        tm_hm_flag = species_data->tmHmLearnset[tm_index];
                    }
                } else {
                    tm_hm_flag = species_data->tmHmLearnset[i / 8];
                }

                if (((tm_hm_flag >> (i % 8)) & 1) && (Move_GetIdFromTableIndex(i) == pokemon_runtime->moves[move_index])) {
                    pokemon->state.moveSlotIllegality[move_index] = 0;
                }
            }
        } else {
            pokemon->state.moveSlotIllegality[move_index] = 0;
        }
    }
}

/**
 * Marks all four move slots illegal, then clears the flags of moves that the
 * species or either tag-team partner species can learn.
 */
void Battle_InitializeMoveIllegalityMask(ActivePokemon* active_pokemon) {
    active_pokemon->state.moveSlotIllegality[0] = 1;
    active_pokemon->state.moveSlotIllegality[1] = 1;
    active_pokemon->state.moveSlotIllegality[2] = 1;
    active_pokemon->state.moveSlotIllegality[3] = 1;

    Battle_MarkIllegalMoves(active_pokemon, active_pokemon->state.runtime.id - 1, &active_pokemon->redBlueLearnsets[0], &active_pokemon->yellowLearnsets[0]);

    if (sPlayerTagTeam[BattleScene_GetParticipantSideIndex(active_pokemon)]->firstPartner != 0) {
        Battle_MarkIllegalMoves(active_pokemon, sPlayerTagTeam[BattleScene_GetParticipantSideIndex(active_pokemon)]->firstPartner - 1, &active_pokemon->redBlueLearnsets[1], &active_pokemon->yellowLearnsets[1]);
    }

    if (sPlayerTagTeam[BattleScene_GetParticipantSideIndex(active_pokemon)]->secondPartner != 0) {
        Battle_MarkIllegalMoves(active_pokemon, sPlayerTagTeam[BattleScene_GetParticipantSideIndex(active_pokemon)]->secondPartner - 1, &active_pokemon->redBlueLearnsets[2], &active_pokemon->yellowLearnsets[2]);
    }
}

/**
 * DMAs the 0x20-byte level-up learnset record for 1-based `species` from the
 * Red/Blue-based learnset table into `destination`.
 */
void Battle_DmaLoadLevelUpLearnset(u8 species, u32 destination) {
    u32 buffer_start = (u32)_70D3A0_ROM_START + ((u32)&D_72780[species - 1] & 0xFFFFFF);

    Dma_WriteChunks(destination, buffer_start, buffer_start + 0x20, 0);
}

/**
 * DMAs the Red/Blue-based and Yellow-based 0x20-byte learnset records for
 * 0-based `species_index` into their corresponding buffers.
 */
void Battle_DmaLoadSpeciesLearnsets(s32 species_index, SpeciesLearnsetBuffer* red_blue_learnset, SpeciesLearnsetBuffer* yellow_learnset) {
    UNUSED s32 pad[3];
    u32 buffer_start;

    buffer_start = (u32)_70D3A0_ROM_START + ((u32)&D_72780[species_index] & 0xFFFFFF);
    Dma_WriteChunks(red_blue_learnset, buffer_start, buffer_start + 0x20, 0);
    buffer_start = (u32)_70D3A0_ROM_START + ((u32)&D_73A60[species_index] & 0xFFFFFF);
    Dma_WriteChunks(yellow_learnset, buffer_start, buffer_start + 0x20, 0);
}

// D_80075BD0 holds one PokemonBattleCues ROM offset per species (indexed species - 1);
// the entry after SUBSTITUTE_DOLL is the partner Pikachu cue bank.
#define PARTNER_PIKACHU_CUE_BANK 152
/**
 * Loads the species presentation data for a participant: its cue bank
 * (the partner Pikachu bank when applicable), model transforms, sway layout,
 * side position record, tag-team partners and learnsets. Optionally rebuilds
 * the move illegality mask.
 *
 * Also triggers on using Transform
 */
void Battle_LoadAnimationAndMarkMoveIllegality(ActivePokemon* pokemon, s32 mark_move_illegality) {
    s16 linked_record_id;
    s32 side_index;
    s16 species;
    u32 rom_address;
    UNUSED s32 pad[8];
    BattleMon* battle_mon;
    SpeciesModelTransform* model_transform;
    u32 transform_end;

    side_index = BattleScene_GetParticipantSideIndex(pokemon);
    species = pokemon->displayObject.objectType - 1;

    battle_mon = &pokemon->sessionTeams->teamMember[pokemon->state.unk_2C]->pokemonPicked[pokemon->state.unk_18];

    rom_address = (u32)_70D3A0_ROM_START + ((u32)D_80075BD0[species] & 0xFFFFFF);
    if ((pokemon->displayObject.objectType == PIKACHU) && (battle_mon->unk_52 & 0x80)) {
        rom_address = (u32)_70D3A0_ROM_START + ((u32)D_80075BD0[PARTNER_PIKACHU_CUE_BANK] & 0xFFFFFF);
    }
    transform_end = ((u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (species << 5)) & 0xFFFFFF)) + 0x20;
    Dma_WriteChunks(sSideBattleCues[side_index], rom_address, rom_address + 0xBC0, 0);

    rom_address = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (species << 5)) & 0xFFFFFF);
    Dma_WriteChunks(D_84384580[side_index], rom_address, transform_end, 0);

    if (side_index == 1) {
        rom_address = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (species << 5)) & 0xFFFFFF);
        Dma_WriteChunks(D_84384578[side_index], rom_address, rom_address + 0x20, 0);

        model_transform = D_84384578[side_index];
        if (model_transform->unk_10 != 0xFF) {
            linked_record_id = model_transform->unk_10;

            // FAKE: transform_end is reused as a scratch temp to match register allocation
            rom_address = ((u32)_70D3A0_ROM_START) + (((u32)(D_6E910 + ((model_transform->unk_10 - (transform_end = 2)) * 0x20))) & 0xFFFFFF);
            Dma_WriteChunks(model_transform, rom_address, rom_address + 0x20, 0);

            D_84384578[side_index]->unk_10 = linked_record_id;
        }
    } else {
        rom_address = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (species << 5)) & 0xFFFFFF);
        Dma_WriteChunks(D_84384578[side_index], rom_address, rom_address + 0x20, 0);
    }

    rom_address = (u32)_70D3A0_ROM_START + ((u32)(D_70B10 + (species * 0x20)) & 0xFFFFFF);
    Dma_WriteChunks(&sDefaultSwayLayout, rom_address, rom_address + 0x20, 0);

    BattleAnim_Vec3fCopy(&pokemon->swayState.layoutConfig.frontCameraShotOffset, &sDefaultSwayLayout.frontCameraShotOffset);
    BattleAnim_Vec3fCopy(&pokemon->swayState.layoutConfig.backCameraShotOffset, &sDefaultSwayLayout.backCameraShotOffset);

    // If you zero these 4 attributes out the game soft locks
    pokemon->swayState.layoutConfig.unk_18 = sDefaultSwayLayout.unk_18;
    pokemon->swayState.layoutConfig.unk_19 = sDefaultSwayLayout.unk_19;
    pokemon->swayState.layoutConfig.unk_1A = sDefaultSwayLayout.unk_1A;
    pokemon->swayState.layoutConfig.unk_1B = sDefaultSwayLayout.unk_1B;
    pokemon->swayState.layoutConfig.frontCameraShotOffset.x *= pokemon->cameraOffsetScaleFactor;
    pokemon->swayState.layoutConfig.backCameraShotOffset.x *= pokemon->cameraOffsetScaleFactor;

    rom_address = (u32)_70D3A0_ROM_START + ((u32)(D_70110 + (species << 4)) & 0xFFFFFF);
    Dma_WriteChunks(&D_84390028[side_index], rom_address, rom_address + 0x10, 0);

    rom_address = (u32)_70D3A0_ROM_START + ((u32)(D_71E10 + (species * 0x10)) & 0xFFFFFF);
    Dma_WriteChunks(sPlayerTagTeam[side_index], rom_address, rom_address + 0x10, 0);

    Battle_DmaLoadSpeciesLearnsets(species, &pokemon->redBlueLearnsets[0], &pokemon->yellowLearnsets[0]);

    if (sPlayerTagTeam[side_index]->firstPartner != 0) {
        Battle_DmaLoadSpeciesLearnsets(sPlayerTagTeam[side_index]->firstPartner - 1, &pokemon->redBlueLearnsets[1], &pokemon->yellowLearnsets[1]);
    }

    if (sPlayerTagTeam[side_index]->secondPartner != 0) {
        Battle_DmaLoadSpeciesLearnsets(sPlayerTagTeam[side_index]->secondPartner - 1, &pokemon->redBlueLearnsets[2], &pokemon->yellowLearnsets[2]);
    }

    if (mark_move_illegality == 1) {
        Battle_InitializeMoveIllegalityMask(pokemon);
    }
}

/**
 * State row 10 tick: requests a model reload at frame 20; once it completes,
 * loads the switch-in owner model, frames the camera and enters state row 18.
 */
void BattleScene_TickRow10CleanupAndEnterState18(ActivePokemon* active_pokemon) {
    if (active_pokemon->animationTimer == 20) {
        active_pokemon->sessionTeams->uniqueStatusFlags |= 0x80;
    }

    if (active_pokemon->sessionTeams->uniqueStatusFlags & 0x10) {
        active_pokemon->sessionTeams->uniqueStatusFlags &= ~0x90;
        Battle_LoadOwnerModelForSwitchIn(active_pokemon);
        BattleScene_TickOwnerCameraFraming(active_pokemon);
        Audio_PlayCommand(2, 0, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        BattleScene_EnterStateRow(active_pokemon, 18);
    }
}

#define DIGLETT_OB1 (DIGLETT - 1)
#define DUGTRIO_OB1 (DUGTRIO - 1)
/**
 * State row 3 enter: plays the move's species sound, clears flag 0x4000
 * for Diglett/Dugtrio (showing the model), and starts the move cue animation and event track.
 */
// Think this has to do with Surf's Animation
void BattleScene_EnterRow3StartMoveAnim(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    ActivePokemonState* pokemon_state;
    s32 side_index;
    s16 species_ob1;
    u8 side_byte;

    species_ob1 = active_pokemon->displayObject.objectType - 1;
    runtime = &active_pokemon->state.runtime;
    pokemon_state = &active_pokemon->state;
    side_index = BattleScene_GetParticipantSideIndex(active_pokemon);

    sCurrentAnimation = &sSideBattleCues[side_index]->moveCues[runtime->usedMove - 1];

    if (!(pokemon_state->flags & ACTIVE_FREEZE)) {
        active_pokemon->animationTimer = 0;

        if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            side_byte = BattleScene_GetParticipantSideIndex(active_pokemon);
            func_80048060(side_byte, runtime->usedMove, PARTNER_PIKACHU, 0);
        } else {
            side_byte = BattleScene_GetParticipantSideIndex(active_pokemon);
            func_80048060(side_byte, runtime->usedMove, species_ob1 + 1, 0);
        }

        if ((pokemon_state->flags & ACTIVE_UNDERGROUND) && ((species_ob1 == DUGTRIO_OB1) || (species_ob1 == DIGLETT_OB1))) {
            Battle_ClearRuntimeFlags(active_pokemon, 8);
            active_pokemon->displayObject.node.renderFlags |= 0x20;
            Battle_SetRuntimeFlags(active_pokemon, 0x10);
            Battle_ClearRuntimeFlags(active_pokemon, 0x4000);
        }

        BattleAnim_SetFlagForRockThrowingMoves(active_pokemon);
        ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
        BattleAnim_SetModelEventTrackFromRow(active_pokemon, runtime->usedMove - 1);

        if (sCurrentAnimation->animationTimer != 0) {
            ModelAnim_SetFrame(&active_pokemon->displayObject, sCurrentAnimation->animationTimer);
            ModelAnim_SetEventFrame(&active_pokemon->displayObject, sCurrentAnimation->animationTimer);
            active_pokemon->animationTimer = sCurrentAnimation->animationTimer;
        } else {
            ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        }
    }
}

// Because this function has an off by 1 in species, these defines make it much more clear what it does
#define ELECTRODE_OB1 (ELECTRODE - 1)
#define SQUIRTLE_OB1 (SQUIRTLE - 1)
#define WARTORTLE_OB1 (WARTORTLE - 1)
#define BLASTOISE_OB1 (BLASTOISE - 1)
#define CLOYSTER_OB1  (CLOYSTER - 1)
/**
 * State row 3 tick: when the move cue animation ends, applies move-specific
 * model flags and queues the move effect script.
 */
void BattleScene_TickRow3PlayMoveEffectScript(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    s16 species = active_pokemon->displayObject.objectType - 1;
    BattleMonRuntime* pokemon_runtime;

    BattleScene_GetParticipantSideIndex(active_pokemon);
    pokemon_runtime = &active_pokemon->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[pokemon_runtime->usedMove - 1];

    // Special exception: if Electrode uses Mega Kick it uses its animation doesn't spawn the "kick" particle
    // Electrode just headbutts (might be a unique animation?)
    // Note: Electrode can't actually learn Mega Kick, might be for in case it uses Mimic
    if ((pokemon_runtime->usedMove == MEGA_KICK) && (species == ELECTRODE_OB1)) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    } else if ((active_pokemon->animationTimer == (sCurrentAnimation->animationDuration + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        if (sBattleScene.unk_00->unk_48 == 20) {
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        } else if (pokemon_runtime->moveCache.lastMove == DIG) {
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        } else {
            if (pokemon_runtime->moveCache.lastMove == WITHDRAW) {
                // Special Withdraw Animations
                if ((species != WARTORTLE_OB1) && (species != BLASTOISE_OB1) && (species != CLOYSTER_OB1) && (species != SQUIRTLE_OB1)) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 12, 0);
                    BattleAnim_PlayMoveEffectScript(active_pokemon, pokemon_runtime->usedMove);
                }
            } else {
                if (pokemon_runtime->moveCache.lastMove == SEISMIC_TOSS) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 8, 0);
                } else if (pokemon_runtime->moveCache.lastMove == SURF) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 10, 0);
                } else if (pokemon_runtime->moveCache.lastMove == MEDITATE) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 13, 0);
                } else if (pokemon_runtime->moveCache.lastMove == WATERFALL) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 14, 0);
                } else if (pokemon_runtime->moveCache.lastMove == MINIMIZE) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 9, 0);
                } else {
                    BattleScene_SetParticipantModelFlags(active_pokemon, sCurrentAnimation->flags1, 0);
                }

                // If Fury Swipe uses BattleAnim_PlayMoveEffectScript instead, the "screen slashing" animation of the move doesn't play
                if ((pokemon_runtime->usedMove == FURY_SWIPES) && (sMultihitCountdown == sMultihitCount)) {
                    BattleAnim_PlayChargingMoveEffectScript(active_pokemon, pokemon_runtime->usedMove);
                } else {
                    BattleAnim_PlayMoveEffectScript(active_pokemon, pokemon_runtime->usedMove);
                }
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

/**
 * State row 3 tick: when the move cue animation ends, plays the species
 * reaction sound (failure, multi-hit or normal), camera shake for Growl, Roar
 * and Earthquake, and Harden's golden material.
 */
void BattleScene_TickRow3PostEffectCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];

    if (active_pokemon->animationTimer == (sCurrentAnimation->animationDuration + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (sBattleScene.unk_00->unk_48 == 24) {
                D_84390234--;
                if (D_84390234 < 0) {
                    if (sBattleMoveFailed != 0) {
                        BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 2);
                    }
                } else {
                    BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 3);
                }
            } else if (sBattleMoveFailed != 0) {
                BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 2);
            } else {
                if ((runtime->usedMove == GROWL) || (runtime->usedMove == ROAR) || (runtime->usedMove == EARTHQUAKE)) {
                    BattleScene_StartCameraShake(active_pokemon);
                }
                BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 0);
                BattleScene_MakeGoldenWhenHarden(active_pokemon);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

/**
 * When the move cue reaches its stat-effect frame, queues the stat-raise
 * particle effect and sound for self-boosting moves.
 */
void Battle_HandleStatBoostingMoveAnimation(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;
    UNUSED s16 pad;
    s16 move;

    move = runtime->usedMove;
    BattleScene_GetParticipantSideIndex(active_pokemon);
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];

    if (active_pokemon->animationTimer == (sCurrentAnimation->unk_09 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (((move == GROWTH) || (move == MEDITATE) || (move == AGILITY) || (move == HARDEN) || (move == WITHDRAW) ||
                 (move == SWORDS_DANCE) || (move == DOUBLE_TEAM) || (move == MINIMIZE) || (move == DEFENSE_CURL) || (move == BARRIER) ||
                 (move == AMNESIA) || (move == ACID_ARMOR) || (move == SHARPEN)) &&
                (sStatCanBeLoweredFurther == 1)) {
                BattleAnim_QueueEffectList6(3, active_pokemon);
                Audio_PlayCommand(35, 0, 0);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

/**
 * Switches the model to its golden material while Harden is used.
 */
void BattleScene_MakeGoldenWhenHarden(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];

    if (runtime->usedMove == HARDEN) {
        Model_SetMaterialTextureMode(&active_pokemon->displayObject, 1);
    }
}

/**
 * State row 21 enter: clears flag 0x4000 for Diglett/Dugtrio and starts move
 * cue 0 with its event track.
 */
void BattleScene_EnterRow21StartAnimRecord0(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    ActivePokemonState* active_pokemon_state = &active_pokemon->state;
    s16 species_ob1;

    species_ob1 = active_pokemon->displayObject.objectType - 1;
    sCurrentAnimation = sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues;

    if (!(active_pokemon_state->flags & ACTIVE_FREEZE)) {
        active_pokemon->animationTimer = 0;
        if ((active_pokemon_state->flags & ACTIVE_UNDERGROUND) && ((species_ob1 == DUGTRIO_OB1) || (species_ob1 == DIGLETT_OB1))) {
            Battle_ClearRuntimeFlags(active_pokemon, 8);
            active_pokemon->displayObject.node.renderFlags |= 0x20;
            Battle_SetRuntimeFlags(active_pokemon, 0x10);
            Battle_ClearRuntimeFlags(active_pokemon, 0x4000);
        }
        ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
        ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        BattleAnim_SetModelEventTrackFromRow(active_pokemon, 4);

        if (sCurrentAnimation->animationTimer != 0) {
            ModelAnim_SetFrame(&active_pokemon->displayObject, sCurrentAnimation->animationTimer);
            ModelAnim_SetEventFrame(&active_pokemon->displayObject, sCurrentAnimation->animationTimer);
            active_pokemon->animationTimer = sCurrentAnimation->animationTimer;
        } else {
            ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        }
    }
}

/**
 * State row 21 tick: when move cue 0 ends, plays the species sound.
 */
void BattleScene_TickRow21PlaySpeciesSound(ActivePokemon* active_pokemon) {
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[0];
    if ((active_pokemon->animationTimer == (sCurrentAnimation->animationDuration + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        func_800479C0(1, active_pokemon->displayObject.objectType, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * State row 19 enter: resumes the move cue animation from its start frame
 * (unk_06) instead of frame 0.
 */
void BattleScene_EnterRow19StartMoveAnimMidFrame(ActivePokemon* active_pokemon) {
    ActivePokemonState* pokemon_state;
    BattleMonRuntime* runtime;

    pokemon_state = &active_pokemon->state;
    runtime = &active_pokemon->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];

    if (pokemon_state->flags & ACTIVE_FREEZE) {
        return;
    }

    active_pokemon->animationTimer = sCurrentAnimation->unk_06;
    if (!(pokemon_state->flags & ACTIVE_UNDERGROUND)) {
        BattleAnim_SetFlagForRockThrowingMoves(active_pokemon);
        ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
        ModelAnim_SetFrame(&active_pokemon->displayObject, sCurrentAnimation->unk_06);
        if (sCurrentAnimation->unk_01 != 0xFF) {
            ModelAnim_SetEventTrack(&active_pokemon->displayObject, sCurrentAnimation->unk_01);
            ModelAnim_SetEventFrame(&active_pokemon->displayObject, sCurrentAnimation->unk_06);
            pokemon_state->unk_36 = 1;
        }
    }
}

/**
 * State row 19 tick: when the move cue ends (Fury Swipes waits 30 frames),
 * queues the move effect script and applies move-specific model flags.
 */
void BattleScene_TickRow19PlayMoveEffectScript(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    s32 animation_duration;

    runtime = &active_pokemon->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];
    if (runtime->usedMove == FURY_SWIPES) {
        animation_duration = sCurrentAnimation->animationDuration + 30;
    } else {
        animation_duration = sCurrentAnimation->animationDuration + 1;
    }

    if ((animation_duration == active_pokemon->animationTimer) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        if (sBattleScene.unk_00->unk_48 == 20) {
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
            return;
        }

        if ((runtime->usedMove == FURY_SWIPES) && (sMultihitCountdown == sMultihitCount)) {
            BattleAnim_PlayChargingMoveEffectScript(active_pokemon, runtime->usedMove);
        } else {
            BattleAnim_PlayMoveEffectScript(active_pokemon, runtime->usedMove);
        }

        if (runtime->moveCache.lastMove == SEISMIC_TOSS) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 8, 0);
        } else if (runtime->moveCache.lastMove == SURF) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 10, 0);
        } else {
            BattleScene_SetParticipantModelFlags(active_pokemon, sCurrentAnimation->flags1, 0);
        }
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * State row 19 tick: when the move cue ends, plays the species reaction sound
 * for failure, multi-hit or normal results.
 */
void BattleScene_TickRow19PostEffectCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    s32 animation_duration;

    runtime = &active_pokemon->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];

    if (runtime->usedMove == FURY_SWIPES) {
        animation_duration = sCurrentAnimation->animationDuration + 30;
    } else {
        animation_duration = sCurrentAnimation->animationDuration + 1;
    }

    if (animation_duration == active_pokemon->animationTimer) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (sBattleScene.unk_00->unk_48 == 24) {
                D_84390234--;
                if (D_84390234 < 0) {
                    if (sBattleMoveFailed != 0) {
                        BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 2);
                    } else {
                        BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 0);
                    }
                } else {
                    BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 3);
                }
            } else if (sBattleMoveFailed != 0) {
                BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 2);
            } else {
                BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 0);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

/**
 * State row 4 enter: picks and starts the target's hit reaction cue from
 * type effectiveness and status (idle when resisted or failed, variants for
 * flags 0x1/0x200), and plays the partner Pikachu effectiveness cries.
 */
void BattleScene_StartHitReactionAnim(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[3];
    s32 target_side;
    ActivePokemonState* target_state;
    UNUSED s32 pad2;
    s32 has_alternate_hit;
    BattleMonRuntime* runtime;
    ActivePokemon* target;

    runtime = &active_pokemon->state.runtime;
    target_side = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    target_state = &sActivePokemon[target_side]->state;
    target = sActivePokemon[target_side];
    sCurrentAnimation = &sSideBattleCues[target_side]->hitCue;

    if (target_state->flags & ACTIVE_SLEEP) {
        has_alternate_hit = BattleScene_ByteArrayContains(target->displayObject.objectType, sPokemonWithAlternateSleepHitReactions, 2);
        if (has_alternate_hit != 0) {
            sCurrentAnimation = &sSideBattleCues[target_side]->hitReactionOverride;
        }
    }

    sActivePokemon[target_side]->animationTimer = 0;

    if (!(target_state->flags & ACTIVE_AIRBORNE) && !(target_state->flags & ACTIVE_UNDERGROUND) && !(target_state->flags & ACTIVE_FREEZE)) {
        // no battle reaction for weak hits
        if (((sTypeEffectiveness < TYPE_EFFECTIVENESS_NEUTRAL) || (sBattleMoveFailed != 0)) && ((runtime->unk_15 & 0x20) == 0)) {
            sCurrentAnimation = &sSideBattleCues[target_side]->idleCues;
            if (target_state->flags & ACTIVE_AIRBORNE) {
                sCurrentAnimation = &sSideBattleCues[target_side]->unk_B00;
            }
        } else if (!(target_state->flags & ACTIVE_SLEEP)) {
            BattleAnim_SetModelEventTrackAndState(sActivePokemon[target_side], BATTLE_CUE_HIT, 1);
        }

        if ((sTypeEffectiveness > TYPE_EFFECTIVENESS_NEUTRAL) && (BattleScene_IsPartnerPikachu(sActivePokemon[target_side]) != 0)) {
            Cry_Play(PARTNER_PIKACHU, 6);
        }

        if ((sTypeEffectiveness == TYPE_EFFECTIVENESS_NEUTRAL) && (BattleScene_IsPartnerPikachu(sActivePokemon[target_side]) != 0)) {
            Cry_Play(PARTNER_PIKACHU, 5);
        }

        if ((sBattleMoveFailed == 0) && (runtime->usedMove == LEECH_SEED)) {
            sCurrentAnimation = &sSideBattleCues[target_side]->hitCue;
        }

        ModelAnim_SetFrame(&sActivePokemon[target_side]->displayObject, 0);
        ModelAnim_SetAnimation(&sActivePokemon[target_side]->displayObject, sCurrentAnimation->id);

        // These moves distort the target's body a bit
        if ((runtime->moveCache.lastMove == STOMP) || (runtime->moveCache.lastMove == BODY_SLAM) || (runtime->moveCache.lastMove == SEISMIC_TOSS)) {
            BattleScene_SetParticipantModelFlags(sActivePokemon[target_side], 0x0F, 0);
        }
    }
}

/**
 * Handles animation for "lasso" moves
 * cleans up effects and queues the end-of-move effect on the target.
 */
void BattleScene_HandleLassoMoves(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    s32 side;

    runtime = &active_pokemon->state.runtime;
    side = BattleScene_GetParticipantSideIndex(active_pokemon);

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->moveCues[runtime->usedMove - 1];

    if (sActivePokemon[side == 0]->animationTimer == (sCurrentAnimation->endFrame + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            BattleAnim_CleanupEffects(1);
            if (runtime->moveCache.lastMove == STRING_SHOT) {
                if ((sStatCanBeLoweredFurther != 0) && (sConfused != 0)) {
                    BattleAnim_PlayMoveEffectEnd(sActivePokemon[side == 0], runtime->usedMove);
                    BattleScene_SetParticipantModelFlags(sActivePokemon[side == 0], 16, 0);
                }
            } else {
                BattleAnim_PlayMoveEffectEnd(sActivePokemon[side == 0], runtime->usedMove);
                if ((runtime->moveCache.lastMove == BIND) || (runtime->moveCache.lastMove == WRAP) || (runtime->moveCache.lastMove == CONSTRICT)) {
                    BattleScene_SetParticipantModelFlags(sActivePokemon[side == 0], 16, 0);
                }
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

/**
 * State row 4 tick: when the target reaches the move cue's end frame,
 * plays the target's reaction sound.
 */
void BattleScene_TickRow4PostEndCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    s32 side;

    side = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    runtime = &active_pokemon->state.runtime;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->moveCues[runtime->usedMove - 1];

    if ((sCurrentAnimation->endFrame + 1) == sActivePokemon[side]->animationTimer) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (sConfused == 1) {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[side], runtime, 1);
            } else {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[side], runtime, 5);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

/**
 * State row 15 enter: starts the hit cue animation with its event track and
 * plays battle sound 30.
 */
void BattleScene_EnterRow15StartAnimA80Seq30(ActivePokemon* active_pokemon) {
    s32 side_index = BattleScene_GetParticipantSideIndex(active_pokemon);

    sCurrentAnimation = &sSideBattleCues[side_index]->hitCue;
    sActivePokemon[side_index]->animationTimer = 0;
    ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
    ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
    BattleAnim_SetModelEventTrackAndState(sActivePokemon[side_index], BATTLE_CUE_HIT, 1);
    BattleAnim_PlayBattleSequenceById(active_pokemon, 30);
}

/**
 * Returns 1 when the timer reaches the checkpoint frame (unk_0C) of the move
 * cue for the opposing participant's used move.
 */
s32 BattleScene_IsOpponentRowCheckpointReached(ActivePokemon* active_pokemon) {
    BattleMonRuntime* opponent_runtime;

    opponent_runtime = &sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[opponent_runtime->usedMove - 1];
    if (sCurrentAnimation->checkpointFrame != 0) {
        if (active_pokemon->animationTimer == sCurrentAnimation->checkpointFrame) {
            return 1;
        }
        return 0;
    }
    return 0;
}

/**
 * Returns 1 when the timer reaches the checkpoint frame (unk_0C) of move cue 0.
 */
s32 BattleScene_IsRowZeroCheckpointReached(ActivePokemon* active_pokemon) {
    BattleScene_GetParticipantSideIndex(active_pokemon);
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[0];
    if (sCurrentAnimation->checkpointFrame != 0) {
        if (active_pokemon->animationTimer == sCurrentAnimation->checkpointFrame) {
            return 1;
        }
        return 0;
    }
    return 0;
}

/**
 * Starts the hit cue animation and event track from frame 0.
 */
void BattleScene_StartHitCueAnimation(ActivePokemon* active_pokemon) {
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->hitCue;
    BattleAnim_SetModelEventTrackFromRow(active_pokemon, BATTLE_CUE_HIT);
    active_pokemon->animationTimer = 0;
    ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
    ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
}

/**
 * State row enter: starts the row's cue (sleep or flag 0x200 variants
 * when applicable) and plays the matching species sound.
 */
void BattleScene_EnterRowAnim166WithCry(ActivePokemon* active_pokemon) {
    s32 row_index = active_pokemon->animationState;
    s32 frozen_flag;
    s32 cue_index;
    BattleMon* party_pokemon;
    ActivePokemonState* pokemon_state;

    cue_index = sBattleSceneStateRowTable[row_index].unk_20;
    party_pokemon = &active_pokemon->teamRoster->pokemonPicked[active_pokemon->state.rosterIndex];
    pokemon_state = &active_pokemon->state;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[cue_index];
    frozen_flag = pokemon_state->flags & ACTIVE_FREEZE;

    if ((frozen_flag == 0) && !(pokemon_state->flags & ACTIVE_UNDERGROUND) && (frozen_flag == 0)) {
        if (party_pokemon->statusCondition & 7) {
            if (BattleScene_ByteArrayContains(active_pokemon->displayObject.objectType, sPokemonWithAlternateSleepIdle, 8) != 0) {
                sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->sleepIdleCue;
            } else {
                sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->idleCues;
            }
        } else if (pokemon_state->flags & ACTIVE_AIRBORNE) {
            sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_B00;
        }

        ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);

        if (pokemon_state->flags & ACTIVE_AIRBORNE) {
            if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, PARTNER_PIKACHU, 26);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 26);
            }
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, PARTNER_PIKACHU, 10);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 10);
        }
    }
}

/**
 * State row 1 tick: on frame 1 plays the cry (the real species while behind
 * a Substitute), unless flag 0x4000 or the freeze flag (0x2) is set
 * or the Pokemon is asleep (status & 7).
 */
void BattleScene_TickRow1PlayOwnerCry(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    ActivePokemonState* state = &active_pokemon->state;
    BattleMon* party_pokemon_ptr = &active_pokemon->teamRoster->pokemonPicked[active_pokemon->state.rosterIndex];

    if ((state->flags & ACTIVE_UNDERGROUND) || (state->flags & ACTIVE_FREEZE) || (party_pokemon_ptr->statusCondition & STATUS_SLEEP_MASK)) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    } else if (active_pokemon->animationTimer == 1) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (active_pokemon->displayObject.objectType >= SUBSTITUTE_DOLL) {
                BattleAnim_PlayOwnerCry(active_pokemon, state->model);
            } else {
                BattleAnim_PlayOwnerCry(active_pokemon, active_pokemon->displayObject.objectType);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

/**
 * State row 16 tick: on frame 1 plays cry mode 3 and the matching species
 * sound, unless flag 0x4000 or the freeze flag (0x2) is set
 * or the Pokemon is asleep (status & 7).
 */
void BattleScene_TickRow16PlayCryAndSpeciesSound(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    BattleMon* party_pokemon_ptr = &active_pokemon->teamRoster->pokemonPicked[active_pokemon->state.rosterIndex];
    ActivePokemonState* state = &active_pokemon->state;

    if ((active_pokemon->state.flags & ACTIVE_UNDERGROUND) || (state->flags & ACTIVE_FREEZE) || (party_pokemon_ptr->statusCondition & 7)) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    } else if ((active_pokemon->animationTimer == 1) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        if (active_pokemon->displayObject.objectType >= SUBSTITUTE_DOLL) {
            Cry_Play(state->model, 3);
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            Cry_Play(PARTNER_PIKACHU, 3);
        } else {
            Cry_Play(active_pokemon->displayObject.objectType, 3);
        }

        if (state->flags & ACTIVE_AIRBORNE) {
            if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, PARTNER_PIKACHU, 27);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 27);
            }
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, PARTNER_PIKACHU, 11);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 11);
        }
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * State row 18 tick: on frame 1 plays cry mode 4 and the matching species
 * sound, unless flag 0x4000 is set or the Pokemon is frozen
 * (status & 0x20) or asleep (status & 7).
 */
void BattleScene_TickRow18PlayCryAndSpeciesSound(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    BattleMon* party_pokemon_ptr = &active_pokemon->teamRoster->pokemonPicked[active_pokemon->state.rosterIndex];
    ActivePokemonState* state;

    if ((active_pokemon->state.flags & ACTIVE_UNDERGROUND) || (party_pokemon_ptr->statusCondition & STATUS_FREEZE) || (party_pokemon_ptr->statusCondition & 7)) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        return;
    }

    if ((active_pokemon->animationTimer == 1) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        state = &active_pokemon->state;
        if (active_pokemon->displayObject.objectType >= SUBSTITUTE_DOLL) {
            Cry_Play(state->model, 4);
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            Cry_Play(PARTNER_PIKACHU, 4);
        } else {
            Cry_Play(active_pokemon->displayObject.objectType, 4);
        }

        if (state->flags & ACTIVE_AIRBORNE) {
            if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, PARTNER_PIKACHU, 27);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 27);
            }
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, PARTNER_PIKACHU, 11);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 11);
        }

        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * State tick: once assets are registered, restores the display model,
 * queues the row's effect list 3 entry and rebinds the session's Pokemon.
 */
void BattleScene_TickAssetLoadQueueRowEffectList3(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    s32 animation_state = active_pokemon->animationState;
    ActivePokemonState* pokemon_state = &active_pokemon->state;

    if (BattleAnim_TryRegisterAssetTables(active_pokemon) != 0) {
        active_pokemon->sessionTeams->displayModel = active_pokemon->state.runtime.id;
        active_pokemon->animationTimer = 0;
        BattleScene_QueueRowEffectList3(active_pokemon, sBattleSceneStateRowTable[animation_state].mode);
        Audio_PlayCommand(3, 0, 0);
        active_pokemon->sessionTeams->unk_04 = &active_pokemon->sessionTeams->teamMember[pokemon_state->unk_2B]->pokemonPicked[pokemon_state->unk_18];
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * State tick: on frame 1, queues the row's effect list 3 entry and sound 3.
 * Not referenced by any state row.
 */
void BattleScene_TickQueueRowEffectList3OnFirstFrame(ActivePokemon* active_pokemon) {
    BattleScene_GetParticipantSideIndex(active_pokemon);
    if ((active_pokemon->animationTimer == 1) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        s32 row_index = active_pokemon->animationState;

        BattleScene_QueueRowEffectList3(active_pokemon, sBattleSceneStateRowTable[row_index].mode);
        Audio_PlayCommand(3, 0, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * State row 20 tick: requests a model reload at frame 79; once it completes,
 * loads the switch-in owner model, frames the camera and enters state row 18.
 */
void BattleScene_TickRow20CleanupAndEnterState18(ActivePokemon* active_pokemon) {
    if (active_pokemon->animationTimer == 79) {
        active_pokemon->sessionTeams->uniqueStatusFlags |= 0x80;
    }

    if (active_pokemon->sessionTeams->uniqueStatusFlags & 0x10) {
        active_pokemon->sessionTeams->uniqueStatusFlags &= ~0x90;

        Battle_LoadOwnerModelForSwitchIn(active_pokemon);
        BattleScene_TickOwnerCameraFraming(active_pokemon);
        Audio_PlayCommand(2, 0, 0);

        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;

        BattleScene_EnterStateRow(active_pokemon, 18);
    }
}

/**
 * Once a requested model reload completes, resets the owner model to the
 * neutral placeholder.
 */
void BattleScene_ResetOwnerModelIfLoaded(ActivePokemon* active_pokemon) {
    if (active_pokemon->sessionTeams->uniqueStatusFlags & 0x10) {
        active_pokemon->sessionTeams->uniqueStatusFlags &= ~0x90;
        Battle_ResetOwnerModelToNeutralPlaceholder(active_pokemon);
    }
}

/**
 * State row 8 enter: starts the charge cue mapped from the used move.
 */
void BattleScene_EnterRow8StartMappedMoveAnim(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    s32 charge_move_cue = sChargeMoveCues[active_pokemon->state.runtime.usedMove - 1];

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[charge_move_cue];
    active_pokemon->animationTimer = 0;
    ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
    ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
    BattleAnim_SetModelEventTrackFromRow(active_pokemon, charge_move_cue);
}

/**
 * State row 8 tick: when the charge cue ends, queues the alternate effect
 * script, applies Fly/Dig model flags and plays the reaction sound.
 */
void BattleScene_TickRow8PlayMoveEffectScriptB(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    s16 species_ob1;
    s16 move;

    species_ob1 = active_pokemon->displayObject.objectType - 1;
    runtime = &active_pokemon->state.runtime;
    move = sChargeMoveCues[runtime->usedMove - 1];

    BattleScene_GetParticipantSideIndex(active_pokemon);

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[move];

    if ((active_pokemon->animationTimer == (sCurrentAnimation->animationDuration + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleAnim_PlayChargingMoveEffectScript(active_pokemon, runtime->usedMove);

        if (runtime->usedMove == FLY) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 3, 0);
        }

        if ((runtime->usedMove == DIG) && (species_ob1 != DIGLETT_OB1) && (species_ob1 != DUGTRIO_OB1)) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 5, 0);
            BattleAnim_QueueEffectList(4, active_pokemon);
        }

        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;

        BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 4);
    }
}

/**
 * State row 9 enter: sets the idle (or sleeping idle) event track.
 */
void BattleScene_EnterRow9SetEventTrack(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[3];
    BattleMon* party_pokemon = &active_pokemon->teamRoster->pokemonPicked[active_pokemon->state.rosterIndex];
    s32 cue_index;

    active_pokemon->animationTimer = 0;
    if (!(active_pokemon->state.flags & 2)) {
        if (party_pokemon->statusCondition & 7) {
            if (BattleScene_ByteArrayContains(active_pokemon->displayObject.objectType, sPokemonWithAlternateSleepIdle, 8) != 0) {
                cue_index = BATTLE_CUE_SLEEP_IDLE;
            } else {
                cue_index = BATTLE_CUE_IDLE;
            }
        } else {
            cue_index = BATTLE_CUE_IDLE;
        }
        sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[cue_index];
        BattleAnim_SetModelEventTrackFromRow(active_pokemon, cue_index);
    }
}

/**
 * State row 9 enter: when the opponent is bound by Bind, Wrap or String Shot,
 * queues the binding effect and model flags.
 */
void BattleScene_EnterRow9QueueEffectList6(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->state.runtime;

    if (runtime->unk_4C & 0x20) {
        if ((runtime->usedMove == BIND) || (runtime->usedMove == WRAP) || (runtime->usedMove == STRING_SHOT)) {
            BattleAnim_QueueEffectList6(2, active_pokemon);
            BattleScene_SetParticipantModelFlags(active_pokemon, 16, 0);
        }
    }
}

/**
 * State row 12 tick: when the target reaches the move cue's end frame, plays
 * reaction sound 5.
 */
void BattleScene_Row12Slot1CameraCleanup(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    s32 side;

    side = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    runtime = &active_pokemon->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->moveCues[runtime->usedMove - 1];

    if ((sCurrentAnimation->endFrame + 1) == sActivePokemon[side]->animationTimer) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 5);
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

/**
 * State row 13: plays battle sounds 20 and/or 33 from runtime bits 0x08/0x10,
 * then retires the slot.
 */
void BattleScene_Row13PlaySequences14And21(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;

    if (runtime->unk_15 & 8) {
        BattleAnim_PlayBattleSequenceById(active_pokemon, 20);
    }

    if (runtime->unk_15 & 0x10) {
        BattleAnim_PlayBattleSequenceById(active_pokemon, 33);
    }

    sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
}

/**
 * State tick: when the faint cue ends, plays sound command 0x33 for the
 * species (nonzero-height models skip it except Fearow, Magneton and Aerodactyl).
 */
void BattleScene_TickPlaySpeciesSequence33(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    u16 species = active_pokemon->displayObject.objectType;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->faintCue;
    if ((BattleScene_GetParticipantModelHeight(active_pokemon) != 0.0f) && (species != FEAROW) && (species != MAGNETON) && (species != AERODACTYL)) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    } else if ((active_pokemon->animationTimer == (sCurrentAnimation->animationDuration + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleAnim_PlaySpeciesSequence33(active_pokemon);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * State tick: at the faint cue's effect frame, queues effect list 3 entry 2
 * or 12 and sound 3.
 */
void BattleScene_TickQueueList3Selector2OrC(ActivePokemon* active_pokemon) {
    s32 first_effect_frame;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->faintCue;
    if (sCurrentAnimation->unk_09 == 1) {
        first_effect_frame = sCurrentAnimation->unk_0A - 76;
    } else {
        first_effect_frame = sCurrentAnimation->unk_0A - 49;
    }

    if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
        if (BattleScene_GetParticipantModelHeight(active_pokemon) != 0.0f) {
            if ((first_effect_frame <= 0) || (first_effect_frame == active_pokemon->animationTimer)) {
                if (sCurrentAnimation->unk_09 == 1) {
                    BattleAnim_QueueEffectList3(2, active_pokemon, active_pokemon, 0xFF, 0xFF);
                } else {
                    BattleAnim_QueueEffectList3(12, active_pokemon, active_pokemon, 0xFF, 0xFF);
                }
                Audio_PlayCommand(3, 0, 0);
                sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
            }
        } else if ((first_effect_frame <= 0) || (first_effect_frame == active_pokemon->animationTimer)) {
            if (sCurrentAnimation->unk_09 == 1) {
                BattleAnim_QueueEffectList3(2, active_pokemon, active_pokemon, 0xFF, 0xFF);
            } else {
                BattleAnim_QueueEffectList3(12, active_pokemon, active_pokemon, 0xFF, 0xFF);
            }
            Audio_PlayCommand(3, 0, 0);
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

/**
 * Same as BattleScene_TickQueueList3Selector2OrC, using cue unk_B10.
 */
void BattleScene_TickQueueList3Selector2OrCFromB10(ActivePokemon* active_pokemon) {
    s32 first_effect_frame;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_B10;
    if (sCurrentAnimation->unk_09 == 1) {
        first_effect_frame = sCurrentAnimation->unk_0A - 76;
    } else {
        first_effect_frame = sCurrentAnimation->unk_0A - 49;
    }

    if ((BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) && ((first_effect_frame <= 0) || (first_effect_frame == active_pokemon->animationTimer))) {
        if (sCurrentAnimation->unk_09 == 1) {
            BattleAnim_QueueEffectList3(2, active_pokemon, active_pokemon, 0xFF, 0xFF);
        } else {
            BattleAnim_QueueEffectList3(12, active_pokemon, active_pokemon, 0xFF, 0xFF);
        }
        Audio_PlayCommand(3, 0, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * State rows 11 and 14 enter: picks and starts the target's hit reaction cue
 * when the move confused, failed or was resisted (Bubble).
 */
void BattleScene_EnterRow11StartHitReactionAnim(ActivePokemon* active_pokemon) {
    UNUSED s32 pad3;
    s32 idle_cue_index;
    s32 unk_B00_cue_index;
    s32 target_side;
    ActivePokemonState* target_state;
    UNUSED s32 pad[2];
    ActivePokemon* target;
    BattleMonRuntime* runtime;

    idle_cue_index = BATTLE_CUE_IDLE;
    target_side = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    target_state = &sActivePokemon[target_side]->state;
    target = sActivePokemon[target_side];
    runtime = &active_pokemon->state.runtime;

    sCurrentAnimation = &sSideBattleCues[target_side]->hitCue;

    if (target_state->flags & ACTIVE_SLEEP) {
        if (BattleScene_ByteArrayContains(target->displayObject.objectType, sPokemonWithAlternateSleepHitReactions, 2) != 0) {
            sCurrentAnimation = &sSideBattleCues[target_side]->hitReactionOverride;
        }
    }

    if ((target_state->flags & ACTIVE_SLEEP) && BattleScene_ByteArrayContains(target->displayObject.objectType, sPokemonWithAlternateSleepIdle, 8)) {
        idle_cue_index = BATTLE_CUE_SLEEP_IDLE;
    }

    sActivePokemon[target_side]->animationTimer = 0;

    if (!(target_state->flags & ACTIVE_UNDERGROUND) && !(target_state->flags & ACTIVE_FREEZE)) {
        if ((runtime->usedMove == BUBBLE) && (sTypeEffectiveness < TYPE_EFFECTIVENESS_NEUTRAL)) {
            sCurrentAnimation = &sSideBattleCues[target_side]->moveCues[idle_cue_index];
        }

        if ((sConfused == 0) || (sBattleMoveFailed != 0)) {
            unk_B00_cue_index = BATTLE_CUE_B00;
            sCurrentAnimation = &sSideBattleCues[target_side]->moveCues[idle_cue_index];
            if (target_state->flags & ACTIVE_AIRBORNE) {
                sCurrentAnimation = &sSideBattleCues[target_side]->moveCues[unk_B00_cue_index];
            }
        } else if (!(target_state->flags & ACTIVE_SLEEP)) {
            BattleAnim_SetModelEventTrackFromRow(sActivePokemon[target_side], BATTLE_CUE_HIT);
        }

        ModelAnim_SetFrame(&sActivePokemon[target_side]->displayObject, 0);
        ModelAnim_SetAnimation(&sActivePokemon[target_side]->displayObject, sCurrentAnimation->id);

        if ((runtime->moveCache.lastMove == STOMP) || (runtime->moveCache.lastMove == BODY_SLAM) || (runtime->moveCache.lastMove == SEISMIC_TOSS)) {
            BattleScene_SetParticipantModelFlags(sActivePokemon[target_side], 15, 0);
        }
    }
}

/**
 * State row 14 tick: when the target reaches the move cue's end frame, plays
 * the confusion sound for Supersonic/Confuse Ray and the end-of-move effect.
 */
void BattleScene_TickRow14PlayMoveEffectEnd(ActivePokemon* active_pokemon) {
    s32 side;
    UNUSED s32 pad;
    BattleMonRuntime* runtime;
    BattleMonRuntime* runtime_temp;

    side = BattleScene_GetParticipantSideIndex(active_pokemon);
    runtime = &sActivePokemon[side == 0]->state.runtime;
    // FAKE
    runtime_temp = &active_pokemon->state.runtime;

    sCurrentAnimation = &sSideBattleCues[side == 0]->moveCues[runtime_temp->usedMove - 1];

    if ((sActivePokemon[side == 0]->animationTimer == (sCurrentAnimation->endFrame + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleAnim_CleanupEffects(1);
        if (((runtime_temp->usedMove == SUPERSONIC) || (runtime_temp->usedMove == CONFUSE_RAY)) && (runtime->unk_4C & 0x80) && (sBattleMoveFailed == 0) &&
            (sConfused == 1)) {
            BattleAnim_PlayBattleSequenceById(sActivePokemon[side == 0], 18);
        }

        BattleAnim_PlayMoveEffectEnd(sActivePokemon[side == 0], runtime_temp->usedMove);
        if ((sBattleMoveFailed == 0) || (sConfused == 1)) {
            BattleAnim_PlaySpeciesReactionSound(sActivePokemon[side == 0], &active_pokemon->state.runtime, 1);
        }

        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
    }
}

/**
 * Returns 2 when the move effect did not apply, 1 when the opposing timer
 * reaches the cue's effect frame plus 80, otherwise 0.
 */
s32 BattleScene_GetOpponentEffectCheckpoint(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;
    s32 target_side;

    target_side = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    sCurrentAnimation = &sSideBattleCues[target_side]->moveCues[runtime->usedMove - 1];

    if (sStatCanBeLoweredFurther != 1) {
        return 2;
    }

    if ((sCurrentAnimation->unk_08 + 80) == sActivePokemon[target_side]->animationTimer) {
        return 1;
    }

    return 0;
}

/**
 * State row 11 tick: at the target's effect frame, queues the effect list 6
 * entry on the target and plays battle sound 32.
 */
void BattleScene_TickRow11QueueEffectList6(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;
    s32 target_side;

    target_side = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->moveCues[runtime->usedMove - 1];
    if (sActivePokemon[target_side]->animationTimer == (sCurrentAnimation->unk_08 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (sStatCanBeLoweredFurther == 1) {
                BattleAnim_QueueEffectList6(1, sActivePokemon[target_side]);
                BattleAnim_PlayBattleSequenceById(active_pokemon, 32);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

/**
 * State row 11 tick: when the target reaches the move cue's end frame, plays
 * the target's reaction sound.
 */
void BattleScene_TickRow11PostEndCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    s32 target_side;

    target_side = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    runtime = &active_pokemon->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->moveCues[runtime->usedMove - 1];

    if ((sCurrentAnimation->endFrame + 1) == sActivePokemon[target_side]->animationTimer) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (sConfused == 1) {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[target_side], runtime, 1);
            } else {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[target_side], runtime, 5);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback = sBattleSceneStateTickSentinel;
        }
    }
}

/**
 * Empty state callback used as the tick-slot sentinel and table filler.
 */
void BattleScene_StateCallbackNop(ActivePokemon* active_pokemon) {
}

/**
 * Stores `callback` in the first free tick slot (sentinel), if any.
 */
void BattleScene_RegisterStateTickCallback(ActivePokemon* active_pokemon, BattleSceneStateCallback callback) {
    UNUSED BattleSceneStateTickSlot* unused_slot;
    s32 i;

    for (i = 0; i < 7; i++) {
        if (sBattleSceneStateTickSentinel == sBattleSceneStateTickSlots[i].callback) {
            sBattleSceneStateTickSlots[i].callback = callback;
            sBattleSceneStateTickSlots[i].unk_00 = active_pokemon;
            break;
        }
    }
}

/**
 * Sets the cue 166 (unkA60) event track on the participant at this side index.
 */
void BattleScene_SetOpponentEventTrackA6(ActivePokemon* active_pokemon) {
    BattleAnim_SetModelEventTrackFromRow(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon)], BATTLE_CUE_A60);
}

/**
 * Enters state row `row_index`: runs its three enter callbacks and registers
 * its four tick callbacks.
 */
void BattleScene_EnterStateRow(ActivePokemon* active_pokemon, s32 row_index) {
    active_pokemon->animationState = row_index;

    sBattleSceneStateRowTable[row_index].unk_04[0](active_pokemon);
    sBattleSceneStateRowTable[row_index].unk_04[1](active_pokemon);
    sBattleSceneStateRowTable[row_index].unk_04[2](active_pokemon);

    BattleScene_RegisterStateTickCallback(active_pokemon, sBattleSceneStateRowTable[row_index].unk_04[3]);
    BattleScene_RegisterStateTickCallback(active_pokemon, sBattleSceneStateRowTable[row_index].unk_04[4]);
    BattleScene_RegisterStateTickCallback(active_pokemon, sBattleSceneStateRowTable[row_index].unk_04[5]);
    BattleScene_RegisterStateTickCallback(active_pokemon, sBattleSceneStateRowTable[row_index].unk_04[6]);
}

/**
 * Advances both participants' timers and runs every tick slot.
 */
void BattleScene_TickStateCallbacks(void) {
    sActivePokemon[0]->animationTimer++;
    sActivePokemon[1]->animationTimer++;

    for (sBattleSceneStateTickSlotIndex = 0; sBattleSceneStateTickSlotIndex < 7; sBattleSceneStateTickSlotIndex++) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].callback(sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_00);
    }
}

/**
 * Restores the normal material after Harden.
 */
void Battle_StopBeingGoldAfterHarden(ActivePokemon* active_pokemon) {
    if (active_pokemon->state.runtime.usedMove == HARDEN) {
        active_pokemon->displayObject.textureMode = 0;
    }
}

/**
 * Sets the event track of cue `cue_index` when the session is idle. Dugtrio's
 * idle cue picks one of three consecutive tracks at random.
 */
void BattleAnim_SetModelEventTrackFromRow(ActivePokemon* pokemon, s32 cue_index) {
    s32 random_offset;
    s32 event_track;
    ActivePokemonState* pokemon_state = &pokemon->state;

    if (BattleAnim_IsSessionBusy(pokemon) == 0) {
        event_track = sSideBattleCues[BattleScene_GetParticipantSideIndex(pokemon)]->moveCues[cue_index].unk_01;
        if ((event_track != 0xFF) && (pokemon_state->unk_36 != 2)) {
            if ((cue_index == BATTLE_CUE_IDLE) && (pokemon->displayObject.objectType == DUGTRIO)) {
                ModelAnim_SetEventFrame(&pokemon->displayObject, 0);
                random_offset = BattleAnim_RandomRange(3);
                if (random_offset >= 3) {
                    random_offset = 2;
                }
                ModelAnim_SetEventTrack(&pokemon->displayObject, event_track + random_offset);
            } else {
                ModelAnim_SetEventFrame(&pokemon->displayObject, 0);
                ModelAnim_SetEventTrack(&pokemon->displayObject, event_track);
                pokemon_state->unk_36 = 1;
            }
        }
    }
}

/**
 * Binds cue `cue_index`'s event track at its end frame and records
 * `event_state`. Returns 1 when the cue has no track, otherwise 0.
 */
s32 BattleAnim_TrySetModelEventTrackFromRow(ActivePokemon* active_pokemon, s32 cue_index, s32 event_state) {
    UNUSED s32 pad;
    s32 event_track;

    if (BattleAnim_IsSessionBusy(active_pokemon) != 0) {
        return 0;
    }

    event_track = sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[cue_index].unk_01;
    if (event_track == 0xFF) {
        return 1;
    }

    ModelAnim_SetEventFrame(&active_pokemon->displayObject, 0);
    ModelAnim_SetEventTrack(&active_pokemon->displayObject, event_track);
    ModelAnim_SetEventFrame(&active_pokemon->displayObject, active_pokemon->displayObject.eventTrack.data->endFrame);

    active_pokemon->state.unk_36 = event_state;
    return 0;
}

/**
 * Sets cue `cue_index`'s event track from frame 0 and records `event_state`.
 */
void BattleAnim_SetModelEventTrackAndState(ActivePokemon* active_pokemon, s32 cue_index, s32 event_state) {
    u8 event_track;

    if (BattleAnim_IsSessionBusy(active_pokemon) == 0) {
        event_track = sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[cue_index].unk_01;
        if (event_track != 0xFF) {
            ModelAnim_SetEventTrack(&active_pokemon->displayObject, event_track);
            ModelAnim_SetEventFrame(&active_pokemon->displayObject, 0);
            active_pokemon->state.unk_36 = event_state;
        }
    }
}

/**
 * Returns 1 while the freeze flag (0x2), sleep (status & 7), flag 0x200 without
 * 0x400, or flag 0x4000 is set.
 */
s32 BattleScene_IsParticipantIncapacitated(ActivePokemon* active_pokemon) {
    ActivePokemonState* state = &active_pokemon->state;
    BattleMon* pokemon = &active_pokemon->teamRoster->pokemonPicked[active_pokemon->state.rosterIndex];

    if ((state->flags & ACTIVE_FREEZE) || (pokemon->statusCondition & 7) || ((state->flags & ACTIVE_AIRBORNE) && !(state->flags & 0x400)) ||
        (state->flags & ACTIVE_UNDERGROUND)) {
        return 1;
    }
    return 0;
}

/**
 * Returns 1 when the animation is done, or after `frame_limit` frames for
 * incapacitated participants.
 */
s32 BattleScene_IsRowWaitComplete(ActivePokemon* active_pokemon, s32 frame_limit) {
    if (BattleScene_IsParticipantIncapacitated(active_pokemon) != 0) {
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    if (active_pokemon->displayObject.transformAnim.animationId == -1) {
        return 1;
    }
    return ModelAnim_IsAnimationDone(&active_pokemon->displayObject);
}

/**
 * Like BattleScene_IsRowWaitComplete, but waits the unkA60 cue's frame count
 * when it is at least 11.
 */
s32 BattleScene_IsRowWaitCompleteWithEventCount(ActivePokemon* active_pokemon, s32 frame_limit) {
    UNUSED u8 unused_value;

    sCurrentAnimation = sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->unkA60;
    if (BattleScene_IsParticipantIncapacitated(active_pokemon) != 0) {
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    if ((sCurrentAnimation->unk_0A < 11) || (sCurrentAnimation->unk_0A == 0xFF)) {
        if (active_pokemon->displayObject.transformAnim.animationId == -1) {
            return 1;
        }
        return ModelAnim_IsAnimationDone(&active_pokemon->displayObject);
    }

    if (BattleScene_AdvanceCameraFrameCounter(sCurrentAnimation->unk_0A + 1) != 0) {
        return 1;
    }

    return 0;
}

/**
 * Returns 1 when the move cue settles: at its end frame (unk_0A) when set,
 * otherwise when its animation ends (or `frame_limit` frames for idle cues).
 */
s32 Battle_IsRowAnimationSettled(ActivePokemon* active_pokemon, s32 frame_limit) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;
    MovePresentationCue* move_cue;
    MovePresentationCue* idle_cue;

    if (active_pokemon) {} //karodo

    move_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];
    idle_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->idleCues;

    if (BattleScene_IsParticipantIncapacitated(active_pokemon) != 0) {
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    if (active_pokemon->displayObject.transformAnim.animationId == -1) {
        return 1;
    }

    if (sBattleScene.unk_00->unk_48 == 20) {
        move_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[0];
    }

    if (move_cue->id == idle_cue->id) {
        if (move_cue->unk_0A != 0xFF) {
            sBattleScene.unk_00->unk_14++;
            if (move_cue->unk_0A == active_pokemon->animationTimer) {
                return 1;
            }
            return 0;
        }

        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    sBattleScene.unk_00->unk_14++;

    if (move_cue->unk_0A != 0xFF) {
        if (move_cue->unk_0A == active_pokemon->animationTimer) {
            return 1;
        }
        return 0;
    }

    return ModelAnim_IsAnimationDone(&active_pokemon->displayObject);
}

/**
 * Battle_IsRowAnimationSettled for the charge cue mapped from the used move.
 */
s32 BattleScene_IsMoveKeyedRowWaitComplete(ActivePokemon* active_pokemon, s32 frame_limit) {
    MovePresentationCue* idle_cue;
    BattleMon* party_pokemon;
    UNUSED s32 pad;
    s32 charge_move;
    MovePresentationCue* move_cue;

    party_pokemon = &active_pokemon->teamRoster->pokemonPicked[active_pokemon->state.rosterIndex];
    charge_move = sChargeMoveCues[active_pokemon->state.runtime.usedMove - 1];
    move_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[charge_move];
    idle_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->idleCues;

    if ((active_pokemon->state.flags & 2) || (party_pokemon->statusCondition & 7) ||
        ((active_pokemon->state.flags & 0x200) && !(active_pokemon->state.flags & 0x400)) || (active_pokemon->state.flags & ACTIVE_UNDERGROUND)) {
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    if (active_pokemon->displayObject.transformAnim.animationId == -1) {
        return 1;
    }

    if (move_cue->id == idle_cue->id) {
        if (move_cue->unk_0A != 0xFF) {
            sBattleScene.unk_00->unk_14++;
            if (move_cue->unk_0A == active_pokemon->animationTimer) {
                return 1;
            }
            return 0;
        }
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    sBattleScene.unk_00->unk_14++;

    if (move_cue->unk_0A != 0xFF) {
        if (move_cue->unk_0A == active_pokemon->animationTimer) {
            return 1;
        }
        return 0;
    }
    return ModelAnim_IsAnimationDone(&active_pokemon->displayObject);
}

/**
 * Returns 1 when the hit cue animation is done or replaced, or after
 * `frame_limit` frames while flag 0x2 or 0x200 (without 0x400) is set.
 */
s32 BattleScene_IsRowAnimWaitComplete(ActivePokemon* active_pokemon, s32 frame_limit) {
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->hitCue;

    if ((active_pokemon->state.flags & 2) || ((active_pokemon->state.flags & 0x200) && !(active_pokemon->state.flags & 0x400))) {
        if (BattleScene_AdvanceCameraFrameCounter(frame_limit) != 0) {
            return 1;
        }
        return 0;
    }

    if (active_pokemon->displayObject.transformAnim.animationId == -1) {
        return 1;
    }

    if (active_pokemon->displayObject.transformAnim.animationId != sCurrentAnimation->id) {
        return 1;
    }

    return ModelAnim_IsAnimationDone(&active_pokemon->displayObject);
}

/**
 * At the last frame of the idle cue, randomly (1 in 2) queues the idle cue's
 * effect when the camera is in mode 1.
 */
void BattleScene_TryQueueIdleCueEffect(ActivePokemon* active_pokemon) {
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->idleCues;
    if (BattleAnim_IsSessionBusy(active_pokemon) == 0) {
        if ((active_pokemon->displayObject.transformAnim.animationId != -1) && (active_pokemon->displayObject.node.flags & 1) &&
            (active_pokemon->displayObject.node.renderFlags & 0x20) && (sBattleScene.unk_00->unk_1C == 1) &&
            (sCurrentAnimation->id == active_pokemon->displayObject.transformAnim.animationId) &&
            (sCurrentAnimation->animationDuration == (active_pokemon->displayObject.transformAnim.frameFixed >> 0x10)) && (sCurrentAnimation->flags1 != 0) &&
            (BattleAnim_RandomRange(2) == 1)) {
            BattleAnim_QueueEffectList3(sCurrentAnimation->flags1, &active_pokemon->displayObject, &active_pokemon->displayObject, sCurrentAnimation->unk_02, sCurrentAnimation->unk_02);
        }
    }
}

/**
 * Sets bits in the participant's animation state flags.
 */
void Battle_SetRuntimeFlags(ActivePokemon* active_pokemon, u16 flag) {
    active_pokemon->state.flags |= flag;
}

/**
 * Clears bits in the participant's animation state flags.
 */
s32 Battle_ClearRuntimeFlags(ActivePokemon* active_pokemon, u16 flag) {
    active_pokemon->state.flags &= ~flag;
}

/**
 * When unk_4C8 is set, restores the model height and clears the 0x200 and
 * 0x4000 flag groups.
 */
void BattleScene_ResetParticipantAnimationFlags(ActivePokemon* active_pokemon) {
    ActivePokemonState* pokemon_state = &active_pokemon->state;

    if (active_pokemon->unk_4C8 != 0) {
        if (pokemon_state->flags & ACTIVE_AIRBORNE) {
            active_pokemon->displayObject.position.y = D_84390028[BattleScene_GetParticipantSideIndex(active_pokemon)].unk_08;
            Battle_ClearRuntimeFlags(active_pokemon, 0x608);
        }

        if (pokemon_state->flags & 0x4008) {
            active_pokemon->displayObject.lodFraction = 0xFF;
            BattleAnim_StopOwnerCategoryParticles(4, active_pokemon);
            active_pokemon->displayObject.position.y = D_84390028[BattleScene_GetParticipantSideIndex(active_pokemon)].unk_08;
            active_pokemon->displayObject.node.renderFlags &= ~2;
            active_pokemon->displayObject.node.renderFlags |= 0x20;
            active_pokemon->displayObject.node.flags |= 1;
            Battle_ClearRuntimeFlags(active_pokemon, 0x4608);
        }
    }
}

/**
 * Moves participants with flag 0x4 to y = 200 (setting 0x200), restarts the
 * Dig cue for Dugtrio with flag 0x4000, then resets both participants' animation flags.
 */
void BattleScene_ResetBothParticipantsAnimationState(void) {
    ActivePokemonState* side1_pokemon_state;
    ActivePokemonState* side2_pokemon_state;
    UNUSED s32 pad[2];
    ActivePokemon* side1_pokemon;
    ActivePokemon* side2_pokemon;

    side1_pokemon_state = &sActivePokemon[0]->state;
    side2_pokemon_state = &sActivePokemon[1]->state;
    side1_pokemon = sActivePokemon[0];
    side2_pokemon = sActivePokemon[1];

    if (side1_pokemon_state->flags & 4) {
        sActivePokemon[0]->displayObject.position.y = 200.0f;
        Battle_SetRuntimeFlags(sActivePokemon[0], 0x200);
        Battle_ClearRuntimeFlags(sActivePokemon[0], 4);
    }

    if (side2_pokemon_state->flags & 4) {
        sActivePokemon[1]->displayObject.position.y = 200.0f;
        Battle_SetRuntimeFlags(sActivePokemon[1], 0x200);
        Battle_ClearRuntimeFlags(sActivePokemon[1], 4);
    }

    if ((side1_pokemon_state->flags & ACTIVE_UNDERGROUND) && (side1_pokemon->displayObject.objectType == DUGTRIO)) {
        sCurrentAnimation = &sSideBattleCues[0]->moveCues[DIG - 1];
        ModelAnim_SetFrame(&sActivePokemon[0]->displayObject, 0);
        ModelAnim_SetAnimation(&sActivePokemon[0]->displayObject, sCurrentAnimation->id);
    }

    if ((side2_pokemon_state->flags & ACTIVE_UNDERGROUND) && (side2_pokemon->displayObject.objectType == DUGTRIO)) {
        sCurrentAnimation = &sSideBattleCues[1]->moveCues[DIG - 1];
        ModelAnim_SetFrame(&sActivePokemon[1]->displayObject, 0);
        ModelAnim_SetAnimation(&sActivePokemon[1]->displayObject, sCurrentAnimation->id);
    }

    BattleScene_ResetParticipantAnimationFlags(sActivePokemon[0]);
    BattleScene_ResetParticipantAnimationFlags(sActivePokemon[1]);
}

/**
 * Ends the opponent's Harden material, converts its flag 0x4 to 0x200 at
 * y = 200, and sets 0x400 on a user with flag 0x200.
 */
void Battle_ClearOpponentHopFlagAndSyncMove(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    ActivePokemonState* target_state;

    target_state = &sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->state;
    BattleScene_GetParticipantSideIndex(active_pokemon);
    BattleScene_GetParticipantSideIndex(active_pokemon);
    Battle_StopBeingGoldAfterHarden(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]);

    if (target_state->flags & 4) {
        sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->displayObject.position.y = 200.0f;
        Battle_SetRuntimeFlags(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0], 0x200);
        Battle_ClearRuntimeFlags(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0], 4);
    }

    if (active_pokemon->state.flags & 0x200) {
        Battle_SetRuntimeFlags(active_pokemon, 0x400);
    }
}

/**
 * Restores a hidden participant's height and clears its hide flags.
 */
void BattleScene_CleanupParticipantHideFlag(ActivePokemon* active_pokemon) {
    if (active_pokemon->state.flags & 8) {
        active_pokemon->displayObject.position.y = BattleScene_GetParticipantModelHeight(active_pokemon);
        Battle_ClearRuntimeFlags(active_pokemon, 0x608);
    }
}

/**
 * Clears the opponent's flag 0x4000, showing its model and stopping category
 * 4 particles.
 */
void BattleScene_CleanupOpponentSpecialAnimFlag(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    ActivePokemon* target = sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0];

    if (target->state.flags & ACTIVE_UNDERGROUND) {
        target->displayObject.node.renderFlags |= 0x20;
        target->displayObject.node.flags |= 1;
        BattleAnim_StopOwnerCategoryParticles(4, target);
        Battle_ClearRuntimeFlags(target, 0x4000);
    }
}

/**
 * Clears the opponent's flag 0x4000 (as above) and its hide flag (0x8).
 */
void BattleScene_CleanupOpponentAnimationFlags(ActivePokemon* active_pokemon) {
    ActivePokemon* target = sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0];
    ActivePokemonState* target_state = &target->state;

    if (target_state->flags & ACTIVE_UNDERGROUND) {
        target->displayObject.node.renderFlags |= 0x20;
        target->displayObject.node.flags |= 1;
        BattleAnim_StopOwnerCategoryParticles(4, target);
        Battle_ClearRuntimeFlags(target, 0x4000);
    }

    if (target_state->flags & 8) {
        target->displayObject.position.y = BattleScene_GetParticipantModelHeight(active_pokemon);
        Battle_ClearRuntimeFlags(target, 0x608);
    }
}

/**
 * Undoes the model changes of the participant's current effect mode
 * (scale, height, rotation and secondary models).
 */
void BattleScene_CleanupParticipantEffectMode(ActivePokemon* active_pokemon) {
    switch (active_pokemon->animationFlags1) {
        case 14:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            BattleScene_PositionParticipantModel(active_pokemon);
            break;

        case 13:
        case 15:
        case 16:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            if (active_pokemon->state.runtime.unk_56 == 0) {
                Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 1.0f, 1.0f, 1.0f);
            } else {
                Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 0.8f, 0.8f, 0.8f);
            }
            break;

        case 12:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            if (active_pokemon->state.runtime.unk_56 == 0) {
                Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 1.0f, 1.0f, 1.0f);
            } else {
                Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 0.8f, 0.8f, 0.8f);
            }
            break;

        case 10:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            active_pokemon->displayObject.position.y = BattleScene_GetParticipantModelHeight(active_pokemon);
            active_pokemon->displayObject.rotation.x = 0;
            break;

        case 9:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 0.8f, 0.8f, 0.8f);
            BattleScene_HideParticipantSecondaryModels(active_pokemon);
            break;

        case 7:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            BattleScene_HideParticipantSecondaryModels(active_pokemon);
            break;

        case 6:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            BattleScene_HideParticipantSecondaryModels(active_pokemon);
            BattleScene_PositionParticipantModel(active_pokemon);
            Vec3s_SetComponents(&active_pokemon->displayObject.rotation, 0, active_pokemon->cameraOffsetScaleFactor << 0xE, 0);
            break;

        case 4:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            active_pokemon->displayObject.rotation.y = active_pokemon->cameraOffsetScaleFactor << 0xE;
            BattleScene_HideParticipantSecondaryModels(active_pokemon);
            break;
    }
}

/**
 * Per-frame status presentation: freeze and sleep animations, the fade-in
 * flash, random idle event tracks and hiding models with flag 0x4000.
 */
void BattleAnim_TickParticipantStatusAnimation(ActivePokemon* active_pokemon) {
    ActivePokemonState* state = &active_pokemon->state;

    BattleAnim_StartFreezeStatusAnimation(active_pokemon);
    BattleAnim_UpdateSleepStatusAnimation(active_pokemon);

    if (state->flags & 0x100) {
        active_pokemon->displayObject.node.renderFlags &= 0xFFDF;
    }

    if ((state->unk_2D == 16) || (state->unk_2D == 19)) {
        Battle_ClearRuntimeFlags(active_pokemon, 0x100);
    }

    state->unk_2E = Math_StepToS32(state->unk_2E, 0, 30, 30);
    if (state->unk_2E != 0) {
        Model_SetMaterialColor(&active_pokemon->displayObject, 0xFF, 0xFF, 0xFF, state->unk_2E);
    }

    switch (state->unk_36) {
        case 2:
            break;

        case 0:
            if (BattleAnim_RandomRange(50) == 2) {
                BattleAnim_SetModelEventTrackFromRow(active_pokemon, BATTLE_CUE_IDLE);
            }
            break;

        case 1:
            if (ModelAnim_IsEventTrackNearEnd(&active_pokemon->displayObject) == 1) {
                ModelAnim_SetEventTrack(&active_pokemon->displayObject, -1);
                ModelAnim_SetEventFrame(&active_pokemon->displayObject, 0);
                state->unk_36 = 0;
            }
            break;
    }

    if (state->flags & ACTIVE_UNDERGROUND) {
        if ((active_pokemon->displayObject.objectType != DIGLETT) && (active_pokemon->displayObject.objectType != DUGTRIO)) {
            active_pokemon->displayObject.lodFraction = 0;
        }
    }
}

/**
 * Starts the sleeping event track, particles and sound for an asleep
 * participant whose sleep animation is not running.
 */
void BattleAnim_TriggerStatusAfflictionCry(ActivePokemon* active_pokemon) {
    BattleMon* party_pokemon = &active_pokemon->teamRoster->pokemonPicked[active_pokemon->state.rosterIndex];

    if ((party_pokemon->statusCondition & 7) && !(active_pokemon->state.flags & 1)) {
        BattleAnim_SetModelEventTrackAndState(active_pokemon, BATTLE_CUE_SLEEP_IDLE, 2);
        BattleAnim_QueueEffectList(3, active_pokemon);
        BattleAnim_PlayBattleSequenceById(active_pokemon, 50);
    }
}

/**
 * Allocates and zeroes the ActivePokemon for `side_index`.
 */
void BattleScene_AllocateParticipantRecord(BattleSessionTeams* session_teams, s32 side_index) {
    ActivePokemon* active_pokemon = main_pool_alloc(sizeof(ActivePokemon), 0);

    sActivePokemon[side_index] = active_pokemon;

    bzero(active_pokemon, sizeof(ActivePokemon));
    bzero(&sActivePokemon[side_index]->state, sizeof(ActivePokemonState));
    bzero(&sActivePokemon[side_index]->state.runtime, sizeof(BattleMonRuntime));
    bzero(&sActivePokemon[side_index]->unk_728, sizeof(PresentationState));
    bzero(&sActivePokemon[side_index]->state.runtime.moveCache, sizeof(CachedMoveData));
    bzero(&sActivePokemon[side_index]->state.unk_9C, sizeof(unk_D_84390010_654_09C));
    bzero(&sActivePokemon[side_index]->state.unk_AC, sizeof(unk_D_84390010_654_0AC));
    bzero(&sActivePokemon[side_index]->unk_8C4, sizeof(MonCaptionState));
    sActivePokemon[side_index]->sessionTeams = session_teams;
}

/**
 * Allocates both participants and the message queues.
 */
void BattleScene_AllocateParticipants(BattleSessionTeams* battle_teams) {
    BattleScene_AllocateParticipantRecord(&battle_teams[0], 0);
    BattleScene_AllocateParticipantRecord(&battle_teams[1], 1);
    Battle_InitMessageQueues();
    sSide1ActivePokemon = sActivePokemon[0];
    sSide2ActivePokemon = sActivePokemon[1];
}

/**
 * Binds the first team member, side and controller to the participant.
 */
void BattleScene_InitializeParticipantController(ActivePokemon* active_pokemon) {
    Controller* controller = &gControllers[active_pokemon->sessionTeams->teamMember[0]->unk_001];

    BattleScene_BindParticipantRosterForSide(active_pokemon, 0);
    BattleScene_SetParticipantSelectedSide(active_pokemon, 0);
    BattleScene_SetParticipantController(active_pokemon, controller);
    active_pokemon->unk_728.unk_16C = 0;
}

/**
 * Creates and positions the participant's Pokemon model and loads its
 * presentation data.
 */
void BattleScene_InitializeParticipantModel(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    ModelNodeView* model_view;
    s16 model_id;

    BattleScene_GetParticipantSideIndex(active_pokemon);
    model_view = Battle_GetMoveEffectListEntry(active_pokemon, 0);
    model_id = Battle_GetDisplayModelId(active_pokemon, 0);
    ModelRenderer_AttachDisplayObject(&active_pokemon->displayObject);

    if (active_pokemon == sActivePokemon[0]) {
        active_pokemon->displayObject.effectSlot = 0;
    } else {
        active_pokemon->displayObject.effectSlot = 1;
    }

    Model_InitDisplayObject(&active_pokemon->displayObject, 0, model_id, model_view);
    Battle_LoadAnimationAndMarkMoveIllegality(active_pokemon, 1);
    ModelAnim_SetAnimation(&active_pokemon->displayObject, 0);
    ModelAnim_SetFrame(&active_pokemon->displayObject, 0);

    active_pokemon->sessionTeams->unk_04 = active_pokemon->teamRoster->pokemonPicked;
    if ((active_pokemon->displayObject.objectType == DIGLETT) || (active_pokemon->displayObject.objectType == DUGTRIO)) {
        active_pokemon->displayObject.node.renderFlags &= ~0x40;
    } else {
        active_pokemon->displayObject.node.renderFlags |= 0x40;
    }

    if (active_pokemon == sActivePokemon[0]) {
        BattleScene_PositionParticipantModel(active_pokemon);
        active_pokemon->displayObject.rotation.y = 0x4000;
    } else {
        BattleScene_PositionParticipantModel(active_pokemon);
        active_pokemon->displayObject.rotation.y = -0x4000;
    }
}

/**
 * Creates the participant's owner (trainer) model.
 */
void BattleScene_InitializeParticipantOwnerModel(ActivePokemon* active_pokemon) {
    PresentationState* presentation = &active_pokemon->unk_728;
    ModelNodeView* model_view;
    s16 model_id;

    model_view = Battle_GetMoveEffectListEntry(active_pokemon, 0);
    model_id = Battle_GetDisplayModelId(active_pokemon, 0);
    ModelRenderer_AttachDisplayObject(&presentation->unk_000);

    if (active_pokemon == sActivePokemon[0]) {
        presentation->unk_000.effectSlot = -1;
        Model_InitDisplayObject(&presentation->unk_000, 1, model_id, model_view);
    } else {
        presentation->unk_000.effectSlot = -1;
        Model_InitDisplayObject(&presentation->unk_000, 2, model_id, model_view);
    }

    ModelAnim_SetAnimation(&presentation->unk_000, 0);
    ModelAnim_SetFrame(&presentation->unk_000, 0);
    presentation->unk_000.node.renderFlags &= ~0x40;
    Vec3f_SetComponentsDuplicate(&presentation->unk_000.position, 0.0f, 0.0f, 0.0f);
}

/**
 * Creates the participant's two hidden secondary models.
 */
void BattleScene_InitializeParticipantSecondaryModels(ActivePokemon* active_pokemon, UNUSED s32* secondary_models) {
    ModelNodeView* model_view;
    s16 model_id;
    s32 i;
    unk_D_84390010_168* secondary_model;

    model_view = Battle_GetMoveEffectListEntry(active_pokemon, 0);
    model_id = Battle_GetDisplayModelId(active_pokemon, 0);

    for (i = 0; i < 2; i++) {
        secondary_model = &active_pokemon->unk_168[i];

        ModelRenderer_AttachDisplayObject(secondary_model);

        if (active_pokemon == sActivePokemon[0]) {
            secondary_model->unk_000.effectSlot = 0xFF;
        } else {
            secondary_model->unk_000.effectSlot = 0xFF;
        }

        Model_InitDisplayObject(secondary_model, 0, model_id, model_view);
        ModelAnim_SetFrame(secondary_model, 0);
        ModelAnim_SetAnimation(secondary_model, 0);

        secondary_model->unk_000.node.renderFlags &= ~0x40;

        if (active_pokemon == sActivePokemon[0]) {
            BattleScene_PositionParticipantModel(active_pokemon);
        } else {
            BattleScene_PositionParticipantModel(active_pokemon);
        }
        secondary_model->unk_000.node.flags &= ~1;
    }
}

/**
 * Creates the participant's hidden auxiliary model (model 154).
 */
void BattleScene_InitializeParticipantAuxiliaryModel(ActivePokemon* active_pokemon) {
    DisplayObject* auxiliary_model = &active_pokemon->unk_4EC;
    ModelNodeView* model_view = active_pokemon->sessionTeams->unk_18;

    ModelRenderer_AttachDisplayObject(auxiliary_model);
    auxiliary_model->effectSlot = 0xFF;
    Model_InitDisplayObject(auxiliary_model, 0, 154, model_view);
    ModelAnim_SetAnimation(auxiliary_model, 0);

    auxiliary_model->node.renderFlags &= ~0x20;
    auxiliary_model->node.flags &= ~1;

    if (active_pokemon == sActivePokemon[0]) {
        Vec3f_SetComponentsDuplicate(&auxiliary_model->position, -50.0f, 2.0f, 0.0f);
    } else {
        Vec3f_SetComponentsDuplicate(&auxiliary_model->position, 50.0f, 2.0f, 0.0f);
    }
}

/**
 * Initializes controllers, all participant models, the camera mode for the
 * session mode, message buffers and audio channel groups.
 */
void BattleScene_InitializePresentation(UNUSED BattleSessionTeams* session_teams) {
    D_84390174 = 0;
    D_84390178.unk_00 = 0;

    BattleScene_InitializeParticipantController(sActivePokemon[0]);
    BattleScene_InitializeParticipantController(sActivePokemon[1]);
    BattleScene_InitializeParticipantModel(sActivePokemon[0]);
    BattleScene_InitializeParticipantModel(sActivePokemon[1]);
    BattleScene_InitializeParticipantOwnerModel(sActivePokemon[0]);
    BattleScene_InitializeParticipantOwnerModel(sActivePokemon[1]);
    BattleScene_InitializeParticipantSecondaryModels(sActivePokemon[0], &sActivePokemon[0]->unk_168);
    BattleScene_InitializeParticipantSecondaryModels(sActivePokemon[1], &sActivePokemon[1]->unk_168);
    BattleScene_InitializeParticipantAuxiliaryModel(sActivePokemon[0]);
    BattleScene_InitializeParticipantAuxiliaryModel(sActivePokemon[1]);

    switch (gSessionContext.mode) {
        case SESSION_MODE_ANYTHING_GOES:
        case SESSION_MODE_NINTENDO_CUP_97:
        case SESSION_MODE_NINTENDO_CUP_98:
        case SESSION_MODE_NINTENDO_CUP_99:
        case SESSION_MODE_PETIT_CUP:
        case SESSION_MODE_PIKA_CUP:
        case SESSION_MODE_PRIME_CUP:
        case SESSION_MODE_GYM_LEADER_CASTLE:
        case SESSION_MODE_VS_MEWTWO:
        case SESSION_MODE_BATTLE_NOW:
        case SESSION_MODE_EVENT_BATTLE:
            BattleScene_SetCameraModeAndStep(4, 0);
            break;

        case SESSION_MODE_ATTRACT_DEMO_BATTLE:
            BattleScene_SetCameraModeAndStep(1, 50);
            Audio_StartMusicTrack(1);
            break;

        default:
            BattleScene_SetCameraModeAndStep(4, 0);
            break;
    }

    BattleScene_SetParticipantModelFlags(sActivePokemon[0], 0, 0);
    BattleScene_SetParticipantModelFlags(sActivePokemon[1], 0, 0);
    BattleScene_ResetMessageQueue();
    BattleScene_ClearParticipantMessageBuffer(sActivePokemon[0]);
    BattleScene_ClearParticipantMessageBuffer(sActivePokemon[1]);
    BattleScene_ConfigureAudioChannelGroupCounts();
    BattleScene_ConfigureAudioChannelGroupsByTeam();
}

/**
 * Zeroes the sway state and sets the facing direction (1 or -1).
 */
void BattleScene_ResetParticipantAuxTransform(UNUSED ActivePokemon* owner, ActivePokemon* active_pokemon, s32 facing_direction) {
    Vec3f_SetComponentsDuplicate(&active_pokemon->swayState, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&active_pokemon->swayState.unk_0C, 0.0f, 0.0f, 0.0f);
    active_pokemon->cameraOffsetScaleFactor = facing_direction;
}

/**
 * Loads battle string tables, clears tick slots and initializes facing,
 * presentation, runtime state and move illegality.
 */
void BattleScene_InitializeRuntime(BattleSessionTeams* session_teams) {
    s32 i;

    Text_InitStringTables();

    sBattleMessagesTable = Text_GetStringTable(30);
    sPokemonNameTable = Text_GetStringTable(36);
    sMoveNameTable = Text_GetStringTable(37);
    sStatusConditionNameTable = Text_GetStringTable(41);
    sBattleControllerDisconnectedMessage = Text_GetStringTable(20);

    for (i = 0; i < 7; i++) {
        sBattleSceneStateTickSlots[i].callback = sBattleSceneStateTickSentinel;
    }

    BattleScene_ResetParticipantAuxTransform(sActivePokemon[0], sActivePokemon[0], 1);
    BattleScene_ResetParticipantAuxTransform(sActivePokemon[1], sActivePokemon[1], -1);
    BattleScene_InitializePresentation(session_teams);
    Battle_InitializeActiveRuntimeState();
    Battle_InitializeMoveIllegalityMask(sActivePokemon[0]);
    Battle_InitializeMoveIllegalityMask(sActivePokemon[1]);
    BattleBox_Close();
}

/**
 * Per-frame idle presentation for both participants.
 */
void BattleScene_UpdateParticipantsAndQueueEffects(UNUSED ActivePokemon* side1_pokemon, UNUSED ActivePokemon* side2_pokemon) {
    Battle_AdvanceSecondaryModelAnimIfFinished(sActivePokemon[0], sActivePokemon[0]);
    Battle_AdvanceSecondaryModelAnimIfFinished(sActivePokemon[1], sActivePokemon[1]);
    BattleAnim_UpdateOwnerStatusIdleAnimation(0);
    BattleAnim_UpdateOwnerStatusIdleAnimation(1);
    BattleScene_TryQueueIdleCueEffect(sActivePokemon[0]);
    BattleScene_TryQueueIdleCueEffect(sActivePokemon[1]);
}

/**
 * Battle scene lifecycle dispatcher: allocate (0), update (1, 2),
 * initialize (3) and HUD render (5). Always returns 0.
 */
s32 BattleScene_DispatchLifecycle(s32 lifecycle_stage, BattleSessionTeams* session_teams) {
    switch (lifecycle_stage) {
        case 0:
            BattleScene_AllocateParticipants(session_teams);
            break;

        case 1:
        case 2:
            BattleScene_UpdateParticipantsAndQueueEffects(sActivePokemon[0], sActivePokemon[1]);
            break;

        case 3:
            BattleScene_InitializeRuntime(session_teams);
            break;

        case 5:
            Battle_RenderHud();
            break;
    }

    return 0;
}

/**
 * Empty callback. Not referenced by any state row.
 */
void func_84307414(ActivePokemon* active_pokemon) {
}

/**
 * Empty state row callback.
 */
void BattleScene_StateRow56EnterNop(ActivePokemon* active_pokemon) {
}

/**
 * Empty state row callback.
 */
void BattleScene_StateRow5Slot3Nop(ActivePokemon* active_pokemon) {
}

/**
 * Empty state row callback.
 */
void BattleScene_StateRow5Slot4Nop(ActivePokemon* active_pokemon) {
}

/**
 * Empty state row callback.
 */
void BattleScene_StateRow5Slot5Nop(ActivePokemon* active_pokemon) {
}

/**
 * Empty state row callback.
 */
void BattleScene_StateRow5Slot6Nop(ActivePokemon* active_pokemon) {
}

/**
 * Empty state row callback.
 */
void BattleScene_StateRow7Slot5Nop(ActivePokemon* active_pokemon) {
}

/**
 * Empty state row callback.
 */
void BattleScene_StateRow6Slot6Nop(ActivePokemon* active_pokemon) {
}

/**
 * Empty state row callback.
 */
void BattleScene_StateRow6Slot5Nop(ActivePokemon* active_pokemon) {
}

/**
 * Empty state row callback.
 */
void BattleScene_StateRow6Slot4Nop(ActivePokemon* active_pokemon) {
}

/**
 * Empty state row callback.
 */
void BattleScene_StateRow6Slot3Nop(ActivePokemon* active_pokemon) {
}

/**
 * Empty callback. Not referenced by any state row.
 */
void func_8430746C(ActivePokemon* active_pokemon) {
}

/**
 * Empty function. Not referenced in C.
 */
void func_84307474(UNUSED ActivePokemon* active_pokemon, UNUSED s32 unused) {
}

/**
 * Empty function. Not referenced in C.
 */
void func_84307480(UNUSED ActivePokemon* active_pokemon, UNUSED s32 unused) {
}

/**
 * Empty state row callback.
 */
void BattleScene_StateRow7Slot4Nop(ActivePokemon* active_pokemon) {
}
