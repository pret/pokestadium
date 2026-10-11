#include "rental_rules.h"
#include "src/poke_icon.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/gb_data.h"
#include "src/text_system.h"
#include "src/audio_sfx.h"
#include "src/gfx_rect.h"
#include "variables.h"

static u16 pokemon_list[151][0x640];
static QualifyingPokemonDisplayRow D_83079E70;

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

s32 RentalRules_BuildSpeciesPage(QualifyingPokemonDisplayNode* display_node, s16 row, s16 ruleset) {
    s32 i;
    s16 species;
    s32 index;
    s32 number_processed;

    for (i = 0; i < 6; i++) {
        display_node->species_listed[i].species = 0;
        display_node->species_listed[i].is_eligible = 0;
    }

    number_processed = 0;
    index = (row * 6) + 1;
    for (i = 0; i < 6; i++, index++) {
        species = index;
        if ((species <= 0) || (species >= 152)) {
            species = 0;
        } else {
            number_processed++;
        }
        display_node->species_listed[i].species = species;

        if (RentalRules_SpeciesMatchesCategory(species, ruleset) != 0) {
            display_node->species_listed[i].is_eligible = 1;
        } else {
            display_node->species_listed[i].is_eligible = 0;
        }
    }

    return number_processed;
}

struct QualifyingPokemonDisplayNode* RentalRules_AdvancePageNode(struct QualifyingPokemonDisplayNode* current_node, s32 advance_amount) {
    while (advance_amount-- > 0) {
        current_node = current_node->below_neighbour;
    }

    return current_node;
}

s32 RentalRules_ScrollPageUp(QualifyingPokemonDisplayRow* row) {
    s32 scroll_successful = 0;

    if (RentalRules_BuildSpeciesPage(row->self_node->above_neighbour, row->pokedex_index - 1, D_800AE540.unk_0001) > 0) {
        row->qualifying_list_state = 3;
        row->unk_02 = 4;
        row->pokedex_index--;
        row->self_node = row->self_node->above_neighbour;
        row->unk_0A = -1;
        row->unk_0C = -1;
        scroll_successful = 1;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    return scroll_successful;
}

s32 RentalRules_ScrollPageDown(QualifyingPokemonDisplayRow* row) {
    s32 scroll_successful = 0;

    if (RentalRules_BuildSpeciesPage(RentalRules_AdvancePageNode(row->self_node, 5), row->pokedex_index + 5, D_800AE540.unk_0001) > 0) {
        row->qualifying_list_state = 3;
        row->unk_02 = 4;
        row->pokedex_index++;
        row->self_node = row->self_node->below_neighbour;
        row->unk_0A = 1;
        row->unk_0C = -1;
        scroll_successful = 1;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    return scroll_successful;
}

void RentalRules_ListUpdateOpen(QualifyingPokemonDisplayRow* row) {
    row->unk_02--;
    row->unk_04 = ((5 - row->unk_02) << 0xA) / 5;
    if (row->unk_02 <= 0) {
        row->qualifying_list_state = 2;
        row->unk_02 = 0;
        row->unk_0C = 2;
    }
}

void RentalRules_ListUpdateShown(QualifyingPokemonDisplayRow* arg0) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        arg0->qualifying_list_state = 4;
        arg0->unk_02 = 5;
        arg0->unk_0C = -1;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DUP)) {
        RentalRules_ScrollPageUp(arg0);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DDOWN)) {
        RentalRules_ScrollPageDown(arg0);
    }
}

void RentalRules_ListUpdateScrolling(QualifyingPokemonDisplayRow* arg0) {
    s32 var_v1;

    arg0->unk_02--;
    if (arg0->unk_02 <= 0) {
        var_v1 = 0;
        if (BTN_IS_DOWN(gPlayer1Controller, BTN_DUP)) {
            var_v1 = RentalRules_ScrollPageUp(arg0);
        } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DDOWN)) {
            var_v1 = RentalRules_ScrollPageDown(arg0);
        }

        if (var_v1 == 0) {
            arg0->qualifying_list_state = 2;
            arg0->unk_02 = 0;
            arg0->unk_0C = 2;
        }
    }
}

void RentalRules_ListUpdateClose(QualifyingPokemonDisplayRow* arg0) {
    arg0->unk_02--;
    arg0->unk_04 = (arg0->unk_02 << 0xA) / 5;
    if (arg0->unk_02 <= 0) {
        arg0->qualifying_list_state = 0;
        arg0->unk_02 = 0;
        arg0->unk_0C = -1;
    }
}

void RentalRules_DrawScrollbar(s16 x, s16 y, QualifyingPokemonDisplayRow* row_display) {
    static s16 D_83003B70 = 0;

    s16 temp_t0;

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, 130, 130, 220, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 60, 60, 150, 255);

    Gfx_DrawTextureIa8(x, y, 16, 8, D_200A200, 0x10, 0);
    Gfx_DrawTextureIa8(x, y + 276, 0x10, 8, D_200A280, 0x10, 0);
    Gfx_DrawTexturedRectClipped(x, y + 8, 0x10, 0x10C, 0, 0, 0x400, 0, 0);

    if (row_display->qualifying_list_state != 3) {
        temp_t0 = (row_display->pokedex_index * 0x10C) / 21;
    } else if (row_display->unk_0A > 0) {
        temp_t0 = (((row_display->pokedex_index * 4) - row_display->unk_02) * 0x10C) / 84;
    } else {
        temp_t0 = (((row_display->pokedex_index * 4) + row_display->unk_02) * 0x10C) / 84;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (D_83003B70 < 4) {
        Gfx_DrawTextureRgba16(x - 4, (y + temp_t0) - 4, 24, 24, D_200A300, 0x18, 0);
    } else {
        Gfx_DrawTextureRgba16(x - 4, (y + temp_t0) - 4, 24, 24, D_200A780, 0x18, 0);
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

void RentalRules_DrawSpeciesPage(s16 x, s16 y, QualifyingPokemonDisplayNode* node) {
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
    QualifyingPokemonDisplayRow* ptr = &D_83079E70;
    s32 i;

    ptr->qualifying_list_state = 0;
    ptr->unk_04 = 0;

    for (i = 0; i < 6; i++) {
        ptr->unk_14[i].below_neighbour = &ptr->unk_14[(i + 1) % 6];
        ptr->unk_14[i].above_neighbour = &ptr->unk_14[(i + 5) % 6];
    }

    if (arg0 != 0) {
        for (i = 0; i < 151; i++) {
            PokeIcon_LoadModelTextureForMon(pokemon_list[i], i + 1, NULL);
        }
    }
}

void RentalRules_ListUpdate(void) {
    QualifyingPokemonDisplayRow* ptr = &D_83079E70;

    if (ptr->qualifying_list_state != 0) {
        switch (ptr->qualifying_list_state) {
            case 1:
                RentalRules_ListUpdateOpen(&D_83079E70);
                break;

            case 2:
                RentalRules_ListUpdateShown(&D_83079E70);
                break;

            case 3:
                RentalRules_ListUpdateScrolling(&D_83079E70);
                break;

            case 4:
                RentalRules_ListUpdateClose(&D_83079E70);
                break;
        }
    }
}

void RentalRules_ListDraw(void) {
    s16 spA6;
    s16 spA4;
    QualifyingPokemonDisplayRow* ptr = &D_83079E70;

    if (ptr->unk_04 == 0) {
        return;
    }

    spA6 = (((0x400 - ptr->unk_04) * 0x108) / 1024) + 0x38;
    spA4 = (((0x400 - ptr->unk_04) * 0xA8) / 1024) + 0x5C;
    RentalRules_DrawWindowFrame(spA6, spA4, (ptr->unk_04 * 0x210) / 1024, (ptr->unk_04 * 0x150) / 1024);

    if (ptr->unk_04 >= 0x400) {
        UNUSED s32 pad;
        s32 i;
        QualifyingPokemonDisplayNode* var_s0;

        RentalRules_DrawFilledPanel(spA6, spA4, 0x210, 0x24, 0x1E, 0x64, 0x64);
        RentalRules_DrawFilledPanel(spA6, spA4 + 0x24, 0x18, 0x12C, 0x1E, 0x1E, 0x64);
        RentalRules_DrawScrollbar(spA6 + 4, spA4 + 0x2C, ptr);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        RentalRules_DrawEligibilityPanelLegend(spA6 + 8, spA4 + 8);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        Font_SetActive(8, 0);
        Text_SetNumberToken(3, ptr->unk_06);
        {
            char sp4C[64];
            Font_Printf(spA6 + 0x2C, spA4 + 8, Text_GetString(sp4C, sizeof(sp4C), D_830039C0, 3));
        }
        Font_EndTexturedTextRendering();

        if (ptr->unk_0C == 0) {
            return;
        }

        if (ptr->qualifying_list_state == 3) {
            s16 sp4A = spA4 - ((ptr->unk_0A * 0x3C * (4 - ptr->unk_02)) / 4);
            Gfx_SetScissorRect(&gDisplayListHead, spA6 + 0x18, spA4 + 0x24, 0x1F8, 0x12C);
            if (ptr->unk_0A > 0) {
                var_s0 = ptr->self_node->above_neighbour;
                for (i = 0; i < 6; i++) {
                    RentalRules_DrawSpeciesPage(spA6 + 0x18, sp4A + 0x24 + i * 0x3C, var_s0);
                    var_s0 = var_s0->below_neighbour;
                }
            } else {
                var_s0 = ptr->self_node;
                for (i = 0; i < 6; i++) {
                    RentalRules_DrawSpeciesPage(spA6 + 0x18, sp4A - 0x18 + i * 0x3C, var_s0);
                    var_s0 = var_s0->below_neighbour;
                }
            }
            Gfx_SetScissorRect(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
        } else {
            var_s0 = ptr->self_node;
            for (i = 0; i < 5; i++) {
                RentalRules_DrawSpeciesPage(spA6 + 0x18, spA4 + 0x24 + i * 0x3C, var_s0);
                var_s0 = var_s0->below_neighbour;
            }
        }

        if (ptr->unk_0C > 0) {
            ptr->unk_0C -= 1;
        }
    }

    if (1) {}
}

void RentalRules_ListOpen(void) {
    QualifyingPokemonDisplayRow* ptr = &D_83079E70;
    s32 i;

    ptr->qualifying_list_state = 1;
    ptr->unk_02 = 5;
    ptr->unk_04 = 0;
    ptr->pokedex_index = 0;
    ptr->unk_0A = 0;
    ptr->unk_0C = -1;
    ptr->unk_06 = RentalRules_CountMatchingSpecies(D_800AE540.unk_0001);
    ptr->self_node = &ptr->unk_14[0];

    for (i = 0; i < 5; i++) {
        RentalRules_BuildSpeciesPage(&ptr->unk_14[i], i, D_800AE540.unk_0001);
    }
}

s32 RentalRules_ListIsActive(void) {
    s32 ret;

    if (D_83079E70.qualifying_list_state != 0) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

s32 RentalRules_ListGetProgress(void) {
    return D_83079E70.unk_04;
}
