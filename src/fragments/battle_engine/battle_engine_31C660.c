#include "battle_engine.h"
#include "src/model_renderer.h"

void BattleAnim_SetupGlobalTintColorFadeDetach(Particle* arg0) {
    BattleAnim_LoadGlobalTintToParticle(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackGlobalTintColorFadeDetach(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupGlobalTintColorFadeDetach(arg0);
            break;

        case 2:
            if (ParticleGfx_ApproachPrimPalette(arg0, arg0->unk_CF, Particle_FieldAA_GetS16_0C068(arg0)) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }

    BattleAnim_SetGlobalTintFromParticle(arg0);
}

void BattleAnim_SetupOwnerModelTintRampDetach(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_FieldAE_SetS16_0BF4C(arg0, arg0->unk_A6);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOwnerModelTintRampDetach(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOwnerModelTintRampDetach(arg0);
            break;

        case 2:
            if (Particle_FieldAE_Approach_0BF60(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void BattleAnim_SetupOwnerModelTintPulseDetach(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_FieldAE_SetS16_0BF4C(arg0, arg0->unk_CE);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOwnerModelTintPulseDetach(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOwnerModelTintPulseDetach(arg0);
            break;

        case 2:
            if (Particle_FieldAE_Approach_0BF60(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 4:
            if (Particle_FieldAE_Approach_0BF60(arg0, 0, arg0->unk_AA) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void func_8433209C(void) {
}

void BattleAnim_CallbackOwnerModelTintHoldFadeDetach(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOwnerModelTintPulseDetach(arg0);
            break;

        case 2:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            if (Particle_FieldAE_Approach_0BF60(arg0, 0, arg0->unk_AA) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void BattleAnim_SetupOwnerModelTintPaletteApproachInactive(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_FieldAE_SetS16_0BF4C(arg0, arg0->unk_A6);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOwnerModelTintPaletteApproachInactive(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOwnerModelTintPaletteApproachInactive(arg0);
            break;

        case 2:
            if (ParticleGfx_ApproachPrimPalette(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                Particle_FieldAE_SetS16_0BF4C(arg0, 0);
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void BattleAnim_SetupOwnerModelTintPaletteApproach(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_FieldAE_SetS16_0BF4C(arg0, arg0->unk_A6);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOwnerModelTintPaletteApproach(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOwnerModelTintPaletteApproach(arg0);
            break;

        case 2:
            if (ParticleGfx_ApproachPrimPalette(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void BattleAnim_SetupOwnerModelTintPaletteCycle(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_FieldAE_SetS16_0BF4C(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOwnerModelTintPaletteCycle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOwnerModelTintPaletteCycle(arg0);
            break;

        case 2:
            Particle_FieldAE_ApproachAndStepState_0BF98(arg0, arg0->unk_A6, arg0->unk_CE);
            break;

        case 3:
            if (ParticleGfx_ApproachPrimPalette(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_FieldAE_ApproachAndStepState_0BF98(arg0, 0, arg0->unk_CE);
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void BattleAnim_SetupOwnerModelTintPaletteApproachRampDown(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_FieldAE_SetS16_0BF4C(arg0, arg0->unk_A6);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOwnerModelTintPaletteApproachRampDown(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOwnerModelTintPaletteApproachRampDown(arg0);
            break;

        case 2:
            if (ParticleGfx_ApproachPrimPalette(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_FieldAE_ApproachAndStepState_0BF98(arg0, 0, arg0->unk_CE);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void BattleAnim_SetupOwnerModelTintPaletteFade(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_FieldAE_SetS16_0BF4C(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOwnerModelTintPaletteFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOwnerModelTintPaletteFade(arg0);
            break;

        case 2:
            if (Particle_FieldAE_Approach_0BF60(arg0, arg0->unk_A6, arg0->unk_CE) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            if (ParticleGfx_ApproachPrimPalette(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void BattleAnim_SetupOwnerModelTintRandomPaletteCycle(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, gParticlePaletteSetA[ParticleMath_RandomRange(6)]);
    Particle_FieldCF_SetU8_0BEEC(arg0, gParticlePaletteSetA[ParticleMath_RandomRange(6)]);
    Particle_SetPrimAlpha(arg0, arg0->unk_CD);

    if (arg0->unk_AA == 0) {
        arg0->unk_AA = 1;
    }

    Particle_FieldA6_SetS16_0BCA8(arg0, 0xFF / arg0->unk_AA);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOwnerModelTintRandomPaletteCycle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOwnerModelTintRandomPaletteCycle(arg0);
            break;

        case 2:
            ParticleGfx_ApproachPrimPalette(arg0, arg0->unk_CF, arg0->unk_AA);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xFF / arg0->unk_AA);
                Particle_FieldCF_SetU8_0BEEC(arg0, gParticlePaletteSetA[ParticleMath_RandomRange(6)]);
            }
            Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
            break;
    }
}

void BattleAnim_SetupOwnerModelTintPaletteRotateFadeDetach(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, gParticlePaletteSetA[0]);
    Particle_FieldAE_SetS16_0BF4C(arg0, 1);
    Particle_FieldCF_SetU8_0BEEC(arg0, gParticlePaletteSetA[1]);
    Particle_SetPrimAlpha(arg0, arg0->unk_CD);

    if (arg0->unk_AA == 0) {
        arg0->unk_AA = 1;
    }

    Particle_FieldA8_SetS16_0BE14(arg0, 0xFF / arg0->unk_AA);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOwnerModelTintPaletteRotateFadeDetach(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOwnerModelTintPaletteRotateFadeDetach(arg0);
            break;

        case 2:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            if (Particle_FieldA8_DecrementToZeroStep1_0BE6C(arg0) != 0) {
                Particle_FieldA8_SetS16_0BE14(arg0, 0xFF / arg0->unk_AA);
                arg0->unk_AE = (arg0->unk_AE + 1) % 6;
                Particle_FieldCF_SetU8_0BEEC(arg0, gParticlePaletteSetA[arg0->unk_AE]);
            }
            ParticleGfx_ApproachPrimPalette(arg0, arg0->unk_CF, arg0->unk_AA);
            Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
            break;

        case 3:
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 8) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_SetupOwnerModelAlphaFade(Particle* arg0) {
    arg0->prim_a = arg0->unk_A6;
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackOwnerModelAlphaFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupOwnerModelAlphaFade(arg0);
            break;

        case 2:
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        Model_SetMaterialAlpha(&arg0->unk_10->displayObject, arg0->prim_a);
    }
}

void BattleAnim_SetupParticleRecolorTransparent(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect125OwnerColorAlphaFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupParticleRecolorTransparent(arg0);
            break;

        case 2:
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x80, 4);
            break;

        case 3:
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 8) != 0) {
                Particle_DisableAndDetach(arg0);
            }
            break;
    }

    Model_SetMaterialColor(&arg0->unk_10->displayObject, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
}

void BattleAnim_SetupDescriptor25AlphaFadeInHoldOut(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackDescriptor25AlphaFadeInHoldOut(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupDescriptor25AlphaFadeInHoldOut(arg0);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, arg0->unk_CD, arg0->unk_AA);
            break;

        case 3:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 4:
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, arg0->unk_AA) != 0) {
                Particle_MarkInactive(arg0);
            }
            break;
    }
}

void BattleAnim_SetupDescriptor25AlphaHoldFadeOut(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, arg0->unk_CD);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackDescriptor25AlphaHoldFadeOut(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupDescriptor25AlphaHoldFadeOut(arg0);
            break;

        case 2:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, arg0->unk_AA) != 0) {
                Particle_MarkInactive(arg0);
            }
            break;
    }
}

void BattleAnim_SetupDescriptor25AlphaFadeInHold(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackDescriptor25AlphaFadeInHold(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupDescriptor25AlphaFadeInHold(arg0);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, arg0->unk_CD, arg0->unk_AA);
            break;

        case 3:
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_MarkInactive(arg0);
            }
            break;
    }
}

void BattleAnim_SetupDescriptor25AlphaHoldDetach(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, arg0->unk_CD);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackDescriptor25AlphaHoldDetach(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupDescriptor25AlphaHoldDetach(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_DisableAndDetach(arg0);
            }
            break;
    }
}

void BattleAnim_SetupDescriptor25PaletteFadeOut(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackDescriptor25PaletteFadeOut(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupDescriptor25PaletteFadeOut(arg0);
            break;

        case 2:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            ParticleGfx_ApproachPrimPalette(arg0, arg0->unk_CD, arg0->unk_AA);
            if (Particle_PrimAlpha_Approach_0BC2C(arg0, 0, arg0->unk_AA) != 0) {
                Particle_MarkInactive(arg0);
            }
            break;
    }
}

void BattleAnim_SetupDescriptor25PaletteFadeIn(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackDescriptor25PaletteFadeIn(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupDescriptor25PaletteFadeIn(arg0);
            break;

        case 2:
            ParticleGfx_ApproachPrimPalette(arg0, arg0->unk_CD, arg0->unk_AA);
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0xFF, arg0->unk_AA);
            break;

        case 3:
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_MarkInactive(arg0);
            }
            break;
    }
}
