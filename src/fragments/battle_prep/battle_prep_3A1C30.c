#include "battle_prep.h"
#include "src/geo_render.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/save_data.h"
#include "src/audio_sfx.h"
#include "src/matrix.h"
#include "src/math_util.h"
#include "src/memmap.h"
#include "src/memory.h"

static BattlePrepRuleWindowLayout gBattlePrepRuleWindowLayouts[] = {
    {
        78,
        84,
        164,
        72,
        2,
        8481,
        0,
        -1,
        44,
    },
    {
        78,
        91,
        164,
        58,
        2,
        8481,
        0,
        -1,
        44,
    },
    {
        77,
        122,
        166,
        92,
        5,
        8481,
        0,
        -1,
        9362,
    },
    {
        77,
        142,
        166,
        52,
        3,
        8481,
        0,
        -1,
        146,
    },
    {
        77,
        144,
        166,
        52,
        3,
        8481,
        0,
        -1,
        146,
    },
    {
        77,
        149,
        166,
        38,
        2,
        8481,
        0,
        -1,
        18,
    },
    {
        60,
        40,
        200,
        64,
        1,
        8481,
        0,
        -1,
        2,
    },
    {
        60,
        40,
        200,
        64,
        1,
        8481,
        0,
        -1,
        2,
    },
    {
        68,
        32,
        184,
        104,
        1,
        8481,
        1,
        -1,
        2,
    },
    {
        60,
        38,
        200,
        164,
        2,
        26889,
        0,
        -1,
        13,
    },
};

void BattlePrep_DrawCursorArrow(BattlePrepRuleWindow* arg0, s16 arg1, s16 arg2) {
    static s16 D_84B17604 = 0;

    if (D_84B17604 < 6) {
        arg1 = (arg1 + (D_84B17604 / 2));
    } else {
        arg1 = ((arg1 - (D_84B17604 / 2)) + 6);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    gDPLoadTextureBlock(gDisplayListHead++, D_10031D0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 22, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg1, arg2 + (arg0->unk_04 * 0xE) + 1, 0x10, 0xB, 0, 0, 0x800, 0x800, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_84B17604 = (D_84B17604 + 1) % 12;
}

void BattlePrep_DrawRuleOption(BattlePrepRuleWindow* arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s8* arg5) {
    if (arg4 == 0) {
        Gfx_SetEnvColor(0x64, 0x64, 0x64, 0xFF);
    } else if (arg3 == arg0->unk_04) {
        Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
    } else {
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    }
    Font_Printf(arg1, arg2 + (arg3 * 0xE), arg5);
}

void BattlePrep_DrawResultPrompt(BattlePrepRuleWindow* arg0, BattlePrepRuleWindowLayout* arg1) {
    BattlePrep_DrawCursorArrow(arg0, arg1->unk_00 + 0xC, arg1->unk_02 + 0x18);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    Font_Printf(arg1->unk_00 + 0x10, arg1->unk_02 + 6, BattlePrep_GetString(0x29));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x22, arg1->unk_02 + 0x18, 0, 1, BattlePrep_GetString(0x2A));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x22, arg1->unk_02 + 0x18, 1, 1, BattlePrep_GetString(0x2B));

    if (arg1->unk_06 == 0x48) {
        Font_SetActive(1, 0);
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        Font_Printf(arg1->unk_00 + 0x4A, arg1->unk_02 + 0x36, "%s%d", BattlePrep_GetString(0x2C), D_800AE540.unk_11F3);
    }

    Font_EndTexturedTextRendering();
}

void BattlePrep_DrawContinuePrompt(BattlePrepRuleWindow* arg0, BattlePrepRuleWindowLayout* arg1) {
    s32 sp2C;
    s32 sp28;

    sp2C = D_800AE540.unk_11F3 > 0;
    sp28 = !!(D_800AE540.unk_11F5 & 2);
    sp28 = !sp28;

    BattlePrep_DrawCursorArrow(arg0, arg1->unk_00 + 5, arg1->unk_02 + 6);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 0, sp2C, BattlePrep_GetString(0x2D));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 1, sp2C, BattlePrep_GetString(0x2E));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 2, sp28, BattlePrep_GetString(0x2F));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 3, 1, BattlePrep_GetString(0x30));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 4, 1, BattlePrep_GetString(0x31));
    Font_SetActive(1, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    Font_Printf(arg1->unk_00 + 0x4A, arg1->unk_02 + 0x4C, "%s%d", BattlePrep_GetString(0x2C), D_800AE540.unk_11F3);
    Font_EndTexturedTextRendering();
}

void BattlePrep_DrawGiveUpPrompt(BattlePrepRuleWindow* arg0, BattlePrepRuleWindowLayout* arg1) {
    s32 sp2C = !!(D_800AE540.unk_11F5 & 2);

    sp2C = !sp2C;
    BattlePrep_DrawCursorArrow(arg0, arg1->unk_00 + 5, arg1->unk_02 + 6);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 0, sp2C, BattlePrep_GetString(0x2F));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 1, 1, BattlePrep_GetString(0x32));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 2, 1, BattlePrep_GetString(0x31));
    Font_EndTexturedTextRendering();
}

void BattlePrep_DrawRetireStreakPrompt(BattlePrepRuleWindow* arg0, BattlePrepRuleWindowLayout* arg1) {
    s32 sp2C = D_800AE540.unk_1194[0].unk_1E < 0x63 && D_800AE540.unk_1194[1].unk_1E < 0x63;

    BattlePrep_DrawCursorArrow(arg0, arg1->unk_00 + 5, arg1->unk_02 + 6);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 0, sp2C, BattlePrep_GetString(0x33));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 1, 1, BattlePrep_GetString(0x34));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 2, 1, BattlePrep_GetString(0x31));
    Font_EndTexturedTextRendering();
}

void BattlePrep_DrawQuitPrompt(BattlePrepRuleWindow* arg0, BattlePrepRuleWindowLayout* arg1) {
    BattlePrep_DrawCursorArrow(arg0, arg1->unk_00 + 5, arg1->unk_02 + 6);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 0, 1, BattlePrep_GetString(0x35));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 1, 1, BattlePrep_GetString(0x31));
    Font_EndTexturedTextRendering();
}

void BattlePrep_DrawCupRuleSummary(BattlePrepRuleWindow* arg0, BattlePrepRuleWindowLayout* arg1) {
    char* temp_v0;

    Font_BeginTranslucentTextRendering();
    Font_EnableTwoCycleTexturing();
    Font_SetActive(4, 0);
    Gfx_SetPrimColor(0x32, 0xFF, 0x64, 0xFF);

    if ((D_800AE540.unk_0000 == 3) || (D_800AE540.unk_0000 == 6)) {
        temp_v0 = BattlePrep_GetString(D_800AE540.unk_0000 - 1);
        Font_Printf((arg1->unk_00 - (Font_MeasureTextExtent(4, 0, temp_v0) / 2)) + 0x64, arg1->unk_02 + 6, temp_v0);
        temp_v0 = BattlePrep_GetString(D_800AE540.unk_0002 + 7);
        Font_Printf((arg1->unk_00 - (Font_MeasureTextExtent(4, 0, temp_v0) / 2)) + 0x64, arg1->unk_02 + 0x18, temp_v0);
        temp_v0 = BattlePrep_GetString(D_800AE540.unk_0003 + 0xA);
        Font_Printf((arg1->unk_00 - (Font_MeasureTextExtent(4, 0, temp_v0) / 2)) + 0x64, arg1->unk_02 + 0x2A, temp_v0);
    } else {
        temp_v0 = BattlePrep_GetString(D_800AE540.unk_0000 - 1);
        Font_Printf((arg1->unk_00 - (Font_MeasureTextExtent(4, 0, temp_v0) / 2)) + 0x64, arg1->unk_02 + 0xA, temp_v0);
        temp_v0 = BattlePrep_GetString(D_800AE540.unk_0003 + 0xA);
        Font_Printf((arg1->unk_00 - (Font_MeasureTextExtent(4, 0, temp_v0) / 2)) + 0x64, arg1->unk_02 + 0x26, temp_v0);
    }

    Font_DisableTwoCycleTexturing();
    Font_EndTexturedTextRendering();
}

void BattlePrep_DrawCastleRuleSummary(BattlePrepRuleWindow* arg0, BattlePrepRuleWindowLayout* arg1) {
    s32 sp12C;
    char sp2C[0x100];

    Font_BeginTranslucentTextRendering();
    Font_EnableTwoCycleTexturing();
    Font_SetActive(4, 0);
    Gfx_SetPrimColor(0x32, 0xFF, 0x64, 0xFF);

    sprintf(sp2C, "%s %s", BattlePrep_GetString(D_800AE540.unk_0002 + 0x13), BattlePrep_GetString(0x36));
    sp12C = Font_MeasureTextExtent(4, 0, sp2C);
    Font_Printf((arg1->unk_00 - (sp12C / 2)) + 0x64, arg1->unk_02 + 0xA, sp2C);

    if (D_800AE540.unk_0002 < 9) {
        if (D_800AE540.unk_0002 == 8) {
            sprintf(sp2C, "%s %d", BattlePrep_GetString(0x1B), D_800AE540.unk_0003);
            sp12C = Font_MeasureTextExtent(4, 0, sp2C);
            Font_Printf((arg1->unk_00 - (sp12C / 2)) + 0x64, arg1->unk_02 + 0x26, sp2C);
        } else if (D_800AE540.unk_0003 < 4) {
            sprintf(&sp2C, "%s %d", BattlePrep_GetString(0x37), D_800AE540.unk_0003);
            sp12C = Font_MeasureTextExtent(4, 0, sp2C);
            Font_Printf((arg1->unk_00 - (sp12C / 2)) + 0x64, arg1->unk_02 + 0x26, sp2C);
        } else {
            sp12C = Font_MeasureTextExtent(4, 0, BattlePrep_GetString(D_800AE540.unk_0002 + 0x1D));
            Font_Printf((arg1->unk_00 - (sp12C / 2)) + 0x64, arg1->unk_02 + 0x26,
                          BattlePrep_GetString(D_800AE540.unk_0002 + 0x1D));
        }
    }

    Font_DisableTwoCycleTexturing();
    Font_EndTexturedTextRendering();
}

void BattlePrep_DrawRankBadge(s16 arg0, s16 arg1, BattleSessionTeams* arg2) {
    static u8* D_84B17608[] = { D_3025950, D_30260A0, D_30267F0, D_3026F40 };

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (arg2->unk_01 == 1) {
        if (arg2->unk_08[0]->unk_000 & 2) {
            Gfx_DrawTextureRgba16(arg0 + 0x1A, arg1 + 3, 0x24, 0x1A, D_3025200, 0x24, 0);
            if (0) {}
        } else {
            Gfx_DrawTextureRgba16(arg0 + 0x1A, arg1 + 3, 0x24, 0x1A, D_84B17608[arg2->unk_08[0]->unk_001], 0x24, 0);
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);
        return;
    }

    if (arg2->unk_08[0]->unk_001 < arg2->unk_08[1]->unk_001) {
        Gfx_DrawTextureRgba16(arg0 + 6, arg1 + 3, 0x24, 0x1A, D_84B17608[arg2->unk_08[0]->unk_001], 0x24, 0);
        Gfx_DrawTextureRgba16(arg0 + 0x30, arg1 + 3, 0x24, 0x1A, D_84B17608[arg2->unk_08[1]->unk_001], 0x24, 0);
    } else {
        Gfx_DrawTextureRgba16(arg0 + 6, arg1 + 3, 0x24, 0x1A, D_84B17608[arg2->unk_08[1]->unk_001], 0x24, 0);
        Gfx_DrawTextureRgba16(arg0 + 0x30, arg1 + 3, 0x24, 0x1A, D_84B17608[arg2->unk_08[0]->unk_001], 0x24, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);
    Font_DrawCharAt(arg0 + 0x24, arg1 + 8, 0x26);
    Font_EndTexturedTextRendering();
}

void BattlePrep_SetStreakColor(BattleSessionTeams* arg0) {
    static s16 D_84B17618 = 0;

    if (arg0->unk_1C == 1) {
        Gfx_SetEnvColor(0xFF, (SINS((s32)(SINS(D_84B17618) * 16384.0f)) * 100.0f) + 155.0f, 0x37, 0xFF);
        D_84B17618 += 0x400;
    } else {
        Gfx_SetEnvColor(0xFF, 0x37, 0x37, 0xFF);
    }
}

void BattlePrep_DrawTeamPreview(BattlePrepRuleWindow* arg0, BattlePrepRuleWindowLayout* arg1) {
    BattlePrep_DrawBorderedRect(arg1->unk_00 + 8, arg1->unk_02 + 0x14, 0xA8, 0x20, 0, 0, 0, 0xFF);
    BattlePrep_DrawBorderedRect(arg1->unk_00 + 8, arg1->unk_02 + 0x44, 0xA8, 0x20, 0, 0, 0, 0xFF);
    BattlePrep_DrawRankBadge(arg1->unk_00 + 8, arg1->unk_02 + 0x14, D_800AE540.unk_1194);
    BattlePrep_DrawRankBadge(arg1->unk_00 + 8, arg1->unk_02 + 0x44, &D_800AE540.unk_1194[1]);
    Font_BeginTranslucentTextRendering();
    Font_EnableTwoCycleTexturing();
    Font_SetActive(4, 0);
    Gfx_SetPrimColor(0x32, 0xFF, 0x64, 0xFF);
    Font_Printf(arg1->unk_00 + 0x40, arg1->unk_02 + 2, BattlePrep_GetString(0x38));
    Font_DisableTwoCycleTexturing();
    Font_SetActive(0x10, 0);
    BattlePrep_SetStreakColor(&D_800AE540.unk_1194[0]);
    Font_Printf(arg1->unk_00 + 0x5C, arg1->unk_02 + 0x18, "%2d", D_800AE540.unk_1194[0].unk_1E);
    BattlePrep_SetStreakColor(&D_800AE540.unk_1194[1]);
    Font_Printf(arg1->unk_00 + 0x5C, arg1->unk_02 + 0x48, "%2d", D_800AE540.unk_1194[1].unk_1E);
    Font_SetActive(4, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    Font_Printf(arg1->unk_00 + 0x82, arg1->unk_02 + 0x1F, BattlePrep_GetString(0x39));
    Font_Printf(arg1->unk_00 + 0x82, arg1->unk_02 + 0x4F, BattlePrep_GetString(0x39));
    Font_EndTexturedTextRendering();
}

void BattlePrep_DrawStreakGiveUpPrompt(BattlePrepRuleWindow* arg0, BattlePrepRuleWindowLayout* arg1) {
    SessionContinueData sp50;
    UNUSED s32 pad;
    s32 sp48;
    s32 temp_v0;

    Session_LoadContinueRecord(&sp50, NULL);
    BattlePrep_DrawBorderedRect(arg1->unk_00 + 0x10, arg1->unk_02 + 0x14, 0xA8, 0x3C, 0, 0, 0, 0xFF);
    BattlePrep_DrawBorderedRect(arg1->unk_00 + 0x10, arg1->unk_02 + 0x60, 0xA8, 0x22, 0, 0, 0, 0xFF);
    BattlePrep_DrawCursorArrow(arg0, arg1->unk_00 + 0x14, arg1->unk_02 + 0x64);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    Font_Printf(arg1->unk_00 + 0x10, arg1->unk_02 + 6, BattlePrep_GetString(0x3A));
    Font_Printf(arg1->unk_00 + 0x10, arg1->unk_02 + 0x52, BattlePrep_GetString(0x3B));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x2A, arg1->unk_02 + 0x64, 0, 1, BattlePrep_GetString(0x3C));
    BattlePrep_DrawRuleOption(arg0, arg1->unk_00 + 0x2A, arg1->unk_02 + 0x64, 1, 1, BattlePrep_GetString(0x3D));
    Gfx_SetEnvColor(0xFF, 0x64, 0x64, 0xFF);

    if (sp50.unk_00 == 7) {
        Font_Printf(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x17, BattlePrep_GetString(sp50.unk_00 - 1));
        Font_Printf(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x26, BattlePrep_GetString(sp50.unk_01 + 0x13));
        if (sp50.unk_01 < 8) {
            if (sp50.unk_02 < 4) {
                Font_Printf(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x35, "%s %d", BattlePrep_GetString(0x37), sp50.unk_02);
            } else {
                Font_Printf(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x35, BattlePrep_GetString(0x3E));
            }
        } else {
            Font_Printf(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x35, "%s %d", BattlePrep_GetString(0x1B), sp50.unk_02);
        }
    } else if ((sp50.unk_00 == 3) || (sp50.unk_00 == 6)) {
        Font_Printf(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x17, BattlePrep_GetString(sp50.unk_00 - 1));
        Font_Printf(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x26, BattlePrep_GetString(sp50.unk_01 + 7));
        Font_Printf(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x35, BattlePrep_GetString(sp50.unk_02 + 0xA));
    } else {
        Font_Printf(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x17, BattlePrep_GetString(sp50.unk_00 - 1));
        Font_Printf(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x26, BattlePrep_GetString(sp50.unk_02 + 0xA));
    }

    if (sp50.unk_00 != 7) {
        Font_SetActive(1, 0);
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        Font_Printf(arg1->unk_00 + 0x64, arg1->unk_02 + 0x43, "%s %d", BattlePrep_GetString(0x2C), sp50.unk_04);
    }

    if (arg0->unk_04 == 0) {
        sp48 = (arg1->unk_04 - Font_MeasureTextExtent(1, 0, BattlePrep_GetString(0x3F))) / 2;
        Font_SetActive(1, 0);
        Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
        Font_SetLineHeight(0xC);
        Font_Printf(arg1->unk_00 + sp48, arg1->unk_02 + 0x86, BattlePrep_GetString(0x3F));
    }

    Font_EndTexturedTextRendering();

    if (sp50.unk_03 == 1) {
        temp_v0 = Font_MeasureTextExtent(1, 0, BattlePrep_GetString(sp50.unk_00 - 1));

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        Gfx_DrawTextureRgba16(arg1->unk_00 + temp_v0 + 0x20, arg1->unk_02 + 0x15, 0x10, 0x10, D_3027690, 0x10, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }
}

void BattlePrep_DrawRuleWindow(BattlePrepRuleWindow* arg0) {
    BattlePrepRuleWindowLayout* temp_s0;
    s16 temp_a1;
    s16 var_a3;

    if ((arg0->unk_00 != 0) && (arg0->unk_02 > 0)) {
        temp_s0 = &gBattlePrepRuleWindowLayouts[arg0->unk_01 - 1];

        if (arg0->unk_02 < 4) {
            var_a3 = (temp_s0->unk_06 * arg0->unk_02) / 4;
            if (var_a3 < 0x10) {
                var_a3 = 0x10;
            }

            temp_a1 = temp_s0->unk_02 + ((temp_s0->unk_06 - var_a3) / 2);
            if (temp_s0->unk_0C == 0) {
                Ui_DrawBorderedPanel(temp_s0->unk_00, temp_a1, temp_s0->unk_04, var_a3, temp_s0->unk_0A);
            } else {
                BattlePrep_DrawBorderedRect(temp_s0->unk_00, temp_a1, temp_s0->unk_04, var_a3, 0x1E, 0x1E, 0x82, 0xFF);
            }
        } else {
            if (temp_s0->unk_0C == 0) {
                Ui_DrawBorderedPanel(temp_s0->unk_00, temp_s0->unk_02, temp_s0->unk_04, temp_s0->unk_06, temp_s0->unk_0A);
            } else {
                BattlePrep_DrawBorderedRect(temp_s0->unk_00, temp_s0->unk_02, temp_s0->unk_04, temp_s0->unk_06, 0x1E, 0x1E, 0x82,
                              0xFF);
            }

            switch (arg0->unk_01) {
                case 1:
                    BattlePrep_DrawResultPrompt(arg0, temp_s0);
                    break;

                case 2:
                    BattlePrep_DrawResultPrompt(arg0, temp_s0);
                    break;

                case 3:
                    BattlePrep_DrawContinuePrompt(arg0, temp_s0);
                    break;

                case 4:
                    BattlePrep_DrawGiveUpPrompt(arg0, temp_s0);
                    break;

                case 5:
                    BattlePrep_DrawRetireStreakPrompt(arg0, temp_s0);
                    break;

                case 6:
                    BattlePrep_DrawQuitPrompt(arg0, temp_s0);
                    break;

                case 7:
                    BattlePrep_DrawCupRuleSummary(arg0, temp_s0);
                    break;

                case 8:
                    BattlePrep_DrawCastleRuleSummary(arg0, temp_s0);
                    break;

                case 9:
                    BattlePrep_DrawTeamPreview(arg0, temp_s0);
                    break;

                case 10:
                    BattlePrep_DrawStreakGiveUpPrompt(arg0, temp_s0);
                    break;
            }
        }
    }
}

void BattlePrep_RunQuitMenu(BattlePrepRuleWindow* arg0) {
    BattlePrepRuleWindowLayout* sp24;
    s16 sp22;
    s32 tmp;

    sp24 = &gBattlePrepRuleWindowLayouts[arg0->unk_01 - 1];
    sp22 = sp24->unk_08 - 1;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        tmp = sp24->unk_10 >> (arg0->unk_04 * 3);
        switch (tmp & 7) {
            case 1:
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
                break;

            case 2:
                Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                break;

            case 3:
                Audio_PlaySoundEffectById(0x1C);
                break;

            case 4:
                Audio_PlaySoundEffectById(0x20);
                break;

            case 5:
                Audio_PlaySoundEffectById(0x1D);
                break;

            case 6:
                Audio_PlaySoundEffectById(0x21);
                break;
        }
        arg0->unk_00 = 2;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        do {
            arg0->unk_04--;
            if (arg0->unk_04 < 0) {
                arg0->unk_04 = sp22;
            }
        } while (!(sp24->unk_0E & (1 << arg0->unk_04)));
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        do {
            arg0->unk_04++;
            if (sp22 < arg0->unk_04) {
                arg0->unk_04 = 0;
            }
        } while (!(sp24->unk_0E & (1 << arg0->unk_04)));
    }
}

void BattlePrep_RuleWindowExpanding(BattlePrepRuleWindow* arg0) {
    arg0->unk_02++;
    if (arg0->unk_02 >= 5) {
        arg0->unk_02 = 4;
        arg0->unk_00 = 3;
    }
}

void BattlePrep_RuleWindowCollapsing(BattlePrepRuleWindow* arg0) {
    arg0->unk_02--;
    if (arg0->unk_02 < 0) {
        arg0->unk_02 = 0;
        arg0->unk_00 = 4;
    }
}

void BattlePrep_UpdateRuleWindow(BattlePrepRuleWindow* arg0) {
    switch (arg0->unk_00) {
        case 1:
            BattlePrep_RuleWindowExpanding(arg0);
            break;

        case 2:
            BattlePrep_RuleWindowCollapsing(arg0);
            break;

        case 3:
            BattlePrep_RunQuitMenu(arg0);
            break;
    }
}

void BattlePrep_InitRuleWindow(BattlePrepRuleWindow* arg0, s16 arg1) {
    BattlePrepRuleWindowLayout* ptr = &gBattlePrepRuleWindowLayouts[arg1 - 1];

    arg0->unk_01 = arg1;
    arg0->unk_02 = 0;
    arg0->unk_04 = 0;
    arg0->unk_00 = 1;

    ptr->unk_0E = -1;

    Audio_PlaySoundEffectById(SFX_PANEL_OPEN);

    if (arg1 - 1 == 2) {
        if (D_800AE540.unk_11F3 == 0) {
            ptr->unk_0E &= ~3;
        }
        if (D_800AE540.unk_11F5 & 2) {
            ptr->unk_0E &= ~4;
        }
    } else if (arg1 - 1 == 3) {
        if (D_800AE540.unk_11F5 & 2) {
            ptr->unk_0E &= ~1;
        }
    } else if ((arg1 - 1 == 4) &&
               ((D_800AE540.unk_1194[0].unk_1E >= 0x63) || (D_800AE540.unk_1194[1].unk_1E >= 0x63))) {
        ptr->unk_0E &= ~1;
    }

    while (!(ptr->unk_0E & (1 << arg0->unk_04))) {
        arg0->unk_04++;
    }
}

void BattlePrep_CloseRuleWindow(BattlePrepRuleWindow* arg0) {
    arg0->unk_00 = 0;
    arg0->unk_01 = 0;
    arg0->unk_02 = 0;
}

s32 BattlePrep_PollRuleWindow(BattlePrepRuleWindow* arg0) {
    if (arg0->unk_00 == 4) {
        arg0->unk_00 = 0;
        return arg0->unk_04;
    }
    return -1;
}
