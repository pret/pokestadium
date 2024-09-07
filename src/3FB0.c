#include "3FB0.h"
#include "memory.h"
#include "memmap.h"

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_800033B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_800033C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003558.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003608.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003648.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003680.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003860.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003890.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003964.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003A14.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003B04.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003B30.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003BE0.s")

s32 func_80003680(u32 addr, u32 arg1, u32 arg2, UnkInputStruct80003C80* arg3);

s32 func_80003C80(s32 arg0, UnkInputStruct80003C80* arg1, s32 side) {
    s32 addr = main_pool_alloc(arg1->unkC + 0x100, side);

    if (addr != 0) {
        s32 size = func_80003680(addr, arg1->unkC + 0x100, (u32)arg1 + arg1->unk8, arg1);
        if (size == 0) {
            main_pool_try_free(addr);
            addr = NULL;
        } else if (side == 0) {
            main_pool_realloc(addr, size);
        }
    }
    main_pool_try_free(arg0);
    return addr;
}

void func_80003890(s32, void*);

s32 func_80003D18(s32 arg0, UnkInputStruct80003D18* arg1, s32 side) {
    s32 vaddr = main_pool_alloc(arg1->unk10, side);

    if (vaddr != NULL) {
        func_80003890(arg1, vaddr);
    }
    main_pool_try_free(arg0);
    return vaddr;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003D64.s")

void func_80003B30(u8*, u8*, u8*, s32);

void* func_80003DC4(u8* romStart, u8* romEnd, s32 arg2, s32 arg3) {
    u32* addr;
    u32* newaddr;
    u32* ret;
    s32 pad;
    int side;

    side = (arg2 == 0) ? MEMORY_POOL_RIGHT : MEMORY_POOL_LEFT;

    addr = main_pool_alloc(0x18, side);
    if (addr != NULL) {
        func_80003B30(addr, romStart, romStart + 0x18, arg3);
        // is PERS-SZP?
        if ((addr[0] == 'PERS') && (addr[1] == '-SZP')) {
            newaddr = main_pool_alloc(ALIGN16(romEnd - romStart), side);
            if (newaddr != NULL) {
                func_80003B30(newaddr, romStart, romEnd, arg3);
                ret = func_80003D18(newaddr, newaddr, arg2);
            }
            // is PRESJPEG?
        } else if ((addr[0] == 'PRES') && (addr[1] == 'JPEG')) {
            newaddr = main_pool_alloc(ALIGN16(romEnd - romStart), side);
            if (newaddr != NULL) {
                func_80003B30(newaddr, romStart, romEnd, arg3);
                ret = func_80003C80(newaddr, newaddr, arg2);
            }
        } else {
            newaddr = main_pool_alloc(ALIGN16(romEnd - romStart), arg2);
            ret = newaddr;
            if (newaddr != NULL) {
                func_80003B30(ret, romStart, romEnd, arg3);
            }
        }
        main_pool_try_free(addr);
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003F54.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80004098.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_800040EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_800041C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80004200.s")

void func_80004200(s32, s32);

s32 func_80004258(s32 id, u8* rom_start, u8* rom_end, s32 arg3) {
    s32 vaddr = func_80003DC4(rom_start, rom_end, arg3, 0);

    if ((vaddr != 0) && (id > 0)) {
        Memmap_SetSegmentMap(id, vaddr, main_pool_get_block_dist(vaddr));
        main_pool_set_func(vaddr, id + 0x82000000, &func_80004200);
    }
    return vaddr;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_800042E0.s")

void func_80004364(u32 base_addr, u32 addr) {
    u32 sp1C;
    u32 temp_a0;

    if ((addr & 0xFF000000) == 0x81000000) {
        sp1C = addr & 0xFFFFFF;
        if (Memmap_GetFragmentBaseVaddr(sp1C) == base_addr) {
            Memmap_ClearFragmentMemmap(sp1C);
        }
    }
}

void func_800043BC(s32 arg0, Fragment* addr) {
    s32 pad;
    u32 sp20 = main_pool_get_block_dist(addr);

    main_pool_set_func(addr, arg0 + 0x81000000, &func_80004364);

    if (sp20 < addr->sizeInRam) {
        main_pool_realloc(addr, addr->sizeInRam);
        Memmap_RelocateFragment(arg0, addr);
    } else {
        Memmap_RelocateFragment(arg0, addr);
        main_pool_realloc(addr, addr->sizeInRam);
    }
}

void* func_80004454(s32 arg0, u8* romStart, u8* romEnd) {
    void* addr = func_80003DC4(romStart, romEnd, 0, 0);

    if (addr != NULL) {
        func_800043BC(arg0, (Fragment*)addr);
    }
    return addr;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_800044A8.s")

void* func_800044F4(u8* romStart, u8* romEnd, s32 arg2, s32 arg3) {
    u32* ret;
    unsigned long sp28_2;
    unsigned long sp28;
    u16* newaddr;

    ret = NULL;
    switch (arg2) {
        case 0:
            newaddr = func_80003DC4(romStart, romEnd, 0, 0);
            ret = newaddr;
            if (newaddr != NULL) {
                newaddr[0] |= 1;
            }
            break;
        case 1:
            newaddr = func_80003DC4(romStart, romStart + 0x20, 0, 0);
            ret = newaddr;
            if (newaddr != NULL) {
                sp28_2 = (ret[3] * 0x10) + 0x10;
                main_pool_try_free(ret);
                newaddr = func_80003DC4(romStart, romStart + sp28_2, 0, 0);
                ret = newaddr;
                if (newaddr != NULL) {
                    *newaddr |= 2;
                    if (arg3 == 1) {
                        *newaddr |= 4;
                    }
                }
            }
            break;
        case 2:
            newaddr = func_80003DC4(romStart, romStart + 0x20, 1, 0);
            ret = newaddr;
            if (newaddr != NULL) {
                sp28 = (ret[3] * 0x10) + 0x10;
                main_pool_try_free(ret);
                newaddr = func_80003DC4(romStart, romStart + sp28, 1, 0);
                ret = newaddr;
                if ((newaddr != NULL) && (arg3 == 1)) {
                    *newaddr |= 4;
                }
            }
            break;
    }
    if (ret != NULL) {
        ret[1] = romStart;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80004660.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_800047A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_800047C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80004804.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_8000484C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_8000495C.s")
