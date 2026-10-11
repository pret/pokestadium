#include "global.h"
#include "stage_loader.h"
#include "memory.h"
#include "string.h"
#include "dp_intro.h"
#include "gfx_rect.h"
#include "gfx_buffer.h"
#include "memmap.h"
#include "util.h"
#include "profiler.h"
#include "stdarg.h"

typedef struct unk_D_80068CA0 {
    /* 0x00 */ struct unk_D_80068CA0* next;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s8 unk_08[4];
} unk_D_80068CA0; // size = 0xC

s32 gShowCPUProfiler = 0;
s32 gShowMEMProfiler = 0;

static Mtx D_80068BC8 = { {
    {
        0x00010000,
        0x00000000,
        0x00000001,
        0x00000000,
    },
    {
        0x00000000,
        0x00010000,
        0x00000000,
        0x00000001,
    },
    {
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
    },
    {
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
    },
} };

static Vp D_80068C08 = { {
    {
        0x0280,
        0x01E0,
        0x01FF,
        0x0000,
    },
    {
        0x0280,
        0x01E0,
        0x01FF,
        0x0000,
    },

} };

static Vp D_80068C18 = { {
    {
        0x0500,
        0x03C0,
        0x01FF,
        0x0000,
    },
    {
        0x0500,
        0x03C0,
        0x01FF,
        0x0000,
    },
} };

static Vtx D_80068C28[] = {
    VTX(0, 240, 0, 0, 0, 0x00, 0x00, 0x81, 0xFF),
    VTX(0, 0, 0, 0, 0, 0x00, 0x00, 0x81, 0xFF),
    VTX(320, 0, 0, 0, 0, 0x00, 0x00, 0x81, 0xFF),
    VTX(320, 240, 0, 0, 0, 0x00, 0x00, 0x81, 0xFF),
};

static Gfx D_80068C68[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2),
    gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT),
    gsSPVertex(D_80068C28, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

static s32 D_80068C98_Pad[2] = { 0, 0 };

static unk_D_80068CA0* D_80068CA0 = NULL;
static unk_D_80068CA0* D_80068CA4 = NULL;

static s32 D_80068CA8 = 0;

static s32 D_80068CAC_Pad[1] = { 0 };

static u32 D_80068CB0[] = {
    0x00000000, 0xF1000F1F, 0x10000000, 0x00F10000, 0x00000FF1, 0x0000F100, 0x000F100F, 0x10000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xF1000F1F, 0x100F1F10, 0x0FFFF1F1, 0x00F1F11F, 0x1000F100,
    0x00F11001, 0xF100F100, 0xF100F100, 0x00000000, 0x00000000, 0x000000F1, 0x00000000, 0xF1000111, 0x10FFFFF1,
    0xF1F11111, 0x0F11F1F1, 0x10001100, 0x0F110000, 0x1F101F1F, 0x1100F100, 0x00000000, 0x00000000, 0x00000F11,
    0x00000000, 0xF1000000, 0x001F1F11, 0x1FFF1000, 0xF1101F11, 0x00000000, 0x0F100000, 0x0F1001F1, 0x10FFFFF1,
    0x0000000F, 0xFF100000, 0x0000F110, 0x00000000, 0xF1000000, 0x00FFFFF1, 0x01F1F10F, 0x1100F1F1, 0xF1000000,
    0x0F100000, 0x0F100F1F, 0x1011F111, 0x00000001, 0x11100000, 0x000F1100, 0x00000000, 0x11000000, 0x001F1F11,
    0xFFFF11F1, 0x10F1F11F, 0x11000000, 0x01F10000, 0xF110F111, 0xF100F100, 0x00F10000, 0x00000000, 0x00F11000,
    0x00000000, 0xF1000000, 0x00011110, 0x11F11011, 0x00111FF1, 0xF1000000, 0x001F100F, 0x11001100, 0x11001100,
    0x0F110000, 0x000000F1, 0x00110000, 0x00000000, 0x11000000, 0x00000000, 0x00110000, 0x00000111, 0x11000000,
    0x00011001, 0x10000000, 0x00000000, 0x01100000, 0x00000011, 0x00000000, 0x0FFF1000, 0xF1000FFF, 0x100FFF10,
    0x00FF10FF, 0xFFF10FFF, 0x10FFFFF1, 0x0FFF100F, 0xFF100000, 0x00000000, 0x00000000, 0x00000000, 0x000FFF10,
    0xF111F10F, 0xF100F111, 0xF1F111F1, 0x0F1F10F1, 0x1111F111, 0xF1F111F1, 0xF111F1F1, 0x11F10000, 0x00000000,
    0x000F1000, 0x00000F10, 0x00F111F1, 0xF100F101, 0xF1001100, 0xF11100F1, 0xF11F10FF, 0xFF10F100, 0x111100F1,
    0xF100F1F1, 0x00F100F1, 0x0000F100, 0x00F1100F, 0xFF1001F1, 0x001100F1, 0xF100F100, 0xF10000FF, 0x110FFF11,
    0xF10F1011, 0x11F1FFFF, 0x10000F11, 0x1FFF111F, 0xFFF10011, 0x00001100, 0x0F110001, 0x1110001F, 0x10000F11,
    0xF100F100, 0xF1000F11, 0x100111F1, 0xFFFFF100, 0x00F1F111, 0xF100F110, 0xF111F101, 0x11F100F1, 0x0000F100,
    0x01F1000F, 0xFF1000F1, 0x1000F110, 0xF100F100, 0xF100F110, 0x00F100F1, 0x111F11F1, 0x00F1F100, 0xF100F100,
    0xF100F1F1, 0x00F10011, 0x000F1100, 0x001F1001, 0x11100F11, 0x00001100, 0x1FFF110F, 0xFF10FFFF, 0xF11FFF11,
    0x000F101F, 0xFF111FFF, 0x1100F100, 0x1FFF111F, 0xFF110000, 0x00011000, 0x00011000, 0x00000110, 0x0000F100,
    0x01111001, 0x11101111, 0x11011110, 0x00011001, 0x11100111, 0x10001100, 0x01111001, 0x11100000, 0x00000000,
    0x00000000, 0x00000000, 0x00001100, 0x0FFF1000, 0xF100FFFF, 0x100FFF10, 0xFFF100FF, 0xFFF1FFFF, 0xF10FFF10,
    0xF100F10F, 0xFF100000, 0xF1F100F1, 0xF10000F1, 0x00F1F100, 0xF10FFF10, 0xF111100F, 0x1F10F111, 0xF1F111F1,
    0xF11F10F1, 0x1111F111, 0x11F111F1, 0xF100F101, 0xF1100000, 0xF1F10F11, 0xF10000FF, 0x1FF1F100, 0xF1F111F1,
    0xF1FF10F1, 0x11F1F100, 0xF1F10011, 0xF101F1F1, 0x0000F100, 0x00F10011, 0xF100F100, 0xF1000000, 0xF1F1F110,
    0xF10000F1, 0xF1F1FF10, 0xF1F100F1, 0xF1F1F1F1, 0x00F1FFFF, 0x11F10000, 0xF100F1FF, 0xFF10FFFF, 0x10F1FFF1,
    0xFFFFF100, 0xF1000000, 0xF1FF1100, 0xF10000F1, 0xF1F1F1F1, 0xF1F100F1, 0xF1FFF1FF, 0xFFF1F111, 0xF1F10000,
    0xF100F1F1, 0x1110F111, 0x10F111F1, 0xF111F100, 0xF100F100, 0xF1F1F100, 0xF10000F1, 0x11F1F11F, 0xF1F100F1,
    0xF111F1F1, 0x11F1F100, 0xF1F100F1, 0xF10F11F1, 0x0000F100, 0x00F100F1, 0xF100F100, 0xF100F100, 0xF1F11F10,
    0xF10000F1, 0x00F1F101, 0xF1F100F1, 0x1FFF11F1, 0x00F1FFFF, 0x111FFF11, 0xFFF110FF, 0xFFF1F100, 0x001FFF11,
    0xF100F10F, 0xFF101FFF, 0x11F101F1, 0xFFFFF1F1, 0x00F1F100, 0xF11FFF11, 0x01111011, 0x00111111, 0x10011110,
    0x11110011, 0x11111100, 0x00011110, 0x11001101, 0x11100111, 0x10110011, 0x11111111, 0x00111100, 0x11011110,
    0xFFFF100F, 0xFF10FFFF, 0x100FFF10, 0xFFFFF1F1, 0x00F1F100, 0xF1F100F1, 0xF100F1F1, 0x00F1FFFF, 0xF100FF10,
    0x0000000F, 0xF10000F1, 0x00000000, 0xF111F1F1, 0x11F1F111, 0xF1F111F1, 0x11F111F1, 0x00F1F100, 0xF1F100F1,
    0xF100F1F1, 0x00F11111, 0xF100F110, 0xF1000001, 0xF1000F1F, 0x10000000, 0xF100F1F1, 0x00F1F100, 0xF1F10011,
    0x00F100F1, 0x00F1F100, 0xF1F100F1, 0x1F1F11F1, 0x00F1000F, 0x1100F100, 0x1F100000, 0xF100F111, 0xF1000000,
    0xF100F1F1, 0x00F1F100, 0xF11FFF10, 0x00F100F1, 0x00F1F100, 0xF1F1F1F1, 0x01F1101F, 0x1F1100F1, 0x1000F100,
    0x01F10000, 0xF1001100, 0x11000000, 0xFFFF11F1, 0xF1F1FFFF, 0x110111F1, 0x00F100F1, 0x00F11F1F, 0x11F1F1F1,
    0x0F1F1001, 0xF1100F11, 0x0000F100, 0x001F1000, 0xF1000000, 0x00000000, 0xF11110F1, 0x1F11F11F, 0x10F100F1,
    0x00F100F1, 0x00F10F1F, 0x10F1F1F1, 0xF111F100, 0xF100F110, 0x0000F100, 0x0001F100, 0xF1000000, 0x00000000,
    0xF100001F, 0xF1F1F101, 0xF11FFF11, 0x00F1001F, 0xFF1101F1, 0x101F1F11, 0xF100F100, 0xF100FFFF, 0xF100FF10,
    0x0000110F, 0xF1000000, 0x00FFFFF1, 0x11000001, 0x11111100, 0x11011110, 0x00110001, 0x11100011, 0x00011110,
    0x11001100, 0x11001111, 0x11001110, 0x00000001, 0x11000000, 0x00111111, 0x00000000, 0x0000F100, 0x00000000,
    0x000F1000, 0x000000FF, 0x10000000, 0xF1000000, 0x00000000, 0x00F10000, 0x0FF10000, 0x00000000, 0x00000000,
    0x00000000, 0x0000F100, 0x00000000, 0x000F1000, 0x00000F11, 0x100FF100, 0xF1000000, 0xF100000F, 0x10F10000,
    0x01F10000, 0x00000000, 0x00000000, 0x0000000F, 0xF100FFF1, 0x000FF100, 0x0FFF100F, 0xF1000F10, 0x00F11F10,
    0xFFF10000, 0x11000001, 0x10F10F10, 0x00F1000F, 0x1F10FFF1, 0x000FF100, 0x00000001, 0x1F10F11F, 0x10F11F10,
    0xF11F10F1, 0x1F10FFF1, 0x00F10F10, 0xF11F1000, 0xF100000F, 0x10F1F110, 0x00F100F1, 0xF1F1F11F, 0x10F11F10,
    0x0000000F, 0xFF10F10F, 0x10F10110, 0xF10F10FF, 0xFF101F11, 0x001FFF10, 0xF10F1000, 0xF100000F, 0x10FF1100,
    0x00F100F1, 0xF1F1F10F, 0x10F10F10, 0x000000F1, 0x1F10F10F, 0x10F10F10, 0xF10F10F1, 0x11100F10, 0x00011F10,
    0xF10F1000, 0xF100F10F, 0x10F1F100, 0x00F100F1, 0xF1F1F10F, 0x10F10F10, 0x0000001F, 0xF1F1FFF1, 0x101FF110,
    0x1FFF101F, 0xFF100F10, 0x000FF110, 0xF10F1000, 0xF1001FF1, 0x10F11F10, 0x0FFF10F1, 0xF1F1F10F, 0x101FF110,
    0x00000001, 0x11111111, 0x00011100, 0x01111001, 0x11100110, 0x00011100, 0x11011000, 0x11000111, 0x00110110,
    0x01111011, 0x11111101, 0x10011100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000F10, 0x00F1000F, 0x1000FFFF, 0xF1000000, 0x00000000, 0x00000000, 0x00000000,
    0x00F10000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000F110, 0x00F10001, 0xF1001111, 0x11000000,
    0x0FF1000F, 0xF100F1FF, 0x100FFFF1, 0x00F100F1, 0x0F10F100, 0xF1F100F1, 0xF100F1F1, 0x0F10FFFF, 0x1000F100,
    0x00F10000, 0xF1000000, 0x00000000, 0xF11F10F1, 0x1F10FF11, 0x10F11111, 0x0FFF10F1, 0x0F10F100, 0xF1F1F1F1,
    0x1F1F11F1, 0x0F10111F, 0x100F1100, 0x00110000, 0x1F100000, 0x00000000, 0xF10F10F1, 0x0F10F110, 0x001FFF10,
    0x01F110F1, 0x0F10F100, 0xF1F1F1F1, 0x01F1101F, 0xFF100FF1, 0x1001F100, 0x00F10000, 0xF1100000, 0x00000000,
    0xFFF1101F, 0xFF10F100, 0x000111F1, 0x00F100F1, 0x0F101F1F, 0x11F1F1F1, 0x0F1F1001, 0x1F10F111, 0x0000F100,
    0x00F10000, 0xF1000000, 0x00000000, 0xF1110001, 0x1F10F100, 0x00FFFF11, 0x00FF101F, 0xF11001F1, 0x101F1F11,
    0xF111F10F, 0xF110FFFF, 0x10001F10, 0x00F1000F, 0x11000000, 0x00000000, 0x11000000, 0x01101100, 0x00111110,
    0x00111001, 0x11000011, 0x00011110, 0x11001101, 0x11001111, 0x10000110, 0x00110001, 0x10000000, 0x00000000,
};

static unk_D_800A7450 D_800A7450;
static unk_func_80007444* stage;
static Mtx D_800A7468;
static char pad_D_800A74A8[0x8];
static Gfx* D_800A74B0;

s32 StageContext_IsHighResolution(void);
void TextRenderer_FlushQueuedStrings(Gfx**, s32);
void TextRenderer_ClearQueuedStrings(void);

void StageFade_Update(void) {
    u8 a;
    u8 b;
    u8 g;
    u8 r;
    unk_func_80007444* v0 = stage;

    if (stage->fade_mode == 0) {
        return;
    }

    r = RGBA16_GET_R(stage->clear_color);
    g = RGBA16_GET_G(stage->clear_color);
    b = RGBA16_GET_B(stage->clear_color);

    r = (r << 3) | (r >> 2);
    g = (g << 3) | (g >> 2);
    b = (b << 3) | (b >> 2);

    switch (stage->fade_mode) {
        case 1:
            a = 255;
            break;

        case 2:
            a = (255 - ((stage->unk_13 * 255) / stage->unk_12));
            break;

        case 3:
            a = ((stage->unk_13 * 255) / stage->unk_12);
            break;
    }

    if (a != 0) {
        gDPSetEnvColor(gDisplayListHead++, r, g, b, a);
        gSPDisplayList(gDisplayListHead++, D_80068C68);
    }

    if (stage->fade_mode == 1) {
        return;
    }

    stage->unk_13++;
    if (stage->unk_13 == stage->unk_12) {
        if (stage->fade_mode == 2) {
            stage->fade_mode = 0;
        } else {
            stage->fade_mode = 1;
        }
    }
}

s32 StageFade_Start(s32 arg0) {
    s32 ret = 0;

    if ((stage != NULL) && ((stage->fade_mode == 1) || (stage->fade_mode == 0))) {
        if (stage->fade_mode == 1) {
            stage->fade_mode = 2;
        } else {
            stage->fade_mode = 3;
        }

        ret = 1;
        stage->unk_13 = 0;
        stage->unk_12 = arg0;
    }

    return ret;
}

s32 StageFade_StartFromOpaque(s32 arg0) {
    s32 ret = 0;

    if ((stage != NULL) && (stage->fade_mode == 1)) {
        ret = StageFade_Start(arg0);
    }

    return ret;
}

s32 StageFade_StartFromTransparent(s32 arg0) {
    s32 ret = 0;

    if ((stage != NULL) && (stage->fade_mode == 0)) {
        ret = StageFade_Start(arg0);
    }

    return ret;
}

void StageFade_SetMode(s32 fade_mode) {
    if (stage != NULL) {
        stage->fade_mode = fade_mode;
        stage->unk_13 = 0;
        stage->unk_12 = 0;
    }
}

void Profiler_SetDisplayModes(u32 arg0, u32 arg1) {
    if (arg0 < 3) {
        gShowCPUProfiler = arg0;
    }

    if (arg1 < 2) {
        gShowMEMProfiler = arg1;
    }
}

void Gfx_SetDefaultRenderState(void) {
    gDPPipeSync(gDisplayListHead++);
    gDPPipelineMode(gDisplayListHead++, G_PM_1PRIMITIVE);
    gDPSetTextureLOD(gDisplayListHead++, G_TL_TILE);
    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
    gDPSetTextureDetail(gDisplayListHead++, G_TD_CLAMP);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);
    gDPSetCombineKey(gDisplayListHead++, G_CK_NONE);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
    gDPSetColorDither(gDisplayListHead++, G_CD_MAGICSQ);
    gDPSetAlphaDither(gDisplayListHead++, G_AD_PATTERN);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPPipeSync(gDisplayListHead++);
}

void Gfx_SetDefaultGeometryState(void) {
    gSPClearGeometryMode(gDisplayListHead++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                 G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gSPTexture(gDisplayListHead++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
}

void StageLoader_ResetGraphicsState(void) {
    GfxImage_ResetCurrent();
    Memmap_SetSegmentMap(0, 0x80000000, osMemSize);
    Memmap_SetSegments(&gDisplayListHead);
    Gfx_SetDefaultRenderState();
    Gfx_SetDefaultGeometryState();
}

void StageLoader_SetupFrame(void) {
    GfxImage_SetRenderTarget(&gDisplayListHead, stage->unk_18[stage->unk_16]);
    guOrtho(&D_800A7468, 0.0f, 320.0f, 0.0f, 240.0f, -2.0f, 2.0f, 1.0f);
    Gfx_SetDefaultRenderState();
    Gfx_SetDefaultGeometryState();

    gSPMatrix(gDisplayListHead++, (u32)&D_80068BC8 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gDisplayListHead++, (u32)&D_800A7468 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    if (stage->zoom == 1) {
        gSPViewport(gDisplayListHead++, (u32)&D_80068C18 & 0x1FFFFFFF);
    } else {
        gSPViewport(gDisplayListHead++, (u32)&D_80068C08 & 0x1FFFFFFF);
    }

    Gfx_SetScissorRect(&gDisplayListHead, 0, 0, stage->unk_00, stage->unk_02);
    StageFade_Update();

    if (gShowCPUProfiler != 0) {
        print_profiler_metrics();
    }

    TextRenderer_FlushQueuedStrings(&gDisplayListHead, StageContext_IsHighResolution());

    if (gShowCPUProfiler != 0) {
        draw_profiler(gShowCPUProfiler - 1);
    }

    if ((gShowCPUProfiler != 0) && (gShowMEMProfiler != 0)) {
        Util_DrawMemProfiler(&gDisplayListHead);
    }

    gDPFullSync(gDisplayListHead++);
    gSPEndDisplayList(gDisplayListHead++);

    Gfx_AllocDisplayList(0);
}

void StageLoader_SwapDisplayListAndReset(void) {
    Gfx_SwapDisplayListBuffer();
    StageLoader_ResetGraphicsState();
}

void StageLoader_BeginFrame(void) {
    StageLoader_SetupFrame();
    D_800A7450.unk_00 = stage->unk_10;
    D_800A7450.zoom = stage->zoom;
    D_800A7450.unk_02 = stage->unk_0D;
    D_800A7450.unk_03 = stage->unk_16;
    D_800A7450.unk_0C = stage->unk_18[stage->unk_16];
    Gfx_GetDisplayListRange(&D_800A7450.unk_04, &D_800A7450.unk_08);
    stage->unk_16++;
    if (stage->unk_16 == stage->unk_0E) {
        stage->unk_16 = 0;
    }
}

void StageLoader_FillFrame(void) {
    BgStage_DrawFrame();

    gDPPipeSync(gDisplayListHead++);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetFillColor(gDisplayListHead++, (stage->clear_color << 0x10) | stage->clear_color);
    gDPFillRectangle(gDisplayListHead++, stage->unk_04, stage->unk_08, stage->unk_06,
                     stage->unk_0A);
    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
}

unk_func_80007444* StageContext_Allocate(s8 zoom, s8 arg1, s8 arg2, s8 arg3, s8 arg4, s32 arg5) {
    unk_func_80007444* temp_v0 = main_pool_alloc(sizeof(unk_func_80007444), 0);

    if (temp_v0 != NULL) {
        if (zoom == 1) {
            temp_v0->unk_00 = 0x280, temp_v0->unk_02 = 0x1E0;
        } else {
            temp_v0->unk_00 = 0x140, temp_v0->unk_02 = 0xF0;
        }

        temp_v0->fade_mode = 1;
        temp_v0->zoom = zoom;
        temp_v0->unk_0D = arg1;
        temp_v0->unk_0E = arg2;
        temp_v0->unk_0F = arg3;
        temp_v0->unk_10 = arg4;
        temp_v0->clear_color = Display_GetFramebufferClearColor();
        temp_v0->unk_16 = 0;
        temp_v0->unk_04 = 0;
        temp_v0->unk_06 = temp_v0->unk_00 - 1;
        temp_v0->unk_08 = 0;
        temp_v0->unk_0A = temp_v0->unk_02 - 1;

        temp_v0->unk_18[0] = 0;
        temp_v0->unk_18[1] = 0;
        temp_v0->unk_18[2] = 0;

        if (arg5 != 0) {
            s32 i;

            for (i = 0; i < temp_v0->unk_0E; i++) {
                temp_v0->unk_18[i] =
                    GfxImage_Allocate(0, IMAGE_SIZE_BITS_16b, temp_v0->unk_00, temp_v0->unk_02, MEMORY_POOL_RIGHT);
            }

            if (temp_v0->unk_0F == 1) {
                void* temp_s3 =
                    GfxImage_Allocate(0, IMAGE_SIZE_BITS_16b, temp_v0->unk_00, temp_v0->unk_02, MEMORY_POOL_LEFT);

                for (i = 0; i < temp_v0->unk_0E; i++) {
                    GfxImage_AttachDepthBuffer(temp_v0->unk_18[i], temp_s3);
                }
            }
        }
    }

    return temp_v0;
}

unk_func_80007444* StageContext_GetCurrent(void) {
    return stage;
}

s32 StageContext_GetFadeMode(void) {
    return stage->fade_mode;
}

void StageContext_SaveAndSwitch(unk_func_80007444* arg0) {
    arg0->fade_mode = stage->fade_mode;
    arg0->unk_12 = stage->unk_12;
    arg0->unk_13 = stage->unk_13;
    arg0->clear_color = stage->clear_color;

    if (stage->unk_16 < arg0->unk_0E) {
        arg0->unk_16 = stage->unk_16;
    } else {
        arg0->unk_16 = 0;
    }

    stage = arg0;
}

void StageContext_Activate(unk_func_80007444* arg0) {
    stage = arg0;
    Display_QueueFramebufferRequest(NULL);
    Display_WaitForCompletion();
    Display_ClearFramebufferLine(arg0->clear_color);
    StageLoader_SwapDisplayListAndReset();
}

void StageContext_Deactivate(void) {
    if (stage != NULL) {
        StageLoader_FillFrame();
        StageLoader_BeginFrame();
        Display_QueueFramebufferRequest(&D_800A7450);
        Display_WaitForCompletion();
        Display_WaitForFrames(2);
        stage = NULL;
    }
}

void StageLoader_WaitForRetrace(void) {
    while (Display_IsFrameReady() == 0) {}
}

void StageLoader_UpdateSegments(void) {
    Memmap_SetSegments(&gDisplayListHead);
}

s32 BgStage_AdvanceFrame(void) {
    StageLoader_BeginFrame();
    Display_QueueFramebufferRequest(&D_800A7450);
    Display_WaitForCompletion();
    StageLoader_SwapDisplayListAndReset();
}

void StageLoader_RunFrames(s32 timer) {
    while (timer-- > 0) {
        StageLoader_FillFrame();
        StageLoader_BeginFrame();
        Display_QueueFramebufferRequest(&D_800A7450);
        Display_WaitForCompletion();
        StageLoader_SwapDisplayListAndReset();
    }
}

s32 BgStage_RunUntilCondition(u32 timer, s32 (*f)(u8)) {
    s32 var_s1 = 0;

    if (timer == 0) {
        while (var_s1 == 0) {
            var_s1 = f(stage->fade_mode);
            BgStage_AdvanceFrame();
        }
    } else {
        while (timer-- > 0) {
            var_s1 = f(stage->fade_mode);
            BgStage_AdvanceFrame();
            if (var_s1 != 0) {
                break;
            }
        }
    }
    return var_s1;
}

s32 BgStage_WaitForCondition(s32 (*arg0)(u8), s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s2;

    var_s2 = 0;
    var_s0 = 1;
    StageFade_StartFromOpaque(arg1);

    while (var_s0 != 0) {
        temp_v0 = arg0(stage->fade_mode);
        if (var_s2 == 0) {
            if (temp_v0 != 0) {
                var_s2 = temp_v0;
                StageFade_StartFromTransparent(arg2);
            }
        } else if (stage->fade_mode == 1) {
            var_s0 = 0;
        }
        BgStage_AdvanceFrame();
    }

    return var_s2;
}

void StageContext_SetClearColor(u16 color) {
    if (stage != NULL) {
        stage->clear_color = color;
        Display_ClearFramebufferLine(color);
    }
}

void BgStage_DrawFrame(void) {
    if (stage != NULL) {
        GfxImage_SetRenderTarget(&gDisplayListHead, stage->unk_18[stage->unk_16]);

        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    }
}

unk_D_80068BB0* StageContext_GetCurrentImage(void) {
    unk_D_80068BB0* ret = NULL;

    if (stage != NULL) {
        ret = stage->unk_18[stage->unk_16];
    }

    return ret;
}

s32 StageContext_IsHighResolution(void) {
    s32 ret = 0;

    if (stage != NULL) {
        ret = stage->zoom == 1;
    }

    return ret;
}

void TextRenderer_SetupGlyphState(void) {
    gDPPipeSync(D_800A74B0++);
    gDPSetCycleType(D_800A74B0++, G_CYC_1CYCLE);
    gDPSetTexturePersp(D_800A74B0++, G_TP_NONE);
    gDPSetTextureFilter(D_800A74B0++, G_TF_POINT);
    gDPSetPrimColor(D_800A74B0++, 0, 0, 255, 255, 255, 255);
    gDPSetRenderMode(D_800A74B0++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineMode(D_800A74B0++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPLoadTextureBlock_4b(D_800A74B0++, (u32)D_80068CB0 & 0x1FFFFFFF, G_IM_FMT_IA, 96, 48, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 7, 6, G_TX_NOLOD, G_TX_NOLOD);
}

void TextRenderer_RestoreState(void) {
    gDPPipeSync(D_800A74B0++);
    gDPSetTexturePersp(D_800A74B0++, G_TP_PERSP);
    gDPSetTextureFilter(D_800A74B0++, G_TF_BILERP);
    gDPSetAlphaCompare(D_800A74B0++, G_AC_NONE);
    gSPTexture(D_800A74B0++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void TextRenderer_DrawGlyphSmall(s16 arg0, s16 arg1, s16 arg2) {
    gSPTextureRectangle(D_800A74B0++, arg0 * 4, arg1 * 4, (arg0 + 6) << 2, (arg1 + 8) << 2, G_TX_RENDERTILE,
                        ((arg2 % 16) * 6) << 5, (u16)(arg2 / 16) << 8, 0x0400, 0x0400);
}

void TextRenderer_DrawGlyphLarge(s16 arg0, s16 arg1, s16 arg2) {
    gSPTextureRectangle(D_800A74B0++, arg0 * 8, arg1 * 8, (arg0 + 6) << 3, (arg1 + 8) << 3, G_TX_RENDERTILE,
                        ((arg2 % 16) * 6) << 5, (u16)(arg2 / 16) << 8, 0x0200, 0x0200);
}

void TextRenderer_DrawString(s16 arg0, s16 arg1, s8* arg2, s32 arg3) {
    s32 temp_s0;

    while (*arg2 != 0) {
        temp_s0 = (*arg2++ & 0x7F) - 0x20;
        if (temp_s0 != 0) {
            if (arg3 == 0) {
                TextRenderer_DrawGlyphSmall(arg0, arg1, temp_s0);
            }

            if (arg3 == 1) {
                TextRenderer_DrawGlyphLarge(arg0, arg1, temp_s0);
            }
        }
        arg0 += 6;
    }
}

void TextRenderer_FlushQueuedStrings(Gfx** arg0, s32 arg1) {
    unk_D_80068CA0* var_s0 = D_80068CA0;
    unk_D_80068CA0* var_s2 = D_80068CA4;

    D_800A74B0 = *arg0;

    if ((var_s0 != NULL) || (var_s2 != NULL)) {
        TextRenderer_SetupGlyphState();

        while (var_s0 != NULL) {
            unk_D_80068CA0* next = var_s0->next;

            TextRenderer_DrawString(var_s0->unk_04, var_s0->unk_06, var_s0->unk_08, arg1);
            Util_Free(var_s0);
            var_s0 = next;
        }

        while (var_s2 != NULL) {
            TextRenderer_DrawString(var_s2->unk_04, var_s2->unk_06, var_s2->unk_08, arg1);
            var_s2 = var_s2->next;
        }

        TextRenderer_RestoreState();
        D_80068CA0 = NULL;
    }

    *arg0 = D_800A74B0;

    D_80068CA8++;
    if (D_80068CA8 >= 0x384) {
        D_80068CA8 = 0;
        if (D_80068CA4 != NULL) {
            TextRenderer_ClearQueuedStrings();
        }
    }
}

void TextRenderer_ClearQueuedStrings(void) {
    unk_D_80068CA0* var_s0 = D_80068CA4;

    while (var_s0 != NULL) {
        unk_D_80068CA0* next = var_s0->next;

        Util_Free(var_s0);
        var_s0 = next;
    }

    D_80068CA4 = NULL;
}

char* TextRenderer_FormatCopy(char* buffer, const char* data, size_t size) {
    return (char*)memcpy(buffer, data, size) + size;
}

s32 HAL_Printf(s16 x, s16 y, const char* fmt, ...) {
    s32 sp124;
    char sp20[0x104];
    unk_D_80068CA0* sp1C;
    va_list args;

    va_start(args, fmt);

    sp124 = _Printf(TextRenderer_FormatCopy, sp20, fmt, args);

    if (sp124 > 0) {
        sp1C = Util_Malloc(sp124 + sizeof(unk_D_80068CA0));
        if (sp1C != NULL) {
            sp1C->unk_04 = x;
            sp1C->unk_06 = y;
            memcpy(sp1C->unk_08, &sp20, sp124);
            sp1C->unk_08[sp124] = 0;
            sp1C->next = D_80068CA0;
            D_80068CA0 = sp1C;
        }
    }

    va_end(args);

    return sp124;
}

s32 TextRenderer_QueuePersistentString(s16 x, s16 y, const char* fmt, ...) {
    s32 sp124;
    char sp20[0x104];
    unk_D_80068CA0* sp1C;
    va_list args;

    va_start(args, fmt);

    D_80068CA8 = 0;
    sp124 = _Printf(TextRenderer_FormatCopy, sp20, fmt, args);
    if (sp124 > 0) {
        sp1C = Util_Malloc(sp124 + sizeof(unk_D_80068CA0));
        if (sp1C != NULL) {
            sp1C->unk_04 = x;
            sp1C->unk_06 = y;
            memcpy(sp1C->unk_08, &sp20, sp124);
            sp1C->unk_08[sp124] = 0;
            sp1C->next = D_80068CA4;
            D_80068CA4 = sp1C;
        }
    }

    va_end(args);

    return sp124;
}
