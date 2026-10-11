#include "ranking_debug_test.h"
#include "src/geo_render.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/jpeg_stream.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/fragments/minigame_actor_framework/minigame_actor_framework.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/geo_layout.h"

static u32 D_86D00530[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E,  0x00000000, 0x014000F0, 0x0000000F, 0x00000000, 0x00000000, 0x05000000,
    0x0D000000, 0x05000000, 0x0F000002,  0x05000000, 0x1F00FFFF, 0x00000000, 0x00000000, 0x00000000, 0x00640064,
    0x00640000, 0x05000000, 0x06000000,  0x06000000, 0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003,
    0x05000000, 0x0A000000, &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000, 0x00000000,
};

void miniUnkInitCamera(void) {
    D_87906054 = D_87906050->node.children;

    miniCameraXRot = 0xA00;
    miniCameraYRot = 0;
    miniCameraDistance = 0x17C;
    miniCameraFov = 0x1E;
    miniCameraNear = 0x32;
    miniCameraFar = 0x1900;

    miniCameraCoords.x = 0;
    miniCameraCoords.y = 0x1E;
    miniCameraCoords.z = 0;

    miniUpdateCamera();
}

void miniUnkUpdateCamera(void) {
    minigameDebuggModeControl();
    miniUpdateCamera();
}

void miniUnkDrawHUB(UNUSED s32 arg0) {
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 1);
    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(&D_87906050->node);

    if (miniDebugMode != 0) {
        showDebuggCameraInfo();
    }

    BgStage_AdvanceFrame();
}

void miniUnkStartFadeIn(void) {
    StageFade_StartFromOpaque(0x10);
    miniTutoScreenState = 3;
}

void miniUnkControls(void) {
    s32 var_s1 = 1;

    while (var_s1 != 0) {
        MiniActor_ReadControllerInputs();

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            miniRankingActorSetup1st(0.2f, 0.0f, 50.0f, 50.0f, 0x2000, 0, 0x1000);
        }

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            miniRankingActorSetup2nd(0.2f, 50.0f, 50.0f, 50.0f, 0, 0, 0);
        }

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_CLEFT)) {
            miniRankingActorSetup3rd(0.2f, -50.0f, 50.0f, 50.0f, -0x6000, 0, 0x2000);
        }

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_Z)) {
            miniDebugMode = (miniDebugMode + 1) & 1;
        }

        if ((miniDebugMode == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_START)) {
            minigameState = 1;
        }

        miniRankingActorsUpdate();
        miniUnkUpdateCamera();

        if ((miniDebugMode == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_CDOWN)) {
            var_s1 = 0;
        }

        miniUnkDrawHUB(1);
    }
}

void miniUnkFadeOutLoop(void) {
    s32 i;

    StageFade_StartFromTransparent(0x1E);

    for (i = 0; i < 30; i++) {
        MiniActor_ReadControllerInputs(); //  inputs
        miniUnkDrawHUB(2);
    }
}

void miniUnkInit(void) {
    UNUSED s32 pad[2];
    MemoryBlock* sp1C = MainPool_AllocState(main_pool_get_available(), 0);

    D_87906050 = process_geo_layout(sp1C, &D_86D00530);
    MainPool_FinalizeAllocation(sp1C);
    ModelRenderer_InitDisplayRoots();
    PokeIcon_OpenModelArchives();
    miniRankingActorsInit();
    miniUnkInitCamera();
}

s32 Minigame_RankingDebugTest(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('MINI');

    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    Font_Init(6, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    FRAGMENT_LOAD(fragment31);
    Fragment_Load((((u32)D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, pokedex_area_model_ROM_START);

    miniUnkInit();
    StageContext_Activate(sp24);
    miniUnkStartFadeIn();
    miniUnkControls();
    miniUnkFadeOutLoop();
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('MINI');

    return 0;
}
