#include "fragment41.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/232C0.h"
#include "src/2E110.h"
#include "src/49790.h"
#include "src/6BC0.h"
#include "src/memory.h"

typedef struct unk_D_82F20A00 {
    /* 0x00000 */ u16 unk_00000[3][20][0x640];
} unk_D_82F20A00; // size = 0x2EE00

static unk_D_82F144D0 D_82F144D0[2];
static unk_D_82F20A00* D_82F20A00;
static s16 D_82F20A04;

s16 func_82F01390(unk_D_82F144D0* arg0, s16 arg1) {
    UNUSED s32 pad;
    unk_func_80022C28_ret* var_v0;
    unk_func_82F00838_sp30_00C sp3C;
    unk_D_82F144D0_0CA8* sp34 = &arg0->unk_0CA8[arg1];

    sp34->unk_000 = 0;
    if (arg1 == 0) {
        var_v0 = func_80022C28(0x20, arg0->unk_000E, 0, 0);
    } else {
        var_v0 = func_80022C28(0x21, arg0->unk_000E, arg1 - 1, 0);
    }

    if (var_v0 != NULL) {
        while (func_80022E18(&sp3C, 1, var_v0) == 1) {
            sp34->unk_00C[sp34->unk_000++] = sp3C;
        }
        func_80022D8C(var_v0);
    }
    return sp34->unk_000;
}

u16* func_82F014E4(u8* arg0, s16 arg1, s16 arg2) {
    return arg0 + (arg1 * 0xFA00) + (arg2 * 0xC80);
}

void func_82F01530(s32 arg0, s16 arg1) {
    MainPoolState* temp_v0_2;
    s32 var_s2;
    unk_D_82F144D0* temp_s1;
    s32 i;
    s32 j;
    unk_D_82F144D0_0CA8* ptr1;
    unk_D_82F144D0_0CA8* ptr2;
    unk_func_82F00838_sp30_00C* temp_a3;

    if ((arg0 < 0) || (arg0 >= 2)) {
        return;
    }

    if (func_8002513C(arg1) == 0) {
        func_80024208(arg1);
    }

    D_82F20A04 = arg0;

    main_pool_push_state('PICK');

    temp_s1 = &D_82F144D0[arg0];
    temp_s1->unk_0000 = 1;
    temp_s1->unk_0002 = -1;
    temp_s1->unk_0004 = 0x140;
    temp_s1->unk_0006 = 0xA0;
    temp_s1->unk_0008 = 0;
    temp_s1->unk_000A = 0;
    temp_s1->unk_000C = 0xA;
    temp_s1->unk_0010 = 0;
    temp_s1->unk_0012 = 0;
    temp_s1->unk_0014 = 0;
    temp_s1->unk_0016 = 0;
    temp_s1->unk_0018 = 0;
    temp_s1->unk_001A = 0;
    temp_s1->unk_001C = 0;
    temp_s1->unk_001E = 0;
    temp_s1->unk_0020 = 0;
    temp_s1->unk_000E = arg1;

    var_s2 = 0;

    for (i = 12; i >= 0; i--) {
        if (func_82F01390(temp_s1, i) > 0) {
            temp_s1->unk_0010 = i;
            var_s2++;
        }
        temp_s1->unk_0CA8[i].unk_008 = NULL;
        temp_s1->unk_0CA8[i].unk_004 = NULL;
    }

    for (i = temp_s1->unk_0010; i < 13; i++) {
        ptr1 = &temp_s1->unk_0CA8[i];

        if (ptr1->unk_000 <= 0) {
            continue;
        }

        for (j = i + 1; j < 13; j++) {
            ptr2 = &temp_s1->unk_0CA8[j];

            if (ptr2->unk_000 > 0) {
                ptr1->unk_008 = ptr2;
                ptr2->unk_004 = ptr1;
                break;
            }
        }
    }

    if (var_s2 >= 2) {
        ptr1 = &temp_s1->unk_0CA8[0];
        while (ptr1->unk_000 <= 0) {
            ptr1++;
        }

        ptr2 = &temp_s1->unk_0CA8[12];
        while (ptr2->unk_000 <= 0) {
            ptr2--;
        }

        ptr1->unk_004 = ptr2;
        ptr2->unk_008 = ptr1;
    }

    temp_v0_2 = func_80002D10(main_pool_get_available(), 0);
    D_82F20A00 = func_80002DCC(temp_v0_2, sizeof(unk_D_82F20A00), 8);
    func_80002D60(temp_v0_2);

    for (i = 0; i < temp_s1->unk_0CA8[temp_s1->unk_0010].unk_000; i++) {
        temp_a3 = &temp_s1->unk_0CA8[temp_s1->unk_0010].unk_00C[i];

        if (((temp_a3->unk_00 <= 0) || (temp_a3->unk_00 >= 0x98) ? 1 : 0)) {
            func_8001B0DC(func_82F014E4(D_82F20A00, temp_s1->unk_0016, i), 0x98, NULL);
        } else {
            func_8001B0DC(func_82F014E4(D_82F20A00, temp_s1->unk_0016, i), 0, temp_a3);
        }
    }

    func_80048B90(4);
}

s32 func_82F018F8(void) {
    unk_D_82F144D0* ptr = &D_82F144D0[D_82F20A04];

    return ptr->unk_0000;
}

void func_82F01920(unk_D_82F144D0* arg0) {
    arg0->unk_000C--;

    arg0->unk_0004 = 0x64 - ((arg0->unk_000C * -0xDC) / 10);
    arg0->unk_0006 = 0x70 - ((arg0->unk_000C * -0x30) / 10);
    arg0->unk_0008 = 0x1B8 - ((arg0->unk_000C * 0x1B8) / 10);
    arg0->unk_000A = 0x10C - ((arg0->unk_000C * 0x10C) / 10);

    if (arg0->unk_000C <= 0) {
        arg0->unk_0000 = 2;
        arg0->unk_000C = 0;
    }
}

void func_82F01A70(unk_D_82F144D0* arg0) {
    s32 temp_v1_3;
    s32 var_v0;
    Controller* controller;
    unk_D_82F144D0_0CA8* temp_a2;
    s32 i;
    unk_func_82F00838_sp30_00C* temp_a1;
    unk_func_82F00838_sp30_00C* temp_a3;
    unk_func_82F00838_sp30_00C* temp_a3_2;
    s16 temp_t1;
    u16 temp_v0 = func_8001F750();

    controller = gPlayer1Controller;

    if (arg0->unk_000C > 0) {
        arg0->unk_000C--;
        if (arg0->unk_000C <= 0) {
            arg0->unk_000C = 0;
            arg0->unk_001C = arg0->unk_0018;
            arg0->unk_001E = arg0->unk_001A;
        } else {
            return;
        }
    }

    temp_a2 = &arg0->unk_0CA8[arg0->unk_0010];

    if (temp_v0 & 0x200) {
        arg0->unk_0018--;
        if (arg0->unk_0018 < 0) {
            arg0->unk_0018 = 0;
        }
    }

    if (temp_v0 & 0x100) {
        arg0->unk_0018++;
        if (arg0->unk_0018 >= 5) {
            arg0->unk_0018 = 4;
        }
    }

    if (temp_v0 & 0x800) {
        arg0->unk_001A--;
        if (arg0->unk_001A < 0) {
            arg0->unk_001A = 0;
        }
    }

    if (temp_v0 & 0x400) {
        arg0->unk_001A++;
        if (arg0->unk_001A >= 4) {
            arg0->unk_001A = 3;
        }
    }

    if ((arg0->unk_0018 != arg0->unk_001C) || (arg0->unk_001A != arg0->unk_001E)) {
        arg0->unk_000C = 4;
        func_80048B90(1);
        return;
    }

    temp_v1_3 = (arg0->unk_001A * 5) + arg0->unk_0018;
    temp_a1 = &arg0->unk_0CA8[arg0->unk_0010].unk_00C[temp_v1_3];

    if (BTN_IS_PRESSED(controller, BTN_A) && (temp_v1_3 < arg0->unk_0CA8[arg0->unk_0010].unk_000)) {
        if ((temp_a1->unk_00 <= 0) || (temp_a1->unk_00 >= 0x98)) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }

        if (var_v0 == 0) {
            arg0->unk_0000 = 4;
            arg0->unk_000C = 0;
            arg0->unk_0002 = 0xA;
            func_82F052F0(arg0, temp_a1, arg0->unk_0004 + (arg0->unk_0018 * 0x58) + 0x2C,
                          arg0->unk_0006 + (arg0->unk_001A * 0x3C) + 0x3A);
            func_80048B90(2);
        } else {
            goto block_25;
        }
    } else {
    block_25:
        if (BTN_IS_PRESSED(controller, BTN_B)) {
            arg0->unk_0000 = 5;
            arg0->unk_000C = 0xA;
            func_80048B90(3);
        } else if (BTN_IS_PRESSED(controller, BTN_R) && (temp_a2->unk_008 != NULL)) {
            arg0->unk_0000 = 3;
            arg0->unk_000C = 0xA;
            arg0->unk_0012 = temp_a2->unk_008 - &arg0->unk_0CA8[0];
            arg0->unk_0014 = 1;

            for (i = 0; i < arg0->unk_0CA8[arg0->unk_0012].unk_000; i++) {
                temp_a3 = &arg0->unk_0CA8[arg0->unk_0012].unk_00C[i];

                temp_t1 = temp_a3->unk_00;
                if ((temp_t1 <= 0) || (temp_t1 >= 0x98)) {
                    var_v0 = 1;
                } else {
                    var_v0 = 0;
                }

                if (var_v0 != 0) {
                    func_8001B0DC(func_82F014E4(D_82F20A00, arg0->unk_0016 ^ 1, i), 0x98, NULL);
                } else {
                    func_8001B0DC(func_82F014E4(D_82F20A00, arg0->unk_0016 ^ 1, i), 0, temp_a3);
                }
            }
        } else if (BTN_IS_PRESSED(controller, BTN_L) && (temp_a2->unk_004 != NULL)) {
            arg0->unk_0000 = 3;
            arg0->unk_000C = 0xA;
            arg0->unk_0012 = temp_a2->unk_004 - &arg0->unk_0CA8[0];
            arg0->unk_0014 = -1;

            for (i = 0; i < arg0->unk_0CA8[arg0->unk_0012].unk_000; i++) {
                temp_a3_2 = &arg0->unk_0CA8[arg0->unk_0012].unk_00C[i];

                if ((temp_a3_2->unk_00 <= 0) || (temp_a3_2->unk_00 >= 0x98)) {
                    var_v0 = 1;
                } else {
                    var_v0 = 0;
                }

                if (var_v0 != 0) {
                    func_8001B0DC(func_82F014E4(D_82F20A00, arg0->unk_0016 ^ 1, i), 0x98, NULL);
                } else {
                    func_8001B0DC(func_82F014E4(D_82F20A00, arg0->unk_0016 ^ 1, i), 0, temp_a3_2);
                }
            }
        }
    }

    if (arg0->unk_0000 == 3) {
        func_80048B90(0x27);
    }
}

void func_82F01FE4(unk_D_82F144D0* arg0) {
    arg0->unk_000C--;
    if (arg0->unk_0014 >= 0) {
        arg0->unk_0004 = ((arg0->unk_000C * 0x1C3) / 10) - 0x15F;
    } else {
        arg0->unk_0004 = 0x227 - ((arg0->unk_000C * 0x1C3) / 10);
    }

    if (arg0->unk_000C <= 0) {
        arg0->unk_0000 = 2;
        arg0->unk_0010 = arg0->unk_0012;
        arg0->unk_000C = 0;
        arg0->unk_0014 = 0;
        arg0->unk_0016 ^= 1;
        arg0->unk_0004 = 0x64;
        func_82F13B4C(2);
    }
}

void func_82F020B4(unk_D_82F144D0* arg0) {
    s32 temp_v0 = func_82F06E38();

    if (temp_v0 != 0) {
        if (temp_v0 == 3) {
            if (arg0->unk_0002 != -1) {
                arg0->unk_0002 = -1;
            }
            func_82F13B4C(-1);
        }
    } else if (arg0->unk_0020 != 0) {
        arg0->unk_0000 = 5;
        arg0->unk_000C = 0xA;
        _bcopy(func_82F014E4(D_82F20A00, arg0->unk_0016, (arg0->unk_001A * 5) + arg0->unk_0018), arg0->unk_0028, 0xC80);
    } else {
        arg0->unk_0000 = 2;
        arg0->unk_000C = 0;
    }
}

void func_82F02180(unk_D_82F144D0* arg0) {
    arg0->unk_000C--;
    arg0->unk_0004 = 0x140 - ((arg0->unk_000C * 0xDC) / 10);
    arg0->unk_0006 = 0xA0 - ((arg0->unk_000C * 0x30) / 10);
    arg0->unk_0008 = (arg0->unk_000C * 0x1B8) / 10;
    arg0->unk_000A = (arg0->unk_000C * 0x10C) / 10;
    if (arg0->unk_000C <= 0) {
        arg0->unk_0000 = 0;
        main_pool_pop_state('PICK');
    }
}

void func_82F022DC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001CADC(arg0 - 7, arg1 - 7, 8, 8, D_302F588, 8, 0);
    func_8001CADC((arg0 + arg2) - 1, arg1 - 7, 8, 8, D_302F5C8, 8, 0);
    func_8001C330(arg0 + 1, arg1 - 7, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    func_8001CADC(arg0 - 7, (arg1 + arg3) - 1, 8, 8, D_302F608, 8, 0);
    func_8001C330(arg0 - 7, arg1 + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);
    func_8001CADC((arg0 + arg2) - 1, (arg1 + arg3) - 1, 8, 8, D_302F648, 8, 0);
    func_8001C330(arg0 + 1, (arg1 + arg3) - 1, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 1, arg1 + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82F02544(s16 arg0, s16 arg1, s16 arg2) {
    static Color_RGB8 D_82F13B90 = { 0x82, 0x1E, 0x1E };
    static Color_RGB8 D_82F13B94 = { 0x96, 0x64, 0x1E };

    Color_RGB8* var_s0;
    char sp64[64];
    s16 tmp = 0x1A8;
    s16 tmp2 = 0x14;
    char* var_v0;

    if (arg0 == 0) {
        var_s0 = &D_82F13B90;
    } else {
        var_s0 = &D_82F13B94;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, var_s0->r, var_s0->g, var_s0->b, 0xFF);

    func_8001CADC(arg1, arg2, 8, 8, D_30387B0, 8, 0);
    func_8001CADC(arg1 + tmp + 8, arg2, 8, 8, D_30387F0, 8, 0);
    func_8001C330(arg1 + 8, arg2, tmp, 8, 0, 0, 0, 0x400, 0);
    func_8001CADC(arg1, arg2 + tmp2, 8, 8, D_3038830, 8, 0);
    func_8001C330(arg1, arg2 + 8, 8, 0xC, 0, 0, 0x400, 0, 0);
    func_8001CADC(arg1 + tmp + 8, arg2 + tmp2, 8, 8, D_3038870, 8, 0);
    func_8001C330(arg1 + 8, arg2 + tmp2, tmp, 8, 0, 0, 0, 0x400, 0);
    func_8001C330(arg1 + tmp + 8, arg2 + 8, 8, 0xC, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    func_8001C604(arg1 + 8, arg2 + 8, tmp, 0xC, var_s0->r, var_s0->g, var_s0->b, 0xFF);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(8, 0);

    if (arg0 == 0) {
        var_v0 = func_8002D7C0(NULL, 0, D_82F13B70, 0xA);
    } else {
        func_8002D600(1, arg0);
        var_v0 = func_8002D7C0(sp64, ARRAY_COUNT(sp64), D_82F13B70, 0xB);
    }

    func_8001F1E8((arg1 - (func_8001F5B0(0, 0, var_v0) / 2)) + 0xDC, arg2 + 4, var_v0);
    func_8001F444();
}

void func_82F028AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, Color_RGB8* arg4, s16 arg5) {
    if (arg5 != 0) {
        func_8001C604(arg0, arg1, arg2, arg3, arg4->r, arg4->g, arg4->b, 0xFF);
    } else {
        s32 color = RGBA5551(arg4->r, arg4->g, arg4->b, 1);

        gDPPipeSync(gDisplayListHead++);
        gDPSetFillColor(gDisplayListHead++, (color << 0x10) | color);
        gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);
    }
}

void func_82F029FC(s16 arg0, s16 arg1, s16 arg2) {
    static Color_RGB8 D_82F13B98 = { 0x3C, 0x3C, 0x82 };
    static Color_RGB8 D_82F13B9C = { 0x28, 0x28, 0x64 };
    static Color_RGB8 D_82F13BA0 = { 0x78, 0x78, 0x96 };

    func_82F028AC(arg0 + 1, arg1 + 1, 0x56, 0x29, &D_82F13B98, arg2);
    func_82F028AC(arg0 + 1, arg1 + 0x2A, 0x56, 0x11, &D_82F13B9C, arg2);
    func_82F028AC(arg0, arg1, 0x58, 1, &D_82F13BA0, arg2);
    func_82F028AC(arg0, arg1 + 0x3B, 0x58, 1, &D_82F13BA0, arg2);
    func_82F028AC(arg0, arg1 + 1, 1, 0x3A, &D_82F13BA0, arg2);
    func_82F028AC(arg0 + 0x57, arg1 + 1, 1, 0x3A, &D_82F13BA0, arg2);
}

void func_82F02B5C(s16 arg0, s16 arg1, s16 arg2) {
    static u8* D_82F13BA4[] = {
        D_302F6E0, D_302F740, D_302F7A0, D_302F800, D_302F860, D_302F8C0, D_302F928, D_302F988, D_302F9E8, D_302FA48,
    };

    s32 i;
    s32 var_s0 = 0x05F5E100;
    s32 var_s4 = 0;

    for (i = 9; i > 0; i--) {
        s32 temp_lo = arg2 / var_s0;

        if ((temp_lo != 0) || (var_s4 != 0) || (i == 0)) {
            func_8001CADC(arg0, arg1, 8, 0xC, D_82F13BA4[temp_lo], 8, 0);
            var_s4 = 1;
            arg0 += 9;
        }

        arg2 %= var_s0;
        var_s0 /= 10;
    }
}

void func_82F02CE8(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    static s16 D_82F13BCC = 0;

    s16 sins = SINS(D_82F13BCC) * 2;
    UNUSED s32 pad[2];

    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 240, 212, 104, 255);

    func_8001CADC(arg0 + sins, arg1 + sins, 0x10, 0x10, D_3038C70, 0x10, 0);
    func_8001CADC(arg0 + sins, ((arg1 + arg3) - sins) - 0x10, 0x10, 0x10, D_3038F70, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - sins) - 0x10, arg1 + sins, 0x10, 0x10, D_3038D70, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - sins) - 0x10, ((arg1 + arg3) - sins) - 0x10, 0x10, 0x10, D_3038E70, 0x10, 0);
    D_82F13BCC += 0x2000;
}

void func_82F02EAC(s16 arg0, s16 arg1, s16 arg2) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);

    func_8001CF10(arg0, arg1, 0x10, 0x1C, D_30388B0, 0x10, 0);
    func_8001CF10((arg0 + arg2) - 0x10, arg1, 0x10, 0x1C, D_3038990, 0x10, 0);
    func_8001C330(arg0 + 0x10, arg1, arg2 - 0x20, 0x1C, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82F02FEC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 sp4C;
    s16 sp48;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x10) {
        var_s3 = 8;
    } else {
        var_s3 = arg2 / 2;
    }

    if (arg3 >= 0x10) {
        var_s2 = 8;
    } else {
        var_s2 = arg3 / 2;
    }

    sp48 = arg2 - (var_s3 * 2);
    sp4C = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038730, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038770, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30386B0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30386F0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3,
                  0x2000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((sp48 > 0) && (sp4C > 0)) {
        func_8001C604(arg0 + var_s3, arg1, sp48, var_s2, arg4, arg5, arg6, arg7);
        func_8001C604(arg0, arg1 + var_s3, arg2, sp4C, arg4, arg5, arg6, arg7);
        func_8001C604(arg0 + var_s3, arg1 + var_s3 + sp4C, sp48, var_s2, arg4, arg5, arg6, arg7);
    } else if (sp48 > 0) {
        func_8001C604(arg0 + var_s3, arg1, sp48, arg3, arg4, arg5, arg6, arg7);
    } else if (sp4C > 0) {
        func_8001C604(arg0, arg1 + var_s2, arg2, sp4C, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82F037EC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if ((arg2 < 0x20) && (arg2 & 1)) {
        arg2 += 1;
    }

    if ((arg3 < 0x20) && (arg3 & 1)) {
        arg3 += 1;
    }

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

    temp_a2 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038B70, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038BF0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038A70, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3038AF0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3,
                  0x4000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((temp_a2 > 0) && (temp_s0_32 > 0)) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, var_s2, arg4, arg5, arg6, arg7);
        func_8001C604(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        func_8001C604(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, temp_a2, var_s2, arg4, arg5, arg6, arg7);
    } else if (temp_a2 > 0) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        func_8001C604(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82F04010(s16 arg0, s16 arg1, u8* arg2, s16 arg3) {
    gDPPipeSync(gDisplayListHead++);

    if (arg3 == 0) {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 150);
    } else {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    }

    func_8001C6AC(arg0, arg1, 0x24, 0x14, arg2, 0x24, 0);
}

void func_82F040D0(unk_D_82F144D0* arg0, s16 arg1, s16 arg2, s32 arg3) {
    static u8* D_82F13BD0[] = {
        D_3039A10, D_3039FB0, D_303A550, D_303AAF0, D_303B090, D_303B630, D_303BBD0,
        D_303C170, D_303C710, D_303CCB0, D_303D250, D_303D7F0, D_303DD90,
    };

    s32 i;

    func_82F02EAC(arg1 - 0x10, arg2 - 4, 0x1F4);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 13; i++) {
        func_82F04010(arg1 + i * 0x24, arg2, D_82F13BD0[i], arg0->unk_0CA8[i].unk_000);
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    if (arg0->unk_0000 != 3) {
        func_8001C6AC((arg1 + (arg0->unk_0010 * 0x24)) - 4, arg2 - 4, 0x2C, 0xE, D_3039070, 0x2C, 0);
        func_8001C6AC((arg1 + (arg0->unk_0010 * 0x24)) - 4, arg2 + 0xA, 0x2C, 0xE, D_3039540, 0x2C, 0);
    }

    gDPPipeSync(gDisplayListHead++);

    if (arg3 != 0) {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    } else {
        gDPSetEnvColor(gDisplayListHead++, 64, 64, 64, 255);
    }

    func_8001C6AC(arg1 - 0x38, arg2 - 8, 0x30, 0x24, D_3027168, 0x30, 0);
    func_8001C6AC(arg1 + 0x1DC, arg2 - 8, 0x30, 0x24, D_3027EE8, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82F043A4(s16 arg0, s16 arg1, s16 arg2) {
    static s16 D_82F13C04[] = { 0xDC, 8 };
    static s16 D_82F13C08[] = { 8, 0x2C };

    UNUSED s32 pad;
    unk_D_82F14450* sp40 = &D_82F14450[D_82F144D0[arg0].unk_000E];
    u8* sp3C;

    func_82F02FEC(arg1, arg2, 0x104, 0x28, 0x1E, 0x1E, 0x82, 0xFF);

    switch (sp40->unk_01) {
        case 1:
            sp3C = D_3029C68;
            break;

        case 2:
            sp3C = D_302A468;
            break;

        case 3:
            sp3C = D_3028C68;
            break;

        case 7:
            sp3C = D_3029468;
            break;
    }

    if (sp3C != NULL) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_8001C6AC(D_82F13C04[arg0] + arg1, arg2 + 4, 0x20, 0x20, sp3C, 0x20, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F1E8(D_82F13C08[arg0] + arg1, arg2 + 0xC, sp40->unk_08);
    func_8001EBE0(4, 0);
    func_8001F1E8(D_82F13C08[arg0] + arg1 + 0x8E, arg2 + 0x14, "%05d", sp40->unk_06);
    func_8001EBE0(4, 0);
    func_8001F1E8(D_82F13C08[arg0] + arg1 + 0x72, arg2 + 0x14, "ID");
    func_8001F444();
}

#ifdef NON_MATCHING
void func_82F04604(unk_D_82F144D0* arg0) {
    static s16 D_82F13C0C[] = { 0x34, 0x148 };

    s32 i;
    s32 spF8;
    s32 spF4;
    s16 var_v0;
    s16 temp_t0;
    s16 spEE;
    s16 var_s2;
    s16 var_a3;
    s16 spE8;
    s32 spE4;
    s32 pad2[3];
    s32 pad[14];
    s16 idx1;
    s16 idx2;
    s16 temp_t1;
    s16 temp_lo;
    s16 temp_s3;

    spE4 = 0;
    if (arg0->unk_0002 > 0) {
        arg0->unk_0002--;
    }

    if (arg0->unk_0000 == 3) {
        spF4 = 2;
        if (arg0->unk_0014 < 0) {
            spEE = -0x1C3;
        } else {
            spEE = 0x1C3;
        }
        func_800060E0(&gDisplayListHead, 0x60, 0x6C, 0x1C3, 0x117);
        spE4 = 1;
    } else {
        spF4 = 1;
        spEE = 0;
    }

    spF8 = 0;
    while (spF8 < spF4) {
        s32 sp68 = spEE * spF8;
        unk_D_82F144D0_0CA8* sp64;

        if (spF8 == 0) {
            var_s2 = arg0->unk_0010;
            spE8 = arg0->unk_0016;
        } else {
            var_s2 = arg0->unk_0012;
            spE8 = arg0->unk_0016 ^ 1;
        }

        sp64 = &arg0->unk_0CA8[var_s2];
        func_82F022DC((s16)sp68 + arg0->unk_0004, arg0->unk_0006, arg0->unk_0008, arg0->unk_000A);

        if ((arg0->unk_0008 == 0x1B8) && (arg0->unk_000A == 0x10C)) {
            unk_func_82F00838_sp30_00C* ptr;

            func_82F02544(var_s2, (s16)sp68 + arg0->unk_0004, arg0->unk_0006);

            if (spF4 == 2) {
                gSPDisplayList(gDisplayListHead++, D_8006F498);
            } else {
                gSPDisplayList(gDisplayListHead++, D_8006F4C0);
            }

            for (i = 0; i < 20; i++) {
                idx1 = i / 5;
                idx2 = i % 5;

                func_82F029FC((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58), arg0->unk_0006 + (idx1 * 0x3C) + 0x1C,
                              spF4 - 1);
            }

            gSPDisplayList(gDisplayListHead++, D_8006F518);
            gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

            for (i = 0; i < sp64->unk_000; i++) {
                ptr = &sp64->unk_00C[i];
                idx1 = i / 5;
                idx2 = i % 5;

                func_8001CADC((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58) + 4, arg0->unk_0006 + (idx1 * 0x3C) + 0x3B, 8,
                              0xA, D_302F690, 8, 0);

                if ((ptr->unk_00 <= 0) || (ptr->unk_00 >= 0x98)) {
                    var_v0 = 1;
                } else {
                    var_v0 = 0;
                }

                if (var_v0 == 0) {
                    func_82F02B5C((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58) + 0xE,
                                  arg0->unk_0006 + (idx1 * 0x3C) + 0x39, ptr->unk_24);
                }
            }

            func_8001F3F4();
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001EBE0(2, 0);

            for (i = 0; i < sp64->unk_000; i++) {
                ptr = &sp64->unk_00C[i];
                idx1 = i / 5;
                idx2 = i % 5;

                if ((ptr->unk_00 <= 0) || (ptr->unk_00 >= 0x98)) {
                    var_v0 = 1;
                } else {
                    var_v0 = 0;
                }

                if (var_v0 == 0) {
                    continue;
                }

                func_8001F1E8((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58) + 0xE, arg0->unk_0006 + (idx1 * 0x3C) + 0x3A,
                              "??");
            }

            func_8001F444();
            func_8001F3F4();
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001EBE0(4, 0);

            for (i = 0; i < sp64->unk_000; i++) {
                ptr = &sp64->unk_00C[i];
                idx1 = i / 5;
                idx2 = i % 5;

                func_8001F1E8((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58) + 5, arg0->unk_0006 + (idx1 * 0x3C) + 0x46,
                              ptr->unk_30);
            }

            func_8001F444();

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            for (i = 0; i < sp64->unk_000; i++) {
                idx1 = i / 5;
                idx2 = i % 5;

                func_8001C6AC((s16)sp68 + arg0->unk_0004 + (idx2 * 0x58) + 0x2C, arg0->unk_0006 + (idx1 * 0x3C) + 0x1F,
                              0x28, 0x28, func_82F014E4(D_82F20A00, spE8, i), 0x28, 0);
            }

            if (arg0->unk_0000 == 2) {
                temp_s3 = (arg0->unk_0004 + (arg0->unk_001C * 0x58));
                temp_lo = (arg0->unk_0006 + (arg0->unk_001E * 0x3C) + 0x1C);

                temp_t0 = arg0->unk_0004 + (arg0->unk_0018 * 0x58);
                temp_t1 = arg0->unk_0006 + (arg0->unk_001A * 0x3C) + 0x1C;

                func_82F02CE8(temp_t0 - (((temp_t0 - temp_s3) * arg0->unk_000C) / 4),
                              temp_t1 - (((temp_t1 - temp_lo) * arg0->unk_000C) / 4), 0x58, 0x3C);
            }

            gSPDisplayList(gDisplayListHead++, D_8006F630);
        }
        spF8++;
        sp68 += spEE;
    }

    if ((arg0->unk_0008 == 0x1B8) && (arg0->unk_000A == 0x10C)) {
        if (spE4 != 0) {
            func_800060E0(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
        }

        if ((arg0->unk_0000 == 2) || (arg0->unk_0000 == 3)) {
            var_a3 = 1;
        } else {
            var_a3 = 0;
        }

        func_82F040D0(arg0, 0x56, 0x50, var_a3);
        func_82F043A4(D_82F20A04, D_82F13C0C[D_82F20A04], 0x20);
    }
}
#else
static s16 D_82F13C0C[] = { 0x34, 0x148 };
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/41/fragment41_289240/func_82F04604.s")
#endif

void func_82F04FD4(void) {
    unk_D_82F144D0* ptr;
    s32 i;

    D_82F20A04 = 0;

    ptr = &D_82F144D0[0];
    for (i = 0; i < 2; i++, ptr++) {
        ptr->unk_0018 = ptr->unk_001A = 0;
        ptr->unk_001C = ptr->unk_001E = 0;
        ptr->unk_0000 = 0;
        ptr->unk_0004 = 0;
        ptr->unk_0006 = 0;
        ptr->unk_0008 = 0;
        ptr->unk_000A = 0;
        ptr->unk_000C = 0;
        ptr->unk_000E = 0;
    }

    func_82F06D50();
}

void func_82F0504C(void) {
    s16 temp_v0;
    s32 i;
    unk_D_82F144D0* var_s0;

    var_s0 = D_82F144D0;

    for (i = 0; i < 2; i++, var_s0++) {
        if (var_s0->unk_0000 == 0) {
            continue;
        }

        switch (var_s0->unk_0000) {
            case 1:
                func_82F01920(var_s0);
                break;

            case 2:
                func_82F01A70(var_s0);
                break;

            case 3:
                func_82F01FE4(var_s0);
                break;

            case 4:
                func_82F06D88();
                func_82F020B4(var_s0);
                break;

            case 5:
                func_82F02180(var_s0);
                break;
        }
    }
}

void func_82F05110(void) {
    s32 i;
    s32 var_s3 = 0;
    unk_D_82F144D0* ptr = &D_82F144D0[0];

    for (i = 0; i < 2; i++, ptr++) {
        if (ptr->unk_0000 != 0) {
            var_s3 = 1;
            if (ptr->unk_0002 != 0) {
                func_82F04604(ptr);
            }
        }
    }

    if (var_s3 != 0) {
        func_82F06E04();
    }
}

u16* func_82F05198(s32 arg0) {
    return D_82F144D0[arg0].unk_0028;
}

void func_82F051B8(void) {
    UNUSED s32 pad[2];
    u16 sp18[0x640];

    _bcopy(D_82F144D0[0].unk_0028, sp18, sizeof(D_82F144D0[0].unk_0028));
    _bcopy(D_82F144D0[1].unk_0028, D_82F144D0[0].unk_0028, sizeof(D_82F144D0[0].unk_0028));
    _bcopy(sp18, D_82F144D0[1].unk_0028, sizeof(D_82F144D0[0].unk_0028));
}

void func_82F05210(s16 arg0, unk_func_80026268_arg0* arg1) {
    func_8001B0DC(D_82F144D0[arg0].unk_0028, 0, arg1);
}

s32 func_82F0525C(s32 arg0, unk_func_82F00838_sp30* arg1) {
    s32 ret = 0;
    unk_D_82F144D0* ptr;

    if (arg1 != NULL) {
        ptr = &D_82F144D0[arg0];
        arg1->unk_00 = ptr->unk_0020;
        arg1->unk_02 = ptr->unk_000E;
        arg1->unk_04 = ptr->unk_0010;
        arg1->unk_06 = (ptr->unk_001A * 5) + ptr->unk_0018;
        arg1->unk_08 = ptr->unk_0CA8[ptr->unk_0010].unk_000;
        arg1->unk_0C = &ptr->unk_0CA8[ptr->unk_0010].unk_00C;
        ret = 1;
    }

    return ret;
}
