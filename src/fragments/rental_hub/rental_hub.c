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

static char** D_82B01140;
static BinArchive* D_82B01144;
static void* D_82B01148;
static s16 D_82B0114C;

static u8 D_82B01120[] = {
    0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0F, 0x00, 0x00,
};

static s8 D_82B0112C[] = {
    0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x03,
};

void RentalHub_DrawHeaderIcon(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(arg0, arg1, 0x30, 0x18, D_2006C00, 0x30, 0);
    Gfx_DrawTextureRgba16(arg0, arg1 + 0x18, 0x30, 0x18, D_2007500, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void RentalHub_DrawHeaderBar(s16 arg0, s16 arg1, s16 arg2, Color_RGBA8* arg3, Color_RGBA8* arg4) {
    gSPDisplayList(gDisplayListHead++, D_8006F558);

    gDPSetEnvColor(gDisplayListHead++, arg3->r, arg3->g, arg3->b, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, arg4->r, arg4->g, arg4->b, 255);

    Gfx_DrawTextureIa8(arg0, arg1, 0x10, 0x20, D_20003C0, 0x10, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 0x10, arg1, 0x10, 0x20, D_20005C0, 0x10, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 0x10, arg1, arg2 - 0x20, 0x20, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void RentalHub_DrawHeader(void) {
    Color_RGBA8 sp2C;
    Color_RGBA8 sp28;

    Color_SetRGB(&sp2C, 0x64, 0x64, 0xC8);
    Color_SetRGB(&sp28, 0x28, 0x28, 0x8C);
    RentalHub_DrawHeaderBar(0x48, 0x28, 0x208, &sp2C, &sp28);
    RentalHub_DrawHeaderIcon(0x30, 0x20);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0, 0, 0, 0xFF);
    Font_Printf(0x6A, 0x2C, Text_GetString(NULL, 0, D_82B01140, D_82B0112C[D_800AE540.unk_0000]));
    Gfx_SetEnvColor(0xFF, 0xFF, 0x77, 0xFF);
    Font_Printf(0x68, 0x2A, Text_GetString(NULL, 0, D_82B01140, D_82B0112C[D_800AE540.unk_0000]));
    Font_EndTexturedTextRendering();
}

void RentalHub_DrawSelectionCursor(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    static s16 D_82B01138 = 0;

    s16 sp56 = SINS(D_82B01138) * 2;
    UNUSED s32 pad[2];

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 240, 212, 104, 255);

    Gfx_DrawTextureIa8(arg0 + sp56, arg1 + sp56, 0x10, 0x10, D_2000C80, 0x10, 0);
    Gfx_DrawTextureIa8(arg0 + sp56, ((arg1 + arg3) - sp56) - 0x10, 0x10, 0x10, D_2000F80, 0x10, 0);
    Gfx_DrawTextureIa8(((arg0 + arg2) - sp56) - 0x10, arg1 + sp56, 0x10, 0x10, D_2000D80, 0x10, 0);
    Gfx_DrawTextureIa8(((arg0 + arg2) - sp56) - 0x10, ((arg1 + arg3) - sp56) - 0x10, 0x10, 0x10, D_2000E80, 0x10, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_82B01138 += 0x2000;
}

void RentalHub_DrawMenuItemBorder(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
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

void RentalHub_DrawMenuItemBox(s16 arg0, s16 arg1, s16 arg2, char* arg3) {
    UNUSED s32 pad;

    if (arg2 >= 0xA) {
        arg1 += ((0x30 - arg2) / 2);
        RentalHub_DrawMenuItemBorder(arg0, arg1, 0x98, arg2);

        gSPDisplayList(gDisplayListHead++, D_8006F470);

        Gfx_FillRectRgb(arg0 + 4, arg1 + 4, 0x90, arg2 - 8, 0x1E, 0x1E, 0x82);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        if ((arg2 - 8) == 0x28) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Font_Printf((arg0 - (Font_MeasureTextExtent(0x10, 0, arg3) / 2)) + 0x4C, arg1 + 0xB, arg3);
            Font_EndTexturedTextRendering();
        }
    }
}

void RentalHub_DrawMenuItems(s16 arg0) {
    UNUSED s32 pad;

    RentalHub_DrawMenuItemBox(0x50, 0x180, arg0 * 6, Text_GetString(NULL, 0, D_82B01140, 4));
    RentalHub_DrawMenuItemBox(0xF4, 0x180, arg0 * 6, Text_GetString(NULL, 0, D_82B01140, 5));
    RentalHub_DrawMenuItemBox(0x198, 0x180, arg0 * 6, Text_GetString(NULL, 0, D_82B01140, 6));
}

s32 RentalHub_HandleInput(void) {
    u32 var_v1 = 'exec';

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        Audio_PlaySoundEffectById(0x1C);
        var_v1 = 'btnA';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        var_v1 = 'btnB';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        var_v1 = 'exec';
        D_82B0114C -= 1;
        if (D_82B0114C < 0) {
            D_82B0114C = 2;
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        var_v1 = 'exec';
        D_82B0114C++;
        if (D_82B0114C >= 3) {
            D_82B0114C = 0;
        }
    }
    return var_v1;
}

void RentalHub_Draw(s16 arg0) {
    BgStage_DrawFrame();
    Gfx_DrawTiledRgba16Image(D_82B01148);
    RentalHub_DrawHeader();
    RentalHub_DrawMenuItems(arg0);
    if (arg0 == 8) {
        RentalHub_DrawSelectionCursor((D_82B0114C * 0xA4) + 0x50, 0x180, 0x98, 0x30);
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
    if ((D_800AE540.unk_0000 == 7) || (D_800AE540.unk_0000 == 8)) {
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
    s16 var_v1;
    u32 temp_s1 = 'exec';

    D_82B0114C = 0;
    RentalHub_FadeInWait();
    Audio_PlaySoundEffectById(SFX_PANEL_OPEN);

    for (i = 1; i < 8; i++) {
        Controller_PollInputs();
        RentalHub_Draw(i);
    }

    while (temp_s1 == 'exec') {
        Controller_PollInputs();
        temp_s1 = RentalHub_HandleInput();
        RentalHub_Draw(i);
    }

    for (i = 7; i >= 0; i--) {
        Controller_PollInputs();
        RentalHub_Draw(i);
    }

    RentalHub_Draw(i);

    if (temp_s1 == 'btnA') {
        var_v1 = D_82B0114C + 1;
    } else {
        if (D_800AE540.unk_0000 != 0) {
            RentalHub_FadeOutWait();
        }
        var_v1 = 0;
    }
    return var_v1;
}

void RentalHub_LoadBackgroundImage(ModeSettings* arg0) {
    D_82B01144 = BinArchive_Open(backgrounds_ROM_START, battle_headers_ROM_START, 1, 1);

    if (D_800AE540.unk_0000 == 7) {
        if (arg0->unk_04 < 8) {
            D_82B01148 = BinArchive_GetFile(D_82B01144, 0xD);
        } else {
            D_82B01148 = BinArchive_GetFile(D_82B01144, 0x10);
        }
    } else {
        D_82B01148 = BinArchive_GetFile(D_82B01144, D_82B01120[D_800AE540.unk_0000]);
    }
}

s32 RentalHub_MenuMain(void) {
    s16 sp26;
    ModeSettings sp1C;
    s16 temp_v0;

    main_pool_push_state('menu');

    Save_EnsureBankLoaded(2);
    Save_GetModeSettings(&sp1C, D_800AE540.unk_11F2);
    Font_Init(0x10, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);

    RentalHub_LoadBackgroundImage(&sp1C);
    Text_InitStringTables();

    D_82B01140 = Text_GetStringTable(0x18);
    D_82B0114C = 0;

    if (D_800AE540.unk_0000 == 7) {
        if (sp1C.unk_04 < 8) {
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
