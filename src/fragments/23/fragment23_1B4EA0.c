#include "fragment23.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/22630.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/2D340.h"
#include "src/2E110.h"
#include "src/2E460.h"
#include "src/49790.h"
#include "src/hal_libc.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_88218060 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Color_RGBA8* unk_04;
} unk_D_88218060; // size = 0x8

typedef struct unk_D_88218070 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8* unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x10 */ Color_RGBA8* unk_10;
} unk_D_88218070; // size = 0x14

static char** D_88224FC0;
static char** D_88224FC4;
static char** D_88224FC8;
static char** D_88224FCC;

void func_8820C930(s32 arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C* arg3) {
    unk_func_80022C28_ret* sp1C = func_80022C28(arg0, arg1, arg2, 0);

    arg3->unk_08 = func_80022E18(arg3->unk_00, arg3->unk_04, sp1C);
    func_80022D8C(sp1C);
}

void func_8820C97C(s32 arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C* arg3, s32 arg4, char* arg5, s32 arg6) {
    unk_func_80022C28_ret* sp2C;

    if (arg6 != -1) {
        if (1) {}
        sp2C = func_80022CC0(arg0, arg1, arg2, arg4, arg5, arg6);
    } else {
        sp2C = func_80022C28(arg0, arg1, arg2, 1);
    }

    func_80022F24(arg3->unk_00, arg3->unk_08, sp2C);

    if ((arg0 == 0x10) || (arg0 == 0x11) || (arg0 == 0x12)) {
        func_80022D24(sp2C);
    } else {
        func_80022D8C(sp2C);
    }
}

void func_8820CA2C(unk_func_8821421C_07C* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        arg0[i].unk_00 = func_80027164(0x12, i);
        if (arg0[i].unk_00 != 0) {
            arg0[i].unk_04 = func_80027184(0x12, i) & 0xFFFF;
            func_800272BC(0x12, i, arg0[i].unk_08);
        }
    }
}

s32 func_8820CAB4(unk_func_8821421C_07C* arg0, s32 arg1, char* arg2) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if ((arg0[i].unk_00 != 0) && (arg1 == arg0[i].unk_04) && (HAL_Strcmp(arg0[i].unk_08, arg2) == 0)) {
            return i;
        }
    }

    for (i = 0; i < 4; i++) {
        if (arg0[i].unk_00 == 0) {
            return i;
        }
    }

    return -1;
}

void func_8820CBA0(unk_func_8821421C_02C_030* arg0, unk_func_8850143C* arg1, spE8_func_882121E0* arg2) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8821421C_02C_030));

    arg0->unk_00.unk_18 = func_8820CC30;
    arg0->unk_00.unk_14.unk_00 = arg1->unk_00.unk_14.unk_00;
    arg0->unk_00.unk_14.unk_02 = arg1->unk_00.unk_14.unk_02;
    arg0->unk_2C = arg1;
    arg0->unk_30 = func_8002EC08(func_80024F68(func_80029080()));
    arg0->unk_34 = -1;
    arg0->unk_38 = arg2;
}

s32 func_8820CC30(unk_func_8821421C_02C_030* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88217FD0 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88217FD4 = { 0x7F, 0x7F, 0x7F, 0xFF };

    s32 temp_v0;
    s32 var_s0;

    if (arg0->unk_34 == -1) {
        return 1;
    }

    temp_v0 = func_8001F5B0(8, 0, arg0->unk_38->unk_00[arg0->unk_34], arg0->unk_34);

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
    func_8001F324(D_88217FD0.r, D_88217FD0.g, D_88217FD0.b, D_88217FD0.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(var_s0, arg2 + 5, arg0->unk_38->unk_00[arg0->unk_34]);
    func_8001F444();

    return 0;
}

s32 func_8820D0E4(unk_func_8821421C_02C_030* arg0) {
    return arg0->unk_34;
}

void func_8820D0EC(unk_func_8821421C_02C_030* arg0, s32 arg1) {
    arg0->unk_34 = arg1;
}

void func_8820D0F4(unk_func_8821421C_034* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    static Color_RGBA8 D_88217FD8 = { 0x64, 0x96, 0xB4, 0xFF };
    static Color_RGBA8 D_88217FDC = { 0x3C, 0x64, 0x78, 0xFF };
    static Color_RGBA8 D_88217FE0 = { 0x99, 0x99, 0x89, 0xFF };
    static Color_RGBA8 D_88217FE4 = { 0xFF, 0xFF, 0x00, 0xFF };

    UNUSED s32 pad[2];
    unk_func_88001300_03C* ptr;
    unk_func_8850B254* sp60;
    unk_func_885012A4* sp5C;
    unk_func_88001300_000* sp58;
    unk_func_88001300_000* sp54;
    unk_func_8850878C* sp50;
    unk_func_8850878C* sp4C;
    unk_func_88001300_03C_01C* sp48;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8821421C_034));

    arg0->unk_00.unk_20 = func_8820D564;
    arg0->unk_00.unk_24 = func_8820D5E8;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, 0x100, 0x3C);

    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    sp60 = mem_pool_alloc(arg3, sizeof(unk_func_8850B254));
    ((func8850B254)Memmap_GetFragmentVaddr(func_8850B254))(sp60, 0, 0, 0x100, 0x14, D_88217FD8, D_88217FDC);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp60);

    arg0->unk_34 = mem_pool_alloc(arg3, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_34, 8, 0, "Do?", 8);
    arg0->unk_34->unk_3C = 0x18;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_34);

    sp5C = mem_pool_alloc(arg3, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp5C, 0, 0x18, 0x100, 0x24, D_88217FE0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp5C);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_88001300_03C));
    ((func8850C284)Memmap_GetFragmentVaddr(func_8850C284))(arg0->unk_30, 1, 2, arg3);

    sp54 = mem_pool_alloc(arg3, sizeof(unk_func_88001300_000));
    ((func8850A40C)Memmap_GetFragmentVaddr(func_8850A40C))(sp54, 0x28, 6, 0x48, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp5C, sp54);
    ptr = arg0->unk_30;
    ptr->unk_18[0] = sp54;

    sp50 = mem_pool_alloc(arg3, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp50, 0xA, 2, func_8002D7C0(NULL, 0, D_88224FC4, 0x17), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp54, sp50);

    sp58 = mem_pool_alloc(arg3, sizeof(unk_func_88001300_000));
    ((func8850A40C)Memmap_GetFragmentVaddr(func_8850A40C))(sp58, 0x90, 6, 0x48, 0x18);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp5C, sp58);
    ptr = arg0->unk_30;
    ptr->unk_18[1] = sp58;

    sp4C = mem_pool_alloc(arg3, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp4C, 6, 2, func_8002D7C0(NULL, 0, D_88224FC4, 0x18), 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp58, sp4C);
    ((func8850CAB4)Memmap_GetFragmentVaddr(func_8850CAB4))(arg0->unk_30);

    sp48 = mem_pool_alloc(arg3, sizeof(unk_func_88001300_03C_01C));
    ((func88503340)Memmap_GetFragmentVaddr(func_88503340))(sp48, 0, 0, 0x10, 0x10, D_88217FE4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp5C, sp48);
    arg0->unk_30->unk_1C = sp48;
}

s32 func_8820D564(unk_func_8821421C_034* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_10(arg0->unk_30, arg1);
        if (var_v1 == 0) {
            if (arg1->buttonPressed & 0x4000) {
                var_v1 = 0x80000002;
            } else if (arg1->buttonPressed & 0x8000) {
                var_v1 = 0x80000004;
            }
        }
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_8820D5E8(unk_func_8821421C_034* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_30->unk_14(arg0->unk_30, arg1);
}

void func_8820D614(unk_func_8821421C_034* arg0, char* arg1) {
    arg0->unk_34->unk_40 = arg1;
}

s32 func_8820D620(unk_func_8821421C_034* arg0, Controller* arg1) {
    s32 var_s0;
    s32 var_s1 = 0;

    arg0->unk_30->unk_14(arg0->unk_30, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);

    while (var_s1 == 0) {
        func_8002EEA8(var_s1);

        var_s0 = func_8820D564(arg0, arg1);

        if (!(var_s0 & 1)) {
            if (var_s0 & 2) {
                var_s1 = 1;
            } else if (var_s0 & 4) {
                switch (arg0->unk_30->unk_24) {
                    case 0:
                        var_s1 = 2;
                        func_80048B90(0x1F);
                        var_s0 = 1;
                        break;

                    case 1:
                        var_s0 = (var_s0 & ~4) | 2;
                        var_s1 = 1;
                        break;
                }
            }
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(var_s0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s1 - 1;
}

s32 func_8820D754(spE8_func_882121E0* arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s1 = 0;
    s32 i;

    for (i = 0; i < arg1; i++) {
        temp_v0 = func_8001F5B0(8, 0, arg0->unk_00[i]);
        if (var_s1 < temp_v0) {
            var_s1 = temp_v0;
        }
    }

    return var_s1;
}

void func_8820D7C8(s32 arg0, s32 arg1, s8* arg2, s32 arg3, s32 arg4, unk_func_88200FA0_030_030* arg5) {
    static Color_RGBA8 D_88217FE8[] = {
        { 0xF0, 0xF0, 0xF0, 0xFF }, { 0xF0, 0xF0, 0xF0, 0x4D }, { 0xF0, 0xF0, 0x00, 0xFF },
        { 0xCB, 0xFF, 0xD6, 0xFF }, { 0xB2, 0xFF, 0xC3, 0xFF },
    };
    static Color_RGBA8 D_88217FFC = { 0x6C, 0x6C, 0x7E, 0xFF };

    Color_RGBA8 sp3C;
    s32 temp_t2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_t2 = ((D_88217FFC.r << 8) & 0xF800) | ((D_88217FFC.g * 8) & 0x7C0) | ((D_88217FFC.b >> 2) & 0x3E) | 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetFillColor(gDisplayListHead++, (temp_t2 << 0x10) | temp_t2);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_3C + arg0) - 1, (arg1 + arg5->unk_3E) - 1);

    func_8001F3F4();

    if (arg4 & 0x100) {
        sp3C = D_88217FE8[2];
    } else if (arg4 & 4) {
        sp3C = D_88217FE8[1];
    } else {
        sp3C = D_88217FE8[0];
    }

    func_8001F324(sp3C.r, sp3C.g, sp3C.b, sp3C.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(arg0 + 8, arg1 + 4, arg2);
    func_8001F444();
}

void func_8820D9B8(unk_func_8821421C_02C_070* arg0, s32 arg1, s32 arg2, s32 arg3, spE8_func_882121E0* arg4, s32 arg5,
                   s32 arg6, MemoryPool* arg7) {
    s32 sp4C = func_8820D754(arg4, arg5) + 0x10;
    UNUSED s32 pad;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8821421C_02C_070));

    arg0->unk_00.unk_20 = func_8820DB98;
    arg0->unk_00.unk_24 = func_8820DBE4;
    arg0->unk_00.unk_10.unk_00 = ((arg3 - sp4C) / 2) + arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_40 = arg6;

    func_8002CBB0(&arg0->unk_34, arg4, arg5, arg5);

    arg0->unk_2C = mem_pool_alloc(arg7, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, sp4C, arg5 * 0x1C);

    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    arg0->unk_30 = mem_pool_alloc(arg7, sizeof(unk_func_88200FA0_030_030));
    ((func885060BC)Memmap_GetFragmentVaddr(func_885060BC))(arg0->unk_30, 0, 0, func_8820D7C8, sp4C, 0x1C, arg5, 1,
                                                           arg7);
    ((func88506384)Memmap_GetFragmentVaddr(func_88506384))(arg0->unk_30, &arg0->unk_34, arg7);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_30);
}

s32 func_8820DB98(unk_func_8821421C_02C_070* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_8820DBE4(unk_func_8821421C_02C_070* arg0, s32 arg1) {
    unk_func_88200FA0_030_030* temp_a0;

    arg0->unk_00.unk_2A = arg1;
    arg0->unk_30->unk_00.unk_24(&arg0->unk_30->unk_00, arg1);
}

s32 func_8820DC10(unk_func_8821421C_02C_070* arg0) {
    return arg0->unk_30->unk_38;
}

void func_8820DC1C(unk_func_8821421C_02C_070* arg0, s32 arg1) {
    arg0->unk_44 = arg1;

    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_30);
    ((func88506BFC)Memmap_GetFragmentVaddr(func_88506BFC))(arg0->unk_30, arg0->unk_44);

    arg0->unk_30->unk_34[arg0->unk_30->unk_38] |= 0x100;
}

void func_8820DC90(unk_func_8821421C_02C_070* arg0) {
    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);
}

void func_8820DCC4(unk_func_8821421C_02C_070* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
}

s32 func_8820DCD4(unk_func_8821421C_02C_070* arg0, Controller* arg1) {
    s32 var_s0;
    s32 var_s1 = 0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    while (var_s1 == 0) {
        func_8002EEA8(NULL);

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

    return var_s1 - 1;
}

void func_8820DDC0(unk_func_8821421C_02C_070* arg0, s32 arg1) {
    arg0->unk_48 = arg1;
    arg0->unk_30->unk_34[arg1] |= 4;
}

s32 func_8820DDE4(u8* arg0, s32 arg1, s32 arg2, s32 arg3) {
    static Color_RGBA8 D_88218000 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_88218004[] = {
        { 0xFF, 0xCB, 0xDE, 0xFF },
        { 0xFF, 0xBF, 0xD6, 0xFF },
        { 0x5A, 0x5A, 0xA6, 0xFF },
    };

    Color_RGBA8 sp34;
    s8 sp2C[8];
    UNUSED s32 pad;
    s8* sp24;

    func_8001F3F4();
    func_8001EBE0(8, 0);

    if (func_8002F1C0(arg0[0]) != 0) {
        sp34 = D_88218004[0];
    } else {
        sp34 = D_88218000;
    }

    func_8001F324(sp34.r, sp34.g, sp34.b, sp34.a);
    func_8001F1E8(arg1 + 0x19, arg2 + 4, func_8002D7C0(NULL, 0, D_88224FC8, arg0[0] - 1));

    if (func_8002F264(arg0[0]) == 0) {
        sp24 = func_8002D7C0(NULL, 0, D_88224FC4, 0x19);
        sprintf(sp2C, "%s00", sp24);
        func_8001EBE0(4, 0);
        func_8001F1E8(((arg1 + arg3) - func_8001F5B0(0, 0, &sp2C)) - 0x19, arg2 + 8, "%s%02d", sp24, arg0[1]);
    }
    func_8001F444();
}

void func_8820DF38(s32 arg0, s32 arg1, u8* arg2, s32 arg3, s32 arg4, unk_func_8820BE14_02C_038* arg5) {
    static Color_RGBA8 D_88218010[] = { 0x40, 0x40, 0x74, 0xFF };
    static Color_RGBA8 D_88218014[] = {
        { 0x78, 0x78, 0xF1, 0xFF },
        { 0x5E, 0x5E, 0xBE, 0xFF },
    };

    Color_RGBA8 spD4;

    if (arg2 != NULL) {
        s32 temp_t1;
        s32 temp_t0;
        s32 temp_t4;
        s32 temp_a3;

        if (arg4 & 2) {
            spD4 = func_8002D444(D_88218010[0], 1.4f);
        } else {
            spD4 = D_88218010[0];
        }

        gDPPipeSync(gDisplayListHead++);

        gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
        gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

        temp_t1 = ((spD4.r << 8) & 0xF800) | ((spD4.g << 3) & 0x7C0) | ((spD4.b >> 2) & 0x3E) | 1;

        gDPPipeSync(gDisplayListHead++);

        gDPSetFillColor(gDisplayListHead++, temp_t1 | (temp_t1 << 0x10));
        gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, arg0 + 0xEB, arg1 + 0x1A);

        temp_a3 =
            ((D_88218014[1].r << 8) & 0xF800) | ((D_88218014[1].g << 3) & 0x7C0) | ((D_88218014[1].b >> 2) & 0x3E) | 1;

        gDPPipeSync(gDisplayListHead++);

        gDPSetFillColor(gDisplayListHead++, temp_a3 | (temp_a3 << 0x10));
        gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + 0xEB, arg1);

        temp_t4 =
            ((D_88218014[1].r << 8) & 0xF800) | ((D_88218014[1].g << 3) & 0x7C0) | ((D_88218014[1].b >> 2) & 0x3E) | 1;

        gDPPipeSync(gDisplayListHead++);

        gDPSetFillColor(gDisplayListHead++, temp_t4 | (temp_t4 << 0x10));
        gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 0x1B, arg0 + 0xEB, arg1 + 0x1B);

        if (!(arg4 & 0x100)) {
            func_8820DDE4(arg2, arg0, arg1, arg5->unk_00.unk_3C);
        }
    } else {
        s32 temp_t1;
        s32 temp_t0;
        s32 temp_t4;
        s32 temp_a3;

        if (arg4 & 1) {
            spD4 = D_88218010[0];

            gDPPipeSync(gDisplayListHead++);

            gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
            gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

            temp_t1 = ((spD4.r << 8) & 0xF800) | ((spD4.g << 3) & 0x7C0) | ((spD4.b >> 2) & 0x3E) | 1;

            gDPPipeSync(gDisplayListHead++);

            gDPSetFillColor(gDisplayListHead++, temp_t1 | (temp_t1 << 0x10));
            gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, arg0 + 0xEB, arg1 + 0x1A);

            temp_a3 = ((D_88218014[1].r << 8) & 0xF800) | ((D_88218014[1].g << 3) & 0x7C0) |
                      ((D_88218014[1].b >> 2) & 0x3E) | 1;

            gDPPipeSync(gDisplayListHead++);

            gDPSetFillColor(gDisplayListHead++, temp_a3 | (temp_a3 << 0x10));
            gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + 0xEB, arg1);

            temp_t4 = ((D_88218014[1].r << 8) & 0xF800) | ((D_88218014[1].g << 3) & 0x7C0) |
                      ((D_88218014[1].b >> 2) & 0x3E) | 1;

            gDPPipeSync(gDisplayListHead++);

            gDPSetFillColor(gDisplayListHead++, temp_t4 | (temp_t4 << 0x10));
            gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 0x1B, arg0 + 0xEB, arg1 + 0x1B);
        } else {
            spD4 = func_8002D444(D_88218010[0], 0.8f);

            gDPPipeSync(gDisplayListHead++);

            gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
            gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

            temp_t0 = ((spD4.r << 8) & 0xF800) | ((spD4.g << 3) & 0x7C0) | ((spD4.b >> 2) & 0x3E) | 1;

            gDPPipeSync(gDisplayListHead++);

            gDPSetFillColor(gDisplayListHead++, temp_t0 | (temp_t0 << 0x10));
            gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + 0xEB, arg1 + 0x1B);
        }
    }
}

void func_8820E5BC(unk_func_8821421C_02C_06C_02C_060* arg0, s32 arg1, s32 arg2, s32 arg3) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8821421C_02C_06C_02C_060));

    arg0->unk_00.unk_18 = func_8820E654;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_00.unk_14.unk_00 = arg3;
    arg0->unk_00.unk_14.unk_02 = 0;
    arg0->unk_2C.unk_00.unk_00 = 1;
    arg0->unk_2C.unk_00.unk_01 = 1;
}

void func_8820E638(unk_func_8821421C_02C_06C_02C_060* arg0, unk_func_8821421C_02C_06C_02C_060_02C_000 arg1) {
    arg0->unk_2C.unk_00 = arg1;
}

s32 func_8820E654(unk_func_8821421C_02C_06C_02C_060* arg0, s32 arg1, s32 arg2) {
    return func_8820DDE4(&arg0->unk_2C, arg1, arg2, arg0->unk_00.unk_14.unk_00);
}

void func_8820E680(unk_func_8820E99C_030* arg0, s32 arg1) {
    arg0->unk_30.unk_0C = 2;
    arg0->unk_30.unk_00 = 1;
    arg0->unk_30.unk_04 = 1;
    arg0->unk_30.unk_08 = arg1;
    arg0->unk_30.unk_10 = 0;
}

void func_8820E6A0(unk_func_8820E99C_030* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    s32 sp2C;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8820E99C_030));

    arg0->unk_00.unk_1C = func_8820E818;
    arg0->unk_00.unk_18 = func_8820E850;
    arg0->unk_00.unk_20 = func_8820E90C;
    arg0->unk_00.unk_24 = func_8820E7B0;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    func_8820E680(arg0, 0);
    sp2C = func_8001F5B0(8, 0, "0");

    arg0->unk_44 = mem_pool_alloc(arg3, sizeof(unk_func_8820E99C_030_044));
    ((func88504F98)Memmap_GetFragmentVaddr(func_88504F98))(arg0->unk_44, -1, 0, sp2C + 2, 0x14);
    arg0->unk_44->unk_00.unk_28 &= ~1;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_44);
}

void func_8820E7B0(unk_func_8820E99C_030* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_44->unk_00.unk_24(&arg0->unk_44->unk_00, arg1);
    arg0->unk_44->unk_00.unk_28 &= ~1;
    if (arg1 & 0x101) {
        arg0->unk_44->unk_00.unk_28 |= 1;
    }
}

s32 func_8820E818(unk_func_8820E99C_030* arg0) {
    s32 tmp = ((arg0->unk_30.unk_0C - arg0->unk_30.unk_10) - 1) * arg0->unk_44->unk_00.unk_14.unk_00;

    arg0->unk_44->unk_00.unk_10.unk_00 = tmp;
    arg0->unk_44->unk_00.unk_10.unk_02 = arg0->unk_44->unk_00.unk_10.unk_02;
    return 0;
}

s32 func_8820E850(unk_func_8820E99C_030* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_8821801C = { 0xF0, 0xF0, 0xF0, 0xFF };

    func_8001F3F4();
    func_8001EBE0(8, 0);
    func_8001F324(D_8821801C.r, D_8821801C.g, D_8821801C.b, D_8821801C.a);
    func_8001F2E4(arg1, arg2, (arg0->unk_30.unk_00 / 10) + 0x30);
    func_8001F2E4(arg0->unk_44->unk_00.unk_14.unk_00 + arg1, arg2, (arg0->unk_30.unk_00 % 10) + 0x30);
    func_8001F444();
    return 0;
}

s32 func_8820E90C(unk_func_8820E99C_030* arg0, Controller* arg1) {
    s32 sp1C = 0;

    if (func_8002E0F4(&arg0->unk_30) == 0) {
        if (arg1->buttonPressed & 0x4000) {
            sp1C = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            sp1C = 0x80000004;
        }
    } else {
        sp1C = 8;
    }
    return sp1C;
}

void func_8820E978(unk_func_8820E99C* arg0, s32 arg1, s32 arg2) {
    arg0->unk_34 = arg2;
    func_8820E680(arg0->unk_30, arg1);
}

void func_8820E99C(unk_func_8820E99C* arg0, s32 arg1, s32 arg2, MemoryPool* arg3) {
    static Color_RGBA8 D_88218020 = { 0x6C, 0x6C, 0x7E, 0xFF };

    char* sp44;
    s32 sp40;
    UNUSED s32 pad;
    unk_func_885012A4* sp38;
    unk_func_8850878C* sp34;

    sp44 = func_8002D7C0(NULL, 0, D_88224FC4, 0x19);
    sp40 = func_8001F5B0(8, 0, sp44) + 0xC + (func_8001F5B0(8, 0, "0") * 2);

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8820E99C));

    arg0->unk_00.unk_20 = func_8820EC1C;
    arg0->unk_00.unk_24 = func_8820EBF0;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, sp40, 0x28);

    arg0->unk_2C->unk_00.unk_28 |= 0x200;
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    arg0->unk_2C->unk_00.unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    sp38 = mem_pool_alloc(arg3, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp38, 0, 0, sp40, 0x28, D_88218020);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp38);

    sp34 = mem_pool_alloc(arg3, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(sp34, 4, 0xA, sp44, 8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp38, sp34);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_8820E99C_030));
    func_8820E6A0(arg0->unk_30, func_8001F5B0(8, 0, sp44) + 6, 0xA, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp38, arg0->unk_30);
    func_8820E978(arg0, 0, 0);
}

void func_8820EBF0(unk_func_8820E99C* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_30->unk_00.unk_24(&arg0->unk_30->unk_00, arg1);
}

s32 func_8820EC1C(unk_func_8820E99C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = arg0->unk_30->unk_00.unk_20(arg0->unk_30, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_8820EC68(unk_func_8820E99C* arg0) {
    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);
}

void func_8820EC9C(unk_func_8820E99C* arg0) {
    arg0->unk_2C->unk_2C = 0xB;
}

void func_8820ECAC(unk_func_8821421C_038_02C* arg0, unk_func_8850143C* arg1) {
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8821421C_038_02C));

    arg0->unk_00.unk_18 = func_8820ED14;
    arg0->unk_00.unk_14.unk_00 = arg1->unk_00.unk_14.unk_00;
    arg0->unk_00.unk_14.unk_02 = arg1->unk_00.unk_14.unk_02;
    arg0->unk_30 = 0;
    arg0->unk_2C = arg1;
}

s32 func_8820ED14(unk_func_8821421C_038_02C* arg0, s32 arg1, s32 arg2) {
    static Color_RGBA8 D_88218024 = { 0xF0, 0xF0, 0xF0, 0xFF };

    if (arg0->unk_30 == 0) {
        return 1;
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    gDPLoadTextureBlock(gDisplayListHead++, D_88223488, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 26, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg1 + 5) << 2, (arg2 + 2) << 2, (arg1 + 0x2C) << 2, (arg2 + 0x1B) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    gDPPipeSync(gDisplayListHead++);

    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

    func_8001F3F4();
    func_8001F324(D_88218024.r, D_88218024.g, D_88218024.b, D_88218024.a);
    func_8001EBE0(8, 0);
    func_8001F1E8(arg1 + 0x35, arg2 + 4, &arg0->unk_30->unk_08);
    func_8001F444();

    return 0;
}

void func_8820EFD0(unk_func_8821421C_038_02C* arg0, unk_func_8821421C_038_050* arg1) {
    arg0->unk_30 = arg1;
}

void func_8820EFD8(s32 arg0, s32 arg1, unk_func_8820EFD8* arg2, s32 arg3, s32 arg4, unk_func_8821421C_038_034* arg5) {
    static Color_RGBA8 D_88218028 = { 0xF0, 0xF0, 0xF0, 0xFF };
    static Color_RGBA8 D_8821802C = { 0x6C, 0x6C, 0x7E, 0xFF };
    static Color_RGBA8 D_88218030 = { 0xAE, 0xAE, 0xCB, 0xFF };
    static Color_RGBA8 D_88218034[] = {
        {
            0x0,
            0x0,
            0x0,
            0x40,
        },
        {
            0x0,
            0x0,
            0x0,
            0x28,
        },
        {
            0x0,
            0x0,
            0x0,
            0x3C,
        },
        {
            0x88,
            0x22,
            0xC,
            0xD0,
        },
    };

    Color_RGBA8 sp6C;
    UNUSED s32 pad;
    char* sp64;
    UNUSED s32 pad2;
    s32 temp_a3;
    s32 temp_t4;

    if (arg4 & 2) {
        sp6C = func_8002D444(D_8821802C, 1.4f);
    } else {
        sp6C = D_8821802C;
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    temp_a3 = ((sp6C.r << 8) & 0xF800) | ((sp6C.g * 8) & 0x7C0) | ((sp6C.b >> 2) & 0x3E) | 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetFillColor(gDisplayListHead++, (temp_a3 << 0x10) | temp_a3);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1 + 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 2);

    temp_t4 = ((D_88218030.r << 8) & 0xF800) | ((D_88218030.g * 8) & 0x7C0) | ((D_88218030.b >> 2) & 0x3E) | 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetFillColor(gDisplayListHead++, (temp_t4 << 0x10) | temp_t4);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg5->unk_00.unk_3C + arg0) - 1, arg1);

    temp_t4 = ((D_88218030.r << 8) & 0xF800) | ((D_88218030.g * 8) & 0x7C0) | ((D_88218030.b >> 2) & 0x3E) | 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetFillColor(gDisplayListHead++, (temp_t4 << 0x10) | temp_t4);
    gDPFillRectangle(gDisplayListHead++, arg0, (arg1 + arg5->unk_00.unk_3E) - 1, (arg5->unk_00.unk_3C + arg0) - 1,
                     (arg1 + arg5->unk_00.unk_3E) - 1);

    func_8001F3F4();
    func_8001F324(D_88218028.r, D_88218028.g, D_88218028.b, D_88218028.a);
    func_8001EBE0(0x10, 0);

    sp64 = func_8002D7C0(NULL, 0, D_88224FC4, 0x14);
    func_8001F1E8(arg0 + 8, arg1 + 6, sp64);
    func_8001F1E8(func_8001F5B0(0, 0, sp64) + arg0 + 8, arg1 + 6, "%s", &arg2->unk_08);
    func_8001EBE0(8, 0);

    sp64 = func_8002D7C0(NULL, 0, D_88224FC4, 0x15);
    func_8001F1E8(arg0 + 0xD, arg1 + 0x24, sp64);
    func_8001F1E8(func_8001F5B0(0, 0, sp64) + arg0 + 0xD, arg1 + 0x24, "%05d", arg2->unk_04);
    func_8001F444();
}

void func_8820F3B8(unk_func_8821421C_038* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3,
                   unk_func_8821421C_034* arg4, MemoryPool* arg5) {
    static Color_RGBA8 D_88218044 = { 0x6C, 0x6C, 0x7E, 0xFF };
    static Color_RGBA8 D_88218048 = { 0x50, 0x50, 0x86, 0xFF };
    static Color_RGBA8 D_8821804C = { 0x79, 0x79, 0xCB, 0xFF };
    static Color_RGBA8 D_88218050 = { 0x40, 0x40, 0x6C, 0xFF };
    static Color_RGBA8 D_88218054 = { 0x6A, 0x6A, 0xB2, 0xFF };
    static Color_RGBA8 D_88218058 = { 0x2D, 0x1A, 0x41, 0xFF };
    static Color_RGBA8 D_8821805C = { 0x6F, 0x5F, 0x7F, 0xFF };
    static unk_D_88218060 D_88218060[] = {
        { 17, D_88218210 },
        { 18, D_88218218 },
    };
    static unk_D_88218070 D_88218070[] = {
        {
            249,
            110,
            54,
            42,
            D_8821B868,
            48,
            D_882181D0,
        },
        {
            249,
            168,
            54,
            42,
            D_8821C5F0,
            48,
            D_882181D8,
        },
    };
    static Color_RGBA8 D_88218098 = { 0xFF, 0xFF, 0x00, 0xFF };

    unk_func_8850BD40* temp_s0_7;
    unk_func_88503298* temp_s0_8;
    unk_func_8850878C* temp_s0_3;
    unk_func_8850878C* temp_s0_4;
    unk_func_885012A4* spB4;
    unk_func_885012A4* spB0;
    unk_func_885012A4* spAC;
    unk_func_885012A4* spA8;
    unk_func_885012A4* spA4;
    unk_func_885012A4* spA0;
    unk_func_885012A4* sp9C;
    unk_func_88001300_000* sp98;
    unk_func_88001300_000* sp94;
    unk_func_8850BD40* temp_s0_5;
    unk_func_88001300_03C_01C* temp_s0_6;
    unk_func_88001300_038* temp_v0_2;
    unk_func_88001300_038* temp_v0_3;
    unk_func_88001300_038* temp_v0_4;
    char* sp7C;
    unk_func_8820BE14_02C_038* temp_v0_8;
    s32 i;
    unk_func_882149A0* temp_v0_6;
    unk_func_882170A8* temp_v0_9;
    unk_func_88507D4C* sp68;
    unk_func_88507D4C* sp64;
    unk_func_8850143C* temp_s0;
    unk_func_8850143C* temp_s0_2;
    s32 j;

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, 0x78);

    arg0->unk_00.unk_1C = func_8821004C;
    arg0->unk_00.unk_20 = func_88210168;
    arg0->unk_00.unk_24 = func_882101B4;
    // clang-format off
    arg0->unk_00.unk_10.unk_00 = arg1;arg0->unk_00.unk_10.unk_02 = arg2;
    // clang-format on
    arg0->unk_60 = 0;

    func_8002C758(&arg0->unk_64, 2, 0x64, arg5);
    arg0->unk_48 = arg4;

    arg0->unk_4C = mem_pool_alloc(arg5, sizeof(unk_func_8821421C_038_04C));
    func_88210334(arg0->unk_4C, arg0);

    arg0->unk_44 = mem_pool_alloc(arg5, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_44, 0, 0, 0x228, 0x162);

    arg0->unk_44->unk_00.unk_28 |= 0x200;
    arg0->unk_44->unk_00.unk_28 |= 0x400;
    arg0->unk_44->unk_00.unk_28 &= ~1;

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_44);

    sp9C = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(sp9C, 0, 0, 0x228, 6, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, sp9C);

    spA0 = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spA0, 0, 0x124, 0x228, 6, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, spA0);

    spA4 = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spA4, 0, 6, 6, 0x11E, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, spA4);

    spA8 = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spA8, 0x222, 6, 6, 0x11E, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, spA8);

    spAC = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spAC, 0xF2, 6, 0x44, 0x11E, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, spAC);

    spB0 = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spB0, 6, 6, 0xEC, 0x13, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, spB0);

    spB4 = mem_pool_alloc(arg5, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spB4, 6, 0x111, 0xEC, 0x13, D_88218044);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, spB4);

    sp94 = mem_pool_alloc(arg5, sizeof(unk_func_88001300_000));
    ((func8850AB48)Memmap_GetFragmentVaddr(func_8850AB48))(sp94, 4, 0x17, 0xF0, 0xFC);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, sp94);

    sp98 = mem_pool_alloc(arg5, sizeof(unk_func_88001300_000));
    ((func8850AB48)Memmap_GetFragmentVaddr(func_8850AB48))(sp98, 0x134, 4, 0xF0, 0x122);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, sp98);

    temp_s0 = mem_pool_alloc(arg5, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(func_8850143C))(temp_s0, 0x136, 6, 0xEC, 0x1E, D_88218048, D_8821804C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, temp_s0);

    arg0->unk_2C = mem_pool_alloc(arg5, sizeof(unk_func_8821421C_038_02C));
    func_8820ECAC(arg0->unk_2C, temp_s0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s0, arg0->unk_2C);

    temp_s0_2 = mem_pool_alloc(arg5, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(func_8850143C))(temp_s0_2, 0, 0x12A, 0x228, 0x38, D_88218058, D_8821805C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, temp_s0_2);

    arg0->unk_38 = mem_pool_alloc(arg5, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_38, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s0_2, arg0->unk_38);

    temp_s0_3 = mem_pool_alloc(arg5, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s0_3, 0x60, 4, func_8002D7C0(NULL, 0, D_88224FC4, 0x13),
                                                           8);
    temp_s0_3->unk_3C = 0x1C;
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_38, temp_s0_3);

    arg0->unk_3C = mem_pool_alloc(arg5, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_3C, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_38, arg0->unk_3C);

    if (sp94) {}
    if (sp98) {}
    if (sp9C) {}
    if (spA0) {}
    if (spA4) {}
    if (spA8) {}
    if (spAC) {}
    if (spB0) {}
    if (spB4) {}

    for (j = 0; j < 2; j++) {
        temp_s0_4 = mem_pool_alloc(arg5, sizeof(unk_func_8850878C));
        sp7C = func_8002D7C0(NULL, 0, D_88224FC4, D_88218060[j].unk_00);

        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s0_4, (0x228 - func_8001F5B0(0x10, 0, sp7C)) / 2,
                                                               0x10, sp7C, 0x10);

        temp_s0_4->unk_30 = D_88218060[j].unk_04[0];
        temp_s0_4->unk_44 = temp_s0_4->unk_44;
        temp_s0_4->unk_34 = D_88218060[j].unk_04[1];
        temp_s0_4->unk_44 = 1;

        ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_3C, temp_s0_4);
    }

    arg0->unk_40 = mem_pool_alloc(arg5, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_40, 0x60, 4, "ERROR", 8);
    arg0->unk_40->unk_3C = 0x1C;
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_38, arg0->unk_40);

    arg0->unk_34 = mem_pool_alloc(arg5, sizeof(unk_func_8821421C_038_034));
    ((func88506DCC)Memmap_GetFragmentVaddr(func_88506DCC))(arg0->unk_34, 6, 0x19, func_8820EFD8, 0xEC, 0x3E, 4, arg5);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_34, 4, arg5);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, arg0->unk_34);

    temp_s0_5 = mem_pool_alloc(arg5, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(temp_s0_5, arg0->unk_34);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_4C, temp_s0_5);

    arg0->unk_4C->unk_28 = mem_pool_alloc(arg5, sizeof(unk_func_88001300_03C));
    ((func8850C284)Memmap_GetFragmentVaddr(func_8850C284))(arg0->unk_4C->unk_28, 3, 1, arg5);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_4C, arg0->unk_4C->unk_28);

    for (i = 0; i < 2; i++) {
        temp_v0_6 = mem_pool_alloc(arg5, sizeof(unk_func_882149A0));
        func_882149A0(temp_v0_6, D_88218070[i].unk_00, D_88218070[i].unk_02, D_88218070[i].unk_04, D_88218070[i].unk_06,
                      D_88218070[i].unk_08, D_88218070[i].unk_0C, D_88218070[i].unk_10[0], D_88218070[i].unk_10[1],
                      D_88218044);

        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, temp_v0_6);

        arg0->unk_4C->unk_28->unk_18[i * arg0->unk_4C->unk_28->unk_2C] = &temp_v0_6->unk_00;
    }

    ((func8850CAB4)Memmap_GetFragmentVaddr(func_8850CAB4))(arg0->unk_4C->unk_28);

    temp_s0_6 = mem_pool_alloc(arg5, sizeof(unk_func_88001300_03C_01C));
    ((func88503340)Memmap_GetFragmentVaddr(func_88503340))(temp_s0_6, 0, 0, 0x10, 0x10, D_88218098);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, temp_s0_6);
    arg0->unk_4C->unk_28->unk_1C = temp_s0_6;

    arg0->unk_30 = mem_pool_alloc(arg5, sizeof(unk_func_8820BE14_02C_038));
    func_882158CC(arg0->unk_30, 0x136, 0x34, 8, func_8820DF38, 0xEC, 0x1C, arg5);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_30, 0x64, arg5);

    sp64 = mem_pool_alloc(arg5, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp64, 0x136, 0x24, 0xEC, 0, arg0->unk_30);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, sp64);

    sp68 = mem_pool_alloc(arg5, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(
        sp68, 0x136, arg0->unk_30->unk_00.unk_00.unk_14.unk_02 + 0x34, 0xEC, 1, arg0->unk_30);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, sp68);
    func_882159AC(arg0->unk_30, sp68);

    temp_v0_9 = mem_pool_alloc(arg5, sizeof(unk_func_882170A8));
    func_882170A8(temp_v0_9, 0xA8, 2, arg0->unk_30, 3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp68, temp_v0_9);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, arg0->unk_30);

    temp_s0_7 = mem_pool_alloc(arg5, sizeof(unk_func_8850BD40));
    ((func8850BD40)Memmap_GetFragmentVaddr(func_8850BD40))(temp_s0_7, arg0->unk_30);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_4C, temp_s0_7);

    temp_s0_8 = mem_pool_alloc(arg5, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(temp_s0_8, arg0->unk_44, arg3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, temp_s0_8);

    // Fake, forcing sp64/sp68 onto the stack
    if (0) {
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, &sp64);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_44, &sp68);
    }
}

void func_8820FFF8(unk_func_8821421C_038* arg0, unk_func_8821421C_07C* arg1) {
    func_8002C740(&arg0->unk_50, arg1, 0x14, 4, 4);

    ((func88506F50)Memmap_GetFragmentVaddr(func_88506F50))(arg0->unk_34, &arg0->unk_50);
}

s32 func_8821004C(unk_func_8821421C_038* arg0) {
    UNUSED s32 pad;
    u8* temp_t0;
    char* sp2C;

    switch (arg0->unk_4C->unk_00.unk_1C) {
        case 0:
            ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_38, 0);
            break;

        case 1:
            ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_38, 1);
            ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_3C, arg0->unk_4C->unk_28->unk_24);
            break;

        case 2:
            sp2C = NULL;
            ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_38, 2);
            temp_t0 = &((u8*)arg0->unk_30->unk_00.unk_2C
                            ->unk_00)[arg0->unk_30->unk_00.unk_2C->unk_0C * arg0->unk_30->unk_00.unk_38];
            if (temp_t0 != NULL) {
                sp2C = func_8002D7C0(NULL, 0, D_88224FCC, temp_t0[0] - 1);
            }
            arg0->unk_40->unk_40 = sp2C;
            break;
    }
    return 0;
}

s32 func_88210168(unk_func_8821421C_038* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_44->unk_30 & 2) {
        var_v1 = arg0->unk_4C->unk_00.unk_10(&arg0->unk_4C->unk_00, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void func_882101B4(unk_func_8821421C_038* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    arg0->unk_4C->unk_00.unk_14(&arg0->unk_4C->unk_00, arg1);
}

void func_882101E0(unk_func_8821421C_038* arg0, s32 arg1) {
    func_8820C930(0x12, 0, arg1, &arg0->unk_64);
    func_88217060(arg0->unk_30, &arg0->unk_60, arg1 | 0x20000);
}

s32 func_88210234(unk_func_8821421C_038* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_v0;
    unk_func_8821421C_038_04C* temp_a0;
    s32 var_s0 = 0;

    arg0->unk_4C->unk_00.unk_14(arg0->unk_4C, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_44);

    while (var_s0 == 0) {
        func_8002EEA8(var_s0);
        temp_v0 = func_88210168(arg0, arg1);

        if (!(temp_v0 & 1)) {
            if (temp_v0 & 2) {
                var_s0 = 1;
            } else if (temp_v0 & 4) {
                if (arg0->unk_48->unk_30->unk_24 == 0) {
                    var_v0 = 1;
                } else {
                    var_v0 = 0;
                }
                var_s0 = var_v0 + 1;
            }
        }
        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(temp_v0);
    }

    arg0->unk_44->unk_2C = 0xB;
    return var_s0 - 1;
}

void func_88210334(unk_func_8821421C_038_04C* arg0, unk_func_8821421C_038* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(func_8850BDF0))(arg0);

    arg0->unk_00.unk_10 = func_88210380;
    arg0->unk_00.unk_24 = arg1;
}

#ifdef NON_MATCHING
s32 func_88210380(unk_func_8821421C_038_04C* arg0, Controller* arg1) {
    s32 var_v1;
    s32 i;
    unk_func_88203ED8_064* var_a0;

    var_v1 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_08;
        }
        var_v1 = var_a0->unk_10(var_a0, arg1);
    }

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

    if (var_v1 & 2) {
        switch (arg0->unk_00.unk_1C) {
            case 1:
                ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 0);
                var_v1 |= 1;
                break;

            case 2:
                ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                var_v1 |= 1;
                break;
        }
    } else if (var_v1 & 4) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                func_8820EFD0(arg0->unk_00.unk_24->unk_2C,
                              &arg0->unk_00.unk_24->unk_50[arg0->unk_00.unk_24->unk_34->unk_00.unk_38]);
                func_882101E0(arg0->unk_00.unk_24, arg0->unk_00.unk_24->unk_34->unk_00.unk_38);

                ((func8850CB48)Memmap_GetFragmentVaddr(func_8850CB48))(arg0->unk_28, 0);
                ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);

                var_v1 |= 1;
                break;

            case 1:
                switch (arg0->unk_28->unk_24) {
                    case 0:
                        ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 2);
                        var_v1 |= 1;
                        break;

                    case 1:
                        func_8820D614(arg0->unk_00.unk_24->unk_48, func_8002D7C0(NULL, 0, D_88224FC4, 0x16));
                        ((func8850CB48)Memmap_GetFragmentVaddr(func_8850CB48))(arg0->unk_00.unk_24->unk_48->unk_30, 1);
                        func_80048B90(2);

                        arg0->unk_28->unk_14(arg0->unk_28, 0x100);

                        if (func_8820D620(arg0->unk_00.unk_24->unk_48, arg1) == 1) {
                            var_v1 = 4;
                        } else {
                            var_v1 = 1;
                        }

                        arg0->unk_28->unk_14(arg0->unk_28, 1);
                        break;
                }
                break;

            case 2:
                var_v1 = 1;
                break;
        }
    }

    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1B4EA0/func_88210380.s")
#endif

void func_8821064C(unk_func_8821421C_02C_06C_02C* arg0, unk_func_8820BE14_02C_038* arg1,
                   unk_func_8820BE14_02C_038* arg2, unk_func_8820E99C* arg3, unk_func_88217740* arg4,
                   unk_func_88509F48* arg5, MemoryPool* arg6) {
    static u16 D_8821809C[] = { 8, 9, 0xA, 0xB, 0xC };
    static Color_RGBA8 D_882180A8 = { 0xF0, 0xF0, 0xF0, 0xFF };

    s32 i;

    ((func88500668)Memmap_GetFragmentVaddr(func_88500668))(arg0, sizeof(unk_func_8821421C_02C_06C_02C));

    arg0->unk_10 = func_882118CC;
    arg0->unk_14 = func_882107D0;
    arg0->unk_18 = 0;
    arg0->unk_1C = 0;
    arg0->unk_20[0] = arg1;
    arg0->unk_20[1] = arg2;
    arg0->unk_28 = arg3;
    arg0->unk_2C[0] = arg1;
    arg0->unk_2C[1] = arg2;
    arg0->unk_34 = arg3;
    arg0->unk_44 = 1;
    arg0->unk_48 = arg4;
    arg0->unk_4C = arg5;

    func_88210D2C(arg0, 0);

    for (i = 0; i < 5; i++) {
        arg0->unk_78[i].unk_00 = mem_pool_alloc(arg6, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_78[i].unk_00, 0, 0,
                                                               func_8002D7C0(NULL, 0, D_88224FC4, D_8821809C[i]), 0x10);

        arg0->unk_78[i].unk_00->unk_30 = D_882180A8;
        arg0->unk_78[i].unk_00->unk_44 = arg0->unk_78[i].unk_00->unk_44;
        arg0->unk_78[i].unk_08 = 0;
        arg0->unk_78[i].unk_04 = 0;
    }
}

void func_882107D0(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1) {
    arg0->unk_18 = arg1;
    func_882107F0(arg0);
}

void func_882107F0(unk_func_8821421C_02C_06C_02C* arg0) {
    s32 i;
    s32 temp_s3 = arg0->unk_18 & 0xFF;
    s32 temp_s4 = arg0->unk_18 & 0xFF00;
    s32 var_v0;

    for (i = 0; i < 3; i++) {
        var_v0 = 0;
        if (i == arg0->unk_1C) {
            var_v0 = 1;
        }
        arg0->unk_20[i]->unk_00.unk_00.unk_24(&arg0->unk_20[i]->unk_00.unk_00, (var_v0 & temp_s3) | temp_s4);
    }
}

void func_88210888(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1) {
    arg0->unk_1C = arg1;
    func_882107F0(arg0);
}

void func_882108A8(unk_func_8821421C_02C_06C_02C* arg0) {
    unk_func_8820BE14_02C_038* temp_t6;
    unk_func_8820BE14_02C_038* temp_t7;

    temp_t6 = arg0->unk_20[0];
    arg0->unk_20[0] = arg0->unk_20[1];
    arg0->unk_20[1] = temp_t6;

    temp_t7 = arg0->unk_2C[0];
    arg0->unk_2C[0] = arg0->unk_2C[1];
    arg0->unk_2C[1] = temp_t7;

    arg0->unk_44 = !arg0->unk_44;
}

void func_882108D8(unk_func_8821421C_02C_06C_02C* arg0, unk_func_8821421C_02C_06C_02C_060_02C_000** arg1,
                   unk_func_8821421C_02C_06C_02C_060_02C_000** arg2) {
    switch (arg0->unk_38) {
        case 0:
            *arg1 =
                &((u8*)arg0->unk_2C[0]
                      ->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C * arg0->unk_2C[0]->unk_00.unk_38];
            *arg2 = NULL;
            break;

        case 1:
            *arg1 =
                &((u8*)arg0->unk_2C[0]->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C * arg0->unk_40];
            *arg2 =
                &((u8*)arg0->unk_2C[0]
                      ->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C * arg0->unk_2C[0]->unk_00.unk_38];
            break;

        case 2:
            *arg1 =
                &((u8*)arg0->unk_2C[0]
                      ->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C * arg0->unk_2C[0]->unk_00.unk_38];
            *arg2 =
                &((u8*)arg0->unk_2C[1]
                      ->unk_00.unk_2C->unk_00)[arg0->unk_2C[1]->unk_00.unk_2C->unk_0C * arg0->unk_2C[1]->unk_00.unk_38];
            break;
    }
}

void func_882109C8(unk_func_8821421C_02C_06C_02C* arg0, unk_func_88001300_000_010* arg1,
                   unk_func_88001300_000_010* arg2) {
    s16 var_v1;

    switch (arg0->unk_38) {
        case 0:
            arg1->unk_00 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 =
                arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_2C[0]->unk_5C - arg0->unk_2C[0]->unk_58);

            arg2->unk_00 = arg0->unk_2C[1]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_2C[1]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_2C[1]->unk_5C - arg0->unk_2C[1]->unk_58);
            break;

        case 1:
            var_v1 = (arg0->unk_2C[0]->unk_00.unk_3E * arg0->unk_40) - arg0->unk_2C[0]->unk_58;
            if (var_v1 < -arg0->unk_2C[0]->unk_00.unk_3E) {
                var_v1 = -arg0->unk_2C[0]->unk_00.unk_3E;
            } else if (arg0->unk_2C[0]->unk_00.unk_00.unk_14.unk_02 < var_v1) {
                var_v1 = arg0->unk_2C[0]->unk_00.unk_00.unk_14.unk_02;
            }

            arg1->unk_00 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_02 + var_v1;

            arg2->unk_00 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_2C[0]->unk_5C - arg0->unk_2C[0]->unk_58);
            break;

        case 2:
            arg1->unk_00 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_00;
            arg1->unk_02 =
                arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_2C[0]->unk_5C - arg0->unk_2C[0]->unk_58);

            arg2->unk_00 = arg0->unk_2C[1]->unk_00.unk_00.unk_10.unk_00;
            arg2->unk_02 =
                arg0->unk_2C[1]->unk_00.unk_00.unk_10.unk_02 + (arg0->unk_2C[1]->unk_5C - arg0->unk_2C[1]->unk_58);
            break;
    }
}

void func_88210B38(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1) {
    s32 temp_v1_2;
    s32 var_v1;
    unk_func_8820BE14_06C* temp_v1 = arg0->unk_2C[0]->unk_00.unk_2C;

    func_8820E978(arg0->unk_34, ((u8*)temp_v1->unk_00 + (arg0->unk_2C[0]->unk_00.unk_38 * temp_v1->unk_0C))[1], arg1);

    var_v1 = arg0->unk_2C[0]->unk_5C - arg0->unk_2C[0]->unk_58;

    if (((!(&arg0->unk_2C[0]->unk_00.unk_00)) && (!(&arg0->unk_2C[0]->unk_00.unk_00))) &&
        (!(&arg0->unk_2C[0]->unk_00.unk_00))) {}

    if (var_v1 == 0xC4) {
        var_v1 -= arg0->unk_34->unk_2C->unk_00.unk_14.unk_02;
        var_v1 -= 4;
    } else {
        var_v1 += 0x20;
    }

    arg0->unk_34->unk_00.unk_10.unk_00 =
        0xD3 + (arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_00 - arg0->unk_34->unk_2C->unk_00.unk_14.unk_00);
    arg0->unk_34->unk_00.unk_10.unk_02 = arg0->unk_2C[0]->unk_00.unk_00.unk_10.unk_02 + var_v1 & 0xFFFF;

    func_8820EC68(arg0->unk_34);
}

void func_88210BFC(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1) {
    switch (arg1) {
        case 0:
            ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_2C[0]);

            func_88215974(&arg0->unk_2C[0]->unk_00, 1);
            func_88215974(&arg0->unk_2C[1]->unk_00, 1);
            func_88210888(arg0, 0);
            func_88217BB8(arg0->unk_48);
            break;

        case 4:
            func_88210888(arg0, 2);
            func_88217BAC(arg0->unk_48);
            break;

        case 1:
            func_88216F18(arg0->unk_2C[1], 0);
            func_88215974(&arg0->unk_2C[1]->unk_00, 0);
            func_88210888(arg0, 1);
            func_88217BAC(arg0->unk_48);
            break;

        case 2:
            func_88215974(&arg0->unk_2C[0]->unk_00, 0);
            func_88210888(arg0, 0);
            func_88217BAC(arg0->unk_48);
            break;

        case 3:
            func_88215974(&arg0->unk_2C[1]->unk_00, 0);
            func_88210888(arg0, 1);
            func_88217BAC(arg0->unk_48);
            break;
    }
    arg0->unk_3C = arg1;
}

void func_88210D2C(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1) {
    arg0->unk_38 = arg1;
    func_88210BFC(arg0, 0);
}

void func_88210D50(unk_func_8821421C_02C_06C_02C* arg0) {
    func_88210BFC(arg0, 0);
    ((func8850628C)Memmap_GetFragmentVaddr(func_8850628C))(arg0->unk_2C[1]);
}

s32 func_88210D8C(unk_func_8821421C_02C_06C_02C* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_3C == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_88210DA8(void) {
}

s32 func_88210DB0(s32 arg0, unk_func_8820BE14_06C* arg1) {
    s32 i;
    s32 var_v1 = 0;
    u8* var_v0 = arg1->unk_00;

    for (i = 0; i < arg1->unk_08; i++, var_v0 += 2) {
        if (arg0 == var_v0[0]) {
            var_v1 = (var_v1 - var_v0[1]) + 0x63;
        }
    }

    return var_v1;
}

s32 func_88210DF4(s32 arg0, unk_func_8820BE14_06C* arg1) {
    s32 var_v1;

    if (func_8002F264(arg0) != 0) {
        if (arg1->unk_08 < arg1->unk_04) {
            var_v1 = 1;
        } else {
            var_v1 = 0;
        }
    } else if (arg1->unk_08 < arg1->unk_04) {
        var_v1 = 0x63;
    } else {
        var_v1 = func_88210DB0(arg0, arg1);
    }
    return var_v1;
}

void func_88210E70(unk_func_8820BE14_02C_038* arg0, u8* arg1) {
    func_8002C88C(arg0->unk_00.unk_2C, arg1, arg0->unk_00.unk_38);
}

void func_88210E98(unk_func_8820BE14_02C_038* arg0, s32 arg1) {
    s32 sp1C = arg0->unk_00.unk_38;

    func_8002C990(arg0->unk_00.unk_2C, arg1);

    if (arg1 < sp1C) {
        sp1C--;
    }

    ((func88507AE4)Memmap_GetFragmentVaddr(func_88507AE4))(arg0, sp1C);
}

void func_88210F00(unk_func_8820BE14_02C_038* arg0) {
    s32 sp1C;
    s32 temp_a1;
    s32 var_a1;

    sp1C = arg0->unk_00.unk_38;
    func_8002C990(arg0->unk_00.unk_2C, sp1C);
    if ((sp1C > 0) && (sp1C >= arg0->unk_00.unk_2C->unk_08)) {
        sp1C -= 1;
    }
    ((func88507AE4)Memmap_GetFragmentVaddr(func_88507AE4))(arg0, sp1C);
}

#ifdef NON_MATCHING
void func_88210F74(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad;
    s32 i;
    s32 var_s3;
    s32 var_v0;
    unk_func_8821421C_02C_06C_02C_060_02C_000 sp44;
    unk_func_8820BE14_06C* temp_s4;
    u8* var_s2;

    temp_s4 = arg0->unk_00.unk_2C;
    var_s3 = arg0->unk_00.unk_38;
    var_s2 = temp_s4->unk_00;
    i = 0;

    while (i < temp_s4->unk_08) {
        if (arg1 == var_s2[0]) {
            arg2 += var_s2[1];
            func_8002C990(temp_s4, i);
            if (i < var_s3) {
                var_s3--;
            }
        } else {
            i++;
            var_s2 += 2;
        }
    }

    sp44.unk_00 = arg1;

    while (arg2 > 0) {
        if (arg2 < 0x63) {
            var_v0 = arg2;
        } else {
            var_v0 = 0x63;
        }
        arg2 -= var_v0;
        sp44.unk_01 = var_v0;
        func_8002C88C(temp_s4, &sp44, var_s3++);
    }

    ((func88507AE4)Memmap_GetFragmentVaddr(func_88507AE4))(arg0, var_s3 - 1);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1B4EA0/func_88210F74.s")
#endif

void func_88211088(unk_func_8820BE14_02C_038* arg0, s32 arg1) {
    u8* temp_v1 = &((u8*)arg0->unk_00.unk_2C->unk_00)[arg0->unk_00.unk_2C->unk_0C * arg0->unk_00.unk_38];

    if (arg1 >= temp_v1[1]) {
        func_88210F00(arg0);
        return;
    }
    temp_v1[1] -= arg1;
}

void func_882110E0(unk_func_8820BE14_02C_038* arg0, unk_func_8820BE14_02C_038* arg1, unk_func_8820E99C* arg2) {
    u8* sp24 = &((u8*)arg0->unk_00.unk_2C->unk_00)[arg0->unk_00.unk_2C->unk_0C * arg0->unk_00.unk_38];

    if (func_8002F264(sp24[0]) != 0) {
        func_88210E70(arg1, &((u8*)arg0->unk_00.unk_2C->unk_00)[arg0->unk_00.unk_2C->unk_0C * arg0->unk_00.unk_38]);
        func_88210F00(arg0);
    } else {
        func_88210F74(arg1, sp24[0], arg2->unk_30->unk_30.unk_00);
        func_88211088(arg0, arg2->unk_30->unk_30.unk_00);
    }

    *arg1->unk_88 = 1;
    *arg0->unk_88 = *arg1->unk_88;
}

s32 func_882111C0(unk_func_8821421C_02C_06C_02C_060_02C_000* arg0, unk_func_8821421C_02C_06C_02C_060_02C_000* arg1) {
    s32 temp_v1 = arg0->unk_01 + arg1->unk_01;
    s32 var_a2;

    if (temp_v1 >= 0x64) {
        var_a2 = temp_v1 - 0x63;
    } else {
        var_a2 = 0;
    }

    arg0->unk_01 = temp_v1 - var_a2;
    arg1->unk_01 = var_a2;
    return var_a2;
}

#ifdef NON_MATCHING
void func_882111F8(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2) {
    unk_func_8821421C_02C_06C_02C_060_02C_000* ptr = arg0->unk_00.unk_2C->unk_00;
    unk_func_8821421C_02C_06C_02C_060_02C_000 sp30;
    unk_func_8821421C_02C_06C_02C_060_02C_000 sp2C;
    s32 var_v1;
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp20;
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp1C;

    sp20 = ptr;
    sp1C = ptr;

    sp20 += arg1;
    sp1C += arg2;

    sp30 = *sp20;
    sp2C = *sp1C;

    if ((func_8002F264(sp30.unk_00) == 0) && (sp30.unk_00 == sp2C.unk_00)) {
        var_v1 = func_882111C0(&sp30, &sp2C);
    } else {
        var_v1 = 1;
    }

    *sp20 = sp2C;
    *sp1C = sp30;

    if (var_v1 == 0) {
        func_88210E98(arg0, arg1);
    }

    *arg0->unk_88 = 1;
}
#else
void func_882111F8(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/23/fragment23_1B4EA0/func_882111F8.s")
#endif

void func_882112E4(unk_func_8820BE14_02C_038* arg0, unk_func_8820BE14_02C_038* arg1) {
    unk_func_8821421C_02C_06C_02C_060_02C_000* temp_v0 = arg0->unk_00.unk_2C->unk_00;
    unk_func_8821421C_02C_06C_02C_060_02C_000* temp_v1 = arg1->unk_00.unk_2C->unk_00;
    unk_func_8821421C_02C_06C_02C_060_02C_000 sp4;

    sp4 = temp_v1[arg1->unk_00.unk_38];
    temp_v1[arg1->unk_00.unk_38] = temp_v0[arg0->unk_00.unk_38];
    temp_v0[arg0->unk_00.unk_38] = sp4;

    *arg1->unk_88 = 1;
    *arg0->unk_88 = *arg1->unk_88;
}

void func_88211380(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1) {
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp3C;
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp38;
    unk_func_8821421C_02C_06C_02C_060_02C sp34;
    unk_func_88001300_000_010 sp30;
    unk_func_88001300_000_010 sp2C;

    func_882108D8(arg0, &sp38, &sp3C);

    sp34.unk_00 = *sp38;

    if (func_8002F264(sp38->unk_00) == 0) {
        sp34.unk_00.unk_01 = arg0->unk_34->unk_30->unk_30.unk_00;
    }

    func_8820E638(arg0->unk_60[0], sp34.unk_00);
    func_882109C8(arg0, &sp30, &sp2C);
    func_882175F4(arg0->unk_58[0], sp30, sp2C);

    if (sp38->unk_01 != sp34.unk_00.unk_01) {
        sp34.unk_02.unk_00 = sp34.unk_00.unk_00;
        sp34.unk_02.unk_01 = sp38->unk_01 - sp34.unk_00.unk_01;
        func_8820E638(arg0->unk_70[0], sp34.unk_02);
        func_88217718(arg0->unk_68[0], sp30);
    }

    arg0->unk_14(arg0, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(func_8850CF00))(arg0->unk_50, arg1);

    arg0->unk_14(arg0, 1);

    func_882110E0(arg0->unk_2C[0], arg0->unk_2C[1], arg0->unk_34);
    func_88210D50(arg0);
}

void func_88211508(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1) {
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp34;
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp30;
    unk_func_8821421C_02C_06C_02C_060_02C sp2C;
    unk_func_88001300_000_010 sp28;
    unk_func_88001300_000_010 sp24;

    func_882108D8(arg0, &sp30, &sp34);

    sp2C.unk_00 = *sp30;
    sp2C.unk_02 = *sp34;

    func_882109C8(arg0, &sp28, &sp24);

    if ((func_8002F264(sp2C.unk_00.unk_00) == 0) && (sp2C.unk_02.unk_00 == sp2C.unk_00.unk_00)) {
        if (func_882111C0(&sp2C.unk_00, &sp2C.unk_02) > 0) {
            func_8820E638(arg0->unk_70[1], sp2C.unk_02);
            func_88217718(arg0->unk_68[1], sp28);
        }

        sp2C.unk_00 = *sp30;
        sp2C.unk_00.unk_01 -= sp2C.unk_02.unk_01;

        func_8820E638(arg0->unk_60[0], sp2C.unk_00);
        func_8820E638(arg0->unk_70[0], *sp34);
        func_882175F4(arg0->unk_58[0], sp28, sp24);
        func_88217718(arg0->unk_68[0], sp24);
    } else {
        func_8820E638(arg0->unk_60[0], sp2C.unk_00);
        func_8820E638(arg0->unk_60[1], sp2C.unk_02);
        func_882175F4(arg0->unk_58[0], sp28, sp24);
        func_882175F4(arg0->unk_58[1], sp24, sp28);
    }

    arg0->unk_14(arg0, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(func_8850CF00))(arg0->unk_50, arg1);

    arg0->unk_14(arg0, 1);

    func_882111F8(arg0->unk_2C[0], arg0->unk_40, arg0->unk_2C[0]->unk_00.unk_38);
    func_88210D50(arg0);
}

void func_88211794(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1) {
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp34;
    unk_func_8821421C_02C_06C_02C_060_02C_000* sp30;
    unk_func_88001300_000_010 sp2C;
    unk_func_88001300_000_010 sp28;

    func_882108D8(arg0, &sp30, &sp34);

    func_8820E638(arg0->unk_60[0], *sp30);
    func_8820E638(arg0->unk_60[1], *sp34);

    func_882109C8(arg0, &sp2C, &sp28);
    func_882175F4(arg0->unk_58[0], sp2C, sp28);
    func_882175F4(arg0->unk_58[1], sp28, sp2C);

    arg0->unk_14(arg0, 0);

    ((func8850CF00)Memmap_GetFragmentVaddr(func_8850CF00))(arg0->unk_50, arg1);

    arg0->unk_14(arg0, 1);

    func_882112E4(arg0->unk_2C[0], arg0->unk_2C[1]);
    func_88210D50(arg0);
}

s32 func_882118CC(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1) {
    s32 sp2C;
    s32 sp28;
    u8* new_var;
    u8* sp24;
    u8* new_var2;

    sp2C = arg0->unk_20[arg0->unk_1C]->unk_00.unk_00.unk_20(arg0->unk_20[arg0->unk_1C], arg1);
    if (sp2C & 1) {
        return sp2C;
    }

    if (sp2C == 0) {
        if (arg1->buttonPressed & 0x4000) {
            sp2C = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            sp2C = 0x80000004;
        }
    }

    switch (arg0->unk_3C) {
        case 0:
            switch (arg0->unk_38) {
                case 0:
                    if (!(sp2C & 2) && (sp2C & 4)) {
                        new_var =
                            &((u8*)arg0->unk_2C[0]->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C *
                                                                           arg0->unk_2C[0]->unk_00.unk_38];
                        sp24 = new_var;

                        if (arg0->unk_2C[0]->unk_00.unk_2C->unk_08 == 0) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                arg0->unk_4C, arg0->unk_78[0].unk_00, arg0->unk_78[0].unk_04, arg0->unk_78[0].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_4C, arg1);
                            sp2C = 1;
                        } else if ((func_8002F1C0(sp24[0]) != 0) && ((arg0->unk_2C[1]->unk_8C >> 0x10) == 2)) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                arg0->unk_4C, arg0->unk_78[4].unk_00, arg0->unk_78[4].unk_04, arg0->unk_78[4].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_4C, arg1);
                            sp2C = 1;
                        } else {
                            sp28 = func_88210DF4(sp24[0], arg0->unk_2C[1]->unk_00.unk_2C);
                            if (sp28 == 0) {
                                func_80048B90(8);
                                ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                    arg0->unk_4C, arg0->unk_78[3].unk_00, arg0->unk_78[3].unk_04,
                                    arg0->unk_78[3].unk_08);
                                ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_4C, arg1);
                                sp2C = 1;
                            } else {
                                arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 2;
                                if (func_8002F264(sp24[0]) == 0) {
                                    func_88210B38(arg0, sp28);
                                    func_88210BFC(arg0, 4);
                                    sp2C |= 1;
                                } else {
                                    func_88210BFC(arg0, 1);
                                    sp2C |= 1;
                                }
                            }
                        }
                    }
                    break;

                case 1:
                    if (!(sp2C & 2) && (sp2C & 4)) {
                        if (arg0->unk_2C[0]->unk_00.unk_2C->unk_08 == 0) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                arg0->unk_4C, arg0->unk_78[1].unk_00, arg0->unk_78[1].unk_04, arg0->unk_78[1].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_4C, arg1);
                            sp2C = 1;
                        } else {
                            arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 2;
                            arg0->unk_40 = arg0->unk_2C[0]->unk_00.unk_38;
                            func_88210BFC(arg0, 2);
                            sp2C |= 1;
                        }
                    }
                    break;

                case 2:
                    if (!(sp2C & 2) && (sp2C & 4)) {
                        sp24 = &((u8*)arg0->unk_2C[0]->unk_00.unk_2C->unk_00)[arg0->unk_2C[0]->unk_00.unk_2C->unk_0C *
                                                                              arg0->unk_2C[0]->unk_00.unk_38];
                        if ((arg0->unk_2C[0]->unk_00.unk_2C->unk_08 == 0) ||
                            (arg0->unk_2C[1]->unk_00.unk_2C->unk_08 == 0)) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                arg0->unk_4C, arg0->unk_78[2].unk_00, arg0->unk_78[2].unk_04, arg0->unk_78[2].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_4C, arg1);
                            sp2C = 1;
                        } else if ((func_8002F1C0(sp24[0]) != 0) && ((arg0->unk_2C[1]->unk_8C >> 0x10) == 2)) {
                            func_80048B90(8);
                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                arg0->unk_4C, arg0->unk_78[4].unk_00, arg0->unk_78[4].unk_04, arg0->unk_78[4].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_4C, arg1);
                            sp2C = 1;
                        } else {
                            arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 2;
                            func_88210BFC(arg0, 3);
                            sp2C |= 1;
                        }
                    }
                    break;
            }
            break;

        case 4:
            if (sp2C & 2) {
                func_8820EC9C(arg0->unk_34);
                func_88210BFC(arg0, 0);
                sp2C |= 1;
            } else if (sp2C & 4) {
                if (arg0->unk_34->unk_34 < arg0->unk_34->unk_30->unk_30.unk_00) {
                    func_80048B90(8);
                    ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                        arg0->unk_4C, arg0->unk_78[3].unk_00, arg0->unk_78[3].unk_04, arg0->unk_78[3].unk_08);
                    ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_4C, arg1);
                    arg0->unk_34->unk_30->unk_30.unk_00 = arg0->unk_34->unk_34;
                    sp2C = 1;
                } else {
                    func_88210BFC(arg0, 1);
                    sp2C |= 1;
                }
            }
            break;

        case 1:
            if (sp2C & 2) {
                if (arg0->unk_34->unk_2C->unk_00.unk_28 & 1) {
                    func_88210BFC(arg0, 4);
                } else {
                    func_88210BFC(arg0, 0);
                }
                func_88216F18(arg0->unk_2C[1], 1);
                sp2C |= 1;
            } else if (sp2C & 4) {
                func_80048B90(0x18);
                arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 0x100;
                if (arg0->unk_34->unk_2C->unk_00.unk_28 & 1) {
                    func_8820EC9C(arg0->unk_34);
                }
                func_88211380(arg0, arg1);
                func_88216F18(arg0->unk_2C[1], 2);
                sp2C = 0x80000081;
            }
            break;

        case 2:
            if (sp2C & 2) {
                func_88210BFC(arg0, 0);
                sp2C |= 1;
            } else if (sp2C & 4) {
                if (arg0->unk_40 == arg0->unk_2C[arg0->unk_1C]->unk_00.unk_38) {
                    sp2C = 0x80000101;
                } else {
                    func_80048B90(0x18);

                    arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 2;
                    arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_40] |= 0x100;
                    arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 0x100;

                    func_88211508(arg0, arg1);
                    sp2C = 0x80000081;
                }
            }
            break;

        case 3:
            if (sp2C & 2) {
                func_88210BFC(arg0, 0);
                sp2C |= 1;
            } else if (sp2C & 4) {
                new_var2 = &((u8*)arg0->unk_2C[1]->unk_00.unk_2C->unk_00)[arg0->unk_2C[1]->unk_00.unk_2C->unk_0C *
                                                                          arg0->unk_2C[1]->unk_00.unk_38];
                if ((func_8002F1C0(new_var2[0]) != 0) && ((arg0->unk_2C[0]->unk_8C >> 0x10) == 2)) {
                    func_80048B90(8);
                    ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                        arg0->unk_4C, arg0->unk_78[4].unk_00, arg0->unk_78[4].unk_04, arg0->unk_78[4].unk_08);
                    ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_4C, arg1);
                    sp2C = 1;
                } else {
                    func_80048B90(0x18);

                    arg0->unk_2C[1]->unk_00.unk_34[arg0->unk_2C[1]->unk_00.unk_38] |= 2;
                    arg0->unk_2C[0]->unk_00.unk_34[arg0->unk_2C[0]->unk_00.unk_38] |= 0x100;
                    arg0->unk_2C[1]->unk_00.unk_34[arg0->unk_2C[1]->unk_00.unk_38] |= 0x100;

                    func_88211794(arg0, arg1);
                    sp2C = 0x80000081;
                }
            }
            break;
    }
    return sp2C;
}

u8* func_88212150(unk_func_8821421C_02C_06C_02C* arg0) {
    unk_func_8820BE14_06C* temp_a1;
    s32 sp0;
    s32 temp_v1;

    switch (arg0->unk_3C) {
        case 0:
        case 2:
        case 4:
            sp0 = 0;
            break;

        case 1:
            return NULL;

        case 3:
            sp0 = 1;
            break;
    }

    temp_v1 = arg0->unk_2C[sp0]->unk_00.unk_38;
    temp_a1 = arg0->unk_2C[sp0]->unk_00.unk_2C;
    if (temp_v1 >= temp_a1->unk_08) {
        return NULL;
    }
    return &((u8*)temp_a1->unk_00)[temp_a1->unk_0C * temp_v1];
}

void func_882121E0(unk_func_8821421C_02C* arg0, s32 arg1, s32 arg2, unk_func_8821421C_03C* arg3, s32* arg4,
                   unk_func_8821421C_07C* arg5, unk_func_88001300_000* arg6, unk_func_8821421C_038* arg7,
                   unk_func_8821421C_034* arg8, unk_func_88509F48* arg9, s8** argA, MemoryPool* argB) {
    static Color_RGBA8 D_882180AC = { 0x6C, 0x6C, 0x7E, 0xFF };
    static Color_RGBA8 D_882180B0 = { 0x50, 0x50, 0x86, 0xFF };
    static Color_RGBA8 D_882180B4 = { 0x79, 0x79, 0xCB, 0xFF };
    static Color_RGBA8 D_882180B8 = { 0x40, 0x40, 0x6C, 0xFF };
    static Color_RGBA8 D_882180BC = { 0x6A, 0x6A, 0xB2, 0xFF };
    static Color_RGBA8 D_882180C0 = { 0x2D, 0x1A, 0x41, 0xFF };
    static Color_RGBA8 D_882180C4 = { 0x6F, 0x5F, 0x7F, 0xFF };
    static unk_D_88218060 D_882180C8[] = {
        {
            0x00000001,
            D_88218228,
        },
        {
            0x00000002,
            D_88218228,
        },
        {
            0x00000003,
            D_882181F0,
        },
        {
            0x00000004,
            D_88218208,
        },
        {
            0x00000005,
            D_88218200,
        },
        {
            0x00000006,
            D_882181F8,
        },
    };
    static unk_D_88218060 D_882180F8[] = {
        {
            0x00000007,
            D_882181F8,
        },
        {
            0x00000007,
            D_882181F8,
        },
    };
    static unk_D_88217C6C D_88218108[] = {
        {
            249,
            28,
            54,
            42,
            D_8821E100,
            48,
            D_882181E8,
            1,
        },
        {
            249,
            73,
            54,
            42,
            D_8821E100,
            48,
            D_882181E8,
            0,
        },
        {
            249,
            118,
            54,
            42,
            D_88218FD0,
            48,
            D_882181B8,
            0,
        },
        {
            249,
            163,
            54,
            42,
            D_88219D58,
            48,
            D_882181C0,
            1,
        },
        {
            249,
            208,
            54,
            42,
            D_8821AAE0,
            48,
            D_882181C8,
            0,
        },
        {
            249,
            253,
            54,
            42,
            D_88218248,
            48,
            D_882181B0,
            0,
        },
    };
    static Color_RGBA8 D_88218198 = { 0xFF, 0xFF, 0x00, 0xFF };
    static u16 D_8821819C[] = { 0xD };
    static Color_RGBA8 D_882181A0 = { 0xF0, 0xF0, 0xF0, 0xFF };

    UNUSED s32 pad[6];
    s32 i;
    spE8_func_882121E0* spE8;
    char spDC[11];
    unk_func_885012A4* spD8;
    unk_func_885012A4* spD4;
    unk_func_885012A4* spD0;
    unk_func_885012A4* spCC;
    unk_func_885012A4* spC8;
    unk_func_88001300_000* spC4;
    unk_func_88001300_000* spC0;
    unk_func_8850143C* spBC;
    unk_func_8850143C* spB8;
    unk_func_882170A8* temp_v0_11;
    unk_func_882170A8* temp_v0_9;
    unk_func_8850143C* temp_s0_2;
    char* spA8;
    unk_func_8850878C* temp_s0_3;
    unk_func_8850878C* temp_s0_4;
    char* sp9C;
    unk_func_88001300_03C_01C* temp_s0_5;
    unk_func_88503298* temp_s0_6;
    unk_func_88507D4C* sp90;
    unk_func_88507D4C* sp8C;
    unk_func_8820E99C* temp_v0_12;
    unk_func_88507D4C* sp84;
    unk_func_88507D4C* sp80;
    s32 j;
    s32 x;
    s32 temp_s0;
    char* temp_s1;
    char* sp6C;

    temp_s0 = func_80029080();

    spE8 = mem_pool_alloc(argB, sizeof(spE8_func_882121E0));
    temp_s1 = mem_pool_alloc(argB, sizeof(char) * 40);

    func_8002D5D4(0x15, func_800251B0(temp_s0, spDC));

    spE8->unk_00[1] = func_8002D7C0(temp_s1, sizeof(char) * 40, D_88224FC4, 0xF);
    spE8->unk_00[0] = func_8002D7C0(NULL, 0, D_88224FC4, 0xE);
    spE8->unk_00[2] = func_8002D7C0(NULL, 0, D_88224FC4, 0x10);

    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, 0xA4);

    arg0->unk_00.unk_1C = func_8821347C;
    arg0->unk_00.unk_20 = func_882135D4;
    arg0->unk_00.unk_24 = func_882136F8;
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;
    arg0->unk_78 = arg3;
    arg0->unk_7C = arg4;
    arg0->unk_90 = arg5;
    arg0->unk_84 = arg7;
    arg0->unk_88 = arg8;
    arg0->unk_8C = arg9;
    arg0->unk_80 = 0;

    arg0->unk_6C = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_06C));
    func_88213774(arg0->unk_6C, arg0);

    arg0->unk_2C = mem_pool_alloc(argB, sizeof(unk_func_88001300_038));
    ((func88502274)Memmap_GetFragmentVaddr(func_88502274))(arg0->unk_2C, 0, 0, 0x228, 0x162);
    arg0->unk_2C->unk_00.unk_28 |= 0x400;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_2C);

    spC8 = mem_pool_alloc(argB, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spC8, 0, 0, 0x228, 6, D_882180AC);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spC8);

    spCC = mem_pool_alloc(argB, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spCC, 0, 0x124, 0x228, 6, D_882180AC);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spCC);

    spD0 = mem_pool_alloc(argB, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spD0, 0, 6, 6, 0x11E, D_882180AC);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spD0);

    spD4 = mem_pool_alloc(argB, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spD4, 0x222, 6, 6, 0x11E, D_882180AC);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spD4);

    spD8 = mem_pool_alloc(argB, sizeof(unk_func_885012A4));
    ((func885012A4)Memmap_GetFragmentVaddr(func_885012A4))(spD8, 0xF2, 6, 0x44, 0x11E, D_882180AC);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spD8);

    spC0 = mem_pool_alloc(argB, sizeof(unk_func_88001300_000));
    ((func8850AB48)Memmap_GetFragmentVaddr(func_8850AB48))(spC0, 4, 4, 0xF0, 0x122);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spC0);

    spC4 = mem_pool_alloc(argB, sizeof(unk_func_88001300_000));
    ((func8850AB48)Memmap_GetFragmentVaddr(func_8850AB48))(spC4, 0x134, 4, 0xF0, 0x122);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spC4);

    spB8 = mem_pool_alloc(argB, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(func_8850143C))(spB8, 6, 6, 0xEC, 0x1E, D_882180B0, D_882180B4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spB8);

    spBC = mem_pool_alloc(argB, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(func_8850143C))(spBC, 0x136, 6, 0xEC, 0x1E, D_882180B0, D_882180B4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, spBC);

    arg0->unk_30[0] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_030));
    func_8820CBA0(arg0->unk_30[0], spB8, spE8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spB8, arg0->unk_30[0]);
    func_8820D0EC(arg0->unk_30[0], 0);

    arg0->unk_30[1] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_030));
    func_8820CBA0(arg0->unk_30[1], spBC, spE8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(spBC, arg0->unk_30[1]);
    func_8820D0EC(arg0->unk_30[1], 1);

    temp_s0_2 = mem_pool_alloc(argB, sizeof(unk_func_8850143C));
    ((func8850143C)Memmap_GetFragmentVaddr(func_8850143C))(temp_s0_2, 0, 0x12A, 0x228, 0x38, D_882180C0, D_882180C4);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s0_2);

    arg0->unk_5C = mem_pool_alloc(argB, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_5C, 0, 0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(temp_s0_2, arg0->unk_5C);

    arg0->unk_60 = mem_pool_alloc(argB, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_60, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_5C, arg0->unk_60);

    for (i = 0; i < 6; i++) {
        temp_s0_3 = mem_pool_alloc(argB, sizeof(unk_func_8850878C));
        spA8 = func_8002D7C0(NULL, 0, D_88224FC4, D_882180C8[i].unk_00);
        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s0_3, (0x228 - func_8001F5B0(0x10, 0, spA8)) / 2,
                                                               0x10, spA8, 0x10);

        temp_s0_3->unk_30 = D_882180C8[i].unk_04[0];
        temp_s0_3->unk_44 = temp_s0_3->unk_44;
        temp_s0_3->unk_34 = D_882180C8[i].unk_04[1];
        temp_s0_3->unk_44 = 1;

        ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_60, temp_s0_3);
    }

    arg0->unk_64 = mem_pool_alloc(argB, sizeof(unk_func_88500994));
    ((func88500994)Memmap_GetFragmentVaddr(func_88500994))(arg0->unk_64, 0, 0);
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_5C, arg0->unk_64);

    for (j = 0; j < 2; j++) {
        temp_s0_4 = mem_pool_alloc(argB, sizeof(unk_func_8850878C));
        sp9C = func_8002D7C0(NULL, 0, D_88224FC4, D_882180F8[j].unk_00);
        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(temp_s0_4, (0x228 - func_8001F5B0(0x10, 0, sp9C)) / 2,
                                                               0x10, sp9C, 0x10);

        temp_s0_4->unk_30 = D_882180F8[j].unk_04[0];
        temp_s0_4->unk_44 = temp_s0_4->unk_44;
        temp_s0_4->unk_34 = D_882180F8[j].unk_04[1];
        temp_s0_4->unk_44 = 1;

        ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_64, temp_s0_4);
    }

    arg0->unk_68 = mem_pool_alloc(argB, sizeof(unk_func_8850878C));
    ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_68, 0x60, 4, "ERROR", 8);
    arg0->unk_68->unk_3C = 0x1C;
    ((func88500A3C)Memmap_GetFragmentVaddr(func_88500A3C))(arg0->unk_5C, arg0->unk_68);

    arg0->unk_40 = mem_pool_alloc(argB, sizeof(unk_func_88217740));
    func_88217740(arg0->unk_40, 0xF4, 5);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_40);

    arg0->unk_6C->unk_28 = mem_pool_alloc(argB, sizeof(unk_func_88001300_03C));
    ((func8850C284)Memmap_GetFragmentVaddr(func_8850C284))(arg0->unk_6C->unk_28, 6, 1, argB);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_6C, arg0->unk_6C->unk_28);

    for (x = 0; x < 6; x++) {
        arg0->unk_44[x] = mem_pool_alloc(argB, sizeof(unk_func_882149A0));

        func_882149A0(arg0->unk_44[x], D_88218108[x].unk_00, D_88218108[x].unk_02, D_88218108[x].unk_04,
                      D_88218108[x].unk_06, D_88218108[x].unk_08, D_88218108[x].unk_0C, D_88218108[x].unk_10[0],
                      D_88218108[x].unk_10[1], D_882180AC);

        if (D_88218108[x].unk_14 != 0) {
            func_882158BC(arg0->unk_44[x]);
        }

        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_44[x]);

        arg0->unk_6C->unk_28->unk_18[x * arg0->unk_6C->unk_28->unk_2C] = arg0->unk_44[x];
    }

    ((func8850CB48)Memmap_GetFragmentVaddr(func_8850CB48))(arg0->unk_6C->unk_28, 2);

    temp_s0_5 = mem_pool_alloc(argB, sizeof(unk_func_88001300_03C_01C));
    ((func88503340)Memmap_GetFragmentVaddr(func_88503340))(temp_s0_5, 0, 0, 0x10, 0x10, D_88218198);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_s0_5);
    arg0->unk_6C->unk_28->unk_1C = temp_s0_5;

    arg0->unk_38[0] = mem_pool_alloc(argB, sizeof(unk_func_8820BE14_02C_038));
    func_882158CC(arg0->unk_38[0], 6, 0x34, 8, func_8820DF38, 0xEC, 0x1C, argB);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_38[0], 0x64, argB);
    func_88217060(arg0->unk_38[0], &arg0->unk_78[0], 0);

    sp8C = mem_pool_alloc(argB, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp8C, 6, 0x24, 0xEC, 0, arg0->unk_38[0]);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp8C);

    sp90 = mem_pool_alloc(argB, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp90, 6, arg0->unk_38[0]->unk_00.unk_00.unk_14.unk_02 + 0x34,
                                                           0xEC, 1, arg0->unk_38[0]);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp90);
    func_882159AC(arg0->unk_38[0], sp90);

    temp_v0_9 = mem_pool_alloc(argB, sizeof(unk_func_882170A8));
    func_882170A8(temp_v0_9, 0xA8, 2, arg0->unk_38[0], 3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp90, temp_v0_9);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_38[0]);

    arg0->unk_38[1] = mem_pool_alloc(argB, sizeof(unk_func_8820BE14_02C_038));
    func_882158CC(arg0->unk_38[1], 0x136, 0x34, 8, func_8820DF38, 0xEC, 0x1C, argB);
    ((func88506238)Memmap_GetFragmentVaddr(func_88506238))(arg0->unk_38[1], 0x64, argB);
    func_88217060(arg0->unk_38[1], &arg0->unk_78[1], 0x10000);

    sp80 = mem_pool_alloc(argB, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(sp80, 0x136, 0x24, 0xEC, 0, arg0->unk_38[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp80);

    sp84 = mem_pool_alloc(argB, sizeof(unk_func_88507D4C));
    ((func88507D4C)Memmap_GetFragmentVaddr(func_88507D4C))(
        sp84, 0x136, arg0->unk_38[1]->unk_00.unk_00.unk_14.unk_02 + 0x34, 0xEC, 1, arg0->unk_38[1]);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, sp84);
    func_882159AC(arg0->unk_38[1], sp84);

    temp_v0_11 = mem_pool_alloc(argB, sizeof(unk_func_882170A8));
    func_882170A8(temp_v0_11, 0xA8, 2, arg0->unk_38[1], 3);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp84, temp_v0_11);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_38[1]);

    temp_v0_12 = mem_pool_alloc(argB, sizeof(unk_func_8820E99C));
    func_8820E99C(temp_v0_12, 0, 0, argB);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, temp_v0_12);

    arg0->unk_6C->unk_2C = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_06C_02C));
    func_8821064C(arg0->unk_6C->unk_2C, arg0->unk_38[0], arg0->unk_38[1], temp_v0_12, arg0->unk_40, arg0->unk_8C, argB);
    ((func8850BF80)Memmap_GetFragmentVaddr(func_8850BF80))(arg0->unk_6C, arg0->unk_6C->unk_2C);

    arg0->unk_6C->unk_2C->unk_50 = mem_pool_alloc(argB, sizeof(unk_func_8850CD44));
    ((func8850CD44)Memmap_GetFragmentVaddr(func_8850CD44))(arg0->unk_6C->unk_2C->unk_50, 4, argB);

    for (j = 0; j < 2; j++) {
        arg0->unk_6C->unk_2C->unk_58[j] = mem_pool_alloc(argB, sizeof(unk_func_882173EC));
        func_882173EC(arg0->unk_6C->unk_2C->unk_58[j], 0, 0);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_6C->unk_2C->unk_58[j]);

        arg0->unk_6C->unk_2C->unk_60[j] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_06C_02C_060));
        func_8820E5BC(arg0->unk_6C->unk_2C->unk_60[j], 0, 0, 0xEC);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_6C->unk_2C->unk_58[j],
                                                               arg0->unk_6C->unk_2C->unk_60[j]);
        arg0->unk_6C->unk_2C->unk_50->unk_1C[j] = arg0->unk_6C->unk_2C->unk_58[j];

        arg0->unk_6C->unk_2C->unk_68[j] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_06C_02C_068));
        func_88217650(arg0->unk_6C->unk_2C->unk_68[j], 0, 0);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_6C->unk_2C->unk_68[j]);

        arg0->unk_6C->unk_2C->unk_70[j] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_06C_02C_060));
        func_8820E5BC(arg0->unk_6C->unk_2C->unk_70[j], 0, 0, 0xEC);
        ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_6C->unk_2C->unk_68[j],
                                                               arg0->unk_6C->unk_2C->unk_70[j]);

        arg0->unk_6C->unk_2C->unk_50->unk_1C[j + 2] = arg0->unk_6C->unk_2C->unk_68[j];
    }

    arg0->unk_70[0] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_070));
    func_8820D9B8(arg0->unk_70[0], 6, 0x28, 0xEC, spE8, 3, 0, argB);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_70[0]);

    arg0->unk_70[1] = mem_pool_alloc(argB, sizeof(unk_func_8821421C_02C_070));
    func_8820D9B8(arg0->unk_70[1], 0x136, 0x28, 0xEC, spE8, 3, 1, argB);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0->unk_2C, arg0->unk_70[1]);

    temp_s0_6 = mem_pool_alloc(argB, sizeof(unk_func_88503298));
    ((func88503298)Memmap_GetFragmentVaddr(func_88503298))(temp_s0_6, arg0->unk_2C, arg6);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, temp_s0_6);

    for (i = 0; i < 1; i++) {
        sp6C = func_8002D7C0(NULL, 0, D_88224FC4, D_8821819C[i]);

        arg0->unk_94[i].unk_00 = mem_pool_alloc(argB, sizeof(unk_func_8850878C));
        ((func8850878C)Memmap_GetFragmentVaddr(func_8850878C))(arg0->unk_94[i].unk_00, 0, 0, sp6C, 0x10);

        arg0->unk_94[i].unk_00->unk_30 = D_882181A0;
        arg0->unk_94[i].unk_00->unk_44 = arg0->unk_94[i].unk_00->unk_44;
        arg0->unk_94[i].unk_08 = 0;
        arg0->unk_94[i].unk_04 = 0;
    }

    arg0->unk_A0 = mem_pool_alloc(argB, sizeof(unk_func_889000C4));
    ((func889000C4)Memmap_GetFragmentVaddr(func_889000C4))(arg0->unk_A0, 0, arg0->unk_2C, 0, argA, argB);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_A0);

    if (sp80) {}
    if (sp84) {}
    if (sp8C) {}
    if (sp90) {}
    if (spB8) {}
    if (spBC) {}
    if (spC8) {}
    if (spCC) {}
    if (spD0) {}
    if (spD4) {}
    if (spD8) {}
    if (spC0) {}
    if (spC4) {}
}

s32 func_8821347C(unk_func_8821421C_02C* arg0) {
    func88500A6C temp_v1_2;
    u8* temp_v0_2;
    char* sp2C;
    s32 var_a1 = arg0->unk_6C->unk_00.unk_1C;

    switch (var_a1) {
        case 0:
            if ((arg0->unk_6C->unk_28->unk_20 == 0x100) && (arg0->unk_6C->unk_28->unk_24 < 2)) {
                ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_5C, 1);
                temp_v1_2 = (func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C);
                if (arg0->unk_6C->unk_28->unk_24 == 0) {
                    var_a1 = 0;
                } else {
                    var_a1 = 1;
                }
                temp_v1_2(arg0->unk_64, var_a1);
            } else {
                ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_5C, 0);
                ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_60, arg0->unk_6C->unk_28->unk_24);
            }
            break;

        case 1:
            sp2C = NULL;
            ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_5C, 2);
            temp_v0_2 = func_88212150(arg0->unk_6C->unk_2C);
            if (temp_v0_2 != NULL) {
                sp2C = func_8002D7C0(NULL, 0, D_88224FCC, temp_v0_2[0] - 1);
            }
            arg0->unk_68->unk_40 = sp2C;
            break;
    }
    return 0;
}

s32 func_882135D4(unk_func_8821421C_02C* arg0, Controller* arg1) {
    s32 var_v1;

    if (arg0->unk_2C->unk_30 & 2) {
        var_v1 = func_88213CA0(arg0->unk_6C, arg1);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_88213618(unk_func_8821421C_02C* arg0, Controller* arg1) {
    s32 temp_v0;
    s32 var_s4 = 0;

    arg0->unk_00.unk_24(&arg0->unk_00, 1);

    ((func88502C98)Memmap_GetFragmentVaddr(func_88502C98))(arg0->unk_2C);

    while (var_s4 == 0) {
        func_8002EEA8(NULL);

        temp_v0 = arg0->unk_00.unk_20(arg0, gPlayer1Controller);

        if (!(temp_v0 & 1) && (temp_v0 & 2)) {
            var_s4 = 1;
            break;
        }

        ((func8850BC94)Memmap_GetFragmentVaddr(func_8850BC94))(temp_v0);
    }

    arg0->unk_2C->unk_2C = 0xB;
    return var_s4;
}

void func_882136F8(unk_func_8821421C_02C* arg0, s32 arg1) {
    arg0->unk_00.unk_2A = arg1;
    ((func8850BF60)Memmap_GetFragmentVaddr(func_8850BF60))(arg0->unk_6C, arg1);
}

void func_88213738(unk_func_8821421C_02C* arg0) {
    func_882158BC(arg0->unk_44[2]);
    func_882158BC(arg0->unk_44[4]);
    func_882158BC(arg0->unk_44[3]);
}

void func_88213774(unk_func_8821421C_02C_06C* arg0, unk_func_8821421C_02C* arg1) {
    ((func8850BDF0)Memmap_GetFragmentVaddr(func_8850BDF0))(arg0);
    arg0->unk_00.unk_24 = arg1;
}

s32 func_882137B4(unk_func_8821421C_03C* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 sp40;
    unk_func_80022C28_ret* temp_v0;
    unk_func_8821421C_02C_06C_02C_060_02C_000* var_s0;
    unk_func_8821421C_02C_06C_02C_060_02C_000 sp34;

    sp40 = 0;
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
        sp40 = 1;
    } else {
        var_s0 = arg0->unk_04.unk_00;
        for (i = 0; i < arg0->unk_04.unk_08; i++, var_s0++) {
            func_80022E18(&sp34, 1, temp_v0);
            if (bcmp(&sp34, var_s0, sizeof(unk_func_8821421C_02C_06C_02C_060_02C_000)) != 0) {
                arg0->unk_00 = 1;
                sp40 = 1;
                break;
            }
        }
    }

    func_80022D8C(temp_v0);
    return sp40;
}

s32 func_882138D4(unk_func_8821421C_02C* arg0) {
    s32 sp24;
    s32 sp20;
    s32 temp_a3;
    s32 temp_v0;
    s32 var_v1;
    s32 var_v1_2;
    unk_func_8821421C_03C* temp_v0_2;

    sp24 = func_80029080();
    sp20 = 0;

    if (func_882137B4(&arg0->unk_78[0], 0x23, sp24, 0) != 0) {
        sp20 = 1;
    }

    if (func_882137B4(&arg0->unk_78[1], 0x22, sp24, 0) != 0) {
        sp20 |= 2;
    }

    if (arg0->unk_78[2].unk_00 != 0) {
        if (arg0->unk_90[arg0->unk_7C->unk_00].unk_00 != 0) {
            if (func_882137B4(&arg0->unk_78[2], 0x12, 0, arg0->unk_7C->unk_00) != 0) {
                sp20 |= 4;
            }
        } else if (arg0->unk_78[2].unk_04.unk_08 > 0) {
            sp20 |= 4;
        } else {
            arg0->unk_78[2].unk_00 = 0;
        }
    }
    return sp20;
}

void func_882139C0(unk_func_8821421C_02C* arg0, s32 arg1) {
    s32 sp4C = func_80029080();
    char sp40[11];

    ((func88500A6C)Memmap_GetFragmentVaddr(func_88500A6C))(arg0->unk_A0->unk_40, 2);
    func_8002EEA8(NULL);

    if (arg0->unk_78[0].unk_00 != 0) {
        func_8820C97C(0x23, sp4C, 0, &arg0->unk_78[0].unk_04, 0, NULL, -1);
    }

    if (arg0->unk_78[1].unk_00 != 0) {
        func_8820C97C(0x22, sp4C, 0, &arg0->unk_78[1].unk_04, 0, NULL, -1);
    }

    if (arg0->unk_78[2].unk_00 != 0) {
        if (arg0->unk_90[arg0->unk_7C->unk_00].unk_00 != 0) {
            if (arg0->unk_78[2].unk_04.unk_08 == 0) {
                func_8002707C(0x12, arg0->unk_7C->unk_00);
            } else {
                func_8820C97C(0x12, 0, arg0->unk_7C->unk_00, &arg0->unk_78[2].unk_04, 0, NULL, -1);
            }
        } else {
            func_8820C97C(0x12, 0, arg0->unk_7C->unk_00, &arg0->unk_78[2].unk_04, 0, func_800251B0(sp4C, sp40),
                          func_80025084(sp4C));
        }
    }

    if (arg1 & 4) {
        func_800284B4(3);
    }

    if (arg1 & 3) {
        ((func88900970)Memmap_GetFragmentVaddr(func_88900970))(arg0->unk_A0, sp4C);
    }

    if (arg1 & 4) {
        func_80026E4C(3);
        func_800284B4(3);
    }
}

s32 func_88213B90(unk_func_8821421C_02C* arg0, Controller* arg1) {
    s32 sp24 = 1;
    s32 sp20 = func_882138D4(arg0);
    s32 temp_v0_2;

    if (sp20 != 0) {
        arg0->unk_6C->unk_28->unk_14(arg0->unk_6C->unk_28, 0);

        ((func889006D4)Memmap_GetFragmentVaddr(func_889006D4))(arg0->unk_A0, 0);
        temp_v0_2 = ((func88900808)Memmap_GetFragmentVaddr(func_88900808))(arg0->unk_A0, arg1, 1);

        if (temp_v0_2 == 0) {
            func_882139C0(arg0, sp20);
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_A0);
        } else if (temp_v0_2 == 1) {
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_A0);
        } else if (temp_v0_2 == 2) {
            ((func889007AC)Memmap_GetFragmentVaddr(func_889007AC))(arg0->unk_A0);
            sp24 = 0;
        }

        arg0->unk_6C->unk_28->unk_14(arg0->unk_6C->unk_28, 1);
    }
    return sp24;
}

s32 func_88213CA0(unk_func_8821421C_02C_06C* arg0, Controller* arg1) {
    s32 i;
    s32 var_a1;
    s32 var_s0;
    unk_func_88203ED8_064* var_a0;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;

    var_s0 = 0;
    if (arg0->unk_00.unk_20 > 0) {
        var_a0 = arg0->unk_00.unk_04;
        for (i = 0; i < arg0->unk_00.unk_1C; i++) {
            var_a0 = var_a0->unk_08;
        }
        var_s0 = var_a0->unk_10(var_a0, arg1);
    }

    if (var_s0 & 1) {
        return var_s0;
    }

    if (var_s0 == 0) {
        if (arg1->buttonPressed & 0x4000) {
            var_s0 = 0x80000002;
        } else if (arg1->buttonPressed & 0x8000) {
            var_s0 = 0x80000004;
        } else if (arg1->buttonPressed & 0x30) {
            var_s0 = 0x01000000;
        }
    }

    if (var_s0 & 2) {
        switch (arg0->unk_00.unk_1C) {
            case 0:
                func_80048B90(3);
                var_s0 = 2;
                if (func_88213B90(arg0->unk_00.unk_24, arg1) == 0) {
                    var_s0 = 3;
                }
                break;

            case 1:
                ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 0);
                var_s0 |= 1;
                break;
        }
    } else if (var_s0 & 4) {
        if (arg0->unk_00.unk_1C == 0) {
            switch (arg0->unk_28->unk_24) {
                case 0:
                case 1:
                    if (arg0->unk_28->unk_24 == 0) {
                        sp4C = 0;
                    } else {
                        sp4C = 1;
                    }
                    func_80048B90(2);

                    arg0->unk_28->unk_14(arg0->unk_28, 0x100);

                    func_8820DC1C(arg0->unk_00.unk_24->unk_70[sp4C], func_8820D0E4(arg0->unk_00.unk_24->unk_30[sp4C]));
                    func_8820DDC0(arg0->unk_00.unk_24->unk_70[sp4C],
                                  func_8820D0E4(arg0->unk_00.unk_24->unk_30[1 - sp4C]));
                    func_8820DC90(arg0->unk_00.unk_24->unk_70[sp4C]);

                    while (func_8820DCD4(arg0->unk_00.unk_24->unk_70[sp4C], arg1) == 1) {
                        sp48 = func_8820DC10(arg0->unk_00.unk_24->unk_70[sp4C]);
                        if ((sp48 == 2) && (arg0->unk_00.unk_24->unk_7C->unk_00 == -1)) {
                            arg0->unk_00.unk_24->unk_70[sp4C]->unk_00.unk_24(&arg0->unk_00.unk_24->unk_70[sp4C]->unk_00,
                                                                             0x100);

                            ((func8850A10C)Memmap_GetFragmentVaddr(func_8850A10C))(
                                arg0->unk_00.unk_24->unk_8C, arg0->unk_00.unk_24->unk_94[0].unk_00,
                                arg0->unk_00.unk_24->unk_94[0].unk_04, arg0->unk_00.unk_24->unk_94[0].unk_08);
                            ((func8850A3CC)Memmap_GetFragmentVaddr(func_8850A3CC))(arg0->unk_00.unk_24->unk_8C, arg1);

                            if (func_88210234(arg0->unk_00.unk_24->unk_84, arg1) == 1) {
                                func_8820D0EC(arg0->unk_00.unk_24->unk_30[sp4C], 2);

                                arg0->unk_00.unk_24->unk_7C->unk_00 =
                                    arg0->unk_00.unk_24->unk_84->unk_34->unk_00.unk_38;
                                arg0->unk_00.unk_24->unk_90[arg0->unk_00.unk_24->unk_7C->unk_00].unk_00 = 0;

                                func_88217060(arg0->unk_00.unk_24->unk_38[sp4C], &arg0->unk_00.unk_24->unk_78[2],
                                              arg0->unk_00.unk_24->unk_7C->unk_00 | 0x20000);
                            } else {
                                arg0->unk_00.unk_24->unk_70[sp4C]->unk_00.unk_24(
                                    &arg0->unk_00.unk_24->unk_70[sp4C]->unk_00, 1);
                                continue;
                            }
                            break;
                        } else {
                            func_8820D0EC(arg0->unk_00.unk_24->unk_30[sp4C], sp48);
                            func_88217060(arg0->unk_00.unk_24->unk_38[sp4C], &arg0->unk_00.unk_24->unk_78[sp48].unk_00,
                                          sp48 << 0x10);
                            break;
                        }
                    }

                    func_8820DCC4(arg0->unk_00.unk_24->unk_70[sp4C]);
                    arg0->unk_28->unk_14(arg0->unk_28, 1);
                    var_s0 = 1;
                    break;

                case 2:
                    func_88210D2C(arg0->unk_2C, 0);
                    ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                    var_s0 |= 1;
                    break;

                case 3:
                    func_88210D2C(arg0->unk_2C, 1);
                    ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                    var_s0 |= 1;
                    break;

                case 4:
                    func_88210D2C(arg0->unk_2C, 2);
                    ((func8850C064)Memmap_GetFragmentVaddr(func_8850C064))(arg0, 1);
                    var_s0 |= 1;
                    break;

                case 5:
                    func_80048B90(3);
                    var_s0 = 2;
                    if (func_88213B90(arg0->unk_00.unk_24, arg1) == 0) {
                        var_s0 = 3;
                    }
                    break;
            }
        }
    } else if (var_s0 & 0x01000000) {
        var_s0 = 1;
        sp40 = arg0->unk_2C->unk_44;
        sp44 = (arg1->buttonPressed & 0x20) != 0;

        switch (arg0->unk_00.unk_1C) {
            case 0:
                sp40 = sp44;
                break;

            case 1:
                if (func_88210D8C(arg0->unk_2C) != 0) {
                    sp40 = sp44;
                }
                break;
        }

        if (sp40 != arg0->unk_2C->unk_44) {
            func_882108A8(arg0->unk_2C);
            func_88213738(arg0->unk_00.unk_24);
            func_88217BC0(&arg0->unk_00.unk_24->unk_40->unk_00);
            ((func8850BFB0)Memmap_GetFragmentVaddr(func_8850BFB0))(arg0);
            var_s0 = 0x80000005;
        }
    }

    return var_s0;
}

void func_8821421C(unk_func_8821421C* arg0, s32 arg1, s32 arg2, MemoryPool* arg3, s32 arg4, char** arg5) {
    static Color_RGBA8 D_882181A4 = { 0x1E, 0x50, 0x50, 0xFF };
    static Color_RGBA8 D_882181A8 = { 0x00, 0x0A, 0x0A, 0xFF };

    unk_func_88001300_000* sp8C;
    unk_func_88001300_000* sp88;
    s32 sp84;
    char sp78[11];
    UNUSED s32 pad[2];
    s32 i;
    unk_func_88500EE4* sp68;
    unk_func_885088F4* sp64;
    unk_func_88509A2C* sp60;
    unk_func_88509E34* sp5C;

    sp84 = func_80029080();
    ((func885007CC)Memmap_GetFragmentVaddr(func_885007CC))(arg0, sizeof(unk_func_8821421C));
    arg0->unk_00.unk_10.unk_00 = arg1;
    arg0->unk_00.unk_10.unk_02 = arg2;

    for (i = 0; i < 3; i++) {
        arg0->unk_3C[i].unk_00 = 0;
    }

    func_8002C758(&arg0->unk_3C[0].unk_04, 2, 0x14, arg3);
    func_8002C758(&arg0->unk_3C[1].unk_04, 2, 0x32, arg3);
    func_8002C758(&arg0->unk_3C[2].unk_04, 2, 0x64, arg3);

    func_8820C930(0x23, sp84, 0, &arg0->unk_3C[0].unk_04);
    func_8820C930(0x22, sp84, 0, &arg0->unk_3C[1].unk_04);

    func_8820CA2C(arg0->unk_7C);

    arg0->unk_78 = func_8820CAB4(arg0->unk_7C, func_80025084(sp84), func_800251B0(sp84, sp78));
    if ((arg0->unk_78 != -1) && (arg0->unk_7C[arg0->unk_78].unk_00 != 0)) {
        func_8820C930(0x12, 0, arg0->unk_78, &arg0->unk_3C[2].unk_04);
    }

    sp8C = mem_pool_alloc(arg3, sizeof(unk_func_88001300_000));
    ((func885031E8)Memmap_GetFragmentVaddr(func_885031E8))(sp8C, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, sp8C);

    sp68 = mem_pool_alloc(arg3, sizeof(unk_func_88500EE4));
    ((func88500EE4)Memmap_GetFragmentVaddr(func_88500EE4))(sp68, 0, 0, 0x280, 0x1E0, D_88223E48, D_882181A4,
                                                           D_882181A8);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp8C, sp68);

    sp64 = mem_pool_alloc(arg3, sizeof(unk_func_885088F4));
    ((func885088F4)Memmap_GetFragmentVaddr(func_885088F4))(sp64, 0x41, 0x15C, 0xDC);
    sp64->unk_2C = 5;
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp8C, sp64);

    sp60 = mem_pool_alloc(arg3, sizeof(unk_func_88509A2C));
    ((func88509A2C)Memmap_GetFragmentVaddr(func_88509A2C))(sp60, 0x38, 0x22, func_80029080(),
                                                           func_8002D7C0(NULL, 0, D_88224FC0, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, sp60);

    sp5C = mem_pool_alloc(arg3, sizeof(unk_func_88509E34));
    ((func88509E34)Memmap_GetFragmentVaddr(func_88509E34))(sp5C, 0, 0, func_8002D7C0(NULL, 0, D_88224FC4, 0));
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp64, sp5C);

    arg0->unk_34 = mem_pool_alloc(arg3, sizeof(unk_func_8821421C_034));
    func_8820D0F4(arg0->unk_34, 0xBA, 0xAE, arg3);

    sp88 = mem_pool_alloc(arg3, sizeof(unk_func_88001300_000));
    ((func885031E8)Memmap_GetFragmentVaddr(func_885031E8))(sp88, 0, 0, 0x280, 0x1E0);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, sp88);

    arg0->unk_38 = mem_pool_alloc(arg3, sizeof(unk_func_8821421C_038));
    func_8820F3B8(arg0->unk_38, 0x2C, 0x4B, sp88, arg0->unk_34, arg3);
    func_8820FFF8(arg0->unk_38, &arg0->unk_7C);

    arg0->unk_30 = mem_pool_alloc(arg3, sizeof(unk_func_88509F48));
    ((func88509F48)Memmap_GetFragmentVaddr(func_88509F48))(arg0->unk_30, 0x2C, 0x4B, 0x228, 0x162, arg3, arg4);

    arg0->unk_2C = mem_pool_alloc(arg3, sizeof(unk_func_8821421C_02C));
    func_882121E0(arg0->unk_2C, 0x2C, 0x4B, arg0->unk_3C, &arg0->unk_78, arg0->unk_7C, sp8C, arg0->unk_38, arg0->unk_34,
                  arg0->unk_30, arg5, arg3);

    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(sp88, arg0->unk_2C);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_38);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_34);
    ((func8850068C)Memmap_GetFragmentVaddr(func_8850068C))(arg0, arg0->unk_30);
}

void func_88214720(unk_func_8821421C* arg0) {
    s32 sp34 = 0;

    while (sp34 == 0) {
        func_800079C4();

        ((func885008C4)Memmap_GetFragmentVaddr(func_885008C4))(arg0);
        ((func88500828)Memmap_GetFragmentVaddr(func_88500828))(arg0, 0, 0);

        func_80007778();
        func_8002EF18(&sp34);
    }
}

void func_882147BC(unk_func_8821421C* arg0) {
    s32 sp24 = func_88213618(arg0->unk_2C, gPlayer1Controller);

    while (arg0->unk_2C->unk_2C->unk_00.unk_28 & 1) {
        func_8002EEA8(0);
    }

    func_8002EEA8(sp24);

    osStopThread(NULL);
}

void func_8821483C(s32 arg0) {
    MemoryPool* sp34;
    void* sp30;
    u8* sp2C;
    func_88002628_sp38* sp28;
    char** sp24;

    main_pool_push_state('OTPC');

    sp2C = main_pool_alloc(0x10000, 0);
    sp34 = mem_pool_try_init(0x10000, 0);

    func_8002D510();

    D_88224FC0 = func_8002D5AC(0x2A);
    D_88224FC4 = func_8002D5AC(3);
    D_88224FC8 = func_8002D5AC(0x27);
    D_88224FCC = func_8002D5AC(0xC);
    sp24 = func_8002D5AC(7);

    sp30 = mem_pool_alloc(sp34, sizeof(unk_func_8821421C));
    func_8821421C(sp30, 0, 0, sp34, arg0, sp24);

    sp28 = ALIGN16((u32)mem_pool_alloc(sp34, sizeof(func_88002628_sp38)));

    osCreateThread(&sp28->thread, 0x32, func_882147BC, sp30, sp2C + 0x10000, osGetThreadPri(NULL) - 1);

    func_8002EE78();
    func_8001F738(gPlayer1Controller);

    osStartThread(&sp28->thread);

    func_88214720(sp30);

    osDestroyThread(&sp28->thread);

    main_pool_pop_state('OTPC');
}
