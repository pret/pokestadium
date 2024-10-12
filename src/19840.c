#include "19840.h"
#include "src/geo_layout.h"
#include "src/dma.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/util.h"
#include <PR/os_internal_reg.h>
#include <PR/leo.h>
#include "src/memory.h"

typedef struct ret_func_unk_D_800ABE10 {
    /* 0x00 */ char unk00[0x3];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ char unk04[0x4];
    /* 0x08 */ unk_D_86002F34** unk_08;
    /* 0x0C */ char unk0C[0x8];
    /* 0x14 */ func_unk_D_800ABE10 unk_14;
} ret_func_unk_D_800ABE10;

unk_D_800ABE10 D_800ABE10;

#ifdef NON_MATCHING
void func_80018C40(unk_D_86002F34* arg0, arg1_func_80010CA8 arg1) {
    s32 i;
    s32 j;
    unk_D_86002F34_018* var_s2;
    unk_D_86002F34_01C* var_s4;

    var_s2 = arg0->unk_18;
    var_s4 = arg0->unk_1C;

    for (i = 0; i < arg0->unk_24; i++, var_s2++) {
        if (var_s2->unk_00 == 0) {
            if (var_s2->unk_01 == 2) {
                u16* var_s1 = var_s2->unk_08;

                for (j = 0; j < var_s2->unk_06; j++) {
                    var_s1[j] = func_80010CA8(var_s1[j], arg1);
                }
            }

            if (var_s2->unk_01 == 3) {
                u32* var_s1 = var_s2->unk_08;

                for (j = 0; j < var_s2->unk_06; j++) {
                    var_s1[j] = func_80010E20(var_s1[j], arg1);
                }
            }
        }
    }

    for (i = 0; i < arg0->unk_25; i++, var_s4++) {
        u16* var_s1 = var_s4->unk_04;

        for (j = 0; j < var_s4->unk_00; j++) {
            var_s1[j] = func_80010CA8(var_s1[j], arg1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/19840/func_80018C40.s")
#endif

Fragment* func_80018DE8(MemoryBlock* arg0, PRESJPEG* arg1, PRESJPEG* arg2) {
    Fragment* sp1C;
    s32 sp18;
    s32 temp_v0_2;

    sp18 = arg0->size;
    sp1C = func_80002DCC(arg0, arg2->unk_0C + 0x100, 0x10);

    if (sp1C != NULL) {
        temp_v0_2 = func_80003680(sp1C, arg2->unk_0C + 0x100, (u8*)arg2 + arg2->unk_08);
        if (temp_v0_2 == 0) {
            func_80002E3C(arg0, sp18);
            sp1C = NULL;
        } else {
            func_80002E3C(arg0, sp18 + temp_v0_2);
        }
    }
    return sp1C;
}

Fragment* func_80018E7C(MainPoolState* arg0, PERSSZP* arg1, PERSSZP* arg2) {
    u8* sp1C = func_80002DCC(arg0, arg2->decompressed_size2, 0x10);

    if (sp1C != NULL) {
        func_80003890(arg2, sp1C);
    }
    return sp1C;
}

Fragment* func_80018EC4(MainPoolState* arg0, PERSSZP* arg1, s32 arg2, u32 arg3) {
    u32* sp1C;

    sp1C = func_80002DCC(arg0, arg3, 0x10);
    if (sp1C != NULL) {
        Util_Memcpy(sp1C, (u8*)arg1 + arg2, arg3 >> 2);
    }
    return sp1C;
}

Fragment* func_80018F20(MainPoolState* arg0, s32 start, s32 end, PERSSZP* arg3, s32 arg4) {
    UNUSED s32 pad;
    u32 size = ALIGN16(end - start);
    Fragment* var_v1 = NULL;

    if (arg4 >= size) {
        func_80003B30(arg3, start, end, 0);

        if (((u32*)arg3->magic)[0] == 'PERS' && (((u32*)arg3->magic)[1] == '-SZP')) {
            var_v1 = func_80018E7C(arg0, arg3, arg3);
        } else if (((u32*)arg3->magic)[0] == 'PRES' && (((u32*)arg3->magic)[1] == 'JPEG')) {
            var_v1 = func_80018DE8(arg0, arg3, arg3);
        } else {
            var_v1 = func_80018EC4(arg0, arg3, 0, size);
        }
    }

    return var_v1;
}

Fragment* func_80018FF4(MainPoolState* arg0, unk_func_800041C0* arg1, PERSSZP* arg2, u32 arg3) {
    s32 sp3C;
    Fragment* sp38;
    PERSSZP* temp_s1;

    LeoLBAToByte(arg1->unk_00, arg1->unk_02, &sp3C);
    sp3C = ALIGN16(sp3C);

    if (arg3 >= sp3C) {
        temp_s1 = arg1->unk_04 + (u8*)arg2;

        func_80001098(0, arg2, arg1->unk_00, arg1->unk_02, &D_800ABE10.unk_9EC, 0);
        osRecvMesg(&D_800ABE10.unk_9EC, NULL, 1);

        if (((u32*)temp_s1->magic)[0] == 'PERS' && (((u32*)temp_s1->magic)[1] == '-SZP')) {
            sp38 = func_80018E7C(arg0, arg2, temp_s1);
        } else if (((u32*)temp_s1->magic)[0] == 'PRES' && (((u32*)temp_s1->magic)[1] == 'JPEG')) {
            sp38 = func_80018DE8(arg0, arg2, temp_s1);
        } else {
            sp38 = func_80018EC4(arg0, arg2, arg1->unk_04, arg1->unk_08);
        }
    }

    return sp38;
}

void func_80019128(MainPoolState* arg0, u32 arg1, Fragment* arg2) {
    Memmap_RelocateFragment(arg1, arg2);
    func_80002E3C(arg0, ((u32)arg2 + arg2->sizeInRam) - (u32)arg0->listHeadR);
}

Fragment* func_80019170(MainPoolState* arg0, BinArchive* arg1, BinArchiveFile* arg2, u32 arg3, s32 arg4) {
    s32 temp_a1 = arg1->unk_04 + arg2->offset;

    return func_80018F20(arg0, temp_a1, arg2->size + temp_a1, arg3, arg4);
}

Fragment* func_800191B0(MainPoolState* arg0, BinArchive* arg1, BinArchiveFile* arg2, u32 arg3, s32 arg4) {
    unk_func_800041C0 sp1C;

    func_800040EC(&sp1C, arg1->unk_04, arg2->offset, arg2->size);
    return func_80018FF4(arg0, &sp1C, arg3, arg4);
}

Fragment* func_80019204(MainPoolState* arg0, BinArchive* arg1, s32 arg2, u32 arg3, s32 arg4) {
    s32 pad[4];
    Fragment* var_s0 = NULL;
    BinArchiveFile* sp2C = (u8*)arg1 + sizeof(BinArchive) + (arg2 * sizeof(BinArchiveFile));

    if (arg2 < arg1->num_files) {
        if (arg1->unk_00 & 1) {
            var_s0 = (u8*)arg1 + sp2C->offset;
        } else if (!(arg1->unk_00 & 4) && (sp2C->unk_08 != NULL)) {
            var_s0 = sp2C->unk_08;
        } else {
            if (arg1->unk_00 & 0x80) {
                var_s0 = func_800191B0(arg0, arg1, sp2C, arg3, arg4);
            } else {
                var_s0 = func_80019170(arg0, arg1, sp2C, arg3, arg4);
            }

            if (var_s0 != NULL) {
                if ((((u32*)var_s0->magic)[0] == 'FRAG') && (((u32*)var_s0->magic)[1] == 'MENT')) {
                    func_80019128(arg0, arg1->unk_02, var_s0);
                }
                sp2C->unk_08 = var_s0;
            }
        }
    }

    return var_s0;
}

s32 func_80019328(MemoryBlock* arg0, Fragment* arg1, arg1_func_80010CA8 arg2) {
    s32 i;
    unk_D_86002F34* temp_v0_2;
    ret_func_unk_D_800ABE10* temp_v0;
    ret_func_unk_D_800ABE10* (*func)(s32, s32) = arg1;

    temp_v0 = func(0, 0);
    temp_v0->unk_14 = arg1;

    for (i = 0; i < temp_v0->unk_03; i++) {
        temp_v0_2 = process_geo_layout(arg0, temp_v0->unk_08[i]);

        if (temp_v0_2->unk_00.unk_00 == 0xE) {
            temp_v0_2->unk_28 = arg1;
            if (arg2.raw != 0) {
                func_80018C40(temp_v0_2, arg2);
            }
        }
        temp_v0->unk_08[i] = temp_v0_2;
    }

    return temp_v0;
}

void func_80019420(MemoryBlock* arg0, arg1_func_80019420* arg1) {
    while (arg1->unk_00) {
        if (arg1->unk_00 == 3) {
            arg1->unk_04 = process_geo_layout(arg0, arg1->unk_04);
        }

        arg1++;
    }
}

void func_80019484(unk_func_80019600* arg0) {
    UNUSED s32 pad;
    MemoryBlock* sp28;
    Fragment* sp24;

    sp28 = func_80002DA4(arg0->pool, arg0->size);
    sp24 = func_80019204(sp28, D_800ABE10.unk_A04.unk_00, arg0->unk_02, D_800ABE10.unk_A04.unk_08, 0x28000);

    if (sp24 != NULL) {
        arg0->unk_08 = func_80019328(sp28, sp24, arg0->unk_18);
    } else {
        arg0->unk_08 = 0;
    }

    arg0->size = sp28->size + 0x10;
}

void func_80019514(unk_func_80019600* arg0) {
    Fragment* temp_v0;
    MainPoolState* temp_s3;
    s32 var_s2;
    s32* temp_s6;
    s16* var_s0;

    temp_s6 = arg0->unk_08;
    var_s2 = 0;
    temp_s3 = func_80002DA4(arg0->pool, arg0->size);
    var_s0 = arg0->unk_0C;

    while (*var_s0 != -1) {
        temp_v0 = func_80019204(temp_s3, D_800ABE10.unk_A04.unk_04, *var_s0, D_800ABE10.unk_A04.unk_08, 0x28000);
        if (temp_v0 == NULL) {
            break;
        }

        temp_s6[var_s2] = temp_v0 + 1;
        func_80019420(temp_s3, temp_v0 + 1);
        var_s0++;
        var_s2++;
    }

    temp_s6[var_s2] = 0;
    arg0->size = temp_s3->listHeadL + 1;
}

#ifdef NON_MATCHING
void func_80019600(UNUSED void* arg0) {
    unk_func_80019600* sp34;

    __osSetFpcCsr(0x01000C01);

    while (true) {
        osRecvMesg(&D_800ABE10.unk_9D0, &sp34, 1);

        switch (sp34->unk_00) {
            case 1:
                func_80019484(sp34);
                break;

            case 2:
                func_80019514(sp34);
                break;
        }

        if (sp34->queue == NULL) {
            continue;
        }

        osSendMesg(sp34->queue, sp34, 1);
    }
}
#else
void func_80019600(UNUSED void* arg0);
#pragma GLOBAL_ASM("asm/us/nonmatchings/19840/func_80019600.s")
#endif

void func_800196DC(void) {
    osCreateMesgQueue(&D_800ABE10.unk_9D0, &D_800ABE10.unk_9B0, 8);
    osCreateMesgQueue(&D_800ABE10.unk_9EC, &D_800ABE10.unk_9E8, 1);
    osCreateThread(&D_800ABE10.unk_000, 7, func_80019600, NULL, &D_800ABE10.unk_9B0, 0xA);
    osStartThread(&D_800ABE10.unk_000);
}

unk_D_86002F58_004_000_010* func_80019760(u32 arg0) {
    s16 i = 1;
    unk_D_86002F58_004_000_010* temp_v0 = main_pool_alloc(sizeof(unk_D_86002F58_004_000_010), 1);

    temp_v0->unk_00 = arg0;
    temp_v0->unk_01 = 0;
    temp_v0->unk_02 = 0;
    temp_v0->unk_24 = 0;
    temp_v0->unk_04[0] = NULL;
    temp_v0->unk_04[1] = NULL;
    temp_v0->unk_18 = NULL;
    temp_v0->unk_2C.raw = 0;

    if (arg0 & 1) {
        temp_v0->unk_04[0] = main_pool_alloc(0x3C000, 1);
        if (arg0 & 4) {
            temp_v0->unk_04[1] = main_pool_alloc(0x3C000, 1);
        } else if (arg0 & 8) {
            for (i = 1; i < 5; i++) {
                temp_v0->unk_04[i] = main_pool_alloc(0x3C000, 1);
            }
        }
    }

    if (arg0 & 2) {
        temp_v0->unk_18 = main_pool_alloc(0x18000, 1);
    }

    osCreateMesgQueue(&temp_v0->unk_30, &temp_v0->unk_48, 2);
    osCreateMesgQueue(&temp_v0->unk_50, &temp_v0->unk_68, 2);
    return temp_v0;
}

void func_8001987C(void) {
    D_800ABE10.unk_A04.unk_00 = func_800044F4(0x920000, NULL, 1, 1);
    D_800ABE10.unk_A04.unk_04 = func_800044F4(0x8CC000, NULL, 1, 1);
    D_800ABE10.unk_A04.unk_08 = main_pool_alloc(0x28000, 1);
}

s32 func_800198E4(unk_D_86002F58_004_000_010* arg0, u16 arg1, unk_D_86002F58_004_000_010_02C arg2) {
    s32 sp1C;
    sp18_func_800198E4* sp18;
    s32 var_v1;

    sp1C = 0;
    if ((arg0->unk_00 & 1) && !(arg0->unk_01 & 1)) {
        sp18 = Util_Malloc(sizeof(sp18_func_800198E4));
        if (sp18 != NULL) {
            var_v1 = arg0->unk_02;
            if (arg0->unk_00 & 4) {
                var_v1 ^= 1;
            }

            sp18->unk_00 = 1;
            sp18->unk_02 = arg1 - 1;
            sp18->unk_04 = &arg0->unk_30;
            sp18->unk_08 = 0;
            sp18->unk_0C = 0;
            sp18->unk_10 = arg0->unk_04[var_v1];
            sp18->unk_14 = 0x3C000;
            sp18->unk_18 = arg2;

            if ((arg0->unk_24 != NULL) && (arg0->unk_24->unk_00 == arg1) && (arg0->unk_2C.raw == sp18->unk_18.raw)) {
                osSendMesg(sp18->unk_04, sp18, 1);
            } else {
                osSendMesg(&D_800ABE10.unk_9D0, sp18, 1);
            }

            arg0->unk_01 |= 1;
            sp1C = 1;
        }
    }

    return sp1C;
}

s32 func_80019A1C(unk_D_86002F58_004_000_010* arg0, u16 arg1, unk_D_86002F58_004_000_010_02C arg2, s16 arg3) {
    if ((arg0->unk_00 & 8) && !(arg0->unk_01 & 1)) {
        arg0->unk_02 = arg3;
        func_800198E4(arg0, arg1, arg2);
    }
    return 0;
}

s32 func_80019A7C(unk_D_86002F58_004_000_010* arg0, s32 arg1, s32 arg2) {
    s32 sp1C = 0;
    sp18_func_800198E4* temp_v0;

    if ((arg0->unk_00 & 2) && !(arg0->unk_01 & 2)) {
        temp_v0 = Util_Malloc(sizeof(sp18_func_800198E4));
        if (temp_v0 != NULL) {
            temp_v0->unk_00 = 2;
            temp_v0->unk_02 = 0;
            temp_v0->unk_04 = &arg0->unk_50;
            temp_v0->unk_08 = arg2;
            temp_v0->unk_0C = arg1;
            temp_v0->unk_10 = arg0->unk_18;
            temp_v0->unk_14 = 0x18000;

            osSendMesg(&D_800ABE10.unk_9D0, temp_v0, 1);

            sp1C = 1;
            arg0->unk_01 |= 2;
        }
    }

    return sp1C;
}

s32 func_80019B48(unk_D_86002F58_004_000_010* arg0, sp18_func_800198E4* arg1) {
    s32 sp1C = 0;

    switch (arg1->unk_00) {
        case 1:
            arg0->unk_01 &= ~1;
            if (arg1->unk_08 != 0) {
                if (arg0->unk_00 & 4) {
                    arg0->unk_02 ^= 1;
                }
                arg0->unk_24 = arg1->unk_08;
                arg0->unk_1C = arg1->unk_14;
                arg0->unk_2C = arg1->unk_18;
            }
            sp1C = 1;
            break;

        case 2:
            arg0->unk_01 &= ~2;
            arg0->unk_28 = arg1->unk_08;
            arg0->unk_20 = arg1->unk_14;
            sp1C = 1;
            break;
    }

    Util_Free(arg1);
    return sp1C;
}

s32 func_80019C08(unk_D_86002F58_004_000_010* arg0) {
    sp18_func_800198E4* sp1C;
    s32 sp18 = 0;

    if (osRecvMesg(&arg0->unk_30, &sp1C, 0) != -1) {
        sp18 = func_80019B48(arg0, sp1C);
    }

    return sp18;
}

s32 func_80019C58(unk_D_86002F58_004_000_010* arg0) {
    OSMesg sp1C;
    s32 sp18 = 0;

    if (osRecvMesg(&arg0->unk_50, &sp1C, 0) != -1) {
        sp18 = func_80019B48(arg0, sp1C);
    }

    return sp18;
}

s32 func_80019CA8(unk_D_86002F58_004_000_010* arg0) {
    OSMesg sp1C;

    osRecvMesg(&arg0->unk_30, &sp1C, 1);
    return func_80019B48(arg0, sp1C);
}

s32 func_80019CE0(unk_D_86002F58_004_000_010* arg0) {
    OSMesg sp1C;

    osRecvMesg(&arg0->unk_50, &sp1C, 1);
    return func_80019B48(arg0, sp1C);
}

unk_D_86002F30* func_80019D18(s32 arg0) {
    Fragment* sp2C;
    arg1_func_80010CA8 sp28;
    unk_D_86002F30* sp24 = NULL;
    MemoryBlock* sp20;

    sp2C = func_8000484C(D_800ABE10.unk_A04.unk_00, arg0 - 1);
    if (sp2C != NULL) {
        sp20 = func_80002D10(main_pool_get_available(), 0);
        sp28.raw = 0;
        sp24 = func_80019328(sp20, sp2C, sp28);
        func_80002D60(sp20);
    }

    return sp24;
}

s32 func_80019D90(unk_func_8001BEE8* arg0) {
    Fragment* sp2C;
    arg1_func_80010CA8 sp28;
    s32 sp24 = 0;
    MemoryBlock* sp20;

    sp2C = func_8000484C(D_800ABE10.unk_A04.unk_00, arg0->unk_00 - 1);
    if (sp2C != NULL) {
        sp20 = func_80002D10(main_pool_get_available(), 0);
        func_8001BEE8(&sp28, arg0);
        sp24 = func_80019328(sp20, sp2C, sp28);
        func_80002D60(sp20);
    }
    return sp24;
}

s32 func_80019E18(s32 arg0, s32 arg1) {
    Fragment* sp2C;
    arg1_func_80010CA8 sp28;
    s32 sp24 = 0;
    MemoryBlock* sp20;

    sp2C = func_8000484C(D_800ABE10.unk_A04.unk_00, arg0 - 1);
    if (sp2C != NULL) {
        sp20 = func_80002D10(main_pool_get_available(), 0);
        sp28.raw = 0;
        sp28.unk_00 = arg1 * 64;
        sp24 = func_80019328(sp20, sp2C, sp28);
        func_80002D60(sp20);
    }
    return sp24;
}

arg1_func_80019420* func_80019EA0(s32 arg0) {
    Fragment* sp24;
    arg1_func_80019420* sp20;
    MemoryBlock* sp1C;

    sp20 = NULL;
    sp24 = func_8000484C(D_800ABE10.unk_A04.unk_04, arg0);
    if (sp24 != NULL) {
        sp1C = func_80002D10(main_pool_get_available(), 0);
        sp20 = sp24->data;
        func_80019420(sp1C, sp20);
        func_80002D60(sp1C);
    }
    return sp20;
}

Fragment* func_80019F0C(MainPoolState* arg0, u32 arg1, s32 arg2, s32 arg3, PERSSZP* arg4, s32 arg5) {
    Fragment* sp24 = func_80018F20(arg0, arg2, arg3, arg4, arg5);

    if (sp24 != NULL) {
        func_80019128(arg0, arg1, sp24);
    }
    return sp24;
}
