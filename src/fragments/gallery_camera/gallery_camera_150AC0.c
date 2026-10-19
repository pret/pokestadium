#include "gallery_camera.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/text_system.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"

const char D_8690A520[] = "FREE BATTLE";
const char D_8690A52C[] = "POK\xE9 CUP";
const char D_8690A538[] = "POK\xE9 CUP2";
const char D_8690A544[] = "PETIT CUP";
const char D_8690A550[] = "PIKA CUP";
const char D_8690A55C[] = "PRIME CUP";
const char D_8690A568[] = "PEWTER GYM";
const char D_8690A574[] = "CERULEAN GYM";
const char D_8690A584[] = "VERMILION GYM";
const char D_8690A594[] = "CELADON GYM";
const char D_8690A5A0[] = "FUCHSIA GYM";
const char D_8690A5AC[] = "SAFFRON GYM";
const char D_8690A5B8[] = "CINNABAR GYM";
const char D_8690A5C8[] = "VIRIDIAN GYM";
const char D_8690A5D8[] = "VS ELITE FOUR";
const char D_8690A5E8[] = "VS MEWTWO";

extern u8 D_50002A0[];
extern u8 D_50003F0[];
extern u8 D_5000BA0[];
extern u8 D_5000C90[];
extern u8 D_50011D0[];
extern u8 D_5001680[];
extern u8 D_50017E8[];

void GalleryUI_DrawGradientQuad(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    DepthBuffer* temp_s1 = GfxImage_GetCurrent();
    Vtx* temp_s2 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    Mtx* sp84 = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    Vp* sp80 = Gfx_AllocDisplayList(sizeof(Vp) * 1);

    Gfx_SetViewportDimensions(sp80, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp80 & 0x1FFFFFFF);

    guOrtho(sp84, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    Gfx_SetVertexAttributes(&temp_s2[0], arg0, arg1, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_FOG | G_LIGHTING);
    gSPSetGeometryMode(gDisplayListHead++, G_SHADE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)sp84 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}

void func_869043F4(void) {
}

void Gallery_DrawHelpBalloonFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 var_s2;
    s16 var_s3;
    s16 sp4C;
    s16 sp48;

    if (arg2 >= 0x10) {
        var_s3 = 8;
    } else {
        var_s3 = arg2 / 2;
    }

    if (arg3 >= 0x10) {
        var_s2 = 8;
    } else {
        var_s2 = arg3 / 2;
    }

    sp4C = arg2 - (var_s3 * 2);
    sp48 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, gUiPanelTopLeftTexture, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, gUiPanelTopRightTexture, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, gUiPanelBottomLeftTexture, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, gUiPanelBottomRightTexture, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3,
                  0x2000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, gUiTranslucentFillDL);

    if ((sp4C > 0) && (sp48 > 0)) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp4C, var_s2, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0, (arg1 + var_s3), arg2, sp48, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0 + var_s3, (arg1 + var_s3) + sp48, sp4C, var_s2, arg4, arg5, arg6, arg7);
    } else if (sp4C > 0) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp4C, arg3, arg4, arg5, arg6, arg7);
    } else if (sp48 > 0) {
        Gfx_FillRectRgba(arg0, arg1 + var_s2, arg2, sp48, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void func_86904BFC(void) {
}

void GalleryUI_DrawScrollingTextureRect(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    unk_D_800A7440 sp30;

    GfxRect_SetBounds(&sp30, arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);

    if (GfxRect_ClipToScissor(&sp30) != 0) {
        if (arg6 != 0) {
            arg4 += ((sp30.x1 - arg0) * arg6) >> 5;
        }

        if (arg7 != 0) {
            arg5 += ((sp30.y2 - arg1) * arg7) >> 5;
        }

        sp30.y1 += 1;
        sp30.x2 += 1;

        gSPTextureRectangle(gDisplayListHead++, sp30.x1 << 2, sp30.y2 << 2, sp30.y1 << 2, sp30.x2 << 2, G_TX_RENDERTILE,
                            arg4, arg5, arg6, arg7);
    }
}

void Gallery_DrawHelpBalloonScrollTexture(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, s16 arg5) {
    gDPLoadTextureTile(gDisplayListHead++, arg4, G_IM_FMT_IA, G_IM_SIZ_8b, arg2, 0, 0, 0, arg2 - 1, arg3 - 1, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 3, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    GalleryUI_DrawScrollingTextureRect(arg0, arg1, arg2, arg3, D_8690B360.unk_02 << 5, 0, 0x400, 0x400);
}

void Gallery_DrawHelpBalloonBubble(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_FOG | G_LIGHTING);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0,
                      COMBINED, 0, 0, 0, COMBINED);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 95, 55, 0, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);

    Gallery_DrawHelpBalloonScrollTexture(arg1, arg2, arg3, arg4, arg0, arg3);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void GalleryUI_DrawRotatedSprite(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    Vec3s spD8;
    Vec3f spCC;
    Vec3f spC0;
    UNUSED s32 pad;
    DepthBuffer* spB8;
    Vtx* spB4;
    MtxF* spB0;
    Mtx* spAC;
    MtxF* spA8;
    Vp* spA4;

    spB8 = GfxImage_GetCurrent();
    spB4 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    spB0 = Gfx_AllocDisplayList(sizeof(MtxF) * 1);
    spAC = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    spA8 = Gfx_AllocDisplayList(sizeof(MtxF) * 1);
    spA4 = Gfx_AllocDisplayList(sizeof(Vp) * 1);

    Vec3s_SetComponents(&spD8, 0, 0, D_8690B360.unk_06);

    Vec3f_SetComponentsDuplicate(&spCC, (f32)arg1 + (arg3 / 2), (f32)arg2 + arg4, 0.0f);
    Vec3f_SetComponentsDuplicate(&spC0, 1.0f, 1.0f, 1.0f);
    MtxF_SetRotationTranslationF(spA8, &spCC, &spD8);
    MtxF_ScaleRows(spA8, spA8, &spC0);
    MtxF_ToFixed(spB0, spA8);
    Gfx_SetViewportDimensions(spA4, spB8->width, spB8->height);

    gSPViewport(gDisplayListHead++, (u32)spA4 & 0x1FFFFFFF);

    guOrtho(spAC, 0.5f, spB8->width - 0.5f, spB8->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    Gfx_SetVertexAttributes(&spB4[0], -(arg3 / 2), -arg4, -1, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spB4[1], (arg3 / 2), -arg4, -1, arg3 << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spB4[2], -(arg3 / 2), 0, -1, 0, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spB4[3], (arg3 / 2), 0, -1, arg3 << 5, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    if (D_8690B360.unk_06 == 0) {
        gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
        gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    } else {
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    }

    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureTile(gDisplayListHead++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg3, 0, 0, 0, arg3 - 1, arg4 - 1, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)spAC & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)spB0 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)spB4 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void func_86905734(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u8 arg6) {
    s32 a1;
    s32 a2;
    s16 spF8[4];
    s16 spF0[4];
    DepthBuffer* spEC;
    Vtx* spE8;
    Mtx* spE4;
    Vp* spE0;

    spEC = GfxImage_GetCurrent();
    spE8 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    spE4 = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    spE0 = Gfx_AllocDisplayList(sizeof(Vp) * 1);

    a1 = arg1;
    a2 = arg2;

    spF8[0] = ((-(arg3 / 2) * COSS(arg5)) - (SINS(arg5) * -arg4)) + a1;
    spF0[0] = ((-(arg3 / 2) * SINS(arg5)) + (COSS(arg5) * -arg4)) + a2;

    spF8[1] = (((arg3 / 2) * COSS(arg5)) - (SINS(arg5) * -arg4)) + a1;
    spF0[1] = (((arg3 / 2) * SINS(arg5)) + (COSS(arg5) * -arg4)) + a2;

    spF8[2] = (-(arg3 / 2) * COSS(arg5)) + a1;
    spF0[2] = (-(arg3 / 2) * SINS(arg5)) + a2;

    spF8[3] = ((arg3 / 2) * COSS(arg5)) + a1;
    spF0[3] = ((arg3 / 2) * SINS(arg5)) + a2;

    Gfx_SetViewportDimensions(spE0, spEC->width, spEC->height);

    gSPViewport(gDisplayListHead++, (u32)spE0 & 0x1FFFFFFF);

    guOrtho(spE4, 0.5f, spEC->width - 0.5f, spEC->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    Gfx_SetVertexAttributes(&spE8[0], spF8[0], spF0[0], -1, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spE8[1], spF8[1], spF0[1], -1, arg3 << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spE8[2], spF8[2], spF0[2], -1, 0, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spE8[3], spF8[3], spF0[3], -1, arg3 << 5, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);

    if (arg6 == 0) {
        gDPLoadTextureBlock(gDisplayListHead++, arg0, G_IM_FMT_IA, G_IM_SIZ_8b, arg3, arg4, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_FOG | G_LIGHTING);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0,
                      COMBINED, 0, 0, 0, COMBINED);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)spE4 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(gDisplayListHead++, (u32)spE8 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void GalleryUI_DrawRotateArrowIcon(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u8 arg6) {
    f32 a1;
    f32 a2;
    s16 spE0[4];
    s16 spD8[4];
    DepthBuffer* spD4;
    Vtx* spD0;
    Mtx* spCC;
    Vp* spC8;

    spD4 = GfxImage_GetCurrent();
    spD0 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    spCC = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    spC8 = Gfx_AllocDisplayList(sizeof(Vp) * 1);

    a1 = arg1;
    a2 = arg2;

    spE0[0] = (COSS(arg5) * -12.0f) + a1;
    spD8[0] = (SINS(arg5) * -12.0f) + a2;

    spE0[1] = (COSS(arg5) * 12.0f) + a1;
    spD8[1] = (SINS(arg5) * 12.0f) + a2;

    spE0[2] = ((COSS(arg5) * -12.0f) - (SINS(arg5) * 56.0f)) + a1;
    spD8[2] = (((SINS(arg5) * -12.0f) + COSS(arg5) * 56.0f)) + a2;

    spE0[3] = ((COSS(arg5) * 12.0f) - (SINS(arg5) * 56.0f)) + a1;
    spD8[3] = (((SINS(arg5) * 12.0f) + COSS(arg5) * 56.0f)) + a2;

    Gfx_SetViewportDimensions(spC8, spD4->width, spD4->height);

    gSPViewport(gDisplayListHead++, (u32)spC8 & 0x1FFFFFFF);

    guOrtho(spCC, 0.5f, spD4->width - 0.5f, spD4->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    Gfx_SetVertexAttributes(&spD0[0], spE0[0], spD8[0], -1, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spD0[1], spE0[1], spD8[1], -1, arg3 << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spD0[2], spE0[2], spD8[2], -1, 0, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spD0[3], spE0[3], spD8[3], -1, arg3 << 5, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);

    if (arg6 == 0) {
        gDPLoadTextureBlock(gDisplayListHead++, arg0, G_IM_FMT_IA, G_IM_SIZ_8b, arg3, arg4, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_FOG | G_LIGHTING);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0,
                      COMBINED, 0, 0, 0, COMBINED);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    gSPMatrix(gDisplayListHead++, (u32)spCC & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(gDisplayListHead++, (u32)spD0 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void GalleryUI_DrawRotateArrowIconMirrored(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u8 arg6) {
    f32 temp_fv0;
    f32 temp_fv1;
    s16 spE0[4];
    s16 spD8[4];
    DepthBuffer* spD4;
    Vtx* spD0;
    Mtx* spCC;
    Vp* spC8;

    spD4 = GfxImage_GetCurrent();
    spD0 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    spCC = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    spC8 = Gfx_AllocDisplayList(sizeof(Vp) * 1);

    temp_fv0 = arg1;
    temp_fv1 = arg2;

    spE0[0] = (COSS(arg5 + 0xC000) * -12.0f) + temp_fv0;
    spD8[0] = (SINS(arg5 + 0xC000) * -12.0f) + temp_fv1;

    spE0[1] = (COSS(arg5 + 0xC000) * 12.0f) + temp_fv0;
    spD8[1] = (SINS(arg5 + 0xC000) * 12.0f) + temp_fv1;

    spE0[2] = ((COSS(arg5 + 0xC000) * -12.0f) - (SINS(arg5 + 0xC000) * 56.0f)) + temp_fv0;
    spD8[2] = ((SINS(arg5 + 0xC000) * -12.0f) + (COSS(arg5 + 0xC000) * 56.0f)) + temp_fv1;

    spE0[3] = ((COSS(arg5 + 0xC000) * 12.0f) - (SINS(arg5 + 0xC000) * 56.0f)) + temp_fv0;
    spD8[3] = ((SINS(arg5 + 0xC000) * 12.0f) + (COSS(arg5 + 0xC000) * 56.0f)) + temp_fv1;

    Gfx_SetViewportDimensions(spC8, spD4->width, spD4->height);

    gSPViewport(gDisplayListHead++, (u32)spC8 & 0x1FFFFFFF);

    guOrtho(spCC, 0.5f, spD4->width - 0.5f, spD4->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    Gfx_SetVertexAttributes(&spD0[0], spE0[0], spD8[0], -1, arg3 << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spD0[1], spE0[1], spD8[1], -1, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spD0[2], spE0[2], spD8[2], -1, arg3 << 5, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&spD0[3], spE0[3], spD8[3], -1, 0, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);

    if (arg6 == 0) {
        gDPLoadTextureBlock(gDisplayListHead++, arg0, G_IM_FMT_IA, G_IM_SIZ_8b, arg3, arg4, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_FOG | G_LIGHTING);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0,
                      COMBINED, 0, 0, 0, COMBINED);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    gSPMatrix(gDisplayListHead++, (u32)spCC & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(gDisplayListHead++, (u32)spD0 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void GalleryUI_DrawNicknameRibbonSegment(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 argA, u8 argB, u8 argC) {
    DepthBuffer* temp_s1 = GfxImage_GetCurrent();
    Vtx* temp_s2 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    Mtx* spAC = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    Vp* spA8 = Gfx_AllocDisplayList(sizeof(Vp));

    Gfx_SetViewportDimensions(spA8, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)spA8 & 0x1FFFFFFF);

    guOrtho(spAC, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    Gfx_SetVertexAttributes(&temp_s2[0], arg1, arg2, -1, argC << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[1], arg1 + arg3, arg2, -1, argB << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[2], arg1, arg2 + arg4, -1, argC << 5, arg6 << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&temp_s2[3], arg1 + arg3, arg2 + arg4, -1, argB << 5, arg6 << 5, 0xFF, 0xFF, 0xFF, 0xFF);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureTile(gDisplayListHead++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg5, 0, arg7, arg8, arg9 - 1, argA - 1,
                       0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)spAC & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void Gallery_DrawNicknameBanner(char* arg0) {
    Color_RGB8 sp4C;
    Color_RGB8 sp48;
    s32 sp44;
    UNUSED s16 pad2;
    s16 sp40;

    if (D_8690A710->unk_014 != 0) {
        sp44 = Font_MeasureTextExtent(0x10, 0, arg0);

        if (D_8690A710->unk_014 == 1) {
            GalleryUI_DrawNicknameRibbonSegment(&D_5001950, 0x3C, 0xAE, 0x22, 0x2B, 0x64, 0x2B, 0, 0, 0x22, 0x2B, 0x21, 0);
            GalleryUI_DrawNicknameRibbonSegment(&D_5001950, 0x5E, 0xAE, 0x22, 0x2B, 0x64, 0x2B, 0x22, 0, 0x44, 0x2B, 0x43, 0x22);
            GalleryUI_DrawNicknameRibbonSegment(&D_5001950, 0x80, 0xAE, 0x20, 0x2B, 0x64, 0x2B, 0x44, 0, 0x64, 0x2B, 0x63, 0x44);
            GalleryUI_DrawNicknameRibbonSegment(&D_5001950, 0xE2, 0xAE, 0x22, 0x2B, 0x64, 0x2B, 0, 0, 0x22, 0x2B, 0, 0x21);
            GalleryUI_DrawNicknameRibbonSegment(&D_5001950, 0xC0, 0xAE, 0x22, 0x2B, 0x64, 0x2B, 0x22, 0, 0x44, 0x2B, 0x22, 0x43);
            GalleryUI_DrawNicknameRibbonSegment(&D_5001950, 0xA0, 0xAE, 0x20, 0x2B, 0x64, 0x2B, 0x44, 0, 0x64, 0x2B, 0x44, 0x63);
            // clang-format off
            sp4C.r = 0xF0; sp4C.g = 0x78; sp4C.b = 0x6E;
            sp48.r = 0xF0; sp48.g = 0xF0; sp48.b = 0x78;
            // clang-format on
            sp40 = 5;
        } else {
            GalleryUI_DrawNicknameRibbonSegment(&D_5003AE8, 0x4C, 0xAE, 0x20, 0x28, 0x20, 0x28, 0, 0, 0x20, 0x28, 0x1F, 0);
            GalleryUI_DrawNicknameRibbonSegment(&D_5003AE8, 0x6C, 0xAE, 0x68, 0x28, 0x20, 0x28, 0x1C, 0, 0x20, 0x2B, 0x87, 0x20);
            GalleryUI_DrawNicknameRibbonSegment(&D_5003AE8, 0xD4, 0xAE, 0x20, 0x28, 0x20, 0x28, 0, 0, 0x20, 0x28, 0, 0x20);
            // clang-format off
            sp4C.r = 0xDC; sp4C.g = 0xFF; sp4C.b = 0xDC;
            sp48.r = 0x78; sp48.g = 0xB4; sp48.b = 0xFF;
            // clang-format on
            sp40 = 7;
        }

        Font_BeginTranslucentTextRendering();
        Font_EnableTwoCycleTexturing();
        Font_SetActive(0x10, 0);
        Gfx_SetEnvColor(sp4C.r, sp4C.g, sp4C.b, 0xFF);
        Gfx_SetPrimColor(sp48.r, sp48.g, sp48.b, 0xFF);
        Font_Printf(0xA0 - (sp44 / 2), sp40 + 0xAE, arg0);
        Font_DisableTwoCycleTexturing();
        Font_EndTexturedTextRendering();
        GalleryUI_DrawGradientQuad(0x50, 0xAC, 0xA0, 0x2D, 0);
    }
}

void Gallery_DrawBackgroundSelectMenu(UNUSED s32 arg0) {
    s32 i;
    s32 var_v1;

    if (D_8690B380 != 0) {
        Gallery_DrawHelpBalloonFrame(0x55, 0x20, 0x96, 0x8C, 0, 0, 0x8C, 0x64);

        gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

        if (D_8690B384 != 0) {
            var_v1 = 0xFF;
        } else {
            var_v1 = 0x37;
        }

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, var_v1);

        Gfx_DrawTextureIa8(0x93, 0x20, 0x18, 0xF, &D_50017E8, 0x18, 0);

        if ((D_8690B38C - 4) != D_8690B384) {
            var_v1 = 0xFF;
        } else {
            var_v1 = 0x37;
        }

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, var_v1);

        Gfx_DrawTextureIa8(0x93, 0x9C, 0x18, 0xF, &D_5001680, 0x18, 0);

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
        gSPDisplayList(gDisplayListHead++, D_8006F5A0);

        Gfx_DrawTextureRgba16Ia8(0x59, (D_8690B388 * 0x14) + 0x35, 0x18, 0xE, D_5000000, &D_50002A0, 0x18, 0x100000);

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

        Font_BeginTranslucentTextRendering();
        Font_SetActive(4, 0);

        for (i = D_8690B384; i < D_8690B384 + 5; i++) {
            if (D_8690B388 == (i - D_8690B384)) {
                Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            }
            Font_Printf(0xA0 - (Font_MeasureTextExtent(4, 0, D_86908C58[i]) / 2), ((i - D_8690B384) * 0x14) + 0x36,
                          D_86908C58[i]);
        }

        Font_EndTexturedTextRendering();
        GalleryUI_DrawGradientQuad(0x4D, 0x34, 0xA6, 0x88, 0);
    }
}

void Gallery_CameraDrawHelpBalloon(void) {
    s32 sp3C;
    s32 sp38;
    Color_RGB8 sp34 = D_86908C98;
    Color_RGB8 sp30 = D_86908C9C;

    if (D_8690B348 >= 3) {
        GalleryUI_DrawGradientQuad(0, 0, 0x140, 0xF0, D_8690B350.unk_04);
    }

    if (D_8690B348 == 4) {
        if (D_8690B350.unk_0E < 0x15) {
            Ui_DrawGradientPanel(D_8690B350.unk_08, D_8690B350.unk_0A - (D_8690B350.unk_0E / 2), D_8690B350.unk_0C,
                          D_8690B350.unk_0E, &sp34, &sp34);
        } else {
            Ui_DrawGradientPanel(D_8690B350.unk_08, D_8690B350.unk_0A - (D_8690B350.unk_0E / 2), D_8690B350.unk_0C,
                          D_8690B350.unk_0E, &sp34, &sp30);
        }

        if (D_8690B350.unk_0E >= 0x1F) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(4, 0);
            sp3C = Font_MeasureTextExtent(4, 0, Text_GetString(NULL, 0, gCameraHelpText, 0));
            sp38 = Text_GetString(NULL, 0, gCameraHelpText, 0);
            Font_Printf((D_8690B350.unk_08 - (sp3C / 2)) + (D_8690B350.unk_0C / 2), D_8690B350.unk_0A - 8, sp38);
            Font_EndTexturedTextRendering();
        }
    }
}

s16 GalleryUI_ClampReelDigitX(s16 arg0) {
    if ((arg0 - D_8690B360.unk_04) <= (D_8690B360.unk_0C + 15.0f)) {
        return 1000;
    }
    return arg0 - D_8690B360.unk_04;
}

void Gallery_DrawPhotoCounterReel(void) {
    s16 sp4E = D_8690B360.unk_0C;
    char sp40[12];
    char sp34[12];
    s16 sp32;
    s16 sp24 = sp4E + 0x17;

    if (D_8690B348 >= 2) {
        return;
    }

    Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp24 + 8), 0x18, 8, 0x1E);
    Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp24 + 0x10), 0x18, 8, 0x1E);

    if (D_8690B348 == 0) {
        if (D_8690B360.unk_00 == 0) {
            sprintf(&sp40, "%d", 0x18 - D_8690B344);

            Font_BeginTranslucentTextRendering();
            Font_SetActive(2, 0);

            if ((0x18 - D_8690B344) >= 0xB) {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0, 0, 0xFF);
            }

            sp32 = 0;
            if ((0x18 - D_8690B344) < 0xA) {
                sp32 = 3;
            }

            Font_Printf(sp24 + sp32 + 9, 0x21, &sp40);
            Font_EndTexturedTextRendering();
        } else {
            sprintf(&sp40, "%d", 0x19 - D_8690B344);
            sprintf(&sp34, "%d", 0x18 - D_8690B344);

            Font_BeginTranslucentTextRendering();
            Font_SetActive(2, 0);

            if ((0x19 - D_8690B344) >= 0xB) {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0, 0, 0xFF);
            }

            sp32 = 0;
            if ((0x18 - D_8690B344) < 0xA) {
                sp32 = 3;
            }

            Font_Printf((sp24 - D_8690B360.unk_00) + sp32 + 0x1D, 0x21, &sp40);

            if ((0x18 - D_8690B344) >= 0xB) {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0, 0, 0xFF);
            }

            sp32 = 0;
            if ((0x18 - D_8690B344) < 0xA) {
                sp32 = 3;
            }

            Font_Printf((sp24 - D_8690B360.unk_00) + sp32 + 9, 0x21, &sp34);
            Font_EndTexturedTextRendering();
        }
    } else if (D_8690B360.unk_00 == 0) {
        if (D_8690B344 != 0) {
            sprintf(&sp40, "%d", 0x18 - D_8690B344);

            Font_BeginTranslucentTextRendering();
            Font_SetActive(2, 0);

            if ((0x18 - D_8690B344) >= 0xB) {
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                Gfx_SetEnvColor(0xFF, 0, 0, 0xFF);
            }

            sp32 = 0;
            if ((0x18 - D_8690B344) < 0xA) {
                sp32 = 3;
            }

            Font_Printf(sp24 + sp32 + 9, 0x21, &sp40);
            Font_EndTexturedTextRendering();
        }
    } else {
        sprintf(&sp40, "%d", 0x17 - D_8690B344);
        sprintf(&sp34, "%d", 0x18 - D_8690B344);

        Font_BeginTranslucentTextRendering();
        Font_SetActive(2, 0);

        if ((0x19 - D_8690B344) >= 0xB) {
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            Gfx_SetEnvColor(0xFF, 0, 0, 0xFF);
        }

        sp32 = 0;
        if ((0x18 - D_8690B344) < 0xA) {
            sp32 = 3;
        }

        Font_Printf((sp24 + D_8690B360.unk_00 + sp32) - 0xB, 0x21, &sp40);

        if ((0x18 - D_8690B344) >= 0xB) {
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            Gfx_SetEnvColor(0xFF, 0, 0, 0xFF);
        }

        sp32 = 0;
        if ((0x18 - D_8690B344) < 0xA) {
            sp32 = 3;
        }

        Font_Printf(sp24 + D_8690B360.unk_00 + sp32 + 9, 0x21, &sp34);
        Font_EndTexturedTextRendering();
    }

    GalleryUI_DrawRotatedSprite(D_50003F0, sp4E, 0x13, 0x18, 0x29);
    Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp24), 0x18, 8, 0x1E);
    Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp24 + 0x18), 0x18, 8, 0x1E);
    Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp24 + 0x20), 0x18, 8, 0x1E);
    Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp24 + 0x28), 0x18, 8, 0x1E);
}

void Gallery_DrawPhotoCounterReelExit(void) {
    s16 sp30 = D_8690B360.unk_0C;
    s16 sp2E;

    if (D_8690B348 < 2) {
        return;
    }

    sp2E = sp30 + 0x17;

    if (GalleryUI_ClampReelDigitX(sp2E + 0) != 0x3E8) {
        Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp2E + 0), 0x18, 8, 0x1E);
    }

    if (GalleryUI_ClampReelDigitX(sp2E + 8) != 0x3E8) {
        Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp2E + 8), 0x18, 8, 0x1E);
    }

    if (GalleryUI_ClampReelDigitX(sp2E + 0x10) != 0x3E8) {
        Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp2E + 0x10), 0x18, 8, 0x1E);
    }

    if (GalleryUI_ClampReelDigitX(sp2E + 0x18) != 0x3E8) {
        Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp2E + 0x18), 0x18, 8, 0x1E);
    }

    if (GalleryUI_ClampReelDigitX(sp2E + 0x20) != 0x3E8) {
        Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp2E + 0x20), 0x18, 8, 0x1E);
    }

    if (GalleryUI_ClampReelDigitX(sp2E + 0x28) != 0x3E8) {
        Gallery_DrawHelpBalloonBubble(D_5000BA0, GalleryUI_ClampReelDigitX(sp2E + 0x28), 0x18, 8, 0x1E);
    }

    GalleryUI_DrawRotatedSprite(D_50003F0, sp30, 0x13, 0x18, 0x29);
}

void Gallery_DrawFrameMarkers(void) {
    if (D_8690B348 == 0) {
        func_86905734(&D_50011D0, D_8690B308.unk_00[0], D_8690B308.unk_00[4], 0x30, 0x19, 0, 0);
        func_86905734(&D_50011D0, D_8690B308.unk_00[1], D_8690B308.unk_00[5], 0x30, 0x19, 0x4000, 1);
        func_86905734(&D_50011D0, D_8690B308.unk_00[2], D_8690B308.unk_00[6], 0x30, 0x19, -0x8000, 1);
        func_86905734(&D_50011D0, D_8690B308.unk_00[3], D_8690B308.unk_00[7], 0x30, 0x19, -0x4000, 1);
        GalleryUI_DrawRotateArrowIcon(&D_5000C90, D_8690B308.unk_10, D_8690B308.unk_20, 0x18, 0x38, 0, 0);
        GalleryUI_DrawRotateArrowIconMirrored(&D_5000C90, D_8690B308.unk_10, D_8690B308.unk_20, 0x18, 0x38, 0, 1);
        GalleryUI_DrawRotateArrowIcon(&D_5000C90, D_8690B308.unk_14, D_8690B308.unk_24, 0x18, 0x38, 0x4000, 1);
        GalleryUI_DrawRotateArrowIconMirrored(&D_5000C90, D_8690B308.unk_14, D_8690B308.unk_24, 0x18, 0x38, 0x4000, 1);
        GalleryUI_DrawRotateArrowIcon(&D_5000C90, D_8690B308.unk_18, D_8690B308.unk_28, 0x18, 0x38, -0x8000, 1);
        GalleryUI_DrawRotateArrowIconMirrored(&D_5000C90, D_8690B308.unk_18, D_8690B308.unk_28, 0x18, 0x38, -0x8000, 1);
        GalleryUI_DrawRotateArrowIcon(&D_5000C90, D_8690B308.unk_1C, D_8690B308.unk_2C, 0x18, 0x38, -0x4000, 1);
        GalleryUI_DrawRotateArrowIconMirrored(&D_5000C90, D_8690B308.unk_1C, D_8690B308.unk_2C, 0x18, 0x38, -0x4000, 1);
    }
}

void Gallery_DrawTutorialTextBox(void) {
    if (D_8690B3C0.unk_00 != 0xFF) {
        Gallery_DrawHelpBalloonFrame(0x3C, 0x9B - (D_8690B3C0.unk_0C / 2), D_8690B3C0.unk_08, D_8690B3C0.unk_0C, 0, 0, 0x9B, 0x7D);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(2, 0);
        Font_SetLineHeight(0xC);
        Font_Printf(0x46, 0x9F - (D_8690B3C0.unk_0C / 2), D_8690B3D0);
        Font_EndTexturedTextRendering();
    }
}
