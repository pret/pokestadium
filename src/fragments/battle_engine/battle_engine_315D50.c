#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/audio_commands.h"
#include "src/3D140.h"
#include "src/audio_fade.h"
#include "src/audio_sfx.h"
#include "src/audio_loop_point.h"
#include "src/cry.h"
#include "src/matrix.h"
#include "src/math_util.h"

typedef struct unk_D_84392040 {
    /* 0x00 */ char unk00[0xC];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk14[0x4];
} unk_D_84392040; // size = 0x18

s32 D_843902A0;
#include "prevent_bss_reordering.h"
s32 gBattleAnimFrameCounter;
s32 gBattleAnimSpawnDelay;
static s32 sBattleAnimQueuedMoveId;
static s32 sBattleAnimQueuedEffectListMode;
#define BATTLE_ANIMATION_QUEUE_INACTIVE 0
#define BATTLE_ANIMATION_QUEUE_START 1
#define BATTLE_ANIMATION_QUEUE_END 2
static s32 D_843902B4;
static s32 sBattleAnimQueuedEffectList;
static s32 D_843902BC;
static s32 sBattleAnimQueuedResourceListPending;
static s32 sBattleAnimQueuedResourceListId;
static s32 sBattleAnimQueuedAlternatePending;
static s32 sBattleAnimQueuedAlternateMoveId;
static s32 sBattleAnimQueuedAlternateList;
static s32 sBattleAnimQueuedExtraPending;
static s32 sBattleAnimQueuedExtraMoveId;
static s32 sBattleAnimQueuedExtraList;
static s8 sBattleAnimCurrentEffectList;
s16 gBattleAnimCurrentAnchor;
s16 gBattleAnimDefaultAnchor;
static s16 sBattleAnimAlternateAnchor;
ActivePokemon* gBattleAnimCurrentOwner;
ActivePokemon* gBattleAnimSecondaryOwner;
ActivePokemon* gBattleAnimTertiaryOwner;
s32 D_843902F4;
s32 D_843902F8;
static s8 sBattleAnimEffectCallbackIndex;
func_D_84390300 gBattleAnimEffectUpdateFuncs[8];
func_D_84390320 gBattleAnimEffectDrawFuncs[8];
s32 D_84390340;
static f32 D_84390344;
Vec3f D_84390348;
static Vec3s D_84390354;
static Vec3f D_84390360;
static Vec3s D_8439036C;
static Vec3s D_84390374;
s16 gSavedPrimColorR;
s16 gSavedPrimColorG;
s16 gSavedPrimColorB;
s16 gSavedPrimColorA;
s16 gPrimColorR;
s16 gPrimColorG;
s16 gPrimColorB;
s16 gPrimColorA;
s16 gEnvColorR;
s16 gEnvColorG;
s16 gEnvColorB;
s16 gEnvColorA;
s16 gFogColorR;
s16 gFogColorG;
s16 gFogColorB;
s16 gFogColorA;
s16 gBlendColorR;
s16 gBlendColorG;
s16 gBlendColorB;
s16 gBlendColorA;
s32 pad_D_843903A8[2];
static s32 D_843903B0;
static s32 D_843903B4;
s32 pad_D_843903B8[6];
static DisplayObject D_843903D0[16];
static s32 D_84391A50[16];
static DisplayObject D_84391A90[4];
static s32 D_84392030[4];
static unk_D_84392040 D_84392040;
f32 D_84392058[26];

static s32 D_84385BB0[] = { 0, 0, 0, 0 };

u32 D_84385BC0[] = {
    0x00000005, 0x00000006, 0x00000007, 0x00000008, 0x00000009, 0x0000000A, 0x0000000B, 0x0000000C,
    0x0000000D, 0x0000000E, 0x0000000F, 0x00000010, 0x00000011, 0x00000012, 0x00000013, 0x00000014,
    0x00000015, 0x00000016, 0x00000017, 0x00000018, 0x00000019, 0x0000001A, 0x0000001B, 0x0000001C,
    0x0000001D, 0x0000001E, 0x0000001F, 0x00000020, 0x00000021, 0x00000026, 0x00000027, 0x00000028,
    0x00000029, 0x0000002A, 0x0000002B, 0x0000002C, 0x0000002D, 0x0000002E, 0x0000002F, 0x00000030,
    0x00000031, 0x00000032, 0x00000033, 0x00000034, 0x00000035, 0x00000036, 0x00000000, 0x00000000,
};

Vtx D_84385C80[] = {
    VTX(-64, -63, 0, 0, 2016, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(62, -63, 0, 2016, 2016, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(62, 0, 0, 2016, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_84385CC0[] = {
    VTX(-16, 96, 0, 0, 3040, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 96, 0, 992, 3040, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 0, 0, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_84385D00[] = {
    VTX(-8, 96, 0, 0, 3040, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(7, 96, 0, 992, 3040, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(7, 0, 0, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-8, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_84385D40[] = {
    VTX(-4, 96, 0, 0, 3040, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(3, 96, 0, 992, 3040, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(3, 0, 0, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(-4, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-160, -120, 0, 0, 2048, 0x00, 0x00, 0x78, 0xFF), VTX(160, -120, 0, 2048, 2048, 0x00, 0x00, 0x78, 0xFF),
    VTX(160, 120, 0, 2048, 0, 0x00, 0x00, 0x78, 0xFF),   VTX(-160, 120, 0, 0, 0, 0x00, 0x00, 0x78, 0xFF),
};

Vtx D_84385DC0[] = {
    VTX(-160, -120, 0, 0, 4096, 0x00, 0x00, 0x78, 0xFF),
    VTX(160, -120, 0, 4096, 4096, 0x00, 0x00, 0x78, 0xFF),
    VTX(160, 120, 0, 4096, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-160, 120, 0, 0, 0, 0x00, 0x00, 0x78, 0xFF),
};

Vtx D_84385E00[] = {
    VTX(-160, -120, 0, 0, 8192, 0x00, 0x00, 0x78, 0xFF),
    VTX(160, -120, 0, 8192, 8192, 0x00, 0x00, 0x78, 0xFF),
    VTX(160, 120, 0, 8192, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-160, 120, 0, 0, 0, 0x00, 0x00, 0x78, 0xFF),
};

ParticleDescriptorChild gParticleDescriptorChildren[] = {
    {
        0x01,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32,
        ParticleGfx_DrawBillboardPrim,
        &sBattleAnimAssetPointers[4],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[5],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod10_32x64,
        ParticleGfx_DrawBillboardPrimEnvQuadVariantA,
        &sBattleAnimAssetPointers[20],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod10_32x64,
        ParticleGfx_DrawBillboardPrimEnvQuadVariantC,
        &sBattleAnimAssetPointers[20],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[5],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32,
        ParticleGfx_DrawBillboardTextureAlphaRotatedQuad,
        &sBattleAnimAssetPointers[5],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod10_32x64,
        ParticleGfx_DrawBillboardPrimEnvQuadVariantC,
        &sBattleAnimAssetPointers[20],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x64,
        ParticleGfx_DrawBillboardPrimEnvQuadVariantA,
        &sBattleAnimAssetPointers[9],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrim,
        &sBattleAnimAssetPointers[3],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[23],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[14],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[17],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[14],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4TileParticleFrame_24x24,
        ParticleGfx_DrawBillboardPrimEnv,
        &sBattleAnimAssetPointers[8],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4TileParticleFrame_24x24,
        ParticleGfx_DrawBillboardPrimEnv,
        &sBattleAnimAssetPointers[8],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4TileParticleFrame_24x24,
        ParticleGfx_DrawBillboardDoubleSided,
        &sBattleAnimAssetPointers[8],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod8_64x64,
        ParticleGfx_DrawBillboardPrimEnvComposite,
        &sBattleAnimAssetPointers[18],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[17],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[17],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[5],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod8_64x64,
        ParticleGfx_DrawBillboardPrimEnvComposite,
        &sBattleAnimAssetPointers[18],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[23],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[13],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv4Mod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[13],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_64x64,
        ParticleGfx_DrawBillboardPrimEnvComposite,
        &sBattleAnimAssetPointers[18],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[23],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4_64x64,
        ParticleGfx_DrawBillboardPrimEnvTriangleDoubleSided,
        &sBattleAnimAssetPointers[11],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[82],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrimEnvRotatedQuad,
        &sBattleAnimAssetPointers[16],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[84],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[169],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[172],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[166],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[167],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_64x64,
        ParticleGfx_DrawBillboardPrimEnvComposite,
        &sBattleAnimAssetPointers[89],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8_32x32,
        ParticleGfx_DrawBillboardPrimEnvRotatedQuad,
        &sBattleAnimAssetPointers[95],
    },
    {
        0x01,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8_32x32,
        BattleAnim_DrawAsset95Ia8Billboard,
        &sBattleAnimAssetPointers[95],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[2],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[100],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvNoiseQuad,
        &sBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvNoiseQuad,
        &sBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[101],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4WrapST_64x64,
        ParticleGfx_DrawBillboardPrimEnvTransformedQuad,
        &sBattleAnimAssetPointers[63],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8WrapST_64x64,
        ParticleGfx_DrawBillboardPrimEnvTransformedQuad,
        &sBattleAnimAssetPointers[112],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardOffsetQuad,
        &sBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x64,
        ParticleGfx_DrawBillboardPrimEnvQuadVariantB,
        &sBattleAnimAssetPointers[117],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[122],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[82],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8_32x32,
        ParticleGfx_DrawBillboardPrimEnvRotatedQuad,
        &sBattleAnimAssetPointers[95],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvRotatedQuad,
        &sBattleAnimAssetPointers[82],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvRotatedQuad,
        &sBattleAnimAssetPointers[82],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &sBattleAnimAssetPointers[14],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardTextureAlphaRotatedQuad,
        &sBattleAnimAssetPointers[17],
    },
};

ParticleDescriptor gBattleAnimParticleDescriptors[] = {
    {
        0x00000001,
        &gParticleDescriptorChildren[0],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[1],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[2],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[3],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[4],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[7],
    },
    {
        0x00000003,
        BattleAnim_DrawParticleNoop,
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[8],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[9],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[10],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[55],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[11],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[12],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[13],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[14],
    },
    {
        0x00000003,
        BattleAnim_DrawAsset13FrameI4YScaledQuadA,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset13FrameI4YScaledQuadB,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset13FrameI4YScaledQuadC,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset13FrameI4ModelQuadA,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset13FrameI4ModelQuadB,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset13FrameI4ModelQuadC,
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[16],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[22],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[23],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[17],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[18],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[56],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[5],
    },
    {
        0x00000003,
        BattleAnim_DrawAsset1BI4TriangleA,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset1BI4TriangleB,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset13FrameDiv2I4Quad,
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[19],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[20],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[24],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[21],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[25],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[26],
    },
    {
        0x00000003,
        BattleAnim_DrawParticleFullScreenColorOverlay,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset18FrameI4ModelQuad,
    },
    {
        0x00000003,
        BattleAnim_DrawAssetA9I4XYScaledQuad,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset19I4AtlasYScaled,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset1AFrameI4Quad,
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[15],
    },
    {
        0x00000003,
        BattleAnim_DrawAsset1CRgba16Quad,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset1ERgba16Quad,
    },
    {
        0x00000003,
        BattleAnim_DrawAssetC3Rgba16Quad,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset1DRotatedI4Quad,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset1FAnimatedI4WithAsset20DisplayList,
    },
    {
        0x00000003,
        BattleAnim_DrawAssetBcRgba16WithAssetBdDisplayList,
    },
    {
        0x00000003,
        BattleAnim_DrawAssets27And28LayeredI4QuadVariantA,
    },
    {
        0x00000003,
        BattleAnim_DrawAssets27And28LayeredI4QuadVariantB,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset29DualI4LayeredQuad,
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[27],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[6],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[45],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[28],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[29],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[30],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[31],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[32],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[33],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[34],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[35],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[54],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[36],
    },
    {
        0x00000003,
        BattleAnim_DrawAsset5EI4AtlasYScaled,
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[37],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[38],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[51],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[39],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[40],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[41],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[42],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[43],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[44],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[46],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[47],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[48],
    },
    {
        0x00000003,
        BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineA,
    },
    {
        0x00000003,
        BattleAnim_DrawAsset76Ia8FrameWithAsset77I4OverlayPipelineB,
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[49],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[50],
    },
    {
        0x00000003,
        BattleAnim_DrawAsset87AnimatedI4Quad,
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[52],
    },
    {
        0x00000001,
        &gParticleDescriptorChildren[53],
    },
    {
        0x00000000,
        NULL,
    },
};

static func_D_84390320 sMoveAnimEffectStartInitFuncs[] = {
    BattleAnim_EffectStartNop, BattleAnim_StartEffect1Descriptor2FPhaseFadeOut, BattleAnim_StartEffect2Descriptor08IndexedScaleDelayFade, BattleAnim_StartEffect3ModelTintAndVerticalFade, BattleAnim_StartEffect4TintDescriptor53ScalePulse, BattleAnim_EffectStartNop, BattleAnim_StartEffect6AnimatedScaleAndBurstEmitter,
    BattleAnim_StartEffect7GlobalTintFade, BattleAnim_StartEffect8ModelBurstAndVerticalFade, BattleAnim_EffectStartNop, BattleAnim_StartEffect10Model60AndModelAnimWait, BattleAnim_StartEffect11GlobalTintFade, BattleAnim_StartEffect12DelayedModelAnim, BattleAnim_StartEffect13SecondaryOwnerSpeciesBranch,
    BattleAnim_StartEffect14ModelAnimAndMoveKeyedTintParticles, BattleAnim_StartEffect15Descriptor08IndexedScaleDelayFade, BattleAnim_StartEffect16TintDescriptor34Sequence, BattleAnim_StartEffect17ModelAnimFinish, BattleAnim_StartEffect18ScatterRadialAndColumnSequence, BattleAnim_EffectStartNop, func_843378CC,
    ParticleEffect_WaterAnimBurst, ParticleEffect_InitSetRotatingPaletteNoTint, ParticleEffect_InitSmokeSetWithMarker, ParticleEffect_PaletteScriptBurst, BattleAnim_EffectStartNop, BattleAnim_StartEffect26TintDescriptor53ScalePulse, BattleAnim_EffectStartNop,
    ParticleEffect_RegisterEffectE0, ParticleEffect_GroupSetupTintAndDefaultBurst, ParticleEffect_FinalGroupSetup, ParticleEffect_ComplexNodeSetup, BattleAnim_EffectStartNop, BattleAnim_EffectStartNop, ParticleEffect_RegisterSparkle,
    ParticleEffect_InitSmokeSetTexture1, ParticleEffect_BasicMultiBurstDelayedSprayOnly, ParticleEffect_SimpleBurstScript, ParticleEffect_RegisterExplosion, InitParticleEffectSet_WithFade, ParticleEffect_RegisterLargeExplosion, ParticleEffect_TextureSetup,
    BattleAnim_EffectStartNop, BattleAnim_EffectStartNop, BattleAnim_EffectStartNop, ParticleEffect_SetMode, BattleAnim_EffectStartNop, BattleAnim_StartEffect47TintDescriptor53ScalePulseAndDescriptor4AFade, BattleAnim_SpawnTimedFireballEffect,
    ParticleEffect_SimpleNodeEntry, BattleAnim_StartEffects50And82TintRampAndModelScaleFade, BattleAnim_EffectStartNop, BattleAnim_StartEffect52ModelAnim, BattleAnim_StartEffect53Descriptor33FadeAndDescriptor47ScaleMotion, BattleAnim_EffectStartNop, BattleAnim_StartEffect55ModelAnimWaitMarkerSlotAndScaleFall,
    ParticleEffect_AdditionalNodeSetup, ParticleEffect_SmallNodeSetupGlobalTintFade17, InitExplosionEffectSet, BattleAnim_CreateStreamSprayColumnEffect, ParticleEffect_GroupSetupTintAndDefaultBurst, ParticleEffect_HandleStateSetup, BattleAnim_EffectStartNop,
    ParticleEffect_RegisterHandlers_Default, BattleAnim_StartEffect64ModelAnimWait, ParticleEffect_RegisterParticleNodes, ParticleEffect_RegisterMultipleHandlers, BattleAnim_EffectStartNop, BattleAnim_StartEffect68ModelAnimWaitAndDescriptor42ScaleFall, BattleAnim_StartEffect69ModelPhaseWaitAndFallingParticles,
    InitParticleEffectSet_WithDifferentTiming, BattleAnim_StartEffect71SpecialModelColorCycle, BattleAnim_StartEffect72ModelAnimWait, BattleAnim_CreateCollisionRandomEffect, BattleAnim_StartEffect74SpecialModelColorCycle, ParticleEffect_RegisterHandlers_Alternate, BattleAnim_StartEffect76Descriptor33FadeAndDescriptor47ScaleMotion,
    InitSmallGlowEffectSet, InitParticleEffectSet_Single, BattleAnim_StartEffect79ModelAnimWaitAndDescriptor25AlphaFade, ParticleEffect_RegisterDefaultTexture, ParticleEffect_AdvancedModeSetup, BattleAnim_StartEffects50And82TintRampAndModelScaleFade, ParticleEffect_SimpleBurst,
    ParticleEffect_InitSmokeSetLongDuration, ParticleEffect_FinalSetupSpiralAndVerticalFade, ParticleEffect_RegisterLargeExplosionAndEffects, BattleAnim_StartEffect87ModelTintAlphaFadeAndVerticalFade, ParticleEffect_MultiNodeEffect88Palette7, ParticleEffect_MultiNodeD, ParticleEffect_PortraitBurst,
    ParticleEffect_PortraitBurstNode, ParticleEffect_PortraitBurstCheck, ParticleEffect_WaterAnimFirework, ParticleEffect_SimpleBurstAnimWaitDelayedTintFade, ParticleEffect_PaletteMultiBurstCleanupWithTintFade, ParticleEffect_PaletteBurstVariant4Model8D, ParticleEffect_PaletteBurstVariant2Model8EDelayedFadeOut,
    BattleAnim_EffectStartNop, ParticleEffect_BasicMultiBurst, ParticleEffect_SimpleBurstAnimWaitDelayedAlphaFadeOut, ParticleEffect_RotationEntry, BattleAnim_DisableEffectSpawningAlias, ParticleEffect_InitSmoke, ParticleEffect_InitFire,
    ParticleEffect_TriggerSpecial, ParticleEffect_AlphaBurst, ParticleEffect_AlphaBurstPalette17, ParticleEffect_AdditionalSetupDualRiseFade, ParticleEffect_SimpleGroupSetup, ParticleEffect_ComplexGroupSetup, BattleAnim_StartEffect111GlobalTintAndSpecialModelColorCycle,
    ParticleEffect_PortraitBurstInit, ParticleEffect_TriggerDefaultPalette1B, ParticleEffect_FinalSetupRiseAndVerticalFade, ParticleEffect_FinalSetupPortraitBurst, ParticleEffect_AdditionalNodeSingleRiseFade, ParticleEffect_StateCollisionSetupDesc29ScaleAnimFade, ParticleEffect_CreateWithCallback,
    ParticleEffect_CreateCallback, InitSmallGlowEffectSet, ParticleEffect_TriggerDefaultPalette1BWithTintFade, BattleAnim_StartEffect122GlobalAndOwnerTintFade, ParticleEffect_ConditionalStateSetup, ParticleEffect_CollisionResponseSwitch, ParticleEffect_RegisterCallbacks,
    func_8433765C, BattleAnim_StartEffect127Descriptor39ScaleFade, BattleAnim_StartEffect128Descriptor39ScaleFade, ParticleEffect_CreateTypeX, ParticleEffect_CreateSmoke, ParticleEffect_CreateSmokeHighPriority, ParticleEffect_CreateDual,
    BattleAnim_StartEffect133ModeOrbitBurstAndEffect135Followup, BattleAnim_StartEffect134ModeOrbitAndMetadataBurst, BattleAnim_StartEffect135ExpandingFlashAndRisingScaleFade, BattleAnim_EffectStartNop, BattleAnim_StartEffect137Descriptor3FRisingFade, ParticleEffect_TextureNodeSetup, BattleAnim_StartEffect139DualRepeatingSparks,
    BattleAnim_StartEffect140StartEffect139Alias, BattleAnim_StartEffect141GridRiseAndFallingBurst, BattleAnim_StartEffect142StartEffect141Alias, BattleAnim_StartEffect143ModeOrbitAndMetadataBurst, BattleAnim_EffectStartNop,
};
static func_D_84390320 sMoveAnimEffectEndInitFuncs[] = {
    BattleAnim_EffectEndNop, BattleAnim_EffectEndNop, InitComplexParticleSequence, ParticleEffect_SpecialCollisionSetup, ParticleEffect_MultiTextureSetup, ParticleEffect_DynamicCollisionSetup, ParticleEffect_RegisterPaletteVariants,
    ParticleEffect_PaletteMultiBurst, BattleAnim_CreateSprayColumnEffect, BattleAnim_EffectEndNop, ParticleEffect_RegisterAnimationCallbacks, BattleAnim_EffectEndNop, BattleAnim_EffectEndNop, ParticleEffect_RegisterSpecific,
    ParticleEffect_InitializeGroup, ParticleEffect_InitExplosionSetTintPalette35, ParticleEffect_AdvancedMultiBurst, ParticleEffect_RegisterSmoke, ParticleEffect_ModeSpecificSetup, BattleAnim_EffectEndNop, InitParticleComboVariant,
    ParticleEffect_RegisterModeSpecific, ParticleEffect_InitExplosionSet, ParticleEffect_RegisterAll, BattleAnim_EffectEndNop, ParticleEffect_PlaySoundAndReset, RegisterParticleEffect_ComplexMovement, InitAdvancedParticleCombo,
    BattleAnim_CreateBurstStreamEffect, ParticleEffect_InitFireSet, ParticleEffect_HandleCollisionSetup, ParticleEffect_RegisterMultiple, BattleAnim_EffectEndNop, BattleAnim_EffectEndNop, InitParticleEffectGroup_Basic,
    ParticleEffect_ConfigTexture7Palette1, ParticleEffect_ConfigTexture9Palette2, ParticleEffect_SpecialSetupBurstPalette3, ParticleEffect_SpecialSetupBurstPalette4, ParticleEffect_AdditionalSetupBurstAndRiseFade, ParticleEffect_InitSparkleSet, BattleAnim_EndEffect41Descriptor34Burst,
    ParticleEffect_ModeSetup, ParticleEffect_CollisionSetup, ParticleEffect_ConfigVariantMotion6, ParticleEffect_CombinedSetupBurst3DRandom, ParticleEffect_CombinedSetupBurstHorizontalRandom, ParticleEffect_SpecialSetupDelayedScatterPalette1, BattleAnim_EffectEndNop,
    ParticleEffect_RegisterColorAnim, ParticleEffect_RegisterHandler_WithParticleData, ParticleEffect_WaterAnimBurstTintFadeOnly, ParticleEffect_MultiHandleSetup, InitParticleEffectSet_WithCustomCallback, ParticleEffect_InitSetTintRampDelayedColorFade, ParticleEffect_SimpleNodeSetup,
    ParticleEffect_InitSetTintRampRisingSpread, ParticleEffect_FullSetupTintFadeOutAndRestore, BattleAnim_EndEffect58ModelAnimAndDescriptorSequence, ParticleEffect_InitCombinedSet, ParticleEffect_WaterAnimFireworkModel42RotationFollow, ParticleEffect_SimpleBurstTintPulseAnimWaitPaletteC, ParticleEffect_PaletteMultiBurstNoCleanupNoTintFade,
    ParticleEffect_FireworkBurst, ParticleEffect_FireballBurst, ParticleEffect_FireworkEntry, ParticleEffect_SimpleNodeBurst, InitParticleEffectSet_WithMultiple, InitParticleEffectSet_WithTimedFireball, BattleAnim_EndEffect69PaletteRotateWithExpandingHoldFade,
    InitParticleEffectSet_WithComplex, BattleAnim_EndEffect71PaletteApproachWithExpandingScaleFades, BattleAnim_CreateSprayColumnEffectTrigger, ParticleEffect_AlphaFireworkPalette17, ParticleEffect_AlphaFirework, ParticleEffect_MultiNodeAEntry, ParticleEffect_TriggerAnother,
    ParticleEffect_TriggerDefaultPalette1C, BattleAnim_EndEffect78ModelAnimDelayedMotionAndFallingParticles, ParticleEffect_CreateColorVariant, ParticleEffect_ConfigVariantMotion16, BattleAnim_EndEffects81And82TintRampAndModelScaleFade, BattleAnim_EndEffects81And82TintRampAndModelScaleFade, BattleAnim_EndEffect83TintRampAndDescriptor34Burst,
    ParticleEffect_TriggerDefaultPalette1CWithTintRamps, ParticleEffect_StateCollisionSetupDesc2BGravityFall, InitParticleEffectSet_ThreeInstances, RegisterParticleEffect_Burst, ParticleEffect_CollisionAndBurstSetup, BattleAnim_EffectEndNop,
};
static u8 sBattleScript_LoadGfxEmpty[] = {
    0x3F, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00,
    0x3F, 0x00, 0x00, 0x00, 0x01, 0x3F, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00,

};
static u8 sBattleScript_LoadGfx03[] = {
    0x03,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxSkullBash[] = {
    0x04,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxGrowth[] = {
    0x05,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfx06[] = {
    0x06,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxGustAndWhirlwind[] = {
    0x09,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxVineWhipFamily[] = {
    0x0A,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfx0B[] = {
    0x0B,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxHazeAndLightScreen[] = {
    0x0C, 0x3F, 0x00, 0x00, 0x0D, 0x3F, 0x00, 0x00,

};
static u8 sBattleScript_LoadGfx0E[] = {
    0x0E,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxThunderFamily[] = {
    0x0F,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfx10[] = {
    0x10,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfx11[] = {
    0x11,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxThunderShock[] = {
    0x11,
    0x3D,
    0x3F,
    0x00,

};
static u8 sBattleScript_LoadGfxAbsorbAndEarthquakeAndHyperFang[] = {
    0x12,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxLeechSeedAndLovelyKissAndMegaDrain[] = {
    0x13,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxBarrageAndConfuseRayAndSludge[] = {
    0x14, 0x3F, 0x00, 0x00, 0x15, 0x3F, 0x00, 0x00,

};
static u8 sBattleScript_LoadGfxSandAttack[] = {
    0x16, 0x3F, 0x00, 0x00, 0x17, 0x3F, 0x00, 0x00,

};
static u8 sBattleScript_LoadGfx18[] = {
    0x18,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxPsybeam[] = {
    0x19,
    0x32,
    0x3F,
    0x00,

};
static u8 sBattleScript_LoadGfxIceBeam[] = {
    0x1A,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxDigAndFissure[] = {
    0x1B,
    0x27,
    0x3F,
    0x00,

};
static u8 sBattleScript_LoadGfxThunder[] = {
    0x1C,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxPeck[] = {
    0x27,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868AC[] = {
    0x1E,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_AnimAttack[] = {
    0x1F,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxDoubleTeamAndMeditate[] = {
    0x20,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_AnimHit[] = {
    0x21,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_AnimMiss[] = {
    0x22,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_AnimFaint[] = {
    0x23, 0x3F, 0x00, 0x00, 0x24, 0x3F, 0x00, 0x00,

};
static u8 sBattleScript_LoadGfxPowderFamily[] = {
    0x25,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfx26_11[] = {
    0x26,
    0x11,
    0x3F,
    0x00,

};
static u8 sBattleScript_LoadGfxEggBombAndFurySwipes[] = {
    0x27,
    0x32,
    0x3F,
    0x00,

};
static u8 sBattleScript_LoadGfxToxic[] = {
    0x28,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfx29_03[] = {
    0x29,
    0x03,
    0x3F,
    0x00,

};
static u8 sBattleScript_LoadGfxSoftBoiled[] = {
    0x2A,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxTransform[] = {
    0x2B,
    0x11,
    0x3F,
    0x00,

};
static u8 sBattleScript_LoadGfxPayDay[] = {
    0x17,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxRazorWindAlt[] = {
    0x09,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxRazorWindAlt2[] = {
    0x0B, 0x3F, 0x00, 0x00, 0x0E, 0x3F, 0x00, 0x00,

};
static u8 sBattleScript_LoadGfxWaterGunAlt[] = {
    0x14,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxPoisonPowder[] = {
    0x15,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxNightShade[] = {
    0x1E,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxWithdrawAlt[] = {
    0x10,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxReflectAlt2[] = {
    0x14,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxFocusEnergyAlt[] = {
    0x0C,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxHighJumpKickAndLick[] = {
    0x07,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxPoisonGas[] = {
    0x36,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxSpore[] = {
    0x18,
    0x0D,
    0x3F,
    0x00,

};
static u8 sBattleScript_LoadGfxSuperFangAlt[] = {
    0x03, 0x3F, 0x00, 0x00, 0x14, 0x3F, 0x00, 0x00,

};
static u8 sBattleScript_LoadGfx2C[] = {
    0x2C,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfx2C_Alt[] = {
    0x2C,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfx3C[] = {
    0x3C,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfx2D[] = {
    0x2D,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfx08[] = {
    0x08,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxSwordsDance[] = {
    0x2E,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxFireBlastAndRest[] = {
    0x2F,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxDreamEaterAndLeer[] = {
    0x30,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxBarrierAndConversion[] = {
    0x31,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfx32[] = {
    0x32,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxDefenseCurl[] = {
    0x33,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxSmog[] = {
    0x34,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxSkyAttack[] = {
    0x35,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxAgility[] = {
    0x37,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxMimic[] = {
    0x38,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxClamp[] = {
    0x39,
    0x3F,
    0x00,
    0x00,

};
static u8 sBattleScript_LoadGfxExplosion[] = {
    0x3A,
    0x0B,
    0x3F,
    0x00,

};
static u8 sBattleScript_LoadGfxLeechLife[] = {
    0x3B,
    0x2C,
    0x3F,
    0x00,

};
static u8 sBattleScript_StartEmpty[] = {
    0x00, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00,

};
static u8 sBattleScript_Start90Nop[] = {
    0x90,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start01Descriptor2FPhaseFadeOut[] = {
    0x01,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start02Descriptor08IndexedScaleDelayFade[] = {
    0x02,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start03ModelTintAndVerticalFade[] = {
    0x03,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen04TintDescriptor53ScalePulse[] = {
    0x66, 0x04, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,

};
static u8 sBattleScript_Start06AnimatedScaleAndBurstEmitter[] = {
    0x06,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start3AInitExplosionEffectSet[] = {
    0x3A,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen07TexturedRibbonSheet[] = {
    0x66,
    0x07,
    0x00,
    0x00,

};
static u8 sBattleScript_Start08ModelBurstAndVerticalFade[] = {
    0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,

};
static u8 sBattleScript_Start0AModel60AndModelAnimWait[] = {
    0x0A,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen0BGlobalTintFade[] = {
    0x66, 0x0B, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,

};
static u8 sBattleScript_Start0DSecondaryOwnerSpeciesBranch[] = {
    0x0D,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start7BConditionalStateSetup[] = {
    0x7B,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start7CCollisionResponseSwitch[] = {
    0x7C,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start0EModelAnimAndMoveKeyedTintParticles[] = {
    0x0E,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start0FDescriptor08IndexedScaleDelayFade[] = {
    0x0F,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start10TintDescriptor34Sequence[] = {
    0x10,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start11ModelAnimFinish[] = {
    0x11,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start12ScatterRadialAndColumnSequence[] = {
    0x12,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start13Radial20[] = {
    0x13, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,

};
static u8 sBattleScript_Start15WaterAnimBurst[] = {
    0x15,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start16InitSetA[] = {
    0x16,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start17InitSmokeSetA[] = {
    0x17,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start18PaletteScriptBurst[] = {
    0x18,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start19Nop[] = {
    0x19, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00,

};
static u8 sBattleScript_Start1CRegisterEffectE0[] = {
    0x1C,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start4CRegisterEffectE0Alt[] = {
    0x4C,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start1DGroupSetupA[] = {
    0x1D, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00,

};
static u8 sBattleScript_Start1FComplexNodeSetup[] = {
    0x1F,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start20Nop[] = {
    0x20,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start21Radial20[] = {
    0x21,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start22RegisterSparkle[] = {
    0x22,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start23InitSmokeSetB[] = {
    0x23,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen24TerrainGrid[] = {
    0x66,
    0x24,
    0x00,
    0x00,

};
static u8 sBattleScript_Start25SimpleBurstScript[] = {
    0x25,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start26RegisterExplosion[] = {
    0x26,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen27InitSetWithFade[] = {
    0x66,
    0x27,
    0x00,
    0x00,

};
static u8 sBattleScript_Start28RegisterLargeExplosion[] = {
    0x28,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start29TextureSetup[] = {
    0x29,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen2ATrail40[] = {
    0x66,
    0x2A,
    0x00,
    0x00,

};
static u8 sBattleScript_Start2BTrail40Variant[] = {
    0x2B,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start2CTrail40GridAlt[] = {
    0x2C,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen2DSetMode[] = {
    0x66, 0x2D, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00,

};
static u8 sBattleScript_NoSpawnThen2FInitSetWithTexture53[] = {
    0x66,
    0x2F,
    0x00,
    0x00,

};
static u8 sBattleScript_Start30TimedFireball[] = {
    0x30,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start31SimpleNodeEntry[] = {
    0x31,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start32RegisterAll48630[] = {
    0x32,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start52RegisterAll48630[] = {
    0x52,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start59MultiNodeD[] = {
    0x59,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start34RegisterHandler49628[] = {
    0x34, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00,

};
static u8 sBattleScript_Start37RegisterHandler49830[] = {
    0x37,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start35RegisterEffectE0Alt2_05RibbonMesh[] = {
    0x35,
    0x05,
    0x00,
    0x00,

};
static u8 sBattleScript_Start6AAlphaBurst[] = {
    0x6A,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start6BAlphaBurst2[] = {
    0x6B,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start1BNop[] = {
    0x1B,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start56RegisterLargeExplosionAndEffects[] = {
    0x56,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start1EFinalGroupSetup[] = {
    0x1E,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start5DWaterAnimFirework[] = {
    0x5D,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start1CRegisterEffectE0_36RibbonMesh[] = {
    0x1C,
    0x36,
    0x00,
    0x00,

};
static u8 sBattleScript_Start0EModelAnimAndMoveKeyedTintParticles_Alt[] = {
    0x0E,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start40RegisterHandler416B0[] = {
    0x40,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start0CDelayedModelAnim[] = {
    0x0C,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start42RegisterMultipleHandlers[] = {
    0x42,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start5FPaletteMultiBurst2[] = {
    0x5F,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen4EInitSetSingle[] = {
    0x66,
    0x4E,
    0x00,
    0x00,

};
static u8 sBattleScript_Start3BCreateStreamSprayColumnEffect[] = {
    0x3B,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start38AdditionalNodeSetup[] = {
    0x38,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen39SmallNodeSetupB[] = {
    0x66,
    0x39,
    0x00,
    0x00,

};
static u8 sBattleScript_Start3DHandleStateSetup[] = {
    0x3D,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start3EOwnerLinkedFourStream[] = {
    0x3E,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start7DRegisterCallbacks[] = {
    0x7D,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start7ESpecial[] = {
    0x7E,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start7FCreateVariant45[] = {
    0x7F,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start80CreateVariant47[] = {
    0x80,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start81CreateTypeX[] = {
    0x81,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start82CreateSmoke[] = {
    0x82,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start83CreateSmokeHighPriority[] = {
    0x83,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start84CreateDual[] = {
    0x84,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start8BDualRepeatingSparks[] = {
    0x8B,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start8CDualRepeatingSparksAlias[] = {
    0x8C,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start8DGridRiseAndFallingBurst[] = {
    0x8D,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start8EGridRiseAndFallingBurstAlias[] = {
    0x8E,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start85ModeOrbitBurstAndFollowup[] = {
    0x85,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start86ModeOrbitAndMetadataBurst[] = {
    0x86,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start8FModeOrbitAndMetadataBurst[] = {
    0x8F,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start87ExpandingFlashAndRisingScaleFade[] = {
    0x87,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start88Nop[] = {
    0x88,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start89Descriptor3FRisingFade[] = {
    0x89,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start8ATextureNodeSetup[] = {
    0x8A,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start3FRegisterHandlersDefault[] = {
    0x3F,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start41RegisterParticleNodes[] = {
    0x41,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start43OwnerAnchoredFourStream[] = {
    0x43,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start71TriggerDefault1[] = {
    0x71,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start79TriggerDefault3[] = {
    0x79,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start44RegisterHandler49384[] = {
    0x44,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start45RegisterHandlers49504[] = {
    0x45,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen46InitSetWithDifferentTiming[] = {
    0x66,
    0x46,
    0x00,
    0x00,

};
static u8 sBattleScript_Start47RegisterHandler49058[] = {
    0x47,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start6FRegisterHandler490A8[] = {
    0x6F,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start48RegisterHandler47448[] = {
    0x48,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start49CreateCollisionRandomEffect[] = {
    0x49,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start4ARegisterHandler49108[] = {
    0x4A,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start4BRegisterHandlersAlternate[] = {
    0x4B,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen78InitSmallGlowEffectSet[] = {
    0x66,
    0x78,
    0x00,
    0x00,

};
static u8 sBattleScript_Start4FRegisterHandler498D8[] = {
    0x4F,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start50RegisterDefaultTexture[] = {
    0x50,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start51AdvancedModeSetup[] = {
    0x51,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start53SimpleBurst[] = {
    0x53,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start54InitSmokeSetC[] = {
    0x54,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start55FinalSetupA[] = {
    0x55,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start72FinalSetupB[] = {
    0x72,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start73FinalSetupC[] = {
    0x73,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start74AdditionalNodeA[] = {
    0x74,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start57_ModelTintAlphaFade[] = {
    0x57,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start58MultiNodeC2[] = {
    0x58,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start59MultiNodeD_Alt[] = {
    0x59,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start5APortraitBurst[] = {
    0x5A,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start5BPortraitBurstNode[] = {
    0x5B,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start5CPortraitBurstCheck[] = {
    0x5C,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start5ESimpleBurst2[] = {
    0x5E,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start60PaletteBurst4[] = {
    0x60,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start61PaletteBurst5[] = {
    0x61,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start62Radial20[] = {
    0x62,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start63BasicMultiBurst[] = {
    0x63,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start64SimpleBurst4[] = {
    0x64,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start65RotationEntry[] = {
    0x65,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_NoSpawnThen1AInitSetAlt2[] = {
    0x66,
    0x1A,
    0x00,
    0x00,

};
static u8 sBattleScript_Start67InitSmoke[] = {
    0x67,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start68InitFire[] = {
    0x68,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start69TriggerSpecial[] = {
    0x69,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start6CAdditionalSetupA[] = {
    0x6C,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start6DSimpleGroupSetup[] = {
    0x6D,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start6EComplexGroupSetup[] = {
    0x6E,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start70PortraitBurstInit[] = {
    0x70,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start75StateCollisionSetupA[] = {
    0x75,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start76CreateWithCallback[] = {
    0x76,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start77CreateCallback[] = {
    0x77,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_Start7AGlobalAndOwnerTintFade[] = {
    0x7A,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_EndEmpty[] = {
    0x00, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, 0x00,

};
static u8 sBattleScript_MsgStart[] = {
    0x01,
    0x00,
    0x00,
    0x00,

};
static u8 sBattleScript_MsgEnd[] = {
    0x30, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,

};
static u8 gBattleScript_End04_MultiTextureSetup[] = {
    0x04,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End05_DynamicCollisionSetup[] = {
    0x05,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End58_CollisionAndBurstSetup[] = {
    0x58, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,

};
static u8 gBattleScript_End07_PaletteMultiBurst[] = {
    0x07,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End08_SprayColumnEffect[] = {
    0x08,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End48_SprayColumnEffectTrigger[] = {
    0x48,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End09_Radial20[] = {
    0x09,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End0A_RegisterAnimationCallbacks[] = {
    0x0A, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00,

};
static u8 gBattleScript_End0E_InitializeGroup[] = {
    0x0E,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End23_ConfigTexture7Palette1[] = {
    0x23,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End24_ConfigTexture9Palette2[] = {
    0x24,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End25_SpecialSetupBurstPalette3[] = {
    0x25,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End_TintRampsWithBurstEmitter[] = {
    0x54,
    0x25,
    0x00,
    0x00,

};
static u8 gBattleScript_End_PaletteTintWithMotionGroup[] = {
    0x4D,
    0x0E,
    0x00,
    0x00,

};
static u8 gBattleScript_End26_SpecialSetupBurstPalette4[] = {
    0x26,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End0F_ExplosionSetTintPalette35[] = {
    0x0F,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End10_AdvancedMultiBurst[] = {
    0x10,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End11_RegisterSmoke[] = {
    0x11,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End12_ModeSpecificSetup[] = {
    0x12, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,

};
static u8 gBattleScript_End15_RegisterModeSpecific[] = {
    0x15,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End16_ExplosionSet[] = {
    0x16,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End17_RegisterAll[] = {
    0x17,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End18_NoOp[] = {
    0x18,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End19_PlaySoundAndReset[] = {
    0x19,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End_SpecificEffectWithMotionGroup[] = {
    0x0D,
    0x0E,
    0x00,
    0x00,

};
static u8 gBattleScript_End03_SpecialCollisionSetup[] = {
    0x03,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End07_PaletteMultiBurst_Alt[] = {
    0x07,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End22_InitParticleGroupBasic[] = {
    0x22,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End35_SetWithCustomCallback[] = {
    0x35,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End45_SetVariant2[] = {
    0x45, 0x00, 0x00, 0x00, 0x0E, 0x04, 0x00, 0x00,

};
static u8 gBattleScript_End1A_ComplexMovement[] = {
    0x1A,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End09_Radial20_Alt[] = {
    0x09,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End_PaletteVariantsWithMotionGroup[] = {
    0x06,
    0x0E,
    0x00,
    0x00,

};
static u8 gBattleScript_End1B_AdvancedParticleCombo[] = {
    0x1B, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00,

};
static u8 gBattleScript_End1D_FireSet[] = {
    0x1D,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End1E_HandleCollisionSetup[] = {
    0x1E,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End55_StateCollisionSetupDesc2BGravityFall[] = {
    0x55,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End1F_RegisterMultiple[] = {
    0x1F,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End20_Radial20[] = {
    0x20,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End21_Radial20[] = {
    0x21,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End_ColorVariantWithBurstAndRiseFade[] = {
    0x4F,
    0x27,
    0x00,
    0x00,

};
static u8 gBattleScript_End28_SparkleSet[] = {
    0x28,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End29_Trigger56A74[] = {
    0x29,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End2A_ModeSetup[] = {
    0x2A,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End2B_CollisionSetup[] = {
    0x2B,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End2C_ConfigVariantMotion6[] = {
    0x2C,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End2D_CombinedSetupBurst3DRandom[] = {
    0x2D,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End_ColorVariantWithCombinedSetup[] = {
    0x4F,
    0x2D,
    0x00,
    0x00,

};
static u8 gBattleScript_End2E_CombinedSetupBurstHorizontalRandom[] = {
    0x2E,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End2F_SpecialSetupDelayedScatterPalette1[] = {
    0x2F,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End31_RegisterColorAnim[] = {
    0x31,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End32_RegisterHandlerWithParticleData[] = {
    0x32,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End_FireworkWithConfigB[] = {
    0x3F, 0x23, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00,

};
static u8 gBattleScript_End34_MultiHandleSetup[] = {
    0x34,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End36_InitSetTintRampDelayedColorFade[] = {
    0x36,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End37_SimpleNodeSetup[] = {
    0x37,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End39_FullSetupTintFadeOutAndRestore[] = {
    0x39,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End49_AlphaFirework2[] = {
    0x49,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End4A_AlphaFirework[] = {
    0x4A,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End3A_ModelAnimAndDescriptorSequence[] = {
    0x3A,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End4B_MultiNodeAEntry[] = {
    0x4B,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End3B_InitCombinedSet[] = {
    0x3B,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End3C_WaterAnimFirework2[] = {
    0x3C,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End3D_SimpleBurst3[] = {
    0x3D,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End3E_PaletteMultiBurst3[] = {
    0x3E,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End40_FireballBurst[] = {
    0x40,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End_CombinedSetupWithCollision[] = {
    0x2D,
    0x1E,
    0x00,
    0x00,

};
static u8 gBattleScript_End41_FireworkEntry[] = {
    0x41,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End42_SimpleNodeBurst[] = {
    0x42,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End43_SetWithMultiple[] = {
    0x43,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End44_SetWithTimedFireball[] = {
    0x44,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End46_SetWithComplex[] = {
    0x46,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End47_SetVariant3[] = {
    0x47,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End_ConfigVariantWithFollowup[] = {
    0x50,
    0x4C,
    0x00,
    0x00,

};
static u8 gBattleScript_End38_InitSetTintRampRisingSpread[] = {
    0x38, 0x00, 0x00, 0x00, 0x4D, 0x00, 0x00, 0x00,

};
static u8 gBattleScript_End4E_RegisterModelAnimAndFallingParticles[] = {
    0x4E, 0x00, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x00,

};
static u8 gBattleScript_End51_RegisterAllTintRampAndModelScaleFade[] = {
    0x51,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End52_RegisterAllTintRampAndModelScaleFade[] = {
    0x52,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End02_ComplexParticleSequence[] = {
    0x02,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End56_ThreeInstanceSet[] = {
    0x56,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End53_TintRampAndDescriptorBurst[] = {
    0x53,
    0x00,
    0x00,
    0x00,

};
static u8 gBattleScript_End_ModelTintWithConfigB[] = {
    0x57,
    0x23,
    0x00,
    0x00,
};
static u8* D_84386D44[][2] = {
    {
        sBattleScript_StartEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start85ModeOrbitBurstAndFollowup,
        sBattleScript_LoadGfx2C,
    },
    {
        sBattleScript_Start86ModeOrbitAndMetadataBurst,
        sBattleScript_LoadGfx2C,
    },
    {
        sBattleScript_Start87ExpandingFlashAndRisingScaleFade,
        sBattleScript_LoadGfx2C_Alt,
    },
    {
        sBattleScript_Start88Nop,
        sBattleScript_LoadGfx2C_Alt,
    },
    {
        sBattleScript_Start89Descriptor3FRisingFade,
        sBattleScript_LoadGfx2D,
    },
    {
        sBattleScript_Start8ATextureNodeSetup,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start8BDualRepeatingSparks,
        sBattleScript_LoadGfx2C_Alt,
    },
    {
        sBattleScript_Start15WaterAnimBurst,
        sBattleScript_LoadGfx10,
    },
    {
        sBattleScript_Start8CDualRepeatingSparksAlias,
        sBattleScript_LoadGfx3C,
    },
    {
        sBattleScript_Start8DGridRiseAndFallingBurst,
        sBattleScript_LoadGfx3C,
    },
    {
        sBattleScript_Start8FModeOrbitAndMetadataBurst,
        sBattleScript_LoadGfx2C,
    },
    {
        sBattleScript_Start8EGridRiseAndFallingBurstAlias,
        sBattleScript_LoadGfx3C,
    },
    {
        sBattleScript_Start7AGlobalAndOwnerTintFade,
        sBattleScript_LoadGfxEmpty,
    },
};
static u8* sBattleAnimMode4StartEffectLists[] = {
    sBattleScript_StartEmpty, sBattleScript_Start7DRegisterCallbacks, sBattleScript_Start7ESpecial, sBattleScript_Start01Descriptor2FPhaseFadeOut, sBattleScript_Start45RegisterHandlers49504, sBattleScript_Start7FCreateVariant45,
    sBattleScript_Start80CreateVariant47, sBattleScript_Start81CreateTypeX, sBattleScript_Start82CreateSmoke, sBattleScript_Start83CreateSmokeHighPriority, sBattleScript_Start84CreateDual, sBattleScript_Start90Nop,
};
static u8* D_84386DEC[] = {
    sBattleScript_EndEmpty, sBattleScript_MsgStart, gBattleScript_End09_Radial20, sBattleScript_MsgEnd, gBattleScript_End31_RegisterColorAnim,
};
static u8* sBattleAnimMode9StartEffectLists[] = { sBattleScript_StartEmpty, sBattleScript_Start2CTrail40GridAlt };
static u8* sMoveAnimEffectScripts[][5] = {
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End0E_InitializeGroup,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End23_ConfigTexture7Palette1,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start0FDescriptor08IndexedScaleDelayFade,
        sBattleScript_StartEmpty,
        gBattleScript_End_ConfigVariantWithFollowup,
        sBattleScript_LoadGfx03,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End_SpecificEffectWithMotionGroup,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxPayDay,
    },
    {
        sBattleScript_Start38AdditionalNodeSetup,
        sBattleScript_StartEmpty,
        gBattleScript_End36_InitSetTintRampDelayedColorFade,
        sBattleScript_LoadGfx11,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start29TextureSetup,
        sBattleScript_StartEmpty,
        gBattleScript_End2A_ModeSetup,
        sBattleScript_AnimAttack,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start49CreateCollisionRandomEffect,
        sBattleScript_StartEmpty,
        gBattleScript_End2B_CollisionSetup,
        sBattleScript_LoadGfxThunderFamily,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start0DSecondaryOwnerSpeciesBranch,
        sBattleScript_StartEmpty,
        gBattleScript_End05_DynamicCollisionSetup,
        sBattleScript_LoadGfx0B,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start47RegisterHandler49058,
        sBattleScript_StartEmpty,
        gBattleScript_End29_Trigger56A74,
        sBattleScript_LoadGfx08,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start6FRegisterHandler490A8,
        sBattleScript_StartEmpty,
        gBattleScript_End53_TintRampAndDescriptorBurst,
        sBattleScript_LoadGfx08,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start0AModel60AndModelAnimWait,
        sBattleScript_Start48RegisterHandler47448,
        gBattleScript_End03_SpecialCollisionSetup,
        sBattleScript_LoadGfxRazorWindAlt,
        sBattleScript_LoadGfxRazorWindAlt2,
    },
    {
        sBattleScript_Start44RegisterHandler49384,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxSwordsDance,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start3DHandleStateSetup,
        sBattleScript_StartEmpty,
        gBattleScript_End1E_HandleCollisionSetup,
        sBattleScript_LoadGfx0B,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start0AModel60AndModelAnimWait,
        sBattleScript_StartEmpty,
        gBattleScript_End2F_SpecialSetupDelayedScatterPalette1,
        sBattleScript_LoadGfxGustAndWhirlwind,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End_ModelTintWithConfigB,
        sBattleScript_LoadGfxVineWhipFamily,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start0AModel60AndModelAnimWait,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxGustAndWhirlwind,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_Start28RegisterLargeExplosion,
        gBattleScript_End_ColorVariantWithCombinedSetup,
        D_843868AC,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start13Radial20,
        sBattleScript_StartEmpty,
        gBattleScript_End09_Radial20,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End2D_CombinedSetupBurst3DRandom,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start75StateCollisionSetupA,
        sBattleScript_StartEmpty,
        gBattleScript_End55_StateCollisionSetupDesc2BGravityFall,
        sBattleScript_LoadGfx0B,
        sBattleScript_LoadGfxVineWhipFamily,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End_ColorVariantWithBurstAndRiseFade,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End23_ConfigTexture7Palette1,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start02Descriptor08IndexedScaleDelayFade,
        sBattleScript_StartEmpty,
        gBattleScript_End_ConfigVariantWithFollowup,
        sBattleScript_LoadGfx03,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start1FComplexNodeSetup,
        sBattleScript_StartEmpty,
        gBattleScript_End37_SimpleNodeSetup,
        sBattleScript_LoadGfxSandAttack,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End0E_InitializeGroup,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start77CreateCallback,
        sBattleScript_StartEmpty,
        gBattleScript_End25_SpecialSetupBurstPalette3,
        sBattleScript_LoadGfx06,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start76CreateWithCallback,
        sBattleScript_StartEmpty,
        gBattleScript_End2F_SpecialSetupDelayedScatterPalette1,
        sBattleScript_LoadGfx06,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start79TriggerDefault3,
        sBattleScript_StartEmpty,
        gBattleScript_End_TintRampsWithBurstEmitter,
        sBattleScript_LoadGfx06,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start74AdditionalNodeA,
        sBattleScript_StartEmpty,
        gBattleScript_End_ColorVariantWithCombinedSetup,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start13Radial20,
        sBattleScript_StartEmpty,
        gBattleScript_End09_Radial20,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start73FinalSetupC,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfx32,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start72FinalSetupB,
        sBattleScript_StartEmpty,
        gBattleScript_End2D_CombinedSetupBurst3DRandom,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start73FinalSetupC,
        sBattleScript_StartEmpty,
        gBattleScript_End2D_CombinedSetupBurst3DRandom,
        sBattleScript_LoadGfx32,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start43OwnerAnchoredFourStream,
        sBattleScript_StartEmpty,
        gBattleScript_End26_SpecialSetupBurstPalette4,
        sBattleScript_LoadGfx06,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start43OwnerAnchoredFourStream,
        sBattleScript_StartEmpty,
        gBattleScript_End26_SpecialSetupBurstPalette4,
        sBattleScript_LoadGfx06,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start43OwnerAnchoredFourStream,
        sBattleScript_StartEmpty,
        gBattleScript_End25_SpecialSetupBurstPalette3,
        sBattleScript_LoadGfx06,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start53SimpleBurst,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxDreamEaterAndLeer,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start4ARegisterHandler49108,
        sBattleScript_StartEmpty,
        gBattleScript_End29_Trigger56A74,
        sBattleScript_LoadGfx08,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start2BTrail40Variant,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_AnimHit,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start2CTrail40GridAlt,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_AnimMiss,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_NoSpawnThen2DSetMode,
        sBattleScript_StartEmpty,
        gBattleScript_End23_ConfigTexture7Palette1,
        sBattleScript_AnimFaint,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start62Radial20,
        sBattleScript_StartEmpty,
        gBattleScript_End21_Radial20,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start11ModelAnimFinish,
        sBattleScript_StartEmpty,
        gBattleScript_End07_PaletteMultiBurst_Alt,
        sBattleScript_LoadGfx0E,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start16InitSetA,
        sBattleScript_StartEmpty,
        gBattleScript_End38_InitSetTintRampRisingSpread,
        sBattleScript_LoadGfx11,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start17InitSmokeSetA,
        sBattleScript_StartEmpty,
        gBattleScript_End16_ExplosionSet,
        sBattleScript_LoadGfx11,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start35RegisterEffectE0Alt2_05RibbonMesh,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxWaterGunAlt,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start06AnimatedScaleAndBurstEmitter,
        sBattleScript_StartEmpty,
        gBattleScript_End02_ComplexParticleSequence,
        sBattleScript_LoadGfx03,
        sBattleScript_LoadGfx0E,
    },
    {
        sBattleScript_Start3AInitExplosionEffectSet,
        sBattleScript_StartEmpty,
        gBattleScript_End1B_AdvancedParticleCombo,
        sBattleScript_LoadGfx03,
        sBattleScript_LoadGfx0E,
    },
    {
        sBattleScript_NoSpawnThen24TerrainGrid,
        sBattleScript_StartEmpty,
        gBattleScript_End10_AdvancedMultiBurst,
        sBattleScript_LoadGfxIceBeam,
        sBattleScript_LoadGfx03,
    },
    {
        sBattleScript_NoSpawnThen2FInitSetWithTexture53,
        sBattleScript_StartEmpty,
        gBattleScript_End43_SetWithMultiple,
        sBattleScript_LoadGfx29_03,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start22RegisterSparkle,
        sBattleScript_StartEmpty,
        gBattleScript_End17_RegisterAll,
        sBattleScript_LoadGfxPsybeam,
        sBattleScript_LoadGfx03,
    },
    {
        sBattleScript_NoSpawnThen04TintDescriptor53ScalePulse,
        sBattleScript_StartEmpty,
        gBattleScript_End44_SetWithTimedFireball,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx29_03,
    },
    {
        sBattleScript_NoSpawnThen78InitSmallGlowEffectSet,
        sBattleScript_StartEmpty,
        gBattleScript_End35_SetWithCustomCallback,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx29_03,
    },
    {
        sBattleScript_NoSpawnThen1AInitSetAlt2,
        sBattleScript_StartEmpty,
        gBattleScript_End45_SetVariant2,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx29_03,
    },
    {
        sBattleScript_NoSpawnThen27InitSetWithFade,
        sBattleScript_StartEmpty,
        gBattleScript_End46_SetWithComplex,
        sBattleScript_LoadGfxPeck,
        sBattleScript_LoadGfx29_03,
    },
    {
        sBattleScript_Start76CreateWithCallback,
        sBattleScript_StartEmpty,
        gBattleScript_End25_SpecialSetupBurstPalette3,
        sBattleScript_LoadGfx06,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start71TriggerDefault1,
        sBattleScript_StartEmpty,
        gBattleScript_End_PaletteTintWithMotionGroup,
        sBattleScript_LoadGfx06,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start6CAdditionalSetupA,
        sBattleScript_StartEmpty,
        gBattleScript_End2E_CombinedSetupBurstHorizontalRandom,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End24_ConfigTexture9Palette2,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start19Nop,
        sBattleScript_StartEmpty,
        gBattleScript_End_ColorVariantWithCombinedSetup,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start4BRegisterHandlersAlternate,
        sBattleScript_StartEmpty,
        gBattleScript_End32_RegisterHandlerWithParticleData,
        sBattleScript_LoadGfxAbsorbAndEarthquakeAndHyperFang,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start18PaletteScriptBurst,
        sBattleScript_StartEmpty,
        gBattleScript_End15_RegisterModeSpecific,
        sBattleScript_LoadGfxLeechSeedAndLovelyKissAndMegaDrain,
        sBattleScript_LoadGfx26_11,
    },
    {
        sBattleScript_Start18PaletteScriptBurst,
        sBattleScript_StartEmpty,
        gBattleScript_End15_RegisterModeSpecific,
        sBattleScript_LoadGfxLeechSeedAndLovelyKissAndMegaDrain,
        sBattleScript_LoadGfx26_11,
    },
    {
        sBattleScript_Start08ModelBurstAndVerticalFade,
        sBattleScript_StartEmpty,
        gBattleScript_End1F_RegisterMultiple,
        sBattleScript_LoadGfxGrowth,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start6DSimpleGroupSetup,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_NoSpawnThen0BGlobalTintFade,
        sBattleScript_StartEmpty,
        gBattleScript_End04_MultiTextureSetup,
        sBattleScript_LoadGfxVineWhipFamily,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_NoSpawnThen46InitSetWithDifferentTiming,
        sBattleScript_Start69TriggerSpecial,
        gBattleScript_End47_SetVariant3,
        sBattleScript_LoadGfxPoisonPowder,
        sBattleScript_LoadGfx29_03,
    },
    {
        sBattleScript_Start41RegisterParticleNodes,
        sBattleScript_StartEmpty,
        gBattleScript_End12_ModeSpecificSetup,
        sBattleScript_LoadGfxPowderFamily,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start41RegisterParticleNodes,
        sBattleScript_StartEmpty,
        gBattleScript_End12_ModeSpecificSetup,
        sBattleScript_LoadGfxPowderFamily,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start41RegisterParticleNodes,
        sBattleScript_StartEmpty,
        gBattleScript_End12_ModeSpecificSetup,
        sBattleScript_LoadGfxPowderFamily,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_NoSpawnThen39SmallNodeSetupB,
        sBattleScript_StartEmpty,
        gBattleScript_End1A_ComplexMovement,
        sBattleScript_LoadGfxVineWhipFamily,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start21Radial20,
        sBattleScript_StartEmpty,
        gBattleScript_End20_Radial20,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start23InitSmokeSetB,
        sBattleScript_StartEmpty,
        gBattleScript_End0F_ExplosionSetTintPalette35,
        sBattleScript_LoadGfx11,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start54InitSmokeSetC,
        sBattleScript_StartEmpty,
        gBattleScript_End1D_FireSet,
        sBattleScript_LoadGfxThunderShock,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start3BCreateStreamSprayColumnEffect,
        sBattleScript_StartEmpty,
        gBattleScript_End08_SprayColumnEffect,
        sBattleScript_LoadGfxThunderFamily,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start12ScatterRadialAndColumnSequence,
        sBattleScript_StartEmpty,
        gBattleScript_End08_SprayColumnEffect,
        sBattleScript_LoadGfxThunderFamily,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start26RegisterExplosion,
        sBattleScript_StartEmpty,
        gBattleScript_End11_RegisterSmoke,
        sBattleScript_LoadGfxThunder,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start12ScatterRadialAndColumnSequence,
        sBattleScript_StartEmpty,
        gBattleScript_End48_SprayColumnEffectTrigger,
        sBattleScript_LoadGfxThunderFamily,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start3FRegisterHandlersDefault,
        sBattleScript_StartEmpty,
        gBattleScript_End0A_RegisterAnimationCallbacks,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxAbsorbAndEarthquakeAndHyperFang,
    },
    {
        sBattleScript_Start25SimpleBurstScript,
        sBattleScript_StartEmpty,
        gBattleScript_End4B_MultiNodeAEntry,
        sBattleScript_LoadGfxDigAndFissure,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start25SimpleBurstScript,
        sBattleScript_StartEmpty,
        gBattleScript_End3A_ModelAnimAndDescriptorSequence,
        sBattleScript_LoadGfxDigAndFissure,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start34RegisterHandler49628,
        sBattleScript_StartEmpty,
        gBattleScript_End4E_RegisterModelAnimAndFallingParticles,
        sBattleScript_LoadGfxToxic,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start11ModelAnimFinish,
        sBattleScript_StartEmpty,
        gBattleScript_End07_PaletteMultiBurst,
        sBattleScript_LoadGfx0E,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start6BAlphaBurst2,
        sBattleScript_StartEmpty,
        gBattleScript_End49_AlphaFirework2,
        sBattleScript_LoadGfx26_11,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start6AAlphaBurst,
        sBattleScript_StartEmpty,
        gBattleScript_End4A_AlphaFirework,
        sBattleScript_LoadGfx26_11,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_NoSpawnThen2ATrail40,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxDoubleTeamAndMeditate,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start60PaletteBurst4,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxAgility,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start1BNop,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start5APortraitBurst,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfx32,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start55FinalSetupA,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfx26_11,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start56RegisterLargeExplosionAndEffects,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxNightShade,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start61PaletteBurst5,
        sBattleScript_StartEmpty,
        gBattleScript_End_FireworkWithConfigB,
        sBattleScript_LoadGfxMimic,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start1DGroupSetupA,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_NoSpawnThen2ATrail40,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxDoubleTeamAndMeditate,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start1BNop,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start6EComplexGroupSetup,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start1EFinalGroupSetup,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start1CRegisterEffectE0,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxBarrageAndConfuseRayAndSludge,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start5DWaterAnimFirework,
        sBattleScript_StartEmpty,
        gBattleScript_End3C_WaterAnimFirework2,
        sBattleScript_LoadGfxWithdrawAlt,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start5BPortraitBurstNode,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxDefenseCurl,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start57_ModelTintAlphaFade,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxBarrierAndConversion,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start0EModelAnimAndMoveKeyedTintParticles,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxHazeAndLightScreen,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start0EModelAnimAndMoveKeyedTintParticles,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxHazeAndLightScreen,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start1CRegisterEffectE0_36RibbonMesh,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxReflectAlt2,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start0EModelAnimAndMoveKeyedTintParticles_Alt,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxFocusEnergyAlt,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start03ModelTintAndVerticalFade,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfx26_11,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start55FinalSetupA,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfx26_11,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start20Nop,
        sBattleScript_StartEmpty,
        gBattleScript_End18_NoOp,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End18_NoOp,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start32RegisterAll48630,
        sBattleScript_StartEmpty,
        gBattleScript_End51_RegisterAllTintRampAndModelScaleFade,
        sBattleScript_LoadGfxEggBombAndFurySwipes,
        sBattleScript_LoadGfx11,
    },
    {
        sBattleScript_Start40RegisterHandler416B0,
        sBattleScript_StartEmpty,
        gBattleScript_End28_SparkleSet,
        sBattleScript_LoadGfxHighJumpKickAndLick,
        sBattleScript_LoadGfx11,
    },
    {
        sBattleScript_Start5CPortraitBurstCheck,
        sBattleScript_StartEmpty,
        gBattleScript_End07_PaletteMultiBurst,
        sBattleScript_LoadGfxSmog,
        sBattleScript_LoadGfx0E,
    },
    {
        sBattleScript_Start4CRegisterEffectE0Alt,
        sBattleScript_StartEmpty,
        gBattleScript_End12_ModeSpecificSetup,
        sBattleScript_LoadGfxBarrageAndConfuseRayAndSludge,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start11ModelAnimFinish,
        sBattleScript_StartEmpty,
        gBattleScript_End07_PaletteMultiBurst,
        sBattleScript_LoadGfx0E,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start4FRegisterHandler498D8,
        sBattleScript_StartEmpty,
        gBattleScript_End0E_InitializeGroup,
        sBattleScript_LoadGfxFireBlastAndRest,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start17InitSmokeSetA,
        sBattleScript_StartEmpty,
        gBattleScript_End3B_InitCombinedSet,
        sBattleScript_LoadGfx11,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start63BasicMultiBurst,
        sBattleScript_StartEmpty,
        gBattleScript_End40_FireballBurst,
        sBattleScript_LoadGfxClamp,
        sBattleScript_LoadGfx03,
    },
    {
        sBattleScript_Start47RegisterHandler49058,
        sBattleScript_StartEmpty,
        gBattleScript_End29_Trigger56A74,
        sBattleScript_LoadGfx08,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_NoSpawnThen07TexturedRibbonSheet,
        sBattleScript_StartEmpty,
        gBattleScript_End34_MultiHandleSetup,
        sBattleScript_LoadGfxSkullBash,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start70PortraitBurstInit,
        sBattleScript_StartEmpty,
        gBattleScript_End_ConfigVariantWithFollowup,
        sBattleScript_LoadGfx32,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start3EOwnerLinkedFourStream,
        sBattleScript_StartEmpty,
        gBattleScript_End25_SpecialSetupBurstPalette3,
        sBattleScript_LoadGfx06,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start13Radial20,
        sBattleScript_StartEmpty,
        gBattleScript_End09_Radial20_Alt,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start0CDelayedModelAnim,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start37RegisterHandler49830,
        sBattleScript_Start2CTrail40GridAlt,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxSoftBoiled,
        sBattleScript_AnimMiss,
    },
    {
        sBattleScript_Start42RegisterMultipleHandlers,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxHighJumpKickAndLick,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start5APortraitBurst,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfx32,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start53SimpleBurst,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxDreamEaterAndLeer,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start5FPaletteMultiBurst2,
        sBattleScript_StartEmpty,
        gBattleScript_End3E_PaletteMultiBurst3,
        sBattleScript_LoadGfxPoisonGas,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start1CRegisterEffectE0,
        sBattleScript_StartEmpty,
        gBattleScript_End12_ModeSpecificSetup,
        sBattleScript_LoadGfxBarrageAndConfuseRayAndSludge,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start65RotationEntry,
        sBattleScript_StartEmpty,
        gBattleScript_End41_FireworkEntry,
        sBattleScript_LoadGfxLeechLife,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start18PaletteScriptBurst,
        sBattleScript_StartEmpty,
        gBattleScript_End15_RegisterModeSpecific,
        sBattleScript_LoadGfxLeechSeedAndLovelyKissAndMegaDrain,
        sBattleScript_LoadGfx26_11,
    },
    {
        sBattleScript_Start5ESimpleBurst2,
        sBattleScript_StartEmpty,
        gBattleScript_End3D_SimpleBurst3,
        sBattleScript_LoadGfxSkyAttack,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start67InitSmoke,
        sBattleScript_Start68InitFire,
        gBattleScript_End19_PlaySoundAndReset,
        sBattleScript_LoadGfxTransform,
        sBattleScript_LoadGfx29_03,
    },
    {
        sBattleScript_Start59MultiNodeD_Alt,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start30TimedFireball,
        sBattleScript_StartEmpty,
        gBattleScript_End22_InitParticleGroupBasic,
        sBattleScript_LoadGfx03,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        gBattleScript_End_PaletteVariantsWithMotionGroup,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxSpore,
    },
    {
        sBattleScript_Start41RegisterParticleNodes,
        sBattleScript_StartEmpty,
        gBattleScript_End12_ModeSpecificSetup,
        sBattleScript_LoadGfxPowderFamily,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start10TintDescriptor34Sequence,
        sBattleScript_StartEmpty,
        gBattleScript_End39_FullSetupTintFadeOutAndRestore,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start31SimpleNodeEntry,
        sBattleScript_StartEmpty,
        gBattleScript_End42_SimpleNodeBurst,
        sBattleScript_LoadGfx26_11,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start51AdvancedModeSetup,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfx0E,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start64SimpleBurst4,
        sBattleScript_StartEmpty,
        gBattleScript_End_CombinedSetupWithCollision,
        sBattleScript_LoadGfxExplosion,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start52RegisterAll48630,
        sBattleScript_StartEmpty,
        gBattleScript_End52_RegisterAllTintRampAndModelScaleFade,
        sBattleScript_LoadGfxEggBombAndFurySwipes,
        sBattleScript_LoadGfx11,
    },
    {
        sBattleScript_Start7CCollisionResponseSwitch,
        sBattleScript_Start7BConditionalStateSetup,
        gBattleScript_End58_CollisionAndBurstSetup,
        sBattleScript_LoadGfx0B,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start50RegisterDefaultTexture,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfxFireBlastAndRest,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_StartEmpty,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start3FRegisterHandlersDefault,
        sBattleScript_StartEmpty,
        gBattleScript_End0A_RegisterAnimationCallbacks,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxAbsorbAndEarthquakeAndHyperFang,
    },
    {
        sBattleScript_Start4ARegisterHandler49108,
        sBattleScript_StartEmpty,
        gBattleScript_End29_Trigger56A74,
        sBattleScript_LoadGfx08,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start58MultiNodeC2,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxBarrierAndConversion,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start1DGroupSetupA,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_NoSpawnThen4EInitSetSingle,
        sBattleScript_StartEmpty,
        gBattleScript_End56_ThreeInstanceSet,
        sBattleScript_LoadGfxSuperFangAlt,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start4ARegisterHandler49108,
        sBattleScript_StartEmpty,
        gBattleScript_End29_Trigger56A74,
        sBattleScript_LoadGfx08,
        sBattleScript_LoadGfx18,
    },
    {
        sBattleScript_Start0DSecondaryOwnerSpeciesBranch,
        sBattleScript_StartEmpty,
        gBattleScript_End05_DynamicCollisionSetup,
        sBattleScript_LoadGfx0B,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start59MultiNodeD,
        sBattleScript_StartEmpty,
        sBattleScript_EndEmpty,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfxEmpty,
    },
    {
        sBattleScript_Start72FinalSetupB,
        sBattleScript_StartEmpty,
        gBattleScript_End2C_ConfigVariantMotion6,
        sBattleScript_LoadGfxEmpty,
        sBattleScript_LoadGfx18,
    },
};

void BattleAnim_PlaySoundEffect1(void) {
    Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
}

void BattleAnim_PlaySoundEffect2(void) {
    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
}

void BattleAnim_PlaySoundEffect3(void) {
    Audio_PlaySoundEffectById(SFX_MENU_BACK);
}

void BattleAnim_PlaySoundEffect8(void) {
    Audio_PlaySoundEffectById(SFX_MENU_ERROR);
}

void BattleAnim_PlayOwnerCry(ActivePokemon* arg0, s16 arg1) {
    if (BattleScene_IsPartnerPikachu(arg0) != 0) {
        Cry_Play(0xC8, 2);
    } else {
        Cry_Play(arg1, 2);
    }
}

void BattleAnim_PlaySpeciesSequence33(ActivePokemon* active_pokemon) {
    s16 sp1E = active_pokemon->displayObject.objectType;

    BattleScene_GetParticipantModelWidth(active_pokemon);
    Audio_PlayCommand(0x33, sp1E, 0);
}

void Battle_TriggerTrainerPresentationCue(ActivePokemon* active_pokemon) {
    ProcessAudioInfo(BattleScene_GetParticipantDisplayPlayerNumber(active_pokemon), &active_pokemon->state.runtime);
}

void BattleAnim_PlaySpeciesReactionSound(ActivePokemon* arg0, BattleMonRuntime* arg1, s32 arg2) {
    Effect_TriggerMoveVisual(arg1->usedMove, arg0->displayObject.objectType, arg2);
    HandleMoveEvent(arg1, arg1->usedMove, arg0->displayObject.objectType, arg2);
}

void BattleScene_ConfigureAudioChannelGroupsByTeam(void) {
    ActivePokemon* ptr1 = sActivePokemon[0];
    ActivePokemon* ptr2 = sActivePokemon[1];
    u8 i;
    u8 sp20[4];

    sp20[0] = 0xA;
    sp20[1] = 0xA;
    sp20[2] = 0xA;
    sp20[3] = 0xA;

    sp20[ptr1->sessionTeams->teamMember[0]->unk_001] = 1;
    if (ptr1->sessionTeams->unk_01 == 2) {
        sp20[ptr1->sessionTeams->teamMember[1]->unk_001] = 1;
    }
    sp20[ptr2->sessionTeams->teamMember[0]->unk_001] = 2;
    if (ptr2->sessionTeams->unk_01 == 2) {
        sp20[ptr2->sessionTeams->teamMember[1]->unk_001] = 2;
    }

    for (i = 0; i < 4; i++) {
        if (sp20[i] == 0xA) {
            sp20[i] = 0;
        }
    }

    Audio_ConfigureChannelGroups(sp20[0], sp20[1], sp20[2], sp20[3]);
}

void BattleScene_ConfigureAudioChannelGroupCounts(void) {
    ActivePokemon* ptr1 = sActivePokemon[0];
    ActivePokemon* ptr2 = sActivePokemon[1];
    u8 sp24[4];

    sp24[0] = 0;
    sp24[1] = 0;
    sp24[2] = 0;
    sp24[3] = 0;

    sp24[ptr1->sessionTeams->teamMember[0]->unk_001] = BattleScene_GetRosterTeamSize(ptr1->sessionTeams->teamMember[0]);
    if (ptr1->sessionTeams->unk_01 == 2) {
        sp24[ptr1->sessionTeams->teamMember[1]->unk_001] = BattleScene_GetRosterTeamSize(ptr1->sessionTeams->teamMember[1]);
    }

    sp24[ptr2->sessionTeams->teamMember[0]->unk_001] = BattleScene_GetRosterTeamSize(ptr2->sessionTeams->teamMember[0]);
    if (ptr2->sessionTeams->unk_01 == 2) {
        sp24[ptr2->sessionTeams->teamMember[1]->unk_001] = BattleScene_GetRosterTeamSize(ptr2->sessionTeams->teamMember[1]);
    }
    Audio_SetChannelGroupCounts(sp24[0], sp24[1], sp24[2], sp24[3]);
}

void BattleScene_SelectBattleMusic(void) {
    switch (gSessionContext.mode) {
        case 0:
            switch (gSessionContext.ruleCategory) {
                case 0:
                    Audio_SelectModeMusic(0, 0xE);
                    break;

                case 1:
                    Audio_SelectModeMusic(0, 0xA);
                    break;

                case 2:
                    Audio_SelectModeMusic(0, 0xB);
                    break;

                case 3:
                    Audio_SelectModeMusic(0, 6);
                    break;

                case 4:
                    Audio_SelectModeMusic(0, 5);
                    break;

                case 5:
                    Audio_SelectModeMusic(0, 4);
                    break;

                case 6:
                    Audio_SelectModeMusic(0, 0);
                    break;

                case 7:
                    Audio_SelectModeMusic(0, 0xC);
                    break;

                case 8:
                    Audio_SelectModeMusic(0, 0xC);
                    break;
            }
            break;

        case 1:
            Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 0xA);
            break;

        case 2:
            Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 0xB);
            break;

        case 3:
            switch (gSessionContext.modeSelection) {
                case 0:
                    Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 6);
                    break;

                case 1:
                    Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 7);
                    break;

                case 2:
                    Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 8);
                    break;

                case 3:
                    Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 9);
                    break;
            }
            break;

        case 4:
            Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 5);
            break;

        case 5:
            Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 4);
            break;

        case 6:
            switch (gSessionContext.modeSelection) {
                case 0:
                    Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 0);
                    break;

                case 1:
                    Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 1);
                    break;

                case 2:
                    Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 2);
                    break;

                case 3:
                    Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 3);
                    break;
            }
            break;

        case 7:
            if (gSessionContext.modeSelection == 9) {
                Audio_SelectModeMusic(5, 0xD);
            } else if (gSessionContext.modeSelection == 8) {
                Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 0xD);
            } else {
                Audio_SelectModeMusic((gSessionContext.modeSelection * 4) + gSessionContext.roundOrDemoId, 0xC);
            }
            break;

        case 8:
            Audio_SelectModeMusic(gSessionContext.roundOrDemoId, 0xF);
            break;

        case 10:
            switch (gSessionContext.ruleCategory) {
                case 0:
                    Audio_SelectModeMusic(0xFF, 0xE);
                    break;

                case 1:
                    Audio_SelectModeMusic(0xFF, 0xA);
                    break;

                case 2:
                    Audio_SelectModeMusic(0xFF, 0xB);
                    break;

                case 3:
                    Audio_SelectModeMusic(0xFF, 6);
                    break;

                case 4:
                    Audio_SelectModeMusic(0xFF, 5);
                    break;

                case 5:
                    Audio_SelectModeMusic(0xFF, 4);
                    break;

                case 6:
                    Audio_SelectModeMusic(0xFF, 0);
                    break;

                case 7:
                    Audio_SelectModeMusic(0xFF, 0xC);
                    break;

                case 8:
                    Audio_SelectModeMusic(0xFF, 0xC);
                    break;
            }
            break;

        case 9:
            Audio_SelectModeMusic(0, 0x10);
            break;
    }
}

void BattleScene_StartBattleMusic(void) {
    switch (gSessionContext.mode) {
        case 16:
            Audio_StartMusicTrack(1);
            break;

        case 0:
            switch (gSessionContext.ruleCategory) {
                case 0:
                    Audio_StartTrackForCategory(0, 0xE);
                    break;

                case 1:
                    Audio_StartTrackForCategory(0, 0xA);
                    break;

                case 2:
                    Audio_StartTrackForCategory(0, 0xB);
                    break;

                case 3:
                    Audio_StartTrackForCategory(0, 6);
                    break;

                case 4:
                    Audio_StartTrackForCategory(0, 5);
                    break;

                case 5:
                    Audio_StartTrackForCategory(0, 4);
                    break;

                case 6:
                    Audio_StartTrackForCategory(0, 0);
                    break;

                case 7:
                    Audio_StartTrackForCategory(0, 0xC);
                    break;

                case 8:
                    Audio_StartTrackForCategory(0, 0xC);
                    break;
            }
            break;

        case 1:
            Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 0xA);
            break;

        case 2:
            Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 0xB);
            break;

        case 3:
            switch (gSessionContext.modeSelection) {
                case 0:
                    Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 6);
                    break;

                case 1:
                    Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 7);
                    break;

                case 2:
                    Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 8);
                    break;

                case 3:
                    Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 9);
                    break;
            }
            break;

        case 4:
            Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 5);
            break;

        case 5:
            Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 4);
            break;

        case 6:
            switch (gSessionContext.modeSelection) {
                case 0:
                    Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 0);
                    break;

                case 1:
                    Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 1);
                    break;

                case 2:
                    Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 2);
                    break;

                case 3:
                    Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 3);
                    break;
            }
            break;

        case 7:
            if (gSessionContext.modeSelection == 9) {
                Audio_StartTrackForCategory(5, 0xD);
            } else if (gSessionContext.modeSelection == 8) {
                Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 0xD);
            } else {
                Audio_StartTrackForCategory((gSessionContext.modeSelection * 4) + gSessionContext.roundOrDemoId, 0xC);
            }
            break;

        case 8:
            Audio_StartTrackForCategory(gSessionContext.roundOrDemoId, 0xF);
            break;

        case 10:
            switch (gSessionContext.ruleCategory) {
                case 0:
                    Audio_StartTrackForCategory(0xFF, 0xE);
                    break;

                case 1:
                    Audio_StartTrackForCategory(0xFF, 0xA);
                    break;

                case 2:
                    Audio_StartTrackForCategory(0xFF, 0xB);
                    break;

                case 3:
                    Audio_StartTrackForCategory(0xFF, 6);
                    break;

                case 4:
                    Audio_StartTrackForCategory(0xFF, 5);
                    break;

                case 5:
                    Audio_StartTrackForCategory(0xFF, 4);
                    break;

                case 6:
                    Audio_StartTrackForCategory(0xFF, 0);
                    break;

                case 7:
                    Audio_StartTrackForCategory(0xFF, 0xC);
                    break;

                case 8:
                    Audio_StartTrackForCategory(0xFF, 0xC);
                    break;
            }
            break;

        case 9:
            Audio_StartTrackForCategory(0, 0x10);
            break;
    }
}

void BattleAnim_PlayBattleSequenceById(ActivePokemon* arg0, s32 arg1) {
    s16 sp1E = arg0->displayObject.objectType;

    if ((BattleScene_IsPartnerPikachu(arg0) != 0) && (arg1 == 0x32)) {
        Audio_PlayCommand(0x32, 0xC8, 0);
    } else if (arg1 == 0x14) {
        Audio_PlayCommand(0x14, 0, 0);
    } else if (arg1 == 0x12) {
        Audio_PlayCommand(0x12, 0, 0);
    } else if (arg1 == 0x32) {
        Audio_PlayCommand(0x32, sp1E, 0);
    } else if (arg1 == 0x21) {
        Audio_PlayCommand(0x21, 0, 0);
    } else if (arg1 == 0x13) {
        Audio_PlayCommand(0x13, 0, 0);
    } else if (arg1 == 0x1E) {
        Audio_PlayCommand(0x1E, 0, 0);
    } else if (arg1 == 0x1F) {
        Audio_PlayCommand(0x1F, 0, 0);
    } else if (arg1 == 0x20) {
        Audio_PlayCommand(0x20, 0, 0);
    }
}

void BattleAnim_RunEffectInitStart(s16 arg0) {
    gBattleAnimCurrentAnchor = gBattleAnimDefaultAnchor;
    sMoveAnimEffectStartInitFuncs[arg0]();
    if (sBattleAnimAlternateAnchor != 0xFF) {
        gBattleAnimCurrentAnchor = sBattleAnimAlternateAnchor;
        sMoveAnimEffectStartInitFuncs[arg0]();
    }
}

void BattleAnim_RunEffectInitEnd(s16 arg0) {
    gBattleAnimCurrentAnchor = gBattleAnimDefaultAnchor;
    sMoveAnimEffectEndInitFuncs[arg0]();
}

void BattleAnim_RegisterEffectSlot(func_D_84390300 arg0, func_D_84390320 arg1) {
    if (sBattleAnimEffectCallbackIndex >= 8) {
        sBattleAnimEffectCallbackIndex = 0;
    }

    if (gBattleAnimEffectUpdateFuncs[sBattleAnimEffectCallbackIndex]) {}

    gBattleAnimEffectUpdateFuncs[sBattleAnimEffectCallbackIndex] = arg0;
    gBattleAnimEffectDrawFuncs[sBattleAnimEffectCallbackIndex] = arg1;
    sBattleAnimEffectCallbackIndex++;
}

void BattleAnim_RunEffectList(s32 arg0, s32 arg1, s32 arg2) {
    u8* sp2C;

    sBattleAnimCurrentEffectList = arg1;

    if (arg2 == 1) {
        switch (arg1) {
            case 0:
                sp2C = sMoveAnimEffectScripts[arg0][0];
                break;

            case 1:
                sp2C = sMoveAnimEffectScripts[arg0][1];
                break;

            case 3:
                sp2C = D_84386D44[arg0][0];
                break;

            case 4:
                sp2C = sBattleAnimMode4StartEffectLists[arg0];
                break;

            case 9:
                sp2C = sBattleAnimMode9StartEffectLists[arg0];
                break;
        }

        while (*sp2C != 0) {
            BattleAnim_RunEffectInitStart(*sp2C);
            gMoveAnimEffectStartFuncs[*sp2C]();
            BattleAnim_RegisterEffectSlot(gMoveAnimEffectStartUpdateFuncs[*sp2C], gMoveAnimEffectStartDrawFuncs[*sp2C]);
            sp2C++;
        }
    } else {
        switch (arg1) {
            case 2:
                sp2C = sMoveAnimEffectScripts[arg0][2];
                break;

            case 6:
                sp2C = D_84386DEC[arg0];
                break;
        }

        while (*sp2C != 0) {
            BattleAnim_RunEffectInitEnd(*sp2C);
            gMoveAnimEffectEndFuncs[*sp2C]();
            BattleAnim_RegisterEffectSlot(gMoveAnimEffectEndUpdateFuncs[*sp2C], gMoveAnimEffectEndDrawFuncs[*sp2C]);
            sp2C++;
        }
    }
}

void BattleAnim_ProcessQueuedEffects(void) {
    if (sBattleAnimQueuedEffectListMode != BATTLE_ANIMATION_QUEUE_INACTIVE) {
        BattleAnim_ResetSpawnDelayAlias();
        BattleAnim_RunEffectList(sBattleAnimQueuedMoveId, sBattleAnimQueuedEffectList, sBattleAnimQueuedEffectListMode);
        sBattleAnimQueuedEffectListMode = BATTLE_ANIMATION_QUEUE_INACTIVE;
    }

    if (sBattleAnimQueuedAlternatePending != 0) {
        BattleAnim_RunEffectList(sBattleAnimQueuedAlternateMoveId, sBattleAnimQueuedAlternateList, sBattleAnimQueuedAlternatePending);
        sBattleAnimQueuedAlternatePending = 0;
    }

    if (sBattleAnimQueuedExtraPending != 0) {
        BattleAnim_RunEffectList(sBattleAnimQueuedExtraMoveId, sBattleAnimQueuedExtraList, sBattleAnimQueuedExtraPending);
        sBattleAnimQueuedExtraPending = 0;
    }

    if (sBattleAnimQueuedResourceListPending != 0) {
        BattleAnim_RunEffectList(sBattleAnimQueuedResourceListId, 4, sBattleAnimQueuedResourceListPending);
        sBattleAnimQueuedResourceListPending = 0;
    }
}

void BattleAnim_UpdateFrame(UNUSED CameraNode* arg0) {
    Particle_UpdateFrameCounters();
    BattleAnim_ProcessQueuedEffects();
    BattleAnim_UpdateEffects();
    BattleAnim_NoopUpdateHook();
}

void BattleAnim_SetQueuedEffectList(u8 effect_list_index) {
    sBattleAnimQueuedEffectList = effect_list_index;
}

u8 BattleAnim_GetCurrentEffectList(void) {
    return sBattleAnimCurrentEffectList;
}

void BattleAnim_SetQueuedResourceListId(u8 arg0) {
    sBattleAnimQueuedResourceListId = arg0;
}

u8 BattleAnim_GetQueuedResourceListId(void) {
    return sBattleAnimQueuedResourceListId;
}

s16 BattleAnim_GetQueuedMoveId(void) {
    return sBattleAnimQueuedMoveId;
}

void BattleAnim_QueueMoveEffect(s32 move_id, ActivePokemon* user, ActivePokemon* user_fallback, s16 default_anchor, s16 alternate_anchor) {
    BattleAnim_SetQueuedEffectList(0);
    sBattleAnimQueuedEffectListMode = BATTLE_ANIMATION_QUEUE_START;
    sBattleAnimQueuedMoveId = move_id;
    gBattleAnimFrameCounter = 0;
    gBattleAnimDefaultAnchor = default_anchor;
    sBattleAnimAlternateAnchor = alternate_anchor;
    gBattleAnimCurrentOwner = user;
    gBattleAnimSecondaryOwner = user;
    gBattleAnimTertiaryOwner = user_fallback;
}

void BattleAnim_QueueMoveEffectScriptA(s32 arg0, ActivePokemon* arg1, ActivePokemon* arg2, s16 arg3, s16 arg4) {
    BattleAnim_QueueMoveEffect(arg0, arg1, arg2, arg3, arg4);
}

void BattleAnim_QueueMoveEffectEnd(s32 move_id, ActivePokemon* user, ActivePokemon* user_fallback, s16 default_anchor, s16 alternate_anchor) {
    BattleAnim_QueueMoveEffect(move_id, user, user_fallback, default_anchor, alternate_anchor);
    BattleAnim_SetQueuedEffectList(2);
    gBattleAnimCurrentOwner = user_fallback;
    sBattleAnimQueuedEffectListMode = BATTLE_ANIMATION_QUEUE_END;
}

void BattleAnim_QueueMoveEffectScriptB(s32 move_id, ActivePokemon* user, ActivePokemon* user_fallback, s16 default_anchor, s16 alternate_anchor) {
    BattleAnim_QueueMoveEffect(move_id, user, user_fallback, default_anchor, alternate_anchor);
    BattleAnim_SetQueuedEffectList(1);
}

void BattleAnim_QueueEffectList3(s32 move_id, ActivePokemon* user, ActivePokemon* user_fallback, s16 default_anchor, s16 alternative_anchor) {
    BattleAnim_QueueMoveEffect(move_id, user, user_fallback, default_anchor, alternative_anchor);
    BattleAnim_SetQueuedEffectList(3);
}

void BattleAnim_QueueEffectList6(s32 arg0, ActivePokemon* arg1) {
    sBattleAnimQueuedAlternatePending = 2;
    sBattleAnimQueuedAlternateMoveId = arg0;
    sBattleAnimQueuedAlternateList = 6;
    gBattleAnimDefaultAnchor = 0xFF;
    sBattleAnimAlternateAnchor = 0xFF;
    gBattleAnimCurrentOwner = arg1;
    gBattleAnimSecondaryOwner = arg1;
    gBattleAnimTertiaryOwner = arg1;
}

void BattleAnim_QueueEffectList5(s32 arg0, ActivePokemon* arg1) {
    BattleAnim_QueueEffectList6(arg0, arg1);
    sBattleAnimQueuedAlternatePending = 1;
    sBattleAnimQueuedAlternateList = 5;
}

void BattleAnim_QueueEffectList6Alt(s32 arg0, ActivePokemon* arg1) {
    BattleAnim_QueueEffectList6(arg0, arg1);
}

void BattleAnim_QueueEffectList9(s32 arg0) {
    sBattleAnimQueuedExtraPending = 1;
    sBattleAnimQueuedExtraList = 9;
    sBattleAnimQueuedExtraMoveId = arg0;
    gBattleAnimDefaultAnchor = 0xFF;
    sBattleAnimAlternateAnchor = 0xFF;
}

void BattleAnim_QueueEffectList(u8 arg0, ActivePokemon* arg1) {
    sBattleAnimQueuedResourceListPending = 1;
    BattleAnim_SetQueuedResourceListId(arg0);
    gBattleAnimCurrentOwner = arg1;
    gBattleAnimDefaultAnchor = 0xFF;
    sBattleAnimAlternateAnchor = 0xFF;
    if (arg0 == 3) {
        gBattleAnimDefaultAnchor = 7;
    }
}

void BattleAnim_StopOwnerCategoryParticles(u8 arg0, ActivePokemon* arg1) {
    BattleAnim_StopParticlesForOwnerCategory(arg0, arg1);
}

void BattleAnim_RegisterAssetTable(arg1_func_80019420* arg0) {
    if (arg0 != NULL) {
        do {
            if (arg0->unk_02 != 0) {
                sBattleAnimAssetPointers[arg0->unk_02] = arg0->unk_04;
                arg0++;
            }
        } while (arg0->unk_00 != 0);
    }
}

void BattleAnim_ResetAssetTable(void) {
    s32 i;

    // clang-format off
    for (i = 0; i < 256; i++) { sBattleAnimAssetPointers[i] = NULL; }
    // clang-format on

    BattleAnim_RegisterAssetTable(BattleAnim_LoadResourceTable(0));
}

void BattleAnim_BuildResourceListForMove(s16 arg0) {
    s32 var_v0 = 0;
    u8* temp_a1 = sMoveAnimEffectScripts[arg0][3];

    while (*temp_a1 != 0x3F) {
        sBattleAnimResourceList[var_v0] = *temp_a1;
        temp_a1++;
        var_v0++;
    }

    temp_a1 = sMoveAnimEffectScripts[arg0][4];
    while (*temp_a1 != 0x3F) {
        sBattleAnimResourceList[var_v0] = *temp_a1;
        temp_a1++;
        var_v0++;
    }

    sBattleAnimResourceList[var_v0] = -1;
}

void BattleAnim_LoadMoveResourceList(BattleSessionTeams* battle_session_teams, s16 move_id) {
    if (move_id != 0xFF) {
        BattleAnim_BuildResourceListForMove(move_id);
        battle_session_teams->assetIsBusy |= 0x80;
        battle_session_teams->unk_20 = sBattleAnimResourceList;
        battle_session_teams->unk_24 = sBattleAnimResourceTablePointers;
    }
}

void BattleAnim_LoadModeResourceList(BattleSessionTeams* battle_session_teams, s16 mode) {
    s32 index = 0;
    u8* var_v1 = D_84386D44[mode][1];

    while (*var_v1 != 0x3F) {
        sBattleAnimResourceList[index] = *var_v1;
        var_v1++;
        index++;
    }

    sBattleAnimResourceList[index] = -1;
    battle_session_teams->unk_20 = sBattleAnimResourceList;
    battle_session_teams->assetIsBusy |= 0x80;
    battle_session_teams->unk_24 = sBattleAnimResourceTablePointers;
}

void BattleAnim_RegisterAllAssetTables(void) {
    s32 i = 0;
    arg1_func_80019420* var_v0;
    arg1_func_80019420** var_s1 = sBattleAnimResourceTablePointers;

    while (*var_s1 != NULL) {
        var_v0 = *var_s1;
        if (i) {}
        BattleAnim_RegisterAssetTable(var_v0);
        var_s1++;
        i++;
    }
}

void BattleAnim_RegisterAssetTablesForSession(BattleSessionTeams* battle_session_teams) {
    battle_session_teams->assetIsBusy &= ~0x10;
    BattleAnim_RegisterAllAssetTables();
}

void BattleAnim_ResetDisplayContexts(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        ModelRenderer_AttachDisplayObject(&D_843903D0[i]);
        D_84391A50[i] = 0;
    }

    for (i = 0; i < 4; i++) {
        ModelRenderer_AttachSecondaryDisplayObject(&D_84391A90[i]);
        D_84392030[i] = 0;
    }
}

Particle* BattleAnim_GetOwnerContextParticle(DisplayObject* arg0) {
    return arg0->node.callbackArg;
}

DisplayObject* BattleAnim_AllocOwnerDisplayContext(Particle* arg0) {
    s32 i;
    s32 var_v0 = -1;
    DisplayObject* temp_a0;

    for (i = 0; i < 16; i++) {
        if (D_84391A50[i] == 0) {
            var_v0 = i;
            break;
        }
    }

    if (var_v0 >= 0) {
        temp_a0 = &D_843903D0[var_v0];
        D_84391A50[var_v0] = 1;
        temp_a0->node.callbackArg = arg0;
    } else {
        temp_a0 = NULL;
    }
    return temp_a0;
}

void BattleAnim_FreeOwnerDisplayContext(DisplayObject* arg0) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (arg0 == &D_843903D0[i]) {
            break;
        }
    }

    if (i != 16) {
        D_84391A50[i] = 0;
        ModelRenderer_ClearDisplayObject(arg0);
    }
}

DisplayObject* BattleAnim_AllocParticleDisplayContext(Particle* arg0) {
    s32 i;
    s32 var_a2 = -1;
    DisplayObject* sp1C;

    for (i = 0; i < 4; i++) {
        if (D_84392030[i] == 0) {
            var_a2 = i;
            break;
        }
    }

    if (var_a2 >= 0) {
        sp1C = &D_84391A90[var_a2];
        D_84392030[var_a2] = 1;
        Particle_SetFlags(arg0, 0x400);
        sp1C->node.callbackArg = arg0;
    } else {
        sp1C = NULL;
    }
    return sp1C;
}

void BattleAnim_FreeParticleDisplayContext(DisplayObject* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (arg0 == &D_84391A90[i]) {
            break;
        }
    }

    if (i != 4) {
        D_84392030[i] = 0;
        ModelRenderer_ClearDisplayObject(arg0);
    }
}

void BattleAnim_InitModelWithAnim(DisplayObject* arg0, s16 arg1, s16 arg2) {
    Model_InitDisplayObject(arg0, 0, 0, sBattleAnimAssetPointers[arg1]);
    ModelAnim_BindTransformCurve(arg0, 0, sBattleAnimAssetPointers[arg2], 0x10000);
}

void BattleAnim_SetModelAnimFrame(DisplayObject* arg0, s16 arg1) {
    ModelAnim_SetFrame(arg0, arg1);
}

void BattleAnim_InitModel(DisplayObject* arg0, s16 arg1) {
    Model_InitDisplayObject(arg0, 0, 0, sBattleAnimAssetPointers[arg1]);
}

void BattleAnim_BindModelAnim(DisplayObject* arg0, s16 arg1) {
    ModelAnim_BindTransformCurve(arg0, 0, sBattleAnimAssetPointers[arg1], 0x10000);
}

void BattleAnim_BindModelAnimReversed(DisplayObject* arg0, s16 arg1) {
    ModelAnim_BindTransformCurve(arg0, 0, sBattleAnimAssetPointers[arg1], -0x10000);
    ModelAnim_SetFrame(arg0, arg0->transformAnim.data->endFrame - 1);
}

s32 BattleAnim_IsModelAnimComplete(DisplayObject* arg0) {
    s32 ret = 0;

    if (arg0->transformAnim.frameFixed == 0) {
        ret = 1;
    }
    return ret;
}

void BattleAnim_UpdateEffectCallbacks(UNUSED CameraNode* arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((gBattleAnimEffectUpdateFuncs[i] != NULL) && (gBattleAnimEffectUpdateFuncs[i]() != 0)) {
            gBattleAnimEffectUpdateFuncs[i] = NULL;
            gBattleAnimEffectDrawFuncs[i] = 0;
        }
    }
}

void BattleAnim_DrawEffectCallbacks(UNUSED CameraNode* arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (gBattleAnimEffectDrawFuncs[i] != NULL) {
            gBattleAnimEffectDrawFuncs[i]();
        }
    }
}

void BattleAnim_UpdateCamera(CameraNode* arg0) {
    gParticleRenderContext.unk_0C = arg0;
    gParticleCameraState = &gParticleRenderContext.unk_10;

    MtxF_Copy(&gParticleCameraState->unk_00, &arg0->view.floatMatrix);
    ParticleMath_CopyVec3f(&gParticleCameraState->unk_40, &arg0->view.eyePosition);
    ParticleMath_CopyVec3f(&gParticleCameraState->unk_4C, &arg0->view.targetPosition);
    BattleAnim_GetCameraLookAngles(&gParticleCameraState->unk_70, &gParticleCameraState->unk_72);
    BattleAnim_GetCameraEyeAngles(&gParticleCameraState->unk_76, &gParticleCameraState->unk_78);
    ParticleMath_NormalizedDirection(&gParticleCameraState->unk_58, gParticleCameraState->unk_40, gParticleCameraState->unk_4C);
    ParticleMath_NormalizedDirection(&gParticleCameraState->unk_64, gParticleCameraState->unk_4C, gParticleCameraState->unk_40);
}

s32 BattleAnim_DispatchPresentation(s32 arg0, CameraNode* arg1) {
    switch (arg0) {
        case 1:
        case 3:
        case 4:
            break;

        case 0:
            BattleAnim_Initialize();
            break;

        case 2:
            BattleAnim_UpdateCamera(arg1);
            BattleAnim_UpdateFrame(arg1);
            BattleAnim_UpdateEffectCallbacks(arg1);
            break;

        case 5:
            BattleAnim_RenderEffectsFrame(arg1);
            break;
    }

    return 0;
}

void BattleAnim_Initialize(void) {
    BattleAnim_InitParticleSystem();
    BattleAnim_Reset();
}

void BattleAnim_Reset(void) {
    s32 i;

    gBattleAnimCurrentOwner = NULL;
    D_843902BC = 0;
    gParticleRenderContext.unk_00.x = 1.0f;
    gParticleRenderContext.unk_00.y = 1.0f;
    gParticleRenderContext.unk_00.z = 1.0f;
    D_843902F4 = 0;
    D_84392040.unk_0C = 1.0f;
    D_84392040.unk_10 = 1.0f;
    sBattleAnimEffectCallbackIndex = 0;

    for (i = 0; i < 8; i++) {
        gBattleAnimEffectUpdateFuncs[i] = NULL;
        gBattleAnimEffectDrawFuncs[i] = NULL;
    }

    gSavedPrimColorR = 0xFF;
    gSavedPrimColorG = 0xFF;
    gSavedPrimColorB = 0xFF;
    gPrimColorA = 0xFF;
    gPrimColorR = 0xFF;
    gPrimColorG = 0xFF;
    gPrimColorB = 0xFF;
    gEnvColorR = 0xFF;
    gEnvColorG = 0xFF;
    gEnvColorB = 0x64;
    gFogColorR = 0;
    gFogColorG = 0;
    gFogColorB = 0;
    D_84390344 = 1.0f;

    Vec3f_SetComponentsDuplicate(&D_84390360, 0.0f, 0.0f, 0.0f);
    Vec3s_SetComponents(&D_8439036C, 0, 0, 0);
    Vec3s_SetComponents(&D_84390374, 0, 0, 0);
    Vec3f_SetComponentsDuplicate(&D_84390348, 0.0f, 0.0f, 0.0f);
    Vec3s_SetComponents(&D_84390354, 0, 0, 0);
    BattleAnim_ResetAssetTable();
    BattleAnim_ResetDisplayContexts();
    D_843903B0 = 0;
    D_843903B4 = 0;
    BattleAnim_EnableEffectSpawning();
}

void BattleAnim_GetPointAlongCameraRay(Vec3f* arg0, f32 arg1) {
    arg0->x = gParticleCameraState->unk_40.x + (arg1 * gParticleCameraState->unk_58.x);
    arg0->y = gParticleCameraState->unk_40.y + (arg1 * gParticleCameraState->unk_58.y);
    arg0->z = gParticleCameraState->unk_40.z + (arg1 * gParticleCameraState->unk_58.z);
}

void BattleAnim_GetCameraEyeAngles(s16* arg0, s16* arg1) {
    CameraNode* temp_v0 = BattleAnim_GetCameraContext();
    f32 sp20 = temp_v0->view.eyePosition.x - temp_v0->view.targetPosition.x;
    f32 sp1C = temp_v0->view.eyePosition.y - temp_v0->view.targetPosition.y;
    f32 sp18 = temp_v0->view.eyePosition.z - temp_v0->view.targetPosition.z;

    *arg0 = MathUtil_Atan2s(sqrtf(SQ(sp20) + SQ(sp18)), sp1C);
    *arg1 = MathUtil_Atan2s(sp18, sp20);
}

void BattleAnim_GetCameraEyeYaw(s16* arg0) {
    CameraNode* temp_v0 = BattleAnim_GetCameraContext();
    f32 x = temp_v0->view.eyePosition.x - temp_v0->view.targetPosition.x;
    f32 z = temp_v0->view.eyePosition.z - temp_v0->view.targetPosition.z;

    *arg0 = MathUtil_Atan2s(z, x);
}

void BattleAnim_GetCameraLookAngles(s16* arg0, s16* arg1) {
    CameraNode* temp_v0 = BattleAnim_GetCameraContext();
    f32 sp20 = temp_v0->view.targetPosition.x - temp_v0->view.eyePosition.x;
    f32 sp1C = temp_v0->view.targetPosition.y - temp_v0->view.eyePosition.y;
    f32 sp18 = temp_v0->view.targetPosition.z - temp_v0->view.eyePosition.z;

    *arg0 = MathUtil_Atan2s(sqrtf(SQ(sp20) + SQ(sp18)), sp1C);
    *arg1 = MathUtil_Atan2s(sp18, sp20);
}

void BattleAnim_GetCameraLookYaw(s16* arg0) {
    CameraNode* temp_v0 = BattleAnim_GetCameraContext();
    f32 x = temp_v0->view.targetPosition.x - temp_v0->view.eyePosition.x;
    f32 z = temp_v0->view.targetPosition.z - temp_v0->view.eyePosition.z;

    *arg0 = MathUtil_Atan2s(z, x);
}

void BattleAnim_GetCameraStoredAngles76(s16* arg0, s16* arg1) {
    *arg0 = gParticleCameraState->unk_76;
    *arg1 = gParticleCameraState->unk_78;
}

void BattleAnim_GetCameraStoredYaw78(s16* arg0) {
    *arg0 = gParticleCameraState->unk_78;
}

void BattleAnim_GetCameraStoredAngles70(s16* arg0, s16* arg1) {
    *arg0 = gParticleCameraState->unk_70;
    *arg1 = gParticleCameraState->unk_72;
}

void BattleAnim_GetCameraStoredYaw72(s16* arg0) {
    *arg0 = gParticleCameraState->unk_72;
}
