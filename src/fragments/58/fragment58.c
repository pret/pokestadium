#include "fragment58.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/232C0.h"
#include "src/29BA0.h"
#include "src/2C1C0.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/DDC0.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_84002D18 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unk_D_84002D18; // size = 0x4

typedef struct unk_D_84002D28 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
} unk_D_84002D28; // size >= 0xA

typedef struct unk_D_84002BE8 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8* unk_08;
    /* 0x0C */ u8* unk_0C;
} unk_D_84002BE8; // size = 0x10

static char** D_84002D00;
static char** D_84002D04;
static BinArchive* D_84002D08;
static u8* D_84002D0C;
static s32 pad_D_84002D10;
static s16 D_84002D14;
static s16 D_84002D16;
static unk_D_84002D18 D_84002D18;
static s32 pad_D_84002D1C;
static s16 D_84002D20;
static unk_D_84002D28 D_84002D28;

static s16 D_84002BE0 = 2;
static s16 D_84002BE4 = 0;
static unk_D_84002BE8 D_84002BE8[11] = {
    {
        1,
        0,
        48,
        6,
        0x03008FD0,
        NULL,
    },
    {
        3,
        0,
        48,
        36,
        0x03008FD0,
        0x03009720,
    },
    {
        5,
        0,
        48,
        66,
        0x03008FD0,
        0x03009E70,
    },
    {
        9,
        0,
        48,
        96,
        0x03008FD0,
        0x0300A5C0,
    },
    {
        2,
        15,
        280,
        6,
        0x03009720,
        NULL,
    },
    {
        4,
        15,
        280,
        36,
        0x03009E70,
        NULL,
    },
    {
        8,
        15,
        280,
        66,
        0x0300A5C0,
        NULL,
    },
    {
        0,
        15,
        280,
        96,
        0x03008880,
        NULL,
    },
    {
        6,
        15,
        336,
        6,
        0x03009720,
        0x03009E70,
    },
    {
        10,
        15,
        336,
        36,
        0x03009720,
        0x0300A5C0,
    },
    {
        12,
        15,
        336,
        66,
        0x03009E70,
        0x0300A5C0,
    },
};
static s16 D_84002C98[] = { 0, 3, 4, 5, 6, 0 };

void func_84000020(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg0, arg1, 0x30, 0x18, D_2006C00, 0x30, 0);
    func_8001C6AC(arg0, arg1 + 0x18, 0x30, 0x18, D_2007500, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_840000F4(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg0, arg1, 0x64, 0x14, D_200B3E0, 0x64, 0);
    func_8001C6AC(arg0, arg1 + 0x14, 0x64, 0x14, D_200C380, 0x64, 0);
    func_8001C6AC(arg0, arg1 + 0x28, 0x64, 0x10, D_200D320, 0x64, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84000200(s16 arg0, s16 arg1, s16 arg2, Color_RGBA8* arg3, Color_RGBA8* arg4) {
    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, arg3->r, arg3->g, arg3->b, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, arg4->r, arg4->g, arg4->b, 255);

    func_8001CADC(arg0, arg1, 0x10, 0x20, D_20003C0, 0x10, 0);
    func_8001CADC((arg0 + arg2) - 0x10, arg1, 0x10, 0x20, D_20005C0, 0x10, 0);
    func_8001C330(arg0 + 0x10, arg1, arg2 - 0x20, 0x20, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_840003A8(void) {
    Color_RGBA8 sp2C;
    Color_RGBA8 sp28;

    func_8000E820(&sp2C, 0x64, 0x64, 0xC8);
    func_8000E820(&sp28, 0x28, 0x28, 0x8C);
    func_84000200(0x48, 0x28, 0x208, &sp2C, &sp28);
    func_84000020(0x30, 0x20);
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F324(0, 0, 0, 0xFF);
    func_8001F1E8(0x6A, 0x2C, func_8002D7C0(NULL, 0, D_84002D00, 0));
    func_8001F324(0xFF, 0xFF, 0x77, 0xFF);
    func_8001F1E8(0x68, 0x2A, func_8002D7C0(NULL, 0, D_84002D00, 0));
    func_8001F444();
}

void func_840004A4(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    static s16 D_84002CA4 = 0;

    s16 sp56 = SINS(D_84002CA4) * 2;
    UNUSED s32 pad[2];

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 240, 212, 104, 255);

    func_8001CADC(arg0 + sp56, arg1 + sp56, 0x10, 0x10, D_2000C80, 0x10, 0);
    func_8001CADC(arg0 + sp56, ((arg1 + arg3) - sp56) - 0x10, 0x10, 0x10, D_2000F80, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - sp56) - 0x10, arg1 + sp56, 0x10, 0x10, D_2000D80, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - sp56) - 0x10, ((arg1 + arg3) - sp56) - 0x10, 0x10, 0x10, D_2000E80, 0x10, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_84002CA4 += 0x2000;
}

void func_84000698(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001CADC(arg0 - 3, arg1 - 3, 8, 8, D_2000340, 8, 0);
    func_8001CADC((arg0 + arg2) - 5, arg1 - 3, 8, 8, D_2000380, 8, 0);
    func_8001C330(arg0 + 4, arg1 - 3, arg2 - 8, 8, 0, 0, 0, 0x400, 0);
    func_8001CADC(arg0 - 3, (arg1 + arg3) - 5, 8, 8, D_20002C0, 8, 0);
    func_8001C330(arg0 - 3, arg1 + 4, 8, arg3 - 8, 0, 0, 0x400, 0, 0);
    func_8001CADC((arg0 + arg2) - 5, (arg1 + arg3) - 5, 8, 8, D_2000300, 8, 0);
    func_8001C330(arg0 + 4, (arg1 + arg3) - 5, arg2 - 8, 8, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 5, arg1 + 4, 8, arg3 - 8, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    func_8001C560(arg0 + 4, arg1 + 4, arg2 - 8, arg3 - 8, 0x3C, 0x3C, 0xA0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_8400094C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

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

s32 func_8400114C(s16 arg0) {
    unk_D_84002BE8* ptr = &D_84002BE8[arg0];
    s16 t = ptr->unk_00;
    s32 var_v1 = 0;

    if (arg0 < 4) {
        if (D_84002D16 >= 2) {
            var_v1 = arg0 == D_84002D18.unk_00;
        } else {
            var_v1 = ptr->unk_00 == (ptr->unk_00 & D_84002D14);
        }
    } else if (arg0 < 11) {
        if (D_84002D16 >= 3) {
            var_v1 = arg0 == (D_84002D18.unk_02 + 4);
        } else {
            s16 tmp = (~D_84002BE8[D_84002D18.unk_00].unk_00 & D_84002D14);

            var_v1 = ptr->unk_00 == (ptr->unk_00 & tmp);
        }
    }
    return var_v1;
}

void func_84001238(s16 arg0, s16 arg1, s16 arg2) {
    if (func_8400114C(arg2) != 0) {
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    } else {
        func_8001F324(0x64, 0x64, 0x64, 0x82);
    }
    func_8001F2E4(arg0, arg1, 0x26);
}

void func_840012B4(void) {
    s32 i;
    s16 temp_s2;
    s16 temp_s3;
    s32 var_t1;
    unk_D_84002BE8* ptr;
    s16 tmp1;
    s16 tmp2;

    func_8400094C(0x64, 0x72, 0x1B0, 0x80, 0, 0, 0, 0xFF);
    func_840000F4(0x10A, 0x96);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 11; i++) {
        temp_s2 = D_84002BE8[i].unk_04 + 0x64;
        temp_s3 = D_84002BE8[i].unk_06 + 0x72;

        if (func_8400114C(i) != 0) {
            var_t1 = 0xFF;
        } else {
            var_t1 = 0x82;
        }

        gDPSetEnvColor(gDisplayListHead++, var_t1, var_t1, var_t1, var_t1);

        func_8001C6AC(temp_s2, temp_s3, 0x24, 0x1A, D_84002BE8[i].unk_08, 0x24, 0);
        if (D_84002BE8[i].unk_0C != NULL) {
            func_8001C6AC(temp_s2 + 0x30, temp_s3, 0x24, 0x1A, D_84002BE8[i].unk_0C, 0x24, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(0x10, 0);

    for (i = 0; i < 11; i++) {
        if (D_84002BE8[i].unk_0C != NULL) {
            func_84001238(D_84002BE8[i].unk_04 + 0x87, D_84002BE8[i].unk_06 + 0x73, i);
        }
    }

    func_8001EBE0(0x10, 0);

    if ((D_84002D16 == 1) || (D_84002D16 == 2)) {
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    } else {
        func_8001F324(0x78, 0x78, 0xC8, 0xFF);
    }

    func_8001F1E8(0x64, 0x5A, func_8002D7C0(NULL, 0, D_84002D00, 1));
    func_8001F444();

    if (D_84002D16 == 1) {
        ptr = &D_84002BE8[D_84002D18.unk_00];
        tmp1 = ptr->unk_04 + 0x64;
        tmp2 = ptr->unk_06 + 0x72;
        func_840004A4(tmp1 - 4, tmp2 - 2, ((ptr->unk_0C == NULL) ? 0x24 : 0x54) + 8, 0x1E);
    } else if (D_84002D16 == 2) {
        ptr = &D_84002BE8[D_84002D18.unk_02];
        tmp1 = ptr[4].unk_04 + 0x64;
        tmp2 = ptr[4].unk_06 + 0x72;
        func_840004A4(tmp1 - 4, tmp2 - 2, ((ptr[4].unk_0C == NULL) ? 0x24 : 0x54) + 8, 0x1E);
    }
}

void func_84001654(void) {
    s32 sp24 = D_84002D18.unk_00;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        func_80048B90(2);
        D_84002D18.unk_02 = 0;
        while (func_8400114C(D_84002D18.unk_02 + 4) == 0) {
            D_84002D18.unk_02++;
        }
        D_84002D16 = 2;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        func_80048B90(3);
        D_84002D16 = 8;
    } else {
        do {
            if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
                D_84002D18.unk_00 = (D_84002D18.unk_00 + 3) % 4;
            } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
                D_84002D18.unk_00 = (D_84002D18.unk_00 + 1) % 4;
            }
        } while (func_8400114C(D_84002D18.unk_00) == 0);

        if (sp24 != D_84002D18.unk_00) {
            func_80048B90(1);
        }
    }
}

void func_840017AC(void) {
    s32 sp34 = D_84002D18.unk_02;
    s32 i;
    s32 var_a0;
    s32 var_s1;
    s32 var_s4;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        func_80048B90(2);
        if (D_84002D18.unk_02 == 3) {
            D_84002D16 = 5;
        } else {
            D_84002D20 = 0;
            D_84002D16 = 3;
        }
        return;
    }

    var_s4 = 0;
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        func_80048B90(3);
        D_84002D18.unk_02 = -1;
        D_84002D16 = 1;
        return;
    }

    var_a0 = D_84002D18.unk_02 / 4;
    var_s1 = D_84002D18.unk_02 % 4;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT) && (var_a0 == 1)) {
        var_a0 = 0;
        var_s4 = 1;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT) && (var_a0 == 0)) {
        var_a0 = 1;
        var_s4 = 1;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        var_s1 = (var_s1 + 3) % 4;
        var_s4 = -1;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        var_s1 = (var_s1 + 1) % 4;
        var_s4 = 1;
    }

    if (var_s4 != 0) {
        for (i = 0; i < 4; i++) {
            if (func_8400114C(var_a0 * 4 + var_s1 + 4) != 0) {
                break;
            }
            var_s1 = (var_s1 + var_s4 + 4) % 4;
        }

        if (i != 4) {
            D_84002D18.unk_02 = var_a0 * 4 + var_s1;
        }
    }

    if (sp34 != D_84002D18.unk_02) {
        func_80048B90(1);
    }
}

void func_840019A4(void) {
    D_84002D18.unk_00 = -1;
    D_84002D18.unk_02 = -1;
}

s32 func_840019BC(void) {
    s32 var_v1 = 0;

    if ((D_84002D18.unk_00 != -1) && (D_84002BE8[D_84002D18.unk_00].unk_0C != 0)) {
        var_v1 = 1;
    }

    if ((D_84002D18.unk_02 != -1) && (D_84002BE8[D_84002D18.unk_02 + 4].unk_0C != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_84001A1C(s16 arg0, s16 arg1, s16 arg2, char* arg3) {
    if ((arg2 != 0) && (func_840019BC() != 0)) {
        func_8001F324(0x3C, 0x3C, 0x3C, 0xFF);
    } else if (arg2 == D_84002D20) {
        func_8001F324(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_8001F1E8(arg0, arg1 + (arg2 * 0x18), arg3);
}

void func_84001AD8(void) {
}

void func_84001AE0(void) {
    UNUSED s32 pad;
    char sp2C[128];

    func_8400094C(0x64, 0x10C, 0x1B0, 0x84, 0, 0, 0, 0xFF);
    func_8001F3F4();
    func_8001EBE0(8, 0);
    func_84001A1C(0x94, 0x114, 0, func_8002D7C0(NULL, 0, D_84002D00, 2));
    func_84001A1C(0x94, 0x114, 1, func_8002D7C0(NULL, 0, D_84002D00, 3));
    func_84001A1C(0x94, 0x114, 2, func_8002D7C0(NULL, 0, D_84002D00, 6));
    func_84001A1C(0x94, 0x114, 3, func_8002D7C0(NULL, 0, D_84002D00, 7));
    func_84001A1C(0x94, 0x114, 4, func_8002D7C0(NULL, 0, D_84002D00, 8));
    func_8001EBE0(4, 0);

    sprintf(sp2C, "%s1~100", func_8002D7C0(NULL, 0, D_84002D04, 0x15));
    func_84001A1C(0x1AE, 0x118, 0, sp2C);
    sprintf(sp2C, "%s50~55", func_8002D7C0(NULL, 0, D_84002D04, 0x15));
    func_84001A1C(0x1AE, 0x118, 1, sp2C);
    sprintf(sp2C, "%s25~30", func_8002D7C0(NULL, 0, D_84002D04, 0x15));
    func_84001A1C(0x1AE, 0x118, 2, sp2C);
    sprintf(sp2C, "%s15~20", func_8002D7C0(NULL, 0, D_84002D04, 0x15));
    func_84001A1C(0x1AE, 0x118, 3, sp2C);
    sprintf(sp2C, "%s1~100", func_8002D7C0(NULL, 0, D_84002D04, 0x15));
    func_84001A1C(0x1AE, 0x118, 4, sp2C);

    func_8001EBE0(0x10, 0);

    if (D_84002D16 == 3) {
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    } else {
        func_8001F324(0x78, 0x78, 0xC8, 0xFF);
    }

    func_8001F1E8(0x64, 0xF4, func_8002D7C0(NULL, 0, D_84002D00, 9));
    func_8001F444();

    if (D_84002D16 == 3) {
        func_80020928(0x6C, (D_84002D20 * 0x18) + 0x114);
    }
}

void func_84001E18(void) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        func_80048B90(0x26);
        D_84002D16 = 7;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        func_80048B90(3);
        D_84002D20 = -1;
        D_84002D16 = 2;
    } else if (func_840019BC() == 0) {
        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
            func_80048B90(1);
            D_84002D20 = (D_84002D20 + 4) % 5;
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
            func_80048B90(1);
            D_84002D20 = (D_84002D20 + 1) % 5;
        }
    }
}

void func_84001F1C(void) {
    D_84002D20 = -1;
}

void func_84001F2C(s16 arg0, char* arg1) {
    if (arg0 == D_84002D28.unk_08) {
        func_8001F324(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_8001F1E8(D_84002D28.unk_00 + 0x34, D_84002D28.unk_02 + (arg0 * 0x1C) + 0x2B, arg1);
}

void func_84001FC0(void) {
    if (D_84002D28.unk_04 > 0) {
        s16 tmp = D_84002D28.unk_04 * 0x11;

        func_80020460(D_84002D28.unk_00, D_84002D28.unk_02 + (s16)((0x88 - tmp) / 2), 0x98, tmp, 0x2121);
        if (D_84002D28.unk_04 == 8) {
            gSPDisplayList(gDisplayListHead++, D_8006F518);

            func_8001C6AC(D_84002D28.unk_00 + 0xC, D_84002D28.unk_02 + 0xA, 0x24, 0x1A, D_3008880, 0x24, 0);

            gSPDisplayList(gDisplayListHead++, D_8006F630);

            func_80020928(D_84002D28.unk_00 + 0xC, D_84002D28.unk_02 + (D_84002D28.unk_08 * 0x1C) + 0x2B);
            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            func_8001F1E8(D_84002D28.unk_00 + 0x30, D_84002D28.unk_02 + 0xB, func_8002D7C0(NULL, 0, D_84002D00, 0xA));
            func_84001F2C(0, func_8002D7C0(NULL, 0, D_84002D00, 0xB));
            func_84001F2C(1, func_8002D7C0(NULL, 0, D_84002D00, 0xC));
            func_84001F2C(2, func_8002D7C0(NULL, 0, D_84002D00, 0xD));
            func_8001F444();
        }
    }
}

void func_840021CC(void) {
    D_84002D28.unk_00 = 0x190;
    D_84002D28.unk_02 = 0x64;
    D_84002D28.unk_04 = 0;
    D_84002D28.unk_08 = 1;
}

void func_840021F4(void) {
    D_84002BE0 = 2;
    D_84002D28.unk_04++;
    if (D_84002D28.unk_04 == 8) {
        D_84002D16 = 4;
    }
}

void func_84002234(void) {
    D_84002BE0 = 2;
    D_84002D28.unk_04--;
    if (D_84002D28.unk_04 == 0) {
        D_84002D16 = D_84002D28.unk_06;
    }
}

void func_84002274(void) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        D_84002BE4 = D_84002D28.unk_08;
        D_84002D28.unk_06 = 3;
        D_84002D20 = 0;
        D_84002D16 = 6;
        func_80048B90(2);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        D_84002D28.unk_06 = 2;
        D_84002D16 = 6;
        func_80048B90(3);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        func_80048B90(1);
        D_84002D28.unk_08 = (D_84002D28.unk_08 + 2) % 3;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        func_80048B90(1);
        D_84002D28.unk_08 = (D_84002D28.unk_08 + 1) % 3;
    }
}

void func_84002388(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_840023B8(void) {
    func_800079C4();
    if (D_84002BE0 > 0) {
        func_84000698(0x4C, 0x54, 0x1E8, 0x150);
        D_84002BE0 -= 1;
    }
    func_840012B4();
    func_84001AE0();
    func_84001FC0();
    func_80007778();
}

void func_84002430(void) {
    s32 i;

    if (func_80007604() == 1) {
        func_80006C6C(8);

        for (i = 0; i < 10; i++) {
            func_800290B4();
            func_800079C4();
            func_8001D924(D_84002D0C);
            func_80007778();
        }
    }
}

void func_840024B0(void) {
    func_8000D278(0x10);
    func_80007990(0xFFFF);
    func_80006CB4(8);

    while (func_80007604() != 1) {
        func_800290B4();
        func_800079C4();
        func_8001D924(D_84002D0C);
        func_80007778();
    }

    func_800077B4(2);
}

void func_8400253C(void) {
    s32 i;
    s16 tmp;

    func_80048B90(4);

    for (i = 0x10; i < 0x170; i += 0x20) {
        func_84002388();
        func_800079C4();
        func_8001D924(D_84002D0C);
        func_840003A8();
        tmp = i;
        tmp = (0x150 - tmp) / 2;
        func_84000698(0x4C, tmp + 0x54, 0x1E8, i);
        func_80007778();
    }
}

void func_840025FC(void) {
    s32 i;

    for (i = 9; i >= 0; i--) {
        func_84002388();
        func_800079C4();
        func_8001D924(D_84002D0C);
        func_840003A8();
        func_84000698(0x4C, (s16)((0x16C - (s16)(0xE + i * 0x23)) / 2) + 0x54, 0x1E8, 0xE + i * 0x23);
        func_80007778();
    }

    for (i = 0; i < 2; i++) {
        func_800079C4();
        func_8001D924(D_84002D0C);
        func_80007778();
    }
}

void func_840026D8(void) {
    char sp44[12];
    unk_D_800AE540_0004* temp_v0;
    s32 i;

    func_8002B5EC(0, D_84002C98[D_84002D20], 0);

    for (i = 0; i < 4; i++) {
        if (D_84002BE8[D_84002D18.unk_00].unk_00 & (1 << i)) {
            sprintf(sp44, "%dP", i + 1);
            func_8002B840(0, func_8002B700(i, 0, sp44, func_8002311C(1)));
        }
    }

    if (D_84002D18.unk_02 == 3) {
        D_800AE540.unk_11EC = D_84002BE4;
        temp_v0 = func_8002B700(-1, 0, "COM", func_8002311C(3));
        func_8002B840(1, temp_v0);
        if (D_84002D18.unk_00 == 3) {
            temp_v0->unk_001 = 2;
        } else {
            temp_v0->unk_001 = 3;
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (D_84002BE8[D_84002D18.unk_02 + 4].unk_00 & (1 << i)) {
                sprintf(sp44, "%dP", i + 1);
                func_8002B840(1, func_8002B700(i, 0, sp44, func_8002311C(1)));
            }
        }
    }

    if (D_800AE540.unk_1194[0].unk_01 == 2) {
        D_800AE540.unk_1194[0].unk_08[0]->unk_214->unk_003 = 0x35;
        D_800AE540.unk_1194[0].unk_08[1]->unk_214->unk_003 = 0x35;
    }

    if (D_800AE540.unk_1194[1].unk_01 == 2) {
        D_800AE540.unk_1194[1].unk_08[0]->unk_214->unk_003 = 0x35;
        D_800AE540.unk_1194[1].unk_08[1]->unk_214->unk_003 = 0x35;
    }
}

s32 func_84002914(void) {
    D_84002D16 = 0;
    func_8000D1F0(0x2D);
    func_840019A4();
    func_84001F1C();
    func_840021CC();
    func_84002430();
    func_8400253C();
    D_84002D16 = 1;
    D_84002D18.unk_00 = 0;

    while ((D_84002D16 != 7) && (D_84002D16 != 8)) {
        func_84002388();
        switch (D_84002D16) {
            case 1:
                func_84001654();
                break;
            case 2:
                func_840017AC();
                break;
            case 3:
                func_84001E18();
                break;
            case 4:
                func_84002274();
                break;
            case 5:
                func_840021F4();
                break;
            case 6:
                func_84002234();
                break;
        }
        func_840023B8();
    }

    if (D_84002D16 == 8) {
        func_840025FC();
        func_840024B0();
        return 0;
    }

    func_840026D8();
    func_840025FC();
    return 1;
}

s32 func_84002A84(s32 arg0, s32 arg1) {
    s32 sp1C;

    main_pool_push_state('RULE');

    func_8001E94C(0x1C, 0);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    ASSET_LOAD(D_3000000, order_select_ui, 0);
    func_8002D510();
    D_84002D00 = func_8002D5AC(0xF);
    D_84002D04 = func_8002D5AC(6);
    D_84002D08 = ASSET_LOAD2(backgrounds, 1, 1);
    D_84002D0C = func_8000484C(D_84002D08, 6);
    D_84002D14 = Cont_GetControllerBits();
    func_80007754();
    sp1C = func_84002914();
    func_8000771C();

    main_pool_pop_state('RULE');
    return sp1C;
}
