#include "gallery_camera.h"
#include "src/matrix.h"
#include "src/stage_loader.h"
#include "src/fragments/minigame_actor_framework/minigame_actor_framework.h"

static s16 D_8690B600;
static s16 D_8690B602;
static f32 D_8690B604;
static s16 D_8690B608;
static s16 D_8690B60A;
static f32 D_8690B60C;
static f32 D_8690B610;
static Vec3f D_8690B618;

f32 GalleryCamera_Distance3D(Vec3f arg0, Vec3f arg1) {
    return sqrtf(SQ(arg1.x - arg0.x) + SQ(arg1.y - arg0.y) + SQ(arg1.z - arg0.z));
}

f32 GalleryCamera_ComputeZoomDistance(f32 arg0) {
    f32 temp_fv1 = (D_8690B2F8.unk_00 + D_8690A708) * arg0;

    if (temp_fv1 > 400.0f) {
        return 400.0f;
    }
    return temp_fv1;
}

f32 GalleryCamera_DistanceXZ(Vec3f arg0, Vec3f arg1) {
    return sqrtf(SQ(arg1.x - arg0.x) + SQ(arg1.z - arg0.z));
}

void func_8690232C(void) {
}

void GalleryCamera_InitFreeView(void) {
    D_87906054 = D_87906050->node.children;
    D_8690B600 = 0;
    D_8690B602 = 0;
    D_8690B604 = GalleryCamera_ComputeZoomDistance(4.0f);

    if (D_8690B2F8.unk_08 != 0.0f) {
        D_87906054->unk_60.at.y = D_8690B2F8.unk_08;
    } else {
        D_87906054->unk_60.at.y = D_8690B2F8.unk_04 + D_8690B2F8.unk_0C;
    }

    Camera_ComputeEyeFromAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, D_8690B604, D_8690B600, D_8690B602);

    if (D_87906054->unk_60.eye.y < 12.0f) {
        D_87906054->unk_60.eye.y = 12.5f;
        Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, &D_8690B604, &D_8690B600, &D_8690B602);
    }

    D_87906054->unk_24.near = 20.0f;
    D_87906054->unk_24.far = 10000.0f;
    D_87906054->unk_24.fovy = 40.0f;
    D_8690A710->unk_008 = 40.0f;

    D_8690B610 = 0.0f;

    Vec3f_SetComponentsDuplicate(&D_8690B618, D_87906054->unk_60.at.x, D_87906054->unk_60.at.y, D_87906054->unk_60.at.z);
}

void GalleryCamera_DebugAdjustZoomOffset(void) {
    f32 temp_fv1;

    if (gPlayer2Controller->stickMag != 0.0f) {
        if (gPlayer2Controller->stickY >= 0.0f) {
            D_8690A708 += gPlayer2Controller->stickMag / 400.0f;
        } else {
            D_8690A708 -= gPlayer2Controller->stickMag / 400.0f;
        }

        temp_fv1 = 10.0f - D_8690B2F8.unk_00;
        if (D_8690A708 < temp_fv1) {
            D_8690A708 = temp_fv1;
        }

        if (D_8690A708 > 60.0f) {
            D_8690A708 = 60.0f;
        }
    }

    HAL_Printf(0x14, 0x14, "OFFSET %6.2f", D_8690A708);
}

void GalleryCamera_ResetFreeView(void) {
    D_8690B600 = 0;
    D_8690B602 = 0;
    D_8690B604 = GalleryCamera_ComputeZoomDistance(4.0f);
    D_87906054->unk_60.at.x = 0.0f;
    D_87906054->unk_60.at.z = 0.0f;

    if (D_8690B2F8.unk_08 != 0) {
        D_87906054->unk_60.at.y = D_8690B2F8.unk_08;
    } else {
        D_87906054->unk_60.at.y = D_8690B2F8.unk_04 + D_8690B2F8.unk_0C;
    }

    Camera_ComputeEyeFromAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, D_8690B604, D_8690B600, D_8690B602);

    if (D_87906054->unk_60.eye.y < 12.0f) {
        D_87906054->unk_60.eye.y = 12.5f;
        Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, &D_8690B604, &D_8690B600, &D_8690B602);
    }

    D_87906054->unk_24.near = 20.0f;
    D_87906054->unk_24.far = 10000.0f;
    D_87906054->unk_24.fovy = 40.0f;
    D_8690A710->unk_008 = 40.0f;
    D_8690B610 = 0.0f;

    Vec3f_SetComponentsDuplicate(&D_8690B618, D_87906054->unk_60.at.x, D_87906054->unk_60.at.y, D_87906054->unk_60.at.z);
}

s32 GalleryCamera_UpdateZoomFov(void) {
    if (D_8690B390.buttonPressed & 0x10) {
        if (D_8690A710->unk_008 == 25.0f) {
            D_8690A710->unk_008 = 40.0f;
        } else {
            D_8690A710->unk_008 = 25.0f;
        }
    }

    D_87906054->unk_24.fovy = Math_StepToF(D_87906054->unk_24.fovy, D_8690A710->unk_008, 1.5f, 1.5f);

    if (D_87906054->unk_24.fovy == D_8690A710->unk_008) {
        return 0;
    }
    return 1;
}

void GalleryCamera_RotateVecByMatrix(Vec3f* arg0, MtxF* arg1) {
    f32 x = (arg1->mf[0][0] * arg0->x) + (arg1->mf[0][1] * arg0->y) + (arg1->mf[0][2] * arg0->z);
    f32 y = (arg1->mf[1][0] * arg0->x) + (arg1->mf[1][1] * arg0->y) + (arg1->mf[1][2] * arg0->z);
    f32 z = (arg1->mf[2][0] * arg0->x) + (arg1->mf[2][1] * arg0->y) + (arg1->mf[2][2] * arg0->z);

    arg0->x = x;
    arg0->y = y;
    arg0->z = z;
}

void GalleryCamera_OrbitAtPoint(s16 arg0) {
    MtxF sp70;
    Vec3s sp68;
    Vec3f sp5C;
    Vec3f sp50;
    UNUSED s32 pad[3];
    Vec3f sp38;
    UNUSED s32 pad2;

    Vec3f_SetComponentsDuplicate(&sp38, 0, 0.0f, 0.0f);
    Vec3f_CalculateDistanceAngles(&sp38, &D_87906054->unk_60.eye, &D_8690B60C, &D_8690B608, &D_8690B60A);
    Vec3f_SetComponentsDuplicate(&sp50, D_87906054->unk_60.at.x, 0.0f, D_87906054->unk_60.at.z);
    Vec3s_SetComponents(&sp68, 0, D_8690B60A + arg0, 0);
    Vec3f_SetComponentsDuplicate(&sp5C, D_8690A710->unk_004 * 4.0f, 0.0f, 0.0f);
    MtxF_SetRotationAndTransformTranslation(&sp70, &D_87906054->unk_60.at, &sp68);
    GalleryCamera_RotateVecByMatrix(&sp5C, &sp70);

    sp50.x += sp5C.x;
    sp50.z += sp5C.z;

    D_87906054->unk_60.at.x = sp50.x;
    D_87906054->unk_60.at.z = sp50.z;

    Vec3f_CalculateDistanceAngles(&sp38, &D_87906054->unk_60.at, &D_8690B60C, &D_8690B608, &D_8690B60A);
    D_8690B60C = GalleryCamera_DistanceXZ(sp38, D_87906054->unk_60.at);
    if ((GalleryCamera_ComputeZoomDistance(1.9f) - 1.0f) <= D_8690B60C) {
        Camera_ComputeEyeFromAngles(&sp38, &sp50, GalleryCamera_ComputeZoomDistance(1.9f) - 1.0f, 0, D_8690B60A);
        D_87906054->unk_60.at.x = sp50.x;
        D_87906054->unk_60.at.z = sp50.z;
    }
    Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, &D_8690B604, &D_8690B600, &D_8690B602);
}

void GalleryCamera_HandleDPadInput(void) {
    if (((D_8690B390.buttonDown & 8) | (D_8690B390.buttonDown & 4) | (D_8690B390.buttonDown & 2) |
         (D_8690B390.buttonDown & 1)) != 0) {
        D_8690A710->unk_004 = Math_StepToF(D_8690A710->unk_004, 1.0f, 0.2f, 0.2f);
    } else {
        D_8690A710->unk_004 = Math_StepToF(D_8690A710->unk_004, 0.0f, 0.2f, 0.2f);
    }

    if ((D_8690B390.buttonDown & 8) && (D_87906054->unk_60.at.y < 300.0f)) {
        D_87906054->unk_60.at.y += 4.0f * D_8690A710->unk_004;
        Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, &D_8690B604, &D_8690B600, &D_8690B602);
        if (D_8690B600 < -0x38E3) {
            D_87906054->unk_60.at.y -= 4.0f * D_8690A710->unk_004;
        }
        Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, &D_8690B604, &D_8690B600, &D_8690B602);
    } else if ((D_8690B390.buttonDown & 4) && (D_87906054->unk_60.at.y > 5.0f)) {
        D_87906054->unk_60.at.y -= 4.0f * D_8690A710->unk_004;
        Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, &D_8690B604, &D_8690B600, &D_8690B602);
        if (D_8690B600 >= 0x38E4) {
            D_87906054->unk_60.at.y += 4.0f * D_8690A710->unk_004;
        }
        Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, &D_8690B604, &D_8690B600, &D_8690B602);
    }

    if (D_87906054->unk_60.at.y > 200.0f) {
        D_87906054->unk_60.at.y = 200.0f;
        Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, &D_8690B604, &D_8690B600, &D_8690B602);
    }

    if (D_87906054->unk_60.at.y < 5.0f) {
        D_87906054->unk_60.at.y = 5.0f;
        Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, &D_8690B604, &D_8690B600, &D_8690B602);
    }

    if (D_8690B390.buttonDown & 1) {
        GalleryCamera_OrbitAtPoint(0);
    } else if (D_8690B390.buttonDown & 2) {
        GalleryCamera_OrbitAtPoint(-0x8000);
    }
}

void GalleryCamera_ClampToBoundaryCircle(Vec3f* arg0, Vec3f* arg1, Vec3f arg2, f32 arg3, s32 arg4) {
    Vec3f sp94;
    Vec3f sp88;
    Vec3f sp7C;
    Vec3f sp70;
    f32 sp6C;
    f32 sp68;
    f32 tmp;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp54;

    sp70 = D_86908C20;

    if (arg0->x == arg1->x) {
        sp7C.x = arg0->x;
        if (arg0->z < 0.0) {
            sp7C.z = -arg3;
        } else {
            sp7C.z = arg3;
        }
    } else {
        sp6C = (arg1->z - arg0->z) / (arg1->x - arg0->x);
        sp68 = arg1->z - (arg1->x * sp6C);

        sp54 = (((SQ(arg2.x) + SQ(sp68)) - ((2 * arg2.z) * sp68)) + SQ(arg2.z)) - SQ(arg3);

        sp38 = SQ(sp6C) + 1.0f;
        sp3C = (((2 * sp6C) * sp68) - (2 * arg2.x)) - ((2 * arg2.z) * sp6C);

        if (SQ(sp3C) < ((4 * sp38) * sp54)) {
            Vec3f_SetComponentsDuplicate(arg1, arg0->x, arg0->y, arg0->z);
            return;
        }

        sp34 = SQ(sp3C) - ((4 * sp38) * sp54);

        sp94.x = (-sp3C - sqrtf(sp34)) / (2 * sp38);
        sp94.y = 0.0f;
        sp94.z = (sp6C * sp94.x) + sp68;

        sp88.x = (sqrtf(sp34) + -sp3C) / (2 * sp38);
        sp88.y = 0.0f;
        sp88.z = (sp6C * sp88.x) + sp68;

        if (GalleryCamera_DistanceXZ(*arg0, sp94) > GalleryCamera_DistanceXZ(*arg0, sp88)) {
            sp7C.x = sp88.x;
            sp7C.z = sp88.z;
        } else {
            sp7C.x = sp94.x;
            sp7C.z = sp94.z;
        }
    }

    sp6C = arg0->y - arg1->y;
    if (sp6C == 0.0f) {
        sp7C.y = arg1->y;
    } else {
        if (arg1->x == arg0->x) {
            tmp = (sp7C.z - arg0->z) / (arg1->z - arg0->z);
        } else {
            tmp = (sp7C.x - arg0->x) / (arg1->x - arg0->x);
        }

        if (arg4 == 1) {
            sp7C.y = ((arg1->y - arg0->y) * tmp) + arg0->y;
        } else {
            sp7C.y = ((arg0->y - arg1->y) * tmp) + arg1->y;
        }
    }

    Vec3f_SetComponentsDuplicate(arg0, arg1->x, arg1->y, arg1->z);
    Vec3f_SetComponentsDuplicate(arg1, sp7C.x, sp7C.y, sp7C.z);
    Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, arg1, &D_8690B604, &D_8690B600, &D_8690B602);
}

void GalleryCamera_ClampAtToBoundaryCircle(Vec3f* arg0, Vec3f* arg1, Vec3f arg2, f32 arg3) {
    Vec3f sp84;
    Vec3f sp78;
    Vec3f tmp;
    Vec3f sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp2C;
    f32 sp44;

    sp60 = D_86908C2C;
    sp2C = arg1->x;
    tmp.z = arg3;
    if (D_87906054->unk_60.at.x == sp2C) {
        tmp.x = D_87906054->unk_60.at.x;
    } else {
        sp5C = (arg1->z - D_87906054->unk_60.at.z) / (arg1->x - D_87906054->unk_60.at.x);
        sp58 = arg1->z - (arg1->x * sp5C);

        sp44 = (((SQ(arg2.x) + SQ(sp58)) - ((2 * arg2.z) * sp58)) + SQ(arg2.z)) - SQ(arg3);

        sp3C = SQ(sp5C) + 1.0f;
        sp38 = ((2 * sp5C * sp58) - (2 * arg2.x)) - ((2 * arg2.z) * sp5C);

        sp2C = SQ(sp38) - ((4 * sp3C) * sp44);

        sp84.x = (-sp38 - sqrtf(sp2C)) / (2 * sp3C);
        sp84.y = 0.0f;
        sp84.z = (sp5C * sp84.x) + sp58;

        sp78.x = (sqrtf(sp2C) + -sp38) / (2 * sp3C);
        sp78.y = 0.0f;
        sp78.z = (sp5C * sp78.x) + sp58;

        if (GalleryCamera_DistanceXZ(*arg1, sp84) > GalleryCamera_DistanceXZ(*arg1, sp78)) {
            tmp.x = sp78.x;
            tmp.z = sp78.z;
        } else {
            tmp.x = sp84.x;
            tmp.z = sp84.z;
        }
    }

    tmp.y = arg0->y;

    Vec3f_SetComponentsDuplicate(arg1, tmp.x, tmp.y, tmp.z);
    Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, arg1, &D_8690B604, &D_8690B600, &D_8690B602);
}

void GalleryCamera_ClampHeight(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3, s32 arg4) {
    f32 temp_fa0;

    arg2 += arg3;

    if (arg4 == 1) {
        temp_fa0 = (arg2 - arg0->y) / (arg1->y - arg0->y);
        if (arg1->x == arg0->x) {
            arg1->x = arg0->x;
        } else {
            arg1->x = ((arg1->x - arg0->x) * temp_fa0) + arg0->x;
        }

        if (arg1->z == arg0->z) {
            arg1->z = arg0->z;
        } else {
            arg1->z = ((arg1->z - arg0->z) * temp_fa0) + arg0->z;
        }
    }

    arg1->y = arg2;
    Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, arg1, &D_8690B604, &D_8690B600, &D_8690B602);
}

void GalleryCamera_ClampEyeToPanBounds(Vec3f* arg0, Vec3f* arg1) {
    UNUSED s32 pad[2];
    Vec3f sp3C = D_86908C38;
    f32 sp38;

    if (arg1->y < 12.0f) {
        GalleryCamera_ClampHeight(arg0, arg1, 12.0f, 0.05f, 0);
    }

    if (arg1->y > 350.0f) {
        GalleryCamera_ClampHeight(arg0, arg1, 350.0f, 0.0f, 0);
    }

    sp38 = GalleryCamera_ComputeZoomDistance(1.9f);
    if (GalleryCamera_DistanceXZ(sp3C, *arg1) < sp38) {
        GalleryCamera_ClampToBoundaryCircle(arg0, arg1, sp3C, GalleryCamera_ComputeZoomDistance(1.9f) + 0.05f, 1);
    }

    if (GalleryCamera_DistanceXZ(sp3C, *arg1) > 400.0f) {
        GalleryCamera_ClampToBoundaryCircle(arg0, arg1, sp3C, 399.0f, 1);
    }

    if (GalleryCamera_DistanceXZ(D_87906054->unk_60.at, *arg1) < 30.0f) {
        GalleryCamera_ClampToBoundaryCircle(arg0, arg1, D_87906054->unk_60.at, 30.1f, 1);
    }
}

void GalleryCamera_ClampOrbitBounds(Vec3f* arg0, Vec3f* arg1, s32 arg2) {
    UNUSED s32 pad[2];
    Vec3f sp3C = D_86908C44;
    f32 sp38;

    if (arg2 == 0) {
        if (arg1->y < 12.0f) {
            GalleryCamera_ClampHeight(arg0, arg1, 12.0f, 0.05f, 1);
        }

        if (arg1->y > 350.0f) {
            GalleryCamera_ClampHeight(arg0, arg1, 350.0f, 0.0f, 1);
        }
    } else {
        if (arg1->y < 12.0f) {
            GalleryCamera_ClampHeight(arg0, arg1, 12.0f, 0.05f, 0);
        }

        if (arg1->y > 350.0f) {
            GalleryCamera_ClampHeight(arg0, arg1, 350.0f, 0.0f, 0);
        }
    }

    if (arg2 == 0) {
        sp38 = GalleryCamera_ComputeZoomDistance(1.9f);
        if (GalleryCamera_DistanceXZ(sp3C, *arg1) < sp38) {
            GalleryCamera_ClampToBoundaryCircle(arg0, arg1, sp3C, GalleryCamera_ComputeZoomDistance(1.9f) + 0.05f, 0);
        }

        if (GalleryCamera_DistanceXZ(sp3C, *arg1) > 400.0f) {
            GalleryCamera_ClampToBoundaryCircle(arg0, arg1, sp3C, 399.0f, 0);
        }

        if (GalleryCamera_DistanceXZ(D_87906054->unk_60.at, *arg1) < 30.0f) {
            GalleryCamera_ClampToBoundaryCircle(arg0, arg1, D_87906054->unk_60.at, 30.1f, 0);
        }
    } else {
        sp38 = GalleryCamera_ComputeZoomDistance(1.9f);
        if (GalleryCamera_DistanceXZ(sp3C, *arg1) < sp38) {
            GalleryCamera_ClampAtToBoundaryCircle(arg0, arg1, sp3C, GalleryCamera_ComputeZoomDistance(1.9f) + 0.05f);
        }

        if (GalleryCamera_DistanceXZ(sp3C, *arg1) > 400.0f) {
            GalleryCamera_ClampAtToBoundaryCircle(arg0, arg1, sp3C, 399.0f);
        }

        if (GalleryCamera_DistanceXZ(D_87906054->unk_60.at, *arg1) < 30.0f) {
            GalleryCamera_ClampAtToBoundaryCircle(arg0, arg1, D_87906054->unk_60.at, 30.1f);
        }
    }
}

void GalleryCamera_HandleFreeMoveInput(void) {
    Vec3f sp44;
    Vec3f sp38;
    UNUSED s32 pad;
    f32 mag;

    if (D_8690B390.stickMag != 0.0f) {
        Vec3f_SetComponentsDuplicate(&sp44, D_87906054->unk_60.eye.x, D_87906054->unk_60.eye.y, D_87906054->unk_60.eye.z);
        if (D_8690B390.stickY >= 0.0f) {
            mag = -(D_8690B390.stickMag / 6.0f);
            Camera_ComputeEyeFromAngles(&D_87906054->unk_60.eye, &sp38, mag, D_8690B600, D_8690B602);
        } else {
            mag = D_8690B390.stickMag / 6.0f;
            Camera_ComputeEyeFromAngles(&D_87906054->unk_60.eye, &sp38, mag, D_8690B600, D_8690B602);
        }
        D_8690B604 = GalleryCamera_Distance3D(D_87906054->unk_60.at, sp38);
        GalleryCamera_ClampEyeToPanBounds(&sp44, &sp38);
        Vec3f_SetComponentsDuplicate(&D_87906054->unk_60.eye, sp38.x, sp38.y, sp38.z);
    }

    if (D_8690B390.buttonDown & 0x200) {
        D_8690B602 -= 0x100;
    }

    if (D_8690B390.buttonDown & 0x100) {
        D_8690B602 += 0x100;
    }

    if (D_8690B390.buttonDown & 0x300) {
        Vec3f_SetComponentsDuplicate(&sp44, D_87906054->unk_60.eye.x, D_87906054->unk_60.eye.y, D_87906054->unk_60.eye.z);
        Camera_ComputeEyeFromAngles(&D_87906054->unk_60.at, &sp38, D_8690B604, D_8690B600, D_8690B602);
        GalleryCamera_ClampOrbitBounds(&sp44, &sp38, 1);
        Vec3f_SetComponentsDuplicate(&D_87906054->unk_60.eye, sp38.x, sp38.y, sp38.z);
    }

    if (D_8690B390.buttonDown & 0x800) {
        D_8690B600 += 0x100;
    }

    if (D_8690B390.buttonDown & 0x400) {
        D_8690B600 -= 0x100;
    }

    if (D_8690B390.buttonDown & 0xC00) {
        Vec3f_SetComponentsDuplicate(&sp44, D_87906054->unk_60.eye.x, D_87906054->unk_60.eye.y, D_87906054->unk_60.eye.z);
        Camera_ComputeEyeFromAngles(&D_87906054->unk_60.at, &sp38, D_8690B604, D_8690B600, D_8690B602);
        GalleryCamera_ClampOrbitBounds(&sp44, &sp38, 0);
        Vec3f_SetComponentsDuplicate(&D_87906054->unk_60.eye, sp38.x, sp38.y, sp38.z);
    }
}
