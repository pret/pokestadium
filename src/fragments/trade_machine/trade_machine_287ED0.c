#include "trade_machine.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/ui_graphics.h"
#include "src/status_icons.h"
#include "src/gb_data.h"
#include "src/pokemon_stats.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/audio_loop_point.h"
#include "src/gfx_buffer.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_82F14438 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x10 */ s8* unk_10;
} unk_D_82F14438; // size = 0x14

typedef struct unk_D_82F144B0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
} unk_D_82F144B0; // size = 0xA

static FontContext* D_82F14420;
s32 D_82F14424;
static s32 D_82F14428;
static s16 D_82F1442C;
static unk_D_82F13B78* D_82F14430;
static s32 pad_D_82F14434;
static unk_D_82F14438 D_82F14438;
static unk_D_82F14438* D_82F1444C;
unk_D_82F14450 D_82F14450[4];
static s16 D_82F144A8;
static s16 D_82F144AA;
static s32 pad_D_82F144AC;
static unk_D_82F144B0 D_82F144B0;
static s32 D_82F144BC;
static s32 D_82F144C0;
static char** D_82F144C4;
static char** D_82F144C8;
static char** D_82F144CC;

char** gTradeStrings = NULL;
char** D_82F13B74 = NULL;
static unk_D_82F13B78 D_82F13B78[2] = {
    { 0x0140, 0x0168, NULL },
    { 0x0000, 0x0000, NULL },
};
static u16 D_82F13B88 = 0;

char* Trade_GetSpeciesName(s32 arg0) {
    return Text_GetString(NULL, 0, D_82F144C4, arg0 - 1);
}

char* Trade_GetMoveName(s32 arg0) {
    return Text_GetString(NULL, 0, D_82F144C8, arg0 - 1);
}

char* Trade_GetTypeName(s32 arg0) {
    return Text_GetString(NULL, 0, D_82F144CC, PokemonType_ToDisplayIndex(arg0));
}

void Trade_SetFadeRect(s16 arg0) {
    unk_D_82F144B0* ptr = &D_82F144B0;

    switch (arg0) {
        case 0:
            ptr->unk_02 = 0;
            ptr->unk_04 = 0;
            ptr->unk_06 = 0x280;
            ptr->unk_08 = 0x1E0;
            break;

        case 1:
            ptr->unk_02 = 0;
            ptr->unk_04 = 0x154;
            ptr->unk_06 = 0x280;
            ptr->unk_08 = 0x8C;
            break;
    }
}

void Trade_ResetFade(void) {
    D_82F144B0.unk_00 = -1;
    Trade_SetFadeRect(0);
}

void Trade_DrawFadeRect(void) {
    unk_D_82F144B0* ptr = &D_82F144B0;

    if ((ptr->unk_00 != 0) && (TradeCable_IsSequenceActive() != 0)) {
        if (ptr->unk_00 > 0) {
            ptr->unk_00--;
        }

        gSPDisplayList(gDisplayListHead++, D_8006F4C0);
        gDPSetFillColor(gDisplayListHead++, 0x00010001);
        gDPFillRectangle(gDisplayListHead++, ptr->unk_02, ptr->unk_04, (ptr->unk_02 + ptr->unk_06) - 1,
                         (ptr->unk_04 + ptr->unk_08) - 1);
    }
}

void Trade_ResetTextPrinter(void) {
    D_82F1444C = &D_82F14438;
    D_82F14438.unk_00 = 0;
    D_82F14438.unk_02 = 0;
    D_82F14438.unk_08 = 0;
    D_82F14438.unk_0A = 2;
    D_82F14438.unk_04 = 0;
    D_82F14438.unk_06 = 0;
    D_82F14438.unk_0C = 0;
    D_82F14438.unk_10 = NULL;
}

void Trade_SetTextPrinter(s16 arg0, s16 arg1, s8* arg2, s32 arg3) {
    s8* ptr;

    D_82F1444C->unk_00 = 0;
    D_82F1444C->unk_02 = 0;

    ptr = arg2;
    if (ptr != NULL) {
        while (*ptr != '\x00') {
            D_82F1444C->unk_02++;
            ptr++;
        }
    }

    D_82F1444C->unk_08 = 0;
    D_82F1444C->unk_0A = 2;
    D_82F1444C->unk_04 = arg0;
    D_82F1444C->unk_06 = arg1;
    D_82F1444C->unk_0C = 0;

    if (arg3 != 0) {
        D_82F1444C->unk_0C |= 1;
    }

    D_82F1444C->unk_10 = arg2;
}

void Trade_ResetTextMenu(void) {
    D_82F14430 = NULL;
}

void Trade_ShowTextMenu(unk_D_82F13B78* arg0, s32 arg1) {
    if (arg0 != D_82F14430) {
        D_82F1442C = 0;
    }

    D_82F14430 = arg0;

    if (NULL != arg0) {
        unk_D_82F13B78* ptr = &arg0[D_82F1442C];

        Trade_SetTextPrinter(ptr->unk_00, ptr->unk_02, ptr->unk_04, arg1);
        D_82F1442C++;
    }
}

s32 Trade_IsTextMenuAtEnd(unk_D_82F13B78* arg0) {
    unk_D_82F13B78* ptr = &arg0[D_82F1442C];
    s32 var_v1 = 0;

    if (ptr->unk_04 == NULL) {
        var_v1 = 1;
    }
    return var_v1;
}

void Trade_UpdateTextPrinter(void) {
    u8 tmp;

    if ((D_82F1444C->unk_10 != 0) && (D_82F1444C->unk_00 >= 0)) {
        if (gPlayer1Controller->buttonPressed & 0x8000) {
            D_82F1444C->unk_08 = 0;
            D_82F1444C->unk_0A = 1;
        } else {
            D_82F1444C->unk_08 -= 1;
        }

        if (D_82F1444C->unk_08 <= 0) {
            Audio_PlaySoundEffectById(SFX_TRADE_TEXT);
            D_82F1444C->unk_08 = D_82F1444C->unk_0A;

            D_82F1444C->unk_00++;

            tmp = D_82F1444C->unk_10[D_82F1444C->unk_00 - 1];
            if (tmp >= 0x80) {
                D_82F1444C->unk_00++;
            }

            if (D_82F1444C->unk_00 >= D_82F1444C->unk_02) {
                D_82F1444C->unk_00 = -1;
            }
        }
    }
}

s32 Trade_GetTextPrinterState(void) {
    s32 var_v1 = 0;

    if (D_82F1444C->unk_10 != NULL) {
        if (D_82F1444C->unk_00 == -1) {
            var_v1 = 2;
        } else if (D_82F1444C->unk_00 >= 0) {
            var_v1 = 1;
        }
    }

    return var_v1;
}

void Trade_DrawTextPrinter(void) {
    s32 i;
    s32 temp_t0;
    s8 sp38[0x100];

    if (D_82F1444C->unk_10 != NULL) {
        Font_BeginTranslucentTextRendering();
        Font_SetActive(0x10, 0);

        if (D_82F1444C->unk_0C & 1) {
            s32 a = D_82F13B88;
            u8 arg = a & 0xF;

            arg = (arg * 0xFF) / 15;
            if (a & 0x10) {
                arg = 0xFF - arg;
            }
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, arg);
        } else {
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        }

        Font_SetLineHeight(0x1E);
        temp_t0 = Font_MeasureTextExtent(0, 0, D_82F1444C->unk_10) / 2;
        if (D_82F1444C->unk_00 == -1) {
            Font_Printf(D_82F1444C->unk_04 - temp_t0, D_82F1444C->unk_06, D_82F1444C->unk_10);
        } else {
            s8* p_sp38 = sp38;
            s8* other = D_82F1444C->unk_10;

            for (i = 0; i < D_82F1444C->unk_00; i++) {
                *p_sp38++ = *other++;
            }

            *p_sp38 = '\x00';
            Font_Printf(D_82F1444C->unk_04 - temp_t0, D_82F1444C->unk_06, &sp38);
        }
        Font_EndTexturedTextRendering();
        D_82F13B88++;
    }
}

void Trade_ReadInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void Trade_ScanPorts(void) {
    UNUSED s32 pad;
    unk_D_82F14450* ptr;
    GbSavePlayerIdentity sp40;
    u8 temp_s2 = Cont_GetControllerBits();
    s32 i;

    main_pool_push_state('info');

    for (i = 0, ptr = &D_82F14450[0]; i < 4; i++, ptr++) {
        GbSave_CopyPlayerIdentity(i, &sp40);
        GbSave_EnsureMainDataLoaded(i);
        Text_UntranscodeNameWrapper(ptr->unk_08, sp40.unk_02);
        ptr->unk_06 = sp40.unk_00;
        ptr->unk_01 = GbSave_GetPortGame(i);
        ptr->unk_00 = GbSave_GetSaveState(i);
        ptr->unk_03 = GbSave_SavedAtPokemonCenter(i);
        ptr->unk_04 = GbSave_HasPokedex(i);
        ptr->unk_05 = (temp_s2 & (1 << i)) != 0;
        ptr->unk_02 = GbSave_GetPartyCount(i);
    }

    main_pool_pop_state('info');
}

void Trade_SwapSelections(void) {
    s32 i;
    unk_func_82F00838_sp30_00C sp50;
    unk_func_82F00838_sp30 sp30[2];

    for (i = 0; i < 2; i++) {
        Trade_GetPickScreenSnapshot(i, &sp30[i]);
    }

    sp50 = sp30[0].unk_0C[sp30[0].unk_06];
    sp30[0].unk_0C[sp30[0].unk_06] = sp30[1].unk_0C[sp30[1].unk_06];
    sp30[1].unk_0C[sp30[1].unk_06] = sp50;

    Trade_SwapPickBuffers();
}

void func_82F00960(void) {
}

void Trade_Init(void) {
    ModelRenderer_InitDisplayRoots();
    Text_InitStringTables();
    gTradeStrings = Text_GetStringTable(0x21);
    D_82F13B74 = Text_GetStringTable(6);
    D_82F144C4 = Text_GetStringTable(0x24);
    D_82F144C8 = Text_GetStringTable(0x25);
    D_82F144CC = Text_GetStringTable(0x26);
    D_82F13B78[0].unk_04 = Text_GetString(NULL, 0, gTradeStrings, 0);
    D_82F14428 = 0;
    Trade_ResetTextMenu();
    D_82F14424 = 0;
    D_82F144A8 = 0;
    D_82F144BC = 0;
    Trade_ResetFade();
    Trade_ResetTextPrinter();
    TradeCable_InitSequence();
    Trade_ScanPorts();
    Trade_InitBoxMachine();
    Trade_ResetPickScreens();
    Trade_ResetSaveSeq();
}

void Trade_Draw(void) {
    BgStage_DrawFrame();
    Trade_DrawFadeRect();
    if (TradeCable_IsSequenceActive() != 0) {
        TradeCable_DrawSequence();
    }
    Trade_DrawTextPrinter();
    Trade_DrawBoxMachine();
    Trade_DrawPickScreens();
    Trade_DrawSaveSeq();
    func_82F00960();
    BgStage_AdvanceFrame();
}

void Trade_SetState(s32 arg0) {
    D_82F14428 = arg0;

    switch (D_82F14428) {
        case 1:
            Trade_ResetTextMenu();
            Trade_ShowTextMenu(D_82F13B78, 0);
            break;

        case 2:
            Trade_ResetBoxMachineFlow();
            Trade_SetTextPrinter(0, 0, 0, 0);
            break;

        case 4:
            if (D_82F144A8 == 1) {
                if (D_82F144BC != 0) {
                    main_pool_pop_state('pmex');
                }
                main_pool_push_state('pmex');
                D_82F144BC = 1;
            }
            GbSave_LoadPort(Trade_GetSelectedBox(D_82F144A8));
            Trade_InitPickScreen(D_82F144A8, Trade_GetSelectedBox(D_82F144A8));
            break;

        case 5:
            Trade_InitSaveSequence(0);
            break;

        case 6:
            Trade_InitSaveSequence(1);
            break;

        case 7:
            Trade_SetFadeRect(0);
            StageFade_StartFromTransparent(0xF);
            Audio_FadeOutAll(0xF);
            break;
    }
}

void Trade_ChangeTopic(s16 arg0) {
    D_82F144AA = arg0;
    Trade_SetState(3);
    TradeCable_SetSequenceState(D_82F144AA);
}

void Trade_UpdateMainMenu(void) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        if (Trade_IsTextMenuAtEnd(D_82F13B78) == 0) {
            Trade_ShowTextMenu(D_82F13B78, 0);
        } else {
            Trade_SetState(2);
        }
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        Audio_PlaySoundEffectById(SFX_PANEL_OPEN);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        Trade_SetState(7);
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
}

void Trade_UpdateWaitForBoxConfirm(void) {
    Trade_SetFadeRect(1);
    if (Trade_GetBoxMachineFlowState() == 0) {
        if (Trade_GetSelectedBox(1) == -1) {
            Trade_SetState(7);
        } else {
            Trade_ChangeTopic(1);
        }
    }
}

void Trade_UpdateWaitForCableCondition(void) {
    Trade_SetFadeRect(0);

    switch (D_82F144AA) {
        case 1:
            if (TradeCable_CheckSequenceCondition(1) != 0) {
                Trade_SetState(4);
            }
            break;

        case 19:
            if (TradeCable_CheckSequenceCondition(2) != 0) {
                Trade_SetState(4);
            }
            break;

        case 4:
        case 8:
        case 11:
            if (TradeCable_CheckSequenceCondition(3) != 0) {
                Trade_SetState(2);
            }
            break;

        case 20:
            if (TradeCable_CheckSequenceCondition(6) != 0) {
                Trade_SetState(5);
            }
            break;

        case 21:
            if (TradeCable_CheckSequenceCondition(8) != 0) {
                Trade_SwapSelections();
                Trade_ChangeTopic(0xC);
            }
            break;

        case 12:
            if (TradeCable_CheckSequenceCondition(0xC) != 0) {
                if (D_82F144B0.unk_00 == -1) {
                    D_82F144B0.unk_00 = 5;
                }
            } else {
                D_82F144B0.unk_00 = -1;
            }

            if (TradeCable_CheckSequenceCondition(0xA) != 0) {
                Trade_SetState(6);
            }
            break;
    }
}

void Trade_UpdateWaitForPickSelection(void) {
    unk_func_82F00838_sp30 sp20;

    if (Trade_IsPickScreenActive() == 0) {
        Trade_GetPickScreenSnapshot(D_82F144A8, &sp20);

        if (sp20.unk_00 != 0) {
            if (D_82F144A8 == 0) {
                Trade_ChangeTopic(0x13);
            } else {
                Trade_ChangeTopic(0x14);
            }
            D_82F144A8 ^= 1;
        } else {
            if (D_82F144A8 == 0) {
                Trade_SetTextPrinter(0, 0, NULL, 0);
                Trade_ChangeTopic(4);
                return;
            }
            Trade_ChangeTopic(8);
            D_82F144A8 = 0;
        }
    }
}

void Trade_UpdateWaitForDepositSave(void) {
    Trade_SetFadeRect(1);

    if (Trade_GetSaveSeqState() == 2) {
        if (D_82F144B0.unk_00 == -1) {
            D_82F144B0.unk_00 = 3;
        }
    } else {
        D_82F144B0.unk_00 = -1;
    }

    if (Trade_GetSaveSeqState() == 0) {
        if (Trade_GetSaveDirection() != 0) {
            Trade_ChangeTopic(0x15);
        } else {
            Trade_ChangeTopic(0xB);
        }
    }
}

void Trade_UpdateWaitForWithdrawSave(void) {
    Trade_SetFadeRect(1);

    if (Trade_GetSaveSeqState() == 2) {
        if (D_82F144B0.unk_00 == -1) {
            D_82F144B0.unk_00 = 3;
        }
    } else {
        D_82F144B0.unk_00 = -1;
    }

    if (Trade_GetSaveSeqState() == 7) {
        D_82F144C0 = 0;
    } else {
        D_82F144C0 = 1;
    }

    if (Trade_GetSaveSeqState() == 0) {
        if (Trade_GetSaveSlotIndex() != 0) {
            Trade_SetState(2);
        } else {
            Trade_SetState(7);
        }
    }
}

s32 Trade_Update(void) {
    s32 sp1C = 1;

    switch (D_82F14428) {
        case 0:
            if (StageContext_GetFadeMode() == 0) {
                Trade_SetState(1);
            }
            break;

        case 1:
            Trade_UpdateMainMenu();
            break;

        case 2:
            Trade_UpdateWaitForBoxConfirm();
            break;

        case 3:
            Trade_UpdateWaitForCableCondition();
            break;

        case 4:
            Trade_UpdateWaitForPickSelection();
            break;

        case 5:
            Trade_UpdateWaitForDepositSave();
            break;

        case 6:
            Trade_UpdateWaitForWithdrawSave();
            break;

        case 7:
            if (StageContext_GetFadeMode() == 1) {
                sp1C = 0;
            }
            break;
    }
    return sp1C;
}

void Trade_Loop(void) {
    StageFade_StartFromOpaque(0x10);
    Audio_StartMusicTrack(0x10);
    Input_SetRepeatController(gPlayer1Controller);

    D_82F144C0 = 1;

    do {
        if (D_82F144C0 != 0) {
            Trade_ReadInput();
        }
        Trade_UpdateTextPrinter();
        Trade_UpdateBoxMachine();
        Trade_UpdatePickScreens();
        Trade_UpdateSaveSeq();
        TradeCable_UpdateSequence();
        Trade_Draw();
        D_82F14424++;
    } while (Trade_Update() != 0);
}

s32 Trade_Main(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('PMEX');

    Gfx_InitDisplayListBuffers(0x14000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    D_82F14420 = Font_Init(0x1E, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, trade_select_ui, 0);

    FRAGMENT_LOAD(fragment31);

    PokeIcon_OpenModelArchives();
    PokeIcon_OpenModelArchive();
    Trade_Init();
    StageContext_Activate(sp24);
    Trade_Loop();
    StageLoader_RunFrames(2);
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('PMEX');

    return 0;
}
