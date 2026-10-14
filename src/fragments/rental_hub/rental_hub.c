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

static char** menu_string_array;
static BinArchive* background_bin_archive;
static void* D_82B01148;
static s16 hovered_menu_item;

static u8 D_82B01120[] = {
    0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0F, 0x00, 0x00,
};

static s8 rental_hub_text_offsets[] = {
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x03,
};

void RentalHub_DrawHeaderIcon(s16 x, s16 y) {
    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureRgba16(x, y, 48, 24, POKEBALL_ICON_TOP, 0x30, 0);
    Gfx_DrawTextureRgba16(x, y + 24, 48, 24, POKEBALL_ICON_BOTTOM, 0x30, 0);

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
    RentalHub_DrawHeaderBar(72, 0x28, 520, &banner_fill, &banner_border);
    RentalHub_DrawHeaderIcon(48, 32);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0, 0, 0, 0xFF);
    Font_Printf(0x6A, 0x2C, Text_GetString(NULL, 0, menu_string_array, rental_hub_text_offsets[gSessionContext.mode]));
    Gfx_SetEnvColor(0xFF, 0xFF, 0x77, 0xFF);
    Font_Printf(0x68, 0x2A, Text_GetString(NULL, 0, menu_string_array, rental_hub_text_offsets[gSessionContext.mode]));
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
    Gfx_DrawTextureIa8(((x + width) - pulse) - 16, ((y + height) - pulse) - 16, 16, 16, TOP_RIGHT_SECTION_CORNER, 0x10, 0);

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

    if (height >= 0xA) {
        y += ((0x30 - height) / 2);
        RentalHub_DrawMenuItemBorder(x, y, 152, height);

        gSPDisplayList(gDisplayListHead++, D_8006F470);

        Gfx_FillRectRgb(x + 4, y + 4, 144, height - 8, 0x1E, 0x1E, 0x82);

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

        if ((height - 8) == 0x28) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Font_Printf((x - (Font_MeasureTextExtent(16, 0, text) / 2)) + 76, y + 11, text);
            Font_EndTexturedTextRendering();
        }
    }
}

void RentalHub_DrawMenuItems(s16 height) {
    UNUSED s32 pad;

    RentalHub_DrawMenuItemBox(0x50, 0x180, height * 6, Text_GetString(NULL, 0, menu_string_array, 4));
    RentalHub_DrawMenuItemBox(0xF4, 0x180, height * 6, Text_GetString(NULL, 0, menu_string_array, 5));
    RentalHub_DrawMenuItemBox(0x198, 0x180, height * 6, Text_GetString(NULL, 0, menu_string_array, 6));
}

s32 RentalHub_HandleInput(void) {
    u32 action = 'exec';

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        Audio_PlaySoundEffectById(0x1C);
        action = 'btnA';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        action = 'btnB';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        action = 'exec';
        hovered_menu_item -= 1;
        if (hovered_menu_item < 0) {
            hovered_menu_item = 2;
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        action = 'exec';
        hovered_menu_item++;
        if (hovered_menu_item >= 3) {
            hovered_menu_item = 0;
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
        RentalHub_DrawSelectionCursor((hovered_menu_item * 164) + 80, 384, 152, 48);
    }
    BgStage_AdvanceFrame();
}

void RentalHub_FadeInWait(void) {
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

    hovered_menu_item = 0;
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
        selected_menu_item = hovered_menu_item + 1;
    } else {
        if (gSessionContext.mode != 0) {
            RentalHub_FadeOutWait();
        }
        selected_menu_item = 0;
    }
    return selected_menu_item;
}

void RentalHub_LoadBackgroundImage(ModeSettings* arg0) {
    background_bin_archive = BinArchive_Open(backgrounds_ROM_START, battle_headers_ROM_START, 1, 1);

    if (gSessionContext.mode == 7) {
        if (arg0->castleClears < 8) {
            D_82B01148 = BinArchive_GetFile(background_bin_archive, 0xD);
        } else {
            D_82B01148 = BinArchive_GetFile(background_bin_archive, 0x10);
        }
    } else {
        D_82B01148 = BinArchive_GetFile(background_bin_archive, D_82B01120[gSessionContext.mode]);
    }
}

s32 RentalHub_MenuMain(void) {
    s16 sp26;
    ModeSettings sp1C;
    s16 temp_v0;

    main_pool_push_state('menu');

    Save_EnsureBankLoaded(2);
    Save_GetModeSettings(&sp1C, gSessionContext.inRound2);
    Font_Init(0x10, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);

    RentalHub_LoadBackgroundImage(&sp1C);
    Text_InitStringTables();

    menu_string_array = Text_GetStringTable(0x18);
    hovered_menu_item = 0;

    if (gSessionContext.mode == 7) {
        if (sp1C.castleClears < 8) {
            Audio_PlayMusicIfChanged(0x2A);
        } else {
            Audio_PlayMusicIfChanged(0x27);
        }
    }

    StageLoader_UpdateSegments();
    sp26 = RentalHub_MenuLoop();
    StageLoader_WaitForRetrace();

    main_pool_pop_state('menu');

    return sp26;
}

s32 RentalHub_LoadRentalPicker(void) {
    FRAGMENT_LOAD_AND_CALL(fragment61, 1, 0);
    return 4;
}

s32 RentalHub_LoadRentalRules(void) {
    FRAGMENT_LOAD_AND_CALL(fragment55, 0, 0);
    return 4;
}

s32 RentalHub_Main(UNUSED s32 arg0, UNUSED s32 arg1) {
    s16 sp2E;
    s32 var_v1;
    s32 var_v1_2;

    sp2E = 4;
    main_pool_push_state('SUBT');

    while (sp2E >= 2) {
        switch (sp2E) {
            case 2:
                sp2E = RentalHub_LoadRentalRules();
                break;

            case 3:
                sp2E = RentalHub_LoadRentalPicker();
                break;

            case 4:
                sp2E = RentalHub_MenuMain();
                break;
        }
    }

    main_pool_pop_state('SUBT');
    return sp2E;
}
