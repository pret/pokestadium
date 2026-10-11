#include "gym_leader_castle_clear.h"
#include "src/geo_render.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/ui_graphics.h"
#include "src/jpeg_stream.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"

s32 Glc_GeoSpriteCallback(s32, GraphNode*);
s32 Glc_GeoBannerCallback(s32, GraphNode*);

typedef struct unk_D_83101E6C {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
} unk_D_83101E6C; // size = 0x14

typedef struct CircleTransition {
    /* 0x00 */ s16 fade_state;
    /* 0x02 */ s16 width;
    /* 0x04 */ s16 circle_height;
    /* 0x08 */ f32 ratio;
} CircleTransition; // size = 0xC

typedef struct FadeTimer {
    /* 0x00 */ s16 mode;
    /* 0x02 */ s16 timer;
    /* 0x04 */ s16 fade;
} FadeTimer; // size = 0x8

static BinArchive* background;
static u8* bin_background;
static s16 stage_fade_mode;
static s16 D_83101EEA;
static s16 tracking_icon_on;
static s16 D_83101EEE;
static s16 D_83101EF0;
static GraphNode* D_83101EF4;
static GraphNode* D_83101EF8;
static GraphNode* D_83101EFC;
static unk_D_83101F00 D_83101F00[2];
static unk_D_83101F00* D_83102210;
static unk_D_83101F00* D_83102214;
static CircleTransition circle_fade;
static FadeTimer background_fade;

static Vtx D_83101BE0[] = {
    VTX(-100, 14, 0, 0, 0, 0x78, 0x32, 0xFF, 0xFF),      VTX(-100, 0, 0, 0, 448, 0xBB, 0x28, 0x8E, 0xFF),
    VTX(100, 0, 0, 6400, 448, 0xBB, 0x28, 0x8E, 0xFF),   VTX(100, 14, 0, 6400, 0, 0x78, 0x32, 0xFF, 0xFF),
    VTX(-100, 0, 0, 0, 0, 0xBB, 0x28, 0x8E, 0xFF),       VTX(-100, -14, 0, 0, 448, 0xFF, 0x1E, 0x1E, 0xFF),
    VTX(100, -14, 0, 6400, 448, 0xFF, 0x1E, 0x1E, 0xFF), VTX(100, 0, 0, 6400, 0, 0xBB, 0x28, 0x8E, 0xFF),
};

static Gfx D_83101C60[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(SHADE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_83101BE0, 8, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_IA, G_IM_SIZ_8b, 200, 14, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F000AF0, G_IM_FMT_IA, G_IM_SIZ_8b, 200, 14, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

static u32 D_83101D08[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_83101BE0, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, Glc_GeoBannerCallback, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};

static Vtx D_83101D40[] = {
    VTX(-64, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -16, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 16, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Gfx D_83101D80[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_BLENDPEDECALA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_83101D40, 4, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_IA, G_IM_SIZ_8b, 128, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

static u32 D_83101DE8[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_83101D40, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, Glc_GeoSpriteCallback, 0x00000000, 0x06000000, 0x01000000,
};

static u32 D_83101E1C[] = {
    0x0C000000,  0x05000000, 0x0B00002D, 0x00000000, 0x028001E0, 0x00000000, 0xFDBD0000,
    0x00000243,  0x05000000, 0x0D000000, 0x05000000, 0x0F000002, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};

static unk_D_83101E6C D_83101E6C[] = {
    { 0xC, 0.0f, 0, 0, 0, 0, 0, 0 },
    { 4, 2.4f, 0xFF, 0, 0, 0, 0, 0 },
    { 4, 2.0f, 0xFF, 0xFF, 0xFF, 0xC8, 0x64, 0 },
    { -1, 2.0f, 0xC8, 0xC8, 0x1E, 0, 0, 0 },
};

void Glc_UpdateSweepObject(DisplayObject* arg0) {
    unk_D_83101F00* ptr = (unk_D_83101F00*)arg0;
    f32 temp_fv0;
    s32 sp1C;
    f32 var_fv0;

    switch (ptr->unk_16A) {
        case 1:
            if (ptr->unk_180 >= 0.0f) {
                ptr->unk_184 -= 0.065f;
            } else {
                ptr->unk_184 += 0.065f;
            }

            sp1C = 0;
            temp_fv0 = ptr->unk_180;
            ptr->unk_180 += ptr->unk_184;

            if (((ptr->unk_180 * temp_fv0) < 0.0f) && (fabsf(ptr->unk_184) < 0.13f)) {
                sp1C = 1;
            }

            if (sp1C == 0) {
                ptr->unk_184 *= 0.75f;
                var_fv0 = (ptr->unk_180 * -520.0f) + 320.0f;
            } else {
                ptr->unk_16A = 2;
                ptr->unk_16C = 0;
                var_fv0 = 320.0f;
            }

            ptr->unk_000.position.x = var_fv0 - 320.0f;
            D_83101EEE = (s16)var_fv0 + 0xC8;
            D_83101EF0 = 0xAC;
            break;

        case 0:
        case 2:
        case 3:
            break;
    }
}

s32 Glc_GeoBannerCallback(s32 arg0, UNUSED GraphNode* arg1) {
    switch (arg0) {
        case 0:
            break;

        case 2:
            Glc_UpdateSweepObject(D_8006F09C);
            break;

        case 5:
            gDPPipeSync(gDisplayListHead++);

            gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_3000000));
            gSPDisplayList(gDisplayListHead++, D_83101C60);

            GeoRender_ApplyMaterialState();
            break;
    }

    return 0;
}

void Glc_UpdateColorKeyframe(unk_D_83101F00* arg0) {
    unk_D_83101E6C* ptr1;
    unk_D_83101E6C* ptr2;
    f32 scale;

    switch (arg0->unk_16A) {
        case 1:
            arg0->unk_16C--;
            ptr1 = &D_83101E6C[arg0->unk_170];
            ptr2 = &D_83101E6C[arg0->unk_170 + 1];

            arg0->unk_172 = ptr2->unk_08 + (((ptr1->unk_08 - ptr2->unk_08) * arg0->unk_16C) / arg0->unk_16E);
            arg0->unk_174 = ptr2->unk_0A + (((ptr1->unk_0A - ptr2->unk_0A) * arg0->unk_16C) / arg0->unk_16E);
            arg0->unk_176 = ptr2->unk_0C + (((ptr1->unk_0C - ptr2->unk_0C) * arg0->unk_16C) / arg0->unk_16E);

            arg0->unk_178 = ptr2->unk_0E + (((ptr1->unk_0E - ptr2->unk_0E) * arg0->unk_16C) / arg0->unk_16E);
            arg0->unk_17A = ptr2->unk_10 + (((ptr1->unk_10 - ptr2->unk_10) * arg0->unk_16C) / arg0->unk_16E);
            arg0->unk_17C = ptr2->unk_12 + (((ptr1->unk_12 - ptr2->unk_12) * arg0->unk_16C) / arg0->unk_16E);

            scale = ptr2->unk_04 + (((ptr1->unk_04 - ptr2->unk_04) * arg0->unk_16C) / arg0->unk_16E);

            if (arg0->unk_16C <= 0) {
                arg0->unk_170++;
                ptr1 = &D_83101E6C[arg0->unk_170];

                arg0->unk_16C = arg0->unk_16E = ptr1->unk_00;
                arg0->unk_172 = ptr1->unk_08;
                arg0->unk_174 = ptr1->unk_0A;
                arg0->unk_176 = ptr1->unk_0C;
                arg0->unk_178 = ptr1->unk_0E;
                arg0->unk_17A = ptr1->unk_10;
                arg0->unk_17C = ptr1->unk_12;

                scale = ptr1->unk_04;

                if (arg0->unk_16C == -1) {
                    arg0->unk_16E = 0;
                    arg0->unk_16A = 2;
                    arg0->unk_16C = arg0->unk_16E;
                }
            }

            Vec3f_SetComponentsDuplicate(&arg0->unk_000.scale, scale, scale, scale);
            break;

        case 0:
        case 2:
        case 3:
            break;
    }
}

s32 Glc_GeoSpriteCallback(s32 arg0, GraphNode* arg1) {
    unk_D_83101F00* ptr = (unk_D_83101F00*)D_8006F09C;

    switch (arg0) {
        case 0:
            break;

        case 2:
            Glc_UpdateColorKeyframe(ptr);
            break;

        case 5:
            gDPPipeSync(gDisplayListHead++);

            gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_30015E0));
            gDPSetPrimColor(gDisplayListHead++, 0, 0, ptr->unk_172, ptr->unk_174, ptr->unk_176, 0xFF);
            gDPSetEnvColor(gDisplayListHead++, ptr->unk_178, ptr->unk_17A, ptr->unk_17C, 0xFF);
            gSPDisplayList(gDisplayListHead++, D_83101D80);

            GeoRender_ApplyMaterialState();
            break;
    }
    return 0;
}

void Glc_InitCircleWipe(void) {
    circle_fade.fade_state = 0;
    circle_fade.width = 0;
    circle_fade.ratio = 7.0f;
}

void Glc_UpdateCircleWipe(void) {
    s32 width_zero;

    switch (circle_fade.fade_state) {
        case 1:
            circle_fade.width--;
            circle_fade.ratio = (circle_fade.width * 7.0f) / circle_fade.circle_height;

            width_zero = circle_fade.width <= 0;
            if (width_zero) {
                circle_fade.fade_state = 2;
                circle_fade.width = circle_fade.circle_height = 0;
                circle_fade.ratio = 0.0f;
            }
            break;

        case 0:
        case 2:
            break;
    }
}

void Glc_DrawCircleWipe(void) {
    s16 temp_y1;
    s16 screen_height;
    s16 temp_z1;
    s16 screen_width;
    s16 width;
    s16 height;
    s16 y1;
    s16 z1;
    s32 texture_step;

    Gfx_SetScissorRect(&gDisplayListHead, 0, 0, 640, 0x1E0);
    if (circle_fade.fade_state == 0) {
        return;
    }

    if ((circle_fade.ratio <= 0.0f) || (circle_fade.fade_state == 2)) {
        gSPDisplayList(gDisplayListHead++, D_8006F4C0);
        gDPSetFillColor(gDisplayListHead++, 0x00010001);
        gDPFillRectangle(gDisplayListHead++, 0, 0, 639, 479);
        return;
    }

    texture_step = ROUND_MAX(1024.0f / circle_fade.ratio);
    width = ROUND_MAX(128.0f * circle_fade.ratio);
    height = ROUND_MAX(128.0f * circle_fade.ratio);

    z1 = (0x280 - width) / 2;
    y1 = (0x1E0 - height) / 2;

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetCombineLERP(gDisplayListHead++, 1, TEXEL0, ENVIRONMENT, 0, 1, TEXEL0, ENVIRONMENT, 0, 1, TEXEL0, ENVIRONMENT,
                      0, 1, TEXEL0, ENVIRONMENT, 0);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3002C00, G_IM_FMT_I, 64, 64, 0, G_TX_MIRROR | G_TX_WRAP,
                           G_TX_MIRROR | G_TX_WRAP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(z1, y1, width, height, 0, 0, texture_step, texture_step, 0);

    temp_z1 = z1;
    temp_y1 = y1;

    gSPDisplayList(gDisplayListHead++, D_8006F4C0);
    gDPSetFillColor(gDisplayListHead++, 0x00010001);

    screen_width = z1 + width;
    screen_height = y1 + height;

    if (z1 < 0) {
        temp_z1 = 0;
    }

    if (y1 < 0) {
        temp_y1 = 0;
    }

    if (screen_width >= 641) {
        screen_width = 640;
    }

    if (screen_height >= 481) {
        screen_height = 480;
    }

    if (temp_y1 > 0) {
        gDPFillRectangle(gDisplayListHead++, 0, 0, 639, temp_y1 - 1);
    }

    if (screen_height < 480) {
        gDPFillRectangle(gDisplayListHead++, 0, screen_height, 639, 479);
    }

    if ((temp_z1 > 0) && (temp_y1 >= 0) && (screen_height < 481)) {
        gDPFillRectangle(gDisplayListHead++, 0, temp_y1, temp_z1 - 1, screen_height - 1);
    }

    if ((screen_width < 641) && (temp_y1 >= 0) && (screen_height < 481)) {
        gDPFillRectangle(gDisplayListHead++, screen_width, temp_y1, 639, screen_height - 1);
    }
}

void Glc_StartCircleWipe(s16 start) {
    if (start > 0) {
        circle_fade.fade_state = 1;
        circle_fade.width = circle_fade.circle_height = start;
        circle_fade.ratio = 7.0f;
    }
}

void Glc_InitBackgroundFade(void) {
    background_fade.mode = 0;
    background_fade.timer = 0;
    background_fade.fade = 0xC0;
}

void Glc_UpdateBackgroundFade(void) {
    switch (background_fade.mode) {
        case 1:
            background_fade.timer--;
            background_fade.fade = ((background_fade.timer * -0x3F) / 10) + 0xFF;
            if (background_fade.timer <= 0) {
                background_fade.mode = 2;
                background_fade.timer = 0;
                background_fade.fade = 0xFF;
            }
            break;

        case 2:
            break;
    }
}

void Glc_DrawFadedBackground(u8* texture, s16 alpha) {
    s32 i;
    s32 j;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 640, 480);
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0,
                      ENVIRONMENT, 0);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, alpha);

    gDPPipeSync(gDisplayListHead++);

    for (i = 0; i < 0x1E0; i += 0x20) {
        for (j = 0; j < 0x280; j += 0x20) {
            gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, j << 2, i << 2, (j + 0x20) << 2, (i + 0x20) << 2, G_TX_RENDERTILE,
                                0, 0, 0x0200, 0x0200);

            texture += 0x200;
        }
    }
}

void Glc_DrawBackground(void) {
    if (background_fade.fade < 0xFF) {
        Glc_DrawFadedBackground(bin_background, background_fade.fade);
    } else {
        Gfx_DrawTiledRgba16Image(bin_background);
    }
}

void Glc_StartBackgroundFade(s16 mode) {
    background_fade.mode = mode;
    if (background_fade.mode == 1) {
        background_fade.timer = 0xA;
        background_fade.fade = 0xC0;
    }
}

void Glc_ReadInputs(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void Glc_InitObjectAnimation(unk_D_83101F00* arg0, s16 arg1) {
    unk_D_83101E6C* ptr;

    arg0->unk_16A = arg1;

    if (arg0->unk_16A == 1) {
        switch (arg0->unk_168) {
            case 1:
                arg0->unk_184 = 0.0f;
                arg0->unk_180 = 1.0f;
                break;

            case 2:
                arg0->unk_170 = 0;
                ptr = &D_83101E6C[arg0->unk_170];

                arg0->unk_16C = arg0->unk_16E = ptr->unk_00;
                arg0->unk_172 = ptr->unk_08;
                arg0->unk_174 = ptr->unk_0A;
                arg0->unk_176 = ptr->unk_0C;
                arg0->unk_178 = ptr->unk_0E;
                arg0->unk_17A = ptr->unk_10;
                arg0->unk_17C = ptr->unk_12;

                Vec3f_SetComponentsDuplicate(&arg0->unk_000.scale, ptr->unk_04, ptr->unk_04, ptr->unk_04);
                break;
        }
    }
}

void Glc_DrawScisRectangle(s16 x1, s16 y1, s16 width, s16 height, s16 texture_start_x, s16 texture_start_y, s16 texture_spread_x, s16 texture_spread_y) {
    gSPScisTextureRectangle(gDisplayListHead++, x1 << 2, y1 << 2, ((x1 + width) - 1) << 2,
                            ((y1 + height) - 1) << 2, 0, texture_start_x, texture_start_y, texture_spread_x, texture_spread_y);
}

void Glc_DrawTrackingIcon(void) {
    f32 v = 1.8f;
    s16 temp_fa0;
    s16 temp_ft2;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    temp_ft2 = ROUND_MAX(28 * v);
    temp_fa0 = ROUND_MAX(1024.0f / v);

    gDPLoadTextureBlock(gDisplayListHead++, D_30025E0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 28, 28, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Glc_DrawScisRectangle(D_83101EEE, D_83101EF0, temp_ft2, temp_ft2, 0, 0, temp_fa0, temp_fa0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Glc_ClearInitState(void) {
    stage_fade_mode = 0;
    if (D_800AE540.unk_11F2 != 0) {
        tracking_icon_on = 1;
    } else {
        tracking_icon_on = 0;
    }
    D_83101EF0 = -0x64;
    D_83101EEE = D_83101EF0;
    Glc_InitCircleWipe();
    Glc_InitBackgroundFade();
}

void Glc_ClearDraw(void) {
    BgStage_DrawFrame();
    Glc_DrawBackground();
    Geo_RenderRootNode(D_83101EF4);
    if (tracking_icon_on != 0) {
        Glc_DrawTrackingIcon();
    }
    Glc_DrawCircleWipe();
    BgStage_AdvanceFrame();
}

s32 Glc_ClearAdvanceState(void) {
    s32 sp1C = 1;

    switch (stage_fade_mode) {
        case 0:
            if (StageContext_GetFadeMode() == 0) {
                stage_fade_mode = 1;
                D_83101EEA = 0;
                Glc_InitObjectAnimation(D_83102210, 1);
            }
            break;

        case 1:
            if (D_83102210->unk_16A == 2) {
                switch (D_83102214->unk_16A) {
                    case 0:
                        Glc_InitObjectAnimation(D_83102214, 1);
                        break;

                    case 2:
                        D_83101EEA += 1;
                        if (D_83101EEA == 1) {
                            Glc_StartBackgroundFade(1);
                        }

                        if (D_83101EEA >= 0x1E) {
                            stage_fade_mode = 2;
                            D_83101EEA = 0;
                            Glc_StartCircleWipe(0xF);
                            StageContext_SetClearColor(1);
                        }
                        break;
                }
            }
            break;

        case 2:
            if (circle_fade.fade_state == 2) {
                sp1C = 0;
            }
            break;
    }

    return sp1C;
}

void Glc_ClearRunLoop(void) {
    Glc_ClearInitState();
    StageFade_StartFromOpaque(0xF);

    do {
        Glc_ReadInputs();
        Glc_UpdateCircleWipe();
        Glc_UpdateBackgroundFade();
        Glc_ClearDraw();
    } while (Glc_ClearAdvanceState() != 0);
}

void Glc_ClearInitGraphics(void) {
    unk_D_83101F00* ptr;
    MemoryBlock* temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    s32 i;

    D_83101EF4 = process_geo_layout(temp_v0, D_83101E1C);
    D_83101EF8 = process_geo_layout(temp_v0, D_83101D08);
    D_83101EFC = process_geo_layout(temp_v0, D_83101DE8);

    MainPool_FinalizeAllocation(temp_v0);
    ModelRenderer_InitDisplayRoots();

    for (i = 0; i < 2; i++) {
        ptr = &D_83101F00[i];

        ModelRenderer_AttachDisplayObject(&ptr->unk_000);

        ptr->unk_172 = ptr->unk_174 = ptr->unk_176 = 0;
        ptr->unk_178 = ptr->unk_17A = ptr->unk_17C = 0;
        ptr->unk_168 = 0;
        ptr->unk_16A = 0;
        ptr->unk_16C = 0;
        ptr->unk_16E = 0;
        ptr->unk_170 = 0;
        ptr->unk_180 = 0.0f;
        ptr->unk_184 = 0.0f;

        switch (i) {
            case 0:
                Vec3f_SetComponentsDuplicate(&ptr->unk_000.position, -520.0f, 44.0f, -579.0f);
                Vec3f_SetComponentsDuplicate(&ptr->unk_000.scale, 2.0f, 2.0f, 2.0f);
                Model_InitDisplayObject(&ptr->unk_000, 0, 0, D_83101EF8);
                ptr->unk_168 = 1;
                D_83102210 = ptr;
                break;

            case 1:
                Vec3f_SetComponentsDuplicate(&ptr->unk_000.position, 0.0, -24.0f, -579.0f);
                Vec3f_SetComponentsDuplicate(&ptr->unk_000.scale, 0.0f, 0.0f, 0.0f);
                Model_InitDisplayObject(&ptr->unk_000, 0, 0, D_83101EFC);
                ptr->unk_168 = 2;
                D_83102214 = ptr;
                break;
        }
    }
}

s32 GymLeaderCastleClear_Main(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* stage_context;

    main_pool_push_state('CLRG');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    stage_context = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    Font_Init(0x10, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, gym_leader_castle_clear_gfx, 0);
    background = ASSET_LOAD2(backgrounds, 1, 1);
    bin_background = BinArchive_GetFile(background, 0xE);

    Glc_ClearInitGraphics();
    StageContext_Activate(stage_context);
    Glc_ClearRunLoop();
    StageLoader_RunFrames(2);
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('CLRG');

    return 0;
}
