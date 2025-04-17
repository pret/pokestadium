#include "fragment56.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/2E110.h"
#include "src/3D140.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/4BA90.h"
#include "src/6A40.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static char** D_82C01660;
static s16 D_82C01664;
static u16 D_82C01666;

void func_82C00020(void) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0,
                      ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 50, 150, 80, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 20, 100, 50, 255);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_300F780, G_IM_FMT_I, 128, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 7, 6, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(0, 0, 0x280, 0x1E0, 0, 0, 0x400, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82C0025C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
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

void func_82C00574(s16 arg0, s16 arg1) {
    gDPSetEnvColor(gDisplayListHead++, 60, 60, 160, 255);

    func_8001CF10(arg0, arg1, 0x10, 0x1C, D_30242C0, 0x10, 0);
    func_8001CF10(arg0 + 0x68, arg1, 0x10, 0x1C, D_30243A0, 0x10, 0);
    func_8001C330(arg0 + 0x10, arg1, 0x58, 0x1C, 0, 0, 0, 0x400, 0);
}

void func_82C00658(s16 arg0, s32 arg1) {
    UNUSED s32 pad;
    s32 var_a2;
    s16 sp30 = (arg0 * 0x16) + 0xA;
    s16 sp2C = ((0xBA - sp30) / 2) + 0xE5;

    if (arg0 > 0) {
        func_80020754(0x89, sp2C, 0x16E, sp30);

        if (arg0 == 8) {
            char* sp40;

            func_82C0025C(0x90, sp2C + 7, 0x160, 0x20, 0x3C, 0x3C, 0xA0, 0xFF);
            func_82C0025C(0x90, sp2C + 0x27, 0x160, 0x8C, 0x1E, 0x1E, 0x64, 0xFF);

            if (arg1 != 0) {
                func_80020928(0x95, sp2C + (D_82C01664 * 0x20) + 0x31);
            }

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            func_82C00574(0x168, sp2C + 0x30);
            func_82C00574(0x168, sp2C + 0x50);

            gSPDisplayList(gDisplayListHead++, D_8006F630);

            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            sp40 = func_8002D7C0(NULL, 0, D_82C01660, 4);
            func_8001F1E8(0x140 - (func_8001F5B0(0x10, 0, sp40) / 2), sp2C + 0xA, sp40);

            if (D_82C01664 == 0) {
                var_a2 = 0;
            } else {
                var_a2 = 0xFF;
            }

            func_8001F324(0xFF, 0xFF, var_a2, 0xFF);
            func_8001F1E8(0xBB, sp2C + 0x31, func_8002D7C0(NULL, 0, D_82C01660, 5));
            sp40 = func_8002D7C0(NULL, 0, D_82C01660, (D_82C01666 & 1) != 0);
            func_8001F1E8(0x1A4 - (func_8001F5B0(0x10, 0, sp40) / 2), sp2C + 0x31, sp40);

            if (D_82C01664 == 1) {
                var_a2 = 0;
            } else {
                var_a2 = 0xFF;
            }

            func_8001F324(0xFF, 0xFF, var_a2, 0xFF);
            func_8001F1E8(0xBB, sp2C + 0x51, func_8002D7C0(NULL, 0, D_82C01660, 6));
            sp40 = func_8002D7C0(NULL, 0, D_82C01660, ((D_82C01666 & 2) != 0) + 2);
            func_8001F1E8(0x1A4 - (func_8001F5B0(0x10, 0, sp40) / 2), sp2C + 0x51, sp40);

            if (D_82C01664 == 2) {
                var_a2 = 0;
            } else {
                var_a2 = 0xFF;
            }

            func_8001F324(0xFF, 0xFF, var_a2, 0xFF);
            func_8001F1E8(0xBB, sp2C + 0x71, func_8002D7C0(NULL, 0, D_82C01660, 7));

            if (D_82C01664 == 3) {
                var_a2 = 0;
            } else {
                var_a2 = 0xFF;
            }

            func_8001F324(0xFF, 0xFF, var_a2, 0xFF);
            func_8001F1E8(0xBB, sp2C + 0x91, func_8002D7C0(NULL, 0, D_82C01660, 8));
            func_8001F444();
        }
    }
}

void func_82C00AA4(s32 arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad;
    s16 sp28 = (arg2 * 0x11) + 2;
    s16 sp24 = ((0x8A - sp28) / 2) + 0x54;

    if (arg2 > 0) {
        func_80020460(0x51, sp24, 0x1DE, sp28, 0x6109);

        if (arg2 == 8) {
            func_80020928(0x119, sp24 + (arg1 * 0x1C) + 0x48);
            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            func_8001F324(0xFF, 0xFF, 0x64, 0xFF);

            if (arg0 == 0) {
                func_8001F3B4(0x1C);
                func_8001F1E8(0x63, sp24 + 0xC, func_8002D7C0(NULL, 0, D_82C01660, 9));
            } else {
                func_8001F3B4(0x1C);
                func_8001F1E8(0x63, sp24 + 0xC, func_8002D7C0(NULL, 0, D_82C01660, 0xA));
            }

            func_8001F324(0xFF, 0xFF, (arg1 == 0) ? 0 : 0xFF, 0xFF);
            func_8001F1E8(0x141, sp24 + 0x48, func_8002D7C0(NULL, 0, D_82C01660, 0xB));
            func_8001F324(0xFF, 0xFF, (arg1 == 1) ? 0 : 0xFF, 0xFF);
            func_8001F1E8(0x141, sp24 + 0x64, func_8002D7C0(NULL, 0, D_82C01660, 0xC));
            func_8001F444();
        }
    }
}

void func_82C00CB4(s32 arg0) {
    UNUSED s32 pad;
    s16 sp28 = arg0 * 9;
    s16 sp24 = ((0x38 - sp28) / 2) + 0x82;

    if (arg0 >= 2) {
        func_80020460(0x87, sp24, 0x172, sp28, 0x6109);
        if (arg0 == 8) {
            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            func_8001F324(0xFF, 0xFF, 0x64, 0xFF);
            func_8001F1E8(0x9B, sp24 + 0x18, func_8002D7C0(NULL, 0, D_82C01660, 0xD));
            func_8001F444();
        }
    }
}

void func_82C00D98(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_800079C4();
    func_82C00020();
    func_82C00658(arg0, arg1 == 0);

    if (arg2 < 2) {
        func_82C00AA4(arg2, arg3, arg1);
    } else {
        func_82C00CB4(arg1);
    }

    func_80007778();
}

s32 func_82C00E10(s32 arg0) {
    s16 i;
    s32 temp_s2;
    s32 var_s2 = 1;
    s16 var_s1 = 1;

    if (arg0 == 0) {
        for (i = 1; i < 8; i++) {
            func_800290B4();
            func_82C00D98(8, i, arg0, 1);
        }
    }

    while (var_s2 != 0) {
        func_800290B4();
        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP | BTN_DDOWN)) {
            func_80048B90(1);
            var_s1 ^= 1;
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            var_s2 = 0;
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            var_s1 = 1;
            var_s2 = 0;
        }
        func_82C00D98(8, 8, arg0, var_s1);
    }

    temp_s2 = var_s1 == 0;
    if (temp_s2 != 0) {
        if (arg0 == 0) {
            func_80048B90(2);
        } else {
            func_80048B90(0x1F);
        }
    } else {
        func_80048B90(3);
    }

    if ((arg0 == 1) || (var_s1 == 1)) {
        for (i = 7; i > 0; i--) {
            func_800290B4();
            func_82C00D98(8, i, arg0, var_s1);
        }
    }
    return temp_s2;
}

void func_82C00F88(void) {
    s16 i;

    for (i = 1; i < 8; i++) {
        func_800290B4();
        func_82C00D98(8, i, 2, 0);
    }

    do {
        func_800290B4();
        func_82C00D98(8, 8, 2, 0);
    } while (!BTN_IS_PRESSED(gPlayer1Controller, BTN_A));

    func_80048B90(2);

    for (i = 7; i > 0; i--) {
        func_800290B4();
        func_82C00D98(8, i, 2, 0);
    }
}

void func_82C01054(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 9; i++) {
        func_80028C48(i);

        for (j = 0; j < 12; j++) {
            func_8002707C(0x10, j);
        }
    }

    for (j = 0; j < 12; j++) {
        func_8002707C(0x11, j);
    }

    for (j = 0; j < 4; j++) {
        func_8002707C(0x12, j);
    }

    func_8002707C(0x13, 0);
    func_8002707C(0x14, 0);
    func_8002707C(0x15, 0);
    func_8002707C(0x16, 0);
    func_8002707C(0x17, 0);
    func_800286D8();
    D_800AE540.unk_11F2 = 0;
    func_8004AF24(0);
    func_8003D68C(1);
    D_82C01666 = 0;
}

void func_82C0115C(u16 arg0) {
    u16 sp26;
    u16 sp24;

    func_80028070(&sp26);
    sp24 = arg0 ^ sp26;

    if (sp24 != 0) {
        if (sp24 & 1) {
            if (arg0 & 1) {
                func_8004AF24(1);
            } else {
                func_8004AF24(0);
            }
        }

        if (sp24 & 2) {
            if (arg0 & 2) {
                func_8003D68C(0);
            } else {
                func_8003D68C(1);
            }
        }

        func_80028084(&arg0);
        func_80026684(0x14, 0);
    }
}

s16 func_82C0120C(void) {
    s16 sp1E = 0;

    switch (D_82C01664) {
        case 0:
            func_80048B90(2);
            D_82C01666 ^= 1;
            break;

        case 1:
            func_80048B90(2);
            D_82C01666 ^= 2;
            break;

        case 2:
            func_80048B90(2);
            if ((func_82C00E10(0) != 0) && (func_82C00E10(1) != 0)) {
                func_82C01054();
                func_82C00F88();
            }
            break;

        case 3:
            func_80048B90(0x1D);
            func_82C0115C(D_82C01666);
            sp1E = 1;
            break;
    }

    return sp1E;
}

void func_82C012FC(void) {
    s16 i;
    s16 var_s1 = 0;

    func_80006C6C(8);
    while (func_80007604() != 0) {
        func_800290B4();
        func_82C00D98(0, 0, 0, 0);
    }

    for (i = 1; i < 8; i++) {
        func_800290B4();
        func_82C00D98(i, 0, 0, 0);
    }

    while (var_s1 == 0) {
        func_800290B4();
        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
            D_82C01664 = (D_82C01664 + 3) % 4;
            func_80048B90(1);
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
            D_82C01664 = (D_82C01664 + 1) % 4;
            func_80048B90(1);
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            var_s1 = func_82C0120C();
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            var_s1 = 2;
            func_80048B90(3);
        }
        func_82C00D98(8, 0, 0, 0);
    }

    for (i = 7; i > 0; i--) {
        func_800290B4();
        func_82C00D98(i, 0, 0, 0);
    }

    func_80007990(0xFFFF);
    func_80006CB4(8);

    while (func_80007604() != 1) {
        func_800290B4();
        func_82C00D98(0, 0, 0, 0);
    }
}

s32 func_82C014FC(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('PREF');

    func_80005E40(0x10000, 0);
    sp24 = func_80007444(1, 0, 2, 0, 2, 1);
    func_8001E94C(0x1C, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, menu_select_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);

    func_8002D510();
    D_82C01660 = func_8002D5AC(0x15);
    func_80028BE4();
    func_80028070(&D_82C01666);
    D_82C01664 = 0;
    func_80007678(sp24);
    func_82C012FC();
    func_800076C0();
    func_800286D8();
    func_80005EAC();

    main_pool_pop_state('PREF');

    return 4;
}
