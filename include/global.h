#ifndef _COMMON_H
#define _COMMON_H

#include <ultra64.h>
#include <PR/sched.h>

typedef unsigned int uintptr_t;

#include "macros.h"
#include "attributes.h"
#include "functions.h"
#include "sections.h"
#include "gfx.h"
#include "color.h"
#include "sound.h"
#include "string.h"
#include "math.h"

struct ModelAssetNode;

typedef union arg1_func_80010CA8 {
    struct {
        /* 0x00 */ s16 unk_00;
        /* 0x02 */ s8 unk_02;
        /* 0x03 */ s8 unk_03;
    };
    u32 raw;
} arg1_func_80010CA8; // size = 0x4

typedef struct ModelAnimationBank {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ u8 transformCount;
    /* 0x05 */ u8 eventTrackCount;
    /* 0x06 */ char pad6[6];
    /* 0x0C */ s32* transformTracks;
    /* 0x10 */ s32* eventTracks;
} ModelAnimationBank; // size >= 0x14

typedef ModelAnimationBank* (*ModelBankCallback)(s32, s32);

typedef struct ModelLoadResult {
    /* 0x00 */ u16 modelId;
    /* 0x02 */ char unk02[0x6];
    /* 0x08 */ struct ModelNodeView* modelRoot;
} ModelLoadResult; // size >= 0xC

typedef struct ModelLoadContext {
    /* 0x00 */ u8 flags;
    /* 0x01 */ u8 pendingLoads;
    /* 0x02 */ u8 bufferIndex;
    /* 0x04 */ s32 modelBuffers[5];
    /* 0x18 */ s32 backgroundBuffer;
    /* 0x1C */ s32 modelSize;
    /* 0x20 */ s32 backgroundSize;
    /* 0x24 */ ModelLoadResult* loadedModel;
    /* 0x28 */ s32 loadedBackground;
    /* 0x2C */ arg1_func_80010CA8 colorVariant;
    /* 0x30 */ OSMesgQueue modelQueue;
    /* 0x48 */ OSMesg modelMessage;
    /* 0x4C */ char pad4C[0x4];
    /* 0x50 */ OSMesgQueue backgroundQueue;
    /* 0x68 */ OSMesg backgroundMessage;
    /* 0x6C */ char pad6C[0x4];
} ModelLoadContext; // size = 0x70

typedef struct ModelNodeView {
    // Legacy graph-header view: preserve pointer declarations for matching.
    // The four-slot overlay is also indexed by asset callers; its full role is unresolved.
    /* 0x00 */ struct ModelNodeView* unk_00[4];
    /* 0x10 */ struct ModelAssetNode* callback;
    /* 0x14 */ ModelLoadContext* callbackArg;
} ModelNodeView; // size >= 0x18

typedef struct ModelAssetNode {
    /* 0x00 */ ModelNodeView node;
    /* 0x18 */ char unk_18[0x10];
    /* 0x28 */ ModelBankCallback getAnimationBank;
} ModelAssetNode; // size >= 0x2C

typedef struct DisplayNodeHeader {
    // Layout-compatible with GraphNode; retain this view's legacy member types.
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 flags;
    /* 0x02 */ u8 renderFlags;
    /* 0x03 */ u8 renderLayer;
    /* 0x04 */ struct DisplayNodeHeader* prevSibling;
    /* 0x08 */ struct DisplayNodeHeader* nextSibling;
    /* 0x0C */ ModelAssetNode* children;
    /* 0x10 */ ModelLoadContext* callback;
    /* 0x14 */ s32 callbackArg;
} DisplayNodeHeader; // size = 0x18

typedef struct TransformAnimData {
    /* 0x00 */ s16 flags; // bit 0x2 clamps at the boundary; otherwise playback wraps
    /* 0x02 */ char unk02[0x2];
    /* 0x04 */ s16 startFrame;
    /* 0x06 */ s16 loopStart;
    /* 0x08 */ u16 channelCount;
    /* 0x0A */ u16 endFrame;
    /* 0x0C */ u32 channelTable;
    /* 0x10 */ u32 translationData;
    /* 0x14 */ u32 rotationData;
    /* 0x18 */ u32 scaleData;
} TransformAnimData; // size >= 0x1C

typedef struct TransformAnimState {
    /* 0x00 */ s16 animationId;
    /* 0x04 */ TransformAnimData* data;
    /* 0x08 */ s32 frameFixed; // signed 16.16 playback position
    /* 0x0C */ u32 speedFixed; // 16.16 step; preserve the legacy unsigned declaration
    /* 0x10 */ char unk10[0x2];
    /* 0x12 */ u16 lastRenderFrame;
} TransformAnimState; // size >= 0x14

typedef struct EventTrackData {
    /* 0x00 */ s16 flags; // bit 0x2 clamps at the boundary; otherwise playback wraps
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ s16 startFrame;
    /* 0x06 */ s16 loopStart;
    /* 0x08 */ u16 trackCount;
    /* 0x0A */ u16 endFrame;
    /* 0x0C */ void* trackTable;
    /* 0x10 */ void* frameValues;
} EventTrackData; // size >= 0x14

typedef struct EventTrackState {
    /* 0x00 */ s16 trackId;
    /* 0x04 */ EventTrackData* data;
    /* 0x08 */ s16 frame;
    /* 0x0A */ u16 lastRenderFrame;
} EventTrackState; // size = 0xC

typedef struct ModelAnchor {
    /* 0x00 */ u16 id;
    /* 0x02 */ u8 unk_02;
    /* 0x04 */ Vec3f position;
} ModelAnchor; // size = 0x10

// Animated model instance processed by Geo_NodeModelPart (node type 0x16).
typedef struct DisplayObject {
    /* 0x000 */ DisplayNodeHeader node;
    /* 0x018 */ s16 rootId;
    /* 0x01A */ s16 objectType;
    /* 0x01C */ u8 textureMode;
    /* 0x01D */ u8 lodFraction; // gDPSetPrimColor's primitive LOD-fraction argument
    /* 0x01E */ Vec3s rotation;
    /* 0x024 */ Vec3f position;
    /* 0x030 */ Vec3f scale;
    /* 0x03C */ Color_RGBA8_u32 textureTint;
    /* 0x040 */ TransformAnimState transformAnim;
    /* 0x054 */ EventTrackState eventTrack;
    /* 0x060 */ MtxF matrix;
    /* 0x0A0 */ Color_RGBA8_u32 fogColor; // submitted through GeoRender_SetFogColor
    /* 0x0A4 */ char unk0A4[2];
    /* 0x0A6 */ u8 effectSlot; // 0/1 select effect state; 0xFF disables slot-specific work
    /* 0x0A7 */ u8 anchorCount;
    /* 0x0A8 */ ModelAnchor anchors[12];
} DisplayObject; // size = 0x168

typedef struct unk_D_86002F34_000_014_004 {
    /* 0x00 */ u8 unk_00[5];
} unk_D_86002F34_000_014_004; // size = 0x5

typedef struct unk_D_86002F34_000_014_010 {
    /* 0x00 */ u8 unk_00[4];
} unk_D_86002F34_000_014_010; // size = 0x4

typedef struct unk_D_86002F34_000_014 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u8* unk_04;
} unk_D_86002F34_000_014; // size >= 0x8

struct GraphNode;
typedef s32 (*GraphNodeCallback)(s32 event, struct GraphNode* node);

typedef struct GraphNode {
    /* 0x00 */ u8 type; // Index into the geometry-node renderer dispatch table.
    /* 0x01 */ u8 flags; // Bit 0 enables rendering; initialized to 0x11.
    /* 0x02 */ u8 renderFlags; // Type-dependent rendering options, not universal flags.
    /* 0x03 */ u8 renderLayer; // Material/render-slot selector; may be remapped by material state.
    /* 0x04 */ struct GraphNode* prevSibling;
    /* 0x08 */ struct GraphNode* nextSibling;
    /* 0x0C */ struct unk_D_86002F34_00C* children; // Circular child-list head; retain legacy pointer type.
    /* 0x10 */ GraphNodeCallback callback; // Events: 0 on installation, 2 on traversal, 5 on DL submission.
    /* 0x14 */ void* callbackArg; // Callback-owned data or selector, accessed through the node.
} GraphNode; // size = 0x18

typedef struct unk_D_86002F34_00C_018 {
    /* 0x00 */ Vp* vp;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 width;
    /* 0x0A */ s16 height;
} unk_D_86002F34_00C_018; // size = 0xC

typedef struct unk_D_86002F34_00C_024 {
    /* 0x00 */ Mtx* mtx;
    /* 0x04 */ u16 perspNorm;
    /* 0x08 */ f32 fovy;
    /* 0x0C */ f32 aspect;
    /* 0x10 */ f32 near;
    /* 0x14 */ f32 far;
    /* 0x18 */ f32 scale;
} unk_D_86002F34_00C_024; // size = 0x1C

typedef struct unk_D_86002F34_00C_040 {
    /* 0x00 */ Mtx* mtx;
    /* 0x04 */ f32 l;
    /* 0x08 */ f32 r;
    /* 0x0C */ f32 b;
    /* 0x10 */ f32 t;
    /* 0x14 */ f32 n;
    /* 0x18 */ f32 f;
    /* 0x1C */ f32 scale;
} unk_D_86002F34_00C_040; // size = 0x20

typedef struct unk_D_86002F34_00C_060 {
    /* 0x00 */ MtxF* p_mtxf;
    /* 0x04 */ MtxF mtxf;
    /* 0x44 */ LookAt* lookat;
    /* 0x48 */ Vec3f eye;
    /* 0x54 */ Vec3f at;
    /* 0x60 */ Vec3f up;
} unk_D_86002F34_00C_060; // size >= 0x6C

typedef struct unk_D_86002F34_00C_0CC {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ Color_RGBA8_u32 color;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ u8* texture;
} unk_D_86002F34_00C_0CC; // size >= 0x20

typedef struct unk_D_86002F34_00C {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ unk_D_86002F34_00C_018 unk_18;	//	viewPort
    /* 0x24 */ unk_D_86002F34_00C_024 unk_24;	//	projection
    /* 0x40 */ unk_D_86002F34_00C_040 unk_40;
    /* 0x60 */ unk_D_86002F34_00C_060 unk_60;	//	camera
    /* 0xCC */ unk_D_86002F34_00C_0CC unk_CC;
    /* 0xEC */ char unkEC[0x4];
} unk_D_86002F34_00C; // size = 0xF0

typedef struct unk_D_86002F34_alt1 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ s8 unk_1C;
    /* 0x1D */ s8 unk_1D;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ Lights7* lights;
} unk_D_86002F34_alt1; // size >= 0x28

typedef struct unk_D_86002F34_alt2 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ GraphNode* unk_18;
} unk_D_86002F34_alt2; // size >= 0x1C

typedef struct unk_D_86002F34_alt3 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s32 unk_1C;
} unk_D_86002F34_alt3; // size >= 0x20

typedef struct unk_D_86002F34_alt4 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ Color_RGBA8_u32 unk_18;
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ u16 unk_1E;
} unk_D_86002F34_alt4; // size >= 0x20

typedef struct unk_D_86002F34_alt5 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ Vec3s unk_24;
} unk_D_86002F34_alt5; // size = 0x2C

typedef struct unk_D_86002F34_alt6 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ Vec3s unk_18;
    /* 0x1E */ Vec3s unk_1E;
    /* 0x24 */ Vec3f unk_24;
    /* 0x30 */ u8 unk_30;
    /* 0x31 */ u8 unk_31;
    /* 0x32 */ s16 unk_32;
} unk_D_86002F34_alt6; // size = 0x34

typedef struct unk_D_86002F34_alt7 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ s16 unk_1C;
} unk_D_86002F34_alt7; // size = 0x20

typedef struct unk_D_86002F34_alt8 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ MtxF unk_1C;
} unk_D_86002F34_alt8; // size = 0x5C

typedef struct unk_D_86002F34_alt9 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ Vec3f unk_1C;
    /* 0x28 */ f32 unk_28;
} unk_D_86002F34_alt9; // size = 0x2C

typedef struct unk_D_86002F34_alt10 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ u8 unk_22;
    /* 0x24 */ Color_RGBA8_u32 unk_24;
} unk_D_86002F34_alt10; // size >= 0x28

typedef struct unk_D_86002F34_alt11_018 {
    /* 0x00 */ u8 fmt;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ char unk04[0x4];
    /* 0x08 */ u8* texture;
} unk_D_86002F34_alt11_018; // size >= 0xC

typedef struct unk_D_86002F34_alt11 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ unk_D_86002F34_alt11_018* unk_18;
    /* 0x1C */ unk_D_86002F34_alt11_018* unk_1C;
} unk_D_86002F34_alt11; // size >= 0x20

typedef struct unk_D_86002F34_alt12 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
} unk_D_86002F34_alt12; // size = 0x20

typedef struct unk_D_86002F34_alt13 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ s16 unk_18;
} unk_D_86002F34_alt13; // size = 0x1C

typedef struct unk_D_86002F34_alt14 {
    /* 0x00 */ GraphNode node;
} unk_D_86002F34_alt14; // size = 0x18

typedef struct unk_D_86002F34_alt15 {
    /* 0x00 */ GraphNode node;
} unk_D_86002F34_alt15; // size = 0x18

typedef struct unk_D_86002F34_alt16 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ u32 unk_18;
} unk_D_86002F34_alt16; // size = 0x1C

typedef struct unk_D_86002F34_alt17 {
    /* 0x00 */ GraphNode node;
} unk_D_86002F34_alt17; // size = 0x18

typedef struct unk_D_86002F34_alt18 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ u8 r;
    /* 0x19 */ u8 g;
    /* 0x1A */ u8 b;
    /* 0x1B */ u8 a;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
} unk_D_86002F34_alt18; // size = 0x20

typedef struct unk_D_86002F34_alt19 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ u8 r;
    /* 0x19 */ u8 g;
    /* 0x1A */ u8 b;
} unk_D_86002F34_alt19; // size = 0x1C

typedef struct unk_D_86002F34_alt20 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} unk_D_86002F34_alt20; // size = 0x1C

typedef struct unk_D_86002F34_alt21 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} unk_D_86002F34_alt21; // size = 0x1C

typedef struct unk_D_86002F34_alt22 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ Vec3f unk_18;
} unk_D_86002F34_alt22; // size = 0x24

typedef struct unk_D_86002F34_alt23 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ s16 unk_18;
} unk_D_86002F34_alt23; // size = 0x1C

typedef struct unk_D_86002F34_alt24 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ Color_RGBA8_u32 unk_28;
} unk_D_86002F34_alt24; // size = 0x2C

typedef void* (*func_unk_D_800ABE10)(s32, s32);

#define unk_D_86002F34_018_GFX_TYPE_1 1 // 8-bit per texel
#define unk_D_86002F34_018_GFX_TYPE_2 2 // 16-bit per texel
#define unk_D_86002F34_018_GFX_TYPE_3 3 // 32-bit per texel

typedef struct unk_D_86002F34_018 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 type;
    /* 0x02 */ s16 width;
    /* 0x04 */ s16 height;
    /* 0x06 */ s16 num_texels;
    /* 0x08 */ u32* texture;
} unk_D_86002F34_018; // size = 0xC

typedef struct unk_D_86002F34_01C {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s16* unk_04;
    /* 0x08 */ char unk08[0x4];
} unk_D_86002F34_01C; // size = 0xC

typedef struct unk_D_86002F34 {
    /* 0x00 */ GraphNode node;
    /* 0x18 */ unk_D_86002F34_018* unk_18;
    /* 0x1C */ unk_D_86002F34_01C* unk_1C;
    /* 0x20 */ Vtx* unk_20;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ func_unk_D_800ABE10 unk_28;
} unk_D_86002F34; // size = 0x2C

// Are unk_D_86002F30 and unk_D_800AC840 the same?
typedef struct unk_D_86002F30 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ ModelNodeView* unk_08;
} unk_D_86002F30; // size = 0x18 ??

typedef struct UnkInputStruct8000D738 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 (*unk_04)[6][0x640];
} UnkInputStruct8000D738; // size = 0x8

typedef struct unk_D_800AA660 {
    /* 0x0000 */ OSThread thread;
    /* 0x01B0 */ char unk01B0[0x10];
    /* 0x01C0 */ OSMesgQueue queue1;
    /* 0x01D8 */ struct unk_D_800AA660* unk_01D8;
    /* 0x01DC */ s32 unk_01DC;
    /* 0x01E0 */ char unk01E0[0x2000];
    /* 0x21E0 */ OSMesg mesg;
    /* 0x21E4 */ OSMesgQueue queue2;
    /* 0x21FC */ u8* font1;
    /* 0x2200 */ u8* font2;
    /* 0x2204 */ UnkInputStruct8000D738 unk_2204;
    /* 0x220C */ char unk220C[4];
} unk_D_800AA660; // size = 0x2210

typedef struct unk_D_864027C0 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
} unk_D_864027C0; // size = 0x20

typedef struct arg1_func_81407874_014_000_010 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
} arg1_func_81407874_014_000_010; // size >= 0x10

typedef struct func_88002628_sp38 {
    /* 0x000 */ OSThread thread;
    /* 0x1B0 */ char unk1B0[0x10];
} func_88002628_sp38; // size = 0x1C0

typedef struct unk_func_88500020 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u8* unk_0C;
} unk_func_88500020; // size = 0x10

// offset 0x898000 in the rom
typedef struct TrainerData {
    /* 0x000 */ char unk00[0x4];
    /* 0x004 */ char name1[12];
    /* 0x010 */ char name2[40];
    /* 0x038 */ u16 gfx_file_index; // high byte battle_portraits, low byte ukn
    /* 0x03A */ char unk3A[0x1F6];
} TrainerData; // size = 0x230

// GB Emulator State
typedef struct unk_D_8122B2C0 {
    /* 0x00000 */ u8 unk_00[0x208];
    /* 0x00208 */ u8 unk_208[0x40];
    /* 0x00248 */ u8 unk_248[0x40];
    /* 0x00288 */ u8 unk_288[0x100];
    /* 0x00388 */ u8 unk_388[0x400];
    /* 0x00788 */ u8 unk_788[0x4000];
    /* 0x04788 */ u8 unk_4788[0xC00];
    /* 0x05388 */ s32 unk_5388;
    /* 0x0538C */ char unk0538C[4];
    /* 0x05390 */ u32 unk_5390;
    /* 0x05394 */ u32 unk_5394;
    /* 0x05398 */ u32 unk_5398;
    /* 0x0539C */ u32 unk_539C;
    /* 0x053A0 */ char unk053A0[0x4];
    /* 0x053A4 */ u32 unk_53A4;
    /* 0x053A8 */ void* unk_53A8;
    /* 0x053AC */ void* unk_53AC;
    /* 0x053B0 */ void* unk_53B0;
    /* 0x053B4 */ void* unk_53B4;
    /* 0x053B8 */ char unk053B8[0x4];
    /* 0x053BC */ void* unk_53BC;
    /* 0x053C0 */ s32 unk_53C0;
    /* 0x053C4 */ char unk053C4[0x24];
    /* 0x053E8 */ u16 unk_53E8;
    /* 0x053EA */ char unk053EA[0x4];
    /* 0x053EE */ u16 unk_53EE;
    /* 0x053F0 */ u16 unk_53F0;
    /* 0x053F2 */ u16 unk_53F2;
    /* 0x053F4 */ char unk053F4[0x2];
    /* 0x053F6 */ u16 unk_53F6;
    /* 0x053F8 */ char unk053F8[0x4];
    /* 0x053FC */ s8 unk_53FC;
    /* 0x053FD */ s8 unk_53FD;
    /* 0x053FE */ u8 unk_53FE;
    /* 0x053FF */ char unk053FF[0x5];
    /* 0x05404 */ u8 unk_5404;
    /* 0x05405 */ char unk05405[0x80];
    /* 0x05485 */ u8 unk_5485;
    /* 0x05486 */ char unk05486[0x7];
    /* 0x0548D */ u8 unk_548D;
    /* 0x0548E */ u8 unk_548E;
    /* 0x0548F */ char unk0548F[0x1];
    /* 0x05490 */ u8 unk_5490;
    /* 0x05491 */ char unk05491[0xB];
    /* 0x0549C */ volatile u8 unk_549C[0x100];
    /* 0x0559C */ volatile u8 unk_559C[0x10];
    /* 0x055AC */ u8 unk_55AC[0x40];
    /* 0x055EC */ u8 unk_55EC[0x40];
    /* 0x0562C */ u8 unk_562C[0x200];
    /* 0x0582C */ u8 unk_582C[0x200];
    /* 0x05A2C */ u8 unk_5A2C[0x200];
    /* 0x05C2C */ char unk05C2C[0x2C];
    /* 0x05C58 */ void* unk_5C58;
    /* 0x05C5C */ OSGbpakId unk_5C5C;
    /* 0x05CAC */ OSGbpakId gbpakId;
    /* 0x05CFC */ OSPfs* pfs;
    /* 0x05D00 */ char unk05D00[0x64];
    /* 0x05D64 */ u8* transferBuffer;
    /* 0x05D68 */ u32 gbAddress;
    /* 0x05D6C */ s32 transferSize;
    /* 0x05D70 */ u32 unk_5D70[4];
    /* 0x05D80 */ u32 unk_5D80[4];
    /* 0x05D90 */ u32 unk_5D90[4];
    /* 0x05DA0 */ u16 unk_5DA0;
    /* 0x05DA2 */ u16 unk_5DA2;
    /* 0x05DA4 */ u8 unk_5DA4[0x20];
    /* 0x05DC4 */ u8 unk_5DC4;
    /* 0x05DC5 */ u8 unk_5DC5;
    /* 0x05DC6 */ u8 unk_5DC6;
    /* 0x05DC7 */ u8 unk_5DC7;
    /* 0x05DC8 */ volatile u8 unk_5DC8;
    /* 0x05DC9 */ volatile u8 unk_5DC9;
    /* 0x05DCA */ volatile u8 unk_5DCA;
    /* 0x05DCB */ u8 status;
    /* 0x05DCC */ u8 unk_5DCC;
    /* 0x05DCD */ s8 unk_5DCD;
    /* 0x05DCE */ u8 unk_5DCE;
    /* 0x05DCF */ u8 unk_5DCF;
    /* 0x05DD0 */ u8 unk_5DD0;
    /* 0x05DD1 */ u8 unk05DD1[0x15287];
  } unk_D_8122B2C0; // size = 0x1B058

#define GB_HEADER(emu, offset) (((u8*)(emu)->unk_53BC)[offset])

extern s16 D_80075E40[];

#include "variables.h"

#endif
