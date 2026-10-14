#ifndef _26820_H_
#define _26820_H_

#include "global.h"
#include "gb_data.h"
#include "game_state.h"

typedef struct GameOptions {
    /* 0x00 */ s16 gbTowerUnlockTier; // 0 = normal, 1 = Doduo, 2 = Dodrio.
    // Opaque word carried into/out of GB Tower. The inherited pointer type is
    // preserved; no self-linked GameOptions list has been established.
    /* 0x04 */ struct GameOptions* unk_04;
} GameOptions; // size = 0x8

typedef struct ModeSettings {
    /* 0x00 */ u16 clearedModes; // Bit (1 << session mode); Mewtwo victory is bit 8.
    /* 0x02 */ char unk02[0x2];
    /* 0x04 */ u8 castleClears; // Highest completed castle location + 1, capped at 8.
    /* 0x05 */ u8 nintendoCupClears; // Highest completed division + 1, capped at 4.
    /* 0x06 */ u8 primeCupClears; // Highest completed division + 1, capped at 4.
    /* 0x07 */ u8 mewtwoUnlocked; // Set when clearedModes reaches 0xF8.
} ModeSettings; // size = 0x8

typedef struct SessionContinueData {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05[2][4];
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ char unk_10[16];
} SessionContinueData; // size = 0x20

typedef struct DeckRecordHeader {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0xA];
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ s16 unk_0E;
} DeckRecordHeader; // size >= 0x10

typedef struct RegisteredTeamSlot {
    /* 0x000 */ DeckRecordHeader unk_000;
    /* 0x010 */ GbPokemonNamedRecord unk_010[1];
    /* 0x047 */ char unk047[0x119];
} RegisteredTeamSlot; // size = 0x160

typedef struct RegisteredTeamBank {
    /* 0x0000 */ RegisteredTeamSlot unk_0000[4][10];
} RegisteredTeamBank; // size = 0x3700

typedef struct SaveOptionsRecord {
    /* 0x00 */ u8 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ GameOptions unk_04;
    /* 0x0C */ ModeSettings unk_0C[1];
    /* 0x14 */ char unk14[0x8];
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ u8 unk_1E;
    /* 0x1F */ u8 unk_1F;
    /* 0x20 */ char unk20[0x8];
} SaveOptionsRecord; // size = 0x28

typedef struct unk_D_800AE4E8_004_2_0DC0_002 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ char unk_04[11];
    /* 0x0F */ char unk_0F[11];
} unk_D_800AE4E8_004_2_0DC0_002; // size = 0x1A

typedef struct unk_D_800AE4E8_004_2_0DC0 {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ char unk001[0x1];
    /* 0x002 */ unk_D_800AE4E8_004_2_0DC0_002 unk_002[1];
    /* 0x01C */ char unk01C[0xF44];
} unk_D_800AE4E8_004_2_0DC0; // size = 0xF60

typedef struct ContinueRecordBlock {
    /* 0x000 */ u8 unk_000;
    /* 0x002 */ SessionContinueData unk_002;
    /* 0x022 */ s16 unk_022;
    /* 0x024 */ GbPokemonNamedRecord unk_024[6];
    /* 0x16E */ u8 unk_16E[6];
    /* 0x174 */ u8 unk_174[6];
    /* 0x17A */ char unk17A[0x6];
} ContinueRecordBlock; // size = 0x180

typedef struct unk_D_800AE4E8_004_2_1EC8_0002 {
    /* 0x00 */ char unk00[0x8C];
} unk_D_800AE4E8_004_2_1EC8_0002; // size = 0x8C

typedef struct unk_D_800AE4E8_004_2_1EC8 {
    /* 0x0000 */ u8 unk_0000;
    /* 0x0001 */ char unk0001[0x1];
    /* 0x0002 */ unk_D_800AE4E8_004_2_1EC8_0002 unk_0002[1];
    /* 0x008E */ char unk008E[0x132A];
} unk_D_800AE4E8_004_2_1EC8; // size = 0x13B8

typedef struct unk_D_800AE4E8_004_2_3280 {
    /* 0x0000 */ u8 unk_0000;
    /* 0x0001 */ char unk0001[0x1];
    /* 0x0002 */ unk_D_800AE4E8_004_2_1EC8_0002 unk_0002[1];
    /* 0x008E */ char unk008E[0xAF6];
} unk_D_800AE4E8_004_2_3280; // size = 0xB84

typedef struct unk_D_800AE4E8_004_2 {
    /* 0x0000 */ char unk0000[0xDC0];
    /* 0x0DC0 */ unk_D_800AE4E8_004_2_0DC0 unk_0DC0;
    /* 0x1D20 */ ContinueRecordBlock unk_1D20;
    /* 0x1EA0 */ SaveOptionsRecord unk_1EA0;
    /* 0x1EC8 */ unk_D_800AE4E8_004_2_1EC8 unk_1EC8;
    /* 0x3280 */ unk_D_800AE4E8_004_2_3280 unk_3280;
    /* 0x3E04 */ char unk3E04[0x17C];
} unk_D_800AE4E8_004_2; // size = 0x3F80

typedef struct unk_D_800AE4E8_004_3_0000 {
    /* 0x0000 */ DeckRecordHeader unk_000;
    /* 0x0010 */ GbPokemonNamedRecord unk_010[1];
    /* 0x0047 */ char unk010[0x421];
} unk_D_800AE4E8_004_3_0000; // size = 0x468

typedef struct unk_D_800AE4E8_004_3_34E0_010 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
} unk_D_800AE4E8_004_3_34E0_010; // size = 0x2

typedef struct unk_D_800AE4E8_004_3_34E0 {
    /* 0x0000 */ DeckRecordHeader unk_00;
    /* 0x0000 */ unk_D_800AE4E8_004_3_34E0_010 unk_10[1];
    /* 0x0012 */ char unk12[0xCE];
} unk_D_800AE4E8_004_3_34E0; // size = 0xE0

typedef struct unk_D_800AE4E8_004_3 {
    /* 0x0000 */ unk_D_800AE4E8_004_3_0000 unk_0000[12];
    /* 0x34E0 */ unk_D_800AE4E8_004_3_34E0 unk_34E0[4];
    /* 0x3860 */ char unk_3860[0x20];
} unk_D_800AE4E8_004_3; // size = 0x3880

typedef union unk_D_800AE4E8_004 {
    RegisteredTeamBank* unk1;
    unk_D_800AE4E8_004_2* unk2;
    unk_D_800AE4E8_004_3* unk3;
} unk_D_800AE4E8_004;

typedef struct SaveBank {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_D_800AE4E8_004 unk_04;
    /* 0x08 */ unk_D_800AE4E8_004 unk_08;
} SaveBank; // size = 0xC

void Save_ResetBank(UNUSED MainPoolBlock* arg0, u32 arg1);
u16 Save_Checksum(u8* arg0, s32 arg1);
s32 Save_RecordIsValid(u8* arg0, s32 arg1);
void Save_WriteFooter(u8* arg0, s32 arg1, s32 arg2);
void Save_WriteRecord(u8* arg0, u8* arg1, s32 arg2, s32 arg3);
void Save_CommitRecord(u8* arg0, s32 arg1, s32 arg2);
void Save_InvalidateRecord(u8* arg0, s32 arg1, s32 arg2);
void Save_RestoreRecord(u8* arg0, s32 arg1, s32 arg2);
void Save_ClearRecord(u8* arg0, s32 arg1, s32 arg2);
void Save_LoadWithRepair(s32 arg0, s32 arg1);
void GbSave_LoadBattleMonRecord(BattleMon* arg0, GbPokemonNamedRecord* arg1);
void GbSave_SaveBattleMonRecord(BattleMon* arg0, GbPokemonNamedRecord* arg1);
s32 Save_IsTypedRecordFlagSet(s32 arg0, s32 arg1, s16 arg2);
void Save_MarkRecordDirty(s32 arg0, s32 arg1, s16 arg2);
void func_8002667C(void);
void Save_CommitTypedRecord(s32 arg0, s32 arg1);
void Save_InvalidateTypedRecord(s32 arg0, s32 arg1);
void Save_RestoreTypedRecord(s32 arg0, s32 arg1);
void Save_ClearTypedRecord(s32 arg0, s32 arg1);
void Save_CommitBankRecords(s16 arg0);
void Save_CommitAllBankRecords(void);
void Save_ResetAndCommitTypedRecord(s32 arg0, s32 arg1);
s32 Deck_GetSaveRecordCapacity(s32 arg0);
s32 Deck_GetSaveRecordSize(s32 arg0);
s32 Deck_IsSaveEntryPresent(s32 arg0, s32 arg1);
s32 Deck_GetSaveEntryTrainerId(s32 arg0, s32 arg1);
char* Deck_GetSaveEntryName(s32 arg0, s32 arg1, char* arg2);
void Deck_GetSaveEntryNameWrapper(s32 arg0, s32 arg1, char* arg2);
void Deck_SetSaveEntryTrainerIdAndName(s32 arg0, s32 arg1, s32 arg2, char* arg3, u16 arg4);
s16 Deck_GetSaveEntryCount(s32 arg0, s32 arg1);
void Deck_SetSaveEntryCount(s32 arg0, s32 arg1, s32 arg2);
void Deck_IncrementSaveEntryCount(s32 arg0, s32 arg1);
s32 Deck_ReadSaveEntry(s32 arg0, s32 arg1, s32 arg2, void* arg3);
s32 Save_WriteTypedRecord(s32 arg0, s32 arg1, s32 arg2, void* arg3);
void Save_GetOptions(GameOptions* options);
void Save_SetOptions(GameOptions* arg0);
void Save_GetModeSettings(ModeSettings* settings, s16 round_index);
void Save_SetModeSettings(ModeSettings* arg0, s16 arg1);
void Save_GetOptionsField02(u16* arg0);
void Save_SetOptionsField02(u16* arg0);
s32 Save_GetOptionsField1E(void);
void Save_SetOptionsField1E(u8 arg0);
s32 Save_GetOptionsField1F(void);
void Save_SetOptionsField1F(u8 arg0);
s32 Save_GetSelectedPokemonId(void);
void Save_SetSelectedPokemonId(u8 arg0, u8 arg1);
void Session_SaveContinueRecord(SessionContinueData* arg0, BattleMon* arg1, s32 arg2);
s32 Session_LoadContinueRecord(SessionContinueData* arg0, BattleMon* arg1);
s32 Save_ContinueRecordExists(void);
s32 Save_FlushBank(s16 arg0);
s32 Save_FlushDirtyBanks(void);
s32 Save_AllocateBank(s16 arg0, u32 arg1);
void Save_InitializeBank0(void);
void Save_InitializeBank1(void);
void Save_InitializeBank2(void);
void Save_InitializeBank3(void);
s32 Save_EnsureBankLoaded(s16 arg0);
void Save_EnsureAllBanksLoaded(void);
void Save_EnsureBank3Loaded(void);
s32 Save_SetActiveRecordBank(s16 arg0);
s32 RegisteredTeam_ReadSlot(RegisteredTeamSlot* arg0, s32 arg1);
s32 RegisteredTeam_WriteSlot(RegisteredTeamSlot* arg0, s32 arg1);
s32 Deck_FindFirstFreeTeamSlot(void);
void Deck_CompactRegisteredTeams(void);

#endif // _26820_H_
