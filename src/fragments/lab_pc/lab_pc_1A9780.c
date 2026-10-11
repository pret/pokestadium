#include "lab_pc.h"
#include "src/poke_icon.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/gb_data.h"
#include "src/pokemon_stats.h"
#include "src/save_data.h"
#include "src/game_state.h"
#include "src/table_view.h"
#include "src/text_system.h"
#include "src/gb_save.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/hal_libc.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/fragments/lab_ui_support/lab_ui_support.h"

typedef struct unk_func_88201488_arg2 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char pad01[0x23];
    /* 0x24 */ u8 unk_24;
} unk_func_88201488_arg2; // size = 0x28

extern s32 D_4006A08;

static char** D_88224FA0;
static char** D_88224FA4;

void LabPC_MarkBoxSeen(unk_func_88205880_00D0* arg0) {
    s32 i;
    s32 temp_s3;
    BattleMon* tmp = arg0->unk_000;

    temp_s3 = GbSave_GetActivePort();

    for (i = 0; i < arg0->unk_690; i++, tmp++) {
        if ((tmp->unk_00.unk_00 > 0) && (tmp->unk_00.unk_00 < 0x98)) {
            GbSave_SetSeenOwnedBits(temp_s3, tmp->unk_00.unk_00, 3);
        }
    }
}

void LabPC_WriteBoxEntries(s32 arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3) {
    DeckHandle* sp1C = Deck_Open(arg0, arg1, arg2, 1);

    Deck_WriteEntries(arg3, arg3->unk_690, sp1C);

    if ((arg0 == 0x10) || (arg0 == 0x11) || (arg0 == 0x12)) {
        Deck_CloseAndFlushBox(sp1C);
    } else {
        Deck_CloseAndFlush(sp1C);
    }
}

s32 LabPC_ReadBoxEntries(s32 arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3, s32 arg4) {
    s32 sp1C;
    DeckHandle* sp18;

    sp18 = Deck_Open(arg0, arg1, arg2, 0);
    if (sp18 == 0) {
        return 0;
    }
    sp1C = Deck_ReadEntries(&arg3->unk_000, arg4, sp18);
    Deck_CloseAndFlush(sp18);
    return sp1C;
}

void LabPC_LoadAllBoxes(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 temp_v0;

    for (i = 0; i < arg3; i++, arg0++) {
        bzero(arg0->unk_000, sizeof(BattleMon) * 20);
        arg0->unk_690 = LabPC_ReadBoxEntries(arg1, arg2, i, arg0, 0x14);
        arg0->unk_694 = arg1;
        arg0->unk_698 = i;
        arg0->unk_69C = 0;
    }
}

s32 LabPC_NoEmptyBoxAvailable(unk_func_88205880_A030* arg0) {
    s32 i;
    unk_func_88205880_00D0** var_a0 = arg0->unk_00;

    for (i = 0; i < arg0->unk_08; i++) {
        if (var_a0[i]->unk_690 == 0) {
            return 0;
        }
    }

    return 1;
}

s32 LabPC_AllBoxesEmpty(unk_func_88205880_A030* arg0) {
    s32 i;
    unk_func_88205880_00D0** var_a0 = arg0->unk_00;

    for (i = 0; i < arg0->unk_08; i++) {
        if (var_a0[i]->unk_690 > 0) {
            return 0;
        }
    }

    return 1;
}

void func_88201488(s32 arg0, s32 arg1, unk_func_88201488_arg2** arg2, s32 arg3, s32 arg4, unk_func_88200FA0_030_030* arg5) {
    static Color_RGBA8 D_88217C20 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88217C24 = { 0x28, 0x28, 0x64, 0xFF };
    static Color_RGBA8 D_88217C28 = { 0x3C, 0x3C, 0x82, 0xFF };
    static Color_RGBA8 D_88217C2C = { 0x78, 0x78, 0x96, 0xFF };
    s32 pad;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    {
        s32 color = GPACK_RGBA5551(D_88217C24.r, D_88217C24.g, D_88217C24.b, 1);
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
        gDPFillRectangle(gDisplayListHead++, arg0 + 1, arg1 + 1, ((0, arg0) + arg5->unk_3C) - 2, arg1 + 0x31);
    }
    {
        s32 color = GPACK_RGBA5551(D_88217C28.r, D_88217C28.g, D_88217C28.b, 1);
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
        gDPFillRectangle(gDisplayListHead++, arg0 + 1, arg1 + 0x32, ((0, arg0) + arg5->unk_3C) - 2, arg1 + 0x49);
    }
    {
        s32 color = GPACK_RGBA5551(D_88217C2C.r, D_88217C2C.g, D_88217C2C.b, 1);
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
        gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_3C + arg0) - 1, arg1);
    }
    {
        s32 color = GPACK_RGBA5551(D_88217C2C.r, D_88217C2C.g, D_88217C2C.b, 1);
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
        gDPFillRectangle(gDisplayListHead++, arg0, (arg1 + arg5->unk_3E) - 1, (arg5->unk_3C + arg0) - 1,
                         (arg1 + arg5->unk_3E) - 1);
    }
    {
        s32 color = GPACK_RGBA5551(D_88217C2C.r, D_88217C2C.g, D_88217C2C.b, 1);
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
        gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, arg0, (arg1 + arg5->unk_3E) - 2);
    }
    {
        s32 color = GPACK_RGBA5551(D_88217C2C.r, D_88217C2C.g, D_88217C2C.b, 1);
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
        gDPFillRectangle(gDisplayListHead++, (arg5->unk_3C + arg0) - 1, arg1 + 1, (arg5->unk_3C + arg0) - 1,
                         (arg1 + arg5->unk_3E) - 2);
    }

    if (arg2 != NULL) {
        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
        gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
        gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
        gDPLoadTextureBlock(gDisplayListHead++, arg2 + 2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 40, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (arg0 + 0x30) << 2, (arg1 + 6) << 2, (arg0 + 0x57) << 2,
                            (arg1 + 0x2D) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
        gDPPipeSync(gDisplayListHead++);
        gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

        if (((*arg2)->unk_00 > 0) && ((*arg2)->unk_00 < 0x98)) {
            gDPPipeSync(gDisplayListHead++);
            gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
            gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
            gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
            gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            gDPLoadTextureBlock(gDisplayListHead++, &D_4006A08, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 10, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, (arg0 + 0xA) << 2, (arg1 + 0x1F) << 2, (arg0 + 0x12) << 2,
                                (arg1 + 0x29) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
            Gfx_DrawNumber(arg0 + 0x14, arg1 + 0x1D, (*arg2)->unk_24);
        }

        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(D_88217C20.r, D_88217C20.g, D_88217C20.b, D_88217C20.a);
        Font_SetActive(8, 0);
        Font_Printf(((arg5->unk_3C - Font_MeasureTextExtent(0, 0, (char*)*arg2 + 0x30)) / 2) + arg0, arg1 + 0x34,
                    (char*)*arg2 + 0x30);
        Font_EndTexturedTextRendering();
    }
}

void func_88201DA0(unk_func_88201DA0* arg0, s32 arg1, s32 arg2, WidgetNode* arg3, FragmentEntry arg4,
                   unk_func_88205880_0098* arg5, MemoryPool* arg6) {
    static Color_RGBA8 D_88217C30 = { 0x32, 0x64, 0x64, 0xFF };

    UNUSED s32 pad[2];
    unk_func_88503298* sp44;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_88201DA0));

    arg0->unk_00.unk_20 = LabPC_CheckBox_HandleInput;
    arg0->unk_00.unk_24 = LabPC_CheckBox_SetSelectedIndex;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_34 = main_pool_alloc(0xFAA0, 0);
    arg0->unk_48 = arg4;
    arg0->unk_4C = arg5;

    arg0->unk_2C = mem_pool_alloc(arg6, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, 0x212, 0x148);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    arg0->unk_58 = mem_pool_alloc(arg6, sizeof(unk_func_8850182C));
    ((func8850182C)Memmap_GetFragmentVaddr(WidgetTree_InitCornerFrame))(arg0->unk_58, 0, 0, arg0->unk_2C->unk_00.unk_14.unk_00, 0x1C,
                                                           D_88217C30);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_58);

    arg0->unk_50 = mem_pool_alloc(arg6, sizeof(unk_func_8850878C));
    arg0->unk_54 = mem_pool_alloc(arg6, sizeof(char) * 18);
    arg0->unk_54[0] = '\x00';
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_50, 0, 4, arg0->unk_54, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_58, arg0->unk_50);

    arg0->unk_30 = mem_pool_alloc(arg6, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_30, 0, 0x1C, func_88201488, 0x6A, 0x4B, 4, 5,
                                                           arg6);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_30, 0x14, arg6);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_30);

    sp44 = mem_pool_alloc(arg6, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(sp44, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, sp44);

    LabPC_CheckBox_SetSelectedIndex(&arg0->unk_00, 1);
}

void LabPC_CheckBox_SetTitle(unk_func_88201DA0* arg0, u32 arg1, u32 arg2) {
    static u16 D_88217C34[] = { 0x32, 0x33 };
    static Color_RGBA8 D_88217C38[] = {
        { 0x96, 0x64, 0x1E, 0xFF },
        { 0x32, 0x64, 0x64, 0xFF },
    };

    HAL_Strcpy(arg0->unk_54, Text_GetString(NULL, 0, D_88224FA4, D_88217C34[arg1 - 1]));
    sprintf(&arg0->unk_54[strlen(arg0->unk_54)], " No.%d", arg2 + 1);

    arg0->unk_50->unk_00.unk_10.unk_00 =
        (arg0->unk_2C->unk_00.unk_14.unk_00 - Font_MeasureTextExtent(arg0->unk_50->unk_2C, arg0->unk_50->unk_38, arg0->unk_54)) /
        2;
    arg0->unk_58->unk_2C = D_88217C38[arg1 - 1];
}

void LabPC_CheckBox_ShowBox(unk_func_88201DA0* arg0, unk_func_88205880_00D0* arg1, u32 arg2) {
    BattleMon* ptr = arg1->unk_000;
    s32 i;

    arg0->unk_5C = arg1;
    arg0->unk_60 = arg2;

    for (i = 0; i < arg1->unk_690; i++, ptr++) {
        arg0->unk_34[i].unk_000 = ptr;
        PokeIcon_LoadModelTextureForMon(&arg0->unk_34[i].unk_008, 0, ptr);
    }

    TableView_Initialize(&arg0->unk_38, arg0->unk_34, 0xC88, 0x14, arg1->unk_690);

    ((func885063B8)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridStridedData))(arg0->unk_30, &arg0->unk_38);

    LabPC_CheckBox_SetTitle(arg0, arg2 >> 0x10, arg2 & 0xFFFF);
}

void LabPC_CheckBox_SetSelectedIndex(unk_func_88203ED8* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_30->unk_00.unk_24(arg0->unk_30, arg1);
}

s32 LabPC_CheckBox_HandleInput(unk_func_88201DA0* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
        if (var_v1 == 0) {
            if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            } else if (arg1->buttonPressed & 0x8000) {
                Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);

                arg0->unk_4C->unk_0C = arg0->unk_34[arg0->unk_30->unk_38].unk_000;
                arg0->unk_4C->unk_10 = arg0->unk_60 >> 0x10;

                arg0->unk_48(1, arg0->unk_4C);

                arg0->unk_30->unk_00.unk_24(arg0->unk_30, 0x100);
                if (arg0->unk_48(4, arg0->unk_4C) == 1) {
                    arg0->unk_5C->unk_69C = 1;
                }
                arg0->unk_30->unk_00.unk_24(arg0->unk_30, 1);
                var_v1 = 1;
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void LabPC_CheckBox_ModalLoop(unk_func_88201DA0* arg0, Controller* arg1) {
    s32 var_s0;
    s32 var_s1 = NULL;

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);

    while (var_s1 == 0) {
        Ui_SendMessageAndPollInput(var_s1);
        var_s0 = LabPC_CheckBox_HandleInput(arg0, arg1);
        if (!(var_s0 & 1) && (var_s0 & 2)) {
            var_s0 |= 1;
            var_s1 = 1;
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(var_s0);
    }
    arg0->unk_2C->unk_2C = 0xB;
}

void LabPC_DrawBoxCount(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88217C40 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char sp28[8];
    s32 sp24 = Font_MeasureTextExtent(4, 0, "00");
    UNUSED s32 pad;

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);
    Gfx_SetEnvColor(D_88217C40.r, D_88217C40.g, D_88217C40.b, D_88217C40.a);
    sprintf(sp28, "%d", arg0->unk_690);
    Font_Printf(((arg1 + sp24) - Font_MeasureTextExtent(0, 0, sp28)) + 0x1C, arg2 + 4, sp28);
    Font_EndTexturedTextRendering();
    if (arg0->unk_690 > 0) {
        Gfx_DrawTiledTextureStrip(&D_800758E0, arg1, arg2 + 2);
    }
}

void LabPC_BuildBoxCountLabel(unk_func_8820253C* arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8820253C));

    arg0->unk_00.unk_18 = LabPC_BoxCountLabel_Draw;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    LabPC_BoxCountLabel_SetBox(arg0, arg3);
}

void LabPC_BoxCountLabel_SetBox(unk_func_8820253C* arg0, unk_func_88205880_00D0* arg1) {
    arg0->unk_2C = arg1;
}

s32 LabPC_BoxCountLabel_Draw(unk_func_8820253C* arg0, s32 arg1, s32 arg2) {
    if (arg0->unk_2C != NULL) {
        LabPC_DrawBoxCount(arg0->unk_2C, arg1, arg2);
    }
}

void LabPC_BuildBoxPairSelector(unk_func_882025E0_1A9780* arg0, unk_func_88200FA0_030_030* arg1, unk_func_88200FA0_030_030* arg2,
                   unk_func_88203ED8* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88217C44 = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 i;
    char* temp_s2;

    ((func88500668)Memmap_GetFragmentVaddr(WidgetTree_InitNode))(arg0, sizeof(unk_func_882025E0_1A9780));

    arg0->unk_00.unk_14 = LabPC_BoxPairSelector_SetFlags;
    arg0->unk_00.unk_10 = LabPC_BoxPairSelector_HandleInput;
    arg0->unk_00.unk_18 = 0;
    arg0->unk_00.unk_1C = 0;
    arg0->unk_24[0] = arg1;
    arg0->unk_24[1] = arg2;
    arg0->unk_38 = 1;
    arg0->unk_00.unk_20 = arg3;
    arg0->unk_2C = 0;

    for (i = 0; i < 5; i++) {
        temp_s2 = Text_GetString(NULL, 0, D_88224FA4, i + 6);

        arg0->unk_3C[i].unk_00 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_3C[i].unk_00, 0, 0, temp_s2, 0x10);
        arg0->unk_3C[i].unk_00->unk_30 = D_88217C44;
        arg0->unk_3C[i].unk_00->unk_44 = arg0->unk_3C[i].unk_00->unk_44;
        arg0->unk_3C[i].unk_08 = 0;
        arg0->unk_3C[i].unk_04 = 0;
    }
}

void LabPC_BoxPairSelector_SetFlags(unk_func_882025E0_1A9780* arg0, s32 arg1) {
    arg0->unk_00.unk_18 = arg1;
    LabPC_BoxPairSelector_Refresh(arg0);
}

void LabPC_BoxPairSelector_Refresh(unk_func_882025E0_1A9780* arg0) {
    s32 i;
    s32 temp_s3 = arg0->unk_00.unk_18 & 0xFF;
    s32 temp_s4 = arg0->unk_00.unk_18 & 0xFF00;
    s32 var_v0;

    for (i = 0; i < 2; i++) {
        var_v0 = 0;
        if (i == arg0->unk_00.unk_1C) {
            var_v0 = 1;
        }
        arg0->unk_24[i]->unk_00.unk_24(&arg0->unk_24[i]->unk_00, (var_v0 & temp_s3) | temp_s4);
    }
}

void LabPC_BoxPairSelector_SetActiveSide(unk_func_882025E0_1A9780* arg0, s32 arg1) {
    arg0->unk_00.unk_1C = arg1;
    LabPC_BoxPairSelector_Refresh(arg0);
}

void LabPC_BoxPairSelector_GetSelectedBoxes(unk_func_882025E0_1A9780* arg0, unk_func_88205880_00D0** arg1, unk_func_88205880_00D0** arg2) {
    switch (arg0->unk_2C) {
        case 0:
            *arg1 = arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_24[0]->unk_38];
            *arg2 = NULL;
            break;

        case 1:
            *arg1 = arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_34];
            *arg2 = arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_24[0]->unk_38];
            break;

        case 2:
            *arg1 = arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_24[0]->unk_38];
            *arg2 = arg0->unk_24[1]->unk_2C->unk_00[arg0->unk_24[1]->unk_38];
            break;
    }
}

void LabPC_BoxPairSelector_GetSelectedBoxIds(unk_func_882025E0_1A9780* arg0, WidgetPoint* arg1, WidgetPoint* arg2) {
    switch (arg0->unk_2C) {
        case 0:
            arg1->unk_00 = arg0->unk_24[0]->unk_00.unk_10.unk_00;
            arg1->unk_02 = arg0->unk_24[0]->unk_00.unk_10.unk_02 + (arg0->unk_24[0]->unk_38 * arg0->unk_24[0]->unk_3E);

            arg2->unk_00 = arg0->unk_24[1]->unk_00.unk_10.unk_00;
            arg2->unk_02 = arg0->unk_24[1]->unk_00.unk_10.unk_02 + (arg0->unk_24[1]->unk_38 * arg0->unk_24[1]->unk_3E);
            break;

        case 1:
            arg1->unk_00 = arg0->unk_24[0]->unk_00.unk_10.unk_00;
            arg1->unk_02 = arg0->unk_24[0]->unk_00.unk_10.unk_02 + (arg0->unk_34 * arg0->unk_24[0]->unk_3E);

            arg2->unk_00 = arg0->unk_24[0]->unk_00.unk_10.unk_00;
            arg2->unk_02 = arg0->unk_24[0]->unk_00.unk_10.unk_02 + (arg0->unk_24[0]->unk_38 * arg0->unk_24[0]->unk_3E);
            break;

        case 2:
            arg1->unk_00 = arg0->unk_24[0]->unk_00.unk_10.unk_00;
            arg1->unk_02 = arg0->unk_24[0]->unk_00.unk_10.unk_02 + (arg0->unk_24[0]->unk_38 * arg0->unk_24[0]->unk_3E);

            arg2->unk_00 = arg0->unk_24[1]->unk_00.unk_10.unk_00;
            arg2->unk_02 = arg0->unk_24[1]->unk_00.unk_10.unk_02 + (arg0->unk_24[1]->unk_38 * arg0->unk_24[1]->unk_3E);
            break;
    }
}

void LabPC_DisableEmptyBoxes(unk_func_88200FA0_030_030* arg0) {
    s32 i;
    s32 count = arg0->unk_2C->unk_08;
    unk_func_88205880_00D0** temp_v0 = arg0->unk_2C->unk_00;

    for (i = 0; i < count; i++) {
        if (temp_v0[i]->unk_690 == 0) {
            arg0->unk_34[i] |= 4;
        }
    }

    ((func88506CE4)Memmap_GetFragmentVaddr(WidgetTree_FindSelectableGridEntry))(arg0);
}

void LabPC_DisableNonEmptyBoxes(unk_func_88200FA0_030_030* arg0) {
    s32 i;
    s32 count = arg0->unk_2C->unk_08;
    unk_func_88205880_00D0** temp_v0 = arg0->unk_2C->unk_00;

    for (i = 0; i < count; i++) {
        if (temp_v0[i]->unk_690 > 0) {
            arg0->unk_34[i] |= 4;
        }
    }

    ((func88506CE4)Memmap_GetFragmentVaddr(WidgetTree_FindSelectableGridEntry))(arg0);
}

void LabPC_BoxPairSelector_RefreshDisabledBoxes(unk_func_882025E0_1A9780* arg0) {
    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_24[0]);
    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_24[1]);

    switch (arg0->unk_2C) {
        case 0:
            LabPC_DisableEmptyBoxes(arg0->unk_24[0]);
            LabPC_DisableNonEmptyBoxes(arg0->unk_24[1]);
            break;

        case 1:
        case 2:
        case 3:
            LabPC_DisableEmptyBoxes(arg0->unk_24[0]);
            LabPC_DisableEmptyBoxes(arg0->unk_24[1]);
            break;
    }
}

void LabPC_BoxPairSelector_SetStage(unk_func_882025E0_1A9780* arg0, s32 arg1) {
    switch (arg1) {
        case 0:
            LabPC_BoxPairSelector_RefreshDisabledBoxes(arg0);
            LabPC_SetGridBorderActive(arg0->unk_24[0], 1);
            LabPC_SetGridBorderActive(arg0->unk_24[1], 1);
            LabPC_BoxPairSelector_SetActiveSide(arg0, 0);
            LabPC_ModeToggleIcon_ClearPressed(arg0->unk_00.unk_20->unk_40);
            break;

        case 1:
            LabPC_SetGridBorderActive(arg0->unk_24[1], 0);
            LabPC_BoxPairSelector_SetActiveSide(arg0, 1);
            LabPC_ModeToggleIcon_SetPressed(arg0->unk_00.unk_20->unk_40);
            break;

        case 2:
            LabPC_SetGridBorderActive(arg0->unk_24[0], 0);
            LabPC_BoxPairSelector_SetActiveSide(arg0, 0);
            LabPC_ModeToggleIcon_SetPressed(arg0->unk_00.unk_20->unk_40);
            break;

        case 3:
            LabPC_SetGridBorderActive(arg0->unk_24[1], 0);
            LabPC_BoxPairSelector_SetActiveSide(arg0, 1);
            LabPC_ModeToggleIcon_SetPressed(arg0->unk_00.unk_20->unk_40);
            break;
    }
    arg0->unk_30 = arg1;
}

void LabPC_BoxPairSelector_SetMode(unk_func_882025E0_1A9780* arg0, s32 arg1) {
    arg0->unk_2C = arg1;
    LabPC_BoxPairSelector_SetStage(arg0, 0);
}

void LabPC_BoxPairSelector_Reset(unk_func_882025E0_1A9780* arg0) {
    LabPC_BoxPairSelector_SetStage(arg0, 0);
}

void LabPC_BoxPairSelector_SwapSides(unk_func_882025E0_1A9780* arg0) {
    unk_func_88200FA0_030_030* temp_t6 = arg0->unk_24[0];

    arg0->unk_24[0] = arg0->unk_24[1];
    arg0->unk_24[1] = temp_t6;

    arg0->unk_38 = !arg0->unk_38;
}

s32 LabPC_BoxPairSelector_IsInitialStage(unk_func_882025E0_1A9780* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_30 == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void LabPC_BoxPairSelector_ReorderSwap(unk_func_882025E0_1A9780* arg0) {
    unk_func_88205880_00D0** temp_v0 = &arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_34];
    unk_func_88205880_00D0** temp_a2 = &arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_24[0]->unk_38];
    unk_func_88205880_00D0* temp_a3;

    temp_a3 = *temp_a2;
    *temp_a2 = *temp_v0;
    *temp_v0 = temp_a3;
}

void LabPC_BoxPairSelector_ExchangeSwap(unk_func_882025E0_1A9780* arg0) {
    unk_func_88205880_00D0* temp_a3;
    unk_func_88205880_00D0** temp_v0 = &arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_24[0]->unk_38];
    unk_func_88205880_00D0** temp_a1 = &arg0->unk_24[1]->unk_2C->unk_00[arg0->unk_24[1]->unk_38];

    temp_a3 = *temp_a1;
    *temp_a1 = *temp_v0;
    *temp_v0 = temp_a3;
}

s32 LabPC_BoxPairSelector_HandleInput(unk_func_882025E0_1A9780* arg0, Controller* arg1) {
    s32 var_a2;

    var_a2 = arg0->unk_24[arg0->unk_00.unk_1C]->unk_00.unk_20(arg0->unk_24[arg0->unk_00.unk_1C], arg1);

    if (var_a2 & 1) {
        return var_a2;
    }

    if (var_a2 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_a2 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_a2 = 0x80000004;
        }
    }

    switch (arg0->unk_30) {
        case 0:
            if (var_a2 & 2) {
                ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_00.unk_20->unk_6C->unk_24[0]);
                ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_00.unk_20->unk_6C->unk_24[1]);
            } else if (var_a2 & 4) {
                switch (arg0->unk_2C) {
                    case 0:
                        if (LabPC_AllBoxesEmpty(arg0->unk_24[0]->unk_2C) != 0) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                arg0->unk_00.unk_20->unk_60, arg0->unk_3C[0].unk_00, arg0->unk_3C[0].unk_04,
                                arg0->unk_3C[0].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_00.unk_20->unk_60, arg1);
                            var_a2 = 1;
                        } else if (LabPC_NoEmptyBoxAvailable(arg0->unk_24[1]->unk_2C) != 0) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                arg0->unk_00.unk_20->unk_60, arg0->unk_3C[4].unk_00, arg0->unk_3C[4].unk_04,
                                arg0->unk_3C[4].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_00.unk_20->unk_60, arg1);
                            var_a2 = 1;
                        } else {
                            arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 2;
                            LabPC_BoxPairSelector_SetStage(arg0, 1);
                            var_a2 |= 1;
                        }
                        break;

                    case 1:
                        if (LabPC_AllBoxesEmpty(arg0->unk_24[0]->unk_2C) != 0) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                arg0->unk_00.unk_20->unk_60, arg0->unk_3C[1].unk_00, arg0->unk_3C[1].unk_04,
                                arg0->unk_3C[1].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_00.unk_20->unk_60, arg1);
                            var_a2 = 1;
                        } else {
                            arg0->unk_34 = arg0->unk_24[0]->unk_38;
                            ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_24[0]);
                            arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 2;
                            LabPC_BoxPairSelector_SetStage(arg0, 2);
                            var_a2 |= 1;
                        }
                        break;

                    case 2:
                        if ((LabPC_AllBoxesEmpty(arg0->unk_24[0]->unk_2C) != 0) ||
                            (LabPC_AllBoxesEmpty(arg0->unk_24[1]->unk_2C) != 0)) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                arg0->unk_00.unk_20->unk_60, arg0->unk_3C[2].unk_00, arg0->unk_3C[2].unk_04,
                                arg0->unk_3C[2].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_00.unk_20->unk_60, arg1);
                            var_a2 = 1;
                        } else {
                            arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 2;
                            LabPC_BoxPairSelector_SetStage(arg0, 3);
                            var_a2 |= 1;
                        }
                        break;

                    case 3:
                        if (LabPC_AllBoxesEmpty(arg0->unk_24[0]->unk_2C) != 0) {
                            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                            ((func8850A10C)Memmap_GetFragmentVaddr(WidgetTree_SetMessagePanelText))(
                                arg0->unk_00.unk_20->unk_60, arg0->unk_3C[3].unk_00, arg0->unk_3C[3].unk_04,
                                arg0->unk_3C[3].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(WidgetTree_RunMessagePanelWithSound))(arg0->unk_00.unk_20->unk_60, arg1);
                            var_a2 = 1;
                        }
                        break;
                }
            }
            break;

        case 1:
            if (var_a2 & 2) {
                LabPC_BoxPairSelector_SetStage(arg0, 0);
                var_a2 |= 1;
            } else if (var_a2 & 4) {
                arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 0x100;
            }
            break;

        case 2:
            if (var_a2 & 2) {
                LabPC_BoxPairSelector_SetStage(arg0, 0);
                var_a2 |= 1;
            } else if (var_a2 & 4) {
                if (arg0->unk_34 == arg0->unk_24[0]->unk_38) {
                    var_a2 = 0x80000101;
                } else {
                    arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 2;
                    arg0->unk_24[0]->unk_34[arg0->unk_34] |= 0x100;
                    arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 0x100;
                }
            }
            break;

        case 3:
            if (var_a2 & 2) {
                LabPC_BoxPairSelector_SetStage(arg0, 0);
                var_a2 |= 1;
            } else if (var_a2 & 4) {
                arg0->unk_24[1]->unk_34[arg0->unk_24[1]->unk_38] |= 2;
                arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 0x100;
                arg0->unk_24[1]->unk_34[arg0->unk_24[1]->unk_38] |= 0x100;
            }
            break;
    }
    return var_a2;
}

static Color_RGBA8 D_88217C48 = { 0xF0, 0xF0, 0xF0, 0xFF };
static Color_RGBA8 D_88217C4C = { 0x5A, 0x5A, 0xA6, 0xFF };
static Color_RGBA8 D_88217C50 = { 0x40, 0x40, 0x74, 0xFF };
static Color_RGBA8 D_88217C54[] = {
    { 0x78, 0x78, 0xF1, 0xFF },
    { 0x5E, 0x5E, 0xBE, 0xFF },
};

void func_88203538(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4, unk_func_88200FA0_030_030* arg5) {
    Color_RGBA8 sp8C;
    Color_RGBA8 sp88;
    s32 pad[1];
    char* sp80;
    char sp7C[4];
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 pad2[2];

    if (arg4 & 2) {
        sp8C = Color_ScaleRgb(D_88217C50, 1.4f);
    } else {
        sp8C = *(Color_RGBA8 *)&D_88217C50;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, 0, 0);

    {
        u32 color = GPACK_RGBA5551(sp8C.r, sp8C.g, sp8C.b, 1);
        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
        gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, ((arg5->unk_3C + arg0) - 1), ((arg1 + arg5->unk_3E) - 2));
    }

    {
        u32 color = GPACK_RGBA5551(D_88217C54[1].r, D_88217C54[1].g, D_88217C54[1].b, 1); gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
        gDPFillRectangle(gDisplayListHead++, arg0, arg1, ((arg5->unk_3C + arg0) - 1), arg1);
    }
    
    {
        u32 color = GPACK_RGBA5551(D_88217C54[1].r, D_88217C54[1].g, D_88217C54[1].b, 1); gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (color << 16) | color);
        gDPFillRectangle(gDisplayListHead++, arg0, ((arg1 + arg5->unk_3E) - 1), ((arg5->unk_3C + arg0) - 1), ((arg1 + arg5->unk_3E) - 1));
    }


    sp88 = D_88217C48;
    if (arg4 & 4) {
        sp88.a = 0x4C;
    }
    sp80 = Text_GetString(0, 0, D_88224FA4, 0x31);
    sp78 = Font_MeasureTextExtent(8, 0, sp80);
    sp74 = Font_MeasureTextExtent(8, 0, " 00");
    sp70 = Font_MeasureTextExtent(4, 0, "00");
    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
    Gfx_SetEnvColor(sp88.r, sp88.g, sp88.b, sp88.a);
    Font_Printf(arg0 + 0x19, arg1 + 2, sp80);
    sprintf(sp7C, "%d", arg3 + 1);
    Font_Printf(((arg0 + sp78 + sp74) - Font_MeasureTextExtent(0, 0, sp7C)) + 0x19, arg1 + 2, sp7C);
    Font_EndTexturedTextRendering();
    if (!(arg4 & 0x100)) {
        LabPC_DrawBoxCount(arg2, ((arg5->unk_3C + arg0) - sp70) - 0x35, arg1);
    }
}

void LabPC_BuildBoxLabelTab(unk_func_8820399C* arg0, s32 arg1, unk_func_8850143C* arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8820399C));

    arg0->unk_00.unk_18 = LabPC_DrawBoxLabelTab;
    arg0->unk_00.unk_14.unk_00 = arg2->unk_00.unk_14.unk_00;
    arg0->unk_00.unk_14.unk_02 = arg2->unk_00.unk_14.unk_02;
    arg0->unk_2C = GbSave_GameToCategoryIndex(GbSave_GetPortGame(GbSave_GetActivePort()));
    arg0->unk_30 = arg1;
}

s32 LabPC_DrawBoxLabelTab(unk_func_8820399C* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88217C5C = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp2C;
    s32 temp_v0;
    s32 var_s0;

    if (arg0->unk_30 == 0) {
        sp2C = Text_GetString(NULL, 0, D_88224FA4, 0xB);
    } else {
        sp2C = Text_GetString(NULL, 0, D_88224FA4, 0xC);
    }
    temp_v0 = Font_MeasureTextExtent(8, 0, sp2C);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    if (arg0->unk_30 == 0) {
        var_s0 = (((arg0->unk_00.unk_14.unk_00 - temp_v0) - 0x20) / 2) + arg1 + 0x20;

        gDPLoadTextureBlock(gDisplayListHead++, D_88223470[arg0->unk_2C], G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 26, 0,
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
    Gfx_SetEnvColor(D_88217C5C.r, D_88217C5C.g, D_88217C5C.b, D_88217C5C.a);
    Font_SetActive(8, 0);
    Font_Printf(var_s0, arg2 + 5, sp2C);
    Font_EndTexturedTextRendering();

    return 0;
}

void func_88203ED8(unk_func_88203ED8* arg0, s32 arg1, s32 arg2, unk_func_88205880_A030* arg3,
                   WidgetNode* arg4, unk_func_88201DA0* arg5, FontContext* arg6, char** arg7,
                   MemoryPool* arg8) {
    static Color_RGBA8 D_88217C60 = { 0x6C, 0x6C, 0x7E, 0xFF };
    static Color_RGBA8 D_88217C64 = { 0x50, 0x50, 0x86, 0xFF };
    static Color_RGBA8 D_88217C68 = { 0x79, 0x79, 0xCB, 0xFF };
    static unk_D_88217C6C D_88217C6C[] = {
        {
            249,
            36,
            54,
            42,
            D_88218FD0,
            48,
            D_882181B8,
            0,
        },
        {
            249,
            84,
            54,
            42,
            D_88219D58,
            48,
            D_882181C0,
            1,
        },
        {
            249,
            132,
            54,
            42,
            D_8821AAE0,
            48,
            D_882181C8,
            0,
        },
        {
            249,
            180,
            54,
            42,
            D_8821B868,
            48,
            D_882181D0,
            1,
        },
        {
            249,
            228,
            54,
            42,
            D_88218248,
            48,
            D_882181B0,
            0,
        },
    };
    static Color_RGBA8 D_88217CE4 = { 0xFF, 0xFF, 0x00, 0xFF };
    static Color_RGBA8 D_88217CE8 = { 0x2D, 0x1A, 0x41, 0xFF };
    static Color_RGBA8 D_88217CEC = { 0x6F, 0x5F, 0x7F, 0xFF };
    static Color_RGBA8* D_88217CF0[5] = { D_882181F0, D_88218208, D_88218200, D_88218210, D_882181F8 };

    s32 pad[7];
    s32 x;
    s32 spB4;
    s32 i;
    s32 j;
    unk_func_885012A4* spA8;
    unk_func_885012A4* spA4;
    unk_func_885012A4* spA0;
    unk_func_885012A4* sp9C;
    unk_func_885012A4* sp98;
    WidgetNode* sp94;
    WidgetNode* sp90;
    unk_func_8850143C* sp8C;
    unk_func_8850143C* sp88;
    char* temp_s1_2;
    WidgetAnimatedFrame* temp_s0;
    unk_func_8850143C* temp_s0_2;
    unk_func_8850878C* temp_s0_3;
    unk_func_88503298* temp_s0_4;
    s32 pad2[3];

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_88203ED8));
    arg0->unk_00.unk_1C = LabPC_BoxMenu_OnShow;
    arg0->unk_00.unk_20 = LabPC_BoxMenu_HandleInput;
    arg0->unk_00.unk_24 = LabPC_BoxMenu_SetVisible;
    // clang-format off
    arg0->unk_00.unk_10.unk_00 = arg1; arg0->unk_00.unk_10.unk_02 = arg2;
    // clang-format on
    arg0->unk_5C = arg5;

    arg0->unk_64 = mem_pool_alloc(arg8, sizeof(unk_func_88203ED8_064));
    LabPC_BoxMenu_InitFocusNode(arg0->unk_64, arg0);

    arg0->unk_2C = mem_pool_alloc(arg8, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, 0x228, 0x172);
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    sp98 = mem_pool_alloc(arg8, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp98, 0, 0, 0x228, 6, D_88217C60);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp98);

    sp9C = mem_pool_alloc(arg8, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp9C, 0, 0x138, 0x228, 6, D_88217C60);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp9C);

    spA0 = mem_pool_alloc(arg8, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spA0, 0, 6, 0xA, 0x132, D_88217C60);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spA0);

    spA4 = mem_pool_alloc(arg8, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spA4, 0x21E, 6, 0xA, 0x132, D_88217C60);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spA4);

    spA8 = mem_pool_alloc(arg8, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spA8, 0xF3, 6, 0x42, 0x132, D_88217C60);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spA8);

    sp90 = mem_pool_alloc(arg8, sizeof(WidgetNode));
    ((func8850AB48)Memmap_GetFragmentVaddr(WidgetTree_InitInsetBorderFrame))(sp90, 8, 4, 0xED, 0x136);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp90);

    sp94 = mem_pool_alloc(arg8, sizeof(WidgetNode));
    ((func8850AB48)Memmap_GetFragmentVaddr(WidgetTree_InitInsetBorderFrame))(sp94, 0x133, 4, 0xED, 0x136);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp94);

    sp88 = mem_pool_alloc(arg8, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(WidgetTree_InitPatternTexture))(sp88, 0xA, 6, 0xE9, 0x1E, D_88217C64, D_88217C68);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp88);

    sp8C = mem_pool_alloc(arg8, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(WidgetTree_InitPatternTexture))(sp8C, 0x135, 6, 0xE9, 0x1E, D_88217C64, D_88217C68);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp8C);

    arg0->unk_30 = mem_pool_alloc(arg8, sizeof(unk_func_8820399C));
    LabPC_BuildBoxLabelTab(arg0->unk_30, 0, sp88);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp88, arg0->unk_30);

    arg0->unk_34 = mem_pool_alloc(arg8, sizeof(unk_func_8820399C));
    LabPC_BuildBoxLabelTab(arg0->unk_34, 1, sp8C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp8C, arg0->unk_34);

    arg0->unk_40 = mem_pool_alloc(arg8, sizeof(unk_func_88217740));
    LabPC_InitModeToggleIcon(arg0->unk_40, 0xF4, 0xA);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_40);

    for (i = 0; i < sizeof(D_88217C6C) / sizeof(D_88217C6C[0]); i++) {
        arg0->unk_44[i] = mem_pool_alloc(arg8, sizeof(unk_func_882149A0));
        LabPC_InitTabWidget(arg0->unk_44[i], D_88217C6C[i].unk_00, D_88217C6C[i].unk_02, D_88217C6C[i].unk_04,
                            D_88217C6C[i].unk_06, D_88217C6C[i].unk_08, D_88217C6C[i].unk_0C, D_88217C6C[i].unk_10[0],
                            D_88217C6C[i].unk_10[1], D_88217C60);
        if (D_88217C6C[i].unk_14 != 0) {
            LabPC_TabWidget_ToggleFlip(arg0->unk_44[i]);
        }
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_44[i]);
    }

    arg0->unk_68 = mem_pool_alloc(arg8, sizeof(WidgetGridMenu));
    ((func8850C284)Memmap_GetFragmentVaddr(WidgetTree_InitGridMenu))(arg0->unk_68, 5, 1, arg8);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_64, arg0->unk_68);

    for (i = 0; i < 5; i++) {
        arg0->unk_68->unk_18[i * arg0->unk_68->unk_2C] = arg0->unk_44[i];
    }

    ((func8850CB48)Memmap_GetFragmentVaddr(WidgetTree_SetGridMenuSelection))(arg0->unk_68, 0);

    temp_s0 = mem_pool_alloc(arg8, sizeof(WidgetAnimatedFrame));
    ((func88503340)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedFrameVariantA))(temp_s0, 0, 0, 0x10, 0x10, D_88217CE4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, temp_s0);
    arg0->unk_68->unk_1C = temp_s0;

    temp_s0_2 = mem_pool_alloc(arg8, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(WidgetTree_InitPatternTexture))(temp_s0_2, 0, 0x13E, 0x228, 0x34, D_88217CE8, D_88217CEC);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, temp_s0_2);

    arg0->unk_58 = mem_pool_alloc(arg8, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_58, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s0_2, arg0->unk_58);

    for (j = 0; j < 5; j++) {
        temp_s1_2 = Text_GetString(NULL, 0, D_88224FA4, j + 1);

        temp_s0_3 = mem_pool_alloc(arg8, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(temp_s0_3, (0x228 - Font_MeasureTextExtent(0, 0, temp_s1_2)) / 2,
                                                               0xE, temp_s1_2, 0x10);
        temp_s0_3->unk_30 = D_88217CF0[j][0];
        temp_s0_3->unk_44 = temp_s0_3->unk_44;
        temp_s0_3->unk_34 = D_88217CF0[j][1];
        temp_s0_3->unk_44 = 1;
        ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_58, temp_s0_3);
    }

    Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_88224FA4, 0x31));
    Font_MeasureTextExtent(8, 0, " 00");
    spB4 = Font_MeasureTextExtent(4, 0, "00");

    arg0->unk_38 = mem_pool_alloc(arg8, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_38, 0xA, 0x24, func_88203538, 0xE9, 0x17, 0xC, 1,
                                                           arg8);
    ((func88506384)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridPage))(arg0->unk_38, &arg3[0], arg8);
    arg0->unk_38->unk_44->unk_00.unk_28 |= 0x100;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_38);

    arg0->unk_3C = mem_pool_alloc(arg8, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_3C, 0x135, 0x24, func_88203538, 0xE9, 0x17, 0xC, 1,
                                                           arg8);
    ((func88506384)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridPage))(arg0->unk_3C, &arg3[1], arg8);
    arg0->unk_3C->unk_44->unk_00.unk_28 |= 0x100;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_3C);

    arg0->unk_6C = mem_pool_alloc(arg8, sizeof(unk_func_882025E0_1A9780));
    LabPC_BuildBoxPairSelector(arg0->unk_6C, arg0->unk_38, arg0->unk_3C, arg0, arg8);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_64, arg0->unk_6C);

    arg0->unk_70 = mem_pool_alloc(arg8, sizeof(unk_func_8850CD44));
    ((func8850CD44)Memmap_GetFragmentVaddr(WidgetTree_InitChildWidgetGroup))(arg0->unk_70, 2, arg8);
    ((func8850CC74)Memmap_GetFragmentVaddr(WidgetTree_AppendChildSelectionProxyItem))(arg0->unk_64, arg0->unk_70);

    for (x = 0; x < 2; x++) {
        arg0->unk_74[x] = mem_pool_alloc(arg8, sizeof(unk_func_882173EC));
        LabPC_InitFlyingIconWidget(arg0->unk_74[x], 0, 0);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_74[x]);

        arg0->unk_7C[x] = mem_pool_alloc(arg8, sizeof(unk_func_8820253C));
        LabPC_BuildBoxCountLabel(arg0->unk_7C[x], 0xB4 - spB4, 0, 0);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_74[x], arg0->unk_7C[x]);

        arg0->unk_70->unk_1C[x] = arg0->unk_74[x];
    }

    temp_s0_4 = mem_pool_alloc(arg8, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(temp_s0_4, arg0->unk_2C, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, temp_s0_4);

    arg0->unk_60 = mem_pool_alloc(arg8, sizeof(unk_func_88509F48));
    ((func88509F48)Memmap_GetFragmentVaddr(WidgetTree_InitMessagePanel))(arg0->unk_60, 0, 0, 0x228, 0x172, arg8, arg6);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_60);

    arg0->unk_84 = mem_pool_alloc(arg8, sizeof(unk_func_889000C4));
    ((func889000C4)Memmap_GetFragmentVaddr(LabUI_BuildConfirmDialog))(arg0->unk_84, 0, arg0->unk_2C, 0, arg7, arg8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_84);

    if (sp88) {}
    if (sp8C) {}
    if (sp90) {}
    if (sp94) {}
    if (sp98) {}
    if (sp9C) {}
    if (spA0) {}
    if (spA4) {}
    if (spA8) {}
}

s32 LabPC_BoxMenu_OnShow(unk_func_88203ED8* arg0) {
    if (arg0->unk_64->unk_00.unk_1C == 0) {
        ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_58, arg0->unk_68->unk_24);
    }
    return 0;
}

void LabPC_BoxMenu_SetVisible(unk_func_88203ED8* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_64->unk_00.unk_14(arg0->unk_64, arg1);
}

s32 LabPC_BoxMenu_HandleInput(unk_func_88203ED8* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_64->unk_00.unk_10(arg0->unk_64, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void LabPC_BoxMenu_ClearButtonHighlights(unk_func_88203ED8* arg0) {
    LabPC_TabWidget_ToggleFlip(arg0->unk_44[0]);
    LabPC_TabWidget_ToggleFlip(arg0->unk_44[1]);
    LabPC_TabWidget_ToggleFlip(arg0->unk_44[2]);
    LabPC_TabWidget_ToggleFlip(arg0->unk_44[3]);
}

void LabPC_BoxMenu_RefreshBoxLabels(unk_func_88203ED8* arg0) {
    unk_func_88205880_00D0* sp34;
    unk_func_88205880_00D0* sp30;
    WidgetPoint sp2C;
    WidgetPoint sp28;

    LabPC_BoxPairSelector_GetSelectedBoxes(arg0->unk_6C, &sp30, &sp34);
    LabPC_BoxPairSelector_GetSelectedBoxIds(arg0->unk_6C, &sp2C, &sp28);

    LabPC_BoxCountLabel_SetBox(arg0->unk_7C[0], sp30);
    LabPC_FlyingIconWidget_Start(arg0->unk_74[0], sp2C, sp28);

    if (sp34 != NULL) {
        LabPC_BoxCountLabel_SetBox(arg0->unk_7C[1], sp34);
        LabPC_FlyingIconWidget_Start(arg0->unk_74[1], sp28, sp2C);
    }

    arg0->unk_6C->unk_00.unk_14(arg0->unk_6C, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(WidgetTree_RunChildWidgetGroup))(arg0->unk_70, 0);

    arg0->unk_6C->unk_00.unk_14(arg0->unk_6C, 1);
}

void LabPC_BoxMenu_InitFocusNode(unk_func_88203ED8_064* arg0, unk_func_88203ED8* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(WidgetTree_InitVerticalMenu))(arg0);

    arg0->unk_00.unk_10 = func_882052F4;
    arg0->unk_24 = arg1;
}

u32 LabPC_BoxHasUnsavedChanges(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    u32 sp90 = 0;
    DeckHandle* temp_v0 = Deck_Open(arg1, arg2, arg3, 0);
    BattleMon* var_s1;
    BattleMon sp34;

    if (temp_v0 == NULL) {
        return 0;
    }

    var_s1 = arg0->unk_000;
    for (i = 0; i < arg0->unk_690; i++, var_s1++) {
        bzero(&sp34, sizeof(BattleMon));
        Deck_ReadEntries(&sp34, 1, temp_v0);
        if (bcmp(&sp34, var_s1, sizeof(BattleMon)) != 0) {
            sp90 = 1;
            break;
        }
    }

    Deck_CloseAndFlush(temp_v0);
    return sp90;
}

s32 LabPC_GetDirtyBoxMask(unk_func_88203ED8* arg0) {
    s32 i;
    s32 temp_s3 = GbSave_GetActivePort();
    s32 var_s2 = 0;
    u32 temp_v0;
    unk_func_88205880_00D0** var_s1;

    var_s1 = arg0->unk_38->unk_2C->unk_00;

    for (i = 0; i < 12; i++) {
        if ((var_s1[i]->unk_694 != 0x21) || (i != var_s1[i]->unk_698)) {
            if ((var_s1[i]->unk_690 != 0) || (Deck_GetEntryCountForType(0x21, temp_s3, i) != 0)) {
                var_s2 |= 2;
                var_s1[i]->unk_69C = 1;
            }
        } else if (var_s1[i]->unk_69C != 0) {
            temp_v0 = LabPC_BoxHasUnsavedChanges(var_s1[i], 0x21, temp_s3, i);
            var_s1[i]->unk_69C = temp_v0;
            if (temp_v0 != 0) {
                var_s2 |= 2;
            }
        }
    }

    var_s1 = arg0->unk_3C->unk_2C->unk_00;

    for (i = 0; i < 12; i++) {
        if ((var_s1[i]->unk_694 != 0x11) || (i != var_s1[i]->unk_698)) {
            if ((var_s1[i]->unk_690 != 0) || (Deck_GetEntryCountForType(0x11, 0, i) != 0)) {
                var_s2 |= 4;
                var_s1[i]->unk_69C = 1;
            }
        } else if (var_s1[i]->unk_69C != 0) {
            temp_v0 = LabPC_BoxHasUnsavedChanges(var_s1[i], 0x11, 0, i);
            var_s1[i]->unk_69C = temp_v0;
            if (temp_v0 != 0) {
                var_s2 |= 4;
            }
        }
    }

    return var_s2;
}

void LabPC_SaveModifiedBoxes(unk_func_88203ED8* arg0, s32 arg1) {
    s32 i;
    s32 temp_s3 = GbSave_GetActivePort();
    unk_func_88205880_00D0** var_s1;

    ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_84->unk_40, 2);
    Ui_SendMessageAndPollInput(NULL);

    var_s1 = arg0->unk_38->unk_2C->unk_00;

    for (i = 0; i < 12; i++) {
        if (var_s1[i]->unk_69C != 0) {
            LabPC_WriteBoxEntries(0x21, temp_s3, i, var_s1[i]);
            LabPC_MarkBoxSeen(var_s1[i]);
        }
    }

    var_s1 = arg0->unk_3C->unk_2C->unk_00;

    for (i = 0; i < 12; i++) {
        if (var_s1[i]->unk_69C != 0) {
            LabPC_WriteBoxEntries(0x11, 0, i, var_s1[i]);
        }
    }

    if (arg1 & 4) {
        Save_FlushBank(3);
    }

    if (arg1 & 2) {
        GbSave_RebuildSeenBitfield(temp_s3);
        ((func88900970)Memmap_GetFragmentVaddr(LabUI_ShowSavingPrompt))(arg0->unk_84, temp_s3);
    }

    if (arg1 & 4) {
        Save_CommitBankRecords(3);
        Save_FlushBank(3);
    }
}

s32 LabPC_ConfirmSaveAndExit(unk_func_88203ED8* arg0, Controller* arg1) {
    s32 sp24 = 1;
    s32 sp20 = LabPC_GetDirtyBoxMask(arg0);
    s32 temp_v0_2;

    if (sp20 != 0) {
        arg0->unk_68->unk_14(arg0->unk_68, 0);
        ((func889006D4)Memmap_GetFragmentVaddr(LabUI_OpenConfirmDialog))(arg0->unk_84, 0);
        temp_v0_2 = ((func88900808)Memmap_GetFragmentVaddr(LabUI_RunConfirmDialog))(arg0->unk_84, arg1, 1);

        if (temp_v0_2 == 0) {
            LabPC_SaveModifiedBoxes(arg0, sp20);
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_84);
        } else if (temp_v0_2 == 1) {
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_84);
        } else if (temp_v0_2 == 2) {
            ((func889007AC)Memmap_GetFragmentVaddr(LabUI_CloseConfirmDialog))(arg0->unk_84);
            sp24 = 0;
        }

        arg0->unk_68->unk_14(arg0->unk_68, 1);
    }

    return sp24;
}

s32 func_882052F4(unk_func_88203ED8_064* arg0, Controller* arg1) {
    s32 sp34;
    s32 tmp;
    s32 i;
    unk_func_88203ED8_064* var_a0;
    s32 sp24;
    s32 sp20;

    sp34 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }
        sp34 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    if (sp34 & 1) {
        return sp34;
    }

    if (sp34 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            sp34 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            sp34 = 0x80000004;
        } else if (arg1->buttonPressed & 0x30) {
            sp34 = 0x01000000;
        }
    }

    if (sp34 & 2) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
                sp34 = 2;
                if (LabPC_ConfirmSaveAndExit(arg0->unk_24, arg1) == 0) {
                    sp34 = 3;
                }
                break;

            case 1:
                ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 0);
                sp34 |= 1;
                break;
        }
    } else if (sp34 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                switch (arg0->unk_24->unk_68->unk_24) {
                    case 0:
                        LabPC_BoxPairSelector_SetMode(arg0->unk_24->unk_6C, 0);
                        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                        sp34 |= 1;
                        break;

                    case 1:
                        LabPC_BoxPairSelector_SetMode(arg0->unk_24->unk_6C, 1);
                        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                        sp34 |= 1;
                        break;

                    case 2:
                        LabPC_BoxPairSelector_SetMode(arg0->unk_24->unk_6C, 2);
                        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                        sp34 |= 1;
                        break;

                    case 3:
                        LabPC_BoxPairSelector_SetMode(arg0->unk_24->unk_6C, 3);
                        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                        sp34 |= 1;
                        break;

                    case 4:
                        Audio_PlaySoundEffectById(SFX_MENU_BACK);
                        sp34 = 2;
                        if (LabPC_ConfirmSaveAndExit(arg0->unk_24, arg1) == 0) {
                            sp34 = 3;
                        }
                        break;
                }
                break;

            case 1:
                switch (arg0->unk_24->unk_68->unk_24) {
                    case 0:
                    case 2:
                        Audio_PlaySoundEffectById(SFX_MOVE_SWAP);
                        LabPC_BoxMenu_RefreshBoxLabels(arg0->unk_24);
                        LabPC_BoxPairSelector_ExchangeSwap(arg0->unk_24->unk_6C);
                        LabPC_BoxPairSelector_Reset(arg0->unk_24->unk_6C);
                        sp34 = 0x80000081;
                        break;

                    case 1:
                        Audio_PlaySoundEffectById(SFX_MOVE_SWAP);
                        LabPC_BoxMenu_RefreshBoxLabels(arg0->unk_24);
                        LabPC_BoxPairSelector_ReorderSwap(arg0->unk_24->unk_6C);
                        LabPC_BoxPairSelector_Reset(arg0->unk_24->unk_6C);
                        sp34 = 0x80000081;
                        break;

                    case 3:
                        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                        tmp = (arg0->unk_24->unk_6C->unk_38 != 0 ? 1 : 2) << 0x10;
                        LabPC_CheckBox_ShowBox(arg0->unk_24->unk_5C,
                        (unk_func_88205880_00D0*)((s32*)arg0->unk_24->unk_6C->unk_24[0]->unk_2C->unk_00)[arg0->unk_24->unk_6C->unk_24[0]->unk_38],
                        tmp | arg0->unk_24->unk_6C->unk_24[0]->unk_38);

                        arg0->unk_24->unk_6C->unk_24[0]->unk_00.unk_24(arg0->unk_24->unk_6C->unk_24[0], 0x100);
                        LabPC_CheckBox_ModalLoop(arg0->unk_24->unk_5C, arg1);

                        arg0->unk_24->unk_6C->unk_24[0]->unk_00.unk_24(arg0->unk_24->unk_6C->unk_24[0], 1);
                        LabPC_BoxPairSelector_Reset(arg0->unk_24->unk_6C);
                        sp34 = 1;
                        break;
                }
                break;
        }
    } else if (sp34 & 0x01000000) {
        sp34 = 1;
        sp24 = (arg1->buttonPressed & 0x20) != 0;
        sp20 = arg0->unk_24->unk_6C->unk_38;

        switch (arg0->unk_00.unk_1C) {
            case 0:
                sp20 = sp24;
                break;

            case 1:
                sp34 = 1;
                if (LabPC_BoxPairSelector_IsInitialStage(arg0->unk_24->unk_6C) != 0) {
                    sp20 = sp24;
                }
                break;
        }

        if (sp20 != arg0->unk_24->unk_6C->unk_38) {
            LabPC_BoxPairSelector_SwapSides(arg0->unk_24->unk_6C);
            if (arg0->unk_00.unk_1C == 1) {
                LabPC_BoxPairSelector_RefreshDisabledBoxes(arg0->unk_24->unk_6C);
            }
            LabPC_BoxMenu_ClearButtonHighlights(arg0->unk_24);
            LabPC_ModeToggleIcon_ToggleMode(arg0->unk_24->unk_40);

            ((func8850BFB0)Memmap_GetFragmentVaddr(WidgetTree_UpdateVerticalMenuItems))(arg0);

            sp34 = 0x80000005;
        }
    }
    return sp34;
}

void LabPC_BoxMenu_ModalLoop(unk_func_88203ED8* arg0, Controller* arg1) {
    s32 var_s1 = 0;
    s32 temp_v0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);

    while (var_s1 == 0) {
        Ui_SendMessageAndPollInput(NULL);

        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(temp_v0 & 1) && (temp_v0 & 2)) {
            var_s1 = 1;
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(temp_v0);
    }

    arg0->unk_2C->unk_2C = 0xB;
}

void LabPC_BuildBoxScreenWidget(unk_func_88205880* arg0, s32 arg1, s32 arg2, FontContext* arg3, MemoryPool* arg4, char** arg5,
                   char** arg6, char** arg7, char** arg8, char** arg9, char** argA, char** argB, char** argC) {
    static Color_RGBA8 D_88217D04 = { 0x1E, 0x50, 0x50, 0xFF };
    static Color_RGBA8 D_88217D08 = { 0x00, 0x0A, 0x0A, 0xFF };

    WidgetNode* sp7C;
    WidgetNode* sp78;
    WidgetNode* sp74;
    FragmentEntry sp70;
    s32 i;
    UNUSED s32 pad[2];
    s32 sp60;
    unk_func_88500EE4* sp5C;
    unk_func_885088F4* sp58;
    unk_func_88509A2C* sp54;
    unk_func_88509E34* sp50;

    sp60 = GbSave_GetActivePort();
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_88205880));
    arg0->unk_0000.unk_20 = LabPC_BoxScreen_HandleInput;
    arg0->unk_0000.unk_10.unk_00 = arg1;
    arg0->unk_0000.unk_10.unk_02 = arg2;

    if (GbSave_GetBoxCount(sp60) == 0) {
        GbSave_MarkBoxDataLoaded(sp60);
    }

    LabPC_LoadAllBoxes(arg0->unk_00D0, 0x21, sp60, 0xC);
    LabPC_LoadAllBoxes(arg0->unk_5050, 0x11, 0, 0xC);

    for (i = 0; i < 12; i++) {
        arg0->unk_9FD0[i] = &arg0->unk_00D0[i];
    }

    for (i = 0; i < 12; i++) {
        arg0->unk_A000[i] = &arg0->unk_5050[i];
    }

    PointerList_Initialize(&arg0->unk_A030[0], arg0->unk_9FD0, 0xC, 0xC);
    PointerList_Initialize(&arg0->unk_A030[1], arg0->unk_A000, 0xC, 0xC);

    sp7C = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func885031E8)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGate))(sp7C, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, sp7C);

    sp5C = mem_pool_alloc(arg4, sizeof(unk_func_88500EE4));
    ((func88500EE4)Memmap_GetFragmentVaddr(WidgetTree_InitTintedTexture))(sp5C, 0, 0, 0x280, 0x1E0, D_88223E48, D_88217D04,
                                                           D_88217D08);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp7C, sp5C);

    sp58 = mem_pool_alloc(arg4, sizeof(unk_func_885088F4));
    ((func885088F4)Memmap_GetFragmentVaddr(WidgetTree_InitSlideTransition))(sp58, 0x41, 0x15C, 0xDC);
    sp58->unk_2C = 5;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp7C, sp58);

    sp54 = mem_pool_alloc(arg4, sizeof(unk_func_88509A2C));
    ((func88509A2C)Memmap_GetFragmentVaddr(WidgetTree_InitSaveSlotLabel))(sp54, 0x38, 0x22, GbSave_GetActivePort(),
                                                           Text_GetString(NULL, 0, D_88224FA0, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp58, sp54);

    sp50 = mem_pool_alloc(arg4, sizeof(unk_func_88509E34));
    ((func88509E34)Memmap_GetFragmentVaddr(WidgetTree_InitTextMessage))(sp50, 0, 0, Text_GetString(NULL, 0, D_88224FA4, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp58, sp50);

    sp78 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func885031E8)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGate))(sp78, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, sp78);

    sp74 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func885031E8)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGate))(sp74, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, sp74);

    sp70 = FRAGMENT_LOAD(fragment27);

    arg0->unk_0098.unk_04 = arg4;
    // clang-format off
    arg0->unk_0098.unk_00 = 0x38; arg0->unk_0098.unk_02 = 0x52;
    // clang-format on
    arg0->unk_0098.unk_14 = sp74;
    arg0->unk_0098.unk_18 = NULL;
    arg0->unk_0098.unk_1C = arg6;
    arg0->unk_0098.unk_20 = arg7;
    arg0->unk_0098.unk_24 = arg8;
    arg0->unk_0098.unk_28 = arg9;
    arg0->unk_0098.unk_2C = argA;
    arg0->unk_0098.unk_30 = argB;
    arg0->unk_0098.unk_34 = argC;

    sp70(0, &arg0->unk_0098);

    arg0->unk_0094 = mem_pool_alloc(arg4, sizeof(unk_func_88201DA0));
    func_88201DA0(arg0->unk_0094, 0x37, 0x52, sp78, sp70, &arg0->unk_0098, arg4);

    arg0->unk_002C = mem_pool_alloc(arg4, sizeof(unk_func_88203ED8));
    func_88203ED8(arg0->unk_002C, 0x2C, 0x4C, &arg0->unk_A030, sp7C, arg0->unk_0094, arg3, arg5, arg4);

    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp78, arg0->unk_002C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp74, arg0->unk_0094);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_0098.unk_08);
}

s32 LabPC_BoxScreen_HandleInput(unk_func_88205880* arg0, Controller* arg1) {
    return arg0->unk_002C->unk_00.unk_20(arg0->unk_002C, arg1);
}

void LabPC_BoxScreen_DrawLoop(unk_func_88205880* arg0) {
    s32 sp34 = 0;

    while (sp34 == 0) {
        BgStage_DrawFrame();

        ((func885008C4)Memmap_GetFragmentVaddr(WidgetTree_Update))(arg0);
        ((func88500828)Memmap_GetFragmentVaddr(WidgetTree_Draw))(arg0, 0, 0);

        BgStage_AdvanceFrame();
        Ui_ReceiveMessage(&sp34);
    }
}

void LabPC_BoxScreen_InputThread(unk_func_88205880* arg0) {
    Input_SetRepeatController(gPlayer1Controller);
    LabPC_BoxMenu_ModalLoop(arg0->unk_002C, gPlayer1Controller);

    while (arg0->unk_002C->unk_2C->unk_00.unk_28 & 1) {
        Ui_SendMessageAndPollInput(NULL);
    }

    Ui_SendMessageAndPollInput(1);
    osStopThread(NULL);
}

void LabPC_ShowBoxes(FontContext* arg0) {
    MemoryPool* sp6C;
    unk_func_88205880* sp68;
    u8* sp64;
    func_88002628_sp38* sp60;
    char** sp5C;
    char** sp58;
    char** sp54;
    char** sp50;
    char** sp4C;
    char** sp48;
    char** sp44;
    char** sp40;

    main_pool_push_state('BXPC');

    FRAGMENT_LOAD(fragment25);

    PokeIcon_OpenModelArchive();
    sp64 = main_pool_alloc(0x1000, 0);
    sp6C = mem_pool_try_init(0x10000, 0);
    Text_InitStringTables();
    D_88224FA0 = Text_GetStringTable(0x2A);
    D_88224FA4 = Text_GetStringTable(4);
    sp5C = Text_GetStringTable(7);
    sp58 = Text_GetStringTable(6);
    sp54 = Text_GetStringTable(0x24);
    sp50 = Text_GetStringTable(0x25);
    sp4C = Text_GetStringTable(0x26);
    sp48 = Text_GetStringTable(0x28);
    sp44 = Text_GetStringTable(0x29);
    sp40 = Text_GetStringTable(0xB);

    sp68 = mem_pool_alloc(sp6C, sizeof(unk_func_88205880));
    LabPC_BuildBoxScreenWidget(sp68, 0, 0, arg0, sp6C, sp5C, sp58, sp54, sp50, sp4C, sp48, sp44, sp40);

    sp60 = ALIGN16((u32)mem_pool_alloc(sp6C, sizeof(func_88002628_sp38)));

    osCreateThread(&sp60->thread, 0x32, LabPC_BoxScreen_InputThread, sp68, sp64 + 0x1000, osGetThreadPri(NULL) - 1);

    Ui_InitInputMessageQueue();

    osStartThread(&sp60->thread);

    LabPC_BoxScreen_DrawLoop(sp68);

    osDestroyThread(&sp60->thread);

    main_pool_pop_state('BXPC');
}
