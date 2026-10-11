#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/geo_render.h"
#include "src/gfx_buffer.h"
#include "src/matrix.h"
#include "src/math_util.h"

static f32 D_84387B00[] = {
    0.0f, 1.0f,  1.0f,  1.3f, 0.8f, 0.9f, 1.3f,  0.8f,  1.0f,  0.9f,  0.6f, 1.2f,  1.2f, 0.6f,  0.9f, 1.5f, 0.8f,
    1.5f, 1.5f,  0.8f,  1.0f, 0.8f, 1.0f, 0.65f, 1.1f,  0.75f, 0.8f,  0.8f, 0.8f,  0.8f, 1.0f,  1.0f, 0.8f, 1.2f,
    1.0f, 0.8f,  1.25f, 1.0f, 1.5f, 0.8f, 1.0f,  1.0f,  0.8f,  0.8f,  1.2f, 1.35f, 0.9f, 1.2f,  1.2f, 1.1f, 0.7f,
    1.1f, 0.9f,  1.5f,  1.0f, 0.9f, 1.0f, 1.3f,  1.0f,  1.38f, 1.15f, 1.4f, 1.3f,  1.2f, 1.0f,  1.0f, 0.9f, 1.3f,
    1.2f, 0.8f,  0.9f,  1.0f, 0.9f, 1.3f, 1.35f, 1.35f, 1.4f,  1.35f, 1.3f, 1.35f, 1.4f, 1.2f,  1.2f, 1.5f, 1.0f,
    1.0f, 0.85f, 1.0f,  1.2f, 1.7f, 1.2f, 1.3f,  1.2f,  1.2f,  0.9f,  1.5f, 1.0f,  1.0f, 1.3f,  2.0f, 0.8f, 1.2f,
    1.2f, 1.2f,  0.8f,  1.2f, 0.8f, 0.8f, 1.2f,  0.8f,  1.2f,  1.25f, 1.4f, 0.9f,  1.2f, 1.25f, 0.9f, 1.2f, 0.7f,
    1.1f, 1.0f,  1.2f,  1.0f, 0.8f, 1.2f, 1.2f,  1.2f,  1.2f,  1.2f,  1.2f, 1.35f, 1.2f, 0.8f,  0.8f, 1.2f, 0.9f,
    1.0f, 1.2f,  1.0f,  1.2f, 1.0f, 1.1f, 1.5f,  1.55f, 1.5f,  1.6f,  1.6f, 1.75f, 1.6f, 1.5f,  1.6f, 1.0f,
};
static f32 D_84387D60[] = {
    0.0f,   0.0f,   -8.0f, 0.0f,   -5.0f,  0.0f,   -10.0f, 0.0f,   -10.0f, 0.0f,   0.0f,   0.0f,   0.0f,   0.0f,
    -35.0f, 0.0f,   0.0f,  0.0f,   0.0f,   0.0f,   -10.0f, 0.0f,   0.0f,   -10.0f, -10.0f, -10.0f, -5.0f,  0.0f,
    -10.0f, -10.0f, 0.0f,  -10.0f, 0.0f,   0.0f,   -10.0f, 0.0f,   0.0f,   0.0f,   -15.0f, 0.0f,   0.0f,   0.0f,
    0.0f,   0.0f,   0.0f,  -15.0f, 0.0f,   0.0f,   0.0f,   0.0f,   -10.0f, -17.0f, 0.0f,   -10.0f, 0.0f,   0.0f,
    0.0f,   -10.0f, -5.0f, -10.0f, -10.0f, 0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   -10.0f,
    0.0f,   0.0f,   0.0f,  0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   -5.0f,  0.0f,   -22.0f, 0.0f,   -25.0f, -20.0f,
    10.0f,  0.0f,   0.0f,  0.0f,   10.0f,  -15.0f, 0.0f,   -5.0f,  0.0f,   -10.0f, 0.0f,   -10.0f, 0.0f,   10.0f,
    0.0f,   0.0f,   0.0f,  0.0f,   -35.0f, -10.0f, 0.0f,   0.0f,   0.0f,   0.0f,   -5.0f,  0.0f,   0.0f,   5.0f,
    -10.0f, 0.0f,   0.0f,  -2.0f,  0.0f,   0.0f,   -10.0f, -10.0f, 0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,
    -15.0f, 0.0f,   0.0f,  0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   15.0f,  -5.0f,  0.0f,   0.0f,   0.0f,   0.0f,
    0.0f,   0.0f,   0.0f,  0.0f,   0.0f,   -15.0f, 0.0f,   -10.0f, -25.0f, -20.0f, -20.0f, 0.0f,
};

void BattleAnim_SetupReflectiveCamera(void) {
    Mtx* sp3C = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    LookAt* sp38 = Gfx_AllocDisplayList(sizeof(LookAt) * 1);
    unk_D_86002F34_00C* temp_v0 = BattleAnim_GetCameraContext();

    guLookAtReflect(sp3C, sp38, temp_v0->unk_60.eye.x, temp_v0->unk_60.eye.y, temp_v0->unk_60.eye.z,
                    temp_v0->unk_60.at.x, temp_v0->unk_60.at.y, temp_v0->unk_60.at.z, temp_v0->unk_60.up.x,
                    temp_v0->unk_60.up.y, temp_v0->unk_60.up.z);
}

void BattleAnim_SelectParticleModelFrames(Particle* arg0, s32 arg1) {
    f32 sp2C = 1.0f;
    s16 sp2A;
    s16 sp28;
    s16 sp26;
    s16 sp24 = Particle_FieldCD_GetU8_0C048(arg0);

    switch (Particle_FieldCF_GetS16_0C058(arg0)) {
        case 30:
            sp2A = 0x23;
            sp28 = 0x24;
            BattleAnim_ApplySpeciesMotionOffset(arg0);
            break;

        case 0:
            sp2A = 0x66;
            sp28 = 0x67;
            sp2C = 0.5f;
            BattleAnim_ApplySpeciesYOffsetVariantA(arg0);
            break;

        case 1:
            sp2A = 0x68;
            sp28 = 0x69;
            sp2C = 0.5f;
            break;

        case 2:
            sp2A = 0x6A;
            sp28 = 0x6B;
            sp2C = 0.5f;
            BattleAnim_ApplySpeciesYOffsetVariantB(arg0);
            break;

        case 3:
            sp2A = 0x73;
            sp28 = 0x74;
            sp2C = BattleAnim_GetSpeciesScaleAndApplyYOffset(arg0);
            break;

        case 4:
            sp2A = 0x78;
            sp28 = 0x79;
            Particle_SetPrimColor(arg0, 0x50, 0x46, 0x3C);
            Particle_SetEnvColor(arg0, 0xFF, 0, 0);
            break;

        case 5:
            sp2A = 0x7B;
            sp28 = 0x7C;
            break;

        case 6:
            sp2A = 0x7D;
            sp28 = 0x7E;
            break;

        case 7:
            sp2A = 0x7F;
            sp28 = 0x80;
            break;

        case 8:
            sp2A = 0x81;
            sp28 = 0x82;
            sp2C = 5.0f;
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
            Particle_SetPrimAlpha(arg0, 0x64);
            break;

        case 42:
            sp2A = 0x81;
            sp28 = 0x82;
            Particle_Field38_AddXZFromField94YOffset180_08F38(arg0, 300.0f);
            sp2C = 5.0f;
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xC);
            Particle_SetPrimAlpha(arg0, 0x64);
            break;

        case 43:
            sp2A = 0x81;
            sp28 = 0x82;
            sp2C = 5.0f;
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xF);
            Particle_SetPrimAlpha(arg0, 0x32);
            break;

        case 9:
            sp2A = 0x83;
            sp28 = 0x84;
            Particle_SetFlags(arg0, 0x800);
            Particle_Field38_AddYScaled_08E90(arg0, 5.0f);
            break;

        case 10:
            sp2A = 0x85;
            sp28 = 0x86;
            sp2C = 0.5f;
            break;

        case 11:
            sp2A = 0x88;
            sp28 = 0x89;
            sp2C = BattleAnim_GetSpeciesScaleAndOffset(arg0);
            break;

        case 12:
            sp2A = 0x8A;
            sp28 = 0x8B;
            break;

        case 13:
            sp2A = 0x9A;
            sp28 = 0x9B;
            sp2C = 1.5f;
            BattleAnim_ApplySpeciesYOffsetVariantC(arg0);

            switch (sp24) {
                case 1:
                    Particle_Field94_AddY_0A594(arg0, 0x6000);
                    break;

                case 2:
                    Particle_Field94_AddY_0A594(arg0, -0x4000);
                    break;
            }
            break;

        case 14:
            sp2A = 0x9C;
            sp2C = BattleAnim_GetSpeciesScaleAdjustSmall(arg0);
            Particle_SetPrimAlpha(arg0, 0);
            break;

        case 15:
            sp2A = 0x9C;
            sp2C = 1.5f;
            Particle_SetPrimAlpha(arg0, 0);
            break;

        case 16:
            sp2A = 0x9D;
            sp28 = 0x9E;

            switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
                case 0x5F:
                    Particle_Field38_AddXZFromField94YOffset180_08F38(arg0, 15.0f);
                    Particle_Field38_SetYScaled_08CA0(arg0, 15.0f);
                    break;

                case 0x82:
                    Particle_Field38_AddXZFromField94YOffset180_08F38(arg0, 15.0f);
                    break;
            }
            break;

        case 17:
            sp2A = 0xA3;
            sp28 = 0xA5;
            break;

        case 18:
            sp2A = 0xA3;
            sp28 = 0xA4;
            sp2C = 1.5f;
            break;

        case 19:
            sp2A = 0xA3;
            sp28 = 0xBB;
            sp2C = 1.5f;
            break;

        case 20:
            sp2A = 0xAA;
            sp28 = 0xAB;
            sp2C = 1.5f;
            break;

        case 21:
            sp2A = 0xAD;
            Particle_FieldAE_SetS16_0BF4C(arg0, 0xBE);
            Particle_SetPrimAlpha(arg0, 0);
            break;

        case 22:
            sp2A = 0x5C;
            sp28 = 0x5D;
            BattleAnim_ApplySpeciesXZOffsetVariantB(arg0);
            break;

        case 23:
            sp2A = 0xAE;
            Particle_SetPrimAlpha(arg0, 0);
            break;

        case 24:
            sp2A = 0xAE;
            Particle_SetPrimAlpha(arg0, 0);
            break;

        case 25:
            sp2A = 0xAF;
            sp28 = 0xB0;
            Particle_SetPrimColor(arg0, 0xFF, 0xFF, 0);
            Particle_SetEnvColor(arg0, 0xFF, 0, 0);
            Particle_Field38_SetYScaled_08CA0(arg0, 10.0f);
            break;

        case 26:
            sp2A = 0xB6;
            sp2C = BattleAnim_GetSpeciesScaleAdjustTiny(arg0);
            Particle_SetPrimAlpha(arg0, 0);
            break;

        case 27:
            sp2A = 0xB3;
            sp28 = 0xB4;
            Particle_SetPrimAlpha(arg0, 0x64);
            Particle_SetPrimColor(arg0, 0xFF, 0xFF, 0);
            Particle_SetEnvColor(arg0, 0xFF, 0, 0);
            sp2C = 0.8f;
            break;

        case 28:
            sp2A = 0xB3;
            sp28 = 0xB5;
            Particle_SetPrimAlpha(arg0, 0x64);
            Particle_SetPrimColor(arg0, 0xFF, 0xFF, 0);
            Particle_SetEnvColor(arg0, 0xFF, 0, 0);
            sp2C = 0.8f;
            break;

        case 29:
            sp2A = 0xBE;
            sp28 = 0xBF;
            break;

        case 31:
            sp2A = 0xC0;
            sp28 = 0xC1;
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
            Particle_SetPrimAlpha(arg0, 0x32);
            sp2C = 1.2f;
            break;

        case 32:
            sp2A = 0xB1;
            sp28 = 0xB2;
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0);
            Particle_SetPrimAlpha(arg0, 0);
            break;

        case 33:
            sp2A = 0xB7;
            break;

        case 34:
            sp2A = 0x2E;
            sp28 = 0x2F;
            Particle_Field94_AddY_0A594(arg0, -0x4000);
            sp2C = 0.5f;
            break;

        case 35:
            sp2A = 0x3B;
            sp28 = 0x3C;
            break;

        case 36:
            sp2A = 0x3D;
            sp28 = 0x3E;

            switch (sp24) {
                case 0:
                    sp26 = 0x6000;
                    break;

                case 1:
                    sp26 = 0x4000;
                    break;

                case 2:
                    sp26 = 0x2000;
                    break;
            }
            Particle_Field94_AddY_0A594(arg0, sp26);
            break;

        case 37:
            sp2A = 0x40;
            sp28 = 0x41;
            break;

        case 38:
            sp2A = 0x4B;
            sp28 = 0x4C;
            break;

        case 39:
            sp2A = 0x4D;
            sp28 = 0x4E;
            BattleAnim_ApplySpeciesXZOffsetVariantA(arg0);
            Particle_SetPrimColor(arg0, 0xFF, 0xFF, 0xFF);
            Particle_SetEnvColor(arg0, 0x37, 0xFF, 0xFF);
            break;

        case 40:
            sp2A = 0x57;
            sp28 = 0x58;
            break;

        case 41:
            sp2A = 0x5A;
            sp28 = 0x5B;
            sp2C = BattleAnim_GetSpeciesScaleAdjust(arg0);
            break;
    }

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        switch (arg1) {
            case 0:
                BattleAnim_InitModelWithAnim(arg0->unk_14, sp2A, sp28);
                break;

            case 1:
                BattleAnim_InitModel(arg0->unk_14, sp2A);
                BattleAnim_BindModelAnimReversed(arg0->unk_14, sp28);
                break;

            case 2:
                BattleAnim_InitModel(arg0->unk_14, sp2A);
                break;
        }
        Particle_Field1C_SetScaled_0B938(arg0, sp2C);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackInitModelAnimWait(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 0);
            break;

        case 2:
            if (ModelAnim_IsFinished(arg0->unk_14) != 0) {
                Particle_MarkInactive(arg0);
            }
            break;
    }
}

void BattleAnim_CallbackInitModelAnim(Particle* arg0) {
    if (arg0->unk_B2 == 1) {
        BattleAnim_SelectParticleModelFrames(arg0, 0);
    }
}

void BattleAnim_CallbackStartEffects83And103ModelAlphaFadeIn(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 0);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, arg0->unk_A6, Particle_FieldCE_GetS32_0C040(arg0));
            break;
    }
}

void BattleAnim_CallbackInitModelAnimWaitCleanup(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 1);
            break;

        case 2:
            if (BattleAnim_IsModelAnimComplete(arg0->unk_14) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void func_84341830(Particle* arg0) {
    if (arg0->unk_B2 == 1) {
        BattleAnim_SelectParticleModelFrames(arg0, 2);
    }
}

void BattleAnim_CallbackInitModelAnimMode2Update(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 2);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, arg0->unk_A6, Particle_FieldCE_GetS32_0C040(arg0));
            break;
    }
}

Gfx* BattleAnim_BuildAnimatedTileDisplayList(Gfx* arg0, u8* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9,
                   s16 argA, s16 argB) {
    gDPLoadTextureTile_4b(arg0++, arg1, G_IM_FMT_I, arg2, 0, 0, 0, arg2 - 1, arg2 - 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, arg6, arg7);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, arg4, arg5, arg2, arg2);

    gDPLoadMultiTile_4b(arg0++, arg1, 0x0100, 1, G_IM_FMT_I, arg2, 0, 0, 0, arg2 - 1, arg2 - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, argA, argB);

    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, arg8, arg9, arg2, arg2);
    return arg0;
}

Gfx* BattleAnim_BuildAnimatedTileDisplayListFromStruct(Gfx* arg0, arg1_func_8434E21C* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7,
                   s16 arg8, s16 arg9, s16 argA, s16 argB) {
    gDPLoadTextureTile_4b(arg0++, arg1->unk_00, G_IM_FMT_I, arg2, arg2, 0, 0, arg2 - 1, arg2 - 1, 0,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, arg6, arg7);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, arg4, arg5, arg2, arg2);

    gDPLoadMultiTile_4b(arg0++, arg1->unk_04, 0x0100, 1, G_IM_FMT_I, arg2, arg2, 0, 0, arg2 - 1, arg2 - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, argA, argB);
    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, arg8, arg9, arg2, arg2);
    return arg0;
}

void func_84341E50(Gfx* arg0) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, temp_v0->env_r, temp_v0->env_g, temp_v0->env_b, 255);

    gSPEndDisplayList(arg0++);
}

void func_84341F08(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_84341E50(arg1->unk_18);
    }
}

void func_84341F44(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    s16 mask = 5;
    Particle* sp40;
    s16 var_a2;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    s16 sp36;
    s16 w = 32;
    s16 h = 32;
    s16 sp30;
    s16 sp2E;
    s16 sp2C;
    s16 sp2A;
    s32 temp_v0_2;

    sp40 = BattleAnim_GetOwnerContextParticle(D_8006F09C);
    temp_v0_2 = Particle_FieldCE_GetS32_0C040(sp40);
    var_a2 = 0x80;

    switch (temp_v0_2) {
        case 0:
            var_a2 = 0x96;
            sp3C = 2;
            sp3A = 0;
            sp38 = -2;
            sp36 = 0;
            sp30 = 0xC;
            sp2E = 0;
            sp2C = 0xF;
            sp2A = 0;
            break;

        case 1:
            var_a2 = 0xFF;
            sp3C = 0;
            sp3A = 0;
            sp38 = 0xF;
            sp36 = 0;
            sp30 = 0xF;
            sp2E = 0;
            sp2C = 0xE;
            sp2A = 0xD;
            break;

        case 2:
            var_a2 = 0xFF;
            sp3C = 0;
            sp3A = 0;
            sp38 = 1;
            sp36 = 0;
            sp30 = 1;
            sp2E = 1;
            sp2C = 7;
            sp2A = 1;
            break;
    }

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, var_a2, sp40->prim_r, sp40->prim_g, sp40->prim_b, sp40->prim_a);
    gDPSetEnvColor(arg0++, sp40->env_r, sp40->env_g, sp40->env_b, 255);

    gDPLoadTextureTile_4b(arg0++, arg1->unk_00, G_IM_FMT_I, w, h, 0, 0, w - 1, h - 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, mask, mask, sp30, sp2E);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, sp3C, sp3A, w, h);

    gDPLoadMultiTile_4b(arg0++, arg1->unk_04, 0x0100, 1, G_IM_FMT_I, w, h, 0, 0, w - 1, h - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, mask, mask, sp2C, sp2A);

    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, sp38, sp36, w, h);

    gSPEndDisplayList(arg0++);
}

void func_84342304(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_84341F44(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void BattleAnim_SetupMove86EndDescriptor24(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 3.0f);
    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, 15.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, -5.0f);
    ParticleGfx_RecolorPrim(arg0, 0xA);
    ParticleGfx_RecolorEnv(arg0, 0x19);
    Particle_SetPrimAlpha(arg0, 0x96);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackMove86EndDescriptor24(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupMove86EndDescriptor24(arg0);
            break;

        case 2:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x20);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_Field1C_Approach_0B98C(arg0, 0.0f, 0.1f);
    Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
}

void BattleAnim_ApplyMove86SpeciesOffset(Particle* arg0) {
    f32 sp1C = 0.0f;
    f32 sp18 = 0.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x2D:
            sp1C = 15.0f;
            break;

        case 0x36:
            sp18 = 10.0f;
            break;

        case 0x3B:
            sp1C = 10.0f;
            sp18 = 10.0f;
            break;

        case 0x4D:
            sp1C = 10.0f;
            break;

        case 0x4F:
            sp1C = 10.0f;
            sp18 = -10.0f;
            break;

        case 0x59:
            sp1C = 20.0f;
            sp18 = -10.0f;
            break;

        case 0x60:
            sp1C = 15.0f;
            break;

        case 0x66:
            sp1C = 10.0f;
            break;

        case 0x67:
            sp1C = 15.0f;
            break;

        case 0x6C:
            sp1C = 15.0f;
            break;

        case 0x6F:
            sp1C = 15.0f;
            break;

        case 0x73:
            sp1C = 15.0f;
            break;

        case 0x7A:
            sp1C = 15.0f;
            break;

        case 0x7D:
            sp1C = 15.0f;
            break;

        case 0x7F:
            sp18 = 15.0f;
            break;

        case 0x82:
            sp1C = 15.0f;
            sp18 = 5.0f;
            break;

        case 0x94:
            sp1C = 15.0f;
            break;
    }
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, sp1C);
    Particle_Field38_AddYScaled_08E90(arg0, sp18);
}

void BattleAnim_SetupMove86StartDescriptor24(Particle* arg0) {
    Vec3f sp34;
    UNUSED s32 pad[2];
    s16 sp2A = Particle_FieldCD_GetU8_0C048(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.05f);

    switch (sp2A) {
        case 0:
            sp34.x = 0;
            sp34.y = -5.0f;
            sp34.z = 0.0f;
            break;

        case 1:
            sp34.x = 0;
            sp34.y = 5.0f;
            sp34.z = 10.0f;
            break;

        case 2:
            sp34.x = 0;
            sp34.y = 5.0f;
            sp34.z = -10.0f;
            break;
    }

    Particle_Field38_AddVecScaledFromVec3f_08D78(arg0, sp34);
    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
    BattleAnim_ApplyMove86SpeciesOffset(arg0);
    Particle_Field74_SetScaled_0AD8C(arg0, 0.0f);
    ParticleGfx_RecolorPrim(arg0, 0xA);
    ParticleGfx_RecolorEnv(arg0, 0x19);
    Particle_SetPrimAlpha(arg0, 0x96);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackMove86StartDescriptor24(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupMove86StartDescriptor24(arg0);
            break;

        case 2:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x10);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_Field1C_Approach_0B98C(arg0, 10.0f, 0.05f);
    Particle_AddVelocityXZFromRotationYViaImpulse(arg0);
}

void func_84342808(void) {
    BattleAnim_SpawnCategory17MarkerSlot(0x55, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 0xC, BattleAnim_CallbackMove86StartDescriptor24, &gBattleAnimParticleDescriptors[0x24], 0xA, 1, 4, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 0xC, BattleAnim_CallbackMove86StartDescriptor24, &gBattleAnimParticleDescriptors[0x24], 0xA, 1, 4, 1, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 0xC, BattleAnim_CallbackMove86StartDescriptor24, &gBattleAnimParticleDescriptors[0x24], 0xA, 1, 4, 2, 0, 0);
}

void func_84342908(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0x30, 0x20, 0xA);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 0xC, 0xA, BattleAnim_CallbackMove86EndDescriptor24, &gBattleAnimParticleDescriptors[0x24], 0x14, 1, 4, gBattleAnimCurrentAnchor, 0, 0);
}

void BattleAnim_ApplyEffect1SpeciesMotion(Particle* arg0) {
    f32 sp24 = 0.0f;
    f32 sp20 = 0.0f;
    f32 sp1C = 0.12f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x4:
            sp24 = 5.0f;
            break;
        case 0xF:
            sp24 = 5.0f;
            break;
        case 0x16:
            sp24 = 3.0f;
            break;
        case 0x1F:
            sp24 = 5.0f;
            break;
        case 0x22:
            sp24 = 3.0f;
            break;
        case 0x24:
            sp24 = 15.0f;
            sp20 = 15.0f;
            break;
        case 0x2A:
            sp20 = 12.0f;
            break;
        case 0x2D:
            sp24 = -15.0f;
            sp20 = 20.0f;
            break;
        case 0x39:
            sp24 = 10.0f;
            break;
        case 0x41:
            sp24 = 8.0f;
            break;
        case 0x4A:
            sp24 = 10.0f;
            break;
        case 0x4C:
            sp24 = 2.0f;
            break;
        case 0x4F:
            sp20 = 8.0f;
            sp24 = 7.0f;
            break;
        case 0x50:
            sp20 = 5.0f;
            sp24 = 7.0f;
            break;
        case 0x54:
            sp20 = 20.0f;
            sp24 = 20.0f;
            break;
        case 0x55:
            sp24 = 20.0f;
            sp20 = 25.0f;
            break;
        case 0x5A:
            sp24 = -15.0f;
            sp20 = 7.0f;
            break;
        case 0x5B:
            sp24 = -10.0f;
            break;
        case 0x5E:
            sp24 = 5.0f;
            break;
        case 0x61:
            sp24 = 5.0f;
            break;
        case 0x73:
            sp24 = 12.0f;
            break;
        case 0x7F:
            sp24 = 3.0f;
            break;
        case 0x80:
            sp24 = 3.0f;
            break;
        case 0x82:
            sp1C = 0.08f;
            sp20 = 5.0f;
            break;
        case 0x83:
            sp1C = 0.08f;
            sp24 = 5.0f;
            break;
        case 0x86:
            sp24 = 3.0f;
            break;
        case 0x88:
            sp24 = 3.0f;
            break;
        case 0x8A:
            sp24 = 15.0f;
            break;
        case 0x8C:
            sp24 = 12.0f;
            sp20 = 10.0f;
            break;
        case 0x8E:
            sp24 = 10.0f;
            break;
        case 0x91:
            sp24 = 3.0f;
            break;
    }

    Particle_Field38_AddXZFromField94Y_08ED0(arg0, sp24 + 5.0f);
    Particle_Field38_AddYScaled_08E90(arg0, sp20);
    Particle_Field1C_SetScaled_0B938(arg0, sp1C);
}

void BattleAnim_SetupEffect1Descriptor2F(Particle* arg0) {
    BattleAnim_ApplyEffect1SpeciesMotion(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect1Descriptor2FPhaseFadeOut(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SetupEffect1Descriptor2F(arg0);
            break;

        case 3:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x20);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);

        case 2:
            break;
    }
}

void BattleAnim_StartEffect1Descriptor2FPhaseFadeOut(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect1Descriptor2FPhaseFadeOut, &gBattleAnimParticleDescriptors[0x2F], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0, 0);
}

void BattleAnim_ApplyModelSpeciesOffset(Particle* arg0) {
    f32 var_fs0 = 0.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0xF:
            var_fs0 = -13.0f;
            break;
        case 0x10:
            var_fs0 = -35.0f;
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, -5.0f);
            break;
        case 0x11:
            var_fs0 = -45.0f;
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, -10.0f);
            break;
        case 0x12:
            var_fs0 = -45.0f;
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, -10.0f);
            break;
        case 0x16:
            var_fs0 = -15.0f;
            break;
        case 0x19:
            var_fs0 = -10.0f;
            break;
        case 0x22:
            var_fs0 = 10.0f;
            break;
        case 0x29:
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, -10.0f);
            var_fs0 = -60.0f;
            break;
        case 0x34:
            var_fs0 = -10.0f;
            break;
        case 0x36:
            var_fs0 = -5.0f;
            break;
        case 0x3B:
            var_fs0 = 25.0f;
            break;
        case 0x4A:
            var_fs0 = -30.0f;
            break;
        case 0x4C:
            var_fs0 = -10.0f;
            break;
        case 0x4D:
            var_fs0 = -5.0f;
            break;
        case 0x51:
            var_fs0 = -30.0f;
            break;
        case 0x52:
            var_fs0 = -8.0f;
            break;
        case 0x5A:
            var_fs0 = -12.0f;
            break;
        case 0x5B:
            var_fs0 = -15.0f;
            break;
        case 0x64:
            var_fs0 = -12.0f;
            break;
        case 0x66:
            var_fs0 = -20.0f;
            break;
        case 0x67:
            var_fs0 = 5.0f;
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, 10.0f);
            break;
        case 0x6C:
            var_fs0 = 10.0f;
            break;
        case 0x70:
            var_fs0 = 15.0f;
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, -10.0f);
            break;
        case 0x74:
            var_fs0 = -20.0f;
            break;
        case 0x75:
            var_fs0 = -10.0f;
            break;
        case 0x79:
            var_fs0 = -8.0f;
            break;
        case 0x7A:
            var_fs0 = -5.0f;
            break;
        case 0x7B:
            var_fs0 = -5.0f;
            break;
        case 0x7F:
            var_fs0 = 5.0f;
            break;
        case 0x80:
            var_fs0 = -12.0f;
            break;
        case 0x82:
            var_fs0 = -10.0f;
            Particle_Field1C_SetScaled_0B938(arg0, 0.15f);
            break;
        case 0x86:
            var_fs0 = -5.0f;
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 5.0f);
            break;
        case 0x87:
            var_fs0 = -15.0f;
            break;
        case 0x89:
            var_fs0 = -30.0f;
            break;
        case 0x93:
            var_fs0 = 18.0f;
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, -15.0f);
            break;
        case 0x94:
            var_fs0 = 15.0f;
            break;
        case 0x97:
            var_fs0 = -13.0f;
            break;
    }
    Particle_Field38_AddYScaled_08E90(arg0, var_fs0);
}

void BattleAnim_InitModelAnimationSlot(Particle* arg0, s16 arg1) {
    Vec3f sp24;

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);

    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x21, 0x22);
        Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
        BattleAnim_ApplyModelSpeciesOffset(arg0);
        Vec3f_SetComponentsDuplicate(&sp24, (arg1 * 5.0f * 2) + -10.0f, 5.0f, 10.0f);
        Particle_AddPositionRotatedVectorByYaw(arg0, sp24);

        switch (arg1) {
            case 0:
                Particle_Field94_SetZ_0A2CC(arg0, 0x1400);
                break;

            case 1:
                Particle_Field38_AddYScaled_08E90(arg0, 2.0f);
                Particle_Field94_SetZ_0A2CC(arg0, 0);
                break;

            case 2:
                Particle_Field94_SetZ_0A2CC(arg0, -0x1400);
                break;
        }

        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffects12And129DelayedModelAnimWait(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    switch (arg0->unk_B2) {
        case 1:
            Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 8);
            Particle_AdvanceLifecycle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                BattleAnim_InitModelAnimationSlot(arg0, sp26);
            }
            break;

        case 3:
            if (ModelAnim_IsFinished(arg0->unk_14) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_StartEffect12DelayedModelAnim(void) {
    BattleAnim_SpawnCategory17MarkerSlot(0x55, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects12And129DelayedModelAnimWait, &gDefaultParticleDescriptor, 0x1E, 3, 6, 0, 0, 0);
}

void BattleAnim_ApplySpeciesMotionOffset(Particle* arg0) {
    f32 sp1C = 10.0f;
    f32 sp18 = 0.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x5:
            sp18 = 10.0f;
            break;
        case 0xB:
            sp1C = 20.0f;
            break;
        case 0xC:
            sp1C = 8.0f;
            break;
        case 0xD:
            sp1C = 15.0f;
            break;
        case 0xF:
            sp1C = -10.0f;
            break;
        case 0x11:
            sp18 = 35.0f;
            sp1C = 0.0f;
            break;
        case 0x12:
            sp18 = 35.0f;
            sp1C = -5.0f;
            break;
        case 0x15:
            sp1C = 4.0f;
            break;
        case 0x16:
            sp18 = 5.0f;
            sp1C = 0.0f;
            break;
        case 0x18:
            sp18 = 8.0f;
            break;
        case 0x1C:
            sp18 = 5.0f;
            break;
        case 0x21:
            sp18 = 5.0f;
            break;
        case 0x26:
            sp1C = 15.0f;
            sp18 = 15.0f;
            break;
        case 0x28:
            sp1C = 15.0f;
            sp18 = 5.0f;
            break;
        case 0x29:
            sp1C = 0.0f;
            break;
        case 0x2A:
            sp18 = 20.0f;
            break;
        case 0x2B:
            sp1C = 15.0f;
            break;
        case 0x2D:
            sp1C = 10.0f;
            sp18 = 15.0f;
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, -1.0f);
            break;
        case 0x30:
            sp18 = 30.0f;
            sp1C = -2.0f;
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, -5.0f);
            break;
        case 0x31:
            sp1C = 5.0f;
            break;
        case 0x32:
            sp1C = 20.0f;
            break;
        case 0x33:
            sp1C = 25.0f;
            break;
        case 0x34:
            sp1C = 20.0f;
            break;
        case 0x36:
            sp1C = 15.0f;
            break;
        case 0x3B:
            sp1C = 20.0f;
            sp18 = 10.0f;
            break;
        case 0x3C:
            sp1C = 5.0f;
            break;
        case 0x3D:
            sp1C = 5.0f;
            break;
        case 0x3F:
            sp1C = 5.0f;
            break;
        case 0x40:
            sp18 = 10.0f;
            sp1C = 0.0f;
            break;
        case 0x41:
            sp1C = 20.0f;
            break;
        case 0x43:
            sp1C = 0.0f;
            break;
        case 0x44:
            sp18 = 8.0f;
            break;
        case 0x46:
            sp1C = -15.0f;
            break;
        case 0x47:
            sp1C = -5.0f;
            break;
        case 0x48:
            sp1C = -8.0f;
            break;
        case 0x49:
            sp1C = 0.0f;
            break;
        case 0x4B:
            sp1C = 0.0f;
            break;
        case 0x4C:
            sp1C = 0.0f;
            break;
        case 0x4D:
            sp1C = -10.0f;
            sp18 = 15.0f;
            break;
        case 0x4E:
            sp1C = -5.0f;
            break;
        case 0x4F:
            sp18 = 10.0f;
            break;
        case 0x51:
            sp1C = 0.0f;
            break;
        case 0x54:
            sp1C = 5.0f;
            break;
        case 0x55:
            sp1C = 5.0f;
            break;
        case 0x56:
            sp1C = 15.0f;
            sp18 = 15.0f;
            break;
        case 0x58:
            sp18 = 15.0f;
            break;
        case 0x59:
            sp18 = 40.0f;
            break;
        case 0x5B:
            sp1C = 0.0f;
            break;
        case 0x5C:
            sp18 = 10.0f;
            break;
        case 0x5D:
            sp18 = 15.0f;
            break;
        case 0x5E:
            sp1C = 5.0f;
            sp18 = 5.0f;
            break;
        case 0x5F:
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 23.0f);
            sp1C = -10.0f;
            sp18 = 0.0f;
            break;
        case 0x60:
            sp1C = 5.0f;
            sp18 = 10.0f;
            break;
        case 0x61:
            sp18 = 10.0f;
            break;
        case 0x62:
            sp18 = 10.0f;
            break;
        case 0x63:
            sp1C = 15.0f;
            sp18 = 60.0f;
            break;
        case 0x65:
            sp1C = 0.0f;
            sp18 = 20.0f;
            break;
        case 0x66:
            sp18 = 10.0f;
            break;
        case 0x67:
            sp18 = 40.0f;
            break;
        case 0x68:
            sp1C = 15.0f;
            break;
        case 0x6A:
            sp1C = 8.0f;
            break;
        case 0x6B:
            sp1C = 15.0f;
            break;
        case 0x6C:
            sp18 = 15.0f;
            break;
        case 0x6D:
            sp1C = 5.0f;
            break;
        case 0x6E:
            sp1C = 5.0f;
            break;
        case 0x6F:
            sp18 = 15.0f;
            sp1C = 0.0f;
            break;
        case 0x70:
            sp1C = 17.0f;
            sp18 = 10.0f;
            break;
        case 0x73:
            sp18 = 50.0f;
            break;
        case 0x75:
            sp1C = -10.0f;
            sp18 = 25.0f;
            break;
        case 0x77:
            sp1C = 0.0f;
            break;
        case 0x79:
            sp18 = 10.0f;
            sp1C = 5.0f;
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, -3.0f);
            break;
        case 0x7B:
            sp1C = 5.0f;
            break;
        case 0x7C:
            sp18 = 10.0f;
            break;
        case 0x7D:
            sp18 = 10.0f;
            break;
        case 0x7F:
            sp1C = 25.0f;
            break;
        case 0x80:
            sp18 = 5.0f;
            sp1C = -5.0f;
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 3.0f);
            break;
        case 0x82:
            sp1C = 15.0f;
            sp18 = 20.0f;
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 3.0f);
            break;
        case 0x83:
            sp18 = 10.0f;
            break;
        case 0x84:
            sp1C = 15.0f;
            break;
        case 0x85:
            sp1C = 20.0f;
            break;
        case 0x86:
            sp18 = 10.0f;
            break;
        case 0x8B:
            sp1C = 5.0f;
            break;
        case 0x8D:
            sp18 = 15.0f;
            sp1C = 0.0f;
            break;
        case 0x8E:
            sp1C = -15.0f;
            sp18 = 25.0f;
            break;
        case 0x8F:
            sp1C = 15.0f;
            sp18 = 30.0f;
            break;
        case 0x90:
            sp18 = 15.0f;
            break;
        case 0x91:
            sp1C = 15.0f;
            sp18 = 10.0f;
            break;
        case 0x92:
            sp1C = 15.0f;
            sp18 = 20.0f;
            break;
        case 0x94:
            sp18 = 15.0f;
            break;
        case 0x95:
            Particle_Field38_AddXZFromField94YOffset90_08FAC(arg0, 1.0f);
            sp1C = 10.0f;
            sp18 = 15.0f;
            break;
        case 0x96:
            sp18 = 20.0f;
            sp1C = 7.0f;
            break;
        case 0x97:
            break;
    }
    Particle_Field38_AddYScaled_08E90(arg0, sp1C);
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, sp18);
}

void BattleAnim_StartEffect14ModelAnimAndMoveKeyedTintParticles(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0x1E, 1, 0xB, 0, 0x1E, 0);
    BattleAnim_AddSpawnDelay(0xF);

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x70:
            BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 0x10, 8, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x44], 0, 4, 0xB, 0, 0x18, 5);
            break;

        case 0x71:
            BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 0x20);
            BattleAnim_SpawnOwnerModelTintPulseDetach(0, 0, 0xA, 0, 0xFF, 0x30);
            BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 0x10, 8, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x44], 0, 8, 0xB, 0, 0x17, 5);
            BattleAnim_SpawnDescriptor25AlphaFadeInHoldOut(0, 1, 0x20, 0xA, 0xFF);
            break;

        case 0x73:
            BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 0x20);
            BattleAnim_SpawnOwnerModelTintPulseDetach(0, 0, 0xA, 0, 0xFF, 0x30);
            BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 0x10, 8, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x44], 0, 8, 0xB, 0, 0, 5);
            BattleAnim_SpawnDescriptor25AlphaFadeInHoldOut(0, 1, 0x20, 0xA, 0xFF);
            break;
    }
}

void BattleAnim_BuildReflectiveTextureDisplayList(Gfx* arg0, s32 arg1, u16 arg2) {
    BattleAnim_SetupReflectiveCamera();

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x70:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, 255);
            gDPSetEnvColor(arg0++, 155, 255, 255, 255);
            break;

        case 0x71:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, 255);
            gDPSetEnvColor(arg0++, 255, 255, 100, 255);
            break;

        case 0x73:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 100, 255);
            gDPSetEnvColor(arg0++, 255, 100, 0, 255);
            break;
    }

    arg0 = BattleAnim_BuildAnimatedTileDisplayList(arg0, arg1, 0x20, 5, 0, 2, 0, 0, 0, 1, 0, 0);

    gSPEndDisplayList(arg0++);
}

void BattleAnim_AllocateReflectiveTextureDisplayList(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        BattleAnim_BuildReflectiveTextureDisplayList(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void BattleAnim_ApplyEffect125ModelScaleOffset(Particle* arg0) {
    f32 sp24 = 1.2f;
    f32 sp20 = 0.0f;
    s32 temp_v0 = BattleAnim_GetOwnerSpecies(arg0->unk_10);

    if (temp_v0 < 0x98) {
        sp24 = D_84387B00[temp_v0];
        sp20 = D_84387D60[temp_v0];
    }

    switch (temp_v0) {
        case 0x29:
            Particle_Field38_AddYScaled_08E90(arg0, 35.0f);
            break;

        case 0x57:
            Particle_Field38_AddYScaled_08E90(arg0, -10.0f);
            break;

        case 0x94:
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 15.0f);
            break;
    }

    Particle_Field1C_SetScaled_0B938(arg0, sp24);
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, sp20);
}

void BattleAnim_InitEffect125Model(Particle* arg0, UNUSED s16 arg1) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x25, 0x26);
        BattleAnim_ApplyEffect125ModelScaleOffset(arg0);
        Particle_FieldA6_SetS16_0BCA8(arg0, 0x20);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffect125ModelBurstEmitter(Particle* arg0) {
    s16 temp_a1 = Particle_FieldAC_GetS16_0C038(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffect125Model(arg0, temp_a1);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                BattleAnim_EmitParticleBurstWithMetadata(arg0, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 8, 0x18, 3);
                Particle_FieldA6_SetS16_0BCA8(arg0, 0x10);
            }
            break;

        case 3:
            Particle_Field1C_ApproachAndStepState_0B9D0(arg0, 0.0f, 0.05f);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 8);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_BuildEffect125DisplayList(Gfx* arg0, u16 arg1) {
    DisplayObject* tmp = D_8006F09C;

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, tmp->lodFraction);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, 1, 1, 0x20, 0x20);
    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, 2, 2, 0x20, 0x20);

    gSPEndDisplayList(arg0++);
}

void BattleAnim_AllocateEffect125DisplayList(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 10);
        BattleAnim_BuildEffect125DisplayList(arg1->unk_18, D_8006F084);
    }
}

void func_84344094(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect125ModelBurstEmitter, &gDefaultParticleDescriptor, 0x1E, 1, 7, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x14, BattleAnim_CallbackStartEffect125OwnerColorAlphaFade, &gDefaultParticleDescriptor, 0x50, 1, 0, 0, 0x35, 0);
}

void BattleAnim_InitEffect65Overlay(Particle* arg0) {
    s16 sp26;
    u16 sp24;
    u16 sp22;

    sp26 = BattleAnim_GetQueuedMoveId();
    sp24 = 0x19;
    sp22 = 0xA;
    Particle_FieldCA_SetU8_0BECC(arg0, 7);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_SetPosition(arg0, 160.0f, 120.0f, 0.0f);

    switch (sp26) {
        case 0x4E:
        case 0x93:
            break;

        case 0x4D:
            sp24 = 0x3E;
            sp22 = 0;
            break;

        case 0x4F:
            sp24 = 0x35;
            break;
    }

    ParticleGfx_RecolorPrim(arg0, sp24);
    ParticleGfx_RecolorEnv(arg0, sp22);
    Particle_SetPrimAlpha(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect65Descriptors31And32FadeIn(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffect65Overlay(arg0);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0xFF, 4);
            break;
    }
}

void func_84344248(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackStartEffect65Descriptors31And32FadeIn, &gBattleAnimParticleDescriptors[0x32], 0, 1, 0x18, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackStartEffect65Descriptors31And32FadeIn, &gBattleAnimParticleDescriptors[0x31], 0, 1, 0x18, 0, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 3, 0x14, BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion, &gBattleAnimParticleDescriptors[0x47], 0, 1, 0x10, 0x64, 0, 0);
}

void BattleAnim_InitEffect28Overlay(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldCA_SetU8_0BECC(arg0, 7);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_SetPosition(arg0, 160.0f, 120.0f, 0.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp26);
    Particle_SetPrimAlpha(arg0, 0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects28And53And76Descriptor33FadeIn(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffect28Overlay(arg0);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0xB4, 8);
            break;
    }
}

void func_843443E0(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackStartEffects28And53And76Descriptor33FadeIn, &gBattleAnimParticleDescriptors[0x33], 0, 1, 0x18, 0, 0x1C, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion, &gBattleAnimParticleDescriptors[0x47], 0, 0xF, 0x11, gBattleAnimCurrentAnchor, 0, 0);
}

void func_84344474(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackStartEffects28And53And76Descriptor33FadeIn, &gBattleAnimParticleDescriptors[0x33], 0, 1, 0x18, 0, 0x1E, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion, &gBattleAnimParticleDescriptors[0x47], 0, 0xF, 0x11, gBattleAnimCurrentAnchor, 0, 0);
}

void func_84344508(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackStartEffects28And53And76Descriptor33FadeIn, &gBattleAnimParticleDescriptors[0x33], 0, 1, 0x18, 0, 0x1D, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects28And53And65And76Descriptor47AnimatedScaleMotion, &gBattleAnimParticleDescriptors[0x47], 0, 0xF, 0x11, gBattleAnimCurrentAnchor, 0, 0);
}

void BattleAnim_InitEffect8Descriptor4A(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0xD);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect8Descriptor4ABurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffect8Descriptor4A(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 0x18);
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }

    Particle_Field1C_Approach_0B98C(arg0, 0.1f, 0.01f);
}

void BattleAnim_InitEffect8ModelBurst(Particle* arg0) {
    s16 sp2E = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
    Particle_Field74_SetScaled_0AD8C(arg0, 4.5f);
    Particle_Field94_AddVec_0A52C(arg0, ParticleMath_RandomSignedOffset(0x800, -0x3800), ParticleMath_RandomSigned(0x1400), 0);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp2E * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect8ModelBurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffect8ModelBurst(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
                BattleAnim_InitModel(arg0->unk_14, 0x9F);
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(3));
            }
            break;

        case 3:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                BattleAnim_EmitParticleBurstWithMetadata(arg0, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 1, 0x17, 4);
            }
            break;

        case 4:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0x1E);
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_ApproachRotationXTo(arg0, 0x1800, 0x400);
        Particle_AddVelocityFromRotationTemplate1(arg0);
        Particle_Field94_AddZ_0A5B0(arg0, 0x2000);
        BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackStartEffect8Descriptor4ABurstChild, &gBattleAnimParticleDescriptors[0x4A], 1);
    }
}

void BattleAnim_ApplyEffect31SpeciesOffset(Particle* arg0) {
    f32 sp1C = 0.0f;

    if (BattleAnim_GetOwnerSpecies(arg0->unk_10) == 0x8C) {
        sp1C = 5.0f;
    }
    Particle_Field38_AddYScaled_08E90(arg0, sp1C);
}

void BattleAnim_InitEffect31Model(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x2B, 0x2C);
        Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
        Particle_Field94_SetY_0A2B8(arg0, ParticleMath_RandomRange(0x10000));
        BattleAnim_ApplyEffect31SpeciesOffset(arg0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackMove73EndEffect31SpawnDescriptor42(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            Particle_FieldA6_SetS16_0BCA8(arg0, ParticleMath_RandomRange(0x18));
            Particle_AdvanceLifecycle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                BattleAnim_InitEffect31Model(arg0);
                BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 1, 0x10, arg0->unk_CD, 0x17, 4);
            }
            break;

        case 3:
            if (ModelAnim_IsFinished(arg0->unk_14) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;
    }
}

void BattleAnim_StartEffect8ModelBurstAndVerticalFade(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 5, BattleAnim_CallbackStartEffect8ModelBurstEmitter, &gDefaultParticleDescriptor, 0, 2, 0x11, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 3, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 1, 0x11, gBattleAnimCurrentAnchor, 0x33, 6);
}

void func_84344B04(void) {
    s32 i;
    s32 var_s2 = 0;
    s32 tmp;
    s32 end = gBattleAnimCurrentOwner->unk_000.anchorCount;

    if (end != 0) {
        for (i = 0; i < end; i++) {
            tmp = gBattleAnimCurrentOwner->unk_000.anchors[i].id;
            BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackMove73EndEffect31SpawnDescriptor42, &gDefaultParticleDescriptor, 0, 1, 0x10, tmp, 0, 0);
            var_s2++;
            if (var_s2 >= 8) {
                break;
            }
        }
    }
}

void func_84344BDC(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x22, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 2, 4, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 4, 9, 0, 0x17, 1);
}

void func_84344C7C(Gfx* arg0, u8* arg1) {
    BattleAnim_SetupReflectiveCamera();
    arg0 = BattleAnim_BuildAnimatedTileDisplayList(arg0, arg1, 0x20, 5, 2, 0, 0, 0, 1, 0, 0, 0);
    gSPEndDisplayList(arg0++);
}

void func_84344CE8(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_84344C7C(arg1->unk_18, arg1->unk_14);
    }
}

void BattleAnim_CallbackStartEffect34SpecialModelFadeIn_InitParticle(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocParticleDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0x30);
        Particle_SetFlags(arg0, 0x200);
        Particle_SetScale(arg0, 5.3f);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffect34SpecialModelFadeIn(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect34SpecialModelFadeIn_InitParticle(arg0);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0xFF, 0x20);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        BattleAnim_GetPointAlongCameraRay(&arg0->unk_50, 3700.0f);
    }
}

void BattleAnim_CallbackEndEffect23Descriptor4AAnimatedFade_InitParticle(Particle* arg0) {
    UNUSED s32 pad[2];
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    UNUSED s16 pad2;
    s16 sp22;

    Particle_FieldCE_GetS32_0C040(arg0);
    sp22 = Particle_FieldCF_GetS16_0C058(arg0);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_Field1C_SetScaled_0B938(arg0, 1.2f);
    Particle_SetScaleSpeed(arg0, 1.0f);
    Particle_SetScaleTarget(arg0, 0.02f);
    func_8140959C(arg0, 5, 0xF, 0xF);
    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.5f) + 8.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp22);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldAE_SetS16_0BF4C(arg0, 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffect23Descriptor4AAnimatedFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect23Descriptor4AAnimatedFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 4);
            }
            break;

        case 3:
            Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 1, 7, 1, 2, 0);
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x40, 8);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void func_84345038(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 0x35);
    BattleAnim_SpawnDescriptor25AlphaFadeInHold(0, 0xFF, 0x10, 0xA, 0x96);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect34SpecialModelFadeIn, &gDefaultParticleDescriptor, 0x1E, 1, 0x14, 0, 0, 0);
}

void func_843450B4(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 0xA, 2, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xC, 0, 0x2A, 0);
    BattleAnim_SpawnOwnerModelTintPaletteCycle(4, 0xA, 0x35, 8, 0xC8, 0x18);
    BattleAnim_SetSpawnDelay(4);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 5, 5, BattleAnim_CallbackEndEffect23Descriptor4AAnimatedFade, &gBattleAnimParticleDescriptors[0x4A], 0, 4, 0xB, 9, 0x13, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 3, 8, BattleAnim_CallbackEndEffect23Descriptor44ScalePulse, &gBattleAnimParticleDescriptors[0x44], 0, 4, 0xB, 9, 0x18, 0xB);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 7, 3, BattleAnim_CallbackEndEffect23Descriptor19AnimatedFade, &gBattleAnimParticleDescriptors[0x19], 0, 6, 0x10, gBattleAnimCurrentAnchor, 0x26, 0);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0x32, 0x20, 0xA);
}

void func_8434523C(Gfx* arg0, s32 arg1, u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, temp_v0->prim_a);

    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0, arg1, 0x40, 6, -4, 0xF, 0, 0, -0xF, 5, 0, 0);

    gSPEndDisplayList(arg0++);
}

void func_843452F0(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_8434523C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84345338(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0, arg1, 0x40, 6, -4, 0xF, 0, 0, -5, 5, 0, 0);

    gSPEndDisplayList(arg0++);
}

void func_8434539C(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_84345338(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_843453E4(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    arg0 = BattleAnim_BuildAnimatedTileDisplayList(arg0, arg1, 0x20, 5, -8, -0x1E, 0, 0, -0xB, -0xA, 0, 0);

    gSPEndDisplayList(arg0++);
}

void func_84345448(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_843453E4(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84345490(void) {
}

void BattleAnim_ApplyMove146SpeciesOffset(Particle* arg0) {
    f32 sp1C = 5.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0xF:
            sp1C = -10.0f;
            break;

        case 0x10:
            sp1C = -30.0f;
            break;

        case 0x11:
            sp1C = -35.0f;
            break;

        case 0x12:
            sp1C = -35.0f;
            break;

        case 0x29:
            sp1C = -50.0f;
            break;

        case 0x3B:
            sp1C = 23.0f;
            break;

        case 0x4A:
            sp1C = -25.0f;
            break;

        case 0x5A:
            sp1C = -8.0f;
            break;

        case 0x5F:
            sp1C = -20.0f;
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 10.0f);
            break;

        case 0x64:
            sp1C = -10.0f;
            break;

        case 0x89:
            sp1C = -25.0f;
            break;

        case 0x93:
            sp1C = 17.0f;
            break;

        case 0x97:
            sp1C = -10.0f;
            break;
    }
    Particle_Field38_AddYScaled_08E90(arg0, sp1C);
}

void BattleAnim_InitMove146Model(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);
    s16 sp24;

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);

    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x31, 0x32);
        Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
        BattleAnim_ApplyMove146SpeciesOffset(arg0);
        switch (sp26) {
            case 0:
                sp24 = 0;
                break;

            case 1:
                sp24 = 0x5555;
                break;

            case 2:
                sp24 = -0x5556;
                break;
        }

        Particle_Field94_AddY_0A594(arg0, sp24);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackMove146EndEffect6ModelAnimWait(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitMove146Model(arg0);
            break;

        case 2:
            if (ModelAnim_IsFinished(arg0->unk_14) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void func_8434575C(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackMove146EndEffect6ModelAnimWait, &gDefaultParticleDescriptor, 0x1E, 1, 6, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackMove146EndEffect6ModelAnimWait, &gDefaultParticleDescriptor, 0x1E, 1, 6, gBattleAnimCurrentAnchor, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackMove146EndEffect6ModelAnimWait, &gDefaultParticleDescriptor, 0x1E, 1, 6, gBattleAnimCurrentAnchor, 2, 0);
}

void BattleAnim_InitEffect49Model(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);
    u16 sp24;

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x47:
            sp24 = 0x18;
            break;

        case 0x48:
            sp24 = 0x1F;
            break;

        case 0x8D:
            sp24 = 0x21;
            break;
    }

    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0x33);
        if (sp26 == 0) {
            BattleAnim_BindModelAnim(arg0->unk_14, 0x34);
        } else {
            BattleAnim_BindModelAnimReversed(arg0->unk_14, 0x34);
        }
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackEndEffect49Model33Anim34WaitCleanup(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffect49Model(arg0);
            break;

        case 2:
            if (BattleAnim_IsModelAnimComplete(arg0->unk_14) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffect21ModelAnimWait(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffect49Model(arg0);
            break;

        case 2:
            if (ModelAnim_IsFinished(arg0->unk_14) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_BuildEffect49DisplayList(Gfx* arg0, UNUSED s32 arg1, UNUSED u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, temp_v0->env_r, temp_v0->env_g, temp_v0->env_b, 0);

    gSPEndDisplayList(arg0++);
}

void BattleAnim_AllocateEffect49DisplayList(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        BattleAnim_BuildEffect49DisplayList(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84345B28(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect49Model33Anim34WaitCleanup, &gDefaultParticleDescriptor, 0, 1, 2, gBattleAnimCurrentAnchor, 1, 0);
}

void func_84345B84(void) {
    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x8D:
            BattleAnim_SpawnOwnerModelTintPaletteFade(0, 0xC, 0x41, 2, 0xC8, 0x10);
            break;

        case 0x47:
            BattleAnim_SpawnOwnerModelTintPaletteFade(0, 0x37, 0x41, 2, 0xC8, 0x10);
            break;

        case 0x48:
            BattleAnim_SpawnOwnerModelTintPaletteFade(0, 0x29, 0x41, 2, 0xC8, 0x10);
            break;
    }

    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect21ModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 2, gBattleAnimCurrentAnchor, 0, 0);
}

void BattleAnim_InitEffect40Model(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0x35);
        Particle_Field1C_SetScaled_0B938(arg0, 5.0f);
        Particle_Field38_AddYScaled_08E90(arg0, -100.0f);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffect40ModelFadeCycle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffect40Model(arg0);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0x80, 0x10);
            break;

        case 3:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 4:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x20);
            break;
    }
}

void func_84345D74(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect40ModelFadeCycle, &gDefaultParticleDescriptor, 0xA, 1, 0xA, 0, 0, 0);
}

void BattleAnim_InitEffect86Model(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0x35);
        Particle_Field1C_SetScaled_0B938(arg0, 5.0f);
        Particle_Field38_AddYScaled_08E90(arg0, -100.0f);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffect86ModelFadeCycle(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffect86Model(arg0);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0x80, 0x10);
            break;

        case 3:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 4:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x20);
            break;
    }
}

void func_84345EC0(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect86ModelFadeCycle, &gDefaultParticleDescriptor, 0x40, 1, 0xA, 0, 0, 0);
    BattleAnim_SpawnOwnerModelAlphaFade(0, 0xFF, 0, 0x10);
    BattleAnim_SpawnOwnerModelAlphaFade(0x2D, 0, 0xFF, 0x20);
}

void BattleAnim_BuildEffect63DisplayList(Gfx* arg0, s32 arg1, u16 arg2) {
    UNUSED s32 pad;
    Particle* sp28 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, 1, 0x28, 0x20, 0x20);
    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, -1, 0x1E, 0x20, 0x20);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, sp28->prim_a);
    gDPSetEnvColor(arg0++, 255, 55, 100, 255);

    gSPEndDisplayList(arg0++);
}

void BattleAnim_AllocateEffect63DisplayList(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        BattleAnim_BuildEffect63DisplayList(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void BattleAnim_BuildEffect75DisplayList(Gfx* arg0, UNUSED s32 arg1, UNUSED u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, 255, 255, 100, 255);

    gSPEndDisplayList(arg0++);
}

void BattleAnim_AllocateEffect75DisplayList(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        BattleAnim_BuildEffect75DisplayList(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void BattleAnim_InitEffects63And75Model(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        if (sp26 == 0) {
            BattleAnim_InitModelWithAnim(arg0->unk_14, 0x36, 0x37);
            Particle_Field1C_SetScaled_0B938(arg0, 0.75f);
        } else {
            BattleAnim_InitModelWithAnim(arg0->unk_14, 0x61, 0x62);
            Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        }
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffects63And75ModelAnimWait(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffects63And75Model(arg0);
            break;

        case 2:
            if (ModelAnim_IsFinished(arg0->unk_14) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_InitEffects10And50Model(Particle* arg0) {
    u16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x39, 0x3A);
        Particle_Field1C_SetScaled_0B938(arg0, 0.5f);

        switch (sp26) {
            case 0:
                break;

            case 1:
                Particle_Field38_AddVecScaled_08E18(arg0, -10.0f, 0.0f, 20.0f);
                break;

            case 2:
                Particle_Field38_AddVecScaled_08E18(arg0, 10.0f, 0.0f, -20.0f);
                break;

            case 3:
                Particle_Field38_AddVecScaled_08E18(arg0, 20.0f, 0.0f, -20.0f);
                break;

            case 4:
                Particle_Field38_AddVecScaled_08E18(arg0, -20.0f, 0.0f, 20.0f);
                break;

            case 5:
                Particle_Field38_AddVecScaled_08E18(arg0, 15.0f, 0.0f, -25.0f);
                break;

            case 6:
                Particle_Field38_AddVecScaled_08E18(arg0, 20.0f, 0.0f, 30.0f);
                break;

            case 7:
                Particle_Field38_AddVecScaled_08E18(arg0, 15.0f, 0.0f, -10.0f);
                break;

            case 8:
                Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
                break;
        }
        Particle_SetPrimColor(arg0, 0xFF, 0xFF, 0xFF);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackEndEffects10And50ModelAnimColorFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffects10And50Model(arg0);
            break;

        case 2:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0xA);
            break;

        case 3:
            Particle_PrimR_Approach_0BAE4(arg0, 0, 0x10);
            Particle_PrimG_Approach_0BB14(arg0, 0, 0x20);
            if (ModelAnim_IsFinished(arg0->unk_14) != 0) {
                Particle_AdvanceLifecycle(arg0);
            }
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_ApplyEffects63And75SpeciesScaleOffset(Particle* arg0) {
    f32 sp1C = 0.6f;
    f32 sp18 = 0.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x3:
            sp1C = 1.0f;
            sp18 = 5.0f;
            break;

        case 0x22:
            sp1C = 1.0f;
            sp18 = 5.0f;
            break;

        case 0x4C:
            sp1C = 0.8f;
            sp18 = 5.0f;
            break;

        case 0x5E:
            sp1C = 0.8f;
            sp18 = 5.0f;
            break;

        case 0x80:
            sp1C = 0.8f;
            sp18 = 10.0f;
            break;

        case 0x82:
            sp18 = 20.0f;
            break;

        case 0x88:
            sp1C = 1.2f;
            sp18 = 10.0f;
            break;

        case 0x8E:
            sp1C = 1.2f;
            sp18 = 20.0f;
            break;

        case 0x91:
            sp1C = 1.2f;
            sp18 = 15.0f;
            break;

        case 0x95:
            sp18 = 10.0f;
            break;
    }

    Particle_Field1C_SetScaled_0B938(arg0, sp1C);
    Particle_Field38_AddXZFromField94YOffset180_08F38(arg0, sp18);
}

void BattleAnim_InitEffects63And75Model38(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0x38);
        BattleAnim_ApplyEffects63And75SpeciesScaleOffset(arg0);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffects63And75Model38FadeIn(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_InitEffects63And75Model38(arg0);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0xFF, 4);
            break;
    }
}

void func_843466EC(Gfx* arg0, s32 arg1, u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0xC8, 255, 255, 255, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, 255, 155, 0, 255);

    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0, arg1, 0x20, 5, 1, 0, 0, 0, -1, 0, 0, 0);

    gSPEndDisplayList(arg0++);
}

void func_843467B0(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_843466EC(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_843467F8(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, 255, 255, 255, temp_v0->prim_r);
    gDPSetEnvColor(arg0++, 255, 155, 0, 255);
    gDPSetCombineLERP(arg0++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED,
                      0, 0, 0, COMBINED);
    gDPSetTextureLUT(arg0++, G_TT_NONE);
    gSPTexture(arg0++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPLoadTextureBlock_4b(arg0++, arg1, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPEndDisplayList(arg0++);
}

void func_84346960(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_843467F8(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_843469A8(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, 255, 255, 255, temp_v0->prim_g);
    gDPSetEnvColor(arg0++, 255, 255, 0, 255);
    gDPSetCombineLERP(arg0++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED,
                      0, 0, 0, COMBINED);
    gDPSetTextureLUT(arg0++, G_TT_NONE);
    gSPTexture(arg0++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPLoadTextureBlock_4b(arg0++, arg1, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPEndDisplayList(arg0++);
}

void func_84346B10(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_843469A8(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84346B58(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects63And75ModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects63And75Model38FadeIn, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
}

void func_84346BE0(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(2, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 2, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(5, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 3, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(9, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 5, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xA, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 6, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xD, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 7, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xA, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void func_84346DC4(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects63And75ModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 1, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects63And75Model38FadeIn, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
}

void func_84346E50(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects10And50ModelAnimColorFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 8, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xA, 3, 2, BattleAnim_CallbackSharedDescriptors3EAnd3FAnimatedRiseFade, &gBattleAnimParticleDescriptors[0x3E], 0, 0x10, 0xA, 0, 0x11, 0);
}

void func_84346EEC(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x23, 0);
}

void func_84346F40(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x24, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 1, 0x24, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 2, 0x24, 0);
    BattleAnim_SpawnOwnerModelTintPulseDetach(0x5F, 0, 0xA, 0, 0xFF, 8);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x5F, 8, 0xC, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 9, 0, 0x17, 6);
}

void BattleAnim_CallbackStartEffect10Model60AlphaFadeIn_InitParticle(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0x60);
        Particle_FieldCA_SetU8_0BECC(arg0, 7);
        Particle_SetFlags(arg0, 0x200);
        Particle_SetScale(arg0, 3.3f);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffect10Model60AlphaFadeIn(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect10Model60AlphaFadeIn_InitParticle(arg0);
            break;

        case 2:
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x9B, 8);
            break;

        case 3:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        BattleAnim_GetPointAlongCameraRay(&arg0->unk_50, 200.0f);
    }
}

void func_8434719C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);
    gDPSetEnvColor(arg0++, 155, 255, 255, 255);

    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0, arg1, 0x20, 5, 2, 1, 0xE, 0xF, 0, 4, 0xC, 5);

    gSPEndDisplayList(arg0++);
}

void func_84347254(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_8434719C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434729C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, 0, 255, 255, 255);

    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0, arg1, 0x20, 5, -3, -5, 0xD, 3, 0, -2, 0xF, 2);

    gSPEndDisplayList(arg0++);
}

void func_84347374(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_8434729C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void BattleAnim_StartEffect10Model60AndModelAnimWait(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xE, 0, 0x25, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect10Model60AlphaFadeIn, &gDefaultParticleDescriptor, 0, 1, 0x14, 0, 0, 0);
}

void func_84347448(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xE, 0, 0x25, 0);
}

void BattleAnim_ApplySpeciesXZOffsetVariantA(Particle* arg0) {
    f32 var_fs0 = 0.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x5:
            Particle_Field38_AddXZFromField94YOffset180_08F38(arg0, 10.0f);
            break;

        case 0xC:
            var_fs0 = 20.0f;
            break;

        case 0xD:
            var_fs0 = -5.0f;
            Particle_Field38_AddXZFromField94YOffset180_08F38(arg0, 15.0f);
            break;

        case 0x34:
            var_fs0 = -10.0f;
            break;

        case 0x4A:
            var_fs0 = 10.0f;
            break;

        case 0x4D:
            var_fs0 = 10.0f;
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, 10.0f);
            break;

        case 0x5A:
            var_fs0 = -5.0f;
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, 5.0f);
            break;

        case 0x66:
            var_fs0 = -5.0f;
            break;

        case 0x6A:
            var_fs0 = 15.0f;
            break;

        case 0x91:
            var_fs0 = 15.0f;
            break;

        case 0x94:
            var_fs0 = -15.0f;
            break;

        case 0x97:
            var_fs0 = 20.0f;
            break;
    }

    if (var_fs0 != 0.0f) {
        Particle_Field38_AddYScaled_08E90(arg0, var_fs0);
    }
}

void BattleAnim_CallbackStartEffects50And82ModelDelay(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 0);
            break;

        case 2:
            Particle_TickDelayAndAdvanceLifecycle(arg0, arg0->unk_A6);
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackStartEffects50And82ScalePulse_InitParticle(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 2.0f);
    Particle_Field38_AddXZFromField94YOffset180_08F38(arg0, 10.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_SetTextureFrame(arg0, 1);
    Particle_Field94_SetZ_0A2CC(arg0, ParticleMath_RandomRange(0x10000));
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects50And82ScalePulse(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects50And82ScalePulse_InitParticle(arg0);
            break;

        case 2:
            Particle_Field1C_ApproachAndStepState_0B9D0(arg0, 10.0f, 1.0f);
            break;

        case 3:
            Particle_Field1C_ApproachAndStepState_0B9D0(arg0, 0.0f, 1.0f);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x40, 0x20);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void BattleAnim_CallbackStartEffects50And82Descriptor48AnimatedScaleFade_InitParticle(Particle* arg0) {
    UNUSED s16 pad;
    s16 sp34;
    Vec3s sp2C;
    UNUSED s32 pad2[3];

    Particle_FieldAC_GetS16_0C038(arg0);
    sp34 = Particle_FieldCF_GetS16_0C058(arg0);
    func_8140959C(arg0, 5, 5, 5);
    Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
    Particle_Field74_SetScaled_0AD8C(arg0, 1.5f);
    sp2C.x = ParticleMath_RandomRange(0x2000) - 0x1000;
    sp2C.y = ParticleMath_RandomRange(0x10000);
    sp2C.z = 0;
    Particle_Field94_AddVecFromVec3s_0A4F0(arg0, sp2C);
    Particle_AddRotationTargetXY(arg0, sp2C.x, sp2C.y);
    Particle_Field9A_SetXY_0A3A0(arg0, 0, 0);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp34);
    Particle_SetPrimAlpha(arg0, 0x80);
    Particle_FieldA6_SetS16_0BCA8(arg0, arg0->unk_AC * 2);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects50And82Descriptor48AnimatedScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects50And82Descriptor48AnimatedScaleFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xA);
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_Field1C_Approach_0B98C(arg0, 2.5f, 0.25f);
            Particle_AddVelocityFromRotationTemplate1(arg0);
            Particle_Field38_AddYScaled_08E90(arg0, 0.5f);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 0x10);
                Particle_PrimG_Approach_0BB14(arg0, 0, 0x14);
                Particle_EnvR_Approach_0BB90(arg0, 0, 0x14);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackStartEffects50And82Descriptor4AAnimatedVerticalFade_InitParticle(Particle* arg0) {
    UNUSED s32 pad[2];
    UNUSED s16 pad2;
    s16 sp24;

    Particle_FieldAC_GetS16_0C038(arg0);
    sp24 = Particle_FieldCF_GetS16_0C058(arg0);
    Particle_FieldCE_GetS32_0C040(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    func_8140959C(arg0, 0xF, 0xF, 0x14);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0x32) * 0.02f) + 1.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetPrimAlpha(arg0, 0x80);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects50And82Descriptor4AAnimatedVerticalFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects50And82Descriptor4AAnimatedVerticalFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 5);
            }
            break;

        case 3:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_AddVelocityYFromFieldOffset74(arg0);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_PrimG_Approach_0BB14(arg0, 0, 0x14);
                Particle_EnvR_Approach_0BB90(arg0, 0, 0x14);
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 4);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void func_84347BF4(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0x78, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, temp_v0->env_r, temp_v0->env_g, temp_v0->env_b, temp_v0->unk_B0);
    gDPSetCombineLERP(arg0++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, PRIMITIVE,
                      ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, ENVIRONMENT);

    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0, arg1, 0x20, 5, 2, 0xA, 0xD, 0xF, -2, 5, 0xE, 0xF);

    gSPEndDisplayList(arg0++);
}

void func_84347D2C(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_84347BF4(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void BattleAnim_CallbackStartEffects50And82CenterModelScalePaletteFade(Particle* arg0) {
    Particle_FieldCE_GetS32_0C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 2);
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_FieldB0_SetS16_0BFEC(arg0, 0x64);
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
            Particle_FieldA6_SetS16_0BCA8(arg0, 5);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 7.0f, 0.25f);
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 5);
            }
            break;

        case 3:
            Particle_Field1C_Approach_0B98C(arg0, 7.0f, 0.25f);
            ParticleGfx_ApproachPrimEnvPalettePair(arg0, 0x1A, 0x19);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_FieldB0_Approach_0C000(arg0, 0, 8);
                Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x10);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackStartEffects50And82OffsetModelsScalePaletteFade(Particle* arg0) {
    s16 sp26 = Particle_FieldCE_GetS32_0C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 2);
            Particle_Field1C_SetScaled_0B938(arg0, 0.5f);
            Particle_FieldB0_SetS16_0BFEC(arg0, 0x64);
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
            Particle_FieldA6_SetS16_0BCA8(arg0, 5);

            switch (sp26) {
                case 0:
                    Particle_Field38_SetXScaled_08C88(arg0, 15.0f);
                    Particle_Field38_SetYScaled_08CA0(arg0, 15.0f);
                    break;

                case 1:
                    Particle_Field38_SetXScaled_08C88(arg0, -15.0f);
                    Particle_Field38_SetZScaled_08CB8(arg0, 15.0f);
                    Particle_Field38_SetYScaled_08CA0(arg0, -10.0f);
                    break;

                case 2:
                    Particle_Field38_SetXScaled_08C88(arg0, -10.0f);
                    Particle_Field38_SetZScaled_08CB8(arg0, -15.0f);
                    break;
            }
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 5.0f, 0.15f);
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 5);
            }
            break;

        case 3:
            Particle_Field1C_Approach_0B98C(arg0, 5.0f, 0.15f);
            ParticleGfx_ApproachPrimEnvPalettePair(arg0, 0x1A, 0x19);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_FieldB0_Approach_0C000(arg0, 0, 8);
                Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x10);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffects81And82ModelScalePaletteFade(Particle* arg0) {
    Particle_FieldCE_GetS32_0C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 2);
            Particle_Field1C_SetScaled_0B938(arg0, 0.25f);
            Particle_FieldB0_SetS16_0BFEC(arg0, 0x64);
            ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x17);
            Particle_FieldA6_SetS16_0BCA8(arg0, 5);
            Particle_Field38_AddXZFromField94Y_08ED0(arg0, 30.0f);
            break;

        case 2:
            Particle_Field1C_Approach_0B98C(arg0, 5.0f, 0.3f);
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 5);
            }
            break;

        case 3:
            Particle_Field1C_Approach_0B98C(arg0, 5.0f, 0.3f);
            ParticleGfx_ApproachPrimEnvPalettePair(arg0, 0x1A, 0x19);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_FieldB0_Approach_0C000(arg0, 0, 8);
                Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x10);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffects81And82Descriptor4AAnimatedColorFade_InitParticle(Particle* arg0) {
    UNUSED s32 pad[2];
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);

    Particle_FieldCE_GetS32_0C040(arg0);
    Particle_FieldCF_GetS16_0C058(arg0);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_Field1C_SetScaled_0B938(arg0, 1.2f);
    Particle_SetScaleSpeed(arg0, 1.0f);
    Particle_SetScaleTarget(arg0, 0.02f);
    func_8140959C(arg0, 5, 0xF, 0xF);
    Particle_Field38_AddYScaled_08E90(arg0, 10.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.5f) + 8.0f);
    ParticleGfx_RecolorPrim(arg0, 0x19);
    ParticleGfx_RecolorEnv(arg0, 0x19);
    Particle_SetPrimAlpha(arg0, 0xC8);
    Particle_FieldAE_SetS16_0BF4C(arg0, 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffects81And82Descriptor4AAnimatedColorFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects81And82Descriptor4AAnimatedColorFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 4);
            }
            break;

        case 3:
            Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 1, 7, 1, 2, 0);
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            Particle_PrimG_Approach_0BB14(arg0, 0, 0x20);
            Particle_EnvG_Approach_0BBF0(arg0, 0, 0x20);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                break;
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void BattleAnim_CallbackEndEffects81And82Descriptor4FAnimatedPaletteFade_InitParticle(Particle* arg0) {
    UNUSED s32 pad[2];
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    UNUSED s16 pad2;
    s16 sp22;

    Particle_FieldCE_GetS32_0C040(arg0);
    sp22 = Particle_FieldCF_GetS16_0C058(arg0);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 2);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, Particle_FieldCF_GetS16_0C058(arg0));
    Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
    Particle_SetScaleSpeed(arg0, 0.5f);
    Particle_SetScaleTarget(arg0, 0.01f);
    func_8140959C(arg0, 0xA, 0, 0xF);
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, 10.0f);
    Particle_Field38_AddYScaled_08E90(arg0, 5.0f);
    Particle_Field74_SetScaled_0AD8C(arg0, (ParticleMath_RandomRange(0xA) * 0.5f) + 8.0f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp22);
    Particle_SetPrimAlpha(arg0, 0xB4);
    Particle_FieldAE_SetS16_0BF4C(arg0, 4);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackEndEffects81And82Descriptor4FAnimatedPaletteFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffects81And82Descriptor4FAnimatedPaletteFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 4);
            }
            break;

        case 3:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0x40, 0x10);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                ParticleGfx_ApproachPrimEnvPalettePair(arg0, 0x16, 0x20);
            }
            Particle_Field74_Approach_0ADBC(arg0, 4.0f, 0.5f);
            Particle_AddVelocityXZFromRotationYPlusHalfTurn(arg0);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);
        Particle_AnimateFramesForward(arg0, 0, 7, 1, 2, 0);
    }
}

void func_84348630(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects50And82ModelDelay, &gDefaultParticleDescriptor, 0x19, 1, 0xE, 0, 0x27, 0);
    BattleAnim_SpawnDescriptor25AlphaFadeInHold(0, 0, 4, 0x1C, 0x80);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x16, BattleAnim_CallbackStartEffects50And82ScalePulse, &gBattleAnimParticleDescriptors[0x54], 0, 1, 0xC, 0, 0x25, 0);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(0x1A, 3, 0x20, 0x1C, 0x96);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x1B, BattleAnim_CallbackStartEffects50And82CenterModelScalePaletteFade, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0x21, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x1E, BattleAnim_CallbackStartEffects50And82OffsetModelsScalePaletteFade, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0x21, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x22, BattleAnim_CallbackStartEffects50And82OffsetModelsScalePaletteFade, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0x21, 1);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x26, BattleAnim_CallbackStartEffects50And82OffsetModelsScalePaletteFade, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0x21, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x28, BattleAnim_CallbackStartEffects50And82Descriptor48AnimatedScaleFade, &gBattleAnimParticleDescriptors[0x48], 0, 6, 0x10, 9, 0x1A, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x32, 2, 2, BattleAnim_CallbackStartEffects50And82Descriptor4AAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 1, 9, 0, 0x1A, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x33, 2, 2, BattleAnim_CallbackStartEffects50And82Descriptor4AAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 1, 9, 0, 0x1A, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x34, 2, 2, BattleAnim_CallbackStartEffects50And82Descriptor4AAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 1, 9, 0, 0x1A, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x36, 2, 2, BattleAnim_CallbackStartEffects50And82Descriptor4AAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 1, 9, 0, 0x1A, 0);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x16, 0xA, 0, 0xFF, 0x40);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x24, 0xA, 0xFF, 0xDC, 0xC);
    BattleAnim_SpawnOwnerModelTintPaletteApproachInactiveAlt(0x28, 0xA, 0x19, 0x10, 0xDC);
    BattleAnim_SpawnOwnerModelTintPaletteApproachInactiveAlt(0x38, 0x19, 0x13, 0x10, 0xDC);
    BattleAnim_SpawnOwnerModelTintPaletteApproachInactiveAlt(0x40, 0x13, 0x10, 0x10, 0xDC);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x48, 0x10, 0xDC, 0xB4, 6);
}

void func_843489FC(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0xFF, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects81And82ModelScalePaletteFade, &gDefaultParticleDescriptor, 0, 1, 0xB, 0, 0x21, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackEndEffects81And82ModelScalePaletteFade, &gDefaultParticleDescriptor, 0, 1, 0xB, 0, 0x21, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xA, 8, 4, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xC, 0, 0x2B, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xC, 8, 5, BattleAnim_CallbackEndEffects81And82Descriptor46AnimatedFade, &gBattleAnimParticleDescriptors[0x46], 0, 5, 0x10, 9, 0x48, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xC, 4, 0xA, BattleAnim_CallbackEndEffects81And82Descriptor4AAnimatedColorFade, &gBattleAnimParticleDescriptors[0x4A], 0, 4, 0xB, 9, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xC, 4, 0xA, BattleAnim_CallbackEndEffects81And82Descriptor4FAnimatedPaletteFade, &gBattleAnimParticleDescriptors[0x4F], 0, 4, 0xE, 9, 0x1A, 0);
    BattleAnim_SpawnOwnerModelTintRampDetach(3, 0xA, 0, 0xFF, 0x40);
    BattleAnim_SpawnOwnerModelTintRampDetach(0xA, 0xA, 0xFF, 0xE6, 5);
    BattleAnim_SpawnOwnerModelTintPaletteApproachInactiveAlt(0x10, 0xA, 0x19, 0x10, 0xDC);
    BattleAnim_SpawnOwnerModelTintPaletteApproachInactiveAlt(0x18, 0x19, 0xB, 0x10, 0xD2);
    BattleAnim_SpawnOwnerModelTintPaletteApproachInactiveAlt(0x28, 0xB, 0x10, 0x10, 0xC8);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x30, 0x10, 0xC8, 0xB4, 6);
}

void func_84348C6C(UNUSED s32 arg0, UNUSED s32 arg1) {
}

void func_84348C78(UNUSED s32 arg0, UNUSED s32 arg1) {
}

void BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);

    arg0->unk_14 = BattleAnim_AllocParticleDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        if (sp26 == 0) {
            BattleAnim_InitModel(arg0->unk_14, 0x55);
        } else {
            BattleAnim_InitModel(arg0->unk_14, 0x63);
        }
        BattleAnim_BindModelAnim(arg0->unk_14, 0x56);
        Particle_SetFlags(arg0, 0x200);
        Particle_FieldCA_SetU8_0BECC(arg0, 7);
        Particle_SetScale(arg0, 1.0f);
        ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x24);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle(Particle* arg0) {
    s16 sp26 = Particle_FieldCF_GetS16_0C058(arg0);
    s32 sp20 = 0;
    f32 var_fv0;

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle_InitParticle(arg0);
            break;

        case 2:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0xE);
            Particle_PrimG_Approach_0BB14(arg0, 0xFF, 7);
            Particle_PrimB_Approach_0BB44(arg0, 0xFF, 0x13);
            Particle_EnvG_Approach_0BBF0(arg0, 0xFF, 0x13);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0xFF, 0x13);
            break;

        case 3:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0x10);
            Particle_PrimB_Approach_0BB44(arg0, 0, 0x11);
            Particle_EnvG_Approach_0BBF0(arg0, 0, 0x11);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x11);
            break;

        case 4:
            if (ModelAnim_IsFinished(arg0->unk_14) != 0) {
                Particle_MarkInactive(arg0);
            }
            break;
    }

    if (Particle_IsRunning(arg0) != 0) {
        if (BattleAnim_GetOwnerSpecies(arg0->unk_10) == 0x5F) {
            sp20 = 1;
        } else if (BattleAnim_GetOwnerSpecies(arg0->unk_10) == 0x82) {
            sp20 = 1;
        }

        if (sp26 == 0) {
            if (sp20 != 0) {
                var_fv0 = 120.0f;
            } else {
                var_fv0 = 170.0f;
            }
            BattleAnim_GetPointAlongCameraRay(&arg0->unk_50, var_fv0);
        } else {
            if (sp20 != 0) {
                var_fv0 = 90.0f;
            } else {
                var_fv0 = 140.0f;
            }
            BattleAnim_GetPointAlongCameraRay(&arg0->unk_50, var_fv0);
        }
    }
}

void func_84348F24(Gfx* arg0, s32 arg1, u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, temp_v0->env_r, temp_v0->env_g, temp_v0->env_b, 0);

    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0, arg1, 0x20, 5, 0, 0, 0, 0, 0, 0, 0, 0);

    gSPEndDisplayList(arg0++);
}

void func_84349010(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_84348F24(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84349058(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle, &gDefaultParticleDescriptor, 0, 1, 0x14, 0, 0, 0);
}

void func_843490A8(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle, &gDefaultParticleDescriptor, 0, 1, 0x14, 0, 0, 0);
}

void func_84349108(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects71And74And111SpecialModelColorCycle, &gDefaultParticleDescriptor, 0, 1, 0x14, 0, 1, 0);
}

void func_8434915C(void) {
    BattleAnim_EndEffects41And83Descriptor34BurstSequence();
}

void func_8434917C(void) {
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xC, 0, 0xFF, 0x40);
    BattleAnim_EndEffects41And83Descriptor34BurstSequence();
    BattleAnim_SpawnOwnerModelTintRampDetach(0x30, 0xC, 0xFF, 0, 2);
}

void func_843491D4(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    BattleAnim_GetOwnerContextParticle(D_8006F09C);
    arg0 = BattleAnim_BuildAnimatedTileDisplayList(arg0, arg1, 0x20, 5, -4, -4, 0xD, 6, 4, 4, 0xF, 1);

    gSPEndDisplayList(arg0++);
}

void func_84349264(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_843491D4(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_843492AC(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    BattleAnim_GetOwnerContextParticle(D_8006F09C);
    arg0 = BattleAnim_BuildAnimatedTileDisplayList(arg0, arg1, 0x20, 5, 1, -1, 0xE, 0xE, -1, 1, 2, 2);

    gSPEndDisplayList(arg0++);
}

void func_8434933C(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_843492AC(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84349384(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 2, 0, 0x28, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 8, 0xC, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 8, 9, 0, 0x22, 6);
}

f32 BattleAnim_GetSpeciesScaleAdjust(Particle* arg0) {
    f32 sp1C = 1.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x3B:
            sp1C = 1.45f;
            break;

        case 0x5F:
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 20.0f);
            sp1C = 0.9f;
            break;

        case 0x82:
            sp1C = 0.9f;
            break;
    }
    return sp1C;
}

void BattleAnim_CallbackStartEffect69ModelPhaseWait(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 0);
            break;

        case 2:
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void func_84349504(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect69ModelPhaseWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x29, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(5, 2, 0xA, BattleAnim_CallbackStartEffect69EndEffect78Descriptor4AFallFade, &gBattleAnimParticleDescriptors[0x4A], 0, 2, 0xA, 0, 0x44, 9);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xA, 5, 6, BattleAnim_CallbackStartEffect69EndEffect78Descriptor30YThresholdFall, &gBattleAnimParticleDescriptors[0x30], 0, 3, 0xA, 0, 0x44, 0xB);
}

void BattleAnim_ApplySpeciesXZOffsetVariantB(Particle* arg0) {
    if (BattleAnim_GetOwnerSpecies(arg0->unk_10) == 0x5F) {
        Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 20.0f);
    }
}

void func_84349628(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x16, 0);
}

void func_8434967C(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x1D, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 3, 3, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0xE, 9, 0, 0xF);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 1, 4, BattleAnim_CallbackStartEffect69EndEffect78Descriptor4AFallFade, &gBattleAnimParticleDescriptors[0x4A], 0, 8, 0x1B, 0, 0x44, 0xA);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackStartEffect69EndEffect78Descriptor30YThresholdFall, &gBattleAnimParticleDescriptors[0x30], 0, 0xC, 0x1B, 0, 0x44, 0xB);
}

void BattleAnim_ApplySpeciesYOffsetVariantA(Particle* arg0) {
    f32 sp1C = 0.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x57:
            sp1C = -20.0f;
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 10.0f);
            break;

        case 0x5F:
            sp1C = -20.0f;
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 15.0f);
            break;
    }
    Particle_Field38_AddYScaled_08E90(arg0, sp1C);
}

void func_84349830(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xB, 0, 0, 0);
    BattleAnim_SpawnCategory19MarkerSlot(0x28, 1);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 4, 3, BattleAnim_CallbackSharedDescriptors42And44ScaleFall, &gBattleAnimParticleDescriptors[0x42], 0, 4, 0xB, 0, 0x17, 0xA);
}

void func_843498D8(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 4, 0, 1, 0);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0x1D, 2, 0x20, 0x14);
}

void BattleAnim_ApplySpeciesYOffsetVariantB(Particle* arg0) {
    f32 sp1C = 0.0f;
    f32 sp18 = 0.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x3B:
            sp1C = 30.0f;
            break;

        case 0x4F:
            sp18 = 10.0f;
            break;

        case 0x66:
            sp1C = 15.0f;
            break;
    }

    if (sp18 != 0.0f) {
        Particle_Field38_AddXZFromField94Y_08ED0(arg0, sp18);
    }

    if (sp1C != 0.0f) {
        Particle_Field38_SetYScaled_08CA0(arg0, sp1C);
    }
}

void func_84349A14(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xB, gBattleAnimCurrentAnchor, 2, 0);
}

void BattleAnim_CallbackStartEffect17ModelAnimFinish_InitParticle(Particle* arg0) {
    Particle_FieldCD_GetU8_0C048(arg0);
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x71, 0x72);
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        Particle_FieldA6_SetS16_0BCA8(arg0, 0x1E);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffect17ModelAnimFinish(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect17ModelAnimFinish_InitParticle(arg0);
            break;

        case 2:
            if (ModelAnim_IsFinished(arg0->unk_14) != 0) {
                Particle_MarkInactive(arg0);
            }
            break;
    }
}

void BattleAnim_CallbackEndEffect7ModelScaleAlphaFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldCD_GetU8_0C048(arg0);

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        switch (sp26) {
            case 0:
                Particle_SetPosition(arg0, 8.0f, 0.0f, -10.0f);
                break;

            case 1:
                Particle_SetPosition(arg0, -10.0f, 0.0f, 12.0f);
                break;

            case 2:
                Particle_SetPosition(arg0, 0.0f, 0.0f, -2.0f);
                break;

            case 3:
                Particle_SetPosition(arg0, 15.0f, 0.0f, 3.0f);
                break;
        }

        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x6E, 0x6F);
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        Particle_FieldA6_SetS16_0BCA8(arg0, 0x1E);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackEndEffect7ModelScaleAlphaFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackEndEffect7ModelScaleAlphaFade_InitParticle(arg0);
            break;

        case 2:
            Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0);
            break;

        case 3:
            Particle_Field1C_ApproachAndStepState_0B9D0(arg0, 0.0f, 0.05f);
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x10);
            break;

        case 4:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void func_84349D10(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    UNUSED s32 pad[2];
    s16 sp2E = Particle_FieldCF_GetS16_0C058(BattleAnim_GetOwnerContextParticle(D_8006F09C));
    u8 sp2D;
    u8 sp2C;
    u8 sp2B;
    u8 sp2A;
    u8 sp29;
    u8 sp28;

    gDPLoadTextureBlock(arg0++, arg1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, 5, 0, 0x20, 0x20);

    switch (sp2E) {
        case 0:
            sp2D = 0x96;
            sp2C = 0x32;
            sp2B = 0x32;
            sp2A = 0;
            sp29 = 0;
            sp28 = 0;
            break;

        case 1:
            sp2D = 0x78;
            sp2C = 0x96;
            sp2B = 0;
            sp2A = 0x64;
            sp29 = 0x78;
            sp28 = 0;
            break;

        case 2:
            sp2D = 0x46;
            sp2C = 0;
            sp2B = 0x78;
            sp2A = 0x64;
            sp29 = 0;
            sp28 = 0x96;
            break;

        case 3:
            sp2D = 0x64;
            sp2C = 0x96;
            sp2B = 0x96;
            sp2A = 0x64;
            sp29 = 0x96;
            sp28 = 0x96;
            break;
    }

    gDPSetPrimColor(arg0++, 0, 0xFF, sp2D, sp2C, sp2B, 255);
    gDPSetEnvColor(arg0++, sp2A, sp29, sp28, 255);

    gSPEndDisplayList(arg0++);
}

void func_84349F80(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_84349D10(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84349FC8(Gfx* arg0, UNUSED arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    DisplayObject* sp24 = D_8006F09C;
    s32 tmp = BattleAnim_GetOwnerContextParticle(D_8006F09C);
    UNUSED u8 sp1F;
    UNUSED u8 sp1E;
    u8 sp1D;
    u8 sp1C;
    u8 sp1B;
    u8 sp1A;
    u8 sp19;
    u8 sp18;

    switch (Particle_FieldCF_GetS16_0C058(tmp)) {
        case 0:
            sp1D = 0xFF;
            sp1C = 0x96;
            sp1B = 0x32;
            sp1A = 0;
            sp19 = 0;
            sp18 = 0;
            break;

        case 1:
            sp1D = 0xFF;
            sp1C = 0xFF;
            sp1B = 0xFF;
            sp1A = 0x96;
            sp19 = 0xB4;
            sp18 = 0;
            break;

        case 2:
            sp1D = 0xFF;
            sp1C = 0xFF;
            sp1B = 0xFF;
            sp1A = 0x96;
            sp19 = 0;
            sp18 = 0xC8;
            break;

        case 3:
            sp1D = 0x64;
            sp1C = 0xFF;
            sp1B = 0xFF;
            sp1A = 0xC8;
            sp19 = 0xFF;
            sp18 = 0xFF;
            break;
    }

    gDPSetCombineLERP(arg0++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED,
                      0, 0, 0, COMBINED);
    gDPSetPrimColor(arg0++, 0, 0xFF, sp1D, sp1C, sp1B, sp24->lodFraction);
    gDPSetEnvColor(arg0++, sp1A, sp19, sp18, 255);

    gSPEndDisplayList(arg0++);
}

void func_8434A18C(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_84349FC8(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

s16 BattleAnim_GetMoveKeyedModelVariantIndex(void) {
    s16 sp1E;

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x7C:
            sp1E = 0;
            break;

        case 0x33:
            sp1E = 1;
            break;

        case 0x5C:
            sp1E = 2;
            break;

        case 0x7A:
            sp1E = 3;
            break;
    }

    return sp1E;
}

s16 BattleAnim_GetMoveKeyedTintRampParam(void) {
    s16 sp1E;

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x7C:
            sp1E = 0x12;
            break;

        case 0x33:
            sp1E = 0x2B;
            break;

        case 0x5C:
            sp1E = 0x3E;
            break;

        case 0x7A:
            sp1E = 0x39;
            break;
    }

    return sp1E;
}

s16 BattleAnim_GetMoveKeyedTrailVariantParam(void) {
    s16 sp1E;

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x7C:
            sp1E = 8;
            break;

        case 0x33:
            sp1E = 0x33;
            break;

        case 0x5C:
            sp1E = 0x33;
            break;

        case 0x7A:
            sp1E = 0x33;
            break;
    }

    return sp1E;
}

void BattleAnim_StartEffect17ModelAnimFinish(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect17ModelAnimFinish, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, BattleAnim_GetMoveKeyedModelVariantIndex(), 0);
}

void func_8434A384(void) {
    s16 sp4E;
    s16 sp44;
    s16 sp4A;

    sp4E = BattleAnim_GetMoveKeyedModelVariantIndex();
    sp44 = BattleAnim_GetMoveKeyedTintRampParam();
    sp4A = BattleAnim_GetMoveKeyedTrailVariantParam();

    BattleAnim_SpawnOwnerModelTintRampDetach(4, sp44, 0, 0xFF, 0x10);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect7ModelScaleAlphaFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, sp4E, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackEndEffect7ModelScaleAlphaFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 1, sp4E, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackEndEffect7ModelScaleAlphaFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 2, sp4E, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackEndEffect7ModelScaleAlphaFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 3, sp4E, 0);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x28, sp44, 0xFF, 0, 0x10);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(6, 4, 0xA, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 9, 0, sp4A, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(7, 8, 5, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 9, 0, sp4A, 0);
}

f32 BattleAnim_GetSpeciesScaleAndApplyYOffset(Particle* arg0) {
    f32 sp1C = 0.5f;
    f32 sp18 = 0.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x57:
            sp18 = -15.0f;
            break;

        case 0x5F:
            sp1C = 0.3f;
            break;

        case 0x82:
            sp18 = 10.0f;
            break;

        case 0x83:
            sp1C = 0.4f;
            sp18 = 7.0f;
            break;
    }

    Particle_SetPrimAlpha(arg0, 0);
    Particle_Field38_AddYScaled_08E90(arg0, sp18 + 5.0f);
    return sp1C;
}

void func_8434A654(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    BattleAnim_GetOwnerContextParticle(D_8006F09C);
    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0, arg1, 0x20, 5, 0, 0, 1, 1, 0, -3, 1, 1);

    gSPEndDisplayList(arg0++);
}

void func_8434A6D8(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_8434A654(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434A720(Gfx* arg0, UNUSED arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, 255, 0, 0, temp_v0->prim_a);
    gSPEndDisplayList(arg0++);
}

void func_8434A794(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_8434A720(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434A7DC(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects83And103ModelAlphaFadeIn, &gDefaultParticleDescriptor, 0x64, 1, 0xB, 0, 3, 6);
}

void BattleAnim_StartEffect39Descriptor26ModelAnimWaitSequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x26, 0);
}

void func_8434A898(void) {
    UNUSED s16 pad;
    s16 sp34;

    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x59:
            sp34 = 0x10;
            break;

        case 0x5A:
            sp34 = 0;
            break;
    }

    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, sp34);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x26, 0);
}

void func_8434A930(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(6, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 4, 2);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 5, 0);
    BattleAnim_EndEffect58Descriptor4AAnd51Sequence();
}

void func_8434A9CC(void) {
    func_8434A930();
}

void func_8434A9EC(void) {
    BattleAnim_SpawnOwnerModelTintRampDetach(4, 0xA, 0, 0xFF, 0x40);
    BattleAnim_SpawnOwnerModelAlphaFadeZeroStartPreset(8);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0, 1, 0xE, 0, 6, 0);
    BattleAnim_StartEffects87And88Descriptor3DVerticalFadeSequence();
}

void func_8434AA6C(void) {
    BattleAnim_SpawnOwnerModelTintRampDetach(6, 0xA, 0, 0xFF, 0x40);
    BattleAnim_SpawnOwnerModelAlphaFadeZeroStartPreset(0xA);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 7, 0);
    BattleAnim_StartEffects87And88Descriptor3DVerticalFadeSequence();
}

void func_8434AAEC(Gfx* arg0, u8 arg1, UNUSED u16 arg2) {
    u8* var_a3;
    s32 idx = arg1 * 0xB48;

    if (BattleScene_GetParticipantSideIndex(BattleAnim_GetOwnerContextParticle(D_8006F09C)->unk_10) == 0) {
        var_a3 = D_8438E778 + idx;
    } else {
        var_a3 = D_8438E77C + idx;
    }

    gDPLoadTextureTile(arg0++, var_a3, G_IM_FMT_RGBA, G_IM_SIZ_16b, 76, 0, 0, 0, 75, 18, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPEndDisplayList(arg0++);
}

void func_8434AC44(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_8434AAEC(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434AC8C(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 6, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 0, 8, 0);
}

void func_8434ACEC(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 0x10);
    func_8434AC8C();
}

void func_8434AD1C(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnim, &gDefaultParticleDescriptor, 0, 1, 0xE, 0, 9, 0);
}

void func_8434AD70(void) {
    s32 var_s0 = 0;

    if (BattleAnim_IsCurrentOwnerSpecies(0x5C) != 0) {
        var_s0 = 1;
    } else if (BattleAnim_IsCurrentOwnerSpecies(0x5D) != 0) {
        var_s0 = 1;
    } else if (BattleAnim_IsCurrentOwnerSpecies(0x5E) != 0) {
        var_s0 = 1;
    } else if (BattleAnim_IsCurrentOwnerSpecies(0x5A) != 0) {
        var_s0 = 1;
    } else if (BattleAnim_IsCurrentOwnerSpecies(0x6C) != 0) {
        var_s0 = 1;
    } else if (BattleAnim_IsCurrentOwnerSpecies(0x2A) != 0) {
        var_s0 = 1;
    }

    if (var_s0 == 0) {
        BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0x10, gBattleAnimCurrentAnchor, 0xA, 0);
    }
}

f32 BattleAnim_GetSpeciesScaleAndOffset(Particle* arg0) {
    f32 sp1C = 0.0f;
    f32 sp18 = 1.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x24:
            sp18 = 1.2f;
            sp1C = 10.0f;
            break;

        case 0x34:
            sp18 = 0.8f;
            break;

        case 0x36:
            sp1C = 15.0f;
            break;

        case 0x3B:
            sp1C = 30.0f;
            sp18 = 0.8f;
            break;

        case 0x5A:
            sp1C = 10.0f;
            break;

        case 0x5F:
            Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(arg0, 15.0f);
            sp1C = 10.0f;
            sp18 = 0.5f;
            break;

        case 0x66:
            sp1C = 15.0f;
            sp18 = 0.8f;
            break;

        case 0x7D:
            sp1C = 8.0f;
            break;

        case 0x7E:
            sp1C = 15.0f;
            sp18 = 0.8f;
            break;

        case 0x82:
            sp1C = 10.0f;
            sp18 = 0.4f;
            break;

        case 0x83:
            sp1C = 10.0f;
            sp18 = 0.4f;
            break;
    }

    Particle_Field38_AddYScaled_08E90(arg0, sp1C);
    return sp18;
}

void func_8434B000(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xB, 0, 0xB, 0);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0x2A, 0x10, 0x17);
}

void func_8434B064(void) {
    BattleAnim_SpawnOwnerModelTintPulseDetach(0, 1, 0x18, 0xFF, 0, 8);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0xC, 0);
}

void BattleAnim_ApplySpeciesYOffsetVariantC(Particle* arg0) {
    f32 sp1C = 0.0f;

    switch (BattleAnim_GetOwnerSpecies(arg0->unk_10)) {
        case 0x34:
            sp1C = 12.0f;
            break;

        case 0x36:
            sp1C = 20.0f;
            break;
    }
    Particle_Field38_AddYScaled_08E90(arg0, sp1C);
}

void BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldCD_GetU8_0C048(arg0);

    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);

    if (arg0->unk_14 != NULL) {
        if ((sp26 == 0) || (sp26 == 1)) {
            BattleAnim_InitModel(arg0->unk_14, 0x8C);
        } else if ((sp26 == 2) || (sp26 == 3)) {
            BattleAnim_InitModel(arg0->unk_14, 0x8E);
        } else {
            BattleAnim_InitModel(arg0->unk_14, 0x8D);
        }

        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        BattleAnim_ApplySpeciesYOffsetVariantC(arg0);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn(Particle* arg0) {
    u32 temp_v0 = Particle_FieldCD_GetU8_0C048(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn_InitParticle(arg0);
            break;

        case 2:
            if ((temp_v0 == 0) || ((s32)temp_v0 == 1)) {
                Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0x80, 8);
            } else if (temp_v0 == 3) {
                Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0xFF, 0xFF);
            } else {
                Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0xFF, 4);
            }
            break;
    }
}

void func_8434B2B8(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    u8* a1;
    Particle* spC8;
    u8 var_t0;
    s16 spC4;
    s16 spC2;
    s16 spC0;
    s16 spBE;
    s16 var_a1;
    s16 var_a2;
    s16 var_a3;
    s16 var_s1;
    UNUSED s16 pad2;
    s16 spB2;
    s16 spB0;
    s16 spAE;
    s16 spAC;
    u16 temp_v0_2;
    s16 var_t2;
    s16 var_t1;

    spC8 = BattleAnim_GetOwnerContextParticle(D_8006F09C);
    temp_v0_2 = Particle_FieldCD_GetU8_0C048(spC8);
    var_s1 = 0x20;
    var_t1 = 5;
    var_t2 = 5;
    var_a3 = 0;
    var_a1 = 0;
    var_a2 = 0;
    var_t0 = spC8->prim_a;

    switch (temp_v0_2) {
        case 0:
            spC4 = -1;
            spC2 = -1;
            spC0 = 1;
            spBE = -1;
            spB2 = 0xF;
            spB0 = 0;
            spAE = 0xE;
            spAC = 0xF;
            break;

        case 1:
            spC4 = -1;
            spC2 = 1;
            spC0 = 1;
            spBE = 1;
            spB2 = 0xF;
            spB0 = 0;
            spAE = 0xE;
            spAC = 0xF;
            break;

        case 2:
            spC4 = -2;
            spC2 = 2;
            spC0 = 2;
            var_a3 = 0xFF;
            spBE = 3;
            spB2 = 0xC;
            spB0 = 1;
            spAE = 0xC;
            spAC = 0;
            break;

        case 3:
            spC4 = -2;
            spC2 = -2;
            spC0 = 2;
            var_a3 = 0xFF;
            spBE = -3;
            spB2 = 0xC;
            spB0 = 1;
            spAE = 0xC;
            spAC = 0;
            break;

        case 4:
            var_a2 = 0xFF;
            var_a1 = 0x9B;
            spC4 = 1;
            spC2 = 1;
            spC0 = -1;
            spBE = -1;
            spB2 = 0xC;
            spB0 = 1;
            spAE = 0xC;
            spAC = 0;

            break;

        case 5:
            spC0 = -0xA;
            spBE = -0xF;
            spC4 = 0;
            spC2 = 0;
            spB2 = 0xF;
            spB0 = 1;
            spAE = 0xF;
            spAC = 1;
            var_a2 = 0xFF;
            var_a1 = 0xFF;
            var_a3 = 0xFF;
            var_t0 = 0x32;
            break;

        case 6:
            spC4 = 2;
            spC2 = -1;
            spC0 = -2;
            spBE = -2;
            spB2 = 0xD;
            spB0 = 0xE;
            spAE = 0xC;
            spAC = 0xE;
            var_a2 = 0xFF;
            var_a1 = 0xFF;
            var_a3 = 0xFF;
            var_s1 = 0x40;
            var_t1 = 6;
            var_t2 = 6;
            break;

        case 7:
            spC4 = 1;
            spC2 = 1;
            spC0 = -1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0xF;
            spAE = 0xF;
            spAC = 0xE;
            var_a2 = 0xFF;
            var_a3 = 0x80;
            break;

        case 8:
            spC4 = 1;
            spC2 = 1;
            spC0 = -1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0xF;
            spAE = 0xF;
            spAC = 0xE;
            var_a1 = 0xFF;
            var_a3 = 0xFF;
            break;

        case 9:
            spC4 = 1;
            spC2 = 1;
            spC0 = -1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0xF;
            spAE = 0xF;
            spAC = 0xE;
            var_a2 = 0x64;
            var_a1 = 0xFF;
            break;

        case 10:
            spC4 = -1;
            spC2 = -1;
            spC0 = 1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0;
            spAE = 0xC;
            spAC = 0xF;
            var_a2 = 0xC8;
            var_a1 = 0x64;
            break;

        case 11:
            spC4 = -1;
            spC2 = -1;
            spC0 = 1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0;
            spAE = 0xC;
            spAC = 0xF;
            var_a1 = 0xFF;
            var_a3 = 0xFF;
            break;

        case 12:
            spC4 = -1;
            spC2 = -1;
            spC0 = 1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0;
            spAE = 0xC;
            spAC = 0xF;
            var_a2 = 0xC8;
            var_a1 = 0xFF;
            break;

        case 13:
            spC4 = -1;
            spC2 = -1;
            spC0 = 1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0;
            spAE = 0xC;
            spAC = 0xF;
            var_a2 = 0xFF;
            break;
    }

    a1 = arg1;

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, 0x80, var_a2, var_a1, var_a3, var_t0);

    gDPLoadTextureTile_4b(arg0++, arg1, G_IM_FMT_I, var_s1, var_s1, 0, 0, var_s1 - 1, var_s1 - 1, 0,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, var_t2, var_t1, spB2, spB0);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, spC4, spC2, var_s1, var_s1);

    gDPLoadMultiTile_4b(arg0++, a1, 0x0100, 1, G_IM_FMT_I, var_s1, var_s1, 0, 0, var_s1 - 1, var_s1 - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, var_t2, var_t1, spAE, spAC);

    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, spC0, spBE, var_s1, var_s1);

    gSPEndDisplayList(arg0++);
}

void func_8434BA28(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_8434B2B8(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434BA70(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn, &gDefaultParticleDescriptor, 0, 1, 0xC, 0, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWaitCleanup, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackInitModelAnimWaitCleanup, &gDefaultParticleDescriptor, 0, 1, 9, 1, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackInitModelAnimWaitCleanup, &gDefaultParticleDescriptor, 0, 1, 9, 2, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackInitModelAnimWaitCleanup, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackInitModelAnimWaitCleanup, &gDefaultParticleDescriptor, 0, 1, 9, 1, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x14, BattleAnim_CallbackInitModelAnimWaitCleanup, &gDefaultParticleDescriptor, 0, 1, 9, 2, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x18, BattleAnim_CallbackInitModelAnimWaitCleanup, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x1C, BattleAnim_CallbackInitModelAnimWaitCleanup, &gDefaultParticleDescriptor, 0, 1, 9, 1, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x20, BattleAnim_CallbackInitModelAnimWaitCleanup, &gDefaultParticleDescriptor, 0, 1, 9, 2, 0xD, 0);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 0x35);
}

void func_8434BCD4(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn, &gDefaultParticleDescriptor, 0, 1, 0xC, 1, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 1, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(8, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 2, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 1, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x14, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 2, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x18, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x1C, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 1, 0xD, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x20, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 2, 0xD, 0);
}

void func_8434BF2C(void) {
    switch (BattleAnim_GetQueuedMoveId()) {
        case 0x8D:
            BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 6);
            BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimMode2Update, &gDefaultParticleDescriptor, 0x80, 1, 0xC, 0xD, 0x1A, 0x20);
            break;

        case 0x47:
            BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 0x3A);
            BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimMode2Update, &gDefaultParticleDescriptor, 0x80, 1, 0xC, 0xB, 0x1A, 0x20);
            break;

        case 0x48:
            BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 0x21);
            BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimMode2Update, &gDefaultParticleDescriptor, 0x80, 1, 0xC, 0xC, 0x1A, 0x20);
            break;
    }
}

void func_8434C070(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn, &gDefaultParticleDescriptor, 0, 1, 0xC, 4, 0, 0);
}

void func_8434C0C4(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn, &gDefaultParticleDescriptor, 0, 1, 0xC, 2, 0, 0);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 0);
    BattleAnim_AddSpawnDelay(0x40);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0, 2, 0x10, 0xA);
}

void func_8434C144(void) {
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0, 2, 0x10, 0xA);
    BattleAnim_SpawnOwnerModelTintRampDetach(4, 0xA, 0xFF, 0, 8);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects95To97EndEffects62And63ModelFadeIn, &gDefaultParticleDescriptor, 0, 1, 0xC, 3, 0, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 4, 4, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 3, 9, 0, 0x18, 0xD);
}

void BattleAnim_CallbackStartEffects21And93ModelAlphaAnchorFollow_InitParticle(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x42, 0xC2);
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x23);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_FieldAE_SetS16_0BF4C(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffects21And93ModelAlphaAnchorFollow(Particle* arg0) {
    s16 sp26;

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects21And93ModelAlphaAnchorFollow_InitParticle(arg0);
            break;

        case 2:
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0xFF, 8);
            Particle_FieldAE_Approach_0BF60(arg0, 0xC8, 6);
            break;
    }

    BattleAnim_GetCameraEyeYaw(&sp26);
    Particle_Field94_SetY_0A2B8(arg0, sp26);
}

void BattleAnim_CallbackEndEffect60Model42AnimC2RotationYFollow_InitParticle(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModelWithAnim(arg0->unk_14, 0x42, 0xC2);
        BattleAnim_SetModelAnimFrame(arg0->unk_14, 0x28);
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x23);
        Particle_FieldAE_SetS16_0BF4C(arg0, 0xFF);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackEndEffect60Model42AnimC2RotationYFollow(Particle* arg0) {
    s16 sp1E;

    if (arg0->unk_B2 == 1) {
        BattleAnim_CallbackEndEffect60Model42AnimC2RotationYFollow_InitParticle(arg0);
    }
    BattleAnim_GetCameraEyeYaw(&sp1E);
    Particle_Field94_SetY_0A2B8(arg0, sp1E);
}

void func_8434C3F0(Gfx* arg0, u8 arg1, UNUSED u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    switch (arg1) {
        case 0:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->prim_a);
            break;

        case 1:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->unk_AE);
            break;
    }

    gDPSetEnvColor(arg0++, temp_v0->env_r, temp_v0->env_g, temp_v0->env_b, 0);
    gDPSetCombineLERP(arg0++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED,
                      0, 0, 0, COMBINED);

    gSPEndDisplayList(arg0++);
}

void func_8434C548(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_8434C3F0(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434C590(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 3);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects21And93ModelAlphaAnchorFollow, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
}

void func_8434C5F0(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0x10, 0x10, 0xA);
}

void func_8434C618(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects21And93ModelAlphaAnchorFollow, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 3);
    BattleAnim_SpawnOwnerModelTintRampDetach(8, 0xA, 0, 0xFF, 0x40);
    BattleAnim_SpawnDescriptor25AlphaFadeInHoldFullAlpha(0xC, 5, 0x10, 0xA);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 4, 9, 0, 0x18, 0xD);
    BattleAnim_AddSpawnDelay(0x21);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0, 0, 0x10, 0xA);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xA, 0xFF, 0, 0x10);
}

void func_8434C720(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect60Model42AnimC2RotationYFollow, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0, 0);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0, 0, 0x10, 0xA);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 3);
    BattleAnim_SpawnOwnerModelTintRampDetach(8, 0xA, 0, 0xFF, 0x40);
    BattleAnim_CreateEffectSlotForCurrentOwner(0xC, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 4, 9, 0, 0x18, 0xD);
    BattleAnim_AddSpawnDelay(0x21);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xA, 0xFF, 0, 0x10);
}

void func_8434C814(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    Particle* temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, 0x80, 100, 200, 255, temp_v0->prim_a);

    gDPLoadTextureTile_4b(arg0++, arg1, G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 14, 15);

    ParticleGfx_SetPartiallyAnimatedTileSize(arg0++, -0xB, -8, 0x20, 0x20);

    gDPLoadMultiTile_4b(arg0++, arg1, 0x0100, 1, G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 13, 15);

    ParticleGfx_SetPartiallyAnimatedAuxTileSize(arg0++, 0x35, -4, 0x20, 0x20);

    gSPEndDisplayList(arg0++);
}

void func_8434CA48(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_8434C814(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

f32 BattleAnim_GetSpeciesScaleAdjustSmall(Particle* arg0) {
    f32 sp1C = 2.5f;

    if (BattleAnim_GetOwnerSpecies(arg0->unk_10) == 0x5F) {
        sp1C = 1.75f;
    }
    return sp1C;
}

void func_8434CAD8(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimMode2Update, &gDefaultParticleDescriptor, 0xFF, 1, 0xC, 0, 0xE, 8);
    BattleAnim_AddSpawnDelay(4);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x10, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 2, 0xE, 0, 0x4E, 3);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x10, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x19], 0, 2, 0xE, 0, 0x4D, 3);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x10, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0xE], 0, 2, 0xE, 0, 0x4D, 3);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 5, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0xA], 0, 2, 0xE, 0, 0x4D, 4);
}

void func_8434CC68(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimMode2Update, &gDefaultParticleDescriptor, 0xFF, 1, 0xC, 0, 0xF, 0x40);
    BattleAnim_SpawnOwnerModelTintPaletteApproachInactive(4, 0xA, 0x35, 0xC, 0xFF);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor04GrowFade, &gBattleAnimParticleDescriptors[4], 0, 1, 0x10, gBattleAnimCurrentAnchor, 0x35, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 5, 3, BattleAnim_CallbackSharedDescriptor19AnimatedFadeMotion, &gBattleAnimParticleDescriptors[0x19], 0, 8, 0x10, gBattleAnimCurrentAnchor, 0x4D, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0xA, 1, 3, BattleAnim_CallbackSharedDescriptor19DelayedAnimatedGrowFade, &gBattleAnimParticleDescriptors[0x19], 0, 8, 0x11, gBattleAnimCurrentAnchor, 0x4D, 0);
    BattleAnim_AddSpawnDelay(0x10);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 5, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0xA], 0, 1, 0xE, 0, 0x4D, 4);
}

void func_8434CE14(void) {
    BattleAnim_AddSpawnDelay(0x41);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x20, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x4A], 0, 2, 7, 0, 0x33, 8);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x20, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x19], 0, 2, 7, 0, 0xC, 8);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 0x20, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0xE], 0, 2, 7, 0, 0xC, 8);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 8, 0xA, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0xA], 0, 2, 7, 0, 0xC, 4);
}

void func_8434CF64(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 4, BattleAnim_CallbackEndEffect16MultiDescriptorAnimatedFallFade, &gBattleAnimParticleDescriptors[0x4A], 0, 3, 0xE, 0, 0x33, 0xC);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 4, BattleAnim_CallbackEndEffect16MultiDescriptorAnimatedFallFade, &gBattleAnimParticleDescriptors[0x19], 0, 3, 0xE, 0, 0xC, 0xC);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 4, BattleAnim_CallbackEndEffect16MultiDescriptorAnimatedFallFade, &gBattleAnimParticleDescriptors[0xE], 0, 3, 0xE, 0, 0xC, 0xC);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 4, 4, BattleAnim_CallbackEndEffect16MultiDescriptorAnimatedFallFade, &gBattleAnimParticleDescriptors[0xA], 0, 3, 0xE, 0, 0xC, 4);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 0xC, BattleAnim_CallbackEndEffect16Descriptor45DelayedRotatingMotion, &gBattleAnimParticleDescriptors[0x45], 0, 4, 0x11, 7, 0x33, 0);
}

void func_8434D0F8(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0x13, gBattleAnimCurrentAnchor, 0x10, 0);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0x22, 0, 0x10, 0xA);
}

void BattleAnim_CallbackStartEffect101EndEffect65Descriptor4ABurstChild_InitParticle(Particle* arg0) {
    Particle_Field1C_SetScaled_0B938(arg0, 0.2f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, 0x33);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect101EndEffect65Descriptor4ABurstChild(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect101EndEffect65Descriptor4ABurstChild_InitParticle(arg0);
            break;

        case 2:
            Particle_AnimateFramesForwardAndAdvanceLifecycle(arg0, 0, 7, 1, 2, 0);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0x20, 0x40);
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }
    Particle_Field1C_Approach_0B98C(arg0, 0.5f, 0.1f);
}

void BattleAnim_CallbackStartEffect101ModelBurstEmitter_InitParticle(Particle* arg0) {
    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.3f);
    Particle_Field94_AddVec_0A52C(arg0, -0x1000, 0, 0);
    Particle_FieldA0_SetY_0A414(arg0, BattleAnim_GetParticleAngleYToTertiaryOwner(arg0));
    Particle_Field9A_SetY_0A3D8(arg0, 0x80);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect101ModelBurstEmitter(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect101ModelBurstEmitter_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
                BattleAnim_InitModelWithAnim(arg0->unk_14, 0xA0, 0xA1);
                Particle_EnableRendering(arg0);
            }
            break;

        case 3:
            if (Particle_TickDelayAndAdvanceLifecycle(arg0, 0xA) != 0) {
                Particle_Field74_SetScaled_0AD8C(arg0, 8.0f);
                BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackStartEffect101EndEffect65Descriptor4ABurstChild, &gBattleAnimParticleDescriptors[0x4A], 1);
                BattleAnim_EmitParticleBurstWithMetadata(arg0, BattleAnim_CallbackStartEffect101Descriptor3DMetadataBurstChild, &gBattleAnimParticleDescriptors[0x3D], 0xC, 0x33, 0);
            }
            break;

        case 4:
            BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackStartEffect101EndEffect65Descriptor4ABurstChild, &gBattleAnimParticleDescriptors[0x4A], 1);
            Particle_ApproachRotationXTo(arg0, 0x1000, 0x200);
            Particle_ApproachRotationTargetY(arg0);
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0xF);
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_AddVelocityFromRotationTemplate1(arg0);
    }
}

void func_8434D448(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect101ModelBurstEmitter, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
}

void BattleAnim_CallbackMove140EndEffect65EmitDescriptor4A_InitParticle(Particle* arg0) {
    Particle_FieldAC_GetS16_0C038(arg0);
    Particle_Field1C_SetScaled_0B938(arg0, 0.4f);
    Particle_Field38_SetYScaled_08CA0(arg0, 15.0f);
    Particle_Field38_AddXZFromField94Y_08ED0(arg0, 50.0f);
    Particle_Field94_AddVec_0A52C(arg0, 0x800, -0x8000, 0);
    Particle_Field74_SetScaled_0AD8C(arg0, 8.0f);
    Particle_AdvanceLifecycle(arg0);
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    BattleAnim_InitModel(arg0->unk_14, 0xA0);
}

void BattleAnim_CallbackMove140EndEffect65EmitDescriptor4A(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackMove140EndEffect65EmitDescriptor4A_InitParticle(arg0);
            break;

        case 2:
            BattleAnim_EmitParticleBurst(arg0, BattleAnim_CallbackStartEffect101EndEffect65Descriptor4ABurstChild, &gBattleAnimParticleDescriptors[0x4A], 1);
            Particle_ApproachRotationXTo(arg0, 0x1000, 0x80);
            Particle_TickDelayAndAdvanceLifecycle(arg0, 7);
            break;

        case 3:
            Particle_DisableAndDetach(arg0);
            break;
    }

    if (Particle_IsRenderingEnabled(arg0) != 0) {
        Particle_AddVelocityFromRotationTemplate1(arg0);
    }
}

void func_8434D5EC(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackMove140EndEffect65EmitDescriptor4A, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(5, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(7, BattleAnim_CallbackSharedDescriptor3DAnimatedColorMotion, &gBattleAnimParticleDescriptors[0x3D], 0, 8, 0x11, 9, 0, 0);
}

void BattleAnim_CallbackStartEffect49EndEffect66ModelFadeIn_InitParticle(Particle* arg0) {
    arg0->unk_14 = BattleAnim_AllocOwnerDisplayContext(arg0);
    if (arg0->unk_14 != NULL) {
        BattleAnim_InitModel(arg0->unk_14, 0xA2);
        Particle_Field1C_SetScaled_0B938(arg0, 1.0f);
        Particle_SetPrimAlpha(arg0, 0);
        Particle_AdvanceLifecycle(arg0);
    } else {
        Particle_DisableAndDetach(arg0);
    }
}

void BattleAnim_CallbackStartEffect49EndEffect66ModelFadeIn(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect49EndEffect66ModelFadeIn_InitParticle(arg0);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0x80, 8);
            break;
    }
}

void func_8434D77C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    UNUSED s32 pad;
    Particle* sp48 = BattleAnim_GetOwnerContextParticle(D_8006F09C);
    UNUSED s16 pad2;
    s16 sp44;
    s16 sp42;

    switch (Particle_FieldCF_GetS16_0C058(sp48)) {
        case 0:
            sp44 = -5;
            sp42 = 3;
            break;

        case 1:
            sp44 = 5;
            sp42 = -3;
            break;
    }

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, 0x80, 55, 255, 255, sp48->prim_a);

    arg0 = BattleAnim_BuildAnimatedTileDisplayListFromStruct(arg0++, arg1, 0x20, 5, 1, sp44, 0xD, 0xC, -1, sp42, 0xB, 0xD);
    gSPEndDisplayList(arg0++);
}

void func_8434D890(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_8434D77C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434D8D8(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect49EndEffect66ModelFadeIn, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0, 0);
}

void func_8434D938(void) {
    BattleAnim_SpawnOwnerModelTintPulseDetach(0, 2, 0xA, 0xFF, 0, 0x10);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect49EndEffect66ModelFadeIn, &gDefaultParticleDescriptor, 0, 1, 9, 0, 1, 0);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 4, 4, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 3, 9, 0, 0x18, 0xD);
}

void BattleAnim_CallbackEndEffects73And74DefaultDescriptorFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 2);
            break;

        case 2:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, arg0->unk_A6, Particle_FieldCE_GetS32_0C040(arg0));
            break;

        case 3:
            Particle_TickDelayAndAdvanceLifecycle(arg0, 0x20);
            break;

        case 4:
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0xA);
            break;

        case 5:
            Particle_DisableAndDetach(arg0);
            break;
    }
}

void func_8434DA94(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 5, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimMode2Update, &gDefaultParticleDescriptor, 0xFF, 1, 0xC, 8, 0x18, 5);
    BattleAnim_SpawnOwnerModelTintPulseDetach(0x32, 1, 0xA, 0, 0xFF, 0x20);
    BattleAnim_SpawnDescriptor25AlphaFadeInHoldOut(0x32, 1, 0x20, 0xA, 0xFF);
}

void func_8434DB40(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 6, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimMode2Update, &gDefaultParticleDescriptor, 0xFF, 1, 0xC, 7, 0x17, 6);
    BattleAnim_SpawnDescriptor25AlphaFadeInHoldOut(0x32, 1, 0x20, 0xA, 0xFF);
    BattleAnim_SpawnOwnerModelTintPulseDetach(0x32, 1, 0xA, 0, 0xFF, 0x20);
}

void func_8434DBEC(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x40, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects73And74DefaultDescriptorFade, &gDefaultParticleDescriptor, 0xFF, 1, 0xC, 8, 0x18, 0x20);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 4, 4, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 3, 9, 0, 0x18, 0xD);
    BattleAnim_SpawnOwnerModelTintRampDetach(8, 0xA, 0, 0xFF, 0x40);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0, 0, 0x10, 0xA);
    BattleAnim_AddSpawnDelay(0x21);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xA, 0xFF, 0, 4);
    BattleAnim_SpawnGlobalTintColorFadeDetach(8, 4, 0xA);
}

void func_8434DD08(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x40, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffects73And74DefaultDescriptorFade, &gDefaultParticleDescriptor, 0xFF, 1, 0xC, 7, 0x17, 0x20);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(4, 4, 4, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 3, 9, 0, 0x18, 0xD);
    BattleAnim_SpawnOwnerModelTintRampDetach(8, 0xA, 0, 0xFF, 0x40);
    BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(0, 0, 0x10, 0xA);
    BattleAnim_AddSpawnDelay(0x21);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xA, 0xFF, 0, 4);
    BattleAnim_SpawnGlobalTintColorFadeDetach(8, 4, 0xA);
}

f32 BattleAnim_GetSpeciesScaleAdjustTiny(Particle* arg0) {
    f32 sp1C = 1.0f;

    if (BattleAnim_GetOwnerSpecies(arg0->unk_10) == 0x34) {
        sp1C = 1.75f;
    }
    return sp1C;
}

void BattleAnim_StartEffect3ModelTintAndVerticalFade(void) {
    s16 sp46 = 7;

    if (BattleAnim_IsCurrentOwnerSpecies(0x14) != 0) {
        sp46 = gBattleAnimCurrentAnchor;
    }
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x10, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimMode2Update, &gDefaultParticleDescriptor, 0x80, 1, 0xC, 0xA, 0x1A, 4);
    BattleAnim_SpawnOwnerModelTintPulseDetach(0, 1, 0xC, 0, 0xC8, 3);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x3C, 4, 0xE, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 0x11, sp46, 0x33, 7);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0x3D, 8, 7, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 0x11, sp46, 0x33, 7);
}

void BattleAnim_EndEffect85TintAndDescriptorMode2Sequence(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 6);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimMode2Update, &gDefaultParticleDescriptor, 0x80, 1, 0xC, 0xA, 0x1A, 0x20);
}

void func_8434E02C(void) {
    BattleAnim_SpawnDefaultDescriptorBurstEmitterSequence(0xE);
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 2, 0x10);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xC, 0, 0xC8, 4);
    BattleAnim_SpawnOwnerModelTintPaletteApproachInactive(0x32, 0xC, 0x19, 2, 0xC8);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x40, BattleAnim_CallbackStartEffect104DelayedSpiralFade, &gBattleAnimParticleDescriptors[0x4F], 0, 0x20, 7, 0, 0, 0);
}

void func_8434E0CC(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 6);
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0x14, 0, 0x80, 0x10);
    BattleAnim_SpawnOwnerModelAlphaFade(0, 0xFF, 0, 0x10);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects83And103ModelAlphaFadeIn, &gDefaultParticleDescriptor, 0xFF, 1, 9, gBattleAnimCurrentAnchor, 0x12, 0x20);
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 1, 0xC, BattleAnim_CallbackSharedAnimatedVerticalFade, &gBattleAnimParticleDescriptors[0x3D], 0, 1, 9, 0, 0x16, 5);
}

void func_8434E1B8(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0x13, 0);
    BattleAnim_SetSpawnDelay(4);
    BattleAnim_EndEffect25Descriptor13DelegateSequence();
}

void func_8434E21C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    Particle* temp_v0;
    UNUSED s32 pad;
    s16 var_t2;
    s16 tmp;
    s16 sp82;
    s16 sp80;
    s16 sp7E;
    s16 sp7C;
    s16 sp7A;
    s16 sp78;
    s16 sp76;
    s16 sp74;
    s16 var_s1;
    s16 var_t1;
    UNUSED s16 pad2;
    s16 var_t5;

    temp_v0 = BattleAnim_GetOwnerContextParticle(D_8006F09C);
    var_t1 = 0x96;
    var_t2 = 0xFF;
    var_s1 = 0x20;
    var_t5 = 5;
    tmp = arg1->unk_0A;

    switch (tmp) {
        case 1:
            sp82 = -5;
            sp80 = -0xF;
            sp7E = -0xA;
            sp7C = -0xA;
            sp7A = 0;
            sp78 = 1;
            sp76 = 0;
            sp74 = 1;
            break;

        case 2:
            sp82 = 5;
            sp80 = -0xF;
            sp7E = 0;
            sp7C = -0xA;
            sp7A = 0;
            sp78 = 0xF;
            sp76 = 0;
            sp74 = 0xF;
            break;

        case 3:
            sp82 = 5;
            sp80 = -0xF;
            sp7C = -0xA;
            sp7E = 0;
            sp7A = 1;
            sp78 = 1;
            sp76 = 1;
            sp74 = 1;
            break;

        case 4:
            sp82 = 5;
            sp80 = -0xF;
            sp7E = 0;
            sp7C = -0xA;
            sp7A = 0;
            sp78 = 0;
            sp76 = 0;
            sp74 = 0;
            break;

        case 5:
            sp82 = -5;
            sp80 = -0xA;
            sp7E = 0;
            sp7C = 0;
            sp7A = 1;
            sp78 = 0;
            sp76 = 0;
            sp74 = 0;
            var_t1 = 0x78;
            var_t2 = 0xC8;
            var_s1 = 0x40;
            var_t5 = 6;
            break;

        case 6:
            sp82 = 0;
            sp80 = -0xA;
            sp7E = 0;
            sp7C = 0;
            sp7A = 1;
            sp78 = 1;
            sp76 = 0;
            sp74 = 0;
            var_t1 = 0x78;
            var_t2 = 0xC8;
            var_s1 = 0x40;
            var_t5 = 6;
            break;
    }

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, var_t1, 255, var_t2, 0, temp_v0->prim_a);

    gDPLoadTextureTile_4b(arg0++, arg1->unk_00, G_IM_FMT_I, 32, 32, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, 5, 5, sp7A, sp78);

    ParticleGfx_SetAnimatedTileSizeOnList(arg0++, sp82, sp80, 0x20, 0x20);

    gDPLoadMultiTile_4b(arg0++, arg1->unk_04, 0x0100, 1, G_IM_FMT_I, var_s1, 0, 0, 0, var_s1 - 1, var_s1 - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, var_t5, var_t5, sp76, sp74);

    ParticleGfx_SetAnimatedAuxTileSizeOnList(arg0++, sp7E, sp7C, var_s1, var_s1);

    gSPEndDisplayList(arg0++);
}

void func_8434E6AC(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = Gfx_AllocDisplayList(sizeof(Gfx) * 30);
        func_8434E21C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void BattleAnim_EndEffect72Descriptor20ModelAnimWaitSequence(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0xE, 5, 0x14, 0);
}

void func_8434E74C(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimMode2Update, &gDefaultParticleDescriptor, 0xBE, 1, 9, 6, 0x15, 2);
    BattleAnim_SpawnOwnerModelTintRampDetach(8, 0xA, 0, 0xFF, 4);
    BattleAnim_StartEffect105TintDefaultBurstAndDescriptor3CSequence();
}

void BattleAnim_CallbackEndEffect76DefaultDescriptorModelFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 0);
            Particle_FieldA6_SetS16_0BCA8(arg0, 2);
            break;

        case 2:
            Particle_PrimG_Approach_0BB14(arg0, 0, 0x20);

            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC != NULL) {
                Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x20);
            }

            if (ModelAnim_IsFinished(arg0->unk_14) != 0) {
                Particle_MarkInactive(arg0);
            }
            break;
    }
}

void func_8434E870(void) {
    BattleAnim_SpawnOwnerModelTintRampDetach(4, 0xA, 0xFF, 0, 0x20);
    BattleAnim_CreateEffectSlotForCurrentOwner(4, BattleAnim_CallbackEndEffect76DefaultDescriptorModelFade, &gDefaultParticleDescriptor, 0, 1, 9, 0, 0x19, 0);
}

void func_8434E8E0(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0x1B, 1);
}

void func_8434E940(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0x1C, 1);
}

void func_8434E9A0(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 0x20, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0x1B, 1);
}

void func_8434EA10(void) {
    BattleAnim_SpawnOwnerModelTintRampDetach(0, 0xC, 0, 0xFF, 0x40);
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackInitModelAnimWait, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0x1C, 1);
    BattleAnim_SpawnOwnerModelTintRampDetach(0x30, 0xC, 0xFF, 0, 2);
}

void BattleAnim_CallbackStartEffects118And119ModelPalettePulse(Particle* arg0) {
    s16 sp26 = Particle_FieldCE_GetS32_0C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 0);
            if (sp26 == 1) {
                Particle_Field1C_SetScaled_0B938(arg0, 1.5f);
                Particle_Field38_AddXZFromField94YOffset180_08F38(arg0, 40.0f);
            }
            break;

        case 2:
            ParticleGfx_ApproachPrimEnvPalettePair(arg0, 0x33, 0x40);
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0xFF, 0x40);
            break;

        case 3:
            ParticleGfx_ApproachPrimEnvPalettePair(arg0, 0, 0x40);
            Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x40);
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void func_8434EBA0(void) {
    BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(0, 2, 3, BattleAnim_CallbackStartEffects118And119ModelPalettePulse, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0x20, 0);
}

void func_8434EC08(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects118And119ModelPalettePulse, &gDefaultParticleDescriptor, 0, 1, 0x11, gBattleAnimCurrentAnchor, 0x20, 1);
}

void BattleAnim_CallbackEndEffect79DefaultDescriptorPaletteFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_SelectParticleModelFrames(arg0, 0);
            break;

        case 2:
            ParticleGfx_ApproachPrimEnvPalettePair(arg0, 0x33, 0x24);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0xFF, 0x1D);
            if (ModelAnim_IsFinished(arg0->unk_14) != 0) {
                Particle_MarkInactive(arg0);
            }
            break;
    }
}

void func_8434ECF4(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackEndEffect79DefaultDescriptorPaletteFade, &gDefaultParticleDescriptor, 0, 1, 0xA, 0, 0x1F, 0);
}

void func_8434ED48(void) {
    BattleAnim_SpawnGlobalTintColorFadeDetach(0, 8, 0x22);
}

void BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldCE_GetS32_0C040(arg0);

    switch (sp26) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, 0.0f, 0.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 10.0f, 10.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 15.0f, -15.0f);
            break;
    }

    Particle_Field1C_SetScaled_0B938(arg0, 0.1f);
    Particle_SetScaleSpeed(arg0, 2.0f);
    Particle_SetScaleTarget(arg0, 0.0625f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 8);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xA);
            }
            break;

        case 3:
            Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);
            if (Particle_FieldA6_DecrementToZeroStep1_0BDAC(arg0) != 0) {
                Particle_PrimAlpha_ApproachAndStepState_0BC5C(arg0, 0, 0x10);
            }
            break;

        case 4:
            Particle_MarkInactive(arg0);
            break;
    }
}

void func_8434EF68(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade, &gBattleAnimParticleDescriptors[0x39], 8, 3, 2, 0, 0x45, 0);
}

void func_8434EFBC(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects127And128Descriptor39ScaleFade, &gBattleAnimParticleDescriptors[0x39], 8, 3, 2, 0, 0x47, 0);
}

void func_8434F010(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffects12And129DelayedModelAnimWait, &gDefaultParticleDescriptor, 0x1E, 3, 6, 0, 0, 0);
}

void func_8434F060(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 6);
}

void func_8434F0B8(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackSharedDescriptor34DelayedFrameMotion, &gBattleAnimParticleDescriptors[0x34], 0, 1, 0x11, 9, 0, 6);
}

void BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade_InitParticle(Particle* arg0) {
    s16 sp26 = Particle_FieldAC_GetS16_0C038(arg0);
    s16 sp24 = Particle_FieldCF_GetS16_0C058(arg0);

    Particle_FieldCE_GetS32_0C040(arg0);

    switch (sp26) {
        case 0:
            Particle_SetPosition(arg0, 0.0f, 0.0f, 0.0f);
            break;

        case 1:
            Particle_SetPosition(arg0, 0.0f, 10.0f, 10.0f);
            break;

        case 2:
            Particle_SetPosition(arg0, 0.0f, 15.0f, -15.0f);
            break;
    }

    Particle_Field1C_SetScaled_0B938(arg0, 0.01f);
    Particle_SetScaleSpeed(arg0, 0.5f);
    Particle_SetScaleTarget(arg0, 0.05f);
    ParticleGfx_RecolorPrimEnvFromPalettePair(arg0, sp24);
    Particle_SetPrimAlpha(arg0, 0xFF);
    Particle_FieldA6_SetS16_0BCA8(arg0, sp26 * 8);
    Particle_DisableRendering(arg0);
    Particle_AdvanceLifecycle(arg0);
}

void BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade(Particle* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade_InitParticle(arg0);
            break;

        case 2:
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_EnableRendering(arg0);
                Particle_FieldA6_SetS16_0BCA8(arg0, 0xA);
            }
            break;

        case 3:
            Particle_Field1C_ApproachField24ByField20_0BA1C(arg0);
            Particle_Field50_AddYScaled_099E0(arg0, 1.0f);
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                Particle_FieldA6_SetS16_0BCA8(arg0, 0x10);
            }
            break;

        case 4:
            Particle_Field74_Approach_0ADBC(arg0, 4.0f, 0.5f);
            Particle_Field50_AddYScaled_099E0(arg0, arg0->unk_74);
            Particle_PrimAlpha_Approach_0BC2C(arg0, 0, 0x10);
            if (Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(arg0) != 0) {
                break;
            }
            break;

        case 5:
            Particle_MarkInactive(arg0);
            break;
    }
}

void func_8434F350(void) {
    BattleAnim_CreateEffectSlotForCurrentOwner(0, BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade, &gBattleAnimParticleDescriptors[0x39], 8, 3, 2, 0, 0x46, 0);
    BattleAnim_CreateEffectSlotForCurrentOwner(0x10, BattleAnim_CallbackStartEffect132Descriptor39DelayedRiseFade, &gBattleAnimParticleDescriptors[0x39], 8, 3, 2, 0, 0x46, 0);
}
