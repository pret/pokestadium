#include "fragment61.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/232C0.h"
#include "src/26820.h"
#include "src/49790.h"
#include "src/hal_libc.h"

s16 D_842115B0[] = { 0x78, 0xFC, 0x180, 0x78, 0xFC, 0x180 };
s16 D_842115BC[] = {
    4, 4, 4, 0x30, 0x30, 0x30,
};

void func_84205E80(s16 arg0, s16 arg1, s32 arg2) {
    if (arg2 & 0x80000000) {
        func_84200420(arg0, arg1, 0x84, 0x2C, 0x64, 0x64, 0xC8, 0xFF);
    } else {
        func_84200420(arg0, arg1, 0x84, 0x2C, 0x3C, 0x3C, 0xA0, 0xFF);
    }
}

void func_84205F18(unk_D_84211B50* arg0, s16 arg1, s16 arg2) {
    s16 i;

    func_842001B8(arg1, arg2, 0x208, 0x60);
    if (((D_800AE540.unk_0001 == 0) || (D_800AE540.unk_0001 == 8)) && (arg0->unk_0004 != 0) && (arg0->unk_0006 > 0) &&
        (arg0->unk_0006 < 6)) {
        func_84200420(arg1 + 4, arg2 + 4, 0x74, 0x58, 0, 0, 0, 0xFF);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_8001C6AC(arg1 + 0x32, arg2 + 0x32, 0x14, 0x14, D_20068E0, 0x14, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    } else {
        func_84200420(arg1 + 4, arg2 + 4, 0x74, 0x58, 0x64, 0x64, 0xC8, 0xFF);
    }

    for (i = 0; i < 6; i++) {
        s16 tmp1 = D_842115B0[i] + arg1;
        s16 tmp2 = D_842115BC[i] + arg2;

        func_84205E80(tmp1, tmp2, arg0->unk_0030[i].raw);
    }
}

void func_84206144(unk_D_84211B50* arg0) {
    s16 temp_s0 = arg0->unk_0018 + (arg0->unk_0010 * 0x84) + 0x78;
    s16 temp_a1 = arg0->unk_001A + (arg0->unk_0012 * 0x2C) + 4;

    if (arg0->unk_0001 == 0xD) {
        if (arg0->unk_000C > 0) {
            temp_a1 = ((temp_a1 + ((arg0->unk_000C * 0x2C) / 4)) - 0x2C);
        } else {
            temp_a1 = (temp_a1 + ((arg0->unk_000C * 0x2C) / 4) + 0x2C);
        }
        func_84200738(temp_s0, temp_a1, 0x84, 0x2C);
    } else if (arg0->unk_0001 == 0xC) {
        if (arg0->unk_000C > 0) {
            temp_s0 = ((temp_s0 + ((arg0->unk_000C * 0x84) / 4)) - 0x84);
        } else {
            temp_s0 = (temp_s0 + ((arg0->unk_000C * 0x84) / 4) + 0x84);
        }
        func_84200738(temp_s0, temp_a1, 0x84, 0x2C);
    } else if (arg0->unk_0001 == 8) {
        func_84200738(temp_s0, temp_a1, 0x84, 0x2C);
    }
}

void func_842062D4(unk_D_84211B50* arg0, s32 arg1) {
    char* temp_v0_10;
    char* temp_v0_4;
    char* temp_v0_5;
    char* temp_v0_6;
    char* temp_v0_7;
    char* temp_v0_8;
    s32 i;
    s16 sp42;
    s16 sp40;
    char* temp_v0_9;

    if ((arg0->unk_0001 != 1) && (arg0->unk_0001 != 0) && ((arg1 != 0) || (arg0->unk_0003 != 0))) {
        func_84205F18(arg0, arg0->unk_0018, arg0->unk_001A);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        for (i = 0; i < 6; i++) {
            if (arg0->unk_0030[i].unk_004.unk_00.unk_00 != 0) {
                s16 tmp1 = D_842115B0[i] + arg0->unk_0018 + 2;
                s16 tmp2 = D_842115BC[i] + arg0->unk_001A + 2;

                func_8001C6AC(tmp1, tmp2, 0x28, 0x28, arg0->unk_0030[i].unk_058, 0x28, 0);
            }
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        func_8001F3F4();

        if (((D_800AE540.unk_0001 == 0) || (D_800AE540.unk_0001 == 8)) && (arg0->unk_0004 != 0) &&
            (arg0->unk_0006 > 0) && (arg0->unk_0006 < 6)) {
            func_8001EBE0(8, 0);
            temp_v0_4 = func_84200130(arg0->unk_0006 + 0x2A);
            func_8001F1E8((arg0->unk_0018 - (func_8001F5B0(8, 0, temp_v0_4) / 2)) + 0x3C, arg0->unk_001A + 8,
                          temp_v0_4);
            if (arg0->unk_0000 == 0) {
                temp_v0_5 = func_84200130(0x31);
                func_8001F1E8((arg0->unk_0018 - (func_8001F5B0(8, 0, temp_v0_5) / 2)) + 0x3C, arg0->unk_001A + 0x1C,
                              temp_v0_5);
            } else {
                temp_v0_6 = func_84200130(0x32);
                func_8001F1E8((arg0->unk_0018 - (func_8001F5B0(8, 0, temp_v0_6) / 2)) + 0x3C, arg0->unk_001A + 0x1C,
                              temp_v0_6);
            }
            func_8001EBE0(4, 0);
            temp_v0_7 = func_84200130(0x33);
            func_8001F1E8((arg0->unk_0018 - (func_8001F5B0(4, 0, temp_v0_7) / 2)) + 0x3C, arg0->unk_001A + 0x46,
                          temp_v0_7);
        } else {
            func_8001EBE0(4, 0);
            if (arg0->unk_0000 == 0) {
                temp_v0_8 = func_84200130(0x34);
                func_8001F1E8((arg0->unk_0018 - (func_8001F5B0(4, 0, temp_v0_8) / 2)) + 0x3C, arg0->unk_001A + 9,
                              temp_v0_8);
            } else {
                temp_v0_9 = func_84200130(0x35);
                func_8001F1E8((arg0->unk_0018 - (func_8001F5B0(4, 0, temp_v0_9) / 2)) + 0x3C, arg0->unk_001A + 9,
                              temp_v0_9);
            }
            temp_v0_10 = func_84200130(0x36);
            func_8001F1E8((arg0->unk_0018 - (func_8001F5B0(4, 0, temp_v0_10) / 2)) + 0x3C, arg0->unk_001A + 0x1A,
                          temp_v0_10);
            func_8001EBE0(8, 0);
            func_8001F1E8((arg0->unk_0018 - (func_8001F5B0(8, 0, arg0->unk_001E) / 2)) + 0x3C, arg0->unk_001A + 0x2F,
                          arg0->unk_001E);
            func_8001EBE0(4, 0);
            func_8001F1E8((arg0->unk_0018 - (func_8001F5B0(4, 0, "ID  00000") / 2)) + 0x3C, arg0->unk_001A + 0x46,
                          "ID  %05d", arg0->unk_001C);
        }
        func_8001EBE0(4, 0);

        for (i = 0; i < 6; i++) {
            if (arg0->unk_0030[i].unk_004.unk_00.unk_00 != 0) {
                s16 tmp1 = D_842115B0[i] + arg0->unk_0018 + 0x2C;
                s16 tmp2 = D_842115BC[i] + arg0->unk_001A + 5;

                func_8001F1E8(tmp1, tmp2, arg0->unk_0030[i].unk_004.unk_30);
            }
        }

        func_8001EBE0(4, 0);

        for (i = 0; i < 6; i++) {
            if (arg0->unk_0030[i].unk_004.unk_00.unk_00 != 0) {
                sp42 = D_842115B0[i] + arg0->unk_0018 + 0x2C;
                sp40 = D_842115BC[i] + arg0->unk_001A + 0x17;
                func_8001F1E8(sp42, sp40, "%s %d", func_84200160(0x15), arg0->unk_0030[i].unk_004.unk_24);
            }
        }

        func_8001F444();
        func_84206144(arg0);

        if (arg0->unk_0003 > 0) {
            arg0->unk_0003--;
        }
    }
}

void func_84206870(unk_D_84211B50* arg0) {
    s16 temp_v0 = arg0->unk_0010 + (arg0->unk_0012 * 3);

    if (arg0->unk_0030[temp_v0].unk_004.unk_00.unk_00 != 0) {
        arg0->unk_0030[temp_v0].unk_004.unk_00.unk_00 = 0;
        arg0->unk_0030[temp_v0].raw = 0;
        arg0->unk_0006 -= 1;
    }
}

void func_842068DC(unk_D_84211B50* arg0) {
    s16 sp1E = arg0->unk_0010 + (arg0->unk_0012 * 3);

    if (func_8420B334(arg0->unk_4D40) != 0) {
        if (arg0->unk_0030[sp1E].unk_004.unk_00.unk_00 != 0) {
            arg0->unk_0030[sp1E].unk_004.unk_00.unk_00 = 0;
            arg0->unk_0030[sp1E].raw = 0;
            arg0->unk_0006--;
        }
        arg0->unk_0030[sp1E].raw |= 0x80000000;
        arg0->unk_0004 = 1;
        arg0->unk_0001 = 3;
    }
}

s32 func_84206990(unk_D_84211B50* arg0) {
    s16 i;
    s16 temp_v0;
    s32 var_s0 = 0;
    unk_func_80022C28_ret* temp_s3;

    temp_v0 = func_80028E68();
    if (temp_v0 < 0xA) {
        temp_s3 = func_80022CC0(0x10, 0, temp_v0, arg0->unk_001E, arg0->unk_001E, arg0->unk_001C);

        for (i = 0; i < arg0->unk_0006; i++) {
            func_80022F24(&arg0->unk_0030[i].unk_004.unk_00.unk_00, 1, temp_s3);
        }

        func_80022D8C(temp_s3);
        func_800286D8();
        var_s0 = 1;
    }
    return var_s0;
}

s32 func_84206A68(unk_D_84211B50* arg0) {
    UNUSED s32 pad;
    s32 temp_v1;
    s16 i;
    s16 sp8[3];

    for (i = 0; i < 3; i++) {
        sp8[i] = 0x3E7;
    }

    for (i = 0; i < arg0->unk_0006; i++) {
        temp_v1 = arg0->unk_0030[i].unk_004.unk_24;
        if (sp8[2] >= temp_v1) {
            sp8[2] = temp_v1;
        }

        if (sp8[1] >= temp_v1) {
            sp8[2] = sp8[1];
            sp8[1] = temp_v1;
        }

        if (sp8[0] >= temp_v1) {
            sp8[1] = sp8[0];
            sp8[0] = temp_v1;
        }
    }

    switch (D_800AE540.unk_0001) {
        default:
            temp_v1 = 0;
            break;

        case 3:
            temp_v1 = (s16)(sp8[0] + sp8[1] + sp8[2]);
            temp_v1 = temp_v1 >= 0x9C;
            break;

        case 4:
            temp_v1 = (s16)(sp8[0] + sp8[1] + sp8[2]);
            temp_v1 = temp_v1 >= 0x51;
            break;

        case 5:
            temp_v1 = (s16)(sp8[0] + sp8[1] + sp8[2]);
            temp_v1 = temp_v1 >= 0x33;
            break;
    }
    return temp_v1;
}

void func_84206BC4(unk_D_84211B50* arg0) {
    arg0->unk_0018 = arg0->unk_0014 + 0x280;
    arg0->unk_001A = arg0->unk_0016;
}

void func_84206BDC(unk_D_84211B50* arg0) {
    arg0->unk_0018 = arg0->unk_0014;
    arg0->unk_001A = arg0->unk_0016;
}

void func_84206BF0(unk_D_84211B50* a0) {
    unk_D_84211B50* arg0 = a0;
    s16 temp_v0;
    s16 temp_v1;
    s16 tmp;

    func_8420DAF4(1);
    if (func_8420DB48(1) >= 0) {
        tmp = a0->unk_0010 + a0->unk_0012 * 3;

        temp_v0 = a0->unk_0014 + (a0->unk_0010 * 0x84) + 0x74;
        temp_v1 = a0->unk_0016 + (a0->unk_0012 * 0x2C);

        arg0->unk_0030[tmp].raw |= 0x80000000;
        func_8420C60C(a0->unk_4D44, a0->unk_0002, 0x30, 0xEC, temp_v0, temp_v1, &a0->unk_0030[tmp], 2);
        a0->unk_0001 = 6;
    }
    a0->unk_0018 = a0->unk_0014;
    a0->unk_001A = a0->unk_0016;
    a0->unk_0003 = 2;
}

void func_84206D10(unk_D_84211B50* arg0) {
    s16 sp26 = arg0->unk_0010 + (arg0->unk_0012 * 3);
    s32 temp_v0 = func_8420C788(arg0->unk_4D44);

    if (temp_v0 == 1) {
        func_8420B334(arg0->unk_4D40);
        arg0->unk_0004 = 0;
        arg0->unk_0001 = 3;
    } else if (temp_v0 == 2) {
        arg0->unk_0030[sp26].raw &= ~0x80000000;
        func_8420DA28(1, NULL);
        arg0->unk_000A = 0;
        arg0->unk_0001 = 8;
    }
    arg0->unk_0018 = arg0->unk_0014;
    arg0->unk_001A = arg0->unk_0016;
}

void func_84206DE8(unk_D_84211B50* arg0) {
    arg0->unk_000A++;
    if (arg0->unk_000A <= 0) {
        arg0->unk_0018 = arg0->unk_0014 + 0x280;
        arg0->unk_0003 = 2;
    } else if (arg0->unk_000A == 0xA) {
        arg0->unk_000A = 0;
        arg0->unk_0018 = arg0->unk_0014;
        if (arg0->unk_0006 == arg0->unk_0008) {
            arg0->unk_0003 = 2;
            arg0->unk_0001 = 7;
        } else {
            // clang-format off
            *(s8*)&arg0->unk_0001 = 2; arg0->unk_0003 = 2;
            // clang-format on
        }
    } else {
        arg0->unk_0018 = (arg0->unk_0014 - (arg0->unk_000A << 6)) + 0x280;
        arg0->unk_0003 = 2;
    }
    arg0->unk_001A = arg0->unk_0016;
}

void func_84206E88(unk_D_84211B50* arg0) {
    arg0->unk_000A++;
    if (arg0->unk_000A == 0xA) {
        arg0->unk_0001 = 0;
        arg0->unk_000A = 0;
        arg0->unk_0018 = arg0->unk_0014 + 0x280;
    } else {
        arg0->unk_0018 = arg0->unk_0014 - (arg0->unk_000A << 6);
    }
    arg0->unk_001A = arg0->unk_0016;
    arg0->unk_0003 = 2;
}

void func_84206EE0(unk_D_84211B50* arg0) {
    func_842068DC(arg0);
    arg0->unk_0018 = arg0->unk_0014;
    arg0->unk_001A = arg0->unk_0016;
    arg0->unk_0003 = 2;
}

void func_84206F1C(unk_D_84211B50* arg0) {
    if (arg0->unk_0010 > 0) {
        arg0->unk_0010--;
        arg0->unk_000C = -1;
        arg0->unk_000E = -4;
        arg0->unk_0001 = 0xC;
        func_80048B90(1);
    }
}

void func_84206F64(unk_D_84211B50* arg0) {
    if (arg0->unk_0010 < 2) {
        arg0->unk_0010++;
        arg0->unk_000C = 1;
        arg0->unk_000E = 4;
        arg0->unk_0001 = 0xC;
        func_80048B90(1);
    }
}

void func_84206FB0(unk_D_84211B50* arg0) {
    if (arg0->unk_0012 > 0) {
        arg0->unk_0012--;
        arg0->unk_000C = -1;
        arg0->unk_000E = -4;
        arg0->unk_0001 = 0xD;
        func_80048B90(1);
    }
}

void func_84206FF8(unk_D_84211B50* arg0) {
    if (arg0->unk_0012 <= 0) {
        arg0->unk_0012++;
        arg0->unk_000C = 1;
        arg0->unk_000E = 4;
        arg0->unk_0001 = 0xD;
        func_80048B90(1);
    }
}

void func_84207040(unk_D_84211B50* arg0) {
    Controller* cont = &gControllers[arg0->unk_0002];

    if (arg0->unk_000A < 8) {
        arg0->unk_000A++;
    } else if (BTN_IS_PRESSED(cont, BTN_A)) {
        s32 temp_v0 = arg0->unk_0010 + (arg0->unk_0012 * 3);

        if (arg0->unk_0030[temp_v0].unk_004.unk_00.unk_00 != 0) {
            func_80048B90(2);
            arg0->unk_0001 = 0xB;
        }
    } else if (BTN_IS_PRESSED(cont, BTN_B)) {
        func_80048B90(3);
        arg0->unk_0001 = 0x10;
    } else if (BTN_IS_PRESSED(cont, BTN_DUP)) {
        func_84206FB0(arg0);
    } else if (BTN_IS_PRESSED(cont, BTN_DDOWN)) {
        func_84206FF8(arg0);
    } else if (BTN_IS_PRESSED(cont, BTN_DRIGHT)) {
        func_84206F64(arg0);
    } else if (BTN_IS_PRESSED(cont, BTN_DLEFT)) {
        func_84206F1C(arg0);
    }

    arg0->unk_0018 = arg0->unk_0014;
    arg0->unk_001A = arg0->unk_0016;
    arg0->unk_0003 = 2;
}

void func_84207190(unk_D_84211B50* arg0) {
    func_8420DAF4(1);
    if (func_8420DB48(1) >= 0) {
        if (func_84206A68(arg0) != 0) {
            arg0->unk_0001 = 0xF;
        } else if (arg0->unk_0000 == 0) {
            arg0->unk_0001 = 7;
        } else {
            arg0->unk_0001 = 0xE;
        }
    }
    arg0->unk_0003 = 2;
}

void func_8420720C(unk_D_84211B50* arg0) {
    Controller* cont = &gControllers[arg0->unk_0002];
    s16 i;

    func_8420DA28(0, cont);

    switch (func_8420DB48(0)) {
        case 0:
            i = arg0->unk_0006;
            if (i == 6) {
                i--;
            }
            arg0->unk_0010 = i % 3;
            arg0->unk_0012 = i / 3;
            arg0->unk_0008 = 6;
            arg0->unk_0001 = 2;
            break;

        case 1:
            func_8420B238(arg0->unk_4D40);
            arg0->unk_000A = 0;
            arg0->unk_0001 = 5;
            break;

        case 2:
            if (func_84206990(arg0) != 0) {
                arg0->unk_0001 = 9;
            } else {
                arg0->unk_0001 = 0xA;
            }
            break;

        case 3:
            func_8420DA28(1, NULL);
            arg0->unk_0010 = 0;
            arg0->unk_0012 = 0;
            arg0->unk_000A = 0;
            arg0->unk_0001 = 8;
            break;

        case 4:
            for (i = 0; i < 6; i++) {
                arg0->unk_0030[i].raw = 0;
                arg0->unk_0030[i].unk_004.unk_00.unk_00 = 0;
            }

            func_8420B264(arg0->unk_4D40);

            arg0->unk_0006 = 0;
            arg0->unk_0010 = 0;
            arg0->unk_0012 = 0;
            arg0->unk_0008 = 6;
            arg0->unk_0001 = 2;
            break;
    }
    arg0->unk_0018 = arg0->unk_0014;
    arg0->unk_001A = arg0->unk_0016;
}

void func_842073A4(unk_D_84211B50* arg0) {
    Controller* cont = &gControllers[arg0->unk_0002];
    s16 i;

    func_8420DA28(0xA, cont);
    switch (func_8420DB48(0xA)) {
        case 0:
            i = arg0->unk_0006;
            if (i == 6) {
                i--;
            }
            arg0->unk_0010 = i % 3;
            arg0->unk_0012 = i / 3;
            arg0->unk_0008 = 6;
            arg0->unk_0001 = 2;
            break;

        case 1:
            func_8420B238(arg0->unk_4D40);
            func_84210A48(arg0->unk_4D48, arg0->unk_001C, arg0->unk_001E, arg0->unk_0030);
            arg0->unk_0001 = 3;
            break;

        case 2:
            func_8420DA28(1, NULL);
            arg0->unk_0010 = 0;
            arg0->unk_0012 = 0;
            arg0->unk_000A = 0;
            arg0->unk_0001 = 8;
            break;

        case 3:
            for (i = 0; i < 6; i++) {
                arg0->unk_0030[i].raw = 0;
                arg0->unk_0030[i].unk_004.unk_00.unk_00 = 0;
            }

            func_8420B264(arg0->unk_4D40);

            arg0->unk_0006 = 0;
            arg0->unk_0010 = 0;
            arg0->unk_0012 = 0;
            arg0->unk_0008 = 6;
            arg0->unk_0001 = 2;
            break;
    }

    arg0->unk_0018 = arg0->unk_0014;
    arg0->unk_001A = arg0->unk_0016;
}

void func_84207530(unk_D_84211B50* arg0) {
    UNUSED s16 pad;
    s16 sp1C = 0xD;
    s32 temp_v0_2;
    Controller* cont = &gControllers[arg0->unk_0002];

    switch (D_800AE540.unk_0001) {
        case 3:
            break;

        case 4:
            sp1C = 0xE;
            break;

        case 5:
            sp1C = 0xF;
            break;
    }

    func_8420DA28(sp1C, cont);

    temp_v0_2 = func_8420DB48(sp1C);
    if (temp_v0_2 != -1) {
        if (temp_v0_2 == 0) {
            arg0->unk_0010 = 2;
            arg0->unk_0012 = 1;
            arg0->unk_0008 = 6;
            arg0->unk_0001 = 2;
        } else {
            func_8420DA28(1, NULL);
            arg0->unk_0010 = 0;
            arg0->unk_0012 = 0;
            arg0->unk_000A = 0;
            arg0->unk_0001 = 8;
        }
    }

    arg0->unk_0018 = arg0->unk_0014;
    arg0->unk_001A = arg0->unk_0016;
}

void func_84207634(unk_D_84211B50* arg0) {
    Controller* cont = &gControllers[arg0->unk_0002];

    func_8420DA28(2, cont);
    if (func_8420DB48(2) >= 0) {
        func_8420B238(arg0->unk_4D40);
        arg0->unk_000A = 0;
        arg0->unk_0001 = 5;
    }
}

void func_842076A0(unk_D_84211B50* arg0) {
    Controller* cont = &gControllers[arg0->unk_0002];

    func_8420DA28(3, cont);
    if (func_8420DB48(3) >= 0) {
        arg0->unk_0001 = 7;
    }
}

void func_842076F8(unk_D_84211B50* arg0) {
    if (arg0->unk_000E > 0) {
        arg0->unk_000C++;
        if (arg0->unk_000C >= arg0->unk_000E) {
            arg0->unk_0001 = 8;
        }
    } else {
        arg0->unk_000C--;
        if (arg0->unk_000E >= arg0->unk_000C) {
            arg0->unk_0001 = 8;
        }
    }
    arg0->unk_0018 = arg0->unk_0014;
    arg0->unk_001A = arg0->unk_0016;
    arg0->unk_0003 = 2;
}

s32 func_8420776C(unk_D_84211B50* arg0) {
    s32 sp1C = 0;

    switch (arg0->unk_0001) {
        case 0:
            func_84206BC4(arg0);
            break;

        case 1:
            func_84206BC4(arg0);
            break;

        case 3:
            func_84206BDC(arg0);
            break;

        case 2:
            func_84206EE0(arg0);
            break;

        case 4:
            func_84206DE8(arg0);
            sp1C = 1;
            break;

        case 5:
            func_84206E88(arg0);
            sp1C = 1;
            break;

        case 6:
            func_84206D10(arg0);
            break;

        case 7:
            func_8420720C(arg0);
            break;

        case 8:
            func_84207040(arg0);
            break;

        case 9:
            func_84207634(arg0);
            break;

        case 10:
            func_842076A0(arg0);
            break;

        case 11:
            func_84206BF0(arg0);
            break;

        case 12:
            func_842076F8(arg0);
            break;

        case 13:
            func_842076F8(arg0);
            break;

        case 14:
            func_842073A4(arg0);
            break;

        case 15:
            func_84207530(arg0);
            break;

        case 16:
            func_84207190(arg0);
            break;
    }
    return sp1C;
}

s32 func_842078C0(unk_D_84211B50* arg0, unk_D_842168A0* arg1, unk_D_8423D3A8* arg2, unk_D_84229EB0* arg3, s16 arg4,
                  u16 arg5, char* arg6, s16 arg7, s16 arg8, s16 arg9) {
    s32 i;

    arg0->unk_0000 = arg4;
    arg0->unk_0001 = 1;
    arg0->unk_0002 = arg9;
    arg0->unk_0004 = 0;
    arg0->unk_0006 = 0;
    arg0->unk_0008 = 6;
    arg0->unk_000A = 0;
    arg0->unk_0010 = 0;
    arg0->unk_0012 = 0;
    arg0->unk_0014 = arg7;
    arg0->unk_0016 = arg8;
    arg0->unk_0018 = arg7 + 0x280;
    arg0->unk_001A = arg8;
    arg0->unk_001C = arg5;

    arg0->unk_4D40 = arg1;
    arg0->unk_4D44 = arg2;
    arg0->unk_4D48 = arg3;

    for (i = 0; i < 6; i++) {
        arg0->unk_0030[i].raw = 0;
        arg0->unk_0030[i].unk_004.unk_00.unk_00 = 0;
    }

    HAL_Strcpy(arg0->unk_001E, arg6);
    return 1;
}

s32 func_842079B4(unk_D_84211B50* arg0, s16 arg1) {
    if (arg0->unk_0001 != 1) {
        return 0;
    }
    arg0->unk_0001 = 4;
    arg0->unk_000A = -arg1;
    return 1;
}

s32 func_842079F0(unk_D_84211B50* arg0) {
    if (arg0->unk_0001 != 3) {
        return 0;
    }
    arg0->unk_0001 = 5;
    arg0->unk_000A = 0;
    return 1;
}

s32 func_84207A1C(unk_D_84211B50* arg0) {
    s16 i;

    if (arg0->unk_0001 != 3) {
        return 0;
    }

    for (i = 0; i < 6; i++) {
        arg0->unk_0030[i].raw = 0;
        arg0->unk_0030[i].unk_004.unk_00.unk_00 = 0;
    }

    func_8420B264(arg0->unk_4D40);
    arg0->unk_0006 = 0;
    arg0->unk_0008 = 6;
    arg0->unk_0010 = 0;
    arg0->unk_0012 = 0;
    arg0->unk_0001 = 2;
    return 1;
}

s32 func_84207AAC(unk_D_84211B50* arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v1 = arg0->unk_0010 + (arg0->unk_0012 * 3);

    if (arg0->unk_0001 == 3) {
        if (arg0->unk_0006 == 0) {
            arg0->unk_0001 = 5;
            arg0->unk_000A = 0;
            return -1;
        }

        arg0->unk_0030[temp_v1].raw &= 0x7FFFFFFF;

        if (arg0->unk_0030[temp_v1].raw == 0) {
            temp_v0 = temp_v1 - 1;
            arg0->unk_0010 = temp_v0 % 3;
            arg0->unk_0012 = temp_v0 / 3;
            func_84206870(arg0);
            arg0->unk_0001 = 2;
        } else {
            func_8420DA28(1, NULL);
            arg0->unk_000A = 0;
            arg0->unk_0001 = 8;
        }
        return 1;
    }

    return 0;
}

s32 func_84207BD4(unk_D_84211B50* arg0, unk_D_838067F0_0168_0000* arg1) {
    s32 var_v0 = arg0->unk_0010 + (arg0->unk_0012 * 3);

    if (arg0->unk_0001 != 3) {
        return 0;
    }

    if (arg0->unk_0030[var_v0].unk_004.unk_00.unk_00 == 0) {
        arg0->unk_0006 += 1;
    }

    arg0->unk_0030[var_v0] = *arg1;

    if (arg0->unk_0006 == arg0->unk_0008) {
        arg0->unk_0003 = 2;
        arg0->unk_0004 = 0;
        if (func_84206A68(arg0) != 0) {
            arg0->unk_0001 = 15;
        } else if (arg0->unk_0000 == 0) {
            arg0->unk_0001 = 7;
        } else {
            arg0->unk_0001 = 0xE;
        }
    } else {
        do {
            var_v0 = (var_v0 + 1) % 6;
        } while (arg0->unk_0030[var_v0].unk_004.unk_00.unk_00 != 0);
        arg0->unk_0010 = var_v0 % 3;
        arg0->unk_0012 = var_v0 / 3;
        arg0->unk_0001 = 2;
    }
    return 1;
}

s32 func_84207D5C(unk_D_84211B50* arg0) {
    s32 idx = (arg0->unk_0010 + (arg0->unk_0012 * 3));

    if (arg0->unk_0001 != 3) {
        return 0;
    }

    if (arg0->unk_0006 == 0) {
        return 0;
    }

    if (arg0->unk_0004 == 0) {
        return 0;
    }

    if ((D_800AE540.unk_0001 != 0) && (D_800AE540.unk_0000 != 8)) {
        return 0;
    }

    arg0->unk_0003 = 2;
    arg0->unk_0004 = 0;
    arg0->unk_0008 = arg0->unk_0006;
    arg0->unk_0030[idx].raw = 0;

    if (arg0->unk_0000 == 0) {
        arg0->unk_0001 = 7;
    } else {
        arg0->unk_0001 = 0xE;
    }
    return 1;
}

s32 func_84207E3C(unk_D_84211B50* arg0, unk_D_838067F0_0168_0000* arg1) {
    s32 i;
    u8 temp_a2;
    unk_D_838067F0_0168_0000* ptr;

    ptr = &arg0->unk_0030[0];
    temp_a2 = arg1->unk_004.unk_00.unk_00;

    if (arg1->unk_004.unk_00.unk_00 == 0) {
        return 0;
    }

    for (i = 0; i < 6; i++, ptr++) {
        if ((ptr->unk_004.unk_00.unk_00 != 0) && !(ptr->raw & 0x80000000)) {
            if (D_800AE540.unk_0001 == 0) {
                if (ptr->raw == arg1->raw) {
                    return 0;
                }
            } else if (ptr->unk_004.unk_00.unk_00 == temp_a2) {
                return 0;
            }
        }
    }

    return 1;
}

s32 func_8420804C(unk_D_84211B50* arg0, unk_D_838067F0_0168_0000* arg1) {
    s32 i;
    unk_D_838067F0_0168_0000* ptr;

    if (arg1->unk_004.unk_00.unk_00 == 0) {
        return 0;
    }

    ptr = &arg0->unk_0030[0];
    for (i = 0; i < 6; i++, ptr++) {
        if ((ptr->unk_004.unk_00.unk_00 != 0) && !(ptr->raw & 0x80000000) && (ptr->raw == arg1->raw)) {
            return 1;
        }
    }

    return 0;
}

s32 func_842081A8(unk_D_84211B50* arg0) {
    return arg0->unk_0001 == 0;
}

void func_842081B4(unk_D_84211B50* arg0, unk_func_80026268_arg0* arg1, s16 arg2) {
    s32 i;

    arg0->unk_0006 = arg2;
    arg0->unk_0008 = arg2;

    for (i = 0; i < arg2; i++) {
        func_8001B0DC(arg0->unk_0030[i].unk_058, 0, &arg1[i]);

        arg0->unk_0030[i].unk_004 = arg1[i];

        arg0->unk_0030[i].unk_000 = (arg1[i].unk_52 & 0x70) >> 4;
        arg0->unk_0030[i].unk_001 = arg1[i].unk_52 & 0xF;
        arg0->unk_0030[i].unk_002 = arg1[i].unk_53;
        arg0->unk_0030[i].unk_003 = arg1[i].unk_00.unk_00;
    }
}
