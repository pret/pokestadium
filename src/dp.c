#include <ultra64.h>

typedef unsigned long uintptr_t;

struct UnkStruct800A5870 {
    u32 vaddr;
    u32 size;
};

extern struct UnkStruct800A5870 D_800A5870[16];
extern struct UnkStruct800A5870 D_800A58F0[60]; // might be 16 too

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

void func_800020B0(u32 id, u32 vaddr, u32 size);
u32 func_800020E0(u32 mask);

void func_80001CE0(s32 id, s32 vaddr, s32 size) {
    D_800A5870[id].vaddr = vaddr;
    D_800A5870[id].size  = size;
}

s32 func_80001CFC(s32 id) {
    return D_800A5870[id].vaddr;
}

// First nibble: A boolean. Process the set or something
// Second nibble: the ID of the array.
// Lower 24-bits: Contents
u32 func_80001D10(u32 mask) {
    if ((mask >> 0x1C) == 0) {
        u32 id    = (mask & 0x0F000000) >> 0x18;
        u32 value = (mask & 0x00FFFFFF) >> 0x00;
        if (D_800A5870[id].vaddr != 0) {
            mask = D_800A5870[id].vaddr + value;
        }
    }
    return mask;
}

s32 func_80001D60(u32 id, u32 arg1) {
    struct UnkStruct800A5870* entry = &D_800A5870[id];

    if ((arg1 - entry->vaddr) >= entry->size) {
        return 0;
    }
    return (id << 0x18) | (arg1 - entry->vaddr);
}

void func_80001D9C(s32 id) {
    D_800A5870[id].vaddr = 0;
    D_800A5870[id].size  = 0;
}

void func_80001DB8(Gfx** gfxDl) {
    s32 i;
    Gfx* gfx = *gfxDl;

    for(i = 0; i < 16; i++) {
        gSPSegment(gfx++, i, osVirtualToPhysical(D_800A5870[i].vaddr));
    }
    *gfxDl = gfx;
}

/*
 * Perform fragment relocation on a given Fragment.
 */
void Fragment_Relocate(u32 id, struct Fragment* fragment) {
    u32 isLoNeg;
    u32 *luiRefs[32];
    u32 luiVals[32];
    u32 *luiInstRef;
    u32 *relocDataP;
    u32 relocSize;
    struct RelocTable* relocInfo;
    u32 relocOffset;
    u32 reloc;
    u32 temp_v0_5;
    u32 i;
    u32 *regValP;
    s32 pad;

    relocOffset = fragment->relocOffset;
    relocSize = fragment->sizeInRam - fragment->relocOffset;
    relocInfo = (struct RelocTable *)((uintptr_t)fragment->relocOffset + (uintptr_t)fragment);

    osInvalICache(fragment, fragment->sizeInRam);
    osInvalDCache(fragment, fragment->sizeInRam);
    func_800020B0(id, fragment, fragment->sizeInRam);

    for(i = 0; i < relocInfo->nRelocations; i++) {
        reloc = relocInfo->relocations[i];
        relocDataP = (u32*)((reloc & 0xFFFFFF) + (uintptr_t)fragment);

        switch ((reloc & 0x7F000000) >> 24) {
            case R_MIPS_32:
                // Handles 32-bit address relocation, used for things such as jump tables and pointers in data.
                // Just relocate the full address.
                *relocDataP = func_800020E0(*relocDataP);
                break;
            case R_MIPS_26:
                // Handles 26-bit address relocation, used for jumps and jals.
                // Extract the address from the target field of the J-type MIPS instruction.
                // Relocate the address and update the instruction.
                *relocDataP = (((u32) (func_800020E0(((*relocDataP * 4) & 0x0FFFFFFC) + 0x80000000) & 0x0FFFFFFF) >> 2) | (*relocDataP & 0xFC000000));
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

                temp_v0_5 = func_800020E0((*regValP << 0x10) + (s16)*relocDataP);
                isLoNeg = (temp_v0_5 & 0x8000) ? 1 : 0;
                *luiInstRef = (u32) ((*luiInstRef & 0xFFFF0000) | ((temp_v0_5 >> 16) + isLoNeg));
                *relocDataP = (u32) ((*relocDataP & 0xFFFF0000) | (temp_v0_5 & 0xFFFF));
                break;
        }
    }
    if (relocSize != 0) {
        bzero(((uintptr_t)fragment->relocOffset + (uintptr_t)fragment), relocSize);
    }
    osWritebackDCache(fragment, fragment->sizeInRam);
}

void func_800020B0(u32 id, u32 vaddr, u32 size) {
    D_800A58F0[id].vaddr = vaddr;
    D_800A58F0[id].size = size;
}

u32 func_800020CC(u32 id) {
    return D_800A58F0[id].vaddr;
}

u32 func_800020E0(u32 mask) {
    if ((mask >= 0x81000000U) && (mask < 0x90000000U)) {
        u32 id    = ((mask & 0x0FF00000) >> 0x14) - 0x10;
        u32 value = ((mask & 0xFFFFF));
        if (D_800A58F0[id].vaddr != 0) {
            mask = D_800A58F0[id].vaddr + value;
        }
    }
    return mask;
}

s32 func_80002144(s32 arg0, s32 arg1) {
    struct UnkStruct800A5870* entry = &D_800A58F0[arg0];

    if ((arg1 - entry->vaddr) >= entry->size) {
        return 0;
    }
    return ((arg0 + 0x10) << 0x14) | 0x80000000 | (arg1 - entry->vaddr);
}

void func_8000218C(u32 id) {
    D_800A58F0[id].vaddr = 0;
    D_800A58F0[id].size = 0;
}

s32 func_800021A8(u32 arg0) {
    struct UnkStruct800A5870* var_v0 = D_800A58F0;
    int i, j;

    for(i = 0; i != 0xF0; i += 4) {
        for(j = 0; j < 4; j++) {
            if (arg0 >= var_v0->vaddr) {
                u32 diff = arg0 - var_v0->vaddr;
                if (diff < var_v0->size) {
                    return ((i + (j + 0x10)) << 0x14) | 0x80000000 | diff;
                }
            }
            var_v0++;
        }
    }
    return 0;
}
