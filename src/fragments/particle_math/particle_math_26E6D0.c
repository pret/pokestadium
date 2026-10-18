#include "particle_math.h"

static u8 gParticlePalette[][3] = {
    { 0, 0, 0 },          { 0, 0x14, 0x1E },    { 0, 0x23, 0x2D },    { 0x40, 0x40, 0x40 }, { 0x46, 0x55, 0x55 },
    { 0x6E, 0x6E, 0x6E }, { 0x80, 0x80, 0x80 }, { 0xB4, 0xC8, 0xC8 }, { 0xC8, 0xFF, 0xFF }, { 0xE6, 0xF0, 0xF0 },
    { 0xFF, 0xFF, 0xFF }, { 0xFF, 0, 0 },       { 0xF0, 0x28, 0x28 }, { 0xFF, 0x80, 0x80 }, { 0xAA, 0x32, 0 },
    { 0x96, 0, 0 },       { 0x64, 0, 0 },       { 0x46, 0x14, 0 },    { 0x32, 0xA, 0xA },   { 0xFF, 0x80, 0 },
    { 0xFF, 0xA0, 0 },    { 0xF0, 0xDC, 0xD8 }, { 0xFF, 0xC8, 0xC8 }, { 0xFF, 0x78, 0xC8 }, { 0xFF, 0, 0x64 },
    { 0xFF, 0xFF, 0 },    { 0xFF, 0xFF, 0x64 }, { 0xFF, 0xFF, 0x9B }, { 0xFF, 0xFF, 0xC8 }, { 0xFF, 0xC8, 0 },
    { 0xD7, 0xFF, 0x73 }, { 0xC8, 0xC8, 0 },    { 0x96, 0x96, 0x32 }, { 0x64, 0x64, 0 },    { 0x80, 0x80, 0x50 },
    { 0, 0xFF, 0 },       { 0x28, 0xFF, 0x28 }, { 0x64, 0xFF, 0x64 }, { 0x80, 0xFF, 0x80 }, { 0x9B, 0xFF, 0xC8 },
    { 0x50, 0x64, 0x3C }, { 0xC8, 0xFF, 0 },    { 0xC8, 0xC8, 0 },    { 0x96, 0xB4, 0 },    { 0, 0x96, 0 },
    { 0, 0x64, 0 },       { 0, 0, 0xFF },       { 0x32, 0x32, 0xFF }, { 0, 0x32, 0xFF },    { 0, 0x64, 0xFF },
    { 0, 0x78, 0xFF },    { 0x20, 0x7C, 0xFF }, { 0x80, 0x80, 0xFF }, { 0x64, 0xC8, 0xFF }, { 0, 0xFF, 0xFF },
    { 0x64, 0xFF, 0xFF }, { 0xB4, 0xFF, 0xFF }, { 0xC8, 0xFF, 0xFF }, { 0x46, 0x64, 0x78 }, { 0xFF, 0, 0xFF },
    { 0xFF, 0x32, 0xFF }, { 0xD7, 0, 0xFF },    { 0x96, 0, 0xC8 },    { 0x64, 0, 0xFF },    { 0xFF, 0x32, 0xFF },
    { 0x78, 0x1E, 0x78 },
};

u8 gParticlePaletteSetA[] = {
    0x0C, 0x19, 0x23, 0x36, 0x2F, 0x3B,
};

static u8 gParticlePaletteSetB[] = {
    0x17, 0x19, 0x25, 0x23, 0x35, 0x14,
};

static u8 gParticleRandomPaletteIndices[] = {
    0x0A, 0x19, 0x36, 0x24, 0x16,
};

static u8 gParticlePalettePairs[][2] = {
    { 0x19, 0xC },  { 0xA, 0x3B },  { 0, 0xC },     { 8, 0x31 },    { 0x2A, 0x23 }, { 0x19, 0x1F }, { 0x36, 0x32 },
    { 0x19, 0xB },  { 0x3B, 0x3C }, { 0xC, 0xC },   { 0xA, 0x1C },  { 0xA, 0x14 },  { 0xA, 0x35 },  { 0xA, 0x24 },
    { 0xA, 0xC },   { 0x19, 0x14 }, { 0x19, 0xC },  { 0x15, 0xA },  { 0xE, 0x11 },  { 8, 0x37 },    { 0x36, 0x30 },
    { 0xA, 0x3F },  { 0xB, 0 },     { 0xA, 0x19 },  { 0xA, 0x36 },  { 0x37, 0x31 }, { 0x19, 0xB },  { 0, 0x3B },
    { 0, 1 },       { 0xA, 0xA },   { 4, 2 },       { 0x29, 0x2C }, { 0xA, 0 },     { 0xC, 0x10 },  { 0x1B, 0x3B },
    { 0xA, 0x27 },  { 0x14, 0xB },  { 0xA, 0x1C },  { 0xA, 0x35 },  { 0xA, 8 },     { 0xA, 0x31 },  { 0x1C, 0x1A },
    { 0x1A, 0xB },  { 0x14, 0xF },  { 0x1A, 0x14 }, { 0x14, 0 },    { 0xB, 0 },     { 0x36, 0x2D }, { 0x23, 0x2C },
    { 0x1A, 0x20 }, { 0x21, 0x21 }, { 0xA, 0xA },   { 0x19, 0x2C }, { 0x3B, 0x3C }, { 0x2B, 0xA },  { 0x3E, 0xA },
    { 0x19, 0x23 }, { 0xA, 0x23 },  { 0xB, 0 },     { 0xA, 0x1A },  { 0xA, 0x35 },  { 0xA, 0x35 },  { 0xA, 0x17 },
    { 0xA, 0x3F },  { 0xA, 0x31 },  { 0xA, 0x17 },  { 0xA, 0x13 },  { 0x3C, 0x3E }, { 0x15, 0x15 }, { 0x3E, 0x3E },
    { 0x23, 0x23 }, { 0x13, 0xC },  { 0x19, 0x13 }, { 0x16, 0xC },  { 0x1C, 0x19 }, { 0x39, 0x2F }, { 0xA, 0x39 },
    { 0x38, 0x35 }, { 0x38, 0x39 }, { 0x1C, 0x1A }, { 9, 0x35 },
};

void ParticleGfx_LoadTextureCallbackRgba16_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureRgba16(texture, 32, 32);
}

void ParticleGfx_LoadTextureCallbackIa8Frame_32x32(Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureIa8(&texture[arg0->unk_C7 * 32 * 32], 32, 32);
}

void ParticleGfx_LoadTextureCallbackIa8_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureIa8(texture, 32, 32);
}

void ParticleGfx_LoadTextureCallbackIa8Frame_32x64(Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureIa8(&texture[arg0->unk_C7 * 32 * 64], 32, 64);
}

void ParticleGfx_LoadTextureCallbackI4_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(texture, 32, 32);
}

void ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32(Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[arg0->unk_C7 * (32 * 32 / 2)], 32, 32);
}

void ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[gParticleFrameMod4 * (32 * 32 / 2)], 32, 32);
}

void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod4_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[(gParticleFrameDiv2 & 3) * (32 * 32 / 2)], 32, 32);
}

void ParticleGfx_LoadTextureCallbackI4FrameDiv4Mod4_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[(gParticleFrameDiv4 & 3) * (32 * 32 / 2)], 32, 32);
}

void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[(gParticleFrameDiv2 & 7) * (32 * 32 / 2)], 32, 32);
}

void ParticleGfx_LoadTextureCallbackI4TileFrameDiv2Mod8_24x24(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureTileI4Alias(&texture[(gParticleFrameDiv2 & 7) * (24 * 24 / 2)], 24, 24);
}

void ParticleGfx_LoadTextureCallbackI4TileParticleFrame_24x24(Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureTileI4Alias(&texture[arg0->unk_C7 * (24 * 24 / 2)], 24, 24);
}

void ParticleGfx_LoadTextureCallbackI4FrameMod10_32x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[(gParticleFrameCounter % 10) * (32 * 64 / 2)], 32, 64);
}

void ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x64(Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[arg0->unk_C7 * (32 * 64 / 2)], 32, 64);
}

void ParticleGfx_LoadTextureCallbackI4_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(texture, 64, 64);
}

void ParticleGfx_LoadTextureCallbackI4FrameMod8_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[gParticleFrameMod8 * (64 * 64 / 2)], 64, 64);
}

void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[(gParticleFrameDiv2 & 7) * (64 * 64 / 2)], 64, 64);
}

void ParticleGfx_LoadTextureCallbackI4ParticleFrame_64x64(Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4Alias(&texture[arg0->unk_C7 * (64 * 64 / 2)], 64, 64);
}

void ParticleGfx_LoadTextureCallbackI4WrapST_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureI4WrapST(texture, 64, 64);
}

void ParticleGfx_LoadTextureCallbackIa8WrapST_64x64(UNUSED Particle* arg0, u8* texture) {
    ParticleGfx_LoadTextureIa8WrapST(texture, 64, 64);
}

void ParticleGfx_DrawBillboardPrim(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimColorTextureCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E018);
}

void ParticleGfx_DrawBillboardPrimEnv(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_8140DFD8);
}

s32 ParticleGfx_DrawBillboardDoubleSided(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawTransformedQuad(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_8140DFD8);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void ParticleGfx_DrawBillboardDefaultQuad(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E018);
}

void ParticleGfx_DrawBillboardPrimEnvQuad(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E018);
}

void ParticleGfx_DrawBillboardTextureAlphaRotatedQuad(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetTextureAlphaCombine(arg0->prim_a);
    ParticleGfx_DrawModelQuadRotated(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E108, arg0->unk_94.z);
}

void ParticleGfx_DrawBillboardOffsetQuad(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E058);
}

void ParticleGfx_DrawBillboardPrimEnvNoiseQuad(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimEnvNoiseCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E018);
}

void ParticleGfx_DrawBillboardPrimEnvRotatedQuad(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuadRotated(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E018, arg0->unk_94.z);
}

void ParticleGfx_DrawBillboardPrimEnvRotatedTriangle(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelTriangleRotated(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E0D8, arg0->unk_94.z);
}

void ParticleGfx_DrawBillboardPrimEnvQuadVariantA(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E178);
}

void ParticleGfx_DrawBillboardPrimEnvQuadVariantB(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E1F8);
}

void ParticleGfx_DrawBillboardPrimEnvQuadVariantC(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E1B8);
}

void ParticleGfx_DrawBillboardPrimEnvComposite(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E2B8);
}

s32 ParticleGfx_DrawBillboardPrimEnvTriangleDoubleSided(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawTransformedQuad(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_8140E2B8);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void ParticleGfx_DrawBillboardPrimEnvTransformedQuad(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawTransformedQuad(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_8140E378);
}

void ParticleGfx_CopyPaletteRgb(u8* arg0, u16 arg1) {
    arg0[0] = gParticlePalette[arg1][0];
    arg0[1] = gParticlePalette[arg1][1];
    arg0[2] = gParticlePalette[arg1][2];
}

void ParticleGfx_CopyPalettePairRgb(u8* arg0, u8* arg1, u16 arg2) {
    u8 sp1C = gParticlePalettePairs[arg2][0];
    u8 sp1E = gParticlePalettePairs[arg2][1];

    ParticleGfx_CopyPaletteRgb(arg0, sp1C);
    ParticleGfx_CopyPaletteRgb(arg1, sp1E);
}

void ParticleGfx_RecolorPrim(Particle* arg0, u16 arg1) {
    arg0->prim_r = gParticlePalette[arg1][0];
    arg0->prim_g = gParticlePalette[arg1][1];
    arg0->prim_b = gParticlePalette[arg1][2];
}

void ParticleGfx_RecolorEnv(Particle* arg0, u16 arg1) {
    arg0->env_r = gParticlePalette[arg1][0];
    arg0->env_g = gParticlePalette[arg1][1];
    arg0->env_b = gParticlePalette[arg1][2];
}

void ParticleGfx_RecolorPrimEnvFromPalettePair(Particle* arg0, u16 arg1) {
    u8 sp1C = gParticlePalettePairs[arg1][0];
    u8 sp1E = gParticlePalettePairs[arg1][1];

    ParticleGfx_RecolorPrim(arg0, sp1C);
    ParticleGfx_RecolorEnv(arg0, sp1E);
}

void ParticleGfx_RecolorPrimFromPaletteSetA(Particle* arg0, s16 arg1) {
    ParticleGfx_RecolorPrim(arg0, gParticlePaletteSetA[arg1]);
}

void ParticleGfx_RecolorEnvFromPaletteSetA(Particle* arg0, s16 arg1) {
    ParticleGfx_RecolorEnv(arg0, gParticlePaletteSetA[arg1]);
}

void ParticleGfx_RecolorPrimFromPaletteSetB(Particle* arg0, s16 arg1) {
    ParticleGfx_RecolorPrim(arg0, gParticlePaletteSetB[arg1]);
}

void ParticleGfx_RecolorEnvFromPaletteSetB(Particle* arg0, s16 arg1) {
    ParticleGfx_RecolorEnv(arg0, gParticlePaletteSetB[arg1]);
}

void ParticleGfx_RecolorPrimEnvFromPaletteSetA(Particle* arg0, s16 arg1) {
    u8 sp1F = gParticlePaletteSetA[arg1];

    ParticleGfx_RecolorPrim(arg0, sp1F);
    ParticleGfx_RecolorEnv(arg0, sp1F);
}

void ParticleGfx_RecolorPrimEnvFromPaletteSetB(Particle* arg0, s16 arg1) {
    u8 sp1F = gParticlePaletteSetB[arg1];

    ParticleGfx_RecolorPrim(arg0, sp1F);
    ParticleGfx_RecolorEnv(arg0, sp1F);
}

void ParticleGfx_RecolorPrimRandomPalette(Particle* arg0) {
    ParticleGfx_RecolorPrim(arg0, gParticleRandomPaletteIndices[(ParticleMath_RandomRange(5) & 0xFF)]);
}

void ParticleGfx_RecolorEnvRandomPalette(Particle* arg0) {
    ParticleGfx_RecolorEnv(arg0, gParticleRandomPaletteIndices[ParticleMath_RandomRange(5) & 0xFF]);
}

s32 ParticleGfx_ApproachPrimPalette(Particle* arg0, u16 arg1, u8 arg2) {
    s32 sp2C = 0;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    u8 sp1C[3];

    ParticleGfx_CopyPaletteRgb(sp1C, arg1);

    sp28 = Particle_PrimR_Approach_0BAE4(arg0, sp1C[0], arg2);
    sp24 = Particle_PrimG_Approach_0BB14(arg0, sp1C[1], arg2);
    sp20 = Particle_PrimB_Approach_0BB44(arg0, sp1C[2], arg2);

    if ((sp28 * sp24 * sp20) != 0) {
        sp2C = 1;
    }
    return sp2C;
}

s32 ParticleGfx_ApproachEnvPalette(Particle* arg0, u16 arg1, u8 arg2) {
    s32 sp2C = 0;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    u8 sp1C[3];

    ParticleGfx_CopyPaletteRgb(&sp1C, arg1);

    sp28 = Particle_EnvR_Approach_0BB90(arg0, sp1C[0], arg2);
    sp24 = Particle_EnvG_Approach_0BBF0(arg0, sp1C[1], arg2);
    sp20 = Particle_EnvB_Approach_0BBC0(arg0, sp1C[2], arg2);

    if ((sp28 * sp24 * sp20) != 0) {
        sp2C = 1;
    }
    return sp2C;
}

s32 ParticleGfx_ApproachPrimEnvPalettePair(Particle* arg0, u16 arg1, u8 arg2) {
    s32 sp44 = 0;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    u8 sp28[3];
    u8 sp24[3];

    ParticleGfx_CopyPalettePairRgb(sp28, sp24, arg1);

    sp40 = Particle_PrimR_Approach_0BAE4(arg0, sp28[0], arg2);
    sp3C = Particle_PrimG_Approach_0BB14(arg0, sp28[1], arg2);
    sp38 = Particle_PrimB_Approach_0BB44(arg0, sp28[2], arg2);
    sp34 = Particle_EnvR_Approach_0BB90(arg0, sp24[0], arg2);
    sp30 = Particle_EnvG_Approach_0BBF0(arg0, sp24[1], arg2);
    sp2C = Particle_EnvB_Approach_0BBC0(arg0, sp24[2], arg2);

    if ((sp40 * sp3C * sp38 * sp34 * sp30 * sp2C) != 0) {
        sp44 = 1;
    }
    return sp44;
}
