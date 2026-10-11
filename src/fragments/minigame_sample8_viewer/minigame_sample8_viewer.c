#include "minigame_sample8_viewer.h"
#include "src/geo_render.h"
#include "src/model_animation.h"
#include "src/model_animation_events.h"
#include "src/geo_layout.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/ui_graphics.h"
#include "src/jpeg_stream.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static u32 D_86700840[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0, 0x0000000F, 0x00000000, 0x00000000,
    0x05000000, 0x0D000000, 0x05000000, 0x0F000002, 0x05000000, 0x1F00FFFF, 0x00000000, 0x00000000,
    0x00000000, 0x00640064, 0x00640000, 0x05000000, 0x00000000, 0x8D000020, 0x06000000, 0x06000000,
    0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003, 0x05000000, 0x0A000000, 0x800AC840,
    0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};

static unk_D_86002F30* D_86700930;
static GraphNode* D_86700934;
static unk_D_86002F34_00C* D_86700938;
static DisplayObject D_86700940;

static s16 D_86700AA8;
static s16 D_86700AAA;
static s16 D_86700AAC;

void Minigame_Sample8Viewer_PollInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void Minigame_Sample8Viewer_InitCamera(void) {
    D_86700938 = D_86700934->children;
    D_86700AA8 = 0x100;
    D_86700AAA = 0;
    D_86700AAC = 0x78;

    D_86700938->unk_24.near = 50.0f;
    D_86700938->unk_24.far = 6400.0f;
    Camera_ComputeEyeFromAngles(&D_86700938->unk_60.at, &D_86700938->unk_60.eye, D_86700AAC, D_86700AA8, D_86700AAA);
}

void Minigame_Sample8Viewer_UpdateCameraControls(void) {
    if (gPlayer1Controller->buttonDown & 0x800) {
        D_86700AA8 += 256;
    }

    if (gPlayer1Controller->buttonDown & 0x400) {
        D_86700AA8 -= 256;
    }

    if (gPlayer1Controller->buttonDown & 0x200) {
        D_86700AAA += 256;
    }

    if (gPlayer1Controller->buttonDown & 0x100) {
        D_86700AAA -= 256;
    }

    if (gPlayer1Controller->buttonDown & 8) {
        D_86700AAC -= 10;
    }

    if (gPlayer1Controller->buttonDown & 4) {
        D_86700AAC += 10;
    }

    if (D_86700AA8 > 16128) {
        D_86700AA8 = 16128;
    }

    if (D_86700AA8 < 0) {
        D_86700AA8 = 0;
    }

    if (D_86700AAC < 50) {
        D_86700AAC = 50;
    }

    Camera_ComputeEyeFromAngles(&D_86700938->unk_60.at, &D_86700938->unk_60.eye, D_86700AAC, D_86700AA8, D_86700AAA);
}

void Minigame_Sample8Viewer_DrawDebugText(s32 arg0) {
    Color_RGB8 sp2C = { 0, 0, 30 };
    Color_RGB8 sp28 = { 0, 0, 250 };

    Ui_DrawGradientPanel(0xC8, 0xBE, 0x5A, 0x20, &sp2C, &sp28);
    Ui_DrawBorderedPanel(0x1E, 0xBE, 0xA0, 0x20, 0x141);
    Font_BeginTranslucentTextRendering();
    Font_EnableTwoCycleTexturing();
    Font_SetActive(4, -2);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetPrimColor(0x50, 0x50, 0xFF, 0xFF);
    Font_Printf(0x30, 0x14, "MINIGAME8 SAMPLE");
    Font_DisableTwoCycleTexturing();
    Font_SetActive(2, -2);
    Gfx_SetEnvColor(0xFF, 0xC8, 0x32, 0xFF);

    switch (arg0) {
        case 0:
            Font_Printf(0xCD, 0xC2, "OPENNING");
            break;

        case 1:
            Font_Printf(0xCD, 0xC2, "PLAYING");
            break;

        case 2:
            Font_Printf(0xCD, 0xC2, "ENDING");
            break;
    }

    if (arg0 == 1) {
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        Font_Printf(0x23, 0xC2, "CAMERA D:%d", D_86700AAC);
        Font_Printf(0x23, 0xCE, "X:%04hX Y:%04hX", D_86700AA8, D_86700AAA);
    }

    Font_EndTexturedTextRendering();
}

void Minigame_Sample8Viewer_DrawFrame(s32 arg0) {
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 0xA6BF);
    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(D_86700934);
    Minigame_Sample8Viewer_DrawDebugText(arg0);
    BgStage_AdvanceFrame();
}

void Minigame_Sample8Viewer_OpeningLoop(void) {
    StageFade_StartFromOpaque(0x10);
    ModelAnim_SetAnimation(&D_86700940, 8);

    while (ModelAnim_IsFinished(&D_86700940) == 0) {
        Minigame_Sample8Viewer_PollInput();
        Minigame_Sample8Viewer_DrawFrame(0);
    }
}

void Minigame_Sample8Viewer_PlayingLoop(void) {
    s32 var_s1 = 1;
    s32 var_s0 = 0;

    ModelAnim_SetAnimation(&D_86700940, 0);

    while (var_s1 != 0) {
        Minigame_Sample8Viewer_PollInput();
        Minigame_Sample8Viewer_UpdateCameraControls();

        var_s0++;

        if (gPlayer1Controller->buttonPressed & 0x1000) {
            var_s1 = 0;
        }

        if (var_s0 == 0x3C) {
            var_s0 = 0;
            ModelAnim_ClearEventTrack(&D_86700940);
            ModelAnim_SetEventTrack(&D_86700940, 0xA);
        }

        Minigame_Sample8Viewer_DrawFrame(1);
    }
}

void Minigame_Sample8Viewer_EndingLoop(void) {
    s32 i;

    ModelAnim_SetAnimation(&D_86700940, 0xB);
    ModelAnim_SetEventTrack(&D_86700940, 0xB);

    while (ModelAnim_IsFinished(&D_86700940) == 0) {
        Minigame_Sample8Viewer_PollInput();
        Minigame_Sample8Viewer_DrawFrame(2);
    }

    StageFade_StartFromTransparent(0x1E);

    for (i = 0; i < 30; i++) {
        Minigame_Sample8Viewer_PollInput();
        Minigame_Sample8Viewer_DrawFrame(2);
    }
}

void Minigame_Sample8Viewer_Init(void) {
    MemoryBlock* sp1C = MainPool_AllocState(main_pool_get_available(), 0);

    D_86700934 = process_geo_layout(sp1C, &D_86700840);
    MainPool_FinalizeAllocation(sp1C);
    ModelRenderer_InitDisplayRoots();
    ModelRenderer_AttachDisplayObject(&D_86700940);
    PokeIcon_OpenModelArchives();
    D_86700930 = Model_LoadByArchiveIndex(0x19);
    Model_InitDisplayObject(&D_86700940, 0, 0x19, D_86700930->unk_08->unk_00[0]);
    ModelAnim_SetAnimation(&D_86700940, 0);
    Minigame_Sample8Viewer_InitCamera();
}

s32 Minigame_Sample8Viewer(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('MINI');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    Font_Init(6, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);

    FRAGMENT_LOAD(fragment31);
    Fragment_Load((((u32)D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, pokedex_area_model_ROM_START);

    Minigame_Sample8Viewer_Init();
    StageContext_Activate(sp24);
    Minigame_Sample8Viewer_OpeningLoop();
    Minigame_Sample8Viewer_PlayingLoop();
    Minigame_Sample8Viewer_EndingLoop();
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('MINI');

    return 0;
}
