#include "lab_pc_list.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/gb_data.h"
#include "src/game_state.h"
#include "src/table_view.h"
#include "src/text_system.h"
#include "src/gb_save.h"
#include "src/audio_sfx.h"
#include "src/hal_libc.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/pokemon_stats.h"

static u8 D_88317360[] = {
    0x5F, 0x45, 0x21, 0x12, 0x51, 0x58, 0x2A, 0x43, 0x96, 0x6F, 0x9C, 0x36, 0x66, 0x8D, 0x19, 0x37, 0xA1, 0xA0, 0x2F,
    9,    0x77, 0x9D, 0x83, 0x1E, 0x50, 0x44, 0x6D, 0x6E, 0x3A, 0x3C, 0x31, 0x3D, 0x8E, 0xC,  0xA3, 0x90, 0x92, 0x20,
    0x8F, 0x5D, 0x9B, 0x5B, 0x49, 0xA,  0x34, 0x6A, 0x74, 0x8A, 0x7F, 0x1C, 1,    0x27, 0x2D, 0x56, 0x9E, 0x3E, 0x8B,
    0x42, 0xB,  0x60, 0x10, 5,    0x3F, 0x59, 0x24, 0x87, 0x4D, 0x17, 0x71, 0x84, 0,    0x4F, 0x48, 0x35, 0x65, 0x7E,
    0x5E, 0x86, 0x79, 0x5A, 0x85, 0x22, 0x2B, 0x97, 0x95, 0x94, 0x93, 0x6C, 0x25, 0x2C, 0x1B, 0x98, 0x14, 0x61, 0x41,
    0x4E, 3,    0x63, 0x64, 0x91, 0x57, 0x53, 0x70, 0x1F, 0x67, 0x38, 0x54, 0x7C, 0x13, 0xA2, 0x1A, 7,    0x4B, 0x39,
    0x68, 0x30, 8,    0x52, 0x55, 0x72, 0x26, 0x4A, 0x7B, 0x7A, 0xD,  0x29, 0x9F, 0x11, 0x8C, 0x75, 0x80, 0x15, 4,
    0x46, 0x7D, 0x3B, 0x33, 0x23, 0x5C, 6,    0x47, 0x4C, 0x76, 0x99, 0xF,  0x1D, 0x82, 0x2E, 0x62, 0x81, 2,    0x18,
    0x28, 0x32, 0xE,  0x69, 0x6B, 0x40, 0x73, 0x16, 0x9A, 0x89, 0x78, 0x88,
};

void BattleMoveListWidget_DrawMove(s32 arg0, s32 arg1, unk_func_88309160_arg2* arg2, s32 arg3, u32 arg4,
                   unk_func_88200FA0_030_030* arg5) {
    static Color_RGBA8 D_88317404[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF },
        { 0xF0, 0xF0, 0xF0, 0x4D },
    };

    Color_RGBA8 sp3C;
    UNUSED s32 pad;
    ret_func_8002ED08* sp34;
    s32 new_var;
    s32 var_v0;
    char* sp28;
    s32 var_v1;
    MoveData* temp_v0_2;

    if (arg2 != NULL) {
        sp34 = Move_GetDisplayInfo(arg2->unk_00);
        if (sp34 == NULL) {
            sp28 = "???????";
        } else {
            sp28 = Text_GetString(NULL, 0, D_8831A4CC, arg2->unk_00 - 1);
        }

        sp3C = D_88317404[(arg4 & 4) ? 1 : 0];

        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(sp3C.r, sp3C.g, sp3C.b, sp3C.a);
        Font_SetActive(8, 0);
        Font_Printf(arg0 + 8, arg1 + 4, sp28);
        Font_EndTexturedTextRendering();

        if (sp34 != NULL) {
            temp_v0_2 = Move_GetData(arg2->unk_00);

            var_v1 = temp_v0_2->unk_05 / 5;
            if (var_v1 >= 7) {
                var_v1 = 7;
            }

            new_var = temp_v0_2->unk_05 + (var_v1 * (arg2->unk_04 >> 6));
            Gfx_DrawNumberFixedWidth((arg5->unk_00.unk_14.unk_00 + arg0) - 0x19, arg1 + 0xC, new_var, 2);
        }
    }
}

void BattleMoveListWidget_Initialize(unk_func_8830867C_04C_078* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    static Color_RGBA8 D_8831740C = { 0xA0, 0x96, 0x64, 0xFF };

    UNUSED s32 pad;
    s32 sp58;
    UNUSED s32 pad2[2];
    s32 sp4C;
    s32 temp_v1;
    unk_func_885012A4* sp44;

    temp_v1 = Font_MeasureTextExtent(8, 0, "WWWWWWWWWWWW") + 0x29;
    sp58 = temp_v1;
    sp4C = temp_v1;
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_04C_078));

    arg0->unk_00.unk_20 = BattleMoveListWidget_HandleInput;
    arg0->unk_00.unk_10.unk_00 = (arg2 - sp4C) - 8;
    arg0->unk_00.unk_10.unk_02 = arg1;

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, sp4C, 0x78);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    sp44 = mem_pool_alloc(arg3, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp44, 0, 0, sp4C, 0x78, D_8831740C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp44);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_30, 0, 4, BattleMoveListWidget_DrawMove, sp58, 0x1C, 4, 1, arg3);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_30, 4, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp44, arg0->unk_30);
}

void BattleMoveListWidget_SetMoves(unk_func_8830867C_04C_078* arg0, BattleMon* arg1) {
    s32 i;
    s32 temp_v0;
    s32 sp34;

    temp_v0 = BattleMon_CountMoves(arg1);
    if ((temp_v0 - 1) >= arg0->unk_30->unk_38) {
        sp34 = arg0->unk_30->unk_38;
    } else {
        sp34 = (temp_v0 - 1);
    }

    for (i = 0; i < temp_v0; i++) {
        arg0->unk_44[i].unk_00 = arg1->unk_09[i];
        arg0->unk_44[i].unk_04 = arg1->unk_20[i];
    }

    TableView_Initialize(&arg0->unk_34, arg0->unk_44, 8, 4, temp_v0);
    ((func885063B8)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridStridedData))(arg0->unk_30, &arg0->unk_34);
    ((func88506BFC)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelection))(arg0->unk_30, sp34);
}

typedef struct unk_func_88309614 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ s32 unk_08;
} unk_func_88309614; // size >= 0xC

void BattleMoveListWidget_DisableUnavailableMoves(unk_func_8830867C_04C_078* arg0) {
    s32 i;

    for (i = 0; i < ((unk_func_88309614*)arg0->unk_30->unk_2C)->unk_08; i++) {
        if ((Move_GetDisplayInfo(arg0->unk_44[i].unk_00) == NULL) || (arg0->unk_44[i].unk_04 >= 0xC0)) {
            arg0->unk_30->unk_34[i] |= 4;
        }
    }
}

void BattleMoveListWidget_DisableRestrictedMoves(unk_func_8830867C_04C_078* arg0) {
    static s32 D_88317410[] = { 0xF, 0x13, 0x39, 0x46, 0x94 };

    s32 j;
    s32 i;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            if (*(s32*)&arg0->unk_44[i].unk_00 == D_88317410[j]) {
                arg0->unk_30->unk_34[i] |= 4;
                break;
            }
        }
    }
}

s32 BattleMoveListWidget_HandleInput(unk_func_8830867C_04C_078* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void BattleMoveListWidget_Destroy(unk_func_8830867C_04C_078* arg0) {
    ((func88506CE4)Memmap_GetFragmentVaddr(WidgetTree_FindSelectableGridEntry))(arg0->unk_30);

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);
}

void BattleMoveListWidget_SetCloseState(unk_func_8830867C_04C_078* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
}

void func_883097E4(void) {
}

s32 BattleInfoWidget_GetEntryDisabledFlags(unk_func_8830867C_034_03C_038_02C_000* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_08 != 0) {
        var_v1 = 2;
    }
    return var_v1;
}

void func_88309808(void) {
}

void BattleInfoWidget_ApplyEntryDisabledFlags(unk_func_8830867C_034_03C* arg0) {
    s32 i;
    s32 j;
    unk_func_8830867C_034_03C_038* temp_s3;
    unk_func_8830867C_034_03C_038_02C_000* var_s0;

    for (i = 0; i < 2; i++) {
        temp_s3 = arg0->unk_38[i];
        var_s0 = temp_s3->unk_2C->unk_00;

        for (j = 0; j < temp_s3->unk_2C->unk_08; j++, var_s0++) {
            temp_s3->unk_34[j] |= BattleInfoWidget_GetEntryDisabledFlags(var_s0);
        }
    }
}

void BattleInfoWidget_SetActivePageFlags(unk_func_8830867C_034_03C* arg0, s32 arg1) {
    s32 i;
    s32 var_v0;
    unk_func_8830867C_034_03C_038* temp_a1;

    if (arg1 != 0) {
        var_v0 = 2;
    } else {
        var_v0 = 0;
    }

    if (arg0->unk_34->unk_2C != 0) {
        temp_a1 = arg0->unk_38[arg0->unk_34->unk_2C - 1];

        for (i = 0; i < temp_a1->unk_2C->unk_08; i++) {
            temp_a1->unk_34[i] &= ~2;
            temp_a1->unk_34[i] |= var_v0;
        }
    }
}

void BattleInfoWidget_SyncEntrySelection(unk_func_8830867C_034_03C* arg0) {
    s32 i;
    s32 j;
    unk_func_8830867C_034_03C_038* temp_v0;
    unk_func_8830867C_034_03C_038_02C_000* ptr;

    for (i = 0; i < 2; i++) {
        temp_v0 = arg0->unk_38[i];
        ptr = temp_v0->unk_2C->unk_00;
        for (j = 0; j < temp_v0->unk_2C->unk_08; j++, ptr++) {
            ptr->unk_08 = (temp_v0->unk_34[j] & 2) != 0;
        }
    }
}

void BattleInfoWidget_DrawIndicator(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Gfx_DrawNumberDigits(arg0, arg1, arg2, 2);
    Gfx_DrawNumberDigits(arg0 + 0x1B, arg1, arg3, 2);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gDisplayListHead++, D_4006A60, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 10, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg0 + 0x12) << 2, (arg1 + 2) << 2, (arg0 + 0x1A) << 2, (arg1 + 0xC) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
}

void BattleInfoWidget_DrawEntry(s32 arg0, s32 arg1, unk_func_88309C38_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_8830867C_034_03C_038* arg5) {
    static Color_RGBA8 D_88317424 = { 0xB2, 0xFF, 0xC3, 0xFF };
    static Color_RGBA8 D_88317428 = { 0xF0, 0xF0, 0xF0, 0xFF };

    UNUSED s32 pad;
    char* sp38;
    char sp34[4];
    UNUSED s32 pad2;
    s32 sp2C;
    s32 sp28;

    sp38 = Text_GetString(NULL, 0, D_8831A4C4, 0x5F);
    if (arg4 & 2) {
        Gfx_DrawTiledTextureStrip(&D_800758E0, arg0 + 8, arg1 + 2);
    } else {
        Gfx_DrawTiledTextureStrip(&D_800758F0, arg0 + 8, arg1 + 2);
    }

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88317428.r, D_88317428.g, D_88317428.b, D_88317428.a);
    Font_SetActive(8, 0);
    Font_Printf(arg0 + 0x2C, arg1 + 2, sp38);

    sprintf(sp34, "%d", arg3 + 1);

    sp28 = Font_MeasureTextExtent(0, 0, " 00");
    sp2C = Font_MeasureTextExtent(0, 0, sp38);

    Font_Printf(((arg0 + sp2C + sp28) - Font_MeasureTextExtent(0, 0, sp34)) + 0x2C, arg1 + 2, sp34);
    Font_EndTexturedTextRendering();
    BattleInfoWidget_DrawIndicator((arg5->unk_00.unk_14.unk_00 + arg0) - 0x35, arg1 + 8, arg2->unk_18, arg2->unk_14);
}

s32 BattleInfoWidget_GetEntryWidth(void) {
    UNUSED s32 pad[2];
    s32 sp1C = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_8831A4C4, 0x5F));
    s32 sp20 = Font_MeasureTextExtent(8, 0, " 00");

    return sp1C + sp20 + 0x3D;
}

void BattleInfoWidget_Initialize(unk_func_8830867C_034_03C* arg0, s32 arg1, s32 arg2, s32 arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_8831742C = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317430 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317434 = { 0xA0, 0x96, 0x64, 0xFF };

    s32 pad2;
    s32 pad3;
    s32 tmp = arg3 * 0x18;
    s32 sp80;
    s32 temp_v0;
    s32 sp78;
    unk_func_8850B254* sp74;
    unk_func_8850878C* sp70;
    char* sp6C;
    unk_func_885012A4* sp68;
    WidgetNode* sp64;
    unk_func_8830867C_034_034* sp60;
    unk_func_8830867C_034_034* sp5C;

    temp_v0 = BattleInfoWidget_GetEntryWidth();
    sp80 = temp_v0 + 0x34;
    sp78 = temp_v0 + 0x46;
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_034_03C));

    arg0->unk_00.unk_20 = BattleInfoWidget_HandleInput;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, sp78, tmp + 0x20);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    sp74 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(sp74, 0, 0, sp78, 0x14, D_8831742C, D_88317430);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp74);

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_30, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp74, arg0->unk_30);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp70, 0, 0, "", 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_30, sp70);
    sp6C = Text_GetString(NULL, 0, D_8831A4C4, 0x60);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(
        sp70, (arg0->unk_2C->unk_00.unk_14.unk_00 - Font_MeasureTextExtent(8, 0, sp6C)) / 2, 0, sp6C, 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_30, sp70);
    sp6C = Text_GetString(NULL, 0, D_8831A4C4, 0x61);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(
        sp70, (arg0->unk_2C->unk_00.unk_14.unk_00 - Font_MeasureTextExtent(8, 0, sp6C)) / 2, 0, sp6C, 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_30, sp70);

    sp68 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp68, 0, 0x18, sp78, tmp + 8, D_88317434);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp68);

    arg0->unk_34 = mem_pool_alloc(arg4, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_34, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp68, arg0->unk_34);

    sp64 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(sp64, 0x2C);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_34, sp64);

    arg0->unk_38[0] = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_03C_038));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_38[0], 0x12, 4, BattleInfoWidget_DrawEntry, sp80, 0x18, arg3, 1,
                                                           arg4);
    arg0->unk_38[0]->unk_00.unk_28 |= 0x100;
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_38[0], arg3, arg4);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_34, arg0->unk_38[0]);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_034));
    BattleInfoWidget_InitializeEntryMarker(sp60, -0x10, 8, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_38[0]->unk_44, sp60);

    arg0->unk_38[1] = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_03C_038));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_38[1], 0x12, 4, BattleInfoWidget_DrawEntry, sp80, 0x18, arg3, 1,
                                                           arg4);
    arg0->unk_38[1]->unk_00.unk_28 |= 0x100;
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_38[1], arg3, arg4);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_34, arg0->unk_38[1]);

    sp5C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_034));
    BattleInfoWidget_InitializeEntryMarker(sp5C, -0x10, 8, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_38[1]->unk_44, sp5C);
}

void BattleInfoWidget_SetEntries(unk_func_8830867C_034_03C* arg0, unk_func_8830867C_034_03C_038_02C* arg1,
                   unk_func_8830867C_034_03C_038_02C* arg2) {
    ((func885063B8)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridStridedData))(arg0->unk_38[0], arg1);
    ((func885063B8)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridStridedData))(arg0->unk_38[1], arg2);
    BattleInfoWidget_ApplyEntryDisabledFlags(arg0);
}

s32 BattleInfoWidget_HandleInput(unk_func_8830867C_034_03C* arg0, Controller* arg1) {
    s32 var_v1 = 0;
    unk_func_8830867C_034_03C_038* sp18;

    if (arg0->unk_2C->unk_30 & 2) {
        if (arg0->unk_34->unk_2C != 0) {
            sp18 = arg0->unk_38[arg0->unk_34->unk_2C - 1];
            var_v1 = sp18->unk_00.unk_20(sp18, arg1);
            if ((var_v1 == 0) && (gPlayer1Controller->buttonPressed & 0x8000)) {
                sp18->unk_34[sp18->unk_38] ^= 2;
                var_v1 = 0x80000004;
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void BattleInfoWidget_SelectPage(unk_func_8830867C_034_03C* arg0, s32 arg1) {
    ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_30, arg1);
    ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_34, arg1);
}

void BattleInfoWidget_InitializeEntryMarker(unk_func_8830867C_034_034* arg0, s32 arg1, s32 arg2, s32 arg3) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_034_034));
    arg0->unk_00.unk_18 = BattleInfoWidget_DrawEntryMarker;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_30 = arg3;
}

s32 BattleInfoWidget_DrawEntryMarker(unk_func_8830867C_034_034* arg0, s32 arg1, s32 arg2) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPLoadTextureBlock(gDisplayListHead++, (arg0->unk_30 != 0) ? D_883186E8 : D_88318530, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                        12, 18, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                        G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, arg1 << 2, arg2 << 2, (arg1 + 0xA) << 2, (arg2 + 0x11) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    gDPPipeSync(gDisplayListHead++);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

    return 0;
}

s32 BattleInfoWidget_GetPageSelectionFlags(unk_func_8830867C_02C_144_000* arg0) {
    s32 i;
    s32 var_v1 = 0;
    unk_func_8830867C_02C_0CC_000_000* ptr = arg0->unk_0C;

    for (i = 0; i < arg0->unk_14; i++) {
        if (ptr[i].unk_08 != 0) {
            var_v1 |= 2;
        }
    }

    return var_v1;
}

void BattleInfoWidget_SyncParentSelection(unk_func_8830867C_034* arg0, unk_func_8830867C_034_03C* arg1) {
    s32 i;
    unk_func_8830867C_034_03C_038* temp_v0 = arg1->unk_38[arg1->unk_34->unk_2C - 1];
    s32 var_v1 = 0;

    for (i = 0; i < temp_v0->unk_2C->unk_08; i++) {
        if (arg0) {}

        if (temp_v0->unk_34[i] & 2) {
            var_v1 = 2;
            break;
        }
    }

    arg0->unk_30->unk_34[arg0->unk_30->unk_38] &= ~2;
    arg0->unk_30->unk_34[arg0->unk_30->unk_38] |= var_v1;
}

void BattleInfoWidget_UpdateEntryFlags(unk_func_8830867C_034* arg0) {
    s32 i;
    unk_func_8830867C_02C_144_000* var_s2 = arg0->unk_30->unk_2C->unk_00;

    for (i = 0; i < arg0->unk_30->unk_2C->unk_08; i++, var_s2++) {
        arg0->unk_30->unk_34[i] = 0;
        arg0->unk_30->unk_34[i] |= BattleInfoWidget_GetPageSelectionFlags(var_s2);
    }
}

void BattleInfoWidget_UpdateConfirmState(unk_func_8830867C_034* arg0) {
    static Color_RGBA8 D_88317438 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_8831743C = { 0xF0, 0xF0, 0xF0, 0x4D };

    s32 i;
    s32 var_a1;
    unk_func_88200FA0_030_030_1CEA00* temp_v0 = arg0->unk_30;
    unk_func_8830867C_02C_0CC* ptr = temp_v0->unk_2C;

    var_a1 = 1;

    for (i = 0; i < ptr->unk_08; i++) {
        if (temp_v0->unk_34[i] & 2) {
            var_a1 = 0;
            break;
        }
    }

    if (var_a1 != 0) {
        arg0->unk_40->unk_00.unk_28 |= 2;
        arg0->unk_40->unk_30 = (0, D_8831743C);
        arg0->unk_40->unk_44 = arg0->unk_40->unk_44;
    } else {
        arg0->unk_40->unk_00.unk_28 &= ~2;
        arg0->unk_40->unk_30 = (0, D_88317438);
        arg0->unk_40->unk_44 = arg0->unk_40->unk_44;
    }
}

void BattleInfoWidget_ApplyEntrySelection(unk_func_8830867C_034* arg0, s32 arg1) {
    unk_func_8830867C_02C_144_000* ptr = &((unk_func_8830867C_02C_144*)(arg0->unk_30->unk_2C))->unk_00[arg1];
    unk_func_8830867C_02C_0CC_000_000* ptr2 = ptr->unk_0C;

    ptr2->unk_08 = (arg0->unk_30->unk_34[arg1] & 2) != 0;
}

void BattleInfoWidget_DrawStatusEntry(s32 arg0, s32 arg1, unk_func_88309C38_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_88200FA0_030_030* arg5) {
    static Color_RGBA8 D_88317440 = { 0xF0, 0xF0, 0xF0, 0xFF };

    Color_RGBA8 sp34;
    UNUSED s32 pad[2];

    if (arg2 != NULL) {
        if (arg4 & 2) {
            Gfx_DrawTiledTextureStrip(&D_800758E0, arg0 + 8, arg1 + 4);
        } else {
            Gfx_DrawTiledTextureStrip(&D_800758F0, arg0 + 8, arg1 + 4);
        }
        sp34 = D_88317440;
        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(sp34.r, sp34.g, sp34.b, sp34.a);
        Font_SetActive(8, 0);
        Font_Printf(arg0 + 0x2C, arg1 + 4, Text_GetString(NULL, 0, D_8831A4C4, arg3 + 0x3B));
        Font_EndTexturedTextRendering();
        if (arg2->unk_14 == 1) {
            BattleInfoWidget_DrawIndicator((arg5->unk_00.unk_14.unk_00 + arg0) - 0x35, arg1 + 0xC, arg2->unk_0C->unk_18,
                          arg2->unk_0C->unk_14);
        }
    }
}

s32 BattleInfoWidget_GetStatusEntryWidth(void) {
    s32 i;
    s32 var_s1 = 0;
    s32 var_v1;

    for (i = 0; i < 3; i++) {
        var_v1 = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_8831A4C4, i + 0x3B));

        if (i == 0) {
            var_v1 += 0x3D;
        }

        if (var_s1 < var_v1) {
            var_s1 = var_v1;
        }
    }

    return var_s1;
}

void BattleInfoWidget_Build(unk_func_8830867C_034* arg0, s32 arg1, s32 arg2, WidgetNode* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88317444 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317448 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_8831744C = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_88317450 = { 0xFF, 0xFF, 0x00, 0xFF };

    UNUSED s32 pad[3];
    char* sp88;
    s32 sp84;
    s32 sp80;
    unk_func_8850B254* sp7C;
    unk_func_8850878C* sp78;
    unk_func_885012A4* sp74;
    unk_func_8850BD40* sp70;
    WidgetNode* sp6C;
    char* sp68;
    s32 sp64;
    s32 sp60;
    WidgetAnimatedFrame* sp5C;
    unk_func_8850BD40* sp58;
    unk_func_8850BD40* sp54;
    unk_func_88503298* sp50;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_034));

    arg0->unk_00.unk_20 = BattleInfoWidget_HandleContainerInput;
    arg0->unk_00.unk_24 = BattleInfoWidget_SetWidgetState;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    sp80 = BattleInfoWidget_GetStatusEntryWidth() + 0x36;
    sp88 = Text_GetString(NULL, 0, D_8831A4C4, 0x39);
    sp84 = Font_MeasureTextExtent(8, 0, sp88);
    if (sp84 < sp80) {
        sp84 = sp80;
    }
    sp84 += 0x10;

    arg0->unk_38 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_038));
    BattleInfoWidget_InitSelectionProxy(arg0->unk_38, arg0);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, sp84, 0xAC);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    sp7C = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(sp7C, 0, 0, sp84, 0x2C, D_88317444, D_88317448);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp7C);

    sp78 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp78, 8, 0, sp88, 8);
    sp78->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp7C, sp78);

    sp74 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp74, 0, 0x30, sp84, 0x7C, D_8831744C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp74);

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_30, 0, 4, BattleInfoWidget_DrawStatusEntry, sp84 - 0x12, 0x1C, 3, 1,
                                                           arg4);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_30, 3, arg4);
    arg0->unk_30->unk_00.unk_28 |= 0x300;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp74, arg0->unk_30);

    arg0->unk_34 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_034));
    BattleInfoWidget_InitializeEntryMarker(arg0->unk_34, arg0->unk_30->unk_00.unk_14.unk_00 + 3, 9, 1);
    arg0->unk_34->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_30->unk_44, arg0->unk_34);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(sp70, arg0->unk_30);
    ((func8850CC74)Memmap_GetFragmentVaddr(WidgetTree_AppendChildSelectionProxyItem))(arg0->unk_38, sp70);
    sp68 = Text_GetString(NULL, 0, D_8831A4C4, 0x46);
    sp64 = Font_MeasureTextExtent(8, 0, sp68);
    sp60 = sp64 + 0x10;
    if (sp60 < 0x48) {
        sp60 = 0x48;
    }

    sp6C = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func8850A40C)Memmap_GetFragmentVaddr(WidgetTree_InitBorderFrame))(sp6C, (sp84 - sp60) / 2, 0x5C, sp60, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp74, sp6C);

    arg0->unk_40 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_40, (sp60 - sp64) / 2, 2, sp68, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp6C, arg0->unk_40);

    sp5C = mem_pool_alloc(arg4, sizeof(WidgetAnimatedFrame));
    ((func88504570)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedFrameVariantC))(sp5C, -3, -3, sp6C->unk_14.unk_00 + 6,
                                                           sp6C->unk_14.unk_02 + 6, D_88317450);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp6C, sp5C);

    sp58 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(sp58, sp6C);
    ((func8850CC74)Memmap_GetFragmentVaddr(WidgetTree_AppendChildSelectionProxyItem))(arg0->unk_38, sp58);

    arg0->unk_3C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_034_03C));
    BattleInfoWidget_Initialize(arg0->unk_3C, arg0->unk_2C->unk_00.unk_14.unk_00 + 0x10, 0, 0xC, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_3C);

    sp54 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(sp54, arg0->unk_3C);
    ((func8850CC74)Memmap_GetFragmentVaddr(WidgetTree_AppendChildSelectionProxyItem))(arg0->unk_38, sp54);

    sp50 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(sp50, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, sp50);
}

void BattleInfoWidget_BindData(unk_func_8830867C_034* arg0, unk_func_8830867C_02C_144* arg1) {
    unk_func_8830867C_02C_144_000_alt* sp1C;

    ((func885063B8)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridStridedData))(arg0->unk_30, arg1);

    sp1C = arg1->unk_00;
    BattleInfoWidget_UpdateEntryFlags(arg0);
    BattleInfoWidget_SetEntries(arg0->unk_3C, &sp1C->unk_2C, &sp1C->unk_4C);
}

void BattleInfoWidget_SetWidgetState(unk_func_8830867C_034* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_38->unk_00.unk_14(arg0->unk_38, arg1);
}

s32 BattleInfoWidget_HandleContainerInput(unk_func_8830867C_034* arg0, Controller* arg1) {
    s32 sp1C;

    if (arg0->unk_2C->unk_30 & 2) {
        sp1C = arg0->unk_38->unk_00.unk_10(arg0->unk_38, arg1);
        if (!(sp1C & 1) && (sp1C & 4)) {
            BattleInfoWidget_ApplyEntrySelection(arg0, 0);
            BattleInfoWidget_SyncEntrySelection(arg0->unk_3C);
        }
    } else {
        sp1C = 1;
    }
    return sp1C;
}

void BattleInfoWidget_InitSelectionProxy(unk_func_8830867C_034_038* arg0, unk_func_8830867C_034* arg1) {
    ((func8850CBA8)Memmap_GetFragmentVaddr(WidgetTree_InitChildSelectionProxy))(arg0);
    arg0->unk_00.unk_10 = BattleInfoWidget_HandleSelectionProxyInput;
    arg0->unk_24 = arg1;
}

s32 BattleInfoWidget_HandleSelectionProxyInput(unk_func_8830867C_034_038* arg0, Controller* arg1) {
    s32 var_v1 = 0;
    s32 i;
    unk_func_8830867C_034_038* var_a0;

    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;

        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }

        var_v1 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    switch (arg0->unk_00.unk_1C) {
        case 0:
            if (var_v1 & 1) {
                if (var_v1 & 8) {
                    arg0->unk_24->unk_34->unk_00.unk_28 &= ~1;
                    if (arg0->unk_24->unk_30->unk_38 != 0) {
                        arg0->unk_24->unk_34->unk_00.unk_28 |= 1;
                    }
                    BattleInfoWidget_SelectPage(arg0->unk_24->unk_3C, arg0->unk_24->unk_30->unk_38);
                }
            } else if (var_v1 & 8) {
                if (arg1->buttonPressed & 0x800) {
                    ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 1);
                    BattleInfoWidget_SelectPage(arg0->unk_24->unk_3C, 0);
                    var_v1 |= 0x80000001;
                } else if (arg1->buttonPressed & 0x400) {
                    arg0->unk_24->unk_34->unk_00.unk_28 &= ~1;
                    ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 1);
                    BattleInfoWidget_SelectPage(arg0->unk_24->unk_3C, 0);
                    var_v1 |= 0x80000001;
                } else if ((arg1->buttonPressed & 0x100) && (arg0->unk_24->unk_30->unk_38 != 0)) {
                    ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 2);
                    var_v1 |= 0x80000001;
                }
            } else {
                if (arg1->buttonPressed & 0x8000) {
                    arg0->unk_24->unk_30->unk_34[arg0->unk_24->unk_30->unk_38] ^= 2;
                    if (arg0->unk_24->unk_30->unk_38 != 0) {
                        BattleInfoWidget_SetActivePageFlags(arg0->unk_24->unk_3C,
                                      arg0->unk_24->unk_30->unk_34[arg0->unk_24->unk_30->unk_38] & 2);
                    }
                    BattleInfoWidget_UpdateConfirmState(arg0->unk_24);
                    var_v1 = 0x80000005;
                } else if (arg1->buttonPressed & 0x4000) {
                    var_v1 = 0x80000002;
                }
            }
            break;

        case 1:
            if (arg1->buttonPressed & 0x800) {
                arg0->unk_24->unk_34->unk_00.unk_28 |= 1;
                ((func88506BFC)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelection))(arg0->unk_24->unk_30,
                                                                       arg0->unk_24->unk_30->unk_2C->unk_08 - 1);
                BattleInfoWidget_SelectPage(arg0->unk_24->unk_3C, arg0->unk_24->unk_30->unk_38);
                ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 0);
                var_v1 = 0x80000009;
            } else if (arg1->buttonPressed & 0x400) {
                ((func88506BFC)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelection))(arg0->unk_24->unk_30, 0);
                BattleInfoWidget_SelectPage(arg0->unk_24->unk_3C, arg0->unk_24->unk_30->unk_38);
                ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 0);
                var_v1 = 0x80000009;
            } else if (arg1->buttonPressed & 0x8000) {
                if (arg0->unk_24->unk_40->unk_00.unk_28 & 2) {
                    var_v1 = 0x80000101;
                } else {
                    var_v1 = 0x80000004;
                }
            } else if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            }
            break;

        case 2:
            if (!(var_v1 & 1)) {
                if (var_v1 & 8) {
                    if (arg1->buttonPressed & 0x200) {
                        ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, 0);
                        var_v1 = 0x80000009;
                    }
                } else if (var_v1 & 4) {
                    BattleInfoWidget_SyncParentSelection(arg0->unk_24, arg0->unk_24->unk_3C);
                    BattleInfoWidget_UpdateConfirmState(arg0->unk_24);
                    var_v1 |= 1;
                } else if (arg1->buttonPressed & 0x4000) {
                    var_v1 = 0x80000002;
                }
            }
            break;
    }
    return var_v1;
}

void BattleInfoWidget_OpenPanels(unk_func_8830867C_034* arg0) {
    BattleInfoWidget_SelectPage(arg0->unk_3C, 0);
    ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0->unk_38, 1);
    arg0->unk_38->unk_00.unk_14(arg0->unk_38, 1);
    arg0->unk_34->unk_00.unk_28 &= ~1;
    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);
    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_3C->unk_2C);
}

void BattleInfoWidget_SetCloseState(unk_func_8830867C_034* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
    arg0->unk_3C->unk_2C->unk_2C = 0xB;
}

s32 BattleInfoWidget_RunSelectionModal(unk_func_8830867C_034* arg0, Controller* arg1) {
    s32 var_s0 = 0;
    s32 temp_v0;

    BattleInfoWidget_OpenPanels(arg0);
    Input_SetRepeatController(arg1);

    while (var_s0 == 0) {
        Ui_SendMessageAndPollInput(var_s0);
        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                var_s0 = 2;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(temp_v0);
    }

    BattleInfoWidget_SetCloseState(arg0);
    return var_s0 - 1;
}

void BattleInfoWidget_DrawLabel(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4) {
    static Color_RGBA8 D_88317454 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88317458 = { 0xF0, 0xF0, 0xF0, 0x4D };

    Color_RGBA8 sp1C;

    if (arg4 & 4) {
        sp1C = (0, D_88317458);
    } else {
        sp1C = (0, D_88317454);
    }

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(sp1C.r, sp1C.g, sp1C.b, sp1C.a);
    Font_SetActive(8, 0);
    Font_Printf(arg0 + 8, arg1 + 4, arg2);
    Font_EndTexturedTextRendering();
}

void BattleInfoWidget_InitDropdownMenu(unk_func_8830867C_030* arg0, WidgetNode* arg1, MemoryPool* arg2) {
    static Color_RGBA8 D_8831745C = { 0xA0, 0x96, 0x64, 0xFF };

    unk_func_88503298* sp44;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_030));

    arg0->unk_00.unk_20 = BattleInfoWidget_HandleSelectionInput;
    arg0->unk_00.unk_24 = BattleInfoWidget_SetSelectionState;
    arg0->unk_00.unk_10.unk_00 = 0;
    arg0->unk_00.unk_10.unk_02 = 0;

    arg0->unk_2C = mem_pool_alloc(arg2, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, 0x10, 0x10);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    arg0->unk_38 = mem_pool_alloc(arg2, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(arg0->unk_38, 0, 0, 0x10, 0x10, D_8831745C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_38);

    arg0->unk_3C = mem_pool_alloc(arg2, sizeof(unk_func_88200FA0_030_030_1CEA00));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_3C, 0, 4, BattleInfoWidget_DrawLabel, 0x10, 0x10, 0xA, 1, arg2);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_3C, 0xA, arg2);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_3C);

    if (arg1 != NULL) {
        sp44 = mem_pool_alloc(arg2, sizeof(unk_func_88503298));
        ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(sp44, arg0->unk_2C, arg1);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, sp44);
    }
}

void BattleInfoWidget_SetLabels(unk_func_8830867C_030* arg0, char** arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_s1;
    s32 i;

    var_s1 = 0;
    for (i = 0; i < arg2; i++) {
        temp_v0 = Font_MeasureTextExtent(8, 0, arg1[i]);
        if (var_s1 < temp_v0) {
            var_s1 = temp_v0;
        }
    }

    var_s1 += 0x10;
    PointerList_Initialize(&arg0->unk_40, arg1, arg2, arg2);
    ((func8850633C)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridData))(arg0->unk_3C, &arg0->unk_40);

    arg0->unk_3C->unk_4A = arg2;

    arg0->unk_2C->unk_00.unk_14.unk_00 = var_s1;
    arg0->unk_2C->unk_00.unk_14.unk_02 = (arg0->unk_40.unk_08 * 0x1C) + 8;

    arg0->unk_3C->unk_3C = var_s1;
    arg0->unk_3C->unk_3E = 0x1C;
    arg0->unk_3C->unk_44->unk_00.unk_14.unk_00 = var_s1;
    arg0->unk_3C->unk_44->unk_00.unk_14.unk_02 = 0x22;
    arg0->unk_3C->unk_50 = 0;
    arg0->unk_3C->unk_52 = -3;
    arg0->unk_3C->unk_00.unk_14 = arg0->unk_2C->unk_00.unk_14;
    arg0->unk_38->unk_00.unk_14 = arg0->unk_2C->unk_00.unk_14;
}

void BattleInfoWidget_UpdateViewport(unk_func_8830867C_030* arg0) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1_4;

    temp_v0 = arg0->unk_2C->unk_00.unk_14.unk_00 + 8;
    temp_a1 = arg0->unk_2C->unk_00.unk_14.unk_02 + 8;

    if (arg0->unk_00.unk_28 & 0x100) {
        if (arg0->unk_50 >= (arg0->unk_30.unk_02 + temp_a1)) {
            arg0->unk_00.unk_10.unk_02 = arg0->unk_30.unk_02 + 4;
        } else {
            temp_a1 = ((arg0->unk_30.unk_02 + temp_a1) - arg0->unk_50);
            arg0->unk_00.unk_10.unk_02 = (arg0->unk_30.unk_02 - temp_a1) + 4;
        }

        temp_v0_2 = arg0->unk_30.unk_00 + arg0->unk_34.unk_00;
        if (arg0->unk_4C >= (temp_v0_2 + temp_v0)) {
            arg0->unk_00.unk_10.unk_00 = temp_v0_2 + 4;
        } else {
            arg0->unk_00.unk_10.unk_00 = (arg0->unk_30.unk_00 - temp_v0) + 4;
        }
    } else {
        if (arg0->unk_4C >= (arg0->unk_30.unk_00 + temp_v0)) {
            arg0->unk_00.unk_10.unk_00 = arg0->unk_30.unk_00 + 4;
        } else {
            temp_v1_4 = ((arg0->unk_30.unk_00 + temp_v0) - arg0->unk_4C);
            arg0->unk_00.unk_10.unk_00 = (arg0->unk_30.unk_00 - temp_v1_4) + 4;
        }

        temp_v0 = arg0->unk_30.unk_02 + arg0->unk_34.unk_02;
        if (arg0->unk_50 >= (temp_v0 + temp_a1)) {
            arg0->unk_00.unk_10.unk_02 = temp_v0 + 4;
        } else {
            arg0->unk_00.unk_10.unk_02 = (arg0->unk_30.unk_02 - temp_a1) + 4;
        }
    }
}

void BattleInfoWidget_SetSelectionState(unk_func_8830867C_030* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_3C->unk_00.unk_24(&arg0->unk_3C->unk_00, arg1);
}

s32 BattleInfoWidget_HandleSelectionInput(unk_func_8830867C_030* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_3C->unk_00.unk_20(arg0->unk_3C, arg1);
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

void BattleInfoWidget_OpenSelectionAt(unk_func_8830867C_030* arg0, s32 arg1) {
    arg0->unk_3C->unk_38 = arg1;
    ((func88506CE4)Memmap_GetFragmentVaddr(WidgetTree_FindSelectableGridEntry))(arg0->unk_3C);
    arg0->unk_00.unk_24(&arg0->unk_00, 1);
    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);
}

void BattleInfoWidget_CloseSelection(unk_func_8830867C_030* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
}

u32 BattleInfoWidget_RunEntryModal(unk_func_8830867C_030* arg0, Controller* arg1, s32 arg2) {
    s32 var_s0;
    s32 var_s1 = 0;

    BattleInfoWidget_OpenSelectionAt(arg0, arg2);

    while (var_s1 == NULL) {
        Ui_SendMessageAndPollInput(var_s1);
        var_s0 = arg0->unk_00.unk_20(arg0, arg1);
        if (var_s0 & 2) {
            var_s1 = 1;
        } else if (var_s0 & 4) {
            if (arg0->unk_3C->unk_34[arg0->unk_3C->unk_38] & 4) {
                var_s0 = (var_s0 & ~4) | 0x100;
            } else {
                var_s1 = arg0->unk_3C->unk_38 + 2;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(var_s0);
    }
    BattleInfoWidget_CloseSelection(arg0);
    return var_s1 - 1;
}

void BattleInfoWidget_DrawStatusMenuLabel(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4) {
    static Color_RGBA8 D_88317460 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88317464 = { 0xF0, 0xF0, 0xF0, 0x4D };
    static Color_RGBA8 D_88317468 = { 0xF0, 0xF0, 0x00, 0xFF };

    Color_RGBA8 sp24;
    UNUSED s32 pad[2];

    if (arg4 & 2) {
        sp24 = (0, D_88317468);
    } else if (arg4 & 4) {
        sp24 = (0, D_88317464);
    } else {
        sp24 = (0, D_88317460);
    }

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(sp24.r, sp24.g, sp24.b, sp24.a);
    Font_SetActive(8, 0);
    Font_Printf(arg0 + 0x11, arg1 + 4, arg2);
    Font_EndTexturedTextRendering();
}

void BattleInfoWidget_BuildStatusMenu(unk_func_8830867C_038* arg0, s32 arg1, s32 arg2, WidgetNode* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_8831746C = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317470 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317474 = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_88317478 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_8831747C = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317480 = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_88317484 = { 0xB2, 0xFF, 0xC3, 0xFF };
    static Color_RGBA8 D_88317488 = { 0xFF, 0xB2, 0xC3, 0xFF };

    s32 i;
    UNUSED s32 pad;
    s32 spAC;
    UNUSED s32 pad2;
    s32 spA4;
    UNUSED s32 pad3;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 tmp;
    s32 temp_v0;
    unk_func_8850B254* sp88;
    unk_func_8850878C* sp84;
    s32 temp_v0_6;
    s32 temp_v0_7;
    unk_func_885012A4* temp_s0_2;
    unk_func_88503298* temp_s0_3;
    unk_func_8850B254* sp70;
    char* sp6C;
    unk_func_8850878C* sp68;
    unk_func_885012A4* sp64;
    unk_func_8850878C* sp60;
    char* sp5C;

    spAC = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_8831A4C4, 0x2A));
    PointerList_Allocate(&arg0->unk_34, 4, arg4);
    PointerList_Insert(&arg0->unk_34, Text_GetString(NULL, 0, D_8831A4C4, 0x2C), 0);
    PointerList_Insert(&arg0->unk_34, Text_GetString(NULL, 0, D_8831A4C4, 0x2D), 1);
    PointerList_Insert(&arg0->unk_34, Text_GetString(NULL, 0, D_8831A4C4, 0x30), 2);
    PointerList_Insert(&arg0->unk_34, Text_GetString(NULL, 0, D_8831A4C4, 0x31), 3);

    for (i = 0; i < 4; i++) {
        temp_v0 = Font_MeasureTextExtent(8, 0, arg0->unk_34.unk_00[i]);
        if (spAC < temp_v0) {
            spAC = temp_v0;
        }
    }

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030_030_1CEA00));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_30, 0, 4, BattleInfoWidget_DrawStatusMenuLabel, spAC, 0x1C, 4, 1, arg4);
    ((func88506384)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridPage))(arg0->unk_30, &arg0->unk_34, arg4);
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, 0x44);

    arg0->unk_00.unk_20 = BattleInfoWidget_HandleStatusInput;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(WidgetAnimatedPanel));
    tmp = spAC + 0x10;
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, tmp, 0xA8);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    sp88 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(sp88, 0, 0, tmp, 0x2C, D_8831746C, D_88317470);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp88);

    sp84 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp84, 8, 0, Text_GetString(NULL, 0, D_8831A4C4, 0x2A), 8);
    sp84->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp88, sp84);

    temp_s0_2 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(temp_s0_2, 0, 0x30, tmp, 0x78, D_88317474);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, temp_s0_2);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s0_2, arg0->unk_30);

    temp_s0_3 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(temp_s0_3, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, temp_s0_3);

    arg0->unk_40 = mem_pool_alloc(arg4, sizeof(WidgetAnimatedPanel));

    sp9C = 0;
    for (i = 0; i < 3; i++) {
        temp_v0_6 = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_8831A4C4, i + 0x32));
        if (sp9C < temp_v0_6) {
            sp9C = temp_v0_6;
        }
    }

    sp98 = 0;
    for (i = 0; i < 3; i++) {
        temp_v0_7 = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_8831A4C4, i + 0x35));
        if (sp98 < temp_v0_7) {
            sp98 = temp_v0_7;
        }
    }

    spA4 = sp9C + sp98 + 0x10;
    sp94 = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_8831A4C4, 0x38));
    if (spA4 < sp94) {
        spA4 = sp94;
    }
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_40, arg0->unk_2C->unk_00.unk_14.unk_00 + 0x10,
                                                           0x18, spA4 + 0x10, 0x90);
    arg0->unk_40->unk_00.unk_28 |= 0x200;
    arg0->unk_40->unk_00.unk_28 |= 0x400;
    arg0->unk_40->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_40);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(sp70, 0, 0, arg0->unk_40->unk_00.unk_14.unk_00, 0x14,
                                                           D_88317478, D_8831747C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_40, sp70);
    sp6C = Text_GetString(NULL, 0, D_8831A4C4, 0x2B);

    sp68 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(
        sp68, (arg0->unk_40->unk_00.unk_14.unk_00 - Font_MeasureTextExtent(8, 0, sp6C)) / 2, 0, sp6C, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp70, sp68);

    sp64 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp64, 0, 0x18, arg0->unk_40->unk_00.unk_14.unk_00, 0x78,
                                                           D_88317480);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_40, sp64);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    sp5C = Text_GetString(NULL, 0, D_8831A4C4, 0x32);
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp60, ((sp9C - Font_MeasureTextExtent(8, 0, sp5C)) / 2) + 8, 8, sp5C,
                                                           8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    sp5C = Text_GetString(NULL, 0, D_8831A4C4, 0x33);
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp60, ((sp9C - Font_MeasureTextExtent(8, 0, sp5C)) / 2) + 8, 0x24,
                                                           sp5C, 8);
    sp60->unk_30 = (0, D_88317484);
    sp60->unk_44 = sp60->unk_44;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    sp5C = Text_GetString(NULL, 0, D_8831A4C4, 0x34);
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp60, ((sp9C - Font_MeasureTextExtent(8, 0, sp5C)) / 2) + 8, 0x40,
                                                           sp5C, 8);
    sp60->unk_30 = (0, D_88317488);
    sp60->unk_44 = sp60->unk_44;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp60, sp9C + 0x18, 8,
                                                           Text_GetString(NULL, 0, D_8831A4C4, 0x35), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp60, sp9C + 0x18, 0x24,
                                                           Text_GetString(NULL, 0, D_8831A4C4, 0x36), 8);
    sp60->unk_30 = (0, D_88317484);
    sp60->unk_44 = sp60->unk_44;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp60, sp9C + 0x18, 0x40,
                                                           Text_GetString(NULL, 0, D_8831A4C4, 0x37), 8);
    sp60->unk_30 = (0, D_88317488);
    sp60->unk_44 = sp60->unk_44;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, sp60);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    sp5C = Text_GetString(NULL, 0, D_8831A4C4, 0x38);
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp60, (arg0->unk_40->unk_00.unk_14.unk_00 - sp94) / 2, 0x5C,
                                                           sp5C, 8);
    sp60->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, sp60);
}

void BattleInfoWidget_SetStatusSelection(unk_func_8830867C_038* arg0, s32 arg1) {
    s32 sp1C;

    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_30);
    if (arg1 == -1) {
        sp1C = 0;
        arg0->unk_30->unk_34[arg0->unk_30->unk_2C->unk_08 - 1] |= 4;
    } else {
        sp1C = arg1;
        arg0->unk_30->unk_34[arg1] |= 2;
    }
    ((func88506BFC)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelection))(arg0->unk_30, sp1C);
}

s32 BattleInfoWidget_HandleStatusInput(unk_func_8830867C_038* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
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

s32 BattleInfoWidget_RunStatusModal(unk_func_8830867C_038* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = NULL;
    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);
    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_40);

    while (var_s0 == 0) {
        Ui_SendMessageAndPollInput(var_s0);
        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                var_s0 = arg0->unk_30->unk_38 + 2;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(temp_v0);
    }
    arg0->unk_2C->unk_2C = 0xB;
    arg0->unk_40->unk_2C = 0xB;
    return var_s0 - 1;
}

void BattleInfoWidget_UpdateNumberIndicator(unk_func_8830867C_044_038* arg0) {
    s32 tmp = ((arg0->unk_30.unk_0C - arg0->unk_30.unk_10) - 1) * arg0->unk_44->unk_00.unk_14.unk_00;

    arg0->unk_44->unk_00.unk_10.unk_00 = tmp;
    arg0->unk_44->unk_00.unk_10.unk_02 = arg0->unk_44->unk_00.unk_10.unk_02;
}

void BattleInfoWidget_InitNumberSelectorDigits(unk_func_8830867C_044_038* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    s32 sp2C;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_044_038));

    arg0->unk_00.unk_18 = BattleInfoWidget_DrawNumberSelector;
    arg0->unk_00.unk_20 = BattleInfoWidget_HandleNumberSelectorInput;
    arg0->unk_00.unk_24 = BattleInfoWidget_SetNumberSelectorState;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    sp2C = Font_MeasureTextExtent(8, 0, "0");

    arg0->unk_44 = mem_pool_alloc(arg3, sizeof(unk_func_8820E99C_030_044));
    ((func88504F98)Memmap_GetFragmentVaddr(WidgetTree_InitDirectionalIndicator))(arg0->unk_44, -1, 0, sp2C + 2, 0x14);
    arg0->unk_44->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_44);
}

void BattleInfoWidget_SetNumberSelectorState(unk_func_8830867C_044_038* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_44->unk_00.unk_24(&arg0->unk_44->unk_00, arg1);
    arg0->unk_44->unk_00.unk_28 &= ~1;
    if (arg1 & 0x101) {
        arg0->unk_44->unk_00.unk_28 |= 1;
    }
}

s32 BattleInfoWidget_DrawNumberSelector(unk_func_8830867C_044_038* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_8831748C = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 i;
    s32 var_s2 = arg0->unk_30.unk_00;

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_8831748C.r, D_8831748C.g, D_8831748C.b, D_8831748C.a);
    Font_SetActive(8, 2);

    for (i = 0; i < arg0->unk_30.unk_0C; i++) {
        Font_DrawCharAt((((arg0->unk_30.unk_0C - i) - 1) * arg0->unk_44->unk_00.unk_14.unk_00) + arg1, arg2,
                      (var_s2 % 10) + 0x30);
        var_s2 /= 10;
    }

    Font_EndTexturedTextRendering();
    return 0;
}

s32 BattleInfoWidget_HandleNumberSelectorInput(unk_func_8830867C_044_038* arg0, Controller* arg1) {
    s32 var_v1 = Ui_AdjustNumericSelection(&arg0->unk_30, Input_GetRepeatedDPad() & 0xFFFF);

    if (!(var_v1 & 1)) {
        if (!(var_v1 & 8)) {
            if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            } else if (arg1->buttonPressed & 0x8000) {
                var_v1 = 0x80000004;
            }
        }
    } else {
        BattleInfoWidget_UpdateNumberIndicator(arg0);
    }
    return var_v1;
}

void BattleInfoWidget_BuildLevelRangeMenu(unk_func_8830867C_044* arg0, s32 arg1, s32 arg2, WidgetNode* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88317490 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317494 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317498 = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_8831749C = { 0xC8, 0xC8, 0xFF, 0xFF };
    static Color_RGBA8 D_883174A0 = { 0xFF, 0xFF, 0x00, 0xFF };

    s32 i;
    s32 temp_v0;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    unk_func_8850878C* temp_s0_5;
    WidgetAnimatedFrame* temp_s0_6;
    unk_func_8850B254* sp80;
    WidgetGridMenu* ptr;
    unk_func_885012A4* sp78;
    UNUSED s32 pad;
    unk_func_8850878C* temp_s0;
    unk_func_8850BD40* temp_s0_2;
    unk_func_8850BD40* temp_s0_3;
    WidgetNode* sp64;
    char* sp60;
    unk_func_8850878C* temp_s0_4;
    s32 sp58;
    s32 tmp;
    unk_func_88503298* temp_s0_7;

    sp94 = Font_MeasureTextExtent(4, 0, Text_GetString(NULL, 0, D_8831A4C4, 0x48));
    sp90 = (Font_MeasureTextExtent(8, 0, "0") * 3) + 6;
    sp8C = 0;

    for (i = 0; i < 2; i++) {
        temp_v0 = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_8831A4C4, i + 0x49));
        if (sp8C < temp_v0) {
            sp8C = temp_v0;
        }
    }

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_044));

    arg0->unk_00.unk_20 = BattleInfoWidget_HandleLevelRangeInput;
    arg0->unk_00.unk_24 = BattleInfoWidget_SetLevelRangeState;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_40 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_044_040));
    BattleInfoWidget_InitLevelRangeSelectionProxy(arg0->unk_40, arg0);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, (sp90 + sp94) + sp90 + sp8C + 0x34,
                                                           0x5C);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    sp80 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(sp80, 0, 0, (sp90 + sp94) + sp90 + sp8C + 0x34, 0x14,
                                                           D_88317490, D_88317494);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp80);

    temp_s0 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(temp_s0, 8, 0, Text_GetString(NULL, 0, D_8831A4C4, 0x47), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp80, temp_s0);

    sp78 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp78, 0, 0x18, (sp90 + sp94) + sp90 + sp8C + 0x34, 0x44,
                                                           D_88317498);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp78);

    arg0->unk_38 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_044_038));
    BattleInfoWidget_InitNumberSelectorDigits(arg0->unk_38, 8, 0xA, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp78, arg0->unk_38);

    temp_s0_2 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(temp_s0_2, arg0->unk_38);
    ((func8850CC74)Memmap_GetFragmentVaddr(WidgetTree_AppendChildSelectionProxyItem))(arg0->unk_40, temp_s0_2);

    arg0->unk_3C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_044_038));
    BattleInfoWidget_InitNumberSelectorDigits(arg0->unk_3C, (sp90 + sp94) + 0x18, 0xA, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp78, arg0->unk_3C);

    temp_s0_3 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(temp_s0_3, arg0->unk_3C);
    ((func8850CC74)Memmap_GetFragmentVaddr(WidgetTree_AppendChildSelectionProxyItem))(arg0->unk_40, temp_s0_3);

    temp_s0_4 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(temp_s0_4, sp90 + 0x10, 0xD,
                                                           Text_GetString(NULL, 0, D_8831A4C4, 0x48), 4);
    temp_s0_4->unk_30 = D_8831749C;
    temp_s0_4->unk_44 = temp_s0_4->unk_44;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp78, temp_s0_4);

    arg0->unk_44 = mem_pool_alloc(arg4, sizeof(WidgetGridMenu));
    ((func8850C284)Memmap_GetFragmentVaddr(WidgetTree_InitGridMenu))(arg0->unk_44, 2, 1, arg4);
    arg0->unk_44->unk_28 |= 0x100;
    ((func8850CC74)Memmap_GetFragmentVaddr(WidgetTree_AppendChildSelectionProxyItem))(arg0->unk_40, arg0->unk_44);

    sp64 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    tmp = (sp90 * 2) + sp94 + 0x20;
    ((func8850A40C)Memmap_GetFragmentVaddr(WidgetTree_InitBorderFrame))(sp64, tmp, 8, sp8C + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp78, sp64);
    ptr = arg0->unk_44;
    ptr->unk_18[0] = sp64;
    sp60 = Text_GetString(NULL, 0, D_8831A4C4, 0x49);
    sp58 = Font_MeasureTextExtent(8, 0, sp60);

    temp_s0_5 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(temp_s0_5, ((sp8C - sp58) / 2) + 6, 2, sp60, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp64, temp_s0_5);

    arg0->unk_34 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func8850A40C)Memmap_GetFragmentVaddr(WidgetTree_InitBorderFrame))(arg0->unk_34, tmp, 0x24, sp8C + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp78, arg0->unk_34);
    arg0->unk_44->unk_18[arg0->unk_44->unk_2C] = arg0->unk_34;
    sp60 = Text_GetString(NULL, 0, D_8831A4C4, 0x4A);
    sp58 = Font_MeasureTextExtent(8, 0, sp60);

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_30, ((sp8C - sp58) / 2) + 6, 2, sp60, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_34, arg0->unk_30);
    ((func8850CAB4)Memmap_GetFragmentVaddr(WidgetTree_SelectFirstEnabledGridItem))(arg0->unk_44);

    temp_s0_6 = mem_pool_alloc(arg4, sizeof(WidgetAnimatedFrame));
    ((func88504570)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedFrameVariantC))(temp_s0_6, 0, 0, 0x10, 0x10, D_883174A0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp78, temp_s0_6);
    arg0->unk_44->unk_1C = temp_s0_6;

    temp_s0_7 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(temp_s0_7, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, temp_s0_7);
}

void BattleInfoWidget_SetLevelRange(unk_func_8830867C_044* arg0, s32 arg1, s32 arg2, s32 arg3) {
    static Color_RGBA8 D_883174A4 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_883174A8 = { 0xF0, 0xF0, 0xF0, 0x4D };
    static Color_RGBA8 D_883174AC = { 0x66, 0x5B, 0x47, 0xFF };

    WidgetNode* temp_v0;
    WidgetNode* temp_v0_2;
    unk_func_8850878C* temp_v1;
    unk_func_8850878C* temp_v1_2;

    arg0->unk_38->unk_30.unk_0C = 3;
    arg0->unk_38->unk_30.unk_00 = arg1;
    arg0->unk_38->unk_30.unk_04 = 1;
    arg0->unk_38->unk_30.unk_08 = 0x64;
    arg0->unk_38->unk_30.unk_10 = 0;

    BattleInfoWidget_UpdateNumberIndicator(arg0->unk_38);

    arg0->unk_3C->unk_30.unk_0C = 3;
    arg0->unk_3C->unk_30.unk_00 = arg2;
    arg0->unk_3C->unk_30.unk_04 = 1;
    arg0->unk_3C->unk_30.unk_08 = 0x64;
    arg0->unk_3C->unk_30.unk_10 = 0;

    BattleInfoWidget_UpdateNumberIndicator(arg0->unk_3C);

    if (arg3 == 0) {
        arg0->unk_34->unk_28 |= 2;
        arg0->unk_30->unk_30 = (0, D_883174A8);
        arg0->unk_30->unk_44 = arg0->unk_30->unk_44;
    } else {
        arg0->unk_34->unk_28 &= ~2;
        arg0->unk_30->unk_30 = (0, D_883174A4);
        arg0->unk_30->unk_44 = arg0->unk_30->unk_44;
    }
}

void BattleInfoWidget_SetLevelRangeState(unk_func_8830867C_044* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_40->unk_00.unk_14(arg0->unk_40, arg1);
}

s32 BattleInfoWidget_HandleLevelRangeInput(unk_func_8830867C_044* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_40->unk_00.unk_10(arg0->unk_40, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 BattleInfoWidget_RunLevelRangeModal(unk_func_8830867C_044* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_v0;
    s32 var_s0 = 0;

    ((func8850CB48)Memmap_GetFragmentVaddr(WidgetTree_SetGridMenuSelection))(arg0->unk_44, 0);
    ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0->unk_40, 0);

    arg0->unk_40->unk_00.unk_14(arg0->unk_40, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);
    while (var_s0 == 0) {
        Ui_SendMessageAndPollInput(var_s0);

        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);

        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                if (arg0->unk_44->unk_24 == 0) {
                    var_v0 = 1;
                } else {
                    var_v0 = 2;
                }
                var_s0 = var_v0 + 1;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(temp_v0);
    }
    arg0->unk_2C->unk_2C = 0xB;
    return var_s0 - 1;
}

void BattleInfoWidget_InitLevelRangeSelectionProxy(unk_func_8830867C_044_040* arg0, unk_func_8830867C_044* arg1) {
    ((func8850CBA8)Memmap_GetFragmentVaddr(WidgetTree_InitChildSelectionProxy))(arg0);
    arg0->unk_00.unk_10 = BattleInfoWidget_LevelRangeSelectionInput;
    arg0->unk_24 = arg1;
}

s32 BattleInfoWidget_LevelRangeSelectionInput(unk_func_8830867C_044_040* arg0, Controller* arg1) {
    s32 var_v1;
    UNUSED s32 pad;
    s32 i;
    unk_func_8830867C_034_038* var_a0;

    var_v1 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;

        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }
        var_v1 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

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

    if (var_v1 & 8) {
        if (arg1->buttonPressed & 0x200) {
            s32 var_a1 = arg0->unk_00.unk_1C;

            if (var_a1 == 0) {
                var_a1 = 3;
            }
            var_a1--;

            switch (var_a1) {
                case 0:
                    arg0->unk_24->unk_38->unk_30.unk_10 = 0;
                    BattleInfoWidget_UpdateNumberIndicator(arg0->unk_24->unk_38);
                    break;

                case 1:
                    arg0->unk_24->unk_3C->unk_30.unk_10 = 0;
                    BattleInfoWidget_UpdateNumberIndicator(arg0->unk_24->unk_3C);
                    break;
            }
            ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, var_a1);
            var_v1 |= 0x80000001;
        } else if (arg1->buttonPressed & 0x100) {
            s32 var_a1 = arg0->unk_00.unk_1C + 1;

            if (var_a1 == 3) {
                var_a1 = 0;
            }

            switch (var_a1) {
                case 0:
                    arg0->unk_24->unk_38->unk_30.unk_10 = 2;
                    BattleInfoWidget_UpdateNumberIndicator(arg0->unk_24->unk_38);
                    break;

                case 1:
                    arg0->unk_24->unk_3C->unk_30.unk_10 = 2;
                    BattleInfoWidget_UpdateNumberIndicator(arg0->unk_24->unk_3C);
                    break;
            }
            ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0, var_a1);
            var_v1 |= 0x80000001;
        }
    } else if (!(var_v1 & 2) && (var_v1 & 4)) {
        switch (arg0->unk_00.unk_1C) {
            case 2:
                break;

            case 0:
            case 1:
                var_v1 = 1;
                break;
        }
    }
    return var_v1;
}

void BattleInfoWidget_DrawStatusListEntry(s32 arg0, s32 arg1, unk_func_88309C38_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_8821421C_038_034* arg5) {
    static Color_RGBA8 D_883174B0 = { 0x54, 0x4B, 0x3A, 0xFF };
    static Color_RGBA8 D_883174B4 = { 0x99, 0x89, 0x6A, 0xFF };

    Color_RGBA8 sp84;
    UNUSED s32 pad;
    s32 sp7C;
    s32 sp78;
    char sp74[4];
    char* sp70;
    UNUSED s32 pad2;
    s32 temp_a0;
    s32 temp_a3;

    sp7C = Font_MeasureTextExtent(4, 0, "00");
    sp78 = (arg5->unk_00.unk_3C - sp7C) - 0x18;
    if (arg4 & 2) {
        sp84 = Color_ScaleRgb(D_883174B0, 1.4f);
    } else {
        sp84 = (0, D_883174B0);
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_a3 = ((sp84.r << 8) & 0xF800) | ((sp84.g << 3) & 0x7C0) | ((sp84.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a3 << 0x10) | temp_a3);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 2);

    temp_a0 = ((D_883174B4.r << 8) & 0xF800) | ((D_883174B4.g << 3) & 0x7C0) | ((D_883174B4.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_00.unk_3C + arg0) - 1, arg1);

    temp_a0 = ((D_883174B4.r << 8) & 0xF800) | ((D_883174B4.g << 3) & 0x7C0) | ((D_883174B4.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, (arg1 + arg5->unk_00.unk_3E) - 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 1);

    sprintf(sp74, "%d", arg3 + 1);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);
    Gfx_SetEnvColor(0xF0, 0xF0, 0xF0, 0xFF);
    Font_Printf(((arg0 + sp7C) - Font_MeasureTextExtent(0, 0, sp74)) + 8, arg1 + 8, sp74);
    Gfx_SetEnvColor(arg2->unk_04->unk_04.r, arg2->unk_04->unk_04.g, arg2->unk_04->unk_04.b, arg2->unk_04->unk_04.a);
    Font_SetActive(8, 0);
    sp70 = Text_GetString(NULL, 0, D_8831A4D4, arg2->unk_04->unk_00);
    Font_Printf(((sp78 - Font_MeasureTextExtent(0, 0, sp70)) / 2) + arg0 + sp7C + 0x10, arg1 + 4, sp70);
    Font_EndTexturedTextRendering();
}

void BattleInfoWidget_CenterLabel(unk_func_8830867C_03C* arg0, unk_func_8850878C* arg1, char* arg2) {
    arg1->unk_00.unk_10.unk_00 = ((arg0->unk_E0 - Font_MeasureTextExtent(8, 0, arg2)) / 2) + 6;
    arg1->unk_40 = arg2;
}

void BattleInfoWidget_BuildTypePanel(unk_func_8830867C_03C* arg0, s32 arg1, s32 arg2, WidgetNode* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_883174B8 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_883174BC = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_883174C0 = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_883174C4 = { 0xFF, 0xFF, 0x00, 0xFF };
    static s32 D_883174C8[] = { 0, 1, 2, 3, 4, 5, 7, 8, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A };

    s32 spCC;
    s32 i;
    s32 spC4;
    char* temp_v0_10;
    UNUSED s32 pad;
    unk_func_8830867C_03C* var_s1;
    unk_func_8830867C_03C* var_s1_2;
    s32 spB0;
    UNUSED s32 pad2;
    s32 temp_s1_3;
    s32 temp_v0_2;
    unk_func_885012A4* spA0;
    WidgetNode* sp98[2];
    s32 var_v1;
    s32 var_v1_2;
    unk_func_8850878C* temp_s0;
    WidgetAnimatedFrame* temp_s0_2;
    unk_func_8850BD40* temp_s0_3;
    unk_func_88503298* temp_s0_4;
    unk_func_8850B254* temp_s1;
    WidgetNode* temp_s1_4;
    WidgetGridMenu* ptr;
    unk_func_88507D4C* sp6C[2];
    WidgetNode* temp_s2_2;

    arg0->unk_E0 = Font_MeasureTextExtent(8, 0, "WWWWWWWW");
    spC4 = Font_MeasureTextExtent(4, 0, "00") + arg0->unk_E0 + 0x18;
    spB0 = 0;

    for (i = 0; i < 2; i++) {
        temp_v0_2 = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_8831A4C4, i + 0x49));
        if (spB0 < temp_v0_2) {
            spB0 = temp_v0_2;
        }
    }

    spCC = ((arg0->unk_E0 < spB0) ? spB0 : arg0->unk_E0) + spC4 + 0x30;
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_03C));

    arg0->unk_00.unk_20 = BattleInfoWidget_HandleTypePanelInput;
    arg0->unk_00.unk_24 = BattleInfoWidget_SetTypePanelState;
    // clang-format off
    arg0->unk_00.unk_10.unk_00 = arg1; arg0->unk_00.unk_10.unk_02 = arg2;
    // clang-format on

    arg0->unk_4C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_03C_04C));
    BattleInfoWidget_InitTypeSelectionProxy(arg0->unk_4C, arg0);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, spCC, 0x12C);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    temp_s1 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(temp_s1, 0, 0, spCC, 0x14, D_883174B8, D_883174BC);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, temp_s1);

    temp_s0 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(temp_s0, 8, 0, Text_GetString(NULL, 0, D_8831A4C4, 0x4B), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s1, temp_s0);

    spA0 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spA0, 0, 0x18, spCC, 0x114, D_883174C0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spA0);

    arg0->unk_50 = mem_pool_alloc(arg4, sizeof(WidgetGridMenu));
    ((func8850C284)Memmap_GetFragmentVaddr(WidgetTree_InitGridMenu))(arg0->unk_50, 4, 1, arg4);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_4C, arg0->unk_50);

    for (i = 0; i < 2; i++) {
        sp98[i] = mem_pool_alloc(arg4, sizeof(WidgetNode));
        ((func8850A40C)Memmap_GetFragmentVaddr(WidgetTree_InitBorderFrame))(sp98[i], 0xC, 0x1C + (i * 0x1C), arg0->unk_E0 + 0xC,
                                                               0x18);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spA0, sp98[i]);

        arg0->unk_50->unk_18[i * arg0->unk_50->unk_2C] = sp98[i];

        arg0->unk_30[i].unk_00 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_30[i].unk_00, 6, 2, "----", 8);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp98[i], arg0->unk_30[i].unk_00);
    }

    temp_s2_2 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func8850A40C)Memmap_GetFragmentVaddr(WidgetTree_InitBorderFrame))(temp_s2_2, 0xC, 0xC4, spB0 + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spA0, temp_s2_2);
    ptr = arg0->unk_50;
    ptr->unk_18[2] = temp_s2_2;
    temp_v0_10 = Text_GetString(NULL, 0, D_8831A4C4, 0x49);
    temp_s1_3 = Font_MeasureTextExtent(8, 0, temp_v0_10);

    arg0->unk_44 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_44, ((spB0 - temp_s1_3) / 2) + 6, 2, temp_v0_10,
                                                           8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s2_2, arg0->unk_44);

    arg0->unk_48 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func8850A40C)Memmap_GetFragmentVaddr(WidgetTree_InitBorderFrame))(arg0->unk_48, 0xC, 0xE0, spB0 + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spA0, arg0->unk_48);
    arg0->unk_50->unk_18[arg0->unk_50->unk_2C + 2] = arg0->unk_48;
    temp_v0_10 = Text_GetString(NULL, 0, D_8831A4C4, 0x4A);
    temp_s1_3 = Font_MeasureTextExtent(8, 0, temp_v0_10);

    arg0->unk_40 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_40, ((spB0 - temp_s1_3) / 2) + 6, 2, temp_v0_10,
                                                           8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_48, arg0->unk_40);
    ((func8850CAB4)Memmap_GetFragmentVaddr(WidgetTree_SelectFirstEnabledGridItem))(arg0->unk_50);

    temp_s0_2 = mem_pool_alloc(arg4, sizeof(WidgetAnimatedFrame));
    ((func88504570)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedFrameVariantC))(temp_s0_2, 0, 0, 0x10, 0x10, D_883174C4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spA0, temp_s0_2);
    arg0->unk_50->unk_1C = temp_s0_2;

    TableView_Initialize(&arg0->unk_D0, arg0->unk_58, 8, 0xF, 0xF);

    for (i = 0; i < 15; i++) {
        arg0->unk_58[i].unk_00 = D_883174C8[i];
        arg0->unk_58[i].unk_04 = ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(D_883174C8[i]);
    }

    var_v1_2 = ((arg0->unk_E0 < spB0) ? spB0 : arg0->unk_E0) + 0x24;

    temp_s1_4 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func8850AB48)Memmap_GetFragmentVaddr(WidgetTree_InitInsetBorderFrame))(temp_s1_4, var_v1_2, 0xA, spC4, 0x100);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spA0, temp_s1_4);

    arg0->unk_54 = mem_pool_alloc(arg4, sizeof(unk_func_8821421C_038_034));
    ((func88506DCC)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGrid))(arg0->unk_54, 0, 0x10, BattleInfoWidget_DrawStatusListEntry, spC4, 0x1C, 8, arg4);
    ((func88506F8C)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridStridedPage))(arg0->unk_54, &arg0->unk_D0, arg4);

    temp_s0_3 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(temp_s0_3, arg0->unk_54);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_4C, temp_s0_3);

    sp6C[0] = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp6C[0], 0, 0, spC4, 0, arg0->unk_54);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s1_4, sp6C[0]);

    sp6C[1] = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp6C[1], 0, arg0->unk_54->unk_00.unk_00.unk_14.unk_02 + 0x10,
                                                           spC4, 1, arg0->unk_54);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s1_4, sp6C[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s1_4, arg0->unk_54);

    temp_s0_4 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(temp_s0_4, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, temp_s0_4);
}

void BattleInfoWidget_SetTypeEntries(unk_func_8830867C_03C* arg0, unk_func_8830867C_02C_C54_01C* arg1) {
    static Color_RGBA8 D_88317504 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88317508 = { 0xF0, 0xF0, 0xF0, 0x4D };
    static Color_RGBA8 D_8831750C = { 0x66, 0x5B, 0x47, 0xFF };

    s32 i;
    char* var_s3;

    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_54);

    for (i = 0; i < 2; i++) {
        if (i < arg1->unk_00) {
            arg0->unk_30[i].unk_04 = arg1->unk_04[i];
            var_s3 =
                Text_GetString(NULL, 0, D_8831A4D4,
                              ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(arg0->unk_30[i].unk_04)->unk_00);
            arg0->unk_30[i].unk_00->unk_30 =
                ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(arg0->unk_30[i].unk_04)->unk_04;
            arg0->unk_30[i].unk_00->unk_44 = arg0->unk_30[i].unk_00->unk_44;
            arg0->unk_54->unk_00.unk_34[Move_NormalizeDisplayIndex(arg0->unk_30[i].unk_04)] |= 2;
        } else {
            arg0->unk_30[i].unk_04 = -1;
            var_s3 = "----";
            arg0->unk_30[i].unk_00->unk_30 = (0, D_88317504);
            arg0->unk_30[i].unk_00->unk_44 = arg0->unk_30[i].unk_00->unk_44;
        }
        BattleInfoWidget_CenterLabel(arg0, arg0->unk_30[i].unk_00, var_s3);
    }

    if (arg1->unk_00 == 0) {
        arg0->unk_48->unk_28 |= 2;
        arg0->unk_40->unk_30 = (0, D_88317508);
        arg0->unk_40->unk_44 = arg0->unk_40->unk_44;
    } else {
        arg0->unk_48->unk_28 &= ~2;
        arg0->unk_40->unk_30 = (0, D_88317504);
        arg0->unk_40->unk_44 = arg0->unk_40->unk_44;
    }
}

void BattleInfoWidget_GetTypeEntries(unk_func_8830867C_03C* arg0, unk_func_8830867C_02C_C54_01C* arg1) {
    s32 i;
    s32 var_v0 = 0;

    for (i = 0; i < 2; i++) {
        if (arg0->unk_30[i].unk_04 != -1) {
            arg1->unk_04[var_v0] = arg0->unk_30[i].unk_04;
            var_v0++;
        }
    }

    arg1->unk_00 = var_v0;
}

void BattleInfoWidget_SetTypePanelState(unk_func_8830867C_03C* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_4C->unk_00.unk_14(arg0->unk_4C, arg1);
}

s32 BattleInfoWidget_HandleTypePanelInput(unk_func_8830867C_03C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_4C->unk_00.unk_10(arg0->unk_4C, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 BattleInfoWidget_RunTypeSelectionModal(unk_func_8830867C_03C* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_v0;
    s32 var_s0 = 0;

    ((func88507AE4)Memmap_GetFragmentVaddr(WidgetTree_SetScrollableGridIndex))(arg0->unk_54, 0);
    ((func8850CB48)Memmap_GetFragmentVaddr(WidgetTree_SetGridMenuSelection))(arg0->unk_50, 0);

    arg0->unk_4C->unk_00.unk_14(arg0->unk_4C, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);

    while (var_s0 == NULL) {
        Ui_SendMessageAndPollInput(var_s0);

        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);

        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                if (arg0->unk_50->unk_24 == 2) {
                    var_v0 = 1;
                } else {
                    var_v0 = 2;
                }
                var_s0 = var_v0 + 1;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(temp_v0);
    }
    arg0->unk_2C->unk_2C = 0xB;
    return var_s0 - 1;
}

void BattleInfoWidget_InitTypeSelectionProxy(unk_func_8830867C_03C_04C* arg0, unk_func_8830867C_03C* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(WidgetTree_InitVerticalMenu))(arg0);
    arg0->unk_00.unk_10 = BattleInfoWidget_HandleTypeSelectionProxyInput;
    arg0->unk_24 = arg1;
}

s32 BattleInfoWidget_HandleTypeSelectionProxyInput(unk_func_8830867C_03C_04C* arg0, Controller* arg1) {
    s32 var_t2;
    unk_func_8830867C_03C_04C* var_a0;
    s32 i;

    var_t2 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }

        var_t2 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    if (var_t2 & 1) {
        return var_t2;
    }

    if (var_t2 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_t2 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_t2 = 0x80000004;
        }
    }

    if (var_t2 & 2) {
        if (arg0->unk_00.unk_1C == 1) {
            ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 0);
            var_t2 |= 1;
        }
    } else if (var_t2 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                switch (arg0->unk_24->unk_50->unk_24) {
                    case 2:
                    case 3:
                        break;

                    case 0:
                    case 1:
                        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                        var_t2 |= 1;
                        break;
                }
                break;

            case 1:
                if (arg0->unk_24->unk_54->unk_00.unk_34[arg0->unk_24->unk_54->unk_00.unk_38] & 2) {
                    var_t2 = (var_t2 & ~4) | 0x101;
                } else {
                    if (arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_04 != -1) {
                        arg0->unk_24->unk_54->unk_00
                            .unk_34[Move_NormalizeDisplayIndex(arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_04)] &= ~2;
                    }
                    arg0->unk_24->unk_54->unk_00.unk_34[arg0->unk_24->unk_54->unk_00.unk_38] |= 2;

                    arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_04 =
                        arg0->unk_24->unk_58[arg0->unk_24->unk_54->unk_00.unk_38].unk_00;
                    BattleInfoWidget_CenterLabel(
                        arg0->unk_24, arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_00,
                        Text_GetString(NULL, 0, D_8831A4D4,
                                      arg0->unk_24->unk_58[arg0->unk_24->unk_54->unk_00.unk_38].unk_04->unk_00));
                    arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_00->unk_30 =
                        arg0->unk_24->unk_58[arg0->unk_24->unk_54->unk_00.unk_38].unk_04->unk_04;
                    arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_00->unk_44 =
                        arg0->unk_24->unk_30[arg0->unk_24->unk_50->unk_24].unk_00->unk_44;
                    arg0->unk_24->unk_50->unk_24++;
                    ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 0);
                    var_t2 |= 1;
                }
                break;
        }
    }
    return var_t2;
}

void BattleInfoWidget_DrawTypeEntry(s32 arg0, s32 arg1, unk_func_88309C38_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_8821421C_038_034* arg5) {
    static Color_RGBA8 D_88317510 = { 0x54, 0x4B, 0x3A, 0xFF };
    static Color_RGBA8 D_88317514 = { 0x99, 0x89, 0x6A, 0xFF };

    Color_RGBA8 sp84;
    UNUSED s32 pad;
    s32 sp7C;
    s32 sp78;
    char sp74[4];
    char* sp70;
    UNUSED s32 pad2;
    s32 temp_a0;
    s32 temp_a3;

    sp7C = Font_MeasureTextExtent(4, 0, "000");
    sp78 = (arg5->unk_00.unk_3C - sp7C) - 0x18;
    if (arg4 & 2) {
        sp84 = Color_ScaleRgb(D_88317510, 1.4f);
    } else {
        sp84 = (0, D_88317510);
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_a3 = ((sp84.r << 8) & 0xF800) | ((sp84.g << 3) & 0x7C0) | ((sp84.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a3 << 0x10) | temp_a3);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 2);

    temp_a0 = ((D_88317514.r << 8) & 0xF800) | ((D_88317514.g << 3) & 0x7C0) | ((D_88317514.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_00.unk_3C + arg0) - 1, arg1);

    temp_a0 = ((D_88317514.r << 8) & 0xF800) | ((D_88317514.g << 3) & 0x7C0) | ((D_88317514.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, (arg1 + arg5->unk_00.unk_3E) - 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 1);

    sprintf(sp74, "%d", arg3 + 1);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);
    Gfx_SetEnvColor(0xF0, 0xF0, 0xF0, 0xFF);
    Font_Printf(((arg0 + sp7C) - Font_MeasureTextExtent(0, 0, sp74)) + 8, arg1 + 8, sp74);

    sp84 = (((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(arg2->unk_01))->unk_04;
    Gfx_SetEnvColor(sp84.r, sp84.g, sp84.b, sp84.a);
    Font_SetActive(8, 0);

    sp70 = Text_GetString(NULL, 0, D_8831A4CC, arg2->unk_00 - 1);
    Font_Printf(((sp78 - Font_MeasureTextExtent(0, 0, sp70)) / 2) + arg0 + sp7C + 0x10, arg1 + 4, sp70);
    Font_EndTexturedTextRendering();
}

void func_8830FA10(void) {
}

void func_8830FA18(void) {
}

void BattleInfoWidget_CenterTypeLabel(unk_func_8830867C_040* arg0, unk_func_8850878C* arg1, char* arg2) {
    arg1->unk_00.unk_10.unk_00 = ((arg0->unk_74 - Font_MeasureTextExtent(8, 0, arg2)) / 2) + 6;
    arg1->unk_40 = arg2;
}

void BattleInfoWidget_BuildMovePanel(unk_func_8830867C_040* arg0, s32 arg1, s32 arg2, WidgetNode* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88317518 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_8831751C = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317520 = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_88317524 = { 0xFF, 0xFF, 0x00, 0xFF };

    s32 spCC;
    s32 i;
    s32 spC4;
    unk_func_8850878C* temp_s0;
    WidgetAnimatedFrame* temp_s0_2;
    unk_func_8850BD40* temp_s0_3;
    unk_func_88503298* temp_s0_4;
    s32 spB0;
    s32 temp_s1_2;
    s32 temp_s1_3;
    s32 temp_v0_2;
    unk_func_885012A4* spA0;
    WidgetNode* sp90[4];
    WidgetGridMenu* ptr;
    s32 var_v1_2;
    char* temp_v0_10;
    UNUSED s32 pad[2];
    unk_func_8850B254* temp_s1;
    WidgetNode* temp_s1_4;
    WidgetNode* temp_s2_2;
    unk_func_88507D4C* sp68[2];
    s32* temp_s2_3;

    arg0->unk_74 = Font_MeasureTextExtent(8, 0, "WWWWWWWWWWWW");
    spC4 = Font_MeasureTextExtent(4, 0, "000") + arg0->unk_74 + 0x18;
    spB0 = 0;

    for (i = 0; i < 2; i++) {
        temp_v0_2 = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_8831A4C4, i + 0x49));
        if (spB0 < temp_v0_2) {
            spB0 = temp_v0_2;
        }
    }

    spCC = ((arg0->unk_74 < spB0) ? spB0 : arg0->unk_74) + spC4 + 0x30;
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_040));

    arg0->unk_00.unk_20 = BattleInfoWidget_HandleMovePanelInput;
    arg0->unk_00.unk_24 = BattleInfoWidget_SetMovePanelState;
    // clang-format off
    arg0->unk_00.unk_10.unk_00 = arg1; arg0->unk_00.unk_10.unk_02 = arg2;
    // clang-format on

    arg0->unk_5C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_040_05C));
    BattleInfoWidget_InitMoveSelectionProxy(arg0->unk_5C, arg0);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, spCC, 0x12C);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    temp_s1 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(temp_s1, 0, 0, spCC, 0x14, D_88317518, D_8831751C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, temp_s1);

    temp_s0 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(temp_s0, 8, 0, Text_GetString(NULL, 0, D_8831A4C4, 0x4C), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s1, temp_s0);

    spA0 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spA0, 0, 0x18, spCC, 0x114, D_88317520);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spA0);

    arg0->unk_60 = mem_pool_alloc(arg4, sizeof(WidgetGridMenu));
    ((func8850C284)Memmap_GetFragmentVaddr(WidgetTree_InitGridMenu))(arg0->unk_60, 6, 1, arg4);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_5C, arg0->unk_60);

    for (i = 0; i < 4; i++) {
        sp90[i] = mem_pool_alloc(arg4, sizeof(WidgetNode));
        ((func8850A40C)Memmap_GetFragmentVaddr(WidgetTree_InitBorderFrame))(sp90[i], 0xC, (i + 1) * 0x1C, arg0->unk_74 + 0xC, 0x18);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spA0, sp90[i]);
        arg0->unk_60->unk_18[i * arg0->unk_60->unk_2C] = sp90[i];

        arg0->unk_30[i].unk_00 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_30[i].unk_00, 6, 2, "-------", 8);
        ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp90[i], arg0->unk_30[i].unk_00);
    }

    temp_s2_2 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func8850A40C)Memmap_GetFragmentVaddr(WidgetTree_InitBorderFrame))(temp_s2_2, 0xC, 0xC4, spB0 + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spA0, temp_s2_2);
    ptr = arg0->unk_60;
    ptr->unk_18[4] = temp_s2_2;
    temp_v0_10 = Text_GetString(NULL, 0, D_8831A4C4, 0x49);
    temp_s1_3 = Font_MeasureTextExtent(8, 0, temp_v0_10);

    arg0->unk_54 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_54, ((spB0 - temp_s1_3) / 2) + 6, 2, temp_v0_10,
                                                           8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s2_2, arg0->unk_54);

    arg0->unk_58 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func8850A40C)Memmap_GetFragmentVaddr(WidgetTree_InitBorderFrame))(arg0->unk_58, 0xC, 0xE0, spB0 + 0xC, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spA0, arg0->unk_58);
    arg0->unk_60->unk_18[arg0->unk_60->unk_2C + 4] = arg0->unk_58;
    temp_v0_10 = Text_GetString(NULL, 0, D_8831A4C4, 0x4A);
    temp_s1_3 = Font_MeasureTextExtent(8, 0, temp_v0_10);

    arg0->unk_50 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_50, ((spB0 - temp_s1_3) / 2) + 6, 2, temp_v0_10,
                                                           8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_58, arg0->unk_50);
    ((func8850CAB4)Memmap_GetFragmentVaddr(WidgetTree_SelectFirstEnabledGridItem))(arg0->unk_60);

    temp_s0_2 = mem_pool_alloc(arg4, sizeof(WidgetAnimatedFrame));
    ((func88504570)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedFrameVariantC))(temp_s0_2, 0, 0, 0x10, 0x10, D_88317524);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spA0, temp_s0_2);
    arg0->unk_60->unk_1C = temp_s0_2;

    temp_s2_3 = mem_pool_alloc(arg4, sizeof(s32) * 0xA4);

    for (i = 0; i < 0xA4; i++) {
        temp_s2_3[D_88317360[i]] = Move_GetDisplayInfo(i + 1);
    }

    PointerList_Initialize(&arg0->unk_68, temp_s2_3, 0xA4, 0xA4);

    var_v1_2 = ((arg0->unk_74 < spB0) ? spB0 : arg0->unk_74) + 0x24;

    temp_s1_4 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func8850AB48)Memmap_GetFragmentVaddr(WidgetTree_InitInsetBorderFrame))(temp_s1_4, var_v1_2, 0xA, spC4, 0x100);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spA0, temp_s1_4);

    arg0->unk_64 = mem_pool_alloc(arg4, sizeof(unk_func_8821421C_038_034));
    ((func88506DCC)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGrid))(arg0->unk_64, 0, 0x10, BattleInfoWidget_DrawTypeEntry, spC4, 0x1C, 8, arg4);
    ((func88506F1C)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridPage))(arg0->unk_64, &arg0->unk_68, arg4);

    temp_s0_3 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(temp_s0_3, arg0->unk_64);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_5C, temp_s0_3);

    sp68[0] = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp68[0], 0, 0, spC4, 0, arg0->unk_64);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s1_4, sp68[0]);

    sp68[1] = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp68[1], 0, arg0->unk_64->unk_00.unk_00.unk_14.unk_02 + 0x10,
                                                           spC4, 1, arg0->unk_64);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s1_4, sp68[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(temp_s1_4, arg0->unk_64);

    temp_s0_4 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(temp_s0_4, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, temp_s0_4);
}

void BattleInfoWidget_SetMoveSlots(unk_func_8830867C_040* arg0, unk_func_8830867C_02C_C54_024* arg1) {
    static Color_RGBA8 D_88317528 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_8831752C = { 0xF0, 0xF0, 0xF0, 0x4D };

    s32 i;
    char* var_s1;
    ret_func_8002ED08* temp_v0;

    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_64);

    for (i = 0; i < 4; i++) {
        if (i < arg1->unk_04) {
            temp_v0 = Move_GetDisplayInfo(arg1->unk_00[i]);
            arg0->unk_30[i].unk_04 = temp_v0;
            var_s1 = Text_GetString(NULL, 0, D_8831A4CC, temp_v0->unk_00[0] - 1);
            arg0->unk_30[i].unk_00->unk_30 =
                (((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(arg0->unk_30[i].unk_04[1]))->unk_04;
            arg0->unk_30[i].unk_00->unk_44 = arg0->unk_30[i].unk_00->unk_44;
            arg0->unk_64->unk_00.unk_34[D_88317360[arg0->unk_30[i].unk_04[0] - 1]] |= 2;
        } else {
            arg0->unk_30[i].unk_04 = NULL;
            var_s1 = "-------";
            arg0->unk_30[i].unk_00->unk_30 = (0, D_88317528);
            arg0->unk_30[i].unk_00->unk_44 = arg0->unk_30[i].unk_00->unk_44;
        }
        BattleInfoWidget_CenterTypeLabel(arg0, arg0->unk_30[i].unk_00, var_s1);
    }

    if (arg1->unk_04 == 0) {
        arg0->unk_58->unk_28 |= 2;
        arg0->unk_50->unk_30 = (0, D_8831752C);
        arg0->unk_50->unk_44 = arg0->unk_50->unk_44;
    } else {
        arg0->unk_58->unk_28 &= ~2;
        arg0->unk_50->unk_30 = (0, D_88317528);
        arg0->unk_50->unk_44 = arg0->unk_50->unk_44;
    }
}

void BattleInfoWidget_GetMoveSlots(unk_func_8830867C_040* arg0, unk_func_8830867C_02C_C54_024* arg1) {
    s32 var_v0 = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (arg0->unk_30[i].unk_04 != NULL) {
            arg1->unk_00[var_v0++] = arg0->unk_30[i].unk_04[0];
        }
    }

    arg1->unk_04 = var_v0;
}

void BattleInfoWidget_SetMovePanelState(unk_func_8830867C_040* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_5C->unk_00.unk_14(arg0->unk_5C, arg1);
}

s32 BattleInfoWidget_HandleMovePanelInput(unk_func_8830867C_040* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_5C->unk_00.unk_10(arg0->unk_5C, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 BattleInfoWidget_RunMovePanelModal(unk_func_8830867C_040* arg0, Controller* arg1) {
    s32 i;
    s32 temp_v0;
    s32 var_v0;
    s32 var_s0 = 0;

    ((func88507AE4)Memmap_GetFragmentVaddr(WidgetTree_SetScrollableGridIndex))(arg0->unk_64, 0);
    ((func8850CB48)Memmap_GetFragmentVaddr(WidgetTree_SetGridMenuSelection))(arg0->unk_60, 0);
    arg0->unk_5C->unk_00.unk_14(arg0->unk_5C, 1);
    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);

    while (var_s0 == 0) {
        Ui_SendMessageAndPollInput(var_s0);
        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);

        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                if (arg0->unk_60->unk_24 == 4) {
                    var_v0 = 1;
                } else {
                    var_v0 = 2;
                }
                var_s0 = var_v0 + 1;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(temp_v0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s0 - 1;
}

void BattleInfoWidget_InitMoveSelectionProxy(unk_func_8830867C_040_05C* arg0, unk_func_8830867C_040* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(WidgetTree_InitVerticalMenu))(arg0);
    arg0->unk_00.unk_10 = func_88310854;
    arg0->unk_24 = arg1;
}

s32 func_88310854(unk_func_8830867C_040_05C* arg0, Controller* arg1) {
    s32 var_t2;
    s32 i;
    unk_func_8830867C_040_05C* var_a0;
    unk_func_88205880_A030* ptr;
    u8* ptr2;

    var_t2 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;

        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }

        var_t2 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    if (var_t2 & 1) {
        return var_t2;
    }

    if (var_t2 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_t2 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_t2 = 0x80000004;
        }
    }

    if (var_t2 & 2) {
        if (arg0->unk_00.unk_1C == 1) {
            ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 0);
            var_t2 |= 1;
        }
    } else if (var_t2 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                switch (arg0->unk_24->unk_60->unk_24) {
                    case 4:
                    case 5:
                        break;

                    case 0:
                    case 1:
                    case 2:
                    case 3:
                        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                        var_t2 |= 1;
                        break;
                }
                break;

            case 1:
                if (arg0->unk_24->unk_64->unk_00.unk_34[arg0->unk_24->unk_64->unk_00.unk_38] & 2) {
                    var_t2 = (var_t2 & ~4) | 0x101;
                } else {
                    if (arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_04 != NULL) {
                        arg0->unk_24->unk_64->unk_00
                            .unk_34[D_88317360[arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_04[0] - 1]] &= ~2;
                    }
                    arg0->unk_24->unk_64->unk_00.unk_34[arg0->unk_24->unk_64->unk_00.unk_38] |= 2;

                    ptr2 = ((unk_func_88205880_A030*)arg0->unk_24->unk_64->unk_00.unk_2C)->unk_00[arg0->unk_24->unk_64->unk_00.unk_38];
                    arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_04 = ptr2;

                    BattleInfoWidget_CenterTypeLabel(arg0->unk_24, arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_00,
                                  Text_GetString(NULL, 0, D_8831A4CC, ptr2[0] - 1));

                    arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_00->unk_30 =
                        ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(ptr2[1])->unk_04;
                    arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_00->unk_44 =
                        arg0->unk_24->unk_30[arg0->unk_24->unk_60->unk_24].unk_00->unk_44;

                    arg0->unk_24->unk_60->unk_24++;
                    ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 0);
                    var_t2 |= 1;
                }
                break;
        }
    }
    return var_t2;
}

void BattleInfoWidget_InitGamePakSlotLabel(unk_func_88310B70* arg0, s32 arg1, s32 arg2, unk_func_8830867C_04C_030* arg3, MemoryPool* arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_88310B70));

    arg0->unk_00.unk_1C = BattleInfoWidget_DrawGamePakSlotLabel;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(arg0->unk_30, 0, 0, 0, 8);
    arg0->unk_30->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_30);

    arg0->unk_2C = arg3;
}

s32 BattleInfoWidget_DrawGamePakSlotLabel(unk_func_88310B70* arg0) {
    arg0->unk_30->unk_40 =
        Text_GetString(NULL, 0, D_8831A4C8, **(u8**)arg0->unk_2C->unk_2C->unk_00[arg0->unk_2C->unk_38].unk_00[0] - 1);
    return 0;
}

void BattleInfoWidget_DrawItemGridCell(s32 arg0, s32 arg1, unk_func_88310CA4_arg2* a2, s32 arg3, s32 arg4,
                   unk_func_8830867C_04C_030* arg5) {
    static Color_RGBA8 D_88317530[2] = {
        { 0x80, 0x79, 0x6C, 0xFF },
        { 0x67, 0x60, 0x53, 0xFF },
    };
    static Color_RGBA8 D_88317538 = { 0x99, 0x91, 0x81, 0xFF };
    static Color_RGBA8 D_8831753C = { 0xB4, 0x82, 0xDC, 0xFF };
    static Color_RGBA8 D_88317540[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF },
        { 0xF0, 0xF0, 0xF0, 0x4D },
    };

    Color_RGBA8 sp8C;
    unk_func_88310CA4_arg2* arg2 = a2;
    char* sp84;
    s32 temp_a0;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t2 = ((D_88317530[0].r << 8) & 0xF800) | ((D_88317530[0].g << 3) & 0x7C0) | ((D_88317530[0].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on
    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, arg0 + 0x105, (arg1 + arg5->unk_00.unk_14.unk_02) - 4);

    temp_a0 =
        ((D_88317530[1].r << 8) & 0xF800) | ((D_88317530[1].g << 3) & 0x7C0) | ((D_88317530[1].b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0 + 0x106, arg1 + 1, (arg0 + (u32)arg5->unk_00.unk_14.unk_00) - 1,
                     (arg1 + arg5->unk_00.unk_14.unk_02) - 2);

    temp_a0 = ((D_88317538.r << 8) & 0xF800) | ((D_88317538.g << 3) & 0x7C0) | ((D_88317538.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_00.unk_14.unk_00 + arg0) - 1, arg1);

    temp_a0 = ((D_88317538.r << 8) & 0xF800) | ((D_88317538.g << 3) & 0x7C0) | ((D_88317538.b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_a0 << 0x10) | temp_a0);
    gDPFillRectangle(gDisplayListHead++, arg0, (arg1 + arg5->unk_00.unk_14.unk_02) - 1,
                     (arg5->unk_00.unk_14.unk_00 + arg0) - 1, (arg1 + arg5->unk_00.unk_14.unk_02) - 1);

    if (arg2 != NULL) {
        char sp30[0x10];

        sp8C = D_88317540[(arg4 & 4) ? 1 : 0];

        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(sp8C.r, sp8C.g, sp8C.b, sp8C.a);
        Font_SetActive(8, 0);
        Font_Printf(arg0 + 0x19, arg1 + 4, Text_GetString(NULL, 0, D_8831A4D8, arg2->unk_00[0] - 1));

        if (arg2->unk_04[0] == 0x12) {
            sp84 = Text_GetString(NULL, 0, D_8831A4C4, 0x51);
            Font_SetActive(8, 0);
            Font_Printf((((arg5->unk_00.unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp84)) - 0x106) / 2) + arg0 + 0x106,
                          arg1 + 4, sp84);
        } else if (arg2->unk_04[0] == 0x22) {
            sp84 = Text_GetString(NULL, 0, D_8831A4C4, 0x50);
            Font_SetActive(8, 0);
            Font_Printf((((arg5->unk_00.unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp84)) - 0x106) / 2) + arg0 + 0x106,
                          arg1 + 4, sp84);
        } else {
            sp84 = Text_GetString(NULL, 0, D_8831A4C4, 0x4F);
            Font_SetActive(8, 0);
            Font_Printf((((arg5->unk_00.unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp84)) - 0x106) / 2) + arg0 + 0x106,
                          arg1 + 4, sp84);
        }

        if (LabItem_IsQuantitylessItemForOperation(arg2->unk_00[0]) == 0) {
            Font_SetActive(8, 0);
            sprintf(sp30, "%s%02d", Text_GetString(NULL, 0, D_8831A4C4, 0x64), arg2->unk_00[1]);
            Font_Printf((arg0 - Font_MeasureTextExtent(0, 0, sp30)) + 0xED, arg1 + 4, sp30);
        }
        Font_EndTexturedTextRendering();
    }
}

void BattleInfoWidget_BuildItemMenu(unk_func_8830867C_04C* arg0, s32 arg1, s32 arg2, WidgetNode* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88317548 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_8831754C = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317550 = { 0x43, 0x35, 0x1C, 0xFF };
    static Color_RGBA8 D_88317554 = { 0xFF, 0xFF, 0xFF, 0xFF };
    static Color_RGBA8 D_88317558 = { 0x14, 0xF0, 0xB4, 0xFF };
    static Color_RGBA8 D_8831755C = { 0x71, 0xE9, 0xF9, 0xFF };
    static Color_RGBA8 D_88317560 = { 0x3C, 0x7B, 0x84, 0xFF };
    static Color_RGBA8 D_88317564 = { 0x93, 0xFA, 0x71, 0xFF };
    static Color_RGBA8 D_88317568 = { 0x51, 0x89, 0x3E, 0xFF };
    static Color_RGBA8 D_8831756C = { 0xFE, 0x73, 0xFE, 0xFF };
    static Color_RGBA8 D_88317570 = { 0x97, 0x44, 0x97, 0xFF };
    static Color_RGBA8 D_88317574 = { 0xFF, 0x73, 0x73, 0xFF };
    static Color_RGBA8 D_88317578 = { 0x83, 0x3B, 0x3B, 0xFF };

    UNUSED s32 pad[3];
    unk_func_8850B254* sp88;
    unk_func_8850878C* sp84;
    unk_func_88507D4C* sp80;
    unk_func_88507D4C* sp7C;
    unk_func_8850BD40* sp78;
    unk_func_885012A4* sp74;
    unk_func_8850878C* sp70;
    unk_func_8850878C* sp6C;
    unk_func_8850878C* sp68;
    unk_func_8850878C* sp64;
    unk_func_8850878C* sp60;
    unk_func_88310B70* sp5C;
    unk_func_8850BD40* sp58;
    unk_func_8850BD40* sp54;
    char** sp50;
    unk_func_8850BD40* sp4C;

    BattleInfoWidget_SetItemMenuMon(arg0, NULL);
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_04C));

    arg0->unk_00.unk_20 = BattleInfoWidget_ItemMenuHandleContainerInput;
    arg0->unk_00.unk_24 = BattleInfoWidget_SetItemMenuState;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_80 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_04C_080));
    BattleInfoWidget_InitItemMenuSelectionProxy(arg0->unk_80, arg0);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_04C_02C));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, 0x166, 0x118);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    sp88 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(sp88, 0, 0, 0x166, 0x14, D_88317548, D_8831754C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp88);
    arg0->unk_38[0] = '\0';

    sp84 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp84, 8, 0, arg0->unk_38, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp88, sp84);

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_04C_030));
    ((func88506DCC)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGrid))(arg0->unk_30, 0, 0x28, BattleInfoWidget_DrawItemGridCell, 0x166, 0x1C, 5, arg4);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_30, 0xAA, arg4);

    sp7C = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp7C, 0, 0x18, arg0->unk_30->unk_00.unk_14.unk_00, 0,
                                                           arg0->unk_30);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp7C);

    sp80 = mem_pool_alloc(arg4, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridScrollbar))(sp80, 0, arg0->unk_30->unk_00.unk_14.unk_02 + 0x28,
                                                           arg0->unk_30->unk_00.unk_14.unk_00, 1, arg0->unk_30);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp80);

    sp78 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(sp78, arg0->unk_30);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_80, sp78);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, arg0->unk_30);

    sp74 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp74, 0, 0xC4, 0x166, 0x54, D_88317550);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp74);

    arg0->unk_34 = mem_pool_alloc(arg4, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_34, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp74, arg0->unk_34);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp70, 0x12, 8, Text_GetString(NULL, 0, D_8831A4C4, 0x52), 8);
    sp70->unk_30 = (0, D_88317554);
    sp70->unk_44 = sp70->unk_44;
    sp70->unk_34 = (0, D_88317558);
    sp70->unk_44 = 1;
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_34, sp70);

    sp6C = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp6C, 0x17, 8, Text_GetString(NULL, 0, D_8831A4C4, 0x53), 8);
    sp6C->unk_30 = (0, D_8831755C);
    sp6C->unk_44 = sp6C->unk_44;
    sp6C->unk_34 = (0, D_88317560);
    sp6C->unk_44 = 1;
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_34, sp6C);

    sp68 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp68, 0x1C, 8, Text_GetString(NULL, 0, D_8831A4C4, 0x54), 8);
    sp68->unk_30 = (0, D_88317564);
    sp68->unk_44 = sp68->unk_44;
    sp68->unk_34 = (0, D_88317568);
    sp68->unk_44 = 1;
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_34, sp68);

    sp64 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp64, 0x21, 8, Text_GetString(NULL, 0, D_8831A4C4, 0x55), 8);
    sp64->unk_30 = (0, D_8831756C);
    sp64->unk_44 = sp64->unk_44;
    sp64->unk_34 = (0, D_88317570);
    sp64->unk_44 = 1;
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_34, sp64);

    sp60 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp60, 0x26, 8, Text_GetString(NULL, 0, D_8831A4C4, 0x56), 8);
    sp60->unk_30 = (0, D_88317574);
    sp60->unk_44 = sp60->unk_44;
    sp60->unk_34 = (0, D_88317578);
    sp60->unk_44 = 1;
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_34, sp60);

    sp5C = mem_pool_alloc(arg4, sizeof(unk_func_88310B70));
    BattleInfoWidget_InitGamePakSlotLabel(sp5C, 8, 0x20, arg0->unk_30, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp74, sp5C);

    sp58 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(sp58, arg0->unk_34);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_80, sp58);

    arg0->unk_78 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_04C_078));
    BattleMoveListWidget_Initialize(arg0->unk_78, 0x35, arg0->unk_2C->unk_00.unk_14.unk_00, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_78);

    sp54 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(sp54, arg0->unk_78);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_80, sp54);

    sp50 = mem_pool_alloc(arg4, sizeof(char*) * 2);
    sp50[0] = Text_GetString(NULL, 0, D_8831A4C4, 0x57);
    sp50[1] = Text_GetString(NULL, 0, D_8831A4C4, 0x58);

    arg0->unk_7C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_030));
    BattleInfoWidget_InitDropdownMenu(arg0->unk_7C, NULL, arg4);
    arg0->unk_7C->unk_4C = 0x280;
    arg0->unk_7C->unk_50 = 0x1E0;
    BattleInfoWidget_SetLabels(arg0->unk_7C, sp50, 1);
    arg0->unk_7C->unk_30.unk_00 = arg0->unk_2C->unk_00.unk_14.unk_00 - 0x57;
    arg0->unk_7C->unk_30.unk_02 = 0xB4;
    arg0->unk_7C->unk_34.unk_00 = 0x20;
    arg0->unk_7C->unk_34.unk_02 = 0x10;
    BattleInfoWidget_UpdateViewport(arg0->unk_7C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_7C);

    sp4C = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(sp4C, arg0->unk_7C);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_80, sp4C);

    arg0->unk_90 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(arg0->unk_90, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_90);
}

s32 LabPCList_CanLearnMoveByLevelUp(s32 arg0, s32 arg1) {
    static SpeciesData D_8831757C[] = {
        { 0x06, 0x4E, 0x54, 0x4E, 0x64, 0x55, 0x14, 0x02, 0x2D, 0xD1, {0x0A, 0x2D, 0x34, 0x2B}, 0x03, {0xB5, 0x43, 0x4F, 0xCE, 0xE3, 0x08, 0x2E}, 0x00 },
        { 0x0C, 0x3C, 0x2D, 0x32, 0x46, 0x50, 0x07, 0x02, 0x2D, 0xA0, {0x5D, 0x00, 0x00, 0x00}, 0x00, {0x2A, 0x43, 0x38, 0xF0, 0x43, 0x28, 0x42}, 0x00 },
        { 0x30, 0x3C, 0x37, 0x32, 0x2D, 0x28, 0x07, 0x03, 0xBE, 0x4B, {0x21, 0x32, 0x00, 0x00}, 0x00, {0x20, 0x03, 0x38, 0xD0, 0x03, 0x28, 0x42}, 0x00 },
        { 0x31, 0x46, 0x41, 0x3C, 0x5A, 0x5A, 0x07, 0x03, 0x4B, 0x8A, {0x21, 0x32, 0x4D, 0x8D}, 0x00, {0x2A, 0x43, 0x38, 0xF0, 0x43, 0x28, 0x42}, 0x00 },
        { 0x32, 0x0A, 0x37, 0x19, 0x5F, 0x2D, 0x04, 0x04, 0xFF, 0x51, {0x0A, 0x00, 0x00, 0x00}, 0x00, {0xA0, 0x03, 0x08, 0xCE, 0x02, 0x88, 0x06}, 0x00 },
        { 0x33, 0x23, 0x50, 0x32, 0x78, 0x46, 0x04, 0x04, 0x32, 0x99, {0x0A, 0x2D, 0x5B, 0x00}, 0x00, {0xA0, 0x43, 0x08, 0xCE, 0x02, 0x88, 0x06}, 0x00 },
        { 0x8D, 0x3C, 0x73, 0x69, 0x50, 0x46, 0x05, 0x15, 0x2D, 0xC9, {0x0A, 0x6A, 0x47, 0x00}, 0x00, {0xB6, 0x7F, 0x0D, 0xC0, 0x83, 0x08, 0x16}, 0x00 },
        { 0x96, 0x6A, 0x6E, 0x5A, 0x82, 0x9A, 0x18, 0x18, 0x03, 0xDC, {0x5D, 0x32, 0x81, 0x5E}, 0x05, {0xB1, 0x7F, 0xAF, 0xF1, 0xAF, 0x38, 0x63}, 0x00 },
        { 0x97, 0x64, 0x64, 0x64, 0x64, 0x64, 0x18, 0x18, 0x2D, 0x40, {0x01, 0x00, 0x00, 0x00}, 0x03, {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F}, 0x00 },
    };

    SpeciesData* var_v1;
    s32 i;

    var_v1 = &gSpeciesData[arg0 - 1];

    if (GbSave_GetPortGame(GbSave_GetActivePort()) == 7) {
        for (i = 0; i < 9; i++) {
            if (arg0 == D_8831757C[i].speciesId) {
                var_v1 = &D_8831757C[i];
            }
        }
    }
    return ((var_v1->tmHmLearnset[arg1 / 8] >> (arg1 % 8)) & 1) != 0;
}

s32 LabPCList_CheckTmHmIneligibility(s32 arg0, unk_func_8830867C_02C_0CC_000_008* arg1) {
    s32 i;
    s32 temp_v0;
    s32 var_s3;
    s32 var_s4;

    if (arg0 >= 0xC9) {
        var_s3 = arg0 - 0xC9;
    } else {
        var_s3 = arg0 - 0x92;
    }

    temp_v0 = BattleMon_CountMoves(arg1);
    var_s4 = 0;
    for (i = 0; i < temp_v0; i++) {
        if (Move_GetIdFromTableIndex(var_s3) == arg1->unk_09[i]) {
            break;
        }
    }

    if (i < temp_v0) {
        var_s4 = 8;
    }

    if (LabPCList_CanLearnMoveByLevelUp(arg1->unk_00, var_s3) == 0) {
        var_s4 |= 0x10;
    }
    return var_s4;
}

s32 LabPCList_CheckPpUpIneligibility(unk_func_8830867C_02C_0CC_000_008* arg0) {
    s32 sp2C = 0;
    s32 temp_v0 = BattleMon_CountMoves(arg0);
    s32 i;

    for (i = 0; i < temp_v0; i++) {
        if ((Move_GetDisplayInfo(arg0->unk_09[i]) != NULL) && (arg0->unk_20[i] < 0xC0)) {
            break;
        }
    }

    if (i >= temp_v0) {
        sp2C = 4;
    }

    return sp2C;
}

s32 LabPCList_CheckVitaminIneligibility(s32 arg0, unk_func_8830867C_02C_0CC_000_008* arg1) {
    s32 var_v1 = 0;

    switch (arg0) {
        case 35:
            if (arg1->unk_14 >= 0x6400) {
                var_v1 = 1;
            }
            break;

        case 36:
            if (arg1->unk_16 >= 0x6400) {
                var_v1 = 1;
            }
            break;

        case 37:
            if (arg1->unk_18 >= 0x6400) {
                var_v1 = 1;
            }
            break;

        case 38:
            if (arg1->unk_1A >= 0x6400) {
                var_v1 = 1;
            }
            break;

        case 39:
            if (arg1->unk_1C >= 0x6400) {
                var_v1 = 1;
            }
            break;

        case 40:
            if (arg1->unk_24 >= 0x64) {
                var_v1 = 2;
            }
            break;
    }
    return var_v1;
}

void BattleInfoWidget_RebindItemGrid(unk_func_8830867C_04C* arg0, unk_func_88200FA0_030_038* arg1) {
    s32 sp1C;
    s32 sp18;

    sp18 = arg0->unk_30->unk_38;
    sp1C = sp18 - (arg0->unk_30->unk_58 / arg0->unk_30->unk_3E);

    ((func88506EE4)Memmap_GetFragmentVaddr(WidgetTree_BindScrollableGridData))(arg0->unk_30, arg1);
    ((func88507C0C)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelectionWithOffset))(arg0->unk_30, sp18, sp1C);
}

void BattleInfoWidget_SetItemMenuMon(unk_func_8830867C_04C* arg0, BattleMon* arg1) {
    arg0->unk_88 = arg1;
}

void BattleInfoWidget_MarkIneligibleItems(unk_func_8830867C_04C* arg0) {
    s32 i;
    s32 var_v0;
    unk_func_8830867C_04C_030_02C_000* var_s2 = arg0->unk_30->unk_2C->unk_00;

    for (i = 0; i < arg0->unk_30->unk_2C->unk_08; i++) {
        if (var_s2->unk_00[i]->unk_08 >= 0x64) {
            var_v0 = LabPCList_CheckTmHmIneligibility(**(u8**)&var_s2->unk_00[i]->unk_00, arg0->unk_88);
        } else if (var_s2->unk_00[i]->unk_08 >= 0x32) {
            var_v0 = LabPCList_CheckPpUpIneligibility(arg0->unk_88);
        } else {
            var_v0 = LabPCList_CheckVitaminIneligibility(**(u8**)&var_s2->unk_00[i]->unk_00, arg0->unk_88);
        }

        if (var_v0 != 0) {
            arg0->unk_30->unk_34[i] |= 4;
        }
    }
}

void BattleInfoWidget_UpdateItemMenuTitle(unk_func_8830867C_04C* arg0) {
    u32 sp1C;

    if (arg0->unk_88 != NULL) {
        sp1C = 0x4D;
        Text_SetStringToken(0x19, Text_GetString(NULL, 0, D_8831A4D0, arg0->unk_88->unk_00.unk_00 - 1));
    } else {
        sp1C = 0x4E;
    }
    Text_GetString(arg0->unk_38, 0x40, D_8831A4C4, sp1C);
}

void BattleInfoWidget_SetItemMenuMode(unk_func_8830867C_04C* arg0, s32 arg1) {
    arg0->unk_8C = arg1;

    if (arg1 != 0) {
        arg0->unk_90->unk_00.unk_28 &= ~1;
    } else {
        arg0->unk_90->unk_00.unk_28 |= 1;
    }

    BattleInfoWidget_UpdateItemMenuTitle(arg0);

    if (arg1 == 0) {
        BattleInfoWidget_MarkIneligibleItems(arg0);
    }
}

void BattleInfoWidget_SetItemMenuState(unk_func_8830867C_04C* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_80->unk_00.unk_14(arg0->unk_80, arg1);
}

s32 BattleInfoWidget_GetItemMenuActionType(unk_func_8830867C_04C* arg0, s32* arg1) {
    s32 sp1C = 0;
    unk_func_8830867C_04C_030_02C_000_000* ptr = arg0->unk_30->unk_2C->unk_00[arg0->unk_30->unk_38].unk_00[0];

    if (ptr->unk_08 >= 0x64) {
        sp1C = 0;
        if (BattleMon_CountMoves(arg1) >= 4) {
            sp1C = 2;
        }
    } else if (ptr->unk_08 >= 0x32) {
        sp1C = 1;
    }
    return sp1C;
}

void BattleInfoWidget_InitItemMenuSelectionProxy(unk_func_8830867C_04C_080* arg0, unk_func_8830867C_04C* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(WidgetTree_InitVerticalMenu))(arg0);
    arg0->unk_00.unk_10 = BattleInfoWidget_ItemMenuHandleInput;
    arg0->unk_24 = arg1;
}

s32 BattleInfoWidget_ItemMenuBackToBrowse(unk_func_8830867C_04C_080* arg0) {
    s32 sp24 = 0;

    if (arg0->unk_24->unk_8C != 0) {
        BattleInfoWidget_SetItemMenuMon(arg0->unk_24, NULL);
        ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_24->unk_34, 1);
        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
        sp24 = 1;
    } else {
        ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_24->unk_34, 0);
        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 0);
    }
    return sp24;
}

s32 BattleInfoWidget_ItemMenuBackFromMoveSelect(unk_func_8830867C_04C_080* arg0) {
    s32 sp24 = 0;

    switch (arg0->unk_24->unk_84) {
        case 0:
            sp24 = BattleInfoWidget_ItemMenuBackToBrowse(arg0);
            break;

        case 1:
            ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 2);
            ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_24->unk_34, 2);
            break;

        case 2:
            ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 2);
            ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_24->unk_34, 3);
            break;
    }

    BattleInfoWidget_CloseSelection(arg0->unk_24->unk_7C);
    return sp24;
}

void BattleInfoWidget_ItemMenuConfirmSelection(unk_func_8830867C_04C_080* arg0) {
    arg0->unk_24->unk_84 = BattleInfoWidget_GetItemMenuActionType(arg0->unk_24, arg0->unk_24->unk_88);
    if (arg0->unk_24->unk_84 > 0) {
        BattleMoveListWidget_SetMoves(arg0->unk_24->unk_78, arg0->unk_24->unk_88);
        if (arg0->unk_24->unk_84 == 1) {
            BattleMoveListWidget_DisableUnavailableMoves(arg0->unk_24->unk_78);
            ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_24->unk_34, 2);
        } else if (arg0->unk_24->unk_84 == 2) {
            BattleMoveListWidget_DisableRestrictedMoves(arg0->unk_24->unk_78);
            ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_24->unk_34, 3);
        }
        BattleMoveListWidget_Destroy(arg0->unk_24->unk_78);
        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 2);
    } else {
        ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_24->unk_34, 4);
        BattleInfoWidget_OpenSelectionAt(arg0->unk_24->unk_7C, 0);
        ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 3);
    }
}

s32 BattleInfoWidget_ItemMenuHandleInput(unk_func_8830867C_04C_080* arg0, Controller* arg1) {
    s32 i;
    s32 var_s0;
    unk_func_8830867C_04C_080* var_a0;

    var_s0 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }
        var_s0 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    if (var_s0 & 1) {
        return var_s0;
    }

    if (var_s0 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_s0 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_s0 = 0x80000004;
        }
    }

    if (var_s0 & 2) {
        switch (arg0->unk_00.unk_1C) {
            case 2:
                BattleMoveListWidget_SetCloseState(arg0->unk_24->unk_78);
                if (BattleInfoWidget_ItemMenuBackToBrowse(arg0) == 0) {
                    var_s0 |= 1;
                }
                break;

            case 3:
                if (BattleInfoWidget_ItemMenuBackFromMoveSelect(arg0) == 0) {
                    var_s0 |= 1;
                }
                break;
        }
    } else if (var_s0 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                if (arg0->unk_24->unk_8C != 0) {
                    ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_24->unk_34, 1);
                    ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                } else {
                    if (arg0->unk_24->unk_30->unk_34[arg0->unk_24->unk_30->unk_38] & 4) {
                        var_s0 = (var_s0 & ~4) | 0x100;
                    } else {
                        BattleInfoWidget_ItemMenuConfirmSelection(arg0);
                        var_s0 |= 1;
                    }
                }
                break;

            case 2:
                ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_24->unk_34, 4);
                BattleInfoWidget_OpenSelectionAt(arg0->unk_24->unk_7C, 0);
                ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 3);
                var_s0 |= 1;
                break;

            case 3:
                switch (arg0->unk_24->unk_7C->unk_3C->unk_38) {
                    case 0:
                        Audio_PlaySoundEffectById(0x22);
                        Audio_PlaySoundEffectById(0x0120000D);
                        var_s0 &= 0x7FFFFFFF;
                        break;

                    case 1:
                        var_s0 = (var_s0 & ~4) | 2;
                        if (BattleInfoWidget_ItemMenuBackFromMoveSelect(arg0) == 0) {
                            var_s0 |= 1;
                        }
                        break;
                }
                break;
        }
    }

    return var_s0;
}

s32 BattleInfoWidget_ItemMenuHandleContainerInput(unk_func_8830867C_04C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_80->unk_00.unk_10(arg0->unk_80, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void BattleInfoWidget_OpenItemMenu(unk_func_8830867C_04C* arg0) {
    arg0->unk_00.unk_24(&arg0->unk_00, 1);
    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);
}

void BattleInfoWidget_CloseItemMenu(unk_func_8830867C_04C* arg0) {
    if (arg0->unk_7C->unk_2C->unk_00.unk_28 & 1) {
        arg0->unk_7C->unk_2C->unk_2C = 0xB;
    }

    if (arg0->unk_78->unk_2C->unk_00.unk_28 & 1) {
        arg0->unk_78->unk_2C->unk_2C = 0xB;
    }

    arg0->unk_2C->unk_2C = 0xB;
    ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0->unk_80, 0);
    ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_34, 0);
}

s32 BattleInfoWidget_RunItemMenuModal(unk_func_8830867C_04C* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_s0 = 0;

    if (arg0->unk_80->unk_00.unk_1C == 0) {
        BattleInfoWidget_OpenItemMenu(arg0);
    }

    if (arg0->unk_80->unk_00.unk_1C == 1) {
        if (arg0->unk_88 == NULL) {
            ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0->unk_80, 0);
            ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_34, 0);
        } else {
            BattleInfoWidget_ItemMenuConfirmSelection(arg0->unk_80);
        }
    }

    while (var_s0 == 0) {
        Ui_SendMessageAndPollInput(var_s0);

        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                if (arg0->unk_80->unk_00.unk_1C == 1) {
                    var_s0 = 3;
                } else {
                    var_s0 = 1;
                }
            } else if (temp_v0 & 4) {
                if (arg0->unk_80->unk_00.unk_1C == 1) {
                    var_s0 = 3;
                } else {
                    var_s0 = 2;
                }
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(temp_v0);
    }

    if (var_s0 != 3) {
        BattleInfoWidget_CloseItemMenu(arg0);
    }
    return var_s0 - 1;
}

void BattleInfoWidget_DrawSlotEntry(s32 arg0, s32 arg1, unk_func_88309160_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_88200FA0_030_030_1CEA00* arg5) {
    static Color_RGBA8 D_8831764C = { 0xFF, 0xB2, 0xC3, 0xFF };
    static Color_RGBA8 D_88317650[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF },
        { 0xF0, 0xF0, 0xF0, 0x4D },
        { 0xFF, 0xB2, 0xC3, 0xFF },
    };

    Color_RGBA8 sp34;
    s32 var_v0;
    char* sp2C;
    char sp28[4];

    sp2C = Text_GetString(NULL, 0, D_8831A4C4, 0x5F);
    if (arg4 & 4) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }

    sp34 = D_88317650[var_v0];

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(sp34.r, sp34.g, sp34.b, sp34.a);
    Font_SetActive(8, 0);
    Font_Printf(arg0 + 8, arg1 + 2, sp2C);

    sprintf(sp28, "%d", arg3 + 1);

    Font_Printf(((arg0 + Font_MeasureTextExtent(0, 0, sp2C) + Font_MeasureTextExtent(0, 0, " 00")) - Font_MeasureTextExtent(0, 0, sp28)) + 8,
                  arg1 + 2, sp28);
    Font_EndTexturedTextRendering();
    BattleInfoWidget_DrawIndicator((arg5->unk_00.unk_14.unk_00 + arg0) - 0x35, arg1 + 8, arg2->unk_18, arg2->unk_14);
}

void BattleInfoWidget_DrawLocationEntry(s32 arg0, s32 arg1, unk_func_88309160_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_88200FA0_030_030_1CEA00* arg5) {
    static Color_RGBA8 D_8831765C[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF },
        { 0xF0, 0xF0, 0xF0, 0x4D },
    };

    Color_RGBA8 sp2C;
    UNUSED s32 pad[2];
    s32 var_v0;

    if (arg4 & 4) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }

    sp2C = D_8831765C[var_v0];

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(sp2C.r, sp2C.g, sp2C.b, sp2C.a);
    Font_SetActive(8, 0);
    Font_Printf(arg0 + 8, arg1 + 4, Text_GetString(NULL, 0, D_8831A4C4, arg3 + 0x3B));
    Font_EndTexturedTextRendering();
    if (arg2->unk_14 == 1) {
        BattleInfoWidget_DrawIndicator((arg5->unk_00.unk_14.unk_00 + arg0) - 0x35, arg1 + 0xC, arg2->unk_0C->unk_18,
                      arg2->unk_0C->unk_14);
    }
}

void BattleInfoWidget_BuildMoveDestinationMenu(unk_func_8830867C_048* arg0, s32 arg1, s32 arg2, WidgetNode* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88317664 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317668 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_8831766C = { 0xA0, 0x96, 0x64, 0xFF };
    static Color_RGBA8 D_88317670 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88317674 = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317678 = { 0xA0, 0x96, 0x64, 0xFF };

    UNUSED s32 pad[2];
    s32 spBC;
    UNUSED s32 pad3;
    unk_func_8850B254* spB4;
    unk_func_8850878C* spB0;
    unk_func_885012A4* spAC;
    unk_func_8850BD40* spA8;
    UNUSED s32 pad4;
    s32 spA0;
    s32 temp_v0_2;
    s32 sp98;
    UNUSED s32 pad5;
    char* sp90;
    char* sp8C;
    s32 sp88;
    s32 sp84;
    unk_func_8850B254* sp80;
    unk_func_8850878C* sp7C;
    unk_func_885012A4* sp78;
    WidgetNode* sp74;
    unk_func_8850BD40* sp70;
    unk_func_8850BD40* sp6C;
    unk_func_88503298* sp68;

    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_048));

    arg0->unk_00.unk_20 = BattleInfoWidget_HandleMoveDestinationContainerInput;
    arg0->unk_00.unk_24 = BattleInfoWidget_SetMoveDestinationState;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_48 = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_048_048));
    BattleInfoWidget_InitMoveDestinationSelectionProxy(arg0->unk_48, arg0);
    spBC = BattleInfoWidget_GetStatusEntryWidth();

    BattleInfoWidget_SetMoveDestinationTitle(arg0, 0, 0);
    temp_v0_2 = Font_MeasureTextExtent(8, 0, arg0->unk_50);
    if (spBC < temp_v0_2) {
        spBC = temp_v0_2;
    }

    BattleInfoWidget_SetMoveDestinationTitle(arg0, 1, 0xB);
    temp_v0_2 = Font_MeasureTextExtent(8, 0, arg0->unk_50);
    if (spBC < temp_v0_2) {
        spBC = temp_v0_2;
    }

    BattleInfoWidget_SetMoveDestinationTitle(arg0, 2, 0xB);
    temp_v0_2 = Font_MeasureTextExtent(8, 0, arg0->unk_50);
    if (spBC < temp_v0_2) {
        spBC = temp_v0_2;
    }

    spBC += 0x10;

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, spBC, 0x8C);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);

    spB4 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(spB4, 0, 0, spBC, 0x2C, D_88317664, D_88317668);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spB4);
    arg0->unk_50[0] = '\0';

    spB0 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(spB0, 8, 0, arg0->unk_50, 8);
    spB0->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spB4, spB0);

    spAC = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(spAC, 0, 0x30, spBC, 0x5C, D_8831766C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, spAC);

    arg0->unk_34 = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030_030_1CEA00));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_34, 0, 4, BattleInfoWidget_DrawLocationEntry, spBC, 0x1C, 3, 1, arg4);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_34, 3, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(spAC, arg0->unk_34);

    spA8 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(spA8, arg0->unk_34);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_48, spA8);

    arg0->unk_4C = mem_pool_alloc(arg4, sizeof(unk_func_8830867C_048_04C));
    ((func8850CBA8)Memmap_GetFragmentVaddr(WidgetTree_InitChildSelectionProxy))(arg0->unk_4C);
    ((func8850BF80)Memmap_GetFragmentVaddr(WidgetTree_AppendVerticalMenuItem))(arg0->unk_48, arg0->unk_4C);

    spA0 = BattleInfoWidget_GetEntryWidth();
    sp90 = Text_GetString(NULL, 0, D_8831A4C4, 0x60);
    sp8C = Text_GetString(NULL, 0, D_8831A4C4, 0x61);
    sp88 = Font_MeasureTextExtent(8, 0, sp90);
    sp84 = Font_MeasureTextExtent(8, 0, sp8C);

    sp98 = spA0;
    if (spA0 < sp88) {
        sp98 = sp88;
    }

    if (sp98 < sp84) {
        sp98 = sp84;
    }
    sp98 += 0x10;
    spA0 += 0x10;

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_30, arg0->unk_2C->unk_00.unk_14.unk_00 + 0x10, 0,
                                                           sp98, 0x140);
    arg0->unk_30->unk_00.unk_28 |= 0x200;
    arg0->unk_30->unk_00.unk_28 |= 0x400;
    arg0->unk_30->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_30);

    sp80 = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(sp80, 0, 0, sp98, 0x14, D_88317670, D_88317674);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_30, sp80);

    arg0->unk_40 = mem_pool_alloc(arg4, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_40, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp80, arg0->unk_40);

    sp7C = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp7C, 0, 0, "", 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_40, sp7C);

    sp7C = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp7C, (sp98 - sp88) / 2, 0, sp90, 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_40, sp7C);

    sp7C = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp7C, (sp98 - sp84) / 2, 0, sp8C, 8);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_40, sp7C);

    sp78 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp78, 0, 0x18, sp98, 0x128, D_88317678);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_30, sp78);

    arg0->unk_44 = mem_pool_alloc(arg4, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(WidgetTree_InitPagedContainer))(arg0->unk_44, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp78, arg0->unk_44);

    sp74 = mem_pool_alloc(arg4, sizeof(WidgetNode));
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(sp74, 0x2C);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_44, sp74);

    arg0->unk_38[0] = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030_030_1CEA00));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_38[0], (sp98 - spA0) / 2, 4, BattleInfoWidget_DrawSlotEntry, spA0,
                                                           0x18, 0xC, 1, arg4);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_38[0], 0xC, arg4);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_44, arg0->unk_38[0]);

    sp70 = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(sp70, arg0->unk_38[0]);
    ((func8850CC74)Memmap_GetFragmentVaddr(WidgetTree_AppendChildSelectionProxyItem))(arg0->unk_4C, sp70);

    arg0->unk_38[1] = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030_030_1CEA00));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_38[1], 0, 4, BattleInfoWidget_DrawSlotEntry, spA0, 0x18, 0xC, 1,
                                                           arg4);
    ((func88506238)Memmap_GetFragmentVaddr(WidgetTree_AllocateEntryFlags))(arg0->unk_38[1], 0xC, arg4);
    ((func88500A3C)Memmap_GetFragmentVaddr(WidgetTree_AddPage))(arg0->unk_44, arg0->unk_38[1]);

    sp6C = mem_pool_alloc(arg4, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(WidgetTree_InitScrollableGridInputProxy))(sp6C, arg0->unk_38[1]);
    ((func8850CC74)Memmap_GetFragmentVaddr(WidgetTree_AppendChildSelectionProxyItem))(arg0->unk_4C, sp6C);

    sp68 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(WidgetTree_InitVisibilityGateBridge))(sp68, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, sp68);
}

void BattleInfoWidget_BindMoveDestinationData(unk_func_8830867C_048* arg0, unk_func_8830867C_02C_144* arg1) {
    unk_func_8830867C_02C_144_000_alt* sp24;

    ((func885063B8)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridStridedData))(arg0->unk_34, arg1);
    sp24 = arg1->unk_00;
    ((func885063B8)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridStridedData))(arg0->unk_38[0], &sp24->unk_2C);
    ((func885063B8)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridStridedData))(arg0->unk_38[1], &sp24->unk_4C);
}

typedef struct unk_func_88313894 {
    /* 0x00 */ char unk00[0xC];
    /* 0x0C */ unk_func_8830867C_02C_0CC_000_000* unk_0C;
    /* 0x10 */ char unk10[0xC];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ unk_func_88313894_020 unk_20;
    /* 0x40 */ unk_func_88313894_020 unk_40;
} unk_func_88313894; // size >= 0x60

void BattleInfoWidget_MarkFullBoxSlots(unk_func_88200FA0_030_030_1CEA00* arg0, unk_func_8830867C_02C_0CC_000* arg1,
                   unk_func_88313894_020* arg2) {
    unk_func_8830867C_02C_0CC_000_000* sp24 = arg2->unk_0C;
    s32 i;

    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0);

    for (i = 0; i < arg2->unk_14; i++, sp24++) {
        if (sp24 == arg1->unk_00) {
            arg0->unk_34[i] |= 4;
        } else if (sp24->unk_10.unk_08 >= arg2->unk_1C) {
            arg0->unk_34[i] |= 4;
        }
    }
}

void BattleInfoWidget_MarkIneligibleDestinations(unk_func_8830867C_048* arg0, unk_func_8830867C_02C_0CC_000* arg1) {
    u16* temp_v0_2;
    u16* temp_v0_3;
    unk_func_88313894* temp_s1;
    unk_func_8830867C_02C_0CC_000_000* temp_v0;

    temp_s1 = arg0->unk_34->unk_2C->unk_00;
    ((func8850628C)Memmap_GetFragmentVaddr(WidgetTree_ClearEntryFlags))(arg0->unk_34);

    temp_v0 = temp_s1->unk_0C;
    if (temp_v0 == arg1->unk_00) {
        arg0->unk_34->unk_34[0] |= 4;
    } else if (temp_v0->unk_10.unk_08 >= temp_s1->unk_1C) {
        arg0->unk_34->unk_34[0] |= 4;
    }

    BattleInfoWidget_MarkFullBoxSlots(arg0->unk_38[0], arg1, &temp_s1->unk_20);
    BattleInfoWidget_MarkFullBoxSlots(arg0->unk_38[1], arg1, &temp_s1->unk_40);
}

void BattleInfoWidget_FormatLocationName(char* arg0, s32 arg1, s32 arg2) {
    static u16 D_8831767C[4] = { 0x3B, 0x62, 0x63, 0 };

    HAL_Strcpy(arg0, Text_GetString(NULL, 0, D_8831A4C4, D_8831767C[arg1]));
    if (arg1 != 0) {
        sprintf(&arg0[strlen(arg0)], " %d", arg2 + 1);
    }
}

void BattleInfoWidget_SetMoveDestinationTitle(unk_func_8830867C_048* arg0, s32 arg1, s32 arg2) {
    char sp18[32];

    BattleInfoWidget_FormatLocationName(sp18, arg1, arg2);
    Text_SetStringToken(0x25, sp18);
    Text_GetString(arg0->unk_50, 0x80, D_8831A4C4, 0x3A);
}

void BattleInfoWidget_SyncDestinationPage(unk_func_8830867C_048* arg0) {
    s32 sp24 = arg0->unk_34->unk_38;

    ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_44, sp24);
    ((func88500A6C)Memmap_GetFragmentVaddr(WidgetTree_SelectPage))(arg0->unk_40, sp24);
}

void BattleInfoWidget_OpenMoveDestinationMenu(unk_func_8830867C_048* arg0) {
    ((func88506CE4)Memmap_GetFragmentVaddr(WidgetTree_FindSelectableGridEntry))(arg0->unk_34);
    ((func88506CE4)Memmap_GetFragmentVaddr(WidgetTree_FindSelectableGridEntry))(arg0->unk_38[0]);
    ((func88506CE4)Memmap_GetFragmentVaddr(WidgetTree_FindSelectableGridEntry))(arg0->unk_38[1]);
    BattleInfoWidget_SyncDestinationPage(arg0);
    ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0->unk_48, 0);

    arg0->unk_48->unk_00.unk_14(arg0->unk_48, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);
    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_30);
}

void BattleInfoWidget_CloseMoveDestinationMenu(unk_func_8830867C_048* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
    arg0->unk_30->unk_2C = 0xB;
}

void BattleInfoWidget_SetMoveDestinationState(unk_func_8830867C_048* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_48->unk_00.unk_14(arg0->unk_48, arg1);
}

s32 BattleInfoWidget_HandleMoveDestinationContainerInput(unk_func_8830867C_048* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_48->unk_00.unk_10(arg0->unk_48, arg1);
        if (!(var_v1 & 1)) {
            if (var_v1 & 2) {
                BattleInfoWidget_CloseMoveDestinationMenu(arg0);
            } else if (var_v1 & 4) {
                BattleInfoWidget_CloseMoveDestinationMenu(arg0);
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void BattleInfoWidget_InitMoveDestinationSelectionProxy(unk_func_8830867C_048_048* arg0, unk_func_8830867C_048* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(WidgetTree_InitVerticalMenu))(arg0);
    arg0->unk_00.unk_10 = BattleInfoWidget_MoveDestinationSelectionInput;
    arg0->unk_24 = arg1;
}

s32 BattleInfoWidget_MoveDestinationSelectionInput(unk_func_8830867C_048_048* arg0, Controller* arg1) {
    s32 var_a2;
    s32 i;
    unk_func_8830867C_048_048* var_a0;
    unk_func_88200FA0_030_030_1CEA00* temp_v0_4;

    var_a2 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;

        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }

        var_a2 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    switch (arg0->unk_00.unk_1C) {
        case 0:
            if (var_a2 & 1) {
                if (var_a2 & 8) {
                    BattleInfoWidget_SyncDestinationPage(arg0->unk_24);
                }
            } else if (arg1->buttonPressed & 0x8000) {
                if (arg0->unk_24->unk_34->unk_38 != 0) {
                    ((func8850CD24)Memmap_GetFragmentVaddr(WidgetTree_SetChildSelectionProxySelection))(arg0->unk_24->unk_4C,
                                                                           arg0->unk_24->unk_34->unk_38 - 1);
                    ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 1);
                    var_a2 |= 1;
                }
                var_a2 |= 0x80000004;
            } else if (arg1->buttonPressed & 0x4000) {
                var_a2 |= 0x80000002;
            }
            break;

        case 1:
            if (!(var_a2 & 1)) {
                if (arg1->buttonPressed & 0x8000) {
                    temp_v0_4 = arg0->unk_24->unk_38[arg0->unk_24->unk_34->unk_38 - 1];
                    if (temp_v0_4->unk_34[temp_v0_4->unk_38] & 4) {
                        var_a2 = 0x80000101;
                    } else {
                        var_a2 = 0x80000004;
                    }
                } else if (arg1->buttonPressed & 0x4000) {
                    ((func8850C064)Memmap_GetFragmentVaddr(WidgetTree_SetVerticalMenuSelection))(arg0, 0);
                    var_a2 = 0x80000003;
                }
            }
            break;
    }
    return var_a2;
}

s32 BattleInfoWidget_RunMoveDestinationModal(unk_func_8830867C_048* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1 = 0;

    BattleInfoWidget_OpenMoveDestinationMenu(arg0);

    while (var_s1 == 0) {
        Ui_SendMessageAndPollInput(var_s1);

        var_s0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(var_s0 & 1)) {
            if (var_s0 & 2) {
                var_s1 = 1;
            } else if (var_s0 & 4) {
                var_s0 = 0x80000801;
                var_s1 = 2;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(var_s0);
    }

    BattleInfoWidget_CloseMoveDestinationMenu(arg0);
    return var_s1 - 1;
}

void BattleInfoWidget_DrawSaveConfirmLabel(s32 arg0, s32 arg1, s8* arg2, s32 arg3) {
    static Color_RGBA8 D_88317684 = { 0xF0, 0xF0, 0xF0, 0xFF };

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(D_88317684.r, D_88317684.g, D_88317684.b, D_88317684.a);
    Font_SetActive(8, 0);
    Font_Printf(arg0 + 8, arg1 + 4, arg2);
    Font_EndTexturedTextRendering();
}

void BattleInfoWidget_BuildSaveConfirmDialog(unk_func_8830867C_02C_0B4* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    static Color_RGBA8 D_88317688 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_8831768C = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88317690 = { 0xA0, 0x96, 0x64, 0xFF };

    UNUSED s32 pad;
    s32 sp68;
    UNUSED s32 pad2[2];
    s32 sp5C;
    s32 temp_v1;
    unk_func_8850B254* sp54;
    char* sp50;
    unk_func_8850878C* sp4C;
    unk_func_885012A4* sp48;

    sp54 = mem_pool_alloc(arg3, sizeof(unk_func_8850B254));
    sp50 = Text_GetString(NULL, 0, D_8831A4C4, 0x59);

    sp4C = mem_pool_alloc(arg3, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(WidgetTree_InitTextLabel))(sp4C, 8, 0, sp50, 8);
    temp_v1 = Font_MeasureTextExtent(8, 0, sp50) + 0x10;
    sp68 = temp_v1;
    sp5C = temp_v1;
    ((func8850B254)Memmap_GetFragmentVaddr(WidgetTree_InitDashedBorderFrame))(sp54, 0, 0, sp5C, 0x14, D_88317688, D_8831768C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp54, sp4C);
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, 0x40);

    arg0->unk_00.unk_20 = BattleInfoWidget_HandleSaveConfirmInput;
    arg0->unk_00.unk_10.unk_00 = (arg2 - sp5C) / 2;
    arg0->unk_00.unk_10.unk_02 = arg1;

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(WidgetAnimatedPanel));
    ((func88502274)Memmap_GetFragmentVaddr(WidgetTree_InitAnimatedPanel))(arg0->unk_2C, 0, 0, sp5C, 0x58);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0, arg0->unk_2C);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp54);

    sp48 = mem_pool_alloc(arg3, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(WidgetTree_InitSolidColor))(sp48, 0, 0x18, sp5C, 0x40, D_88317690);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(arg0->unk_2C, sp48);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_8830867C_02C_0B4_030));
    ((func885060BC)Memmap_GetFragmentVaddr(WidgetTree_InitPagedGrid))(arg0->unk_30, 0, 4, BattleInfoWidget_DrawSaveConfirmLabel, sp68, 0x1C, 2, 1, arg3);

    PointerList_Allocate(&arg0->unk_34, 2, arg3);
    PointerList_Insert(&arg0->unk_34, Text_GetString(NULL, 0, D_8831A4C4, 0x5A), 0);
    PointerList_Insert(&arg0->unk_34, Text_GetString(NULL, 0, D_8831A4C4, 0x5B), 1);

    ((func88506384)Memmap_GetFragmentVaddr(WidgetTree_BindPagedGridPage))(arg0->unk_30, &arg0->unk_34, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(WidgetTree_AppendChild))(sp48, arg0->unk_30);
}

s32 BattleInfoWidget_HandleSaveConfirmInput(unk_func_8830867C_02C_0B4* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 BattleInfoWidget_RunSaveConfirmModal(unk_func_8830867C_02C_0B4* arg0, Controller* arg1) {
    s32 temp_v0_3;
    s32 var_s0;
    s32 var_s1 = 0;

    ((func88506BFC)Memmap_GetFragmentVaddr(WidgetTree_SetPagedGridSelection))(arg0->unk_30, 0);

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(WidgetTree_OpenAnimatedPanel))(arg0->unk_2C);

    while (var_s1 == 0) {
        Ui_SendMessageAndPollInput(var_s1);

        var_s0 = arg0->unk_00.unk_20(arg0, arg1);

        if (!(var_s0 & 1)) {
            if (arg1->buttonPressed & 0x4000) {
                var_s0 = 0x80000003;
                var_s1 = 2;
            } else if (arg1->buttonPressed & 0x8000) {
                temp_v0_3 = arg0->unk_30->unk_38;
                var_s1 = temp_v0_3 + 1;
                if (temp_v0_3 == 0) {
                    var_s0 = 4;
                } else {
                    var_s0 = 2;
                }
                var_s0 |= 0x80000001;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(Ui_PlayInputActionSound))(var_s0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s1 - 1;
}

void LabPCList_InitTextFadeWidget(unk_func_882173EC* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_882173EC));
    arg0->unk_00.unk_1C = LabPCList_TextFadeWidget_Update;
    arg0->unk_00.unk_18 = LabPCList_DrawTextFadeWidget;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = arg4;
    arg0->unk_2C = 0x3C;
    arg0->unk_00.unk_28 &= ~1;
}

s32 LabPCList_TextFadeWidget_Update(unk_func_882173EC* arg0) {
    if (arg0->unk_2C >= 0x3C) {
        arg0->unk_00.unk_28 &= ~0x101;
        return 0;
    }

    arg0->unk_00.unk_28 |= 0x100;
    arg0->unk_2C++;
    if ((*((s32*)&arg0->unk_30) == -1) && (arg0->unk_2C == 0x15)) {
        arg0->unk_2C = 0x29;
    }
    return 0;
}

s32 LabPCList_DrawTextFadeWidget(unk_func_882173EC* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88317694[] = {
        { 0x00, 0x00, 0x00, 0xFF },
        { 0x32, 0x32, 0x32, 0xFF },
    };

    char* sp6C = NULL;
    Color_RGBA8 sp68;
    s32 sp64 = arg0->unk_2C - 1;
    s32 temp_t3;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t3 = ((D_88317694[(sp64 / 3) & 1].r << 8) & 0xF800) | ((D_88317694[(sp64 / 3) & 1].g << 3) & 0x7C0) | ((D_88317694[(sp64 / 3) & 1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on
    gDPSetFillColor(gDisplayListHead++, (temp_t3 << 0x10) | temp_t3);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_00.unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_00.unk_14.unk_02) - 1);

    if (sp64 < 0x14) {
        if (*(s32*)&arg0->unk_30 != -1) {
            ret_func_8002ED08* sp44;
            UNUSED s32 pad[2];

            sp44 = Move_GetDisplayInfo(*(s32*)&arg0->unk_30);
            sp68 = ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(sp44->unk_00[1])->unk_04;
            sp6C = Text_GetString(NULL, 0, D_8831A4CC, *(s32*)&arg0->unk_30 - 1);
            sp68.a = 0xFF;
        }
    } else if (sp64 < 0x28) {
        ret_func_8002ED08* sp38;
        UNUSED s32 pad2[2];

        sp38 = Move_GetDisplayInfo(*(s32*)&arg0->unk_30);
        sp68 = ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(sp38->unk_00[1])->unk_04;
        sp6C = Text_GetString(NULL, 0, D_8831A4CC, *(s32*)&arg0->unk_30 - 1);
        sp68.a = ((-sp64 * 0xFF) + 0x26D9) / 20;
    } else {
        ret_func_8002ED08* sp2C;

        sp2C = Move_GetDisplayInfo(*(s32*)&arg0->unk_34);
        sp68 = ((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(sp2C->unk_00[1])->unk_04;
        sp6C = Text_GetString(NULL, 0, D_8831A4CC, *(s32*)&arg0->unk_34 - 1);
        sp68.a = ((sp64 * 0xFF) - 0x27D8) / 20;
    }

    if (sp6C != NULL) {
        Font_BeginTranslucentTextRendering();
        Font_SetActive(4, 0);
        Gfx_SetEnvColor(sp68.r, sp68.g, sp68.b, sp68.a);
        Font_Printf(((arg0->unk_00.unk_14.unk_00 - Font_MeasureTextExtent(0, 0, sp6C)) / 2) + arg1,
                      ((arg0->unk_00.unk_14.unk_02 - 0x10) / 2) + arg2, sp6C);
        Font_EndTexturedTextRendering();
    }
    return 0;
}

void LabPCList_TextFadeWidget_Start(unk_func_882173EC* arg0, s32 arg1, s32 arg2, WidgetPoint arg3) {
    arg0->unk_2C = 0;
    *(s32*)&arg0->unk_30 = arg1;
    *(s32*)&arg0->unk_34 = arg2;
    arg0->unk_00.unk_10 = arg3;
    arg0->unk_00.unk_28 |= 1;
}

void LabPCList_InitPpUpAnimWidget(unk_func_8830867C_02C_0C0* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_8830867C_02C_0C0));
    arg0->unk_00.unk_00.unk_1C = LabPCList_PpUpAnimWidget_Update;
    arg0->unk_00.unk_00.unk_18 = LabPCList_DrawPpUpAnimWidget;
    arg0->unk_00.unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_00.unk_14.unk_02 = arg4;
    arg0->unk_00.unk_2C = 0x5C;
    arg0->unk_00.unk_00.unk_28 &= ~1;
}

s32 LabPCList_PpUpAnimWidget_Update(unk_func_8830867C_02C_0C0* arg0) {
    if (arg0->unk_00.unk_2C >= 0x5C) {
        arg0->unk_00.unk_00.unk_28 &= ~1;
        return 0;
    }

    if (arg0->unk_00.unk_2C >= 0x5B) {
        arg0->unk_00.unk_00.unk_28 &= ~0x100;
    }

    arg0->unk_00.unk_2C++;
    return 0;
}

s32 LabPCList_DrawPpUpAnimWidget(unk_func_8830867C_02C_0C0* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_8831769C = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_883176A0[] = {
        { 0x00, 0x00, 0x00, 0xFF },
        { 0x32, 0x32, 0x32, 0xFF },
    };

    UNUSED s32 pad;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    Color_RGBA8 sp8C;
    char* sp88;
    char sp84[4];
    s32 sp80;
    ret_func_8002ED08* temp_s0;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 temp_t0;

    sp90 = arg0->unk_00.unk_2C - 1;
    sp80 = Font_MeasureTextExtent(4, 0, "00") + 4;
    sp74 = (arg0->unk_00.unk_00.unk_14.unk_02 - 0x10) / 2;
    temp_s0 = Move_GetDisplayInfo(*(s32*)&arg0->unk_00.unk_30);
    sp8C = (((func884000C4)Memmap_GetFragmentVaddr(LabPC_GetTypeColor))(temp_s0->unk_00[1]))->unk_04;
    sp88 = Text_GetString(NULL, 0, D_8831A4CC, *(s32*)&arg0->unk_00.unk_30 - 1);
    sp70 = strlen(sp88);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_t0 = ((D_883176A0[(sp90 / 3) & 1].r << 8) & 0xF800) | ((D_883176A0[(sp90 / 3) & 1].g << 3) & 0x7C0) |
              ((D_883176A0[(sp90 / 3) & 1].b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_t0 << 0x10) | temp_t0);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_00.unk_00.unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_00.unk_00.unk_14.unk_02) - 1);

    if (sp90 < 0x10) {
        sp78 = arg0->unk_00.unk_00.unk_14.unk_00 - ((sp80 * sp90) / 16);
        sp98 = (((sp78 - Font_MeasureTextExtent(4, 0, sp88, arg1)) - sp70) - 7) / sp70;
        if (arg2) {}
        sp94 = arg2 + sp74;
    } else if (sp90 < 0x24) {
        sp78 = arg0->unk_00.unk_00.unk_14.unk_00 - sp80;
        sp98 = (((sp78 - Font_MeasureTextExtent(4, 0, sp88, arg1)) - sp70) - 7) / sp70;
        sp94 = arg2 + sp74;
    } else if (sp90 < 0x38) {
        s32 sp50 = sp90 - 0x24;
        UNUSED s32 pad3[3];

        sp78 = arg0->unk_00.unk_00.unk_14.unk_00 - sp80;
        sp98 = (((sp78 - Font_MeasureTextExtent(4, 0, sp88, arg1)) - sp70) - 7) / sp70;
        sp94 = (arg2 + sp74) - ((arg0->unk_00.unk_00.unk_14.unk_02 * sp50) / 20);
    } else if (sp90 < 0x4C) {
        sp78 = arg0->unk_00.unk_00.unk_14.unk_00 - sp80;
        sp98 = (((sp78 - Font_MeasureTextExtent(4, 0, sp88, arg1)) - sp70) - 7) / sp70;
        sp94 = (arg2 + sp74) - arg0->unk_00.unk_00.unk_14.unk_02;
    } else if (sp90 < 0x5C) {
        sp78 = arg0->unk_00.unk_00.unk_14.unk_00 - ((sp80 * (0x5B - sp90)) / 16);
        sp98 = (((sp78 - Font_MeasureTextExtent(4, 0, sp88, arg1)) - sp70) - 7) / sp70;
        sp94 = (arg2 + sp74) - arg0->unk_00.unk_00.unk_14.unk_02;
    }

    if (sp98 > 0) {
        if (1) {}
        sp98 = 0;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetScissorFrac(gDisplayListHead++, G_SC_NON_INTERLACE, arg1 * 4.0f, arg2 * 4.0f,
                      (arg0->unk_00.unk_00.unk_14.unk_00 + arg1) * 4.0f,
                      (arg2 + arg0->unk_00.unk_00.unk_14.unk_02) * 4.0f);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, sp98);
    Gfx_SetEnvColor(sp8C.r, sp8C.g, sp8C.b, sp8C.a);
    Font_Printf(((sp78 - Font_MeasureTextExtent(4, sp98, sp88)) / 2) + arg1, arg2 + sp74, sp88);
    Font_SetActive(4, 0);
    Gfx_SetEnvColor(D_8831769C.r, D_8831769C.g, D_8831769C.b, D_8831769C.a);

    sprintf(sp84, "%d", *(s32*)&arg0->unk_00.unk_34);

    Font_Printf(((arg1 + sp78 + sp80) - Font_MeasureTextExtent(0, 0, sp84)) - 4, sp94, sp84);

    sprintf(sp84, "%d", arg0->unk_38);

    Font_Printf(((arg1 + sp78 + sp80) - Font_MeasureTextExtent(0, 0, sp84)) - 4, arg0->unk_00.unk_00.unk_14.unk_02 + sp94,
                  sp84);
    Font_EndTexturedTextRendering();

    gDPPipeSync(gDisplayListHead++);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 640, 480);

    return 0;
}

void LabPCList_PpUpAnimWidget_Start(unk_func_8830867C_02C_0C0* arg0, s32 arg1, s32 arg2, s32 arg3, WidgetPoint arg4) {
    arg0->unk_00.unk_2C = 0;
    *(s32*)&arg0->unk_00.unk_30 = arg1;
    *(s32*)&arg0->unk_00.unk_34 = arg2;
    arg0->unk_38 = arg3;
    arg0->unk_00.unk_00.unk_10 = arg4;
    arg0->unk_00.unk_00.unk_28 |= 0x101;
}

void LabPCList_InitVitaminAnimWidget(unk_func_882173EC* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_882173EC));
    arg0->unk_00.unk_1C = LabPCList_VitaminAnimWidget_Update;
    arg0->unk_00.unk_18 = LabPCList_DrawVitaminAnimWidget;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = arg4;
    arg0->unk_2C = 0x28;
    arg0->unk_00.unk_28 &= ~1;
}

s32 LabPCList_VitaminAnimWidget_Update(unk_func_882173EC* arg0) {
    if (arg0->unk_2C >= 0x28) {
        arg0->unk_00.unk_28 &= ~1;
        return 0;
    }
    if (arg0->unk_2C >= 0x27) {
        arg0->unk_00.unk_28 &= ~0x100;
    }
    arg0->unk_2C += 1;
    return 0;
}

s32 LabPCList_DrawVitaminAnimWidget(unk_func_882173EC* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_883176A8 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_883176AC[] = {
        { 0x00, 0x00, 0x00, 0xFF },
        { 0x32, 0x32, 0x32, 0xFF },
    };

    char sp7C[4];
    s32 sp78;
    s32 sp74;
    UNUSED s32 pad;
    s32 temp_t0;
    s32 temp_t3;
    s32 var_s4;

    sp78 = Font_MeasureTextExtent(4, 0, "000");
    temp_t3 = arg0->unk_2C - 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_t0 = ((D_883176AC[(temp_t3 / 3) & 1].r << 8) & 0xF800) | ((D_883176AC[(temp_t3 / 3) & 1].g << 3) & 0x7C0) |
              ((D_883176AC[(temp_t3 / 3) & 1].b >> 2) & 0x3E) | 1;
    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (temp_t0 << 0x10) | temp_t0);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_00.unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_00.unk_14.unk_02) - 1);

    sp74 = ((arg0->unk_00.unk_14.unk_00 - sp78) / 2) + arg1;
    var_s4 = ((arg0->unk_00.unk_14.unk_02 - 0x10) / 2) + arg2;
    if (temp_t3 >= 0x14) {
        var_s4 -= (arg0->unk_00.unk_14.unk_02 * (temp_t3 - 0x14)) / 20;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetScissorFrac(gDisplayListHead++, G_SC_NON_INTERLACE, arg1 * 4.0f, arg2 * 4.0f,
                      (arg0->unk_00.unk_14.unk_00 + arg1) * 4.0f, (arg2 + arg0->unk_00.unk_14.unk_02) * 4.0f);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);
    Gfx_SetEnvColor(D_883176A8.r, D_883176A8.g, D_883176A8.b, D_883176A8.a);

    sprintf(sp7C, "%d", *(s32*)&arg0->unk_30);

    Font_Printf((sp74 + sp78) - Font_MeasureTextExtent(0, 0, sp7C), var_s4, sp7C);

    sprintf(sp7C, "%d", *(s32*)&arg0->unk_34);

    Font_Printf((sp74 + sp78) - Font_MeasureTextExtent(0, 0, sp7C), arg0->unk_00.unk_14.unk_02 + var_s4, sp7C);
    Font_EndTexturedTextRendering();

    gDPPipeSync(gDisplayListHead++);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 640, 480);

    return 0;
}

void LabPCList_TextCrossfadeWidget_Start(unk_func_882173EC* arg0, char* arg1, char* arg2, WidgetPoint arg3) {
    arg0->unk_2C = 0;
    *(char**)&arg0->unk_30 = arg1;
    *(char**)&arg0->unk_34 = arg2;
    arg0->unk_00.unk_10 = arg3;
    arg0->unk_00.unk_28 |= 0x101;
}

void LabPCList_InitLocationCrossfadeWidget(unk_func_882173EC* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(WidgetTree_InitWidget))(arg0, sizeof(unk_func_882173EC));

    arg0->unk_00.unk_1C = LabPCList_LocationCrossfadeWidget_Update;
    arg0->unk_00.unk_18 = LabPCList_DrawLocationCrossfadeWidget;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = arg4;
    arg0->unk_2C = 0x3C;
    arg0->unk_00.unk_28 &= ~1;
}

s32 LabPCList_LocationCrossfadeWidget_Update(unk_func_882173EC* arg0) {
    if (arg0->unk_2C >= 0x3C) {
        arg0->unk_00.unk_28 &= ~1;
        return 0;
    }
    if (arg0->unk_2C >= 0x3B) {
        arg0->unk_00.unk_28 &= ~0x100;
    }
    arg0->unk_2C++;
    return 0;
}

void LabPCList_DrawLocationCaption(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    static Color_RGBA8 D_883176B4 = { 0xF0, 0xF0, 0xF0, 0xFF };

    Color_RGBA8 sp2C;
    char sp24[8];
    UNUSED s32 pad;

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);

    switch (arg4) {
        case 32:
            sp2C = (0, D_8831727C);
            Gfx_SetEnvColor(sp2C.r, sp2C.g, sp2C.b, arg6);
            Font_Printf(arg0 + 4, ((arg3 - 0x10) / 2) + arg1, Text_GetString(NULL, 0, D_8831A4C4, 0x14));
            break;

        case 33:
            Gfx_SetEnvColor(D_883176B4.r, D_883176B4.g, D_883176B4.b, arg6);
            sprintf(sp24, "%d", arg5 + 1);
            Font_Printf(((arg0 + arg2) - Font_MeasureTextExtent(0, 0, sp24)) - 4, ((arg3 - 0x10) / 2) + arg1, sp24);

            sp2C = (0, D_88317280);
            Gfx_SetEnvColor(sp2C.r, sp2C.g, sp2C.b, arg6);
            Font_Printf(arg0 + 4, ((arg3 - 0x10) / 2) + arg1, Text_GetString(NULL, 0, D_8831A4C4, 0x15));
            break;

        case 17:
            Gfx_SetEnvColor(D_883176B4.r, D_883176B4.g, D_883176B4.b, arg6);
            sprintf(sp24, "%d", arg5 + 1);
            Font_Printf(((arg0 + arg2) - Font_MeasureTextExtent(0, 0, sp24)) - 4, ((arg3 - 0x10) / 2) + arg1, sp24);

            sp2C = (0, D_88317284);
            Gfx_SetEnvColor(sp2C.r, sp2C.g, sp2C.b, arg6);
            Font_Printf(arg0 + 4, ((arg3 - 0x10) / 2) + arg1, Text_GetString(NULL, 0, D_8831A4C4, 0x16));
            break;
    }
    Font_EndTexturedTextRendering();
}

s32 LabPCList_DrawLocationCrossfadeWidget(unk_func_882173EC* arg0, s32 arg1, s32 arg2) {
    static s32 D_883176B8[] = { 0x20, 0x21, 0x11 };
    static Color_RGBA8 D_883176C4[] = {
        { 0x00, 0x00, 0x00, 0xFF },
        { 0x32, 0x32, 0x32, 0xFF },
    };

    s32 temp_t0 = arg0->unk_2C - 1;
    s32 temp_t4;
    s32 var_v0;
    s32 var_v1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    // clang-format off
    temp_t4 = ((D_883176C4[(temp_t0 / 3) & 1].r << 8) & 0xF800) | ((D_883176C4[(temp_t0 / 3) & 1].g << 3) & 0x7C0) | ((D_883176C4[(temp_t0 / 3) & 1].b >> 2) & 0x3E) | 1; gDPPipeSync(gDisplayListHead++);
    // clang-format on
    gDPSetFillColor(gDisplayListHead++, (temp_t4 << 0x10) | temp_t4);
    gDPFillRectangle(gDisplayListHead++, arg1, arg2, (arg0->unk_00.unk_14.unk_00 + arg1) - 1,
                     (arg2 + arg0->unk_00.unk_14.unk_02) - 1);

    if (temp_t0 < 0x14) {
        var_v1 = 0xFF;
        var_v0 = *(s32*)&arg0->unk_30;
    } else if (temp_t0 < 0x28) {
        var_v1 = ((-temp_t0 * 0xFF) + 0x26D9) / 20;
        var_v0 = *(s32*)&arg0->unk_30;
    } else {
        var_v1 = ((temp_t0 * 0xFF) - 0x27D8) / 20;
        var_v0 = *(s32*)&arg0->unk_34;
    }

    LabPCList_DrawLocationCaption(arg1, arg2, arg0->unk_00.unk_14.unk_00, arg0->unk_00.unk_14.unk_02, D_883176B8[var_v0 >> 0x10],
                  var_v0 & 0xFFFF, var_v1);
    return 0;
}

void LabPCList_LocationCrossfadeWidget_Start(unk_func_882173EC* arg0, s32 arg1, s32 arg2, WidgetPoint arg3) {
    arg0->unk_2C = 0;
    *(s32*)&arg0->unk_30 = arg1;
    *(s32*)&arg0->unk_34 = arg2;
    arg0->unk_00.unk_10 = arg3;
    arg0->unk_00.unk_28 |= 0x101;
}
