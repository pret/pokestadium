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
#include "variables.h"

typedef struct AreaSelectEntryConfig {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 orbitRadius;
    /* 0x06 */ s8 upArea;
    /* 0x07 */ s8 downArea;
    /* 0x08 */ s8 leftArea;
    /* 0x09 */ s8 rightArea;
    /* 0x0A */ Color_RGBA8 exitColor;
} AreaSelectEntryConfig; // size = 0xE

typedef struct AreaSelectMagnemitePoint {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 diameter;
} AreaSelectMagnemitePoint; // size = 0x6

typedef struct AreaSelectMagnemiteTrail {
    /* 0x00 */ s16 centerX;
    /* 0x02 */ s16 centerY;
    /* 0x04 */ s16 orbitRadius;
    /* 0x06 */ s16 scalePercent;
    /* 0x08 */ s16 orbitAngle;
    /* 0x0A */ s16 spriteFrame;
    // FAKE: matched declaration has four points, but the loops access six.
    // Preserve the 0x24 stride and overlapping accesses; this is not a layout repair.
    /* 0x0C */ AreaSelectMagnemitePoint afterimages[4];
} AreaSelectMagnemiteTrail; // size = 0x24

typedef struct AreaSelectExitFade {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 halfExtent;
    /* 0x06 */ s16 blackBlendAlpha;
    /* 0x08 */ Color_RGBA8 color;
} AreaSelectExitFade; // size >= 0xC

static s16 sAreaSelectBackgroundFadeAlpha = 0;

static s16 sAreaSelectGlowDiameter = 0;

static s16 sAreaSelectStateIds[] = {
    STATE_STADIUM_MENU,   STATE_FREE_BATTLE, STATE_GYM_LEADER_CASTLE, STATE_VS_MEWTWO,   STATE_KIDS_CLUB,
    STATE_VICTORY_PALACE, STATE_POKEMON_LAB, STATE_GB_TOWER,          STATE_MENU_SELECT,
};

static u8* sAreaSelectNameBannerTextures[] = {
    0x03006E60, 0x0300D060, 0x03013260, 0x03019460, 0x0301F660,
    0x03025860, 0x0302BA60, 0x03031C60, 0x03037E60, 0x0303E060,
};

#define AREA_STADIUM 0
#define AREA_FREE_BATTLE 1
#define AREA_GYM_LEADER_CASTLE 2
#define AREA_VS_MEWTWO 3
#define AREA_MINIGAMES 4
#define AREA_HALL_OF_FAME 5
#define AREA_OAKS_LAB 6
#define AREA_GB_TOWER 7
#define AREA_NONE 8

// Menu-loop states, not area indices. In particular, state 2 crossfades banners.
#define AREA_SELECT_INTRO 0
#define AREA_SELECT_INPUT 1
#define AREA_SELECT_MOVE 2
#define AREA_SELECT_SHRINK 3
#define AREA_SELECT_CANCEL 4
#define AREA_SELECT_EXIT_FADE 5
#define AREA_SELECT_MEWTWO_EXIT 6
#define AREA_SELECT_DONE 7
#define AREA_SELECT_REVEAL_MEWTWO 8

static AreaSelectEntryConfig sAreaSelectEntryConfigs[9] = {
    // Stadium
    { 300, 185, 75, AREA_VS_MEWTWO, AREA_MINIGAMES, AREA_OAKS_LAB, AREA_GB_TOWER, { 50, 80, 150, 0 } },
    // Free Battle
    { 520, 280, 75, AREA_GB_TOWER, AREA_NONE, AREA_MINIGAMES, AREA_NONE, { 50, 80, 150, 0 } },
    // Gym Leader Castle
    { 110, 90, 65, AREA_NONE, AREA_OAKS_LAB, AREA_NONE, AREA_VS_MEWTWO, { 50, 80, 150, 0 } },
    // VS Mewtwo
    { 300, 65, 65, AREA_NONE, AREA_STADIUM, AREA_GYM_LEADER_CASTLE, AREA_GB_TOWER, { 50, 80, 150, 0 } },
    // Minigames
    { 350, 315, 80, AREA_STADIUM, AREA_NONE, AREA_HALL_OF_FAME, AREA_FREE_BATTLE, { 50, 80, 150, 0 } },
    // Hall of Fame
    { 190, 330, 70, AREA_OAKS_LAB, AREA_NONE, AREA_NONE, AREA_MINIGAMES, { 50, 80, 150, 0 } },
    // Professor Oak's Lab
    { 120, 230, 65, AREA_GYM_LEADER_CASTLE, AREA_HALL_OF_FAME, AREA_NONE, AREA_STADIUM, { 50, 80, 150, 0 } },
    // GB Tower
    { 510, 150, 65, AREA_VS_MEWTWO, AREA_FREE_BATTLE, AREA_STADIUM, AREA_NONE, { 50, 80, 150, 0 } },
    // No selectable area: initial cursor position, blocked neighbor, and B-button exit.
    { 300, 185, 10, AREA_NONE, AREA_NONE, AREA_NONE, AREA_NONE, { 50, 80, 150, 0 } },
};

static u8* sAreaSelectMagnemiteTextures[] = { 0x03005000, 0x03005A20, 0x03006440, 0x03005A20 };

static char** sAreaSelectStrings;
static BinArchive* sAreaSelectBackgroundArchive;
static Vp sAreaSelectViewport;
static Mtx sAreaSelectProjectionMtx;
static u8* sAreaSelectCurrentBackground;
static u8* sAreaSelectNextBackground;
static AreaSelectExitFade sAreaSelectExitFade;
static AreaSelectMagnemiteTrail sAreaSelectMagnemiteTrails[3];
static s32 pad_D_822031D0[0x2];
static s16 sAreaSelectSelectedIndex;
static s16 sAreaSelectPreviousIndex;
static s16 sAreaSelectTransitionFrame;
static ModeSettings sAreaSelectModeSettings;
static GameOptions sAreaSelectGameOptions;

s32 AreaSelect_CheckCartRemoved(s32 next_state) {
    u32 saved_interrupt_mask = osSetIntMask(OS_IM_NONE);

    // Preserve the retail cartridge-signature guard. The predicate alone does
    // not establish that physical cartridge removal is its only trigger.
    if (!(HW_REG(PI_STATUS_REG, u32) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) &&
        ((*(u32*)0xB0000D10 & 0xFFFF) != 0x400)) {
        next_state = -0x40;
    }

    osSetIntMask(saved_interrupt_mask);
    return next_state;
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

    for (i = 0; i < 480; i += 0x20) {
        for (j = 0; j < 640; j += 0x20) {
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

// Build the inner colored quad and outer surround for the selected area's exit fade.
Vtx* AreaSelect_BuildExitFadeVertices(void) {
    Vtx* vertex;
    s16 half_extent;
    s16 x;
    s16 y;
    u8 r;
    u8 g;
    u8 b;
    u8 alpha;

    x = sAreaSelectExitFade.x;
    y = sAreaSelectExitFade.y;
    half_extent = sAreaSelectExitFade.halfExtent;
    r = sAreaSelectExitFade.color.r;
    g = sAreaSelectExitFade.color.g;
    b = sAreaSelectExitFade.color.b;
    alpha = sAreaSelectExitFade.color.a;

    vertex = Gfx_AllocDisplayList(sizeof(Vtx) * 8);

    if (vertex != NULL) {
        Gfx_SetVertexAttributes(&vertex[0], x - half_extent, y - half_extent, -1, 0, 0, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[1], x - half_extent, y + half_extent, -1, 0, 2016, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[2], x + half_extent, y + half_extent, -1, 2016, 2016, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[3], x + half_extent, y - half_extent, -1, 2016, 0, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[4], x - 2000, y - 2000, -1, 0, 0, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[5], x - 2000, y + 2000, -1, 0, 0, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[6], x + 2000, y + 2000, -1, 0, 0, r, g, b, alpha);
        Gfx_SetVertexAttributes(&vertex[7], x + 2000, y - 2000, -1, 0, 0, r, g, b, alpha);
    }

    return vertex;
}

// Fade the surround to the area's color, then blend that color toward black.
void AreaSelect_DrawExitFade(void) {
    Vtx* vertex;

    // Hidden until the selected-area exit animation raises the color alpha.
    if (sAreaSelectExitFade.color.a <= 0) {
        return;
    }

    vertex = AreaSelect_BuildExitFadeVertices();

    if (vertex != 0) {
        gDPPipeSync(gDisplayListHead++);

        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, sAreaSelectExitFade.blackBlendAlpha);
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

        gSPTexture(gDisplayListHead++, 65535, 65535, 0, G_TX_RENDERTILE, G_ON);

        // The first 64x32 I8 texture in the currently loaded area_select_ui segment.
        gDPLoadTextureBlock(gDisplayListHead++, D_3000000, G_IM_FMT_I, G_IM_SIZ_8b, 64, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                            G_TX_MIRROR | G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (u32)vertex & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
        gSPTexture(gDisplayListHead++, 65535, 65535, 0, G_TX_RENDERTILE, G_OFF);
    }
}

/*
    Loops the Magnemite icons around in a circle
*/
void AreaSelect_AdvanceMagnemiteTrail(void) {
    s32 trail_index;
    s32 history_index;
    s16 scaled_radius;
    s16 orbit_angle = sAreaSelectMagnemiteTrails[0].orbitAngle;

    for (trail_index = 0; trail_index < 3; trail_index++) {
        for (history_index = 4; history_index >= 0; history_index--) {
            sAreaSelectMagnemiteTrails[trail_index].afterimages[history_index + 1] = sAreaSelectMagnemiteTrails[trail_index].afterimages[history_index];
        }

        scaled_radius = (sAreaSelectMagnemiteTrails[0].scalePercent * sAreaSelectMagnemiteTrails[0].orbitRadius) / 100;

        sAreaSelectMagnemiteTrails[trail_index].afterimages[0].x = sAreaSelectMagnemiteTrails[0].centerX + (COSS((orbit_angle)) * scaled_radius);
        sAreaSelectMagnemiteTrails[trail_index].afterimages[0].y = sAreaSelectMagnemiteTrails[0].centerY + (SINS((orbit_angle)) * scaled_radius);
        sAreaSelectMagnemiteTrails[trail_index].afterimages[0].diameter = (sAreaSelectMagnemiteTrails[0].scalePercent * 72) / 100;

        orbit_angle -= 21845;
    }
}

void AreaSelect_InitMagnemiteTrail(s32 area) {
    s32 i;

    sAreaSelectMagnemiteTrails[0].centerX = sAreaSelectEntryConfigs[area].x;
    sAreaSelectMagnemiteTrails[0].centerY = sAreaSelectEntryConfigs[area].y;
    sAreaSelectMagnemiteTrails[0].orbitRadius = sAreaSelectEntryConfigs[area].orbitRadius;
    sAreaSelectMagnemiteTrails[0].scalePercent = 100;
    sAreaSelectMagnemiteTrails[0].spriteFrame = 0;
    sAreaSelectMagnemiteTrails[0].orbitAngle = 0;

    for (i = 0; i < 6; i++) {
        AreaSelect_AdvanceMagnemiteTrail();
        sAreaSelectMagnemiteTrails[0].orbitAngle -= 0x800;
    }
}

Vtx* AreaSelect_BuildMagnemiteQuadVerts(s16 x, s16 y, s16 diameter, Color_RGBA8 color) {
    s16 half_extent;
    Vtx* vertices;

    vertices = Gfx_AllocDisplayList(sizeof(Vtx) * 8);
    if (vertices != NULL) {
        half_extent = diameter / 2;

        Gfx_SetVertexAttributes(&vertices[0], x - half_extent, y - half_extent, -1, 0, 0, color.r, color.g, color.b, color.a);
        Gfx_SetVertexAttributes(&vertices[1], x - half_extent, y + half_extent, -1, 0, 1152, color.r, color.g, color.b, color.a);
        Gfx_SetVertexAttributes(&vertices[2], x + half_extent, y + half_extent, -1, 1152, 1152, color.r, color.g, color.b, color.a);
        Gfx_SetVertexAttributes(&vertices[3], x + half_extent, y - half_extent, -1, 1152, 0, color.r, color.g, color.b, color.a);
    }

    return vertices;
}

void AreaSelect_DrawMagnemiteQuad(s16 x, s16 y, s16 diameter, u8* sprite, Color_RGBA8 color) {
    Vtx* vertices = AreaSelect_BuildMagnemiteQuadVerts(x, y, diameter, color);

    if (vertices != NULL) {
        gDPLoadTextureBlock(gDisplayListHead++, sprite, G_IM_FMT_RGBA, G_IM_SIZ_16b, 36, 36, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (u32)vertices & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
    }
}

void AreaSelect_DrawMagnemiteTrail(u8* sprite) {
    Color_RGBA8 color;
    s16 history_index;
    s16 trail_index;
    s16 diameter;
    s16 x;
    s16 y;

    for (history_index = 5; history_index >= 0; history_index--) {
        for (trail_index = 0; trail_index < 3; trail_index++) {
            diameter = sAreaSelectMagnemiteTrails[trail_index].afterimages[history_index].diameter;
            x = sAreaSelectMagnemiteTrails[trail_index].afterimages[history_index].x;
            y = sAreaSelectMagnemiteTrails[trail_index].afterimages[history_index].y;

            if (diameter != 0) {
                if (history_index == 0) {
                    Color_SetRGBA(&color, 255, 255, 255, 255);
                } else {
                    Color_SetRGBA(&color, 255, 255, 100, 160 - (history_index * 30));
                }
                AreaSelect_DrawMagnemiteQuad(x, y, diameter, sprite, color);
            }
        }
    }
}

void AreaSelect_DrawAndAdvanceMagnemites(void) {
    if (sAreaSelectSelectedIndex != AREA_NONE) {
        AreaSelect_AdvanceMagnemiteTrail();

        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
        gSPTexture(gDisplayListHead++, 65535, 65535, 0, G_TX_RENDERTILE, G_ON);

        AreaSelect_DrawMagnemiteTrail(sAreaSelectMagnemiteTextures[sAreaSelectMagnemiteTrails->spriteFrame / 2]);

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
        gSPTexture(gDisplayListHead++, 65535, 65535, 0, G_TX_RENDERTILE, G_OFF);

        sAreaSelectMagnemiteTrails->orbitAngle -= 0x800;
        sAreaSelectMagnemiteTrails->spriteFrame = (sAreaSelectMagnemiteTrails->spriteFrame + 2) % 8;
    }
}

void AreaSelect_DrawNameBanner(s16 x, s16 y, s16 alpha, s16 area) {
    s32 i;
    u8* area_name_banner_texture;

    if (area != AREA_NONE) {
        if (area == AREA_GB_TOWER) {
            area += sAreaSelectGameOptions.gbTowerUnlockTier;
        }
        area_name_banner_texture = sAreaSelectNameBannerTextures[area];

        gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, alpha);

        for (i = 0; i < 16; i++) {
            Gfx_DrawTextureRgba16(x, y + (i * 4), 196, 4, area_name_banner_texture + (i * 1568), 196, 0);
        }

        if ((gSessionContext.inRound2 != 0) && ((area == AREA_STADIUM) || (area == AREA_GYM_LEADER_CASTLE) || (area == AREA_VS_MEWTWO))) {
            Gfx_DrawTextureRgba16(x - 32, y + 13, 36, 36, gRound2BadgeTexture, 36, 0);
        }

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
    }
}

void func_822014C0(void) {
    // Empty retail function. Its original purpose is unknown; retain the address name.
}

// State 2 interpolates the old/new labels during the six-frame cursor move.
// Independently, the static offset makes all visible labels bob vertically.
void AreaSelect_DrawNameBannerCrossfade(s16 menu_state, s16 x, s16 y) {
    static s16 sAreaSelectBannerBobOffset = 1;
    static s16 sAreaSelectBannerBobDirection = 1;

    s16 crossfade_alpha;

    if (menu_state == AREA_SELECT_MOVE) {
        crossfade_alpha = (sAreaSelectTransitionFrame * 42) + 3;
        AreaSelect_DrawNameBanner(x, (y + (sAreaSelectBannerBobOffset / 4)) - 5, 255 - crossfade_alpha, sAreaSelectPreviousIndex);
        AreaSelect_DrawNameBanner(x, (y + (sAreaSelectBannerBobOffset / 4)) - 5, crossfade_alpha, sAreaSelectSelectedIndex);
    } else if ((menu_state != AREA_SELECT_REVEAL_MEWTWO) && (menu_state != AREA_SELECT_INTRO)) {
        AreaSelect_DrawNameBanner(x, (y + (sAreaSelectBannerBobOffset / 4)) - 5, 255, sAreaSelectSelectedIndex);
    }

    sAreaSelectBannerBobOffset += sAreaSelectBannerBobDirection;
    if (sAreaSelectBannerBobOffset == 0) {
        sAreaSelectBannerBobDirection = 1;
    }

    if (sAreaSelectBannerBobOffset == 43) {
        sAreaSelectBannerBobDirection = -1;
    }
}

// Animate the marker at Mewtwo's location when that battle has been unlocked.
void AreaSelect_DrawMewtwoMarker(s16 x, s16 y) {
    static u32 sAreaSelectMarkerTextures[] = {
        0x03044C60, 0x03045020, 0x030453E0, 0x030457A0, 0x03045B60, 0x03045F20, 0x030462E0,
        0x030466A0, 0x03046A60, 0x03046E20, 0x030471E0, 0x030475A0, 0x03047960, 0x03047D20,
        0x030480E0, 0x030484A0, 0x03048860, 0x030493A0, 0x03048FE0, 0x03048C20,
    };
    static s16 sAreaSelectMarkerFrame = 0;

    if (sAreaSelectModeSettings.mewtwoUnlocked != 0) {
        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetEnvColor(gDisplayListHead++, 0, 100, 255, 255);

        if (gSessionContext.sessionFlags & SESSION_FLAG_REVEAL_MEWTWO) {
            gDPSetPrimColor(gDisplayListHead++, 0, 255, 255, 255, 255, sAreaSelectBackgroundFadeAlpha);
        } else {
            gDPSetPrimColor(gDisplayListHead++, 0, 255, 255, 255, 255, 255);
        }

        gDPLoadTextureBlock_4b(gDisplayListHead++, sAreaSelectMarkerTextures[sAreaSelectMarkerFrame], G_IM_FMT_I, 48, 40, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);

        Gfx_DrawTexturedRectClipped(x - 40, y - 40, 80, 80, 0, 0, 0x200, 0x200, 0);

        sAreaSelectMarkerFrame = (sAreaSelectMarkerFrame + 1) % 20;
    }
}

void AreaSelect_DrawGlowCircle(s16 x, s16 y, s16 diameter) {
    if ((sAreaSelectModeSettings.mewtwoUnlocked == 0) || (diameter <= 0)) {
        return;
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPLoadTextureBlock_4b(gDisplayListHead++, sAreaSelectGlowCircleTexture, G_IM_FMT_I, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    if (1) {} // karodo

    Gfx_DrawTexturedRectClipped(x - (diameter / 2), y - (diameter / 2), diameter, diameter, 0, 0, 0x10000 / diameter, 0x10000 / diameter, 0);
}

void AreaSelect_DrawInfoPanel(s16 x, s16 y, s16 width, s16 height, u8 r, u8 g, u8 b, u8 alpha) {
    s16 inner_height;
    s16 inner_width;
    s16 corner_height;
    s16 corner_width;

    if (width >= 16) {
        corner_width = 8;
    } else {
        corner_width = width / 2;
    }

    if (height >= 16) {
        corner_height = 8;
    } else {
        corner_height = height / 2;
    }

    inner_width = width - (corner_width * 2);
    inner_height = height - (corner_height * 2);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, r, g, b, alpha);
    gDPLoadTextureBlock_4b(gDisplayListHead++, gUiPanelTopLeftTexture, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(x, y, corner_width, corner_height, 0, 0, 0x2000 / corner_width, 0x2000 / corner_height, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, gUiPanelTopRightTexture, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((x + width) - corner_width, y, corner_width, corner_height, 0, 0, 0x2000 / corner_width, 0x2000 / corner_height, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, gUiPanelBottomLeftTexture, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(x, (y + height) - corner_height, corner_width, corner_height, 0, 0, 0x2000 / corner_width, 0x2000 / corner_height, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, gUiPanelBottomRightTexture, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((x + width) - corner_width, (y + height) - corner_height, corner_width, corner_height, 0, 0, 0x2000 / corner_width,
                  0x2000 / corner_height, 0);

    gSPDisplayList(gDisplayListHead++, gUiTranslucentFillDL);

    if ((inner_width > 0) && (inner_height > 0)) {
        Gfx_FillRectRgba(x + corner_width, y, inner_width, corner_height, r, g, b, alpha);
        Gfx_FillRectRgba(x, y + corner_width, width, inner_height, r, g, b, alpha);
        Gfx_FillRectRgba(x + corner_width, y + corner_width + inner_height, inner_width, corner_height, r, g, b, alpha);
    } else if (inner_width > 0) {
        Gfx_FillRectRgba(x + corner_width, y, inner_width, height, r, g, b, alpha);
    } else if (inner_height > 0) {
        Gfx_FillRectRgba(x, y + corner_height, width, inner_height, r, g, b, alpha);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void AreaSelect_DrawAreaInfoBox(s32 draw_text) {
    AreaSelect_DrawInfoPanel(56, 380, 528, 60, 30, 30, 130, 150);

    if (draw_text != 0) {
        Font_BeginTranslucentTextRendering();
        Font_SetActive(8, 0);
        Font_SetLineHeight(24);
        Font_Printf(91, 386, Text_GetString(NULL, 0, sAreaSelectStrings, sAreaSelectSelectedIndex));
        Font_EndTexturedTextRendering();
    }
}

void AreaSelect_PollInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

s32 AreaSelect_HandleInput(void) {
    s8 next_area = AREA_NONE;
    s32 next_state = AREA_SELECT_INPUT;

    sAreaSelectMagnemiteTrails->centerX = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].x;
    sAreaSelectMagnemiteTrails->centerY = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].y;
    sAreaSelectMagnemiteTrails->orbitRadius = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].orbitRadius;
    sAreaSelectMagnemiteTrails->scalePercent = 100;

    sAreaSelectExitFade.x = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].x;
    sAreaSelectExitFade.y = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].y;
    sAreaSelectExitFade.color = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].exitColor;
    sAreaSelectExitFade.blackBlendAlpha = 0;
    sAreaSelectExitFade.halfExtent = 300;

    if (gPlayer1Controller->buttonPressed & BTN_A) {
        if (sAreaSelectSelectedIndex == AREA_VS_MEWTWO) {
            Cry_Play(150, 8);
        }
        Audio_PlaySoundEffectById(51);
        Audio_PlaySoundEffectById(22);
        next_state = AREA_SELECT_SHRINK;
    } else if (gPlayer1Controller->buttonPressed & BTN_B) {
        Audio_PlayMusicIfChangedImmediate(40);
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        next_state = AREA_SELECT_CANCEL;
    } else if (gPlayer1Controller->buttonPressed & BTN_DUP) {
        next_area = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].upArea;
    } else if (gPlayer1Controller->buttonPressed & BTN_DDOWN) {
        next_area = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].downArea;
    } else if (gPlayer1Controller->buttonPressed & BTN_DLEFT) {
        next_area = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].leftArea;
    } else if (gPlayer1Controller->buttonPressed & BTN_DRIGHT) {
        next_area = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].rightArea;
    }

    if (next_area != AREA_NONE) {
        Audio_PlaySoundEffectById(SFX_AREA_CURSOR);
        next_state = AREA_SELECT_MOVE;
        sAreaSelectPreviousIndex = sAreaSelectSelectedIndex;
        sAreaSelectSelectedIndex = next_area;
        sAreaSelectTransitionFrame = 0;
    }

    return next_state;
}

s16 AreaSelect_UpdateCursorMove(void) {
    s32 next_state;
    s32 selected_x;
    s32 selected_y;
    s32 selected_radius;
    s32 previous_x;
    s32 previous_y;
    s32 previous_radius;

    previous_x = sAreaSelectEntryConfigs[sAreaSelectPreviousIndex].x;
    previous_y = sAreaSelectEntryConfigs[sAreaSelectPreviousIndex].y;
    previous_radius = sAreaSelectEntryConfigs[sAreaSelectPreviousIndex].orbitRadius;
    selected_x = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].x;
    selected_y = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].y;
    selected_radius = sAreaSelectEntryConfigs[sAreaSelectSelectedIndex].orbitRadius;

    sAreaSelectTransitionFrame++;

    sAreaSelectMagnemiteTrails->centerX = (((selected_x - previous_x) * sAreaSelectTransitionFrame) / 6) + previous_x;
    sAreaSelectMagnemiteTrails->centerY = (((selected_y - previous_y) * sAreaSelectTransitionFrame) / 6) + previous_y;
    sAreaSelectMagnemiteTrails->orbitRadius = (((selected_radius - previous_radius) * sAreaSelectTransitionFrame) / 6) + previous_radius;
    sAreaSelectMagnemiteTrails->scalePercent = 100;
    sAreaSelectMagnemiteTrails->orbitAngle += 0x800;

    if (sAreaSelectTransitionFrame == 6) {
        next_state = AREA_SELECT_INPUT;
    } else {
        next_state = AREA_SELECT_MOVE;
    }

    return next_state;
}

s32 AreaSelect_ShrinkMagnemites(void) {
    s32 next_state = AREA_SELECT_SHRINK;

    if (sAreaSelectMagnemiteTrails->scalePercent >= 11) {
        sAreaSelectMagnemiteTrails->scalePercent -= 5;
    } else {
        sAreaSelectMagnemiteTrails->scalePercent = 0;
        if (sAreaSelectSelectedIndex == AREA_VS_MEWTWO) {
            Audio_StopMusic(0x20);
            next_state = AREA_SELECT_MEWTWO_EXIT;
        } else {
            if (sAreaSelectSelectedIndex != AREA_GB_TOWER) {
                Audio_StopMusic(40);
            }
            next_state = AREA_SELECT_EXIT_FADE;
        }
    }
    return next_state;
}

s32 AreaSelect_UpdateExitFade(void) {
    s16 next_state = AREA_SELECT_EXIT_FADE;

    if (sAreaSelectExitFade.color.a < 250) {
        sAreaSelectExitFade.color.a += 25;
    } else if (sAreaSelectExitFade.blackBlendAlpha < 255) {
        sAreaSelectExitFade.color.a = 255;
        sAreaSelectExitFade.blackBlendAlpha += 25;
        if (sAreaSelectExitFade.blackBlendAlpha >= 255) {
            sAreaSelectExitFade.blackBlendAlpha = 255;
            StageContext_SetClearColor(1);
            StageFade_StartFromTransparent(1);
            next_state = AREA_SELECT_EXIT_FADE;
        }
    } else {
        next_state = AreaSelect_CheckCartRemoved(AREA_SELECT_DONE);
    }
    return next_state;
}

s32 AreaSelect_UpdateMewtwoExit(void) {
    s16 next_state = AREA_SELECT_MEWTWO_EXIT;

    if (sAreaSelectGlowDiameter < 0x200) {
        sAreaSelectGlowDiameter += 0x40;
    } else if (sAreaSelectGlowDiameter == 0x200) {
        sAreaSelectGlowDiameter += 0x40;
        StageContext_SetClearColor(65535);
        StageFade_StartFromTransparent(2);
        next_state = AREA_SELECT_MEWTWO_EXIT;
    } else if (sAreaSelectGlowDiameter < 640) {
        sAreaSelectGlowDiameter += 0x40;
        if (sAreaSelectGlowDiameter == 640) {
            next_state = AREA_SELECT_DONE;
        }
    }
    return next_state;
}

s32 AreaSelect_UpdateCancelFade(void) {
    s32 fade_mode = StageContext_GetFadeMode();
    s16 next_state = AREA_SELECT_CANCEL;

    switch (fade_mode) {
        case 0:
            StageContext_SetClearColor(65535);
            StageFade_StartFromTransparent(0x10);
            next_state = AREA_SELECT_CANCEL;
            break;

        case 1:
            sAreaSelectSelectedIndex = AREA_NONE;
            next_state = AREA_SELECT_DONE;
            break;
    }

    return next_state;
}

void AreaSelect_SetupOrthoProjection(void) {
    guOrtho(&sAreaSelectProjectionMtx, 0.0f, 640.0f, 480.0f, 0.0f, -2.0f, 2.0f, 1.0f);
    Gfx_SetViewportDimensions(&sAreaSelectViewport, 640, 480);

    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gSPPerspNormalize(gDisplayListHead++, 65535);
    gSPViewport(gDisplayListHead++, (u32)&sAreaSelectViewport & 0x1FFFFFFF);
    gSPMatrix(gDisplayListHead++, (u32)&sAreaSelectProjectionMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&gIdentityMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void AreaSelect_Draw(s16 menu_state) {
    BgStage_DrawFrame();
    AreaSelect_SetupOrthoProjection();

    if (sAreaSelectBackgroundFadeAlpha == 0) {
        Gfx_DrawTiledRgba16Image(sAreaSelectCurrentBackground);
    } else if (sAreaSelectBackgroundFadeAlpha == 255) {
        Gfx_DrawTiledRgba16Image(sAreaSelectNextBackground);
    } else {
        AreaSelect_DrawCrossfadeBackground(sAreaSelectCurrentBackground, sAreaSelectNextBackground, sAreaSelectBackgroundFadeAlpha);
    }

    AreaSelect_DrawMewtwoMarker(300, 65);
    AreaSelect_DrawAndAdvanceMagnemites();
    AreaSelect_DrawNameBannerCrossfade(menu_state, 404, 40);
    AreaSelect_DrawGlowCircle(300, 65, sAreaSelectGlowDiameter);
    AreaSelect_DrawExitFade();

    if ((menu_state == AREA_SELECT_INPUT) || (menu_state == AREA_SELECT_MOVE)) {
        AreaSelect_DrawAreaInfoBox(menu_state == AREA_SELECT_INPUT);
    }

    BgStage_AdvanceFrame();
}

s32 AreaSelect_RevealMewtwo(void) {
    s16 next_state = AREA_SELECT_REVEAL_MEWTWO;

    sAreaSelectSelectedIndex = AREA_NONE;
    if (StageContext_GetFadeMode() == 0) {
        sAreaSelectBackgroundFadeAlpha += 4;
        if (sAreaSelectBackgroundFadeAlpha == 0x100) {
            gSessionContext.sessionFlags &= (0xFFFF ^ SESSION_FLAG_REVEAL_MEWTWO);
            sAreaSelectBackgroundFadeAlpha = 255;
            sAreaSelectPreviousIndex = AREA_NONE;
            sAreaSelectSelectedIndex = AREA_STADIUM;
            next_state = AREA_SELECT_MOVE;
        }
    }
    return next_state;
}

void AreaSelect_Intro(void) {
    AreaSelect_InitMagnemiteTrail(sAreaSelectSelectedIndex);
    Audio_PlayMusicIfChanged(80);
    StageFade_StartFromOpaque(10);

    while (StageContext_GetFadeMode() != 0) {
        AreaSelect_PollInput();
        AreaSelect_Draw(AREA_SELECT_INTRO);
    }
}

/*
    Handles dispatch on selecting an area
*/
void AreaSelect_Loop(void) {
    s16 menu_state;

    menu_state = AREA_SELECT_MOVE;
    if (gSessionContext.sessionFlags & SESSION_FLAG_REVEAL_MEWTWO) {
        Cry_Play(150, 7);
        menu_state = AREA_SELECT_REVEAL_MEWTWO;
    }

    if (sAreaSelectModeSettings.mewtwoUnlocked == 0) {
        sAreaSelectEntryConfigs[AREA_STADIUM].upArea = AREA_NONE;
        sAreaSelectEntryConfigs[AREA_GYM_LEADER_CASTLE].rightArea = AREA_NONE;
        sAreaSelectEntryConfigs[AREA_GB_TOWER].upArea = AREA_NONE;
    }

    sAreaSelectPreviousIndex = AREA_NONE;
    sAreaSelectSelectedIndex = AREA_STADIUM;

    while (menu_state != AREA_SELECT_DONE) {
        AreaSelect_PollInput();

        switch (menu_state) {
            case AREA_SELECT_INPUT:
                menu_state = AreaSelect_HandleInput();
                break;
            case AREA_SELECT_MOVE:
                menu_state = AreaSelect_UpdateCursorMove();
                break;

            case AREA_SELECT_SHRINK:
                menu_state = AreaSelect_ShrinkMagnemites();
                break;

            case AREA_SELECT_CANCEL:
                menu_state = AreaSelect_UpdateCancelFade();
                break;

            case AREA_SELECT_EXIT_FADE:
                menu_state = AreaSelect_UpdateExitFade();
                break;

            case AREA_SELECT_MEWTWO_EXIT:
                menu_state = AreaSelect_UpdateMewtwoExit();
                break;

            case AREA_SELECT_REVEAL_MEWTWO:
                menu_state = AreaSelect_RevealMewtwo();
                break;
        }

        AreaSelect_Draw(menu_state);
    }
}

// Archive entries combine island lighting with the unlocked Tower tier.
// Round 1 also uses the night entry for the Mewtwo-unlock reveal.
#define AREA_BACKGROUND_NIGHT_DODRIO 2
#define AREA_BACKGROUND_DAY_DODRIO 1
#define AREA_BACKGROUND_DAY_DODUO 19
#define AREA_BACKGROUND_DAY_NORMAL 18
void AreaSelect_LoadBackgroundArt(void) {
    sAreaSelectBackgroundArchive = ASSET_LOAD2(backgrounds, 1, 1);

    if (sAreaSelectGameOptions.gbTowerUnlockTier == 2) {
        if (gSessionContext.inRound2 == 0) {
            sAreaSelectCurrentBackground = BinArchive_GetFile(sAreaSelectBackgroundArchive, AREA_BACKGROUND_DAY_DODRIO);
            sAreaSelectNextBackground = BinArchive_GetFile(sAreaSelectBackgroundArchive, AREA_BACKGROUND_NIGHT_DODRIO);
        } else {
            sAreaSelectNextBackground = sAreaSelectCurrentBackground = BinArchive_GetFile(sAreaSelectBackgroundArchive, AREA_BACKGROUND_NIGHT_DODRIO);
        }
    } else if (sAreaSelectGameOptions.gbTowerUnlockTier == 1) {
        sAreaSelectNextBackground = sAreaSelectCurrentBackground = BinArchive_GetFile(sAreaSelectBackgroundArchive, AREA_BACKGROUND_DAY_DODUO);
    } else {
        sAreaSelectNextBackground = sAreaSelectCurrentBackground = BinArchive_GetFile(sAreaSelectBackgroundArchive, AREA_BACKGROUND_DAY_NORMAL);
    }
}

s32 AreaSelect_Main(UNUSED s32 arg0, UNUSED s32 arg1) {
    StageContext* stage_context;

    main_pool_push_state('LAND');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    stage_context = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    Font_Init(28, 0);

    // D_1000000/D_2000000/D_3000000 are reusable segment bases, not unique textures.
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, area_select_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);

    Text_InitStringTables();
    sAreaSelectStrings = Text_GetStringTable(23);
    Save_EnsureBankLoaded(2);
    Save_GetOptions(&sAreaSelectGameOptions);
    Save_GetModeSettings(&sAreaSelectModeSettings, gSessionContext.inRound2);
    AreaSelect_LoadBackgroundArt();
    sAreaSelectSelectedIndex = AREA_NONE;

    if ((sAreaSelectModeSettings.mewtwoUnlocked != 0) &&
        !(gSessionContext.sessionFlags & SESSION_FLAG_REVEAL_MEWTWO) &&
        !(sAreaSelectModeSettings.clearedModes & (1 << RULE_CATEGORY_VS_MEWTWO))) {
        sAreaSelectBackgroundFadeAlpha = 255;
    }

    StageContext_Activate(stage_context);
    AreaSelect_Intro();
    AreaSelect_Loop();
    StageContext_Deactivate();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('LAND');

    return sAreaSelectStateIds[sAreaSelectSelectedIndex];
}
