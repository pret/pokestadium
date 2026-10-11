#include "demo_scenes.h"
#include "src/geo_render.h"
#include "src/model_animation.h"
#include "src/geo_layout.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/save_data.h"
#include "src/jpeg_stream.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/DDC0.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static u32 D_86B0E250[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E,  0x00000000, 0x014000F0, 0x00000032, 0x00000000, 0x00000118,
    0x05000000, 0x0D000000, 0x05000000,  0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003,
    0x05000000, 0x0A000000, &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};

static unk_D_86002F30* D_86B106B0;
static GraphNode* D_86B106B4;
static DisplayObject D_86B106B8;
static unk_D_86002F34_00C* D_86B10820;
static BinArchive* D_86B10824;
static u8* D_86B10828;
static u8 D_86B1082C;
static ModeSettings D_86B10830;

void MewtwoIntro_DrawOverlay(void) {
}

void MewtwoIntro_InitCamera(void) {
    D_86B10820 = D_86B106B4->children;
    Vec3f_SetComponentsDuplicate(&D_86B10820->unk_60.at, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&D_86B10820->unk_60.eye, 0.0f, 0.0f, 200.0f);
    D_86B10820->unk_24.near = 16.0f;
    D_86B10820->unk_24.far = 32768.0f;
    D_86B10820->unk_24.fovy = 45.0f;
}

void MewtwoIntro_ReadControllerInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void MewtwoIntro_DrawBackgroundTiles(u8* arg0) {
    s32 i;
    s32 j;

    if (1) {}

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGB, G_CC_DECALRGB);

    gDPPipeSync(gDisplayListHead++);

    for (i = 0; i < 15; i++) {
        for (j = 0; j < 20; j++, arg0 += 0x200) {
            Gfx_DrawTextureRgba16(j * 0x10, i * 0x10, 0x10, 0x10, arg0, 0x10, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void MewtwoIntro_RenderFrame(void) {
    BgStage_DrawFrame();
    MewtwoIntro_DrawBackgroundTiles(D_86B10828);
    GfxImage_ClearDepthRectangle(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(D_86B106B4);
    MewtwoIntro_DrawOverlay();
    BgStage_AdvanceFrame();
}

s32 MewtwoIntro_UpdateFade(void) {
    s32 var_v0;

    if ((D_86B106B8.transformAnim.frameFixed >> 0x10) >= 0x5F) {
        Model_SetMaterialColor(&D_86B106B8, 0, 0, 0, D_86B1082C += 0x14);
    }

    if ((D_86B106B8.transformAnim.frameFixed >> 0x10) == 0x64) {
        StageContext_SetClearColor(1);
        StageFade_StartFromTransparent(3);
    }

    var_v0 = ModelAnim_IsAnimationDone(&D_86B106B8) != 0;
    if (var_v0) {
        return 1;
    }
}

void MewtwoIntro_RunLoop(void) {
    s32 var_s0 = 1;

    StageFade_StartFromOpaque(0xC);
    Audio_PlayMusicIfChanged(0x30);

    while (var_s0 != 0) {
        MewtwoIntro_ReadControllerInput();
        if (MewtwoIntro_UpdateFade() != 0) {
            var_s0 = 0;
        }
        MewtwoIntro_RenderFrame();
    }

    StageLoader_RunFrames(2);
}

void MewtwoIntro_InitScene(void) {
    MemoryBlock* sp1C = MainPool_AllocState(main_pool_get_available(), 0);

    D_86B106B4 = process_geo_layout(sp1C, &D_86B0E250);

    MainPool_FinalizeAllocation(sp1C);
    ModelRenderer_InitDisplayRoots();
    MewtwoIntro_InitCamera();
    ModelRenderer_AttachDisplayObject(&D_86B106B8);
    PokeIcon_OpenModelArchives();

    D_86B106B0 = Model_LoadByArchiveIndex(0xD6);
    Model_InitDisplayObject(&D_86B106B8, 0, 0xD6, D_86B106B0->unk_08->unk_00[0]);
    ModelAnim_SetAnimation(&D_86B106B8, 1);
    Vec3f_SetComponentsDuplicate(&D_86B106B8.position, 0.0f, 0.0f, 0.0f);
    D_86B1082C = 0;
}

s32 Stage_ShowMewtwoIntro(void) {
    unk_func_80007444* sp24;

    main_pool_push_state('MTWO');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    Font_Init(6, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    FRAGMENT_LOAD(fragment31);

    Save_EnsureBankLoaded(2);
    Save_GetModeSettings(&D_86B10830, D_800AE540.unk_11F2);

    if (D_800AE540.unk_11F2 == 1) {
        D_86B10824 = ASSET_LOAD2(backgrounds, 1, 1);
        D_86B10828 = BinArchive_GetFile(D_86B10824, 2);
    } else if (D_86B10830.unk_00 & 0x100) {
        D_86B10824 = ASSET_LOAD2(backgrounds, 1, 1);
        D_86B10828 = BinArchive_GetFile(D_86B10824, 1);
    } else {
        D_86B10824 = ASSET_LOAD2(backgrounds, 1, 1);
        D_86B10828 = BinArchive_GetFile(D_86B10824, 2);
    }

    MewtwoIntro_InitScene();
    StageContext_Activate(sp24);
    MewtwoIntro_RunLoop();
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('MTWO');

    return 0;
}
