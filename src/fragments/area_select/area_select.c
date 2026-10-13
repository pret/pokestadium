#include "area_select.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/game_state.h"
#include "src/save_data.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/cry.h"
#include "src/gfx_buffer.h"
#include "src/DDC0.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/math_util.h"

typedef struct AreaSelectEntryConfig {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s8 unk_06;
    /* 0x07 */ s8 unk_07;
    /* 0x08 */ s8 unk_08;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ Color_RGBA8 unk_0A;
} AreaSelectEntryConfig; // size = 0xE

typedef struct AreaSelectMagnemitePoint {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
} AreaSelectMagnemitePoint; // size = 0x6

typedef struct AreaSelectMagnemiteTrail {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ AreaSelectMagnemitePoint unk_0C[4];
} AreaSelectMagnemiteTrail; // size = 0x24

typedef struct AreaSelectCursorGlow {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 fadeProgress;
    /* 0x08 */ Color_RGBA8 color;
} AreaSelectCursorGlow; // size >= 0xC

static s16 sAreaSelectBackgroundFadeAlpha = 0;

static s16 sAreaSelectGlowRadius = 0;

static s16 sAreaSelectStateIds[] = {
    STATE_STADIUM_MENU,   STATE_FREE_BATTLE, STATE_GYM_LEADER_CASTLE, STATE_VS_MEWTWO,   STATE_KIDS_CLUB,
    STATE_VICTORY_PALACE, STATE_POKEMON_LAB, STATE_GB_TOWER,          STATE_MENU_SELECT,
};

static u8* sAreaSelectNameBannerTextures[] = {
    0x03006E60, 0x0300D060, 0x03013260, 0x03019460, 0x0301F660,
    0x03025860, 0x0302BA60, 0x03031C60, 0x03037E60, 0x0303E060,
};

static AreaSelectEntryConfig sAreaSelectEntryConfigs[9] = {
    // unused?
    { 0x012C, 0x00B9, 0x004B, 0x03, 0x04, 0x06, 0x07, { 0x32, 0x50, 0x96, 0x00 } },
    // Free Battle
    { 0x0208, 0x0118, 0x004B, 0x07, 0x08, 0x04, 0x08, { 0x32, 0x50, 0x96, 0x00 } },
    // Gym Leader Castle
    { 0x006E, 0x005A, 0x0041, 0x08, 0x06, 0x08, 0x03, { 0x32, 0x50, 0x96, 0x00 } },
    // VS Mewtwo
    { 0x012C, 0x0041, 0x0041, 0x08, 0x00, 0x02, 0x07, { 0x32, 0x50, 0x96, 0x00 } },
    // Minigames
    { 0x015E, 0x013B, 0x0050, 0x00, 0x08, 0x05, 0x01, { 0x32, 0x50, 0x96, 0x00 } },
    // Hall of Fame
    { 0x00BE, 0x014A, 0x0046, 0x06, 0x08, 0x08, 0x04, { 0x32, 0x50, 0x96, 0x00 } },
    // Professor Oak's Lab
    { 0x0078, 0x00E6, 0x0041, 0x02, 0x05, 0x08, 0x00, { 0x32, 0x50, 0x96, 0x00 } },
    // GB Tower
    { 0x01FE, 0x0096, 0x0041, 0x03, 0x01, 0x00, 0x08, { 0x32, 0x50, 0x96, 0x00 } },
    // Stadium
    { 300, 185, 10, 0x08, 0x08, 0x08, 0x08, { 0x32, 0x50, 0x96, 0x00 } },
};

static u8* sAreaSelectMagnemiteTextures[] = { 0x03005000, 0x03005A20, 0x03006440, 0x03005A20 };

static char** sAreaSelectStrings;
static BinArchive* sAreaSelectBackgroundArchive;
static Vp sAreaSelectViewport;
static Mtx sAreaSelectProjectionMtx;
static u8* sAreaSelectCurrentBackground;
static u8* sAreaSelectNextBackground;
static AreaSelectCursorGlow sAreaSelectCursor;
static AreaSelectMagnemiteTrail sAreaSelectMagnemiteTrails[3];
static s32 pad_D_822031D0[0x2];
static s16 sAreaSelectSelectedIndex;
static s16 sAreaSelectPreviousIndex;
static s16 sAreaSelectTransitionFrame;
static ModeSettings sAreaSelectModeSettings;
static GameOptions sAreaSelectGameOptions;

s32 AreaSelect_CheckCartRemoved(s32 arg0) {
    u32 temp_a0 = osSetIntMask(1);

    if (!(HW_REG(PI_STATUS_REG, u32) & 3) && ((*(u32*)0xB0000D10 & 0xFFFF) != 0x400)) {
        arg0 = -0x40;
    }

    osSetIntMask(temp_a0);
    return arg0;
}

void AreaSelect_DrawCrossfadeBackground(u8* fade_out_texture, u8* fade_in_texture, u8 alpha) {
    s32 i;
    s32 j;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 640, 480);
    gDPSetCombineLERP(gDisplayListHead++, TEXEL1, TEXEL0, ENV_ALPHA, TEXEL0, TEXEL1, TEXEL0, ENVIRONMENT, TEXEL0, 0, 0,
                      0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, alpha);
    gDPPipeSync(gDisplayListHead++);

    for (i = 0; i < 0x1E0; i += 0x20) {
        for (j = 0; j < 0x280; j += 0x20) {
            gDPLoadTextureBlock(gDisplayListHead++, fade_out_texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gDPLoadMultiBlock(gDisplayListHead++, fade_in_texture, 0x0100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                              G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                              G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, j << 2, i << 2, (j + 0x20) << 2, (i + 0x20) << 2, G_TX_RENDERTILE,
                                0, 0, 0x0200, 0x0200);

            fade_out_texture += 0x200;
            fade_in_texture += 0x200;
        }
    }
}

/*
    Handles setting the coordinates for the fade out upon selecting an area
    Proposed name change: AreaSelect_SetFadeOutCoordinates
*/
Vtx* AreaSelect_BuildGlowQuadVerts(void) {
    Vtx* vertex;
    s16 offset;
    s16 x;
    s16 y;
    u8 r;
    u8 g;
    u8 b;
    u8 alpha;

    x = sAreaSelectCursor.unk_00;
    y = sAreaSelectCursor.unk_02;
    offset = sAreaSelectCursor.unk_04;
    r = sAreaSelectCursor.color.r;
    g = sAreaSelectCursor.color.g;
    b = sAreaSelectCursor.color.b;
    alpha = sAreaSelectCursor.color.a;

    vertex = Gfx_AllocDisplayList(sizeof(Vtx) * 8);

    if (vertex != NULL) {
        Gfx_SetVertexAttributes(&vertex[0], x - offset, y - offset, -1, 0, 0, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[1], x - offset, y + offset, -1, 0, 2016, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[2], x + offset, y + offset, -1, 2016, 2016, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[3], x + offset, y - offset, -1, 2016, 0, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[4], x - 2000, y - 2000, -1, 0, 0, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[5], x - 2000, y + 2000, -1, 0, 0, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[6], x + 2000, y + 2000, -1, 0, 0, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[7], x + 2000, y - 2000, -1, 0, 0, r, g, b, alpha);
    }

    return vertex;
}

/*
    Handles Drawing the Fade out
    Proposed name change: AreaSelect_DrawFadeOut
*/
void AreaSelect_DrawCursorGlow(void) {
    Vtx* vertex;

    // proxy for "Player hasn't selected an area"
    if (sAreaSelectCursor.color.a <= 0) {
        return;
    }

    vertex = AreaSelect_BuildGlowQuadVerts();

    if (vertex != 0) {
        gDPPipeSync(gDisplayListHead++);

        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, sAreaSelectCursor.fadeProgress);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, SHADE, ENV_ALPHA, SHADE, 0, 0, 0, SHADE, ENVIRONMENT, SHADE,
                          ENV_ALPHA, SHADE, 0, 0, 0, SHADE);

        gSPVertex(gDisplayListHead++, (u32)vertex & 0x1FFFFFFF, 8, 0);
        gSP2Triangles(gDisplayListHead++, 0, 4, 1, 0, 1, 4, 5, 0);
        gSP2Triangles(gDisplayListHead++, 1, 5, 2, 0, 2, 5, 6, 0);
        gSP2Triangles(gDisplayListHead++, 2, 6, 7, 0, 2, 7, 3, 0);
        gSP2Triangles(gDisplayListHead++, 3, 4, 0, 0, 3, 7, 4, 0);

        gDPPipeSync(gDisplayListHead++);

        gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
        gDPSetRenderMode(gDisplayListHead++, G_RM_PASS, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, SHADE, ENV_ALPHA, SHADE, 1, TEXEL0, ENVIRONMENT, TEXEL0, 0,
                          0, 0, COMBINED, COMBINED, 0, SHADE, 0);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);

        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

        gDPLoadTextureBlock(gDisplayListHead++, D_3000000, G_IM_FMT_I, G_IM_SIZ_8b, 64, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                            G_TX_MIRROR | G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (u32)vertex & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    }
}

void AreaSelect_AdvanceMagnemiteTrail(void) {
    s32 i;
    s32 j;
    s16 temp_fv0;
    s16 var_v0 = sAreaSelectMagnemiteTrails[0].unk_08;

    for (i = 0; i < 3; i++) {
        for (j = 4; j >= 0; j--) {
            sAreaSelectMagnemiteTrails[i].unk_0C[j + 1] = sAreaSelectMagnemiteTrails[i].unk_0C[j];
        }

        temp_fv0 = (sAreaSelectMagnemiteTrails[0].unk_06 * sAreaSelectMagnemiteTrails[0].unk_04) / 100;

        sAreaSelectMagnemiteTrails[i].unk_0C[0].unk_00 = sAreaSelectMagnemiteTrails[0].unk_00 + (COSS((var_v0)) * temp_fv0);
        sAreaSelectMagnemiteTrails[i].unk_0C[0].unk_02 = sAreaSelectMagnemiteTrails[0].unk_02 + (SINS((var_v0)) * temp_fv0);
        sAreaSelectMagnemiteTrails[i].unk_0C[0].unk_04 = (sAreaSelectMagnemiteTrails[0].unk_06 * 0x48) / 100;

        var_v0 -= 0x5555;
    }
}

void AreaSelect_InitMagnemiteTrail(s32 arg0) {
    s32 i;

    sAreaSelectMagnemiteTrails[0].unk_00 = sAreaSelectEntryConfigs[arg0].unk_00;
    sAreaSelectMagnemiteTrails[0].unk_02 = sAreaSelectEntryConfigs[arg0].unk_02;
    sAreaSelectMagnemiteTrails[0].unk_04 = sAreaSelectEntryConfigs[arg0].unk_04;
    sAreaSelectMagnemiteTrails[0].unk_06 = 0x64;
    sAreaSelectMagnemiteTrails[0].unk_0A = 0;
    sAreaSelectMagnemiteTrails[0].unk_08 = 0;

    for (i = 0; i < 6; i++) {
        AreaSelect_AdvanceMagnemiteTrail();
        sAreaSelectMagnemiteTrails[0].unk_08 -= 0x800;
    }
}

Vtx* AreaSelect_BuildMagnemiteQuadVerts(s16 arg0, s16 arg1, s16 arg2, Color_RGBA8 arg3) {
    s16 sp44;
    Vtx* temp_v0;

    temp_v0 = Gfx_AllocDisplayList(sizeof(Vtx) * 8);
    if (temp_v0 != NULL) {
        sp44 = arg2 / 2;

        Gfx_SetVertexAttributes(&temp_v0[0], arg0 - sp44, arg1 - sp44, -1, 0, 0, arg3.r, arg3.g, arg3.b, arg3.a);
        Gfx_SetVertexAttributes(&temp_v0[1], arg0 - sp44, arg1 + sp44, -1, 0, 0x480, arg3.r, arg3.g, arg3.b, arg3.a);
        Gfx_SetVertexAttributes(&temp_v0[2], arg0 + sp44, arg1 + sp44, -1, 0x480, 0x480, arg3.r, arg3.g, arg3.b, arg3.a);
        Gfx_SetVertexAttributes(&temp_v0[3], arg0 + sp44, arg1 - sp44, -1, 0x480, 0, arg3.r, arg3.g, arg3.b, arg3.a);
    }

    return temp_v0;
}

void AreaSelect_DrawMagnemiteQuad(s16 arg0, s16 arg1, s16 arg2, u8* arg3, Color_RGBA8 arg4) {
    Vtx* temp_v0 = AreaSelect_BuildMagnemiteQuadVerts(arg0, arg1, arg2, arg4);

    if (temp_v0 != NULL) {
        gDPLoadTextureBlock(gDisplayListHead++, arg3, G_IM_FMT_RGBA, G_IM_SIZ_16b, 36, 36, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
    }
}

void AreaSelect_DrawMagnemiteTrail(u8* arg0) {
    Color_RGBA8 sp5C;
    s16 i;
    s16 j;
    s16 temp_s1;
    s16 temp_s3;
    s16 temp_s4;

    for (i = 5; i >= 0; i--) {
        for (j = 0; j < 3; j++) {
            temp_s1 = sAreaSelectMagnemiteTrails[j].unk_0C[i].unk_04;
            temp_s3 = sAreaSelectMagnemiteTrails[j].unk_0C[i].unk_00;
            temp_s4 = sAreaSelectMagnemiteTrails[j].unk_0C[i].unk_02;

            if (temp_s1 != 0) {
                if (i == 0) {
                    Color_SetRGBA(&sp5C, 0xFF, 0xFF, 0xFF, 0xFF);
                } else {
                    Color_SetRGBA(&sp5C, 0xFF, 0xFF, 0x64, 0xA0 - (i * 30));
                }
                AreaSelect_DrawMagnemiteQuad(temp_s3, temp_s4, temp_s1, arg0, sp5C);
            }
        }
    }
}

void AreaSelect_UpdateMagnemites(void) {
    if (sAreaSelectSelectedIndex != 8) {
        AreaSelect_AdvanceMagnemiteTrail();

        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

        AreaSelect_DrawMagnemiteTrail(sAreaSelectMagnemiteTextures[sAreaSelectMagnemiteTrails->unk_0A / 2]);

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);

        sAreaSelectMagnemiteTrails->unk_08 -= 0x800;
        sAreaSelectMagnemiteTrails->unk_0A = (sAreaSelectMagnemiteTrails->unk_0A + 2) % 8;
    }
}

void AreaSelect_DrawNameBanner(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 i;
    u8* var_s2;

    if (arg3 != 8) {
        if (arg3 == 7) {
            arg3 += sAreaSelectGameOptions.unk_00;
        }
        var_s2 = sAreaSelectNameBannerTextures[arg3];

        gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg2);

        for (i = 0; i < 16; i++) {
            Gfx_DrawTextureRgba16(arg0, arg1 + (i * 4), 0xC4, 4, var_s2 + (i * 0x620), 0xC4, 0);
        }

        if ((gSessionContext.unk_11F2 != 0) && ((arg3 == 0) || (arg3 == 2) || (arg3 == 3))) {
            Gfx_DrawTextureRgba16(arg0 - 0x20, arg1 + 0xD, 0x24, 0x24, D_20144E0, 0x24, 0);
        }

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
    }
}

void func_822014C0(void) {
}

void AreaSelect_DrawNameBannerCrossfade(s16 arg0, s16 arg1, s16 arg2) {
    static s16 areaSelectBannerScrollFrame = 1;
    static s16 areaSelectBannerScrollDirection = 1;

    s16 sp1E;

    if (arg0 == 2) {
        sp1E = (sAreaSelectTransitionFrame * 0x2A) + 3;
        AreaSelect_DrawNameBanner(arg1, (arg2 + (areaSelectBannerScrollFrame / 4)) - 5, 0xFF - sp1E, sAreaSelectPreviousIndex);
        AreaSelect_DrawNameBanner(arg1, (arg2 + (areaSelectBannerScrollFrame / 4)) - 5, sp1E, sAreaSelectSelectedIndex);
    } else if ((arg0 != 8) && (arg0 != 0)) {
        AreaSelect_DrawNameBanner(arg1, (arg2 + (areaSelectBannerScrollFrame / 4)) - 5, 0xFF, sAreaSelectSelectedIndex);
    }

    areaSelectBannerScrollFrame += areaSelectBannerScrollDirection;
    if (areaSelectBannerScrollFrame == 0) {
        areaSelectBannerScrollDirection = 1;
    }

    if (areaSelectBannerScrollFrame == 0x2B) {
        areaSelectBannerScrollDirection = -1;
    }
}

void AreaSelect_DrawPulsingMarker(s16 arg0, s16 arg1) {
    static u32 areaSelectMarkerTextures[] = {
        0x03044C60, 0x03045020, 0x030453E0, 0x030457A0, 0x03045B60, 0x03045F20, 0x030462E0,
        0x030466A0, 0x03046A60, 0x03046E20, 0x030471E0, 0x030475A0, 0x03047960, 0x03047D20,
        0x030480E0, 0x030484A0, 0x03048860, 0x030493A0, 0x03048FE0, 0x03048C20,
    };
    static s16 areaSelectMarkerFrame = 0;

    if (sAreaSelectModeSettings.unk_07 != 0) {
        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetEnvColor(gDisplayListHead++, 0, 100, 255, 255);

        if (gSessionContext.sessionFlags & 4) {
            gDPSetPrimColor(gDisplayListHead++, 0, 0xFF, 255, 255, 255, sAreaSelectBackgroundFadeAlpha);
        } else {
            gDPSetPrimColor(gDisplayListHead++, 0, 0xFF, 255, 255, 255, 255);
        }

        gDPLoadTextureBlock_4b(gDisplayListHead++, areaSelectMarkerTextures[areaSelectMarkerFrame], G_IM_FMT_I, 48, 40, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);

        Gfx_DrawTexturedRectClipped(arg0 - 0x28, arg1 - 0x28, 0x50, 0x50, 0, 0, 0x200, 0x200, 0);

        areaSelectMarkerFrame = (areaSelectMarkerFrame + 1) % 20;
    }
}

void AreaSelect_DrawGlowCircle(s16 arg0, s16 arg1, s16 arg2) {
    if ((sAreaSelectModeSettings.unk_07 == 0) || (arg2 <= 0)) {
        return;
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3044260, G_IM_FMT_I, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    if (1) {}

    Gfx_DrawTexturedRectClipped(arg0 - (arg2 / 2), arg1 - (arg2 / 2), arg2, arg2, 0, 0, 0x10000 / arg2, 0x10000 / arg2, 0);
}

void AreaSelect_DrawInfoPanel(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 sp54;
    s16 sp50;
    s16 var_s2;
    s16 var_s3;

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

    sp50 = arg2 - (var_s3 * 2);
    sp54 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A60, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028AA0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20289E0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A20, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3,
                  0x2000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, gUiTranslucentFillDL);

    if ((sp50 > 0) && (sp54 > 0)) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp50, var_s2, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0, arg1 + var_s3, arg2, sp54, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0 + var_s3, arg1 + var_s3 + sp54, sp50, var_s2, arg4, arg5, arg6, arg7);
    } else if (sp50 > 0) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp50, arg3, arg4, arg5, arg6, arg7);
    } else if (sp54 > 0) {
        Gfx_FillRectRgba(arg0, arg1 + var_s2, arg2, sp54, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void AreaSelect_DrawAreaInfoBox(s32 arg0) {
    AreaSelect_DrawInfoPanel(0x38, 0x17C, 0x210, 0x3C, 0x1E, 0x1E, 0x82, 0x96);

    if (arg0 != 0) {
        Font_BeginTranslucentTextRendering();
        Font_SetActive(8, 0);
        Font_SetLineHeight(0x18);
        Font_Printf(0x5B, 0x182, Text_GetString(NULL, 0, sAreaSelectStrings, sAreaSelectSelectedIndex));
        Font_EndTexturedTextRendering();
    }
}

void AreaSelect_PollInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

s32 AreaSelect_HandleInput(void) {
    s8 var_s0 = 8;
    s32 var_t1 = 1;

    sAreaSelectMagnemiteTrails->unk_00 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_00;
    sAreaSelectMagnemiteTrails->unk_02 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_02;
    sAreaSelectMagnemiteTrails->unk_04 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_04;
    sAreaSelectMagnemiteTrails->unk_06 = 0x64;

    sAreaSelectCursor.unk_00 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_00;
    sAreaSelectCursor.unk_02 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_02;
    sAreaSelectCursor.color = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_0A;
    sAreaSelectCursor.fadeProgress = 0;
    sAreaSelectCursor.unk_04 = 0x12C;

    if (gPlayer1Controller->buttonPressed & 0x8000) {
        if (sAreaSelectSelectedIndex == 3) {
            Cry_Play(0x96, 8);
        }
        Audio_PlaySoundEffectById(0x33);
        Audio_PlaySoundEffectById(0x16);
        var_t1 = 3;
    } else if (gPlayer1Controller->buttonPressed & 0x4000) {
        Audio_PlayMusicIfChangedImmediate(0x28);
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        var_t1 = 4;
    } else if (gPlayer1Controller->buttonPressed & 0x800) {
        var_s0 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_06;
    } else if (gPlayer1Controller->buttonPressed & 0x400) {
        var_s0 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_07;
    } else if (gPlayer1Controller->buttonPressed & 0x200) {
        var_s0 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_08;
    } else if (gPlayer1Controller->buttonPressed & 0x100) {
        var_s0 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_09;
    }

    if (var_s0 != 8) {
        Audio_PlaySoundEffectById(SFX_AREA_CURSOR);
        var_t1 = 2;
        sAreaSelectPreviousIndex = sAreaSelectSelectedIndex;
        sAreaSelectSelectedIndex = var_s0;
        sAreaSelectTransitionFrame = 0;
    }

    return var_t1;
}

s16 AreaSelect_CursorMoveAnim(void) {
    s32 var_v1;
    s32 v8_0;
    s32 v8_2;
    s32 v8_4;
    s32 vA_0;
    s32 vA_2;
    s32 vA_4;

    vA_0 = sAreaSelectEntryConfigs[sAreaSelectPreviousIndex].unk_00;
    vA_2 = sAreaSelectEntryConfigs[sAreaSelectPreviousIndex].unk_02;
    vA_4 = sAreaSelectEntryConfigs[sAreaSelectPreviousIndex].unk_04;
    v8_0 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_00;
    v8_2 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_02;
    v8_4 = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].unk_04;

    sAreaSelectTransitionFrame++;

    sAreaSelectMagnemiteTrails->unk_00 = (((v8_0 - vA_0) * sAreaSelectTransitionFrame) / 6) + vA_0;
    sAreaSelectMagnemiteTrails->unk_02 = (((v8_2 - vA_2) * sAreaSelectTransitionFrame) / 6) + vA_2;
    sAreaSelectMagnemiteTrails->unk_04 = (((v8_4 - vA_4) * sAreaSelectTransitionFrame) / 6) + vA_4;
    sAreaSelectMagnemiteTrails->unk_06 = 0x64;
    sAreaSelectMagnemiteTrails->unk_08 += 0x800;

    if (sAreaSelectTransitionFrame == 6) {
        var_v1 = 1;
    } else {
        var_v1 = 2;
    }

    return var_v1;
}

s32 AreaSelect_ConfirmSelection(void) {
    s32 var_v1 = 3;

    if (sAreaSelectMagnemiteTrails->unk_06 >= 0xB) {
        sAreaSelectMagnemiteTrails->unk_06 -= 5;
    } else {
        sAreaSelectMagnemiteTrails->unk_06 = 0;
        if (sAreaSelectSelectedIndex == 3) {
            Audio_StopMusic(0x20);
            var_v1 = 6;
        } else {
            if (sAreaSelectSelectedIndex != 7) {
                Audio_StopMusic(0x28);
            }
            var_v1 = 5;
        }
    }
    return var_v1;
}

s32 AreaSelect_FadeToBattle(void) {
    s16 var_a1 = 5;

    if (sAreaSelectCursor.color.a < 0xFA) {
        sAreaSelectCursor.color.a += 0x19;
    } else if (sAreaSelectCursor.fadeProgress < 0xFF) {
        sAreaSelectCursor.color.a = 0xFF;
        sAreaSelectCursor.fadeProgress += 0x19;
        if (sAreaSelectCursor.fadeProgress >= 0xFF) {
            sAreaSelectCursor.fadeProgress = 0xFF;
            StageContext_SetClearColor(1);
            StageFade_StartFromTransparent(1);
            var_a1 = 5;
        }
    } else {
        var_a1 = AreaSelect_CheckCartRemoved(7);
    }
    return var_a1;
}

s32 AreaSelect_MusicFadeWait(void) {
    s16 var_a1 = 6;

    if (sAreaSelectGlowRadius < 0x200) {
        sAreaSelectGlowRadius += 0x40;
    } else if (sAreaSelectGlowRadius == 0x200) {
        sAreaSelectGlowRadius += 0x40;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(2);
        var_a1 = 6;
    } else if (sAreaSelectGlowRadius < 0x280) {
        sAreaSelectGlowRadius += 0x40;
        if (sAreaSelectGlowRadius == 0x280) {
            var_a1 = 7;
        }
    }
    return var_a1;
}

s32 AreaSelect_WaitFragmentUnload(void) {
    s32 temp_v0 = StageContext_GetFadeMode();
    s16 var_v1 = 4;

    switch (temp_v0) {
        case 0:
            StageContext_SetClearColor(0xFFFF);
            StageFade_StartFromTransparent(0x10);
            var_v1 = 4;
            break;

        case 1:
            sAreaSelectSelectedIndex = 8;
            var_v1 = 7;
            break;
    }

    return var_v1;
}

void AreaSelect_SetupOrthoProjection(void) {
    guOrtho(&sAreaSelectProjectionMtx, 0.0f, 640.0f, 480.0f, 0.0f, -2.0f, 2.0f, 1.0f);
    Gfx_SetViewportDimensions(&sAreaSelectViewport, 0x280, 0x1E0);

    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPViewport(gDisplayListHead++, (u32)&sAreaSelectViewport & 0x1FFFFFFF);
    gSPMatrix(gDisplayListHead++, (u32)&sAreaSelectProjectionMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void AreaSelect_Draw(s16 arg0) {
    BgStage_DrawFrame();
    AreaSelect_SetupOrthoProjection();

    if (sAreaSelectBackgroundFadeAlpha == 0) {
        Gfx_DrawTiledRgba16Image(sAreaSelectCurrentBackground);
    } else if (sAreaSelectBackgroundFadeAlpha == 0xFF) {
        Gfx_DrawTiledRgba16Image(sAreaSelectNextBackground);
    } else {
        AreaSelect_DrawCrossfadeBackground(sAreaSelectCurrentBackground, sAreaSelectNextBackground, sAreaSelectBackgroundFadeAlpha);
    }

    AreaSelect_DrawPulsingMarker(0x12C, 0x41);
    AreaSelect_UpdateMagnemites();
    AreaSelect_DrawNameBannerCrossfade(arg0, 0x194, 0x28);
    AreaSelect_DrawGlowCircle(0x12C, 0x41, sAreaSelectGlowRadius);
    AreaSelect_DrawCursorGlow();

    if ((arg0 == 1) || (arg0 == 2)) {
        AreaSelect_DrawAreaInfoBox(arg0 == 1);
    }

    BgStage_AdvanceFrame();
}

s32 AreaSelect_FadeInFromBattle(void) {
    s16 var_v1 = 8;

    sAreaSelectSelectedIndex = 8;
    if (StageContext_GetFadeMode() == 0) {
        sAreaSelectBackgroundFadeAlpha += 4;
        if (sAreaSelectBackgroundFadeAlpha == 0x100) {
            gSessionContext.sessionFlags &= 0xFFFB;
            sAreaSelectBackgroundFadeAlpha = 0xFF;
            sAreaSelectPreviousIndex = 8;
            sAreaSelectSelectedIndex = 0;
            var_v1 = 2;
        }
    }
    return var_v1;
}

void AreaSelect_Intro(void) {
    AreaSelect_InitMagnemiteTrail(sAreaSelectSelectedIndex);
    Audio_PlayMusicIfChanged(0x50);
    StageFade_StartFromOpaque(0xA);

    while (StageContext_GetFadeMode() != 0) {
        AreaSelect_PollInput();
        AreaSelect_Draw(0);
    }
}

void AreaSelect_Loop(void) {
    s16 i;

    i = 2;
    if (gSessionContext.sessionFlags & 4) {
        Cry_Play(0x96, 7);
        i = 8;
    }

    if (sAreaSelectModeSettings.unk_07 == 0) {
        sAreaSelectEntryConfigs[0].unk_06 = 8;
        sAreaSelectEntryConfigs[2].unk_09 = 8;
        sAreaSelectEntryConfigs[7].unk_06 = 8;
    }

    sAreaSelectPreviousIndex = 8;
    sAreaSelectSelectedIndex = 0;

    while (i != 7) {
        AreaSelect_PollInput();

        switch (i) {
            case 1:
                i = AreaSelect_HandleInput();
                break;
            case 2:
                i = AreaSelect_CursorMoveAnim();
                break;

            case 3:
                i = AreaSelect_ConfirmSelection();
                break;

            case 4:
                i = AreaSelect_WaitFragmentUnload();
                break;

            case 5:
                i = AreaSelect_FadeToBattle();
                break;

            case 6:
                i = AreaSelect_MusicFadeWait();
                break;

            case 8:
                i = AreaSelect_FadeInFromBattle();
                break;
        }

        AreaSelect_Draw(i);
    }
}

void AreaSelect_LoadBackgroundArt(void) {
    sAreaSelectBackgroundArchive = ASSET_LOAD2(backgrounds, 1, 1);

    if (sAreaSelectGameOptions.unk_00 == 2) {
        if (gSessionContext.unk_11F2 == 0) {
            sAreaSelectCurrentBackground = BinArchive_GetFile(sAreaSelectBackgroundArchive, 1);
            sAreaSelectNextBackground = BinArchive_GetFile(sAreaSelectBackgroundArchive, 2);
        } else {
            sAreaSelectNextBackground = sAreaSelectCurrentBackground = BinArchive_GetFile(sAreaSelectBackgroundArchive, 2);
        }
    } else if (sAreaSelectGameOptions.unk_00 == 1) {
        sAreaSelectNextBackground = sAreaSelectCurrentBackground = BinArchive_GetFile(sAreaSelectBackgroundArchive, 0x13);
    } else {
        sAreaSelectNextBackground = sAreaSelectCurrentBackground = BinArchive_GetFile(sAreaSelectBackgroundArchive, 0x12);
    }
}

s32 AreaSelect_Main(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('LAND');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    Font_Init(0x1C, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, area_select_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);

    Text_InitStringTables();
    sAreaSelectStrings = Text_GetStringTable(0x17);
    Save_EnsureBankLoaded(2);
    Save_GetOptions(&sAreaSelectGameOptions);
    Save_GetModeSettings(&sAreaSelectModeSettings, gSessionContext.unk_11F2);
    AreaSelect_LoadBackgroundArt();
    sAreaSelectSelectedIndex = 8;

    if ((sAreaSelectModeSettings.unk_07 != 0) && !(gSessionContext.sessionFlags & 4) && !(sAreaSelectModeSettings.unk_00 & 0x100)) {
        sAreaSelectBackgroundFadeAlpha = 0xFF;
    }

    StageContext_Activate(sp24);
    AreaSelect_Intro();
    AreaSelect_Loop();
    StageContext_Deactivate();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('LAND');

    return sAreaSelectStateIds[sAreaSelectSelectedIndex];
}
