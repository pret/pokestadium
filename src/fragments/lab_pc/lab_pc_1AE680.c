#include "lab_pc.h"
#include "src/geo_render.h"
#include "src/poke_icon.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/save_data.h"
#include "src/game_state.h"
#include "src/table_view.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/hal_libc.h"
#include "src/fragments/pokemon_lab_support/pokemon_lab_support.h"
#include "src/fragments/widget_tree/widget_tree.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/pokemon_stats.h"

typedef void (*ThreadEntries)(unk_func_8820BE14*);

typedef struct unk_D_88217D10 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
} unk_D_88217D10; // size = 0xC

typedef struct unk_D_88217E40 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8* unk_10;
} unk_D_88217E40; // size = 0x14

typedef struct unk_D_88217EA4 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8* unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ Color_RGBA8* unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u16 unk_18;
} unk_D_88217EA4; // size = 0x1C

typedef struct unk_func_8820634C_arg2_unk0 {
    /* 0x00 */ char pad00[0x8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} unk_func_8820634C_arg2_unk0;

typedef struct unk_func_8820634C_arg2 {
    /* 0x00 */ unk_func_8820634C_arg2_unk0* unk_00;
    /* 0x00 */ char pad04[0x4];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} unk_func_8820634C_arg2; // size = 0x54

void LabPC_PokemonSessionThread(unk_func_8820BE14*);
void LabPC_PrizePokemonThread(unk_func_8820BE14*);
void LabPC_SwapMenu_RefreshHighlight(unk_func_8820B12C_02C*);
s32 LabPC_SwapScreen_UpdatePageSelection(unk_func_8820BE14_02C*);
void LabPC_SwapMenu_SetSelectMode(unk_func_8820B12C_02C*, s32);
void LabPC_SwapMenu_SetState(unk_func_8820B12C_02C*, s32);
s32 LabPC_SwapMenuInput(unk_func_8820B12C_02C*, Controller*);
s32 LabPC_HandleInput(unk_func_8820BE14_02C*, Controller*);
void LabPC_SwapScreen_SetMenuState(unk_func_8820BE14_02C*, s32);
void LabPC_InitSwapController(unk_func_8820B12C*, unk_func_8820BE14_02C*);
s32 LabPC_SwapControllerInput(unk_func_8820B12C*, Controller*);
void LabPC_MonNameLevelWidget_SetMon(unk_func_882079D8* arg0, unk_func_88205880_00D0* arg1);
s32 LabPC_MonNameLevelWidget_Draw(unk_func_882079D8*, s32, s32);
s32 LabPC_BoxTypeSelectorInput(unk_func_8820BE14_02C_078*, Controller*);
s32 LabPC_DrawBoxLocationLabel(unk_func_88208C5C*, s32, s32);
void LabPC_InfoCard_SetMon(unk_func_8820BE14_02C_070* arg0, unk_func_88205880_00D0* arg1);
s32 LabPC_DrawPokemonInfoCard(unk_func_8820BE14_02C_070*, s32, s32);

static char** D_88224FB0;
static char** D_88224FB4;
static char** D_88224FB8;
static char** D_88224FBC;

void func_88206110(BattleMon* arg0) {
    static unk_D_88217D10 D_88217D10[2][9] = {
        {
            { 1, 0x87, 0x21, 0x2D, 0, 0 },
            { 4, 0x87, 0xA, 0x2D, 0, 0 },
            { 7, 0x87, 0x21, 0x27, 0, 0 },
            { 0x6A, 0x1F40, 0x18, 0x60, 0, 0 },
            { 0x6B, 0x1F40, 4, 0x61, 0, 0 },
            { 0x85, 0x3D09, 0x21, 0x1C, 0, 0 },
            { 0x8A, 0x1F40, 0x37, 0x6E, 0, 0 },
            { 0x8C, 0x1F40, 0xA, 0x6A, 0, 0 },
            { 0x36, 0xD2F, 0xA, 0x85, 0, 0 },
        },
        {
            { 1, 0x87, 0x21, 0x2D, 0, 0 },
            { 4, 0x87, 0xA, 0x2D, 0, 0 },
            { 7, 0x87, 0x21, 0x27, 0, 0 },
            { 0x6A, 0x1F40, 0x18, 0x60, 0, 0 },
            { 0x6B, 0x1F40, 4, 0x61, 0, 0 },
            { 0x85, 0x3D09, 0x21, 0x27, 0, 0 },
            { 0x8A, 0x1F40, 0x37, 0x6E, 0, 0 },
            { 0x8C, 0x1F40, 0xA, 0x6A, 0, 0 },
            { 0x36, 0xD2F, 0xA, 0x85, 0, 0 },
        },
    };

    s32 i;
    s32 var_a2;
    unk_D_88217D10* var_v0;
    unk_D_88217D10* temp_a1;
    s32 temp_a2;

    bzero(arg0, sizeof(BattleMon));

    arg0->unk_00.unk_00 = (u16)Save_GetSelectedPokemonId();
    var_a2 = GbSave_GetPortGame(GbSave_GetActivePort());
    i = 0;
    if (var_a2 == 7) {
        // FAKE
        if (1) {}
        if (1) {}
        if (1) {}
        if (1) {}
        if (1) {}
        var_a2 = 1;
    } else {
        var_a2 = 0;
    }

    temp_a1 = D_88217D10[var_a2];
    temp_a2 = var_a2;

    for (var_v0 = temp_a1; i < 9; i++, var_v0++) {
        if (var_v0->unk_00 == arg0->unk_00.unk_00) {
            break;
        }
    }

    if (i == 9) {
        i = 0;
        var_v0 = D_88217D10[temp_a2];
    }

    arg0->unk_10 = var_v0->unk_04;
    arg0->unk_09[0] = temp_a1[i].unk_08;
    arg0->unk_09[1] = temp_a1[i].unk_09;
    arg0->unk_09[2] = temp_a1[i].unk_0A;
    arg0->unk_09[3] = temp_a1[i].unk_0B;

    arg0->unk_0E = 0x7D0;
    arg0->unk_14 = 0;
    arg0->unk_16 = 0;
    arg0->unk_18 = 0;
    arg0->unk_1A = 0;
    arg0->unk_1C = 0;

    arg0->unk_1E = (s16)(u16)guRandom();

    arg0->unk_06 = D_80070FA0[arg0->unk_00.unk_00 - 1].unk_06;
    arg0->unk_07 = D_80070FA0[arg0->unk_00.unk_00 - 1].unk_07;

    Pokemon_PrepareBattleMon(arg0);

    arg0->unk_04 = arg0->unk_24;

    HAL_Strcpy(arg0->unk_30, Text_GetString(NULL, 0, D_88224FB8, arg0->unk_00.unk_00 - 1));
    HAL_Strcpy(arg0->unk_3B, Text_GetString(NULL, 0, D_88224FB4, 0x17));

    Pokemon_SetDisplayNameFromOt(arg0);

    if (Save_GetSelectedPokemonId() & 0x100) {
        arg0->unk_08 = 0xA8;
    } else {
        arg0->unk_08 = 0xA7;
    }

    arg0->unk_52 = 0;
    arg0->unk_53 = 0;
    arg0->unk_25 = 0;
}

s32 LabPC_ReadDeckEntries(unk_func_882062E4* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 sp1C = 0;
    DeckHandle* sp18;

    sp18 = Deck_Open(arg2, arg3, arg4, 0);
    if (sp18 != NULL) {
        sp1C = Deck_ReadEntries(arg0, arg1, sp18);
        Deck_CloseAndFlush(sp18);
    }
    return sp1C;
}

static Color_RGBA8 D_88217DE8 = { 0xF0, 0xF0, 0xF0, 0xFF };
static Color_RGBA8 D_88217DEC = { 0xF0, 0xF0, 0xF0, 0x4D };
static Color_RGBA8 D_88217DF0 = { 0xF0, 0xF0, 0x00, 0xFF };

const char D_88224E90[] = "%d";
const char D_88224E94[] = " 00";

void LabPC_DrawBoxNumberCell(s32 arg0, s32 arg1, unk_func_8820634C_arg2* arg2, s32 arg3, s32 arg4, unk_func_88200FA0_030_030* arg5) {
    static Color_RGBA8 D_88217DF4 = { 0x6C, 0x6C, 0x7E, 0xFF };
    Color_RGBA8 sp64;
    s32 pad60[1];
    char* sp5C;
    char sp58[4];
    s32 color;

    sp5C = Text_GetString(0, 0, D_88224FB4, 0x41);
    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, 0, 0);

    color = GPACK_RGBA5551(D_88217DF4.r, D_88217DF4.g, D_88217DF4.b, 1);
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_3C + arg0) - 1, (arg1 + arg5->unk_3E) - 1);
    Font_BeginTranslucentTextRendering();
    if (arg4 & 0x100) {
        sp64 = *(Color_RGBA8 *)&D_88217DF0;
    } else if (arg4 & 4) {
        sp64 = *(Color_RGBA8 *)&D_88217DEC;
    } else {
        sp64 = *(Color_RGBA8 *)&D_88217DE8;
    }
    Gfx_SetEnvColor(sp64.r, sp64.g, sp64.b, sp64.a);
    Font_SetActive(8, 0);

    Font_Printf(arg0 + 8, arg1 + 2, sp5C);
    sprintf(sp58, D_88224E90, (int)arg3 + 1);
    Font_Printf(((arg0 + Font_MeasureTextExtent(0, 0, sp5C) + Font_MeasureTextExtent(0, 0, D_88224E94)) - Font_MeasureTextExtent(0, 0, sp58)) + 8, arg1 + 2, sp58);
    Font_EndTexturedTextRendering();
    LabPC_DrawPageCounterDigits((arg5->unk_3C + arg0) - 0x35, arg1 + 8, arg2->unk_0C, arg2->unk_08, 2);
}


static u8 D_88217DF8[] = {
    0x18,
    0x19,
    0x1A,
};
static Color_RGBA8 D_88217DFC = { 0xF0, 0xF0, 0xF0, 0xFF };
static Color_RGBA8 D_88217E00 = { 0xF0, 0xF0, 0xF0, 0x4D };
static Color_RGBA8 D_88217E04 = { 0xF0, 0xF0, 0x00, 0xFF };

void LabPC_DrawBoxTypeCell(s32 arg0, s32 arg1, unk_func_8820634C_arg2* arg2, s32 arg3, s32 arg4, unk_func_88200FA0_030_030* arg5) {
    static Color_RGBA8 D_88217E08 = { 0x6C, 0x6C, 0x7E, 0xFF };
    unk_func_8820634C_arg2_unk0* temp_v0_7;
    Color_RGBA8 sp48;
    u32 color;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, 0, 0);

    color = GPACK_RGBA5551(D_88217E08.r, D_88217E08.g, D_88217E08.b, 1);
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_3C + arg0) - 1, (arg1 + arg5->unk_3E) - 1);
    Font_BeginTranslucentTextRendering();
    if (arg4 & 0x100) {
        sp48 = *(Color_RGBA8 *)&D_88217E04;
    } else if (arg4 & 4) {
        sp48 = *(Color_RGBA8 *)&D_88217E00;
    } else {
        sp48 = *(Color_RGBA8 *)&D_88217DFC;
    }
    Gfx_SetEnvColor(sp48.r, sp48.g, sp48.b, sp48.a);
    Font_SetActive(8, 0);
    Font_Printf(arg0 + 8, arg1 + 4, Text_GetString(0, 0, D_88224FB4, D_88217DF8[arg3]));
    Font_EndTexturedTextRendering();
    if (arg2->unk_08 == 1) {
        temp_v0_7 = arg2->unk_00;
        LabPC_DrawPageCounterDigits((arg5->unk_3C + arg0) - 0x35, arg1 + 0xA, temp_v0_7->unk_0C, temp_v0_7->unk_08, 2);
    }
}

s32 LabPC_BoxNumberSelectorInput(unk_func_8820BE14_02C_078_034* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 LabPC_RunBoxNumberSelectorModal(WidgetTextList* arg0, Controller* arg1) {
    s32 var_s0;
    s32 var_s1 = 0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);

    while (var_s1 == 0) {
        Ui_SendMessageAndPollInput(var_s1);

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

    arg0->unk_2C->unk_2C = 0xB;
    return var_s1 - 1;
}

s32 LabPC_MeasureBoxNumberWidth(void) {
    s32 tmp;
    s32 sp18;

    sp18 = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_88224FB4, 0x41));
    tmp = Font_MeasureTextExtent(8, 0, " 00");

    return sp18 + tmp + 0x3D;
}

void LabPC_InitBoxNumberSelector(unk_func_8820BE14_02C_078_034* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    s32 sp4C = LabPC_MeasureBoxNumberWidth() + 0x10;
    UNUSED s32 pad[2];

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(&arg0->unk_00, sizeof(unk_func_8820BE14_02C_078_034));

    arg0->unk_00.unk_20 = LabPC_BoxNumberSelectorInput;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, sp4C, 0x120);

    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_30, 0, 0, LabPC_DrawBoxNumberCell, sp4C, 0x18, 0xC, 1, arg3);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_30, 0xC, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_30);
}

s32 LabPC_MeasureBoxTypeLabelWidth(void) {
    static u8 D_88217E0C[3] = { 0x18, 0x19, 0x1A };

    s32 i;
    s32 var_v1;
    s32 var_s1 = 0;

    for (i = 0; i < 3; i++) {
        var_v1 = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_88224FB4, D_88217E0C[i]));

        if (i == 0) {
            var_v1 += 0x3D;
        }

        if (var_s1 < var_v1) {
            var_s1 = var_v1;
        }
    }

    return var_s1;
}

void LabPC_InitBoxTypeSelector(unk_func_8820BE14_02C_078* arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_8820BE14_06C_000* arg4,
                   s32 arg5, MemoryPool* arg6) {
    UNUSED s32 pad;
    s32 sp48 = LabPC_MeasureBoxTypeLabelWidth() + 0x10;
    UNUSED s32 pad2;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(&arg0->unk_00, sizeof(unk_func_8820BE14_02C_078));

    arg0->unk_00.unk_20 = LabPC_BoxTypeSelectorInput;
    arg0->unk_00.unk_10.unk_00 = ((arg3 - sp48) / 2) + arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_4C = arg5;
    arg0->unk_2C = mem_pool_alloc(arg6, sizeof(WidgetAnimatedPanel));

    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, sp48, 0x54);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00, arg0->unk_2C);

    TableView_Initialize(&arg0->unk_38, arg4, 0x10, 3, 3);

    arg0->unk_30 = mem_pool_alloc(arg6, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_30, 0, 0, LabPC_DrawBoxTypeCell, sp48, 0x1C, 3, 1, arg6);
    ((func88506404)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridStridedPage))(arg0->unk_30, &arg0->unk_38, arg6);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_30);

    arg0->unk_34 = mem_pool_alloc(arg6, sizeof(unk_func_8820BE14_02C_078_034));
    LabPC_InitBoxNumberSelector(arg0->unk_34, 0x9C, 0x1C, arg6);

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_34);

    arg0->unk_48 = 0;
}

u32 LabPC_BoxTypeSelector_GetSlotSelection(unk_func_8820BE14_02C_078* arg0) {
    return ((arg0->unk_30->unk_38 == 0) ? 0 : arg0->unk_34->unk_30->unk_38) | (arg0->unk_30->unk_38 << 0x10);
}

void LabPC_BoxTypeSelector_SetSlotASelection(unk_func_8820BE14_02C_078* arg0, u32 arg1) {
    arg0->unk_50 = arg1 >> 0x10;
    arg0->unk_54 = arg1 & 0xFFFF;

    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_30);
    ((func88506BFC)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelection))(arg0->unk_30, arg0->unk_50);

    if (arg0->unk_50 == 0) {
        arg0->unk_30->unk_34[arg0->unk_30->unk_38] |= 0x100;
    }
}

void LabPC_BoxTypeSelector_SetSlotBSelection(unk_func_8820BE14_02C_078* arg0, u32 arg1) {
    arg0->unk_58 = arg1 >> 0x10;
    arg0->unk_5C = arg1 & 0xFFFF;

    if (arg0->unk_58 == 0) {
        arg0->unk_30->unk_34[arg0->unk_58] |= 4;
    }
}

s32 LabPC_BoxTypeSelectorInput(unk_func_8820BE14_02C_078* arg0, Controller* arg1) {
    s32 var_v1;
    s32 sp20;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);

        if (!(var_v1 & 1)) {
            if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            } else if (arg1->buttonPressed & 0x8000) {
                if (arg0->unk_30->unk_38 == 0) {
                    var_v1 = 0x80000004;
                } else {
                    sp20 = 0;

                    ((func885063B8)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridStridedData))(arg0->unk_34->unk_30,
                                                                           &arg0->unk_38.unk_00[arg0->unk_30->unk_38]);

                    if (arg0->unk_4C != 0) {
                        arg0->unk_34->unk_00.unk_10.unk_00 = -arg0->unk_34->unk_2C->unk_00.unk_14.unk_00;
                    } else {
                        arg0->unk_34->unk_00.unk_10.unk_00 = arg0->unk_2C->unk_00.unk_14.unk_00;
                    }

                    arg0->unk_34->unk_00.unk_10.unk_02 = 8;
                    if (arg0->unk_50 == arg0->unk_30->unk_38) {
                        arg0->unk_34->unk_30->unk_34[arg0->unk_54] |= 0x100;
                        sp20 = arg0->unk_54;
                    }

                    if (arg0->unk_58 == arg0->unk_30->unk_38) {
                        arg0->unk_34->unk_30->unk_34[arg0->unk_5C] |= 4;
                        if ((sp20 == 0) && (arg0->unk_5C == 0)) {
                            sp20 = 1;
                        }
                    }

                    ((func88506BFC)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelection))(arg0->unk_34->unk_30, sp20);

                    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);

                    arg0->unk_00.unk_24(&arg0->unk_00, 0x100);

                    if (LabPC_RunBoxNumberSelectorModal(arg0->unk_34, arg1) == 1) {
                        var_v1 = 4;
                    } else {
                        var_v1 = 1;
                    }
                    arg0->unk_00.unk_24(&arg0->unk_00, 1);
                }
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 LabPC_RunBoxTypeSelectorModal(unk_func_8820BE14_02C_078* arg0, Controller* arg1) {
    s32 var_s0;
    s32 var_s1 = 0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);

    while (var_s1 == 0) {
        Ui_SendMessageAndPollInput(var_s1);

        var_s0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(var_s0 & 1)) {
            if (var_s0 & 2) {
                var_s0 |= 1;
                var_s1 = 1;
            } else if (var_s0 & 4) {
                var_s0 |= 1;
                var_s1 = 2;
            }
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(var_s0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s1 - 1;
}

void LabPC_DrawMonNameLevel(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3) {
    static Color_RGBA8 D_88217E10 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88217E14 = { 0x5A, 0x5A, 0xA6, 0xFF };

    s32 temp_v1;

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88217E10.r, D_88217E10.g, D_88217E10.b, D_88217E10.a);
    Font_SetActive(8, 0);
    Font_Printf(arg1 + 0x14, arg2 + 4, arg0->unk_000[0].unk_30);
    Font_SetActive(4, 0);

    temp_v1 = Font_MeasureTextExtent(0, 0, "L100");

    if ((arg0->unk_000[0].unk_00.unk_00 <= 0) || (arg0->unk_000[0].unk_00.unk_00 >= 0x98)) {
        Font_Printf(((arg1 + arg3) - temp_v1) - 0x14, arg2 + 8, "L?");
    } else {
        Font_Printf(((arg1 + arg3) - temp_v1) - 0x14, arg2 + 8, "L%d", arg0->unk_000[0].unk_24);
    }
    Font_EndTexturedTextRendering();
}

void LabPC_DrawSwapBoxLabel(s32 arg0, s32 arg1, unk_func_88205880_00D0* arg2, s32 arg3, s32 arg4, unk_func_88200FA0_030_030* arg5) {
    static Color_RGBA8 D_88217E18 = { 0x40, 0x40, 0x74, 0xFF };
    static Color_RGBA8 D_88217E1C[] = {
        { 0x78, 0x78, 0xF1, 0xFF },
        { 0x5E, 0x5E, 0xBE, 0xFF },
        { 0xFF, 0xCB, 0xDE, 0xFF },
        { 0xFF, 0xBF, 0xD6, 0xFF },
    };
    Color_RGBA8 spD4;
    s32 sp94;
    

    if (arg2 != 0) {
        if (arg4 & 2) {
            spD4 = Color_ScaleRgb(D_88217E18, 1.4f);
        } else {
            spD4 = *(Color_RGBA8 *)&D_88217E18;
        }
        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
        gDPSetRenderMode(gDisplayListHead++, 0, 0);
        {
            
            s32 color = GPACK_RGBA5551(spD4.r, spD4.g, spD4.b, 1);
            gDPPipeSync(gDisplayListHead++);
            gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
            gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, arg0 + 0xCB, arg1 + 0x1A);
        }
        {
            s32 color = GPACK_RGBA5551(D_88217E1C[1].r, D_88217E1C[1].g, D_88217E1C[1].b, 1);
            gDPPipeSync(gDisplayListHead++);
            gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
            gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + 0xCB, arg1);
        }
        {
            s32 color = GPACK_RGBA5551(D_88217E1C[1].r, D_88217E1C[1].g, D_88217E1C[1].b, 1);
            gDPPipeSync(gDisplayListHead++);
            gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
            gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 0x1B, arg0 + 0xCB, arg1 + 0x1B);
        }
        if (!(arg4 & 0x100)) {
            LabPC_DrawMonNameLevel(arg2, arg0, arg1, arg5->unk_3C);
        }
    } else {
        if (arg4 & 1) {
            spD4 = *(Color_RGBA8 *)&D_88217E18;
            gDPPipeSync(gDisplayListHead++);
            gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
            gDPSetRenderMode(gDisplayListHead++, 0, 0);
            {
                s32 color = GPACK_RGBA5551(spD4.r, spD4.g, spD4.b, 1);
                gDPPipeSync(gDisplayListHead++);
                gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
                gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, arg0 + 0xCB, arg1 + 0x1A);
            }
            {
                s32 color = GPACK_RGBA5551(D_88217E1C[1].r, D_88217E1C[1].g, D_88217E1C[1].b, 1);
                gDPPipeSync(gDisplayListHead++);
                gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
                gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + 0xCB, arg1);
            }
            {
                s32 color = GPACK_RGBA5551(D_88217E1C[1].r, D_88217E1C[1].g, D_88217E1C[1].b, 1);
                gDPPipeSync(gDisplayListHead++);
                gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
                gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 0x1B, arg0 + 0xCB, arg1 + 0x1B);
            }
            return;
        }
        spD4 = Color_ScaleRgb(D_88217E18, 0.8f);
        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
        gDPSetRenderMode(gDisplayListHead++, 0, 0);
        {
            s32 color = GPACK_RGBA5551(spD4.r, spD4.g, spD4.b, 1);
            gDPPipeSync(gDisplayListHead++);
            gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
            gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + 0xCB, arg1 + 0x1B);
        }
    }
}


void LabPC_InitMonNameLevelWidget(unk_func_882079D8* arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_88205880_00D0* arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(&arg0->unk_00, sizeof(unk_func_882079D8));

    arg0->unk_00.unk_18 = LabPC_MonNameLevelWidget_Draw;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = 0;

    LabPC_MonNameLevelWidget_SetMon(arg0, arg4);
}

void LabPC_MonNameLevelWidget_SetMon(unk_func_882079D8* arg0, unk_func_88205880_00D0* arg1) {
    arg0->unk_2C = arg1;
}

s32 LabPC_MonNameLevelWidget_Draw(unk_func_882079D8* arg0, s32 arg1, s32 arg2) {
    if (arg0->unk_2C != NULL) {
        LabPC_DrawMonNameLevel(arg0->unk_2C, arg1, arg2, arg0->unk_00.unk_14.unk_00);
    }
}

void LabPC_InitSwapMenu(unk_func_8820B12C_02C* arg0, unk_func_8820B12C_02C_020* arg1, unk_func_8820B12C_02C_020* arg2,
                   unk_func_88217740* arg3, unk_func_88509F48* arg4, s32 arg5, MemoryPool* arg6) {
    static Color_RGBA8 D_88217E2C = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 i;

    ((func88500668)Memmap_GetFragmentVaddr(WidgetTree_InitNode))(arg0, sizeof(unk_func_8820B12C_02C));

    arg0->unk_14 = LabPC_SwapMenu_SetSelectMode;
    arg0->unk_10 = LabPC_SwapMenuInput;
    arg0->unk_18 = 0;
    arg0->unk_1C = 0;
    arg0->unk_20[0] = arg1;
    arg0->unk_20[1] = arg2;
    arg0->unk_34 = 1;
    arg0->unk_38 = arg3;
    arg0->unk_3C = arg4;
    arg0->unk_74 = arg5;

    LabPC_SwapMenu_SetState(arg0, 0);

    for (i = 0; i < 6; i++) {
        arg0->unk_5C[i] = mem_pool_alloc(arg6, sizeof(unk_func_8850878C));

        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_5C[i], 0, 0,
                                                               Text_GetString(NULL, 0, D_88224FB4, i + 0xB), 0x10);

        arg0->unk_5C[i]->unk_30 = D_88217E2C;
        arg0->unk_5C[i]->unk_44 = arg0->unk_5C[i]->unk_44;
    }
}

void LabPC_SwapMenu_NotifyModeChanged(unk_func_8820B12C_02C* arg0, s32 arg1) {
    arg0->unk_48->unk_18 = arg1;
    arg0->unk_44(2, arg0->unk_48);
}

void LabPC_SwapMenu_SetSelectMode(unk_func_8820B12C_02C* arg0, s32 arg1) {
    arg0->unk_18 = arg1;
    LabPC_SwapMenu_RefreshHighlight(arg0);
}

void LabPC_SwapMenu_RefreshHighlight(unk_func_8820B12C_02C* arg0) {
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_v0;
    s32 i;
    s32 var_v0;
    unk_func_8820B12C_02C* var_s1;
    unk_func_8820B12C_02C_020* temp_a0;

    temp_v0 = arg0->unk_18;
    temp_s3 = temp_v0 & 0xFF;
    temp_s4 = temp_v0 & 0xFF00;

    for (i = 0; i < 2; i++) {
        var_v0 = 0;
        if (i == arg0->unk_1C) {
            var_v0 = 1;
        }
        arg0->unk_20[i]->unk_00.unk_00.unk_24(&arg0->unk_20[i]->unk_00, (var_v0 & temp_s3) | temp_s4);
    }
}

void LabPC_SwapMenu_SetActiveSide(unk_func_8820B12C_02C* arg0, s32 arg1) {
    arg0->unk_1C = arg1;
    LabPC_SwapMenu_RefreshHighlight(arg0);
}

void LabPC_SwapMenu_SetState(unk_func_8820B12C_02C* arg0, s32 arg1) {
    arg0->unk_28 = arg1;
    arg0->unk_2C = 0;
}

void LabPC_SwapMenu_SwapSides(unk_func_8820B12C_02C* arg0) {
    unk_func_8820B12C_02C_020* temp_t6 = arg0->unk_20[0];

    arg0->unk_20[0] = arg0->unk_20[1];
    arg0->unk_20[1] = temp_t6;
    arg0->unk_34 = !arg0->unk_34;
}

void LabPC_SwapMenu_GetSelectedMons(unk_func_8820B12C_02C* arg0, unk_func_88205880_00D0** arg1, unk_func_88205880_00D0** arg2) {
    switch (arg0->unk_28) {
        case 0:
        case 3:
            *arg1 = arg0->unk_20[0]->unk_00.unk_2C->unk_00[arg0->unk_20[0]->unk_00.unk_38];
            *arg2 = NULL;
            break;

        case 1:
            *arg1 = arg0->unk_20[0]->unk_00.unk_2C->unk_00[arg0->unk_30];
            *arg2 = arg0->unk_20[0]->unk_00.unk_2C->unk_00[arg0->unk_20[0]->unk_00.unk_38];
            break;

        case 2:
            *arg1 = arg0->unk_20[0]->unk_00.unk_2C->unk_00[arg0->unk_20[0]->unk_00.unk_38];
            *arg2 = arg0->unk_20[1]->unk_00.unk_2C->unk_00[arg0->unk_20[1]->unk_00.unk_38];
            break;
    }
}

void LabPC_SwapMenu_GetSelectedPositions(unk_func_8820B12C_02C* arg0, WidgetPoint* arg1, WidgetPoint* arg2) {
    s16 var_v1;

    switch (arg0->unk_28) {
        case 0:
            arg1->unk_00 = arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 =
                arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_20[0]->unk_5C - arg0->unk_20[0]->unk_58);

            arg2->unk_00 = arg0->unk_20[1]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_20[1]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_20[1]->unk_5C - arg0->unk_20[1]->unk_58);
            break;

        case 1:
            var_v1 = (arg0->unk_20[0]->unk_00.unk_3E * arg0->unk_30) - arg0->unk_20[0]->unk_58;
            if (var_v1 < -arg0->unk_20[0]->unk_00.unk_3E) {
                var_v1 = -arg0->unk_20[0]->unk_00.unk_3E;
            } else if (arg0->unk_20[0]->unk_00.unk_00.unk_14.unk_02 < var_v1) {
                var_v1 = arg0->unk_20[0]->unk_00.unk_00.unk_14.unk_02;
            }

            arg1->unk_00 = arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 = arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_02 + var_v1;

            arg2->unk_00 = arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_20[0]->unk_5C - arg0->unk_20[0]->unk_58);
            break;

        case 2:
            arg1->unk_00 = arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 =
                arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_20[0]->unk_5C - arg0->unk_20[0]->unk_58);

            arg2->unk_00 = arg0->unk_20[1]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_20[1]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_20[1]->unk_5C - arg0->unk_20[1]->unk_58);
            break;
    }
}

void LabPC_SwapMenu_SetPhase(unk_func_8820B12C_02C* arg0, s32 arg1) {
    switch (arg1) {
        case 0:
            ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_20[0]);
            LabPC_SetGridBorderActive(&arg0->unk_20[0]->unk_00, 1);
            LabPC_SetGridBorderActive(&arg0->unk_20[1]->unk_00, 1);
            LabPC_SwapMenu_SetActiveSide(arg0, 0);
            LabPC_ModeToggleIcon_ClearPressed(arg0->unk_38);
            break;

        case 1:
            arg0->unk_20[0]->unk_00.unk_34[arg0->unk_20[0]->unk_00.unk_38] |= 2;
            LabPC_ScrollableGrid_SetSwapMode(arg0->unk_20[1], 0);
            LabPC_SetGridBorderActive(&arg0->unk_20[1]->unk_00, 0);
            LabPC_SwapMenu_SetActiveSide(arg0, 1);
            LabPC_ModeToggleIcon_SetPressed(arg0->unk_38);
            break;

        case 2:
            arg0->unk_20[arg0->unk_1C]->unk_00.unk_34[arg0->unk_20[arg0->unk_1C]->unk_00.unk_38] |= 2;
            LabPC_SetGridBorderActive(&arg0->unk_20[arg0->unk_1C]->unk_00, 0);
            arg0->unk_30 = arg0->unk_20[arg0->unk_1C]->unk_00.unk_38;
            LabPC_ModeToggleIcon_SetPressed(arg0->unk_38);
            break;

        case 3:
            arg0->unk_20[0]->unk_00.unk_34[arg0->unk_20[0]->unk_00.unk_38] |= 2;
            LabPC_SetGridBorderActive(&arg0->unk_20[1]->unk_00, 0);
            LabPC_SwapMenu_SetActiveSide(arg0, 1);
            LabPC_ModeToggleIcon_SetPressed(arg0->unk_38);
            break;
    }

    arg0->unk_2C = arg1;
}

void LabPC_SwapMenu_Reset(unk_func_8820B12C_02C* arg0) {
    LabPC_SwapMenu_SetPhase(arg0, 0);
    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(&arg0->unk_20[1]->unk_00);
}

s32 LabPC_SwapMenu_IsIdle(unk_func_8820B12C_02C* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_2C == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void LabPC_MoveMonToSlot(unk_func_8820B12C_02C_020* arg0, unk_func_8820B12C_02C_020* arg1) {
    unk_func_88205880_00D0* ptr2 = arg0->unk_00.unk_2C->unk_00[arg0->unk_00.unk_38];

    ((func88507CC4)Memmap_GetFragmentVaddr(WidgetTree_SetScrollableGridEntryText))(arg1, ptr2);
    ((func88507CEC)Memmap_GetFragmentVaddr(WidgetTree_RemoveScrollableGridEntry))(arg0);

    *arg1->unk_88 = 1;
    *arg0->unk_88 = *arg1->unk_88;
}

void LabPC_SwapMonsInBox(unk_func_8820B12C_02C_020* arg0, s32 arg1, s32 arg2) {
    unk_func_88205880_00D0* temp_v0 = arg0->unk_00.unk_2C->unk_00[arg1];

    arg0->unk_00.unk_2C->unk_00[arg1] = arg0->unk_00.unk_2C->unk_00[arg2];
    arg0->unk_00.unk_2C->unk_00[arg2] = temp_v0;

    *arg0->unk_88 = 1;
}

void LabPC_ExchangeMonsBetweenBoxes(unk_func_8820B12C_02C_020* arg0, unk_func_8820B12C_02C_020* arg1) {
    unk_func_88205880_00D0* temp_v0 = arg1->unk_00.unk_2C->unk_00[arg1->unk_00.unk_38];
    unk_func_88205880_00D0** temp_v1;

    arg1->unk_00.unk_2C->unk_00[arg1->unk_00.unk_38] = arg0->unk_00.unk_2C->unk_00[arg0->unk_00.unk_38];
    arg0->unk_00.unk_2C->unk_00[arg0->unk_00.unk_38] = temp_v0;

    *arg1->unk_88 = 1;
    *arg0->unk_88 = *arg1->unk_88;
}

void LabPC_RemoveMonFromBox(unk_func_8820B12C_02C_020* arg0) {
    ((func88507CEC)Memmap_GetFragmentVaddr(WidgetTree_RemoveScrollableGridEntry))(arg0);
    *arg0->unk_88 = 1;
}

void LabPC_PerformMove(unk_func_8820B12C_02C* arg0, Controller* arg1) {
    unk_func_88205880_00D0* sp34;
    unk_func_88205880_00D0* sp30;
    WidgetPoint sp2C;
    WidgetPoint sp28;

    LabPC_SwapMenu_GetSelectedMons(arg0, &sp30, &sp34);
    LabPC_MonNameLevelWidget_SetMon(arg0->unk_54[0], sp30);
    LabPC_SwapMenu_GetSelectedPositions(arg0, &sp2C, &sp28);
    LabPC_FlyingIconWidget_Start(arg0->unk_4C[0], sp2C, sp28);

    arg0->unk_14(arg0, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(WidgetTree_RunChildWidgetGroup))(arg0->unk_40, arg1);

    arg0->unk_14(arg0, 1);

    LabPC_MoveMonToSlot(arg0->unk_20[0], arg0->unk_20[1]);
    LabPC_SwapMenu_Reset(arg0);
}

void LabPC_PerformExchange(unk_func_8820B12C_02C* arg0, Controller* arg1, s32 arg2) {
    unk_func_88205880_00D0* sp34;
    unk_func_88205880_00D0* sp30;
    WidgetPoint sp2C;
    WidgetPoint sp28;

    LabPC_SwapMenu_GetSelectedMons(arg0, &sp30, &sp34);
    LabPC_MonNameLevelWidget_SetMon(arg0->unk_54[0], sp30);
    LabPC_MonNameLevelWidget_SetMon(arg0->unk_54[1], sp34);
    LabPC_SwapMenu_GetSelectedPositions(arg0, &sp2C, &sp28);
    LabPC_FlyingIconWidget_Start(arg0->unk_4C[0], sp2C, sp28);
    LabPC_FlyingIconWidget_Start(arg0->unk_4C[1], sp28, sp2C);

    arg0->unk_14(arg0, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(WidgetTree_RunChildWidgetGroup))(arg0->unk_40, arg1);

    arg0->unk_14(arg0, 1);

    if (arg2 != 0) {
        LabPC_SwapMonsInBox(arg0->unk_20[0], arg0->unk_30, arg0->unk_20[0]->unk_00.unk_38);
    } else {
        LabPC_ExchangeMonsBetweenBoxes(arg0->unk_20[0], arg0->unk_20[1]);
    }

    LabPC_SwapMenu_Reset(arg0);
}

void LabPC_PerformReleaseOrReceive(unk_func_8820B12C_02C* arg0) {
    unk_func_88205880_00D0* sp2C;
    unk_func_88205880_00D0* sp28;
    s32 sp24;

    LabPC_SwapMenu_GetSelectedMons(arg0, &sp28, &sp2C);

    arg0->unk_48->unk_0C = sp28;
    arg0->unk_48->unk_10 = arg0->unk_20[0]->unk_8C >> 0x10;

    arg0->unk_44(1, arg0->unk_48);

    Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);

    arg0->unk_20[0]->unk_00.unk_00.unk_24(&arg0->unk_20[0]->unk_00.unk_00, 0x100);

    sp24 = arg0->unk_44(4, arg0->unk_48);

    arg0->unk_20[0]->unk_00.unk_00.unk_24(&arg0->unk_20[0]->unk_00.unk_00, 1);

    if (arg0->unk_48->unk_18 != 0) {
        if (sp24 == 0) {
            LabPC_RemoveMonFromBox(arg0->unk_20[0]);
        }
    } else if (sp24 == 1) {
        *arg0->unk_20[0]->unk_88 = 1;
    }

    LabPC_SwapMenu_Reset(arg0);
}

s32 LabPC_SwapMenuInput(unk_func_8820B12C_02C* arg0, Controller* arg1) {
    s32 var_v1;
    s32 var_v0;
    func8850A10C temp_v1;

    var_v1 = arg0->unk_20[arg0->unk_1C]->unk_00.unk_00.unk_20(arg0->unk_20[arg0->unk_1C], arg1);

    if (var_v1 & 1) {
        return var_v1;
    }

    if (var_v1 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_v1 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_v1 = 0x80000004;
        }
    }

    switch (arg0->unk_2C) {
        case 0:
            switch (arg0->unk_28) {
                case 0:
                    if (!(var_v1 & 2) && (var_v1 & 4)) {
                        if (arg0->unk_20[0]->unk_00.unk_2C->unk_08 == 0) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(arg0->unk_3C, arg0->unk_5C[0], 0, 0);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_3C, arg1);
                            var_v1 = 1;
                        } else if (arg0->unk_20[1]->unk_00.unk_2C->unk_08 >= arg0->unk_20[1]->unk_00.unk_2C->unk_04) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(arg0->unk_3C, arg0->unk_5C[5], 0, 0);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_3C, arg1);
                            var_v1 = 1;
                        } else {
                            LabPC_SwapMenu_SetPhase(arg0, 1);
                            var_v1 |= 1;
                        }
                    }
                    break;

                case 1:
                    if (!(var_v1 & 2) && (var_v1 & 4)) {
                        if (arg0->unk_20[0]->unk_00.unk_2C->unk_08 == 0) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(arg0->unk_3C, arg0->unk_5C[1], 0, 0);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_3C, arg1);
                            var_v1 = 1;
                        } else {
                            LabPC_SwapMenu_SetPhase(arg0, 2);
                            var_v1 |= 1;
                        }
                    }
                    break;

                case 2:
                    if (!(var_v1 & 2) && (var_v1 & 4)) {
                        if ((arg0->unk_20[0]->unk_00.unk_2C->unk_08 == 0) ||
                            (arg0->unk_20[1]->unk_00.unk_2C->unk_08 == 0)) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(arg0->unk_3C, arg0->unk_5C[2], 0, 0);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_3C, arg1);
                            var_v1 = 1;
                        } else {
                            LabPC_SwapMenu_SetPhase(arg0, 3);
                            var_v1 |= 1;
                        }
                    }
                    break;

                case 3:
                    if (!(var_v1 & 2) && (var_v1 & 4)) {
                        if (arg0->unk_20[0]->unk_00.unk_2C->unk_08 == 0) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            temp_v1 = ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText));
                            if (arg0->unk_48->unk_18 != 0) {
                                var_v0 = 4;
                            } else {
                                var_v0 = 3;
                            }
                            temp_v1(arg0->unk_3C, arg0->unk_5C[var_v0], 0, 0);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_3C, arg1);
                            var_v1 = 1;
                        } else {
                            LabPC_PerformReleaseOrReceive(arg0);
                            var_v1 = 5;
                        }
                    }
                    break;
            }
            break;

        case 1:
            if (var_v1 & 2) {
                LabPC_SwapMenu_SetPhase(arg0, 0);
                LabPC_ScrollableGrid_SetSwapMode(arg0->unk_20[1], 1);
                var_v1 |= 1;
            } else if (var_v1 & 4) {
                Audio_PlaySoundEffectById(SFX_MOVE_SWAP);
                arg0->unk_20[0]->unk_00.unk_34[arg0->unk_20[0]->unk_00.unk_38] |= 0x100;
                LabPC_PerformMove(arg0, arg1);
                LabPC_ScrollableGrid_SetSwapMode(arg0->unk_20[1], 2);
                if (arg0->unk_74 != 0) {
                    var_v1 = 0x02000000;
                } else {
                    var_v1 = 0x80000081;
                }
            }
            break;

        case 2:
            if (var_v1 & 2) {
                LabPC_SwapMenu_SetPhase(arg0, 0);
                var_v1 |= 1;
            } else if (var_v1 & 4) {
                if (arg0->unk_30 == arg0->unk_20[arg0->unk_1C]->unk_00.unk_38) {
                    var_v1 = 0x80000101;
                } else {
                    Audio_PlaySoundEffectById(SFX_MOVE_SWAP);
                    arg0->unk_20[arg0->unk_1C]->unk_00.unk_34[arg0->unk_20[arg0->unk_1C]->unk_00.unk_38] |= 2;
                    arg0->unk_20[arg0->unk_1C]->unk_00.unk_34[arg0->unk_30] |= 0x100;
                    arg0->unk_20[arg0->unk_1C]->unk_00.unk_34[arg0->unk_20[arg0->unk_1C]->unk_00.unk_38] |= 0x100;
                    LabPC_PerformExchange(arg0, arg1, 1);
                    var_v1 = 0x80000081;
                }
            }
            break;

        case 3:
            if (var_v1 & 2) {
                LabPC_SwapMenu_SetPhase(arg0, 0);
                var_v1 |= 1;
            } else if (var_v1 & 4) {
                Audio_PlaySoundEffectById(SFX_MOVE_SWAP);
                arg0->unk_20[1]->unk_00.unk_34[arg0->unk_20[1]->unk_00.unk_38] |= 2;
                arg0->unk_20[0]->unk_00.unk_34[arg0->unk_20[0]->unk_00.unk_38] |= 0x100;
                arg0->unk_20[1]->unk_00.unk_34[arg0->unk_20[1]->unk_00.unk_38] |= 0x100;
                LabPC_PerformExchange(arg0, arg1, 0);
                var_v1 = 0x80000081;
            }
            break;
    }

    return var_v1;
}

unk_func_88205880_00D0* LabPC_GetHighlightedMon(unk_func_8820B12C_02C* arg0) {
    s32 temp_v1;
    unk_func_88205880_A030* temp_a1;

    if (arg0->unk_2C == 1) {
        return NULL;
    }

    temp_v1 = arg0->unk_20[arg0->unk_1C]->unk_00.unk_38;
    temp_a1 = arg0->unk_20[arg0->unk_1C]->unk_00.unk_2C;

    if (temp_v1 >= temp_a1->unk_08) {
        return NULL;
    }

    return temp_a1->unk_00[temp_v1];
}

void LabPC_InitBoxLocationWidget(unk_func_88208C5C* arg0, unk_func_8850143C* arg1) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_88208C5C));

    arg0->unk_00.unk_18 = LabPC_DrawBoxLocationLabel;
    arg0->unk_00.unk_14.unk_00 = arg1->unk_00.unk_14.unk_00;
    arg0->unk_00.unk_14.unk_02 = arg1->unk_00.unk_14.unk_02;
    arg0->unk_2C = arg1;
    arg0->unk_30 = GbSave_GameToCategoryIndex(GbSave_GetPortGame(GbSave_GetActivePort()));
    arg0->unk_34 = -1;
    arg0->unk_38 = -1;
}

s32 LabPC_DrawBoxLocationLabel(unk_func_88208C5C* arg0, s32 arg1, s32 arg2) {
    static u8 D_88217E30[] = {
        0x27,
        0x42,
        0x43,
        0x40,
    };
    static Color_RGBA8 D_88217E34 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88217E38 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* spBC = Text_GetString(NULL, 0, D_88224FB4, D_88217E30[arg0->unk_34]);
    s8 sp9C[0x20];
    s32 temp_v0;
    s32 var_s0;

    if (arg0->unk_38 == -1) {
        return 1;
    }

    if ((arg0->unk_34 == 1) || (arg0->unk_34 == 2)) {
        sprintf(sp9C, "%s %d", spBC, arg0->unk_38 + 1);
        spBC = sp9C;
    }

    temp_v0 = Font_MeasureTextExtent(8, 0, spBC);

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
    Gfx_SetEnvColor(D_88217E34.r, D_88217E34.g, D_88217E34.b, D_88217E34.a);
    Font_SetActive(8, 0);
    Font_Printf(var_s0, arg2 + 5, spBC);
    Font_EndTexturedTextRendering();

    return 0;
}

u32 LabPC_BoxLocationWidget_GetSelection(unk_func_88208C5C* arg0) {
    return (arg0->unk_34 << 0x10) | arg0->unk_38;
}

void LabPC_BoxLocationWidget_SetSelection(unk_func_88208C5C* arg0, u32 arg1) {
    arg0->unk_34 = arg1 >> 0x10;
    arg0->unk_38 = arg1 & 0xFFFF;
}

void LabPC_InitPokemonInfoCard(unk_func_8820BE14_02C_070* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8820BE14_02C_070));

    arg0->unk_0000.unk_18 = LabPC_DrawPokemonInfoCard;
    arg0->unk_0000.unk_10.unk_00 = arg1;
    arg0->unk_0000.unk_10.unk_02 = arg2;

    LabPC_InfoCard_SetMon(arg0, NULL);

    arg0->unk_0030 = 0;
}

void LabPC_DrawMoveName(s32 arg0, s32 arg1, ret_func_8002ED08* arg2, s32 arg3) {
    Color_RGBA8 sp24;
    char* sp20;

    Font_SetActive(8, 0);
    if (arg2 == NULL) {
        sp24 = ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(0)->unk_04;
        sp20 = "???????";
    } else {
        sp24 = ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(arg2->unk_00[1])->unk_04;
        sp20 = Text_GetString(NULL, 0, D_88224FBC, arg2->unk_00[0] - 1);
    }

    Gfx_SetEnvColor(sp24.r, sp24.g, sp24.b, sp24.a);

    if (arg3 != 0) {
        arg0 = (arg0 - Font_MeasureTextExtent(0, 0, sp20)) + 0x8C;
    }

    Font_Printf(arg0, arg1, sp20);
}

s32 LabPC_DrawPokemonInfoCard(unk_func_8820BE14_02C_070* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88217E3C = { 0xF0, 0xF0, 0xF0, 0xFF };
    static unk_D_88217E40 D_88217E40[] = {
        {
            0x000000DB,
            0x00000004,
            0x00000001,
            0x00000167,
            0x040037A8,
        },
        {
            0x00000193,
            0x0000001C,
            0x00000000,
            0x0000017F,
            0x04003AD0,
        },
        {
            0x0000017B,
            0x00000034,
            0x00000000,
            0x00000167,
            0x04003DF8,
        },
        { 0x000000C3, 0x0000001C, 0x00000001, 0x0000014F, 0x04004120 },
    };

    s32 i;
    s32 spB0;
    unk_func_88205880_00D0* ptr = arg0->unk_002C;

    if (ptr == NULL) {
        return 0;
    }

    spB0 = BattleMon_CountMoves(ptr);

    i = (u32)arg0->unk_0039[arg0->unk_0030] & ~7;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    gDPLoadTextureBlock(gDisplayListHead++, i, G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 40, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg1 + 0x84) << 2, (arg2 + 0xA) << 2, (arg1 + 0xAB) << 2,
                        (arg2 + 0x31) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    for (i = 0; i < 4; i++) {
        gDPLoadTextureBlock(gDisplayListHead++, D_88217E40[i].unk_10, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (arg1 + D_88217E40[i].unk_0C) << 2, (arg2 + D_88217E40[i].unk_04) << 2,
                            ((arg1 + D_88217E40[i].unk_0C) + 0x13) << 2, (arg2 + D_88217E40[i].unk_04 + 0x13) << 2,
                            G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

    Font_BeginTranslucentTextRendering();

    if ((arg0->unk_002C->unk_000[0].unk_00.unk_00 <= 0) || (arg0->unk_002C->unk_000[0].unk_00.unk_00 >= 0x98)) {
        Gfx_SetEnvColor(D_88217E3C.r, D_88217E3C.g, D_88217E3C.b, D_88217E3C.a);
        Font_SetActive(8, 0);
        Font_Printf(arg1 + 8, arg2 + 8, "?????");
    } else {
        Gfx_SetEnvColor(D_88217E3C.r, D_88217E3C.g, D_88217E3C.b, D_88217E3C.a);
        Font_SetActive(8, 0);

        Font_Printf(arg1 + 8, arg2 + 0x24, Text_GetString(NULL, 0, D_88224FB4, 0x12));
        Gfx_SetEnvColor(0xFF, 0xC8, 0xC8, 0xFF);
        Font_SetActive(4, 0);

        Font_Printf(arg1 + 6, arg2 + 0x56, Text_GetString(NULL, 0, D_88224FB4, 0x13));
        Font_Printf(arg1 + 0x91, arg2 + 0x56, Text_GetString(NULL, 0, D_88224FB4, 0x14));
        Font_Printf(arg1 + 0x11C, arg2 + 0x56, Text_GetString(NULL, 0, D_88224FB4, 0x15));
        Font_Printf(arg1 + 0x1A7, arg2 + 0x56, Text_GetString(NULL, 0, D_88224FB4, 0x16));

        Gfx_SetEnvColor(D_88217E3C.r, D_88217E3C.g, D_88217E3C.b, D_88217E3C.a);
        Font_SetActive(8, 0);
        Font_Printf(arg1 + 8, arg2 + 8,
                      Text_GetString(NULL, 0, D_88224FB8, arg0->unk_002C->unk_000[0].unk_00.unk_00 - 1));

        Font_Printf(arg1 + 0x44, arg2 + 0x24, "%3d", arg0->unk_002C->unk_000[0].unk_26);
        Font_Printf(arg1 + 0x46, arg2 + 0x54, "%3d", arg0->unk_002C->unk_000[0].unk_28);
        Font_Printf(arg1 + 0xD1, arg2 + 0x54, "%3d", arg0->unk_002C->unk_000[0].unk_2A);
        Font_Printf(arg1 + 0x15C, arg2 + 0x54, "%3d", arg0->unk_002C->unk_000[0].unk_2C);
        Font_Printf(arg1 + 0x1E7, arg2 + 0x54, "%3d", arg0->unk_002C->unk_000[0].unk_2E);
    }

    for (i = 0; i < spB0; i++) {
        LabPC_DrawMoveName(D_88217E40[i].unk_00 + arg1, D_88217E40[i].unk_04 + arg2,
                      Move_GetDisplayInfo(arg0->unk_002C->unk_000[0].unk_09[i]), D_88217E40[i].unk_08);
    }

    Font_EndTexturedTextRendering();

    return 0;
}

void LabPC_InfoCard_SetMon(unk_func_8820BE14_02C_070* arg0, unk_func_88205880_00D0* arg1) {
    arg0->unk_002C = arg1;
    if (arg1 != NULL) {
        arg0->unk_0030 = (arg0->unk_0030 + 1) & 1;
        PokeIcon_LoadModelTextureForMon((u32)arg0->unk_0039[arg0->unk_0030] & ~7, 0, arg0->unk_002C);
    }
}

s32 LabPC_FindDirtyDeck(unk_func_8820BE14_06C* arg0) {
    s32 i;
    s32 j;
    unk_func_8820BE14_06C_000* ptr;

    for (i = 0; i < 3; i++) {
        ptr = arg0[i].unk_00;
        for (j = 0; j < arg0[i].unk_08; j++) {
            if (ptr[j].unk_04.unk_08 < ptr[j].unk_04.unk_04) {
                return (i << 0x10) | j;
            }
        }
    }
    return 0;
}

#ifdef NON_MATCHING
void func_88209B54(unk_func_8820BE14_02C* arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C_000* arg3,
                   unk_func_8820BE14_06C_000* arg4, WidgetNode* arg5, FragmentEntry arg6,
                   unk_func_8820BE14_030* arg7, unk_func_88509F48* arg8, char** arg9, MemoryPool* argA) {
    static Color_RGBA8 D_88217E90 = { 0x6C, 0x6C, 0x7E, 0xFF };
    static Color_RGBA8 D_88217E94 = { 0x50, 0x50, 0x86, 0xFF };
    static Color_RGBA8 D_88217E98 = { 0x79, 0x79, 0xCB, 0xFF };
    static Color_RGBA8 D_88217E9C = { 0x40, 0x40, 0x6C, 0xFF };
    static Color_RGBA8 D_88217EA0 = { 0x6A, 0x6A, 0xB2, 0xFF };
    static unk_D_88217EA4 D_88217EA4[] = {
        {
            219,
            40,
            54,
            42,
            D_8821E100,
            0x30,
            0x0000,
            D_882181E8,
            1,
            1,
        },
        {
            279,
            40,
            54,
            42,
            D_8821E100,
            0x30,
            0x0000,
            D_882181E8,
            0,
            3,
        },
        {
            219,
            88,
            54,
            42,
            D_88218FD0,
            0x30,
            0x0000,
            D_882181B8,
            0,
            3,
        },
        {
            279,
            88,
            54,
            42,
            D_8821B868,
            0x30,
            0x0000,
            D_882181D0,
            1,
            1,
        },
        {
            219,
            136,
            54,
            42,
            D_8821AAE0,
            0x30,
            0x0000,
            D_882181C8,
            0,
            1,
        },
        {
            279,
            136,
            54,
            42,
            D_88219D58,
            0x30,
            0x0000,
            D_882181C0,
            1,
            1,
        },
        {
            219,
            184,
            54,
            42,
            D_88218248,
            0x30,
            0x0000,
            D_882181B0,
            0,
            3,
        },
        {
            279,
            184,
            54,
            42,
            D_8821D378,
            0x30,
            0x0000,
            D_882181E0,
            1,
            1,
        },
    };
    static Color_RGBA8 D_88217F84 = { 0xFF, 0xFF, 0x00, 0xFF };
    static Color_RGBA8 D_88217F88 = { 0x2D, 0x1A, 0x41, 0xFF };
    static Color_RGBA8 D_88217F8C = { 0x6F, 0x5F, 0x7F, 0xFF };
    static Color_RGBA8* D_88217F90[] = {
        D_88218228, D_88218228, D_882181F0, D_88218210, D_88218200, D_88218208, D_882181F8, D_88218220,
    };
    static Color_RGBA8* D_88217FB0[] = { D_882181F8, D_882181F8 };
    static Color_RGBA8 D_88217FB8 = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 i;
    s32 j;
    UNUSED s32 pad;
    unk_func_885012A4* sp108;
    unk_func_885012A4* sp104;
    unk_func_885012A4* sp100;
    unk_func_885012A4* spFC;
    unk_func_885012A4* spF8;
    WidgetNode* spF4;
    WidgetNode* spF0;
    unk_func_8850143C* spEC;
    unk_func_8850143C* spE8;
    s32 spE4;
    UNUSED s32 padA0;
    UNUSED s32 padA1;
    UNUSED s32 padA2;
    UNUSED s32 padA3;
    unk_func_8850878C* spB4[8];
    UNUSED s32 padB0;
    UNUSED s32 padB1;
    UNUSED s32 padB2;
    UNUSED s32 padB3;
    char* spA0;
    s32 sp9C;
    unk_func_88507D4C* sp98;
    unk_func_88507D4C* sp94;
    UNUSED s32 padC;
    unk_func_88507D4C* sp8C;
    unk_func_88507D4C* sp88;
    s32 temp_s0_5;
    char* temp_s1_2;
    char* temp_v0_10;
    unk_func_882149A0* temp_v0_7;
    unk_func_8850878C* temp_s0;
    u32 temp_v0_17;

    arg0->unk_8C = arg4;
    arg0->unk_80 = arg8;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8820BE14_02C));

    arg0->unk_00.unk_1C = LabPC_SwapScreen_UpdatePageSelection;
    arg0->unk_00.unk_20 = LabPC_HandleInput;
    arg0->unk_00.unk_24 = LabPC_SwapScreen_SetMenuState;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_74 = mem_pool_alloc(argA, sizeof(unk_func_8820B12C));
    LabPC_InitSwapController(arg0->unk_74, arg0);

    arg0->unk_2C = mem_pool_alloc(argA, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, 0x228, 0x160);
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    temp_s0 = mem_pool_alloc(argA, sizeof(WidgetDelayedNode));
    ((func88503118)Memmap_GetFragmentVaddr(WidgetTree_InitDelayedWidget))(temp_s0, 0, 0, 0x228, 0x160);
    ((WidgetDelayedNode*)temp_s0)->unk_2C = 0;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, temp_s0);

    spF8 = mem_pool_alloc(argA, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spF8, 0, 0, 0x228, 8, D_88217E90);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spF8);
    if (&spF8) {
    }

    spFC = mem_pool_alloc(argA, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spFC, 0, 0xEE, 0x228, 6, D_88217E90);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spFC);
    if (&spFC) {
    }

    sp100 = mem_pool_alloc(argA, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp100, 0, 8, 8, 0xE6, D_88217E90);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp100);
    if (&sp100) {
    }

    sp104 = mem_pool_alloc(argA, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp104, 0x220, 8, 8, 0xE6, D_88217E90);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp104);
    if (&sp104) {
    }

    sp108 = mem_pool_alloc(argA, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp108, 0xD4, 8, 0x80, 0xE6, D_88217E90);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp108);
    if (&sp108) {
    }

    spF0 = mem_pool_alloc(argA, sizeof(WidgetNode));
    ((func8850AB48)Memmap_GetFragmentVaddr(WidgetTree_InitInsetBorderFrame))(spF0, 8, 8, 0xCC, 0xE6);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spF0);
    if (&spF0) {
    }

    spF4 = mem_pool_alloc(argA, sizeof(WidgetNode));
    ((func8850AB48)Memmap_GetFragmentVaddr(WidgetTree_InitInsetBorderFrame))(spF4, 0x154, 8, 0xCC, 0xE6);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spF4);
    if (&spF4) {
    }

    spE8 = mem_pool_alloc(argA, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(WidgetTree_InitPatternTexture))(spE8, 8, 8, 0xCC, 0x1E, D_88217E94, D_88217E98);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spE8);

    spEC = mem_pool_alloc(argA, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(WidgetTree_InitPatternTexture))(spEC, 0x154, 8, 0xCC, 0x1E, D_88217E94, D_88217E98);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spEC);

    arg0->unk_30[0] = mem_pool_alloc(argA, sizeof(unk_func_88208C5C));
    LabPC_InitBoxLocationWidget(arg0->unk_30[0], spE8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spE8, arg0->unk_30[0]);
    if (&spE8) {
    }

    arg0->unk_30[1] = mem_pool_alloc(argA, sizeof(unk_func_88208C5C));
    LabPC_InitBoxLocationWidget(arg0->unk_30[1], spEC);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spEC, arg0->unk_30[1]);
    if (&spEC) {
    }

    arg0->unk_40 = mem_pool_alloc(argA, sizeof(unk_func_88217740));
    LabPC_InitModeToggleIcon(arg0->unk_40, 0xF4, 0xA);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_40);

    if (arg3 != NULL) {
        arg0->unk_40->unk_00.unk_28 &= ~1;
    }

    temp_v0_17 = 1 << ((arg3 != NULL) ? 1 : 0);

    for (spE4 = 0; (u32)spE4 < 8; spE4++) {
        unk_D_88217EA4* ptr = &D_88217EA4[spE4];
        if (!(ptr->unk_18 & temp_v0_17)) {
            continue;
        }

        arg0->unk_44[spE4] = mem_pool_alloc(argA, sizeof(unk_func_882149A0));
        LabPC_InitTabWidget(arg0->unk_44[spE4], ptr->unk_00, ptr->unk_02, ptr->unk_04, ptr->unk_06, ptr->unk_08, ptr->unk_0C,
                      ptr->unk_10[0], ptr->unk_10[1], D_88217E90);

        if (ptr->unk_14 != 0) {
            LabPC_TabWidget_ToggleFlip(arg0->unk_44[spE4]);
        }

        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_44[spE4]);
    }

    arg0->unk_74->unk_28 = mem_pool_alloc(argA, sizeof(WidgetGridMenu));
    ((func8850C284)Memmap_GetFragmentVaddr(WidgetTree_InitGridMenu))(arg0->unk_74->unk_28, 4, 2, argA);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_74, arg0->unk_74->unk_28);

    for (spE4 = 0; spE4 != 8; spE4++) {
        if (D_88217EA4[spE4].unk_18 & temp_v0_17) {
            arg0->unk_74->unk_28->unk_18[(spE4 / 2) * arg0->unk_74->unk_28->unk_2C + (spE4 % 2)] = arg0->unk_44[spE4];
        }
    }

    ((func8850CB48)Memmap_GetFragmentVaddr(WidgetTree_SetGridMenuSelection))(arg0->unk_74->unk_28, 2);

    temp_s0 = mem_pool_alloc(argA, sizeof(WidgetAnimatedFrame));
    ((func88503340)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedFrameVariantA))(temp_s0, 0, 0, 0x10, 0x10, D_88217F84);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, temp_s0);
    arg0->unk_74->unk_28->unk_1C = (unk_func_882170A8*)temp_s0;

    temp_s0 = mem_pool_alloc(argA, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(WidgetTree_InitPatternTexture))(temp_s0, 0, 0xF4, 0x228, 0x6C, D_88217F88, D_88217F8C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, temp_s0);

    arg0->unk_64 = mem_pool_alloc(argA, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_64, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s0, arg0->unk_64);

    arg0->unk_68 = mem_pool_alloc(argA, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_68, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_64, arg0->unk_68);

    for (spE4 = 0; spE4 != 8; spE4++) {
        temp_s1_2 = Text_GetString(NULL, 0, D_88224FB4, spE4 + 1);
        spB4[spE4] = mem_pool_alloc(argA, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(spB4[spE4], (0x228 - Font_MeasureTextExtent(0x10, 0, temp_s1_2)) / 2,
                                                               0x2A, temp_s1_2, 0x10);
        spB4[spE4]->unk_30 = D_88217F90[spE4][0];
        spB4[spE4]->unk_44 = spB4[spE4]->unk_44;
        spB4[spE4]->unk_34 = D_88217F90[spE4][1];
        spB4[spE4]->unk_44 = 1;
        ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_68, spB4[spE4]);
    }

    if (arg3 != NULL) {
        temp_v0_10 = Text_GetString(NULL, 0, D_88224FB4, 9);
        spB4[2]->unk_00.unk_10.unk_00 = (0x228 - Font_MeasureTextExtent(0x10, 0, temp_v0_10)) / 2;
        spB4[2]->unk_00.unk_10.unk_02 = 0x2A;
        spB4[2]->unk_40 = temp_v0_10;
    }

    arg0->unk_6C = mem_pool_alloc(argA, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_6C, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_64, arg0->unk_6C);

    for (j = 0; j != 2; j++) {
        temp_s0 = mem_pool_alloc(argA, sizeof(unk_func_8850878C));
        spA0 = Text_GetString(NULL, 0, D_88224FB4, 0xA);

        if (j == 0) {
            sp9C = 0x210 - Font_MeasureTextExtent(0x10, 0, spA0);
        } else {
            sp9C = 0x18;
        }

        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(temp_s0, sp9C, 0x1A, spA0, 0x10);

        temp_s0->unk_30 = D_88217FB0[j][0];
        temp_s0->unk_44 = temp_s0->unk_44;
        temp_s0->unk_34 = D_88217FB0[j][1];
        temp_s0->unk_44 = 1;
        temp_s0->unk_3C = 0x20;

        ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_6C, temp_s0);
    }

    arg0->unk_70 = mem_pool_alloc(argA, sizeof(unk_func_8820BE14_02C_070));
    LabPC_InitPokemonInfoCard(arg0->unk_70, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_64, arg0->unk_70);

    arg0->unk_38[0] = mem_pool_alloc(argA, sizeof(unk_func_8820B12C_02C_020));
    LabPC_InitScrollableBoxGrid(arg0->unk_38[0], 8, 0x36, 6, LabPC_DrawSwapBoxLabel, 0xCC, 0x1C, argA);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_38[0], 0x14, argA);

    sp94 = mem_pool_alloc(argA, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp94, 8, 0x26, 0xCC, 0, arg0->unk_38[0]);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp94);
    if (&sp94) {
    }

    sp98 = mem_pool_alloc(argA, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp98, 8, arg0->unk_38[0]->unk_00.unk_00.unk_14.unk_02 + 0x36,
                                                           0xCC, 1, arg0->unk_38[0]);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp98);
    LabPC_BoxGrid_BindMessagePanel(arg0->unk_38[0], sp98);

    temp_s0 = mem_pool_alloc(argA, sizeof(unk_func_882170A8));
    LabPC_InitPageCounterWidget((unk_func_882170A8*)temp_s0, 0x98, 2, arg0->unk_38[0], 2);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp98, temp_s0);
    if (&sp98) {
    }
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_38[0]);

    arg0->unk_38[1] = mem_pool_alloc(argA, sizeof(unk_func_8820B12C_02C_020));
    LabPC_InitScrollableBoxGrid(arg0->unk_38[1], 0x154, 0x36, 6, LabPC_DrawSwapBoxLabel, 0xCC, 0x1C, argA);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_38[1], 0x14, argA);

    sp88 = mem_pool_alloc(argA, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp88, 0x154, 0x26, 0xCC, 0, arg0->unk_38[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp88);
    if (&sp88) {
    }

    sp8C = mem_pool_alloc(argA, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(
        sp8C, 0x154, arg0->unk_38[1]->unk_00.unk_00.unk_14.unk_02 + 0x36, 0xCC, 1, arg0->unk_38[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp8C);
    LabPC_BoxGrid_BindMessagePanel(arg0->unk_38[1], sp8C);

    temp_s0 = mem_pool_alloc(argA, sizeof(unk_func_882170A8));
    LabPC_InitPageCounterWidget((unk_func_882170A8*)temp_s0, 0x98, 2, arg0->unk_38[1], 2);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp8C, temp_s0);
    if (&sp8C) {
    }
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_38[1]);

    if (arg3 != NULL) {
        temp_s0_5 = LabPC_FindDirtyDeck(arg0->unk_8C);
        LabPC_BoxLocationWidget_SetSelection(arg0->unk_30[0], 0x30000);
        LabPC_BoxLocationWidget_SetSelection(arg0->unk_30[1], temp_s0_5);
        LabPC_BindGridDeckData(arg0->unk_38[0], arg3, 0x30000);
        LabPC_BindGridDeckData(arg0->unk_38[1],
                      (arg0->unk_8C[temp_s0_5 >> 0x10].unk_0C * (temp_s0_5 & 0xFFFF)) +
                          arg0->unk_8C[temp_s0_5 >> 0x10].unk_00,
                      temp_s0_5);
    } else {
        LabPC_BoxLocationWidget_SetSelection(arg0->unk_30[0], 0);
        LabPC_BoxLocationWidget_SetSelection(arg0->unk_30[1], 0x10000);
        LabPC_BindGridDeckData(arg0->unk_38[0], arg0->unk_8C[0].unk_00, 0);
        LabPC_BindGridDeckData(arg0->unk_38[1], arg0->unk_8C[1].unk_00, 0x10000);
    }

    arg0->unk_74->unk_2C = mem_pool_alloc(argA, sizeof(unk_func_8820B12C_02C));
    LabPC_InitSwapMenu(arg0->unk_74->unk_2C, arg0->unk_38, arg0->unk_38[1], arg0->unk_40, arg0->unk_80, arg3 != NULL, argA);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_74, arg0->unk_74->unk_2C);

    arg0->unk_74->unk_2C->unk_40 = mem_pool_alloc(argA, sizeof(unk_func_8850CD44));
    ((func8850CD44)Memmap_GetFragmentVaddr(WidgetTree_InitChildWidgetGroup))(arg0->unk_74->unk_2C->unk_40, 2, argA);

    for (j = 0; j != 2; j++) {
        arg0->unk_74->unk_2C->unk_4C[j] = mem_pool_alloc(argA, sizeof(unk_func_882173EC));
        LabPC_InitFlyingIconWidget(arg0->unk_74->unk_2C->unk_4C[j], 0, 0);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_74->unk_2C->unk_4C[j]);

        arg0->unk_74->unk_2C->unk_54[j] = mem_pool_alloc(argA, sizeof(unk_func_882079D8));
        LabPC_InitMonNameLevelWidget(arg0->unk_74->unk_2C->unk_54[j], 0, 0, 0xCC, NULL);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_74->unk_2C->unk_4C[j],
                                                               arg0->unk_74->unk_2C->unk_54[j]);

        arg0->unk_74->unk_2C->unk_40->unk_1C[j] = arg0->unk_74->unk_2C->unk_4C[j];
    }

    arg0->unk_74->unk_2C->unk_44 = arg6;
    arg0->unk_74->unk_2C->unk_48 = arg7;

    arg0->unk_78[0] = mem_pool_alloc(argA, sizeof(unk_func_8820BE14_02C_078));
    LabPC_InitBoxTypeSelector(arg0->unk_78[0], 8, 0x2A, 0xCC, arg0->unk_8C, 0, argA);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_78[0]);

    arg0->unk_78[1] = mem_pool_alloc(argA, sizeof(unk_func_8820BE14_02C_078));
    LabPC_InitBoxTypeSelector(arg0->unk_78[1], 0x154, 0x2A, 0xCC, arg0->unk_8C, 1, argA);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_78[1]);

    temp_s0 = mem_pool_alloc(argA, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))((unk_func_88503298*)temp_s0, arg0->unk_2C, arg5);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, temp_s0);

    arg0->unk_84 = mem_pool_alloc(argA, sizeof(unk_func_889000C4));
    ((func889000C4)Memmap_GetFragmentVaddr(LabUI_BuildConfirmDialog))(arg0->unk_84, arg3 != NULL, arg0->unk_2C, 0, arg9, argA);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_84);

    temp_s0 = mem_pool_alloc(argA, sizeof(char) * 0x80);

    arg0->unk_88 = mem_pool_alloc(argA, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_88, 0, 0, (char*)temp_s0, 0x10);
    arg0->unk_88->unk_30 = D_88217FB8;
    arg0->unk_88->unk_44 = arg0->unk_88->unk_44;
}
#else
static Color_RGBA8 D_88217E90 = { 0x6C, 0x6C, 0x7E, 0xFF };
static Color_RGBA8 D_88217E94 = { 0x50, 0x50, 0x86, 0xFF };
static Color_RGBA8 D_88217E98 = { 0x79, 0x79, 0xCB, 0xFF };
static Color_RGBA8 D_88217E9C = { 0x40, 0x40, 0x6C, 0xFF };
static Color_RGBA8 D_88217EA0 = { 0x6A, 0x6A, 0xB2, 0xFF };
static unk_D_88217EA4 D_88217EA4[] = {
    {
        219,
        40,
        54,
        42,
        D_8821E100,
        0x30,
        0x0000,
        D_882181E8,
        1,
        1,
    },
    {
        279,
        40,
        54,
        42,
        D_8821E100,
        0x30,
        0x0000,
        D_882181E8,
        0,
        3,
    },
    {
        219,
        88,
        54,
        42,
        D_88218FD0,
        0x30,
        0x0000,
        D_882181B8,
        0,
        3,
    },
    {
        279,
        88,
        54,
        42,
        D_8821B868,
        0x30,
        0x0000,
        D_882181D0,
        1,
        1,
    },
    {
        219,
        136,
        54,
        42,
        D_8821AAE0,
        0x30,
        0x0000,
        D_882181C8,
        0,
        1,
    },
    {
        279,
        136,
        54,
        42,
        D_88219D58,
        0x30,
        0x0000,
        D_882181C0,
        1,
        1,
    },
    {
        219,
        184,
        54,
        42,
        D_88218248,
        0x30,
        0x0000,
        D_882181B0,
        0,
        3,
    },
    {
        279,
        184,
        54,
        42,
        D_8821D378,
        0x30,
        0x0000,
        D_882181E0,
        1,
        1,
    },
};
static Color_RGBA8 D_88217F84 = { 0xFF, 0xFF, 0x00, 0xFF };
static Color_RGBA8 D_88217F88 = { 0x2D, 0x1A, 0x41, 0xFF };
static Color_RGBA8 D_88217F8C = { 0x6F, 0x5F, 0x7F, 0xFF };
static Color_RGBA8* D_88217F90[] = {
    D_88218228, D_88218228, D_882181F0, D_88218210, D_88218200, D_88218208, D_882181F8, D_88218220,
};
static Color_RGBA8* D_88217FB0[] = { D_882181F8, D_882181F8 };
static Color_RGBA8 D_88217FB8 = { 0xF0, 0xF0, 0xF0, 0xFF };
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/lab_pc/lab_pc_1AE680/func_88209B54.s")
#endif

s32 LabPC_SwapScreen_UpdatePageSelection(unk_func_8820BE14_02C* arg0) {
    switch (arg0->unk_74->unk_00.unk_1C) {
        case 0:
            if ((arg0->unk_74->unk_28->unk_20 == 0x100) && (arg0->unk_74->unk_28->unk_24 < 2)) {
                ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_64, 1);
                ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_6C,
                                                                       (arg0->unk_74->unk_28->unk_24 == 0) ? 0 : 1);
            } else {
                ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_64, 0);
                ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_68, arg0->unk_74->unk_28->unk_24);
            }
            break;

        case 1:
            if (LabPC_BoxLocationWidget_GetSelection(arg0->unk_30[0]) == 0x30000) {
                ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_64, 0);
                ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_68, arg0->unk_74->unk_28->unk_24);
            } else {
                LabPC_InfoCard_SetMon(arg0->unk_70, LabPC_GetHighlightedMon(arg0->unk_74->unk_2C));
                ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_64, 2);
            }
            break;
    }

    return 0;
}

s32 LabPC_HandleInput(unk_func_8820BE14_02C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_74->unk_00.unk_10(&arg0->unk_74->unk_00, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 LabPC_RunSwapScreenModal(unk_func_8820BE14_02C* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_s2 = 0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);

    while (var_s2 == 0) {
        Ui_SendMessageAndPollInput(0);

        temp_v0 = arg0->unk_00.unk_20(arg0, gPlayer1Controller);

        if (!(temp_v0 & 1) && (temp_v0 & 2)) {
            var_s2 = 1;
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(temp_v0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s2;
}

void LabPC_SwapScreen_SetMenuState(unk_func_8820BE14_02C* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    ((func8850BF60)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuState))(arg0->unk_74, arg1);
}

void LabPC_ReleaseSwapWidgets(unk_func_8820B12C_02C* arg0) {
    LabPC_TabWidget_ToggleFlip(arg0->unk_4C[0]);
    LabPC_TabWidget_ToggleFlip(arg0->unk_54[0]);
    LabPC_TabWidget_ToggleFlip(arg0->unk_54[1]);
    LabPC_TabWidget_ToggleFlip(arg0->unk_4C[1]);
    LabPC_TabWidget_ToggleFlip(arg0->unk_5C[1]);
}

void LabPC_InitSwapController(unk_func_8820B12C* arg0, unk_func_8820BE14_02C* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(WidgetTree_InitVerticalMenu))(&arg0->unk_00);

    arg0->unk_00.unk_10 = LabPC_SwapControllerInput;
    arg0->unk_00.unk_24 = arg1;
}

s32 LabPC_DeckHasChanged(unk_func_8820BE14_06C_000* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 sp90;
    DeckHandle* temp_v0;
    unk_func_88205880_00D0** var_s1;
    BattleMon sp34;

    sp90 = 0;
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
        sp90 = 1;
    } else {
        var_s1 = arg0->unk_04.unk_00;

        for (i = 0; i < arg0->unk_04.unk_08; i++, var_s1++) {
            bzero(&sp34, sizeof(BattleMon));
            Deck_ReadEntries(&sp34, 1, temp_v0);
            if (bcmp(&sp34, *var_s1, sizeof(BattleMon)) != 0) {
                arg0->unk_00 = 1;
                sp90 = 1;
                break;
            }
        }
    }

    Deck_CloseAndFlush(temp_v0);

    return sp90;
}

s32 LabPC_CheckDirtyDecks(unk_func_8820BE14_02C* arg0) {
    s32 i;
    s32 temp_s2;
    s32 var_s4;
    unk_func_8820BE14_06C_000* var_s1;

    temp_s2 = GbSave_GetActivePort();
    var_s4 = 0;

    var_s1 = arg0->unk_8C[0].unk_00;
    for (i = 0; i < 1; i++) {
        if (LabPC_DeckHasChanged(&var_s1[i], 0x20, temp_s2, i) != 0) {
            var_s4 |= 1;
            break;
        }
    }

    var_s1 = arg0->unk_8C[1].unk_00;
    for (i = 0; i < 12; i++) {
        if (LabPC_DeckHasChanged(&var_s1[i], 0x21, temp_s2, i) != 0) {
            var_s4 |= 2;
            break;
        }
    }

    var_s1 = arg0->unk_8C[2].unk_00;
    for (i = 0; i < 12; i++) {
        if (LabPC_DeckHasChanged(&var_s1[i], 0x11, temp_s2, i) != 0) {
            var_s4 |= 4;
            break;
        }
    }

    return var_s4;
}

s32 LabPC_IsPrizeDeckEmpty(unk_func_8820BE14_02C* arg0) {
    return arg0->unk_8C->unk_00->unk_04.unk_08 == 0;
}

void LabPC_WriteDeckBack(s32 arg0, s32 arg1, s32 arg2, unk_func_88200FA0_030_038* arg3) {
    s32 i;
    unk_func_88205880_00D0** sp28;
    DeckHandle* temp_s3;

    sp28 = arg3->unk_00;
    temp_s3 = Deck_Open(arg0, arg1, arg2, 1);

    for (i = 0; i < arg3->unk_08; i++) {
        Deck_WriteEntries(sp28[i], 1, temp_s3);
    }

    if ((arg0 == 0x10) || (arg0 == 0x11) || (arg0 == 0x12)) {
        Deck_CloseAndFlushBox(temp_s3);
    } else {
        Deck_CloseAndFlush(temp_s3);
    }
}

void LabPC_MarkSeenOwned(unk_func_88200FA0_030_038* arg0, s32 arg1) {
    s32 i;
    unk_func_88205880_00D0** tmp = arg0->unk_00;

    for (i = 0; i < arg0->unk_08; i++) {
        if ((tmp[i]->unk_000[0].unk_00.unk_00 > 0) && (tmp[i]->unk_000[0].unk_00.unk_00 < 0x98)) {
            GbSave_SetSeenOwnedBits(arg1, tmp[i]->unk_000[0].unk_00.unk_00, 3);
        }
    }
}

void LabPC_CommitChanges(unk_func_8820BE14_02C* arg0, s32 arg1) {
    s32 i;
    s32 temp_s5;
    unk_func_8820BE14_06C_000* temp_s4;

    temp_s5 = GbSave_GetActivePort();
    ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_84->unk_40, 2);
    Ui_SendMessageAndPollInput(NULL);

    temp_s4 = arg0->unk_8C[0].unk_00;
    for (i = 0; i < 1; i++) {
        if (temp_s4[i].unk_00 != 0) {
            LabPC_WriteDeckBack(0x20, temp_s5, i, &temp_s4[i].unk_04);
            LabPC_MarkSeenOwned(&temp_s4[i].unk_04, temp_s5);
        }
    }

    temp_s4 = arg0->unk_8C[1].unk_00;
    for (i = 0; i < 12; i++) {
        if (temp_s4[i].unk_00 != 0) {
            LabPC_WriteDeckBack(0x21, temp_s5, i, &temp_s4[i].unk_04);
            LabPC_MarkSeenOwned(&temp_s4[i].unk_04, temp_s5);
        }
    }

    temp_s4 = arg0->unk_8C[2].unk_00;
    for (i = 0; i < 12; i++) {
        if (temp_s4[i].unk_00 != 0) {
            LabPC_WriteDeckBack(0x11, temp_s5, i, &temp_s4[i].unk_04);
        }
    }

    if (LabPC_BoxLocationWidget_GetSelection(arg0->unk_30[0]) == 0x30000) {
        Save_SetSelectedPokemonId(0, 0);
        Save_CommitBankRecords(2);
        Save_FlushBank(2);
    }

    if (arg1 & 4) {
        Save_FlushBank(3);
    }

    if (arg1 & 3) {
        GbSave_RebuildSeenBitfield(temp_s5);
        ((func88900970)Memmap_GetFragmentVaddr(LabUI_ShowSavingPrompt))(arg0->unk_84, temp_s5);
    }

    if (arg1 & 4) {
        Save_CommitBankRecords(3);
        Save_FlushBank(3);
    }
}

s32 LabPC_RunConfirmSaveFlow(unk_func_8820BE14_02C* arg0, Controller* arg1) {
    s32 sp34;
    s32 sp30;
    UNUSED s32 pad[2];
    func889006D4 sp24;
    s32 temp_v0_2;

    sp34 = 1;
    sp30 = LabPC_CheckDirtyDecks(arg0);

    if (sp30 != 0) {
        arg0->unk_74->unk_28->unk_14(arg0->unk_74->unk_28, 0);

        sp24 = ((func889006D4)Memmap_GetFragmentVaddr(LabUI_OpenConfirmDialog));

        sp24(arg0->unk_84, LabPC_IsPrizeDeckEmpty(arg0));

        temp_v0_2 = ((func88900808)Memmap_GetFragmentVaddr(LabUI_RunConfirmDialog))(arg0->unk_84, arg1, 1);
        if (temp_v0_2 == 0) {
            LabPC_CommitChanges(arg0, sp30);
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_84);
        } else if (temp_v0_2 == 1) {
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_84);
        } else if (temp_v0_2 == 2) {
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_84);
            sp34 = 0;
        }

        arg0->unk_74->unk_28->unk_14(arg0->unk_74->unk_28, 1);
    }
    return sp34;
}

s32 LabPC_SwapControllerInput(unk_func_8820B12C* arg0, Controller* arg1) {
    static u8 D_88217FBC[] = { 0x18, 0x19, 0x1A };

    s32 i;
    s32 var_s1;
    s32 temp_v0_8;
    unk_func_8820B12C_000* var_a0;
    s32 sp64;
    u32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    char sp30[0x20];

    var_s1 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_08;
        }
        var_s1 = var_a0->unk_10(var_a0, arg1);
    }

    if (var_s1 & 1) {
        return var_s1;
    }

    if (var_s1 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_s1 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_s1 = 0x80000004;
        } else if (arg1->buttonPressed & 0x30) {
            var_s1 = 0x01000000;
        }
    }

    if (var_s1 & 2) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
                var_s1 = 2;
                if (LabPC_RunConfirmSaveFlow(arg0->unk_00.unk_24, arg1) == 0) {
                    var_s1 = 3;
                }
                break;

            case 1:
                ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 0);
                var_s1 |= 1;
                break;
        }
    } else if (var_s1 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 1:
                break;

            case 0:
                switch (arg0->unk_28->unk_24) {
                    case 0:
                    case 1:
                        if (arg0->unk_28->unk_24 == 0) {
                            sp64 = 0;
                        } else {
                            sp64 = 1;
                        }
                        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                        LabPC_BoxTypeSelector_SetSlotASelection(arg0->unk_00.unk_24->unk_78[sp64],
                                      LabPC_BoxLocationWidget_GetSelection(arg0->unk_00.unk_24->unk_30[sp64]));
                        LabPC_BoxTypeSelector_SetSlotBSelection(arg0->unk_00.unk_24->unk_78[sp64],
                                      LabPC_BoxLocationWidget_GetSelection(arg0->unk_00.unk_24->unk_30[1 - sp64]));

                        arg0->unk_28->unk_14(arg0->unk_28, 0x100);

                        if (LabPC_RunBoxTypeSelectorModal(arg0->unk_00.unk_24->unk_78[sp64], arg1) == 1) {
                            sp60 = LabPC_BoxTypeSelector_GetSlotSelection(arg0->unk_00.unk_24->unk_78[sp64]);
                            LabPC_BoxLocationWidget_SetSelection(arg0->unk_00.unk_24->unk_30[sp64], sp60);
                            LabPC_BindGridDeckData(arg0->unk_00.unk_24->unk_38[sp64],
                                          (u8*)arg0->unk_00.unk_24->unk_8C[sp60 >> 0x10].unk_00 +
                                              (arg0->unk_00.unk_24->unk_8C[sp60 >> 0x10].unk_0C * (sp60 & 0xFFFF)),
                                          sp60);
                        }
                        arg0->unk_28->unk_14(arg0->unk_28, 1);
                        var_s1 = 1;
                        break;

                    case 2:
                        LabPC_SwapMenu_SetState(arg0->unk_2C, 0);
                        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                        var_s1 |= 1;
                        break;

                    case 5:
                        LabPC_SwapMenu_SetState(arg0->unk_2C, 1);
                        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                        var_s1 |= 1;
                        break;

                    case 4:
                        LabPC_SwapMenu_SetState(arg0->unk_2C, 2);
                        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                        var_s1 |= 1;
                        break;

                    case 6:
                        Audio_PlaySoundEffectById(SFX_MENU_BACK);
                        var_s1 = 2;
                        if (LabPC_RunConfirmSaveFlow(arg0->unk_00.unk_24, arg1) == 0) {
                            var_s1 = 3;
                        }
                        break;

                    case 3:
                        LabPC_SwapMenu_SetState(arg0->unk_2C, 3);
                        LabPC_SwapMenu_NotifyModeChanged(arg0->unk_2C, 0);
                        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                        var_s1 |= 1;
                        break;
                    case 7:
                        LabPC_SwapMenu_SetState(arg0->unk_2C, 3);
                        LabPC_SwapMenu_NotifyModeChanged(arg0->unk_2C, 1);
                        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                        var_s1 |= 1;
                        break;
                }
                break;
        }
    } else if ((arg0->unk_00.unk_24->unk_40->unk_00.unk_28 & 1) && (var_s1 & 0x01000000)) {
        var_s1 = 1;
        sp5C = (arg1->buttonPressed & 0x20) != 0;
        sp58 = arg0->unk_2C->unk_34;
        switch (arg0->unk_00.unk_1C) {
            case 0:
                sp58 = sp5C;
                break;

            case 1:
                if (LabPC_SwapMenu_IsIdle(arg0->unk_2C) != 0) {
                    sp58 = sp5C;
                }
                break;
        }

        if (sp58 != arg0->unk_2C->unk_34) {
            LabPC_SwapMenu_SwapSides(arg0->unk_2C);
            LabPC_ReleaseSwapWidgets(arg0->unk_00.unk_24);
            LabPC_ModeToggleIcon_ToggleMode(arg0->unk_00.unk_24->unk_40);
            ((func8850BFB0)Memmap_GetFragmentVaddr(WidgetTree_UpdateVerticalMenuItems))(arg0);
            var_s1 = 0x80000005;
        }
    } else if (var_s1 & 0x02000000) {
        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 0);

        temp_v0_8 = LabPC_BoxLocationWidget_GetSelection(arg0->unk_00.unk_24->unk_30[1]);
        sp50 = temp_v0_8 & 0xFFFF;
        sp54 = temp_v0_8 >> 0x10;

        HAL_Strcpy(sp30, Text_GetString(NULL, 0, D_88224FB4, D_88217FBC[sp54]));

        if ((sp54 == 1) || (sp54 == 2)) {
            sprintf(&sp30[strlen(sp30)], " %d", sp50 + 1);
        }

        Text_SetStringToken(0x25, &sp30);
        Text_GetString(arg0->unk_00.unk_24->unk_88->unk_40, 0x80, D_88224FB4, 0x11);

        ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(arg0->unk_00.unk_24->unk_80, arg0->unk_00.unk_24->unk_88,
                                                               2, 0);
        ((func8850A3EC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelSilent))(arg0->unk_00.unk_24->unk_80, arg1);

        Audio_PlaySoundEffectById(0x29);

        var_s1 |= 2;
        if (LabPC_RunConfirmSaveFlow(arg0->unk_00.unk_24, arg1) == 0) {
            var_s1 |= 1;
        }
    }

    return var_s1;
}

#ifdef NON_MATCHING
void func_8820BE14(unk_func_8820BE14* arg0, s32 arg1, s32 arg2, s32 arg3, MemoryPool* arg4, s32 arg5, char** arg6,
                   char** arg7, char** arg8, char** arg9, char** argA, char** argB) {
    static Color_RGBA8 D_88217FC0 = { 0x1E, 0x50, 0x50, 0xFF };
    static Color_RGBA8 D_88217FC4 = { 0x00, 0x0A, 0x0A, 0xFF };

    WidgetNode* spC4;
    void* temp_v0;
    unk_func_882062E4* new_var;
    unk_func_88200FA0_030_038* var_s0;
    s32 spB4;
    s32 var_s2;
    s32 var_s3;
    s32 var_s2_2;
    s32 var_s3_2;
    unk_func_8820BE14_06C_000* spA0;
    unk_func_8820BE14_06C_000* ptr;
    unk_func_88200FA0_030_038* ptr2;
    s32 i;
    s32 j;
    unk_func_882062E4* var_s1;
    unk_func_8820BE14_06C_000* var_s4;
    unk_func_8820BE14_06C_000* var_s4_2;
    s32 count;
    unk_func_88500EE4* temp_s0;
    WidgetNode* temp_s0_4;
    unk_func_88509A2C* temp_s1;
    unk_func_88509E34* temp_s1_2;
    unk_func_885088F4* temp_s2;
    BattleMon* temp_v0_5;
    FragmentEntry temp_v0_7;
    void** temp_t0;

    spA0 = NULL;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, 0x9C);

    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    spB4 = GbSave_GetActivePort();

    var_s1 = mem_pool_alloc(arg4, sizeof(unk_func_882062E4) * (6 + (12 * 20) * 2));
    bzero(var_s1, sizeof(unk_func_882062E4) * (6 + (12 * 20) * 2));

    ByteMatrix_Allocate(&arg0->unk_6C, 0x10, 1, arg4);
    ByteMatrix_Allocate(&arg0->unk_7C, 0x10, 12, arg4);
    ByteMatrix_Allocate(&arg0->unk_8C, 0x10, 12, arg4);

    arg0->unk_6C.unk_08 = 1;
    ptr = arg0->unk_6C.unk_00;
    for (i = 0; i < 1; i++) {
        PointerList_Allocate(&ptr[i].unk_04, 6, arg4);
    }

    arg0->unk_7C.unk_08 = 12;
    ptr = arg0->unk_7C.unk_00;
    for (i = 0; i < 12; i++) {
        PointerList_Allocate(&ptr[i].unk_04, 20, arg4);
    }

    arg0->unk_8C.unk_08 = 12;
    ptr = arg0->unk_8C.unk_00;
    for (i = 0; i < 12; i++) {
        PointerList_Allocate(&ptr[i].unk_04, 20, arg4);
    }

    if (GbSave_GetBoxCount(spB4) == 0) {
        GbSave_MarkBoxDataLoaded(spB4);
    }

    var_s4_2 = var_s4 = arg0->unk_6C.unk_00;
    for (i = 0; i < 1; i++, var_s4_2++, var_s4++) {
        ptr2 = &var_s4_2->unk_04;
        count = LabPC_ReadDeckEntries(var_s1, 6, 0x20, spB4, i);
        var_s4_2->unk_04.unk_08 = count;

        for (j = 0; j < count; j++) {
            ptr2->unk_00[j] = var_s1++;
        }

        var_s4->unk_00 = 0;
    }

    var_s4_2 = var_s4 = arg0->unk_7C.unk_00;
    for (i = 0; i < 12; i++, var_s4_2++, var_s4++) {
        ptr2 = &var_s4_2->unk_04;
        count = LabPC_ReadDeckEntries(var_s1, 20, 0x21, spB4, i);
        var_s4_2->unk_04.unk_08 = count;

        for (j = 0; j < count; j++) {
            ptr2->unk_00[j] = var_s1++;
        }

        var_s4->unk_00 = 0;
    }

    var_s4_2 = var_s4 = arg0->unk_8C.unk_00;
    for (i = 0; i < 12; i++, var_s4_2++, var_s4++) {
        ptr2 = &var_s4_2->unk_04;
        count = LabPC_ReadDeckEntries(var_s1, 20, 0x11, 0, i);
        var_s4_2->unk_04.unk_08 = count;

        for (j = 0; j < count; j++) {
            ptr2->unk_00[j] = var_s1++;
        }

        var_s4->unk_00 = 0;
    }

    if (arg3 == 1) {
        temp_v0_5 = mem_pool_alloc(arg4, sizeof(BattleMon));
        func_88206110(temp_v0_5);

        spA0 = mem_pool_alloc(arg4, sizeof(unk_func_8820BE14_06C_000));
        PointerList_Allocate(&spA0->unk_04, 1, arg4);

        spA0->unk_04.unk_08 = 1;
        *spA0->unk_04.unk_00 = temp_v0_5;
        spA0->unk_00 = 0;
    }

    spC4 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func885031E8)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGate))(spC4, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, spC4);

    temp_s0 = mem_pool_alloc(arg4, sizeof(unk_func_88500EE4));
    ((func88500EE4)Memmap_GetFragmentVaddr(WidgetTree_InitTintedTexture))(temp_s0, 0, 0, 0x280, 0x1E0, D_88223E48, D_88217FC0,
                                                           D_88217FC4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spC4, temp_s0);

    temp_s2 = mem_pool_alloc(arg4, sizeof(unk_func_885088F4));
    ((func885088F4)Memmap_GetFragmentVaddr(WidgetTree_InitSlideTransition))(temp_s2, 0x41, 0x15C, 0xDC);
    temp_s2->unk_2C = 5;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spC4, temp_s2);

    temp_s1 = mem_pool_alloc(arg4, sizeof(unk_func_88509A2C));
    ((func88509A2C)Memmap_GetFragmentVaddr(WidgetTree_InitSaveSlotLabel))(temp_s1, 0x38, 0x22, GbSave_GetActivePort(),
                                                           Text_GetString(NULL, 0, D_88224FB0, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s2, temp_s1);

    temp_s1_2 = mem_pool_alloc(arg4, sizeof(unk_func_88509E34));
    ((func88509E34)Memmap_GetFragmentVaddr(WidgetTree_InitTextMessage))(temp_s1_2, 0, 0, Text_GetString(NULL, 0, D_88224FB4, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s2, temp_s1_2);

    temp_s0_4 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func885031E8)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGate))(temp_s0_4, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, temp_s0_4);

    temp_v0_7 = Fragment_Load(((((u32) fragment27_TEXT_START) & 0x0FF00000) >> 0x14) - 0x10, fragment27_ROM_START,
                             fragment28_ROM_START);

    arg0->unk_30.unk_04 = arg4;
    arg0->unk_30.unk_00 = 0x38;
    arg0->unk_30.unk_02 = 0x52;
    arg0->unk_30.unk_14 = temp_s0_4;
    arg0->unk_30.unk_18 = 0;

    arg0->unk_4C = arg7;
    arg0->unk_50 = D_88224FB8;
    arg0->unk_54 = D_88224FBC;
    arg0->unk_58 = arg8;
    arg0->unk_5C = arg9;
    arg0->unk_60 = argA;
    arg0->unk_64 = argB;

    temp_v0_7(0, &arg0->unk_30);

    arg0->unk_68 = mem_pool_alloc(arg4, sizeof(unk_func_88509F48));
    ((func88509F48)Memmap_GetFragmentVaddr(WidgetTree_InitMessagePanel))(arg0->unk_68, 0x2C, 0x4C, 0x228, 0x160, arg4, arg5);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_8820BE14_02C));
    func_88209B54(arg0->unk_2C, 0x2C, 0x4C, spA0, &arg0->unk_6C, spC4, temp_v0_7, &arg0->unk_30, arg0->unk_68, arg6,
                  arg4);

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s0_4, arg0->unk_2C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(&arg0->unk_00, arg0->unk_30.unk_08);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s0_4, arg0->unk_68);
}
#else
static Color_RGBA8 D_88217FC0 = { 0x1E, 0x50, 0x50, 0xFF };
static Color_RGBA8 D_88217FC4 = { 0x00, 0x0A, 0x0A, 0xFF };
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/lab_pc/lab_pc_1AE680/func_8820BE14.s")
#endif

void LabPC_RunSwapScreenLoop(unk_func_8820BE14* arg0) {
    volatile s32 sp34 = 0;

    while (sp34 == 0) {
        GeoRender_AdvanceFrameCounter();
        BgStage_DrawFrame();

        ((func885008C4)Memmap_GetFragmentVaddr(WidgetTree_Update))(&arg0->unk_00);
        ((func88500828)Memmap_GetFragmentVaddr(WidgetTree_Draw))(&arg0->unk_00, 0, 0);

        BgStage_AdvanceFrame();
        Ui_ReceiveMessage(&sp34);
    }
}

void LabPC_PokemonSessionThread(unk_func_8820BE14* arg0) {
    s32 sp24 = LabPC_RunSwapScreenModal(arg0->unk_2C, gPlayer1Controller);

    while (arg0->unk_2C->unk_2C->unk_00.unk_28 & 1) {
        Ui_SendMessageAndPollInput(0);
    }

    Ui_SendMessageAndPollInput(sp24);
    osStopThread(NULL);
}

void LabPC_PrizePokemonThread(unk_func_8820BE14* arg0) {
    s32 sp24;
    s32 var_s0;

    StageFade_StartFromOpaque(8);

    var_s0 = 8;
    while (var_s0-- > 0) {
        Ui_SendMessageAndPollInput(NULL);
    }

    sp24 = LabPC_RunSwapScreenModal(arg0->unk_2C, gPlayer1Controller);

    while (arg0->unk_2C->unk_2C->unk_00.unk_28 & 1) {
        Ui_SendMessageAndPollInput(NULL);
    }

    StageFade_StartFromTransparent(8);

    var_s0 = 10;
    while (var_s0-- > 0) {
        Ui_SendMessageAndPollInput(NULL);
    }

    Ui_SendMessageAndPollInput(sp24);

    osStopThread(NULL);
}

void LabPC_ShowPokemon(FontContext* arg0, s32 arg1) {
    static ThreadEntries D_88217FC8[] = { LabPC_PokemonSessionThread, LabPC_PrizePokemonThread };

    MemoryPool* sp5C;
    void* sp58;
    u8* sp54;
    func_88002628_sp38* sp50;
    char** sp4C;
    char** sp48;
    char** sp44;
    char** sp40;
    char** sp3C;
    char** sp38;

    main_pool_push_state('OTPC');

    FRAGMENT_LOAD(fragment25);

    PokeIcon_OpenModelArchive();

    sp54 = main_pool_alloc(0x10000, 0);
    sp5C = mem_pool_try_init(0x18000, 0);

    if (arg1 == 1) {
        Save_EnsureBankLoaded(2);
    }
    Text_InitStringTables();

    D_88224FB0 = Text_GetStringTable(0x2A);
    D_88224FB4 = Text_GetStringTable(2);
    D_88224FB8 = Text_GetStringTable(0x24);
    D_88224FBC = Text_GetStringTable(0x25);

    sp4C = Text_GetStringTable(7);
    sp48 = Text_GetStringTable(6);
    sp44 = Text_GetStringTable(0x26);
    sp40 = Text_GetStringTable(0x28);
    sp3C = Text_GetStringTable(0x29);
    sp38 = Text_GetStringTable(0xB);

    sp58 = mem_pool_alloc(sp5C, sizeof(unk_func_8820BE14));
    func_8820BE14(sp58, 0, 0, arg1, sp5C, arg0, sp4C, sp48, sp44, sp40, sp3C, sp38);

    sp50 = ALIGN16((u32)mem_pool_alloc(sp5C, sizeof(func_88002628_sp38)));

    osCreateThread(&sp50->thread, 0x32, D_88217FC8[arg1], sp58, sp54 + 0x10000, osGetThreadPri(NULL) - 1);

    Ui_InitInputMessageQueue();
    Input_SetRepeatController(gPlayer1Controller);

    osStartThread(&sp50->thread);

    LabPC_RunSwapScreenLoop(sp58);

    osDestroyThread(&sp50->thread);

    main_pool_pop_state('OTPC');
}
