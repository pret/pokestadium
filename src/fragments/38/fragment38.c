#include "fragment38.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/22630.h"
#include "src/2C1C0.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/4CBC0.h"
#include "src/6A40.h"
#include "src/DDC0.h"
#include "src/F420.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static char** D_82305A20;
static char** D_82305A24;
static unk_D_82305A28 D_82305A28;
static unk_D_82305A30 D_82305A30;
static unk_D_82305A30 D_82305A38;
static unk_D_82305A40 D_82305A40;
static unk_D_82305A50 D_82305A50[6];
static unk_D_82305AF8 D_82305AF8[2];
static unk_D_8230F528 D_8230F528[3];

static unk_D_82305920 D_82305920[] = {
    {
        68,
        132,
        248,
        56,
        3,
    },
    {
        324,
        132,
        248,
        56,
        4,
    },
    {
        68,
        200,
        248,
        56,
        6,
    },
    {
        324,
        200,
        248,
        56,
        5,
    },
    {
        68,
        268,
        248,
        56,
        254,
    },
    {
        324,
        268,
        248,
        56,
        255,
    },
    {
        80,
        385,
        152,
        48,
        1,
    },
    {
        244,
        385,
        152,
        48,
        2,
    },
};
static s16 D_82305970[] = {
    0x0198, 0x0181, 0x0098, 0x0030, 0, 0,
};
static unk_D_82305978 D_8230597C[] = {
    {
        50,
        55,
        155,
        1,
    },
    {
        50,
        55,
        155,
        1,
    },
    {
        50,
        55,
        155,
        1,
    },
    {
        25,
        30,
        80,
        8,
    },
    {
        15,
        20,
        50,
        16,
    },
    {
        1,
        100,
        300,
        32,
    },
};

void func_82300020(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    static s16 D_823059AC = 0;

    s16 temp_ft3 = SINS(D_823059AC) * 2;
    UNUSED s32 pad[2];

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 240, 212, 104, 255);

    func_8001CADC(arg0 + temp_ft3, arg1 + temp_ft3, 0x10, 0x10, D_2000C80, 0x10, 0);
    func_8001CADC(arg0 + temp_ft3, ((arg1 + arg3) - temp_ft3) - 0x10, 0x10, 0x10, D_2000F80, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - temp_ft3) - 0x10, arg1 + temp_ft3, 0x10, 0x10, D_2000D80, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - temp_ft3) - 0x10, ((arg1 + arg3) - temp_ft3) - 0x10, 0x10, 0x10, D_2000E80, 0x10, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_823059AC += 0x2000;
}

void func_82300214(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001CADC(arg0 - 3, arg1 - 3, 8, 8, D_2000340, 8, 0);
    func_8001CADC((arg0 + arg2) - 5, arg1 - 3, 8, 8, D_2000380, 8, 0);
    func_8001C330(arg0 + 4, arg1 - 3, arg2 - 8, 8, 0, 0, 0, 0x400, 0);
    func_8001CADC(arg0 - 3, (arg1 + arg3) - 5, 8, 8, D_20002C0, 8, 0);
    func_8001C330(arg0 - 3, arg1 + 4, 8, arg3 - 8, 0, 0, 0x400, 0, 0);
    func_8001CADC((arg0 + arg2) - 5, (arg1 + arg3) - 5, 8, 8, D_2000300, 8, 0);
    func_8001C330(arg0 + 4, (arg1 + arg3) - 5, arg2 - 8, 8, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 5, arg1 + 4, 8, arg3 - 8, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_8230047C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 var_s2;
    s16 var_s3;
    s16 temp_a2;
    s16 temp_s0_32;

    if (arg2 >= 0x20) {
        var_s3 = 0x10;
    } else {
        var_s3 = arg2 / 2;
    }

    if (arg3 >= 0x20) {
        var_s2 = 0x10;
    } else {
        var_s2 = arg3 / 2;
    }

    temp_a2 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20288E0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028960, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20287E0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028860, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3,
                  0x4000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((temp_a2 > 0) && (temp_s0_32 > 0)) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, var_s2, arg4, arg5, arg6, arg7);
        func_8001C604(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        func_8001C604(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, temp_a2, var_s2, arg4, arg5, arg6, arg7);
    } else if (temp_a2 > 0) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        func_8001C604(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82300C7C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 sp48;
    s16 sp44;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x10) {
        var_s3 = 8;
    } else {
        var_s3 = arg2 / 2;
    }

    if (arg3 >= 0x10) {
        var_s2 = 8;
    } else {
        var_s2 = arg3 / 2;
    }

    sp48 = arg2 - (var_s3 * 2);
    sp44 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A60, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028AA0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20289E0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A20, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3,
                  0x2000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((sp48 > 0) && (sp44 > 0)) {
        func_8001C604(arg0 + var_s3, arg1, sp48, var_s2, arg4, arg5, arg6, arg7);
        func_8001C604(arg0, arg1 + var_s3, arg2, sp44, arg4, arg5, arg6, arg7);
        func_8001C604(arg0 + var_s3, (arg1 + var_s3) + sp44, sp48, var_s2, arg4, arg5, arg6, arg7);
    } else if (sp48 > 0) {
        func_8001C604(arg0 + var_s3, arg1, sp48, arg3, arg4, arg5, arg6, arg7);
    } else if (sp44 > 0) {
        func_8001C604(arg0, arg1 + var_s2, arg2, sp44, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_8230147C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    func_8001CADC(arg0, arg1, 8, 8, D_2000B40, 8, 0);
    func_8001CADC((arg0 + arg2) - 8, arg1, 8, 8, D_2000B80, 8, 0);
    func_8001C330(arg0 + 8, arg1, arg2 - 0x10, 8, 0, 0, 0, 0x400, 0);
    func_8001CADC(arg0, (arg1 + arg3) - 8, 8, 8, D_2000BC0, 8, 0);
    func_8001C330(arg0, arg1 + 8, 8, arg3 - 0x10, 0, 0, 0x400, 0, 0);
    func_8001CADC((arg0 + arg2) - 8, (arg1 + arg3) - 8, 8, 8, D_2000C00, 8, 0);
    func_8001C330(arg0 + 8, (arg1 + arg3) - 8, arg2 - 0x10, 8, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 8, arg1 + 8, 8, arg3 - 0x10, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    func_8001C604(arg0 + 8, arg1 + 8, arg2 - 0x10, arg3 - 0x10, arg4, arg5, arg6, arg7);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82301794(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg0, arg1, 0x30, 0x18, D_2006C00, 0x30, 0);
    func_8001C6AC(arg0, arg1 + 0x18, 0x30, 0x18, D_2007500, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82301868(s16 arg0, s16 arg1, s16 arg2, Color_RGBA8* arg3, Color_RGBA8* arg4) {
    gSPDisplayList(gDisplayListHead++, D_8006F558);

    gDPSetEnvColor(gDisplayListHead++, arg3->r, arg3->g, arg3->b, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, arg4->r, arg4->g, arg4->b, 255);

    func_8001CADC(arg0, arg1, 0x10, 0x20, D_20003C0, 0x10, 0);
    func_8001CADC((arg0 + arg2) - 0x10, arg1, 0x10, 0x20, D_20005C0, 0x10, 0);
    func_8001C330(arg0 + 0x10, arg1, arg2 - 0x20, 0x20, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82301A10(void) {
    Color_RGBA8 sp2C;
    Color_RGBA8 sp28;

    func_8000E820(&sp2C, 0x64, 0x64, 0xC8);
    func_8000E820(&sp28, 0x28, 0x28, 0x8C);
    func_82301868(0x48, 0x28, 0x208, &sp2C, &sp28);
    func_82301794(0x30, 0x20);
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F324(0, 0, 0, 0xFF);
    func_8001F1E8(0x6A, 0x2C, func_8002D7C0(NULL, 0, D_82305A20, 8));
    func_8001F324(0xFF, 0xFF, 0x77, 0xFF);
    func_8001F1E8(0x68, 0x2A, func_8002D7C0(NULL, 0, D_82305A20, 8));
    func_8001F444();
}

void func_82301B0C(unk_D_82305A30* arg0) {
    s16 tmp1;
    s16 tmp2;
    s16 sp3A;

    if (arg0->unk_02 >= 0x10) {
        tmp1 = arg0->unk_02;
        tmp2 = arg0->unk_04;
        sp3A = arg0->unk_06 + ((0x3C - tmp1) / 2);

        func_82300C7C(tmp2, sp3A, 0x210, tmp1, 0x1E, 0x1E, 0x82, 0x96);
        if (((0x3C - tmp1) == 0) && (D_82305A28.unk_02 < 8)) {
            func_8001F3F4();
            func_8001EBE0(8, 0);
            func_8001F3B4(0x18);
            func_8001F1E8(tmp2 + 0x20, sp3A + 8,
                          func_8002D7C0(NULL, 0, D_82305A20, D_82305A50[D_82305A28.unk_02].unk_18));
            func_8001F444();
        }
    }
}

void func_82301C30(unk_D_82305A30* arg0) {
    switch (arg0->unk_00) {
        case 1:
            arg0->unk_02 += 6;
            if (arg0->unk_02 == 0x3C) {
                arg0->unk_00 = 0;
            }
            break;

        case 2:
            arg0->unk_02 -= 6;
            if (arg0->unk_02 == 0) {
                arg0->unk_00 = 0;
            }
            break;
    }
}

void func_82301C98(unk_D_82305A30* arg0, s16 arg1, s16 arg2) {
    arg0->unk_00 = 0;
    arg0->unk_02 = 0;
    arg0->unk_04 = arg1;
    arg0->unk_06 = arg2;
}

void func_82301CC4(unk_D_82305A50* arg0) {
    s16 temp_s1;
    s16 temp_s2;

    if (arg0->unk_00 != 0) {
        temp_s1 = arg0->unk_08;
        temp_s2 = arg0->unk_0A;

        func_82300214(temp_s1, temp_s2, 0xF8, 0x38);

        gSPDisplayList(gDisplayListHead++, D_8006F470);

        if (arg0->unk_0C != NULL) {
            if (arg0->unk_01 != 0) {
                func_8001C560(temp_s1 + 4, temp_s2 + 4, 0xF0, 0x30, 0x1E, 0x1E, 0x64);
            } else {
                func_8001C560(temp_s1 + 4, temp_s2 + 4, 0xF0, 0x30, 0x64, 0x1E, 0x1E);
            }

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            func_8001C6AC(temp_s1 + 8, temp_s2 + 8, 0x28, 0x28, arg0->unk_0C, 0x28, 0);
        } else {
            func_8001C560(temp_s1 + 4, temp_s2 + 4, 0xF0, 0x30, 0x1E, 0x5A, 0x1E);
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        func_8001F3F4();
        if (arg0->unk_0C != NULL) {
            s32 sp3C = temp_s2 + 8;
            char sp44[64];

            func_8001EBE0(8, 0);

            if (arg0->unk_01 != 0) {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                func_8001F324(0xDC, 0x37, 0x37, 0xFF);
            }

            func_8001F1E8(temp_s1 + 0x34, sp3C, arg0->unk_10);
            func_8001EBE0(4, 0);
            func_8001F324(0x92, 0xC1, 0xFF, 0xFF);
            sprintf(sp44, "%s%d~%d", func_8002D7C0(NULL, 0, D_82305A24, 0x15), arg0->unk_14, arg0->unk_16);
            func_8001F1E8((temp_s1 - (s16)func_8001F5B0(4, 0, sp44)) + 0xEA, temp_s2 + 0x20, sp44);
        } else {
            func_8001EBE0(8, 0);
            func_8001F1E8((temp_s1 - ((s16)func_8001F5B0(8, 0, arg0->unk_10) / 2)) + 0x7A, temp_s2 + 0x12,
                          arg0->unk_10);
        }
        func_8001F444();
    }
}

void func_82301FF0(unk_D_82305A50* arg0) {
    switch (arg0->unk_00) {
        case 2:
            arg0->unk_02 -= 1;
            if (arg0->unk_02 == 0) {
                arg0->unk_00 = 1;
            }

            if (arg0->unk_04 < 0x140) {
                arg0->unk_08 = arg0->unk_04 - (arg0->unk_02 << 5);
            } else {
                arg0->unk_08 = arg0->unk_04 + (arg0->unk_02 << 5);
            }
            break;

        case 3:
            arg0->unk_02 += 1;
            if (arg0->unk_02 == 0xA) {
                arg0->unk_00 = 0;
            }

            if (arg0->unk_04 < 0x140) {
                arg0->unk_08 = arg0->unk_04 - (arg0->unk_02 << 5);
            } else {
                arg0->unk_08 = arg0->unk_04 + (arg0->unk_02 << 5);
            }
            break;
    }
}

void func_823020B4(unk_D_82305A50* arg0, s16 arg1, s16 arg2, u8* arg3, s8* arg4, s16 arg5, s16 arg6) {
    arg0->unk_00 = 0;
    arg0->unk_02 = 0xA;
    arg0->unk_04 = arg1;
    arg0->unk_06 = arg2;
    arg0->unk_08 = arg1;
    arg0->unk_0A = arg2;
    arg0->unk_0C = arg3;
    arg0->unk_10 = arg4;
    arg0->unk_14 = 0;
    arg0->unk_16 = 0;
    arg0->unk_18 = arg6;
    arg0->unk_01 = 1;

    if (arg5 != 0) {
        arg0->unk_14 = D_8230597C[arg5 - 1].unk_00;
        arg0->unk_16 = D_8230597C[arg5 - 1].unk_02;
        arg0->unk_01 = func_82302BB4(&D_82305AF8[0], arg5);
        arg0->unk_01 &= func_82302BB4(&D_82305AF8[1], arg5);
    }
}

void func_82302188(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    if (arg3 != 0) {
        func_8230147C(arg1, arg2, 0x84, 0x2C, 0x64, 0x1E, 0x1E, 0xFF);
    } else if (arg0 == 0) {
        func_8230147C(arg1, arg2, 0x84, 0x2C, 0x3C, 0x3C, 0xA0, 0xFF);
    } else {
        func_8230147C(arg1, arg2, 0x84, 0x2C, 0x1E, 0x64, 0x1E, 0xFF);
    }
}

static s16 D_823059B0[] = { 0x78, 0xFC, 0x180, 0x78, 0xFC, 0x180 };
static s16 D_823059BC[] = { 4, 4, 4, 0x30, 0x30, 0x30 };

void func_82302268(unk_D_82305AF8* arg0, s16 arg1, s16 arg2) {
    s16 i;
    s16 tmp1;
    s16 tmp2;
    s16 tmp3;

    func_82300214(arg1, arg2, 0x208, 0x60);
    if (arg0->unk_0001 == 0) {
        func_8230147C(arg1 + 4, arg2 + 4, 0x74, 0x58, 0x64, 0x64, 0xC8, 0xFF);
    } else {
        func_8230147C(arg1 + 4, arg2 + 4, 0x74, 0x58, 0x1E, 0x82, 0x1E, 0xFF);
    }

    for (i = 0; i < 6; i++) {
        tmp1 = arg0->unk_0001;
        tmp2 = D_823059B0[i] + arg1;
        tmp3 = D_823059BC[i] + arg2;
        func_82302188(tmp1, tmp2, tmp3, arg0->unk_0020[i].unk_25);
    }
}

void func_823023F8(unk_D_82305AF8* arg0, s16 arg1, s16 arg2) {
    char sp40[256];
    s16 sp3E;

    if (arg0->unk_0003 == 0) {
        sp3E = (arg0->unk_0010 >= 0) ? (s16)(SINS((s16)(SINS(arg0->unk_0010) * 16384.0f)) * 127.0f) + 0x7F
                                     : (s16)(SINS(arg0->unk_0010) * 127.0f) + 0x7F;

        func_8001F504(arg1 + 0x78, arg2 + 4, 0x18C, 0x58, 0x64, 0x1E, 0x1E, (sp3E * 2) / 3);
        func_8001F3F4();
        func_8001EBE0(0x10, 0);
        func_8001F324(0xFF, 0xFF, 0, sp3E);
        func_8001F3B4(0x20);
        func_8002D600(3, D_8230597C[arg0->unk_0004 - 1].unk_04);
        func_8001F1E8(arg1 + 0x88, arg2 + 0x14, func_8002D7C0(sp40, 0x100, D_82305A20, 9));
        func_8001F444();
        arg0->unk_0010 += 0x300;
    }
}

void func_823025B8(unk_D_82305AF8* arg0) {
    u8* var_s0;
    s16 i;
    s16 sp58;
    s16 sp56;
    s16 tmp1;
    s16 tmp2;
    s16 tmp3;
    s16 tmp4;

    if (arg0->unk_0000 != 0) {
        sp58 = arg0->unk_000C;
        sp56 = arg0->unk_000E;

        if (arg0->unk_0001 == 0) {
            var_s0 = D_3024C80;
        } else {
            var_s0 = D_30260C0;
        }

        func_82302268(arg0, sp58, sp56);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_8001C6AC(sp58 + 0x1A, sp56 + 8, 0x48, 0x12, var_s0, 0x48, 0);
        func_8001C6AC(sp58 + 0x1A, sp56 + 0x1A, 0x48, 0x12, var_s0 + 0xA20, 0x48, 0);

        for (i = 0; i < 6; i++) {
            tmp1 = D_823059B0[i] + sp58 + 2;
            tmp2 = D_823059BC[i] + sp56 + 2;
            func_8001C6AC(tmp1, tmp2, 0x28, 0x28, arg0->unk_0218[i], 0x28, 0);
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        func_8001F3F4();
        func_8001EBE0(8, 0);
        func_8001F1E8((sp58 - (func_8001F5B0(8, 0, arg0->unk_0014) / 2)) + 0x3E, sp56 + 0x2F, arg0->unk_0014);
        func_8001EBE0(4, 0);
        func_8001F1E8((sp58 - (func_8001F5B0(4, 0, "ID  00000") / 2)) + 0x3E, sp56 + 0x46, "ID  %05d", arg0->unk_0012);
        func_8001EBE0(4, 0);

        for (i = 0; i < 6; i++) {
            tmp1 = D_823059B0[i] + sp58 + 0x2C;
            tmp2 = D_823059BC[i] + sp56 + 5;
            func_8001F1E8(tmp1, tmp2, arg0->unk_0020[i].unk_30);
        }

        func_8001EBE0(4, 0);

        for (i = 0; i < 6; i++) {
            tmp3 = D_823059B0[i] + sp58 + 0x2C;
            tmp4 = D_823059BC[i] + sp56 + 0x17;
            func_8001F1E8(tmp3, tmp4, "%s%d", func_8002D7C0(NULL, 0, D_82305A24, 0x15), arg0->unk_0020[i].unk_24);
        }

        func_8001F444();
        func_823023F8(arg0, sp58, sp56);
    }
}

void func_82302998(unk_D_82305AF8* arg0) {
    switch (arg0->unk_0000) {
        case 2:
            arg0->unk_0006 -= 1;
            if (arg0->unk_0006 == 0) {
                arg0->unk_0000 = 1;
            }

            if (arg0->unk_0001 == 0) {
                arg0->unk_000C = arg0->unk_0008 - (arg0->unk_0006 << 6);
            } else {
                arg0->unk_000C = arg0->unk_0008 + (arg0->unk_0006 << 6);
            }
            break;

        case 3:
            arg0->unk_0006 += 1;
            if (arg0->unk_0006 == 0xA) {
                arg0->unk_0000 = 0;
            }

            if (arg0->unk_0001 == 0) {
                arg0->unk_000C = arg0->unk_0008 - (arg0->unk_0006 << 6);
            } else {
                arg0->unk_000C = arg0->unk_0008 + (arg0->unk_0006 << 6);
            }
            break;
    }
}

void func_82302A6C(unk_D_82305AF8* arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 i;

    arg0->unk_0000 = 0;
    arg0->unk_0001 = arg3;
    arg0->unk_0006 = 0xA;
    arg0->unk_0008 = arg1;
    arg0->unk_000A = arg2;
    arg0->unk_000C = arg1;
    arg0->unk_000E = arg2;
    arg0->unk_0012 = func_80025084(arg3);
    func_800251B0(arg3, arg0->unk_0014);

    for (i = 0; i < 6; i++) {
        func_80024CB0(0x20, arg3, 0, i, &arg0->unk_0020[i]);
        func_8001B0DC(arg0->unk_0218[i], 0, &arg0->unk_0020[i]);
    }
}

s32 func_82302B78(unk_func_80026268_arg0* arg0) {
    s32 i;
    s32 var_v1 = 1;

    for (i = 0; i < 4; i++) {
        if (arg0->unk_09[i] == 0) {
            break;
        }

        if (arg0->unk_09[i] >= 0xA6) {
            var_v1 = 0;
        }
    }

    return var_v1;
}

u8 func_82302BB4(unk_D_82305AF8* arg0, s16 arg1) {
    unk_D_82305978* ptr1;
    s16 sp54[3];
    unk_func_80026268_arg0* var_s1;
    s16 i;
    s16 j;

    var_s1 = arg0->unk_0020;

    for (i = 0; i < 3; i++) {
        sp54[i] = 999;
    }

    for (i = 0; i < 6; i++, var_s1++) {
        var_s1->unk_25 = 1;
        if ((var_s1->unk_00.unk_00 > 0) && (var_s1->unk_00.unk_00 < 0x98)) {
            if (func_82302B78(var_s1) != 0) {
                ptr1 = &D_8230597C[(arg1 - 1) & 0xFFFFFFFF];

                if (D_8006FF00[var_s1->unk_00.unk_00 - 1].unk_0C & ptr1->unk_06) {
                    if ((var_s1->unk_24 >= ptr1->unk_00) && (ptr1->unk_02 >= var_s1->unk_24)) {
                        var_s1->unk_25 = 0;
                    }
                }

                for (j = 0; j < i; j++) {
                    if (var_s1->unk_00.unk_00 == arg0->unk_0020[j].unk_00.unk_00) {
                        var_s1->unk_25 = 1;
                        arg0->unk_0020[j].unk_25 = 1;
                    }
                }
            }
        }

        if (sp54[2] >= var_s1->unk_24) {
            sp54[2] = var_s1->unk_24;
        }

        if (sp54[1] >= var_s1->unk_24) {
            sp54[2] = sp54[1];
            sp54[1] = var_s1->unk_24;
        }

        if (sp54[0] >= var_s1->unk_24) {
            sp54[1] = sp54[0];
            sp54[0] = var_s1->unk_24;
        }
    }

    for (i = 0, j = 0; i < 6; i++) {
        if (arg0->unk_0020[i].unk_25 == 0) {
            j++;
        }
    }

    arg0->unk_0002 = j == 6;
    if (arg0->unk_0002) {
        arg0->unk_0003 = D_8230597C[arg1 - 1].unk_04 >= (sp54[0] + sp54[1] + sp54[2]);
    } else {
        arg0->unk_0003 = 1;
    }
    return arg0->unk_0002;
}

u8 func_82302E34(unk_D_82305AF8* arg0, s16 arg1) {
    arg0->unk_0004 = arg1;
    arg0->unk_0010 = 0;
    arg0->unk_0000 = 2;
    return func_82302BB4(arg0, arg1);
}

void func_82302E6C(unk_D_82305A30* arg0) {
    s16 temp_s3;
    s16 temp_s2;
    s16 i;
    s16 sp58;

    if (arg0->unk_02 > 0) {
        temp_s2 = arg0->unk_02 / 4;
        temp_s3 = arg0->unk_04;
        sp58 = arg0->unk_06 + ((0x38 - arg0->unk_02) / 2);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        for (i = 0; i < 4; i++) {
            gDPLoadTextureBlock(gDisplayListHead++, &D_302C000[i * 0xAF0], G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 14, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            func_8001C330(temp_s3, sp58 + (i * temp_s2), 0x64, temp_s2, 0, 0, 0x400, 0x3800 / temp_s2, 0);
        }

        if ((arg0->unk_01 == 0) && (arg0->unk_02 == 0x38)) {
            func_8230047C(0x70, sp58 + 8, 0x1A0, 0x28, 0, 0, 0, 0x96);

            gSPDisplayList(gDisplayListHead++, D_8006F630);

            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            func_8001F324(0xFF, 0x50, 0x64, 0xFF);
            func_8001F1E8(0x90, sp58 + 0xE, func_8002D7C0(NULL, 0, D_82305A20, 0xA));
            func_8001F444();
        } else {
            gSPDisplayList(gDisplayListHead++, D_8006F630);
        }
    }
}

void func_823031B0(unk_D_82305A30* arg0) {
    switch (arg0->unk_00) {
        case 1:
            arg0->unk_02 += 7;
            if (arg0->unk_02 == 0x38) {
                if (arg0->unk_01 == 0) {
                    func_80048B90(8);
                }
                arg0->unk_00 = 0;
            }
            break;

        case 2:
            arg0->unk_02 -= 7;
            if (arg0->unk_02 == 0) {
                arg0->unk_00 = 0;
            }
            break;
    }
}

void func_82303248(unk_D_82305A30* arg0, s16 arg1, s16 arg2) {
    arg0->unk_00 = 0;
    arg0->unk_02 = 0;
    arg0->unk_04 = arg1;
    arg0->unk_06 = arg2;
}

void func_82303274(unk_D_82305A30* arg0, s32 arg1) {
    arg0->unk_01 = arg1;
    arg0->unk_00 = 1;
}

void func_82303284(unk_D_8230F528* arg0) {
    UNUSED s32 pad;
    s16 sp3A;
    s16 sp38;
    s16 sp36;

    if (arg0->unk_02 >= 0xA) {
        sp3A = arg0->unk_02;
        sp38 = arg0->unk_04;
        sp36 = arg0->unk_06 + ((0x30 - sp3A) / 2);
        func_82300214(sp38, sp36, 0x98, sp3A);

        gSPDisplayList(gDisplayListHead++, D_8006F470);

        func_8001C560(sp38 + 4, sp36 + 4, 0x90, sp3A - 8, 0x3C, 0x3C, 0xA0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        if (arg0->unk_02 == 0x30) {
            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            func_8001F1E8((sp38 - ((s16)func_8001F5B0(0x10, 0, arg0->unk_08) / 2)) + 0x4C, sp36 + 0xB, arg0->unk_08);
            func_8001F444();
        }
    }
}

void func_8230340C(unk_D_8230F528* arg0) {
    switch (arg0->unk_00) {
        case 1:
            arg0->unk_02 += 6;
            if (arg0->unk_02 == 0x30) {
                arg0->unk_00 = 0;
            }
            break;

        case 2:
            arg0->unk_02 -= 6;
            if (arg0->unk_02 == 6) {
                arg0->unk_00 = 0;
            }
            break;
    }
}

void func_82303478(unk_D_8230F528* arg0, s16 arg1, s16 arg2, s8* arg3) {
    arg0->unk_00 = 0;
    arg0->unk_02 = 6;
    arg0->unk_04 = arg1;
    arg0->unk_06 = arg2;
    arg0->unk_08 = arg3;
}

void func_823034AC(unk_D_82305A40* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    char sp30[64];
    UNUSED s32 pad;

    if (((arg1 == 1) || (arg1 == 2)) && (arg0->unk_01 == 0)) {
        func_8001F324(0x50, 0x50, 0xB4, 0xFF);
    } else if (arg1 == arg0->unk_0C) {
        func_8001F324(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    }

    func_8001F1E8(arg0->unk_08 + 0x34, arg0->unk_0A + arg1 * 0x21 + 0x2F, func_8002D7C0(NULL, 0, D_82305A20, arg2));

    if (arg3 >= 0) {
        func_8002D600(2, arg4);
        func_8002D7C0(sp30, sizeof(sp30), D_82305A20, arg3);
        func_8001F1E8((arg0->unk_08 - (func_8001F5B0(0, 0, sp30) / 2)) + 0x158, arg0->unk_0A + arg1 * 0x21 + 0x2F, sp30,
                      arg4);
    }
}

void func_82303614(s16 arg0, s16 arg1, s16 arg2) {
    if (arg2 != 0) {
        func_8001F324(0x82, 0x1E, 0x1E, 0xFF);
    } else {
        func_8001F324(0x32, 0x32, 0x96, 0xFF);
    }

    func_8001CF10(arg0, arg1, 0x10, 0x1C, D_30242C0, 0x10, 0);
    func_8001CF10(arg0 + 0x68, arg1, 0x10, 0x1C, D_30243A0, 0x10, 0);
    func_8001C330(arg0 + 0x10, arg1, 0x58, 0x1C, 0, 0, 0, 0x400, 0);
}

void func_82303710(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    static s16 D_823059C8 = 0;

    s16 sp36 = SINS(D_823059C8) * 2;

    if (arg2 == 1) {
        if (arg3 >= 6) {
            func_8001C6AC(arg0 - sp36, arg1 + (arg2 * 0x21), 0x14, 0x20, D_302FBC0, 0x14, 0);
        }

        if (arg3 < 0x5A) {
            func_8001C6AC(arg0 + sp36 + 0x94, arg1 + (arg2 * 0x21), 0x14, 0x20, D_30300C0, 0x14, 0);
        }
    } else {
        if (arg3 >= 0xB) {
            func_8001C6AC(arg0 - sp36, arg1 + (arg2 * 0x21), 0x14, 0x20, D_302FBC0, 0x14, 0);
        }

        if (arg3 < 0x5A) {
            func_8001C6AC(arg0 + sp36 + 0x94, arg1 + (arg2 * 0x21), 0x14, 0x20, D_30300C0, 0x14, 0);
        }
    }
    D_823059C8 += 0x2000;
}

void func_8230391C(unk_D_82305A40* arg0) {
    char* sp54;
    s16 var_a3;
    s16 temp_s1;
    s16 temp_s2;
    UNUSED s16 pad;
    s16 sp4A;

    if (arg0->unk_06 >= 0xF) {
        sp4A = arg0->unk_06;
        temp_s2 = arg0->unk_08;
        temp_s1 = arg0->unk_0A + ((0xBA - sp4A) / 2);

        func_80020754(temp_s2, temp_s1, 0x1BE, sp4A);

        if (sp4A == 0xBA) {
            func_8230147C(temp_s2 + 7, temp_s1 + 7, 0x1B0, 0x20, 0x82, 0x1E, 0x1E, 0xFF);
            func_8230147C(temp_s2 + 7, temp_s1 + 0x27, 0x1B0, 0x8C, 0x1E, 0x1E, 0x64, 0xFF);
            func_80020928(temp_s2 + 0xE, temp_s1 + (arg0->unk_0C * 0x21) + 0x31);

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            if (arg0->unk_01 == 1) {
                if (arg0->unk_0C == 1) {
                    func_82303710(temp_s2 + 0x104, temp_s1 + 0x2D, arg0->unk_0C, arg0->unk_02);
                }

                if (arg0->unk_0C == 2) {
                    func_82303710(temp_s2 + 0x104, temp_s1 + 0x2D, arg0->unk_0C, arg0->unk_04);
                }
            }

            func_82303614(temp_s2 + 0x11C, temp_s1 + 0x2E, 1);
            func_82303614(temp_s2 + 0x11C, temp_s1 + 0x4F, arg0->unk_01);
            func_82303614(temp_s2 + 0x11C, temp_s1 + 0x70, arg0->unk_01);

            gSPDisplayList(gDisplayListHead++, D_8006F630);

            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            sp54 = func_8002D7C0(NULL, 0, D_82305A20, 0xB);
            func_8001F1E8((temp_s2 - (func_8001F5B0(0x10, 0, sp54) / 2)) + 0xDF, temp_s1 + 0xA, sp54);

            if (arg0->unk_01 == 1) {
                var_a3 = 0xC;
            } else {
                var_a3 = 0xD;
            }

            func_823034AC(arg0, 0, 0xE, var_a3, 0);
            func_823034AC(arg0, 1, 0x10, 0xF, arg0->unk_02);
            func_823034AC(arg0, 2, 0x11, 0x12, arg0->unk_04);
            func_823034AC(arg0, 3, 0x13, -1, 0);
            func_8001F444();
        } else {
            func_8230147C(temp_s2 + 7, temp_s1 + 7, 0x1B0, sp4A - 0xE, 0x1E, 0x1E, 0x64, 0xFF);
        }
    }
}

void func_82303CA0(unk_D_82305A40* arg0) {
    s32 temp_v0_2;

    switch (arg0->unk_00) {
        case 1:
            temp_v0_2 = func_8001F750();
            if ((temp_v0_2 == 0x200) && (arg0->unk_01 == 1)) {
                if (arg0->unk_0C == 1) {
                    if (arg0->unk_02 >= 6) {
                        arg0->unk_02 -= 5;
                        func_80048B90(1);
                    }
                }

                if (arg0->unk_0C == 2) {
                    if (arg0->unk_04 >= 0xB) {
                        arg0->unk_04 -= 0xA;
                        func_80048B90(1);
                    }
                }
            } else if ((temp_v0_2 == 0x100) && (arg0->unk_01 == 1)) {
                if (arg0->unk_0C == 1) {
                    if (arg0->unk_02 < 0x5A) {
                        arg0->unk_02 += 5;
                        func_80048B90(1);
                    }
                }

                if (arg0->unk_0C == 2) {
                    if (arg0->unk_04 < 0x5A) {
                        arg0->unk_04 += 0xA;
                        func_80048B90(1);
                    }
                }
            } else {
                if (gPlayer1Controller->buttonPressed & 0x800) {
                    if (arg0->unk_0C > 0) {
                        arg0->unk_0C--;
                        func_80048B90(1);
                    }
                } else if (gPlayer1Controller->buttonPressed & 0x400) {
                    if (arg0->unk_0C < 3) {
                        arg0->unk_0C++;
                        func_80048B90(1);
                    }
                } else if (gPlayer1Controller->buttonPressed & 0x8000) {
                    if (arg0->unk_0C == 0) {
                        arg0->unk_01 ^= 1;
                        func_80048B90(2);
                    }

                    if (arg0->unk_0C == 3) {
                        D_80075680[0] = arg0->unk_01;
                        D_80075680[1] = arg0->unk_02;
                        D_80075680[2] = arg0->unk_04;
                        arg0->unk_00 = 3;
                        func_80048B90(0x1D);
                    }
                } else {
                    if (gPlayer1Controller->buttonPressed & 0x4000) {
                        arg0->unk_01 = D_80075680[0];
                        arg0->unk_02 = D_80075680[1];
                        arg0->unk_04 = D_80075680[2];
                        arg0->unk_00 = 3;
                        func_80048B90(3);
                    }
                }
            }
            break;

        case 2:
            arg0->unk_06 += 0x16;
            if (arg0->unk_06 == 0xBA) {
                func_8001F738(gPlayer1Controller);
                arg0->unk_00 = 1;
            }
            break;

        case 3:
            arg0->unk_06 -= 0x16;
            if (arg0->unk_06 == 0xA) {
                arg0->unk_00 = 0;
            }
            break;
    }
}

void func_82303F58(unk_D_82305A40* arg0, s16 arg1, s16 arg2, s32 arg3) {
    arg0->unk_00 = 0;
    arg0->unk_06 = 0xA;
    arg0->unk_08 = arg1;
    arg0->unk_0A = arg2;
    arg0->unk_0C = 0;

    if (arg3 != 0) {
        arg0->unk_01 = D_80075680[0];
        arg0->unk_02 = D_80075680[1];
        arg0->unk_04 = D_80075680[2];
    }
}

void func_82303FB4(unk_D_82305A40* arg0) {
    func_80048B90(4);
    arg0->unk_00 = 2;
    arg0->unk_0C = 0;
}

void func_82303FE8(void) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0,
                      ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 140, 190, 200, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 110, 160, 170, 255);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_302EBC0, G_IM_FMT_I, 128, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 7, 6, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(0, 0, 0x280, 0x1E0, 0, 0, 0x400, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82304224(s16 arg0) {
    s16 i;

    func_800079C4();
    func_82303FE8();
    func_82301A10();
    func_82301B0C(&D_82305A30);
    func_82302E6C(&D_82305A38);
    func_8230391C(&D_82305A40);
    func_823025B8(&D_82305AF8[0]);
    func_823025B8(&D_82305AF8[1]);

    for (i = 0; i < 6; i++) {
        func_82301CC4(&D_82305A50[i]);
    }

    for (i = 0; i < 3; i++) {
        func_82303284(&D_8230F528[i]);
    }

    if (arg0 >= 0) {
        func_82300020(D_82305920[arg0].unk_00, D_82305920[arg0].unk_02, D_82305920[arg0].unk_04,
                      D_82305920[arg0].unk_06);
    }

    func_80007778();
}

void func_82304358(void) {
    s16 i;

    func_800290B4();
    func_82301C30(&D_82305A30);
    func_823031B0(&D_82305A38);
    func_82303CA0(&D_82305A40);
    func_82302998(&D_82305AF8[0]);
    func_82302998(&D_82305AF8[1]);

    for (i = 0; i < 6; i++) {
        func_82301FF0(&D_82305A50[i]);
    }

    for (i = 0; i < 3; i++) {
        func_8230340C(&D_8230F528[i]);
    }
}

void func_8230443C(unk_D_82305A28* arg0) {
    if (arg0->unk_00 == 3) {
        do {
            func_82304358();
            if (gPlayer1Controller->buttonPressed & 0x800) {
                if (arg0->unk_02 >= 2) {
                    arg0->unk_02 -= 2;
                    func_80048B90(1);
                }
            } else if (gPlayer1Controller->buttonPressed & 0x400) {
                if (arg0->unk_02 < 4) {
                    arg0->unk_02 += 2;
                    func_80048B90(1);
                }
            } else if (gPlayer1Controller->buttonPressed & 0x200) {
                if ((arg0->unk_02 & 1) == 1) {
                    arg0->unk_02--;
                    func_80048B90(1);
                }
            } else if (gPlayer1Controller->buttonPressed & 0x100) {
                if (!(arg0->unk_02 & 1)) {
                    arg0->unk_02++;
                    func_80048B90(1);
                }
            } else if (gPlayer1Controller->buttonPressed & 0x8000) {
                switch (arg0->unk_02) {
                    case 4:
                        arg0->unk_00 = 5;
                        func_80048B90(0x1C);
                        break;

                    case 5:
                        arg0->unk_00 = 2;
                        func_80048B90(3);
                        break;

                    default:
                        arg0->unk_00 = 7;
                        func_80048B90(0x1C);
                        break;
                }
            } else if (gPlayer1Controller->buttonPressed & 0x4000) {
                func_80048B90(3);
                arg0->unk_00 = 2;
            }
            func_82304224(arg0->unk_02);
        } while (arg0->unk_00 == 3);
    }
    arg0->unk_06 = 4;
}

void func_823045D8(unk_D_82305A28* arg0) {
    s16 i;
    s16 j;

    func_8000D1F0(0x2D);
    func_80006C6C(8);

    for (i = 0; i < 6; i++) {
        func_82304358();
        func_82304224(-1);
    }

    D_82305A30.unk_00 = 1;
    func_8004DF94(0x01100001, 0, 0);

    for (j = 0; j < 6; j++) {
        D_82305A50[j].unk_00 = 2;
    }

    for (i = 0; i < 12; i++) {
        func_82304358();
        func_82304224(-1);
    }

    arg0->unk_00 = 3;
}

void func_823046C8(unk_D_82305A28* arg0) {
    s16 i;
    s16 j;

    D_82305A30.unk_00 = 2;

    for (i = 0; i < 6; i++) {
        D_82305A50[i].unk_00 = 3;
    }

    for (j = 0; j < 6; j++) {
        func_82304358();
        func_82304224(-1);
    }

    func_8000D278(0x10);
    func_80007990(0xFFFF);
    func_80006CB4(8);

    while (func_80007604() != 1) {
        func_82304358();
        func_82304224(-1);
    }

    arg0->unk_00 = 0;
}

void func_823047B0(unk_D_82305A28* arg0) {
    s16 i;
    s16 j;
    u8 tmp1;

    D_82305A30.unk_00 = 2;

    for (i = 0; i < 6; i++) {
        D_82305A50[i].unk_00 = 3;
    }

    for (j = 0; j < 12; j++) {
        func_82304358();
        func_82304224(-1);
    }

    func_8004DF94(0x01100001, 0, 0);
    arg0->unk_01 = func_82302E34(&D_82305AF8[0], D_82305920[arg0->unk_02].unk_08);
    arg0->unk_01 &= func_82302E34(&D_82305AF8[1], D_82305920[arg0->unk_02].unk_08);
    func_82303274(&D_82305A38, arg0->unk_01);

    tmp1 = !arg0->unk_01;
    arg0->unk_04 = tmp1;

    for (i = tmp1; i < 3; i++) {
        D_8230F528[i].unk_00 = 1;
    }

    for (j = 0; j < 12; j++) {
        func_82304358();
        func_82304224(-1);
    }

    arg0->unk_00 = 4;
}

void func_8230495C(unk_D_82305A28* arg0) {
    u8 temp_v1;
    s16 i;
    s16 j;

    temp_v1 = !arg0->unk_01;
    D_82305AF8[0].unk_0000 = 3;
    D_82305AF8[1].unk_0000 = 3;
    D_82305A38.unk_00 = 2;

    for (i = temp_v1; i < 3; i++) {
        D_8230F528[i].unk_00 = 2;
    }

    for (j = 0; j < 12; j++) {
        func_82304358();
        func_82304224(-1);
    }

    D_82305A30.unk_00 = 1;
    func_8004DF94(0x01100001, 0, 0);

    for (i = 0; i < 6; i++) {
        D_82305A50[i].unk_00 = 2;
    }

    for (j = 0; j < 12; j++) {
        func_82304358();
        func_82304224(-1);
    }

    arg0->unk_00 = 3;
}

void func_82304AB0(unk_D_82305A28* arg0) {
    u8 temp_v1;
    s16 i;
    s16 j;

    func_8004DF94(0x01100001, 0, 0);
    arg0->unk_01 = func_82302E34(&D_82305AF8[0], D_82305920[arg0->unk_02].unk_08);
    arg0->unk_01 &= func_82302E34(&D_82305AF8[1], D_82305920[arg0->unk_02].unk_08);
    func_82303274(&D_82305A38, arg0->unk_01);

    temp_v1 = !arg0->unk_01;
    arg0->unk_04 = temp_v1;

    for (i = temp_v1; i < 3; i++) {
        D_8230F528[i].unk_00 = 1;
    }

    for (j = 0; j < 12; j++) {
        func_82304358();
        func_82304224(-1);
    }

    arg0->unk_00 = 4;
}

void func_82304BEC(unk_func_80026268_arg0* arg0, s16 arg1) {
    unk_D_800AC910_040 sp30;
    unk_D_800AC910_040 sp20;

    if ((func_80024F68(arg1) == 7) && (arg0->unk_00.unk_00 == 0x19)) {
        func_80025040(arg1, &sp20);
        _bcopy(arg0->unk_46, sp30.unk_02, 11);
        sp30.unk_00 = arg0->unk_0E;
        if (func_80022A04(&sp30, &sp20)) {
            arg0->unk_52 |= 0x80;
        }
    }
}

void func_82304C7C(unk_D_82305AF8* arg0) {
    s16 i;
    unk_D_800AE540_0004* temp_s4 = func_8002B700(arg0->unk_0001, arg0->unk_0012, arg0->unk_0014, func_8002311C(1));

    for (i = 0; i < 6; i++) {
        func_82304BEC(&arg0->unk_0020[i], arg0->unk_0001);
        func_8002B888(temp_s4, &arg0->unk_0020[i]);
    }

    func_8002B840(arg0->unk_0001, temp_s4);
}

void func_82304D30(unk_D_82305A28* arg0) {
    s16 i;
    s16 j;

    func_8002B5EC(0xA, D_82305920[arg0->unk_02].unk_08, 0);
    func_82304C7C(&D_82305AF8[0]);
    func_82304C7C(&D_82305AF8[1]);

    if (D_82305A40.unk_01 == 1) {
        D_800AE540.unk_11ED = D_82305A40.unk_01;
        D_800AE540.unk_11EE = D_82305A40.unk_02;
        D_800AE540.unk_11EF = D_82305A40.unk_04;
    }
    D_82305AF8[0].unk_0000 = 3;
    D_82305AF8[1].unk_0000 = 3;
    D_82305A38.unk_00 = 2;

    for (i = 0; i < 3; i++) {
        D_8230F528[i].unk_00 = 2;
    }

    for (j = 0; j < 6; j++) {
        func_82304358();
        func_82304224(-1);
    }

    func_8000D278(0x10);
    func_80007990(0xFFFF);
    func_80006CB4(8);

    while (func_80007604() != 1) {
        func_82304358();
        func_82304224(-1);
    }

    arg0->unk_06 = 0x2A;
    arg0->unk_00 = 0;
}

void func_82304EA0(unk_D_82305A28* arg0) {
    u8 temp_s7;

    temp_s7 = !arg0->unk_01;

    if (arg0->unk_00 == 4) {
        do {
            func_82304358();
            if (gPlayer1Controller->buttonPressed & 0x200) {
                if (temp_s7 < arg0->unk_04) {
                    arg0->unk_04--;
                    func_80048B90(1);
                }
            } else if (gPlayer1Controller->buttonPressed & 0x100) {
                if (arg0->unk_04 < 2) {
                    arg0->unk_04++;
                    func_80048B90(1);
                }
            } else if (gPlayer1Controller->buttonPressed & 0x8000) {
                switch (arg0->unk_04) {
                    case 0:
                        arg0->unk_00 = 6;
                        func_80048B90(0x20);
                        break;

                    case 1:
                        arg0->unk_00 = 9;
                        func_80048B90(0x1C);
                        break;

                    case 2:
                        arg0->unk_00 = 8;
                        func_80048B90(3);
                        break;
                }
            } else if (gPlayer1Controller->buttonPressed & 0x4000) {
                func_80048B90(3);
                arg0->unk_04 = 2;
                arg0->unk_00 = 8;
            }
            func_82304224(arg0->unk_04 + 6);
        } while (arg0->unk_00 == 4);
    }
}

void func_82305038(unk_D_82305A28* arg0) {
    s16 i;
    s16 j;

    D_82305A30.unk_00 = 2;

    for (i = 0; i < 6; i++) {
        D_82305A50[i].unk_00 = 3;
    }

    for (j = 0; j < 12; j++) {
        func_82304358();
        func_82304224(-1);
    }

    func_82303FB4(&D_82305A40);

    while (D_82305A40.unk_00 != 0) {
        func_82304358();
        func_82304224(-1);
    }

    D_82305A30.unk_00 = 1;
    func_8004DF94(0x01100001, 0, 0);

    for (i = 0; i < 6; i++) {
        D_82305A50[i].unk_00 = 2;
    }

    for (j = 0; j < 12; j++) {
        func_82304358();
        func_82304224(-1);
    }

    arg0->unk_00 = 3;
}

void func_8230519C(unk_D_82305A28* arg0) {
    s16 i;
    s16 j;

    func_8002B5EC(0xA, D_82305920[arg0->unk_02].unk_08, 0);

    D_82305AF8[0].unk_0000 = 3;
    D_82305AF8[1].unk_0000 = 3;
    D_82305A38.unk_00 = 2;

    for (i = 0; i < 3; i++) {
        D_8230F528[i].unk_00 = 2;
    }

    for (j = 0; j < 12; j++) {
        func_82304358();
        func_82304224(-1);
    }

    arg0->unk_06 = 0x12;
    arg0->unk_00 = 0;
}

void func_8230527C(unk_D_82305A28* arg0) {
    while (arg0->unk_00 != 0) {
        switch (arg0->unk_00) {
            case 1:
                func_823045D8(arg0);
                break;

            case 2:
                func_823046C8(arg0);
                break;

            case 3:
                func_8230443C(arg0);
                break;

            case 4:
                func_82304EA0(arg0);
                break;

            case 7:
                func_823047B0(arg0);
                break;

            case 8:
                func_8230495C(arg0);
                break;

            case 6:
                func_82304D30(arg0);
                break;

            case 5:
                func_82305038(arg0);
                break;

            case 9:
                func_8230519C(arg0);
                break;

            case 10:
                func_82304AB0(arg0);
                break;
        }
    }
}

void func_82305370(unk_D_82305A28* arg0, s16 arg1) {
    s16 i;

    if (arg1 == -1) {
        arg0->unk_00 = 1;
        arg0->unk_02 = 2;
    } else {
        arg0->unk_00 = 0xA;
        arg0->unk_02 = arg1;
    }
    arg0->unk_06 = 0x12;

    func_82301C98(&D_82305A30, 0x38, 0x17C);
    func_82303248(&D_82305A38, 0x10E, 0xC0);
    func_82303F58(&D_82305A40, 0x68, 0x93, (arg1 + 1) == 0);

    func_82302A6C(&D_82305AF8[0], 0x40, 0x5C, 0);
    func_82302A6C(&D_82305AF8[1], 0x40, 0xF8, 1);

    func_823020B4(&D_82305A50[0], 0x44, 0x84, D_3028E00, func_8002D7C0(NULL, 0, D_82305A20, 0x15), 3, 0);
    func_823020B4(&D_82305A50[1], 0x144, 0x84, D_3029A80, func_8002D7C0(NULL, 0, D_82305A20, 0x18), 4, 1);
    func_823020B4(&D_82305A50[2], 0x44, 0xC8, D_302A700, func_8002D7C0(NULL, 0, D_82305A20, 0x1A), 6, 5);
    func_823020B4(&D_82305A50[3], 0x144, 0xC8, D_302B380, func_8002D7C0(NULL, 0, D_82305A20, 0x19), 5, 3);
    func_823020B4(&D_82305A50[4], 0x44, 0x10C, NULL, func_8002D7C0(NULL, 0, D_82305A20, 0x1B), 0, 6);
    func_823020B4(&D_82305A50[5], 0x144, 0x10C, NULL, func_8002D7C0(NULL, 0, D_82305A20, 0x1C), 0, 7);

    func_82303478(&D_8230F528[0], 0x50, 0x181, func_8002D7C0(NULL, 0, D_82305A20, 0x1D));
    func_82303478(&D_8230F528[1], 0xF4, 0x181, func_8002D7C0(NULL, 0, D_82305A20, 0x1E));
    func_82303478(&D_8230F528[2], 0x198, 0x181, func_8002D7C0(NULL, 0, D_82305A20, 0x1F));

    if (arg1 == -1) {
        for (i = 2; i >= 0; i--) {
            if (D_82305A50[i].unk_01 != 0) {
                arg0->unk_02 = i;
            }
        }
    }
}

s16 func_823056C4(void) {
    static s16 D_823059CC = -1;

    main_pool_push_state('EVSL');

    func_8001E94C(0x1C, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    ASSET_LOAD(D_3000000, menu_select_ui, 0);

    func_8001B058();
    func_80023AF8(0);
    func_80023AF8(1);
    func_80007754();
    func_82305370(&D_82305A28, D_823059CC);
    func_8230527C(&D_82305A28);
    D_823059CC = D_82305A28.unk_02;
    func_8000771C();
    func_80005EAC();

    main_pool_pop_state('EVSL');

    return D_82305A28.unk_06;
}

s32 func_823057E4(UNUSED s32 arg0, UNUSED s32 arg1) {
    s16 temp_v0 = STATE_EVENT_BATTLE;

    main_pool_push_state('EBTL');

    func_80005E40(0x10000, 0);
    func_80007678(func_80007444(1, 0, 2, 0, 2, 1));
    func_8002D510();
    D_82305A20 = func_8002D5AC(0x10);
    D_82305A24 = func_8002D5AC(6);

    while (temp_v0 == STATE_EVENT_BATTLE) {
        temp_v0 = func_823056C4();
        if (temp_v0 == STATE_EVENT_BATTLE) {
            FRAGMENT_LOAD_AND_CALL(fragment55, 0, 0);
        }
    }

    func_800076C0();
    func_80005EAC();

    main_pool_pop_state('EBTL');

    return temp_v0;
}
