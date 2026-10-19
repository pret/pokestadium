#ifndef _22630_H_
#define _22630_H_

#include "global.h"
#include "memory.h"
#include "game_state.h"
#include "table_view.h"

#define STAT_HP 1
#define STAT_SPECIAL 2
#define STAT_SPEED 3
#define STAT_DEFENSE 4
#define STAT_ATTACK 5

// Shifted, one-based view used by gBaseStats. Its named stat fields and
// unk_13 address the same bytes as SpeciesData's stats and growthRate.
typedef struct PokemonStats {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 baseHP;
    /* 0x07 */ u8 baseSpecial;
    /* 0x08 */ u8 baseSpeed;
    /* 0x09 */ u8 baseDefense;
    /* 0x0A */ u8 baseAttack;
    /* 0x0B */ char unk0B[0x4];
    /* 0x0F */ u8 unk_0F[1];
    /* 0x10 */ char unk10[0x3];
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ char unk14[0x3];
} PokemonStats; // size = 0x17

// Red/Blue base data without the sprite dimensions and sprite pointers.
typedef struct SpeciesData {
    /* 0x00 */ u8 speciesId;
    /* 0x01 */ u8 baseHitPoints;
    /* 0x02 */ u8 baseAttack;
    /* 0x03 */ u8 baseDefense;
    /* 0x04 */ u8 baseSpeed;
    /* 0x05 */ u8 baseSpecial;
    /* 0x06 */ u8 type1;
    /* 0x07 */ u8 type2;
    /* 0x08 */ u8 catchRate;
    /* 0x09 */ u8 baseExperience;
    /* 0x0A */ u8 startingMoves[4];
    /* 0x0E */ u8 growthRate;
    /* 0x0F */ u8 tmHmLearnset[7]; // TM01-TM50, then HM01-HM05, least-significant bit first.
    /* 0x16 */ u8 padding;
} SpeciesData; // size = 0x17

extern PokemonStats gBaseStats[];
// Indexed by species ID - 1: Bulbasaur through Mew, then the Substitute doll.
extern SpeciesData gSpeciesData[152];

typedef struct unk_D_80071D88 {
    /* 0x00 */ char* type_name;
    /* 0x04 */ Color_RGBA8 color;
} unk_D_80071D88; // size = 0x8
extern unk_D_80071D88 D_80071D88[];

typedef struct GbPokemonRecord {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01[2];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08[4];
    /* 0x0C */ u8 unk_0C[2];
    /* 0x0E */ u8 unk_0E[3];
    /* 0x11 */ u8 unk_11[2];
    /* 0x13 */ u8 unk_13[2];
    /* 0x15 */ u8 unk_15[2];
    /* 0x17 */ u8 unk_17[2];
    /* 0x19 */ u8 unk_19[2];
    /* 0x1B */ u8 unk_1B[2];
    /* 0x1D */ u8 unk_1D[4];
} GbPokemonRecord; // size = 0x21

typedef struct GbPokemonNamedRecord {
    /* 0x00 */ GbPokemonRecord unk_00;
    /* 0x21 */ u8 unk_21[11];
    /* 0x2C */ u8 unk_2C[11];
} GbPokemonNamedRecord; // size = 0x37

typedef struct GbPokemonRecordExt {
    /* 0x00 */ GbPokemonRecord unk_00;
    /* 0x21 */ u8 unk_21;
    // Big-endian u16 stats, read and written with GbData_ReadU16BE/GbData_WriteU16BE. Byte arrays
    // keep the record unaligned: the Japanese GbSaveParty places it at odd offsets.
    /* 0x22 */ u8 unk_22[2];
    /* 0x24 */ u8 unk_24[2];
    /* 0x26 */ u8 unk_26[2];
    /* 0x28 */ u8 unk_28[2];
    /* 0x2A */ u8 unk_2A[2];
} GbPokemonRecordExt; // size = 0x2C

typedef struct DeckHandle {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} DeckHandle; // size = 0xC

#if defined(VERSION_JP)
// Japanese Red/Green save layout. Names are 6 bytes, a box holds 30 Pokemon (0x566 bytes) and
// a box bank holds 4 boxes. Offsets come from the JP pokemon_stats code in gb_data.c:
// GbSave_ReadMainData reads 0x1020 bytes from SRAM 0x2580 and checks the checksum byte at
// 0x1014, GbSave_ReadBoxBank reads 0x15A0 bytes per bank and GbSave_GetBoxEntry indexes boxes
// in 0x566-byte steps.
//@src/pokemon_stats.c
typedef struct GbSaveParty {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001[1];
    /* 0x002 */ char unk002[6];
    /* 0x008 */ GbPokemonRecordExt unk_008[6];
    /* 0x110 */ char unk_110[6][6];
    /* 0x134 */ char unk_134[6][6];
} GbSaveParty; // size = 0x158

typedef struct GbSaveBoxEntry {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001[1];
    /* 0x002 */ char unk002[0x6];
} GbSaveBoxEntry; // size = 0x8

typedef struct GbSaveCurrentBox {
    /* 0x000 */ GbSaveBoxEntry unk_000;
    /* 0x008 */ char unk008[0x18];
    /* 0x020 */ GbPokemonRecord unk_020[1];
    /* 0x041 */ char unk041[0x3BD];
    /* 0x3FE */ char unk_3FE[1][6];
    /* 0x404 */ char unk404[0xAE];
    /* 0x4B2 */ char unk_4B2[1][6];
} GbSaveCurrentBox; // size >= 0x4B8

typedef struct GbSaveChecksumBlock {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ u8 unk_14;
    /* 0x15 */ char unk15[0xB];
} GbSaveChecksumBlock; // size = 0x20

typedef struct GbSaveMainData {
    /* 0x000 */ u8 unk_000[1];
    /* 0x001 */ char unk001[0x17];
    /* 0x018 */ u8 unk_018[6];
    /* 0x01E */ u8 unk_01E[1];
    /* 0x01F */ char unk01F[0x12];
    /* 0x031 */ u8 unk_031[1];
    /* 0x032 */ char unk032[0x12];
    /* 0x044 */ u8 unk_044;
    /* 0x045 */ BattleMonSpecies unk_045[1];
    /* 0x047 */ char unk047[0x2A];
    /* 0x071 */ u8 unk_071;
    /* 0x072 */ char unk072[0x9];
    /* 0x07B */ u8 unk_07B;
    /* 0x07C */ char unk07C[0x4];
    /* 0x080 */ u8 unk_080;
    /* 0x081 */ char unk081[0x1DB];
    /* 0x25C */ u8 unk_25C;
    /* 0x25D */ BattleMonSpecies unk_25D[1];
    /* 0x25F */ char unk25F[0x63];
    /* 0x2C2 */ s8 unk_2C2;
    /* 0x2C3 */ char unk2C3[0x174];
    /* 0x437 */ u8 unk_437;
    /* 0x438 */ char unk438[0x35];
    /* 0x46D */ s8 unk_46D;
    /* 0x46E */ char unk46E[0xA5];
    /* 0x513 */ s8 unk_513;
    /* 0x514 */ char unk514[0x441];
    /* 0x955 */ GbSaveParty unk_955;
    /* 0xAAD */ GbSaveCurrentBox unk_AAD;
    /* 0xF65 */ char unkF65[0x9B];
    /* 0x1000 */ GbSaveChecksumBlock unk_1000;
} GbSaveMainData; // size = 0x1020

typedef struct GbSaveBoxPair {
    /* 0x000 */ GbSaveBoxEntry unk_000;
    /* 0x008 */ GbSaveBoxEntry unk_008;
    /* 0x010 */ char unk010[0x556];
} GbSaveBoxPair; // size = 0x566

typedef struct GbSaveBoxBank {
    /* 0x0000 */ GbSaveBoxPair unk_0000[4];
    /* 0x1598 */ char unk1598[0x8];
} GbSaveBoxBank; // size = 0x15A0

typedef struct GbSaveBoxData {
    /* 0x0000 */ GbSaveBoxBank unk_0000[2];
} GbSaveBoxData; // size = 0x2B40
#else
typedef struct GbSaveParty {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001[1];
    /* 0x002 */ char unk002[6];
    /* 0x008 */ GbPokemonRecordExt unk_008[6];
    /* 0x110 */ char unk_110[6][11];
    /* 0x152 */ char unk_152[6][11];
} GbSaveParty; // size = 0x194

typedef struct GbSaveBoxEntry {
    /* 0x000 */ u8 unk_000;
    /* 0x000 */ u8 unk_001[1];
    /* 0x002 */ char unk002[0x12];
} GbSaveBoxEntry; // size = 0x14

typedef struct GbSaveCurrentBox {
    /* 0x000 */ GbSaveBoxEntry unk_000;
    /* 0x014 */ char unk014[0x2];
    /* 0x016 */ GbPokemonRecord unk_016[1];
    /* 0x037 */ char unk037[0x273];
    /* 0x2AA */ char unk_2AA[1][11];
    /* 0x2B5 */ char unk2B5[0xD1];
    /* 0x386 */ char unk_386[1][11];
} GbSaveCurrentBox; // size >= 0x391

typedef struct GbSaveChecksumBlock {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0x1];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ char unk04[0x1C];
} GbSaveChecksumBlock; // size = 0x20

typedef struct GbSaveMainData {
    /* 0x000 */ u8 unk_000[1];
    /* 0x001 */ char unk001[0x17];
    /* 0x018 */ u8 unk_018[11];
    /* 0x023 */ u8 unk_023[1];
    /* 0x024 */ char unk024[0x12];
    /* 0x036 */ u8 unk_036[1];
    /* 0x037 */ char unk037[0x12];
    /* 0x049 */ u8 unk_049;
    /* 0x04A */ BattleMonSpecies unk_04A[1];
    /* 0x04C */ char unk04C[0x2A];
    /* 0x076 */ u8 unk_076;
    /* 0x077 */ char unk077[0xE];
    /* 0x085 */ u8 unk_085;
    /* 0x086 */ char unk086[0x4];
    /* 0x08A */ u8 unk_08A;
    /* 0x08B */ char unk08B[0x1DB];
    /* 0x266 */ u8 unk_266;
    /* 0x267 */ BattleMonSpecies unk_267[1];
    /* 0x269 */ char unk269[0x63];
    /* 0x2CC */ s8 unk_2CC;
    /* 0x2CD */ char unk2CD[0x174];
    /* 0x441 */ u8 unk_441;
    /* 0x442 */ char unk442[0x35];
    /* 0x477 */ s8 unk_477;
    /* 0x478 */ char unk478[0xA5];
    /* 0x51D */ s8 unk_51D;
    /* 0x51E */ char unk51E[0x48E];
    /* 0x9AC */ GbSaveParty unk_9AC;
    /* 0xB40 */ GbSaveCurrentBox unk_B40;
    /* 0xED1 */ char unkED1[0xCF];
    /* 0xFA0 */ GbSaveChecksumBlock unk_FA0;
} GbSaveMainData; // size = 0xFC0

typedef struct GbSaveBoxPair {
    /* 0x000 */ GbSaveBoxEntry unk_000;
    /* 0x000 */ GbSaveBoxEntry unk_014;
    /* 0x028 */ char unk028[0x43A];
} GbSaveBoxPair; // size = 0x462

typedef struct GbSaveBoxBank {
    /* 0x0000 */ GbSaveBoxPair unk_0000[6];
    /* 0x1A4C */ char unk1A4C[0x14];
} GbSaveBoxBank; // size = 0x1A60

typedef struct GbSaveBoxData {
    /* 0x0000 */ GbSaveBoxBank unk_0000[2];
} GbSaveBoxData; // size = 0x34C0
#endif

#if defined(VERSION_JP)
// The JP GbSave_RefreshPlayerIdentity copies a 6-byte trainer name (_bcopy size 6) to 0x42 and
// GbSave_CopyPlayerIdentity copies one 8-byte word, so the identity block is 8 bytes.
typedef struct GbSavePlayerIdentity {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[6];
} GbSavePlayerIdentity; // size = 0x8
#else
typedef struct GbSavePlayerIdentity {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[11];
    /* 0x0D */ u8 unk_0D[2];
    /* 0x0F */ char unkF[0x1];
} GbSavePlayerIdentity; // size = 0x10
#endif

#if defined(VERSION_JP)
typedef struct GbSavePort {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06[0x13];
    /* 0x19 */ u8 unk_19[0x20];
    /* 0x39 */ char unk39[0x7];
    /* 0x40 */ GbSavePlayerIdentity unk_40;
    /* 0x48 */ GbSaveMainData* unk_48;
    /* 0x4C */ GbSaveBoxData* unk_4C;
} GbSavePort; // size = 0x50
#else
typedef struct GbSavePort {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06[0x13];
    /* 0x19 */ u8 unk_19[0x20];
    /* 0x39 */ char unk39[0x7];
    /* 0x40 */ GbSavePlayerIdentity unk_40;
    /* 0x50 */ GbSaveMainData* unk_50;
    /* 0x54 */ GbSaveBoxData* unk_54;
} GbSavePort; // size = 0x58
#endif

u16 GbData_ReadU16BE(u8* arg0);
u32 GbData_ReadU24BE(u8* arg0);
void GbData_WriteU16BE(u8* arg0, s32 arg1);
void GbData_WriteU24BE(u8* arg0, s32 arg1);
char* Text_UntranscodeName(char* arg0, char* arg1);
void Text_UntranscodeNameWrapper(char* arg0, char* arg1);
char* Text_TranscodeName(char* arg0, char* arg1);
char* Text_TranscodeNameWrapper(char* arg0, char* arg1);
char* Text_UntranscodeFixedName(char* arg0, char* arg1);
#if defined(VERSION_JP)
s8* Text_CopyString(s8* arg0, s8* arg1);
#else
char* Text_CopyString(char* arg0, char* arg1);
#endif
char* Text_CopySpeciesName(char* arg0, s32 arg1);
char* Text_GetTmHmName(s32 arg0, char* arg1);
void Pokemon_FromGbRecord(BattleMon* arg0, GbPokemonRecord* arg1);
void Pokemon_FromGbRecordExt(BattleMon* arg0, GbPokemonRecordExt* arg1);
void Pokemon_ToGbRecord(BattleMon* arg0, GbPokemonRecord* arg1);
void Pokemon_ToGbRecordExt(unk_func_88205880_00D0* arg0, GbPokemonRecordExt* arg1);
u16 StatExpSqrt(u16 arg0);
void func_800220C4(void);
u16 func_800220CC(s32 arg0, u16 arg1);
u32 CalculateStatValue(s32 statId, s32 speciesId, u16 statModifier, u16 level, u16 dvBits);
void Pokemon_RecalcStats(BattleMon* arg0);
u16 Pokemon_StatExpForTarget(s32 arg0, s32 arg1, u16 arg2, u16 arg3, u16 arg4);
u32 Pokemon_ExpForLevel(s32 arg0, u16 arg1);

#endif // _6BC0_H_
