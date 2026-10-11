#ifndef _FRAGMENT61_H_
#define _FRAGMENT61_H_

#include "global.h"
#include "src/geo_node.h"
#include "src/poke_icon.h"
#include "src/fragments/gallery_rental_viewer/gallery_rental_viewer.h"

struct RentalCarouselState;
struct unk_D_84229EB0;

typedef struct unk_D_8423D3A8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ unk_D_800A7440 unk_0E;
    /* 0x16 */ unk_D_800A7440 unk_16;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ ModelLoadContext* unk_24;
    /* 0x28 */ unk_func_8001B1FC* unk_28;
    /* 0x2C */ unk_D_838067F0_0168_0000* unk_2C;
} unk_D_8423D3A8; // size >= 0x30

typedef struct unk_D_842168A0_13608 {
    /* 0x00 */ char unk04[0x4];
} unk_D_842168A0_13608; // size >= 0x4

typedef struct unk_D_84229EB0_00024 {
    /* 0x0000 */ unk_D_838067F0_0168_0000 unk_0000[6];
    /* 0x4D10 */ u16 unk_4D10;
    /* 0x4D12 */ char unk_4D12[2];
    /* 0x4D14 */ char unk4D14[0xA];
    /* 0x4D1E */ s16 unk_4D1E;
    /* 0x4D20 */ s16 unk_4D20;
    /* 0x4D24 */ struct unk_D_84229EB0_00024* unk_4D24;
    /* 0x4D28 */ struct unk_D_84229EB0_00024* unk_4D28;
    /* 0x4D2C */ char unk4D2C[0x4];
} unk_D_84229EB0_00024; // size = 0x4D30

typedef struct RentalTeamTray {
    /* 0x0000 */ u8 unk_0000;
    /* 0x0001 */ u8 unk_0001;
    /* 0x0002 */ u8 unk_0002;
    /* 0x0003 */ u8 unk_0003;
    /* 0x0004 */ u8 unk_0004;
    /* 0x0006 */ s16 unk_0006;
    /* 0x0008 */ s16 unk_0008;
    /* 0x000A */ s16 unk_000A;
    /* 0x000C */ s16 unk_000C;
    /* 0x000E */ s16 unk_000E;
    /* 0x0010 */ s16 unk_0010;
    /* 0x0012 */ s16 unk_0012;
    /* 0x0014 */ s16 unk_0014;
    /* 0x0016 */ s16 unk_0016;
    /* 0x0018 */ s16 unk_0018;
    /* 0x001A */ s16 unk_001A;
    /* 0x001C */ u16 unk_001C;
    /* 0x001E */ char unk_001E[2];
    /* 0x0020 */ char unk0020[0x10];
    /* 0x0030 */ unk_D_838067F0_0168_0000 unk_0030[6];
    /* 0x4D40 */ struct RentalCarouselState* unk_4D40;
    /* 0x4D44 */ unk_D_8423D3A8* unk_4D44;
    /* 0x4D48 */ struct unk_D_84229EB0* unk_4D48;
} RentalTeamTray; // size = 0x4D4C

typedef struct RentalRoster {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ BattleMon unk_04[1];
} RentalRoster; // size >= 0x58

typedef struct RentalCarouselState {
    /* 0x00000 */ u8 unk_00000;
    /* 0x00001 */ u8 unk_00001;
    /* 0x00002 */ u8 unk_00002;
    /* 0x00003 */ u8 unk_00003;
    /* 0x00004 */ u8 unk_00004;
    /* 0x00005 */ u8 unk_00005;
    /* 0x00006 */ u8 unk_00006;
    /* 0x00007 */ u8 unk_00007;
    /* 0x00008 */ u8 unk_00008;
    /* 0x00009 */ u8 unk_00009;
    /* 0x0000A */ s16 unk_0000A;
    /* 0x0000C */ s16 unk_0000C;
    /* 0x0000E */ s16 unk_0000E;
    /* 0x00010 */ s16 unk_00010;
    /* 0x00012 */ s16 unk_00012;
    /* 0x00014 */ s16 unk_00014;
    /* 0x00016 */ s16 unk_00016;
    /* 0x00018 */ s16 unk_00018;
    /* 0x0001A */ s16 unk_0001A;
    /* 0x0001C */ unk_D_838067F0_003C unk_0001C[13];
    /* 0x0013A */ char unk0013A[0x2];
    /* 0x0013C */ RentalRoster* unk_0013C;
    /* 0x00140 */ unk_D_838067F0_0168* unk_00140;
    /* 0x00144 */ char unk00144[0x4];
    /* 0x00148 */ unk_D_838067F0_0168 unk_00148[8];
    /* 0x13608 */ RentalTeamTray* unk_13608;
    /* 0x1360C */ unk_D_8423D3A8* unk_1360C;
} RentalCarouselState; // size = 0x13610

typedef struct unk_D_84229EB0 {
    /* 0x00000 */ u8 unk_00000;
    /* 0x00001 */ u8 unk_00001;
    /* 0x00002 */ u8 unk_00002;
    /* 0x00003 */ u8 unk_00003;
    /* 0x00004 */ u8 unk_00004;
    /* 0x00005 */ s8 unk_00005;
    /* 0x00006 */ s16 unk_00006;
    /* 0x00008 */ s16 unk_00008;
    /* 0x0000A */ s16 unk_0000A;
    /* 0x0000C */ u8 unk_0000C;
    /* 0x0000D */ u8 unk_0000D;
    /* 0x0000E */ s16 unk_0000E;
    /* 0x00010 */ s16 unk_00010;
    /* 0x00012 */ s16 unk_00012;
    /* 0x00014 */ s16 unk_00014;
    /* 0x00016 */ s16 unk_00016;
    /* 0x00018 */ s16 unk_00018;
    /* 0x0001A */ s16 unk_0001A;
    /* 0x0001C */ s16 unk_0001C;
    /* 0x0001E */ u8 unk_0001E;
    /* 0x0001F */ u8 unk_0001F;
    /* 0x00020 */ u8 unk_00020;
    /* 0x00024 */ unk_D_84229EB0_00024* unk_00024;
    /* 0x00028 */ unk_D_84229EB0_00024 unk_00028[3];
    /* 0x0E7B8 */ char unk0E7B8[0x4D30];
    /* 0x134E8 */ RentalTeamTray* unk_134E8;
    /* 0x134EC */ RentalCarouselState* unk_134EC;
    /* 0x134F0 */ unk_D_8423D3A8* unk_134F0;
    /* 0x134F4 */ char unk134F4[0x4];
} unk_D_84229EB0; // size = 0x134F8

typedef struct unk_D_8423D3D8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ TeamRoster* unk_04;
} unk_D_8423D3D8; // size = 0x8

typedef struct unk_D_84211704 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s8 unk_0A;
    /* 0x0B */ s8 unk_0B;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u16 unk_0E;
} unk_D_84211704; // size = 0x10

s32 TeamSelection_CheckCartRemoved(s32 arg0);
char* TeamSelection_GetTextFromSetA(s32 arg0);
char* TeamSelection_GetTextFromSetB(s32 arg0);
char* TeamSelection_GetModeText(s32 arg0);
char* TeamSelection_GetLabelText(s32 arg0);
char* TeamSelection_GetInstructionText(s32 arg0);
char* TeamSelection_FormatText(char* arg0, s32 arg1, s32 arg2);
void TeamSelection_DrawCornerFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void TeamSelection_DrawColoredFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void TeamSelection_DrawAnimatedGoldCorners(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void TeamSelection_DrawTexturedFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void TeamSelection_DrawTexturedPanel(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void TeamSelection_DrawHeaderBackdrop(s16 arg0, s16 arg1);
void TeamSelection_DrawRegistrationHeaderBackdrop(s16 arg0, s16 arg1);
void TeamSelection_DrawCategoryBanner(s16 arg0, s16 arg1, s16 arg2);
void TeamSelection_DrawGradientPanel(s16 arg0, s16 arg1, s16 arg2, Color_RGBA8* arg3, Color_RGBA8* arg4);
void TeamSelection_DrawTitleHeader(void);
void TeamSelection_DrawCategoryRow(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void TeamSelection_DrawCategoryScreen(s16 arg0, s16 arg1, s16 arg2);
void TeamSelection_WaitForConfirm(void);
s32 TeamSelection_HandleConfirmInput(void);
s16 TeamSelection_RunCategorySelection(void);
void TeamSelection_DrawFrame(s16 arg0, s16 arg1);
void TeamSelection_RenderFrame(UNUSED s16 arg0, s16 arg1, s16 arg2);
s16 TeamSelection_RunModal(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void TeamSelection_Update(UNUSED s16 arg0, UNUSED s32 arg1);
void TeamSelection_Open(s16 arg0, s32 arg1, s16 arg2);
void TeamSelection_RunInputLoop(s16 arg0, s16 arg1, s16 arg2);
void TeamSelection_InitializeSlots(void);
void TeamSelection_InitializeSlot(unk_D_8423D3D8* arg0, s16 arg1);
s32 Team_CommitSelectionToTrainer(unk_D_8423D3D8* arg0, s16 arg1);
void TeamSelection_FadeOut(s32 arg0);
void TeamSelection_FadeIn(void);
void TeamSelection_ApplySlotSelection(s16 arg0, s16 arg1);
s32 Team_SelectTeams(void);
s32 Team_SelectRegisteredTeams(void);
void RegisteredTeam_Register(void);
void RegisteredTeam_Browse(void);
void RegisteredTeam_Delete(void);
s32 RegisteredTeam_Manage(void);
void Rental_LoadRosterForMode(void);
void Rental_LoadBackgroundImage(void);
s32 Rental_Main(s32 arg0, UNUSED s32 arg1);

s32 TeamSelection_TrainerSlots_GraphCallback(s32 arg0, unk_func_80011B94* arg1);
void TeamSelection_TrainerSlots_DrawCursorPrompt(void);
void TeamSelection_TrainerSlots_DrawEntry(s32 arg0);
void TeamSelection_TrainerSlots_DrawEntries(void);
void TeamSelection_TrainerSlots_DrawEntryFrame(s32 arg0, s16 arg1, s16 arg2);
void TeamSelection_TrainerSlots_Render(s32 arg0);
void TeamSelection_TrainerSlots_UpdateModelScale(s16 arg0, f32 arg1);
void TeamSelection_TrainerSlots_UpdateModelPose(s16 arg0, f32 arg1);
void TeamSelection_TrainerSlots_MoveFromSpecialUp(void);
void TeamSelection_TrainerSlots_MoveFromTrainerToSpecial(void);
void TeamSelection_TrainerSlots_MovePrevious(void);
void TeamSelection_TrainerSlots_MoveNext(void);
void TeamSelection_TrainerSlots_HandleInput(void);
void TeamSelection_TrainerSlots_AnimateOpen(void);
void TeamSelection_TrainerSlots_AnimateSelected(void);
void TeamSelection_TrainerSlots_AnimateClose(void);
void TeamSelection_TrainerSlots_Teardown(void);
void TeamSelection_TrainerSlots_HandleRulePrompt(void);
s32 TeamSelection_TrainerSlots_Update(void);
void TeamSelection_TrainerSlots_ApplySaveStates(void);
void TeamSelection_TrainerSlots_InitializeModels(void);
void TeamSelection_TrainerSlots_PollGameBoySaves(void);
s32 TeamSelection_TrainerSlots_Initialize(s16 arg0);
s32 TeamSelection_TrainerSlots_Open(s16 arg0, s32 arg1);
s16 TeamSelection_TrainerSlots_GetSelection(void);

void Rental_DrawTeamSlotFrame(s16 arg0, s16 arg1, s32 arg2);
void Rental_DrawTeamTrayFrame(RentalTeamTray* arg0, s16 arg1, s16 arg2);
void Rental_DrawTeamCursor(RentalTeamTray* arg0);
void Rental_DrawTeamTray(RentalTeamTray* arg0, s32 arg1);
void Rental_BeginSlotReplace(RentalTeamTray* arg0);
s32 Rental_SaveTeamToDeck(RentalTeamTray* arg0);
s32 Rental_CheckTeamLevelCap(RentalTeamTray* arg0);
void Rental_TeamTrayHide(RentalTeamTray* arg0);
void Rental_TeamTrayShow(RentalTeamTray* arg0);
void Rental_OpenSlotAssignmentDialog(RentalTeamTray* a0);
void Rental_ResolveSlotPick(RentalTeamTray* arg0);
void Rental_TeamTraySlideIn(RentalTeamTray* arg0);
void Rental_TeamTraySlideOut(RentalTeamTray* arg0);
void Rental_BeginSlotReplacement(RentalTeamTray* arg0);
void Rental_TeamCursorLeft(RentalTeamTray* arg0);
void Rental_TeamCursorRight(RentalTeamTray* arg0);
void Rental_TeamCursorUp(RentalTeamTray* arg0);
void Rental_TeamCursorDown(RentalTeamTray* arg0);
void Rental_TeamGridHandleInput(RentalTeamTray* arg0);
void Rental_ConfirmTeam(RentalTeamTray* arg0);
void Rental_HandleTeamConfirmation(RentalTeamTray* arg0);
void Rental_HandleRegisteredTeamConfirmation(RentalTeamTray* arg0);
void Rental_HandleLevelCapWarning(RentalTeamTray* arg0);
void Rental_HandleTeamSaveResult(RentalTeamTray* arg0);
void Rental_HandleTeamCancel(RentalTeamTray* arg0);
void Rental_TeamTraySlideTick(RentalTeamTray* arg0);
s32 Rental_TeamSlotsUpdate(RentalTeamTray* arg0);
s32 Rental_InitTeamTray(RentalTeamTray* arg0, RentalCarouselState* arg1, unk_D_8423D3A8* arg2, unk_D_84229EB0* arg3, s16 arg4, u16 arg5,
                  char* arg6, s16 arg7, s16 arg8, s16 arg9);
s32 Rental_TeamTrayOpen(RentalTeamTray* arg0, s16 arg1);
s32 Rental_TeamTrayResume(RentalTeamTray*);
s32 Rental_ResetTeamSlots(RentalTeamTray*);
s32 Rental_RemoveHighlightedSlot(RentalTeamTray*);
s32 Rental_AssignMonToSlot(RentalTeamTray*, unk_D_838067F0_0168_0000*);
s32 Rental_ClearCurrentSlotSelection(RentalTeamTray*);
s32 Rental_CanAddMonToTeam(RentalTeamTray*, unk_D_838067F0_0168_0000*);
s32 Rental_TeamContainsMon(RentalTeamTray*, unk_D_838067F0_0168_0000*);
s32 Rental_TeamTrayIsIdle(RentalTeamTray* arg0);
void Rental_CopyRosterToTeam(RentalTeamTray* arg0, BattleMon* arg1, s16 arg2);

void Rental_CarouselDraw(RentalCarouselState*, s32);
s32 Rental_PrimeCarousel(RentalCarouselState*, RentalTeamTray*, unk_D_8423D3A8*, s16, s16, s16, s16, s16, RentalRoster*);
s32 Rental_CarouselTick(RentalCarouselState*);
s32 Rental_CarouselOpen(RentalCarouselState*, s16);
s32 Rental_CarouselResumeAfterAssign(RentalCarouselState*);
s32 Rental_CarouselAcknowledgeAssign(RentalCarouselState*);
void Rental_CarouselRequestRedraw(RentalCarouselState*);
s32 Rental_CarouselResumeInput(RentalCarouselState*);
s32 Rental_CarouselIsIdle(RentalCarouselState*);

void TeamSelection_Preview_DrawOptionText(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s8* arg4);
void TeamSelection_Preview_DrawHeader(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void TeamSelection_Preview_DrawTypeIcon(s16 arg0, s16 arg1, s16 arg2);
void TeamSelection_Preview_DrawMovePanel(s16 arg0, s16 arg1, s32 arg2);
s16 TeamSelection_Preview_CenterMoveText(s16 arg0, s16 arg1, char* arg2);
void TeamSelection_Preview_DrawPokemonDetails(unk_D_8423D3A8* arg0, s32 arg1);
void func_8420C360(unk_D_8423D3A8* arg0);
void TeamSelection_Preview_HandleInput(unk_D_8423D3A8* arg0);
void TeamSelection_Preview_Open(unk_D_8423D3A8* arg0);
void TeamSelection_Preview_Close(unk_D_8423D3A8* arg0);
s32 TeamSelection_Preview_Initialize(unk_D_8423D3A8* arg0);
s32 TeamSelection_Preview_Update(unk_D_8423D3A8* arg0);
s32 TeamSelection_Preview_StartFull(unk_D_8423D3A8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5,
    unk_D_838067F0_0168_0000* arg6, s16 arg7);
s32 TeamSelection_Preview_StartCompact(unk_D_8423D3A8* arg0, s16 arg1, s16 arg2, unk_D_838067F0_0168_0000* arg3);
s32 TeamSelection_Preview_GetSelectionState(unk_D_8423D3A8* arg0);
void TeamSelection_RulePrompt_DrawOption(s16 arg0, s16 arg1, s16 arg2, char* arg3);
void TeamSelection_RulePrompt_DrawOptionSetFour(unk_D_84211704* arg0);
void TeamSelection_RulePrompt_DrawOptionSetThreeA(unk_D_84211704* arg0);
void TeamSelection_RulePrompt_DrawOptionSetThreeB(unk_D_84211704* arg0);
void TeamSelection_RulePrompt_DrawOptionSetThreeC(unk_D_84211704* arg0);
void TeamSelection_RulePrompt_DrawOptionSetTwo(unk_D_84211704* arg0);
void TeamSelection_RulePrompt_DrawSingleLabel(unk_D_84211704* arg0);
void TeamSelection_RulePrompt_DrawThreeRowPanel(unk_D_84211704* arg0);
void TeamSelection_RulePrompt_DrawOffsetThreeRowPanel(unk_D_84211704* arg0);
void TeamSelection_RulePrompt_DrawSmallThreeRowPanel(unk_D_84211704* arg0);
void TeamSelection_RulePrompt_DrawSmallThreeRowVariant(unk_D_84211704* arg0);
void TeamSelection_RulePrompt_DrawOptionSetTwoB(unk_D_84211704* arg0);
void TeamSelection_RulePrompt_DrawNumberAndLabel(unk_D_84211704* arg0, s16 arg1);
void TeamSelection_RulePrompt_DrawBinaryLabel(unk_D_84211704* arg0, s16 arg1);
void TeamSelection_RulePrompt_DrawFrame(s32 arg0);
void TeamSelection_RulePrompt_HandleInput(void);
void TeamSelection_RulePrompt_AdvanceOpen(void);
void TeamSelection_RulePrompt_AdvanceClose(void);
s32 TeamSelection_RulePrompt_Update(void);
s32 TeamSelection_RulePrompt_Open(s16 arg0, Controller* arg1);
s32 TeamSelection_RulePrompt_BeginClose(s16 arg0);
s16 TeamSelection_RulePrompt_TryFinish(s16 arg0);
s32 func_8420DBA0(unk_D_84229EB0_00024* arg0);
void RegisteredTeam_DeleteAndCompact(unk_D_84229EB0_00024* arg0);
void TeamSelection_RegisteredTeam_DrawCard(unk_D_84229EB0* arg0, s16 arg1, s16 arg2, unk_D_84229EB0_00024* arg3);
void TeamSelection_RegisteredTeam_DrawHeader(s16 arg0, s16 arg1);
void TeamSelection_RegisteredTeam_DrawScrollbar(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_DrawAnimatedListFrame(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_DrawAnimatedCursor(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_DrawVisibleCards(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_Render(unk_D_84229EB0* arg0, s32 arg1);
unk_D_84229EB0_00024* TeamSelection_RegisteredTeam_GetNext(unk_D_84229EB0_00024* arg0, s32 arg1);
unk_D_84229EB0_00024* TeamSelection_RegisteredTeam_GetPrevious(unk_D_84229EB0_00024* arg0, s32 arg1);
s32 TeamSelection_RegisteredTeam_Load(unk_D_84229EB0_00024* arg0, s16 arg1);
void TeamSelection_RegisteredTeam_UpdatePreview(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_InitializeSelection(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_SetOpeningPosition(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_AdvanceOpen(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_AdvanceClose(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_AdvanceReturnFromEdit(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_MoveListUp(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_MoveListDown(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_HandleListInput(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_MovePokemonLeft(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_MovePokemonRight(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_MovePokemonUp(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_MovePokemonDown(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_HandlePokemonInput(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_AdvanceCursorTransition(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_AdvancePanelShrink(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_AdvancePanelExpand(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_HandleRulePromptA(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_HandleRulePromptB(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_HandleSavePrompt(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_EditTeam(unk_D_84229EB0* arg0);
void RegisteredTeam_SaveFromTray(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_HandleDiscardPrompt(unk_D_84229EB0* arg0);
void TeamSelection_RegisteredTeam_LoadVisible(unk_D_84229EB0* arg0);
s32 TeamSelection_RegisteredTeam_Update(unk_D_84229EB0* arg0);
s32 TeamSelection_RegisteredTeam_Initialize(unk_D_84229EB0* arg0, RentalTeamTray* arg1, RentalCarouselState* arg2, unk_D_8423D3A8* arg3,
                  s16 arg4, s16 arg5, s16 arg6, s16 arg7);
s32 RegistrationManager_Begin(unk_D_84229EB0* arg0);
s32 RegistrationManager_Initialize(unk_D_84229EB0* arg0, u16 arg1, char* arg2, unk_D_838067F0_0168_0000* arg3);
s32 TeamSelection_RegisteredTeam_GetSelection(unk_D_84229EB0* arg0);
s32 RegisteredTeam_LoadSelected(unk_D_84229EB0* arg0, unk_D_84229EB0_00024** arg1);
void TeamSelection_RegisteredTeam_ApplySelection(unk_D_84229EB0* arg0, s16 arg1);

#endif // _FRAGMENT61_H_
