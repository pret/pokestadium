#include "battle_engine.h"
#include "moves.h"
#include "src/geo_render.h"
#include "src/matrix.h"
#include "pokemon.h"

unk_D_843901B0 D_843901B0;
f32 D_843901F0;
f32 D_843901F4;

static s32 D_84385B50 = 0;

f32 BattleScene_ScaleCameraDistance(ActivePokemon* arg0, f32 arg1, f32 arg2) {
    f32 temp_fv1 = BattleScene_GetParticipantModelRadiusScaled(arg0) * arg1;

    if (arg2 < temp_fv1) {
        return arg2;
    }
    return temp_fv1;
}

s32 BattleScene_AdvanceCameraSubstepCounter(s32 arg0) {
    sBattleScene.unk_00->unk_10++;
    if (sBattleScene.unk_00->unk_10 >= arg0) {
        sBattleScene.unk_00->unk_10 = 0;
        return 1;
    }
    return 0;
}

s32 BattleScene_AdvanceCameraFrameCounter(s32 frame_limit) {
    sBattleScene.unk_00->unk_14++;
    if (sBattleScene.unk_00->unk_14 >= frame_limit) {
        sBattleScene.unk_00->unk_14 = 0;
        return 1;
    }
    return 0;
}

s32 BattleScene_AdvanceCameraFrameCounterUntil(s32 arg0) {
    if (sBattleScene.unk_00->unk_14 >= arg0) {
        return 1;
    }
    sBattleScene.unk_00->unk_14++;
    return 0;
}

s32 BattleScene_IsCameraFrameCounterAtLeast(s32 arg0) {
    if (sBattleScene.unk_00->unk_14 >= arg0) {
        return 1;
    }
    return 0;
}

void BattleScene_SetActivePokemonIndex(s32 arg0) {
    sBattleScene.unk_00->unk_2C = arg0;
}

void BattleScene_ResetCameraFrameCounter(void) {
    sBattleScene.unk_00->unk_14 = 0;
}

void BattleScene_ResetCameraSubstepCounter(void) {
    sBattleScene.unk_00->unk_10 = 0;
}

void BattleScene_SetCameraAtAndEyeFromAngles(CameraNode* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5, s16 arg6) {
    Vec3f_SetComponentsDuplicate(&arg0->view.targetPosition, arg1, arg2, arg3);
    Camera_ComputeEyeFromAngles(&arg0->view.targetPosition, &arg0->view.eyePosition, arg4, arg5, arg6);
}

void BattleScene_GetOwnerCameraAnchor(ActivePokemon* arg0, Vec3f* arg1) {
    UNUSED s32 pad;
    u8 sp18[] = {
        0x52, 0x73, 0x59, 0x91, 0x5F, 0x82, 0x58, 0x66, 0x0A,
    };

    if (BattleScene_ByteArrayContains(arg0->displayObject.objectType, sp18, 9) != 0) {
        BattleScene_GetOwnerBoneOrDefaultAnchor(arg0, arg1, 9);
    } else {
        BattleScene_GetOwnerBoneOrDefaultAnchor(arg0, arg1, 0x64);
    }
}

void BattleScene_GetOwnerBoneOrDefaultAnchor(ActivePokemon* arg0, Vec3f* arg1, s32 arg2) {
    if (GeoRender_FindAnchorPosition(&arg0->displayObject, arg2, arg1) == NULL) {
        BattleAnim_GetOwnerDefaultAnchorPosition(arg0, arg1);
        arg1->x = BattleScene_GetParticipantModelXOffset(arg0);
        arg1->z = 0.0f;
    }
}

void BattleScene_SetCameraModeAndStep(s32 camera_mode, s32 camera_step) {
    sBattleScene.unk_00->unk_1C = camera_mode;
    sBattleScene.unk_00->unk_20 = camera_step;
}

void BattleScene_SetCameraClipPlanes(CameraNode* arg0, f32 arg1, f32 arg2) {
    arg0->perspective.nearPlane = arg1;
    arg0->perspective.farPlane = arg2;
}

void BattleScene_SetCameraSubstate(s32 arg0, u16 arg1) {
    sBattleScene.unk_00->unk_30 = arg0;
    sBattleScene.unk_00->unk_2E = arg1;
}

void BattleScene_ApplyCameraPhaseDefaults(void) {
    if (sBattleScene.unk_00->unk_18 == 2) {
        if (sBattleScene.unk_00->unk_44 == 1) {
            BattleScene_SetCameraModeAndStep(1, 0x32);
        }

        if (sBattleScene.unk_00->unk_44 == 2) {
            sBattleScene.unk_00->unk_2C = sBattleScene.unk_00->unk_2A;
            BattleScene_SetCameraModeAndStep(2, 0);
        }
    }
}

void BattleScene_SetDamageShakeAmplitude(ActivePokemon* arg0) {
    BattleMon* ptr = &arg0->unk_724->pokemonPicked[arg0->state.unk_08];

    sBattleScene.unk_00->unk_68 = ((ptr->unk_02 - arg0->state.runtime.unk_0C) / 996.0f) * 1400.0f;

    if (sBattleScene.unk_00->unk_68 == 0.0f) {
        sBattleScene.unk_00->unk_68 = 0.0f;
    } else if (sBattleScene.unk_00->unk_68 <= 20.0f) {
        sBattleScene.unk_00->unk_68 = 20.0f;
    } else if (sBattleScene.unk_00->unk_68 >= 50.0f) {
        sBattleScene.unk_00->unk_68 = 50.0f;
    }

    sBattleScene.unk_00->unk_7A = 0;

    if (D_84390288 != 0) {
        sBattleScene.unk_00->unk_68 = 25.0f;
    }
}

void BattleScene_ApplyCameraShake(CameraNode* arg0) {
    UNUSED s32 pad;
    f32 sp30;
    f32 temp_fv0;
    s16 sp2A;
    s16 sp28;

    BattleAnim_CalculateDistanceAngles(&arg0->view.eyePosition, &arg0->view.targetPosition, &sp30, &sp28, &sp2A);
    sBattleScene.unk_00->unk_7A += 0x38E0;
    BattleAnim_ApproachF(&sBattleScene.unk_00->unk_68, 0.0f, 0.18f);

    temp_fv0 = COSS(sBattleScene.unk_00->unk_7A) * sBattleScene.unk_00->unk_68;

    arg0->view.eyePosition.y += temp_fv0 / 3.0f;
    arg0->view.targetPosition.y += temp_fv0 / 3.0f;
    arg0->view.eyePosition.x += temp_fv0 * SINS(sp2A + 0x4000);
    arg0->view.targetPosition.x += temp_fv0 * SINS(sp2A + 0x4000);
}

void BattleScene_StartCameraShake(UNUSED ActivePokemon* active_pokemon) {
    sBattleScene.unk_00->unk_68 = 30.0f;
    sBattleScene.unk_00->unk_7A = 0;
}

s32 BattleScene_IsCameraAngleSettled(s16 arg0, s16 arg1) {
    s16 temp_v1;
    s16 var_v1;

    temp_v1 = arg1 - arg0;
    var_v1 = arg1;
    if (temp_v1 > 0) {
        temp_v1 -= 0xE38;
        if (temp_v1 > 0) {
            var_v1 -= temp_v1;
        } else {
            var_v1 = arg1;
        }
    } else {
        temp_v1 += 0xE38;
        if (temp_v1 < 0) {
            var_v1 -= temp_v1;
        } else {
            var_v1 = arg1;
        }
    }

    if (var_v1 == arg1) {
        return 1;
    }
    return 0;
}

s32 BattleScene_ApproachCameraRoll(CameraNode* arg0, s16 arg1, s16 arg2) {
    if (arg1 > 0) {
        sBattleScene.unk_00->unk_58 -= arg1;
        if ((sBattleScene.unk_00->unk_58 < arg2) && ((arg2 - arg1) < sBattleScene.unk_00->unk_58)) {
            sBattleScene.unk_00->unk_58 = arg2;
            return 1;
        }
    } else {
        sBattleScene.unk_00->unk_58 -= arg1;
        if ((arg2 < sBattleScene.unk_00->unk_58) && (sBattleScene.unk_00->unk_58 < (arg2 - arg1))) {
            sBattleScene.unk_00->unk_58 = arg2;
            return 1;
        }
    }

    Camera_ComputeEyeFromAngles(&arg0->view.targetPosition, &arg0->view.eyePosition, sBattleScene.unk_00->unk_5C, sBattleScene.unk_00->unk_56,
                  sBattleScene.unk_00->unk_58);
    return 0;
}

s32 BattleScene_ApproachCameraRollNoEyeUpdate(UNUSED CameraNode* arg0, s16 arg1, s16 arg2) {
    sBattleScene.unk_00->unk_58 -= arg1;

    if (arg1 > 0) {
        if ((arg2 >= sBattleScene.unk_00->unk_58) && (sBattleScene.unk_00->unk_58 >= (arg2 - arg1))) {
            sBattleScene.unk_00->unk_58 = arg2;
            return 1;
        }
    } else if ((sBattleScene.unk_00->unk_58 >= arg2) && ((arg2 - arg1) >= sBattleScene.unk_00->unk_58)) {
        sBattleScene.unk_00->unk_58 = arg2;
        return 1;
    }
    return 0;
}

void BattleScene_SetCameraAnglesAndDistance(s16 arg0, s16 arg1, f32 arg2) {
    sBattleScene.unk_00->unk_56 = arg0;
    sBattleScene.unk_00->unk_58 = arg1;
    sBattleScene.unk_00->unk_5C = arg2;
}

void BattleScene_SetCameraSendOutShot(CameraNode* arg0, s32 arg1) {
    static u8 D_84385B60 = 0x5F;
    static u16 D_84385B64 = 0x38F;

    ActivePokemonState* sp6C;
    UNUSED s32 pad;
    ActivePokemon* temp_s0;
    Vec3f sp58;
    f32 sp54;
    UNUSED u16 pad2;
    UNUSED u8 pad3;
    u8 sp50;
    UNUSED u16 pad4;
    u16 sp4C;
    s32 idx = sBattleScene.unk_00->unk_2C == 0;

    sp6C = &sActivePokemon[idx]->state;
    sp50 = D_84385B60;
    sp4C = D_84385B64;
    temp_s0 = sActivePokemon[arg1 == 0];
    arg0->perspective.verticalFieldOfView = 60.0f;

    BattleScene_ResetCameraFrameCounter();
    BattleAnim_GetOwnerDefaultAnchorPosition(temp_s0, &sp58);

    sp58.y /= 3.0f;
    if (temp_s0->state.flags & 0x4000) {
        sp58.y = 0.0f;
    }

    BattleScene_SetCameraAtFromAnchor(temp_s0, arg0, sp58, 0, 0, 0.0f, 0.0f);

    if ((sp6C->unk_2D != 0x10) && !(sp6C->flags & 0x4000)) {
        BattleScene_EnterStateRow(temp_s0, 1);
    }

    temp_s0 = sActivePokemon[arg1];
    if (temp_s0->swayState.layoutConfig.unk_0C.x == 0.0f) {
        BattleAnim_GetOwnerDefaultAnchorPosition(temp_s0, &sp58);
    } else {
        BattleAnim_Vec3fCopy(&sp58, &temp_s0->swayState.layoutConfig.unk_0C);
        sp58.y += temp_s0->displayObject.position.y - BattleScene_GetParticipantModelHeight(temp_s0);
    }

    sp54 = BattleScene_ScaleCameraDistance(temp_s0, 3.0f, 300.0f);
    if ((BattleScene_ByteArrayContains(temp_s0->displayObject.objectType, &sp50, 1) != 0) && (arg1 == 1)) {
        BattleScene_SetCameraEyeFromPosition(arg0, sp58, 0, BattleScene_GetParticipantFacingAngle(temp_s0) - (temp_s0->unk_4B0 * 0x6AA4), sp54, 20.0f);
    } else if (BattleScene_ByteArrayContains(temp_s0->displayObject.objectType, (u8*)&sp4C, 2) != 0) {
        BattleScene_SetCameraEyeFromPosition(arg0, sp58, 0, BattleScene_GetParticipantFacingAngle(temp_s0) - (temp_s0->unk_4B0 * 0x6AA4), sp54, 20.0f);
    } else {
        BattleScene_SetCameraEyeFromPosition(arg0, sp58, 0, BattleScene_GetParticipantFacingAngle(temp_s0) - (temp_s0->unk_4B0 * 0x754E), sp54, 0.0f);
    }
}

void BattleScene_ClampCameraEyeFloor(CameraNode* arg0) {
    if (arg0->view.eyePosition.y <= 13.0f) {
        arg0->view.eyePosition.y = 13.0f;
    }
}

void BattleScene_UpdateCameraModelOffset(ActivePokemon* arg0, CameraNode* arg1) {
    SwayState* sp38 = &arg0->swayState;
    UNUSED s32 pad[5];
    f32 sp3C = 0.0f;

    if (BattleScene_ByteArrayContains(arg0->displayObject.objectType, &D_843845F0, 1) != 0) {
        sp3C = BattleAnim_GetOwnerModelHeight(arg0) / 1.5f;
    } else if (BattleScene_ByteArrayContains(arg0->displayObject.objectType, &D_843845F4, 1) != 0) {
        sp3C = BattleAnim_GetOwnerModelHeight(arg0) * 0.5f;
    } else if ((BattleScene_ByteArrayContains(arg0->displayObject.objectType, &D_843845F8, 1) != 0) && (arg0->state.flags & 0x200)) {
        sp3C = 2.0f * BattleAnim_GetOwnerModelHeight(arg0);
    } else if ((BattleScene_ByteArrayContains(arg0->displayObject.objectType, D_843845FC, 2) != 0) && (arg0->state.flags & 0x200)) {
        sp3C = BattleAnim_GetOwnerModelHeight(arg0) * 1.5f;
    }

    Vec3f_SetComponentsDuplicate(&arg0->swayState.unk_18, arg0->swayState.layoutConfig.unk_00.x, arg0->swayState.layoutConfig.unk_00.y,
                  arg0->swayState.layoutConfig.unk_00.z);
    arg0->swayState.unk_18.y = (arg0->displayObject.position.y - BattleScene_GetParticipantModelHeight(arg0)) + arg0->swayState.unk_18.y + sp3C;
    BattleAnim_Vec3fCopy(&sBattleScene.unk_00->unk_B8, &arg1->view.targetPosition);
    BattleAnim_Vec3fCopy(&sBattleScene.unk_00->unk_C4, &arg1->view.eyePosition);
    Vec3f_CalculateDistanceAngles(&sBattleScene.unk_00->unk_B8, &sBattleScene.unk_00->unk_C4, &sBattleScene.unk_00->unk_70, &sp38->unk_44,
                  &sp38->unk_46);
    Vec3f_CalculateDistanceAngles(&arg0->swayState.unk_18, &arg1->view.targetPosition, &sp38->unk_4C, &sp38->unk_44, &sp38->unk_46);
    sBattleScene.unk_00->unk_6C = 0.0f;
    sBattleScene.unk_00->unk_74 = 0.0f;
}

void BattleScene_ClearCameraOffsetVectors(void) {
    Vec3f_SetComponentsDuplicate(&sBattleScene.unk_00->unk_94, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&sBattleScene.unk_00->unk_A0, 0.0f, 0.0f, 0.0f);
}

void BattleScene_SetCameraAtFromAnchor(ActivePokemon* arg0, CameraNode* arg1, Vec3f arg2, s16 arg3, s16 arg4, f32 arg5, f32 arg6) {
    Camera_ComputeEyeFromAngles(&arg2, &arg1->view.targetPosition, arg5, arg3, arg4);
    arg1->view.targetPosition.y += arg6;
    arg1->view.targetPosition.y += BattleScene_GetParticipantEyeHeight(arg0);
}

void BattleScene_SetCameraAtFromPosition(CameraNode* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5) {
    Camera_ComputeEyeFromAngles(&arg1, &arg0->view.targetPosition, arg4, arg2, arg3);
    arg0->view.targetPosition.y += arg5;
}

void BattleScene_SetCameraEyeFromPosition(CameraNode* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5) {
    Camera_ComputeEyeFromAngles(&arg1, &arg0->view.eyePosition, arg4, arg2, arg3);
    arg0->view.eyePosition.y += arg5;
}

void BattleScene_SetCameraEyeFromAt(CameraNode* arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4) {
    Camera_ComputeEyeFromAngles(&arg0->view.targetPosition, &arg0->view.eyePosition, arg3, arg1, arg2);
    arg0->view.eyePosition.y += arg4;
}

void BattleScene_SetCameraEyeAndStoreAngles(CameraNode* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5) {
    BattleScene_SetCameraAnglesAndDistance(arg2, arg3, arg4);
    Camera_ComputeEyeFromAngles(&arg1, &arg0->view.eyePosition, arg4, arg2, arg3);
    arg0->view.eyePosition.y += arg5;
}

void BattleScene_SetCameraEyeAndStoreAnglesFromAt(CameraNode* arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4) {
    BattleScene_SetCameraAnglesAndDistance(arg1, arg2, arg3);
    Camera_ComputeEyeFromAngles(&arg0->view.targetPosition, &arg0->view.eyePosition, arg3, arg1, arg2);
    arg0->view.eyePosition.y += arg4;
}

void BattleScene_CameraHelperNop(UNUSED CameraNode* arg0) {
}

void BattleScene_SnapFloatPair(f32* arg0, f32* arg1) {
    f32 tmp;

    if (*arg0 != *arg1) {
        if (*arg1 < *arg0) {
            tmp = *arg0 - *arg1;
            if (tmp <= 1e-05) {
                *arg1 = *arg0;
            }
        } else {
            tmp = *arg1 - *arg0;
            if (tmp <= 1e-05) {
                *arg0 = *arg1;
            }
        }
    }
}

void BattleScene_ApplyOwnerFramingAdjustments(CameraNode* arg0, ActivePokemon* arg1, UNUSED f32 arg2) {
    SwayState* sp2C = &arg1->swayState;
    f32 var_fv1;
    Vec3f sp64;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;
    f32 sp3C;
    f32 temp_fv1;
    s16 sp36;
    s16 sp34;

    BattleAnim_Vec3fCopy(&sp4C, &arg0->view.targetPosition);
    BattleAnim_Vec3fCopy(&sp40, &arg0->view.targetPosition);
    BattleScene_GetOwnerCameraAnchor(arg1, &sp64);
    Vec3f_CalculateDistanceAngles(&sp64, &arg1->swayState.unk_18, &sp3C, &sp36, &sp34);

    switch (arg1->displayObject.objectType) {
        case 0x5F:
            arg0->perspective.verticalFieldOfView = 50.0f;
            return;

        case 0x82:
            arg0->perspective.verticalFieldOfView = 50.0f;
            if (sp3C < (BattleScene_GetParticipantModelRadius(arg1) * 0.5f)) {
                BattleAnim_Vec3fCopy(&sp64, &arg1->swayState.unk_18);
            }
            break;

        case 0x1D:
        case 0x29:
        case 0x32:
        case 0x33:
        case 0x5B:
            if (sp3C < (BattleScene_GetParticipantModelRadius(arg1) * 5.0f)) {
                BattleAnim_Vec3fCopy(&sp64, &arg1->swayState.unk_18);
            }
            break;

        case 0x12:
            if (sp3C < (BattleScene_GetParticipantModelRadius(arg1) * 1.5f)) {
                BattleAnim_Vec3fCopy(&sp64, &arg1->swayState.unk_18);
            }
            break;

        case 0x27:
        case 0x58:
        case 0x59:
        case 0x96:
            if (sp3C < BattleScene_GetParticipantModelRadius(arg1)) {
                BattleAnim_Vec3fCopy(&sp64, &arg1->swayState.unk_18);
            }
            break;

        case 0x4A:
        case 0x65:
        case 0x67:
            if (sp3C < (BattleScene_GetParticipantModelRadius(arg1) / 1.2f)) {
                BattleAnim_Vec3fCopy(&sp64, &arg1->swayState.unk_18);
            }
            break;

        case 0x7:
        case 0x11:
        case 0x16:
        case 0x4C:
        case 0x5C:
        case 0x83:
            if (sp3C < (BattleScene_GetParticipantModelRadius(arg1) / 3.0f)) {
                BattleAnim_Vec3fCopy(&sp64, &arg1->swayState.unk_18);
            }
            break;

        default:
            if (sp3C < (BattleScene_GetParticipantModelRadius(arg1) * 0.5f)) {
                BattleAnim_Vec3fCopy(&sp64, &arg1->swayState.unk_18);
            }
            break;
    }

    sp64.y = arg1->swayState.unk_18.y;
    Camera_ComputeEyeFromAngles(&sp64, &sp58, sp2C->unk_4C, sp2C->unk_44, sp2C->unk_46);
    sp4C.y = sp58.y;
    Vec3f_CalculateDistanceAngles(&sp4C, &sp58, &sp3C, &sp36, &sp34);

    switch (arg1->displayObject.objectType) {
        case GRIMER:
        case MUK:
        case JOLTEON:
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 50.0f);
            break;

        case FEAROW:
        case GOLEM:
        case MEWTWO:
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 1.5f);
            break;

        default:
            temp_fv1 = sp3C / BattleScene_GetParticipantModelRadius(arg1);
            if (temp_fv1 <= 0.1f) {
                var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 15.0f);
            } else if (temp_fv1 <= 0.2f) {
                var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 7.0f);
            } else if (temp_fv1 <= 0.3f) {
                var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 5.0f);
            } else if (temp_fv1 <= 0.4f) {
                var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 3.0f);
            } else if (temp_fv1 <= 0.5f) {
                var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 1.5f);
            } else {
                var_fv1 = sp3C / BattleScene_GetParticipantModelRadius(arg1);
            }
            break;
    }

    if (var_fv1 > 1.0f) {
        var_fv1 = 1.0f;
    }

    Camera_ComputeEyeFromAngles(&sp4C, &arg0->view.targetPosition, sp3C * var_fv1, 0, sp34);
    BattleScene_GetOwnerCameraAnchor(arg1, &sp64);
    Camera_ComputeEyeFromAngles(&sp64, &sp58, sp2C->unk_4C, sp2C->unk_44, sp2C->unk_46);

    sp3C = sp40.y - sp58.y;
    if (sp3C < 0.0f) {
        sp3C *= -1.0f;
    }

    if (arg1->animationFlags1 == 0xD) {
        var_fv1 = 0;
    } else if ((arg1->displayObject.objectType == GRIMER) || (arg1->displayObject.objectType == MUK)) {
        temp_fv1 = sp3C / BattleScene_GetParticipantModelRadius(arg1);
        if (temp_fv1 <= 0.05f) {
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 90.0f);
        } else if (temp_fv1 <= 0.1f) {
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 70.0f);
        } else if (temp_fv1 <= 0.2f) {
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 65.0f);
        } else if (temp_fv1 <= 0.3f) {
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 63.0f);
        } else {
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 45.0f);
        }
    } else {
        temp_fv1 = sp3C / BattleScene_GetParticipantModelRadius(arg1);
        if (temp_fv1 <= 0.05f) {
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 50.0f);
        } else if (temp_fv1 <= 0.1f) {
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 30.0f);
        } else if (temp_fv1 <= 0.2f) {
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 25.0f);
        } else if (temp_fv1 <= 0.3f) {
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 23.0f);
        } else {
            var_fv1 = sp3C / (BattleScene_GetParticipantModelRadius(arg1) * 15.0f);
        }
    }

    if (var_fv1 > 1.0f) {
        var_fv1 = 1.0f;
    }

    BattleAnim_ApproachF(&sp40.y, sp58.y, var_fv1);
    arg0->view.targetPosition.y = sp40.y;
    BattleScene_SnapFloatPair(&arg0->view.targetPosition.x, &arg0->view.eyePosition.x);
    BattleScene_SnapFloatPair(&arg0->view.targetPosition.y, &arg0->view.eyePosition.y);
    BattleScene_SnapFloatPair(&arg0->view.targetPosition.z, &arg0->view.eyePosition.z);
}

void BattleScene_RecomputeCameraDistance(CameraNode* arg0, ActivePokemon* arg1) {
    UNUSED s32 pad[5];
    f32 var_fv0_2;
    f32 sp44;
    s32 temp_lo;
    s16 sp3E;
    s16 sp3C;
    f32 sp38;
    s16 sp36;
    s16 sp34;
    u8 sp2C[] = { 0x2D, 0x35, 0x79, 0x2C, 0x6E };

    Vec3f_CalculateDistanceAngles(&sBattleScene.unk_00->unk_B8, &sBattleScene.unk_00->unk_C4, &sp38, &sp36, &sp34);
    Vec3f_CalculateDistanceAngles(&arg0->view.targetPosition, &arg0->view.eyePosition, &sp44, &sp3E, &sp3C);

    temp_lo = sp34 / 182;
    if ((temp_lo == 0x5A) || (temp_lo == -0x5A)) {
        if (BattleScene_ByteArrayContains(arg1->displayObject.objectType, sp2C, sizeof(sp2C)) != 0) {
            sp44 = sp38;
        } else {
            sp44 = Math_StepToF(sp44, sp38, 30.0f, 5.0f);
        }
    } else {
        var_fv0_2 = sBattleScene.unk_00->unk_70 - sp44;
        if (var_fv0_2 < 0.0f) {
            var_fv0_2 *= -1.0f;
        }

        if (sp44 < sp38) {
            sp44 = Math_StepToF(sp44, sBattleScene.unk_00->unk_70, var_fv0_2 * 0.4f, var_fv0_2 * 0.08f);
        }
    }
    Camera_ComputeEyeFromAngles(&arg0->view.targetPosition, &arg0->view.eyePosition, sp44, sp36, sp34);
}

void BattleScene_ReframeAndRecomputeDistance(CameraNode* arg0, ActivePokemon* arg1) {
    BattleScene_ApplyOwnerFramingAdjustments(arg0, arg1, 50.0f);
    BattleScene_RecomputeCameraDistance(arg0, arg1);
}

void BattleScene_ReframeAndRecomputeDistanceForSwitch(CameraNode* arg0, ActivePokemon* arg1) {
    BattleScene_ApplyOwnerFramingAdjustments(arg0, arg1, 90.0f);
    BattleScene_RecomputeCameraDistance(arg0, arg1);
}

void BattleScene_ApplyOwnerFramingOnly(CameraNode* arg0, ActivePokemon* arg1) {
    BattleScene_ApplyOwnerFramingAdjustments(arg0, arg1, 50.0f);
}

void BattleScene_UpdateCameraTargetFromOwner(CameraNode* arg0, ActivePokemon* arg1) {
    SwayState* ptr = &arg1->swayState;
    UNUSED s32 pad;
    Vec3f sp54;
    Vec3f sp48;
    Vec3f sp3C;
    f32 sp38;
    f32 var_fa0;
    s16 sp32;
    s16 sp30;

    BattleAnim_Vec3fCopy(&sp3C, &arg0->view.targetPosition);
    BattleScene_GetOwnerCameraAnchor(arg1, &sp54);
    Vec3f_CalculateDistanceAngles(&sp54, &arg1->swayState.unk_18, &sp38, &sp32, &sp30);

    if (sp38 < (BattleScene_GetParticipantModelRadius(arg1) * 1.1f)) {
        BattleAnim_Vec3fCopy(&sp54, &arg1->swayState.unk_18);
    }

    Camera_ComputeEyeFromAngles(&sp54, &sp48, ptr->unk_4C, ptr->unk_44, ptr->unk_46);
    Vec3f_CalculateDistanceAngles(&sp3C, &sp48, &sp38, &sp32, &sp30);

    var_fa0 = (sp38 / (BattleScene_GetParticipantModelRadius(arg1) * 80.0f)) * 3.0f;
    if (var_fa0 >= 1.0f) {
        var_fa0 = 1.0f;
    }

    Camera_ComputeEyeFromAngles(&sp3C, &arg0->view.targetPosition, sp38 * var_fa0, sp32, sp30);
}

s32 BattleScene_FrameCamera(CameraNode* arg0, ActivePokemon* arg1) {
    Vec3f sp84;
    UNUSED s32 pad[3];
    Vec3f sp6C;
    Vec3f sp60;
    UNUSED s32 pad2[3];
    s16 sp52;
    s16 sp50;
    s16 sp4E;
    s16 sp4C;
    UNUSED s32 pad3[2];
    BattleMonRuntime* temp_v1;

    temp_v1 = &sActivePokemon[BattleScene_GetParticipantSideIndex(arg1) == 0]->state.runtime;

    if (arg1->state.flags & 0x4000) {
        return 1;
    }

    if (temp_v1->usedMove == 0x53) {
        BattleScene_SelectCameraShot(arg1, arg0, 4);
        return 1;
    }

    BattleAnim_Vec3fCopy(&sp6C, &arg0->view.targetPosition);
    BattleAnim_Vec3fCopy(&sp60, &arg0->view.eyePosition);

    if ((arg1->displayObject.objectType != 0x5F) && (arg1->animationFlags1 != 0xD)) {
        BattleScene_UpdateCameraTargetFromOwner(arg0, arg1);
    }

    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sp84);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 3.5f, 300.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sp84, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F0, 0.0f);

    if (arg0->view.eyePosition.y <= 13.0f) {
        arg0->view.eyePosition.y = 13.0f;
    }

    BattleAnim_CalculateDistanceAngles(&sp84, &arg0->view.eyePosition, &D_843901F4, &sp4C, &sp50);
    BattleAnim_CalculateDistanceAngles(&sp84, &sp60, &D_843901F0, &sp4E, &sp52);
    BattleAnim_ApproachF(&D_843901F0, D_843901F4, 0.2f);
    BattleAnim_ApproachF(&sBattleScene.unk_00->unk_94.z, 0.2f, 0.03f);
    BattleAnim_StepToS16VariableRate(&sp52, sp50, sBattleScene.unk_00->unk_94.z);
    BattleAnim_StepToS16VariableRate(&sp4E, sp4C, sBattleScene.unk_00->unk_94.z);
    BattleScene_SetCameraEyeFromPosition(arg0, sp84, sp4E, sp52, D_843901F0, 0.0f);

    if ((sp4C == sp4E) && (sp50 == sp52)) {
        return 1;
    }
    return 0;
}

void BattleScene_ApproachCameraTargetFromOwner(CameraNode* arg0, ActivePokemon* arg1) {
    SwayState* ptr = &arg1->swayState;
    Vec3f sp58;
    Vec3f sp4C;
    UNUSED s32 pad[3];
    Vec3f sp34;
    f32 sp30;
    UNUSED s32 pad2[1];
    s16 sp2A;
    s16 sp28;

    BattleAnim_Vec3fCopy(&sp34, &arg0->view.targetPosition);
    BattleScene_GetOwnerCameraAnchor(arg1, &sp58);
    Camera_ComputeEyeFromAngles(&sp58, &sp4C, ptr->unk_4C, ptr->unk_44, ptr->unk_46);
    Vec3f_CalculateDistanceAngles(&sp34, &sp4C, &sp30, &sp2A, &sp28);
    sBattleScene.unk_00->unk_94.z = Math_StepToF(sBattleScene.unk_00->unk_94.z, 0.8f, 0.05f, 0.05f);
    Camera_ComputeEyeFromAngles(&sp34, &arg0->view.targetPosition, sBattleScene.unk_00->unk_94.z * sp30, sp2A, sp28);
}

void BattleScene_UpdateCameraVerticalFraming(CameraNode* arg0, ActivePokemon* arg1) {
    SwayState* ptr = &arg1->swayState;
    Vec3f sp60;
    Vec3f sp54;
    UNUSED s32 pad[3];
    Vec3f sp3C;
    UNUSED s32 pad2[3];

    BattleAnim_Vec3fCopy(&sp3C, &arg0->view.targetPosition);
    BattleScene_GetOwnerCameraAnchor(arg1, &sp60);
    Camera_ComputeEyeFromAngles(&sp60, &sp54, ptr->unk_4C, ptr->unk_44, ptr->unk_46);
    BattleAnim_ApproachF(&arg0->view.targetPosition.y, sp54.y, 0.1f);
    if (arg0->view.targetPosition.y < -10.0f) {
        arg0->view.targetPosition.y = -10.0f;
    }
    BattleAnim_ApproachF(&arg0->view.eyePosition.y, BattleAnim_GetOwnerModelHeight(arg1) * 4.0f, 0.04f);
}

void BattleScene_RecenterCameraOnOwner(CameraNode* arg0, ActivePokemon* arg1) {
    Vec3f sp74;
    Vec3f sp68;
    Vec3f sp5C;
    f32 sp58;
    s16 sp56;
    s16 sp54;
    s16 sp52;
    s16 sp50;
    s16 sp4E;
    s16 sp4C;

    BattleAnim_Vec3fCopy(&sp68, &arg0->view.targetPosition);
    BattleAnim_Vec3fCopy(&sp5C, &arg0->view.eyePosition);
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sp74);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 3.5f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sp74, 0, BattleScene_GetParticipantFacingAngle(arg1), 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sp74, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F0, 0.0f);
    BattleAnim_CalculateDistanceAngles(&arg0->view.targetPosition, &arg0->view.eyePosition, &D_843901F4, &sp4C, &sp50);
    BattleAnim_CalculateDistanceAngles(&sp68, &sp5C, &D_843901F0, &sp4E, &sp52);
    BattleAnim_ApproachF(&D_843901F0, D_843901F4, 0.05f);
    BattleAnim_StepToS16(&sp52, sp50, 0x108);
    BattleAnim_StepToS16(&sp4E, sp4C, 0xB6);
    BattleAnim_CalculateDistanceAngles(&sp68, &arg0->view.targetPosition, &sp58, &sp56, &sp54);
    Camera_ComputeEyeFromAngles(&sp68, &arg0->view.targetPosition, sp58 / 8, sp56, sp54);
    BattleScene_SetCameraEyeFromAt(arg0, sp4E, sp52, D_843901F0, 0.0f);
}

void BattleScene_ApproachCameraTarget(CameraNode* arg0, ActivePokemon* arg1, UNUSED s32 arg2) {
    SwayState* ptr = &arg1->swayState;
    Vec3f sp50;
    Vec3f sp44;
    Vec3f sp38;
    f32 sp34;
    s16 sp32;
    s16 sp30;
    UNUSED s32 pad;

    BattleScene_GetOwnerCameraAnchor(arg1, &sp50);
    BattleAnim_Vec3fCopy(&sp38, &arg0->view.targetPosition);
    Camera_ComputeEyeFromAngles(&sp50, &sp44, ptr->unk_4C, ptr->unk_44, ptr->unk_46);
    BattleAnim_CalculateDistanceAngles(&sp38, &sp44, &sp34, &sp32, &sp30);
    Camera_ComputeEyeFromAngles(&sp38, &arg0->view.targetPosition, sp34 * 0.1f, sp32, sp30);
}

void BattleScene_ApproachCameraZoom(CameraNode* arg0, ActivePokemon* arg1) {
    s16 sp26;
    s16 sp24;

    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 8.0f, 500.0f);
    BattleAnim_CalculateDistanceAngles(&arg0->view.targetPosition, &arg0->view.eyePosition, &D_843901F4, &sp26, &sp24);
    BattleAnim_ApproachF(&D_843901F4, D_843901F0, 0.03f);
    BattleAnim_StepToS16(&sp26, 0xE38, 0x5B);
    BattleScene_SetCameraEyeFromAt(arg0, sp26, sp24, D_843901F4, 0.0f);
}

s32 BattleScene_ApproachCloseCameraShot(CameraNode* arg0, ActivePokemon* arg1) {
    Vec3f sp3C;
    Vec3f sp30;
    f32 sp2C;
    s16 sp2A;
    s16 sp28;

    BattleAnim_Vec3fCopy(&sp3C, &arg0->view.targetPosition);
    BattleAnim_Vec3fCopy(&sp30, &arg0->view.eyePosition);
    BattleScene_CameraShotTargetClose(arg0, arg1);
    Vec3f_CalculateDistanceAngles(&sp30, &arg0->view.eyePosition, &sp2C, &sp28, &sp2A);
    Camera_ComputeEyeFromAngles(&sp30, &arg0->view.eyePosition, sp2C / 2, sp28, sp2A);
    BattleAnim_Vec3fCopy(&arg0->view.targetPosition, &sp3C);

    if (sp2C <= 0.5f) {
        return 1;
    }
    return 0;
}

s32 BattleScene_AnimateCameraPreset(CameraNode* arg0, ActivePokemon* arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad;
    Vec3f sp60;
    Vec3f sp54;
    Vec3f sp48;
    Vec3f sp3C;
    f32 sp38;
    f32 sp34;
    s16 sp32;
    s16 sp30;

    if (D_843901B0.unk_3C != 200.0f) {
        arg0->perspective.verticalFieldOfView = D_843901B0.unk_3C;
    } else if (arg3 == 1) {
        BattleAnim_ApproachF(&arg0->perspective.verticalFieldOfView, 30.0f, 0.06f);
    } else {
        arg0->perspective.verticalFieldOfView = 30.0f;
    }

    BattleAnim_ApproachF(&sBattleScene.unk_00->unk_94.z, D_843901B0.unk_34, D_843901B0.unk_38);
    Camera_ComputeEyeFromAngles(&D_843901B0.unk_00, &sp54, D_843901B0.unk_30, D_843901B0.unk_26, D_843901B0.unk_28);
    BattleAnim_Vec3fCopy(&sp48, &arg0->view.eyePosition);
    BattleAnim_CalculateDistanceAngles(&sp48, &sp54, &sp38, &sp32, &sp30);
    Camera_ComputeEyeFromAngles(&sp48, &arg0->view.eyePosition, sBattleScene.unk_00->unk_94.z * sp38, sp32, sp30);
    Camera_ComputeEyeFromAngles(&D_843901B0.unk_00, &sp3C, D_843901B0.unk_2C, D_843901B0.unk_20, D_843901B0.unk_22);

    if (arg2 == 1) {
        sp3C.y += BattleScene_GetParticipantEyeHeight(arg1);
    }

    BattleAnim_Vec3fCopy(&sp60, &arg0->view.targetPosition);
    BattleAnim_CalculateDistanceAngles(&sp60, &sp3C, &sp34, &sp32, &sp30);
    Camera_ComputeEyeFromAngles(&sp60, &arg0->view.targetPosition, sBattleScene.unk_00->unk_94.z * sp34, sp32, sp30);

    if ((sp38 <= 1.75f) && (sp34 <= 1.75f)) {
        return 1;
    }
    return 0;
}

s32 BattleScene_AnimateCameraPresetToOwner(CameraNode* arg0, ActivePokemon* arg1) {
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;
    Vec3f sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 var_fa1;
    s16 sp36;
    s16 sp34;

    if (D_843901B0.unk_3C != 200.0f) {
        arg0->perspective.verticalFieldOfView = D_843901B0.unk_3C;
    } else {
        arg0->perspective.verticalFieldOfView = 30.0f;
    }

    BattleAnim_ApproachF(&sBattleScene.unk_00->unk_94.z, D_843901B0.unk_34, D_843901B0.unk_38);
    BattleScene_GetOwnerCameraAnchor(arg1, &sp6C);
    Vec3f_CalculateDistanceAngles(&D_843901B0.unk_00, &sp6C, &sp44, &sp36, &sp34);

    var_fa1 = sp44 / (BattleScene_GetParticipantModelRadius(arg1) * 40.0f);
    if (var_fa1 >= 0.6f) {
        var_fa1 = 1.0f;
    }

    sp44 *= var_fa1;
    sp44 += D_843901B0.unk_30;

    Camera_ComputeEyeFromAngles(&D_843901B0.unk_00, &sp60, sp44, D_843901B0.unk_26, D_843901B0.unk_28);
    BattleAnim_Vec3fCopy(&sp54, &arg0->view.eyePosition);
    BattleAnim_CalculateDistanceAngles(&sp54, &sp60, &sp40, &sp36, &sp34);
    Camera_ComputeEyeFromAngles(&sp54, &arg0->view.eyePosition, sBattleScene.unk_00->unk_94.z * sp40, sp36, sp34);
    BattleScene_GetOwnerCameraAnchor(arg1, &sp6C);
    Vec3f_CalculateDistanceAngles(&D_843901B0.unk_00, &sp6C, &sp44, &sp36, &sp34);

    var_fa1 = sp44 / (BattleScene_GetParticipantModelRadius(arg1) * 40.0f);
    if (var_fa1 >= 0.6f) {
        var_fa1 = 1;
    }
    sp44 *= var_fa1;
    sp44 += D_843901B0.unk_2C;

    Camera_ComputeEyeFromAngles(&D_843901B0.unk_00, &sp48, sp44, D_843901B0.unk_20, D_843901B0.unk_22);
    sp48.y += BattleScene_GetParticipantEyeHeight(arg1);
    BattleAnim_Vec3fCopy(&sp6C, &arg0->view.targetPosition);
    BattleAnim_CalculateDistanceAngles(&sp6C, &sp48, &sp3C, &sp36, &sp34);
    Camera_ComputeEyeFromAngles(&sp6C, &arg0->view.targetPosition, sBattleScene.unk_00->unk_94.z * sp3C, sp36, sp34);

    if ((sp40 <= 1.0f) && (sp3C <= 1.0f)) {
        return 1;
    }
    return 0;
}

void BattleScene_CameraPresetNop(UNUSED CameraNode* arg0) {
    if (arg0) {}
}

void BattleScene_ApplyCameraPreset(CameraNode* arg0, ActivePokemon* arg1, s32 arg2) {
    BattleScene_SetCameraAtFromPosition(arg0, D_843901B0.unk_00, D_843901B0.unk_0C, D_843901B0.unk_0E, D_843901B0.unk_18, 0.0f);
    if (arg2 == 1) {
        arg0->view.targetPosition.y += BattleScene_GetParticipantEyeHeight(arg1);
        BattleScene_SetCameraEyeFromPosition(arg0, arg0->view.targetPosition, D_843901B0.unk_12, D_843901B0.unk_14, D_843901B0.unk_1C, 0.0f);
    } else {
        BattleScene_SetCameraEyeFromPosition(arg0, D_843901B0.unk_00, D_843901B0.unk_12, D_843901B0.unk_14, D_843901B0.unk_1C, 0.0f);
    }
}

void BattleScene_SetCameraPresetAtAngles(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_843901B0.unk_0C = arg0;
    D_843901B0.unk_0E = arg1;
    D_843901B0.unk_20 = arg2;
    D_843901B0.unk_22 = arg3;
}

void BattleScene_SetCameraPresetAtDistances(f32 arg0, f32 arg1) {
    D_843901B0.unk_18 = arg0;
    D_843901B0.unk_2C = arg1;
}

void BattleScene_SetCameraPresetEyeAngles(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_843901B0.unk_12 = arg0;
    D_843901B0.unk_14 = arg1;
    D_843901B0.unk_26 = arg2;
    D_843901B0.unk_28 = arg3;
}

void BattleScene_SetCameraPresetEyeDistances(f32 arg0, f32 arg1) {
    D_843901B0.unk_1C = arg0;
    D_843901B0.unk_30 = arg1;
}

void BattleScene_SetCameraPresetSmoothing(f32 arg0, f32 arg1) {
    D_843901B0.unk_34 = arg0;
    D_843901B0.unk_38 = arg1;
}

void BattleScene_LoadCameraPreset(unk_D_86B0C160* arg0, CameraNode* arg1, ActivePokemon* arg2) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 temp_fv1;
    UNUSED s16 pad;
    s16 sp20;

    BattleScene_ClearCameraOffsetVectors();
    if (arg0->unk_30 != 200.0f) {
        temp_fv1 = arg0->unk_30;
        D_843901B0.unk_3C = temp_fv1;
        arg1->perspective.verticalFieldOfView = temp_fv1;
    } else {
        D_843901B0.unk_3C = arg0->unk_30;
    }

    sp34 = BattleScene_ScaleCameraDistance(arg2, arg0->unk_0C, 500.0f);
    sp30 = BattleScene_ScaleCameraDistance(arg2, arg0->unk_20, 500.0f);
    sp2C = BattleScene_ScaleCameraDistance(arg2, arg0->unk_10, 500.0f);
    sp28 = BattleScene_ScaleCameraDistance(arg2, arg0->unk_24, 500.0f);
    sp20 = BattleScene_GetParticipantFacingAngle(arg2);

    BattleScene_SetCameraPresetAtAngles(arg0->unk_00, sp20 - (arg0->unk_02 * arg2->unk_4B0), arg0->unk_14,
                  BattleScene_GetParticipantFacingAngle(arg2) - (arg0->unk_16 * arg2->unk_4B0));
    BattleScene_SetCameraPresetAtDistances(sp34, sp30);
    sp20 = BattleScene_GetParticipantFacingAngle(arg2);
    BattleScene_SetCameraPresetEyeAngles(arg0->unk_06, sp20 - (arg0->unk_08 * arg2->unk_4B0), arg0->unk_1A,
                  BattleScene_GetParticipantFacingAngle(arg2) - (arg0->unk_1C * arg2->unk_4B0));
    BattleScene_SetCameraPresetEyeDistances(sp2C, sp28);
    BattleScene_SetCameraPresetSmoothing(arg0->unk_28, arg0->unk_2C);
}

void BattleScene_LoadCameraPresetUnscaled(unk_D_86B0C160* arg0, CameraNode* arg1) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 tmp;

    BattleScene_ClearCameraOffsetVectors();

    if (arg0->unk_30 != 200.0f) {
        tmp = arg0->unk_30;
        D_843901B0.unk_3C = tmp;
        arg1->perspective.verticalFieldOfView = tmp;
    } else {
        D_843901B0.unk_3C = arg0->unk_30;
    }

    sp2C = arg0->unk_0C;
    sp28 = arg0->unk_20;
    sp24 = arg0->unk_10;
    sp20 = arg0->unk_24;

    BattleScene_SetCameraPresetAtAngles(arg0->unk_00, arg0->unk_02, arg0->unk_14, arg0->unk_16);
    BattleScene_SetCameraPresetAtDistances(sp2C, sp28);
    BattleScene_SetCameraPresetEyeAngles(arg0->unk_06, arg0->unk_08, arg0->unk_1A, arg0->unk_1C);
    BattleScene_SetCameraPresetEyeDistances(sp24, sp20);
    BattleScene_SetCameraPresetSmoothing(arg0->unk_28, arg0->unk_2C);
}

s32 BattleScene_AnimateCameraIntro(CameraNode* arg0, ActivePokemon* arg1) {
    Vec3f sp64;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;
    Vec3f sp34;
    f32 sp30;
    UNUSED s32 pad;
    s16 sp2A;
    s16 sp28;

    BattleAnim_ApproachF(&arg0->perspective.verticalFieldOfView, 30.0f, 0.06f);
    Vec3f_SetComponentsDuplicate(&sp64, arg1->unk_4B0 * -150.0f, 5.0f, 0.0f);
    BattleAnim_ApproachF(&sBattleScene.unk_00->unk_94.z, 0.2f, 0.06f);
    Camera_ComputeEyeFromAngles(&sp64, &sp4C, 100.0f, 0, BattleScene_GetParticipantFacingAngle(arg1));
    BattleAnim_Vec3fCopy(&sp40, &arg0->view.eyePosition);
    BattleAnim_CalculateDistanceAngles(&sp40, &sp4C, &sp30, &sp2A, &sp28);
    Camera_ComputeEyeFromAngles(&sp40, &arg0->view.eyePosition, sBattleScene.unk_00->unk_94.z * sp30, sp2A, sp28);
    Camera_ComputeEyeFromAngles(&sp64, &sp34, 0.0f, 0, BattleScene_GetParticipantFacingAngle(arg1));
    BattleAnim_Vec3fCopy(&sp58, &arg0->view.targetPosition);
    BattleAnim_CalculateDistanceAngles(&sp58, &sp34, &sp30, &sp2A, &sp28);

    if (sp30 >= 1.0f) {
        Camera_ComputeEyeFromAngles(&sp58, &arg0->view.targetPosition, sBattleScene.unk_00->unk_94.z * sp30, sp2A, sp28);
        return 0;
    }
    return 1;
}

s32 BattleScene_AreActivePokemonHeightsSeparated(UNUSED CameraNode* arg0) {
    Vec3f sp2C;
    Vec3f sp20;
    f32 var_fv0;

    BattleAnim_GetOwnerDefaultAnchorPosition(sActivePokemon[0], &sp2C);
    BattleAnim_GetOwnerDefaultAnchorPosition(sActivePokemon[1], &sp20);

    var_fv0 = sp2C.y - sp20.y;
    if (sp2C.y < sp20.y) {
        var_fv0 *= -1.0f;
    }

    if (var_fv0 > 35.0f) {
        return 1;
    }
    return 0;
}

void BattleScene_SetCameraActivePokemonHeightShot(CameraNode* arg0, s32 arg1) {
    UNUSED s32 pad;
    Vec3f sp60;
    Vec3f sp54;
    Vec3f sp48;
    ActivePokemon* sp40;

    BattleScene_ClearCameraOffsetVectors();
    arg0->perspective.verticalFieldOfView = 30.0f;

    sp40 = sActivePokemon[arg1];
    BattleAnim_GetOwnerDefaultAnchorPosition(sp40, &sp60);
    BattleScene_SetCameraEyeFromPosition(arg0, sp60, 0, sp40->unk_4B0 << 0xE, 100.0f, 0.0f);
    BattleAnim_GetOwnerDefaultAnchorPosition(sActivePokemon[arg1], &sp54);

    BattleAnim_GetOwnerDefaultAnchorPosition(sActivePokemon[arg1 == 0], &sp48);
    sp40 = sActivePokemon[arg1 == 0];
    BattleAnim_GetOwnerDefaultAnchorPosition(sp40, &sp60);

    if (sp48.y < sp54.y) {
        sp60.y = sp54.y * 1.8f;
        BattleScene_SetCameraAtFromAnchor(sp40, arg0, sp60, 0, 0, 0, 0);
    } else {
        sp60.y = 0.0f;
        BattleScene_SetCameraAtFromAnchor(sp40, arg0, sp60, 0, 0, 0, 0);
    }
}

s32 BattleScene_ApproachCameraActivePokemonHeightShot(CameraNode* arg0, s32 arg1) {
    UNUSED s32 pad;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;
    Vec3f sp34;
    f32 sp30;
    s16 sp2E;
    s16 sp2C;

    BattleAnim_ApproachF(&sBattleScene.unk_00->unk_94.z, 0.1f, 0.05f);
    BattleAnim_GetOwnerDefaultAnchorPosition(sActivePokemon[arg1], &sp40);
    BattleAnim_GetOwnerDefaultAnchorPosition(sActivePokemon[!arg1], &sp34);

    if (sp34.y < sp40.y) {
        BattleAnim_GetOwnerDefaultAnchorPosition(sActivePokemon[!arg1], &sp4C);
    } else {
        BattleAnim_GetOwnerDefaultAnchorPosition(sActivePokemon[!arg1], &sp4C);
        sp4C.y *= 1.3f;
    }

    BattleAnim_Vec3fCopy(&sp58, &arg0->view.targetPosition);
    BattleAnim_CalculateDistanceAngles(&sp58, &sp4C, &sp30, &sp2E, &sp2C);
    Camera_ComputeEyeFromAngles(&sp58, &arg0->view.targetPosition, sBattleScene.unk_00->unk_94.z * sp30, sp2E, sp2C);

    if (sp30 <= 1.0f) {
        return 1;
    }
    return 0;
}

void BattleScene_SetCameraOwnerShot(CameraNode* arg0, ActivePokemon* arg1) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);

    sBattleScene.unk_00->unk_D0.x = BattleScene_GetParticipantModelXOffset(arg1);
    sBattleScene.unk_00->unk_D0.z = 0.0f;

    if (arg1->state.runtime.moveCache.lastMove == WITHDRAW) {
        D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 4.5f, 300.0f);
        if (D_843901F0 <= 100.0f) {
            D_843901F0 = 100.0f;
        }

        if (sBattleScene.unk_00->unk_D0.y < 20.0f) {
            sBattleScene.unk_00->unk_D0.y = 20.0f;
        }
    } else {
        D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 3.5f, 300.0f);
    }

    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F0, 0.0f);
}

void BattleScene_SetCameraOwnerWideShot(CameraNode* arg0, ActivePokemon* arg1) {
    f32 sp3C;

    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    sp3C = BattleScene_ScaleCameraDistance(arg1, 8.0f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromAt(arg0, 0, arg1->unk_4B0 << 0xE, sp3C, 0.0f);
}

void BattleScene_SetCameraPresetClose(CameraNode* arg0, ActivePokemon* arg1, s32 arg2) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 0.5f, 100.0f);
    D_843901F4 = BattleScene_ScaleCameraDistance(arg1, 5.0f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F0, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1) - (arg1->unk_4B0 * 0x31C7), D_843901F4, 0.0f);

    if (arg2 == 1) {
        BattleScene_UpdateCameraModelOffset(arg1, arg0);
    } else {
        BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
        BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
    }

    BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
}

void BattleScene_SetCameraPresetAngledClose(CameraNode* arg0, ActivePokemon* arg1, s32 arg2) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 0.5f, 100.0f);
    D_843901F4 = BattleScene_ScaleCameraDistance(arg1, 5.0f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F0, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0x71C, BattleScene_GetParticipantFacingAngle(arg1) - (arg1->unk_4B0 * 0x1555), D_843901F4,
                  0.0f);
    if (arg2 == 1) {
        BattleScene_UpdateCameraModelOffset(arg1, arg0);
    } else {
        BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
        BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
    }
    BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
}

void BattleScene_SetCameraPresetOffsetClose(CameraNode* arg0, ActivePokemon* arg1, s32 arg2) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 0.5f, 100.0f);
    D_843901F4 = BattleScene_ScaleCameraDistance(arg1, 5.0f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F0, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0xE38, BattleScene_GetParticipantFacingAngle(arg1), D_843901F4, 0.0f);
    if (arg2 == 1) {
        BattleScene_UpdateCameraModelOffset(arg1, arg0);
    } else {
        BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
        BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
    }
    BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
}

void BattleScene_SetCameraPresetLowClose(CameraNode* arg0, ActivePokemon* arg1, s32 arg2) {
    UNUSED s32 pad[4];
    s16 sp3E;

    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 0.5f, 100.0f);
    D_843901F4 = BattleScene_ScaleCameraDistance(arg1, 5.0f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F0, 0.0f);
    sp3E = BattleScene_GetParticipantFacingAngle(arg1);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0, sp3E - (arg1->unk_4B0 * 0x1555), D_843901F4,
                  -BattleAnim_GetOwnerModelHeight(arg1) * 0.8);
    if (arg2 == 1) {
        BattleScene_UpdateCameraModelOffset(arg1, arg0);
    } else {
        BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
        BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
    }
    BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
}

void BattleScene_SetCameraPresetWide(CameraNode* arg0, ActivePokemon* arg1, s32 arg2) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 3.5f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F0, 0.0f);
    if (arg2 == 1) {
        BattleScene_UpdateCameraModelOffset(arg1, arg0);
    } else {
        BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
        BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
    }
    BattleScene_ReframeAndRecomputeDistance(arg0, arg1);
}

void BattleScene_SetCameraPresetWideStatic(CameraNode* arg0, ActivePokemon* arg1, s32 arg2) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 3.5f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F0, 0.0f);
    if (arg2 == 1) {
        BattleScene_UpdateCameraModelOffset(arg1, arg0);
    }
}

void BattleScene_SetCameraPresetFromTable(CameraNode* arg0, ActivePokemon* arg1, s32 arg2, s32 arg3) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &D_843901B0.unk_00);
    BattleScene_LoadCameraPreset(&D_843849C0[arg2], arg0, arg1);
    BattleScene_ApplyCameraPreset(arg0, arg1, 1);
    BattleScene_CameraPresetNop(arg0);
    if (arg3 == 1) {
        BattleScene_UpdateCameraModelOffset(arg1, arg0);
    }
}

void BattleScene_CameraShotTargetStandard(CameraNode* arg0, ActivePokemon* arg1) {
    BattleScene_ClearCameraOffsetVectors();
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 5.0f, 400.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, arg1->unk_4B0 << 0xE, 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0, arg1->unk_4B0 * 0xE38, D_843901F0, 0.0f);
    BattleScene_UpdateCameraModelOffset(arg1, arg0);
}

void BattleScene_CameraShotTargetAngled(CameraNode* arg0, ActivePokemon* arg1) {
    BattleScene_ClearCameraOffsetVectors();
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 5.0f, 400.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, arg1->unk_4B0 << 0xE, 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0x1555, arg1->unk_4B0 * 0xE38, D_843901F0, 0.0f);
    BattleScene_UpdateCameraModelOffset(arg1, arg0);
}

void BattleScene_CameraShotTargetHigh(CameraNode* arg0, ActivePokemon* arg1) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 5.0f, 400.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, arg1->unk_4B0 << 0xE, 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0, arg1->unk_4B0 * 0xE38, D_843901F0, 2.0f * BattleAnim_GetOwnerModelHeight(arg1));
    BattleScene_UpdateCameraModelOffset(arg1, arg0);
}

void BattleScene_CameraShotTargetLow(CameraNode* arg0, ActivePokemon* arg1) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 5.0f, 400.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, arg1->unk_4B0 << 0xE, 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0, arg1->unk_4B0 * 0xE38, D_843901F0, -BattleAnim_GetOwnerModelHeight(arg1) * 0.8f);
    if (arg0->view.eyePosition.y <= 15.0f) {
        arg0->view.eyePosition.y = 15.0f;
    }
    BattleScene_UpdateCameraModelOffset(arg1, arg0);
}

void BattleScene_CameraShotTargetClose(CameraNode* arg0, ActivePokemon* arg1) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 3.5f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F0, 0.0f);
    BattleScene_UpdateCameraModelOffset(arg1, arg0);
}

void BattleScene_SetCameraFollowPresetNear(CameraNode* arg0, ActivePokemon* arg1, s32 arg2) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 3.5f, 300.0f);
    D_843901F4 = BattleScene_ScaleCameraDistance(arg1, 0.5f, 100.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F4, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1) - (arg1->unk_4B0 * 0x1555), D_843901F0, 0.0f);
    if (arg2 == 1) {
        BattleScene_UpdateCameraModelOffset(arg1, arg0);
    }
}

void BattleScene_SetCameraOwnerStandardShot(CameraNode* arg0, ActivePokemon* arg1) {
    BattleAnim_GetOwnerDefaultAnchorPosition(arg1, &sBattleScene.unk_00->unk_D0);
    D_843901F0 = BattleScene_ScaleCameraDistance(arg1, 3.5f, 300.0f);
    BattleScene_SetCameraAtFromAnchor(arg1, arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), 0.0f, 0.0f);
    BattleScene_SetCameraEyeFromPosition(arg0, sBattleScene.unk_00->unk_D0, 0, BattleScene_GetParticipantFacingAngle(arg1), D_843901F0, 0.0f);
    BattleScene_UpdateCameraModelOffset(arg1, arg0);
}

void BattleScene_SelectCameraPreset(ActivePokemon* arg0, CameraNode* arg1, s32 arg2, s32 arg3) {
    BattleScene_ClearCameraOffsetVectors();
    switch (arg2) {
        case 0:
            BattleScene_SetCameraPresetWide(arg1, arg0, arg3);
            break;

        case 1:
            BattleScene_SetCameraPresetWideStatic(arg1, arg0, arg3);
            break;

        case 2:
            BattleScene_SetCameraPresetClose(arg1, arg0, arg3);
            break;

        case 3:
            BattleScene_SetCameraPresetOffsetClose(arg1, arg0, arg3);
            break;

        case 4:
            BattleScene_SetCameraPresetFromTable(arg1, arg0, 0, arg3);
            break;

        case 5:
            BattleScene_SetCameraPresetFromTable(arg1, arg0, 1, arg3);
            break;

        case 6:
            BattleScene_SetCameraPresetAngledClose(arg1, arg0, arg3);
            break;

        case 7:
            BattleScene_SetCameraPresetLowClose(arg1, arg0, arg3);
            break;

        case 8:
            BattleScene_SetCameraPresetFromTable(arg1, arg0, 2, arg3);
            break;

        case 9:
            BattleScene_SetCameraPresetFromTable(arg1, arg0, 3, arg3);
            break;

        case 10:
            BattleScene_SetCameraPresetFromTable(arg1, arg0, 4, arg3);
            break;

        case 11:
            BattleScene_SetCameraPresetFromTable(arg1, arg0, 5, arg3);
            break;

        default:
            BattleScene_SetCameraPresetClose(arg1, arg0, arg3);
            break;
    }
}

void BattleScene_SelectCameraFollowPreset(ActivePokemon* arg0, CameraNode* arg1, s32 arg2) {
    BattleScene_ClearCameraOffsetVectors();
    switch (arg2) {
        case 0:
            BattleScene_SetCameraPresetClose(arg1, arg0, 1);
            break;
        case 1:
            BattleScene_SetCameraPresetAngledClose(arg1, arg0, 1);
            break;
        case 2:
            BattleScene_SetCameraPresetLowClose(arg1, arg0, 1);
            break;
        case 3:
            BattleScene_SetCameraPresetWide(arg1, arg0, 1);
            break;
        case 4:
            BattleScene_SetCameraFollowPresetNear(arg1, arg0, 1);
            break;
        default:
            BattleScene_SetCameraPresetClose(arg1, arg0, 1);
            break;
    }
}

void BattleScene_SelectCameraShot(ActivePokemon* arg0, CameraNode* arg1, s32 arg2) {
    BattleScene_ClearCameraOffsetVectors();
    switch (arg2) {
        case 0:
            BattleScene_CameraShotTargetStandard(arg1, arg0);
            break;

        case 1:
            BattleScene_CameraShotTargetHigh(arg1, arg0);
            break;

        case 2:
            BattleScene_CameraShotTargetLow(arg1, arg0);
            break;

        case 3:
            BattleScene_CameraShotTargetClose(arg1, arg0);
            break;

        case 4:
            BattleScene_CameraShotTargetAngled(arg1, arg0);
            break;

        case 5:
            BattleScene_CameraShotTargetHigh(arg1, arg0);
            break;

        case 6:
            BattleScene_CameraShotTargetLow(arg1, arg0);
            break;

        case 7:
            BattleScene_CameraShotTargetClose(arg1, arg0);
            break;

        default:
            BattleScene_CameraShotTargetClose(arg1, arg0);
            break;
    }
}
