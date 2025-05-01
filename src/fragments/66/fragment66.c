#include "fragment66.h"
#include "src/12D80.h"
#include "src/17300.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/232C0.h"
#include "src/2E110.h"
#include "src/2E460.h"
#include "src/3FB0.h"
#include "src/485C0.h"
#include "src/48C60.h"
#include "src/49790.h"
#include "src/4F410.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/DDC0.h"
#include "src/F420.h"
#include "src/geo_layout.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/util.h"

static GraphNode* D_83202010;
static GraphNode* D_83202014;
static unk_D_86002F30* D_83202018;
static char** D_8320201C;
static char** D_83202020;
static unk_D_86002F58_004_000 D_83202028[4];
static unk_D_832025C8 D_832025C8;
static unk_D_832027C8 D_832027C8;

static s32 D_83201F50 = 0;
static s32 D_83201F54 = -1;
static char* D_83201F58 = NULL;
static u32 D_83201F5C[] = {
    0x0C000000,  0x05000000, 0x0B00001E,    0x00000000, 0x014000F0, 0x00000320, 0x00000000, 0x000005DC, 0x05000000,
    0x0D000000,  0x05000000, 0x0E000002,    0x05000000, 0x22010000, 0x8C200060, 0x06000000, 0x14000000, 0x002B0012,
    0xFFFFFF32,  0x16FFFFFF, 0x0F000003,    0x05000000, 0x1F000000, 0x00000000, 0x00000000, 0x003CFF06, 0x00640064,
    0x00640000,  0x08000000, func_83200020, 0x00000000, 0x05000000, 0x00000000, D_8C200920, 0x06000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000,    0x06000000, 0x06000000, 0x01000000,
};

s32 func_83200020(s32 arg0, unk_D_86002F58_004_000* arg1) {
    if (arg0 == 2) {
        arg1->unk_01E.z -= 0x80;
        arg1->unk_024.x = D_83202028->unk_024.x;
        arg1->unk_024.y = D_83202028->unk_024.y + 70.0f;
    }
    return 0;
}

s32 func_83200064(unk_func_80026268_arg0* arg0) {
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

s32 func_832000A0(unk_func_80026268_arg0* arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 sp1C = 0;

    if ((arg0->unk_00.unk_00 > 0) && (arg0->unk_00.unk_00 < 0x98)) {
        if ((func_83200064(arg0) != 0) && (D_8006FF00[arg0->unk_00.unk_00 - 1].unk_0C & arg3)) {
            if ((arg0->unk_24 >= arg1) && (arg2 >= arg0->unk_24)) {
                sp1C = 1;
            }
        }
    }
    return sp1C;
}

s32 func_83200148(s16 arg0, s16 arg1, s16 arg2) {
    UNUSED s32 pad[22];
    s32 sp34;
    s16 var_s3;
    unk_func_80022C28_ret* var_v0;
    unk_func_80026268_arg0* ptr = &D_832027C8.unk_04;

    sp34 = 0;
    var_s3 = 0;

    if (arg1 == 0) {
        var_v0 = func_80022C28(0x20, arg0, 0, 0);
    } else {
        var_v0 = func_80022C28(0x21, arg0, arg1 - 1, 0);
    }

    if (var_v0 != NULL) {
        while (func_80022E18(&ptr->unk_00.unk_00, 1, var_v0) == 1) {
            if (func_832000A0(ptr, 1, 0x64, 0x20) != 0) {
                if (!arg2--) {
                    if (ptr->unk_00.unk_00 == 0x19) {
                        sp34 = 1;
                    }
                    break;
                }
            }
            var_s3++;
        }
        func_80022D8C(var_v0);
    }

    if (sp34 != 0) {
        return var_s3;
    }
    return -1;
}

s32 func_8320029C(void) {
    s32 i;
    unk_D_800AE540_0004* var_v1;

    var_v1 = D_800AE540.unk_1194[0].unk_08[0];

    for (i = 0; i < var_v1->unk_002; i++) {
        if (var_v1->unk_01C[i].unk_00.unk_00 == 0x19) {
            D_832027C8.unk_00 = (var_v1->unk_01C[i].unk_52 & 0x70) >> 4;
            D_832027C8.unk_01 = var_v1->unk_01C[i].unk_52 & 0xF;
            if ((D_832027C8.unk_00 < 4) && (D_832027C8.unk_01 < 0xD)) {
                if (func_80023D60(D_832027C8.unk_00) != 0) {
                    D_832027C8.unk_02 = func_83200148(D_832027C8.unk_00, D_832027C8.unk_01, var_v1->unk_01C[i].unk_53);
                    if (D_832027C8.unk_02 >= 0) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }

    return 0;
}

s32 func_8320037C(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_832027C8.unk_04.unk_09[i] == 0) {
            break;
        }
    }
    return i;
}

void func_832003AC(void) {
    static s32 D_83202004 = 0;

    if ((D_83202028[0].unk_040.unk_00 != 0xA) && (D_83202028[0].unk_040.unk_00 != 5)) {
        D_83202004++;
        if (D_83202004 == 0x3C) {
            D_83202004 = 0;
            func_8001BD9C(&D_83202028[0], -1);
            func_8001BD9C(&D_83202028[0], 0xA);
        }
    }

    if ((D_83202028[0].unk_040.unk_00 != 0) && (func_80017514(&D_83202028[0]) != 0)) {
        if (D_83201F50 != 0) {
            D_83202028[0].unk_000.unk_01 &= ~1;
        } else {
            func_8001BD04(&D_83202028[0], 0);
        }
    }
}

void func_83200468(void) {
    if (D_83201F54 == -1) {
        D_83202028[1].unk_000.unk_01 &= ~1;
        D_83202028[2].unk_000.unk_01 &= ~1;
        D_83202028[3].unk_000.unk_01 &= ~1;
        return;
    }

    switch (D_83201F54) {
        case 0x0:
            D_83202028[1].unk_000.unk_01 |= 1;
            break;

        case 0x8:
            D_83202028[2].unk_000.unk_01 |= 1;
            break;

        case 0x10:
            D_83202028[3].unk_000.unk_01 |= 1;
            break;

        case 0x46:
            D_83202028[1].unk_000.unk_01 &= ~1;
            break;

        case 0x4E:
            D_83202028[2].unk_000.unk_01 &= ~1;
            break;

        case 0x56:
            D_83202028[3].unk_000.unk_01 &= ~1;
            break;
    }

    if (D_83201F54 < 0x57) {
        D_83201F54++;
    }
}

s32 func_8320058C(u8 arg0) {
    func_80015348();
    func_832003AC();
    func_83200468();
    func_800079C4();
    func_8000699C(&gDisplayListHead, 1);
    func_80015094(D_83202010);
    return 0;
}

void func_832005E4(s16 arg0, s16 arg1) {
    s32 var_a3;

    if (D_832025C8.unk_00 < 0x10) {
        var_a3 = D_832025C8.unk_00 * 0x10;
    } else if (D_832025C8.unk_00 < 0x23) {
        var_a3 = 0xFF;
    } else if (D_832025C8.unk_00 < 0x32) {
        var_a3 = (-D_832025C8.unk_00 * 0x10) + 0x320;
    } else {
        var_a3 = 0;
    }

    D_832025C8.unk_00++;
    if (D_832025C8.unk_00 >= 0x3D) {
        D_832025C8.unk_00 = 0;
    }

    func_8001F324(0xFF, 0xFF, 0xFF, var_a3);
    func_8001F2E4(arg0, arg1, 0x23);
}

void func_83200684(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    Color_RGB8 sp24 = { 0x00, 0x00, 0x32 };
    Color_RGB8 sp20 = { 0x00, 0x00, 0xC8 };

    func_8002053C(arg0, arg1, arg2, arg3, &sp24, &sp20);
}

void func_83200700(s16 arg0, s16 arg1) {
    gSPDisplayList(gDisplayListHead++, D_8006F4E0);

    func_8001C6AC(arg0, arg1, 0x18, 0xE, Util_ConvertAddrToVirtAddr(D_8C200090), 0x18, 0x200000);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_832007A4(char* arg0, s32 arg1) {
    while (arg1-- > 0) {
        func_800290B4();
        func_8320058C(0);
        func_83200684(0x1E, 0x20, 0x104, 0x30);
        func_8001F3F4();
        func_8001EBE0(2, 0);
        func_8001F3B4(0x10);
        func_8001F1E8(0x2E, 0x28, arg0);
        func_8001F444();
        func_80007778();
    }

    D_83201F58 = arg0;
}

void func_8320084C(char* arg0, s32 arg1) {
    D_832025C8.unk_00 = 0x10;

    do {
        func_800290B4();
        func_8320058C(0);
        func_83200684(0x1E, 0x20, 0x104, 0x30);
        func_8001F3F4();
        func_8001EBE0(2, 0);
        func_8001F3B4(0x10);
        func_8001F1E8(0x2E, 0x28, arg0);
        func_8001EBE0(4, 0);
        if (arg1 != 0) {
            func_832005E4(0x104, 0x38);
        }
        func_8001F444();
        func_80007778();
    } while (!BTN_IS_PRESSED(gPlayer1Controller, BTN_A));

    func_80048B90(1);
    D_83201F58 = arg0;
}

void func_83200934(s8* arg0) {
    s32 i;
    s32 x1 = 0x1E;
    s32 x2 = 0x122;
    s32 y1 = 0x28;
    s32 y2 = 0x48;

    for (i = 1; i < 9; i++) {
        func_800290B4();
        func_8320058C(0);
        func_83200684(0x1E, 0x20, 0x104, 0x30);

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

        func_8001F3F4();
        func_8001EBE0(2, 0);
        func_8001F3B4(0x10);
        func_8001F1E8(0x2E, y1 - i * 4, D_83201F58);
        func_8001F1E8(0x2E, y2 - i * 4, arg0);
        func_8001F444();
        func_80007778();
    }

    D_83201F58 = arg0;
}

s32 func_83200ADC(char* arg0) {
    s32 temp_s3;
    s32 var_a2;
    s32 var_s1;
    s32 var_s2;

    var_s2 = 1;
    var_s1 = 0;

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

        temp_s3 = var_s1 == 0;
        func_8320058C(0);
        func_83200684(0x1E, 0x20, 0x104, 0x30);
        func_83200684(0xD2, 0x54, 0x50, 0x2C);
        func_83200700(0xDA, (var_s1 * 0x10) + 0x5C);
        func_8001F3F4();
        func_8001EBE0(2, 0);
        func_8001F3B4(0x10);
        func_8001F1E8(0x2E, 0x28, arg0);

        if (temp_s3 != 0) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        func_8001F324(0xFF, 0xFF, var_a2, 0xFF);
        func_8001F1E8(0xF2, 0x5C, func_8002D7C0(NULL, 0, D_83202020, 0x10));

        if (var_s1 == 1) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        func_8001F324(0xFF, 0xFF, var_a2, 0xFF);
        func_8001F1E8(0xF2, 0x6C, func_8002D7C0(NULL, 0, D_83202020, 0x11));
        func_8001F444();
        func_80007778();
    }

    if (temp_s3 != 0) {
        func_80048B90(2);
    } else {
        func_80048B90(3);
    }
    return temp_s3;
}

s32 func_83200CD8(char* arg0) {
    s32 var_a2;
    s32 var_s0;
    s32 var_s4;

    var_s4 = 1;
    var_s0 = 0;

    while (var_s4 != 0) {
        func_800290B4();

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
            func_80048B90(1);
            var_s0--;
            if (var_s0 < 0) {
                var_s0 = 3;
            }
        }

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
            func_80048B90(1);
            var_s0++;
            if (var_s0 >= 4) {
                var_s0 = 0;
            }
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            if ((D_832027C8.unk_04.unk_09[var_s0] == 0xF) || (D_832027C8.unk_04.unk_09[var_s0] == 0x13) ||
                (D_832027C8.unk_04.unk_09[var_s0] == 0x46) || (D_832027C8.unk_04.unk_09[var_s0] == 0x94)) {
                func_80048B90(8);
            } else {
                var_s4 = 0;
                func_80048B90(2);
            }
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            var_s4 = 0;
            var_s0 = -1;
            func_80048B90(3);
        }

        func_8320058C(0);
        func_83200684(0x1E, 0x20, 0x82, 0x30);
        func_8001F3F4();
        func_8001EBE0(2, 0);
        func_8001F3B4(0x10);
        func_8001F1E8(0x2E, 0x28, arg0);
        func_8001F444();
        func_83200684(0x96, 0x20, 0x8C, 0x4C);
        func_83200700(0x9E, (var_s0 * 0x10) + 0x28);
        func_8001F3F4();
        func_8001EBE0(2, 0);
        func_8001F3B4(0x10);

        if (var_s0 == 0) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        func_8001F324(0xFF, 0xFF, var_a2, 0xFF);
        func_8001F1E8(0xB6, 0x28, func_8002D7C0(NULL, 0, D_8320201C, D_832027C8.unk_04.unk_09[0] - 1));

        if (var_s0 == 1) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        func_8001F324(0xFF, 0xFF, var_a2, 0xFF);
        func_8001F1E8(0xB6, 0x38, func_8002D7C0(NULL, 0, D_8320201C, D_832027C8.unk_04.unk_09[1] - 1));

        if (var_s0 == 2) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        func_8001F324(0xFF, 0xFF, var_a2, 0xFF);
        func_8001F1E8(0xB6, 0x48, func_8002D7C0(NULL, 0, D_8320201C, D_832027C8.unk_04.unk_09[2] - 1));

        if (var_s0 == 3) {
            var_a2 = 0;
        } else {
            var_a2 = 0xFF;
        }

        func_8001F324(0xFF, 0xFF, var_a2, 0xFF);
        func_8001F1E8(0xB6, 0x58, func_8002D7C0(NULL, 0, D_8320201C, D_832027C8.unk_04.unk_09[3] - 1));

        func_8001F444();
        func_80007778();
    }

    return var_s0;
}

void func_83200FF8(void) {
    func_83200934(func_8002D7C0(NULL, 0, D_83202020, 4));
    D_83202028->unk_01E.y = -0x800;
    func_8001BD04(D_83202028, 5);
    func_8001BD9C(D_83202028, 0);
    D_83201F50 = 1;
    func_832007A4(func_8002D7C0(NULL, 0, D_83202020, 4), 0x46);
    func_80006C04(0x1E);
    func_8000D278(0x3C);
    func_832007A4(func_8002D7C0(NULL, 0, D_83202020, 4), 0x1E);
}

void func_832010BC(void) {
    func_8001BD04(D_83202028, 0xA);
    func_8001BD9C(D_83202028, 7);
    func_80048060(0, 0x39, 0x19, 0);
    D_83201F50 = 1;
    func_8000D1F0(0x4A);
    func_83200934(func_8002D7C0(NULL, 0, D_83202020, 0xF));
    func_832007A4(func_8002D7C0(NULL, 0, D_83202020, 0xF), 0x98);
    func_80006C04(0x1E);
    func_832007A4(func_8002D7C0(NULL, 0, D_83202020, 0xF), 0x1E);
}

void func_8320118C(void) {
    s32 i;
    unk_D_86002F34_00C* temp_s1 = D_83202010->unk_0C;

    D_83202028->unk_01E.y = 0x1000;

    for (i = 0; i < 120; i++) {
        func_800290B4();
        temp_s1->unk_60.at.y = 0x320 - ((i * 0x1E0) / 120);
        temp_s1->unk_60.eye.y = 0x320 - ((i * 0x1E0) / 120);
        D_83202028->unk_01E.y += 0x200;
        func_8320058C(0);
        func_80007778();
    }
}

s32 func_8320126C(void) {
    s16 var_s0 = 0x14;
    s16 var_s1 = 0x10;
    s32 i;

    func_8001BD04(D_83202028, 8);

    for (i = 0; i < 8; i++) {
        func_800290B4();
        func_8320058C(0);
        func_83200684(0xA0 - (var_s0 / 2), 0x38 - (var_s1 / 2), var_s0, var_s1);
        func_80007778();
        var_s0 += 0x1E;
        var_s1 += 4;
    }

    func_8320084C(func_8002D7C0(NULL, 0, D_83202020, 0), 1);
    func_83200934(func_8002D7C0(NULL, 0, D_83202020, 1));
    func_8320084C(func_8002D7C0(NULL, 0, D_83202020, 1), 1);

    while (true) {
        func_83200934(func_8002D7C0(NULL, 0, D_83202020, 2));
        if (func_83200ADC(func_8002D7C0(NULL, 0, D_83202020, 2)) != 0) {
            return 1;
        }

        func_83200934(func_8002D7C0(NULL, 0, D_83202020, 3));
        if (func_83200ADC(func_8002D7C0(NULL, 0, D_83202020, 3)) != 0) {
            func_83200FF8();
            return 0;
        }
    }
}

s32 func_83201450(void) {
    s32 spAC;
    char sp2C[0x80];
    s32 temp_v0;

    temp_v0 = func_8320037C();
    if (temp_v0 == 4) {
        while (true) {
            func_83200934(func_8002D7C0(NULL, 0, D_83202020, 5));
            func_8320084C(func_8002D7C0(NULL, 0, D_83202020, 5), 1);
            func_83200934(func_8002D7C0(NULL, 0, D_83202020, 6));
            func_8320084C(func_8002D7C0(NULL, 0, D_83202020, 6), 1);
            func_83200934(func_8002D7C0(NULL, 0, D_83202020, 7));

            if (func_83200ADC(func_8002D7C0(NULL, 0, D_83202020, 7)) != 0) {
                func_83200934(func_8002D7C0(NULL, 0, D_83202020, 9));

                spAC = func_83200CD8(func_8002D7C0(NULL, 0, D_83202020, 9));
                if (spAC >= 0) {
                    func_832007A4(func_8002D7C0(NULL, 0, D_83202020, 0xA), 0x1E);
                    func_8001BD04(D_83202028, 9);
                    D_83201F54 = 0;
                    func_800479C0(0x85, 0x19, 0);
                    func_8320084C(func_8002D7C0(NULL, 0, D_83202020, 0xB), 1);
                    func_8002D5D4(0x1D, func_8002D7C0(NULL, 0, D_8320201C, D_832027C8.unk_04.unk_09[spAC] - 1));
                    func_8002D7C0(sp2C, sizeof(sp2C), D_83202020, 0xC);
                    func_8000D278(0x3C);
                    func_83200934(sp2C);
                    func_8320084C(sp2C, 1);
                    func_83200934(func_8002D7C0(NULL, 0, D_83202020, 0xD));
                    func_8320084C(func_8002D7C0(NULL, 0, D_83202020, 0xD), 1);
                    D_83201F54 = -1;
                    return spAC;
                }
            }

            func_83200934(func_8002D7C0(NULL, 0, D_83202020, 8));

            if (func_83200ADC(func_8002D7C0(NULL, 0, D_83202020, 8)) != 0) {
                func_83200FF8();
                return -1;
            }
        }
    }

    func_8000D278(0x3C);
    return temp_v0;
}

void func_832016F4(s32 arg0) {
    func_8320058C(0);
    func_83200684(0x1E, 0x20, 0x104, 0x30);

    if (arg0 == 0) {
        func_83200684(0x4C, 0x64, 0xA8, 0x28);
    } else {
        func_83200684(0x30, 0x54, 0xE0, 0x78);
    }

    func_8001F3F4();
    func_8001EBE0(2, 0);
    func_8001F3B4(0x10);
    func_8001F1E8(0x2E, 0x28, func_8002D7C0(NULL, 0, D_83202020, 0xE));

    if (arg0 == 0) {
        func_8001F3F4();
        func_8001EBE0(4, 0);
        func_8001F1E8(0x5C, 0x70, func_8002D7C0(NULL, 0, D_83202020, 0x12));
        func_8001F444();
    } else {
        func_8001F3B4(0x10);
        func_8001F1E8(0x40, 0x84, func_8002D7C0(NULL, 0, D_83202020, 0x13));
        func_8001F324(0xFF, 0xFF, 0x64, 0xFF);

        if (arg0 == 2) {
            func_8001EBE0(4, 0);
            func_8001F1E8(0x4C, 0x64, func_8002D7C0(NULL, 0, D_83202020, 0x14));
        } else if (arg0 == 3) {
            func_8001F3B4(0x10);
            func_8001F1E8(0x40, 0x5C, func_8002D7C0(NULL, 0, D_83202020, 0x15));
        }
    }

    func_8001F444();
    func_80007778();
}

void func_832018DC(void) {
    s32 var_s0;
    s32 temp_v0;
    unk_func_80022C28_ret* var_v0;

    if (D_832027C8.unk_01 == 0) {
        var_v0 = func_80022C28(0x20, D_832027C8.unk_00, 0, 2);
    } else {
        var_v0 = func_80022C28(0x21, D_832027C8.unk_00, D_832027C8.unk_01 - 1, 2);
    }

    func_80022DF4(var_v0, D_832027C8.unk_02);
    func_80022F24(&D_832027C8.unk_04, 1, var_v0);
    func_80022D8C(var_v0);
    func_832016F4(0);
    func_832016F4(0);
    func_8002447C(D_832027C8.unk_00);

    while (func_800243D8(D_832027C8.unk_00) == 0) {
        var_s0 = 2;
        do {
            temp_v0 = func_80023E34(D_832027C8.unk_00);
            if (temp_v0 == 1) {
                var_s0 = 1;
            }

            if (temp_v0 == 3) {
                var_s0 = 3;
            }

            func_832016F4(var_s0);
        } while (temp_v0 != 2);

        func_832016F4(0);
        func_832016F4(0);
    }
    func_800244F4(D_832027C8.unk_00);
}

void func_83201A18(s32 arg0) {
    s32 i;

    func_8004E810(0x19, 0);
    func_83200934(func_8002D7C0(NULL, 0, D_83202020, 0xE));
    func_832007A4(func_8002D7C0(NULL, 0, D_83202020, 0xE), 1);

    for (i = func_8320037C(); i < 4; i++) {
        D_832027C8.unk_04.unk_09[i] = 0;
        D_832027C8.unk_04.unk_20[i] = 0;
    }

    D_832027C8.unk_04.unk_09[arg0] = 0x39;
    D_832027C8.unk_04.unk_20[arg0] = D_80072B00[0x38].unk_05;

    func_832018DC();
    func_8320084C(func_8002D7C0(NULL, 0, D_83202020, 0xE), 1);
    func_832010BC();
}

void func_83201B60(void) {
    s32 temp_v0;

    func_8000D1F0(0x49);
    func_800077B4(2);
    func_80006C04(0x28);
    func_80007820(0xA, func_8320058C);
    func_8320118C();
    if (func_8320126C() != 0) {
        temp_v0 = func_83201450();
        if (temp_v0 >= 0) {
            func_83201A18(temp_v0);
        }
    }
    func_800077B4(2);
}

void func_83201BD8(unk_D_86002F58_004_000* arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_8001BC34(arg0, 0, 0, D_83202014);
    func_800173DC(arg0, 0, D_8C2011C4, 0x10000);
    arg0->unk_000.unk_01 &= ~1;
    func_8000E88C(&arg0->unk_030, 1.5f, 1.5f, 1.5f);
    arg0->unk_024.x = arg1;
    arg0->unk_024.y = arg2;
    arg0->unk_01E.z = arg3;
}

void func_83201C8C(void) {
    MemoryBlock* temp_v0;
    s32 i;

    temp_v0 = func_80002D10(main_pool_get_available(), 0);
    D_83202010 = process_geo_layout(temp_v0, D_83201F5C);
    D_83202014 = process_geo_layout(temp_v0, D_8C201070);

    func_80002D60(temp_v0);
    func_8001BB20();

    for (i = 0; i < 4; i++) {
        func_8001BB58(&D_83202028[i]);
    }

    func_8001BC34(&D_83202028[0], 0, 0, D_83202018->unk_08->unk_00[0]);
    func_8000E88C(&D_83202028[0].unk_030, 16.0f, 16.0f, 16.0f);
    func_8001BD04(&D_83202028[0], 0);
    D_83202028->unk_000.unk_02 &= ~0x40;
    func_83201BD8(&D_83202028[1], -0x50, 0x17C, 0x1800);
    func_83201BD8(&D_83202028[2], 0, 0x17C, 0);
    func_83201BD8(&D_83202028[3], 0x50, 0x17C, -0x1800);
}

s32 func_83201DD4(UNUSED s32 arg0, UNUSED s32 arg1) {
    UNUSED s32 pad;
    unk_func_80007444* sp20;

    main_pool_push_state('PIKA');

    if (func_8320029C() != 0) {
        func_80005E40(0x10000, 0);
        sp20 = func_80007444(0, 1, 3, 1, 2, 1);
        func_8001E94C(6, 0);

        FRAGMENT_LOAD(fragment31);
        func_80004454(FRAGMENT_ID(_798CD0), _798CD0_ROM_START, _798CD0_ROM_END);
        ASSET_LOAD(D_1000000, common_menu1_ui, 0);

        func_8002D510();
        D_8320201C = func_8002D5AC(0x25);
        D_83202020 = func_8002D5AC(0x1C);
        func_8001987C();
        D_83202018 = func_80019D90(&D_832027C8.unk_04);
        func_83201C8C();
        func_80007678(sp20);
        func_83201B60();
        func_800076C0();
        func_8001E9CC();
        func_80005EAC();
    }

    main_pool_pop_state('PIKA');
    return 0;
}
