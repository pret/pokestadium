#include "fragment23.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/22630.h"
#include "src/232C0.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/2D340.h"
#include "src/2E110.h"
#include "src/2E460.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/hal_libc.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/fragments/29/fragment29.h"

static char** D_88224FA0;
static char** D_88224FA4;

void func_88201210(unk_func_88205880_00D0* arg0) {
    s32 i;
    s32 temp_s3;
    unk_func_80026268_arg0* tmp = arg0->unk_000;

    temp_s3 = func_80029080();

    for (i = 0; i < arg0->unk_690; i++, tmp++) {
        if ((tmp->unk_00.unk_00 > 0) && (tmp->unk_00.unk_00 < 0x98)) {
            func_800256F4(temp_s3, tmp->unk_00.unk_00, 3);
        }
    }
}

void func_88201294(s32 arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3) {
    unk_func_80022C28_ret* sp1C = func_80022C28(arg0, arg1, arg2, 1);

    func_80022F24(arg3, arg3->unk_690, sp1C);

    if ((arg0 == 0x10) || (arg0 == 0x11) || (arg0 == 0x12)) {
        func_80022D24(sp1C);
    } else {
        func_80022D8C(sp1C);
    }
}

s32 func_8820130C(s32 arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3, s32 arg4) {
    s32 sp1C;
    unk_func_80022C28_ret* sp18;

    sp18 = func_80022C28(arg0, arg1, arg2, 0);
    if (sp18 == 0) {
        return 0;
    }
    sp1C = func_80022E18(&arg3->unk_000, arg4, sp18);
    func_80022D8C(sp18);
    return sp1C;
}

void func_88201360(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 temp_v0;

    for (i = 0; i < arg3; i++, arg0++) {
        bzero(arg0->unk_000, sizeof(unk_func_80026268_arg0) * 20);
        arg0->unk_690 = func_8820130C(arg1, arg2, i, arg0, 0x14);
        arg0->unk_694 = arg1;
        arg0->unk_698 = i;
        arg0->unk_69C = 0;
    }
}

s32 func_882013F8(unk_func_88205880_A030* arg0) {
    s32 i;
    unk_func_88205880_00D0** var_a0 = arg0->unk_00;

    for (i = 0; i < arg0->unk_08; i++) {
        if (var_a0[i]->unk_690 == 0) {
            return 0;
        }
    }

    return 1;
}

s32 func_88201440(unk_func_88205880_A030* arg0) {
    s32 i;
    unk_func_88205880_00D0** var_a0 = arg0->unk_00;

    for (i = 0; i < arg0->unk_08; i++) {
        if (var_a0[i]->unk_690 > 0) {
            return 0;
        }
    }

    return 1;
}

void func_88201488();
static Color_RGBA8 D_88217C20 = { 0xF0, 0xF0, 0xF0, 0xFF };
static Color_RGBA8 D_88217C24 = { 0x28, 0x28, 0x64, 0xFF };
static Color_RGBA8 D_88217C28 = { 0x3C, 0x3C, 0x82, 0xFF };
static Color_RGBA8 D_88217C2C = { 0x78, 0x78, 0x96, 0xFF };
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1A9780/func_88201488.s")

void func_88201DA0(unk_func_88201DA0* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, FragmentEntry arg4,
                   unk_func_88205880_0098* arg5, MemoryPool* arg6) {
    static Color_RGBA8 D_88217C30 = { 0x32, 0x64, 0x64, 0xFF };

    UNUSED s32 pad[2];
    unk_func_88503298* sp44;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88201DA0));

    arg0->unk_00.unk_20 = func_88202254;
    arg0->unk_00.unk_24 = func_88202228;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_34 = main_pool_alloc(0xFAA0, 0);
    arg0->unk_48 = arg4;
    arg0->unk_4C = arg5;

    arg0->unk_2C = mem_pool_alloc(arg6, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, 0x212, 0x148);
    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    arg0->unk_58 = mem_pool_alloc(arg6, sizeof(unk_func_8850182C));
    ((func8850182C)Memmap_GetFragmentVaddr(func_8850182C))(arg0->unk_58, 0, 0, arg0->unk_2C->unk_00.unk_14.unk_00, 0x1C,
                                                           D_88217C30);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_58);

    arg0->unk_50 = mem_pool_alloc(arg6, sizeof(unk_func_8850878C));
    arg0->unk_54 = mem_pool_alloc(arg6, sizeof(char) * 18);
    arg0->unk_54[0] = '\x00';
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_50, 0, 4, arg0->unk_54, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_58, arg0->unk_50);

    arg0->unk_30 = mem_pool_alloc(arg6, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_30, 0, 0x1C, func_88201488, 0x6A, 0x4B, 4, 5,
                                                           arg6);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_30, 0x14, arg6);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_30);

    sp44 = mem_pool_alloc(arg6, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(sp44, arg0->unk_2C, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, sp44);

    func_88202228(&arg0->unk_00, 1);
}

void func_88202054(unk_func_88201DA0* arg0, u32 arg1, u32 arg2) {
    static u16 D_88217C34[] = { 0x32, 0x33 };
    static Color_RGBA8 D_88217C38[] = {
        { 0x96, 0x64, 0x1E, 0xFF },
        { 0x32, 0x64, 0x64, 0xFF },
    };

    HAL_Strcpy(arg0->unk_54, func_8002D7C0(NULL, 0, D_88224FA4, D_88217C34[arg1 - 1]));
    sprintf(&arg0->unk_54[strlen(arg0->unk_54)], " No.%d", arg2 + 1);

    arg0->unk_50->unk_00.unk_10.unk_00 =
        (arg0->unk_2C->unk_00.unk_14.unk_00 - func_8001F5B0(arg0->unk_50->unk_2C, arg0->unk_50->unk_38, arg0->unk_54)) /
        2;
    arg0->unk_58->unk_2C = D_88217C38[arg1 - 1];
}

void func_8820213C(unk_func_88201DA0* arg0, unk_func_88205880_00D0* arg1, u32 arg2) {
    unk_func_80026268_arg0* ptr = arg1->unk_000;
    s32 i;

    arg0->unk_5C = arg1;
    arg0->unk_60 = arg2;

    for (i = 0; i < arg1->unk_690; i++, ptr++) {
        arg0->unk_34[i].unk_000 = ptr;
        func_8001B0DC(&arg0->unk_34[i].unk_008, 0, ptr);
    }

    func_8002C740(&arg0->unk_38, arg0->unk_34, 0xC88, 0x14, arg1->unk_690);

    ((func885063B8)Memmap_GetFragmentVaddr(func_885063B8))(arg0->unk_30, &arg0->unk_38);

    func_88202054(arg0, arg2 >> 0x10, arg2 & 0xFFFF);
}

void func_88202228(unk_func_88203ED8* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_30->unk_00.unk_24(arg0->unk_30, arg1);
}

s32 func_88202254(unk_func_88201DA0* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
        if (var_v1 == 0) {
            if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            } else if (arg1->buttonPressed & 0x8000) {
                func_80048B90(2);

                arg0->unk_4C->unk_0C = arg0->unk_34[arg0->unk_30->unk_38].unk_000;
                arg0->unk_4C->unk_10 = arg0->unk_60 >> 0x10;

                arg0->unk_48(1, arg0->unk_4C);

                arg0->unk_30->unk_00.unk_24(arg0->unk_30, 0x100);
                if (arg0->unk_48(4, arg0->unk_4C) == 1) {
                    arg0->unk_5C->unk_69C = 1;
                }
                arg0->unk_30->unk_00.unk_24(arg0->unk_30, 1);
                var_v1 = 1;
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_88202394(unk_func_88201DA0* arg0, Controller* arg1) {
    s32 var_s0;
    s32 var_s1 = NULL;

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);

    while (var_s1 == 0) {
        func_8002EEA8(var_s1);
        var_s0 = func_88202254(arg0, arg1);
        if (!(var_s0 & 1) && (var_s0 & 2)) {
            var_s0 |= 1;
            var_s1 = 1;
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(var_s0);
    }
    arg0->unk_2C->unk_2C = 0xB;
}

void func_88202450(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88217C40 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char sp28[8];
    s32 sp24 = func_8001F5B0(4, 0, "00");
    UNUSED s32 pad;

    func_8001F3F4();
    func_8001EBE0(4, 0);
    func_8001F324(D_88217C40.r, D_88217C40.g, D_88217C40.b, D_88217C40.a);
    sprintf(sp28, "%d", arg0->unk_690);
    func_8001F1E8(((arg1 + sp24) - func_8001F5B0(0, 0, sp28)) + 0x1C, arg2 + 4, sp28);
    func_8001F444();
    if (arg0->unk_690 > 0) {
        func_8002D8C8(&D_800758E0, arg1, arg2 + 2);
    }
}

void func_8820253C(unk_func_8820253C* arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8820253C));

    arg0->unk_00.unk_18 = func_882025B4;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    func_882025AC(arg0, arg3);
}

void func_882025AC(unk_func_8820253C* arg0, unk_func_88205880_00D0* arg1) {
    arg0->unk_2C = arg1;
}

s32 func_882025B4(unk_func_8820253C* arg0, s32 arg1, s32 arg2) {
    if (arg0->unk_2C != NULL) {
        func_88202450(arg0->unk_2C, arg1, arg2);
    }
}

void func_882025E0(unk_func_882025E0_1A9780* arg0, unk_func_88200FA0_030_030* arg1, unk_func_88200FA0_030_030* arg2,
                   unk_func_88203ED8* arg3, MemoryPool* arg4) {
    static Color_RGBA8 D_88217C44 = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 i;
    char* temp_s2;

    ((func88500668)Memmap_GetFragmentVaddr(func_88500668))(arg0, sizeof(unk_func_882025E0_1A9780));

    arg0->unk_00.unk_14 = func_88202738;
    arg0->unk_00.unk_10 = func_88202F70;
    arg0->unk_00.unk_18 = 0;
    arg0->unk_00.unk_1C = 0;
    arg0->unk_24[0] = arg1;
    arg0->unk_24[1] = arg2;
    arg0->unk_38 = 1;
    arg0->unk_00.unk_20 = arg3;
    arg0->unk_2C = 0;

    for (i = 0; i < 5; i++) {
        temp_s2 = func_8002D7C0(NULL, 0, D_88224FA4, i + 6);

        arg0->unk_3C[i].unk_00 = mem_pool_alloc(arg4, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_3C[i].unk_00, 0, 0, temp_s2, 0x10);
        arg0->unk_3C[i].unk_00->unk_30 = D_88217C44;
        arg0->unk_3C[i].unk_00->unk_44 = arg0->unk_3C[i].unk_00->unk_44;
        arg0->unk_3C[i].unk_08 = 0;
        arg0->unk_3C[i].unk_04 = 0;
    }
}

void func_88202738(unk_func_882025E0_1A9780* arg0, s32 arg1) {
    arg0->unk_00.unk_18 = arg1;
    func_88202758(arg0);
}

void func_88202758(unk_func_882025E0_1A9780* arg0) {
    s32 i;
    s32 temp_s3 = arg0->unk_00.unk_18 & 0xFF;
    s32 temp_s4 = arg0->unk_00.unk_18 & 0xFF00;
    s32 var_v0;

    for (i = 0; i < 2; i++) {
        var_v0 = 0;
        if (i == arg0->unk_00.unk_1C) {
            var_v0 = 1;
        }
        arg0->unk_24[i]->unk_00.unk_24(&arg0->unk_24[i]->unk_00, (var_v0 & temp_s3) | temp_s4);
    }
}

void func_882027F0(unk_func_882025E0_1A9780* arg0, s32 arg1) {
    arg0->unk_00.unk_1C = arg1;
    func_88202758(arg0);
}

void func_88202810(unk_func_882025E0_1A9780* arg0, unk_func_88205880_00D0** arg1, unk_func_88205880_00D0** arg2) {
    switch (arg0->unk_2C) {
        case 0:
            *arg1 = arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_24[0]->unk_38];
            *arg2 = NULL;
            break;

        case 1:
            *arg1 = arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_34];
            *arg2 = arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_24[0]->unk_38];
            break;

        case 2:
            *arg1 = arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_24[0]->unk_38];
            *arg2 = arg0->unk_24[1]->unk_2C->unk_00[arg0->unk_24[1]->unk_38];
            break;
    }
}

void func_882028EC(unk_func_882025E0_1A9780* arg0, unk_func_88001300_000_010* arg1, unk_func_88001300_000_010* arg2) {
    switch (arg0->unk_2C) {
        case 0:
            arg1->unk_00 = arg0->unk_24[0]->unk_00.unk_10.unk_00;
            arg1->unk_02 = arg0->unk_24[0]->unk_00.unk_10.unk_02 + (arg0->unk_24[0]->unk_38 * arg0->unk_24[0]->unk_3E);

            arg2->unk_00 = arg0->unk_24[1]->unk_00.unk_10.unk_00;
            arg2->unk_02 = arg0->unk_24[1]->unk_00.unk_10.unk_02 + (arg0->unk_24[1]->unk_38 * arg0->unk_24[1]->unk_3E);
            break;

        case 1:
            arg1->unk_00 = arg0->unk_24[0]->unk_00.unk_10.unk_00;
            arg1->unk_02 = arg0->unk_24[0]->unk_00.unk_10.unk_02 + (arg0->unk_34 * arg0->unk_24[0]->unk_3E);

            arg2->unk_00 = arg0->unk_24[0]->unk_00.unk_10.unk_00;
            arg2->unk_02 = arg0->unk_24[0]->unk_00.unk_10.unk_02 + (arg0->unk_24[0]->unk_38 * arg0->unk_24[0]->unk_3E);
            break;

        case 2:
            arg1->unk_00 = arg0->unk_24[0]->unk_00.unk_10.unk_00;
            arg1->unk_02 = arg0->unk_24[0]->unk_00.unk_10.unk_02 + (arg0->unk_24[0]->unk_38 * arg0->unk_24[0]->unk_3E);

            arg2->unk_00 = arg0->unk_24[1]->unk_00.unk_10.unk_00;
            arg2->unk_02 = arg0->unk_24[1]->unk_00.unk_10.unk_02 + (arg0->unk_24[1]->unk_38 * arg0->unk_24[1]->unk_3E);
            break;
    }
}

void func_88202A2C(unk_func_88200FA0_030_030* arg0) {
    s32 i;
    s32 count = arg0->unk_2C->unk_08;
    unk_func_88205880_00D0** temp_v0 = arg0->unk_2C->unk_00;

    for (i = 0; i < count; i++) {
        if (temp_v0[i]->unk_690 == 0) {
            arg0->unk_34[i] |= 4;
        }
    }

    ((func88506CE4)Memmap_GetFragmentVaddr(func_88506CE4))(arg0);
}

void func_88202B74(unk_func_88200FA0_030_030* arg0) {
    s32 i;
    s32 count = arg0->unk_2C->unk_08;
    unk_func_88205880_00D0** temp_v0 = arg0->unk_2C->unk_00;

    for (i = 0; i < count; i++) {
        if (temp_v0[i]->unk_690 > 0) {
            arg0->unk_34[i] |= 4;
        }
    }

    ((func88506CE4)Memmap_GetFragmentVaddr(func_88506CE4))(arg0);
}

void func_88202CBC(unk_func_882025E0_1A9780* arg0) {
    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_24[0]);
    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_24[1]);

    switch (arg0->unk_2C) {
        case 0:
            func_88202A2C(arg0->unk_24[0]);
            func_88202B74(arg0->unk_24[1]);
            break;

        case 1:
        case 2:
        case 3:
            func_88202A2C(arg0->unk_24[0]);
            func_88202A2C(arg0->unk_24[1]);
            break;
    }
}

void func_88202D60(unk_func_882025E0_1A9780* arg0, s32 arg1) {
    switch (arg1) {
        case 0:
            func_88202CBC(arg0);
            func_88215974(arg0->unk_24[0], 1);
            func_88215974(arg0->unk_24[1], 1);
            func_882027F0(arg0, 0);
            func_88217BB8(arg0->unk_00.unk_20->unk_40);
            break;

        case 1:
            func_88215974(arg0->unk_24[1], 0);
            func_882027F0(arg0, 1);
            func_88217BAC(arg0->unk_00.unk_20->unk_40);
            break;

        case 2:
            func_88215974(arg0->unk_24[0], 0);
            func_882027F0(arg0, 0);
            func_88217BAC(arg0->unk_00.unk_20->unk_40);
            break;

        case 3:
            func_88215974(arg0->unk_24[1], 0);
            func_882027F0(arg0, 1);
            func_88217BAC(arg0->unk_00.unk_20->unk_40);
            break;
    }
    arg0->unk_30 = arg1;
}

void func_88202E74(unk_func_882025E0_1A9780* arg0, s32 arg1) {
    arg0->unk_2C = arg1;
    func_88202D60(arg0, 0);
}

void func_88202E98(unk_func_882025E0_1A9780* arg0) {
    func_88202D60(arg0, 0);
}

void func_88202EB8(unk_func_882025E0_1A9780* arg0) {
    unk_func_88200FA0_030_030* temp_t6 = arg0->unk_24[0];

    arg0->unk_24[0] = arg0->unk_24[1];
    arg0->unk_24[1] = temp_t6;

    arg0->unk_38 = !arg0->unk_38;
}

s32 func_88202ED8(unk_func_882025E0_1A9780* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_30 == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_88202EF4(unk_func_882025E0_1A9780* arg0) {
    unk_func_88205880_00D0** temp_v0 = &arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_34];
    unk_func_88205880_00D0** temp_a2 = &arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_24[0]->unk_38];
    unk_func_88205880_00D0* temp_a3;

    temp_a3 = *temp_a2;
    *temp_a2 = *temp_v0;
    *temp_v0 = temp_a3;
}

void func_88202F2C(unk_func_882025E0_1A9780* arg0) {
    unk_func_88205880_00D0* temp_a3;
    unk_func_88205880_00D0** temp_v0 = &arg0->unk_24[0]->unk_2C->unk_00[arg0->unk_24[0]->unk_38];
    unk_func_88205880_00D0** temp_a1 = &arg0->unk_24[1]->unk_2C->unk_00[arg0->unk_24[1]->unk_38];

    temp_a3 = *temp_a1;
    *temp_a1 = *temp_v0;
    *temp_v0 = temp_a3;
}

s32 func_88202F70(unk_func_882025E0_1A9780* arg0, Controller* arg1) {
    s32 var_a2;

    var_a2 = arg0->unk_24[arg0->unk_00.unk_1C]->unk_00.unk_20(arg0->unk_24[arg0->unk_00.unk_1C], arg1);

    if (var_a2 & 1) {
        return var_a2;
    }

    if (var_a2 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_a2 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_a2 = 0x80000004;
        }
    }

    switch (arg0->unk_30) {
        case 0:
            if (var_a2 & 2) {
                ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_00.unk_20->unk_6C->unk_24[0]);
                ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_00.unk_20->unk_6C->unk_24[1]);
            } else if (var_a2 & 4) {
                switch (arg0->unk_2C) {
                    case 0:
                        if (func_88201440(arg0->unk_24[0]->unk_2C) != 0) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                arg0->unk_00.unk_20->unk_60, arg0->unk_3C[0].unk_00, arg0->unk_3C[0].unk_04,
                                arg0->unk_3C[0].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_00.unk_20->unk_60, arg1);
                            var_a2 = 1;
                        } else if (func_882013F8(arg0->unk_24[1]->unk_2C) != 0) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                arg0->unk_00.unk_20->unk_60, arg0->unk_3C[4].unk_00, arg0->unk_3C[4].unk_04,
                                arg0->unk_3C[4].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_00.unk_20->unk_60, arg1);
                            var_a2 = 1;
                        } else {
                            arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 2;
                            func_88202D60(arg0, 1);
                            var_a2 |= 1;
                        }
                        break;

                    case 1:
                        if (func_88201440(arg0->unk_24[0]->unk_2C) != 0) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                arg0->unk_00.unk_20->unk_60, arg0->unk_3C[1].unk_00, arg0->unk_3C[1].unk_04,
                                arg0->unk_3C[1].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_00.unk_20->unk_60, arg1);
                            var_a2 = 1;
                        } else {
                            arg0->unk_34 = arg0->unk_24[0]->unk_38;
                            ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_24[0]);
                            arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 2;
                            func_88202D60(arg0, 2);
                            var_a2 |= 1;
                        }
                        break;

                    case 2:
                        if ((func_88201440(arg0->unk_24[0]->unk_2C) != 0) ||
                            (func_88201440(arg0->unk_24[1]->unk_2C) != 0)) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                arg0->unk_00.unk_20->unk_60, arg0->unk_3C[2].unk_00, arg0->unk_3C[2].unk_04,
                                arg0->unk_3C[2].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_00.unk_20->unk_60, arg1);
                            var_a2 = 1;
                        } else {
                            arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 2;
                            func_88202D60(arg0, 3);
                            var_a2 |= 1;
                        }
                        break;

                    case 3:
                        if (func_88201440(arg0->unk_24[0]->unk_2C) != 0) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                arg0->unk_00.unk_20->unk_60, arg0->unk_3C[3].unk_00, arg0->unk_3C[3].unk_04,
                                arg0->unk_3C[3].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_00.unk_20->unk_60, arg1);
                            var_a2 = 1;
                        }
                        break;
                }
            }
            break;

        case 1:
            if (var_a2 & 2) {
                func_88202D60(arg0, 0);
                var_a2 |= 1;
            } else if (var_a2 & 4) {
                arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 0x100;
            }
            break;

        case 2:
            if (var_a2 & 2) {
                func_88202D60(arg0, 0);
                var_a2 |= 1;
            } else if (var_a2 & 4) {
                if (arg0->unk_34 == arg0->unk_24[0]->unk_38) {
                    var_a2 = 0x80000101;
                } else {
                    arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 2;
                    arg0->unk_24[0]->unk_34[arg0->unk_34] |= 0x100;
                    arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 0x100;
                }
            }
            break;

        case 3:
            if (var_a2 & 2) {
                func_88202D60(arg0, 0);
                var_a2 |= 1;
            } else if (var_a2 & 4) {
                arg0->unk_24[1]->unk_34[arg0->unk_24[1]->unk_38] |= 2;
                arg0->unk_24[0]->unk_34[arg0->unk_24[0]->unk_38] |= 0x100;
                arg0->unk_24[1]->unk_34[arg0->unk_24[1]->unk_38] |= 0x100;
            }
            break;
    }
    return var_a2;
}

void func_88203538();
static Color_RGBA8 D_88217C48 = { 0xF0, 0xF0, 0xF0, 0xFF };
static Color_RGBA8 D_88217C4C = { 0x5A, 0x5A, 0xA6, 0xFF };
static Color_RGBA8 D_88217C50 = { 0x40, 0x40, 0x74, 0xFF };
static Color_RGBA8 D_88217C54 = { 0x78, 0x78, 0xF1, 0xFF };
static Color_RGBA8 D_88217C58 = { 0x5E, 0x5E, 0xBE, 0xFF };
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1A9780/func_88203538.s")

void func_8820399C(unk_func_8820399C* arg0, s32 arg1, unk_func_8850143C* arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8820399C));

    arg0->unk_00.unk_18 = func_88203A20;
    arg0->unk_00.unk_14.unk_00 = arg2->unk_00.unk_14.unk_00;
    arg0->unk_00.unk_14.unk_02 = arg2->unk_00.unk_14.unk_02;
    arg0->unk_2C = func_8002EC08(func_80024F68(func_80029080()));
    arg0->unk_30 = arg1;
}

s32 func_88203A20(unk_func_8820399C* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88217C5C = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* sp2C;
    s32 temp_v0;
    s32 var_s0;

    if (arg0->unk_30 == 0) {
        sp2C = func_8002D7C0(NULL, 0, D_88224FA4, 0xB);
    } else {
        sp2C = func_8002D7C0(NULL, 0, D_88224FA4, 0xC);
    }
    temp_v0 = func_8001F5B0(8, 0, sp2C);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    if (arg0->unk_30 == 0) {
        var_s0 = (((arg0->unk_00.unk_14.unk_00 - temp_v0) - 0x20) / 2) + arg1 + 0x20;

        gDPLoadTextureBlock(gDisplayListHead++, D_88223470[arg0->unk_2C], G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 26, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (var_s0 - 0x20) << 2, (arg2 + 2) << 2, (var_s0 - 9) << 2,
                            (arg2 + 0x1B) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    } else {
        var_s0 = (((arg0->unk_00.unk_14.unk_00 - temp_v0) - 0x30) / 2) + arg1 + 0x30;

        gDPLoadTextureBlock(gDisplayListHead++, D_88223488, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 26, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (var_s0 - 0x30) << 2, (arg2 + 2) << 2, (var_s0 - 9) << 2,
                            (arg2 + 0x1B) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

    func_8001F3F4();
    func_8001F324(D_88217C5C.r, D_88217C5C.g, D_88217C5C.b, D_88217C5C.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(var_s0, arg2 + 5, sp2C);
    func_8001F444();

    return 0;
}

#ifdef NON_MATCHING
void func_88203ED8(unk_func_88203ED8* arg0, s32 arg1, s32 arg2, unk_func_88205880_A030* arg3,
                   unk_func_88001300_000* arg4, unk_func_88201DA0* arg5, unk_D_800AC870* arg6, char** arg7,
                   MemoryPool* arg8) {
    static Color_RGBA8 D_88217C60 = { 0x6C, 0x6C, 0x7E, 0xFF };
    static Color_RGBA8 D_88217C64 = { 0x50, 0x50, 0x86, 0xFF };
    static Color_RGBA8 D_88217C68 = { 0x79, 0x79, 0xCB, 0xFF };
    static unk_D_88217C6C D_88217C6C[] = {
        {
            249,
            36,
            54,
            42,
            D_88218FD0,
            48,
            D_882181B8,
            0,
        },
        {
            249,
            84,
            54,
            42,
            D_88219D58,
            48,
            D_882181C0,
            1,
        },
        {
            249,
            132,
            54,
            42,
            D_8821AAE0,
            48,
            D_882181C8,
            0,
        },
        {
            249,
            180,
            54,
            42,
            D_8821B868,
            48,
            D_882181D0,
            1,
        },
        {
            249,
            228,
            54,
            42,
            D_88218248,
            48,
            D_882181B0,
            0,
        },
    };
    static Color_RGBA8 D_88217CE4 = { 0xFF, 0xFF, 0x00, 0xFF };
    static Color_RGBA8 D_88217CE8 = { 0x2D, 0x1A, 0x41, 0xFF };
    static Color_RGBA8 D_88217CEC = { 0x6F, 0x5F, 0x7F, 0xFF };
    static Color_RGBA8* D_88217CF0[5] = { D_882181F0, D_88218208, D_88218200, D_88218210, D_882181F8 };

    s32 i;
    s32 j;
    s32 x;
    s32 spB4;
    unk_func_885012A4* spA8;
    unk_func_885012A4* spA4;
    unk_func_885012A4* spA0;
    unk_func_885012A4* sp9C;
    unk_func_885012A4* sp98;
    unk_func_88001300_000* sp94;
    unk_func_88001300_000* sp90;
    unk_func_8850143C* sp8C;
    unk_func_8850143C* sp88;
    char* temp_s1_2;
    unk_func_88001300_03C_01C* temp_s0;
    unk_func_8850143C* temp_s0_2;
    unk_func_8850878C* temp_s0_3;
    unk_func_88503298* temp_s0_4;
    unk_D_88217C6C* ptr;
    unk_func_882149A0* ptr2;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88203ED8));
    arg0->unk_00.unk_1C = func_88204BA8;
    arg0->unk_00.unk_20 = func_88204C28;
    arg0->unk_00.unk_24 = func_88204BFC;
    // clang-format off
    arg0->unk_00.unk_10.unk_00 = arg1; arg0->unk_00.unk_10.unk_02 = arg2;
    // clang-format on
    arg0->unk_5C = arg5;

    arg0->unk_64 = mem_pool_alloc(arg8, sizeof(unk_func_88203ED8_064));
    func_88204DC0(arg0->unk_64, arg0);

    arg0->unk_2C = mem_pool_alloc(arg8, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, 0x228, 0x172);
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    sp98 = mem_pool_alloc(arg8, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp98, 0, 0, 0x228, 6, D_88217C60);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp98);

    sp9C = mem_pool_alloc(arg8, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp9C, 0, 0x138, 0x228, 6, D_88217C60);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp9C);

    spA0 = mem_pool_alloc(arg8, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spA0, 0, 6, 0xA, 0x132, D_88217C60);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spA0);

    spA4 = mem_pool_alloc(arg8, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spA4, 0x21E, 6, 0xA, 0x132, D_88217C60);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spA4);

    spA8 = mem_pool_alloc(arg8, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spA8, 0xF3, 6, 0x42, 0x132, D_88217C60);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spA8);

    sp90 = mem_pool_alloc(arg8, sizeof(unk_func_88001300_000));
    ((func8850AB48)Memmap_GetFragmentVaddr(func_8850AB48))(sp90, 8, 4, 0xED, 0x136);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp90);

    sp94 = mem_pool_alloc(arg8, sizeof(unk_func_88001300_000));
    ((func8850AB48)Memmap_GetFragmentVaddr(func_8850AB48))(sp94, 0x133, 4, 0xED, 0x136);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp94);

    sp88 = mem_pool_alloc(arg8, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(func_8850143C))(sp88, 0xA, 6, 0xE9, 0x1E, D_88217C64, D_88217C68);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp88);

    sp8C = mem_pool_alloc(arg8, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(func_8850143C))(sp8C, 0x135, 6, 0xE9, 0x1E, D_88217C64, D_88217C68);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp8C);

    arg0->unk_30 = mem_pool_alloc(arg8, sizeof(unk_func_8820399C));
    func_8820399C(arg0->unk_30, 0, sp88);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp88, arg0->unk_30);

    arg0->unk_34 = mem_pool_alloc(arg8, sizeof(unk_func_8820399C));
    func_8820399C(arg0->unk_34, 1, sp8C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp8C, arg0->unk_34);

    arg0->unk_40 = mem_pool_alloc(arg8, sizeof(unk_func_88217740));
    func_88217740(arg0->unk_40, 0xF4, 0xA);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_40);

    ptr = &D_88217C6C[0];
    for (i = 0; i < 5; i++, ptr++) {
        ptr2 = mem_pool_alloc(arg8, sizeof(unk_func_882149A0));
        arg0->unk_44[i] = ptr2;
        func_882149A0(ptr2, ptr->unk_00, ptr->unk_02, ptr->unk_04, ptr->unk_06, ptr->unk_08, ptr->unk_0C,
                      ptr->unk_10[0], ptr->unk_10[1], D_88217C60);
        if (ptr->unk_14 != 0) {
            func_882158BC(ptr2);
        }
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, ptr2);
    }

    arg0->unk_68 = mem_pool_alloc(arg8, sizeof(unk_func_88001300_03C));
    ((func8850C284)Memmap_GetFragmentVaddr(func_8850C284))(arg0->unk_68, 5, 1, arg8);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_64, arg0->unk_68);

    for (j = 0; j < 5; j++) {
        arg0->unk_68->unk_18[arg0->unk_68->unk_2C * j] = arg0->unk_44[j];
    }

    ((func8850CB48)Memmap_GetFragmentVaddr(func_8850CB48))(arg0->unk_68, 0);

    temp_s0 = mem_pool_alloc(arg8, sizeof(unk_func_88001300_03C_01C));
    ((func88503340)Memmap_GetFragmentVaddr(func_88503340))(temp_s0, 0, 0, 0x10, 0x10, D_88217CE4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s0);
    arg0->unk_68->unk_1C = temp_s0;

    temp_s0_2 = mem_pool_alloc(arg8, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(func_8850143C))(temp_s0_2, 0, 0x13E, 0x228, 0x34, D_88217CE8, D_88217CEC);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s0_2);

    arg0->unk_58 = mem_pool_alloc(arg8, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_58, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s0_2, arg0->unk_58);

    for (i = 0; i < 5; i++) {
        temp_s1_2 = func_8002D7C0(NULL, 0, D_88224FA4, i + 1);

        temp_s0_3 = mem_pool_alloc(arg8, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s0_3, (0x228 - func_8001F5B0(0, 0, temp_s1_2)) / 2,
                                                               0xE, temp_s1_2, 0x10);
        temp_s0_3->unk_30 = D_88217CF0[i][0];
        temp_s0_3->unk_34 = D_88217CF0[i][1];
        temp_s0_3->unk_44 = temp_s0_3->unk_44;
        temp_s0_3->unk_44 = 1;
        ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_58, temp_s0_3);
    }

    func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_88224FA4, 0x31));
    func_8001F5B0(8, 0, " 00");
    spB4 = func_8001F5B0(4, 0, "00");

    arg0->unk_38 = mem_pool_alloc(arg8, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_38, 0xA, 0x24, func_88203538, 0xE9, 0x17, 0xC, 1,
                                                           arg8);
    ((func88506384)Memmap_GetFragmentVaddr(func_88506384))(arg0->unk_38, &arg3[0], arg8);
    arg0->unk_38->unk_44->unk_00.unk_28 |= 0x100;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_38);

    arg0->unk_3C = mem_pool_alloc(arg8, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_3C, 0x135, 0x24, func_88203538, 0xE9, 0x17, 0xC, 1,
                                                           arg8);
    ((func88506384)Memmap_GetFragmentVaddr(func_88506384))(arg0->unk_3C, &arg3[1], arg8);
    arg0->unk_3C->unk_44->unk_00.unk_28 |= 0x100;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_3C);

    arg0->unk_6C = mem_pool_alloc(arg8, sizeof(unk_func_882025E0_1A9780));
    func_882025E0(arg0->unk_6C, arg0->unk_38, arg0->unk_3C, arg0, arg8);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_64, arg0->unk_6C);

    arg0->unk_70 = mem_pool_alloc(arg8, sizeof(unk_func_8850CD44));
    ((func8850CD44)Memmap_GetFragmentVaddr(func_8850CD44))(arg0->unk_70, 2, arg8);
    ((func8850CC74)Memmap_GetFragmentVaddr(func_8850CC74))(arg0->unk_64, arg0->unk_70);

    for (i = 0; i < 2; i++) {
        arg0->unk_74[i] = mem_pool_alloc(arg8, sizeof(unk_func_882173EC));
        func_882173EC(arg0->unk_74[i], 0, 0);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_74[i]);

        arg0->unk_7C[i] = mem_pool_alloc(arg8, sizeof(unk_func_8820253C));
        func_8820253C(arg0->unk_7C[i], 0xB4 - spB4, 0, 0);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_74[i], arg0->unk_7C[i]);

        arg0->unk_70->unk_1C[i] = arg0->unk_74[i];
    }

    temp_s0_4 = mem_pool_alloc(arg8, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(temp_s0_4, arg0->unk_2C, arg4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, temp_s0_4);

    arg0->unk_60 = mem_pool_alloc(arg8, sizeof(unk_func_88509F48));
    ((func88509F48)Memmap_GetFragmentVaddr(func_88509F48))(arg0->unk_60, 0, 0, 0x228, 0x172, arg8, arg6);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_60);

    arg0->unk_84 = mem_pool_alloc(arg8, sizeof(unk_func_889000C4));
    ((func889000C4)Memmap_GetFragmentVaddr(func_889000C4))(arg0->unk_84, 0, arg0->unk_2C, 0, arg7, arg8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_84);

    if (sp88) {}
    if (sp8C) {}
    if (sp90) {}
    if (sp94) {}
    if (sp98) {}
    if (sp9C) {}
    if (spA0) {}
    if (spA4) {}
    if (spA8) {}
}
#else
static Color_RGBA8 D_88217C60 = { 0x6C, 0x6C, 0x7E, 0xFF };
static Color_RGBA8 D_88217C64 = { 0x50, 0x50, 0x86, 0xFF };
static Color_RGBA8 D_88217C68 = { 0x79, 0x79, 0xCB, 0xFF };
static unk_D_88217C6C D_88217C6C[] = {
    {
        249,
        36,
        54,
        42,
        D_88218FD0,
        48,
        D_882181B8,
        0,
    },
    {
        249,
        84,
        54,
        42,
        D_88219D58,
        48,
        D_882181C0,
        1,
    },
    {
        249,
        132,
        54,
        42,
        D_8821AAE0,
        48,
        D_882181C8,
        0,
    },
    {
        249,
        180,
        54,
        42,
        D_8821B868,
        48,
        D_882181D0,
        1,
    },
    {
        249,
        228,
        54,
        42,
        D_88218248,
        48,
        D_882181B0,
        0,
    },
};
static Color_RGBA8 D_88217CE4 = { 0xFF, 0xFF, 0x00, 0xFF };
static Color_RGBA8 D_88217CE8 = { 0x2D, 0x1A, 0x41, 0xFF };
static Color_RGBA8 D_88217CEC = { 0x6F, 0x5F, 0x7F, 0xFF };
static Color_RGBA8* D_88217CF0[5] = { D_882181F0, D_88218208, D_88218200, D_88218210, D_882181F8 };
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1A9780/func_88203ED8.s")
#endif

s32 func_88204BA8(unk_func_88203ED8* arg0) {
    if (arg0->unk_64->unk_00.unk_1C == 0) {
        ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_58, arg0->unk_68->unk_24);
    }
    return 0;
}

void func_88204BFC(unk_func_88203ED8* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_64->unk_00.unk_14(arg0->unk_64, arg1);
}

s32 func_88204C28(unk_func_88203ED8* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_64->unk_00.unk_10(arg0->unk_64, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_88204C74(unk_func_88203ED8* arg0) {
    func_882158BC(arg0->unk_44[0]);
    func_882158BC(arg0->unk_44[1]);
    func_882158BC(arg0->unk_44[2]);
    func_882158BC(arg0->unk_44[3]);
}

void func_88204CBC(unk_func_88203ED8* arg0) {
    unk_func_88205880_00D0* sp34;
    unk_func_88205880_00D0* sp30;
    unk_func_88001300_000_010 sp2C;
    unk_func_88001300_000_010 sp28;

    func_88202810(arg0->unk_6C, &sp30, &sp34);
    func_882028EC(arg0->unk_6C, &sp2C, &sp28);

    func_882025AC(arg0->unk_7C[0], sp30);
    func_882175F4(arg0->unk_74[0], sp2C, sp28);

    if (sp34 != NULL) {
        func_882025AC(arg0->unk_7C[1], sp34);
        func_882175F4(arg0->unk_74[1], sp28, sp2C);
    }

    arg0->unk_6C->unk_00.unk_14(arg0->unk_6C, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(func_8850CF00))(arg0->unk_70, 0);

    arg0->unk_6C->unk_00.unk_14(arg0->unk_6C, 1);
}

void func_88204DC0(unk_func_88203ED8_064* arg0, unk_func_88203ED8* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(func_8850BDF0))(arg0);

    arg0->unk_00.unk_10 = func_882052F4;
    arg0->unk_24 = arg1;
}

u32 func_88204E0C(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    u32 sp90 = 0;
    unk_func_80022C28_ret* temp_v0 = func_80022C28(arg1, arg2, arg3, 0);
    unk_func_80026268_arg0* var_s1;
    unk_func_80026268_arg0 sp34;

    if (temp_v0 == NULL) {
        return 0;
    }

    var_s1 = arg0->unk_000;
    for (i = 0; i < arg0->unk_690; i++, var_s1++) {
        bzero(&sp34, sizeof(unk_func_80026268_arg0));
        func_80022E18(&sp34, 1, temp_v0);
        if (bcmp(&sp34, var_s1, sizeof(unk_func_80026268_arg0)) != 0) {
            sp90 = 1;
            break;
        }
    }

    func_80022D8C(temp_v0);
    return sp90;
}

s32 func_88204EE8(unk_func_88203ED8* arg0) {
    s32 i;
    s32 temp_s3 = func_80029080();
    s32 var_s2 = 0;
    u32 temp_v0;
    unk_func_88205880_00D0** var_s1;

    var_s1 = arg0->unk_38->unk_2C->unk_00;

    for (i = 0; i < 12; i++) {
        if ((var_s1[i]->unk_694 != 0x21) || (i != var_s1[i]->unk_698)) {
            if ((var_s1[i]->unk_690 != 0) || (func_8002EE1C(0x21, temp_s3, i) != 0)) {
                var_s2 |= 2;
                var_s1[i]->unk_69C = 1;
            }
        } else if (var_s1[i]->unk_69C != 0) {
            temp_v0 = func_88204E0C(var_s1[i], 0x21, temp_s3, i);
            var_s1[i]->unk_69C = temp_v0;
            if (temp_v0 != 0) {
                var_s2 |= 2;
            }
        }
    }

    var_s1 = arg0->unk_3C->unk_2C->unk_00;

    for (i = 0; i < 12; i++) {
        if ((var_s1[i]->unk_694 != 0x11) || (i != var_s1[i]->unk_698)) {
            if ((var_s1[i]->unk_690 != 0) || (func_8002EE1C(0x11, 0, i) != 0)) {
                var_s2 |= 4;
                var_s1[i]->unk_69C = 1;
            }
        } else if (var_s1[i]->unk_69C != 0) {
            temp_v0 = func_88204E0C(var_s1[i], 0x11, 0, i);
            var_s1[i]->unk_69C = temp_v0;
            if (temp_v0 != 0) {
                var_s2 |= 4;
            }
        }
    }

    return var_s2;
}

void func_8820508C(unk_func_88203ED8* arg0, s32 arg1) {
    s32 i;
    s32 temp_s3 = func_80029080();
    unk_func_88205880_00D0** var_s1;

    ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_84->unk_40, 2);
    func_8002EEA8(NULL);

    var_s1 = arg0->unk_38->unk_2C->unk_00;

    for (i = 0; i < 12; i++) {
        if (var_s1[i]->unk_69C != 0) {
            func_88201294(0x21, temp_s3, i, var_s1[i]);
            func_88201210(var_s1[i]);
        }
    }

    var_s1 = arg0->unk_3C->unk_2C->unk_00;

    for (i = 0; i < 12; i++) {
        if (var_s1[i]->unk_69C != 0) {
            func_88201294(0x11, 0, i, var_s1[i]);
        }
    }

    if (arg1 & 4) {
        func_800284B4(3);
    }

    if (arg1 & 2) {
        func_80025540(temp_s3);
        ((func88900970)Memmap_GetFragmentVaddr(func_88900970))(arg0->unk_84, temp_s3);
    }

    if (arg1 & 4) {
        func_80026E4C(3);
        func_800284B4(3);
    }
}

s32 func_882051EC(unk_func_88203ED8* arg0, Controller* arg1) {
    s32 sp24 = 1;
    s32 sp20 = func_88204EE8(arg0);
    s32 temp_v0_2;

    if (sp20 != 0) {
        arg0->unk_68->unk_14(arg0->unk_68, 0);
        ((func889006D4)Memmap_GetFragmentVaddr(func_889006D4))(arg0->unk_84, 0);
        temp_v0_2 = ((func88900808)Memmap_GetFragmentVaddr(func_88900808))(arg0->unk_84, arg1, 1);

        if (temp_v0_2 == 0) {
            func_8820508C(arg0, sp20);
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_84);
        } else if (temp_v0_2 == 1) {
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_84);
        } else if (temp_v0_2 == 2) {
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_84);
            sp24 = 0;
        }

        arg0->unk_68->unk_14(arg0->unk_68, 1);
    }

    return sp24;
}

#ifdef NON_MATCHING
// Did match but now broken due to merging structs on the func_8820213C call
s32 func_882052F4(unk_func_88203ED8_064* arg0, Controller* arg1) {
    s32 sp34;
    s32 tmp;
    s32 i;
    unk_func_88203ED8_064* var_a0;
    s32 sp24;
    s32 sp20;

    sp34 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_00.unk_00.unk_08;
        }
        sp34 = var_a0->unk_00.unk_10(var_a0, arg1);
    }

    if (sp34 & 1) {
        return sp34;
    }

    if (sp34 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            sp34 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            sp34 = 0x80000004;
        } else if (arg1->buttonPressed & 0x30) {
            sp34 = 0x01000000;
        }
    }

    if (sp34 & 2) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                func_80048B90(3);
                sp34 = 2;
                if (func_882051EC(arg0->unk_24, arg1) == 0) {
                    sp34 = 3;
                }
                break;

            case 1:
                ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 0);
                sp34 |= 1;
                break;
        }
    } else if (sp34 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                switch (arg0->unk_24->unk_68->unk_24) {
                    case 0:
                        func_88202E74(arg0->unk_24->unk_6C, 0);
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                        sp34 |= 1;
                        break;

                    case 1:
                        func_88202E74(arg0->unk_24->unk_6C, 1);
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                        sp34 |= 1;
                        break;

                    case 2:
                        func_88202E74(arg0->unk_24->unk_6C, 2);
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                        sp34 |= 1;
                        break;

                    case 3:
                        func_88202E74(arg0->unk_24->unk_6C, 3);
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                        sp34 |= 1;
                        break;

                    case 4:
                        func_80048B90(3);
                        sp34 = 2;
                        if (func_882051EC(arg0->unk_24, arg1) == 0) {
                            sp34 = 3;
                        }
                        break;
                }
                break;

            case 1:
                switch (arg0->unk_24->unk_68->unk_24) {
                    case 0:
                    case 2:
                        func_80048B90(0x18);
                        func_88204CBC(arg0->unk_24);
                        func_88202F2C(arg0->unk_24->unk_6C);
                        func_88202E98(arg0->unk_24->unk_6C);
                        sp34 = 0x80000081;
                        break;

                    case 1:
                        func_80048B90(0x18);
                        func_88204CBC(arg0->unk_24);
                        func_88202EF4(arg0->unk_24->unk_6C);
                        func_88202E98(arg0->unk_24->unk_6C);
                        sp34 = 0x80000081;
                        break;

                    case 3:
                        func_80048B90(2);
                        tmp = (arg0->unk_24->unk_6C->unk_38 != 0 ? 1 : 2) << 0x10;
                        func_8820213C(arg0->unk_24->unk_5C,
                                      &((unk_func_882025E0_1A9780*)arg0->unk_24->unk_6C)
                                           ->unk_24[0]
                                           ->unk_2C->unk_00[0]
                                           ->unk_000[arg0->unk_24->unk_6C->unk_24[0]->unk_38],
                                      tmp | arg0->unk_24->unk_6C->unk_24[0]->unk_38);

                        arg0->unk_24->unk_6C->unk_24[0]->unk_00.unk_24(arg0->unk_24->unk_6C->unk_24[0], 0x100);
                        func_88202394(arg0->unk_24->unk_5C, arg1);

                        arg0->unk_24->unk_6C->unk_24[0]->unk_00.unk_24(arg0->unk_24->unk_6C->unk_24[0], 1);
                        func_88202E98(arg0->unk_24->unk_6C);
                        sp34 = 1;
                        break;
                }
                break;
        }
    } else if (sp34 & 0x01000000) {
        sp34 = 1;
        sp24 = (arg1->buttonPressed & 0x20) != 0;
        sp20 = arg0->unk_24->unk_6C->unk_38;

        switch (arg0->unk_00.unk_1C) {
            case 0:
                sp20 = sp24;
                break;

            case 1:
                sp34 = 1;
                if (func_88202ED8(arg0->unk_24->unk_6C) != 0) {
                    sp20 = sp24;
                }
                break;
        }

        if (sp20 != arg0->unk_24->unk_6C->unk_38) {
            func_88202EB8(arg0->unk_24->unk_6C);
            if (arg0->unk_00.unk_1C == 1) {
                func_88202CBC(arg0->unk_24->unk_6C);
            }
            func_88204C74(arg0->unk_24);
            func_88217BC0(arg0->unk_24->unk_40);

            ((func8850BFB0)Memmap_GetFragmentVaddr(func_8850BFB0))(arg0);

            sp34 = 0x80000005;
        }
    }
    return sp34;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1A9780/func_882052F4.s")
#endif

void func_882057B4(unk_func_88203ED8* arg0, Controller* arg1) {
    s32 var_s1 = 0;
    s32 temp_v0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);

    while (var_s1 == 0) {
        func_8002EEA8(NULL);

        temp_v0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(temp_v0 & 1) && (temp_v0 & 2)) {
            var_s1 = 1;
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(temp_v0);
    }

    arg0->unk_2C->unk_2C = 0xB;
}

void func_88205880(unk_func_88205880* arg0, s32 arg1, s32 arg2, unk_D_800AC870* arg3, MemoryPool* arg4, char** arg5,
                   char** arg6, char** arg7, char** arg8, char** arg9, char** argA, char** argB, char** argC) {
    static Color_RGBA8 D_88217D04 = { 0x1E, 0x50, 0x50, 0xFF };
    static Color_RGBA8 D_88217D08 = { 0x00, 0x0A, 0x0A, 0xFF };

    unk_func_88001300_000* sp7C;
    unk_func_88001300_000* sp78;
    unk_func_88001300_000* sp74;
    FragmentEntry sp70;
    s32 i;
    UNUSED s32 pad[2];
    s32 sp60;
    unk_func_88500EE4* sp5C;
    unk_func_885088F4* sp58;
    unk_func_88509A2C* sp54;
    unk_func_88509E34* sp50;

    sp60 = func_80029080();
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88205880));
    arg0->unk_0000.unk_20 = func_88205DD0;
    arg0->unk_0000.unk_10.unk_00 = arg1;
    arg0->unk_0000.unk_10.unk_02 = arg2;

    if (func_8002513C(sp60) == 0) {
        func_80024208(sp60);
    }

    func_88201360(arg0->unk_00D0, 0x21, sp60, 0xC);
    func_88201360(arg0->unk_5050, 0x11, 0, 0xC);

    for (i = 0; i < 12; i++) {
        arg0->unk_9FD0[i] = &arg0->unk_00D0[i];
    }

    for (i = 0; i < 12; i++) {
        arg0->unk_A000[i] = &arg0->unk_5050[i];
    }

    func_8002CBB0(&arg0->unk_A030[0], arg0->unk_9FD0, 0xC, 0xC);
    func_8002CBB0(&arg0->unk_A030[1], arg0->unk_A000, 0xC, 0xC);

    sp7C = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func885031E8)Memmap_GetFragmentVaddr(func_885031E8))(sp7C, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, sp7C);

    sp5C = mem_pool_alloc(arg4, sizeof(unk_func_88500EE4));
    ((func88500EE4)Memmap_GetFragmentVaddr(func_88500EE4))(sp5C, 0, 0, 0x280, 0x1E0, D_88223E48, D_88217D04,
                                                           D_88217D08);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp7C, sp5C);

    sp58 = mem_pool_alloc(arg4, sizeof(unk_func_885088F4));
    ((func885088F4)Memmap_GetFragmentVaddr(func_885088F4))(sp58, 0x41, 0x15C, 0xDC);
    sp58->unk_2C = 5;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp7C, sp58);

    sp54 = mem_pool_alloc(arg4, sizeof(unk_func_88509A2C));
    ((func88509A2C)Memmap_GetFragmentVaddr(func_88509A2C))(sp54, 0x38, 0x22, func_80029080(),
                                                           func_8002D7C0(NULL, 0, D_88224FA0, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp58, sp54);

    sp50 = mem_pool_alloc(arg4, sizeof(unk_func_88509E34));
    ((func88509E34)Memmap_GetFragmentVaddr(func_88509E34))(sp50, 0, 0, func_8002D7C0(NULL, 0, D_88224FA4, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp58, sp50);

    sp78 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func885031E8)Memmap_GetFragmentVaddr(func_885031E8))(sp78, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, sp78);

    sp74 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func885031E8)Memmap_GetFragmentVaddr(func_885031E8))(sp74, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, sp74);

    sp70 = FRAGMENT_LOAD(fragment27);

    arg0->unk_0098.unk_04 = arg4;
    // clang-format off
    arg0->unk_0098.unk_00 = 0x38; arg0->unk_0098.unk_02 = 0x52;
    // clang-format on
    arg0->unk_0098.unk_14 = sp74;
    arg0->unk_0098.unk_18 = NULL;
    arg0->unk_0098.unk_1C = arg6;
    arg0->unk_0098.unk_20 = arg7;
    arg0->unk_0098.unk_24 = arg8;
    arg0->unk_0098.unk_28 = arg9;
    arg0->unk_0098.unk_2C = argA;
    arg0->unk_0098.unk_30 = argB;
    arg0->unk_0098.unk_34 = argC;

    sp70(0, &arg0->unk_0098);

    arg0->unk_0094 = mem_pool_alloc(arg4, sizeof(unk_func_88201DA0));
    func_88201DA0(arg0->unk_0094, 0x37, 0x52, sp78, sp70, &arg0->unk_0098, arg4);

    arg0->unk_002C = mem_pool_alloc(arg4, sizeof(unk_func_88203ED8));
    func_88203ED8(arg0->unk_002C, 0x2C, 0x4C, &arg0->unk_A030, sp7C, arg0->unk_0094, arg3, arg5, arg4);

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp78, arg0->unk_002C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp74, arg0->unk_0094);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_0098.unk_08);
}

s32 func_88205DD0(unk_func_88205880* arg0, Controller* arg1) {
    return arg0->unk_002C->unk_00.unk_20(arg0->unk_002C, arg1);
}

void func_88205DF8(unk_func_88205880* arg0) {
    s32 sp34 = 0;

    while (sp34 == 0) {
        func_800079C4();

        ((func885008C4)Memmap_GetFragmentVaddr(func_885008C4))(arg0);
        ((func88500828)Memmap_GetFragmentVaddr(func_88500828))(arg0, 0, 0);

        func_80007778();
        func_8002EF18(&sp34);
    }
}

void func_88205E94(unk_func_88205880* arg0) {
    func_8001F738(gPlayer1Controller);
    func_882057B4(arg0->unk_002C, gPlayer1Controller);

    while (arg0->unk_002C->unk_2C->unk_00.unk_28 & 1) {
        func_8002EEA8(NULL);
    }

    func_8002EEA8(1);
    osStopThread(NULL);
}

void func_88205F1C(unk_D_800AC870* arg0) {
    MemoryPool* sp6C;
    unk_func_88205880* sp68;
    u8* sp64;
    func_88002628_sp38* sp60;
    char** sp5C;
    char** sp58;
    char** sp54;
    char** sp50;
    char** sp4C;
    char** sp48;
    char** sp44;
    char** sp40;

    main_pool_push_state('BXPC');

    FRAGMENT_LOAD(fragment25);

    func_8001B058();
    sp64 = main_pool_alloc(0x1000, 0);
    sp6C = mem_pool_try_init(0x10000, 0);
    func_8002D510();
    D_88224FA0 = func_8002D5AC(0x2A);
    D_88224FA4 = func_8002D5AC(4);
    sp5C = func_8002D5AC(7);
    sp58 = func_8002D5AC(6);
    sp54 = func_8002D5AC(0x24);
    sp50 = func_8002D5AC(0x25);
    sp4C = func_8002D5AC(0x26);
    sp48 = func_8002D5AC(0x28);
    sp44 = func_8002D5AC(0x29);
    sp40 = func_8002D5AC(0xB);

    sp68 = mem_pool_alloc(sp6C, sizeof(unk_func_88205880));
    func_88205880(sp68, 0, 0, arg0, sp6C, sp5C, sp58, sp54, sp50, sp4C, sp48, sp44, sp40);

    sp60 = ALIGN16((u32)mem_pool_alloc(sp6C, sizeof(func_88002628_sp38)));

    osCreateThread(&sp60->thread, 0x32, func_88205E94, sp68, sp64 + 0x1000, osGetThreadPri(NULL) - 1);

    func_8002EE78();

    osStartThread(&sp60->thread);

    func_88205DF8(sp68);

    osDestroyThread(&sp60->thread);

    main_pool_pop_state('BXPC');
}
