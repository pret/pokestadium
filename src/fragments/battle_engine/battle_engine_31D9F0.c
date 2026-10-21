#include "battle_engine.h"
#include "src/model_renderer.h"

void BattleAnim_CallbackStartEffects23And35And84Descriptor4FColorCycleScaleFade_InitParticle(Particle* arg0, s16 arg1) {
    UNUSED s32 pad[3];
    s16 sp22 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
    Particle_Field94_AddX_0A578(arg0, ParticleMath_RandomSignedOffset(0x400, 0xE00));
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomSigned(0x400));
    Particle_Field74_SetScaled_0AD8C(arg0, 2.5f);

    switch (arg1) {
        case 0:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
            break;

        case 1:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x18);
            break;
    }

    Particle_FieldA6_SetS16_0BCA8(arg0, sp22 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects23And35And84Descriptor4FColorCycleScaleFade_AdvancePhase(Particle* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (Particle_TickPhaseTimer(arg0, 2) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;

        case 2:
            Particle_Field94_DecrementXTo_0A7DC(arg0, -0x400, 0x200);
            if (Particle_TickPhaseTimer(arg0, 0x10) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;
    }

    if (arg0->unk_B8 > 0) {
        Particle_AddVelocityFromRotationTemplate1(arg0);
    }
}

void BattleAnim_CallbackStartEffects23And35And84Descriptor4FColorCycleScaleFade(Particle* arg0) {
    s16 sp2E = Particle_FieldCF_GetS16_0C058(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects23And35And84Descriptor4FColorCycleScaleFade_InitParticle(arg0, sp2E);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_BeginPhase(arg0);
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xB);
            }
            break;

        case 3:
            Particle_Field1C_Approach_0B98C(arg0, 0.75f, 0.03f);

            switch (sp2E) {
                case 0:
                    Particle_PrimB_Approach_0BB44(arg0, 0, 0x18);
                    Particle_EnvG_Approach_0BBF0(arg0, 0, 0x18);
                    break;

                case 1:
                    Particle_PrimR_Approach_0BAE4(arg0, 0, 0x18);
                    Particle_EnvG_Approach_0BBF0(arg0, 0x78, 0xC);
                    break;
            }

            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xC);
            }
            break;

        case 4:
            Particle_Field1C_Approach_0B98C(arg0, 0.75f, 0.02f);
            switch (sp2E) {
                case 0:
                    Particle_PrimG_Approach_0BB14(arg0, 0, 0x10);
                    Particle_EnvR_Approach_0BB90(arg0, 0, 0x10);
                    break;

                case 1:
                    Particle_PrimG_Approach_0BB14(arg0, 0x78, 0xC);
                    Particle_EnvG_Approach_0BBF0(arg0, 0, 0xA);
                    break;
            }

            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x18) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_AnimateFramesForward(arg0, 0, 7, 1, 2, -1);
        BattleAnim_CallbackStartEffects23And35And84Descriptor4FColorCycleScaleFade_AdvancePhase(arg0);
    }
}

void BattleAnim_SetupUnusedDescriptor4FColorCycleScaleFadeVariant(Particle* arg0) {
    UNUSED s32 pad[3];
    s16 sp22 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomSigned(0x400));
    Particle_Field74_SetScaled_0AD8C(arg0, D_84392058[0]);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp22 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_MotionUnusedDescriptor4FColorCycleScaleFadeVariant(Particle* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (Particle_TickPhaseTimer(arg0, 2) != 0) {
                Particle_AdvancePhase(arg0);
                Particle_Field94_AddZ_0A5B0(arg0, 0x2900);
            }
            break;

        case 2:
            Particle_Field94_AddX_0A578(arg0, 0xC00);
            break;
    }

    if (arg0->unk_B8 > 0) {
        Particle_AddVelocityFromRotationTemplate7B(arg0);
    }
}

void BattleAnim_CallbackUnusedDescriptor4FColorCycleScaleFadeVariant(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupUnusedDescriptor4FColorCycleScaleFadeVariant(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_BeginPhase(arg0);
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xB);
            }
            break;

        case 3:
            Particle_Field1C_Approach_0B98C(arg0, 0.75f, 0.03f);
            Particle_PrimB_Approach_0BB44(arg0, 0, 0x18);
            Particle_EnvG_Approach_0BBF0(arg0, 0, 0x20);
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xC);
            }
            break;

        case 4:
            Particle_Field1C_Approach_0B98C(arg0, 0.75f, 0.02f);
            Particle_PrimG_Approach_0BB14(arg0, 0, 0x10);
            Particle_EnvR_Approach_0BB90(arg0, 0, 0x10);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0xC) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_AnimateFramesForward(arg0, 0, 7, 1, 2, -1);
        BattleAnim_MotionUnusedDescriptor4FColorCycleScaleFadeVariant(arg0);
    }
}

void BattleAnim_CallbackStartEffects23And35And84Descriptor3DAlphaScaleFade_InitParticle(Particle* arg0) {
    UNUSED s32 pad[3];
    s16 sp22 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp20 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.4f);
    Particle_Field94_AddX_0A578(arg0, ParticleMath_RandomSignedOffset(0x200, 0xE00));
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomSigned(0x1800));
    Particle_Field74_SetScaled_0AD8C(arg0, 2.0f);

    switch (sp20) {
        case 0:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1A);
            break;

        case 1:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 6);
            break;
    }

    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp22 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects23And35And84Descriptor3DAlphaScaleFade_AdvancePhase(Particle* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (Particle_TickPhaseTimer(arg0, 1) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;

        case 2:
            Particle_Field94_DecrementXTo_0A7DC(arg0, -0x1800, 0x800);
            if (Particle_TickPhaseTimer(arg0, 0x10) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;
    }

    if (arg0->unk_B8 > 0) {
        Particle_AddVelocityFromRotationTemplate1(arg0);
    }
}

void BattleAnim_CallbackStartEffects23And35And84Descriptor3DAlphaScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects23And35And84Descriptor3DAlphaScaleFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_BeginPhase(arg0);
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 4);
            Particle_Field1C_Approach_0B98C(arg0, 0.75f, 0.05f);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        BattleAnim_CallbackStartEffects23And35And84Descriptor3DAlphaScaleFade_AdvancePhase(arg0);
    }
}

void BattleAnim_CallbackStartEffects23And35And84Descriptor4FRotatingFallColorCycle_InitParticle(Particle* arg0, s16 arg1) {
    UNUSED s32 pad[3];
    s16 sp22 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    Particle_Field94_AddX_0A578(arg0, ParticleMath_RandomSignedOffset(0x200, 0xE00));
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomSigned(0x2000));
    Particle_Field74_SetScaled_0AD8C(arg0, 2.0f);

    switch (arg1) {
        case 0:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
            break;

        case 1:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x18);
            break;
    }

    Particle_FieldA6_SetS16_0BCA8(arg0, sp22 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects23And35And84Descriptor4FRotatingFallColorCycle_AdvancePhase(Particle* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (Particle_TickPhaseTimer(arg0, arg0->unk_AE) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;

        case 2:
            Particle_ApproachRotationXTo(arg0, 0x4000, 0x800);
            if (Particle_TickPhaseTimer(arg0, 0x10) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;
    }

    if (arg0->unk_B8 > 0) {
        Particle_AddVelocityFromRotationTemplate1(arg0);
    }
}

void BattleAnim_CallbackStartEffects23And35And84Descriptor4FRotatingFallColorCycle(Particle* arg0) {
    s16 temp_v0 = Particle_FieldCF_GetS16_0C058(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects23And35And84Descriptor4FRotatingFallColorCycle_InitParticle(arg0, temp_v0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_BeginPhase(arg0);
                Particle_EnableRendering(arg0);
                Particle_FieldAE_SetS16_0BF4C(arg0, ParticleMath_RandomRange(3));
                Particle_FieldA6_SetS16_0BCA8(arg0, 8);
            }
            break;

        case 3:
            switch (temp_v0) {
                case 0:
                    Particle_PrimB_Approach_0BB44(arg0, 0, 0x20);
                    Particle_EnvG_Approach_0BBF0(arg0, 0, 0x20);
                    break;

                case 1:
                    Particle_PrimR_Approach_0BAE4(arg0, 0, 0x20);
                    Particle_EnvG_Approach_0BBF0(arg0, 0x78, 0x10);
                    break;
            }
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 4:
            switch (temp_v0) {
                case 0:
                    Particle_PrimG_Approach_0BB14(arg0, 0, 0x20);
                    Particle_EnvR_Approach_0BB90(arg0, 0, 0x20);
                    break;

                case 1:
                    Particle_PrimG_Approach_0BB14(arg0, 0x78, 0xC);
                    Particle_EnvG_Approach_0BBF0(arg0, 0, 0xA);
                    break;
            }

            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x18) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_AnimateFramesForward(arg0, 0, 7, 1, 2, -1);
        Particle_Field1C_Approach_0B98C(arg0, 0.02f, 0.015f);
        BattleAnim_CallbackStartEffects23And35And84Descriptor4FRotatingFallColorCycle_AdvancePhase(arg0);
        if (arg0->unk_2C.y <= 0.0f) {
            Particle_MarkInactive(arg0);
        }
    }
}

void BattleAnim_CallbackSharedGrowFadeSetup(Particle* arg0) {
    Particle_Field38_AddXZFromField94YOffset180_08F38(arg0, 33.0f);
    Particle_Field1C_SetScaled_0B938(arg0, 0.67f);
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptor04GrowFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedGrowFadeSetup(arg0);
            break;

        case 2:
            if (Particle_Field1C_Approach_0B98C(arg0, 6.67f, 0.67f) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0);
            break;

        case 4:
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 8) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffect68Descriptor1BExpandingFadeDrift(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedGrowFadeSetup(arg0);
            break;

        case 2:
            if (Particle_Field1C_Approach_0B98C(arg0, 8.0f, 1.0f) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 8);
            break;

        case 4:
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 8) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_Field94_AddZ_0A5B0(arg0, 0x1000);
}

void BattleAnim_CallbackUnusedGrowFadeVariant(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedGrowFadeSetup(arg0);
            break;

        case 2:
            if (Particle_Field1C_Approach_0B98C(arg0, 8.0f, 1.0f) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 8);
            break;

        case 4:
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 8) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_Field94_AddZ_0A5B0(arg0, 0x1000);

    if (gParticleFrameMod4 == 0) {
        ParticleGfx_RecolorPrimFromPaletteSetB(arg0, ParticleMath_RandomRange(6));
    }
}

void BattleAnim_CallbackStartEffect104DelayedSpiralFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    Particle_Field7C_SetYScaled_0AF24(arg0, 2.0f);
    Particle_Field9A_SetY_0A3D8(arg0, ParticleMath_RandomRange(0x10000));
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1A);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect104DelayedSpiralFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect104DelayedSpiralFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 0x10);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, -1);
            Particle_Field1C_Approach_0B98C(arg0, 1.0f, 0.1f);
            Particle_Field50_AddYScaled_099E0(arg0, 2.0f);
            Particle_UpdateRotatingVelocityXZ(arg0, 10.0f, 0x800);
            Particle_PrimG_Approach_0BB14(arg0, 0, 4);
            Particle_EnvR_Approach_0BB90(arg0, 0, 4);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x18) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffect29Descriptor02RotatingScaleGrow_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    Particle_Field38_SetYScaled_08CA0(arg0, 10.0f);
    Particle_Field7C_SetYScaled_0AF24(arg0, 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1A);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_DisableRendering(arg0);
    Particle_Field9A_SetY_0A3D8(arg0, (sp26 << 0x10) / 18);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 3);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect29Descriptor02RotatingScaleGrow(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect29Descriptor02RotatingScaleGrow_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_Field1C_Approach_0B98C(arg0, 1.0f, 0.1f);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_UpdateRotatingVelocityXZ(arg0, 50.0f, 0);
    }
}

void BattleAnim_SetupUnusedVariant2(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_Field38_SetYScaled_08CA0(arg0, 10.0f);
    Particle_Field7C_SetYScaled_0AF24(arg0, 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1A);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_DisableRendering(arg0);
    Particle_Field9A_SetY_0A3D8(arg0, (sp26 << 0x10) / 18);
    Particle_FieldA6_SetS16_0BCA8(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackUnusedVariant2(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 3:
            break;

        case 1:
            BattleAnim_SetupUnusedVariant2(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 4:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x10);
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_UpdateRotatingVelocityXZ(arg0, 50.0f, 0);
    }
}

void BattleAnim_CallbackStartEffect22Descriptor4ABurstChild_InitParticle(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.4f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1A);
    Particle_SetPrimAlpha(arg0, 0xA0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect22Descriptor4ABurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect22Descriptor4ABurstChild_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 2, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 0x18);
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_Field1C_Approach_0B98C(arg0, 0.6f, 0.05f);
}

void BattleAnim_CallbackStartEffect22Descriptor46BurstEmitter_InitParticle(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.4f);
    Particle_Field74_SetScaled_0AD8C(arg0, 8.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x29);
    Particle_SetTextureFrame(arg0, 2);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect22Descriptor46BurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect22Descriptor46BurstEmitter_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 3, 5, 1, 1, 0);
            break;

        case 3:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0xF);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        ParticleGfx_ApproachPrimEnvPalettePair(arg0, 0x2A, 0x1C);
        Particle_AddVelocityFromRotationTemplate1(arg0);
        BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackStartEffect22Descriptor4ABurstChild, &gBattleAnimParticleDescriptors[0x4A], 1);
    }
}

void BattleAnim_CallbackStartEffect22Descriptor34RotatingPaletteScaleFade_InitParticle(Particle* arg0) {
    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1D);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect22Descriptor34RotatingPaletteScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect22Descriptor34RotatingPaletteScaleFade_InitParticle(arg0);
            break;

        case 2:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 1);
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 3, 1, 2, 0);
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            ParticleGfx_ApproachPrimEnvPalettePair(arg0, 0, 0x20);
            Particle_Field1C_Approach_0B98C(arg0, 1.5f, 0.1f);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackStartEffect22Descriptor3DRotatingAlphaPaletteFade_InitParticle(Particle* arg0) {
    Vec3s sp28;
    UNUSED s32 pad[1];

    Particle_FieldCF_GetS16_0C058(arg0);
    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.45f);
    sp28.x = ParticleMath_RandomSigned(0x2000);
    sp28.y = ParticleMath_RandomSignedOffset(0x3000, 0);
    sp28.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1D);
    Particle_SetPrimAlpha(arg0, 0x64);
    Particle_Field74_SetScaled_0AD8C(arg0, 2.5f);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect22Descriptor3DRotatingAlphaPaletteFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect22Descriptor3DRotatingAlphaPaletteFade_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_Field74_Approach_0ADBC(arg0, 0.5, 0.5f);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 4);
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_Field1C_Approach_0B98C(arg0, 0.75f, 0.1f);
        Particle_AddVelocityFromRotationTemplate1(arg0);
        ParticleGfx_ApproachPrimEnvPalettePair(arg0, 0x1A, 0x10);
    }
}

void BattleAnim_SetParticleColorFromVariantIndex(Particle* arg0, u8 arg1) {
    u16 sp1E;

    Particle_FieldCF_SetU8Alt_0BEF8(arg0, arg1);

    switch (arg1) {
        case 0:
            sp1E = 0x1A;
            break;

        case 1:
            sp1E = 0x2A;
            break;

        case 2:
            sp1E = 0x24;
            break;

        case 3:
            sp1E = 0x2C;
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp1E);
}

void func_84334B04(void) {
}

void BattleAnim_ApproachParticleColorFromVariantIndex(Particle* arg0) {
    UNUSED u16 pad;
    u16 sp1C;
    u16 sp1A;

    switch (Particle_FieldCF_GetS16_0C058(arg0)) {
        case 0:
            sp1C = 0x2E;
            sp1A = 0x10;
            break;

        case 1:
            sp1C = 0x2D;
            sp1A = 0x10;
            break;

        case 2:
            sp1C = 0x2D;
            sp1A = 0x10;
            break;

        case 3:
            sp1C = 0x2B;
            sp1A = 0x10;
            break;
    }

    ParticleGfx_ApproachPrimEnvPalettePair(arg0, sp1C, sp1A);
}

void BattleAnim_CallbackEndEffect40Descriptor46DelayedScaleAlphaFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);
    s16 sp22 = Particle_FieldCE_GetS32_0C040(arg0);

    switch (sp26) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, -5.0f, 0.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 5.0f, 5.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 5.0f, -5.0f);
            break;
    }

    switch (sp22) {
        case 0:
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_SetScaleSpeed(arg0, 1.0f);
            Particle_SetScaleTarget(arg0, 0.1f);
            break;

        case 1:
            Particle_Field1C_SetScaled_0B938(arg0, 0.75f);
            Particle_SetScaleSpeed(arg0, 1.5f);
            Particle_SetScaleTarget(arg0, 0.15f);
            break;

        case 2:
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetScaleSpeed(arg0, 2.0f);
            Particle_SetScaleTarget(arg0, 0.2f);
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetTextureFrame(arg0, 1);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect40Descriptor46DelayedScaleAlphaFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect40Descriptor46DelayedScaleAlphaFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 2, 7, 1, 1, 0);
            if (arg0->unk_C7 >= 6) {
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 0x4E);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffects81And82Descriptor46AnimatedFade_InitParticle(Particle* arg0) {
    Vec3f sp2C;
    s16 sp2A;
    s16 sp28;

    sp2A = Particle_FieldAC_GetS16_0C038(arg0);
    sp28 = Particle_FieldCF_GetS16_0C058(arg0);
    sp2C.x = ParticleMath_RandomSigned(0xA);
    sp2C.y = ParticleMath_RandomSignedOffset(0xF, 0xA);
    sp2C.z = ParticleMath_RandomSigned(0xF);
    Particle_Field38_AddVecScaledFromVec3f_08D78(arg0, sp2C);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(5) * 0.25f) + 3.0f);
    Particle_Field1C_SetScaled_0B938(arg0, 0.75f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp28);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2A * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffects81And82Descriptor46AnimatedFade(Particle* arg0) {
    Particle_FieldCE_GetS32_0C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects81And82Descriptor46AnimatedFade_InitParticle(arg0);
            break;
        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 1, 7, 1, 1, 0);

            if (arg0->unk_C7 >= 6) {
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 0x4E);
            }

            if (arg0->unk_C7 >= 4) {}
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffect40Descriptor48SpreadScaleAlphaFade_InitParticle(Particle* arg0) {
    Vec3s sp30;
    Vec3f sp24;
    s16 sp22;
    s16 sp20;

    sp22 = Particle_FieldAC_GetS16_0C038(arg0);
    sp20 = Particle_FieldCF_GetS16_0C058(arg0);
    sp24.x = ParticleMath_RandomSigned(0xA);
    sp24.y = ParticleMath_RandomSignedOffset(0xA, 5);
    sp24.z = ParticleMath_RandomSigned(0xA);
    Particle_Field38_AddVecScaledFromVec3f_08D78(arg0, sp24);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.5f);
    sp30.x = ParticleMath_RandomSigned(0x2000);
    sp30.y = ParticleMath_RandomSigned(0x2000);
    sp30.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp30);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp20);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp22 * 2);
    Particle_SetTextureFrame(arg0, 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect40Descriptor48SpreadScaleAlphaFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect40Descriptor48SpreadScaleAlphaFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 2, 7, 1, 1, 0);
            Particle_Field1C_Approach_0B98C(arg0, 1.2f, 0.05f);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 0x10);
            Particle_AddVelocityFromRotationTemplate1(arg0);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffect40Descriptor3DSpreadRisingColorFade_InitParticle(Particle* arg0) {
    s16 sp36 = Particle_FieldAC_GetS16_0C038(arg0);
    Vec3s sp30;
    UNUSED s32 pad[3];

    Particle_SetRandomVelocityXYZ(arg0, 5, 5, 5);
    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);
    sp30.x = 0x2000 - ParticleMath_RandomRange(0x4000);
    sp30.y = 0x2000 - ParticleMath_RandomRange(0x4000);
    sp30.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp30);
    Particle_AddRotationTargetXY(arg0, sp30.x, sp30.y);
    Particle_Field9A_SetXY_0A3A0(arg0, 0, 0);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1A);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp36 * 3);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect40Descriptor3DSpreadRisingColorFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect40Descriptor3DSpreadRisingColorFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xA);
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_Field1C_Approach_0B98C(arg0, 1.0f, 0.1f);
            Particle_PrimR_Approach_0BAE4(arg0, 0, 0xC);
            Particle_PrimG_Approach_0BB14(arg0, 0, 0x20);
            Particle_AddVelocityFromRotationTemplate1(arg0);
            Particle_Field38_AddYScaled_08E90(arg0, 0.4f);
            BattleAnim_ApproachParticleColorFromVariantIndex(arg0);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 0x10) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffect56Descriptor46RisingScaleAlphaFade_InitParticle(Particle* arg0) {
    s16 sp36 = Particle_FieldAC_GetS16_0C038(arg0);
    Vec3s sp30;
    Vec3f sp24;

    sp24.x = ParticleMath_RandomSigned(0x19);
    sp24.y = ParticleMath_RandomSignedOffset(0xF, 5);
    sp24.z = ParticleMath_RandomSigned(0xA);
    Particle_Field38_AddVecScaledFromVec3f_08D78(arg0, sp24);
    Particle_Field1C_SetScaled_0B938(arg0, 0.15f);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.5f);
    sp30.x = 0x2000 - ParticleMath_RandomRange(0x4000);
    sp30.y = 0x2000 - ParticleMath_RandomRange(0x4000);
    sp30.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp30);
    Particle_AddRotationTargetXY(arg0, sp30.x, sp30.y);
    Particle_Field9A_SetXY_0A3A0(arg0, 0, 0);
    BattleAnim_SetParticleColorFromVariantIndex(arg0, (sp36 % 4) & 0xFF);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp36 * 1);
    Particle_SetTextureFrame(arg0, 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect56Descriptor46RisingScaleAlphaFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect56Descriptor46RisingScaleAlphaFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 2, 7, 1, 1, 0);
            Particle_Field1C_Approach_0B98C(arg0, 0.45000002f, 0.075f);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 0x10);
            Particle_AddVelocityFromRotationTemplate1(arg0);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffect56Descriptor47SpreadScaleAlphaRise_InitParticle(Particle* arg0) {
    s16 sp36 = Particle_FieldAC_GetS16_0C038(arg0);
    Vec3s sp30;
    UNUSED s32 pad[3];

    Particle_SetRandomVelocityXYZ(arg0, 5, 0xA, 0xA);
    Particle_Field1C_SetScaled_0B938(arg0, 0.90000004f);
    Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);
    sp30.x = ParticleMath_RandomSigned(0x2000);
    sp30.y = ParticleMath_RandomRange(0x10000);
    sp30.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp30);
    BattleAnim_SetParticleColorFromVariantIndex(arg0, (sp36 % 4) & 0xFF);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, 0);
    Particle_SetTextureFrame(arg0, 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect56Descriptor47SpreadScaleAlphaRise(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect56Descriptor47SpreadScaleAlphaRise_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 5);
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_Field1C_Approach_0B98C(arg0, 1.05f, 0.075f);
            Particle_Field74_Approach_0ADBC(arg0, 0.5, 0.5f);
            Particle_AddVelocityFromRotationTemplate1(arg0);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_Field50_AddYScaled_099E0(arg0, 0.5f);
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 0x10);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffects54And56Descriptor3DRisingColorScaleFade_InitParticle(Particle* arg0) {
    s16 sp36 = Particle_FieldAC_GetS16_0C038(arg0);
    Vec3s sp30;
    UNUSED s32 pad[3];

    Particle_SetRandomVelocityXYZ(arg0, 5, 5, 5);
    Particle_Field1C_SetScaled_0B938(arg0, 0.75f);
    Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);
    sp30.x = 0x2000 - ParticleMath_RandomRange(0x4000);
    sp30.y = ParticleMath_RandomRange(0x10000);
    sp30.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp30);
    Particle_AddRotationTargetXY(arg0, sp30.x, sp30.y);
    Particle_Field9A_SetXY_0A3A0(arg0, 0, 0);
    BattleAnim_SetParticleColorFromVariantIndex(arg0, (sp36 % 4) & 0xFF);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp36 * 3);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffects54And56Descriptor3DRisingColorScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects54And56Descriptor3DRisingColorScaleFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xA);
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_PrimR_Approach_0BAE4(arg0, 0, 0xC);
            Particle_PrimG_Approach_0BB14(arg0, 0, 0x20);
            Particle_Field1C_Approach_0B98C(arg0, 1.5f, 0.15f);
            BattleAnim_ApproachParticleColorFromVariantIndex(arg0);
            Particle_AddVelocityFromRotationTemplate1(arg0);
            Particle_Field38_AddYScaled_08E90(arg0, 0.4f);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 0x10) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffects40And54Descriptor46SpreadScaleFade_InitParticle(Particle* arg0) {
    s16 sp36;
    Vec3s sp30;
    Vec3f sp24;

    sp36 = Particle_FieldAC_GetS16_0C038(arg0);
    sp24.x = ParticleMath_RandomSigned(0x14);
    sp24.y = ParticleMath_RandomSignedOffset(0xF, 0xA);
    sp24.z = ParticleMath_RandomSigned(0xF);
    Particle_Field38_AddVecScaledFromVec3f_08D78(arg0, sp24);
    Particle_Field1C_SetScaled_0B938(arg0, 0.1f);
    sp30.x = ParticleMath_RandomRange(0x10000);
    sp30.y = ParticleMath_RandomRange(0x10000);
    sp30.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp30);
    Particle_AddRotationTargetXY(arg0, sp30.x, sp30.y);
    Particle_Field9A_SetXY_0A3A0(arg0, 0, 0);
    BattleAnim_SetParticleColorFromVariantIndex(arg0, (sp36 % 4) & 0xFF);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp36 * 2);
    Particle_SetTextureFrame(arg0, 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffects40And54Descriptor46SpreadScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects40And54Descriptor46SpreadScaleFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 2, 7, 1, 1, 0);
            Particle_Field1C_Approach_0B98C(arg0, 0.3f, 0.05f);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 0x10);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffect54Descriptor46DelayedColorAlphaFade_InitParticle(Particle* arg0) {
    s16 temp_s1 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.75f);

    switch (temp_s1) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, -3.0f, 0.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 3.0f, 3.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 3.0f, -3.0f);
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, temp_s1 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect54Descriptor46DelayedColorAlphaFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect54Descriptor46DelayedColorAlphaFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 1, 0);
            Particle_Field1C_Approach_0B98C(arg0, 1.0f, 0.02f);
            Particle_PrimB_Approach_0BB44(arg0, 0, 0x20);
            Particle_EnvG_Approach_0BBF0(arg0, 0, 0x20);
            if (arg0->unk_C7 >= 6) {
                Particle_PrimG_Approach_0BB14(arg0, 0, 0x20);
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 0x4E);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackSharedRotatingColorFadeSetup(Particle* arg0, s16 arg1, s16 arg2) {
    UNUSED s32 pad[2];
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field38_SetYScaled_08CA0(arg0, -10.0f);
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, 50.0f);
    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);

    switch (arg1) {
        case 0:
            Particle_Field94_AddX_0A578(arg0, ParticleMath_RandomSigned(0x800));
            Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomSignedOffset(0x1000, 0x8000));
            break;

        case 1:
            Particle_Field94_AddX_0A578(arg0, ParticleMath_RandomSigned(0xA00));
            Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomSignedOffsetBySign(0xD00, 0xF400) + 0x8000);
            break;
    }

    switch (arg2) {
        case 0:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1A);
            break;

        case 1:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 6);
            break;
    }

    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedRotatingColorFadeMotion(Particle* arg0, s32 arg1) {
    s16 temp_v0 = Particle_FieldCF_GetS16_0C058(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedRotatingColorFadeSetup(arg0, arg1, temp_v0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_FieldA6_SetS16_0BCA8(arg0, 0xC);
            Particle_AdvanceLifecycle(arg0);
            break;

        case 4:
            switch (temp_v0) {
                case 0:
                    Particle_PrimG_Approach_0BB14(arg0, 0, 0x10);
                    Particle_EnvR_Approach_0BB90(arg0, 0, 0x10);
                    break;

                case 1:
                    Particle_PrimG_Approach_0BB14(arg0, 0, 0xA);
                    Particle_EnvG_Approach_0BBF0(arg0, 0, 5);
                    break;
            }

            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x18) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_ApproachRotationXTo(arg0, -0xC00, 0x100);
        Particle_Field1C_Approach_0B98C(arg0, 1.2f, 0.04f);
        Particle_AddVelocityFromRotationTemplate1(arg0);
        Particle_AnimateFramesForward(arg0, 0, 7, 1, 2, -1);
    }
}

void BattleAnim_CallbackEndEffects15And22Descriptor4ERotatingColorFadeVariant0(Particle* arg0) {
    BattleAnim_CallbackSharedRotatingColorFadeMotion(arg0, 0);
}

void BattleAnim_CallbackEndEffects15And22Descriptor4ERotatingColorFadeVariant1(Particle* arg0) {
    BattleAnim_CallbackSharedRotatingColorFadeMotion(arg0, 1);
}

void BattleAnim_CallbackEndEffects15And22And59Descriptor3DRotatingAlphaScaleFade_InitParticle(Particle* arg0) {
    s16 sp36 = Particle_FieldCF_GetS16_0C058(arg0);
    UNUSED s32 pad[3];
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.4f);
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, 15.0f);
    Particle_Field94_AddX_0A578(arg0, ParticleMath_RandomSignedOffset(0x200, 0xE00));
    Particle_Field94_AddY_0A594(arg0, ParticleMath_RandomSignedOffset(0x3800, 0x8000));
    Particle_FieldA0_SetX_0A400(arg0, -0x4000);
    Particle_Field9A_SetX_0A3C4(arg0, 0x1000);
    Particle_Field74_SetScaled_0AD8C(arg0, 3.0f);

    switch (sp36) {
        case 0:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1A);
            break;

        case 1:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 6);
            break;
    }

    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffects15And22And59Descriptor3DRotatingAlphaScaleFade_AdvancePhase(Particle* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (Particle_TickPhaseTimer(arg0, 1) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;

        case 2:
            Particle_ApproachRotationTargetX(arg0);
            if (Particle_TickPhaseTimer(arg0, 0x10) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;
    }

    if (arg0->unk_B8 > 0) {
        Particle_AddVelocityFromRotationTemplate1(arg0);
    }
}

void BattleAnim_CallbackEndEffects15And22And59Descriptor3DRotatingAlphaScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects15And22And59Descriptor3DRotatingAlphaScaleFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_BeginPhase(arg0);
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 4);
            Particle_Field1C_Approach_0B98C(arg0, 1.2f, 0.1f);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        BattleAnim_CallbackEndEffects15And22And59Descriptor3DRotatingAlphaScaleFade_AdvancePhase(arg0);
    }
}

void BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade_InitParticle(Particle* arg0) {
    UNUSED s32 pad[3];
    s16 sp22 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp20 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.6f);
    Particle_Field38_AddYScaled_08E90(arg0, 15.0f);
    Particle_Field38_AddXZFromField94YOffset180_08F38(arg0, 20.0f);

    switch (sp20) {
        case 0:
            Particle_Field74_SetScaled_0AD8C(arg0, 1.5f);
            Particle_Field94_AddX_0A578(arg0, -0x4000);
            break;

        case 1:
            Particle_Field74_SetScaled_0AD8C(arg0, 2.0f);
            Particle_Field94_AddY_0A594(arg0, 0x4000);
            Particle_Field94_AddX_0A578(arg0, -0xE00);
            break;

        case 2:
            Particle_Field74_SetScaled_0AD8C(arg0, 2.0f);
            Particle_Field94_AddY_0A594(arg0, -0x4000);
            Particle_Field94_AddX_0A578(arg0, -0xE00);
            break;

        case 3:
            Particle_Field74_SetScaled_0AD8C(arg0, 2.5f);
            Particle_Field94_AddY_0A594(arg0, 0x4000);
            Particle_Field94_AddX_0A578(arg0, 0x2000);
            break;

        case 4:
            Particle_Field74_SetScaled_0AD8C(arg0, 2.5f);
            Particle_Field94_AddY_0A594(arg0, -0x4000);
            Particle_Field94_AddX_0A578(arg0, 0x2000);
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp22 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade_AdvancePhase(Particle* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (Particle_TickPhaseTimer(arg0, 2) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;

        case 2:
            if (Particle_TickPhaseTimer(arg0, 0x10) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;
    }

    if (arg0->unk_B8 > 0) {
        Particle_AddVelocityFromRotationTemplate5(arg0);
    }
}

void BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_BeginPhase(arg0);
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xB);
            }
            break;

        case 3:
            Particle_PrimB_Approach_0BB44(arg0, 0, 0x18);
            Particle_EnvG_Approach_0BBF0(arg0, 0, 0x18);
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xC);
            }
            break;

        case 4:
            Particle_PrimG_Approach_0BB14(arg0, 0, 0x10);
            Particle_EnvR_Approach_0BB90(arg0, 0, 0x10);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x40) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field1C_Approach_0B98C(arg0, 0.8f, 0.025f);
        Particle_AnimateFramesForward(arg0, 0, 7, 1, 2, -1);
        BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade_AdvancePhase(arg0);
    }
}

void BattleAnim_CallbackEndEffect59Descriptor4FColorScaleFade_InitParticle(Particle* arg0) {
    UNUSED s32 pad[3];
    s16 sp22 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_FieldCF_GetS16_0C058(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.7f);
    Particle_SetRandomVelocityX(arg0, 0xF);
    Particle_SetRandomVelocityYOffset(arg0, 0xF, 0xA);
    Particle_SetRandomVelocityZ(arg0, 0xF);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1A);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp22 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect59Descriptor4FColorScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect59Descriptor4FColorScaleFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_BeginPhase(arg0);
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 8);
            }
            break;

        case 3:
            Particle_PrimG_Approach_0BB14(arg0, 0, 0x10);
            Particle_EnvR_Approach_0BB90(arg0, 0, 0x10);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 0x18) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field1C_Approach_0B98C(arg0, 1.0f, 0.025f);
        Particle_AnimateFramesForward(arg0, 0, 7, 1, 2, 0);
    }
}

void ParticleEffect_InitSetRotatingPaletteNoTint(void) {
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(0, 0, 0x40, 0xA, 0xC8);
    BattleAnim_CreateEffectSlotForCurrentOwner(1, BattleAnim_CallbackStartEffect22Descriptor34RotatingPaletteScaleFade, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackStartEffect22Descriptor3DRotatingAlphaPaletteFade, &gBattleAnimParticleDescriptors[0x3D], 0, 3, 0x11, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackStartEffect22Descriptor46BurstEmitter, &gBattleAnimParticleDescriptors[0x46], 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
}

void ParticleEffect_InitSetTintRampRisingSpread(void) {
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(2, 0, 0x40, 0xA, 0xC8);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xC, 0xFF, 0, 0x30);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackEndEffect56Descriptor46RisingScaleAlphaFade, &gBattleAnimParticleDescriptors[0x46], 0, 6, 0x10, 9, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackEndEffect56Descriptor46RisingScaleAlphaFade, &gBattleAnimParticleDescriptors[0x46], 0, 6, 0x10, 9, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 2, BattleAnim_CallbackEndEffects54And56Descriptor3DRisingColorScaleFade, &gBattleAnimParticleDescriptors[0x3D], 0, 4, 0x10, 9, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 2, BattleAnim_CallbackEndEffect56Descriptor47SpreadScaleAlphaRise, &gBattleAnimParticleDescriptors[0x47], 0, 4, 0x10, 9, 0, 0);
}

void ParticleEffect_InitSetTintRampDelayedColorFade(void) {
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(2, 0, 0x40, 0xA, 0xC8);
    BattleAnim_SpawnOwnerModelTintRampDetach(2, 0xB, 0xC8, 0, 0x10);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect54Descriptor46DelayedColorAlphaFade, &gBattleAnimParticleDescriptors[0x46], 0, 3, 0x10, 9, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xA, BattleAnim_CallbackEndEffects40And54Descriptor46SpreadScaleFade, &gBattleAnimParticleDescriptors[0x46], 0, 8, 0x11, 9, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xC, 2, 2, BattleAnim_CallbackEndEffects54And56Descriptor3DRisingColorScaleFade, &gBattleAnimParticleDescriptors[0x3D], 0, 4, 0x11, 9, 0, 0);
}

void ParticleEffect_InitSmokeSetWithMarker(void) {
    BattleAnim_SpawnCategory17MarkerSlot(0x64, 1);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 6);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 0x3C, BattleAnim_CallbackStartEffects23And35And84Descriptor4FColorCycleScaleFade, &gBattleAnimParticleDescriptors[0x4F], 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x1E, BattleAnim_CallbackStartEffects23And35And84Descriptor3DAlphaScaleFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x1E, BattleAnim_CallbackStartEffects23And35And84Descriptor4FRotatingFallColorCycle, &gBattleAnimParticleDescriptors[0x4F], 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
}

void ParticleEffect_InitExplosionSet(void) {
    BattleAnim_SpawnOwnerModelTintPaletteFade(0xA, 0xB, 0x10, 8, 0xC8, 0x10);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 0x14, BattleAnim_CallbackEndEffects15And22Descriptor4ERotatingColorFadeVariant0, &gBattleAnimParticleDescriptors[0x4E], 0, 1, 0x11, 9, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 2, BattleAnim_CallbackEndEffects15And22Descriptor4ERotatingColorFadeVariant1, &gBattleAnimParticleDescriptors[0x4E], 0, 0xC, 0x11, 9, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xE, 8, 5, BattleAnim_CallbackEndEffects15And22And59Descriptor3DRotatingAlphaScaleFade, &gBattleAnimParticleDescriptors[0x3D], 0, 2, 0x11, 9, 0, 0);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x3C, 0x10, 0xC8, 0, 8);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x3A, 2, 2, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 9, 0, 0x33, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x3C, 2, 2, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 9, 0, 0x33, 0);
}

void ParticleEffect_InitSmokeSetTexture1(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 6);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 0x3C, BattleAnim_CallbackStartEffects23And35And84Descriptor4FColorCycleScaleFade, &gBattleAnimParticleDescriptors[0x4F], 0, 1, 0x11, gBattleAnimCurrentAnchor, 1, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x1E, BattleAnim_CallbackStartEffects23And35And84Descriptor3DAlphaScaleFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 0x11, gBattleAnimCurrentAnchor, 1, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x1E, BattleAnim_CallbackStartEffects23And35And84Descriptor4FRotatingFallColorCycle, &gBattleAnimParticleDescriptors[0x4F], 0, 1, 0x11, gBattleAnimCurrentAnchor, 1, 0);
}

void ParticleEffect_InitExplosionSetTintPalette35(void) {
    BattleAnim_SpawnOwnerModelTintPaletteFade(0xA, 0x35, 0x2E, 8, 0xC8, 0x10);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 0x14, BattleAnim_CallbackEndEffects15And22Descriptor4ERotatingColorFadeVariant0, &gBattleAnimParticleDescriptors[0x4E], 0, 1, 0x11, 9, 1, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 2, BattleAnim_CallbackEndEffects15And22Descriptor4ERotatingColorFadeVariant1, &gBattleAnimParticleDescriptors[0x4E], 0, 0xC, 0x11, 9, 1, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xE, 8, 5, BattleAnim_CallbackEndEffects15And22And59Descriptor3DRotatingAlphaScaleFade, &gBattleAnimParticleDescriptors[0x3D], 0, 2, 0x11, 9, 1, 0);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x3C, 0x2E, 0xC8, 0, 8);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x3A, 2, 2, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 9, 0, 0x18, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x3C, 2, 2, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 9, 0, 0x18, 0);
}

void ParticleEffect_InitSmokeSetLongDuration(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 6);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 0x50, BattleAnim_CallbackStartEffects23And35And84Descriptor4FColorCycleScaleFade, &gBattleAnimParticleDescriptors[0x4F], 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x28, BattleAnim_CallbackStartEffects23And35And84Descriptor3DAlphaScaleFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x28, BattleAnim_CallbackStartEffects23And35And84Descriptor4FRotatingFallColorCycle, &gBattleAnimParticleDescriptors[0x4F], 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
}

void ParticleEffect_InitFireSet(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect29Descriptor02RotatingScaleGrow, &gBattleAnimParticleDescriptors[2], 0, 0x12, 0xE, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackStartEffect104DelayedSpiralFade, &gBattleAnimParticleDescriptors[0x4F], 0, 0x20, 7, 0, 0, 0);
    BattleAnim_SpawnOwnerModelTintPaletteFade(8, 0xB, 0x10, 8, 0xC8, 0x10);
}

void func_8433765C(void) {
}

void ParticleEffect_InitNoop(void) {
}

void ParticleEffect_InitSparkleSet(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor04GrowFade, &gBattleAnimParticleDescriptors[4], 0, 1, 0x10, 9, 0x14, 0);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(0, 0, 0x40, 0xA, 0xC8);
    BattleAnim_SpawnOwnerModelTintPaletteApproachInactive(4, 0xA, 0x19, 0x20, 0xFF);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect40Descriptor46DelayedScaleAlphaFade, &gBattleAnimParticleDescriptors[0x46], 0, 3, 0x10, 9, 0x17, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(6, BattleAnim_CallbackEndEffect40Descriptor46DelayedScaleAlphaFade, &gBattleAnimParticleDescriptors[0x46], 0, 3, 0x10, 9, 0x2C, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackEndEffect40Descriptor46DelayedScaleAlphaFade, &gBattleAnimParticleDescriptors[0x46], 0, 3, 0x10, 9, 0x1A, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x12, BattleAnim_CallbackEndEffect40Descriptor46DelayedScaleAlphaFade, &gBattleAnimParticleDescriptors[0x46], 0, 2, 0x10, 9, 0x1A, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x14, BattleAnim_CallbackEndEffect40Descriptor48SpreadScaleAlphaFade, &gBattleAnimParticleDescriptors[0x48], 0, 3, 0x11, 9, 0x1A, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x14, 2, 2, BattleAnim_CallbackEndEffect40Descriptor3DSpreadRisingColorFade, &gBattleAnimParticleDescriptors[0x3D], 0, 6, 0x11, 9, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x18, BattleAnim_CallbackEndEffects40And54Descriptor46SpreadScaleFade, &gBattleAnimParticleDescriptors[0x46], 0, 8, 0x11, 9, 0, 0);
}

void func_843378CC(void) {
}

void ParticleEffect_InitCombinedSet(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0xFF, 0);
    BattleAnim_SpawnOwnerModelTintPaletteFade(0xA, 0xB, 0x10, 8, 0xC8, 0x10);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 8, 0x14, BattleAnim_CallbackEndEffects15And22And59Descriptor3DRotatingAlphaScaleFade, &gBattleAnimParticleDescriptors[0x3D], 0, 2, 0xE, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 8, 0x14, BattleAnim_CallbackEndEffect59Descriptor4FColorScaleFade, &gBattleAnimParticleDescriptors[0x4F], 0, 2, 9, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 6, 0x28, BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade, &gBattleAnimParticleDescriptors[0x4F], 0, 1, 9, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x3C, BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade, &gBattleAnimParticleDescriptors[0x4F], 0, 1, 9, 0, 1, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x3C, BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade, &gBattleAnimParticleDescriptors[0x4F], 0, 1, 9, 0, 2, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 3, 0x50, BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade, &gBattleAnimParticleDescriptors[0x4F], 0, 1, 9, 0, 3, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 3, 0x50, BattleAnim_CallbackEndEffect59Descriptor4FRotatingColorScaleFade, &gBattleAnimParticleDescriptors[0x4F], 0, 1, 9, 0, 4, 0);
}
