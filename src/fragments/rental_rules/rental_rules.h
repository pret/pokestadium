#ifndef _FRAGMENT55_H_
#define _FRAGMENT55_H_

#include "global.h"
#include "src/game_state.h"

typedef struct unk_D_83003CE0 {
    /* 0x00 */ char* unk_00[29];
    /* 0x74 */ char* unk_74;
    /* 0x78 */ char* unk_78;
    /* 0x7C */ char* unk_7C;
    /* 0x80 */ char* unk_80;
    /* 0x84 */ char* unk_84;
    /* 0x88 */ char* unk_88;
    /* 0x8C */ char* unk_8C;
    /* 0x90 */ char* unk_90;
    /* 0x94 */ char* unk_94;
    /* 0x98 */ char* unk_98;
    /* 0x9C */ char unk_9C[100];
} unk_D_83003CE0; // size = 0x100

typedef struct SpeciesQualificationStatus {
    /* 0x00 */ s16 species;
    /* 0x02 */ s16 is_eligible;
} SpeciesQualificationStatus; // size = 0x4

typedef struct QualifyingPokemonDisplayRow {
    /* 0x00 */ SpeciesQualificationStatus species_listed[6];
    /* 0x18 */ struct QualifyingPokemonDisplayRow* below_neighbor;
    /* 0x1C */ struct QualifyingPokemonDisplayRow* above_neighbor;
} QualifyingPokemonDisplayRow; // size = 0x20

typedef struct QualifyingPokemonDisplay {
    /* 0x00 */ s16 qualifying_list_state;
    /* 0x02 */ s16 animation_ticks;  // Updates remaining: 5 for opening/closing, 4 for scrolling.
    /* 0x04 */ s16 window_openness;  // 0 = closed, 1024 = fully open.
    /* 0x06 */ s16 eligible_count;   // Species accepted by the current category predicate.
    /* 0x08 */ s16 top_row_index;    // Row index; its first species is top_row_index * 6 + 1.
    /* 0x0A */ s16 scroll_direction; // -1 = up, +1 = down, 0 = initial position.
    /* 0x0C */ s16 row_draw_budget;  // -1 = continuous, 0 = skip rows, positive = row draws remaining.
    /* 0x10 */ QualifyingPokemonDisplayRow* top_row;
    /* 0x14 */ QualifyingPokemonDisplayRow row_buffer[6]; // Circular buffer: 5 visible rows plus 1 scroll row.
} QualifyingPokemonDisplay;                               // size = 0xD4

extern unk_D_83003CE0 D_83003CE0;
extern unk_D_83003CE0 D_83003DE0;

extern char** sBattleModeLabels;

char* RentalRules_GetPokemonName(s32 file_number);
void RentalRules_LoadBackgroundArchive(void);
void RentalRules_PollInput(void);
s16* RentalRules_GetRuleIdList(SessionContext* session_context);
char* RentalRules_GetModeLabel(s8 arg0);
char* RentalRules_GetCategoryLabel(s8 arg0);
s32 RentalRules_RuleListHasEmptyEntry(s16* arg0);
void RentalRules_UpdateFadeIn(void);
void RentalRules_UpdateMainInput(void);
void RentalRules_UpdateWaitPopupClose(void);
void RentalRules_UpdateFadeOut(void);
s32 RentalRules_UpdateExitDelay(void);
void RentalRules_DrawBackgroundFallback(void);
void RentalRules_DrawHeaderBanner(void);
void RentalRules_DrawWindowFrame(s16 left, s16 bottom, s16 right, s16 top);
void RentalRules_DrawFilledPanel(s16 x1, s16 y1, s16 width, s16 height, u8 r, u8 g, u8 b);
void RentalRules_DrawBulletIcon(s16 x, s16 y);
void RentalRules_DrawRuleListText(s16 x, s16 y);
void RentalRules_DrawRuleListPanel(void);
void RentalRules_DrawFrame(void);
void RentalRules_LoadCategoryStrings(void);
void RentalRules_LoadDescriptionStrings(void);
void RentalRules_Init(void);
s32 RentalRules_Update(void);
void RentalRules_Loop(void);
s32 RentalRules_Main(UNUSED s32 arg0, UNUSED s32 arg1);

s32 RentalRules_CountTextLines(s8* text);
void RentalRules_PopupUpdateOpen(void);
void RentalRules_PopupUpdateShown(void);
void RentalRules_PopupUpdateClose(void);
void RentalRules_PopupReset(void);
void RentalRules_PopupUpdate(void);
void RentalRules_PopupDraw(void);
void RentalRules_PopupOpen(s16 text_index);
s32 RentalRules_PopupIsActive(void);
s32 RentalRules_PopupGetProgress(void);

s32 RentalRules_SpeciesMatchesCategory(s16 species, s16 ruleset);
s16 RentalRules_CountMatchingSpecies(s16 ruleset);
s32 RentalRules_BuildSpeciesPage(QualifyingPokemonDisplayRow* row, s16 current_row_index, s16 ruleset);
QualifyingPokemonDisplayRow* RentalRules_AdvancePageNode(QualifyingPokemonDisplayRow* row, s32 advance_amount);
s32 RentalRules_ScrollPageUp(QualifyingPokemonDisplay* display);
s32 RentalRules_ScrollPageDown(QualifyingPokemonDisplay* display);
void RentalRules_QualifyingSpeciesWindowUpdateOpen(QualifyingPokemonDisplay* display);
void RentalRules_QualifyingSpeciesWindowUpdateShown(QualifyingPokemonDisplay* display);
void RentalRules_QualifyingSpeciesWindowUpdateScrolling(QualifyingPokemonDisplay* display);
void RentalRules_QualifyingSpeciesWindowUpdateClose(QualifyingPokemonDisplay* display);
void RentalRules_DrawScrollbar(s16 x, s16 y, QualifyingPokemonDisplay* display);
void RentalRules_DrawEligibilityPanelLegend(s16 x, s16 y);
void RentalRules_DrawSpeciesPage(s16 x, s16 y, QualifyingPokemonDisplayRow* node);
void RentalRules_QualifyingSpeciesWindowInit(s32 arg0);
void RentalRules_QualifyingSpeciesWindowUpdate(void);
void RentalRules_QualifyingSpeciesWindowDraw(void);
void RentalRules_QualifyingSpeciesWindowOpen(void);
s32 RentalRules_QualifyingSpeciesWindowIsActive(void);
s32 RentalRules_GetSpeciesWindowOpeningProgress(void);

#endif // _FRAGMENT55_H_
