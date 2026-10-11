#include "trade_machine.h"
#include "src/poke_icon.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/ui_graphics.h"
#include "src/pokemon_stats.h"
#include "src/text_system.h"
#include "src/audio_sfx.h"
#include "src/gfx_rect.h"
#include "src/memory.h"

typedef struct unk_D_82F20A00 {
    /* 0x00000 */ u16 unk_00000[3][20][0x640];
} unk_D_82F20A00; // size = 0x2EE00

static unk_D_82F144D0 D_82F144D0[2];
static unk_D_82F20A00* D_82F20A00;
static s16 D_82F20A04;

s16 Trade_ReadDeckEntries(unk_D_82F144D0* arg0, s16 arg1) {
    UNUSED s32 pad;
    DeckHandle* var_v0;
    unk_func_82F00838_sp30_00C sp3C;
    unk_D_82F144D0_0CA8* sp34 = &arg0->unk_0CA8[arg1];

    sp34->unk_000 = 0;
    if (arg1 == 0) {
        var_v0 = Deck_Open(0x20, arg0->unk_000E, 0, 0);
    } else {
        var_v0 = Deck_Open(0x21, arg0->unk_000E, arg1 - 1, 0);
    }

    if (var_v0 != NULL) {
        while (Deck_ReadEntries(&sp3C, 1, var_v0) == 1) {
            sp34->unk_00C[sp34->unk_000++] = sp3C;
        }
        Deck_CloseAndFlush(var_v0);
    }
    return sp34->unk_000;
}

u16* Trade_GetPickBufferSlot(u8* arg0, s16 arg1, s16 arg2) {
    return arg0 + (arg1 * 0xFA00) + (arg2 * 0xC80);
}

void Trade_InitPickScreen(s32 arg0, s16 arg1) {
    MainPoolState* temp_v0_2;
    s32 var_s2;
    unk_D_82F144D0* temp_s1;
    s32 i;
    s32 j;
    unk_D_82F144D0_0CA8* ptr1;
    unk_D_82F144D0_0CA8* ptr2;
    unk_func_82F00838_sp30_00C* temp_a3;

    if ((arg0 < 0) || (arg0 >= 2)) {
        return;
    }

    if (GbSave_GetBoxCount(arg1) == 0) {
        GbSave_MarkBoxDataLoaded(arg1);
    }

    D_82F20A04 = arg0;

    main_pool_push_state('PICK');

    temp_s1 = &D_82F144D0[arg0];
    temp_s1->unk_0000 = 1;
    temp_s1->unk_0002 = -1;
    temp_s1->unk_0004 = 0x140;
    temp_s1->unk_0006 = 0xA0;
    temp_s1->unk_0008 = 0;
    temp_s1->unk_000A = 0;
    temp_s1->unk_000C = 0xA;
    temp_s1->unk_0010 = 0;
    temp_s1->unk_0012 = 0;
    temp_s1->unk_0014 = 0;
    temp_s1->unk_0016 = 0;
    temp_s1->unk_0018 = 0;
    temp_s1->unk_001A = 0;
    temp_s1->unk_001C = 0;
    temp_s1->unk_001E = 0;
    temp_s1->unk_0020 = 0;
    temp_s1->unk_000E = arg1;

    var_s2 = 0;

    for (i = 12; i >= 0; i--) {
        if (Trade_ReadDeckEntries(temp_s1, i) > 0) {
            temp_s1->unk_0010 = i;
            var_s2++;
        }
        temp_s1->unk_0CA8[i].unk_008 = NULL;
        temp_s1->unk_0CA8[i].unk_004 = NULL;
    }

    for (i = temp_s1->unk_0010; i < 13; i++) {
        ptr1 = &temp_s1->unk_0CA8[i];

        if (ptr1->unk_000 <= 0) {
            continue;
        }

        for (j = i + 1; j < 13; j++) {
            ptr2 = &temp_s1->unk_0CA8[j];

            if (ptr2->unk_000 > 0) {
                ptr1->unk_008 = ptr2;
                ptr2->unk_004 = ptr1;
                break;
            }
        }
    }

    if (var_s2 >= 2) {
        ptr1 = &temp_s1->unk_0CA8[0];
        while (ptr1->unk_000 <= 0) {
            ptr1++;
        }

        ptr2 = &temp_s1->unk_0CA8[12];
        while (ptr2->unk_000 <= 0) {
            ptr2--;
        }

        ptr1->unk_004 = ptr2;
        ptr2->unk_008 = ptr1;
    }

    temp_v0_2 = MainPool_AllocState(main_pool_get_available(), 0);
    D_82F20A00 = MainPool_AllocAligned(temp_v0_2, sizeof(unk_D_82F20A00), 8);
    MainPool_FinalizeAllocation(temp_v0_2);

    for (i = 0; i < temp_s1->unk_0CA8[temp_s1->unk_0010].unk_000; i++) {
        temp_a3 = &temp_s1->unk_0CA8[temp_s1->unk_0010].unk_00C[i];

        if (((temp_a3->unk_00 <= 0) || (temp_a3->unk_00 >= 0x98) ? 1 : 0)) {
            PokeIcon_LoadModelTextureForMon(Trade_GetPickBufferSlot(D_82F20A00, temp_s1->unk_0016, i), 0x98, NULL);
        } else {
            PokeIcon_LoadModelTextureForMon(Trade_GetPickBufferSlot(D_82F20A00, temp_s1->unk_0016, i), 0, temp_a3);
        }
    }

    Audio_PlaySoundEffectById(SFX_PANEL_OPEN);
}

s32 Trade_IsPickScreenActive(void) {
    unk_D_82F144D0* ptr = &D_82F144D0[D_82F20A04];

    return ptr->unk_0000;
}

void Trade_UpdatePickScreenOpen(unk_D_82F144D0* arg0) {
    arg0->unk_000C--;

    arg0->unk_0004 = 0x64 - ((arg0->unk_000C * -0xDC) / 10);
    arg0->unk_0006 = 0x70 - ((arg0->unk_000C * -0x30) / 10);
    arg0->unk_0008 = 0x1B8 - ((arg0->unk_000C * 0x1B8) / 10);
    arg0->unk_000A = 0x10C - ((arg0->unk_000C * 0x10C) / 10);

    if (arg0->unk_000C <= 0) {
        arg0->unk_0000 = 2;
        arg0->unk_000C = 0;
    }
}

void Trade_UpdatePickScreenInput(unk_D_82F144D0* arg0) {
    s32 temp_v1_3;
    s32 var_v0;
    Controller* controller;
    unk_D_82F144D0_0CA8* temp_a2;
    s32 i;
    unk_func_82F00838_sp30_00C* temp_a1;
    unk_func_82F00838_sp30_00C* temp_a3;
    unk_func_82F00838_sp30_00C* temp_a3_2;
    s16 temp_t1;
    u16 temp_v0 = Input_GetRepeatedDPad();

    controller = gPlayer1Controller;

    if (arg0->unk_000C > 0) {
        arg0->unk_000C--;
        if (arg0->unk_000C <= 0) {
            arg0->unk_000C = 0;
            arg0->unk_001C = arg0->unk_0018;
            arg0->unk_001E = arg0->unk_001A;
        } else {
            return;
        }
    }

    temp_a2 = &arg0->unk_0CA8[arg0->unk_0010];

    if (temp_v0 & 0x200) {
        arg0->unk_0018--;
        if (arg0->unk_0018 < 0) {
            arg0->unk_0018 = 0;
        }
    }

    if (temp_v0 & 0x100) {
        arg0->unk_0018++;
        if (arg0->unk_0018 >= 5) {
            arg0->unk_0018 = 4;
        }
    }

    if (temp_v0 & 0x800) {
        arg0->unk_001A--;
        if (arg0->unk_001A < 0) {
            arg0->unk_001A = 0;
        }
    }

    if (temp_v0 & 0x400) {
        arg0->unk_001A++;
        if (arg0->unk_001A >= 4) {
            arg0->unk_001A = 3;
        }
    }

    if ((arg0->unk_0018 != arg0->unk_001C) || (arg0->unk_001A != arg0->unk_001E)) {
        arg0->unk_000C = 4;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        return;
    }

    temp_v1_3 = (arg0->unk_001A * 5) + arg0->unk_0018;
    temp_a1 = &arg0->unk_0CA8[arg0->unk_0010].unk_00C[temp_v1_3];

    if (BTN_IS_PRESSED(controller, BTN_A) && (temp_v1_3 < arg0->unk_0CA8[arg0->unk_0010].unk_000)) {
        if ((temp_a1->unk_00 <= 0) || (temp_a1->unk_00 >= 0x98)) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }

        if (var_v0 == 0) {
            arg0->unk_0000 = 4;
            arg0->unk_000C = 0;
            arg0->unk_0002 = 0xA;
            Trade_OpenInfoBox(arg0, temp_a1, arg0->unk_0004 + (arg0->unk_0018 * 0x58) + 0x2C,
                          arg0->unk_0006 + (arg0->unk_001A * 0x3C) + 0x3A);
            Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        } else {
            goto block_25;
        }
    } else {
    block_25:
        if (BTN_IS_PRESSED(controller, BTN_B)) {
            arg0->unk_0000 = 5;
            arg0->unk_000C = 0xA;
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
        } else if (BTN_IS_PRESSED(controller, BTN_R) && (temp_a2->unk_008 != NULL)) {
            arg0->unk_0000 = 3;
            arg0->unk_000C = 0xA;
            arg0->unk_0012 = temp_a2->unk_008 - &arg0->unk_0CA8[0];
            arg0->unk_0014 = 1;

            for (i = 0; i < arg0->unk_0CA8[arg0->unk_0012].unk_000; i++) {
                temp_a3 = &arg0->unk_0CA8[arg0->unk_0012].unk_00C[i];

                temp_t1 = temp_a3->unk_00;
                if ((temp_t1 <= 0) || (temp_t1 >= 0x98)) {
                    var_v0 = 1;
                } else {
                    var_v0 = 0;
                }

                if (var_v0 != 0) {
                    PokeIcon_LoadModelTextureForMon(Trade_GetPickBufferSlot(D_82F20A00, arg0->unk_0016 ^ 1, i), 0x98, NULL);
                } else {
                    PokeIcon_LoadModelTextureForMon(Trade_GetPickBufferSlot(D_82F20A00, arg0->unk_0016 ^ 1, i), 0, temp_a3);
                }
            }
        } else if (BTN_IS_PRESSED(controller, BTN_L) && (temp_a2->unk_004 != NULL)) {
            arg0->unk_0000 = 3;
            arg0->unk_000C = 0xA;
            arg0->unk_0012 = temp_a2->unk_004 - &arg0->unk_0CA8[0];
            arg0->unk_0014 = -1;

            for (i = 0; i < arg0->unk_0CA8[arg0->unk_0012].unk_000; i++) {
                temp_a3_2 = &arg0->unk_0CA8[arg0->unk_0012].unk_00C[i];

                if ((temp_a3_2->unk_00 <= 0) || (temp_a3_2->unk_00 >= 0x98)) {
                    var_v0 = 1;
                } else {
                    var_v0 = 0;
                }

                if (var_v0 != 0) {
                    PokeIcon_LoadModelTextureForMon(Trade_GetPickBufferSlot(D_82F20A00, arg0->unk_0016 ^ 1, i), 0x98, NULL);
                } else {
                    PokeIcon_LoadModelTextureForMon(Trade_GetPickBufferSlot(D_82F20A00, arg0->unk_0016 ^ 1, i), 0, temp_a3_2);
                }
            }
        }
    }

    if (arg0->unk_0000 == 3) {
        Audio_PlaySoundEffectById(SFX_PAGE_CHANGE);
    }
}

void Trade_UpdatePickScreenPageSwipe(unk_D_82F144D0* arg0) {
    arg0->unk_000C--;
    if (arg0->unk_0014 >= 0) {
        arg0->unk_0004 = ((arg0->unk_000C * 0x1C3) / 10) - 0x15F;
    } else {
        arg0->unk_0004 = 0x227 - ((arg0->unk_000C * 0x1C3) / 10);
    }

    if (arg0->unk_000C <= 0) {
        arg0->unk_0000 = 2;
        arg0->unk_0010 = arg0->unk_0012;
        arg0->unk_000C = 0;
        arg0->unk_0014 = 0;
        arg0->unk_0016 ^= 1;
        arg0->unk_0004 = 0x64;
        TradeCable_SetSequenceTimer(2);
    }
}

void Trade_ConfirmPickSelection(unk_D_82F144D0* arg0) {
    s32 temp_v0 = Trade_GetInfoBoxState();

    if (temp_v0 != 0) {
        if (temp_v0 == 3) {
            if (arg0->unk_0002 != -1) {
                arg0->unk_0002 = -1;
            }
            TradeCable_SetSequenceTimer(-1);
        }
    } else if (arg0->unk_0020 != 0) {
        arg0->unk_0000 = 5;
        arg0->unk_000C = 0xA;
        _bcopy(Trade_GetPickBufferSlot(D_82F20A00, arg0->unk_0016, (arg0->unk_001A * 5) + arg0->unk_0018), arg0->unk_0028, 0xC80);
    } else {
        arg0->unk_0000 = 2;
        arg0->unk_000C = 0;
    }
}

void Trade_UpdatePickScreenClose(unk_D_82F144D0* arg0) {
    arg0->unk_000C--;
    arg0->unk_0004 = 0x140 - ((arg0->unk_000C * 0xDC) / 10);
    arg0->unk_0006 = 0xA0 - ((arg0->unk_000C * 0x30) / 10);
    arg0->unk_0008 = (arg0->unk_000C * 0x1B8) / 10;
    arg0->unk_000A = (arg0->unk_000C * 0x10C) / 10;
    if (arg0->unk_000C <= 0) {
        arg0->unk_0000 = 0;
        main_pool_pop_state('PICK');
    }
}

void Trade_DrawPickScreenFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureIa8(arg0 - 7, arg1 - 7, 8, 8, D_302F588, 8, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 1, arg1 - 7, 8, 8, D_302F5C8, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 1, arg1 - 7, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTextureIa8(arg0 - 7, (arg1 + arg3) - 1, 8, 8, D_302F608, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 - 7, arg1 + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 1, (arg1 + arg3) - 1, 8, 8, D_302F648, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 1, (arg1 + arg3) - 1, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTexturedRectClipped((arg0 + arg2) - 1, arg1 + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Trade_DrawPlayerBanner(s16 arg0, s16 arg1, s16 arg2) {
    static Color_RGB8 D_82F13B90 = { 0x82, 0x1E, 0x1E };
    static Color_RGB8 D_82F13B94 = { 0x96, 0x64, 0x1E };

    Color_RGB8* var_s0;
    char sp64[64];
    s16 tmp = 0x1A8;
    s16 tmp2 = 0x14;
    char* var_v0;

    if (arg0 == 0) {
        var_s0 = &D_82F13B90;
    } else {
        var_s0 = &D_82F13B94;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, var_s0->r, var_s0->g, var_s0->b, 0xFF);

    Gfx_DrawTextureIa8(arg1, arg2, 8, 8, D_30387B0, 8, 0);
    Gfx_DrawTextureIa8(arg1 + tmp + 8, arg2, 8, 8, D_30387F0, 8, 0);
    Gfx_DrawTexturedRectClipped(arg1 + 8, arg2, tmp, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTextureIa8(arg1, arg2 + tmp2, 8, 8, D_3038830, 8, 0);
    Gfx_DrawTexturedRectClipped(arg1, arg2 + 8, 8, 0xC, 0, 0, 0x400, 0, 0);
    Gfx_DrawTextureIa8(arg1 + tmp + 8, arg2 + tmp2, 8, 8, D_3038870, 8, 0);
    Gfx_DrawTexturedRectClipped(arg1 + 8, arg2 + tmp2, tmp, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTexturedRectClipped(arg1 + tmp + 8, arg2 + 8, 8, 0xC, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    Gfx_FillRectRgba(arg1 + 8, arg2 + 8, tmp, 0xC, var_s0->r, var_s0->g, var_s0->b, 0xFF);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);

    if (arg0 == 0) {
        var_v0 = Text_GetString(NULL, 0, gTradeStrings, 0xA);
    } else {
        Text_SetNumberToken(1, arg0);
        var_v0 = Text_GetString(sp64, ARRAY_COUNT(sp64), gTradeStrings, 0xB);
    }

    Font_Printf((arg1 - (Font_MeasureTextExtent(0, 0, var_v0) / 2)) + 0xDC, arg2 + 4, var_v0);
    Font_EndTexturedTextRendering();
}

void Trade_FillRect(s16 arg0, s16 arg1, s16 arg2, s16 arg3, Color_RGB8* arg4, s16 arg5) {
    if (arg5 != 0) {
        Gfx_FillRectRgba(arg0, arg1, arg2, arg3, arg4->r, arg4->g, arg4->b, 0xFF);
    } else {
        s32 color = RGBA5551(arg4->r, arg4->g, arg4->b, 1);

        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (color << 0x10) | color);
        gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);
    }
}

void Trade_DrawPickSlotBackdrop(s16 arg0, s16 arg1, s16 arg2) {
    static Color_RGB8 D_82F13B98 = { 0x3C, 0x3C, 0x82 };
    static Color_RGB8 D_82F13B9C = { 0x28, 0x28, 0x64 };
    static Color_RGB8 D_82F13BA0 = { 0x78, 0x78, 0x96 };

    Trade_FillRect(arg0 + 1, arg1 + 1, 0x56, 0x29, &D_82F13B98, arg2);
    Trade_FillRect(arg0 + 1, arg1 + 0x2A, 0x56, 0x11, &D_82F13B9C, arg2);
    Trade_FillRect(arg0, arg1, 0x58, 1, &D_82F13BA0, arg2);
    Trade_FillRect(arg0, arg1 + 0x3B, 0x58, 1, &D_82F13BA0, arg2);
    Trade_FillRect(arg0, arg1 + 1, 1, 0x3A, &D_82F13BA0, arg2);
    Trade_FillRect(arg0 + 0x57, arg1 + 1, 1, 0x3A, &D_82F13BA0, arg2);
}

void Trade_DrawDigitStrip(s16 arg0, s16 arg1, s16 arg2) {
    static u8* D_82F13BA4[] = {
        D_302F6E0, D_302F740, D_302F7A0, D_302F800, D_302F860, D_302F8C0, D_302F928, D_302F988, D_302F9E8, D_302FA48,
    };

    s32 i;
    s32 var_s0 = 0x05F5E100;
    s32 var_s4 = 0;

    for (i = 9; i > 0; i--) {
        s32 temp_lo = arg2 / var_s0;

        if ((temp_lo != 0) || (var_s4 != 0) || (i == 0)) {
            Gfx_DrawTextureIa8(arg0, arg1, 8, 0xC, D_82F13BA4[temp_lo], 8, 0);
            var_s4 = 1;
            arg0 += 9;
        }

        arg2 %= var_s0;
        var_s0 /= 10;
    }
}

void Trade_DrawSelectionCorners(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    static s16 D_82F13BCC = 0;

    s16 sins = SINS(D_82F13BCC) * 2;
    UNUSED s32 pad[2];

    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 240, 212, 104, 255);

    Gfx_DrawTextureIa8(arg0 + sins, arg1 + sins, 0x10, 0x10, D_3038C70, 0x10, 0);
    Gfx_DrawTextureIa8(arg0 + sins, ((arg1 + arg3) - sins) - 0x10, 0x10, 0x10, D_3038F70, 0x10, 0);
    Gfx_DrawTextureIa8(((arg0 + arg2) - sins) - 0x10, arg1 + sins, 0x10, 0x10, D_3038D70, 0x10, 0);
    Gfx_DrawTextureIa8(((arg0 + arg2) - sins) - 0x10, ((arg1 + arg3) - sins) - 0x10, 0x10, 0x10, D_3038E70, 0x10, 0);
    D_82F13BCC += 0x2000;
}

void Trade_DrawTitleBarStrip(s16 arg0, s16 arg1, s16 arg2) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);

    Gfx_DrawTextureI4(arg0, arg1, 0x10, 0x1C, D_30388B0, 0x10, 0);
    Gfx_DrawTextureI4((arg0 + arg2) - 0x10, arg1, 0x10, 0x1C, D_3038990, 0x10, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 0x10, arg1, arg2 - 0x20, 0x1C, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Trade_DrawRoundedFrameSmall(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 sp4C;
    s16 sp48;
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

    sp48 = arg2 - (var_s3 * 2);
    sp4C = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038730, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038770, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30386B0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30386F0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3,
                  0x2000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((sp48 > 0) && (sp4C > 0)) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp48, var_s2, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0, arg1 + var_s3, arg2, sp4C, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0 + var_s3, arg1 + var_s3 + sp4C, sp48, var_s2, arg4, arg5, arg6, arg7);
    } else if (sp48 > 0) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp48, arg3, arg4, arg5, arg6, arg7);
    } else if (sp4C > 0) {
        Gfx_FillRectRgba(arg0, arg1 + var_s2, arg2, sp4C, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Trade_DrawRoundedFrameLarge(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if ((arg2 < 0x20) && (arg2 & 1)) {
        arg2 += 1;
    }

    if ((arg3 < 0x20) && (arg3 & 1)) {
        arg3 += 1;
    }

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

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038B70, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038BF0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038A70, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038AF0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
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

void Trade_DrawBoxTabIcon(s16 arg0, s16 arg1, u8* arg2, s16 arg3) {
    gDPPipeSync(gDisplayListHead++);

    if (arg3 == 0) {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 150);
    } else {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    }

    Gfx_DrawTextureRgba16(arg0, arg1, 0x24, 0x14, arg2, 0x24, 0);
}

void Trade_DrawBoxTabBar(unk_D_82F144D0* arg0, s16 arg1, s16 arg2, s32 arg3) {
    static u8* D_82F13BD0[] = {
        D_3039A10, D_3039FB0, D_303A550, D_303AAF0, D_303B090, D_303B630, D_303BBD0,
        D_303C170, D_303C710, D_303CCB0, D_303D250, D_303D7F0, D_303DD90,
    };

    s32 i;

    Trade_DrawTitleBarStrip(arg1 - 0x10, arg2 - 4, 0x1F4);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 13; i++) {
        Trade_DrawBoxTabIcon(arg1 + i * 0x24, arg2, D_82F13BD0[i], arg0->unk_0CA8[i].unk_000);
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    if (arg0->unk_0000 != 3) {
        Gfx_DrawTextureRgba16((arg1 + (arg0->unk_0010 * 0x24)) - 4, arg2 - 4, 0x2C, 0xE, D_3039070, 0x2C, 0);
        Gfx_DrawTextureRgba16((arg1 + (arg0->unk_0010 * 0x24)) - 4, arg2 + 0xA, 0x2C, 0xE, D_3039540, 0x2C, 0);
    }

    gDPPipeSync(gDisplayListHead++);

    if (arg3 != 0) {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    } else {
        gDPSetEnvColor(gDisplayListHead++, 64, 64, 64, 255);
    }

    Gfx_DrawTextureRgba16(arg1 - 0x38, arg2 - 8, 0x30, 0x24, D_3027168, 0x30, 0);
    Gfx_DrawTextureRgba16(arg1 + 0x1DC, arg2 - 8, 0x30, 0x24, D_3027EE8, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Trade_DrawPortInfoPanel(s16 arg0, s16 arg1, s16 arg2) {
    static s16 D_82F13C04[] = { 0xDC, 8 };
    static s16 D_82F13C08[] = { 8, 0x2C };

    UNUSED s32 pad;
    unk_D_82F14450* sp40 = &D_82F14450[D_82F144D0[arg0].unk_000E];
    u8* sp3C;

    Trade_DrawRoundedFrameSmall(arg1, arg2, 0x104, 0x28, 0x1E, 0x1E, 0x82, 0xFF);

    switch (sp40->unk_01) {
        case 1:
            sp3C = D_3029C68;
            break;

        case 2:
            sp3C = D_302A468;
            break;

        case 3:
            sp3C = D_3028C68;
            break;

        case 7:
            sp3C = D_3029468;
            break;
    }

    if (sp3C != NULL) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);

        Gfx_DrawTextureRgba16(D_82F13C04[arg0] + arg1, arg2 + 4, 0x20, 0x20, sp3C, 0x20, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Font_Printf(D_82F13C08[arg0] + arg1, arg2 + 0xC, sp40->unk_08);
    Font_SetActive(4, 0);
    Font_Printf(D_82F13C08[arg0] + arg1 + 0x8E, arg2 + 0x14, "%05d", sp40->unk_06);
    Font_SetActive(4, 0);
    Font_Printf(D_82F13C08[arg0] + arg1 + 0x72, arg2 + 0x14, "ID");
    Font_EndTexturedTextRendering();
}

void func_82F04604(unk_D_82F144D0* arg0) {
    static s16 D_82F13C0C[] = { 0x34, 0x148 };

    s32 i;
    s32 spF8;
    s32 spF4;
    s16 var_v0;
    s16 temp_t0;
    s16 spEE;
    s16 var_s2;
    s16 var_a3;
    s16 spE8;
    s32 spE4;
    s32 pad2[3];
    s32 pad[14];
    s16 idx1;
    s16 idx2;
    s16 temp_t1;
    s16 temp_lo;
    s16 temp_s3;

    spE4 = 0;
    if (arg0->unk_0002 > 0) {
        arg0->unk_0002--;
    }

    if (arg0->unk_0000 == 3) {
        spF4 = 2;
        if (arg0->unk_0014 < 0) {
            spEE = -0x1C3;
        } else {
            spEE = 0x1C3;
        }
        Gfx_SetScissorRect(&gDisplayListHead, 0x60, 0x6C, 0x1C3, 0x117);
        spE4 = 1;
    } else {
        spF4 = 1;
        spEE = 0;
    }

    spF8 = 0;
    if (spF4 > 0) do {
        s32 sp68 = spEE * spF8;
        unk_D_82F144D0_0CA8* sp64;

        if (spF8 == 0) {
            var_s2 = arg0->unk_0010;
            spE8 = arg0->unk_0016;
        } else {
            var_s2 = arg0->unk_0012;
            spE8 = arg0->unk_0016 ^ 1;
        }

        sp64 = &arg0->unk_0CA8[var_s2];
        Trade_DrawPickScreenFrame((s16)(spEE * spF8) + arg0->unk_0004, arg0->unk_0006, arg0->unk_0008, arg0->unk_000A);

        if ((arg0->unk_0008 == 0x1B8) && (arg0->unk_000A == 0x10C)) {
            unk_func_82F00838_sp30_00C* ptr;

            Trade_DrawPlayerBanner(var_s2, (s16)sp68 + arg0->unk_0004, arg0->unk_0006);

            if (spF4 == 2) {
                gSPDisplayList(gDisplayListHead++, D_8006F498);
            } else {
                gSPDisplayList(gDisplayListHead++, D_8006F4C0);
            }

            for (i = 0; i < 20; i++) {
                idx1 = i / 5;
                idx2 = i % 5;

                Trade_DrawPickSlotBackdrop((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58), arg0->unk_0006 + (idx1 * 0x3C) + 0x1C,
                              spF4 - 1);
            }

            gSPDisplayList(gDisplayListHead++, D_8006F518);
            gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

            for (i = 0; i < sp64->unk_000; i++) {
                ptr = &sp64->unk_00C[i];
                idx1 = i / 5;
                idx2 = i % 5;

                Gfx_DrawTextureIa8((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58) + 4, arg0->unk_0006 + (idx1 * 0x3C) + 0x3B, 8,
                              0xA, D_302F690, 8, 0);

                if ((ptr->unk_00 <= 0) || (ptr->unk_00 >= 0x98)) {
                    var_v0 = 1;
                } else {
                    var_v0 = 0;
                }

                if (var_v0 == 0) {
                    Trade_DrawDigitStrip((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58) + 0xE,
                                  arg0->unk_0006 + (idx1 * 0x3C) + 0x39, ptr->unk_24);
                }
            }

            Font_BeginTranslucentTextRendering();
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_SetActive(2, 0);

            for (i = 0; i < sp64->unk_000; i++) {
                ptr = &sp64->unk_00C[i];
                idx1 = i / 5;
                idx2 = i % 5;

                if ((ptr->unk_00 <= 0) || (ptr->unk_00 >= 0x98)) {
                    var_v0 = 1;
                } else {
                    var_v0 = 0;
                }

                if (var_v0 == 0) {
                    continue;
                }

                Font_Printf((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58) + 0xE, arg0->unk_0006 + (idx1 * 0x3C) + 0x3A,
                              "??");
            }

            Font_EndTexturedTextRendering();
            Font_BeginTranslucentTextRendering();
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_SetActive(4, 0);

            for (i = 0; i < sp64->unk_000; i++) {
                ptr = &sp64->unk_00C[i];
                idx1 = i / 5;
                idx2 = i % 5;

                Font_Printf((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58) + 5, arg0->unk_0006 + (idx1 * 0x3C) + 0x46,
                              ptr->unk_30);
            }

            Font_EndTexturedTextRendering();

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            for (i = 0; i < sp64->unk_000; i++) {
                idx1 = i / 5;
                idx2 = i % 5;

                Gfx_DrawTextureRgba16((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58) + 0x2C, arg0->unk_0006 + (idx1 * 0x3C) + 0x1F,
                              0x28, 0x28, Trade_GetPickBufferSlot(D_82F20A00, spE8, i), 0x28, 0);
            }

            if (arg0->unk_0000 == 2) {
                temp_s3 = (arg0->unk_0004 + (arg0->unk_001C * 0x58));
                temp_lo = (arg0->unk_0006 + (arg0->unk_001E * 0x3C) + 0x1C);

                temp_t0 = arg0->unk_0004 + (arg0->unk_0018 * 0x58);
                temp_t1 = arg0->unk_0006 + (arg0->unk_001A * 0x3C) + 0x1C;

                Trade_DrawSelectionCorners(temp_t0 - (((temp_t0 - temp_s3) * arg0->unk_000C) / 4),
                              temp_t1 - (((temp_t1 - temp_lo) * arg0->unk_000C) / 4), 0x58, 0x3C);
            }

            gSPDisplayList(gDisplayListHead++, D_8006F630);
        }
        spF8++;
        sp68 += spEE;
    } while (spF8 < spF4);

    if ((arg0->unk_0008 == 0x1B8) && (arg0->unk_000A == 0x10C)) {
        if (spE4 != 0) {
            Gfx_SetScissorRect(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
        }

        if ((arg0->unk_0000 == 2) || (arg0->unk_0000 == 3)) {
            var_a3 = 1;
        } else {
            var_a3 = 0;
        }

        Trade_DrawBoxTabBar(arg0, 0x56, 0x50, var_a3);
        Trade_DrawPortInfoPanel(D_82F20A04, D_82F13C0C[D_82F20A04], 0x20);
    }
}

void Trade_ResetPickScreens(void) {
    unk_D_82F144D0* ptr;
    s32 i;

    D_82F20A04 = 0;

    ptr = &D_82F144D0[0];
    for (i = 0; i < 2; i++, ptr++) {
        ptr->unk_0018 = ptr->unk_001A = 0;
        ptr->unk_001C = ptr->unk_001E = 0;
        ptr->unk_0000 = 0;
        ptr->unk_0004 = 0;
        ptr->unk_0006 = 0;
        ptr->unk_0008 = 0;
        ptr->unk_000A = 0;
        ptr->unk_000C = 0;
        ptr->unk_000E = 0;
    }

    Trade_ResetInfoBox();
}

void Trade_UpdatePickScreens(void) {
    s16 temp_v0;
    s32 i;
    unk_D_82F144D0* var_s0;

    var_s0 = D_82F144D0;

    for (i = 0; i < 2; i++, var_s0++) {
        if (var_s0->unk_0000 == 0) {
            continue;
        }

        switch (var_s0->unk_0000) {
            case 1:
                Trade_UpdatePickScreenOpen(var_s0);
                break;

            case 2:
                Trade_UpdatePickScreenInput(var_s0);
                break;

            case 3:
                Trade_UpdatePickScreenPageSwipe(var_s0);
                break;

            case 4:
                Trade_UpdateInfoBox();
                Trade_ConfirmPickSelection(var_s0);
                break;

            case 5:
                Trade_UpdatePickScreenClose(var_s0);
                break;
        }
    }
}

void Trade_DrawPickScreens(void) {
    s32 i;
    s32 var_s3 = 0;
    unk_D_82F144D0* ptr = &D_82F144D0[0];

    for (i = 0; i < 2; i++, ptr++) {
        if (ptr->unk_0000 != 0) {
            var_s3 = 1;
            if (ptr->unk_0002 != 0) {
                func_82F04604(ptr);
            }
        }
    }

    if (var_s3 != 0) {
        Trade_DrawInfoBoxIfActive();
    }
}

u16* Trade_GetPickBuffer(s32 arg0) {
    return D_82F144D0[arg0].unk_0028;
}

void Trade_SwapPickBuffers(void) {
    UNUSED s32 pad[2];
    u16 sp18[0x640];

    _bcopy(D_82F144D0[0].unk_0028, sp18, sizeof(D_82F144D0[0].unk_0028));
    _bcopy(D_82F144D0[1].unk_0028, D_82F144D0[0].unk_0028, sizeof(D_82F144D0[0].unk_0028));
    _bcopy(sp18, D_82F144D0[1].unk_0028, sizeof(D_82F144D0[0].unk_0028));
}

void Trade_LoadPickBufferIcon(s16 arg0, BattleMon* arg1) {
    PokeIcon_LoadModelTextureForMon(D_82F144D0[arg0].unk_0028, 0, arg1);
}

s32 Trade_GetPickScreenSnapshot(s32 arg0, unk_func_82F00838_sp30* arg1) {
    s32 ret = 0;
    unk_D_82F144D0* ptr;

    if (arg1 != NULL) {
        ptr = &D_82F144D0[arg0];
        arg1->unk_00 = ptr->unk_0020;
        arg1->unk_02 = ptr->unk_000E;
        arg1->unk_04 = ptr->unk_0010;
        arg1->unk_06 = (ptr->unk_001A * 5) + ptr->unk_0018;
        arg1->unk_08 = ptr->unk_0CA8[ptr->unk_0010].unk_000;
        arg1->unk_0C = &ptr->unk_0CA8[ptr->unk_0010].unk_00C;
        ret = 1;
    }

    return ret;
}
