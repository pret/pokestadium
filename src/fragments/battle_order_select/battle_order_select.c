#include "battle_order_select.h"
#include "src/geo_render.h"
#include "src/poke_icon.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/ui_graphics.h"
#include "src/status_icons.h"
#include "src/pokemon_stats.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/gfx_buffer.h"
#include "src/DDC0.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static unk_D_84803760 D_84803760[2];
static BinArchive* D_84803780;
static void* D_84803784;
static char** D_84803788;
static char** D_8480378C;
static char** D_84803790;
static char** D_84803794;
static s16 D_84803798;
static s16 D_8480379A;
static s32 D_8480379C;
static unk_D_848037A0 D_848037A0[4];
static SessionContext* D_84816420;
static Controller D_84816428;
static s32 D_8481644C;
static s32 D_84816450;
static s16 D_84816458[4];

static u16 D_84803540[] = { 0x1D, 0x341, 0x6947, 0x6A41 };
static unk_D_84803548 D_84803548[] = {
    { 0x001E, 0x0000 },
    { 0x001E, 0x4000 },
    { 0x0001, 0x8000 },
    { 0x0000, 0x0000 },
};
static unk_D_84803548 D_84803558[] = {
    { 0x001E, 0x0000 }, { 0x000A, 0x4000 }, { 0x001E, 0x0002 }, { 0x0001, 0x8000 }, { 0x0000, 0x0000 },
};
static unk_D_84803548 D_8480356C[] = {
    { 0x001E, 0x0000 }, { 0x000A, 0x4000 }, { 0x000A, 0x0002 },
    { 0x001E, 0x0008 }, { 0x0001, 0x8000 }, { 0x0000, 0x0000 },
};
static unk_D_84803548 D_84803584[] = {
    { 0x001E, 0x0000 }, { 0x000A, 0x4000 }, { 0x000A, 0x0002 }, { 0x000A, 0x0008 },
    { 0x001E, 0x8000 }, { 0x0001, 0x8000 }, { 0x0000, 0x0000 },
};
static unk_D_84803548 D_848035A0[] = {
    { 0x001E, 0x0000 }, { 0x000A, 0x4000 }, { 0x000A, 0x0002 }, { 0x000A, 0x0008 },
    { 0x000A, 0x8000 }, { 0x001E, 0x0004 }, { 0x0001, 0x8000 }, { 0x0000, 0x0000 },
};
static unk_D_84803548 D_848035C0[] = {
    { 0x001E, 0x0000 }, { 0x000A, 0x4000 }, { 0x000A, 0x0002 }, { 0x000A, 0x0008 },
    { 0x000A, 0x8000 }, { 0x000A, 0x0004 }, { 0x001E, 0x0001 }, { 0x0001, 0x8000 },
};
static unk_D_84803548* D_848035E0[] = {
    NULL, D_84803548, D_84803558, D_8480356C, D_84803584, D_848035A0, D_848035C0,
};
static unk_D_848035FC D_848035FC[] = {
    { { 0xF0, 0xF0, 0xF0 }, D_2017740 }, { { 0xF0, 0x96, 0x32 }, D_2019040 }, { { 0x50, 0x96, 0xF0 }, D_20199A0 },
    { { 0xC8, 0x96, 0xF0 }, D_2019680 }, { { 0xF0, 0xC8, 0x78 }, D_2018D20 }, { { 0x64, 0xB4, 0xB4 }, D_2018A00 },
    { { 0x50, 0x96, 0xF0 }, D_20199A0 }, { { 0xC8, 0xF0, 0x50 }, D_2019360 }, { { 0xDC, 0xC8, 0xF0 }, D_2019FE0 },
    { { 0xF0, 0x64, 0x64 }, D_2017A60 }, { { 0x46, 0xB4, 0xF0 }, D_2017D80 }, { { 0x64, 0xC8, 0x64 }, D_20183C0 },
    { { 0xF0, 0xF0, 0x32 }, D_20186E0 }, { { 0xF0, 0x8C, 0xB4 }, D_2019CC0 }, { { 0xB4, 0xF0, 0xF0 }, D_20180A0 },
    { { 0x64, 0xDC, 0xC8 }, D_201A300 },
};
static Color_RGB8 D_8480367C = { 0x00, 0x0A, 0x41 };
static Color_RGB8 D_84803680 = { 0x00, 0x00, 0xD2 };
static u8* D_84803684[] = { D_3008FD0, D_3009720, D_3009E70 };
static u8* D_84803690[] = { D_300A5C0, D_300AD10 };
static u8* D_84803698[] = { D_300B9B8 };
static u8* D_8480369C[][3] = {
    {
        D_300C660,
        D_300D308,
        D_300DFB0,
    },
    {
        D_300EC58,
        D_3005B80,
        D_3005F40,
    },
    {
        D_3006300,
        D_30066C0,
        D_3006A80,
    },
    {
        D_3006E40,
        D_3007200,
        D_30075C0,
    },
    {
        D_3007980,
        D_3007D40,
        D_3008100,
    },
};
static u8* D_848036D8 = D_30084C0;

void BattleMenu_DrawBottomActionButtons(void) {
    Gfx_DrawTiledRgba16Image(D_84803784);

    gSPDisplayList(gDisplayListHead++, D_8006F4E0);

    Gfx_DrawTextureRgba16(0x71, 0x1A8, 0x20, 0x18, D_3002220, 0x20, 0x200000);
    Gfx_DrawTextureRgba16(0x162, 0x1A8, 0x20, 0x18, D_3002820, 0x20, 0x200000);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
    Font_Printf(0x5A, 0x1AA, "*");
    Font_Printf(0x149, 0x1AA, "*");
    Font_Printf(0x91, 0x1A8, Text_GetString(NULL, 0, D_84803790, 2));
    Font_Printf(0x180, 0x1A8, Text_GetString(NULL, 0, D_84803790, 3));
    Font_EndTexturedTextRendering();
}

void BattleMenu_DrawScrollingRulesText(void) {
    s32 i;
    s32 var_s2;
    s32 var_s4;
    s8 temp_v0;
    s8* var_v0;
    unk_D_80068BB0* sp58;
    Color_RGB8 sp54;
    Color_RGB8 sp50;

    var_s4 = 0x30 - (D_8480379A % 24);
    var_s2 = D_8480379A / 24;
    sp58 = StageContext_GetCurrentImage();
    sp54 = D_8480367C;
    sp50 = D_84803680;
    Ui_DrawGradientPanel(0x228, 0x20, 0x2E, 0x186, &sp54, &sp50);

    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 563, 48, 587, 408);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0xA5, 0xDE, 0x8C, 0xFF);

    if ((D_84816420->unk_0001 == 0) || (D_84816420->unk_0001 == 8)) {
        var_v0 = Text_GetString(NULL, 0, D_84803790, 1);
    } else {
        var_v0 = Text_GetString(NULL, 0, D_84803790, 0);
    }

    for (i = 0; i < 16; i++) {
        Font_DrawCharAt(((0x2E - Font_GetCharWidth(0x10, var_v0[var_s2])) / 2) + 0x228, var_s4, var_v0[var_s2]);
        var_s2 += 1;
        if (strlen(var_v0) < var_s2) {
            var_s2 = 0;
        }
        var_s4 += 0x18;
    }
    Font_EndTexturedTextRendering();

    gDPSetScissorFrac(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, sp58->width * 4.0f, sp58->height * 4.0f);

    D_8480379A += 2;
    if (D_8480379A >= ((strlen(var_v0) * 0x18) + 0x18)) {
        D_8480379A = 0;
    }
}

void BattleMenu_InitTeamOrderState(unk_D_84803760* arg0, BattleSessionTeams* arg1, s32 arg2) {
    s32 i;

    arg0->unk_00 = 0;
    arg0->unk_01 = 0;

    for (i = 0; i < 6; i++) {
        arg0->unk_02[i] = 0;
        arg0->unk_08[i] = 1;
    }

    if (arg2 != 0) {
        if (arg2 != 8) {
            // clang-format off
            for (i = 3; i < 6; i++) { arg0->unk_02[i] = -1; }
            // clang-format on
        }
    }

    if (arg1->unk_01 == 1) {
        arg0->unk_0E = arg1->unk_08[0]->unk_001;
        arg0->unk_0F = -1;
        arg0->unk_01 = (arg1->unk_08[0]->unk_000 & 2) != 0;
    } else if (arg1->unk_08[0]->unk_001 < arg1->unk_08[1]->unk_001) {
        arg0->unk_0E = arg1->unk_08[0]->unk_001;
        arg0->unk_0F = arg1->unk_08[1]->unk_001;
    } else {
        arg0->unk_0E = arg1->unk_08[1]->unk_001;
        arg0->unk_0F = arg1->unk_08[0]->unk_001;
    }
}

void BattleMenu_DrawSidebarLeadIcon(s32 arg0, s32 arg1, unk_D_84803760* arg2) {
    u8* sp2C;

    if (arg2->unk_0F == -1) {
        if (arg2->unk_01 != 0) {
            Gfx_DrawTextureRgba16(arg0, arg1, 0x24, 0x1A, D_3008880, 0x24, 0x200000);
        } else {
            Gfx_DrawTextureRgba16(arg0, arg1, 0x24, 0x1A, D_84803684[arg2->unk_0E], 0x24, 0x200000);
        }
    } else {
        switch (arg2->unk_0E) {
            case 0:
                sp2C = D_84803690[arg2->unk_0F];
                break;

            case 1:
                sp2C = D_84803698[arg2->unk_0F];
                break;

            case 2:
                sp2C = D_8480369C[0][arg2->unk_0F];
                break;
        }
        Gfx_DrawTextureRgba16(arg0, arg1, 0x24, 0x2D, sp2C, 0x24, 0x200000);
    }
}

s32 BattleMenu_DrawSidebarRowTypeIcon(s32 arg0, s32 arg1, s8 arg2, s8 arg3) {
    s32 sp34;
    s32 sp30;

    if (arg2 != 0) {
        if (arg2 == -1) {
            Gfx_DrawTextureRgba16(arg0, arg1, 0x20, 0x14, D_3005680, 0x20, 0x200000);
        } else {
            sp34 = (arg2 >> 4) & 0xF;
            sp30 = arg2 & 0xF;

            if (arg3 > 0) {
                if (sp30 < 3) {
                    sp30++;
                }
            } else if (sp30 > 0) {
                sp30--;
            }

            if (sp30 > 0) {
                Gfx_DrawTextureRgba16(arg0 + 6, arg1, 0x18, 0x14, D_8480369C[sp34][sp30], 0x18, 0x200000);
                arg2 = (sp34 * 0x10) | sp30;
            } else {
                arg2 = 0;
            }
        }
    }
    return arg2;
}

void BattleMenu_DrawTeamOrderSidebarTeam0(void) {
    unk_D_84803760* temp_v0 = &D_84803760[0];
    s32 i;
    s16 var_s2;
    s32 var_s1;

    if (temp_v0->unk_0F == -1) {
        var_s2 = 0x3F;
    } else {
        var_s2 = 0x4A;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F4E0);

    Gfx_DrawTextureRgba16(0x2D, var_s2, 0x20, 0xC, D_3003C80, 0x20, 0x200000);
    Gfx_DrawTextureRgba16(0x2D, var_s2 + 0xC, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    Gfx_DrawTextureRgba16(0x2D, var_s2 + 0x23, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    Gfx_DrawTextureRgba16(0x2D, var_s2 + 0x3A, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    Gfx_DrawTextureRgba16(0x2D, var_s2 + 0x51, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    Gfx_DrawTextureRgba16(0x25, var_s2 + 0x68, 0x28, 0x2E, D_3002E20, 0x28, 0x200000);

    if (temp_v0->unk_0F == -1) {
        BattleMenu_DrawSidebarLeadIcon(0x2D, 0x21, &D_84803760[0]);
    } else {
        BattleMenu_DrawSidebarLeadIcon(0x2D, 0x1D, &D_84803760[0]);
    }

    var_s1 = var_s2 + 0x76;
    for (i = 0; i < 6; i++) {
        temp_v0->unk_02[i] = BattleMenu_DrawSidebarRowTypeIcon(0x2D, var_s1 - i * 0x17, temp_v0->unk_02[i], temp_v0->unk_08[i]);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void BattleMenu_DrawTeamOrderSidebarTeam1(void) {
    unk_D_84803760* temp_v0 = &D_84803760[1];
    s32 i;
    s16 var_s2;
    s32 var_s1;

    if (temp_v0->unk_0F == -1) {
        var_s2 = 0xF1;
    } else {
        var_s2 = 0xE6;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F4E0);

    Gfx_DrawTextureRgba16(0x2D, var_s2, 0x28, 0x2C, D_3003F80, 0x28, 0x200000);
    Gfx_DrawTextureRgba16(0x2D, var_s2 + 0x2C, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    Gfx_DrawTextureRgba16(0x2D, var_s2 + 0x43, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    Gfx_DrawTextureRgba16(0x2D, var_s2 + 0x5A, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    Gfx_DrawTextureRgba16(0x2D, var_s2 + 0x71, 0x20, 0x17, D_30050C0, 0x20, 0x200000);
    Gfx_DrawTextureRgba16(0x2D, var_s2 + 0x88, 0x20, 0xE, D_3004D40, 0x20, 0x200000);

    if (temp_v0->unk_0F == -1) {
        BattleMenu_DrawSidebarLeadIcon(0x2D, 0x189, &D_84803760[1]);
    } else {
        BattleMenu_DrawSidebarLeadIcon(0x2D, 0x17C, &D_84803760[1]);
    }

    var_s1 = var_s2 + 0xC;
    for (i = 0; i < 6; i++) {
        temp_v0->unk_02[i] = BattleMenu_DrawSidebarRowTypeIcon(0x2D, var_s1 + i * 0x17, temp_v0->unk_02[i], temp_v0->unk_08[i]);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void BattleMenu_AppendOrderSlotIcon(s32 arg0, s32 arg1) {
    unk_D_84803760* temp_v0 = &D_84803760[arg0];

    temp_v0->unk_02[temp_v0->unk_00] = ((arg1 + 1) << 4) | (temp_v0->unk_02[temp_v0->unk_00] & 0xF);
    temp_v0->unk_08[temp_v0->unk_00] = 1;
    temp_v0->unk_00++;
}

void BattleMenu_ResetOrderSlotIcons(s32 arg0) {
    unk_D_84803760* ptr = &D_84803760[arg0];
    s32 i;

    for (i = 0; i < 6; i++) {
        ptr->unk_08[i] = -1;
    }
    ptr->unk_00 = 0;
}

void BattleMenu_DrawBorderedPanel(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    Ui_DrawBorderedPanelStyleB(arg0, arg1, arg2, arg3, D_84803540[arg4]);
}

void BattleMenu_DrawOrderSelectPanel_PartyGrid(unk_D_848037A0* arg0) {
    s32 i;
    s16 temp_s7;
    s16 temp_fp;
    s32 temp_s1_2;
    s32 temp_s2_3;
    s32 temp_v0_4;

    temp_s7 = arg0->unk_0012;
    temp_fp = arg0->unk_0014;

    BattleMenu_DrawBorderedPanel(temp_s7, temp_fp, 0x1D7, 0x5E, arg0->unk_0001);

    gSPDisplayList(gDisplayListHead++, D_8006F4E0);

    Gfx_DrawTextureRgba16(temp_s7 + 7, temp_fp + 0xB, 0x1A, 0x1A, &D_30005B0, 0x1C, 0x200000);
    Gfx_DrawTextureRgba16(temp_s7 + 0xA1, temp_fp + 0xB, 0x1A, 0x1A, &D_3001110, 0x1C, 0x200000);
    Gfx_DrawTextureRgba16(temp_s7 + 0x13B, temp_fp + 0xB, 0x1A, 0x1A, &D_3001C70, 0x1C, 0x200000);
    Gfx_DrawTextureRgba16(temp_s7 + 7, temp_fp + 0x35, 0x1A, 0x1A, D_3000000, 0x1C, 0x200000);
    Gfx_DrawTextureRgba16(temp_s7 + 0xA1, temp_fp + 0x35, 0x1A, 0x1A, &D_3000B60, 0x1C, 0x200000);
    Gfx_DrawTextureRgba16(temp_s7 + 0x13B, temp_fp + 0x35, 0x1A, 0x1A, &D_30016C0, 0x1C, 0x200000);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(temp_s7 + 0x23, temp_fp + 6, 0x28, 0x28, arg0->unk_0020[0], 0x28, 0);
    Gfx_DrawTextureRgba16(temp_s7 + 0xBD, temp_fp + 6, 0x28, 0x28, arg0->unk0CA0, 0x28, 0);
    Gfx_DrawTextureRgba16(temp_s7 + 0x157, temp_fp + 6, 0x28, 0x28, &arg0->unk0CA0[0xC80], 0x28, 0);
    Gfx_DrawTextureRgba16(temp_s7 + 0x23, temp_fp + 0x30, 0x28, 0x28, &arg0->unk0CA0[0x1900], 0x28, 0);
    Gfx_DrawTextureRgba16(temp_s7 + 0xBD, temp_fp + 0x30, 0x28, 0x28, &arg0->unk0CA0[0x2580], 0x28, 0);
    Gfx_DrawTextureRgba16(temp_s7 + 0x157, temp_fp + 0x30, 0x28, 0x28, &arg0->unk0CA0[0x3200], 0x28, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);

    for (i = 0; i < arg0->unk_0017; i++) {
        temp_v0_4 = BattleMenu_IsSlotAlreadySelected(arg0, i);
        if ((arg0->unk_0009 != 0) && (temp_v0_4 != 0)) {
            Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
        }
        temp_s1_2 = temp_s7 + ((i % 3) * 0x9A) + 0x4C;
        temp_s2_3 = temp_fp + ((i / 3) * 0x2A) + 8;
        Font_Printf(temp_s1_2, temp_s2_3, arg0->unk_0018[i].unk_30);
        if ((arg0->unk_0009 != 0) && (temp_v0_4 != 0)) {
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        }
        Font_Printf(temp_s1_2, temp_s2_3 + 0x14, "%s%d", Text_GetString(NULL, 0, D_84803794, 0x15),
                      arg0->unk_0018[i].unk_24);
    }

    Font_EndTexturedTextRendering();

    if (arg0->unk_0007 > 0) {
        if (arg0->unk_0003 == 0) {
            Gfx_DrawRgba16ImageRegion(D_84803784, 0xC8, 0x81, 0x15F, 0x53);
        } else {
            Gfx_DrawRgba16ImageRegion(D_84803784, 0x50, 0xF0, 0x15F, 0x53);
        }
        arg0->unk_0007 -= 1;
    }
}

void BattleMenu_DrawCursorArrow(s16 arg0, s16 arg1, s16 arg2) {
    if (D_84816458[arg2] < 6) {
        arg0 += D_84816458[arg2];
    } else {
        arg0 = (arg0 - D_84816458[arg2]) + 0xC;
    }
    Ui_DrawTextureMarker(arg0, arg1);
    D_84816458[arg2] = (D_84816458[arg2] + 1) % 12;
}

void BattleMenu_DrawOrderSelectPanel_ConfirmPrompt(unk_D_848037A0* arg0) {
    s32 sp38;
    s16 var_s1;
    s16 var_s2;

    if (arg0->unk_0002 == -1) {
        if (arg0->unk_0003 == 0) {
            var_s1 = 0xC8;
            var_s2 = 0x81;
        } else {
            var_s1 = 0x50;
            var_s2 = 0xF0;
        }

        BattleMenu_DrawOrderSelectPanel_PartyGrid(arg0);
        BattleMenu_DrawBorderedPanel(var_s1, var_s2, 0x15F, 0x53, arg0->unk_0001);

        if (arg0->unk_000A == 0) {
            BattleMenu_DrawCursorArrow(var_s1 + 0x26, var_s2 + 0x30, arg0->unk_0000);
        } else {
            BattleMenu_DrawCursorArrow(var_s1 + 0x86, var_s2 + 0x30, arg0->unk_0000);
        }

        Font_BeginTranslucentTextRendering();
        Font_SetActive(0x10, 0);
        Font_Printf(var_s1 + 0x1F, var_s2 + 0xB, Text_GetString(NULL, 0, D_84803790, 4));
        Font_Printf(var_s1 + 0x4F, var_s2 + 0x30, Text_GetString(NULL, 0, D_84803790, 5));
        Font_Printf(var_s1 + 0xAF, var_s2 + 0x30, Text_GetString(NULL, 0, D_84803790, 6));
        Font_EndTexturedTextRendering();
        arg0->unk_0007 = 2;
    } else {
        var_s1 = arg0->unk_0012;
        var_s2 = arg0->unk_0014;

        BattleMenu_DrawOrderSelectPanel_PartyGrid(arg0);
        Gfx_FillRectWithDisplayState(var_s1 + 5, var_s2 + 5, 0x1CD, 0x54, 0, 0, 0, 0x80);
        if (arg0->unk_000A == 0) {
            BattleMenu_DrawCursorArrow(var_s1 + 0x5C, var_s2 + 0x3C, arg0->unk_0000);
        } else {
            BattleMenu_DrawCursorArrow(var_s1 + 0xBC, var_s2 + 0x3C, arg0->unk_0000);
        }
        Font_BeginTranslucentTextRendering();
        Font_SetActive(0x10, 0);
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        Font_Printf(var_s1 + 0x50, var_s2 + 0x14, Text_GetString(NULL, 0, D_84803790, 4));
        Font_Printf(var_s1 + 0x80, var_s2 + 0x3C, Text_GetString(NULL, 0, D_84803790, 5));
        Font_Printf(var_s1 + 0xE0, var_s2 + 0x3C, Text_GetString(NULL, 0, D_84803790, 6));
        Font_EndTexturedTextRendering();
    }
}

void BattleMenu_DrawOrderSelectPanel_LevelCapNotice(unk_D_848037A0* arg0) {
    char sp38[0x100];
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    switch (D_84816420->unk_0001) {
        case 3:
            sp2C = 0x9B;
            break;

        case 4:
            sp2C = 0x50;
            break;

        case 5:
            sp2C = 0x32;
            break;
    }

    if (arg0->unk_0002 == -1) {
        // clang-format off
        if (arg0->unk_0003 == 0) {
            sp34 = 0xC8; sp30 = 0x81;
        } else {
            sp34 = 0x50; sp30 = 0xF0;
        }
        // clang-format on

        BattleMenu_DrawBorderedPanel(sp34, sp30, 0x15F, 0x53, arg0->unk_0001);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(0x10, 0);
        Gfx_SetEnvColor(0xFF, 0x63, 0x63, 0xFF);
        Font_SetLineHeight(0x25);
        Text_SetNumberToken(3, sp2C);
        Font_Printf(sp34 + 0x10, sp30 + 0xB, Text_GetString(sp38, sizeof(sp38), D_84803790, 7));
        Font_EndTexturedTextRendering();
        arg0->unk_0007 = 2;
    } else {
        sp34 = arg0->unk_0012;
        sp30 = arg0->unk_0014;

        BattleMenu_DrawOrderSelectPanel_PartyGrid(arg0);
        Gfx_FillRectWithDisplayState(sp34 + 5, sp30 + 5, 0x1CD, 0x54, 0, 0, 0, 0x80);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(0x10, 0);
        Gfx_SetEnvColor(0xFF, 0x63, 0x63, 0xFF);
        Font_SetLineHeight(0x28);
        Text_SetNumberToken(3, sp2C);
        Font_Printf(sp34 + 0x50, sp30 + 0x14, Text_GetString(NULL, 0, D_84803790, 7));
        Font_EndTexturedTextRendering();
    }
}

void BattleMenu_DrawOrderSelectPanel_Ready(unk_D_848037A0* arg0) {
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    char* temp_v0;

    if (arg0->unk_0002 == -1) {
        // clang-format off
        if (arg0->unk_0003 == 0) {
            sp3C = 0xC8; sp38 = 0x81;
        } else {
            sp3C = 0x50; sp38 = 0xF0;
        }
        // clang-format on
        arg0->unk_0007 = 0;
        BattleMenu_DrawOrderSelectPanel_PartyGrid(arg0);
        BattleMenu_DrawBorderedPanel(sp3C, sp38, 0x15F, 0x53, arg0->unk_0001);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(0x20, 0);
        Font_EnableTwoCycleTexturing();
        Gfx_SetPrimColor(0x1C, 0x74, 0xFF, 0xFF);
        temp_v0 = Text_GetString(NULL, 0, D_84803790, 8);
        Font_Printf((sp3C - (Font_MeasureTextExtent(0x20, 0, temp_v0) / 2)) + 0xAF, sp38 + 0x19, temp_v0);
        Font_DisableTwoCycleTexturing();
        Font_EndTexturedTextRendering();
    } else {
        sp3C = arg0->unk_0012;
        sp38 = arg0->unk_0014;

        if (arg0->unk_0008 < 0x10) {
            sp34 = arg0->unk_0008 * 0x10;
        } else if (arg0->unk_0008 < 0x23) {
            sp34 = 0xFF;
        } else if (arg0->unk_0008 < 0x32) {
            sp34 = (-arg0->unk_0008 * 0x10) + 0x320;
        } else {
            sp34 = 0;
        }

        arg0->unk_0008++;
        if (arg0->unk_0008 >= 0x3D) {
            arg0->unk_0008 = 0;
        }

        BattleMenu_DrawOrderSelectPanel_PartyGrid(arg0);
        Gfx_FillRectWithDisplayState(sp3C + 5, sp38 + 5, 0x1CD, 0x54, 0, 0, 0, 0x80);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(0x20, 0);
        Font_EnableTwoCycleTexturing();
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, sp34);
        Gfx_SetPrimColor(0x1C, 0x74, 0xFF, sp34);
        temp_v0 = Text_GetString(NULL, 0, D_84803790, 8);
        Font_Printf((sp3C - (Font_MeasureTextExtent(0x20, 0, temp_v0) / 2)) + 0xEB, sp38 + 0x25, temp_v0);
        Font_DisableTwoCycleTexturing();
        Font_EndTexturedTextRendering();
    }
}

void BattleMenu_DrawOrderSelectPanel_MonDetail(unk_D_848037A0* arg0) {
    s32 i;
    s16 temp_fp;
    s8 temp_s1;
    unk_D_848035FC* temp_v1;
    s32 idx;
    s32 sp7C;
    BattleMon* sp78;

    temp_fp = arg0->unk_0012;
    temp_s1 = arg0->unk_0016;
    sp7C = arg0->unk_0014;
    sp78 = &arg0->unk_0018[temp_s1];

    BattleMenu_DrawBorderedPanel(temp_fp, sp7C, 0x1D7, 0x5E, arg0->unk_0001);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(temp_fp + 8, sp7C + 7, 0x28, 0x28, &arg0->unk_0020[temp_s1], 0x28, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);
    Font_Printf(temp_fp + 0x32, sp7C + 7, arg0->unk_0018[temp_s1].unk_30);
    Font_Printf(temp_fp + 0x32, sp7C + 0x1B, "%s", Text_GetString(NULL, 0, D_84803794, 8));
    Font_Printf(temp_fp + 0xBE, sp7C + 7, Text_GetString(NULL, 0, D_84803790, 9));
    Font_Printf(temp_fp + 0xBE, sp7C + 0x1B, Text_GetString(NULL, 0, D_84803790, 0xA));
    Font_Printf(temp_fp + 0xBE, sp7C + 0x2F, Text_GetString(NULL, 0, D_84803790, 0xB));
    Font_Printf(temp_fp + 0xBE, sp7C + 0x43, Text_GetString(NULL, 0, D_84803790, 0xC));
    Font_Printf(temp_fp + 0x32, sp7C + 0x2F, Text_GetString(NULL, 0, D_84803790, 0xD));

    if (sp78->unk_06 != sp78->unk_07) {
        Font_Printf(temp_fp + 0x32, sp7C + 0x43, Text_GetString(NULL, 0, D_84803790, 0xE));
    }

    idx = PokemonType_ToDisplayIndex(sp78->unk_06);
    Gfx_SetEnvColor(D_848035FC[idx].unk_00.r, D_848035FC[idx].unk_00.g, D_848035FC[idx].unk_00.b, 0xFF);
    Font_Printf(temp_fp + 0x7A, sp7C + 0x2F, Text_GetString(NULL, 0, D_8480378C, PokemonType_ToDisplayIndex(sp78->unk_06)));

    if (sp78->unk_06 != sp78->unk_07) {
        idx = PokemonType_ToDisplayIndex(sp78->unk_07);
        Gfx_SetEnvColor(D_848035FC[idx].unk_00.r, D_848035FC[idx].unk_00.g, D_848035FC[idx].unk_00.b, 0xFF);
        Font_Printf(temp_fp + 0x7A, sp7C + 0x43, Text_GetString(NULL, 0, D_8480378C, PokemonType_ToDisplayIndex(sp78->unk_07)));
    }

    Font_SetActive(4, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    Font_Printf(temp_fp + 0x8C, sp7C + 7, "%s%d", Text_GetString(NULL, 0, D_84803794, 0x15),
                  arg0->unk_0018[temp_s1].unk_24);
    Font_Printf(temp_fp + 0x52, sp7C + 0x1B, "%3d", sp78->unk_26);
    Font_Printf(temp_fp + 0xFA, sp7C + 7, "%3d", sp78->unk_28);
    Font_Printf(temp_fp + 0xFA, sp7C + 0x1B, "%3d", sp78->unk_2A);
    Font_Printf(temp_fp + 0xFA, sp7C + 0x2F, "%3d", sp78->unk_2C);
    Font_Printf(temp_fp + 0xFA, sp7C + 0x43, "%3d", sp78->unk_2E);

    for (i = 0; i < 4; i++) {
        if (sp78->unk_09[i] == 0) {
            break;
        }
        temp_v1 = &D_848035FC[gMoveDisplayInfo[sp78->unk_09[i] - 1].unk_01];
        Font_SetActive(4, 0);
        Gfx_SetEnvColor(temp_v1->unk_00.r, temp_v1->unk_00.g, temp_v1->unk_00.b, 0xFF);
        Font_Printf(temp_fp + 0x14C, (i * 0x14) + sp7C + 7, Text_GetString(NULL, 0, D_84803788, sp78->unk_09[i] - 1));
        Font_SetActive(4, 0);
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        Font_Printf(temp_fp + 0x1B3, (i * 0x14) + sp7C + 7, "%2d", sp78->unk_20[i] & 0x3F);
    }

    Font_EndTexturedTextRendering();

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 4; i++) {
        if (sp78->unk_09[i] == 0) {
            break;
        }
        Gfx_DrawTextureRgba16(temp_fp + 0x136, (i * 0x14) + sp7C + 7, 0x14, 0x14,
                      D_848035FC[gMoveDisplayInfo[sp78->unk_09[i] - 1].unk_01].unk_04, 0x14, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    if (arg0->unk_0007 > 0) {
        if (arg0->unk_0003 == 0) {
            Gfx_DrawRgba16ImageRegion(D_84803784, 0xC8, 0x81, 0x15F, 0x53);
        } else {
            Gfx_DrawRgba16ImageRegion(D_84803784, 0x50, 0xF0, 0x15F, 0x53);
        }
        arg0->unk_0007--;
    }
}

void BattleMenu_DrawConfirmButtonLabel(unk_D_848037A0* arg0) {
    s16 sp26;
    s16 sp24;

    if (arg0->unk_0003 == 0) {
        // clang-format off
        sp26 = 0x50; sp24 = 0x81;
        // clang-format on
    } else {
        sp26 = 0x1B1;
        sp24 = 0x123;
    }

    BattleMenu_DrawBorderedPanel(sp26, sp24, 0x76, 0x20, arg0->unk_0001);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
    Font_Printf((sp26 - (Font_MeasureTextExtent(8, 0, arg0->unk_001C->unk_008) / 2)) + 0x3B, sp24 + 5,
                  arg0->unk_001C->unk_008);
    Font_EndTexturedTextRendering();
}

void BattleMenu_DrawOrderSelectPanel(unk_D_848037A0* arg0) {
    if ((D_84803798 != 0) || (arg0->unk_0006 != 0)) {
        if ((D_84803798 != 0) && (arg0->unk_0002 == -1)) {
            BattleMenu_DrawConfirmButtonLabel(arg0);
        }

        switch (arg0->unk_0005) {
            case 0:
                BattleMenu_DrawOrderSelectPanel_PartyGrid(arg0);
                break;

            case 1:
                BattleMenu_DrawOrderSelectPanel_ConfirmPrompt(arg0);
                break;

            case 2:
                BattleMenu_DrawOrderSelectPanel_LevelCapNotice(arg0);
                break;

            case 3:
                BattleMenu_DrawOrderSelectPanel_Ready(arg0);
                break;

            case 4:
                BattleMenu_DrawOrderSelectPanel_MonDetail(arg0);
                break;
        }

        if (arg0->unk_0006 != 0) {
            arg0->unk_0006--;
        }
    } else if (arg0->unk_0005 == 3) {
        BattleMenu_DrawOrderSelectPanel_Ready(arg0);
    }
}

void BattleMenu_UpdateComPanelAutoInput(void) {
    s32 i;
    s8 var_v0;
    unk_D_84803548* ptr;

    for (i = 0; i < 4; i++) {
        if ((D_848037A0[i].unk_001C != NULL) && (D_848037A0[i].unk_001C->unk_000 & 2)) {
            break;
        }
    }

    if (i < 4) {
        if ((D_84816420->unk_0001 != 0) && (D_84816420->unk_0001 != 8)) {
            var_v0 = 3;
        } else {
            var_v0 = D_848037A0[i].unk_0017;
        }
        D_84816428.buttonPressed = 0;
        if (D_84816450 == 0) {
            ptr = D_848035E0[var_v0];

            D_84816450 = ptr[D_8481644C].unk_00;
            if (D_84816450 != 0) {
                D_84816428.buttonPressed = ptr[D_8481644C].unk_02;
                D_8481644C++;
            }
        }

        if (D_84816450 > 0) {
            D_84816450--;
        }
    }
}

s32 BattleMenu_IsSlotAlreadySelected(unk_D_848037A0* arg0, s8 arg1) {
    s32 i;
    s8 temp_v1;
    unk_D_848037A0* var_a2;

    for (i = 0; i < arg0->unk_000B; i++) {
        if (arg1 == arg0->unk_000C[i]) {
            return 1;
        }
    }

    return 0;
}

s32 BattleMenu_PicksExceedLevelCap(unk_D_848037A0* arg0) {
    s32 i;
    s32 var_v0 = 0;

    if (!(arg0->unk_001C->unk_000 & 2)) {
        for (i = 0; i < arg0->unk_000B; i++) {
            var_v0 += arg0->unk_0018[arg0->unk_000C[i]].unk_24;
        }

        if (D_84816420->unk_0001 == 3) {
            if ((arg0->unk_000B == 2) && (var_v0 >= 0x6A)) {
                return 1;
            }

            if ((arg0->unk_000B == 3) && (var_v0 >= 0x9C)) {
                return 1;
            }
        } else if (D_84816420->unk_0001 == 4) {
            if ((arg0->unk_000B == 2) && (var_v0 >= 0x38)) {
                return 1;
            }

            if ((arg0->unk_000B == 3) && (var_v0 >= 0x51)) {
                return 1;
            }
        } else if (D_84816420->unk_0001 == 5) {
            if ((arg0->unk_000B == 2) && (var_v0 >= 0x24)) {
                return 1;
            }

            if ((arg0->unk_000B == 3) && (var_v0 >= 0x33)) {
                return 1;
            }
        }
    }

    return 0;
}

s32 BattleMenu_IsOrderSelectionComplete(unk_D_848037A0* arg0) {
    s8 var_v1;

    if ((D_84816420->unk_0001 != 0) && (D_84816420->unk_0001 != 8)) {
        var_v1 = 3;
    } else if (arg0->unk_001C->unk_000 & 2) {
        var_v1 = arg0->unk_0017;
    } else {
        var_v1 = arg0->unk_0017;
        if ((arg0->unk_0002 != -1) && (var_v1 >= 4)) {
            var_v1 = 3;
        }
    }

    return arg0->unk_000B >= var_v1;
}

void BattleMenu_SelectOrderSlot(unk_D_848037A0* arg0, s8 arg1, s32 arg2) {
    if (arg1 >= arg0->unk_0017) {
        Audio_PlaySoundEffectById(SFX_MENU_ERROR);
        return;
    }

    if (arg2 != 0) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        arg0->unk_0005 = 4;
        arg0->unk_0006 = 2;
        arg0->unk_0016 = arg1;
        return;
    }

    if (BattleMenu_IsSlotAlreadySelected(arg0, arg1) != 0) {
        Audio_PlaySoundEffectById(SFX_MENU_ERROR);
        return;
    }

    arg0->unk_000C[arg0->unk_000B] = arg1;
    arg0->unk_000B++;
    BattleMenu_AppendOrderSlotIcon(arg0->unk_0003, arg0->unk_0001);

    if (arg0->unk_0009 != 0) {
        arg0->unk_0006 = 2;
    }

    if (BattleMenu_PicksExceedLevelCap(arg0) != 0) {
        Audio_PlaySoundEffectById(SFX_MENU_ERROR);
        arg0->unk_0005 = 2;
        arg0->unk_0006 = 2;
        return;
    }

    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
    if (BattleMenu_IsOrderSelectionComplete(arg0) != 0) {
        arg0->unk_0005 = 1;
        arg0->unk_000A = 0;
        arg0->unk_0006 = 2;
    }
}

void BattleMenu_UndoLastOrderSelection(unk_D_848037A0* arg0) {
    unk_D_848037A0* temp_v0;

    if (arg0->unk_000B > 0) {
        arg0->unk_000B = 0;

        BattleMenu_ResetOrderSlotIcons(arg0->unk_0003);

        if (arg0->unk_0009 != 0) {
            arg0->unk_0006 = 2;
        }

        Audio_PlaySoundEffectById(SFX_MENU_BACK);

        if (arg0->unk_0002 != -1) {
            temp_v0 = &D_848037A0[arg0->unk_0002];
            temp_v0->unk_0005 = 0;
            temp_v0->unk_000B = 0;
            temp_v0->unk_0009 = 0;
            temp_v0->unk_0006 = 2;
        }
    }
}

void BattleMenu_HandleOrderSelectPanel_PartyInput(Controller* arg0, unk_D_848037A0* arg1) {
    s32 temp_a2 = BTN_IS_DOWN(arg0, BTN_R);

    if (BTN_IS_PRESSED(arg0, BTN_R)) {
        // clang-format off
        arg1->unk_0009 = 1; arg1->unk_0006 = 2;
        // clang-format on
    }

    if (arg0->unk_0A & 0x10) {
        arg1->unk_0009 = 0;
        arg1->unk_0006 = 2;
    }

    if (BTN_IS_PRESSED(arg0, BTN_L)) {
        BattleMenu_UndoLastOrderSelection(arg1);
    } else if (BTN_IS_PRESSED(arg0, BTN_B)) {
        BattleMenu_SelectOrderSlot(arg1, 0, temp_a2);
    } else if (BTN_IS_PRESSED(arg0, BTN_CLEFT)) {
        BattleMenu_SelectOrderSlot(arg1, 1, temp_a2);
    } else if (BTN_IS_PRESSED(arg0, BTN_CUP)) {
        BattleMenu_SelectOrderSlot(arg1, 2, temp_a2);
    } else if (BTN_IS_PRESSED(arg0, BTN_A)) {
        BattleMenu_SelectOrderSlot(arg1, 3, temp_a2);
    } else if (BTN_IS_PRESSED(arg0, BTN_CDOWN)) {
        BattleMenu_SelectOrderSlot(arg1, 4, temp_a2);
    } else if (BTN_IS_PRESSED(arg0, BTN_CRIGHT)) {
        BattleMenu_SelectOrderSlot(arg1, 5, temp_a2);
    }
}

void BattleMenu_HandleOrderSelectPanel_ConfirmInput(Controller* arg0, unk_D_848037A0* arg1) {
    unk_D_848037A0* temp_v0_2;

    if (BTN_IS_PRESSED(arg0, BTN_R)) {
        arg1->unk_0009 = 1;
        arg1->unk_0006 = 2;
    }
    if (arg0->unk_0A & 0x10) {
        arg1->unk_0009 = 0;
        arg1->unk_0006 = 2;
    }

    if (BTN_IS_PRESSED(arg0, BTN_DLEFT | BTN_DRIGHT)) {
        arg1->unk_0006 = 2;
        arg1->unk_000A ^= 1;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    } else if (BTN_IS_PRESSED(arg0, BTN_A)) {
        if (arg1->unk_000A == 0) {
            arg1->unk_0006 = 2;
            arg1->unk_0005 = 3;
            arg1->unk_0008 = 0;
            Audio_PlaySoundEffectById(9);
        } else {
            arg1->unk_0006 = 2;
            arg1->unk_0005 = 0;
            arg1->unk_000B = 0;
            arg1->unk_0009 = 0;
            BattleMenu_ResetOrderSlotIcons(arg1->unk_0003);
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
            if (arg1->unk_0002 != -1) {
                temp_v0_2 = &D_848037A0[arg1->unk_0002];
                temp_v0_2->unk_0005 = 0;
                temp_v0_2->unk_000B = 0;
                temp_v0_2->unk_0009 = 0;
                temp_v0_2->unk_0006 = 2;
            }
        }
    }
    arg1->unk_0006 = 2;
}

void BattleMenu_HandleOrderSelectPanel_LevelCapNoticeInput(Controller* arg0, unk_D_848037A0* arg1) {
    if (BTN_IS_PRESSED(arg0, BTN_A | BTN_B)) {
        arg1->unk_0005 = 0;
        arg1->unk_000B = 0;
        arg1->unk_0009 = 0;
        arg1->unk_0006 = 2;
        BattleMenu_ResetOrderSlotIcons(arg1->unk_0003);
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
}

void BattleMenu_HandleOrderSelectPanel_MonDetailInput(Controller* arg0, unk_D_848037A0* arg1) {
    s32 var_v0 = 0;

    switch (arg1->unk_0016) {
        case 0:
            if (arg0->unk_0A & 0x4000) {
                var_v0 = 1;
            }
            break;

        case 1:
            if (arg0->unk_0A & 2) {
                var_v0 = 1;
            }
            break;

        case 2:
            if (arg0->unk_0A & 8) {
                var_v0 = 1;
            }
            break;

        case 3:
            if (arg0->unk_0A & 0x8000) {
                var_v0 = 1;
            }
            break;

        case 4:
            if (arg0->unk_0A & 4) {
                var_v0 = 1;
            }
            break;

        case 5:
            if (arg0->unk_0A & 1) {
                var_v0 = 1;
            }
            break;
    }

    if (var_v0 != 0) {
        if (!(arg0->buttonDown & 0x10)) {
            arg1->unk_0009 = 0;
        }
        arg1->unk_0005 = 0;
        arg1->unk_0006 = 2;
    }
}

s32 BattleMenu_UpdateOrderSelectPanel(s32 arg0, unk_D_848037A0* arg1) {
    Controller* var_a0;
    s32 sp18 = 0;

    if (arg1->unk_001C->unk_000 & 2) {
        var_a0 = &D_84816428;
    } else {
        var_a0 = &gControllers[arg1->unk_0001];
    }

    if (arg0 == 0) {
        switch (arg1->unk_0005) {
            case 0:
                BattleMenu_HandleOrderSelectPanel_PartyInput(var_a0, arg1);
                break;

            case 1:
                BattleMenu_HandleOrderSelectPanel_ConfirmInput(var_a0, arg1);
                break;

            case 2:
                BattleMenu_HandleOrderSelectPanel_LevelCapNoticeInput(var_a0, arg1);
                break;

            case 3:
                sp18 = 1;
                break;

            case 4:
                BattleMenu_HandleOrderSelectPanel_MonDetailInput(var_a0, arg1);
                break;
        }
    }
    return sp18;
}

s32 BattleMenu_UpdateOrderSelect(s32 arg0) {
    UNUSED s32 pad;
    s32 i;
    s32 var_s2;
    s32 sp30;

    var_s2 = 0;
    sp30 = 0;

    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
    BattleMenu_UpdateComPanelAutoInput();
    GeoRender_AdvanceFrameCounter();
    BgStage_DrawFrame();

    if (D_84803798 != 0) {
        BattleMenu_DrawBottomActionButtons();
    }

    for (i = 0; i < D_8480379C; i++) {
        var_s2 += BattleMenu_UpdateOrderSelectPanel(arg0, &D_848037A0[i]);
        BattleMenu_DrawOrderSelectPanel(&D_848037A0[i]);
    }

    BattleMenu_DrawTeamOrderSidebarTeam0();
    BattleMenu_DrawTeamOrderSidebarTeam1();
    BattleMenu_DrawScrollingRulesText();

    if (arg0 == 0) {
        if (var_s2 == D_8480379C) {
            sp30 = 1;
            StageContext_SetClearColor(0xFFFF);
            Audio_StopMusic(0x10);
        }

        if (D_84803798 > 0) {
            D_84803798 -= 1;
        }
    } else {
        D_84803798 = 2;
    }
    return sp30;
}

void BattleMenu_RearrangeLeadPokemon(BattleSessionTeams* arg0, unk_D_84803760* arg1) {
    TeamRoster* temp_v0;
    s32 tmp;

    if (arg0->unk_01 == 2) {
        tmp = ((arg1->unk_02[0] >> 4) & 0xF) - 1;
        if (tmp == arg0->unk_08[1]->unk_001) {
            temp_v0 = arg0->unk_08[0];
            arg0->unk_08[0] = arg0->unk_08[1];
            arg0->unk_08[1] = temp_v0;
        }
    }
}

void BattleMenu_FillDefaultOrder(s8* arg0, s32 arg1) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < arg1; j++) {
            if (i == arg0[j]) {
                break;
            }
        }

        if (j == arg1) {
            arg0[arg1] = i;
            arg1 += 1;
        }
    }
}

void BattleMenu_CommitOrderSelection(void) {
    s32 i;
    s32 var_s4;
    TeamRoster* temp_s1;
    unk_D_848037A0* var_s2;

    var_s2 = D_848037A0;
    var_s4 = D_8480379C;

    while (var_s4-- > 0) {
        temp_s1 = var_s2->unk_001C;
        if (temp_s1->unk_000 & 2) {
            temp_s1->unk_002 = temp_s1->unk_214->unk_002;
            _bcopy(temp_s1->unk_214->unk_028, temp_s1->unk_01C, 0x1F8);
        } else {
            BattleMenu_FillDefaultOrder(var_s2->unk_000C, var_s2->unk_000B);
            temp_s1->unk_002 = var_s2->unk_000B;

            for (i = 0; i < temp_s1->unk_214->unk_002; i++) {
                temp_s1->unk_01C[i] = var_s2->unk_0018[var_s2->unk_000C[i]];
            }
        }
        var_s2++;
    }

    BattleMenu_RearrangeLeadPokemon(&D_84816420->unk_1194[0], &D_84803760[0]);
    BattleMenu_RearrangeLeadPokemon(&D_84816420->unk_1194[1], &D_84803760[1]);
}

void BattleMenu_AddOrderSelectPanel(s16 arg0, s16 arg1, TeamRoster* arg2, s32 arg3, s32 arg4) {
    s32 i;
    unk_D_848037A0* temp_v1;
    BattleMon* temp_s0;

    temp_v1 = &D_848037A0[D_8480379C];
    temp_v1->unk_0000 = D_8480379C;
    temp_v1->unk_0001 = arg2->unk_001;
    temp_v1->unk_0002 = arg4;
    temp_v1->unk_0003 = arg3;
    temp_v1->unk_0005 = 0;
    temp_v1->unk_000B = 0;
    temp_v1->unk_0006 = 2;
    temp_v1->unk_0007 = 0;
    temp_v1->unk_0009 = 0;
    temp_v1->unk_000A = 0;
    temp_v1->unk_0012 = arg0;
    temp_v1->unk_0014 = arg1;
    temp_v1->unk_0017 = arg2->unk_214->unk_002;
    temp_v1->unk_0018 = arg2->unk_214->unk_028;
    temp_v1->unk_001C = arg2;

    for (i = 0; i < arg2->unk_214->unk_002; i++) {
        temp_s0 = &arg2->unk_214->unk_028[i];
        Pokemon_PrepareBattleMon(temp_s0);
        temp_s0->unk_06 = D_80070FA0[temp_s0->unk_00.unk_00 - 1].unk_06;
        temp_s0->unk_07 = D_80070FA0[temp_s0->unk_00.unk_00 - 1].unk_07;
        PokeIcon_LoadModelTextureForMon(temp_v1->unk_0020[i], 0, temp_s0);
    }

    D_8480379C++;
}

void BattleMenu_InitOrderSelectPanels(SessionContext* arg0) {
    BattleSessionTeams* temp_s0 = &arg0->unk_1194[0];

    D_84816420 = arg0;
    D_8480379C = 0;
    D_84803798 = 2;
    D_8480379A = 0;
    D_8481644C = 0;
    D_84816450 = 0;
    D_84816428.buttonPressed = 0;

    BattleMenu_InitTeamOrderState(&D_84803760[0], &D_84816420->unk_1194[0], D_84816420->unk_0001);
    BattleMenu_InitTeamOrderState(&D_84803760[1], &D_84816420->unk_1194[1], D_84816420->unk_0001);

    if (temp_s0->unk_01 == 1) {
        BattleMenu_AddOrderSelectPanel(0x50, 0x21, temp_s0->unk_08[0], 0, -1);
    } else if (temp_s0->unk_08[0]->unk_001 < temp_s0->unk_08[1]->unk_001) {
        BattleMenu_AddOrderSelectPanel(0x50, 0x21, temp_s0->unk_08[0], 0, D_8480379C + 1);
        BattleMenu_AddOrderSelectPanel(0x50, 0x81, temp_s0->unk_08[1], 0, D_8480379C - 1);
    } else {
        BattleMenu_AddOrderSelectPanel(0x50, 0x21, temp_s0->unk_08[1], 0, D_8480379C + 1);
        BattleMenu_AddOrderSelectPanel(0x50, 0x81, temp_s0->unk_08[0], 0, D_8480379C - 1);
    }

    temp_s0++;
    if (temp_s0->unk_01 == 1) {
        BattleMenu_AddOrderSelectPanel(0x50, 0x146, temp_s0->unk_08[0], 1, -1);
    } else if (temp_s0->unk_08[0]->unk_001 < temp_s0->unk_08[1]->unk_001) {
        BattleMenu_AddOrderSelectPanel(0x50, 0xE6, temp_s0->unk_08[0], 1, D_8480379C + 1);
        BattleMenu_AddOrderSelectPanel(0x50, 0x146, temp_s0->unk_08[1], 1, D_8480379C - 1);
    } else {
        BattleMenu_AddOrderSelectPanel(0x50, 0xE6, temp_s0->unk_08[1], 1, D_8480379C + 1);
        BattleMenu_AddOrderSelectPanel(0x50, 0x146, temp_s0->unk_08[0], 1, D_8480379C - 1);
    }
}

s32 BattleMenu_RunOrderSelectScreen(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('MSEL');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(1, 1, 2, 0, 2, 1);
    Text_InitStringTables();
    Font_Init(0x3C, 0);
    PokeIcon_OpenModelArchive();
    D_84803780 = ASSET_LOAD2(backgrounds, 1, 1);
    D_84803784 = BinArchive_GetFile(D_84803780, 5);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, order_select_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);

    D_84803788 = Text_GetStringTable(0x25);
    D_8480378C = Text_GetStringTable(0x26);
    D_84803790 = Text_GetStringTable(0x12);
    D_84803794 = Text_GetStringTable(6);

    BattleMenu_InitOrderSelectPanels(&D_800AE540);
    Audio_PlayMusicIfChanged(7);
    StageContext_Activate(sp24);
    BgStage_WaitForCondition(BattleMenu_UpdateOrderSelect, 8, 8);
    StageContext_Deactivate();
    BattleMenu_CommitOrderSelection();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('MSEL');
    return 0;
}
