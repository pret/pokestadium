#ifndef BATTLE_STATE_FLAGS_H
#define BATTLE_STATE_FLAGS_H

/*
 * ActivePokemonState.flags
 *
 * Presentation state, not the authoritative gameplay status.
 * Proposed names describe observed setters and consumers.
 * Keep the struct member u16.
 */
#define ACTIVE_SLEEP         0x0001 /* Sleep presentation active. */
#define ACTIVE_FREEZE        0x0002 /* Freeze presentation active. */
#define ACTIVE_AIR_SETTLE    0x0004 /* Pending height = 200 and airborne-state setup. */
#define ACTIVE_RETURN_RESET  0x0008 /* Two-turn-move return cleanup pending. */
#define ACTIVE_DIG_EMERGE    0x0010 /* Diglett/Dugtrio emergence presentation. */

/* 0x0020, 0x0040, 0x0080: unassigned. */

#define ACTIVE_HOLD_RENDER   0x0100 /* Repeatedly clears model render flag 0x20. */
#define ACTIVE_AIRBORNE      0x0200 /* Airborne presentation active. */
#define ACTIVE_AIR_ACTION    0x0400 /* Action started while airborne. */
#define ACTIVE_SUBSTITUTE    0x0800 /* Substitute presentation active. */
#define ACTIVE_SUB_BREAK     0x1000 /* Substitute break presentation pending. */

/* 0x2000: unassigned. */

#define ACTIVE_UNDERGROUND   0x4000 /* Underground/Dig presentation active. */

/* 0x8000: unassigned. */

/*
 * BattleMon.statusCondition
 *
 * Bits 0–2 hold a sleep counter, not independent status flags.
 * Toxic uses STATUS_POISON plus separate runtime state.
 * Fainting is not encoded as a status bit here.
 * Keep the struct member u8.
 */
#define STATUS_NONE          0x00
#define STATUS_SLEEP_MASK    0x07
#define STATUS_POISON        0x08
#define STATUS_BURN          0x10
#define STATUS_FREEZE        0x20
#define STATUS_PARALYSIS     0x40

/* 0x80: unassigned. */

#endif /* BATTLE_STATE_FLAGS_H */