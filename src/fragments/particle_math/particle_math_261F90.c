#include "particle_math.h"
#include "include/math.h"
#include "src/matrix.h"
#include "src/math_util.h"

ParticleMatrixPool* gParticleMatrixPool;
s32 gParticleMatrixPoolIndex;
s32 gParticleMatrixPoolIndex;
ParticleRenderContext gParticleRenderContext;
ParticleCameraState* gParticleCameraState;
u32 gParticleFrameCounter;
s32 gParticleFrameMod64;
s32 gParticleFrameMod32;
s32 gParticleFrameMod16;
s32 gParticleFrameMod8;
s32 gParticleFrameMod4;
u32 gParticleFrameMod3;
s32 gParticleFrameMod2;
u32 gParticleFrameDiv64;
u32 gParticleFrameDiv32;
u32 gParticleFrameDiv16;
u32 gParticleFrameDiv8;
u32 gParticleFrameDiv4;
u32 gParticleFrameDiv3;
u32 gParticleFrameDiv2;
s32 gParticleFrameDiv64Parity;
s32 gParticleFrameDiv32Parity;
s32 gParticleFrameDiv16Parity;
s32 gParticleFrameDiv8Parity;
s32 gParticleFrameDiv4Parity;
s32 gParticleFrameDiv3Parity;
s32 gParticleFrameDiv2Parity;
s32 gParticleRandomOffset;
static s32 pad_D_8140E714[2];
Particle* gParticlePool;
BattleAnimEffectSlot* gBattleAnimEffectSlots;
ParticleEmitter* gMiniFxEmitters;
s32 gParticlePoolIndex;
s32 gBattleAnimEffectSlotIndex;
s32 gMiniFxEmitterIndex;

void ParticleMath_BitwiseOr(s32* arg0, s32 arg1) {
    *arg0 |= arg1;
}

void ParticleMath_BitwiseAndNot(s32* arg0, s32 arg1) {
    *arg0 &= ~arg1;
}

void ParticleMath_BitwiseXor(s32* arg0, s32 arg1) {
    *arg0 ^= arg1;
}

s32 ParticleMath_HasBits(s32* arg0, s32 arg1) {
    s32 var_v1 = 0;

    if (*arg0 & arg1) {
        var_v1 = 1;
    }
    return var_v1;
}

s32 ParticleMath_LacksBits(s32* arg0, s32 arg1) {
    s32 var_v1 = 0;

    if (!(*arg0 & arg1)) {
        var_v1 = 1;
    }
    return var_v1;
}

s32 ParticleMath_ApproachFloatUp(f32* arg0, f32 arg1, f32 arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += arg2;
        if (arg1 <= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachFloatDown(f32* arg0, f32 arg1, f32 arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= arg2;
        if (*arg0 <= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachS32Up(s32* arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += arg2;
        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachS32Down(s32* arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= arg2;
        if (arg1 >= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachS16Up(s16* arg0, s16 arg1, s16 arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += arg2;
        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachU16Up(u16* arg0, u16 arg1, u16 arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += arg2;
        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachS16Down(s16* arg0, s16 arg1, s16 arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= arg2;
        if (arg1 >= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachU16Down(u16* arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;
    s32 temp_v0 = *arg0;

    if (arg1 < temp_v0) {
        temp_v0 -= arg2;
        if (arg1 >= temp_v0) {
            temp_v0 = arg1;
            var_v1 = 1;
        }
        *arg0 = temp_v0;
    }
    return var_v1;
}

s32 ParticleMath_ApproachFloatUpByPointer(f32* arg0, f32 arg1, f32* arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += *arg2;
        if (arg1 <= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachFloatDownByPointer(f32* arg0, f32 arg1, f32* arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= *arg2;
        if (*arg0 <= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachS32UpByPointer(s32* arg0, s32 arg1, s32* arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += *arg2;
        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachS32DownByPointer(s32* arg0, s32 arg1, s32* arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= *arg2;
        if (arg1 >= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachS16UpByPointer(s16* arg0, s16 arg1, s16* arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += *arg2;
        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachS16DownByPointer(s16* arg0, s16 arg1, s16* arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= *arg2;
        if (arg1 >= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 ParticleMath_ApproachS8(s8* arg0, s8 arg1, s8 arg2) {
    s32 var_v1 = 0;
    s32 var_a3 = *arg0;

    if (var_a3 < arg1) {
        if (arg2 >= 0) {
            var_a3 += arg2;
        } else {
            var_a3 -= arg2;
        }

        if (var_a3 >= arg1) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else if (arg1 < var_a3) {
        if (arg2 >= 0) {
            var_a3 -= arg2;
        } else {
            var_a3 += arg2;
        }

        if (arg1 >= var_a3) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else {
        var_v1 = 1;
    }

    *arg0 = var_a3;
    return var_v1;
}

s32 ParticleMath_ApproachU8(u8* arg0, u8 arg1, u8 arg2) {
    s32 var_v1 = 0;
    s32 var_a3 = *arg0;

    if (var_a3 < arg1) {
        var_a3 += arg2;
        if (var_a3 >= arg1) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else if (arg1 < var_a3) {
        var_a3 -= arg2;
        if (arg1 >= var_a3) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else {
        var_v1 = 1;
    }

    *arg0 = var_a3;
    return var_v1;
}

s32 ParticleMath_ApproachS16(s16* arg0, s16 arg1, s16 arg2) {
    s32 var_v1 = 0;
    s32 var_a3 = *arg0;

    if (var_a3 < arg1) {
        if (arg2 >= 0) {
            var_a3 += arg2;
        } else {
            var_a3 -= arg2;
        }

        if (var_a3 >= arg1) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else if (arg1 < var_a3) {
        if (arg2 >= 0) {
            var_a3 -= arg2;
        } else {
            var_a3 += arg2;
        }

        if (arg1 >= var_a3) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else {
        var_v1 = 1;
    }

    *arg0 = var_a3;
    return var_v1;
}

s32 ParticleMath_ApproachAngle(s16* arg0, s16 arg1, s16 arg2) {
    s32 a0 = *(u16*)arg0;
    s32 var_v1 = 0;
    s32 var_a1 = (u16)arg1;

    if ((u16)arg1 == a0) {
        var_a1 = (u16)arg1;
        var_v1 = 1;
    } else {
        var_a1 = (u16)arg1 - a0;
        if (var_a1 < -0x8000) {
            var_a1 = arg2 + a0;
            if (((u16)arg1 - var_a1) <= -65536) {
                var_a1 = (u16)arg1;
                var_v1 = 1;
            }
        } else if (var_a1 < 0) {
            var_a1 = a0 - arg2;
            if (((u16)arg1 - var_a1) >= 0) {
                var_a1 = (u16)arg1;
                var_v1 = 1;
            }
        } else if (var_a1 < 0x8000) {
            var_a1 = arg2 + a0;
            if (((u16)arg1 - var_a1) <= 0) {
                var_a1 = (u16)arg1;
                var_v1 = 1;
            }
        } else {
            var_a1 = a0 - arg2;
            if (((u16)arg1 - var_a1) >= 0x10000) {
                var_a1 = (u16)arg1;
                var_v1 = 1;
            }
        }
    }

    *arg0 = var_a1;
    return var_v1;
}

s32 ParticleMath_ApproachS32(s32* arg0, s32 arg1, s32 arg2) {
    s32 temp_v0 = *arg0;
    s32 var_v1 = 0;

    if (temp_v0 < arg1) {
        if (arg2 >= 0) {
            *arg0 = temp_v0 + arg2;
        } else {
            *arg0 = temp_v0 - arg2;
        }

        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    } else if (arg1 < temp_v0) {
        if (arg2 >= 0) {
            *arg0 = temp_v0 - arg2;
        } else {
            *arg0 = temp_v0 + arg2;
        }

        if (arg1 >= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    } else {
        var_v1 = 1;
    }

    return var_v1;
}

s32 ParticleMath_ApproachFloat(f32* arg0, f32 arg1, f32 arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        if (arg2 >= 0.0f) {
            *arg0 += arg2;
        } else {
            *arg0 -= arg2;
        }

        if (arg1 <= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    } else if (arg1 < *arg0) {
        if (arg2 >= 0.0f) {
            *arg0 -= arg2;
        } else {
            *arg0 += arg2;
        }

        if (*arg0 <= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    } else {
        var_v1 = 1;
    }

    return var_v1;
}

void ParticleMath_BounceFloat(f32* arg0, f32 arg1, f32 arg2, f32* arg3) {
    *arg0 += *arg3;

    if (*arg3 >= 0.0f) {
        if (arg2 <= *arg0) {
            *arg0 = arg2;
            *arg3 = -*arg3;
        }
    } else if (*arg0 <= arg1) {
        *arg0 = arg1;
        *arg3 = -*arg3;
    }
}

void ParticleMath_BounceS16(s16* arg0, s16 arg1, s16 arg2, s16* arg3) {
    *arg0 += *arg3;
    if (*arg3 >= 0) {
        if (*arg0 >= arg2) {
            *arg0 = arg2;
            *arg3 = -*arg3;
        }
    } else if (arg1 >= *arg0) {
        *arg0 = arg1;
        *arg3 = -*arg3;
    }
}

void ParticleMath_CopyVec3f(Vec3f* arg0, Vec3f* arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
    arg0->z = arg1->z;
}

void ParticleMath_CopyVec3s(Vec3s* arg0, Vec3s* arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
    arg0->z = arg1->z;
}

void ParticleMath_AddVec3f(Vec3f* arg0, Vec3f* arg1) {
    arg0->x += arg1->x;
    arg0->y += arg1->y;
    arg0->z += arg1->z;
}

void ParticleMath_AddVec3s(Vec3s* arg0, Vec3s* arg1) {
    arg0->x += arg1->x;
    arg0->y += arg1->y;
    arg0->z += arg1->z;
}

f32 ParticleMath_DotVec3f(Vec3f arg0, Vec3f arg1) {
    return (arg0.x * arg1.x) + (arg0.y * arg1.y) + (arg0.z * arg1.z);
}

s32 ParticleMath_IsWithinRadius2D(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 var_v1 = 0;

    if ((SQ(arg2 - arg0) + SQ(arg3 - arg1)) <= SQ(arg4)) {
        var_v1 = 1;
    }
    return var_v1;
}

void ParticleMath_AdvanceRandomOffset(void) {
    gParticleRandomOffset++;
}

u32 ParticleMath_RandomRange(s32 arg0) {
    u32 temp_a0 = guRandom() + gParticleRandomOffset;
    u32 var_v1;

    if (arg0 == 0) {
        var_v1 = 0;
    } else {
        var_v1 = (temp_a0 / 10) % arg0;
    }
    return var_v1;
}

s32 ParticleMath_RandomRangeOffset(s32 arg0, s32 arg1) {
    return ParticleMath_RandomRange(arg0) + arg1;
}

s32 ParticleMath_RandomSigned(s32 arg0) {
    return ParticleMath_RandomRange(arg0 * 2) - arg0;
}

s32 ParticleMath_RandomSignedOffset(s32 arg0, s32 arg1) {
    return ParticleMath_RandomSigned(arg0) + arg1;
}

s32 ParticleMath_RandomSignedOffsetBySign(s32 arg0, s32 arg1) {
    s32 temp_v0 = ParticleMath_RandomSigned(arg0);

    if (temp_v0 >= 0) {
        temp_v0 += arg1;
    } else {
        temp_v0 -= arg1;
    }
    return temp_v0;
}

void ParticleMath_NoopStub(UNUSED s32 arg0) {
}

s16 ParticleMath_Atan2YZ(Vec3f arg0) {
    return MathUtil_Atan2s(arg0.y, arg0.z);
}

s16 ParticleMath_Atan2ZX(Vec3f arg0) {
    return MathUtil_Atan2s(arg0.z, arg0.x);
}

s16 ParticleMath_Atan2XY(Vec3f arg0) {
    return MathUtil_Atan2s(arg0.x, arg0.y);
}

void ParticleMath_Vec3ToAngles(Vec3s* arg0, Vec3f arg1) {
    arg0->x = MathUtil_Atan2s(arg1.y, arg1.z);
    arg0->y = MathUtil_Atan2s(arg1.z, arg1.x);
    arg0->z = MathUtil_Atan2s(arg1.x, arg1.y);
}

f32 ParticleMath_Rotate2DX(f32 arg0, f32 arg1, s16 arg2) {
    return (COSS(arg2) * arg0) - (SINS(arg2) * arg1);
}

f32 ParticleMath_Rotate2DY(f32 arg0, f32 arg1, s16 arg2) {
    return (SINS(arg2) * arg0) + (COSS(arg2) * arg1);
}

Vec3f* ParticleMath_RotateVec3fY(Vec3f* arg0, Vec3f arg1, Vec3s arg2) {
    f32 temp_fv0 = SINS(arg2.y);
    f32 temp_fv1 = COSS(arg2.y);

    arg0->x = (arg1.x * temp_fv1) + (arg1.z * temp_fv0);
    arg0->y = arg1.y;
    arg0->z = (-arg1.x * temp_fv0) + (arg1.z * temp_fv1);

    return arg0;
}

Vec3f* ParticleMath_MakeXZVectorFromAngle(Vec3f* arg0, f32 arg1, s16 arg2) {
    f32 temp_fv0 = SINS(arg2);
    f32 temp_fv1 = COSS(arg2);

    arg0->x = arg1 * temp_fv0;
    arg0->y = 0.0f;
    arg0->z = arg1 * temp_fv1;

    return arg0;
}

Vec3f* ParticleMath_RotateVec3fXY(Vec3f* arg0, Vec3f arg1, Vec3s arg4) {
    f32 x = arg1.x;
    f32 y = arg1.y;
    f32 z = arg1.z;
    f32 temp_fv0 = SINS(arg4.x);
    f32 temp_fv1 = COSS(arg4.x);
    f32 temp_ft4 = SINS(arg4.y);
    f32 temp_ft5 = COSS(arg4.y);

    arg0->x = (x * temp_ft5) + (z * temp_ft4);
    arg0->y = ((x * temp_fv0 * temp_ft4) + (y * temp_fv1)) - (z * temp_fv0 * temp_ft5);
    arg0->z = (-x * temp_fv1 * temp_ft4) + (y * temp_fv0) + (z * temp_fv1 * temp_ft5);

    return arg0;
}

f32 ParticleMath_Distance3D(Vec3f arg0, Vec3f arg1) {
    return sqrtf(SQ(arg1.x - arg0.x) + SQ(arg1.y - arg0.y) + SQ(arg1.z - arg0.z));
}

f32 ParticleMath_DistanceXZ(Vec3f arg0, Vec3f arg1) {
    return sqrtf(SQ(arg1.x - arg0.x) + SQ(arg1.z - arg0.z));
}

Vec3f* ParticleMath_NormalizedDirection(Vec3f* arg0, Vec3f arg1, Vec3f arg2) {
    arg0->x = arg2.x - arg1.x;
    arg0->y = arg2.y - arg1.y;
    arg0->z = arg2.z - arg1.z;

    Vec3f_Normalize(arg0);

    return arg0;
}

s32 ParticleMath_DistanceScaled(Vec3f arg0, Vec3f arg1, f32 arg2) {
    return ParticleMath_Distance3D(arg0, arg1) / arg2;
}

s32 ParticleMath_ScaleDirectionToLength(Vec3f* arg0, Vec3f arg1, Vec3f arg2, f32 arg3) {
    f32 temp_fv1;

    arg0->x = arg2.x - arg1.x;
    arg0->y = arg2.y - arg1.y;
    arg0->z = arg2.z - arg1.z;

    temp_fv1 = arg3 / sqrtf(SQ(arg0->x) + SQ(arg0->y) + SQ(arg0->z));

    arg0->x = arg0->x * temp_fv1;
    arg0->y = arg0->y * temp_fv1;
    arg0->z = arg0->z * temp_fv1;

    return 1.0f / temp_fv1;
}

Vec3f* ParticleMath_RandomDirection(Vec3f* arg0, f32 arg1) {
    Vec3f sp2C;
    Vec3s sp24;

    sp2C.x = 0.0f;
    sp2C.y = 0.0f;
    sp2C.z = arg1;

    sp24.x = ParticleMath_RandomRange(0x10000);
    sp24.y = ParticleMath_RandomRange(0x10000);

    ParticleMath_RotateVec3fXY(arg0, sp2C, sp24);
    return arg0;
}

Vec3f* ParticleMath_ScaleVec3f(Vec3f* arg0, f32 arg1) {
    arg0->x *= arg1;
    arg0->y *= arg1;
    arg0->z *= arg1;

    return arg0;
}

s16 ParticleMath_AngleXBetweenPoints(Vec3f arg0, Vec3f arg1) {
    return MathUtil_Atan2s(arg1.y - arg0.y, arg1.z - arg0.z);
}

s16 ParticleMath_AngleYBetweenPoints(Vec3f arg0, Vec3f arg1) {
    return MathUtil_Atan2s(arg1.z - arg0.z, arg1.x - arg0.x);
}

s16 ParticleMath_AngleZBetweenPoints(Vec3f arg0, Vec3f arg1) {
    return MathUtil_Atan2s(arg1.x - arg0.x, arg1.y - arg0.y);
}

s16 ParticleMath_ApproachAngleCoarse(s16 arg0, s16 arg1) {
    s16 temp_v0 = arg1 - arg0;

    if ((arg0 >> 8) != (arg1 >> 8)) {
        if (temp_v0 < 0x400) {
            arg0 += 0x80;
        } else if (temp_v0 < 0x800) {
            arg0 += 0x200;
        } else if (temp_v0 < 0x4000) {
            arg0 += 0x400;
        } else if (temp_v0 < 0x8000) {
            arg0 += 0x700;
        } else if (temp_v0 < 0xC000) {
            arg0 -= 0x700;
        } else if (temp_v0 < 0xF800) {
            arg0 -= 0x400;
        } else if (temp_v0 < 0xFC00) {
            arg0 -= 0x200;
        } else {
            arg0 -= 0x80;
        }
    } else {
        arg0 = arg1;
    }

    return arg0;
}

void ParticleGfx_NoopStub1(void) {
}

void ParticleGfx_PushMatrix(MtxF* arg0) {
    if (gParticleMatrixPoolIndex < 0x16C) {
        MtxF_ToFixed(&gParticleMatrixPool->unk_0000[gParticleMatrixPoolIndex], arg0);

        gSPMatrix(gDisplayListHead++, (u32)&gParticleMatrixPool->unk_0000[gParticleMatrixPoolIndex] & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gParticleMatrixPoolIndex++;
    }
}

void ParticleGfx_Build2DTransformMatrix(MtxF* arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    f32 temp_fv0 = SINS(arg3) * arg4;
    f32 temp_fv1 = COSS(arg3) * arg4;

    arg0->mf[0][0] = temp_fv1;
    arg0->mf[0][1] = -temp_fv0;
    arg0->mf[0][2] = 0.0f;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = temp_fv0;
    arg0->mf[1][1] = temp_fv1;
    arg0->mf[1][2] = 0.0f;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = 0.0f;
    arg0->mf[2][1] = 0.0f;
    arg0->mf[2][2] = 1.0f;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg1;
    arg0->mf[3][1] = arg2;
    arg0->mf[3][2] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void ParticleGfx_Build2DTransformMatrixYScaled(MtxF* arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    f32 temp_fv0 = SINS(arg3);
    f32 temp_fv1 = COSS(arg3);

    arg0->mf[0][0] = temp_fv1;
    arg0->mf[0][1] = -temp_fv0;
    arg0->mf[0][2] = 0.0f;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = temp_fv0 * arg4;
    arg0->mf[1][1] = temp_fv1 * arg4;
    arg0->mf[1][2] = 0.0f;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = 0.0f;
    arg0->mf[2][1] = 0.0f;
    arg0->mf[2][2] = 1.0f;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg1;
    arg0->mf[3][1] = arg2;
    arg0->mf[3][2] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void ParticleGfx_Push2DTransform(s16 arg0, s16 arg1, s16 arg2, f32 arg3) {
    MtxF sp20;

    ParticleGfx_Build2DTransformMatrix(&sp20, arg0, arg1, arg2 + 0x8000, arg3);
    ParticleGfx_PushMatrix(&sp20);
}

void ParticleGfx_Push2DTransformYScaled(s16 arg0, s16 arg1, s16 arg2, f32 arg3) {
    MtxF sp20;

    ParticleGfx_Build2DTransformMatrixYScaled(&sp20, arg0, arg1, arg2 + 0x8000, arg3);
    ParticleGfx_PushMatrix(&sp20);
}

void ParticleGfx_BuildTransformMatrix(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3) {
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_ft4;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_ft4 = SINS(arg2.x);
    temp_fv0 = COSS(arg2.x);

    temp_fv1 = SINS(arg2.y);
    temp_fa1 = COSS(arg2.y);

    temp_fs0 = SINS(arg2.z);
    temp_fs1 = COSS(arg2.z);

    arg0->mf[0][0] = ((temp_fa1 * temp_fs1) + (temp_ft4 * temp_fv1 * temp_fs0)) * arg3;
    arg0->mf[0][1] = temp_fv0 * temp_fs0 * arg3;
    arg0->mf[0][2] = ((-temp_fv1 * temp_fs1) + (temp_ft4 * temp_fa1 * temp_fs0)) * arg3;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = ((-temp_fa1 * temp_fs0) + (temp_ft4 * temp_fv1 * temp_fs1)) * arg3;
    arg0->mf[1][1] = temp_fv0 * temp_fs1 * arg3;
    arg0->mf[1][2] = ((temp_fv1 * temp_fs0) + (temp_ft4 * temp_fa1 * temp_fs1)) * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = temp_fv0 * temp_fv1 * arg3;
    arg0->mf[2][1] = -temp_ft4 * arg3;
    arg0->mf[2][2] = temp_fv0 * temp_fa1 * arg3;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg1.x;
    arg0->mf[3][1] = arg1.y;
    arg0->mf[3][2] = arg1.z;
    arg0->mf[3][3] = 1.0f;
}

void ParticleGfx_BuildTransformMatrixYScaled(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fa1 = SINS(arg2.x);
    temp_fv0 = COSS(arg2.x);

    temp_fv1 = SINS(arg2.y);
    temp_fa0 = COSS(arg2.y);

    temp_ft5 = SINS(arg2.z);
    temp_fs0 = COSS(arg2.z);

    arg0->mf[0][0] = (temp_fa0 * temp_fs0) + (temp_fa1 * temp_fv1 * temp_ft5);
    arg0->mf[0][1] = temp_fv0 * temp_ft5;
    arg0->mf[0][2] = (-temp_fv1 * temp_fs0) + (temp_fa1 * temp_fa0 * temp_ft5);
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = ((-temp_fa0 * temp_ft5) + (temp_fa1 * temp_fv1 * temp_fs0)) * arg3;
    arg0->mf[1][1] = temp_fv0 * temp_fs0 * arg3;
    arg0->mf[1][2] = ((temp_fv1 * temp_ft5) + (temp_fa1 * temp_fa0 * temp_fs0)) * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = temp_fv0 * temp_fv1;
    arg0->mf[2][1] = -temp_fa1;
    arg0->mf[2][2] = temp_fv0 * temp_fa0;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg1.x;
    arg0->mf[3][1] = arg1.y;
    arg0->mf[3][2] = arg1.z;
    arg0->mf[3][3] = 1.0f;
}

void ParticleGfx_BuildTransformMatrixXYScaled(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3, f32 arg4) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fa1 = SINS(arg2.x);
    temp_fv0 = COSS(arg2.x);

    temp_fv1 = SINS(arg2.y);
    temp_fa0 = COSS(arg2.y);

    temp_ft5 = SINS(arg2.z);
    temp_fs0 = COSS(arg2.z);

    arg0->mf[0][0] = ((temp_fa0 * temp_fs0) + (temp_fa1 * temp_fv1 * temp_ft5)) * arg3;
    arg0->mf[0][1] = temp_fv0 * temp_ft5 * arg3;
    arg0->mf[0][2] = ((-temp_fv1 * temp_fs0) + (temp_fa1 * temp_fa0 * temp_ft5)) * arg3;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = ((-temp_fa0 * temp_ft5) + (temp_fa1 * temp_fv1 * temp_fs0)) * arg4;
    arg0->mf[1][1] = temp_fv0 * temp_fs0 * arg4;
    arg0->mf[1][2] = ((temp_fv1 * temp_ft5) + (temp_fa1 * temp_fa0 * temp_fs0)) * arg4;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = temp_fv0 * temp_fv1;
    arg0->mf[2][1] = -temp_fa1;
    arg0->mf[2][2] = temp_fv0 * temp_fa0;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg1.x;
    arg0->mf[3][1] = arg1.y;
    arg0->mf[3][2] = arg1.z;
    arg0->mf[3][3] = 1.0f;
}

void ParticleGfx_BuildBillboardMatrix(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3) {
    arg0->mf[0][0] = arg1->mf[0][0] * arg3;
    arg0->mf[0][1] = arg1->mf[1][0] * arg3;
    arg0->mf[0][2] = arg1->mf[2][0] * arg3;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = arg1->mf[0][1] * arg3;
    arg0->mf[1][1] = arg1->mf[1][1] * arg3;
    arg0->mf[1][2] = arg1->mf[2][1] * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2] * arg3;
    arg0->mf[2][1] = arg1->mf[1][2] * arg3;
    arg0->mf[2][2] = arg1->mf[2][2] * arg3;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg2.x;
    arg0->mf[3][1] = arg2.y;
    arg0->mf[3][2] = arg2.z;
    arg0->mf[3][3] = 1.0f;
}

void ParticleGfx_BuildBillboardMatrixYScaled(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3) {
    arg0->mf[0][0] = arg1->mf[0][0];
    arg0->mf[0][1] = arg1->mf[1][0];
    arg0->mf[0][2] = arg1->mf[2][0];
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = arg1->mf[0][1] * arg3;
    arg0->mf[1][1] = arg1->mf[1][1] * arg3;
    arg0->mf[1][2] = arg1->mf[2][1] * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2];
    arg0->mf[2][1] = arg1->mf[1][2];
    arg0->mf[2][2] = arg1->mf[2][2];
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg2.x;
    arg0->mf[3][1] = arg2.y;
    arg0->mf[3][2] = arg2.z;
    arg0->mf[3][3] = 1.0f;
}

void ParticleGfx_BuildBillboardRotatedMatrix(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3, s16 arg4) {
    f32 temp_fv0 = SINS(arg4);
    f32 temp_fv1 = COSS(arg4);

    arg0->mf[0][0] = ((arg1->mf[0][0] * temp_fv1) + (arg1->mf[0][1] * temp_fv0)) * arg3;
    arg0->mf[0][1] = ((arg1->mf[1][0] * temp_fv1) + (arg1->mf[1][1] * temp_fv0)) * arg3;
    arg0->mf[0][2] = ((arg1->mf[2][0] * temp_fv1) + (arg1->mf[2][1] * temp_fv0)) * arg3;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = ((arg1->mf[0][0] * -temp_fv0) + (arg1->mf[0][1] * temp_fv1)) * arg3;
    arg0->mf[1][1] = ((arg1->mf[1][0] * -temp_fv0) + (arg1->mf[1][1] * temp_fv1)) * arg3;
    arg0->mf[1][2] = ((arg1->mf[2][0] * -temp_fv0) + (arg1->mf[2][1] * temp_fv1)) * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2] * arg3;
    arg0->mf[2][1] = arg1->mf[1][2] * arg3;
    arg0->mf[2][2] = arg1->mf[2][2] * arg3;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg2.x;
    arg0->mf[3][1] = arg2.y;
    arg0->mf[3][2] = arg2.z;
    arg0->mf[3][3] = 1.0f;
}

void ParticleGfx_BuildBillboardRotatedMatrixYScaled(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3, s16 arg4) {
    f32 temp_fv0 = SINS(arg4);
    f32 temp_fv1 = COSS(arg4);

    arg0->mf[0][0] = (arg1->mf[0][0] * temp_fv1) + (arg1->mf[0][1] * temp_fv0);
    arg0->mf[0][1] = (arg1->mf[1][0] * temp_fv1) + (arg1->mf[1][1] * temp_fv0);
    arg0->mf[0][2] = (arg1->mf[2][0] * temp_fv1) + (arg1->mf[2][1] * temp_fv0);
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = ((arg1->mf[0][0] * -temp_fv0) + (arg1->mf[0][1] * temp_fv1)) * arg3;
    arg0->mf[1][1] = ((arg1->mf[1][0] * -temp_fv0) + (arg1->mf[1][1] * temp_fv1)) * arg3;
    arg0->mf[1][2] = ((arg1->mf[2][0] * -temp_fv0) + (arg1->mf[2][1] * temp_fv1)) * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2];
    arg0->mf[2][1] = arg1->mf[1][2];
    arg0->mf[2][2] = arg1->mf[2][2];
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg2.x;
    arg0->mf[3][1] = arg2.y;
    arg0->mf[3][2] = arg2.z;
    arg0->mf[3][3] = 1.0f;
}

void ParticleGfx_BuildDirectionMatrix(MtxF* arg0, Vec3f arg1, Vec3f arg2, s16 arg3, f32 arg4) {
    Vec3f sp3C;
    Vec3f sp30;
    Vec3f sp24;

    Vec3f_SetComponentsDuplicate(&sp3C, SINS(arg3), 0.0f, COSS(arg3));
    Vec3f_Normalize(&arg1);
    Vec3f_CrossProduct(&sp30, &arg1, &sp3C);
    Vec3f_Normalize(&sp30);
    Vec3f_CrossProduct(&sp24, &sp30, &arg1);
    Vec3f_Normalize(&sp24);

    arg0->mf[0][0] = sp30.x * arg4;
    arg0->mf[0][1] = sp30.y * arg4;
    arg0->mf[0][2] = sp30.z * arg4;
    arg0->mf[3][0] = arg2.x;

    arg0->mf[1][0] = arg1.x * arg4;
    arg0->mf[1][1] = arg1.y * arg4;
    arg0->mf[1][2] = arg1.z * arg4;
    arg0->mf[3][1] = arg2.y;

    arg0->mf[2][0] = sp24.x * arg4;
    arg0->mf[2][1] = sp24.y * arg4;
    arg0->mf[2][2] = sp24.z * arg4;
    arg0->mf[3][2] = arg2.z;

    arg0->mf[0][3] = 0.0f;
    arg0->mf[1][3] = 0.0f;
    arg0->mf[2][3] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void ParticleGfx_PushTransformMatrix(Vec3f arg0, Vec3s arg1, f32 arg2) {
    MtxF sp28;

    ParticleGfx_BuildTransformMatrix(&sp28, arg0, arg1, arg2);
    ParticleGfx_PushMatrix(&sp28);
}

void ParticleGfx_PushTransformMatrixYScaled(Vec3f arg0, Vec3s arg1, f32 arg2) {
    MtxF sp28;

    ParticleGfx_BuildTransformMatrixYScaled(&sp28, arg0, arg1, arg2);
    ParticleGfx_PushMatrix(&sp28);
}

void ParticleGfx_PushTransformMatrixXYScaled(Vec3f arg0, Vec3s arg1, f32 arg2, f32 arg3) {
    MtxF sp28;

    ParticleGfx_BuildTransformMatrixXYScaled(&sp28, arg0, arg1, arg2, arg3);
    ParticleGfx_PushMatrix(&sp28);
}

void ParticleGfx_PushBillboardMatrix(CameraNode* arg0, Vec3f arg1, f32 arg4) {
    MtxF sp20;

    ParticleGfx_BuildBillboardMatrix(&sp20, &arg0->view.floatMatrix, arg1, arg4);
    ParticleGfx_PushMatrix(&sp20);
}

void ParticleGfx_PushBillboardRotatedMatrix(CameraNode* arg0, Vec3f arg1, f32 arg4, s16 arg5) {
    MtxF sp28;

    ParticleGfx_BuildBillboardRotatedMatrix(&sp28, &arg0->view.floatMatrix, arg1, arg4, arg5);
    ParticleGfx_PushMatrix(&sp28);
}

void ParticleGfx_PushBillboardMatrixYScaled(CameraNode* arg0, Vec3f arg1, f32 arg4) {
    MtxF sp20;

    ParticleGfx_BuildBillboardMatrixYScaled(&sp20, &arg0->view.floatMatrix, arg1, arg4);
    ParticleGfx_PushMatrix(&sp20);
}

void ParticleGfx_PushBillboardRotatedMatrixYScaled(CameraNode* arg0, Vec3f arg1, f32 arg4, s16 arg5) {
    MtxF sp28;

    ParticleGfx_BuildBillboardRotatedMatrixYScaled(&sp28, &arg0->view.floatMatrix, arg1, arg4, arg5);
    ParticleGfx_PushMatrix(&sp28);
}

void ParticleGfx_PushTransformMatrixWithHalfTurnXY(Vec3f arg0, Vec3s arg3, f32 arg5) {
    MtxF sp30;
    Vec3s sp28;

    sp28.x = arg3.x + 0x8000;
    sp28.y = arg3.y + 0x8000;
    sp28.z = arg3.z;

    ParticleGfx_BuildTransformMatrix(&sp30, arg0, sp28, arg5);
    ParticleGfx_PushMatrix(&sp30);
}

void ParticleGfx_PushDirectionMatrix(Vec3f arg0, Vec3f arg3, f32 arg6) {
    MtxF sp30;

    ParticleGfx_BuildDirectionMatrix(&sp30, arg3, arg0, 0, arg6);
    ParticleGfx_PushMatrix(&sp30);
}
