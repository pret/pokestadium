#include "gallery.h"
#include "include/math.h"
#include "src/math_util.h"

const char D_8007C510[0x24] = "og_normal_Fvector() zero div. err!\n";
const char D_8007C534[0x4] = "";

void Mtx_BuildDirectionRotation(Mtx* mtx, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 sp144;
    f32 sp140;
    f32 temp_fa0;
    f32 temp_fa1;
    UNUSED s32 pad[1];
    Mtx spF0;
    Mtx spB0;
    Mtx sp70;
    UNUSED s32 pad2[16];

    temp_fa1 = arg4 - arg1;
    temp_fa0 = arg6 - arg3;
    sp140 = (f32) (((f64) (f32) MathUtil_Atan2s(temp_fa0, temp_fa1) * 360.0) / 65535.0);
    sp144 = (f32) (((f64) (f32) MathUtil_Atan2s(arg5 - arg2, sqrtf((temp_fa1 * temp_fa1) + (temp_fa0 * temp_fa0))) * 360.0) / 65535.0);
    guRotate(&spB0, sp140, 0.0f, 1.0f, 0.0f);
    guRotate(&sp70, sp144, 0.0f, 0.0f, 1.0f);
    guMtxCatL(&spB0, &sp70, &spF0);
    *mtx = spF0;
}

f32 Math_AbsF32(f32 arg0) {
    if (arg0 < 0.0) {
        arg0 = -arg0;
    }
    return arg0;
}

void Vec3f_CrossProductComponents(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32* arg6, f32* arg7, f32* arg8) {
    *arg6 = (arg1 * arg5) - (arg2 * arg4);
    *arg7 = (arg2 * arg3) - (arg0 * arg5);
    *arg8 = (arg0 * arg4) - (arg1 * arg3);
}

void Vec3f_NormalizeComponents(f32* arg0, f32* arg1, f32* arg2) {
    f32 temp_fv1;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_fv0;

    temp_fv1 = *arg0;
    temp_fa1 = *arg1;
    temp_ft4 = *arg2;
    temp_fv0 = sqrtf((temp_fv1 * temp_fv1) + (temp_fa1 * temp_fa1) + (temp_ft4 * temp_ft4));
    if (temp_fv0 > 0.0f) {
        temp_fv1 /= temp_fv0;
        temp_fa1 /= temp_fv0;
        temp_ft4 /= temp_fv0;
    }
    *arg0 = temp_fv1;
    *arg1 = temp_fa1;
    *arg2 = temp_ft4;
}

void Vec3f_CrossProductArrays(const f32* a, const f32* b, f32* out) {
    f32 ax = a[0];
    f32 ay = a[1];
    f32 az = a[2];

    f32 bx = b[0];
    f32 by = b[1];
    f32 bz = b[2];

    out[0] = (ay * bz) - (az * by);
    out[1] = (az * bx) - (ax * bz);
    out[2] = (ax * by) - (ay * bx);
}

#if defined(VERSION_US_REV2)
#pragma GLOBAL_ASM("asm/us/nonmatchings/vector_math/Vec3f_NormalizeSafe.s")
#else
void Vec3f_NormalizeSafe(Vec3f* vec) {
    f32 x;
    f32 y;
    f32 z;
    f32 len;

    x = vec->x;
    y = vec->y;
    z = vec->z;

    len = sqrtf((x * x) + (y * y) + (z * z));

    if (len > 0.0f) {
        x = x / len;
        y = y / len;
        z = z / len;
    }

    vec->x = x;
    vec->y = y;
    vec->z = z;
}
#endif

void Mtx_BuildTranslatedDirectionRotation(Mtx* mtx, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 sp10C;
    f32 sp108;
    UNUSED s32 pad;
    UNUSED s32 pad2;
    f32 temp_fa1;
    f32 temp_fv0;
    Mtx spB8;
    Mtx sp78;
    Mtx sp38;

    temp_fa1 = arg4 - arg1;
    temp_fv0 = arg6 - arg3;
    sp108 = (f32) (((f64) (f32) MathUtil_Atan2s(-temp_fv0, temp_fa1) * 360.0) / 65535.0);
    sp10C = (f32) (((f64) (f32) MathUtil_Atan2s(-(arg5 - arg2), sqrtf((temp_fa1 * temp_fa1) + (temp_fv0 * temp_fv0))) * 360.0) / 65535.0);
    guTranslate(&spB8, arg1, arg2, arg3);
    guRotate(&sp78, sp108, 0.0f, -1.0f, 0.0f);
    guMtxCatL(&sp78, &spB8, &spB8);
    guRotate(&sp38, sp10C, 1.0f, 0.0f, 0.0f);
    guMtxCatL(&sp38, &spB8, &spB8);
    *mtx = spB8;
}

void Math_ProjectPointOntoLine(
    f32 px, f32 py, f32 pz,
    f32 ax, f32 ay, f32 az,
    f32 bx, f32 by, f32 bz,
    f32* outX, f32* outY, f32* outZ
) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 t;
    f32 lenSq = SQ(bx - ax) + SQ(by - ay) + SQ(bz - az);
    f32 dx2;
    f32 dy2;
    f32 dz2;

    if (lenSq == 0.0) {
        *outX = ax;
        *outY = ay;
        *outZ = az;
        return;
    }

    
    dx = bx - ax;
    dy = by - ay;
    dz = bz - az;
    dx2 = px - ax;
    dy2 = py - ay;
    dz2 = pz - az;

    t = ((dx * dx2) + (dy * dy2) + (dz * dz2)) / lenSq;

    *outX = ax + (t * dx);
    *outY = ay + (t * dy);
    *outZ = az + (t * dz);
}

void MtxF_ExtractScale(MtxF* arg0, MtxF* arg1) {
    f32 sp24 = sqrtf(SQ(arg1->mf[0][0]) + SQ(arg1->mf[0][1]) + SQ(arg1->mf[0][2]));
    f32 sp20 = sqrtf(SQ(arg1->mf[1][0]) + SQ(arg1->mf[1][1]) + SQ(arg1->mf[1][2]));
    f32 sp1C = sqrtf(SQ(arg1->mf[2][0]) + SQ(arg1->mf[2][1]) + SQ(arg1->mf[2][2]));

    arg0->mf[0][0] = arg1->mf[0][0] * sp24;
    arg0->mf[0][1] = arg1->mf[1][0] * sp24;
    arg0->mf[0][2] = arg1->mf[2][0] * sp24;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = arg1->mf[0][1] * sp20;
    arg0->mf[1][1] = arg1->mf[1][1] * sp20;
    arg0->mf[1][2] = arg1->mf[2][1] * sp20;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2] * sp1C;
    arg0->mf[2][1] = arg1->mf[1][2] * sp1C;
    arg0->mf[2][2] = arg1->mf[2][2] * sp1C;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = 0.0f;
    arg0->mf[3][1] = 0.0f;
    arg0->mf[3][2] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void MtxF_GetScaleVector(MtxF* arg0, Vec3f* arg1) {
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    temp_fv0 = arg0->mf[0][0];
    temp_fv1 = arg0->mf[0][1];
    temp_fa1 = arg0->mf[0][2];

    sp30 = arg0->mf[1][0];
    sp2C = arg0->mf[1][1];
    sp28 = arg0->mf[1][2];

    sp24 = arg0->mf[2][0];
    sp20 = arg0->mf[2][1];
    sp1C = arg0->mf[2][2];

    arg1->x = sqrtf(SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa1));
    arg1->y = sqrtf(SQ(sp30) + SQ(sp2C) + SQ(sp28));
    arg1->z = sqrtf(SQ(sp24) + SQ(sp20) + SQ(sp1C));
}
