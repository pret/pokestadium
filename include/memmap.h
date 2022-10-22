#ifndef _MEMMAP_H_
#define _MEMMAP_H_

struct MemoryMap {
    uintptr_t vaddr;
    size_t size;
};

// these are probably .bss symbols in memmap.c, but until I have more
// of bss mapped, not 100% sure if they go in that file. TODO: Migrate
extern struct MemoryMap gSegments[16];
extern struct MemoryMap gFragments[240];

/* MIPS Relocation Types */
#define R_MIPS_32 2
#define R_MIPS_26 4
#define R_MIPS_HI16 5
#define R_MIPS_LO16 6

struct RelocTable {
    /* 0x00 */ u32 nRelocations;
    /* 0x04 */ u32 relocations[]; // variable size
};

struct Fragment {
    u32 ep1, ep2;    // MIPS instructions to jump to the main function,
                     // typically something like "j 0x8xx00020; nop"
    char str[8];     // "FRAGMENT"
    u32 entrypoint;  // typically 0x20
    u32 relocOffset; // relocOffset
    u32 sizeInRom;
    u32 sizeInRam;
    char data[]; // variable size
};

void Memmap_SetSegmentMap(u32 id, uintptr_t vaddr, u32 size);
uintptr_t Memmap_GetSegmentBaseVaddr(u32 id);
uintptr_t Memmap_GetSegmentVaddr(u32 mask);
u32 Memmap_GetSegmentVaddrMask(u32 i, uintptr_t addr);
void Memmap_ClearSegmentMemmap(u32 id);
void Memmap_SetSegments(Gfx** gfxDl);
void Memmap_RelocateFragment(u32 id, struct Fragment* fragment);
void Memmap_SetFragmentMap(u32 id, uintptr_t vaddr, u32 size);
uintptr_t Memmap_GetFragmentBaseVaddr(u32 id);
uintptr_t Memmap_GetFragmentVaddr(u32 mask);
u32 Memmap_GetFragmentVaddrMask(u32 i, uintptr_t addr);
void Memmap_ClearFragmentMemmap(u32 id);
uintptr_t Memmap_GetLoadedFragmentVaddr(uintptr_t addr);

#endif // _MEMMAP_H_
