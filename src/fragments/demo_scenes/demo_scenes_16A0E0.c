#include "demo_scenes.h"
#include "src/geo_render.h"
#include "src/model_animation.h"
#include "src/geo_layout.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_loop_point.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_86B10BD0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} unk_D_86B10BD0; // size >= 0xC

typedef struct unk_D_86B10BE0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} unk_D_86B10BE0; // size >= 0x14

static u32 D_86B0E2B0[] = {
    0xA4AAA4E1, 0xA4C7A4C8, 0xA4A6A1AA, 0x20A5C9A1, 0xBCA5C9A1, 0xBCA4CE0A, 0xA5B2A1BC, 0xA5E0A5DC, 0xA1BCA5A4,
    0xA4F2A5B2, 0xA5C3A5C8, 0xA4C0A1AA, 0x00000000, 0x4742A5D3, 0xA5EBA4CE, 0xA5B2A1BC, 0xA5E0A5DC, 0xA1BCA5A4,
    0xA4AC0A20, 0x20A5B9A5, 0xD4A1BCA5, 0xC9A5A2A5, 0xC3A5D7A1, 0xAA000000, 0xA4B9A4B4, 0xA4A4A4BE, 0xA1AA20A5,
    0xC9A1BCA5, 0xC9A5EAA5, 0xAAA4CE0A, 0xA5B2A1BC, 0xA5E0A5DC, 0xA1BCA5A4, 0xA4F2A5B2, 0xA5C3A5C8, 0xA4C0A1AA,
    0x00000000, 0x4742A5D3, 0xA5EBA4CE, 0xA5B2A1BC, 0xA5E0A5DC, 0xA1BCA5A4, 0xA4AC0AA4, 0xB5A4E9A4, 0xCBA5B9A5,
    0xD4A1BCA5, 0xC9A5A2A5, 0xC3A5D7A4, 0xC0A1AA00,
};

static u32 D_86B0E374[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E,  0x00000000, 0x014000F0, 0x00000000, 0x00000000, 0x00000118,
    0x05000000, 0x0D000000, 0x05000000,  0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003,
    0x05000000, 0x0A000000, &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};

static char** D_86B10840;
static unk_D_86002F30* D_86B10844;
static GraphNode* D_86B10848;
static DisplayObject D_86B10850;
static unk_D_86002F34_00C* D_86B109B8;
static BinArchive* D_86B109BC;
static u8* D_86B109C0;
static s8 D_86B109C8[0x100];
static s8 D_86B10AC8[0x100];
static s16 D_86B10BC8;
static s16 D_86B10BCA;
static s16 D_86B10BCC;
static unk_D_86B10BD0 D_86B10BD0;
static unk_D_86B10BE0 D_86B10BE0;

void FirstClearBonus_InitCamera(void) {
    D_86B109B8 = D_86B10848->children;

    D_86B10BC8 = 0;
    D_86B10BCA = 0;
    D_86B10BCC = 0x78;

    Camera_ComputeEyeFromAngles(&D_86B109B8->unk_60.at, &D_86B109B8->unk_60.eye, D_86B10BCC, D_86B10BC8, D_86B10BCA);

    D_86B109B8->unk_24.near = 50.0f;
    D_86B109B8->unk_24.far = 6400.0f;
}

void FirstClearBonus_InitState(void) {
    D_86B10BD0.unk_00 = 0;
    D_86B10BD0.unk_04 = 0;
    D_86B10BD0.unk_08 = 0;
    D_86B10BE0.unk_10 = 0xA;
}

void func_86B0A81C(void) {
}

void FirstClearBonus_DrawDialogFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 sp48;
    s16 sp44;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x10) {
        var_s3 = 8;
    } else {
        var_s3 = arg2 / 2;
    }

    if (arg3 >= 0x10) {
        var_s2 = 8;
    } else {
        var_s2 = arg3 / 2;
    }

    sp48 = arg2 - (var_s3 * 2);
    sp44 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A60, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028AA0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20289E0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A20, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3,
                  0x2000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((sp48 > 0) && (sp44 > 0)) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp48, var_s2, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0, arg1 + var_s3, arg2, sp44, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0 + var_s3, (arg1 + var_s3) + sp44, sp48, var_s2, arg4, arg5, arg6, arg7);
    } else if (sp48 > 0) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp48, arg3, arg4, arg5, arg6, arg7);
    } else if (sp44 > 0) {
        Gfx_FillRectRgba(arg0, arg1 + var_s2, arg2, sp44, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void FirstClearBonus_ShowDialogBox(void) {
    D_86B10BE0.unk_00 = 0xFF;
}

void FirstClearBonus_HideDialogBox(void) {
    D_86B10BE0.unk_00 = 0;
}

s32 FirstClearBonus_RevealNextChar(void) {
    if (D_86B109C8[D_86B10BE0.unk_04] == 0) {
        return 1;
    }

    D_86B10AC8[D_86B10BE0.unk_04++] = D_86B109C8[D_86B10BE0.unk_04];

    if (D_86B109C8[D_86B10BE0.unk_04] == 0) {
        return 1;
    }

    D_86B10AC8[D_86B10BE0.unk_04++] = D_86B109C8[D_86B10BE0.unk_04];
    return 0;
}

void FirstClearBonus_DrawDialogBox(void) {
    FirstClearBonus_DrawDialogFrame(0x3C, 0xBE - (D_86B10BE0.unk_10 / 2), D_86B10BE0.unk_0C, D_86B10BE0.unk_10, 0x50, 0x50, 0xF0, 0x80);
}

void FirstClearBonus_DrawDialogText(void) {
    Font_BeginTranslucentTextRendering();
    Font_SetActive(2, 0);
    Font_SetLineHeight(0x10);
    Font_Printf(0x56, 0xAF, "%s", D_86B10AC8);
    Font_EndTexturedTextRendering();
}

void FirstClearBonus_UpdateDialogSequence(void) {
    s32 i;

    switch (D_86B10BE0.unk_00) {
        case 0x0:
            if (D_800AE540.unk_0000 == 0x16) {
                sprintf(D_86B109C8, Text_GetString(NULL, 0, D_86B10840, 0x91));
            } else {
                sprintf(D_86B109C8, Text_GetString(NULL, 0, D_86B10840, 0x93));
            }

            D_86B10BE0.unk_04 = 0;
            D_86B10BE0.unk_08 = 0;
            D_86B10BE0.unk_0C = 0xC8;
            D_86B10BE0.unk_10 = 0xA;

            // clang-format off
            for (i = 0; i < 255; i++) { D_86B10AC8[i] = 0; }
            // clang-format on

            FirstClearBonus_DrawDialogBox();
            D_86B10BE0.unk_00++;
            break;

        case 0x1:
            D_86B10BE0.unk_10 = Math_StepToS32(D_86B10BE0.unk_10, 0x28, 8, 8);
            if (D_86B10BE0.unk_10 == 0x28) {
                D_86B10BE0.unk_00++;
            }
            FirstClearBonus_DrawDialogBox();
            break;

        case 0x2:
            FirstClearBonus_DrawDialogBox();
            if (FirstClearBonus_RevealNextChar() != 0) {
                D_86B10BE0.unk_00++;
            }
            FirstClearBonus_DrawDialogText();
            break;

        case 0x3:
            FirstClearBonus_DrawDialogBox();
            FirstClearBonus_DrawDialogText();

            if (D_86B10BE0.unk_08++ == 0x3C) {
                if (D_800AE540.unk_0000 == 0x16) {
                    sprintf(D_86B109C8, Text_GetString(NULL, 0, D_86B10840, 0x92));
                } else {
                    sprintf(D_86B109C8, Text_GetString(NULL, 0, D_86B10840, 0x94));
                }

                D_86B10BE0.unk_04 = 0;
                D_86B10BE0.unk_08 = 0;

                // clang-format off
                for (i = 0; i < 255; i++) { D_86B10AC8[i] = 0; }
                // clang-format on

                D_86B10BE0.unk_00++;
            }
            break;

        case 0x4:
            FirstClearBonus_DrawDialogBox();
            if (FirstClearBonus_RevealNextChar() != 0) {
                D_86B10BE0.unk_00++;
            }
            FirstClearBonus_DrawDialogText();
            break;

        case 0x5:
            FirstClearBonus_DrawDialogBox();
            FirstClearBonus_DrawDialogText();

            if (D_86B10BE0.unk_08++ == 0x41) {
                D_86B10BE0.unk_00 = 0xFF;
            }
            break;

        case 0xFF:
            D_86B10BE0.unk_10 = Math_StepToS32(D_86B10BE0.unk_10, 0, 8, 8);
            if (D_86B10BE0.unk_10 >= 0xB) {
                FirstClearBonus_DrawDialogBox();
            }
            break;
    }
}

void FirstClearBonus_ReadControllerInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void func_86B0B4C8(void) {
}

void FirstClearBonus_DrawBackgroundTiles(u8* arg0) {
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

void FirstClearBonus_RenderFrame(void) {
    BgStage_DrawFrame();
    FirstClearBonus_DrawBackgroundTiles(D_86B109C0);
    GfxImage_ClearDepthRectangle(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(D_86B10848);
    FirstClearBonus_UpdateDialogSequence();
    BgStage_AdvanceFrame();
}

s32 FirstClearBonus_UpdateScene(void) {
    s32 sp24 = 0;

    switch (D_86B10BD0.unk_00) {
        case 0:
            D_86B10850.node.renderFlags |= 0x20;
            D_86B10850.node.flags |= 1;
            D_86B10BD0.unk_00++;
            break;

        case 1:
            if ((D_86B10850.transformAnim.frameFixed >> 0x10) == 0xA) {
                Audio_StartMusicTrack(0x38);
            }

            if ((D_86B10850.transformAnim.frameFixed >> 0x10) == 0x72) {
                D_86B10BD0.unk_08 = 0;
                D_86B10850.node.renderFlags &= 0xFFDF;
                FirstClearBonus_HideDialogBox();
                Audio_StartMusicTrack(0x13);
                D_86B10BD0.unk_00++;
            }
            break;

        case 2:
            if (D_86B10BE0.unk_00 == 0xFF) {
                D_86B10BD0.unk_08 = 0;
                D_86B10850.node.renderFlags |= 0x20;
                FirstClearBonus_ShowDialogBox();
                D_86B10BD0.unk_00++;
            }
            break;

        case 3:
            if (ModelAnim_IsAnimationDone(&D_86B10850) != 0) {
                D_86B10BD0.unk_00++;
            }
            break;

        case 4:
            sp24 = 1;
            break;
    }

    return sp24;
}

void FirstClearBonus_RunLoop(void) {
    s32 i;
    s32 var_s2 = 1;

    StageContext_SetClearColor(1);
    StageFade_StartFromOpaque(0xA);

    for (i = 0; i < 10; i++) {
        FirstClearBonus_ReadControllerInput();
        FirstClearBonus_RenderFrame();
    }

    while (var_s2 != 0) {
        FirstClearBonus_ReadControllerInput();
        if (FirstClearBonus_UpdateScene() != 0) {
            var_s2 = 0;
        }
        FirstClearBonus_RenderFrame();
    }

    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromTransparent(8);

    for (i = 0; i < 8; i++) {
        FirstClearBonus_ReadControllerInput();
        FirstClearBonus_RenderFrame();
    }

    StageLoader_RunFrames(2);
}

void FirstClearBonus_InitScene(void) {
    MemoryBlock* temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);

    D_86B10848 = process_geo_layout(temp_v0, &D_86B0E374);
    MainPool_FinalizeAllocation(temp_v0);

    ModelRenderer_InitDisplayRoots();
    FirstClearBonus_InitCamera();
    FirstClearBonus_InitState();
    FirstClearBonus_ShowDialogBox();
    ModelRenderer_AttachDisplayObject(&D_86B10850);
    PokeIcon_OpenModelArchives();

    if (D_800AE540.unk_0000 == 0x16) {
        D_86B10844 = Model_LoadByArchiveIndex(0xD5);
        Model_InitDisplayObject(&D_86B10850, 0, 0xD5, D_86B10844->unk_08->unk_00[0]);
    } else {
        D_86B10844 = Model_LoadByArchiveIndex(0xD4);
        Model_InitDisplayObject(&D_86B10850, 0, 0xD4, D_86B10844->unk_08->unk_00[0]);
    }

    ModelAnim_SetAnimation(&D_86B10850, 0);

    D_86B10850.node.renderFlags &= ~0x20;
    D_86B10850.node.flags &= ~1;

    Vec3f_SetComponentsDuplicate(&D_86B10850.position, 0.0f, 11.0f, -105.0f);
}

s32 Stage_ShowFirstClearBonusScene(void) {
    unk_func_80007444* sp24;

    main_pool_push_state('GBOY');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    Font_Init(2, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    FRAGMENT_LOAD(fragment31);

    Text_InitStringTables();
    D_86B10840 = Text_GetStringTable(0x1E);

    if (D_800AE540.unk_0000 == 0x16) {
        D_86B109BC = ASSET_LOAD2(backgrounds, 1, 1);
        D_86B109C0 = BinArchive_GetFile(D_86B109BC, 0x12);
    } else {
        D_86B109BC = ASSET_LOAD2(backgrounds, 1, 1);
        D_86B109C0 = BinArchive_GetFile(D_86B109BC, 0x13);
    }

    FirstClearBonus_InitScene();
    StageContext_Activate(sp24);
    FirstClearBonus_RunLoop();
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('GBOY');

    return 0;
}
