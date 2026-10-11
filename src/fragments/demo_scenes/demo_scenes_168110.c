#include "demo_scenes.h"
#include "src/matrix.h"

typedef struct unk_D_86B0DFC0 {
    u8 unk_00[1];
} unk_D_86B0DFC0; // size = ??

static unk_D_86B0DFC0 D_86B0DFC0 = { 0x8E };

s16 Intro_GetTrackedModelFacingOffset(void) {
    return D_86B0FA78->unk_004.rotation.y + 0x8000;
}

s32 Util_ByteInArray(u8 arg0, u8* arg1, s32 arg2) {
    while (arg2--) {
        if (arg0 == *arg1) {
            return 1;
        }
        arg1++;
    }
    return 0;
}

void Intro_ComputeFollowPoint(unk_D_86B0FA78* arg0, Vec3f* arg1) {
    f32 sp24 = 0.0f;
    unk_D_86B0DFC0 sp20 = D_86B0DFC0;

    if (Util_ByteInArray(D_86B0FA78->unk_174, sp20.unk_00, 1) != 0) {
        sp24 = D_86B10660.unk_04 / 1.5f;
    }

    if (D_86B10660.unk_08 != 0) {
        arg1->x = arg0->unk_004.position.x;
        arg1->y = arg0->unk_004.position.y + sp24;
        arg1->z = arg0->unk_004.position.z;
    } else {
        arg1->x = arg0->unk_004.position.x;
        arg1->y = arg0->unk_004.position.y + D_86B10660.unk_04;
        arg1->z = arg0->unk_004.position.z;
    }

    if (arg1->y < 0) {
        arg1->y = D_86B10660.unk_04;
    }
}

void Intro_UpdateOrbitCamera(void) {
    Camera_ComputeEyeFromAngles(&D_86B0FA7C->unk_04, &D_86B0FA7C->unk_00->unk_60.at, D_86B0FA7C->unk_1C, D_86B0FA7C->unk_10,
                  Intro_GetTrackedModelFacingOffset() + D_86B0FA7C->unk_12);
    Camera_ComputeEyeFromAngles(&D_86B0FA7C->unk_04, &D_86B0FA7C->unk_00->unk_60.eye, D_86B0FA7C->unk_20, D_86B0FA7C->unk_16,
                  Intro_GetTrackedModelFacingOffset() + D_86B0FA7C->unk_18);

    D_86B0FA7C->unk_00->unk_60.at.y += D_86B10660.unk_0C;
    if (D_86B0FA7C->unk_00->unk_60.eye.y <= 10.0f) {
        D_86B0FA7C->unk_00->unk_60.eye.y = 10.0f;
    }
}

f32 Intro_ClampOrbitDistance(f32 arg0, f32 arg1) {
    f32 temp_fv1 = D_86B10660.unk_00 * arg0;

    if (arg1 < temp_fv1) {
        return arg1;
    }
    return temp_fv1;
}

void IntroCamKeyframe_SetAngles(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_86B0FA7C->unk_10 = arg0;
    D_86B0FA7C->unk_12 = arg1;
    D_86B0FA7C->unk_24 = arg2;
    D_86B0FA7C->unk_26 = arg3;
}

void IntroCamKeyframe_SetDistance(f32 arg0, f32 arg1) {
    D_86B0FA7C->unk_1C = arg0;
    D_86B0FA7C->unk_30 = arg1;
}

void IntroCamKeyframe_SetAtAngles(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_86B0FA7C->unk_16 = arg0;
    D_86B0FA7C->unk_18 = arg1;
    D_86B0FA7C->unk_2A = arg2;
    D_86B0FA7C->unk_2C = arg3;
}

void IntroCamKeyframe_SetAtDistance(f32 arg0, f32 arg1) {
    D_86B0FA7C->unk_20 = arg0;
    D_86B0FA7C->unk_34 = arg1;
}

void IntroCamKeyframe_SetTransitionSpeed(f32 arg0, f32 arg1) {
    D_86B0FA7C->unk_38 = arg0;
    D_86B0FA7C->unk_3C = arg1;
}

void Intro_LoadCameraKeyframe(unk_D_86B0C160* arg0, unk_D_86002F34_00C* arg1) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    D_86B0FA7C->unk_44 = 0.0f;
    if (arg0->unk_30 != 200.0f) {
        arg1->unk_24.fovy = D_86B0FA7C->unk_40 = arg0->unk_30;
    } else {
        D_86B0FA7C->unk_40 = arg0->unk_30;
    }

    sp34 = Intro_ClampOrbitDistance(arg0->unk_0C, 500.0f);
    sp30 = Intro_ClampOrbitDistance(arg0->unk_20, 500.0f);
    sp2C = Intro_ClampOrbitDistance(arg0->unk_10, 500.0f);
    sp28 = Intro_ClampOrbitDistance(arg0->unk_24, 500.0f);

    IntroCamKeyframe_SetAngles(arg0->unk_00, Intro_GetTrackedModelFacingOffset() + arg0->unk_02, arg0->unk_14, Intro_GetTrackedModelFacingOffset() + arg0->unk_16);
    IntroCamKeyframe_SetDistance(sp34, sp30);

    IntroCamKeyframe_SetAtAngles(arg0->unk_06, Intro_GetTrackedModelFacingOffset() + arg0->unk_08, arg0->unk_1A, Intro_GetTrackedModelFacingOffset() + arg0->unk_1C);
    IntroCamKeyframe_SetAtDistance(sp2C, sp28);
    IntroCamKeyframe_SetTransitionSpeed(arg0->unk_28, arg0->unk_2C);
}

s32 Intro_UpdateCameraKeyframe(unk_D_86002F34_00C* arg0) {
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;
    Vec3f sp38;
    f32 sp34;
    f32 sp30;
    s16 sp2E;
    s16 sp2C;

    if (D_86B0FA7C->unk_40 != 200.0f) {
        arg0->unk_24.fovy = D_86B0FA7C->unk_40;
    } else {
        Math_EaseTowardF(&arg0->unk_24.fovy, 30.0f, 0.06f);
    }

    Math_EaseTowardF(&D_86B0FA7C->unk_44, D_86B0FA7C->unk_38, D_86B0FA7C->unk_3C);
    Camera_ComputeEyeFromAngles(&D_86B0FA7C->unk_04, &sp50, D_86B0FA7C->unk_34, D_86B0FA7C->unk_2A,
                  Intro_GetTrackedModelFacingOffset() + D_86B0FA7C->unk_2C);

    if (sp50.y <= 10.0f) {
        sp50.y = 10.0f;
    }

    Vec3f_Copy(&sp44, &arg0->unk_60.eye);
    Vec3f_CalculateDistanceAngles(&sp44, &sp50, &sp34, &sp2E, &sp2C);
    Camera_ComputeEyeFromAngles(&sp44, &arg0->unk_60.eye, D_86B0FA7C->unk_44 * sp34, sp2E, sp2C);
    Camera_ComputeEyeFromAngles(&D_86B0FA7C->unk_04, &sp38, D_86B0FA7C->unk_30, D_86B0FA7C->unk_24,
                  Intro_GetTrackedModelFacingOffset() + D_86B0FA7C->unk_26);

    sp38.y += D_86B10660.unk_0C;

    Vec3f_Copy(&sp5C, &arg0->unk_60.at);
    Vec3f_CalculateDistanceAngles(&sp5C, &sp38, &sp30, &sp2E, &sp2C);
    Camera_ComputeEyeFromAngles(&sp5C, &arg0->unk_60.at, D_86B0FA7C->unk_44 * sp30, sp2E, sp2C);

    if ((sp34 <= 1.0f) && (sp30 <= 1.0f)) {
        return 1;
    }
    return 0;
}
