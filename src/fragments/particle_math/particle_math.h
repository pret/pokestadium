#ifndef _FRAGMENT34_H_
#define _FRAGMENT34_H_

#include "global.h"

struct Particle;
struct ParticleDescriptorChild;
struct Battler;
struct BattleAnimEffectSlot;

typedef void (*ParticleUpdateCallback)(struct Particle*);
typedef void (*ParticleRenderCallback)(struct Particle*, unk_D_86002F34_00C*);
typedef void (*unk_D_8140E728_01C_004_1_04)(struct Particle*, s32, struct ParticleDescriptorChild*);
typedef void (*unk_D_8140E728_01C_004_1_08)(struct Particle*, s32, struct ParticleDescriptorChild*);

typedef struct unk_D_8140E728_01C_00C_1 {
    /* 0x00 */ s32 arg;
} unk_D_8140E728_01C_00C_1;

typedef union unk_D_8140E728_01C_00C {
    s32 arg;
    unk_D_8140E728_01C_00C_1* s;
} unk_D_8140E728_01C_00C;

typedef struct ParticleDescriptorChild {
    /* 0x00 */ u8 unk_00;
    /* 0x00 */ u8 unk_01;
    /* 0x00 */ s16 unk_02;
    /* 0x04 */ unk_D_8140E728_01C_004_1_04 unk_04;
    /* 0x08 */ unk_D_8140E728_01C_004_1_08 unk_08;
    /* 0x0C */ unk_D_8140E728_01C_00C unk_0C;
} ParticleDescriptorChild; // size = 0x10

typedef union ParticleDescriptorPayload {
    ParticleDescriptorChild* a;
    ParticleRenderCallback func;
} ParticleDescriptorPayload;

typedef struct ParticleDescriptor {
    /* 0x00 */ s32 unk_00; /* unk_04: 1 = a, 3 = func */
    /* 0x04 */ ParticleDescriptorPayload unk_04;
} ParticleDescriptor; // size = 0x08

typedef struct ParticleEmitter {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ Vec3s unk_10;
    /* 0x18 */ ParticleUpdateCallback unk_18;
    /* 0x1C */ ParticleDescriptor* unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ s8 unk_2A;
    /* 0x2B */ s8 unk_2B;
    /* 0x2C */ u8 unk_2C;
    /* 0x2D */ u8 unk_2D;
    /* 0x2E */ u8 unk_2E;
    /* 0x2F */ u8 unk_2F;
} ParticleEmitter; // size = 0x30

typedef struct Particle {
    /* 0x00 */ struct Particle* next;
    /* 0x04 */ struct Particle* prev;
    /* 0x08 */ ParticleUpdateCallback unk_08;
    /* 0x0C */ ParticleDescriptor* unk_0C;
    /* 0x10 */ struct Battler* unk_10;
    /* 0x14 */ DisplayObject* unk_14;
    /* 0x18 */ u32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ Vec3f unk_2C;
    /* 0x38 */ Vec3f unk_38;
    /* 0x44 */ char unk44[0xC];
    /* 0x50 */ Vec3f unk_50;
    /* 0x5C */ Vec3f unk_5C;
    /* 0x68 */ Vec3f unk_68;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ f32 unk_78;
    /* 0x7C */ Vec3f unk_7C;
    /* 0x88 */ char unk88[0xC];
    /* 0x94 */ Vec3s unk_94;
    /* 0x9A */ Vec3s unk_9A;
    /* 0xA0 */ Vec3s unk_A0;
    /* 0xA6 */ s16 unk_A6;
    /* 0xA8 */ s16 unk_A8;
    /* 0xAA */ s16 unk_AA;
    /* 0xAC */ s16 unk_AC;
    /* 0xAE */ s16 unk_AE;
    /* 0xB0 */ s16 unk_B0;
    /* 0xB2 */ s16 unk_B2;
    /* 0xB4 */ char unkB4[0x2];
    /* 0xB6 */ s16 unk_B6;
    /* 0xB8 */ s16 unk_B8;
    /* 0xBA */ s16 unk_BA;
    /* 0xBC */ s16 unk_BC;
    /* 0xBE */ u8 prim_r;
    /* 0xBF */ u8 prim_g;
    /* 0xC0 */ u8 prim_b;
    /* 0xC1 */ u8 env_r;
    /* 0xC2 */ u8 env_g;
    /* 0xC3 */ u8 env_b;
    /* 0xC4 */ u8 prim_a;
    /* 0xC5 */ char unkC5[0x1];
    /* 0xC6 */ s8 unk_C6;
    /* 0xC7 */ s8 unk_C7;
    /* 0xC8 */ char unkC8[0x2];
    /* 0xCA */ u8 unk_CA;
    /* 0xCB */ u8 unk_CB;
    /* 0xCC */ u8 unk_CC;
    /* 0xCD */ u8 unk_CD;
    /* 0xCE */ u8 unk_CE;
    /* 0xCF */ u8 unk_CF;
    /* 0xD0 */ s8 unk_D0;
} Particle; // size = 0xD4

typedef void (*func_unk_D_8140E724)(struct Particle*);

typedef struct BattleAnimEffectSlot {
    /* 0x00 */ func_unk_D_8140E724 unk_00;
    /* 0x04 */ ParticleDescriptor* unk_04;
    /* 0x08 */ struct Battler* unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s8 unk_14;
    /* 0x15 */ s8 unk_15;
    /* 0x16 */ u8 unk_16;
    /* 0x17 */ u8 unk_17;
    /* 0x18 */ u8 unk_18;
    /* 0x19 */ u8 unk_19;
    /* 0x1A */ u8 unk_1A;
    /* 0x1B */ u8 unk_1B;
} BattleAnimEffectSlot; // size = 0x1C

typedef struct arg1_func_87903D64_014 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_D_86002F34_000_014_004* unk_04;
    /* 0x08 */ unk_D_86002F34_000_014_004* unk_08;
    /* 0x0C */ unk_D_86002F34_000_014_004* unk_0C;
    /* 0x10 */ unk_D_86002F34_000_014_010* unk_10;
    /* 0x14 */ unk_D_86002F34_000_014_010* unk_14;
    /* 0x18 */ unk_D_86002F34_000_014_010* unk_18;
} arg1_func_87903D64_014; // size = 0x1C

// Possibly unk_D_86002F34_alt7, unk_D_86002F34_alt8,
// unk_D_86002F34_alt9 or unk_D_86002F34_alt2
typedef struct arg1_func_87903D64 {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ arg1_func_87903D64_014* unk_14;
    /* 0x18 */ Gfx* unk_18;
} arg1_func_87903D64; // size >= 0x1C

typedef struct arg1_func_81407874_014_000_014_000_000 {
    /* 0x00 */ Color_RGBA8 color;
    /* 0x04 */ u8 l;
} arg1_func_81407874_014_000_014_000_000; // size = 0x5

typedef struct arg1_func_81407874_014_000_018_000_000 {
    /* 0x00 */ Color_RGBA8 color;
} arg1_func_81407874_014_000_018_000_000; // size = 0x4

typedef union arg1_func_81407874_014_000_014_000 {
    arg1_func_81407874_014_000_014_000_000* ptr5;
    arg1_func_81407874_014_000_018_000_000* ptr4;
    Color_RGBA8_u32 color;
    u8** texture;
} arg1_func_81407874_014_000_014_000; // size = 0x4

typedef struct arg1_func_81407874_014_000_014 {
    /* 0x00 */ arg1_func_81407874_014_000_014_000 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} arg1_func_81407874_014_000_014; // size >= 0x08

typedef struct arg1_func_81407874_014_000_01C {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
} arg1_func_81407874_014_000_01C; // size >= 0x04

typedef struct arg1_func_81407874_014_000 {
    /* 0x00 */ struct arg1_func_81407874_014_000* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk08[0x8];
    /* 0x10 */ arg1_func_81407874_014_000_010* unk_10;
    /* 0x14 */ arg1_func_81407874_014_000_014* unk_14;
    /* 0x18 */ arg1_func_81407874_014_000_014* unk_18;
    /* 0x1C */ arg1_func_81407874_014_000_01C* unk_1C;
} arg1_func_81407874_014_000; // size >= 0x20

typedef struct arg1_func_81407874_014_004_008 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
} arg1_func_81407874_014_004_008; // size >= 0xA

typedef struct arg1_func_81407874_014_004_004 {
    /* 0x00 */ s16 fmt;
    /* 0x02 */ s16 size;
    /* 0x04 */ s16 width;
    /* 0x06 */ s16 height;
    /* 0x08 */ s16 cms;
    /* 0x0A */ s16 cmt;
    /* 0x0C */ s16 masks;
    /* 0x0E */ s16 maskt;
    /* 0x10 */ s16 shfits;
    /* 0x12 */ s16 shiftt;
} arg1_func_81407874_014_004_004; // size >= 0x14

typedef struct arg1_func_81407874_014_004 {
    /* 0x00 */ arg1_func_81407874_014_000* unk_00;
    /* 0x04 */ arg1_func_81407874_014_004_004* unk_04;
    /* 0x08 */ arg1_func_81407874_014_004_008* unk_08;
    /* 0x0C */ arg1_func_81407874_014_000_014* unk_0C;
} arg1_func_81407874_014_004; // size >= 0x4

typedef struct arg1_func_81407874_014 {
    /* 0x00 */ arg1_func_81407874_014_000* unk_00;
    /* 0x04 */ arg1_func_81407874_014_004* unk_04;
} arg1_func_81407874_014; // size >= 0x8

typedef struct arg1_func_81407874 {
    /* 0x00 */ char unk00[0x14];
    /* 0x00 */ arg1_func_81407874_014* unk_14;
} arg1_func_81407874; // size >= 0x18

typedef struct ParticleCameraState {
    /* 0x00 */ MtxF unk_00;
    /* 0x40 */ Vec3f unk_40;
    /* 0x4C */ Vec3f unk_4C;
    /* 0x58 */ Vec3f unk_58;
    /* 0x64 */ Vec3f unk_64;
    /* 0x70 */ s16 unk_70;
    /* 0x72 */ s16 unk_72;
    /* 0x74 */ char unk74[0x2];
    /* 0x76 */ s16 unk_76;
    /* 0x78 */ s16 unk_78;
} ParticleCameraState; // size = 0x7C

typedef struct ParticleRenderContext {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ unk_D_86002F34_00C* unk_0C;
    /* 0x10 */ ParticleCameraState unk_10;
} ParticleRenderContext; // size = 0x8C

typedef struct ParticleMatrixPool {
    /* 0x0000 */ MtxF unk_0000[364];
    /* 0x5B00 */ char unk5B00[0x80];
    /* 0x5B80 */ Mtx unk_5B80;
    /* 0x5BC0 */ char unk5BC0[0x20];
} ParticleMatrixPool; // size = 0x5BE0

extern Gfx D_8140DAE0[];
extern Gfx D_8140DB30[];
extern Gfx D_8140DBA8[];
extern Gfx D_8140DC00[];
extern Gfx D_8140DC58[];
extern Gfx D_8140DC78[];
extern Gfx D_8140DC98[];
extern Gfx D_8140DCB8[];
extern Gfx D_8140DCD8[];
extern Gfx D_8140DCF8[];
extern Gfx D_8140DD18[];
extern Gfx D_8140DD38[];
extern Gfx D_8140DD58[];
extern Gfx D_8140DD78[];
extern Gfx D_8140DDD8[];
extern Gfx D_8140DDF8[];
extern Vtx D_8140DE78[];
extern Vtx D_8140DEF8[];
extern Vtx D_8140DF78[];
extern Vtx D_8140DFA8[];
extern Vtx D_8140DFD8[];
extern Vtx D_8140E018[];
extern Vtx D_8140E058[];
extern Vtx D_8140E098[];
extern Vtx D_8140E0D8[];
extern Vtx D_8140E108[];
extern Vtx D_8140E148[];
extern Vtx D_8140E178[];
extern Vtx D_8140E1B8[];
extern Vtx D_8140E1F8[];
extern Vtx D_8140E238[];
extern Vtx D_8140E2B8[];
extern Vtx D_8140E378[];
extern Vtx D_8140E3B8[];
extern Gfx D_8140E418[];
extern Gfx D_8140E430[];
extern Gfx D_8140E448[];
extern ParticleDescriptor gDefaultParticleDescriptor;

extern u8 gParticlePaletteSetA[];

extern ParticleMatrixPool* gParticleMatrixPool;
extern s32 gParticleMatrixPoolIndex;
extern s32 gParticleMatrixPoolIndex;
extern ParticleRenderContext gParticleRenderContext;
extern ParticleCameraState* gParticleCameraState;
extern u32 gParticleFrameCounter;
extern s32 gParticleFrameMod64;
extern s32 gParticleFrameMod32;
extern s32 gParticleFrameMod16;
extern s32 gParticleFrameMod8;
extern s32 gParticleFrameMod4;
extern u32 gParticleFrameMod3;
extern s32 gParticleFrameMod2;
extern u32 gParticleFrameDiv64;
extern u32 gParticleFrameDiv32;
extern u32 gParticleFrameDiv16;
extern u32 gParticleFrameDiv8;
extern u32 gParticleFrameDiv4;
extern u32 gParticleFrameDiv3;
extern u32 gParticleFrameDiv2;
extern s32 gParticleFrameDiv64Parity;
extern s32 gParticleFrameDiv32Parity;
extern s32 gParticleFrameDiv16Parity;
extern s32 gParticleFrameDiv8Parity;
extern s32 gParticleFrameDiv4Parity;
extern s32 gParticleFrameDiv3Parity;
extern s32 gParticleFrameDiv2Parity;
extern s32 gParticleRandomOffset;
extern Particle* gParticlePool;
extern BattleAnimEffectSlot* gBattleAnimEffectSlots;
extern ParticleEmitter* gMiniFxEmitters;
extern s32 gParticlePoolIndex;
extern s32 gBattleAnimEffectSlotIndex;
extern s32 gMiniFxEmitterIndex;

void ParticleMath_BitwiseOr(s32* arg0, s32 arg1);
void ParticleMath_BitwiseAndNot(s32* arg0, s32 arg1);
void ParticleMath_BitwiseXor(s32* arg0, s32 arg1);
s32 ParticleMath_HasBits(s32* arg0, s32 arg1);
s32 ParticleMath_LacksBits(s32* arg0, s32 arg1);
s32 ParticleMath_ApproachFloatUp(f32* arg0, f32 arg1, f32 arg2);
s32 ParticleMath_ApproachFloatDown(f32* arg0, f32 arg1, f32 arg2);
s32 ParticleMath_ApproachS32Up(s32* arg0, s32 arg1, s32 arg2);
s32 ParticleMath_ApproachS32Down(s32* arg0, s32 arg1, s32 arg2);
s32 ParticleMath_ApproachS16Up(s16* arg0, s16 arg1, s16 arg2);
s32 ParticleMath_ApproachU16Up(u16* arg0, u16 arg1, u16 arg2);
s32 ParticleMath_ApproachS16Down(s16* arg0, s16 arg1, s16 arg2);
s32 ParticleMath_ApproachU16Down(u16* arg0, s32 arg1, s32 arg2);
s32 ParticleMath_ApproachFloatUpByPointer(f32* arg0, f32 arg1, f32* arg2);
s32 ParticleMath_ApproachFloatDownByPointer(f32* arg0, f32 arg1, f32* arg2);
s32 ParticleMath_ApproachS32UpByPointer(s32* arg0, s32 arg1, s32* arg2);
s32 ParticleMath_ApproachS32DownByPointer(s32* arg0, s32 arg1, s32* arg2);
s32 ParticleMath_ApproachS16UpByPointer(s16* arg0, s16 arg1, s16* arg2);
s32 ParticleMath_ApproachS16DownByPointer(s16* arg0, s16 arg1, s16* arg2);
s32 ParticleMath_ApproachS8(s8* arg0, s8 arg1, s8 arg2);
s32 ParticleMath_ApproachU8(u8* arg0, u8 arg1, u8 arg2);
s32 ParticleMath_ApproachS16(s16* arg0, s16 arg1, s16 arg2);
s32 ParticleMath_ApproachAngle(s16* arg0, s16 arg1, s16 arg2);
s32 ParticleMath_ApproachS32(s32* arg0, s32 arg1, s32 arg2);
s32 ParticleMath_ApproachFloat(f32* arg0, f32 arg1, f32 arg2);
void ParticleMath_BounceFloat(f32* arg0, f32 arg1, f32 arg2, f32* arg3);
void ParticleMath_BounceS16(s16* arg0, s16 arg1, s16 arg2, s16* arg3);
void ParticleMath_CopyVec3f(Vec3f* arg0, Vec3f* arg1);
void ParticleMath_CopyVec3s(Vec3s* arg0, Vec3s* arg1);
void ParticleMath_AddVec3f(Vec3f* arg0, Vec3f* arg1);
void ParticleMath_AddVec3s(Vec3s* arg0, Vec3s* arg1);
f32 ParticleMath_DotVec3f(Vec3f arg0, Vec3f arg1);
s32 ParticleMath_IsWithinRadius2D(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void ParticleMath_AdvanceRandomOffset(void);
u32 ParticleMath_RandomRange(s32 arg0);
s32 ParticleMath_RandomRangeOffset(s32 arg0, s32 arg1);
s32 ParticleMath_RandomSigned(s32 arg0);
s32 ParticleMath_RandomSignedOffset(s32 arg0, s32 arg1);
s32 ParticleMath_RandomSignedOffsetBySign(s32 arg0, s32 arg1);
void ParticleMath_NoopStub(UNUSED s32 arg0);
s16 ParticleMath_Atan2YZ(Vec3f arg0);
s16 ParticleMath_Atan2ZX(Vec3f arg0);
s16 ParticleMath_Atan2XY(Vec3f arg0);
void ParticleMath_Vec3ToAngles(Vec3s* arg0, Vec3f arg1);
f32 ParticleMath_Rotate2DX(f32 arg0, f32 arg1, s16 arg2);
f32 ParticleMath_Rotate2DY(f32 arg0, f32 arg1, s16 arg2);
Vec3f* ParticleMath_RotateVec3fY(Vec3f* arg0, Vec3f arg1, Vec3s arg4);
Vec3f* ParticleMath_MakeXZVectorFromAngle(Vec3f* arg0, f32 arg1, s16 arg2);
Vec3f* ParticleMath_RotateVec3fXY(Vec3f* arg0, Vec3f arg1, Vec3s arg4);
f32 ParticleMath_Distance3D(Vec3f arg0, Vec3f arg1);
f32 ParticleMath_DistanceXZ(Vec3f arg0, Vec3f arg1);
Vec3f* ParticleMath_NormalizedDirection(Vec3f* arg0, Vec3f arg1, Vec3f arg2);
s32 ParticleMath_DistanceScaled(Vec3f arg0, Vec3f arg1, f32 arg2);
s32 ParticleMath_ScaleDirectionToLength(Vec3f* arg0, Vec3f arg1, Vec3f arg2, f32 arg3);
Vec3f* ParticleMath_RandomDirection(Vec3f* arg0, f32 arg1);
Vec3f* ParticleMath_ScaleVec3f(Vec3f* arg0, f32 arg1);
s16 ParticleMath_AngleXBetweenPoints(Vec3f arg0, Vec3f arg1);
s16 ParticleMath_AngleYBetweenPoints(Vec3f arg0, Vec3f arg1);
s16 ParticleMath_AngleZBetweenPoints(Vec3f arg0, Vec3f arg1);
s16 ParticleMath_ApproachAngleCoarse(s16 arg0, s16 arg1);
void ParticleGfx_NoopStub1(void);
void ParticleGfx_PushMatrix(MtxF* arg0);
void ParticleGfx_Build2DTransformMatrix(MtxF* arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
void ParticleGfx_Build2DTransformMatrixYScaled(MtxF* arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
void ParticleGfx_Push2DTransform(s16 arg0, s16 arg1, s16 arg2, f32 arg3);
void ParticleGfx_Push2DTransformYScaled(s16 arg0, s16 arg1, s16 arg2, f32 arg3);
void ParticleGfx_BuildTransformMatrix(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3);
void ParticleGfx_BuildTransformMatrixYScaled(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3);
void ParticleGfx_BuildTransformMatrixXYScaled(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3, f32 arg4);
void ParticleGfx_BuildBillboardMatrix(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3);
void ParticleGfx_BuildBillboardMatrixYScaled(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3);
void ParticleGfx_BuildBillboardRotatedMatrix(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3, s16 arg4);
void ParticleGfx_BuildBillboardRotatedMatrixYScaled(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3, s16 arg4);
void ParticleGfx_BuildDirectionMatrix(MtxF* arg0, Vec3f arg1, Vec3f arg2, s16 arg3, f32 arg4);
void ParticleGfx_PushTransformMatrix(Vec3f arg0, Vec3s arg1, f32 arg2);
void ParticleGfx_PushTransformMatrixYScaled(Vec3f arg0, Vec3s arg1, f32 arg2);
void ParticleGfx_PushTransformMatrixXYScaled(Vec3f arg0, Vec3s arg1, f32 arg2, f32 arg3);
void ParticleGfx_PushBillboardMatrix(unk_D_86002F34_00C* arg0, Vec3f arg1, f32 arg4);
void ParticleGfx_PushBillboardRotatedMatrix(unk_D_86002F34_00C* arg0, Vec3f arg1, f32 arg4, s16 arg5);
void ParticleGfx_PushBillboardMatrixYScaled(unk_D_86002F34_00C* arg0, Vec3f arg1, f32 arg4);
void ParticleGfx_PushBillboardRotatedMatrixYScaled(unk_D_86002F34_00C* arg0, Vec3f arg1, f32 arg4, s16 arg5);
void ParticleGfx_PushTransformMatrixWithHalfTurnXY(Vec3f arg0, Vec3s arg3, f32 arg5);
void ParticleGfx_PushDirectionMatrix(Vec3f arg0, Vec3f arg3, f32 arg6);


void ParticleGfx_PipeSync(void);
void ParticleGfx_SetTextureState(void);
s32 ParticleGfx_TextureSizeLog2(s32 size);
void ParticleGfx_NoopStub2(void);
void ParticleGfx_NoopStub3(void);
void ParticleGfx_NoopStub4(void);
void ParticleGfx_NoopStub5(void);
void ParticleGfx_NoopStub6(void);
void ParticleGfx_NoopStub7(void);
void ParticleGfx_NoopStub8(void);
void ParticleGfx_NoopStub9(void);
void ParticleGfx_LoadTextureBlock32(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void ParticleGfx_LoadTextureTile32(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void ParticleGfx_LoadTextureBlock16(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void ParticleGfx_LoadTextureTile16(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void ParticleGfx_LoadTextureBlock8(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void ParticleGfx_LoadTextureTile8(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void ParticleGfx_LoadTextureBlock4(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void ParticleGfx_LoadTextureTile4(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void ParticleGfx_LoadTextureMultiBlock4(u8* texture, s32 tmem, s32 rtile, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void ParticleGfx_LoadTextureRgba32(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureTileRgba32(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureRgba16(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureRgba16Dual(u8* texture1, u8* texture2, s32 width, s32 height);
void ParticleGfx_LoadTextureRgba16WrapS(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureRgba16WrapT(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureRgba16WrapST(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureRgba16WrapSWithMask(u8* texture, s32 width, s32 height, s32 masks);
void ParticleGfx_LoadTextureTileRgba16(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureIa16(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureTileIa16(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureIa8(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureTileIa8(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureIa8WrapST(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureI8(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureI8WrapST(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureTileI8(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureI8Alias(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureTileI8Alias(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureTileIa4(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureTileI4(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureIa4(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureI4(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureI4WrapST(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureI4Alias(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureTileI4Alias(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureI4WrapS(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureI4WrapSTNoMirror(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureI4MultiBlockWrapST(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureI4MultiBlockWrapSTWithShift(u8* texture, s32 width, s32 height, s32 shifts, s32 shiftt);
void ParticleGfx_LoadTextureCi8(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureCi8WrapSWithMask(u8* texture, s32 width, s32 height, s32 masks);
void ParticleGfx_LoadTextureTileCi8(u8* texture, s32 width, s32 height);
void ParticleGfx_LoadTextureDualRgba16I8(u8* texture1, u8* texture2, s32 width, s32 height);
void ParticleGfx_DrawQuadVertices(Vtx* arg0);
void ParticleGfx_NoopStub10(void);
void ParticleGfx_DrawTransformedQuad(Vec3f arg0, Vec3s arg1, f32 arg2, Vtx* arg3);
void ParticleGfx_DrawTransformedQuadYScaled(Vec3f arg0, Vec3s arg1, f32 arg3, Vtx* arg4);
void ParticleGfx_DrawTransformedQuadXYScaled(Vec3f arg0, Vec3s arg1, f32 arg2, f32 arg3, Vtx* arg4);
void ParticleGfx_DrawTransformedTriangle(Vec3f arg0, Vec3s arg1, f32 arg2, Vtx* arg3);
void ParticleGfx_DrawModelQuad(unk_D_86002F34_00C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3);
void ParticleGfx_DrawModelQuadRotated(unk_D_86002F34_00C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3, s16 arg4);
void ParticleGfx_DrawModelQuadYScaled(unk_D_86002F34_00C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3);
void ParticleGfx_DrawModelQuadRotatedYScaled(unk_D_86002F34_00C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3, s16 arg4);
void ParticleGfx_DrawModelTriangle(unk_D_86002F34_00C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3);
void ParticleGfx_DrawModelTriangleRotated(unk_D_86002F34_00C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3, s16 arg4);
void ParticleGfx_DrawI8TextureAtlas(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height);
void ParticleGfx_DrawIa16TextureAtlas(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height);
void ParticleGfx_DrawIa8TextureAtlas(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height);
void ParticleGfx_DrawI4TextureAtlas(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height);
void ParticleGfx_DrawI4TextureAtlasTiled(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height);
void ParticleGfx_SetPrimColor(u8 r, u8 g, u8 b, u8 a);
void ParticleGfx_SetEnvColor(u8 r, u8 g, u8 b, u8 a);
void ParticleGfx_SetFogColor(u8 r, u8 g, u8 b, u8 a);
void ParticleGfx_SetBlendColor(u8 r, u8 g, u8 b, u8 a);
void ParticleGfx_SetPrimColorTextureCombine(u8 r, u8 g, u8 b, u8 a);
void ParticleGfx_SetTextureAlphaCombine(u8 a);
void ParticleGfx_SetPrimEnvColorCombine(u8 prim_r, u8 prim_g, u8 prim_b, u8 env_r, u8 env_g, u8 env_b, u8 prim_a);
void ParticleGfx_SetPrimEnvNoiseCombine(u8 prim_r, u8 prim_g, u8 prim_b, u8 env_r, u8 env_g, u8 env_b, u8 prim_a);
void ParticleGfx_SetPrimEnvColorShadeCombine(u8 prim_r, u8 prim_g, u8 prim_b, u8 prim_a, u8 env_r, u8 env_g, u8 env_b, u8 env_a);
void ParticleGfx_SetPrimEnvLodCombine(u8 l, u8 prim_r, u8 prim_g, u8 prim_b, u8 prim_a, u8 env_r, u8 env_g, u8 env_b);
void ParticleGfx_SetPrimEnvLodTextureCombine(u8 l, u8 prim_r, u8 prim_g, u8 prim_b, u8 prim_a, u8 env_r, u8 env_g, u8 env_b);
u32 ParticleGfx_GetFrameDivisor(s32 arg0);
void ParticleGfx_SetAnimatedTileSize(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void ParticleGfx_SetAnimatedAuxTileSize(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void ParticleGfx_SetAnimatedTileSizeOnList(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void ParticleGfx_SetAnimatedAuxTileSizeOnList(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void ParticleGfx_SetPartiallyAnimatedTileSize(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void ParticleGfx_SetPartiallyAnimatedAuxTileSize(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void ParticleGfx_SetFrameIndexedTileSize(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void ParticleGfx_SetFrameIndexedAuxTileSize(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void ParticleGfx_LoadTextureI4ToList(Gfx* gfx, u8* texture, s32 width, s32 height);
Gfx* ParticleGfx_LoadDescriptorTexture(Gfx* arg0, u8* texture, arg1_func_81407874_014_004* arg2, s32 tmem, s32 rtile);
Gfx* ParticleGfx_LoadDescriptorTextureAndTile(Gfx* arg0, arg1_func_81407874_014_004* arg1, s32 tmem, s32 rtile);
Gfx* ParticleGfx_LoadPrimaryDescriptorTexture(Gfx* arg0, arg1_func_81407874_014* arg1);
Gfx* ParticleGfx_LoadSecondaryDescriptorTexture(Gfx* arg0, arg1_func_81407874_014* arg1);
void ParticleGfx_SetCombineModeFromDescriptor(Gfx* arg0, arg1_func_81407874_014_000_010* arg1);
Gfx* func_81407590(Gfx* arg0, arg1_func_81407874_014* arg1);
void ParticleGfx_GraphNodeBuildDescriptorMaterialList(s32 arg0, arg1_func_87903D64* arg1);


void Particle_ResetDefaults(Particle* arg0);
Particle* Particle_Alloc(void);
void Particle_Free(Particle* arg0);
Particle* Particle_New(void);
Particle* Particle_AllocChain(u8 arg0);
void Particle_EmitBurstAtTransform(f32 arg0, Vec3f arg1, Vec3s arg2, ParticleUpdateCallback arg3, ParticleDescriptor* arg4, s16 arg5);
void Particle_EmitBurstAtTransformWithMetadata(f32 arg0, Vec3f arg1, Vec3s arg2, ParticleUpdateCallback arg3, ParticleDescriptor* arg4, s16 arg5, s16 arg6);
void Particle_EmitBurstFromObject(DisplayObject* arg0, ParticleUpdateCallback arg1, ParticleDescriptor* arg2, s16 arg3, s16 arg4);
void Particle_EmitBurstFromObjectWithMetadata(DisplayObject* arg0, ParticleUpdateCallback arg1, ParticleDescriptor* arg2, s16 arg3, s16 arg4, s16 arg5);
s32 Particle_CountActive(void);
s32 Particle_CountActiveAlias(void);
void Particle_InitLifecycle(Particle* arg0);
void Particle_MarkInactive(Particle* arg0);
void Particle_DisableAndDetach(Particle* arg0);
s32 Particle_IsInactive(Particle* arg0);
s32 Particle_IsRunning(Particle* arg0);
void Particle_AdvanceLifecycle(Particle* arg0);
s32 Particle_TickDelayTimer(Particle* arg0, s16 arg1);
s32 Particle_TickDelayAndAdvanceLifecycle(Particle* arg0, s16 arg1);
void Particle_SetFlags(Particle* arg0, s32 arg1);
void Particle_ClearFlags(Particle* arg0, s32 arg1);
void Particle_ToggleFlags(Particle* arg0, s32 arg1);
s32 Particle_HasFlags(Particle* arg0, s32 arg1);
s32 Particle_LacksFlags(Particle* arg0, s32 arg1);
void Particle_EnableRendering(Particle* arg0);
void Particle_DisableRendering(Particle* arg0);
s32 Particle_IsRenderingEnabled(Particle* arg0);
void Particle_EnableFlag40(Particle* arg0);
void Particle_DisableFlag40(Particle* arg0);
void Particle_HasFlag40(Particle* arg0);
void Particle_SetTextureFrame(Particle* arg0, s16 arg1);
s32 Particle_AnimateFramesForward(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
s32 Particle_AnimateFramesForwardAndAdvanceLifecycle(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
s32 Particle_AnimateFramesReverse(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
s32 Particle_AnimateFramesReverseAndAdvanceLifecycle(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
s32 Particle_AnimateFramesPingPong(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
s32 Particle_AnimateFramesPingPongAndAdvanceLifecycle(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
s32 Particle_AnimateFramesReverseFirstPingPong(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
s32 Particle_AnimateFramesReverseFirstPingPongAndAdvanceLifecycle(Particle* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
void Particle_BeginPhase(Particle* arg0);
void Particle_ResetPhase(Particle* arg0);
void Particle_AdvancePhase(Particle* arg0);
s32 Particle_TickPhaseTimer(Particle* arg0, s16 arg1);
void Particle_UpdateWorldTransform(Particle* arg0);
void Particle_SetPosition(Particle* arg0, f32 arg1, f32 arg2, f32 arg3);
void Particle_Field38_SetVecFromVec3fScaled_08C20(Particle* arg0, Vec3f arg1);
void Particle_Field38_SetVec_08C68(Particle* arg0, f32 arg1, f32 arg2, f32 arg3);
void Particle_Field38_SetXScaled_08C88(Particle* arg0, f32 arg1);
void Particle_Field38_SetYScaled_08CA0(Particle* arg0, f32 arg1);
void Particle_Field38_SetZScaled_08CB8(Particle* arg0, f32 arg1);
void Particle_SetPositionFromRotationTemplate1(Particle* arg0, f32 arg1);
void Particle_SetPositionFromRotationTemplate2(Particle* arg0, f32 arg1);
void Particle_Field38_AddVecScaledFromVec3f_08D78(Particle* arg0, Vec3f arg1);
void Particle_Field38_AddVecFromVec3f_08DD8(Particle* arg0, Vec3f arg1);
void Particle_Field38_AddVecScaled_08E18(Particle* arg0, f32 arg1, f32 arg2, f32 arg3);
void Particle_Field38_AddXScaled_08E70(Particle* arg0, f32 arg1);
void Particle_Field38_AddYScaled_08E90(Particle* arg0, f32 arg1);
void Particle_Field38_AddZScaled_08EB0(Particle* arg0, f32 arg1);
void Particle_Field38_AddXZFromField94Y_08ED0(Particle* arg0, f32 arg1);
void Particle_Field38_AddXZFromField94YOffset180_08F38(Particle* arg0, f32 arg1);
void Particle_Field38_AddXZFromField94YOffset90_08FAC(Particle* arg0, f32 arg1);
void Particle_Field38_AddXZFromField94YOffsetMinus90_0901C(Particle* arg0, f32 arg1);
void func_8140908C(Particle* arg0, f32 arg1);
void Particle_AddPositionFromRotationTemplate1(Particle* arg0, f32 arg1);
void Particle_AddPositionFromRotationTemplate2(Particle* arg0, f32 arg1);
void Particle_AddPositionRotatedVectorByYaw(Particle* arg0, Vec3f arg1);
void func_81409248(Particle* arg0, s32 arg1);
void func_81409288(Particle* arg0, s32 arg1);
void func_814092C8(Particle* arg0, s32 arg1);
void func_81409308(Particle* arg0, s32 arg1, s32 arg2);
void func_8140935C(Particle* arg0, s32 arg1, s32 arg2);
void func_814093B0(Particle* arg0, s32 arg1, s32 arg2);
void func_81409404(Particle* arg0, s32 arg1, s32 arg2);
void func_8140948C(Particle* arg0, s32 arg1, s32 arg2);
void func_81409514(Particle* arg0, s32 arg1, s32 arg2);
void func_8140959C(Particle* arg0, s32 arg1, s32 arg2, s32 arg3);
void func_81409634(Particle* arg0, s32 arg1, s32 arg2, s32 arg3);
void func_81409708(Particle* arg0, s32 arg1, s32 arg2);
void func_814097D8(Particle* arg0, s32 arg1, s32 arg2, s32 arg3);
void Particle_SetOrigin(Particle* arg0, f32 arg1, f32 arg2, f32 arg3);
void Particle_SetVelocity(Particle* arg0, f32 arg1, f32 arg2, f32 arg3);
void Particle_Field50_SetXScaled_098E8(Particle* arg0, f32 arg1);
void Particle_Field50_SetYScaled_09900(Particle* arg0, f32 arg1);
void Particle_Field50_SetZScaled_09918(Particle* arg0, f32 arg1);
void Particle_SetVelocityRandomDirection(Particle* arg0, f32 arg1);
void Particle_Field50_AddVecScaled_09968(Particle* arg0, f32 arg1, f32 arg2, f32 arg3);
void Particle_Field50_AddXScaled_099C0(Particle* arg0, f32 arg1);
void Particle_Field50_AddYScaled_099E0(Particle* arg0, f32 arg1);
void Particle_Field50_AddZScaled_09A00(Particle* arg0, f32 arg1);
void Particle_Field50_SubVecScaled_09A20(Particle* arg0, f32 arg1, f32 arg2, f32 arg3);
void Particle_Field50_SubXScaled_09A78(Particle* arg0, f32 arg1);
void Particle_Field50_SubYScaled_09A98(Particle* arg0, f32 arg1);
void Particle_Field50_SubZScaled_09AB8(Particle* arg0, f32 arg1);
s32 Particle_Field50_ApproachXToField5C_09AD8(Particle* arg0, f32 arg1);
s32 Particle_Field50_ApproachYToField5C_09B18(Particle* arg0, f32 arg1);
s32 Particle_Field50_ApproachZToField5C_09B58(Particle* arg0, f32 arg1);
void Particle_Field50_SetVecFromField7C_09B98(Particle* arg0);
void Particle_Field50_SetXZFromField7C_09BB4(Particle* arg0);
void Particle_Field50_SetXYFromField7C_09BC8(Particle* arg0);
void Particle_Field50_AddVecFromField7C_09BDC(Particle* arg0);
void Particle_Field50_AddXZFromField7C_09C10(Particle* arg0);
void Particle_Field50_AddXYFromField7C_09C34(Particle* arg0);
void Particle_Field50_AddXFromField7C_09C58(Particle* arg0);
void Particle_Field50_AddYFromField7C_09C6C(Particle* arg0);
void Particle_Field50_AddZFromField7C_09C80(Particle* arg0);
void Particle_SetVelocityXZFromRotationY(Particle* arg0);
void Particle_AddVelocityXZFromRotationYViaImpulse(Particle* arg0);
void Particle_AddVelocityXYFromRotationZViaImpulse(Particle* arg0);
void Particle_AddVelocityFromRotationTemplate1(Particle* arg0);
void Particle_AddVelocityFromRotationTemplate2(Particle* arg0);
void Particle_AddVelocityFromRotationTemplate3(Particle* arg0);
void Particle_AddVelocityFromRotationTemplate4(Particle* arg0);
void Particle_AddVelocityFromRotationTemplate5(Particle* arg0);
void Particle_AddVelocityFromRotationTemplate6(Particle* arg0);
void Particle_AddVelocityFromRotationTemplate7A(Particle* arg0);
void Particle_AddVelocityFromRotationTemplate7B(Particle* arg0);
void Particle_AddVelocityXZFromRotationY(Particle* arg0);
void Particle_AddVelocityXZFromRotationYPlusHalfTurn(Particle* arg0);
void Particle_AddVelocityXZFromRotationYPlusHalfTurnFromArgument(Particle* arg0, f32 arg1);
void Particle_AddVelocityYFromFieldOffset74(Particle* arg0);
s32 Particle_Field50_AddNegField74Y_CheckField2CYNonPositive_09F84(Particle* arg0);
s32 Particle_Field74_AdvanceAndAddNegY_CheckField2CYNonPositive_09FD8(Particle* arg0);
void Particle_SetVelocityTarget(Particle* arg0, f32 arg1, f32 arg2, f32 arg3);
void Particle_Field5C_SetXScaled_0A07C(Particle* arg0, f32 arg1);
void Particle_Field5C_SetYScaled_0A094(Particle* arg0, f32 arg1);
void Particle_Field5C_SetZScaled_0A0AC(Particle* arg0, f32 arg1);
s32 Particle_Field5C_ApproachY_0A0C4(Particle* arg0, f32 arg1, f32 arg2);
f32 ParticleMath_ScaleApproachStep(f32 arg0);
void Particle_ApproachPosition(Particle* arg0, Vec3f arg1);
void Particle_Field94_SetVecFromVec3s_0A24C(Particle* arg0, Vec3s arg1);
void Particle_SetRotation(Particle* arg0, s16 arg1, s16 arg2, s16 arg3);
void Particle_Field94_SetX_0A2A4(Particle* arg0, s16 arg1);
void Particle_Field94_SetY_0A2B8(Particle* arg0, s16 arg1);
void Particle_Field94_SetZ_0A2CC(Particle* arg0, s16 arg1);
void Particle_Field94_AddConstantAll_0A2E0(Particle* arg0);
void Particle_Field94_AddXConstant_0A30C(Particle* arg0);
void Particle_Field94_AddYConstant_0A320(Particle* arg0);
void Particle_Field94_AddZConstant_0A334(Particle* arg0);
void Particle_SetRotationSpeed(Particle* arg0, s16 arg1, s16 arg2, s16 arg3);
void Particle_Field9A_SetVecFromVec3s_0A37C(Particle* arg0, Vec3s arg1);
void Particle_Field9A_SetXY_0A3A0(Particle* arg0, s16 arg1, s16 arg2);
void Particle_Field9A_SetX_0A3C4(Particle* arg0, s16 arg1);
void Particle_Field9A_SetY_0A3D8(Particle* arg0, s16 arg1);
void Particle_Field9A_SetZ_0A3EC(Particle* arg0, s16 arg1);
void Particle_FieldA0_SetX_0A400(Particle* arg0, s16 arg1);
void Particle_FieldA0_SetY_0A414(Particle* arg0, s16 arg1);
void Particle_SetRotationTargetXY(Particle* arg0, s16 arg1, s16 arg2);
void Particle_SetRotationTargetFromCurrent(Particle* arg0);
void Particle_Field94_AddVecFromField9A_0A480(Particle* arg0);
void Particle_Field94_AddXFromField9A_0A4B4(Particle* arg0);
void Particle_Field94_AddYFromField9A_0A4C8(Particle* arg0);
void Particle_Field94_AddZFromField9A_0A4DC(Particle* arg0);
void Particle_Field94_AddVecFromVec3s_0A4F0(Particle* arg0, Vec3s arg1);
void Particle_Field94_AddVec_0A52C(Particle* arg0, s16 arg1, s16 arg2, s16 arg3);
void Particle_Field94_AddX_0A578(Particle* arg0, s16 arg1);
void Particle_Field94_AddY_0A594(Particle* arg0, s16 arg1);
void Particle_Field94_AddZ_0A5B0(Particle* arg0, s16 arg1);
void Particle_AddRotationTargetXY(Particle* arg0, s16 arg1, s16 arg2);
void Particle_Field94_SubVecFromVec3s_0A600(Particle* arg0, Vec3s arg1);
void Particle_Field94_SubX_0A63C(Particle* arg0, s16 arg1);
void Particle_Field94_SubY_0A658(Particle* arg0, s16 arg1);
void Particle_Field94_SubZ_0A674(Particle* arg0, s16 arg1);
void Particle_ApproachRotationTargetX(Particle* arg0);
void Particle_ApproachRotationTargetY(Particle* arg0);
void Particle_ApproachRotationTargetZ(Particle* arg0);
void Particle_ApproachRotationTargetXY(Particle* arg0);
void Particle_ApproachRotationTargetXYZ(Particle* arg0);
void Particle_ApproachRotationXTo(Particle* arg0, s16 arg1, s16 arg2);
void Particle_ApproachRotationYTo(Particle* arg0, s16 arg1, s16 arg2);
s32 Particle_Field94_DecrementXTo_0A7DC(Particle* arg0, s32 arg1, s32 arg2);
s32 Particle_Field94_DecrementYTo_0A810(Particle* arg0, s32 arg1, s32 arg2);
s32 Particle_Field94_DecrementZTo_0A844(Particle* arg0, s32 arg1, s32 arg2);
void Particle_AddRotationRandomSignedXY(Particle* arg0, s32 arg1, s32 arg2);
void Particle_AddRotationRandomSignedXYWithXHalfTurn(Particle* arg0, s32 arg1, s32 arg2);
void Particle_AddRotationRandomSignedY(Particle* arg0, s32 arg1);
void Particle_AddRotationRandomSignedYWithHalfTurn(Particle* arg0, s32 arg1);
void Particle_AddRotationRandomSignedXWithFixedYQuarterTurn(Particle* arg0);
void Particle_ComputeVectorFromRotationY(Particle* arg0, f32 arg1, Vec3f* arg2);
void Particle_ComputeVectorFromRotationXY(Particle* arg0, f32 arg1, Vec3f* arg2);
void Particle_ComputeVectorFromRotationXZ(Particle* arg0, f32 arg1, Vec3f* arg2);
void Particle_ComputeVectorFromRotationXYZAlt(Particle* arg0, f32 arg1, Vec3f* arg2);
void Particle_ComputeVectorFromRotationYZVariant(Particle* arg0, f32 arg1, Vec3f* arg2);
void Particle_Field74_SetScaled_0AD8C(Particle* arg0, f32 arg1);
void Particle_Field78_SetScaled_0ADA4(Particle* arg0, f32 arg1);
s32 Particle_Field74_Approach_0ADBC(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field74_ApproachUsingField78_0AE00(Particle* arg0, f32 arg1);
s32 Particle_Field78_Approach_0AE40(Particle* arg0, f32 arg1, f32 arg2);
void Particle_Field7C_SetVecScaled_0AE84(Particle* arg0, Vec3f arg1);
void Particle_SetVelocityImpulse(Particle* arg0, f32 arg1, f32 arg2, f32 arg3);
void Particle_Field7C_SetXScaled_0AF0C(Particle* arg0, f32 arg1);
void Particle_Field7C_SetYScaled_0AF24(Particle* arg0, f32 arg1);
void Particle_Field7C_SetZScaled_0AF3C(Particle* arg0, f32 arg1);
s32 Particle_Field7C_IncrementXUntilAtLeast_0AF54(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field7C_IncrementYUntilAtLeast_0AFA8(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field7C_IncrementZUntilAtLeast_0AFFC(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field7C_DecrementXUntilAtMost_0B050(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field7C_DecrementYUntilAtMost_0B0A4(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field7C_DecrementZUntilAtMost_0B0F8(Particle* arg0, f32 arg1, f32 arg2);
void Particle_Field7C_ScaleVec_0B14C(Particle* arg0, f32 arg1);
s32 Particle_Field7C_ApproachY_0B180(Particle* arg0, f32 arg1, f32 arg2);
void Particle_Field7C_SetYFromField74AngleX_0B1C4(Particle* arg0);
void Particle_Field7C_SetXFromField74AngleY_0B1EC(Particle* arg0);
void Particle_Field7C_SetZFromField74AngleY_0B214(Particle* arg0);
void Particle_Field7C_SetXYFromField74AngleZ_0B23C(Particle* arg0);
void Particle_Field7C_SetXZFromField74AngleY_0B278(Particle* arg0);
void Particle_Field7C_SetVecFromField74AnglesXY_0B2B4(Particle* arg0);
void Particle_Field7C_SetVecFromField74AnglesXZ_0B330(Particle* arg0);
void Particle_Field7C_SetVecFromField74AnglesXYAlt_0B3AC(Particle* arg0);
void Particle_Field7C_SetVecFromField74AnglesYZ_0B42C(Particle* arg0);
void Particle_Field7C_SetVecFromField74AnglesXYZ_0B4A0(Particle* arg0);
void Particle_Field7C_SetVecFromField74AnglesXYZAlt_0B568(Particle* arg0);
void Particle_Field7C_SetVecFromField74AnglesYZAlt_0B638(Particle* arg0);
void Particle_Field7C_SetVecFromField74AnglesYZVariant_0B700(Particle* arg0);
void Particle_UpdateRotatingVelocityXZ(Particle* arg0, f32 arg1, s16 arg2);
s32 Particle_Field50_AdvanceField7CWithTimer_0B854(Particle* arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5);
void Particle_Field1C_SetScaled_0B938(Particle* arg0, f32 arg1);
void Particle_SetScale(Particle* arg0, f32 arg1);
void Particle_SetScaleSpeed(Particle* arg0, f32 arg1);
void Particle_SetScaleTarget(Particle* arg0, f32 arg1);
s32 Particle_Field1C_Approach_0B98C(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field1C_ApproachAndStepState_0B9D0(Particle* arg0, f32 arg1, f32 arg2);
s32 Particle_Field1C_ApproachField24ByField20_0BA1C(Particle* arg0);
s32 Particle_Field1C_ApproachField24AndStepState_0BA48(Particle* arg0);
s32 Particle_Field20_Approach_0BA84(Particle* arg0, f32 arg1, f32 arg2);
void Particle_SetPrimColor(Particle* arg0, u8 arg1, u8 arg2, u8 arg3);
s32 Particle_PrimR_Approach_0BAE4(Particle* arg0, u8 arg1, u8 arg2);
s32 Particle_PrimG_Approach_0BB14(Particle* arg0, u8 arg1, u8 arg2);
s32 Particle_PrimB_Approach_0BB44(Particle* arg0, u8 arg1, u8 arg2);
void Particle_SetEnvColor(Particle* arg0, u8 arg1, u8 arg2, u8 arg3);
s32 Particle_EnvR_Approach_0BB90(Particle* arg0, u8 arg1, u8 arg2);
s32 Particle_EnvB_Approach_0BBC0(Particle* arg0, u8 arg1, u8 arg2);
s32 Particle_EnvG_Approach_0BBF0(Particle* arg0, u8 arg1, u8 arg2);
void Particle_SetPrimAlpha(Particle* arg0, u8 arg1);
s32 Particle_PrimAlpha_Approach_0BC2C(Particle* arg0, u8 arg1, u8 arg2);
s32 Particle_PrimAlpha_ApproachAndStepState_0BC5C(Particle* arg0, u8 arg1, u8 arg2);
void Particle_FieldA6_SetS16_0BCA8(Particle* arg0, s16 arg1);
s16 Particle_FieldA6_GetS16_0BCBC(Particle* arg0);
s32 Particle_FieldA6_DecrementTo_0BCC4(Particle* arg0, s16 arg1, s16 arg2);
s32 Particle_FieldA6_DecrementToZero_0BD08(Particle* arg0, s16 arg1);
s32 Particle_FieldA6_DecrementToZeroAndStepState_0BD34(Particle* arg0, s16 arg1);
s32 Particle_FieldA6_DecrementToStep1_0BD80(Particle* arg0, s16 arg1);
s32 Particle_FieldA6_DecrementToZeroStep1_0BDAC(Particle* arg0);
s32 Particle_FieldA6_DecrementToZeroStep1AndStepState_0BDD0(Particle* arg0);
void Particle_FieldA8_SetS16_0BE14(Particle* arg0, s16 arg1);
s16 Particle_FieldA8_GetS16_0BE28(Particle* arg0);
s32 Particle_FieldA8_DecrementTo_0BE30(Particle* arg0, s16 arg1);
s32 Particle_FieldA8_DecrementToZeroStep1_0BE6C(Particle* arg0);
s32 Particle_FieldA8_DecrementToZeroStep1AndStepState_0BE8C(Particle* arg0);
void Particle_FieldCA_SetU8_0BECC(Particle* arg0, u8 arg1);
void Particle_FieldAC_SetS16_0BED8(Particle* arg0, s16 arg1);
void Particle_FieldCF_SetU8_0BEEC(Particle* arg0, u8 arg1);
void Particle_FieldCF_SetU8Alt_0BEF8(Particle* arg0, u8 arg1);
void Particle_FieldCC_SetU8_0BF04(Particle* arg0, u8 arg1);
void Particle_FieldAA_SetS16_0BF10(Particle* arg0, s16 arg1);
void Particle_FieldCE_SetS16_0BF24(Particle* arg0, s16 arg1);
void Particle_FieldCD_SetS16_0BF38(Particle* arg0, s16 arg1);
void Particle_FieldAE_SetS16_0BF4C(Particle* arg0, s16 arg1);
s32 Particle_FieldAE_Approach_0BF60(Particle* arg0, s16 arg1, s16 arg2);
s32 Particle_FieldAE_ApproachAndStepState_0BF98(Particle* arg0, s16 arg1, s16 arg2);
void Particle_FieldB0_SetS16_0BFEC(Particle* arg0, s16 arg1);
s32 Particle_FieldB0_Approach_0C000(Particle* arg0, s16 arg1, s16 arg2);
s16 Particle_FieldAC_GetS16_0C038(Particle* arg0);
s32 Particle_FieldCE_GetS32_0C040(Particle* arg0);
u8 Particle_FieldCD_GetU8_0C048(Particle* arg0);
s16 Particle_FieldAE_GetS16_0C050(Particle* arg0);
s16 Particle_FieldCF_GetS16_0C058(Particle* arg0);
s16 Particle_FieldAA_GetS16_0C068(Particle* arg0);
void Particle_SetFieldOffsetACIfNotSentinel(Particle* arg0, s16 arg1);
void Particle_SetFieldOffsetCFIfNotSentinel(Particle* arg0, u8 arg1);
void Particle_SetFieldOffsetA6IfNotSentinel(Particle* arg0, s16 arg1);
void Particle_SetFieldOffsetA8IfNotSentinel(Particle* arg0, s16 arg1);
void Particle_SetFieldOffsetCEIfNotSentinel(Particle* arg0, u8 arg1);
void Particle_SetFieldOffsetCDIfNotSentinel(Particle* arg0, u8 arg1);
void Particle_SetFieldOffsetAAIfNotSentinel(Particle* arg0, s16 arg1);
void Particle_SetPrimAlphaIfNotSentinel(Particle* arg0, u8 arg1);
void Particle_SetFieldOffsetAEIfNotSentinel(Particle* arg0, s16 arg1);
void Particle_SetFieldOffsetB0IfNotSentinel(Particle* arg0, s16 arg1);
void Particle_RenderWorldChains(unk_D_86002F34_00C* arg0);
void Particle_RenderOrthoParticles(unk_D_86002F34_00C* arg0);
void Particle_SetRenderMode(s16 arg0);
void Particle_InvokeRenderSetup(Particle* arg0, ParticleDescriptorChild* arg1);
void Particle_PrepareRender(Particle* arg0);
void Particle_DispatchDraw(Particle* arg0, unk_D_86002F34_00C* arg1);
void Particle_NoopDraw(UNUSED Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);


void Particle_UpdateFrameCounters(void);
void Particle_UpdateFrameCountersAlias(void);


void ParticleGfx_LoadTextureCallbackRgba16_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackIa8Frame_32x32(Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackIa8_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackIa8Frame_32x64(Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x32(Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameMod4_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod4_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameDiv4Mod4_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_32x32(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4TileFrameDiv2Mod8_24x24(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4TileParticleFrame_24x24(Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameMod10_32x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4ParticleFrame_32x64(Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameMod8_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4FrameDiv2Mod8_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4ParticleFrame_64x64(Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackI4WrapST_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_LoadTextureCallbackIa8WrapST_64x64(UNUSED Particle* arg0, u8* texture);
void ParticleGfx_DrawBillboardPrim(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardPrimEnv(Particle* arg0, unk_D_86002F34_00C* arg1);
s32 ParticleGfx_DrawBillboardDoubleSided(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardDefaultQuad(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardPrimEnvQuad(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardTextureAlphaRotatedQuad(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardOffsetQuad(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardPrimEnvNoiseQuad(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardPrimEnvRotatedQuad(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardPrimEnvRotatedTriangle(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardPrimEnvQuadVariantA(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardPrimEnvQuadVariantB(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardPrimEnvQuadVariantC(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardPrimEnvComposite(Particle* arg0, unk_D_86002F34_00C* arg1);
s32 ParticleGfx_DrawBillboardPrimEnvTriangleDoubleSided(Particle* arg0, UNUSED unk_D_86002F34_00C* arg1);
void ParticleGfx_DrawBillboardPrimEnvTransformedQuad(Particle* arg0, unk_D_86002F34_00C* arg1);
void ParticleGfx_CopyPaletteRgb(u8* arg0, u16 arg1);
void ParticleGfx_CopyPalettePairRgb(u8* arg0, u8* arg1, u16 arg2);
void ParticleGfx_RecolorPrim(Particle* arg0, u16 arg1);
void ParticleGfx_RecolorEnv(Particle* arg0, u16 arg1);
void ParticleGfx_RecolorPrimEnvFromPalettePair(Particle* arg0, u16 arg1);
void ParticleGfx_RecolorPrimFromPaletteSetA(Particle* arg0, s16 arg1);
void ParticleGfx_RecolorEnvFromPaletteSetA(Particle* arg0, s16 arg1);
void ParticleGfx_RecolorPrimFromPaletteSetB(Particle* arg0, s16 arg1);
void ParticleGfx_RecolorEnvFromPaletteSetB(Particle* arg0, s16 arg1);
void ParticleGfx_RecolorPrimEnvFromPaletteSetA(Particle* arg0, s16 arg1);
void ParticleGfx_RecolorPrimEnvFromPaletteSetB(Particle* arg0, s16 arg1);
void ParticleGfx_RecolorPrimRandomPalette(Particle* arg0);
void ParticleGfx_RecolorEnvRandomPalette(Particle* arg0);
s32 ParticleGfx_ApproachPrimPalette(Particle* arg0, u16 arg1, u8 arg2);
s32 ParticleGfx_ApproachEnvPalette(Particle* arg0, u16 arg1, u8 arg2);
s32 ParticleGfx_ApproachPrimEnvPalettePair(Particle* arg0, u16 arg1, u8 arg2);

#endif // _FRAGMENT34_H_
