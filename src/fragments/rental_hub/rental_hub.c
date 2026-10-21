#include "rental_hub.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/game_state.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/DDC0.h"
#include "src/matrix.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "variables.h"

static char** sMenuStringArray;
static BinArchive* sBackgroundArchive;
static void* D_82B01148;
static s16 sHoveredMenuItem;

static u8 D_82B01120[] = {
    6, 0x07, 0x08, 9, 10, 11, 12, 13, 0x0F, 0x00, 0x00,
};

static s8 sRentalHubTextOffsets[] = {
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x03,
};

void RentalHub_DrawHeaderIcon(s16 x, s16 y) {
    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureRgba16(x, y, 48, 24, POKEBALL_ICON_TOP, 48, 0);
    Gfx_DrawTextureRgba16(x, y + 24, 48, 24, POKEBALL_ICON_BOTTOM, 48, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void RentalHub_DrawHeaderBar(s16 x, s16 y, s16 clip_width, Color_RGBA8* fill_color, Color_RGBA8* border_color) {
    gSPDisplayList(gDisplayListHead++, D_8006F558);

    gDPSetEnvColor(gDisplayListHead++, fill_color->r, fill_color->g, fill_color->b, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, border_color->r, border_color->g, border_color->b, 255);

    Gfx_DrawTextureIa8(x, y, 16, 32, D_20003C0, 0x10, 0);
    Gfx_DrawTextureIa8((x + clip_width) - 16, y, 16, 32, D_20005C0, 0x10, 0);
    Gfx_DrawTexturedRectClipped(x + 16, y, clip_width - 32, 32, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void RentalHub_DrawHeader(void) {
    Color_RGBA8 banner_fill;
    Color_RGBA8 banner_border;

    Color_SetRGB(&banner_fill, 0x64, 0x64, 0xC8);
    Color_SetRGB(&banner_border, 0x28, 0x28, 0x8C);
    RentalHub_DrawHeaderBar(72, 40, 520, &banner_fill, &banner_border);
    RentalHub_DrawHeaderIcon(48, 32);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0, 0, 0, 0xFF);
    Font_Printf(106, 44, Text_GetString(NULL, 0, sMenuStringArray, sRentalHubTextOffsets[gSessionContext.mode]));
    Gfx_SetEnvColor(0xFF, 0xFF, 0x77, 0xFF);
    Font_Printf(104, 42, Text_GetString(NULL, 0, sMenuStringArray, sRentalHubTextOffsets[gSessionContext.mode]));
    Font_EndTexturedTextRendering();
}

void RentalHub_DrawSelectionCursor(s16 x, s16 y, s16 width, s16 height) {
    static s16 pulsing_timer = 0;

    s16 pulse = SINS(pulsing_timer) * 2;
    UNUSED s32 pad[2];

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, 240, 212, 104, 255);

    Gfx_DrawTextureIa8(x + pulse, y + pulse, 16, 16, BOTTOM_LEFT_SECTION_CORNER, 16, 0);
    Gfx_DrawTextureIa8(x + pulse, ((y + height) - pulse) - 16, 16, 16, TOP_LEFT_SECTION_CORNER, 16, 0);
    Gfx_DrawTextureIa8(((x + width) - pulse) - 16, y + pulse, 16, 16, BOTTOM_RIGHT_SECTION_CORNER, 16, 0);
    Gfx_DrawTextureIa8(((x + width) - pulse) - 16, ((y + height) - pulse) - 16, 16, 16, TOP_RIGHT_SECTION_CORNER, 0x10,
                       0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    pulsing_timer += 0x2000;
}

void RentalHub_DrawMenuItemBorder(s16 x, s16 y, s16 width, s16 height) {
    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureIa8(x - 3, y - 3, 8, 8, D_2000340, 8, 0);
    Gfx_DrawTextureIa8((x + width) - 5, y - 3, 8, 8, D_2000380, 8, 0);
    Gfx_DrawTexturedRectClipped(x + 4, y - 3, width - 8, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTextureIa8(x - 3, (y + height) - 5, 8, 8, D_20002C0, 8, 0);
    Gfx_DrawTexturedRectClipped(x - 3, y + 4, 8, height - 8, 0, 0, 0x400, 0, 0);
    Gfx_DrawTextureIa8((x + width) - 5, (y + height) - 5, 8, 8, D_2000300, 8, 0);
    Gfx_DrawTexturedRectClipped(x + 4, (y + height) - 5, width - 8, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTexturedRectClipped((x + width) - 5, y + 4, 8, height - 8, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void RentalHub_DrawMenuItemBox(s16 x, s16 y, s16 height, char* text) {
    UNUSED s32 pad;

    if (height >= 10) {
        y += ((48 - height) / 2);
        RentalHub_DrawMenuItemBorder(x, y, 152, height);

        gSPDisplayList(gDisplayListHead++, D_8006F470);

        Gfx_FillRectRgb(x + 4, y + 4, 144, height - 8, 0x1E, 0x1E, 0x82);

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

        if ((height - 8) == 40) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Font_Printf((x - (Font_MeasureTextExtent(16, 0, text) / 2)) + 76, y + 11, text);
            Font_EndTexturedTextRendering();
        }
    }
}

void RentalHub_DrawMenuItems(s16 height) {
    UNUSED s32 pad;

    RentalHub_DrawMenuItemBox(80, 384, height * 6, Text_GetString(NULL, 0, sMenuStringArray, 4));
    RentalHub_DrawMenuItemBox(244, 384, height * 6, Text_GetString(NULL, 0, sMenuStringArray, 5));
    RentalHub_DrawMenuItemBox(408, 384, height * 6, Text_GetString(NULL, 0, sMenuStringArray, 6));
}

s32 RentalHub_HandleInput(void) {
    u32 action = 'exec';

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        Audio_PlaySoundEffectById(28);
        action = 'btnA';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        action = 'btnB';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        action = 'exec';
        sHoveredMenuItem -= 1;
        if (sHoveredMenuItem < 0) {
            sHoveredMenuItem = 2;
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        action = 'exec';
        sHoveredMenuItem++;
        if (sHoveredMenuItem >= 3) {
            sHoveredMenuItem = 0;
        }
    }
    return action;
}

void RentalHub_Draw(s16 height) {
    BgStage_DrawFrame();
    Gfx_DrawTiledRgba16Image(D_82B01148);
    RentalHub_DrawHeader();
    RentalHub_DrawMenuItems(height);
    if (height == 8) {
        RentalHub_DrawSelectionCursor((sHoveredMenuItem * 164) + 80, 384, 152, 48);
    }
    BgStage_AdvanceFrame();
}

void RentalHub_FadeInWait(void) {
    // FAKE
    if (StageContext_GetFadeMode != NULL) {
        StageFade_StartFromOpaque(8);
        while (StageContext_GetFadeMode() != 0) {
            Controller_PollInputs();
            RentalHub_Draw(0);
        }
    }
}

void RentalHub_FadeOutWait(void) {
    if ((gSessionContext.mode == 7) || (gSessionContext.mode == 8)) {
        Audio_StopMusic(0x10);
    }

    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromTransparent(8);

    while (StageContext_GetFadeMode() != 1) {
        Controller_PollInputs();
        RentalHub_Draw(0);
    }

    StageLoader_RunFrames(2);
}

s16 RentalHub_MenuLoop(void) {
    s16 i;
    s16 selected_menu_item;
    u32 action = 'exec';

    sHoveredMenuItem = 0;
    RentalHub_FadeInWait();
    Audio_PlaySoundEffectById(SFX_PANEL_OPEN);

    for (i = 1; i < 8; i++) {
        Controller_PollInputs();
        RentalHub_Draw(i);
    }

    while (action == 'exec') {
        Controller_PollInputs();
        action = RentalHub_HandleInput();
        RentalHub_Draw(i);
    }

    for (i = 7; i >= 0; i--) {
        Controller_PollInputs();
        RentalHub_Draw(i);
    }

    RentalHub_Draw(i);

    if (action == 'btnA') {
        selected_menu_item = sHoveredMenuItem + 1;
    } else {
        if (gSessionContext.mode != 0) {
            RentalHub_FadeOutWait();
        }
        selected_menu_item = 0;
    }
    return selected_menu_item;
}

void RentalHub_LoadBackgroundImage(ModeSettings* arg0) {
    sBackgroundArchive = BinArchive_Open(backgrounds_ROM_START, battle_headers_ROM_START, 1, 1);

    if (gSessionContext.mode == 7) {
        if (arg0->castleClears < 8) {
            D_82B01148 = BinArchive_GetFile(sBackgroundArchive, 13);
        } else {
            D_82B01148 = BinArchive_GetFile(sBackgroundArchive, 0x10);
        }
    } else {
        D_82B01148 = BinArchive_GetFile(sBackgroundArchive, D_82B01120[gSessionContext.mode]);
    }
}

s32 RentalHub_MenuMain(void) {
    s16 var_sp26;
    ModeSettings var_sp1C;
    s16 var_v0;

    main_pool_push_state('menu');

    Save_EnsureBankLoaded(2);
    Save_GetModeSettings(&var_sp1C, gSessionContext.inRound2);
    Font_Init(0x10, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);

    RentalHub_LoadBackgroundImage(&var_sp1C);
    Text_InitStringTables();

    sMenuStringArray = Text_GetStringTable(24);
    sHoveredMenuItem = 0;

    if (gSessionContext.mode == 7) {
        if (var_sp1C.castleClears < 8) {
            Audio_PlayMusicIfChanged(42);
        } else {
            Audio_PlayMusicIfChanged(39);
        }
    }

    StageLoader_UpdateSegments();
    var_sp26 = RentalHub_MenuLoop();
    StageLoader_WaitForRetrace();

    main_pool_pop_state('menu');

    return var_sp26;
}

s32 RentalHub_LoadRentalPicker(void) {
    FRAGMENT_LOAD_AND_CALL(FRAGMENT_RENTAL_TEAM_SELECTION, 1, 0);
    return 4;
}

s32 RentalHub_LoadRentalRules(void) {
    FRAGMENT_LOAD_AND_CALL(FRAGMENT_RENTAL_RULES, 0, 0);
    return 4;
}

s32 RentalHub_Main(UNUSED s32 arg0, UNUSED s32 arg1) {
    s16 var_sp2E;
    s32 var_v1;
    s32 var_v1_2;

    var_sp2E = 4;
    main_pool_push_state('SUBT');

    while (var_sp2E >= 2) {
        switch (var_sp2E) {
            case 2:
                var_sp2E = RentalHub_LoadRentalRules();
                break;

            case 3:
                var_sp2E = RentalHub_LoadRentalPicker();
                break;

            case 4:
                var_sp2E = RentalHub_MenuMain();
                break;
        }
    }

    main_pool_pop_state('SUBT');
    return var_sp2E;
}
