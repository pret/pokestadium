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
    /* 0x9C */ char unk9C[0x64];
} unk_D_83003CE0; // size = 0x100

typedef struct SpeciesQualificationStatus {
    /* 0x00 */ s16 species;
    /* 0x02 */ s16 is_eligible;
} SpeciesQualificationStatus; // size = 0x4

typedef struct QualifyingPokemonDisplayRow {
    /* 0x00 */ SpeciesQualificationStatus species_listed[6];
    /* 0x18 */ struct QualifyingPokemonDisplayRow* below_neighbour;
    /* 0x1C */ struct QualifyingPokemonDisplayRow* above_neighbour;
} QualifyingPokemonDisplayRow; // size = 0x20

typedef struct QualifyingPokemonDisplay {
    /* 0x00 */ s16 qualifying_list_state;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 pokedex_index;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x10 */ QualifyingPokemonDisplayRow* self_node;
    /* 0x14 */ QualifyingPokemonDisplayRow unk_14[6];
} QualifyingPokemonDisplay; // size = 0xD4

extern unk_D_83003CE0 D_83003CE0;
extern unk_D_83003CE0 D_83003DE0;

extern char** D_830039C0;

char* RentalRules_GetPokemonName(s32 arg0);
void RentalRules_LoadBackgroundArchive(void);
void RentalRules_PollInput(void);
s16* RentalRules_GetRuleIdList(SessionContext* arg0);
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

s32 RentalRules_SpeciesMatchesCategory(s16 arg0, s16 arg1);
s16 RentalRules_CountMatchingSpecies(s16 arg0);
s32 RentalRules_BuildSpeciesPage(QualifyingPokemonDisplayRow* arg0, s16 arg1, s16 arg2);
QualifyingPokemonDisplayRow* RentalRules_AdvancePageNode(QualifyingPokemonDisplayRow* arg0, s32 arg1);
s32 RentalRules_ScrollPageUp(QualifyingPokemonDisplay* arg0);
s32 RentalRules_ScrollPageDown(QualifyingPokemonDisplay* arg0);
void RentalRules_ListUpdateOpen(QualifyingPokemonDisplay* arg0);
void RentalRules_ListUpdateShown(QualifyingPokemonDisplay* arg0);
void RentalRules_ListUpdateScrolling(QualifyingPokemonDisplay* arg0);
void RentalRules_ListUpdateClose(QualifyingPokemonDisplay* arg0);
void RentalRules_DrawScrollbar(s16 arg0, s16 arg1, QualifyingPokemonDisplay* arg2);
void RentalRules_DrawEligibilityPanelLegend(s16 arg0, s16 arg1);
void RentalRules_DrawSpeciesPage(s16 arg0, s16 arg1, QualifyingPokemonDisplayRow* arg2);
void RentalRules_ListInit(s32 arg0);
void RentalRules_ListUpdate(void);
void RentalRules_ListDraw(void);
void RentalRules_ListOpen(void);
s32 RentalRules_ListIsActive(void);
s32 RentalRules_ListGetProgress(void);


#endif // _FRAGMENT55_H_
