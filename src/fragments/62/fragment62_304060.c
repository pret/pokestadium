#include "fragment62.h"
#include "src/17300.h"
#include "src/F420.h"

typedef struct unk_D_843859E0 {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ f32 unk_0C;
} unk_D_843859E0; // size = 0x10

static unk_D_843859E0 D_843859E0[] = {
    {
        0x00,
        2002.1199951171875f,
        1367,
        -20914,
        50.0f,
    },
    {
        0x01,
        1693.1199951171875f,
        183,
        -11871,
        50.0f,
    },
    {
        0x02,
        1934.97998046875f,
        1217,
        8182,
        50.0f,
    },
    {
        0x03,
        1733.780029296875f,
        397,
        6520,
        50.0f,
    },
    {
        0x04,
        1102.3900146484375f,
        1577,
        -3562,
        50.0f,
    },
    {
        0x05,
        1425.7900390625f,
        2285,
        -5775,
        50.0f,
    },
    {
        0x06,
        871.3599853515625f,
        1825,
        -8898,
        50.0f,
    },
    {
        0x07,
        1170.8199462890625f,
        4982,
        -6725,
        50.0f,
    },
    {
        0x11,
        1645.5699462890625f,
        7861,
        -122,
        50.0f,
    },
    {
        0x01,
        1741.530029296875f,
        6993,
        -6029,
        50.0f,
    },
    {
        0x06,
        1608.3199462890625f,
        6419,
        -16201,
        50.0f,
    },
    {
        0x00,
        1122.8599853515625f,
        2584,
        -14668,
        50.0f,
    },
    {
        0x00,
        1667.239990234375f,
        5360,
        4438,
        50.0f,
    },
    {
        0x00,
        1315.9599609375f,
        3001,
        -7883,
        50.0f,
    },
    {
        0x00,
        1575.4300537109375f,
        5834,
        10901,
        50.0f,
    },
    {
        0x00,
        719.8599853515625f,
        3047,
        -16384,
        50.0f,
    },
    {
        0x00,
        939.3900146484375f,
        2300,
        0,
        50.0f,
    },
    {
        0x01,
        560.239990234375f,
        773,
        -8863,
        50.0f,
    },
    {
        0x01,
        2002.1199951171875f,
        1367,
        -20914,
        30.0f,
    },
    {
        0x01,
        2002.1199951171875f,
        1367,
        -20914,
        30.0f,
    },
};

s32 func_843197A0(void) {
    if (((func_84307C04(D_84390010[0]) + func_84307C04(D_84390010[1])) <= 85.0f) &&
        (func_84307BAC(D_84390010[0]) == 0.0f) && (func_84307BAC(D_84390010[1]) == 0.0f) &&
        (D_84390010[0]->unk_000.unk_024.y == 0.0f) && (D_84390010[1]->unk_000.unk_024.y == 0.0f)) {
        return 1;
    }
    return 0;
}

s32 func_84319878(UNUSED unk_D_84390010* arg0, unk_D_86002F34_00C* arg1) {
    unk_D_84390010_654* ptr = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;

    if ((ptr->unk_2D == 0x10) || ((ptr->unk_34 & 0x4000) != 0)) {
        func_8431A4C4(arg1);
        return 1;
    }
    return 0;
}

s32 func_843198EC(UNUSED unk_D_84390010* arg0, UNUSED unk_D_86002F34_00C* arg1) {
    unk_D_84390010_654* ptr = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;
    s32 idx = D_84390240.unk_00->unk_2C == 0;
    unk_D_84390010_654* ptr2 = &D_84390010[idx]->unk_654;

    if ((ptr->unk_34 & 0x4000) || (ptr2->unk_34 & 0x4000)) {
        return 1;
    }
    return 0;
}

void func_8431995C(unk_D_86002F34_00C* arg0) {
    func_8431AE5C();
    arg0->unk_24.fovy = 50.0f;
    if (func_843197A0() != 0) {
        func_8431BB24(arg0, D_84385B9C, 0, 0, 0.0f, 0.0f);
        func_8431BC38(arg0, D_84385B9C, 0x5B0, 0, 550.0f, 0.0f);
    } else {
        func_8431BB24(arg0, D_84385B90, 0, 0, 0.0f, 0.0f);
        func_8431BC38(arg0, D_84385B90, 0x5B0, 0, 550.0f, 0.0f);
    }
    arg0->unk_60.eye.z *= 0.6;
    D_84390240.unk_00->unk_20++;
}

void func_84319AE8(unk_D_86002F34_00C* arg0) {
    func_8431AE5C();
    arg0->unk_24.fovy = 30.0f;
    if (func_843197A0() != 0) {
        func_8431BB24(arg0, D_84385B9C, 0, 0, 0.0f, 0.0f);
        func_8431BC38(arg0, D_84385B9C, 0x1A4E, 0, 1000.0f, 0.0f);
    } else {
        func_8431BB24(arg0, D_84385B90, 0, 0, 0.0f, 0.0f);
        func_8431BC38(arg0, D_84385B90, 0x1A4E, 0, 1000.0f, 0.0f);
    }
    D_84390240.unk_00->unk_20++;
}

void func_84319C58(unk_D_86002F34_00C* arg0, s32 arg1) {
    UNUSED s32 pad;
    f32 sp50;
    f32 sp4C;
    s16 sp4A;
    unk_D_84390010_654* sp44;
    UNUSED s32 pad2;
    u16 sp3E;
    unk_D_84390010* temp_s0;

    sp44 = &D_84390010[arg1]->unk_654;
    func_8431BA5C();
    func_8431AE4C(arg1);
    temp_s0 = D_84390010[D_84390240.unk_00->unk_2C];

    if (func_84319878(temp_s0, arg0) == 0) {
        func_843081F0(temp_s0, &D_84390240.unk_00->unk_D0);
        if (!(sp44->unk_34 & 2)) {
            func_84305760(temp_s0, 1);
        }

        sp50 = func_84308598(temp_s0) * 3.5f;
        sp3E = func_8430C414(3);
        sp50 *= ((func_84308014(temp_s0) * 0.5f * sp3E) + 1.0f);

        if (sp50 > 325.0f) {
            sp50 = 325.0f;
        }

        sp3E = func_8430C414(4);
        sp4C = func_84308548(temp_s0) * sp3E;
        sp4A = func_8430C414(0xB4);

        if (sp44->unk_34 & 0x200) {
            sp4C = 0.0f;
        }

        func_8431BAB4(temp_s0, arg0, D_84390240.unk_00->unk_D0, 0, 0, 0, 0.0f);
        func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, 0x4000 - (sp4A * 0xB6), sp50, sp4C);
        func_8431D5C8(arg0);
        func_8431B858(temp_s0, arg0);

        if (temp_s0->unk_000.unk_01A == 0x5F) {
            arg0->unk_24.fovy = 50.0f;
        } else {
            arg0->unk_24.fovy = 30.0f;
        }
        D_84390240.unk_00->unk_20++;
    }
}

void func_84319F10(unk_D_86002F34_00C* arg0, s32 arg1) {
    UNUSED s32 pad[2];
    unk_D_86B0C160* sp24;
    s32 var_a0;
    unk_D_84390010* temp_s0;

    func_8431BA5C();
    func_8431AE4C(arg1);
    temp_s0 = D_84390010[D_84390240.unk_00->unk_2C];

    if (func_84319878(temp_s0, arg0) == 0) {
        if (temp_s0->unk_654.unk_34 & 0x200) {
            sp24 = &D_84384888[0];
        } else {
            var_a0 = func_8430C414(5);
            if (var_a0 >= 5) {
                var_a0 = 0;
            }
            sp24 = &D_843847EC[var_a0];
        }
        arg0->unk_24.fovy = sp24->unk_30;
        func_843081F0(temp_s0, &D_843901B0.unk_00);
        func_8431D7D8(sp24, arg0, temp_s0);
        func_8431D5D0(arg0, temp_s0, 1);
        func_8431D5C8(arg0);
        D_84390240.unk_00->unk_20++;
    }
}

void func_8431A024(unk_D_86002F34_00C* arg0, s32 arg1) {
    arg0->unk_24.fovy = 30.0f;
    func_8431AE4C(arg1);
    if (func_84319878(D_84390010[arg1], arg0) == 0) {
        func_8431B500(arg0, arg1);
        D_84390240.unk_00->unk_20++;
    }
}

void func_8431A098(unk_D_86002F34_00C* arg0) {
    func_8431AE4C(D_84390240.unk_00->unk_54 - 1);
    if (func_843198EC(D_84390010[D_84390240.unk_00->unk_2C], arg0) != 0) {
        D_84390240.unk_00->unk_54 = 0;
        func_8431A4C4(arg0);
    } else {
        func_8431DC78(arg0, D_84390240.unk_00->unk_2C);
        D_84390240.unk_00->unk_20++;
    }
}

void func_8431A130(unk_D_86002F34_00C* arg0) {
    func_8431AE4C(D_84390240.unk_00->unk_2C);
    D_84390240.unk_00->unk_54 = 0;
    if (func_843198EC(D_84390010[D_84390240.unk_00->unk_2C], arg0) != 0) {
        func_8431A4C4(arg0);
    } else {
        func_8431DC78(arg0, D_84390240.unk_00->unk_2C);
        D_84390240.unk_00->unk_20++;
    }
}

void func_8431A1C8(unk_D_86002F34_00C* arg0) {
    s16 var_v1;

    func_8431AE5C();
    if (D_800AE540.unk_0000 == 0x10) {
        var_v1 = D_843859E0[D_800AE540.unk_0001].unk_00;
        if (D_800AE540.unk_0001 == 7) {
            var_v1 += D_800AE540.unk_0002;
        }
    } else {
        var_v1 = D_843859E0[D_800AE540.unk_0000].unk_00;
        if (D_800AE540.unk_0000 == 7) {
            var_v1 += D_800AE540.unk_0002;
        }
    }
    arg0->unk_24.fovy = D_843859E0[var_v1].unk_0C;
    func_8000E88C(&arg0->unk_60.at, 0.0f, 10.0f, 0.0f);
    func_80010354(&arg0->unk_60.at, &arg0->unk_60.eye, D_843859E0[var_v1].unk_04, D_843859E0[var_v1].unk_08,
                  D_843859E0[var_v1].unk_0A);
    D_84390240.unk_00->unk_20++;
}

void func_8431A2C8(unk_D_86002F34_00C* arg0, s32 arg1) {
    UNUSED s32 pad[5];
    s32 var_v1;
    unk_D_84390010* temp_s0;
    f32 tmp1;
    s16 tmp4;
    s16 tmp3;
    f32 tmp2;

    func_8431AFD0(arg0, 10.0f, 12800.0f);
    arg0->unk_24.fovy = 60.0f;
    func_8431AE4C(arg1);
    temp_s0 = D_84390010[arg1];

    if (func_84319878(temp_s0, arg0) == 0) {
        if ((temp_s0->unk_000.unk_01A == 0x98) || (temp_s0->unk_654.unk_34 & 2)) {
            func_8431A4C4(arg0);
            return;
        }

        if ((temp_s0->unk_000.unk_01A == 0x5F) && (arg1 == 1)) {
            var_v1 = 0x97;
        } else {
            var_v1 = (temp_s0->unk_000.unk_01A - 1) & 0xFF;
        }

        tmp2 = (D_84384580[arg1]->unk_00.y + temp_s0->unk_000.unk_024.y) + D_84384C30[var_v1].z;
        tmp1 = ((D_84384580[arg1]->unk_00.z + D_84384C30[var_v1].y) * temp_s0->unk_4B0) + temp_s0->unk_000.unk_024.x;

        func_8000E88C(&arg0->unk_60.at, tmp1, tmp2, temp_s0->unk_000.unk_024.z);

        tmp1 = D_84384580[D_84390240.unk_00->unk_2C]->unk_00.x * D_84384C30[var_v1].x;
        tmp4 = D_84384580[D_84390240.unk_00->unk_2C]->unk_0C;
        tmp3 = (temp_s0->unk_4B0 * D_84384580[D_84390240.unk_00->unk_2C]->unk_0E) + func_84308190(temp_s0);

        func_80010354(&arg0->unk_60.at, &arg0->unk_60.eye, tmp1, tmp4, tmp3);
        D_84390240.unk_00->unk_20++;
    }
}

void func_8431A4C4(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad[2];
    s32 sp20[] = {
        // D_84385B20
        0x00000000, 0x00000008, 0x00000004, 0x00000014, 0x0000000A,
        0x00000006, 0x00000002, 0x00000016, 0x00000018, 0x000000FF,
    };

    func_8431AFD0(arg0, 20.0f, 12800.0f);
    arg0->unk_24.fovy = 30.0f;
    if ((D_84390240.unk_00->unk_54 != 0) && (func_8431DBEC(arg0) != 0)) {
        D_84390240.unk_00->unk_20 = 0x10;
    } else {
        D_84390240.unk_00->unk_54 = 0;
        if (sp20[D_84390240.unk_00->unk_0C] == 0xFF) {
            D_84390240.unk_00->unk_0C = 0;
        }
        D_84390240.unk_00->unk_20 = sp20[D_84390240.unk_00->unk_0C];
        D_84390240.unk_00->unk_0C++;
    }

    func_843087F8(*D_84390010);
    func_843087F8(D_84390010[1]);
    func_8431AE5C();

    switch (D_84390240.unk_00->unk_20) {
        case 0:
            func_8431995C(arg0);
            break;

        case 2:
            func_84319AE8(arg0);
            break;

        case 4:
            func_84319C58(arg0, 0);
            break;

        case 6:
            func_84319C58(arg0, 1);
            break;

        case 8:
            func_84319F10(arg0, 0);
            break;

        case 10:
            func_84319F10(arg0, 1);
            break;

        case 12:
            func_8431A024(arg0, 0);
            break;

        case 14:
            func_8431A024(arg0, 1);
            break;

        case 16:
            func_8431A098(arg0);
            break;

        case 18:
            func_8431A130(arg0);
            break;

        case 20:
            func_8431A1C8(arg0);
            break;

        case 22:
            func_8431A2C8(arg0, 0);
            break;

        case 24:
            func_8431A2C8(arg0, 1);
            break;
    }
}

void func_8431A718(unk_D_86002F34_00C* arg0) {
    arg0->unk_24.fovy = 50.0f;
    if (func_8431B34C(arg0, 0xB6, 0x78DC) != 0) {
        func_8431A4C4(arg0);
    } else {
        arg0->unk_60.eye.z *= 0.6;
    }
}

void func_8431A780(unk_D_86002F34_00C* arg0) {
    if (func_8431B34C(arg0, 0xB6, 0x78DC) != 0) {
        func_8431A4C4(arg0);
    }
}

void func_8431A7B8(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    unk_D_84390010_654* sp18 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;

    if ((sp18->unk_2D == 0x10) || ((sp18->unk_34 & 0x4000) != 0)) {
        func_8431A4C4(arg0);
        return;
    }

    if (!(sp18->unk_34 & 0x200)) {
        func_8431C784(arg0, D_84390010[D_84390240.unk_00->unk_2C]);
    }

    if ((sp18->unk_34 & 1) || (sp18->unk_34 & 2) || (D_84390010[D_84390240.unk_00->unk_2C]->unk_000.unk_01A == 0x98)) {
        if (func_8431ADAC(0x5A) != 0) {
            func_8431A4C4(arg0);
        }
    } else if (func_800174E4(&D_84390010[D_84390240.unk_00->unk_2C]->unk_000) != 0) {
        func_8431A4C4(arg0);
    }
}

void func_8431A8B0(unk_D_86002F34_00C* arg0) {
    unk_D_84390010* sp1C = D_84390010[D_84390240.unk_00->unk_2C];

    if ((sp1C->unk_654.unk_2D == 0x10) || (sp1C->unk_654.unk_34 & 0x4000)) {
        func_8431A4C4(arg0);
    } else if ((func_8431ADAC(0x5A) != 0) || (func_8431D118(arg0, sp1C, 1, 0) != 0)) {
        func_8431A4C4(arg0);
    }
}

void func_8431A94C(unk_D_86002F34_00C* arg0) {
    unk_D_84390010_654* ptr = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;

    if ((ptr->unk_2D == 0x10) || (ptr->unk_34 & 0x4000)) {
        func_8431A4C4(arg0);
    } else {
        arg0->unk_24.fovy = 60.0f;
        if (func_8431ADAC(0x3C) != 0) {
            func_8431A4C4(arg0);
        }
    }
}

void func_8431A9E0(unk_D_86002F34_00C* arg0) {
    if (func_8431DE30(arg0, D_84390240.unk_00->unk_2C) != 0) {
        s32 idx = D_84390240.unk_00->unk_2C == 0;

        D_84390240.unk_00->unk_2C = idx;
        D_84390240.unk_00->unk_20 = 0x12;
        func_8431A130(arg0);
    }
}

void func_8431AA3C(unk_D_86002F34_00C* arg0) {
    if (func_8431DE30(arg0, D_84390240.unk_00->unk_2C) != 0) {
        func_8431A4C4(arg0);
    }
}

void func_8431AA78(unk_D_86002F34_00C* arg0) {
    if (func_8431ADAC(0x78) != 0) {
        func_8431A4C4(arg0);
    }
}

void func_8431AAAC(unk_D_86002F34_00C* arg0) {
    func_8431AFD0(arg0, 10.0f, 12800.0f);
    arg0->unk_24.fovy = 60.0f;
    if (func_8431ADAC(0x3C) != 0) {
        func_8431A4C4(arg0);
    }
}

void func_8431AAFC(unk_D_86002F34_00C* arg0) {
    if ((D_800AE540.unk_0000 == 0x10) && (D_84390240.unk_00->unk_1C == 1)) {
        func_8430FB68();
    } else if (D_84390240.unk_00->unk_1C == 1) {
        if ((D_84390240.unk_00->unk_30 == 0) && (D_84390010[0]->unk_728.unk_168->unk_1C == 0x17) &&
            (D_84390010[1]->unk_728.unk_168->unk_1C == 0x103)) {
            func_8430FB68();
        } else if ((D_84390240.unk_00->unk_30 == 0) && (D_84390010[0]->unk_728.unk_168->unk_1C < 0xE) &&
                   (D_84390010[1]->unk_728.unk_168->unk_1C >= 0x10D)) {
            func_8430D30C();
        }
    }

    switch (D_84390240.unk_00->unk_20) {
        case 1:
            func_8431A718(arg0);
            break;

        case 3:
            func_8431A780(arg0);
            break;

        case 5:
            func_8431A7B8(arg0);
            break;

        case 7:
            func_8431A7B8(arg0);
            break;

        case 9:
            func_8431A8B0(arg0);
            break;

        case 11:
            func_8431A8B0(arg0);
            break;

        case 13:
            func_8431A94C(arg0);
            break;

        case 15:
            func_8431A94C(arg0);
            break;

        case 17:
            func_8431A9E0(arg0);
            break;

        case 19:
            func_8431AA3C(arg0);
            break;

        case 21:
            func_8431AA78(arg0);
            break;

        case 23:
            func_8431AAAC(arg0);
            break;

        case 25:
            func_8431AAAC(arg0);
            break;

        case 50:
            func_8431A4C4(arg0);
            break;
    }
}
