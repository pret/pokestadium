#include "gallery_debugger.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/save_data.h"
#include "src/jpeg_stream.h"
#include "src/gfx_buffer.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_839006B0 {
    /* 0x00 */ BattleMon unk_00;
    /* 0x54 */ char unk54[0x38];
} unk_D_839006B0; // size = 0x8C

typedef struct unk_D_83902700 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk04[0x70];
} unk_D_83902700; // size >= 0x74

static unk_D_839006B0 D_839006B0[37];
static unk_D_839006B0 D_83901AF0[22];
static void* D_839026F8;
static s32 D_839026FC;
static unk_D_83902700 D_83902700;
static s32 D_83902774;

static Gfx D_83900630[] = {
    gsSPEndDisplayList(),
};

static Gfx D_83900638[] = {
    gsSPEndDisplayList(),
};

void func_83900020(void) {
}

void GalleryDebugger_SaveControllerPak(void) {
}

void GalleryDebugger_LoadControllerPak(void) {
}

void GalleryDebugger_LoadDeckEntries(void) {
    s32 i;

    D_839026FC = 0;
    D_83902700.unk_00 = 0;
    Save_EnsureBankLoaded(2);

    for (i = 0; i < 36; i++) {
        Deck_ReadSaveEntry(0x16, 0, i, &D_839006B0[i]);
    }

    for (i = 0; i < 21; i++) {
        Deck_ReadSaveEntry(0x17, 0, i, &D_83901AF0[i]);
    }

    func_83900020();
}

void GalleryDebugger_SaveDeckEntries(void) {
    s32 i;

    for (i = 0; i < 36; i++) {
        Save_WriteTypedRecord(0x16, 0, i, &D_839006B0[i]);
    }

    for (i = 0; i < 21; i++) {
        Save_WriteTypedRecord(0x17, 0, i, &D_83901AF0[i]);
    }

    Save_CommitBankRecords(2);
    Save_FlushBank(2);
}

void GalleryDebugger_DrawMenu(void) {
    static char* D_83900640[] = { "Load Controller Pak", "Save Controller Pak", "Quit" };

    s32 i;
    s32 sp30;
    char* temp_s0 = "GALLERY DEBUGGER";

    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    sp30 = (0x280 - Font_MeasureTextExtent(0, 0, temp_s0)) / 2;
    Font_Printf(sp30, 0x64, temp_s0);

    for (i = 0; i < 3; i++) {
        s32 tmp = i * 0x16;
        if (i != D_83902700.unk_00) {
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
        }
        Font_Printf(0x78, 0x82 + tmp, D_83900640[i]);
    }

    Font_Printf(sp30, 0xC8, "PFS ERROR : %d", D_83902774);
    Font_EndTexturedTextRendering();
}

void GalleryDebugger_DrawFrame(void) {
    BgStage_DrawFrame();
    Gfx_DrawTiledRgba16Image(D_839026F8);
    GalleryDebugger_DrawMenu();
    BgStage_AdvanceFrame();
}

s32 GalleryDebugger_HandleMenuInput(void) {
    s32 var_a2 = 0;
    s32 temp_a1 = D_83902700.unk_00;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        D_83902700.unk_00--;
        if (D_83902700.unk_00 < 0) {
            D_83902700.unk_00 = 0;
        }
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        D_83902700.unk_00++;
        if (D_83902700.unk_00 >= 3) {
            D_83902700.unk_00 = 2;
        }
    }

    if (temp_a1 != D_83902700.unk_00) {
        D_83902774 = 0;
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        switch (D_83902700.unk_00) {
            case 0:
                GalleryDebugger_LoadControllerPak();
                var_a2 = 0;
                break;

            case 1:
                GalleryDebugger_SaveControllerPak();
                var_a2 = 0;
                break;

            case 2:
                var_a2 = 1;
                break;
        }
    }

    return var_a2;
}

s32 GalleryDebugger_UpdateFadeState(void) {
    s32 sp1C = 1;

    switch (D_839026FC) {
        case 0:
            if (StageContext_GetFadeMode() == 0) {
                D_839026FC = 1;
            }
            break;

        case 1:
            if (GalleryDebugger_HandleMenuInput() != 0) {
                D_839026FC = 2;
                StageFade_StartFromTransparent(0xF);
            }
            break;

        case 2:
            if (StageContext_GetFadeMode() == 1) {
                sp1C = 0;
            }
            break;
    }
    return sp1C;
}

void GalleryDebugger_PollInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void GalleryDebugger_MenuLoop(void) {
    StageFade_StartFromOpaque(0xF);
    do {
        GalleryDebugger_PollInput();
        GalleryDebugger_DrawFrame();
    } while (GalleryDebugger_UpdateFadeState() != 0);
}

s32 GalleryDebugger_Main(s32 arg0, s32 arg1) {
    StageContext* sp24;

    main_pool_push_state('GLDB');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    Font_Init(0x18, 0);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, gallery_ui, 0);
    D_839026F8 = BinArchive_GetFile(ASSET_LOAD2(backgrounds, 1, 1), 0x14);
    GalleryDebugger_LoadDeckEntries();
    StageContext_Activate(sp24);
    GalleryDebugger_MenuLoop();
    GalleryDebugger_SaveDeckEntries();
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('GLDB');

    return 0;
}
