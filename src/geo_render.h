#ifndef _12D80_H_
#define _12D80_H_

#include "global.h"

typedef struct unk_D_800AB970 {
    /* 0x000 */ Vec3f unk_000[1];
    /* 0x00C */ char unk00C[0x174];
    /* 0x180 */ s32 unk_180;
    /* 0x184 */ char unk184[0xC];
} unk_D_800AB970; // size = 0x190?

typedef struct unk_D_800ABB00 {
    /* 0x00 */ void* unk_00;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ char unk08[0x8];
} unk_D_800ABB00; // size >= 0x10?

typedef struct unk_D_800ABB28 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Gfx* unk_04;
    /* 0x08 */ Gfx* unk_08;
    /* 0x0C */ MtxF* unk_0C;
    /* 0x10 */ Color_RGBA8_u32 unk_10;
    /* 0x14 */ Color_RGBA8_u32 unk_14;
    /* 0x18 */ unk_D_86002F34_alt11_018* unk_18;
    /* 0x1C */ struct unk_D_800ABB28* unk_1C;
    /* 0x20 */ Gfx* unk_20;
    /* 0x24 */ u8 unk_24;
    /* 0x24 */ u8 unk_25;
    /* 0x24 */ u8 unk_26;
    /* 0x24 */ u8 unk_27;
} unk_D_800ABB28; // size = 0x28

typedef struct unk_D_800ABB10 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ Color_RGBA8_u32 unk_04;
    /* 0x08 */ Color_RGBA8_u32 unk_08;
    /* 0x0C */ unk_D_86002F34_alt11_018* unk_0C;
    /* 0x10 */ unk_D_800ABB28* unk_10;
    /* 0x14 */ Gfx* unk_14;
} unk_D_800ABB10; // size = 0x18?

extern s32 D_8006F080;
extern u16 D_8006F084;
extern unk_D_86002F34_00C* D_8006F088;
extern unk_D_86002F34_alt1* D_8006F08C;
extern unk_D_86002F34_alt1* D_8006F090;
extern unk_D_86002F34_00C* D_8006F094;
extern unk_D_86002F34_alt1* D_8006F098;
extern DisplayObject* D_8006F09C;
extern unk_D_86002F34_alt11* D_8006F0A0;

void GeoRender_InitMatrixStack(void);
void GeoRender_CommitMatrix(void);
void GeoRender_SetMatrix(MtxF* arg0);
void GeoRender_PushMultipliedMatrix(MtxF* arg0);
void GeoRender_PushScaledMatrix(Vec3f* arg0);
MtxF* GeoRender_GetRelativeMatrix(s32 arg0);
MtxF* GeoRender_GetMatrix(s32 arg0);
void GeoRender_ResetTransformStack(void);
void GeoRender_PushScale(Vec3f* arg0);
Vtx* GeoOverlay_BuildFadeQuad(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1);
void GeoOverlay_DrawFadeQuad(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1);
void func_80012870(Vtx* arg0, unk_D_86002F34_00C_0CC* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);
Vtx* GeoOverlay_BuildRotatingQuad(unk_D_86002F34_00C_0CC* arg0);
void GeoOverlay_DrawRotatingQuad(unk_D_86002F34_00C_0CC* arg0, UNUSED unk_D_86002F34_00C_040* arg1);
void GeoOverlay_Draw(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1);
void Geo_ProcessNodeChildren(GraphNode* arg0);
void Geo_NodeReference(GraphNode* arg0);
void Geo_NodeCamera(GraphNode* arg0);
void Geo_NodeType3Pass(GraphNode* arg0);
void Geo_NodeModelRoot(GraphNode* arg0);
void Geo_NodeModelPartRoot(GraphNode* arg0);
void Geo_NodeOrtho(GraphNode* arg0);
void Geo_NodePerspective(GraphNode* arg0);
void Geo_NodeBackground(GraphNode* arg0);
void Geo_NodeClearDepth(UNUSED GraphNode* arg0);
void Geo_NodeType9Empty(UNUSED GraphNode* arg0);
void Geo_NodeFog(GraphNode* arg0);
void func_80013D34(GraphNode* arg0);
void Geo_NodeType12Empty(UNUSED GraphNode* arg0);
void Geo_NodeAmbientLight(GraphNode* arg0);
void Geo_NodeShadowContext(GraphNode* arg0);
void Geo_NodeCullDistance(GraphNode* arg0);
void Geo_NodeSwitchCase(GraphNode* arg0);
void Geo_NodeTranslateRotate(GraphNode* arg0);
void Geo_NodeTranslate(GraphNode* arg0);
void Geo_NodeAnimatedPart(GraphNode* arg0);
void Geo_NodeDisplayListPart(GraphNode* arg0);
void Geo_NodeModelPart(GraphNode* arg0);
void Geo_NodeDisplayListMatrix(GraphNode* arg0);
void Geo_NodeScale(GraphNode* arg0);
void Geo_NodeDisplayList(GraphNode* arg0);
void Geo_NodeShadowTexture(GraphNode* arg0);
void GeoRender_RecordAnchorPosition(s32 arg0);
void Geo_NodeAnchor(GraphNode* arg0);
void Geo_NodeGroup(GraphNode* arg0);
void Geo_NodeShadow(GraphNode* arg0);
void Geo_RenderRootNode(GraphNode* node);
void Geo_ProcessCallbacks(GraphNode* arg0, s32 arg1);
void GeoRender_SetMode(s32 arg0);
void GeoRender_AdvanceFrameCounter(void);
s32 GeoRender_IsModelFrameCurrent(void);
Vec3f* GeoRender_FindAnchorPosition(DisplayObject* arg0, s16 arg1, Vec3f* arg2);
void GeoRender_SetCombineMode(Gfx* arg0, arg1_func_81407874_014_000_010* arg1);
void GeoRender_SyncMaterialState(void);
void GeoRender_SetRenderMode(void);
void GeoRender_ApplyMaterialState(void);
void GeoRender_SetFogColor(unk_D_800ABB10* arg0);
void GeoRender_RestoreRenderMode(UNUSED unk_D_800ABB10* arg0);
void GeoRender_SetPrimitiveColor(unk_D_800ABB10* arg0);
void GeoRender_SetCombineTableEntry(unk_D_800ABB10* arg0);
void GeoRender_DisableTexture(UNUSED unk_D_800ABB10* arg0);
void GeoRender_BindTexture(unk_D_800ABB10* arg0);
void GeoRender_EnableTextureGeneration(UNUSED unk_D_800ABB10* arg0);
void GeoRender_SelectMaterialSlot(s16 arg0);
void GeoRender_SetTextureMode(s16 arg0);
s16 GeoRender_NormalizeTextureFormat(s16 arg0);
void GeoRender_SubmitMaterial(s16 arg0, MtxF* arg1);
void GeoRender_SubmitDisplayList(Gfx* arg0, s32 arg1);
void GeoRender_SetMaterialParams(Color_RGBA8_u32 arg0, u8 arg1, u32 arg2);
void GeoRender_SetMaterialTexture(s32 arg0, Color_RGBA8_u32 arg1, unk_D_86002F34_alt11_018* arg2, unk_D_86002F34_alt11_018* arg3, s32 arg4);
void GeoRender_InitMaterialState(s32 arg0, s32 arg1);
void GeoRender_FlushMaterialSlots(void);

#endif // _12D80_H_
