#include "gallery_snap.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/text_system.h"
#include "src/ui_graphics.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/audio_loop_point.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/controller_ram.h"
#include "src/controller.h"
#include "src/fragments/gallery_backgrounds/gallery_backgrounds.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_833031B4 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16* unk_0C;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s32 unk_14;
} unk_D_833031B4; // size = 0x18

typedef struct unk_D_83303180 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ s16 unk_08;
} unk_D_83303180; // size = 0xC

static s32 D_833032E0;
static s32 D_833032E4;
static unk_D_83407B38 D_833032E8;
static BinArchive* D_8330339C;
static s32 D_833033A0;
static unk_D_83403C60 D_833033A8;
static s32 D_83303434;
static s32 D_83303438;
static s32 D_8330343C;
static s32 D_83303440;
static s32 D_83303444;

static unk_D_83303180 D_83303180[] = {
    { NULL, 0x30, 0x23, 0 },
    { D_03002A40, 0x20, 0x24, 7 },
    { NULL, 0x30, 0x23, 8 },
};

static s16 D_833031A4[] = { 0x11 };
static s16 D_833031A8[] = { 0x12 };
static s16 D_833031AC[] = { 0x13 };
static s16 D_833031B0[] = { -1, 0x15 };

static unk_D_833031B4 D_833031B4[] = {
    {
        D_03001000,
        48,
        35,
        5,
        11,
        NULL,
        1,
        0,
        28,
    },
    {
        D_3001D20,
        48,
        35,
        6,
        12,
        D_833031A4,
        1,
        0,
        28,
    },
    {
        D_03002A40,
        32,
        36,
        7,
        13,
        D_833031A8,
        1,
        0,
        28,
    },
    {
        NULL,
        48,
        35,
        8,
        14,
        D_833031AC,
        1,
        0,
        28,
    },
    {
        D_03003340,
        32,
        36,
        61,
        62,
        NULL,
        1,
        0,
        SFX_MENU_CONFIRM,
    },
    {
        D_03003C40,
        32,
        36,
        -1,
        -1,
        D_833031B0,
        1,
        0,
        28,
    },
    {
        NULL,
        0,
        0,
        10,
        16,
        NULL,
        2,
        0,
        SFX_MENU_BACK,
    },
};
static s16 D_8330325C[2] = { 0x108, 0x108 };
static s16 D_83303260[2] = { 0x5C, 0x5C };
static s16 D_83303264[2] = { 0x98, 0x4C };
static s16 D_83303268[2] = { 0x7A, 0x3D };
static s32 D_8330326C[] = { 5, 3, 3, 0, 0, 7, 8 };

void Gallery_SnapDrawRoundedFrame(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg7);

    Gfx_DrawTextureIa8(arg0 - 7, arg1 - 7, 8, 8, &D_300BE40, 8, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 1, arg1 - 7, 8, 8, &D_300BE80, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 1, arg1 - 7, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTextureIa8(arg0 - 7, (arg1 + arg3) - 1, 8, 8, &D_300BEC0, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 - 7, arg1 + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);
    Gfx_DrawTextureIa8((arg0 + arg2) - 1, (arg1 + arg3) - 1, 8, 8, &D_300BF00, 8, 0);
    Gfx_DrawTexturedRectClipped(arg0 + 1, (arg1 + arg3) - 1, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    Gfx_DrawTexturedRectClipped((arg0 + arg2) - 1, arg1 + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    Gfx_FillRectRgba(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

unk_D_83407B38* Gallery_SnapGetActiveGrid(void) {
    unk_D_83407B38* ret;

    if (D_83407AE4 == 0) {
        ret = &D_833032E8;
    } else {
        ret = &D_83407B38;
    }
    return ret;
}

void Gallery_SnapUpdateMenuIconStates(void) {
    unk_D_833031B4* ptr;
    s32 sp28;
    s32 i;
    s32 sp20;
    s16 sp1C[2];
    u8* sp18;
    s32 var_v0;

    sp28 = Gallery_CountValidPhotos(D_83403C60, 0x24, 1);
    if (D_83407AE4 == 0) {
        sp1C[1] = 0xF;
        sp1C[0] = 0x14;
        var_v0 = Gallery_CountValidPhotos(D_83407ABC, 4, 1);
        sp20 = 4;
        sp18 = D_3004540;
    } else {
        sp1C[1] = 0x3F;
        sp1C[0] = 0x40;
        var_v0 = Gallery_CountValidPhotos(D_83407AC0, 0x10, 1);
        sp20 = 0x10;
        sp18 = D_3005260;
    }

    ptr = &D_833031B4[0];

    for (i = 0; i < 7; i++, ptr++) {
        switch (i) {
            case 1:
            case 2:
                if (sp28 > 0) {
                    ptr->unk_12 = 0;
                } else {
                    ptr->unk_12 = 1;
                }
                break;

            case 3:
                if (var_v0 > 0) {
                    ptr->unk_12 = 0;
                } else {
                    ptr->unk_12 = 1;
                }
                ptr->unk_00 = sp18;
                break;

            case 5:
                if (D_83407AE8 == 0) {
                    ptr->unk_08 = 9;
                    ptr->unk_0A = sp1C[1];
                } else {
                    ptr->unk_08 = 0x44;
                    ptr->unk_0A = 0x46;
                }

                D_833031B0[0] = sp1C[0];

                if ((var_v0 < sp20) && (D_83407AE8 == 0)) {
                    ptr->unk_12 = 1;
                } else if (D_8330343C == 0) {
                    ptr->unk_12 = 2;
                } else {
                    ptr->unk_12 = 0;
                }
                break;

            default:
                ptr->unk_12 = 0;
                break;
        }
    }
}

s32 Gallery_SnapConfirmSaveBackgrounds(void) {
    s32 sp1C = 0;

    if (Gallery_BackgroundsChanged() != 0) {
        D_833032E4 = 6;
        Gallery_OpenConfirmPrompt(3, gPlayer1Controller);
        D_83303438 = 4;
    } else {
        sp1C = 1;
    }
    return sp1C;
}

s32 Gallery_SnapUpdateMenuInput(void) {
    s32 sp2C;
    s32 sp28;
    unk_D_833031B4* sp24;
    s32 sp20;
    s32 sp1C;

    sp2C = 0;
    sp28 = 0;
    sp20 = D_83407AE8;
    sp1C = D_83402E28;

    if (Gallery_FindReadyScene(Gallery_SnapGetActiveGrid()->unk_20, 0x25) != -1) {
        return 0;
    }

    if (gPlayer1Controller->buttonPressed & 0x800) {
        D_83402E28--;
        if (D_83402E28 < 0) {
            D_83402E28 = 6;
        }
    } else if (gPlayer1Controller->buttonPressed & 0x400) {
        D_83402E28++;
        if (D_83402E28 >= 7) {
            D_83402E28 = 0;
        }
    } else if (gPlayer1Controller->buttonPressed & 0x4000) {
        sp2C = 1;
        D_83402E28 = 6;
    }

    if (sp1C != D_83402E28) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    sp24 = &D_833031B4[D_83402E28];

    if (sp1C != D_83402E28) {
        D_833033A0 = 0;
        D_83303444 = 0;
    }

    if ((D_83407AEC != 0) && (D_83303444 == 0)) {
        if ((gPlayer1Controller->buttonDown & 0x20) && (gPlayer1Controller->buttonDown & 0x10) && (D_83402E28 == 5)) {
            D_83407AE8 = 1;
        } else {
            D_83407AE8 = 0;
        }
    }

    if (sp20 != D_83407AE8) {
        D_833033A0 = 0;
        Gallery_SnapUpdateMenuIconStates();
    }

    if (sp2C != 0) {
        if (Gallery_SnapConfirmSaveBackgrounds() != 0) {
            sp28 = 1;
        }
        Audio_PlaySoundEffectById(sp24->unk_14);
    } else if (gPlayer1Controller->buttonPressed & 0x8000) {
        if (sp24->unk_12 == 0) {
            switch (D_83402E28) {
                default:
                    sp28 = 1;
                    break;

                case 3:
                    D_833032E0 = 2;
                    D_833032E4 = 3;
                    break;

                case 4:
                    D_83407AE4 ^= 1;
                    Gallery_SnapUpdateMenuIconStates();
                    break;

                case 5:
                    if (D_83407AE8 != 0) {
                        sp28 = 2;
                    } else {
                        D_833032E4 = 5;
                        D_83303434 = 0;
                    }
                    break;

                case 6:
                    if (Gallery_SnapConfirmSaveBackgrounds() != 0) {
                        sp28 = 1;
                    }
                    break;
            }
            Audio_PlaySoundEffectById(sp24->unk_14);
        } else if ((D_83402E28 == 5) && (D_83407AE8 != 0)) {
            sp28 = 2;
            Audio_PlaySoundEffectById(sp24->unk_14);
        } else {
            D_833033A0 = 1;
            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
        }
    }
    return sp28;
}

void Gallery_SnapResetToMenu(void) {
    D_833032E0 = 0;
    D_833032E4 = 1;
    Gallery_InitPageCursor(&D_83407B30);
}

s32 Gallery_SnapUpdateGridInput(unk_D_83407B38* arg0) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    unk_func_80031270* sp38;
    UNUSED s32 pad[2];
    s32 idx;
    unk_func_80031270* sp28;

    sp4C = 0;
    sp48 = arg0->unk_00;
    Gallery_IndexToGridPos(arg0, &sp44, &sp40, sp48);
    if (Gallery_FindReadyScene(arg0->unk_20, 0x25) != -1) {
        return 0;
    }

    if (gPlayer1Controller->buttonPressed & 0x800) {
        sp40--;
        if (sp40 < 0) {
            sp40 = arg0->unk_1C - 1;
        }
    }

    if (gPlayer1Controller->buttonPressed & 0x400) {
        sp40++;
        if (sp40 >= arg0->unk_1C) {
            sp40 = 0;
        }
    }

    if (gPlayer1Controller->buttonPressed & 0x200) {
        sp44--;
        if (sp44 < 0) {
            sp44 = arg0->unk_18 - 1;
        }
    }

    if (gPlayer1Controller->buttonPressed & 0x100) {
        sp44++;
        if (sp44 >= arg0->unk_18) {
            sp44 = 0;
        }
    }

    arg0->unk_00 = Gallery_GridPosToIndex(arg0, sp44, sp40);
    if (arg0->unk_00 != sp48) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    if (gPlayer1Controller->buttonPressed & 0x8000) {
        sp3C = (arg0->unk_08 * arg0->unk_14) + arg0->unk_00;
        sp38 = arg0->unk_20[sp3C];
        if (arg0->unk_04 == -1) {
            if (Gallery_IsSceneReady(sp38) != 0) {
                arg0->unk_04 = sp3C;
                arg0->unk_B0->unk_18 = sp38->unk_18;
                arg0->unk_B0->unk_00 = 0;
                Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
            } else {
                Audio_PlaySoundEffectById(SFX_MENU_ERROR);
            }
        } else {
            if ((arg0->unk_04 >= 0) && (arg0->unk_04 < arg0->unk_14)) {
                if (sp3C != arg0->unk_04) {
                    sp38->unk_00 = 0;
                    arg0->unk_20[arg0->unk_04]->unk_00 = 0;
                    Gallery_SwapPhotoRecords(sp38->unk_18, arg0->unk_B0->unk_18);
                    Audio_PlaySoundEffectById(0x29);
                } else {
                    Audio_PlaySoundEffectById(SFX_MENU_BACK);
                }
            } else {
                if (Gallery_PhotoRecordsEqual(arg0->unk_B0->unk_18, sp38->unk_18) == 0) {
                    Audio_PlaySoundEffectById(0x31);
                    D_833032E4 = 4;

                    D_833033A8 = *sp38->unk_18;
                    *sp38->unk_18 = *arg0->unk_B0->unk_18;

                    sp38->unk_00 = 0;
                } else {
                    Audio_PlaySoundEffectById(SFX_MENU_BACK);
                    Gallery_SnapResetToMenu();
                }
            }
            arg0->unk_04 = -1;
        }
    } else if (gPlayer1Controller->buttonPressed & 0x4000) {
        if (arg0->unk_04 == -1) {
            D_833032E0 = 0;
            D_833032E4 = 1;
        } else {
            if (arg0->unk_04 >= 4) {
                Gallery_InitPageCursor(&D_83407B30);
                D_833032E0 = 0;
                D_833032E4 = 1;
            }
            arg0->unk_04 = -1;
        }
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    } else if (gPlayer1Controller->buttonPressed & 4) {
        idx = (arg0->unk_08 * arg0->unk_14) + arg0->unk_00;
        if (arg0->unk_04 == -1) {
            sp28 = arg0->unk_20[idx];
        } else {
            sp28 = arg0->unk_B0;
        }

        if ((arg0->unk_04 == -1) && (Gallery_IsSceneReady(sp28) != 0)) {
            sp4C = 1;
            Audio_PlaySoundEffectById(SFX_ZOOM_IN);
            Gallery_SetEnlargeTarget(sp28->unk_18);
        } else {
            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
        }
    }

    return sp4C;
}

void Gallery_SnapDrawScaledImage(u16* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6) {
    s32 temp_fa0;
    s32 temp_fa0_2;
    s32 temp_fv1;
    s32 temp_fv1_2;
    s32 tmp = G_TX_NOMIRROR | G_TX_CLAMP;

    if ((arg5 == 0.0f) || (arg6 == 0.0f)) {
        return;
    }

    gDPLoadTextureTile(gDisplayListHead++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg3, 0, 0, 0, arg3, arg4 - 1, 0, tmp,
                       tmp, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    temp_fv1 = ROUND_MAX(arg3 * arg5);
    temp_fa0 = ROUND_MAX(arg4 * arg6);
    temp_fv1_2 = ROUND_MAX(arg3 * (arg5 - 1.0f) * 0.5f);
    temp_fv1_2 = -temp_fv1_2;
    temp_fa0_2 = ROUND_MAX(arg4 * (arg6 - 1.0f) * 0.5f);

    Gfx_DrawTexturedRectClipped(arg1 + temp_fv1_2, arg2 - temp_fa0_2, temp_fv1, temp_fa0, 0, 0, 1024.0f / arg5, 1024.0f / arg6, 0);
}

void func_83301090(void) {
    static s16 D_83303288 = 0;
    static s16 D_8330328C = 0x3200;

    f32 temp_fs0;
    f32 temp_fs1;
    s32 temp_s2;
    s32 temp_t0;
    char* temp_v0_4;
    s32 i;
    u8 tmp;
    u8 tmp2;
    u8 r;

    temp_fs0 = (SINS(D_83303288) * 0.2f) + 1.0f;
    temp_fs1 = (SINS(D_83303288 + D_8330328C) * 0.2f) + 1.0f;

    D_83303288 += 0x2000;

    for (i = 0; i < 7; i++) {
        tmp = (D_833031B4[i].unk_12 == 0) ? 0xFF : 0x40;

        if (D_833031B4[i].unk_10 == 1) {
            Gallery_SnapDrawRoundedFrame(0x46, 0x4E + i * 0x36, 0x7F, 0x18, 0x1E, 0x1E, 0x82, tmp);
        } else {
            Gallery_SnapDrawRoundedFrame(0x46, 0x4E + i * 0x36, 0x7F, 0x18, 0x1E, 0x64, 0x1E, tmp);
        }
    }

    Gallery_SnapDrawCursor(Gallery_SnapGetActiveGrid());

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 7; i++) {
        temp_t0 = -D_833031B4[i].unk_04 + 0xC;

        if (D_833031B4[i].unk_12 == 0) {
            r = 0xFF;
        } else {
            r = 0x40;
        }

        if (D_833031B4[i].unk_00 != NULL) {
            gDPPipeSync(gDisplayListHead++);

            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, r);

            if ((i == D_83402E28) && (D_833031B4[i].unk_12 == 0)) {
                Gallery_SnapDrawScaledImage(D_833031B4[i].unk_00, temp_t0 + 0x46, (i * 0x36) + 0x48, D_833031B4[i].unk_04,
                              D_833031B4[i].unk_06, temp_fs0, temp_fs1);
            } else {
                Gallery_DrawImageStrips(D_833031B4[i].unk_00, temp_t0 + 0x46, (i * 0x36) + 0x48, D_833031B4[i].unk_04,
                              D_833031B4[i].unk_06, 0);
            }
        }
    }

    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);

    for (i = 0; i < 7; i++) {
        temp_v0_4 = Gallery_GetUiString(D_833031B4[i].unk_08);
        temp_s2 = ((0x73 - Font_MeasureTextExtent(0, 0, temp_v0_4)) / 2) + 0xC;
        tmp2 = (D_833031B4[i].unk_12 == 0) ? 0xFFu : 0x40u;

        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, tmp2);
        Font_Printf(temp_s2 + 0x46, 0x50 + i * 0x36, temp_v0_4);
    }

    Font_EndTexturedTextRendering();
}

void Gallery_SnapDrawTitleBar(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp3C;
    UNUSED s32 pad;
    char* sp34;
    Color_RGBA8 sp30 = { 0x9A, 0x37, 0x54, 0xFF };
    Color_RGBA8 sp2C = { 0xC3, 0x54, 0x84, 0xFF };
    unk_D_83303180* sp20;

    Gallery_DrawHeaderBar(arg0, arg1, 0x186, &sp30, &sp2C);

    if ((D_833032E0 != 0) && (D_833032E0 != 2)) {
        sp20 = &D_83303180[arg2];
    } else if (D_83407AE4 == 0) {
        sp20 = &D_83303180[arg2];
        do {
            sp20->unk_00 = D_3004540;
        } while (0);
    } else {
        sp20 = &D_83303180[arg2];
        sp20->unk_00 = D_3005260;
    }

    if (sp20->unk_00 != NULL) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);

        Gallery_DrawImageStrips(sp20->unk_00, arg0 + 0x10, arg1 - 1, sp20->unk_04, sp20->unk_06, 0);
    }

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    sp34 = Gallery_GetUiString(sp20->unk_08);
    sp3C = (0x186 - Font_MeasureTextExtent(0, 0, sp34)) / 2;
    Gfx_SetEnvColor(0, 0, 0, 0xFF);
    Font_Printf(arg0 + sp3C + 2, arg1 + 5, sp34);
    Gfx_SetEnvColor(0xFF, 0xFF, 0x77, 0xFF);
    Font_Printf(arg0 + sp3C, arg1 + 3, sp34);
    Font_EndTexturedTextRendering();
}

void Gallery_SnapDrawHintBox(unk_D_83407B38* arg0, s32 arg1, s32 arg2) {
    unk_D_833031B4* temp_v1 = &D_833031B4[D_83402E28];
    char* sp18 = NULL;

    switch (D_833032E0) {
        case 0:
            if (D_833032E4 == 5) {
                switch (D_83303434) {
                    case 0:
                        if (D_83407AE8 == 0) {
                            sp18 = Gallery_GetUiString(0x1B);
                        } else {
                            sp18 = Gallery_GetUiString(0x45);
                        }
                        break;

                    case 1:
                        sp18 = Gallery_GetUiString(0x1D);
                }
                break;
            } else if ((D_833033A0 != 0) && (temp_v1->unk_0C != NULL)) {
                sp18 = Gallery_GetUiString(temp_v1->unk_0C[temp_v1->unk_12 - 1]);
            } else {
                sp18 = Gallery_GetUiString(temp_v1->unk_0A);
            }
            break;

        case 1:
            if (D_833032E4 == 4) {
                sp18 = Gallery_GetUiString(0x17);
            } else {
                sp18 = Gallery_GetUiString(0x16);
            }
            break;

        case 2:
            if (arg0->unk_04 == -1) {
                sp18 = Gallery_GetUiString(0x19);
            } else {
                sp18 = Gallery_GetUiString(0x1A);
            }
            break;
    }

    Gallery_DrawBluePanel(arg1, arg2, 0x186, 0x4C);

    if (sp18 != NULL) {
        if (1) {}
        if (1) {}
        if (1) {}
        Font_BeginTranslucentTextRendering();
        Font_SetActive(8, 0);
        Font_SetLineHeight(0x14);
        Font_Printf(arg1 + 0xA, arg2 + 8, sp18);
        Font_EndTexturedTextRendering();
    }
}

void Gallery_SnapInit(s32 arg0, s32 arg1) {
    unk_D_83407B38* temp_v0_2;
    ModelLoadContext* sp30;

    switch (arg0) {
        case 1:
            D_833032E0 = 1;
            break;

        case 2:
            D_833032E0 = 2;
            break;

        default:
            D_833032E0 = 0;
            break;
    }

    D_833032E4 = 0;
    D_83303438 = -1;
    D_833033A0 = 0;
    D_83303434 = 0;
    D_83303444 = 0;

    if (arg1 == 0) {
        D_83407AE8 = 0;
    } else {
        D_83407AE8 = 1;
        D_83303444 = 1;
    }

    if (Controller_CheckAccessoryEeprom() != 0) {
        D_8330343C = 1;
    } else {
        D_8330343C = 0;
    }

    Gallery_ResetPhotoPool();
    Gallery_SnapUpdateMenuIconStates();
    ModelRenderer_InitDisplayRoots();
    sp30 = PokeIcon_AllocFramebuffers(5);
    Gallery_InitSceneGrid(&D_833032E8, 0x3C, 0x2D, 4, 2, sp30, D_8330339C, D_83407ABC, 4, 1);
    Gallery_RebindSceneGridResources(&D_83407B38, sp30, D_8330339C);

    if (D_833032E0 == 1) {
        temp_v0_2 = Gallery_SnapGetActiveGrid();
        temp_v0_2->unk_04 = 0x400;
        temp_v0_2->unk_B0->unk_18 = &D_83403C60[D_83407B30.unk_04];
        temp_v0_2->unk_B0->unk_00 = 0;
    } else if (D_833032E0 == 2) {
        Gallery_RestorePosition(&D_833032E8, &D_83407B00);
        Gallery_RestorePosition(&D_83407B38, &D_83407B08);
    }

    Gallery_ResetConfirmPrompt();
}

void Gallery_SnapDrawGradientQuad(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGBA8* arg4, Color_RGBA8* arg5) {
    unk_D_80068BB0* temp_s1 = GfxImage_GetCurrent();
    Vtx* temp_s2 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    Mtx* sp84 = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    Vp* sp80 = Gfx_AllocDisplayList(sizeof(Vp) * 1);

    Gfx_SetViewportDimensions(sp80, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp80 & 0x1FFFFFFF);

    guOrtho(sp84, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    Gfx_SetVertexAttributes(&temp_s2[0], arg0, arg1, -1, 0, 0, arg4->r, arg4->g, arg4->b, arg4->a);
    Gfx_SetVertexAttributes(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, arg5->r, arg5->g, arg5->b, arg5->a);
    Gfx_SetVertexAttributes(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, arg4->r, arg4->g, arg4->b, arg4->a);
    Gfx_SetVertexAttributes(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, arg5->r, arg5->g, arg5->b, arg5->a);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                 G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)sp84 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}

void Gallery_SnapDrawBackgroundWipe(void) {
    static Color_RGBA8 D_83303298 = { 0, 0, 0, 0xFF };
    static Color_RGBA8 D_8330329C = { 0, 0, 0, 0 };
    static s32 D_833032A0 = 0xBE;
    static s32 D_833032A4 = 0xFA;

    s32 var_ra;
    Color_RGBA8 sp80 = D_83303298;
    Color_RGBA8 sp7C = D_8330329C;

    if (D_83303438 > 0) {
        D_83303438--;
    }

    if (D_83303438 == 0) {
        var_ra = 0x12C;
    } else {
        var_ra = 0x280;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0, ENVIRONMENT,
                      PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 40, 40, 55, 255);
    gDPSetEnvColor(gDisplayListHead++, 150, 95, 110, 255);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3000000, G_IM_FMT_I, 128, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 7, 6, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(D_833032A0, 0, var_ra - D_833032A0, 0x1E0, 0, 0, 0x400, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
    gSPDisplayList(gDisplayListHead++, D_8006F4C0);
    gDPSetFillColor(gDisplayListHead++, 0x00000001);
    gDPFillRectangle(gDisplayListHead++, 0, 0, D_833032A0 - 1, 479);
    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Gallery_SnapDrawGradientQuad(D_833032A0, 0, D_833032A4 - D_833032A0, 0x1E0, &sp80, &sp7C);
}

void func_83302068(unk_D_83407B38* arg0) {
    s32 pad0[4];
    s32 sp8C;
    s16 temp_fp;
    s16 temp_s4;
    s16 temp_s5;
    s32 temp_s0;
    s32 var_s6;
    s32 sp78;
    s32 sp74;
    unk_func_80031270* temp_s1;
    s32 i;
    s32 sp68;
    s32 sp64;
    s32 j;
    s32 jy;
    s32 jx;

    temp_fp = D_8330325C[D_83407AE4];
    temp_s4 = D_83303264[D_83407AE4];
    temp_s5 = D_83303268[D_83407AE4];
    sp8C = D_83303260[D_83407AE4];

    if (D_83407AE4 == 0) {
        var_s6 = 4;
    } else {
        var_s6 = 1;
    }

    for (i = 0; i < arg0->unk_14; i++) {
        temp_s0 = (arg0->unk_08 * arg0->unk_14) + i;
        Gallery_IndexToGridPos(arg0, &sp78, &sp74, i);
        temp_s1 = arg0->unk_20[temp_s0];

        if ((i != arg0->unk_04) && (Gallery_IsSceneReady(temp_s1) != 0) && (temp_s1->unk_00 == 2)) {
            for (j = 0; j < var_s6; j++) {
                Gallery_DrawPhotoThumbnail(temp_s1->unk_08->img_p, (temp_s4 * sp78) + temp_fp + ((temp_s4 / 2) * (j % 2)),
                              (temp_s5 * sp74) + sp8C + ((temp_s5 / 2) * (j / 2)), temp_s1->unk_04, temp_s1->unk_06, 8,
                              1);
            }
        }
    }

    if (arg0->unk_04 != -1) {
        Gallery_IndexToGridPos(arg0, &sp68, &sp64, arg0->unk_00);
        temp_s1 = arg0->unk_B0;
        if ((Gallery_IsSceneReady(temp_s1) != 0) && (temp_s1->unk_00 == 2)) {
            for (j = 0; j < var_s6; j++) {
                jx = j % 2;
                jy = j / 2;
                Gallery_DrawDropShadow((temp_s4 * sp68) + temp_fp + ((temp_s4 / 2) * (j % 2)),
                              (temp_s5 * sp64) + sp8C + ((temp_s5 / 2) * (j / 2)),
                              temp_s1->unk_04, temp_s1->unk_06);

                Gallery_DrawPhotoThumbnail(temp_s1->unk_08->img_p,
                              ((temp_s4 * sp68) + temp_fp + ((temp_s4 / 2) * jx)) - 0x10,
                              ((temp_s5 * sp64) + sp8C + ((temp_s5 / 2) * jy)) - 0x10,
                              temp_s1->unk_04, temp_s1->unk_06, 8, 1);
            }
        }
    }
}

void Gallery_SnapDrawCursor(unk_D_83407B38* arg0) {
    unk_func_80031270* temp_s0;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 var_a2;
    s32 var_a3;
    s32 var_v0;

    sp50 = D_8330325C[D_83407AE4];
    sp4C = D_83303260[D_83407AE4];
    sp48 = D_83303264[D_83407AE4];
    sp44 = D_83303268[D_83407AE4];
    temp_s0 = arg0->unk_B0;
    Gallery_IndexToGridPos(arg0, &sp58, &sp54, arg0->unk_00);

    switch (D_833032E0) {
        case 0:
            gSPDisplayList(gDisplayListHead++, D_8006F518);
            Gallery_DrawSelectionCorners(0x3E, (D_83402E28 * 0x36) + 0x46, 0x8F, 0x28);
            break;

        case 2:
            gSPDisplayList(gDisplayListHead++, D_8006F518);

            if (arg0->unk_04 == -1) {
                var_v0 = 0;
            } else {
                var_v0 = -0x10;
            }

            if (D_83407AE4 == 0) {
                var_a2 = (temp_s0->unk_04 * 2) + 0x18;
                var_a3 = (temp_s0->unk_06 * 2) + 0x18;
            } else {
                var_a2 = temp_s0->unk_04 + 8;
                var_a3 = temp_s0->unk_06 + 8;
            }
            Gallery_DrawSelectionCorners(((sp48 * sp58) + sp50 + var_v0) - 4, ((sp44 * sp54) + sp4C + var_v0) - 4, var_a2, var_a3);
            break;

        case 1:
            if ((arg0->unk_04 != -1) && (Gallery_IsSceneReady(temp_s0) != 0) && (temp_s0->unk_00 == 2)) {
                gSPDisplayList(gDisplayListHead++, D_8006F518);

                if (D_83407AE4 == 0) {
                    var_a2 = (temp_s0->unk_04 * 2) + 0x18;
                    var_a3 = (temp_s0->unk_06 * 2) + 0x18;
                } else {
                    var_a2 = temp_s0->unk_04 + 8;
                    var_a3 = temp_s0->unk_06 + 8;
                }
                Gallery_DrawSelectionCorners(((sp48 * sp58) + sp50) - 0x14, ((sp44 * sp54) + sp4C) - 0x14, var_a2, var_a3);
            }
            break;
    }
}

void Gallery_SnapDrawBackPrompt(s32 arg0) {
    s8* sp2C;
    s32 temp_v1;

    sp2C = Gallery_GetUiString(0x3C);
    temp_v1 = ((0x186 - Font_MeasureTextExtent(0, 0, sp2C)) / 2) + 0xD5;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    Gfx_DrawTextureRgba16(temp_v1 - 0x20, arg0 - 2, 0x18, 0x18, D_30099B8, 0x18, 0);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    Font_Printf(temp_v1, arg0, sp2C);
    Font_EndTexturedTextRendering();
}

void Gallery_SnapDrawFrame(void) {
    UNUSED s32 pad;
    unk_D_83407B38* sp18 = Gallery_SnapGetActiveGrid();

    BgStage_DrawFrame();
    Gallery_SnapDrawBackgroundWipe();
    Gallery_SnapDrawTitleBar(0xD5, 0x24, D_833032E0);
    func_83302068(sp18);
    func_83301090();

    if ((D_833032E0 == 2) && (sp18->unk_04 == -1)) {
        Gallery_SnapDrawBackPrompt(0x158);
    }

    Gallery_SnapDrawHintBox(sp18, 0xD5, 0x172);
    Gallery_DrawConfirmPrompt(1);
    BgStage_AdvanceFrame();
}

void Gallery_SnapUpdatePasteConfirm(unk_D_83407B38* arg0) {
    s32 var_a2 = 0;
    s32 idx = (arg0->unk_08 * arg0->unk_14) + arg0->unk_00;
    unk_func_80031270* temp_v1 = arg0->unk_20[idx];

    if (gPlayer1Controller->buttonPressed & 0x8000) {
        Audio_PlaySoundEffectById(0x29);
        var_a2 = 1;
        Gallery_SnapUpdateMenuIconStates();
    } else if (gPlayer1Controller->buttonPressed & 0x4000) {
        *temp_v1->unk_18 = D_833033A8;
        temp_v1->unk_00 = 0;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        var_a2 = 1;
    }

    if (var_a2 != 0) {
        Gallery_SnapResetToMenu();
    }
}

void Gallery_SnapUpdateSaveConfirm(void) {
    static s32 D_833032A8 = 0;

    if (D_833033A0 != 0) {
        if (D_833032A8 > 0) {
            D_833032A8--;
            if (D_833032A8 == 0) {
                D_83303434 = 1;
                Audio_PlaySoundEffectById(SFX_MENU_ERROR);
            }
        }
    }

    if (D_833032A8 <= 0) {
        if (gPlayer1Controller->buttonPressed & 0x8000) {
            Audio_PlaySoundEffectById(0x1C);
            Gallery_SaveUnlockedBackgrounds(1, D_8330343C);
            if (D_8330343C != 0) {
                Controller_WriteAccessoryStatus(0x5A);
            }
            D_833033A0 = 1;
            D_833032A8 = 4;
        } else if (gPlayer1Controller->buttonPressed & 0x4000) {
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
            D_833032E4 = 1;
            D_833033A0 = 0;
            D_83303434 = 0;
        }
    }
}

void Gallery_SnapUpdateExitConfirm(void) {
    s16 temp_v0;
    s32 var_a2;

    temp_v0 = Gallery_GetConfirmPromptResult(3);
    if (temp_v0 != -1) {
        var_a2 = 0;
        if (temp_v0 == -2) {
            temp_v0 = 2;
        }

        switch (temp_v0) {
            case 0:
                D_833032E4 = 7;
                Gallery_OpenConfirmPrompt(4, gPlayer1Controller);
                var_a2 = 0;
                D_83303440 = 6;
                break;

            case 1:
                var_a2 = 1;
                break;

            default:
                D_833032E4 = 1;
                break;
        }

        if (var_a2 != 0) {
            D_833032E4 = 8;
            StageContext_SetClearColor(0xFFFF);
            StageFade_StartFromTransparent(0xF);
            if (D_8330326C[D_83402E28] == 8) {
                Audio_FadeOutAll(0xF);
            }
        }
    }
}

void Gallery_SnapUpdateExitDelay(void) {
    D_83303440--;
    if (D_83303440 <= 0) {
        Gallery_RequestCloseConfirmPrompt(4);
        Gallery_SaveUnlockedBackgrounds(0, D_8330343C);
        D_833032E4 = 8;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xF);
        if (D_8330326C[D_83402E28] == 8) {
            Audio_FadeOutAll(0xF);
        }
    }
}

s32 Gallery_SnapUpdate(void) {
    static s32 D_833032AC = 2;

    s32 temp_v0_2;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    unk_D_833031B4* sp1C;
    s32 sp18;

    sp28 = 1;
    sp24 = D_833032E4;
    sp20 = D_83407AE4;
    sp1C = &D_833031B4[D_83402E28];

    switch (D_833032E4) {
        case 0:
            if (StageContext_GetFadeMode() == 0) {
                D_833032AC--;
                if (D_833032AC <= 0) {
                    switch (D_833032E0) {
                        case 0:
                            if (D_83407AE8 != 0) {
                                if (sp1C->unk_12 == 0) {
                                    D_833032E4 = 5;
                                    D_83303434 = 0;
                                } else {
                                    D_833032E4 = 1;
                                    D_833033A0 = 1;
                                    Audio_PlaySoundEffectById(SFX_MENU_ERROR);
                                }
                            } else {
                                D_833032E4 = 1;
                            }
                            break;

                        case 1:
                            D_833032E4 = 2;
                            break;

                        case 2:
                            D_833032E4 = 3;
                            break;
                    }
                }
            }
            break;

        case 1:
            temp_v0_2 = Gallery_SnapUpdateMenuInput();
            if (temp_v0_2 != 0) {
                D_833032E4 = 8;
                if (temp_v0_2 == 2) {
                    StageContext_SetClearColor(1);
                    sp18 = 8;
                } else {
                    sp18 = 0xF;
                    if (sp18) {}
                    StageContext_SetClearColor(0xFFFF);
                }
                StageFade_StartFromTransparent(sp18);
                if (D_8330326C[D_83402E28] == 8) {
                    Audio_FadeOutAll(sp18);
                }
            }

            if (D_833032E4 != 1) {
                D_83303438 = -1;
            }
            break;

        case 2:
        case 3:
            if (Gallery_SnapUpdateGridInput(Gallery_SnapGetActiveGrid()) != 0) {
                D_833032E4 = 8;
                StageContext_SetClearColor(1);
                StageFade_StartFromTransparent(1);
            }
            break;

        case 4:
            Gallery_SnapUpdatePasteConfirm(Gallery_SnapGetActiveGrid());
            break;

        case 5:
            Gallery_SnapUpdateSaveConfirm();
            break;

        case 6:
            Gallery_SnapUpdateExitConfirm();
            break;

        case 7:
            Gallery_SnapUpdateExitDelay();
            break;

        case 8:
            if (StageContext_GetFadeMode() == 1) {
                sp28 = 0;
            }
            break;
    }

    if (((sp24 != D_833032E4) && (D_833032E4 == 1)) || (sp20 != D_83407AE4)) {
        D_83303438 = 4;
    }
    return sp28;
}

void Gallery_SnapReadInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void Gallery_SnapLoop(void) {
    s32 var_a0;

    if (D_833032E0 == 2) {
        var_a0 = 1;
    } else {
        var_a0 = 7;
    }
    StageFade_StartFromOpaque(var_a0);

    do {
        Gallery_SnapReadInput();

        if ((Gallery_UpdateConfirmPrompt() != 0) && (D_83303438 == 0)) {
            D_83303438 = -1;
        }

        switch (D_833032E4) {
            case 0:
            case 8:
                break;

            default:
                Gallery_ProcessSceneGrid(Gallery_SnapGetActiveGrid());
                break;
        }

        Gallery_SnapDrawFrame();
        Gallery_FinishActiveScene();
    } while (Gallery_SnapUpdate() != 0);
}

s32 Gallery_SnapGetResult(void) {
    s32 sp1C = D_8330326C[D_83402E28];

    if (Gallery_GetEnlargeTarget(0) != NULL) {
        sp1C = 4;
    }

    if (D_83402E28 == 2) {
        D_83407B30.unk_00 = 1;
    }

    Gallery_SavePosition(&D_833032E8, &D_83407B00);
    Gallery_SavePosition(&D_83407B38, &D_83407B08);

    return sp1C;
}

void Gallery_SnapMain(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('SNAP');

    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    Font_Init(0x18, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, gallery_ui, 0);
    ASSET_LOAD(D_5000000, snap_mode_ui, 0);

    FRAGMENT_LOAD(fragment31);

    PokeIcon_OpenModelArchives();
    D_8330339C = ASSET_LOAD2(stadium_models, 1, 1);
    Text_InitStringTables();
    Gallery_InitStringTables();
    Gallery_SnapInit(arg0, arg1);
    StageContext_Activate(sp24);
    Gallery_SnapLoop();
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('SNAP');

    Gallery_SnapGetResult();
}
