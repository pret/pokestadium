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

typedef struct AreaSelectSparklePoint {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
} AreaSelectSparklePoint; // size = 0x6

typedef struct AreaSelectSparkleTrail {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ AreaSelectSparklePoint unk_0C[4];
} AreaSelectSparkleTrail; // size = 0x24

typedef struct AreaSelectCursorGlow {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ Color_RGBA8 unk_08;
} AreaSelectCursorGlow; // size >= 0xC

static s16 gAreaSelectBackgroundFadeAlpha = 0;

static s16 gAreaSelectGlowRadius = 0;

static s16 gAreaSelectStateIds[] = {
    STATE_STADIUM_MENU,   STATE_FREE_BATTLE, STATE_GYM_LEADER_CASTLE, STATE_VS_MEWTWO,   STATE_KIDS_CLUB,
    STATE_VICTORY_PALACE, STATE_POKEMON_LAB, STATE_GB_TOWER,          STATE_MENU_SELECT,
};

static u8* gAreaSelectNameBannerTextures[] = {
    0x03006E60, 0x0300D060, 0x03013260, 0x03019460, 0x0301F660,
    0x03025860, 0x0302BA60, 0x03031C60, 0x03037E60, 0x0303E060,
};

static AreaSelectEntryConfig gAreaSelectEntryConfigs[9] = {
    { 0x012C, 0x00B9, 0x004B, 0x03, 0x04, 0x06, 0x07, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x0208, 0x0118, 0x004B, 0x07, 0x08, 0x04, 0x08, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x006E, 0x005A, 0x0041, 0x08, 0x06, 0x08, 0x03, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x012C, 0x0041, 0x0041, 0x08, 0x00, 0x02, 0x07, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x015E, 0x013B, 0x0050, 0x00, 0x08, 0x05, 0x01, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x00BE, 0x014A, 0x0046, 0x06, 0x08, 0x08, 0x04, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x0078, 0x00E6, 0x0041, 0x02, 0x05, 0x08, 0x00, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x01FE, 0x0096, 0x0041, 0x03, 0x01, 0x00, 0x08, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x012C, 0x00B9, 0x000A, 0x08, 0x08, 0x08, 0x08, { 0x32, 0x50, 0x96, 0x00 } },
};

static u8* gAreaSelectSparkleTextures[] = { 0x03005000, 0x03005A20, 0x03006440, 0x03005A20 };

static char** gAreaSelectStrings;
static BinArchive* gAreaSelectBackgroundArchive;
static Vp gAreaSelectViewport;
static Mtx gAreaSelectProjectionMtx;
static u8* gAreaSelectCurrentBackground;
static u8* gAreaSelectNextBackground;
static AreaSelectCursorGlow gAreaSelectCursorGlow;
static AreaSelectSparkleTrail gAreaSelectSparkleTrails[3];
static s32 pad_D_822031D0[0x2];
static s16 gAreaSelectSelectedIndex;
static s16 gAreaSelectPreviousIndex;
static s16 gAreaSelectTransitionFrame;
static ModeSettings gAreaSelectModeSettings;
static GameOptions gAreaSelectGameOptions;

s32 AreaSelect_CheckCartRemoved(s32 arg0) {
    u32 temp_a0 = osSetIntMask(1);

    if (!(HW_REG(PI_STATUS_REG, u32) & 3) && ((*(u32*)0xB0000D10 & 0xFFFF) != 0x400)) {
        arg0 = -0x40;
    }

    osSetIntMask(temp_a0);
    return arg0;
}

void AreaSelect_DrawCrossfadeBackground(u8* arg0, u8* arg1, u8 arg2) {
    s32 i;
    s32 j;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 640, 480);
    gDPSetCombineLERP(gDisplayListHead++, TEXEL1, TEXEL0, ENV_ALPHA, TEXEL0, TEXEL1, TEXEL0, ENVIRONMENT, TEXEL0, 0, 0,
                      0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg2);
    gDPPipeSync(gDisplayListHead++);

    for (i = 0; i < 0x1E0; i += 0x20) {
        for (j = 0; j < 0x280; j += 0x20) {
            gDPLoadTextureBlock(gDisplayListHead++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gDPLoadMultiBlock(gDisplayListHead++, arg1, 0x0100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                              G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                              G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, j << 2, i << 2, (j + 0x20) << 2, (i + 0x20) << 2, G_TX_RENDERTILE,
                                0, 0, 0x0200, 0x0200);

            arg0 += 0x200;
            arg1 += 0x200;
        }
    }
}

Vtx* AreaSelect_BuildGlowQuadVerts(void) {
    Vtx* temp_v0;
    s16 temp_s0;
    s16 temp_s6;
    s16 temp_s7;
    u8 temp_s2;
    u8 temp_s3;
    u8 temp_s4;
    u8 temp_s5;

    temp_s6 = gAreaSelectCursorGlow.unk_00;
    temp_s7 = gAreaSelectCursorGlow.unk_02;
    temp_s0 = gAreaSelectCursorGlow.unk_04;
    temp_s2 = gAreaSelectCursorGlow.unk_08.r;
    temp_s3 = gAreaSelectCursorGlow.unk_08.g;
    temp_s4 = gAreaSelectCursorGlow.unk_08.b;
    temp_s5 = gAreaSelectCursorGlow.unk_08.a;

    temp_v0 = Gfx_AllocDisplayList(sizeof(Vtx) * 8);

    if (temp_v0 != NULL) {
        Gfx_SetVertexAttributes(&temp_v0[0], temp_s6 - temp_s0, temp_s7 - temp_s0, -1, 0, 0, temp_s2, temp_s3, temp_s4, temp_s5);
        Gfx_SetVertexAttributes(&temp_v0[1], temp_s6 - temp_s0, temp_s7 + temp_s0, -1, 0, 0x7E0, temp_s2, temp_s3, temp_s4,
                      temp_s5);
        Gfx_SetVertexAttributes(&temp_v0[2], temp_s6 + temp_s0, temp_s7 + temp_s0, -1, 0x7E0, 0x7E0, temp_s2, temp_s3, temp_s4,
                      temp_s5);
        Gfx_SetVertexAttributes(&temp_v0[3], temp_s6 + temp_s0, temp_s7 - temp_s0, -1, 0x7E0, 0, temp_s2, temp_s3, temp_s4,
                      temp_s5);

        Gfx_SetVertexAttributes(&temp_v0[4], temp_s6 - 0x7D0, temp_s7 - 0x7D0, -1, 0, 0, temp_s2, temp_s3, temp_s4, temp_s5);
        Gfx_SetVertexAttributes(&temp_v0[5], temp_s6 - 0x7D0, temp_s7 + 0x7D0, -1, 0, 0, temp_s2, temp_s3, temp_s4, temp_s5);
        Gfx_SetVertexAttributes(&temp_v0[6], temp_s6 + 0x7D0, temp_s7 + 0x7D0, -1, 0, 0, temp_s2, temp_s3, temp_s4, temp_s5);
        Gfx_SetVertexAttributes(&temp_v0[7], temp_s6 + 0x7D0, temp_s7 - 0x7D0, -1, 0, 0, temp_s2, temp_s3, temp_s4, temp_s5);
    }

    return temp_v0;
}

void AreaSelect_DrawCursorGlow(void) {
    Vtx* temp_v0;

    if (gAreaSelectCursorGlow.unk_08.a <= 0) {
        return;
    }

    temp_v0 = AreaSelect_BuildGlowQuadVerts();

    if (temp_v0 != 0) {
        gDPPipeSync(gDisplayListHead++);

        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gAreaSelectCursorGlow.unk_06);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, SHADE, ENV_ALPHA, SHADE, 0, 0, 0, SHADE, ENVIRONMENT, SHADE,
                          ENV_ALPHA, SHADE, 0, 0, 0, SHADE);

        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 8, 0);
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
        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    }
}

void AreaSelect_AdvanceSparkleTrail(void) {
    s32 i;
    s32 j;
    s16 temp_fv0;
    s16 var_v0 = gAreaSelectSparkleTrails[0].unk_08;

    for (i = 0; i < 3; i++) {
        for (j = 4; j >= 0; j--) {
            gAreaSelectSparkleTrails[i].unk_0C[j + 1] = gAreaSelectSparkleTrails[i].unk_0C[j];
        }

        temp_fv0 = (gAreaSelectSparkleTrails[0].unk_06 * gAreaSelectSparkleTrails[0].unk_04) / 100;

        gAreaSelectSparkleTrails[i].unk_0C[0].unk_00 = gAreaSelectSparkleTrails[0].unk_00 + (COSS((var_v0)) * temp_fv0);
        gAreaSelectSparkleTrails[i].unk_0C[0].unk_02 = gAreaSelectSparkleTrails[0].unk_02 + (SINS((var_v0)) * temp_fv0);
        gAreaSelectSparkleTrails[i].unk_0C[0].unk_04 = (gAreaSelectSparkleTrails[0].unk_06 * 0x48) / 100;

        var_v0 -= 0x5555;
    }
}

void AreaSelect_InitSparkleTrail(s32 arg0) {
    s32 i;

    gAreaSelectSparkleTrails[0].unk_00 = gAreaSelectEntryConfigs[arg0].unk_00;
    gAreaSelectSparkleTrails[0].unk_02 = gAreaSelectEntryConfigs[arg0].unk_02;
    gAreaSelectSparkleTrails[0].unk_04 = gAreaSelectEntryConfigs[arg0].unk_04;
    gAreaSelectSparkleTrails[0].unk_06 = 0x64;
    gAreaSelectSparkleTrails[0].unk_0A = 0;
    gAreaSelectSparkleTrails[0].unk_08 = 0;

    for (i = 0; i < 6; i++) {
        AreaSelect_AdvanceSparkleTrail();
        gAreaSelectSparkleTrails[0].unk_08 -= 0x800;
    }
}

Vtx* AreaSelect_BuildSparkleQuadVerts(s16 arg0, s16 arg1, s16 arg2, Color_RGBA8 arg3) {
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

void AreaSelect_DrawSparkleQuad(s16 arg0, s16 arg1, s16 arg2, u8* arg3, Color_RGBA8 arg4) {
    Vtx* temp_v0 = AreaSelect_BuildSparkleQuadVerts(arg0, arg1, arg2, arg4);

    if (temp_v0 != NULL) {
        gDPLoadTextureBlock(gDisplayListHead++, arg3, G_IM_FMT_RGBA, G_IM_SIZ_16b, 36, 36, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
    }
}

void AreaSelect_DrawSparkleTrail(u8* arg0) {
    Color_RGBA8 sp5C;
    s16 i;
    s16 j;
    s16 temp_s1;
    s16 temp_s3;
    s16 temp_s4;

    for (i = 5; i >= 0; i--) {
        for (j = 0; j < 3; j++) {
            temp_s1 = gAreaSelectSparkleTrails[j].unk_0C[i].unk_04;
            temp_s3 = gAreaSelectSparkleTrails[j].unk_0C[i].unk_00;
            temp_s4 = gAreaSelectSparkleTrails[j].unk_0C[i].unk_02;

            if (temp_s1 != 0) {
                if (i == 0) {
                    Color_SetRGBA(&sp5C, 0xFF, 0xFF, 0xFF, 0xFF);
                } else {
                    Color_SetRGBA(&sp5C, 0xFF, 0xFF, 0x64, 0xA0 - (i * 30));
                }
                AreaSelect_DrawSparkleQuad(temp_s3, temp_s4, temp_s1, arg0, sp5C);
            }
        }
    }
}

void AreaSelect_UpdateSparkles(void) {
    if (gAreaSelectSelectedIndex != 8) {
        AreaSelect_AdvanceSparkleTrail();

        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

        AreaSelect_DrawSparkleTrail(gAreaSelectSparkleTextures[gAreaSelectSparkleTrails->unk_0A / 2]);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);

        gAreaSelectSparkleTrails->unk_08 -= 0x800;
        gAreaSelectSparkleTrails->unk_0A = (gAreaSelectSparkleTrails->unk_0A + 2) % 8;
    }
}

void AreaSelect_DrawNameBanner(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 i;
    u8* var_s2;

    if (arg3 != 8) {
        if (arg3 == 7) {
            arg3 += gAreaSelectGameOptions.unk_00;
        }
        var_s2 = gAreaSelectNameBannerTextures[arg3];

        gSPDisplayList(gDisplayListHead++, D_8006F518);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg2);

        for (i = 0; i < 16; i++) {
            Gfx_DrawTextureRgba16(arg0, arg1 + (i * 4), 0xC4, 4, var_s2 + (i * 0x620), 0xC4, 0);
        }

        if ((D_800AE540.unk_11F2 != 0) && ((arg3 == 0) || (arg3 == 2) || (arg3 == 3))) {
            Gfx_DrawTextureRgba16(arg0 - 0x20, arg1 + 0xD, 0x24, 0x24, D_20144E0, 0x24, 0);
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }
}

void func_822014C0(void) {
}

void AreaSelect_DrawNameBannerCrossfade(s16 arg0, s16 arg1, s16 arg2) {
    static s16 areaSelectBannerScrollFrame = 1;
    static s16 areaSelectBannerScrollDirection = 1;

    s16 sp1E;

    if (arg0 == 2) {
        sp1E = (gAreaSelectTransitionFrame * 0x2A) + 3;
        AreaSelect_DrawNameBanner(arg1, (arg2 + (areaSelectBannerScrollFrame / 4)) - 5, 0xFF - sp1E, gAreaSelectPreviousIndex);
        AreaSelect_DrawNameBanner(arg1, (arg2 + (areaSelectBannerScrollFrame / 4)) - 5, sp1E, gAreaSelectSelectedIndex);
    } else if ((arg0 != 8) && (arg0 != 0)) {
        AreaSelect_DrawNameBanner(arg1, (arg2 + (areaSelectBannerScrollFrame / 4)) - 5, 0xFF, gAreaSelectSelectedIndex);
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

    if (gAreaSelectModeSettings.unk_07 != 0) {
        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetEnvColor(gDisplayListHead++, 0, 100, 255, 255);

        if (D_800AE540.unk_11F5 & 4) {
            gDPSetPrimColor(gDisplayListHead++, 0, 0xFF, 255, 255, 255, gAreaSelectBackgroundFadeAlpha);
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
    if ((gAreaSelectModeSettings.unk_07 == 0) || (arg2 <= 0)) {
        return;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);
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

    gSPDisplayList(gDisplayListHead++, D_8006F518);
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

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((sp50 > 0) && (sp54 > 0)) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp50, var_s2, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0, arg1 + var_s3, arg2, sp54, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0 + var_s3, arg1 + var_s3 + sp54, sp50, var_s2, arg4, arg5, arg6, arg7);
    } else if (sp50 > 0) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp50, arg3, arg4, arg5, arg6, arg7);
    } else if (sp54 > 0) {
        Gfx_FillRectRgba(arg0, arg1 + var_s2, arg2, sp54, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void AreaSelect_DrawAreaInfoBox(s32 arg0) {
    AreaSelect_DrawInfoPanel(0x38, 0x17C, 0x210, 0x3C, 0x1E, 0x1E, 0x82, 0x96);

    if (arg0 != 0) {
        Font_BeginTranslucentTextRendering();
        Font_SetActive(8, 0);
        Font_SetLineHeight(0x18);
        Font_Printf(0x5B, 0x182, Text_GetString(NULL, 0, gAreaSelectStrings, gAreaSelectSelectedIndex));
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

    gAreaSelectSparkleTrails->unk_00 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_00;
    gAreaSelectSparkleTrails->unk_02 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_02;
    gAreaSelectSparkleTrails->unk_04 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_04;
    gAreaSelectSparkleTrails->unk_06 = 0x64;

    gAreaSelectCursorGlow.unk_00 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_00;
    gAreaSelectCursorGlow.unk_02 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_02;
    gAreaSelectCursorGlow.unk_08 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_0A;
    gAreaSelectCursorGlow.unk_06 = 0;
    gAreaSelectCursorGlow.unk_04 = 0x12C;

    if (gPlayer1Controller->buttonPressed & 0x8000) {
        if (gAreaSelectSelectedIndex == 3) {
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
        var_s0 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_06;
    } else if (gPlayer1Controller->buttonPressed & 0x400) {
        var_s0 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_07;
    } else if (gPlayer1Controller->buttonPressed & 0x200) {
        var_s0 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_08;
    } else if (gPlayer1Controller->buttonPressed & 0x100) {
        var_s0 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_09;
    }

    if (var_s0 != 8) {
        Audio_PlaySoundEffectById(SFX_AREA_CURSOR);
        var_t1 = 2;
        gAreaSelectPreviousIndex = gAreaSelectSelectedIndex;
        gAreaSelectSelectedIndex = var_s0;
        gAreaSelectTransitionFrame = 0;
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

    vA_0 = gAreaSelectEntryConfigs[gAreaSelectPreviousIndex].unk_00;
    vA_2 = gAreaSelectEntryConfigs[gAreaSelectPreviousIndex].unk_02;
    vA_4 = gAreaSelectEntryConfigs[gAreaSelectPreviousIndex].unk_04;
    v8_0 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_00;
    v8_2 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_02;
    v8_4 = gAreaSelectEntryConfigs[gAreaSelectSelectedIndex].unk_04;

    gAreaSelectTransitionFrame++;

    gAreaSelectSparkleTrails->unk_00 = (((v8_0 - vA_0) * gAreaSelectTransitionFrame) / 6) + vA_0;
    gAreaSelectSparkleTrails->unk_02 = (((v8_2 - vA_2) * gAreaSelectTransitionFrame) / 6) + vA_2;
    gAreaSelectSparkleTrails->unk_04 = (((v8_4 - vA_4) * gAreaSelectTransitionFrame) / 6) + vA_4;
    gAreaSelectSparkleTrails->unk_06 = 0x64;
    gAreaSelectSparkleTrails->unk_08 += 0x800;

    if (gAreaSelectTransitionFrame == 6) {
        var_v1 = 1;
    } else {
        var_v1 = 2;
    }

    return var_v1;
}

s32 AreaSelect_ConfirmSelection(void) {
    s32 var_v1 = 3;

    if (gAreaSelectSparkleTrails->unk_06 >= 0xB) {
        gAreaSelectSparkleTrails->unk_06 -= 5;
    } else {
        gAreaSelectSparkleTrails->unk_06 = 0;
        if (gAreaSelectSelectedIndex == 3) {
            Audio_StopMusic(0x20);
            var_v1 = 6;
        } else {
            if (gAreaSelectSelectedIndex != 7) {
                Audio_StopMusic(0x28);
            }
            var_v1 = 5;
        }
    }
    return var_v1;
}

s32 AreaSelect_FadeToBattle(void) {
    s16 var_a1 = 5;

    if (gAreaSelectCursorGlow.unk_08.a < 0xFA) {
        gAreaSelectCursorGlow.unk_08.a += 0x19;
    } else if (gAreaSelectCursorGlow.unk_06 < 0xFF) {
        gAreaSelectCursorGlow.unk_08.a = 0xFF;
        gAreaSelectCursorGlow.unk_06 += 0x19;
        if (gAreaSelectCursorGlow.unk_06 >= 0xFF) {
            gAreaSelectCursorGlow.unk_06 = 0xFF;
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

    if (gAreaSelectGlowRadius < 0x200) {
        gAreaSelectGlowRadius += 0x40;
    } else if (gAreaSelectGlowRadius == 0x200) {
        gAreaSelectGlowRadius += 0x40;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(2);
        var_a1 = 6;
    } else if (gAreaSelectGlowRadius < 0x280) {
        gAreaSelectGlowRadius += 0x40;
        if (gAreaSelectGlowRadius == 0x280) {
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
            gAreaSelectSelectedIndex = 8;
            var_v1 = 7;
            break;
    }

    return var_v1;
}

void AreaSelect_SetupOrthoProjection(void) {
    guOrtho(&gAreaSelectProjectionMtx, 0.0f, 640.0f, 480.0f, 0.0f, -2.0f, 2.0f, 1.0f);
    Gfx_SetViewportDimensions(&gAreaSelectViewport, 0x280, 0x1E0);

    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPViewport(gDisplayListHead++, (u32)&gAreaSelectViewport & 0x1FFFFFFF);
    gSPMatrix(gDisplayListHead++, (u32)&gAreaSelectProjectionMtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void AreaSelect_Draw(s16 arg0) {
    BgStage_DrawFrame();
    AreaSelect_SetupOrthoProjection();

    if (gAreaSelectBackgroundFadeAlpha == 0) {
        Gfx_DrawTiledRgba16Image(gAreaSelectCurrentBackground);
    } else if (gAreaSelectBackgroundFadeAlpha == 0xFF) {
        Gfx_DrawTiledRgba16Image(gAreaSelectNextBackground);
    } else {
        AreaSelect_DrawCrossfadeBackground(gAreaSelectCurrentBackground, gAreaSelectNextBackground, gAreaSelectBackgroundFadeAlpha);
    }

    AreaSelect_DrawPulsingMarker(0x12C, 0x41);
    AreaSelect_UpdateSparkles();
    AreaSelect_DrawNameBannerCrossfade(arg0, 0x194, 0x28);
    AreaSelect_DrawGlowCircle(0x12C, 0x41, gAreaSelectGlowRadius);
    AreaSelect_DrawCursorGlow();

    if ((arg0 == 1) || (arg0 == 2)) {
        AreaSelect_DrawAreaInfoBox(arg0 == 1);
    }

    BgStage_AdvanceFrame();
}

s32 AreaSelect_FadeInFromBattle(void) {
    s16 var_v1 = 8;

    gAreaSelectSelectedIndex = 8;
    if (StageContext_GetFadeMode() == 0) {
        gAreaSelectBackgroundFadeAlpha += 4;
        if (gAreaSelectBackgroundFadeAlpha == 0x100) {
            D_800AE540.unk_11F5 &= 0xFFFB;
            gAreaSelectBackgroundFadeAlpha = 0xFF;
            gAreaSelectPreviousIndex = 8;
            gAreaSelectSelectedIndex = 0;
            var_v1 = 2;
        }
    }
    return var_v1;
}

void AreaSelect_Intro(void) {
    AreaSelect_InitSparkleTrail(gAreaSelectSelectedIndex);
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
    if (D_800AE540.unk_11F5 & 4) {
        Cry_Play(0x96, 7);
        i = 8;
    }

    if (gAreaSelectModeSettings.unk_07 == 0) {
        gAreaSelectEntryConfigs[0].unk_06 = 8;
        gAreaSelectEntryConfigs[2].unk_09 = 8;
        gAreaSelectEntryConfigs[7].unk_06 = 8;
    }

    gAreaSelectPreviousIndex = 8;
    gAreaSelectSelectedIndex = 0;

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
    gAreaSelectBackgroundArchive = ASSET_LOAD2(backgrounds, 1, 1);

    if (gAreaSelectGameOptions.unk_00 == 2) {
        if (D_800AE540.unk_11F2 == 0) {
            gAreaSelectCurrentBackground = BinArchive_GetFile(gAreaSelectBackgroundArchive, 1);
            gAreaSelectNextBackground = BinArchive_GetFile(gAreaSelectBackgroundArchive, 2);
        } else {
            gAreaSelectNextBackground = gAreaSelectCurrentBackground = BinArchive_GetFile(gAreaSelectBackgroundArchive, 2);
        }
    } else if (gAreaSelectGameOptions.unk_00 == 1) {
        gAreaSelectNextBackground = gAreaSelectCurrentBackground = BinArchive_GetFile(gAreaSelectBackgroundArchive, 0x13);
    } else {
        gAreaSelectNextBackground = gAreaSelectCurrentBackground = BinArchive_GetFile(gAreaSelectBackgroundArchive, 0x12);
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
    gAreaSelectStrings = Text_GetStringTable(0x17);
    Save_EnsureBankLoaded(2);
    Save_GetOptions(&gAreaSelectGameOptions);
    Save_GetModeSettings(&gAreaSelectModeSettings, D_800AE540.unk_11F2);
    AreaSelect_LoadBackgroundArt();
    gAreaSelectSelectedIndex = 8;

    if ((gAreaSelectModeSettings.unk_07 != 0) && !(D_800AE540.unk_11F5 & 4) && !(gAreaSelectModeSettings.unk_00 & 0x100)) {
        gAreaSelectBackgroundFadeAlpha = 0xFF;
    }

    StageContext_Activate(sp24);
    AreaSelect_Intro();
    AreaSelect_Loop();
    StageContext_Deactivate();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('LAND');

    return gAreaSelectStateIds[gAreaSelectSelectedIndex];
}
