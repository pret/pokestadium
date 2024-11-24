#include "fragment23.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/29BA0.h"
#include "src/2D340.h"
#include "src/2E110.h"
#include "src/2E460.h"
#include "src/49790.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static char** D_88224F90;
static char** D_88224F94;

static u16 D_88217BF0[4] = { 6, 7, 8, 9 };
static Color_RGBA8 D_88217BF8 = { 0xA0, 0x96, 0x64, 0xFF };
static u16 D_88217BFC[4] = { 2, 3, 4, 5 };
static Color_RGBA8 D_88217C04 = { 0x64, 0x96, 0xB4, 0xFF };
static Color_RGBA8 D_88217C08 = { 0x3C, 0x64, 0x78, 0xFF };
static Color_RGBA8 D_88217C0C = { 0xA0, 0x96, 0x64, 0xFF };

void func_88200290(unk_func_88503298* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    s32 i;
    s32 temp_v0;
    s32 var_s1;
    unk_func_885012A4* temp_s0;

    var_s1 = 0;
    for (i = 0; i < 4; i++) {
        temp_v0 = func_8001F5B0(0x10, 0, func_8002D7C0(NULL, 0, D_88224F94, D_88217BF0[i]));
        if (var_s1 < temp_v0) {
            var_s1 = temp_v0;
        }
    }
    var_s1 += 0x10;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88503298));
    arg0->unk_00.unk_10.unk_00 = ((0x280 - var_s1) / 2) - arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, var_s1, 0x68);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    temp_s0 = mem_pool_alloc(arg3, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(temp_s0, 0, 0, var_s1, 0x68, D_88217BF8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s0);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_30, 8, 8, 0, 0x10);
    arg0->unk_30->unk_3C = 0x20;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s0, arg0->unk_30);
}

void func_882004BC(unk_func_88503298* arg0, s8* arg1) {
    arg0->unk_30->unk_40 = arg1;
}

void func_882004C8(unk_func_88200FA0_030* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4) {
    s32 i;
    s32 j;
    char* temp_s0;
    s32 temp_v0;
    s32 var_s2;
    unk_func_885012A4* temp_s0_2;
    unk_func_8850B254* sp6C;
    UNUSED s32 pad1[3];
    unk_func_88503298* temp_s0_3;
    unk_func_8850878C* temp_s1;

    if ((arg2 <= 0) || (arg2 >= 5)) {
        arg2 = 0;
    } else {
        arg2--;
    }

    var_s2 = func_8001F5B0(0x10, 0, func_8002D7C0(NULL, 0, D_88224F94, 1));

    for (j = 0; j < 4; j++) {
        temp_v0 = func_8001F5B0(0x10, 0, func_8002D7C0(NULL, 0, D_88224F94, D_88217BFC[j]));
        if (var_s2 < temp_v0) {
            var_s2 = temp_v0;
        }
    }
    var_s2 += 0x10;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88200FA0_030));
    arg0->unk_00.unk_20 = func_88200A30;
    arg0->unk_00.unk_10.unk_00 = (0x280 - var_s2) / 2;
    arg0->unk_00.unk_10.unk_02 = arg1;

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, var_s2, 0xA4);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    sp6C = mem_pool_alloc(arg4, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(sp6C, 0, 0, var_s2, 0x18, D_88217C04, D_88217C08);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp6C);

    temp_s1 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
    temp_s0 = func_8002D7C0(NULL, 0, D_88224F94, 1);
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s1, (var_s2 - func_8001F5B0(0x10, 0, temp_s0)) / 2, 0,
                                                           temp_s0, 0x10);
    temp_s1->unk_3C = 0x1C;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp6C, temp_s1);

    func_8002CBC0(&arg0->unk_38, 4, arg4);

    for (i = 0; i < 4; i++) {
        func_8002CC2C(&arg0->unk_38, func_8002D7C0(NULL, 0, D_88224F94, D_88217BFC[i]), i);
    }

    temp_s0_2 = mem_pool_alloc(arg4, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(temp_s0_2, 0, 0x1C, var_s2, 0x88, D_88217C0C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s0_2);

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_30, 0, 4, func_882009B4, var_s2, 0x20, 4, 1, arg4);
    ((func88506384)Memmap_GetFragmentVaddr(func_88506384))(arg0->unk_30, &arg0->unk_38, arg4);
    ((func88506BFC)Memmap_GetFragmentVaddr(func_88506BFC))(arg0->unk_30, arg2);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s0_2, arg0->unk_30);

    arg0->unk_34 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    func_88200290(arg0->unk_34, arg0->unk_00.unk_10.unk_00, 0xB4, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_34);
    func_88200968(arg0, arg2);

    temp_s0_3 = mem_pool_alloc(arg4, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(temp_s0_3, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, temp_s0_3);
}

void func_88200968(unk_func_88200FA0_030* arg0, s32 arg1) {
    func_882004BC(arg0->unk_34, func_8002D7C0(NULL, 0, D_88224F94, arg1 + 6));
}

void func_882009B4(s32 arg0, s32 arg1, char* arg2, s32 arg3) {
    static Color_RGBA8 D_88217C10 = { 0xF0, 0xF0, 0xF0, 0xFF };

    func_8001F3F4();
    func_8001F324(D_88217C10.r, D_88217C10.g, D_88217C10.b, D_88217C10.a);
    func_8001EBE0(0x10, 0);
    func_8001F1E8(arg0 + 8, arg1 + 4, arg2);
    func_8001F444();
}

s32 func_88200A30(unk_func_88200FA0_030* arg0, Controller* arg1) {
    s32 sp1C;

    if (arg0->unk_2C->unk_30 & 2) {
        sp1C = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
        if ((sp1C & 1) && (sp1C & 8)) {
            func_88200968(arg0, arg0->unk_30->unk_38);
        }
    } else if (!(arg0->unk_2C->unk_00.unk_28 & 1)) {
        sp1C = 2;
    } else {
        sp1C = 1;
    }
    return sp1C;
}

void func_88200ACC(unk_func_88200FA0_030* arg0) {
    arg0->unk_2C->unk_00.unk_28 |= 1;
    arg0->unk_34->unk_2C->unk_00.unk_28 |= 1;
}

void func_88200AF4(unk_func_88200FA0_030* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
    arg0->unk_34->unk_2C->unk_2C = 0xB;
    while (arg0->unk_2C->unk_00.unk_28 & 1) {
        func_8002EEA8(NULL);
    }
}

s32 func_88200B60(unk_func_88200FA0_030* arg0, Controller* arg1) {
    s32 var_s0;
    s32 var_s1 = 0;

    func_88200ACC(arg0);

    while (var_s1 == 0) {
        func_8002EEA8(NULL);
        var_s0 = func_88200A30(arg0, arg1);
        if (!(var_s0 & 1)) {
            if (arg1->buttonPressed & 0x4000) {
                var_s0 = 0x80000003;
                var_s1 = 1;
            } else if (arg1->buttonPressed & 0x8000) {
                func_80048B90(0x1C);
                var_s0 = 1;
                var_s1 = arg0->unk_30->unk_38 + 2;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(var_s0);
    }
    func_88200AF4(arg0);
    return var_s1;
}

void func_88200C44(unk_func_88200FA0* arg0, s32 arg1, s32 arg2, s32 arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88217C14 = { 0x1E, 0x50, 0x50, 0xFF };
    static Color_RGBA8 D_88217C18 = { 0x00, 0x0A, 0x0A, 0xFF };

    unk_func_88001300_000* sp4C;
    unk_func_88500EE4* sp48;
    unk_func_88509A2C* sp44;
    unk_func_88509E34* sp40;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, 0x34);
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    sp4C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func885031E8)Memmap_GetFragmentVaddr(func_885031E8))(sp4C, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, sp4C);

    sp48 = mem_pool_alloc(arg4, sizeof(unk_func_88500EE4));
    ((func88500EE4)Memmap_GetFragmentVaddr(func_88500EE4))(sp48, 0, 0, 0x280, 0x1E0, D_88223E48, D_88217C14,
                                                           D_88217C18);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp4C, sp48);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_885088F4));
    ((func885088F4)Memmap_GetFragmentVaddr(func_885088F4))(arg0->unk_2C, 0x41, 0x15C, 0xDC);
    if (func_80007604() == 0) {
        arg0->unk_2C->unk_2C = 5;
    }
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp4C, arg0->unk_2C);

    sp44 = mem_pool_alloc(arg4, sizeof(unk_func_88509A2C));
    ((func88509A2C)Memmap_GetFragmentVaddr(func_88509A2C))(sp44, 0x38, 0x22, func_80029080(),
                                                           func_8002D7C0(NULL, 0, D_88224F90, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp44);

    sp40 = mem_pool_alloc(arg4, sizeof(unk_func_88509E34));
    ((func88509E34)Memmap_GetFragmentVaddr(func_88509E34))(sp40, 0, 0, func_8002D7C0(NULL, 0, D_88224F94, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp40);

    arg0->unk_30 = mem_pool_alloc(arg4, sizeof(unk_func_88200FA0_030));
    func_882004C8(arg0->unk_30, 0x78, arg3, sp4C, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_30);

    arg0->unk_00.unk_24(&arg0->unk_00, 1);
}

s32 func_88200F00(unk_func_88200FA0* arg0) {
    s32 sp34 = 0;

    while (sp34 == 0) {
        func_800079C4();
        ((func885008C4)Memmap_GetFragmentVaddr(func_885008C4))(arg0);
        ((func88500828)Memmap_GetFragmentVaddr(func_88500828))(arg0, 0, 0);
        func_80007778();
        func_8002EF18(&sp34);
    }
    return sp34;
}

void func_88200FA0(unk_func_88200FA0* arg0) {
    s32 sp24;
    s32 i;

    while (func_80007604() != 0) {
        func_8002EEA8(NULL);
    }

    func_8001F738(gPlayer1Controller);

    sp24 = func_88200B60(arg0->unk_30, gPlayer1Controller);
    if (sp24 == 1) {
        arg0->unk_2C->unk_2C = 9;
        func_80006CB4(8);

        i = 10;
        while (i-- > 0) {
            func_8002EEA8(NULL);
        }
    }
    func_8002EEA8(sp24);

    osStopThread(NULL);
}

s32 func_8820104C(s32 arg0, UNUSED s32 arg1) {
    MemoryPool* sp34;
    void* sp30;
    u8* sp2C;
    func_88002628_sp38* sp28;
    UNUSED s32 pad;
    s32 sp20;

    main_pool_push_state('SLTM');

    sp2C = main_pool_alloc(0x1000, 0);
    sp34 = mem_pool_try_init(0x8000, 0);

    func_8002D510();
    D_88224F90 = func_8002D5AC(0x2A);
    D_88224F94 = func_8002D5AC(1);

    sp30 = mem_pool_alloc(sp34, sizeof(unk_func_88200FA0));
    func_88200C44(sp30, 0, 0, arg0, sp34);

    sp28 = ALIGN16((u32)mem_pool_alloc(sp34, sizeof(func_88002628_sp38)));
    osCreateThread(&sp28->thread, 0x32, func_88200FA0, sp30, sp2C + 0x1000, osGetThreadPri(NULL) - 1);

    func_8002EE78();
    func_8001F738(gPlayer1Controller);

    osStartThread(&sp28->thread);

    func_80006C6C(8);
    sp20 = func_88200F00(sp30);

    osDestroyThread(&sp28->thread);

    main_pool_pop_state('SLTM');

    if (sp20 == 1) {
        FRAGMENT_LOAD_AND_CALL2(fragment22, 1, 0);
        return 0;
    }

    if (sp20 == 5) {
        FRAGMENT_LOAD_AND_CALL2(fragment24, 1, 0);
        return 0;
    }

    return sp20 - 1;
}
