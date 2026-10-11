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

static char** glc_text_ui;
static char** glc_text_trainer_names;
static Glc_Trainer current_node_trainers[4];
static BinArchive* trainer_data_archive;
static BinArchive* portrait_archive;
static BinArchive* background_archive ;
static u8* gym_leader_castle_texture;
static u8* elite_four_texture;
static u8* D_84A0317C;
static ModeSettings D_84A03180;
static s16 current_hover_node_index;

#define CHAMPION 0xB
#define ELITE_4 0xA
#define ELITE_4_TO_GLC 9
#define GLC_TO_ELITE_4 8
#define GIOVANNI 7

static CastleMapNode castle_map_nodes[] = {
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
        0x05,      0x00, 164, 178,  160, 170, 116, 96, 48, 70, -32768, 7, 5, 0, 7, { 0xCD, 0x91, 0x00, 0x00 },
        D_30041A0, 5,    35,  NULL,
    },
    {
        0x06,      0x00, 284, 148,  290, 138, 250, 78, 48, 70, -32768, 0, 8, 6, 8, { 0xFF, 0x00, 0x00, 0x00 },
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
        0x09,      0x00, 190, 384,  174, 424, 180, 394, 40, 27, -32768, 0, 0, 0, 0, { 0xFF, 0x64, 0x00, 0x00 },
        D_3008E50, -1,   9,   NULL,
    },
    {
        0x0A,      0x00, 446, 216,  374, 210, 356, 128, 72, 43, -32768, 12, 10, 10, 0, { 0xFF, 0x64, 0x00, 0x00 },
        D_3007620, 10,   10,  NULL,
    },
    {
        0x0B,      0x00, 0,  0,    312, 148, 274, 68, 72, 43, -32768, 0, 11, 0, 0, { 0x00, 0x64, 0xC8, 0x00 },
        D_3008238, -1,   11, NULL,
    },
};

static s16 selected_map_node = 0;
static s16 cursor_move_timer = 0;
static s16 D_84A030E8 = 0xFF;
static s16 room_description_height = 0;
static s16 glc_to_e4_transition = 0;

void Glc_DrawBackgroundCrossFade(u8* fade_in_texture, u8* fade_out_texture, u8 alpha) {
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

void Glc_DrawScaledTextureRgba(s16 x_start, s16 y_start, s16 draw_width, s16 height, s16 load_width, u8* texture, f32 scale) {
    UNUSED s32 pad;

    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, (s32)(load_width / scale), (s32)(height / scale),
                        0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(x_start, y_start, draw_width, height, 0, 0, 1024.0f / scale, 1024.0f / scale, 0);
}

void func_84A00630(void) {
}

void Glc_DrawScaledTextureIa8(s16 x_start, s16 y_start, s16 width, s16 height, u8* texture, f32 scale) {
    UNUSED s32 pad;

    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_IA, G_IM_SIZ_8b, (s32)(width / scale), (s32)(height / scale), 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(x_start, y_start, width, height, 0, 0, 1024.0f / scale, 1024.0f / scale, 0);
}

void Glc_DrawRoomDescription(void) {
    char sp40[0x100];
    UNUSED s32 pad2;
    s16 y1;
    UNUSED s32 pad;
    s16 current_node_file_number;

    if (room_description_height >= 0x10) {
        y1 = 240 - (room_description_height / 2);
        Ui_DrawBorderedPanelNoFill(120, y1, 400, room_description_height);
        Gfx_FillRectWithDisplayState(127, y1 + 7, 386, room_description_height - 14, 0x14, 0x32, 0x64, 0x96);

        if (room_description_height == 0x50) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(8, 0);
            Font_SetLineHeight(24);

            if (selected_map_node == GIOVANNI) {
                Font_Printf(136, y1 + 16, Text_GetString(NULL, 0, glc_text_ui, 0xC));
            } else if (selected_map_node == ELITE_4) {
                Font_Printf(136, y1 + 16, Text_GetString(NULL, 0, glc_text_ui, 0xD));
            } else {
                current_node_file_number = castle_map_nodes[selected_map_node].file_number;
                if (current_node_file_number >= 0x1E) {
                    Text_SetStringToken(0x24, Text_GetString(NULL, 0, glc_text_trainer_names, current_node_file_number));
                } else if (current_node_file_number >= 0) {
                    Text_SetStringToken(0x24, Text_GetString(NULL, 0, glc_text_ui, current_node_file_number));
                } else {
                    Text_SetStringToken(0x24, " ");
                }

                current_node_file_number = castle_map_nodes[selected_map_node + 1].file_number;
                if (current_node_file_number >= 0x1E) {
                    Text_SetStringToken(0x29, Text_GetString(NULL, 0, glc_text_trainer_names, current_node_file_number));
                } else if (current_node_file_number >= 0) {
                    Text_SetStringToken(0x29, Text_GetString(NULL, 0, glc_text_ui, current_node_file_number));
                } else {
                    Text_SetStringToken(0x29, " ");
                }
                Font_Printf(0x88, y1 + 0x10, Text_GetString(sp40, sizeof(sp40), glc_text_ui, 0xE));
            }
            Font_EndTexturedTextRendering();
        }
    }
}

void Glc_DrawTrainerIntroPanels(void) {
    UNUSED s32 pad[3];
    s32 i;
    char* boss_title;
    CastleMapNode* hovered_map_node = &castle_map_nodes[selected_map_node];

    for (i = 0; i < 4; i++) {
        if (current_node_trainers[i].loaded != 0) {
            s16 trainer_portrait_x = current_node_trainers[i].portrait_x;

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            Glc_DrawScaledTextureRgba(trainer_portrait_x, 240, 128, 64, 128, D_3009290, 2.0f);
            Glc_DrawScaledTextureRgba(trainer_portrait_x, 304, 128, 64, 128, D_300A290, 2.0f);
            Glc_DrawScaledTextureRgba(trainer_portrait_x, 368, 128, 64, 128, D_300B290, 2.0f);
            Glc_DrawScaledTextureRgba(trainer_portrait_x + 8, 312, 112, 56, 128, current_node_trainers[i].portrait + 0x208, 2.0f);
            Glc_DrawScaledTextureRgba(trainer_portrait_x + 8, 368, 112, 56, 128, current_node_trainers[i].portrait + 0x1008, 2.0f);

            gSPDisplayList(gDisplayListHead++, D_8006F630);

            Font_BeginTranslucentTextRendering();
            // special titles for Gym leaders
            // Condition reads as "is the player in the Elite Four room OR is panel the gym leader's?"
            if ((selected_map_node >= GLC_TO_ELITE_4) || (i == 3)) {
                Font_SetActive(8, 0);

                if (hovered_map_node->boss_title >= 0) {
                    boss_title = Text_GetString(NULL, 0, glc_text_ui, hovered_map_node->boss_title);
                } else {
                    boss_title = " ";
                }

                Font_Printf((trainer_portrait_x - (Font_MeasureTextExtent(8, 0, boss_title) / 2)) + 64, 244, boss_title);
            }

            Font_SetActive(4, 0);

            if ((i == 3) && (selected_map_node < GLC_TO_ELITE_4)) {
                Font_Printf(trainer_portrait_x + 8, 268, Text_GetString(NULL, 0, glc_text_ui, 8));
            } else {
                Font_Printf(trainer_portrait_x + 8, 268, Text_GetString(NULL, 0, glc_text_ui, 0xF));
            }

            Font_SetActive(0x10, 0);
            Font_Printf((trainer_portrait_x - (Font_MeasureTextExtent(0x10, 0, current_node_trainers[i].name) / 2)) + 64, 284,
                          current_node_trainers[i].name);
            Font_EndTexturedTextRendering();
        }
    }
}

void Glc_DrawMapBorder(void) {
    static s16 D_84A030F4 = 0;
    static s16 D_84A030F8 = 1;

    s16 i;
    s16 var_s1 = (D_84A030F4 / 4) + 0x22;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 9; i++) {
        Gfx_DrawTextureRgba16(0x24, var_s1, 0xE4, 8, D_3011A30 + i * 0xE40, 0xE4, 0);
        var_s1 += 8;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_84A030F4 += D_84A030F8;
    if (D_84A030F4 == 0) {
        D_84A030F8 = 1;
    }

    if (D_84A030F4 == 0x23) {
        D_84A030F8 = -1;
    }
}

void Glc_DrawRoomMarkers(void) {
    s32 i;
    s32 node_alpha;
    s32 backwards_index;
    CastleMapNode* node;

    if (selected_map_node < ELITE_4_TO_GLC) {
        node = &castle_map_nodes[0];
        backwards_index = 9;
    } else {
        node = &castle_map_nodes[9];
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
        if (node->node_state != 0) {
            node_alpha = 0xFF;
            if (node->node_state == 1) {
                node_alpha = (s32)((COSS(node->pulsing) + 1.0f) * 96.0f);
                node_alpha += 63;
                node->pulsing += 0x200;
            } else {
                node->pulsing = 0;
                node->node_state--;
            }

            gDPSetEnvColor(gDisplayListHead++, node->color.r, node->color.g, node->color.b, node_alpha);

            if (node->index == 9) {
                gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 0, 255);
            } else {
                gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
            }

            Glc_DrawScaledTextureIa8(node->marker_x, node->marker_y, node->marker_width * 2, node->marker_height * 2, node->texture, 2.0f);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Glc_DrawRoomLabels(void) {
    s32 backwards_index;
    char* label;
    CastleMapNode* node;
    s16 tmp;

    if (selected_map_node < ELITE_4_TO_GLC) {
        node = &castle_map_nodes[0];
        backwards_index = 8;
    } else {
        node = &castle_map_nodes[9];
        backwards_index = 3;
    }

    Font_BeginTranslucentTextRendering();
    Font_EnableTwoCycleTexturing();
    Font_SetActive(4, 0);
    Gfx_SetPrimColor(0x50, 0x64, 0xDC, 0xFF);

    for (; backwards_index > 0; backwards_index--, node++) {
        if (node->node_state != 0) {
            if (node->file_number >= 0x1E) {
                label = Text_GetString(NULL, 0, glc_text_trainer_names, node->file_number);
            } else if (node->file_number >= 0) {
                label = Text_GetString(NULL, 0, glc_text_ui, node->file_number);
            } else {
                label = " ";
            }
            tmp = node->label_x - (Font_MeasureTextExtent(4, 0, label) / 2);
            Font_Printf(tmp, node->label_y, label);
        }
    }

    Font_DisableTwoCycleTexturing();
    Font_EndTexturedTextRendering();
}

void Glc_DrawGymLeaderInfoPanel(CastleMapNode* node, u8 alpha1, u8 alpha2) {
    char* string;

    if (node->info_panel_texture != NULL) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, alpha1);

        Glc_DrawScaledTextureRgba(502, 352, 96, 48, 96, node->info_panel_texture, 1.5f);
        Glc_DrawScaledTextureRgba(502, 400, 96, 48, 96, node->info_panel_texture + 0x1000, 1.5f);

        gSPDisplayList(gDisplayListHead++, D_8006F558);
        gDPSetEnvColor(gDisplayListHead++, node->color.r, node->color.g, node->color.b, (alpha2 * 0x96) / 255);

        Gfx_DrawTextureIa16(358, 372, 16, 76, D_300C290, 0x10, 0);
        Gfx_DrawTexturedRectClipped(374, 372, 128, 76, 480, 0, 0, 0x400, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        Font_BeginTranslucentTextRendering();
        Font_EnableTwoCycleTexturing();
        Gfx_SetEnvColor(0x8C, 0x90, 0x90, alpha2);
        Gfx_SetPrimColor(0xFF, 0xFF, 0xFF, alpha2);
        Font_SetActive(8, 0);

        if (node->boss_title >= 0) {
            string = Text_GetString(NULL, 0, glc_text_ui, node->boss_title);
        } else {
            string = " ";
        }
        Font_Printf(430 - (Font_MeasureTextExtent(8, 0, string) / 2), 378, string);
        Font_SetActive(0x20, 0);

        if (node->file_number >= 0x1E) {
            string = Text_GetString(NULL, 0, glc_text_trainer_names, node->file_number);
        } else if (node->file_number >= 0) {
            string = Text_GetString(NULL, 0, glc_text_ui, node->file_number);
        } else {
            string = " ";
        }

        Font_Printf(430 - (Font_MeasureTextExtent(32, 0, string) / 2), 0x196, string);
        Font_DisableTwoCycleTexturing();
        Font_EndTexturedTextRendering();
    }
}

void Glc_DrawEliteFourRoomInfoPanel(CastleMapNode* node, u8 alpha1, u8 alpha2) {
    char* string;

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, alpha1);

    Glc_DrawScaledTextureRgba(470, 318, 128, 26, 128, node->info_panel_texture, 1.28f);
    Glc_DrawScaledTextureRgba(470, 344, 128, 26, 128, node->info_panel_texture + 0xFA0, 1.28f);
    Glc_DrawScaledTextureRgba(470, 370, 128, 26, 128, node->info_panel_texture + 0x1F40, 1.28f);
    Glc_DrawScaledTextureRgba(470, 396, 128, 26, 128, node->info_panel_texture + 0x2EE0, 1.28f);
    Glc_DrawScaledTextureRgba(470, 422, 128, 26, 128, node->info_panel_texture + 0x3E80, 1.28f);

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, node->color.r, node->color.g, node->color.b, (alpha2 * 0x96) / 255);
    gDPLoadTextureBlock(gDisplayListHead++, D_300C290, G_IM_FMT_IA, G_IM_SIZ_16b, 16, 76, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(346, 372, 16, 76, 0, 0, 0x400, 0x400, 0);
    Gfx_DrawTexturedRectClipped(362, 0x174, 108, 76, 480, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_EnableTwoCycleTexturing();
    Gfx_SetEnvColor(0x8C, 0x90, 0x90, alpha2);
    Gfx_SetPrimColor(0xFF, 0xFF, 0xFF, alpha2);
    Font_SetActive(0x10, 0);

    if (node->file_number >= 0x1E) {
        string = Text_GetString(NULL, 0, glc_text_trainer_names, node->file_number);
    } else if (node->file_number >= 0) {
        string = Text_GetString(NULL, 0, glc_text_ui, node->file_number);
    } else {
        string = " ";
    }

    Font_Printf(408 - (Font_MeasureTextExtent(16, 0, string) / 2), 406, string);
    Font_DisableTwoCycleTexturing();
    Font_EndTexturedTextRendering();
}

void Glc_UpdateRoomInfoPanelFade(void) {
    u8 sp1F;

    if (D_84A030E8 > 0) {
        if (D_84A030E8 < 0xFF) {
            if (selected_map_node == ELITE_4) {
                Glc_DrawEliteFourRoomInfoPanel(&castle_map_nodes[selected_map_node], D_84A030E8, D_84A030E8);
            } else {
                Glc_DrawGymLeaderInfoPanel(&castle_map_nodes[selected_map_node], D_84A030E8, D_84A030E8);
            }
        } else if (cursor_move_timer == 0) {
            if (selected_map_node == ELITE_4) {
                Glc_DrawEliteFourRoomInfoPanel(&castle_map_nodes[selected_map_node], 0xFF, 0xFF);
            } else {
                Glc_DrawGymLeaderInfoPanel(&castle_map_nodes[selected_map_node], 0xFF, 0xFF);
            }
        } else {
            sp1F = ((cursor_move_timer * 0xFF) / 4) & 0xFF;
            if (selected_map_node == ELITE_4) {
                Glc_DrawEliteFourRoomInfoPanel(&castle_map_nodes[selected_map_node], 0xFF, 0xFF - sp1F);
            } else {
                Glc_DrawGymLeaderInfoPanel(&castle_map_nodes[selected_map_node], 0xFF, 0xFF - sp1F);
            }

            if (current_hover_node_index == 0xA) {
                Glc_DrawEliteFourRoomInfoPanel(&castle_map_nodes[current_hover_node_index], sp1F, sp1F);
            } else {
                Glc_DrawGymLeaderInfoPanel(&castle_map_nodes[current_hover_node_index], sp1F, sp1F);
            }
        }
    }
}

void Glc_UpdateMapCursor(void) {
    s16 x;
    s16 y;
    CastleMapNode* node = &castle_map_nodes[selected_map_node];

    if (cursor_move_timer == 0) {
        x = node->cursor_x - 0x20;
        y = node->cursor_y - 0xD;
    } else {
        x = ((((castle_map_nodes[current_hover_node_index].cursor_x - node->cursor_x) * cursor_move_timer) / 4) + node->cursor_x) - 0x20;
        y = ((((castle_map_nodes[current_hover_node_index].cursor_y - node->cursor_y) * cursor_move_timer) / 4) + node->cursor_y) - 0xD;

        cursor_move_timer--;
        if ((cursor_move_timer == 0) && ((selected_map_node == GLC_TO_ELITE_4) || (selected_map_node == ELITE_4_TO_GLC))) {
            StageContext_SetClearColor(1);
            StageFade_StartFromTransparent(8);
        }
    }

    Ui_DrawAnimatedTextureMarker(x - 3, y);
}

void Glc_Draw(void) {
    BgStage_DrawFrame();

    if (selected_map_node < ELITE_4_TO_GLC) {
        if (glc_to_e4_transition == 0) {
            Gfx_DrawTiledRgba16Image(gym_leader_castle_texture);
        } else if (glc_to_e4_transition == 0xFF) {
            Gfx_DrawTiledRgba16Image(elite_four_texture);
        } else {
            Glc_DrawBackgroundCrossFade(gym_leader_castle_texture, elite_four_texture, glc_to_e4_transition);
            if (glc_to_e4_transition < 0xFF) {
                glc_to_e4_transition += 5;
            }
        }
    } else {
        Gfx_DrawTiledRgba16Image(D_84A0317C);
        glc_to_e4_transition = 0xFF;
    }

    if (D_800AE540.unk_11F2 == 1) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);

        Gfx_DrawTextureRgba16(0x22C, 0x28, 0x24, 0x24, D_3019C38, 0x24, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }

    Glc_DrawRoomMarkers();
    Glc_DrawRoomLabels();
    Glc_UpdateRoomInfoPanelFade();
    Glc_UpdateMapCursor();
    Glc_DrawTrainerIntroPanels();
    Glc_DrawMapBorder();
    Glc_DrawRoomDescription();
    BgStage_AdvanceFrame();
}

s32 func_84A02074(void) {
    return 0;
}

s32 Glc_SelectRoom(void) {
    s16 auto_advance_timer;
    s16 node_to_move_to;
    s16 changed;
    CastleMapNode* node;

    auto_advance_timer = 30;
    changed = 2;

    while (changed == 2) {
        node_to_move_to = -1;
        node = &castle_map_nodes[selected_map_node];

        Controller_PollInputs();

        if (func_84A02074() == 0) {
            if (StageContext_GetFadeMode() == 0) {
                if (cursor_move_timer == 0) {
                    current_hover_node_index = selected_map_node;
                    if (selected_map_node == CHAMPION) {
                        auto_advance_timer--;
                        if (auto_advance_timer == 0) {
                            changed = 3;
                        }
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
                        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                        changed = 3;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
                        Audio_PlaySoundEffectById(SFX_MENU_BACK);
                        if (node->index >= 0xA) {
                            selected_map_node = 9;
                            cursor_move_timer = 3;
                        } else {
                            changed = 1;
                        }
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP) && (node->up_neighbour != 0)) {
                        node_to_move_to = node->up_neighbour - 1;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN) && (node->down_neighbour != 0)) {
                        node_to_move_to = node->down_neighbour - 1;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT) && (node->left_neighbour != 0)) {
                        node_to_move_to = node->left_neighbour - 1;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT) && (node->right_neighbour != 0)) {
                        node_to_move_to = node->right_neighbour - 1;
                    }

                    if ((node_to_move_to >= 0) && (castle_map_nodes[node_to_move_to].node_state != 0)) {
                        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
                        selected_map_node = node_to_move_to;
                        cursor_move_timer = 3;
                    }
                }
            } else if (StageContext_GetFadeMode() == 1) {
                if (selected_map_node == GLC_TO_ELITE_4) {
                    selected_map_node = ELITE_4;
                }

                if (selected_map_node == ELITE_4_TO_GLC) {
                    selected_map_node = GIOVANNI;
                }
                StageFade_StartFromOpaque(8);
            }
        }
        Glc_Draw();
    }
    return changed;
}

void Glc_LoadTrainerPanels(void) {
    s32 i;
    s32 trainer_file_index;
    s32 trainer_count;
    TrainerData* trainer_data;
    s32 portrait_file_index;

    if (selected_map_node == CHAMPION) {
        trainer_count = 1;
    } else {
        trainer_count = 4;
    }

    if (selected_map_node < GLC_TO_ELITE_4) {
        trainer_file_index = selected_map_node + 12;
    } else {
        trainer_file_index = selected_map_node + 10;
    }

    if (D_800AE540.unk_11F2 != 0) {
        trainer_file_index += 0x1F;
    }

    trainer_data = BinArchive_GetFile(trainer_data_archive, trainer_file_index);

    for (i = 0; i < trainer_count; i++) {
        portrait_file_index = (trainer_data[i].gfx_file_index >> 8) & 0xFF;
        current_node_trainers[i].loaded = 1;
        current_node_trainers[i].portrait_x = 0x280;
        current_node_trainers[i].name = trainer_data[i].name1;
        current_node_trainers[i].portrait = BinArchive_GetFile(portrait_archive, portrait_file_index);
    }
}

void Glc_ClearTrainerPanels(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        current_node_trainers[i].loaded = 0;
    }
}

void Glc_SlideTrainerPanels(s16 panels_start, s16 panels_end, s16 timer, s16 x_delta) {
    s32 i;

    while (timer-- > 0) {
        for (i = panels_start; i <= panels_end; i++) {
            current_node_trainers[i].portrait_x += x_delta;
        }
        Controller_PollInputs();
        Glc_Draw();
    }
}

s32 Glc_ShowIntro(void) {
    s16 i;
    s32 in_elite_four_challenge;
    s32 intro_choice= 0;

    main_pool_push_state('itro');

    Glc_LoadTrainerPanels();
    Audio_StopMusic(8);

    for (i = 3; i >= 0; i--) {
        D_84A030E8 = i << 6;
        Controller_PollInputs();
        Glc_Draw();
    }

    Audio_PlayMusicIfChanged(0x2B);
    if (selected_map_node == CHAMPION) {
        Glc_SlideTrainerPanels(0, 0, 6, -0x40);
    } else {
        Glc_SlideTrainerPanels(0, 3, 3, -0x40);
        Glc_SlideTrainerPanels(0, 2, 2, -0x40);
        Glc_SlideTrainerPanels(0, 1, 2, -0x40);
        Glc_SlideTrainerPanels(0, 0, 2, -0x40);
    }

    while (intro_choice == 0) {
        Controller_PollInputs();
        Glc_Draw();
        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            intro_choice= 1;
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            if (selected_map_node == CHAMPION) {
                intro_choice= 1;
            } else {
                intro_choice= 2;
            }
        }
    }

    if (intro_choice == 1) {
        Audio_PlaySoundEffectById(0x1C);
        in_elite_four_challenge = 0;
        if (selected_map_node == CHAMPION) {
            Glc_SlideTrainerPanels(0, 0, 6, -0x40);
        } else {
            Glc_SlideTrainerPanels(3, 3, 2, -0x40);
            Glc_SlideTrainerPanels(2, 3, 2, -0x40);
            Glc_SlideTrainerPanels(1, 3, 2, -0x40);
            Glc_SlideTrainerPanels(0, 3, 3, -0x40);
        }
        Glc_ClearTrainerPanels();
        Glc_Draw();
    } else {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        in_elite_four_challenge = 2;
        Audio_StopMusic(0x12);
        if (selected_map_node == CHAMPION) {
            Glc_SlideTrainerPanels(0, 0, 6, 0x40);
        } else {
            Glc_SlideTrainerPanels(0, 0, 2, 0x40);
            Glc_SlideTrainerPanels(0, 1, 2, 0x40);
            Glc_SlideTrainerPanels(0, 2, 2, 0x40);
            Glc_SlideTrainerPanels(0, 3, 3, 0x40);
        }
        Glc_ClearTrainerPanels();

        if (D_84A03180.unk_04 < 8) {
            Audio_PlayMusicIfChanged(0x2A);
        } else {
            Audio_PlayMusicIfChanged(0x27);
        }

        for (i = 1; i < 5; i++) {
            D_84A030E8 = (i << 6) - 1;
            Controller_PollInputs();
            Glc_Draw();
        }
    }

    main_pool_pop_state('itro');

    return in_elite_four_challenge;
}

s32 Glc_AdvanceRoom(void) {
    s16 i;

    if (D_800AE540.unk_0002 == 7) {
        Audio_PlayCategory11SoundCommand(0x01100015, 0, 0);
        glc_to_e4_transition = 5;
    }

    for (i = 1; i < 5; i++) {
        room_description_height = i * 0x14;
        Controller_PollInputs();
        Glc_Draw();
    }

    do {
        Controller_PollInputs();
        Glc_Draw();
    } while (!BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B));

    Audio_PlaySoundEffectById(0x01100011);

    if (D_800AE540.unk_0002 == 8) {
        castle_map_nodes[11].node_state = 0x3C;
    } else {
        castle_map_nodes[D_84A03180.unk_04].node_state = 0x3C;
    }

    if (D_84A03180.unk_04 == 8) {
        castle_map_nodes[9].node_state = 0x3C;
        castle_map_nodes[10].node_state = 0x3C;
    }

    for (i = 3; i >= 0; i--) {
        room_description_height = i * 0x14;
        Controller_PollInputs();
        Glc_Draw();
    }

    current_hover_node_index = selected_map_node;
    selected_map_node += 1;
    cursor_move_timer = 3;
    return 2;
}

s16 Glc_RunMenu(s16 action) {
    s16 i;

    if (StageContext_GetFadeMode() == 1) {
        StageFade_StartFromOpaque(8);
        for (i = 0; i < 9; i++) {
            Controller_PollInputs();
            Glc_Draw();
        }
    }

    while ((action != 0) && (action != 1)) {
        switch (action) {
            case 2:
                action = Glc_SelectRoom();
                break;

            case 3:
                action = Glc_ShowIntro();
                break;

            case 4:
                action = Glc_AdvanceRoom();
                break;
        }
    }

    D_800AE540.unk_0003 = 1;
    if (selected_map_node < GLC_TO_ELITE_4) {
        D_800AE540.unk_0002 = selected_map_node;
    } else {
        D_800AE540.unk_0002 = selected_map_node - 2;
    }
    return action;
}

s16 Glc_InitMenu(s16 arg0) {
    s16 i;
    s16 sp2C = 2;
    s16 var_v1 = D_84A03180.unk_04;

    if (D_800AE540.unk_0002 < 8) {
        selected_map_node = D_800AE540.unk_0002;
    } else {
        selected_map_node = D_800AE540.unk_0002 + 2;
    }

    if (arg0 == 1) {
        sp2C = 4;
        if (D_800AE540.unk_0002 < 8) {
            var_v1--;
        }
    }

    if (var_v1 >= 8) {
        glc_to_e4_transition = 0xFF;
    } else {
        glc_to_e4_transition = 0;
    }

    for (i = 0; i <= var_v1; i++) {
        castle_map_nodes[i].node_state = 1;
    }

    if (castle_map_nodes[8].node_state != 0) {
        castle_map_nodes[9].node_state = 1;
        castle_map_nodes[10].node_state = 1;
    }

    for (i = 0; i < 4; i++) {
        current_node_trainers[i].loaded = 0;
    }

    for (i = 0; i < 8; i++) {
        castle_map_nodes[i].info_panel_texture = BinArchive_GetFile(portrait_archive, i + 2);
    }

    castle_map_nodes[10].info_panel_texture = D_300CC10;
    castle_map_nodes[11].info_panel_texture = BinArchive_GetFile(portrait_archive, 0xE);
    return sp2C;
}

s32 GymLeaderCastle_Main(s32 arg0, UNUSED s32 arg1) {
    s16 sp1E;

    main_pool_push_state('PNLV');

    Font_Init(0x3C, 0);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, gym_leader_castle_ui, 0);
    Text_InitStringTables();
    glc_text_ui = Text_GetStringTable(0x19);
    glc_text_trainer_names = Text_GetStringTable(0x22);
    Save_EnsureBankLoaded(2);
    Save_GetModeSettings(&D_84A03180, D_800AE540.unk_11F2);
    trainer_data_archive = BinArchive_Open(0x898000, NULL, 1, 1);
    portrait_archive = ASSET_LOAD2(battle_portraits, 1, 1);
    background_archive  = ASSET_LOAD2(backgrounds, 1, 1);
    gym_leader_castle_texture = BinArchive_GetFile(background_archive , 0xD);
    elite_four_texture = BinArchive_GetFile(background_archive , 0x10);
    D_84A0317C = BinArchive_GetFile(background_archive , 0xE);
    StageLoader_UpdateSegments();

    sp1E = Glc_InitMenu(arg0);
    if (D_84A03180.unk_04 < 8) {
        Audio_PlayMusicIfChanged(0x2A);
    } else {
        Audio_PlayMusicIfChanged(0x27);
    }

    sp1E = Glc_RunMenu(sp1E);
    StageLoader_WaitForRetrace();
    Font_Free();

    main_pool_pop_state('PNLV');
    return sp1E == 0;
}
