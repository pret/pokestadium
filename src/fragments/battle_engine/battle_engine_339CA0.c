#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/geo_render.h"
#include "src/gfx_buffer.h"
#include "src/matrix.h"
#include "src/math_util.h"

void BattleAnim_CallbackSharedDescriptor29ScaleAnimFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    switch (Particle_FieldCE_GetS32_0C040(arg0)) {
        case 0:
            Particle_Field94_AddX_0A578(arg0, 0x4000);
            break;

        case 1:
            Particle_Field94_AddX_0A578(arg0, -0x3000);
            Particle_Field94_AddY_0A594(arg0, 0x4000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x2000);
            break;

        case 2:
            Particle_Field94_AddX_0A578(arg0, 0x2000);
            Particle_Field94_AddY_0A594(arg0, 0x2000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x2000);
            break;

        case 3:
            Particle_Field94_AddX_0A578(arg0, -0x8000);
            Particle_Field94_AddY_0A594(arg0, 0x2000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x6000);
            break;

        case 4:
            Particle_Field94_AddX_0A578(arg0, -0x4000);
            Particle_Field94_AddY_0A594(arg0, 0x4000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x4000);
            break;
    }

    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
    Particle_AddPositionFromRotationTemplate1(arg0, (sp26 - 1) * 10.0f);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptor29ScaleAnimFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedDescriptor29ScaleAnimFade_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 1, 0);
            break;

        case 3:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x40);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
    Particle_Field1C_Approach_0B98C(arg0, 3.5f, 0.25f);
}

void BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_FieldCF_GetS16_0C058(arg0);

    switch (sp26) {
        case 0:
            Particle_Field94_AddX_0A578(arg0, 0x5800);
            Particle_Field94_AddY_0A594(arg0, 0x5800);
            Particle_Field94_AddZ_0A5B0(arg0, -0x6000);
            break;

        case 1:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            Particle_Field94_AddY_0A594(arg0, 0);
            Particle_Field94_AddZ_0A5B0(arg0, 0x5800);
            break;

        case 2:
            Particle_Field94_AddX_0A578(arg0, 0x2000);
            Particle_Field94_AddY_0A594(arg0, 0x2000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x2000);
            break;

        case 3:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            break;

        case 4:
            Particle_Field94_AddX_0A578(arg0, 0);
            Particle_Field94_AddY_0A594(arg0, 0);
            Particle_Field94_AddZ_0A5B0(arg0, 0);
            break;

        case 5:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            Particle_Field94_AddY_0A594(arg0, 0x2800);
            Particle_Field94_AddZ_0A5B0(arg0, 0x5800);
            break;
    }

    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xC);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 3);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 1, 0);
            Particle_Field1C_Approach_0B98C(arg0, 3.5f, 0.25f);
            break;

        case 4:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x40);
            Particle_Field1C_Approach_0B98C(arg0, 3.5f, 0.25f);
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    switch (sp26) {
        case 0:
            Particle_Field94_AddX_0A578(arg0, 0x5800);
            Particle_Field94_AddY_0A594(arg0, 0x5800);
            Particle_Field94_AddZ_0A5B0(arg0, -0x6000);
            break;

        case 1:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            Particle_Field94_AddY_0A594(arg0, 0);
            Particle_Field94_AddZ_0A5B0(arg0, 0x5800);
            break;

        case 2:
            Particle_Field94_AddX_0A578(arg0, 0x2000);
            Particle_Field94_AddY_0A594(arg0, 0x2000);
            Particle_Field94_AddZ_0A5B0(arg0, 0x2000);
            break;

        case 3:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            break;

        case 4:
            Particle_Field94_AddX_0A578(arg0, 0);
            Particle_Field94_AddY_0A594(arg0, 0);
            Particle_Field94_AddZ_0A5B0(arg0, 0);
            break;

        case 5:
            Particle_Field94_AddX_0A578(arg0, 0x6000);
            Particle_Field94_AddY_0A594(arg0, 0x2800);
            Particle_Field94_AddZ_0A5B0(arg0, 0x5800);
            break;
    }

    switch (sp24) {
        case 0:
            Particle_SetRandomVelocityXSymmetric(arg0, 0xA, 3);
            Particle_SetRandomVelocityYOffset(arg0, 0xF, 0xA);
            Particle_SetRandomVelocityZSymmetric(arg0, 0xF, 3);
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xD);
            break;

        case 1:
            Particle_SetRandomVelocityXSymmetric(arg0, 0xA, 5);
            Particle_SetRandomVelocityYOffset(arg0, 0x14, 5);
            Particle_SetRandomVelocityZSymmetric(arg0, 0xA, 5);
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xE);
            break;
    }

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 2, 1, 0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackSharedOwnerKeyedGrowColorFade_InitParticle(Particle* arg0) {
    s16 sp26 = BattleAnim_GetOwnerSpecies(gBattleAnimSecondaryOwner);

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));

    if (sp26 == 0x42) {
        Particle_SetPosition(arg0, 320.0f, 0.0f, 0.0f);
        Particle_Field94_AddZ_0A5B0(arg0, -0x2800);
    } else {
        Particle_Field94_AddZ_0A5B0(arg0, 0x2500);
    }
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedOwnerKeyedGrowColorFade(Particle* arg0) {
    s16 sp26 = Particle_FieldCE_GetS32_0C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedOwnerKeyedGrowColorFade_InitParticle(arg0);
            break;

        case 2:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0x14);
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_Field1C_Approach_0B98C(arg0, 6.2f, 1.0f);

    if (sp26 == 0) {
        Particle_PrimG_Approach_0BB14(arg0, 0, 0x18);
        Particle_PrimB_Approach_0BB44(arg0, 0, 0x18);
        Particle_EnvG_Approach_0BBF0(arg0, 0, 0x18);
        Particle_EnvB_Approach_0BBC0(arg0, 0, 0x18);
    }
}

void BattleAnim_CallbackSharedOwnerKeyedGrowColorAlphaFade_InitParticle(Particle* arg0) {
    s16 sp26 = BattleAnim_GetOwnerSpecies(gBattleAnimSecondaryOwner);

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);

    if (sp26 == 0x42) {
        Particle_Field94_AddZ_0A5B0(arg0, 0x2500);
    } else {
        Particle_SetPosition(arg0, 320.0f, 0.0f, 0.0f);
        Particle_Field94_AddZ_0A5B0(arg0, -0x2800);
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedOwnerKeyedGrowColorAlphaFade(Particle* arg0) {
    s16 sp26 = Particle_FieldCE_GetS32_0C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedOwnerKeyedGrowColorAlphaFade_InitParticle(arg0);
            break;

        case 2:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0x14);
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    Particle_Field1C_Approach_0B98C(arg0, 6.0f, 1.0f);

    if (sp26 == 0) {
        Particle_PrimG_Approach_0BB14(arg0, 0, 0x18);
        Particle_PrimB_Approach_0BB44(arg0, 0, 0x18);
        Particle_EnvG_Approach_0BBF0(arg0, 0, 0x18);
        Particle_EnvB_Approach_0BBC0(arg0, 0, 0x18);
    }
    Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x10);
}

void BattleAnim_CallbackSharedOwnerKeyedAnimGrowFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldCE_GetS32_0C040(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);
    s16 sp22 = BattleAnim_GetOwnerSpecies(gBattleAnimSecondaryOwner);

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);

    if (sp22 == 0x42) {
        Particle_Field94_AddX_0A578(arg0, -0x2000);
        Particle_Field94_AddY_0A594(arg0, 0x4000);
    } else {
        Particle_Field94_AddX_0A578(arg0, 0x2000);
        Particle_Field94_AddY_0A594(arg0, 0x4000);
    }

    switch (sp26) {
        case 0:
            Particle_Field38_AddYScaled_08E90(arg0, -10.0f);
            break;

        case 2:
            Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedOwnerKeyedAnimGrowFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedOwnerKeyedAnimGrowFade_InitParticle(arg0);
            break;

        case 2:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 8);
            break;

        case 3:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x20);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_AnimateFramesForward(arg0, 0, 7, 1, 2, 0);
    Particle_Field1C_Approach_0B98C(arg0, 5.0f, 0.4f);
}

void BattleAnim_CallbackEndEffect88Descriptor2AOwnerKeyedAnimGrowFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldCE_GetS32_0C040(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);
    s16 sp22 = BattleAnim_GetOwnerSpecies(gBattleAnimSecondaryOwner);

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);

    if (sp22 == 0x42) {
        Particle_Field94_AddX_0A578(arg0, -0x2000);
        Particle_Field94_AddY_0A594(arg0, 0x4000);
    } else {
        Particle_Field94_AddX_0A578(arg0, 0x2000);
        Particle_Field94_AddY_0A594(arg0, 0x4000);
    }

    switch (sp26) {
        case 0:
            Particle_Field38_AddYScaled_08E90(arg0, -10.0f);
            break;

        case 2:
            Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetPrimAlpha(arg0, 0x80);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect88Descriptor2AOwnerKeyedAnimGrowFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect88Descriptor2AOwnerKeyedAnimGrowFade_InitParticle(arg0);
            break;

        case 2:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 8);
            break;

        case 3:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x10);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_AnimateFramesForward(arg0, 0, 7, 1, 2, 0);
    Particle_Field1C_Approach_0B98C(arg0, 5.0f, 0.4f);
}

void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor3DMetadataBurstChild_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetPrimAlpha(arg0, 0x64);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor3DMetadataBurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor3DMetadataBurstChild_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 6);
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackSharedTieredSmallRiseImpulseFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
    arg0->unk_5C.y = (MathUtil_Random_ZeroOne() * 0.5f) + 0.25f;
    Particle_Field94_AddY_0A594(arg0, 0x1800 - ((0x3000 / Particle_FieldAA_GetS16_0C068(arg0)) * sp26));
    Particle_Field74_SetScaled_0AD8C(arg0, (2.0f * MathUtil_Random_ZeroOne()) + 3.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetPrimAlpha(arg0, 0xB4);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedTieredSmallRiseImpulseFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedTieredSmallRiseImpulseFade_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_Field1C_Approach_0B98C(arg0, 0.75f, 0.025f);
            Particle_Field74_Approach_0ADBC(arg0, 0.5f, 0.25f);
            Particle_Field50_AddYScaled_099E0(arg0, arg0->unk_5C.y);
            Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
            break;

        case 3:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x20);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackSharedTieredLargeRiseImpulseFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    arg0->unk_5C.y = (MathUtil_Random_ZeroOne() * 0.5f) + 0.25f;
    Particle_Field94_AddY_0A594(arg0, 0x1800 - ((0x3000 / Particle_FieldAA_GetS16_0C068(arg0)) * sp26));
    Particle_Field74_SetScaled_0AD8C(arg0, (MathUtil_Random_ZeroOne() * 2.5f) + 3.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetPrimAlpha(arg0, 0xB4);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedTieredLargeRiseImpulseFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedTieredLargeRiseImpulseFade_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 3, 0);
            Particle_Field1C_Approach_0B98C(arg0, 1.0f, 0.05f);
            Particle_Field74_Approach_0ADBC(arg0, 0.5f, 0.25f);
            Particle_Field50_AddYScaled_099E0(arg0, arg0->unk_5C.y);
            break;

        case 3:
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x20) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
    Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
}

void BattleAnim_CallbackStartEffect31Descriptor49TieredRiseImpulseFade_InitParticle(Particle* arg0) {
    UNUSED s16 pad;
    s16 sp24 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
    arg0->unk_5C.y = (MathUtil_Random_ZeroOne() * 0.5f) + 0.4f;
    Particle_Field94_AddY_0A594(arg0, 0x800 - ((0x1000 / Particle_FieldAA_GetS16_0C068(arg0)) * sp24));
    Particle_Field74_SetScaled_0AD8C(arg0, (2.0f * MathUtil_Random_ZeroOne()) + 5.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x32);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect31Descriptor49TieredRiseImpulseFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect31Descriptor49TieredRiseImpulseFade_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 9);
            Particle_Field1C_Approach_0B98C(arg0, 0.4f, 0.025f);
            Particle_Field50_AddYScaled_099E0(arg0, arg0->unk_5C.y);
            Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_SetupUnusedRiseImpulseVariant(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.4f);
    Particle_SetRandomVelocityXYZ(arg0, 0, 0, 0xA);
    arg0->unk_5C.y = (MathUtil_Random_ZeroOne() * 0.5f) + 0.25f;
    Particle_Field94_AddY_0A594(arg0, 0x2000 - ((0x4000 / Particle_FieldAA_GetS16_0C068(arg0)) * sp26));
    Particle_Field74_SetScaled_0AD8C(arg0, MathUtil_Random_ZeroOne() + 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xA);
    Particle_SetPrimAlpha(arg0, 0x64);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackUnusedRiseImpulseVariant(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupUnusedRiseImpulseVariant(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_Field1C_Approach_0B98C(arg0, 0.75f, 0.025f);
            Particle_Field74_Approach_0ADBC(arg0, 0.5f, 0.2f);
            Particle_Field50_AddYScaled_099E0(arg0, arg0->unk_5C.y);
            Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
            break;

        case 3:
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x20) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffect55Descriptor49RiseGravityFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.3f);
    Particle_SetRandomVelocityXYZ(arg0, 0xA, 5, 0xA);
    Particle_Field38_AddYScaled_08E90(arg0, 15.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.1f) + 1.5f);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x32);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect55Descriptor49RiseGravityFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect55Descriptor49RiseGravityFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_Field1C_Approach_0B98C(arg0, 0.5f, 0.02f);
            Particle_AnimateFramesForward(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 6);
            if (Particle_Field50_AddNegField74Y_CheckField2CYNonPositive_09F84(arg0) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
    Particle_Field94_AddY_0A594(arg0, sp26 << 0xC);
    Particle_Field74_SetScaled_0AD8C(arg0, (2.0f * MathUtil_Random_ZeroOne()) + 6.0f);
    Particle_Field7C_SetYScaled_0AF24(arg0, (MathUtil_Random_ZeroOne() * 3.0f) + 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xA);
    Particle_SetPrimAlpha(arg0, 0x64);
    Particle_FieldA6_SetS16_0BCA8(arg0, 7);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_Field1C_Approach_0B98C(arg0, 0.8f, 0.1f);
            Particle_Field74_Approach_0ADBC(arg0, 1.0, 1.0f);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_Field7C_ApproachY_0B180(arg0, 0.5f, 0.4f);
                Particle_Field50_AddYFromField7C_09C6C(arg0);
            }
            break;

        case 3:
            Particle_Field50_AddYFromField7C_09C6C(arg0);
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x20);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
    }
}

void BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    switch (Particle_FieldCF_GetS16_0C058(arg0)) {
        case 0:
            Particle_Field1C_SetScaled_0B938(arg0, 0.75f);
            Particle_SetRandomVelocityXYZ(arg0, 0xF, 0xF, 0xF);
            Particle_Field38_AddYScaled_08E90(arg0, 15.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);
            break;

        case 1:
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_SetRandomVelocityXYZ(arg0, 3, 3, 3);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            break;
    }

    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x13);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 6);
            Particle_Field50_AddNegField74Y_CheckField2CYNonPositive_09F84(arg0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackOrphanDescriptor34ColorFadeDetach_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_SetRandomRotatedVelocityXY(arg0, 0xF, 0xF);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
    Particle_SetPrimColor(arg0, 0xFF, 0xFF, 0xFF);
    Particle_SetEnvColor(arg0, 0xFF, 0x64, 0);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOrphanDescriptor34ColorFadeDetach(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackOrphanDescriptor34ColorFadeDetach_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_PrimR_Approach_0BAE4(arg0, 0x64, 9);
            Particle_EnvR_Approach_0BB90(arg0, 0, 0x10);
            Particle_EnvG_Approach_0BBF0(arg0, 0x32, 3);
            Particle_EnvB_Approach_0BBC0(arg0, 0xFF, 0x10);
            if (Particle_TickDelayTimer(arg0, 8) != 0) {
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x20);
            }
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade_InitParticle(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.1f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x14);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade_InitParticle(arg0);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 0.75f, 0.08125f);
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x20);
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_SetupUnusedGlitterVariant(Particle* arg0) {
    Vec3s sp28;

    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.1f);
    sp28.x = MathUtil_Random16();
    sp28.y = MathUtil_Random16();
    sp28.z = 0;
    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp28);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x15);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(5) + 8);
    Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackUnusedGlitterVariant(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupUnusedGlitterVariant(arg0);
            break;

        case 2:
            Particle_Field74_Approach_0ADBC(arg0, 2.0f, 0.5f);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x40) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_AddVelocityFromRotationTemplate1(arg0);
    }
}

void BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild_InitParticle(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldAC_GetS16_0C038(arg0);

    sp28.x = ParticleMath_RandomSigned(0x2000);
    sp28.y = ParticleMath_RandomSignedOffset(0x2000, 0x8000);
    sp28.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);

    switch (sp26) {
        case 0:
            Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x15);
            break;

        case 1:
            Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x1B);
            break;
    }

    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(5) + 8);
    Particle_Field74_SetScaled_0AD8C(arg0, 6.0f);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild_InitParticle(arg0);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 0.1f, 0.01f);
            Particle_Field74_Approach_0ADBC(arg0, 3.0f, 0.75f);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x40) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_AddVelocityFromRotationTemplate1(arg0);
    }
}

void BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion_InitParticle(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);

    switch (sp26) {
        case 0:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 8);
            Particle_SetPrimAlpha(arg0, 0x64);
            Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
            sp28.x = ParticleMath_RandomSigned(0x2000);
            sp28.y = ParticleMath_RandomSignedOffset(0x2000, 0x8000);
            sp28.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
            break;

        case 1:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 8);
            Particle_SetPrimAlpha(arg0, 0x64);
            Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
            sp28.x = ParticleMath_RandomSigned(0x2000);
            sp28.y = ParticleMath_RandomSignedOffset(0x2000, 0x8000);
            sp28.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
            break;

        case 2:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 8);
            Particle_SetPrimAlpha(arg0, 0x64);
            Particle_Field38_SetYScaled_08CA0(arg0, -10.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 5.0f);
            sp28.x = ParticleMath_RandomSigned(0x2000);
            sp28.y = ParticleMath_RandomSignedOffset(0x2000, 0x8000);
            sp28.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
            break;

        case 3:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 9);
            Particle_SetPrimAlpha(arg0, 0x96);
            Particle_Field74_SetScaled_0AD8C(arg0, 3.0f);
            sp28.x = ParticleMath_RandomSigned(0x2000);
            sp28.y = ParticleMath_RandomSignedOffset(0x2000, 0x8000);
            sp28.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
            break;

        case 4:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 5);
            Particle_SetPrimAlpha(arg0, 0x96);
            Particle_Field74_SetScaled_0AD8C(arg0, 4.0f);
            sp28.x = ParticleMath_RandomSigned(0x3000);
            sp28.y = ParticleMath_RandomSignedOffset(0x3000, 0x8000);
            sp28.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
            break;
    }

    Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(5) + 8);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion(Particle* arg0) {
    s16 sp2E = Particle_FieldCF_GetS16_0C058(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion_InitParticle(arg0);
            break;
        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);

            switch (sp2E) {
                case 3:
                    Particle_PrimR_Approach_0BAE4(arg0, 0, 9);
                    Particle_Field74_Approach_0ADBC(arg0, 1.0f, 0.75f);
                    Particle_PrimAlpha_Approach_0BC2C(arg0, 0x32, 6);
                    break;

                case 4:
                    Particle_Field74_Approach_0ADBC(arg0, 1.0f, 0.75f);
                    Particle_Field38_AddYScaled_08E90(arg0, 0.5f);
                    Particle_PrimAlpha_Approach_0BC2C(arg0, 0x32, 6);
                    break;

                default:
                    Particle_PrimG_Approach_0BB14(arg0, 0x64, 6);
                    Particle_Field74_Approach_0ADBC(arg0, 2.0f, 0.5f);
                    break;
            }
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_AddVelocityFromRotationTemplate1(arg0);
    }
}

void BattleAnim_CallbackEndEffect52Descriptor42BurstChild_InitParticle(Particle* arg0) {
    s16 sp2E = Particle_FieldAC_GetS16_0C038(arg0);
    Vec3s sp28;

    Particle_Field1C_SetScaled_0B938(arg0, 0.1f);
    if (arg0->unk_68.y < 0.0f) {
        arg0->unk_68.y = 0.0f;
    }
    sp28.x = ParticleMath_RandomRange(0x10000);
    sp28.y = ParticleMath_RandomRange(0x10000);
    sp28.z = 0;
    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp28);
    Particle_Field9A_SetZ_0A3EC(arg0, ParticleMath_RandomSignedOffsetBySign(0x400, 0x400));
    Particle_Field74_SetScaled_0AD8C(arg0, 8.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 0);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect52Descriptor42BurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect52Descriptor42BurstChild_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_Field1C_ApproachAndStepState_0B9D0(arg0, 0.3f, 0.05f);
            Particle_Field74_Approach_0ADBC(arg0, 3.0f, 1.0f);
            break;

        case 4:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 2);
            break;

        case 5:
            Particle_Field1C_ApproachAndStepState_0B9D0(arg0, 0.05f, 0.05f);
            break;

        case 6:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field94_AddZFromField9A_0A4DC(arg0);
        Particle_Field7C_SetVecFromField74AnglesXY_0B2B4(arg0);
        Particle_Field50_AddVecFromField7C_09BDC(arg0);
    }
}

void BattleAnim_SetupEndEffect52DefaultBurstChild(Particle* arg0) {
    BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackEndEffect52Descriptor42BurstChild, &gBattleAnimParticleDescriptors[0x42], 0xC);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect52DefaultBurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupEndEffect52DefaultBurstChild(arg0);
            break;

        case 2:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_SetupSharedScalePulseFallSetup(Particle* arg0) {
    s16 sp2E = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp2C = Particle_FieldCE_GetS32_0C040(arg0);
    s16 sp2A = Particle_FieldCF_GetS16_0C058(arg0);
    Vec3s sp24;

    sp24.x = ParticleMath_RandomRange(0x10000);
    sp24.y = ParticleMath_RandomRange(0x10000);
    sp24.z = 0;

    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp24);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
    Particle_Field78_SetScaled_0ADA4(arg0, 0.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp2A);
    Particle_Field1C_SetScaled_0B938(arg0, 0.0f);
    Particle_SetScaleSpeed(arg0, 0.3f);
    Particle_SetScaleTarget(arg0, 0.05f);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 2);

    switch (sp2C) {
        case 0:
            Particle_AddPositionFromRotationTemplate1(arg0, ParticleMath_RandomRangeOffset(0x1E, 0xA));
            Particle_SetScaleSpeed(arg0, 0.2f);
            break;

        case 1:
            if (arg0->unk_68.y < 0) {
                arg0->unk_68.y = 0;
            }
            Particle_AddPositionFromRotationTemplate1(arg0, ParticleMath_RandomRangeOffset(0x28, 0xA));
            Particle_SetScaleSpeed(arg0, 0.3f);
            Particle_SetScaleTarget(arg0, 0.04f);
            break;

        case 2:
            Particle_SetScaleSpeed(arg0, 0.1f);
            Particle_SetScaleTarget(arg0, 0.03f);
            Particle_AddPositionFromRotationTemplate1(arg0, ParticleMath_RandomRangeOffset(0xC, 5));
            Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 1);
            break;

        case 3:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 0.1f);
            Particle_AddPositionFromRotationTemplate1(arg0, ParticleMath_RandomRangeOffset(0x14, 0x1E));
            Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 4);
            break;

        case 5:
            Particle_SetRandomVelocityXYZ(arg0, 0, 0xF, 0x19);
            Particle_Field38_AddYScaled_08E90(arg0, 15.0f);
            Particle_SetScaleSpeed(arg0, 0.15f);
            Particle_SetScaleTarget(arg0, 0.02f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.1f);
            break;

        case 6:
            Particle_AddPositionFromRotationTemplate1(arg0, ParticleMath_RandomRangeOffset(0x1E, 0x14));
            Particle_Field74_SetScaled_0AD8C(arg0, 0.3f);
            break;

        case 8:
            Particle_AddPositionFromRotationTemplate1(arg0, ParticleMath_RandomRangeOffset(8, 2));
            Particle_SetScaleSpeed(arg0, 0.1f);
            Particle_SetScaleTarget(arg0, 0.04f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_FieldA6_SetS16_0BCA8(arg0, 0);
            break;

        case 7:
            Particle_AddPositionFromRotationTemplate1(arg0, ParticleMath_RandomRangeOffset(0xA, 2));
            Particle_SetScaleSpeed(arg0, 0.2f);
            Particle_SetScaleTarget(arg0, 0.025f);
            Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);
            break;

        case 9:
            Particle_AddPositionFromRotationTemplate1(arg0, ParticleMath_RandomRangeOffset(0x1E, 0x14));
            Particle_SetScaleSpeed(arg0, 0.3f);
            Particle_SetScaleTarget(arg0, 0.025f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
            Particle_Field78_SetScaled_0ADA4(arg0, 0.02f);
            break;

        case 10:
            Particle_AddPositionFromRotationTemplate1(arg0, ParticleMath_RandomRangeOffset(0x19, 5));
            Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
            Particle_SetScaleSpeed(arg0, 0.2f);
            break;

        case 11:
            Particle_AddPositionFromRotationTemplate1(arg0, ParticleMath_RandomRangeOffset(5, 5));
            Particle_Field74_SetScaled_0AD8C(arg0, ParticleMath_RandomRange(5) + 5.0f);
            break;
    }
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptors42And44ScaleFall(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupSharedScalePulseFallSetup(arg0);
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

void BattleAnim_CallbackEndEffect23Descriptor44ScalePulse_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.0f);
    Particle_SetScaleSpeed(arg0, 0.3f);
    Particle_SetScaleTarget(arg0, 0.05f);
    Particle_SetRandomVelocityXYZ(arg0, 0xA, 0x14, 0x14);
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, 15.0f);
    Particle_Field38_AddYScaled_08E90(arg0, 7.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, ParticleMath_RandomRange(5) + 8.0f);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect23Descriptor44ScalePulse(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect23Descriptor44ScalePulse_InitParticle(arg0);
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
        Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
    }
}

void BattleAnim_CallbackEndEffect67Descriptor42ScalePulseFallFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupSharedScalePulseFallSetup(arg0);
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
        Particle_AddVelocityFromRotationTemplate1(arg0);
        if (arg0->unk_2C.y < 0.0f) {
            Particle_MarkInactive(arg0);
        }
    }
}

void BattleAnim_CallbackEndEffect43Descriptor40DelayedAnimFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.7f);
    Particle_Field38_SetYScaled_08CA0(arg0, 10.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x19);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect43Descriptor40DelayedAnimFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect43Descriptor40DelayedAnimFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 5, 1, 1, 2);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCE_GetS32_0C040(arg0);

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));

    switch (sp24) {
        case 1:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            break;

        case 5:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            break;

        case 6:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            break;

        case 16:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_Field1C_SetScaled_0B938(arg0, 2.0f);
            break;

        case 7:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            break;

        case 8:
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            Particle_Field38_AddYScaled_08E90(arg0, -10.0f);
            break;

        case 12:
            Particle_Field1C_SetScaled_0B938(arg0, 0.75f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_SetRandomVelocityXYZ(arg0, 8, 0xA, 8);
            break;

        case 13:
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
            Particle_SetRandomVelocityX(arg0, 0x1E);
            Particle_SetRandomVelocityYOffset(arg0, 0x14, 0xA);
            Particle_SetRandomVelocityZ(arg0, 0x1E);
            break;

        case 14:
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
            Particle_SetRandomVelocityX(arg0, 0x14);
            Particle_SetRandomVelocityYOffset(arg0, 0x14, 0xA);
            Particle_SetRandomVelocityZ(arg0, 0xF);
            break;

        case 15:
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.3f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0xA, 0xA);
            break;
    }

    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 3, 1, 1, 0);
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    switch (Particle_FieldCF_GetS16_0C058(arg0)) {
        case 0:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            Particle_Field38_AddYScaled_08E90(arg0, 15.0f);
            break;

        case 1:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 2:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            Particle_Field38_AddYScaled_08E90(arg0, -10.0f);
            break;

        case 3:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 1);
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 4:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 2);
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 5:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 3);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 6:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 9:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetRandomVelocityXYZ(arg0, 0xF, 0xF, 0xF);
            Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 10:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetRandomVelocityXYZ(arg0, 0x14, 0, 0x14);
            Particle_Field38_SetYScaled_08CA0(arg0, 0.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 11:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.2f);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0, 0xA);
            Particle_Field38_SetYScaled_08CA0(arg0, 30.0f - (sp26 * 5.0f));
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;
    }

    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 2);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 3, 1, 1, 0);
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC != 0) && (arg0->unk_B8 == 0)) {
                Particle_AdvancePhase(arg0);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    if (arg0->unk_B8 == 1) {
        BattleAnim_EmitParticleBurstWithMetadata(arg0, BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor3DMetadataBurstChild, &gBattleAnimParticleDescriptors[0x3D], 1, 8, 0);
        Particle_AdvancePhase(arg0);
    }
}

void BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    switch (Particle_FieldCF_GetS16_0C058(arg0)) {
        case 3:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 1);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            Particle_FieldCF_SetU8_0BEEC(arg0, 0);
            break;

        case 4:
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 2);
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.4f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            Particle_FieldCF_SetU8_0BEEC(arg0, 1);
            break;
    }

    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

s32 BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 2);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 3, 1, 1, 0);
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC != NULL) && (arg0->unk_B8 == 0)) {
                Particle_AdvancePhase(arg0);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    switch (arg0->unk_B8) {
        case 1:
            BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild, &gBattleAnimParticleDescriptors[0x38], 8);
            Particle_AdvancePhase(arg0);
            break;

        case 2:
            if (Particle_TickPhaseTimer(arg0, 1) != 0) {
                BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild, &gBattleAnimParticleDescriptors[0x38], 4);
                Particle_AdvancePhase(arg0);
            }
            break;

        case 3:
            if (Particle_TickPhaseTimer(arg0, 1) != 0) {
                BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackEndEffects37And38Descriptor38BurstChild, &gBattleAnimParticleDescriptors[0x38], 4);
                Particle_AdvancePhase(arg0);
            }
            break;
    }
}

void BattleAnim_CallbackStartEffect56Descriptor40AnimScaleFade_InitParticle(Particle* arg0) {
    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.05f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 7);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, 0x32);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect56Descriptor40AnimScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect56Descriptor40AnimScaleFade_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForward(arg0, 0, 5, 1, 1, -1);
            Particle_Field1C_Approach_0B98C(arg0, 0.3f, 0.01f);
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackStartEffect56Descriptor46AnimColorImpulseFade_InitParticle(Particle* arg0) {
    s16 sp2E;
    s16 sp2C;
    Vec3s sp24;

    sp2E = Particle_FieldAC_GetS16_0C038(arg0);
    sp2C = sp2E % 3;
    Particle_Field1C_SetScaled_0B938(arg0, 0.4f);
    Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);

    sp24.x = MathUtil_Random16();
    sp24.y = MathUtil_Random16();
    sp24.z = 0;
    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp24);

    switch (sp2C) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, -2.0f, 0.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 2.0f, 2.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 2.0f, -2.0f);
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect56Descriptor46AnimColorImpulseFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect56Descriptor46AnimColorImpulseFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 1, 0);
            Particle_Field74_Approach_0ADBC(arg0, 0.2f, 0.25f);
            Particle_Field1C_Approach_0B98C(arg0, 0.5f, 0.02f);
            Particle_PrimB_Approach_0BB44(arg0, 0, 0x20);
            Particle_EnvG_Approach_0BBF0(arg0, 0, 0x20);
            if (arg0->unk_C7 >= 6) {
                Particle_PrimG_Approach_0BB14(arg0, 0, 0x20);
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 0x4E);
            }
            Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackStartEffect73Descriptor15AnimatedColorImpulseFade_InitParticle(Particle* arg0) {
    s16 sp2E = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp2C = sp2E % 3;
    Vec3s sp24;

    Particle_Field1C_SetScaled_0B938(arg0, 0.4f);
    Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);

    sp24.x = MathUtil_Random16();
    sp24.y = MathUtil_Random16();
    sp24.z = 0;
    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp24);

    switch (sp2C) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, -2.0f, 0.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 2.0f, 2.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 2.0f, -2.0f);
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect73Descriptor15AnimatedColorImpulseFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect73Descriptor15AnimatedColorImpulseFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 1, 0);
            Particle_Field74_Approach_0ADBC(arg0, 0.2f, 0.25f);
            Particle_Field1C_Approach_0B98C(arg0, 0.5f, 0.02f);
            Particle_PrimB_Approach_0BB44(arg0, 0, 0x20);
            Particle_EnvG_Approach_0BBF0(arg0, 0, 0x20);
            if (arg0->unk_C7 >= 6) {
                Particle_PrimG_Approach_0BB14(arg0, 0, 0x20);
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 0x4E);
            }
            Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_RecolorParticleByQueuedMoveId(Particle* arg0) {
    s16 sp1E;

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x4D:
            sp1E = 0x43;
            break;
        case 0x4E:
            sp1E = 5;
            break;
        case 0x4F:
            sp1E = 0xC;
            break;
        case 0x93:
            sp1E = 5;
            break;
        case 0x1C:
            sp1E = 0x31;
            break;
        case 0x6C:
            sp1E = 0x1C;
            break;
        case 0x7B:
            sp1E = 0x1E;
            break;
        case 0x36:
            sp1E = 0x1D;
            break;
        case 0x72:
            sp1E = 0x1E;
            break;
        case 0x8B:
            sp1E = 0x1E;
            break;
    }
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp1E);
}

void BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion_InitParticle(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    sp28.x = MathUtil_Random16();
    sp28.y = MathUtil_Random16();
    sp28.z = 0;
    Particle_Field94_SetVecFromVec3s_0A24C(arg0, sp28);

    switch (sp24) {
        case 0:
            Particle_SetRandomVelocityXYZ(arg0, 0xF, 0xF, 0xF);
            Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 1.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;

        case 1:
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0xA, 0xA);
            Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
            break;
    }

    BattleAnim_RecolorParticleByQueuedMoveId(arg0);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion_InitParticle(arg0);
            break;

        case 2:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 6);
            Particle_Field1C_Approach_0B98C(arg0, 2.0f, 0.075f);
            Particle_AddVelocityFromRotationTemplate1(arg0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackStartEffect81Descriptor4BGrowColorShiftFade_InitParticle(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldA6_SetS16_0BCA8(arg0, 0x18);
    arg0->unk_74 = 0.02f;
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect81Descriptor4BGrowColorShiftFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect81Descriptor4BGrowColorShiftFade_InitParticle(arg0);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 2.0f, 0.02f);
            Particle_EnvG_Approach_0BBF0(arg0, 0xC8, 2);
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            ParticleMath_ApproachFloat(&arg0->unk_74, 0.008f, 0.001f);
            Particle_Field1C_Approach_0B98C(arg0, 2.0f, arg0->unk_74);
            Particle_EnvG_Approach_0BBF0(arg0, 0xC8, 2);
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0xC);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackStartEffect81Descriptor3DRisingAnimFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_SetRandomVelocityXYZ(arg0, 0xF, 0xF, 0xF);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x32) * 0.02f) + 0.5f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0x64);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect81Descriptor3DRisingAnimFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect81Descriptor3DRisingAnimFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(4) + 4);
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            Particle_AddVelocityYFromFieldOffset74(arg0);
            break;

        case 4:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x40, 4);
            Particle_AddVelocityYFromFieldOffset74(arg0);
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_InitSharedVerticalFadeParticle_ApplySpeciesOffset(Particle* arg0) {
    f32 sp24 = 0.0f;
    f32 sp20 = 0.0f;
    s32 sp1C = 0;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x9:
            sp20 = 5.0f;
            break;

        case 0x19:
            sp20 = 0.0f;
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            break;

        case 0x37:
            sp20 = 8.0f;
            break;

        case 0x49:
            sp1C = 1;
            break;

        case 0x50:
            sp1C = 1;
            break;

        case 0x74:
            sp20 = 5.0f;
            break;

        case 0x82:
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            sp24 = -5.0f;
            sp20 = 10.0f;
            sp1C = 1;
            break;

        case 0x83:
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            sp20 = 5.0f;
            sp1C = 1;
            break;

        case 0x86:
            sp20 = 10.0f;
            break;

        case 0x95:
            sp20 = 10.0f;
            break;
    }

    if (sp1C == 0) {
        Particle_SetRandomVelocityXYZ(arg0, 0xA, 0, 0x23);
    } else {
        Particle_SetRandomVelocityXYZ(arg0, 0xF, 0, 0x2D);
    }

    Particle_Field38_AddXZFromField94Y_08ED0(arg0, 10.0f + sp24);
    Particle_Field38_AddYScaled_08E90(arg0, 5.0f + sp20);
}

void BattleAnim_InitSharedVerticalFadeParticle(Particle* arg0) {
    Vec3s sp30;
    s16 sp2E = Particle_FieldAC_GetS16_0C038(arg0);
    u16 sp2C = Particle_FieldCE_GetS32_0C040(arg0);

    Particle_FieldB0_SetS16_0BFEC(arg0, 2);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 2);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));

    switch (sp2C) {
        case 0:
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0xA, 0xA);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x32) * 0.02f) + 0.5f);
            Particle_SetPrimAlpha(arg0, 0x64);
            Particle_FieldAE_SetS16_0BF4C(arg0, 4);
            break;

        case 1:
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0xF, 0x3C);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x32) * 0.04f) + 1.0f);
            Particle_SetPrimAlpha(arg0, 0x64);
            Particle_FieldAE_SetS16_0BF4C(arg0, 4);
            break;

        case 2:
            Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
            Particle_SetRandomVelocityXYZ(arg0, 0xF, 0x14, 0x19);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x32) * 0.07f) + 4.0f);
            Particle_SetPrimAlpha(arg0, 0xA0);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp2E);
            Particle_FieldAE_SetS16_0BF4C(arg0, 0xA);
            break;

        case 3:
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0, 0x19);
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, 10.0f);
            Particle_Field38_AddYScaled_08E90(arg0, 5.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.05f) + 0.2f);
            Particle_SetPrimAlpha(arg0, 0xFF);
            Particle_FieldAE_SetS16_0BF4C(arg0, 2);
            Particle_FieldB0_SetS16_0BFEC(arg0, 2);
            break;

        case 8:
            Particle_Field1C_SetScaled_0B938(arg0, 1.2f);
            BattleAnim_InitSharedVerticalFadeParticle_ApplySpeciesOffset(arg0);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.05f) + 0.2f);
            Particle_SetPrimAlpha(arg0, 0xFF);
            Particle_FieldAE_SetS16_0BF4C(arg0, 2);
            Particle_FieldB0_SetS16_0BFEC(arg0, 2);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp2E);
            break;

        case 12:
            Particle_Field1C_SetScaled_0B938(arg0, 1.2f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0, 0x28);
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, 10.0f);
            Particle_Field38_AddYScaled_08E90(arg0, 5.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.05f) + 0.2f);
            Particle_SetPrimAlpha(arg0, 0xFF);
            Particle_FieldAE_SetS16_0BF4C(arg0, 2);
            Particle_FieldB0_SetS16_0BFEC(arg0, 2);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp2E);
            break;

        case 4:
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0, 0x14);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.05f) + 0.5f);
            Particle_SetPrimAlpha(arg0, 0xFF);
            Particle_FieldAE_SetS16_0BF4C(arg0, 2);
            Particle_FieldB0_SetS16_0BFEC(arg0, 2);
            break;

        case 5:
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetRandomVelocityXYZ(arg0, 0xF, 0xF, 0xF);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x32) * 0.02f) + 1.0f);
            Particle_SetPrimAlpha(arg0, 0x80);
            Particle_FieldAE_SetS16_0BF4C(arg0, 4);
            break;

        case 6:
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_SetRandomVelocityXYZ(arg0, 5, 5, 5);
            Particle_Field74_SetScaled_0AD8C(arg0, 0.5f);
            Particle_SetPrimAlpha(arg0, 0xC8);
            Particle_FieldAE_SetS16_0BF4C(arg0, 4);
            break;

        case 7:
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0, 5);
            Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x14) * 0.02f) + 0.5f);
            Particle_SetPrimAlpha(arg0, 0xC8);
            Particle_FieldAE_SetS16_0BF4C(arg0, 4);
            break;

        case 9:
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0, 0xA);
            sp30.x = ParticleMath_RandomSigned(0x1800) - 0x4000;
            sp30.y = ParticleMath_RandomRange(0x10000);
            sp30.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp30);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x14) * 0.15f) + 3.0f);
            Particle_Field7C_SetVecFromField74AnglesXY_0B2B4(arg0);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp2E);
            Particle_FieldAE_SetS16_0BF4C(arg0, 0xA);
            break;

        case 10:
            Particle_Field1C_SetScaled_0B938(arg0, 0.8f);
            Particle_SetRandomVelocityXYZ(arg0, 0xF, 0, 0xF);
            sp30.x = ParticleMath_RandomSigned(0x1000) - 0x4000;
            sp30.y = ParticleMath_RandomRange(0x10000);
            sp30.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp30);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x14) * 0.15f) + 4.0f);
            Particle_Field7C_SetVecFromField74AnglesXY_0B2B4(arg0);
            Particle_FieldA6_SetS16_0BCA8(arg0, 0);
            Particle_FieldAE_SetS16_0BF4C(arg0, 0xA);
            break;

        case 11:
            Particle_Field1C_SetScaled_0B938(arg0, 0.05f);
            Particle_SetRandomVelocityXYZ(arg0, 0xA, 0, 0xA);
            sp30.x = ParticleMath_RandomSigned(0x1000) - 0x4000;
            sp30.y = ParticleMath_RandomRange(0x10000);
            sp30.z = 0;
            Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp30);
            Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x14) * 0.3f) + 6.0f);
            Particle_Field7C_SetVecFromField74AnglesXY_0B2B4(arg0);
            Particle_SetPrimAlpha(arg0, 0xFF);
            Particle_FieldA6_SetS16_0BCA8(arg0, sp2E);
            Particle_FieldAE_SetS16_0BF4C(arg0, 0xA);
            break;
    }

    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedAnimatedVerticalFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitSharedVerticalFadeParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, arg0->unk_B0, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x40, arg0->unk_AE);
            Particle_AddVelocityYFromFieldOffset74(arg0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_ApplySpeciesKeyedSpawnOffset(Particle* arg0) {
    f32 sp1C = 50.0f;
    f32 sp18 = 30.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 3:
            sp1C = 40.0f;
            break;

        case 0x5F:
            sp1C = 25.0f;
            break;

        case 0x67:
            sp1C = 35.0f;
            break;

        case 0x71:
            sp18 = 35.0f;
            break;

        case 0x73:
            sp1C = 40.0f;
            break;

        case 0x82:
            sp1C = 20.0f;
            break;

        case 0x83:
            sp1C = 30.0f;
            break;
    }

    Particle_Field38_AddXZFromField94Y_08ED0(arg0, sp1C);
    Particle_Field38_AddYScaled_08E90(arg0, sp18);
    Particle_Field78_SetScaled_0ADA4(arg0, 0.4f);
}

void BattleAnim_CallbackEndEffect16MultiDescriptorAnimatedFallFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitSharedVerticalFadeParticle(arg0);
            BattleAnim_ApplySpeciesKeyedSpawnOffset(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_BeginPhase(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 0x14);
            }
            break;

        case 3:
            Particle_AnimateFramesForward(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x40, 2);
            Particle_Field74_AdvanceAndAddNegY_CheckField2CYNonPositive_09FD8(arg0);
            Particle_AddVelocityXZFromRotationYPlusHalfTurnFromArgument(arg0, 10.0f);
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    switch (arg0->unk_B8) {
        case 1:
            Particle_Field78_Approach_0AE40(arg0, 1.0f, 0.1f);
            if (Particle_TickPhaseTimer(arg0, 4) != 0) {
                Particle_AdvancePhase(arg0);
                Particle_Field78_SetScaled_0ADA4(arg0, 0.2f);
            }
            break;

        case 2:
            Particle_Field78_Approach_0AE40(arg0, -0.5f, 0.2f);
            break;
    }
}

void BattleAnim_CallbackStartEffect69EndEffect78Descriptor4AFallFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitSharedVerticalFadeParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, arg0->unk_B0, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x40, arg0->unk_AE);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_Field7C_DecrementYUntilAtMost_0B0A4(arg0, -2.0f, 0.3f);
        Particle_Field50_AddVecFromField7C_09BDC(arg0);
    }
}

void BattleAnim_CallbackStartEffect69EndEffect78Descriptor30YThresholdFall(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitSharedVerticalFadeParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            if (arg0->unk_2C.y < 0.0f) {
                Particle_MarkInactive(arg0);
            }
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_Field7C_DecrementYUntilAtMost_0B0A4(arg0, -10.0f, 0.8f);
        Particle_Field50_AddVecFromField7C_09BDC(arg0);
    }
}

void BattleAnim_CallbackStartEffect101Descriptor3DMetadataBurstChild_InitParticle(Particle* arg0) {
    UNUSED s32 pad;

    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_FieldCD_GetU8_0C048(arg0);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    Particle_Field94_AddVec_0A52C(arg0, ParticleMath_RandomRange(0x10000), ParticleMath_RandomRange(0x10000), 0);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.75f);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect101Descriptor3DMetadataBurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect101Descriptor3DMetadataBurstChild_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x80, 8);
            Particle_AddVelocityFromRotationTemplate1(arg0);
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackDescriptor50BurstChild_InitParticle(Particle* arg0) {
    Vec3s sp28;
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldAC_GetS16_0C038(arg0);
    sp28.x = ParticleMath_RandomSignedOffset(0x1000, -0x2000);
    sp28.y = ParticleMath_RandomSignedOffset(0x1000, 0x8000);
    sp28.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp28);
    Particle_Field1C_SetScaled_0B938(arg0, 0.05f);
    Particle_SetScaleSpeed(arg0, 0.25f);
    Particle_SetScaleTarget(arg0, 0.02f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp26);
    Particle_FieldA6_SetS16_0BCA8(arg0, 8);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(8) * 0.25f) + 2.0f);
    Particle_Field7C_SetVecFromField74AnglesXY_0B2B4(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackDescriptor50BurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackDescriptor50BurstChild_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 1, 7, 1, 2, 0);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 0x10);
            }
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);
        Particle_Field7C_DecrementYUntilAtMost_0B0A4(arg0, -1.5f, 0.1f);
        Particle_Field50_AddVecFromField7C_09BDC(arg0);
    }
}

void BattleAnim_CallbackDescriptor50BurstEmitter_InitParticle(Particle* arg0) {
    switch (arg0->unk_A6) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, -5.0f, -10.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 8.0f, 8.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 3.0f, 0.0f);
            break;

        case 3:
            Particle_SetPosition(arg0, 0.0f, -3.0f, 5.0f);
            break;
    }

    Particle_FieldA6_SetS16_0BCA8(arg0, 6);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackDescriptor50BurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackDescriptor50BurstEmitter_InitParticle(arg0);
            break;

        case 2:
            BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackDescriptor50BurstChild, &gBattleAnimParticleDescriptors[0x50], 1);
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }
}

void func_843553B4(void) {
}

void BattleAnim_CallbackUnusedFallingTrailVariant(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitSharedVerticalFadeParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 1, 7, 1, 2, 0);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0x64, 0x10);
            }
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);
        Particle_Field7C_DecrementYUntilAtMost_0B0A4(arg0, -1.5f, 0.2f);
        Particle_Field50_AddVecFromField7C_09BDC(arg0);
    }
}

void BattleAnim_CallbackSharedDescriptor3CExpandingFadeIn_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    Particle_Field38_AddYScaled_08E90(arg0, 5.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp26);
    Particle_SetPrimAlpha(arg0, 0x40);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackSharedDescriptor3CExpandingFadeIn(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackSharedDescriptor3CExpandingFadeIn_InitParticle(arg0);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 8.0f, 0.1f);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0xFF, 4);
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackStartEffects29And60And104And110Descriptor44BurstChild_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_Field74_SetScaled_0AD8C(arg0, 100.0f);
    Particle_Field78_SetScaled_0ADA4(arg0, 3.0f);
    Particle_Field5C_SetYScaled_0A094(arg0, 2.0f);
    Particle_Field9A_SetY_0A3D8(arg0, 0x400);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_Field1C_SetScaled_0B938(arg0, 0.5f - (sp26 * 0.04f));
    Particle_SetPrimAlpha(arg0, (0xFF - (sp26 * 0x10)) & 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 + 1);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects29And60And104And110Descriptor44BurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects29And60And104And110Descriptor44BurstChild_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 0x18);
            }
            break;

        case 3:
            if ((Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) && (Particle_Field1C_Approach_0B98C(arg0, 0.0f, 0.05f) != 0)) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field74_ApproachUsingField78_0AE00(arg0, 0.0f);
        Particle_Field94_AddYFromField9A_0A4C8(arg0);
        Particle_SetVelocityXZFromRotationY(arg0);
        Particle_Field50_ApproachYToField5C_09B18(arg0, 0.0f);
        Particle_EnvB_Approach_0BBC0(arg0, 0xFF, 4);
        Particle_EnvG_Approach_0BBF0(arg0, 0xFF, 4);
    }
}

void BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter_InitParticle(Particle* arg0) {
    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field94_SetY_0A2B8(arg0, ParticleMath_RandomRange(0x10000));
    Particle_Field50_SetYScaled_09900(arg0, ParticleMath_RandomSignedOffsetBySign(0x28, 0x28));
    BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackStartEffects29And60And104And110Descriptor44BurstChild, &gBattleAnimParticleDescriptors[0x44], 5);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter_InitParticle(arg0);
            break;

        case 2:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackDescriptor26BurstChild_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_SetPrimColor(arg0, 0xDC, 0xFF, 0xFF);
    ParticleGfx_RecolorEnv(arg0, 0x35);
    arg0->unk_1C = (sp26 * 0.05f) + 0.5f;
    Particle_Field74_SetScaled_0AD8C(arg0, 2.0f);
    Particle_SetPrimAlpha(arg0, (0xFF - (sp26 << 5)) & 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 + 1);
    Particle_SetTextureFrame(arg0, 0xF);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackDescriptor26BurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackDescriptor26BurstChild_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                ParticleMath_ScaleDirectionToLength(&arg0->unk_7C, arg0->unk_50, D_84390348, arg0->unk_74);
            }
            break;

        case 3:
            Particle_Field7C_ScaleVec_0B14C(arg0, 1.5f);
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, 4) != 0) {
                Particle_Field74_SetScaled_0AD8C(arg0, 10.0f);
                Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_ScaleDirectionToLength(&arg0->unk_7C, arg0->unk_50, D_84390348, arg0->unk_74));
            }
            break;

        case 4:
            Particle_Field1C_Approach_0B98C(arg0, 0.1f, 0.02f);
            Particle_PrimR_Approach_0BAE4(arg0, 0xFF, 4);
            Particle_EnvR_Approach_0BB90(arg0, 0xFF, 8);
            Particle_EnvG_Approach_0BBF0(arg0, 0xFF, 8);
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field50_AddVecFromField7C_09BDC(arg0);
    }
}

void BattleAnim_CallbackDescriptor26BurstEmitter_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    Particle_SetVelocityRandomDirection(arg0, 100.0f);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 + 1);
    ParticleGfx_RecolorPrim(arg0, 0xA);
    ParticleGfx_RecolorEnv(arg0, 0x35);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackDescriptor26BurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackDescriptor26BurstEmitter_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            if (Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 0xF, 2, 1, 0) != 0) {
                BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackDescriptor26BurstChild, &gBattleAnimParticleDescriptors[0x26], 5);
            }
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_SetupUnusedGrowingSparkVariant(Particle* arg0) {
    f32 sp24;
    s16 sp22 = Particle_FieldAC_GetS16_0C038(arg0);

    sp24 = (sp22 + 15.0f) / 20.0f;
    if (sp24 >= 1.0f) {
        sp24 = 1.0f;
    }

    Particle_Field1C_SetScaled_0B938(arg0, sp24);
    Particle_SetScaleSpeed(arg0, 8.0f * sp24);
    Particle_SetScaleTarget(arg0, 0.35f * sp24);
    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
    Particle_SetTextureFrame(arg0, 0xF);
    ParticleGfx_RecolorPrim(arg0, 0xA);
    ParticleGfx_RecolorEnv(arg0, 0x35);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp22 * 8);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackUnusedGrowingSparkVariant(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupUnusedGrowingSparkVariant(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0xC);
            break;

        case 4:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0x20, 0x20);
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);
        Particle_EnvG_Approach_0BBF0(arg0, 0, 0x10);
        Particle_EnvB_Approach_0BBC0(arg0, 0, 8);
    }
}

void ParticleEffect_InitializeGroup(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 7, 0, 7);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 7, 1, 0);
}

void ParticleEffect_ConfigTexture7Palette1(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 7, 0, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 7, 1, 0);
}

void ParticleEffect_ConfigTexture9Palette2(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 8);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 9, 2, 0);
}

void ParticleEffect_ConfigVariantMotion6(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 9, 0, 0);
}

void ParticleEffect_ConfigVariantMotion16(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 0x10);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 9, 0, 0);
}

void ParticleEffect_SpecialSetupBurstPalette3(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 3, 0);
}

void ParticleEffect_SpecialSetupBurstPalette4(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects37And38Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 4, 0);
}

void ParticleEffect_SpecialSetupDelayedScatterPalette1(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 7, 0x11, 9, 1, 0xC);
}

void ParticleEffect_TextureSetup(void) {
    s32 temp_s1 = gBattleAnimCurrentAnchor & 0xFF;

    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 6, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 0x11, temp_s1, 0x18, 2);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(1, 8, 6, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 0x11, temp_s1, 0x18, 2);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(2, 8, 6, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 0x11, temp_s1, 0x18, 2);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 8, 6, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 0x11, temp_s1, 0x18, 2);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 6, 0xC, BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade, &gBattleAnimParticleDescriptors[0x4A], 0, 2, 0x11, temp_s1, 1, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(1, 6, 0xA, BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade, &gBattleAnimParticleDescriptors[0x4A], 0, 2, 0x11, temp_s1, 1, 0);
}

void ParticleEffect_ModeSetup(void) {
    UNUSED s32 pad;

    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 3, 5);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x10, 0x64, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackEndEffect67Descriptor3DAnimatedGravityFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x10, 0x64, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 9, 0, 0x18, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 4, 9, 0, 0x18, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 4, 9, 0, 0x18, 0);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0x35, 0xE0, 0, 0x20);
}

void ParticleEffect_CollisionSetup(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 3, 5);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackEndEffect43Descriptor40DelayedAnimFade, &gBattleAnimParticleDescriptors[0x40], 0, 1, 0x10, 0x64, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 5, BattleAnim_CallbackStartEffects18And73Descriptor11ScatterRiseFade, &gBattleAnimParticleDescriptors[0x11], 8, 4, 2, 0, 0, 0);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(0, 0, 0x40, 0xA, 0xC8);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0x19, 0xE1, 0, 0x40);
}

void BattleAnim_OrphanDescriptor34Emitter(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackOrphanDescriptor34ColorFadeDetach, &gBattleAnimParticleDescriptors[0x34], 0, 5, 0x11, gBattleAnimCurrentAnchor, 0, 0);
}

void ParticleEffect_AdditionalSetupDualRiseFade(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x28, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void ParticleEffect_AdditionalSetupBurstAndRiseFade(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade, &gBattleAnimParticleDescriptors[0x36], 0, 1, 0xA, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void ParticleEffect_CombinedSetupBurst3DRandom(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 5, 0x11, 0x64, 9, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade, &gBattleAnimParticleDescriptors[0x36], 0, 1, 0xA, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xC, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void ParticleEffect_CombinedSetupBurstHorizontalRandom(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 5, 0xA, 0, 0xA, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedDescriptor36ScaleAlphaFade, &gBattleAnimParticleDescriptors[0x36], 0, 1, 0xA, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xC, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void BattleAnim_EndEffects41And83Descriptor34BurstSequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects39And41And45And46And83Descriptor34BurstEmitter, &gBattleAnimParticleDescriptors[0x34], 0, 7, 0xA, 0, 0xB, 0);
}

void BattleAnim_StartEffect7GlobalTintFade(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 0x22);
}

void ParticleEffect_MultiHandleSetup(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 9, 0, 0x17, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x12, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 0xA, 9, 0, 0x17, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x20, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 5, 9, 0, 0x17, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect52DefaultBurstEmitter, &gDefaultParticleDescriptor, 0, 2, 9, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackEndEffect52DefaultBurstEmitter, &gDefaultParticleDescriptor, 0, 2, 9, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(5, BattleAnim_CallbackEndEffect52DefaultBurstEmitter, &gDefaultParticleDescriptor, 0, 2, 9, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackEndEffect52DefaultBurstEmitter, &gDefaultParticleDescriptor, 0, 2, 9, 0, 0, 0);
}

void BattleAnim_StartEffect137Descriptor3FRisingFade(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void ParticleEffect_TextureNodeSetup(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 3, 2, BattleAnim_CallbackSharedTieredSmallRiseImpulseFade, &gBattleAnimParticleDescriptors[0x4A], 0, 3, 0x11, gBattleAnimCurrentAnchor, 0x11, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 2, BattleAnim_CallbackSharedTieredLargeRiseImpulseFade, &gBattleAnimParticleDescriptors[0x4A], 0, 2, 0x11, gBattleAnimCurrentAnchor, 0x11, 0);
}

void ParticleEffect_HandleStateSetup(void) {
    UNUSED s32 pad;

    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xB, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xB, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xA, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xB, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x1E, BattleAnim_CallbackSharedOwnerKeyedGrowColorFade, &gBattleAnimParticleDescriptors[0x41], 0, 1, 0x18, 0, 0xF, 0);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0x23, 0, 0x10, 0x14);
}

void ParticleEffect_HandleCollisionSetup(void) {
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(0, 2, 0x10, 0x14, 0xFF);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedAnimGrowFade, &gBattleAnimParticleDescriptors[0x2A], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0x10, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedGrowColorAlphaFade, &gBattleAnimParticleDescriptors[0x41], 0, 1, 0x18, 0, 0xF, 0);
}

void BattleAnim_StartEffect13SecondaryOwnerSpeciesBranch(void) {
    s16 tmp = BattleAnim_GetOwnerSpecies(gBattleAnimSecondaryOwner);

    if (tmp == 0x7B) {
        ParticleEffect_HandleStateSetup();
        return;
    }

    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 3, 0x10, gBattleAnimCurrentAnchor, 0xB, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 3, 0x10, gBattleAnimCurrentAnchor, 0xB, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xA, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 3, 0x10, gBattleAnimCurrentAnchor, 0xB, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x1E, BattleAnim_CallbackSharedOwnerKeyedGrowColorFade, &gBattleAnimParticleDescriptors[0x28], 0, 1, 0x18, 0, 0xF, 0);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0x23, 0, 0x10, 0x14);
}

void ParticleEffect_DynamicCollisionSetup(void) {
    s16 tmp = BattleAnim_GetOwnerSpecies(gBattleAnimSecondaryOwner);

    if (tmp == 0x7B) {
        ParticleEffect_HandleCollisionSetup();
        return;
    }

    BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(0, 2, 0x10, 0x14, 0xFF);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedAnimGrowFade, &gBattleAnimParticleDescriptors[0x2A], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0x10, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedAnimGrowFade, &gBattleAnimParticleDescriptors[0x2A], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0x10, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedAnimGrowFade, &gBattleAnimParticleDescriptors[0x2A], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0x10, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedGrowColorAlphaFade, &gBattleAnimParticleDescriptors[0x28], 0, 1, 0x18, 0, 0xF, 0);
}

void ParticleEffect_ConditionalStateSetup(void) {
    UNUSED s16 pad;
    s16 sp3C = BattleAnim_GetOwnerSpecies(gBattleAnimSecondaryOwner);
    s16 sp3A = 3;

    if (sp3C == 0x7B) {
        sp3A = 1;
    }

    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, sp3A, 0x10, gBattleAnimCurrentAnchor, 0xB, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, sp3A, 0x10, gBattleAnimCurrentAnchor, 0xB, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xA, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, sp3A, 0x10, gBattleAnimCurrentAnchor, 0xB, 2);

    if (sp3C == 0x7B) {
        BattleAnim_CreateEffectSlotForCurrentOwner(0x1E, BattleAnim_CallbackSharedOwnerKeyedGrowColorFade, &gBattleAnimParticleDescriptors[0x41], 0, 1, 0x18, 0, 0xF, 0);
    } else {
        BattleAnim_CreateEffectSlotForCurrentOwner(0x1E, BattleAnim_CallbackSharedOwnerKeyedGrowColorFade, &gBattleAnimParticleDescriptors[0x28], 0, 1, 0x18, 0, 0xF, 0);
    }
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0x23, 0, 0x10, 0x14);
}

void ParticleEffect_CollisionResponseSwitch(void) {
    s16 tmp = BattleAnim_GetOwnerSpecies(gBattleAnimSecondaryOwner);

    if (tmp == 0x7B) {
        BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedOwnerKeyedGrowColorFade, &gBattleAnimParticleDescriptors[0x41], 0, 1, 0x18, 0, 0xF, 0);
    } else {
        BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedOwnerKeyedGrowColorFade, &gBattleAnimParticleDescriptors[0x28], 0, 1, 0x18, 0, 0xF, 0);
    }
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(5, 0, 8, 0x14, 0x80);
}

void ParticleEffect_CollisionAndBurstSetup(void) {
    s16 tmp = BattleAnim_GetOwnerSpecies(gBattleAnimSecondaryOwner);

    if (tmp == 0x7B) {
        BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(0, 2, 8, 0x14, 0x80);
        BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackEndEffect88Descriptor2AOwnerKeyedAnimGrowFade, &gBattleAnimParticleDescriptors[0x2A], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0x10, 2);
        BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedGrowColorAlphaFade, &gBattleAnimParticleDescriptors[0x41], 0, 1, 0x18, 0, 0xF, 0);
    } else {
        BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(0, 2, 8, 0x14, 0x80);
        BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackEndEffect88Descriptor2AOwnerKeyedAnimGrowFade, &gBattleAnimParticleDescriptors[0x2A], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0x10, 0);
        BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackEndEffect88Descriptor2AOwnerKeyedAnimGrowFade, &gBattleAnimParticleDescriptors[0x2A], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0x10, 1);
        BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackEndEffect88Descriptor2AOwnerKeyedAnimGrowFade, &gBattleAnimParticleDescriptors[0x2A], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0x10, 2);
        BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedGrowColorAlphaFade, &gBattleAnimParticleDescriptors[0x28], 0, 1, 0x18, 0, 0xF, 0);
    }
}

void ParticleEffect_StateCollisionSetupDesc29ScaleAnimFade(void) {
    UNUSED s32 pad;

    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xD, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xA, BattleAnim_CallbackSharedDescriptor29ScaleAnimFade, &gBattleAnimParticleDescriptors[0x29], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xD, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x1E, BattleAnim_CallbackSharedOwnerKeyedGrowColorFade, &gBattleAnimParticleDescriptors[0x41], 0, 1, 0x18, 0, 0xD, 1);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0x23, 0, 0x10, 0x29);
}

void ParticleEffect_StateCollisionSetupDesc2BGravityFall(void) {
    UNUSED s32 pad;

    BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(0, 2, 0x10, 0x29, 0xFF);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedAnimGrowFade, &gBattleAnimParticleDescriptors[0x2A], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xD, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackSharedOwnerKeyedGrowColorAlphaFade, &gBattleAnimParticleDescriptors[0x41], 0, 1, 0x18, 0, 0xD, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 5, BattleAnim_CallbackEndEffects85And87GravityFallDelay, &gBattleAnimParticleDescriptors[0x2B], 0, 2, 0xE, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 5, BattleAnim_CallbackEndEffects85And87GravityFallDelay, &gBattleAnimParticleDescriptors[0x2B], 0, 2, 0xE, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 0xF, BattleAnim_CallbackEndEffects85And87GravityFallDelay, &gBattleAnimParticleDescriptors[0x2B], 0, 1, 0xE, 0, 0, 0);
}

void ParticleEffect_AdditionalNodeSetup(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 0x24, BattleAnim_CallbackStartEffect56Descriptor46AnimColorImpulseFade, &gBattleAnimParticleDescriptors[0x46], 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect56Descriptor40AnimScaleFade, &gBattleAnimParticleDescriptors[0x40], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0, 0);
}

void ParticleEffect_SpecialCollisionSetup(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect3Descriptor29DirectionalScaleFade, &gBattleAnimParticleDescriptors[0x29], 0, 6, 0x10, 0x64, 0, 0);
}

void BattleAnim_StartEffect11GlobalTintFade(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 0x28);
}

void ParticleEffect_MultiTextureSetup(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 8, 0x10, 9, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 0xA, 0x10, 9, 0, 0);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0x46, 4, 0xA);
}

void ParticleEffect_SmallNodeSetupGlobalTintFade17(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 0x17);
}

void BattleAnim_EndEffect26DelayedDescriptor29ScatterSequence(void) {
    BattleAnim_AddSpawnDelay(0x10);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 8, 0x10, 9, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 8, 0x10, 9, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x20, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 8, 0x10, 9, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x30, BattleAnim_CallbackSharedDescriptor29DirectionalScatterFade, &gBattleAnimParticleDescriptors[0x29], 0, 8, 0x10, 9, 1, 0);
}

void ParticleEffect_ModeSpecificSetup(void) {
    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x4D:
            BattleAnim_SpawnOwnerModelTintPulseDetach(0, 0x64, 0x3E, 0, 0xA0, 4);
            break;

        case 0x4E:
            BattleAnim_SpawnOwnerModelTintPulseDetach(0, 0x64, 0x19, 0, 0xA0, 4);
            break;

        case 0x4F:
            BattleAnim_SpawnOwnerModelTintPulseDetach(0, 0x64, 0x2F, 0, 0xA0, 4);
            break;

        case 0x93:
            BattleAnim_SpawnOwnerModelTintPulseDetach(0, 0x64, 0x19, 0, 0xA0, 4);
            break;

        case 0x7B:
            BattleAnim_SpawnOwnerModelTintPulseDetach(0, 0x64, 0x3E, 0, 0xA0, 4);
            break;

        case 0x8B:
            BattleAnim_SpawnOwnerModelTintPulseDetach(0, 0x64, 0x3E, 0, 0xA0, 4);
            break;
    }
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion, &gBattleAnimParticleDescriptors[0x47], 0, 7, 0x10, 0x64, 1, 0);
}

void ParticleEffect_ComplexNodeSetup(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 3, BattleAnim_CallbackStartEffect31Descriptor49TieredRiseImpulseFade, &gBattleAnimParticleDescriptors[0x49], 0, 8, 0x11, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 3, 2, BattleAnim_CallbackSharedTieredSmallRiseImpulseFade, &gBattleAnimParticleDescriptors[0x47], 0, 6, 0x11, gBattleAnimCurrentAnchor, 0x31, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 2, BattleAnim_CallbackSharedTieredLargeRiseImpulseFade, &gBattleAnimParticleDescriptors[0x47], 0, 4, 0x11, gBattleAnimCurrentAnchor, 0x31, 0);
}

void ParticleEffect_SimpleNodeSetup(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect55Descriptor49RiseGravityFade, &gBattleAnimParticleDescriptors[0x49], 0, 5, 0x10, 0x64, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(3, BattleAnim_CallbackEndEffect55Descriptor49RiseGravityFade, &gBattleAnimParticleDescriptors[0x49], 0, 5, 0x10, 0x64, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion, &gBattleAnimParticleDescriptors[0x47], 0, 7, 0x10, 0x64, 1, 0);
}

void ParticleEffect_AdvancedModeSetup(void) {
    BattleAnim_SpawnOwnerModelAlphaFade(0, 0xFF, 0x30, 6);
    BattleAnim_SpawnOwnerModelAlphaFade(0x24, 0, 0, 0xFF);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0x23, 0, 0xFF, 8);
    BattleAnim_AddSpawnDelay(6);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackStartEffect81Descriptor4BGrowColorShiftFade, &gBattleAnimParticleDescriptors[0x4B], 0, 1, 0xA, 0, 0x2F, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 4, BattleAnim_CallbackStartEffect81Descriptor3DRisingAnimFade, &gBattleAnimParticleDescriptors[0x3D], 0, 3, 9, 0, 0x30, 0);
}

void BattleAnim_StartEffect16TintDescriptor34Sequence(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 6);
    BattleAnim_SpawnOwnerModelTintRampDetach(8, 0xA, 0, 0xFF, 0x40);
    BattleAnim_SpawnDescriptor25AlphaFadeInHoldFullAlpha(0xC, 5, 0x10, 0xA);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 4, 9, 0, 0x18, 0xD);
    BattleAnim_AddSpawnDelay(0x21);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0, 0, 0x10, 0xA);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 0xA);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xA, 0xFF, 0, 0x10);
}

void ParticleEffect_FullSetupTintFadeOutAndRestore(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 6);
    BattleAnim_SpawnOwnerModelTintRampDetach(8, 0xA, 0, 0xFF, 0x40);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0, 0, 0x10, 0xA);
    BattleAnim_AddSpawnDelay(0x21);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 0xA);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xA, 0xFF, 0, 0x10);
}

void ParticleEffect_FinalSetupSpiralAndVerticalFade(void) {
    UNUSED s32 pad;

    BattleAnim_SpawnOwnerModelTintPulseDetach(0, 1, 0xC, 0, 0xC8, 0x10);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(6, 4, 0xE, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 0x11, 7, 0x1A, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(7, 8, 7, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 0x11, 7, 0x1A, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect104DelayedSpiralFade, &gBattleAnimParticleDescriptors[0x4F], 0, 0x20, 7, 0, 0, 0);
    BattleAnim_EndEffect85TintAndDescriptorMode2Sequence();
}

void ParticleEffect_FinalSetupRiseAndVerticalFade(void) {
    BattleAnim_SpawnOwnerModelTintPulseDetach(0, 1, 0xC, 0, 0xC8, 4);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(6, 4, 0xE, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 0x11, 7, 0x33, 7);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(7, 8, 7, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 0x11, 7, 0x33, 7);
}

void ParticleEffect_FinalSetupPortraitBurst(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 6);
    ParticleEffect_PortraitBurst();
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(8, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void ParticleEffect_AdditionalNodeSingleRiseFade(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void BattleAnim_EndEffect58Descriptor4AAnd51Sequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(5, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(6, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(7, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
}

void BattleAnim_EndEffectUnusedVerticalFadeAndDelayedFrameSequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(5, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(6, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(7, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
}

void BattleAnim_StartEffects87And88Descriptor3DVerticalFadeSequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 2, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 2, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 2, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
}

void ParticleEffect_MultiNodeD(void) {
    BattleAnim_SpawnOwnerModelTintRampDetach(4, 0xA, 0, 0xFF, 0x40);
    BattleAnim_SpawnOwnerModelTintRampDetach(9, 0xA, 0xFF, 0, 0x40);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(1, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0xE, 0, 0x33, 2);
}

void BattleAnim_SpawnDefaultDescriptorBurstEmitterSequence(s32 arg0) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 4, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(8, 1, 4, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x10, 1, 8, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x18, 1, 8, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x20, 1, 8, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x30, 1, 8, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x3C, 1, 8, BattleAnim_CallbackStartEffects29And60And104And110DefaultDescriptorBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 2, 0, arg0, 0);
}

void ParticleEffect_GroupSetupTintAndDefaultBurst(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 6);
    BattleAnim_SpawnDefaultDescriptorBurstEmitterSequence(0xE);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0x64, 0x20, 0xA);
}

void BattleAnim_StartEffect105TintDefaultBurstAndDescriptor3CSequence(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 6);
    BattleAnim_SpawnDefaultDescriptorBurstEmitterSequence(0x17);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xA, BattleAnim_CallbackSharedDescriptor3CExpandingFadeIn, &gBattleAnimParticleDescriptors[0x3C], 0x1A, 1, 5, 0, 0x33, 0);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0x64, 0x20, 0xA);
}

void ParticleEffect_SimpleGroupSetup(void) {
    BattleAnim_SpawnOwnerModelTintPulseDetach(0xA, 1, 0xA, 0, 0xFF, 0x20);
}

void ParticleEffect_ComplexGroupSetup(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 6);
    BattleAnim_SpawnDefaultDescriptorBurstEmitterSequence(0xC);
    BattleAnim_SpawnOwnerModelTintPaletteRotateFadeDetach(4, 0x32, 0x20, 0xA0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 8, 5, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 9, 0, 0xC, 9);
}

void ParticleEffect_FinalGroupSetup(void) {
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xA, 0xFF, 0, 0x20);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 2, 2, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 9, 0, 0x17, 1);
}
