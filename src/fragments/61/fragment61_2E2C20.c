#include "fragment61.h"
#include "src/19840.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/225A0.h"
#include "src/22630.h"
#include "src/232C0.h"
#include "src/26820.h"
#include "src/2E110.h"
#include "src/49790.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/dp_intro.h"
#include "src/hal_libc.h"

typedef struct unk_D_842115F0 {
    /* 0x00 */ Color_RGB8 unk_00[4];
    /* 0x0C */ u8* unk_0C;
} unk_D_842115F0; // size = 0x10

unk_D_842115F0 D_842115F0[] = {
    {
        {
            { 0xB4, 0xB4, 0xB4 },
            { 0x5A, 0x5A, 0x5A },
            { 0xF0, 0xF0, 0xF0 },
            { 0x00, 0x00, 0x00 },
        },
        D_2017740,
    },
    {
        {
            { 0xD2, 0x64, 0x28 },
            { 0xA0, 0x32, 0x1E },
            { 0xF0, 0x96, 0x32 },
            { 0x00, 0x00, 0x00 },
        },
        D_2019040,
    },
    {
        {
            { 0x3C, 0x64, 0xDC },
            { 0x1E, 0x1E, 0x96 },
            { 0x50, 0x96, 0xF0 },
            { 0x00, 0x00, 0x00 },
        },
        D_20199A0,
    },
    {
        {
            { 0xAA, 0x46, 0xDC },
            { 0x64, 0x1E, 0xA0 },
            { 0xC8, 0x96, 0xF0 },
            { 0x00, 0x00, 0x00 },
        },
        D_2019680,
    },
    {
        {
            { 0x96, 0x82, 0x3C },
            { 0x5A, 0x50, 0x1E },
            { 0xF0, 0xC8, 0x78 },
            { 0x00, 0x00, 0x00 },
        },
        D_2018D20,
    },
    {
        {
            { 0x64, 0x96, 0x96 },
            { 0x1E, 0x50, 0x50 },
            { 0x64, 0xB4, 0xB4 },
            { 0x00, 0x00, 0x00 },
        },
        D_2018A00,
    },
    {
        {
            { 0x3C, 0x64, 0xDC },
            { 0x1E, 0x1E, 0x96 },
            { 0x50, 0x96, 0xF0 },
            { 0x00, 0x00, 0x00 },
        },
        D_20199A0,
    },
    {
        {
            { 0x6E, 0xA0, 0x1E },
            { 0x28, 0x5A, 0x1E },
            { 0xC8, 0xF0, 0x50 },
            { 0x00, 0x00, 0x00 },
        },
        D_2019360,
    },
    {
        {
            { 0xA0, 0x8C, 0xB4 },
            { 0x5A, 0x46, 0x6E },
            { 0xDC, 0xC8, 0xF0 },
            { 0x00, 0x00, 0x00 },
        },
        D_2019FE0,
    },
    {
        {
            { 0xC8, 0x3C, 0x3C },
            { 0x8C, 0x1E, 0x1E },
            { 0xF0, 0x64, 0x64 },
            { 0x00, 0x00, 0x00 },
        },
        D_2017A60,
    },
    {
        {
            { 0x32, 0x96, 0xDC },
            { 0x1E, 0x64, 0xA0 },
            { 0x46, 0xB4, 0xF0 },
            { 0x00, 0x00, 0x00 },
        },
        D_2017D80,
    },
    {
        {
            { 0x1E, 0xAA, 0x1E },
            { 0x1E, 0x6E, 0x1E },
            { 0x64, 0xC8, 0x64 },
            { 0x00, 0x00, 0x00 },
        },
        D_20183C0,
    },
    {
        {
            { 0xB4, 0x96, 0x1E },
            { 0x78, 0x64, 0x1E },
            { 0xF0, 0xF0, 0x32 },
            { 0x00, 0x00, 0x00 },
        },
        D_20186E0,
    },
    {
        {
            { 0xC8, 0x5A, 0x96 },
            { 0x8C, 0x1E, 0x5A },
            { 0xF0, 0x8C, 0xB4 },
            { 0x00, 0x00, 0x00 },
        },
        D_2019CC0,
    },
    {
        {
            { 0x64, 0xBE, 0xBE },
            { 0x1E, 0x8C, 0x8C },
            { 0xB4, 0xF0, 0xF0 },
            { 0x00, 0x00, 0x00 },
        },
        D_20180A0,
    },
    {
        {
            { 0x1E, 0xA0, 0x8C },
            { 0x1E, 0x64, 0x50 },
            { 0x64, 0xDC, 0xC8 },
            { 0x00, 0x00, 0x00 },
        },
        D_201A300,
    },
};
s16 D_842116F0[] = { 0x14A, 0x15E, 0xFC, 0xE4 };
s16 D_842116F8[] = { 0x7C, 0x95, 0xAE, 0x95 };

void func_8420B390(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s8* arg4) {
    if (arg2 == arg3) {
        func_8001F324(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_8001F1E8(arg0, arg1, arg4);
}

void func_8420B40C(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (arg2 != 0) {
        func_80020928(arg0 + 0x19C, arg1 + (arg3 * 0x16) + 0x3A);
        func_8001F3F4();
        func_8001EBE0(8, 0);
        func_8001F3B4(0x16);

        switch (arg2) {
            case 1:
                func_8001F1E8(arg0 + 0x19C, arg1 + 0x20, func_84200130(0));
                break;

            case 2:
                func_8001F1E8(arg0 + 0x19C, arg1 + 0x20, func_84200130(1));
                break;

            case 3:
                func_8001F1E8(arg0 + 0x19C, arg1 + 0xA, func_84200130(2));
                break;
        }

        func_8001EBE0(8, 0);
        func_8420B390(arg0 + 0x1CE, arg1 + 0x3A, 0, arg3, func_84200130(3));
        func_8420B390(arg0 + 0x1CE, arg1 + 0x50, 1, arg3, func_84200130(4));
        func_8001F444();
    }
}

void func_8420B5A4(s16 arg0, s16 arg1, s16 arg2) {
    unk_D_842115F0* sp34 = &D_842115F0[func_800219FC(arg2)];
    unk_D_842115F0* sp30 = &D_842115F0[func_800219FC(arg2)];

    gDPSetEnvColor(gDisplayListHead++, sp34->unk_00->r, sp34->unk_00->g, sp34->unk_00->b, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, (sp30->unk_00 + 1)->r, (sp30->unk_00 + 1)->g, (sp30->unk_00 + 1)->b, 255);

    func_8001CADC(arg0, arg1, 0x14, 0x28, D_20165C0, 0x18, 0);
    func_8001CADC(arg0 + 0x38, arg1, 0x14, 0x28, D_2016980, 0x18, 0);
    func_8001C330(arg0 + 0x14, arg1, 0x24, 0x28, 0, 0, 0, 0x400, 0);
}

void func_8420B71C(s16 arg0, s16 arg1, s32 arg2) {
    s16 i;
    s16 var_a3;

    if (arg2 != 0) {
        gSPDisplayList(gDisplayListHead++, D_8006F4E0);
        gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);

        for (i = 0; i < 0x54; i += 0x14) {
            var_a3 = CLAMP_MIN(0x54 - i, 20);
            func_8001C6AC(arg0, arg1 + i, 0x64, var_a3, (i * 0xC8) + arg2, 0x64, 0x200000);
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }
}

s16 func_8420B870(s16 arg0, s16 arg1, char* arg2) {
    if (arg0 >= 2) {
        arg1 -= func_8001F5B0(8, 0, arg2, arg1);
    }
    return arg1;
}

void func_8420B8CC(unk_D_8423D3A8* arg0, s32 arg1) {
    UNUSED s32 pad[2];
    s16 i;
    s16 temp_s4;
    s16 temp_s5;
    char* temp_v0_8;
    unk_func_80026268_arg0* temp_s6;

    temp_s4 = arg0->unk_06;
    temp_s5 = arg0->unk_08;
    temp_s6 = &arg0->unk_2C->unk_004;

    if (arg0->unk_00 != 0) {
        func_842001B8(temp_s4, temp_s5, arg0->unk_0A, arg0->unk_0C);
        if ((arg0->unk_0A == 0x228) && (arg0->unk_0C == 0xCC)) {
            if (arg0->unk_2C->unk_000 == 4) {
                func_84200420(temp_s4 + 4, temp_s5 + 4, 0x190, 0x1C, 0xAA, 0x3C, 0x96, 0xFF);
            } else {
                switch (arg0->unk_2C->unk_001) {
                    case 0:
                        func_84200420(temp_s4 + 4, temp_s5 + 4, 0x190, 0x1C, 0xAA, 0x3C, 0x3C, 0xFF);
                        break;

                    case 9:
                        func_84200420(temp_s4 + 4, temp_s5 + 4, 0x190, 0x1C, 0xAA, 0x3C, 0x96, 0xFF);
                        break;

                    default:
                        func_84200420(temp_s4 + 4, temp_s5 + 4, 0x190, 0x1C, 0xB4, 0x8C, 0x28, 0xFF);
                        break;
                }
            }

            func_84200420(temp_s4 + 0x68, temp_s5 + 0x20, 0x12C, 0x54, 0xB4, 0xAA, 0x64, 0xFF);
            func_84200420(temp_s4 + 0x194, temp_s5 + 4, 0x90, 0x78, 0x32, 0x32, 0x82, 0xFF);
            func_84200420(temp_s4 + 4, temp_s5 + 0x74, 0x220, 0x54, 0xA0, 0x96, 0x32, 0xFF);

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            func_8001C6AC(temp_s4 + 0x108, temp_s5 + 0x77, 0x1C, 0x1A, D_2014F00, 0x1C, 0);
            func_8001C6AC(temp_s4 + 0xF0, temp_s5 + 0x90, 0x1C, 0x1A, D_20154B0, 0x1C, 0);
            func_8001C6AC(temp_s4 + 0x11C, temp_s5 + 0x90, 0x1C, 0x1A, D_2016010, 0x1C, 0);
            func_8001C6AC(temp_s4 + 0x108, temp_s5 + 0xA9, 0x1C, 0x1A, D_2015A60, 0x1C, 0);

            if ((arg0->unk_2C->unk_000 != 4) && (arg0->unk_2C->unk_001 == 0xD)) {
                func_8001C6AC(temp_s4 + 0x14, temp_s5 + 0x78, 0x40, 0x14, D_2016D40, 0x40, 0);
            }

            gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0,
                              ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0);

            func_8420B5A4(temp_s4 + 0x6A, temp_s5 + 0x26, temp_s6->unk_06);

            if (temp_s6->unk_06 != temp_s6->unk_07) {
                func_8420B5A4(temp_s4 + 0xBA, temp_s5 + 0x26, temp_s6->unk_07);
            }

            gSPDisplayList(gDisplayListHead++, D_8006F630);

            func_8420B71C(temp_s4 + 4, temp_s5 + 0x20, arg0->unk_20);
            func_8420B40C(temp_s4, temp_s5, arg0->unk_01, arg0->unk_02);
            func_8001F3F4();
            func_8001EBE0(8, 0);
            func_8001F1E8(temp_s4 + 0xC, temp_s5 + 8, temp_s6->unk_30);
            func_8001EBE0(8, 0);
            func_8001F1E8(temp_s4 + 0x84, temp_s5 + 8, "%s %d", func_84200160(0x15), temp_s6->unk_24);
            func_8001EBE0(4, 0);
            func_8001F1E8(temp_s4 + 0xE8, temp_s5 + 0xC, "%s%03d", func_84200160(0x16), temp_s6->unk_00.unk_00);
            func_8001EBE0(4, 0);
            func_8001F1E8(temp_s4 + 0x13C, temp_s5 + 0xC, func_84200088(temp_s6->unk_00.unk_00));
            func_8001EBE0(8, 0);
            func_8001F1E8(temp_s4 + 0x76, temp_s5 + 0x5A, "%s", func_84200160(8));
            func_8001EBE0(8, 0);
            func_8001F1E8(temp_s4 + 0xA4, temp_s5 + 0x5A, "%3d", temp_s6->unk_26);
            func_8001EBE0(4, 0);
            func_8001F1E8(temp_s4 + 0x116, temp_s5 + 0x25, func_84200130(5));
            func_8001F1E8(temp_s4 + 0x116, temp_s5 + 0x38, func_84200130(6));
            func_8001F1E8(temp_s4 + 0x116, temp_s5 + 0x4B, func_84200130(7));
            func_8001F1E8(temp_s4 + 0x116, temp_s5 + 0x5E, func_84200130(8));
            func_8001EBE0(4, 0);
            func_8001F1E8(temp_s4 + 0x15E, temp_s5 + 0x25, "%3d", temp_s6->unk_28);
            func_8001F1E8(temp_s4 + 0x15E, temp_s5 + 0x38, "%3d", temp_s6->unk_2A);
            func_8001F1E8(temp_s4 + 0x15E, temp_s5 + 0x4B, "%3d", temp_s6->unk_2C);
            func_8001F1E8(temp_s4 + 0x15E, temp_s5 + 0x5E, "%3d", temp_s6->unk_2E);
            func_8001EBE0(4, 0);
            temp_v0_8 = func_84200130(9);
            func_8001F1E8((temp_s4 - (func_8001F5B0(4, 0, temp_v0_8) / 2)) + 0x90, temp_s5 + 0x26, temp_v0_8);
            temp_v0_8 = func_842000F8(func_800219FC(temp_s6->unk_06));
            func_8001F1E8((temp_s4 - (func_8001F5B0(4, 0, temp_v0_8) / 2)) + 0x90, temp_s5 + 0x3A, temp_v0_8);

            if (temp_s6->unk_06 != temp_s6->unk_07) {
                temp_v0_8 = func_84200130(0xA);
                func_8001F1E8((temp_s4 - (func_8001F5B0(4, 0, temp_v0_8) / 2)) + 0xE0, temp_s5 + 0x26, temp_v0_8);
                temp_v0_8 = func_842000F8(func_800219FC(temp_s6->unk_07));
                func_8001F1E8((temp_s4 - (func_8001F5B0(4, 0, temp_v0_8) / 2)) + 0xE0, temp_s5 + 0x3A, temp_v0_8);
            }

            func_8001EBE0(8, 0);

            {
                s16 sp80;
                Color_RGB8* color;
                u8 temp_a0;

                for (i = 0; i < 4; i++) {
                    temp_a0 = temp_s6->unk_09[i];
                    if (temp_a0 == 0) {
                        break;
                    }
                    color = &D_842115F0[D_80072338[temp_a0 - 1].unk_01].unk_00[2];
                    sp80 = func_8420B870(i, D_842116F0[i], func_842000C0(temp_a0));
                    func_8001F324(color->r, color->g, color->b, 0xFF);
                    func_8001F1E8(temp_s4 + sp80, D_842116F8[i] + temp_s5, func_842000C0(temp_s6->unk_09[i]));
                }

                func_8001F444();

                gSPDisplayList(gDisplayListHead++, D_8006F518);

                for (i = 0; i < 4; i++) {
                    if (temp_s6->unk_09[i] == 0) {
                        break;
                    }

                    sp80 = func_8420B870(i, D_842116F0[i], func_842000C0(temp_s6->unk_09[i]));
                    func_8001C6AC((temp_s4 + sp80) - 0x18, D_842116F8[i] + temp_s5, 0x14, 0x14,
                                  D_842115F0[D_80072338[temp_s6->unk_09[i] - 1].unk_01].unk_0C, 0x14, 0);
                }
            }

            gSPDisplayList(gDisplayListHead++, D_8006F630);

            arg0->unk_20 = 0;
        }
    }
}

void func_8420C360(unk_D_8423D3A8* arg0) {
}

void func_8420C368(unk_D_8423D3A8* arg0) {
    Controller* cont = &gControllers[arg0->unk_03];

    if (BTN_IS_PRESSED(cont, BTN_A)) {
        if (arg0->unk_01 == 0) {
            func_80048B90(3);
        } else if (arg0->unk_02 == 0) {
            func_80048B90(0x22);
        } else {
            func_80048B90(3);
        }
        arg0->unk_04 = 0;
        arg0->unk_00 = 3;
    } else if (BTN_IS_PRESSED(cont, BTN_B)) {
        func_80048B90(3);
        arg0->unk_04 = 0;
        arg0->unk_02 = 1;
        arg0->unk_00 = 3;
    } else if (BTN_IS_PRESSED(cont, BTN_DUP | BTN_DDOWN) && (arg0->unk_01 != 0)) {
        func_80048B90(1);
        arg0->unk_02 ^= 1;
    }

    arg0->unk_06 = arg0->unk_0E.x1;
    arg0->unk_08 = arg0->unk_0E.y2;
    arg0->unk_0A = 0x228;
    arg0->unk_0C = 0xCC;
    arg0->unk_20 = func_8001B9D4(arg0->unk_28);
}

void func_8420C484(unk_D_8423D3A8* arg0) {
    arg0->unk_06 = arg0->unk_0E.x1;
    arg0->unk_08 = arg0->unk_0E.y2;
    arg0->unk_0A = 0x228;
    arg0->unk_0C = 0xCC;
    arg0->unk_00 = 1;
    arg0->unk_20 = func_8001B9D4(arg0->unk_28);
}

void func_8420C4DC(unk_D_8423D3A8* arg0) {
    arg0->unk_06 = arg0->unk_16.x1;
    arg0->unk_08 = arg0->unk_16.y2;
    arg0->unk_0A = 0x8C;
    arg0->unk_0C = 0x34;
    arg0->unk_00 = 0;
}

s32 func_8420C504(unk_D_8423D3A8* arg0) {
    arg0->unk_24 = func_80019760(1);
    arg0->unk_28 = func_8001B1FC(arg0->unk_24, 0x64, 0x54, 0, 0, 0x64, 0x54, NULL);
    arg0->unk_28->unk_00 &= ~2;
    arg0->unk_00 = 0;
    arg0->unk_03 = 0;
    arg0->unk_04 = 0;
    arg0->unk_20 = 0;
    return 0x10;
}

s32 func_8420C580(unk_D_8423D3A8* arg0) {
    s32 sp1C = 0;

    switch (arg0->unk_00) {
        case 0:
            sp1C = 0;
            func_8420C360(arg0);
            break;

        case 1:
            sp1C = 0;
            func_8420C368(arg0);
            break;

        case 2:
            func_8420C484(arg0);
            sp1C = 1;
            break;

        case 3:
            func_8420C4DC(arg0);
            sp1C = 1;
            break;
    }
    return sp1C;
}

s32 func_8420C60C(unk_D_8423D3A8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5,
                  unk_D_838067F0_0168_0000* arg6, s16 arg7) {
    if (arg0->unk_00 != 0) {
        return 0;
    }

    func_8001B2D8(arg0->unk_28, &arg6->unk_004, 0x108D);

    arg0->unk_00 = 2;
    arg0->unk_01 = arg7;
    arg0->unk_02 = 0;
    arg0->unk_03 = arg1;
    arg0->unk_04 = 0;
    arg0->unk_20 = 0;
    arg0->unk_2C = arg6;

    func_80005FC0(&arg0->unk_0E, arg2, arg3, arg2 + 0x227, arg3 + 0xCB);
    func_80005FC0(&arg0->unk_16, arg4, arg5, arg4 + 0x8B, arg5 + 0x33);
    return 1;
}

s32 func_8420C6D8(unk_D_8423D3A8* arg0, s16 arg1, s16 arg2, unk_D_838067F0_0168_0000* arg3) {
    if (arg0->unk_00 != 1) {
        return 0;
    }

    while (func_80001C90() == 0) {}

    func_8001B2D8(arg0->unk_28, &arg3->unk_004, 0x108D);
    arg0->unk_2C = arg3;
    func_80005FC0(&arg0->unk_16, arg1, arg2, arg1 + 0x8B, arg2 + 0x33);
    return 1;
}

s32 func_8420C788(unk_D_8423D3A8* arg0) {
    s16 var_v1 = 0;

    if (arg0->unk_00 == 0) {
        var_v1 = arg0->unk_02 + 1;
    }
    return var_v1;
}
