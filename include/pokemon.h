#ifndef _POKEMON_H_
#define _POKEMON_H_

#include "global.h"

// ----------------------------------------------------------------------------
// Species IDs
//
// The codebase uses 1-indexed species IDs throughout. ID 0 is reserved as
// "no species / invalid". The canonical Gen-1 range is 1..NATIONAL_DEX_COUNT.
//
// Several internal APIs (func_80022A60, the moves/effects tables) accept a
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

#endif