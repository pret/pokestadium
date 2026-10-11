#include "rental_team_selection.h"
#include "src/display_object_textures.h"
#include "src/poke_icon.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/status_icons.h"
#include "src/gb_data.h"
#include "src/pokemon_stats.h"
#include "src/save_data.h"
#include "src/text_system.h"
#include "src/audio_sfx.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"
#include "src/dp_intro.h"
#include "src/hal_libc.h"

s16 D_8423E580;
Controller* D_8423E584;
s16 D_8423E588;
s16 D_8423E58A;

s16 D_84211700 = 0;
unk_D_84211704 D_84211704[] = {
    {
        132,
        300,
        376,
        136,
        0,
        4,
        0,
        8481,
        0x0374,
    },
    {
        132,
        300,
        376,
        136,
        0,
        1,
        0,
        8481,
        0x0002,
    },
    {
        132,
        300,
        376,
        136,
        0,
        1,
        0,
        26907,
        0x0002,
    },
    {
        132,
        300,
        376,
        136,
        0,
        1,
        0,
        -32503,
        0x0001,
    },
    {
        210,
        300,
        220,
        108,
        0,
        3,
        0,
        8481,
        0x006C,
    },
    {
        210,
        150,
        220,
        108,
        0,
        3,
        0,
        8481,
        0x006C,
    },
    {
        210,
        300,
        290,
        108,
        0,
        3,
        2,
        -32503,
        0x0052,
    },
    {
        210,
        150,
        290,
        108,
        0,
        3,
        2,
        -32503,
        0x0052,
    },
    {
        110,
        300,
        420,
        92,
        0,
        1,
        0,
        26907,
        0x0002,
    },
    {
        210,
        300,
        290,
        82,
        0,
        2,
        0,
        8481,
        0x000A,
    },
    {
        132,
        300,
        376,
        136,
        0,
        3,
        0,
        8481,
        0x0052,
    },
    {
        70,
        320,
        500,
        92,
        0,
        1,
        0,
        26907,
        0x0002,
    },
    {
        160,
        320,
        320,
        82,
        0,
        2,
        0,
        8481,
        0x000A,
    },
    {
        110,
        300,
        420,
        136,
        0,
        1,
        0,
        -32503,
        0x0002,
    },
    {
        110,
        300,
        420,
        136,
        0,
        1,
        0,
        -32503,
        0x0002,
    },
    {
        110,
        300,
        420,
        136,
        0,
        1,
        0,
        -32503,
        0x0002,
    },
    {
        132,
        180,
        376,
        92,
        -22,
        1,
        0,
        26889,
        0x0002,
    },
    {
        120,
        160,
        400,
        64,
        0,
        1,
        0,
        26889,
        0x0002,
    },
    {
        120,
        160,
        400,
        64,
        0,
        1,
        0,
        26889,
        0x0002,
    },
    {
        210,
        300,
        290,
        82,
        0,
        2,
        1,
        8481,
        0x000A,
    },
};

void TeamSelection_RulePrompt_DrawOption(s16 arg0, s16 arg1, s16 arg2, char* arg3) {
    if (arg2 == D_8423E58A) {
        Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
    } else {
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    }
    Font_Printf(arg0 + 0x3C, arg1 + (arg2 * 0x1C) + 0xC, arg3);
}

void TeamSelection_RulePrompt_DrawOptionSetFour(unk_D_84211704* arg0) {
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 0, TeamSelection_GetLabelText(0x15));
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 1, TeamSelection_GetLabelText(0x16));
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 2, TeamSelection_GetLabelText(0x17));
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 3, TeamSelection_GetLabelText(0x18));
    Font_EndTexturedTextRendering();

    if (D_8423E58A >= 0) {
        Ui_DrawAnimatedTextureMarker(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void TeamSelection_RulePrompt_DrawOptionSetThreeA(unk_D_84211704* arg0) {
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 0, TeamSelection_GetLabelText(0x19));
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 1, TeamSelection_GetLabelText(0x1A));
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 2, TeamSelection_GetLabelText(0x1B));
    Font_EndTexturedTextRendering();

    if (D_8423E58A >= 0) {
        Ui_DrawAnimatedTextureMarker(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void TeamSelection_RulePrompt_DrawOptionSetThreeB(unk_D_84211704* arg0) {
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 0, TeamSelection_GetLabelText(0x15));
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 1, TeamSelection_GetLabelText(0x17));
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 2, TeamSelection_GetLabelText(0x18));
    Font_EndTexturedTextRendering();

    if (D_8423E58A >= 0) {
        Ui_DrawAnimatedTextureMarker(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void TeamSelection_RulePrompt_DrawOptionSetThreeC(unk_D_84211704* arg0) {
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 0, TeamSelection_GetLabelText(0x1C));
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 1, TeamSelection_GetLabelText(0x1D));
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 2, TeamSelection_GetLabelText(0x1E));
    Font_EndTexturedTextRendering();

    if (D_8423E58A >= 0) {
        Ui_DrawAnimatedTextureMarker(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void TeamSelection_RulePrompt_DrawOptionSetTwo(unk_D_84211704* arg0) {
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 0, TeamSelection_GetLabelText(0x1F));
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 1, TeamSelection_GetLabelText(0x20));
    Font_EndTexturedTextRendering();

    if (D_8423E58A >= 0) {
        Ui_DrawAnimatedTextureMarker(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void TeamSelection_RulePrompt_DrawSingleLabel(unk_D_84211704* arg0) {
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Font_Printf(arg0->unk_00 + 0x2D, arg0->unk_02 + 0x38, TeamSelection_GetLabelText(0x21));
    Font_EndTexturedTextRendering();
}

void TeamSelection_RulePrompt_DrawThreeRowPanel(unk_D_84211704* arg0) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x18, arg0->unk_02 + 0x26, 0x4C, 0x14, D_2029CE0, 0x4C, 0);
    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x18, arg0->unk_02 + 0x3A, 0x4C, 0x14, D_202A8C0, 0x4C, 0);
    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x18, arg0->unk_02 + 0x4E, 0x4C, 0x14, D_202B4A0, 0x4C, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Font_Printf(arg0->unk_00 + 0x78, arg0->unk_02 + 0x38, TeamSelection_GetLabelText(0x22));
    Font_EndTexturedTextRendering();
}

void TeamSelection_RulePrompt_DrawOffsetThreeRowPanel(unk_D_84211704* arg0) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x18, arg0->unk_02 + arg0->unk_08 + 0x26, 0x4C, 0x14, D_2029CE0, 0x4C, 0);
    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x18, arg0->unk_02 + arg0->unk_08 + 0x3A, 0x4C, 0x14, D_202A8C0, 0x4C, 0);
    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x18, arg0->unk_02 + arg0->unk_08 + 0x4E, 0x4C, 0x14, D_202B4A0, 0x4C, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Font_SetLineHeight(0x1E);
    Font_Printf(arg0->unk_00 + 0x78, arg0->unk_02 + arg0->unk_08 + 0x29, TeamSelection_GetLabelText(0x23));
    Font_EndTexturedTextRendering();
}

void TeamSelection_RulePrompt_DrawSmallThreeRowPanel(unk_D_84211704* arg0) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x10, arg0->unk_02 + 0x10, 0x4C, 0x14, D_2029CE0, 0x4C, 0);
    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x10, arg0->unk_02 + 0x24, 0x4C, 0x14, D_202A8C0, 0x4C, 0);
    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x10, arg0->unk_02 + 0x38, 0x4C, 0x14, D_202B4A0, 0x4C, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Font_SetLineHeight(0x1C);
    Font_Printf(arg0->unk_00 + 0x68, arg0->unk_02 + 0x14, TeamSelection_GetLabelText(0x24));
    Font_EndTexturedTextRendering();
}

void TeamSelection_RulePrompt_DrawSmallThreeRowVariant(unk_D_84211704* arg0) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x10, arg0->unk_02 + 0x10, 0x4C, 0x14, D_2029CE0, 0x4C, 0);
    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x10, arg0->unk_02 + 0x24, 0x4C, 0x14, D_202A8C0, 0x4C, 0);
    Gfx_DrawTextureRgba16(arg0->unk_00 + 0x10, arg0->unk_02 + 0x38, 0x4C, 0x14, D_202B4A0, 0x4C, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Font_Printf(arg0->unk_00 + 0x68, arg0->unk_02 + 0x22, TeamSelection_GetLabelText(0x25));
    Font_EndTexturedTextRendering();
}

void TeamSelection_RulePrompt_DrawOptionSetTwoB(unk_D_84211704* arg0) {
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 0, TeamSelection_GetLabelText(0x26));
    TeamSelection_RulePrompt_DrawOption(arg0->unk_00, arg0->unk_02, 1, TeamSelection_GetLabelText(0x20));
    Font_EndTexturedTextRendering();

    if (D_8423E58A >= 0) {
        Ui_DrawAnimatedTextureMarker(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void TeamSelection_RulePrompt_DrawNumberAndLabel(unk_D_84211704* arg0, s16 arg1) {
    char sp28[0x100];
    s32 tmp;
    char* sp20;

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Font_SetLineHeight(0x1C);
    Text_SetNumberToken(2, arg1);
    sp20 = TeamSelection_FormatText(sp28, sizeof(sp28), 0x27);
    tmp = ((arg0->unk_04 - Font_MeasureTextExtent(0, 0, sp20)) / 2);
    Font_Printf(arg0->unk_00 + tmp, arg0->unk_02 + 0x14, sp20);
    sp20 = TeamSelection_GetLabelText(0x28);
    tmp = ((arg0->unk_04 - Font_MeasureTextExtent(0, 0, sp20)) / 2);
    Font_Printf(arg0->unk_00 + tmp, arg0->unk_02 + 0x56, sp20);
    Font_EndTexturedTextRendering();
}

void TeamSelection_RulePrompt_DrawBinaryLabel(unk_D_84211704* arg0, s16 arg1) {
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    if (arg1 == 0) {
        Font_Printf(arg0->unk_00 + 0x18, arg0->unk_02 + 0x14, TeamSelection_GetLabelText(0x29));
    } else {
        Font_Printf(arg0->unk_00 + 0x39, arg0->unk_02 + 0x14, TeamSelection_GetLabelText(0x2A));
    }
    Font_EndTexturedTextRendering();
}

void TeamSelection_RulePrompt_DrawFrame(s32 arg0) {
    s16 tmp2;
    s16 var_a3;
    unk_D_84211704* temp_s0;

    if ((D_84211700 != 0) && (D_8423E588 > 0)) {
        temp_s0 = &D_84211704[D_8423E580];
        if (D_8423E588 < 4) {
            var_a3 = (temp_s0->unk_06 * D_8423E588) / 4;
            if (var_a3 < 0x10) {
                var_a3 = 0x10;
            }
            tmp2 = temp_s0->unk_02 + ((temp_s0->unk_06 - var_a3) / 2);
            Ui_DrawBorderedPanel(temp_s0->unk_00, tmp2, temp_s0->unk_04, var_a3, temp_s0->unk_0C);
        } else {
            Ui_DrawBorderedPanel(temp_s0->unk_00, temp_s0->unk_02, temp_s0->unk_04, temp_s0->unk_06, temp_s0->unk_0C);

            switch (D_8423E580) {
                case 0:
                    TeamSelection_RulePrompt_DrawOptionSetFour(temp_s0);
                    break;
                case 1:
                    TeamSelection_RulePrompt_DrawSingleLabel(temp_s0);
                    break;
                case 2:
                    TeamSelection_RulePrompt_DrawThreeRowPanel(temp_s0);
                    break;
                case 3:
                    TeamSelection_RulePrompt_DrawOffsetThreeRowPanel(temp_s0);
                    break;
                case 4:
                    TeamSelection_RulePrompt_DrawOptionSetThreeA(temp_s0);
                    break;
                case 5:
                    TeamSelection_RulePrompt_DrawOptionSetThreeA(temp_s0);
                    break;
                case 6:
                    TeamSelection_RulePrompt_DrawOptionSetThreeC(temp_s0);
                    break;
                case 7:
                    TeamSelection_RulePrompt_DrawOptionSetThreeC(temp_s0);
                    break;
                case 8:
                    TeamSelection_RulePrompt_DrawSmallThreeRowPanel(temp_s0);
                    break;
                case 9:
                    TeamSelection_RulePrompt_DrawOptionSetTwo(temp_s0);
                    break;
                case 10:
                    TeamSelection_RulePrompt_DrawOptionSetThreeB(temp_s0);
                    break;
                case 11:
                    TeamSelection_RulePrompt_DrawSmallThreeRowVariant(temp_s0);
                    break;
                case 12:
                    TeamSelection_RulePrompt_DrawOptionSetTwoB(temp_s0);
                    break;
                case 13:
                    TeamSelection_RulePrompt_DrawNumberAndLabel(temp_s0, 0x9B);
                    break;
                case 14:
                    TeamSelection_RulePrompt_DrawNumberAndLabel(temp_s0, 0x50);
                    break;
                case 15:
                    TeamSelection_RulePrompt_DrawNumberAndLabel(temp_s0, 0x32);
                    break;
                case 16:
                    TeamSelection_RulePrompt_DrawOffsetThreeRowPanel(temp_s0);
                    break;
                case 17:
                    TeamSelection_RulePrompt_DrawBinaryLabel(temp_s0, 0);
                    break;
                case 18:
                    TeamSelection_RulePrompt_DrawBinaryLabel(temp_s0, 1);
                    break;
                case 19:
                    TeamSelection_RulePrompt_DrawOptionSetTwo(temp_s0);
                    break;
            }
        }
    }
}

void TeamSelection_RulePrompt_HandleInput(void) {
    s16 tmp = D_84211704[D_8423E580].unk_0A;

    if (D_8423E584 != NULL) {
        if (BTN_IS_PRESSED(D_8423E584, BTN_A)) {
            s32 tmp2 = (D_84211704[D_8423E580].unk_0E >> (D_8423E58A * 3));

            switch (tmp2 & 7) {
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
                    Audio_PlaySoundEffectById(0x21);
                    break;

                case 6:
                    if (Deck_FindFirstFreeTeamSlot() < 0xC) {
                        Audio_PlaySoundEffectById(0x20);
                    } else {
                        Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                    }
                    break;
            }
            D_84211700 = 3;
        } else if (BTN_IS_PRESSED(D_8423E584, BTN_B)) {
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
            D_8423E58A = -1;
            D_84211700 = 3;
        } else if (BTN_IS_PRESSED(D_8423E584, BTN_DUP)) {
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            D_8423E58A -= 1;
            if (D_8423E58A < 0) {
                D_8423E58A = tmp - 1;
            }
        } else if (BTN_IS_PRESSED(D_8423E584, BTN_DDOWN)) {
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            D_8423E58A += 1;
            if (D_8423E58A >= tmp) {
                D_8423E58A = 0;
            }
        }
    }
    D_8423E588 = 4;
}

void TeamSelection_RulePrompt_AdvanceOpen(void) {
    D_8423E588++;
    if (D_8423E588 >= 5) {
        D_8423E588 = 4;
        D_84211700 = 2;
    }
}

void TeamSelection_RulePrompt_AdvanceClose(void) {
    D_8423E588--;
    if (D_8423E588 < 0) {
        D_8423E588 = 0;
        D_84211700 = 4;
    }
}

s32 TeamSelection_RulePrompt_Update(void) {
    s32 sp1C = 0;

    switch (D_84211700) {
        case 2:
            sp1C = 0;
            TeamSelection_RulePrompt_HandleInput();
            break;

        case 1:
            TeamSelection_RulePrompt_AdvanceOpen();
            sp1C = 1;
            break;

        case 3:
            TeamSelection_RulePrompt_AdvanceClose();
            sp1C = 1;
            break;
    }

    return sp1C;
}

s32 TeamSelection_RulePrompt_Open(s16 arg0, Controller* arg1) {
    if (D_84211700 == 0) {
        switch (arg0) {
            case 8:
                Audio_PlaySoundEffectById(0x1F);

            case 11:
                Audio_PlaySoundEffectById(0x1E);
                break;
        }
        Audio_PlaySoundEffectById(SFX_PANEL_OPEN);
        D_8423E580 = arg0;
        D_8423E58A = D_84211704[arg0].unk_0B;
        D_8423E588 = 0;
        D_8423E584 = arg1;
        D_84211700 = 1;
        return 1;
    }
    return 0;
}

s32 TeamSelection_RulePrompt_BeginClose(s16 arg0) {
    if ((D_84211700 == 2) && (arg0 == D_8423E580)) {
        D_8423E58A = -1;
        D_84211700 = 3;
        return 1;
    }
    return 0;
}

s16 TeamSelection_RulePrompt_TryFinish(s16 arg0) {
    if ((D_84211700 == 4) && (arg0 == D_8423E580)) {
        D_84211700 = 0;
        return D_8423E58A + 1;
    }
    return -1;
}
