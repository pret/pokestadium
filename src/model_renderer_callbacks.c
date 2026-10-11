#include "model_renderer_callbacks.h"
#include "src/geo_render.h"
#include "src/gallery.h"
#include "src/battle_hud.h"
#include "src/33FE0.h"
#include "src/gfx_buffer.h"
#include "src/matrix.h"

typedef struct StadiumModelSlot {
    /* 0x000 */ StadiumModel model;
    /* 0x204 */ char pad204[0x5CC];
} StadiumModelSlot; // size = 0x7D0

typedef struct unk_func_80032F94_a0 {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
} unk_func_80032F94_a0;  // size = 0x20

typedef struct unk_D_800B2EA8 {
    u8 unk_00[0xA8];
} unk_D_800B2EA8; // size = 0xA8

typedef struct {
    MtxF mtx[16];   // 16 (0x10) × 0x40 = 0x400
} MtxBuffer; // size = 0x400

s32 D_80076270[16] = { // identity Mtx
    0x00010000, 0x00000000, 0x00000001, 0x00000000,
    0x00000000, 0x00010000, 0x00000000, 0x00000001,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
Gfx D_800762B0[3] = {
    {{ 0xE3000A01, 0x00100000 }},
    {{ 0xE7000000, 0x00000000 }},
    {{ 0xDF000000, 0x00000000 }},
};
Gfx D_800762C8[5] = {
    {{ 0xD9FDFFFF, 0x00000000 }},
    {{ 0xE7000000, 0x00000000 }},
    {{ 0xFC309680, 0x5F1AFFFF }},
    {{ 0xE3001001, 0x00000000 }},
    {{ 0xDF000000, 0x00000000 }},
};

// extern Gfx D_800762C8[] = {
//     gsSPSetGeometryMode(0x00FDFFFF),
//     gsDPPipeSync(),
//     gsDPSetCombineLERP(
//         TEXEL0, 0, SHADE, 0,      // Color cycle 1
//         TEXEL0, 0, SHADE, 0,      // Color cycle 2
//         0, 0, 0, SHADE,           // Alpha cycle 1
//         0, 0, 0, SHADE            // Alpha cycle 2
//     ),
//     gsDPSetAlphaCompare(G_AC_NONE),
//     gsSPEndDisplayList(),
// };

s16 D_800AF7C0[4];
static MtxBuffer D_800AF7C8[2];
static StadiumModelSlot D_800AFFC8[2][3];
static unk_D_800B2EA8 D_800B2EA8[1];

void ModelRenderer_OnSlotReady(s32 arg0) {

}

s32 ModelRenderer_IsReady(UNUSED s32 arg0) {
    return 1;
}

void ModelRenderer_CacheSlotMatrices(u8 arg0) {
    MtxF_Copy(D_800AF7C8[arg0].mtx, GeoRender_GetRelativeMatrix(0));
    MtxF_Copy(D_800AF7C8[arg0].mtx[1].mf, GeoRender_GetRelativeMatrix(-1));
}

void ModelRenderer_ApplySlotScale(u8 index) {
    MtxF* temp_a1;
    MtxF sp1C;

    temp_a1 = &D_800AF7C8[index];
    MtxF_ExtractScale(&sp1C, &D_8006F088->unk_60.mtxf);
    guMtxCatF(sp1C.mf, temp_a1->mf, temp_a1->mf);
}

void ModelRenderer_RebuildSlotMatrix(u8 index) {
    MtxF* temp_a0;
    
    s32 pad[2];
    f32 spC0;
    f32 spBC;
    f32 spB8;
    
    MtxF sp78;
    MtxF sp38;
    Vec3f sp2C;
    
    temp_a0 = &D_800AF7C8[index].mtx;
    
    MtxF_GetScaleVector(temp_a0, &sp2C);
    guScaleF(sp38.mf, sp2C.x, sp2C.y, sp2C.z);
    guMtxXFMF(temp_a0->mf, 0.0f, 0.0f, 0.0f, &spC0, &spBC, &spB8);
    guTranslateF(sp78.mf, spC0, spBC, spB8);
    guMtxCatF(sp38.mf, sp78.mf, temp_a0->mf);
}

void ModelRenderer_ClearSlotModels(s32 arg0) {
    s32 i;
    StadiumModelSlot* slot = &D_800AFFC8[arg0];

    for (i = 0; i < 3; i++) {
        slot[i].model.unk_00 = 0;
    }
}

Gfx* ModelRenderer_SetupSlotColors(Gfx* gfx) {
    u8 temp_v0 = D_8006F09C->lodFraction;

    switch (D_8006F09C->objectType) {
        case 0x92:
            gSPDisplayList(gfx++, D_800762C8);
            gDPSetPrimColor(gfx++, 0, temp_v0, 255, 255, 255, 200);
            gDPSetEnvColor(gfx++, 255, 32, 0, 0);
            break;
        case 0x7E:
            gSPDisplayList(gfx++, D_800762C8);
            gDPSetPrimColor(gfx++, 0, temp_v0, 255, 255, 5, 255);
            gDPSetEnvColor(gfx++, 255, 32, 0, 0);
            break;
        default:
            gSPDisplayList(gfx++, D_800762C8);
            gDPSetPrimColor(gfx++, 0, temp_v0, 255, 255, 255, 255);
            gDPSetEnvColor(gfx++, 180 - (D_8006F084 % 8) * 10, 32, 0, 0);
            break;
    }

    return gfx;
}

void ModelRenderer_UpdateSlotModel(void) {
    u8 index;
    s32 mode;

    mode = ModelRenderer_GetActiveMode();
    index = (u8)mode;
    if (mode < 2) {
        ModelRenderer_CacheSlotMatrices(index);
        ModelRenderer_RebuildSlotMatrix(index);
        ModelRenderer_ApplySlotScale(index);

        if (D_8006F09C->objectType == 0x92) {
            func_80033B2C(&D_800AFFC8[index][D_800AF7B0[index & 1]].model, D_800B2EA8, D_800AF7C8[index].mtx, &D_80077950);
            return;
        }
        func_80033B2C(&D_800AFFC8[index][D_800AF7B0[index & 1]].model, D_800B2EA8, D_800AF7C8[index].mtx, &D_800777A8);
    }
}

void ModelRenderer_UpdateSlotVertices(void) {
    u8 index;
    s32 mode;

    mode = ModelRenderer_GetActiveMode();
    index = (u8)mode;
    if ((mode < 2) && (func_800325AC() == 0) && (D_800AF7C0[index] >= 2)) {
        ModelRenderer_CacheSlotMatrices(index);
        ModelRenderer_RebuildSlotMatrix(index);
        ModelRenderer_ApplySlotScale(index);
        func_800361C4(&D_800AFFC8[index][D_800AF7B0[index & 1]].model, &D_800AF7C8[index].mtx);
    }
}

Gfx* ModelRenderer_DrawStaticSegment(Gfx* gfx) {
    ModelSegment* segment;
    s32 pad[1];
    MtxF modelMtx;     // sp1E8
    MtxF tempCatMtx;   // sp1A8
    MtxF sp168;
    MtxF scaleMtx;     // sp128
    MtxF translateMtx; // spE8
    Mtx tempMtx;       // spA8
    Mtx* mtxL;
    u32 pad2[16];
    Vec3f scale;
    Vec3f translate;

    if (D_8006F09C->objectType == 0x92) {
        segment = (ModelSegment *)&D_80077950;
    } else {
        segment = (ModelSegment *)&D_800777A8;
    }
    MtxF_ExtractScale(&modelMtx, &D_8006F088->unk_60.mtxf);
    guMtxF2L(&modelMtx.mf[0], &tempMtx);
    MtxF_Copy(&tempCatMtx, GeoRender_GetRelativeMatrix(0));
    MtxF_GetScaleVector(&tempCatMtx, &scale);
    guScaleF(&scaleMtx.mf[0], scale.x, scale.y, scale.z);
    guMtxXFMF(&tempCatMtx.mf[0], 0.0f, 0.0f, 0.0f, &translate.z, &translate.y, &translate.x);
    guTranslateF(&translateMtx.mf[0], translate.z, translate.y, translate.x);
    mtxL = Gfx_AllocDisplayList(0x40);
    guMtxCatF(&scaleMtx.mf[0], &translateMtx.mf[0], &tempCatMtx.mf[0]);
    guMtxF2L(&tempCatMtx.mf[0], mtxL);
    guMtxCatL(&tempMtx, mtxL, mtxL);
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xDA380002;    _gfx->words.w1 = mtxL;    }
    gfx = ModelRenderer_SetupSlotColors(gfx);
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xDB060038;    _gfx->words.w1 = (s32) segment->vertexSegment;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xDE000000;    _gfx->words.w1 = (s32) segment->displayList;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xD8380002;    _gfx->words.w1 = 0x40;    }
    {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xDE000000;    _gfx->words.w1 = &D_800762B0;    }
    return gfx;
}

Gfx* ModelRenderer_RenderActiveSlot(Gfx* gfx) {
    u8 mode;
    Vtx* vtx;
    s16* var_v1;

    mode = ModelRenderer_GetActiveMode();
    if ((mode == 0xFF) || (mode == 0xFE)) {
        return ModelRenderer_DrawStaticSegment(gfx);
    }
    if (mode >= 4) {
        return gfx;
    }
    if (mode >= 2) {
        mode &= 1;
        if (D_800AF7C0[mode] >= 2) {
            Gfx_AllocDisplayList(0xA0);
            gfx = ModelRenderer_SetupSlotColors(gfx);
            var_v1 = &D_800AF7B0[mode & 1];
            {
                ModelSegment* segment = (ModelSegment*)(&D_800AFFC8[mode][*var_v1].model.unkSegment);
                {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xDB060038;    _gfx->words.w1 = (s32) segment->vertexSegment;    }
                {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xDE000000;    _gfx->words.w1 = (s32) segment->displayList;    }
                {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xDE000000;    _gfx->words.w1 = &D_800762B0;    }
            }
            *var_v1 += 1;
        }
        return gfx;
    }
    switch (D_800AF7C0[mode]) {
        default:
            var_v1 = &D_800AF7B0[mode & 1];
            break;
        case 1:
            ModelRenderer_UpdateSlotModel();
            var_v1 = &D_800AF7B0[mode & 1];
            break;
        case 2:
        case 3:
            vtx = Gfx_AllocDisplayList(0xA0);
            {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xDA380002;    _gfx->words.w1 = &D_80076270;    }
            gfx = ModelRenderer_SetupSlotColors(gfx);
            var_v1 = &D_800AF7B0[mode & 1];
            gfx = Model_Draw(gfx, &D_800AFFC8[mode][*var_v1].model, vtx);
            {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xD8380002;    _gfx->words.w1 = 0x40;    }
            {    Gfx *_gfx = (Gfx *)(gfx++);    _gfx->words.w0 = 0xDE000000;    _gfx->words.w1 = &D_800762B0;    }
            break;
    }
    *var_v1 += 1;
    return gfx;
}
