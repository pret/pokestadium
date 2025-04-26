#include "fragment61.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/232C0.h"
#include "src/2E110.h"
#include "src/49790.h"
#include "src/6BC0.h"

void func_842082D0(s16 arg0, s16 arg1, s16 arg2) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);

    func_8001CF10(arg0, arg1, 0x10, 0x1C, D_20007C0, 0x10, 0);
    func_8001CF10((arg0 + arg2) - 0x10, arg1, 0x10, 0x1C, D_20008A0, 0x10, 0);
    func_8001C330(arg0 + 0x10, arg1, arg2 - 0x20, 0x1C, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84208410(s16 arg0, s16 arg1, u8* arg2, s16 arg3) {
    if (arg3 == 0) {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 150);
    } else {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    }
    func_8001C6AC(arg0, arg1, 0x24, 0x14, arg2, 0x24, 0);
}

void func_842084BC(unk_D_842168A0* arg0) {
    s16 temp_s0 = arg0->unk_00014 - 0x2C;
    s16 sp3C = arg0->unk_00016 - 0x20;

    func_842082D0(temp_s0, sp3C, 0x208);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_84208410(temp_s0 + 8, sp3C + 4, D_2001A20, arg0->unk_0001C[0].unk_00);
    func_84208410(temp_s0 + 0x2C, sp3C + 4, D_2002560, arg0->unk_0001C[1].unk_00);
    func_84208410(temp_s0 + 0x50, sp3C + 4, D_2002B00, arg0->unk_0001C[2].unk_00);
    func_84208410(temp_s0 + 0x74, sp3C + 4, D_20030A0, arg0->unk_0001C[3].unk_00);
    func_84208410(temp_s0 + 0x98, sp3C + 4, D_2003640, arg0->unk_0001C[4].unk_00);
    func_84208410(temp_s0 + 0xBC, sp3C + 4, D_2003BE0, arg0->unk_0001C[5].unk_00);
    func_84208410(temp_s0 + 0xE0, sp3C + 4, D_2004180, arg0->unk_0001C[6].unk_00);
    func_84208410(temp_s0 + 0x104, sp3C + 4, D_2004720, arg0->unk_0001C[7].unk_00);
    func_84208410(temp_s0 + 0x128, sp3C + 4, D_2004CC0, arg0->unk_0001C[8].unk_00);
    func_84208410(temp_s0 + 0x14C, sp3C + 4, D_2005260, arg0->unk_0001C[9].unk_00);
    func_84208410(temp_s0 + 0x170, sp3C + 4, D_2005800, arg0->unk_0001C[10].unk_00);
    func_84208410(temp_s0 + 0x194, sp3C + 4, D_2005DA0, arg0->unk_0001C[11].unk_00);
    func_84208410(temp_s0 + 0x1B8, sp3C + 4, D_2006340, arg0->unk_0001C[12].unk_00);
    func_84208410(temp_s0 + 0x1DC, sp3C + 4, D_2001FC0, 0x97);

    if (arg0->unk_00001 != 7) {
        func_8001C6AC(temp_s0 + (arg0->unk_00005 * 0x24) + 4, sp3C, 0x2C, 0xE, D_2001080, 0x2C, 0);
        func_8001C6AC(temp_s0 + (arg0->unk_00005 * 0x24) + 4, sp3C + 0xE, 0x2C, 0xE, D_2001550, 0x2C, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

s32 func_84208820(unk_D_842168A0* arg0) {
    s16 i;
    s16 var_v1 = 1;

    for (i = 0; i < 13; i++) {
        if (arg0->unk_0001C[i].unk_00 != 0) {
            var_v1++;
        }
    }

    return var_v1;
}

s32 func_84208870(unk_D_838067F0_0168* arg0) {
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

void func_842088A0(s16 arg0, s16 arg1, unk_D_838067F0_0168* arg2) {
    static Color_RGB8 D_842115D0[] = {
        { 0xB4, 0x3C, 0x3C },
        { 0xBE, 0x96, 0x32 },
        { 0xAA, 0x3C, 0x96 },
    };
    static Color_RGB8 D_842115DC[] = {
        { 0x3C, 0x14, 0x14 },
        { 0x46, 0x32, 0x1E },
        { 0x50, 0x28, 0x3C },
    };

    char sp58[256];
    char* sp54;
    s32 temp_v0;

    temp_v0 = func_84208870(arg2);

    gSPDisplayList(gDisplayListHead++, D_8006F558);

    gDPSetEnvColor(gDisplayListHead++, D_842115D0[temp_v0].r, D_842115D0[temp_v0].g, D_842115D0[temp_v0].b, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, D_842115DC[temp_v0].r, D_842115DC[temp_v0].g, D_842115DC[temp_v0].b, 255);

    func_8001CADC(arg0, arg1, 8, 0x1C, D_2000980, 8, 0);
    func_8001CADC(arg0 + 0x184, arg1, 8, 0x1C, D_2000A60, 8, 0);
    func_8001C330(arg0 + 8, arg1, 0x17C, 0x1C, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(8, 0);

    switch (arg2->unk_2692) {
        case 0:
            sp54 = func_84200130(0x12);
            break;

        case 13:
            sp54 = func_84200130(0x13);
            break;

        default:
            func_8002D600(1, arg2->unk_2692);
            sp54 = func_84200190(sp58, 0x100, 0x14);
            break;
    }

    func_8001F1E8((arg0 - (func_8001F5B0(8, 0, sp54) / 2)) + 0xC6, arg1 + 4, sp54);
    func_8001F444();
}

void func_84208B04(s16 arg0, s16 arg1, unk_D_842168A0* arg2) {
    static s16 D_842115E8 = 0;

    s16 sp5E;
    s16 temp_a3;
    s16 var_v1;

    temp_a3 = arg2->unk_00006 + arg2->unk_0000E;

    if (arg2->unk_00005 < 0xD) {
        var_v1 = ((arg2->unk_0001C[arg2->unk_00005].unk_00 + 2) / 3);
    } else {
        var_v1 = ((arg2->unk_0013C->unk_00 + 2) / 3);
    }

    if (var_v1 < 4) {
        var_v1 = 4;
    }

    if ((arg2->unk_00001 == 8) || (arg2->unk_00001 == 0xA)) {
        if (arg2->unk_00018 > 0) {
            sp5E = ((((temp_a3 * 4) + arg2->unk_00018) * 0x98) - 0x260) / ((var_v1 * 4) - 4);
        } else {
            sp5E = ((((temp_a3 * 4) + arg2->unk_00018) * 0x98) + 0x260) / ((var_v1 * 4) - 4);
        }
    } else {
        sp5E = (temp_a3 * 0x98) / (var_v1 - 1);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    func_8001C560(arg0, arg1, 0x18, 0xCC, 0x3C, 0x3C, 0xA0);

    gSPDisplayList(gDisplayListHead++, D_8006F558);

    gDPSetEnvColor(gDisplayListHead++, 130, 130, 220, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 60, 60, 150, 255);

    func_8001CADC(arg0 + 4, arg1 + 0x20, 0x10, 8, D_200A200, 0x10, 0);
    func_8001CADC(arg0 + 4, arg1 + 0xC0, 0x10, 8, D_200A280, 0x10, 0);
    func_8001C330(arg0 + 4, arg1 + 0x28, 0x10, 0x98, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (D_842115E8 < 4) {
        func_8001C6AC(arg0, arg1 + sp5E + 0x1C, 0x18, 0x18, D_200A300, 0x18, 0);
    } else {
        func_8001C6AC(arg0, arg1 + sp5E + 0x1C, 0x18, 0x18, D_200A780, 0x18, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    if (arg2->unk_00001 == 3) {
        D_842115E8 = (D_842115E8 + 1) % 8;
    }
}

void func_84208F64(unk_D_842168A0* arg0, s16 arg1, s16 arg2, unk_D_838067F0_0168* arg3) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if ((arg3->unk_0000[i].unk_004.unk_00.unk_00 != 0) &&
            (func_84207E3C(arg0->unk_13608, &arg3->unk_0000[i & 0xFFFFFFFF]) != 0)) {
            func_84200420(arg1 + i * 0x84, arg2, 0x84, 0x2C, 0x64, 0x64, 0xC8, 0xFF);
        } else {
            func_84200420(arg1 + i * 0x84, arg2, 0x84, 0x2C, 0x3C, 0x3C, 0xA0, 0xFF);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 3; i++) {
        if (arg3->unk_0000[i].unk_004.unk_00.unk_00 != 0) {
            func_8001C6AC(arg1 + (i * 0x84) + 2, arg2 + 2, 0x28, 0x28, arg3->unk_0000[i].unk_058, 0x28, 0);
        }
    }

    gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0,
                      ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0);
    gDPSetEnvColor(gDisplayListHead++, 140, 220, 240, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 40, 100, 220, 255);

    for (i = 0; i < 3; i++) {
        if (func_8420804C(arg0->unk_13608, &arg3->unk_0000[i & 0xFFFFFFFF]) != 0) {
            func_8001CADC(arg1 + (i * 0x84) + 0x2E, arg2 + 0xB, 0x48, 0x1C, D_200AC00, 0x48, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();

    for (i = 0; i < 3; i++) {
        if ((arg3->unk_0000[i].unk_004.unk_00.unk_00 != 0) &&
            (func_8420804C(arg0->unk_13608, &arg3->unk_0000[i & 0xFFFFFFFF]) == 0)) {
            if (func_84207E3C(arg0->unk_13608, &arg3->unk_0000[i & 0xFFFFFFFF]) != 0) {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                func_8001F324(0x32, 0x32, 0xC8, 0x80);
            }
            func_8001EBE0(4, 0);
            func_8001F1E8(arg1 + (i * 0x84) + 0x2C, arg2 + 5, arg3->unk_0000[i].unk_004.unk_30);
            func_8001EBE0(4, 0);
            func_8001F1E8(arg1 + (i * 0x84) + 0x2C, arg2 + 0x17, "%s%d", func_84200160(0x15),
                          arg3->unk_0000[i].unk_004.unk_24);
        }
    }

    func_8001F444();
}

void func_84209340(unk_D_842168A0* arg0, s32 arg1) {
    unk_D_838067F0_0168* var_s1_2;
    s16 i;
    s16 spB0;
    s16 temp_s3_3;
    s16 temp_s7;

    spB0 = arg0->unk_00014;
    temp_s7 = arg0->unk_00016;

    if ((arg0->unk_00001 != 1) && (arg0->unk_00001 != 2) && ((arg1 != 0) || (arg0->unk_00009 != 0))) {
        func_842084BC(arg0);

        func_842001B8(spB0, temp_s7, 0x1B4, 0xD4);
        func_84208B04(spB0 + 4, temp_s7 + 4, arg0);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        if (func_84208820(arg0) >= 2) {
            func_8001C6AC(spB0 - 0x32, temp_s7 + 0x52, 0x30, 0x18, D_2007E00, 0x30, 0);
            func_8001C6AC(spB0 - 0x32, temp_s7 + 0x6A, 0x30, 0x18, D_2008700, 0x30, 0);
            func_8001C6AC(spB0 + 0x1BA, temp_s7 + 0x52, 0x30, 0x18, D_2009000, 0x30, 0);
            func_8001C6AC(spB0 + 0x1BA, temp_s7 + 0x6A, 0x30, 0x18, D_2009900, 0x30, 0);
        }

        gSPDisplayList(gDisplayListHead++, D_8006F470);

        func_8001C560(spB0 + 0x1C, temp_s7 + 4, 8, 0xCC, 0x32, 0x32, 0x32);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        if (arg0->unk_00001 == 7) {
            s16 sp9E = spB0 - ((arg0->unk_00018 * 0x194) / 8);
            s16 tmp3 = (((arg0->unk_0001A > 0) ? 0x194 : -0x194) + sp9E);
            s32 pad;

            func_800060E0(&gDisplayListHead, spB0 + 0x24, temp_s7 + 4, 0x18C, 0xCC);
            func_842088A0(sp9E + 0x24, temp_s7 + 4, arg0->unk_00140->unk_268C);
            func_842088A0(tmp3 + 0x24, temp_s7 + 4, arg0->unk_00140);

            gSPDisplayList(gDisplayListHead++, D_8006F518);
            gDPLoadTextureBlock(gDisplayListHead++, D_2000C40, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 4, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            func_8001C330(sp9E + 0x1B0, temp_s7 + 4, 8, 0xCC, 0, 0, 0x400, 0, 0);
            func_8001C330(tmp3 + 0x1B0, temp_s7 + 4, 8, 0xCC, 0, 0, 0x400, 0, 0);

            gSPDisplayList(gDisplayListHead++, D_8006F630);

            var_s1_2 = arg0->unk_00140;
            for (i = 0; i < 4; i++) {
                func_84208F64(arg0, tmp3 + 0x24, temp_s7 + (i * 0x2C) + 0x20, var_s1_2);
                var_s1_2 = var_s1_2->unk_2688;
            }

            for (i = 0; i < 4; i++) {
                func_84208F64(arg0, sp9E + 0x24, temp_s7 + (i * 0x2C) + 0x20, var_s1_2);
                var_s1_2 = var_s1_2->unk_2688;
            }

            func_800060E0(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
        } else if (arg0->unk_00001 == 8) {
            temp_s3_3 = temp_s7 - ((arg0->unk_00018 * 0x2C) / 4);
            func_842088A0(spB0 + 0x24, temp_s7 + 4, arg0->unk_00140);
            func_800060E0(&gDisplayListHead, spB0 + 0x24, temp_s7 + 0x20, 0x18C, 0xB0);
            if (arg0->unk_0001A > 0) {
                var_s1_2 = arg0->unk_00140->unk_268C;
                for (i = 0; i < 5; i++) {
                    func_84208F64(arg0, spB0 + 0x24, temp_s3_3 + (i * 0x2C) + 0x20, var_s1_2);
                    var_s1_2 = var_s1_2->unk_2688;
                }
            } else {
                var_s1_2 = arg0->unk_00140;
                for (i = 0; i < 5; i++) {
                    func_84208F64(arg0, spB0 + 0x24, (temp_s3_3 + (i * 0x2C)) - 0xC, var_s1_2);
                    var_s1_2 = var_s1_2->unk_2688;
                }
            }
            func_800060E0(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
        } else {
            func_842088A0(spB0 + 0x24, temp_s7 + 4, arg0->unk_00140);
            var_s1_2 = arg0->unk_00140;

            for (i = 0; i < 4; i++) {
                func_84208F64(arg0, spB0 + 0x24, temp_s7 + (i * 0x2C) + 0x20, var_s1_2);
                var_s1_2 = var_s1_2->unk_2688;
            }
        }

        if (arg0->unk_00001 == 0xA) {
            s16 tmp1 = (arg0->unk_0000C * 0x84) + 0x24;
            s16 tmp2 = (arg0->unk_0000E * 0x2C) + 0x20;

            if (arg0->unk_00018 > 0) {
                tmp2 = ((tmp2 + ((arg0->unk_00018 * 0x2C) / 4)) - 0x2C);
            } else {
                tmp2 = (tmp2 + ((arg0->unk_00018 * 0x2C) / 4) + 0x2C);
            }
            func_84200738(spB0 + tmp1, temp_s7 + tmp2, 0x84, 0x2C);
        } else if (arg0->unk_00001 == 9) {
            s16 tmp1 = (arg0->unk_0000C * 0x84) + 0x24;
            s16 tmp2 = (arg0->unk_0000E * 0x2C) + 0x20;

            if (arg0->unk_00018 > 0) {
                tmp1 = ((tmp1 + ((arg0->unk_00018 * 0x84) / 4)) - 0x84);
            } else {
                tmp1 = (tmp1 + ((arg0->unk_00018 * 0x84) / 4) + 0x84);
            }
            func_84200738(spB0 + tmp1, temp_s7 + tmp2, 0x84, 0x2C);
        } else if ((arg0->unk_00001 == 3) || (arg0->unk_00001 == 8)) {
            s16 tmp1 = (arg0->unk_0000C * 0x84) + 0x24;
            s16 tmp2 = (arg0->unk_0000E * 0x2C) + 0x20;

            func_84200738(spB0 + tmp1, temp_s7 + tmp2, 0x84, 0x2C);
        }

        if (arg0->unk_00009 > 0) {
            arg0->unk_00009--;
        }
    }
}

void func_84209CEC(void) {
}

unk_D_838067F0_0168* func_84209CF4(unk_D_838067F0_0168* arg0, s32 arg1) {
    while (arg1-- > 0) {
        arg0 = arg0->unk_2688;
    }

    return arg0;
}

void func_84209D18(unk_D_842168A0* arg0, unk_func_80026268_arg0* arg1) {
    unk_D_800AC910_040 sp38;
    unk_D_800AC910_040 sp28;

    if ((arg0->unk_00004 < 4) && (func_80024F68(arg0->unk_00004) == 7) && (arg1->unk_00.unk_00 == 0x19)) {
        func_80025040(arg0->unk_00004, &sp28);
        _bcopy(arg1->unk_46, sp38.unk_02, 11);
        sp38.unk_00 = arg1->unk_0E;
        if (func_80022A04(&sp38, &sp28) != 0) {
            arg1->unk_52 |= 0x80;
        }
    }
}

s32 func_84209DB8(unk_D_842168A0* arg0, unk_D_838067F0_0168* arg1, s32 arg2, unk_D_842168A0_0013C* arg3) {
    s16 i;
    s16 j;
    s16 var_s3;
    unk_D_838067F0_003C* temp_s5;
    unk_func_80022C28_ret* var_v0;

    arg1->unk_2690 = arg0->unk_00004;
    arg1->unk_2692 = arg0->unk_00005;
    var_s3 = 0;

    for (i = 0; i < 3; i++) {
        arg1->unk_0000[i].unk_004.unk_00.unk_00 = 0;
        arg1->unk_0000[i].raw = 0;
    }

    if (arg0->unk_00005 < 0xD) {
        temp_s5 = &arg0->unk_0001C[arg0->unk_00005];

        if (arg0->unk_00004 < 4) {
            if (arg0->unk_00005 == 0) {
                var_v0 = func_80022C28(0x20, arg0->unk_00004, 0, 0);
            } else {
                var_v0 = func_80022C28(0x21, arg0->unk_00004, arg0->unk_00005 - 1, 0);
            }

            if (var_v0 != NULL) {
                i = arg2 * 3;
                for (j = 0; j < 3; j++) {
                    if (i < temp_s5->unk_00) {
                        if (func_80022DF4(var_v0, temp_s5->unk_02[i++]) != 0) {
                            var_s3 += func_80022E18(&arg1->unk_0000[j].unk_004.unk_00.unk_00, 1, var_v0);
                        }
                    }
                }
                func_80022D8C(var_v0);
            }
        }
    } else if (arg3 != NULL) {
        i = arg2 * 3;
        for (j = 0; j < 3; j++) {
            if (i < arg3->unk_00) {
                _bcopy(&arg3->unk_04[i++], &arg1->unk_0000[var_s3].unk_004, sizeof(arg3->unk_04[0]));
                func_800228B0(&arg1->unk_0000[var_s3++].unk_004);
            }
        }
    }

    for (i = 0; i < var_s3; i++) {
        func_8001B0DC(arg1->unk_0000[i].unk_058, 0, &arg1->unk_0000[i].unk_004);

        arg1->unk_0000[i].unk_000 = arg0->unk_00004;
        arg1->unk_0000[i].unk_001 = arg0->unk_00005;
        arg1->unk_0000[i].unk_002 = (arg2 * 3) + i;
        arg1->unk_0000[i].unk_003 = arg1->unk_0000[i].unk_004.unk_00.unk_00;

        arg1->unk_0000[i].unk_004.unk_53 = (arg2 * 3) + i;
        arg1->unk_0000[i].unk_004.unk_52 = (arg0->unk_00004 * 0x10) | arg0->unk_00005;

        func_84209D18(arg0, &arg1->unk_0000[i].unk_004);
    }

    return var_s3;
}

void func_8420A0A4(unk_D_842168A0* arg0) {
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00016 = arg0->unk_00012 + 0x1E0;
}

void func_8420A0BC(unk_D_842168A0* arg0) {
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00016 = arg0->unk_00012;
    if (arg0->unk_00002 != 0) {
        arg0->unk_00001 = arg0->unk_00002;
        arg0->unk_00002 = 0;
    }
}

void func_8420A0E4(unk_D_842168A0* arg0) {
    unk_D_838067F0_0168* sp2C;
    s32 temp_v0;

    sp2C = func_84209CF4(arg0->unk_00140, arg0->unk_0000E);
    temp_v0 = func_8420C788(arg0->unk_1360C);

    if (temp_v0 == 1) {
        if (func_84207BD4(arg0->unk_13608, &sp2C->unk_0000[arg0->unk_0000C]) != 0) {
            arg0->unk_00009 = 2;
            arg0->unk_00001 = 4;
        }
    } else if ((s16)temp_v0 == 2) {
        arg0->unk_00001 = 3;
    }

    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00016 = arg0->unk_00012;
}

void func_8420A1B0(unk_D_842168A0* arg0) {
    arg0->unk_0000A++;
    if (arg0->unk_0000A <= 0) {
        arg0->unk_00016 = arg0->unk_00012 + 0x1E0;
    } else if (arg0->unk_0000A == 0xA) {
        arg0->unk_00001 = 4;
        arg0->unk_0000A = 0;
        arg0->unk_00016 = arg0->unk_00012;
    } else {
        arg0->unk_00016 = (arg0->unk_00012 - (arg0->unk_0000A * 0x30)) + 0x1E0;
    }
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00009 = 2;
}

void func_8420A228(unk_D_842168A0* arg0) {
    arg0->unk_0000A++;
    if (arg0->unk_0000A == 0xA) {
        arg0->unk_00001 = 2;
        arg0->unk_0000A = 0;
        arg0->unk_00016 = arg0->unk_00012 + 0x1E0;
    } else {
        arg0->unk_00016 = arg0->unk_00012 + (arg0->unk_0000A * 0x30);
    }
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00009 = 2;
}

void func_8420A288(unk_D_842168A0* arg0) {
    unk_D_838067F0_0168* sp3C = func_84209CF4(arg0->unk_00140, arg0->unk_0000E);
    s32 var_t1;
    s16 tmp1;
    s16 tmp2;

    if (func_84207E3C(arg0->unk_13608, &sp3C->unk_0000[arg0->unk_0000C]) != 0) {
        if (arg0->unk_00000 == 0) {
            var_t1 = 1;
        } else {
            var_t1 = 3;
        }

        tmp1 = arg0->unk_00010 + (arg0->unk_0000C * 0x84) + 0x20;
        tmp2 = arg0->unk_00012 + (arg0->unk_0000E * 0x2C) + 0x1C;
        tmp1 = func_8420C60C(arg0->unk_1360C, arg0->unk_00003, 0x30, 0xEC, tmp1, tmp2, &sp3C->unk_0000[arg0->unk_0000C],
                             var_t1);

        if (tmp1 != 0) {
            func_80048B90(2);
            arg0->unk_00001 = 0xB;
        }
    } else {
        func_80048B90(8);
    }
}

void func_8420A3E4(unk_D_842168A0* arg0) {
    if (arg0->unk_00007 == 0) {
        if (arg0->unk_0000E != 0) {
            arg0->unk_0000E--;
            arg0->unk_00018 = -1;
            arg0->unk_0001A = -4;
            arg0->unk_00001 = 0xA;
            func_80048B90(1);
        } else if ((arg0->unk_00006 > 0) &&
                   (func_84209DB8(arg0, arg0->unk_00140->unk_268C, arg0->unk_00006 - 1, arg0->unk_0013C) != 0)) {
            arg0->unk_00006--;
            arg0->unk_00140 = arg0->unk_00140->unk_268C;
            arg0->unk_00018 = -1;
            arg0->unk_0001A = -4;
            arg0->unk_00001 = 8;
            func_80048B90(1);
        }

        arg0->unk_00007 = arg0->unk_00008;
        arg0->unk_00008 = 2;
    }
}

void func_8420A4B8(unk_D_842168A0* arg0) {
    if (arg0->unk_00007 == 0) {
        if (arg0->unk_0000E != 3) {
            arg0->unk_0000E++;
            arg0->unk_00018 = 1;
            arg0->unk_0001A = 4;
            arg0->unk_00001 = 0xA;
            func_80048B90(1);
        } else if (func_84209DB8(arg0, func_84209CF4(arg0->unk_00140, 4), arg0->unk_00006 + 4, arg0->unk_0013C) != 0) {
            arg0->unk_00006++;
            arg0->unk_00140 = arg0->unk_00140->unk_2688;
            arg0->unk_00018 = 1;
            arg0->unk_0001A = 4;
            arg0->unk_00001 = 8;
            func_80048B90(1);
        }
        arg0->unk_00007 = arg0->unk_00008;
        arg0->unk_00008 = 2;
    }
}

void func_8420A594(unk_D_842168A0* arg0) {
    if (arg0->unk_00007 == 0) {
        if (arg0->unk_0000C > 0) {
            arg0->unk_0000C--;
            arg0->unk_00018 = -1;
            arg0->unk_0001A = -4;
            arg0->unk_00001 = 9;
            func_80048B90(1);
        }
        arg0->unk_00007 = arg0->unk_00008;
        arg0->unk_00008 = 2;
    }
}

void func_8420A604(unk_D_842168A0* arg0) {
    if (arg0->unk_00007 == 0) {
        if (arg0->unk_0000C < 2) {
            arg0->unk_0000C++;
            arg0->unk_00018 = 1;
            arg0->unk_0001A = 4;
            arg0->unk_00001 = 9;
            func_80048B90(1);
        }
        arg0->unk_00007 = arg0->unk_00008;
        arg0->unk_00008 = 2;
    }
}

void func_8420A678(unk_D_842168A0* arg0) {
    s16 var_s0;
    s16 i;
    unk_D_838067F0_0168* var_s1;

    var_s0 = (arg0->unk_00005 + 1) % 14;
    while ((var_s0 < 0xD) && (arg0->unk_0001C[var_s0].unk_00 == 0)) {
        var_s0 = (var_s0 + 1) % 14;
    }

    if (var_s0 != arg0->unk_00005) {
        func_80048B90(0x27);
        arg0->unk_00005 = var_s0;
        arg0->unk_00140 = func_84209CF4(arg0->unk_00140, 4);
        arg0->unk_00006 = 0;

        var_s1 = arg0->unk_00140;
        for (i = 0; i < 4; i++) {
            func_84209DB8(arg0, var_s1, arg0->unk_00006 + i, arg0->unk_0013C);
            var_s1 = var_s1->unk_2688;
        }

        arg0->unk_00018 = 0;
        arg0->unk_0001A = 8;
        arg0->unk_00001 = 7;
    }
}

void func_8420A7D8(unk_D_842168A0* arg0) {
    s16 var_s0;
    s16 i;
    unk_D_838067F0_0168* var_s1;

    var_s0 = (arg0->unk_00005 + 0xD) % 14;
    while ((var_s0 < 0xD) && (arg0->unk_0001C[var_s0].unk_00 == 0)) {
        var_s0 = (var_s0 + 0xD) % 14;
    }

    if (var_s0 != arg0->unk_00005) {
        func_80048B90(0x27);
        arg0->unk_00005 = var_s0;
        arg0->unk_00140 = func_84209CF4(arg0->unk_00140, 4);
        arg0->unk_00006 = 0;

        var_s1 = arg0->unk_00140;
        for (i = 0; i < 4; i++) {
            func_84209DB8(arg0, var_s1, arg0->unk_00006 + i, arg0->unk_0013C);
            var_s1 = var_s1->unk_2688;
        }

        arg0->unk_00018 = 0;
        arg0->unk_0001A = -8;
        arg0->unk_00001 = 7;
    }
}

void func_8420A938(unk_D_842168A0* arg0) {
    s32 temp_v0 = func_84207AAC(arg0->unk_13608);

    if (temp_v0 != -1) {
        if (temp_v0 == 1) {
            arg0->unk_00009 = 2;
            arg0->unk_00001 = 4;
            func_80048B90(3);
        }
    } else {
        arg0->unk_00009 = 2;
        arg0->unk_0000A = 0;
        arg0->unk_00001 = 6;
        func_80048B90(3);
    }
}

void func_8420A9B8(unk_D_842168A0* arg0) {
    if (func_84207D5C(arg0->unk_13608) != 0) {
        arg0->unk_00009 = 2;
        arg0->unk_00001 = 4;
        func_80048B90(2);
    }
}

void func_8420AA08(unk_D_842168A0* arg0) {
    Controller* cont = &gControllers[arg0->unk_00003];

    if (BTN_IS_PRESSED(cont, BTN_A)) {
        func_8420A288(arg0);
    } else if (BTN_IS_PRESSED(cont, BTN_B)) {
        func_8420A938(arg0);
    } else if (BTN_IS_PRESSED(cont, BTN_START)) {
        func_8420A9B8(arg0);
    } else if (BTN_IS_PRESSED(cont, BTN_R)) {
        func_8420A678(arg0);
    } else if (BTN_IS_PRESSED(cont, BTN_L)) {
        func_8420A7D8(arg0);
    } else if (BTN_IS_DOWN(cont, BTN_DLEFT)) {
        func_8420A594(arg0);
    } else if (BTN_IS_DOWN(cont, BTN_DRIGHT)) {
        func_8420A604(arg0);
    } else if (BTN_IS_DOWN(cont, BTN_DUP)) {
        func_8420A3E4(arg0);
    } else if (BTN_IS_DOWN(cont, BTN_DDOWN)) {
        func_8420A4B8(arg0);
    } else {
        arg0->unk_00008 = 8;
        arg0->unk_00007 = 0;
    }

    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00016 = arg0->unk_00012;
    arg0->unk_00009 = 2;
}

void func_8420AB50(unk_D_842168A0* arg0) {
    if (arg0->unk_0001A > 0) {
        arg0->unk_00018++;
        if (arg0->unk_00018 >= arg0->unk_0001A) {
            arg0->unk_00001 = 3;
        }
    } else {
        arg0->unk_00018--;
        if (arg0->unk_0001A >= arg0->unk_00018) {
            arg0->unk_00001 = 3;
        }
    }
    arg0->unk_00014 = arg0->unk_00010;
    arg0->unk_00016 = arg0->unk_00012;
    arg0->unk_00009 = 2;
}

s32 func_8420ABC4(unk_func_80026268_arg0* arg0) {
    s32 i;
    s32 var_v1 = 1;

    for (i = 0; i < 4; i++) {
        if (arg0->unk_09[i] == 0) {
            break;
        }

        if (arg0->unk_09[i] >= 0xA6) {
            var_v1 = 0;
        }
    }

    return var_v1;
}

s32 func_8420AC00(unk_func_80026268_arg0* arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 sp1C = 0;

    if ((arg0->unk_00.unk_00 > 0) && (arg0->unk_00.unk_00 < 0x98)) {
        if ((func_8420ABC4(arg0) != 0) && (D_8006FEE8[arg0->unk_00.unk_00][8] & arg3)) {
            if ((arg0->unk_24 >= arg1) && (arg2 >= arg0->unk_24)) {
                sp1C = 1;
            }
        }
    }
    return sp1C;
}

s32 func_8420ACA8(unk_D_842168A0* arg0, s16 arg1, s16 arg2) {
    unk_D_838067F0_003C* ptr = &arg0->unk_0001C[arg1];
    unk_func_80026268_arg0 sp50;
    s32 var_s0;
    s16 var_s2;
    unk_D_838067F0_003C* temp_v0;
    unk_func_80022C28_ret* var_v0;

    ptr->unk_00 = 0;
    var_s2 = 0;

    if (arg0->unk_00004 < 4) {
        if (arg1 == 0) {
            var_v0 = func_80022C28(0x20, arg0->unk_00004, 0, 0);
        } else {
            var_v0 = func_80022C28(0x21, arg0->unk_00004, arg1 - 1, 0);
        }

        if (var_v0 != NULL) {
            while (func_80022E18(&sp50, 1, var_v0) == 1) {
                switch (arg2) {
                    case 0:
                        var_s0 = func_8420AC00(&sp50, 1, 0x64, 0x20);
                        break;

                    case 1:
                        var_s0 = func_8420AC00(&sp50, 0x32, 0x37, 1);
                        break;

                    case 2:
                        var_s0 = func_8420AC00(&sp50, 0x32, 0x37, 1);
                        break;

                    case 3:
                        var_s0 = func_8420AC00(&sp50, 0x32, 0x37, 1);
                        break;
                    case 4:
                        var_s0 = func_8420AC00(&sp50, 0x19, 0x1E, 8);
                        break;

                    case 5:
                        var_s0 = func_8420AC00(&sp50, 0xF, 0x14, 0x10);
                        break;

                    case 6:
                        var_s0 = func_8420AC00(&sp50, 1, 0x64, 0x20);
                        break;

                    case 7:
                        var_s0 = func_8420AC00(&sp50, 1, 0x64, 0x20);
                        break;

                    case 8:
                        var_s0 = func_8420AC00(&sp50, 1, 0x64, 0x20);
                        break;
                }

                if (var_s0 != 0) {
                    temp_v0 = ptr;
                    temp_v0->unk_02[temp_v0->unk_00] = var_s2;
                    temp_v0->unk_00 += 1;
                }

                var_s2++;
            }
            func_80022D8C(var_v0);
        }
    }
    return ptr->unk_00;
}

s32 func_8420AF1C(unk_D_842168A0* arg0, unk_D_84211B50* arg1, unk_D_8423D3A8* arg2, s16 arg3, s16 arg4, s16 arg5,
                  s16 arg6, s16 arg7, unk_D_842168A0_0013C* arg8) {
    s16 i;

    arg0->unk_00000 = arg3;
    arg0->unk_00001 = 1;
    arg0->unk_00002 = 0;
    arg0->unk_00003 = arg6;
    arg0->unk_00004 = arg7;
    arg0->unk_00005 = 0xD;
    arg0->unk_00006 = 0;
    arg0->unk_00007 = 0;
    arg0->unk_00008 = 8;
    arg0->unk_0000A = 0;
    arg0->unk_0000C = 0;
    arg0->unk_0000E = 0;
    arg0->unk_00016 = arg5 + 0x1E0;
    arg0->unk_00010 = arg4;
    arg0->unk_00014 = arg4;
    arg0->unk_00012 = arg5;
    arg0->unk_0013C = arg8;
    arg0->unk_13608 = arg1;
    arg0->unk_1360C = arg2;
    arg0->unk_00140 = &arg0->unk_00148[0];

    for (i = 0; i < 8; i++) {
        arg0->unk_00148[i].unk_2688 = &arg0->unk_00148[(i + 1) & 7];
        arg0->unk_00148[i].unk_268C = &arg0->unk_00148[(i - 1) & 7];
    }

    for (i = 12; i >= 0; i--) {
        if (func_8420ACA8(arg0, i, D_800AE540.unk_0001) > 0) {
            arg0->unk_00005 = i;
        }
    }

    for (i = 0; i < 4; i++) {
        func_84209DB8(arg0, &arg0->unk_00148[i], i, arg0->unk_0013C);
    }

    return 2;
}

s32 func_8420B0C8(unk_D_842168A0* arg0) {
    s32 sp1C = 0;

    if (arg0->unk_00007 > 0) {
        arg0->unk_00007--;
    }

    switch (arg0->unk_00001) {
        case 1:
            func_8420A0A4(arg0);
            break;

        case 2:
            func_8420A0A4(arg0);
            break;

        case 4:
            func_8420A0BC(arg0);
            break;

        case 3:
            func_8420AA08(arg0);
            break;

        case 7:
            func_8420AB50(arg0);
            break;

        case 8:
            func_8420AB50(arg0);
            break;

        case 9:
            func_8420AB50(arg0);
            break;

        case 10:
            func_8420AB50(arg0);
            break;

        case 5:
            func_8420A1B0(arg0);
            sp1C = 1;
            break;

        case 6:
            func_8420A228(arg0);
            sp1C = 1;
            break;

        case 11:
            func_8420A0E4(arg0);
            break;
    }
    return sp1C;
}

s32 func_8420B1D0(unk_D_842168A0* arg0, s16 arg1) {
    if (arg0->unk_00001 != 1) {
        return 0;
    }
    arg0->unk_00001 = 5;
    arg0->unk_0000A = -arg1;
    return 1;
}

s32 func_8420B20C(unk_D_842168A0* arg0) {
    if (arg0->unk_00001 != 2) {
        return 0;
    }
    arg0->unk_00001 = 5;
    arg0->unk_0000A = 0;
    return 1;
}

s32 func_8420B238(unk_D_842168A0* arg0) {
    if (arg0->unk_00001 != 4) {
        return 0;
    }
    arg0->unk_00002 = 6;
    arg0->unk_0000A = 0;
    return 1;
}

void func_8420B264(unk_D_842168A0* arg0) {
    arg0->unk_00009 = 2;
}

void func_8420B270(unk_D_842168A0* arg0) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (func_84207E3C(arg0->unk_13608,
                          &func_84209CF4(arg0->unk_00140, arg0->unk_0000E)->unk_0000[arg0->unk_0000C]) != 0) {
            break;
        }

        arg0->unk_0000C++;
        if (arg0->unk_0000C == 3) {
            arg0->unk_0000C = 0;
            arg0->unk_0000E = (arg0->unk_0000E + 1) & 3;
        }
    }
}

s32 func_8420B334(unk_D_842168A0* arg0) {
    if (arg0->unk_00001 == 4) {
        func_8420B270(arg0);
        arg0->unk_00002 = 3;
        return 1;
    }
    return 0;
}

s32 func_8420B37C(unk_D_842168A0* arg0) {
    return arg0->unk_00001 == 2;
}
