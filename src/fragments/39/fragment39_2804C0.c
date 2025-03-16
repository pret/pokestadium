#include "fragment39.h"
#include "src/1CF30.h"
#include "src/2E110.h"
#include "src/fragments/2/fragment2.h"

static unk_D_8250A480 D_8250A480;
static unk_D_8250A498 D_8250A498;
static char* D_8250A4B0[9];

void func_82504820(char** arg0) {
    D_8250A480.unk_00 = 0;
    D_8250A480.unk_02 = 0;
    D_8250A480.unk_14 = arg0;
}

s32 func_82504838(void) {
    return D_8250A480.unk_00;
}

void func_82504844(s16 arg0) {
    unk_D_8250A480* ptr = &D_8250A480;

    ptr->unk_00 = arg0;

    switch (ptr->unk_00) {
        case 0:
            ptr->unk_02 = 0;
            ptr->unk_0C = 0;
            ptr->unk_10 = 0.0f;
            break;

        case 1:
            ptr->unk_02 = 0xA;
            ptr->unk_04 = -0xF8;
            ptr->unk_06 = 0x5A;
            ptr->unk_08 = 0x280;
            ptr->unk_0A = 0x15E;
            ptr->unk_10 = 0.0f;
            break;

        case 2:
            ptr->unk_02 = 0x12C;
            ptr->unk_04 = 0xBC;
            ptr->unk_08 = 0x5C;
            ptr->unk_0C = 0;
            break;

        case 3:
            ptr->unk_02 = 0xA;
            ptr->unk_10 = 0.0f;
            break;
    }
}

void func_82504930(unk_D_8250A480* arg0) {
    arg0->unk_02--;
    arg0->unk_04 = ((arg0->unk_02 * -0x1B4) / 10) + 0xBC;
    arg0->unk_08 = ((arg0->unk_02 * 0x224) / 10) + 0x5C;
    if (arg0->unk_02 <= 0) {
        func_82504844(2);
    }
}

void func_82504A08(unk_D_8250A480* arg0) {
    arg0->unk_02 = 0x12C;
    arg0->unk_10 = 0.0f;
    if (arg0->unk_02 <= 0) {
        arg0->unk_0C += 0x1000;
        arg0->unk_10 += 0.05f;
        if (arg0->unk_10 > 4.0f) {
            arg0->unk_10 = 4.0f;
        }
    }
}

void func_82504A68(unk_D_8250A480* arg0) {
    arg0->unk_02--;
    arg0->unk_04 = ((arg0->unk_02 * -0x1C4) / 10) + 0x280;
    arg0->unk_08 = ((arg0->unk_02 * 0x224) / 10) - 0x1C8;
    if (arg0->unk_02 <= 0) {
        func_82504844(0);
    }
}

void func_82504B38(void) {
    unk_D_8250A480* ptr = &D_8250A480;

    if (ptr->unk_00 != 0) {
        switch (ptr->unk_00) {
            case 1:
                func_82504930(ptr);
                break;
            case 2:
                func_82504A08(ptr);
                break;
            case 3:
                func_82504A68(ptr);
                break;
        }
    }
}

void func_82504BB4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 sp48;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x20) {
        var_s3 = 0x10;
    } else {
        var_s3 = arg2 / 2;
    }

    if (arg3 >= 0x20) {
        var_s2 = 0x10;
    } else {
        var_s2 = arg3 / 2;
    }

    sp48 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30CD490, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30CD510, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30CD390, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30CD410, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3,
                  0x4000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((sp48 > 0) && (temp_s0_32 > 0)) {
        func_8001C604(arg0 + var_s3, arg1, sp48, var_s2, arg4, arg5, arg6, arg7);
        func_8001C604(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        func_8001C604(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, sp48, var_s2, arg4, arg5, arg6, arg7);
    } else if (sp48 > 0) {
        func_8001C604(arg0 + var_s3, arg1, sp48, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        func_8001C604(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_825053B4(s16 arg0, s16 arg1, s8* arg2, f32 arg3, s16 arg4) {
    s16 var_s2;
    s8* var_v1;
    s32 i;
    char sp50[4];
    s16 tmp;

    var_s2 = 0;
    while (*arg2) {
        var_v1 = sp50;
        if (*arg2 < 0) {
            for (i = 0; i < 2; i++) {
                *var_v1++ = *arg2++;
            }
            *var_v1 = '\x00';
        } else {
            *var_v1++ = *arg2++;
            *var_v1++ = 0;
        }

        tmp = SINS(arg4 + var_s2) * arg3;
        func_8001F1E8(arg0, arg1 + tmp, sp50);
        var_s2 += 0x3000;
        arg0 += 0x18;
    }
}

void func_825054F4(void) {
    UNUSED s32 pad;
    unk_D_8250A480* ptr = &D_8250A480;
    char* sp2C = func_8002D7C0(NULL, 0, ptr->unk_14, 0);
    char* sp28 = func_8002D7C0(NULL, 0, ptr->unk_14, 1);

    if (ptr->unk_00 != 0) {
        func_82504BB4(ptr->unk_04, ptr->unk_06, 0xF8, 0x2C, 0x1E, 0x1E, 0x82, 0x80);
        func_82504BB4(ptr->unk_08, ptr->unk_0A, 0x1C8, 0x2C, 0x64, 0, 0x50, 0x80);
        func_8001F3F4();
        func_8001EBE0(0x10, 0);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        if (ptr->unk_10 <= 0.0f) {
            func_8001F1E8((ptr->unk_04 - (func_8001F5B0(0, 0, sp2C) / 2)) + 0x7C, ptr->unk_06 + 0xA, sp2C);
            func_8001F1E8((ptr->unk_08 - (func_8001F5B0(0, 0, sp28) / 2)) + 0xE4, ptr->unk_0A + 0xA, sp28);
        } else {
            func_825053B4(ptr->unk_04 + 0x18, ptr->unk_06 + 0xA, sp2C, ptr->unk_10, ptr->unk_0C);
            func_825053B4(ptr->unk_08 + 0x18, ptr->unk_0A + 0xA, sp28, ptr->unk_10, ptr->unk_0C);
        }
        func_8001F444();
    }
}

void func_82505720(char** arg0) {
    s32 i;

    D_8250A498.unk_00 = 0;
    D_8250A498.unk_02 = 0;
    D_8250A498.unk_14 = arg0;

    for (i = 0; i < 9; i++) {
        D_8250A4B0[i] = func_8002D7C0(NULL, 0, arg0, i + 7);
    }
}

void func_825057A0(void) {
}

void func_825057A8(s16 arg0) {
    unk_D_8250A498* ptr = &D_8250A498;

    if (ptr->unk_12 != ptr->unk_10) {
        ptr->unk_10 = ptr->unk_12;
        ptr->unk_0C = ptr->unk_0E;
        ptr->unk_04 = ptr->unk_06;
    }
    ptr->unk_12 = arg0;
    ptr->unk_0E = func_8001F5B0(0, 0, D_8250A4B0[ptr->unk_12], arg0) + 0x30;
    ptr->unk_06 = (0x280 - ptr->unk_0E) / 2;
    ptr->unk_02 = 5;
}

void func_82505874(s16 arg0, s16 arg1) {
    unk_D_8250A498* ptr = &D_8250A498;

    ptr->unk_00 = arg0;

    switch (ptr->unk_00) {
        case 0:
            ptr->unk_02 = 0;
            break;

        case 1:
            ptr->unk_02 = 0xA;
            ptr->unk_10 = ptr->unk_12 = arg1;
            ptr->unk_0C = ptr->unk_0E = func_8001F5B0(0, 0, D_8250A4B0[ptr->unk_12], arg1) + 0x30;
            ptr->unk_04 = ptr->unk_06 = (0x280 - ptr->unk_0C) / 2;
            ptr->unk_08 = -0x2C;
            ptr->unk_0A = 0x1E0;
            break;

        case 2:
            ptr->unk_08 = 0x3C;
            break;

        case 3:
            ptr->unk_02 = 0xA;
            break;
    }
}

void func_82505998(unk_D_8250A498* arg0) {
    arg0->unk_02--;
    arg0->unk_08 = ((arg0->unk_02 * -0x68) / 10) + 0x3C;
    arg0->unk_0A = ((arg0->unk_02 * 0x56) / 10) + 0x18A;
    if (arg0->unk_02 <= 0) {
        func_82505874(2, -1);
    }
}

void func_82505A70(unk_D_8250A498* arg0) {
    if (arg0->unk_10 != arg0->unk_12) {
        arg0->unk_02--;
        if (arg0->unk_02 <= 0) {
            arg0->unk_10 = arg0->unk_12;
            arg0->unk_0C = arg0->unk_0E;
            arg0->unk_04 = arg0->unk_06;
        }
    }
}

void func_82505AB8(unk_D_8250A498* arg0) {
    arg0->unk_02--;
    arg0->unk_08 = ((arg0->unk_02 * 0x68) / 10) - 0x2C;
    arg0->unk_0A = ((arg0->unk_02 * -0x56) / 10) + 0x1E0;
    if (arg0->unk_02 <= 0) {
        func_82505874(0, -1);
    }
}

void func_82505B94(void) {
    unk_D_8250A498* ptr = &D_8250A498;

    if (ptr->unk_00 != 0) {
        switch (ptr->unk_00) {
            case 1:
                func_82505998(ptr);
                break;

            case 2:
                func_82505A70(ptr);
                break;

            case 3:
                func_82505AB8(ptr);
                break;
        }
    }
}

void func_82505C10(void) {
    UNUSED s32 pad;
    unk_D_8250A498* ptr = &D_8250A498;
    char* sp3C;
    s16 tmp;
    char* sp34 = func_8002D7C0(NULL, 0, ptr->unk_14, 0x10);

    if (ptr->unk_00 != 0) {
        if (ptr->unk_10 == ptr->unk_12) {
            func_82504BB4(ptr->unk_04, ptr->unk_08, ptr->unk_0C, 0x2C, 0x1E, 0x1E, 0x82, 0x80);
        } else {
            tmp = (ptr->unk_02 << 7) / 5;
            func_82504BB4(ptr->unk_04, ptr->unk_08, ptr->unk_0C, 0x2C, 0x1E, 0x1E, 0x82, tmp);
            tmp = ((-ptr->unk_02 * 0x80) + 0x280) / 5;
            func_82504BB4(ptr->unk_06, ptr->unk_08, ptr->unk_0E, 0x2C, 0x1E, 0x1E, 0x82, tmp);
        }

        if (D_8780FA48 == -1) {
            func_82504BB4(0x98, ptr->unk_0A, 0x140, 0x2C, 0x64, 0, 0x50, 0x80);
        }

        func_8001F3F4();
        func_8001EBE0(0x10, 0);
        sp3C = D_8250A4B0[ptr->unk_10];
        if (ptr->unk_10 == ptr->unk_12) {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F1E8(ptr->unk_04 + 0x18, ptr->unk_08 + 0xA, sp3C);
        } else {
            tmp = (ptr->unk_02 * 0xFF) / 5;
            func_8001F324(0xFF, 0xFF, 0xFF, tmp);
            func_8001F1E8(ptr->unk_04 + 0x18, ptr->unk_08 + 0xA, sp3C);
            sp3C = D_8250A4B0[ptr->unk_12];
            tmp = ((5 - ptr->unk_02) * 0xFF) / 5;
            func_8001F324(0xFF, 0xFF, 0xFF, tmp);
            func_8001F1E8(ptr->unk_06 + 0x18, ptr->unk_08 + 0xA, sp3C);
        }

        if (D_8780FA48 == -1) {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F1E8(0x140 - (func_878013D4(D_8250A304, sp34) / 2), ptr->unk_0A + 0xA, sp34);
        }
        func_8001F444();
    }
}
