#include "fragment61.h"
#include "src/20470.h"
#include "src/22630.h"
#include "src/232C0.h"
#include "src/26820.h"
#include "src/49790.h"
#include "src/19840.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/225A0.h"
#include "src/2E110.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/dp_intro.h"
#include "src/hal_libc.h"

u8* D_84211850[] = {
    D_202C080, D_202C500, D_202C980, D_202CE00, D_202D280, D_202D700, D_202DB80, D_202E000,
};
s16 D_84211870[] = { 0x74, 0xF8, 0x17C, 0x74, 0xF8, 0x17C };
s16 D_8421187C[] = { 0, 0, 0, 0x2C, 0x2C, 0x2C };

s32 func_8420DBA0(unk_D_84229EB0_00024* arg0) {
    s16 temp_v0;
    s16 i;
    s32 ret = 0;
    unk_func_80022C28_ret* temp_s3;

    temp_v0 = func_80028E68();
    if (temp_v0 < 0xA) {
        temp_s3 = func_80022CC0(0x10, 0, temp_v0, &arg0->unk_4D12, &arg0->unk_4D12, arg0->unk_4D10);

        for (i = 0; i < arg0->unk_4D20; i++) {
            func_80022F24(&arg0->unk_0000[i].unk_004.unk_00.unk_00, 1, temp_s3);
        }

        func_80022D8C(temp_s3);
        func_800286D8();
        ret = 1;
    }
    return ret;
}

void func_8420DC78(unk_D_84229EB0_00024* arg0) {
    unk_D_800AE4E8_004_1_000 sp30;
    s16 tmp = arg0->unk_4D1E;
    s16 i;

    if (tmp >= 0xA) {
        return;
    }

    for (i = tmp; i < 9; i++) {
        func_80028C7C(&sp30, i + 1);
        func_80028D60(&sp30, i);
        func_80026684(0x10, i);
    }

    func_8002707C(0x10, 9);
    func_800286D8();
}

void func_8420DD14(unk_D_84229EB0* arg0, s16 arg1, s16 arg2, unk_D_84229EB0_00024* arg3) {
    UNUSED s32 pad;
    s16 i;
    s16 j;
    Color_RGBA8 sp8C;
    s16 temp_a0;
    s16 temp_a1;
    s16 temp_s2;
    s16 temp_s3;
    s16 var_s1;

    if ((arg0->unk_00001 == 8) || (arg0->unk_00001 == 9) || (arg0->unk_00001 == 0xA)) {
        func_84200420(arg1, arg2, 0x74, 0x58, 0x64, 0x64, 0xC8, 0xFF);

        for (var_s1 = 0, i = 0; i < 2; i++) {
            for (j = 0; j < 3; j++, var_s1++) {
                temp_a0 = D_84211870[var_s1] + arg1;
                temp_a1 = D_8421187C[var_s1] + arg2;
                if ((j == arg0->unk_00008) && (i == arg0->unk_0000A)) {
                    func_84200420(temp_a0, temp_a1, 0x84, 0x2C, 0x64, 0x64, 0xC8, 0xFF);
                } else {
                    func_84200420(temp_a0, temp_a1, 0x84, 0x2C, 0x3C, 0x3C, 0xA0, 0xFF);
                }
            }
        }
    } else {
        if (arg3->unk_4D1E == arg0->unk_0000D) {
            func_8000E820(&sp8C, 0x64, 0x64, 0xC8);
        } else {
            func_8000E820(&sp8C, 0x3C, 0x3C, 0xC8);
        }
        func_84200420(arg1, arg2, 0x74, 0x58, sp8C.r, sp8C.g, sp8C.b, 0xFF);

        for (var_s1 = 0; var_s1 < 6; var_s1++) {
            temp_a0 = D_84211870[var_s1] + arg1;
            temp_a1 = D_8421187C[var_s1] + arg2;

            func_84200420(temp_a0, temp_a1, 0x84, 0x2C, sp8C.r, sp8C.g, sp8C.b, 0xFF);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    func_8001C560(arg1, arg2 + 0x58, 0x200, 4, 0x32, 0x32, 0x32);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (arg3->unk_4D20 != 0) {
        if (arg3->unk_4D20 > 0) {
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 128);
        } else {
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
        }
        func_8001C6AC(arg1 + 0x14, arg2 + 0xE, 0x4C, 0x14, D_2029CE0, 0x4C, 0);
        func_8001C6AC(arg1 + 0x14, arg2 + 0x22, 0x4C, 0x14, D_202A8C0, 0x4C, 0);
        func_8001C6AC(arg1 + 0x14, arg2 + 0x36, 0x4C, 0x14, D_202B4A0, 0x4C, 0);
    }

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    for (var_s1 = 0; var_s1 < 6; var_s1++) {
        if (arg3->unk_0000[var_s1].raw != 0) {
            temp_s2 = D_84211870[var_s1] + arg1 + 2;
            temp_s3 = D_8421187C[var_s1] + arg2 + 2;
            func_8001C6AC(temp_s2, temp_s3, 0x28, 0x28, arg3->unk_0000[var_s1].unk_058, 0x28, 0);
            if (arg3->unk_0000[var_s1].raw & 0x80000000) {
                u8* ptr = D_84211850[arg3->unk_0000[var_s1].raw & 7];

                func_8001CF10(temp_s2 - 4, temp_s3 - 4, 0x30, 0x30, ptr, 0x30, 0);
            }
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(8, 0);
    func_8001F1E8(arg1 + 2, arg2 + 2, "%d", arg3->unk_4D1E + 1);

    if (arg3->unk_4D20 > 0) {
        func_8001EBE0(8, 0);
        func_8001F1E8(arg1 + 8, arg2 + 0x2B, &arg3->unk_4D12);
        func_8001EBE0(4, 0);
        func_8001F1E8(arg1 + 8, arg2 + 0x42, "ID %05d", arg3->unk_4D10);
    }

    func_8001EBE0(4, 0);

    for (var_s1 = 0; var_s1 < 6; var_s1++) {
        if (arg3->unk_0000[var_s1].unk_004.unk_00.unk_00 != 0) {
            s16 tmp1 = D_84211870[var_s1] + arg1 + 0x2C;
            s16 tmp2 = D_8421187C[var_s1] + arg2 + 5;

            func_8001F1E8(tmp1, tmp2, arg3->unk_0000[var_s1].unk_004.unk_30);
        }
    }

    func_8001EBE0(4, 0);

    for (var_s1 = 0; var_s1 < 6; var_s1++) {
        if (arg3->unk_0000[var_s1].unk_004.unk_00.unk_00 != 0) {
            temp_s2 = D_84211870[var_s1] + arg1 + 0x2C;
            temp_s3 = D_8421187C[var_s1] + arg2 + 0x17;
            func_8001F1E8(temp_s2, temp_s3, "%s%d", func_84200160(0x15), arg3->unk_0000[var_s1].unk_004.unk_24);
        }
    }

    func_8001F444();
}

void func_8420E46C(s16 arg0, s16 arg1) {
    char* sp54 = func_84200130(D_800AE540.unk_0001 + 0x3F);
    s32 sp50 = func_8001F5B0(8, 0, sp54);

    gSPDisplayList(gDisplayListHead++, D_8006F558);

    gDPSetEnvColor(gDisplayListHead++, 170, 60, 150, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 80, 40, 60, 255);

    func_8001CADC(arg0, arg1, 8, 0x1C, D_2000980, 8, 0);
    func_8001CADC(arg0 + 0x218, arg1, 8, 0x1C, D_2000A60, 8, 0);
    func_8001C330(arg0 + 4, arg1, 0x218, 0x1C, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(8, 0);
    func_8001F1E8(arg0 + 8, arg1 + 3, func_84200130(0xE));
    func_8001F1E8((arg0 - sp50) + 0x20E, arg1 + 3, sp54);
    func_8001F444();
}

void func_8420E63C(unk_D_84229EB0* arg0) {
    static s16 D_84211888 = 0;

    s16 sp66;
    s16 sp64;
    s16 sp62;
    s16 temp_s2;

    sp62 = arg0->unk_00012 + 4;
    temp_s2 = arg0->unk_00014 + 0x20;
    sp64 = arg0->unk_0001C;

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    func_8001C560(sp62 + 0, temp_s2, 0x18, arg0->unk_00016, 0x3C, 0x3C, 0xA0);
    func_8001C560(sp62 + 0x18, temp_s2, 8, arg0->unk_00016, 0x32, 0x32, 0x32);

    if (sp64 < 3) {
        sp64 = 3;
    }

    if (arg0->unk_00016 == 0x110) {
        if ((arg0->unk_00001 == 0xC) || (arg0->unk_00001 == 0xB)) {
            if (arg0->unk_00018 > 0) {
                sp66 = ((((arg0->unk_0000D * 4) + arg0->unk_00018) * 0xF8) - 0x3E0) / ((sp64 * 4) - 4);
            } else {
                sp66 = ((((arg0->unk_0000D * 4) + arg0->unk_00018) * 0xF8) + 0x3E0) / ((sp64 * 4) - 4);
            }
        } else {
            sp66 = (arg0->unk_0000D * 0xF8) / (sp64 - 1);
        }

        gSPDisplayList(gDisplayListHead++, D_8006F558);
        gDPSetEnvColor(gDisplayListHead++, 130, 130, 220, 255);
        gDPSetPrimColor(gDisplayListHead++, 0, 0, 60, 60, 150, 255);

        func_8001CADC(sp62 + 4, temp_s2 + 4, 0x10, 8, D_200A200, 0x10, 0);
        func_8001CADC(sp62 + 4, temp_s2 + 0x104, 0x10, 8, D_200A280, 0x10, 0);
        func_8001C330(sp62 + 4, temp_s2 + 0xC, 0x10, 0xF8, 0, 0, 0x400, 0, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        if (D_84211888 < 4) {
            func_8001C6AC(sp62, temp_s2 + sp66, 0x18, 0x18, D_200A300, 0x18, 0);
        } else {
            func_8001C6AC(sp62, temp_s2 + sp66, 0x18, 0x18, D_200A780, 0x18, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    if (arg0->unk_00001 == 2) {
        D_84211888 = (D_84211888 + 1) % 8;
    }
}

void func_8420EA88(unk_D_84229EB0* arg0) {
    s16 sp1E = arg0->unk_00012 + 0x24;
    s16 temp_a1 = arg0->unk_00014 + ((arg0->unk_0000D - arg0->unk_0000C) * 0x5C) + 0x20;

    if (arg0->unk_00001 == 0xB) {
        if (arg0->unk_00018 > 0) {
            temp_a1 = ((temp_a1 + ((arg0->unk_00018 * 0x5C) / 4)) - 0x5C);
        } else {
            temp_a1 = (temp_a1 + ((arg0->unk_00018 * 0x5C) / 4) + 0x5C);
        }
        func_84200738(sp1E, temp_a1, 0x200, 0x58);
    } else if ((arg0->unk_00001 == 2) || (arg0->unk_00001 == 0xC)) {
        func_84200738(sp1E, temp_a1, 0x200, 0x58);
    }
}

void func_8420EB7C(unk_D_84229EB0* arg0) {
    s16 temp_s0 = arg0->unk_00012 + (arg0->unk_00008 * 0x84) + 0x98;
    s16 temp_a1 = arg0->unk_00014 + (arg0->unk_0000A * 0x2C) + 0x20;

    if (arg0->unk_00001 == 0xA) {
        if (arg0->unk_00018 > 0) {
            temp_a1 = ((temp_a1 + ((arg0->unk_00018 * 0x2C) / 4)) - 0x2C);
        } else {
            temp_a1 = (temp_a1 + ((arg0->unk_00018 * 0x2C) / 4) + 0x2C);
        }
        func_84200738(temp_s0, temp_a1, 0x84, 0x2C);
    } else if (arg0->unk_00001 == 9) {
        if (arg0->unk_00018 > 0) {
            temp_s0 = ((temp_s0 + ((arg0->unk_00018 * 0x84) / 4)) - 0x84);
        } else {
            temp_s0 = (temp_s0 + ((arg0->unk_00018 * 0x84) / 4) + 0x84);
        }
        func_84200738(temp_s0, temp_a1, 0x84, 0x2C);
    } else if (arg0->unk_00001 == 8) {
        func_84200738(temp_s0, temp_a1, 0x84, 0x2C);
    }
}

void func_8420ED0C(unk_D_84229EB0* arg0) {
    s16 i;
    s16 temp_s4;
    s16 temp_s5;
    s16 var_s0;
    unk_D_84229EB0_00024* var_s1;

    var_s1 = arg0->unk_00024;
    temp_s5 = arg0->unk_00012 + 0x24;
    temp_s4 = arg0->unk_00014 + 0x20;

    var_s0 = (arg0->unk_00016 - ((arg0->unk_0000D - arg0->unk_0000C) * 0x5C)) - 0x58;
    if (var_s0 > 0) {
        var_s0 = 0;
    }
    func_800060E0(&gDisplayListHead, 0, temp_s4, 0x280, arg0->unk_00016);

    for (i = 0; i < 3; i++) {
        if ((var_s0 >= -0x5B) && (var_s0 < arg0->unk_00016)) {
            func_8420DD14(arg0, temp_s5, temp_s4 + var_s0, var_s1);
        }
        var_s0 += 0x5C;
        var_s1 = var_s1->unk_4D24;
    }

    func_800060E0(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
}

void func_8420EE54(unk_D_84229EB0* arg0, s32 arg1) {
    UNUSED s32 pad;
    s32 i;
    char* temp_v0_3;
    unk_D_84229EB0_00024* var_s0;
    s16 tmp1;
    s16 tmp2;
    s16 sp42;

    tmp1 = arg0->unk_00012;
    tmp2 = arg0->unk_00014;

    if ((arg0->unk_00001 != 1) && (arg0->unk_00001 != 0) && ((arg1 != 0) || (arg0->unk_00004 != 0))) {
        func_842001B8(tmp1, tmp2, 0x228, arg0->unk_00016 + 0x24);
        func_8420E46C(tmp1 + 4, tmp2 + 4);
        func_8420E63C(arg0);

        if (arg0->unk_00001 == 0xC) {
            sp42 = tmp2 - ((arg0->unk_00018 * 0x5C) / 4);
            func_800060E0(&gDisplayListHead, tmp1 + 0x24, tmp2 + 0x20, 0x200, 0x110);
            if (arg0->unk_0001A > 0) {
                var_s0 = arg0->unk_00024->unk_4D28;
                for (i = 0; i < 4; i++) {
                    func_8420DD14(arg0, tmp1 + 0x24, sp42 + 0x20 + i * 0x5C, var_s0);
                    var_s0 = var_s0->unk_4D24;
                }
            } else {
                var_s0 = arg0->unk_00024;
                for (i = 0; i < 4; i++) {
                    func_8420DD14(arg0, tmp1 + 0x24, sp42 - 0x3C + i * 0x5C, var_s0);
                    var_s0 = var_s0->unk_4D24;
                }
            }
            func_800060E0(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
        } else {
            func_8420ED0C(arg0);
        }

        func_8420EA88(arg0);
        func_8420EB7C(arg0);

        if ((arg1 != 0) && (arg0->unk_00000 == 1)) {
            func_8420112C(0x38, 0x190, 0x210, 0x28, 0x1E, 0x1E, 0x82, 0x96);
            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            temp_v0_3 = func_84200130(0x10);
            func_8001F1E8(0x140 - (func_8001F5B0(0x10, 0, temp_v0_3) / 2), 0x198, temp_v0_3);
            func_8001F444();
        }

        if ((arg1 != 0) && (arg0->unk_00000 == 2)) {
            func_8420112C(0x38, 0x190, 0x210, 0x28, 0x64, 0x1E, 0x1E, 0x96);
            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            temp_v0_3 = func_84200130(0x11);
            func_8001F1E8(0x140 - (func_8001F5B0(0x10, 0, temp_v0_3) / 2), 0x198, temp_v0_3);
            func_8001F444();
        }

        if (arg0->unk_00004 > 0) {
            arg0->unk_00004--;
        }
    }
}

unk_D_84229EB0_00024* func_8420F1BC(unk_D_84229EB0_00024* arg0, s32 arg1) {
    while (arg1-- > 0) {
        arg0 = arg0->unk_4D28;
    }

    return arg0;
}

unk_D_84229EB0_00024* func_8420F1E0(unk_D_84229EB0_00024* arg0, s32 arg1) {
    while (arg1-- > 0) {
        arg0 = arg0->unk_4D24;
    }

    return arg0;
}

s32 func_8420F204(unk_D_84229EB0_00024* arg0, s16 arg1) {
    s16 i;
    s16 var_s4;
    unk_func_80022C28_ret* temp_v0;

    var_s4 = 0;
    arg0->unk_4D10 = 0;
    arg0->unk_4D12[0] = 0;

    for (i = 0; i < 6; i++) {
        arg0->unk_0000[i].unk_004.unk_00.unk_00 = 0;
        arg0->unk_0000[i].raw = 0;
    }

    temp_v0 = func_80022C28(0x10, 0, arg1, 0);
    if (temp_v0 != NULL) {
        for (i = 0; i < 6; i++) {
            var_s4 += func_80022E18(&arg0->unk_0000[i].unk_004, 1, temp_v0);
        }
        func_80022D8C(temp_v0);
        arg0->unk_4D10 = func_80027184(0x10, arg1);
        func_800272BC(0x10, arg1, arg0->unk_4D12);
    }

    for (i = 0; i < var_s4; i++) {
        func_8001B0DC(arg0->unk_0000[i].unk_058, 0, &arg0->unk_0000[i].unk_004);
        arg0->unk_0000[i].unk_000 = 4;
        arg0->unk_0000[i].unk_001 = arg1;
        arg0->unk_0000[i].unk_002 = i;
        arg0->unk_0000[i].unk_003 = arg0->unk_0000[i].unk_004.unk_00.unk_00;
    }

    arg0->unk_4D1E = arg1;
    arg0->unk_4D20 = var_s4;

    return var_s4;
}

void func_8420F37C(unk_D_84229EB0* arg0) {
    s16 temp_s1;
    s16 sp34;
    s16 sp32;
    unk_D_84229EB0_00024* temp_v0_2;

    if (arg0->unk_00006 == 1) {
        temp_s1 = arg0->unk_00008 + (arg0->unk_0000A * 3);
        sp34 = arg0->unk_0000E + (arg0->unk_00008 * 0x84) + 0x94;
        sp32 = arg0->unk_00010 + (arg0->unk_0000A * 0x2C) + 0x1C;
        temp_v0_2 = func_8420F1E0(arg0->unk_00024, arg0->unk_0000D - arg0->unk_0000C);
        if (arg0->unk_00005 == -1) {
            func_8420C60C(arg0->unk_134F0, arg0->unk_00003, 0x30, 0xEC, sp34, sp32, &temp_v0_2->unk_0000[temp_s1], 0);
        } else if (temp_s1 != arg0->unk_00005) {
            func_8420C6D8(arg0->unk_134F0, sp34, sp32, &temp_v0_2->unk_0000[temp_s1]);
            arg0->unk_00006 = 0xA;
        }
        arg0->unk_00005 = temp_s1;
    }

    if (arg0->unk_00006 < 0xA) {
        arg0->unk_00006++;
    }
}

void func_8420F4FC(unk_D_84229EB0* arg0) {
    arg0->unk_00008 = 0;
    arg0->unk_0000A = 0;
    arg0->unk_00006 = 0;
    arg0->unk_00005 = -1;
    arg0->unk_00001 = 0xD;
    arg0->unk_00002 = 8;
}

void func_8420F524(unk_D_84229EB0* arg0) {
    arg0->unk_00012 = arg0->unk_0000E + 0x280;
    arg0->unk_00014 = arg0->unk_00010;
}

void func_8420F53C(unk_D_84229EB0* arg0) {
    arg0->unk_00006++;
    if (arg0->unk_00006 == 0xA) {
        arg0->unk_00001 = 2;
        arg0->unk_00006 = 0;
        arg0->unk_00012 = arg0->unk_0000E;
    } else {
        arg0->unk_00012 = (arg0->unk_0000E - (arg0->unk_00006 << 6)) + 0x280;
    }
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00004 = 2;
}

void func_8420F598(unk_D_84229EB0* arg0) {
    arg0->unk_00006++;
    if (arg0->unk_00006 == 0xA) {
        arg0->unk_00001 = 0;
        arg0->unk_00006 = 0;
        arg0->unk_00012 = arg0->unk_0000E + 0x280;
    } else {
        arg0->unk_00012 = arg0->unk_0000E - (arg0->unk_00006 << 6);
    }
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00004 = 2;
}

void func_8420F5F0(unk_D_84229EB0* arg0) {
    arg0->unk_00006++;
    if (arg0->unk_00006 == 0x14) {
        arg0->unk_00001 = 0x11;
        arg0->unk_00006 = 0;
        arg0->unk_00012 = arg0->unk_0000E;
    } else {
        arg0->unk_00012 = (arg0->unk_0000E - (arg0->unk_00006 << 5)) + 0x280;
    }
    arg0->unk_00016 = 0x58;
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00004 = 2;
}

void func_8420F654(unk_D_84229EB0* arg0) {
    unk_D_84229EB0_00024* sp24;

    if (arg0->unk_0001E == 0) {
        if ((arg0->unk_0000D - arg0->unk_0000C) > 0) {
            arg0->unk_0000D--;
            arg0->unk_00018 = -1;
            arg0->unk_0001A = -4;
            arg0->unk_00002 = 2;
            arg0->unk_00001 = 0xB;
            func_80048B90(1);
        } else if (arg0->unk_0000C > 0) {
            sp24 = func_8420F1BC(arg0->unk_00024, 1);
            func_80048B90(1);
            func_8420F204(sp24, arg0->unk_0000D - 1);
            arg0->unk_0000C -= 1;
            arg0->unk_0000D -= 1;
            arg0->unk_00024 = arg0->unk_00024->unk_4D28;
            arg0->unk_00018 = -1;
            arg0->unk_0001A = -4;
            arg0->unk_00002 = 2;
            arg0->unk_00001 = 0xC;
        }
        arg0->unk_0001E = arg0->unk_0001F;
        arg0->unk_0001F = 2;
    }
}

void func_8420F754(unk_D_84229EB0* arg0) {
    if (arg0->unk_0001E == 0) {
        if ((arg0->unk_0000D - arg0->unk_0000C) < 2) {
            arg0->unk_0000D++;
            arg0->unk_00018 = 1;
            arg0->unk_0001A = 4;
            arg0->unk_00002 = 2;
            arg0->unk_00001 = 0xB;
            func_80048B90(1);
        } else if ((arg0->unk_0000C < 7) &&
                   ((func_8420F204(func_8420F1E0(arg0->unk_00024, 3), arg0->unk_0000D + 1) != 0) ||
                    (arg0->unk_00000 != 0))) {
            func_80048B90(1);
            arg0->unk_0000C += 1;
            arg0->unk_0000D += 1;
            arg0->unk_00024 = arg0->unk_00024->unk_4D24;
            arg0->unk_00018 = 1;
            arg0->unk_0001A = 4;
            arg0->unk_00002 = 2;
            arg0->unk_00001 = 0xC;
        }
        arg0->unk_0001E = arg0->unk_0001F;
        arg0->unk_0001F = 2;
    }
}

void func_8420F86C(unk_D_84229EB0* arg0) {
    Controller* cont = &gControllers[arg0->unk_00003];
    unk_D_84229EB0_00024* temp_v0 = func_8420F1E0(arg0->unk_00024, arg0->unk_0000D - arg0->unk_0000C);

    if (BTN_IS_PRESSED(cont, BTN_A)) {
        if (temp_v0->unk_0000[0].unk_004.unk_00.unk_00 != 0) {
            func_80048B90(2);

            switch (arg0->unk_00000) {
                case 0:
                    arg0->unk_00001 = 5;
                    break;

                case 1:
                    func_8420F4FC(arg0);
                    break;

                case 2:
                    arg0->unk_00001 = 6;
                    break;
            }
        } else {
            func_80048B90(8);
        }
    } else if (BTN_IS_PRESSED(cont, BTN_B)) {
        func_80048B90(3);
        arg0->unk_00020 = 1;
        arg0->unk_00006 = 0;
        arg0->unk_00001 = 4;
    } else if (BTN_IS_DOWN(cont, BTN_DUP)) {
        func_8420F654(arg0);
    } else if (BTN_IS_DOWN(cont, BTN_DDOWN)) {
        func_8420F754(arg0);
    } else {
        arg0->unk_0001F = 8;
        arg0->unk_0001E = 0;
    }
    arg0->unk_00012 = arg0->unk_0000E;
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00004 = 2;
}

void func_8420F9C8(unk_D_84229EB0* arg0) {
    if (arg0->unk_00008 > 0) {
        unk_D_84229EB0_00024* ptr = func_8420F1E0(arg0->unk_00024, arg0->unk_0000D - arg0->unk_0000C);
        s32 idx = ((arg0->unk_0000A * 3) + arg0->unk_00008) - 1;

        if (ptr->unk_0000[idx].unk_004.unk_00.unk_00 != 0) {
            arg0->unk_00008 = arg0->unk_00008 - 1;
            arg0->unk_00018 = -1;
            arg0->unk_0001A = -4;
            arg0->unk_00006 = 0;
            arg0->unk_00002 = 8;
            arg0->unk_00001 = 9;
            func_80048B90(1);
        }
    }
}

void func_8420FA88(unk_D_84229EB0* arg0) {
    if (arg0->unk_00008 < 2) {
        unk_D_84229EB0_00024* ptr = func_8420F1E0(arg0->unk_00024, arg0->unk_0000D - arg0->unk_0000C);
        s32 idx = ((arg0->unk_0000A * 3) + arg0->unk_00008) + 1;

        if (ptr->unk_0000[idx].unk_004.unk_00.unk_00 != 0) {
            arg0->unk_00008++;
            arg0->unk_00018 = 1;
            arg0->unk_0001A = 4;
            arg0->unk_00006 = 0;
            arg0->unk_00002 = 8;
            arg0->unk_00001 = 9;
            func_80048B90(1);
        }
    }
}

void func_8420FB4C(unk_D_84229EB0* arg0) {
    if (arg0->unk_0000A > 0) {
        unk_D_84229EB0_00024* ptr = func_8420F1E0(arg0->unk_00024, arg0->unk_0000D - arg0->unk_0000C);
        s32 idx = ((arg0->unk_0000A * 3) + arg0->unk_00008) - 3;

        if (ptr->unk_0000[idx].unk_004.unk_00.unk_00 != 0) {
            arg0->unk_0000A--;
            arg0->unk_00018 = -1;
            arg0->unk_0001A = -4;
            arg0->unk_00006 = 0;
            arg0->unk_00002 = 8;
            arg0->unk_00001 = 0xA;
            func_80048B90(1);
        }
    }
}

void func_8420FC0C(unk_D_84229EB0* arg0) {
    if (arg0->unk_0000A <= 0) {
        unk_D_84229EB0_00024* ptr = func_8420F1E0(arg0->unk_00024, arg0->unk_0000D - arg0->unk_0000C);
        s32 idx = ((arg0->unk_0000A * 3) + arg0->unk_00008) + 3;

        if (ptr->unk_0000[idx].unk_004.unk_00.unk_00 != 0) {
            arg0->unk_0000A = arg0->unk_0000A + 1;
            arg0->unk_00018 = 1;
            arg0->unk_0001A = 4;
            arg0->unk_00006 = 0;
            arg0->unk_00002 = 8;
            arg0->unk_00001 = 0xA;
            func_80048B90(1);
        }
    }
}

void func_8420FCCC(unk_D_84229EB0* arg0) {
    Controller* cont = &gControllers[arg0->unk_00003];

    func_8420F37C(arg0);

    if (arg0->unk_00006 == 0xA) {
        if (func_8420C788(arg0->unk_134F0) != 0) {
            if (arg0->unk_00000 == 2) {
                arg0->unk_00002 = 6;
            } else {
                arg0->unk_00002 = 2;
            }
            arg0->unk_00001 = 0xE;
        } else if (BTN_IS_PRESSED(cont, BTN_DUP)) {
            func_8420FB4C(arg0);
        } else if (BTN_IS_PRESSED(cont, BTN_DDOWN)) {
            func_8420FC0C(arg0);
        } else if (BTN_IS_PRESSED(cont, BTN_DRIGHT)) {
            func_8420FA88(arg0);
        } else if (BTN_IS_PRESSED(cont, BTN_DLEFT)) {
            func_8420F9C8(arg0);
        }
    }
    arg0->unk_00012 = arg0->unk_0000E;
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00004 = 2;
}

void func_8420FDDC(unk_D_84229EB0* arg0) {
    if (arg0->unk_0001A > 0) {
        arg0->unk_00018++;
        if (arg0->unk_00018 >= arg0->unk_0001A) {
            arg0->unk_00001 = arg0->unk_00002;
        }
    } else {
        arg0->unk_00018--;
        if (arg0->unk_0001A >= arg0->unk_00018) {
            arg0->unk_00001 = arg0->unk_00002;
        }
    }
    arg0->unk_00012 = arg0->unk_0000E;
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00004 = 2;
}

void func_8420FE50(unk_D_84229EB0* arg0) {
    if (arg0->unk_00016 == 0x58) {
        if (arg0->unk_00006 == 0) {
            arg0->unk_00001 = arg0->unk_00002;
        } else {
            arg0->unk_00006--;
        }
    } else {
        arg0->unk_00016 -= 0x2E;
    }
    arg0->unk_00004 = 2;
}

void func_8420FE90(unk_D_84229EB0* arg0) {
    arg0->unk_00016 += 0x2E;
    if (arg0->unk_00016 == 0x110) {
        arg0->unk_00001 = arg0->unk_00002;
    }
    arg0->unk_00004 = 2;
}

void func_8420FEC0(unk_D_84229EB0* arg0) {
    s16 sp26 = 4;

    if ((arg0->unk_0000D - arg0->unk_0000C) == 2) {
        sp26 = 5;
    }

    func_8420DA28(sp26, &gControllers[arg0->unk_00003]);

    switch (func_8420DB48(sp26)) {
        case 0:
            arg0->unk_00001 = 2;
            break;

        case 1:
            arg0->unk_00006 = 8;
            arg0->unk_00001 = 0xD;
            arg0->unk_00002 = 4;
            break;

        case 2:
            arg0->unk_00001 = 2;
            break;

        case 3:
            func_8420F4FC(arg0);
            break;
    }

    arg0->unk_00012 = arg0->unk_0000E;
    arg0->unk_00014 = arg0->unk_00010;
}

void func_8420FFB0(unk_D_84229EB0* arg0) {
    s16 sp26 = 6;

    if ((arg0->unk_0000D - arg0->unk_0000C) == 2) {
        sp26 = 7;
    }

    func_8420DA28(sp26, &gControllers[arg0->unk_00003]);

    switch (func_8420DB48(sp26)) {
        case 0:
            arg0->unk_00001 = 2;
            break;

        case 1:
            arg0->unk_00006 = 0;
            arg0->unk_00001 = 0xD;
            arg0->unk_00002 = 0xF;
            break;

        case 2:
            func_8420F4FC(arg0);
            break;

        case 3:
            arg0->unk_00001 = 2;
            break;
    }

    arg0->unk_00012 = arg0->unk_0000E;
    arg0->unk_00014 = arg0->unk_00010;
}

void func_8421009C(unk_D_84229EB0* arg0) {
    s32 sp24;

    if (func_80028E68() == 0) {
        sp24 = 0x13;
    } else {
        sp24 = 9;
    }

    func_8420DA28(sp24, &gControllers[arg0->unk_00003]);

    switch (func_8420DB48(sp24)) {
        case 1:
            arg0->unk_00006 = 0;
            arg0->unk_00001 = 0xE;
            arg0->unk_00002 = 0x13;
            break;

        case 0:
        case 2:
            arg0->unk_00006 = 0;
            arg0->unk_00001 = 4;
            break;
    }

    arg0->unk_00012 = arg0->unk_0000E;
    arg0->unk_00014 = arg0->unk_00010;
}

void func_8421015C(unk_D_84229EB0* arg0) {
    unk_D_84229EB0_00024* temp_v0;
    s16 temp_hi;
    s16 temp_lo;

    temp_v0 = func_8420F1E0(arg0->unk_00024, arg0->unk_0000D - arg0->unk_0000C);
    temp_lo = arg0->unk_00006 / 12;
    temp_hi = arg0->unk_00006 % 12;

    if (temp_lo < temp_v0->unk_4D20) {
        if (temp_hi < 8) {
            temp_v0->unk_0000[temp_lo].raw = temp_hi + 0x80000000;
        } else {
            temp_v0->unk_0000[temp_lo].raw = 1;
        }

        if (temp_hi == 4) {
            temp_v0->unk_0000[temp_lo].unk_004.unk_00.unk_00 = 0;
            func_8001B0DC(temp_v0->unk_0000[temp_lo].unk_058, 0x84, NULL);
            func_80048B90(0x01100010);
        }
    }

    if (((temp_v0->unk_4D20 * 0xC) - 1) >= arg0->unk_00006) {
        if (arg0->unk_00006 == ((temp_v0->unk_4D20 * 0xC) - 1)) {
            temp_v0->unk_4D20 = -1;
            func_8420DC78(temp_v0);
            func_8420DA28(8, &gControllers[arg0->unk_00003]);
        }
        arg0->unk_00006 += 1;
    } else if (func_8420DB48(8) >= 0) {
        arg0->unk_00001 = 7;
    }

    arg0->unk_00012 = arg0->unk_0000E;
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00004 = 2;
}

void func_84210328(unk_D_84229EB0* arg0) {
    s32 i;
    unk_D_84229EB0_00024* temp_a3;
    s16 temp_hi;
    s16 temp_lo;
    unk_D_84229EB0_00024* temp_v0;

    temp_a3 = arg0->unk_00024;
    temp_v0 = temp_a3->unk_4D24;

    temp_lo = arg0->unk_00006 / 12;
    temp_hi = arg0->unk_00006 % 12;

    if (arg0->unk_00006 == 0) {
        temp_a3->unk_4D20 = 0;
        for (i = 0; i < 6; i++) {
            if (temp_v0->unk_0000[i].unk_004.unk_00.unk_00 != 0) {
                temp_a3->unk_4D20++;
            }
        }
    }

    if (temp_lo < temp_a3->unk_4D20) {
        if (temp_hi < 8) {
            temp_a3->unk_0000[temp_lo].raw = temp_hi + 0x80000000;
        } else {
            temp_a3->unk_0000[temp_lo].raw = temp_v0->unk_0000[temp_lo].raw;
        }

        if (temp_hi == 4) {
            temp_a3->unk_0000[temp_lo].unk_004.unk_00.unk_00 = temp_v0->unk_0000[temp_lo].unk_004.unk_00.unk_00;
            _bcopy(temp_v0->unk_0000[temp_lo].unk_058, temp_a3->unk_0000[temp_lo].unk_058,
                   sizeof(temp_v0->unk_0000[temp_lo].unk_058));
            func_80048B90(0x01100010);
        }
    }

    if ((temp_a3->unk_4D20 * 0xC) - 1 >= arg0->unk_00006) {
        if (arg0->unk_00006 == (temp_a3->unk_4D20 * 0xC) - 1) {
            func_8420DBA0(temp_a3);
            func_8420DA28(0xB, &gControllers[arg0->unk_00003]);
        }
        arg0->unk_00006++;
    } else if (func_8420DB48(0xB) >= 0) {
        if (func_80028E68() >= 0xA) {
            func_842079F0(arg0->unk_134E8);
            arg0->unk_00006 = 0;
            arg0->unk_00001 = 4;
        } else {
            arg0->unk_00001 = 0x12;
        }
    }

    arg0->unk_00012 = arg0->unk_0000E;
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00004 = 2;
}

void func_8421059C(unk_D_84229EB0* arg0) {
    func_8420DA28(0xC, &gControllers[arg0->unk_00003]);

    switch (func_8420DB48(0xC)) {
        case 1:
            func_84207A1C(arg0->unk_134E8);
            func_8420B20C(arg0->unk_134EC);
            arg0->unk_00006 = 0;
            arg0->unk_00001 = 4;
            break;

        case 0:
        case 2:
            func_842079F0(arg0->unk_134E8);
            arg0->unk_00006 = 0;
            arg0->unk_00001 = 4;
            break;
    }

    arg0->unk_00012 = arg0->unk_0000E;
    arg0->unk_00014 = arg0->unk_00010;
}

void func_84210668(unk_D_84229EB0* arg0) {
    s32 i;
    unk_D_84229EB0_00024* var_s1;

    arg0->unk_00006++;

    if (arg0->unk_00006 == 4) {
        var_s1 = arg0->unk_00024;
        for (i = 0; i < 3; i++) {
            func_8420F204(var_s1, arg0->unk_0000C + i);
            var_s1 = var_s1->unk_4D24;
        }

        arg0->unk_00004 = 2;
        arg0->unk_00006 = 0;
        arg0->unk_00001 = 2;
    }
}

s32 func_842106FC(unk_D_84229EB0* arg0) {
    s32 sp1C = 0;

    if (arg0->unk_0001E > 0) {
        arg0->unk_0001E--;
    }

    switch (arg0->unk_00001) {
        case 0:
            func_8420F524(arg0);
            break;

        case 1:
            func_8420F524(arg0);
            break;

        case 2:
            func_8420F86C(arg0);
            break;

        case 3:
            func_8420F53C(arg0);
            sp1C = 1;
            break;

        case 4:
            func_8420F598(arg0);
            sp1C = 1;
            break;

        case 8:
            func_8420FCCC(arg0);
            break;

        case 9:
            func_8420FDDC(arg0);
            break;

        case 10:
            func_8420FDDC(arg0);
            break;

        case 12:
            func_8420FDDC(arg0);
            break;

        case 11:
            func_8420FDDC(arg0);
            break;

        case 5:
            func_8420FEC0(arg0);
            break;

        case 6:
            func_8420FFB0(arg0);
            break;

        case 7:
            func_8421009C(arg0);
            break;

        case 13:
            func_8420FE50(arg0);
            sp1C = 1;
            break;

        case 14:
            func_8420FE90(arg0);
            sp1C = 1;
            break;

        case 15:
            func_8421015C(arg0);
            break;

        case 16:
            func_8420F5F0(arg0);
            sp1C = 1;
            break;

        case 17:
            func_84210328(arg0);
            break;

        case 18:
            func_8421059C(arg0);
            break;

        case 19:
            func_84210668(arg0);
            break;
    }
    return sp1C;
}

s32 func_8421089C(unk_D_84229EB0* arg0, unk_D_84211B50* arg1, unk_D_842168A0* arg2, unk_D_8423D3A8* arg3, s16 arg4,
                  s16 arg5, s16 arg6, s16 arg7) {
    s32 i;

    arg0->unk_00000 = arg4;
    arg0->unk_00001 = 1;
    arg0->unk_00003 = arg7;
    arg0->unk_00006 = 0;
    arg0->unk_0000C = 0;
    arg0->unk_0000D = 0;
    arg0->unk_00008 = 0;
    arg0->unk_0000A = 0;
    arg0->unk_0000E = arg5;
    arg0->unk_00010 = arg6;
    arg0->unk_00012 = arg5 + 0x280;
    arg0->unk_00014 = arg6;
    arg0->unk_00016 = 0x110;
    arg0->unk_0001C = 0xA;
    arg0->unk_0001E = 0;
    arg0->unk_0001F = 8;
    arg0->unk_134E8 = arg1;
    arg0->unk_134EC = arg2;
    arg0->unk_134F0 = arg3;
    arg0->unk_00024 = arg0->unk_00028;

    for (i = 0; i < 4; i++) {
        arg0->unk_00028[i].unk_4D24 = &arg0->unk_00028[(i + 1) & 3];
        arg0->unk_00028[i].unk_4D28 = &arg0->unk_00028[(i - 1) & 3];
    }

    if (arg4 != 3) {
        if (arg4 != 4) {
            for (i = 0; i < 3; i++) {
                func_8420F204(&arg0->unk_00028[i], arg0->unk_0000C + i);
            }
        }
    }

    if (arg0->unk_00000 == 0) {
        arg0->unk_0001C = func_80028E68();
    }
    return 4;
}

s32 func_84210A18(unk_D_84229EB0* arg0) {
    if (arg0->unk_00001 != 1) {
        return 0;
    }
    arg0->unk_00020 = 0;
    arg0->unk_00006 = 0;
    arg0->unk_00001 = 3;
    return 1;
}

s32 func_84210A48(unk_D_84229EB0* arg0, u16 arg1, char* arg2, unk_D_838067F0_0168_0000* arg3) {
    unk_D_84229EB0_00024* ptr = arg0->unk_00028;
    s16 i;

    _bcopy(arg3, &arg0->unk_00028[0], sizeof(unk_D_838067F0_0168_0000) * 6);
    _bcopy(arg3, &arg0->unk_00028[1], sizeof(unk_D_838067F0_0168_0000) * 6);
    ptr->unk_4D1E = func_80028E68();
    ptr->unk_4D20 = -1;
    ptr->unk_4D10 = arg1;
    HAL_Strcpy(ptr->unk_4D12, arg2);

    for (i = 0; i < 6; i++) {
        if (ptr->unk_0000[i].unk_004.unk_00.unk_00 != 0) {
            ptr->unk_0000[i].unk_004.unk_00.unk_00 = 0;
            ptr->unk_0000[i].raw = 1;
            func_8001B0DC(ptr->unk_0000[i].unk_058, 0x84, NULL);
        } else {
            ptr->unk_0000[i].raw = 0;
        }
    }

    arg0->unk_00006 = 0;
    arg0->unk_00001 = 0x10;
    return 1;
}

s32 func_84210B54(unk_D_84229EB0* arg0) {
    return arg0->unk_00001 == 0;
}

s32 func_84210B60(unk_D_84229EB0* arg0, unk_D_84229EB0_00024** arg1) {
    s32 i;
    s16 var_t0 = 0;

    *arg1 = NULL;

    if (arg0->unk_00020 == 0) {
        *arg1 = func_8420F1E0(arg0->unk_00024, arg0->unk_0000D - arg0->unk_0000C);
        var_t0 = (*arg1)->unk_4D20;

        for (i = 0; i < 6; i++) {
            (*arg1)->unk_0000[i].unk_004.unk_52 = 0x40;
            (*arg1)->unk_0000[i].unk_004.unk_53 = arg0->unk_0000D;
        }
    }
    return var_t0;
}

void func_84210C80(unk_D_84229EB0* arg0, s16 arg1) {
    s32 tmp;

    arg0->unk_0000D = arg1;
    if (arg0->unk_0001C < 4) {
        arg0->unk_0000C = 0;
    } else {
        tmp = arg0->unk_0001C - 3;
        if (arg1 < tmp) {
            arg0->unk_0000C = arg1;
        } else {
            arg0->unk_0000C = tmp;
        }
    }

    for (arg1 = 0; arg1 < 3; arg1++) {
        func_8420F204(&arg0->unk_00028[arg1], arg0->unk_0000C + arg1);
    }
}
