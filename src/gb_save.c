#include "gb_save.h"
#include "src/input.h"
#include "src/gb_data.h"
#include "src/pokemon_stats.h"
#include "src/save_data.h"
#include "src/game_state.h"
#include "src/audio_sfx.h"
#include "src/gfx_buffer.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static OSMesgQueue D_800AF750;
static s32 D_800AF768;

static Color_RGBA8 D_800758A0[] = {
    { 0xF0, 0xF0, 0xF0, 0xFF },
    { 0xE1, 0xE1, 0xE1, 0xFF },
};

static u32 D_800758A8[] = {
    D_04001878, D_040018E0, D_04001948, D_040019B0, D_04001A18, D_04001A80, D_04001AF0,
    D_04001B58, D_04001BC0, D_04001C28, 0x10,       0x10,       0x10,       D_4001010,
};

unk_func_88500020 D_800758E0 = {
    0x00000014,
    0x00000014,
    0x00000014,
    D_4001C90,
};

unk_func_88500020 D_800758F0[] = {
    {
        0x00000014,
        0x00000014,
        0x00000014,
        D_4001FB8,
    },
    {
        0x00000018,
        0x00000018,
        0x00000018,
        D_4006AB8,
    },
};

void GbSave_BuildPortSummary(unk_func_8002D860* arg0, s32 arg1) {
    if (GbSave_GetSaveState(arg1) != 0) {
        arg0->unk_00 = 1;
    } else {
        arg0->unk_00 = 0;
        arg0->unk_08 = GbSave_GetTrainerId(arg1);
        GbSave_GetPlayerName(arg1, &arg0[1]);
    }
    arg0->unk_04 = GbSave_GetPortGame(arg1);
}

void Gfx_DrawTiledTextureStrip(unk_func_88500020* arg0, s32 arg1, s32 a2) {
    s32 temp_lo;
    s32 var_t0;
    u8* var_s2;
    s32 i;
    s32 arg2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    temp_lo = 0x1000 / (arg0->unk_00 * 2);
    var_s2 = arg0->unk_0C;
    arg2 = a2;
    i = arg0->unk_04;

    while (i > 0) {
        if (temp_lo < i) {
            var_t0 = temp_lo;
        } else {
            var_t0 = i;
        }

        gDPLoadTextureBlock(gDisplayListHead++, var_s2, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg0->unk_00, var_t0, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, arg1 << 2, arg2 << 2, ((arg1 + arg0->unk_08) - 1) << 2,
                            ((arg2 + var_t0) - 1) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

        i -= var_t0;
        arg2 += var_t0;
        var_s2 += var_t0 * arg0->unk_00 * 2;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
}

s32 Ui_AdjustVerticalSelection(unk_func_8002DCB8_arg0* arg0, s32 arg1) {
    s32 ret = 0;

    switch (arg1) {
        case 0x800:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_04 == 0) {
                arg0->unk_04 += arg0->unk_08;
            }
            arg0->unk_04--;
            ret = 1;
            break;

        case 0x400:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_04 >= (arg0->unk_08 - 1)) {
                arg0->unk_04 -= arg0->unk_08;
            }
            arg0->unk_04++;
            ret = 1;
            break;
    }

    return ret;
}

s32 Ui_HandleVerticalSelectionInput(s32 arg0) {
    s32 sp1C = Input_GetRepeatedDPad() & 0xFFFF;

    Ui_AdjustVerticalSelection(arg0, sp1C);
    return sp1C;
}

s32 Ui_AdjustHorizontalSelection(unk_func_8002DD98_arg0* arg0, s32 arg1) {
    s32 ret = 0;

    switch (arg1) {
        case 0x200:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_04 == 0) {
                arg0->unk_04 += arg0->unk_08;
            }
            arg0->unk_04--;
            ret = 1;
            break;

        case 0x100:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_04 >= (arg0->unk_08 - 1)) {
                arg0->unk_04 -= arg0->unk_08;
            }
            arg0->unk_04++;
            ret = 1;
            break;
    }

    return ret;
}

s32 Ui_HandleHorizontalSelectionInput(unk_func_8002DD98_arg0* arg0) {
    s32 sp1C = Input_GetRepeatedDPad() & 0xFFFF;

    Ui_AdjustHorizontalSelection(arg0, sp1C);
    return sp1C;
}

void Ui_AdjustSteppedScrollSelection(unk_func_8002DE78_arg0* arg0) {
    s32 temp_v0 = Input_GetRepeatedDPad();
    s32 sp18 = arg0->unk_0C;

    if (gPlayer1Controller->buttonDown & 0x2000) {
        sp18 = ((arg0->unk_08 - arg0->unk_04) + 1) / 10;
    }

    switch (temp_v0) {
        case 0x800:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_00 - sp18 < arg0->unk_04) {
                arg0->unk_00 = arg0->unk_04;
            } else {
                arg0->unk_00 -= sp18;
            }
            break;

        case 0x400:
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            if (arg0->unk_08 < arg0->unk_00 + sp18) {
                arg0->unk_00 = arg0->unk_08;
            } else {
                arg0->unk_00 += sp18;
            }
            break;
    }
}

s32 Ui_AdjustNumericSelection(unk_func_8830867C_044_038_030* arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a2;
    s32 var_t1;
    s32 i;

    var_t1 = 0;
    var_a2 = 1;

    for (i = arg0->unk_10; i > 0; i--) {
        var_a2 *= 10;
    }

    switch (arg1) {
        case 0x200:
            temp_v0 = arg0->unk_10 + 1;
            if (temp_v0 < arg0->unk_0C) {
                arg0->unk_10 = temp_v0;
                Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
                var_t1 = 9;
            } else {
                var_t1 = 8;
            }
            break;

        case 0x100:
            if (arg0->unk_10 > 0) {
                arg0->unk_10--;
                Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
                var_t1 = 9;
            } else {
                var_t1 = 8;
            }
            break;

        case 0x800:
            if (arg0->unk_00 == arg0->unk_08) {
                arg0->unk_00 = arg0->unk_00 - ((arg0->unk_00 / var_a2) * var_a2);
                if (arg0->unk_00 < arg0->unk_04) {
                    arg0->unk_00 = arg0->unk_04;
                }
            } else {
                arg0->unk_00 += var_a2;
                if (arg0->unk_08 < arg0->unk_00) {
                    arg0->unk_00 = arg0->unk_08;
                }
            }
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            var_t1 = 9;
            break;

        case 0x400:
            if (arg0->unk_00 == arg0->unk_04) {
                arg0->unk_00 = arg0->unk_08;
            } else {
                arg0->unk_00 -= var_a2;
                if (arg0->unk_00 < arg0->unk_04) {
                    arg0->unk_00 = arg0->unk_04;
                }
            }
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            var_t1 = 9;
            break;
    }
    return var_t1;
}

s32 Ui_HandleNumericSelectionInput(unk_func_8820E99C_030_030* arg0) {
    s32 sp1C = Input_GetRepeatedDPad() & 0xFFFF;

    Ui_AdjustNumericSelection(arg0, sp1C);
    return sp1C;
}

s32 Ui_AdjustSteppedRangeSelection(unk_func_8002E128_arg0* arg0) {
    s32 sp1C = Input_GetRepeatedDPad() & 0xFFFF;
    s32 sp18 = arg0->unk_0C;

    if (sp1C != 0) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);

        switch (sp1C) {
            case 0x200:
                sp18 *= 0xA;

            case 0x800:
                if (arg0->unk_00 >= arg0->unk_08) {
                    arg0->unk_00 = arg0->unk_04;
                } else if (arg0->unk_08 < (arg0->unk_00 + sp18)) {
                    arg0->unk_00 = arg0->unk_08;
                } else {
                    arg0->unk_00 = arg0->unk_00 + sp18;
                }
                break;

            case 0x100:
                sp18 *= 0xA;

            case 0x400:
                if (arg0->unk_04 >= arg0->unk_00) {
                    arg0->unk_00 = arg0->unk_08;
                } else if ((arg0->unk_00 - sp18) < arg0->unk_04) {
                    arg0->unk_00 = arg0->unk_04;
                } else {
                    arg0->unk_00 = arg0->unk_00 - sp18;
                }
                break;
        }
    }

    return sp1C;
}

void Gfx_DrawNumber(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 temp_lo;
    s32 var_s3;
    s32 var_t5 = 0x05F5E100;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    var_s3 = 0;

    for (i = 9; i > 0;) {
        temp_lo = arg2 / var_t5;
        i--;

        if ((temp_lo != 0) || (var_s3 != 0) || (i == 0)) {
            var_s3 = 1;

            gDPLoadTextureBlock(gDisplayListHead++, D_800758A8[temp_lo], G_IM_FMT_IA, G_IM_SIZ_8b, 8, 12, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + 8) << 2, (arg1 + 0xC) << 2,
                                G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
            arg0 += 9;
        }

        arg2 %= var_t5;
        var_t5 /= 10;
    }
}

void Gfx_DrawNumberFixedWidth(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_t0 = 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    while (arg3 > 0) {
        arg3--;
        if ((arg2 > 0) || (var_t0 != 0)) {
            gDPLoadTextureBlock(gDisplayListHead++, D_800758A8[arg2 % 10], G_IM_FMT_IA, G_IM_SIZ_8b, 8, 12, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, (arg0 + (arg3 * 9)) << 2, arg1 << 2, ((arg0 + (arg3 * 9)) + 8) << 2,
                                (arg1 + 0xC) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        }
        arg2 /= 10;
        var_t0 = 0;
    }
}

void Gfx_DrawNumberDigits(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    while (arg3 > 0) {
        arg3--;
        gDPLoadTextureBlock(gDisplayListHead++, D_800758A8[arg2 % 10], G_IM_FMT_IA, G_IM_SIZ_8b, 8, 12, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (arg0 + (arg3 * 9)) << 2, arg1 << 2, ((arg0 + (arg3 * 9)) + 8) << 2,
                            (arg1 + 0xC) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        arg2 /= 10;
    }
}

s32 Ui_GetSelectionDirection(unk_func_8002EBD8_arg0* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_08 & 0x4000) {
        var_v1 = -1;
    } else if (arg0->unk_08 & 0x8000) {
        var_v1 = 1;
    }

    return var_v1;
}

s32 GbSave_GameToCategoryIndex(s32 arg0) {
    static s32 D_80075910[] = { 0, 0, 1, 2, 0, 0, 0, 3, 0, 0, 0, 0 };

    return D_80075910[arg0];
}

Color_RGBA8 Color_InterpolateFromGray(Color_RGBA8 arg0, f32 arg1) {
    static Color_RGBA8 D_80075940 = { 0xC8, 0xC8, 0xC8, 0xFF };

    Color_RGBA8 sp4;

    sp4.r = (s32)((arg0.r - D_80075940.r) * arg1) + D_80075940.r;
    sp4.g = (s32)((arg0.g - D_80075940.g) * arg1) + D_80075940.g;
    sp4.b = (s32)((arg0.b - D_80075940.b) * arg1) + D_80075940.b;
    sp4.a = arg0.a;

    return sp4;
}

static u8 pad_D_80075944[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s32 BattleMon_CountMoves(BattleMon* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (arg0->unk_09[i] == 0) {
            break;
        }
    }

    return i;
}

ret_func_8002ED08* Move_GetDisplayInfo(s32 arg0) {
    if ((arg0 <= 0) || (arg0 > 165)) {
        return NULL;
    }
    return &gMoveDisplayInfo[arg0 - 1];
}

MoveData* Move_GetData(s32 arg0) {
    if ((arg0 <= 0) || (arg0 >= 0xA6)) {
        return NULL;
    }
    return &gMoveData[arg0 - 1];
}

s32 Species_GetMoveSlot(BattleMon* arg0, s32 arg1) {
    s32 temp_v0 = arg0->unk_00.unk_00 - 1;
    s32 var_v1;

    if (arg1 == 1) {
        if (D_80070FA0[temp_v0].unk_06 == D_80070FA0[temp_v0].unk_07) {
            return -1;
        }
        var_v1 = D_80070FA0[temp_v0].unk_07;
    } else {
        var_v1 = D_80070FA0[temp_v0].unk_06;
    }
    return var_v1;
}

s32 Move_NormalizeDisplayIndex(s32 arg0) {
    s32 ret;

    if (arg0 >= 0x14) {
        ret = arg0 - 0xC;
    } else if (arg0 >= 7) {
        ret = arg0 - 1;
    } else {
        ret = arg0;
    }

    return ret;
}

s32 Deck_GetEntryCountForType(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp1C;

    switch (arg0) {
        case 32:
        case 33:
        case 34:
        case 35:
            sp1C = Deck_GetCount(arg0, arg1, arg2);
            break;

        case 16:
        case 17:
        case 18:
            sp1C = Deck_GetSaveEntryCount(arg0, arg2);
            break;
    }
    return sp1C;
}

void Ui_InitInputMessageQueue(void) {
    osCreateMesgQueue(&D_800AF750, &D_800AF768, 1);
}

void Ui_SendMessageAndPollInput(OSMesg arg0) {
    osSendMesg(&D_800AF750, arg0, 1);
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void Ui_SendNullMessage(void) {
    osSendMesg(&D_800AF750, NULL, 1);
}

void Ui_ReceiveMessage(OSMesg arg0) {
    osRecvMesg(&D_800AF750, arg0, 1);
}

void State_PokemonLab(void) {
    s32 game_state;
    s32 var_s4;

    FRAGMENT_LOAD_AND_CALL(FRAGMENT_TRANSFER_PAK_SELECT, 1, 0);

    if (GbSave_GetActivePort() == -1) {
        gCurrentGameState = STATE_AREA_SELECT;
        return;
    }

    var_s4 = 0;
    game_state = STATE_POKEMON_LAB;

    do {
        if (game_state == STATE_POKEMON_LAB) {
            main_pool_push_state('PLAB');

            if (GbSave_GetActivePort() != -1) {
                Save_EnsureBankLoaded(3);
                GbSave_LoadPort(GbSave_GetActivePort());
            }

#if defined(VERSION_JP)
            Gfx_InitDisplayListBuffers(0x11000, 0);
#else
            Gfx_InitDisplayListBuffers(0x16000, 0);
#endif
            StageContext_Activate(StageContext_Allocate(1, 1, 2, 0, 2, 1));

            FRAGMENT_LOAD_AND_CALL2(FRAGMENT_PROFESSOR_OAK_LAB, var_s4, 0);

            while ((game_state == STATE_POKEMON_LAB) && (D_800AE520.unk_00 != 0)) {
                D_800AE520.unk_00 = 0;
                game_state = Fragment_LoadAndCall(D_800AE520.fragment_id, D_800AE520.rom_start, D_800AE520.rom_end,
                                           D_800AE520.arg0, D_800AE520.arg1);
            }

            StageContext_Deactivate();
            Gfx_FreeDisplayListBuffers();

            main_pool_pop_state('PLAB');
        } else {
            switch (game_state) {
                case 0x10000:
                    FRAGMENT_LOAD_AND_CALL(FRAGMENT_TRADE_MACHINE, 0, 0);
                    var_s4 = 2;
                    game_state = STATE_POKEMON_LAB;
                    break;

                case 0x10001:
                    FRAGMENT_LOAD_AND_CALL(FRAGMENT_TRANSFER_PAK_SELECT, 0, 0);
                    var_s4 = 1;
                    game_state = STATE_POKEMON_LAB;
                    break;
            }
        }
    } while (game_state != STATE_AREA_SELECT);

    gCurrentGameState = STATE_AREA_SELECT;
}
