
#include "cup_select.h"
#include "src/geo_render.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/save_data.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/geo_layout.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"

#define SELECTED_CUP 0
#define SELECTING_DIVISION 1
#define SELECTED_DIVISION 2

static BinArchive* cup_background_bin;
static void* cup_background;
static GraphNode* render_node;
static GraphNode* division_render;
static GraphNode* arrow_render;
static DisplayObject division_listings[4];
static DisplayObject arrows[3];
static ModeSettings D_82E023A0;
static s16 hovered_division;
static s16 latest_unlocked_division;

static u32 render_block[] = {
    0x0C000000, 0x05000000, 0x0B00002D,  0x00000000, 0x028001E0, 0x00000000, 0xFDBD0000, 0x00000243,
    0x05000000, 0x0D000000, 0x05000000,  0x14000000, 0x00000000, 0xFFFFFF32, 0x16FFFFFF, 0x0F000002,
    0x05000000, 0x0A000000, &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};
static u8* D_82E01170[] = { D_3000000, D_3009000, D_3012000, D_301B000 };
static Vtx D_82E01180[] = {
    VTX(-128, 36, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-128, 12, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 12, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 36, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E011C0[] = {
    VTX(-64, 36, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 12, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 12, 0, 4096, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 36, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01200[] = {
    VTX(0, 36, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 12, 0, 4096, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 12, 0, 6144, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 36, 0, 6144, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01240[] = {
    VTX(64, 36, 0, 6144, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 12, 0, 6144, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, 12, 0, 8192, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, 36, 0, 8192, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01280[] = {
    VTX(-128, 12, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-128, -12, 0, 0, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -12, 0, 2048, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 12, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E012C0[] = {
    VTX(-64, 12, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -12, 0, 2048, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -12, 0, 4096, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 12, 0, 4096, 768, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01300[] = {
    VTX(0, 12, 0, 4096, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -12, 0, 4096, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -12, 0, 6144, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 12, 0, 6144, 768, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01340[] = {
    VTX(64, 12, 0, 6144, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -12, 0, 6144, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, -12, 0, 8192, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, 12, 0, 8192, 768, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01380[] = {
    VTX(-128, -12, 0, 0, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-128, -36, 0, 0, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -36, 0, 2048, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -12, 0, 2048, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E013C0[] = {
    VTX(-64, -12, 0, 2048, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -36, 0, 2048, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -36, 0, 4096, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -12, 0, 4096, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01400[] = {
    VTX(0, -12, 0, 4096, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -36, 0, 4096, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -36, 0, 6144, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -12, 0, 6144, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01440[] = {
    VTX(64, -12, 0, 6144, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -36, 0, 6144, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, -36, 0, 8192, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, -12, 0, 8192, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82E01480[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 0, 0, 63, 23, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E01180, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 64, 0, 127, 23, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E011C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 128, 0, 191, 23, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E01200, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 192, 0, 255, 23, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E01240, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 0, 24, 63, 47, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E01280, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 64, 24, 127, 47, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E012C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 128, 24, 191, 47, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82E01300, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 192, 24, 255, 47, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82E01340, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 0, 48, 63, 71, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E01380, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 64, 48, 127, 71, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E013C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 128, 48, 191, 71, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82E01400, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 192, 48, 255, 71, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82E01440, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 division_block[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82E01180, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, CupSelect_IconGeoPostCallback, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_82E01838[] = {
    VTX(-38, 18, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-38, 0, 0, 0, 576, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(38, 0, 0, 2432, 576, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(38, 18, 0, 2432, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-38, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-38, -18, 0, 0, 576, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(38, -18, 0, 2432, 576, 0xFF, 0xFF, 0xFF, 0xFF), VTX(38, 0, 0, 2432, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82E018B8[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_82E01838, 8, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 76, 18, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F000AB0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 76, 18, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};
static u32 arrow_block[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82E01838, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, CupSelect_DividerGeoPostCallback, 0x00000000, 0x06000000, 0x01000000,
};

void CupSelect_PollController(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void func_82E00050(void) {
}

void CupSelect_DrawSelectionCorners(s16 left, s16 bottom, s16 right, s16 top, u8 r, u8 g, u8 b, u8 alpha) {
    static s16 pulsing_timer = 0;

    s16 pulse = SINS(pulsing_timer) * 2;
    UNUSED s32 pad[2];

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, r, g, b, alpha);

    Gfx_DrawTextureIa8((left + pulse) - 8, (bottom + pulse) - 8, 0x10, 0x10, bottom_left_sc_tex, 0x10, 0);
    Gfx_DrawTextureIa8((left + pulse) - 8, ((bottom + top) - pulse) - 8, 0x10, 0x10, top_left_sc_tex, 0x10, 0);
    Gfx_DrawTextureIa8(((left + right) - pulse) - 8, (bottom + pulse) - 8, 0x10, 0x10, bottom_right_sc_tex, 0x10, 0);
    Gfx_DrawTextureIa8(((left + right) - pulse) - 8, ((bottom + top) - pulse) - 8, 0x10, 0x10, top_right_sc_tex, 0x10, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    pulsing_timer += 0x2000;
}

s32 CupSelect_IconGeoPostCallback(s32 arg0, UNUSED unk_func_80011B94* arg1) {
    s32 temp_a3;
    s32 var_t0;

    if (arg0 == 5) {
        temp_a3 = D_8006F09C->node.callbackArg;
        if (latest_unlocked_division >= temp_a3) {
            var_t0 = 0xFF;
        } else {
            var_t0 = 0x80;
        }

        gDPPipeSync(gDisplayListHead++);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, var_t0);
        gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_82E01170[temp_a3]));
        gSPDisplayList(gDisplayListHead++, D_82E01480);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

s32 CupSelect_DividerGeoPostCallback(s32 arg0, UNUSED unk_func_80011B94* arg1) {
    s32 var_a3;

    if (arg0 == 5) {
        s32 tmp = D_8006F09C->node.callbackArg;

        if (tmp < latest_unlocked_division) {
            var_a3 = 0xFF;
        } else {
            var_a3 = 0x80;
        }

        gDPPipeSync(gDisplayListHead++);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, var_a3);
        gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_3024000));
        gSPDisplayList(gDisplayListHead++, D_82E018B8);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

void CupSelect_RenderFrame(s32 mode, s32 counter) {
    BgStage_DrawFrame();
    Gfx_DrawTiledRgba16Image(cup_background);
    Geo_RenderRootNode(render_node);
 
    if (mode == SELECTED_CUP) {
        if ((counter >= 0) && (counter < 11)) {
            division_listings[0].rotation.y = ((10 - counter) * -0x5000) / 10;
        }

        if ((counter >= 2) && (counter < 13)) {
            arrows[0].rotation.y = ((12 - counter) * -0x5000) / 10;
        }

        if ((counter >= 4) && (counter < 15)) {
            division_listings[1].rotation.y = ((14 - counter) * -0x5000) / 10;
        }

        if ((counter >= 6) && (counter < 17)) {
            arrows[1].rotation.y = ((16 - counter) * -0x5000) / 10;
        }

        if ((counter >= 8) && (counter < 19)) {
            division_listings[2].rotation.y = ((18 - counter) * -0x5000) / 10;
        }

        if ((counter >= 10) && (counter < 21)) {
            arrows[2].rotation.y = ((20 - counter) * -0x5000) / 10;
        }

        if ((counter >= 12) && (counter < 23)) {
            division_listings[3].rotation.y = ((22 - counter) * -0x5000) / 10;
        }
    }

    if (mode == SELECTED_DIVISION) {
        if ((counter >= 0) && (counter < 11)) {
            division_listings[0].rotation.y = ((counter - 0) * 0x5000) / 10;
        }

        if ((counter >= 2) && (counter < 13)) {
            arrows[0].rotation.y = (((counter - 2) * 0x5000)) / 10;
        }

        if ((counter >= 4) && (counter < 15)) {
            division_listings[1].rotation.y = (((counter - 4) * 0x5000)) / 10;
        }

        if ((counter >= 6) && (counter < 17)) {
            arrows[1].rotation.y = (((counter - 6) * 0x5000)) / 10;
        }

        if ((counter >= 8) && (counter < 19)) {
            division_listings[2].rotation.y = (((counter - 8) * 0x5000)) / 10;
        }

        if ((counter >= 10) && (counter < 21)) {
            arrows[2].rotation.y = (((counter - 10) * 0x5000)) / 10;
        }

        if ((counter >= 12) && (counter < 23)) {
            division_listings[3].rotation.y = (((counter - 12) * 0x5000)) / 10;
        }
    }

    if (mode == SELECTING_DIVISION) {
        CupSelect_DrawSelectionCorners(208, (hovered_division * 108) + 50, 224, 56, 0xFF, 0xF0, 0x64, 0xFF);
    }
    BgStage_AdvanceFrame();
}

void CupSelect_BuildDivisionList(void) {
    s32 i;
    DisplayObject* division_listing;
    DisplayObject* arrow;

    for (division_listing = &division_listings[0], i = 0; i < 4; i++, division_listing++) {
        Model_InitDisplayObject(division_listing, 0, 0, division_render);
        division_listings[i].rotation.y = -0x5000;
    }

    Vec3f_SetComponentsDuplicate(&division_listings[0].position, 0.0f, 162.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&division_listings[1].position, 0.0f, 54.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&division_listings[2].position, 0.0f, -54.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&division_listings[3].position, 0.0f, -162.0f, -579.0f);

    for (arrow = &arrows[0], i = 0; i < 3; i++, arrow++) {
        Model_InitDisplayObject(arrow, 0, 0, arrow_render);
        arrows[i].rotation.y = -0x5000;
    }

    Vec3f_SetComponentsDuplicate(&arrows[0].position, 0.0f, 108.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&arrows[1].position, 0.0f, 0, -579.0f);
    Vec3f_SetComponentsDuplicate(&arrows[2].position, 0.0f, -108.0f, -579.0f);
}

s32 CupSelect_HandleInput(void) {
    s32 action = 'exec';

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        Audio_PlaySoundEffectById(0x26);
        D_800AE540.unk_0002 = hovered_division;
        action = 'slct';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        action = 'quit';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        if (hovered_division > 0) {
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            hovered_division--;
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN) && (hovered_division < latest_unlocked_division)) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        hovered_division++;
    }
    return action;
}

s32 CupSelect_Loop(void) {
    s16 i;
    s32 state = 'exec';
    s32 selected_division;

    CupSelect_BuildDivisionList();
    hovered_division = latest_unlocked_division;

    for (i = 0; i < 23; i++) {
        CupSelect_PollController();
        CupSelect_RenderFrame(0, i);
    }

    while (state == 'exec') {
        CupSelect_PollController();
        CupSelect_RenderFrame(1, 0);
        state = CupSelect_HandleInput();
    }

    selected_division = state == 'slct';
    if (selected_division) {
        for (i = 0; i < 23; i++) {
            CupSelect_PollController();
            CupSelect_RenderFrame(2, i);
        }
    // quit out
    } else {
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(8);
        while (StageContext_GetFadeMode() != 1) {
            CupSelect_PollController();
            CupSelect_RenderFrame(1, 0);
        }
        StageLoader_RunFrames(2);
    }
    return selected_division;
}

void CupSelect_InitGeoLayouts(void) {
    MemoryBlock* memory_block = MainPool_AllocState(main_pool_get_available(), 0);
    s32 i;
    DisplayObject* cursor;

    render_node = process_geo_layout(memory_block, &render_block);
    division_render = process_geo_layout(memory_block, &division_block);
    arrow_render = process_geo_layout(memory_block, &arrow_block);
    MainPool_FinalizeAllocation(memory_block);
    ModelRenderer_InitDisplayRoots();

    for (cursor = &division_listings[0], i = 0; i < 4; cursor++, i++) {
        ModelRenderer_AttachDisplayObject(cursor);
        division_listings[i].node.callbackArg = i;
    }

    for (cursor = &arrows[0], i = 0; i < 3; cursor++, i++) {
        ModelRenderer_AttachDisplayObject(cursor);
        arrows[i].node.callbackArg = i;
    }
}

s32 CupSelect_Main(UNUSED s32 arg0, UNUSED s32 arg1) {
    s16 background_file = -1;
    s32 did_select = 1;

    switch (D_800AE540.unk_0000) {
        case 3:
            background_file = 9;
            break;

        case 6:
            background_file = 0xC;
            break;
    }

    if (background_file != -1) {
        main_pool_push_state('LVSL');

        Font_Init(0x10, 0);
        Save_EnsureBankLoaded(2);
        Save_GetModeSettings(&D_82E023A0, D_800AE540.unk_11F2);
        if (D_800AE540.unk_0000 == 3) {
            latest_unlocked_division = D_82E023A0.unk_05;
        } else {
            latest_unlocked_division = D_82E023A0.unk_06;
        }
        if (latest_unlocked_division == 4) {
            latest_unlocked_division -= 1;
        }

        ASSET_LOAD(D_1000000, common_menu1_ui, 0);
        ASSET_LOAD(D_2000000, common_menu2_ui, 0);
        ASSET_LOAD(D_3000000, cup_ball_select_ui, 0);

        cup_background_bin = ASSET_LOAD2(backgrounds, 1, 1);
        cup_background = BinArchive_GetFile(cup_background_bin, background_file);

        CupSelect_InitGeoLayouts();
        StageLoader_UpdateSegments();
        did_select = CupSelect_Loop();
        StageLoader_WaitForRetrace();

        main_pool_pop_state('LVSL');
    }
    return did_select;
}
