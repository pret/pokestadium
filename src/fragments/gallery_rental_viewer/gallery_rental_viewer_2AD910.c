#include "gallery_rental_viewer.h"
#include "src/poke_icon.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/pokemon_stats.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/gfx_buffer.h"
#include "src/controller.h"
#include "src/fragments/minigame_select/minigame_select.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static s32 D_83805650;
static s32 D_83805654;
static void* D_83805658;
static unk_D_8380565C* D_8380565C;
static s32 D_83805660;
static s32 D_83805664;
static s32 D_83805668;

void Gallery_RentalViewerInit(s32 arg0) {
    D_83805654 = 0;
    D_83805650 = arg0;
    D_83805668 = -1;
    D_83805660 = -1;
    Text_InitStringTables();
    Gallery_InitStringTables();
    Gallery_RentalViewerInitScene();
    Gallery_RentalViewerInitBoxPicker(0x68, 0x8A, D_8380565C);
    Gallery_ResetConfirmPrompt();
}

void Gallery_RentalViewerSetFadeCounter(s32 arg0) {
    D_83805668 = arg0;
}

void Gallery_RentalViewerDrawIcon(s32 arg0, s32 arg1) {
    Gfx_DrawTextureRgba16(arg0, arg1, 0x40, 0x18, D_04000000, 0x40, 0);
    Gfx_DrawTextureRgba16(arg0, arg1 + 0x18, 0x40, 0x18, D_4000C00, 0x40, 0);
}

void Gallery_RentalViewerDrawTitleBar(void) {
    char* sp2C = Gallery_GetUiString(4);
    Color_RGBA8 sp28 = { 0x9A, 0x37, 0x54, 0xFF };
    Color_RGBA8 sp24 = { 0xC3, 0x54, 0x84, 0xFF };

    Gallery_DrawHeaderBar(0x48, 0x28, 0x208, &sp28, &sp24);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gallery_RentalViewerDrawIcon(0x28, 0x20);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0, 0, 0, 0xFF);
    Font_Printf(0x7A, 0x2D, sp2C);
    Gfx_SetEnvColor(0xFF, 0xFF, 0x77, 0xFF);
    Font_Printf(0x78, 0x2B, sp2C);
    Font_EndTexturedTextRendering();
}

void Gallery_RentalViewerDrawFrame(void) {
    BgStage_DrawFrame();
    if (D_83805668 != 0) {
        Gfx_DrawTiledRgba16Image(D_83805658);
        Gallery_RentalViewerDrawTitleBar();
    }
    Gallery_RentalViewerDrawTeamList(1);
    func_838043F8(1);
    Gallery_DrawConfirmPrompt(1);
    BgStage_AdvanceFrame();
    if (D_83805668 > 0) {
        D_83805668 -= 1;
    }
}

void Gallery_RentalViewerLoadPort(s32 arg0) {
    D_83805654 = 2;
    Gallery_RentalViewerSetFadeCounter(0xC);

    main_pool_push_state('glpc');

    if ((D_83805664 >= 0) && (D_83805664 < 4)) {
        GbSave_LoadPort(D_83805664);
    }

    if (arg0 != 0) {
        Gallery_RentalViewerOpenBoxPicker(D_83805664, &D_83407B18.unk_08);
    } else {
        Gallery_RentalViewerOpenBoxPicker(D_83805664, NULL);
    }
}

void Gallery_RentalViewerUpdateLoadConfirm(void) {
    D_83805660 = Gallery_GetConfirmPromptResult(2);

    if (D_83805660 != -1) {
        if (D_83805660 == -2) {
            D_83805660 = 2;
        }

        if (D_83805660 != 2) {
            D_83805654 = 4;
            StageFade_StartFromTransparent(0xF);
        } else {
            D_83805654 = 1;
            Gallery_RentalViewerBeginZoomIntro(D_83805664);
            D_83805660 = -1;
        }
    }
}

s32 Gallery_RentalViewerHandleInput(void) {
    static s32 D_83804CB8 = 4;

    s32 sp7C = 1;
    s32 sp78 = 0;
    s32 sp74;
    BattleMon sp20;

    switch (D_83805654) {
        case 0:
            if (StageContext_GetFadeMode() == 0) {
                D_83804CB8--;
                if (D_83804CB8 <= 0) {
                    D_83805654 = 1;
                    if (D_83805650 == 1) {
                        D_83805664 = D_83407B18.unk_08.unk_00;
                        Gallery_RentalViewerLoadPort(1);
                    } else {
                        if (D_83805650 == 2) {
                            D_83805664 = 5;
                        } else {
                            D_83805664 = -1;
                        }
                        Gallery_RentalViewerBeginZoomIntro(D_83805664);
                    }
                }
            }
            break;

        case 1:
            D_83805664 = Gallery_RentalViewerGetSelectedSlot();
            switch (D_83805664) {
                case -2:
                    if (D_83402E20 > 0) {
                        D_83805654 = 3;
                        Gallery_OpenConfirmPrompt(2, gPlayer1Controller);
                    } else {
                        sp78 = 1;
                    }
                    break;

                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                    Gallery_RentalViewerLoadPort(0);
                    break;

                case 5:
                    sp78 = 1;
                    _bcopy(&D_8380565C->unk_7E4, &sp20, sizeof(BattleMon));
                    Gallery_CopyPhotoMonFromBattleMon(&D_83407AC8, &sp20);
                    break;
            }

            if (sp78 != 0) {
                D_83805654 = 4;
                StageFade_StartFromTransparent(0xF);
            }
            break;

        case 2:
            sp74 = Gallery_RentalViewerGetLoadState();
            if (sp74 != 0) {
                main_pool_pop_state('glpc');

                D_83805668 = -1;
                if (sp74 > 0) {
                    D_83805654 = 4;
                    StageFade_StartFromTransparent(0xF);
                } else {
                    D_83805654 = 1;
                    Gallery_RentalViewerBeginZoomIntro(D_83805664);
                }
            }
            break;

        case 3:
            Gallery_RentalViewerUpdateLoadConfirm();
            break;

        case 4:
            if (StageContext_GetFadeMode() == 1) {
                sp7C = 0;
            }
            break;
    }
    return sp7C;
}

void Gallery_RentalViewerPollInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void Gallery_RentalViewerLoop(void) {
    StageFade_StartFromOpaque(7);
    do {
        Gallery_RentalViewerPollInput();
        Gallery_RentalViewerUpdate();
        Gallery_RentalViewerUpdateBoxPicker();
        Gallery_UpdateConfirmPrompt();
        Gallery_RentalViewerDrawFrame();
    } while (Gallery_RentalViewerHandleInput() != 0);
}

s32 Gallery_RentalViewerGetResult(void) {
    s32 var_v1;
    unk_D_83407B18_008* temp_a0 = &D_83407B18.unk_08;
    temp_a0 += 0;

    if (D_83805660 == 0) {
        var_v1 = 2;
    } else if (D_83805660 == 1) {
        var_v1 = 0;
    } else {
        switch (D_83805664) {
            case -2:
                var_v1 = 0;
                break;

            case 5:
                var_v1 = 6;
                break;

            default:
                var_v1 = 1;
                break;
        }
    }

    temp_a0->unk_00 = D_83805664;
    Gallery_RentalViewerSaveBoxCursor(temp_a0);
    return var_v1;
}

s32 Gallery_RentalViewerMain(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('SLCT');

    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    D_8250A304 = Font_Init(0x1C, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    ASSET_LOAD(D_3000000, gallery_ui, 0);
    ASSET_LOAD(D_04000000, snap_select_ui, 0);

    D_83805658 = BinArchive_GetFile(ASSET_LOAD2(backgrounds, 1, 1), 0x14);
    D_8380565C = BinArchive_GetFile(BinArchive_Open(TRAINER_DATA_ROM_START, NULL, 1, 0), 0x1A);

    PokeIcon_OpenModelArchive();
    Gallery_RentalViewerInit(arg0);
    StageContext_Activate(sp24);
    Gallery_RentalViewerLoop();
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('SLCT');

    return Gallery_RentalViewerGetResult();
}
