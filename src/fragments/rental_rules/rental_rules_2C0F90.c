#include "rental_rules.h"
#include "src/graphics_textures.h"
#include "src/audio_sfx.h"

static s16 sRulePopupStatus;
static s16 sPopupCloseProgress;
static s16 sRulesTextIndex;
static s16 sPopupOpenProgress;
static s16 sWindowBottom;
static s16 sWindowTop;

s32 RentalRules_CountTextLines(s8* text) {
    s16 num_lines = 1;

    while (*text != 0) {
        if (*text == '\n') {
            num_lines++;
        }
        text++;
    }

    return num_lines;
}

void RentalRules_PopupUpdateOpen(void) {
    sPopupCloseProgress--;
    sPopupOpenProgress = ((5 - sPopupCloseProgress) << 10) / 5;
    if (sPopupCloseProgress <= 0) {
        sRulePopupStatus = 2;
        sPopupCloseProgress = 0;
    }
}

void RentalRules_PopupUpdateShown(void) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        sRulePopupStatus = 3;
        sPopupCloseProgress = 5;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
}

void RentalRules_PopupUpdateClose(void) {
    sPopupCloseProgress--;
    sPopupOpenProgress = (sPopupCloseProgress << 10) / 5;
    if (sPopupCloseProgress <= 0) {
        sRulePopupStatus = 0;
        sPopupCloseProgress = 0;
    }
}

void RentalRules_PopupReset(void) {
    sRulePopupStatus = 0;
    sPopupOpenProgress = 0;
}

void RentalRules_PopupUpdate(void) {
    if (sRulePopupStatus != 0) {
        switch (sRulePopupStatus) {
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
    s16 y;

    if (sPopupOpenProgress != 0) {
        y = sWindowBottom + (((sWindowTop / 2) * (0x400 - sPopupOpenProgress)) / 1024);
        RentalRules_DrawWindowFrame(72, y, 496, (sWindowTop * sPopupOpenProgress) / 1024);
        if (sPopupOpenProgress >= 0x400) {
            RentalRules_DrawFilledPanel(72, y, 496, 32, 0x1E, 0x64, 0x64);
            RentalRules_DrawFilledPanel(72, y + 32, 496, sWindowTop - 32, 0x3C, 0x3C, 0xA0);
            Font_BeginTranslucentTextRendering();
            Font_SetActive(8, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_SetLineHeight(24);
            Font_Printf(80, y + 6, D_83003CE0.unk_00[sRulesTextIndex]);
#if defined(VERSION_JP)
            // The Japanese build clears the active index with -1 here (the call before the
            // first Font_Printf still passes 0).
            Font_SetActive(8, -1);
#else
            Font_SetActive(8, 0);
#endif
            Font_Printf(80, y + 40, D_83003DE0.unk_00[sRulesTextIndex]);
            Font_EndTexturedTextRendering();
        }
    }
}

void RentalRules_PopupOpen(s16 text_index) {
    s32 units_for_text_fit;

    sRulePopupStatus = 1;
    sPopupCloseProgress = 5;
    sPopupOpenProgress = 0;
    sRulesTextIndex = text_index;
    units_for_text_fit = (RentalRules_CountTextLines(D_83003DE0.unk_00[sRulesTextIndex]) * 24);
    sWindowTop = 44 + units_for_text_fit;
    sWindowBottom = ((480 - sWindowTop) / 2) + 20;
}

s32 RentalRules_PopupIsActive(void) {
    s32 is_active;

    if (sRulePopupStatus != 0) {
        is_active = 1;
    } else {
        is_active = 0;
    }
    return is_active;
}

s32 RentalRules_PopupGetProgress(void) {
    return sPopupOpenProgress;
}
