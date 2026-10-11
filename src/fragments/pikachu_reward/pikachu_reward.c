#include "pikachu_reward.h"
#include "src/geo_render.h"
#include "src/model_animation.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/pokemon_stats.h"
#include "src/text_system.h"
#include "src/gb_save.h"
#include "src/jpeg_stream.h"
#include "src/audio_fade.h"
#include "src/audio_stored_fade.h"
#include "src/audio_sfx.h"
#include "src/cry.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/DDC0.h"
#include "src/matrix.h"
#include "src/geo_layout.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/util.h"

static GraphNode* D_83202010;
static GraphNode* D_83202014;
static unk_D_86002F30* D_83202018;
static char** D_8320201C;
static char** D_83202020;
static DisplayObject D_83202028[4];
static unk_D_832025C8 D_832025C8;
static unk_D_832027C8 D_832027C8;

static s32 D_83201F50 = 0;
static s32 D_83201F54 = -1;
static char* D_83201F58 = NULL;
static u32 D_83201F5C[] = {
    0x0C000000,  0x05000000, 0x0B00001E,    0x00000000, 0x014000F0, 0x00000320, 0x00000000, 0x000005DC, 0x05000000,
    0x0D000000,  0x05000000, 0x0E000002,    0x05000000, 0x22010000, 0x8C200060, 0x06000000, 0x14000000, 0x002B0012,
    0xFFFFFF32,  0x16FFFFFF, 0x0F000003,    0x05000000, 0x1F000000, 0x00000000, 0x00000000, 0x003CFF06, 0x00640064,
    0x00640000,  0x08000000, PikachuReward_PositionSurfingPikachuModel, 0x00000000, 0x05000000, 0x00000000, D_8C200920, 0x06000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000,    0x06000000, 0x06000000, 0x01000000,
};

s32 PikachuReward_PositionSurfingPikachuModel(s32 arg0, DisplayObject* arg1) {
    if (arg0 == 2) {
        arg1->rotation.z -= 0x80;
        arg1->position.x = D_83202028->position.x;
        arg1->position.y = D_83202028->position.y + 70.0f;
    }
    return 0;
}

s32 PikachuReward_CheckNoSpecialMove(BattleMon* arg0) {
    s32 i;
    s32 var_v1 = 1;

    for (i = 0; i < 4; i++) {
        if (arg0->unk_09[i] == 0) {
            break;
        }

        if (arg0->unk_09[i] >= 0xA6) {
            var_v1 = 0;
        }
    }

    return var_v1;
}

s32 PikachuReward_CheckEligibleForSurf(BattleMon* arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 sp1C = 0;

    if ((arg0->unk_00.unk_00 > 0) && (arg0->unk_00.unk_00 < 0x98)) {
        if ((PikachuReward_CheckNoSpecialMove(arg0) != 0) && (D_8006FF00[arg0->unk_00.unk_00 - 1].unk_0C & arg3)) {
            if ((arg0->unk_24 >= arg1) && (arg2 >= arg0->unk_24)) {
                sp1C = 1;
            }
        }
    }
    return sp1C;
}

s32 PikachuReward_SearchDeckForPikachu(s16 arg0, s16 arg1, s16 arg2) {
    UNUSED s32 pad[22];
    s32 sp34;
    s16 var_s3;
    DeckHandle* var_v0;
    BattleMon* ptr = &D_832027C8.unk_04;

    sp34 = 0;
    var_s3 = 0;

    if (arg1 == 0) {
        var_v0 = Deck_Open(0x20, arg0, 0, 0);
    } else {
        var_v0 = Deck_Open(0x21, arg0, arg1 - 1, 0);
    }

    if (var_v0 != NULL) {
        while (Deck_ReadEntries(&ptr->unk_00.unk_00, 1, var_v0) == 1) {
            if (PikachuReward_CheckEligibleForSurf(ptr, 1, 0x64, 0x20) != 0) {
                if (!arg2--) {
                    if (ptr->unk_00.unk_00 == 0x19) {
                        sp34 = 1;
                    }
                    break;
                }
            }
            var_s3++;
        }
        Deck_CloseAndFlush(var_v0);
    }

    if (sp34 != 0) {
        return var_s3;
    }
    return -1;
}

s32 PikachuReward_FindPikachuOnCart(void) {
    s32 i;
    TeamRoster* var_v1;

    var_v1 = D_800AE540.unk_1194[0].unk_08[0];

    for (i = 0; i < var_v1->unk_002; i++) {
        if (var_v1->unk_01C[i].unk_00.unk_00 == 0x19) {
            D_832027C8.unk_00 = (var_v1->unk_01C[i].unk_52 & 0x70) >> 4;
            D_832027C8.unk_01 = var_v1->unk_01C[i].unk_52 & 0xF;
            if ((D_832027C8.unk_00 < 4) && (D_832027C8.unk_01 < 0xD)) {
                if (GbSave_LoadPort(D_832027C8.unk_00) != 0) {
                    D_832027C8.unk_02 = PikachuReward_SearchDeckForPikachu(D_832027C8.unk_00, D_832027C8.unk_01, var_v1->unk_01C[i].unk_53);
                    if (D_832027C8.unk_02 >= 0) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }

    return 0;
}

s32 PikachuReward_CountKnownMoves(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_832027C8.unk_04.unk_09[i] == 0) {
            break;
        }
    }
    return i;
}

void PikachuReward_UpdateLeadPikachuAnimation(void) {
    static s32 D_83202004 = 0;

    if ((D_83202028[0].transformAnim.animationId != 0xA) && (D_83202028[0].transformAnim.animationId != 5)) {
        D_83202004++;
        if (D_83202004 == 0x3C) {
            D_83202004 = 0;
            ModelAnim_SetEventTrack(&D_83202028[0], -1);
            ModelAnim_SetEventTrack(&D_83202028[0], 0xA);
        }
    }

    if ((D_83202028[0].transformAnim.animationId != 0) && (ModelAnim_IsFinished(&D_83202028[0]) != 0)) {
        if (D_83201F50 != 0) {
            D_83202028[0].node.flags &= ~1;
        } else {
            ModelAnim_SetAnimation(&D_83202028[0], 0);
        }
    }
}

void PikachuReward_UpdateFollowerVisibility(void) {
    if (D_83201F54 == -1) {
        D_83202028[1].node.flags &= ~1;
        D_83202028[2].node.flags &= ~1;
        D_83202028[3].node.flags &= ~1;
        return;
    }

    switch (D_83201F54) {
        case 0x0:
            D_83202028[1].node.flags |= 1;
            break;

        case 0x8:
            D_83202028[2].node.flags |= 1;
            break;

        case 0x10:
            D_83202028[3].node.flags |= 1;
            break;

        case 0x46:
            D_83202028[1].node.flags &= ~1;
            break;

        case 0x4E:
            D_83202028[2].node.flags &= ~1;
            break;

        case 0x56:
            D_83202028[3].node.flags &= ~1;
            break;
    }

    if (D_83201F54 < 0x57) {
        D_83201F54++;
    }
}

s32 PikachuReward_RenderFrame(u8 arg0) {
    GeoRender_AdvanceFrameCounter();
    PikachuReward_UpdateLeadPikachuAnimation();
    PikachuReward_UpdateFollowerVisibility();
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 1);
    Geo_RenderRootNode(D_83202010);
    return 0;
}

void PikachuReward_DrawBlinkingStarIcon(s16 arg0, s16 arg1) {
    s32 var_a3;

    if (D_832025C8.unk_00 < 0x10) {
        var_a3 = D_832025C8.unk_00 * 0x10;
    } else if (D_832025C8.unk_00 < 0x23) {
        var_a3 = 0xFF;
    } else if (D_832025C8.unk_00 < 0x32) {
        var_a3 = (-D_832025C8.unk_00 * 0x10) + 0x320;
    } else {
        var_a3 = 0;
    }

    D_832025C8.unk_00++;
    if (D_832025C8.unk_00 >= 0x3D) {
        D_832025C8.unk_00 = 0;
    }

    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, var_a3);
    Font_DrawCharAt(arg0, arg1, 0x23);
}

void PikachuReward_DrawTextBoxPanel(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    Color_RGB8 sp24 = { 0x00, 0x00, 0x32 };
    Color_RGB8 sp20 = { 0x00, 0x00, 0xC8 };

    Ui_DrawGradientPanel(arg0, arg1, arg2, arg3, &sp24, &sp20);
}

void PikachuReward_DrawSelectionCursor(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F4E0);

    Gfx_DrawTextureRgba16(arg0, arg1, 0x18, 0xE, Util_ConvertAddrToVirtAddr(D_8C200090), 0x18, 0x200000);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void PikachuReward_ShowTextForFrames(char* arg0, s32 arg1) {
    while (arg1-- > 0) {
        Controller_PollInputs();
        PikachuReward_RenderFrame(0);
        PikachuReward_DrawTextBoxPanel(0x1E, 0x20, 0x104, 0x30);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(2, 0);
        Font_SetLineHeight(0x10);
        Font_Printf(0x2E, 0x28, arg0);
        Font_EndTexturedTextRendering();
        BgStage_AdvanceFrame();
    }

    D_83201F58 = arg0;
}

void PikachuReward_ShowTextWaitForA(char* arg0, s32 arg1) {
    D_832025C8.unk_00 = 0x10;

    do {
        Controller_PollInputs();
        PikachuReward_RenderFrame(0);
        PikachuReward_DrawTextBoxPanel(0x1E, 0x20, 0x104, 0x30);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(2, 0);
        Font_SetLineHeight(0x10);
        Font_Printf(0x2E, 0x28, arg0);
        Font_SetActive(4, 0);
        if (arg1 != 0) {
            PikachuReward_DrawBlinkingStarIcon(0x104, 0x38);
        }
        Font_EndTexturedTextRendering();
        BgStage_AdvanceFrame();
    } while (!BTN_IS_PRESSED(gPlayer1Controller, BTN_A));

    Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    D_83201F58 = arg0;
}

void PikachuReward_ScrollTextIn(s8* arg0) {
    s32 i;
    s32 x1 = 0x1E;
    s32 x2 = 0x122;
    s32 y1 = 0x28;
    s32 y2 = 0x48;

    for (i = 1; i < 9; i++) {
        Controller_PollInputs();
        PikachuReward_RenderFrame(0);
        PikachuReward_DrawTextBoxPanel(0x1E, 0x20, 0x104, 0x30);

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

        Font_BeginTranslucentTextRendering();
        Font_SetActive(2, 0);
        Font_SetLineHeight(0x10);
        Font_Printf(0x2E, y1 - i * 4, D_83201F58);
        Font_Printf(0x2E, y2 - i * 4, arg0);
        Font_EndTexturedTextRendering();
        BgStage_AdvanceFrame();
    }

    D_83201F58 = arg0;
}

s32 PikachuReward_ConfirmYesNoPrompt(char* arg0) {
    s32 temp_s3;
    s32 var_a2;
    s32 var_s1;
    s32 var_s2;

    var_s2 = 1;
    var_s1 = 0;

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

        temp_s3 = var_s1 == 0;
        PikachuReward_RenderFrame(0);
        PikachuReward_DrawTextBoxPanel(0x1E, 0x20, 0x104, 0x30);
        PikachuReward_DrawTextBoxPanel(0xD2, 0x54, 0x50, 0x2C);
        PikachuReward_DrawSelectionCursor(0xDA, (var_s1 * 0x10) + 0x5C);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(2, 0);
        Font_SetLineHeight(0x10);
        Font_Printf(0x2E, 0x28, arg0);

        if (temp_s3 != 0) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        Gfx_SetEnvColor(0xFF, 0xFF, var_a2, 0xFF);
        Font_Printf(0xF2, 0x5C, Text_GetString(NULL, 0, D_83202020, 0x10));

        if (var_s1 == 1) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        Gfx_SetEnvColor(0xFF, 0xFF, var_a2, 0xFF);
        Font_Printf(0xF2, 0x6C, Text_GetString(NULL, 0, D_83202020, 0x11));
        Font_EndTexturedTextRendering();
        BgStage_AdvanceFrame();
    }

    if (temp_s3 != 0) {
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
    } else {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
    return temp_s3;
}

s32 PikachuReward_SelectMoveToForget(char* arg0) {
    s32 var_a2;
    s32 var_s0;
    s32 var_s4;

    var_s4 = 1;
    var_s0 = 0;

    while (var_s4 != 0) {
        Controller_PollInputs();

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            var_s0--;
            if (var_s0 < 0) {
                var_s0 = 3;
            }
        }

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            var_s0++;
            if (var_s0 >= 4) {
                var_s0 = 0;
            }
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            if ((D_832027C8.unk_04.unk_09[var_s0] == 0xF) || (D_832027C8.unk_04.unk_09[var_s0] == 0x13) ||
                (D_832027C8.unk_04.unk_09[var_s0] == 0x46) || (D_832027C8.unk_04.unk_09[var_s0] == 0x94)) {
                Audio_PlaySoundEffectById(SFX_MENU_ERROR);
            } else {
                var_s4 = 0;
                Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
            }
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            var_s4 = 0;
            var_s0 = -1;
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
        }

        PikachuReward_RenderFrame(0);
        PikachuReward_DrawTextBoxPanel(0x1E, 0x20, 0x82, 0x30);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(2, 0);
        Font_SetLineHeight(0x10);
        Font_Printf(0x2E, 0x28, arg0);
        Font_EndTexturedTextRendering();
        PikachuReward_DrawTextBoxPanel(0x96, 0x20, 0x8C, 0x4C);
        PikachuReward_DrawSelectionCursor(0x9E, (var_s0 * 0x10) + 0x28);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(2, 0);
        Font_SetLineHeight(0x10);

        if (var_s0 == 0) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        Gfx_SetEnvColor(0xFF, 0xFF, var_a2, 0xFF);
        Font_Printf(0xB6, 0x28, Text_GetString(NULL, 0, D_8320201C, D_832027C8.unk_04.unk_09[0] - 1));

        if (var_s0 == 1) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        Gfx_SetEnvColor(0xFF, 0xFF, var_a2, 0xFF);
        Font_Printf(0xB6, 0x38, Text_GetString(NULL, 0, D_8320201C, D_832027C8.unk_04.unk_09[1] - 1));

        if (var_s0 == 2) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        Gfx_SetEnvColor(0xFF, 0xFF, var_a2, 0xFF);
        Font_Printf(0xB6, 0x48, Text_GetString(NULL, 0, D_8320201C, D_832027C8.unk_04.unk_09[2] - 1));

        if (var_s0 == 3) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        Gfx_SetEnvColor(0xFF, 0xFF, var_a2, 0xFF);
        Font_Printf(0xB6, 0x58, Text_GetString(NULL, 0, D_8320201C, D_832027C8.unk_04.unk_09[3] - 1));

        Font_EndTexturedTextRendering();
        BgStage_AdvanceFrame();
    }

    return var_s0;
}

void PikachuReward_ShowDeclinedEnding(void) {
    PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 4));
    D_83202028->rotation.y = -0x800;
    ModelAnim_SetAnimation(D_83202028, 5);
    ModelAnim_SetEventTrack(D_83202028, 0);
    D_83201F50 = 1;
    PikachuReward_ShowTextForFrames(Text_GetString(NULL, 0, D_83202020, 4), 0x46);
    StageFade_Start(0x1E);
    Audio_StopMusic(0x3C);
    PikachuReward_ShowTextForFrames(Text_GetString(NULL, 0, D_83202020, 4), 0x1E);
}

void PikachuReward_ShowSuccessEnding(void) {
    ModelAnim_SetAnimation(D_83202028, 0xA);
    ModelAnim_SetEventTrack(D_83202028, 7);
    func_80048060(0, 0x39, 0x19, 0);
    D_83201F50 = 1;
    Audio_PlayMusicIfChanged(0x4A);
    PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 0xF));
    PikachuReward_ShowTextForFrames(Text_GetString(NULL, 0, D_83202020, 0xF), 0x98);
    StageFade_Start(0x1E);
    PikachuReward_ShowTextForFrames(Text_GetString(NULL, 0, D_83202020, 0xF), 0x1E);
}

void PikachuReward_PlayIntroCamera(void) {
    s32 i;
    unk_D_86002F34_00C* temp_s1 = D_83202010->children;

    D_83202028->rotation.y = 0x1000;

    for (i = 0; i < 120; i++) {
        Controller_PollInputs();
        temp_s1->unk_60.at.y = 0x320 - ((i * 0x1E0) / 120);
        temp_s1->unk_60.eye.y = 0x320 - ((i * 0x1E0) / 120);
        D_83202028->rotation.y += 0x200;
        PikachuReward_RenderFrame(0);
        BgStage_AdvanceFrame();
    }
}

s32 PikachuReward_ShowIntroAndConfirm(void) {
    s16 var_s0 = 0x14;
    s16 var_s1 = 0x10;
    s32 i;

    ModelAnim_SetAnimation(D_83202028, 8);

    for (i = 0; i < 8; i++) {
        Controller_PollInputs();
        PikachuReward_RenderFrame(0);
        PikachuReward_DrawTextBoxPanel(0xA0 - (var_s0 / 2), 0x38 - (var_s1 / 2), var_s0, var_s1);
        BgStage_AdvanceFrame();
        var_s0 += 0x1E;
        var_s1 += 4;
    }

    PikachuReward_ShowTextWaitForA(Text_GetString(NULL, 0, D_83202020, 0), 1);
    PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 1));
    PikachuReward_ShowTextWaitForA(Text_GetString(NULL, 0, D_83202020, 1), 1);

    while (true) {
        PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 2));
        if (PikachuReward_ConfirmYesNoPrompt(Text_GetString(NULL, 0, D_83202020, 2)) != 0) {
            return 1;
        }

        PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 3));
        if (PikachuReward_ConfirmYesNoPrompt(Text_GetString(NULL, 0, D_83202020, 3)) != 0) {
            PikachuReward_ShowDeclinedEnding();
            return 0;
        }
    }
}

s32 PikachuReward_ResolveMoveSlot(void) {
    s32 spAC;
    char sp2C[0x80];
    s32 temp_v0;

    temp_v0 = PikachuReward_CountKnownMoves();
    if (temp_v0 == 4) {
        while (true) {
            PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 5));
            PikachuReward_ShowTextWaitForA(Text_GetString(NULL, 0, D_83202020, 5), 1);
            PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 6));
            PikachuReward_ShowTextWaitForA(Text_GetString(NULL, 0, D_83202020, 6), 1);
            PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 7));

            if (PikachuReward_ConfirmYesNoPrompt(Text_GetString(NULL, 0, D_83202020, 7)) != 0) {
                PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 9));

                spAC = PikachuReward_SelectMoveToForget(Text_GetString(NULL, 0, D_83202020, 9));
                if (spAC >= 0) {
                    PikachuReward_ShowTextForFrames(Text_GetString(NULL, 0, D_83202020, 0xA), 0x1E);
                    ModelAnim_SetAnimation(D_83202028, 9);
                    D_83201F54 = 0;
                    func_800479C0(0x85, 0x19, 0);
                    PikachuReward_ShowTextWaitForA(Text_GetString(NULL, 0, D_83202020, 0xB), 1);
                    Text_SetStringToken(0x1D, Text_GetString(NULL, 0, D_8320201C, D_832027C8.unk_04.unk_09[spAC] - 1));
                    Text_GetString(sp2C, sizeof(sp2C), D_83202020, 0xC);
                    Audio_StopMusic(0x3C);
                    PikachuReward_ScrollTextIn(sp2C);
                    PikachuReward_ShowTextWaitForA(sp2C, 1);
                    PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 0xD));
                    PikachuReward_ShowTextWaitForA(Text_GetString(NULL, 0, D_83202020, 0xD), 1);
                    D_83201F54 = -1;
                    return spAC;
                }
            }

            PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 8));

            if (PikachuReward_ConfirmYesNoPrompt(Text_GetString(NULL, 0, D_83202020, 8)) != 0) {
                PikachuReward_ShowDeclinedEnding();
                return -1;
            }
        }
    }

    Audio_StopMusic(0x3C);
    return temp_v0;
}

void PikachuReward_ShowSaveStatusScreen(s32 arg0) {
    PikachuReward_RenderFrame(0);
    PikachuReward_DrawTextBoxPanel(0x1E, 0x20, 0x104, 0x30);

    if (arg0 == 0) {
        PikachuReward_DrawTextBoxPanel(0x4C, 0x64, 0xA8, 0x28);
    } else {
        PikachuReward_DrawTextBoxPanel(0x30, 0x54, 0xE0, 0x78);
    }

    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    Font_SetLineHeight(0x10);
    Font_Printf(0x2E, 0x28, Text_GetString(NULL, 0, D_83202020, 0xE));

    if (arg0 == 0) {
        Font_BeginTranslucentTextRendering();
        Font_SetActive(4, 0);
        Font_Printf(0x5C, 0x70, Text_GetString(NULL, 0, D_83202020, 0x12));
        Font_EndTexturedTextRendering();
    } else {
        Font_SetLineHeight(0x10);
        Font_Printf(0x40, 0x84, Text_GetString(NULL, 0, D_83202020, 0x13));
        Gfx_SetEnvColor(0xFF, 0xFF, 0x64, 0xFF);

        if (arg0 == 2) {
            Font_SetActive(4, 0);
            Font_Printf(0x4C, 0x64, Text_GetString(NULL, 0, D_83202020, 0x14));
        } else if (arg0 == 3) {
            Font_SetLineHeight(0x10);
            Font_Printf(0x40, 0x5C, Text_GetString(NULL, 0, D_83202020, 0x15));
        }
    }

    Font_EndTexturedTextRendering();
    BgStage_AdvanceFrame();
}

void PikachuReward_SaveToCartridge(void) {
    s32 var_s0;
    s32 temp_v0;
    DeckHandle* var_v0;

    if (D_832027C8.unk_01 == 0) {
        var_v0 = Deck_Open(0x20, D_832027C8.unk_00, 0, 2);
    } else {
        var_v0 = Deck_Open(0x21, D_832027C8.unk_00, D_832027C8.unk_01 - 1, 2);
    }

    Deck_SetCursor(var_v0, D_832027C8.unk_02);
    Deck_WriteEntries(&D_832027C8.unk_04, 1, var_v0);
    Deck_CloseAndFlush(var_v0);
    PikachuReward_ShowSaveStatusScreen(0);
    PikachuReward_ShowSaveStatusScreen(0);
    GbSave_ValidateBeforeWrite(D_832027C8.unk_00);

    while (GbSave_RebuildAndWriteSave(D_832027C8.unk_00) == 0) {
        var_s0 = 2;
        do {
            temp_v0 = GbSave_PollCartRemoval(D_832027C8.unk_00);
            if (temp_v0 == 1) {
                var_s0 = 1;
            }

            if (temp_v0 == 3) {
                var_s0 = 3;
            }

            PikachuReward_ShowSaveStatusScreen(var_s0);
        } while (temp_v0 != 2);

        PikachuReward_ShowSaveStatusScreen(0);
        PikachuReward_ShowSaveStatusScreen(0);
    }
    GbSave_RequirePakPresent(D_832027C8.unk_00);
}

void PikachuReward_TeachSurfToPikachu(s32 arg0) {
    s32 i;

    Cry_Play(0x19, 0);
    PikachuReward_ScrollTextIn(Text_GetString(NULL, 0, D_83202020, 0xE));
    PikachuReward_ShowTextForFrames(Text_GetString(NULL, 0, D_83202020, 0xE), 1);

    for (i = PikachuReward_CountKnownMoves(); i < 4; i++) {
        D_832027C8.unk_04.unk_09[i] = 0;
        D_832027C8.unk_04.unk_20[i] = 0;
    }

    D_832027C8.unk_04.unk_09[arg0] = 0x39;
    D_832027C8.unk_04.unk_20[arg0] = gMoveData[0x38].unk_05;

    PikachuReward_SaveToCartridge();
    PikachuReward_ShowTextWaitForA(Text_GetString(NULL, 0, D_83202020, 0xE), 1);
    PikachuReward_ShowSuccessEnding();
}

void PikachuReward_RunSequence(void) {
    s32 temp_v0;

    Audio_PlayMusicIfChanged(0x49);
    StageLoader_RunFrames(2);
    StageFade_Start(0x28);
    BgStage_RunUntilCondition(0xA, PikachuReward_RenderFrame);
    PikachuReward_PlayIntroCamera();
    if (PikachuReward_ShowIntroAndConfirm() != 0) {
        temp_v0 = PikachuReward_ResolveMoveSlot();
        if (temp_v0 >= 0) {
            PikachuReward_TeachSurfToPikachu(temp_v0);
        }
    }
    StageLoader_RunFrames(2);
}

void PikachuReward_SetupFollowerModel(DisplayObject* arg0, s16 arg1, s16 arg2, s16 arg3) {
    Model_InitDisplayObject(arg0, 0, 0, D_83202014);
    ModelAnim_BindTransformCurve(arg0, 0, D_8C2011C4, 0x10000);
    arg0->node.flags &= ~1;
    Vec3f_SetComponentsDuplicate(&arg0->scale, 1.5f, 1.5f, 1.5f);
    arg0->position.x = arg1;
    arg0->position.y = arg2;
    arg0->rotation.z = arg3;
}

void PikachuReward_SetupScene(void) {
    MemoryBlock* temp_v0;
    s32 i;

    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    D_83202010 = process_geo_layout(temp_v0, D_83201F5C);
    D_83202014 = process_geo_layout(temp_v0, D_8C201070);

    MainPool_FinalizeAllocation(temp_v0);
    ModelRenderer_InitDisplayRoots();

    for (i = 0; i < 4; i++) {
        ModelRenderer_AttachDisplayObject(&D_83202028[i]);
    }

    Model_InitDisplayObject(&D_83202028[0], 0, 0, D_83202018->unk_08->unk_00[0]);
    Vec3f_SetComponentsDuplicate(&D_83202028[0].scale, 16.0f, 16.0f, 16.0f);
    ModelAnim_SetAnimation(&D_83202028[0], 0);
    D_83202028->node.renderFlags &= ~0x40;
    PikachuReward_SetupFollowerModel(&D_83202028[1], -0x50, 0x17C, 0x1800);
    PikachuReward_SetupFollowerModel(&D_83202028[2], 0, 0x17C, 0);
    PikachuReward_SetupFollowerModel(&D_83202028[3], 0x50, 0x17C, -0x1800);
}

s32 Stadium_BonusPikachuReward(UNUSED s32 arg0, UNUSED s32 arg1) {
    UNUSED s32 pad;
    unk_func_80007444* sp20;

    main_pool_push_state('PIKA');

    if (PikachuReward_FindPikachuOnCart() != 0) {
        Gfx_InitDisplayListBuffers(0x10000, 0);
        sp20 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
        Font_Init(6, 0);

        FRAGMENT_LOAD(fragment31);
        Fragment_Load(FRAGMENT_ID(_798CD0), _798CD0_ROM_START, _798CD0_ROM_END);
        ASSET_LOAD(D_1000000, common_menu1_ui, 0);

        Text_InitStringTables();
        D_8320201C = Text_GetStringTable(0x25);
        D_83202020 = Text_GetStringTable(0x1C);
        PokeIcon_OpenModelArchives();
        D_83202018 = Model_LoadForPokemon(&D_832027C8.unk_04);
        PikachuReward_SetupScene();
        StageContext_Activate(sp20);
        PikachuReward_RunSequence();
        StageContext_Deactivate();
        Font_Free();
        Gfx_FreeDisplayListBuffers();
    }

    main_pool_pop_state('PIKA');
    return 0;
}
