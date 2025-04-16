#include "fragment47.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/232C0.h"
#include "src/2E110.h"
#include "src/30640.h"
#include "src/49790.h"
#include "src/6BC0.h"
#include "src/fragments/61/fragment61.h"

static unk_D_838067F0 D_838067F0;

void func_838024C0(unk_D_83407B18_008* arg0) {
    arg0->unk_02 = D_838067F0.unk_001C;
    arg0->unk_04 = D_838067F0.unk_0020;
    arg0->unk_06 = D_838067F0.unk_0024;
    arg0->unk_08 = D_838067F0.unk_0028;
}

s32 func_838024EC(void) {
    unk_D_838067F0* ptr = &D_838067F0;
    s32 ret;

    if (ptr->unk_0000 == 7) {
        ret = 1;
    } else if (ptr->unk_0000 == 0) {
        ret = -1;
    } else {
        ret = 0;
    }

    return ret;
}

void func_8380252C(s32 arg0, s32 arg1, unk_D_8380565C* arg2) {
    D_838067F0.unk_0000 = 0;
    D_838067F0.unk_0004 = arg0;
    D_838067F0.unk_0008 = arg1;
    D_838067F0.unk_015C = arg2;
}

s32 func_83802548(unk_D_838067F0* arg0, s32 arg1) {
    char sp48[88];
    unk_func_80022C28_ret* var_v0;
    unk_D_838067F0_003C* ptr = &arg0->unk_003C[arg1];
    s32 i;

    i = 0;
    ptr->unk_00 = 0;

    if (arg0->unk_0018 < 4) {
        if (arg1 == 0) {
            var_v0 = func_80022C28(0x20, arg0->unk_0018, 0, 0);
        } else {
            var_v0 = func_80022C28(0x21, arg0->unk_0018, arg1 - 1, 0);
        }

        if (var_v0 != NULL) {
            while (func_80022E18(sp48, 1, var_v0) == 1) {
                ptr->unk_02[ptr->unk_00++] = i++;
            }
            func_80022D8C(var_v0);
        }
    }
    return ptr->unk_00;
}

void func_83802660(unk_D_838067F0* arg0, unk_func_80026268_arg0* arg1) {
    typedef struct unk_func_83802660_sp28 {
        /* 0x00 */ unk_D_800AC910_040 unk_00;
        /* 0x00 */ u16 unk_12;
        /* 0x00 */ char unk_14[11];
    } unk_func_83802660_sp28; // size = 0x12

    unk_func_83802660_sp28 sp28;

    if ((arg0->unk_0018 < 4) && (func_80024F68(arg0->unk_0018) == 7) && (arg1->unk_00.unk_00 == 0x19)) {
        func_80025040(arg0->unk_0018, &sp28);
        _bcopy(arg1->unk_46, sp28.unk_14, sizeof(arg1->unk_46));
        sp28.unk_12 = arg1->unk_0E;
        if (func_80022A04(&sp28.unk_12, &sp28) != 0) {
            arg1->unk_52 |= 0x80;
        }
    }
}

s32 func_83802700(unk_D_838067F0* arg0, unk_D_838067F0_0168* arg1, s32 arg2, unk_D_8380565C* arg3) {
    s32 i;
    s32 j;
    unk_D_838067F0_003C* temp_s3;
    s32 var_s4;
    u32 var_s1_3;
    unk_func_80022C28_ret* var_v0;

    var_s4 = 0;

    arg1->unk_2690 = arg0->unk_0018;
    arg1->unk_2692 = arg0->unk_001C;

    for (i = 0; i < 3; i++) {
        arg1->unk_0000[i].unk_004[0].unk_00.unk_00 = 0;
        *(s32*)&arg1->unk_0000[i].unk_000 = 0;
    }

    if (arg0->unk_001C <= 0xC) {
        temp_s3 = &arg0->unk_003C[arg0->unk_001C];

        if (arg0->unk_0018 < 4) {
            if (arg0->unk_001C == 0) {
                var_v0 = func_80022C28(0x20, arg0->unk_0018, 0, 0);
            } else {
                var_v0 = func_80022C28(0x21, arg0->unk_0018, arg0->unk_001C - 1, 0);
            }

            if (var_v0 != NULL) {
                i = arg2 * 3;
                for (j = 0; j < 3; j++) {
                    if (i < temp_s3->unk_00) {
                        if (func_80022DF4(var_v0, temp_s3->unk_02[i++]) != 0) {
                            var_s4 += func_80022E18(arg1->unk_0000[j].unk_004, 1, var_v0);
                        }
                    }
                }

                func_80022D8C(var_v0);
            }
        }
    } else if (arg3 != NULL) {
        s32 var_s1_3 = arg2 * 3;
        for (j = 0; j < 3; j++) {
            if (var_s1_3 < arg3->unk_000) {
                _bcopy(&arg3->unk_004[var_s1_3++], &arg1->unk_0000[var_s4].unk_004[0], 0x54);
                func_800228B0(arg1->unk_0000[var_s4++].unk_004);
            }
        }
    }

    for (i = 0; i < var_s4; i++) {
        func_8001B0DC(&arg1->unk_0000[i].unk_004[1], 0, &arg1->unk_0000[i].unk_004[0]);

        arg1->unk_0000[i].unk_000 = arg0->unk_0018;
        arg1->unk_0000[i].unk_001 = arg0->unk_001C;
        arg1->unk_0000[i].unk_002 = arg2 * 3 + i;
        arg1->unk_0000[i].unk_003 = arg1->unk_0000[i].unk_004[0].unk_00.unk_00;

        arg1->unk_0000[i].unk_004[0].unk_53 = arg2 * 3 + i;
        arg1->unk_0000[i].unk_004[0].unk_52 = (arg0->unk_0018 * 0x10) | arg0->unk_001C;

        func_83802660(arg0, &arg1->unk_0000[i].unk_004[0]);
    }

    return var_s4;
}

s32 func_838029D4(s32 arg0, unk_D_83407B18_008* arg1) {
    unk_D_838067F0* ptr = &D_838067F0;
    unk_D_838067F0_0168* ptr2;
    s32 i;
    s32 temp_lo;
    s32 temp_t2;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    unk_D_838067F0* var_v1;

    if (ptr->unk_0000 != 0) {
        return 0;
    }

    ptr->unk_0000 = 1;
    ptr->unk_000C = ptr->unk_0004;
    ptr->unk_0010 = ptr->unk_0008 + 0x1E0;
    ptr->unk_0014 = 0;
    ptr->unk_0018 = arg0;

    if (arg1 != NULL) {
        ptr->unk_001C = arg1->unk_02;
        ptr->unk_0020 = arg1->unk_04;
        ptr->unk_0024 = arg1->unk_06;
        ptr->unk_0028 = arg1->unk_08;
    } else {
        ptr->unk_001C = 0xD;
        ptr->unk_0020 = 0;
        ptr->unk_0024 = 0;
        ptr->unk_0028 = 0;
    }

    ptr->unk_002C = 0;
    ptr->unk_0030 = 0;
    ptr->unk_0038 = 0;
    ptr->unk_0034 = 8;

    ptr->unk_0160 = &ptr->unk_0168[0];

    for (i = 0; i < 12; i++) {
        ptr->unk_0168[i].unk_2688 = &ptr->unk_0168[(i + 1) % 12];
        ptr->unk_0168[i].unk_268C = &ptr->unk_0168[(i + 11) % 12];
    }

    for (i = 12; i >= 0; i--) {
        if ((func_83802548(&D_838067F0, i) > 0) && (arg1 == NULL)) {
            ptr->unk_001C = i;
        }
    }

    ptr2 = ptr->unk_0160;
    for (i = 0; i < 6; i++) {
        func_83802700(&D_838067F0, ptr2, ptr->unk_0020 + i, ptr->unk_015C);
        ptr2 = ptr2->unk_2688;
    }

    func_80048B90(4);
    return 1;
}

void func_83802C0C(unk_D_838067F0* arg0) {
    arg0->unk_0014++;
    if (arg0->unk_0014 <= 0) {
        arg0->unk_0010 = arg0->unk_0008 + 0x1E0;
    } else if (arg0->unk_0014 == 0xA) {
        arg0->unk_0000 = 2;
        arg0->unk_0014 = 0;
        arg0->unk_0010 = arg0->unk_0008;
    } else {
        arg0->unk_0010 = (arg0->unk_0008 - (arg0->unk_0014 * 0x30)) + 0x1E0;
    }
    arg0->unk_000C = arg0->unk_0004;
}

unk_D_838067F0_0168* func_83802C74(unk_D_838067F0_0168* arg0, s32 arg1) {
    while (arg1-- > 0) {
        arg0 = arg0->unk_2688;
    }
    return arg0;
}

void func_83802C98(unk_D_838067F0* arg0) {
    unk_D_838067F0_0168* ptr = func_83802C74(arg0->unk_0160, arg0->unk_0028);
    unk_func_80026268_arg0* temp_a1 = &ptr->unk_0000[arg0->unk_0024].unk_004[0];

    if (temp_a1->unk_00.unk_00 != 0) {
        arg0->unk_0000 = 7;
        func_8003107C(&D_83407AC8, temp_a1);
        if ((temp_a1->unk_00.unk_00 == 0x19) && (temp_a1->unk_52 & 0x80)) {
            D_83407AC8.unk_02 = 0x99;
        }
        func_80048B90(0x20);
    } else {
        func_80048B90(8);
    }
}

void func_83802D64(unk_D_838067F0* arg0) {
    arg0->unk_0000 = 8;
    arg0->unk_0014 = 0;
    func_80048B90(3);
    func_8380008C(-1);
}

void func_83802D98(unk_D_838067F0* arg0) {
    s32 i;
    s32 var_s0;
    unk_D_838067F0_0168* var_s1;

    var_s0 = (arg0->unk_001C + 1) % 14;
    while (var_s0 < ARRAY_COUNT(arg0->unk_003C) && (arg0->unk_003C[var_s0].unk_00 == 0)) {
        var_s0 = (var_s0 + 1) % 14;
    }

    if (var_s0 != arg0->unk_001C) {
        func_80048B90(0x27);
        arg0->unk_001C = var_s0;
        arg0->unk_0160 = func_83802C74(arg0->unk_0160, 6);
        arg0->unk_0020 = 0;

        var_s1 = arg0->unk_0160;
        for (i = 0; i < 6; i++) {
            func_83802700(arg0, var_s1, arg0->unk_0020 + i, arg0->unk_015C);
            var_s1 = var_s1->unk_2688;
        }

        arg0->unk_002C = 0;
        arg0->unk_0030 = 8;
        arg0->unk_0000 = 3;
    }
}

void func_83802EE8(unk_D_838067F0* arg0) {
    s32 i;
    s32 var_s0;
    unk_D_838067F0_0168* var_s1;

    var_s0 = (arg0->unk_001C + ARRAY_COUNT(arg0->unk_003C)) % 14;
    while (var_s0 < ARRAY_COUNT(arg0->unk_003C) && (arg0->unk_003C[var_s0].unk_00 == 0)) {
        var_s0 = (var_s0 + ARRAY_COUNT(arg0->unk_003C)) % 14;
    }

    if (var_s0 != arg0->unk_001C) {
        func_80048B90(0x27);
        arg0->unk_001C = var_s0;
        arg0->unk_0160 = func_83802C74(arg0->unk_0160, 6);
        arg0->unk_0020 = 0;

        var_s1 = arg0->unk_0160;
        for (i = 0; i < 6; i++) {
            func_83802700(arg0, var_s1, arg0->unk_0020 + i, arg0->unk_015C);
            var_s1 = var_s1->unk_2688;
        }

        arg0->unk_002C = 0;
        arg0->unk_0030 = -8;
        arg0->unk_0000 = 3;
    }
}

void func_83803038(unk_D_838067F0* arg0) {
    if (arg0->unk_0038 == 0) {
        if (arg0->unk_0024 > 0) {
            arg0->unk_0024--;
            arg0->unk_002C = -1;
            arg0->unk_0030 = -4;
            arg0->unk_0000 = 5;
            func_80048B90(1);
        }
        arg0->unk_0038 = arg0->unk_0034;
        arg0->unk_0034 = 2;
    }
}

void func_838030A8(unk_D_838067F0* arg0) {
    if (arg0->unk_0038 == 0) {
        if (arg0->unk_0024 < 2) {
            arg0->unk_0024++;
            arg0->unk_002C = 1;
            arg0->unk_0030 = 4;
            arg0->unk_0000 = 5;
            func_80048B90(1);
        }
        arg0->unk_0038 = arg0->unk_0034;
        arg0->unk_0034 = 2;
    }
}

void func_8380311C(unk_D_838067F0* arg0) {
    if (arg0->unk_0038 == 0) {
        if (arg0->unk_0028 != 0) {
            arg0->unk_0028--;
            arg0->unk_002C = -1;
            arg0->unk_0030 = -4;
            arg0->unk_0000 = 6;
            func_80048B90(1);
        } else if ((arg0->unk_0020 > 0) &&
                   (func_83802700(arg0, arg0->unk_0160->unk_268C, arg0->unk_0020 - 1, arg0->unk_015C) != 0)) {
            arg0->unk_0020 -= 1;
            arg0->unk_0160 = arg0->unk_0160->unk_268C;
            arg0->unk_002C = -1;
            arg0->unk_0030 = -4;
            arg0->unk_0000 = 4;
            func_80048B90(1);
        }
        arg0->unk_0038 = arg0->unk_0034;
        arg0->unk_0034 = 2;
    }
}

void func_838031F0(unk_D_838067F0* arg0) {
    if (arg0->unk_0038 == 0) {
        if (arg0->unk_0028 != 5) {
            arg0->unk_0028++;
            arg0->unk_002C = 1;
            arg0->unk_0030 = 4;
            arg0->unk_0000 = 6;
            func_80048B90(1);
        } else if (func_83802700(arg0, func_83802C74(arg0->unk_0160, 6), arg0->unk_0020 + 6, arg0->unk_015C) != 0) {
            arg0->unk_0020++;
            arg0->unk_0160 = arg0->unk_0160->unk_2688;
            arg0->unk_002C = 1;
            arg0->unk_0030 = 4;
            arg0->unk_0000 = 4;
            func_80048B90(1);
        }
        arg0->unk_0038 = arg0->unk_0034;
        arg0->unk_0034 = 2;
    }
}

void func_838032C8(unk_D_838067F0* arg0) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        func_83802C98(arg0);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        func_83802D64(arg0);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_R)) {
        func_83802D98(arg0);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_L)) {
        func_83802EE8(arg0);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DLEFT)) {
        func_83803038(arg0);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DRIGHT)) {
        func_838030A8(arg0);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DUP)) {
        func_8380311C(arg0);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DDOWN)) {
        func_838031F0(arg0);
    } else {
        arg0->unk_0038 = 0;
        arg0->unk_0034 = 8;
    }
    arg0->unk_000C = arg0->unk_0004;
    arg0->unk_0010 = arg0->unk_0008;
}

void func_838033DC(unk_D_838067F0* arg0) {
    if (arg0->unk_0030 > 0) {
        arg0->unk_002C++;
        if (arg0->unk_002C >= arg0->unk_0030) {
            arg0->unk_0000 = 2;
        }
    } else {
        arg0->unk_002C--;
        if (arg0->unk_0030 >= arg0->unk_002C) {
            arg0->unk_0000 = 2;
        }
    }
    arg0->unk_000C = arg0->unk_0004;
    arg0->unk_0010 = arg0->unk_0008;
}

void func_83803438(unk_D_838067F0* arg0) {
    arg0->unk_0014++;
    if (arg0->unk_0014 == 0xA) {
        arg0->unk_0000 = 0;
        arg0->unk_0010 = arg0->unk_0008 + 0x1E0;
        arg0->unk_0014 = 0;
    } else {
        arg0->unk_0010 = arg0->unk_0008 + (arg0->unk_0014 * 0x30);
    }
    arg0->unk_000C = arg0->unk_0004;
}

void func_83803488(void) {
    unk_D_838067F0* ptr = &D_838067F0;

    if (ptr->unk_0000 != 0) {
        if (ptr->unk_0038 > 0) {
            ptr->unk_0038--;
        }

        switch (ptr->unk_0000) {
            case 1:
                func_83802C0C(ptr);
                break;

            case 2:
                func_838032C8(ptr);
                break;

            case 3:
                func_838033DC(ptr);
                break;

            case 4:
                func_838033DC(ptr);
                break;

            case 5:
                func_838033DC(ptr);
                break;

            case 6:
                func_838033DC(ptr);
                break;

            case 8:
                func_83803438(ptr);
                break;
        }
    }
}

void func_8380355C(s16 arg0, s16 arg1, s16 arg2) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);

    func_8001CF10(arg0, arg1, 0x10, 0x1C, D_20007C0, 0x10, 0);
    func_8001CF10((arg0 + arg2) - 0x10, arg1, 0x10, 0x1C, D_20008A0, 0x10, 0);
    func_8001C330(arg0 + 0x10, arg1, arg2 - 0x20, 0x1C, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_8380369C(s16 arg0, s16 arg1, u8* arg2, s16 arg3) {
    if (arg3 == 0) {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 150);
    } else {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    }
    func_8001C6AC(arg0, arg1, 0x24, 0x14, arg2, 0x24, 0);
}

void func_83803748(unk_D_838067F0* arg0) {
    s32 temp_s0 = arg0->unk_000C - 0x2C;
    s32 sp40 = arg0->unk_0010 - 0x20;

    func_8380355C(temp_s0, sp40, 0x208);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8380369C(temp_s0 + 8, sp40 + 4, D_2001A20, arg0->unk_003C[0].unk_00);
    func_8380369C(temp_s0 + 0x2C, sp40 + 4, D_2002560, arg0->unk_003C[1].unk_00);
    func_8380369C(temp_s0 + 0x50, sp40 + 4, D_2002B00, arg0->unk_003C[2].unk_00);
    func_8380369C(temp_s0 + 0x74, sp40 + 4, D_20030A0, arg0->unk_003C[3].unk_00);
    func_8380369C(temp_s0 + 0x98, sp40 + 4, D_2003640, arg0->unk_003C[4].unk_00);
    func_8380369C(temp_s0 + 0xBC, sp40 + 4, D_2003BE0, arg0->unk_003C[5].unk_00);
    func_8380369C(temp_s0 + 0xE0, sp40 + 4, D_2004180, arg0->unk_003C[6].unk_00);
    func_8380369C(temp_s0 + 0x104, sp40 + 4, D_2004720, arg0->unk_003C[7].unk_00);
    func_8380369C(temp_s0 + 0x128, sp40 + 4, D_2004CC0, arg0->unk_003C[8].unk_00);
    func_8380369C(temp_s0 + 0x14C, sp40 + 4, D_2005260, arg0->unk_003C[9].unk_00);
    func_8380369C(temp_s0 + 0x170, sp40 + 4, D_2005800, arg0->unk_003C[10].unk_00);
    func_8380369C(temp_s0 + 0x194, sp40 + 4, D_2005DA0, arg0->unk_003C[11].unk_00);
    func_8380369C(temp_s0 + 0x1B8, sp40 + 4, D_2006340, arg0->unk_003C[12].unk_00);
    func_8380369C(temp_s0 + 0x1DC, sp40 + 4, D_2001FC0, 0x97);

    if (arg0->unk_0000 != 3) {
        func_8001C6AC(temp_s0 + 4 + (arg0->unk_001C * 0x24), sp40, 0x2C, 0xE, D_2001080, 0x2C, 0);
        func_8001C6AC(temp_s0 + 4 + (arg0->unk_001C * 0x24), sp40 + 0xE, 0x2C, 0xE, D_2001550, 0x2C, 0);
    }
}

void func_83803A80(s32 arg0, s32 arg1, unk_D_838067F0* arg2) {
    static s16 D_83805540 = 0;

    s32 sp5C;
    s32 temp_a3;
    s32 var_v1;

    temp_a3 = arg2->unk_0020 + arg2->unk_0028;
    if (arg2->unk_001C < ARRAY_COUNT(arg2->unk_003C)) {
        var_v1 = (arg2->unk_003C[arg2->unk_001C].unk_00 + 2) / 3;
    } else {
        var_v1 = (arg2->unk_015C->unk_000 + 2) / 3u;
    }

    if (var_v1 < 6) {
        var_v1 = 6;
    }

    if ((arg2->unk_0000 == 4) || (arg2->unk_0000 == 6)) {
        if (arg2->unk_002C > 0) {
            sp5C = ((((temp_a3 * 4) + arg2->unk_002C) * 0xF0) - 0x3C0) / ((var_v1 * 4) - 4);
        } else {
            sp5C = ((((temp_a3 * 4) + arg2->unk_002C) * 0xF0) + 0x3C0) / ((var_v1 * 4) - 4);
        }
    } else {
        sp5C = (temp_a3 * 0xF0) / (var_v1 - 1);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    func_8001C560(arg0, arg1, 0x18, 0x124, 0x3C, 0x3C, 0xA0);

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, 130, 130, 220, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 60, 60, 150, 255);

    func_8001CADC(arg0 + 4, arg1 + 0x20, 0x10, 8, D_200A200, 0x10, 0);
    func_8001CADC(arg0 + 4, arg1 + 0x118, 0x10, 8, D_200A280, 0x10, 0);
    func_8001C330(arg0 + 4, arg1 + 0x28, 0x10, 0xF0, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (D_83805540 < 4) {
        func_8001C6AC(arg0, arg1 + sp5C + 0x1C, 0x18, 0x18, D_200A300, 0x18, 0);
    } else {
        func_8001C6AC(arg0, arg1 + sp5C + 0x1C, 0x18, 0x18, D_200A780, 0x18, 0);
    }

    if (arg2->unk_0000 == 2) {
        D_83805540 = (D_83805540 + 1) % 8;
    }
}

s32 func_83803E94(unk_D_838067F0* arg0) {
    s32 i;
    s32 var_v1 = 1;

    for (i = 0; i < 13; i++) {
        if (arg0->unk_003C[i].unk_00 != 0) {
            var_v1++;
        }
    }

    return var_v1;
}

s32 func_83803F04(unk_D_838067F0_0168* arg0) {
    s32 ret;

    switch (arg0->unk_2692) {
        case 0:
            ret = 0;
            break;

        case 13:
            ret = 2;
            break;

        default:
            ret = 1;
            break;
    }
    return ret;
}

void func_83803F34(s32 arg0, s32 arg1, unk_D_838067F0_0168* arg2) {
    static Color_RGB8 D_83805544[] = {
        { 0xB4, 0x3C, 0x3C },
        { 0xBE, 0x96, 0x32 },
        { 0xAA, 0x3C, 0x96 },
    };
    static Color_RGB8 D_83805550[] = {
        { 0x3C, 0x14, 0x14 },
        { 0x46, 0x32, 0x1E },
        { 0x50, 0x28, 0x3C },
    };

    char sp60[0x100];
    char* var_v0;
    s32 tmp;
    s32 temp_v0 = func_83803F04(arg2);

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, D_83805544[temp_v0].r, D_83805544[temp_v0].g, D_83805544[temp_v0].b, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, D_83805550[temp_v0].r, D_83805550[temp_v0].g, D_83805550[temp_v0].b, 255);

    func_8001CADC(arg0, arg1, 8, 0x1C, &D_2000980, 8, 0);
    func_8001CADC(arg0 + 0x184, arg1, 8, 0x1C, &D_2000A60, 8, 0);
    func_8001C330(arg0 + 8, arg1, 0x17C, 0x1C, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(8, 0);

    switch (arg2->unk_2692) {
        case 0:
            var_v0 = func_83402374(0x42);
            break;

        case 13:
            var_v0 = func_834023CC(0x13);
            break;

        default:
            func_8002D600(2, arg2->unk_2692);
            var_v0 = func_834023A4(&sp60, 0x100, 0x43);
            break;
    }

    tmp = func_8001F5B0(8, 0, var_v0) / 2;
    func_8001F1E8((arg0 - tmp) + 0xC6, arg1 + 4, var_v0);
    func_8001F444();
}

void func_8380419C(s32 arg0, s32 arg1, unk_D_838067F0_0168* arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (arg2->unk_0000[i].unk_004[0].unk_00.unk_00 != 0) {
            func_84200420(arg0 + i * 0x84, arg1, 0x84, 0x2C, 0x64, 0x64, 0xC8, 0xFF);
        } else {
            func_84200420(arg0 + i * 0x84, arg1, 0x84, 0x2C, 0x3C, 0x3C, 0xA0, 0xFF);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 3; i++) {
        if (arg2->unk_0000[i].unk_004[0].unk_00.unk_00 != 0) {
            func_8001C6AC(arg0 + (i * 0x84) + 2, arg1 + 2, 0x28, 0x28, &arg2->unk_0000[i].unk_004[1].unk_00.unk_00,
                          0x28, 0);
        }
    }

    func_8001F3F4();

    for (i = 0; i < 3; i++) {
        if (arg2->unk_0000[i].unk_004[0].unk_00.unk_00 != 0) {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001EBE0(4, 0);
            func_8001F1E8(arg0 + (i * 0x84) + 0x2C, arg1 + 5, arg2->unk_0000[i].unk_004[0].unk_30);
            func_8001EBE0(4, 0);
            func_8001F1E8(arg0 + (i * 0x84) + 0x2C, arg1 + 0x17, "L%d", arg2->unk_0000[i].unk_004[0].unk_24);
        }
    }

    func_8001F444();
}

#ifdef NON_MATCHING
void func_838043F8(s32 arg0) {
    unk_D_838067F0* ptr = &D_838067F0;
    s32 i;
    s32 spC4 = ptr->unk_000C;
    s32 spC0 = ptr->unk_0010;
    unk_D_838067F0_0168* var_s2;

    if ((ptr->unk_0000 == 0) || (arg0 == 0)) {
        return;
    }

    func_83803748(&D_838067F0);
    func_842001B8(spC4, spC0, 0x1B4, 0x12C);
    func_83803A80(spC4 + 4, spC0 + 4, &D_838067F0);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (func_83803E94(&D_838067F0) >= 2) {
        func_8001C6AC(spC4 - 0x32, spC0 + 8, 0x30, 0x18, D_2007E00, 0x30, 0);
        func_8001C6AC(spC4 - 0x32, spC0 + 0x20, 0x30, 0x18, D_2008700, 0x30, 0);
        func_8001C6AC(spC4 + 0x1BA, spC0 + 8, 0x30, 0x18, D_2009000, 0x30, 0);
        func_8001C6AC(spC4 + 0x1BA, spC0 + 0x20, 0x30, 0x18, D_2009900, 0x30, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    func_8001C560(spC4 + 0x1C, spC0 + 4, 8, 0x124, 0x32, 0x32, 0x32);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    if (ptr->unk_0000 == 3) {
        s32 var_s0;
        s32 temp_s2_2 = spC4 - ((ptr->unk_002C * 0x194) / 8);

        if (ptr->unk_0030 > 0) {
            var_s0 = 0x194;
        } else {
            var_s0 = -0x194;
        }

        func_800060E0(&gDisplayListHead, spC4 + 0x24, spC0 + 4, 0x18C, 0x124);
        func_83803F34(temp_s2_2 + 0x24, spC0 + 4, ptr->unk_0160->unk_268C);
        func_83803F34((var_s0 + temp_s2_2) + 0x24, spC0 + 4, ptr->unk_0160);

        gSPDisplayList(gDisplayListHead++, D_8006F518);
        gDPLoadTextureBlock(gDisplayListHead++, D_2000C40, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 4, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        func_8001C330(temp_s2_2 + 0x1B0, spC0 + 4, 8, 0x124, 0, 0, 0x400, 0, 0);
        func_8001C330((var_s0 + temp_s2_2) + 0x1B0, spC0 + 4, 8, 0x124, 0, 0, 0x400, 0, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        var_s2 = ptr->unk_0160;
        for (i = 0; i < 6; i++) {
            func_8380419C((var_s0 + temp_s2_2) + 0x24, spC0 + 0x20 + i * 0x2C, var_s2);
            var_s2 = var_s2->unk_2688;
        }

        for (i = 0; i < 6; i++) {
            func_8380419C(temp_s2_2 + 0x24, spC0 + 0x20 + i * 0x2C, var_s2);
            var_s2 = var_s2->unk_2688;
        }

        func_800060E0(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
    } else if (ptr->unk_0000 == 4) {
        s32 sp80 = spC0 - ((ptr->unk_002C * 0x2C) / 4);
        s32 pad[2];

        func_83803F34(spC4 + 0x24, spC0 + 4, ptr->unk_0160);
        func_800060E0(&gDisplayListHead, spC4 + 0x24, spC0 + 0x20, 0x18C, 0x108);
        if (ptr->unk_0030 > 0) {
            var_s2 = ptr->unk_0160->unk_268C;
            for (i = 0; i < 7; i++) {
                func_8380419C(spC4 + 0x24, sp80 + 0x20 + i * 0x2C, var_s2);
                var_s2 = var_s2->unk_2688;
            }
        } else {
            var_s2 = ptr->unk_0160;
            for (i = 0; i < 7; i++) {
                func_8380419C(spC4 + 0x24, sp80 - 0xC + i * 0x2C, var_s2);
                var_s2 = var_s2->unk_2688;
            }
        }
        func_800060E0(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
    } else {
        func_83803F34(spC4 + 0x24, spC0 + 4, ptr->unk_0160);
        var_s2 = ptr->unk_0160;
        for (i = 0; i < 6; i++) {
            func_8380419C(spC4 + 0x24, spC0 + 0x20 + i * 0x2C, var_s2);
            var_s2 = var_s2->unk_2688;
        }
    }

    if (ptr->unk_0000 == 6) {
        s32 var_v0 = (ptr->unk_0024 * 0x84) + 0x24;
        s32 var_v1 = (ptr->unk_0028 * 0x2C) + 0x20;

        if (ptr->unk_002C > 0) {
            var_v1 += ((ptr->unk_002C * 0x2C) / 4) - 0x2C;
        } else {
            var_v1 += ((ptr->unk_002C * 0x2C) / 4) + 0x2C;
        }
        func_84200738(spC4 + var_v0, spC0 + var_v1, 0x84, 0x2C);
    } else if (ptr->unk_0000 == 5) {
        s32 var_v0 = (ptr->unk_0024 * 0x84) + 0x24;
        s32 var_v1 = (ptr->unk_0028 * 0x2C) + 0x20;

        if (ptr->unk_002C > 0) {
            var_v0 += ((ptr->unk_002C * 0x84) / 4) - 0x84;
        } else {
            var_v0 += ((ptr->unk_002C * 0x84) / 4) + 0x84;
        }
        func_84200738(spC4 + var_v0, spC0 + var_v1, 0x84, 0x2C);
    } else {
        s32 var_v0 = (ptr->unk_0024 * 0x84) + 0x24;
        s32 var_v1 = (ptr->unk_0028 * 0x2C) + 0x20;

        func_84200738(spC4 + var_v0, spC0 + var_v1, 0x84, 0x2C);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_2AFDB0/func_838043F8.s")
#endif
