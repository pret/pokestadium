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

static unk_D_8438E7B0 D_8438E7B0;
static unk_D_8438E7B0 D_8438F390;
static SpeciesModelTransform D_8438FF70;
static SpeciesModelTransform D_8438FF90;
static SpeciesModelTransform D_8438FFB0;
static SpeciesModelTransform D_8438FFD0;
static TagTeamPartners D_8438FFF0;
static TagTeamPartners D_84390000;
Battler* D_84390010[2];
Battler* D_84390018;
Battler* D_8439001C;
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

void BattleScene_ClearStateTickCallbacks(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        gBattleSceneStateTickSlots[i].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_QueueRowEffectList3(Battler* arg0, s32 arg1) {
    BattleAnim_QueueEffectList3(arg1, &arg0->unk_000, &arg0->unk_000, 0xFF, 0xFF);
}

void BattleAnim_PlayMoveEffectScriptA(Battler* arg0, s32 arg1) {
    UNUSED s16 pad;
    s16 sp24;
    s32 sp20;

    sp20 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    sp24 = Battle_GetCameraShotFieldB(arg0);
    BattleAnim_QueueMoveEffectScriptA(arg1, arg0, D_84390010[sp20], sp24, Battle_GetCameraShotFieldC(arg0));
}

void BattleAnim_PlayMoveEffectScriptB(Battler* arg0, s32 arg1) {
    UNUSED s16 pad;
    s16 sp24;
    s32 sp20;

    sp20 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    sp24 = Battle_GetCameraShotFieldB(arg0);
    BattleAnim_QueueMoveEffectScriptB(arg1, arg0, D_84390010[sp20], sp24, Battle_GetCameraShotFieldC(arg0));
}

void BattleAnim_PlayMoveEffectEnd(Battler* arg0, s32 arg1) {
    UNUSED s16 pad;
    s16 sp24;
    s32 sp20;

    sp20 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    sp24 = Battle_GetSideAnimTableFieldB(arg0);
    BattleAnim_QueueMoveEffectEnd(arg1, D_84390010[sp20], arg0, sp24, Battle_GetSideAnimTableFieldC(arg0));
}

void BattleScene_TickClearAnimRecordIfLoaded(Battler* arg0) {
    if (BattleAnim_TryRegisterAssetTables(arg0) != 0) {
        arg0->unk_4C4 = 0;
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickStartRowAnimRecord(Battler* arg0) {
    UNUSED s32 pad;
    s32 idx = arg0->unk_4C0;
    s32 sp24 = gBattleSceneStateRowTable[idx].unk_20;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp24];
    if (BattleAnim_TryRegisterAssetTables(arg0) != 0) {
        BattleAnim_SetModelEventTrackAndState(arg0, sp24, 2);
        arg0->unk_4C4 = 0;
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        ModelAnim_SetFrame(&arg0->unk_000, 0);
        ModelAnim_SetAnimation(&arg0->unk_000, D_84390020->unk_00);
    }
}

void BattleScene_TickQueueRowEffectList3AtAnimEnd(Battler* arg0) {
    s32 idx = arg0->unk_4C0;
    s32 sp28 = gBattleSceneStateRowTable[idx].unk_20;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp28];
    if (BattleScene_GetParticipantModelHeight(arg0) != 0.0f) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    } else if ((arg0->unk_4C4 == (D_84390020->unk_04 + 1)) && (BattleAnim_IsAssetLoadBusy(arg0) == 0)) {
        BattleScene_QueueRowEffectList3(arg0, gBattleSceneStateRowTable[idx].unk_24);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_ResetStateFrameCounter(Battler* arg0) {
    arg0->unk_4C4 = 0;
}

void BattleScene_ResetOpponentStateFrameCounter(Battler* arg0) {
    D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_4C4 = 0;
}

void BattleAnim_SetOverlayFlagForSpecialMoves(Battler* arg0) {
    BattleMonRuntime* ptr = &arg0->unk_654.unk_38;

    if (ptr->unk_5A == 0x46 || ptr->unk_5A == 0x9D || ptr->unk_5A == 0x58) {
        D_84390010[0]->unk_000.node.renderFlags |= 2;
        D_84390010[1]->unk_000.node.renderFlags |= 2;
    }
}

void BattleAnim_ClearOverlayFlag(Battler* arg0) {
    D_84390010[0]->unk_000.node.renderFlags &= ~2;
    D_84390010[1]->unk_000.node.renderFlags &= ~2;
}

s32 BattleAnim_IsAssetLoadBusy(Battler* arg0) {
    return arg0->unk_720->unk_1D & 0xD0;
}

s32 BattleAnim_PollAssetLoadBusyFlags(Battler* arg0) {
    PokeIcon_PollBackgroundForObject(arg0->unk_720);
    return arg0->unk_720->unk_1D & 0xC0;
}

s32 BattleAnim_IsSessionBusy(Battler* arg0) {
    return arg0->unk_720->unk_00 & 0xD0;
}

s32 BattleAnim_TryRegisterAssetTables(Battler* arg0) {
    if (BattleAnim_PollAssetLoadBusyFlags(arg0) == 0) {
        BattleAnim_RegisterAssetTablesForSession(arg0->unk_720);
        return 1;
    }
    return 0;
}

void BattleScene_LoadMoveResourceList(Battler* arg0) {
    if (gBattleScene.unk_00->unk_48 == 0xE) {
        BattleAnim_LoadMoveResourceList(arg0->unk_720, BattleScene_GetActiveAnimRowId(arg0));
    } else {
        BattleAnim_LoadMoveResourceList(arg0->unk_720, BattleScene_GetActiveAnimRowId(arg0));
    }
}

void BattleScene_LoadRowResourceList(Battler* arg0) {
    s32 idx = arg0->unk_4C0;

    BattleAnim_LoadModeResourceList(arg0->unk_720, gBattleSceneStateRowTable[idx].unk_24);
}

void BattleScene_ReloadMoveResourceList(Battler* arg0) {
    BattleAnim_LoadMoveResourceList(arg0->unk_720, BattleScene_GetActiveAnimRowId(arg0));
}

void BattleAnim_BeginSessionRequest(Battler* arg0) {
    arg0->unk_720->unk_02 = 0x98;
    arg0->unk_720->unk_00 |= 0x80;
}

void BattleAnim_BeginSessionRequestForActiveMon(Battler* arg0) {
    arg0->unk_720->unk_04 = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    arg0->unk_720->unk_00 |= 0x80;
    arg0->unk_720->unk_02 = arg0->unk_654.unk_BC;
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

void Battle_FilterUnusableMoves(Battler* arg0, u16 arg1, SpeciesLearnsetBuffer* arg2, SpeciesLearnsetBuffer* arg3) {
    s32 i;
    s32 j;
    s32 temp_v0_3;
    s32 temp_v1_2;
    u8 var_a0;
    unk_D_80070F84* temp_s4; //TODO: this is definitely typed wrong
    BattleMonRuntime* temp_s5;

    temp_s5 = &arg0->unk_654.unk_38;

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

void Battle_InitializeMoveUsabilityMask(Battler* arg0) {
    arg0->unk_654.unk_C1[0] = 1;
    arg0->unk_654.unk_C1[1] = 1;
    arg0->unk_654.unk_C1[2] = 1;
    arg0->unk_654.unk_C1[3] = 1;

    Battle_FilterUnusableMoves(arg0, arg0->unk_654.unk_38.unk_0B - 1, &arg0->unk_94C, &arg0->unk_9AC);

    if (D_84384588[BattleScene_GetParticipantSideIndex(arg0)]->unk_00 != 0) {
        Battle_FilterUnusableMoves(arg0, D_84384588[BattleScene_GetParticipantSideIndex(arg0)]->unk_00 - 1, &arg0->unk_96C, &arg0->unk_9CC);
    }

    if (D_84384588[BattleScene_GetParticipantSideIndex(arg0)]->unk_01 != 0) {
        Battle_FilterUnusableMoves(arg0, D_84384588[BattleScene_GetParticipantSideIndex(arg0)]->unk_01 - 1, &arg0->unk_98C, &arg0->unk_9EC);
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

void func_84302658(Battler* arg0, s32 arg1) {
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

    ptr = &arg0->unk_720->unk_08[arg0->unk_654.unk_2C]->unk_01C[arg0->unk_654.unk_18];

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

void BattleScene_TickRow10CleanupAndEnterState18(Battler* arg0) {
    if (arg0->unk_4C4 == 0x14) {
        arg0->unk_720->unk_00 |= 0x80;
    }

    if (arg0->unk_720->unk_00 & 0x10) {
        arg0->unk_720->unk_00 &= ~0x90;
        Battle_LoadOwnerModelForSwitchIn(arg0);
        BattleScene_TickOwnerCameraFraming(arg0);
        Audio_PlayCommand(2, 0, 0);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        BattleScene_EnterStateRow(arg0, 0x12);
    }
}

void BattleScene_EnterRow3StartMoveAnim(Battler* arg0) {
    BattleMonRuntime* sp24;
    BattlerState* sp20;
    s32 idx;
    s16 sp2A;
    u8 tmp;

    sp2A = arg0->unk_000.objectType - 1;
    sp24 = &arg0->unk_654.unk_38;
    sp20 = &arg0->unk_654;
    idx = BattleScene_GetParticipantSideIndex(arg0);

    D_84390020 = &D_84384570[idx]->unk_000[sp24->unk_5A - 1];

    if (!(sp20->unk_34 & 2)) {
        arg0->unk_4C4 = 0;

        if (BattleScene_IsPartnerPikachu(arg0) != 0) {
            tmp = BattleScene_GetParticipantSideIndex(arg0);
            func_80048060(tmp, sp24->unk_5A, 0xC8, 0);
        } else {
            tmp = BattleScene_GetParticipantSideIndex(arg0);
            func_80048060(tmp, sp24->unk_5A, sp2A + 1, 0);
        }

        if ((sp20->unk_34 & 0x4000) && ((sp2A == 0x32) || (sp2A == 0x31))) {
            Battle_ClearRuntimeFlags(arg0, 8);
            arg0->unk_000.node.renderFlags |= 0x20;
            Battle_SetRuntimeFlags(arg0, 0x10);
            Battle_ClearRuntimeFlags(arg0, 0x4000);
        }

        BattleAnim_SetOverlayFlagForSpecialMoves(arg0);
        ModelAnim_SetAnimation(&arg0->unk_000, D_84390020->unk_00);
        BattleAnim_SetModelEventTrackFromRow(arg0, sp24->unk_5A - 1);

        if (D_84390020->unk_0B != 0) {
            ModelAnim_SetFrame(&arg0->unk_000, D_84390020->unk_0B);
            ModelAnim_SetEventFrame(&arg0->unk_000, D_84390020->unk_0B);
            arg0->unk_4C4 = D_84390020->unk_0B;
        } else {
            ModelAnim_SetFrame(&arg0->unk_000, 0);
        }
    }
}

void BattleScene_TickRow3PlayMoveEffectScript(Battler* arg0) {
    UNUSED s32 pad;
    s16 sp32 = arg0->unk_000.objectType - 1;
    BattleMonRuntime* sp24;

    BattleScene_GetParticipantSideIndex(arg0);
    sp24 = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp24->unk_5A - 1];

    if ((sp24->unk_5A == 0x19) && (sp32 == 0x64)) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    } else if ((arg0->unk_4C4 == (D_84390020->unk_04 + 1)) && (BattleAnim_IsAssetLoadBusy(arg0) == 0)) {
        if (gBattleScene.unk_00->unk_48 == 0x14) {
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        } else if (sp24->unk_44.unk_00 == 0x5B) {
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        } else {
            if (sp24->unk_44.unk_00 == 0x6E) {
                if ((sp32 != 7) && (sp32 != 8) && (sp32 != 0x5A) && (sp32 != 6)) {
                    BattleScene_SetParticipantModelFlags(arg0, 0xC, 0);
                    BattleAnim_PlayMoveEffectScriptA(arg0, sp24->unk_5A);
                }
            } else {
                if (sp24->unk_44.unk_00 == 0x45) {
                    BattleScene_SetParticipantModelFlags(arg0, 8, 0);
                } else if (sp24->unk_44.unk_00 == 0x39) {
                    BattleScene_SetParticipantModelFlags(arg0, 0xA, 0);
                } else if (sp24->unk_44.unk_00 == 0x60) {
                    BattleScene_SetParticipantModelFlags(arg0, 0xD, 0);
                } else if (sp24->unk_44.unk_00 == 0x7F) {
                    BattleScene_SetParticipantModelFlags(arg0, 0xE, 0);
                } else if (sp24->unk_44.unk_00 == 0x6B) {
                    BattleScene_SetParticipantModelFlags(arg0, 9, 0);
                } else {
                    BattleScene_SetParticipantModelFlags(arg0, D_84390020->unk_05, 0);
                }

                if ((sp24->unk_5A == 0x9A) && (D_84390230 == D_8439022C)) {
                    BattleAnim_PlayMoveEffectScriptB(arg0, sp24->unk_5A);
                } else {
                    BattleAnim_PlayMoveEffectScriptA(arg0, sp24->unk_5A);
                }
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow3PostEffectCamera(Battler* arg0) {
    BattleMonRuntime* sp24 = &arg0->unk_654.unk_38;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp24->unk_5A - 1];

    if (arg0->unk_4C4 == (D_84390020->unk_04 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(arg0) == 0) {
            if (gBattleScene.unk_00->unk_48 == 0x18) {
                D_84390234--;
                if (D_84390234 < 0) {
                    if (gBattleMoveFailed != 0) {
                        BattleAnim_PlaySpeciesReactionSound(arg0, sp24, 2);
                    }
                } else {
                    BattleAnim_PlaySpeciesReactionSound(arg0, sp24, 3);
                }
            } else if (gBattleMoveFailed != 0) {
                BattleAnim_PlaySpeciesReactionSound(arg0, sp24, 2);
            } else {
                if ((sp24->unk_5A == 0x2D) || (sp24->unk_5A == 0x2E) || (sp24->unk_5A == 0x59)) {
                    BattleScene_StartCameraShake(arg0);
                }
                BattleAnim_PlaySpeciesReactionSound(arg0, sp24, 0);
                func_843031A0(arg0);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow3QueueEffectList6(Battler* arg0) {
    BattleMonRuntime* sp24 = &arg0->unk_654.unk_38;
    UNUSED s16 pad;
    s16 sp18;

    sp18 = sp24->unk_5A;
    BattleScene_GetParticipantSideIndex(arg0);
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp24->unk_5A - 1];

    if (arg0->unk_4C4 == (D_84390020->unk_09 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(arg0) == 0) {
            if (((sp18 == 0x4A) || (sp18 == 0x60) || (sp18 == 0x61) || (sp18 == 0x6A) || (sp18 == 0x6E) ||
                 (sp18 == 0xE) || (sp18 == 0x68) || (sp18 == 0x6B) || (sp18 == 0x6F) || (sp18 == 0x70) ||
                 (sp18 == 0x85) || (sp18 == 0x97) || (sp18 == 0x9F)) &&
                (D_843C4E45 == 1)) {
                BattleAnim_QueueEffectList6(3, arg0);
                Audio_PlayCommand(0x23, 0, 0);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void func_843031A0(Battler* arg0) {
    BattleMonRuntime* temp_v1 = &arg0->unk_654.unk_38;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[temp_v1->unk_5A - 1];

    if (temp_v1->unk_5A == 0x6A) {
        Model_SetMaterialTextureMode(&arg0->unk_000, 1);
    }
}

void BattleScene_EnterRow21StartAnimRecord0(Battler* arg0) {
    UNUSED s32 pad[2];
    BattlerState* temp_v1 = &arg0->unk_654;
    s16 sp22;

    sp22 = arg0->unk_000.objectType - 1;
    D_84390020 = D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000;

    if (!(temp_v1->unk_34 & 2)) {
        arg0->unk_4C4 = 0;
        if ((temp_v1->unk_34 & 0x4000) && ((sp22 == 0x32) || (sp22 == 0x31))) {
            Battle_ClearRuntimeFlags(arg0, 8);
            arg0->unk_000.node.renderFlags |= 0x20;
            Battle_SetRuntimeFlags(arg0, 0x10);
            Battle_ClearRuntimeFlags(arg0, 0x4000);
        }
        ModelAnim_SetAnimation(&arg0->unk_000, D_84390020->unk_00);
        ModelAnim_SetFrame(&arg0->unk_000, 0);
        BattleAnim_SetModelEventTrackFromRow(arg0, 4);

        if (D_84390020->unk_0B != 0) {
            ModelAnim_SetFrame(&arg0->unk_000, D_84390020->unk_0B);
            ModelAnim_SetEventFrame(&arg0->unk_000, D_84390020->unk_0B);
            arg0->unk_4C4 = D_84390020->unk_0B;
        } else {
            ModelAnim_SetFrame(&arg0->unk_000, 0);
        }
    }
}

void BattleScene_TickRow21PlaySpeciesSound(Battler* arg0) {
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[0];
    if ((arg0->unk_4C4 == (D_84390020->unk_04 + 1)) && (BattleAnim_IsAssetLoadBusy(arg0) == 0)) {
        func_800479C0(1, arg0->unk_000.objectType, 0);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_EnterRow19StartMoveAnimMidFrame(Battler* arg0) {
    BattlerState* sp20;
    BattleMonRuntime* ptr;

    sp20 = &arg0->unk_654;
    ptr = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[ptr->unk_5A - 1];

    if (sp20->unk_34 & 2) {
        return;
    }

    arg0->unk_4C4 = D_84390020->unk_06;
    if (!(sp20->unk_34 & 0x4000)) {
        BattleAnim_SetOverlayFlagForSpecialMoves(arg0);
        ModelAnim_SetAnimation(&arg0->unk_000, D_84390020->unk_00);
        ModelAnim_SetFrame(&arg0->unk_000, D_84390020->unk_06);
        if (D_84390020->unk_01 != 0xFF) {
            ModelAnim_SetEventTrack(&arg0->unk_000, D_84390020->unk_01);
            ModelAnim_SetEventFrame(&arg0->unk_000, D_84390020->unk_06);
            sp20->unk_36 = 1;
        }
    }
}

void BattleScene_TickRow19PlayMoveEffectScript(Battler* arg0) {
    BattleMonRuntime* sp20;
    s32 var_v0;

    sp20 = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp20->unk_5A - 1];
    if (sp20->unk_5A == 0x9A) {
        var_v0 = D_84390020->unk_04 + 0x1E;
    } else {
        var_v0 = D_84390020->unk_04 + 1;
    }

    if ((var_v0 == arg0->unk_4C4) && (BattleAnim_IsAssetLoadBusy(arg0) == 0)) {
        if (gBattleScene.unk_00->unk_48 == 0x14) {
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
            return;
        }

        if ((sp20->unk_5A == 0x9A) && (D_84390230 == D_8439022C)) {
            BattleAnim_PlayMoveEffectScriptB(arg0, sp20->unk_5A);
        } else {
            BattleAnim_PlayMoveEffectScriptA(arg0, sp20->unk_5A);
        }

        if (sp20->unk_44.unk_00 == 0x45) {
            BattleScene_SetParticipantModelFlags(arg0, 8, 0);
        } else if (sp20->unk_44.unk_00 == 0x39) {
            BattleScene_SetParticipantModelFlags(arg0, 0xA, 0);
        } else {
            BattleScene_SetParticipantModelFlags(arg0, D_84390020->unk_05, 0);
        }
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickRow19PostEffectCamera(Battler* arg0) {
    BattleMonRuntime* sp18;
    s32 var_v0;

    sp18 = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp18->unk_5A - 1];

    if (sp18->unk_5A == 0x9A) {
        var_v0 = D_84390020->unk_04 + 0x1E;
    } else {
        var_v0 = D_84390020->unk_04 + 1;
    }

    if (var_v0 == arg0->unk_4C4) {
        if (BattleAnim_IsAssetLoadBusy(arg0) == 0) {
            if (gBattleScene.unk_00->unk_48 == 0x18) {
                D_84390234--;
                if (D_84390234 < 0) {
                    if (gBattleMoveFailed != 0) {
                        BattleAnim_PlaySpeciesReactionSound(arg0, sp18, 2);
                    } else {
                        BattleAnim_PlaySpeciesReactionSound(arg0, sp18, 0);
                    }
                } else {
                    BattleAnim_PlaySpeciesReactionSound(arg0, sp18, 3);
                }
            } else if (gBattleMoveFailed != 0) {
                BattleAnim_PlaySpeciesReactionSound(arg0, sp18, 2);
            } else {
                BattleAnim_PlaySpeciesReactionSound(arg0, sp18, 0);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_EnterRow4StartHitReactionAnim(Battler* arg0) {
    UNUSED s32 pad[3];
    s32 sp40;
    BattlerState* sp3C;
    UNUSED s32 pad2;
    s32 temp_v0;
    BattleMonRuntime* sp28;
    Battler* temp_a1;

    sp28 = &arg0->unk_654.unk_38;
    sp40 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    sp3C = &D_84390010[sp40]->unk_654;
    temp_a1 = D_84390010[sp40];
    D_84390020 = &D_84384570[sp40]->unk_A80;

    if (sp3C->unk_34 & 1) {
        temp_v0 = BattleScene_ByteArrayContains(temp_a1->unk_000.objectType, D_84384598, 2);
        if (temp_v0 != 0) {
            D_84390020 = &D_84384570[sp40]->unk_B20;
        }
    }

    D_84390010[sp40]->unk_4C4 = 0;

    if (!(sp3C->unk_34 & 0x200) && !(sp3C->unk_34 & 0x4000) && !(sp3C->unk_34 & 2)) {
        if (((D_843C4DEC < 0xA) || (gBattleMoveFailed != 0)) && ((sp28->unk_15 & 0x20) == 0)) {
            D_84390020 = &D_84384570[sp40]->unk_A50;
            if (sp3C->unk_34 & 0x200) {
                D_84390020 = &D_84384570[sp40]->unk_B00;
            }
        } else if (!(sp3C->unk_34 & 1)) {
            BattleAnim_SetModelEventTrackAndState(D_84390010[sp40], 0xA8, 1);
        }

        if ((D_843C4DEC >= 0xB) && (BattleScene_IsPartnerPikachu(D_84390010[sp40]) != 0)) {
            Cry_Play(0xC8, 6);
        }

        if ((D_843C4DEC == 0xA) && (BattleScene_IsPartnerPikachu(D_84390010[sp40]) != 0)) {
            Cry_Play(0xC8, 5);
        }

        if ((gBattleMoveFailed == 0) && (sp28->unk_5A == 0x49)) {
            D_84390020 = &D_84384570[sp40]->unk_A80;
        }

        ModelAnim_SetFrame(&D_84390010[sp40]->unk_000, 0);
        ModelAnim_SetAnimation(&D_84390010[sp40]->unk_000, D_84390020->unk_00);

        if ((sp28->unk_44.unk_00 == 0x17) || (sp28->unk_44.unk_00 == 0x22) || (sp28->unk_44.unk_00 == 0x45)) {
            BattleScene_SetParticipantModelFlags(D_84390010[sp40], 0xF, 0);
        }
    }
}

void BattleScene_TickPlayMoveEffectEnd(Battler* arg0) {
    BattleMonRuntime* sp20;
    s32 sp28;

    sp20 = &arg0->unk_654.unk_38;
    sp28 = BattleScene_GetParticipantSideIndex(arg0);

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_000[sp20->unk_5A - 1];

    if (D_84390010[sp28 == 0]->unk_4C4 == (D_84390020->unk_07 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(arg0) == 0) {
            BattleAnim_CleanupEffects(1);
            if (sp20->unk_44.unk_00 == 0x51) {
                if ((D_843C4E45 != 0) && (D_843C4E44 != 0)) {
                    BattleAnim_PlayMoveEffectEnd(D_84390010[sp28 == 0], sp20->unk_5A);
                    BattleScene_SetParticipantModelFlags(D_84390010[sp28 == 0], 0x10, 0);
                }
            } else {
                BattleAnim_PlayMoveEffectEnd(D_84390010[sp28 == 0], sp20->unk_5A);
                if ((sp20->unk_44.unk_00 == 0x14) || (sp20->unk_44.unk_00 == 0x23) || (sp20->unk_44.unk_00 == 0x84)) {
                    BattleScene_SetParticipantModelFlags(D_84390010[sp28 == 0], 0x10, 0);
                }
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow4PostEndCamera(Battler* arg0) {
    BattleMonRuntime* sp20;
    s32 sp28;

    sp28 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    sp20 = &arg0->unk_654.unk_38;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_000[sp20->unk_5A - 1];

    if ((D_84390020->unk_07 + 1) == D_84390010[sp28]->unk_4C4) {
        if (BattleAnim_IsAssetLoadBusy(arg0) == 0) {
            if (D_843C4E44 == 1) {
                BattleAnim_PlaySpeciesReactionSound(D_84390010[sp28], sp20, 1);
            } else {
                BattleAnim_PlaySpeciesReactionSound(D_84390010[sp28], sp20, 5);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_EnterRow15StartAnimA80Seq30(Battler* arg0) {
    s32 sp1C = BattleScene_GetParticipantSideIndex(arg0);

    D_84390020 = &D_84384570[sp1C]->unk_A80;
    D_84390010[sp1C]->unk_4C4 = 0;
    ModelAnim_SetFrame(&arg0->unk_000, 0);
    ModelAnim_SetAnimation(&arg0->unk_000, D_84390020->unk_00);
    BattleAnim_SetModelEventTrackAndState(D_84390010[sp1C], 0xA8, 1);
    BattleAnim_PlayBattleSequenceById(arg0, 0x1E);
}

s32 BattleScene_IsOpponentRowCheckpointReached(Battler* arg0) {
    BattleMonRuntime* sp1C;

    sp1C = &D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_654.unk_38;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp1C->unk_5A - 1];
    if (D_84390020->unk_0C != 0) {
        if (arg0->unk_4C4 == D_84390020->unk_0C) {
            return 1;
        }
        return 0;
    }
    return 0;
}

s32 BattleScene_IsRowZeroCheckpointReached(Battler* arg0) {
    BattleScene_GetParticipantSideIndex(arg0);
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[0];
    if (D_84390020->unk_0C != 0) {
        if (arg0->unk_4C4 == D_84390020->unk_0C) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void func_84303E58(Battler* arg0) {
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_A80;
    BattleAnim_SetModelEventTrackFromRow(arg0, 0xA8);
    arg0->unk_4C4 = 0;
    ModelAnim_SetFrame(&arg0->unk_000, 0);
    ModelAnim_SetAnimation(&arg0->unk_000, D_84390020->unk_00);
}

void BattleScene_EnterRowAnim166WithCry(Battler* arg0) {
    s32 idx = arg0->unk_4C0;
    s32 temp_a0;
    s32 sp34;
    BattleMon* sp30;
    BattlerState* sp24;

    sp34 = gBattleSceneStateRowTable[idx].unk_20;
    sp30 = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    sp24 = &arg0->unk_654;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp34];
    temp_a0 = sp24->unk_34 & 2;

    if ((temp_a0 == 0) && !(sp24->unk_34 & 0x4000) && (temp_a0 == 0)) {
        if (sp30->unk_05 & 7) {
            if (BattleScene_ByteArrayContains(arg0->unk_000.objectType, D_84384590, 8) != 0) {
                D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unkA90[0x60];
            } else {
                D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_A50;
            }
        } else if (sp24->unk_34 & 0x200) {
            D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_B00;
        }

        ModelAnim_SetFrame(&arg0->unk_000, 0);
        ModelAnim_SetAnimation(&arg0->unk_000, D_84390020->unk_00);

        if (sp24->unk_34 & 0x200) {
            if (BattleScene_IsPartnerPikachu(arg0) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, 0xC8, 0x1A);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, arg0->unk_000.objectType, 0x1A);
            }
        } else if (BattleScene_IsPartnerPikachu(arg0) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, 0xC8, 0xA);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, arg0->unk_000.objectType, 0xA);
        }
    }
}

void BattleScene_TickRow1PlayOwnerCry(Battler* arg0) {
    UNUSED s32 pad;
    BattlerState* sp18 = &arg0->unk_654;
    BattleMon* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    if ((sp18->unk_34 & 0x4000) || (sp18->unk_34 & 2) || (ptr->unk_05 & 7)) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    } else if (arg0->unk_4C4 == 1) {
        if (BattleAnim_IsAssetLoadBusy(arg0) == 0) {
            if (arg0->unk_000.objectType >= 0x98) {
                BattleAnim_PlayOwnerCry(arg0, sp18->unk_BC);
            } else {
                BattleAnim_PlayOwnerCry(arg0, arg0->unk_000.objectType);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow16PlayCryAndSpeciesSound(Battler* arg0) {
    UNUSED s32 pad;
    BattleMon* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    BattlerState* sp24 = &arg0->unk_654;

    if ((arg0->unk_654.unk_34 & 0x4000) || (sp24->unk_34 & 2) || (ptr->unk_05 & 7)) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    } else if ((arg0->unk_4C4 == 1) && (BattleAnim_IsAssetLoadBusy(arg0) == 0)) {
        if (arg0->unk_000.objectType >= 0x98) {
            Cry_Play(sp24->unk_BC, 3);
        } else if (BattleScene_IsPartnerPikachu(arg0) != 0) {
            Cry_Play(0xC8, 3);
        } else {
            Cry_Play(arg0->unk_000.objectType, 3);
        }

        if (sp24->unk_34 & 0x200) {
            if (BattleScene_IsPartnerPikachu(arg0) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, 0xC8, 0x1B);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, arg0->unk_000.objectType, 0x1B);
            }
        } else if (BattleScene_IsPartnerPikachu(arg0) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, 0xC8, 0xB);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, arg0->unk_000.objectType, 0xB);
        }
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickRow18PlayCryAndSpeciesSound(Battler* arg0) {
    UNUSED s32 pad;
    BattleMon* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    BattlerState* sp24;

    if ((arg0->unk_654.unk_34 & 0x4000) || (ptr->unk_05 & 0x20) || (ptr->unk_05 & 7)) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        return;
    }

    if ((arg0->unk_4C4 == 1) && (BattleAnim_IsAssetLoadBusy(arg0) == 0)) {
        sp24 = &arg0->unk_654;
        if (arg0->unk_000.objectType >= 0x98) {
            Cry_Play(sp24->unk_BC, 4);
        } else if (BattleScene_IsPartnerPikachu(arg0) != 0) {
            Cry_Play(0xC8, 4);
        } else {
            Cry_Play(arg0->unk_000.objectType, 4);
        }

        if (sp24->unk_34 & 0x200) {
            if (BattleScene_IsPartnerPikachu(arg0) != 0) {
                func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, 0xC8, 0x1B);
            } else {
                func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, arg0->unk_000.objectType, 0x1B);
            }
        } else if (BattleScene_IsPartnerPikachu(arg0) != 0) {
            func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, 0xC8, 0xB);
        } else {
            func_80048060(BattleScene_GetParticipantSideIndex(arg0) & 0xFF, 0, arg0->unk_000.objectType, 0xB);
        }

        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickAssetLoadQueueRowEffectList3(Battler* arg0) {
    UNUSED s32 pad[2];
    s32 sp24 = arg0->unk_4C0;
    BattlerState* temp_v1 = &arg0->unk_654;

    if (BattleAnim_TryRegisterAssetTables(arg0) != 0) {
        arg0->unk_720->unk_02 = arg0->unk_654.unk_38.unk_0B;
        arg0->unk_4C4 = 0;
        BattleScene_QueueRowEffectList3(arg0, gBattleSceneStateRowTable[sp24].unk_24);
        Audio_PlayCommand(3, 0, 0);
        arg0->unk_720->unk_04 = &arg0->unk_720->unk_08[temp_v1->unk_2B]->unk_01C[temp_v1->unk_18];
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void func_843046BC(Battler* arg0) {
    BattleScene_GetParticipantSideIndex(arg0);
    if ((arg0->unk_4C4 == 1) && (BattleAnim_IsAssetLoadBusy(arg0) == 0)) {
        s32 idx = arg0->unk_4C0;

        BattleScene_QueueRowEffectList3(arg0, gBattleSceneStateRowTable[idx].unk_24);
        Audio_PlayCommand(3, 0, 0);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickRow20CleanupAndEnterState18(Battler* arg0) {
    if (arg0->unk_4C4 == 0x4F) {
        arg0->unk_720->unk_00 |= 0x80;
    }

    if (arg0->unk_720->unk_00 & 0x10) {
        arg0->unk_720->unk_00 &= ~0x90;

        Battle_LoadOwnerModelForSwitchIn(arg0);
        BattleScene_TickOwnerCameraFraming(arg0);
        Audio_PlayCommand(2, 0, 0);

        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;

        BattleScene_EnterStateRow(arg0, 0x12);
    }
}

void func_84304800(Battler* arg0) {
    if (arg0->unk_720->unk_00 & 0x10) {
        arg0->unk_720->unk_00 &= ~0x90;
        Battle_ResetOwnerModelToNeutralPlaceholder(arg0);
    }
}

void BattleScene_EnterRow8StartMappedMoveAnim(Battler* arg0) {
    UNUSED s32 pad[2];
    s32 sp24 = D_84384670[arg0->unk_654.unk_38.unk_5A - 1];

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp24];
    arg0->unk_4C4 = 0;
    ModelAnim_SetFrame(&arg0->unk_000, 0);
    ModelAnim_SetAnimation(&arg0->unk_000, D_84390020->unk_00);
    BattleAnim_SetModelEventTrackFromRow(arg0, sp24);
}

void BattleScene_TickRow8PlayMoveEffectScriptB(Battler* arg0) {
    BattleMonRuntime* temp_s1_2;
    s16 sp22;
    s16 temp_s1;

    sp22 = arg0->unk_000.objectType - 1;
    temp_s1_2 = &arg0->unk_654.unk_38;
    temp_s1 = D_84384670[temp_s1_2->unk_5A - 1];

    BattleScene_GetParticipantSideIndex(arg0);

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[temp_s1];

    if ((arg0->unk_4C4 == (D_84390020->unk_04 + 1)) && (BattleAnim_IsAssetLoadBusy(arg0) == 0)) {
        BattleAnim_PlayMoveEffectScriptB(arg0, temp_s1_2->unk_5A);

        if (temp_s1_2->unk_5A == 0x13) {
            BattleScene_SetParticipantModelFlags(arg0, 3, 0);
        }

        if ((temp_s1_2->unk_5A == 0x5B) && (sp22 != 0x31) && (sp22 != 0x32)) {
            BattleScene_SetParticipantModelFlags(arg0, 5, 0);
            BattleAnim_QueueEffectList(4, arg0);
        }

        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;

        BattleAnim_PlaySpeciesReactionSound(arg0, temp_s1_2, 4);
    }
}

void BattleScene_EnterRow9SetEventTrack(Battler* arg0) {
    UNUSED s32 pad[3];
    BattleMon* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    s32 sp1C;

    arg0->unk_4C4 = 0;
    if (!(arg0->unk_654.unk_34 & 2)) {
        if (ptr->unk_05 & 7) {
            if (BattleScene_ByteArrayContains(arg0->unk_000.objectType, D_84384590, 8) != 0) {
                sp1C = 0xAF;
            } else {
                sp1C = 0xA5;
            }
        } else {
            sp1C = 0xA5;
        }
        D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp1C];
        BattleAnim_SetModelEventTrackFromRow(arg0, sp1C);
    }
}

void BattleScene_EnterRow9QueueEffectList6(Battler* arg0) {
    BattleMonRuntime* ptr = &D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_654.unk_38;

    if (ptr->unk_4C & 0x20) {
        if ((ptr->unk_5A == 0x14) || (ptr->unk_5A == 0x23) || (ptr->unk_5A == 0x51)) {
            BattleAnim_QueueEffectList6(2, arg0);
            BattleScene_SetParticipantModelFlags(arg0, 0x10, 0);
        }
    }
}

void BattleScene_Row12Slot1CameraCleanup(Battler* arg0) {
    BattleMonRuntime* sp20;
    s32 sp28;

    sp28 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    sp20 = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_000[sp20->unk_5A - 1];

    if ((D_84390020->unk_07 + 1) == D_84390010[sp28]->unk_4C4) {
        if (BattleAnim_IsAssetLoadBusy(arg0) == 0) {
            BattleAnim_PlaySpeciesReactionSound(arg0, sp20, 5);
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_Row13PlaySequences14And21(Battler* arg0) {
    BattleMonRuntime* sp20 = &arg0->unk_654.unk_38;

    if (sp20->unk_15 & 8) {
        BattleAnim_PlayBattleSequenceById(arg0, 0x14);
    }

    if (sp20->unk_15 & 0x10) {
        BattleAnim_PlayBattleSequenceById(arg0, 0x21);
    }

    gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
}

void BattleScene_TickPlaySpeciesSequence33(Battler* arg0) {
    UNUSED s32 pad;
    u16 sp22 = arg0->unk_000.objectType;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_A70;
    if ((BattleScene_GetParticipantModelHeight(arg0) != 0.0f) && (sp22 != 0x16) && (sp22 != 0x52) && (sp22 != 0x8E)) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    } else if ((arg0->unk_4C4 == (D_84390020->unk_04 + 1)) && (BattleAnim_IsAssetLoadBusy(arg0) == 0)) {
        BattleAnim_PlaySpeciesSequence33(arg0);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void BattleScene_TickQueueList3Selector2OrC(Battler* arg0) {
    s32 sp24;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_A70;
    if (D_84390020->unk_09 == 1) {
        sp24 = D_84390020->unk_0A - 0x4C;
    } else {
        sp24 = D_84390020->unk_0A - 0x31;
    }

    if (BattleAnim_IsAssetLoadBusy(arg0) == 0) {
        if (BattleScene_GetParticipantModelHeight(arg0) != 0.0f) {
            if ((sp24 <= 0) || (sp24 == arg0->unk_4C4)) {
                if (D_84390020->unk_09 == 1) {
                    BattleAnim_QueueEffectList3(2, arg0, arg0, 0xFF, 0xFF);
                } else {
                    BattleAnim_QueueEffectList3(0xC, arg0, arg0, 0xFF, 0xFF);
                }
                Audio_PlayCommand(3, 0, 0);
                gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
            }
        } else if ((sp24 <= 0) || (sp24 == arg0->unk_4C4)) {
            if (D_84390020->unk_09 == 1) {
                BattleAnim_QueueEffectList3(2, arg0, arg0, 0xFF, 0xFF);
            } else {
                BattleAnim_QueueEffectList3(0xC, arg0, arg0, 0xFF, 0xFF);
            }
            Audio_PlayCommand(3, 0, 0);
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickQueueList3Selector2OrCFromB10(Battler* arg0) {
    s32 sp24;

    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_B10;
    if (D_84390020->unk_09 == 1) {
        sp24 = D_84390020->unk_0A - 0x4C;
    } else {
        sp24 = D_84390020->unk_0A - 0x31;
    }

    if ((BattleAnim_IsAssetLoadBusy(arg0) == 0) && ((sp24 <= 0) || (sp24 == arg0->unk_4C4))) {
        if (D_84390020->unk_09 == 1) {
            BattleAnim_QueueEffectList3(2, arg0, arg0, 0xFF, 0xFF);
        } else {
            BattleAnim_QueueEffectList3(0xC, arg0, arg0, 0xFF, 0xFF);
        }
        Audio_PlayCommand(3, 0, 0);
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

void func_8430506C(Battler* arg0) {
    s32 pad3;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    BattlerState* sp3C;
    s32 pad[2];
    Battler* sp30;
    BattleMonRuntime* sp28;

    sp48 = 0xA5;
    sp40 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    sp3C = &D_84390010[sp40]->unk_654;
    sp30 = D_84390010[sp40];
    sp28 = &arg0->unk_654.unk_38;

    D_84390020 = &D_84384570[sp40]->unk_A80;

    if (sp3C->unk_34 & 1) {
        if (BattleScene_ByteArrayContains(sp30->unk_000.objectType, D_84384598, 2) != 0) {
            D_84390020 = &D_84384570[sp40]->unk_B20;
        }
    }

    if ((sp3C->unk_34 & 1) && BattleScene_ByteArrayContains(sp30->unk_000.objectType, D_84384590, 8)) {
        sp48 = 0xAF;
    }

    D_84390010[sp40]->unk_4C4 = 0;

    if (!(sp3C->unk_34 & 0x4000) && !(sp3C->unk_34 & 2)) {
        if ((sp28->unk_5A == 0x91) && (D_843C4DEC < 0xA)) {
            D_84390020 = &D_84384570[sp40]->unk_000[sp48];
        }

        if ((D_843C4E44 == 0) || (gBattleMoveFailed != 0)) {
            sp44 = 0xB0;
            D_84390020 = &D_84384570[sp40]->unk_000[sp48];
            if (sp3C->unk_34 & 0x200) {
                D_84390020 = &D_84384570[sp40]->unk_000[sp44];
            }
        } else if (!(sp3C->unk_34 & 1)) {
            BattleAnim_SetModelEventTrackFromRow(D_84390010[sp40], 0xA8);
        }

        ModelAnim_SetFrame(&D_84390010[sp40]->unk_000, 0);
        ModelAnim_SetAnimation(&D_84390010[sp40]->unk_000, D_84390020->unk_00);

        if ((sp28->unk_44.unk_00 == 0x17) || (sp28->unk_44.unk_00 == 0x22) || (sp28->unk_44.unk_00 == 0x45)) {
            BattleScene_SetParticipantModelFlags(D_84390010[sp40], 0xF, 0);
        }
    }
}

void BattleScene_TickRow14PlayMoveEffectEnd(Battler* arg0) {
    s32 sp2C;
    UNUSED s32 pad;
    BattleMonRuntime* sp24;
    BattleMonRuntime* sp1C;

    sp2C = BattleScene_GetParticipantSideIndex(arg0);
    sp24 = &D_84390010[sp2C == 0]->unk_654.unk_38;
    sp1C = &arg0->unk_654.unk_38;

    D_84390020 = &D_84384570[sp2C == 0]->unk_000[sp1C->unk_5A - 1];

    if ((D_84390010[sp2C == 0]->unk_4C4 == (D_84390020->unk_07 + 1)) && (BattleAnim_IsAssetLoadBusy(arg0) == 0)) {
        BattleAnim_CleanupEffects(1);
        if (((sp1C->unk_5A == 0x30) || (sp1C->unk_5A == 0x6D)) && (sp24->unk_4C & 0x80) && (gBattleMoveFailed == 0) &&
            (D_843C4E44 == 1)) {
            BattleAnim_PlayBattleSequenceById(D_84390010[sp2C == 0], 0x12);
        }

        BattleAnim_PlayMoveEffectEnd(D_84390010[sp2C == 0], sp1C->unk_5A);
        if ((gBattleMoveFailed == 0) || (D_843C4E44 == 1)) {
            BattleAnim_PlaySpeciesReactionSound(D_84390010[sp2C == 0], &arg0->unk_654.unk_38, 1);
        }

        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
    }
}

s32 func_84305458(Battler* arg0) {
    BattleMonRuntime* ptr = &arg0->unk_654.unk_38;
    s32 temp_v1;

    temp_v1 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    D_84390020 = &D_84384570[temp_v1]->unk_000[ptr->unk_5A - 1];

    if (D_843C4E45 != 1) {
        return 2;
    }

    if ((D_84390020->unk_08 + 0x50) == D_84390010[temp_v1]->unk_4C4) {
        return 1;
    }

    return 0;
}

void BattleScene_TickRow11QueueEffectList6(Battler* arg0) {
    BattleMonRuntime* ptr = &arg0->unk_654.unk_38;
    s32 sp28;

    sp28 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_000[ptr->unk_5A - 1];
    if (D_84390010[sp28]->unk_4C4 == (D_84390020->unk_08 + 1)) {
        if (BattleAnim_IsAssetLoadBusy(arg0) == 0) {
            if (D_843C4E45 == 1) {
                BattleAnim_QueueEffectList6(1, D_84390010[sp28]);
                BattleAnim_PlayBattleSequenceById(arg0, 0x20);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_TickRow11PostEndCamera(Battler* arg0) {
    BattleMonRuntime* sp20;
    s32 sp28;

    sp28 = BattleScene_GetParticipantSideIndex(arg0) == 0;
    sp20 = &arg0->unk_654.unk_38;
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_000[sp20->unk_5A - 1];

    if ((D_84390020->unk_07 + 1) == D_84390010[sp28]->unk_4C4) {
        if (BattleAnim_IsAssetLoadBusy(arg0) == 0) {
            if (D_843C4E44 == 1) {
                BattleAnim_PlaySpeciesReactionSound(D_84390010[sp28], sp20, 1);
            } else {
                BattleAnim_PlaySpeciesReactionSound(D_84390010[sp28], sp20, 5);
            }
            gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04 = gBattleSceneStateTickSentinel;
        }
    }
}

void BattleScene_StateCallbackNop(Battler* arg0) {
}

void BattleScene_RegisterStateTickCallback(Battler* arg0, BattleSceneStateCallback arg1) {
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

void BattleScene_SetOpponentEventTrackA6(Battler* arg0) {
    BattleAnim_SetModelEventTrackFromRow(D_84390010[BattleScene_GetParticipantSideIndex(arg0)], 0xA6);
}

void BattleScene_EnterStateRow(Battler* arg0, s32 arg1) {
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
    D_84390010[0]->unk_4C4++;
    D_84390010[1]->unk_4C4++;

    for (gBattleSceneStateTickSlotIndex = 0; gBattleSceneStateTickSlotIndex < 7; gBattleSceneStateTickSlotIndex++) {
        gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_04(gBattleSceneStateTickSlots[gBattleSceneStateTickSlotIndex].unk_00);
    }
}

void Battle_ResetCryEventIfStruggle(Battler* arg0) {
    if (arg0->unk_654.unk_38.unk_5A == 0x6A) {
        arg0->unk_000.textureMode = 0;
    }
}

void BattleAnim_SetModelEventTrackFromRow(Battler* arg0, s32 arg1) {
    s32 temp_v0;
    s32 sp30;
    BattlerState* sp24 = &arg0->unk_654;

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

s32 BattleAnim_TrySetModelEventTrackFromRow(Battler* arg0, s32 arg1, s32 arg2) {
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

void BattleAnim_SetModelEventTrackAndState(Battler* arg0, s32 arg1, s32 arg2) {
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

s32 BattleScene_IsParticipantIncapacitated(Battler* arg0) {
    BattlerState* sp20 = &arg0->unk_654;
    BattleMon* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    if ((sp20->unk_34 & 2) || (ptr->unk_05 & 7) || ((sp20->unk_34 & 0x200) && !(sp20->unk_34 & 0x400)) ||
        (sp20->unk_34 & 0x4000)) {
        return 1;
    }
    return 0;
}

s32 BattleScene_IsRowWaitComplete(Battler* arg0, s32 arg1) {
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

s32 BattleScene_IsRowWaitCompleteWithEventCount(Battler* arg0, s32 arg1) {
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

s32 Battle_IsRowAnimationSettled(Battler* arg0, s32 arg1) {
    BattleMonRuntime* ptr = &arg0->unk_654.unk_38;
    MovePresentationCue* sp20;
    MovePresentationCue* sp1C;

    if (arg0) {}

    sp20 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[ptr->unk_5A - 1];
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

s32 BattleScene_IsMoveKeyedRowWaitComplete(Battler* arg0, s32 arg1) {
    MovePresentationCue* temp_a2;
    BattleMon* sp28;
    UNUSED s32 pad;
    s32 sp20;
    MovePresentationCue* sp1C;

    sp28 = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];
    sp20 = D_84384670[arg0->unk_654.unk_38.unk_5A - 1];
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

s32 BattleScene_IsRowAnimWaitComplete(Battler* arg0, s32 arg1) {
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

void func_843060EC(Battler* arg0) {
    D_84390020 = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_A50;
    if (BattleAnim_IsSessionBusy(arg0) == 0) {
        if ((arg0->unk_000.transformAnim.animationId != -1) && (arg0->unk_000.node.flags & 1) &&
            (arg0->unk_000.node.renderFlags & 0x20) && (gBattleScene.unk_00->unk_1C == 1) &&
            (D_84390020->unk_00 == arg0->unk_000.transformAnim.animationId) &&
            (D_84390020->unk_04 == (arg0->unk_000.transformAnim.frameFixed >> 0x10)) && (D_84390020->unk_05 != 0) &&
            (BattleAnim_RandomRange(2) == 1)) {
            BattleAnim_QueueEffectList3(D_84390020->unk_05, &arg0->unk_000, &arg0->unk_000, D_84390020->unk_02, D_84390020->unk_02);
        }
    }
}

void Battle_SetRuntimeFlags(Battler* arg0, u16 arg1) {
    arg0->unk_654.unk_34 |= arg1;
}

s32 Battle_ClearRuntimeFlags(Battler* arg0, u16 arg1) {
    arg0->unk_654.unk_34 &= ~arg1;
}

void BattleScene_ResetParticipantAnimationFlags(Battler* arg0) {
    BattlerState* sp24 = &arg0->unk_654;

    if (arg0->unk_4C8 != 0) {
        if (sp24->unk_34 & 0x200) {
            arg0->unk_000.position.y = D_84390028[BattleScene_GetParticipantSideIndex(arg0)].unk_08;
            Battle_ClearRuntimeFlags(arg0, 0x608);
        }

        if (sp24->unk_34 & 0x4008) {
            arg0->unk_000.lodFraction = 0xFF;
            BattleAnim_StopOwnerCategoryParticles(4, arg0);
            arg0->unk_000.position.y = D_84390028[BattleScene_GetParticipantSideIndex(arg0)].unk_08;
            arg0->unk_000.node.renderFlags &= ~2;
            arg0->unk_000.node.renderFlags |= 0x20;
            arg0->unk_000.node.flags |= 1;
            Battle_ClearRuntimeFlags(arg0, 0x4608);
        }
    }
}

void BattleScene_ResetBothParticipantsAnimationState(void) {
    BattlerState* sp34;
    BattlerState* sp30;
    UNUSED s32 pad[2];
    Battler* sp24;
    Battler* sp20;

    sp34 = &D_84390010[0]->unk_654;
    sp30 = &D_84390010[1]->unk_654;
    sp24 = D_84390010[0];
    sp20 = D_84390010[1];

    if (sp34->unk_34 & 4) {
        D_84390010[0]->unk_000.position.y = 200.0f;
        Battle_SetRuntimeFlags(D_84390010[0], 0x200);
        Battle_ClearRuntimeFlags(D_84390010[0], 4);
    }

    if (sp30->unk_34 & 4) {
        D_84390010[1]->unk_000.position.y = 200.0f;
        Battle_SetRuntimeFlags(D_84390010[1], 0x200);
        Battle_ClearRuntimeFlags(D_84390010[1], 4);
    }

    if ((sp34->unk_34 & 0x4000) && (sp24->unk_000.objectType == 0x33)) {
        D_84390020 = &D_84384570[0]->unk_000[0x5A];
        ModelAnim_SetFrame(&D_84390010[0]->unk_000, 0);
        ModelAnim_SetAnimation(&D_84390010[0]->unk_000, D_84390020->unk_00);
    }

    if ((sp30->unk_34 & 0x4000) && (sp20->unk_000.objectType == 0x33)) {
        D_84390020 = &D_84384570[1]->unk_000[0x5A];
        ModelAnim_SetFrame(&D_84390010[1]->unk_000, 0);
        ModelAnim_SetAnimation(&D_84390010[1]->unk_000, D_84390020->unk_00);
    }

    BattleScene_ResetParticipantAnimationFlags(D_84390010[0]);
    BattleScene_ResetParticipantAnimationFlags(D_84390010[1]);
}

void Battle_ClearOpponentHopFlagAndSyncMove(Battler* arg0) {
    UNUSED s32 pad;
    BattlerState* sp20;

    sp20 = &D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_654;
    BattleScene_GetParticipantSideIndex(arg0);
    BattleScene_GetParticipantSideIndex(arg0);
    Battle_ResetCryEventIfStruggle(D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0]);

    if (sp20->unk_34 & 4) {
        D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0]->unk_000.position.y = 200.0f;
        Battle_SetRuntimeFlags(D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0], 0x200);
        Battle_ClearRuntimeFlags(D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0], 4);
    }

    if (arg0->unk_654.unk_34 & 0x200) {
        Battle_SetRuntimeFlags(arg0, 0x400);
    }
}

void BattleScene_CleanupParticipantHideFlag(Battler* arg0) {
    if (arg0->unk_654.unk_34 & 8) {
        arg0->unk_000.position.y = BattleScene_GetParticipantModelHeight(arg0);
        Battle_ClearRuntimeFlags(arg0, 0x608);
    }
}

void BattleScene_CleanupOpponentSpecialAnimFlag(Battler* arg0) {
    UNUSED s32 pad[2];
    Battler* sp1C = D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0];

    if (sp1C->unk_654.unk_34 & 0x4000) {
        sp1C->unk_000.node.renderFlags |= 0x20;
        sp1C->unk_000.node.flags |= 1;
        BattleAnim_StopOwnerCategoryParticles(4, sp1C);
        Battle_ClearRuntimeFlags(sp1C, 0x4000);
    }
}

void BattleScene_CleanupOpponentAnimationFlags(Battler* arg0) {
    Battler* temp_s0 = D_84390010[BattleScene_GetParticipantSideIndex(arg0) == 0];
    BattlerState* ptr = &temp_s0->unk_654;

    if (ptr->unk_34 & 0x4000) {
        temp_s0->unk_000.node.renderFlags |= 0x20;
        temp_s0->unk_000.node.flags |= 1;
        BattleAnim_StopOwnerCategoryParticles(4, temp_s0);
        Battle_ClearRuntimeFlags(temp_s0, 0x4000);
    }

    if (ptr->unk_34 & 8) {
        temp_s0->unk_000.position.y = BattleScene_GetParticipantModelHeight(arg0);
        Battle_ClearRuntimeFlags(temp_s0, 0x608);
    }
}

void BattleScene_CleanupParticipantEffectMode(Battler* arg0) {
    switch (arg0->unk_4B4) {
        case 14:
            BattleScene_SetParticipantModelFlags(arg0, 0, 0);
            BattleScene_PositionParticipantModel(arg0);
            break;

        case 13:
        case 15:
        case 16:
            BattleScene_SetParticipantModelFlags(arg0, 0, 0);
            if (arg0->unk_654.unk_38.unk_56 == 0) {
                Vec3f_SetComponentsDuplicate(&arg0->unk_000.scale, 1.0f, 1.0f, 1.0f);
            } else {
                Vec3f_SetComponentsDuplicate(&arg0->unk_000.scale, 0.8f, 0.8f, 0.8f);
            }
            break;

        case 12:
            BattleScene_SetParticipantModelFlags(arg0, 0, 0);
            if (arg0->unk_654.unk_38.unk_56 == 0) {
                Vec3f_SetComponentsDuplicate(&arg0->unk_000.scale, 1.0f, 1.0f, 1.0f);
            } else {
                Vec3f_SetComponentsDuplicate(&arg0->unk_000.scale, 0.8f, 0.8f, 0.8f);
            }
            break;

        case 10:
            BattleScene_SetParticipantModelFlags(arg0, 0, 0);
            arg0->unk_000.position.y = BattleScene_GetParticipantModelHeight(arg0);
            arg0->unk_000.rotation.x = 0;
            break;

        case 9:
            BattleScene_SetParticipantModelFlags(arg0, 0, 0);
            Vec3f_SetComponentsDuplicate(&arg0->unk_000.scale, 0.8f, 0.8f, 0.8f);
            BattleScene_HideParticipantSecondaryModels(arg0);
            break;

        case 7:
            BattleScene_SetParticipantModelFlags(arg0, 0, 0);
            BattleScene_HideParticipantSecondaryModels(arg0);
            break;

        case 6:
            BattleScene_SetParticipantModelFlags(arg0, 0, 0);
            BattleScene_HideParticipantSecondaryModels(arg0);
            BattleScene_PositionParticipantModel(arg0);
            Vec3s_SetComponents(&arg0->unk_000.rotation, 0, arg0->unk_4B0 << 0xE, 0);
            break;

        case 4:
            BattleScene_SetParticipantModelFlags(arg0, 0, 0);
            arg0->unk_000.rotation.y = arg0->unk_4B0 << 0xE;
            BattleScene_HideParticipantSecondaryModels(arg0);
            break;
    }
}

void BattleAnim_TickParticipantStatusAnimation(Battler* arg0) {
    BattlerState* temp_s1 = &arg0->unk_654;

    BattleAnim_StartFreezeStatusAnimation(arg0);
    BattleAnim_UpdateSleepStatusAnimation(arg0);

    if (temp_s1->unk_34 & 0x100) {
        arg0->unk_000.node.renderFlags &= 0xFFDF;
    }

    if ((temp_s1->unk_2D == 0x10) || (temp_s1->unk_2D == 0x13)) {
        Battle_ClearRuntimeFlags(arg0, 0x100);
    }

    temp_s1->unk_2E = Math_StepToS32(temp_s1->unk_2E, 0, 0x1E, 0x1E);
    if (temp_s1->unk_2E != 0) {
        Model_SetMaterialColor(&arg0->unk_000, 0xFF, 0xFF, 0xFF, temp_s1->unk_2E);
    }

    switch (temp_s1->unk_36) {
        case 2:
            break;

        case 0:
            if (BattleAnim_RandomRange(0x32) == 2) {
                BattleAnim_SetModelEventTrackFromRow(arg0, 0xA5);
            }
            break;

        case 1:
            if (ModelAnim_IsEventTrackNearEnd(&arg0->unk_000) == 1) {
                ModelAnim_SetEventTrack(&arg0->unk_000, -1);
                ModelAnim_SetEventFrame(&arg0->unk_000, 0);
                temp_s1->unk_36 = 0;
            }
            break;
    }

    if (temp_s1->unk_34 & 0x4000) {
        if ((arg0->unk_000.objectType != 0x32) && (arg0->unk_000.objectType != 0x33)) {
            arg0->unk_000.lodFraction = 0;
        }
    }
}

void BattleAnim_TriggerStatusAfflictionCry(Battler* arg0) {
    BattleMon* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    if ((ptr->unk_05 & 7) && !(arg0->unk_654.unk_34 & 1)) {
        BattleAnim_SetModelEventTrackAndState(arg0, 0xAF, 2);
        BattleAnim_QueueEffectList(3, arg0);
        BattleAnim_PlayBattleSequenceById(arg0, 0x32);
    }
}

void BattleScene_AllocateParticipantRecord(BattleSessionTeams* arg0, s32 arg1) {
    Battler* ptr = main_pool_alloc(sizeof(Battler), 0);

    D_84390010[arg1] = ptr;

    bzero(ptr, sizeof(Battler));
    bzero(&D_84390010[arg1]->unk_654, sizeof(BattlerState));
    bzero(&D_84390010[arg1]->unk_654.unk_38, sizeof(BattleMonRuntime));
    bzero(&D_84390010[arg1]->unk_728, sizeof(PresentationState));
    bzero(&D_84390010[arg1]->unk_654.unk_38.unk_44, sizeof(CachedMoveData));
    bzero(&D_84390010[arg1]->unk_654.unk_9C, sizeof(unk_D_84390010_654_09C));
    bzero(&D_84390010[arg1]->unk_654.unk_AC, sizeof(unk_D_84390010_654_0AC));
    bzero(&D_84390010[arg1]->unk_8C4, sizeof(MonCaptionState));
    D_84390010[arg1]->unk_720 = arg0;
}

void BattleScene_AllocateParticipants(BattleSessionTeams* arg0) {
    BattleScene_AllocateParticipantRecord(&arg0[0], 0);
    BattleScene_AllocateParticipantRecord(&arg0[1], 1);
    Battle_InitMessageQueues();
    D_84390018 = D_84390010[0];
    D_8439001C = D_84390010[1];
}

void BattleScene_InitializeParticipantController(Battler* arg0) {
    Controller* sp24 = &gControllers[arg0->unk_720->unk_08[0]->unk_001];

    BattleScene_BindParticipantRosterForSide(arg0, 0);
    BattleScene_SetParticipantSelectedSide(arg0, 0);
    BattleScene_SetParticipantController(arg0, sp24);
    arg0->unk_728.unk_16C = 0;
}

void BattleScene_InitializeParticipantModel(Battler* arg0) {
    UNUSED s32 pad[2];
    ModelNodeView* sp24;
    s16 sp22;

    BattleScene_GetParticipantSideIndex(arg0);
    sp24 = Battle_GetMoveEffectListEntry(arg0, 0);
    sp22 = Battle_GetTrainerId(arg0, 0);
    ModelRenderer_AttachDisplayObject(&arg0->unk_000);

    if (arg0 == D_84390010[0]) {
        arg0->unk_000.effectSlot = 0;
    } else {
        arg0->unk_000.effectSlot = 1;
    }

    Model_InitDisplayObject(&arg0->unk_000, 0, sp22, sp24);
    func_84302658(arg0, 1);
    ModelAnim_SetAnimation(&arg0->unk_000, 0);
    ModelAnim_SetFrame(&arg0->unk_000, 0);

    arg0->unk_720->unk_04 = arg0->unk_724->unk_01C;
    if ((arg0->unk_000.objectType == 0x32) || (arg0->unk_000.objectType == 0x33)) {
        arg0->unk_000.node.renderFlags &= ~0x40;
    } else {
        arg0->unk_000.node.renderFlags |= 0x40;
    }

    if (arg0 == D_84390010[0]) {
        BattleScene_PositionParticipantModel(arg0);
        arg0->unk_000.rotation.y = 0x4000;
    } else {
        BattleScene_PositionParticipantModel(arg0);
        arg0->unk_000.rotation.y = -0x4000;
    }
}

void BattleScene_InitializeParticipantOwnerModel(Battler* arg0) {
    PresentationState* ptr = &arg0->unk_728;
    ModelNodeView* sp28;
    s16 sp26;

    sp28 = Battle_GetMoveEffectListEntry(arg0, 0);
    sp26 = Battle_GetTrainerId(arg0, 0);
    ModelRenderer_AttachDisplayObject(&ptr->unk_000);

    if (arg0 == D_84390010[0]) {
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

void BattleScene_InitializeParticipantSecondaryModels(Battler* arg0, s32* arg1) {
    ModelNodeView* sp44;
    s16 sp42;
    s32 i;
    unk_D_84390010_168* ptr;

    sp44 = Battle_GetMoveEffectListEntry(arg0, 0);
    sp42 = Battle_GetTrainerId(arg0, 0);

    for (i = 0; i < 2; i++) {
        ptr = &arg0->unk_168[i];

        ModelRenderer_AttachDisplayObject(ptr);

        if (arg0 == D_84390010[0]) {
            ptr->unk_000.effectSlot = 0xFF;
        } else {
            ptr->unk_000.effectSlot = 0xFF;
        }

        Model_InitDisplayObject(ptr, 0, sp42, sp44);
        ModelAnim_SetFrame(ptr, 0);
        ModelAnim_SetAnimation(ptr, 0);

        ptr->unk_000.node.renderFlags &= ~0x40;

        if (arg0 == D_84390010[0]) {
            BattleScene_PositionParticipantModel(arg0);
        } else {
            BattleScene_PositionParticipantModel(arg0);
        }
        ptr->unk_000.node.flags &= ~1;
    }
}

void BattleScene_InitializeParticipantAuxiliaryModel(Battler* arg0) {
    DisplayObject* ptr = &arg0->unk_4EC;
    ModelNodeView* sp20 = arg0->unk_720->unk_18;

    ModelRenderer_AttachDisplayObject(ptr);
    ptr->effectSlot = 0xFF;
    Model_InitDisplayObject(ptr, 0, 0x9A, sp20);
    ModelAnim_SetAnimation(ptr, 0);

    ptr->node.renderFlags &= ~0x20;
    ptr->node.flags &= ~1;

    if (arg0 == D_84390010[0]) {
        Vec3f_SetComponentsDuplicate(&ptr->position, -50.0f, 2.0f, 0.0f);
    } else {
        Vec3f_SetComponentsDuplicate(&ptr->position, 50.0f, 2.0f, 0.0f);
    }
}

void BattleScene_InitializePresentation(UNUSED BattleSessionTeams* arg0) {
    D_84390174 = 0;
    D_84390178.unk_00 = 0;

    BattleScene_InitializeParticipantController(D_84390010[0]);
    BattleScene_InitializeParticipantController(D_84390010[1]);
    BattleScene_InitializeParticipantModel(D_84390010[0]);
    BattleScene_InitializeParticipantModel(D_84390010[1]);
    BattleScene_InitializeParticipantOwnerModel(D_84390010[0]);
    BattleScene_InitializeParticipantOwnerModel(D_84390010[1]);
    BattleScene_InitializeParticipantSecondaryModels(D_84390010[0], &D_84390010[0]->unk_168);
    BattleScene_InitializeParticipantSecondaryModels(D_84390010[1], &D_84390010[1]->unk_168);
    BattleScene_InitializeParticipantAuxiliaryModel(D_84390010[0]);
    BattleScene_InitializeParticipantAuxiliaryModel(D_84390010[1]);

    switch (D_800AE540.unk_0000) {
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

    BattleScene_SetParticipantModelFlags(D_84390010[0], 0, 0);
    BattleScene_SetParticipantModelFlags(D_84390010[1], 0, 0);
    BattleScene_ResetMessageQueue();
    BattleScene_ClearParticipantMessageBuffer(D_84390010[0]);
    BattleScene_ClearParticipantMessageBuffer(D_84390010[1]);
    BattleScene_ConfigureAudioChannelGroupCounts();
    BattleScene_ConfigureAudioChannelGroupsByTeam();
}

void BattleScene_ResetParticipantAuxTransform(UNUSED Battler* arg0, Battler* arg1, s32 arg2) {
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

    BattleScene_ResetParticipantAuxTransform(D_84390010[0], D_84390010[0], 1);
    BattleScene_ResetParticipantAuxTransform(D_84390010[1], D_84390010[1], -1);
    BattleScene_InitializePresentation(arg0);
    Battle_InitializeActiveRuntimeState();
    Battle_InitializeMoveUsabilityMask(D_84390010[0]);
    Battle_InitializeMoveUsabilityMask(D_84390010[1]);
    BattleBox_Close();
}

void BattleScene_UpdateParticipantsAndQueueEffects(Battler* arg0, Battler* arg1) {
    Battle_AdvanceSecondaryModelAnimIfFinished(D_84390010[0], D_84390010[0]);
    Battle_AdvanceSecondaryModelAnimIfFinished(D_84390010[1], D_84390010[1]);
    BattleAnim_UpdateOwnerStatusIdleAnimation(0);
    BattleAnim_UpdateOwnerStatusIdleAnimation(1);
    func_843060EC(D_84390010[0]);
    func_843060EC(D_84390010[1]);
}

s32 BattleScene_DispatchLifecycle(s32 arg0, BattleSessionTeams* arg1) {
    switch (arg0) {
        case 0:
            BattleScene_AllocateParticipants(arg1);
            break;

        case 1:
        case 2:
            BattleScene_UpdateParticipantsAndQueueEffects(D_84390010[0], D_84390010[1]);
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

void func_84307414(Battler* arg0) {
}

void BattleScene_StateRow56EnterNop(Battler* arg0) {
}

void BattleScene_StateRow5Slot3Nop(Battler* arg0) {
}

void BattleScene_StateRow5Slot4Nop(Battler* arg0) {
}

void BattleScene_StateRow5Slot5Nop(Battler* arg0) {
}

void BattleScene_StateRow5Slot6Nop(Battler* arg0) {
}

void BattleScene_StateRow7Slot5Nop(Battler* arg0) {
}

void BattleScene_StateRow6Slot6Nop(Battler* arg0) {
}

void BattleScene_StateRow6Slot5Nop(Battler* arg0) {
}

void BattleScene_StateRow6Slot4Nop(Battler* arg0) {
}

void BattleScene_StateRow6Slot3Nop(Battler* arg0) {
}

void func_8430746C(Battler* arg0) {
}

void func_84307474(Battler* arg0, s32 arg1) {
}

void func_84307480(Battler* arg0, s32 arg1) {
}

void BattleScene_StateRow7Slot4Nop(Battler* arg0) {
}
