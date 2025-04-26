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

s16 D_8423E580;
Controller* D_8423E584;
s16 D_8423E588;
s16 D_8423E58A;

s16 D_84211700 = 0;
unk_D_84211704 D_84211704[] = {
    {
        132,
        300,
        376,
        136,
        0,
        4,
        0,
        8481,
        0x0374,
    },
    {
        132,
        300,
        376,
        136,
        0,
        1,
        0,
        8481,
        0x0002,
    },
    {
        132,
        300,
        376,
        136,
        0,
        1,
        0,
        26907,
        0x0002,
    },
    {
        132,
        300,
        376,
        136,
        0,
        1,
        0,
        -32503,
        0x0001,
    },
    {
        210,
        300,
        220,
        108,
        0,
        3,
        0,
        8481,
        0x006C,
    },
    {
        210,
        150,
        220,
        108,
        0,
        3,
        0,
        8481,
        0x006C,
    },
    {
        210,
        300,
        290,
        108,
        0,
        3,
        2,
        -32503,
        0x0052,
    },
    {
        210,
        150,
        290,
        108,
        0,
        3,
        2,
        -32503,
        0x0052,
    },
    {
        110,
        300,
        420,
        92,
        0,
        1,
        0,
        26907,
        0x0002,
    },
    {
        210,
        300,
        290,
        82,
        0,
        2,
        0,
        8481,
        0x000A,
    },
    {
        132,
        300,
        376,
        136,
        0,
        3,
        0,
        8481,
        0x0052,
    },
    {
        70,
        320,
        500,
        92,
        0,
        1,
        0,
        26907,
        0x0002,
    },
    {
        160,
        320,
        320,
        82,
        0,
        2,
        0,
        8481,
        0x000A,
    },
    {
        110,
        300,
        420,
        136,
        0,
        1,
        0,
        -32503,
        0x0002,
    },
    {
        110,
        300,
        420,
        136,
        0,
        1,
        0,
        -32503,
        0x0002,
    },
    {
        110,
        300,
        420,
        136,
        0,
        1,
        0,
        -32503,
        0x0002,
    },
    {
        132,
        180,
        376,
        92,
        -22,
        1,
        0,
        26889,
        0x0002,
    },
    {
        120,
        160,
        400,
        64,
        0,
        1,
        0,
        26889,
        0x0002,
    },
    {
        120,
        160,
        400,
        64,
        0,
        1,
        0,
        26889,
        0x0002,
    },
    {
        210,
        300,
        290,
        82,
        0,
        2,
        1,
        8481,
        0x000A,
    },
};

void func_8420C7B0(s16 arg0, s16 arg1, s16 arg2, char* arg3) {
    if (arg2 == D_8423E58A) {
        func_8001F324(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_8001F1E8(arg0 + 0x3C, arg1 + (arg2 * 0x1C) + 0xC, arg3);
}

void func_8420C844(unk_D_84211704* arg0) {
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 0, func_84200130(0x15));
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 1, func_84200130(0x16));
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 2, func_84200130(0x17));
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 3, func_84200130(0x18));
    func_8001F444();

    if (D_8423E58A >= 0) {
        func_80020928(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void func_8420C930(unk_D_84211704* arg0) {
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 0, func_84200130(0x19));
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 1, func_84200130(0x1A));
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 2, func_84200130(0x1B));
    func_8001F444();

    if (D_8423E58A >= 0) {
        func_80020928(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void func_8420CA00(unk_D_84211704* arg0) {
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 0, func_84200130(0x15));
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 1, func_84200130(0x17));
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 2, func_84200130(0x18));
    func_8001F444();

    if (D_8423E58A >= 0) {
        func_80020928(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void func_8420CAD0(unk_D_84211704* arg0) {
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 0, func_84200130(0x1C));
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 1, func_84200130(0x1D));
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 2, func_84200130(0x1E));
    func_8001F444();

    if (D_8423E58A >= 0) {
        func_80020928(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void func_8420CBA0(unk_D_84211704* arg0) {
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 0, func_84200130(0x1F));
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 1, func_84200130(0x20));
    func_8001F444();

    if (D_8423E58A >= 0) {
        func_80020928(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void func_8420CC54(unk_D_84211704* arg0) {
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F1E8(arg0->unk_00 + 0x2D, arg0->unk_02 + 0x38, func_84200130(0x21));
    func_8001F444();
}

void func_8420CCAC(unk_D_84211704* arg0) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg0->unk_00 + 0x18, arg0->unk_02 + 0x26, 0x4C, 0x14, D_2029CE0, 0x4C, 0);
    func_8001C6AC(arg0->unk_00 + 0x18, arg0->unk_02 + 0x3A, 0x4C, 0x14, D_202A8C0, 0x4C, 0);
    func_8001C6AC(arg0->unk_00 + 0x18, arg0->unk_02 + 0x4E, 0x4C, 0x14, D_202B4A0, 0x4C, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F1E8(arg0->unk_00 + 0x78, arg0->unk_02 + 0x38, func_84200130(0x22));
    func_8001F444();
}

void func_8420CE24(unk_D_84211704* arg0) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg0->unk_00 + 0x18, arg0->unk_02 + arg0->unk_08 + 0x26, 0x4C, 0x14, D_2029CE0, 0x4C, 0);
    func_8001C6AC(arg0->unk_00 + 0x18, arg0->unk_02 + arg0->unk_08 + 0x3A, 0x4C, 0x14, D_202A8C0, 0x4C, 0);
    func_8001C6AC(arg0->unk_00 + 0x18, arg0->unk_02 + arg0->unk_08 + 0x4E, 0x4C, 0x14, D_202B4A0, 0x4C, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F3B4(0x1E);
    func_8001F1E8(arg0->unk_00 + 0x78, arg0->unk_02 + arg0->unk_08 + 0x29, func_84200130(0x23));
    func_8001F444();
}

void func_8420CFC4(unk_D_84211704* arg0) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg0->unk_00 + 0x10, arg0->unk_02 + 0x10, 0x4C, 0x14, D_2029CE0, 0x4C, 0);
    func_8001C6AC(arg0->unk_00 + 0x10, arg0->unk_02 + 0x24, 0x4C, 0x14, D_202A8C0, 0x4C, 0);
    func_8001C6AC(arg0->unk_00 + 0x10, arg0->unk_02 + 0x38, 0x4C, 0x14, D_202B4A0, 0x4C, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F3B4(0x1C);
    func_8001F1E8(arg0->unk_00 + 0x68, arg0->unk_02 + 0x14, func_84200130(0x24));
    func_8001F444();
}

void func_8420D144(unk_D_84211704* arg0) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg0->unk_00 + 0x10, arg0->unk_02 + 0x10, 0x4C, 0x14, D_2029CE0, 0x4C, 0);
    func_8001C6AC(arg0->unk_00 + 0x10, arg0->unk_02 + 0x24, 0x4C, 0x14, D_202A8C0, 0x4C, 0);
    func_8001C6AC(arg0->unk_00 + 0x10, arg0->unk_02 + 0x38, 0x4C, 0x14, D_202B4A0, 0x4C, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F1E8(arg0->unk_00 + 0x68, arg0->unk_02 + 0x22, func_84200130(0x25));
    func_8001F444();
}

void func_8420D2BC(unk_D_84211704* arg0) {
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 0, func_84200130(0x26));
    func_8420C7B0(arg0->unk_00, arg0->unk_02, 1, func_84200130(0x20));
    func_8001F444();

    if (D_8423E58A >= 0) {
        func_80020928(arg0->unk_00 + 0x10, arg0->unk_02 + (D_8423E58A * 0x1C) + 0xC);
    }
}

void func_8420D370(unk_D_84211704* arg0, s16 arg1) {
    char sp28[0x100];
    s32 tmp;
    char* sp20;

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F3B4(0x1C);
    func_8002D600(2, arg1);
    sp20 = func_84200190(sp28, sizeof(sp28), 0x27);
    tmp = ((arg0->unk_04 - func_8001F5B0(0, 0, sp20)) / 2);
    func_8001F1E8(arg0->unk_00 + tmp, arg0->unk_02 + 0x14, sp20);
    sp20 = func_84200130(0x28);
    tmp = ((arg0->unk_04 - func_8001F5B0(0, 0, sp20)) / 2);
    func_8001F1E8(arg0->unk_00 + tmp, arg0->unk_02 + 0x56, sp20);
    func_8001F444();
}

void func_8420D464(unk_D_84211704* arg0, s16 arg1) {
    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    if (arg1 == 0) {
        func_8001F1E8(arg0->unk_00 + 0x18, arg0->unk_02 + 0x14, func_84200130(0x29));
    } else {
        func_8001F1E8(arg0->unk_00 + 0x39, arg0->unk_02 + 0x14, func_84200130(0x2A));
    }
    func_8001F444();
}

void func_8420D4F8(s32 arg0) {
    s16 tmp2;
    s16 var_a3;
    unk_D_84211704* temp_s0;

    if ((D_84211700 != 0) && (D_8423E588 > 0)) {
        temp_s0 = &D_84211704[D_8423E580];
        if (D_8423E588 < 4) {
            var_a3 = (temp_s0->unk_06 * D_8423E588) / 4;
            if (var_a3 < 0x10) {
                var_a3 = 0x10;
            }
            tmp2 = temp_s0->unk_02 + ((temp_s0->unk_06 - var_a3) / 2);
            func_80020460(temp_s0->unk_00, tmp2, temp_s0->unk_04, var_a3, temp_s0->unk_0C);
        } else {
            func_80020460(temp_s0->unk_00, temp_s0->unk_02, temp_s0->unk_04, temp_s0->unk_06, temp_s0->unk_0C);

            switch (D_8423E580) {
                case 0:
                    func_8420C844(temp_s0);
                    break;
                case 1:
                    func_8420CC54(temp_s0);
                    break;
                case 2:
                    func_8420CCAC(temp_s0);
                    break;
                case 3:
                    func_8420CE24(temp_s0);
                    break;
                case 4:
                    func_8420C930(temp_s0);
                    break;
                case 5:
                    func_8420C930(temp_s0);
                    break;
                case 6:
                    func_8420CAD0(temp_s0);
                    break;
                case 7:
                    func_8420CAD0(temp_s0);
                    break;
                case 8:
                    func_8420CFC4(temp_s0);
                    break;
                case 9:
                    func_8420CBA0(temp_s0);
                    break;
                case 10:
                    func_8420CA00(temp_s0);
                    break;
                case 11:
                    func_8420D144(temp_s0);
                    break;
                case 12:
                    func_8420D2BC(temp_s0);
                    break;
                case 13:
                    func_8420D370(temp_s0, 0x9B);
                    break;
                case 14:
                    func_8420D370(temp_s0, 0x50);
                    break;
                case 15:
                    func_8420D370(temp_s0, 0x32);
                    break;
                case 16:
                    func_8420CE24(temp_s0);
                    break;
                case 17:
                    func_8420D464(temp_s0, 0);
                    break;
                case 18:
                    func_8420D464(temp_s0, 1);
                    break;
                case 19:
                    func_8420CBA0(temp_s0);
                    break;
            }
        }
    }
}

void func_8420D75C(void) {
    s16 tmp = D_84211704[D_8423E580].unk_0A;

    if (D_8423E584 != NULL) {
        if (BTN_IS_PRESSED(D_8423E584, BTN_A)) {
            s32 tmp2 = (D_84211704[D_8423E580].unk_0E >> (D_8423E58A * 3));

            switch (tmp2 & 7) {
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
                    func_80048B90(0x21);
                    break;

                case 6:
                    if (func_80028E68() < 0xC) {
                        func_80048B90(0x20);
                    } else {
                        func_80048B90(8);
                    }
                    break;
            }
            D_84211700 = 3;
        } else if (BTN_IS_PRESSED(D_8423E584, BTN_B)) {
            func_80048B90(3);
            D_8423E58A = -1;
            D_84211700 = 3;
        } else if (BTN_IS_PRESSED(D_8423E584, BTN_DUP)) {
            func_80048B90(1);
            D_8423E58A -= 1;
            if (D_8423E58A < 0) {
                D_8423E58A = tmp - 1;
            }
        } else if (BTN_IS_PRESSED(D_8423E584, BTN_DDOWN)) {
            func_80048B90(1);
            D_8423E58A += 1;
            if (D_8423E58A >= tmp) {
                D_8423E58A = 0;
            }
        }
    }
    D_8423E588 = 4;
}

void func_8420D938(void) {
    D_8423E588++;
    if (D_8423E588 >= 5) {
        D_8423E588 = 4;
        D_84211700 = 2;
    }
}

void func_8420D978(void) {
    D_8423E588--;
    if (D_8423E588 < 0) {
        D_8423E588 = 0;
        D_84211700 = 4;
    }
}

s32 func_8420D9B0(void) {
    s32 sp1C = 0;

    switch (D_84211700) {
        case 2:
            sp1C = 0;
            func_8420D75C();
            break;

        case 1:
            func_8420D938();
            sp1C = 1;
            break;

        case 3:
            func_8420D978();
            sp1C = 1;
            break;
    }

    return sp1C;
}

s32 func_8420DA28(s16 arg0, Controller* arg1) {
    if (D_84211700 == 0) {
        switch (arg0) {
            case 8:
                func_80048B90(0x1F);

            case 11:
                func_80048B90(0x1E);
                break;
        }
        func_80048B90(4);
        D_8423E580 = arg0;
        D_8423E58A = D_84211704[arg0].unk_0B;
        D_8423E588 = 0;
        D_8423E584 = arg1;
        D_84211700 = 1;
        return 1;
    }
    return 0;
}

s32 func_8420DAF4(s16 arg0) {
    if ((D_84211700 == 2) && (arg0 == D_8423E580)) {
        D_8423E58A = -1;
        D_84211700 = 3;
        return 1;
    }
    return 0;
}

s16 func_8420DB48(s16 arg0) {
    if ((D_84211700 == 4) && (arg0 == D_8423E580)) {
        D_84211700 = 0;
        return D_8423E58A + 1;
    }
    return -1;
}
