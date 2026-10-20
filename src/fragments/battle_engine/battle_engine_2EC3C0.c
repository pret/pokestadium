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

// called on any fade in battle
void BattleScene_ClearStateTickCallbacks(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        sBattleSceneStateTickSlots[i].unk_04 = sBattleSceneStateTickSentinel;
    }
}

// called on move select... sometimes. called on faint
void BattleScene_QueueRowEffectList3(ActivePokemon* actor, s32 move_id) {
    BattleAnim_QueueEffectList3(move_id, &actor->displayObject, &actor->displayObject, 0xFF, 0xFF);
}

// played on gengar using thunderbolt in bug boy glc fight
void BattleAnim_PlayMoveEffectScriptA(ActivePokemon* user, s32 move_id) {
    UNUSED s16 pad;
    s16 camera_shot;
    s32 user_side_index;

    user_side_index = BattleScene_GetParticipantSideIndex(user) == 0;
    camera_shot = Battle_GetCameraShotFieldB(user);
    BattleAnim_QueueMoveEffectScriptA(move_id, user, sActivePokemon[user_side_index], camera_shot, Battle_GetCameraShotFieldC(user));
}

// guess: plays during changing moves like skull base
// but for some reason connected to fury swipes too?
void BattleAnim_PlayMoveEffectScriptB(ActivePokemon* user, s32 move_id) {
    UNUSED s16 pad;
    s16 camera_shot;
    s32 user_side_index;

    user_side_index = BattleScene_GetParticipantSideIndex(user) == 0;
    camera_shot = Battle_GetCameraShotFieldB(user);
    BattleAnim_QueueMoveEffectScriptB(move_id, user, sActivePokemon[user_side_index], camera_shot, Battle_GetCameraShotFieldC(user));
}

// play on move end
void BattleAnim_PlayMoveEffectEnd(ActivePokemon* user, s32 move_id) {
    UNUSED s16 pad;
    s16 default_anchor; // TODO: more descriptive name
    s32 user_side;

    user_side = BattleScene_GetParticipantSideIndex(user) == 0;
    default_anchor = Battle_GetSideAnimTableFieldB(user);
    BattleAnim_QueueMoveEffectEnd(move_id, sActivePokemon[user_side], user, default_anchor, Battle_GetSideAnimTableFieldC(user));
}

// play on move end
void BattleScene_TickClearAnimRecordIfLoaded(ActivePokemon* active_pokemon) {
    if (BattleAnim_TryRegisterAssetTables(active_pokemon) != 0) {
        active_pokemon->animationTimer = 0;
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    }
}

// triggers on faint
void BattleScene_TickStartRowAnimRecord(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    s32 idx = active_pokemon->animationState;
    s32 sp24 = sBattleSceneStateRowTable[idx].unk_20;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[sp24];
    if (BattleAnim_TryRegisterAssetTables(active_pokemon) != 0) {
        BattleAnim_SetModelEventTrackAndState(active_pokemon, sp24, 2);
        active_pokemon->animationTimer = 0;
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
    }
}

// trigger unknown
void BattleScene_TickQueueRowEffectList3AtAnimEnd(ActivePokemon* active_pokemon) {
    s32 idx = active_pokemon->animationState;
    s32 sp28 = sBattleSceneStateRowTable[idx].unk_20;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[sp28];
    if (BattleScene_GetParticipantModelHeight(active_pokemon) != 0.0f) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    } else if ((active_pokemon->animationTimer == (sCurrentAnimation->animationDuration + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleScene_QueueRowEffectList3(active_pokemon, sBattleSceneStateRowTable[idx].mode);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    }
}

// triggers on waiting for move selection
void BattleScene_ResetStateFrameCounter(ActivePokemon* active_pokemon) {
    active_pokemon->animationTimer = 0;
}

// trigger on up on the dialogue box disappearing after move use
void BattleScene_ResetOpponentStateFrameCounter(ActivePokemon* active_pokemon) {
    sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->animationTimer = 0;
}

// trigger on up on the dialogue box disappearing after move use
// used to animate moves that throw rocks
void BattleAnim_SetOverlayFlagForSpecialMoves(ActivePokemon* active_pokemon) {
    BattleMonRuntime* active_pokemon_runtime = &active_pokemon->state.runtime;

    if (active_pokemon_runtime->usedMove == STRENGTH || active_pokemon_runtime->usedMove == ROCK_SLIDE || active_pokemon_runtime->usedMove == ROCK_THROW) {
        sActivePokemon[0]->displayObject.node.renderFlags |= 2;
        sActivePokemon[1]->displayObject.node.renderFlags |= 2;
    }
}

// triggers at the end of move animations and at the end of damage animation of using a rock throwing move
void BattleAnim_ClearOverlayFlag(ActivePokemon* active_pokemon) {
    sActivePokemon[0]->displayObject.node.renderFlags &= ~2;
    sActivePokemon[1]->displayObject.node.renderFlags &= ~2;
}

/*
    Can only guess the semantic guess is correct
*/
s32 BattleAnim_IsAssetLoadBusy(ActivePokemon* active_pokemon) {
    return active_pokemon->sessionTeams->assetIsBusy & 0xD0;
}

s32 BattleAnim_PollAssetLoadBusyFlags(ActivePokemon* active_pokemon) {
    PokeIcon_PollBackgroundForObject(active_pokemon->sessionTeams);
    return active_pokemon->sessionTeams->assetIsBusy & 0xC0;
}

s32 BattleAnim_IsSessionBusy(ActivePokemon* active_pokemon) {
    return active_pokemon->sessionTeams->uniqueStatusFlags & 0xD0;
}

s32 BattleAnim_TryRegisterAssetTables(ActivePokemon* active_pokemon) {
    if (BattleAnim_PollAssetLoadBusyFlags(active_pokemon) == 0) {
        BattleAnim_RegisterAssetTablesForSession(active_pokemon->sessionTeams);
        return 1;
    }
    return 0;
}

void BattleScene_LoadMoveResourceList(ActivePokemon* active_pokemon) {
    // FAKE
    if (sBattleScene.unk_00->unk_48 == 0xE) {
        BattleAnim_LoadMoveResourceList(active_pokemon->sessionTeams, BattleScene_GetActiveAnimRowId(active_pokemon));
    } else {
        BattleAnim_LoadMoveResourceList(active_pokemon->sessionTeams, BattleScene_GetActiveAnimRowId(active_pokemon));
    }
}

void BattleScene_LoadRowResourceList(ActivePokemon* active_pokemon) {
    s32 idx = active_pokemon->animationState;

    BattleAnim_LoadModeResourceList(active_pokemon->sessionTeams, sBattleSceneStateRowTable[idx].mode);
}

void BattleScene_ReloadMoveResourceList(ActivePokemon* active_pokemon) {
    BattleAnim_LoadMoveResourceList(active_pokemon->sessionTeams, BattleScene_GetActiveAnimRowId(active_pokemon));
}

void Battle_MakeSubstitute(ActivePokemon* active_pokemon) {
    active_pokemon->sessionTeams->displayModel = SUBSTITUTE_DOLL;
    active_pokemon->sessionTeams->uniqueStatusFlags |= 0x80;
}

void BattleScene_DestroySubstitute(ActivePokemon* active_pokemon) {
    active_pokemon->sessionTeams->unk_04 = &active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08];
    active_pokemon->sessionTeams->uniqueStatusFlags |= 0x80;
    active_pokemon->sessionTeams->displayModel = active_pokemon->state.model;
}

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

void Battle_MarkIllegalMoves(ActivePokemon* pokemon, u16 pokemon_id, SpeciesLearnsetBuffer* first_learnset_buffer, SpeciesLearnsetBuffer* second_learnset_buffer) {
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
                if ((first_learnset_buffer->unk_00[i] != 0) && (pokemon_runtime->unk_26 >= first_learnset_buffer->unk_00[i]) &&
                    (first_learnset_buffer->unk_0A[i] == pokemon_runtime->moves[move_index])) {
                    pokemon->state.moveSlotIllegality[move_index] = 0;
                }
            }

            for (i = 0; i < 10; i++) {
                if ((second_learnset_buffer->unk_00[i] != 0) && (pokemon_runtime->unk_26 >= second_learnset_buffer->unk_00[i]) &&
                    (second_learnset_buffer->unk_0A[i] == pokemon_runtime->moves[move_index])) {
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

void Battle_InitializeMoveIllegalityMask(ActivePokemon* active_pokemon) {
    active_pokemon->state.moveSlotIllegality[0] = 1;
    active_pokemon->state.moveSlotIllegality[1] = 1;
    active_pokemon->state.moveSlotIllegality[2] = 1;
    active_pokemon->state.moveSlotIllegality[3] = 1;

    Battle_MarkIllegalMoves(active_pokemon, active_pokemon->state.runtime.id - 1, &active_pokemon->unk_94C, &active_pokemon->unk_9AC);

    if (sPlayerTagTeam[BattleScene_GetParticipantSideIndex(active_pokemon)]->firstPartner != 0) {
        Battle_MarkIllegalMoves(active_pokemon, sPlayerTagTeam[BattleScene_GetParticipantSideIndex(active_pokemon)]->firstPartner - 1, &active_pokemon->unk_96C, &active_pokemon->unk_9CC);
    }

    if (sPlayerTagTeam[BattleScene_GetParticipantSideIndex(active_pokemon)]->secondPartner != 0) {
        Battle_MarkIllegalMoves(active_pokemon, sPlayerTagTeam[BattleScene_GetParticipantSideIndex(active_pokemon)]->secondPartner - 1, &active_pokemon->unk_98C, &active_pokemon->unk_9EC);
    }
}

void Battle_DmaLoadAnimRecord(u8 read_end, u32 write_start) {
    u32 temp_a1 = (u32)_70D3A0_ROM_START + ((u32)&D_72780[read_end - 1] & 0xFFFFFF);

    Dma_WriteChunks(write_start, temp_a1, temp_a1 + 0x20, 0);
}

void Battle_DmaLoadAnimRecordPair(s32 read_end, SpeciesLearnsetBuffer* first_learnset_buffer, SpeciesLearnsetBuffer* second_learnset_buffer) {
    UNUSED s32 pad[3];
    u32 buffer_start;

    buffer_start = (u32)_70D3A0_ROM_START + ((u32)&D_72780[read_end] & 0xFFFFFF);
    Dma_WriteChunks(first_learnset_buffer, buffer_start, buffer_start + 0x20, 0);
    buffer_start = (u32)_70D3A0_ROM_START + ((u32)&D_73A60[read_end] & 0xFFFFFF);
    Dma_WriteChunks(second_learnset_buffer, buffer_start, buffer_start + 0x20, 0);
}

void Battle_LoadAnimationAndMarkMoveIllegality(ActivePokemon* pokemon, s32 mark_move_illegality) {
    s16 sp6E;
    s32 side_index;
    s16 object_type_index;
    u32 var_a1;
    s32 pad[8];
    BattleMon* ptr;
    SpeciesModelTransform* ptr2;
    u32 tmp;

    side_index = BattleScene_GetParticipantSideIndex(pokemon);
    object_type_index = pokemon->displayObject.objectType - 1;

    ptr = &pokemon->sessionTeams->teamMember[pokemon->state.unk_2C]->pokemonPicked[pokemon->state.unk_18];

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)D_80075BD0[object_type_index] & 0xFFFFFF);
    if ((pokemon->displayObject.objectType == 0x19) && (ptr->unk_52 & 0x80)) {
        var_a1 = (u32)_70D3A0_ROM_START + ((u32)D_80075BD0[152] & 0xFFFFFF);
    }
    tmp = ((u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (object_type_index << 5)) & 0xFFFFFF)) + 0x20;
    Dma_WriteChunks(sSideBattleCues[side_index], var_a1, var_a1 + 0xBC0, 0);

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (object_type_index << 5)) & 0xFFFFFF);
    Dma_WriteChunks(D_84384580[side_index], var_a1, tmp, 0);

    if (side_index == 1) {
        var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (object_type_index << 5)) & 0xFFFFFF);
        Dma_WriteChunks(D_84384578[side_index], var_a1, var_a1 + 0x20, 0);

        ptr2 = D_84384578[side_index];
        if (ptr2->unk_10 != 0xFF) {
            sp6E = ptr2->unk_10;

            var_a1 = ((u32)_70D3A0_ROM_START) + (((u32)(D_6E910 + ((ptr2->unk_10 - (tmp = 2)) * 0x20))) & 0xFFFFFF);
            Dma_WriteChunks(ptr2, var_a1, var_a1 + 0x20, 0);

            D_84384578[side_index]->unk_10 = sp6E;
        }
    } else {
        var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (object_type_index << 5)) & 0xFFFFFF);
        Dma_WriteChunks(D_84384578[side_index], var_a1, var_a1 + 0x20, 0);
    }

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_70B10 + (object_type_index * 0x20)) & 0xFFFFFF);
    Dma_WriteChunks(&sDefaultSwayLayout, var_a1, var_a1 + 0x20, 0);

    BattleAnim_Vec3fCopy(&pokemon->swayState.layoutConfig.unk_00, &sDefaultSwayLayout.unk_00);
    BattleAnim_Vec3fCopy(&pokemon->swayState.layoutConfig.unk_0C, &sDefaultSwayLayout.unk_0C);

    pokemon->swayState.layoutConfig.unk_18 = sDefaultSwayLayout.unk_18;
    pokemon->swayState.layoutConfig.unk_19 = sDefaultSwayLayout.unk_19;
    pokemon->swayState.layoutConfig.unk_1A = sDefaultSwayLayout.unk_1A;
    pokemon->swayState.layoutConfig.unk_1B = sDefaultSwayLayout.unk_1B;
    pokemon->swayState.layoutConfig.unk_00.x *= pokemon->unk_4B0;
    pokemon->swayState.layoutConfig.unk_0C.x *= pokemon->unk_4B0;

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_70110 + (object_type_index << 4)) & 0xFFFFFF);
    Dma_WriteChunks(&D_84390028[side_index], var_a1, var_a1 + 0x10, 0);

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_71E10 + (object_type_index * 0x10)) & 0xFFFFFF);
    Dma_WriteChunks(sPlayerTagTeam[side_index], var_a1, var_a1 + 0x10, 0);

    Battle_DmaLoadAnimRecordPair(object_type_index, &pokemon->unk_94C, &pokemon->unk_9AC);

    if (sPlayerTagTeam[side_index]->firstPartner != 0) {
        Battle_DmaLoadAnimRecordPair(sPlayerTagTeam[side_index]->firstPartner - 1, &pokemon->unk_96C, &pokemon->unk_9CC);
    }

    if (sPlayerTagTeam[side_index]->secondPartner != 0) {
        Battle_DmaLoadAnimRecordPair(sPlayerTagTeam[side_index]->secondPartner - 1, &pokemon->unk_98C, &pokemon->unk_9EC);
    }

    if (mark_move_illegality == 1) {
        Battle_InitializeMoveIllegalityMask(pokemon);
    }
}

void BattleScene_TickRow10CleanupAndEnterState18(ActivePokemon* active_pokemon) {
    if (active_pokemon->animationTimer == 0x14) {
        active_pokemon->sessionTeams->uniqueStatusFlags |= 0x80;
    }

    if (active_pokemon->sessionTeams->uniqueStatusFlags & 0x10) {
        active_pokemon->sessionTeams->uniqueStatusFlags &= ~0x90;
        Battle_LoadOwnerModelForSwitchIn(active_pokemon);
        BattleScene_TickOwnerCameraFraming(active_pokemon);
        Audio_PlayCommand(2, 0, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        BattleScene_EnterStateRow(active_pokemon, 0x12);
    }
}

// Think this has to do with Surf's Animation
void BattleScene_EnterRow3StartMoveAnim(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    ActivePokemonState* pokemon_state;
    s32 side_index;
    s16 object_type_index;
    u8 tmp;

    object_type_index = active_pokemon->displayObject.objectType - 1;
    runtime = &active_pokemon->state.runtime;
    pokemon_state = &active_pokemon->state;
    side_index = BattleScene_GetParticipantSideIndex(active_pokemon);

    sCurrentAnimation = &sSideBattleCues[side_index]->moveCues[runtime->usedMove - 1];

    if (!(pokemon_state->flags & 2)) {
        active_pokemon->animationTimer = 0;

        if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            tmp = BattleScene_GetParticipantSideIndex(active_pokemon);
            func_80048060(tmp, runtime->usedMove, PARTNER_PIKACHU, 0);
        } else {
            tmp = BattleScene_GetParticipantSideIndex(active_pokemon);
            func_80048060(tmp, runtime->usedMove, object_type_index + 1, 0);
        }

        if ((pokemon_state->flags & 0x4000) && ((object_type_index == 0x32) || (object_type_index == 0x31))) {
            Battle_ClearRuntimeFlags(active_pokemon, 8);
            active_pokemon->displayObject.node.renderFlags |= 0x20;
            Battle_SetRuntimeFlags(active_pokemon, 0x10);
            Battle_ClearRuntimeFlags(active_pokemon, 0x4000);
        }

        BattleAnim_SetOverlayFlagForSpecialMoves(active_pokemon);
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
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    } else if ((active_pokemon->animationTimer == (sCurrentAnimation->animationDuration + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        if (sBattleScene.unk_00->unk_48 == 0x14) {
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        } else if (pokemon_runtime->moveCache.lastMove == DIG) {
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        } else {
            if (pokemon_runtime->moveCache.lastMove == WITHDRAW) {
                // Special Withdraw Animations
                if ((species != WARTORTLE_OB1) && (species != BLASTOISE_OB1) && (species != CLOYSTER_OB1) && (species != SQUIRTLE_OB1)) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 0xC, 0);
                    BattleAnim_PlayMoveEffectScriptA(active_pokemon, pokemon_runtime->usedMove);
                }
            } else {
                if (pokemon_runtime->moveCache.lastMove == SEISMIC_TOSS) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 8, 0);
                } else if (pokemon_runtime->moveCache.lastMove == SURF) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 0xA, 0);
                } else if (pokemon_runtime->moveCache.lastMove == MEDITATE) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 0xD, 0);
                } else if (pokemon_runtime->moveCache.lastMove == WATERFALL) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 0xE, 0);
                } else if (pokemon_runtime->moveCache.lastMove == MINIMIZE) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 9, 0);
                } else {
                    BattleScene_SetParticipantModelFlags(active_pokemon, sCurrentAnimation->flags1, 0);
                }

                if ((pokemon_runtime->usedMove == FURY_SWIPES) && (D_84390230 == D_8439022C)) {
                    BattleAnim_PlayMoveEffectScriptB(active_pokemon, pokemon_runtime->usedMove);
                } else {
                    BattleAnim_PlayMoveEffectScriptA(active_pokemon, pokemon_runtime->usedMove);
                }
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow3PostEffectCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];

    if (active_pokemon->animationTimer == (sCurrentAnimation->animationDuration + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (sBattleScene.unk_00->unk_48 == 0x18) {
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
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        }
    }
}

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
                (D_843C4E45 == 1)) {
                BattleAnim_QueueEffectList6(3, active_pokemon);
                Audio_PlayCommand(0x23, 0, 0);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_MakeGoldenWhenHarden(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];

    if (runtime->usedMove == HARDEN) {
        Model_SetMaterialTextureMode(&active_pokemon->displayObject, 1);
    }
}

#define DIGLETT_OB1 (DIGLETT - 1)
#define DUGTRIO_OB1 (DUGTRIO - 1)
void BattleScene_EnterRow21StartAnimRecord0(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    ActivePokemonState* active_pokemon_state = &active_pokemon->state;
    s16 species_ob1;

    species_ob1 = active_pokemon->displayObject.objectType - 1;
    sCurrentAnimation = sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues;

    if (!(active_pokemon_state->flags & 2)) {
        active_pokemon->animationTimer = 0;
        if ((active_pokemon_state->flags & 0x4000) && ((species_ob1 == DUGTRIO_OB1) || (species_ob1 == DIGLETT_OB1))) {
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

void BattleScene_TickRow21PlaySpeciesSound(ActivePokemon* active_pokemon) {
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[0];
    if ((active_pokemon->animationTimer == (sCurrentAnimation->animationDuration + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        func_800479C0(1, active_pokemon->displayObject.objectType, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    }
}

void BattleScene_EnterRow19StartMoveAnimMidFrame(ActivePokemon* active_pokemon) {
    ActivePokemonState* pokemon_state;
    BattleMonRuntime* runtime;

    pokemon_state = &active_pokemon->state;
    runtime = &active_pokemon->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[runtime->usedMove - 1];

    if (pokemon_state->flags & 2) {
        return;
    }

    active_pokemon->animationTimer = sCurrentAnimation->unk_06;
    if (!(pokemon_state->flags & 0x4000)) {
        BattleAnim_SetOverlayFlagForSpecialMoves(active_pokemon);
        ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
        ModelAnim_SetFrame(&active_pokemon->displayObject, sCurrentAnimation->unk_06);
        if (sCurrentAnimation->unk_01 != 0xFF) {
            ModelAnim_SetEventTrack(&active_pokemon->displayObject, sCurrentAnimation->unk_01);
            ModelAnim_SetEventFrame(&active_pokemon->displayObject, sCurrentAnimation->unk_06);
            pokemon_state->unk_36 = 1;
        }
    }
}

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
        if (sBattleScene.unk_00->unk_48 == 0x14) {
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
            return;
        }

        if ((runtime->usedMove == FURY_SWIPES) && (D_84390230 == D_8439022C)) {
            BattleAnim_PlayMoveEffectScriptB(active_pokemon, runtime->usedMove);
        } else {
            BattleAnim_PlayMoveEffectScriptA(active_pokemon, runtime->usedMove);
        }

        if (runtime->moveCache.lastMove == SEISMIC_TOSS) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 8, 0);
        } else if (runtime->moveCache.lastMove == SURF) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 0xA, 0);
        } else {
            BattleScene_SetParticipantModelFlags(active_pokemon, sCurrentAnimation->flags1, 0);
        }
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickRow19PostEffectCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp18;
    s32 var_v0;

    sp18 = &active_pokemon->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[sp18->usedMove - 1];

    if (sp18->usedMove == FURY_SWIPES) {
        var_v0 = sCurrentAnimation->animationDuration + 30;
    } else {
        var_v0 = sCurrentAnimation->animationDuration + 1;
    }

    if (var_v0 == active_pokemon->animationTimer) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (sBattleScene.unk_00->unk_48 == 0x18) {
                D_84390234--;
                if (D_84390234 < 0) {
                    if (sBattleMoveFailed != 0) {
                        BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp18, 2);
                    } else {
                        BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp18, 0);
                    }
                } else {
                    BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp18, 3);
                }
            } else if (sBattleMoveFailed != 0) {
                BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp18, 2);
            } else {
                BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp18, 0);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_EnterRow4StartHitReactionAnim(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[3];
    s32 side;
    ActivePokemonState* pokemon_state;
    UNUSED s32 pad2;
    s32 temp_v0;
    BattleMonRuntime* runtime;
    ActivePokemon* pokemon;

    runtime = &active_pokemon->state.runtime;
    side = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    pokemon_state = &sActivePokemon[side]->state;
    pokemon = sActivePokemon[side];
    sCurrentAnimation = &sSideBattleCues[side]->hitCue;

    if (pokemon_state->flags & 1) {
        temp_v0 = BattleScene_ByteArrayContains(pokemon->displayObject.objectType, sPokemonWithAlternateSleepHitReactions, 2);
        if (temp_v0 != 0) {
            sCurrentAnimation = &sSideBattleCues[side]->unk_B20;
        }
    }

    sActivePokemon[side]->animationTimer = 0;

    if (!(pokemon_state->flags & 0x200) && !(pokemon_state->flags & 0x4000) && !(pokemon_state->flags & 2)) {
        if (((D_843C4DEC < 0xA) || (sBattleMoveFailed != 0)) && ((runtime->unk_15 & 0x20) == 0)) {
            sCurrentAnimation = &sSideBattleCues[side]->idleCues;
            if (pokemon_state->flags & 0x200) {
                sCurrentAnimation = &sSideBattleCues[side]->unk_B00;
            }
        } else if (!(pokemon_state->flags & 1)) {
            BattleAnim_SetModelEventTrackAndState(sActivePokemon[side], 0xA8, 1);
        }

        if ((D_843C4DEC >= 0xB) && (BattleScene_IsPartnerPikachu(sActivePokemon[side]) != 0)) {
            Cry_Play(PARTNER_PIKACHU, 6);
        }

        if ((D_843C4DEC == 0xA) && (BattleScene_IsPartnerPikachu(sActivePokemon[side]) != 0)) {
            Cry_Play(PARTNER_PIKACHU, 5);
        }

        if ((sBattleMoveFailed == 0) && (runtime->usedMove == LEECH_SEED)) {
            sCurrentAnimation = &sSideBattleCues[side]->hitCue;
        }

        ModelAnim_SetFrame(&sActivePokemon[side]->displayObject, 0);
        ModelAnim_SetAnimation(&sActivePokemon[side]->displayObject, sCurrentAnimation->id);

        if ((runtime->moveCache.lastMove == STOMP) || (runtime->moveCache.lastMove == BODY_SLAM) || (runtime->moveCache.lastMove == SEISMIC_TOSS)) {
            BattleScene_SetParticipantModelFlags(sActivePokemon[side], 0xF, 0);
        }
    }
}

void BattleScene_TickPlayMoveEffectEnd(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    s32 side;

    runtime = &active_pokemon->state.runtime;
    side = BattleScene_GetParticipantSideIndex(active_pokemon);

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->moveCues[runtime->usedMove - 1];

    if (sActivePokemon[side == 0]->animationTimer == (sCurrentAnimation->unk_07 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            BattleAnim_CleanupEffects(1);
            if (runtime->moveCache.lastMove == STRING_SHOT) {
                if ((D_843C4E45 != 0) && (sConfused != 0)) {
                    BattleAnim_PlayMoveEffectEnd(sActivePokemon[side == 0], runtime->usedMove);
                    BattleScene_SetParticipantModelFlags(sActivePokemon[side == 0], 0x10, 0);
                }
            } else {
                BattleAnim_PlayMoveEffectEnd(sActivePokemon[side == 0], runtime->usedMove);
                if ((runtime->moveCache.lastMove == BIND) || (runtime->moveCache.lastMove == WRAP) || (runtime->moveCache.lastMove == CONSTRICT)) {
                    BattleScene_SetParticipantModelFlags(sActivePokemon[side == 0], 0x10, 0);
                }
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow4PostEndCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    s32 side;

    side = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    runtime = &active_pokemon->state.runtime;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->moveCues[runtime->usedMove - 1];

    if ((sCurrentAnimation->unk_07 + 1) == sActivePokemon[side]->animationTimer) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (sConfused == 1) {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[side], runtime, 1);
            } else {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[side], runtime, 5);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_EnterRow15StartAnimA80Seq30(ActivePokemon* active_pokemon) {
    s32 sp1C = BattleScene_GetParticipantSideIndex(active_pokemon);

    sCurrentAnimation = &sSideBattleCues[sp1C]->hitCue;
    sActivePokemon[sp1C]->animationTimer = 0;
    ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
    ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
    BattleAnim_SetModelEventTrackAndState(sActivePokemon[sp1C], 0xA8, 1);
    BattleAnim_PlayBattleSequenceById(active_pokemon, 0x1E);
}

s32 BattleScene_IsOpponentRowCheckpointReached(ActivePokemon* active_pokemon) {
    BattleMonRuntime* side;

    side = &sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[side->usedMove - 1];
    if (sCurrentAnimation->unk_0C != 0) {
        if (active_pokemon->animationTimer == sCurrentAnimation->unk_0C) {
            return 1;
        }
        return 0;
    }
    return 0;
}

s32 BattleScene_IsRowZeroCheckpointReached(ActivePokemon* active_pokemon) {
    BattleScene_GetParticipantSideIndex(active_pokemon);
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[0];
    if (sCurrentAnimation->unk_0C != 0) {
        if (active_pokemon->animationTimer == sCurrentAnimation->unk_0C) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void func_84303E58(ActivePokemon* active_pokemon) {
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->hitCue;
    BattleAnim_SetModelEventTrackFromRow(active_pokemon, 0xA8);
    active_pokemon->animationTimer = 0;
    ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
    ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
}

void BattleScene_EnterRowAnim166WithCry(ActivePokemon* active_pokemon) {
    s32 idx = active_pokemon->animationState;
    s32 temp_a0;
    s32 sp34;
    BattleMon* sp30;
    ActivePokemonState* sp24;

    sp34 = sBattleSceneStateRowTable[idx].unk_20;
    sp30 = &active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08];
    sp24 = &active_pokemon->state;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[sp34];
    temp_a0 = sp24->flags & 2;

    if ((temp_a0 == 0) && !(sp24->flags & 0x4000) && (temp_a0 == 0)) {
        if (sp30->statusCondition & 7) {
            if (BattleScene_ByteArrayContains(active_pokemon->displayObject.objectType, sPokemonWithAlternateSleepIdle, 8) != 0) {
                sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->chargeCues[0x60];
            } else {
                sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->idleCues;
            }
        } else if (sp24->flags & 0x200) {
            sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_B00;
        }

        ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);

        if (sp24->flags & 0x200) {
            if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0x1A);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 0x1A);
            }
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0xA);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 0xA);
        }
    }
}

void BattleScene_TickRow1PlayOwnerCry(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    ActivePokemonState* state = &active_pokemon->state;
    BattleMon* party_pokemon_ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08];

    if ((state->flags & 0x4000) || (state->flags & 2) || (party_pokemon_ptr->statusCondition & 7)) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    } else if (active_pokemon->animationTimer == 1) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (active_pokemon->displayObject.objectType >= 0x98) {
                BattleAnim_PlayOwnerCry(active_pokemon, state->model);
            } else {
                BattleAnim_PlayOwnerCry(active_pokemon, active_pokemon->displayObject.objectType);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow16PlayCryAndSpeciesSound(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    BattleMon* party_pokemon_ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08];
    ActivePokemonState* state = &active_pokemon->state;

    if ((active_pokemon->state.flags & 0x4000) || (state->flags & 2) || (party_pokemon_ptr->statusCondition & 7)) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    } else if ((active_pokemon->animationTimer == 1) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        if (active_pokemon->displayObject.objectType >= 0x98) {
            Cry_Play(state->model, 3);
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            Cry_Play(PARTNER_PIKACHU, 3);
        } else {
            Cry_Play(active_pokemon->displayObject.objectType, 3);
        }

        if (state->flags & 0x200) {
            if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0x1B);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 0x1B);
            }
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0xB);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 0xB);
        }
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickRow18PlayCryAndSpeciesSound(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    BattleMon* party_pokemon_ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08];
    ActivePokemonState* state;

    if ((active_pokemon->state.flags & 0x4000) || (party_pokemon_ptr->statusCondition & 0x20) || (party_pokemon_ptr->statusCondition & 7)) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        return;
    }

    if ((active_pokemon->animationTimer == 1) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        state = &active_pokemon->state;
        if (active_pokemon->displayObject.objectType >= 0x98) {
            Cry_Play(state->model, 4);
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            Cry_Play(0xC8, 4);
        } else {
            Cry_Play(active_pokemon->displayObject.objectType, 4);
        }

        if (state->flags & 0x200) {
            if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0x1B);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 0x1B);
            }
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0xB);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->displayObject.objectType, 0xB);
        }

        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    }
}

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
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    }
}

void func_843046BC(ActivePokemon* active_pokemon) {
    BattleScene_GetParticipantSideIndex(active_pokemon);
    if ((active_pokemon->animationTimer == 1) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        s32 idx = active_pokemon->animationState;

        BattleScene_QueueRowEffectList3(active_pokemon, sBattleSceneStateRowTable[idx].mode);
        Audio_PlayCommand(3, 0, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickRow20CleanupAndEnterState18(ActivePokemon* active_pokemon) {
    if (active_pokemon->animationTimer == 0x4F) {
        active_pokemon->sessionTeams->uniqueStatusFlags |= 0x80;
    }

    if (active_pokemon->sessionTeams->uniqueStatusFlags & 0x10) {
        active_pokemon->sessionTeams->uniqueStatusFlags &= ~0x90;

        Battle_LoadOwnerModelForSwitchIn(active_pokemon);
        BattleScene_TickOwnerCameraFraming(active_pokemon);
        Audio_PlayCommand(2, 0, 0);

        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;

        BattleScene_EnterStateRow(active_pokemon, 0x12);
    }
}

void func_84304800(ActivePokemon* active_pokemon) {
    if (active_pokemon->sessionTeams->uniqueStatusFlags & 0x10) {
        active_pokemon->sessionTeams->uniqueStatusFlags &= ~0x90;
        Battle_ResetOwnerModelToNeutralPlaceholder(active_pokemon);
    }
}

void BattleScene_EnterRow8StartMappedMoveAnim(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    s32 charge_move_cue = sChargeMoveCues[active_pokemon->state.runtime.usedMove - 1];

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[charge_move_cue];
    active_pokemon->animationTimer = 0;
    ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
    ModelAnim_SetAnimation(&active_pokemon->displayObject, sCurrentAnimation->id);
    BattleAnim_SetModelEventTrackFromRow(active_pokemon, charge_move_cue);
}

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
        BattleAnim_PlayMoveEffectScriptB(active_pokemon, runtime->usedMove);

        if (runtime->usedMove == FLY) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 3, 0);
        }

        if ((runtime->usedMove == DIG) && (species_ob1 != DIGLETT_OB1) && (species_ob1 != DUGTRIO_OB1)) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 5, 0);
            BattleAnim_QueueEffectList(4, active_pokemon);
        }

        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;

        BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 4);
    }
}

void BattleScene_EnterRow9SetEventTrack(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[3];
    BattleMon* ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08];
    s32 sp1C;

    active_pokemon->animationTimer = 0;
    if (!(active_pokemon->state.flags & 2)) {
        if (ptr->statusCondition & 7) {
            if (BattleScene_ByteArrayContains(active_pokemon->displayObject.objectType, sPokemonWithAlternateSleepIdle, 8) != 0) {
                sp1C = 0xAF;
            } else {
                sp1C = 0xA5;
            }
        } else {
            sp1C = 0xA5;
        }
        sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[sp1C];
        BattleAnim_SetModelEventTrackFromRow(active_pokemon, sp1C);
    }
}

void BattleScene_EnterRow9QueueEffectList6(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->state.runtime;

    if (runtime->unk_4C & 0x20) {
        if ((runtime->usedMove == BIND) || (runtime->usedMove == WRAP) || (runtime->usedMove == STRING_SHOT)) {
            BattleAnim_QueueEffectList6(2, active_pokemon);
            BattleScene_SetParticipantModelFlags(active_pokemon, 0x10, 0);
        }
    }
}

void BattleScene_Row12Slot1CameraCleanup(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime;
    s32 side;

    side = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    runtime = &active_pokemon->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->moveCues[runtime->usedMove - 1];

    if ((sCurrentAnimation->unk_07 + 1) == sActivePokemon[side]->animationTimer) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            BattleAnim_PlaySpeciesReactionSound(active_pokemon, runtime, 5);
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_Row13PlaySequences14And21(ActivePokemon* active_pokemon) {
    BattleMonRuntime* runtime = &active_pokemon->state.runtime;

    if (runtime->unk_15 & 8) {
        BattleAnim_PlayBattleSequenceById(active_pokemon, 0x14);
    }

    if (runtime->unk_15 & 0x10) {
        BattleAnim_PlayBattleSequenceById(active_pokemon, 0x21);
    }

    sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
}

void BattleScene_TickPlaySpeciesSequence33(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    u16 species = active_pokemon->displayObject.objectType;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->faintCue;
    if ((BattleScene_GetParticipantModelHeight(active_pokemon) != 0.0f) && (species != FEAROW) && (species != MAGNETON) && (species != AERODACTYL)) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    } else if ((active_pokemon->animationTimer == (sCurrentAnimation->animationDuration + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleAnim_PlaySpeciesSequence33(active_pokemon);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickQueueList3Selector2OrC(ActivePokemon* active_pokemon) {
    s32 sp24;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->faintCue;
    if (sCurrentAnimation->unk_09 == 1) {
        sp24 = sCurrentAnimation->unk_0A - 0x4C;
    } else {
        sp24 = sCurrentAnimation->unk_0A - 0x31;
    }

    if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
        if (BattleScene_GetParticipantModelHeight(active_pokemon) != 0.0f) {
            if ((sp24 <= 0) || (sp24 == active_pokemon->animationTimer)) {
                if (sCurrentAnimation->unk_09 == 1) {
                    BattleAnim_QueueEffectList3(2, active_pokemon, active_pokemon, 0xFF, 0xFF);
                } else {
                    BattleAnim_QueueEffectList3(0xC, active_pokemon, active_pokemon, 0xFF, 0xFF);
                }
                Audio_PlayCommand(3, 0, 0);
                sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
            }
        } else if ((sp24 <= 0) || (sp24 == active_pokemon->animationTimer)) {
            if (sCurrentAnimation->unk_09 == 1) {
                BattleAnim_QueueEffectList3(2, active_pokemon, active_pokemon, 0xFF, 0xFF);
            } else {
                BattleAnim_QueueEffectList3(0xC, active_pokemon, active_pokemon, 0xFF, 0xFF);
            }
            Audio_PlayCommand(3, 0, 0);
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickQueueList3Selector2OrCFromB10(ActivePokemon* active_pokemon) {
    s32 sp24;

    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_B10;
    if (sCurrentAnimation->unk_09 == 1) {
        sp24 = sCurrentAnimation->unk_0A - 0x4C;
    } else {
        sp24 = sCurrentAnimation->unk_0A - 0x31;
    }

    if ((BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) && ((sp24 <= 0) || (sp24 == active_pokemon->animationTimer))) {
        if (sCurrentAnimation->unk_09 == 1) {
            BattleAnim_QueueEffectList3(2, active_pokemon, active_pokemon, 0xFF, 0xFF);
        } else {
            BattleAnim_QueueEffectList3(0xC, active_pokemon, active_pokemon, 0xFF, 0xFF);
        }
        Audio_PlayCommand(3, 0, 0);
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    }
}

void func_8430506C(ActivePokemon* active_pokemon) {
    s32 pad3;
    s32 struggle;
    s32 sp44;
    s32 side;
    ActivePokemonState* state;
    s32 pad[2];
    ActivePokemon* active_pokemon_ptr;
    BattleMonRuntime* runtime;

    struggle = STRUGGLE;
    side = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    state = &sActivePokemon[side]->state;
    active_pokemon_ptr = sActivePokemon[side];
    runtime = &active_pokemon->state.runtime;

    sCurrentAnimation = &sSideBattleCues[side]->hitCue;

    if (state->flags & 1) {
        if (BattleScene_ByteArrayContains(active_pokemon_ptr->displayObject.objectType, sPokemonWithAlternateSleepHitReactions, 2) != 0) {
            sCurrentAnimation = &sSideBattleCues[side]->unk_B20;
        }
    }

    if ((state->flags & 1) && BattleScene_ByteArrayContains(active_pokemon_ptr->displayObject.objectType, sPokemonWithAlternateSleepIdle, 8)) {
        struggle = 0xAF;
    }

    sActivePokemon[side]->animationTimer = 0;

    if (!(state->flags & 0x4000) && !(state->flags & 2)) {
        if ((runtime->usedMove == BUBBLE) && (D_843C4DEC < 0xA)) {
            sCurrentAnimation = &sSideBattleCues[side]->moveCues[struggle];
        }

        if ((sConfused == 0) || (sBattleMoveFailed != 0)) {
            sp44 = 0xB0;
            sCurrentAnimation = &sSideBattleCues[side]->moveCues[struggle];
            if (state->flags & 0x200) {
                sCurrentAnimation = &sSideBattleCues[side]->moveCues[sp44];
            }
        } else if (!(state->flags & 1)) {
            BattleAnim_SetModelEventTrackFromRow(sActivePokemon[side], 0xA8);
        }

        ModelAnim_SetFrame(&sActivePokemon[side]->displayObject, 0);
        ModelAnim_SetAnimation(&sActivePokemon[side]->displayObject, sCurrentAnimation->id);

        if ((runtime->moveCache.lastMove == STOMP) || (runtime->moveCache.lastMove == BODY_SLAM) || (runtime->moveCache.lastMove == SEISMIC_TOSS)) {
            BattleScene_SetParticipantModelFlags(sActivePokemon[side], 0xF, 0);
        }
    }
}

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

    if ((sActivePokemon[side == 0]->animationTimer == (sCurrentAnimation->unk_07 + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleAnim_CleanupEffects(1);
        if (((runtime_temp->usedMove == SUPERSONIC) || (runtime_temp->usedMove == CONFUSE_RAY)) && (runtime->unk_4C & 0x80) && (sBattleMoveFailed == 0) &&
            (sConfused == 1)) {
            BattleAnim_PlayBattleSequenceById(sActivePokemon[side == 0], 0x12);
        }

        BattleAnim_PlayMoveEffectEnd(sActivePokemon[side == 0], runtime_temp->usedMove);
        if ((sBattleMoveFailed == 0) || (sConfused == 1)) {
            BattleAnim_PlaySpeciesReactionSound(sActivePokemon[side == 0], &active_pokemon->state.runtime, 1);
        }

        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
    }
}

s32 func_84305458(ActivePokemon* active_pokemon) {
    BattleMonRuntime* ptr = &active_pokemon->state.runtime;
    s32 temp_v1;

    temp_v1 = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    sCurrentAnimation = &sSideBattleCues[temp_v1]->moveCues[ptr->usedMove - 1];

    if (D_843C4E45 != 1) {
        return 2;
    }

    if ((sCurrentAnimation->unk_08 + 0x50) == sActivePokemon[temp_v1]->animationTimer) {
        return 1;
    }

    return 0;
}

void BattleScene_TickRow11QueueEffectList6(ActivePokemon* active_pokemon) {
    BattleMonRuntime* ptr = &active_pokemon->state.runtime;
    s32 sp28;

    sp28 = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->moveCues[ptr->usedMove - 1];
    if (sActivePokemon[sp28]->animationTimer == (sCurrentAnimation->unk_08 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (D_843C4E45 == 1) {
                BattleAnim_QueueEffectList6(1, sActivePokemon[sp28]);
                BattleAnim_PlayBattleSequenceById(active_pokemon, 0x20);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow11PostEndCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp20;
    s32 sp28;

    sp28 = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    sp20 = &active_pokemon->state.runtime;
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->moveCues[sp20->usedMove - 1];

    if ((sCurrentAnimation->unk_07 + 1) == sActivePokemon[sp28]->animationTimer) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (sConfused == 1) {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[sp28], sp20, 1);
            } else {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[sp28], sp20, 5);
            }
            sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04 = sBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_StateCallbackNop(ActivePokemon* active_pokemon) {
}

void BattleScene_RegisterStateTickCallback(ActivePokemon* arg0, BattleSceneStateCallback arg1) {
    BattleSceneStateTickSlot* var_a2;
    s32 i;

    for (i = 0; i < 7; i++) {
        if (sBattleSceneStateTickSentinel == sBattleSceneStateTickSlots[i].unk_04) {
            sBattleSceneStateTickSlots[i].unk_04 = arg1;
            sBattleSceneStateTickSlots[i].unk_00 = arg0;
            break;
        }
    }
}

void BattleScene_SetOpponentEventTrackA6(ActivePokemon* active_pokemon) {
    BattleAnim_SetModelEventTrackFromRow(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon)], 0xA6);
}

void BattleScene_EnterStateRow(ActivePokemon* arg0, s32 arg1) {
    arg0->animationState = arg1;

    sBattleSceneStateRowTable[arg1].unk_04[0](arg0);
    sBattleSceneStateRowTable[arg1].unk_04[1](arg0);
    sBattleSceneStateRowTable[arg1].unk_04[2](arg0);

    BattleScene_RegisterStateTickCallback(arg0, sBattleSceneStateRowTable[arg1].unk_04[3]);
    BattleScene_RegisterStateTickCallback(arg0, sBattleSceneStateRowTable[arg1].unk_04[4]);
    BattleScene_RegisterStateTickCallback(arg0, sBattleSceneStateRowTable[arg1].unk_04[5]);
    BattleScene_RegisterStateTickCallback(arg0, sBattleSceneStateRowTable[arg1].unk_04[6]);
}

void BattleScene_TickStateCallbacks(void) {
    sActivePokemon[0]->animationTimer++;
    sActivePokemon[1]->animationTimer++;

    for (sBattleSceneStateTickSlotIndex = 0; sBattleSceneStateTickSlotIndex < 7; sBattleSceneStateTickSlotIndex++) {
        sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_04(sBattleSceneStateTickSlots[sBattleSceneStateTickSlotIndex].unk_00);
    }
}

void Battle_StopBeingGoldAfterHarden(ActivePokemon* active_pokemon) {
    if (active_pokemon->state.runtime.usedMove == HARDEN) {
        active_pokemon->displayObject.textureMode = 0;
    }
}

void BattleAnim_SetModelEventTrackFromRow(ActivePokemon* pokemon, s32 event) {
    s32 temp_v0;
    s32 sp30;
    ActivePokemonState* sp24 = &pokemon->state;

    if (BattleAnim_IsSessionBusy(pokemon) == 0) {
        sp30 = sSideBattleCues[BattleScene_GetParticipantSideIndex(pokemon)]->moveCues[event].unk_01;
        if ((sp30 != 0xFF) && (sp24->unk_36 != 2)) {
            if ((event == 165) && (pokemon->displayObject.objectType == DUGTRIO)) {
                ModelAnim_SetEventFrame(&pokemon->displayObject, 0);
                temp_v0 = BattleAnim_RandomRange(3);
                if (temp_v0 >= 3) {
                    temp_v0 = 2;
                }
                ModelAnim_SetEventTrack(&pokemon->displayObject, sp30 + temp_v0);
            } else {
                ModelAnim_SetEventFrame(&pokemon->displayObject, 0);
                ModelAnim_SetEventTrack(&pokemon->displayObject, sp30);
                sp24->unk_36 = 1;
            }
        }
    }
}

s32 BattleAnim_TrySetModelEventTrackFromRow(ActivePokemon* active_pokemon, s32 move, s32 arg2) {
    UNUSED s32 pad;
    s32 sp20;

    if (BattleAnim_IsSessionBusy(active_pokemon) != 0) {
        return 0;
    }

    sp20 = sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[move].unk_01;
    if (sp20 == 0xFF) {
        return 1;
    }

    ModelAnim_SetEventFrame(&active_pokemon->displayObject, 0);
    ModelAnim_SetEventTrack(&active_pokemon->displayObject, sp20);
    ModelAnim_SetEventFrame(&active_pokemon->displayObject, active_pokemon->displayObject.eventTrack.data->endFrame);

    active_pokemon->state.unk_36 = arg2;
    return 0;
}

void BattleAnim_SetModelEventTrackAndState(ActivePokemon* arg0, s32 arg1, s32 arg2) {
    u8 temp_a1;

    if (BattleAnim_IsSessionBusy(arg0) == 0) {
        temp_a1 = sSideBattleCues[BattleScene_GetParticipantSideIndex(arg0)]->moveCues[arg1].unk_01;
        if (temp_a1 != 0xFF) {
            ModelAnim_SetEventTrack(&arg0->displayObject, temp_a1);
            ModelAnim_SetEventFrame(&arg0->displayObject, 0);
            arg0->state.unk_36 = arg2;
        }
    }
}

s32 BattleScene_IsParticipantIncapacitated(ActivePokemon* active_pokemon) {
    ActivePokemonState* state = &active_pokemon->state;
    BattleMon* pokemon = &active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08];

    if ((state->flags & 2) || (pokemon->statusCondition & 7) || ((state->flags & 0x200) && !(state->flags & 0x400)) ||
        (state->flags & 0x4000)) {
        return 1;
    }
    return 0;
}

s32 BattleScene_IsRowWaitComplete(ActivePokemon* arg0, s32 arg1) {
    if (BattleScene_IsParticipantIncapacitated(arg0) != 0) {
        if (BattleScene_AdvanceCameraFrameCounter(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if (arg0->displayObject.transformAnim.animationId == -1) {
        return 1;
    }
    return ModelAnim_IsAnimationDone(&arg0->displayObject);
}

s32 BattleScene_IsRowWaitCompleteWithEventCount(ActivePokemon* arg0, s32 arg1) {
    u8 temp_v0;

    sCurrentAnimation = sSideBattleCues[BattleScene_GetParticipantSideIndex(arg0)]->unkA60;
    if (BattleScene_IsParticipantIncapacitated(arg0) != 0) {
        if (BattleScene_AdvanceCameraFrameCounter(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if ((sCurrentAnimation->unk_0A < 0xB) || (sCurrentAnimation->unk_0A == 0xFF)) {
        if (arg0->displayObject.transformAnim.animationId == -1) {
            return 1;
        }
        return ModelAnim_IsAnimationDone(&arg0->displayObject);
    }

    if (BattleScene_AdvanceCameraFrameCounter(sCurrentAnimation->unk_0A + 1) != 0) {
        return 1;
    }

    return 0;
}

s32 Battle_IsRowAnimationSettled(ActivePokemon* arg0, s32 arg1) {
    BattleMonRuntime* ptr = &arg0->state.runtime;
    MovePresentationCue* sp20;
    MovePresentationCue* sp1C;

    if (arg0) {} //karodo

    sp20 = &sSideBattleCues[BattleScene_GetParticipantSideIndex(arg0)]->moveCues[ptr->usedMove - 1];
    sp1C = &sSideBattleCues[BattleScene_GetParticipantSideIndex(arg0)]->idleCues;

    if (BattleScene_IsParticipantIncapacitated(arg0) != 0) {
        if (BattleScene_AdvanceCameraFrameCounter(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if (arg0->displayObject.transformAnim.animationId == -1) {
        return 1;
    }

    if (sBattleScene.unk_00->unk_48 == 0x14) {
        sp20 = &sSideBattleCues[BattleScene_GetParticipantSideIndex(arg0)]->moveCues[0];
    }

    if (sp20->id == sp1C->id) {
        if (sp20->unk_0A != 0xFF) {
            sBattleScene.unk_00->unk_14++;
            if (sp20->unk_0A == arg0->animationTimer) {
                return 1;
            }
            return 0;
        }

        if (BattleScene_AdvanceCameraFrameCounter(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    sBattleScene.unk_00->unk_14++;

    if (sp20->unk_0A != 0xFF) {
        if (sp20->unk_0A == arg0->animationTimer) {
            return 1;
        }
        return 0;
    }

    return ModelAnim_IsAnimationDone(&arg0->displayObject);
}

s32 BattleScene_IsMoveKeyedRowWaitComplete(ActivePokemon* active_pokemon, s32 delta) {
    MovePresentationCue* idle_cue;
    BattleMon* sp28;
    UNUSED s32 pad;
    s32 charge_move;
    MovePresentationCue* move_cue;

    sp28 = &active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08];
    charge_move = sChargeMoveCues[active_pokemon->state.runtime.usedMove - 1];
    move_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->moveCues[charge_move];
    idle_cue = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->idleCues;

    if ((active_pokemon->state.flags & 2) || (sp28->statusCondition & 7) ||
        ((active_pokemon->state.flags & 0x200) && !(active_pokemon->state.flags & 0x400)) || (active_pokemon->state.flags & 0x4000)) {
        if (BattleScene_AdvanceCameraFrameCounter(delta) != 0) {
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
        if (BattleScene_AdvanceCameraFrameCounter(delta) != 0) {
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

s32 BattleScene_IsRowAnimWaitComplete(ActivePokemon* active_pokemon, s32 delta) {
    sCurrentAnimation = &sSideBattleCues[BattleScene_GetParticipantSideIndex(active_pokemon)]->hitCue;

    if ((active_pokemon->state.flags & 2) || ((active_pokemon->state.flags & 0x200) && !(active_pokemon->state.flags & 0x400))) {
        if (BattleScene_AdvanceCameraFrameCounter(delta) != 0) {
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

void func_843060EC(ActivePokemon* active_pokemon) {
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

void Battle_SetRuntimeFlags(ActivePokemon* arg0, u16 arg1) {
    arg0->state.flags |= arg1;
}

s32 Battle_ClearRuntimeFlags(ActivePokemon* arg0, u16 arg1) {
    arg0->state.flags &= ~arg1;
}

void BattleScene_ResetParticipantAnimationFlags(ActivePokemon* active_pokemon) {
    ActivePokemonState* sp24 = &active_pokemon->state;

    if (active_pokemon->unk_4C8 != 0) {
        if (sp24->flags & 0x200) {
            active_pokemon->displayObject.position.y = D_84390028[BattleScene_GetParticipantSideIndex(active_pokemon)].unk_08;
            Battle_ClearRuntimeFlags(active_pokemon, 0x608);
        }

        if (sp24->flags & 0x4008) {
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

void BattleScene_ResetBothParticipantsAnimationState(void) {
    ActivePokemonState* sp34;
    ActivePokemonState* sp30;
    UNUSED s32 pad[2];
    ActivePokemon* sp24;
    ActivePokemon* sp20;

    sp34 = &sActivePokemon[0]->state;
    sp30 = &sActivePokemon[1]->state;
    sp24 = sActivePokemon[0];
    sp20 = sActivePokemon[1];

    if (sp34->flags & 4) {
        sActivePokemon[0]->displayObject.position.y = 200.0f;
        Battle_SetRuntimeFlags(sActivePokemon[0], 0x200);
        Battle_ClearRuntimeFlags(sActivePokemon[0], 4);
    }

    if (sp30->flags & 4) {
        sActivePokemon[1]->displayObject.position.y = 200.0f;
        Battle_SetRuntimeFlags(sActivePokemon[1], 0x200);
        Battle_ClearRuntimeFlags(sActivePokemon[1], 4);
    }

    if ((sp34->flags & 0x4000) && (sp24->displayObject.objectType == 0x33)) {
        sCurrentAnimation = &sSideBattleCues[0]->moveCues[0x5A];
        ModelAnim_SetFrame(&sActivePokemon[0]->displayObject, 0);
        ModelAnim_SetAnimation(&sActivePokemon[0]->displayObject, sCurrentAnimation->id);
    }

    if ((sp30->flags & 0x4000) && (sp20->displayObject.objectType == 0x33)) {
        sCurrentAnimation = &sSideBattleCues[1]->moveCues[0x5A];
        ModelAnim_SetFrame(&sActivePokemon[1]->displayObject, 0);
        ModelAnim_SetAnimation(&sActivePokemon[1]->displayObject, sCurrentAnimation->id);
    }

    BattleScene_ResetParticipantAnimationFlags(sActivePokemon[0]);
    BattleScene_ResetParticipantAnimationFlags(sActivePokemon[1]);
}

void Battle_ClearOpponentHopFlagAndSyncMove(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    ActivePokemonState* sp20;

    sp20 = &sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->state;
    BattleScene_GetParticipantSideIndex(active_pokemon);
    BattleScene_GetParticipantSideIndex(active_pokemon);
    Battle_StopBeingGoldAfterHarden(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]);

    if (sp20->flags & 4) {
        sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->displayObject.position.y = 200.0f;
        Battle_SetRuntimeFlags(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0], 0x200);
        Battle_ClearRuntimeFlags(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0], 4);
    }

    if (active_pokemon->state.flags & 0x200) {
        Battle_SetRuntimeFlags(active_pokemon, 0x400);
    }
}

void BattleScene_CleanupParticipantHideFlag(ActivePokemon* active_pokemon) {
    if (active_pokemon->state.flags & 8) {
        active_pokemon->displayObject.position.y = BattleScene_GetParticipantModelHeight(active_pokemon);
        Battle_ClearRuntimeFlags(active_pokemon, 0x608);
    }
}

void BattleScene_CleanupOpponentSpecialAnimFlag(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    ActivePokemon* sp1C = sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0];

    if (sp1C->state.flags & 0x4000) {
        sp1C->displayObject.node.renderFlags |= 0x20;
        sp1C->displayObject.node.flags |= 1;
        BattleAnim_StopOwnerCategoryParticles(4, sp1C);
        Battle_ClearRuntimeFlags(sp1C, 0x4000);
    }
}

void BattleScene_CleanupOpponentAnimationFlags(ActivePokemon* active_pokemon) {
    ActivePokemon* temp_s0 = sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0];
    ActivePokemonState* ptr = &temp_s0->state;

    if (ptr->flags & 0x4000) {
        temp_s0->displayObject.node.renderFlags |= 0x20;
        temp_s0->displayObject.node.flags |= 1;
        BattleAnim_StopOwnerCategoryParticles(4, temp_s0);
        Battle_ClearRuntimeFlags(temp_s0, 0x4000);
    }

    if (ptr->flags & 8) {
        temp_s0->displayObject.position.y = BattleScene_GetParticipantModelHeight(active_pokemon);
        Battle_ClearRuntimeFlags(temp_s0, 0x608);
    }
}

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
            Vec3s_SetComponents(&active_pokemon->displayObject.rotation, 0, active_pokemon->unk_4B0 << 0xE, 0);
            break;

        case 4:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            active_pokemon->displayObject.rotation.y = active_pokemon->unk_4B0 << 0xE;
            BattleScene_HideParticipantSecondaryModels(active_pokemon);
            break;
    }
}

void BattleAnim_TickParticipantStatusAnimation(ActivePokemon* active_pokemon) {
    ActivePokemonState* temp_s1 = &active_pokemon->state;

    BattleAnim_StartFreezeStatusAnimation(active_pokemon);
    BattleAnim_UpdateSleepStatusAnimation(active_pokemon);

    if (temp_s1->flags & 0x100) {
        active_pokemon->displayObject.node.renderFlags &= 0xFFDF;
    }

    if ((temp_s1->unk_2D == 0x10) || (temp_s1->unk_2D == 0x13)) {
        Battle_ClearRuntimeFlags(active_pokemon, 0x100);
    }

    temp_s1->unk_2E = Math_StepToS32(temp_s1->unk_2E, 0, 0x1E, 0x1E);
    if (temp_s1->unk_2E != 0) {
        Model_SetMaterialColor(&active_pokemon->displayObject, 0xFF, 0xFF, 0xFF, temp_s1->unk_2E);
    }

    switch (temp_s1->unk_36) {
        case 2:
            break;

        case 0:
            if (BattleAnim_RandomRange(0x32) == 2) {
                BattleAnim_SetModelEventTrackFromRow(active_pokemon, 0xA5);
            }
            break;

        case 1:
            if (ModelAnim_IsEventTrackNearEnd(&active_pokemon->displayObject) == 1) {
                ModelAnim_SetEventTrack(&active_pokemon->displayObject, -1);
                ModelAnim_SetEventFrame(&active_pokemon->displayObject, 0);
                temp_s1->unk_36 = 0;
            }
            break;
    }

    if (temp_s1->flags & 0x4000) {
        if ((active_pokemon->displayObject.objectType != 0x32) && (active_pokemon->displayObject.objectType != 0x33)) {
            active_pokemon->displayObject.lodFraction = 0;
        }
    }
}

void BattleAnim_TriggerStatusAfflictionCry(ActivePokemon* active_pokemon) {
    BattleMon* ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08];

    if ((ptr->statusCondition & 7) && !(active_pokemon->state.flags & 1)) {
        BattleAnim_SetModelEventTrackAndState(active_pokemon, 0xAF, 2);
        BattleAnim_QueueEffectList(3, active_pokemon);
        BattleAnim_PlayBattleSequenceById(active_pokemon, 0x32);
    }
}

void BattleScene_AllocateParticipantRecord(BattleSessionTeams* arg0, s32 arg1) {
    ActivePokemon* ptr = main_pool_alloc(sizeof(ActivePokemon), 0);

    sActivePokemon[arg1] = ptr;

    bzero(ptr, sizeof(ActivePokemon));
    bzero(&sActivePokemon[arg1]->state, sizeof(ActivePokemonState));
    bzero(&sActivePokemon[arg1]->state.runtime, sizeof(BattleMonRuntime));
    bzero(&sActivePokemon[arg1]->unk_728, sizeof(PresentationState));
    bzero(&sActivePokemon[arg1]->state.runtime.moveCache, sizeof(CachedMoveData));
    bzero(&sActivePokemon[arg1]->state.unk_9C, sizeof(unk_D_84390010_654_09C));
    bzero(&sActivePokemon[arg1]->state.unk_AC, sizeof(unk_D_84390010_654_0AC));
    bzero(&sActivePokemon[arg1]->unk_8C4, sizeof(MonCaptionState));
    sActivePokemon[arg1]->sessionTeams = arg0;
}

void BattleScene_AllocateParticipants(BattleSessionTeams* battle_teams) {
    BattleScene_AllocateParticipantRecord(&battle_teams[0], 0);
    BattleScene_AllocateParticipantRecord(&battle_teams[1], 1);
    Battle_InitMessageQueues();
    sSide1ActivePokemon = sActivePokemon[0];
    sSide2ActivePokemon = sActivePokemon[1];
}

void BattleScene_InitializeParticipantController(ActivePokemon* active_pokemon) {
    Controller* sp24 = &gControllers[active_pokemon->sessionTeams->teamMember[0]->unk_001];

    BattleScene_BindParticipantRosterForSide(active_pokemon, 0);
    BattleScene_SetParticipantSelectedSide(active_pokemon, 0);
    BattleScene_SetParticipantController(active_pokemon, sp24);
    active_pokemon->unk_728.unk_16C = 0;
}

void BattleScene_InitializeParticipantModel(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    ModelNodeView* sp24;
    s16 sp22;

    BattleScene_GetParticipantSideIndex(active_pokemon);
    sp24 = Battle_GetMoveEffectListEntry(active_pokemon, 0);
    sp22 = Battle_GetTrainerId(active_pokemon, 0);
    ModelRenderer_AttachDisplayObject(&active_pokemon->displayObject);

    if (active_pokemon == sActivePokemon[0]) {
        active_pokemon->displayObject.effectSlot = 0;
    } else {
        active_pokemon->displayObject.effectSlot = 1;
    }

    Model_InitDisplayObject(&active_pokemon->displayObject, 0, sp22, sp24);
    Battle_LoadAnimationAndMarkMoveIllegality(active_pokemon, 1);
    ModelAnim_SetAnimation(&active_pokemon->displayObject, 0);
    ModelAnim_SetFrame(&active_pokemon->displayObject, 0);

    active_pokemon->sessionTeams->unk_04 = active_pokemon->unk_724->pokemonPicked;
    if ((active_pokemon->displayObject.objectType == 0x32) || (active_pokemon->displayObject.objectType == 0x33)) {
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

void BattleScene_InitializeParticipantOwnerModel(ActivePokemon* active_pokemon) {
    PresentationState* ptr = &active_pokemon->unk_728;
    ModelNodeView* sp28;
    s16 sp26;

    sp28 = Battle_GetMoveEffectListEntry(active_pokemon, 0);
    sp26 = Battle_GetTrainerId(active_pokemon, 0);
    ModelRenderer_AttachDisplayObject(&ptr->unk_000);

    if (active_pokemon == sActivePokemon[0]) {
        ptr->unk_000.effectSlot = -1;
        Model_InitDisplayObject(&ptr->unk_000, 1, sp26, sp28);
    } else {
        ptr->unk_000.effectSlot = -1;
        Model_InitDisplayObject(&ptr->unk_000, 2, sp26, sp28);
    }

    ModelAnim_SetAnimation(&ptr->unk_000, 0);
    ModelAnim_SetFrame(&ptr->unk_000, 0);
    ptr->unk_000.node.renderFlags &= ~0x40;
    Vec3f_SetComponentsDuplicate(&ptr->unk_000.position, 0.0f, 0.0f, 0.0f);
}

void BattleScene_InitializeParticipantSecondaryModels(ActivePokemon* arg0, s32* arg1) {
    ModelNodeView* sp44;
    s16 sp42;
    s32 i;
    unk_D_84390010_168* ptr;

    sp44 = Battle_GetMoveEffectListEntry(arg0, 0);
    sp42 = Battle_GetTrainerId(arg0, 0);

    for (i = 0; i < 2; i++) {
        ptr = &arg0->unk_168[i];

        ModelRenderer_AttachDisplayObject(ptr);

        if (arg0 == sActivePokemon[0]) {
            ptr->unk_000.effectSlot = 0xFF;
        } else {
            ptr->unk_000.effectSlot = 0xFF;
        }

        Model_InitDisplayObject(ptr, 0, sp42, sp44);
        ModelAnim_SetFrame(ptr, 0);
        ModelAnim_SetAnimation(ptr, 0);

        ptr->unk_000.node.renderFlags &= ~0x40;

        if (arg0 == sActivePokemon[0]) {
            BattleScene_PositionParticipantModel(arg0);
        } else {
            BattleScene_PositionParticipantModel(arg0);
        }
        ptr->unk_000.node.flags &= ~1;
    }
}

void BattleScene_InitializeParticipantAuxiliaryModel(ActivePokemon* active_pokemon) {
    DisplayObject* ptr = &active_pokemon->unk_4EC;
    ModelNodeView* sp20 = active_pokemon->sessionTeams->unk_18;

    ModelRenderer_AttachDisplayObject(ptr);
    ptr->effectSlot = 0xFF;
    Model_InitDisplayObject(ptr, 0, 0x9A, sp20);
    ModelAnim_SetAnimation(ptr, 0);

    ptr->node.renderFlags &= ~0x20;
    ptr->node.flags &= ~1;

    if (active_pokemon == sActivePokemon[0]) {
        Vec3f_SetComponentsDuplicate(&ptr->position, -50.0f, 2.0f, 0.0f);
    } else {
        Vec3f_SetComponentsDuplicate(&ptr->position, 50.0f, 2.0f, 0.0f);
    }
}

void BattleScene_InitializePresentation(UNUSED BattleSessionTeams* arg0) {
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
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            BattleScene_SetCameraModeAndStep(4, 0);
            break;

        case 16:
            BattleScene_SetCameraModeAndStep(1, 0x32);
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

void BattleScene_ResetParticipantAuxTransform(UNUSED ActivePokemon* arg0, ActivePokemon* arg1, s32 arg2) {
    Vec3f_SetComponentsDuplicate(&arg1->swayState, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&arg1->swayState.unk_0C, 0.0f, 0.0f, 0.0f);
    arg1->unk_4B0 = arg2;
}

void BattleScene_InitializeRuntime(BattleSessionTeams* arg0) {
    s32 i;

    Text_InitStringTables();

    sBattleMessagesTable = Text_GetStringTable(0x1E);
    sPokemonNameTable = Text_GetStringTable(0x24);
    sMoveNameTable = Text_GetStringTable(0x25);
    sStatusConditionNameTable = Text_GetStringTable(0x29);
    sBattleControllerDisconnectedMessage = Text_GetStringTable(0x14);

    for (i = 0; i < 7; i++) {
        sBattleSceneStateTickSlots[i].unk_04 = sBattleSceneStateTickSentinel;
    }

    BattleScene_ResetParticipantAuxTransform(sActivePokemon[0], sActivePokemon[0], 1);
    BattleScene_ResetParticipantAuxTransform(sActivePokemon[1], sActivePokemon[1], -1);
    BattleScene_InitializePresentation(arg0);
    Battle_InitializeActiveRuntimeState();
    Battle_InitializeMoveIllegalityMask(sActivePokemon[0]);
    Battle_InitializeMoveIllegalityMask(sActivePokemon[1]);
    BattleBox_Close();
}

void BattleScene_UpdateParticipantsAndQueueEffects(ActivePokemon* arg0, ActivePokemon* arg1) {
    Battle_AdvanceSecondaryModelAnimIfFinished(sActivePokemon[0], sActivePokemon[0]);
    Battle_AdvanceSecondaryModelAnimIfFinished(sActivePokemon[1], sActivePokemon[1]);
    BattleAnim_UpdateOwnerStatusIdleAnimation(0);
    BattleAnim_UpdateOwnerStatusIdleAnimation(1);
    func_843060EC(sActivePokemon[0]);
    func_843060EC(sActivePokemon[1]);
}

s32 BattleScene_DispatchLifecycle(s32 arg0, BattleSessionTeams* arg1) {
    switch (arg0) {
        case 0:
            BattleScene_AllocateParticipants(arg1);
            break;

        case 1:
        case 2:
            BattleScene_UpdateParticipantsAndQueueEffects(sActivePokemon[0], sActivePokemon[1]);
            break;

        case 3:
            BattleScene_InitializeRuntime(arg1);
            break;

        case 5:
            Battle_RenderHud();
            break;
    }

    return 0;
}

void func_84307414(ActivePokemon* active_pokemon) {
}

void BattleScene_StateRow56EnterNop(ActivePokemon* active_pokemon) {
}

void BattleScene_StateRow5Slot3Nop(ActivePokemon* active_pokemon) {
}

void BattleScene_StateRow5Slot4Nop(ActivePokemon* active_pokemon) {
}

void BattleScene_StateRow5Slot5Nop(ActivePokemon* active_pokemon) {
}

void BattleScene_StateRow5Slot6Nop(ActivePokemon* active_pokemon) {
}

void BattleScene_StateRow7Slot5Nop(ActivePokemon* active_pokemon) {
}

void BattleScene_StateRow6Slot6Nop(ActivePokemon* active_pokemon) {
}

void BattleScene_StateRow6Slot5Nop(ActivePokemon* active_pokemon) {
}

void BattleScene_StateRow6Slot4Nop(ActivePokemon* active_pokemon) {
}

void BattleScene_StateRow6Slot3Nop(ActivePokemon* active_pokemon) {
}

void func_8430746C(ActivePokemon* active_pokemon) {
}

void func_84307474(ActivePokemon* arg0, s32 arg1) {
}

void func_84307480(ActivePokemon* arg0, s32 arg1) {
}

void BattleScene_StateRow7Slot4Nop(ActivePokemon* active_pokemon) {
}
