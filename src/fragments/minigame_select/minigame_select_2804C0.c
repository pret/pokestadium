#include "minigame_select.h"
#include "src/graphics_textures.h"
#include "src/text_system.h"
#include "src/fragments/widget_toolkit/widget_toolkit.h"

static unk_D_8250A480 D_8250A480;
static unk_D_8250A498 D_8250A498;
static char* D_8250A4B0[9];

void KidsClub_InitMatchBanner(char** arg0) {
    D_8250A480.unk_00 = 0;
    D_8250A480.unk_02 = 0;
    D_8250A480.unk_14 = arg0;
}

s32 KidsClub_GetMatchBannerState(void) {
    return D_8250A480.unk_00;
}

void KidsClub_SetMatchBannerState(s16 arg0) {
    unk_D_8250A480* ptr = &D_8250A480;

    ptr->unk_00 = arg0;

    switch (ptr->unk_00) {
        case 0:
            ptr->unk_02 = 0;
            ptr->unk_0C = 0;
            ptr->unk_10 = 0.0f;
            break;

        case 1:
            ptr->unk_02 = 0xA;
            ptr->unk_04 = -0xF8;
            ptr->unk_06 = 0x5A;
            ptr->unk_08 = 0x280;
            ptr->unk_0A = 0x15E;
            ptr->unk_10 = 0.0f;
            break;

        case 2:
            ptr->unk_02 = 0x12C;
            ptr->unk_04 = 0xBC;
            ptr->unk_08 = 0x5C;
            ptr->unk_0C = 0;
            break;

        case 3:
            ptr->unk_02 = 0xA;
            ptr->unk_10 = 0.0f;
            break;
    }
}

void KidsClub_AdvanceMatchBannerOpen(unk_D_8250A480* arg0) {
    arg0->unk_02--;
    arg0->unk_04 = ((arg0->unk_02 * -0x1B4) / 10) + 0xBC;
    arg0->unk_08 = ((arg0->unk_02 * 0x224) / 10) + 0x5C;
    if (arg0->unk_02 <= 0) {
        KidsClub_SetMatchBannerState(2);
    }
}

void KidsClub_UpdateMatchBannerIdle(unk_D_8250A480* arg0) {
    arg0->unk_02 = 0x12C;
    arg0->unk_10 = 0.0f;
    if (arg0->unk_02 <= 0) {
        arg0->unk_0C += 0x1000;
        arg0->unk_10 += 0.05f;
        if (arg0->unk_10 > 4.0f) {
            arg0->unk_10 = 4.0f;
        }
    }
}

void KidsClub_AdvanceMatchBannerClose(unk_D_8250A480* arg0) {
    arg0->unk_02--;
    arg0->unk_04 = ((arg0->unk_02 * -0x1C4) / 10) + 0x280;
    arg0->unk_08 = ((arg0->unk_02 * 0x224) / 10) - 0x1C8;
    if (arg0->unk_02 <= 0) {
        KidsClub_SetMatchBannerState(0);
    }
}

void KidsClub_UpdateMatchBanner(void) {
    unk_D_8250A480* ptr = &D_8250A480;

    if (ptr->unk_00 != 0) {
        switch (ptr->unk_00) {
            case 1:
                KidsClub_AdvanceMatchBannerOpen(ptr);
                break;
            case 2:
                KidsClub_UpdateMatchBannerIdle(ptr);
                break;
            case 3:
                KidsClub_AdvanceMatchBannerClose(ptr);
                break;
        }
    }
}

void KidsClub_DrawRoundedFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 sp48;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x20) {
        var_s3 = 0x10;
    } else {
        var_s3 = arg2 / 2;
    }

    if (arg3 >= 0x20) {
        var_s2 = 0x10;
    } else {
        var_s2 = arg3 / 2;
    }

    sp48 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30CD490, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30CD510, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30CD390, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30CD410, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3,
                  0x4000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, gUiTranslucentFillDL);

    if ((sp48 > 0) && (temp_s0_32 > 0)) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp48, var_s2, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, sp48, var_s2, arg4, arg5, arg6, arg7);
    } else if (sp48 > 0) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, sp48, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        Gfx_FillRectRgba(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void KidsClub_DrawWavyText(s16 arg0, s16 arg1, s8* arg2, f32 arg3, s16 arg4) {
    s16 var_s2;
    s8* var_v1;
    s32 i;
    char sp50[4];
    s16 tmp;

    var_s2 = 0;
    while (*arg2) {
        var_v1 = sp50;
        if (*arg2 < 0) {
            for (i = 0; i < 2; i++) {
                *var_v1++ = *arg2++;
            }
            *var_v1 = '\x00';
        } else {
            *var_v1++ = *arg2++;
            *var_v1++ = 0;
        }

        tmp = SINS(arg4 + var_s2) * arg3;
        Font_Printf(arg0, arg1 + tmp, sp50);
        var_s2 += 0x3000;
        arg0 += 0x18;
    }
}

void KidsClub_DrawMatchBanner(void) {
    UNUSED s32 pad;
    unk_D_8250A480* ptr = &D_8250A480;
    char* sp2C = Text_GetString(NULL, 0, ptr->unk_14, 0);
    char* sp28 = Text_GetString(NULL, 0, ptr->unk_14, 1);

    if (ptr->unk_00 != 0) {
        KidsClub_DrawRoundedFrame(ptr->unk_04, ptr->unk_06, 0xF8, 0x2C, 0x1E, 0x1E, 0x82, 0x80);
        KidsClub_DrawRoundedFrame(ptr->unk_08, ptr->unk_0A, 0x1C8, 0x2C, 0x64, 0, 0x50, 0x80);
        Font_BeginTranslucentTextRendering();
        Font_SetActive(0x10, 0);
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        if (ptr->unk_10 <= 0.0f) {
            Font_Printf((ptr->unk_04 - (Font_MeasureTextExtent(0, 0, sp2C) / 2)) + 0x7C, ptr->unk_06 + 0xA, sp2C);
            Font_Printf((ptr->unk_08 - (Font_MeasureTextExtent(0, 0, sp28) / 2)) + 0xE4, ptr->unk_0A + 0xA, sp28);
        } else {
            KidsClub_DrawWavyText(ptr->unk_04 + 0x18, ptr->unk_06 + 0xA, sp2C, ptr->unk_10, ptr->unk_0C);
            KidsClub_DrawWavyText(ptr->unk_08 + 0x18, ptr->unk_0A + 0xA, sp28, ptr->unk_10, ptr->unk_0C);
        }
        Font_EndTexturedTextRendering();
    }
}

void KidsClub_InitRoundBanner(char** arg0) {
    s32 i;

    D_8250A498.unk_00 = 0;
    D_8250A498.unk_02 = 0;
    D_8250A498.unk_14 = arg0;

    for (i = 0; i < 9; i++) {
        D_8250A4B0[i] = Text_GetString(NULL, 0, arg0, i + 7);
    }
}

void func_825057A0(void) {
}

void KidsClub_SetRoundBannerLabel(s16 arg0) {
    unk_D_8250A498* ptr = &D_8250A498;

    if (ptr->unk_12 != ptr->unk_10) {
        ptr->unk_10 = ptr->unk_12;
        ptr->unk_0C = ptr->unk_0E;
        ptr->unk_04 = ptr->unk_06;
    }
    ptr->unk_12 = arg0;
    ptr->unk_0E = Font_MeasureTextExtent(0, 0, D_8250A4B0[ptr->unk_12], arg0) + 0x30;
    ptr->unk_06 = (0x280 - ptr->unk_0E) / 2;
    ptr->unk_02 = 5;
}

void KidsClub_SetRoundBannerState(s16 arg0, s16 arg1) {
    unk_D_8250A498* ptr = &D_8250A498;

    ptr->unk_00 = arg0;

    switch (ptr->unk_00) {
        case 0:
            ptr->unk_02 = 0;
            break;

        case 1:
            ptr->unk_02 = 0xA;
            ptr->unk_10 = ptr->unk_12 = arg1;
            ptr->unk_0C = ptr->unk_0E = Font_MeasureTextExtent(0, 0, D_8250A4B0[ptr->unk_12], arg1) + 0x30;
            ptr->unk_04 = ptr->unk_06 = (0x280 - ptr->unk_0C) / 2;
            ptr->unk_08 = -0x2C;
            ptr->unk_0A = 0x1E0;
            break;

        case 2:
            ptr->unk_08 = 0x3C;
            break;

        case 3:
            ptr->unk_02 = 0xA;
            break;
    }
}

void KidsClub_AdvanceRoundBannerOpen(unk_D_8250A498* arg0) {
    arg0->unk_02--;
    arg0->unk_08 = ((arg0->unk_02 * -0x68) / 10) + 0x3C;
    arg0->unk_0A = ((arg0->unk_02 * 0x56) / 10) + 0x18A;
    if (arg0->unk_02 <= 0) {
        KidsClub_SetRoundBannerState(2, -1);
    }
}

void KidsClub_UpdateRoundBannerCrossfade(unk_D_8250A498* arg0) {
    if (arg0->unk_10 != arg0->unk_12) {
        arg0->unk_02--;
        if (arg0->unk_02 <= 0) {
            arg0->unk_10 = arg0->unk_12;
            arg0->unk_0C = arg0->unk_0E;
            arg0->unk_04 = arg0->unk_06;
        }
    }
}

void KidsClub_AdvanceRoundBannerClose(unk_D_8250A498* arg0) {
    arg0->unk_02--;
    arg0->unk_08 = ((arg0->unk_02 * 0x68) / 10) - 0x2C;
    arg0->unk_0A = ((arg0->unk_02 * -0x56) / 10) + 0x1E0;
    if (arg0->unk_02 <= 0) {
        KidsClub_SetRoundBannerState(0, -1);
    }
}

void KidsClub_UpdateRoundBanner(void) {
    unk_D_8250A498* ptr = &D_8250A498;

    if (ptr->unk_00 != 0) {
        switch (ptr->unk_00) {
            case 1:
                KidsClub_AdvanceRoundBannerOpen(ptr);
                break;

            case 2:
                KidsClub_UpdateRoundBannerCrossfade(ptr);
                break;

            case 3:
                KidsClub_AdvanceRoundBannerClose(ptr);
                break;
        }
    }
}

void KidsClub_DrawRoundBanner(void) {
    UNUSED s32 pad;
    unk_D_8250A498* ptr = &D_8250A498;
    char* sp3C;
    s16 tmp;
    char* sp34 = Text_GetString(NULL, 0, ptr->unk_14, 0x10);

    if (ptr->unk_00 != 0) {
        if (ptr->unk_10 == ptr->unk_12) {
            KidsClub_DrawRoundedFrame(ptr->unk_04, ptr->unk_08, ptr->unk_0C, 0x2C, 0x1E, 0x1E, 0x82, 0x80);
        } else {
            tmp = (ptr->unk_02 << 7) / 5;
            KidsClub_DrawRoundedFrame(ptr->unk_04, ptr->unk_08, ptr->unk_0C, 0x2C, 0x1E, 0x1E, 0x82, tmp);
            tmp = ((-ptr->unk_02 * 0x80) + 0x280) / 5;
            KidsClub_DrawRoundedFrame(ptr->unk_06, ptr->unk_08, ptr->unk_0E, 0x2C, 0x1E, 0x1E, 0x82, tmp);
        }

        if (D_8780FA48 == -1) {
            KidsClub_DrawRoundedFrame(0x98, ptr->unk_0A, 0x140, 0x2C, 0x64, 0, 0x50, 0x80);
        }

        Font_BeginTranslucentTextRendering();
        Font_SetActive(0x10, 0);
        sp3C = D_8250A4B0[ptr->unk_10];
        if (ptr->unk_10 == ptr->unk_12) {
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_Printf(ptr->unk_04 + 0x18, ptr->unk_08 + 0xA, sp3C);
        } else {
            tmp = (ptr->unk_02 * 0xFF) / 5;
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, tmp);
            Font_Printf(ptr->unk_04 + 0x18, ptr->unk_08 + 0xA, sp3C);
            sp3C = D_8250A4B0[ptr->unk_12];
            tmp = ((5 - ptr->unk_02) * 0xFF) / 5;
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, tmp);
            Font_Printf(ptr->unk_06 + 0x18, ptr->unk_08 + 0xA, sp3C);
        }

        if (D_8780FA48 == -1) {
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_Printf(0x140 - (Text_MeasureStringWidth(D_8250A304, sp34) / 2), ptr->unk_0A + 0xA, sp34);
        }
        Font_EndTexturedTextRendering();
    }
}
