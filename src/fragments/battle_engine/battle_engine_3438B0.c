#include "battle_engine.h"
#include "src/gfx_buffer.h"

void BattleAnim_RenderNop1(void) {
}

void BattleAnim_RenderNop2(void) {
}

void BattleAnim_DrawFullScreenColorOverlay(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    gSPDisplayList(gDisplayListHead++, gDL_BeginColorFill);

    ParticleGfx_SetPrimColor(arg0, arg1, arg2, arg3);

    gSPTextureRectangle(gDisplayListHead++, 0, 0, 0x04FC, 0x03BC, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    gSPDisplayList(gDisplayListHead++, gDL_EndColorFill);
}

void BattleAnim_RenderEffectsFrame(CameraNode* arg0) {
    BattleAnim_DrawEffectCallbacks(arg0);
    gParticleMatrixPool = Gfx_AllocDisplayList(sizeof(ParticleMatrixPool));
    gParticleMatrixPoolIndex = 0;
    gBattleAnimFrameCounter += 1;

    gSPDisplayList(gDisplayListHead++, D_8140DB30);

    ParticleGfx_SetPrimColor(gPrimColorR, gPrimColorG, gPrimColorB, gPrimColorA);
    ParticleGfx_SetFogColor(gFogColorR, gFogColorG, gFogColorB, gFogColorA);
    ParticleGfx_SetEnvColor(gEnvColorR, gEnvColorG, gEnvColorB, gEnvColorA);
    ParticleGfx_SetBlendColor(gBlendColorR, gBlendColorG, gBlendColorB, gBlendColorA);
    Battle_SetStageTintColor(gSavedPrimColorR, gSavedPrimColorG, gSavedPrimColorB);
    Particle_RenderWorldChains(arg0);
    guOrtho(&gParticleMatrixPool->unk_5B80, 0.0f, 320.0f, 240.0f, 0.0f, -2.0f, 2.0f, 1.0f);

    gSPMatrix(gDisplayListHead++, (u32)&gParticleMatrixPool->unk_5B80 & 0x1FFFFFFF,
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gDisplayListHead++, gDL_BeginUIOverlay);

    ParticleGfx_PipeSync();
    Particle_RenderOrthoParticles(arg0);

    gSPDisplayList(gDisplayListHead++, D_8140DAE0);
}
