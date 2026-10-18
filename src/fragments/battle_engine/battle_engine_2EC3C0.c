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

static unk_D_8438E7B0 D_8438E7B0;
static unk_D_8438E7B0 D_8438F390;
static SpeciesModelTransform D_8438FF70;
static SpeciesModelTransform D_8438FF90;
static SpeciesModelTransform D_8438FFB0;
static SpeciesModelTransform D_8438FFD0;
static TagTeamPartners D_8438FFF0;
static TagTeamPartners D_84390000;
ActivePokemon* sActivePokemon[2];
ActivePokemon* D_84390018;
ActivePokemon* D_8439001C;
static MovePresentationCue* D_84390020;
unk_D_84390028 D_84390028[2];
static SwayLayoutConfig D_84390048;
static BattleSceneStateTickSlot gBattleSceneStateTickSlots[7];
static s32 gBattleSceneStateTickSlotIndex;
static s32 D_843900A4;
f32 D_843900A8[2];

unk_D_8438E7B0* D_84384570[] = { &D_8438E7B0, &D_8438F390 };
SpeciesModelTransform* D_84384578[] = {
    &D_8438FF70,
    &D_8438FF90,
};
SpeciesModelTransform* D_84384580[] = {
    &D_8438FFB0,
    &D_8438FFD0,
};
TagTeamPartners* D_84384588[] = { &D_8438FFF0, &D_84390000 };
u8 D_84384590[] = { 0x39, 0x67, 0x64, 0x6D, 0x28, 0x6E, 0x2A, 0x47 };
static u8 D_84384598[] = { 0x64, 0x6E };
static u8 D_8438459C[] = {
    0x06, 0x0C, 0x30, 0x31, 0x32, 0x33, 0x8D, 0x96, 0x97,
};
static u8 D_843845A8[] = {
    0x06,
    0x2E,
};
static u8 D_843845AC[] = {
    0x06,
    0x42,
};
static u8 D_843845B0[] = {
    0x06,
    0x42,
};
static u8 D_843845B4[] = {
    0x06,
    0x42,
};
static u8 D_843845B8[] = {
    0x06,
    0x06,
};
static u8 D_843845BC[] = {
    0x06,
    0x06,
};
static u8 D_843845C0[] = {
    0x06,
    0x16,
};
static u8 D_843845C4[] = {
    0x01,
    0x7F,
};
static u8 D_843845C8[] = {
    0x06,
    0x7F,
};
static u8* D_843845CC[] = {
    D_843845A8, D_843845AC, D_843845B0, D_843845B4, D_843845B8, D_843845BC, D_843845C0, D_843845C4, D_843845C8,
};
u8 D_843845F0 = 0x8E;
u8 D_843845F4 = 0x16;
u8 D_843845F8 = 0x53;
u8 D_843845FC[] = { 0x55, 0x54 };

char** D_843900B0;
char** D_843900B4;
char** D_843900B8;
char** D_843900BC;
char** D_843900C0;

// called on move select
void BattleScene_ClearStateTickCallbacks(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        gBattleSceneStateTickSlots[i].unk_04 = gBattleSceneStateTickSentinel;
    }
}

// called on move select
void BattleScene_QueueRowEffectList3(ActivePokemon* arg0, s32 arg1) {
    BattleAnim_QueueEffectList3(arg1, &arg0->unk_000, &arg0->unk_000, 0xFF, 0xFF);
}

// played on gengar using thunderbolt in bug boy glc fight
void BattleAnim_PlayMoveEffectScriptA(ActivePokemon* arg0, s32 arg1) {
    UNUSED s16 pad;
    s16 sp24;
    s32 sp20;

    sp20 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    sp24 = Battle_GetCameraShotFieldB(arg0);
    BattleAnim_QueueMoveEffectScriptA(arg1, arg0, sActivePokemon[sp20], sp24, Battle_GetCameraShotFieldC(arg0));
}

// trigger unknown
void BattleAnim_PlayMoveEffectScriptB(ActivePokemon* arg0, s32 arg1) {
    UNUSED s16 pad;
    s16 sp24;
    s32 sp20;

    sp20 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    sp24 = Battle_GetCameraShotFieldB(arg0);
    BattleAnim_QueueMoveEffectScriptB(arg1, arg0, sActivePokemon[sp20], sp24, Battle_GetCameraShotFieldC(arg0));
}

// play on move end
void BattleAnim_PlayMoveEffectEnd(ActivePokemon* arg0, s32 arg1) {
    UNUSED s16 pad;
    s16 sp24;
    s32 sp20;

    sp20 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    sp24 = Battle_GetSideAnimTableFieldB(arg0);
    BattleAnim_QueueMoveEffectEnd(arg1, sActivePokemon[sp20], arg0, sp24, Battle_GetSideAnimTableFieldC(arg0));
}

// play on move end
void BattleScene_TickClearAnimRecordIfLoaded(ActivePokemon* active_pokemon) {
    if (BattleAnim_TryRegisterAssetTables(active_pokemon) != 0) {
        active_pokemon->unk_4C4 = 0;
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

// trigger unknown
void BattleScene_TickStartRowAnimRecord(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    s32 idx = active_pokemon->unk_4C0;
    s32 sp24 = gBattleSceneStateRowTable[idx].unk_20;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp24];
    if (BattleAnim_TryRegisterAssetTables(active_pokemon) != 0) {
        BattleAnim_SetModelEventTrackAndState(active_pokemon, sp24, 2);
        active_pokemon->unk_4C4 = 0;
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        ModelAnim_SetFrame(&active_pokemon->unk_000, 0);
        ModelAnim_SetAnimation(&active_pokemon->unk_000, D_84390020->unk_00);
    }
}

// trigger unknown
void BattleScene_TickQueueRowEffectList3AtAnimEnd(ActivePokemon* active_pokemon) {
    s32 idx = active_pokemon->unk_4C0;
    s32 sp28 = gBattleSceneStateRowTable[idx].unk_20;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp28];
    if (BattleScene_GetParticipantModelHeight(active_pokemon) != 0.0f) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    } else if ((active_pokemon->unk_4C4 == (D_84390020->unk_04 + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleScene_QueueRowEffectList3(active_pokemon, gBattleSceneStateRowTable[idx].unk_24);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

// triggers on waiting for move selection
void BattleScene_ResetStateFrameCounter(ActivePokemon* active_pokemon) {
    active_pokemon->unk_4C4 = 0;
}

// trigger on up on the dialogue box disappearing after move use
void BattleScene_ResetOpponentStateFrameCounter(ActivePokemon* active_pokemon) {
    sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->unk_4C4 = 0;
}

// trigger on up on the dialogue box disappearing after move use
// used to animate moves that throw rocks
void BattleAnim_SetOverlayFlagForSpecialMoves(ActivePokemon* active_pokemon) {
    BattleMonRuntime* ptr = &active_pokemon->unk_654.runtime;

    if (ptr->usedMove == STRENGTH || ptr->usedMove == ROCK_SLIDE || ptr->usedMove == ROCK_THROW) {
        sActivePokemon[0]->unk_000.node.renderFlags |= 2;
        sActivePokemon[1]->unk_000.node.renderFlags |= 2;
    }
}

// triggers at the end of move animations and at the end of damage animation of using a rock throwing move
void BattleAnim_ClearOverlayFlag(ActivePokemon* active_pokemon) {
    sActivePokemon[0]->unk_000.node.renderFlags &= ~2;
    sActivePokemon[1]->unk_000.node.renderFlags &= ~2;
}

s32 BattleAnim_IsAssetLoadBusy(ActivePokemon* active_pokemon) {
    return active_pokemon->unk_720->unk_1D & 0xD0;
}

s32 BattleAnim_PollAssetLoadBusyFlags(ActivePokemon* active_pokemon) {
    PokeIcon_PollBackgroundForObject(active_pokemon->unk_720);
    return active_pokemon->unk_720->unk_1D & 0xC0;
}

s32 BattleAnim_IsSessionBusy(ActivePokemon* active_pokemon) {
    return active_pokemon->unk_720->unk_00 & 0xD0;
}

s32 BattleAnim_TryRegisterAssetTables(ActivePokemon* active_pokemon) {
    if (BattleAnim_PollAssetLoadBusyFlags(active_pokemon) == 0) {
        BattleAnim_RegisterAssetTablesForSession(active_pokemon->unk_720);
        return 1;
    }
    return 0;
}

void BattleScene_LoadMoveResourceList(ActivePokemon* active_pokemon) {
    // FAKE
    if (gBattleScene.unk_00->unk_48 == 0xE) {
        BattleAnim_LoadMoveResourceList(active_pokemon->unk_720, BattleScene_GetActiveAnimRowId(active_pokemon));
    } else {
        BattleAnim_LoadMoveResourceList(active_pokemon->unk_720, BattleScene_GetActiveAnimRowId(active_pokemon));
    }
}

void BattleScene_LoadRowResourceList(ActivePokemon* active_pokemon) {
    s32 idx = active_pokemon->unk_4C0;

    BattleAnim_LoadModeResourceList(active_pokemon->unk_720, gBattleSceneStateRowTable[idx].unk_24);
}

void BattleScene_ReloadMoveResourceList(ActivePokemon* active_pokemon) {
    BattleAnim_LoadMoveResourceList(active_pokemon->unk_720, BattleScene_GetActiveAnimRowId(active_pokemon));
}

void BattleAnim_BeginSessionRequest(ActivePokemon* active_pokemon) {
    active_pokemon->unk_720->unk_02 = 0x98;
    active_pokemon->unk_720->unk_00 |= 0x80;
}

void BattleAnim_BeginSessionRequestForActiveMon(ActivePokemon* active_pokemon) {
    active_pokemon->unk_720->unk_04 = &active_pokemon->unk_724->pokemonPicked[active_pokemon->unk_654.unk_08];
    active_pokemon->unk_720->unk_00 |= 0x80;
    active_pokemon->unk_720->unk_02 = active_pokemon->unk_654.unk_BC;
}

s32 BattleScene_FindU16InByteArray(u16 arg0, u8* arg1, s32 arg2) {
    s32 var_v1 = 0;

    while (arg2--) {
        if (arg0 == *arg1) {
            return var_v1;
        }
        arg1++;
        var_v1++;
    }

    return -1;
}

void Battle_FilterUnusableMoves(ActivePokemon* arg0, u16 arg1, SpeciesLearnsetBuffer* arg2, SpeciesLearnsetBuffer* arg3) {
    s32 i;
    s32 j;
    s32 temp_v0_3;
    s32 temp_v1_2;
    u8 var_a0;
    unk_D_80070F84* temp_s4; //TODO: this is definitely typed wrong
    BattleMonRuntime* temp_s5;

    temp_s5 = &arg0->unk_654.runtime;

    for (i = 0; i < 4; i++) {
        if (temp_s5->unk_1F[i] != 0) {
            temp_s4 = &D_80070FA0[arg1];

            for (j = 0; j < ARRAY_COUNT(temp_s4->unk_0A); j++) {
                if ((temp_s4->unk_0A[j] != 0) && (temp_s4->unk_0A[j] == temp_s5->unk_1F[i])) {
                    arg0->unk_654.unk_C1[i] = 0;
                }
            }

            for (j = 0; j < 10; j++) {
                if ((arg2->unk_00[j] != 0) && (temp_s5->unk_26 >= arg2->unk_00[j]) &&
                    (arg2->unk_0A[j] == temp_s5->unk_1F[i])) {
                    arg0->unk_654.unk_C1[i] = 0;
                }
            }

            for (j = 0; j < 10; j++) {
                if ((arg3->unk_00[j] != 0) && (temp_s5->unk_26 >= arg3->unk_00[j]) &&
                    (arg3->unk_0A[j] == temp_s5->unk_1F[i])) {
                    arg0->unk_654.unk_C1[i] = 0;
                }
            }

            for (j = 0; j < 0x37; j++) {
                temp_v0_3 = BattleScene_FindU16InByteArray(arg1 + 1, D_8438459C, 9);
                if (temp_v0_3 >= 0) {
                    temp_v1_2 = j / 8;
                    if (temp_v1_2 == D_843845CC[temp_v0_3][0]) {
                        var_a0 = temp_s4->unk_0F[temp_v1_2] | D_843845CC[temp_v0_3][1];
                    } else {
                        var_a0 = temp_s4->unk_0F[temp_v1_2];
                    }
                } else {
                    var_a0 = temp_s4->unk_0F[j / 8];
                }

                if (((var_a0 >> (j % 8)) & 1) && (Move_GetIdFromTableIndex(j) == temp_s5->unk_1F[i])) {
                    arg0->unk_654.unk_C1[i] = 0;
                }
            }
        } else {
            arg0->unk_654.unk_C1[i] = 0;
        }
    }
}

void Battle_InitializeMoveUsabilityMask(ActivePokemon* active_pokemon) {
    active_pokemon->unk_654.unk_C1[0] = 1;
    active_pokemon->unk_654.unk_C1[1] = 1;
    active_pokemon->unk_654.unk_C1[2] = 1;
    active_pokemon->unk_654.unk_C1[3] = 1;

    Battle_FilterUnusableMoves(active_pokemon, active_pokemon->unk_654.runtime.unk_0B - 1, &active_pokemon->unk_94C, &active_pokemon->unk_9AC);

    if (D_84384588[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_00 != 0) {
        Battle_FilterUnusableMoves(active_pokemon, D_84384588[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_00 - 1, &active_pokemon->unk_96C, &active_pokemon->unk_9CC);
    }

    if (D_84384588[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_01 != 0) {
        Battle_FilterUnusableMoves(active_pokemon, D_84384588[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_01 - 1, &active_pokemon->unk_98C, &active_pokemon->unk_9EC);
    }
}

void Battle_DmaLoadAnimRecord(u8 arg0, u32 arg1) {
    u32 temp_a1 = (u32)_70D3A0_ROM_START + ((u32)&D_72780[arg0 - 1] & 0xFFFFFF);

    Dma_WriteChunks(arg1, temp_a1, temp_a1 + 0x20, 0);
}

void Battle_DmaLoadAnimRecordPair(s32 arg0, SpeciesLearnsetBuffer* arg1, SpeciesLearnsetBuffer* arg2) {
    UNUSED s32 pad[3];
    u32 temp_a1;

    temp_a1 = (u32)_70D3A0_ROM_START + ((u32)&D_72780[arg0] & 0xFFFFFF);
    Dma_WriteChunks(arg1, temp_a1, temp_a1 + 0x20, 0);
    temp_a1 = (u32)_70D3A0_ROM_START + ((u32)&D_73A60[arg0] & 0xFFFFFF);
    Dma_WriteChunks(arg2, temp_a1, temp_a1 + 0x20, 0);
}

void func_84302658(ActivePokemon* arg0, s32 arg1) {
    s16 sp6E;
    s32 sp68;
    s16 sp66;
    u32 var_a1;
    s32 pad[8];
    BattleMon* ptr;
    SpeciesModelTransform* ptr2;
    u32 tmp;

    sp68 = BattleScene_GetParticipantSideIndex(arg0);
    sp66 = arg0->unk_000.objectType - 1;

    ptr = &arg0->unk_720->teamMember[arg0->unk_654.unk_2C]->pokemonPicked[arg0->unk_654.unk_18];

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)D_80075BD0[sp66] & 0xFFFFFF);
    if ((arg0->unk_000.objectType == 0x19) && (ptr->unk_52 & 0x80)) {
        var_a1 = (u32)_70D3A0_ROM_START + ((u32)D_80075BD0[152] & 0xFFFFFF);
    }
    tmp = ((u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (sp66 << 5)) & 0xFFFFFF)) + 0x20;
    Dma_WriteChunks(D_84384570[sp68], var_a1, var_a1 + 0xBC0, 0);

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (sp66 << 5)) & 0xFFFFFF);
    Dma_WriteChunks(D_84384580[sp68], var_a1, tmp, 0);

    if (sp68 == 1) {
        var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (sp66 << 5)) & 0xFFFFFF);
        Dma_WriteChunks(D_84384578[sp68], var_a1, var_a1 + 0x20, 0);

        ptr2 = D_84384578[sp68];
        if (ptr2->unk_10 != 0xFF) {
            sp6E = ptr2->unk_10;

            var_a1 = ((u32)_70D3A0_ROM_START) + (((u32)(D_6E910 + ((ptr2->unk_10 - (tmp = 2)) * 0x20))) & 0xFFFFFF);
            Dma_WriteChunks(ptr2, var_a1, var_a1 + 0x20, 0);

            D_84384578[sp68]->unk_10 = sp6E;
        }
    } else {
        var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_6E910 + (sp66 << 5)) & 0xFFFFFF);
        Dma_WriteChunks(D_84384578[sp68], var_a1, var_a1 + 0x20, 0);
    }

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_70B10 + (sp66 * 0x20)) & 0xFFFFFF);
    Dma_WriteChunks(&D_84390048, var_a1, var_a1 + 0x20, 0);

    BattleAnim_Vec3fCopy(&arg0->unk_448.unk_24.unk_00, &D_84390048.unk_00);
    BattleAnim_Vec3fCopy(&arg0->unk_448.unk_24.unk_0C, &D_84390048.unk_0C);

    arg0->unk_448.unk_24.unk_18 = D_84390048.unk_18;
    arg0->unk_448.unk_24.unk_19 = D_84390048.unk_19;
    arg0->unk_448.unk_24.unk_1A = D_84390048.unk_1A;
    arg0->unk_448.unk_24.unk_1B = D_84390048.unk_1B;
    arg0->unk_448.unk_24.unk_00.x *= arg0->unk_4B0;
    arg0->unk_448.unk_24.unk_0C.x *= arg0->unk_4B0;

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_70110 + (sp66 << 4)) & 0xFFFFFF);
    Dma_WriteChunks(&D_84390028[sp68], var_a1, var_a1 + 0x10, 0);

    var_a1 = (u32)_70D3A0_ROM_START + ((u32)(D_71E10 + (sp66 * 0x10)) & 0xFFFFFF);
    Dma_WriteChunks(D_84384588[sp68], var_a1, var_a1 + 0x10, 0);

    Battle_DmaLoadAnimRecordPair(sp66, &arg0->unk_94C, &arg0->unk_9AC);

    if (D_84384588[sp68]->unk_00 != 0) {
        Battle_DmaLoadAnimRecordPair(D_84384588[sp68]->unk_00 - 1, &arg0->unk_96C, &arg0->unk_9CC);
    }

    if (D_84384588[sp68]->unk_01 != 0) {
        Battle_DmaLoadAnimRecordPair(D_84384588[sp68]->unk_01 - 1, &arg0->unk_98C, &arg0->unk_9EC);
    }

    if (arg1 == 1) {
        Battle_InitializeMoveUsabilityMask(arg0);
    }
}

void BattleScene_TickRow10CleanupAndEnterState18(ActivePokemon* active_pokemon) {
    if (active_pokemon->unk_4C4 == 0x14) {
        active_pokemon->unk_720->unk_00 |= 0x80;
    }

    if (active_pokemon->unk_720->unk_00 & 0x10) {
        active_pokemon->unk_720->unk_00 &= ~0x90;
        Battle_LoadOwnerModelForSwitchIn(active_pokemon);
        BattleScene_TickOwnerCameraFraming(active_pokemon);
        Audio_PlayCommand(2, 0, 0);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        BattleScene_EnterStateRow(active_pokemon, 0x12);
    }
}

void BattleScene_EnterRow3StartMoveAnim(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp24;
    ActivePokemonState* sp20;
    s32 idx;
    s16 sp2A;
    u8 tmp;

    sp2A = active_pokemon->unk_000.objectType - 1;
    sp24 = &active_pokemon->unk_654.runtime;
    sp20 = &active_pokemon->unk_654;
    idx = BattleScene_GetParticipantSideIndex(active_pokemon);

    D_84390020 = &D_84384570[idx]->unk_000[sp24->usedMove - 1];

    if (!(sp20->unk_34 & 2)) {
        active_pokemon->unk_4C4 = 0;

        if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            tmp = BattleScene_GetParticipantSideIndex(active_pokemon);
            func_80048060(tmp, sp24->usedMove, 0xC8, 0);
        } else {
            tmp = BattleScene_GetParticipantSideIndex(active_pokemon);
            func_80048060(tmp, sp24->usedMove, sp2A + 1, 0);
        }

        if ((sp20->unk_34 & 0x4000) && ((sp2A == 0x32) || (sp2A == 0x31))) {
            Battle_ClearRuntimeFlags(active_pokemon, 8);
            active_pokemon->unk_000.node.renderFlags |= 0x20;
            Battle_SetRuntimeFlags(active_pokemon, 0x10);
            Battle_ClearRuntimeFlags(active_pokemon, 0x4000);
        }

        BattleAnim_SetOverlayFlagForSpecialMoves(active_pokemon);
        ModelAnim_SetAnimation(&active_pokemon->unk_000, D_84390020->unk_00);
        BattleAnim_SetModelEventTrackFromRow(active_pokemon, sp24->usedMove - 1);

        if (D_84390020->unk_0B != 0) {
            ModelAnim_SetFrame(&active_pokemon->unk_000, D_84390020->unk_0B);
            ModelAnim_SetEventFrame(&active_pokemon->unk_000, D_84390020->unk_0B);
            active_pokemon->unk_4C4 = D_84390020->unk_0B;
        } else {
            ModelAnim_SetFrame(&active_pokemon->unk_000, 0);
        }
    }
}

void BattleScene_TickRow3PlayMoveEffectScript(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    s16 sp32 = active_pokemon->unk_000.objectType - 1;
    BattleMonRuntime* sp24;

    BattleScene_GetParticipantSideIndex(active_pokemon);
    sp24 = &active_pokemon->unk_654.runtime;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp24->usedMove - 1];

    if ((sp24->usedMove == 0x19) && (sp32 == 0x64)) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    } else if ((active_pokemon->unk_4C4 == (D_84390020->unk_04 + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        if (gBattleScene.unk_00->unk_48 == 0x14) {
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        } else if (sp24->unk_44.unk_00 == 0x5B) {
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        } else {
            if (sp24->unk_44.unk_00 == 0x6E) {
                if ((sp32 != 7) && (sp32 != 8) && (sp32 != 0x5A) && (sp32 != 6)) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 0xC, 0);
                    BattleAnim_PlayMoveEffectScriptA(active_pokemon, sp24->usedMove);
                }
            } else {
                if (sp24->unk_44.unk_00 == 0x45) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 8, 0);
                } else if (sp24->unk_44.unk_00 == 0x39) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 0xA, 0);
                } else if (sp24->unk_44.unk_00 == 0x60) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 0xD, 0);
                } else if (sp24->unk_44.unk_00 == 0x7F) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 0xE, 0);
                } else if (sp24->unk_44.unk_00 == 0x6B) {
                    BattleScene_SetParticipantModelFlags(active_pokemon, 9, 0);
                } else {
                    BattleScene_SetParticipantModelFlags(active_pokemon, D_84390020->unk_05, 0);
                }

                if ((sp24->usedMove == 0x9A) && (D_84390230 == D_8439022C)) {
                    BattleAnim_PlayMoveEffectScriptB(active_pokemon, sp24->usedMove);
                } else {
                    BattleAnim_PlayMoveEffectScriptA(active_pokemon, sp24->usedMove);
                }
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow3PostEffectCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp24 = &active_pokemon->unk_654.runtime;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp24->usedMove - 1];

    if (active_pokemon->unk_4C4 == (D_84390020->unk_04 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (gBattleScene.unk_00->unk_48 == 0x18) {
                D_84390234--;
                if (D_84390234 < 0) {
                    if (gBattleMoveFailed != 0) {
                        BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp24, 2);
                    }
                } else {
                    BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp24, 3);
                }
            } else if (gBattleMoveFailed != 0) {
                BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp24, 2);
            } else {
                if ((sp24->usedMove == 0x2D) || (sp24->usedMove == 0x2E) || (sp24->usedMove == 0x59)) {
                    BattleScene_StartCameraShake(active_pokemon);
                }
                BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp24, 0);
                func_843031A0(active_pokemon);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow3QueueEffectList6(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp24 = &active_pokemon->unk_654.runtime;
    UNUSED s16 pad;
    s16 sp18;

    sp18 = sp24->usedMove;
    BattleScene_GetParticipantSideIndex(active_pokemon);
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp24->usedMove - 1];

    if (active_pokemon->unk_4C4 == (D_84390020->unk_09 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (((sp18 == 0x4A) || (sp18 == 0x60) || (sp18 == 0x61) || (sp18 == 0x6A) || (sp18 == 0x6E) ||
                 (sp18 == 0xE) || (sp18 == 0x68) || (sp18 == 0x6B) || (sp18 == 0x6F) || (sp18 == 0x70) ||
                 (sp18 == 0x85) || (sp18 == 0x97) || (sp18 == 0x9F)) &&
                (D_843C4E45 == 1)) {
                BattleAnim_QueueEffectList6(3, active_pokemon);
                Audio_PlayCommand(0x23, 0, 0);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void func_843031A0(ActivePokemon* active_pokemon) {
    BattleMonRuntime* temp_v1 = &active_pokemon->unk_654.runtime;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[temp_v1->usedMove - 1];

    if (temp_v1->usedMove == 0x6A) {
        Model_SetMaterialTextureMode(&active_pokemon->unk_000, 1);
    }
}

void BattleScene_EnterRow21StartAnimRecord0(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    ActivePokemonState* temp_v1 = &active_pokemon->unk_654;
    s16 sp22;

    sp22 = active_pokemon->unk_000.objectType - 1;
    D_84390020 = D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000;

    if (!(temp_v1->unk_34 & 2)) {
        active_pokemon->unk_4C4 = 0;
        if ((temp_v1->unk_34 & 0x4000) && ((sp22 == 0x32) || (sp22 == 0x31))) {
            Battle_ClearRuntimeFlags(active_pokemon, 8);
            active_pokemon->unk_000.node.renderFlags |= 0x20;
            Battle_SetRuntimeFlags(active_pokemon, 0x10);
            Battle_ClearRuntimeFlags(active_pokemon, 0x4000);
        }
        ModelAnim_SetAnimation(&active_pokemon->unk_000, D_84390020->unk_00);
        ModelAnim_SetFrame(&active_pokemon->unk_000, 0);
        BattleAnim_SetModelEventTrackFromRow(active_pokemon, 4);

        if (D_84390020->unk_0B != 0) {
            ModelAnim_SetFrame(&active_pokemon->unk_000, D_84390020->unk_0B);
            ModelAnim_SetEventFrame(&active_pokemon->unk_000, D_84390020->unk_0B);
            active_pokemon->unk_4C4 = D_84390020->unk_0B;
        } else {
            ModelAnim_SetFrame(&active_pokemon->unk_000, 0);
        }
    }
}

void BattleScene_TickRow21PlaySpeciesSound(ActivePokemon* active_pokemon) {
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[0];
    if ((active_pokemon->unk_4C4 == (D_84390020->unk_04 + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        func_800479C0(1, active_pokemon->unk_000.objectType, 0);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_EnterRow19StartMoveAnimMidFrame(ActivePokemon* active_pokemon) {
    ActivePokemonState* sp20;
    BattleMonRuntime* ptr;

    sp20 = &active_pokemon->unk_654;
    ptr = &active_pokemon->unk_654.runtime;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[ptr->usedMove - 1];

    if (sp20->unk_34 & 2) {
        return;
    }

    active_pokemon->unk_4C4 = D_84390020->unk_06;
    if (!(sp20->unk_34 & 0x4000)) {
        BattleAnim_SetOverlayFlagForSpecialMoves(active_pokemon);
        ModelAnim_SetAnimation(&active_pokemon->unk_000, D_84390020->unk_00);
        ModelAnim_SetFrame(&active_pokemon->unk_000, D_84390020->unk_06);
        if (D_84390020->unk_01 != 0xFF) {
            ModelAnim_SetEventTrack(&active_pokemon->unk_000, D_84390020->unk_01);
            ModelAnim_SetEventFrame(&active_pokemon->unk_000, D_84390020->unk_06);
            sp20->unk_36 = 1;
        }
    }
}

void BattleScene_TickRow19PlayMoveEffectScript(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp20;
    s32 var_v0;

    sp20 = &active_pokemon->unk_654.runtime;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp20->usedMove - 1];
    if (sp20->usedMove == 0x9A) {
        var_v0 = D_84390020->unk_04 + 0x1E;
    } else {
        var_v0 = D_84390020->unk_04 + 1;
    }

    if ((var_v0 == active_pokemon->unk_4C4) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        if (gBattleScene.unk_00->unk_48 == 0x14) {
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
            return;
        }

        if ((sp20->usedMove == 0x9A) && (D_84390230 == D_8439022C)) {
            BattleAnim_PlayMoveEffectScriptB(active_pokemon, sp20->usedMove);
        } else {
            BattleAnim_PlayMoveEffectScriptA(active_pokemon, sp20->usedMove);
        }

        if (sp20->unk_44.unk_00 == 0x45) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 8, 0);
        } else if (sp20->unk_44.unk_00 == 0x39) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 0xA, 0);
        } else {
            BattleScene_SetParticipantModelFlags(active_pokemon, D_84390020->unk_05, 0);
        }
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickRow19PostEffectCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp18;
    s32 var_v0;

    sp18 = &active_pokemon->unk_654.runtime;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp18->usedMove - 1];

    if (sp18->usedMove == 0x9A) {
        var_v0 = D_84390020->unk_04 + 0x1E;
    } else {
        var_v0 = D_84390020->unk_04 + 1;
    }

    if (var_v0 == active_pokemon->unk_4C4) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (gBattleScene.unk_00->unk_48 == 0x18) {
                D_84390234--;
                if (D_84390234 < 0) {
                    if (gBattleMoveFailed != 0) {
                        BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp18, 2);
                    } else {
                        BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp18, 0);
                    }
                } else {
                    BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp18, 3);
                }
            } else if (gBattleMoveFailed != 0) {
                BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp18, 2);
            } else {
                BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp18, 0);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_EnterRow4StartHitReactionAnim(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[3];
    s32 sp40;
    ActivePokemonState* sp3C;
    UNUSED s32 pad2;
    s32 temp_v0;
    BattleMonRuntime* sp28;
    ActivePokemon* temp_a1;

    sp28 = &active_pokemon->unk_654.runtime;
    sp40 = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    sp3C = &sActivePokemon[sp40]->unk_654;
    temp_a1 = sActivePokemon[sp40];
    D_84390020 = &D_84384570[sp40]->unk_A80;

    if (sp3C->unk_34 & 1) {
        temp_v0 = BattleScene_ByteArrayContains(temp_a1->unk_000.objectType, D_84384598, 2);
        if (temp_v0 != 0) {
            D_84390020 = &D_84384570[sp40]->unk_B20;
        }
    }

    sActivePokemon[sp40]->unk_4C4 = 0;

    if (!(sp3C->unk_34 & 0x200) && !(sp3C->unk_34 & 0x4000) && !(sp3C->unk_34 & 2)) {
        if (((D_843C4DEC < 0xA) || (gBattleMoveFailed != 0)) && ((sp28->unk_15 & 0x20) == 0)) {
            D_84390020 = &D_84384570[sp40]->unk_A50;
            if (sp3C->unk_34 & 0x200) {
                D_84390020 = &D_84384570[sp40]->unk_B00;
            }
        } else if (!(sp3C->unk_34 & 1)) {
            BattleAnim_SetModelEventTrackAndState(sActivePokemon[sp40], 0xA8, 1);
        }

        if ((D_843C4DEC >= 0xB) && (BattleScene_IsPartnerPikachu(sActivePokemon[sp40]) != 0)) {
            Cry_Play(0xC8, 6);
        }

        if ((D_843C4DEC == 0xA) && (BattleScene_IsPartnerPikachu(sActivePokemon[sp40]) != 0)) {
            Cry_Play(0xC8, 5);
        }

        if ((gBattleMoveFailed == 0) && (sp28->usedMove == 0x49)) {
            D_84390020 = &D_84384570[sp40]->unk_A80;
        }

        ModelAnim_SetFrame(&sActivePokemon[sp40]->unk_000, 0);
        ModelAnim_SetAnimation(&sActivePokemon[sp40]->unk_000, D_84390020->unk_00);

        if ((sp28->unk_44.unk_00 == 0x17) || (sp28->unk_44.unk_00 == 0x22) || (sp28->unk_44.unk_00 == 0x45)) {
            BattleScene_SetParticipantModelFlags(sActivePokemon[sp40], 0xF, 0);
        }
    }
}

void BattleScene_TickPlayMoveEffectEnd(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp20;
    s32 sp28;

    sp20 = &active_pokemon->unk_654.runtime;
    sp28 = BattleScene_GetParticipantSideIndex(active_pokemon);

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->unk_000[sp20->usedMove - 1];

    if (sActivePokemon[sp28 == 0]->unk_4C4 == (D_84390020->unk_07 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            BattleAnim_CleanupEffects(1);
            if (sp20->unk_44.unk_00 == 0x51) {
                if ((D_843C4E45 != 0) && (D_843C4E44 != 0)) {
                    BattleAnim_PlayMoveEffectEnd(sActivePokemon[sp28 == 0], sp20->usedMove);
                    BattleScene_SetParticipantModelFlags(sActivePokemon[sp28 == 0], 0x10, 0);
                }
            } else {
                BattleAnim_PlayMoveEffectEnd(sActivePokemon[sp28 == 0], sp20->usedMove);
                if ((sp20->unk_44.unk_00 == 0x14) || (sp20->unk_44.unk_00 == 0x23) || (sp20->unk_44.unk_00 == 0x84)) {
                    BattleScene_SetParticipantModelFlags(sActivePokemon[sp28 == 0], 0x10, 0);
                }
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow4PostEndCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp20;
    s32 sp28;

    sp28 = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    sp20 = &active_pokemon->unk_654.runtime;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->unk_000[sp20->usedMove - 1];

    if ((D_84390020->unk_07 + 1) == sActivePokemon[sp28]->unk_4C4) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (D_843C4E44 == 1) {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[sp28], sp20, 1);
            } else {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[sp28], sp20, 5);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_EnterRow15StartAnimA80Seq30(ActivePokemon* active_pokemon) {
    s32 sp1C = BattleScene_GetParticipantSideIndex(active_pokemon);

    D_84390020 = &D_84384570[sp1C]->unk_A80;
    sActivePokemon[sp1C]->unk_4C4 = 0;
    ModelAnim_SetFrame(&active_pokemon->unk_000, 0);
    ModelAnim_SetAnimation(&active_pokemon->unk_000, D_84390020->unk_00);
    BattleAnim_SetModelEventTrackAndState(sActivePokemon[sp1C], 0xA8, 1);
    BattleAnim_PlayBattleSequenceById(active_pokemon, 0x1E);
}

s32 BattleScene_IsOpponentRowCheckpointReached(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp1C;

    sp1C = &sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->unk_654.runtime;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp1C->usedMove - 1];
    if (D_84390020->unk_0C != 0) {
        if (active_pokemon->unk_4C4 == D_84390020->unk_0C) {
            return 1;
        }
        return 0;
    }
    return 0;
}

s32 BattleScene_IsRowZeroCheckpointReached(ActivePokemon* active_pokemon) {
    BattleScene_GetParticipantSideIndex(active_pokemon);
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[0];
    if (D_84390020->unk_0C != 0) {
        if (active_pokemon->unk_4C4 == D_84390020->unk_0C) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void func_84303E58(ActivePokemon* active_pokemon) {
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_A80;
    BattleAnim_SetModelEventTrackFromRow(active_pokemon, 0xA8);
    active_pokemon->unk_4C4 = 0;
    ModelAnim_SetFrame(&active_pokemon->unk_000, 0);
    ModelAnim_SetAnimation(&active_pokemon->unk_000, D_84390020->unk_00);
}

void BattleScene_EnterRowAnim166WithCry(ActivePokemon* active_pokemon) {
    s32 idx = active_pokemon->unk_4C0;
    s32 temp_a0;
    s32 sp34;
    BattleMon* sp30;
    ActivePokemonState* sp24;

    sp34 = gBattleSceneStateRowTable[idx].unk_20;
    sp30 = &active_pokemon->unk_724->pokemonPicked[active_pokemon->unk_654.unk_08];
    sp24 = &active_pokemon->unk_654;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp34];
    temp_a0 = sp24->unk_34 & 2;

    if ((temp_a0 == 0) && !(sp24->unk_34 & 0x4000) && (temp_a0 == 0)) {
        if (sp30->unk_05 & 7) {
            if (BattleScene_ByteArrayContains(active_pokemon->unk_000.objectType, D_84384590, 8) != 0) {
                D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unkA90[0x60];
            } else {
                D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_A50;
            }
        } else if (sp24->unk_34 & 0x200) {
            D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_B00;
        }

        ModelAnim_SetFrame(&active_pokemon->unk_000, 0);
        ModelAnim_SetAnimation(&active_pokemon->unk_000, D_84390020->unk_00);

        if (sp24->unk_34 & 0x200) {
            if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0x1A);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->unk_000.objectType, 0x1A);
            }
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0xA);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->unk_000.objectType, 0xA);
        }
    }
}

void BattleScene_TickRow1PlayOwnerCry(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    ActivePokemonState* sp18 = &active_pokemon->unk_654;
    BattleMon* ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->unk_654.unk_08];

    if ((sp18->unk_34 & 0x4000) || (sp18->unk_34 & 2) || (ptr->unk_05 & 7)) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    } else if (active_pokemon->unk_4C4 == 1) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (active_pokemon->unk_000.objectType >= 0x98) {
                BattleAnim_PlayOwnerCry(active_pokemon, sp18->unk_BC);
            } else {
                BattleAnim_PlayOwnerCry(active_pokemon, active_pokemon->unk_000.objectType);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow16PlayCryAndSpeciesSound(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    BattleMon* ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->unk_654.unk_08];
    ActivePokemonState* sp24 = &active_pokemon->unk_654;

    if ((active_pokemon->unk_654.unk_34 & 0x4000) || (sp24->unk_34 & 2) || (ptr->unk_05 & 7)) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    } else if ((active_pokemon->unk_4C4 == 1) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        if (active_pokemon->unk_000.objectType >= 0x98) {
            Cry_Play(sp24->unk_BC, 3);
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            Cry_Play(0xC8, 3);
        } else {
            Cry_Play(active_pokemon->unk_000.objectType, 3);
        }

        if (sp24->unk_34 & 0x200) {
            if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0x1B);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->unk_000.objectType, 0x1B);
            }
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0xB);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->unk_000.objectType, 0xB);
        }
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickRow18PlayCryAndSpeciesSound(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    BattleMon* ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->unk_654.unk_08];
    ActivePokemonState* sp24;

    if ((active_pokemon->unk_654.unk_34 & 0x4000) || (ptr->unk_05 & 0x20) || (ptr->unk_05 & 7)) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        return;
    }

    if ((active_pokemon->unk_4C4 == 1) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        sp24 = &active_pokemon->unk_654;
        if (active_pokemon->unk_000.objectType >= 0x98) {
            Cry_Play(sp24->unk_BC, 4);
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            Cry_Play(0xC8, 4);
        } else {
            Cry_Play(active_pokemon->unk_000.objectType, 4);
        }

        if (sp24->unk_34 & 0x200) {
            if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0x1B);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->unk_000.objectType, 0x1B);
            }
        } else if (BattleScene_IsPartnerPikachu(active_pokemon) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, 0xC8, 0xB);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(active_pokemon) & 0xFF, 0, active_pokemon->unk_000.objectType, 0xB);
        }

        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickAssetLoadQueueRowEffectList3(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    s32 sp24 = active_pokemon->unk_4C0;
    ActivePokemonState* temp_v1 = &active_pokemon->unk_654;

    if (BattleAnim_TryRegisterAssetTables(active_pokemon) != 0) {
        active_pokemon->unk_720->unk_02 = active_pokemon->unk_654.runtime.unk_0B;
        active_pokemon->unk_4C4 = 0;
        BattleScene_QueueRowEffectList3(active_pokemon, gBattleSceneStateRowTable[sp24].unk_24);
        Audio_PlayCommand(3, 0, 0);
        active_pokemon->unk_720->unk_04 = &active_pokemon->unk_720->teamMember[temp_v1->unk_2B]->pokemonPicked[temp_v1->unk_18];
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void func_843046BC(ActivePokemon* active_pokemon) {
    BattleScene_GetParticipantSideIndex(active_pokemon);
    if ((active_pokemon->unk_4C4 == 1) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        s32 idx = active_pokemon->unk_4C0;

        BattleScene_QueueRowEffectList3(active_pokemon, gBattleSceneStateRowTable[idx].unk_24);
        Audio_PlayCommand(3, 0, 0);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickRow20CleanupAndEnterState18(ActivePokemon* active_pokemon) {
    if (active_pokemon->unk_4C4 == 0x4F) {
        active_pokemon->unk_720->unk_00 |= 0x80;
    }

    if (active_pokemon->unk_720->unk_00 & 0x10) {
        active_pokemon->unk_720->unk_00 &= ~0x90;

        Battle_LoadOwnerModelForSwitchIn(active_pokemon);
        BattleScene_TickOwnerCameraFraming(active_pokemon);
        Audio_PlayCommand(2, 0, 0);

        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;

        BattleScene_EnterStateRow(active_pokemon, 0x12);
    }
}

void func_84304800(ActivePokemon* active_pokemon) {
    if (active_pokemon->unk_720->unk_00 & 0x10) {
        active_pokemon->unk_720->unk_00 &= ~0x90;
        Battle_ResetOwnerModelToNeutralPlaceholder(active_pokemon);
    }
}

void BattleScene_EnterRow8StartMappedMoveAnim(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    s32 sp24 = D_84384670[active_pokemon->unk_654.runtime.usedMove - 1];

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp24];
    active_pokemon->unk_4C4 = 0;
    ModelAnim_SetFrame(&active_pokemon->unk_000, 0);
    ModelAnim_SetAnimation(&active_pokemon->unk_000, D_84390020->unk_00);
    BattleAnim_SetModelEventTrackFromRow(active_pokemon, sp24);
}

void BattleScene_TickRow8PlayMoveEffectScriptB(ActivePokemon* active_pokemon) {
    BattleMonRuntime* temp_s1_2;
    s16 sp22;
    s16 temp_s1;

    sp22 = active_pokemon->unk_000.objectType - 1;
    temp_s1_2 = &active_pokemon->unk_654.runtime;
    temp_s1 = D_84384670[temp_s1_2->usedMove - 1];

    BattleScene_GetParticipantSideIndex(active_pokemon);

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[temp_s1];

    if ((active_pokemon->unk_4C4 == (D_84390020->unk_04 + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleAnim_PlayMoveEffectScriptB(active_pokemon, temp_s1_2->usedMove);

        if (temp_s1_2->usedMove == 0x13) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 3, 0);
        }

        if ((temp_s1_2->usedMove == 0x5B) && (sp22 != 0x31) && (sp22 != 0x32)) {
            BattleScene_SetParticipantModelFlags(active_pokemon, 5, 0);
            BattleAnim_QueueEffectList(4, active_pokemon);
        }

        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;

        BattleAnim_PlaySpeciesReactionSound(active_pokemon, temp_s1_2, 4);
    }
}

void BattleScene_EnterRow9SetEventTrack(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[3];
    BattleMon* ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->unk_654.unk_08];
    s32 sp1C;

    active_pokemon->unk_4C4 = 0;
    if (!(active_pokemon->unk_654.unk_34 & 2)) {
        if (ptr->unk_05 & 7) {
            if (BattleScene_ByteArrayContains(active_pokemon->unk_000.objectType, D_84384590, 8) != 0) {
                sp1C = 0xAF;
            } else {
                sp1C = 0xA5;
            }
        } else {
            sp1C = 0xA5;
        }
        D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp1C];
        BattleAnim_SetModelEventTrackFromRow(active_pokemon, sp1C);
    }
}

void BattleScene_EnterRow9QueueEffectList6(ActivePokemon* active_pokemon) {
    BattleMonRuntime* ptr = &sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->unk_654.runtime;

    if (ptr->unk_4C & 0x20) {
        if ((ptr->usedMove == 0x14) || (ptr->usedMove == 0x23) || (ptr->usedMove == 0x51)) {
            BattleAnim_QueueEffectList6(2, active_pokemon);
            BattleScene_SetParticipantModelFlags(active_pokemon, 0x10, 0);
        }
    }
}

void BattleScene_Row12Slot1CameraCleanup(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp20;
    s32 sp28;

    sp28 = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    sp20 = &active_pokemon->unk_654.runtime;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->unk_000[sp20->usedMove - 1];

    if ((D_84390020->unk_07 + 1) == sActivePokemon[sp28]->unk_4C4) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            BattleAnim_PlaySpeciesReactionSound(active_pokemon, sp20, 5);
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_Row13PlaySequences14And21(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp20 = &active_pokemon->unk_654.runtime;

    if (sp20->unk_15 & 8) {
        BattleAnim_PlayBattleSequenceById(active_pokemon, 0x14);
    }

    if (sp20->unk_15 & 0x10) {
        BattleAnim_PlayBattleSequenceById(active_pokemon, 0x21);
    }

    gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
}

void BattleScene_TickPlaySpeciesSequence33(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    u16 sp22 = active_pokemon->unk_000.objectType;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_A70;
    if ((BattleScene_GetParticipantModelHeight(active_pokemon) != 0.0f) && (sp22 != 0x16) && (sp22 != 0x52) && (sp22 != 0x8E)) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    } else if ((active_pokemon->unk_4C4 == (D_84390020->unk_04 + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleAnim_PlaySpeciesSequence33(active_pokemon);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickQueueList3Selector2OrC(ActivePokemon* active_pokemon) {
    s32 sp24;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_A70;
    if (D_84390020->unk_09 == 1) {
        sp24 = D_84390020->unk_0A - 0x4C;
    } else {
        sp24 = D_84390020->unk_0A - 0x31;
    }

    if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
        if (BattleScene_GetParticipantModelHeight(active_pokemon) != 0.0f) {
            if ((sp24 <= 0) || (sp24 == active_pokemon->unk_4C4)) {
                if (D_84390020->unk_09 == 1) {
                    BattleAnim_QueueEffectList3(2, active_pokemon, active_pokemon, 0xFF, 0xFF);
                } else {
                    BattleAnim_QueueEffectList3(0xC, active_pokemon, active_pokemon, 0xFF, 0xFF);
                }
                Audio_PlayCommand(3, 0, 0);
                gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
            }
        } else if ((sp24 <= 0) || (sp24 == active_pokemon->unk_4C4)) {
            if (D_84390020->unk_09 == 1) {
                BattleAnim_QueueEffectList3(2, active_pokemon, active_pokemon, 0xFF, 0xFF);
            } else {
                BattleAnim_QueueEffectList3(0xC, active_pokemon, active_pokemon, 0xFF, 0xFF);
            }
            Audio_PlayCommand(3, 0, 0);
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickQueueList3Selector2OrCFromB10(ActivePokemon* active_pokemon) {
    s32 sp24;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_B10;
    if (D_84390020->unk_09 == 1) {
        sp24 = D_84390020->unk_0A - 0x4C;
    } else {
        sp24 = D_84390020->unk_0A - 0x31;
    }

    if ((BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) && ((sp24 <= 0) || (sp24 == active_pokemon->unk_4C4))) {
        if (D_84390020->unk_09 == 1) {
            BattleAnim_QueueEffectList3(2, active_pokemon, active_pokemon, 0xFF, 0xFF);
        } else {
            BattleAnim_QueueEffectList3(0xC, active_pokemon, active_pokemon, 0xFF, 0xFF);
        }
        Audio_PlayCommand(3, 0, 0);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void func_8430506C(ActivePokemon* active_pokemon) {
    s32 pad3;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    ActivePokemonState* sp3C;
    s32 pad[2];
    ActivePokemon* sp30;
    BattleMonRuntime* sp28;

    sp48 = 0xA5;
    sp40 = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    sp3C = &sActivePokemon[sp40]->unk_654;
    sp30 = sActivePokemon[sp40];
    sp28 = &active_pokemon->unk_654.runtime;

    D_84390020 = &D_84384570[sp40]->unk_A80;

    if (sp3C->unk_34 & 1) {
        if (BattleScene_ByteArrayContains(sp30->unk_000.objectType, D_84384598, 2) != 0) {
            D_84390020 = &D_84384570[sp40]->unk_B20;
        }
    }

    if ((sp3C->unk_34 & 1) && BattleScene_ByteArrayContains(sp30->unk_000.objectType, D_84384590, 8)) {
        sp48 = 0xAF;
    }

    sActivePokemon[sp40]->unk_4C4 = 0;

    if (!(sp3C->unk_34 & 0x4000) && !(sp3C->unk_34 & 2)) {
        if ((sp28->usedMove == 0x91) && (D_843C4DEC < 0xA)) {
            D_84390020 = &D_84384570[sp40]->unk_000[sp48];
        }

        if ((D_843C4E44 == 0) || (gBattleMoveFailed != 0)) {
            sp44 = 0xB0;
            D_84390020 = &D_84384570[sp40]->unk_000[sp48];
            if (sp3C->unk_34 & 0x200) {
                D_84390020 = &D_84384570[sp40]->unk_000[sp44];
            }
        } else if (!(sp3C->unk_34 & 1)) {
            BattleAnim_SetModelEventTrackFromRow(sActivePokemon[sp40], 0xA8);
        }

        ModelAnim_SetFrame(&sActivePokemon[sp40]->unk_000, 0);
        ModelAnim_SetAnimation(&sActivePokemon[sp40]->unk_000, D_84390020->unk_00);

        if ((sp28->unk_44.unk_00 == 0x17) || (sp28->unk_44.unk_00 == 0x22) || (sp28->unk_44.unk_00 == 0x45)) {
            BattleScene_SetParticipantModelFlags(sActivePokemon[sp40], 0xF, 0);
        }
    }
}

void BattleScene_TickRow14PlayMoveEffectEnd(ActivePokemon* active_pokemon) {
    s32 sp2C;
    UNUSED s32 pad;
    BattleMonRuntime* sp24;
    BattleMonRuntime* sp1C;

    sp2C = BattleScene_GetParticipantSideIndex(active_pokemon);
    sp24 = &sActivePokemon[sp2C == 0]->unk_654.runtime;
    sp1C = &active_pokemon->unk_654.runtime;

    D_84390020 = &D_84384570[sp2C == 0]->unk_000[sp1C->usedMove - 1];

    if ((sActivePokemon[sp2C == 0]->unk_4C4 == (D_84390020->unk_07 + 1)) && (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0)) {
        BattleAnim_CleanupEffects(1);
        if (((sp1C->usedMove == 0x30) || (sp1C->usedMove == 0x6D)) && (sp24->unk_4C & 0x80) && (gBattleMoveFailed == 0) &&
            (D_843C4E44 == 1)) {
            BattleAnim_PlayBattleSequenceById(sActivePokemon[sp2C == 0], 0x12);
        }

        BattleAnim_PlayMoveEffectEnd(sActivePokemon[sp2C == 0], sp1C->usedMove);
        if ((gBattleMoveFailed == 0) || (D_843C4E44 == 1)) {
            BattleAnim_PlaySpeciesReactionSound(sActivePokemon[sp2C == 0], &active_pokemon->unk_654.runtime, 1);
        }

        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

s32 func_84305458(ActivePokemon* active_pokemon) {
    BattleMonRuntime* ptr = &active_pokemon->unk_654.runtime;
    s32 temp_v1;

    temp_v1 = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    D_84390020 = &D_84384570[temp_v1]->unk_000[ptr->usedMove - 1];

    if (D_843C4E45 != 1) {
        return 2;
    }

    if ((D_84390020->unk_08 + 0x50) == sActivePokemon[temp_v1]->unk_4C4) {
        return 1;
    }

    return 0;
}

void BattleScene_TickRow11QueueEffectList6(ActivePokemon* active_pokemon) {
    BattleMonRuntime* ptr = &active_pokemon->unk_654.runtime;
    s32 sp28;

    sp28 = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->unk_000[ptr->usedMove - 1];
    if (sActivePokemon[sp28]->unk_4C4 == (D_84390020->unk_08 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (D_843C4E45 == 1) {
                BattleAnim_QueueEffectList6(1, sActivePokemon[sp28]);
                BattleAnim_PlayBattleSequenceById(active_pokemon, 0x20);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow11PostEndCamera(ActivePokemon* active_pokemon) {
    BattleMonRuntime* sp20;
    s32 sp28;

    sp28 = BattleScene_GetParticipantSideIndex(active_pokemon) == 0;
    sp20 = &active_pokemon->unk_654.runtime;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->unk_000[sp20->usedMove - 1];

    if ((D_84390020->unk_07 + 1) == sActivePokemon[sp28]->unk_4C4) {
        if (BattleAnim_IsAssetLoadBusy(active_pokemon) == 0) {
            if (D_843C4E44 == 1) {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[sp28], sp20, 1);
            } else {
                BattleAnim_PlaySpeciesReactionSound(sActivePokemon[sp28], sp20, 5);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_StateCallbackNop(ActivePokemon* active_pokemon) {
}

void BattleScene_RegisterStateTickCallback(ActivePokemon* arg0, BattleSceneStateCallback arg1) {
    BattleSceneStateTickSlot* var_a2;
    s32 i;

    for (i = 0; i < 7; i++) {
        if (gBattleSceneStateTickSentinel == gBattleSceneStateTickSlots[i].unk_04) {
            gBattleSceneStateTickSlots[i].unk_04 = arg1;
            gBattleSceneStateTickSlots[i].unk_00 = arg0;
            break;
        }
    }
}

void BattleScene_SetOpponentEventTrackA6(ActivePokemon* active_pokemon) {
    BattleAnim_SetModelEventTrackFromRow(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon)], 0xA6);
}

void BattleScene_EnterStateRow(ActivePokemon* arg0, s32 arg1) {
    arg0->unk_4C0 = arg1;

    gBattleSceneStateRowTable[arg1].unk_04[0](arg0);
    gBattleSceneStateRowTable[arg1].unk_04[1](arg0);
    gBattleSceneStateRowTable[arg1].unk_04[2](arg0);

    BattleScene_RegisterStateTickCallback(arg0, gBattleSceneStateRowTable[arg1].unk_04[3]);
    BattleScene_RegisterStateTickCallback(arg0, gBattleSceneStateRowTable[arg1].unk_04[4]);
    BattleScene_RegisterStateTickCallback(arg0, gBattleSceneStateRowTable[arg1].unk_04[5]);
    BattleScene_RegisterStateTickCallback(arg0, gBattleSceneStateRowTable[arg1].unk_04[6]);
}

void BattleScene_TickStateCallbacks(void) {
    sActivePokemon[0]->unk_4C4++;
    sActivePokemon[1]->unk_4C4++;

    for (gBattleSceneStateTickSlotIndex = 0; gBattleSceneStateTickSlotIndex < 7; gBattleSceneStateTickSlotIndex++) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04(gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_00);
    }
}

void Battle_ResetCryEventIfStruggle(ActivePokemon* active_pokemon) {
    if (active_pokemon->unk_654.runtime.usedMove == 0x6A) {
        active_pokemon->unk_000.textureMode = 0;
    }
}

void BattleAnim_SetModelEventTrackFromRow(ActivePokemon* arg0, s32 arg1) {
    s32 temp_v0;
    s32 sp30;
    ActivePokemonState* sp24 = &arg0->unk_654;

    if (BattleAnim_IsSessionBusy(arg0) == 0) {
        sp30 = D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[arg1].unk_01;
        if ((sp30 != 0xFF) && (sp24->unk_36 != 2)) {
            if ((arg1 == 165) && (arg0->unk_000.objectType == 0x33)) {
                ModelAnim_SetEventFrame(&arg0->unk_000, 0);
                temp_v0 = BattleAnim_RandomRange(3);
                if (temp_v0 >= 3) {
                    temp_v0 = 2;
                }
                ModelAnim_SetEventTrack(&arg0->unk_000, sp30 + temp_v0);
            } else {
                ModelAnim_SetEventFrame(&arg0->unk_000, 0);
                ModelAnim_SetEventTrack(&arg0->unk_000, sp30);
                sp24->unk_36 = 1;
            }
        }
    }
}

s32 BattleAnim_TrySetModelEventTrackFromRow(ActivePokemon* arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad;
    s32 sp20;

    if (BattleAnim_IsSessionBusy(arg0) != 0) {
        return 0;
    }

    sp20 = D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[arg1].unk_01;
    if (sp20 == 0xFF) {
        return 1;
    }

    ModelAnim_SetEventFrame(&arg0->unk_000, 0);
    ModelAnim_SetEventTrack(&arg0->unk_000, sp20);
    ModelAnim_SetEventFrame(&arg0->unk_000, arg0->unk_000.eventTrack.data->endFrame);

    arg0->unk_654.unk_36 = arg2;
    return 0;
}

void BattleAnim_SetModelEventTrackAndState(ActivePokemon* arg0, s32 arg1, s32 arg2) {
    u8 temp_a1;

    if (BattleAnim_IsSessionBusy(arg0) == 0) {
        temp_a1 = D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[arg1].unk_01;
        if (temp_a1 != 0xFF) {
            ModelAnim_SetEventTrack(&arg0->unk_000, temp_a1);
            ModelAnim_SetEventFrame(&arg0->unk_000, 0);
            arg0->unk_654.unk_36 = arg2;
        }
    }
}

s32 BattleScene_IsParticipantIncapacitated(ActivePokemon* active_pokemon) {
    ActivePokemonState* sp20 = &active_pokemon->unk_654;
    BattleMon* ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->unk_654.unk_08];

    if ((sp20->unk_34 & 2) || (ptr->unk_05 & 7) || ((sp20->unk_34 & 0x200) && !(sp20->unk_34 & 0x400)) ||
        (sp20->unk_34 & 0x4000)) {
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

    if (arg0->unk_000.transformAnim.animationId == -1) {
        return 1;
    }
    return ModelAnim_IsAnimationDone(&arg0->unk_000);
}

s32 BattleScene_IsRowWaitCompleteWithEventCount(ActivePokemon* arg0, s32 arg1) {
    u8 temp_v0;

    D_84390020 = D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unkA60;
    if (BattleScene_IsParticipantIncapacitated(arg0) != 0) {
        if (BattleScene_AdvanceCameraFrameCounter(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if ((D_84390020->unk_0A < 0xB) || (D_84390020->unk_0A == 0xFF)) {
        if (arg0->unk_000.transformAnim.animationId == -1) {
            return 1;
        }
        return ModelAnim_IsAnimationDone(&arg0->unk_000);
    }

    if (BattleScene_AdvanceCameraFrameCounter(D_84390020->unk_0A + 1) != 0) {
        return 1;
    }

    return 0;
}

s32 Battle_IsRowAnimationSettled(ActivePokemon* arg0, s32 arg1) {
    BattleMonRuntime* ptr = &arg0->unk_654.runtime;
    MovePresentationCue* sp20;
    MovePresentationCue* sp1C;

    if (arg0) {}

    sp20 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[ptr->usedMove - 1];
    sp1C = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_A50;

    if (BattleScene_IsParticipantIncapacitated(arg0) != 0) {
        if (BattleScene_AdvanceCameraFrameCounter(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if (arg0->unk_000.transformAnim.animationId == -1) {
        return 1;
    }

    if (gBattleScene.unk_00->unk_48 == 0x14) {
        sp20 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[0];
    }

    if (sp20->unk_00 == sp1C->unk_00) {
        if (sp20->unk_0A != 0xFF) {
            gBattleScene.unk_00->unk_14++;
            if (sp20->unk_0A == arg0->unk_4C4) {
                return 1;
            }
            return 0;
        }

        if (BattleScene_AdvanceCameraFrameCounter(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    gBattleScene.unk_00->unk_14++;

    if (sp20->unk_0A != 0xFF) {
        if (sp20->unk_0A == arg0->unk_4C4) {
            return 1;
        }
        return 0;
    }

    return ModelAnim_IsAnimationDone(&arg0->unk_000);
}

s32 BattleScene_IsMoveKeyedRowWaitComplete(ActivePokemon* arg0, s32 arg1) {
    MovePresentationCue* temp_a2;
    BattleMon* sp28;
    UNUSED s32 pad;
    s32 sp20;
    MovePresentationCue* sp1C;

    sp28 = &arg0->unk_724->pokemonPicked[arg0->unk_654.unk_08];
    sp20 = D_84384670[arg0->unk_654.runtime.usedMove - 1];
    sp1C = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp20];
    temp_a2 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_A50;

    if ((arg0->unk_654.unk_34 & 2) || (sp28->unk_05 & 7) ||
        ((arg0->unk_654.unk_34 & 0x200) && !(arg0->unk_654.unk_34 & 0x400)) || (arg0->unk_654.unk_34 & 0x4000)) {
        if (BattleScene_AdvanceCameraFrameCounter(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if (arg0->unk_000.transformAnim.animationId == -1) {
        return 1;
    }

    if (sp1C->unk_00 == temp_a2->unk_00) {
        if (sp1C->unk_0A != 0xFF) {
            gBattleScene.unk_00->unk_14++;
            if (sp1C->unk_0A == arg0->unk_4C4) {
                return 1;
            }
            return 0;
        }
        if (BattleScene_AdvanceCameraFrameCounter(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    gBattleScene.unk_00->unk_14++;

    if (sp1C->unk_0A != 0xFF) {
        if (sp1C->unk_0A == arg0->unk_4C4) {
            return 1;
        }
        return 0;
    }
    return ModelAnim_IsAnimationDone(&arg0->unk_000);
}

s32 BattleScene_IsRowAnimWaitComplete(ActivePokemon* arg0, s32 arg1) {
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_A80;

    if ((arg0->unk_654.unk_34 & 2) || ((arg0->unk_654.unk_34 & 0x200) && !(arg0->unk_654.unk_34 & 0x400))) {
        if (BattleScene_AdvanceCameraFrameCounter(arg1) != 0) {
            return 1;
        }
        return 0;
    }

    if (arg0->unk_000.transformAnim.animationId == -1) {
        return 1;
    }

    if (arg0->unk_000.transformAnim.animationId != D_84390020->unk_00) {
        return 1;
    }

    return ModelAnim_IsAnimationDone(&arg0->unk_000);
}

void func_843060EC(ActivePokemon* active_pokemon) {
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_A50;
    if (BattleAnim_IsSessionBusy(active_pokemon) == 0) {
        if ((active_pokemon->unk_000.transformAnim.animationId != -1) && (active_pokemon->unk_000.node.flags & 1) &&
            (active_pokemon->unk_000.node.renderFlags & 0x20) && (gBattleScene.unk_00->unk_1C == 1) &&
            (D_84390020->unk_00 == active_pokemon->unk_000.transformAnim.animationId) &&
            (D_84390020->unk_04 == (active_pokemon->unk_000.transformAnim.frameFixed >> 0x10)) && (D_84390020->unk_05 != 0) &&
            (BattleAnim_RandomRange(2) == 1)) {
            BattleAnim_QueueEffectList3(D_84390020->unk_05, &active_pokemon->unk_000, &active_pokemon->unk_000, D_84390020->unk_02, D_84390020->unk_02);
        }
    }
}

void Battle_SetRuntimeFlags(ActivePokemon* arg0, u16 arg1) {
    arg0->unk_654.unk_34 |= arg1;
}

s32 Battle_ClearRuntimeFlags(ActivePokemon* arg0, u16 arg1) {
    arg0->unk_654.unk_34 &= ~arg1;
}

void BattleScene_ResetParticipantAnimationFlags(ActivePokemon* active_pokemon) {
    ActivePokemonState* sp24 = &active_pokemon->unk_654;

    if (active_pokemon->unk_4C8 != 0) {
        if (sp24->unk_34 & 0x200) {
            active_pokemon->unk_000.position.y = D_84390028[BattleScene_GetParticipantSideIndex(active_pokemon)].unk_08;
            Battle_ClearRuntimeFlags(active_pokemon, 0x608);
        }

        if (sp24->unk_34 & 0x4008) {
            active_pokemon->unk_000.lodFraction = 0xFF;
            BattleAnim_StopOwnerCategoryParticles(4, active_pokemon);
            active_pokemon->unk_000.position.y = D_84390028[BattleScene_GetParticipantSideIndex(active_pokemon)].unk_08;
            active_pokemon->unk_000.node.renderFlags &= ~2;
            active_pokemon->unk_000.node.renderFlags |= 0x20;
            active_pokemon->unk_000.node.flags |= 1;
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

    sp34 = &sActivePokemon[0]->unk_654;
    sp30 = &sActivePokemon[1]->unk_654;
    sp24 = sActivePokemon[0];
    sp20 = sActivePokemon[1];

    if (sp34->unk_34 & 4) {
        sActivePokemon[0]->unk_000.position.y = 200.0f;
        Battle_SetRuntimeFlags(sActivePokemon[0], 0x200);
        Battle_ClearRuntimeFlags(sActivePokemon[0], 4);
    }

    if (sp30->unk_34 & 4) {
        sActivePokemon[1]->unk_000.position.y = 200.0f;
        Battle_SetRuntimeFlags(sActivePokemon[1], 0x200);
        Battle_ClearRuntimeFlags(sActivePokemon[1], 4);
    }

    if ((sp34->unk_34 & 0x4000) && (sp24->unk_000.objectType == 0x33)) {
        D_84390020 = &D_84384570[0]->unk_000[0x5A];
        ModelAnim_SetFrame(&sActivePokemon[0]->unk_000, 0);
        ModelAnim_SetAnimation(&sActivePokemon[0]->unk_000, D_84390020->unk_00);
    }

    if ((sp30->unk_34 & 0x4000) && (sp20->unk_000.objectType == 0x33)) {
        D_84390020 = &D_84384570[1]->unk_000[0x5A];
        ModelAnim_SetFrame(&sActivePokemon[1]->unk_000, 0);
        ModelAnim_SetAnimation(&sActivePokemon[1]->unk_000, D_84390020->unk_00);
    }

    BattleScene_ResetParticipantAnimationFlags(sActivePokemon[0]);
    BattleScene_ResetParticipantAnimationFlags(sActivePokemon[1]);
}

void Battle_ClearOpponentHopFlagAndSyncMove(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    ActivePokemonState* sp20;

    sp20 = &sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->unk_654;
    BattleScene_GetParticipantSideIndex(active_pokemon);
    BattleScene_GetParticipantSideIndex(active_pokemon);
    Battle_ResetCryEventIfStruggle(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]);

    if (sp20->unk_34 & 4) {
        sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0]->unk_000.position.y = 200.0f;
        Battle_SetRuntimeFlags(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0], 0x200);
        Battle_ClearRuntimeFlags(sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0], 4);
    }

    if (active_pokemon->unk_654.unk_34 & 0x200) {
        Battle_SetRuntimeFlags(active_pokemon, 0x400);
    }
}

void BattleScene_CleanupParticipantHideFlag(ActivePokemon* active_pokemon) {
    if (active_pokemon->unk_654.unk_34 & 8) {
        active_pokemon->unk_000.position.y = BattleScene_GetParticipantModelHeight(active_pokemon);
        Battle_ClearRuntimeFlags(active_pokemon, 0x608);
    }
}

void BattleScene_CleanupOpponentSpecialAnimFlag(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[2];
    ActivePokemon* sp1C = sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0];

    if (sp1C->unk_654.unk_34 & 0x4000) {
        sp1C->unk_000.node.renderFlags |= 0x20;
        sp1C->unk_000.node.flags |= 1;
        BattleAnim_StopOwnerCategoryParticles(4, sp1C);
        Battle_ClearRuntimeFlags(sp1C, 0x4000);
    }
}

void BattleScene_CleanupOpponentAnimationFlags(ActivePokemon* active_pokemon) {
    ActivePokemon* temp_s0 = sActivePokemon[BattleScene_GetParticipantSideIndex(active_pokemon) == 0];
    ActivePokemonState* ptr = &temp_s0->unk_654;

    if (ptr->unk_34 & 0x4000) {
        temp_s0->unk_000.node.renderFlags |= 0x20;
        temp_s0->unk_000.node.flags |= 1;
        BattleAnim_StopOwnerCategoryParticles(4, temp_s0);
        Battle_ClearRuntimeFlags(temp_s0, 0x4000);
    }

    if (ptr->unk_34 & 8) {
        temp_s0->unk_000.position.y = BattleScene_GetParticipantModelHeight(active_pokemon);
        Battle_ClearRuntimeFlags(temp_s0, 0x608);
    }
}

void BattleScene_CleanupParticipantEffectMode(ActivePokemon* active_pokemon) {
    switch (active_pokemon->unk_4B4) {
        case 14:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            BattleScene_PositionParticipantModel(active_pokemon);
            break;

        case 13:
        case 15:
        case 16:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            if (active_pokemon->unk_654.runtime.unk_56 == 0) {
                Vec3f_SetComponentsDuplicate(&active_pokemon->unk_000.scale, 1.0f, 1.0f, 1.0f);
            } else {
                Vec3f_SetComponentsDuplicate(&active_pokemon->unk_000.scale, 0.8f, 0.8f, 0.8f);
            }
            break;

        case 12:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            if (active_pokemon->unk_654.runtime.unk_56 == 0) {
                Vec3f_SetComponentsDuplicate(&active_pokemon->unk_000.scale, 1.0f, 1.0f, 1.0f);
            } else {
                Vec3f_SetComponentsDuplicate(&active_pokemon->unk_000.scale, 0.8f, 0.8f, 0.8f);
            }
            break;

        case 10:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            active_pokemon->unk_000.position.y = BattleScene_GetParticipantModelHeight(active_pokemon);
            active_pokemon->unk_000.rotation.x = 0;
            break;

        case 9:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            Vec3f_SetComponentsDuplicate(&active_pokemon->unk_000.scale, 0.8f, 0.8f, 0.8f);
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
            Vec3s_SetComponents(&active_pokemon->unk_000.rotation, 0, active_pokemon->unk_4B0 << 0xE, 0);
            break;

        case 4:
            BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
            active_pokemon->unk_000.rotation.y = active_pokemon->unk_4B0 << 0xE;
            BattleScene_HideParticipantSecondaryModels(active_pokemon);
            break;
    }
}

void BattleAnim_TickParticipantStatusAnimation(ActivePokemon* active_pokemon) {
    ActivePokemonState* temp_s1 = &active_pokemon->unk_654;

    BattleAnim_StartFreezeStatusAnimation(active_pokemon);
    BattleAnim_UpdateSleepStatusAnimation(active_pokemon);

    if (temp_s1->unk_34 & 0x100) {
        active_pokemon->unk_000.node.renderFlags &= 0xFFDF;
    }

    if ((temp_s1->unk_2D == 0x10) || (temp_s1->unk_2D == 0x13)) {
        Battle_ClearRuntimeFlags(active_pokemon, 0x100);
    }

    temp_s1->unk_2E = Math_StepToS32(temp_s1->unk_2E, 0, 0x1E, 0x1E);
    if (temp_s1->unk_2E != 0) {
        Model_SetMaterialColor(&active_pokemon->unk_000, 0xFF, 0xFF, 0xFF, temp_s1->unk_2E);
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
            if (ModelAnim_IsEventTrackNearEnd(&active_pokemon->unk_000) == 1) {
                ModelAnim_SetEventTrack(&active_pokemon->unk_000, -1);
                ModelAnim_SetEventFrame(&active_pokemon->unk_000, 0);
                temp_s1->unk_36 = 0;
            }
            break;
    }

    if (temp_s1->unk_34 & 0x4000) {
        if ((active_pokemon->unk_000.objectType != 0x32) && (active_pokemon->unk_000.objectType != 0x33)) {
            active_pokemon->unk_000.lodFraction = 0;
        }
    }
}

void BattleAnim_TriggerStatusAfflictionCry(ActivePokemon* active_pokemon) {
    BattleMon* ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->unk_654.unk_08];

    if ((ptr->unk_05 & 7) && !(active_pokemon->unk_654.unk_34 & 1)) {
        BattleAnim_SetModelEventTrackAndState(active_pokemon, 0xAF, 2);
        BattleAnim_QueueEffectList(3, active_pokemon);
        BattleAnim_PlayBattleSequenceById(active_pokemon, 0x32);
    }
}

void BattleScene_AllocateParticipantRecord(BattleSessionTeams* arg0, s32 arg1) {
    ActivePokemon* ptr = main_pool_alloc(sizeof(ActivePokemon), 0);

    sActivePokemon[arg1] = ptr;

    bzero(ptr, sizeof(ActivePokemon));
    bzero(&sActivePokemon[arg1]->unk_654, sizeof(ActivePokemonState));
    bzero(&sActivePokemon[arg1]->unk_654.runtime, sizeof(BattleMonRuntime));
    bzero(&sActivePokemon[arg1]->unk_728, sizeof(PresentationState));
    bzero(&sActivePokemon[arg1]->unk_654.runtime.unk_44, sizeof(CachedMoveData));
    bzero(&sActivePokemon[arg1]->unk_654.unk_9C, sizeof(unk_D_84390010_654_09C));
    bzero(&sActivePokemon[arg1]->unk_654.unk_AC, sizeof(unk_D_84390010_654_0AC));
    bzero(&sActivePokemon[arg1]->unk_8C4, sizeof(MonCaptionState));
    sActivePokemon[arg1]->unk_720 = arg0;
}

void BattleScene_AllocateParticipants(BattleSessionTeams* arg0) {
    BattleScene_AllocateParticipantRecord(&arg0[0], 0);
    BattleScene_AllocateParticipantRecord(&arg0[1], 1);
    Battle_InitMessageQueues();
    D_84390018 = sActivePokemon[0];
    D_8439001C = sActivePokemon[1];
}

void BattleScene_InitializeParticipantController(ActivePokemon* active_pokemon) {
    Controller* sp24 = &gControllers[active_pokemon->unk_720->teamMember[0]->unk_001];

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
    ModelRenderer_AttachDisplayObject(&active_pokemon->unk_000);

    if (active_pokemon == sActivePokemon[0]) {
        active_pokemon->unk_000.effectSlot = 0;
    } else {
        active_pokemon->unk_000.effectSlot = 1;
    }

    Model_InitDisplayObject(&active_pokemon->unk_000, 0, sp22, sp24);
    func_84302658(active_pokemon, 1);
    ModelAnim_SetAnimation(&active_pokemon->unk_000, 0);
    ModelAnim_SetFrame(&active_pokemon->unk_000, 0);

    active_pokemon->unk_720->unk_04 = active_pokemon->unk_724->pokemonPicked;
    if ((active_pokemon->unk_000.objectType == 0x32) || (active_pokemon->unk_000.objectType == 0x33)) {
        active_pokemon->unk_000.node.renderFlags &= ~0x40;
    } else {
        active_pokemon->unk_000.node.renderFlags |= 0x40;
    }

    if (active_pokemon == sActivePokemon[0]) {
        BattleScene_PositionParticipantModel(active_pokemon);
        active_pokemon->unk_000.rotation.y = 0x4000;
    } else {
        BattleScene_PositionParticipantModel(active_pokemon);
        active_pokemon->unk_000.rotation.y = -0x4000;
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
    ModelNodeView* sp20 = active_pokemon->unk_720->unk_18;

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
    Vec3f_SetComponentsDuplicate(&arg1->unk_448, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&arg1->unk_448.unk_0C, 0.0f, 0.0f, 0.0f);
    arg1->unk_4B0 = arg2;
}

void BattleScene_InitializeRuntime(BattleSessionTeams* arg0) {
    s32 i;

    Text_InitStringTables();

    D_843900B0 = Text_GetStringTable(0x1E);
    D_843900B4 = Text_GetStringTable(0x24);
    D_843900B8 = Text_GetStringTable(0x25);
    D_843900BC = Text_GetStringTable(0x29);
    D_843900C0 = Text_GetStringTable(0x14);

    for (i = 0; i < 7; i++) {
        gBattleSceneStateTickSlots[i].unk_04 = gBattleSceneStateTickSentinel;
    }

    BattleScene_ResetParticipantAuxTransform(sActivePokemon[0], sActivePokemon[0], 1);
    BattleScene_ResetParticipantAuxTransform(sActivePokemon[1], sActivePokemon[1], -1);
    BattleScene_InitializePresentation(arg0);
    Battle_InitializeActiveRuntimeState();
    Battle_InitializeMoveUsabilityMask(sActivePokemon[0]);
    Battle_InitializeMoveUsabilityMask(sActivePokemon[1]);
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
