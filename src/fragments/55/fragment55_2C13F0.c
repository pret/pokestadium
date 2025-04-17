#include "fragment55.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/22630.h"
#include "src/2E110.h"
#include "src/49790.h"
#include "src/6BC0.h"

static u16 D_83003EF0[151][0x640];
static unk_D_83079E70 D_83079E70;

s32 func_830026D0(s16 arg0, s16 arg1) {
    s32 var_v1;
    s16 sp2;

    if ((arg0 <= 0) || (arg0 >= 0x98)) {
        return 0;
    }

    var_v1 = 0;
    switch (arg1) {
        case 0:
            var_v1 = 1;
            break;

        case 1:
            sp2 = 1;
            break;

        case 2:
            sp2 = 2;
            break;

        case 3:
            sp2 = 1;
            break;

        case 4:
            sp2 = 8;
            break;

        case 5:
            sp2 = 0x10;
            break;

        case 6:
            sp2 = 0x20;
            break;

        case 7:
            var_v1 = 1;
            break;

        case 8:
            var_v1 = 1;
            break;
    }

    if (var_v1 == 0) {
        if (D_8006FEE8[arg0][8] & sp2) {
            var_v1 = 1;
        } else {
            var_v1 = 0;
        }
    }
    return var_v1;
}

s16 func_830027C8(s16 arg0) {
    s16 i;
    s16 var_s1 = 0;

    for (i = 1; i < 152; i++) {
        if (func_830026D0(i, arg0) != 0) {
            var_s1++;
        }
    }

    return var_s1;
}

s32 func_83002848(unk_D_83079E70_000* arg0, s16 arg1, s16 arg2) {
    s32 i;
    s16 var_a0;
    s32 var_s1;
    s32 var_s3;

    for (i = 0; i < 6; i++) {
        arg0->unk_00[i].unk_00 = 0;
        arg0->unk_00[i].unk_02 = 0;
    }

    var_s3 = 0;
    var_s1 = (arg1 * 6) + 1;
    for (i = 0; i < 6; i++, var_s1++) {
        var_a0 = var_s1;
        if ((var_a0 <= 0) || (var_a0 >= 0x98)) {
            var_a0 = 0;
        } else {
            var_s3++;
        }
        arg0->unk_00[i].unk_00 = var_a0;

        if (func_830026D0(var_a0, arg2) != 0) {
            arg0->unk_00[i].unk_02 = 1;
        } else {
            arg0->unk_00[i].unk_02 = 0;
        }
    }

    return var_s3;
}

unk_D_83079E70_000* func_83002950(unk_D_83079E70_000* arg0, s32 arg1) {
    while (arg1-- > 0) {
        arg0 = arg0->unk_18;
    }

    return arg0;
}

s32 func_83002974(unk_D_83079E70* arg0) {
    s32 sp1C = 0;

    if (func_83002848(arg0->unk_10->unk_1C, arg0->unk_08 - 1, D_800AE540.unk_0001) > 0) {
        arg0->unk_00 = 3;
        arg0->unk_02 = 4;
        arg0->unk_08--;
        arg0->unk_10 = arg0->unk_10->unk_1C;
        arg0->unk_0A = -1;
        arg0->unk_0C = -1;
        sp1C = 1;
        func_80048B90(1);
    }

    return sp1C;
}

s32 func_83002A0C(unk_D_83079E70* arg0) {
    s32 sp1C = 0;

    if (func_83002848(func_83002950(arg0->unk_10, 5), arg0->unk_08 + 5, D_800AE540.unk_0001) > 0) {
        arg0->unk_00 = 3;
        arg0->unk_02 = 4;
        arg0->unk_08++;
        arg0->unk_10 = arg0->unk_10->unk_18;
        arg0->unk_0A = 1;
        arg0->unk_0C = -1;
        sp1C = 1;
        func_80048B90(1);
    }

    return sp1C;
}

void func_83002AB4(unk_D_83079E70* arg0) {
    arg0->unk_02--;
    arg0->unk_04 = ((5 - arg0->unk_02) << 0xA) / 5;
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 2;
        arg0->unk_02 = 0;
        arg0->unk_0C = 2;
    }
}

void func_83002B1C(unk_D_83079E70* arg0) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        arg0->unk_00 = 4;
        arg0->unk_02 = 5;
        arg0->unk_0C = -1;
        func_80048B90(3);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DUP)) {
        func_83002974(arg0);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DDOWN)) {
        func_83002A0C(arg0);
    }
}

void func_83002BA4(unk_D_83079E70* arg0) {
    s32 var_v1;

    arg0->unk_02--;
    if (arg0->unk_02 <= 0) {
        var_v1 = 0;
        if (BTN_IS_DOWN(gPlayer1Controller, BTN_DUP)) {
            var_v1 = func_83002974(arg0);
        } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DDOWN)) {
            var_v1 = func_83002A0C(arg0);
        }

        if (var_v1 == 0) {
            arg0->unk_00 = 2;
            arg0->unk_02 = 0;
            arg0->unk_0C = 2;
        }
    }
}

void func_83002C30(unk_D_83079E70* arg0) {
    arg0->unk_02--;
    arg0->unk_04 = (arg0->unk_02 << 0xA) / 5;
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 0;
        arg0->unk_02 = 0;
        arg0->unk_0C = -1;
    }
}

void func_83002C74(s16 arg0, s16 arg1, unk_D_83079E70* arg2) {
    static s16 D_83003B70 = 0;

    s16 temp_t0;

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, 130, 130, 220, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 60, 60, 150, 255);

    func_8001CADC(arg0, arg1, 0x10, 8, D_200A200, 0x10, 0);
    func_8001CADC(arg0, arg1 + 0x114, 0x10, 8, D_200A280, 0x10, 0);
    func_8001C330(arg0, arg1 + 8, 0x10, 0x10C, 0, 0, 0x400, 0, 0);

    if (arg2->unk_00 != 3) {
        temp_t0 = (arg2->unk_08 * 0x10C) / 21;
    } else if (arg2->unk_0A > 0) {
        temp_t0 = (((arg2->unk_08 * 4) - arg2->unk_02) * 0x10C) / 84;
    } else {
        temp_t0 = (((arg2->unk_08 * 4) + arg2->unk_02) * 0x10C) / 84;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (D_83003B70 < 4) {
        func_8001C6AC(arg0 - 4, (arg1 + temp_t0) - 4, 0x18, 0x18, D_200A300, 0x18, 0);
    } else {
        func_8001C6AC(arg0 - 4, (arg1 + temp_t0) - 4, 0x18, 0x18, D_200A780, 0x18, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    D_83003B70 = (D_83003B70 + 1) % 8;
}

void func_83002F9C(s16 arg0, s16 arg1) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 60, 60, 160, 255);

    func_8001CF10(arg0, arg1, 0x20, 0x14, D_4000DD0, 0x20, 0);
}

void func_83003054(s16 arg0, s16 arg1, unk_D_83079E70_000* arg2) {
    UNUSED s32 pad;
    s32 i;
    Color_RGB8* var_v0;
    Color_RGB8 sp78 = { 0x3C, 0x3C, 0xA0 };
    Color_RGB8 sp74 = { 0x64, 0x1E, 0x1E };
    Color_RGB8 sp70 = { 0x1E, 0x1E, 0x64 };
    s16 temp_s0;

    for (i = 0; i < 6; i++) {
        if (arg2->unk_00[i].unk_00 != 0) {
            if (arg2->unk_00[i].unk_02 != 0) {
                var_v0 = &sp78;
            } else {
                var_v0 = &sp74;
            }
        } else {
            var_v0 = &sp70;
        }
        func_83001178(arg0 + i * 0x54, arg1, 0x54, 0x3C, var_v0->r, var_v0->g, var_v0->b);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 6; i++) {
        temp_s0 = arg2->unk_00[i].unk_00;
        if (temp_s0 != NULL) {
            func_8001C6AC(arg0 + (i * 0x54) + 0x16, arg1 + 3, 0x28, 0x28, D_83003EF0[temp_s0 - 1], 0x28, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(4, 0);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);

    for (i = 0; i < 6; i++) {
        temp_s0 = arg2->unk_00[i].unk_00;
        if (temp_s0 != NULL) {
            func_8001F1E8(arg0 + (i * 0x54) + 2, arg1 + 0x2A, func_83000020(temp_s0));
        }
    }

    func_8001F444();
}

void func_830032D8(s32 arg0) {
    unk_D_83079E70* ptr = &D_83079E70;
    s32 i;

    ptr->unk_00 = 0;
    ptr->unk_04 = 0;

    for (i = 0; i < 6; i++) {
        ptr->unk_14[i].unk_18 = &ptr->unk_14[(i + 1) % 6];
        ptr->unk_14[i].unk_1C = &ptr->unk_14[(i + 5) % 6];
    }

    if (arg0 != 0) {
        for (i = 0; i < 151; i++) {
            func_8001B0DC(D_83003EF0[i], i + 1, NULL);
        }
    }
}

void func_830033F0(void) {
    unk_D_83079E70* ptr = &D_83079E70;

    if (ptr->unk_00 != 0) {
        switch (ptr->unk_00) {
            case 1:
                func_83002AB4(&D_83079E70);
                break;

            case 2:
                func_83002B1C(&D_83079E70);
                break;

            case 3:
                func_83002BA4(&D_83079E70);
                break;

            case 4:
                func_83002C30(&D_83079E70);
                break;
        }
    }
}

void func_83003484(void) {
    s16 spA6;
    s16 spA4;
    unk_D_83079E70* ptr = &D_83079E70;

    if (ptr->unk_04 == 0) {
        return;
    }

    spA6 = (((0x400 - ptr->unk_04) * 0x108) / 1024) + 0x38;
    spA4 = (((0x400 - ptr->unk_04) * 0xA8) / 1024) + 0x5C;
    func_83000F10(spA6, spA4, (ptr->unk_04 * 0x210) / 1024, (ptr->unk_04 * 0x150) / 1024);

    if (ptr->unk_04 >= 0x400) {
        UNUSED s32 pad;
        s32 i;
        unk_D_83079E70_000* var_s0;

        func_83001178(spA6, spA4, 0x210, 0x24, 0x1E, 0x64, 0x64);
        func_83001178(spA6, spA4 + 0x24, 0x18, 0x12C, 0x1E, 0x1E, 0x64);
        func_83002C74(spA6 + 4, spA4 + 0x2C, ptr);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_83002F9C(spA6 + 8, spA4 + 8);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        func_8001F3F4();
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001EBE0(8, 0);
        func_8002D600(3, ptr->unk_06);
        {
            char sp4C[64];
            func_8001F1E8(spA6 + 0x2C, spA4 + 8, func_8002D7C0(sp4C, sizeof(sp4C), D_830039C0, 3));
        }
        func_8001F444();

        if (ptr->unk_0C == 0) {
            return;
        }

        if (ptr->unk_00 == 3) {
            s16 sp4A = spA4 - ((ptr->unk_0A * 0x3C * (4 - ptr->unk_02)) / 4);
            func_800060E0(&gDisplayListHead, spA6 + 0x18, spA4 + 0x24, 0x1F8, 0x12C);
            if (ptr->unk_0A > 0) {
                var_s0 = ptr->unk_10->unk_1C;
                for (i = 0; i < 6; i++) {
                    func_83003054(spA6 + 0x18, sp4A + 0x24 + i * 0x3C, var_s0);
                    var_s0 = var_s0->unk_18;
                }
            } else {
                var_s0 = ptr->unk_10;
                for (i = 0; i < 6; i++) {
                    func_83003054(spA6 + 0x18, sp4A - 0x18 + i * 0x3C, var_s0);
                    var_s0 = var_s0->unk_18;
                }
            }
            func_800060E0(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
        } else {
            var_s0 = ptr->unk_10;
            for (i = 0; i < 5; i++) {
                func_83003054(spA6 + 0x18, spA4 + 0x24 + i * 0x3C, var_s0);
                var_s0 = var_s0->unk_18;
            }
        }

        if (ptr->unk_0C > 0) {
            ptr->unk_0C -= 1;
        }
    }

    if (1) {}
}

void func_830038DC(void) {
    unk_D_83079E70* ptr = &D_83079E70;
    s32 i;

    ptr->unk_00 = 1;
    ptr->unk_02 = 5;
    ptr->unk_04 = 0;
    ptr->unk_08 = 0;
    ptr->unk_0A = 0;
    ptr->unk_0C = -1;
    ptr->unk_06 = func_830027C8(D_800AE540.unk_0001);
    ptr->unk_10 = &ptr->unk_14[0];

    for (i = 0; i < 5; i++) {
        func_83002848(&ptr->unk_14[i], i, D_800AE540.unk_0001);
    }
}

s32 func_83003988(void) {
    s32 ret;

    if (D_83079E70.unk_00 != 0) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

s32 func_830039AC(void) {
    return D_83079E70.unk_04;
}
