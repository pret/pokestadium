#include "battle_engine.h"

void BattleAnim_InitStartEffect135Descriptor1CRisingScale(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);
    s16 sp24 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field38_SetYScaled_08CA0(arg0, 2.5f);
    Particle_Field1C_SetScaled_0B938(arg0, 0.065789476f);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
    sp28.x = ParticleMath_RandomSigned(0x5000);
    sp28.y = sp24 * (0x10000 / arg0->unk_AA);
    sp28.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
    ParticleGfx_RecolorPrim(arg0, sp26);
    Particle_SetPrimAlpha(arg0, 0x80);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect135Descriptor1CRisingScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitStartEffect135Descriptor1CRisingScale(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, Particle_FieldAC_GetS16_0C038(arg0)) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_Field1C_Approach_0B98C(arg0, 1.3157895f, 0.16447368f);
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 4:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x10);
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_Field94_AddY_0A594(arg0, 0x400);
    Particle_AddVelocityFromRotationTemplate1(arg0);
}

void BattleAnim_InitStartEffect135ExpandingFlash(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.65789473f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp26);
    Particle_SetTextureFrame(arg0, 2);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect135ExpandingFlashFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitStartEffect135ExpandingFlash(arg0);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 6.5789475f, 0.32894737f);
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0xF);
            break;

        case 3:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 4:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x20);
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_InitStartEffect139Descriptor42FallingScale(Particle* arg0) {
    s16 sp2E = Particle_FieldCF_GetS16_0C058(arg0);
    s16 sp2C = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.05f);
    Particle_SetRotation(arg0, ParticleMath_RandomRange(0x10000), ParticleMath_RandomRange(0x10000), 0);
    Particle_Field74_SetScaled_0AD8C(arg0, 1.2f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp2E);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2C * 1);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect139Descriptor42FallingScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitStartEffect139Descriptor42FallingScale(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            if (Particle_Field1C_Approach_0B98C(arg0, 0.15f, 0.025f) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            if (Particle_Field1C_Approach_0B98C(arg0, 0.0f, 0.04f) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_Field74_Approach_0ADBC(arg0, 0.2, 0.2f);
    Particle_AddVelocityFromRotationTemplate1(arg0);
    Particle_Field38_AddYScaled_08E90(arg0, -1.0f);
}

void BattleAnim_InitStartEffect139Descriptor22SpinFade(Particle* arg0) {
    UNUSED s16 pad;
    s16 sp2C;

    Particle_FieldAC_GetS16_0C038(arg0);
    sp2C = Particle_FieldCF_GetS16_0C058(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.175f);
    Particle_SetRotation(arg0, ParticleMath_RandomRange(0x10000), ParticleMath_RandomRange(0x10000), 0);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp2C);
    Particle_SetPrimAlpha(arg0, 0x80);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect139Descriptor22SpinFadeSpark(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitStartEffect139Descriptor22SpinFade(arg0);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 0.1f, 0.01f);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 8);
            Particle_AddVelocityFromRotationTemplate1(arg0);
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_InitStartEffect141Descriptor1CGridRise(Particle* arg0) {
    s16 sp2E;
    s16 sp2C;
    s16 temp_v0;
    Vec3s sp24;

    temp_v0 = Particle_FieldAC_GetS16_0C038(arg0);
    sp2E = temp_v0 / 8;
    sp2C = temp_v0 % 8;

    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    sp24.x = 0x6000 - (sp2E * 0xC00);
    sp24.y = (sp2C << 0xC) + 0xB000;
    sp24.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp24);
    Particle_SetPrimColor(arg0, 0xC8, 0xFF, 0xFF);
    Particle_SetPrimAlpha(arg0, 0x60);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2E);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect141Descriptor1CGridRiseFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitStartEffect141Descriptor1CGridRise(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xA);
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_Field94_AddY_0A594(arg0, 0x200);
            Particle_Field1C_Approach_0B98C(arg0, 2.0f, 0.01f);
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 4:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x10);
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_InitStartEffects133And134And143Descriptor44ModeOrbit(Particle* arg0) {
    s16 sp36;
    s16 sp34;
    s16 sp32 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp30 = Particle_FieldCF_GetS16_0C058(arg0);
    s16 sp2E = Particle_FieldCE_GetS32_0C040(arg0);

    Particle_SetRotation(arg0, ParticleMath_RandomRange(0x10000), ParticleMath_RandomRange(0x10000), 0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.01f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp30);

    switch (sp2E) {
        case 0:
            Particle_FieldAE_SetS16_0BF4C(arg0, ParticleMath_RandomRangeOffset(0x14, 0x14));
            Particle_FieldB0_SetS16_0BFEC(arg0, 0);
            sp36 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            sp34 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            Particle_FieldA8_SetS16_0BE14(arg0, 8);
            break;

        case 1:
            Particle_FieldAE_SetS16_0BF4C(arg0, ParticleMath_RandomRangeOffset(0x28, 0x14));
            Particle_FieldB0_SetS16_0BFEC(arg0, 1);
            sp36 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            sp34 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            Particle_FieldA8_SetS16_0BE14(arg0, 0x10);
            break;

        case 2:
            Particle_FieldAE_SetS16_0BF4C(arg0, ParticleMath_RandomRangeOffset(0x1E, 0x14));
            Particle_FieldB0_SetS16_0BFEC(arg0, 2);
            sp36 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            sp34 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            Particle_FieldA8_SetS16_0BE14(arg0, 0xA);
            break;

        case 3:
            Particle_FieldAE_SetS16_0BF4C(arg0, 0x1E - sp32);
            Particle_FieldB0_SetS16_0BFEC(arg0, 2);
            sp36 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            sp34 = ParticleMath_RandomSignedOffsetBySign(0x200, 0x200);
            Particle_FieldA8_SetS16_0BE14(arg0, 0xA);
            break;
    }

    Particle_Field9A_SetX_0A3C4(arg0, sp36);
    Particle_Field9A_SetY_0A3D8(arg0, sp34);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp32 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl(Particle* arg0) {
    Particle_FieldCE_GetS32_0C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitStartEffects133And134And143Descriptor44ModeOrbit(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_AdvancePhase(arg0);
            }
            break;

        case 3:
            if (Particle_Field1C_ApproachAndStepState_0B9D0(arg0, 0.3f, 0.05f) != 0) {}
            break;

        case 4:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A8) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;

        case 5:
            Particle_Field1C_ApproachAndStepState_0B9D0(arg0, 0.0f, 0.05f);
            break;

        case 6:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        switch (arg0->unk_B8) {
            case 1:
                Particle_Field94_AddXFromField9A_0A4B4(arg0);
                Particle_SetPositionFromRotationTemplate1(arg0, arg0->unk_AE);
                break;

            case 2:
                Particle_Field94_AddXFromField9A_0A4B4(arg0);
                Particle_FieldAE_Approach_0BF60(arg0, 0, arg0->unk_B0);
                Particle_SetPositionFromRotationTemplate1(arg0, arg0->unk_AE);
                break;
        }
    }

    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
}

void BattleAnim_InitStartEffects133And134And143Descriptor38MetadataBurst(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    Particle_Field38_AddYScaled_08E90(arg0, 5.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp26);
    Particle_SetPrimAlpha(arg0, 0x40);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects133And134And143Descriptor38MetadataBurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitStartEffects133And134And143Descriptor38MetadataBurst(arg0);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 4.0f, 0.1f);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0xC8, 8);
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            Particle_Field1C_Approach_0B98C(arg0, 0.25f, 0.5f);
            BattleAnim_EmitParticleBurstWithMetadata(arg0, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 6, 0x18, 7);
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, 6) != 0) {
                Particle_FieldCC_SetU8_0BF04(arg0, 9);
            }
            break;

        case 4:
            Particle_Field50_AddYScaled_099E0(arg0, 15.0f);
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0xA);
            BattleAnim_EmitParticleBurstWithMetadata(arg0, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 6, 0x18, 7);
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

s16 BattleAnim_GetSessionModeEffectParam(void) {
    s16 var_v1 = 0x3B;

    switch (gSessionContext.mode) {
        case 0:
            var_v1 = 0xD;
            break;

        case 1:
            var_v1 = 0x3C;
            break;

        case 2:
            var_v1 = 0x3C;
            break;

        case 3:
            var_v1 = 3;
            break;

        case 4:
            var_v1 = 3;
            break;

        case 5:
            var_v1 = 3;
            break;
    }
    return var_v1;
}

void BattleAnim_StartEffect139DualRepeatingSparks(void) {
    s16 sp3E = BattleAnim_GetSessionModeEffectParam();

    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 0x1E, BattleAnim_CallbackStartEffect139Descriptor22SpinFadeSpark, &gBattleAnimParticleDescriptors[0x22], 0x10, 1, 0x1E, 0, sp3E, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 0x1E, BattleAnim_CallbackStartEffect139Descriptor42FallingScaleFade, &gBattleAnimParticleDescriptors[0x42], 0x10, 2, 0x1E, 0, sp3E, 0);
}

void BattleAnim_StartEffect140StartEffect139Alias(void) {
    BattleAnim_StartEffect139DualRepeatingSparks();
}

void BattleAnim_StartEffect141GridRiseAndFallingBurst(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xB, 1, 5, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 5, 0x1E, 0, BattleAnim_GetSessionModeEffectParam(), 8);
    BattleAnim_SpawnDescriptor25AlphaFadeInHold(0xA, 2, 0x16, 7, 0xFF);
    BattleAnim_SetSpawnDelay(0x10);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect141Descriptor1CGridRiseFade, &gBattleAnimParticleDescriptors[0x1C], 0, 0x40, 0x1E, 0, 0xA, 0);
}

void BattleAnim_StartEffect142StartEffect141Alias(void) {
    BattleAnim_StartEffect141GridRiseAndFallingBurst();
}

void BattleAnim_StartEffect135ExpandingFlashAndRisingScaleFade(void) {
    UNUSED s32 pad;

    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0, 0, 0x10, 7);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xA, 0xFF, 0xFF, 0xFF);
    BattleAnim_SpawnOwnerModelAlphaFade(0, 0xFF, 0xFF, 0xFF);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x14, 0xA, 0xFF, 0, 8);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect135ExpandingFlashFade, &gBattleAnimParticleDescriptors[0x21], 4, 1, 2, 0, 0x50, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect135ExpandingFlashFade, &gBattleAnimParticleDescriptors[0x23], 4, 1, 2, 0, 0x50, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect135ExpandingFlashFade, &gBattleAnimParticleDescriptors[0x17], 4, 1, 2, 0, 0x50, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 4, BattleAnim_CallbackStartEffect135Descriptor1CRisingScaleFade, &gBattleAnimParticleDescriptors[0x1C], 5, 0x10, 7, 0, 0x39, 0);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0x32, 0x10, 0xA);
}

void BattleAnim_StartEffect134ModeOrbitAndMetadataBurst(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 6);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 5, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 4, 9, 0, 0x3C, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 5, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 4, 9, 0, 0x3C, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x18, 1, 4, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 8, 9, 0, 0x3C, 2);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x1E, 1, 8, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 8, 9, 0, 0x3C, 3);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x1E, 1, 8, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 8, 9, 0, 0x3C, 3);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x26, 0xA, 0, 0xFF, 4);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x2D, BattleAnim_CallbackStartEffects133And134And143Descriptor38MetadataBurstEmitter, &gBattleAnimParticleDescriptors[0x38], 0x1A, 1, 2, 0, 0x3C, 0);
    BattleAnim_SpawnOwnerModelAlphaFade(0x48, 0x40, 0, 0xFF);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0x55, 6, 0xA);
}

void BattleAnim_StartEffect143ModeOrbitAndMetadataBurst(void) {
    UNUSED s32 pad;

    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 6);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 4, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 8, 9, 0, 0x3C, 2);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(6, 1, 8, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 8, 9, 0, 0x3C, 3);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(6, 1, 8, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 8, 9, 0, 0x3C, 3);
    BattleAnim_SpawnOwnerModelTintRampDetach(0xE, 0xA, 0, 0xFF, 4);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x14, BattleAnim_CallbackStartEffects133And134And143Descriptor38MetadataBurstEmitter, &gBattleAnimParticleDescriptors[0x38], 0x1A, 1, 2, 0, 0x3C, 0);
    BattleAnim_SpawnOwnerModelAlphaFade(0x2D, 0x40, 0, 0xFF);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0x32, 6, 0xA);
}

void BattleAnim_StartEffect133ModeOrbitBurstAndEffect135Followup(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 6);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 5, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 4, 9, 0, 0x3C, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 5, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 4, 9, 0, 0x3C, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x18, 1, 4, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 8, 9, 0, 0x3C, 2);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x1E, 1, 8, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 8, 9, 0, 0x3C, 3);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x1E, 1, 8, BattleAnim_CallbackStartEffects133And134And143Descriptor44ModeOrbitSwirl, &gBattleAnimParticleDescriptors[0x44], 0, 8, 9, 0, 0x3C, 3);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x26, 0xA, 0, 0xFF, 8);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x28, BattleAnim_CallbackStartEffects133And134And143Descriptor38MetadataBurstEmitter, &gBattleAnimParticleDescriptors[0x38], 0x18, 1, 2, 0, 0x3C, 0);
    BattleAnim_SpawnDescriptor25AlphaFadeInHoldOut(0x3C, 0, 0x40, 0xA, 0xFF);
    BattleAnim_SpawnOwnerModelAlphaFade(0x40, 0xFF, 0, 0xFF);
    BattleAnim_SetSpawnDelay(0x50);
    BattleAnim_StartEffect135ExpandingFlashAndRisingScaleFade();
}

void BattleAnim_StartEffect122GlobalAndOwnerTintFade(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0xFF, 0);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x14, 0, 0, 0xFF, 0x10);
}
