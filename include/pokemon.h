#ifndef _POKEMON_H_
#define _POKEMON_H_

#include "global.h"

// ----------------------------------------------------------------------------
// Species IDs
//
// The codebase uses 1-indexed species IDs throughout. ID 0 is reserved as
// "no species / invalid". The canonical Gen-1 range is 1..NATIONAL_DEX_COUNT.
//
// Several internal APIs (GetSpeciesType2, the moves/effects tables) accept a
// wider range up to SPECIES_EXTENDED_MAX to accommodate Pokemon Stadium-
// specific IDs beyond the national dex (glitch forms, event Pokemon, etc.).
// SPECIES_BLANK is the sentinel returned when a lookup fails or the input
// is out of range.
// ----------------------------------------------------------------------------

#define SPECIES_NONE            0       // invalid / unset / no Pokemon
#define NATIONAL_DEX_COUNT      151     // total Pokemon in Gen 1 national dex
#define SPECIES_BLANK           152     // out-of-range sentinel (returned on lookup failure)
#define SPECIES_EXTENDED_MAX    190     // upper bound of internal species ID range

// ----------------------------------------------------------------------------
// Move IDs
//
// The codebase uses 1-indexed move IDs throughout, matching the Gen-1
// national move list (165 moves total). ID 0 is reserved as "no move /
// invalid". MOVE_BOUNDARY (== MOVE_MAX_ID + 1) is the value used in range
// checks; e.g. func_8002ED40 rejects move IDs >= MOVE_BOUNDARY.
// ----------------------------------------------------------------------------

#define MOVE_NONE               0       // invalid / unset / no move
#define MOVE_COUNT              165     // total moves in the Gen-1 move list
#define MOVE_MAX_ID             165     // last valid move ID
#define MOVE_BOUNDARY           0xA6    // canonical "max + 1" sentinel used in range checks

// ----------------------------------------------------------------------------
// Pokemon Types
//
// Gen-1 type encoding (verified against D_80072B00 moves data — known move:
// move 89 Dig = type 4 = Ground, move 66 Submission = type 1 = Fighting, etc.).
// Type IDs are 0..14 in Gen-1.
//
// KNOWN_UNKNOWNS:
// - Move 2 (Karate Chop): Stadium data shows type=0 (Normal); canonical
//   Gen-1 says Fighting. May be Stadium retypes it, or move-list reorders.
// - Move 84 (Mega Drain): Stadium data shows type=0x17 (out of 0..14 range)
//   and PP=30; canonical Gen-1 says Grass / PP=15. Same uncertainty.
// ----------------------------------------------------------------------------

typedef enum PokemonType {
    TYPE_NORMAL    = 0,
    TYPE_FIGHTING  = 1,
    TYPE_FLYING    = 2,
    TYPE_POISON    = 3,
    TYPE_GROUND    = 4,
    TYPE_ROCK      = 5,
    TYPE_BUG       = 6,
    TYPE_GHOST     = 7,
    TYPE_FIRE      = 8,
    TYPE_WATER     = 9,
    TYPE_GRASS     = 10,
    TYPE_ELECTRIC  = 11,
    TYPE_PSYCHIC   = 12,
    TYPE_ICE       = 13,
    TYPE_DRAGON    = 14
} PokemonType;

// ----------------------------------------------------------------------------
// Item IDs
//
// Stadium's item encoding has three distinct ranges:
//
//   1..83     regular Gen-1 items (Master Ball, Potions, status healers,
//             evolution stones, badges, key items, fossils, etc.)
//             Looked up in gItemNames (gItemNames, post-rename) by index.
//   196..200  HM01..HM05 (Hidden Machines) — formatted as ひでんマシン%02d
//   201..254  TM01..TM54 (Technical Machines) — formatted as わざマシン%02d
//
// IDs 0, 84..195, and 255+ have no name mapping (fallback = gItemNames[6],
// which is '？？？？？' / placeholder).
//
// Stadium uses 54 TMs rather than Gen-1's 50 — TM51..TM54 (IDs 251..254)
// may be Stadium-specific or unused.
//
// KNOWN_UNKNOWNS:
// - TM01..TM50 in Stadium don't necessarily match Gen-1's canonical TM
//   ordering (move 249 = TM50 in Gen 1; Stadium may differ).
// ----------------------------------------------------------------------------

#define ITEM_NONE              0       // invalid / no item
#define ITEM_REGULAR_FIRST     1       // first regular item ID
#define ITEM_REGULAR_LAST      83      // last regular item ID (Potion variants etc.)
#define ITEM_REGULAR_COUNT     83      // number of regular items
#define ITEM_HM_FIRST          196     // HM01 — Hidden Machine
#define ITEM_HM_LAST           200     // HM05
#define ITEM_HM_COUNT          5
#define ITEM_TM_FIRST          201     // TM01 — Technical Machine
#define ITEM_TM_LAST           254     // TM54 (Stadium's range; Gen 1 has only 50)
#define ITEM_TM_COUNT          54

// ----------------------------------------------------------------------------
// Status conditions
//
// Gen-1 status encoding (inferred from the status-healer item IDs in
// gItemNames: item 11=どくけし/Antidote, 12=やけどなおし/Burn Heal,
// 13=こおりなおし/Ice Heal, 14=ねむけざまし/Awakening, 15=まひなおし/Parlyz
// Heal). The encoding matches the canonical Gen-1 status byte:
//
//   0 = STATUS_NONE      no status
//   1 = STATUS_SLEEP     prevents attacking; decrements per turn
//   2 = STATUS_POISON    HP loss per turn
//   3 = STATUS_BURN      HP loss per turn; halves Attack
//   4 = STATUS_FREEZE    prevents attacking until thawed
//   5 = STATUS_PARALYSIS 25% miss chance; halves Speed
//   6 = STATUS_TOXIC     PSN++ (Gen 2+; unlikely in Gen-1-only Stadium)
//   7 = STATUS_ANY       sentinel: any non-OK status (mask 0x07)
//
// KNOWN_UNKNOWNS:
// - The actual storage location of the status byte in battle structs
//   is unrenamed. Patterns that initially looked like status storage
//   (`unk_D_800FCB18.unk_15 & 7`, `temp_s6->unk_15` on 0x8/0x10/0x40)
//   turned out to be audio flags and critical-hit modifiers respectively.
//   The real status byte is buried in unrenamed `unk_*` fields on
//   `unk_D_843C5568` and related battle structs in src/fragments/62/.
//   A future batch needs deeper archaeology on fragment62_361050.c and
//   the unk_D_843C5568 struct (status apply, turn-end tick, sleep
//   counter) before STATUS_* can replace live `unk_NN` accesses.
// - Confirmation that Stadium uses 0..6 (not 0..5 or a different
//   range) is pending — item IDs 11-15 strongly suggest the standard
//   Gen-1 5 main statuses, but the actual value in the battle struct
//   hasn't been located yet.
// ----------------------------------------------------------------------------

typedef enum PokemonStatus {
    STATUS_NONE      = 0,
    STATUS_SLEEP     = 1,
    STATUS_POISON    = 2,
    STATUS_BURN      = 3,
    STATUS_FREEZE    = 4,
    STATUS_PARALYSIS = 5,
    STATUS_TOXIC     = 6
} PokemonStatus;

#define STATUS_ANY 7  // sentinel: any non-OK status (mask 0x07)

#endif