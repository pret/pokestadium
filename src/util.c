#include <ultra64.h>
#include "memmap.h"
#include "memory.h"
#include "util.h"

/**
 * Based on the context of this variable's usage, it appears to be intended to
 * be non-0 whenever the expansion RAM is in, however it is never initialized
 * properly. It seems to serve as whereever the new start of memory will be
 * located whenever plugged in, but its only functional with the debug profiler.
 * It will, however, allocate a much bigger pool if set to non-0.
 */
u32 gExpansionRAMStart = FALSE;

extern struct MainPool** gMainPool; // gMainPool

void func_80003860(void);
s32 func_80007A58(void);

/**
 * Convert any valid address to its virtual (KSEG0) counterpart.
 */
uintptr_t Util_ConvertAddrToVirtAddr(uintptr_t addr) {
    uintptr_t retaddr = NULL; // any invalid cases are treated as NULL return.

    // convert physical (in installed memory range) to virtual.
    if (addr < osMemSize) {
        retaddr = addr | 0x80000000;
        // convert segmented to virtual.
    } else if (addr < 0x10000000U) {
        retaddr = Memmap_GetSegmentVaddr(addr);
        // convert a fragment pre-relocated address to a post-relocated virtual address.
    } else if ((addr >= 0x81000000U) &&
               (addr < 0x90000000U)) { // is the address in fragment space? convert it to its post-relocated address.
        retaddr = Memmap_GetFragmentVaddr(addr);
        // pass-through addresses that are already virtual (in installed memory range)
    } else if ((addr >= 0x80000000U) && (addr < (uintptr_t)(osMemSize + 0x80000000U))) {
        retaddr = addr;
    }

    return retaddr;
}

/**
 * Copy memory from one address to the other.
 */
void Util_Memcpy(u32* dest, u32* src, int size) {
    while (size-- > 0) {
        *(dest++) = *(src++);
    }
}

/**
 * Initialize the global memory pools and set the main pool after the
 * global pool.
 */
void Util_InitMainPools(void) {
    /**
     * wat? mem sizes are only ever 0x400000 or 0x800000. This check makes no sense
     * in normal contexts. However, since osGetMemSize checks each MB at a time, if
     * the 7MB check fails for whatever reason it can theoretically set osMemSize to
     * 0x600000. This is not known to occur in practical contexts, but there may be
     * some other unknown reason for this.
     */
    if ((gExpansionRAMStart > 0) && (osMemSize > 0x600000U)) {
        main_pool_init(&gPool, POOL_END_6MB);
    } else {
        main_pool_init(&gPool, POOL_END_4MB);
        gExpansionRAMStart = 0;
    }
    func_80003860();
    gMainPool = mem_pool_try_init(0x10000, 0);
}

/**
 * Allocate memory from the main pool.
 */
void* Util_Malloc(s32 size) {
    return mem_pool_alloc(gMainPool, size);
}

/**
 * Free a pointer being used in the main pool.
 */
void Util_Free(void* ptr) {
    mem_pool_free(gMainPool, ptr);
}

/**
 * Draws a profiler rectangle with given coordinates. Solely used by the next function
 * which facilitates the tacked on memory profiler.
 */
void Util_DrawRect(Gfx** dlist, s32 ulx, s32 lrx, u16 color) {
    s32 uly = 15;
    s32 lry = 17;
    Gfx* gfx = *dlist;

    if (func_80007A58() != 0) {
        ulx <<= 1;
        lrx <<= 1;
        uly <<= 1;
        lry <<= 1;
    }

    gDPPipeSync(gfx++);
    gDPSetFillColor(gfx++, color << 16 | color);
    gDPFillRectangle(gfx++, ulx, uly, lrx, lry);
    *dlist = gfx;
}

/**
 * Render the memory profiler bar and print the MEM display. For some reason, this
 * is not within profiler.c itself but added in this "util" file. This seems to be
 * tacked onto the profiler by HAL instead of EAD.
 */
void Util_DrawMemProfiler(Gfx** dlist) {
    struct MainPool* pool = main_pool_get_pool(); // get pool pointer
    /**
     * Get the available memory offset by gExpansionRAMStart variable. This variable is weird; it
     * seems to be used in reference to osMemSize checks >= 0x600000 which would only be true
     * in Expansion RAM contexts. However, this game does not use the expansion RAM in any
     * other context. This variable is negative when gExpansionRAMStart is too big, and not when
     * it isnt. It is therefore reasonable to assume that this variable would represent how much
     * memory is leftover and if negative would mean this cant fit into 4MB, which would therefore
     * mean that the developers need to trim more memory to get it to fit into 4MB.
     */
    s32 available = main_pool_get_available() - gExpansionRAMStart;

    if (available >= 0) {
        // calculate approximation coordinates based on the current pool addresses in order
        // to display them on the memory profiler.
        s32 baseX = 30;
        s32 startX = ((u32)(K0_TO_PHYS(pool->start)) >> 15) + baseX;
        s32 headLX = ((u32)(K0_TO_PHYS(pool->listHeadL)) >> 15) + baseX;
        s32 headRX = ((u32)(K0_TO_PHYS(pool->listHeadR) - gExpansionRAMStart) >> 15) + baseX;
        s32 endX = ((u32)(K0_TO_PHYS(pool->end) - gExpansionRAMStart) >> 15) + baseX;

        // draw the rects.
        Util_DrawRect(dlist, baseX, startX, GPACK_RGBA5551(248, 120, 40, 1));  // orange
        Util_DrawRect(dlist, startX, headLX, GPACK_RGBA5551(248, 248, 40, 1)); // yellow
        Util_DrawRect(dlist, headLX, headRX, GPACK_RGBA5551(40, 80, 248, 1));  // blue
        Util_DrawRect(dlist, headRX, endX, GPACK_RGBA5551(248, 248, 40, 1));   // yellow

        // how many bytes and kilobytes are available?
        HAL_Printf(baseX, 20, "MEM: +%XH (+%dK)", available, available / 1024);
    } else {
        // same as above.
        s32 baseX = 30;
        s32 startX = ((u32)(K0_TO_PHYS(pool->start)) >> 15) + baseX;
        s32 headLX = ((u32)(K0_TO_PHYS(pool->listHeadL)) >> 15) + baseX;
        s32 headRX = ((u32)(K0_TO_PHYS(pool->listHeadR) - gExpansionRAMStart) >> 15) + baseX;
        s32 endX = ((u32)(K0_TO_PHYS(pool->end) - gExpansionRAMStart) >> 15) + baseX;

        // draw the rects. if we are negative in the memory, we are using red for the backwards
        // allocations to indicate too much memory is being used.
        Util_DrawRect(dlist, baseX, startX, GPACK_RGBA5551(248, 120, 40, 1));  // orange
        Util_DrawRect(dlist, startX, headRX, GPACK_RGBA5551(248, 248, 40, 1)); // yellow
        Util_DrawRect(dlist, headRX, headLX, GPACK_RGBA5551(248, 40, 40, 1));  // red
        Util_DrawRect(dlist, headLX, endX, GPACK_RGBA5551(248, 248, 40, 1));   // yellow

        // how many bytes and kilobytes are available?
        HAL_Printf(baseX, 20, "MEM: -%XH (-%dK)", -available, -available / 1024);
    }
}

/**
 * Clear memory address area.
 */
void Util_Memclear(u64* dest, u32 size) {
    while (size-- > 0) {
        *(dest++) = -1;
    }
}

/**
 * Unused function for checking some 64-bit range (possibly some display list?) for values
 * cooresponding to 0x8040000080400000. This could have been for some memory test however
 * the code for such a test is not present in this ROM, so we can only guess this function's
 * intended usage.
 */
s32 Util_CheckStubMemArea(u64* ptr) {
    s32 ret = 0;

    while (*(ptr++) == 0x8040000080400000) {
        ret++;
    }
    return ret * sizeof(*ptr);
}
