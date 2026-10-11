#include "rental_rules.h"
#include "src/graphics_textures.h"
#include "src/audio_sfx.h"

static s16 D_83003EE0;
static s16 D_83003EE2;
static s16 D_83003EE4;
static s16 D_83003EE6;
static s16 D_83003EE8;
static s16 D_83003EEA;

s32 RentalRules_CountTextLines(s8* arg0) {
    s16 var_v1 = 1;

    while (*arg0 != 0) {
        if (*arg0 == '\n') {
            var_v1++;
        }
        arg0++;
    }

    return var_v1;
}

void RentalRules_PopupUpdateOpen(void) {
    D_83003EE2--;
    D_83003EE6 = ((5 - D_83003EE2) << 0xA) / 5;
    if (D_83003EE2 <= 0) {
        D_83003EE0 = 2;
        D_83003EE2 = 0;
    }
}

void RentalRules_PopupUpdateShown(void) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        D_83003EE0 = 3;
        D_83003EE2 = 5;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
}

void RentalRules_PopupUpdateClose(void) {
    D_83003EE2--;
    D_83003EE6 = (D_83003EE2 << 0xA) / 5;
    if (D_83003EE2 <= 0) {
        D_83003EE0 = 0;
        D_83003EE2 = 0;
    }
}

void RentalRules_PopupReset(void) {
    D_83003EE0 = 0;
    D_83003EE6 = 0;
}

void RentalRules_PopupUpdate(void) {
    if (D_83003EE0 != 0) {
        switch (D_83003EE0) {
            case 1:
                RentalRules_PopupUpdateOpen();
                break;

            case 2:
                RentalRules_PopupUpdateShown();
                break;

            case 3:
                RentalRules_PopupUpdateClose();
                break;
        }
    }
}

void RentalRules_PopupDraw(void) {
    s16 temp_s0;

    if (D_83003EE6 != 0) {
        temp_s0 = D_83003EE8 + (((D_83003EEA / 2) * (0x400 - D_83003EE6)) / 1024);
        RentalRules_DrawWindowFrame(0x48, temp_s0, 0x1F0, (D_83003EEA * D_83003EE6) / 1024);
        if (D_83003EE6 >= 0x400) {
            RentalRules_DrawFilledPanel(0x48, temp_s0, 0x1F0, 0x20, 0x1E, 0x64, 0x64);
            RentalRules_DrawFilledPanel(0x48, temp_s0 + 0x20, 0x1F0, D_83003EEA - 0x20, 0x3C, 0x3C, 0xA0);
            Font_BeginTranslucentTextRendering();
            Font_SetActive(8, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_SetLineHeight(0x18);
            Font_Printf(0x50, temp_s0 + 6, D_83003CE0.unk_00[D_83003EE4]);
            Font_SetActive(8, 0);
            Font_Printf(0x50, temp_s0 + 0x28, D_83003DE0.unk_00[D_83003EE4]);
            Font_EndTexturedTextRendering();
        }
    }
}

void RentalRules_PopupOpen(s16 arg0) {
    s32 tmp;

    D_83003EE0 = 1;
    D_83003EE2 = 5;
    D_83003EE6 = 0;
    D_83003EE4 = arg0;
    tmp = (RentalRules_CountTextLines(D_83003DE0.unk_00[D_83003EE4]) * 0x18);
    D_83003EEA = 0x2C + tmp;
    D_83003EE8 = ((0x1E0 - D_83003EEA) / 2) + 0x14;
}

s32 RentalRules_PopupIsActive(void) {
    s32 ret;

    if (D_83003EE0 != 0) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

s32 RentalRules_PopupGetProgress(void) {
    return D_83003EE6;
}
