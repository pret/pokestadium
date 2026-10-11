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

BattleMon* BattleScene_GetParticipantSessionMon(Battler* arg0) {
    BattleMon* ptr = &arg0->unk_720->unk_08[arg0->unk_654.unk_2C]->unk_01C[arg0->unk_654.unk_08];

    return ptr;
}

s32 BattleScene_IsPartnerPikachu(Battler* arg0) {
    BattleMon* temp_v0 = BattleScene_GetParticipantSessionMon(arg0);

    if ((arg0->unk_000.objectType == 0x19) && (temp_v0->unk_52 & 0x80)) {
        return 1;
    }
    return 0;
}

f32 BattleScene_GetParticipantModelHeight(Battler* arg0) {
    return D_84390028[BattleScene_GetParticipantSideIndex(arg0)].unk_08;
}

f32 BattleScene_GetParticipantModelRadius(Battler* arg0) {
    return D_84390028[BattleScene_GetParticipantSideIndex(arg0)].unk_00;
}

f32 BattleScene_GetParticipantModelWidth(Battler* arg0) {
    return D_84390028[BattleScene_GetParticipantSideIndex(arg0)].unk_04;
}

f32 BattleScene_GetParticipantEyeHeight(Battler* arg0) {
    return D_84390028[BattleScene_GetParticipantSideIndex(arg0)].unk_0C;
}

void BattleScene_PositionParticipantModel(Battler* arg0) {
    if (BattleScene_GetParticipantSideIndex(arg0) == 0) {
        if (arg0->unk_000.objectType == 0x82) {
            Vec3f_SetComponentsDuplicate(&arg0->unk_000.position, -225.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
        } else if ((arg0->unk_000.objectType == 3) || (arg0->unk_000.objectType == 0x83)) {
            Vec3f_SetComponentsDuplicate(&arg0->unk_000.position, -175.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
        } else if (arg0->unk_000.objectType == 0x5F) {
            Vec3f_SetComponentsDuplicate(&arg0->unk_000.position, -225.0f, BattleScene_GetParticipantModelHeight(arg0), 7.5000005f);
        } else {
            Vec3f_SetComponentsDuplicate(&arg0->unk_000.position, -150.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
        }
    } else if ((arg0->unk_000.objectType == 0x82) || (arg0->unk_000.objectType == 0x5F)) {
        Vec3f_SetComponentsDuplicate(&arg0->unk_000.position, 225.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
    } else if ((arg0->unk_000.objectType == 3) || (arg0->unk_000.objectType == 0x83)) {
        Vec3f_SetComponentsDuplicate(&arg0->unk_000.position, 175.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
    } else {
        Vec3f_SetComponentsDuplicate(&arg0->unk_000.position, 150.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
    }
}

f32 BattleScene_GetParticipantModelXOffset(Battler* arg0) {
    if (BattleScene_GetParticipantSideIndex(arg0) == 0) {
        if ((arg0->unk_000.objectType == 0x82) || (arg0->unk_000.objectType == 0x5F)) {
            return -200.0f;
        }

        if ((arg0->unk_000.objectType == 3) || (arg0->unk_000.objectType == 0x83)) {
            return -175.0f;
        }
        return -150.0f;
    }

    if ((arg0->unk_000.objectType == 0x82) || (arg0->unk_000.objectType == 0x5F)) {
        return 200.0f;
    }

    if ((arg0->unk_000.objectType == 3) || (arg0->unk_000.objectType == 0x83)) {
        return 175.0f;
    }

    return 150.0f;
}

void BattleScene_SetParticipantModelScale(Battler* arg0, f32 arg1) {
    arg0->unk_000.scale.x = arg1;
    arg0->unk_000.scale.y = arg1;
    arg0->unk_000.scale.z = arg1;
}

s32 BattleScene_GetSelectedSideTeamSize(Battler* arg0) {
    return arg0->unk_720->unk_08[arg0->unk_654.unk_2B]->unk_002;
}

s32 BattleScene_GetOpposingSelectedSideTeamSize(Battler* arg0) {
    s32 idx = arg0->unk_654.unk_2B == 0;

    return arg0->unk_720->unk_08[idx]->unk_002;
}

s32 BattleScene_GetParticipantSideIndex(Battler* arg0) {
    if (arg0 == D_84390018) {
        return 0;
    }
    return 1;
}

u8 Battle_GetCameraShotFieldB(Battler* arg0) {
    UNUSED s32 pad;
    UNUSED s16 pad2;
    s16 sp18 = arg0->unk_654.unk_38.unk_5A - 1;
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp18];

    return ptr->unk_02;
}

u8 Battle_GetCameraShotFieldC(Battler* arg0) {
    UNUSED s32 pad;
    UNUSED s16 pad2;
    s16 sp18 = arg0->unk_654.unk_38.unk_5A - 1;
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_000[sp18];

    return ptr->unk_03;
}

s16 Battle_GetSideAnimTableFieldB(Battler* arg0) {
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_A80;

    return ptr->unk_02;
}

s32 Battle_GetSideAnimTableFieldC(Battler* arg0) {
    MovePresentationCue* ptr = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_A80;

    return ptr->unk_03;
}

f32 Battle_GetScaledHeightY(Battler* arg0) {
    return ((BattleScene_GetParticipantModelWidth(arg0) * 2) / 50.0f) * arg0->unk_000.scale.y;
}

f32 Battle_GetScaleRatio(Battler* arg0) {
    return (BattleScene_GetParticipantModelWidth(arg0) * 2) / 50.0f;
}

s16 BattleScene_GetActiveAnimRowId(Battler* arg0) {
    return arg0->unk_654.unk_38.unk_5A;
}

void BattleScene_GetParticipantModelBoundsScaled(Battler* arg0, Vec3f* arg1) {
    arg1->x = ((BattleScene_GetParticipantModelRadius(arg0) * 2) / 50.0f) * arg0->unk_000.scale.x;
    arg1->y = ((BattleScene_GetParticipantModelWidth(arg0) * 2) / 50.0f) * arg0->unk_000.scale.y;
    arg1->z = ((BattleScene_GetParticipantModelRadius(arg0) * 2) / 50.0f) * arg0->unk_000.scale.x;
}

void BattleScene_GetParticipantModelRotation(Battler* arg0, Vec3s* arg1) {
    arg1->x = arg0->unk_000.rotation.x;
    arg1->y = arg0->unk_000.rotation.y;
    arg1->z = arg0->unk_000.rotation.z;
}

u16 Battle_GetActiveMonHp(Battler* arg0) {
    BattleMon* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    return ptr->unk_02;
}

s16 BattleScene_GetParticipantFacingAngle(Battler* arg0) {
    return arg0->unk_4B0 << 0xE;
}

s32 BattleAnim_GetSpeciesBySideIndex(s32 arg0) {
    return D_84390010[arg0]->unk_000.objectType;
}

s32 BattleAnim_GetOwnerSpecies(Battler* arg0) {
    return arg0->unk_000.objectType;
}

u8 BattleScene_IsParticipantModelVisible(Battler* arg0) {
    s32 ret = arg0->unk_000.node.flags & 1;
    return ret;
}

void BattleScene_GetParticipantModelPosition(Battler* arg0, Vec3f* arg1) {
    arg1->x = arg0->unk_000.position.x;
    arg1->y = arg0->unk_000.position.y;
    arg1->z = arg0->unk_000.position.z;
}

void BattleAnim_GetOwnerDefaultAnchorPosition(Battler* arg0, Vec3f* arg1) {
    f32 var_fs0 = 0.0f;

    if (BattleScene_ByteArrayContains(arg0->unk_000.objectType, &D_843845F0, 1) != 0) {
        var_fs0 = BattleAnim_GetOwnerModelHeight(arg0) / 1.5f;
    } else if (BattleScene_ByteArrayContains(arg0->unk_000.objectType, &D_843845F4, 1) != 0) {
        var_fs0 = BattleAnim_GetOwnerModelHeight(arg0) * 0.5f;
    } else if ((BattleScene_ByteArrayContains(arg0->unk_000.objectType, &D_843845F8, 1) != 0) && (arg0->unk_654.unk_34 & 0x200)) {
        var_fs0 = 2.0f * BattleAnim_GetOwnerModelHeight(arg0);
    } else if ((BattleScene_ByteArrayContains(arg0->unk_000.objectType, D_843845FC, 2) != 0) && (arg0->unk_654.unk_34 & 0x200)) {
        var_fs0 = BattleAnim_GetOwnerModelHeight(arg0) * 1.5f;
    }

    if (BattleScene_GetParticipantModelHeight(arg0) != 0.0f) {
        arg1->x = arg0->unk_000.position.x;
        arg1->y = arg0->unk_000.position.y + var_fs0;
        arg1->z = arg0->unk_000.position.z;
    } else {
        arg1->x = arg0->unk_000.position.x;
        arg1->y = BattleAnim_GetOwnerModelHeight(arg0) + arg0->unk_000.position.y + var_fs0;
        arg1->z = arg0->unk_000.position.z;
    }

    if (arg1->y < 0.0f) {
        arg1->y = BattleAnim_GetOwnerModelHeight(arg0);
    }
}

void BattleScene_ComputeParticipantModelOffset(Battler* arg0, Vec3f* arg1) {
    if (BattleScene_GetParticipantSideIndex(arg0) == 0) {
        if (arg0->unk_000.objectType == 0x82) {
            Vec3f_SetComponentsDuplicate(arg1, -225.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
        } else if ((arg0->unk_000.objectType == 3) || (arg0->unk_000.objectType == 0x83)) {
            Vec3f_SetComponentsDuplicate(arg1, -175.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
        } else if (arg0->unk_000.objectType == 0x5F) {
            Vec3f_SetComponentsDuplicate(arg1, -225.0f, BattleScene_GetParticipantModelHeight(arg0), 7.5000005f);
        } else {
            Vec3f_SetComponentsDuplicate(arg1, -150.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
        }
    } else if ((arg0->unk_000.objectType == 0x82) || (arg0->unk_000.objectType == 0x5F)) {
        Vec3f_SetComponentsDuplicate(arg1, 225.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
    } else if ((arg0->unk_000.objectType == 3) || (arg0->unk_000.objectType == 0x83)) {
        Vec3f_SetComponentsDuplicate(arg1, 175.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
    } else {
        Vec3f_SetComponentsDuplicate(arg1, 150.0f, BattleScene_GetParticipantModelHeight(arg0), 0.0f);
    }
}

void BattleScene_GetParticipantAuxiliaryModelPosition(Battler* arg0, Vec3f* arg1) {
    arg1->x = arg0->unk_4EC.position.x;
    arg1->y = arg0->unk_4EC.position.y + 2.5f;
    arg1->z = arg0->unk_4EC.position.z;
}

f32 BattleAnim_GetOwnerModelHeight(Battler* arg0) {
    if (arg0->unk_4B4 == 0x10) {
        return BattleScene_GetParticipantModelWidth(arg0);
    }
    return BattleScene_GetParticipantModelWidth(arg0) * arg0->unk_000.scale.y;
}

f32 BattleScene_GetParticipantModelRadiusScaled(Battler* arg0) {
    return BattleScene_GetParticipantModelRadius(arg0) * arg0->unk_000.scale.y;
}

ModelNodeView* Battle_GetMoveEffectListEntry(Battler* arg0, s32 arg1) {
    return arg0->unk_720->unk_14->unk_00[2]->unk_00[arg1];
}

s32 Battle_GetTrainerId(Battler* arg0, UNUSED s32 arg1) {
    return arg0->unk_720->unk_02;
}

char* Battle_GetActiveMoveName(Battler* arg0) {
    return Text_GetString(NULL, 0, D_843900B8, arg0->unk_654.unk_38.unk_5A - 1);
}

u8* Battle_GetActiveMonNickname(Battler* arg0) {
    return arg0->unk_724->unk_01C[arg0->unk_654.unk_08].unk_30;
}

void BattleScene_SetParticipantModelFlags(Battler* arg0, s32 arg1, s32 arg2) {
    arg0->unk_4B4 = arg1;
    arg0->unk_4B8 = arg2;
}

void Battle_AdvanceSecondaryModelAnimIfFinished(Battler* arg0, Battler* arg1) {
    s32 idx;
    MovePresentationCue* sp30;
    MovePresentationCue* sp2C;
    MovePresentationCue* sp28;
    BattlerState* sp20 = &arg0->unk_654;

    idx = BattleScene_GetParticipantSideIndex(arg0);
    sp30 = &D_84384570[idx]->unk_A50;
    idx = BattleScene_GetParticipantSideIndex(arg0);
    sp2C = &D_84384570[idx]->unk_B00;
    idx = BattleScene_GetParticipantSideIndex(arg0);
    sp28 = &D_84384570[idx]->unk_AF0;

    if (!(sp20->unk_34 & 0x4002)) {
        if ((BattleAnim_IsSessionBusy(arg0) == 0) && (arg1->unk_000.transformAnim.animationId != -1) &&
            (ModelAnim_IsFinished(&arg1->unk_000) == 1)) {
            if (sp20->unk_34 & 0x200) {
                ModelAnim_SetAnimation(&arg1->unk_000, sp2C->unk_00);
            } else if ((sp20->unk_34 & 1) && (BattleScene_ByteArrayContains(arg1->unk_000.objectType, D_84384590, 8) != 0)) {
                ModelAnim_SetAnimation(&arg1->unk_000, sp28->unk_00);
            } else {
                if (arg1->unk_000.objectType == 0x84) {
                    idx = BattleAnim_RandomRange(5);
                    ModelAnim_SetAnimation(&arg1->unk_000, idx + 0xE);
                } else {
                    ModelAnim_SetAnimation(&arg1->unk_000, sp30->unk_00);
                }

                if (!(sp20->unk_34 & 1)) {
                    BattleAnim_SetModelEventTrackAndState(arg0, 0xA5, 1);
                }
            }

            ModelAnim_SetFrame(&arg1->unk_000, 0);
        }
    }
}

void Battle_ResetModelToIdleAnim(Battler* arg0) {
    s32 idx;
    BattlerState* sp24;
    MovePresentationCue* sp34;
    MovePresentationCue* sp30;
    MovePresentationCue* sp2C;

    sp24 = &arg0->unk_654;
    idx = BattleScene_GetParticipantSideIndex(arg0);
    sp34 = &D_84384570[idx]->unk_A50;
    idx = BattleScene_GetParticipantSideIndex(arg0);
    sp30 = &D_84384570[idx]->unk_B00;
    idx = BattleScene_GetParticipantSideIndex(arg0);
    sp2C = &D_84384570[idx]->unk_AF0;

    if (!(sp24->unk_34 & 0x4002) && (BattleAnim_IsSessionBusy(arg0) == 0) && (arg0->unk_000.transformAnim.animationId != -1)) {
        ModelAnim_SetFrame(&arg0->unk_000, 0);
        if (sp24->unk_34 & 0x200) {
            ModelAnim_SetAnimation(&arg0->unk_000, sp30->unk_00);
        } else if ((sp24->unk_34 & 1) && (BattleScene_ByteArrayContains(arg0->unk_000.objectType, D_84384590, 8) != 0)) {
            ModelAnim_SetAnimation(&arg0->unk_000, sp2C->unk_00);
        } else {
            if (arg0->unk_000.objectType == 0x84) {
                ModelAnim_SetAnimation(&arg0->unk_000, BattleAnim_RandomRange(5) + 0xE);
            } else {
                ModelAnim_SetAnimation(&arg0->unk_000, sp34->unk_00);
            }

            if (!(sp24->unk_34 & 1)) {
                BattleAnim_SetModelEventTrackAndState(arg0, 0xA5, 1);
            }
        }
    }
}

void Battle_SetModelToStatusAnim(Battler* arg0) {
    MovePresentationCue* sp1C = &D_84384570[BattleScene_GetParticipantSideIndex(arg0)]->unk_A80;

    if (arg0->unk_000.transformAnim.animationId != -1) {
        ModelAnim_SetFrame(&arg0->unk_000, 0);
        ModelAnim_SetAnimation(&arg0->unk_000, sp1C->unk_00);
    }
}

void BattleScene_BindParticipantRosterForSide(Battler* arg0, s32 arg1) {
    arg0->unk_724 = arg0->unk_720->unk_08[arg1];
}

void BattleScene_SetParticipantSelectedSide(Battler* arg0, s32 arg1) {
    arg0->unk_654.unk_2B = arg1;
}

void BattleScene_SetParticipantController(Battler* arg0, Controller* arg1) {
    arg0->unk_654.unk_C8 = arg1;
}

void BattleScene_RebindParticipantToSide(Battler* arg0, s32 arg1) {
    BattlerState* temp_v0 = &arg0->unk_654;

    BattleScene_BindParticipantRosterForSide(arg0, arg1);
    BattleScene_SetParticipantSelectedSide(arg0, arg1);
    temp_v0->unk_08 = temp_v0->unk_18;
    arg0->unk_728.unk_16C = temp_v0->unk_2B;
}

s32 Battle_HasUsableSleepStatusTarget(Battler* arg0) {
    s32 i;
    BattlerState* temp_s0;
    BattleMon* ptr;

    temp_s0 = &arg0->unk_654;

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(arg0); i++) {
        ptr = &arg0->unk_724->unk_01C[i];
        if ((ptr->unk_05 & 0x20) && (arg0->unk_654.unk_38.unk_16[temp_s0->unk_08 + temp_s0->unk_2B * 3] == 0)) {
            return 1;
        }
    }

    if (arg0->unk_720->unk_01 == 2) {
        for (i = 0; i < BattleScene_GetOpposingSelectedSideTeamSize(arg0); i++) {
            ptr = &arg0->unk_720->unk_08[temp_s0->unk_2B == 0]->unk_01C[i];
            if ((ptr->unk_05 & 0x20) &&
                (arg0->unk_654.unk_38.unk_16[temp_s0->unk_08 + (temp_s0->unk_2B == 0) * 3] == 0)) {
                return 1;
            }
        }
    }

    return 0;
}

s32 Battle_HasUsableMajorStatusTarget(Battler* arg0) {
    s32 i;
    BattlerState* temp_s0;
    BattleMon* ptr;

    temp_s0 = &arg0->unk_654;

    for (i = 0; i < BattleScene_GetSelectedSideTeamSize(arg0); i++) {
        ptr = &arg0->unk_724->unk_01C[i];
        if ((ptr->unk_05 & 7) && (arg0->unk_654.unk_38.unk_16[temp_s0->unk_08 + temp_s0->unk_2B * 3] == 0)) {
            return 1;
        }
    }

    if (arg0->unk_720->unk_01 == 2) {
        for (i = 0; i < BattleScene_GetOpposingSelectedSideTeamSize(arg0); i++) {
            ptr = &arg0->unk_720->unk_08[temp_s0->unk_2B == 0]->unk_01C[i];
            if ((ptr->unk_05 & 7) && (arg0->unk_654.unk_38.unk_16[temp_s0->unk_08 + (temp_s0->unk_2B == 0) * 3] == 0)) {
                return 1;
            }
        }
    }
    return 0;
}

s32 BattleScene_GetCombinedTeamSize(Battler* arg0) {
    if (arg0->unk_720->unk_01 != 2) {
        return arg0->unk_720->unk_08[0]->unk_002;
    }
    return arg0->unk_720->unk_08[1]->unk_002 + arg0->unk_720->unk_08[0]->unk_002;
}

u8 BattleScene_GetRosterTeamSize(TeamRoster* arg0) {
    return arg0->unk_002;
}

s32 BattleScene_GetParticipantDisplayPlayerNumber(Battler* arg0) {
    return arg0->unk_720->unk_08[arg0->unk_728.unk_16C]->unk_001 + 1;
}

void BattleScene_ReinitParticipantBodyModel(Battler* arg0, Battler* arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad;
    ModelNodeView* sp20 = Battle_GetMoveEffectListEntry(arg0, 0);

    BattleScene_GetParticipantSideIndex(arg0);
    ModelRenderer_ClearDisplayObject(&arg1->unk_000);

    if (arg0 == D_84390010[0]) {
        arg1->unk_000.effectSlot = 0;
    } else {
        arg1->unk_000.effectSlot = 1;
    }

    Model_InitDisplayObject(&arg1->unk_000, 0, arg2, sp20);
    func_84302658(arg0, arg3);
    ModelAnim_SetFrame(&arg1->unk_000, 0);
    ModelAnim_SetAnimation(&arg1->unk_000, 0);

    if ((arg1->unk_000.objectType == 0x32) || (arg1->unk_000.objectType == 0x33)) {
        arg1->unk_000.node.renderFlags &= 0xFFBF;
    } else {
        arg1->unk_000.node.renderFlags |= 0x40;
    }

    if (!(arg0->unk_654.unk_34 & 0x200)) {
        if (arg0 == D_84390010[0]) {
            BattleScene_PositionParticipantModel(arg0);
            arg1->unk_000.rotation.y = 0x4000;
        } else {
            BattleScene_PositionParticipantModel(arg0);
            arg1->unk_000.rotation.y = -0x4000;
        }
    }
}

void BattleScene_ReinitParticipantOwnerModel(Battler* arg0, PresentationState* arg1, s16 arg2) {
    ModelNodeView* sp24;

    sp24 = Battle_GetMoveEffectListEntry(arg0, 0);
    ModelRenderer_ClearDisplayObject(&arg1->unk_000);

    if (arg0 == D_84390010[0]) {
        arg1->unk_000.effectSlot = 0xFF;
    } else {
        arg1->unk_000.effectSlot = 0xFF;
    }

    if (arg0 == D_84390010[0]) {
        Model_InitDisplayObject(&arg1->unk_000, 1, arg2, sp24);
    } else {
        Model_InitDisplayObject(&arg1->unk_000, 2, arg2, sp24);
    }

    ModelAnim_SetFrame(&arg1->unk_000, 0);
    ModelAnim_SetAnimation(&arg1->unk_000, 0);
    arg1->unk_000.node.renderFlags &= ~0x40;
}

void BattleScene_ReinitParticipantSecondaryModels(Battler* arg0, s16 arg1) {
    s32 i;
    ModelNodeView* sp58;
    unk_D_84390010_168* var_s0;

    sp58 = Battle_GetMoveEffectListEntry(arg0, 0);

    for (i = 0; i < 2; i++) {
        var_s0 = &arg0->unk_168[i];

        ModelRenderer_ClearDisplayObject(&var_s0->unk_000);
        if (arg0 == D_84390010[0]) {
            var_s0->unk_000.effectSlot = 0xFF;
        } else {
            var_s0->unk_000.effectSlot = 0xFF;
        }

        Model_InitDisplayObject(&var_s0->unk_000, 0, arg1, sp58);
        ModelAnim_SetFrame(&var_s0->unk_000, 0);
        ModelAnim_SetAnimation(&var_s0->unk_000, 0);

        var_s0->unk_000.node.renderFlags &= ~0x40;

        if (arg0 == D_84390010[0]) {
            Vec3f_SetComponentsDuplicate(&var_s0->unk_000.position, -150.0f, 0.0f, 0.0f);
            var_s0->unk_000.rotation.y = 0x4000;
        } else {
            Vec3f_SetComponentsDuplicate(&var_s0->unk_000.position, 150.0f, 0.0f, 0.0f);
            var_s0->unk_000.rotation.y = -0x4000;
        }

        var_s0->unk_000.node.flags &= ~1;
    }
}

void Battle_ResetEventTrack(Battler* arg0) {
    if (arg0->unk_654.unk_34 & 1) {
        BattleAnim_TrySetModelEventTrackFromRow(arg0, 0xAF, 2);
    } else {
        arg0->unk_654.unk_36 = 0;
        ModelAnim_SetEventFrame(&arg0->unk_000, 0);
        ModelAnim_SetEventTrack(&arg0->unk_000, -1);
    }
}

void Battle_LoadOwnerModelForSpecies(Battler* arg0) {
    BattlerState* ptr = &arg0->unk_654;
    UNUSED s32 pad[3];
    s16 sp26;

    Battle_GetMoveEffectListEntry(arg0, 0);
    sp26 = Battle_GetTrainerId(arg0, 0);
    BattleScene_ReinitParticipantBodyModel(arg0, arg0, sp26, 0);
    BattleScene_ReinitParticipantOwnerModel(arg0, &arg0->unk_728, sp26);
    BattleScene_ReinitParticipantSecondaryModels(arg0, sp26);
    Battle_ResetEventTrack(arg0);
    ptr->unk_34 &= 0x1800;
    Vec3f_SetComponentsDuplicate(&arg0->unk_000.scale, 1.0f, 1.0f, 1.0f);
}

void Battle_LoadOwnerModelForSwitchIn(Battler* arg0) {
    BattlerState* ptr = &arg0->unk_654;
    UNUSED s32 pad[3];
    s16 sp26;

    Battle_GetMoveEffectListEntry(arg0, 0);
    sp26 = Battle_GetTrainerId(arg0, 0);
    BattleScene_ReinitParticipantBodyModel(arg0, arg0, sp26, 1);
    BattleScene_ReinitParticipantOwnerModel(arg0, &arg0->unk_728, sp26);
    BattleScene_ReinitParticipantSecondaryModels(arg0, sp26);
    Battle_ResetEventTrack(arg0);
    ptr->unk_2D = 0;
    ptr->unk_34 &= 0x1800;
    Vec3f_SetComponentsDuplicate(&arg0->unk_000.scale, 1.0f, 1.0f, 1.0f);
}

void Battle_ResetOwnerModelToNeutralPlaceholder(Battler* arg0) {
    Model_SetMaterialColor(&arg0->unk_000, 0xFF, 0xFF, 0xFF, arg0->unk_654.unk_2E = 0xFF);
    arg0->unk_654.unk_BC = arg0->unk_000.objectType;
    BattleScene_ReinitParticipantBodyModel(arg0, arg0, 0x98, 0);
    BattleScene_ReinitParticipantSecondaryModels(arg0, 0x98);
    Battle_ResetEventTrack(arg0);
}

void Battle_ReloadNeutralPlaceholderModel(Battler* arg0) {
    BattleScene_ReinitParticipantBodyModel(arg0, arg0, 0x98, 0);
    BattleScene_ReinitParticipantSecondaryModels(arg0, 0x98);
    Battle_ResetEventTrack(arg0);
}

void Battle_ReloadModelForActiveMove(Battler* arg0) {
    UNUSED s32 pad[3];
    BattlerState* ptr = &arg0->unk_654;
    s16 sp2E = Battle_GetTrainerId(arg0, 0);

    ptr->unk_2E = 0xFF;
    Model_SetMaterialColor(&arg0->unk_000, 0xFF, 0xFF, 0xFF, ptr->unk_2E);
    BattleScene_ReinitParticipantBodyModel(arg0, arg0, sp2E, 0);
    BattleScene_ReinitParticipantSecondaryModels(arg0, sp2E);
    Battle_ResetEventTrack(arg0);
}
