#ifndef _232C0_H_
#define _232C0_H_

#include "global.h"
#include "memory.h"
#include "game_state.h"
#include "table_view.h"
#include "gb_data.h"

typedef enum {
    POKEMON_ROM_NONE = 0,
    POKEMON_ROM_RED = 1,
    POKEMON_ROM_GREEN = 2,
    POKEMON_ROM_BLUE = 3,
    POKEMON_ROM_YELLOW = 7,
} PokemonRomType;

typedef struct GbSavePortSnapshot {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001;
    /* 0x002 */ u16 unk_002;
#if defined(VERSION_JP)
    // GbSave_CopyPortSnapshot copies the 6-byte trainer name and then the 0x158-byte party.
    /* 0x004 */ char unk_004[6];
    /* 0x00A */ GbSaveParty unk_00A;
} GbSavePortSnapshot; // size = 0x162
#else
    /* 0x004 */ char unk_004[11];
    /* 0x00F */ GbSaveParty unk_00F;
} GbSavePortSnapshot; // size >= 0x1A3
#endif

typedef struct unk_func_800228F0 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ char unk_04[16];
    /* 0x14 */ char unk_14[16];
} unk_func_800228F0; // size >= 0x28

u16 Pokemon_LevelFromExp(s32 arg0, u32 arg1);
void Pokemon_PrepareBattleMon(BattleMon* arg0);
void Pokemon_SetDisplayNameFromOt(BattleMon* arg0);
s32 VictoryPalace_LoadSpeciesRecord(unk_func_800228F0*, u16);
void VictoryPalace_SaveSpeciesRecord(BattleMon* arg0, s16 arg1, u8 arg2);
s32 GbSave_PlayerIdentityMatches(u16* arg0, GbSavePlayerIdentity* arg1);
u8 Move_GetIdFromTableIndex(s32 tm_hm_index);
u8 Species_ToInternalIndex(s32 arg0);
s32 Species_FromInternalIndex(s32 arg0);
u8 func_80022A88(s32 arg0);
u8 func_80022A98(s32 arg0);
s32 func_80022AA8(s32 arg0);
s32 func_80022ACC(s32 arg0);
void Deck_InitializeSaveBackend(DeckHandle* arg0);
void Deck_InitializeBoxBackend(DeckHandle* arg0);
DeckHandle* Deck_Open(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
DeckHandle* Deck_OpenAndSetName(s32 arg0, s32 arg1, s32 arg2, s32 arg3, char* arg4, u16 arg5);
s32 Deck_CloseAndFlushBox(DeckHandle* arg0);
s32 Deck_CloseAndFlush(DeckHandle* arg0);
s32 Deck_SetCursor(DeckHandle*, s32);
s32 Deck_ReadEntries(u8* arg0, s32 arg1, DeckHandle* arg2);
s32 Deck_WriteEntries(u8* arg0, s32 arg1, DeckHandle* arg2);
void Text_LoadPlayerLabels(void);
char* Text_GetPlayerLabel(s32 arg0);
s32 GbSave_HasPlayerNameMarker(u8* arg0);
s32 GbSave_VerifyChecksum(u8* arg0, u8* arg1);
void GbSave_ComputeChecksum(u8* arg0, u8* arg1);
s32 GbSave_VerifyWriteback(u8* arg0, s32 arg1);
s8 GbCart_IdentifyGame(s32 arg0);
s32 GbSave_CheckMainDataUnchanged(s32 arg0);
s32 GbSave_ReadMainData(s32 arg0);
s32 GbSave_InvalidateMainDataChecksum(s32 arg0);
s32 GbSave_ReadBoxBank(s32 arg0, s32 arg1);
s32 GbSave_WriteBoxBank(s32 arg0, s32 arg1);
void GbSave_ReleasePortBuffers(UNUSED MainPoolBlock* arg0, u32 arg1);
void GbSave_CheckLocationFlag(s32 arg0);
s32 GbSave_OpenMainData(s32 arg0);
s32 GbSave_EnsureMainDataLoaded(s32 arg0);
s32 GbSave_OpenBoxData(s32 arg0);
s32 GbSave_LoadPort(s32 arg0);
s32 GbSave_PollCartRemoval(s32 arg0);
void GbSave_RefreshPortState(s32 arg0);
void GbSave_ForceReloadPort(s32 arg0);
s32 GbSave_ScanAllPorts(void);
void GbSave_MarkBoxDataLoaded(s32 arg0);
s32 GbSave_WriteBoxBanks(s32 arg0);
s32 GbSave_CommitMainData(s32 arg0);
s32 GbSave_RebuildAndWriteSave(s32 arg0);
void GbSave_ValidateBeforeWrite(s32 arg0);
void GbSave_RequirePakPresent(s32 arg0);
GbSaveBoxEntry* GbSave_GetBoxEntry(s32 arg0, s32 arg1);
void GbSave_LoadMainPokemon(BattleMon* arg0, s32 arg1, s32 arg2);
void GbSave_SaveMainPokemon(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2);
void GbSave_LoadBoxPokemon(BattleMon* arg0, s32 arg1, s32 arg2, s32 arg3);
void GbSave_SaveBoxPokemon(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 GbSave_GetBoxEntryCount(s32 arg0, s32 arg1);
void GbSave_SetBoxEntryCount(s32 arg0, s32 arg1, s32 arg2);
s32 Deck_GetCapacity(s32 arg0);
s32 Deck_GetEntrySize(s32 arg0);
s32 Deck_GetCount(s32 arg0, s32 arg1, s32 arg2);
void Deck_DeleteEntry(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void Deck_AppendEntry(s32 arg0, s32 arg1, s32 arg2);
s32 Deck_ReadEntry(s32 arg0, s32 arg1, s32 arg2, s32 arg3, BattleMon* arg4);
s32 Deck_WriteEntry(s32 arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_88205880_00D0* arg4);
s32 GbSave_GetPresentPortMask(void);
s32 GbSave_GetSaveState(s32 arg0);
s32 GbSave_GetPortAvailability(s32 arg0);
s32 GbSave_GetPortGame(s32 arg0);
s32 GbSave_GetPartyCount(s32 arg0);
s32 GbSave_RefreshPlayerIdentity(s32 arg0);
void GbSave_CopyPlayerIdentity(s32 arg0, GbSavePlayerIdentity* arg1);
s32 GbSave_GetTrainerId(s32 arg0);
void GbSave_SetTrainerId(s32 arg0, u16 arg1);
s32 GbSave_GetBoxCount(s32 arg0);
char* GbSave_GetPlayerName(s32 arg0, char* arg1);
char* GbSave_SetPlayerName(s32 arg0, char* arg1);
char* GbSave_GetSecondaryName(s32 arg0, char* arg1);
char* GbSave_SetSecondaryName(s32 arg0, char* arg1);
s32 GbSave_GetStarterChoice(s32 arg0);
s32 GbSave_SavedAtPokemonCenter(s32 arg0);
s32 GbSave_HasPokedex(s32 arg0);
s32 GbSave_HasProgressFlag1000(s32 arg0);
s32 GbSave_CopyPortSnapshot(s32 arg0, GbSavePortSnapshot* arg1);
void GbSave_MarkSeenBits(char* arg0, s32 arg1, u8* arg2);
void GbSave_RebuildSeenBitfield(s32 arg0);
s32 GbSave_GetSpeciesProgressLevel(s32 arg0, s32 arg1);
void GbSave_SetSeenOwnedBits(s32 arg0, s32 arg1, s32 arg2);
s32 GbSave_CountSpeciesProgressField036(s32 arg0);
s32 GbSave_CountSpeciesProgressField023(s32 arg0);
s32 GbSave_CountSpeciesProgressField06(s32 arg0);

#endif // _232C0_H_
