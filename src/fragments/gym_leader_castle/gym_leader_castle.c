#include "gym_leader_castle.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/save_data.h"
#include "src/game_state.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/audio_commands_category2.h"
#include "src/DDC0.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static char** sUiText;
static char** sTrainerNameText;
static GymLeaderCastleTrainer sCurrentNodeTrainers[4];
static BinArchive* sTrainerDataArchive;
static BinArchive* sPortraitArchive;
static BinArchive* sBackgroundArchive;
static u8* sGymLeaderCastleTexture;
static u8* sEliteFourTexture;
static u8* D_84A0317C;
static ModeSettings D_84A03180;
static s16 sCurrentHoverNodeIndex;

#define CHAMPION 11
#define ELITE_4 10
#define ELITE_4_TO_GLC 9
#define GLC_TO_ELITE_4 8
#define GIOVANNI 7

static CastleMapNode sCastleMapNodes[] = {
    {
        0x00,      0x00, 154, 390,  118, 362, 96, 278, 48, 70, -32768, 0, 0, 0, 2, { 0x96, 0x64, 0xFF, 0x00 },
        D_3000000, 0,    30,  NULL,
    },
    {
        0x01,      0x00, 238, 416,  210, 392, 184, 304, 48, 70, -32768, 3, 0, 1, 3, { 0x00, 0x9B, 0xFF, 0x00 },
        D_3000D20, 1,    31,  NULL,
    },
    {
        0x02,      0x00, 322, 386,  282, 362, 248, 274, 48, 70, -32768, 4, 2, 2, 0, { 0xFF, 0x5F, 0x0F, 0x00 },
        D_3001A40, 2,    32,  NULL,
    },
    {
        0x03,      0x00, 270, 304,  256, 282, 234, 190, 48, 70, -32768, 5, 3, 5, 0, { 0x8C, 0x37, 0xFF, 0x00 },
        D_3002760, 3,    33,  NULL,
    },
    {
        0x04,      0x00, 214, 286,  188, 266, 168, 180, 48, 70, -32768, 6, 4, 6, 4, { 0xFF, 0x37, 0xFF, 0x00 },
        D_3003480, 4,    34,  NULL,
    },
    {
        5,         0x00, 164, 178,  160, 170, 116, 96, 48, 70, -32768, 7, 5, 0, 7, { 0xCD, 0x91, 0x00, 0x00 },
        D_30041A0, 5,    35,  NULL,
    },
    {
        6,         0x00, 284, 148,  290, 138, 250, 78, 48, 70, -32768, 0, 8, 6, 8, { 0xFF, 0x00, 0x00, 0x00 },
        D_3004EC0, 6,    36,  NULL,
    },
    {
        0x07,      0x00, 364, 243,  330, 214, 306, 110, 48, 70, -32768, 7, 0, 7, 9, { 0x37, 0xFF, 0xFF, 0x00 },
        D_3005BE0, 7,    37,  NULL,
    },
    {
        0x08,      0x00, 0,  0,    418, 204, 390, 102, 48, 70, -32768, 0, 0, 0, 0, { 0xC8, 0xFF, 0x00, 0x00 },
        D_3006900, -1,   -1, NULL,
    },
    {
        9,         0x00, 190, 384,  174, 424, 180, 394, 40, 27, -32768, 0, 0, 0, 0, { 0xFF, 0x64, 0x00, 0x00 },
        D_3008E50, -1,   9,   NULL,
    },
    {
        10,        0x00, 446, 216,  374, 210, 356, 128, 72, 43, -32768, 12, 10, 10, 0, { 0xFF, 0x64, 0x00, 0x00 },
        D_3007620, 10,   10,  NULL,
    },
    {
        11,        0x00, 0,  0,    312, 148, 274, 68, 72, 43, -32768, 0, 11, 0, 0, { 0x00, 0x64, 0xC8, 0x00 },
        D_3008238, -1,   11, NULL,
    },
};

static s16 sSelectedMapNode = 0;
static s16 sCursorMoveTimer = 0;
static s16 D_84A030E8 = 0xFF;
static s16 sRoomDescriptionHeight = 0;
static s16 sEliteFourTransition = 0;

void GymLeaderCastle_DrawBackgroundCrossFade(u8* fade_in_texture, u8* fade_out_texture, u8 alpha) {
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
            gDPLoadTextureBlock(gDisplayListHead++, fade_in_texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gDPLoadMultiBlock(gDisplayListHead++, fade_out_texture, 0x0100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                              G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                              G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, j << 2, i << 2, (j + 0x20) << 2, (i + 0x20) << 2, G_TX_RENDERTILE,
                                0, 0, 0x0200, 0x0200);
            fade_in_texture += 0x200;
            fade_out_texture += 0x200;
        }
    }
}

void GymLeaderCastle_DrawScaledTextureRgba(s16 x_start, s16 y_start, s16 draw_width, s16 height, s16 load_width,
                                           u8* texture, f32 scale) {
    UNUSED s32 pad;

    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, (s32)(load_width / scale),
                        (s32)(height / scale), 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                        G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(x_start, y_start, draw_width, height, 0, 0, 1024.0f / scale, 1024.0f / scale, 0);
}

void func_84A00630(void) {
}

void GymLeaderCastle_DrawScaledTextureIa8(s16 x_start, s16 y_start, s16 width, s16 height, u8* texture, f32 scale) {
    UNUSED s32 pad;

    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_IA, G_IM_SIZ_8b, (s32)(width / scale),
                        (s32)(height / scale), 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                        G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(x_start, y_start, width, height, 0, 0, 1024.0f / scale, 1024.0f / scale, 0);
}

void GymLeaderCastle_DrawRoomDescription(void) {
    char var_sp40[0x100];
    UNUSED s32 pad2;
    s16 y1;
    UNUSED s32 pad;
    s16 current_node_file_number;

    if (sRoomDescriptionHeight >= 0x10) {
        y1 = 240 - (sRoomDescriptionHeight / 2);
        Ui_DrawBorderedPanelNoFill(120, y1, 400, sRoomDescriptionHeight);
        Gfx_FillRectWithDisplayState(127, y1 + 7, 386, sRoomDescriptionHeight - 14, 0x14, 0x32, 0x64, 0x96);

        if (sRoomDescriptionHeight == 80) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(8, 0);
            Font_SetLineHeight(24);

            if (sSelectedMapNode == GIOVANNI) {
                Font_Printf(136, y1 + 16, Text_GetString(NULL, 0, sUiText, 12));
            } else if (sSelectedMapNode == ELITE_4) {
                Font_Printf(136, y1 + 16, Text_GetString(NULL, 0, sUiText, 13));
            } else {
                current_node_file_number = sCastleMapNodes[sSelectedMapNode].fileNumber;
                if (current_node_file_number >= 30) {
                    Text_SetStringToken(36, Text_GetString(NULL, 0, sTrainerNameText, current_node_file_number));
                } else if (current_node_file_number >= 0) {
                    Text_SetStringToken(36, Text_GetString(NULL, 0, sUiText, current_node_file_number));
                } else {
                    Text_SetStringToken(36, " ");
                }

                current_node_file_number = sCastleMapNodes[sSelectedMapNode + 1].fileNumber;
                if (current_node_file_number >= 30) {
                    Text_SetStringToken(41, Text_GetString(NULL, 0, sTrainerNameText, current_node_file_number));
                } else if (current_node_file_number >= 0) {
                    Text_SetStringToken(41, Text_GetString(NULL, 0, sUiText, current_node_file_number));
                } else {
                    Text_SetStringToken(41, " ");
                }
                Font_Printf(136, y1 + 0x10, Text_GetString(var_sp40, sizeof(var_sp40), sUiText, 14));
            }
            Font_EndTexturedTextRendering();
        }
    }
}

void GymLeaderCastle_DrawTrainerIntroPanels(void) {
    UNUSED s32 pad[3];
    s32 i;
    char* boss_title;
    CastleMapNode* hovered_map_node = &sCastleMapNodes[sSelectedMapNode];

    for (i = 0; i < 4; i++) {
        if (sCurrentNodeTrainers[i].loaded != 0) {
            s16 trainer_portrait_x = sCurrentNodeTrainers[i].portraitX;

            gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

            GymLeaderCastle_DrawScaledTextureRgba(trainer_portrait_x, 240, 128, 64, 128, D_3009290, 2.0f);
            GymLeaderCastle_DrawScaledTextureRgba(trainer_portrait_x, 304, 128, 64, 128, D_300A290, 2.0f);
            GymLeaderCastle_DrawScaledTextureRgba(trainer_portrait_x, 368, 128, 64, 128, D_300B290, 2.0f);
            GymLeaderCastle_DrawScaledTextureRgba(trainer_portrait_x + 8, 312, 112, 56, 128,
                                                  sCurrentNodeTrainers[i].portrait + 520, 2.0f);
            GymLeaderCastle_DrawScaledTextureRgba(trainer_portrait_x + 8, 368, 112, 56, 128,
                                                  sCurrentNodeTrainers[i].portrait + 4104, 2.0f);

            gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

            Font_BeginTranslucentTextRendering();
            // special titles for Gym leaders
            // Condition reads as "is the player in the Elite Four room OR is panel the gym leader's?"
            if ((sSelectedMapNode >= GLC_TO_ELITE_4) || (i == 3)) {
                Font_SetActive(8, 0);

                if (hovered_map_node->bossTitle >= 0) {
                    boss_title = Text_GetString(NULL, 0, sUiText, hovered_map_node->bossTitle);
                } else {
                    boss_title = " ";
                }

                Font_Printf((trainer_portrait_x - (Font_MeasureTextExtent(8, 0, boss_title) / 2)) + 64, 244,
                            boss_title);
            }

            Font_SetActive(4, 0);

            if ((i == 3) && (sSelectedMapNode < GLC_TO_ELITE_4)) {
                Font_Printf(trainer_portrait_x + 8, 268, Text_GetString(NULL, 0, sUiText, 8));
            } else {
                Font_Printf(trainer_portrait_x + 8, 268, Text_GetString(NULL, 0, sUiText, 0xF));
            }

            Font_SetActive(0x10, 0);
            Font_Printf((trainer_portrait_x - (Font_MeasureTextExtent(0x10, 0, sCurrentNodeTrainers[i].name) / 2)) + 64,
                        284, sCurrentNodeTrainers[i].name);
            Font_EndTexturedTextRendering();
        }
    }
}

void GymLeaderCastle_DrawMapBorder(void) {
    static s16 D_84A030F4 = 0;
    static s16 D_84A030F8 = 1;

    s16 i;
    s16 var_s1 = (D_84A030F4 / 4) + 34;

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    for (i = 0; i < 9; i++) {
        Gfx_DrawTextureRgba16(36, var_s1, 228, 8, D_3011A30 + i * 3648, 228, 0);
        var_s1 += 8;
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    D_84A030F4 += D_84A030F8;
    if (D_84A030F4 == 0) {
        D_84A030F8 = 1;
    }

    if (D_84A030F4 == 35) {
        D_84A030F8 = -1;
    }
}

void GymLeaderCastle_DrawRoomMarkers(void) {
    s32 i;
    s32 node_alpha;
    s32 backwards_index;
    CastleMapNode* node;

    if (sSelectedMapNode < ELITE_4_TO_GLC) {
        node = &sCastleMapNodes[0];
        backwards_index = 9;
    } else {
        node = &sCastleMapNodes[9];
        backwards_index = 3;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0,
                      PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    for (; backwards_index > 0; backwards_index--, node++) {
        if (node->nodeState != 0) {
            node_alpha = 0xFF;
            if (node->nodeState == 1) {
                node_alpha = (s32)((COSS(node->pulsing) + 1.0f) * 96.0f);
                node_alpha += 63;
                node->pulsing += 0x200;
            } else {
                node->pulsing = 0;
                node->nodeState--;
            }

            gDPSetEnvColor(gDisplayListHead++, node->color.r, node->color.g, node->color.b, node_alpha);

            if (node->index == 9) {
                gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 0, 255);
            } else {
                gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
            }

            GymLeaderCastle_DrawScaledTextureIa8(node->markerX, node->markerY, node->markerWidth * 2,
                                                 node->markerHeight * 2, node->texture, 2.0f);
        }
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void GymLeaderCastle_DrawRoomLabels(void) {
    s32 backwards_index;
    char* label;
    CastleMapNode* node;
    s16 tmp;

    if (sSelectedMapNode < ELITE_4_TO_GLC) {
        node = &sCastleMapNodes[0];
        backwards_index = 8;
    } else {
        node = &sCastleMapNodes[9];
        backwards_index = 3;
    }

    Font_BeginTranslucentTextRendering();
    Font_EnableTwoCycleTexturing();
    Font_SetActive(4, 0);
    Gfx_SetPrimColor(0x50, 0x64, 0xDC, 0xFF);

    for (; backwards_index > 0; backwards_index--, node++) {
        if (node->nodeState != 0) {
            if (node->fileNumber >= 30) {
                label = Text_GetString(NULL, 0, sTrainerNameText, node->fileNumber);
            } else if (node->fileNumber >= 0) {
                label = Text_GetString(NULL, 0, sUiText, node->fileNumber);
            } else {
                label = " ";
            }
            tmp = node->labelX - (Font_MeasureTextExtent(4, 0, label) / 2);
            Font_Printf(tmp, node->labelY, label);
        }
    }

    Font_DisableTwoCycleTexturing();
    Font_EndTexturedTextRendering();
}

void GymLeaderCastle_DrawGymLeaderInfoPanel(CastleMapNode* node, u8 alpha1, u8 alpha2) {
    char* string;

    if (node->infoPanelTexture != NULL) {
        gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, alpha1);

        GymLeaderCastle_DrawScaledTextureRgba(502, 352, 96, 48, 96, node->infoPanelTexture, 1.5f);
        GymLeaderCastle_DrawScaledTextureRgba(502, 400, 96, 48, 96, node->infoPanelTexture + 0x1000, 1.5f);

        gSPDisplayList(gDisplayListHead++, D_8006F558);
        gDPSetEnvColor(gDisplayListHead++, node->color.r, node->color.g, node->color.b, (alpha2 * 0x96) / 255);

        Gfx_DrawTextureIa16(358, 372, 16, 76, D_300C290, 0x10, 0);
        Gfx_DrawTexturedRectClipped(374, 372, 128, 76, 480, 0, 0, 0x400, 0);

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

        Font_BeginTranslucentTextRendering();
        Font_EnableTwoCycleTexturing();
        Gfx_SetEnvColor(0x8C, 0x90, 0x90, alpha2);
        Gfx_SetPrimColor(0xFF, 0xFF, 0xFF, alpha2);
        Font_SetActive(8, 0);

        if (node->bossTitle >= 0) {
            string = Text_GetString(NULL, 0, sUiText, node->bossTitle);
        } else {
            string = " ";
        }
        Font_Printf(430 - (Font_MeasureTextExtent(8, 0, string) / 2), 378, string);
        Font_SetActive(0x20, 0);

        if (node->fileNumber >= 30) {
            string = Text_GetString(NULL, 0, sTrainerNameText, node->fileNumber);
        } else if (node->fileNumber >= 0) {
            string = Text_GetString(NULL, 0, sUiText, node->fileNumber);
        } else {
            string = " ";
        }

        Font_Printf(430 - (Font_MeasureTextExtent(32, 0, string) / 2), 406, string);
        Font_DisableTwoCycleTexturing();
        Font_EndTexturedTextRendering();
    }
}

#if defined(VERSION_US_REV2)
// clang-format off
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/gym_leader_castle/gym_leader_castle/GymLeaderCastle_DrawEliteFourRoomInfoPanel.s")
// clang-format on
#else
void GymLeaderCastle_DrawEliteFourRoomInfoPanel(CastleMapNode* node, u8 alpha1, u8 alpha2) {
    char* string;

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, alpha1);

    GymLeaderCastle_DrawScaledTextureRgba(470, 318, 128, 26, 128, node->infoPanelTexture, 1.28f);
    GymLeaderCastle_DrawScaledTextureRgba(470, 344, 128, 26, 128, node->infoPanelTexture + 4000, 1.28f);
    GymLeaderCastle_DrawScaledTextureRgba(470, 370, 128, 26, 128, node->infoPanelTexture + 8000, 1.28f);
    GymLeaderCastle_DrawScaledTextureRgba(470, 396, 128, 26, 128, node->infoPanelTexture + 12000, 1.28f);
    GymLeaderCastle_DrawScaledTextureRgba(470, 422, 128, 26, 128, node->infoPanelTexture + 16000, 1.28f);

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, node->color.r, node->color.g, node->color.b, (alpha2 * 0x96) / 255);
    gDPLoadTextureBlock(gDisplayListHead++, D_300C290, G_IM_FMT_IA, G_IM_SIZ_16b, 16, 76, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(346, 372, 16, 76, 0, 0, 0x400, 0x400, 0);
    Gfx_DrawTexturedRectClipped(362, 372, 108, 76, 480, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_EnableTwoCycleTexturing();
    Gfx_SetEnvColor(0x8C, 0x90, 0x90, alpha2);
    Gfx_SetPrimColor(0xFF, 0xFF, 0xFF, alpha2);
    Font_SetActive(0x10, 0);

    if (node->fileNumber >= 30) {
        string = Text_GetString(NULL, 0, sTrainerNameText, node->fileNumber);
    } else if (node->fileNumber >= 0) {
        string = Text_GetString(NULL, 0, sUiText, node->fileNumber);
    } else {
        string = " ";
    }

    Font_Printf(408 - (Font_MeasureTextExtent(16, 0, string) / 2), 406, string);
    Font_DisableTwoCycleTexturing();
    Font_EndTexturedTextRendering();
}
#endif

void GymLeaderCastle_UpdateRoomInfoPanelFade(void) {
    u8 var_sp1F;

    if (D_84A030E8 > 0) {
        if (D_84A030E8 < 0xFF) {
            if (sSelectedMapNode == ELITE_4) {
                GymLeaderCastle_DrawEliteFourRoomInfoPanel(&sCastleMapNodes[sSelectedMapNode], D_84A030E8, D_84A030E8);
            } else {
                GymLeaderCastle_DrawGymLeaderInfoPanel(&sCastleMapNodes[sSelectedMapNode], D_84A030E8, D_84A030E8);
            }
        } else if (sCursorMoveTimer == 0) {
            if (sSelectedMapNode == ELITE_4) {
                GymLeaderCastle_DrawEliteFourRoomInfoPanel(&sCastleMapNodes[sSelectedMapNode], 0xFF, 0xFF);
            } else {
                GymLeaderCastle_DrawGymLeaderInfoPanel(&sCastleMapNodes[sSelectedMapNode], 0xFF, 0xFF);
            }
        } else {
            var_sp1F = ((sCursorMoveTimer * 0xFF) / 4) & 0xFF;
            if (sSelectedMapNode == ELITE_4) {
                GymLeaderCastle_DrawEliteFourRoomInfoPanel(&sCastleMapNodes[sSelectedMapNode], 0xFF, 0xFF - var_sp1F);
            } else {
                GymLeaderCastle_DrawGymLeaderInfoPanel(&sCastleMapNodes[sSelectedMapNode], 0xFF, 0xFF - var_sp1F);
            }

            if (sCurrentHoverNodeIndex == 10) {
                GymLeaderCastle_DrawEliteFourRoomInfoPanel(&sCastleMapNodes[sCurrentHoverNodeIndex], var_sp1F,
                                                           var_sp1F);
            } else {
                GymLeaderCastle_DrawGymLeaderInfoPanel(&sCastleMapNodes[sCurrentHoverNodeIndex], var_sp1F, var_sp1F);
            }
        }
    }
}

void GymLeaderCastle_UpdateMapCursor(void) {
    s16 x;
    s16 y;
    CastleMapNode* node = &sCastleMapNodes[sSelectedMapNode];

    if (sCursorMoveTimer == 0) {
        x = node->cursorX - 0x20;
        y = node->cursorY - 13;
    } else {
        x = ((((sCastleMapNodes[sCurrentHoverNodeIndex].cursorX - node->cursorX) * sCursorMoveTimer) / 4) +
             node->cursorX) -
            0x20;
        y = ((((sCastleMapNodes[sCurrentHoverNodeIndex].cursorY - node->cursorY) * sCursorMoveTimer) / 4) +
             node->cursorY) -
            13;

        sCursorMoveTimer--;
        if ((sCursorMoveTimer == 0) && ((sSelectedMapNode == GLC_TO_ELITE_4) || (sSelectedMapNode == ELITE_4_TO_GLC))) {
            StageContext_SetClearColor(1);
            StageFade_StartFromTransparent(8);
        }
    }

    Ui_DrawAnimatedTextureMarker(x - 3, y);
}

void GymLeaderCastle_Draw(void) {
    BgStage_DrawFrame();

    if (sSelectedMapNode < ELITE_4_TO_GLC) {
        if (sEliteFourTransition == 0) {
            Gfx_DrawTiledRgba16Image(sGymLeaderCastleTexture);
        } else if (sEliteFourTransition == 0xFF) {
            Gfx_DrawTiledRgba16Image(sEliteFourTexture);
        } else {
            GymLeaderCastle_DrawBackgroundCrossFade(sGymLeaderCastleTexture, sEliteFourTexture, sEliteFourTransition);
            if (sEliteFourTransition < 0xFF) {
                sEliteFourTransition += 5;
            }
        }
    } else {
        Gfx_DrawTiledRgba16Image(D_84A0317C);
        sEliteFourTransition = 0xFF;
    }

    if (gSessionContext.inRound2 == 1) {
        gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

        Gfx_DrawTextureRgba16(556, 40, 36, 36, D_3019C38, 36, 0);

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
    }

    GymLeaderCastle_DrawRoomMarkers();
    GymLeaderCastle_DrawRoomLabels();
    GymLeaderCastle_UpdateRoomInfoPanelFade();
    GymLeaderCastle_UpdateMapCursor();
    GymLeaderCastle_DrawTrainerIntroPanels();
    GymLeaderCastle_DrawMapBorder();
    GymLeaderCastle_DrawRoomDescription();
    BgStage_AdvanceFrame();
}

s32 func_84A02074(void) {
    return 0;
}

s32 GymLeaderCastle_SelectRoom(void) {
    s16 auto_advance_timer;
    s16 node_to_move_to;
    s16 changed;
    CastleMapNode* node;

    auto_advance_timer = 30;
    changed = 2;

    while (changed == 2) {
        node_to_move_to = -1;
        node = &sCastleMapNodes[sSelectedMapNode];

        Controller_PollInputs();

        if (func_84A02074() == 0) {
            if (StageContext_GetFadeMode() == 0) {
                if (sCursorMoveTimer == 0) {
                    sCurrentHoverNodeIndex = sSelectedMapNode;
                    if (sSelectedMapNode == CHAMPION) {
                        auto_advance_timer--;
                        if (auto_advance_timer == 0) {
                            changed = 3;
                        }
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
                        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                        changed = 3;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
                        Audio_PlaySoundEffectById(SFX_MENU_BACK);
                        if (node->index >= 10) {
                            sSelectedMapNode = 9;
                            sCursorMoveTimer = 3;
                        } else {
                            changed = 1;
                        }
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP) && (node->upNeighbor != 0)) {
                        node_to_move_to = node->upNeighbor - 1;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN) && (node->downNeighbor != 0)) {
                        node_to_move_to = node->downNeighbor - 1;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT) && (node->leftNeighbor != 0)) {
                        node_to_move_to = node->leftNeighbor - 1;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT) && (node->rightNeighbor != 0)) {
                        node_to_move_to = node->rightNeighbor - 1;
                    }

                    if ((node_to_move_to >= 0) && (sCastleMapNodes[node_to_move_to].nodeState != 0)) {
                        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
                        sSelectedMapNode = node_to_move_to;
                        sCursorMoveTimer = 3;
                    }
                }
            } else if (StageContext_GetFadeMode() == 1) {
                if (sSelectedMapNode == GLC_TO_ELITE_4) {
                    sSelectedMapNode = ELITE_4;
                }

                if (sSelectedMapNode == ELITE_4_TO_GLC) {
                    sSelectedMapNode = GIOVANNI;
                }
                StageFade_StartFromOpaque(8);
            }
        }
        GymLeaderCastle_Draw();
    }
    return changed;
}

void GymLeaderCastle_LoadTrainerPanels(void) {
    s32 i;
    s32 trainer_file_index;
    s32 trainer_count;
    TrainerData* trainer_data;
    s32 portrait_file_index;

    if (sSelectedMapNode == CHAMPION) {
        trainer_count = 1;
    } else {
        trainer_count = 4;
    }

    if (sSelectedMapNode < GLC_TO_ELITE_4) {
        trainer_file_index = sSelectedMapNode + 12;
    } else {
        trainer_file_index = sSelectedMapNode + 10;
    }

    if (gSessionContext.inRound2 != 0) {
        trainer_file_index += 0x1F;
    }

    trainer_data = BinArchive_GetFile(sTrainerDataArchive, trainer_file_index);

    for (i = 0; i < trainer_count; i++) {
        portrait_file_index = (trainer_data[i].gfx_file_index >> 8) & 0xFF;
        sCurrentNodeTrainers[i].loaded = 1;
        sCurrentNodeTrainers[i].portraitX = 640;
        sCurrentNodeTrainers[i].name = trainer_data[i].name1;
        sCurrentNodeTrainers[i].portrait = BinArchive_GetFile(sPortraitArchive, portrait_file_index);
    }
}

void GymLeaderCastle_ClearTrainerPanels(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        sCurrentNodeTrainers[i].loaded = 0;
    }
}

void GymLeaderCastle_SlideTrainerPanels(s16 panels_start, s16 panels_end, s16 timer, s16 x_delta) {
    s32 i;

    while (timer-- > 0) {
        for (i = panels_start; i <= panels_end; i++) {
            sCurrentNodeTrainers[i].portraitX += x_delta;
        }
        Controller_PollInputs();
        GymLeaderCastle_Draw();
    }
}

s32 GymLeaderCastle_ShowIntro(void) {
    s16 i;
    s32 in_elite_four_challenge;
    s32 intro_choice = 0;

    main_pool_push_state('itro');

    GymLeaderCastle_LoadTrainerPanels();
    Audio_StopMusic(8);

    for (i = 3; i >= 0; i--) {
        D_84A030E8 = i << 6;
        Controller_PollInputs();
        GymLeaderCastle_Draw();
    }

    Audio_PlayMusicIfChanged(43);
    if (sSelectedMapNode == CHAMPION) {
        GymLeaderCastle_SlideTrainerPanels(0, 0, 6, -0x40);
    } else {
        GymLeaderCastle_SlideTrainerPanels(0, 3, 3, -0x40);
        GymLeaderCastle_SlideTrainerPanels(0, 2, 2, -0x40);
        GymLeaderCastle_SlideTrainerPanels(0, 1, 2, -0x40);
        GymLeaderCastle_SlideTrainerPanels(0, 0, 2, -0x40);
    }

    while (intro_choice == 0) {
        Controller_PollInputs();
        GymLeaderCastle_Draw();
        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            intro_choice = 1;
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            if (sSelectedMapNode == CHAMPION) {
                intro_choice = 1;
            } else {
                intro_choice = 2;
            }
        }
    }

    if (intro_choice == 1) {
        Audio_PlaySoundEffectById(28);
        in_elite_four_challenge = 0;
        if (sSelectedMapNode == CHAMPION) {
            GymLeaderCastle_SlideTrainerPanels(0, 0, 6, -0x40);
        } else {
            GymLeaderCastle_SlideTrainerPanels(3, 3, 2, -0x40);
            GymLeaderCastle_SlideTrainerPanels(2, 3, 2, -0x40);
            GymLeaderCastle_SlideTrainerPanels(1, 3, 2, -0x40);
            GymLeaderCastle_SlideTrainerPanels(0, 3, 3, -0x40);
        }
        GymLeaderCastle_ClearTrainerPanels();
        GymLeaderCastle_Draw();
    } else {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        in_elite_four_challenge = 2;
        Audio_StopMusic(18);
        if (sSelectedMapNode == CHAMPION) {
            GymLeaderCastle_SlideTrainerPanels(0, 0, 6, 0x40);
        } else {
            GymLeaderCastle_SlideTrainerPanels(0, 0, 2, 0x40);
            GymLeaderCastle_SlideTrainerPanels(0, 1, 2, 0x40);
            GymLeaderCastle_SlideTrainerPanels(0, 2, 2, 0x40);
            GymLeaderCastle_SlideTrainerPanels(0, 3, 3, 0x40);
        }
        GymLeaderCastle_ClearTrainerPanels();

        if (D_84A03180.castleClears < 8) {
            Audio_PlayMusicIfChanged(42);
        } else {
            Audio_PlayMusicIfChanged(39);
        }

        for (i = 1; i < 5; i++) {
            D_84A030E8 = (i << 6) - 1;
            Controller_PollInputs();
            GymLeaderCastle_Draw();
        }
    }

    main_pool_pop_state('itro');

    return in_elite_four_challenge;
}

s32 GymLeaderCastle_AdvanceRoom(void) {
    s16 i;

    if (gSessionContext.modeSelection == 7) {
        Audio_PlayCategory11SoundCommand(0x01100015, 0, 0);
        sEliteFourTransition = 5;
    }

    for (i = 1; i < 5; i++) {
        sRoomDescriptionHeight = i * 20;
        Controller_PollInputs();
        GymLeaderCastle_Draw();
    }

    do {
        Controller_PollInputs();
        GymLeaderCastle_Draw();
    } while (!BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B));

    Audio_PlaySoundEffectById(0x01100011);

    if (gSessionContext.modeSelection == 8) {
        sCastleMapNodes[11].nodeState = 60;
    } else {
        sCastleMapNodes[D_84A03180.castleClears].nodeState = 60;
    }

    if (D_84A03180.castleClears == 8) {
        sCastleMapNodes[9].nodeState = 60;
        sCastleMapNodes[10].nodeState = 60;
    }

    for (i = 3; i >= 0; i--) {
        sRoomDescriptionHeight = i * 20;
        Controller_PollInputs();
        GymLeaderCastle_Draw();
    }

    sCurrentHoverNodeIndex = sSelectedMapNode;
    sSelectedMapNode += 1;
    sCursorMoveTimer = 3;
    return 2;
}

s16 GymLeaderCastle_RunMenu(s16 action) {
    s16 i;

    if (StageContext_GetFadeMode() == 1) {
        StageFade_StartFromOpaque(8);
        for (i = 0; i < 9; i++) {
            Controller_PollInputs();
            GymLeaderCastle_Draw();
        }
    }

    while ((action != 0) && (action != 1)) {
        switch (action) {
            case 2:
                action = GymLeaderCastle_SelectRoom();
                break;

            case 3:
                action = GymLeaderCastle_ShowIntro();
                break;

            case 4:
                action = GymLeaderCastle_AdvanceRoom();
                break;
        }
    }

    gSessionContext.roundOrDemoId = 1;
    if (sSelectedMapNode < GLC_TO_ELITE_4) {
        gSessionContext.modeSelection = sSelectedMapNode;
    } else {
        gSessionContext.modeSelection = sSelectedMapNode - 2;
    }
    return action;
}

s16 GymLeaderCastle_InitMenu(s16 arg0) {
    s16 i;
    s16 var_sp2C = 2;
    s16 var_v1 = D_84A03180.castleClears;

    if (gSessionContext.modeSelection < 8) {
        sSelectedMapNode = gSessionContext.modeSelection;
    } else {
        sSelectedMapNode = gSessionContext.modeSelection + 2;
    }

    if (arg0 == 1) {
        var_sp2C = 4;
        if (gSessionContext.modeSelection < 8) {
            var_v1--;
        }
    }

    if (var_v1 >= 8) {
        sEliteFourTransition = 0xFF;
    } else {
        sEliteFourTransition = 0;
    }

    for (i = 0; i <= var_v1; i++) {
        sCastleMapNodes[i].nodeState = 1;
    }

    if (sCastleMapNodes[8].nodeState != 0) {
        sCastleMapNodes[9].nodeState = 1;
        sCastleMapNodes[10].nodeState = 1;
    }

    for (i = 0; i < 4; i++) {
        sCurrentNodeTrainers[i].loaded = 0;
    }

    for (i = 0; i < 8; i++) {
        sCastleMapNodes[i].infoPanelTexture = BinArchive_GetFile(sPortraitArchive, i + 2);
    }

    sCastleMapNodes[10].infoPanelTexture = D_300CC10;
    sCastleMapNodes[11].infoPanelTexture = BinArchive_GetFile(sPortraitArchive, 14);
    return var_sp2C;
}

s32 GymLeaderCastle_Main(s32 arg0, UNUSED s32 arg1) {
    s16 var_sp1E;

    main_pool_push_state('PNLV');

    Font_Init(60, 0);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, gym_leader_castle_ui, 0);
    Text_InitStringTables();
    sUiText = Text_GetStringTable(25);
    sTrainerNameText = Text_GetStringTable(34);
    Save_EnsureBankLoaded(2);
    Save_GetModeSettings(&D_84A03180, gSessionContext.inRound2);
    sTrainerDataArchive = BinArchive_Open(TRAINER_DATA_ROM_START, NULL, 1, 1);
    sPortraitArchive = ASSET_LOAD2(battle_portraits, 1, 1);
    sBackgroundArchive = ASSET_LOAD2(backgrounds, 1, 1);
    sGymLeaderCastleTexture = BinArchive_GetFile(sBackgroundArchive, 13);
    sEliteFourTexture = BinArchive_GetFile(sBackgroundArchive, 0x10);
    D_84A0317C = BinArchive_GetFile(sBackgroundArchive, 14);
    StageLoader_UpdateSegments();

    var_sp1E = GymLeaderCastle_InitMenu(arg0);
    if (D_84A03180.castleClears < 8) {
        Audio_PlayMusicIfChanged(42);
    } else {
        Audio_PlayMusicIfChanged(39);
    }

    var_sp1E = GymLeaderCastle_RunMenu(var_sp1E);
    StageLoader_WaitForRetrace();
    Font_Free();

    main_pool_pop_state('PNLV');
    return var_sp1E == 0;
}
