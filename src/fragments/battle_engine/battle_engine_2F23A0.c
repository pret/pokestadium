#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/model_animation_events.h"
#include "src/model_renderer.h"
#include "src/text_system.h"
#include "src/matrix.h"

s32 BattleScene_ByteArrayContains(u8 arg0, u8* arg1, s32 arg2) {
    while (arg2--) {
        if (arg0 == *arg1) {
            return 1;
        }
        arg1++;
    }

    return 0;
}

BattleMon* BattleScene_GetParticipantSessionMon(ActivePokemon* active_pokemon) {
    BattleMon* ptr = &active_pokemon->sessionTeams->teamMember[active_pokemon->state.unk_2C]->pokemonPicked[active_pokemon->state.unk_08];

    return ptr;
}

s32 BattleScene_IsPartnerPikachu(ActivePokemon* active_pokemon) {
    BattleMon* temp_v0 = BattleScene_GetParticipantSessionMon(active_pokemon);

    if ((active_pokemon->displayObject.objectType == 0x19) && (temp_v0->unk_52 & 0x80)) {
        return 1;
    }
    return 0;
}

f32 BattleScene_GetParticipantModelHeight(ActivePokemon* active_pokemon) {
    return gPokemonModelDimensions[BattleScene_GetParticipantSideIndex(active_pokemon)].unk_08;
}

f32 BattleScene_GetParticipantModelRadius(ActivePokemon* active_pokemon) {
    return gPokemonModelDimensions[BattleScene_GetParticipantSideIndex(active_pokemon)].unk_00;
}

f32 BattleScene_GetParticipantModelWidth(ActivePokemon* active_pokemon) {
    return gPokemonModelDimensions[BattleScene_GetParticipantSideIndex(active_pokemon)].unk_04;
}

f32 BattleScene_GetParticipantEyeHeight(ActivePokemon* active_pokemon) {
    return gPokemonModelDimensions[BattleScene_GetParticipantSideIndex(active_pokemon)].unk_0C;
}

void BattleScene_PositionParticipantModel(ActivePokemon* active_pokemon) {
    if (BattleScene_GetParticipantSideIndex(active_pokemon) == 0) {
        if (active_pokemon->displayObject.objectType == 0x82) {
            Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.position, -225.0f, BattleScene_GetParticipantModelHeight(active_pokemon), 0.0f);
        } else if ((active_pokemon->displayObject.objectType == 3) || (active_pokemon->displayObject.objectType == 0x83)) {
            Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.position, -175.0f, BattleScene_GetParticipantModelHeight(active_pokemon), 0.0f);
        } else if (active_pokemon->displayObject.objectType == 0x5F) {
            Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.position, -225.0f, BattleScene_GetParticipantModelHeight(active_pokemon), 7.5000005f);
        } else {
            Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.position, -150.0f, BattleScene_GetParticipantModelHeight(active_pokemon), 0.0f);
        }
    } else if ((active_pokemon->displayObject.objectType == 0x82) || (active_pokemon->displayObject.objectType == 0x5F)) {
        Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.position, 225.0f, BattleScene_GetParticipantModelHeight(active_pokemon), 0.0f);
    } else if ((active_pokemon->displayObject.objectType == 3) || (active_pokemon->displayObject.objectType == 0x83)) {
        Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.position, 175.0f, BattleScene_GetParticipantModelHeight(active_pokemon), 0.0f);
    } else {
        Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.position, 150.0f, BattleScene_GetParticipantModelHeight(active_pokemon), 0.0f);
    }
}

f32 BattleScene_GetParticipantModelXOffset(ActivePokemon* active_pokemon) {
    if (BattleScene_GetParticipantSideIndex(active_pokemon) == 0) {
        if ((active_pokemon->displayObject.objectType == 0x82) || (active_pokemon->displayObject.objectType == 0x5F)) {
            return -200.0f;
        }

        if ((active_pokemon->displayObject.objectType == 3) || (active_pokemon->displayObject.objectType == 0x83)) {
            return -175.0f;
        }
        return -150.0f;
    }

    if ((active_pokemon->displayObject.objectType == 0x82) || (active_pokemon->displayObject.objectType == 0x5F)) {
        return 200.0f;
    }

    if ((active_pokemon->displayObject.objectType == 3) || (active_pokemon->displayObject.objectType == 0x83)) {
        return 175.0f;
    }

    return 150.0f;
}

void BattleScene_SetParticipantModelScale(ActivePokemon* arg0, f32 arg1) {
    arg0->displayObject.scale.x = arg1;
    arg0->displayObject.scale.y = arg1;
    arg0->displayObject.scale.z = arg1;
}

s32 BattleScene_GetSelectedSideTeamSize(ActivePokemon* active_pokemon) {
    return active_pokemon->sessionTeams->teamMember[active_pokemon->state.unk_2B]->numberOfPokemonChosen;
}

s32 BattleScene_GetOpposingSelectedSideTeamSize(ActivePokemon* active_pokemon) {
    s32 idx = active_pokemon->state.unk_2B == 0;

    return active_pokemon->sessionTeams->teamMember[idx]->numberOfPokemonChosen;
}

s32 BattleScene_GetParticipantSideIndex(ActivePokemon* active_pokemon) {
    if (active_pokemon == sSide1ActivePokemon) {
        return 0;
    }
    return 1;
}

u8 Battle_GetCameraShotFieldB(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    UNUSED s16 pad2;
    s16 sp18 = active_pokemon->state.runtime.usedMove - 1;
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp18];

    return ptr->unk_02;
}

u8 Battle_GetCameraShotFieldC(ActivePokemon* active_pokemon) {
    UNUSED s32 pad;
    UNUSED s16 pad2;
    s16 sp18 = active_pokemon->state.runtime.usedMove - 1;
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_000[sp18];

    return ptr->unk_03;
}

s16 Battle_GetSideAnimTableFieldB(ActivePokemon* active_pokemon) {
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_A80;

    return ptr->unk_02;
}

s32 Battle_GetSideAnimTableFieldC(ActivePokemon* active_pokemon) {
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_A80;

    return ptr->unk_03;
}

f32 Battle_GetScaledHeightY(ActivePokemon* active_pokemon) {
    return ((BattleScene_GetParticipantModelWidth(active_pokemon) * 2) / 50.0f) * active_pokemon->displayObject.scale.y;
}

f32 Battle_GetScaleRatio(ActivePokemon* active_pokemon) {
    return (BattleScene_GetParticipantModelWidth(active_pokemon) * 2) / 50.0f;
}

s16 BattleScene_GetActiveAnimRowId(ActivePokemon* active_pokemon) {
    return active_pokemon->state.runtime.usedMove;
}

void BattleScene_GetParticipantModelBoundsScaled(ActivePokemon* arg0, Vec3f* arg1) {
    arg1->x = ((BattleScene_GetParticipantModelRadius(arg0) * 2) / 50.0f) * arg0->displayObject.scale.x;
    arg1->y = ((BattleScene_GetParticipantModelWidth(arg0) * 2) / 50.0f) * arg0->displayObject.scale.y;
    arg1->z = ((BattleScene_GetParticipantModelRadius(arg0) * 2) / 50.0f) * arg0->displayObject.scale.x;
}

void BattleScene_GetParticipantModelRotation(ActivePokemon* arg0, Vec3s* arg1) {
    arg1->x = arg0->displayObject.rotation.x;
    arg1->y = arg0->displayObject.rotation.y;
    arg1->z = arg0->displayObject.rotation.z;
}

u16 Battle_GetActiveMonHp(ActivePokemon* active_pokemon) {
    BattleMon* ptr = &active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08];

    return ptr->unk_02;
}

s16 BattleScene_GetParticipantFacingAngle(ActivePokemon* active_pokemon) {
    return active_pokemon->unk_4B0 << 0xE;
}

s32 BattleAnim_GetSpeciesBySideIndex(s32 arg0) {
    return sActivePokemon[arg0]->displayObject.objectType;
}

s32 BattleAnim_GetOwnerSpecies(ActivePokemon* active_pokemon) {
    return active_pokemon->displayObject.objectType;
}

u8 BattleScene_IsParticipantModelVisible(ActivePokemon* active_pokemon) {
    s32 ret = active_pokemon->displayObject.node.flags & 1;
    return ret;
}

void BattleScene_GetParticipantModelPosition(ActivePokemon* arg0, Vec3f* arg1) {
    arg1->x = arg0->displayObject.position.x;
    arg1->y = arg0->displayObject.position.y;
    arg1->z = arg0->displayObject.position.z;
}

void BattleAnim_GetOwnerDefaultAnchorPosition(ActivePokemon* arg0, Vec3f* arg1) {
    f32 var_fs0 = 0.0f;

    if (BattleScene_ByteArrayContains(arg0->displayObject.objectType, &D_843845F0, 1) != 0) {
        var_fs0 = BattleAnim_GetOwnerModelHeight(arg0) / 1.5f;
    } else if (BattleScene_ByteArrayContains(arg0->displayObject.objectType, &D_843845F4, 1) != 0) {
        var_fs0 = BattleAnim_GetOwnerModelHeight(arg0) * 0.5f;
    } else if ((BattleScene_ByteArrayContains(arg0->displayObject.objectType, &D_843845F8, 1) != 0) && (arg0->state.unk_34 & 0x200)) {
        var_fs0 = 2.0f * BattleAnim_GetOwnerModelHeight(arg0);
    } else if ((BattleScene_ByteArrayContains(arg0->displayObject.objectType, D_843845FC, 2) != 0) && (arg0->state.unk_34 & 0x200)) {
        var_fs0 = BattleAnim_GetOwnerModelHeight(arg0) * 1.5f;
    }

    if (BattleScene_GetParticipantModelHeight(arg0) != 0.0f) {
        arg1->x = arg0->displayObject.position.x;
        arg1->y = arg0->displayObject.position.y + var_fs0;
        arg1->z = arg0->displayObject.position.z;
    } else {
        arg1->x = arg0->displayObject.position.x;
        arg1->y = BattleAnim_GetOwnerModelHeight(arg0) + arg0->displayObject.position.y + var_fs0;
        arg1->z = arg0->displayObject.position.z;
    }

    if (arg1->y < 0.0f) {
        arg1->y = BattleAnim_GetOwnerModelHeight(arg0);
    }
}

void BattleScene_ComputeParticipantModelOffset(ActivePokemon* arg0, Vec3f* arg1) {
    if (BattleScene_GetParticipantSideIndex(arg0) == 0) {
        if (arg0->displayObject.objectType == 0x82) {
            Vec3f_SetComponentsDuplicate(arg1, -225.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
        } else if ((arg0->displayObject.objectType == 3) || (arg0->displayObject.objectType == 0x83)) {
            Vec3f_SetComponentsDuplicate(arg1, -175.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
        } else if (arg0->displayObject.objectType == 0x5F) {
            Vec3f_SetComponentsDuplicate(arg1, -225.0f, BattleScene_GetParticipantModelHeight(arg0), 7.5000005f);
        } else {
            Vec3f_SetComponentsDuplicate(arg1, -150.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
        }
    } else if ((arg0->displayObject.objectType == 0x82) || (arg0->displayObject.objectType == 0x5F)) {
        Vec3f_SetComponentsDuplicate(arg1, 225.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
    } else if ((arg0->displayObject.objectType == 3) || (arg0->displayObject.objectType == 0x83)) {
        Vec3f_SetComponentsDuplicate(arg1, 175.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
    } else {
        Vec3f_SetComponentsDuplicate(arg1, 150.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
    }
}

void BattleScene_GetParticipantAuxiliaryModelPosition(ActivePokemon* arg0, Vec3f* arg1) {
    arg1->x = arg0->unk_4EC.position.x;
    arg1->y = arg0->unk_4EC.position.y + 2.5f;
    arg1->z = arg0->unk_4EC.position.z;
}

f32 BattleAnim_GetOwnerModelHeight(ActivePokemon* active_pokemon) {
    if (active_pokemon->unk_4B4 == 0x10) {
        return BattleScene_GetParticipantModelWidth(active_pokemon);
    }
    return BattleScene_GetParticipantModelWidth(active_pokemon) * active_pokemon->displayObject.scale.y;
}

f32 BattleScene_GetParticipantModelRadiusScaled(ActivePokemon* active_pokemon) {
    return BattleScene_GetParticipantModelRadius(active_pokemon) * active_pokemon->displayObject.scale.y;
}

ModelNodeView* Battle_GetMoveEffectListEntry(ActivePokemon* arg0, s32 arg1) {
    return arg0->sessionTeams->unk_14->unk_00[2]->unk_00[arg1];
}

s32 Battle_GetTrainerId(ActivePokemon* arg0, UNUSED s32 arg1) {
    return arg0->sessionTeams->displayModel;
}

char* Battle_GetActiveMoveName(ActivePokemon* active_pokemon) {
    return Text_GetString(NULL, 0, sMoveNameTable, active_pokemon->state.runtime.usedMove - 1);
}

u8* Battle_GetActiveMonNickname(ActivePokemon* active_pokemon) {
    return active_pokemon->unk_724->pokemonPicked[active_pokemon->state.unk_08].unk_30;
}

void BattleScene_SetParticipantModelFlags(ActivePokemon* arg0, s32 arg1, s32 arg2) {
    arg0->unk_4B4 = arg1;
    arg0->unk_4B8 = arg2;
}

void Battle_AdvanceSecondaryModelAnimIfFinished(ActivePokemon* arg0, ActivePokemon* arg1) {
    s32 idx;
    MovePresentationCue* sp30;
    MovePresentationCue* sp2C;
    MovePresentationCue* sp28;
    ActivePokemonState* sp20 = &arg0->state;

    idx = BattleScene_GetParticipantSideIndex(arg0);
    sp30 = &D_84384570[idx]->unk_A50;
    idx = BattleScene_GetParticipantSideIndex(arg0);
    sp2C = &D_84384570[idx]->unk_B00;
    idx = BattleScene_GetParticipantSideIndex(arg0);
    sp28 = &D_84384570[idx]->unk_AF0;

    if (!(sp20->unk_34 & 0x4002)) {
        if ((BattleAnim_IsSessionBusy(arg0) == 0) && (arg1->displayObject.transformAnim.animationId != -1) &&
            (ModelAnim_IsFinished(&arg1->displayObject) == 1)) {
            if (sp20->unk_34 & 0x200) {
                ModelAnim_SetAnimation(&arg1->displayObject, sp2C->id);
            } else if ((sp20->unk_34 & 1) && (BattleScene_ByteArrayContains(arg1->displayObject.objectType, D_84384590, 8) != 0)) {
                ModelAnim_SetAnimation(&arg1->displayObject, sp28->id);
            } else {
                if (arg1->displayObject.objectType == 0x84) {
                    idx = BattleAnim_RandomRange(5);
                    ModelAnim_SetAnimation(&arg1->displayObject, idx + 0xE);
                } else {
                    ModelAnim_SetAnimation(&arg1->displayObject, sp30->id);
                }

                if (!(sp20->unk_34 & 1)) {
                    BattleAnim_SetModelEventTrackAndState(arg0, 0xA5, 1);
                }
            }

            ModelAnim_SetFrame(&arg1->displayObject, 0);
        }
    }
}

void Battle_ResetModelToIdleAnim(ActivePokemon* active_pokemon) {
    s32 idx;
    ActivePokemonState* sp24;
    MovePresentationCue* sp34;
    MovePresentationCue* sp30;
    MovePresentationCue* sp2C;

    sp24 = &active_pokemon->state;
    idx = BattleScene_GetParticipantSideIndex(active_pokemon);
    sp34 = &D_84384570[idx]->unk_A50;
    idx = BattleScene_GetParticipantSideIndex(active_pokemon);
    sp30 = &D_84384570[idx]->unk_B00;
    idx = BattleScene_GetParticipantSideIndex(active_pokemon);
    sp2C = &D_84384570[idx]->unk_AF0;

    if (!(sp24->unk_34 & 0x4002) && (BattleAnim_IsSessionBusy(active_pokemon) == 0) && (active_pokemon->displayObject.transformAnim.animationId != -1)) {
        ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        if (sp24->unk_34 & 0x200) {
            ModelAnim_SetAnimation(&active_pokemon->displayObject, sp30->id);
        } else if ((sp24->unk_34 & 1) && (BattleScene_ByteArrayContains(active_pokemon->displayObject.objectType, D_84384590, 8) != 0)) {
            ModelAnim_SetAnimation(&active_pokemon->displayObject, sp2C->id);
        } else {
            if (active_pokemon->displayObject.objectType == 0x84) {
                ModelAnim_SetAnimation(&active_pokemon->displayObject, BattleAnim_RandomRange(5) + 0xE);
            } else {
                ModelAnim_SetAnimation(&active_pokemon->displayObject, sp34->id);
            }

            if (!(sp24->unk_34 & 1)) {
                BattleAnim_SetModelEventTrackAndState(active_pokemon, 0xA5, 1);
            }
        }
    }
}

void Battle_SetModelToStatusAnim(ActivePokemon* active_pokemon) {
    MovePresentationCue* sp1C = &D_84384570[BattleScene_GetParticipantSideIndex(active_pokemon)]->unk_A80;

    if (active_pokemon->displayObject.transformAnim.animationId != -1) {
        ModelAnim_SetFrame(&active_pokemon->displayObject, 0);
        ModelAnim_SetAnimation(&active_pokemon->displayObject, sp1C->id);
    }
}

void BattleScene_BindParticipantRosterForSide(ActivePokemon* arg0, s32 arg1) {
    arg0->unk_724 = arg0->sessionTeams->teamMember[arg1];
}

void BattleScene_SetParticipantSelectedSide(ActivePokemon* arg0, s32 arg1) {
    arg0->state.unk_2B = arg1;
}

void BattleScene_SetParticipantController(ActivePokemon* arg0, Controller* arg1) {
    arg0->state.unk_C8 = arg1;
}

void BattleScene_RebindParticipantToSide(ActivePokemon* arg0, s32 arg1) {
    ActivePokemonState* temp_v0 = &arg0->state;

    BattleScene_BindParticipantRosterForSide(arg0, arg1);
    BattleScene_SetParticipantSelectedSide(arg0, arg1);
    temp_v0->unk_08 = temp_v0->unk_18;
    arg0->unk_728.unk_16C = temp_v0->unk_2B;
}

s32 Battle_HasUsableSleepStatusTarget(ActivePokemon* active_pokemon) {
    s32 i;
    ActivePokemonState* temp_s0;
    BattleMon* ptr;

    temp_s0 = &active_pokemon->state;

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(active_pokemon); i++) {
        ptr = &active_pokemon->unk_724->pokemonPicked[i];
        if ((ptr->unk_05 & 0x20) && (active_pokemon->state.runtime.unk_16[temp_s0->unk_08 + temp_s0->unk_2B * 3] == 0)) {
            return 1;
        }
    }

    if (active_pokemon->sessionTeams->unk_01 == 2) {
        for (i = 0; i < BattleScene_GetOpposingSelectedSideTeamSize(active_pokemon); i++) {
            ptr = &active_pokemon->sessionTeams->teamMember[temp_s0->unk_2B == 0]->pokemonPicked[i];
            if ((ptr->unk_05 & 0x20) &&
                (active_pokemon->state.runtime.unk_16[temp_s0->unk_08 + (temp_s0->unk_2B == 0) * 3] == 0)) {
                return 1;
            }
        }
    }

    return 0;
}

s32 Battle_HasUsableMajorStatusTarget(ActivePokemon* active_pokemon) {
    s32 i;
    ActivePokemonState* temp_s0;
    BattleMon* ptr;

    temp_s0 = &active_pokemon->state;

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(active_pokemon); i++) {
        ptr = &active_pokemon->unk_724->pokemonPicked[i];
        if ((ptr->unk_05 & 7) && (active_pokemon->state.runtime.unk_16[temp_s0->unk_08 + temp_s0->unk_2B * 3] == 0)) {
            return 1;
        }
    }

    if (active_pokemon->sessionTeams->unk_01 == 2) {
        for (i = 0; i < BattleScene_GetOpposingSelectedSideTeamSize(active_pokemon); i++) {
            ptr = &active_pokemon->sessionTeams->teamMember[temp_s0->unk_2B == 0]->pokemonPicked[i];
            if ((ptr->unk_05 & 7) && (active_pokemon->state.runtime.unk_16[temp_s0->unk_08 + (temp_s0->unk_2B == 0) * 3] == 0)) {
                return 1;
            }
        }
    }
    return 0;
}

s32 BattleScene_GetCombinedTeamSize(ActivePokemon* active_pokemon) {
    if (active_pokemon->sessionTeams->unk_01 != 2) {
        return active_pokemon->sessionTeams->teamMember[0]->numberOfPokemonChosen;
    }
    return active_pokemon->sessionTeams->teamMember[1]->numberOfPokemonChosen + active_pokemon->sessionTeams->teamMember[0]->numberOfPokemonChosen;
}

u8 BattleScene_GetRosterTeamSize(TeamRoster* arg0) {
    return arg0->numberOfPokemonChosen;
}

s32 BattleScene_GetParticipantDisplayPlayerNumber(ActivePokemon* active_pokemon) {
    return active_pokemon->sessionTeams->teamMember[active_pokemon->unk_728.unk_16C]->unk_001 + 1;
}

void BattleScene_ReinitParticipantBodyModel(ActivePokemon* arg0, ActivePokemon* arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad;
    ModelNodeView* sp20 = Battle_GetMoveEffectListEntry(arg0, 0);

    BattleScene_GetParticipantSideIndex(arg0);
    ModelRenderer_ClearDisplayObject(&arg1->displayObject);

    if (arg0 == sActivePokemon[0]) {
        arg1->displayObject.effectSlot = 0;
    } else {
        arg1->displayObject.effectSlot = 1;
    }

    Model_InitDisplayObject(&arg1->displayObject, 0, arg2, sp20);
    Battle_LoadAnimationAndMarkMoveIllegality(arg0, arg3);
    ModelAnim_SetFrame(&arg1->displayObject, 0);
    ModelAnim_SetAnimation(&arg1->displayObject, 0);

    if ((arg1->displayObject.objectType == 0x32) || (arg1->displayObject.objectType == 0x33)) {
        arg1->displayObject.node.renderFlags &= 0xFFBF;
    } else {
        arg1->displayObject.node.renderFlags |= 0x40;
    }

    if (!(arg0->state.unk_34 & 0x200)) {
        if (arg0 == sActivePokemon[0]) {
            BattleScene_PositionParticipantModel(arg0);
            arg1->displayObject.rotation.y = 0x4000;
        } else {
            BattleScene_PositionParticipantModel(arg0);
            arg1->displayObject.rotation.y = -0x4000;
        }
    }
}

void BattleScene_ReinitParticipantOwnerModel(ActivePokemon* arg0, PresentationState* arg1, s16 arg2) {
    ModelNodeView* sp24;

    sp24 = Battle_GetMoveEffectListEntry(arg0, 0);
    ModelRenderer_ClearDisplayObject(&arg1->unk_000);

    if (arg0 == sActivePokemon[0]) {
        arg1->unk_000.effectSlot = 0xFF;
    } else {
        arg1->unk_000.effectSlot = 0xFF;
    }

    if (arg0 == sActivePokemon[0]) {
        Model_InitDisplayObject(&arg1->unk_000, 1, arg2, sp24);
    } else {
        Model_InitDisplayObject(&arg1->unk_000, 2, arg2, sp24);
    }

    ModelAnim_SetFrame(&arg1->unk_000, 0);
    ModelAnim_SetAnimation(&arg1->unk_000, 0);
    arg1->unk_000.node.renderFlags &= ~0x40;
}

void BattleScene_ReinitParticipantSecondaryModels(ActivePokemon* arg0, s16 arg1) {
    s32 i;
    ModelNodeView* sp58;
    unk_D_84390010_168* var_s0;

    sp58 = Battle_GetMoveEffectListEntry(arg0, 0);

    for (i = 0; i < 2; i++) {
        var_s0 = &arg0->unk_168[i];

        ModelRenderer_ClearDisplayObject(&var_s0->unk_000);
        if (arg0 == sActivePokemon[0]) {
            var_s0->unk_000.effectSlot = 0xFF;
        } else {
            var_s0->unk_000.effectSlot = 0xFF;
        }

        Model_InitDisplayObject(&var_s0->unk_000, 0, arg1, sp58);
        ModelAnim_SetFrame(&var_s0->unk_000, 0);
        ModelAnim_SetAnimation(&var_s0->unk_000, 0);

        var_s0->unk_000.node.renderFlags &= ~0x40;

        if (arg0 == sActivePokemon[0]) {
            Vec3f_SetComponentsDuplicate(&var_s0->unk_000.position, -150.0f, 0.0f, 0.0f);
            var_s0->unk_000.rotation.y = 0x4000;
        } else {
            Vec3f_SetComponentsDuplicate(&var_s0->unk_000.position, 150.0f, 0.0f, 0.0f);
            var_s0->unk_000.rotation.y = -0x4000;
        }

        var_s0->unk_000.node.flags &= ~1;
    }
}

void Battle_ResetEventTrack(ActivePokemon* active_pokemon) {
    if (active_pokemon->state.unk_34 & 1) {
        BattleAnim_TrySetModelEventTrackFromRow(active_pokemon, 0xAF, 2);
    } else {
        active_pokemon->state.unk_36 = 0;
        ModelAnim_SetEventFrame(&active_pokemon->displayObject, 0);
        ModelAnim_SetEventTrack(&active_pokemon->displayObject, -1);
    }
}

void Battle_LoadOwnerModelForSpecies(ActivePokemon* active_pokemon) {
    ActivePokemonState* ptr = &active_pokemon->state;
    UNUSED s32 pad[3];
    s16 sp26;

    Battle_GetMoveEffectListEntry(active_pokemon, 0);
    sp26 = Battle_GetTrainerId(active_pokemon, 0);
    BattleScene_ReinitParticipantBodyModel(active_pokemon, active_pokemon, sp26, 0);
    BattleScene_ReinitParticipantOwnerModel(active_pokemon, &active_pokemon->unk_728, sp26);
    BattleScene_ReinitParticipantSecondaryModels(active_pokemon, sp26);
    Battle_ResetEventTrack(active_pokemon);
    ptr->unk_34 &= 0x1800;
    Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 1.0f, 1.0f, 1.0f);
}

void Battle_LoadOwnerModelForSwitchIn(ActivePokemon* active_pokemon) {
    ActivePokemonState* ptr = &active_pokemon->state;
    UNUSED s32 pad[3];
    s16 sp26;

    Battle_GetMoveEffectListEntry(active_pokemon, 0);
    sp26 = Battle_GetTrainerId(active_pokemon, 0);
    BattleScene_ReinitParticipantBodyModel(active_pokemon, active_pokemon, sp26, 1);
    BattleScene_ReinitParticipantOwnerModel(active_pokemon, &active_pokemon->unk_728, sp26);
    BattleScene_ReinitParticipantSecondaryModels(active_pokemon, sp26);
    Battle_ResetEventTrack(active_pokemon);
    ptr->unk_2D = 0;
    ptr->unk_34 &= 0x1800;
    Vec3f_SetComponentsDuplicate(&active_pokemon->displayObject.scale, 1.0f, 1.0f, 1.0f);
}

void Battle_ResetOwnerModelToNeutralPlaceholder(ActivePokemon* active_pokemon) {
    Model_SetMaterialColor(&active_pokemon->displayObject, 0xFF, 0xFF, 0xFF, active_pokemon->state.unk_2E = 0xFF);
    active_pokemon->state.model = active_pokemon->displayObject.objectType;
    BattleScene_ReinitParticipantBodyModel(active_pokemon, active_pokemon, 0x98, 0);
    BattleScene_ReinitParticipantSecondaryModels(active_pokemon, 0x98);
    Battle_ResetEventTrack(active_pokemon);
}

void Battle_ReloadNeutralPlaceholderModel(ActivePokemon* active_pokemon) {
    BattleScene_ReinitParticipantBodyModel(active_pokemon, active_pokemon, 0x98, 0);
    BattleScene_ReinitParticipantSecondaryModels(active_pokemon, 0x98);
    Battle_ResetEventTrack(active_pokemon);
}

void Battle_ReloadModelForActiveMove(ActivePokemon* active_pokemon) {
    UNUSED s32 pad[3];
    ActivePokemonState* ptr = &active_pokemon->state;
    s16 sp2E = Battle_GetTrainerId(active_pokemon, 0);

    ptr->unk_2E = 0xFF;
    Model_SetMaterialColor(&active_pokemon->displayObject, 0xFF, 0xFF, 0xFF, ptr->unk_2E);
    BattleScene_ReinitParticipantBodyModel(active_pokemon, active_pokemon, sp2E, 0);
    BattleScene_ReinitParticipantSecondaryModels(active_pokemon, sp2E);
    Battle_ResetEventTrack(active_pokemon);
}
