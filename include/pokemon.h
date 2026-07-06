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

#endif