#include "battle_engine.h"

s32 BattleAnim_DrawAsset95Ia8Billboard(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_PushBillboardMatrix(arg1, arg0->unk_2C, arg0->unk_1C);

    gSPDisplayList(gDisplayListHead++, gDL_PanelBackground);
}

void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4Overlay(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_LoadTextureIa8(sBattleAnimAssetPointers[0x76] + (arg0->unk_C7 << 0xB), 0x20, 0x40);
    ParticleGfx_LoadTextureI4MultiBlockWrapSTWithShift(sBattleAnimAssetPointers[0x77], 0x40, 0x40, 2, 1);
    ParticleGfx_SetAnimatedAuxTileSize(0, 0xA, 0x40, 0x40);
    ParticleGfx_SetPrimEnvLodTextureCombine(0x80, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a, arg0->env_r, arg0->env_g, arg0->env_b);
    ParticleGfx_DrawModelQuad(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E1F8);
}

void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineA(Particle* arg0, CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DCD8);

    BattleAnim_DrawAsset76Ia8FrameWithAsset77I4Overlay(arg0, arg1);
}

void BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineB(Particle* arg0, CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DD58);

    BattleAnim_DrawAsset76Ia8FrameWithAsset77I4Overlay(arg0, arg1);
}

void BattleAnim_DrawAsset1FAnimatedI4WithAsset20DisplayList(Particle* arg0, CameraNode* arg1) {
    ParticleGfx_PushBillboardMatrix(arg1, arg0->unk_2C, arg0->unk_1C);

    gSPDisplayList(gDisplayListHead++, D_8140DD58);

    ParticleGfx_LoadTextureI4WrapSTNoMirror(sBattleAnimAssetPointers[0x1F], 0x20, 0x40);
    ParticleGfx_SetAnimatedTileSize(0, 8, 0x20, 0x40);
    ParticleGfx_SetPrimEnvColorShadeCombine(0xFF, 0xFF, 0xFF, arg0->prim_a, 0xFF, 0xFF, 0xFF, 0xFF);

    gDPSetRenderMode(gDisplayListHead++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
    gSPDisplayList(gDisplayListHead++, sBattleAnimAssetPointers[0x20]);
}

s32 BattleAnim_DrawAssetBcRgba16WithAssetBdDisplayList(Particle* arg0, UNUSED CameraNode* arg1) {
    ParticleGfx_PushTransformMatrix(arg0->unk_2C, arg0->unk_94, arg0->unk_1C);

    gSPDisplayList(gDisplayListHead++, gDL_ItemIcon);

    ParticleGfx_LoadTextureRgba16(sBattleAnimAssetPointers[0xBC], 0x20, 0x20);

    gSPDisplayList(gDisplayListHead++, sBattleAnimAssetPointers[0xBD]);
}

void BattleAnim_DrawAssets27And28LayeredI4QuadVariantA(Particle* arg0, UNUSED CameraNode* arg1) {
    ParticleGfx_Push2DTransform(arg0->unk_2C.x, arg0->unk_2C.y, arg0->unk_94.z, arg0->unk_1C);

    gSPDisplayList(gDisplayListHead++, D_8140DCD8);

    ParticleGfx_SetPrimEnvLodCombine(0x80, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a, arg0->env_r, arg0->env_g, arg0->env_b);
    ParticleGfx_LoadTextureI4WrapSTNoMirror(sBattleAnimAssetPointers[0x27], 0x40, 0x40);
    ParticleGfx_SetAnimatedTileSize(2, -2, 0x40, 0x40);
    ParticleGfx_LoadTextureI4MultiBlockWrapST(sBattleAnimAssetPointers[0x28], 0x40, 0x40);
    ParticleGfx_SetAnimatedAuxTileSize(0, -1, 0x40, 0x40);
    ParticleGfx_DrawQuadVertices(D_84385DC0);
}

void BattleAnim_DrawAssets27And28LayeredI4QuadVariantB(Particle* arg0, UNUSED CameraNode* arg1) {
    ParticleGfx_Push2DTransform(arg0->unk_2C.x, arg0->unk_2C.y, arg0->unk_94.z, arg0->unk_1C);

    gSPDisplayList(gDisplayListHead++, D_8140DCD8);

    ParticleGfx_SetPrimEnvLodCombine(0x80, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a, arg0->env_r, arg0->env_g, arg0->env_b);
    ParticleGfx_LoadTextureI4WrapSTNoMirror(sBattleAnimAssetPointers[0x27], 0x40, 0x40);
    ParticleGfx_SetAnimatedTileSize(1, -3, 0x40, 0x40);
    ParticleGfx_LoadTextureI4MultiBlockWrapST(sBattleAnimAssetPointers[0x28], 0x40, 0x40);
    ParticleGfx_SetAnimatedAuxTileSize(-2, -2, 0x40, 0x40);
    ParticleGfx_DrawQuadVertices(D_84385E00);
}

void BattleAnim_DrawAsset29DualI4LayeredQuad(Particle* arg0, UNUSED CameraNode* arg1) {
    ParticleGfx_Push2DTransform(arg0->unk_2C.x, arg0->unk_2C.y, arg0->unk_94.z, arg0->unk_1C);

    gSPDisplayList(gDisplayListHead++, D_8140DCD8);

    ParticleGfx_SetPrimEnvLodCombine(0x80, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a, arg0->env_r, arg0->env_g, arg0->env_b);
    ParticleGfx_LoadTextureMultiBlock4(sBattleAnimAssetPointers[0x29], 0, 0, 4, 0x20, 0x20, 1, 1, 5, 5, 2, 0);
    ParticleGfx_SetAnimatedTileSize(1, 1, 0x20, 0x20);
    ParticleGfx_LoadTextureMultiBlock4(sBattleAnimAssetPointers[0x29], 0x100, 1, 4, 0x20, 0x20, 1, 1, 5, 5, 1, 0xF);
    ParticleGfx_SetAnimatedAuxTileSize(-1, 1, 0x20, 0x20);
    ParticleGfx_DrawQuadVertices(gFullscreenQuadVtx);
}

void BattleAnim_DrawAsset87AnimatedI4Quad(Particle* arg0, UNUSED CameraNode* arg1) {
    ParticleGfx_Push2DTransform(arg0->unk_2C.x, arg0->unk_2C.y, arg0->unk_94.z, arg0->unk_1C);

    gSPDisplayList(gDisplayListHead++, D_8140DCD8);

    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_LoadTextureI4WrapSTNoMirror(sBattleAnimAssetPointers[0x87], 0x20, 0x20);
    ParticleGfx_SetAnimatedTileSize(0, 2, 0x20, 0x20);
    ParticleGfx_DrawQuadVertices(gFullscreenQuadVtx);
}

void BattleAnim_DrawI4AtlasYScaled(Particle* arg0, u8* arg1) {
    ParticleGfx_Push2DTransformYScaled(arg0->unk_2C.x, arg0->unk_2C.y, arg0->unk_94.z, arg0->unk_1C);

    gSPDisplayList(gDisplayListHead++, D_8140DCD8);

    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawI4TextureAtlas(arg1, D_84385C80, 0x40, 0x40, 0x40, 0x40);
}

void BattleAnim_DrawAsset19I4AtlasYScaled(Particle* arg0, UNUSED CameraNode* arg1) {
    BattleAnim_DrawI4AtlasYScaled(arg0, sBattleAnimAssetPointers[0x19]);
}

void BattleAnim_DrawAsset5EI4AtlasYScaled(Particle* arg0, UNUSED CameraNode* arg1) {
    BattleAnim_DrawI4AtlasYScaled(arg0, sBattleAnimAssetPointers[0x5E]);
}

void BattleAnim_DrawAsset1AFrameI4Quad(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DD58);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x1A] + (arg0->unk_C7 << 9), 0x20, 0x20);
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawTransformedQuad(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_8140E018);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset1CRgba16Quad(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DC00);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureRgba16(sBattleAnimAssetPointers[0x1C], 0x20, 0x20);
    ParticleGfx_DrawTransformedQuad(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_8140E018);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset1ERgba16Quad(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DC00);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureRgba16(sBattleAnimAssetPointers[0x1E], 0x20, 0x20);
    ParticleGfx_DrawTransformedQuad(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_8140E018);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAssetC3Rgba16Quad(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DC00);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureRgba16(sBattleAnimAssetPointers[0xC3], 0x20, 0x20);
    ParticleGfx_DrawTransformedQuad(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_8140E018);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset1DRotatedI4Quad(Particle* arg0, UNUSED CameraNode* arg1) {
    Vec3s sp40;

    gSPDisplayList(gDisplayListHead++, D_8140DCD8);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x1D], 0x20, 0x20);
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    sp40.x = arg0->unk_94.x + 0x4000;
    sp40.y = arg0->unk_94.y + 0x4000;
    sp40.z = arg0->unk_94.z;
    ParticleGfx_DrawTransformedQuad(arg0->unk_2C, sp40, arg0->unk_1C, D_8140E018);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawParticleNoop(UNUSED Particle* arg0, UNUSED CameraNode* arg1) {
}

void BattleAnim_DrawAsset13FrameI4YScaledQuadA(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DD58);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x13] + (gParticleFrameMod8 * 0x600), 0x20, 0x60);
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);

    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_DrawTransformedQuadYScaled(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_84385CC0);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset13FrameI4YScaledQuadB(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DD58);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x13] + (gParticleFrameMod8 * 0x600), 0x20, 0x60);
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawTransformedQuadYScaled(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_84385D00);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset13FrameI4YScaledQuadC(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DD58);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x13] + (gParticleFrameMod8 * 0x600), 0x20, 0x60);
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawTransformedQuadYScaled(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, D_84385D40);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset13FrameI4ModelQuadA(Particle* arg0, CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DD58);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x13] + (gParticleFrameMod8 * 0x600), 0x20, 0x60);
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuadRotatedYScaled(arg1, arg0->unk_2C, arg0->unk_1C, D_84385CC0, arg0->unk_94.z);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset13FrameI4ModelQuadB(Particle* arg0, CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DD58);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x13] + (gParticleFrameMod8 * 0x600), 0x20, 0x60);
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuadRotatedYScaled(arg1, arg0->unk_2C, arg0->unk_1C, D_84385D00, arg0->unk_94.z);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset13FrameI4ModelQuadC(Particle* arg0, CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DD58);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x13] + (gParticleFrameMod8 * 0x600), 0x20, 0x60);
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuadRotatedYScaled(arg1, arg0->unk_2C, arg0->unk_1C, D_84385D40, arg0->unk_94.z);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset1BI4TriangleA(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DCD8);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x1B], 0x10, 0x100);
    ParticleGfx_SetPrimEnvColorCombine(0xFF, 0xFF, 0xFF, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
    ParticleGfx_DrawTransformedTriangle(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, gVtx_UI_TriangleSmall);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset1BI4TriangleB(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DCD8);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x1B], 0x10, 0x100);
    ParticleGfx_SetPrimEnvColorCombine(0xFF, 0xFF, 0xFF, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
    ParticleGfx_DrawTransformedTriangle(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, gVtx_UI_TriangleLarge);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset13FrameDiv2I4Quad(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DCD8);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x13] + ((gParticleFrameDiv2 & 7) * 0x600), 0x20, 0x60);
    ParticleGfx_SetPrimEnvColorCombine(0xFF, 0xFF, 0xFF, 0, 0x64, 0xC8, 0xFF);
    ParticleGfx_DrawTransformedQuad(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, gVtx_UI_ComplexQuad);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawAsset18FrameI4ModelQuad(Particle* arg0, CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DD58);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0x18] + (arg0->unk_C7 << 9), 0x20, 0x20);
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawModelQuadRotated(arg1, arg0->unk_2C, arg0->unk_1C, D_8140E018, arg0->unk_94.z);
}

void BattleAnim_DrawAssetA9I4XYScaledQuad(Particle* arg0, UNUSED CameraNode* arg1) {
    gSPDisplayList(gDisplayListHead++, D_8140DD58);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);

    ParticleGfx_LoadTextureI4Alias(sBattleAnimAssetPointers[0xA9], 0x20, 0x20);
    ParticleGfx_SetPrimEnvColorCombine(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->env_r, arg0->env_g, arg0->env_b, arg0->prim_a);
    ParticleGfx_DrawTransformedQuadXYScaled(arg0->unk_2C, arg0->unk_94, arg0->unk_1C, arg0->unk_20, gVtx_UI_RectVertical);

    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void BattleAnim_DrawParticleFullScreenColorOverlay(Particle* arg0, UNUSED CameraNode* arg1) {
    BattleAnim_DrawFullScreenColorOverlay(arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
}
