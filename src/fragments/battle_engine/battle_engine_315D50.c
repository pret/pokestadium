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
static s32 gBattleAnimQueuedMoveId;
static s32 gBattleAnimQueuedEffectListMode;
static s32 D_843902B4;
static s32 gBattleAnimQueuedEffectList;
static s32 D_843902BC;
static s32 gBattleAnimQueuedResourceListPending;
static s32 gBattleAnimQueuedResourceListId;
static s32 gBattleAnimQueuedAlternatePending;
static s32 gBattleAnimQueuedAlternateMoveId;
static s32 gBattleAnimQueuedAlternateList;
static s32 gBattleAnimQueuedExtraPending;
static s32 gBattleAnimQueuedExtraMoveId;
static s32 gBattleAnimQueuedExtraList;
static s8 gBattleAnimCurrentEffectList;
s16 gBattleAnimCurrentAnchor;
s16 gBattleAnimDefaultAnchor;
static s16 gBattleAnimAlternateAnchor;
Battler* gBattleAnimCurrentOwner;
Battler* gBattleAnimSecondaryOwner;
Battler* gBattleAnimTertiaryOwner;
s32 D_843902F4;
s32 D_843902F8;
static s8 gBattleAnimEffectCallbackIndex;
func_D_84390300 gBattleAnimEffectUpdateFuncs[8];
func_D_84390320 gBattleAnimEffectDrawFuncs[8];
s32 D_84390340;
static f32 D_84390344;
Vec3f D_84390348;
static Vec3s D_84390354;
static Vec3f D_84390360;
static Vec3s D_8439036C;
static Vec3s D_84390374;
s16 D_8439037A;
s16 D_8439037C;
s16 D_8439037E;
s16 D_84390380;
s16 D_84390382;
s16 D_84390384;
s16 D_84390386;
s16 D_84390388;
s16 D_8439038A;
s16 D_8439038C;
s16 D_8439038E;
s16 D_84390390;
s16 D_84390392;
s16 D_84390394;
s16 D_84390396;
s16 D_84390398;
s16 D_8439039A;
s16 D_8439039C;
s16 D_8439039E;
s16 D_843903A0;
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
        &gBattleAnimAssetPointers[4],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[5],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod10_32x64,
        ParticleGfx_DrawBillboardPrimEnvQuadVariantA,
        &gBattleAnimAssetPointers[20],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod10_32x64,
        ParticleGfx_DrawBillboardPrimEnvQuadVariantC,
        &gBattleAnimAssetPointers[20],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[5],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32,
        ParticleGfx_DrawBillboardTextureAlphaRotatedQuad,
        &gBattleAnimAssetPointers[5],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod10_32x64,
        ParticleGfx_DrawBillboardPrimEnvQuadVariantC,
        &gBattleAnimAssetPointers[20],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x64,
        ParticleGfx_DrawBillboardPrimEnvQuadVariantA,
        &gBattleAnimAssetPointers[9],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrim,
        &gBattleAnimAssetPointers[3],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[23],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[14],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[17],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[14],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4TileParticleFrame_24x24,
        ParticleGfx_DrawBillboardPrimEnv,
        &gBattleAnimAssetPointers[8],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4TileParticleFrame_24x24,
        ParticleGfx_DrawBillboardPrimEnv,
        &gBattleAnimAssetPointers[8],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4TileParticleFrame_24x24,
        ParticleGfx_DrawBillboardDoubleSided,
        &gBattleAnimAssetPointers[8],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod8_64x64,
        ParticleGfx_DrawBillboardPrimEnvComposite,
        &gBattleAnimAssetPointers[18],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[17],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[17],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[5],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod8_64x64,
        ParticleGfx_DrawBillboardPrimEnvComposite,
        &gBattleAnimAssetPointers[18],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[23],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[13],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv4Mod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[13],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_64x64,
        ParticleGfx_DrawBillboardPrimEnvComposite,
        &gBattleAnimAssetPointers[18],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[23],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4_64x64,
        ParticleGfx_DrawBillboardPrimEnvTriangleDoubleSided,
        &gBattleAnimAssetPointers[11],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[82],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrimEnvRotatedQuad,
        &gBattleAnimAssetPointers[16],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[84],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[169],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[172],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[166],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[167],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_64x64,
        ParticleGfx_DrawBillboardPrimEnvComposite,
        &gBattleAnimAssetPointers[89],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8_32x32,
        ParticleGfx_DrawBillboardPrimEnvRotatedQuad,
        &gBattleAnimAssetPointers[95],
    },
    {
        0x01,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8_32x32,
        BattleAnim_DrawAsset95Ia8Billboard,
        &gBattleAnimAssetPointers[95],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[2],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[100],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvNoiseQuad,
        &gBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvNoiseQuad,
        &gBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[101],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4WrapST_64x64,
        ParticleGfx_DrawBillboardPrimEnvTransformedQuad,
        &gBattleAnimAssetPointers[63],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8WrapST_64x64,
        ParticleGfx_DrawBillboardPrimEnvTransformedQuad,
        &gBattleAnimAssetPointers[112],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardOffsetQuad,
        &gBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x64,
        ParticleGfx_DrawBillboardPrimEnvQuadVariantB,
        &gBattleAnimAssetPointers[117],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[122],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[82],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8_32x32,
        ParticleGfx_DrawBillboardPrimEnvRotatedQuad,
        &gBattleAnimAssetPointers[95],
    },
    {
        0x00,
        0x01,
        0x0001,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvRotatedQuad,
        &gBattleAnimAssetPointers[82],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardPrimEnvRotatedQuad,
        &gBattleAnimAssetPointers[82],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[83],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod4_32x32,
        ParticleGfx_DrawBillboardPrimEnvQuad,
        &gBattleAnimAssetPointers[14],
    },
    {
        0x00,
        0x01,
        0x0000,
        ParticleGfx_LoadTextureCallbackIa8Frame_32x32,
        ParticleGfx_DrawBillboardTextureAlphaRotatedQuad,
        &gBattleAnimAssetPointers[17],
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

static func_D_84390320 gMoveAnimEffectStartInitFuncs[] = {
    BattleAnim_EffectStartNop, BattleAnim_StartEffect1Descriptor2FPhaseFadeOut, BattleAnim_StartEffect2Descriptor08IndexedScaleDelayFade, BattleAnim_StartEffect3ModelTintAndVerticalFade, BattleAnim_StartEffect4TintDescriptor53ScalePulse, BattleAnim_EffectStartNop, BattleAnim_StartEffect6AnimatedScaleAndBurstEmitter,
    BattleAnim_StartEffect7GlobalTintFade, BattleAnim_StartEffect8ModelBurstAndVerticalFade, BattleAnim_EffectStartNop, BattleAnim_StartEffect10Model60AndModelAnimWait, BattleAnim_StartEffect11GlobalTintFade, BattleAnim_StartEffect12DelayedModelAnim, BattleAnim_StartEffect13SecondaryOwnerSpeciesBranch,
    BattleAnim_StartEffect14ModelAnimAndMoveKeyedTintParticles, BattleAnim_StartEffect15Descriptor08IndexedScaleDelayFade, BattleAnim_StartEffect16TintDescriptor34Sequence, BattleAnim_StartEffect17ModelAnimFinish, BattleAnim_StartEffect18ScatterRadialAndColumnSequence, BattleAnim_EffectStartNop, func_843378CC,
    func_8434C590, func_84336B8C, func_84336EE8, func_8434BF2C, BattleAnim_EffectStartNop, func_8433BC38, BattleAnim_EffectStartNop,
    func_843443E0, func_84358DE4, func_84358F6C, func_84357E60, BattleAnim_EffectStartNop, BattleAnim_EffectStartNop, func_84345038,
    func_843371C0, func_8434CE14, func_8434A898, func_84342808, func_8433BD08, func_84345D74, func_84356254,
    BattleAnim_EffectStartNop, BattleAnim_EffectStartNop, BattleAnim_EffectStartNop, func_8434ED48, BattleAnim_EffectStartNop, func_8433B988, func_8433B374,
    func_8434D8D8, func_84348630, BattleAnim_EffectStartNop, func_84349628, func_84344508, BattleAnim_EffectStartNop, func_84349830,
    func_843579C0, func_84357B80, func_8433B6FC, func_8433E124, func_84358DE4, func_84356DBC, BattleAnim_EffectStartNop,
    func_84346B58, func_84346EEC, func_84344248, func_84346F40, BattleAnim_EffectStartNop, func_84349384, func_84349504,
    func_8433BDFC, func_84349058, func_84347448, func_8433E46C, func_84349108, func_84346DC4, func_84344474,
    func_8433BB78, func_8433BECC, func_843498D8, func_84349A14, func_84358034, func_84348630, func_8434A7DC,
    func_843374A4, func_84358288, func_84345EC0, func_8434A9EC, func_8434AA6C, func_84358A5C, func_8434AC8C,
    func_8434AD1C, func_8434AD70, func_8434C618, func_8434B000, func_8434BA70, func_8434C070, func_8434C0C4,
    BattleAnim_EffectStartNop, func_8434CAD8, func_8434D0F8, func_8434D448, BattleAnim_DisableEffectSpawningAlias, func_8434E0CC, func_8434E02C,
    func_8434E74C, func_8434DA94, func_8434DB40, func_8435674C, func_84358EA0, func_84358EDC, func_843490A8,
    func_8434ACEC, func_8434E8E0, func_8435839C, func_843584C0, func_84358538, func_84357700, func_8434EBA0,
    func_8434EC08, func_8433BB78, func_8434E9A0, BattleAnim_StartEffect122GlobalAndOwnerTintFade, func_8435727C, func_8435742C, func_84344094,
    func_8433765C, func_8434EF68, func_8434EFBC, func_8434F010, func_8434F060, func_8434F0B8, func_8434F350,
    BattleAnim_StartEffect133ModeOrbitBurstAndEffect135Followup, BattleAnim_StartEffect134ModeOrbitAndMetadataBurst, BattleAnim_StartEffect135ExpandingFlashAndRisingScaleFade, BattleAnim_EffectStartNop, BattleAnim_StartEffect137Descriptor3FRisingFade, func_84356D04, BattleAnim_StartEffect139DualRepeatingSparks,
    BattleAnim_StartEffect140StartEffect139Alias, BattleAnim_StartEffect141GridRiseAndFallingBurst, BattleAnim_StartEffect142StartEffect141Alias, BattleAnim_StartEffect143ModeOrbitAndMetadataBurst, BattleAnim_EffectStartNop,
};
static func_D_84390320 gMoveAnimEffectEndInitFuncs[] = {
    BattleAnim_EffectEndNop, BattleAnim_EffectEndNop, func_8433B58C, func_84357A64, func_84357AE0, func_84357110, func_8434575C,
    func_8434A384, func_8433DECC, BattleAnim_EffectEndNop, func_84346BE0, BattleAnim_EffectEndNop, BattleAnim_EffectEndNop, func_84344BDC,
    func_84355E58, func_843372D8, func_8434CF64, func_84342908, func_84357CC8, BattleAnim_EffectEndNop, func_8433BF54,
    func_84345B84, func_84337000, func_843450B4, BattleAnim_EffectEndNop, func_8434E1B8, func_84340CB0, func_8433B7E4,
    func_8433E33C, func_843375B0, func_84356EF4, func_84344B04, BattleAnim_EffectEndNop, BattleAnim_EffectEndNop, func_8433B3D8,
    func_84355EF0, func_84355F88, func_84356148, func_843561A0, func_843567F4, func_8433766C, func_8434915C,
    func_8435643C, func_843565DC, func_84356020, func_843568C8, func_843569A0, func_843561F8, BattleAnim_EffectEndNop,
    func_84345B28, func_84346E50, func_8434C5F0, func_84356AF0, func_8433C3A0, func_84336DD8, func_84357F64,
    func_84336C80, func_843581FC, func_8434A930, func_843378D4, func_8434C720, func_8434B064, func_8434BCD4,
    func_8434C144, func_8434CC68, func_8434D5EC, func_8434D938, func_8433C06C, func_8433C284, func_8433C4EC,
    func_8433C604, func_8433C784, func_8433DFF4, func_8434DD08, func_8434DBEC, func_8434A9CC, func_8434E870,
    func_8434E940, func_8434967C, func_8434ECF4, func_843560B4, func_843489FC, func_843489FC, func_8434917C,
    func_8434EA10, func_8435783C, func_8433CAFC, func_84340D14, func_843574FC, BattleAnim_EffectEndNop,
};
static u8 D_8438682C[] = {
    0x3F, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00,
    0x3F, 0x00, 0x00, 0x00, 0x01, 0x3F, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00,

};
static u8 D_84386844[] = {
    0x03,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386848[] = {
    0x04,
    0x3F,
    0x00,
    0x00,

};
static u8 D_8438684C[] = {
    0x05,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386850[] = {
    0x06,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386854[] = {
    0x09,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386858[] = {
    0x0A,
    0x3F,
    0x00,
    0x00,

};
static u8 D_8438685C[] = {
    0x0B,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386860[] = {
    0x0C, 0x3F, 0x00, 0x00, 0x0D, 0x3F, 0x00, 0x00,

};
static u8 D_84386868[] = {
    0x0E,
    0x3F,
    0x00,
    0x00,

};
static u8 D_8438686C[] = {
    0x0F,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386870[] = {
    0x10,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386874[] = {
    0x11,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386878[] = {
    0x11,
    0x3D,
    0x3F,
    0x00,

};
static u8 D_8438687C[] = {
    0x12,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386880[] = {
    0x13,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386884[] = {
    0x14, 0x3F, 0x00, 0x00, 0x15, 0x3F, 0x00, 0x00,

};
static u8 D_8438688C[] = {
    0x16, 0x3F, 0x00, 0x00, 0x17, 0x3F, 0x00, 0x00,

};
static u8 D_84386894[] = {
    0x18,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386898[] = {
    0x19,
    0x32,
    0x3F,
    0x00,

};
static u8 D_8438689C[] = {
    0x1A,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868A0[] = {
    0x1B,
    0x27,
    0x3F,
    0x00,

};
static u8 D_843868A4[] = {
    0x1C,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868A8[] = {
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
static u8 D_843868B0[] = {
    0x1F,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868B4[] = {
    0x20,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868B8[] = {
    0x21,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868BC[] = {
    0x22,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868C0[] = {
    0x23, 0x3F, 0x00, 0x00, 0x24, 0x3F, 0x00, 0x00,

};
static u8 D_843868C8[] = {
    0x25,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868CC[] = {
    0x26,
    0x11,
    0x3F,
    0x00,

};
static u8 D_843868D0[] = {
    0x27,
    0x32,
    0x3F,
    0x00,

};
static u8 D_843868D4[] = {
    0x28,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868D8[] = {
    0x29,
    0x03,
    0x3F,
    0x00,

};
static u8 D_843868DC[] = {
    0x2A,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868E0[] = {
    0x2B,
    0x11,
    0x3F,
    0x00,

};
static u8 D_843868E4[] = {
    0x17,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868E8[] = {
    0x09,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868EC[] = {
    0x0B, 0x3F, 0x00, 0x00, 0x0E, 0x3F, 0x00, 0x00,

};
static u8 D_843868F4[] = {
    0x14,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868F8[] = {
    0x15,
    0x3F,
    0x00,
    0x00,

};
static u8 D_843868FC[] = {
    0x1E,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386900[] = {
    0x10,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386904[] = {
    0x14,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386908[] = {
    0x0C,
    0x3F,
    0x00,
    0x00,

};
static u8 D_8438690C[] = {
    0x07,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386910[] = {
    0x36,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386914[] = {
    0x18,
    0x0D,
    0x3F,
    0x00,

};
static u8 D_84386918[] = {
    0x03, 0x3F, 0x00, 0x00, 0x14, 0x3F, 0x00, 0x00,

};
static u8 D_84386920[] = {
    0x2C,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386924[] = {
    0x2C,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386928[] = {
    0x3C,
    0x3F,
    0x00,
    0x00,

};
static u8 D_8438692C[] = {
    0x2D,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386930[] = {
    0x08,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386934[] = {
    0x2E,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386938[] = {
    0x2F,
    0x3F,
    0x00,
    0x00,

};
static u8 D_8438693C[] = {
    0x30,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386940[] = {
    0x31,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386944[] = {
    0x32,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386948[] = {
    0x33,
    0x3F,
    0x00,
    0x00,

};
static u8 D_8438694C[] = {
    0x34,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386950[] = {
    0x35,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386954[] = {
    0x37,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386958[] = {
    0x38,
    0x3F,
    0x00,
    0x00,

};
static u8 D_8438695C[] = {
    0x39,
    0x3F,
    0x00,
    0x00,

};
static u8 D_84386960[] = {
    0x3A,
    0x0B,
    0x3F,
    0x00,

};
static u8 D_84386964[] = {
    0x3B,
    0x2C,
    0x3F,
    0x00,

};
static u8 D_84386968[] = {
    0x00, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00,

};
static u8 D_84386970[] = {
    0x90,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386974[] = {
    0x01,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386978[] = {
    0x02,
    0x00,
    0x00,
    0x00,

};
static u8 D_8438697C[] = {
    0x03,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386980[] = {
    0x66, 0x04, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,

};
static u8 D_84386988[] = {
    0x06,
    0x00,
    0x00,
    0x00,

};
static u8 D_8438698C[] = {
    0x3A,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386990[] = {
    0x66,
    0x07,
    0x00,
    0x00,

};
static u8 D_84386994[] = {
    0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,

};
static u8 D_8438699C[] = {
    0x0A,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869A0[] = {
    0x66, 0x0B, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,

};
static u8 D_843869A8[] = {
    0x0D,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869AC[] = {
    0x7B,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869B0[] = {
    0x7C,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869B4[] = {
    0x0E,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869B8[] = {
    0x0F,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869BC[] = {
    0x10,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869C0[] = {
    0x11,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869C4[] = {
    0x12,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869C8[] = {
    0x13, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,

};
static u8 D_843869D0[] = {
    0x15,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869D4[] = {
    0x16,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869D8[] = {
    0x17,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869DC[] = {
    0x18,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869E0[] = {
    0x19, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00,

};
static u8 D_843869E8[] = {
    0x1C,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869EC[] = {
    0x4C,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869F0[] = {
    0x1D, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00,

};
static u8 D_843869F8[] = {
    0x1F,
    0x00,
    0x00,
    0x00,

};
static u8 D_843869FC[] = {
    0x20,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A00[] = {
    0x21,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A04[] = {
    0x22,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A08[] = {
    0x23,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A0C[] = {
    0x66,
    0x24,
    0x00,
    0x00,

};
static u8 D_84386A10[] = {
    0x25,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A14[] = {
    0x26,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A18[] = {
    0x66,
    0x27,
    0x00,
    0x00,

};
static u8 D_84386A1C[] = {
    0x28,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A20[] = {
    0x29,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A24[] = {
    0x66,
    0x2A,
    0x00,
    0x00,

};
static u8 D_84386A28[] = {
    0x2B,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A2C[] = {
    0x2C,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A30[] = {
    0x66, 0x2D, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00,

};
static u8 D_84386A38[] = {
    0x66,
    0x2F,
    0x00,
    0x00,

};
static u8 D_84386A3C[] = {
    0x30,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A40[] = {
    0x31,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A44[] = {
    0x32,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A48[] = {
    0x52,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A4C[] = {
    0x59,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A50[] = {
    0x34, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00,

};
static u8 D_84386A5C[] = {
    0x37,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A60[] = {
    0x35,
    0x05,
    0x00,
    0x00,

};
static u8 D_84386A64[] = {
    0x6A,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A68[] = {
    0x6B,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A6C[] = {
    0x1B,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A70[] = {
    0x56,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A74[] = {
    0x1E,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A78[] = {
    0x5D,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A7C[] = {
    0x1C,
    0x36,
    0x00,
    0x00,

};
static u8 D_84386A80[] = {
    0x0E,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A84[] = {
    0x40,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A88[] = {
    0x0C,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A8C[] = {
    0x42,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A90[] = {
    0x5F,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A94[] = {
    0x66,
    0x4E,
    0x00,
    0x00,

};
static u8 D_84386A98[] = {
    0x3B,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386A9C[] = {
    0x38,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AA0[] = {
    0x66,
    0x39,
    0x00,
    0x00,

};
static u8 D_84386AA4[] = {
    0x3D,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AA8[] = {
    0x3E,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AAC[] = {
    0x7D,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AB0[] = {
    0x7E,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AB4[] = {
    0x7F,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AB8[] = {
    0x80,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386ABC[] = {
    0x81,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AC0[] = {
    0x82,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AC4[] = {
    0x83,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AC8[] = {
    0x84,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386ACC[] = {
    0x8B,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AD0[] = {
    0x8C,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AD4[] = {
    0x8D,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AD8[] = {
    0x8E,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386ADC[] = {
    0x85,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AE0[] = {
    0x86,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AE4[] = {
    0x8F,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AE8[] = {
    0x87,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AEC[] = {
    0x88,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AF0[] = {
    0x89,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AF4[] = {
    0x8A,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AF8[] = {
    0x3F,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386AFC[] = {
    0x41,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B00[] = {
    0x43,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B04[] = {
    0x71,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B08[] = {
    0x79,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B0C[] = {
    0x44,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B10[] = {
    0x45,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B14[] = {
    0x66,
    0x46,
    0x00,
    0x00,

};
static u8 D_84386B18[] = {
    0x47,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B1C[] = {
    0x6F,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B20[] = {
    0x48,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B24[] = {
    0x49,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B28[] = {
    0x4A,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B2C[] = {
    0x4B,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B30[] = {
    0x66,
    0x78,
    0x00,
    0x00,

};
static u8 D_84386B34[] = {
    0x4F,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B38[] = {
    0x50,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B3C[] = {
    0x51,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B40[] = {
    0x53,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B44[] = {
    0x54,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B48[] = {
    0x55,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B4C[] = {
    0x72,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B50[] = {
    0x73,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B54[] = {
    0x74,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B58[] = {
    0x57,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B5C[] = {
    0x58,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B60[] = {
    0x59,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B64[] = {
    0x5A,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B68[] = {
    0x5B,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B6C[] = {
    0x5C,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B70[] = {
    0x5E,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B74[] = {
    0x60,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B78[] = {
    0x61,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B7C[] = {
    0x62,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B80[] = {
    0x63,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B84[] = {
    0x64,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B88[] = {
    0x65,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B8C[] = {
    0x66,
    0x1A,
    0x00,
    0x00,

};
static u8 D_84386B90[] = {
    0x67,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B94[] = {
    0x68,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B98[] = {
    0x69,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386B9C[] = {
    0x6C,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BA0[] = {
    0x6D,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BA4[] = {
    0x6E,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BA8[] = {
    0x70,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BAC[] = {
    0x75,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BB0[] = {
    0x76,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BB4[] = {
    0x77,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BB8[] = {
    0x7A,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BBC[] = {
    0x00, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, 0x00,

};
static u8 D_84386BC4[] = {
    0x01,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BC8[] = {
    0x30, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,

};
static u8 D_84386BD0[] = {
    0x04,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BD4[] = {
    0x05,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BD8[] = {
    0x58, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,

};
static u8 D_84386BE0[] = {
    0x07,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BE4[] = {
    0x08,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BE8[] = {
    0x48,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BEC[] = {
    0x09,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386BF0[] = {
    0x0A, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00,

};
static u8 D_84386C00[] = {
    0x0E,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C04[] = {
    0x23,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C08[] = {
    0x24,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C0C[] = {
    0x25,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C10[] = {
    0x54,
    0x25,
    0x00,
    0x00,

};
static u8 D_84386C14[] = {
    0x4D,
    0x0E,
    0x00,
    0x00,

};
static u8 D_84386C18[] = {
    0x26,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C1C[] = {
    0x0F,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C20[] = {
    0x10,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C24[] = {
    0x11,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C28[] = {
    0x12, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,

};
static u8 D_84386C34[] = {
    0x15,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C38[] = {
    0x16,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C3C[] = {
    0x17,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C40[] = {
    0x18,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C44[] = {
    0x19,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C48[] = {
    0x0D,
    0x0E,
    0x00,
    0x00,

};
static u8 D_84386C4C[] = {
    0x03,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C50[] = {
    0x07,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C54[] = {
    0x22,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C58[] = {
    0x35,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C5C[] = {
    0x45, 0x00, 0x00, 0x00, 0x0E, 0x04, 0x00, 0x00,

};
static u8 D_84386C64[] = {
    0x1A,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C68[] = {
    0x09,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C6C[] = {
    0x06,
    0x0E,
    0x00,
    0x00,

};
static u8 D_84386C70[] = {
    0x1B, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00,

};
static u8 D_84386C78[] = {
    0x1D,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C7C[] = {
    0x1E,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C80[] = {
    0x55,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C84[] = {
    0x1F,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C88[] = {
    0x20,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C8C[] = {
    0x21,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C90[] = {
    0x4F,
    0x27,
    0x00,
    0x00,

};
static u8 D_84386C94[] = {
    0x28,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C98[] = {
    0x29,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386C9C[] = {
    0x2A,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CA0[] = {
    0x2B,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CA4[] = {
    0x2C,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CA8[] = {
    0x2D,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CAC[] = {
    0x4F,
    0x2D,
    0x00,
    0x00,

};
static u8 D_84386CB0[] = {
    0x2E,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CB4[] = {
    0x2F,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CB8[] = {
    0x31,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CBC[] = {
    0x32,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CC0[] = {
    0x3F, 0x23, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00,

};
static u8 D_84386CC8[] = {
    0x34,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CCC[] = {
    0x36,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CD0[] = {
    0x37,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CD4[] = {
    0x39,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CD8[] = {
    0x49,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CDC[] = {
    0x4A,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CE0[] = {
    0x3A,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CE4[] = {
    0x4B,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CE8[] = {
    0x3B,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CEC[] = {
    0x3C,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CF0[] = {
    0x3D,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CF4[] = {
    0x3E,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CF8[] = {
    0x40,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386CFC[] = {
    0x2D,
    0x1E,
    0x00,
    0x00,

};
static u8 D_84386D00[] = {
    0x41,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386D04[] = {
    0x42,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386D08[] = {
    0x43,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386D0C[] = {
    0x44,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386D10[] = {
    0x46,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386D14[] = {
    0x47,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386D18[] = {
    0x50,
    0x4C,
    0x00,
    0x00,

};
static u8 D_84386D1C[] = {
    0x38, 0x00, 0x00, 0x00, 0x4D, 0x00, 0x00, 0x00,

};
static u8 D_84386D24[] = {
    0x4E, 0x00, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x00,

};
static u8 D_84386D2C[] = {
    0x51,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386D30[] = {
    0x52,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386D34[] = {
    0x02,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386D38[] = {
    0x56,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386D3C[] = {
    0x53,
    0x00,
    0x00,
    0x00,

};
static u8 D_84386D40[] = {
    0x57,
    0x23,
    0x00,
    0x00,
};
static u8* D_84386D44[][2] = {
    {
        D_84386968,
        D_8438682C,
    },
    {
        D_84386ADC,
        D_84386920,
    },
    {
        D_84386AE0,
        D_84386920,
    },
    {
        D_84386AE8,
        D_84386924,
    },
    {
        D_84386AEC,
        D_84386924,
    },
    {
        D_84386AF0,
        D_8438692C,
    },
    {
        D_84386AF4,
        D_8438682C,
    },
    {
        D_84386968,
        D_8438682C,
    },
    {
        D_84386ACC,
        D_84386924,
    },
    {
        D_843869D0,
        D_84386870,
    },
    {
        D_84386AD0,
        D_84386928,
    },
    {
        D_84386AD4,
        D_84386928,
    },
    {
        D_84386AE4,
        D_84386920,
    },
    {
        D_84386AD8,
        D_84386928,
    },
    {
        D_84386BB8,
        D_8438682C,
    },
};
static u8* gBattleAnimMode4StartEffectLists[] = {
    D_84386968, D_84386AAC, D_84386AB0, D_84386974, D_84386B10, D_84386AB4,
    D_84386AB8, D_84386ABC, D_84386AC0, D_84386AC4, D_84386AC8, D_84386970,
};
static u8* D_84386DEC[] = {
    D_84386BBC, D_84386BC4, D_84386BEC, D_84386BC8, D_84386CB8,
};
static u8* gBattleAnimMode9StartEffectLists[] = { D_84386968, D_84386A2C };
static u8* gMoveAnimEffectScripts[][5] = {
    {
        D_84386968,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386968,
        D_84386968,
        D_84386CA4,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386CA4,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386C00,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386C04,
        D_8438682C,
        D_84386894,
    },
    {
        D_843869B8,
        D_84386968,
        D_84386D18,
        D_84386844,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386C48,
        D_8438682C,
        D_843868E4,
    },
    {
        D_84386A9C,
        D_84386968,
        D_84386CCC,
        D_84386874,
        D_84386894,
    },
    {
        D_84386A20,
        D_84386968,
        D_84386C9C,
        D_843868B0,
        D_84386894,
    },
    {
        D_84386B24,
        D_84386968,
        D_84386CA0,
        D_8438686C,
        D_84386894,
    },
    {
        D_843869A8,
        D_84386968,
        D_84386BD4,
        D_8438685C,
        D_8438682C,
    },
    {
        D_84386B18,
        D_84386968,
        D_84386C98,
        D_84386930,
        D_84386894,
    },
    {
        D_84386B1C,
        D_84386968,
        D_84386D3C,
        D_84386930,
        D_84386894,
    },
    {
        D_8438699C,
        D_84386B20,
        D_84386C4C,
        D_843868E8,
        D_843868EC,
    },
    {
        D_84386B0C,
        D_84386968,
        D_84386BBC,
        D_84386934,
        D_8438682C,
    },
    {
        D_84386AA4,
        D_84386968,
        D_84386C7C,
        D_8438685C,
        D_8438682C,
    },
    {
        D_8438699C,
        D_84386968,
        D_84386CB4,
        D_84386854,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386D40,
        D_84386858,
        D_84386894,
    },
    {
        D_8438699C,
        D_84386968,
        D_84386BBC,
        D_84386854,
        D_8438682C,
    },
    {
        D_84386968,
        D_84386A1C,
        D_84386CAC,
        D_843868AC,
        D_84386894,
    },
    {
        D_843869C8,
        D_84386968,
        D_84386BEC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386968,
        D_84386968,
        D_84386CA8,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386BAC,
        D_84386968,
        D_84386C80,
        D_8438685C,
        D_84386858,
    },
    {
        D_84386968,
        D_84386968,
        D_84386C90,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386C04,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386978,
        D_84386968,
        D_84386D18,
        D_84386844,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386CA4,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386CA4,
        D_8438682C,
        D_84386894,
    },
    {
        D_843869F8,
        D_84386968,
        D_84386CD0,
        D_8438688C,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386C00,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386BB4,
        D_84386968,
        D_84386C0C,
        D_84386850,
        D_84386894,
    },
    {
        D_84386BB0,
        D_84386968,
        D_84386CB4,
        D_84386850,
        D_84386894,
    },
    {
        D_84386B08,
        D_84386968,
        D_84386C10,
        D_84386850,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386CA4,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386B54,
        D_84386968,
        D_84386CAC,
        D_8438682C,
        D_84386894,
    },
    {
        D_843869C8,
        D_84386968,
        D_84386BEC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386B50,
        D_84386968,
        D_84386CA4,
        D_84386944,
        D_84386894,
    },
    {
        D_84386B4C,
        D_84386968,
        D_84386CA8,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386B50,
        D_84386968,
        D_84386CA8,
        D_84386944,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386B00,
        D_84386968,
        D_84386C18,
        D_84386850,
        D_84386894,
    },
    {
        D_84386B00,
        D_84386968,
        D_84386C18,
        D_84386850,
        D_84386894,
    },
    {
        D_84386B00,
        D_84386968,
        D_84386C0C,
        D_84386850,
        D_84386894,
    },
    {
        D_84386B40,
        D_84386968,
        D_84386BBC,
        D_8438693C,
        D_8438682C,
    },
    {
        D_84386B28,
        D_84386968,
        D_84386C98,
        D_84386930,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386968,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386A28,
        D_84386968,
        D_84386BBC,
        D_843868B8,
        D_8438682C,
    },
    {
        D_84386A2C,
        D_84386968,
        D_84386BBC,
        D_843868BC,
        D_8438682C,
    },
    {
        D_84386A30,
        D_84386968,
        D_84386C04,
        D_843868C0,
        D_84386894,
    },
    {
        D_84386B7C,
        D_84386968,
        D_84386C8C,
        D_8438682C,
        D_8438682C,
    },
    {
        D_843869C0,
        D_84386968,
        D_84386C50,
        D_84386868,
        D_8438682C,
    },
    {
        D_843869D4,
        D_84386968,
        D_84386D1C,
        D_84386874,
        D_84386894,
    },
    {
        D_843869D8,
        D_84386968,
        D_84386C38,
        D_84386874,
        D_84386894,
    },
    {
        D_84386A60,
        D_84386968,
        D_84386BBC,
        D_843868F4,
        D_8438682C,
    },
    {
        D_84386988,
        D_84386968,
        D_84386D34,
        D_84386844,
        D_84386868,
    },
    {
        D_8438698C,
        D_84386968,
        D_84386C70,
        D_84386844,
        D_84386868,
    },
    {
        D_84386A0C,
        D_84386968,
        D_84386C20,
        D_8438689C,
        D_84386844,
    },
    {
        D_84386A38,
        D_84386968,
        D_84386D08,
        D_843868D8,
        D_8438682C,
    },
    {
        D_84386A04,
        D_84386968,
        D_84386C3C,
        D_84386898,
        D_84386844,
    },
    {
        D_84386980,
        D_84386968,
        D_84386D0C,
        D_8438682C,
        D_843868D8,
    },
    {
        D_84386B30,
        D_84386968,
        D_84386C58,
        D_8438682C,
        D_843868D8,
    },
    {
        D_84386B8C,
        D_84386968,
        D_84386C5C,
        D_8438682C,
        D_843868D8,
    },
    {
        D_84386A18,
        D_84386968,
        D_84386D10,
        D_843868A8,
        D_843868D8,
    },
    {
        D_84386BB0,
        D_84386968,
        D_84386C0C,
        D_84386850,
        D_84386894,
    },
    {
        D_84386B04,
        D_84386968,
        D_84386C14,
        D_84386850,
        D_84386894,
    },
    {
        D_84386B9C,
        D_84386968,
        D_84386CB0,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386C08,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386CA4,
        D_8438682C,
        D_84386894,
    },
    {
        D_843869E0,
        D_84386968,
        D_84386CAC,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386B2C,
        D_84386968,
        D_84386CBC,
        D_8438687C,
        D_8438682C,
    },
    {
        D_843869DC,
        D_84386968,
        D_84386C34,
        D_84386880,
        D_843868CC,
    },
    {
        D_843869DC,
        D_84386968,
        D_84386C34,
        D_84386880,
        D_843868CC,
    },
    {
        D_84386994,
        D_84386968,
        D_84386C84,
        D_8438684C,
        D_8438682C,
    },
    {
        D_84386BA0,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_843869A0,
        D_84386968,
        D_84386BD0,
        D_84386858,
        D_84386894,
    },
    {
        D_84386B14,
        D_84386B98,
        D_84386D14,
        D_843868F8,
        D_843868D8,
    },
    {
        D_84386AFC,
        D_84386968,
        D_84386C28,
        D_843868C8,
        D_84386894,
    },
    {
        D_84386AFC,
        D_84386968,
        D_84386C28,
        D_843868C8,
        D_84386894,
    },
    {
        D_84386AFC,
        D_84386968,
        D_84386C28,
        D_843868C8,
        D_84386894,
    },
    {
        D_84386AA0,
        D_84386968,
        D_84386C64,
        D_84386858,
        D_84386894,
    },
    {
        D_84386A00,
        D_84386968,
        D_84386C88,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386A08,
        D_84386968,
        D_84386C1C,
        D_84386874,
        D_84386894,
    },
    {
        D_84386B44,
        D_84386968,
        D_84386C78,
        D_84386878,
        D_84386894,
    },
    {
        D_84386A98,
        D_84386968,
        D_84386BE4,
        D_8438686C,
        D_8438682C,
    },
    {
        D_843869C4,
        D_84386968,
        D_84386BE4,
        D_8438686C,
        D_8438682C,
    },
    {
        D_84386A14,
        D_84386968,
        D_84386C24,
        D_843868A4,
        D_8438682C,
    },
    {
        D_843869C4,
        D_84386968,
        D_84386BE8,
        D_8438686C,
        D_8438682C,
    },
    {
        D_84386AF8,
        D_84386968,
        D_84386BF0,
        D_8438682C,
        D_8438687C,
    },
    {
        D_84386A10,
        D_84386968,
        D_84386CE4,
        D_843868A0,
        D_84386894,
    },
    {
        D_84386A10,
        D_84386968,
        D_84386CE0,
        D_843868A0,
        D_84386894,
    },
    {
        D_84386A50,
        D_84386968,
        D_84386D24,
        D_843868D4,
        D_84386894,
    },
    {
        D_843869C0,
        D_84386968,
        D_84386BE0,
        D_84386868,
        D_8438682C,
    },
    {
        D_84386A68,
        D_84386968,
        D_84386CD8,
        D_843868CC,
        D_84386894,
    },
    {
        D_84386A64,
        D_84386968,
        D_84386CDC,
        D_843868CC,
        D_84386894,
    },
    {
        D_84386A24,
        D_84386968,
        D_84386BBC,
        D_843868B4,
        D_8438682C,
    },
    {
        D_84386B74,
        D_84386968,
        D_84386BBC,
        D_84386954,
        D_8438682C,
    },
    {
        D_84386A6C,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386B64,
        D_84386968,
        D_84386CA4,
        D_84386944,
        D_84386894,
    },
    {
        D_84386B48,
        D_84386968,
        D_84386CA4,
        D_843868CC,
        D_84386894,
    },
    {
        D_84386A70,
        D_84386968,
        D_84386BBC,
        D_843868FC,
        D_8438682C,
    },
    {
        D_84386B78,
        D_84386968,
        D_84386CC0,
        D_84386958,
        D_84386894,
    },
    {
        D_843869F0,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386A24,
        D_84386968,
        D_84386BBC,
        D_843868B4,
        D_8438682C,
    },
    {
        D_84386A6C,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386BA4,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386A74,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386968,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_843869E8,
        D_84386968,
        D_84386BBC,
        D_84386884,
        D_84386894,
    },
    {
        D_84386A78,
        D_84386968,
        D_84386CEC,
        D_84386900,
        D_84386894,
    },
    {
        D_84386B68,
        D_84386968,
        D_84386BBC,
        D_84386948,
        D_8438682C,
    },
    {
        D_84386B58,
        D_84386968,
        D_84386BBC,
        D_84386940,
        D_84386894,
    },
    {
        D_843869B4,
        D_84386968,
        D_84386BBC,
        D_84386860,
        D_8438682C,
    },
    {
        D_843869B4,
        D_84386968,
        D_84386BBC,
        D_84386860,
        D_8438682C,
    },
    {
        D_84386A7C,
        D_84386968,
        D_84386BBC,
        D_84386904,
        D_8438682C,
    },
    {
        D_84386A80,
        D_84386968,
        D_84386BBC,
        D_84386908,
        D_8438682C,
    },
    {
        D_8438697C,
        D_84386968,
        D_84386BBC,
        D_843868CC,
        D_8438682C,
    },
    {
        D_84386B48,
        D_84386968,
        D_84386CA4,
        D_843868CC,
        D_84386894,
    },
    {
        D_843869FC,
        D_84386968,
        D_84386C40,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386968,
        D_84386968,
        D_84386C40,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386A44,
        D_84386968,
        D_84386D2C,
        D_843868D0,
        D_84386874,
    },
    {
        D_84386A84,
        D_84386968,
        D_84386C94,
        D_8438690C,
        D_84386874,
    },
    {
        D_84386B6C,
        D_84386968,
        D_84386BE0,
        D_8438694C,
        D_84386868,
    },
    {
        D_843869EC,
        D_84386968,
        D_84386C28,
        D_84386884,
        D_84386894,
    },
    {
        D_843869C0,
        D_84386968,
        D_84386BE0,
        D_84386868,
        D_8438682C,
    },
    {
        D_84386B34,
        D_84386968,
        D_84386C00,
        D_84386938,
        D_84386894,
    },
    {
        D_843869D8,
        D_84386968,
        D_84386CE8,
        D_84386874,
        D_84386894,
    },
    {
        D_84386B80,
        D_84386968,
        D_84386CF8,
        D_8438695C,
        D_84386844,
    },
    {
        D_84386B18,
        D_84386968,
        D_84386C98,
        D_84386930,
        D_84386894,
    },
    {
        D_84386990,
        D_84386968,
        D_84386CC8,
        D_84386848,
        D_84386894,
    },
    {
        D_84386BA8,
        D_84386968,
        D_84386D18,
        D_84386944,
        D_84386894,
    },
    {
        D_84386AA8,
        D_84386968,
        D_84386C0C,
        D_84386850,
        D_84386894,
    },
    {
        D_843869C8,
        D_84386968,
        D_84386C68,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386A88,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386A5C,
        D_84386A2C,
        D_84386BBC,
        D_843868DC,
        D_843868BC,
    },
    {
        D_84386A8C,
        D_84386968,
        D_84386BBC,
        D_8438690C,
        D_8438682C,
    },
    {
        D_84386B64,
        D_84386968,
        D_84386CA4,
        D_84386944,
        D_84386894,
    },
    {
        D_84386B40,
        D_84386968,
        D_84386BBC,
        D_8438693C,
        D_8438682C,
    },
    {
        D_84386A90,
        D_84386968,
        D_84386CF4,
        D_84386910,
        D_8438682C,
    },
    {
        D_843869E8,
        D_84386968,
        D_84386C28,
        D_84386884,
        D_84386894,
    },
    {
        D_84386B88,
        D_84386968,
        D_84386D00,
        D_84386964,
        D_84386894,
    },
    {
        D_843869DC,
        D_84386968,
        D_84386C34,
        D_84386880,
        D_843868CC,
    },
    {
        D_84386B70,
        D_84386968,
        D_84386CF0,
        D_84386950,
        D_8438682C,
    },
    {
        D_84386B90,
        D_84386B94,
        D_84386C44,
        D_843868E0,
        D_843868D8,
    },
    {
        D_84386B60,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386A3C,
        D_84386968,
        D_84386C54,
        D_84386844,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386C6C,
        D_8438682C,
        D_84386914,
    },
    {
        D_84386AFC,
        D_84386968,
        D_84386C28,
        D_843868C8,
        D_84386894,
    },
    {
        D_843869BC,
        D_84386968,
        D_84386CD4,
        D_8438682C,
        D_84386894,
    },
    {
        D_84386A40,
        D_84386968,
        D_84386D04,
        D_843868CC,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386B3C,
        D_84386968,
        D_84386BBC,
        D_84386868,
        D_84386894,
    },
    {
        D_84386B84,
        D_84386968,
        D_84386CFC,
        D_84386960,
        D_84386894,
    },
    {
        D_84386A48,
        D_84386968,
        D_84386D30,
        D_843868D0,
        D_84386874,
    },
    {
        D_843869B0,
        D_843869AC,
        D_84386BD8,
        D_8438685C,
        D_8438682C,
    },
    {
        D_84386B38,
        D_84386968,
        D_84386CA4,
        D_84386938,
        D_84386894,
    },
    {
        D_84386968,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386AF8,
        D_84386968,
        D_84386BF0,
        D_8438682C,
        D_8438687C,
    },
    {
        D_84386B28,
        D_84386968,
        D_84386C98,
        D_84386930,
        D_84386894,
    },
    {
        D_84386B5C,
        D_84386968,
        D_84386BBC,
        D_84386940,
        D_84386894,
    },
    {
        D_843869F0,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386A94,
        D_84386968,
        D_84386D38,
        D_84386918,
        D_84386894,
    },
    {
        D_84386B28,
        D_84386968,
        D_84386C98,
        D_84386930,
        D_84386894,
    },
    {
        D_843869A8,
        D_84386968,
        D_84386BD4,
        D_8438685C,
        D_8438682C,
    },
    {
        D_84386A4C,
        D_84386968,
        D_84386BBC,
        D_8438682C,
        D_8438682C,
    },
    {
        D_84386B4C,
        D_84386968,
        D_84386CA4,
        D_8438682C,
        D_84386894,
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

void BattleAnim_PlayOwnerCry(Battler* arg0, s16 arg1) {
    if (BattleScene_IsPartnerPikachu(arg0) != 0) {
        Cry_Play(0xC8, 2);
    } else {
        Cry_Play(arg1, 2);
    }
}

void BattleAnim_PlaySpeciesSequence33(Battler* arg0) {
    s16 sp1E = arg0->unk_000.objectType;

    BattleScene_GetParticipantModelWidth(arg0);
    Audio_PlayCommand(0x33, sp1E, 0);
}

void Battle_TriggerTrainerPresentationCue(Battler* arg0) {
    func_8003EB40(BattleScene_GetParticipantDisplayPlayerNumber(arg0), &arg0->unk_654.unk_38);
}

void BattleAnim_PlaySpeciesReactionSound(Battler* arg0, BattleMonRuntime* arg1, s32 arg2) {
    func_800479C0(arg1->unk_5A, arg0->unk_000.objectType, arg2);
    func_80040A70(arg1, arg1->unk_5A, arg0->unk_000.objectType, arg2);
}

void BattleScene_ConfigureAudioChannelGroupsByTeam(void) {
    Battler* ptr1 = D_84390010[0];
    Battler* ptr2 = D_84390010[1];
    u8 i;
    u8 sp20[4];

    sp20[0] = 0xA;
    sp20[1] = 0xA;
    sp20[2] = 0xA;
    sp20[3] = 0xA;

    sp20[ptr1->unk_720->unk_08[0]->unk_001] = 1;
    if (ptr1->unk_720->unk_01 == 2) {
        sp20[ptr1->unk_720->unk_08[1]->unk_001] = 1;
    }
    sp20[ptr2->unk_720->unk_08[0]->unk_001] = 2;
    if (ptr2->unk_720->unk_01 == 2) {
        sp20[ptr2->unk_720->unk_08[1]->unk_001] = 2;
    }

    for (i = 0; i < 4; i++) {
        if (sp20[i] == 0xA) {
            sp20[i] = 0;
        }
    }

    Audio_ConfigureChannelGroups(sp20[0], sp20[1], sp20[2], sp20[3]);
}

void BattleScene_ConfigureAudioChannelGroupCounts(void) {
    Battler* ptr1 = D_84390010[0];
    Battler* ptr2 = D_84390010[1];
    u8 sp24[4];

    sp24[0] = 0;
    sp24[1] = 0;
    sp24[2] = 0;
    sp24[3] = 0;

    sp24[ptr1->unk_720->unk_08[0]->unk_001] = BattleScene_GetRosterTeamSize(ptr1->unk_720->unk_08[0]);
    if (ptr1->unk_720->unk_01 == 2) {
        sp24[ptr1->unk_720->unk_08[1]->unk_001] = BattleScene_GetRosterTeamSize(ptr1->unk_720->unk_08[1]);
    }

    sp24[ptr2->unk_720->unk_08[0]->unk_001] = BattleScene_GetRosterTeamSize(ptr2->unk_720->unk_08[0]);
    if (ptr2->unk_720->unk_01 == 2) {
        sp24[ptr2->unk_720->unk_08[1]->unk_001] = BattleScene_GetRosterTeamSize(ptr2->unk_720->unk_08[1]);
    }
    Audio_SetChannelGroupCounts(sp24[0], sp24[1], sp24[2], sp24[3]);
}

void BattleScene_SelectBattleMusic(void) {
    switch (D_800AE540.unk_0000) {
        case 0:
            switch (D_800AE540.unk_0001) {
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
            Audio_SelectModeMusic(D_800AE540.unk_0003, 0xA);
            break;

        case 2:
            Audio_SelectModeMusic(D_800AE540.unk_0003, 0xB);
            break;

        case 3:
            switch (D_800AE540.unk_0002) {
                case 0:
                    Audio_SelectModeMusic(D_800AE540.unk_0003, 6);
                    break;

                case 1:
                    Audio_SelectModeMusic(D_800AE540.unk_0003, 7);
                    break;

                case 2:
                    Audio_SelectModeMusic(D_800AE540.unk_0003, 8);
                    break;

                case 3:
                    Audio_SelectModeMusic(D_800AE540.unk_0003, 9);
                    break;
            }
            break;

        case 4:
            Audio_SelectModeMusic(D_800AE540.unk_0003, 5);
            break;

        case 5:
            Audio_SelectModeMusic(D_800AE540.unk_0003, 4);
            break;

        case 6:
            switch (D_800AE540.unk_0002) {
                case 0:
                    Audio_SelectModeMusic(D_800AE540.unk_0003, 0);
                    break;

                case 1:
                    Audio_SelectModeMusic(D_800AE540.unk_0003, 1);
                    break;

                case 2:
                    Audio_SelectModeMusic(D_800AE540.unk_0003, 2);
                    break;

                case 3:
                    Audio_SelectModeMusic(D_800AE540.unk_0003, 3);
                    break;
            }
            break;

        case 7:
            if (D_800AE540.unk_0002 == 9) {
                Audio_SelectModeMusic(5, 0xD);
            } else if (D_800AE540.unk_0002 == 8) {
                Audio_SelectModeMusic(D_800AE540.unk_0003, 0xD);
            } else {
                Audio_SelectModeMusic((D_800AE540.unk_0002 * 4) + D_800AE540.unk_0003, 0xC);
            }
            break;

        case 8:
            Audio_SelectModeMusic(D_800AE540.unk_0003, 0xF);
            break;

        case 10:
            switch (D_800AE540.unk_0001) {
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
    switch (D_800AE540.unk_0000) {
        case 16:
            Audio_StartMusicTrack(1);
            break;

        case 0:
            switch (D_800AE540.unk_0001) {
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
            Audio_StartTrackForCategory(D_800AE540.unk_0003, 0xA);
            break;

        case 2:
            Audio_StartTrackForCategory(D_800AE540.unk_0003, 0xB);
            break;

        case 3:
            switch (D_800AE540.unk_0002) {
                case 0:
                    Audio_StartTrackForCategory(D_800AE540.unk_0003, 6);
                    break;

                case 1:
                    Audio_StartTrackForCategory(D_800AE540.unk_0003, 7);
                    break;

                case 2:
                    Audio_StartTrackForCategory(D_800AE540.unk_0003, 8);
                    break;

                case 3:
                    Audio_StartTrackForCategory(D_800AE540.unk_0003, 9);
                    break;
            }
            break;

        case 4:
            Audio_StartTrackForCategory(D_800AE540.unk_0003, 5);
            break;

        case 5:
            Audio_StartTrackForCategory(D_800AE540.unk_0003, 4);
            break;

        case 6:
            switch (D_800AE540.unk_0002) {
                case 0:
                    Audio_StartTrackForCategory(D_800AE540.unk_0003, 0);
                    break;

                case 1:
                    Audio_StartTrackForCategory(D_800AE540.unk_0003, 1);
                    break;

                case 2:
                    Audio_StartTrackForCategory(D_800AE540.unk_0003, 2);
                    break;

                case 3:
                    Audio_StartTrackForCategory(D_800AE540.unk_0003, 3);
                    break;
            }
            break;

        case 7:
            if (D_800AE540.unk_0002 == 9) {
                Audio_StartTrackForCategory(5, 0xD);
            } else if (D_800AE540.unk_0002 == 8) {
                Audio_StartTrackForCategory(D_800AE540.unk_0003, 0xD);
            } else {
                Audio_StartTrackForCategory((D_800AE540.unk_0002 * 4) + D_800AE540.unk_0003, 0xC);
            }
            break;

        case 8:
            Audio_StartTrackForCategory(D_800AE540.unk_0003, 0xF);
            break;

        case 10:
            switch (D_800AE540.unk_0001) {
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

void BattleAnim_PlayBattleSequenceById(Battler* arg0, s32 arg1) {
    s16 sp1E = arg0->unk_000.objectType;

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
    gMoveAnimEffectStartInitFuncs[arg0]();
    if (gBattleAnimAlternateAnchor != 0xFF) {
        gBattleAnimCurrentAnchor = gBattleAnimAlternateAnchor;
        gMoveAnimEffectStartInitFuncs[arg0]();
    }
}

void BattleAnim_RunEffectInitEnd(s16 arg0) {
    gBattleAnimCurrentAnchor = gBattleAnimDefaultAnchor;
    gMoveAnimEffectEndInitFuncs[arg0]();
}

void BattleAnim_RegisterEffectSlot(func_D_84390300 arg0, func_D_84390320 arg1) {
    if (gBattleAnimEffectCallbackIndex >= 8) {
        gBattleAnimEffectCallbackIndex = 0;
    }

    if (gBattleAnimEffectUpdateFuncs[gBattleAnimEffectCallbackIndex]) {}

    gBattleAnimEffectUpdateFuncs[gBattleAnimEffectCallbackIndex] = arg0;
    gBattleAnimEffectDrawFuncs[gBattleAnimEffectCallbackIndex] = arg1;
    gBattleAnimEffectCallbackIndex++;
}

void BattleAnim_RunEffectList(s32 arg0, s32 arg1, s32 arg2) {
    u8* sp2C;

    gBattleAnimCurrentEffectList = arg1;

    if (arg2 == 1) {
        switch (arg1) {
            case 0:
                sp2C = gMoveAnimEffectScripts[arg0][0];
                break;

            case 1:
                sp2C = gMoveAnimEffectScripts[arg0][1];
                break;

            case 3:
                sp2C = D_84386D44[arg0][0];
                break;

            case 4:
                sp2C = gBattleAnimMode4StartEffectLists[arg0];
                break;

            case 9:
                sp2C = gBattleAnimMode9StartEffectLists[arg0];
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
                sp2C = gMoveAnimEffectScripts[arg0][2];
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
    if (gBattleAnimQueuedEffectListMode != 0) {
        BattleAnim_ResetSpawnDelayAlias();
        BattleAnim_RunEffectList(gBattleAnimQueuedMoveId, gBattleAnimQueuedEffectList, gBattleAnimQueuedEffectListMode);
        gBattleAnimQueuedEffectListMode = 0;
    }

    if (gBattleAnimQueuedAlternatePending != 0) {
        BattleAnim_RunEffectList(gBattleAnimQueuedAlternateMoveId, gBattleAnimQueuedAlternateList, gBattleAnimQueuedAlternatePending);
        gBattleAnimQueuedAlternatePending = 0;
    }

    if (gBattleAnimQueuedExtraPending != 0) {
        BattleAnim_RunEffectList(gBattleAnimQueuedExtraMoveId, gBattleAnimQueuedExtraList, gBattleAnimQueuedExtraPending);
        gBattleAnimQueuedExtraPending = 0;
    }

    if (gBattleAnimQueuedResourceListPending != 0) {
        BattleAnim_RunEffectList(gBattleAnimQueuedResourceListId, 4, gBattleAnimQueuedResourceListPending);
        gBattleAnimQueuedResourceListPending = 0;
    }
}

void BattleAnim_UpdateFrame(UNUSED unk_D_86002F34_00C* arg0) {
    Particle_UpdateFrameCounters();
    BattleAnim_ProcessQueuedEffects();
    BattleAnim_UpdateEffects();
    BattleAnim_NoopUpdateHook();
}

void BattleAnim_SetQueuedEffectList(u8 arg0) {
    gBattleAnimQueuedEffectList = arg0;
}

u8 BattleAnim_GetCurrentEffectList(void) {
    return gBattleAnimCurrentEffectList;
}

void BattleAnim_SetQueuedResourceListId(u8 arg0) {
    gBattleAnimQueuedResourceListId = arg0;
}

u8 BattleAnim_GetQueuedResourceListId(void) {
    return gBattleAnimQueuedResourceListId;
}

s16 BattleAnim_GetQueuedMoveId(void) {
    return gBattleAnimQueuedMoveId;
}

void BattleAnim_QueueMoveEffect(s32 arg0, Battler* arg1, Battler* arg2, s16 arg3, s16 arg4) {
    BattleAnim_SetQueuedEffectList(0);
    gBattleAnimQueuedEffectListMode = 1;
    gBattleAnimQueuedMoveId = arg0;
    gBattleAnimFrameCounter = 0;
    gBattleAnimDefaultAnchor = arg3;
    gBattleAnimAlternateAnchor = arg4;
    gBattleAnimCurrentOwner = arg1;
    gBattleAnimSecondaryOwner = arg1;
    gBattleAnimTertiaryOwner = arg2;
}

void BattleAnim_QueueMoveEffectScriptA(s32 arg0, Battler* arg1, Battler* arg2, s16 arg3, s16 arg4) {
    BattleAnim_QueueMoveEffect(arg0, arg1, arg2, arg3, arg4);
}

void BattleAnim_QueueMoveEffectEnd(s32 arg0, Battler* arg1, Battler* arg2, s16 arg3, s16 arg4) {
    BattleAnim_QueueMoveEffect(arg0, arg1, arg2, arg3, arg4);
    BattleAnim_SetQueuedEffectList(2);
    gBattleAnimCurrentOwner = arg2;
    gBattleAnimQueuedEffectListMode = 2;
}

void BattleAnim_QueueMoveEffectScriptB(s32 arg0, Battler* arg1, Battler* arg2, s16 arg3, s16 arg4) {
    BattleAnim_QueueMoveEffect(arg0, arg1, arg2, arg3, arg4);
    BattleAnim_SetQueuedEffectList(1);
}

void BattleAnim_QueueEffectList3(s32 arg0, Battler* arg1, Battler* arg2, s16 arg3, s16 arg4) {
    BattleAnim_QueueMoveEffect(arg0, arg1, arg2, arg3, arg4);
    BattleAnim_SetQueuedEffectList(3);
}

void BattleAnim_QueueEffectList6(s32 arg0, Battler* arg1) {
    gBattleAnimQueuedAlternatePending = 2;
    gBattleAnimQueuedAlternateMoveId = arg0;
    gBattleAnimQueuedAlternateList = 6;
    gBattleAnimDefaultAnchor = 0xFF;
    gBattleAnimAlternateAnchor = 0xFF;
    gBattleAnimCurrentOwner = arg1;
    gBattleAnimSecondaryOwner = arg1;
    gBattleAnimTertiaryOwner = arg1;
}

void BattleAnim_QueueEffectList5(s32 arg0, Battler* arg1) {
    BattleAnim_QueueEffectList6(arg0, arg1);
    gBattleAnimQueuedAlternatePending = 1;
    gBattleAnimQueuedAlternateList = 5;
}

void BattleAnim_QueueEffectList6Alt(s32 arg0, Battler* arg1) {
    BattleAnim_QueueEffectList6(arg0, arg1);
}

void BattleAnim_QueueEffectList9(s32 arg0) {
    gBattleAnimQueuedExtraPending = 1;
    gBattleAnimQueuedExtraList = 9;
    gBattleAnimQueuedExtraMoveId = arg0;
    gBattleAnimDefaultAnchor = 0xFF;
    gBattleAnimAlternateAnchor = 0xFF;
}

void BattleAnim_QueueEffectList(u8 arg0, Battler* arg1) {
    gBattleAnimQueuedResourceListPending = 1;
    BattleAnim_SetQueuedResourceListId(arg0);
    gBattleAnimCurrentOwner = arg1;
    gBattleAnimDefaultAnchor = 0xFF;
    gBattleAnimAlternateAnchor = 0xFF;
    if (arg0 == 3) {
        gBattleAnimDefaultAnchor = 7;
    }
}

void BattleAnim_StopOwnerCategoryParticles(u8 arg0, Battler* arg1) {
    BattleAnim_StopParticlesForOwnerCategory(arg0, arg1);
}

void BattleAnim_RegisterAssetTable(arg1_func_80019420* arg0) {
    if (arg0 != NULL) {
        do {
            if (arg0->unk_02 != 0) {
                gBattleAnimAssetPointers[arg0->unk_02] = arg0->unk_04;
                arg0++;
            }
        } while (arg0->unk_00 != 0);
    }
}

void BattleAnim_ResetAssetTable(void) {
    s32 i;

    // clang-format off
    for (i = 0; i < 256; i++) { gBattleAnimAssetPointers[i] = NULL; }
    // clang-format on

    BattleAnim_RegisterAssetTable(BattleAnim_LoadResourceTable(0));
}

void BattleAnim_BuildResourceListForMove(s16 arg0) {
    s32 var_v0 = 0;
    u8* temp_a1 = gMoveAnimEffectScripts[arg0][3];

    while (*temp_a1 != 0x3F) {
        gBattleAnimResourceList[var_v0] = *temp_a1;
        temp_a1++;
        var_v0++;
    }

    temp_a1 = gMoveAnimEffectScripts[arg0][4];
    while (*temp_a1 != 0x3F) {
        gBattleAnimResourceList[var_v0] = *temp_a1;
        temp_a1++;
        var_v0++;
    }

    gBattleAnimResourceList[var_v0] = -1;
}

void BattleAnim_LoadMoveResourceList(BattleSessionTeams* arg0, s16 arg1) {
    if (arg1 != 0xFF) {
        BattleAnim_BuildResourceListForMove(arg1);
        arg0->unk_1D |= 0x80;
        arg0->unk_20 = gBattleAnimResourceList;
        arg0->unk_24 = gBattleAnimResourceTablePointers;
    }
}

void BattleAnim_LoadModeResourceList(BattleSessionTeams* arg0, s16 arg1) {
    s32 var_v0 = 0;
    u8* var_v1 = D_84386D44[arg1][1];

    while (*var_v1 != 0x3F) {
        gBattleAnimResourceList[var_v0] = *var_v1;
        var_v1++;
        var_v0++;
    }

    gBattleAnimResourceList[var_v0] = -1;
    arg0->unk_20 = gBattleAnimResourceList;
    arg0->unk_1D |= 0x80;
    arg0->unk_24 = gBattleAnimResourceTablePointers;
}

void BattleAnim_RegisterAllAssetTables(void) {
    s32 i = 0;
    arg1_func_80019420* var_v0;
    arg1_func_80019420** var_s1 = gBattleAnimResourceTablePointers;

    while (*var_s1 != NULL) {
        var_v0 = *var_s1;
        if (i) {}
        BattleAnim_RegisterAssetTable(var_v0);
        var_s1++;
        i++;
    }
}

void BattleAnim_RegisterAssetTablesForSession(BattleSessionTeams* arg0) {
    arg0->unk_1D &= ~0x10;
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
    Model_InitDisplayObject(arg0, 0, 0, gBattleAnimAssetPointers[arg1]);
    ModelAnim_BindTransformCurve(arg0, 0, gBattleAnimAssetPointers[arg2], 0x10000);
}

void BattleAnim_SetModelAnimFrame(DisplayObject* arg0, s16 arg1) {
    ModelAnim_SetFrame(arg0, arg1);
}

void BattleAnim_InitModel(DisplayObject* arg0, s16 arg1) {
    Model_InitDisplayObject(arg0, 0, 0, gBattleAnimAssetPointers[arg1]);
}

void BattleAnim_BindModelAnim(DisplayObject* arg0, s16 arg1) {
    ModelAnim_BindTransformCurve(arg0, 0, gBattleAnimAssetPointers[arg1], 0x10000);
}

void BattleAnim_BindModelAnimReversed(DisplayObject* arg0, s16 arg1) {
    ModelAnim_BindTransformCurve(arg0, 0, gBattleAnimAssetPointers[arg1], -0x10000);
    ModelAnim_SetFrame(arg0, arg0->transformAnim.data->endFrame - 1);
}

s32 BattleAnim_IsModelAnimComplete(DisplayObject* arg0) {
    s32 ret = 0;

    if (arg0->transformAnim.frameFixed == 0) {
        ret = 1;
    }
    return ret;
}

void BattleAnim_UpdateEffectCallbacks(UNUSED unk_D_86002F34_00C* arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((gBattleAnimEffectUpdateFuncs[i] != NULL) && (gBattleAnimEffectUpdateFuncs[i]() != 0)) {
            gBattleAnimEffectUpdateFuncs[i] = NULL;
            gBattleAnimEffectDrawFuncs[i] = 0;
        }
    }
}

void BattleAnim_DrawEffectCallbacks(UNUSED unk_D_86002F34_00C* arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (gBattleAnimEffectDrawFuncs[i] != NULL) {
            gBattleAnimEffectDrawFuncs[i]();
        }
    }
}

void BattleAnim_UpdateCamera(unk_D_86002F34_00C* arg0) {
    gParticleRenderContext.unk_0C = arg0;
    gParticleCameraState = &gParticleRenderContext.unk_10;

    MtxF_Copy(&gParticleCameraState->unk_00, &arg0->unk_60.mtxf);
    ParticleMath_CopyVec3f(&gParticleCameraState->unk_40, &arg0->unk_60.eye);
    ParticleMath_CopyVec3f(&gParticleCameraState->unk_4C, &arg0->unk_60.at);
    BattleAnim_GetCameraLookAngles(&gParticleCameraState->unk_70, &gParticleCameraState->unk_72);
    BattleAnim_GetCameraEyeAngles(&gParticleCameraState->unk_76, &gParticleCameraState->unk_78);
    ParticleMath_NormalizedDirection(&gParticleCameraState->unk_58, gParticleCameraState->unk_40, gParticleCameraState->unk_4C);
    ParticleMath_NormalizedDirection(&gParticleCameraState->unk_64, gParticleCameraState->unk_4C, gParticleCameraState->unk_40);
}

s32 BattleAnim_DispatchPresentation(s32 arg0, unk_D_86002F34_00C* arg1) {
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
    gBattleAnimEffectCallbackIndex = 0;

    for (i = 0; i < 8; i++) {
        gBattleAnimEffectUpdateFuncs[i] = NULL;
        gBattleAnimEffectDrawFuncs[i] = NULL;
    }

    D_8439037A = 0xFF;
    D_8439037C = 0xFF;
    D_8439037E = 0xFF;
    D_84390388 = 0xFF;
    D_84390382 = 0xFF;
    D_84390384 = 0xFF;
    D_84390386 = 0xFF;
    D_8439038A = 0xFF;
    D_8439038C = 0xFF;
    D_8439038E = 0x64;
    D_84390392 = 0;
    D_84390394 = 0;
    D_84390396 = 0;
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
    unk_D_86002F34_00C* temp_v0 = BattleAnim_GetCameraContext();
    f32 sp20 = temp_v0->unk_60.eye.x - temp_v0->unk_60.at.x;
    f32 sp1C = temp_v0->unk_60.eye.y - temp_v0->unk_60.at.y;
    f32 sp18 = temp_v0->unk_60.eye.z - temp_v0->unk_60.at.z;

    *arg0 = MathUtil_Atan2s(sqrtf(SQ(sp20) + SQ(sp18)), sp1C);
    *arg1 = MathUtil_Atan2s(sp18, sp20);
}

void BattleAnim_GetCameraEyeYaw(s16* arg0) {
    unk_D_86002F34_00C* temp_v0 = BattleAnim_GetCameraContext();
    f32 x = temp_v0->unk_60.eye.x - temp_v0->unk_60.at.x;
    f32 z = temp_v0->unk_60.eye.z - temp_v0->unk_60.at.z;

    *arg0 = MathUtil_Atan2s(z, x);
}

void BattleAnim_GetCameraLookAngles(s16* arg0, s16* arg1) {
    unk_D_86002F34_00C* temp_v0 = BattleAnim_GetCameraContext();
    f32 sp20 = temp_v0->unk_60.at.x - temp_v0->unk_60.eye.x;
    f32 sp1C = temp_v0->unk_60.at.y - temp_v0->unk_60.eye.y;
    f32 sp18 = temp_v0->unk_60.at.z - temp_v0->unk_60.eye.z;

    *arg0 = MathUtil_Atan2s(sqrtf(SQ(sp20) + SQ(sp18)), sp1C);
    *arg1 = MathUtil_Atan2s(sp18, sp20);
}

void BattleAnim_GetCameraLookYaw(s16* arg0) {
    unk_D_86002F34_00C* temp_v0 = BattleAnim_GetCameraContext();
    f32 x = temp_v0->unk_60.at.x - temp_v0->unk_60.eye.x;
    f32 z = temp_v0->unk_60.at.z - temp_v0->unk_60.eye.z;

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
