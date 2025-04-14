#include "fragment41.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/232C0.h"
#include "src/2E110.h"
#include "src/49790.h"

static unk_D_82F210E0 D_82F210E0;
static unk_func_82F00838_sp30_00C* D_82F21120[2];
static s16 D_82F21128;
static s32 D_82F2112C;
static s32 D_82F21130;

s32 func_82F09EB0(unk_func_82F00838_sp30* arg0) {
    unk_func_80022C28_ret* sp24;
    s32 var_v1;

    if (arg0->unk_04 == 0) {
        sp24 = func_80022C28(0x20, arg0->unk_02, 0, 1);
    } else {
        sp24 = func_80022C28(0x21, arg0->unk_02, arg0->unk_04 - 1, 1);
    }

    func_80022F24(&arg0->unk_0C->unk_00, arg0->unk_08, sp24);
    func_80022D8C(sp24);

    var_v1 = func_80024270(arg0->unk_02);
    if (var_v1 != 0) {
        var_v1 = func_8002431C(arg0->unk_02);
    }
    return var_v1;
}

s32 func_82F09F44(unk_D_82F210E0* arg0) {
    s32 i;
    unk_func_82F00838_sp30* ptr;
    unk_func_82F00838_sp30 sp30[2];
    s32 sp2C = 0;

    for (i = 0; i < 2; i++) {
        func_82F0525C(i, &sp30[i]);
    }

    if (arg0->unk_06 < 0) {
        arg0->unk_06 = 0;
        for (i = 0, ptr = &sp30[0]; i < 2; i++, ptr++) {
            func_8002447C(ptr->unk_02);
        }
    }

    if (arg0->unk_08 < 2) {
        for (i = 0, ptr = &sp30[0]; i < 2; i++, ptr++) {
            if (i < arg0->unk_08) {
                continue;
            }

            if (func_80023658(ptr->unk_02) != 0) {
                arg0->unk_08++;
            } else {
                break;
            }
        }
    }

    if (arg0->unk_08 < 2) {
        return 0;
    }

    for (i = 0, ptr = &sp30[0]; i < 2; i++, ptr++) {
        if (i < arg0->unk_0A) {
            continue;
        }

        if (func_82F09EB0(ptr) != 0) {
            arg0->unk_0A += 1;
            func_800244F4(ptr->unk_02);
        } else {
            break;
        }
    }

    if (arg0->unk_0A == 2) {
        sp2C = 1;
    }
    return sp2C;
}

void func_82F0A0A8(s32 arg0) {
    UNUSED s32 pad;
    unk_D_82F210E0* ptr = &D_82F210E0;
    s32 i;
    unk_func_82F00838_sp30 sp2C;

    ptr->unk_00 = 1;
    ptr->unk_02 = 0xA;
    ptr->unk_04 = 0;
    ptr->unk_06 = -1;
    ptr->unk_08 = 0;
    ptr->unk_0A = 0;
    ptr->unk_0C = 0;
    ptr->unk_0E = 0;
    ptr->unk_10 = -1;
    ptr->unk_12 = -1;
    if (arg0 != 0) {
        ptr->unk_04 |= 1;
    }

    for (i = 0; i < 2; i++) {
        func_82F0525C(i, &sp2C);
        D_82F21120[i] = &sp2C.unk_0C[sp2C.unk_06];
    }

    D_82F21128 = 0;
    D_82F2112C = 0;
    D_82F21130 = 0;

    for (i = 0; i < 2; i++) {
        ptr->unk_14[i].unk_00 = ptr->unk_14[i].unk_02 = 0;
        ptr->unk_14[i].unk_04 = 0xC8;
        ptr->unk_14[i].unk_06 = 0;
    }

    ptr->unk_24.unk_00 = 0;
    ptr->unk_24.unk_04 = 0xE8;
    ptr->unk_24.unk_06 = 0;
    ptr->unk_2C.unk_00 = 0;
    ptr->unk_2C.unk_04 = 0x210;
    ptr->unk_2C.unk_06 = 0;
    ptr->unk_34.unk_00 = 0;
    ptr->unk_34.unk_04 = 0xE8;
    ptr->unk_34.unk_06 = 0;
    ptr->unk_24.unk_02 = 0;
    ptr->unk_2C.unk_02 = 0;
    ptr->unk_34.unk_02 = 0;

    if (arg0 != 0) {
        func_80048B90(0x1E);
    } else {
        func_80048B90(4);
    }
}

void func_82F0A23C(unk_D_82F210E0* arg0) {
    s32 i;
    unk_D_82F20A40_00E* ptr;

    arg0->unk_02--;

    for (i = 0; i < 2; i++) {
        arg0->unk_14[i].unk_00 = ((i * 0x118) - ((arg0->unk_02 * 0) / 10)) + 0x50;
        arg0->unk_14[i].unk_02 = 0x60 - ((arg0->unk_02 * -0x54) / 10);
        arg0->unk_14[i].unk_04 = 0xC8 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_14[i].unk_06 = 0xA8 - ((arg0->unk_02 * 0xA8) / 10);
    }

    ptr = &arg0->unk_24;
    if (!(arg0->unk_04 & 1)) {
        ptr->unk_00 = 0xCC - ((arg0->unk_02 * 0) / 10);
        ptr->unk_02 = 0x11C - ((arg0->unk_02 * -0x38) / 10);
        ptr->unk_04 = 0xE8 - ((arg0->unk_02 * 0) / 10);
        ptr->unk_06 = 0x70 - ((arg0->unk_02 * 0x70) / 10);
    }

    ptr = &arg0->unk_2C;
    if (arg0->unk_04 & 1) {
        ptr->unk_00 = 0x38 - ((arg0->unk_02 * 0) / 10);
        ptr->unk_02 = 0x190 - ((arg0->unk_02 * -0x14) / 10);
        ptr->unk_04 = 0x210 - ((arg0->unk_02 * 0) / 10);
        ptr->unk_06 = 0x28 - ((arg0->unk_02 * 0x28) / 10);
    }

    if (arg0->unk_02 <= 0) {
        if (arg0->unk_04 & 1) {
            arg0->unk_00 = 3;
            arg0->unk_02 = 0x14;
            arg0->unk_04 |= 4;
        } else {
            arg0->unk_00 = 2;
            arg0->unk_02 = 0;
            arg0->unk_04 |= 6;
        }
    }
}

void func_82F0A5F8(unk_D_82F210E0* arg0) {
    s32 var_t0 = 0;
    s32 var_a2;
    s16 tmp;

    if (arg0->unk_04 & 1) {
        var_a2 = 3;
    } else {
        var_a2 = 2;
    }

    tmp = D_82F21128;
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP) && (D_82F21128 > 0)) {
        D_82F21128--;
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN) && (D_82F21128 < (var_a2 - 1))) {
        D_82F21128++;
    }

    if (D_82F21128 != tmp) {
        var_t0 = 0;
        func_80048B90(1);
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        var_t0 = 1;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B) && !(arg0->unk_04 & 1)) {
        var_t0 = 1;
        D_82F21128 = 1;
    }

    if (var_t0 != 0) {
        if (arg0->unk_04 & 1) {
            switch (D_82F21128) {
                case 0:
                    arg0->unk_00 = 5;
                    arg0->unk_02 = 0xA;
                    D_82F21130 = 0;
                    func_80048B90(0x1D);
                    break;

                case 1:
                    arg0->unk_00 = 5;
                    arg0->unk_02 = 0xA;
                    D_82F21130 = 1;
                    func_80048B90(0x22);
                    break;

                default:
                    arg0->unk_00 = 8;
                    arg0->unk_02 = 0xA;
                    arg0->unk_04 &= ~4;
                    D_82F21130 = 0;
                    func_80048B90(3);
                    break;
            }
        } else {
            arg0->unk_00 = 8;
            arg0->unk_02 = 0xA;
            arg0->unk_04 &= ~6;
            if (D_82F21128 == 0) {
                D_82F2112C = 1;
                func_80048B90(2);
            } else {
                D_82F2112C = 0;
                func_80048B90(3);
            }
        }
        arg0->unk_12 = -1;
    }
}

void func_82F0A804(unk_D_82F210E0* arg0) {
    arg0->unk_02--;
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        arg0->unk_02 = 0;
    }

    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 4;
        arg0->unk_02 = 0xA;
    }
}

void func_82F0A850(unk_D_82F210E0* arg0) {
    arg0->unk_02--;
    arg0->unk_24.unk_00 = 0xA2 - (arg0->unk_02 * 0) / 10;
    arg0->unk_24.unk_02 = 0x116 - ((arg0->unk_02 * -0x2E) / 10);
    arg0->unk_24.unk_04 = 0x13C - (arg0->unk_02 * 0) / 10;
    arg0->unk_24.unk_06 = 0x70 - ((arg0->unk_02 * 0x70) / 10);
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 2;
        arg0->unk_02 = 0;
    }
}

void func_82F0A950(unk_D_82F210E0* arg0) {
    arg0->unk_02--;
    arg0->unk_24.unk_00 = 0xA2 - (arg0->unk_02 * 0) / 10;
    arg0->unk_24.unk_02 = 0x144 - ((arg0->unk_02 * 0x2E) / 10);
    arg0->unk_24.unk_04 = 0x13C - (arg0->unk_02 * 0) / 10;
    arg0->unk_24.unk_06 = -((arg0->unk_02 * -0x70) / 10);
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 6;
        arg0->unk_02 = 0xA;
    }
}

void func_82F0AA50(unk_D_82F210E0* arg0) {
    arg0->unk_02--;
    arg0->unk_34.unk_00 = 0xCC - (arg0->unk_02 * 0) / 10;
    arg0->unk_34.unk_02 = 0x134 - ((arg0->unk_02 * -0x1C) / 10);
    arg0->unk_34.unk_04 = 0xE8 - (arg0->unk_02 * 0) / 10;
    arg0->unk_34.unk_06 = 0x38 - ((arg0->unk_02 * 0x38) / 10);
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 7;
        arg0->unk_02 = 5;
        arg0->unk_06 = -1;
        arg0->unk_08 = 0;
        arg0->unk_0A = 0;
        arg0->unk_0C = 0;
        arg0->unk_0E = 0;
        arg0->unk_10 = -1;
    }
}

void func_82F0AB68(unk_D_82F210E0* arg0) {
    s32 temp_v0;
    unk_func_82F00838_sp30 sp24;

    arg0->unk_02--;
    if (arg0->unk_02 <= 0) {
        arg0->unk_02 = 0;
        if (arg0->unk_0C == 1) {
            func_82F0525C(arg0->unk_0A, &sp24);
            temp_v0 = func_80023E34(sp24.unk_02);
            if (temp_v0 == 1) {
                arg0->unk_10 = 1;
            }

            if (temp_v0 == 3) {
                arg0->unk_10 = 3;
            }

            if (temp_v0 == 2) {
                arg0->unk_0C = 2;
                arg0->unk_0E = 3;
                arg0->unk_10 = 0;
            }
        }

        if (arg0->unk_0C == 2) {
            arg0->unk_0E -= 1;
            if (arg0->unk_0E <= 0) {
                arg0->unk_0C = 0;
                arg0->unk_0E = 0;
            }
        }

        if (arg0->unk_0C == 0) {
            if (func_82F09F44(arg0) != 0) {
                arg0->unk_00 = 8;
                arg0->unk_02 = 0xA;
                arg0->unk_04 &= ~4;
                arg0->unk_10 = -1;
                func_80048B90(9);
            } else {
                arg0->unk_06 += 1;
                arg0->unk_0C = 1;
                arg0->unk_10 = 2;
                func_82F0525C(arg0->unk_0A, &sp24);
                temp_v0 = func_80023E34(sp24.unk_02);
                if (temp_v0 == 1) {
                    arg0->unk_10 = 1;
                }

                if (temp_v0 == 3) {
                    arg0->unk_10 = 3;
                }
            }
        }
    }
}

void func_82F0ACC4(unk_D_82F210E0* arg0) {
    unk_D_82F20A40_00E* temp_v1;
    s32 i;

    arg0->unk_02--;

    for (i = 0; i < 2; i++) {
        arg0->unk_14[i].unk_00 = ((i * 0x118) - ((arg0->unk_02 * 0) / 10)) + 0x50;
        arg0->unk_14[i].unk_02 = 0xB4 - ((arg0->unk_02 * 0x54) / 10);
        arg0->unk_14[i].unk_04 = 0xC8 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_14[i].unk_06 = -((arg0->unk_02 * -0xA8) / 10);
    }

    temp_v1 = &arg0->unk_24;
    if (arg0->unk_04 & 1) {
        if ((temp_v1->unk_04 != 0x13C) || (temp_v1->unk_06 != 0)) {
            temp_v1->unk_00 = 0xA2 - ((arg0->unk_02 * 0) / 10);
            temp_v1->unk_02 = 0x144 - ((arg0->unk_02 * 0x2E) / 10);
            temp_v1->unk_04 = 0x13C - ((arg0->unk_02 * 0) / 10);
            temp_v1->unk_06 = -((arg0->unk_02 * -0x70) / 10);
        }
    } else if ((temp_v1->unk_04 != 0xE8) || (temp_v1->unk_06 != 0)) {
        temp_v1->unk_00 = 0xCC - ((arg0->unk_02 * 0) / 10);
        temp_v1->unk_02 = 0x154 - ((arg0->unk_02 * 0x38) / 10);
        temp_v1->unk_04 = 0xE8 - ((arg0->unk_02 * 0) / 10);
        temp_v1->unk_06 = -((arg0->unk_02 * -0x70) / 10);
    }

    temp_v1 = &arg0->unk_2C;
    if ((arg0->unk_2C.unk_04 != 0x210) || (arg0->unk_2C.unk_06 != 0)) {
        temp_v1->unk_00 = 0x38 - ((arg0->unk_02 * 0) / 10);
        temp_v1->unk_02 = 0x1A4 - ((arg0->unk_02 * 0x14) / 10);
        temp_v1->unk_04 = 0x210 - ((arg0->unk_02 * 0) / 10);
        temp_v1->unk_06 = -((arg0->unk_02 * -0x28) / 10);
    }

    temp_v1 = &arg0->unk_34;
    if ((arg0->unk_34.unk_04 != 0xE8) || (arg0->unk_34.unk_06 != 0)) {
        temp_v1->unk_00 = 0xCC - ((arg0->unk_02 * 0) / 10);
        temp_v1->unk_02 = 0x150 - ((arg0->unk_02 * 0x1C) / 10);
        temp_v1->unk_04 = 0xE8 - ((arg0->unk_02 * 0) / 10);
        temp_v1->unk_06 = -((arg0->unk_02 * -0x38) / 10);
    }

    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 0;
        arg0->unk_02 = 0;
        arg0->unk_04 = 0;
    }
}

void func_82F0B2A4(s16 arg0, s16 arg1, s16 arg2) {
    UNUSED s32 pad;
    u16* img = func_82F05198(arg0);

    gDPLoadTextureBlock(gDisplayListHead++, img, G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 40, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg1, arg2, 0x3C, 0x3C, 0, 0, 0x2AB, 0x2AB, 0);
}

void func_82F0B3E0(unk_D_82F210E0* arg0) {
    unk_D_82F20A40_00E* var_s0;
    s32 sp74[2];
    unk_func_82F00838_sp30_00C* temp_s3;
    s32 i;

    if (arg0->unk_12 > 0) {
        arg0->unk_12--;
    }

    for (i = 0; i < 2; i++) {
        var_s0 = &arg0->unk_14[i];
        if ((var_s0->unk_04 != 0xC8) || (var_s0->unk_06 != 0)) {
            func_82F022DC(var_s0->unk_00, var_s0->unk_02, var_s0->unk_04, var_s0->unk_06);
        }
    }

    for (i = 0; i < 2; i++) {
        if ((arg0->unk_14[i].unk_04 == 0xC8) && (arg0->unk_14[i].unk_06 == 0xA8)) {
            sp74[i] = 1;
        } else {
            sp74[i] = 0;
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    for (i = 0; i < 2; i++) {
        var_s0 = &arg0->unk_14[i];
        if (sp74[i] != 0) {
            func_8001C604(var_s0->unk_00, var_s0->unk_02, var_s0->unk_04, var_s0->unk_06, 0x32, 0x32, 0x96, 0xFF);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 2; i++) {
        if (sp74[i] != 0) {
            func_82F0B2A4(i, arg0->unk_14[i].unk_00 + 0x46, arg0->unk_14[i].unk_02 + 0xA);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);

    for (i = 0; i < 2; i++) {
        if (sp74[i] != 0) {
            temp_s3 = D_82F21120[i];
            var_s0 = &arg0->unk_14[i];
            func_8001EBE0(4, 0);
            func_8001F1E8(var_s0->unk_00 + 0xA, var_s0->unk_02 + 0x4A, "No.");
            func_8001EBE0(4, 0);
            func_8001F1E8(var_s0->unk_00 + 0x26, var_s0->unk_02 + 0x4A, "%03d", temp_s3->unk_00);
            func_8001EBE0(8, 0);
            func_8001F1E8(var_s0->unk_00 + 0x62, var_s0->unk_02 + 0x46, func_82F00020(temp_s3->unk_00));
            func_8001EBE0(8, 0);
            func_8001F1E8(var_s0->unk_00 + 0x10, var_s0->unk_02 + 0x5E, func_8002D7C0(NULL, 0, D_82F13B70, 0x14));
            func_8001F1E8(var_s0->unk_00 + 0x46, var_s0->unk_02 + 0x5E, "/%s", temp_s3->unk_30);
            func_8001F1E8(var_s0->unk_00 + 0x10, var_s0->unk_02 + 0x74, func_8002D7C0(NULL, 0, D_82F13B70, 0x15));
            func_8001F1E8(var_s0->unk_00 + 0x46, var_s0->unk_02 + 0x74, "/%s", temp_s3->unk_3B);
            func_8001F1E8(var_s0->unk_00 + 0x10, var_s0->unk_02 + 0x8A, "ID%05d", temp_s3->unk_0E);
        }
    }

    func_8001F444();
}

void func_82F0B7B4(unk_D_82F210E0* arg0) {
    s32 i;
    unk_D_82F20A40_00E* var_s4 = &arg0->unk_24;
    Color_RGB8* var_v0;
    s16 temp_ft3;
    s16 arg2;
    Color_RGB8 sp64 = { 0x1E, 0x1E, 0x82 };
    Color_RGB8 sp60 = { 0x64, 0x1E, 0x1E };

    if (arg0->unk_04 & 1) {
        if ((var_s4->unk_04 == 0x13C) && (var_s4->unk_06 == 0)) {
            return;
        }
    } else if ((var_s4->unk_04 == 0xE8) && (var_s4->unk_06 == 0)) {
        return;
    }

    if (arg0->unk_04 & 1) {
        var_v0 = &sp60;
    } else {
        var_v0 = &sp64;
    }

    if ((var_s4->unk_04 >= 0xE) && (var_s4->unk_06 >= 0xE)) {
        func_8002053C(var_s4->unk_00, var_s4->unk_02, var_s4->unk_04, var_s4->unk_06, var_v0, var_v0);
    }

    if (arg0->unk_04 & 1) {
        if ((var_s4->unk_04 != 0x13C) || (var_s4->unk_06 != 0x70)) {
            return;
        }
    } else if ((var_s4->unk_04 != 0xE8) || (var_s4->unk_06 != 0x70)) {
        return;
    }

    {
        static s16 D_82F13F78 = 0;

        temp_ft3 = SINS(D_82F13F78) * 3.0f;

        if (arg0->unk_04 & 1) {
            func_800207FC(var_s4->unk_00 + temp_ft3 + 0x10, var_s4->unk_02 + (D_82F21128 * 0x1C) + 0x14);
        } else {
            func_800207FC(var_s4->unk_00 + temp_ft3 + 0x18, var_s4->unk_02 + (D_82F21128 * 0x1C) + 0x32);
        }

        func_8001F3F4();
        func_8001EBE0(0x10, 0);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);

        if (arg0->unk_04 & 1) {
            char* sp54[3];
            for (i = 0; i < 3; i++) {
                sp54[0] = func_8002D7C0(NULL, 0, D_82F13B70, 0x1A);
                sp54[1] = func_8002D7C0(NULL, 0, D_82F13B70, 0x1B);
                sp54[2] = func_8002D7C0(NULL, 0, D_82F13B70, 0x1C);
                func_8001F1E8(var_s4->unk_00 + 0x38, var_s4->unk_02 + i * 0x1C + 0x10, sp54[i]);
            }
        } else {
            char* temp_v0 = func_8002D7C0(NULL, 0, D_82F13B70, 0x16);
            char* sp48[2];

            arg2 = func_8001F5B0(0, 0, temp_v0);
            func_8001F1E8((var_s4->unk_00 + (var_s4->unk_04 / 2)) - (arg2 / 2), var_s4->unk_02 + 0x10, temp_v0);

            for (i = 0; i < 2; i++) {
                sp48[0] = func_8002D7C0(NULL, 0, D_82F13B70, 0x17);
                sp48[1] = func_8002D7C0(NULL, 0, D_82F13B70, 0x18);
                if (i != D_82F21128) {
                    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
                } else {
                    func_8001F324(0xFF, 0xFF, 0, 0xFF);
                }
                arg2 = func_8001F5B0(0, 0, sp48[i]);
                func_8001F1E8((var_s4->unk_00 + (var_s4->unk_04 / 2)) - (arg2 / 2), var_s4->unk_02 + i * 0x1C + 0x2C,
                              sp48[i]);
            }
        }

        func_8001F444();
        D_82F13F78 += 0x1000;
    }
}

void func_82F0BBE8(unk_D_82F210E0* arg0) {
    s32 sp34;
    unk_D_82F20A40_00E* temp_s0 = &arg0->unk_2C;

    if ((arg0->unk_2C.unk_04 != 0x210) || (arg0->unk_2C.unk_06 != 0)) {
        func_82F037EC(temp_s0->unk_00, temp_s0->unk_02, temp_s0->unk_04, temp_s0->unk_06, 0x1E, 0x1E, 0x82, 0xFF);
        if ((temp_s0->unk_04 == 0x210) && (temp_s0->unk_06 == 0x28)) {
            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            sp34 = func_8001F5B0(0, 0, func_8002D7C0(NULL, 0, D_82F13B70, 0x1D)) / 2;
            func_8001F1E8((temp_s0->unk_00 + (temp_s0->unk_04 / 2)) - sp34, temp_s0->unk_02 + 8,
                          func_8002D7C0(NULL, 0, D_82F13B70, 0x1D));
            func_8001F444();
        }
    }
}

void func_82F0BD38(unk_D_82F210E0* arg0) {
    unk_D_82F20A40_00E* temp_s0 = &arg0->unk_34;
    char* sp40;
    UNUSED s32 pad;
    Color_RGB8 sp38 = { 0x64, 0x1E, 0x1E };

    if ((arg0->unk_34.unk_04 != 0xE8) || (arg0->unk_34.unk_06 != 0)) {
        if ((temp_s0->unk_04 >= 0xE) && (temp_s0->unk_06 >= 0xE)) {
            func_8002053C(temp_s0->unk_00, temp_s0->unk_02, temp_s0->unk_04, temp_s0->unk_06, &sp38, &sp38);
        }

        if ((temp_s0->unk_04 == 0xE8) && (temp_s0->unk_06 == 0x38)) {
            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            sp40 = func_8002D7C0(NULL, 0, D_82F13B70, 0x1E);
            func_8001F1E8((temp_s0->unk_00 + (temp_s0->unk_04 / 2)) - (func_8001F5B0(0, 0, sp40) / 2),
                          temp_s0->unk_02 + 0x10, sp40);
            func_8001F444();
        }
    }
}

void func_82F0BE7C(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    Color_RGB8 sp24 = { 0x58, 0x08, 0x00 };
    Color_RGB8 sp20 = { 0x58, 0x08, 0x00 };

    func_8002053C(arg0, arg1, arg2, arg3, &sp24, &sp20);
}

#ifdef NON_MATCHING
void func_82F0BEF8(unk_D_82F210E0* arg0) {
    static s16 D_82F13F88 = 0;

    s32 pad[2];
    char sp38[64];
    s32 pad2[2];
    unk_func_82F00838_sp30 sp20;

    if (arg0->unk_08 < 2) {
        func_82F0525C(arg0->unk_08, &sp20);
    } else {
        func_82F0525C(arg0->unk_0A, &sp20);
    }

    if (arg0->unk_10 == -1) {
        return;
    }

    func_82F0BE7C(0x6E, 0x72, 0x1A4, 0x114);
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);

    switch (arg0->unk_10) {
        case 0:
            func_8001F470();
            func_8001F36C(0xFF, 0xF1, 0x78, 0xFF);
            func_8001F1E8(0xEC, 0xA8, func_8002D7C0(NULL, 0, D_82F13B70, 0x1F));
            func_8001F4C4();
            break;

        case 2:
            func_8001F470();
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F36C(0xFF, 0xF1, 0x78, 0xFF);
            // func_8002D600(1, (((((((((tmp) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) &
            // 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) &
            // 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF);
            func_8002D600(1, sp20.unk_02 + 1);
            func_8001F1E8(0xB0, 0x90, func_8002D7C0(sp38, sizeof(sp38), D_82F13B70, 0x20));
            func_8001F4C4();
            break;

        case 3:
            func_8001F470();
            func_8001F36C(0xFF, 0xF1, 0x78, 0xFF);
            func_8001F1E8(0x80, 0x90, func_8002D7C0(NULL, 0, D_82F13B70, 0x21));
            func_8001F4C4();
            break;
    }

    if (arg0->unk_10 != 0) {
        func_8001F470();
        func_8001F36C(0xFF, 0xF1, 0x78, 0xFF);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F3B4(0x24);
        func_8001F1E8(0x80, 0xF0, func_8002D7C0(NULL, 0, D_82F13B70, 0x22));
    }

    func_8001F444();
    D_82F13F88 += 0x800;
}
#else
static s16 D_82F13F88 = 0;
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/41/fragment41_291D60/func_82F0BEF8.s")
#endif

s32 func_82F0C16C(void) {
    return D_82F210E0.unk_00;
}

s32 func_82F0C178(void) {
    return D_82F2112C;
}

s32 func_82F0C184(void) {
    return D_82F21130;
}

void func_82F0C190(void) {
    unk_D_82F210E0* ptr = &D_82F210E0;
    s32 i;

    ptr->unk_00 = 0;
    ptr->unk_02 = 0;
    ptr->unk_04 = 0;

    for (i = 0; i < 2; i++) {
        D_82F210E0.unk_14[i].unk_00 = D_82F210E0.unk_14[i].unk_02 = 0;
        D_82F210E0.unk_14[i].unk_04 = 0xC8;
        D_82F210E0.unk_14[i].unk_06 = 0;
    }

    ptr->unk_24.unk_00 = 0;
    ptr->unk_24.unk_04 = 0xE8;
    ptr->unk_24.unk_06 = 0;
    ptr->unk_2C.unk_00 = 0;
    ptr->unk_2C.unk_04 = 0x210;
    ptr->unk_2C.unk_06 = 0;
    ptr->unk_34.unk_00 = 0;
    ptr->unk_34.unk_04 = 0xE8;
    ptr->unk_34.unk_06 = 0;

    ptr->unk_24.unk_02 = 0;
    ptr->unk_2C.unk_02 = ptr->unk_34.unk_02 = 0;

    for (i = 0; i < 2; i++) {
        D_82F21120[i] = NULL;
    }
}

void func_82F0C254(void) {
    unk_D_82F210E0* ptr = &D_82F210E0;

    if (ptr->unk_00 == 0) {
        return;
    }

    switch (ptr->unk_00) {
        case 1:
            func_82F0A23C(&D_82F210E0);
            break;

        case 2:
            func_82F0A5F8(&D_82F210E0);
            break;

        case 3:
            func_82F0A804(&D_82F210E0);
            break;

        case 4:
            func_82F0A850(&D_82F210E0);
            break;

        case 5:
            func_82F0A950(&D_82F210E0);
            break;

        case 6:
            func_82F0AA50(&D_82F210E0);
            break;

        case 7:
            func_82F0AB68(&D_82F210E0);
            break;

        case 8:
            func_82F0ACC4(&D_82F210E0);
            break;
    }
}

void func_82F0C320(void) {
    static s16 D_82F13F8C[] = { 0x32, 0x14A };

    unk_D_82F210E0* ptr = &D_82F210E0;
    s32 i;

    if (ptr->unk_00 != 0) {
        if (ptr->unk_12 != 0) {
            func_82F0B3E0(&D_82F210E0);
        }

        func_82F0B7B4(&D_82F210E0);
        func_82F0BBE8(&D_82F210E0);
        func_82F0BD38(&D_82F210E0);

        if (ptr->unk_04 & 2) {
            func_82F097D8(0x120, 0x8C);
        }

        if (ptr->unk_04 & 4) {
            for (i = 0; i < 2; i++) {
                func_82F043A4(i, D_82F13F8C[i], 0x2A);
            }
        }
        func_82F0BEF8(&D_82F210E0);
    }
}
