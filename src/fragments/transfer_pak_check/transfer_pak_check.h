#ifndef _FRAGMENT57_H_
#define _FRAGMENT57_H_

#include "global.h"
#include "src/gfx_rect.h"
#include "src/geo_node.h"
#include "src/save_data.h"

typedef struct Pak_PortStatus {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ char unk_08[1];
    /* 0x09 */ char unk09[0xD];
} Pak_PortStatus; // size = 0x16

typedef struct PakUi_StatusPopup {
    /* 0x00 */ u8 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char unk0C[0x4];
} PakUi_StatusPopup; // size = 0x10

typedef struct unk_D_82D09F1C {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s8 unk_08;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ s8 unk_0A;
    /* 0x0B */ s8 unk_0B;
} unk_D_82D09F1C; // size = 0xC

s32 Pak_CheckPiIntegrity(s32 arg0);
void PakUi_DrawMenuBackdrop(void);
void PakUi_BuildFrameBuffer(DepthBuffer* arg0, s16 arg1, s16 arg2);
void PakUi_DrawThickBoxBorder(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void PakUi_DrawThinBoxBorder(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void PakUi_DrawRotatingCorners(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
s32 PakUi_RenderPartyCardTexture(s32 arg0, unk_func_80011B94* arg1);
s32 PakUi_RenderIconPanelTexture(s32 arg0, unk_func_80011B94* arg1);
s32 PakUi_RenderBannerTexture(s32 arg0, unk_func_80011B94* arg1);
void PakUi_DrawPartyProgressBar(s32 arg0);
void PakUi_DrawTitleHeader(s16 arg0);
void PakUi_DrawPartyCardBadge(s32 arg0);
void PakUi_DrawPartyCardList(u8 arg0);
void PakUi_BuildPartyCard(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8* arg4);
void PakUi_InitPartyCard(s32 arg0);
void PakUi_BuildIconPanel(void);
void PakUi_BuildBottomBanner(void);
void PakUi_UpdatePartyDisplayFrame(s32 arg0, s16 arg1);
void TransferPak_InitPartyDisplay(void);
void PakUi_FreePartyDisplayModels(void);
s32 TransferPak_ShowRulesPrompt(void);
void PakUi_DrawDataPanelBorder(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void PakUi_DrawMenuOptionText(s16 arg0, s16 arg1, s16 arg2, s16 arg3, char* arg4);
void PakUi_DrawRulesPanel(s16 arg0, s16 arg1);
void PakUi_DrawDataSummaryPanel(s16 arg0, s16 arg1, SessionContinueData* arg2, s32 arg3);
void PakUi_UpdateConfirmDisplayFrame(s16 arg0, s16 arg1, SessionContinueData* arg2, s16 arg3, s16 arg4);
s32 TransferPak_ConfirmPrompt(SessionContinueData* arg0);
#if defined(VERSION_JP)
s16 TransferPak_MainMenu(void);
#else
s16 TransferPak_MainMenu(SessionContinueData* arg0);
#endif
void PakUi_DrawStatusPopup(PakUi_StatusPopup* arg0);
s32 PakUi_UpdateStatusPopup(PakUi_StatusPopup* arg0);
void PakUi_InitStatusPopup(PakUi_StatusPopup* arg0, s16 arg1, s16 arg2);
void PakUi_OpenStatusPopup(PakUi_StatusPopup* arg0, s16 arg1, s16 arg2);
s32 PakUi_RenderMenuIconTexture(s32 arg0, UNUSED unk_func_80011B94* a1);
s32 PakUi_ComputeBlinkAlpha(void);
#if defined(VERSION_JP)
void PakUi_DrawHeaderProgressBar(s32 arg0);
void PakUi_DrawBodyProgressBar(s32 arg0);
#else
void PakUi_DrawHeaderProgressBar(s32 arg0, s32 arg1);
void PakUi_DrawBodyProgressBar(s32 arg0, s32 arg1);
#endif
void PakUi_UpdateMenuDisplayFrame(s32 arg0, s32 arg1);
DepthBuffer* PakUi_BuildGameIconBuffer(s32 arg0);
DepthBuffer* PakUi_BuildControllerIconBuffer(void);
DepthBuffer* PakUi_BuildControllerIconBufferAlt(void);
DepthBuffer* PakUi_BuildMonIconBuffer(void);
DepthBuffer* PakUi_BuildTextLabelBuffer(s8* arg0, u8 arg1, u8 arg2, u8 arg3);
void TransferPak_MenuIconsInit(void);
void TransferPak_MenuIconsFree(void);
s32 TransferPak_MenuHandleInput(void);
s32 TransferPak_MenuCursorToCode(void);
s16 TransferPak_MenuLoop(void);
void Pak_PollPortStatus(void);
void TransferPak_InitMenuGraphics(void);
s32 TransferPak_CheckMain(s32 arg0, s32 arg1);

#endif // _FRAGMENT57_H_
