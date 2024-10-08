#ifndef _MEMMAP_H_
#define _MEMMAP_H_

#ifdef M2C
#define RELOCATIONS_SIZE 1
#else
#define RELOCATIONS_SIZE
#endif

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
    /* 0x04 */ u32 relocations[RELOCATIONS_SIZE]; // variable size
};

typedef s32 (*FragmentEntry)(s32, s32);

typedef struct Fragment {
    /* 0x00 */ u32 inst[2];     // MIPS instructions to jump to the main function, typically something like "j 0x8xx00020; nop"
    /* 0x08 */ char magic[8];   // "FRAGMENT"
    /* 0x10 */ u32 headerSize;  // typically 0x20
    /* 0x14 */ u32 relocOffset; // relocOffset
    /* 0x18 */ u32 sizeInRom;
    /* 0x1C */ u32 sizeInRam;
    /* 0x20 */ char data[RELOCATIONS_SIZE]; // variable size
} Fragment;

void Memmap_SetSegmentMap(u32 id, uintptr_t vaddr, size_t size);
uintptr_t Memmap_GetSegmentBaseVaddr(u32 id);
uintptr_t Memmap_GetSegmentVaddr(u32 mask);
u32 Memmap_GetSegmentVaddrMask(u32 i, uintptr_t addr);
void Memmap_ClearSegmentMemmap(u32 id);
void Memmap_SetSegments(Gfx** gfxDl);
void Memmap_RelocateFragment(u32 id, struct Fragment* fragment);
void Memmap_SetFragmentMap(u32 id, uintptr_t vaddr, size_t size);
uintptr_t Memmap_GetFragmentBaseVaddr(u32 id);
uintptr_t Memmap_GetFragmentVaddr(u32 mask);
u32 Memmap_GetFragmentVaddrMask(u32 i, uintptr_t addr);
void Memmap_ClearFragmentMemmap(u32 id);
uintptr_t Memmap_GetLoadedFragmentVaddr(uintptr_t addr);

#endif // _MEMMAP_H_
