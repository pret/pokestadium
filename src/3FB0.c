#include "global.h"
#include "memory.h"

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003C80.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003D18.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80003D64.s")

void* func_80003DC4(uintptr_t romStart, uintptr_t romEnd, s32 arg2, s32 arg3) {
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

s32 func_80004258(s32 id, s32 arg1, s32 arg2, s32 arg3) {
    s32 vaddr = func_80003DC4(arg1, arg2, arg3, 0);

    if ((vaddr != 0) && (id > 0)) {
        Memmap_SetSegmentMap(id, vaddr, main_pool_get_block_dist(vaddr));
        main_pool_set_func(vaddr, id + 0x82000000, &func_80004200);
    }
    return vaddr;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_800042E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_80004364.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_800043BC.s")

void* func_80004454(s32 arg0, uintptr_t romStart, uintptr_t romEnd) {
    void* addr = func_80003DC4(romStart, romEnd, 0, 0);

    if (addr != NULL) {
        func_800043BC(arg0, addr);
    }
    return addr;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3FB0/func_800044A8.s")

void* func_800044F4(uintptr_t romStart, uintptr_t romEnd, s32 arg2, s32 arg3) {
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
