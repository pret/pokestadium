#include "lab_pc.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/gb_data.h"
#include "src/pokemon_stats.h"
#include "src/save_data.h"
#include "src/game_state.h"
#include "src/table_view.h"
#include "src/text_system.h"
#include "src/gb_save.h"
#include "src/audio_sfx.h"
#include "src/hal_libc.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_88218060 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Color_RGBA8* unk_04;
} unk_D_88218060; // size = 0x8

typedef struct unk_D_88218070 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8* unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x10 */ Color_RGBA8* unk_10;
} unk_D_88218070; // size = 0x14

static char** D_88224FC0;
static char** D_88224FC4;
static char** D_88224FC8;
static char** D_88224FCC;

void LabItem_ReadDeckEntries(s32 arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C* arg3) {
    DeckHandle* sp1C = Deck_Open(arg0, arg1, arg2, 0);

    arg3->unk_08 = Deck_ReadEntries(arg3->unk_00, arg3->unk_04, sp1C);
    Deck_CloseAndFlush(sp1C);
}

void LabItem_WriteDeckBack(s32 arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C* arg3, s32 arg4, char* arg5, s32 arg6) {
    DeckHandle* sp2C;

    if (arg6 != -1) {
        if (1) {}
        sp2C = Deck_OpenAndSetName(arg0, arg1, arg2, arg4, arg5, arg6);
    } else {
        sp2C = Deck_Open(arg0, arg1, arg2, 1);
    }

    Deck_WriteEntries(arg3->unk_00, arg3->unk_08, sp2C);

    if ((arg0 == 0x10) || (arg0 == 0x11) || (arg0 == 0x12)) {
        Deck_CloseAndFlushBox(sp2C);
    } else {
        Deck_CloseAndFlush(sp2C);
    }
}

void LabItem_LoadGamePakBoxSlots(unk_func_8821421C_07C* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        arg0[i].unk_00 = Deck_IsSaveEntryPresent(0x12, i);
        if (arg0[i].unk_00 != 0) {
            arg0[i].unk_04 = Deck_GetSaveEntryTrainerId(0x12, i) & 0xFFFF;
            Deck_GetSaveEntryName(0x12, i, arg0[i].unk_08);
        }
    }
}

s32 LabItem_FindOrAllocateGamePakBoxSlot(unk_func_8821421C_07C* arg0, s32 arg1, char* arg2) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if ((arg0[i].unk_00 != 0) && (arg1 == arg0[i].unk_04) && (HAL_Strcmp(arg0[i].unk_08, arg2) == 0)) {
            return i;
        }
    }

    for (i = 0; i < 4; i++) {
        if (arg0[i].unk_00 == 0) {
            return i;
        }
    }

    return -1;
}

void LabItem_InitBoxLocationWidget(unk_func_8821421C_02C_030* arg0, unk_func_8850143C* arg1, spE8_func_882121E0* arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8821421C_02C_030));

    arg0->unk_00.unk_18 = LabItem_DrawBoxLocationLabel;
    arg0->unk_00.unk_14.unk_00 = arg1->unk_00.unk_14.unk_00;
    arg0->unk_00.unk_14.unk_02 = arg1->unk_00.unk_14.unk_02;
    arg0->unk_2C = arg1;
    arg0->unk_30 = GbSave_GameToCategoryIndex(GbSave_GetPortGame(GbSave_GetActivePort()));
    arg0->unk_34 = -1;
    arg0->unk_38 = arg2;
}

s32 LabItem_DrawBoxLocationLabel(unk_func_8821421C_02C_030* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88217FD0 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88217FD4 = { 0x7F, 0x7F, 0x7F, 0xFF };

    s32 temp_v0;
    s32 var_s0;

    if (arg0->unk_34 == -1) {
        return 1;
    }

    temp_v0 = Font_MeasureTextExtent(8, 0, arg0->unk_38->unk_00[arg0->unk_34], arg0->unk_34);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    if ((arg0->unk_34 == 0) || (arg0->unk_34 == 1)) {
        var_s0 = (((arg0->unk_00.unk_14.unk_00 - temp_v0) - 0x20) / 2) + arg1 + 0x20;

        gDPLoadTextureBlock(gDisplayListHead++, D_88223470[arg0->unk_30], G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 26, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (var_s0 - 0x20) << 2, (arg2 + 2) << 2, (var_s0 - 9) << 2,
                            (arg2 + 0x1B) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    } else {
        var_s0 = (((arg0->unk_00.unk_14.unk_00 - temp_v0) - 0x30) / 2) + arg1 + 0x30;

        gDPLoadTextureBlock(gDisplayListHead++, D_88223488, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 26, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (var_s0 - 0x30) << 2, (arg2 + 2) << 2, (var_s0 - 9) << 2,
                            (arg2 + 0x1B) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88217FD0.r, D_88217FD0.g, D_88217FD0.b, D_88217FD0.a);
    Font_SetActive(8, 0);
    Font_Printf(var_s0, arg2 + 5, arg0->unk_38->unk_00[arg0->unk_34]);
    Font_EndTexturedTextRendering();

    return 0;
}

s32 LabItem_BoxLocationWidget_GetSelection(unk_func_8821421C_02C_030* arg0) {
    return arg0->unk_34;
}

void LabItem_BoxLocationWidget_SetSelection(unk_func_8821421C_02C_030* arg0, s32 arg1) {
    arg0->unk_34 = arg1;
}

void LabItem_InitConfirmDialog(unk_func_8821421C_034* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    static Color_RGBA8 D_88217FD8 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88217FDC = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88217FE0 = { 0x99, 0x99, 0x89, 0xFF };
    static Color_RGBA8 D_88217FE4 = { 0xFF, 0xFF, 0x00, 0xFF };

    UNUSED s32 pad[2];
    WidgetGridMenu* ptr;
    unk_func_8850B254* sp60;
    unk_func_885012A4* sp5C;
    WidgetNode* sp58;
    WidgetNode* sp54;
    unk_func_8850878C* sp50;
    unk_func_8850878C* sp4C;
    WidgetAnimatedFrame* sp48;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8821421C_034));

    arg0->unk_00.unk_20 = LabItem_ConfirmDialog_HandleInput;
    arg0->unk_00.unk_24 = LabItem_ConfirmDialog_SetSelectedIndex;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, 0x100, 0x3C);

    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    sp60 = mem_pool_alloc(arg3, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(sp60, 0, 0, 0x100, 0x14, D_88217FD8, D_88217FDC);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp60);

    arg0->unk_34 = mem_pool_alloc(arg3, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_34, 8, 0, "Do?", 8);
    arg0->unk_34->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_34);

    sp5C = mem_pool_alloc(arg3, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp5C, 0, 0x18, 0x100, 0x24, D_88217FE0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp5C);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(WidgetGridMenu));
    ((func8850C284)Memmap_GetFragmentVaddr(WidgetTree_InitGridMenu))(arg0->unk_30, 1, 2, arg3);

    sp54 = mem_pool_alloc(arg3, sizeof(WidgetNode));
    ((func8850A40C)Memmap_GetFragmentVaddr(WidgetTree_InitBorderFrame))(sp54, 0x28, 6, 0x48, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp5C, sp54);
    ptr = arg0->unk_30;
    ptr->unk_18[0] = sp54;

    sp50 = mem_pool_alloc(arg3, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp50, 0xA, 2, Text_GetString(NULL, 0, D_88224FC4, 0x17), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp54, sp50);

    sp58 = mem_pool_alloc(arg3, sizeof(WidgetNode));
    ((func8850A40C)Memmap_GetFragmentVaddr(WidgetTree_InitBorderFrame))(sp58, 0x90, 6, 0x48, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp5C, sp58);
    ptr = arg0->unk_30;
    ptr->unk_18[1] = sp58;

    sp4C = mem_pool_alloc(arg3, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp4C, 6, 2, Text_GetString(NULL, 0, D_88224FC4, 0x18), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp58, sp4C);
    ((func8850CAB4)Memmap_GetFragmentVaddr(WidgetTree_SelectFirstEnabledGridItem))(arg0->unk_30);

    sp48 = mem_pool_alloc(arg3, sizeof(WidgetAnimatedFrame));
    ((func88503340)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedFrameVariantA))(sp48, 0, 0, 0x10, 0x10, D_88217FE4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp5C, sp48);
    arg0->unk_30->unk_1C = sp48;
}

s32 LabItem_ConfirmDialog_HandleInput(unk_func_8821421C_034* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_10(arg0->unk_30, arg1);
        if (var_v1 == 0) {
            if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            } else if (arg1->buttonPressed & 0x8000) {
                var_v1 = 0x80000004;
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void LabItem_ConfirmDialog_SetSelectedIndex(unk_func_8821421C_034* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_30->unk_14(arg0->unk_30, arg1);
}

void LabItem_SetConfirmDialogText(unk_func_8821421C_034* arg0, char* arg1) {
    arg0->unk_34->unk_40 = arg1;
}

s32 LabItem_RunConfirmDialog(unk_func_8821421C_034* arg0, Controller* arg1) {
    s32 var_s0;
    s32 var_s1 = 0;

    arg0->unk_30->unk_14(arg0->unk_30, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);

    while (var_s1 == 0) {
        Ui_SendMessageAndPollInput(var_s1);

        var_s0 = LabItem_ConfirmDialog_HandleInput(arg0, arg1);

        if (!(var_s0 & 1)) {
            if (var_s0 & 2) {
                var_s1 = 1;
            } else if (var_s0 & 4) {
                switch (arg0->unk_30->unk_24) {
                    case 0:
                        var_s1 = 2;
                        Audio_PlaySoundEffectById(0x1F);
                        var_s0 = 1;
                        break;

                    case 1:
                        var_s0 = (var_s0 & ~4) | 2;
                        var_s1 = 1;
                        break;
                }
            }
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(var_s0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s1 - 1;
}

s32 LabItem_MeasureMenuWidth(spE8_func_882121E0* arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s1 = 0;
    s32 i;

    for (i = 0; i < arg1; i++) {
        temp_v0 = Font_MeasureTextExtent(8, 0, arg0->unk_00[i]);
        if (var_s1 < temp_v0) {
            var_s1 = temp_v0;
        }
    }

    return var_s1;
}

void LabItem_DrawMenuCell(s32 arg0, s32 arg1, s8* arg2, s32 arg3, s32 arg4, unk_func_88200FA0_030_030* arg5) {
    static Color_RGBA8 D_88217FE8[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF }, { 0xF0, 0xF0, 0xF0, 0x4D }, { 0xF0, 0xF0, 0x00, 0xFF },
        { 0xCB, 0xFF, 0xD6, 0xFF }, { 0xB2, 0xFF, 0xC3, 0xFF },
    };
    static Color_RGBA8 D_88217FFC = { 0x6C, 0x6C, 0x7E, 0xFF };

    Color_RGBA8 sp3C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_t2 = ((D_88217FFC.r << 8) & 0xF800) | ((D_88217FFC.g << 3) & 0x7C0) | ((D_88217FFC.b >> 2) & 0x3E) | 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_3C + arg0) - 1, (arg1 + arg5->unk_3E) - 1);

    Font_BeginTranslucentTextRendering();

    if (arg4 & 0x100) {
        sp3C = D_88217FE8[2];
    } else if (arg4 & 4) {
        sp3C = D_88217FE8[1];
    } else {
        sp3C = D_88217FE8[0];
    }

    Gfx_SetEnvColor(sp3C.r, sp3C.g, sp3C.b, sp3C.a);
    Font_SetActive(8, 0);
    Font_Printf(arg0 + 8, arg1 + 4, arg2);
    Font_EndTexturedTextRendering();
}

void LabItem_InitDropdownMenu(unk_func_8821421C_02C_070* arg0, s32 arg1, s32 arg2, s32 arg3, spE8_func_882121E0* arg4, s32 arg5,
                   s32 arg6, MemoryPool* arg7) {
    s32 sp4C = LabItem_MeasureMenuWidth(arg4, arg5) + 0x10;
    UNUSED s32 pad;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8821421C_02C_070));

    arg0->unk_00.unk_20 = LabItem_DropdownMenu_HandleInput;
    arg0->unk_00.unk_24 = LabItem_DropdownMenu_SetSelectedIndex;
    arg0->unk_00.unk_10.unk_00 = ((arg3 - sp4C) / 2) + arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_40 = arg6;

    PointerList_Initialize(&arg0->unk_34, arg4, arg5, arg5);

    arg0->unk_2C = mem_pool_alloc(arg7, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, sp4C, arg5 * 0x1C);

    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    arg0->unk_30 = mem_pool_alloc(arg7, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_30, 0, 0, LabItem_DrawMenuCell, sp4C, 0x1C, arg5, 1,
                                                           arg7);
    ((func88506384)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridPage))(arg0->unk_30, &arg0->unk_34, arg7);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_30);
}

s32 LabItem_DropdownMenu_HandleInput(unk_func_8821421C_02C_070* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void LabItem_DropdownMenu_SetSelectedIndex(unk_func_8821421C_02C_070* arg0, s32 arg1) {
    unk_func_88200FA0_030_030* temp_a0;

    arg0->unk_00.unk_2A = arg1;
    arg0->unk_30->unk_00.unk_24(&arg0->unk_30->unk_00, arg1);
}

s32 LabItem_DropdownMenu_GetSelectedIndex(unk_func_8821421C_02C_070* arg0) {
    return arg0->unk_30->unk_38;
}

void LabItem_DropdownMenu_SetSelection(unk_func_8821421C_02C_070* arg0, s32 arg1) {
    arg0->unk_44 = arg1;

    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_30);
    ((func88506BFC)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelection))(arg0->unk_30, arg0->unk_44);

    arg0->unk_30->unk_34[arg0->unk_30->unk_38] |= 0x100;
}

void LabItem_DropdownMenu_Open(unk_func_8821421C_02C_070* arg0) {
    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);
}

void LabItem_DropdownMenu_Close(unk_func_8821421C_02C_070* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
}

s32 LabItem_RunDropdownMenuModal(unk_func_8821421C_02C_070* arg0, Controller* arg1) {
    s32 var_s0;
    s32 var_s1 = 0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    while (var_s1 == 0) {
        Ui_SendMessageAndPollInput(NULL);

        var_s0 = arg0->unk_00.unk_20(arg0, arg1);

        if (!(var_s0 & 1)) {
            if (arg1->buttonPressed & 0x4000) {
                var_s0 = 0x80000003;
                var_s1 = 1;
            } else if (arg1->buttonPressed & 0x8000) {
                var_s0 = 0x80000005;
                var_s1 = 2;
            }
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(var_s0);
    }

    return var_s1 - 1;
}

void LabItem_DropdownMenu_SetDisabledIndex(unk_func_8821421C_02C_070* arg0, s32 arg1) {
    arg0->unk_48 = arg1;
    arg0->unk_30->unk_34[arg1] |= 4;
}

s32 LabItem_DrawItemRow(u8* arg0, s32 arg1, s32 arg2, s32 arg3) {
    static Color_RGBA8 D_88218000 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88218004[] = {
        { 0xFF, 0xCB, 0xDE, 0xFF },
        { 0xFF, 0xBF, 0xD6, 0xFF },
        { 0x5A, 0x5A, 0xA6, 0xFF },
    };

    Color_RGBA8 sp34;
    s8 sp2C[8];
    UNUSED s32 pad;
    s8* sp24;

    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);

    if (LabItem_IsQuantitylessItem(arg0[0]) != 0) {
        sp34 = D_88218004[0];
    } else {
        sp34 = D_88218000;
    }

    Gfx_SetEnvColor(sp34.r, sp34.g, sp34.b, sp34.a);
    Font_Printf(arg1 + 0x19, arg2 + 4, Text_GetString(NULL, 0, D_88224FC8, arg0[0] - 1));

    if (LabItem_IsQuantitylessItemForOperation(arg0[0]) == 0) {
        sp24 = Text_GetString(NULL, 0, D_88224FC4, 0x19);
        sprintf(sp2C, "%s00", sp24);
        Font_SetActive(4, 0);
        Font_Printf(((arg1 + arg3) - Font_MeasureTextExtent(0, 0, &sp2C)) - 0x19, arg2 + 8, "%s%02d", sp24, arg0[1]);
    }
    Font_EndTexturedTextRendering();
}

void LabItem_DrawItemGridCell(s32 arg0, s32 arg1, u8* arg2, s32 arg3, s32 arg4, unk_func_8820BE14_02C_038* arg5) {
    static Color_RGBA8 D_88218010[] = { 0x40, 0x40, 0x74, 0xFF };
    static Color_RGBA8 D_88218014[] = {
        { 0x78, 0x78, 0xF1, 0xFF },
        { 0x5E, 0x5E, 0xBE, 0xFF },
    };

    Color_RGBA8 spD4;

    if (arg2 != NULL) {
        s32 temp_t1;
        s32 temp_t0;
        s32 temp_t4;
        s32 temp_a3;

        if (arg4 & 2) {
            spD4 = Color_ScaleRgb(D_88218010[0], 1.4f);
        } else {
            spD4 = D_88218010[0];
        }

        gDPPipeSync(gDisplayListHead++);

        gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
        gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

        temp_t1 = ((spD4.r << 8) & 0xF800) | ((spD4.g << 3) & 0x7C0) | ((spD4.b >> 2) & 0x3E) | 1;

        gDPPipeSync(gDisplayListHead++);

        gDPSetFillColor(gDisplayListHead++, temp_t1 | (temp_t1 << 0x10));
        gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, arg0 + 0xEB, arg1 + 0x1A);

        temp_a3 =
            ((D_88218014[1].r << 8) & 0xF800) | ((D_88218014[1].g << 3) & 0x7C0) | ((D_88218014[1].b >> 2) & 0x3E) | 1;

        gDPPipeSync(gDisplayListHead++);

        gDPSetFillColor(gDisplayListHead++, temp_a3 | (temp_a3 << 0x10));
        gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + 0xEB, arg1);

        temp_t4 =
            ((D_88218014[1].r << 8) & 0xF800) | ((D_88218014[1].g << 3) & 0x7C0) | ((D_88218014[1].b >> 2) & 0x3E) | 1;

        gDPPipeSync(gDisplayListHead++);

        gDPSetFillColor(gDisplayListHead++, temp_t4 | (temp_t4 << 0x10));
        gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 0x1B, arg0 + 0xEB, arg1 + 0x1B);

        if (!(arg4 & 0x100)) {
            LabItem_DrawItemRow(arg2, arg0, arg1, arg5->unk_00.unk_3C);
        }
    } else {
        s32 temp_t1;
        s32 temp_t0;
        s32 temp_t4;
        s32 temp_a3;

        if (arg4 & 1) {
            spD4 = D_88218010[0];

            gDPPipeSync(gDisplayListHead++);

            gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
            gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

            temp_t1 = ((spD4.r << 8) & 0xF800) | ((spD4.g << 3) & 0x7C0) | ((spD4.b >> 2) & 0x3E) | 1;

            gDPPipeSync(gDisplayListHead++);

            gDPSetFillColor(gDisplayListHead++, temp_t1 | (temp_t1 << 0x10));
            gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, arg0 + 0xEB, arg1 + 0x1A);

            temp_a3 = ((D_88218014[1].r << 8) & 0xF800) | ((D_88218014[1].g << 3) & 0x7C0) |
                      ((D_88218014[1].b >> 2) & 0x3E) | 1;

            gDPPipeSync(gDisplayListHead++);

            gDPSetFillColor(gDisplayListHead++, temp_a3 | (temp_a3 << 0x10));
            gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + 0xEB, arg1);

            temp_t4 = ((D_88218014[1].r << 8) & 0xF800) | ((D_88218014[1].g << 3) & 0x7C0) |
                      ((D_88218014[1].b >> 2) & 0x3E) | 1;

            gDPPipeSync(gDisplayListHead++);

            gDPSetFillColor(gDisplayListHead++, temp_t4 | (temp_t4 << 0x10));
            gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 0x1B, arg0 + 0xEB, arg1 + 0x1B);
        } else {
            spD4 = Color_ScaleRgb(D_88218010[0], 0.8f);

            gDPPipeSync(gDisplayListHead++);

            gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
            gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

            temp_t0 = ((spD4.r << 8) & 0xF800) | ((spD4.g << 3) & 0x7C0) | ((spD4.b >> 2) & 0x3E) | 1;

            gDPPipeSync(gDisplayListHead++);

            gDPSetFillColor(gDisplayListHead++, temp_t0 | (temp_t0 << 0x10));
            gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + 0xEB, arg1 + 0x1B);
        }
    }
}

void LabItem_InitItemRowWidget(unk_func_8821421C_02C_06C_02C_060* arg0, s32 arg1, s32 arg2, s32 arg3) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8821421C_02C_06C_02C_060));

    arg0->unk_00.unk_18 = LabItem_ItemRowWidget_Draw;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = 0;
    arg0->unk_2C.unk_00.unk_00 = 1;
    arg0->unk_2C.unk_00.unk_01 = 1;
}

void LabItem_ItemRowWidget_SetItem(unk_func_8821421C_02C_06C_02C_060* arg0, unk_func_8821421C_02C_06C_02C_060_02C_000 arg1) {
    arg0->unk_2C.unk_00 = arg1;
}

s32 LabItem_ItemRowWidget_Draw(unk_func_8821421C_02C_06C_02C_060* arg0, s32 arg1, s32 arg2) {
    return LabItem_DrawItemRow(&arg0->unk_2C, arg1, arg2, arg0->unk_00.unk_14.unk_00);
}

void LabItem_QuantitySpinner_Init(unk_func_8820E99C_030* arg0, s32 arg1) {
    arg0->unk_30.unk_0C = 2;
    arg0->unk_30.unk_00 = 1;
    arg0->unk_30.unk_04 = 1;
    arg0->unk_30.unk_08 = arg1;
    arg0->unk_30.unk_10 = 0;
}

void LabItem_InitQuantitySpinnerDigits(unk_func_8820E99C_030* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    s32 sp2C;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8820E99C_030));

    arg0->unk_00.unk_1C = LabItem_QuantitySpinnerDigits_PositionArrow;
    arg0->unk_00.unk_18 = LabItem_DrawQuantitySpinnerDigits;
    arg0->unk_00.unk_20 = LabItem_QuantitySpinnerInput;
    arg0->unk_00.unk_24 = LabItem_QuantitySpinnerDigits_SetSelected;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    LabItem_QuantitySpinner_Init(arg0, 0);
    sp2C = Font_MeasureTextExtent(8, 0, "0");

    arg0->unk_44 = mem_pool_alloc(arg3, sizeof(unk_func_8820E99C_030_044));
    ((func88504F98)Memmap_GetFragmentVaddr(WidgetTree_InitDirectionalIndicator))(arg0->unk_44, -1, 0, sp2C + 2, 0x14);
    arg0->unk_44->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_44);
}

void LabItem_QuantitySpinnerDigits_SetSelected(unk_func_8820E99C_030* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_44->unk_00.unk_24(&arg0->unk_44->unk_00, arg1);
    arg0->unk_44->unk_00.unk_28 &= ~1;
    if (arg1 & 0x101) {
        arg0->unk_44->unk_00.unk_28 |= 1;
    }
}

s32 LabItem_QuantitySpinnerDigits_PositionArrow(unk_func_8820E99C_030* arg0) {
    s32 tmp = ((arg0->unk_30.unk_0C - arg0->unk_30.unk_10) - 1) * arg0->unk_44->unk_00.unk_14.unk_00;

    arg0->unk_44->unk_00.unk_10.unk_00 = tmp;
    arg0->unk_44->unk_00.unk_10.unk_02 = arg0->unk_44->unk_00.unk_10.unk_02;
    return 0;
}

s32 LabItem_DrawQuantitySpinnerDigits(unk_func_8820E99C_030* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_8821801C = { 0xF0, 0xF0, 0xF0, 0xFF };

    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
    Gfx_SetEnvColor(D_8821801C.r, D_8821801C.g, D_8821801C.b, D_8821801C.a);
    Font_DrawCharAt(arg1, arg2, (arg0->unk_30.unk_00 / 10) + 0x30);
    Font_DrawCharAt(arg0->unk_44->unk_00.unk_14.unk_00 + arg1, arg2, (arg0->unk_30.unk_00 % 10) + 0x30);
    Font_EndTexturedTextRendering();
    return 0;
}

s32 LabItem_QuantitySpinnerInput(unk_func_8820E99C_030* arg0, Controller* arg1) {
    s32 sp1C = 0;

    if (Ui_HandleNumericSelectionInput(&arg0->unk_30) == 0) {
        if (arg1->buttonPressed & 0x4000) {
            sp1C = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            sp1C = 0x80000004;
        }
    } else {
        sp1C = 8;
    }
    return sp1C;
}

void LabItem_QuantitySpinner_SetMax(unk_func_8820E99C* arg0, s32 arg1, s32 arg2) {
    arg0->unk_34 = arg2;
    LabItem_QuantitySpinner_Init(arg0->unk_30, arg1);
}

void LabItem_InitQuantitySpinner(unk_func_8820E99C* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    static Color_RGBA8 D_88218020 = { 0x6C, 0x6C, 0x7E, 0xFF };

    char* sp44;
    s32 sp40;
    UNUSED s32 pad;
    unk_func_885012A4* sp38;
    unk_func_8850878C* sp34;

    sp44 = Text_GetString(NULL, 0, D_88224FC4, 0x19);
    sp40 = Font_MeasureTextExtent(8, 0, sp44) + 0xC + (Font_MeasureTextExtent(8, 0, "0") * 2);

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8820E99C));

    arg0->unk_00.unk_20 = LabItem_QuantitySpinner_HandleInput;
    arg0->unk_00.unk_24 = LabItem_QuantitySpinner_SetSelected;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, sp40, 0x28);

    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    sp38 = mem_pool_alloc(arg3, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp38, 0, 0, sp40, 0x28, D_88218020);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp38);

    sp34 = mem_pool_alloc(arg3, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp34, 4, 0xA, sp44, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp38, sp34);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_8820E99C_030));
    LabItem_InitQuantitySpinnerDigits(arg0->unk_30, Font_MeasureTextExtent(8, 0, sp44) + 6, 0xA, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp38, arg0->unk_30);
    LabItem_QuantitySpinner_SetMax(arg0, 0, 0);
}

void LabItem_QuantitySpinner_SetSelected(unk_func_8820E99C* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_30->unk_00.unk_24(&arg0->unk_30->unk_00, arg1);
}

s32 LabItem_QuantitySpinner_HandleInput(unk_func_8820E99C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void LabItem_QuantitySpinner_Open(unk_func_8820E99C* arg0) {
    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);
}

void LabItem_QuantitySpinner_Close(unk_func_8820E99C* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
}

void LabItem_InitGamePakLabelWidget(unk_func_8821421C_038_02C* arg0, unk_func_8850143C* arg1) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8821421C_038_02C));

    arg0->unk_00.unk_18 = LabItem_DrawGamePakLabel;
    arg0->unk_00.unk_14.unk_00 = arg1->unk_00.unk_14.unk_00;
    arg0->unk_00.unk_14.unk_02 = arg1->unk_00.unk_14.unk_02;
    arg0->unk_30 = 0;
    arg0->unk_2C = arg1;
}

s32 LabItem_DrawGamePakLabel(unk_func_8821421C_038_02C* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88218024 = { 0xF0, 0xF0, 0xF0, 0xFF };

    if (arg0->unk_30 == 0) {
        return 1;
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    gDPLoadTextureBlock(gDisplayListHead++, D_88223488, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 26, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg1 + 5) << 2, (arg2 + 2) << 2, (arg1 + 0x2C) << 2, (arg2 + 0x1B) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPPipeSync(gDisplayListHead++);

    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88218024.r, D_88218024.g, D_88218024.b, D_88218024.a);
    Font_SetActive(8, 0);
    Font_Printf(arg1 + 0x35, arg2 + 4, &arg0->unk_30->unk_08);
    Font_EndTexturedTextRendering();

    return 0;
}

void LabItem_GamePakLabelWidget_SetSlot(unk_func_8821421C_038_02C* arg0, unk_func_8821421C_038_050* arg1) {
    arg0->unk_30 = arg1;
}

void LabItem_DrawGamePakInfoCard(s32 arg0, s32 arg1, unk_func_8820EFD8* arg2, s32 arg3, s32 arg4, unk_func_8821421C_038_034* arg5) {
    static Color_RGBA8 D_88218028 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_8821802C = { 0x6C, 0x6C, 0x7E, 0xFF };
    static Color_RGBA8 D_88218030 = { 0xAE, 0xAE, 0xCB, 0xFF };
    static Color_RGBA8 D_88218034[] = {
        {
            0x0,
            0x0,
            0x0,
            0x40,
        },
        {
            0x0,
            0x0,
            0x0,
            0x28,
        },
        {
            0x0,
            0x0,
            0x0,
            0x3C,
        },
        {
            0x88,
            0x22,
            0xC,
            0xD0,
        },
    };

    Color_RGBA8 sp6C;
    UNUSED s32 pad;
    char* sp64;
    UNUSED s32 pad2;
    s32 temp_a3;
    s32 temp_t4;

    if (arg4 & 2) {
        sp6C = Color_ScaleRgb(D_8821802C, 1.4f);
    } else {
        sp6C = D_8821802C;
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_a3 = ((sp6C.r << 8) & 0xF800) | ((sp6C.g * 8) & 0x7C0) | ((sp6C.b >> 2) & 0x3E) | 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetFillColor(gDisplayListHead++, (temp_a3 << 0x10) | temp_a3);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 2);

    temp_t4 = ((D_88218030.r << 8) & 0xF800) | ((D_88218030.g * 8) & 0x7C0) | ((D_88218030.b >> 2) & 0x3E) | 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetFillColor(gDisplayListHead++, (temp_t4 << 0x10) | temp_t4);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_00.unk_3C + arg0) - 1, arg1);

    temp_t4 = ((D_88218030.r << 8) & 0xF800) | ((D_88218030.g * 8) & 0x7C0) | ((D_88218030.b >> 2) & 0x3E) | 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetFillColor(gDisplayListHead++, (temp_t4 << 0x10) | temp_t4);
    gDPFillRectangle(gDisplayListHead++, arg0, (arg1 + arg5->unk_00.unk_3E) - 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 1);

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88218028.r, D_88218028.g, D_88218028.b, D_88218028.a);
    Font_SetActive(0x10, 0);

    sp64 = Text_GetString(NULL, 0, D_88224FC4, 0x14);
    Font_Printf(arg0 + 8, arg1 + 6, sp64);
    Font_Printf(Font_MeasureTextExtent(0, 0, sp64) + arg0 + 8, arg1 + 6, "%s", &arg2->unk_08);
    Font_SetActive(8, 0);

    sp64 = Text_GetString(NULL, 0, D_88224FC4, 0x15);
    Font_Printf(arg0 + 0xD, arg1 + 0x24, sp64);
    Font_Printf(Font_MeasureTextExtent(0, 0, sp64) + arg0 + 0xD, arg1 + 0x24, "%05d", arg2->unk_04);
    Font_EndTexturedTextRendering();
}

void LabItem_InitBoxScreen(unk_func_8821421C_038* arg0, s32 arg1, s32 arg2, WidgetNode* arg3,
                   unk_func_8821421C_034* arg4, MemoryPool* arg5) {
    static Color_RGBA8 D_88218044 = { 0x6C, 0x6C, 0x7E, 0xFF };
    static Color_RGBA8 D_88218048 = { 0x50, 0x50, 0x86, 0xFF };
    static Color_RGBA8 D_8821804C = { 0x79, 0x79, 0xCB, 0xFF };
    static Color_RGBA8 D_88218050 = { 0x40, 0x40, 0x6C, 0xFF };
    static Color_RGBA8 D_88218054 = { 0x6A, 0x6A, 0xB2, 0xFF };
    static Color_RGBA8 D_88218058 = { 0x2D, 0x1A, 0x41, 0xFF };
    static Color_RGBA8 D_8821805C = { 0x6F, 0x5F, 0x7F, 0xFF };
    static unk_D_88218060 D_88218060[] = {
        { 17, D_88218210 },
        { 18, D_88218218 },
    };
    static unk_D_88218070 D_88218070[] = {
        {
            249,
            110,
            54,
            42,
            D_8821B868,
            48,
            D_882181D0,
        },
        {
            249,
            168,
            54,
            42,
            D_8821C5F0,
            48,
            D_882181D8,
        },
    };
    static Color_RGBA8 D_88218098 = { 0xFF, 0xFF, 0x00, 0xFF };

    unk_func_8850BD40* temp_s0_7;
    unk_func_88503298* temp_s0_8;
    unk_func_8850878C* temp_s0_3;
    unk_func_8850878C* temp_s0_4;
    unk_func_885012A4* spB4;
    unk_func_885012A4* spB0;
    unk_func_885012A4* spAC;
    unk_func_885012A4* spA8;
    unk_func_885012A4* spA4;
    unk_func_885012A4* spA0;
    unk_func_885012A4* sp9C;
    WidgetNode* sp98;
    WidgetNode* sp94;
    unk_func_8850BD40* temp_s0_5;
    WidgetAnimatedFrame* temp_s0_6;
    WidgetAnimatedPanel* temp_v0_2;
    WidgetAnimatedPanel* temp_v0_3;
    WidgetAnimatedPanel* temp_v0_4;
    char* sp7C;
    unk_func_8820BE14_02C_038* temp_v0_8;
    s32 i;
    unk_func_882149A0* temp_v0_6;
    unk_func_882170A8* temp_v0_9;
    unk_func_88507D4C* sp68;
    unk_func_88507D4C* sp64;
    unk_func_8850143C* temp_s0;
    unk_func_8850143C* temp_s0_2;
    s32 j;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, 0x78);

    arg0->unk_00.unk_1C = LabItem_BoxScreen_UpdatePageSelection;
    arg0->unk_00.unk_20 = LabItem_BoxScreen_HandleInput;
    arg0->unk_00.unk_24 = LabItem_BoxScreen_SetMenuState;
    // clang-format off
    arg0->unk_00.unk_10.unk_00 = arg1;arg0->unk_00.unk_10.unk_02 = arg2;
    // clang-format on
    arg0->unk_60 = 0;

    ByteMatrix_Allocate(&arg0->unk_64, 2, 0x64, arg5);
    arg0->unk_48 = arg4;

    arg0->unk_4C = mem_pool_alloc(arg5, sizeof(unk_func_8821421C_038_04C));
    LabItem_InitBoxScreenMenu(arg0->unk_4C, arg0);

    arg0->unk_44 = mem_pool_alloc(arg5, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_44, 0, 0, 0x228, 0x162);

    arg0->unk_44->unk_00.unk_28 |= 0x200;
    arg0->unk_44->unk_00.unk_28 |= 0x400;
    arg0->unk_44->unk_00.unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_44);

    sp9C = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp9C, 0, 0, 0x228, 6, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, sp9C);

    spA0 = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spA0, 0, 0x124, 0x228, 6, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, spA0);

    spA4 = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spA4, 0, 6, 6, 0x11E, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, spA4);

    spA8 = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spA8, 0x222, 6, 6, 0x11E, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, spA8);

    spAC = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spAC, 0xF2, 6, 0x44, 0x11E, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, spAC);

    spB0 = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spB0, 6, 6, 0xEC, 0x13, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, spB0);

    spB4 = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spB4, 6, 0x111, 0xEC, 0x13, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, spB4);

    sp94 = mem_pool_alloc(arg5, sizeof(WidgetNode));
    ((func8850AB48)Memmap_GetFragmentVaddr(WidgetTree_InitInsetBorderFrame))(sp94, 4, 0x17, 0xF0, 0xFC);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, sp94);

    sp98 = mem_pool_alloc(arg5, sizeof(WidgetNode));
    ((func8850AB48)Memmap_GetFragmentVaddr(WidgetTree_InitInsetBorderFrame))(sp98, 0x134, 4, 0xF0, 0x122);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, sp98);

    temp_s0 = mem_pool_alloc(arg5, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(WidgetTree_InitPatternTexture))(temp_s0, 0x136, 6, 0xEC, 0x1E, D_88218048, D_8821804C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, temp_s0);

    arg0->unk_2C = mem_pool_alloc(arg5, sizeof(unk_func_8821421C_038_02C));
    LabItem_InitGamePakLabelWidget(arg0->unk_2C, temp_s0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s0, arg0->unk_2C);

    temp_s0_2 = mem_pool_alloc(arg5, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(WidgetTree_InitPatternTexture))(temp_s0_2, 0, 0x12A, 0x228, 0x38, D_88218058, D_8821805C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, temp_s0_2);

    arg0->unk_38 = mem_pool_alloc(arg5, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_38, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s0_2, arg0->unk_38);

    temp_s0_3 = mem_pool_alloc(arg5, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(temp_s0_3, 0x60, 4, Text_GetString(NULL, 0, D_88224FC4, 0x13),
                                                           8);
    temp_s0_3->unk_3C = 0x1C;
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_38, temp_s0_3);

    arg0->unk_3C = mem_pool_alloc(arg5, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_3C, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_38, arg0->unk_3C);

    if (sp94) {}
    if (sp98) {}
    if (sp9C) {}
    if (spA0) {}
    if (spA4) {}
    if (spA8) {}
    if (spAC) {}
    if (spB0) {}
    if (spB4) {}

    for (j = 0; j < 2; j++) {
        temp_s0_4 = mem_pool_alloc(arg5, sizeof(unk_func_8850878C));
        sp7C = Text_GetString(NULL, 0, D_88224FC4, D_88218060[j].unk_00);

        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(temp_s0_4, (0x228 - Font_MeasureTextExtent(0x10, 0, sp7C)) / 2,
                                                               0x10, sp7C, 0x10);

        temp_s0_4->unk_30 = D_88218060[j].unk_04[0];
        temp_s0_4->unk_44 = temp_s0_4->unk_44;
        temp_s0_4->unk_34 = D_88218060[j].unk_04[1];
        temp_s0_4->unk_44 = 1;

        ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_3C, temp_s0_4);
    }

    arg0->unk_40 = mem_pool_alloc(arg5, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_40, 0x60, 4, "ERROR", 8);
    arg0->unk_40->unk_3C = 0x1C;
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_38, arg0->unk_40);

    arg0->unk_34 = mem_pool_alloc(arg5, sizeof(unk_func_8821421C_038_034));
    ((func88506DCC)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGrid))(arg0->unk_34, 6, 0x19, LabItem_DrawGamePakInfoCard, 0xEC, 0x3E, 4, arg5);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_34, 4, arg5);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, arg0->unk_34);

    temp_s0_5 = mem_pool_alloc(arg5, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(temp_s0_5, arg0->unk_34);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_4C, temp_s0_5);

    arg0->unk_4C->unk_28 = mem_pool_alloc(arg5, sizeof(WidgetGridMenu));
    ((func8850C284)Memmap_GetFragmentVaddr(WidgetTree_InitGridMenu))(arg0->unk_4C->unk_28, 3, 1, arg5);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_4C, arg0->unk_4C->unk_28);

    for (i = 0; i < 2; i++) {
        temp_v0_6 = mem_pool_alloc(arg5, sizeof(unk_func_882149A0));
        LabPC_InitTabWidget(temp_v0_6, D_88218070[i].unk_00, D_88218070[i].unk_02, D_88218070[i].unk_04, D_88218070[i].unk_06,
                      D_88218070[i].unk_08, D_88218070[i].unk_0C, D_88218070[i].unk_10[0], D_88218070[i].unk_10[1],
                      D_88218044);

        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, temp_v0_6);

        arg0->unk_4C->unk_28->unk_18[i * arg0->unk_4C->unk_28->unk_2C] = &temp_v0_6->unk_00;
    }

    ((func8850CAB4)Memmap_GetFragmentVaddr(WidgetTree_SelectFirstEnabledGridItem))(arg0->unk_4C->unk_28);

    temp_s0_6 = mem_pool_alloc(arg5, sizeof(WidgetAnimatedFrame));
    ((func88503340)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedFrameVariantA))(temp_s0_6, 0, 0, 0x10, 0x10, D_88218098);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, temp_s0_6);
    arg0->unk_4C->unk_28->unk_1C = temp_s0_6;

    arg0->unk_30 = mem_pool_alloc(arg5, sizeof(unk_func_8820BE14_02C_038));
    LabPC_InitScrollableBoxGrid(arg0->unk_30, 0x136, 0x34, 8, LabItem_DrawItemGridCell, 0xEC, 0x1C, arg5);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_30, 0x64, arg5);

    sp64 = mem_pool_alloc(arg5, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp64, 0x136, 0x24, 0xEC, 0, arg0->unk_30);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, sp64);

    sp68 = mem_pool_alloc(arg5, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(
        sp68, 0x136, arg0->unk_30->unk_00.unk_00.unk_14.unk_02 + 0x34, 0xEC, 1, arg0->unk_30);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, sp68);
    LabPC_BoxGrid_BindMessagePanel(arg0->unk_30, sp68);

    temp_v0_9 = mem_pool_alloc(arg5, sizeof(unk_func_882170A8));
    LabPC_InitPageCounterWidget(temp_v0_9, 0xA8, 2, arg0->unk_30, 3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp68, temp_v0_9);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, arg0->unk_30);

    temp_s0_7 = mem_pool_alloc(arg5, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(temp_s0_7, arg0->unk_30);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_4C, temp_s0_7);

    temp_s0_8 = mem_pool_alloc(arg5, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(temp_s0_8, arg0->unk_44, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, temp_s0_8);

    // Fake, forcing sp64/sp68 onto the stack
    if (0) {
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, &sp64);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_44, &sp68);
    }
}

void LabItem_BindBoxScreenSlot(unk_func_8821421C_038* arg0, unk_func_8821421C_07C* arg1) {
    TableView_Initialize(&arg0->unk_50, arg1, 0x14, 4, 4);

    ((func88506F50)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridStridedData))(arg0->unk_34, &arg0->unk_50);
}

s32 LabItem_BoxScreen_UpdatePageSelection(unk_func_8821421C_038* arg0) {
    UNUSED s32 pad;
    u8* temp_t0;
    char* sp2C;

    switch (arg0->unk_4C->unk_00.unk_1C) {
        case 0:
            ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_38, 0);
            break;

        case 1:
            ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_38, 1);
            ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_3C, arg0->unk_4C->unk_28->unk_24);
            break;

        case 2:
            sp2C = NULL;
            ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_38, 2);
            temp_t0 = &((u8*)arg0->unk_30->unk_00.unk_2C
                            ->unk_00)[arg0->unk_30->unk_00.unk_2C->unk_0C * arg0->unk_30->unk_00.unk_38];
            if (temp_t0 != NULL) {
                sp2C = Text_GetString(NULL, 0, D_88224FCC, temp_t0[0] - 1);
            }
            arg0->unk_40->unk_40 = sp2C;
            break;
    }
    return 0;
}

s32 LabItem_BoxScreen_HandleInput(unk_func_8821421C_038* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_44->unk_30 & 2) {
        var_v1 = arg0->unk_4C->unk_00.unk_10(&arg0->unk_4C->unk_00, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void LabItem_BoxScreen_SetMenuState(unk_func_8821421C_038* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_4C->unk_00.unk_14(&arg0->unk_4C->unk_00, arg1);
}

void LabItem_LoadBoxScreenSlotItems(unk_func_8821421C_038* arg0, s32 arg1) {
    LabItem_ReadDeckEntries(0x12, 0, arg1, &arg0->unk_64);
    LabPC_BindGridStridedData(arg0->unk_30, &arg0->unk_60, arg1 | 0x20000);
}

s32 LabItem_RunBoxScreenModal(unk_func_8821421C_038* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_v0;
    unk_func_8821421C_038_04C* temp_a0;
    s32 var_s0 = 0;

    arg0->unk_4C->unk_00.unk_14(arg0->unk_4C, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_44);

    while (var_s0 == 0) {
        Ui_SendMessageAndPollInput(var_s0);
        temp_v0 = LabItem_BoxScreen_HandleInput(arg0, arg1);

        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                if (arg0->unk_48->unk_30->unk_24 == 0) {
                    var_v0 = 1;
                } else {
                    var_v0 = 0;
                }
                var_s0 = var_v0 + 1;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(temp_v0);
    }

    arg0->unk_44->unk_2C = 0xB;
    return var_s0 - 1;
}

void LabItem_InitBoxScreenMenu(unk_func_8821421C_038_04C* arg0, unk_func_8821421C_038* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(WidgetTree_InitVerticalMenu))(arg0);

    arg0->unk_00.unk_10 = func_88210380;
    arg0->unk_00.unk_24 = arg1;
}

s32 func_88210380(unk_func_8821421C_038_04C* arg0, Controller* arg1) {
    s32 var_v1;
    s32 i;
    unk_func_8821421C_038_04C_000* var_a0;

    var_v1 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_08;
        }
        var_v1 = var_a0->unk_10(var_a0, arg1);
    }
    if (var_v1 & 1) return var_v1;
    if (var_v1 == 0) {
        if (arg1->buttonPressed & 0x4000) var_v1 = 0x80000002;
        else if (arg1->buttonPressed & 0x8000) var_v1 = 0x80000004;
    }
    if (var_v1 & 2) {
        switch (arg0->unk_00.unk_1C) {
            case 1: ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 0); var_v1 |= 1; break;
            case 2: ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1); var_v1 |= 1; break;
        }
    } else if (var_v1 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                LabItem_GamePakLabelWidget_SetSlot(arg0->unk_00.unk_24->unk_2C, arg0->unk_00.unk_24->unk_50[0] + arg0->unk_00.unk_24->unk_34->unk_00.unk_38);
                LabItem_LoadBoxScreenSlotItems(arg0->unk_00.unk_24, arg0->unk_00.unk_24->unk_34->unk_00.unk_38);
                ((func8850CB48)Memmap_GetFragmentVaddr(WidgetTree_SetGridMenuSelection))(arg0->unk_28, 0);
                ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                var_v1 |= 1;
                break;
            case 1:
                switch (arg0->unk_28->unk_24) {
                    case 0: ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 2); var_v1 |= 1; break;
                    case 1:
                        LabItem_SetConfirmDialogText(arg0->unk_00.unk_24->unk_48, Text_GetString(NULL, 0, D_88224FC4, 0x16));
                        ((func8850CB48)Memmap_GetFragmentVaddr(WidgetTree_SetGridMenuSelection))(arg0->unk_00.unk_24->unk_48->unk_30, 1);
                        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                        arg0->unk_28->unk_14(arg0->unk_28, 0x100);
                        if (LabItem_RunConfirmDialog(arg0->unk_00.unk_24->unk_48, arg1) == 1) var_v1 = 4; else var_v1 = 1;
                        arg0->unk_28->unk_14(arg0->unk_28, 1);
                        break;
                }
                break;
            case 2: var_v1 = 1; break;
        }
    }
    return var_v1;
}

void LabItem_InitOperationController(unk_func_8821421C_02C_06C_02C* arg0, unk_func_8820BE14_02C_038* arg1,
                   unk_func_8820BE14_02C_038* arg2, unk_func_8820E99C* arg3, unk_func_88217740* arg4,
                   unk_func_88509F48* arg5, MemoryPool* arg6) {
    static u16 D_8821809C[] = { 8, 9, 0xA, 0xB, 0xC };
    static Color_RGBA8 D_882180A8 = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 i;

    ((func88500668)Memmap_GetFragmentVaddr(WidgetTree_InitNode))(arg0, sizeof(unk_func_8821421C_02C_06C_02C));

    arg0->unk_10 = LabItem_OperationInputHandler;
    arg0->unk_14 = LabItem_OperationController_SetSelectMode;
    arg0->unk_18 = 0;
    arg0->unk_1C = 0;
    arg0->unk_20[0] = arg1;
    arg0->unk_20[1] = arg2;
    arg0->unk_28 = arg3;
    arg0->unk_2C[0] = arg1;
    arg0->unk_2C[1] = arg2;
    arg0->unk_34 = arg3;
    arg0->unk_44 = 1;
    arg0->unk_48 = arg4;
    arg0->unk_4C = arg5;

    LabItem_SetOperationMode(arg0, 0);

    for (i = 0; i < 5; i++) {
        arg0->unk_78[i].unk_00 = mem_pool_alloc(arg6, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_78[i].unk_00, 0, 0,
                                                               Text_GetString(NULL, 0, D_88224FC4, D_8821809C[i]), 0x10);

        arg0->unk_78[i].unk_00->unk_30 = D_882180A8;
        arg0->unk_78[i].unk_00->unk_44 = arg0->unk_78[i].unk_00->unk_44;
        arg0->unk_78[i].unk_08 = 0;
        arg0->unk_78[i].unk_04 = 0;
    }
}

void LabItem_OperationController_SetSelectMode(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1) {
    arg0->unk_18 = arg1;
    LabItem_OperationController_RefreshHighlight(arg0);
}

void LabItem_OperationController_RefreshHighlight(unk_func_8821421C_02C_06C_02C* arg0) {
    s32 i;
    s32 temp_s3 = arg0->unk_18 & 0xFF;
    s32 temp_s4 = arg0->unk_18 & 0xFF00;
    s32 var_v0;

    for (i = 0; i < 3; i++) {
        var_v0 = 0;
        if (i == arg0->unk_1C) {
            var_v0 = 1;
        }
        arg0->unk_20[i]->unk_00.unk_00.unk_24(&arg0->unk_20[i]->unk_00.unk_00, (var_v0 & temp_s3) | temp_s4);
    }
}

void LabItem_OperationController_SetActiveSide(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1) {
    arg0->unk_1C = arg1;
    LabItem_OperationController_RefreshHighlight(arg0);
}

void LabItem_OperationController_SwapSides(unk_func_8821421C_02C_06C_02C* arg0) {
    unk_func_8820BE14_02C_038* temp_t6;
    unk_func_8820BE14_02C_038* temp_t7;

    temp_t6 = arg0->unk_20[0];
    arg0->unk_20[0] = arg0->unk_20[1];
    arg0->unk_20[1] = temp_t6;

    temp_t7 = arg0->unk_2C[0];
    arg0->unk_2C[0] = arg0->unk_2C[1];
    arg0->unk_2C[1] = temp_t7;

    arg0->unk_44 = !arg0->unk_44;
}

void LabItem_GetSelectedEntryPair(unk_func_8821421C_02C_06C_02C* arg0, unk_func_8821421C_02C_06C_02C_060_02C_000** arg1,
                   unk_func_8821421C_02C_06C_02C_060_02C_000** arg2) {
    switch (arg0->unk_38) {
        case 0:
            *arg1 =
                &((u8*)arg0->unk_2C[0]
                      ->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C * arg0->unk_2C[0]->unk_00.unk_38];
            *arg2 = NULL;
            break;

        case 1:
            *arg1 =
                &((u8*)arg0->unk_2C[0]->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C * arg0->unk_40];
            *arg2 =
                &((u8*)arg0->unk_2C[0]
                      ->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C * arg0->unk_2C[0]->unk_00.unk_38];
            break;

        case 2:
            *arg1 =
                &((u8*)arg0->unk_2C[0]
                      ->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C * arg0->unk_2C[0]->unk_00.unk_38];
            *arg2 =
                &((u8*)arg0->unk_2C[1]
                      ->unk_00.unk_2C->unk_00)[arg0->unk_2C[1]->unk_00.unk_2C->unk_0C * arg0->unk_2C[1]->unk_00.unk_38];
            break;
    }
}

void LabItem_GetSelectedSlotPositions(unk_func_8821421C_02C_06C_02C* arg0, WidgetPoint* arg1,
                   WidgetPoint* arg2) {
    s16 var_v1;

    switch (arg0->unk_38) {
        case 0:
            arg1->unk_00 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 =
                arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_2C[0]->unk_5C - arg0->unk_2C[0]->unk_58);

            arg2->unk_00 = arg0->unk_2C[1]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_2C[1]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_2C[1]->unk_5C - arg0->unk_2C[1]->unk_58);
            break;

        case 1:
            var_v1 = (arg0->unk_2C[0]->unk_00.unk_3E * arg0->unk_40) - arg0->unk_2C[0]->unk_58;
            if (var_v1 < -arg0->unk_2C[0]->unk_00.unk_3E) {
                var_v1 = -arg0->unk_2C[0]->unk_00.unk_3E;
            } else if (arg0->unk_2C[0]->unk_00.unk_00.unk_14.unk_02 < var_v1) {
                var_v1 = arg0->unk_2C[0]->unk_00.unk_00.unk_14.unk_02;
            }

            arg1->unk_00 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_02 + var_v1;

            arg2->unk_00 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_2C[0]->unk_5C - arg0->unk_2C[0]->unk_58);
            break;

        case 2:
            arg1->unk_00 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 =
                arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_2C[0]->unk_5C - arg0->unk_2C[0]->unk_58);

            arg2->unk_00 = arg0->unk_2C[1]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_2C[1]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_2C[1]->unk_5C - arg0->unk_2C[1]->unk_58);
            break;
    }
}

void LabItem_OpenQuantitySpinnerForSelection(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1) {
    s32 temp_v1_2;
    s32 var_v1;
    unk_func_8820BE14_06C* temp_v1 = arg0->unk_2C[0]->unk_00.unk_2C;

    LabItem_QuantitySpinner_SetMax(arg0->unk_34, ((u8*)temp_v1->unk_00 + (arg0->unk_2C[0]->unk_00.unk_38 * temp_v1->unk_0C))[1], arg1);

    var_v1 = arg0->unk_2C[0]->unk_5C - arg0->unk_2C[0]->unk_58;

    if (((!(&arg0->unk_2C[0]->unk_00.unk_00)) && (!(&arg0->unk_2C[0]->unk_00.unk_00))) &&
        (!(&arg0->unk_2C[0]->unk_00.unk_00))) {}

    if (var_v1 == 0xC4) {
        var_v1 -= arg0->unk_34->unk_2C->unk_00.unk_14.unk_02;
        var_v1 -= 4;
    } else {
        var_v1 += 0x20;
    }

    arg0->unk_34->unk_00.unk_10.unk_00 =
        0xD3 + (arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_00 - arg0->unk_34->unk_2C->unk_00.unk_14.unk_00);
    arg0->unk_34->unk_00.unk_10.unk_02 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_02 + var_v1 & 0xFFFF;

    LabItem_QuantitySpinner_Open(arg0->unk_34);
}

void LabItem_SetOperationState(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1) {
    switch (arg1) {
        case 0:
            ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_2C[0]);

            LabPC_SetGridBorderActive(&arg0->unk_2C[0]->unk_00, 1);
            LabPC_SetGridBorderActive(&arg0->unk_2C[1]->unk_00, 1);
            LabItem_OperationController_SetActiveSide(arg0, 0);
            LabPC_ModeToggleIcon_ClearPressed(arg0->unk_48);
            break;

        case 4:
            LabItem_OperationController_SetActiveSide(arg0, 2);
            LabPC_ModeToggleIcon_SetPressed(arg0->unk_48);
            break;

        case 1:
            LabPC_ScrollableGrid_SetSwapMode(arg0->unk_2C[1], 0);
            LabPC_SetGridBorderActive(&arg0->unk_2C[1]->unk_00, 0);
            LabItem_OperationController_SetActiveSide(arg0, 1);
            LabPC_ModeToggleIcon_SetPressed(arg0->unk_48);
            break;

        case 2:
            LabPC_SetGridBorderActive(&arg0->unk_2C[0]->unk_00, 0);
            LabItem_OperationController_SetActiveSide(arg0, 0);
            LabPC_ModeToggleIcon_SetPressed(arg0->unk_48);
            break;

        case 3:
            LabPC_SetGridBorderActive(&arg0->unk_2C[1]->unk_00, 0);
            LabItem_OperationController_SetActiveSide(arg0, 1);
            LabPC_ModeToggleIcon_SetPressed(arg0->unk_48);
            break;
    }
    arg0->unk_3C = arg1;
}

void LabItem_SetOperationMode(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1) {
    arg0->unk_38 = arg1;
    LabItem_SetOperationState(arg0, 0);
}

void LabItem_ResetOperation(unk_func_8821421C_02C_06C_02C* arg0) {
    LabItem_SetOperationState(arg0, 0);
    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_2C[1]);
}

s32 LabItem_IsOperationIdle(unk_func_8821421C_02C_06C_02C* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_3C == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_88210DA8(void) {
}

s32 LabItem_ComputeRemainingCapacity(s32 arg0, unk_func_8820BE14_06C* arg1) {
    s32 i;
    s32 var_v1 = 0;
    u8* var_v0 = arg1->unk_00;

    for (i = 0; i < arg1->unk_08; i++, var_v0 += 2) {
        if (arg0 == var_v0[0]) {
            var_v1 = (var_v1 - var_v0[1]) + 0x63;
        }
    }

    return var_v1;
}

s32 LabItem_ComputeMaxTransferQuantity(s32 arg0, unk_func_8820BE14_06C* arg1) {
    s32 var_v1;

    if (LabItem_IsQuantitylessItemForOperation(arg0) != 0) {
        if (arg1->unk_08 < arg1->unk_04) {
            var_v1 = 1;
        } else {
            var_v1 = 0;
        }
    } else if (arg1->unk_08 < arg1->unk_04) {
        var_v1 = 0x63;
    } else {
        var_v1 = LabItem_ComputeRemainingCapacity(arg0, arg1);
    }
    return var_v1;
}

void LabItem_InsertGridEntry(unk_func_8820BE14_02C_038* arg0, u8* arg1) {
    ByteMatrix_InsertRow(arg0->unk_00.unk_2C, arg1, arg0->unk_00.unk_38);
}

void LabItem_RemoveGridEntryAt(unk_func_8820BE14_02C_038* arg0, s32 arg1) {
    s32 sp1C = arg0->unk_00.unk_38;

    ByteMatrix_RemoveRow(arg0->unk_00.unk_2C, arg1);

    if (arg1 < sp1C) {
        sp1C--;
    }

    ((func88507AE4)Memmap_GetFragmentVaddr(WidgetTree_SetScrollableGridIndex))(arg0, sp1C);
}

void LabItem_RemoveSelectedGridEntry(unk_func_8820BE14_02C_038* arg0) {
    s32 sp1C;
    s32 temp_a1;
    s32 var_a1;

    sp1C = arg0->unk_00.unk_38;
    ByteMatrix_RemoveRow(arg0->unk_00.unk_2C, sp1C);
    if ((sp1C > 0) && (sp1C >= arg0->unk_00.unk_2C->unk_08)) {
        sp1C -= 1;
    }
    ((func88507AE4)Memmap_GetFragmentVaddr(WidgetTree_SetScrollableGridIndex))(arg0, sp1C);
}

void func_88210F74(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad;
    s32 i;
    s32 var_s3;
    s32 var_v0;
    unk_func_8821421C_02C_06C_02C_060_02C_000 sp44;
    unk_func_8820BE14_06C* temp_s4;
    void* temp_v1;
    u8* var_s2;

    temp_s4 = arg0->unk_00.unk_2C;
    var_s3 = arg0->unk_00.unk_38;
    temp_v1 = temp_s4->unk_00;
    i = 0;

    if (temp_s4->unk_08 > 0) {
        var_s2 = (u8*)temp_v1;
        do {
            if (arg1 == var_s2[0]) {
                arg2 += var_s2[1];
                ByteMatrix_RemoveRow(temp_s4, i);
                if (i < var_s3) {
                    var_s3--;
                }
            } else {
                i++;
                var_s2 += 2;
            }
        } while (i < temp_s4->unk_08);
    }

    sp44.unk_00 = arg1;

    while (arg2 > 0) {
        if (arg2 < 0x63) {
            var_v0 = arg2;
        } else {
            var_v0 = 0x63;
        }
        arg2 -= var_v0;
        sp44.unk_01 = var_v0;
        ByteMatrix_InsertRow(temp_s4, &sp44, var_s3++);
    }

    ((func88507AE4)Memmap_GetFragmentVaddr(WidgetTree_SetScrollableGridIndex))(arg0, var_s3 - 1);
}

void LabItem_SubtractSelectedItemQuantity(unk_func_8820BE14_02C_038* arg0, s32 arg1) {
    u8* temp_v1 = &((u8*)arg0->unk_00.unk_2C->unk_00)[arg0->unk_00.unk_2C->unk_0C * arg0->unk_00.unk_38];

    if (arg1 >= temp_v1[1]) {
        LabItem_RemoveSelectedGridEntry(arg0);
        return;
    }
    temp_v1[1] -= arg1;
}

void LabItem_MoveSelectedItem(unk_func_8820BE14_02C_038* arg0, unk_func_8820BE14_02C_038* arg1, unk_func_8820E99C* arg2) {
    u8* sp24 = &((u8*)arg0->unk_00.unk_2C->unk_00)[arg0->unk_00.unk_2C->unk_0C * arg0->unk_00.unk_38];

    if (LabItem_IsQuantitylessItemForOperation(sp24[0]) != 0) {
        LabItem_InsertGridEntry(arg1, &((u8*)arg0->unk_00.unk_2C->unk_00)[arg0->unk_00.unk_2C->unk_0C * arg0->unk_00.unk_38]);
        LabItem_RemoveSelectedGridEntry(arg0);
    } else {
        func_88210F74(arg1, sp24[0], arg2->unk_30->unk_30.unk_00);
        LabItem_SubtractSelectedItemQuantity(arg0, arg2->unk_30->unk_30.unk_00);
    }

    *arg1->unk_88 = 1;
    *arg0->unk_88 = *arg1->unk_88;
}

s32 LabItem_CombineStackQuantities(unk_func_8821421C_02C_06C_02C_060_02C_000* arg0, unk_func_8821421C_02C_06C_02C_060_02C_000* arg1) {
    s32 temp_v1 = arg0->unk_01 + arg1->unk_01;
    s32 var_a2;

    if (temp_v1 >= 0x64) {
        var_a2 = temp_v1 - 0x63;
    } else {
        var_a2 = 0;
    }

    arg0->unk_01 = temp_v1 - var_a2;
    arg1->unk_01 = var_a2;
    return var_a2;
}

void func_882111F8(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2) {
    unk_func_8821421C_02C_06C_02C_060_02C_000* ptr = arg0->unk_00.unk_2C->unk_00;
    unk_func_8821421C_02C_06C_02C_060_02C_000 sp30;
    unk_func_8821421C_02C_06C_02C_060_02C_000 sp2C;
    s32 var_v1;
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp20;

    sp20 = ptr;
    sp20 += arg1;
    sp30 = *sp20;
    sp2C = ptr[arg2];

    if ((LabItem_IsQuantitylessItemForOperation(sp30.unk_00) == 0) && (sp30.unk_00 == sp2C.unk_00)) {
        var_v1 = LabItem_CombineStackQuantities(&sp30, &sp2C);
    } else {
        var_v1 = 1;
    }

    *sp20 = sp2C;
    ptr[arg2] = sp30;

    if (var_v1 == 0) {
        LabItem_RemoveGridEntryAt(arg0, arg1);
    }

    *arg0->unk_88 = 1;
}

void LabItem_SwapEntries(unk_func_8820BE14_02C_038* arg0, unk_func_8820BE14_02C_038* arg1) {
    unk_func_8821421C_02C_06C_02C_060_02C_000* temp_v0 = arg0->unk_00.unk_2C->unk_00;
    unk_func_8821421C_02C_06C_02C_060_02C_000* temp_v1 = arg1->unk_00.unk_2C->unk_00;
    unk_func_8821421C_02C_06C_02C_060_02C_000 sp4;

    sp4 = temp_v1[arg1->unk_00.unk_38];
    temp_v1[arg1->unk_00.unk_38] = temp_v0[arg0->unk_00.unk_38];
    temp_v0[arg0->unk_00.unk_38] = sp4;

    *arg1->unk_88 = 1;
    *arg0->unk_88 = *arg1->unk_88;
}

void LabItem_CommitMove(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1) {
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp3C;
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp38;
    unk_func_8821421C_02C_06C_02C_060_02C sp34;
    WidgetPoint sp30;
    WidgetPoint sp2C;

    LabItem_GetSelectedEntryPair(arg0, &sp38, &sp3C);

    sp34.unk_00 = *sp38;

    if (LabItem_IsQuantitylessItemForOperation(sp38->unk_00) == 0) {
        sp34.unk_00.unk_01 = arg0->unk_34->unk_30->unk_30.unk_00;
    }

    LabItem_ItemRowWidget_SetItem(arg0->unk_60[0], sp34.unk_00);
    LabItem_GetSelectedSlotPositions(arg0, &sp30, &sp2C);
    LabPC_FlyingIconWidget_Start(arg0->unk_58[0], sp30, sp2C);

    if (sp38->unk_01 != sp34.unk_00.unk_01) {
        sp34.unk_02.unk_00 = sp34.unk_00.unk_00;
        sp34.unk_02.unk_01 = sp38->unk_01 - sp34.unk_00.unk_01;
        LabItem_ItemRowWidget_SetItem(arg0->unk_70[0], sp34.unk_02);
        LabPC_SlideIconWidget_Start(arg0->unk_68[0], sp30);
    }

    arg0->unk_14(arg0, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(WidgetTree_RunChildWidgetGroup))(arg0->unk_50, arg1);

    arg0->unk_14(arg0, 1);

    LabItem_MoveSelectedItem(arg0->unk_2C[0], arg0->unk_2C[1], arg0->unk_34);
    LabItem_ResetOperation(arg0);
}

void LabItem_CommitReorder(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1) {
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp34;
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp30;
    unk_func_8821421C_02C_06C_02C_060_02C sp2C;
    WidgetPoint sp28;
    WidgetPoint sp24;

    LabItem_GetSelectedEntryPair(arg0, &sp30, &sp34);

    sp2C.unk_00 = *sp30;
    sp2C.unk_02 = *sp34;

    LabItem_GetSelectedSlotPositions(arg0, &sp28, &sp24);

    if ((LabItem_IsQuantitylessItemForOperation(sp2C.unk_00.unk_00) == 0) && (sp2C.unk_02.unk_00 == sp2C.unk_00.unk_00)) {
        if (LabItem_CombineStackQuantities(&sp2C.unk_00, &sp2C.unk_02) > 0) {
            LabItem_ItemRowWidget_SetItem(arg0->unk_70[1], sp2C.unk_02);
            LabPC_SlideIconWidget_Start(arg0->unk_68[1], sp28);
        }

        sp2C.unk_00 = *sp30;
        sp2C.unk_00.unk_01 -= sp2C.unk_02.unk_01;

        LabItem_ItemRowWidget_SetItem(arg0->unk_60[0], sp2C.unk_00);
        LabItem_ItemRowWidget_SetItem(arg0->unk_70[0], *sp34);
        LabPC_FlyingIconWidget_Start(arg0->unk_58[0], sp28, sp24);
        LabPC_SlideIconWidget_Start(arg0->unk_68[0], sp24);
    } else {
        LabItem_ItemRowWidget_SetItem(arg0->unk_60[0], sp2C.unk_00);
        LabItem_ItemRowWidget_SetItem(arg0->unk_60[1], sp2C.unk_02);
        LabPC_FlyingIconWidget_Start(arg0->unk_58[0], sp28, sp24);
        LabPC_FlyingIconWidget_Start(arg0->unk_58[1], sp24, sp28);
    }

    arg0->unk_14(arg0, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(WidgetTree_RunChildWidgetGroup))(arg0->unk_50, arg1);

    arg0->unk_14(arg0, 1);

    func_882111F8(arg0->unk_2C[0], arg0->unk_40, arg0->unk_2C[0]->unk_00.unk_38);
    LabItem_ResetOperation(arg0);
}

void LabItem_CommitExchange(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1) {
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp34;
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp30;
    WidgetPoint sp2C;
    WidgetPoint sp28;

    LabItem_GetSelectedEntryPair(arg0, &sp30, &sp34);

    LabItem_ItemRowWidget_SetItem(arg0->unk_60[0], *sp30);
    LabItem_ItemRowWidget_SetItem(arg0->unk_60[1], *sp34);

    LabItem_GetSelectedSlotPositions(arg0, &sp2C, &sp28);
    LabPC_FlyingIconWidget_Start(arg0->unk_58[0], sp2C, sp28);
    LabPC_FlyingIconWidget_Start(arg0->unk_58[1], sp28, sp2C);

    arg0->unk_14(arg0, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(WidgetTree_RunChildWidgetGroup))(arg0->unk_50, arg1);

    arg0->unk_14(arg0, 1);

    LabItem_SwapEntries(arg0->unk_2C[0], arg0->unk_2C[1]);
    LabItem_ResetOperation(arg0);
}

s32 LabItem_OperationInputHandler(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1) {
    s32 sp2C;
    s32 sp28;
    u8* new_var;
    u8* sp24;
    u8* new_var2;

    sp2C = arg0->unk_20[arg0->unk_1C]->unk_00.unk_00.unk_20(arg0->unk_20[arg0->unk_1C], arg1);
    if (sp2C & 1) {
        return sp2C;
    }

    if (sp2C == 0) {
        if (arg1->buttonPressed & 0x4000) {
            sp2C = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            sp2C = 0x80000004;
        }
    }

    switch (arg0->unk_3C) {
        case 0:
            switch (arg0->unk_38) {
                case 0:
                    if (!(sp2C & 2) && (sp2C & 4)) {
                        new_var =
                            &((u8*)arg0->unk_2C[0]->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C *
                                                                           arg0->unk_2C[0]->unk_00.unk_38];
                        sp24 = new_var;

                        if (arg0->unk_2C[0]->unk_00.unk_2C->unk_08 == 0) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                arg0->unk_4C, arg0->unk_78[0].unk_00, arg0->unk_78[0].unk_04, arg0->unk_78[0].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_4C, arg1);
                            sp2C = 1;
                        } else if ((LabItem_IsQuantitylessItem(sp24[0]) != 0) && ((arg0->unk_2C[1]->unk_8C >> 0x10) == 2)) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                arg0->unk_4C, arg0->unk_78[4].unk_00, arg0->unk_78[4].unk_04, arg0->unk_78[4].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_4C, arg1);
                            sp2C = 1;
                        } else {
                            sp28 = LabItem_ComputeMaxTransferQuantity(sp24[0], arg0->unk_2C[1]->unk_00.unk_2C);
                            if (sp28 == 0) {
                                Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                                ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                    arg0->unk_4C, arg0->unk_78[3].unk_00, arg0->unk_78[3].unk_04,
                                    arg0->unk_78[3].unk_08);
                                ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_4C, arg1);
                                sp2C = 1;
                            } else {
                                arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 2;
                                if (LabItem_IsQuantitylessItemForOperation(sp24[0]) == 0) {
                                    LabItem_OpenQuantitySpinnerForSelection(arg0, sp28);
                                    LabItem_SetOperationState(arg0, 4);
                                    sp2C |= 1;
                                } else {
                                    LabItem_SetOperationState(arg0, 1);
                                    sp2C |= 1;
                                }
                            }
                        }
                    }
                    break;

                case 1:
                    if (!(sp2C & 2) && (sp2C & 4)) {
                        if (arg0->unk_2C[0]->unk_00.unk_2C->unk_08 == 0) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                arg0->unk_4C, arg0->unk_78[1].unk_00, arg0->unk_78[1].unk_04, arg0->unk_78[1].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_4C, arg1);
                            sp2C = 1;
                        } else {
                            arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 2;
                            arg0->unk_40 = arg0->unk_2C[0]->unk_00.unk_38;
                            LabItem_SetOperationState(arg0, 2);
                            sp2C |= 1;
                        }
                    }
                    break;

                case 2:
                    if (!(sp2C & 2) && (sp2C & 4)) {
                        sp24 = &((u8*)arg0->unk_2C[0]->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C *
                                                                              arg0->unk_2C[0]->unk_00.unk_38];
                        if ((arg0->unk_2C[0]->unk_00.unk_2C->unk_08 == 0) ||
                            (arg0->unk_2C[1]->unk_00.unk_2C->unk_08 == 0)) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                arg0->unk_4C, arg0->unk_78[2].unk_00, arg0->unk_78[2].unk_04, arg0->unk_78[2].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_4C, arg1);
                            sp2C = 1;
                        } else if ((LabItem_IsQuantitylessItem(sp24[0]) != 0) && ((arg0->unk_2C[1]->unk_8C >> 0x10) == 2)) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                arg0->unk_4C, arg0->unk_78[4].unk_00, arg0->unk_78[4].unk_04, arg0->unk_78[4].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_4C, arg1);
                            sp2C = 1;
                        } else {
                            arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 2;
                            LabItem_SetOperationState(arg0, 3);
                            sp2C |= 1;
                        }
                    }
                    break;
            }
            break;

        case 4:
            if (sp2C & 2) {
                LabItem_QuantitySpinner_Close(arg0->unk_34);
                LabItem_SetOperationState(arg0, 0);
                sp2C |= 1;
            } else if (sp2C & 4) {
                if (arg0->unk_34->unk_34 < arg0->unk_34->unk_30->unk_30.unk_00) {
                    Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                    ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                        arg0->unk_4C, arg0->unk_78[3].unk_00, arg0->unk_78[3].unk_04, arg0->unk_78[3].unk_08);
                    ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_4C, arg1);
                    arg0->unk_34->unk_30->unk_30.unk_00 = arg0->unk_34->unk_34;
                    sp2C = 1;
                } else {
                    LabItem_SetOperationState(arg0, 1);
                    sp2C |= 1;
                }
            }
            break;

        case 1:
            if (sp2C & 2) {
                if (arg0->unk_34->unk_2C->unk_00.unk_28 & 1) {
                    LabItem_SetOperationState(arg0, 4);
                } else {
                    LabItem_SetOperationState(arg0, 0);
                }
                LabPC_ScrollableGrid_SetSwapMode(arg0->unk_2C[1], 1);
                sp2C |= 1;
            } else if (sp2C & 4) {
                Audio_PlaySoundEffectById(SFX_MOVE_SWAP);
                arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 0x100;
                if (arg0->unk_34->unk_2C->unk_00.unk_28 & 1) {
                    LabItem_QuantitySpinner_Close(arg0->unk_34);
                }
                LabItem_CommitMove(arg0, arg1);
                LabPC_ScrollableGrid_SetSwapMode(arg0->unk_2C[1], 2);
                sp2C = 0x80000081;
            }
            break;

        case 2:
            if (sp2C & 2) {
                LabItem_SetOperationState(arg0, 0);
                sp2C |= 1;
            } else if (sp2C & 4) {
                if (arg0->unk_40 == arg0->unk_2C[arg0->unk_1C]->unk_00.unk_38) {
                    sp2C = 0x80000101;
                } else {
                    Audio_PlaySoundEffectById(SFX_MOVE_SWAP);

                    arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 2;
                    arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_40] |= 0x100;
                    arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 0x100;

                    LabItem_CommitReorder(arg0, arg1);
                    sp2C = 0x80000081;
                }
            }
            break;

        case 3:
            if (sp2C & 2) {
                LabItem_SetOperationState(arg0, 0);
                sp2C |= 1;
            } else if (sp2C & 4) {
                new_var2 = &((u8*)arg0->unk_2C[1]->unk_00.unk_2C->unk_00)[arg0->unk_2C[1]->unk_00.unk_2C->unk_0C *
                                                                          arg0->unk_2C[1]->unk_00.unk_38];
                if ((LabItem_IsQuantitylessItem(new_var2[0]) != 0) && ((arg0->unk_2C[0]->unk_8C >> 0x10) == 2)) {
                    Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                    ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                        arg0->unk_4C, arg0->unk_78[4].unk_00, arg0->unk_78[4].unk_04, arg0->unk_78[4].unk_08);
                    ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_4C, arg1);
                    sp2C = 1;
                } else {
                    Audio_PlaySoundEffectById(SFX_MOVE_SWAP);

                    arg0->unk_2C[1]->unk_00.unk_34[arg0->unk_2C[1]->unk_00.unk_38] |= 2;
                    arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 0x100;
                    arg0->unk_2C[1]->unk_00.unk_34[arg0->unk_2C[1]->unk_00.unk_38] |= 0x100;

                    LabItem_CommitExchange(arg0, arg1);
                    sp2C = 0x80000081;
                }
            }
            break;
    }
    return sp2C;
}

u8* LabItem_GetHighlightedEntry(unk_func_8821421C_02C_06C_02C* arg0) {
    unk_func_8820BE14_06C* temp_a1;
    s32 sp0;
    s32 temp_v1;

    switch (arg0->unk_3C) {
        case 0:
        case 2:
        case 4:
            sp0 = 0;
            break;

        case 1:
            return NULL;

        case 3:
            sp0 = 1;
            break;
    }

    temp_v1 = arg0->unk_2C[sp0]->unk_00.unk_38;
    temp_a1 = arg0->unk_2C[sp0]->unk_00.unk_2C;
    if (temp_v1 >= temp_a1->unk_08) {
        return NULL;
    }
    return &((u8*)temp_a1->unk_00)[temp_a1->unk_0C * temp_v1];
}

void LabItem_BuildOperationNode(unk_func_8821421C_02C* arg0, s32 arg1, s32 arg2, unk_func_8821421C_03C* arg3, s32* arg4,
                   unk_func_8821421C_07C* arg5, WidgetNode* arg6, unk_func_8821421C_038* arg7,
                   unk_func_8821421C_034* arg8, unk_func_88509F48* arg9, s8** argA, MemoryPool* argB) {
    static Color_RGBA8 D_882180AC = { 0x6C, 0x6C, 0x7E, 0xFF };
    static Color_RGBA8 D_882180B0 = { 0x50, 0x50, 0x86, 0xFF };
    static Color_RGBA8 D_882180B4 = { 0x79, 0x79, 0xCB, 0xFF };
    static Color_RGBA8 D_882180B8 = { 0x40, 0x40, 0x6C, 0xFF };
    static Color_RGBA8 D_882180BC = { 0x6A, 0x6A, 0xB2, 0xFF };
    static Color_RGBA8 D_882180C0 = { 0x2D, 0x1A, 0x41, 0xFF };
    static Color_RGBA8 D_882180C4 = { 0x6F, 0x5F, 0x7F, 0xFF };
    static unk_D_88218060 D_882180C8[] = {
        {
            0x00000001,
            D_88218228,
        },
        {
            0x00000002,
            D_88218228,
        },
        {
            0x00000003,
            D_882181F0,
        },
        {
            0x00000004,
            D_88218208,
        },
        {
            0x00000005,
            D_88218200,
        },
        {
            0x00000006,
            D_882181F8,
        },
    };
    static unk_D_88218060 D_882180F8[] = {
        {
            0x00000007,
            D_882181F8,
        },
        {
            0x00000007,
            D_882181F8,
        },
    };
    static unk_D_88217C6C D_88218108[] = {
        {
            249,
            28,
            54,
            42,
            D_8821E100,
            48,
            D_882181E8,
            1,
        },
        {
            249,
            73,
            54,
            42,
            D_8821E100,
            48,
            D_882181E8,
            0,
        },
        {
            249,
            118,
            54,
            42,
            D_88218FD0,
            48,
            D_882181B8,
            0,
        },
        {
            249,
            163,
            54,
            42,
            D_88219D58,
            48,
            D_882181C0,
            1,
        },
        {
            249,
            208,
            54,
            42,
            D_8821AAE0,
            48,
            D_882181C8,
            0,
        },
        {
            249,
            253,
            54,
            42,
            D_88218248,
            48,
            D_882181B0,
            0,
        },
    };
    static Color_RGBA8 D_88218198 = { 0xFF, 0xFF, 0x00, 0xFF };
    static u16 D_8821819C[] = { 0xD };
    static Color_RGBA8 D_882181A0 = { 0xF0, 0xF0, 0xF0, 0xFF };

    UNUSED s32 pad[6];
    s32 i;
    spE8_func_882121E0* spE8;
    char spDC[11];
    unk_func_885012A4* spD8;
    unk_func_885012A4* spD4;
    unk_func_885012A4* spD0;
    unk_func_885012A4* spCC;
    unk_func_885012A4* spC8;
    WidgetNode* spC4;
    WidgetNode* spC0;
    unk_func_8850143C* spBC;
    unk_func_8850143C* spB8;
    unk_func_882170A8* temp_v0_11;
    unk_func_882170A8* temp_v0_9;
    unk_func_8850143C* temp_s0_2;
    char* spA8;
    unk_func_8850878C* temp_s0_3;
    unk_func_8850878C* temp_s0_4;
    char* sp9C;
    WidgetAnimatedFrame* temp_s0_5;
    unk_func_88503298* temp_s0_6;
    unk_func_88507D4C* sp90;
    unk_func_88507D4C* sp8C;
    unk_func_8820E99C* temp_v0_12;
    unk_func_88507D4C* sp84;
    unk_func_88507D4C* sp80;
    s32 j;
    s32 x;
    s32 temp_s0;
    char* temp_s1;
    char* sp6C;

    temp_s0 = GbSave_GetActivePort();

    spE8 = mem_pool_alloc(argB, sizeof(spE8_func_882121E0));
    temp_s1 = mem_pool_alloc(argB, sizeof(char) * 40);

    Text_SetStringToken(0x15, GbSave_GetPlayerName(temp_s0, spDC));

    spE8->unk_00[1] = Text_GetString(temp_s1, sizeof(char) * 40, D_88224FC4, 0xF);
    spE8->unk_00[0] = Text_GetString(NULL, 0, D_88224FC4, 0xE);
    spE8->unk_00[2] = Text_GetString(NULL, 0, D_88224FC4, 0x10);

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, 0xA4);

    arg0->unk_00.unk_1C = LabItem_RefreshDescriptionPanel;
    arg0->unk_00.unk_20 = LabPC_ItemMenu_HandleInput;
    arg0->unk_00.unk_24 = LabItem_SetMenuState;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_78 = arg3;
    arg0->unk_7C = arg4;
    arg0->unk_90 = arg5;
    arg0->unk_84 = arg7;
    arg0->unk_88 = arg8;
    arg0->unk_8C = arg9;
    arg0->unk_80 = 0;

    arg0->unk_6C = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_06C));
    LabItem_InitMenuController(arg0->unk_6C, arg0);

    arg0->unk_2C = mem_pool_alloc(argB, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, 0x228, 0x162);
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    spC8 = mem_pool_alloc(argB, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spC8, 0, 0, 0x228, 6, D_882180AC);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spC8);

    spCC = mem_pool_alloc(argB, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spCC, 0, 0x124, 0x228, 6, D_882180AC);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spCC);

    spD0 = mem_pool_alloc(argB, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spD0, 0, 6, 6, 0x11E, D_882180AC);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spD0);

    spD4 = mem_pool_alloc(argB, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spD4, 0x222, 6, 6, 0x11E, D_882180AC);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spD4);

    spD8 = mem_pool_alloc(argB, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spD8, 0xF2, 6, 0x44, 0x11E, D_882180AC);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spD8);

    spC0 = mem_pool_alloc(argB, sizeof(WidgetNode));
    ((func8850AB48)Memmap_GetFragmentVaddr(WidgetTree_InitInsetBorderFrame))(spC0, 4, 4, 0xF0, 0x122);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spC0);

    spC4 = mem_pool_alloc(argB, sizeof(WidgetNode));
    ((func8850AB48)Memmap_GetFragmentVaddr(WidgetTree_InitInsetBorderFrame))(spC4, 0x134, 4, 0xF0, 0x122);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spC4);

    spB8 = mem_pool_alloc(argB, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(WidgetTree_InitPatternTexture))(spB8, 6, 6, 0xEC, 0x1E, D_882180B0, D_882180B4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spB8);

    spBC = mem_pool_alloc(argB, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(WidgetTree_InitPatternTexture))(spBC, 0x136, 6, 0xEC, 0x1E, D_882180B0, D_882180B4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spBC);

    arg0->unk_30[0] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_030));
    LabItem_InitBoxLocationWidget(arg0->unk_30[0], spB8, spE8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spB8, arg0->unk_30[0]);
    LabItem_BoxLocationWidget_SetSelection(arg0->unk_30[0], 0);

    arg0->unk_30[1] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_030));
    LabItem_InitBoxLocationWidget(arg0->unk_30[1], spBC, spE8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spBC, arg0->unk_30[1]);
    LabItem_BoxLocationWidget_SetSelection(arg0->unk_30[1], 1);

    temp_s0_2 = mem_pool_alloc(argB, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(WidgetTree_InitPatternTexture))(temp_s0_2, 0, 0x12A, 0x228, 0x38, D_882180C0, D_882180C4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, temp_s0_2);

    arg0->unk_5C = mem_pool_alloc(argB, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_5C, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s0_2, arg0->unk_5C);

    arg0->unk_60 = mem_pool_alloc(argB, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_60, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_5C, arg0->unk_60);

    for (i = 0; i < 6; i++) {
        temp_s0_3 = mem_pool_alloc(argB, sizeof(unk_func_8850878C));
        spA8 = Text_GetString(NULL, 0, D_88224FC4, D_882180C8[i].unk_00);
        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(temp_s0_3, (0x228 - Font_MeasureTextExtent(0x10, 0, spA8)) / 2,
                                                               0x10, spA8, 0x10);

        temp_s0_3->unk_30 = D_882180C8[i].unk_04[0];
        temp_s0_3->unk_44 = temp_s0_3->unk_44;
        temp_s0_3->unk_34 = D_882180C8[i].unk_04[1];
        temp_s0_3->unk_44 = 1;

        ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_60, temp_s0_3);
    }

    arg0->unk_64 = mem_pool_alloc(argB, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_64, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_5C, arg0->unk_64);

    for (j = 0; j < 2; j++) {
        temp_s0_4 = mem_pool_alloc(argB, sizeof(unk_func_8850878C));
        sp9C = Text_GetString(NULL, 0, D_88224FC4, D_882180F8[j].unk_00);
        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(temp_s0_4, (0x228 - Font_MeasureTextExtent(0x10, 0, sp9C)) / 2,
                                                               0x10, sp9C, 0x10);

        temp_s0_4->unk_30 = D_882180F8[j].unk_04[0];
        temp_s0_4->unk_44 = temp_s0_4->unk_44;
        temp_s0_4->unk_34 = D_882180F8[j].unk_04[1];
        temp_s0_4->unk_44 = 1;

        ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_64, temp_s0_4);
    }

    arg0->unk_68 = mem_pool_alloc(argB, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_68, 0x60, 4, "ERROR", 8);
    arg0->unk_68->unk_3C = 0x1C;
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_5C, arg0->unk_68);

    arg0->unk_40 = mem_pool_alloc(argB, sizeof(unk_func_88217740));
    LabPC_InitModeToggleIcon(arg0->unk_40, 0xF4, 5);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_40);

    arg0->unk_6C->unk_28 = mem_pool_alloc(argB, sizeof(WidgetGridMenu));
    ((func8850C284)Memmap_GetFragmentVaddr(WidgetTree_InitGridMenu))(arg0->unk_6C->unk_28, 6, 1, argB);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_6C, arg0->unk_6C->unk_28);

    for (x = 0; x < 6; x++) {
        arg0->unk_44[x] = mem_pool_alloc(argB, sizeof(unk_func_882149A0));

        LabPC_InitTabWidget(arg0->unk_44[x], D_88218108[x].unk_00, D_88218108[x].unk_02, D_88218108[x].unk_04,
                      D_88218108[x].unk_06, D_88218108[x].unk_08, D_88218108[x].unk_0C, D_88218108[x].unk_10[0],
                      D_88218108[x].unk_10[1], D_882180AC);

        if (D_88218108[x].unk_14 != 0) {
            LabPC_TabWidget_ToggleFlip(arg0->unk_44[x]);
        }

        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_44[x]);

        arg0->unk_6C->unk_28->unk_18[x * arg0->unk_6C->unk_28->unk_2C] = arg0->unk_44[x];
    }

    ((func8850CB48)Memmap_GetFragmentVaddr(WidgetTree_SetGridMenuSelection))(arg0->unk_6C->unk_28, 2);

    temp_s0_5 = mem_pool_alloc(argB, sizeof(WidgetAnimatedFrame));
    ((func88503340)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedFrameVariantA))(temp_s0_5, 0, 0, 0x10, 0x10, D_88218198);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, temp_s0_5);
    arg0->unk_6C->unk_28->unk_1C = temp_s0_5;

    arg0->unk_38[0] = mem_pool_alloc(argB, sizeof(unk_func_8820BE14_02C_038));
    LabPC_InitScrollableBoxGrid(arg0->unk_38[0], 6, 0x34, 8, LabItem_DrawItemGridCell, 0xEC, 0x1C, argB);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_38[0], 0x64, argB);
    LabPC_BindGridStridedData(arg0->unk_38[0], &arg0->unk_78[0], 0);

    sp8C = mem_pool_alloc(argB, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp8C, 6, 0x24, 0xEC, 0, arg0->unk_38[0]);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp8C);

    sp90 = mem_pool_alloc(argB, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp90, 6, arg0->unk_38[0]->unk_00.unk_00.unk_14.unk_02 + 0x34,
                                                           0xEC, 1, arg0->unk_38[0]);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp90);
    LabPC_BoxGrid_BindMessagePanel(arg0->unk_38[0], sp90);

    temp_v0_9 = mem_pool_alloc(argB, sizeof(unk_func_882170A8));
    LabPC_InitPageCounterWidget(temp_v0_9, 0xA8, 2, arg0->unk_38[0], 3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp90, temp_v0_9);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_38[0]);

    arg0->unk_38[1] = mem_pool_alloc(argB, sizeof(unk_func_8820BE14_02C_038));
    LabPC_InitScrollableBoxGrid(arg0->unk_38[1], 0x136, 0x34, 8, LabItem_DrawItemGridCell, 0xEC, 0x1C, argB);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_38[1], 0x64, argB);
    LabPC_BindGridStridedData(arg0->unk_38[1], &arg0->unk_78[1], 0x10000);

    sp80 = mem_pool_alloc(argB, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp80, 0x136, 0x24, 0xEC, 0, arg0->unk_38[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp80);

    sp84 = mem_pool_alloc(argB, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(
        sp84, 0x136, arg0->unk_38[1]->unk_00.unk_00.unk_14.unk_02 + 0x34, 0xEC, 1, arg0->unk_38[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp84);
    LabPC_BoxGrid_BindMessagePanel(arg0->unk_38[1], sp84);

    temp_v0_11 = mem_pool_alloc(argB, sizeof(unk_func_882170A8));
    LabPC_InitPageCounterWidget(temp_v0_11, 0xA8, 2, arg0->unk_38[1], 3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp84, temp_v0_11);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_38[1]);

    temp_v0_12 = mem_pool_alloc(argB, sizeof(unk_func_8820E99C));
    LabItem_InitQuantitySpinner(temp_v0_12, 0, 0, argB);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, temp_v0_12);

    arg0->unk_6C->unk_2C = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_06C_02C));
    LabItem_InitOperationController(arg0->unk_6C->unk_2C, arg0->unk_38[0], arg0->unk_38[1], temp_v0_12, arg0->unk_40, arg0->unk_8C, argB);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_6C, arg0->unk_6C->unk_2C);

    arg0->unk_6C->unk_2C->unk_50 = mem_pool_alloc(argB, sizeof(unk_func_8850CD44));
    ((func8850CD44)Memmap_GetFragmentVaddr(WidgetTree_InitChildWidgetGroup))(arg0->unk_6C->unk_2C->unk_50, 4, argB);

    for (j = 0; j < 2; j++) {
        arg0->unk_6C->unk_2C->unk_58[j] = mem_pool_alloc(argB, sizeof(unk_func_882173EC));
        LabPC_InitFlyingIconWidget(arg0->unk_6C->unk_2C->unk_58[j], 0, 0);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_6C->unk_2C->unk_58[j]);

        arg0->unk_6C->unk_2C->unk_60[j] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_06C_02C_060));
        LabItem_InitItemRowWidget(arg0->unk_6C->unk_2C->unk_60[j], 0, 0, 0xEC);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_6C->unk_2C->unk_58[j],
                                                               arg0->unk_6C->unk_2C->unk_60[j]);
        arg0->unk_6C->unk_2C->unk_50->unk_1C[j] = arg0->unk_6C->unk_2C->unk_58[j];

        arg0->unk_6C->unk_2C->unk_68[j] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_06C_02C_068));
        LabPC_InitSlideIconWidget(arg0->unk_6C->unk_2C->unk_68[j], 0, 0);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_6C->unk_2C->unk_68[j]);

        arg0->unk_6C->unk_2C->unk_70[j] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_06C_02C_060));
        LabItem_InitItemRowWidget(arg0->unk_6C->unk_2C->unk_70[j], 0, 0, 0xEC);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_6C->unk_2C->unk_68[j],
                                                               arg0->unk_6C->unk_2C->unk_70[j]);

        arg0->unk_6C->unk_2C->unk_50->unk_1C[j + 2] = arg0->unk_6C->unk_2C->unk_68[j];
    }

    arg0->unk_70[0] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_070));
    LabItem_InitDropdownMenu(arg0->unk_70[0], 6, 0x28, 0xEC, spE8, 3, 0, argB);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_70[0]);

    arg0->unk_70[1] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_070));
    LabItem_InitDropdownMenu(arg0->unk_70[1], 0x136, 0x28, 0xEC, spE8, 3, 1, argB);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_70[1]);

    temp_s0_6 = mem_pool_alloc(argB, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(temp_s0_6, arg0->unk_2C, arg6);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, temp_s0_6);

    for (i = 0; i < 1; i++) {
        sp6C = Text_GetString(NULL, 0, D_88224FC4, D_8821819C[i]);

        arg0->unk_94[i].unk_00 = mem_pool_alloc(argB, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_94[i].unk_00, 0, 0, sp6C, 0x10);

        arg0->unk_94[i].unk_00->unk_30 = D_882181A0;
        arg0->unk_94[i].unk_00->unk_44 = arg0->unk_94[i].unk_00->unk_44;
        arg0->unk_94[i].unk_08 = 0;
        arg0->unk_94[i].unk_04 = 0;
    }

    arg0->unk_A0 = mem_pool_alloc(argB, sizeof(unk_func_889000C4));
    ((func889000C4)Memmap_GetFragmentVaddr(LabUI_BuildConfirmDialog))(arg0->unk_A0, 0, arg0->unk_2C, 0, argA, argB);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_A0);

    if (sp80) {}
    if (sp84) {}
    if (sp8C) {}
    if (sp90) {}
    if (spB8) {}
    if (spBC) {}
    if (spC8) {}
    if (spCC) {}
    if (spD0) {}
    if (spD4) {}
    if (spD8) {}
    if (spC0) {}
    if (spC4) {}
}

s32 LabItem_RefreshDescriptionPanel(unk_func_8821421C_02C* arg0) {
    func88500A6C temp_v1_2;
    u8* temp_v0_2;
    char* sp2C;
    s32 var_a1 = arg0->unk_6C->unk_00.unk_1C;

    switch (var_a1) {
        case 0:
            if ((arg0->unk_6C->unk_28->unk_20 == 0x100) && (arg0->unk_6C->unk_28->unk_24 < 2)) {
                ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_5C, 1);
                temp_v1_2 = (func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage);
                if (arg0->unk_6C->unk_28->unk_24 == 0) {
                    var_a1 = 0;
                } else {
                    var_a1 = 1;
                }
                temp_v1_2(arg0->unk_64, var_a1);
            } else {
                ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_5C, 0);
                ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_60, arg0->unk_6C->unk_28->unk_24);
            }
            break;

        case 1:
            sp2C = NULL;
            ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_5C, 2);
            temp_v0_2 = LabItem_GetHighlightedEntry(arg0->unk_6C->unk_2C);
            if (temp_v0_2 != NULL) {
                sp2C = Text_GetString(NULL, 0, D_88224FCC, temp_v0_2[0] - 1);
            }
            arg0->unk_68->unk_40 = sp2C;
            break;
    }
    return 0;
}

s32 LabPC_ItemMenu_HandleInput(unk_func_8821421C_02C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = LabItem_BoxPairMenu_HandleInput(arg0->unk_6C, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 LabPC_ItemMenu_ModalLoop(unk_func_8821421C_02C* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_s4 = 0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);

    while (var_s4 == 0) {
        Ui_SendMessageAndPollInput(NULL);

        temp_v0 = arg0->unk_00.unk_20(arg0, gPlayer1Controller);

        if (!(temp_v0 & 1) && (temp_v0 & 2)) {
            var_s4 = 1;
            break;
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(temp_v0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s4;
}

void LabItem_SetMenuState(unk_func_8821421C_02C* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    ((func8850BF60)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuState))(arg0->unk_6C, arg1);
}

void LabItem_ToggleAllTabFlips(unk_func_8821421C_02C* arg0) {
    LabPC_TabWidget_ToggleFlip(arg0->unk_44[2]);
    LabPC_TabWidget_ToggleFlip(arg0->unk_44[4]);
    LabPC_TabWidget_ToggleFlip(arg0->unk_44[3]);
}

void LabItem_InitMenuController(unk_func_8821421C_02C_06C* arg0, unk_func_8821421C_02C* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(WidgetTree_InitVerticalMenu))(arg0);
    arg0->unk_00.unk_24 = arg1;
}

s32 LabItem_DeckHasChanged(unk_func_8821421C_03C* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 sp40;
    DeckHandle* temp_v0;
    unk_func_8821421C_02C_06C_02C_060_02C_000* var_s0;
    unk_func_8821421C_02C_06C_02C_060_02C_000 sp34;

    sp40 = 0;
    if (arg0->unk_00 == 0) {
        return 0;
    }

    temp_v0 = Deck_Open(arg1, arg2, arg3, 0);
    if (temp_v0 == NULL) {
        return 0;
    }

    arg0->unk_00 = 0;
    if (Deck_GetEntryCountForType(arg1, arg2, arg3) != arg0->unk_04.unk_08) {
        arg0->unk_00 = 1;
        sp40 = 1;
    } else {
        var_s0 = arg0->unk_04.unk_00;
        for (i = 0; i < arg0->unk_04.unk_08; i++, var_s0++) {
            Deck_ReadEntries(&sp34, 1, temp_v0);
            if (bcmp(&sp34, var_s0, sizeof(unk_func_8821421C_02C_06C_02C_060_02C_000)) != 0) {
                arg0->unk_00 = 1;
                sp40 = 1;
                break;
            }
        }
    }

    Deck_CloseAndFlush(temp_v0);
    return sp40;
}

s32 LabItem_CheckDirtyDecks(unk_func_8821421C_02C* arg0) {
    s32 sp24;
    s32 sp20;
    s32 temp_a3;
    s32 temp_v0;
    s32 var_v1;
    s32 var_v1_2;
    unk_func_8821421C_03C* temp_v0_2;

    sp24 = GbSave_GetActivePort();
    sp20 = 0;

    if (LabItem_DeckHasChanged(&arg0->unk_78[0], 0x23, sp24, 0) != 0) {
        sp20 = 1;
    }

    if (LabItem_DeckHasChanged(&arg0->unk_78[1], 0x22, sp24, 0) != 0) {
        sp20 |= 2;
    }

    if (arg0->unk_78[2].unk_00 != 0) {
        if (arg0->unk_90[arg0->unk_7C->unk_00].unk_00 != 0) {
            if (LabItem_DeckHasChanged(&arg0->unk_78[2], 0x12, 0, arg0->unk_7C->unk_00) != 0) {
                sp20 |= 4;
            }
        } else if (arg0->unk_78[2].unk_04.unk_08 > 0) {
            sp20 |= 4;
        } else {
            arg0->unk_78[2].unk_00 = 0;
        }
    }
    return sp20;
}

void LabItem_CommitChanges(unk_func_8821421C_02C* arg0, s32 arg1) {
    s32 sp4C = GbSave_GetActivePort();
    char sp40[11];

    ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_A0->unk_40, 2);
    Ui_SendMessageAndPollInput(NULL);

    if (arg0->unk_78[0].unk_00 != 0) {
        LabItem_WriteDeckBack(0x23, sp4C, 0, &arg0->unk_78[0].unk_04, 0, NULL, -1);
    }

    if (arg0->unk_78[1].unk_00 != 0) {
        LabItem_WriteDeckBack(0x22, sp4C, 0, &arg0->unk_78[1].unk_04, 0, NULL, -1);
    }

    if (arg0->unk_78[2].unk_00 != 0) {
        if (arg0->unk_90[arg0->unk_7C->unk_00].unk_00 != 0) {
            if (arg0->unk_78[2].unk_04.unk_08 == 0) {
                Save_ResetAndCommitTypedRecord(0x12, arg0->unk_7C->unk_00);
            } else {
                LabItem_WriteDeckBack(0x12, 0, arg0->unk_7C->unk_00, &arg0->unk_78[2].unk_04, 0, NULL, -1);
            }
        } else {
            LabItem_WriteDeckBack(0x12, 0, arg0->unk_7C->unk_00, &arg0->unk_78[2].unk_04, 0, GbSave_GetPlayerName(sp4C, sp40),
                          GbSave_GetTrainerId(sp4C));
        }
    }

    if (arg1 & 4) {
        Save_FlushBank(3);
    }

    if (arg1 & 3) {
        ((func88900970)Memmap_GetFragmentVaddr(LabUI_ShowSavingPrompt))(arg0->unk_A0, sp4C);
    }

    if (arg1 & 4) {
        Save_CommitBankRecords(3);
        Save_FlushBank(3);
    }
}

s32 LabItem_RunConfirmSaveFlow(unk_func_8821421C_02C* arg0, Controller* arg1) {
    s32 sp24 = 1;
    s32 sp20 = LabItem_CheckDirtyDecks(arg0);
    s32 temp_v0_2;

    if (sp20 != 0) {
        arg0->unk_6C->unk_28->unk_14(arg0->unk_6C->unk_28, 0);

        ((func889006D4)Memmap_GetFragmentVaddr(LabUI_OpenConfirmDialog))(arg0->unk_A0, 0);
        temp_v0_2 = ((func88900808)Memmap_GetFragmentVaddr(LabUI_RunConfirmDialog))(arg0->unk_A0, arg1, 1);

        if (temp_v0_2 == 0) {
            LabItem_CommitChanges(arg0, sp20);
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_A0);
        } else if (temp_v0_2 == 1) {
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_A0);
        } else if (temp_v0_2 == 2) {
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_A0);
            sp24 = 0;
        }

        arg0->unk_6C->unk_28->unk_14(arg0->unk_6C->unk_28, 1);
    }
    return sp24;
}

s32 LabItem_BoxPairMenu_HandleInput(unk_func_8821421C_02C_06C* arg0, Controller* arg1) {
    s32 i;
    s32 var_a1;
    s32 var_s0;
    unk_func_8821421C_02C_06C_000* var_a0;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;

    var_s0 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_08;
        }
        var_s0 = var_a0->unk_10(var_a0, arg1);
    }

    if (var_s0 & 1) {
        return var_s0;
    }

    if (var_s0 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_s0 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_s0 = 0x80000004;
        } else if (arg1->buttonPressed & 0x30) {
            var_s0 = 0x01000000;
        }
    }

    if (var_s0 & 2) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
                var_s0 = 2;
                if (LabItem_RunConfirmSaveFlow(arg0->unk_00.unk_24, arg1) == 0) {
                    var_s0 = 3;
                }
                break;

            case 1:
                ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 0);
                var_s0 |= 1;
                break;
        }
    } else if (var_s0 & 4) {
        if (arg0->unk_00.unk_1C == 0) {
            switch (arg0->unk_28->unk_24) {
                case 0:
                case 1:
                    if (arg0->unk_28->unk_24 == 0) {
                        sp4C = 0;
                    } else {
                        sp4C = 1;
                    }
                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);

                    arg0->unk_28->unk_14(arg0->unk_28, 0x100);

                    LabItem_DropdownMenu_SetSelection(arg0->unk_00.unk_24->unk_70[sp4C], LabItem_BoxLocationWidget_GetSelection(arg0->unk_00.unk_24->unk_30[sp4C]));
                    LabItem_DropdownMenu_SetDisabledIndex(arg0->unk_00.unk_24->unk_70[sp4C],
                                  LabItem_BoxLocationWidget_GetSelection(arg0->unk_00.unk_24->unk_30[1 - sp4C]));
                    LabItem_DropdownMenu_Open(arg0->unk_00.unk_24->unk_70[sp4C]);

                    while (LabItem_RunDropdownMenuModal(arg0->unk_00.unk_24->unk_70[sp4C], arg1) == 1) {
                        sp48 = LabItem_DropdownMenu_GetSelectedIndex(arg0->unk_00.unk_24->unk_70[sp4C]);
                        if ((sp48 == 2) && (arg0->unk_00.unk_24->unk_7C->unk_00 == -1)) {
                            arg0->unk_00.unk_24->unk_70[sp4C]->unk_00.unk_24(&arg0->unk_00.unk_24->unk_70[sp4C]->unk_00,
                                                                             0x100);

                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                arg0->unk_00.unk_24->unk_8C, arg0->unk_00.unk_24->unk_94[0].unk_00,
                                arg0->unk_00.unk_24->unk_94[0].unk_04, arg0->unk_00.unk_24->unk_94[0].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_00.unk_24->unk_8C, arg1);

                            if (LabItem_RunBoxScreenModal(arg0->unk_00.unk_24->unk_84, arg1) == 1) {
                                LabItem_BoxLocationWidget_SetSelection(arg0->unk_00.unk_24->unk_30[sp4C], 2);

                                arg0->unk_00.unk_24->unk_7C->unk_00 =
                                    arg0->unk_00.unk_24->unk_84->unk_34->unk_00.unk_38;
                                arg0->unk_00.unk_24->unk_90[arg0->unk_00.unk_24->unk_7C->unk_00].unk_00 = 0;

                                LabPC_BindGridStridedData(arg0->unk_00.unk_24->unk_38[sp4C], &arg0->unk_00.unk_24->unk_78[2],
                                              arg0->unk_00.unk_24->unk_7C->unk_00 | 0x20000);
                            } else {
                                arg0->unk_00.unk_24->unk_70[sp4C]->unk_00.unk_24(
                                    &arg0->unk_00.unk_24->unk_70[sp4C]->unk_00, 1);
                                continue;
                            }
                            break;
                        } else {
                            LabItem_BoxLocationWidget_SetSelection(arg0->unk_00.unk_24->unk_30[sp4C], sp48);
                            LabPC_BindGridStridedData(arg0->unk_00.unk_24->unk_38[sp4C], &arg0->unk_00.unk_24->unk_78[sp48].unk_00,
                                          sp48 << 0x10);
                            break;
                        }
                    }

                    LabItem_DropdownMenu_Close(arg0->unk_00.unk_24->unk_70[sp4C]);
                    arg0->unk_28->unk_14(arg0->unk_28, 1);
                    var_s0 = 1;
                    break;

                case 2:
                    LabItem_SetOperationMode(arg0->unk_2C, 0);
                    ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                    var_s0 |= 1;
                    break;

                case 3:
                    LabItem_SetOperationMode(arg0->unk_2C, 1);
                    ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                    var_s0 |= 1;
                    break;

                case 4:
                    LabItem_SetOperationMode(arg0->unk_2C, 2);
                    ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                    var_s0 |= 1;
                    break;

                case 5:
                    Audio_PlaySoundEffectById(SFX_MENU_BACK);
                    var_s0 = 2;
                    if (LabItem_RunConfirmSaveFlow(arg0->unk_00.unk_24, arg1) == 0) {
                        var_s0 = 3;
                    }
                    break;
            }
        }
    } else if (var_s0 & 0x01000000) {
        var_s0 = 1;
        sp40 = arg0->unk_2C->unk_44;
        sp44 = (arg1->buttonPressed & 0x20) != 0;

        switch (arg0->unk_00.unk_1C) {
            case 0:
                sp40 = sp44;
                break;

            case 1:
                if (LabItem_IsOperationIdle(arg0->unk_2C) != 0) {
                    sp40 = sp44;
                }
                break;
        }

        if (sp40 != arg0->unk_2C->unk_44) {
            LabItem_OperationController_SwapSides(arg0->unk_2C);
            LabItem_ToggleAllTabFlips(arg0->unk_00.unk_24);
            LabPC_ModeToggleIcon_ToggleMode(&arg0->unk_00.unk_24->unk_40->unk_00);
            ((func8850BFB0)Memmap_GetFragmentVaddr(WidgetTree_UpdateVerticalMenuItems))(arg0);
            var_s0 = 0x80000005;
        }
    }

    return var_s0;
}

void LabPC_BuildItemScreenWidget(unk_func_8821421C* arg0, s32 arg1, s32 arg2, MemoryPool* arg3, s32 arg4, char** arg5) {
    static Color_RGBA8 D_882181A4 = { 0x1E, 0x50, 0x50, 0xFF };
    static Color_RGBA8 D_882181A8 = { 0x00, 0x0A, 0x0A, 0xFF };

    WidgetNode* sp8C;
    WidgetNode* sp88;
    s32 sp84;
    char sp78[11];
    UNUSED s32 pad[2];
    s32 i;
    unk_func_88500EE4* sp68;
    unk_func_885088F4* sp64;
    unk_func_88509A2C* sp60;
    unk_func_88509E34* sp5C;

    sp84 = GbSave_GetActivePort();
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8821421C));
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    for (i = 0; i < 3; i++) {
        arg0->unk_3C[i].unk_00 = 0;
    }

    ByteMatrix_Allocate(&arg0->unk_3C[0].unk_04, 2, 0x14, arg3);
    ByteMatrix_Allocate(&arg0->unk_3C[1].unk_04, 2, 0x32, arg3);
    ByteMatrix_Allocate(&arg0->unk_3C[2].unk_04, 2, 0x64, arg3);

    LabItem_ReadDeckEntries(0x23, sp84, 0, &arg0->unk_3C[0].unk_04);
    LabItem_ReadDeckEntries(0x22, sp84, 0, &arg0->unk_3C[1].unk_04);

    LabItem_LoadGamePakBoxSlots(arg0->unk_7C);

    arg0->unk_78 = LabItem_FindOrAllocateGamePakBoxSlot(arg0->unk_7C, GbSave_GetTrainerId(sp84), GbSave_GetPlayerName(sp84, sp78));
    if ((arg0->unk_78 != -1) && (arg0->unk_7C[arg0->unk_78].unk_00 != 0)) {
        LabItem_ReadDeckEntries(0x12, 0, arg0->unk_78, &arg0->unk_3C[2].unk_04);
    }

    sp8C = mem_pool_alloc(arg3, sizeof(WidgetNode));
    ((func885031E8)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGate))(sp8C, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, sp8C);

    sp68 = mem_pool_alloc(arg3, sizeof(unk_func_88500EE4));
    ((func88500EE4)Memmap_GetFragmentVaddr(WidgetTree_InitTintedTexture))(sp68, 0, 0, 0x280, 0x1E0, D_88223E48, D_882181A4,
                                                           D_882181A8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp8C, sp68);

    sp64 = mem_pool_alloc(arg3, sizeof(unk_func_885088F4));
    ((func885088F4)Memmap_GetFragmentVaddr(WidgetTree_InitSlideTransition))(sp64, 0x41, 0x15C, 0xDC);
    sp64->unk_2C = 5;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp8C, sp64);

    sp60 = mem_pool_alloc(arg3, sizeof(unk_func_88509A2C));
    ((func88509A2C)Memmap_GetFragmentVaddr(WidgetTree_InitSaveSlotLabel))(sp60, 0x38, 0x22, GbSave_GetActivePort(),
                                                           Text_GetString(NULL, 0, D_88224FC0, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, sp60);

    sp5C = mem_pool_alloc(arg3, sizeof(unk_func_88509E34));
    ((func88509E34)Memmap_GetFragmentVaddr(WidgetTree_InitTextMessage))(sp5C, 0, 0, Text_GetString(NULL, 0, D_88224FC4, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, sp5C);

    arg0->unk_34 = mem_pool_alloc(arg3, sizeof(unk_func_8821421C_034));
    LabItem_InitConfirmDialog(arg0->unk_34, 0xBA, 0xAE, arg3);

    sp88 = mem_pool_alloc(arg3, sizeof(WidgetNode));
    ((func885031E8)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGate))(sp88, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, sp88);

    arg0->unk_38 = mem_pool_alloc(arg3, sizeof(unk_func_8821421C_038));
    LabItem_InitBoxScreen(arg0->unk_38, 0x2C, 0x4B, sp88, arg0->unk_34, arg3);
    LabItem_BindBoxScreenSlot(arg0->unk_38, &arg0->unk_7C);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_88509F48));
    ((func88509F48)Memmap_GetFragmentVaddr(WidgetTree_InitMessagePanel))(arg0->unk_30, 0x2C, 0x4B, 0x228, 0x162, arg3, arg4);

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(unk_func_8821421C_02C));
    LabItem_BuildOperationNode(arg0->unk_2C, 0x2C, 0x4B, arg0->unk_3C, &arg0->unk_78, arg0->unk_7C, sp8C, arg0->unk_38, arg0->unk_34,
                  arg0->unk_30, arg5, arg3);

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp88, arg0->unk_2C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_38);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_34);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_30);
}

void LabPC_ItemScreen_DrawLoop(unk_func_8821421C* arg0) {
    s32 sp34 = 0;

    while (sp34 == 0) {
        BgStage_DrawFrame();

        ((func885008C4)Memmap_GetFragmentVaddr(WidgetTree_Update))(arg0);
        ((func88500828)Memmap_GetFragmentVaddr(WidgetTree_Draw))(arg0, 0, 0);

        BgStage_AdvanceFrame();
        Ui_ReceiveMessage(&sp34);
    }
}

void LabPC_ItemScreen_InputThread(unk_func_8821421C* arg0) {
    s32 sp24 = LabPC_ItemMenu_ModalLoop(arg0->unk_2C, gPlayer1Controller);

    while (arg0->unk_2C->unk_2C->unk_00.unk_28 & 1) {
        Ui_SendMessageAndPollInput(0);
    }

    Ui_SendMessageAndPollInput(sp24);

    osStopThread(NULL);
}

void LabPC_ShowItems(UNUSED FontContext* arg0) {
    MemoryPool* sp34;
    void* sp30;
    u8* sp2C;
    func_88002628_sp38* sp28;
    char** sp24;

    main_pool_push_state('OTPC');

    sp2C = main_pool_alloc(0x10000, 0);
    sp34 = mem_pool_try_init(0x10000, 0);

    Text_InitStringTables();

    D_88224FC0 = Text_GetStringTable(0x2A);
    D_88224FC4 = Text_GetStringTable(3);
    D_88224FC8 = Text_GetStringTable(0x27);
    D_88224FCC = Text_GetStringTable(0xC);
    sp24 = Text_GetStringTable(7);

    sp30 = mem_pool_alloc(sp34, sizeof(unk_func_8821421C));
    LabPC_BuildItemScreenWidget(sp30, 0, 0, sp34, arg0, sp24);

    sp28 = ALIGN16((u32)mem_pool_alloc(sp34, sizeof(func_88002628_sp38)));

    osCreateThread(&sp28->thread, 0x32, LabPC_ItemScreen_InputThread, sp30, sp2C + 0x10000, osGetThreadPri(NULL) - 1);

    Ui_InitInputMessageQueue();
    Input_SetRepeatController(gPlayer1Controller);

    osStartThread(&sp28->thread);

    LabPC_ItemScreen_DrawLoop(sp30);

    osDestroyThread(&sp28->thread);

    main_pool_pop_state('OTPC');
}
