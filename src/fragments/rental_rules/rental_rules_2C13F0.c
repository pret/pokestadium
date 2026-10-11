#include "rental_rules.h"
#include "src/poke_icon.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/gb_data.h"
#include "src/text_system.h"
#include "src/audio_sfx.h"
#include "src/gfx_rect.h"
#include "variables.h"

#define INACTIVE 0
#define OPENING 1
#define AWAITING_INPUT 2 
#define SCROLLING 3
#define CLOSING 4

static u16 pokemon_list[151][0x640];
static QualifyingPokemonDisplay qualifying_species_display;

s32 RentalRules_SpeciesMatchesCategory(s16 species, s16 ruleset) {
    s32 is_eligible;
    s16 eligibility_mask;

    if ((species <= 0) || (species >= 152)) {
        return 0;
    }

    is_eligible = 0;
    switch (ruleset) {
        case 0:
            is_eligible = 1;
            break;

        case 1:
            eligibility_mask = 1;
            break;

        case 2:
            eligibility_mask = 2;
            break;

        case 3:
            eligibility_mask = 1;
            break;

        case 4:
            eligibility_mask = 8;
            break;

        case 5:
            eligibility_mask = 0x10;
            break;

        case 6:
            eligibility_mask = 0x20;
            break;

        case 7:
            is_eligible = 1;
            break;

        case 8:
            is_eligible = 1;
            break;
    }

    if (is_eligible == 0) {
        if (gSpeciesDataById[species][8] & eligibility_mask) {
            is_eligible = 1;
        } else {
            is_eligible = 0;
        }
    }
    return is_eligible;
}

s16 RentalRules_CountMatchingSpecies(s16 ruleset) {
    s16 i;
    s16 number_of_eligible_pokemon = 0;

    for (i = 1; i < 152; i++) {
        if (RentalRules_SpeciesMatchesCategory(i, ruleset) != 0) {
            number_of_eligible_pokemon++;
        }
    }

    return number_of_eligible_pokemon;
}

s32 RentalRules_BuildSpeciesPage(QualifyingPokemonDisplayRow* row, s16 current_row_index, s16 ruleset) {
    s32 i;
    s16 species;
    s32 index;
    s32 number_processed;

    for (i = 0; i < 6; i++) {
        row->species_listed[i].species = 0;
        row->species_listed[i].is_eligible = 0;
    }

    number_processed = 0;
    index = (current_row_index * 6) + 1;
    for (i = 0; i < 6; i++, index++) {
        species = index;
        if ((species <= 0) || (species >= 152)) {
            species = 0;
        } else {
            number_processed++;
        }
        row->species_listed[i].species = species;

        if (RentalRules_SpeciesMatchesCategory(species, ruleset) != 0) {
            row->species_listed[i].is_eligible = 1;
        } else {
            row->species_listed[i].is_eligible = 0;
        }
    }

    return number_processed;
}

struct QualifyingPokemonDisplayRow* RentalRules_AdvancePageNode(QualifyingPokemonDisplayRow* row, s32 advance_amount) {
    while (advance_amount-- > 0) {
        row = row->below_neighbour;
    }

    return row;
}

s32 RentalRules_ScrollPageUp(QualifyingPokemonDisplay* display) {
    s32 scroll_successful = 0;

    if (RentalRules_BuildSpeciesPage(display->top_row->above_neighbour, display->top_row_index - 1, gSessionContext.ruleCategory) > 0) {
        display->qualifying_list_state = 3;
        display->animation_ticks = 4;
        display->top_row_index--;
        display->top_row = display->top_row->above_neighbour;
        display->scroll_direction = -1;
        display->row_draw_budget = -1;
        scroll_successful = 1;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    return scroll_successful;
}

s32 RentalRules_ScrollPageDown(QualifyingPokemonDisplay* display) {
    s32 scroll_successful = 0;

    if (RentalRules_BuildSpeciesPage(RentalRules_AdvancePageNode(display->top_row, 5), display->top_row_index + 5, gSessionContext.ruleCategory) > 0) {
        display->qualifying_list_state = SCROLLING;
        display->animation_ticks = 4;
        display->top_row_index++;
        display->top_row = display->top_row->below_neighbour;
        display->scroll_direction = 1;
        display->row_draw_budget = -1;
        scroll_successful = 1;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    return scroll_successful;
}

void RentalRules_ListUpdateOpen(QualifyingPokemonDisplay* display) {
    display->animation_ticks--;
    display->window_openness = ((5 - display->animation_ticks) << 0xA) / 5;
    if (display->animation_ticks <= 0) {
        display->qualifying_list_state = AWAITING_INPUT;
        display->animation_ticks = 0;
        display->row_draw_budget = 2;
    }
}

void RentalRules_ListUpdateShown(QualifyingPokemonDisplay* display) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        display->qualifying_list_state = CLOSING;
        display->animation_ticks = 5;
        display->row_draw_budget = -1;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DUP)) {
        RentalRules_ScrollPageUp(display);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DDOWN)) {
        RentalRules_ScrollPageDown(display);
    }
}

void RentalRules_ListUpdateScrolling(QualifyingPokemonDisplay* display) {
    s32 var_v1;

    display->animation_ticks--;
    if (display->animation_ticks <= 0) {
        var_v1 = 0;
        if (BTN_IS_DOWN(gPlayer1Controller, BTN_DUP)) {
            var_v1 = RentalRules_ScrollPageUp(display);
        } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DDOWN)) {
            var_v1 = RentalRules_ScrollPageDown(display);
        }

        if (var_v1 == 0) {
            display->qualifying_list_state = AWAITING_INPUT;
            display->animation_ticks = 0;
            display->row_draw_budget = 2;
        }
    }
}

void RentalRules_ListUpdateClose(QualifyingPokemonDisplay* arg0) {
    arg0->animation_ticks--;
    arg0->window_openness = (arg0->animation_ticks << 0xA) / 5;
    if (arg0->animation_ticks <= 0) {
        arg0->qualifying_list_state = INACTIVE;
        arg0->animation_ticks = 0;
        arg0->row_draw_budget = -1;
    }
}

void RentalRules_DrawScrollbar(s16 x, s16 y, QualifyingPokemonDisplay* row_display) {
    static s16 D_83003B70 = 0;

    s16 y_offset;

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, 130, 130, 220, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 60, 60, 150, 255);

    Gfx_DrawTextureIa8(x, y, 16, 8, D_200A200, 0x10, 0);
    Gfx_DrawTextureIa8(x, y + 276, 0x10, 8, D_200A280, 0x10, 0);
    Gfx_DrawTexturedRectClipped(x, y + 8, 0x10, 0x10C, 0, 0, 0x400, 0, 0);

    if (row_display->qualifying_list_state != SCROLLING) {
        y_offset = (row_display->top_row_index * 0x10C) / 21;
    } else if (row_display->scroll_direction > 0) {
        y_offset = (((row_display->top_row_index * 4) - row_display->animation_ticks) * 0x10C) / 84;
    } else {
        y_offset = (((row_display->top_row_index * 4) + row_display->animation_ticks) * 0x10C) / 84;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (D_83003B70 < 4) {
        Gfx_DrawTextureRgba16(x - 4, (y + y_offset) - 4, 24, 24, D_200A300, 0x18, 0);
    } else {
        Gfx_DrawTextureRgba16(x - 4, (y + y_offset) - 4, 24, 24, D_200A780, 0x18, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    D_83003B70 = (D_83003B70 + 1) % 8;
}

void RentalRules_DrawEligibilityPanelLegend(s16 x, s16 y) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 60, 60, 160, 255);

    Gfx_DrawTextureI4(x, y, 32, 20, ELIGIBILITY_PANEL_LEGEND, 0x20, 0);
}

void RentalRules_DrawSpeciesPage(s16 x, s16 y, QualifyingPokemonDisplayRow* node) {
    UNUSED s32 pad;
    s32 i;
    Color_RGB8* current_panel_color;
    Color_RGB8 eligible_panel_color = { 0x3C, 0x3C, 0xA0 };
    Color_RGB8 banned_panel_color = { 0x64, 0x1E, 0x1E };
    Color_RGB8 empty_panel_color = { 0x1E, 0x1E, 0x64 };
    s16 temp_s0;

    for (i = 0; i < 6; i++) {
        if (node->species_listed[i].species != 0) {
            if (node->species_listed[i].is_eligible != 0) {
                current_panel_color = &eligible_panel_color;
            } else {
                current_panel_color = &banned_panel_color;
            }
        } else {
            current_panel_color = &empty_panel_color;
        }
        RentalRules_DrawFilledPanel(x + i * 0x54, y, 0x54, 0x3C, current_panel_color->r, current_panel_color->g, current_panel_color->b);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 6; i++) {
        temp_s0 = node->species_listed[i].species;
        if (temp_s0 != NULL) {
            Gfx_DrawTextureRgba16(x + (i * 0x54) + 0x16, y + 3, 0x28, 0x28, pokemon_list[temp_s0 - 1], 0x28, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);

    for (i = 0; i < 6; i++) {
        temp_s0 = node->species_listed[i].species;
        if (temp_s0 != NULL) {
            Font_Printf(x + (i * 0x54) + 2, y + 0x2A, RentalRules_GetPokemonName(temp_s0));
        }
    }

    Font_EndTexturedTextRendering();
}

void RentalRules_ListInit(s32 arg0) {
    QualifyingPokemonDisplay* ptr = &qualifying_species_display;
    s32 i;

    ptr->qualifying_list_state = INACTIVE;
    ptr->window_openness = 0;

    for (i = 0; i < 6; i++) {
        ptr->row_buffer[i].below_neighbour = &ptr->row_buffer[(i + 1) % 6];
        ptr->row_buffer[i].above_neighbour = &ptr->row_buffer[(i + 5) % 6];
    }

    if (arg0 != 0) {
        for (i = 0; i < 151; i++) {
            PokeIcon_LoadModelTextureForMon(pokemon_list[i], i + 1, NULL);
        }
    }
}

void RentalRules_ListUpdate(void) {
    QualifyingPokemonDisplay* ptr = &qualifying_species_display;

    if (ptr->qualifying_list_state != INACTIVE) {
        switch (ptr->qualifying_list_state) {
            case OPENING:
                RentalRules_ListUpdateOpen(&qualifying_species_display);
                break;

            case AWAITING_INPUT:
                RentalRules_ListUpdateShown(&qualifying_species_display);
                break;

            case SCROLLING:
                RentalRules_ListUpdateScrolling(&qualifying_species_display);
                break;

            case CLOSING:
                RentalRules_ListUpdateClose(&qualifying_species_display);
                break;
        }
    }
}

void RentalRules_ListDraw(void) {
    s16 spA6;
    s16 spA4;
    QualifyingPokemonDisplay* ptr = &qualifying_species_display;

    if (ptr->window_openness == 0) {
        return;
    }

    spA6 = (((0x400 - ptr->window_openness) * 0x108) / 1024) + 0x38;
    spA4 = (((0x400 - ptr->window_openness) * 0xA8) / 1024) + 0x5C;
    RentalRules_DrawWindowFrame(spA6, spA4, (ptr->window_openness * 0x210) / 1024, (ptr->window_openness * 0x150) / 1024);

    if (ptr->window_openness >= 0x400) {
        UNUSED s32 pad;
        s32 i;
        QualifyingPokemonDisplayRow* var_s0;

        RentalRules_DrawFilledPanel(spA6, spA4, 0x210, 0x24, 0x1E, 0x64, 0x64);
        RentalRules_DrawFilledPanel(spA6, spA4 + 0x24, 0x18, 0x12C, 0x1E, 0x1E, 0x64);
        RentalRules_DrawScrollbar(spA6 + 4, spA4 + 0x2C, ptr);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        RentalRules_DrawEligibilityPanelLegend(spA6 + 8, spA4 + 8);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        Font_SetActive(8, 0);
        Text_SetNumberToken(3, ptr->eligible_count);
        {
            char sp4C[64];
            Font_Printf(spA6 + 0x2C, spA4 + 8, Text_GetString(sp4C, sizeof(sp4C), D_830039C0, 3));
        }
        Font_EndTexturedTextRendering();

        if (ptr->row_draw_budget == 0) {
            return;
        }

        if (ptr->qualifying_list_state == SCROLLING) {
            s16 sp4A = spA4 - ((ptr->scroll_direction * 0x3C * (4 - ptr->animation_ticks)) / 4);
            Gfx_SetScissorRect(&gDisplayListHead, spA6 + 0x18, spA4 + 0x24, 0x1F8, 0x12C);
            if (ptr->scroll_direction > 0) {
                var_s0 = ptr->top_row->above_neighbour;
                for (i = 0; i < 6; i++) {
                    RentalRules_DrawSpeciesPage(spA6 + 0x18, sp4A + 0x24 + i * 0x3C, var_s0);
                    var_s0 = var_s0->below_neighbour;
                }
            } else {
                var_s0 = ptr->top_row;
                for (i = 0; i < 6; i++) {
                    RentalRules_DrawSpeciesPage(spA6 + 0x18, sp4A - 0x18 + i * 0x3C, var_s0);
                    var_s0 = var_s0->below_neighbour;
                }
            }
            Gfx_SetScissorRect(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
        } else {
            var_s0 = ptr->top_row;
            for (i = 0; i < 5; i++) {
                RentalRules_DrawSpeciesPage(spA6 + 0x18, spA4 + 0x24 + i * 0x3C, var_s0);
                var_s0 = var_s0->below_neighbour;
            }
        }

        if (ptr->row_draw_budget > 0) {
            ptr->row_draw_budget -= 1;
        }
    }

    if (1) {}
}

void RentalRules_ListOpen(void) {
    QualifyingPokemonDisplay* ptr = &qualifying_species_display;
    s32 i;

    ptr->qualifying_list_state = OPENING;
    ptr->animation_ticks = 5;
    ptr->window_openness = 0;
    ptr->top_row_index = 0;
    ptr->scroll_direction = 0;
    ptr->row_draw_budget = -1;
    ptr->eligible_count = RentalRules_CountMatchingSpecies(gSessionContext.ruleCategory);
    ptr->top_row = &ptr->row_buffer[0];

    for (i = 0; i < 5; i++) {
        RentalRules_BuildSpeciesPage(&ptr->row_buffer[i], i, gSessionContext.ruleCategory);
    }
}

s32 RentalRules_ListIsActive(void) {
    s32 is_active;

    if (qualifying_species_display.qualifying_list_state != INACTIVE) {
        is_active = 1;
    } else {
        is_active = 0;
    }
    return is_active;
}

s32 RentalRules_ListGetProgress(void) {
    return qualifying_species_display.window_openness;
}
