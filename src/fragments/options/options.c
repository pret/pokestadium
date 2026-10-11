#include "options.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/save_data.h"
#include "src/game_state.h"
#include "src/text_system.h"
#include "src/3D140.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/audio_channel.h"
#include "src/gfx_buffer.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static char** D_82C01660;
static s16 D_82C01664;
static u16 D_82C01666;

void Options_DrawBackground(void) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0,
                      ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 50, 150, 80, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 20, 100, 50, 255);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_300F780, G_IM_FMT_I, 128, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 7, 6, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(0, 0, 0x280, 0x1E0, 0, 0, 0x400, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Options_DrawPanelBox(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
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

void Options_DrawValueCapsule(s16 arg0, s16 arg1) {
    gDPSetEnvColor(gDisplayListHead++, 60, 60, 160, 255);

    Gfx_DrawTextureI4(arg0, arg1, 0x10, 0x1C, D_30242C0, 0x10, 0);
    Gfx_DrawTextureI4(arg0 + 0x68, arg1, 0x10, 0x1C, D_30243A0, 0x10, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 0x10, arg1, 0x58, 0x1C, 0, 0, 0, 0x400, 0);
}

void Options_DrawMainPanel(s16 arg0, s32 arg1) {
    UNUSED s32 pad;
    s32 var_a2;
    s16 sp30 = (arg0 * 0x16) + 0xA;
    s16 sp2C = ((0xBA - sp30) / 2) + 0xE5;

    if (arg0 > 0) {
        Ui_DrawBorderedPanelNoFill(0x89, sp2C, 0x16E, sp30);

        if (arg0 == 8) {
            char* sp40;

            Options_DrawPanelBox(0x90, sp2C + 7, 0x160, 0x20, 0x3C, 0x3C, 0xA0, 0xFF);
            Options_DrawPanelBox(0x90, sp2C + 0x27, 0x160, 0x8C, 0x1E, 0x1E, 0x64, 0xFF);

            if (arg1 != 0) {
                Ui_DrawAnimatedTextureMarker(0x95, sp2C + (D_82C01664 * 0x20) + 0x31);
            }

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            Options_DrawValueCapsule(0x168, sp2C + 0x30);
            Options_DrawValueCapsule(0x168, sp2C + 0x50);

            gSPDisplayList(gDisplayListHead++, D_8006F630);

            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            sp40 = Text_GetString(NULL, 0, D_82C01660, 4);
            Font_Printf(0x140 - (Font_MeasureTextExtent(0x10, 0, sp40) / 2), sp2C + 0xA, sp40);

            if (D_82C01664 == 0) {
                var_a2 = 0;
            } else {
                var_a2 = 0xFF;
            }

            Gfx_SetEnvColor(0xFF, 0xFF, var_a2, 0xFF);
            Font_Printf(0xBB, sp2C + 0x31, Text_GetString(NULL, 0, D_82C01660, 5));
            sp40 = Text_GetString(NULL, 0, D_82C01660, (D_82C01666 & 1) != 0);
            Font_Printf(0x1A4 - (Font_MeasureTextExtent(0x10, 0, sp40) / 2), sp2C + 0x31, sp40);

            if (D_82C01664 == 1) {
                var_a2 = 0;
            } else {
                var_a2 = 0xFF;
            }

            Gfx_SetEnvColor(0xFF, 0xFF, var_a2, 0xFF);
            Font_Printf(0xBB, sp2C + 0x51, Text_GetString(NULL, 0, D_82C01660, 6));
            sp40 = Text_GetString(NULL, 0, D_82C01660, ((D_82C01666 & 2) != 0) + 2);
            Font_Printf(0x1A4 - (Font_MeasureTextExtent(0x10, 0, sp40) / 2), sp2C + 0x51, sp40);

            if (D_82C01664 == 2) {
                var_a2 = 0;
            } else {
                var_a2 = 0xFF;
            }

            Gfx_SetEnvColor(0xFF, 0xFF, var_a2, 0xFF);
            Font_Printf(0xBB, sp2C + 0x71, Text_GetString(NULL, 0, D_82C01660, 7));

            if (D_82C01664 == 3) {
                var_a2 = 0;
            } else {
                var_a2 = 0xFF;
            }

            Gfx_SetEnvColor(0xFF, 0xFF, var_a2, 0xFF);
            Font_Printf(0xBB, sp2C + 0x91, Text_GetString(NULL, 0, D_82C01660, 8));
            Font_EndTexturedTextRendering();
        }
    }
}

void Options_DrawConfirmPrompt(s32 arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad;
    s16 sp28 = (arg2 * 0x11) + 2;
    s16 sp24 = ((0x8A - sp28) / 2) + 0x54;

    if (arg2 > 0) {
        Ui_DrawBorderedPanel(0x51, sp24, 0x1DE, sp28, 0x6109);

        if (arg2 == 8) {
            Ui_DrawAnimatedTextureMarker(0x119, sp24 + (arg1 * 0x1C) + 0x48);
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0x64, 0xFF);

            if (arg0 == 0) {
                Font_SetLineHeight(0x1C);
                Font_Printf(0x63, sp24 + 0xC, Text_GetString(NULL, 0, D_82C01660, 9));
            } else {
                Font_SetLineHeight(0x1C);
                Font_Printf(0x63, sp24 + 0xC, Text_GetString(NULL, 0, D_82C01660, 0xA));
            }

            Gfx_SetEnvColor(0xFF, 0xFF, (arg1 == 0) ? 0 : 0xFF, 0xFF);
            Font_Printf(0x141, sp24 + 0x48, Text_GetString(NULL, 0, D_82C01660, 0xB));
            Gfx_SetEnvColor(0xFF, 0xFF, (arg1 == 1) ? 0 : 0xFF, 0xFF);
            Font_Printf(0x141, sp24 + 0x64, Text_GetString(NULL, 0, D_82C01660, 0xC));
            Font_EndTexturedTextRendering();
        }
    }
}

void Options_DrawEraseCompleteMessage(s32 arg0) {
    UNUSED s32 pad;
    s16 sp28 = arg0 * 9;
    s16 sp24 = ((0x38 - sp28) / 2) + 0x82;

    if (arg0 >= 2) {
        Ui_DrawBorderedPanel(0x87, sp24, 0x172, sp28, 0x6109);
        if (arg0 == 8) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0x64, 0xFF);
            Font_Printf(0x9B, sp24 + 0x18, Text_GetString(NULL, 0, D_82C01660, 0xD));
            Font_EndTexturedTextRendering();
        }
    }
}

void Options_Draw(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    BgStage_DrawFrame();
    Options_DrawBackground();
    Options_DrawMainPanel(arg0, arg1 == 0);

    if (arg2 < 2) {
        Options_DrawConfirmPrompt(arg2, arg3, arg1);
    } else {
        Options_DrawEraseCompleteMessage(arg1);
    }

    BgStage_AdvanceFrame();
}

s32 Options_ConfirmPrompt(s32 arg0) {
    s16 i;
    s32 temp_s2;
    s32 var_s2 = 1;
    s16 var_s1 = 1;

    if (arg0 == 0) {
        for (i = 1; i < 8; i++) {
            Controller_PollInputs();
            Options_Draw(8, i, arg0, 1);
        }
    }

    while (var_s2 != 0) {
        Controller_PollInputs();
        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP | BTN_DDOWN)) {
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            var_s1 ^= 1;
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            var_s2 = 0;
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            var_s1 = 1;
            var_s2 = 0;
        }
        Options_Draw(8, 8, arg0, var_s1);
    }

    temp_s2 = var_s1 == 0;
    if (temp_s2 != 0) {
        if (arg0 == 0) {
            Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        } else {
            Audio_PlaySoundEffectById(0x1F);
        }
    } else {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }

    if ((arg0 == 1) || (var_s1 == 1)) {
        for (i = 7; i > 0; i--) {
            Controller_PollInputs();
            Options_Draw(8, i, arg0, var_s1);
        }
    }
    return temp_s2;
}

void Options_ShowEraseCompleteScreen(void) {
    s16 i;

    for (i = 1; i < 8; i++) {
        Controller_PollInputs();
        Options_Draw(8, i, 2, 0);
    }

    do {
        Controller_PollInputs();
        Options_Draw(8, 8, 2, 0);
    } while (!BTN_IS_PRESSED(gPlayer1Controller, BTN_A));

    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);

    for (i = 7; i > 0; i--) {
        Controller_PollInputs();
        Options_Draw(8, i, 2, 0);
    }
}

void Options_EraseSaveData(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 9; i++) {
        Save_SetActiveRecordBank(i);

        for (j = 0; j < 12; j++) {
            Save_ResetAndCommitTypedRecord(0x10, j);
        }
    }

    for (j = 0; j < 12; j++) {
        Save_ResetAndCommitTypedRecord(0x11, j);
    }

    for (j = 0; j < 4; j++) {
        Save_ResetAndCommitTypedRecord(0x12, j);
    }

    Save_ResetAndCommitTypedRecord(0x13, 0);
    Save_ResetAndCommitTypedRecord(0x14, 0);
    Save_ResetAndCommitTypedRecord(0x15, 0);
    Save_ResetAndCommitTypedRecord(0x16, 0);
    Save_ResetAndCommitTypedRecord(0x17, 0);
    Save_FlushDirtyBanks();
    D_800AE540.unk_11F2 = 0;
    Audio_SetMonoOutput(0);
    Audio_SetVoiceEnabled(1);
    D_82C01666 = 0;
}

void Options_ApplySoundSettings(u16 arg0) {
    u16 sp26;
    u16 sp24;

    Save_GetOptionsField02(&sp26);
    sp24 = arg0 ^ sp26;

    if (sp24 != 0) {
        if (sp24 & 1) {
            if (arg0 & 1) {
                Audio_SetMonoOutput(1);
            } else {
                Audio_SetMonoOutput(0);
            }
        }

        if (sp24 & 2) {
            if (arg0 & 2) {
                Audio_SetVoiceEnabled(0);
            } else {
                Audio_SetVoiceEnabled(1);
            }
        }

        Save_SetOptionsField02(&arg0);
        Save_CommitTypedRecord(0x14, 0);
    }
}

s16 Options_ApplySelection(void) {
    s16 sp1E = 0;

    switch (D_82C01664) {
        case 0:
            Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
            D_82C01666 ^= 1;
            break;

        case 1:
            Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
            D_82C01666 ^= 2;
            break;

        case 2:
            Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
            if ((Options_ConfirmPrompt(0) != 0) && (Options_ConfirmPrompt(1) != 0)) {
                Options_EraseSaveData();
                Options_ShowEraseCompleteScreen();
            }
            break;

        case 3:
            Audio_PlaySoundEffectById(0x1D);
            Options_ApplySoundSettings(D_82C01666);
            sp1E = 1;
            break;
    }

    return sp1E;
}

void Options_Loop(void) {
    s16 i;
    s16 var_s1 = 0;

    StageFade_StartFromOpaque(8);
    while (StageContext_GetFadeMode() != 0) {
        Controller_PollInputs();
        Options_Draw(0, 0, 0, 0);
    }

    for (i = 1; i < 8; i++) {
        Controller_PollInputs();
        Options_Draw(i, 0, 0, 0);
    }

    while (var_s1 == 0) {
        Controller_PollInputs();
        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
            D_82C01664 = (D_82C01664 + 3) % 4;
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
            D_82C01664 = (D_82C01664 + 1) % 4;
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            var_s1 = Options_ApplySelection();
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            var_s1 = 2;
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
        }
        Options_Draw(8, 0, 0, 0);
    }

    for (i = 7; i > 0; i--) {
        Controller_PollInputs();
        Options_Draw(i, 0, 0, 0);
    }

    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromTransparent(8);

    while (StageContext_GetFadeMode() != 1) {
        Controller_PollInputs();
        Options_Draw(0, 0, 0, 0);
    }
}

s32 Options_Main(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('PREF');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    Font_Init(0x1C, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, menu_select_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);

    Text_InitStringTables();
    D_82C01660 = Text_GetStringTable(0x15);
    Save_EnsureAllBanksLoaded();
    Save_GetOptionsField02(&D_82C01666);
    D_82C01664 = 0;
    StageContext_Activate(sp24);
    Options_Loop();
    StageContext_Deactivate();
    Save_FlushDirtyBanks();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('PREF');

    return 4;
}
