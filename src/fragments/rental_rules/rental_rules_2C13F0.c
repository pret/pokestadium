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

QualifyingPokemonDisplayRow* RentalRules_AdvancePageNode(QualifyingPokemonDisplayRow* row, s32 advance_amount) {
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

void RentalRules_QualifyingSpeciesWindowUpdateOpen(QualifyingPokemonDisplay* display) {
    display->animation_ticks--;
    display->window_openness = ((5 - display->animation_ticks) << 0xA) / 5;
    if (display->animation_ticks <= 0) {
        display->qualifying_list_state = AWAITING_INPUT;
        display->animation_ticks = 0;
        display->row_draw_budget = 2;
    }
}

void RentalRules_QualifyingSpeciesWindowUpdateShown(QualifyingPokemonDisplay* display) {
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

void RentalRules_QualifyingSpeciesWindowUpdateScrolling(QualifyingPokemonDisplay* display) {
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

void RentalRules_QualifyingSpeciesWindowUpdateClose(QualifyingPokemonDisplay* display) {
    display->animation_ticks--;
    display->window_openness = (display->animation_ticks << 0xA) / 5;
    if (display->animation_ticks <= 0) {
        display->qualifying_list_state = INACTIVE;
        display->animation_ticks = 0;
        display->row_draw_budget = -1;
    }
}

void RentalRules_DrawScrollbar(s16 x, s16 y, QualifyingPokemonDisplay* display) {
    static s16 D_83003B70 = 0;

    s16 y_offset;

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, 130, 130, 220, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 60, 60, 150, 255);

    Gfx_DrawTextureIa8(x, y, 16, 8, D_200A200, 0x10, 0);
    Gfx_DrawTextureIa8(x, y + 276, 0x10, 8, D_200A280, 0x10, 0);
    Gfx_DrawTexturedRectClipped(x, y + 8, 0x10, 0x10C, 0, 0, 0x400, 0, 0);

    if (display->qualifying_list_state != SCROLLING) {
        y_offset = (display->top_row_index * 0x10C) / 21;
    } else if (display->scroll_direction > 0) {
        y_offset = (((display->top_row_index * 4) - display->animation_ticks) * 0x10C) / 84;
    } else {
        y_offset = (((display->top_row_index * 4) + display->animation_ticks) * 0x10C) / 84;
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

void RentalRules_QualifyingSpeciesWindowInit(s32 arg0) {
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

void RentalRules_QualifyingSpeciesWindowUpdate(void) {
    QualifyingPokemonDisplay* ptr = &qualifying_species_display;

    if (ptr->qualifying_list_state != INACTIVE) {
        switch (ptr->qualifying_list_state) {
            case OPENING:
                RentalRules_QualifyingSpeciesWindowUpdateOpen(&qualifying_species_display);
                break;

            case AWAITING_INPUT:
                RentalRules_QualifyingSpeciesWindowUpdateShown(&qualifying_species_display);
                break;

            case SCROLLING:
                RentalRules_QualifyingSpeciesWindowUpdateScrolling(&qualifying_species_display);
                break;

            case CLOSING:
                RentalRules_QualifyingSpeciesWindowUpdateClose(&qualifying_species_display);
                break;
        }
    }
}

void RentalRules_QualifyingSpeciesWindowDraw(void) {
    s16 x;
    s16 y;
    QualifyingPokemonDisplay* display = &qualifying_species_display;

    if (display->window_openness == 0) {
        return;
    }

    x = (((1024 - display->window_openness) * 264) / 1024) + 56;
    y = (((1024 - display->window_openness) * 168) / 1024) + 92;
    RentalRules_DrawWindowFrame(x, y, (display->window_openness * 528) / 1024, (display->window_openness * 336) / 1024);

    if (display->window_openness >= 1024) {
        UNUSED s32 pad;
        s32 i;
        QualifyingPokemonDisplayRow* node_to_draw;

        RentalRules_DrawFilledPanel(x, y, 528, 36, 0x1E, 0x64, 0x64);
        RentalRules_DrawFilledPanel(x, y + 36, 24, 300, 0x1E, 0x1E, 0x64);
        RentalRules_DrawScrollbar(x + 4, y + 0x2C, display);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        RentalRules_DrawEligibilityPanelLegend(x + 8, y + 8);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        Font_SetActive(8, 0);
        Text_SetNumberToken(3, display->eligible_count);
        {
            char sp4C[64];
            Font_Printf(x + 44, y + 8, Text_GetString(sp4C, sizeof(sp4C), battle_mode_labels, 3));
        }
        Font_EndTexturedTextRendering();

        if (display->row_draw_budget == 0) {
            return;
        }

        if (display->qualifying_list_state == SCROLLING) {
            s16 sp4A = y - ((display->scroll_direction * 0x3C * (4 - display->animation_ticks)) / 4);
            Gfx_SetScissorRect(&gDisplayListHead, x + 0x18, y + 0x24, 0x1F8, 0x12C);
            if (display->scroll_direction > 0) {
                node_to_draw = display->top_row->above_neighbour;
                for (i = 0; i < 6; i++) {
                    RentalRules_DrawSpeciesPage(x + 24, sp4A + 36 + i * 0x3C, node_to_draw);
                    node_to_draw = node_to_draw->below_neighbour;
                }
            } else {
                node_to_draw = display->top_row;
                for (i = 0; i < 6; i++) {
                    RentalRules_DrawSpeciesPage(x + 24, sp4A - 24 + i * 0x3C, node_to_draw);
                    node_to_draw = node_to_draw->below_neighbour;
                }
            }
            Gfx_SetScissorRect(&gDisplayListHead, 0, 0, 640, 480);
        } else {
            node_to_draw = display->top_row;
            for (i = 0; i < 5; i++) {
                RentalRules_DrawSpeciesPage(x + 24, y + 36 + i * 60, node_to_draw);
                node_to_draw = node_to_draw->below_neighbour;
            }
        }

        if (display->row_draw_budget > 0) {
            display->row_draw_budget -= 1;
        }
    }

    if (1) {}
}

void RentalRules_QualifyingSpeciesWindowOpen(void) {
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

s32 RentalRules_QualifyingSpeciesWindowIsActive(void) {
    s32 is_active;

    if (qualifying_species_display.qualifying_list_state != INACTIVE) {
        is_active = 1;
    } else {
        is_active = 0;
    }
    return is_active;
}

s32 RentalRules_GetQualifyingSpeciesDisplayOpeningProgress(void) {
    return qualifying_species_display.window_openness;
}
