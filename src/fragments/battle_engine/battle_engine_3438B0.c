#include "battle_engine.h"
#include "src/gfx_buffer.h"

void BattleAnim_RenderNop1(void) {
}

void BattleAnim_RenderNop2(void) {
}

void BattleAnim_DrawFullScreenColorOverlay(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8140DDF8);

    ParticleGfx_SetPrimColor(arg0, arg1, arg2, arg3);

    gSPTextureRectangle(gDisplayListHead++, 0, 0, 0x04FC, 0x03BC, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    gSPDisplayList(gDisplayListHead++, D_8140DDD8);
}

void BattleAnim_RenderEffectsFrame(CameraNode* arg0) {
    BattleAnim_DrawEffectCallbacks(arg0);
    gParticleMatrixPool = Gfx_AllocDisplayList(sizeof(ParticleMatrixPool));
    gParticleMatrixPoolIndex = 0;
    gBattleAnimFrameCounter += 1;

    gSPDisplayList(gDisplayListHead++, D_8140DB30);

    ParticleGfx_SetPrimColor(D_84390382, D_84390384, D_84390386, D_84390388);
    ParticleGfx_SetFogColor(D_84390392, D_84390394, D_84390396, D_84390398);
    ParticleGfx_SetEnvColor(D_8439038A, D_8439038C, D_8439038E, D_84390390);
    ParticleGfx_SetBlendColor(D_8439039A, D_8439039C, D_8439039E, D_843903A0);
    Battle_SetStageTintColor(D_8439037A, D_8439037C, D_8439037E);
    Particle_RenderWorldChains(arg0);
    guOrtho(&gParticleMatrixPool->unk_5B80, 0.0f, 320.0f, 240.0f, 0.0f, -2.0f, 2.0f, 1.0f);

    gSPMatrix(gDisplayListHead++, (u32)&gParticleMatrixPool->unk_5B80 & 0x1FFFFFFF,
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gDisplayListHead++, D_8140DD78);

    ParticleGfx_PipeSync();
    Particle_RenderOrthoParticles(arg0);

    gSPDisplayList(gDisplayListHead++, D_8140DAE0);
}
