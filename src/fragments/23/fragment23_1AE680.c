#include "fragment23.h"
#include "src/12D80.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/2D340.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/hal_libc.h"
#include "src/fragments/25/fragment25.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef void (*ThreadEntries)(unk_func_8820BE14*);

typedef struct unk_D_88217D10 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
} unk_D_88217D10; // size = 0xC

typedef struct unk_D_88217E40 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8* unk_10;
} unk_D_88217E40; // size = 0x14

typedef struct unk_D_88217EA4 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8* unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ Color_RGBA8* unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u16 unk_18;
} unk_D_88217EA4; // size = 0x1C

void func_8820C5BC(unk_func_8820BE14*);
void func_8820C63C(unk_func_8820BE14*);
void func_88207C54(unk_func_8820B12C_02C*);
s32 func_8820ADEC(unk_func_8820BE14_02C*);
void func_88207C34(unk_func_8820B12C_02C*, s32);
void func_88207D0C(unk_func_8820B12C_02C*, s32);
s32 func_88208600(unk_func_8820B12C_02C*, Controller*);
s32 func_8820AF78(unk_func_8820BE14_02C*, Controller*);
void func_8820B0A0(unk_func_8820BE14_02C*, s32);
void func_8820B12C(unk_func_8820B12C*, unk_func_8820BE14_02C*);
s32 func_8820B838(unk_func_8820B12C*, Controller*);
void func_88207A54(unk_func_882079D8* arg0, unk_func_88205880_00D0* arg1);
s32 func_88207A5C(unk_func_882079D8*, s32, s32);
s32 func_88206F44(unk_func_8820BE14_02C_078*, Controller*);
s32 func_88208CE4(unk_func_88208C5C*, s32, s32);
void func_88209A88(unk_func_8820BE14_02C_070* arg0, unk_func_88205880_00D0* arg1);
s32 func_8820938C(unk_func_8820BE14_02C_070*, s32, s32);

static char** D_88224FB0;
static char** D_88224FB4;
static char** D_88224FB8;
static char** D_88224FBC;

#ifdef NON_MATCHING
void func_88206110(unk_func_8820BE14_sp* arg0) {
    static unk_D_88217D10 D_88217D10[2][9] = {
        {
            { 1, 0x87, 0x21, 0x2D, 0, 0 },
            { 4, 0x87, 0xA, 0x2D, 0, 0 },
            { 7, 0x87, 0x21, 0x27, 0, 0 },
            { 0x6A, 0x1F40, 0x18, 0x60, 0, 0 },
            { 0x6B, 0x1F40, 4, 0x61, 0, 0 },
            { 0x85, 0x3D09, 0x21, 0x1C, 0, 0 },
            { 0x8A, 0x1F40, 0x37, 0x6E, 0, 0 },
            { 0x8C, 0x1F40, 0xA, 0x6A, 0, 0 },
            { 0x36, 0xD2F, 0xA, 0x85, 0, 0 },
        },
        {
            { 1, 0x87, 0x21, 0x2D, 0, 0 },
            { 4, 0x87, 0xA, 0x2D, 0, 0 },
            { 7, 0x87, 0x21, 0x27, 0, 0 },
            { 0x6A, 0x1F40, 0x18, 0x60, 0, 0 },
            { 0x6B, 0x1F40, 4, 0x61, 0, 0 },
            { 0x85, 0x3D09, 0x21, 0x27, 0, 0 },
            { 0x8A, 0x1F40, 0x37, 0x6E, 0, 0 },
            { 0x8C, 0x1F40, 0xA, 0x6A, 0, 0 },
            { 0x36, 0xD2F, 0xA, 0x85, 0, 0 },
        },
    };

    s32 i;
    s32 var_a2;
    unk_D_88217D10* var_v0;
    unk_D_88217D10* temp_a1;

    bzero(arg0, sizeof(unk_func_8820BE14_sp));

    arg0->unk_00 = func_8002816C();
    if (func_80024F68(func_80029080()) == 7) {
        var_a2 = 1;
    } else {
        var_a2 = 0;
    }

    temp_a1 = D_88217D10[var_a2];

    for (i = 0, var_v0 = temp_a1; i < 9; i++, var_v0++) {
        if (var_v0->unk_00 == arg0->unk_00) {
            break;
        }
    }

    if (i == 9) {
        i = 0;
        var_v0 = D_88217D10[var_a2];
    }

    arg0->unk_10 = var_v0->unk_04;
    arg0->unk_09 = temp_a1[i].unk_08;
    arg0->unk_0A = temp_a1[i].unk_09;
    arg0->unk_0B = temp_a1[i].unk_0A;
    arg0->unk_0C = temp_a1[i].unk_0B;

    arg0->unk_0E = 0x7D0;
    arg0->unk_14 = 0;
    arg0->unk_16 = 0;
    arg0->unk_18 = 0;
    arg0->unk_1A = 0;
    arg0->unk_1C = 0;

    arg0->unk_1E = guRandom();

    arg0->unk_06 = D_80070FA0[arg0->unk_00 - 1].unk_06;
    arg0->unk_07 = D_80070FA0[arg0->unk_00 - 1].unk_07;

    func_80022734(arg0);

    arg0->unk_04 = arg0->unk_24;

    HAL_Strcpy(arg0->unk_30, func_8002D7C0(NULL, 0, D_88224FB8, arg0->unk_00 - 1));
    HAL_Strcpy(arg0->unk_3B, func_8002D7C0(NULL, 0, D_88224FB4, 0x17));

    func_800228B0(arg0);

    if (func_8002816C() & 0x100) {
        arg0->unk_08 = 0xA8;
    } else {
        arg0->unk_08 = 0xA7;
    }

    arg0->unk_52 = 0;
    arg0->unk_53 = 0;
    arg0->unk_25 = 0;
}
#else
static unk_D_88217D10 D_88217D10[2][9] = {
    {
        { 1, 0x87, 0x21, 0x2D, 0, 0 },
        { 4, 0x87, 0xA, 0x2D, 0, 0 },
        { 7, 0x87, 0x21, 0x27, 0, 0 },
        { 0x6A, 0x1F40, 0x18, 0x60, 0, 0 },
        { 0x6B, 0x1F40, 4, 0x61, 0, 0 },
        { 0x85, 0x3D09, 0x21, 0x1C, 0, 0 },
        { 0x8A, 0x1F40, 0x37, 0x6E, 0, 0 },
        { 0x8C, 0x1F40, 0xA, 0x6A, 0, 0 },
        { 0x36, 0xD2F, 0xA, 0x85, 0, 0 },
    },
    {
        { 1, 0x87, 0x21, 0x2D, 0, 0 },
        { 4, 0x87, 0xA, 0x2D, 0, 0 },
        { 7, 0x87, 0x21, 0x27, 0, 0 },
        { 0x6A, 0x1F40, 0x18, 0x60, 0, 0 },
        { 0x6B, 0x1F40, 4, 0x61, 0, 0 },
        { 0x85, 0x3D09, 0x21, 0x27, 0, 0 },
        { 0x8A, 0x1F40, 0x37, 0x6E, 0, 0 },
        { 0x8C, 0x1F40, 0xA, 0x6A, 0, 0 },
        { 0x36, 0xD2F, 0xA, 0x85, 0, 0 },
    },
};
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1AE680/func_88206110.s")
#endif

s32 func_882062E4(unk_func_882062E4* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 sp1C = 0;
    unk_func_80022C28_ret* sp18;

    sp18 = func_80022C28(arg2, arg3, arg4, 0);
    if (sp18 != NULL) {
        sp1C = func_80022E18(arg0, arg1, sp18);
        func_80022D8C(sp18);
    }
    return sp1C;
}

static Color_RGBA8 D_88217DE8 = { 0xF0, 0xF0, 0xF0, 0xFF };
static Color_RGBA8 D_88217DEC = { 0xF0, 0xF0, 0xF0, 0x4D };
static Color_RGBA8 D_88217DF0 = { 0xF0, 0xF0, 0x00, 0xFF };
static Color_RGBA8 D_88217DF4 = { 0x6C, 0x6C, 0x7E, 0xFF };

void func_8820634C();
// const char D_88224E90[] = "%d";
// const char D_88224E94[] = " 00";
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1AE680/func_8820634C.s")

static u8 D_88217DF8[] = {
    0x18,
    0x19,
    0x1A,
};
static Color_RGBA8 D_88217DFC = { 0xF0, 0xF0, 0xF0, 0xFF };
static Color_RGBA8 D_88217E00 = { 0xF0, 0xF0, 0xF0, 0x4D };
static Color_RGBA8 D_88217E04 = { 0xF0, 0xF0, 0x00, 0xFF };
static Color_RGBA8 D_88217E08 = { 0x6C, 0x6C, 0x7E, 0xFF };

void func_8820660C();
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1AE680/func_8820660C.s")

s32 func_88206868(unk_func_8820BE14_02C_078_034* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_882068B4(unk_func_88001300_034* arg0, Controller* arg1) {
    s32 var_s0;
    s32 var_s1 = 0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);

    while (var_s1 == 0) {
        func_8002EEA8(var_s1);

        var_s0 = arg0->unk_00.unk_20(arg0, arg1);

        if (!(var_s0 & 1)) {
            if (arg1->buttonPressed & 0x4000) {
                var_s0 = 0x80000003;
                var_s1 = 1;
            } else if (arg1->buttonPressed & 0x8000) {
                var_s0 = 0x80000005;
                var_s1 = 2;
            }
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(var_s0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s1 - 1;
}

s32 func_882069C0(void) {
    s32 tmp;
    s32 sp18;

    sp18 = func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_88224FB4, 0x41));
    tmp = func_8001F5B0(8, 0, " 00");

    return sp18 + tmp + 0x3D;
}

void func_88206A20(unk_func_8820BE14_02C_078_034* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    s32 sp4C = func_882069C0() + 0x10;
    UNUSED s32 pad[2];

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(&arg0->unk_00, sizeof(unk_func_8820BE14_02C_078_034));

    arg0->unk_00.unk_20 = func_88206868;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, sp4C, 0x120);

    arg0->unk_2C->unk_28 |= 0x200;
    arg0->unk_2C->unk_28 |= 0x400;
    arg0->unk_2C->unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_30, 0, 0, func_8820634C, sp4C, 0x18, 0xC, 1, arg3);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_30, 0xC, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_30);
}

s32 func_88206BA0(void) {
    static u8 D_88217E0C[3] = { 0x18, 0x19, 0x1A };

    s32 i;
    s32 var_v1;
    s32 var_s1 = 0;

    for (i = 0; i < 3; i++) {
        var_v1 = func_8001F5B0(8, 0, func_8002D7C0(NULL, 0, D_88224FB4, D_88217E0C[i]));

        if (i == 0) {
            var_v1 += 0x3D;
        }

        if (var_s1 < var_v1) {
            var_s1 = var_v1;
        }
    }

    return var_s1;
}

void func_88206C4C(unk_func_8820BE14_02C_078* arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_8820BE14_06C_000* arg4,
                   s32 arg5, MemoryPool* arg6) {
    UNUSED s32 pad;
    s32 sp48 = func_88206BA0() + 0x10;
    UNUSED s32 pad2;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(&arg0->unk_00, sizeof(unk_func_8820BE14_02C_078));

    arg0->unk_00.unk_20 = func_88206F44;
    arg0->unk_00.unk_10.unk_00 = ((arg3 - sp48) / 2) + arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_4C = arg5;
    arg0->unk_2C = mem_pool_alloc(arg6, sizeof(unk_func_88001300_038));

    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, sp48, 0x54);
    arg0->unk_2C->unk_28 |= 0x200;
    arg0->unk_2C->unk_28 |= 0x400;
    arg0->unk_2C->unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00, arg0->unk_2C);

    func_8002C740(&arg0->unk_38, arg4, 0x10, 3, 3);

    arg0->unk_30 = mem_pool_alloc(arg6, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_30, 0, 0, func_8820660C, sp48, 0x1C, 3, 1, arg6);
    ((func88506404)Memmap_GetFragmentVaddr(func_88506404))(arg0->unk_30, &arg0->unk_38, arg6);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_30);

    arg0->unk_34 = mem_pool_alloc(arg6, sizeof(unk_func_8820BE14_02C_078_034));
    func_88206A20(arg0->unk_34, 0x9C, 0x1C, arg6);

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_34);

    arg0->unk_48 = 0;
}

u32 func_88206E50(unk_func_8820BE14_02C_078* arg0) {
    return ((arg0->unk_30->unk_38 == 0) ? 0 : arg0->unk_34->unk_30->unk_38) | (arg0->unk_30->unk_38 << 0x10);
}

void func_88206E80(unk_func_8820BE14_02C_078* arg0, u32 arg1) {
    arg0->unk_50 = arg1 >> 0x10;
    arg0->unk_54 = arg1 & 0xFFFF;

    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_30);
    ((func88506BFC)Memmap_GetFragmentVaddr(func_88506BFC))(arg0->unk_30, arg0->unk_50);

    if (arg0->unk_50 == 0) {
        arg0->unk_30->unk_34[arg0->unk_30->unk_38] |= 0x100;
    }
}

void func_88206F0C(unk_func_8820BE14_02C_078* arg0, u32 arg1) {
    arg0->unk_58 = arg1 >> 0x10;
    arg0->unk_5C = arg1 & 0xFFFF;

    if (arg0->unk_58 == 0) {
        arg0->unk_30->unk_34[arg0->unk_58] |= 4;
    }
}

s32 func_88206F44(unk_func_8820BE14_02C_078* arg0, Controller* arg1) {
    s32 var_v1;
    s32 sp20;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);

        if (!(var_v1 & 1)) {
            if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            } else if (arg1->buttonPressed & 0x8000) {
                if (arg0->unk_30->unk_38 == 0) {
                    var_v1 = 0x80000004;
                } else {
                    sp20 = 0;

                    ((func885063B8)Memmap_GetFragmentVaddr(func_885063B8))(arg0->unk_34->unk_30,
                                                                           &arg0->unk_38.unk_00[arg0->unk_30->unk_38]);

                    if (arg0->unk_4C != 0) {
                        arg0->unk_34->unk_00.unk_10.unk_00 = -arg0->unk_34->unk_2C->unk_14;
                    } else {
                        arg0->unk_34->unk_00.unk_10.unk_00 = arg0->unk_2C->unk_14;
                    }

                    arg0->unk_34->unk_00.unk_10.unk_02 = 8;
                    if (arg0->unk_50 == arg0->unk_30->unk_38) {
                        arg0->unk_34->unk_30->unk_34[arg0->unk_54] |= 0x100;
                        sp20 = arg0->unk_54;
                    }

                    if (arg0->unk_58 == arg0->unk_30->unk_38) {
                        arg0->unk_34->unk_30->unk_34[arg0->unk_5C] |= 4;
                        if ((sp20 == 0) && (arg0->unk_5C == 0)) {
                            sp20 = 1;
                        }
                    }

                    ((func88506BFC)Memmap_GetFragmentVaddr(func_88506BFC))(arg0->unk_34->unk_30, sp20);

                    func_80048B90(2);

                    arg0->unk_00.unk_24(&arg0->unk_00, 0x100);

                    if (func_882068B4(arg0->unk_34, arg1) == 1) {
                        var_v1 = 4;
                    } else {
                        var_v1 = 1;
                    }
                    arg0->unk_00.unk_24(&arg0->unk_00, 1);
                }
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_88207154(unk_func_8820BE14_02C_078* arg0, Controller* arg1) {
    s32 var_s0;
    s32 var_s1 = 0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);

    while (var_s1 == 0) {
        func_8002EEA8(var_s1);

        var_s0 = arg0->unk_00.unk_20(arg0, arg1);
        if (!(var_s0 & 1)) {
            if (var_s0 & 2) {
                var_s0 |= 1;
                var_s1 = 1;
            } else if (var_s0 & 4) {
                var_s0 |= 1;
                var_s1 = 2;
            }
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(var_s0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s1 - 1;
}

void func_8820723C(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3) {
    static Color_RGBA8 D_88217E10 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88217E14 = { 0x5A, 0x5A, 0xA6, 0xFF };

    s32 temp_v1;

    func_8001F3F4();
    func_8001F324(D_88217E10.r, D_88217E10.g, D_88217E10.b, D_88217E10.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(arg1 + 0x14, arg2 + 4, arg0->unk_000[0].unk_30);
    func_8001EBE0(4, 0);

    temp_v1 = func_8001F5B0(0, 0, "L100");

    if ((arg0->unk_000[0].unk_00 <= 0) || (arg0->unk_000[0].unk_00 >= 0x98)) {
        func_8001F1E8(((arg1 + arg3) - temp_v1) - 0x14, arg2 + 8, "L?");
    } else {
        func_8001F1E8(((arg1 + arg3) - temp_v1) - 0x14, arg2 + 8, "L%d", arg0->unk_000[0].unk_24);
    }
    func_8001F444();
}

static Color_RGBA8 D_88217E18 = { 0x40, 0x40, 0x74, 0xFF };
static Color_RGBA8 D_88217E1C[] = {
    { 0x78, 0x78, 0xF1, 0xFF },
    { 0x5E, 0x5E, 0xBE, 0xFF },
    { 0xFF, 0xCB, 0xDE, 0xFF },
    { 0xFF, 0xBF, 0xD6, 0xFF },
};

void func_88207354();
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1AE680/func_88207354.s")

void func_882079D8(unk_func_882079D8* arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_88205880_00D0* arg4) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(&arg0->unk_00, sizeof(unk_func_882079D8));

    arg0->unk_00.unk_18 = func_88207A5C;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = 0;

    func_88207A54(arg0, arg4);
}

void func_88207A54(unk_func_882079D8* arg0, unk_func_88205880_00D0* arg1) {
    arg0->unk_2C = arg1;
}

s32 func_88207A5C(unk_func_882079D8* arg0, s32 arg1, s32 arg2) {
    if (arg0->unk_2C != NULL) {
        func_8820723C(arg0->unk_2C, arg1, arg2, arg0->unk_00.unk_14.unk_00);
    }
}

void func_88207A94(unk_func_8820B12C_02C* arg0, unk_func_8820B12C_02C_020* arg1, unk_func_8820B12C_02C_020* arg2,
                   unk_func_88217740* arg3, unk_func_88509F48* arg4, s32 arg5, MemoryPool* arg6) {
    static Color_RGBA8 D_88217E2C = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 i;

    ((func88500668)Memmap_GetFragmentVaddr(func_88500668))(arg0, sizeof(unk_func_8820B12C_02C));

    arg0->unk_14 = func_88207C34;
    arg0->unk_10 = func_88208600;
    arg0->unk_18 = 0;
    arg0->unk_1C = 0;
    arg0->unk_20[0] = arg1;
    arg0->unk_20[1] = arg2;
    arg0->unk_34 = 1;
    arg0->unk_38 = arg3;
    arg0->unk_3C = arg4;
    arg0->unk_74 = arg5;

    func_88207D0C(arg0, 0);

    for (i = 0; i < 6; i++) {
        arg0->unk_5C[i] = mem_pool_alloc(arg6, sizeof(unk_func_8850878C));

        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_5C[i], 0, 0,
                                                               func_8002D7C0(NULL, 0, D_88224FB4, i + 0xB), 0x10);

        arg0->unk_5C[i]->unk_30 = D_88217E2C;
        arg0->unk_5C[i]->unk_44 = arg0->unk_5C[i]->unk_44;
    }
}

void func_88207BFC(unk_func_8820B12C_02C* arg0, s32 arg1) {
    arg0->unk_48->unk_18 = arg1;
    arg0->unk_44(2, arg0->unk_48);
}

void func_88207C34(unk_func_8820B12C_02C* arg0, s32 arg1) {
    arg0->unk_18 = arg1;
    func_88207C54(arg0);
}

void func_88207C54(unk_func_8820B12C_02C* arg0) {
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_v0;
    s32 i;
    s32 var_v0;
    unk_func_8820B12C_02C* var_s1;
    unk_func_8820B12C_02C_020* temp_a0;

    temp_v0 = arg0->unk_18;
    temp_s3 = temp_v0 & 0xFF;
    temp_s4 = temp_v0 & 0xFF00;

    for (i = 0; i < 2; i++) {
        var_v0 = 0;
        if (i == arg0->unk_1C) {
            var_v0 = 1;
        }
        arg0->unk_20[i]->unk_00.unk_00.unk_24(&arg0->unk_20[i]->unk_00, (var_v0 & temp_s3) | temp_s4);
    }
}

void func_88207CEC(unk_func_8820B12C_02C* arg0, s32 arg1) {
    arg0->unk_1C = arg1;
    func_88207C54(arg0);
}

void func_88207D0C(unk_func_8820B12C_02C* arg0, s32 arg1) {
    arg0->unk_28 = arg1;
    arg0->unk_2C = 0;
}

void func_88207D18(unk_func_8820B12C_02C* arg0) {
    unk_func_8820B12C_02C_020* temp_t6 = arg0->unk_20[0];

    arg0->unk_20[0] = arg0->unk_20[1];
    arg0->unk_20[1] = temp_t6;
    arg0->unk_34 = !arg0->unk_34;
}

void func_88207D38(unk_func_8820B12C_02C* arg0, unk_func_88205880_00D0** arg1, unk_func_88205880_00D0** arg2) {
    switch (arg0->unk_28) {
        case 0:
        case 3:
            *arg1 = arg0->unk_20[0]->unk_00.unk_2C->unk_00[arg0->unk_20[0]->unk_00.unk_38];
            *arg2 = NULL;
            break;

        case 1:
            *arg1 = arg0->unk_20[0]->unk_00.unk_2C->unk_00[arg0->unk_30];
            *arg2 = arg0->unk_20[0]->unk_00.unk_2C->unk_00[arg0->unk_20[0]->unk_00.unk_38];
            break;

        case 2:
            *arg1 = arg0->unk_20[0]->unk_00.unk_2C->unk_00[arg0->unk_20[0]->unk_00.unk_38];
            *arg2 = arg0->unk_20[1]->unk_00.unk_2C->unk_00[arg0->unk_20[1]->unk_00.unk_38];
            break;
    }
}

void func_88207E14(unk_func_8820B12C_02C* arg0, unk_func_88001300_000_010* arg1, unk_func_88001300_000_010* arg2) {
    s16 var_v1;

    switch (arg0->unk_28) {
        case 0:
            arg1->unk_00 = arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 =
                arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_20[0]->unk_5C - arg0->unk_20[0]->unk_58);

            arg2->unk_00 = arg0->unk_20[1]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_20[1]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_20[1]->unk_5C - arg0->unk_20[1]->unk_58);
            break;

        case 1:
            var_v1 = (arg0->unk_20[0]->unk_00.unk_3E * arg0->unk_30) - arg0->unk_20[0]->unk_58;
            if (var_v1 < -arg0->unk_20[0]->unk_00.unk_3E) {
                var_v1 = -arg0->unk_20[0]->unk_00.unk_3E;
            } else if (arg0->unk_20[0]->unk_00.unk_00.unk_14.unk_02 < var_v1) {
                var_v1 = arg0->unk_20[0]->unk_00.unk_00.unk_14.unk_02;
            }

            arg1->unk_00 = arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 = arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_02 + var_v1;

            arg2->unk_00 = arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_20[0]->unk_5C - arg0->unk_20[0]->unk_58);
            break;

        case 2:
            arg1->unk_00 = arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 =
                arg0->unk_20[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_20[0]->unk_5C - arg0->unk_20[0]->unk_58);

            arg2->unk_00 = arg0->unk_20[1]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_20[1]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_20[1]->unk_5C - arg0->unk_20[1]->unk_58);
            break;
    }
}

void func_88207F84(unk_func_8820B12C_02C* arg0, s32 arg1) {
    switch (arg1) {
        case 0:
            ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_20[0]);
            func_88215974(&arg0->unk_20[0]->unk_00, 1);
            func_88215974(&arg0->unk_20[1]->unk_00, 1);
            func_88207CEC(arg0, 0);
            func_88217BB8(arg0->unk_38);
            break;

        case 1:
            arg0->unk_20[0]->unk_00.unk_34[arg0->unk_20[0]->unk_00.unk_38] |= 2;
            func_88216F18(arg0->unk_20[1], 0);
            func_88215974(&arg0->unk_20[1]->unk_00, 0);
            func_88207CEC(arg0, 1);
            func_88217BAC(arg0->unk_38);
            break;

        case 2:
            arg0->unk_20[arg0->unk_1C]->unk_00.unk_34[arg0->unk_20[arg0->unk_1C]->unk_00.unk_38] |= 2;
            func_88215974(&arg0->unk_20[arg0->unk_1C]->unk_00, 0);
            arg0->unk_30 = arg0->unk_20[arg0->unk_1C]->unk_00.unk_38;
            func_88217BAC(arg0->unk_38);
            break;

        case 3:
            arg0->unk_20[0]->unk_00.unk_34[arg0->unk_20[0]->unk_00.unk_38] |= 2;
            func_88215974(&arg0->unk_20[1]->unk_00, 0);
            func_88207CEC(arg0, 1);
            func_88217BAC(arg0->unk_38);
            break;
    }

    arg0->unk_2C = arg1;
}

void func_88208124(unk_func_8820B12C_02C* arg0) {
    func_88207F84(arg0, 0);
    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(&arg0->unk_20[1]->unk_00);
}

s32 func_88208160(unk_func_8820B12C_02C* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_2C == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_8820817C(unk_func_8820B12C_02C_020* arg0, unk_func_8820B12C_02C_020* arg1) {
    unk_func_88205880_00D0* ptr2 = arg0->unk_00.unk_2C->unk_00[arg0->unk_00.unk_38];

    ((func88507CC4)Memmap_GetFragmentVaddr(func_88507CC4))(arg1, ptr2);
    ((func88507CEC)Memmap_GetFragmentVaddr(func_88507CEC))(arg0);

    *arg1->unk_88 = 1;
    *arg0->unk_88 = *arg1->unk_88;
}

void func_8820820C(unk_func_8820B12C_02C_020* arg0, s32 arg1, s32 arg2) {
    unk_func_88205880_00D0* temp_v0 = arg0->unk_00.unk_2C->unk_00[arg1];

    arg0->unk_00.unk_2C->unk_00[arg1] = arg0->unk_00.unk_2C->unk_00[arg2];
    arg0->unk_00.unk_2C->unk_00[arg2] = temp_v0;

    *arg0->unk_88 = 1;
}

void func_88208250(unk_func_8820B12C_02C_020* arg0, unk_func_8820B12C_02C_020* arg1) {
    unk_func_88205880_00D0* temp_v0 = arg1->unk_00.unk_2C->unk_00[arg1->unk_00.unk_38];
    unk_func_88205880_00D0** temp_v1;

    arg1->unk_00.unk_2C->unk_00[arg1->unk_00.unk_38] = arg0->unk_00.unk_2C->unk_00[arg0->unk_00.unk_38];
    arg0->unk_00.unk_2C->unk_00[arg0->unk_00.unk_38] = temp_v0;

    *arg1->unk_88 = 1;
    *arg0->unk_88 = *arg1->unk_88;
}

void func_882082BC(unk_func_8820B12C_02C_020* arg0) {
    ((func88507CEC)Memmap_GetFragmentVaddr(func_88507CEC))(arg0);
    *arg0->unk_88 = 1;
}

void func_882082FC(unk_func_8820B12C_02C* arg0, Controller* arg1) {
    unk_func_88205880_00D0* sp34;
    unk_func_88205880_00D0* sp30;
    unk_func_88001300_000_010 sp2C;
    unk_func_88001300_000_010 sp28;

    func_88207D38(arg0, &sp30, &sp34);
    func_88207A54(arg0->unk_54[0], sp30);
    func_88207E14(arg0, &sp2C, &sp28);
    func_882175F4(arg0->unk_4C[0], sp2C, sp28);

    arg0->unk_14(arg0, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(func_8850CF00))(arg0->unk_40, arg1);

    arg0->unk_14(arg0, 1);

    func_8820817C(arg0->unk_20[0], arg0->unk_20[1]);
    func_88208124(arg0);
}

void func_882083D0(unk_func_8820B12C_02C* arg0, Controller* arg1, s32 arg2) {
    unk_func_88205880_00D0* sp34;
    unk_func_88205880_00D0* sp30;
    unk_func_88001300_000_010 sp2C;
    unk_func_88001300_000_010 sp28;

    func_88207D38(arg0, &sp30, &sp34);
    func_88207A54(arg0->unk_54[0], sp30);
    func_88207A54(arg0->unk_54[1], sp34);
    func_88207E14(arg0, &sp2C, &sp28);
    func_882175F4(arg0->unk_4C[0], sp2C, sp28);
    func_882175F4(arg0->unk_4C[1], sp28, sp2C);

    arg0->unk_14(arg0, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(func_8850CF00))(arg0->unk_40, arg1);

    arg0->unk_14(arg0, 1);

    if (arg2 != 0) {
        func_8820820C(arg0->unk_20[0], arg0->unk_30, arg0->unk_20[0]->unk_00.unk_38);
    } else {
        func_88208250(arg0->unk_20[0], arg0->unk_20[1]);
    }

    func_88208124(arg0);
}

void func_88208508(unk_func_8820B12C_02C* arg0) {
    unk_func_88205880_00D0* sp2C;
    unk_func_88205880_00D0* sp28;
    s32 sp24;

    func_88207D38(arg0, &sp28, &sp2C);

    arg0->unk_48->unk_0C = sp28;
    arg0->unk_48->unk_10 = arg0->unk_20[0]->unk_8C >> 0x10;

    arg0->unk_44(1, arg0->unk_48);

    func_80048B90(2);

    arg0->unk_20[0]->unk_00.unk_00.unk_24(&arg0->unk_20[0]->unk_00.unk_00, 0x100);

    sp24 = arg0->unk_44(4, arg0->unk_48);

    arg0->unk_20[0]->unk_00.unk_00.unk_24(&arg0->unk_20[0]->unk_00.unk_00, 1);

    if (arg0->unk_48->unk_18 != 0) {
        if (sp24 == 0) {
            func_882082BC(arg0->unk_20[0]);
        }
    } else if (sp24 == 1) {
        *arg0->unk_20[0]->unk_88 = 1;
    }

    func_88208124(arg0);
}

s32 func_88208600(unk_func_8820B12C_02C* arg0, Controller* arg1) {
    s32 var_v1;
    s32 var_v0;
    func8850A10C temp_v1;

    var_v1 = arg0->unk_20[arg0->unk_1C]->unk_00.unk_00.unk_20(arg0->unk_20[arg0->unk_1C], arg1);

    if (var_v1 & 1) {
        return var_v1;
    }

    if (var_v1 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_v1 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_v1 = 0x80000004;
        }
    }

    switch (arg0->unk_2C) {
        case 0:
            switch (arg0->unk_28) {
                case 0:
                    if (!(var_v1 & 2) && (var_v1 & 4)) {
                        if (arg0->unk_20[0]->unk_00.unk_2C->unk_08 == 0) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(arg0->unk_3C, arg0->unk_5C[0], 0, 0);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_3C, arg1);
                            var_v1 = 1;
                        } else if (arg0->unk_20[1]->unk_00.unk_2C->unk_08 >= arg0->unk_20[1]->unk_00.unk_2C->unk_04) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(arg0->unk_3C, arg0->unk_5C[5], 0, 0);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_3C, arg1);
                            var_v1 = 1;
                        } else {
                            func_88207F84(arg0, 1);
                            var_v1 |= 1;
                        }
                    }
                    break;

                case 1:
                    if (!(var_v1 & 2) && (var_v1 & 4)) {
                        if (arg0->unk_20[0]->unk_00.unk_2C->unk_08 == 0) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(arg0->unk_3C, arg0->unk_5C[1], 0, 0);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_3C, arg1);
                            var_v1 = 1;
                        } else {
                            func_88207F84(arg0, 2);
                            var_v1 |= 1;
                        }
                    }
                    break;

                case 2:
                    if (!(var_v1 & 2) && (var_v1 & 4)) {
                        if ((arg0->unk_20[0]->unk_00.unk_2C->unk_08 == 0) ||
                            (arg0->unk_20[1]->unk_00.unk_2C->unk_08 == 0)) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(arg0->unk_3C, arg0->unk_5C[2], 0, 0);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_3C, arg1);
                            var_v1 = 1;
                        } else {
                            func_88207F84(arg0, 3);
                            var_v1 |= 1;
                        }
                    }
                    break;

                case 3:
                    if (!(var_v1 & 2) && (var_v1 & 4)) {
                        if (arg0->unk_20[0]->unk_00.unk_2C->unk_08 == 0) {
                            func_80048B90(8);
                            temp_v1 = ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C));
                            if (arg0->unk_48->unk_18 != 0) {
                                var_v0 = 4;
                            } else {
                                var_v0 = 3;
                            }
                            temp_v1(arg0->unk_3C, arg0->unk_5C[var_v0], 0, 0);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_3C, arg1);
                            var_v1 = 1;
                        } else {
                            func_88208508(arg0);
                            var_v1 = 5;
                        }
                    }
                    break;
            }
            break;

        case 1:
            if (var_v1 & 2) {
                func_88207F84(arg0, 0);
                func_88216F18(arg0->unk_20[1], 1);
                var_v1 |= 1;
            } else if (var_v1 & 4) {
                func_80048B90(0x18);
                arg0->unk_20[0]->unk_00.unk_34[arg0->unk_20[0]->unk_00.unk_38] |= 0x100;
                func_882082FC(arg0, arg1);
                func_88216F18(arg0->unk_20[1], 2);
                if (arg0->unk_74 != 0) {
                    var_v1 = 0x02000000;
                } else {
                    var_v1 = 0x80000081;
                }
            }
            break;

        case 2:
            if (var_v1 & 2) {
                func_88207F84(arg0, 0);
                var_v1 |= 1;
            } else if (var_v1 & 4) {
                if (arg0->unk_30 == arg0->unk_20[arg0->unk_1C]->unk_00.unk_38) {
                    var_v1 = 0x80000101;
                } else {
                    func_80048B90(0x18);
                    arg0->unk_20[arg0->unk_1C]->unk_00.unk_34[arg0->unk_20[arg0->unk_1C]->unk_00.unk_38] |= 2;
                    arg0->unk_20[arg0->unk_1C]->unk_00.unk_34[arg0->unk_30] |= 0x100;
                    arg0->unk_20[arg0->unk_1C]->unk_00.unk_34[arg0->unk_20[arg0->unk_1C]->unk_00.unk_38] |= 0x100;
                    func_882083D0(arg0, arg1, 1);
                    var_v1 = 0x80000081;
                }
            }
            break;

        case 3:
            if (var_v1 & 2) {
                func_88207F84(arg0, 0);
                var_v1 |= 1;
            } else if (var_v1 & 4) {
                func_80048B90(0x18);
                arg0->unk_20[1]->unk_00.unk_34[arg0->unk_20[1]->unk_00.unk_38] |= 2;
                arg0->unk_20[0]->unk_00.unk_34[arg0->unk_20[0]->unk_00.unk_38] |= 0x100;
                arg0->unk_20[1]->unk_00.unk_34[arg0->unk_20[1]->unk_00.unk_38] |= 0x100;
                func_882083D0(arg0, arg1, 0);
                var_v1 = 0x80000081;
            }
            break;
    }

    return var_v1;
}

unk_func_88205880_00D0* func_88208BFC(unk_func_8820B12C_02C* arg0) {
    s32 temp_v1;
    unk_func_88205880_A030* temp_a1;

    if (arg0->unk_2C == 1) {
        return NULL;
    }

    temp_v1 = arg0->unk_20[arg0->unk_1C]->unk_00.unk_38;
    temp_a1 = arg0->unk_20[arg0->unk_1C]->unk_00.unk_2C;

    if (temp_v1 >= temp_a1->unk_08) {
        return NULL;
    }

    return temp_a1->unk_00[temp_v1];
}

void func_88208C5C(unk_func_88208C5C* arg0, unk_func_8850143C* arg1) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_88208C5C));

    arg0->unk_00.unk_18 = func_88208CE4;
    arg0->unk_00.unk_14.unk_00 = arg1->unk_00.unk_14.unk_00;
    arg0->unk_00.unk_14.unk_02 = arg1->unk_00.unk_14.unk_02;
    arg0->unk_2C = arg1;
    arg0->unk_30 = func_8002EC08(func_80024F68(func_80029080()));
    arg0->unk_34 = -1;
    arg0->unk_38 = -1;
}

s32 func_88208CE4(unk_func_88208C5C* arg0, s32 arg1, s32 arg2) {
    static u8 D_88217E30[] = {
        0x27,
        0x42,
        0x43,
        0x40,
    };
    static Color_RGBA8 D_88217E34 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88217E38 = { 0xF0, 0xF0, 0xF0, 0xFF };

    char* spBC = func_8002D7C0(NULL, 0, D_88224FB4, D_88217E30[arg0->unk_34]);
    s8 sp9C[0x20];
    s32 temp_v0;
    s32 var_s0;

    if (arg0->unk_38 == -1) {
        return 1;
    }

    if ((arg0->unk_34 == 1) || (arg0->unk_34 == 2)) {
        sprintf(sp9C, "%s %d", spBC, arg0->unk_38 + 1);
        spBC = sp9C;
    }

    temp_v0 = func_8001F5B0(8, 0, spBC);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    if ((arg0->unk_34 == 0) || (arg0->unk_34 == 1)) {
        var_s0 = (((arg0->unk_00.unk_14.unk_00 - temp_v0) - 0x20) / 2) + arg1 + 0x20;

        gDPLoadTextureBlock(gDisplayListHead++, D_88223470[arg0->unk_30], G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 26, 0,
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
    func_8001F324(D_88217E34.r, D_88217E34.g, D_88217E34.b, D_88217E34.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(var_s0, arg2 + 5, spBC);
    func_8001F444();

    return 0;
}

u32 func_882091E4(unk_func_88208C5C* arg0) {
    return (arg0->unk_34 << 0x10) | arg0->unk_38;
}

void func_882091F8(unk_func_88208C5C* arg0, u32 arg1) {
    arg0->unk_34 = arg1 >> 0x10;
    arg0->unk_38 = arg1 & 0xFFFF;
}

void func_8820920C(unk_func_8820BE14_02C_070* arg0, s32 arg1, s32 arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8820BE14_02C_070));

    arg0->unk_0000.unk_18 = func_8820938C;
    arg0->unk_0000.unk_10.unk_00 = arg1;
    arg0->unk_0000.unk_10.unk_02 = arg2;

    func_88209A88(arg0, NULL);

    arg0->unk_0030 = 0;
}

void func_8820927C(s32 arg0, s32 arg1, ret_func_8002ED08* arg2, s32 arg3) {
    Color_RGBA8 sp24;
    char* sp20;

    func_8001EBE0(8, 0);
    if (arg2 == NULL) {
        sp24 = ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(0)->unk_04;
        sp20 = "???????";
    } else {
        sp24 = ((func884000C4)Memmap_GetFragmentVaddr(func_884000C4))(arg2->unk_00[1])->unk_04;
        sp20 = func_8002D7C0(NULL, 0, D_88224FBC, arg2->unk_00[0] - 1);
    }

    func_8001F324(sp24.r, sp24.g, sp24.b, sp24.a);

    if (arg3 != 0) {
        arg0 = (arg0 - func_8001F5B0(0, 0, sp20)) + 0x8C;
    }

    func_8001F1E8(arg0, arg1, sp20);
}

s32 func_8820938C(unk_func_8820BE14_02C_070* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88217E3C = { 0xF0, 0xF0, 0xF0, 0xFF };
    static unk_D_88217E40 D_88217E40[] = {
        {
            0x000000DB,
            0x00000004,
            0x00000001,
            0x00000167,
            0x040037A8,
        },
        {
            0x00000193,
            0x0000001C,
            0x00000000,
            0x0000017F,
            0x04003AD0,
        },
        {
            0x0000017B,
            0x00000034,
            0x00000000,
            0x00000167,
            0x04003DF8,
        },
        { 0x000000C3, 0x0000001C, 0x00000001, 0x0000014F, 0x04004120 },
    };

    s32 i;
    s32 spB0;
    unk_func_88205880_00D0* ptr = arg0->unk_002C;

    if (ptr == NULL) {
        return 0;
    }

    spB0 = func_8002ECDC(ptr);

    i = (u32)arg0->unk_0039[arg0->unk_0030] & ~7;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    gDPLoadTextureBlock(gDisplayListHead++, i, G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 40, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg1 + 0x84) << 2, (arg2 + 0xA) << 2, (arg1 + 0xAB) << 2,
                        (arg2 + 0x31) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    for (i = 0; i < 4; i++) {
        gDPLoadTextureBlock(gDisplayListHead++, D_88217E40[i].unk_10, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (arg1 + D_88217E40[i].unk_0C) << 2, (arg2 + D_88217E40[i].unk_04) << 2,
                            ((arg1 + D_88217E40[i].unk_0C) + 0x13) << 2, (arg2 + D_88217E40[i].unk_04 + 0x13) << 2,
                            G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

    func_8001F3F4();

    if ((arg0->unk_002C->unk_000[0].unk_00 <= 0) || (arg0->unk_002C->unk_000[0].unk_00 >= 0x98)) {
        func_8001F324(D_88217E3C.r, D_88217E3C.g, D_88217E3C.b, D_88217E3C.a);
        func_8001EBE0(8, 0);
        func_8001F1E8(arg1 + 8, arg2 + 8, "?????");
    } else {
        func_8001F324(D_88217E3C.r, D_88217E3C.g, D_88217E3C.b, D_88217E3C.a);
        func_8001EBE0(8, 0);

        func_8001F1E8(arg1 + 8, arg2 + 0x24, func_8002D7C0(NULL, 0, D_88224FB4, 0x12));
        func_8001F324(0xFF, 0xC8, 0xC8, 0xFF);
        func_8001EBE0(4, 0);

        func_8001F1E8(arg1 + 6, arg2 + 0x56, func_8002D7C0(NULL, 0, D_88224FB4, 0x13));
        func_8001F1E8(arg1 + 0x91, arg2 + 0x56, func_8002D7C0(NULL, 0, D_88224FB4, 0x14));
        func_8001F1E8(arg1 + 0x11C, arg2 + 0x56, func_8002D7C0(NULL, 0, D_88224FB4, 0x15));
        func_8001F1E8(arg1 + 0x1A7, arg2 + 0x56, func_8002D7C0(NULL, 0, D_88224FB4, 0x16));

        func_8001F324(D_88217E3C.r, D_88217E3C.g, D_88217E3C.b, D_88217E3C.a);
        func_8001EBE0(8, 0);
        func_8001F1E8(arg1 + 8, arg2 + 8, func_8002D7C0(NULL, 0, D_88224FB8, arg0->unk_002C->unk_000[0].unk_00 - 1));

        func_8001F1E8(arg1 + 0x44, arg2 + 0x24, "%3d", arg0->unk_002C->unk_000[0].unk_26);
        func_8001F1E8(arg1 + 0x46, arg2 + 0x54, "%3d", arg0->unk_002C->unk_000[0].unk_28);
        func_8001F1E8(arg1 + 0xD1, arg2 + 0x54, "%3d", arg0->unk_002C->unk_000[0].unk_2A);
        func_8001F1E8(arg1 + 0x15C, arg2 + 0x54, "%3d", arg0->unk_002C->unk_000[0].unk_2C);
        func_8001F1E8(arg1 + 0x1E7, arg2 + 0x54, "%3d", arg0->unk_002C->unk_000[0].unk_2E);
    }

    for (i = 0; i < spB0; i++) {
        func_8820927C(D_88217E40[i].unk_00 + arg1, D_88217E40[i].unk_04 + arg2,
                      func_8002ED08(arg0->unk_002C->unk_000[0].unk_09[i]), D_88217E40[i].unk_08);
    }

    func_8001F444();

    return 0;
}

void func_88209A88(unk_func_8820BE14_02C_070* arg0, unk_func_88205880_00D0* arg1) {
    arg0->unk_002C = arg1;
    if (arg1 != NULL) {
        arg0->unk_0030 = (arg0->unk_0030 + 1) & 1;
        func_8001B0DC((u32)arg0->unk_0039[arg0->unk_0030] & ~7, 0, arg0->unk_002C);
    }
}

s32 func_88209AF0(unk_func_8820BE14_06C* arg0) {
    s32 i;
    s32 j;
    unk_func_8820BE14_06C_000* ptr;

    for (i = 0; i < 3; i++) {
        ptr = arg0[i].unk_00;
        for (j = 0; j < arg0[i].unk_08; j++) {
            if (ptr[j].unk_04.unk_08 < ptr[j].unk_04.unk_04) {
                return (i << 0x10) | j;
            }
        }
    }
    return 0;
}

#ifdef NON_MATCHING
void func_88209B54(unk_func_8820BE14_02C* arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C_000* arg3,
                   unk_func_8820BE14_06C_000* arg4, unk_func_88001300_000* arg5, FragmentEntry arg6,
                   unk_func_8820BE14_030* arg7, unk_func_88509F48* arg8, char** arg9, MemoryPool* argA) {
    static Color_RGBA8 D_88217E90 = { 0x6C, 0x6C, 0x7E, 0xFF };
    static Color_RGBA8 D_88217E94 = { 0x50, 0x50, 0x86, 0xFF };
    static Color_RGBA8 D_88217E98 = { 0x79, 0x79, 0xCB, 0xFF };
    static Color_RGBA8 D_88217E9C = { 0x40, 0x40, 0x6C, 0xFF };
    static Color_RGBA8 D_88217EA0 = { 0x6A, 0x6A, 0xB2, 0xFF };
    static unk_D_88217EA4 D_88217EA4[] = {
        {
            219,
            40,
            54,
            42,
            D_8821E100,
            0x30,
            0x0000,
            D_882181E8,
            1,
            1,
        },
        {
            279,
            40,
            54,
            42,
            D_8821E100,
            0x30,
            0x0000,
            D_882181E8,
            0,
            3,
        },
        {
            219,
            88,
            54,
            42,
            D_88218FD0,
            0x30,
            0x0000,
            D_882181B8,
            0,
            3,
        },
        {
            279,
            88,
            54,
            42,
            D_8821B868,
            0x30,
            0x0000,
            D_882181D0,
            1,
            1,
        },
        {
            219,
            136,
            54,
            42,
            D_8821AAE0,
            0x30,
            0x0000,
            D_882181C8,
            0,
            1,
        },
        {
            279,
            136,
            54,
            42,
            D_88219D58,
            0x30,
            0x0000,
            D_882181C0,
            1,
            1,
        },
        {
            219,
            184,
            54,
            42,
            D_88218248,
            0x30,
            0x0000,
            D_882181B0,
            0,
            3,
        },
        {
            279,
            184,
            54,
            42,
            D_8821D378,
            0x30,
            0x0000,
            D_882181E0,
            1,
            1,
        },
    };
    static Color_RGBA8 D_88217F84 = { 0xFF, 0xFF, 0x00, 0xFF };
    static Color_RGBA8 D_88217F88 = { 0x2D, 0x1A, 0x41, 0xFF };
    static Color_RGBA8 D_88217F8C = { 0x6F, 0x5F, 0x7F, 0xFF };
    static Color_RGBA8* D_88217F90[] = {
        D_88218228, D_88218228, D_882181F0, D_88218210, D_88218200, D_88218208, D_882181F8, D_88218220,
    };
    static Color_RGBA8* D_88217FB0[] = { D_882181F8, D_882181F8 };
    static Color_RGBA8 D_88217FB8 = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 i;
    s32 j;
    unk_func_885012A4* sp108;
    unk_func_885012A4* sp104;
    unk_func_885012A4* sp100;
    unk_func_885012A4* spFC;
    unk_func_885012A4* spF8;
    unk_func_88001300_000* spF4;
    unk_func_88001300_000* spF0;
    unk_func_8850143C* spEC;
    unk_func_8850143C* spE8;
    u32 spE4;
    unk_func_8850878C* spB4[8];
    char* spA0;
    s32 sp9C;
    unk_func_88507D4C* sp98;
    unk_func_88507D4C* sp94;
    unk_func_88507D4C* sp8C;
    unk_func_88507D4C* sp88;
    u32 sp50;
    s32 temp_s0_5;
    char* temp_s1_2;
    char* temp_v0_10;
    unk_func_8820BE14_06C* temp_v0_17;
    unk_func_882149A0* temp_v0_7;
    unk_func_88217740* temp_v0_5;
    unk_func_88217740* temp_v0_6;
    unk_func_88001300_02C* temp_s0;
    unk_func_88001300_03C_01C* temp_s0_2;
    unk_func_8850143C* temp_s0_3;
    unk_func_8850878C* temp_s0_4;
    unk_func_88503298* temp_s0_6;
    char* temp_s0_7;
    unk_func_882170A8* temp_v0_14;
    unk_func_882170A8* temp_v0_16;

    arg0->unk_8C = arg4;
    arg0->unk_80 = arg8;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8820BE14_02C));

    arg0->unk_00.unk_1C = func_8820ADEC;
    arg0->unk_00.unk_20 = func_8820AF78;
    arg0->unk_00.unk_24 = func_8820B0A0;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_10.unk_00 = arg1;

    arg0->unk_74 = mem_pool_alloc(argA, sizeof(unk_func_8820B12C));
    func_8820B12C(arg0->unk_74, arg0);

    arg0->unk_2C = mem_pool_alloc(argA, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, 0x228, 0x160);
    arg0->unk_2C->unk_28 |= 0x400;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    temp_s0 = mem_pool_alloc(argA, sizeof(unk_func_88001300_02C));
    ((func88503118)Memmap_GetFragmentVaddr(func_88503118))(temp_s0, 0, 0, 0x228, 0x160);
    temp_s0->unk_2C = 0;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s0);

    spF8 = mem_pool_alloc(argA, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spF8, 0, 0, 0x228, 8, D_88217E90);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spF8);

    spFC = mem_pool_alloc(argA, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spFC, 0, 0xEE, 0x228, 6, D_88217E90);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spFC);

    sp100 = mem_pool_alloc(argA, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp100, 0, 8, 8, 0xE6, D_88217E90);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp100);

    sp104 = mem_pool_alloc(argA, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp104, 0x220, 8, 8, 0xE6, D_88217E90);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp104);

    sp108 = mem_pool_alloc(argA, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp108, 0xD4, 8, 0x80, 0xE6, D_88217E90);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp108);

    spF0 = mem_pool_alloc(argA, sizeof(unk_func_88001300_000));
    ((func8850AB48)Memmap_GetFragmentVaddr(func_8850AB48))(spF0, 8, 8, 0xCC, 0xE6);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spF0);

    spF4 = mem_pool_alloc(argA, sizeof(unk_func_88001300_000));
    ((func8850AB48)Memmap_GetFragmentVaddr(func_8850AB48))(spF4, 0x154, 8, 0xCC, 0xE6);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spF4);

    spE8 = mem_pool_alloc(argA, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(func_8850143C))(spE8, 8, 8, 0xCC, 0x1E, D_88217E94, D_88217E98);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spE8);

    spEC = mem_pool_alloc(argA, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(func_8850143C))(spEC, 0x154, 8, 0xCC, 0x1E, D_88217E94, D_88217E98);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spEC);

    arg0->unk_30[0] = mem_pool_alloc(argA, sizeof(unk_func_88208C5C));
    func_88208C5C(arg0->unk_30[0], spE8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spE8, arg0->unk_30[0]);

    arg0->unk_30[1] = mem_pool_alloc(argA, sizeof(unk_func_88208C5C));
    func_88208C5C(arg0->unk_30[1], spEC);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spEC, arg0->unk_30[1]);

    arg0->unk_40 = mem_pool_alloc(argA, sizeof(unk_func_88217740));
    func_88217740(arg0->unk_40, 0xF4, 0xA);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_40);

    if (arg3 != NULL) {
        arg0->unk_40->unk_00.unk_28 &= ~1;
    }

    sp50 = 1 << ((arg3 != NULL) ? 1 : 0);

    for (j = 0; j < 8; j++) {
        unk_D_88217EA4* ptr = &D_88217EA4[j];
        if (!(ptr->unk_18 & sp50)) {
            continue;
        }

        arg0->unk_44[j] = mem_pool_alloc(argA, sizeof(unk_func_882149A0));
        func_882149A0(arg0->unk_44[j], ptr->unk_00, ptr->unk_02, ptr->unk_04, ptr->unk_06, ptr->unk_08, ptr->unk_0C,
                      ptr->unk_10[0], ptr->unk_10[1], D_88217E90);

        if (ptr->unk_14 != 0) {
            func_882158BC(arg0->unk_44[j]);
        }

        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_44[i]);
    }

    arg0->unk_74->unk_28 = mem_pool_alloc(argA, sizeof(unk_func_88001300_03C));
    ((func8850C284)Memmap_GetFragmentVaddr(func_8850C284))(arg0->unk_74->unk_28, 4, 2, argA);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_74, arg0->unk_74->unk_28);

    for (j = 0; j < 8; j++) {
        if (D_88217EA4[j].unk_18 & sp50) {
            arg0->unk_74->unk_28->unk_18[(j / 2) * arg0->unk_74->unk_28->unk_2C + (j % 2)] = arg0->unk_44[j];
        }
    }

    ((func8850CB48)Memmap_GetFragmentVaddr(func_8850CB48))(arg0->unk_74->unk_28, 2);

    temp_s0_2 = mem_pool_alloc(argA, sizeof(unk_func_88001300_03C_01C));
    ((func88503340)Memmap_GetFragmentVaddr(func_88503340))(temp_s0_2, 0, 0, 0x10, 0x10, D_88217F84);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s0_2);
    arg0->unk_74->unk_28->unk_1C = temp_s0_2;

    temp_s0_3 = mem_pool_alloc(argA, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(func_8850143C))(temp_s0_3, 0, 0xF4, 0x228, 0x6C, D_88217F88, D_88217F8C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s0_3);

    arg0->unk_64 = mem_pool_alloc(argA, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_64, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s0_3, arg0->unk_64);

    arg0->unk_68 = mem_pool_alloc(argA, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_68, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_64, arg0->unk_68);

    for (j = 0; j < 8; j++) {
        temp_s1_2 = func_8002D7C0(NULL, 0, D_88224FB4, j + 1);
        spB4[j] = mem_pool_alloc(argA, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(spB4[j], (0x228 - func_8001F5B0(0x10, 0, temp_s1_2)) / 2,
                                                               0x2A, temp_s1_2, 0x10);
        spB4[j]->unk_30 = D_88217F90[j][0];
        spB4[j]->unk_44 = spB4[j]->unk_44;
        spB4[j]->unk_34 = D_88217F90[j][1];
        spB4[j]->unk_44 = 1;
        ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_68, spB4[j]);
    }

    if (arg3 != NULL) {
        temp_v0_10 = func_8002D7C0(NULL, 0, D_88224FB4, 9);
        spB4[2]->unk_00.unk_10.unk_00 = (0x228 - func_8001F5B0(0x10, 0, temp_v0_10)) / 2;
        spB4[2]->unk_00.unk_10.unk_02 = 0x2A;
        spB4[2]->unk_40 = temp_v0_10;
    }

    arg0->unk_6C = mem_pool_alloc(argA, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_6C, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_64, arg0->unk_6C);

    for (j = 0; j < 2; j++) {
        temp_s0_4 = mem_pool_alloc(argA, sizeof(unk_func_8850878C));
        spA0 = func_8002D7C0(NULL, 0, D_88224FB4, 0xA);

        if (j == 0) {
            sp9C = 0x210 - func_8001F5B0(0x10, 0, spA0);
        } else {
            sp9C = 0x18;
        }

        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s0_4, sp9C, 0x1A, spA0, 0x10);

        temp_s0_4->unk_30 = D_88217FB0[j][0];
        temp_s0_4->unk_44 = temp_s0_4->unk_44;
        temp_s0_4->unk_34 = D_88217FB0[j][1];
        temp_s0_4->unk_44 = 1;
        temp_s0_4->unk_3C = 0x20;

        ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_6C, temp_s0_4);
    }

    arg0->unk_70 = mem_pool_alloc(argA, sizeof(unk_func_8820BE14_02C_070));
    func_8820920C(arg0->unk_70, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_64, arg0->unk_70);

    arg0->unk_38[0] = mem_pool_alloc(argA, sizeof(unk_func_8820B12C_02C_020));
    func_882158CC(arg0->unk_38[0], 8, 0x36, 6, func_88207354, 0xCC, 0x1C, argA);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_38[0], 0x14, argA);

    sp94 = mem_pool_alloc(argA, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp94, 8, 0x26, 0xCC, 0, arg0->unk_38[0]);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp94);

    sp98 = mem_pool_alloc(argA, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp98, 8, arg0->unk_38[0]->unk_00.unk_00.unk_14.unk_02 + 0x36,
                                                           0xCC, 1, arg0->unk_38);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp98);
    func_882159AC(arg0->unk_38[0], sp98);

    temp_v0_14 = mem_pool_alloc(argA, sizeof(unk_func_882170A8));
    func_882170A8(temp_v0_14, 0x98, 2, arg0->unk_38, 2);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp98, temp_v0_14);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_38[0]);

    arg0->unk_38[1] = mem_pool_alloc(argA, sizeof(unk_func_8820B12C_02C_020));
    func_882158CC(arg0->unk_38[1], 0x154, 0x36, 6, func_88207354, 0xCC, 0x1C, argA);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_38[1], 0x14, argA);

    sp88 = mem_pool_alloc(argA, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp88, 0x154, 0x26, 0xCC, 0, arg0->unk_38[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp88);

    sp8C = mem_pool_alloc(argA, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(
        sp8C, 0x154, arg0->unk_38[1]->unk_00.unk_00.unk_14.unk_02 + 0x36, 0xCC, 1, arg0->unk_38[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp8C);
    func_882159AC(arg0->unk_38[1], sp8C);

    temp_v0_16 = mem_pool_alloc(argA, sizeof(unk_func_882170A8));
    func_882170A8(temp_v0_16, 0x98, 2, arg0->unk_38[1], 2);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp8C, temp_v0_16);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_38[1]);

    if (arg3 != NULL) {
        temp_s0_5 = func_88209AF0(arg0->unk_8C);
        func_882091F8(arg0->unk_30[0], 0x30000);
        func_882091F8(arg0->unk_30[1], temp_s0_5);
        func_88217018(arg0->unk_38[0], arg3, 0x30000);
        func_88217018(arg0->unk_38[1],
                      (arg0->unk_8C[temp_s0_5 >> 0x10].unk_0C * (temp_s0_5 & 0xFFFF)) +
                          arg0->unk_8C[temp_s0_5 >> 0x10].unk_00,
                      temp_s0_5);
    } else {
        func_882091F8(arg0->unk_30[0], 0);
        func_882091F8(arg0->unk_30[1], 0x10000);
        func_88217018(arg0->unk_38[0], arg0->unk_8C[0].unk_00, 0);
        func_88217018(arg0->unk_38[1], arg0->unk_8C[1].unk_00, 0x10000);
    }

    arg0->unk_74->unk_2C = mem_pool_alloc(argA, sizeof(unk_func_8820B12C_02C));
    func_88207A94(arg0->unk_74->unk_2C, arg0->unk_38, arg0->unk_38[1], arg0->unk_40, arg0->unk_80, arg3 != NULL, argA);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_74, arg0->unk_74->unk_2C);

    arg0->unk_74->unk_2C->unk_40 = mem_pool_alloc(argA, sizeof(unk_func_8850CD44));
    ((func8850CD44)Memmap_GetFragmentVaddr(func_8850CD44))(arg0->unk_74->unk_2C->unk_40, 2, argA);

    for (j = 0; j < 2; j++) {
        arg0->unk_74->unk_2C->unk_4C[j] = mem_pool_alloc(argA, sizeof(unk_func_882173EC));
        func_882173EC(arg0->unk_74->unk_2C->unk_4C[j], 0, 0);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_74->unk_2C->unk_4C[j]);

        arg0->unk_74->unk_2C->unk_54[j] = mem_pool_alloc(argA, sizeof(unk_func_882079D8));
        func_882079D8(arg0->unk_74->unk_2C->unk_54[j], 0, 0, 0xCC, NULL);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_74->unk_2C->unk_4C[j],
                                                               arg0->unk_74->unk_2C->unk_54[j]);

        arg0->unk_74->unk_2C->unk_40->unk_1C[j] = arg0->unk_74->unk_2C->unk_4C[j];
    }

    arg0->unk_74->unk_2C->unk_44 = arg6;
    arg0->unk_74->unk_2C->unk_48 = arg7;

    arg0->unk_78[0] = mem_pool_alloc(argA, sizeof(unk_func_8820BE14_02C_078));
    func_88206C4C(arg0->unk_78[0], 8, 0x2A, 0xCC, arg0->unk_8C, 0, argA);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_78[0]);

    arg0->unk_78[1] = mem_pool_alloc(argA, sizeof(unk_func_8820BE14_02C_078));
    func_88206C4C(arg0->unk_78[1], 0x154, 0x2A, 0xCC, arg0->unk_8C, 1, argA);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_78[1]);

    temp_s0_6 = mem_pool_alloc(argA, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(temp_s0_6, arg0->unk_2C, arg5);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, temp_s0_6);

    arg0->unk_84 = mem_pool_alloc(argA, sizeof(unk_func_889000C4));
    ((func889000C4)Memmap_GetFragmentVaddr(func_889000C4))(arg0->unk_84, arg3 != NULL, arg0->unk_2C, 0, arg9, argA);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_84);

    temp_s0_7 = mem_pool_alloc(argA, sizeof(char) * 0x80);

    arg0->unk_88 = mem_pool_alloc(argA, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_88, 0, 0, temp_s0_7, 0x10);
    arg0->unk_88->unk_30 = D_88217FB8;
    arg0->unk_88->unk_44 = arg0->unk_88->unk_44;
}
#else
static Color_RGBA8 D_88217E90 = { 0x6C, 0x6C, 0x7E, 0xFF };
static Color_RGBA8 D_88217E94 = { 0x50, 0x50, 0x86, 0xFF };
static Color_RGBA8 D_88217E98 = { 0x79, 0x79, 0xCB, 0xFF };
static Color_RGBA8 D_88217E9C = { 0x40, 0x40, 0x6C, 0xFF };
static Color_RGBA8 D_88217EA0 = { 0x6A, 0x6A, 0xB2, 0xFF };
static unk_D_88217EA4 D_88217EA4[] = {
    {
        219,
        40,
        54,
        42,
        D_8821E100,
        0x30,
        0x0000,
        D_882181E8,
        1,
        1,
    },
    {
        279,
        40,
        54,
        42,
        D_8821E100,
        0x30,
        0x0000,
        D_882181E8,
        0,
        3,
    },
    {
        219,
        88,
        54,
        42,
        D_88218FD0,
        0x30,
        0x0000,
        D_882181B8,
        0,
        3,
    },
    {
        279,
        88,
        54,
        42,
        D_8821B868,
        0x30,
        0x0000,
        D_882181D0,
        1,
        1,
    },
    {
        219,
        136,
        54,
        42,
        D_8821AAE0,
        0x30,
        0x0000,
        D_882181C8,
        0,
        1,
    },
    {
        279,
        136,
        54,
        42,
        D_88219D58,
        0x30,
        0x0000,
        D_882181C0,
        1,
        1,
    },
    {
        219,
        184,
        54,
        42,
        D_88218248,
        0x30,
        0x0000,
        D_882181B0,
        0,
        3,
    },
    {
        279,
        184,
        54,
        42,
        D_8821D378,
        0x30,
        0x0000,
        D_882181E0,
        1,
        1,
    },
};
static Color_RGBA8 D_88217F84 = { 0xFF, 0xFF, 0x00, 0xFF };
static Color_RGBA8 D_88217F88 = { 0x2D, 0x1A, 0x41, 0xFF };
static Color_RGBA8 D_88217F8C = { 0x6F, 0x5F, 0x7F, 0xFF };
static Color_RGBA8* D_88217F90[] = {
    D_88218228, D_88218228, D_882181F0, D_88218210, D_88218200, D_88218208, D_882181F8, D_88218220,
};
static Color_RGBA8* D_88217FB0[] = { D_882181F8, D_882181F8 };
static Color_RGBA8 D_88217FB8 = { 0xF0, 0xF0, 0xF0, 0xFF };
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1AE680/func_88209B54.s")
#endif

s32 func_8820ADEC(unk_func_8820BE14_02C* arg0) {
    switch (arg0->unk_74->unk_00.unk_1C) {
        case 0:
            if ((arg0->unk_74->unk_28->unk_20 == 0x100) && (arg0->unk_74->unk_28->unk_24 < 2)) {
                ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_64, 1);
                ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_6C,
                                                                       (arg0->unk_74->unk_28->unk_24 == 0) ? 0 : 1);
            } else {
                ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_64, 0);
                ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_68, arg0->unk_74->unk_28->unk_24);
            }
            break;

        case 1:
            if (func_882091E4(arg0->unk_30[0]) == 0x30000) {
                ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_64, 0);
                ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_68, arg0->unk_74->unk_28->unk_24);
            } else {
                func_88209A88(arg0->unk_70, func_88208BFC(arg0->unk_74->unk_2C));
                ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_64, 2);
            }
            break;
    }

    return 0;
}

s32 func_8820AF78(unk_func_8820BE14_02C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_74->unk_00.unk_10(&arg0->unk_74->unk_00, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8820AFC4(unk_func_8820BE14_02C* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_s2 = 0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);

    while (var_s2 == 0) {
        func_8002EEA8(0);

        temp_v0 = arg0->unk_00.unk_20(arg0, gPlayer1Controller);

        if (!(temp_v0 & 1) && (temp_v0 & 2)) {
            var_s2 = 1;
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(temp_v0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s2;
}

void func_8820B0A0(unk_func_8820BE14_02C* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    ((func8850BF60)Memmap_GetFragmentVaddr(func_8850BF60))(arg0->unk_74, arg1);
}

void func_8820B0E0(unk_func_8820B12C_02C* arg0) {
    func_882158BC(arg0->unk_4C[0]);
    func_882158BC(arg0->unk_54[0]);
    func_882158BC(arg0->unk_54[1]);
    func_882158BC(arg0->unk_4C[1]);
    func_882158BC(arg0->unk_5C[1]);
}

void func_8820B12C(unk_func_8820B12C* arg0, unk_func_8820BE14_02C* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(func_8850BDF0))(&arg0->unk_00);

    arg0->unk_00.unk_10 = func_8820B838;
    arg0->unk_00.unk_24 = arg1;
}

s32 func_8820B178(unk_func_8820BE14_06C_000* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 sp90;
    unk_func_80022C28_ret* temp_v0;
    unk_func_88205880_00D0** var_s1;
    unk_func_80026268_arg0 sp34;

    sp90 = 0;
    if (arg0->unk_00 == 0) {
        return 0;
    }

    temp_v0 = func_80022C28(arg1, arg2, arg3, 0);
    if (temp_v0 == NULL) {
        return 0;
    }

    arg0->unk_00 = 0;

    if (func_8002EE1C(arg1, arg2, arg3) != arg0->unk_04.unk_08) {
        arg0->unk_00 = 1;
        sp90 = 1;
    } else {
        var_s1 = arg0->unk_04.unk_00;

        for (i = 0; i < arg0->unk_04.unk_08; i++, var_s1++) {
            bzero(&sp34, sizeof(unk_func_80026268_arg0));
            func_80022E18(&sp34, 1, temp_v0);
            if (bcmp(&sp34, *var_s1, sizeof(unk_func_80026268_arg0)) != 0) {
                arg0->unk_00 = 1;
                sp90 = 1;
                break;
            }
        }
    }

    func_80022D8C(temp_v0);

    return sp90;
}

s32 func_8820B2A4(unk_func_8820BE14_02C* arg0) {
    s32 i;
    s32 temp_s2;
    s32 var_s4;
    unk_func_8820BE14_06C_000* var_s1;

    temp_s2 = func_80029080();
    var_s4 = 0;

    var_s1 = arg0->unk_8C[0].unk_00;
    for (i = 0; i < 1; i++) {
        if (func_8820B178(&var_s1[i], 0x20, temp_s2, i) != 0) {
            var_s4 |= 1;
            break;
        }
    }

    var_s1 = arg0->unk_8C[1].unk_00;
    for (i = 0; i < 12; i++) {
        if (func_8820B178(&var_s1[i], 0x21, temp_s2, i) != 0) {
            var_s4 |= 2;
            break;
        }
    }

    var_s1 = arg0->unk_8C[2].unk_00;
    for (i = 0; i < 12; i++) {
        if (func_8820B178(&var_s1[i], 0x11, temp_s2, i) != 0) {
            var_s4 |= 4;
            break;
        }
    }

    return var_s4;
}

s32 func_8820B3AC(unk_func_8820BE14_02C* arg0) {
    return arg0->unk_8C->unk_00->unk_04.unk_08 == 0;
}

void func_8820B3C0(s32 arg0, s32 arg1, s32 arg2, unk_func_88200FA0_030_038* arg3) {
    s32 i;
    unk_func_88205880_00D0** sp28;
    unk_func_80022C28_ret* temp_s3;

    sp28 = arg3->unk_00;
    temp_s3 = func_80022C28(arg0, arg1, arg2, 1);

    for (i = 0; i < arg3->unk_08; i++) {
        func_80022F24(sp28[i], 1, temp_s3);
    }

    if ((arg0 == 0x10) || (arg0 == 0x11) || (arg0 == 0x12)) {
        func_80022D24(temp_s3);
    } else {
        func_80022D8C(temp_s3);
    }
}

void func_8820B480(unk_func_88200FA0_030_038* arg0, s32 arg1) {
    s32 i;
    unk_func_88205880_00D0** tmp = arg0->unk_00;

    for (i = 0; i < arg0->unk_08; i++) {
        if ((tmp[i]->unk_000[0].unk_00 > 0) && (tmp[i]->unk_000[0].unk_00 < 0x98)) {
            func_800256F4(arg1, tmp[i]->unk_000[0].unk_00, 3);
        }
    }
}

void func_8820B504(unk_func_8820BE14_02C* arg0, s32 arg1) {
    s32 i;
    s32 temp_s5;
    unk_func_8820BE14_06C_000* temp_s4;

    temp_s5 = func_80029080();
    ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_84->unk_40, 2);
    func_8002EEA8(NULL);

    temp_s4 = arg0->unk_8C[0].unk_00;
    for (i = 0; i < 1; i++) {
        if (temp_s4[i].unk_00 != 0) {
            func_8820B3C0(0x20, temp_s5, i, &temp_s4[i].unk_04);
            func_8820B480(&temp_s4[i].unk_04, temp_s5);
        }
    }

    temp_s4 = arg0->unk_8C[1].unk_00;
    for (i = 0; i < 12; i++) {
        if (temp_s4[i].unk_00 != 0) {
            func_8820B3C0(0x21, temp_s5, i, &temp_s4[i].unk_04);
            func_8820B480(&temp_s4[i].unk_04, temp_s5);
        }
    }

    temp_s4 = arg0->unk_8C[2].unk_00;
    for (i = 0; i < 12; i++) {
        if (temp_s4[i].unk_00 != 0) {
            func_8820B3C0(0x11, temp_s5, i, &temp_s4[i].unk_04);
        }
    }

    if (func_882091E4(arg0->unk_30[0]) == 0x30000) {
        func_8002817C(0, 0);
        func_80026E4C(2);
        func_800284B4(2);
    }

    if (arg1 & 4) {
        func_800284B4(3);
    }

    if (arg1 & 3) {
        func_80025540(temp_s5);
        ((func88900970)Memmap_GetFragmentVaddr(func_88900970))(arg0->unk_84, temp_s5);
    }

    if (arg1 & 4) {
        func_80026E4C(3);
        func_800284B4(3);
    }
}

s32 func_8820B714(unk_func_8820BE14_02C* arg0, Controller* arg1) {
    s32 sp34;
    s32 sp30;
    UNUSED s32 pad[2];
    func889006D4 sp24;
    s32 temp_v0_2;

    sp34 = 1;
    sp30 = func_8820B2A4(arg0);

    if (sp30 != 0) {
        arg0->unk_74->unk_28->unk_14(arg0->unk_74->unk_28, 0);

        sp24 = ((func889006D4)Memmap_GetFragmentVaddr(func_889006D4));

        sp24(arg0->unk_84, func_8820B3AC(arg0));

        temp_v0_2 = ((func88900808)Memmap_GetFragmentVaddr(func_88900808))(arg0->unk_84, arg1, 1);
        if (temp_v0_2 == 0) {
            func_8820B504(arg0, sp30);
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_84);
        } else if (temp_v0_2 == 1) {
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_84);
        } else if (temp_v0_2 == 2) {
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_84);
            sp34 = 0;
        }

        arg0->unk_74->unk_28->unk_14(arg0->unk_74->unk_28, 1);
    }
    return sp34;
}

s32 func_8820B838(unk_func_8820B12C* arg0, Controller* arg1) {
    static u8 D_88217FBC[] = { 0x18, 0x19, 0x1A };

    s32 i;
    s32 var_s1;
    s32 temp_v0_8;
    unk_func_8820B12C_000* var_a0;
    s32 sp64;
    u32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    char sp30[0x20];

    var_s1 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_08;
        }
        var_s1 = var_a0->unk_10(var_a0, arg1);
    }

    if (var_s1 & 1) {
        return var_s1;
    }

    if (var_s1 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_s1 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_s1 = 0x80000004;
        } else if (arg1->buttonPressed & 0x30) {
            var_s1 = 0x01000000;
        }
    }

    if (var_s1 & 2) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                func_80048B90(3);
                var_s1 = 2;
                if (func_8820B714(arg0->unk_00.unk_24, arg1) == 0) {
                    var_s1 = 3;
                }
                break;

            case 1:
                ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 0);
                var_s1 |= 1;
                break;
        }
    } else if (var_s1 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 1:
                break;

            case 0:
                switch (arg0->unk_28->unk_24) {
                    case 0:
                    case 1:
                        if (arg0->unk_28->unk_24 == 0) {
                            sp64 = 0;
                        } else {
                            sp64 = 1;
                        }
                        func_80048B90(2);
                        func_88206E80(arg0->unk_00.unk_24->unk_78[sp64],
                                      func_882091E4(arg0->unk_00.unk_24->unk_30[sp64]));
                        func_88206F0C(arg0->unk_00.unk_24->unk_78[sp64],
                                      func_882091E4(arg0->unk_00.unk_24->unk_30[1 - sp64]));

                        arg0->unk_28->unk_14(arg0->unk_28, 0x100);

                        if (func_88207154(arg0->unk_00.unk_24->unk_78[sp64], arg1) == 1) {
                            sp60 = func_88206E50(arg0->unk_00.unk_24->unk_78[sp64]);
                            func_882091F8(arg0->unk_00.unk_24->unk_30[sp64], sp60);
                            func_88217018(arg0->unk_00.unk_24->unk_38[sp64],
                                          (u8*)arg0->unk_00.unk_24->unk_8C[sp60 >> 0x10].unk_00 +
                                              (arg0->unk_00.unk_24->unk_8C[sp60 >> 0x10].unk_0C * (sp60 & 0xFFFF)),
                                          sp60);
                        }
                        arg0->unk_28->unk_14(arg0->unk_28, 1);
                        var_s1 = 1;
                        break;

                    case 2:
                        func_88207D0C(arg0->unk_2C, 0);
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                        var_s1 |= 1;
                        break;

                    case 5:
                        func_88207D0C(arg0->unk_2C, 1);
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                        var_s1 |= 1;
                        break;

                    case 4:
                        func_88207D0C(arg0->unk_2C, 2);
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                        var_s1 |= 1;
                        break;

                    case 6:
                        func_80048B90(3);
                        var_s1 = 2;
                        if (func_8820B714(arg0->unk_00.unk_24, arg1) == 0) {
                            var_s1 = 3;
                        }
                        break;

                    case 3:
                        func_88207D0C(arg0->unk_2C, 3);
                        func_88207BFC(arg0->unk_2C, 0);
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                        var_s1 |= 1;
                        break;
                    case 7:
                        func_88207D0C(arg0->unk_2C, 3);
                        func_88207BFC(arg0->unk_2C, 1);
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                        var_s1 |= 1;
                        break;
                }
                break;
        }
    } else if ((arg0->unk_00.unk_24->unk_40->unk_00.unk_28 & 1) && (var_s1 & 0x01000000)) {
        var_s1 = 1;
        sp5C = (arg1->buttonPressed & 0x20) != 0;
        sp58 = arg0->unk_2C->unk_34;
        switch (arg0->unk_00.unk_1C) {
            case 0:
                sp58 = sp5C;
                break;

            case 1:
                if (func_88208160(arg0->unk_2C) != 0) {
                    sp58 = sp5C;
                }
                break;
        }

        if (sp58 != arg0->unk_2C->unk_34) {
            func_88207D18(arg0->unk_2C);
            func_8820B0E0(arg0->unk_00.unk_24);
            func_88217BC0(arg0->unk_00.unk_24->unk_40);
            ((func8850BFB0)Memmap_GetFragmentVaddr(func_8850BFB0))(arg0);
            var_s1 = 0x80000005;
        }
    } else if (var_s1 & 0x02000000) {
        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 0);

        temp_v0_8 = func_882091E4(arg0->unk_00.unk_24->unk_30[1]);
        sp50 = temp_v0_8 & 0xFFFF;
        sp54 = temp_v0_8 >> 0x10;

        HAL_Strcpy(sp30, func_8002D7C0(NULL, 0, D_88224FB4, D_88217FBC[sp54]));

        if ((sp54 == 1) || (sp54 == 2)) {
            sprintf(&sp30[strlen(sp30)], " %d", sp50 + 1);
        }

        func_8002D5D4(0x25, &sp30);
        func_8002D7C0(arg0->unk_00.unk_24->unk_88->unk_40, 0x80, D_88224FB4, 0x11);

        ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(arg0->unk_00.unk_24->unk_80, arg0->unk_00.unk_24->unk_88,
                                                               2, 0);
        ((func8850A3EC)Memmap_GetFragmentVaddr(func_8850A3EC))(arg0->unk_00.unk_24->unk_80, arg1);

        func_80048B90(0x29);

        var_s1 |= 2;
        if (func_8820B714(arg0->unk_00.unk_24, arg1) == 0) {
            var_s1 |= 1;
        }
    }

    return var_s1;
}

#ifdef NON_MATCHING
void func_8820BE14(unk_func_8820BE14* arg0, s32 arg1, s32 arg2, s32 arg3, MemoryPool* arg4, s32 arg5, char** arg6,
                   char** arg7, char** arg8, char** arg9, char** argA, char** argB) {
    static Color_RGBA8 D_88217FC0 = { 0x1E, 0x50, 0x50, 0xFF };
    static Color_RGBA8 D_88217FC4 = { 0x00, 0x0A, 0x0A, 0xFF };

    s32 i;
    s32 j;
    unk_func_88001300_000* spC4;
    s32 spB4;
    unk_func_8820BE14_06C_000* spA0;
    unk_func_8820BE14_06C* sp5C;
    void (*sp58)(unk_func_88001300_000*, s32, s32, s32, s32);
    s32 temp_s0_2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s3_3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    u32 temp_s0_3;
    u32 temp_s3;
    unk_func_88001300_02C* temp_v0_8;
    unk_func_88200FA0_030_038* var_s0;
    unk_func_88200FA0_030_038* var_s0_2;
    unk_func_88200FA0_030_038* var_s0_3;
    unk_func_8820BE14_06C* temp_a0;
    FragmentEntry temp_v0_7;
    unk_func_88500EE4* temp_s0;
    unk_func_88001300_000* temp_s0_4;
    unk_func_88509A2C* temp_s1;
    unk_func_88509E34* temp_s1_2;
    unk_func_885088F4* temp_s2;
    void* temp_v0;
    unk_func_8820BE14_sp* temp_v0_5;
    void* temp_v0_6;
    unk_func_882062E4* var_s1;
    void* var_s2_4;
    void* var_s2_5;
    void* var_s2_6;
    unk_func_8820BE14_06C_000* var_s4;
    unk_func_8820BE14_06C_000* var_s4_2;
    void* var_s4_3;
    void** temp_t0;
    void** temp_t2;
    void** temp_t4;
    unk_func_8820BE14_06C_000* ptr;
    unk_func_88200FA0_030_038* ptr2;
    s32 count;
    unk_func_882062E4* new_var;

    spA0 = NULL;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, 0x9C);

    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    spB4 = func_80029080();

    var_s1 = mem_pool_alloc(arg4, sizeof(unk_func_882062E4) * (6 + (12 * 20) * 2));
    bzero(var_s1, sizeof(unk_func_882062E4) * (6 + (12 * 20) * 2));

    func_8002C758(&arg0->unk_6C, 0x10, 1, arg4);
    func_8002C758(&arg0->unk_7C, 0x10, 12, arg4);
    func_8002C758(&arg0->unk_8C, 0x10, 12, arg4);

    arg0->unk_6C.unk_08 = 1;
    ptr = arg0->unk_6C.unk_00;
    for (i = 0; i < 1; i++) {
        func_8002CBC0(&ptr[i].unk_04, 6, arg4);
    }

    arg0->unk_7C.unk_08 = 12;
    ptr = arg0->unk_7C.unk_00;
    for (i = 0; i < 12; i++) {
        func_8002CBC0(&ptr[i].unk_04, 20, arg4);
    }

    arg0->unk_8C.unk_08 = 12;
    ptr = arg0->unk_8C.unk_00;
    for (i = 0; i < 12; i++) {
        func_8002CBC0(&ptr[i].unk_04, 20, arg4);
    }

    if (func_8002513C(spB4) == 0) {
        func_80024208(spB4);
    }

    var_s4_2 = var_s4 = arg0->unk_6C.unk_00;
    for (i = 0; i < 1; i++, var_s4_2++, var_s4++) {
        count = func_882062E4(var_s1, 6, 0x20, spB4, i);
        var_s4_2->unk_04.unk_08 = count;

        ptr2 = &var_s4_2->unk_04;
        for (j = 0; j < count; j++) {
            ptr2->unk_00[j] = var_s1++;
        }

        var_s4->unk_00 = 0;
    }

    var_s4_2 = var_s4 = arg0->unk_7C.unk_00;
    for (i = 0; i < 12; i++, var_s4_2++, var_s4++) {
        count = func_882062E4(var_s1, 20, 0x21, spB4, i);
        var_s4_2->unk_04.unk_08 = count;

        ptr2 = &var_s4_2->unk_04;
        for (j = 0; j < count; j++) {
            ptr2->unk_00[j] = var_s1++;
        }

        var_s4->unk_00 = 0;
    }

    var_s4_2 = var_s4 = arg0->unk_8C.unk_00;
    for (i = 0; i < 12; i++, var_s4_2++, var_s4++) {
        count = func_882062E4(var_s1, 20, 0x11, 0, i);
        var_s4_2->unk_04.unk_08 = count;

        ptr2 = &var_s4_2->unk_04;
        for (j = 0; j < count; j++) {
            ptr2->unk_00[j] = var_s1++;
        }

        var_s4->unk_00 = 0;
    }

    if (arg3 == 1) {
        temp_v0_5 = mem_pool_alloc(arg4, sizeof(unk_func_8820BE14_sp));
        func_88206110(temp_v0_5);

        spA0 = mem_pool_alloc(arg4, sizeof(unk_func_8820BE14_06C_000));
        func_8002CBC0(&spA0->unk_04, 1, arg4);

        spA0->unk_04.unk_08 = 1;
        *spA0->unk_04.unk_00 = temp_v0_5;
        spA0->unk_00 = 0;
    }

    spC4 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func885031E8)Memmap_GetFragmentVaddr(func_885031E8))(spC4, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, spC4);

    temp_s0 = mem_pool_alloc(arg4, sizeof(unk_func_88500EE4));
    ((func88500EE4)Memmap_GetFragmentVaddr(func_88500EE4))(temp_s0, 0, 0, 0x280, 0x1E0, D_88223E48, D_88217FC0,
                                                           D_88217FC4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spC4, temp_s0);

    temp_s2 = mem_pool_alloc(arg4, sizeof(unk_func_885088F4));
    ((func885088F4)Memmap_GetFragmentVaddr(func_885088F4))(temp_s2, 0x41, 0x15C, 0xDC);
    temp_s2->unk_2C = 5;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spC4, temp_s2);

    temp_s1 = mem_pool_alloc(arg4, sizeof(unk_func_88509A2C));
    ((func88509A2C)Memmap_GetFragmentVaddr(func_88509A2C))(temp_s1, 0x38, 0x22, func_80029080(),
                                                           func_8002D7C0(NULL, 0, D_88224FB0, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s2, temp_s1);

    temp_s1_2 = mem_pool_alloc(arg4, sizeof(unk_func_88509E34));
    ((func88509E34)Memmap_GetFragmentVaddr(func_88509E34))(temp_s1_2, 0, 0, func_8002D7C0(NULL, 0, D_88224FB4, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s2, temp_s1_2);

    temp_s0_4 = mem_pool_alloc(arg4, sizeof(unk_func_88001300_000));
    ((func885031E8)Memmap_GetFragmentVaddr(func_885031E8))(temp_s0_4, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, temp_s0_4);

    temp_v0_7 = FRAGMENT_LOAD(fragment27);

    arg0->unk_30.unk_04 = arg4;
    arg0->unk_30.unk_00 = 0x38;
    arg0->unk_30.unk_02 = 0x52;
    arg0->unk_30.unk_14 = temp_s0_4;
    arg0->unk_30.unk_18 = 0;

    arg0->unk_4C = arg7;
    arg0->unk_50 = D_88224FB8;
    arg0->unk_54 = D_88224FBC;
    arg0->unk_58 = arg8;
    arg0->unk_5C = arg9;
    arg0->unk_60 = argA;
    arg0->unk_64 = argB;

    temp_v0_7(0, &arg0->unk_30);

    arg0->unk_68 = mem_pool_alloc(arg4, sizeof(unk_func_88509F48));
    ((func88509F48)Memmap_GetFragmentVaddr(func_88509F48))(arg0->unk_68, 0x2C, 0x4C, 0x228, 0x160, arg4, arg5);

    arg0->unk_2C = mem_pool_alloc(arg4, sizeof(unk_func_8820BE14_02C));
    func_88209B54(arg0->unk_2C, 0x2C, 0x4C, spA0, &arg0->unk_6C, spC4, temp_v0_7, &arg0->unk_30, arg0->unk_68, arg6,
                  arg4);

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s0_4, arg0->unk_2C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(&arg0->unk_00, arg0->unk_30.unk_08);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s0_4, arg0->unk_68);
}
#else
static Color_RGBA8 D_88217FC0 = { 0x1E, 0x50, 0x50, 0xFF };
static Color_RGBA8 D_88217FC4 = { 0x00, 0x0A, 0x0A, 0xFF };
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1AE680/func_8820BE14.s")
#endif

void func_8820C510(unk_func_8820BE14* arg0) {
    volatile s32 sp34 = 0;

    while (sp34 == 0) {
        func_80015348();
        func_800079C4();

        ((func885008C4)Memmap_GetFragmentVaddr(func_885008C4))(&arg0->unk_00);
        ((func88500828)Memmap_GetFragmentVaddr(func_88500828))(&arg0->unk_00, 0, 0);

        func_80007778();
        func_8002EF18(&sp34);
    }
}

void func_8820C5BC(unk_func_8820BE14* arg0) {
    s32 sp24 = func_8820AFC4(arg0->unk_2C, gPlayer1Controller);

    while (arg0->unk_2C->unk_2C->unk_28 & 1) {
        func_8002EEA8(0);
    }

    func_8002EEA8(sp24);
    osStopThread(NULL);
}

void func_8820C63C(unk_func_8820BE14* arg0) {
    s32 sp24;
    s32 var_s0;

    func_80006C6C(8);

    var_s0 = 8;
    while (var_s0-- > 0) {
        func_8002EEA8(NULL);
    }

    sp24 = func_8820AFC4(arg0->unk_2C, gPlayer1Controller);

    while (arg0->unk_2C->unk_2C->unk_28 & 1) {
        func_8002EEA8(NULL);
    }

    func_80006CB4(8);

    var_s0 = 10;
    while (var_s0-- > 0) {
        func_8002EEA8(NULL);
    }

    func_8002EEA8(sp24);

    osStopThread(NULL);
}

void func_8820C700(s32 arg0, s32 arg1) {
    static ThreadEntries D_88217FC8[] = { func_8820C5BC, func_8820C63C };

    MemoryPool* sp5C;
    void* sp58;
    u8* sp54;
    func_88002628_sp38* sp50;
    char** sp4C;
    char** sp48;
    char** sp44;
    char** sp40;
    char** sp3C;
    char** sp38;

    main_pool_push_state('OTPC');

    FRAGMENT_LOAD(fragment25);

    func_8001B058();

    sp54 = main_pool_alloc(0x10000, 0);
    sp5C = mem_pool_try_init(0x18000, 0);

    if (arg1 == 1) {
        func_80028AFC(2);
    }
    func_8002D510();

    D_88224FB0 = func_8002D5AC(0x2A);
    D_88224FB4 = func_8002D5AC(2);
    D_88224FB8 = func_8002D5AC(0x24);
    D_88224FBC = func_8002D5AC(0x25);

    sp4C = func_8002D5AC(7);
    sp48 = func_8002D5AC(6);
    sp44 = func_8002D5AC(0x26);
    sp40 = func_8002D5AC(0x28);
    sp3C = func_8002D5AC(0x29);
    sp38 = func_8002D5AC(0xB);

    sp58 = mem_pool_alloc(sp5C, sizeof(unk_func_8820BE14));
    func_8820BE14(sp58, 0, 0, arg1, sp5C, arg0, sp4C, sp48, sp44, sp40, sp3C, sp38);

    sp50 = ALIGN16((u32)mem_pool_alloc(sp5C, sizeof(func_88002628_sp38)));

    osCreateThread(&sp50->thread, 0x32, D_88217FC8[arg1], sp58, sp54 + 0x10000, osGetThreadPri(NULL) - 1);

    func_8002EE78();
    func_8001F738(gPlayer1Controller);

    osStartThread(&sp50->thread);

    func_8820C510(sp58);

    osDestroyThread(&sp50->thread);

    main_pool_pop_state('OTPC');
}
