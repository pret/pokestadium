#ifndef _MACROS_H_
#define _MACROS_H_

#define true 1
#define false 0

// Avoid compiler warnings for unused variables
#ifdef __GNUC__
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif

#ifndef __sgi
#define GLOBAL_ASM(...)
#endif

#ifdef _LANGUAGE_C
#define HW_REG(reg, type) *(volatile type*)((reg) | 0xA0000000)
#endif

#define assert

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

#define SQ(x) ((x) * (x))
#define CB(x) ((x) * (x) * (x))

// cast thru uintptr_t for integer to pointer casts
#define INT2VOID(i) ((void *)(uintptr_t)(i))

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define ALIGN2(val) (((u32)(val) + 0x1) & ~0x1)
#define ALIGN4(val) (((val) + 0x3) & ~0x3)
#define ALIGN8(val) (((val) + 0x7) & ~0x7)
#define ALIGN16(val) (((val) + 0xFu) & ~0xFu)
#define ALIGN64(val) (((val) + 0x3F) & ~0x3F)

#define DECR(x) ((x) == 0 ? 0 : --(x))

//! checks min first
#define CLAMP(x, min, max) ((x) < (min) ? (min) : (x) > (max) ? (max) : (x))
//! checks max first
#define CLAMP_ALT(x, min, max) ((x) > (max) ? (max) : (x) < (min) ? (min) : (x))
#define CLAMP_MAX(x, max) ((x) > (max) ? (x) : (max))
#define CLAMP_MIN(x, min) ((x) < (min) ? (x) : (min))

#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define ABS_ALT(x) ((x) >= 0 ? (x) : -(x))

#define ABS_NORMALIZED(x) ((ABS_ALT((x)) < (0.000001f)) ? 0.0f : (x))

#define FRAGMENT_ID(fragment) ((((u32)fragment##_TEXT_START & 0x0FF00000) >> 0x14) - 0x10)
#define ASSET_ID(asset) (((u32)asset & 0x0F000000) >> 0x18)

#define FRAGMENT_LOAD(fragment) ( \
    func_80004454(FRAGMENT_ID(fragment), fragment##_ROM_START, fragment##_relocs_ROM_END) \
)

#define FRAGMENT_LOAD_AND_CALL(fragment, arg0, arg1) (\
    func_80029008(FRAGMENT_ID(fragment), fragment##_ROM_START, fragment##_relocs_ROM_END, arg0, arg1) \
)

#define FRAGMENT_LOAD_AND_CALL2(fragment, arg0, arg1) (\
    func_80029048(FRAGMENT_ID(fragment), fragment##_ROM_START, fragment##_relocs_ROM_END, arg0, arg1) \
)

#define ASSET_LOAD(vram, rom, arg0) (\
    func_80004258(ASSET_ID(vram), rom##_ROM_START, rom##_ROM_END, arg0) \
)

#define ASSET_LOAD2(rom, arg0, arg1) (\
    func_800044F4(rom##_ROM_START, rom##_ROM_END, arg0, arg1) \
)

#endif
