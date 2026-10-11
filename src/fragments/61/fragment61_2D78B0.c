#include "fragments/rental_team_selection/rental_team_selection.h"
#include "src/display_object_textures.h"
#include "src/poke_icon.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/ui_graphics.h"
#include "src/status_icons.h"
#include "src/gb_data.h"
#include "src/pokemon_stats.h"
#include "src/save_data.h"
#include "src/game_state.h"
#include "src/session.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/DDC0.h"
#include "src/matrix.h"
#include "src/fragments/rental_team_selection/rental_team_selection.h"
#include "src/hal_libc.h"
#include "src/memory.h"
#include "src/stage_loader.h"

BinArchive* D_84211B30;
void* D_84211B34;
RentalRoster* D_84211B38;
char** D_84211B3C;
char** D_84211B40;
char** D_84211B44;
char** D_84211B48;
char** D_84211B4C;
RentalTeamTray D_84211B50;
RentalCarouselState D_842168A0;
unk_D_84229EB0 D_84229EB0;
unk_D_8423D3A8 D_8423D3A8;
unk_D_8423D3D8 D_8423D3D8[4];
s16 D_8423D3F8;

s16 D_84210D40 = 2;
s16 D_84210D44 = 0x20;
s16 D_84210D48 = 0;
u8 D_84210D4C[] = {
    0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0F,
};

s32 TeamSelection_CheckCartRemoved(s32 arg0) {
    u32 temp_a0 = osSetIntMask(1);

    if (!(IO_READ(PI_STATUS_REG) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) &&
        (((D_B0000800 & 0xFFFF) & 0xFFFF) != 1)) {
        arg0 = -0x80;
    }
    osSetIntMask(temp_a0);
    return arg0;
}

char* TeamSelection_GetTextFromSetA(s32 arg0) {
    return Text_GetString(NULL, 0, D_84211B3C, arg0 - 1);
}

char* TeamSelection_GetTextFromSetB(s32 arg0) {
    return Text_GetString(NULL, 0, D_84211B40, arg0 - 1);
}

char* TeamSelection_GetModeText(s32 arg0) {
    return Text_GetString(NULL, 0, D_84211B44, PokemonType_ToDisplayIndex(arg0));
}

char* TeamSelection_GetLabelText(s32 arg0) {
    return Text_GetString(NULL, 0, D_84211B48, arg0);
}

char* TeamSelection_GetInstructionText(s32 arg0) {
    return Text_GetString(NULL, 0, D_84211B4C, arg0);
}

char* TeamSelection_FormatText(char* arg0, s32 arg1, s32 arg2) {
    return Text_GetString(arg0, arg1, D_84211B48, arg2);
}

void TeamSelection_DrawCornerFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureIa8(arg0 - 3, arg1 - 3, 8, 8, D_2000340, 8, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 5, arg1 - 3, 8, 8, D_2000380, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 4, arg1 - 3, arg2 - 8, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTextureIa8(arg0 - 3, (arg1 + arg3) - 5, 8, 8, D_20002C0, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 - 3, arg1 + 4, 8, arg3 - 8, 0, 0, 0x400, 0, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 5, (arg1 + arg3) - 5, 8, 8, D_2000300, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 4, (arg1 + arg3) - 5, arg2 - 8, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTexturedRectClipped((arg0 + arg2) - 5, arg1 + 4, 8, arg3 - 8, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void TeamSelection_DrawColoredFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    Gfx_DrawTextureIa8(arg0, arg1, 8, 8, D_2000B40, 8, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 8, arg1, 8, 8, D_2000B80, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 8, arg1, arg2 - 0x10, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTextureIa8(arg0, (arg1 + arg3) - 8, 8, 8, D_2000BC0, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0, arg1 + 8, 8, arg3 - 0x10, 0, 0, 0x400, 0, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 8, (arg1 + arg3) - 8, 8, 8, D_2000C00, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 8, (arg1 + arg3) - 8, arg2 - 0x10, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTexturedRectClipped((arg0 + arg2) - 8, arg1 + 8, 8, arg3 - 0x10, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    Gfx_FillRectRgba(arg0 + 8, arg1 + 8, arg2 - 0x10, arg3 - 0x10, arg4, arg5, arg6, arg7);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void TeamSelection_DrawAnimatedGoldCorners(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    static s16 D_84210D58 = 0;

    s16 sp56 = SINS(D_84210D58) * 2;
    UNUSED s32 pad[2];

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 240, 212, 104, 255);

    Gfx_DrawTextureIa8(arg0 + sp56, arg1 + sp56, 0x10, 0x10, bottom_left_sc_tex, 0x10, 0);
    Gfx_DrawTextureIa8(arg0 + sp56, ((arg1 + arg3) - sp56) - 0x10, 0x10, 0x10, top_left_sc_tex, 0x10, 0);
    Gfx_DrawTextureIa8(((arg0 + arg2) - sp56) - 0x10, arg1 + sp56, 0x10, 0x10, bottom_right_sc_tex, 0x10, 0);
    Gfx_DrawTextureIa8(((arg0 + arg2) - sp56) - 0x10, ((arg1 + arg3) - sp56) - 0x10, 0x10, 0x10, top_right_sc_tex, 0x10, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_84210D58 += 0x2000;
}

void TeamSelection_DrawTexturedFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x20) {
        var_s3 = 0x10;
    } else {
        var_s3 = arg2 / 2;
    }
    if (arg3 >= 0x20) {
        var_s2 = 0x10;
    } else {
        var_s2 = arg3 / 2;
    }
    temp_a2 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20288E0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028960, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20287E0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028860, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3,
                  0x4000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((temp_a2 > 0) && (temp_s0_32 > 0)) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, temp_a2, var_s2, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, temp_a2, var_s2, arg4, arg5, arg6, arg7);
    } else if (temp_a2 > 0) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, temp_a2, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        Gfx_FillRectRgba(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void TeamSelection_DrawTexturedPanel(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
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
    temp_a2 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

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

    if ((temp_a2 > 0) && (temp_s0_32 > 0)) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, temp_a2, var_s2, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, temp_a2, var_s2, arg4, arg5, arg6, arg7);
    } else if (temp_a2 > 0) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, temp_a2, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        Gfx_FillRectRgba(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void TeamSelection_DrawHeaderBackdrop(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(arg0, arg1, 0x30, 0x18, D_2006C00, 0x30, 0);
    Gfx_DrawTextureRgba16(arg0, arg1 + 0x18, 0x30, 0x18, D_2007500, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void TeamSelection_DrawRegistrationHeaderBackdrop(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(arg0, arg1, 0x30, 0x18, &D_2028AE0, 0x30, 0);
    Gfx_DrawTextureRgba16(arg0, arg1 + 0x18, 0x30, 0x18, &D_20293E0, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void TeamSelection_DrawCategoryBanner(s16 arg0, s16 arg1, s16 arg2) {
    static u8* D_84210D5C[] = { D_200DFA0, D_200F3E0, D_2010820, D_2011C60, D_20130A0 };

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(arg0, arg1, 0x48, 0x12, D_84210D5C[arg2], 0x48, 0);
    Gfx_DrawTextureRgba16(arg0, arg1 + 0x12, 0x48, 0x12, D_84210D5C[arg2] + 0xA20, 0x48, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void TeamSelection_DrawGradientPanel(s16 arg0, s16 arg1, s16 arg2, Color_RGBA8* arg3, Color_RGBA8* arg4) {
    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, arg3->r, arg3->g, arg3->b, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, arg4->r, arg4->g, arg4->b, 255);

    Gfx_DrawTextureIa8(arg0, arg1, 0x10, 0x20, D_20003C0, 0x10, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 0x10, arg1, 0x10, 0x20, D_20005C0, 0x10, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 0x10, arg1, arg2 - 0x20, 0x20, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void TeamSelection_DrawTitleHeader(void) {
    static s32 D_84210D70[] = {
        0x3B, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3D, 0x3E,
    };

    Color_RGBA8 sp2C;
    Color_RGBA8 sp28;

    Color_SetRGB(&sp2C, 0x64, 0x64, 0xC8);
    Color_SetRGB(&sp28, 0x28, 0x28, 0x8C);
    TeamSelection_DrawGradientPanel(0x48, 0x28, 0x208, &sp2C, &sp28);
    TeamSelection_DrawHeaderBackdrop(0x30, 0x20);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0, 0, 0, 0xFF);
    Font_Printf(0x6A, 0x2C, TeamSelection_GetLabelText(D_84210D70[D_800AE540.unk_0000]));
    Gfx_SetEnvColor(0xFF, 0xFF, 0x77, 0xFF);
    Font_Printf(0x68, 0x2A, TeamSelection_GetLabelText(D_84210D70[D_800AE540.unk_0000]));
    Font_EndTexturedTextRendering();
}

void TeamSelection_DrawCategoryRow(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    if (arg2 == D_8423D3F8) {
        Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
    } else {
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    }
    Font_Printf(arg0 + 0x36, arg1 + (arg2 * 0x1E) + 0x2C, arg3);
}

void TeamSelection_DrawCategoryScreen(s16 arg0, s16 arg1, s16 arg2) {
    UNUSED s32 pad[2];
    char* sp30;
    s16 temp_a3;
    s16 temp_v0;

    BgStage_DrawFrame();
    Gfx_DrawTiledRgba16Image(D_84211B34);
    TeamSelection_DrawTitleHeader();
    if (arg2 > 0) {
        temp_a3 = (((arg2 * 0x9A) - 0x9A) / 8) + 0x10;
        Ui_DrawBorderedPanelNoFill(0x6D, (s16)(((0xAA - temp_a3) / 2) + 0x81), 0x1A6, temp_a3);
        temp_v0 = (((arg2 * 0x5C) - 0x5C) / 8) + 0x10;
        if (1) {}
        TeamSelection_DrawTexturedPanel(0x38, ((0x6C - temp_v0) / 2) + 0x14C, 0x210, (((arg2 * 0x5C) - 0x5C) / 8) + 0x10, 0x1E, 0x1E,
                      0x82, 0x96);
        if (arg2 == 9) {
            TeamSelection_DrawColoredFrame(0x74, 0x88, 0x198, 0x20, 0x8C, 0x28, 0x8C, 0xFF);
            TeamSelection_DrawColoredFrame(0x74, 0xA8, 0x198, 0x7C, 0x64, 0x1E, 0x64, 0xFF);
            Ui_DrawAnimatedTextureMarker(0x79, (D_8423D3F8 * 0x1E) + 0xAD);
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Font_Printf(0x7D, 0x8B, "%s %s", TeamSelection_GetLabelText(D_800AE540.unk_0001 + 0x3F), TeamSelection_GetLabelText(0x48));
            TeamSelection_DrawCategoryRow(0x6D, 0x81, 0, TeamSelection_GetLabelText(0x49));
            TeamSelection_DrawCategoryRow(0x6D, 0x81, 1, TeamSelection_GetLabelText(0x4A));
            TeamSelection_DrawCategoryRow(0x6D, 0x81, 2, TeamSelection_GetLabelText(0x4B));
            TeamSelection_DrawCategoryRow(0x6D, 0x81, 3, TeamSelection_GetLabelText(0x4C));
            Font_SetActive(8, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_SetLineHeight(0x18);
            Font_Printf(0x58, 0x154, Text_GetString(NULL, 0, D_84211B48, 0x4D));
            Font_EndTexturedTextRendering();
        }
    }
    TeamSelection_RulePrompt_DrawFrame(0);
    BgStage_AdvanceFrame();
}

void TeamSelection_WaitForConfirm(void) {
    Audio_PlaySoundEffectById(SFX_MENU_ERROR);
    TeamSelection_RulePrompt_Open(0x10, gPlayer1Controller);

    while (TeamSelection_RulePrompt_TryFinish(0x10) == -1) {
        TeamSelection_RulePrompt_Update();
        TeamSelection_DrawCategoryScreen(0x8C, 0xBC, 9);
        Controller_PollInputs();
    }
}

s32 TeamSelection_HandleConfirmInput(void) {
    s32 sp1C = 'exec';

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        if ((D_8423D3F8 == 0) && (Deck_FindFirstFreeTeamSlot() == 0xA)) {
            TeamSelection_WaitForConfirm();
        } else {
            if (D_8423D3F8 < 3) {
                Audio_PlaySoundEffectById(0x1C);
            } else {
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
            }
            sp1C = 'btnA';
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        D_8423D3F8 = 3;
        sp1C = 'btnB';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        D_8423D3F8--;
        if (D_8423D3F8 < 0) {
            D_8423D3F8 = 3;
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        D_8423D3F8++;
        if (D_8423D3F8 >= 4) {
            D_8423D3F8 = 0;
        }
    }
    return sp1C;
}

s16 TeamSelection_RunCategorySelection(void) {
    s16 i;
    s32 temp_s0;

    D_8423D3F8 = 0;
    Audio_PlaySoundEffectById(SFX_PANEL_OPEN);

    for (i = 0; i < 9; i++) {
        Controller_PollInputs();
        TeamSelection_DrawCategoryScreen(0x8C, 0xBC, i);
    }

    do {
        Controller_PollInputs();
        temp_s0 = TeamSelection_HandleConfirmInput();
        TeamSelection_DrawCategoryScreen(0x8C, 0xBC, 9);
    } while (temp_s0 == 'exec');

    for (i = 8; i >= 0; i--) {
        Controller_PollInputs();
        TeamSelection_DrawCategoryScreen(0x8C, 0xBC, i);
    }

    TeamSelection_DrawCategoryScreen(0x8C, 0xBC, 0);
    return TeamSelection_CheckCartRemoved(D_8423D3F8);
}

void TeamSelection_DrawFrame(s16 arg0, s16 arg1) {
    Color_RGBA8 sp34;
    Color_RGBA8 sp30;
    s32 var_t0 = 0;

    if ((D_800AE540.unk_0000 == 0) && (arg1 >= 0)) {
        if (D_84210D48 == 0) {
            var_t0 = 1;
        } else {
            if ((D_84210D48 % 12) >= 5) {
                var_t0 = 1;
            }
            D_84210D48--;
        }
    }

    if (arg0 == 0) {
        Color_SetRGB(&sp34, 0x64, 0x64, 0xC8);
        Color_SetRGB(&sp30, 0x28, 0x28, 0x8C);
        TeamSelection_DrawGradientPanel(0x48, 0x28, 0x208, &sp34, &sp30);
        TeamSelection_DrawHeaderBackdrop(0x30, 0x20);
        if (var_t0 != 0) {
            TeamSelection_DrawCategoryBanner(0x1AE, 0x26, arg1);
        }
    } else {
        Color_SetRGB(&sp34, 0xB4, 0x5A, 0xA0);
        Color_SetRGB(&sp30, 0x78, 0x28, 0x64);
        TeamSelection_DrawGradientPanel(0x48, 0x28, 0x208, &sp34, &sp30);
        TeamSelection_DrawRegistrationHeaderBackdrop(0x30, 0x20);
    }

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0, 0, 0, 0xFF);

    Font_Printf(0x6A, 0x2C, Text_GetString(NULL, 0, D_84211B48, arg0 + 0x37));
    Gfx_SetEnvColor(0xFF, 0xFF, 0x77, 0xFF);
    Font_Printf(0x68, 0x2A, Text_GetString(NULL, 0, D_84211B48, arg0 + 0x37));

    if ((arg0 == 0) && (var_t0 != 0)) {
        Font_SetActive(4, 0);
        Font_Printf(0x1F9, 0x2F, Text_GetString(NULL, 0, D_84211B48, 0x4E));
    }
    Font_EndTexturedTextRendering();
}

void TeamSelection_RenderFrame(UNUSED s16 arg0, s16 arg1, s16 arg2) {
    s32 temp_s0 = D_84210D40 > 0;

    BgStage_DrawFrame();

    if (temp_s0 != 0) {
        D_84210D40--;
        Gfx_DrawTiledRgba16Image(D_84211B34);
        TeamSelection_DrawFrame(arg1, arg2);
    }

    if (D_84210D44 & 8) {
        TeamSelection_TrainerSlots_Render(temp_s0);
    }

    if (D_84210D44 & 1) {
        Rental_DrawTeamTray(&D_84211B50, temp_s0);
    }

    if (D_84210D44 & 2) {
        Rental_CarouselDraw(&D_842168A0, temp_s0);
    }

    if (D_84210D44 & 4) {
        TeamSelection_RegisteredTeam_Render(&D_84229EB0, temp_s0);
    }

    if (D_84210D44 & 0x10) {
        TeamSelection_Preview_DrawPokemonDetails(&D_8423D3A8, temp_s0);
    }

    if (D_84210D44 & 0x20) {
        TeamSelection_RulePrompt_DrawFrame(temp_s0);
    }

    BgStage_AdvanceFrame();
}

s16 TeamSelection_RunModal(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 temp_s1 = -1;
    s16 i;

    D_84210D48 = 0x27;

    for (i = 0; i < 4; i++) {
        D_84210D40 = 2;
        TeamSelection_RenderFrame(-1, arg1, arg2);
    }

    TeamSelection_TrainerSlots_Open(arg0, arg3);

    while (temp_s1 == -1) {
        Controller_PollInputs();
        TeamSelection_TrainerSlots_Update();
        TeamSelection_RulePrompt_Update();
        temp_s1 = TeamSelection_TrainerSlots_GetSelection();
        D_84210D40 = 2;
        TeamSelection_RenderFrame(-1, arg1, arg2);
    }

    TeamSelection_RenderFrame(-1, arg1, arg2);
    return temp_s1;
}

void TeamSelection_Update(UNUSED s16 arg0, UNUSED s32 arg1) {
    s32 var_a1 = 0;

    if (D_84210D44 & 1) {
        var_a1 = Rental_TeamSlotsUpdate(&D_84211B50);
    }

    if (D_84210D44 & 2) {
        var_a1 |= Rental_CarouselTick(&D_842168A0);
    }

    if (D_84210D44 & 4) {
        var_a1 |= TeamSelection_RegisteredTeam_Update(&D_84229EB0);
    }

    if (D_84210D44 & 0x10) {
        var_a1 |= TeamSelection_Preview_Update(&D_8423D3A8);
    }

    if (D_84210D44 & 0x20) {
        var_a1 |= TeamSelection_RulePrompt_Update();
    }

    if (var_a1 != 0) {
        D_84210D40 = 2;
    }
}

void TeamSelection_Open(s16 arg0, s32 arg1, s16 arg2) {
    Audio_PlaySoundEffectById(SFX_PANEL_OPEN);
    if (arg0 == 4) {
        RegistrationManager_Begin(&D_84229EB0);
    } else {
        Rental_TeamTrayOpen(&D_84211B50, 0);
        Rental_CarouselOpen(&D_842168A0, 0);
    }
    Controller_PollInputs();
    TeamSelection_Update(arg0, 0);
    TeamSelection_RenderFrame(arg0, arg1, arg2);
}

void TeamSelection_RunInputLoop(s16 arg0, s16 arg1, s16 arg2) {
    s32 var_s0 = 1;

    Input_SetRepeatController(&gControllers[D_842168A0.unk_00003]);

    while (var_s0 != 0) {
        Controller_PollInputs();
        TeamSelection_Update(arg0, Input_GetRepeatedDPad() & 0xFFFF);
        TeamSelection_RenderFrame(arg0, arg1, arg2);

        if (arg0 == 4) {
            var_s0 = TeamSelection_RegisteredTeam_GetSelection(&D_84229EB0) == 0;
        } else {
            var_s0 = !Rental_TeamTrayIsIdle(&D_84211B50);
            var_s0 |= !Rental_CarouselIsIdle(&D_842168A0);
        }
    }
}

void TeamSelection_InitializeSlots(void) {
    s16 i;
    TeamRoster* var_v0 = D_800AE540.unk_0004;

    for (i = 0; i < 4; i++) {
        D_8423D3D8[i].unk_00 = 0;
        D_8423D3D8[i].unk_01 = i;
        D_8423D3D8[i].unk_02 = i;
    }

    for (i = 0; i < 4; i++, var_v0++) {
        if (var_v0->unk_000 & 1) {
            if (!(var_v0->unk_000 & 2)) {
                D_8423D3D8[var_v0->unk_001].unk_00 = 1;
                D_8423D3D8[var_v0->unk_001].unk_04 = var_v0;
            } else if (D_800AE540.unk_0000 == 0) {
                D_8423D3D8[var_v0->unk_001].unk_00 = 1;
                D_8423D3D8[var_v0->unk_001].unk_04 = var_v0;
                D_8423D3D8[var_v0->unk_001].unk_01 = 4;
                D_8423D3D8[var_v0->unk_001].unk_02 = 0;
            }
        }
    }
}

void TeamSelection_InitializeSlot(unk_D_8423D3D8* arg0, s16 arg1) {
    char sp50[16];
    UNUSED s32 pad;
    u16 var_v1;
    GbSavePlayerIdentity sp38;

    if (arg1 == 4) {
        D_84210D44 |= TeamSelection_RegisteredTeam_Initialize(&D_84229EB0, &D_84211B50, &D_842168A0, &D_8423D3A8, 0, 0x2C, 0x54, arg0->unk_02);
        return;
    }

    if (arg1 < 4) {
        GbSave_CopyPlayerIdentity(arg1, &sp38);
        Text_UntranscodeName(sp50, sp38.unk_02);
        var_v1 = sp38.unk_00;
    } else {
        HAL_Strcpy(sp50, Text_GetPlayerLabel(1));
        var_v1 = 0;
    }

    D_84210D44 |= Rental_InitTeamTray(&D_84211B50, &D_842168A0, &D_8423D3A8, NULL, 0, var_v1, sp50, 0x40, 0x54, arg0->unk_02);
    D_84210D44 |= Rental_PrimeCarousel(&D_842168A0, &D_84211B50, &D_8423D3A8, 0, 0x68, 0xE4, arg0->unk_02, arg1, D_84211B38);
}

s32 Team_CommitSelectionToTrainer(unk_D_8423D3D8* arg0, s16 arg1) {
    s32 temp_s3;
    s32 var_s0 = 0;
    unk_D_84229EB0_00024* sp34;
    s32 i;

    arg0->unk_04->unk_002 = 0;
    if (arg1 == 4) {
        temp_s3 = RegisteredTeam_LoadSelected(&D_84229EB0, &sp34);
        if (sp34 != NULL) {
            arg0->unk_04->unk_018 = sp34->unk_4D10;
            if (D_800AE540.unk_0000 != 0) {
                HAL_Strcpy(arg0->unk_04->unk_008, sp34->unk_4D12);
            }
            HAL_Strcpy(arg0->unk_04->unk_214->unk_014, sp34->unk_4D12);

            for (i = 0; i < temp_s3; i++) {
                Trainer_AddPokemon(arg0->unk_04, &sp34->unk_0000[i].unk_004);
            }
            var_s0 = 1;
        }
    } else {
        arg0->unk_04->unk_018 = D_84211B50.unk_001C;
        if (D_800AE540.unk_0000 != 0) {
            HAL_Strcpy(arg0->unk_04->unk_008, D_84211B50.unk_001E);
        }
        HAL_Strcpy(arg0->unk_04->unk_214->unk_014, D_84211B50.unk_001E);

        if (D_84211B50.unk_0006 > 0) {
            for (i = 0; i < D_84211B50.unk_0006; i++) {
                Trainer_AddPokemon(arg0->unk_04, &D_84211B50.unk_0030[i].unk_004);
            }
            var_s0 = 1;
        }
    }
    return var_s0;
}

void TeamSelection_FadeOut(s32 arg0) {
    s32 i;

    StageContext_SetClearColor(1);
    Audio_StopMusic(0x10);
    StageFade_StartFromTransparent(8);

    for (i = 0; i < 8; i++) {
        Controller_PollInputs();
        BgStage_DrawFrame();
        Gfx_DrawTiledRgba16Image(D_84211B34);
        if (arg0 != 0) {
            TeamSelection_DrawFrame(0, -1);
        }
        BgStage_AdvanceFrame();
    }

    StageLoader_RunFrames(2);
}

void TeamSelection_FadeIn(void) {
    s32 i;

    if (StageContext_GetFadeMode() == 1) {
        StageFade_StartFromOpaque(8);
        for (i = 0; i < 10; i++) {
            Controller_PollInputs();
            BgStage_DrawFrame();
            Gfx_DrawTiledRgba16Image(D_84211B34);
            TeamSelection_DrawFrame(0, -1);
            BgStage_AdvanceFrame();
        }
    }
}

void TeamSelection_ApplySlotSelection(s16 arg0, s16 arg1) {
    TeamRoster* temp_v1 = D_8423D3D8[arg0].unk_04;

    if (temp_v1->unk_002 != 0) {
        if (arg1 == 4) {
            TeamSelection_RegisteredTeam_ApplySelection(&D_84229EB0, temp_v1->unk_214->unk_028[0].unk_53);
        } else {
            Rental_CopyRosterToTeam(&D_84211B50, &temp_v1->unk_214->unk_028, temp_v1->unk_214->unk_002);
        }
    }
}

s32 Team_SelectTeams(void) {
    s16 var_s1 = 0;
    s16 var_s2;

    if ((D_800AE540.unk_0000 == 7) && (D_800AE540.unk_0002 == 9)) {
        TeamSelection_FadeOut(0);
        Team_ResetOpponentHistory();
        return 1;
    }

    switch (D_800AE540.unk_0000) {
        case 0:
            Audio_PlayMusicIfChanged(0x2D);
            break;

        case 7:
            Audio_PlayMusicIfChanged(0x2B);
            break;

        case 8:
            Audio_PlayMusicIfChanged(0x30);
            break;

        default:
            Audio_PlayMusicIfChanged(0x15);
            break;
    }

    TeamSelection_InitializeSlots();
    TeamSelection_FadeIn();

    D_84210D44 |= TeamSelection_TrainerSlots_Initialize(0);
    D_84210D44 |= TeamSelection_Preview_Initialize(&D_8423D3A8);

    while (var_s1 >= 0 && var_s1 < 4) {
        if (D_8423D3D8[var_s1].unk_00 != 0) {
            var_s2 = TeamSelection_RunModal(D_8423D3D8[var_s1].unk_02, 0, D_8423D3D8[var_s1].unk_01, 1);
            D_8423D3D8[var_s1].unk_04->unk_002 = 0;

            if (var_s2 < 0) {
                var_s1 -= 1;
                while (var_s1 >= 0) {
                    if (D_8423D3D8[var_s1].unk_00 != 0) {
                        var_s2 = (D_8423D3D8[var_s1].unk_04->unk_01C[0].unk_52 & 0x70) >> 4;
                        break;
                    }
                    var_s1--;
                }
            }

            if (var_s1 >= 0) {
                s32 idx = var_s1;

                main_pool_push_state('pkgb');

                if (var_s2 < 4) {
                    GbSave_LoadPort(var_s2);
                    GbSave_MarkBoxDataLoaded(var_s2);
                    D_800AE540.gbStarterChoice = GbSave_GetStarterChoice(var_s2);
                } else {
                    D_800AE540.gbStarterChoice = 0;
                }

                TeamSelection_InitializeSlot(&D_8423D3D8[(unsigned long)idx], var_s2);
                TeamSelection_ApplySlotSelection(var_s1, var_s2);
                TeamSelection_Open(var_s2, 0, D_8423D3D8[var_s1].unk_01);
                TeamSelection_RunInputLoop(var_s2, 0, D_8423D3D8[var_s1].unk_01);

                if (Team_CommitSelectionToTrainer(&D_8423D3D8[(unsigned long)idx], var_s2) != 0) {
                    var_s1++;
                }

                main_pool_pop_state('pkgb');
            }
        } else {
            var_s1++;
        }
    }

    if (var_s1 == -1) {
        return 0;
    }

    TeamSelection_FadeOut(1);
    Team_ResetOpponentHistory();
    return 1;
}

s32 Team_SelectRegisteredTeams(void) {
    s16 var_s1 = 0;
    s16 var_s2;

    switch (D_800AE540.unk_0000) {
        case 0:
            Audio_PlayMusicIfChanged(0x2D);
            break;

        case 7:
            Audio_PlayMusicIfChanged(0x2B);
            break;

        case 8:
            Audio_PlayMusicIfChanged(0x30);
            break;

        default:
            Audio_PlayMusicIfChanged(0x15);
            break;
    }

    TeamSelection_InitializeSlots();
    TeamSelection_FadeIn();

    D_84210D44 |= TeamSelection_TrainerSlots_Initialize(0);
    D_84210D44 |= TeamSelection_Preview_Initialize(&D_8423D3A8);

    while ((var_s1 >= 0) && (var_s1 < 4)) {
        if (D_8423D3D8[var_s1].unk_00 != 0) {
            if (D_8423D3D8[var_s1].unk_04->unk_002 == 0) {
                var_s2 = TeamSelection_RunModal(D_8423D3D8[var_s1].unk_02, 0, D_8423D3D8[var_s1].unk_01, 1);
            } else {
                var_s2 = ((D_8423D3D8[var_s1].unk_04->unk_01C[0].unk_52 & 0x70) >> 4);
            }

            if (var_s2 < 0) {
                var_s1--;

                while (var_s1 >= 0) {
                    if (D_8423D3D8[var_s1].unk_00 != 0) {
                        var_s2 = (D_8423D3D8[var_s1].unk_04->unk_01C[0].unk_52 & 0x70) >> 4;
                        break;
                    }
                    var_s1--;
                }
            }

            if (var_s1 >= 0) {
                s32 idx = var_s1;

                main_pool_push_state('pkgb');

                if (var_s2 < 4) {
                    GbSave_LoadPort(var_s2);
                    GbSave_MarkBoxDataLoaded(var_s2);
                    D_800AE540.gbStarterChoice = GbSave_GetStarterChoice(var_s2);
                } else {
                    D_800AE540.gbStarterChoice = 0;
                }
                TeamSelection_InitializeSlot(&D_8423D3D8[(unsigned long)idx], var_s2);
                TeamSelection_ApplySlotSelection(var_s1, var_s2);
                TeamSelection_Open(var_s2, 0, D_8423D3D8[var_s1].unk_01);
                TeamSelection_RunInputLoop(var_s2, 0, D_8423D3D8[var_s1].unk_01);
                if (Team_CommitSelectionToTrainer(&D_8423D3D8[(unsigned long)idx], var_s2) != 0) {
                    var_s1++;
                }

                main_pool_pop_state('pkgb');
            }
        } else {
            var_s1++;
        }
    }

    if (var_s1 == -1) {
        return 0;
    }

    TeamSelection_FadeOut(1);
    Team_ResetOpponentHistory();
    return 1;
}

void RegisteredTeam_Register(void) {
    unk_D_84229EB0* ptr;
    char sp74[16];
    s16 temp_v0;
    u16 var_s1;
    GbSavePlayerIdentity sp60;

    while (true) {
        temp_v0 = TeamSelection_RunModal(0, 1, 0, 1);
        if (temp_v0 < 0) {
            return;
        }

        main_pool_push_state('regi');

        if (temp_v0 < 4) {
            GbSave_LoadPort(temp_v0);
            GbSave_MarkBoxDataLoaded(temp_v0);
            GbSave_CopyPlayerIdentity(temp_v0, &sp60);
            Text_UntranscodeName(sp74, sp60.unk_02);
            var_s1 = sp60.unk_00;
        } else {
            HAL_Strcpy(sp74, Text_GetPlayerLabel(1));
            var_s1 = 0;
        }

        ptr = &D_84229EB0;
        D_84210D44 |= TeamSelection_RegisteredTeam_Initialize(ptr, &D_84211B50, &D_842168A0, &D_8423D3A8, 3, 0x2C, 0xBC, 0);
        D_84210D44 |= Rental_InitTeamTray(&D_84211B50, &D_842168A0, &D_8423D3A8, ptr, 1, var_s1, sp74, 0x40, 0x54, 0);
        D_84210D44 |= Rental_PrimeCarousel(&D_842168A0, &D_84211B50, &D_8423D3A8, 1, 0x68, 0xE4, 0, temp_v0, D_84211B38);

        TeamSelection_Open(temp_v0, 1, 0);
        TeamSelection_RunInputLoop(temp_v0, 1, 0);

        main_pool_pop_state('regi');

        if (D_84211B50.unk_0006 != 0) {
            break;
        }
    }
}

void RegisteredTeam_Browse(void) {
    D_84210D44 |= TeamSelection_RegisteredTeam_Initialize(&D_84229EB0, &D_84211B50, &D_842168A0, &D_8423D3A8, 1, 0x2C, 0x54, 0);

    RegistrationManager_Begin(&D_84229EB0);
    Controller_PollInputs();
    TeamSelection_Update(4, 0);
    TeamSelection_RenderFrame(4, 2, 0);
    Input_SetRepeatController(&gControllers[D_842168A0.unk_00003]);

    do {
        Controller_PollInputs();
        TeamSelection_Update(4, Input_GetRepeatedDPad() & 0xFFFF);
        TeamSelection_RenderFrame(4, 2, 0);
    } while (TeamSelection_RegisteredTeam_GetSelection(&D_84229EB0) == 0);
}

void RegisteredTeam_Delete(void) {
    D_84210D44 |= TeamSelection_RegisteredTeam_Initialize(&D_84229EB0, &D_84211B50, &D_842168A0, &D_8423D3A8, 2, 0x2C, 0x54, 0);

    RegistrationManager_Begin(&D_84229EB0);
    Controller_PollInputs();
    TeamSelection_Update(4, 0);
    TeamSelection_RenderFrame(4, 3, 0);
    Input_SetRepeatController(&gControllers[D_842168A0.unk_00003]);

    do {
        Controller_PollInputs();
        TeamSelection_Update(4, Input_GetRepeatedDPad() & 0xFFFF);
        TeamSelection_RenderFrame(4, 3, 0);
    } while (TeamSelection_RegisteredTeam_GetSelection(&D_84229EB0) == 0);
}

s32 RegisteredTeam_Manage(void) {
    s16 temp_v0;

    D_84210D44 |= TeamSelection_TrainerSlots_Initialize(1);
    D_84210D44 |= TeamSelection_Preview_Initialize(&D_8423D3A8);

    do {
        temp_v0 = TeamSelection_RunCategorySelection();
        switch (temp_v0) {
            case 0:
                RegisteredTeam_Register();
                break;

            case 1:
                RegisteredTeam_Browse();
                break;

            case 2:
                RegisteredTeam_Delete();
                break;
        }
    } while (temp_v0 != 3);

    return 1;
}

void Rental_LoadRosterForMode(void) {
    BinArchive* temp_a0;
    s16 var_a1;

    temp_a0 = BinArchive_Open(0x898000, NULL, 1, 0);

    switch (D_800AE540.unk_0001) {
        case 0:
            var_a1 = 0x1A;
            break;

        case 1:
            var_a1 = 0x1A;
            break;

        case 2:
            var_a1 = 0x1B;
            break;

        case 3:
            var_a1 = 0x1C;
            break;

        case 4:
            var_a1 = 0x17;
            break;

        case 5:
            var_a1 = 0x18;
            break;

        case 6:
            var_a1 = 0x19;
            break;

        case 7:
            var_a1 = 0x1E;
            break;

        case 8:
            var_a1 = 0x19;
            break;

        default:
            var_a1 = 0;
            break;
    }

    if (var_a1 == 0) {
        D_84211B38 = NULL;
    } else {
        if (D_800AE540.unk_11F2 != 0) {
            var_a1 += 0x1F;
        }
        D_84211B38 = BinArchive_GetFile(temp_a0, var_a1);
    }
}

void Rental_LoadBackgroundImage(void) {
    ModeSettings sp20;

    D_84211B30 = ASSET_LOAD2(backgrounds, 1, 1);
    if (D_800AE540.unk_0000 == 7) {
        if (D_800AE540.unk_0002 >= 8) {
            D_84211B34 = BinArchive_GetFile(D_84211B30, 0xE);
        } else {
            Save_EnsureBankLoaded(2);
            Save_GetModeSettings(&sp20, D_800AE540.unk_11F2);
            if (sp20.unk_04 < 8) {
                D_84211B34 = BinArchive_GetFile(D_84211B30, 0xD);
            } else {
                D_84211B34 = BinArchive_GetFile(D_84211B30, 0x10);
            }
        }
    } else {
        D_84211B34 = BinArchive_GetFile(D_84211B30, D_84210D4C[D_800AE540.unk_0000]);
    }
}

s32 Rental_Main(s32 arg0, UNUSED s32 arg1) {
    s32 var_v1;

    main_pool_push_state('PICK');

    Font_Init(0x1C, 0);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    FRAGMENT_LOAD(fragment31);
    PokeIcon_OpenModelArchives();
    Text_InitStringTables();

    D_84211B3C = Text_GetStringTable(0x24);
    D_84211B40 = Text_GetStringTable(0x25);
    D_84211B44 = Text_GetStringTable(0x26);
    D_84211B48 = Text_GetStringTable(0x1A);
    D_84211B4C = Text_GetStringTable(6);

    Save_EnsureBankLoaded(D_800AE540.unk_0001 / 4);
    Save_SetActiveRecordBank(D_800AE540.unk_0001);
    Deck_CompactRegisteredTeams();
    Rental_LoadBackgroundImage();
    PokeIcon_OpenModelArchive();
    Rental_LoadRosterForMode();
    StageLoader_UpdateSegments();

    if (arg0 == 1) {
        var_v1 = RegisteredTeam_Manage();
    } else if (D_800AE540.unk_11F6 & 0x20) {
        var_v1 = Team_SelectRegisteredTeams();
        D_800AE540.unk_11F6 = D_800AE540.unk_11F6 & 0xFFDF;
    } else {
        D_800AE540.unk_11F5 &= 0xFFFD;
        var_v1 = Team_SelectTeams();
    }

    StageLoader_WaitForRetrace();

    main_pool_pop_state('PICK');

    return var_v1;
}
