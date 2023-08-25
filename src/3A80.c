#include <ultra64.h>
#include "memmap.h"
#include "intro_loader.h"

extern s32 D_80068B90;
extern u8 D_80104BB0[];
extern s32 D_800A60B0;

void func_80003860(void);
s32 func_80002A40(s32, s32);
void func_80002BD0(s32, void *); // type unknown
s32 func_80007A58(void);

uintptr_t func_80002E80(uintptr_t addr) {
    uintptr_t retaddr = 0x00000000;

    if (addr < (size_t) osMemSize) {
        retaddr = addr | 0x80000000;
    } else if (addr < 0x10000000U) {
        retaddr = Memmap_GetSegmentVaddr(addr);
    } else if ((addr >= 0x81000000U) && (addr < 0x90000000U)) { // is the address in fragment space? convert it to its post-relocated address.
        retaddr = Memmap_GetFragmentVaddr(addr);
    } else if ((addr >= 0x80000000U) && (addr < (uintptr_t) (osMemSize + 0x80000000U))) {
        retaddr = addr;
    }
    return retaddr;
}

// HAL memcpy?
void func_80002F28(u32* dest, u32* src, int size) {
    while (size --> 0) {
        *(dest++) = *(src++);
    }
}

void func_80002F58(void) {
    // wat? mem sizes are only ever 0x400000 or 0x800000. This check makes no sense.
    if ((D_80068B90 != 0) && ((u32) osMemSize > 0x600000U)) {
        func_800022C0(&D_80104BB0, 0x80600000);
    } else {
        func_800022C0(&D_80104BB0, 0x80400000);
        D_80068B90 = 0;
    }
    func_80003860();
    D_800A60B0 = func_80002A40(0x10000, 0);
}

void *func_80002FDC(s32 arg0) {
    return func_80002AF8(D_800A60B0, arg0);
}

void func_80003004(void *arg0) {
    func_80002BD0(D_800A60B0, arg0);
}

// HAL_DrawRect
void func_8000302C(Gfx** dlist, s32 ulx, s32 lrx, u16 color) {
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

void func_8000310C(Gfx** dlist) 
{
    struct Unk800A6070 * sp54 = func_80002A30();
    s32 temp_s1 = func_80002764() - D_80068B90;

    if (temp_s1 >= 0) 
    {
        u32 coord = 0x1E;
        s32 sp48 = ((u32) ( K0_TO_PHYS(sp54->unk20)) >> 0xF) + coord;
        s32 sp44 = ((u32) ( K0_TO_PHYS(sp54->unk28)) >> 0xF) + coord;
        s32 sp40 = ((u32) ( K0_TO_PHYS(sp54->unk2C) - D_80068B90) >> 0xF) + coord;
        s32 sp3C = ((u32) ( K0_TO_PHYS(sp54->unk24) - D_80068B90) >> 0xF) + coord;

        func_8000302C(dlist, coord, sp48, 0xFBCB);
        func_8000302C(dlist, sp48, sp44, 0xFFCB);
        func_8000302C(dlist, sp44, sp40, 0x2ABF);
        func_8000302C(dlist, sp40, sp3C, 0xFFCB);
        HAL_Printf(coord, 0x14, "MEM: +%XH (+%dK)",  temp_s1, temp_s1 / 1024);
    }
    else
    {
        u32 coord = 0x1E;
        s32 sp34 = ((u32) ( K0_TO_PHYS(sp54->unk20)) >> 0xF) + coord;
        s32 sp30 = ((u32) ( K0_TO_PHYS(sp54->unk28)) >> 0xF) + coord;
        s32 sp2C = ((u32) ( K0_TO_PHYS(sp54->unk2C) - D_80068B90) >> 0xF) + coord;
        s32 sp28 = ((u32) ( K0_TO_PHYS(sp54->unk24) - D_80068B90) >> 0xF) + coord;
        func_8000302C(dlist, coord, sp34, 0xFBCB);
        func_8000302C(dlist, sp34, sp2C, 0xFFCB);
        func_8000302C(dlist, sp2C, sp30, 0xF94B);
        func_8000302C(dlist, sp30, sp28, 0xFFCB);
        HAL_Printf(coord, 0x14, "MEM: -%XH (-%dK)", -temp_s1, -temp_s1 / 1024);
    }
}

void func_8000330C(u64 * dest, u32 arg1) {
    while( arg1 --> 0 ) {
        *(dest++) = -1;
    }
}

s32 func_80003348(u64* arg0) 
{
    s32 ret = 0;

    while (*(arg0++) == 0x8040000080400000)
    {   
        ret++;
    }
    return ret * sizeof(*arg0);
}
