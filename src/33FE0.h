#ifndef _33E30_H_
#define _33E30_H_

#include "global.h"

typedef struct PosBlend {
    /* 0x00 */ Vec3f base;
    /* 0x0C */ Vec3f offset;
} PosBlend; // size = 0x18

typedef struct Vec3sPad {
    /* 0x0 */ Vec3s vec;
    /* 0x6 */ char pad06[0x9];
} Vec3sPad; // size = 0x10

typedef struct Vec3fCounter {
    /* 0x00 */ Vec3f vec;
    /* 0x0C */ s16 count;
    /* 0x0E */ s16 pad;
} Vec3fCounter; // size = 0x10

typedef struct ModelTransformCmd {
    /* 0x00 */ s16 targetIndex;
    /* 0x02 */ s16 sourceIndex;
    /* 0x04 */ s16 enableFrom;
    /* 0x06 */ s16 enableTo;
    /* 0x08 */ f32 blendWeight;
} ModelTransformCmd; // size = 0x0C

typedef struct TransformWeights {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 owner;
    /* 0x04 */ f32 w0;
    /* 0x08 */ f32 w1;
    /* 0x0C */ f32 w2;
} TransformWeights;     // size = 0x10

typedef struct ModelVertex {
    /* 0x00 */ s16 jointIndex;      // bone / transform index
    /* 0x02 */ s16 parentIndex;     // parent bone index
    /* 0x04 */ s16 childIndex;      // child / next transform
    /* 0x06 */ u16  pad06;
    /* 0x08 */ ModelTransformCmd cmd;
    /* 0x14 */ u8   pad14[0xC];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ u8  pad24[0x40];
    /* 0x64 */ PosBlend position;   // base + animated offset
    /* 0x7C */ f32 colorR;          // vertex color (float)
    /* 0x80 */ f32 colorG;
    /* 0x84 */ f32 colorB;
    /* 0x88 */ s16 texS;            // texture coordinate S
    /* 0x8A */ s16 texT;            // texture coordinate T
    /* 0x8C */ u8  alpha;           // vertex alpha
    /* 0x8D */ u8  pad8D;
    /* 0x8E */ u16 disabled;      // enable / visibility / animation flags
    /* 0x90 */ s16 drawGroup;       // render group / material group
    /* 0x92 */ s16 nextIndex;       // linked-list / chain index
} ModelVertex;                      // size = 0x94

typedef struct StadiumTransform {
    /* 0x00 */ s32  unk_00;
    /* 0x04 */ f32  maxDist;
    /* 0x08 */ f32  x0;
    /* 0x0C */ f32  y0;
    /* 0x10 */ f32  z0;

    /* 0x14 */ f32  x1;
    /* 0x18 */ f32  y1;
    /* 0x1C */ f32  z1;

    /* 0x20 */ f32  x2;
    /* 0x24 */ f32  y2;
    /* 0x28 */ f32  z2;

    /* 0x2C */ f32  x3;
    /* 0x30 */ f32  y3;
    /* 0x34 */ f32  z3;

    /* 0x38 */ MtxF* mtx;
} StadiumTransform; // size = 0x3C

typedef struct ModelSegment {
    /* 0x00 */ u16 type;
    /* 0x02 */ u16 nodeCount;
    /* 0x04 */ u16 vertexCount;
    /* 0x06 */ u16 triangleCount;
    /* 0x08 */ u32 indexSegment;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u32 tableSegment;
    /* 0x14 */ u32 remapSegment;
    /* 0x18 */ u32 vertexSegment;
    /* 0x1C */ Gfx* displayList;
} ModelSegment; // size = 20

typedef struct StadiumModel {
    /* 0x00 */  s16 unk_00;
    /* 0x02 */  s16 unk_02;
    /* 0x04 */  StadiumTransform transforms[5];
    /* 0x130 */ u32 modelSegment;
    /* 0x134 */ s8 pad134[0x24];
    /* 0x158 */ Vec3f position;
    /* 0x164 */ s8 pad164[0xC];
    /* 0x170 */ ModelVertex mvtx;
} StadiumModel; // size = 0x204

void func_800350E4(ModelSegment*, MtxF*, ModelVertex*);
void func_800359FC(ModelSegment*, ModelVertex*, StadiumModel*, f32);
void func_80035FA8(ModelSegment*, ModelVertex*);

#endif // _33E30_H_
