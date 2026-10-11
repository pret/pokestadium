#ifndef _FRAGMENT43_H_
#define _FRAGMENT43_H_

#include "global.h"
#include "gallery.h"

typedef struct unk_D_83402E4C {
    /* 0x00 */ s16 unk_00;
    /* 0x00 */ s16 unk_02;
    /* 0x00 */ s16 unk_04;
    /* 0x00 */ s16 unk_06;
    /* 0x00 */ s8 unk_08;
    /* 0x00 */ s8 unk_09;
    /* 0x00 */ s16 unk_0A;
    /* 0x00 */ s16* unk_0C;
} unk_D_83402E4C; // size = 0x10

typedef struct unk_D_83407B18_008 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ char unk_0A[0x2];
} unk_D_83407B18_008; // size >= 0xC

typedef struct unk_D_83407B18 {
    /* 0x00 */ unk_D_83407B00 unk_00;
    /* 0x08 */ unk_D_83407B18_008 unk_08;
    /* 0x14 */ char unk14[0x4];
} unk_D_83407B18; // size = 0x18

extern unk_D_83402EE0 D_83402EE0[24];
extern s32 D_83403C00[24];
extern unk_D_83403C60 D_83403C60[36];
extern unk_D_83403C60 D_834063C0[21];
extern unk_D_83403C60* D_83407ABC;
extern unk_D_83403C60* D_83407AC0;
extern unk_D_83407AC8 D_83407AC8;
extern s32 D_83407AE4;
extern s32 D_83407AE8;
extern s32 D_83407AEC;
extern unk_D_83407B00 D_83407AF8;
extern unk_D_83407B00 D_83407B00;
extern unk_D_83407B00 D_83407B08;
extern unk_D_83407B00 D_83407B10;
extern unk_D_83407B18 D_83407B18;
extern unk_D_83407B00 D_83407B30;
extern unk_D_83407B38 D_83407B38;

extern s32 D_83402E20;
extern s32 D_83402E24;
extern s32 D_83402E28;

void Gallery_LoadUnlockedBackgrounds(void);
s32 Gallery_ControlRecordIsPopulated(unk_D_83406EB0* arg0);
s32 Gallery_ControlRecordIsDirty(unk_D_83406EB0* arg0);
s32 Gallery_ArraysDiffer(unk_D_83403C60* arg0, unk_D_83403C60* arg1, s32 arg2);
s32 Gallery_BackgroundsChanged(void);
s32 Gallery_SaveUnlockedBackgrounds(s32 arg0, s32 arg1);
void func_8340051C(void);
void Gallery_ResetPhotoPool(void);
void Gallery_ClearPhotoRecord(unk_D_83403C60* arg0);
void Gallery_SwapPhotoRecords(unk_D_83403C60* arg0, unk_D_83403C60* arg1);
s32 Gallery_PhotoRecordsEqual(unk_D_83403C60* arg0, unk_D_83403C60* arg1);
void Gallery_SetEnlargeTarget(unk_D_83403C60* arg0);
unk_D_83403C60* Gallery_GetEnlargeTarget(s32 arg0);
void Gallery_InitPageCursor(unk_D_83407B00* arg0);
s32 Gallery_CountTextLines(s8* arg0);
s32 Gallery_CountValidPhotos(unk_D_83403C60* arg0, s32 arg1, s32 arg2);
s32 Gallery_FindNthEmptySlot(unk_D_83403C60* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 Gallery_FindFirstEmptySlot(unk_D_83403C60* arg0, s32 arg1);
void Gallery_DrawBluePanel(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void Gallery_DrawRoundedFrame(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void Gallery_DrawHeaderBar(s32 arg0, s32 arg1, s32 arg2, Color_RGBA8* arg3, Color_RGBA8* arg4);
void Gallery_DrawImageStrips(u16* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void Gallery_FillRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void Gallery_DrawWhiteBorder(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void Gallery_DrawDropShadow(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void Gallery_DrawPhotoThumbnail(u16* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void Gallery_DrawSelectionCorners(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void Gallery_DrawStatusIcon(s32 arg0, s32 arg1, s32 arg2);
void Gallery_InitSceneGrid(unk_D_83407B38* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, ModelLoadContext* arg5,
    BinArchive* arg6, unk_D_83403C60* arg7, s32 arg8, s32 arg9);
void Gallery_ProcessSceneGrid(unk_D_83407B38* arg0);
void Gallery_FinishActiveScene(void);
s32 Gallery_CountReadyScenesOnPage(unk_D_83407B38* arg0, s32 arg1);
void Gallery_ClearSavedPosition(unk_D_83407B00* arg0);
void Gallery_SavePosition(unk_D_83407B38* arg0, unk_D_83407B00* arg1);
void Gallery_RestorePosition(unk_D_83407B38* arg0, unk_D_83407B00* arg1);
void Gallery_IndexToGridPos(unk_D_83407B38* arg0, s32* arg1, s32* arg2, s32 arg3);
s32 Gallery_GridPosToIndex(unk_D_83407B38* arg0, s32 arg1, s32 arg2);
void Gallery_RebindSceneGridResources(unk_D_83407B38* arg0, ModelLoadContext* arg1, BinArchive* arg2);

void Gallery_InitStringTables(void);
char* Gallery_GetUiString(s32 arg0);
char* Gallery_CopyUiString(char* arg0, s32 arg1, s32 arg2);
char* Gallery_GetCommonUiString(s32 arg0);
char* Gallery_CopyCommonUiString(char* arg0, s32 arg1, u32 arg2);

void Gallery_DrawYesNoOptions(unk_D_83402E4C* arg0, s16 arg1);
void Gallery_DrawSaveOptions(unk_D_83402E4C* arg0);
void Gallery_DrawDeleteOptions(unk_D_83402E4C* arg0);
void Gallery_DrawMessagePrompt(unk_D_83402E4C* arg0);
void Gallery_ResetConfirmPrompt(void);
void Gallery_DrawConfirmPrompt(UNUSED s32 arg0);
void Gallery_UpdateConfirmPromptInput(void);
void Gallery_AdvanceConfirmPromptOpen(void);
void Gallery_AdvanceConfirmPromptClose(void);
s32 Gallery_UpdateConfirmPrompt(void);
s32 Gallery_OpenConfirmPrompt(s16 arg0, Controller* arg1);
s32 Gallery_RequestCloseConfirmPrompt(s16 arg0);
s16 Gallery_GetConfirmPromptResult(s16 arg0);

#endif // _FRAGMENT43_H_
