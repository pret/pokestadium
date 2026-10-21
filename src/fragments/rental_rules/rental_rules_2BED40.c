#include "rental_rules.h"
#include "src/poke_icon.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/ui_graphics.h"
#include "src/save_data.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static s16 D_83003C80;
static s16 D_83003C82;
static u16 D_83003C84;
static BinArchive* D_83003C88;
static void* D_83003C8C;
static s16 D_83003C90;
static s16 D_83003C92;
static s16 D_83003C94;
static s32 D_83003C98;
static char* D_83003C9C;
static s16* D_83003CA0;
static s16 D_83003CA4;
static s16 D_83003CA6;
static char* sStadiumModeLabel;
static char* sFreeBattleModeLabel;
static char* sEventBattleModeLabel;
static char* sGymLeaderCastleModeLabel;
static char* sVsMewtwoModeLabel;
static char* sAnythingGoesLabel;
static char* sNintendoCup97Label;
static char* sNintendoCup98Label;
static char* sNintendoCup99Label;
static char* sPetitCupLabel;
static char* sPikaCupLabel;
static char* sPrimeCupLabel;
static char* sGymLeaderCastleLabel;
static char* sVsMewtwoLabel;
unk_D_83003CE0 D_83003CE0;
unk_D_83003CE0 D_83003DE0;

char** sBattleModeLabels = NULL;
static char** D_830039C4 = NULL;
static u8 D_830039C8[] = {
    6, 0x07, 0x08, 9, 10, 11, 12, 13, 0x0F,
};
static s16 D_830039D4[] = {
    0x0007, 0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 5, 6, 35, 0xFFFF,
};
static s16 D_830039E8[] = {
    0x0007, 0x0000, 0x0001, 29, 0x0003, 0x0004, 5, 9, 35, 0xFFFF,
};
static s16 D_830039FC[] = {
    0x0007, 0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 5, 35, 0xFFFF, 0x0000,
};
static s16 D_83003A10[] = {
    11, 0x0000, 0x0001, 10, 0x0004, 5, 6, 35, 0xFFFF, 0x0000,
};
static s16 D_83003A24[] = {
    11, 0x0000, 0x0001, 30, 0x0004, 5, 9, 35, 0xFFFF, 0x0000,
};
static s16 D_83003A38[] = {
    11,     0x0000, 0x0001, 10,     0x0004, 5,  35,     0xFFFF, 14,     0x0000, 0x0001, 12,     13,
    0x0004, 5,      6,      35,     0xFFFF, 14, 0x0000, 0x0001, 0x001F, 13,     0x0004, 5,      9,
    35,     0xFFFF, 14,     0x0000, 0x0001, 12, 13,     0x0004, 5,      35,     0xFFFF, 0x0000,
};
static s16 D_83003A84[] = {
    19, 0x0000, 0x0001, 0x000F, 0x0010, 17, 18, 0x0004, 5, 6, 35, 0xFFFF,
};
static s16 D_83003A9C[] = {
    19, 0x0000, 0x0001, 0x0020, 0x0010, 17, 18, 0x0004, 5, 9, 35, 0xFFFF,
};
static s16 D_83003AB4[] = {
    19, 0x0000, 0x0001, 0x000F, 0x0010, 17, 18, 0x0004, 5, 35, 0xFFFF, 0x0000,
};
static s16 D_83003ACC[] = {
    0x0000, 0x0001, 22, 23, 0x0004, 5, 6, 35, 0xFFFF, 0x0000,
};
static s16 D_83003AE0[] = {
    0x0000, 0x0001, 33, 23, 0x0004, 5, 9, 35, 0xFFFF, 0x0000,
};
static s16 D_83003AF4[] = {
    0x0000, 0x0001, 22, 23, 0x0004, 5, 35, 0xFFFF,
};
static s16 D_83003B04[] = {
    21, 0x0000, 0x0001, 36, 0x0004, 6, 35, 0xFFFF,
};
static s16 D_83003B14[] = {
    21, 0x0000, 0x0001, 20, 0x0004, 9, 35, 0xFFFF,
};
static s16 D_83003B24[] = {
    21, 0x0000, 0x0001, 20, 0x0004, 35, 0xFFFF, 0x0000,
};
static s16 D_83003B34[] = {
    21, 26, 20, 37, 34, 38, 35, 0xFFFF,
};
static s16 D_83003B44[] = {
    21, 0x0000, 0x0001, 20, 25, 0x0004, 35, 0xFFFF,
};
static s16 D_83003B54[] = {
    21, 28, 27, 20, 35, 0xFFFF,
};

char* RentalRules_GetPokemonName(s32 file_number) {
    return Text_GetString(NULL, 0, D_830039C4, file_number - 1);
}

void RentalRules_LoadBackgroundArchive(void) {
    ModeSettings var_sp20;

    if (gSessionContext.mode != 10) {
        D_83003C88 = BinArchive_Open(backgrounds_ROM_START, battle_headers_ROM_START, 1, 1);
        if (gSessionContext.mode == 7) {
            Save_EnsureBankLoaded(2);
            Save_GetModeSettings(&var_sp20, gSessionContext.inRound2);
            if (var_sp20.castleClears < 8) {
                D_83003C8C = BinArchive_GetFile(D_83003C88, 13);
            } else {
                D_83003C8C = BinArchive_GetFile(D_83003C88, 0x10);
            }
        } else {
            D_83003C8C = BinArchive_GetFile(D_83003C88, D_830039C8[gSessionContext.mode]);
        }
    }
}

void RentalRules_PollInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

s16* RentalRules_GetRuleIdList(SessionContext* session_context) {
    s16* var_v1 = NULL;

    switch (session_context->ruleCategory) {
        case 1:
            switch (session_context->mode) {
                case 1:
                    var_v1 = D_830039D4;
                    break;
                case 10:
                    var_v1 = D_830039E8;
                    break;
                case 0:
                    var_v1 = D_830039FC;
                    break;
            }
            break;

        case 2:
            switch (session_context->mode) {
                case 2:
                    var_v1 = D_83003A10;
                    break;
                case 10:
                    var_v1 = D_83003A24;
                    break;
                case 0:
                    var_v1 = D_83003A38;
                    break;
            }
            break;

        case 3:
            switch (session_context->mode) {
                case 3:
                    var_v1 = D_830039D4;
                    break;
                case 10:
                    var_v1 = D_830039E8;
                    break;
                case 0:
                    var_v1 = D_830039FC;
                    break;
            }
            break;

        case 4:
            switch (session_context->mode) {
                case 4:
                    var_v1 = D_83003A84;
                    break;
                case 10:
                    var_v1 = D_83003A9C;
                    break;
                case 0:
                    var_v1 = D_83003AB4;
                    break;
            }
            break;

        case 5:
            switch (session_context->mode) {
                case 5:
                    var_v1 = D_83003ACC;
                    break;
                case 10:
                    var_v1 = D_83003AE0;
                    break;
                case 0:
                    var_v1 = D_83003AF4;
                    break;
            }
            break;

        case 6:
            switch (session_context->mode) {
                case 6:
                    var_v1 = D_83003B04;
                    break;
                case 10:
                    var_v1 = D_83003B14;
                    break;
                case 0:
                    var_v1 = D_83003B24;
                    break;
            }
            break;

        case 0:
            switch (session_context->mode) {
                case 0:
                    var_v1 = D_83003B34;
                    break;
            }
            break;

        case 7:
            switch (session_context->mode) {
                case 7:
                    var_v1 = D_83003B44;
                    break;
            }
            break;

        case 8:
            switch (session_context->mode) {
                case 8:
                    var_v1 = D_83003B54;
                    break;
            }
            break;
    }

    return var_v1;
}

char* RentalRules_GetModeLabel(s8 arg0) {
    char* ret;

    switch (arg0) {
        case 0:
            ret = sFreeBattleModeLabel;
            break;

        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            ret = sStadiumModeLabel;
            break;

        case 7:
            ret = sGymLeaderCastleModeLabel;
            break;

        case 8:
            ret = sVsMewtwoModeLabel;
            break;

        case 10:
            ret = sEventBattleModeLabel;
            break;

        default:
            ret = NULL;
            break;
    }

    return ret;
}

char* RentalRules_GetCategoryLabel(s8 arg0) {
    char* label;

    switch (arg0) {
        case 0:
            label = sAnythingGoesLabel;
            break;

        case 1:
            label = sNintendoCup97Label;
            break;

        case 2:
            label = sNintendoCup98Label;
            break;

        case 3:
            label = sNintendoCup99Label;
            break;

        case 4:
            label = sPetitCupLabel;
            break;

        case 5:
            label = sPikaCupLabel;
            break;

        case 6:
            label = sPrimeCupLabel;
            break;

        case 7:
            label = sGymLeaderCastleLabel;
            break;

        case 8:
            label = sVsMewtwoLabel;
            break;

        default:
            label = NULL;
            break;
    }

    return label;
}

s32 RentalRules_RuleListHasEmptyEntry(s16* arg0) {
    s32 ret = 0;

    while (*arg0 != -1) {
        if (D_83003DE0.unk_00[*arg0] == '\x00') {
            ret = 1;
            break;
        }
        arg0++;
    }

    return ret;
}

void RentalRules_UpdateFadeIn(void) {
    s32 var_lo;

    D_83003C82--;

    D_83003C92 = var_lo = ((10 - D_83003C82) << 10) / 10;

    if (D_83003C84 & 4) {
        D_83003C94 = var_lo;
    }

    if (D_83003C82 <= 0) {
        D_83003C80 = 1;
        D_83003C90 = 2;
    }
}

void RentalRules_UpdateMainInput(void) {
    s16 tmp = D_83003CA6;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        D_83003CA6--;
        if (D_83003CA6 < 0) {
            D_83003CA6 = D_83003CA4 - 1;
        }
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        D_83003CA6++;
        if (D_83003CA6 >= D_83003CA4) {
            D_83003CA6 = 0;
        }
    }

    if (D_83003CA6 != tmp) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        D_83003C80 = 2;
        D_83003C82 = 0;

        if (D_83003DE0.unk_00[D_83003CA0[D_83003CA6]] != NULL) {
            RentalRules_PopupOpen(D_83003CA0[D_83003CA6]);
        } else {
            RentalRules_QualifyingSpeciesWindowOpen();
            Audio_PlaySoundEffectById(SFX_PANEL_OPEN);
        }

        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        D_83003C80 = 3;
        D_83003C82 = 10;
        D_83003C90 = -1;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
}

void RentalRules_UpdateWaitPopupClose(void) {
    if ((RentalRules_PopupIsActive() == 0) && (RentalRules_QualifyingSpeciesWindowIsActive() == 0)) {
        D_83003C80 = 1;
    }
}

void RentalRules_UpdateFadeOut(void) {
    s32 var_lo;

    D_83003C82--;
    var_lo = (D_83003C82 << 10) / 10;

    D_83003C92 = var_lo;
    if (D_83003C84 & 4) {
        D_83003C94 = var_lo;
    }

    if (D_83003C82 <= 0) {
        D_83003C80 = 4;
        D_83003C82 = 2;
        D_83003C90 = -1;
    }
}

s32 RentalRules_UpdateExitDelay(void) {
    s32 var_v1 = 0;

    D_83003C82--;
    if (D_83003C82 <= 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void RentalRules_DrawBackgroundFallback(void) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0,
                      ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 140, 190, 200, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 110, 160, 170, 255);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_302EBC0, G_IM_FMT_I, 128, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 7, 6, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(0, 0, 640, 480, 0, 0, 0x400, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void RentalRules_DrawHeaderBanner(void) {
    UNUSED s32 pad;
    s16 var_s1;
    s16 var_spD8;

    if (D_83003C94 == 0) {
        return;
    }

    var_s1 = (((-D_83003C94 * 0x10) + 0x4000) / 1024) + 40;
    var_spD8 = (D_83003C94 << 5) / 1024;

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, 100, 100, 200, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 40, 40, 140, 255);

    gDPLoadTextureBlock(gDisplayListHead++, D_20003C0, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(56, var_s1, 0x10, var_spD8, 0, 0, 1008, 0x8000 / var_spD8, 0);

    gDPLoadTextureBlock(gDisplayListHead++, D_20005C0, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(576, var_s1, 0x10, var_spD8, 0, 0, 0x400, 0x8000 / var_spD8, 0);
    Gfx_DrawTexturedRectClipped(72, var_s1, 504, var_spD8, 0, 0, 0, 0x8000 / var_spD8, 0);

    if (D_83003C94 < 0x400) {
        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
    } else {
        gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

        Gfx_DrawTextureRgba16(48, var_s1 - 8, 48, 24, D_2006C00, 48, 0);
        Gfx_DrawTextureRgba16(48, var_s1 + 0x10, 48, 24, D_2007500, 48, 0);

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

        Font_BeginTranslucentTextRendering();
        Font_SetActive(0x10, 0);

        if (D_83003C98 != 0) {
            char var_sp48[0x40];
            char* var_v0_21;

            Gfx_SetEnvColor(0, 0, 0, 0xFF);
            Text_SetStringToken(38, D_83003C98);
            var_v0_21 = Text_GetString(var_sp48, sizeof(var_sp48), sBattleModeLabels, 0);
            Font_Printf(106, var_s1 + 4, var_v0_21);
            Gfx_SetEnvColor(0xFF, 0xFF, 0x77, 0xFF);
            Font_Printf(104, var_s1 + 2, var_v0_21);
        }

        Font_EndTexturedTextRendering();
    }
}

void RentalRules_DrawWindowFrame(s16 left, s16 bottom, s16 arg2, s16 arg3) {
    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureIa8(left - 7, bottom - 7, 8, 8, D_2000340, 8, 0);
    Gfx_DrawTextureIa8((left + arg2) - 1, bottom - 7, 8, 8, D_2000380, 8, 0);
    Gfx_DrawTexturedRectClipped(left + 1, bottom - 7, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTextureIa8(left - 7, (bottom + arg3) - 1, 8, 8, D_20002C0, 8, 0);
    Gfx_DrawTexturedRectClipped(left - 7, bottom + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);
    Gfx_DrawTextureIa8((left + arg2) - 1, (bottom + arg3) - 1, 8, 8, D_2000300, 8, 0);
    Gfx_DrawTexturedRectClipped(left + 1, (bottom + arg3) - 1, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTexturedRectClipped((left + arg2) - 1, bottom + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void RentalRules_DrawFilledPanel(s16 x1, s16 y1, s16 width, s16 height, u8 r, u8 g, u8 b) {
    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, r, g, b, 255);

    Gfx_DrawTextureIa8(x1, y1, 8, 8, D_2000B40, 8, 0);
    Gfx_DrawTextureIa8((x1 + width) - 8, y1, 8, 8, D_2000B80, 8, 0);
    Gfx_DrawTexturedRectClipped(x1 + 8, y1, width - 16, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTextureIa8(x1, (y1 + height) - 8, 8, 8, D_2000BC0, 8, 0);
    Gfx_DrawTexturedRectClipped(x1, y1 + 8, 8, height - 16, 0, 0, 0x400, 0, 0);
    Gfx_DrawTextureIa8((x1 + width) - 8, (y1 + height) - 8, 8, 8, D_2000C00, 8, 0);
    Gfx_DrawTexturedRectClipped(x1 + 8, (y1 + height) - 8, width - 16, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTexturedRectClipped((x1 + width) - 8, y1 + 8, 8, height - 16, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, gUiTranslucentFillDL);

    Gfx_FillRectRgba(x1 + 8, y1 + 8, width - 16, height - 16, r, g, b, 0xFF);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void RentalRules_DrawBulletIcon(s16 x, s16 y) {
    gDPLoadTextureTile(gDisplayListHead++, D_4000C40, G_IM_FMT_IA, G_IM_SIZ_8b, 20, 0, 0, 0, 19, 19, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(x, y, 20, 20, 0, 0, 0x400, 0x400, 0);
}

void RentalRules_DrawRuleListText(s16 x, s16 y) {
    s16 tmp;
    s32 i;
    char var_sp48[0x40];

    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);

    if (D_83003C9C != NULL) {
        if (D_83003C9C != sAnythingGoesLabel) {
            Text_SetStringToken(39, D_83003C9C);
            Font_Printf(x + 16, y + 4, Text_GetString(var_sp48, sizeof(var_sp48), sBattleModeLabels, 1));
        } else {
            Font_Printf(x + 16, y + 4, D_83003C9C);
        }
    }

    Font_Printf(x + 48, y + 308, Text_GetString(NULL, 0, sBattleModeLabels, 2));
    Font_SetActive(8, 0);

    for (i = 0; i < D_83003CA4; i++) {
        if (i != D_83003CA6) {
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
        }
        tmp = D_83003CA0[i];
        Font_Printf(x + 84, y + 38 + i * 24, D_83003CE0.unk_00[tmp]);
    }
}

void RentalRules_DrawRuleListPanel(void) {
    static s16 D_83003B60 = 0;

    s32 i;
    s16 var_s3;
    s16 var_s2_2;

    if (D_83003C92 == 0) {
        return;
    }

    var_s3 = (((-D_83003C92 * 168) + 172032) / 1024) + 92;
    var_s2_2 = (D_83003C92 * 336) / 1024;
    RentalRules_DrawWindowFrame(56, var_s3, 528, var_s2_2);

    if (D_83003C92 >= 0x400) {
        RentalRules_DrawFilledPanel(56, var_s3, 528, 0x20, 0x3C, 0x3C, 0xA0);
        RentalRules_DrawFilledPanel(56, var_s3 + 0x20, 528, 272, 0x1E, 0x1E, 0x64);
        RentalRules_DrawFilledPanel(56, var_s3 + 304, 528, 0x20, 0x3C, 0x3C, 0xA0);
        if ((RentalRules_PopupGetProgress() == 0) && (RentalRules_GetSpeciesWindowOpeningProgress() == 0)) {
            s16 sins = SINS(D_83003B60) * 3.0f;

            Ui_DrawTextureMarker(sins + 72, var_s3 + (D_83003CA6 * 24) + 42);
            D_83003B60 += 0x1000;
        }

        gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

        Gfx_DrawTextureRgba16(72, var_s3 + 306, 28, 28, D_04000000, 28, 0);

        for (i = 0; i < D_83003CA4; i++) {
            RentalRules_DrawBulletIcon(116, var_s3 + 40 + i * 24);
        }

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

        Font_BeginTranslucentTextRendering();
        RentalRules_DrawRuleListText(56, var_s3);
        Font_EndTexturedTextRendering();
    }
}

void RentalRules_DrawFrame(void) {
    BgStage_DrawFrame();
    if (D_83003C90 != 0) {
        if (gSessionContext.mode == 10) {
            RentalRules_DrawBackgroundFallback();
        } else {
            Gfx_DrawTiledRgba16Image(D_83003C8C);
        }

        RentalRules_DrawHeaderBanner();

        if (D_83003C90 > 0) {
            D_83003C90--;
        }
    }

    if ((RentalRules_PopupGetProgress() < 0x400) && (RentalRules_GetSpeciesWindowOpeningProgress() < 0x400)) {
        RentalRules_DrawRuleListPanel();
    }

    RentalRules_PopupDraw();
    RentalRules_QualifyingSpeciesWindowDraw();
    BgStage_AdvanceFrame();
}

void RentalRules_LoadCategoryStrings(void) {
    s32 i;

    for (i = 0; i < 29; i++) {
        D_83003CE0.unk_00[i] = Text_GetString(NULL, 0, sBattleModeLabels, i + 4);
    }

    D_83003CE0.unk_74 = D_83003CE0.unk_00[2];
    D_83003CE0.unk_78 = D_83003CE0.unk_00[10];
    D_83003CE0.unk_7C = D_83003CE0.unk_00[12];
    D_83003CE0.unk_80 = D_83003CE0.unk_00[15];
    D_83003CE0.unk_84 = D_83003CE0.unk_00[22];
    D_83003CE0.unk_88 = D_83003CE0.unk_00[27];
    D_83003CE0.unk_8C = Text_GetString(NULL, 0, sBattleModeLabels, 33);
    D_83003CE0.unk_90 = D_83003CE0.unk_00[20];
    D_83003CE0.unk_94 = D_83003CE0.unk_00[4];
    D_83003CE0.unk_98 = Text_GetString(NULL, 0, sBattleModeLabels, 34);
}

void RentalRules_LoadDescriptionStrings(void) {
    s32 i;
    s32 var_s2 = 0;

    for (i = 0; i < 39; i++) {
        switch (i) {
            case 7:
            case 11:
            case 14:
            case 19:
            case 24:
                D_83003DE0.unk_00[i] = NULL;
                break;

            default:
                D_83003DE0.unk_00[i] = Text_GetString(NULL, 0, sBattleModeLabels, var_s2 + 35);
                var_s2++;
                break;
        }
    }
}

void RentalRules_Init(void) {
    D_83003C80 = 0;
    D_83003C82 = 10;
    D_83003C90 = -1;
    D_83003C92 = 0;
    Audio_PlaySoundEffectById(SFX_PANEL_OPEN);
    D_83003C98 = 0;
    D_83003C9C = NULL;
    D_83003CA6 = 0;
    D_83003C84 = 0;

    D_83003CA0 = RentalRules_GetRuleIdList(&gSessionContext);
    if (D_83003CA0 == 0) {
        D_83003CA4 = 0;
    } else {
        D_83003CA4 = 0;
        while (D_83003CA0[D_83003CA4] != -1) {
            D_83003CA4++;
        }
    }

    RentalRules_LoadCategoryStrings();
    RentalRules_LoadDescriptionStrings();

    sStadiumModeLabel = Text_GetString(NULL, 0, sBattleModeLabels, 70);
    sFreeBattleModeLabel = Text_GetString(NULL, 0, sBattleModeLabels, 69);
    sEventBattleModeLabel = Text_GetString(NULL, 0, sBattleModeLabels, 73);
    sGymLeaderCastleModeLabel = Text_GetString(NULL, 0, sBattleModeLabels, 71);
    sVsMewtwoModeLabel = Text_GetString(NULL, 0, sBattleModeLabels, 72);
    sAnythingGoesLabel = Text_GetString(NULL, 0, sBattleModeLabels, 74);
    sNintendoCup97Label = Text_GetString(NULL, 0, sBattleModeLabels, 77);
    sNintendoCup98Label = Text_GetString(NULL, 0, sBattleModeLabels, 76);
    sNintendoCup99Label = Text_GetString(NULL, 0, sBattleModeLabels, 75);
    sPetitCupLabel = Text_GetString(NULL, 0, sBattleModeLabels, 78);
    sPikaCupLabel = Text_GetString(NULL, 0, sBattleModeLabels, 79);
    sPrimeCupLabel = Text_GetString(NULL, 0, sBattleModeLabels, 80);

    sGymLeaderCastleLabel = sGymLeaderCastleModeLabel;
    sVsMewtwoLabel = sVsMewtwoModeLabel;

    D_83003C98 = RentalRules_GetModeLabel(gSessionContext.mode);
    D_83003C9C = RentalRules_GetCategoryLabel(gSessionContext.ruleCategory);

    if (gSessionContext.inRound2 != 0) {
        D_83003C84 |= 1;
    }

    if (RentalRules_RuleListHasEmptyEntry(D_83003CA0) != 0) {
        D_83003C84 |= 2;
    }

    if (D_83003C84 & 4) {
        D_83003C94 = 0;
    } else {
        D_83003C94 = 0x400;
    }

    RentalRules_PopupReset();

    RentalRules_QualifyingSpeciesWindowInit((D_83003C84 & 2) ? 1 : 0);
}

s32 RentalRules_Update(void) {
    s32 var_sp1C = 1;

    switch (D_83003C80) {
        case 0:
            RentalRules_UpdateFadeIn();
            break;

        case 1:
            RentalRules_UpdateMainInput();
            break;

        case 2:
            RentalRules_UpdateWaitPopupClose();
            break;

        case 3:
            RentalRules_UpdateFadeOut();
            break;

        case 4:
            if (RentalRules_UpdateExitDelay() != 0) {
                var_sp1C = 0;
            }
            break;
    }
    return var_sp1C;
}

void RentalRules_Loop(void) {
    RentalRules_Init();
    do {
        RentalRules_PollInput();
        RentalRules_PopupUpdate();
        RentalRules_QualifyingSpeciesWindowUpdate();
        RentalRules_DrawFrame();
    } while (RentalRules_Update() != 0);
}

s32 RentalRules_Main(UNUSED s32 arg0, UNUSED s32 arg1) {
    main_pool_push_state('EXPL');

    Font_Init(28, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    ASSET_LOAD(D_3000000, menu_select_ui, 0);
    ASSET_LOAD(D_04000000, rental_rules_ui, 0);

    RentalRules_LoadBackgroundArchive();
    PokeIcon_OpenModelArchive();
    Text_InitStringTables();
    sBattleModeLabels = Text_GetStringTable(0x20);
    D_830039C4 = Text_GetStringTable(36);
    StageLoader_UpdateSegments();
    RentalRules_Loop();
    StageLoader_WaitForRetrace();

    main_pool_pop_state('EXPL');

    return 0;
}
