#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/matrix.h"

typedef struct unk_D_843859E0 {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ f32 unk_0C;
} unk_D_843859E0; // size = 0x10

static unk_D_843859E0 D_843859E0[] = {
    {
        0x00,
        2002.1199951171875f,
        1367,
        -20914,
        50.0f,
    },
    {
        0x01,
        1693.1199951171875f,
        183,
        -11871,
        50.0f,
    },
    {
        0x02,
        1934.97998046875f,
        1217,
        8182,
        50.0f,
    },
    {
        0x03,
        1733.780029296875f,
        397,
        6520,
        50.0f,
    },
    {
        0x04,
        1102.3900146484375f,
        1577,
        -3562,
        50.0f,
    },
    {
        0x05,
        1425.7900390625f,
        2285,
        -5775,
        50.0f,
    },
    {
        0x06,
        871.3599853515625f,
        1825,
        -8898,
        50.0f,
    },
    {
        0x07,
        1170.8199462890625f,
        4982,
        -6725,
        50.0f,
    },
    {
        0x11,
        1645.5699462890625f,
        7861,
        -122,
        50.0f,
    },
    {
        0x01,
        1741.530029296875f,
        6993,
        -6029,
        50.0f,
    },
    {
        0x06,
        1608.3199462890625f,
        6419,
        -16201,
        50.0f,
    },
    {
        0x00,
        1122.8599853515625f,
        2584,
        -14668,
        50.0f,
    },
    {
        0x00,
        1667.239990234375f,
        5360,
        4438,
        50.0f,
    },
    {
        0x00,
        1315.9599609375f,
        3001,
        -7883,
        50.0f,
    },
    {
        0x00,
        1575.4300537109375f,
        5834,
        10901,
        50.0f,
    },
    {
        0x00,
        719.8599853515625f,
        3047,
        -16384,
        50.0f,
    },
    {
        0x00,
        939.3900146484375f,
        2300,
        0,
        50.0f,
    },
    {
        0x01,
        560.239990234375f,
        773,
        -8863,
        50.0f,
    },
    {
        0x01,
        2002.1199951171875f,
        1367,
        -20914,
        30.0f,
    },
    {
        0x01,
        2002.1199951171875f,
        1367,
        -20914,
        30.0f,
    },
};

s32 BattleScene_AreBothParticipantModelsCompact(void) {
    if (((BattleScene_GetParticipantModelWidth(D_84390010[0]) + BattleScene_GetParticipantModelWidth(D_84390010[1])) <= 85.0f) &&
        (BattleScene_GetParticipantModelHeight(D_84390010[0]) == 0.0f) && (BattleScene_GetParticipantModelHeight(D_84390010[1]) == 0.0f) &&
        (D_84390010[0]->unk_000.position.y == 0.0f) && (D_84390010[1]->unk_000.position.y == 0.0f)) {
        return 1;
    }
    return 0;
}

s32 BattleScene_SkipIntroIfFainted(UNUSED Battler* arg0, unk_D_86002F34_00C* arg1) {
    BattlerState* ptr = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;

    if ((ptr->unk_2D == 0x10) || ((ptr->unk_34 & 0x4000) != 0)) {
        BattleScene_SelectNextIntroCameraShot(arg1);
        return 1;
    }
    return 0;
}

s32 BattleScene_IsEitherBattlerFainted(UNUSED Battler* arg0, UNUSED unk_D_86002F34_00C* arg1) {
    BattlerState* ptr = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;
    s32 idx = gBattleScene.unk_00->unk_2C == 0;
    BattlerState* ptr2 = &D_84390010[idx]->unk_654;

    if ((ptr->unk_34 & 0x4000) || (ptr2->unk_34 & 0x4000)) {
        return 1;
    }
    return 0;
}

void BattleScene_IntroCameraStep0(unk_D_86002F34_00C* arg0) {
    BattleScene_ResetCameraFrameCounter();
    arg0->unk_24.fovy = 50.0f;
    if (BattleScene_AreBothParticipantModelsCompact() != 0) {
        BattleScene_SetCameraAtFromPosition(arg0, D_84385B9C, 0, 0, 0.0f, 0.0f);
        BattleScene_SetCameraEyeAndStoreAngles(arg0, D_84385B9C, 0x5B0, 0, 550.0f, 0.0f);
    } else {
        BattleScene_SetCameraAtFromPosition(arg0, D_84385B90, 0, 0, 0.0f, 0.0f);
        BattleScene_SetCameraEyeAndStoreAngles(arg0, D_84385B90, 0x5B0, 0, 550.0f, 0.0f);
    }
    arg0->unk_60.eye.z *= 0.6;
    gBattleScene.unk_00->unk_20++;
}

void BattleScene_IntroCameraStep2(unk_D_86002F34_00C* arg0) {
    BattleScene_ResetCameraFrameCounter();
    arg0->unk_24.fovy = 30.0f;
    if (BattleScene_AreBothParticipantModelsCompact() != 0) {
        BattleScene_SetCameraAtFromPosition(arg0, D_84385B9C, 0, 0, 0.0f, 0.0f);
        BattleScene_SetCameraEyeAndStoreAngles(arg0, D_84385B9C, 0x1A4E, 0, 1000.0f, 0.0f);
    } else {
        BattleScene_SetCameraAtFromPosition(arg0, D_84385B90, 0, 0, 0.0f, 0.0f);
        BattleScene_SetCameraEyeAndStoreAngles(arg0, D_84385B90, 0x1A4E, 0, 1000.0f, 0.0f);
    }
    gBattleScene.unk_00->unk_20++;
}

void BattleScene_IntroCameraStep4Or6(unk_D_86002F34_00C* arg0, s32 arg1) {
    UNUSED s32 pad;
    f32 sp50;
    f32 sp4C;
    s16 sp4A;
    BattlerState* sp44;
    UNUSED s32 pad2;
    u16 sp3E;
    Battler* temp_s0;

    sp44 = &D_84390010[arg1]->unk_654;
    BattleScene_ClearCameraOffsetVectors();
    BattleScene_SetActiveBattlerIndex(arg1);
    temp_s0 = D_84390010[gBattleScene.unk_00->unk_2C];

    if (BattleScene_SkipIntroIfFainted(temp_s0, arg0) == 0) {
        BattleAnim_GetOwnerDefaultAnchorPosition(temp_s0, &gBattleScene.unk_00->unk_D0);
        if (!(sp44->unk_34 & 2)) {
            BattleScene_EnterStateRow(temp_s0, 1);
        }

        sp50 = BattleScene_GetParticipantModelRadiusScaled(temp_s0) * 3.5f;
        sp3E = BattleAnim_RandomRange(3);
        sp50 *= ((Battle_GetScaledHeightY(temp_s0) * 0.5f * sp3E) + 1.0f);

        if (sp50 > 325.0f) {
            sp50 = 325.0f;
        }

        sp3E = BattleAnim_RandomRange(4);
        sp4C = BattleAnim_GetOwnerModelHeight(temp_s0) * sp3E;
        sp4A = BattleAnim_RandomRange(0xB4);

        if (sp44->unk_34 & 0x200) {
            sp4C = 0.0f;
        }

        BattleScene_SetCameraAtFromAnchor(temp_s0, arg0, gBattleScene.unk_00->unk_D0, 0, 0, 0, 0.0f);
        BattleScene_SetCameraEyeFromPosition(arg0, gBattleScene.unk_00->unk_D0, 0, 0x4000 - (sp4A * 0xB6), sp50, sp4C);
        BattleScene_CameraPresetNop(arg0);
        BattleScene_UpdateCameraModelOffset(temp_s0, arg0);

        if (temp_s0->unk_000.objectType == 0x5F) {
            arg0->unk_24.fovy = 50.0f;
        } else {
            arg0->unk_24.fovy = 30.0f;
        }
        gBattleScene.unk_00->unk_20++;
    }
}

void BattleScene_IntroCameraStep8Or10(unk_D_86002F34_00C* arg0, s32 arg1) {
    UNUSED s32 pad[2];
    unk_D_86B0C160* sp24;
    s32 var_a0;
    Battler* temp_s0;

    BattleScene_ClearCameraOffsetVectors();
    BattleScene_SetActiveBattlerIndex(arg1);
    temp_s0 = D_84390010[gBattleScene.unk_00->unk_2C];

    if (BattleScene_SkipIntroIfFainted(temp_s0, arg0) == 0) {
        if (temp_s0->unk_654.unk_34 & 0x200) {
            sp24 = &D_84384888[0];
        } else {
            var_a0 = BattleAnim_RandomRange(5);
            if (var_a0 >= 5) {
                var_a0 = 0;
            }
            sp24 = &D_843847EC[var_a0];
        }
        arg0->unk_24.fovy = sp24->unk_30;
        BattleAnim_GetOwnerDefaultAnchorPosition(temp_s0, &D_843901B0.unk_00);
        BattleScene_LoadCameraPreset(sp24, arg0, temp_s0);
        BattleScene_ApplyCameraPreset(arg0, temp_s0, 1);
        BattleScene_CameraPresetNop(arg0);
        gBattleScene.unk_00->unk_20++;
    }
}

void BattleScene_IntroCameraStep12Or14(unk_D_86002F34_00C* arg0, s32 arg1) {
    arg0->unk_24.fovy = 30.0f;
    BattleScene_SetActiveBattlerIndex(arg1);
    if (BattleScene_SkipIntroIfFainted(D_84390010[arg1], arg0) == 0) {
        BattleScene_SetCameraSendOutShot(arg0, arg1);
        gBattleScene.unk_00->unk_20++;
    }
}

void BattleScene_IntroCameraStep16(unk_D_86002F34_00C* arg0) {
    BattleScene_SetActiveBattlerIndex(gBattleScene.unk_00->unk_54 - 1);
    if (BattleScene_IsEitherBattlerFainted(D_84390010[gBattleScene.unk_00->unk_2C], arg0) != 0) {
        gBattleScene.unk_00->unk_54 = 0;
        BattleScene_SelectNextIntroCameraShot(arg0);
    } else {
        BattleScene_SetCameraBattlerHeightShot(arg0, gBattleScene.unk_00->unk_2C);
        gBattleScene.unk_00->unk_20++;
    }
}

void BattleScene_IntroCameraStep18(unk_D_86002F34_00C* arg0) {
    BattleScene_SetActiveBattlerIndex(gBattleScene.unk_00->unk_2C);
    gBattleScene.unk_00->unk_54 = 0;
    if (BattleScene_IsEitherBattlerFainted(D_84390010[gBattleScene.unk_00->unk_2C], arg0) != 0) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    } else {
        BattleScene_SetCameraBattlerHeightShot(arg0, gBattleScene.unk_00->unk_2C);
        gBattleScene.unk_00->unk_20++;
    }
}

void BattleScene_IntroCameraStep20(unk_D_86002F34_00C* arg0) {
    s16 var_v1;

    BattleScene_ResetCameraFrameCounter();
    if (D_800AE540.unk_0000 == 0x10) {
        var_v1 = D_843859E0[D_800AE540.unk_0001].unk_00;
        if (D_800AE540.unk_0001 == 7) {
            var_v1 += D_800AE540.unk_0002;
        }
    } else {
        var_v1 = D_843859E0[D_800AE540.unk_0000].unk_00;
        if (D_800AE540.unk_0000 == 7) {
            var_v1 += D_800AE540.unk_0002;
        }
    }
    arg0->unk_24.fovy = D_843859E0[var_v1].unk_0C;
    Vec3f_SetComponentsDuplicate(&arg0->unk_60.at, 0.0f, 10.0f, 0.0f);
    Camera_ComputeEyeFromAngles(&arg0->unk_60.at, &arg0->unk_60.eye, D_843859E0[var_v1].unk_04, D_843859E0[var_v1].unk_08,
                  D_843859E0[var_v1].unk_0A);
    gBattleScene.unk_00->unk_20++;
}

void BattleScene_IntroCameraStep22Or24(unk_D_86002F34_00C* arg0, s32 arg1) {
    UNUSED s32 pad[5];
    s32 var_v1;
    Battler* temp_s0;
    f32 tmp1;
    s16 tmp4;
    s16 tmp3;
    f32 tmp2;

    BattleScene_SetCameraClipPlanes(arg0, 10.0f, 12800.0f);
    arg0->unk_24.fovy = 60.0f;
    BattleScene_SetActiveBattlerIndex(arg1);
    temp_s0 = D_84390010[arg1];

    if (BattleScene_SkipIntroIfFainted(temp_s0, arg0) == 0) {
        if ((temp_s0->unk_000.objectType == 0x98) || (temp_s0->unk_654.unk_34 & 2)) {
            BattleScene_SelectNextIntroCameraShot(arg0);
            return;
        }

        if ((temp_s0->unk_000.objectType == 0x5F) && (arg1 == 1)) {
            var_v1 = 0x97;
        } else {
            var_v1 = (temp_s0->unk_000.objectType - 1) & 0xFF;
        }

        tmp2 = (D_84384580[arg1]->unk_00.y + temp_s0->unk_000.position.y) + D_84384C30[var_v1].z;
        tmp1 = ((D_84384580[arg1]->unk_00.z + D_84384C30[var_v1].y) * temp_s0->unk_4B0) + temp_s0->unk_000.position.x;

        Vec3f_SetComponentsDuplicate(&arg0->unk_60.at, tmp1, tmp2, temp_s0->unk_000.position.z);

        tmp1 = D_84384580[gBattleScene.unk_00->unk_2C]->unk_00.x * D_84384C30[var_v1].x;
        tmp4 = D_84384580[gBattleScene.unk_00->unk_2C]->unk_0C;
        tmp3 = (temp_s0->unk_4B0 * D_84384580[gBattleScene.unk_00->unk_2C]->unk_0E) + BattleScene_GetParticipantFacingAngle(temp_s0);

        Camera_ComputeEyeFromAngles(&arg0->unk_60.at, &arg0->unk_60.eye, tmp1, tmp4, tmp3);
        gBattleScene.unk_00->unk_20++;
    }
}

void BattleScene_SelectNextIntroCameraShot(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad[2];
    s32 sp20[] = {
        // D_84385B20
        0x00000000, 0x00000008, 0x00000004, 0x00000014, 0x0000000A,
        0x00000006, 0x00000002, 0x00000016, 0x00000018, 0x000000FF,
    };

    BattleScene_SetCameraClipPlanes(arg0, 20.0f, 12800.0f);
    arg0->unk_24.fovy = 30.0f;
    if ((gBattleScene.unk_00->unk_54 != 0) && (BattleScene_AreBattlerHeightsSeparated(arg0) != 0)) {
        gBattleScene.unk_00->unk_20 = 0x10;
    } else {
        gBattleScene.unk_00->unk_54 = 0;
        if (sp20[gBattleScene.unk_00->unk_0C] == 0xFF) {
            gBattleScene.unk_00->unk_0C = 0;
        }
        gBattleScene.unk_00->unk_20 = sp20[gBattleScene.unk_00->unk_0C];
        gBattleScene.unk_00->unk_0C++;
    }

    Battle_ResetModelToIdleAnim(*D_84390010);
    Battle_ResetModelToIdleAnim(D_84390010[1]);
    BattleScene_ResetCameraFrameCounter();

    switch (gBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_IntroCameraStep0(arg0);
            break;

        case 2:
            BattleScene_IntroCameraStep2(arg0);
            break;

        case 4:
            BattleScene_IntroCameraStep4Or6(arg0, 0);
            break;

        case 6:
            BattleScene_IntroCameraStep4Or6(arg0, 1);
            break;

        case 8:
            BattleScene_IntroCameraStep8Or10(arg0, 0);
            break;

        case 10:
            BattleScene_IntroCameraStep8Or10(arg0, 1);
            break;

        case 12:
            BattleScene_IntroCameraStep12Or14(arg0, 0);
            break;

        case 14:
            BattleScene_IntroCameraStep12Or14(arg0, 1);
            break;

        case 16:
            BattleScene_IntroCameraStep16(arg0);
            break;

        case 18:
            BattleScene_IntroCameraStep18(arg0);
            break;

        case 20:
            BattleScene_IntroCameraStep20(arg0);
            break;

        case 22:
            BattleScene_IntroCameraStep22Or24(arg0, 0);
            break;

        case 24:
            BattleScene_IntroCameraStep22Or24(arg0, 1);
            break;
    }
}

void BattleScene_IntroCameraRollStep(unk_D_86002F34_00C* arg0) {
    arg0->unk_24.fovy = 50.0f;
    if (BattleScene_ApproachCameraRoll(arg0, 0xB6, 0x78DC) != 0) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    } else {
        arg0->unk_60.eye.z *= 0.6;
    }
}

void BattleScene_IntroCameraRollStepNoFov(unk_D_86002F34_00C* arg0) {
    if (BattleScene_ApproachCameraRoll(arg0, 0xB6, 0x78DC) != 0) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    }
}

void BattleScene_IntroCameraAnimationHoldStep(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    BattlerState* sp18 = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;

    if ((sp18->unk_2D == 0x10) || ((sp18->unk_34 & 0x4000) != 0)) {
        BattleScene_SelectNextIntroCameraShot(arg0);
        return;
    }

    if (!(sp18->unk_34 & 0x200)) {
        BattleScene_ApplyOwnerFramingOnly(arg0, D_84390010[gBattleScene.unk_00->unk_2C]);
    }

    if ((sp18->unk_34 & 1) || (sp18->unk_34 & 2) || (D_84390010[gBattleScene.unk_00->unk_2C]->unk_000.objectType == 0x98)) {
        if (BattleScene_AdvanceCameraFrameCounter(0x5A) != 0) {
            BattleScene_SelectNextIntroCameraShot(arg0);
        }
    } else if (ModelAnim_IsAnimationDone(&D_84390010[gBattleScene.unk_00->unk_2C]->unk_000) != 0) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    }
}

void BattleScene_IntroCameraPresetHoldStep(unk_D_86002F34_00C* arg0) {
    Battler* sp1C = D_84390010[gBattleScene.unk_00->unk_2C];

    if ((sp1C->unk_654.unk_2D == 0x10) || (sp1C->unk_654.unk_34 & 0x4000)) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    } else if ((BattleScene_AdvanceCameraFrameCounter(0x5A) != 0) || (BattleScene_AnimateCameraPreset(arg0, sp1C, 1, 0) != 0)) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    }
}

void BattleScene_IntroCameraWideHoldStep(unk_D_86002F34_00C* arg0) {
    BattlerState* ptr = &D_84390010[gBattleScene.unk_00->unk_2C]->unk_654;

    if ((ptr->unk_2D == 0x10) || (ptr->unk_34 & 0x4000)) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    } else {
        arg0->unk_24.fovy = 60.0f;
        if (BattleScene_AdvanceCameraFrameCounter(0x3C) != 0) {
            BattleScene_SelectNextIntroCameraShot(arg0);
        }
    }
}

void BattleScene_IntroCameraHeightShotSwapStep(unk_D_86002F34_00C* arg0) {
    if (BattleScene_ApproachCameraBattlerHeightShot(arg0, gBattleScene.unk_00->unk_2C) != 0) {
        s32 idx = gBattleScene.unk_00->unk_2C == 0;

        gBattleScene.unk_00->unk_2C = idx;
        gBattleScene.unk_00->unk_20 = 0x12;
        BattleScene_IntroCameraStep18(arg0);
    }
}

void BattleScene_IntroCameraHeightShotStep(unk_D_86002F34_00C* arg0) {
    if (BattleScene_ApproachCameraBattlerHeightShot(arg0, gBattleScene.unk_00->unk_2C) != 0) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    }
}

void BattleScene_IntroCameraTimedHoldStep(unk_D_86002F34_00C* arg0) {
    if (BattleScene_AdvanceCameraFrameCounter(0x78) != 0) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    }
}

void BattleScene_IntroCameraFinalHoldStep(unk_D_86002F34_00C* arg0) {
    BattleScene_SetCameraClipPlanes(arg0, 10.0f, 12800.0f);
    arg0->unk_24.fovy = 60.0f;
    if (BattleScene_AdvanceCameraFrameCounter(0x3C) != 0) {
        BattleScene_SelectNextIntroCameraShot(arg0);
    }
}

void BattleScene_UpdateIntroCameraSequence(unk_D_86002F34_00C* arg0) {
    if ((D_800AE540.unk_0000 == 0x10) && (gBattleScene.unk_00->unk_1C == 1)) {
        BattleScene_UpdateActionSelectPhase();
    } else if (gBattleScene.unk_00->unk_1C == 1) {
        if ((gBattleScene.unk_00->unk_30 == 0) && (D_84390010[0]->unk_728.unk_168->unk_1C == 0x17) &&
            (D_84390010[1]->unk_728.unk_168->unk_1C == 0x103)) {
            BattleScene_UpdateActionSelectPhase();
        } else if ((gBattleScene.unk_00->unk_30 == 0) && (D_84390010[0]->unk_728.unk_168->unk_1C < 0xE) &&
                   (D_84390010[1]->unk_728.unk_168->unk_1C >= 0x10D)) {
            BattleScene_ResetActionSelectionTimers();
        }
    }

    switch (gBattleScene.unk_00->unk_20) {
        case 1:
            BattleScene_IntroCameraRollStep(arg0);
            break;

        case 3:
            BattleScene_IntroCameraRollStepNoFov(arg0);
            break;

        case 5:
            BattleScene_IntroCameraAnimationHoldStep(arg0);
            break;

        case 7:
            BattleScene_IntroCameraAnimationHoldStep(arg0);
            break;

        case 9:
            BattleScene_IntroCameraPresetHoldStep(arg0);
            break;

        case 11:
            BattleScene_IntroCameraPresetHoldStep(arg0);
            break;

        case 13:
            BattleScene_IntroCameraWideHoldStep(arg0);
            break;

        case 15:
            BattleScene_IntroCameraWideHoldStep(arg0);
            break;

        case 17:
            BattleScene_IntroCameraHeightShotSwapStep(arg0);
            break;

        case 19:
            BattleScene_IntroCameraHeightShotStep(arg0);
            break;

        case 21:
            BattleScene_IntroCameraTimedHoldStep(arg0);
            break;

        case 23:
            BattleScene_IntroCameraFinalHoldStep(arg0);
            break;

        case 25:
            BattleScene_IntroCameraFinalHoldStep(arg0);
            break;

        case 50:
            BattleScene_SelectNextIntroCameraShot(arg0);
            break;
    }
}
