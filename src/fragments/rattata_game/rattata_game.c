#include "rattata_game.h"
#include "src/geo_render.h"
#include "src/model_animation.h"
#include "src/model_animation_events.h"
#include "src/geo_layout.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/ui_graphics.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/gfx_rect.h"
#include "src/audio_loop_point.h"
#include "src/gfx_buffer.h"
#include "src/matrix.h"
#include "src/audio_channel.h"
#include "src/audio_sound_state.h"
#include "src/gallery.h"
#include "src/controller.h"
#include "src/fragments/widget_toolkit/widget_toolkit.h"
#include "src/fragments/minigame_shared_graphics/minigame_shared_graphics.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_86203CEC {
    /* 0x0 */ void* unk_00;
    /* 0x4 */ s16 unk_04;
    /* 0x6 */ s16 unk_06;
} unk_D_86203CEC; // size = 0x8

static u32 D_862038C0[] = {
    0xFFFFFFD8, 0xFFFFFF65, 0x00000056, 0x00000097, 0xA4CFA4B7, 0xA4ECA5B3, 0xA5E9A5C3, 0xA5BF0000, 0xA1A1A1A1,
    0xA1A1A1A1, 0xA4F2A4EC, 0xA4F3A4C0, 0xA4B7A4C6, 0xA1A1A4CF, 0xA4B7A4ED, 0xA4A6A1A3, 0x00000000, 0xA5CFA1BC,
    0xA5C9A5EB, 0xA4CFA1A1, 0xA1A1A1A1, 0xA1A1A1A1, 0xA1A1A1A1, 0xA4CE20A4, 0xA6A4A8A4, 0xF2A1A1A4, 0xAAA4B7A4,
    0xC6000000, 0xA5B8A5E3, 0xA5F3A5D7, 0xA4C7A1A1, 0xA4C8A4D3, 0xA4B3A4A8, 0xA4E8A4A6, 0xA1A30000, 0xA4A4A4C1,
    0xA4D0A4F3, 0xA4B5A4AD, 0xA4CBA1A1, 0xA5B4A1BC, 0xA5EBA4B7, 0xA4BFA4D2, 0xA4C8A4AC, 0xA1A1A4AB, 0xA4C1A1A3,
    0x00000000, 0xA4CFA4B7, 0xA4EB0000, 0xA4C9A4A6, 0xA4C1A4E3, 0xA4AF0000, 0xA4CFA4F3, 0xA4C6A4A4, 0x00000000,
    0xA4D2A4B2, 0x00000000, 0xA4CFA4CA, 0x00000000, 0xA4A2A4BF, 0xA4DE0000, 0xA4E9A4AF, 0xA4B7A4E7, 0xA4A60000,
    0xA4C1A4E5, 0xA4A6A4B7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x000A0005, 0x00020000,
};

static f32 D_86203BA0[4][10] = {
    { 5.5f, 10.5f, 15.5f, 20.5f, 23.79999924f, 27.10000038f, 30.5f, 35.5f, 40.5f, 45.5f },
    { 5.5f, 8.5f, 17.5f, 19.5f, 24.5f, 26.5f, 34.5f, 37.5f, 45.5f, 47.5f },
    { 5.5f, 7.5f, 9.5f, 17.5f, 27.5f, 29.5f, 31.5f, 42.5f, 44.5f, 46.5f },
    { 60.0f, 61.0f, 62.0f, 63.0f, 64.0f, 65.0f, 66.0f, 67.0f, 68.0f, 69.0f },
};

static u32 D_86203C40[] = {
    0x001C000E, 0xFFFFFFFF, 0x0000FFFF, 0x0062000E, 0xFFFFFFFF, 0x00FF00FF, 0x00A8000E,
    0xFFFFFFFF, 0xFF0000FF, 0x00EE000E, 0xFFFFFFFF, 0xFFFF00FF, 0x00000000,
};

static unk_func_87801684 D_86203C74[] = {
    {
        0x303ED80,
        0x02,
    },
    {
        0x303F180,
        0x02,
    },
    {
        0x303F580,
        0x02,
    },
    {
        0x303F180,
        0x02,
    },
    {
        0x0,
        0x0,
    },
};

static unk_func_87801684 D_86203C9C[] = {
    {
        0x3040580,
        0x12,
    },
    {
        0x3040980,
        0x02,
    },
    { 0x3040D80, 0x08 },
    {
        0x3040980,
        0x02,
    },
    { 0x0, 0x0 },
};

static unk_func_87801684 D_86203CC4[] = {
    { 0x03042E00, 0x0E }, { 0x03044360, 0x02 }, { 0x03044A80, 0x06 }, { 0x03044360, 0x02 }, { 0, 0 },
};

static unk_D_86203CEC D_86203CEC[] = {
    { D_87A01190, 0x0019, 0x000F },
    { D_87A01178, 0x0019, 0x0014 },
    { D_87A01180, 0x001E, 0x0028 },
    { D_87A011A4, 0x0028, 0x005A },
};

static u32 D_86203D0C[] = {
    0x0C00FFFF,       (u32)&D_5000000, 0x0B00001E,      0x00000000,      0x014000F0,      0x0000000F,
    0x00000000,       0x00000000,      (u32)&D_5000000, 0x0D000000,      (u32)&D_5000000, 0x14000000,
    0x002B0012,       0xFFFFFF32,      0x16FFFFFF,      0x0F000003,      (u32)&D_5000000, 0x0A000000,
    (u32)&D_800AC840, (u32)&D_6000000, (u32)&D_6000000, (u32)&D_6000000, (u32)&D_3000000, 0x87806398,
    (u32)&D_6000000,  (u32)&D_1000000, 0xFFFFFFFF,      0x0505FFFF,      0x0505FFFF,      0xFFFFFFFF,
    0xFFFFFFFF,       0x05FF05FF,      0x05FF05FF,      0xFFFFFFFF,      0xFFFFFFFF,      0xFF0505FF,
    0xFF0505FF,       0xFFFFFFFF,      0xFFFFFFFF,      0xFFFF05FF,      0xFFFF05FF,      0xFFFFFFFF,
};

// Unused rodata strings
const char D_86203DC0[] = " %dP";
const char D_86203DC8[] = "%s";

static unk_D_86002F30* D_86203E30;
static unk_D_86002F30* D_86203E34;
static unk_D_86002F34* D_86203E38;
static unk_D_86002F34_00C* D_86203E3C;
static s16 D_86203E40;
static s16 D_86203E42;
static s16 D_86203E44;
static u16 D_86203E46;
static s32 D_86203E48;
static s16 D_86203E4C;
static RattataRacer D_86203E50[4];
static RattataRacer* D_86204590;
static DisplayObject* D_86204594;
static DisplayObject D_86204598;
static s16 D_86204700;
static u32 D_86204704;
static s16 D_86204708;
static s16 D_8620470A;
static s16 D_8620470C;
static s16 D_8620470E;
static f32 D_86204710;
static FontContext* D_86204714;
static s16 D_86204718;
static s16 D_8620471A;
static s16 D_8620471C;
static RattataHurdleMarker D_86204720[4][10];
static RattataHurdleMarker* D_86208280;
static s32 D_86208288[4];
static s32 D_86208298;
static s16 D_8620829C;
u32 D_862082A0[4];

void RattataGame_InitAIDifficulty(RattataRacer* arg0) {
    arg0->unk_002 = D_8780FA38 + 1;
}

void RattataGame_DrawRankBanners(void) {
    UNUSED s32 pad[3];
    MtxF spDC;
    Mtx sp98;
    s32 i;
    UNUSED s32 pad2[1];

    MtxF_ExtractScale(&spDC, &D_86203E3C->unk_60.mtxf);
    guMtxF2L(spDC.mf, &sp98);

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;
        if (D_86204590->unk_19E == 2) {
            switch (D_86204590->unk_1B2) {
                case 0:
                    gDisplayListHead = MiniGfx_DrawTexturedQuad(gDisplayListHead, &sp98, -(i - 1.5f) * 40.0f, 5.0f, 30.0f, 0.25f,
                                                     &D_4000008, 0x20, 0x20);
                    break;

                case 1:
                    gDisplayListHead = MiniGfx_DrawTexturedQuad(gDisplayListHead, &sp98, -(i - 1.5f) * 40.0f, 5.0f, 30.0f, 0.25f,
                                                     &D_4000810, 0x20, 0x20);
                    break;

                case 2:
                    gDisplayListHead = MiniGfx_DrawTexturedQuad(gDisplayListHead, &sp98, -(i - 1.5f) * 40.0f, 5.0f, 30.0f, 0.25f,
                                                     &D_4001018, 0x20, 0x20);
                    break;

                case 3:
                    gDisplayListHead = MiniGfx_DrawTexturedQuad(gDisplayListHead, &sp98, -(i - 1.5f) * 40.0f, 5.0f, 30.0f, 0.25f,
                                                     &D_4001820, 0x20, 0x20);
                    break;
            }
        }
    }
}

void func_862002EC(void) {
}

void RattataGame_UpdateAIInput(void) {
    UNUSED s32 pad[2];
    s32 i;
    unk_D_86203CEC* temp_s0;
    u16 sp60[4];
    f32 temp_fv0;
    f32 temp_fv1;

    sp60[0] = gPlayer1Controller->buttonPressed;
    sp60[1] = gPlayer2Controller->buttonPressed;
    sp60[2] = gPlayer3Controller->buttonPressed;
    sp60[3] = gPlayer4Controller->buttonPressed;

    if (D_86203E48 == 2) {
        for (i = 0; i < 4; i++) {
            D_86204590 = &D_86203E50[i];

            if (D_86204590->unk_002 == 0) {
                D_86204590->unk_170 = sp60[i];
            } else {
                D_86204590->unk_170 = 0;
                if (D_86204590->unk_002 > 0) {
                    temp_s0 = &D_86203CEC[D_86204590->unk_002 - 1];

                    if (Rand_Range(0x64) < temp_s0->unk_04) {
                        D_86204590->unk_170 |= 0x8000;
                    }

                    if (Rand_Range(0x64) < temp_s0->unk_06) {
                        temp_fv0 = D_86204590->unk_1A8;
                        temp_fv1 = D_86204590->unk_1A4;
                        if (((temp_fv0 + 10.0f) < temp_fv1) && (temp_fv1 < (temp_fv0 + 20.0f))) {
                            D_86204590->unk_170 |= 0x800;
                        }
                    }
                }
            }
        }

        return;
    }

    for (i = 0; i < 4; i++) {
        D_86203E50[i].unk_170 = sp60[i];
    }
}

void RattataGame_PollInput(void) {
    D_8620471A = 0;
    if (StageContext_GetFadeMode() == 0) {
        D_8620471A = 1;
        Cont_StartReadInputs();
        Cont_ReadInputs();
        Input_ResetRepeatState();
        RattataGame_UpdateAIInput();
    }
}

void RattataGame_InitCamera(void) {
    D_8620829C = 0;
    D_86203E3C = D_86203E38->node.children;

    MiniCam_SetActive(D_86203E3C);
    D_86203E40 = 0x1300;
    D_86203E42 = -0x6700;
    D_86203E44 = 0x14A;

    D_86203E3C->unk_24.near = 50.0f;
    D_86203E3C->unk_24.far = 6400.0f;
    D_86203E3C->unk_24.fovy = 30.0f;

    D_86203E3C->unk_60.at.x = 0.0f;
    D_86203E3C->unk_60.at.y = 0.0f;
    D_86203E3C->unk_60.at.z = 5.0f;

    Camera_ComputeEyeFromAngles(&D_86203E3C->unk_60.at, &D_86203E3C->unk_60.eye, D_86203E44, D_86203E40, D_86203E42);
}

void RattataGame_UpdateCamera(void) {
    switch (D_86203E48) {
        case 0:
            D_86203E40 = 0xD00;
            D_86203E42 = -0x1D00;
            D_86203E44 = 0x1F4;
            break;

        case 1:
            if (D_86203E40 > 0x1300) {
                D_86203E40 -= 0x20;
            }

            if (D_86203E42 > 0x9900u) {
                D_86203E42 -= 0x100;
                if (D_86203E42 < 0x9900u) {
                    D_86203E42 = -0x6700;
                }
            }

            if (D_86203E44 > 0x14A) {
                D_86203E44 -= 2;
            }
            break;

        case 2:
            if (D_8780FC94 == 0) {
                if (D_86203E44 > 0x14A) {
                    D_86203E44 -= 2;
                }

                D_86203E42 += 0x20;
                if ((u16)D_86203E42 < 0xC000) {
                    D_86203E40 += 0xA;

                    if (D_86203E40 > 0x1500) {
                        D_86203E40 = 0x1500;
                    }
                } else if ((D_86203E40 & 0xFFFF) > 0xA00) {
                    D_86203E40 -= 0xA;
                }
            }
            break;

        case 3:
        case 4:
            if (D_86203E44 > 0xF0) {
                D_86203E44 -= 1;
                if (D_86203E44 < 0xF0) {
                    D_86203E44 = 0xF0;
                }
            }

            if ((D_86203E40 & 0xFFFF) > 0x2FC) {
                D_86203E40 -= 0x1E;
                if ((D_86203E40 & 0xFFFF) < 0x2FC) {
                    D_86203E40 = 0x2FC;
                }
            }
            D_86203E42 += 0x40;
            break;

        case 5:
            D_86203E42 += 0x60;
            break;

        default:
            break;
    }

    if (D_86203E40 > 0x3F00) {
        D_86203E40 = 0x3F00;
    }

    if (D_86203E40 < 0) {
        D_86203E40 = 0;
    }

    if (D_86203E44 < 0x32) {
        D_86203E44 = 0x32;
    }

    Camera_ComputeEyeFromAngles(&D_86203E3C->unk_60.at, &D_86203E3C->unk_60.eye, D_86203E44, D_86203E40, D_86203E42);
}

void func_86200938(void) {
}

void RattataGame_DrawTutorialScreen(s32 arg0) {
    UNUSED s32 pad;
    UNUSED u8 sp50[3] = { 0, 0, 30 };
    UNUSED u8 sp4C[3] = { 0, 0, 150 };
    s32 sp48;
    s32 sp44;
    char* sp40;
    s32 sp3C;
    s32 sp38;
    char* sp34;

    Font_BeginTranslucentTextRendering();
    Font_EndTexturedTextRendering();

    if (arg0 == 0) {
        Ui_DrawBorderedPanel(0x18, 0x16, 0x110, 0x90, 0x15);
        Ui_DrawBorderedPanel(0x18, 0xA5, 0x110, 0x36, 0x14B);
    }

    Font_BeginTranslucentTextRendering();

    switch (arg0) {
        case 1:
        case 2:
        case 3:
        case 4:
            break;

        case 0:
            Font_EnableTwoCycleTexturing();
            Font_SetActive(2, 0);
            Font_SetLineHeight(0xC);
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetPrimColor(0xF9, 0xF4, 0, 0xFF);
            Font_Printf(0xA0 - (Text_MeasureStringWidth(D_86204714, Text_GetString(NULL, 0, D_87806330, 0x23)) / 2), 0x20,
                          Text_GetString(NULL, 0, D_87806330, 0x23));
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetPrimColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_Printf(0x28, 0x34, Text_GetString(NULL, 0, D_87806330, 0x24));
            Font_Printf(0x28, 0x4C, Text_GetString(NULL, 0, D_87806330, 0x25));
            Font_Printf(0x28, 0x70, Text_GetString(NULL, 0, D_87806330, 0x26));
            Gfx_SetEnvColor(0xC8, 0xC8, 0xFF, 0xFF);
            Gfx_SetPrimColor(0x50, 0x50, 0xFF, 0xFF);

            sp40 = Text_GetString(NULL, 0, D_87806330, 0x5F);
            Widget_MeasureLabelBox(&sp48, &sp44, Text_GetString(NULL, 0, D_87806330, 0x24), sp40, 0xC);
            if (sp48 >= 0) {
                Font_Printf(sp48 + 0x28, sp44 + 0x34, sp40);
            }

            Gfx_SetEnvColor(0xE6, 0xD2, 0xFF, 0xFF);
            Gfx_SetPrimColor(0x82, 0x50, 0xD2, 0xFF);

            sp34 = Text_GetString(NULL, 0, D_87806330, 0x61);
            Widget_MeasureLabelBox(&sp3C, &sp38, Text_GetString(NULL, 0, D_87806330, 0x25), sp34, 0xC);
            if (sp3C >= 0) {
                Font_Printf(sp3C + 0x28, sp38 + 0x4C, sp34);
            }

            Gfx_SetEnvColor(0xE6, 0xD2, 0xFF, 0xFF);
            Gfx_SetPrimColor(0x82, 0x50, 0xD2, 0xFF);
            Font_Printf(0x8C, 0xB0, Text_GetString(NULL, 0, D_87806330, 0x19));
            Gfx_SetEnvColor(0xC8, 0xC8, 0xFF, 0xFF);
            Gfx_SetPrimColor(0x50, 0x50, 0xFF, 0xFF);
            Font_Printf(0xFC, 0xB0, Text_GetString(NULL, 0, D_87806330, 0x27));
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetPrimColor(0xFF, 0x80, 0x80, 0xFF);
            Font_Printf(0xA2, 0xC8, Text_GetString(NULL, 0, D_87806330, 0x14));
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetPrimColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_Printf(0x75, 0xB0, Text_GetString(NULL, 0, D_87806330, 0x5C));
            Font_Printf(0xE5, 0xB0, Text_GetString(NULL, 0, D_87806330, 0x5C));
            Font_Printf(0x8B, 0xC8, Text_GetString(NULL, 0, D_87806330, 0x5C));
            Font_DisableTwoCycleTexturing();
            break;
    }

    Font_EndTexturedTextRendering();

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (arg0 == 0) {
        Widget_DrawAnimIcon24(0x56, 0xAC, D_86203CC4);
        Widget_DrawAnimIcon16(0xCC, 0xB0, D_86203C74);
        Widget_DrawAnimIcon16C(0x74, 0xC6, D_86203C9C);
        Widget_DrawSplitBanner(2, 0x19, 0xA6);
    } else if (D_86204718 == 1) {
        Widget_DrawStripedBar(0x1E, 0x17);
    }
}

void RattataGame_DrawFrame(s32 arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_862082A0[i] = D_86203E50[i].unk_190 * 36.0f;
    }

    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 1);

    if (D_8780FC94 == 0) {
        GeoRender_AdvanceFrameCounter();
    }

    Widget_CountdownUpdate();
    Geo_RenderRootNode(D_86203E38);
    gDisplayListHead = MiniCam_ApplyProjection(gDisplayListHead);
    RattataGame_DrawRankBanners();

    if (D_8780FC98 == 0) {
        RattataGame_DrawTutorialScreen(arg0);
    }

    if (D_86204718 == 0) {
        Widget_PauseMenuUpdate();
    } else {
        Widget_DrawControllerDisconnectBanner();
    }

    BgStage_AdvanceFrame();
    D_86203E46++;
}

s32 RattataGame_WaitForStart(void) {
    s32 i;
    s32 var_s1_3;

    StageLoader_RunFrames(0xA);
    StageFade_StartFromOpaque(0x10);

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;
        ModelAnim_SetAnimation(D_86204594, 0);
        ModelAnim_ClearEventTrack(D_86204594);
        D_86204594->transformAnim.speedFixed = 0x10000;
        D_86204594->transformAnim.frameFixed = Rand_Range(0x14) << 0x10;
    }

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        if ((D_8780FA30[i] == 0) && (D_86204718 == 0)) {
            D_86204590->unk_002 = 0;
        } else {
            RattataGame_InitAIDifficulty(D_86204590);
        }
    }

    D_86203E48 = 0;
    if (D_86204718 == 0) {
        var_s1_3 = 1;
    } else {
        RattataGame_UpdateCamera();
        RattataGame_DrawFrame(D_86203E48);
        return 0;
    }

    while (var_s1_3 == 1) {
        RattataGame_PollInput();
        RattataGame_UpdateCamera();
        if (D_8620471A == 1) {
            if (gPlayer1Controller->buttonPressed & 0x1000) {
                var_s1_3 = 0;
            }

            if ((D_8780FA2A == 0) && (gPlayer1Controller->buttonPressed & 0x4000)) {
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
                Widget_PauseMenuTrigger(2);
                return -1;
            }
        }
        RattataGame_DrawFrame(D_86203E48);
    }

    return 0;
}

void RattataGame_UpdateStartCountdown(void) {
    s32 i;

    StageFade_StartFromOpaque(0x10);

    for (i = 0; i < 4; i++) {
        ModelAnim_SetAnimation(&D_86203E50[i].unk_008, 0);
    }

    D_86204700 = 1;
    Widget_CountdownStart(1);
    D_86203E48 = 1;

    while (D_86204700 == 1) {
        switch (Widget_CountdownGetState()) {
            case 1:
            case 2:
            case 3:
                MiniSound_DispatchCommand(0x60001, 0, 0);
                break;
            case 0:
                D_86204700 = 0;
                break;
        }

        RattataGame_PollInput();

        if ((D_86204718 == 1) && (StageContext_GetFadeMode() == 0) &&
            ((gPlayer1Controller->buttonPressed | gPlayer2Controller->buttonPressed |
              gPlayer3Controller->buttonPressed | (gPlayer4Controller->buttonPressed != 0)) != 0)) {
            StageFade_StartFromTransparent(0x1E);
            Audio_BeginVolumeTransition(0x1E);
            D_86204700 = 0;

            for (i = 0; i < 30; i++) {
                RattataGame_UpdateCamera();
                RattataGame_DrawFrame(D_86203E48);
            }

            while (Audio_GetActivityScore() != 0) {
                RattataGame_UpdateCamera();
                RattataGame_DrawFrame(D_86203E48);
            }

            Audio_ResetVolumeTransition();
            Widget_PauseMenuTrigger(2);
        }

        RattataGame_UpdateCamera();
        RattataGame_DrawFrame(D_86203E48);
    }
}

void RattataGame_SyncRacerZPosition(RattataRacer* arg0) {
    f32 temp_fv0 = arg0->unk_178 - 30.0f;

    arg0->unk_008.position.z = temp_fv0;
    arg0->unk_194 = temp_fv0 / 3.0f;
}

void RattataGame_ResetRacerState(RattataRacer* arg0) {
    arg0->unk_19C = 0;
    arg0->unk_180 = 30.0f;
    arg0->unk_184 = 30.0f;
    arg0->unk_17C = 5.0f;
    arg0->unk_188 = 3.0f;
    arg0->unk_174 = 0.0f;
    arg0->unk_178 = 0.0f;
    arg0->unk_198 = -1.0f;
    RattataGame_SyncRacerZPosition(arg0);
    arg0->unk_190 = 0.0f - arg0->unk_194;
}

s32 RattataGame_CheckHurdleCollision(RattataRacer* arg0, RattataHurdleMarker* arg1) {
    f32 temp_fv0;
    f32 temp_fv1;

    arg0->unk_1A4 = -1.0f;

    if ((arg1->unk_000 == 0) || (arg1->unk_002 == 0) || (arg1->unk_002 >= 2)) {
        return 0;
    }

    temp_fv0 = 30.0f - (arg1->unk_004.transformAnim.frameFixed / 111411.2f);
    temp_fv1 = arg0->unk_008.position.z / 3.0f;

    arg0->unk_1A8 = temp_fv1;
    arg0->unk_1A4 = temp_fv0;

    if ((temp_fv0 <= temp_fv1 - 3.0f) && (arg0->unk_19C == 1) && (arg0->unk_008.transformAnim.frameFixed >= 0xC0001) &&
        (arg1->unk_170 == 0)) {
        arg1->unk_170 = 1;
    }

    if ((temp_fv0 <= temp_fv1 - 3.0f) || ((temp_fv1 + 3.0f) <= temp_fv0)) {
        return 0;
    }

    if (arg0->unk_19C == 1) {
        if ((arg0->unk_008.transformAnim.frameFixed >= 0x20001) && (arg0->unk_008.transformAnim.frameFixed < 0x100000)) {
            return 0;
        }
    }
    arg1->unk_170 = 1;
    return -1;
}

void RattataGame_UpdateRunAnimSpeed(RattataRacer* arg0) {
    arg0->unk_008.transformAnim.speedFixed = (arg0->unk_178 * 196608.0f) / arg0->unk_180;
}

void RattataGame_SetRacerAnimState(RattataRacer* arg0, s32 arg1) {
    DisplayObject* temp_s0 = &arg0->unk_008;

    switch (arg1) {
        case 3:
            arg0->unk_19C = 3;
            ModelAnim_SetAnimation(temp_s0, 0);
            temp_s0->transformAnim.speedFixed = 0x10000;
            break;

        case 0:
            arg0->unk_19C = 0;
            ModelAnim_SetAnimation(temp_s0, 1);
            RattataGame_UpdateRunAnimSpeed(arg0);
            break;

        case 1:
            arg0->unk_19C = 1;
            ModelAnim_SetAnimation(temp_s0, 2);
            temp_s0->transformAnim.speedFixed = 0x10000;
            MiniSound_DispatchCommand(0x60003, arg0->unk_000, 0);
            break;

        case 2:
            arg0->unk_19C = 2;
            ModelAnim_SetAnimation(temp_s0, 3);
            temp_s0->transformAnim.speedFixed = 0x10000;
            MiniSound_DispatchCommand(0x60004, arg0->unk_000, 0);
            break;
    }
}

void RattataGame_UpdateHurdleMarkers(RattataRacer* arg0) {
    s32 i;
    f32 temp_fs1;
    u32 temp_v0;
    DisplayObject* temp_s1;
    s32 arg0_unk000 = arg0->unk_000;
    f32 unk_190;

    for (i = 0; i < 10; i++) {
        D_86208280 = &D_86204720[arg0_unk000][i];
        temp_s1 = &D_86208280->unk_004;
        D_86208280->unk_000 = 0;
        unk_190 = arg0->unk_190;
        temp_fs1 = D_86203BA0[D_8620471C][i] * 10.44f * 1.7f;

        if (((temp_fs1 - 30.0f) <= unk_190) && (unk_190 <= ((temp_fs1 - 30.0f) + 67.64706f))) {

            switch (D_86208280->unk_002) {
                case 0:
                    if ((unk_190 - (temp_fs1 - 30.0f)) < 5.0f) {
                        D_86208280->unk_002 = 1;
                        Model_InitDisplayObject(temp_s1, 0, 0xB0, D_86203E34->unk_08->unk_00[arg0_unk000]);
                    }
                    break;

                case 2:
                    D_86208280->unk_17A++;
                    if (D_86208280->unk_17A >= 5) {
                        D_86208280->unk_17A = 0;
                        D_86208280->unk_002 = 3;
                    }
                    break;

                case 3:
                    D_86208280->unk_17A++;
                    if (D_86208280->unk_17A >= 5) {
                        D_86208280->unk_17A = 0;
                        D_86208280->unk_002 = 2;
                    }
                    break;
            }

            if ((D_86208280->unk_002 > 0) && ((unk_190 - (temp_fs1 - 30.0f)) > 64.70588f)) {
                D_86208280->unk_002 = 0;
                ModelRenderer_ClearDisplayObject(temp_s1);
            }

            if (D_86208280->unk_002 >= 2) {
                D_86208280->unk_178++;
                if (D_86208280->unk_178 >= 0x1F) {
                    D_86208280->unk_002 = 0;
                    ModelRenderer_ClearDisplayObject(temp_s1);
                }
            }

            temp_v0 = ((unk_190 - temp_fs1) + 30.0f) * 1.7f * 65536.0f;
            temp_s1->transformAnim.frameFixed = (D_86208280->unk_16C + temp_v0) >> 1;
            D_86208280->unk_16C = temp_v0;

            if (D_86208280->unk_002 == 1) {
                ModelAnim_SetAnimation(temp_s1, 0);
                temp_s1->lodFraction = 0xFF;
            } else if (D_86208280->unk_002 == 3) {
                ModelAnim_SetAnimation(temp_s1, 0);
                temp_s1->lodFraction = 0x80;
            } else if ((D_86208280->unk_002 == 0) || (D_86208280->unk_002 == 2)) {
                temp_s1->transformAnim.frameFixed = 0x730000;
            }

            temp_s1->transformAnim.speedFixed = 0;
            D_86208280->unk_000 = 1;
        }
    }

    if (arg0) {}
}

s16 RattataGame_UpdateRacers(void) {
    s32 i;
    s32 j;
    s16 sp86;
    UNUSED s32 pad1[2];
    f32 var_fa0;

    sp86 = 0;

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;

        D_86204590->unk_1A0 = 0;

        if (D_86204590->unk_178 < D_86204590->unk_174) {
            var_fa0 = D_86204590->unk_174 - D_86204590->unk_178;
            if (var_fa0 < 1.0f) {
                D_86204590->unk_178 += var_fa0;
            } else {
                D_86204590->unk_178 += 1.0f;
            }
        } else if (D_86204590->unk_174 < D_86204590->unk_178) {
            var_fa0 = D_86204590->unk_178 - D_86204590->unk_174;
            if (var_fa0 < 1.0f) {
                D_86204590->unk_178 -= var_fa0;
            } else {
                D_86204590->unk_178 -= 1.0f;
            }
        }

        if (D_86204590->unk_19E == 0) {
            switch (D_86204590->unk_19C) {
                case 0:
                    if (D_86204590->unk_170 & 0x800) {
                        RattataGame_SetRacerAnimState(D_86204590, 1);
                    } else {
                        if (D_86204590->unk_170 & 0x8000) {
                            D_86204590->unk_174 += D_86204590->unk_188;
                            if (D_86204590->unk_174 < D_86204590->unk_184) {
                                D_86204590->unk_174 = D_86204590->unk_184;
                            }
                        }

                        D_86204590->unk_174 -= (D_86204590->unk_188 / 10.0f);

                        if (D_86204590->unk_180 < D_86204590->unk_174) {
                            D_86204590->unk_174 = D_86204590->unk_180;
                            D_86204590->unk_1A2 = 5;
                        } else {
                            D_86204590->unk_1A2 -= 1;
                            if (D_86204590->unk_1A2 < 0) {
                                D_86204590->unk_1A2 = 0;
                            }
                        }

                        if (D_86204590->unk_174 < 0.0f) {
                            D_86204590->unk_174 = 0.0f;
                        }

                        RattataGame_UpdateRunAnimSpeed(D_86204590);
                    }

                    if (D_86204590->unk_174 <= D_86204590->unk_17C) {
                        RattataGame_SetRacerAnimState(D_86204590, 3);
                    }
                    break;

                case 1:
                    if (ModelAnim_IsFinished(D_86204594) != 0) {
                        RattataGame_SetRacerAnimState(D_86204590, 0);
                    }
                    break;

                case 2:
                    D_86204590->unk_174 = 0.0f;
                    if (ModelAnim_IsFinished(D_86204594) != 0) {
                        RattataGame_SetRacerAnimState(D_86204590, 3);
                    }
                    break;

                case 3:
                    D_86204590->unk_174 = 0.0f;
                    if (D_86204590->unk_170 & 0x8000) {
                        D_86204590->unk_174 = D_86204590->unk_184;
                        RattataGame_SetRacerAnimState(D_86204590, 0);
                    }
                    break;
            }

            D_86204590->unk_18C = D_86204590->unk_190;
            D_86204590->unk_190 += D_86204590->unk_178 * 0.05f;

            RattataGame_SyncRacerZPosition(D_86204590);

            for (j = 0; j < 10; j++) {
                D_86208280 = &D_86204720[i][j];

                if ((D_86208280->unk_002 == 1) && (RattataGame_CheckHurdleCollision(D_86204590, D_86208280) != 0)) {
                    RattataGame_SetRacerAnimState(D_86204590, 2);
                    D_86208280->unk_002 = 2;
                    D_86208280->unk_17A = 0;
                    D_86204590->unk_1AC += 1;
                }
            }

            if (D_86204590->unk_190 + D_86204590->unk_194 >= 885.0f) {
                var_fa0 = 0.0f;
                if (D_86204590->unk_178 > 0.0f) {
                    f32 var_fa1 = (885.0f - D_86204590->unk_18C);

                    var_fa0 = var_fa1 / (D_86204590->unk_178 * 0.05f);
                }

                D_86204590->unk_198 = D_86204704 + var_fa0;
                D_86204590->unk_19E = 1;
                D_86204590->unk_174 = D_86204590->unk_180;
                D_86204590->unk_178 = D_86204590->unk_174;

                ModelAnim_SetAnimation(D_86204594, 2);
                D_86204594->transformAnim.speedFixed = 0x10000;

                switch (D_86208298) {
                    case 0:
                        MiniSound_DispatchCommand(0x60006, D_86204590->unk_000, 0);
                        break;

                    case 3:
                        MiniSound_DispatchCommand(0x60008, D_86204590->unk_000, 0);
                        break;

                    default:
                        MiniSound_DispatchCommand(0x60007, D_86204590->unk_000, 0);
                        break;
                }

                D_86208288[D_86208298] = i;
                D_86208298++;
                D_86204590->unk_1A0 = 1;
                sp86++;
            } else {
                D_86204590->unk_18C = D_86204590->unk_190 + D_86204590->unk_194;
            }
        } else {
            D_86204590->unk_190 += D_86204590->unk_178 * 0.05f;

            if (D_86204590->unk_190 > 910.0f) {
                D_86204590->unk_190 = 910.0f;
                D_86204590->unk_19E = 2;
            }

            RattataGame_SyncRacerZPosition(D_86204590);

            if (ModelAnim_IsFinished(D_86204594) != 0) {
                ModelAnim_SetAnimation(D_86204594, 0);
                D_86204594->transformAnim.frameFixed = 0;
                D_86204594->transformAnim.speedFixed = 0x10000;
            }
        }
    }

    return sp86;
}

void RattataGame_AdvanceFinishLineApproach(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;

        if (D_86204590->unk_19E == 1) {
            D_86204590->unk_190 += D_86204590->unk_178 * 0.05f;
            if (D_86204590->unk_190 > 910.0f) {
                D_86204590->unk_190 = 910.0f;
                D_86204590->unk_19E = 2;
            }

            RattataGame_SyncRacerZPosition(D_86204590);

            if (ModelAnim_IsFinished(D_86204594) != 0) {
                ModelAnim_SetAnimation(D_86204594, 0);
                D_86204594->transformAnim.frameFixed = 0;
                D_86204594->transformAnim.speedFixed = 0x10000;
            }
        }
    }
}

void RattataGame_MainLoop(void) {
    s32 spA4;
    s32 i;
    s32 j;
    s16 temp_s1_2;
    s16 var_s3;
    DisplayObject* var_s2;
    RattataRacer* temp_s1;
    s16 var_v0_2;
    s16 sp8C;
    RattataRacer* temp_v1;
    RattataRacer* sp78[4];
    RattataRacer* var_s0_3;

    spA4 = 1;

    for (i = 0; i < 4; i++) {
        temp_s1 = &D_86203E50[i];
        var_s2 = &temp_s1->unk_008;

        ModelAnim_SetAnimation(var_s2, 1);
        ModelAnim_ClearEventTrack(var_s2);
        var_s2->transformAnim.frameFixed = (Rand_Range(5) * 0x3) << 0x10;
        RattataGame_ResetRacerState(temp_s1);
        temp_s1->unk_1C8 = 0;
        temp_s1->unk_1B2 = 4;
        temp_s1->unk_19E = 0;
        temp_s1->unk_198 = -1.0f;
    }

    D_86204704 = 0;
    D_86203E4C = 0;
    MiniSound_DispatchCommand(0x60002, 0, 0);
    D_86203E48 = 2;
    D_86203E46 = 0;

    sp8C = 0;
    D_86204710 = 99999.0f;

    while (spA4 != 0) {
        RattataGame_PollInput();
        RattataGame_UpdateCamera();

        if (D_8780FC92 != 0) {
            return;
        }

        if (D_8780FC94 == 0) {
            if (D_86204704 >= 0x708) {
                spA4 = 0;
            }

            if (D_86204718 == 1) {
                if ((gPlayer1Controller->buttonPressed != 0) && (sp8C == 0)) {
                    D_86204704 = 0x1C2;
                    sp8C = 1;
                }

                if (D_86204704 == 0x1C2) {
                    StageFade_StartFromTransparent(0x1E);
                    Audio_BeginVolumeTransition(0x1E);
                }

                if (D_86204704 >= 0x1E0) {
                    Widget_PauseMenuTrigger(2);
                    spA4 = 0;
                }
            }

            if (D_86204704 == 0xF) {
                Audio_StartMusicTrack(0x19);
            }

            temp_s1_2 = RattataGame_UpdateRacers();

            for (i = 0; i < 4; i++) {
                RattataGame_UpdateHurdleMarkers(&D_86203E50[i]);
            }

            if (temp_s1_2 > 0) {
                var_v0_2 = 0;
                for (i = 0; i < 4; i++) {
                    var_s0_3 = &D_86203E50[i];
                    if (var_s0_3->unk_1A0 == 1) {
                        f32 tmp = var_s0_3->unk_198;

                        if (tmp < D_86204710) {
                            D_86204710 = tmp;
                        }
                        sp78[var_v0_2++] = var_s0_3;
                    }
                }

                if (temp_s1_2 == 1) {
                    sp78[0]->unk_1B2 = D_86203E4C;
                    sp78[0]->unk_1A0 = 0;
                } else {
                    for (i = 0; i < temp_s1_2 - 1; i++) {
                        for (j = i + 1; j < temp_s1_2; j++) {
                            if (sp78[j]->unk_198 < sp78[i]->unk_198) {
                                temp_v1 = sp78[j];
                                sp78[j] = sp78[i];
                                sp78[i] = temp_v1;
                            }
                        }
                    }

                    sp78[0]->unk_1B2 = D_86203E4C;
                    for (i = 1; i < temp_s1_2; i++) {
                        if (sp78[i - 1]->unk_198 < sp78[i]->unk_198) {
                            D_86203E4C++;
                        }
                        sp78[i]->unk_1B2 = D_86203E4C;
                    }

                    for (i = 0; i < temp_s1_2; i++) {
                        sp78[i]->unk_1A0 = 0;
                    }
                }

                D_86203E4C++;
            }

            var_s3 = 0;
            for (i = 0; i < 4; i++) {
                if (D_86203E50[i].unk_19E == 2) {
                    var_s3++;
                }
            }

            if (var_s3 >= 4) {
                spA4 = 0;
            }

            D_86204704++;
        }

        RattataGame_DrawFrame(D_86203E48);
    }

    var_s3 = 0;
    for (i = 0; i < 4; i++) {
        if (D_86203E50[i].unk_19E == 1) {
            var_s3++;
        }
    }

    while (var_s3 > 0) {
        RattataGame_PollInput();
        RattataGame_UpdateCamera();
        if (D_8780FC92 == 0) {
            if (D_8780FC94 == 0) {
                var_s3 = 0;
                RattataGame_AdvanceFinishLineApproach();

                for (i = 0; i < 4; i++) {
                    RattataGame_UpdateHurdleMarkers(&D_86203E50[i]);
                }

                for (i = 0; i < 4; i++) {
                    if (D_86203E50[i].unk_19E == 1) {
                        var_s3++;
                    }
                }
            }

            RattataGame_DrawFrame(D_86203E48);
        } else {
            return;
        }
    }

    var_s3 = 0;
    D_86204708 = 0;

    for (i = 0; i < 4; i++) {
        temp_s1 = &D_86203E50[i];

        if ((temp_s1->unk_19E > 0) && (temp_s1->unk_1B2 == 0)) {
            Widget_PauseMenuRecordWin(i);
            D_86204708++;
            temp_s1->unk_1C8 = 1;
            if (temp_s1->unk_002 == 0) {
                var_s3 = 1;
            }
        }
    }

    if (D_86204708 != 1) {
        D_8620470A = 1;
    } else if (var_s3 == 1) {
        Audio_StartMusicTrack(0xBD);
    } else {
        Audio_StartMusicTrack(0xBE);
    }
}

void RattataGame_UpdatePostRaceIdleAnim(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;

        if ((D_86204590->unk_19E > 0) && (D_86204590->unk_1C8 == 1)) {
            continue;
        }

        if ((ModelAnim_IsFinished(D_86204594) == 0) && (D_86204594->transformAnim.frameFixed < 0x340000)) {
            continue;
        }

        ModelAnim_SetAnimation(D_86204594, 5);
        D_86204594->transformAnim.frameFixed = 0x270000;
    }
}

void RattataGame_PlayResultAnimation(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;
        if ((D_86204590->unk_19E > 0) && (D_86204590->unk_1C8 == 1)) {
            ModelAnim_SetAnimation(D_86204594, 4);
            D_86204594->transformAnim.speedFixed = 0x10000;
        } else {
            ModelAnim_SetAnimation(D_86204594, 5);
            D_86204594->transformAnim.frameFixed = 0;
            D_86204594->transformAnim.speedFixed = 0x10000;
            ModelAnim_SetEventTrack(D_86204594, 0);
        }
    }

    while (D_8780FC94 != 0) {
        RattataGame_PollInput();
        RattataGame_DrawFrame(D_86203E48);
    }

    Widget_PauseMenuTrigger(1);
    D_86203E48 = 3;

    for (i = 0; i < 120; i++) {
        RattataGame_PollInput();
        RattataGame_UpdateCamera();
        RattataGame_DrawFrame(D_86203E48);
    }

    for (i = 0; i < 30; i++) {
        RattataGame_PollInput();
        RattataGame_UpdateCamera();
        RattataGame_DrawFrame(D_86203E48);
    }
}

void RattataGame_WaitForAudioToFinish(void) {
    while (Audio_GetActivityScore() != 0) {
        RattataGame_PollInput();
        RattataGame_DrawFrame(D_86203E48);
    }
    Audio_ResetVolumeTransition();
}

void RattataGame_FadeOutAndTransition(void) {
    s32 i;

    Audio_FadeOutAll(0x1E);
    StageFade_StartFromTransparent(0x1E);

    for (i = 0; i < 30; i++) {
        RattataGame_PollInput();
        RattataGame_DrawFrame(D_86203E48);
    }
}

void RattataGame_PlayOutroSequence(s32 arg0) {
    s32 i;

    D_86203E48 = 6;

    for (i = 0; i < arg0; i++) {
        RattataGame_PollInput();
        RattataGame_DrawFrame(D_86203E48);
    }
}

void RattataGame_WaitForContinue(void) {
    D_86203E48 = 5;

    while (D_8780FC96 == 0) {
        if ((D_8780FA2A == 1) && (D_8620470E > 0)) {
            D_8620470E -= 0xA;
            if (D_8620470E < 0) {
                D_8620470E = 0;
            }
        }

        RattataGame_PollInput();
        RattataGame_UpdateCamera();
        RattataGame_UpdatePostRaceIdleAnim();
        RattataGame_DrawFrame(D_86203E48);
    }
}

void RattataGame_LoadAssets(void) {
    s32 i;
    s32 j;
    MemoryBlock* temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    DisplayObject* temp_s0;

    D_86203E38 = process_geo_layout(temp_v0, &D_86203D0C);
    MainPool_FinalizeAllocation(temp_v0);
    ModelRenderer_InitDisplayRoots();
    PokeIcon_OpenModelArchives();
    D_8620470E = 0xFF;
    D_8620471A = 0;
    D_86203E30 = Model_LoadByArchiveIndex(0xB8);
    ModelRenderer_AttachDisplayObject(&D_86204598);
    Model_InitDisplayObject(&D_86204598, 0, 0xB8, D_86203E30->unk_08->unk_00[0]);
    D_86204598.position.y = -26.0f;
    D_86203E30 = Model_LoadByArchiveIndex(0xAF);

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        temp_s0 = &D_86204590->unk_008;
        D_86204590->unk_000 = i;

        RattataGame_InitAIDifficulty(D_86204590);
        ModelRenderer_AttachDisplayObject(temp_s0);
        Model_InitDisplayObject(temp_s0, 0, 0xAF, D_86203E30->unk_08->unk_00[0]);
        temp_s0->position.x = -(i - 1.5f) * 40.0f;
        temp_s0->position.y = 0.0f;
        temp_s0->scale.x = 1.0f;
        temp_s0->scale.y = 1.0f;
        temp_s0->scale.z = 1.0f;
        ModelAnim_SetAnimation(temp_s0, 0);
        ModelAnim_ClearEventTrack(temp_s0);
        RattataGame_ResetRacerState(D_86204590);
        temp_s0->transformAnim.speedFixed = 0x20000;
    }

    D_86203E34 = Model_LoadByArchiveIndex(0xB0);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 10; j++) {
            D_86208280 = &D_86204720[i][j];
            temp_s0 = &D_86208280->unk_004;

            ModelRenderer_AttachDisplayObject(temp_s0);

            D_86208280->unk_000 = 0;
            D_86208280->unk_002 = 0;
            temp_s0->position.x = -(i - 1.5f) * 40.0f;
            temp_s0->position.y = -25.0f;
            temp_s0->transformAnim.frameFixed = 0x730000;
            temp_s0->transformAnim.speedFixed = 0;
        }
    }

    RattataGame_InitCamera();
    Widget_CountdownInit();
}

void RattataGame_InitPlayerSlots(void) {
    s32 i;
    s32 j;
    DisplayObject* temp_s0;

    D_86208298 = 0;
    D_8620470A = 0;
    D_8620471C = Rand_Range(3);

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        temp_s0 = &D_86204590->unk_008;

        D_86204590->unk_000 = i;
        D_86204590->unk_19E = 0;
        RattataGame_InitAIDifficulty(D_86204590);
        D_86204590->unk_1A2 = 0;
        D_86204590->unk_1AE = 0;
        D_86204590->unk_1B0 = 0;
        D_86204590->unk_1AC = 0;
        D_86204590->unk_1B2 = 4;
        D_86204590->unk_1B4 = 0;
        D_86204590->unk_170 = 0;
        RattataGame_ResetRacerState(D_86204590);
        temp_s0->position.x = -(i - 1.5f) * 40.0f;
        temp_s0->position.y = 0.0f;
        temp_s0->scale.x = 1.0f;
        temp_s0->scale.y = 1.0f;
        temp_s0->scale.z = 1.0f;
        temp_s0->transformAnim.speedFixed = 0x20000;
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 10; j++) {
            D_86208280 = &D_86204720[i][j];
            temp_s0 = &D_86208280->unk_004;

            D_86208280->unk_000 = 0;
            D_86208280->unk_002 = 0;
            D_86208280->unk_178 = 0;
            D_86208280->unk_170 = 0;
            temp_s0->position.x = -(i - 1.5f) * 40.0f;
            temp_s0->position.y = -25.0f;
            temp_s0->transformAnim.frameFixed = 0x730000;
            temp_s0->transformAnim.speedFixed = 0;
        }
    }
}

void RattataGame_Main(s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    if (arg0 == 1) {
        D_86204718 = 1;
        Minigame_InitSharedState(3);
    } else {
        D_86204718 = 0;
    }

    main_pool_push_state('MINI');

    Gfx_InitDisplayListBuffers(0x10000, 0);

    sp24 = StageContext_Allocate(0, 0, 3, 1, 2, 1);
    D_86204714 = Font_Init(0x16, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_04000000, run_rattata_run_flag_gfx, 0);
    FRAGMENT_LOAD(fragment31);

    Fragment_Load((((u32)&D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, _5C7A70_ROM_END);

    RattataGame_LoadAssets();
    Widget_PauseMenuInit();
    StageContext_Activate(sp24);
    RattataGame_InitPlayerSlots();

    if (RattataGame_WaitForStart() != -1) {
        Audio_FadeOutAll(0x3C);
        RattataGame_PlayOutroSequence(5);
        RattataGame_UpdateStartCountdown();
        RattataGame_MainLoop();
        if ((D_8780FC92 == 0) && (D_86204718 == 0)) {
            RattataGame_PlayResultAnimation();
            RattataGame_WaitForContinue();
        }
    }

    if (D_86204718 == 0) {
        RattataGame_FadeOutAndTransition();
    } else {
        RattataGame_WaitForAudioToFinish();
    }

    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('MINI');

    Widget_PauseMenuGetResult();
}
