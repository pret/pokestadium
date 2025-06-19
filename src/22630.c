#include "22630.h"
#include "include/string.h"
#include "src/22630.h"
#include "src/26820.h"
#include "src/2E110.h"
#include "src/gb_tower.h"
#include "src/hal_libc.h"
#include "src/util.h"

u16 func_80021A30(u8* arg0) {
    return (arg0[0] << 8) | arg0[1];
}

u32 func_80021A48(u8* arg0) {
    return (arg0[0] << 0x10) | (arg0[1] << 8) | arg0[2];
}

void func_80021A68(u8* arg0, s32 arg1) {
    arg0[0] = (arg1 >> 8) & 0xFF;
    arg0[1] = arg1 & 0xFF;
}

void func_80021A78(u8* arg0, s32 arg1) {
    arg0[0] = (arg1 >> 0x10) & 0xFF;
    arg0[1] = (arg1 >> 8) & 0xFF;
    arg0[2] = (arg1)&0xFF;
}

char* func_80021A90(char* arg0, char* arg1) {
    extern s8 D_80073030[];

    char* sp34 = arg0;
    char* sp18;
    char* temp_s1 = func_8002311C(1);

    while (*arg1 != 'P') {
        if (*arg1 == ']') {
            memcpy(arg0, temp_s1, strlen(temp_s1) + 1);
            arg0 += strlen(temp_s1);
        } else {
            *arg0++ = D_80073030[*arg1];
        }
        arg1++;
    }

    *arg0++ = '\x0';

    return sp34;
}

void func_80021B5C(char* arg0, char* arg1) {
    func_80021A90(arg0, arg1);
}

char* func_80021B7C(char* arg0, char* arg1) {
    extern u8 D_80073130[];

    char* sp1C = arg0;
    char* sp18 = arg1;

    if (HAL_Strcmp(sp18, func_8002311C(1)) == 0) {
        *arg0++ = ']';
    } else {
        while (*sp18 != 0) {
            *arg0++ = D_80073130[*sp18++];
        }
    }

    *arg0++ = 'P';

    return sp1C;
}

char* func_80021C20(char* arg0, char* arg1) {
    return func_80021B7C(arg0, arg1);
}

char* func_80021C40(char* arg0, char* arg1) {
    char sp1C[11];

    _bcopy(arg1, sp1C, 0xA);

    sp1C[10] = 'P';

    return func_80021A90(arg0, sp1C);
}

char* func_80021C80(char* arg0, char* arg1) {
    HAL_Strcpy(arg0, arg1);
    return arg0;
}

char* func_80021CA4(char* arg0, s32 arg1) {
    func_80021C80(arg0, (char*)*(u32*)D_8006FEE8[arg1]);
    return arg0;
}

char* func_80021CE0(s32 arg0, char* arg1) {
    extern char* D_80072EE0[];
    // "ひでんマシン%02d"
    static const char D_0007CCA0[] = { 0xA4, 0xD2, 0xA4, 0xC7, 0xA4, 0xF3, 0xA5, 0xDE, 0xA5, 0xB7,
                                       0xA5, 0xF3, 0x25, 0x30, 0x32, 0x64, 0x00, 0x00, 0x00, 0x00 };
    // "わざマシン%02d"
    static const char D_0007CCB4[] = { 0xA4, 0xEF, 0xA4, 0xB6, 0xA5, 0xDE, 0xA5, 0xB7,
                                       0xA5, 0xF3, 0x25, 0x30, 0x32, 0x64, 0x00, 0x00 };

    if ((arg0 > 0) && (arg0 < 0x54)) {
        HAL_Strcpy(arg1, D_80072EE0[arg0 - 1]);
    } else if ((arg0 >= 0xC4) && (arg0 < 0xC9)) {
        sprintf(arg1, D_0007CCA0, arg0 - 0xC3, arg0);
    } else if ((arg0 >= 0xC9) && (arg0 < 0xFF)) {
        sprintf(arg1, D_0007CCB4, arg0 - 0xC8, arg0);
    } else {
        HAL_Strcpy(arg1, D_80072EE0[6]);
    }

    return arg1;
}

void func_80021D9C(unk_func_80026268_arg0* arg0, unk_D_800AE4E8_004_1_000_010_000* arg1) {
    arg0->unk_00.unk_00 = func_80022A60(arg1->unk_00);
    arg0->unk_00.unk_01 = arg1->unk_00;
    arg0->unk_02 = func_80021A30(arg1->unk_01);

    arg0->unk_04 = arg1->unk_03;
    arg0->unk_05 = arg1->unk_04;
    arg0->unk_06 = arg1->unk_05;
    arg0->unk_07 = arg1->unk_06;
    arg0->unk_08 = arg1->unk_07;

    arg0->unk_0E = func_80021A30(arg1->unk_0C);
    arg0->unk_10 = func_80021A48(arg1->unk_0E);
    arg0->unk_14 = func_80021A30(arg1->unk_11);
    arg0->unk_16 = func_80021A30(arg1->unk_13);
    arg0->unk_18 = func_80021A30(arg1->unk_15);
    arg0->unk_1A = func_80021A30(arg1->unk_17);
    arg0->unk_1C = func_80021A30(arg1->unk_19);
    arg0->unk_1E = func_80021A30(arg1->unk_1B);

    memcpy(arg0->unk_09, arg1->unk_08, 4);
    memcpy(arg0->unk_20, arg1->unk_1D, 4);
}

void func_80021E90(unk_func_80026268_arg0* arg0, unk_D_800AC910_050_9AC_008* arg1) {
    func_80021D9C(arg0, &arg1->unk_00);
    arg0->unk_24 = arg1->unk_21;
    arg0->unk_26 = func_80021A30(&arg1->unk_22);
    arg0->unk_28 = func_80021A30(&arg1->unk_24);
    arg0->unk_2A = func_80021A30(&arg1->unk_26);
    arg0->unk_2C = func_80021A30(&arg1->unk_28);
    arg0->unk_2E = func_80021A30(&arg1->unk_2A);
}

void func_80021F04(unk_func_80026268_arg0* arg0, unk_D_800AE4E8_004_1_000_010_000* arg1) {
    if (func_80022A38(arg0->unk_00.unk_00) & 0xFF) {
        arg1->unk_00 = func_80022A38(arg0->unk_00.unk_00);
    } else {
        arg1->unk_00 = arg0->unk_00.unk_01;
    }

    func_80021A68(arg1->unk_01, (u16)arg0->unk_02);

    arg1->unk_03 = arg0->unk_04;
    arg1->unk_04 = arg0->unk_05;
    arg1->unk_05 = arg0->unk_06;
    arg1->unk_06 = arg0->unk_07;
    arg1->unk_07 = arg0->unk_08;

    func_80021A68(arg1->unk_0C, arg0->unk_0E);
    func_80021A78(arg1->unk_0E, arg0->unk_10);
    func_80021A68(arg1->unk_11, arg0->unk_14);
    func_80021A68(arg1->unk_13, arg0->unk_16);
    func_80021A68(arg1->unk_15, arg0->unk_18);
    func_80021A68(arg1->unk_17, arg0->unk_1A);
    func_80021A68(arg1->unk_19, arg0->unk_1C);
    func_80021A68(arg1->unk_1B, arg0->unk_1E);

    memcpy(arg1->unk_08, arg0->unk_09, 4);
    memcpy(arg1->unk_1D, arg0->unk_20, 4);
}

void func_80022010(unk_func_88205880_00D0* arg0, unk_D_800AC910_050_9AC_008* arg1) {
    func_80021F04(arg0->unk_000, arg1);
    arg1->unk_21 = arg0->unk_000[0].unk_24;
    func_80021A68(&arg1->unk_22, arg0->unk_000[0].unk_26);
    func_80021A68(&arg1->unk_24, arg0->unk_000[0].unk_28);
    func_80021A68(&arg1->unk_26, arg0->unk_000[0].unk_2A);
    func_80021A68(&arg1->unk_28, arg0->unk_000[0].unk_2C);
    func_80021A68(&arg1->unk_2A, arg0->unk_000[0].unk_2E);
}

u16 func_80022084(u16 arg0) {
    u16 i;

    for (i = 1; i < 255; i++) {
        if (SQ(i) >= arg0) {
            break;
        }
    }
    return i;
}

void func_800220C4(void) {
}

u16 func_800220CC(s32 arg0, u16 arg1) {
    u16 sp6;

    switch (arg0) {
        case 1:
            sp6 = ((arg1 & 0x1000) >> 9) | ((arg1 & 0x100) >> 6) | ((arg1 & 0x10) >> 3) | (arg1 & 1);
            break;

        case 2:
            sp6 = (arg1 >> 0xC) & 0xF;
            break;

        case 3:
            sp6 = (arg1 >> 8) & 0xF;
            break;

        case 4:
            sp6 = (arg1 >> 4) & 0xF;
            break;

        case 5:
            sp6 = arg1 & 0xF;
            break;
    }

    return sp6;
}

u32 func_80022170(s32 arg0, s32 arg1, u16 arg2, u16 arg3, u16 arg4) {
    u16 sp1C;
    u16 sp24;
    u16 sp22;

    switch (arg0) {
        case 1:
            sp24 = D_80070F84[arg1].unk_06;
            break;

        case 2:
            sp24 = D_80070F84[arg1].unk_07;
            break;

        case 3:
            sp24 = D_80070F84[arg1].unk_08;
            break;

        case 4:
            sp24 = D_80070F84[arg1].unk_09;
            break;

        case 5:
            sp24 = D_80070F84[arg1].unk_0A[0];
            break;
    }

    sp22 = func_800220CC(arg0, arg4);

    sp1C = (((func_80022084(arg2) / 4) + ((sp24 + sp22) * 2)) * arg3) / 100;
    if (arg0 == 1) {
        sp1C += arg3 + 10;
    } else {
        sp1C += 5;
    }

    if (sp1C > 999) {
        sp1C = 999;
    }

    return sp1C;
}

void func_80022338(unk_func_80026268_arg0* arg0) {
    arg0->unk_24 = func_800226C0(arg0->unk_00.unk_00, arg0->unk_10);
    arg0->unk_26 = func_80022170(1, arg0->unk_00.unk_00, arg0->unk_14, arg0->unk_24, arg0->unk_1E);
    arg0->unk_28 = func_80022170(2, arg0->unk_00.unk_00, arg0->unk_16, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2A = func_80022170(3, arg0->unk_00.unk_00, arg0->unk_18, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2C = func_80022170(4, arg0->unk_00.unk_00, arg0->unk_1A, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2E = func_80022170(5, arg0->unk_00.unk_00, arg0->unk_1C, arg0->unk_24, arg0->unk_1E);
}

u16 func_8002240C(s32 arg0, s32 arg1, u16 arg2, u16 arg3, u16 arg4) {
    s32 i;
    s32 tmp;

    for (i = 1; i < 0xFFFF; i += 2) {
        tmp = func_80022170(arg0, arg1, i + 2, arg3, arg4);
        if (arg2 < tmp) {
            break;
        }
    }

    return i;
}

u32 func_800224B8(s32 arg0, u16 arg1) {
    u32 sp4;

    switch (D_80070F84[arg0].unk_13) {
        case 0:
            sp4 = arg1 * arg1 * arg1;
            break;

        case 1:
            sp4 = (((arg1 * arg1 * arg1 * 3) / 4) + (arg1 * 0xA * arg1)) - 0x1E;
            break;

        case 2:
            sp4 = (((arg1 * arg1 * arg1 * 3) / 4) + (arg1 * 0x14 * arg1)) - 0x1E;
            break;

        case 3:
            sp4 = ((((arg1 * arg1 * arg1 * 6) / 5) - (arg1 * 0xF * arg1)) + (arg1 * 0x64)) - 0x8C;
            break;

        case 4:
            sp4 = (arg1 * arg1 * arg1 * 4) / 5;
            break;

        case 5:
            sp4 = (arg1 * arg1 * arg1 * 5) / 4;
            break;
    }

    return sp4;
}
