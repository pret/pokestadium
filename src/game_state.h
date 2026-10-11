#ifndef _29BA0_H_
#define _29BA0_H_

#include "global.h"
#include "jpeg_stream.h"
#include "src/controller.h"
#include "PR/leo.h"

typedef struct arg1_func_80019420 {
    /* 0x00 */ s8 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ void* unk_04;
} arg1_func_80019420; // size = 0x8

typedef struct unk_D_800AE520 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 fragment_id;
    /* 0x04 */ u8* rom_start;
    /* 0x08 */ u8* rom_end;
    /* 0x0C */ s32 arg0;
    /* 0x10 */ s32 arg1;
} unk_D_800AE520; // size >= 0x14

typedef struct BattleMonSpecies {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
} BattleMonSpecies; // size = 0x2

typedef struct BattleMon {
    /* 0x00 */ BattleMonSpecies unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09[4];
    /* 0x0D */ u8 pad0D;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ u16 unk_1E;
    /* 0x20 */ u8 unk_20[4];
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ u8 unk_30[11];
    /* 0x3B */ u8 unk_3B[11];
    /* 0x46 */ u8 unk_46[11];
    /* 0x51 */ u8 pad51;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
} BattleMon; // size = 0x54

typedef struct ExtendedRosterInfo {
    /* 0x000 */ u16 unk_000;
    /* 0x002 */ u8 unk_002;
    /* 0x003 */ u8 unk_003;
    /* 0x004 */ char unk004[0x10];
    /* 0x014 */ char unk_014[4];
    /* 0x018 */ char unk018[0x10];
    /* 0x028 */ BattleMon unk_028[1];
    /* 0x07C */ char unk07C[0x1A4];
    /* 0x220 */ char unk_220[0x4];
    /* 0x224 */ char unk224[0x24];
} ExtendedRosterInfo; // size = 0x248

typedef struct TeamRoster {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001;
    /* 0x002 */ u8 unk_002;
    /* 0x004 */ Controller* controller;
    /* 0x008 */ char unk_008[4];
    /* 0x00C */ char unk00C[0xC];
    /* 0x018 */ s32 unk_018;
    /* 0x01C */ BattleMon unk_01C[6];
    /* 0x214 */ ExtendedRosterInfo* unk_214;
    /* 0x218 */ char unk218[0x4];
} TeamRoster; // size = 0x21C

typedef struct BattleSessionTeams {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ TeamRoster* unk_04;
    /* 0x08 */ TeamRoster* unk_08[2];
    /* 0x10 */ ModelLoadContext* unk_10;
    /* 0x14 */ ModelNodeView* unk_14;
    /* 0x18 */ ModelNodeView* unk_18;
    /* 0x1C */ u8 unk_1C;
    /* 0x1D */ u8 unk_1D;
    /* 0x1E */ u8 unk_1E;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ arg1_func_80019420* unk_24;
} BattleSessionTeams; // size = 0x28

typedef struct SessionContext {
    /* 0x0000 */ s8 unk_0000;
    /* 0x0001 */ s8 unk_0001;
    /* 0x0002 */ s8 unk_0002;
    /* 0x0003 */ s8 unk_0003;
    /* 0x0004 */ TeamRoster unk_0004[4];
    /* 0x0874 */ ExtendedRosterInfo unk_0874[4];
    /* 0x1194 */ BattleSessionTeams unk_1194[2];
    /* 0x11E4 */ u8 unk_11E4[2][4];
    /* 0x11EC */ u8 unk_11EC;
    /* 0x11EC */ u8 unk_11ED;
    /* 0x11EC */ u8 unk_11EE;
    /* 0x11EC */ u8 unk_11EF;
    /* 0x11F0 */ u8 gbStarterChoice;
    /* 0x11F1 */ char unk11F1[0x1];
    /* 0x11F2 */ u8 unk_11F2;
    /* 0x11F3 */ u8 unk_11F3;
    /* 0x11F4 */ u8 unk_11F4;
    /* 0x11F5 */ u8 unk_11F5;
    /* 0x11F6 */ u16 unk_11F6;
} SessionContext; // size = 0x11F8

extern u16 D_80073660[16][256];
extern s32 gCurrentGameState;
extern unk_D_800AE520 D_800AE520;
extern SessionContext D_800AE540;
extern BinArchive* D_800AF738;

s32 Game_DoCopyProtection(s32 state);
s32 Fragment_LoadAndCall(s32 arg0, u8* romStart, u8* romEnd, u32 arg3, u32 arg4);
void Fragment_QueueCall(s32 arg0, u8* arg1, u8* arg2, s32 arg3, s32 arg4);
TeamRoster* Trainer_GetSlots(void);
s32 GbSave_GetActivePort(void);
void GbSave_SetActivePort(s32 arg0);
void Controller_PollInputs(void);
s32 Stage_RunDemoScene(s16 arg0);
void State_RunCredits(void);
void State_N64LogoIntro(void);
void State_TitleScreen(void);
void State_N64ddBootUnused(void);
void State_StubbedDebug(void);
void State_AreaSelect(void);
void State_EventBattle(void);
void State_Options(void);
void State_MenuSelect(void);
s16 RuleWizard_StadiumMenu(s16 arg0);
void State_StadiumMenu(void);
s32 RuleWizard_FreeBattle(s16 arg0);
void State_FreeBattle(void);
s16 RuleWizard_VsMewtwo(s16 arg0);
void State_VsMewtwo(void);
void State_KidsClub(void);
void State_Gallery(void);
void State_VictoryPalace(void);
void State_GbTower(void);
s16 RuleWizard_GymLeaderCastle(s16 arg0, s16 arg1);
void State_GymLeaderCastle(void);
void State_BattleNow(s32 arg0);
void State_BattleFromEvent(void);
void State_FastN64Logo(void);
void State_FastBattle(void);
void func_8002B244(void);
void State_KidsClubTitle(void);
void Game_ShutdownAndLoadFragment(s32 arg0, s32 arg1);
void Game_ResetStorageDevice(void);
void Game_Thread(UNUSED LEODiskID* arg);

#endif // _29BA0_H_
