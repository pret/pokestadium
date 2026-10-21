#include "battle_engine.h"

void BattleAnim_UnusedResetAppearanceAndAdvance(Particle* arg0) {
    Particle_SetPrimColor(arg0, 0xFF, 0xFF, 0xFF);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackUnusedGenericFadeApproach(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 0:
            break;

        case 1:
            BattleAnim_UnusedResetAppearanceAndAdvance(arg0);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 3.0f, 0.025f);
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0x12C);
            break;

        case 3:
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 0x20) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_UpdateRotatingVelocityXZ(arg0, 32.0f, 0x400);
}

void BattleAnim_SetupOrphanDescriptor2BSpinFade(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    Particle_Field7C_SetYScaled_0AF24(arg0, 1.0f);
    Particle_Field94_SetX_0A2A4(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field94_SetZ_0A2CC(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field9A_SetY_0A3D8(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOrphanDescriptor2BSpinFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOrphanDescriptor2BSpinFade(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_BeginPhase(arg0);
            }
            break;

        case 3:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, 0x32) != 0) {
                Particle_AdvancePhase(arg0);
            }
            break;

        case 4:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, 0x14) != 0) {}
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    switch (arg0->unk_B8) {
        case 1:
            Particle_Field74_Approach_0ADBC(arg0, 50.0f, 0.5f);
            Particle_Field50_AddYScaled_099E0(arg0, 1.0f);
            Particle_UpdateRotatingVelocityXZ(arg0, arg0->unk_74, 0x1000);
            Particle_Field94_AddX_0A578(arg0, 0x2000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x3000);
            break;

        case 2:
            Particle_Field74_Approach_0ADBC(arg0, 0.0f, 1.0f);
            Particle_Field50_AddYScaled_099E0(arg0, -2.0f);
            Particle_UpdateRotatingVelocityXZ(arg0, arg0->unk_74, 0x1000);
            Particle_Field94_AddX_0A578(arg0, 0x2000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x3000);
            break;
    }
}

void BattleAnim_SetupOrphanDescriptor2EScatterFade(Particle* arg0) {
    s16 sp2E = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    Particle_Field74_SetScaled_0AD8C(arg0, 10.0f);
    Particle_Field94_AddVec_0A52C(arg0, ParticleMath_RandomSigned(0x1000), ParticleMath_RandomSigned(0x1000), 0);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 4);
    ParticleGfx_RecolorPrim(arg0, 0x24);
    ParticleGfx_RecolorEnv(arg0, 0x24);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOrphanDescriptor2EScatterFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOrphanDescriptor2EScatterFade(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0x46);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_AddVelocityFromRotationTemplate1(arg0);
        Particle_Field94_AddZ_0A5B0(arg0, 0x2000);
    }
}

void BattleAnim_SetupEndEffect26Descriptor2CGravityScatterFall(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.12f);
    Particle_Field7C_SetYScaled_0AF24(arg0, (ParticleMath_RandomRange(0x14) * 0.02f) + 0.25f);
    Particle_Field94_SetX_0A2A4(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field94_SetZ_0A2CC(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
    Particle_FieldAE_SetS16_0BF4C(arg0, ParticleMath_RandomRange(0x800) + 0xC00);
    Particle_Field9A_SetX_0A3C4(arg0, ParticleMath_RandomSignedOffsetBySign(0x800, 0x300));
    Particle_FieldB0_SetS16_0BFEC(arg0, ParticleMath_RandomSignedOffsetBySign(0x800, 0x300));
    Particle_Field9A_SetY_0A3D8(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field9A_SetZ_0A3EC(arg0, ParticleMath_RandomSignedOffsetBySign(0x800, 0x300));
    Particle_Field38_AddYScaled_08E90(arg0, ParticleMath_RandomRange(0x1E));
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect26Descriptor2CGravityScatterFall(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupEndEffect26Descriptor2CGravityScatterFall(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_BeginPhase(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(0xA) + 0x1E);
            }
            break;

        case 3:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 8);
                Particle_AdvancePhase(arg0);
            }
            break;

        case 4:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_Field9A_SetX_0A3C4(arg0, ParticleMath_RandomSignedOffsetBySign(0x1000, 0x600));
                Particle_FieldB0_SetS16_0BFEC(arg0, ParticleMath_RandomSignedOffsetBySign(0x400, 0x400));
                Particle_Field9A_SetZ_0A3EC(arg0, ParticleMath_RandomSignedOffsetBySign(0x1000, 0x600));
                arg0->unk_38.x += arg0->unk_50.x;
                arg0->unk_50.x = 0;
                arg0->unk_38.z += arg0->unk_50.z;
                arg0->unk_50.z = 0;
                Particle_AdvancePhase(arg0);
                arg0->unk_7C.y = -((ParticleMath_RandomRange(8) * 0.1f) + 0.5f);
            }
            break;

        case 5:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0x46);
            break;

        case 6:
            Particle_MarkInactive(arg0);
            break;
    }

    switch (arg0->unk_B8) {
        case 1:
            Particle_Field74_Approach_0ADBC(arg0, 20.0f, 0.5f);
            Particle_Field50_AddYScaled_099E0(arg0, arg0->unk_7C.y);
            Particle_UpdateRotatingVelocityXZ(arg0, arg0->unk_74, arg0->unk_AE);
            break;

        case 2:
            Particle_FieldAE_Approach_0BF60(arg0, 0, 0x200);
            Particle_Field50_AddYScaled_099E0(arg0, arg0->unk_7C.y);
            Particle_UpdateRotatingVelocityXZ(arg0, arg0->unk_74, arg0->unk_AE);
            break;

        case 3:
            Particle_Field50_AddYScaled_099E0(arg0, arg0->unk_7C.y);
            Particle_UpdateRotatingVelocityXZ(arg0, 5.0f, 0x400);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field94_AddXFromField9A_0A4B4(arg0);
        Particle_Field94_AddY_0A594(arg0, arg0->unk_B0);
        Particle_Field94_AddZFromField9A_0A4DC(arg0);
        if (arg0->unk_2C.y < 0.0f) {
            Particle_MarkInactive(arg0);
        }
    }
}

void BattleAnim_SetupEndEffects85And87GravityFallDelay(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCE_GetS32_0C040(arg0);

    Particle_Field7C_SetYScaled_0AF24(arg0, 0.5f);

    switch (sp24) {
        case 0:
            Particle_Field1C_SetScaled_0B938(arg0, 0.12f);
            arg0->unk_5C.y = -((ParticleMath_RandomRange(0xA) * 0.1f) + 0.5f);
            Particle_Field38_AddYScaled_08E90(arg0, ParticleMath_RandomRange(0x28) + 0x1E);
            Particle_SetRandomVelocityXSymmetric(arg0, 0x1E, 0);
            Particle_SetRandomVelocityZSymmetric(arg0, 0x1E, 0);
            break;

        case 1:
            Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
            arg0->unk_5C.y = -((ParticleMath_RandomRange(4) * 0.1f) + 0.2f);
            Particle_Field38_AddYScaled_08E90(arg0, ParticleMath_RandomSigned(0x14) + 0x1E);
            Particle_SetRandomVelocityXSymmetric(arg0, 0xF, 5);
            Particle_SetRandomVelocityZSymmetric(arg0, 0x14, 5);
            break;
    }

    Particle_Field94_SetX_0A2A4(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field94_SetZ_0A2CC(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field74_SetScaled_0AD8C(arg0, ParticleMath_RandomRange(0x14) + 15.0f);
    Particle_FieldAE_SetS16_0BF4C(arg0, ParticleMath_RandomRange(0x300) + 0x400);
    Particle_Field9A_SetY_0A3D8(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field9A_SetX_0A3C4(arg0, ParticleMath_RandomSignedOffsetBySign(0x800, 0x400));
    Particle_Field9A_SetZ_0A3EC(arg0, ParticleMath_RandomSignedOffsetBySign(0x800, 0x400));
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffects85And87GravityFallDelay(Particle* arg0) {
    s16 sp26 = Particle_FieldCE_GetS32_0C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupEndEffects85And87GravityFallDelay(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_BeginPhase(arg0);
                switch (sp26) {
                    case 0:
                        Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(0x1E) + 0x32);
                        break;

                    case 1:
                        Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(0x1E) + 0x64);
                        break;
                }
            }
            break;

        case 3:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    if (arg0->unk_B8 == 1) {
        Particle_Field50_AddYScaled_099E0(arg0, arg0->unk_5C.y);
        Particle_UpdateRotatingVelocityXZ(arg0, 5.0f, 0x400);
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field94_AddXFromField9A_0A4B4(arg0);
        Particle_Field94_AddYFromField9A_0A4C8(arg0);
        Particle_Field94_AddZFromField9A_0A4DC(arg0);
        if (arg0->unk_2C.y < 0.0f) {
            Particle_MarkInactive(arg0);
        }
    }
}

void func_84340AC4(void) {
}

void BattleAnim_OrphanDescriptor2BAnd2EEmitterSequence(void) {
    BattleAnim_SpawnCategory17MarkerSlot(0x80, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor2BSpinFade, &gBattleAnimParticleDescriptors[0x2B], 0, 0x10, 0xA, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackOrphanDescriptor2BSpinFade, &gBattleAnimParticleDescriptors[0x2B], 0, 0x10, 0xA, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackOrphanDescriptor2BSpinFade, &gBattleAnimParticleDescriptors[0x2B], 0, 0x10, 0xA, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackOrphanDescriptor2BSpinFade, &gBattleAnimParticleDescriptors[0x2B], 0, 8, 0xA, 0, 0, 0);
    BattleAnim_AddSpawnDelay(0x3A);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor2EScatterFade, &gBattleAnimParticleDescriptors[0x2E], 0, 0x10, 2, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor2EScatterFade, &gBattleAnimParticleDescriptors[0x2E], 0, 0x10, 2, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor2EScatterFade, &gBattleAnimParticleDescriptors[0x2E], 0, 0x10, 2, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor2EScatterFade, &gBattleAnimParticleDescriptors[0x2E], 0, 0x10, 2, 0, 0, 0);
}

void RegisterParticleEffect_ComplexMovement(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 0x14, BattleAnim_CallbackEndEffect26Descriptor2CGravityScatterFall, &gBattleAnimParticleDescriptors[0x2C], 0, 4, 0xE, 0, 0, 0);
    BattleAnim_EndEffect26DelayedDescriptor29ScatterSequence();
}

void RegisterParticleEffect_Burst(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 5, BattleAnim_CallbackEndEffects85And87GravityFallDelay, &gBattleAnimParticleDescriptors[0x2D], 0, 1, 0xE, 0, 0, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 5, BattleAnim_CallbackEndEffects85And87GravityFallDelay, &gBattleAnimParticleDescriptors[0x2D], 0, 1, 0xE, 0, 0, 1);
}
