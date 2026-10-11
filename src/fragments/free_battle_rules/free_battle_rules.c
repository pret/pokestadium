#include "free_battle_rules.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/ui_graphics.h"
#include "src/pokemon_stats.h"
#include "src/game_state.h"
#include "src/session.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/DDC0.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_84002D18 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unk_D_84002D18; // size = 0x4

typedef struct unk_D_84002D28 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
} unk_D_84002D28; // size >= 0xA

typedef struct unk_D_84002BE8 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8* unk_08;
    /* 0x0C */ u8* unk_0C;
} unk_D_84002BE8; // size = 0x10

static char** D_84002D00;
static char** D_84002D04;
static BinArchive* D_84002D08;
static u8* D_84002D0C;
static s32 pad_D_84002D10;
static s16 D_84002D14;
static s16 D_84002D16;
static unk_D_84002D18 D_84002D18;
static s32 pad_D_84002D1C;
static s16 D_84002D20;
static unk_D_84002D28 D_84002D28;

static s16 D_84002BE0 = 2;
static s16 D_84002BE4 = 0;
static unk_D_84002BE8 D_84002BE8[11] = {
    {
        1,
        0,
        48,
        6,
        0x03008FD0,
        NULL,
    },
    {
        3,
        0,
        48,
        36,
        0x03008FD0,
        0x03009720,
    },
    {
        5,
        0,
        48,
        66,
        0x03008FD0,
        0x03009E70,
    },
    {
        9,
        0,
        48,
        96,
        0x03008FD0,
        0x0300A5C0,
    },
    {
        2,
        15,
        280,
        6,
        0x03009720,
        NULL,
    },
    {
        4,
        15,
        280,
        36,
        0x03009E70,
        NULL,
    },
    {
        8,
        15,
        280,
        66,
        0x0300A5C0,
        NULL,
    },
    {
        0,
        15,
        280,
        96,
        0x03008880,
        NULL,
    },
    {
        6,
        15,
        336,
        6,
        0x03009720,
        0x03009E70,
    },
    {
        10,
        15,
        336,
        36,
        0x03009720,
        0x0300A5C0,
    },
    {
        12,
        15,
        336,
        66,
        0x03009E70,
        0x0300A5C0,
    },
};
static s16 D_84002C98[] = { 0, 3, 4, 5, 6, 0 };

void FreeBattle_DrawHeaderImage(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(arg0, arg1, 0x30, 0x18, D_2006C00, 0x30, 0);
    Gfx_DrawTextureRgba16(arg0, arg1 + 0x18, 0x30, 0x18, D_2007500, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void FreeBattle_DrawBannerImage(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(arg0, arg1, 0x64, 0x14, D_200B3E0, 0x64, 0);
    Gfx_DrawTextureRgba16(arg0, arg1 + 0x14, 0x64, 0x14, D_200C380, 0x64, 0);
    Gfx_DrawTextureRgba16(arg0, arg1 + 0x28, 0x64, 0x10, D_200D320, 0x64, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void FreeBattle_DrawTintedBar(s16 arg0, s16 arg1, s16 arg2, Color_RGBA8* arg3, Color_RGBA8* arg4) {
    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, arg3->r, arg3->g, arg3->b, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, arg4->r, arg4->g, arg4->b, 255);

    Gfx_DrawTextureIa8(arg0, arg1, 0x10, 0x20, D_20003C0, 0x10, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 0x10, arg1, 0x10, 0x20, D_20005C0, 0x10, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 0x10, arg1, arg2 - 0x20, 0x20, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void FreeBattle_DrawTitleBar(void) {
    Color_RGBA8 sp2C;
    Color_RGBA8 sp28;

    Color_SetRGB(&sp2C, 0x64, 0x64, 0xC8);
    Color_SetRGB(&sp28, 0x28, 0x28, 0x8C);
    FreeBattle_DrawTintedBar(0x48, 0x28, 0x208, &sp2C, &sp28);
    FreeBattle_DrawHeaderImage(0x30, 0x20);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0, 0, 0, 0xFF);
    Font_Printf(0x6A, 0x2C, Text_GetString(NULL, 0, D_84002D00, 0));
    Gfx_SetEnvColor(0xFF, 0xFF, 0x77, 0xFF);
    Font_Printf(0x68, 0x2A, Text_GetString(NULL, 0, D_84002D00, 0));
    Font_EndTexturedTextRendering();
}

void FreeBattle_DrawSelectionCorners(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    static s16 D_84002CA4 = 0;

    s16 sp56 = SINS(D_84002CA4) * 2;
    UNUSED s32 pad[2];

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 240, 212, 104, 255);

    Gfx_DrawTextureIa8(arg0 + sp56, arg1 + sp56, 0x10, 0x10, D_2000C80, 0x10, 0);
    Gfx_DrawTextureIa8(arg0 + sp56, ((arg1 + arg3) - sp56) - 0x10, 0x10, 0x10, D_2000F80, 0x10, 0);
    Gfx_DrawTextureIa8(((arg0 + arg2) - sp56) - 0x10, arg1 + sp56, 0x10, 0x10, D_2000D80, 0x10, 0);
    Gfx_DrawTextureIa8(((arg0 + arg2) - sp56) - 0x10, ((arg1 + arg3) - sp56) - 0x10, 0x10, 0x10, D_2000E80, 0x10, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_84002CA4 += 0x2000;
}

void FreeBattle_DrawPanelFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureIa8(arg0 - 3, arg1 - 3, 8, 8, D_2000340, 8, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 5, arg1 - 3, 8, 8, D_2000380, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 4, arg1 - 3, arg2 - 8, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTextureIa8(arg0 - 3, (arg1 + arg3) - 5, 8, 8, D_20002C0, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 - 3, arg1 + 4, 8, arg3 - 8, 0, 0, 0x400, 0, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 5, (arg1 + arg3) - 5, 8, 8, D_2000300, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 4, (arg1 + arg3) - 5, arg2 - 8, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTexturedRectClipped((arg0 + arg2) - 5, arg1 + 4, 8, arg3 - 8, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    Gfx_FillRectRgb(arg0 + 4, arg1 + 4, arg2 - 8, arg3 - 8, 0x3C, 0x3C, 0xA0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void FreeBattle_DrawSlicedFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
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

s32 FreeBattle_IsRuleAvailable(s16 arg0) {
    unk_D_84002BE8* ptr = &D_84002BE8[arg0];
    s16 t = ptr->unk_00;
    s32 var_v1 = 0;

    if (arg0 < 4) {
        if (D_84002D16 >= 2) {
            var_v1 = arg0 == D_84002D18.unk_00;
        } else {
            var_v1 = ptr->unk_00 == (ptr->unk_00 & D_84002D14);
        }
    } else if (arg0 < 11) {
        if (D_84002D16 >= 3) {
            var_v1 = arg0 == (D_84002D18.unk_02 + 4);
        } else {
            s16 tmp = (~D_84002BE8[D_84002D18.unk_00].unk_00 & D_84002D14);

            var_v1 = ptr->unk_00 == (ptr->unk_00 & tmp);
        }
    }
    return var_v1;
}

void FreeBattle_DrawRuleMark(s16 arg0, s16 arg1, s16 arg2) {
    if (FreeBattle_IsRuleAvailable(arg2) != 0) {
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    } else {
        Gfx_SetEnvColor(0x64, 0x64, 0x64, 0x82);
    }
    Font_DrawCharAt(arg0, arg1, 0x26);
}

void FreeBattle_DrawRuleGrid(void) {
    s32 i;
    s16 temp_s2;
    s16 temp_s3;
    s32 var_t1;
    unk_D_84002BE8* ptr;
    s16 tmp1;
    s16 tmp2;

    FreeBattle_DrawSlicedFrame(0x64, 0x72, 0x1B0, 0x80, 0, 0, 0, 0xFF);
    FreeBattle_DrawBannerImage(0x10A, 0x96);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 11; i++) {
        temp_s2 = D_84002BE8[i].unk_04 + 0x64;
        temp_s3 = D_84002BE8[i].unk_06 + 0x72;

        if (FreeBattle_IsRuleAvailable(i) != 0) {
            var_t1 = 0xFF;
        } else {
            var_t1 = 0x82;
        }

        gDPSetEnvColor(gDisplayListHead++, var_t1, var_t1, var_t1, var_t1);

        Gfx_DrawTextureRgba16(temp_s2, temp_s3, 0x24, 0x1A, D_84002BE8[i].unk_08, 0x24, 0);
        if (D_84002BE8[i].unk_0C != NULL) {
            Gfx_DrawTextureRgba16(temp_s2 + 0x30, temp_s3, 0x24, 0x1A, D_84002BE8[i].unk_0C, 0x24, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);

    for (i = 0; i < 11; i++) {
        if (D_84002BE8[i].unk_0C != NULL) {
            FreeBattle_DrawRuleMark(D_84002BE8[i].unk_04 + 0x87, D_84002BE8[i].unk_06 + 0x73, i);
        }
    }

    Font_SetActive(0x10, 0);

    if ((D_84002D16 == 1) || (D_84002D16 == 2)) {
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    } else {
        Gfx_SetEnvColor(0x78, 0x78, 0xC8, 0xFF);
    }

    Font_Printf(0x64, 0x5A, Text_GetString(NULL, 0, D_84002D00, 1));
    Font_EndTexturedTextRendering();

    if (D_84002D16 == 1) {
        ptr = &D_84002BE8[D_84002D18.unk_00];
        tmp1 = ptr->unk_04 + 0x64;
        tmp2 = ptr->unk_06 + 0x72;
        FreeBattle_DrawSelectionCorners(tmp1 - 4, tmp2 - 2, ((ptr->unk_0C == NULL) ? 0x24 : 0x54) + 8, 0x1E);
    } else if (D_84002D16 == 2) {
        ptr = &D_84002BE8[D_84002D18.unk_02];
        tmp1 = ptr[4].unk_04 + 0x64;
        tmp2 = ptr[4].unk_06 + 0x72;
        FreeBattle_DrawSelectionCorners(tmp1 - 4, tmp2 - 2, ((ptr[4].unk_0C == NULL) ? 0x24 : 0x54) + 8, 0x1E);
    }
}

void FreeBattle_UpdateRuleRowSelect(void) {
    s32 sp24 = D_84002D18.unk_00;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        D_84002D18.unk_02 = 0;
        while (FreeBattle_IsRuleAvailable(D_84002D18.unk_02 + 4) == 0) {
            D_84002D18.unk_02++;
        }
        D_84002D16 = 2;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        D_84002D16 = 8;
    } else {
        do {
            if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
                D_84002D18.unk_00 = (D_84002D18.unk_00 + 3) % 4;
            } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
                D_84002D18.unk_00 = (D_84002D18.unk_00 + 1) % 4;
            }
        } while (FreeBattle_IsRuleAvailable(D_84002D18.unk_00) == 0);

        if (sp24 != D_84002D18.unk_00) {
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        }
    }
}

void FreeBattle_UpdateRuleOptionSelect(void) {
    s32 sp34 = D_84002D18.unk_02;
    s32 i;
    s32 var_a0;
    s32 var_s1;
    s32 var_s4;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        if (D_84002D18.unk_02 == 3) {
            D_84002D16 = 5;
        } else {
            D_84002D20 = 0;
            D_84002D16 = 3;
        }
        return;
    }

    var_s4 = 0;
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        D_84002D18.unk_02 = -1;
        D_84002D16 = 1;
        return;
    }

    var_a0 = D_84002D18.unk_02 / 4;
    var_s1 = D_84002D18.unk_02 % 4;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT) && (var_a0 == 1)) {
        var_a0 = 0;
        var_s4 = 1;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT) && (var_a0 == 0)) {
        var_a0 = 1;
        var_s4 = 1;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        var_s1 = (var_s1 + 3) % 4;
        var_s4 = -1;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        var_s1 = (var_s1 + 1) % 4;
        var_s4 = 1;
    }

    if (var_s4 != 0) {
        for (i = 0; i < 4; i++) {
            if (FreeBattle_IsRuleAvailable(var_a0 * 4 + var_s1 + 4) != 0) {
                break;
            }
            var_s1 = (var_s1 + var_s4 + 4) % 4;
        }

        if (i != 4) {
            D_84002D18.unk_02 = var_a0 * 4 + var_s1;
        }
    }

    if (sp34 != D_84002D18.unk_02) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }
}

void FreeBattle_ClearRuleSelection(void) {
    D_84002D18.unk_00 = -1;
    D_84002D18.unk_02 = -1;
}

s32 FreeBattle_SelectionHasSubrule(void) {
    s32 var_v1 = 0;

    if ((D_84002D18.unk_00 != -1) && (D_84002BE8[D_84002D18.unk_00].unk_0C != 0)) {
        var_v1 = 1;
    }

    if ((D_84002D18.unk_02 != -1) && (D_84002BE8[D_84002D18.unk_02 + 4].unk_0C != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

void FreeBattle_DrawLevelOptionLine(s16 arg0, s16 arg1, s16 arg2, char* arg3) {
    if ((arg2 != 0) && (FreeBattle_SelectionHasSubrule() != 0)) {
        Gfx_SetEnvColor(0x3C, 0x3C, 0x3C, 0xFF);
    } else if (arg2 == D_84002D20) {
        Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
    } else {
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    }
    Font_Printf(arg0, arg1 + (arg2 * 0x18), arg3);
}

void func_84001AD8(void) {
}

void FreeBattle_DrawLevelSelectPanel(void) {
    UNUSED s32 pad;
    char sp2C[128];

    FreeBattle_DrawSlicedFrame(0x64, 0x10C, 0x1B0, 0x84, 0, 0, 0, 0xFF);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
    FreeBattle_DrawLevelOptionLine(0x94, 0x114, 0, Text_GetString(NULL, 0, D_84002D00, 2));
    FreeBattle_DrawLevelOptionLine(0x94, 0x114, 1, Text_GetString(NULL, 0, D_84002D00, 3));
    FreeBattle_DrawLevelOptionLine(0x94, 0x114, 2, Text_GetString(NULL, 0, D_84002D00, 6));
    FreeBattle_DrawLevelOptionLine(0x94, 0x114, 3, Text_GetString(NULL, 0, D_84002D00, 7));
    FreeBattle_DrawLevelOptionLine(0x94, 0x114, 4, Text_GetString(NULL, 0, D_84002D00, 8));
    Font_SetActive(4, 0);

    sprintf(sp2C, "%s1~100", Text_GetString(NULL, 0, D_84002D04, 0x15));
    FreeBattle_DrawLevelOptionLine(0x1AE, 0x118, 0, sp2C);
    sprintf(sp2C, "%s50~55", Text_GetString(NULL, 0, D_84002D04, 0x15));
    FreeBattle_DrawLevelOptionLine(0x1AE, 0x118, 1, sp2C);
    sprintf(sp2C, "%s25~30", Text_GetString(NULL, 0, D_84002D04, 0x15));
    FreeBattle_DrawLevelOptionLine(0x1AE, 0x118, 2, sp2C);
    sprintf(sp2C, "%s15~20", Text_GetString(NULL, 0, D_84002D04, 0x15));
    FreeBattle_DrawLevelOptionLine(0x1AE, 0x118, 3, sp2C);
    sprintf(sp2C, "%s1~100", Text_GetString(NULL, 0, D_84002D04, 0x15));
    FreeBattle_DrawLevelOptionLine(0x1AE, 0x118, 4, sp2C);

    Font_SetActive(0x10, 0);

    if (D_84002D16 == 3) {
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    } else {
        Gfx_SetEnvColor(0x78, 0x78, 0xC8, 0xFF);
    }

    Font_Printf(0x64, 0xF4, Text_GetString(NULL, 0, D_84002D00, 9));
    Font_EndTexturedTextRendering();

    if (D_84002D16 == 3) {
        Ui_DrawAnimatedTextureMarker(0x6C, (D_84002D20 * 0x18) + 0x114);
    }
}

void FreeBattle_UpdateLevelSelect(void) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        Audio_PlaySoundEffectById(0x26);
        D_84002D16 = 7;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        D_84002D20 = -1;
        D_84002D16 = 2;
    } else if (FreeBattle_SelectionHasSubrule() == 0) {
        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            D_84002D20 = (D_84002D20 + 4) % 5;
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            D_84002D20 = (D_84002D20 + 1) % 5;
        }
    }
}

void FreeBattle_ClearLevelSelection(void) {
    D_84002D20 = -1;
}

void FreeBattle_DrawConfirmLine(s16 arg0, char* arg1) {
    if (arg0 == D_84002D28.unk_08) {
        Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
    } else {
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    }
    Font_Printf(D_84002D28.unk_00 + 0x34, D_84002D28.unk_02 + (arg0 * 0x1C) + 0x2B, arg1);
}

void FreeBattle_DrawConfirmPanel(void) {
    if (D_84002D28.unk_04 > 0) {
        s16 tmp = D_84002D28.unk_04 * 0x11;

        Ui_DrawBorderedPanel(D_84002D28.unk_00, D_84002D28.unk_02 + (s16)((0x88 - tmp) / 2), 0x98, tmp, 0x2121);
        if (D_84002D28.unk_04 == 8) {
            gSPDisplayList(gDisplayListHead++, D_8006F518);

            Gfx_DrawTextureRgba16(D_84002D28.unk_00 + 0xC, D_84002D28.unk_02 + 0xA, 0x24, 0x1A, D_3008880, 0x24, 0);

            gSPDisplayList(gDisplayListHead++, D_8006F630);

            Ui_DrawAnimatedTextureMarker(D_84002D28.unk_00 + 0xC, D_84002D28.unk_02 + (D_84002D28.unk_08 * 0x1C) + 0x2B);
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Font_Printf(D_84002D28.unk_00 + 0x30, D_84002D28.unk_02 + 0xB, Text_GetString(NULL, 0, D_84002D00, 0xA));
            FreeBattle_DrawConfirmLine(0, Text_GetString(NULL, 0, D_84002D00, 0xB));
            FreeBattle_DrawConfirmLine(1, Text_GetString(NULL, 0, D_84002D00, 0xC));
            FreeBattle_DrawConfirmLine(2, Text_GetString(NULL, 0, D_84002D00, 0xD));
            Font_EndTexturedTextRendering();
        }
    }
}

void FreeBattle_InitConfirmPanel(void) {
    D_84002D28.unk_00 = 0x190;
    D_84002D28.unk_02 = 0x64;
    D_84002D28.unk_04 = 0;
    D_84002D28.unk_08 = 1;
}

void FreeBattle_OpenConfirmPanel(void) {
    D_84002BE0 = 2;
    D_84002D28.unk_04++;
    if (D_84002D28.unk_04 == 8) {
        D_84002D16 = 4;
    }
}

void FreeBattle_CloseConfirmPanel(void) {
    D_84002BE0 = 2;
    D_84002D28.unk_04--;
    if (D_84002D28.unk_04 == 0) {
        D_84002D16 = D_84002D28.unk_06;
    }
}

void FreeBattle_UpdateConfirmDialog(void) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        D_84002BE4 = D_84002D28.unk_08;
        D_84002D28.unk_06 = 3;
        D_84002D20 = 0;
        D_84002D16 = 6;
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        D_84002D28.unk_06 = 2;
        D_84002D16 = 6;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        D_84002D28.unk_08 = (D_84002D28.unk_08 + 2) % 3;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        D_84002D28.unk_08 = (D_84002D28.unk_08 + 1) % 3;
    }
}

void FreeBattle_PollInputs(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void FreeBattle_DrawFrame(void) {
    BgStage_DrawFrame();
    if (D_84002BE0 > 0) {
        FreeBattle_DrawPanelFrame(0x4C, 0x54, 0x1E8, 0x150);
        D_84002BE0 -= 1;
    }
    FreeBattle_DrawRuleGrid();
    FreeBattle_DrawLevelSelectPanel();
    FreeBattle_DrawConfirmPanel();
    BgStage_AdvanceFrame();
}

void FreeBattle_FadeIn(void) {
    s32 i;

    if (StageContext_GetFadeMode() == 1) {
        StageFade_StartFromOpaque(8);

        for (i = 0; i < 10; i++) {
            Controller_PollInputs();
            BgStage_DrawFrame();
            Gfx_DrawTiledRgba16Image(D_84002D0C);
            BgStage_AdvanceFrame();
        }
    }
}

void FreeBattle_FadeOut(void) {
    Audio_StopMusic(0x10);
    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromTransparent(8);

    while (StageContext_GetFadeMode() != 1) {
        Controller_PollInputs();
        BgStage_DrawFrame();
        Gfx_DrawTiledRgba16Image(D_84002D0C);
        BgStage_AdvanceFrame();
    }

    StageLoader_RunFrames(2);
}

void FreeBattle_SlideInPanel(void) {
    s32 i;
    s16 tmp;

    Audio_PlaySoundEffectById(SFX_PANEL_OPEN);

    for (i = 0x10; i < 0x170; i += 0x20) {
        FreeBattle_PollInputs();
        BgStage_DrawFrame();
        Gfx_DrawTiledRgba16Image(D_84002D0C);
        FreeBattle_DrawTitleBar();
        tmp = i;
        tmp = (0x150 - tmp) / 2;
        FreeBattle_DrawPanelFrame(0x4C, tmp + 0x54, 0x1E8, i);
        BgStage_AdvanceFrame();
    }
}

void FreeBattle_SlideOutPanel(void) {
    s32 i;

    for (i = 9; i >= 0; i--) {
        FreeBattle_PollInputs();
        BgStage_DrawFrame();
        Gfx_DrawTiledRgba16Image(D_84002D0C);
        FreeBattle_DrawTitleBar();
        FreeBattle_DrawPanelFrame(0x4C, (s16)((0x16C - (s16)(0xE + i * 0x23)) / 2) + 0x54, 0x1E8, 0xE + i * 0x23);
        BgStage_AdvanceFrame();
    }

    for (i = 0; i < 2; i++) {
        BgStage_DrawFrame();
        Gfx_DrawTiledRgba16Image(D_84002D0C);
        BgStage_AdvanceFrame();
    }
}

void FreeBattle_ApplyRuleSelection(void) {
    char sp44[12];
    TeamRoster* temp_v0;
    s32 i;

    Session_SetMode(0, D_84002C98[D_84002D20], 0);

    for (i = 0; i < 4; i++) {
        if (D_84002BE8[D_84002D18.unk_00].unk_00 & (1 << i)) {
            sprintf(sp44, "%dP", i + 1);
            Team_AddTrainer(0, Trainer_Create(i, 0, sp44, Text_GetPlayerLabel(1)));
        }
    }

    if (D_84002D18.unk_02 == 3) {
        D_800AE540.unk_11EC = D_84002BE4;
        temp_v0 = Trainer_Create(-1, 0, "COM", Text_GetPlayerLabel(3));
        Team_AddTrainer(1, temp_v0);
        if (D_84002D18.unk_00 == 3) {
            temp_v0->unk_001 = 2;
        } else {
            temp_v0->unk_001 = 3;
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (D_84002BE8[D_84002D18.unk_02 + 4].unk_00 & (1 << i)) {
                sprintf(sp44, "%dP", i + 1);
                Team_AddTrainer(1, Trainer_Create(i, 0, sp44, Text_GetPlayerLabel(1)));
            }
        }
    }

    if (D_800AE540.unk_1194[0].unk_01 == 2) {
        D_800AE540.unk_1194[0].unk_08[0]->unk_214->unk_003 = 0x35;
        D_800AE540.unk_1194[0].unk_08[1]->unk_214->unk_003 = 0x35;
    }

    if (D_800AE540.unk_1194[1].unk_01 == 2) {
        D_800AE540.unk_1194[1].unk_08[0]->unk_214->unk_003 = 0x35;
        D_800AE540.unk_1194[1].unk_08[1]->unk_214->unk_003 = 0x35;
    }
}

s32 FreeBattle_RuleSelectLoop(void) {
    D_84002D16 = 0;
    Audio_PlayMusicIfChanged(0x2D);
    FreeBattle_ClearRuleSelection();
    FreeBattle_ClearLevelSelection();
    FreeBattle_InitConfirmPanel();
    FreeBattle_FadeIn();
    FreeBattle_SlideInPanel();
    D_84002D16 = 1;
    D_84002D18.unk_00 = 0;

    while ((D_84002D16 != 7) && (D_84002D16 != 8)) {
        FreeBattle_PollInputs();
        switch (D_84002D16) {
            case 1:
                FreeBattle_UpdateRuleRowSelect();
                break;
            case 2:
                FreeBattle_UpdateRuleOptionSelect();
                break;
            case 3:
                FreeBattle_UpdateLevelSelect();
                break;
            case 4:
                FreeBattle_UpdateConfirmDialog();
                break;
            case 5:
                FreeBattle_OpenConfirmPanel();
                break;
            case 6:
                FreeBattle_CloseConfirmPanel();
                break;
        }
        FreeBattle_DrawFrame();
    }

    if (D_84002D16 == 8) {
        FreeBattle_SlideOutPanel();
        FreeBattle_FadeOut();
        return 0;
    }

    FreeBattle_ApplyRuleSelection();
    FreeBattle_SlideOutPanel();
    return 1;
}

s32 FreeBattle_RuleSelectMain(s32 arg0, s32 arg1) {
    s32 sp1C;

    main_pool_push_state('RULE');

    Font_Init(0x1C, 0);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    ASSET_LOAD(D_3000000, order_select_ui, 0);
    Text_InitStringTables();
    D_84002D00 = Text_GetStringTable(0xF);
    D_84002D04 = Text_GetStringTable(6);
    D_84002D08 = ASSET_LOAD2(backgrounds, 1, 1);
    D_84002D0C = BinArchive_GetFile(D_84002D08, 6);
    D_84002D14 = Cont_GetControllerBits();
    StageLoader_UpdateSegments();
    sp1C = FreeBattle_RuleSelectLoop();
    StageLoader_WaitForRetrace();

    main_pool_pop_state('RULE');
    return sp1C;
}
