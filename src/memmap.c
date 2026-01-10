#include "global.h"
#include "memmap.h"

struct MemoryMap {
    uintptr_t vaddr;
    size_t size;
};

struct MemoryMap gSegments[16];
struct MemoryMap gFragments[240];

/*
 * Set the base virtual address and size of the specified segment memmap.
 */
void Memmap_SetSegmentMap(u32 id, uintptr_t vaddr, size_t size) {
    gSegments[id].vaddr = vaddr;
    gSegments[id].size = size;
}

/*
 * Return the base address of the specified segment number.
 */
uintptr_t Memmap_GetSegmentBaseVaddr(u32 id) {
    return gSegments[id].vaddr;
}

/*
 * Return the current virtual address of a given offset into a segment. This is
 * calculated based on the input bitmask constructed of the following values:
 *
 * Input: XYZZZZZZ
 * X: Safety nibble. Only process if 0.
 * Y: Segment number.
 * Z: Segment offset.
 */
uintptr_t Memmap_GetSegmentVaddr(u32 mask) {
    if ((mask >> 0x1C) == 0) {
        u32 id = (mask & 0x0F000000) >> 0x18;
        u32 value = (mask & 0x00FFFFFF) >> 0x00;
        if (gSegments[id].vaddr != NULL) {
            mask = gSegments[id].vaddr + value;
        }
    }
    return mask;
}

/*
 * Returns the input bitmask equivalent for Memmap_GetSegmentVaddr's input. This function
 * appears to be unused.
 */
u32 Memmap_GetSegmentVaddrMask(u32 i, uintptr_t addr) {
    struct MemoryMap* entry = &gSegments[i];
    size_t diff = addr - entry->vaddr;

    if (diff >= entry->size) {
        return 0;
    }
    return (i << 0x18) | diff;
}

/*
 * Clear the memmap for the segment ID specified.
 */
void Memmap_ClearSegmentMemmap(u32 id) {
    gSegments[id].vaddr = NULL;
    gSegments[id].size = 0;
}

/*
 * Initialize the 16 segments with the segment memmap virtual addresses for the
 * display list head.
 */
void Memmap_SetSegments(Gfx** gfxDl) {
    u32 i;
    Gfx* gfx = *gfxDl;

    for (i = 0; i < 16; i++) {
        gSPSegment(gfx++, i, osVirtualToPhysical((void*)gSegments[i].vaddr));
    }
    *gfxDl = gfx;
}

/*
 * Perform fragment relocation on a given Fragment.
 */
void Memmap_RelocateFragment(u32 id, struct Fragment* fragment) {
    u32 isLoNeg;
    u32* luiRefs[32];
    u32 luiVals[32];
    u32* luiInstRef;
    u32* relocDataP;
    u32 relocSize;
    struct RelocTable* relocInfo;
    UNUSED u32 relocOffset;
    u32 reloc;
    u32 temp_v0_5;
    u32 i;
    u32* regValP;
    UNUSED s32 pad;

    relocOffset = fragment->relocOffset;
    relocSize = fragment->sizeInRam - fragment->relocOffset;
    relocInfo = (struct RelocTable*)((uintptr_t)fragment->relocOffset + (uintptr_t)fragment);

    osInvalICache(fragment, fragment->sizeInRam);
    osInvalDCache(fragment, fragment->sizeInRam);
    Memmap_SetFragmentMap(id, (uintptr_t)fragment, fragment->sizeInRam);

    for (i = 0; i < relocInfo->nRelocations; i++) {
        reloc = relocInfo->relocations[i];
        relocDataP = (u32*)((reloc & 0xFFFFFF) + (uintptr_t)fragment);

        switch ((reloc & 0x7F000000) >> 24) {
            case R_MIPS_32:
                // Handles 32-bit address relocation, used for things such as jump tables and pointers in data.
                // Just relocate the full address.
                *relocDataP = Memmap_GetFragmentVaddr(*relocDataP);
                break;
            case R_MIPS_26:
                // Handles 26-bit address relocation, used for jumps and jals.
                // Extract the address from the target field of the J-type MIPS instruction.
                // Relocate the address and update the instruction.
                *relocDataP =
                    (((u32)(Memmap_GetFragmentVaddr(((*relocDataP * 4) & 0x0FFFFFFC) + 0x80000000) & 0x0FFFFFFF) >> 2) |
                     (*relocDataP & 0xFC000000));
                break;
            case R_MIPS_HI16:
                // Handles relocation for a hi/lo pair, part 1.
                // Store the reference to the LUI instruction (hi) using the `rt` register of the instruction.
                // This will be updated later in the `R_MIPS_LO16` section.
                luiRefs[(*relocDataP >> 0x10) & 0x1F] = relocDataP;
                luiVals[(*relocDataP >> 0x10) & 0x1F] = *relocDataP;
                break;
            case R_MIPS_LO16:
                // Handles relocation for a hi/lo pair, part 2.
                // Grab the stored LUI (hi) from the `R_MIPS_HI16` section using the `rs` register of the instruction.
                // The full address is calculated, relocated, and then used to update both the LUI and lo instructions.
                // If the lo part is negative, add 1 to the LUI value.
                // Note: The lo instruction is assumed to have a signed immediate.
                luiInstRef = luiRefs[(*relocDataP >> 0x15) & 0x1F];
                regValP = &luiVals[(*relocDataP >> 0x15) & 0x1F];

                temp_v0_5 = Memmap_GetFragmentVaddr((*regValP << 0x10) + (s16)*relocDataP);
                isLoNeg = (temp_v0_5 & 0x8000) ? 1 : 0;
                *luiInstRef = (u32)((*luiInstRef & 0xFFFF0000) | ((temp_v0_5 >> 16) + isLoNeg));
                *relocDataP = (u32)((*relocDataP & 0xFFFF0000) | (temp_v0_5 & 0xFFFF));
                break;
        }
    }
    if (relocSize != 0) {
        bzero((void*)((uintptr_t)fragment->relocOffset + (uintptr_t)fragment), relocSize);
    }
    osWritebackDCache(fragment, fragment->sizeInRam);
}

/*
 * Set the base virtual address and size of the specified fragment memmap.
 */
void Memmap_SetFragmentMap(u32 id, uintptr_t vaddr, size_t size) {
    gFragments[id].vaddr = vaddr;
    gFragments[id].size = size;
}

/*
 * Return the base vaddress of the fragment ID specified.
 */
uintptr_t Memmap_GetFragmentBaseVaddr(u32 id) {
    return gFragments[id].vaddr;
}

/*
 * Return the current virtual address of a given offset into a fragment. This is
 * calculated based on the input bitmask constructed of the following values:
 *
 * Input: XYYZZZZZ
 * X: Safety nibble. Only process if 0. This is handled by the address range check
 *    at the start.
 * Y: Fragment number.
 * Z: Fragment offset.
 */
uintptr_t Memmap_GetFragmentVaddr(void* addr) {
    if (((u32)addr >= 0x81000000U) && ((u32)addr < 0x90000000U)) {
        u32 id = (((u32)addr & 0x0FF00000) >> 0x14) - 0x10;
        u32 value = (((u32)addr & 0x000FFFFF));

        if (gFragments[id].vaddr != NULL) {
            addr = gFragments[id].vaddr + value;
        }
    }
    return (uintptr_t)addr;
}

/*
 * Returns the input bitmask equivalent for Memmap_GetFragmentVaddr's input. This function
 * appears to be unused.
 */
u32 Memmap_GetFragmentVaddrMask(u32 i, uintptr_t addr) {
    struct MemoryMap* entry = &gFragments[i];
    size_t diff = addr - entry->vaddr;

    if (diff >= entry->size) {
        return 0;
    }
    return ((i + 0x10) << 0x14) | 0x80000000 | diff;
}

/*
 * Clear the memmap for the fragment ID specified.
 */
void Memmap_ClearFragmentMemmap(u32 id) {
    gFragments[id].vaddr = NULL;
    gFragments[id].size = 0;
}

/*
 * Given a specified address, check to see if it is located inside of a fragment
 * currently loaded. Return a calculated address.
 */
uintptr_t Memmap_GetLoadedFragmentVaddr(uintptr_t addr) {
    struct MemoryMap* fraglist = gFragments;
    int i, UNUSED j;

    for (i = 0, fraglist = gFragments; i < 0xF0; i++, fraglist++) {
        if (addr >= fraglist->vaddr) {
            size_t diff = addr - fraglist->vaddr;
            if (diff < fraglist->size) {
                return ((i + 0x10) << 0x14) | 0x80000000 | diff;
            }
        }
    }
    return 0;
}
