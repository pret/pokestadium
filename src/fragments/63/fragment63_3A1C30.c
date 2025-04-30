#include "fragment63.h"
#include "src/12D80.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/26820.h"
#include "src/49790.h"
#include "src/F420.h"
#include "src/math_util.h"
#include "src/memmap.h"
#include "src/memory.h"

static unk_D_84B17550 D_84B17550[] = {
    {
        78,
        84,
        164,
        72,
        2,
        8481,
        0,
        -1,
        44,
    },
    {
        78,
        91,
        164,
        58,
        2,
        8481,
        0,
        -1,
        44,
    },
    {
        77,
        122,
        166,
        92,
        5,
        8481,
        0,
        -1,
        9362,
    },
    {
        77,
        142,
        166,
        52,
        3,
        8481,
        0,
        -1,
        146,
    },
    {
        77,
        144,
        166,
        52,
        3,
        8481,
        0,
        -1,
        146,
    },
    {
        77,
        149,
        166,
        38,
        2,
        8481,
        0,
        -1,
        18,
    },
    {
        60,
        40,
        200,
        64,
        1,
        8481,
        0,
        -1,
        2,
    },
    {
        60,
        40,
        200,
        64,
        1,
        8481,
        0,
        -1,
        2,
    },
    {
        68,
        32,
        184,
        104,
        1,
        8481,
        1,
        -1,
        2,
    },
    {
        60,
        38,
        200,
        164,
        2,
        26889,
        0,
        -1,
        13,
    },
};

void func_84B0DB30(unk_D_84B2665C* arg0, s16 arg1, s16 arg2) {
    static s16 D_84B17604 = 0;

    if (D_84B17604 < 6) {
        arg1 = (arg1 + (D_84B17604 / 2));
    } else {
        arg1 = ((arg1 - (D_84B17604 / 2)) + 6);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    gDPLoadTextureBlock(gDisplayListHead++, D_10031D0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 22, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_8001C330(arg1, arg2 + (arg0->unk_04 * 0xE) + 1, 0x10, 0xB, 0, 0, 0x800, 0x800, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_84B17604 = (D_84B17604 + 1) % 12;
}

void func_84B0DD5C(unk_D_84B2665C* arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s8* arg5) {
    if (arg4 == 0) {
        func_8001F324(0x64, 0x64, 0x64, 0xFF);
    } else if (arg3 == arg0->unk_04) {
        func_8001F324(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_8001F1E8(arg1, arg2 + (arg3 * 0xE), arg5);
}

void func_84B0DE04(unk_D_84B2665C* arg0, unk_D_84B17550* arg1) {
    func_84B0DB30(arg0, arg1->unk_00 + 0xC, arg1->unk_02 + 0x18);
    func_8001F3F4();
    func_8001EBE0(2, 0);
    func_8001F1E8(arg1->unk_00 + 0x10, arg1->unk_02 + 6, func_84B0037C(0x29));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x22, arg1->unk_02 + 0x18, 0, 1, func_84B0037C(0x2A));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x22, arg1->unk_02 + 0x18, 1, 1, func_84B0037C(0x2B));

    if (arg1->unk_06 == 0x48) {
        func_8001EBE0(1, 0);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F1E8(arg1->unk_00 + 0x4A, arg1->unk_02 + 0x36, "%s%d", func_84B0037C(0x2C), D_800AE540.unk_11F3);
    }

    func_8001F444();
}

void func_84B0DF70(unk_D_84B2665C* arg0, unk_D_84B17550* arg1) {
    s32 sp2C;
    s32 sp28;

    sp2C = D_800AE540.unk_11F3 > 0;
    sp28 = !!(D_800AE540.unk_11F5 & 2);
    sp28 = !sp28;

    func_84B0DB30(arg0, arg1->unk_00 + 5, arg1->unk_02 + 6);
    func_8001F3F4();
    func_8001EBE0(2, 0);
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 0, sp2C, func_84B0037C(0x2D));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 1, sp2C, func_84B0037C(0x2E));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 2, sp28, func_84B0037C(0x2F));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 3, 1, func_84B0037C(0x30));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 4, 1, func_84B0037C(0x31));
    func_8001EBE0(1, 0);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F1E8(arg1->unk_00 + 0x4A, arg1->unk_02 + 0x4C, "%s%d", func_84B0037C(0x2C), D_800AE540.unk_11F3);
    func_8001F444();
}

void func_84B0E198(unk_D_84B2665C* arg0, unk_D_84B17550* arg1) {
    s32 sp2C = !!(D_800AE540.unk_11F5 & 2);

    sp2C = !sp2C;
    func_84B0DB30(arg0, arg1->unk_00 + 5, arg1->unk_02 + 6);
    func_8001F3F4();
    func_8001EBE0(2, 0);
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 0, sp2C, func_84B0037C(0x2F));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 1, 1, func_84B0037C(0x32));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 2, 1, func_84B0037C(0x31));
    func_8001F444();
}

void func_84B0E2D8(unk_D_84B2665C* arg0, unk_D_84B17550* arg1) {
    s32 sp2C = D_800AE540.unk_1194[0].unk_1E < 0x63 && D_800AE540.unk_1194[1].unk_1E < 0x63;

    func_84B0DB30(arg0, arg1->unk_00 + 5, arg1->unk_02 + 6);
    func_8001F3F4();
    func_8001EBE0(2, 0);
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 0, sp2C, func_84B0037C(0x33));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 1, 1, func_84B0037C(0x34));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 2, 1, func_84B0037C(0x31));
    func_8001F444();
}

void func_84B0E424(unk_D_84B2665C* arg0, unk_D_84B17550* arg1) {
    func_84B0DB30(arg0, arg1->unk_00 + 5, arg1->unk_02 + 6);
    func_8001F3F4();
    func_8001EBE0(2, 0);
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 0, 1, func_84B0037C(0x35));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x1A, arg1->unk_02 + 6, 1, 1, func_84B0037C(0x31));
    func_8001F444();
}

void func_84B0E50C(unk_D_84B2665C* arg0, unk_D_84B17550* arg1) {
    char* temp_v0;

    func_8001F3F4();
    func_8001F470();
    func_8001EBE0(4, 0);
    func_8001F36C(0x32, 0xFF, 0x64, 0xFF);

    if ((D_800AE540.unk_0000 == 3) || (D_800AE540.unk_0000 == 6)) {
        temp_v0 = func_84B0037C(D_800AE540.unk_0000 - 1);
        func_8001F1E8((arg1->unk_00 - (func_8001F5B0(4, 0, temp_v0) / 2)) + 0x64, arg1->unk_02 + 6, temp_v0);
        temp_v0 = func_84B0037C(D_800AE540.unk_0002 + 7);
        func_8001F1E8((arg1->unk_00 - (func_8001F5B0(4, 0, temp_v0) / 2)) + 0x64, arg1->unk_02 + 0x18, temp_v0);
        temp_v0 = func_84B0037C(D_800AE540.unk_0003 + 0xA);
        func_8001F1E8((arg1->unk_00 - (func_8001F5B0(4, 0, temp_v0) / 2)) + 0x64, arg1->unk_02 + 0x2A, temp_v0);
    } else {
        temp_v0 = func_84B0037C(D_800AE540.unk_0000 - 1);
        func_8001F1E8((arg1->unk_00 - (func_8001F5B0(4, 0, temp_v0) / 2)) + 0x64, arg1->unk_02 + 0xA, temp_v0);
        temp_v0 = func_84B0037C(D_800AE540.unk_0003 + 0xA);
        func_8001F1E8((arg1->unk_00 - (func_8001F5B0(4, 0, temp_v0) / 2)) + 0x64, arg1->unk_02 + 0x26, temp_v0);
    }

    func_8001F4C4();
    func_8001F444();
}

void func_84B0E718(unk_D_84B2665C* arg0, unk_D_84B17550* arg1) {
    s32 sp12C;
    char sp2C[0x100];

    func_8001F3F4();
    func_8001F470();
    func_8001EBE0(4, 0);
    func_8001F36C(0x32, 0xFF, 0x64, 0xFF);

    sprintf(sp2C, "%s %s", func_84B0037C(D_800AE540.unk_0002 + 0x13), func_84B0037C(0x36));
    sp12C = func_8001F5B0(4, 0, sp2C);
    func_8001F1E8((arg1->unk_00 - (sp12C / 2)) + 0x64, arg1->unk_02 + 0xA, sp2C);

    if (D_800AE540.unk_0002 < 9) {
        if (D_800AE540.unk_0002 == 8) {
            sprintf(sp2C, "%s %d", func_84B0037C(0x1B), D_800AE540.unk_0003);
            sp12C = func_8001F5B0(4, 0, sp2C);
            func_8001F1E8((arg1->unk_00 - (sp12C / 2)) + 0x64, arg1->unk_02 + 0x26, sp2C);
        } else if (D_800AE540.unk_0003 < 4) {
            sprintf(&sp2C, "%s %d", func_84B0037C(0x37), D_800AE540.unk_0003);
            sp12C = func_8001F5B0(4, 0, sp2C);
            func_8001F1E8((arg1->unk_00 - (sp12C / 2)) + 0x64, arg1->unk_02 + 0x26, sp2C);
        } else {
            sp12C = func_8001F5B0(4, 0, func_84B0037C(D_800AE540.unk_0002 + 0x1D));
            func_8001F1E8((arg1->unk_00 - (sp12C / 2)) + 0x64, arg1->unk_02 + 0x26,
                          func_84B0037C(D_800AE540.unk_0002 + 0x1D));
        }
    }

    func_8001F4C4();
    func_8001F444();
}

void func_84B0E948(s16 arg0, s16 arg1, unk_D_800AE540_1194* arg2) {
    static u8* D_84B17608[] = { D_3025950, D_30260A0, D_30267F0, D_3026F40 };

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (arg2->unk_01 == 1) {
        if (arg2->unk_08[0]->unk_000 & 2) {
            func_8001C6AC(arg0 + 0x1A, arg1 + 3, 0x24, 0x1A, D_3025200, 0x24, 0);
            if (0) {}
        } else {
            func_8001C6AC(arg0 + 0x1A, arg1 + 3, 0x24, 0x1A, D_84B17608[arg2->unk_08[0]->unk_001], 0x24, 0);
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);
        return;
    }

    if (arg2->unk_08[0]->unk_001 < arg2->unk_08[1]->unk_001) {
        func_8001C6AC(arg0 + 6, arg1 + 3, 0x24, 0x1A, D_84B17608[arg2->unk_08[0]->unk_001], 0x24, 0);
        func_8001C6AC(arg0 + 0x30, arg1 + 3, 0x24, 0x1A, D_84B17608[arg2->unk_08[1]->unk_001], 0x24, 0);
    } else {
        func_8001C6AC(arg0 + 6, arg1 + 3, 0x24, 0x1A, D_84B17608[arg2->unk_08[1]->unk_001], 0x24, 0);
        func_8001C6AC(arg0 + 0x30, arg1 + 3, 0x24, 0x1A, D_84B17608[arg2->unk_08[0]->unk_001], 0x24, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(4, 0);
    func_8001F2E4(arg0 + 0x24, arg1 + 8, 0x26);
    func_8001F444();
}

void func_84B0EC18(unk_D_800AE540_1194* arg0) {
    static s16 D_84B17618 = 0;

    if (arg0->unk_1C == 1) {
        func_8001F324(0xFF, (SINS((s32)(SINS(D_84B17618) * 16384.0f)) * 100.0f) + 155.0f, 0x37, 0xFF);
        D_84B17618 += 0x400;
    } else {
        func_8001F324(0xFF, 0x37, 0x37, 0xFF);
    }
}

void func_84B0ECE8(unk_D_84B2665C* arg0, unk_D_84B17550* arg1) {
    func_84B0053C(arg1->unk_00 + 8, arg1->unk_02 + 0x14, 0xA8, 0x20, 0, 0, 0, 0xFF);
    func_84B0053C(arg1->unk_00 + 8, arg1->unk_02 + 0x44, 0xA8, 0x20, 0, 0, 0, 0xFF);
    func_84B0E948(arg1->unk_00 + 8, arg1->unk_02 + 0x14, D_800AE540.unk_1194);
    func_84B0E948(arg1->unk_00 + 8, arg1->unk_02 + 0x44, &D_800AE540.unk_1194[1]);
    func_8001F3F4();
    func_8001F470();
    func_8001EBE0(4, 0);
    func_8001F36C(0x32, 0xFF, 0x64, 0xFF);
    func_8001F1E8(arg1->unk_00 + 0x40, arg1->unk_02 + 2, func_84B0037C(0x38));
    func_8001F4C4();
    func_8001EBE0(0x10, 0);
    func_84B0EC18(&D_800AE540.unk_1194[0]);
    func_8001F1E8(arg1->unk_00 + 0x5C, arg1->unk_02 + 0x18, "%2d", D_800AE540.unk_1194[0].unk_1E);
    func_84B0EC18(&D_800AE540.unk_1194[1]);
    func_8001F1E8(arg1->unk_00 + 0x5C, arg1->unk_02 + 0x48, "%2d", D_800AE540.unk_1194[1].unk_1E);
    func_8001EBE0(4, 0);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F1E8(arg1->unk_00 + 0x82, arg1->unk_02 + 0x1F, func_84B0037C(0x39));
    func_8001F1E8(arg1->unk_00 + 0x82, arg1->unk_02 + 0x4F, func_84B0037C(0x39));
    func_8001F444();
}

void func_84B0EF14(unk_D_84B2665C* arg0, unk_D_84B17550* arg1) {
    unk_func_800281D4 sp50;
    UNUSED s32 pad;
    s32 sp48;
    s32 temp_v0;

    func_80028320(&sp50, NULL);
    func_84B0053C(arg1->unk_00 + 0x10, arg1->unk_02 + 0x14, 0xA8, 0x3C, 0, 0, 0, 0xFF);
    func_84B0053C(arg1->unk_00 + 0x10, arg1->unk_02 + 0x60, 0xA8, 0x22, 0, 0, 0, 0xFF);
    func_84B0DB30(arg0, arg1->unk_00 + 0x14, arg1->unk_02 + 0x64);
    func_8001F3F4();
    func_8001EBE0(2, 0);
    func_8001F1E8(arg1->unk_00 + 0x10, arg1->unk_02 + 6, func_84B0037C(0x3A));
    func_8001F1E8(arg1->unk_00 + 0x10, arg1->unk_02 + 0x52, func_84B0037C(0x3B));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x2A, arg1->unk_02 + 0x64, 0, 1, func_84B0037C(0x3C));
    func_84B0DD5C(arg0, arg1->unk_00 + 0x2A, arg1->unk_02 + 0x64, 1, 1, func_84B0037C(0x3D));
    func_8001F324(0xFF, 0x64, 0x64, 0xFF);

    if (sp50.unk_00 == 7) {
        func_8001F1E8(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x17, func_84B0037C(sp50.unk_00 - 1));
        func_8001F1E8(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x26, func_84B0037C(sp50.unk_01 + 0x13));
        if (sp50.unk_01 < 8) {
            if (sp50.unk_02 < 4) {
                func_8001F1E8(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x35, "%s %d", func_84B0037C(0x37), sp50.unk_02);
            } else {
                func_8001F1E8(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x35, func_84B0037C(0x3E));
            }
        } else {
            func_8001F1E8(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x35, "%s %d", func_84B0037C(0x1B), sp50.unk_02);
        }
    } else if ((sp50.unk_00 == 3) || (sp50.unk_00 == 6)) {
        func_8001F1E8(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x17, func_84B0037C(sp50.unk_00 - 1));
        func_8001F1E8(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x26, func_84B0037C(sp50.unk_01 + 7));
        func_8001F1E8(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x35, func_84B0037C(sp50.unk_02 + 0xA));
    } else {
        func_8001F1E8(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x17, func_84B0037C(sp50.unk_00 - 1));
        func_8001F1E8(arg1->unk_00 + 0x1E, arg1->unk_02 + 0x26, func_84B0037C(sp50.unk_02 + 0xA));
    }

    if (sp50.unk_00 != 7) {
        func_8001EBE0(1, 0);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F1E8(arg1->unk_00 + 0x64, arg1->unk_02 + 0x43, "%s %d", func_84B0037C(0x2C), sp50.unk_04);
    }

    if (arg0->unk_04 == 0) {
        sp48 = (arg1->unk_04 - func_8001F5B0(1, 0, func_84B0037C(0x3F))) / 2;
        func_8001EBE0(1, 0);
        func_8001F324(0xFF, 0xFF, 0, 0xFF);
        func_8001F3B4(0xC);
        func_8001F1E8(arg1->unk_00 + sp48, arg1->unk_02 + 0x86, func_84B0037C(0x3F));
    }

    func_8001F444();

    if (sp50.unk_03 == 1) {
        temp_v0 = func_8001F5B0(1, 0, func_84B0037C(sp50.unk_00 - 1));

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_8001C6AC(arg1->unk_00 + temp_v0 + 0x20, arg1->unk_02 + 0x15, 0x10, 0x10, D_3027690, 0x10, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }
}

void func_84B0F464(unk_D_84B2665C* arg0) {
    unk_D_84B17550* temp_s0;
    s16 temp_a1;
    s16 var_a3;

    if ((arg0->unk_00 != 0) && (arg0->unk_02 > 0)) {
        temp_s0 = &D_84B17550[arg0->unk_01 - 1];

        if (arg0->unk_02 < 4) {
            var_a3 = (temp_s0->unk_06 * arg0->unk_02) / 4;
            if (var_a3 < 0x10) {
                var_a3 = 0x10;
            }

            temp_a1 = temp_s0->unk_02 + ((temp_s0->unk_06 - var_a3) / 2);
            if (temp_s0->unk_0C == 0) {
                func_80020460(temp_s0->unk_00, temp_a1, temp_s0->unk_04, var_a3, temp_s0->unk_0A);
            } else {
                func_84B0053C(temp_s0->unk_00, temp_a1, temp_s0->unk_04, var_a3, 0x1E, 0x1E, 0x82, 0xFF);
            }
        } else {
            if (temp_s0->unk_0C == 0) {
                func_80020460(temp_s0->unk_00, temp_s0->unk_02, temp_s0->unk_04, temp_s0->unk_06, temp_s0->unk_0A);
            } else {
                func_84B0053C(temp_s0->unk_00, temp_s0->unk_02, temp_s0->unk_04, temp_s0->unk_06, 0x1E, 0x1E, 0x82,
                              0xFF);
            }

            switch (arg0->unk_01) {
                case 1:
                    func_84B0DE04(arg0, temp_s0);
                    break;

                case 2:
                    func_84B0DE04(arg0, temp_s0);
                    break;

                case 3:
                    func_84B0DF70(arg0, temp_s0);
                    break;

                case 4:
                    func_84B0E198(arg0, temp_s0);
                    break;

                case 5:
                    func_84B0E2D8(arg0, temp_s0);
                    break;

                case 6:
                    func_84B0E424(arg0, temp_s0);
                    break;

                case 7:
                    func_84B0E50C(arg0, temp_s0);
                    break;

                case 8:
                    func_84B0E718(arg0, temp_s0);
                    break;

                case 9:
                    func_84B0ECE8(arg0, temp_s0);
                    break;

                case 10:
                    func_84B0EF14(arg0, temp_s0);
                    break;
            }
        }
    }
}

void func_84B0F6C4(unk_D_84B2665C* arg0) {
    unk_D_84B17550* sp24;
    s16 sp22;
    s32 tmp;

    sp24 = &D_84B17550[arg0->unk_01 - 1];
    sp22 = sp24->unk_08 - 1;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        tmp = sp24->unk_10 >> (arg0->unk_04 * 3);
        switch (tmp & 7) {
            case 1:
                func_80048B90(3);
                break;

            case 2:
                func_80048B90(2);
                break;

            case 3:
                func_80048B90(0x1C);
                break;

            case 4:
                func_80048B90(0x20);
                break;

            case 5:
                func_80048B90(0x1D);
                break;

            case 6:
                func_80048B90(0x21);
                break;
        }
        arg0->unk_00 = 2;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        func_80048B90(1);
        do {
            arg0->unk_04--;
            if (arg0->unk_04 < 0) {
                arg0->unk_04 = sp22;
            }
        } while (!(sp24->unk_0E & (1 << arg0->unk_04)));
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        func_80048B90(1);
        do {
            arg0->unk_04++;
            if (sp22 < arg0->unk_04) {
                arg0->unk_04 = 0;
            }
        } while (!(sp24->unk_0E & (1 << arg0->unk_04)));
    }
}

void func_84B0F888(unk_D_84B2665C* arg0) {
    arg0->unk_02++;
    if (arg0->unk_02 >= 5) {
        arg0->unk_02 = 4;
        arg0->unk_00 = 3;
    }
}

void func_84B0F8BC(unk_D_84B2665C* arg0) {
    arg0->unk_02--;
    if (arg0->unk_02 < 0) {
        arg0->unk_02 = 0;
        arg0->unk_00 = 4;
    }
}

void func_84B0F8E8(unk_D_84B2665C* arg0) {
    switch (arg0->unk_00) {
        case 1:
            func_84B0F888(arg0);
            break;

        case 2:
            func_84B0F8BC(arg0);
            break;

        case 3:
            func_84B0F6C4(arg0);
            break;
    }
}

void func_84B0F950(unk_D_84B2665C* arg0, s16 arg1) {
    unk_D_84B17550* ptr = &D_84B17550[arg1 - 1];

    arg0->unk_01 = arg1;
    arg0->unk_02 = 0;
    arg0->unk_04 = 0;
    arg0->unk_00 = 1;

    ptr->unk_0E = -1;

    func_80048B90(4);

    if (arg1 - 1 == 2) {
        if (D_800AE540.unk_11F3 == 0) {
            ptr->unk_0E &= ~3;
        }
        if (D_800AE540.unk_11F5 & 2) {
            ptr->unk_0E &= ~4;
        }
    } else if (arg1 - 1 == 3) {
        if (D_800AE540.unk_11F5 & 2) {
            ptr->unk_0E &= ~1;
        }
    } else if ((arg1 - 1 == 4) &&
               ((D_800AE540.unk_1194[0].unk_1E >= 0x63) || (D_800AE540.unk_1194[1].unk_1E >= 0x63))) {
        ptr->unk_0E &= ~1;
    }

    while (!(ptr->unk_0E & (1 << arg0->unk_04))) {
        arg0->unk_04++;
    }
}

void func_84B0FACC(unk_D_84B2665C* arg0) {
    arg0->unk_00 = 0;
    arg0->unk_01 = 0;
    arg0->unk_02 = 0;
}

s32 func_84B0FADC(unk_D_84B2665C* arg0) {
    if (arg0->unk_00 == 4) {
        arg0->unk_00 = 0;
        return arg0->unk_04;
    }
    return -1;
}
