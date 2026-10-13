#include "rental_rules.h"
#include "src/graphics_textures.h"
#include "src/audio_sfx.h"

static s16 rule_popup_status;
static s16 popup_close_progress;
static s16 rules_text_index;
static s16 popup_open_progress;
static s16 window_bottom;
static s16 window_top;

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
    popup_close_progress--;
    popup_open_progress = ((5 - popup_close_progress) << 0xA) / 5;
    if (popup_close_progress <= 0) {
        rule_popup_status = 2;
        popup_close_progress = 0;
    }
}

void RentalRules_PopupUpdateShown(void) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        rule_popup_status = 3;
        popup_close_progress = 5;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
}

void RentalRules_PopupUpdateClose(void) {
    popup_close_progress--;
    popup_open_progress = (popup_close_progress << 0xA) / 5;
    if (popup_close_progress <= 0) {
        rule_popup_status = 0;
        popup_close_progress = 0;
    }
}

void RentalRules_PopupReset(void) {
    rule_popup_status = 0;
    popup_open_progress = 0;
}

void RentalRules_PopupUpdate(void) {
    if (rule_popup_status != 0) {
        switch (rule_popup_status) {
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

    if (popup_open_progress != 0) {
        y = window_bottom + (((window_top / 2) * (0x400 - popup_open_progress)) / 1024);
        RentalRules_DrawWindowFrame(0x48, y, 496, (window_top * popup_open_progress) / 1024);
        if (popup_open_progress >= 0x400) {
            RentalRules_DrawFilledPanel(72, y, 496, 32, 0x1E, 0x64, 0x64);
            RentalRules_DrawFilledPanel(72, y + 32, 496, window_top - 32, 0x3C, 0x3C, 0xA0);
            Font_BeginTranslucentTextRendering();
            Font_SetActive(8, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_SetLineHeight(0x18);
            Font_Printf(0x50, y + 6, D_83003CE0.unk_00[rules_text_index]);
            Font_SetActive(8, 0);
            Font_Printf(0x50, y + 40, D_83003DE0.unk_00[rules_text_index]);
            Font_EndTexturedTextRendering();
        }
    }
}

void RentalRules_PopupOpen(s16 text_index) {
    s32 units_for_text_fit;

    rule_popup_status = 1;
    popup_close_progress = 5;
    popup_open_progress = 0;
    rules_text_index = text_index;
    units_for_text_fit = (RentalRules_CountTextLines(D_83003DE0.unk_00[rules_text_index]) * 0x18);
    window_top = 44 + units_for_text_fit;
    window_bottom = ((480 - window_top) / 2) + 20;
}

s32 RentalRules_PopupIsActive(void) {
    s32 is_active;

    if (rule_popup_status != 0) {
        is_active = 1;
    } else {
        is_active = 0;
    }
    return is_active;
}

s32 RentalRules_PopupGetProgress(void) {
    return popup_open_progress;
}
