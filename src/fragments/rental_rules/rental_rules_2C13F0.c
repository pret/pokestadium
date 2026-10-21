#include "game_state.h"
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

static u16 sPokemonList[151][1600];
static QualifyingPokemonDisplay sQualifyingSpeciesDisplay;

s32 RentalRules_SpeciesMatchesCategory(s16 species, s16 ruleset) {
    s32 is_eligible;
    s16 eligibility_mask;

    if ((species <= 0) || (species >= 152)) {
        return 0;
    }

    is_eligible = 0;
    switch (ruleset) {
        case RULE_CATEGORY_ANYTHING_GOES:
            is_eligible = 1;
            break;

        case RULE_CATEGORY_NINTENDO_CUP_97:
            eligibility_mask = 1;
            break;

        case RULE_CATEGORY_NINTENDO_CUP_98:
            eligibility_mask = 2;
            break;

        case RULE_CATEGORY_NINTENDO_CUP_99:
            eligibility_mask = 1;
            break;

        case RULE_CATEGORY_PETIT_CUP:
            eligibility_mask = 8;
            break;

        case RULE_CATEGORY_PIKA_CUP:
            eligibility_mask = 0x10;
            break;

        case RULE_CATEGORY_PRIME_CUP:
            eligibility_mask = 0x20;
            break;

        case RULE_CATEGORY_GYM_LEADER_CASTLE:
            is_eligible = 1;
            break;

        case RULE_CATEGORY_VS_MEWTWO:
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
        row->speciesListed[i].species = 0;
        row->speciesListed[i].isEligible = 0;
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
        row->speciesListed[i].species = species;

        if (RentalRules_SpeciesMatchesCategory(species, ruleset) != 0) {
            row->speciesListed[i].isEligible = 1;
        } else {
            row->speciesListed[i].isEligible = 0;
        }
    }

    return number_processed;
}

QualifyingPokemonDisplayRow* RentalRules_AdvancePageNode(QualifyingPokemonDisplayRow* row, s32 advance_amount) {
    while (advance_amount-- > 0) {
        row = row->belowNeighbor;
    }

    return row;
}

s32 RentalRules_ScrollPageUp(QualifyingPokemonDisplay* display) {
    s32 scroll_successful = 0;

    if (RentalRules_BuildSpeciesPage(display->topRow->aboveNeighbor, display->topRowIndex - 1,
                                     gSessionContext.ruleCategory) > 0) {
        display->qualifyingListState = 3;
        display->animationTicks = 4;
        display->topRowIndex--;
        display->topRow = display->topRow->aboveNeighbor;
        display->scrollDirection = -1;
        display->rowDrawBudget = -1;
        scroll_successful = 1;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    return scroll_successful;
}

s32 RentalRules_ScrollPageDown(QualifyingPokemonDisplay* display) {
    s32 scroll_successful = 0;

    if (RentalRules_BuildSpeciesPage(RentalRules_AdvancePageNode(display->topRow, 5), display->topRowIndex + 5,
                                     gSessionContext.ruleCategory) > 0) {
        display->qualifyingListState = SCROLLING;
        display->animationTicks = 4;
        display->topRowIndex++;
        display->topRow = display->topRow->belowNeighbor;
        display->scrollDirection = 1;
        display->rowDrawBudget = -1;
        scroll_successful = 1;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    return scroll_successful;
}

void RentalRules_QualifyingSpeciesWindowUpdateOpen(QualifyingPokemonDisplay* display) {
    display->animationTicks--;
    display->windowOpenness = ((5 - display->animationTicks) << 10) / 5;
    if (display->animationTicks <= 0) {
        display->qualifyingListState = AWAITING_INPUT;
        display->animationTicks = 0;
        display->rowDrawBudget = 2;
    }
}

void RentalRules_QualifyingSpeciesWindowUpdateShown(QualifyingPokemonDisplay* display) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        display->qualifyingListState = CLOSING;
        display->animationTicks = 5;
        display->rowDrawBudget = -1;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DUP)) {
        RentalRules_ScrollPageUp(display);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DDOWN)) {
        RentalRules_ScrollPageDown(display);
    }
}

void RentalRules_QualifyingSpeciesWindowUpdateScrolling(QualifyingPokemonDisplay* display) {
    s32 scrolling_direction;

    display->animationTicks--;
    if (display->animationTicks <= 0) {
        scrolling_direction = 0;
        if (BTN_IS_DOWN(gPlayer1Controller, BTN_DUP)) {
            scrolling_direction = RentalRules_ScrollPageUp(display);
        } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DDOWN)) {
            scrolling_direction = RentalRules_ScrollPageDown(display);
        }

        if (scrolling_direction == 0) {
            display->qualifyingListState = AWAITING_INPUT;
            display->animationTicks = 0;
            display->rowDrawBudget = 2;
        }
    }
}

void RentalRules_QualifyingSpeciesWindowUpdateClose(QualifyingPokemonDisplay* display) {
    display->animationTicks--;
    display->windowOpenness = (display->animationTicks << 10) / 5;
    if (display->animationTicks <= 0) {
        display->qualifyingListState = INACTIVE;
        display->animationTicks = 0;
        display->rowDrawBudget = -1;
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
    Gfx_DrawTexturedRectClipped(x, y + 8, 0x10, 268, 0, 0, 0x400, 0, 0);

    if (display->qualifyingListState != SCROLLING) {
        y_offset = (display->topRowIndex * 268) / 21;
    } else if (display->scrollDirection > 0) {
        y_offset = (((display->topRowIndex * 4) - display->animationTicks) * 268) / 84;
    } else {
        y_offset = (((display->topRowIndex * 4) + display->animationTicks) * 268) / 84;
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    if (D_83003B70 < 4) {
        Gfx_DrawTextureRgba16(x - 4, (y + y_offset) - 4, 24, 24, D_200A300, 24, 0);
    } else {
        Gfx_DrawTextureRgba16(x - 4, (y + y_offset) - 4, 24, 24, D_200A780, 24, 0);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

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
    s16 species;

    for (i = 0; i < 6; i++) {
        if (node->speciesListed[i].species != 0) {
            if (node->speciesListed[i].isEligible != 0) {
                current_panel_color = &eligible_panel_color;
            } else {
                current_panel_color = &banned_panel_color;
            }
        } else {
            current_panel_color = &empty_panel_color;
        }
        RentalRules_DrawFilledPanel(x + i * 84, y, 84, 60, current_panel_color->r, current_panel_color->g,
                                    current_panel_color->b);
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    for (i = 0; i < 6; i++) {
        species = node->speciesListed[i].species;
        if (species != NULL) {
            Gfx_DrawTextureRgba16(x + (i * 84) + 22, y + 3, 40, 40, sPokemonList[species - 1], 40, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);

    for (i = 0; i < 6; i++) {
        species = node->speciesListed[i].species;
        if (species != NULL) {
            Font_Printf(x + (i * 84) + 2, y + 42, RentalRules_GetPokemonName(species));
        }
    }

    Font_EndTexturedTextRendering();
}

void RentalRules_QualifyingSpeciesWindowInit(s32 arg0) {
    QualifyingPokemonDisplay* ptr = &sQualifyingSpeciesDisplay;
    s32 i;

    ptr->qualifyingListState = INACTIVE;
    ptr->windowOpenness = 0;

    for (i = 0; i < 6; i++) {
        ptr->rowBuffer[i].belowNeighbor = &ptr->rowBuffer[(i + 1) % 6];
        ptr->rowBuffer[i].aboveNeighbor = &ptr->rowBuffer[(i + 5) % 6];
    }

    if (arg0 != 0) {
        for (i = 0; i < 151; i++) {
            PokeIcon_LoadModelTextureForMon(sPokemonList[i], i + 1, NULL);
        }
    }
}

void RentalRules_QualifyingSpeciesWindowUpdate(void) {
    QualifyingPokemonDisplay* ptr = &sQualifyingSpeciesDisplay;

    if (ptr->qualifyingListState != INACTIVE) {
        switch (ptr->qualifyingListState) {
            case OPENING:
                RentalRules_QualifyingSpeciesWindowUpdateOpen(&sQualifyingSpeciesDisplay);
                break;

            case AWAITING_INPUT:
                RentalRules_QualifyingSpeciesWindowUpdateShown(&sQualifyingSpeciesDisplay);
                break;

            case SCROLLING:
                RentalRules_QualifyingSpeciesWindowUpdateScrolling(&sQualifyingSpeciesDisplay);
                break;

            case CLOSING:
                RentalRules_QualifyingSpeciesWindowUpdateClose(&sQualifyingSpeciesDisplay);
                break;
        }
    }
}

void RentalRules_QualifyingSpeciesWindowDraw(void) {
    s16 x;
    s16 y;
    QualifyingPokemonDisplay* display = &sQualifyingSpeciesDisplay;

    if (display->windowOpenness == 0) {
        return;
    }

    x = (((1024 - display->windowOpenness) * 264) / 1024) + 56;
    y = (((1024 - display->windowOpenness) * 168) / 1024) + 92;
    RentalRules_DrawWindowFrame(x, y, (display->windowOpenness * 528) / 1024, (display->windowOpenness * 336) / 1024);

    if (display->windowOpenness >= 1024) {
        UNUSED s32 pad;
        s32 i;
        QualifyingPokemonDisplayRow* node_to_draw;

        RentalRules_DrawFilledPanel(x, y, 528, 36, 0x1E, 0x64, 0x64);
        RentalRules_DrawFilledPanel(x, y + 36, 24, 300, 0x1E, 0x1E, 0x64);
        RentalRules_DrawScrollbar(x + 4, y + 44, display);

        gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

        RentalRules_DrawEligibilityPanelLegend(x + 8, y + 8);

        gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        Font_SetActive(8, 0);
        Text_SetNumberToken(3, display->eligibleCount);
        {
            char var_sp4C[64];
            Font_Printf(x + 44, y + 8, Text_GetString(var_sp4C, sizeof(var_sp4C), sBattleModeLabels, 3));
        }
        Font_EndTexturedTextRendering();

        if (display->rowDrawBudget == 0) {
            return;
        }

        if (display->qualifyingListState == SCROLLING) {
            s16 var_sp4A = y - ((display->scrollDirection * 60 * (4 - display->animationTicks)) / 4);
            Gfx_SetScissorRect(&gDisplayListHead, x + 24, y + 36, 504, 300);
            if (display->scrollDirection > 0) {
                node_to_draw = display->topRow->aboveNeighbor;
                for (i = 0; i < 6; i++) {
                    RentalRules_DrawSpeciesPage(x + 24, var_sp4A + 36 + i * 60, node_to_draw);
                    node_to_draw = node_to_draw->belowNeighbor;
                }
            } else {
                node_to_draw = display->topRow;
                for (i = 0; i < 6; i++) {
                    RentalRules_DrawSpeciesPage(x + 24, var_sp4A - 24 + i * 60, node_to_draw);
                    node_to_draw = node_to_draw->belowNeighbor;
                }
            }
            Gfx_SetScissorRect(&gDisplayListHead, 0, 0, 640, 480);
        } else {
            node_to_draw = display->topRow;
            for (i = 0; i < 5; i++) {
                RentalRules_DrawSpeciesPage(x + 24, y + 36 + i * 60, node_to_draw);
                node_to_draw = node_to_draw->belowNeighbor;
            }
        }

        if (display->rowDrawBudget > 0) {
            display->rowDrawBudget -= 1;
        }
    }

    // karodo
    if (1) {}
}

void RentalRules_QualifyingSpeciesWindowOpen(void) {
    QualifyingPokemonDisplay* ptr = &sQualifyingSpeciesDisplay;
    s32 i;

    ptr->qualifyingListState = OPENING;
    ptr->animationTicks = 5;
    ptr->windowOpenness = 0;
    ptr->topRowIndex = 0;
    ptr->scrollDirection = 0;
    ptr->rowDrawBudget = -1;
    ptr->eligibleCount = RentalRules_CountMatchingSpecies(gSessionContext.ruleCategory);
    ptr->topRow = &ptr->rowBuffer[0];

    for (i = 0; i < 5; i++) {
        RentalRules_BuildSpeciesPage(&ptr->rowBuffer[i], i, gSessionContext.ruleCategory);
    }
}

s32 RentalRules_QualifyingSpeciesWindowIsActive(void) {
    s32 is_active;

    if (sQualifyingSpeciesDisplay.qualifyingListState != INACTIVE) {
        is_active = 1;
    } else {
        is_active = 0;
    }
    return is_active;
}

s32 RentalRules_GetSpeciesWindowOpeningProgress(void) {
    return sQualifyingSpeciesDisplay.windowOpenness;
}
