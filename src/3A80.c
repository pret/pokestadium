#include <ultra64.h>
#include "memmap.h"
#include "memory.h"

/**
 * Based on the context of this variable's usage, it appears to be intended to
 * be non-0 whenever the expansion RAM is in, however it is never initialized
 * properly. It seems to serve as whereever the new start of memory will be
 * located whenever plugged in, but its only functional with the debug profiler.
 * It will, however, allocate a much bigger pool if set to non-0.
 */
s32 gExpansionRAMStart = FALSE;

extern struct MainPool **gMainPool; // gMainPool

void func_80003860(void);
s32 func_80007A58(void);

/**
 * Convert any valid address to its virtual (KSEG0) counterpart.
 */
uintptr_t convert_addr_to_virt_addr(uintptr_t addr) {
    uintptr_t retaddr = 0x00000000; // any invalid cases are treated as NULL return.

    // convert physical (in installed memory range) to virtual.
    if (addr < (size_t) osMemSize) {
        retaddr = addr | 0x80000000;
    // convert segmented to virtual.
    } else if (addr < 0x10000000U) {
        retaddr = Memmap_GetSegmentVaddr(addr);
    // convert a fragment pre-relocated address to a post-relocated virtual address.
    } else if ((addr >= 0x81000000U) && (addr < 0x90000000U)) { // is the address in fragment space? convert it to its post-relocated address.
        retaddr = Memmap_GetFragmentVaddr(addr);
    // pass-through addresses that are already virtual (in installed memory range)
    } else if ((addr >= 0x80000000U) && (addr < (uintptr_t) (osMemSize + 0x80000000U))) {
        retaddr = addr;
    }

    return retaddr;
}

/*
 * Copy memory from one address to the other. (why is this function not in HAL_libc?)
 */
void HAL_Memcpy(u32* dest, u32* src, int size) {
    while (size --> 0) {
        *(dest++) = *(src++);
    }
}

void func_80002F58(void) {
    // wat? mem sizes are only ever 0x400000 or 0x800000. This check makes no sense.
    // Effectively, it checks if the expansion RAM is in. But why not just use all
    // of it, or at least do the correct check of osMemSize == 0x800000?
    if ((gExpansionRAMStart != 0) && ((u32) osMemSize > 0x600000U)) {
        main_pool_init(&gPool, POOL_END_6MB);
    } else {
        main_pool_init(&gPool, POOL_END_4MB);
        gExpansionRAMStart = 0;
    }
    func_80003860();
    gMainPool = mem_pool_try_init(0x10000, 0);
}

void *func_80002FDC(s32 size) {
    return mem_pool_alloc(gMainPool, size);
}

void func_80003004(void *arg0) {
    mem_pool_free(gMainPool, arg0);
}

void HAL_DrawRect(Gfx** dlist, s32 ulx, s32 lrx, u16 color) {
    s32 uly = 0xF;
    s32 lry = 0x11;
    Gfx *gfx = *dlist;

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

void func_8000310C(Gfx** dlist) {
    struct MainPool *pool = main_pool_get_pool();
    s32 temp_s1 = main_pool_get_available() - gExpansionRAMStart;

    if (temp_s1 >= 0) 
    {
        s32 base = 30;
        s32 sp48 = ((u32) ( K0_TO_PHYS(pool->start)) >> 15) + base;
        s32 sp44 = ((u32) ( K0_TO_PHYS(pool->listHeadL)) >> 15) + base;
        s32 sp40 = ((u32) ( K0_TO_PHYS(pool->listHeadR) - gExpansionRAMStart) >> 15) + base;
        s32 sp3C = ((u32) ( K0_TO_PHYS(pool->end) - gExpansionRAMStart) >> 15) + base;

        HAL_DrawRect(dlist, base, sp48, 0xFBCB);
        HAL_DrawRect(dlist, sp48, sp44, 0xFFCB);
        HAL_DrawRect(dlist, sp44, sp40, 0x2ABF);
        HAL_DrawRect(dlist, sp40, sp3C, 0xFFCB);
        HAL_Printf(base, 0x14, "MEM: +%XH (+%dK)",  temp_s1, temp_s1 / 1024);
    }
    else
    {
        s32 base = 30;
        s32 sp34 = ((u32) ( K0_TO_PHYS(pool->start)) >> 15) + base;
        s32 sp30 = ((u32) ( K0_TO_PHYS(pool->listHeadL)) >> 15) + base;
        s32 sp2C = ((u32) ( K0_TO_PHYS(pool->listHeadR) - gExpansionRAMStart) >> 15) + base;
        s32 sp28 = ((u32) ( K0_TO_PHYS(pool->end) - gExpansionRAMStart) >> 15) + base;
        HAL_DrawRect(dlist, base, sp34, 0xFBCB);
        HAL_DrawRect(dlist, sp34, sp2C, 0xFFCB);
        HAL_DrawRect(dlist, sp2C, sp30, 0xF94B);
        HAL_DrawRect(dlist, sp30, sp28, 0xFFCB);
        HAL_Printf(base, 0x14, "MEM: -%XH (-%dK)", -temp_s1, -temp_s1 / 1024);
    }
}

/*
 * Clear memory address area.
 */
void HAL_Memclear(u64* dest, u32 size) {
    while( size --> 0 ) {
        *(dest++) = -1;
    }
}

s32 func_80003348(u64* arg0)  {
    s32 ret = 0;

    while (*(arg0++) == 0x8040000080400000)
    {   
        ret++;
    }
    return ret * sizeof(*arg0);
}
