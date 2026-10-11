#include "minigame_actor_framework.h"
#include "src/gfx_buffer.h"
#include "src/math_util.h"
#include "src/memory.h"
#include "src/geo_render.h"

void MiniFx_Init(void) {
    gParticlePool = main_pool_alloc(sizeof(Particle) * 300, 0);
    bzero(gParticlePool, sizeof(Particle) * 300);
    gParticlePoolIndex = 0;

    gMiniFxEmitters = main_pool_alloc(sizeof(ParticleEmitter) * 128, 0);
    bzero(gMiniFxEmitters, sizeof(ParticleEmitter) * 128);
    gMiniFxEmitterIndex = 0;
}

s32 MiniFx_AllocEmitter(void) {
    s32 i;
    s32 var_v0 = gMiniFxEmitterIndex;
    ParticleEmitter* var_v1 = &gMiniFxEmitters[var_v0];

    for (i = 0; i < 0x80; i++) {
        if (var_v1->unk_2B == 0) {
            break;
        }

        var_v0++;
        if (var_v0 >= 0x80) {
            var_v0 = 0;
            var_v1 = gMiniFxEmitters;
        } else {
            var_v1++;
        }
    }

    if (i >= 0x80) {
        var_v1 = -1;
    } else {
        var_v1->unk_2B = 1;

        gMiniFxEmitterIndex = var_v0 + 1;
        if (gMiniFxEmitterIndex >= 0x80) {
            gMiniFxEmitterIndex = 0;
        }
    }
    return var_v1;
}

void MiniFx_FreeEmitter(ParticleEmitter* arg0) {
    arg0->unk_28 = 0;
    arg0->unk_2B = 0;
    arg0->unk_2A = 0;
    arg0->unk_26 = arg0->unk_28;
}

s32 MiniFx_ConfigureEmitter(s32 arg0, s32 arg1, s8 arg2, f32 arg3, Vec3f arg4, Vec3s arg7, ParticleUpdateCallback arg9,
                  ParticleDescriptor* argA, s32 argB, u8 argC, s16 argD, u8 argE, u8 argF, u8 arg10) {
    ParticleEmitter* temp_v0 = (ParticleEmitter*)MiniFx_AllocEmitter();

    if ((s32)temp_v0 != -1) {
        temp_v0->unk_28 = arg0;
        temp_v0->unk_26 = arg1;
        temp_v0->unk_2A = arg2;
        temp_v0->unk_2C = argC;

        temp_v0->unk_00 = arg3;

        temp_v0->unk_04.x = arg4.x;
        temp_v0->unk_04.y = arg4.y;
        temp_v0->unk_04.z = arg4.z;

        temp_v0->unk_10.x = arg7.x;
        temp_v0->unk_10.y = arg7.y;
        temp_v0->unk_10.z = arg7.z;

        temp_v0->unk_18 = arg9;
        temp_v0->unk_1C = argA;
        temp_v0->unk_20 = argB;
        temp_v0->unk_24 = argD;
        temp_v0->unk_2D = argE;
        temp_v0->unk_2E = argF;
        temp_v0->unk_2F = arg10;
    }

    return (s32)temp_v0;
}

void MiniFx_ConfigureOneShotEmitter(s32 arg0, f32 arg1, Vec3f arg2, ParticleUpdateCallback arg3, ParticleDescriptor* arg4, s16 arg5,
                   u8 arg6, u8 arg7) {
    Vec3s sp50;

    sp50.x = sp50.y = sp50.z = 0;

    MiniFx_ConfigureEmitter(arg0, 0, 1, arg1, arg2, sp50, arg3, arg4, 0, 0, arg5, arg6, arg7, 0);
}

void MiniFx_ConfigureEmitterWithPeriodAndRepeat(s32 arg0, s32 arg1, s8 arg2, f32 arg3, Vec3f arg4, ParticleUpdateCallback arg7,
                   ParticleDescriptor* arg8, s16 arg9, u8 argA, u8 argB) {
    Vec3s sp50;

    sp50.x = sp50.y = sp50.z = 0;

    MiniFx_ConfigureEmitter(arg0, arg1, arg2, arg3, arg4, sp50, arg7, arg8, 0, 0, arg9, argA, argB, 0);
}

void MiniFx_ApplyEmitterToParticle(Particle* arg0, ParticleEmitter* arg1, s16 arg2) {
    if ((s32)arg0 != -1) {
        while (arg0 != NULL) {
            arg0->unk_28 = arg1->unk_00;

            ParticleMath_CopyVec3f(&arg0->unk_68, &arg1->unk_04);
            ParticleMath_CopyVec3s(&arg0->unk_94, &arg1->unk_10);

            arg0->unk_AC = arg2++;

            arg0->unk_08 = arg1->unk_18;
            arg0->unk_0C = arg1->unk_1C;

            arg0->unk_CD = arg1->unk_2F;
            arg0->unk_CE = arg1->unk_2D;
            arg0->unk_AA = arg1->unk_24;
            arg0->unk_CF = arg1->unk_2E;

            arg0 = arg0->next;
        };
    }
}

void MiniFx_EmitParticles(ParticleEmitter* arg0) {
    s16 i;
    s16 sp2C;
    ParticleDescriptor* temp_v0 = arg0->unk_1C;
    s16 temp_v1 = arg0->unk_24;
    ParticleDescriptorChild* unk_04 = temp_v0->unk_04.a;

    if ((temp_v0->unk_00 == 1) && (unk_04->unk_00 == 1)) {
        MiniFx_ApplyEmitterToParticle(Particle_AllocChain(temp_v1), arg0, 0);
    } else {
        for (i = 0; i < sp2C; i++) {
            MiniFx_ApplyEmitterToParticle(Particle_New(), arg0, i);
        }
    }
}

void MiniFx_TryEmit(ParticleEmitter* arg0) {
    if (arg0->unk_2C == 0) {
        MiniFx_EmitParticles(arg0);
    }
}

void MiniFx_TickEmitters(void) {
    s32 i;
    ParticleEmitter* var_s0 = gMiniFxEmitters;

    for (i = 0; i < 0x80; i++, var_s0++) {
        if (var_s0->unk_2B != 0) {
            var_s0->unk_28--;
            if (var_s0->unk_28 < 0) {
                MiniFx_TryEmit(var_s0);
                if (var_s0->unk_2A > 0) {
                    var_s0->unk_2A--;
                    if (var_s0->unk_2A == 0) {
                        MiniFx_FreeEmitter(var_s0);
                    }
                } else {
                    var_s0->unk_28 = var_s0->unk_26;
                }
            }
        }
    }
}

void MiniFx_SetParticleRenderScale(Particle* arg0) {
    gParticleRenderContext.unk_00.x = arg0->unk_28;
    gParticleRenderContext.unk_00.y = arg0->unk_28;
    gParticleRenderContext.unk_00.z = arg0->unk_28;
}

void MiniFx_RetireParticle(Particle* arg0) {
    if (Particle_IsInactive(arg0) != 0) {
        arg0->unk_18 = 0;
        Particle_DisableAndDetach(arg0);
        Particle_Free(arg0);
    } else {
        Particle_UpdateWorldTransform(arg0);
    }
}

void MiniFx_UpdateParticles(void) {
    s32 i;
    Particle* var_s0 = gParticlePool;

    MiniFx_TickEmitters();

    for (i = 0; i < 0x12C; i++, var_s0++) {
        if (var_s0->unk_D0 != 0) {
            MiniFx_SetParticleRenderScale(var_s0);

            var_s0->unk_08(var_s0);

            MiniFx_RetireParticle(var_s0);
        }
    }
}

void MiniFx_DrawParticles(void) {
    gSPPerspNormalize(gDisplayListHead++, D_87906054->unk_24.perspNorm);
    gSPMatrix(gDisplayListHead++, D_87906054->unk_24.mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, D_87906054->unk_60.p_mtxf, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    gParticleMatrixPool = Gfx_AllocDisplayList(sizeof(ParticleMatrixPool));
    gParticleMatrixPoolIndex = 0;

    gSPDisplayList(gDisplayListHead++, D_8140DB30);

    Particle_RenderWorldChains(D_87906054);

    gSPDisplayList(gDisplayListHead++, D_8140DAE0);
}

void MiniFx_InitRandomVelocityGravityParticle(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_SetPrimColor(arg0, 0xC8, 0xAA, 0x64);
    Particle_SetEnvColor(arg0, 0x3A, 0x18, 0x18);
    Particle_Field1C_SetScaled_0B938(arg0, (ParticleMath_RandomRange(0xA) * 0.03f) + 0.15f);

    sp28.x = ParticleMath_RandomSigned(0x400) - 0x3000;
    sp28.y = (ParticleMath_RandomSigned(0x400) + (sp26 << 0xD)) - 0x3000;
    sp28.z = 0;

    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.3f) + 6.0f);
    Particle_Field7C_SetVecFromField74AnglesXY_0B2B4(arg0);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void MiniFx_UpdateRandomVelocityGravityParticle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            MiniFx_InitRandomVelocityGravityParticle(arg0);
            break;

        case 2:
            if (arg0->unk_2C.y < 0.0f) {
                Particle_MarkInactive(arg0);
            }
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_Field7C_DecrementYUntilAtMost_0B0A4(arg0, -8.0f, 1.0f);
        Particle_Field50_AddVecFromField7C_09BDC(arg0);
    }
}

void MiniFx_InitPalette10FastRiseFadeParticle(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field74_SetScaled_0AD8C(arg0, (2.0f * MathUtil_Random_ZeroOne()) + 4.0f);
    Particle_Field7C_SetYScaled_0AF24(arg0, (MathUtil_Random_ZeroOne() * 3.0f) + 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xA);
    Particle_SetPrimAlpha(arg0, 0x64);
    Particle_FieldA6_SetS16_0BCA8(arg0, 7);
    Particle_AdvanceLifecycle(arg0);
}

void MiniFx_UpdatePalette10FastRiseFadeParticle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            MiniFx_InitPalette10FastRiseFadeParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_Field1C_Approach_0B98C(arg0, 0.8f, 0.1f);
            Particle_Field74_Approach_0ADBC(arg0, 1.0f, 1);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_Field7C_ApproachY_0B180(arg0, 0.5f, 0.4f);
                Particle_Field50_AddYFromField7C_09C6C(arg0);
            }
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
    }
}

void MiniFx_InitPalette10SlowRiseFadeParticle(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field74_SetScaled_0AD8C(arg0, (2.0f * MathUtil_Random_ZeroOne()) + 2.0f);
    Particle_Field7C_SetYScaled_0AF24(arg0, (MathUtil_Random_ZeroOne() * 3.0f) + 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xA);
    Particle_SetPrimAlpha(arg0, 0x64);
    Particle_FieldA6_SetS16_0BCA8(arg0, 7);
    Particle_AdvanceLifecycle(arg0);
}

void MiniFx_UpdatePalette10SlowRiseFadeParticle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            MiniFx_InitPalette10SlowRiseFadeParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_Field1C_Approach_0B98C(arg0, 0.8f, 0.1f);
            Particle_Field74_Approach_0ADBC(arg0, 1.0f, 1);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_Field7C_ApproachY_0B180(arg0, 0.5f, 0.4f);
                Particle_Field50_AddYFromField7C_09C6C(arg0);
            }
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
    }
}

void MiniFx_InitRandomOffsetPalette10RiseFadeParticle(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    func_8140959C(arg0, 3, 0, 3);
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field74_SetScaled_0AD8C(arg0, (MathUtil_Random_ZeroOne() * 3.0f) + 3.0f);
    Particle_Field7C_SetYScaled_0AF24(arg0, (2.0f * MathUtil_Random_ZeroOne()) + 4.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xA);
    Particle_SetPrimAlpha(arg0, 0x64);
    Particle_FieldA6_SetS16_0BCA8(arg0, 7);
    Particle_AdvanceLifecycle(arg0);
}

void MiniFx_UpdateRandomOffsetPalette10RiseFadeParticle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            MiniFx_InitRandomOffsetPalette10RiseFadeParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_Field1C_Approach_0B98C(arg0, 1.0f, 0.05f);
            Particle_Field74_Approach_0ADBC(arg0, 1.0f, 1);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_Field7C_ApproachY_0B180(arg0, 1.0f, 0.2f);
                Particle_Field50_AddYFromField7C_09C6C(arg0);
            }
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
    }
}

void MiniFx_InitSurfaceCrossingGravityParticle(Particle* arg0) {
    Vec3s sp28;

    Particle_SetPrimColor(arg0, 0xC8, 0xAA, 0x64);
    Particle_SetEnvColor(arg0, 0x3A, 0x18, 0x18);
    Particle_Field1C_SetScaled_0B938(arg0, (MathUtil_Random_ZeroOne() * 0.1f) + 0.1f);

    sp28.x = ParticleMath_RandomSigned(0x800) - 0x3800;
    sp28.y = ParticleMath_RandomSigned(0x1000) + 0x8000;
    sp28.z = 0;

    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.3f) + 6.0f);
    Particle_Field7C_SetVecFromField74AnglesXY_0B2B4(arg0);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void MiniFx_UpdateSurfaceCrossingGravityParticle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            MiniFx_InitSurfaceCrossingGravityParticle(arg0);
            break;

        case 2:
            if (arg0->unk_50.y < 0.0f) {
                Particle_MarkInactive(arg0);
            }
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        if (arg0->unk_2C.y > 0.0f) {
            Particle_EnableRendering(arg0);
        } else {
            Particle_DisableRendering(arg0);
        }
        Particle_Field7C_DecrementYUntilAtMost_0B0A4(arg0, -8.0f, 1.0f);
        Particle_Field50_AddVecFromField7C_09BDC(arg0);
    }
}

void MiniFx_InitPalette17DelayedRevealFallParticle(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_FieldCE_GetS32_0C040(arg0);

    sp28.x = ParticleMath_RandomRange(0x10000);
    sp28.y = ParticleMath_RandomRange(0x10000);
    sp28.z = 0;

    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp28);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
    Particle_Field78_SetScaled_0ADA4(arg0, 0);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
    Particle_Field1C_SetScaled_0B938(arg0, 0.0f);
    Particle_SetScaleSpeed(arg0, 0.6f);
    Particle_SetScaleTarget(arg0, 0.1f);
    func_81409404(arg0, 0x14, 0xA);
    func_8140935C(arg0, 0xF, 0xF);
    func_81409514(arg0, 0x14, 0xA);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void MiniFx_UpdatePalette17DelayedRevealFallParticle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            MiniFx_InitPalette17DelayedRevealFallParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            if (Particle_Field1C_ApproachField24AndStepState_0BA48(arg0) != 0) {
                Particle_SetScaleSpeed(arg0, 0.0f);
            }
            break;

        case 4:
            Particle_Field1C_ApproachField24AndStepState_0BA48(arg0);
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field74_AdvanceAndAddNegY_CheckField2CYNonPositive_09FD8(arg0);
        if (arg0->unk_2C.y < 0.0f) {
            Particle_MarkInactive(arg0);
        }
    }
}

void MiniFx_InitPalette17SmallDelayedRevealFallParticle(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    sp28.x = ParticleMath_RandomRange(0x10000);
    sp28.y = ParticleMath_RandomRange(0x10000);
    sp28.z = 0;

    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp28);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
    Particle_Field78_SetScaled_0ADA4(arg0, 0.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
    Particle_Field1C_SetScaled_0B938(arg0, 0.0f);
    Particle_SetScaleSpeed(arg0, 0.2f);
    Particle_SetScaleTarget(arg0, 0.035f);
    func_81409404(arg0, 7, 3);
    func_8140935C(arg0, 0x14, 0xA);
    func_81409514(arg0, 7, 3);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void MiniFx_UpdatePalette17SmallDelayedRevealFallParticle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            MiniFx_InitPalette17SmallDelayedRevealFallParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            if (Particle_Field1C_ApproachField24AndStepState_0BA48(arg0) != 0) {
                Particle_SetScaleSpeed(arg0, 0.0f);
            }
            break;

        case 4:
            Particle_Field1C_ApproachField24AndStepState_0BA48(arg0);
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field74_AdvanceAndAddNegY_CheckField2CYNonPositive_09FD8(arg0);
        if (arg0->unk_2C.y < 0.0f) {
            Particle_MarkInactive(arg0);
        }
    }
}

void MiniFx_InitCoolGravityParticle(Particle* arg0) {
    Vec3s sp30;

    Particle_SetPrimColor(arg0, 0xFF, 0xFF, 0xFF);
    Particle_SetEnvColor(arg0, 0x64, 0xC8, 0xFF);
    Particle_Field1C_SetScaled_0B938(arg0, (MathUtil_Random_ZeroOne() * 0.2f) + 0.3f);

    sp30.x = ParticleMath_RandomSigned(0x1800) - 0x3000;
    sp30.y = ParticleMath_RandomSigned(0x10000);
    sp30.z = 0;

    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp30);

    Particle_Field38_AddVecScaled_08E18(arg0, ParticleMath_RandomSigned(0xA) * 0.1f, ParticleMath_RandomRange(0xA) * 0.25f, ParticleMath_RandomSigned(0xA) * 0.1f);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(5) * 0.35f) + 4.0f);
    Particle_Field7C_SetVecFromField74AnglesXY_0B2B4(arg0);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void MiniFx_UpdateCoolGravityParticle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            MiniFx_InitCoolGravityParticle(arg0);
            break;

        case 2:
            if (arg0->unk_50.y < -2.5f) {
                Particle_MarkInactive(arg0);
            }
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_Field7C_DecrementYUntilAtMost_0B0A4(arg0, -8.0f, 0.8f);
        Particle_Field50_AddVecFromField7C_09BDC(arg0);
    }
}

void MiniFx_BuildParticleRenderListVariantA(Gfx* arg0, unk_D_86002F34_000_014* arg1, UNUSED u16 arg2) {
    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0xB4, 255, 255, 255, 128);
    gDPSetEnvColor(arg0++, 255, 255, 255, 255);
    gDPSetCombineLERP(arg0++, TEXEL0, TEXEL1, PRIM_LOD_FRAC, TEXEL1, TEXEL0, TEXEL1, PRIMITIVE, TEXEL1, 0, 0, 0,
                      COMBINED, COMBINED, 0, SHADE, 0);

    gDPLoadTextureTile(arg0++, arg1->unk_00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0, 0, 0, 31, 31, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 12, G_TX_NOLOD);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, 0xA, 0xE, 0x20, 0x20);

    gDPLoadMultiTile(arg0++, arg1->unk_04, 0x0100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0, 0, 0, 31, 31, 0,
                     G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 1, G_TX_NOLOD);

    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, 5, 7, 0x20, 0x20);

    gSPEndDisplayList(arg0++);
}

void MiniFx_GraphNodeBuildParticleRenderListVariantA(s32 arg0, arg1_func_87902F80* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        MiniFx_BuildParticleRenderListVariantA(arg1->unk_18, arg1->node.callbackArg, D_8006F084);
    }
}

void MiniFx_BuildParticleRenderListVariantB(Gfx* arg0, unk_D_86002F34_000_014* arg1, UNUSED u16 arg2) {
    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0xC8, 255, 255, 255, 180);
    gDPSetEnvColor(arg0++, 255, 255, 255, 255);
    gDPSetCombineLERP(arg0++, TEXEL0, TEXEL1, PRIM_LOD_FRAC, TEXEL1, TEXEL0, TEXEL1, PRIMITIVE, TEXEL1, 0, 0, 0,
                      COMBINED, COMBINED, 0, SHADE, 0);

    gDPLoadTextureTile(arg0++, arg1->unk_00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0, 0, 0, 31, 31, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 15, 1);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, 2, 6, 0x20, 0x20);

    gDPLoadMultiTile(arg0++, arg1->unk_04, 0x0100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0, 0, 0, 31, 31, 0,
                     G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 1, G_TX_NOLOD);

    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, -2, 0xC, 0x20, 0x20);

    gSPEndDisplayList(arg0++);
}

void MiniFx_GraphNodeBuildParticleRenderListVariantB(s32 arg0, arg1_func_87902F80* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        MiniFx_BuildParticleRenderListVariantB(arg1->unk_18, arg1->node.callbackArg, D_8006F084);
    }
}
