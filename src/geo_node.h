#ifndef _11BA0_H_
#define _11BA0_H_

#include "global.h"
#include "src/memory.h"

typedef struct unk_func_80011B94 {
    /* 0x00 */ DisplayNodeHeader display_node_header;
    /* 0x18 */ Gfx* gfx;
} unk_func_80011B94; // size = 0x1C

typedef struct unk_D_8690A610_018 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ Color_RGBA8_u32 unk_04;
} unk_D_8690A610_018; // size = 0x8

typedef struct unk_D_8690A610 {
    /* 0x00 */ DisplayNodeHeader node;
    /* 0x18 */ unk_D_8690A610_018 unk_18;
} unk_D_8690A610; // size = 0x20

void GeoNode_Init(GraphNode* arg0, u8 arg1);
void GeoNode_SetCallback(GraphNode* arg0, GraphNodeCallback arg1, void* arg2);
GraphNode* GeoNode_CreateContainer(MainPoolState* arg0, GraphNode* arg1);
unk_D_86002F34_alt2* GeoNode_CreateWithReference(MainPoolState* arg0, unk_D_86002F34_alt2* arg1, GraphNode* arg2);
unk_D_86002F34_00C* GeoNode_CreateCamera(MemoryBlock* arg0, unk_D_86002F34_00C* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
unk_D_86002F34_alt13* GeoNode_CreateType3(MemoryBlock* arg0, unk_D_86002F34_alt13* arg1, s16 arg2);
unk_D_86002F34_alt1* GeoNode_CreateType4(MemoryBlock* arg0, unk_D_86002F34_alt1* arg1, s16 arg2);
unk_D_86002F34_alt14* GeoNode_CreateOrtho(MainPoolState* arg0, unk_D_86002F34_alt14* arg1, s16 arg2);
unk_D_86002F34_alt15* GeoNode_CreatePerspective(MainPoolState* arg0, unk_D_86002F34_alt15* arg1, s16 arg2);
unk_D_86002F34_alt16* GeoNode_CreateBackground(MainPoolState* arg0, unk_D_86002F34_alt16* arg1, u8 arg2, u8 arg3, u8 arg4);
unk_D_86002F34_alt17* GeoNode_CreateClearDepth(MainPoolState* arg0, unk_D_86002F34_alt17* arg1);
unk_D_8690A610* GeoNode_CreateFog(s32 arg0, unk_D_8690A610* arg1, s16 arg2, s16 arg3, u8 r, u8 g, u8 b, u8 a);
unk_D_86002F34_alt18* GeoNode_CreateLight(MainPoolState* arg0, unk_D_86002F34_alt18* arg1, s16 arg2, s16 arg3, u8 r, u8 g, u8 b, u8 a);
unk_D_86002F34_alt19* GeoNode_CreateAmbientLight(MainPoolState* arg0, unk_D_86002F34_alt19* arg1, u8 r, u8 g, u8 b);
unk_D_86002F34* GeoNode_CreateShadowContext(MainPoolState* arg0, unk_D_86002F34* arg1, s32 arg2,
                              unk_D_86002F34_018* arg3, s32 arg4, unk_D_86002F34_01C* arg5,
                              s32 arg6, Vtx* arg7);
unk_D_86002F34_alt12* GeoNode_CreateShadow(MainPoolState* arg0, unk_D_86002F34_alt12* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
unk_D_86002F34_alt20* GeoNode_CreateCullDistance(MainPoolState* arg0, unk_D_86002F34_alt20* arg1, s16 arg2, s16 arg3);
unk_D_86002F34_alt21* GeoNode_CreateSwitchCase(MainPoolState* arg0, unk_D_86002F34_alt21* arg1, s16 arg2, s16 arg3);
unk_D_86002F34_alt5* GeoNode_CreateTranslateRotate(MainPoolState* arg0, unk_D_86002F34_alt5* arg1, Vec3f* arg2, Vec3s* arg3);
unk_D_86002F34_alt22* GeoNode_CreateTranslate(MainPoolState* arg0, unk_D_86002F34_alt22* arg1, Vec3f* arg2);
unk_D_86002F34_alt6* GeoNode_CreateAnimatedPart(MainPoolState* arg0, unk_D_86002F34_alt6* arg1, s16 arg2, s16 arg3, s16 arg4, Vec3s* arg5, Vec3s* arg6, Vec3f* arg7);
unk_D_86002F34_alt7* GeoNode_CreateDisplayListPart(MainPoolState* arg0, unk_D_86002F34_alt7* arg1, s32 arg2, Gfx* arg3, s16 arg4);
DisplayObject* GeoNode_CreateModelPart(MainPoolState* arg0, DisplayObject* arg1, s16 arg2, Vec3f* arg3,
                                      Vec3s* arg4, Vec3f* arg5);
unk_D_86002F34_alt8* GeoNode_CreateDisplayListMatrix(MainPoolState* arg0, unk_D_86002F34_alt8* arg1, s32 arg2, Gfx* arg3, MtxF* arg4);
unk_D_86002F34_alt8* GeoNode_CreateDisplayListMatrixFromTransform(MainPoolState* arg0, unk_D_86002F34_alt8* arg1, s32 arg2, Gfx* arg3, Vec3f* arg4, Vec3s* arg5);
unk_D_86002F34_alt9* GeoNode_CreateScale(MainPoolState* arg0, unk_D_86002F34_alt9* arg1, s32 arg2, Gfx* arg3, Vec3f* arg4, f32 arg5);
unk_func_80011B94* GeoNode_CreateDisplayList(MainPoolState* arg0, unk_func_80011B94* arg1, s32 arg2, Gfx* arg3);
unk_D_86002F34_alt10* GeoNode_CreateShadowTexture(MainPoolState* arg0, unk_D_86002F34_alt10* arg1, s16 arg2, s16 arg3, Gfx* arg4, s16 arg5, s16 arg6, u8 r, u8 g, u8 b, u8 a);
unk_D_86002F34_alt23* GeoNode_CreateAnchor(MainPoolState* arg0, unk_D_86002F34_alt23* arg1, s16 arg2);
unk_D_86002F34_alt24* GeoNode_CreateGroup(MainPoolState* arg0, unk_D_86002F34_alt24* arg1, s32 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s32 arg9,
                                    u8 r, u8 g, u8 b, u8 a);
void GeoCamera_SetViewport(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void GeoCamera_SetPerspective(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3);
void GeoCamera_SetEyeAtUp(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7);
void GeoCamera_SetBackground(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5);
void GeoCamera_SetBackgroundTexture(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, s32 arg3, u32 arg4);
void GraphNode_AppendChild(GraphNode* parent, GraphNode* child);
void GraphNode_RemoveChild(GraphNode* arg0, GraphNode* arg1);
GraphNode* GraphNode_GetChildAtIndex(GraphNode* arg0, s32 arg1);


#endif // _11BA0_H_
