#include "fragment55.h"
#include "src/1CF30.h"
#include "src/49790.h"

static s16 D_83003EE0;
static s16 D_83003EE2;
static s16 D_83003EE4;
static s16 D_83003EE6;
static s16 D_83003EE8;
static s16 D_83003EEA;

s32 func_83002270(s8* arg0) {
    s16 var_v1 = 1;

    while (*arg0 != 0) {
        if (*arg0 == '\n') {
            var_v1++;
        }
        arg0++;
    }

    return var_v1;
}

void func_830022B0(void) {
    D_83003EE2--;
    D_83003EE6 = ((5 - D_83003EE2) << 0xA) / 5;
    if (D_83003EE2 <= 0) {
        D_83003EE0 = 2;
        D_83003EE2 = 0;
    }
}

void func_83002324(void) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        D_83003EE0 = 3;
        D_83003EE2 = 5;
        func_80048B90(3);
    }
}

void func_83002370(void) {
    D_83003EE2--;
    D_83003EE6 = (D_83003EE2 << 0xA) / 5;
    if (D_83003EE2 <= 0) {
        D_83003EE0 = 0;
        D_83003EE2 = 0;
    }
}

void func_830023B8(void) {
    D_83003EE0 = 0;
    D_83003EE6 = 0;
}

void func_830023CC(void) {
    if (D_83003EE0 != 0) {
        switch (D_83003EE0) {
            case 1:
                func_830022B0();
                break;

            case 2:
                func_83002324();
                break;

            case 3:
                func_83002370();
                break;
        }
    }
}

void func_8300243C(void) {
    s16 temp_s0;

    if (D_83003EE6 != 0) {
        temp_s0 = D_83003EE8 + (((D_83003EEA / 2) * (0x400 - D_83003EE6)) / 1024);
        func_83000F10(0x48, temp_s0, 0x1F0, (D_83003EEA * D_83003EE6) / 1024);
        if (D_83003EE6 >= 0x400) {
            func_83001178(0x48, temp_s0, 0x1F0, 0x20, 0x1E, 0x64, 0x64);
            func_83001178(0x48, temp_s0 + 0x20, 0x1F0, D_83003EEA - 0x20, 0x3C, 0x3C, 0xA0);
            func_8001F3F4();
            func_8001EBE0(8, 0);
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F3B4(0x18);
            func_8001F1E8(0x50, temp_s0 + 6, D_83003CE0.unk_00[D_83003EE4]);
            func_8001EBE0(8, 0);
            func_8001F1E8(0x50, temp_s0 + 0x28, D_83003DE0.unk_00[D_83003EE4]);
            func_8001F444();
        }
    }
}

void func_830025F8(s16 arg0) {
    s32 tmp;

    D_83003EE0 = 1;
    D_83003EE2 = 5;
    D_83003EE6 = 0;
    D_83003EE4 = arg0;
    tmp = (func_83002270(D_83003DE0.unk_00[D_83003EE4]) * 0x18);
    D_83003EEA = 0x2C + tmp;
    D_83003EE8 = ((0x1E0 - D_83003EEA) / 2) + 0x14;
}

s32 func_8300269C(void) {
    s32 ret;

    if (D_83003EE0 != 0) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

s32 func_830026C0(void) {
    return D_83003EE6;
}
