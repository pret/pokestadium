#include "fragment11.h"
#include "src/12D80.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/geo_layout.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/4BDC0.h"
#include "src/4CBC0.h"
#include "src/50860.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/fragments/2/fragment2.h"
#include "src/fragments/5/fragment5.h"
#include "src/stage_loader.h"
#include "src/controller.h"

static unk_D_86002F58_004_000 D_865092E0;
static unk_D_86002F58_004_000 D_86509448;
static unk_D_86002F58_004_000 D_865095B0;
static unk_D_86002F58_004_000 D_86509718;
static unk_D_86002F58_004_000 D_86509880;
static unk_D_86002F58_004_000 D_865099E8;
static unk_D_86002F58_004_000 D_86509B50;
static unk_D_86002F58_004_000 D_86509CB8;
static unk_D_86002F58_004_000 D_86509E20;
static unk_D_86002F58_004_000 D_86509F88;
static unk_D_86002F58_004_000 D_8650A0F0;
static unk_D_86002F58_004_000 D_8650A258;
static unk_D_86002F58_004_000 D_8650A3C0;

static unk_D_864027C0 D_86502C20[] = {
    { -60.0f, 7.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0, 0xA00, 0 },
    { -20.0f, 7.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0, 0x300, 0 },
    { 20.0f, 7.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0, -0x300, 0 },
    { 60.0f, 7.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0, -0xA00, 0 },
};

static unk_D_86002F58_004_000* D_86502CA0[] = {
    &D_865092E0, &D_86509448, &D_865095B0, &D_86509718, &D_86509880, &D_865099E8, &D_86509B50,
    &D_86509CB8, &D_86509E20, &D_86509F88, &D_8650A0F0, &D_8650A258, &D_8650A3C0,
};

static u8 D_86502CD4 = 0;
static u16 D_86502CD8 = 0;

static unk_func_87801684 D_86502CDC[] = {
    { 0x0303F980, 2 }, { 0x0303FD80, 2 }, { 0x03040180, 2 },    { 0x0303FD80, 2 }, { 0x0303F980, 2 },
    { 0x0303FD80, 2 }, { 0x03040180, 2 }, { 0x0303FD80, 2 },    { 0x0303F980, 2 }, { 0x0303FD80, 2 },
    { 0x03040180, 2 }, { 0x0303FD80, 2 }, { 0x0303F980, 0x18 }, { NULL, 0 },
};

static unk_func_87801684 D_86502D4C[] = {
    { 0x0303ED80, 0x18 }, { 0x0303F180, 2 }, { 0x0303F580, 2 }, { 0x0303F180, 2 }, { 0x0303ED80, 2 },
    { 0x0303F180, 2 },    { 0x0303F580, 2 }, { 0x0303F180, 2 }, { 0x0303ED80, 2 }, { 0x0303F180, 2 },
    { 0x0303F580, 2 },    { 0x0303F180, 2 }, { 0x0303ED80, 2 }, { NULL, 0 },
};

static unk_func_87801684 D_86502DBC[] = {
    { 0x03040580, 0x12 }, { 0x03040980, 2 }, { 0x03040D80, 8 }, { 0x03040980, 2 }, { NULL, 0 },
};

static u32 D_86502DE4[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0, 0x0000000F, 0x00000000, 0x00000000, 0x05000000,
    0x0D000000, 0x05000000, 0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003, 0x05000000, 0x1F00FFFF,
    0x00000000, 0x00000000, 0x00000000, 0x00640064, 0x00640000, 0x06000000, 0x05000000, 0x0A000000, 0x800AC840,
    0x06000000, 0x06000000, 0x06000000, 0x03000000, 0x87806398, 0x06000000, 0x01000000,
};

static u8 D_86502E6C = 0;
static u8 D_86502E70 = 0;

unk_D_8650A528 D_8650A528[4];
unk_D_8650A528* D_8650AB28;
static unk_D_86002F58_004_000* D_8650AB2C;
unk_D_8650AB30 D_8650AB30[4];
unk_D_8650AB30* D_8650AD70;

void func_86500020(unk_D_8650A528* arg0, u8 arg1) {
    if (arg0->unk_000 == 4) {
        arg0->unk_00D = 0;
        return;
    }

    if (arg1 == 0) {
        arg0->unk_00D = func_87B00050(3);
    } else if ((D_8650AD84 + 1) == D_8650AD85) {
        arg0->unk_00D = func_86501FC0(arg0->unk_000, 1);
    } else {
        arg0->unk_00D = func_86501FC0(arg0->unk_000, 0);
    }
}

void func_865000C0(void) {
    s8 i;

    for (i = 0; i < 4; i++) {
        if (D_8780FA30[i] == 0) {
            D_8650A528[i].unk_000 = 4;
        } else {
            D_8650A528[i].unk_000 = D_8780FA38;
        }
    }
}

void func_86500140(void) {
    u8 i;

    for (i = 0; i < 4; i++) {
        switch (D_8780FA68[i]) {
            case 1:
                D_8650A528[i].unk_004 = 1;
                break;

            case 2:
                D_8650A528[i].unk_004 = 0;
                break;

            default:
                if (func_87B00050(2) != 0) {
                    D_8650A528[i].unk_004 = 0;
                } else {
                    D_8650A528[i].unk_004 = 1;
                }
                break;
        }
    }
}

void func_86500238(void) {
    u8 i;
    s8 temp_ft2;
    u8 var_s1;
    s32 sp58;
    UNUSED s32 pad;
    u32 var_s0_2;

    if (D_8780FC94 != 1) {
        for (i = 0; i < 4; i++) {
            D_8650AB28 = &D_8650A528[i];
            sp58 = D_8650AB28->unk_008;

            var_s1 = 0;
            if (D_87B000C8 != 0) {
                if (D_86502CD8 < 0x57) {
                    var_s1 = 2;
                } else if (D_86502CD8 == 0x57) {
                    var_s1 = 1;
                    if (D_8650AB28->unk_00C == 1) {
                        D_8650AB28->unk_008 = 3;
                    } else {
                        D_8650AB28->unk_008 = 4;
                    }
                } else if (D_86502CD8 == 0xB4) {
                    var_s1 = 1;
                    if (D_8650AB28->unk_00C == 1) {
                        D_8650AB28->unk_008 = 6;
                    } else {
                        D_8650AB28->unk_008 = 5;
                    }
                } else if (func_80017514(&D_8650AB28->unk_014) != 0) {
                    switch (D_8650AB28->unk_008) {
                        case 6:
                            var_s1 = 1;
                            if (D_8650AB28->unk_004 == 0) {
                                D_86502E6C = 1;
                            } else if (D_8650AB28->unk_004 == 1) {
                                D_86502E70 = 1;
                            }
                            break;

                        case 4:
                            var_s1 = 1;
                            D_8650AB28->unk_008 = 5;
                            break;

                        case 0:
                        case 3:
                            var_s1 = 1;
                            D_8650AB28->unk_008 = 0;
                            break;
                    }
                } else if ((D_8650AB28->unk_008 == 6) &&
                           (((D_86502E6C != 0) && ((D_8650AB28->unk_014.unk_040.unk_08 >> 0x10) == 0x37)) ||
                            ((D_86502E70 != 0) && ((D_8650AB28->unk_014.unk_040.unk_08 >> 0x10) == 0x5E)))) {
                    var_s1 = 1;
                }
            } else if ((D_86502CD4 == 0) && (D_8650AB28->unk_00E >= 3) &&
                       ((D_8650AB28->unk_008 == 0) || (D_8650AB28->unk_008 == 3))) {
                D_8650AB28->unk_008 = 1;
                var_s1 = 1;
                if ((D_8780FC92 == 0) && (D_8780FC94 == 0)) {
                    func_8004D9B0(0x80001, i, 0);
                }
            } else if ((D_86502CD4 == 0) && (D_8650AB28->unk_00E < 3) && (D_8650AB28->unk_008 == 2)) {
                D_8650AB28->unk_008 = 3;
                var_s1 = 1;
                if ((D_8780FC92 == 0) && (D_8780FC94 == 0)) {
                    func_8004D9B0(0x80001, i, 5);
                }
            } else {
                if ((D_8780FC92 == 0) && (D_8780FC94 == 0)) {
                    temp_ft2 = ROUND_MAX((D_8650AB28->unk_010 * 100.0f) / D_8650AB28->unk_012);

                    if (temp_ft2 >= 0x4B) {
                        var_s0_2 = 4;
                    } else if (temp_ft2 >= 0x32) {
                        var_s0_2 = 3;
                    } else if (temp_ft2 >= 0x19) {
                        var_s0_2 = 2;
                    } else {
                        var_s0_2 = 1;
                    }

                    func_8004D9B0(0x80001, i, var_s0_2);
                    func_8004D9B0(0x80002, i, var_s0_2);
                }

                if (func_80017514(&D_8650AB28->unk_014) != 0) {
                    switch (D_8650AB28->unk_008) {
                        case 0:
                        case 3:
                            var_s1 = 1;
                            D_8650AB28->unk_008 = 0;
                            break;

                        case 1:
                        case 2:
                            var_s1 = 1;
                            D_8650AB28->unk_008 = 2;
                            break;
                    }
                }
            }

            if (!!var_s1) {
                if (D_8650AB28->unk_008 != sp58) {
                    func_8001BD04(&D_8650AB28->unk_014, D_8650AB28->unk_008);
                    if (D_8650AB28->unk_008 != 0) {
                        func_8001BD9C(&D_8650AB28->unk_014, D_8650AB28->unk_008);
                    }
                } else if (D_8650AB28->unk_008 == 6) {
                    if (D_8650AB28->unk_004 == 0) {
                        func_80017464(&D_8650AB28->unk_014, 0x1B);
                        func_80017804(&D_8650AB28->unk_014, 0x1B);
                    } else if (D_8650AB28->unk_004 == 1) {
                        func_80017464(&D_8650AB28->unk_014, 0x4B);
                        func_80017804(&D_8650AB28->unk_014, 0x4B);
                    }
                } else if (var_s1 == 2) {
                    func_80017464(&D_8650AB28->unk_014, D_8650AB28->unk_014.unk_040.unk_08 >> 0x10);
                    if (D_8650AB28->unk_008 != 0) {
                        func_80017804(&D_8650AB28->unk_014, D_8650AB28->unk_014.unk_040.unk_08 >> 0x10);
                    }
                } else {
                    func_80017464(&D_8650AB28->unk_014, 0);
                    if (D_8650AB28->unk_008 != 0) {
                        func_80017804(&D_8650AB28->unk_014, 0);
                    }
                }
            }
        }
    }
}

void func_8650077C(void) {
    u8 i;
    u32 var_a0;

    for (i = 0; i < 13; i++) {
        var_a0 = 0;

        switch (i) {
            case 0:
                var_a0 = 1;
                break;

            case 1:
            case 2:
            case 3:
            case 4:
                if (D_8650A528[i - 1].unk_00C != 1) {
                    var_a0 = 1;
                    if (D_8650A528[i - 1].unk_004 == 0) {
                        D_86502CA0[i]->unk_024 = D_8650A528[i - 1].unk_014.unk_0EC;
                    } else if (D_8650A528[i - 1].unk_004 == 1) {
                        D_86502CA0[i]->unk_024 = D_8650A528[i - 1].unk_014.unk_0DC;
                    }
                }
                break;

            case 5:
            case 6:
            case 7:
            case 8:
                if (D_8650A528[i - 5].unk_00C == 1) {
                    var_a0 = 1;
                }
                break;

            case 9:
            case 10:
            case 11:
            case 12:
                if (D_8650A528[i - 9].unk_00C != 1) {
                    var_a0 = 1;
                }
                break;
        }

        if (var_a0 != 0) {
            func_80017464(D_86502CA0[i], 0);
            func_8001BD9C(D_86502CA0[i], 0);
            func_80017804(D_86502CA0[i], 0);
        }
    }
}

void func_86500904(void) {
    u8 i;
    s16 var_s4 = 0;

    for (i = 0; i < 4; i++) {
        D_8650AB28 = &D_8650A528[i];

        if ((D_8650AB28->unk_010 >= D_8650AB28->unk_012) && (var_s4 < D_8650AB28->unk_010)) {
            var_s4 = D_8650AB28->unk_010;
        }
    }

    for (i = 0; i < 4; i++) {
        D_8650AB28 = &D_8650A528[i];

        if ((D_8650AB28->unk_010 >= D_8650AB28->unk_012) && (var_s4 == D_8650AB28->unk_010)) {
            D_8650AB28->unk_00C = 1;
            func_87802F00(i);

            D_87B000D4++;

            if ((D_8780FC92 == 0) && (D_8780FC94 == 0)) {
                func_8004D9B0(0x80003, i, 0);
            }
        }
    }

    for (i = 0; i < 4; i++) {
        D_8650AB28 = &D_8650A528[i];

        if (D_8650AB28->unk_010 >= D_8650AB28->unk_012) {
            if (D_8650AB28->unk_00C == 1) {
                D_8650AB28->unk_010 = D_8650AB28->unk_012 + 1;
            } else {
                D_8650AB28->unk_010 = D_8650AB28->unk_012;
            }
        }
    }
}

void func_86500AC4(UNUSED s32 arg0) {
    func_878025D0();
    func_86502A68();
}

void func_86500AEC(void) {
    u8 i;

    if ((D_8780FC92 != 0) || (D_8780FC94 != 0) || (D_87B000C8 != 0)) {
        return;
    }

    for (i = 0; i < 4; i++) {
        D_8650AB28 = &D_8650A528[i];

        if (D_8650AB28->unk_000 == 4) {
            if ((D_86509250 == 1) || (D_86509250 == 3) || ((D_86509250 == 0) && (D_86509254 == 1))) {
                if (gControllers[i].buttonPressed & 0x8000) {
                    D_8650AB28->unk_00D += 1;
                }

                if (gControllers[i].buttonPressed & 0x4000) {
                    D_8650AB28->unk_00D -= 2;
                }
            } else if ((D_86509250 == 2) || (D_86509250 == 4) || ((D_86509250 == 0) && (D_86509254 == 2))) {
                if (gControllers[i].buttonPressed & 0x8000) {
                    D_8650AB28->unk_00D -= 2;
                }

                if (gControllers[i].buttonPressed & 0x4000) {
                    D_8650AB28->unk_00D += 1;
                }
            }
        }
    }

    D_8650AD84++;
    if (D_8650AD84 == 2) {
        switch (D_86509250) {
            case 3:
                D_86509250 = 1;
                break;

            case 4:
                D_86509250 = 2;
                break;
        }
    } else if ((D_8650AD84 + 4) == D_8650AD85) {
        D_86509254 = D_86509250;

        switch (D_86509250) {
            case 1:
                D_86509250 = 3;
                break;

            case 2:
                D_86509250 = 4;
                break;
        }
    } else {
        if ((D_8650AD84 + 2) == D_8650AD85) {
            D_86509250 = 0;
        } else if (D_8650AD84 >= D_8650AD85) {
            func_865029C0();
        }
    }
}

void func_86500D38(s32 arg0) {
    u8 i;

    if ((arg0 == 0) || ((arg0 == 3) && (D_87B000D0 == 1))) {
        func_80020460(0x18, 0x16, 0x110, 0x90, 0x15);
        func_80020460(0x18, 0xA5, 0x110, 0x36, 0x14B);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_87801F48(2, 0x19, 0xA6);
        func_87801754(0x62, 0xB0, D_86502CDC);
        func_87801684(0x74, 0xB0, D_86502D4C);
        func_87801824(0x74, 0xC6, D_86502DBC);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    } else if ((arg0 == 1) || (arg0 == 2) || ((arg0 == 3) && (D_87B000D0 == 0))) {
        s16 sp5C[] = {
            0x002B,
            0x0071,
            0x00B7,
            0x00FD,
        };

        gSPDisplayList(gDisplayListHead++, D_8006F518);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

        for (i = 0; i < 4; i++) {
            if (D_8650A528[i].unk_000 == 4) {
                func_87801644(i, sp5C[i], 0xC6, 0.75f);
            } else {
                func_87801644(-1 - i, sp5C[i], 0xC6, 0.75f);
            }
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }

    if ((arg0 == 1) || (arg0 == 2) || ((arg0 == 3) && (D_87B000D0 == 0))) {
        for (i = 0; i < 4; i++) {
            D_8650AB28 = &D_8650A528[i];

            func_8780024C((i * 0x47) + 0x1C, 0xDB, 0x32, D_8650AB28->unk_010, D_8650AB28->unk_012 + 1);
        }
    }

    func_8001F3F4();
    func_8001F470();

    if ((arg0 == 0) || ((arg0 == 3) && (D_87B000D0 == 1))) {
        s32 temp_s0;
        s32 sp48;
        s32 sp44;
        char* sp40 = func_8002D7C0(NULL, 0, D_87806330, 0x2D);

        func_8001EBE0(2, 0);
        func_8001F3B4(0xC);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F36C(0xF9, 0xF4, 0, 0xFF);
        func_8001F1E8(0xA0 - (func_878013D4(D_87B000E0, func_8002D7C0(NULL, 0, D_87806330, 0x2C)) / 2), 0x20,
                      func_8002D7C0(NULL, 0, D_87806330, 0x2C));
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F36C(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F1E8(0x28, 0x34, sp40);

        temp_s0 = (func_8002D80C(sp40) * 0xC) + 0xC;
        func_8001F1E8(0x28, temp_s0 + 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x2E));

        temp_s0 += (func_8002D80C(func_8002D7C0(NULL, 0, D_87806330, 0x2E)) * 0xC) + 0xC;
        func_8001F1E8(0x28, temp_s0 + 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x2F));

        func_8001F1E8(0x8B, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
        func_8001F1E8(0x8B, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
        func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
        func_8001F36C(0x50, 0x50, 0xFF, 0xFF);
        func_87801290(&sp48, &sp44, sp40, func_8002D7C0(NULL, 0, D_87806330, 0x5F), 0xC);
        func_8001F1E8(sp48 + 0x28, sp44 + 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x5F));
        func_8001F324(0xC8, 0xFA, 0xD2, 0xFF);
        func_8001F36C(0x32, 0xE6, 0x82, 0xFF);
        func_87801290(&sp48, &sp44, sp40, func_8002D7C0(NULL, 0, D_87806330, 0x60), 0xC);
        func_8001F1E8(sp48 + 0x28, sp44 + 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x60));
        func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
        func_8001F36C(0x50, 0x50, 0xFF, 0xFF);
        func_8001F1E8(0xA2, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x30));
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F36C(0xFF, 0x80, 0x80, 0xFF);
        func_8001F1E8(0xA2, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x14));
    }

    func_8001F4C4();
    func_8001F444();
}

void func_865013D4(s32 arg0) {
    u8 i;

    func_800079C4();
    func_8000699C(&gDisplayListHead, 0xA6BF);

    if (D_8780FC94 == 0) {
        func_80015348();
    }

    func_80015094(D_87B000E8);

    if (D_8780FC98 == 0) {
        func_86500D38(arg0);
    }

    func_87804FD4();
    func_80007778();

    if (D_8780FC94 == 0) {
        D_87B000C0++;

        if (arg0 == 2) {
            if (D_87B000C8 == 0) {
                D_86502CD4++;
                if (D_86502CD4 >= 0xF) {
                    D_86502CD4 = 0;

                    for (i = 0; i < 4; i++) {
                        D_8650AB28 = &D_8650A528[i];

                        D_8650AB28->unk_010 += D_8650AB28->unk_00D;
                        if (D_8650AB28->unk_010 < 0) {
                            D_8650AB28->unk_010 = 0;
                        } else if (D_8650AB28->unk_010 >= D_8650AB28->unk_012) {
                            D_87B000C8 = 1;
                        }
                        D_8650AB28->unk_00E = D_8650AB28->unk_00D;
                        func_86500020(D_8650AB28, 1);
                    }

                    if (D_87B000C8 != 0) {
                        func_86500904();
                        func_8650077C();
                    }
                }
            } else if (D_86502CD8 < 0xC4) {
                D_86502CD8++;

                switch (D_86502CD8) {
                    case 0x5B:
                    case 0x6F:
                    case 0x83:
                        if ((D_87B000D4 != 4) && (D_8780FC92 == 0)) {
                            func_8004D9B0(0x80004, 0, 0);
                            func_8004D9B0(0x80005, 0, 0);
                        }
                        break;

                    case 0x96:
                        if ((D_87B000D4 != 4) && (D_8780FC92 == 0)) {
                            func_8004D9B0(0x80006, 0, 0);
                        }
                        break;

                    case 0xC3:
                        func_87802EB8(1);
                        break;
                }
            }
        }
    }
}

void func_86501668(void) {
    u8 i;
    u8 var_s1;
    s32 var_s2;

    var_s1 = 0;
    var_s2 = 1;

    func_800077B4(5);
    func_80006C6C(0x10);

    while (var_s2 != 0) {
        if (var_s1 >= 0x11) {
            if (gPlayer1Controller->buttonPressed & 0x1000) {
                var_s2 = 0;
            } else if ((D_8780FA2A == 0) && (gPlayer1Controller->buttonPressed & 0x4000)) {
                func_80048B90(3);
                func_87802EB8(2);
                D_87B000D0 = 1;
                return;
            }
        }

        func_87B00020();
        func_86500AC4(0);
        func_86500238();
        func_865013D4(0);

        if (var_s1 < 0x11) {
            var_s1++;
        }
    }

    func_8004B9C4(0x3C);

    if (D_8780FC92 == 0) {
        while (true) {
            if (D_87B000C4 <= 0) {
                break;
            }

            for (i = 3; i > 0; i--) {
                s32 tmp = (i * 0x3C) / 2;
                if (tmp == D_87B000C4) {
                    if (i == 3) {
                        func_8780295C(1);
                    }
                    func_8004D9B0(0x80007, 0, 0);
                }
            }

            D_87B000C4--;

            func_87B00020();
            func_86500AC4(1);
            func_86500238();
            func_865013D4(1);
        }
    }
}

void func_86501828(void) {
    static u8 D_86502E7C = 0;

    s32 var_s0 = 1;

    if (D_8780FC92 == 0) {
        func_865029C0();
        func_8004D9B0(0x80008, 0, 0);
        func_87B00020();
        func_86500AC4(2);
        func_86500238();
        func_865013D4(2);

        while (var_s0 != 0) {
            if (D_8780FC92 != 0) {
                break;
            }

            if ((D_86502E7C == 0) && (func_87802974() == -2)) {
                func_8004B1CC(0x1D);
                D_86502E7C = 1;
            }

            func_87B00020();
            func_86500AC4(2);

            if (D_87B000C8 == 0) {
                func_86500AEC();
            } else if (D_8780FC96 != 0) {
                var_s0 = 0;
            }

            func_86502110(2);
            func_86500238();
            func_865013D4(2);
        }
    }
}

void func_86501964(void) {
    u8 i;

    func_8004FC60(1, 0x1E);
    func_8004FC60(2, 0x1E);
    func_80006CB4(0x1E);

    for (i = 0; i < 30; i++) {
        func_87B00020();
        func_86500AC4(3);
        func_86502110(3);
        func_86500238();
        func_865013D4(3);
    }
}

void func_865019E4(void) {
    D_87B000EC = D_87B000E8->unk_00.unk_0C;

    D_87B000F0 = -0x200;
    D_87B000F2 = 0;
    D_87B000F4 = 0xBE;

    D_87B000EC->unk_24.near = 50.0f;
    D_87B000EC->unk_24.far = 6400.0f;
    D_87B000EC->unk_24.fovy = 40.0f;

    D_87B000EC->unk_60.at.y = 51.0f;

    func_80010354(&D_87B000EC->unk_60.at, &D_87B000EC->unk_60.eye, D_87B000F4, D_87B000F0, D_87B000F2);
}

void func_86501AAC(void) {
    u8 j;
    u8 i;
    MemoryBlock* temp_v0;

    temp_v0 = func_80002D10(main_pool_get_available(), 0);
    D_87B000E8 = process_geo_layout(temp_v0, D_86502DE4);
    func_80002D60(temp_v0);
    func_8001BB20();
    func_8001987C();
    func_865000C0();
    func_86500140();

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            D_87B000E4 = func_80019D18(0xC5);
        } else {
            D_87B000E4 = func_80019D18(0xC6);
        }

        for (j = 0; j < 4; j++) {
            if (i == D_8650A528[j].unk_004) {
                D_8650AB28 = &D_8650A528[j];
                D_8650AB2C = &D_8650AB28->unk_014;

                func_8001BB58(D_8650AB2C);

                if (i == 0) {
                    func_8001BC34(D_8650AB2C, 0, 0xC5, D_87B000E4->unk_08->unk_00[0]);
                } else {
                    func_8001BC34(D_8650AB2C, 0, 0xC6, D_87B000E4->unk_08->unk_00[0]);
                }

                D_8650AB28->unk_008 = 0;
                func_8001BD04(D_8650AB2C, D_8650AB28->unk_008);
                func_80017464(D_8650AB2C, func_87B00050(D_8650AB2C->unk_040.unk_04->unk_0A));

                D_8650AB2C->unk_024.x = D_86502C20[j].unk_00;
                D_8650AB2C->unk_024.y = D_86502C20[j].unk_04;

                if (i == 0) {
                    D_8650AB2C->unk_024.y += 0.15f;
                }

                D_8650AB2C->unk_024.z = D_86502C20[j].unk_08;

                D_8650AB2C->unk_030.x = D_86502C20[j].unk_0C;
                D_8650AB2C->unk_030.y = D_86502C20[j].unk_10;
                D_8650AB2C->unk_030.z = D_86502C20[j].unk_14;

                D_8650AB2C->unk_01E.x = D_86502C20[j].unk_18;
                D_8650AB2C->unk_01E.y = D_86502C20[j].unk_1A;
                D_8650AB2C->unk_01E.z = D_86502C20[j].unk_1C;

                D_8650AB28->unk_00C = 0;
                D_8650AB28->unk_00E = 0;

                func_86500020(D_8650AB28, 0);

                D_8650AB28->unk_010 = 0;
                D_8650AB28->unk_012 = 0x28;
            }
        }
    }

    {
        u16 sp5C[] = {
            0x00C9, 0x00C8, 0x00C8, 0x00C8, 0x00C8, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF, 0x00D0, 0x00D1,
        };

        for (j = 0; j < 13; j++) {
            if ((j != 2) && (j != 3) && (j != 4)) {
                D_87B000E4 = func_80019D18(sp5C[j]);
            }

            D_8650AB2C = D_86502CA0[j];

            func_8001BB58(D_8650AB2C);
            func_8001BC34(D_8650AB2C, 0, sp5C[j], D_87B000E4->unk_08->unk_00[0]);
            func_8001BD04(D_8650AB2C, 0);
            func_80017464(D_8650AB2C, D_8650AB2C->unk_040.unk_04->unk_0A);
        }
    }

    func_86502BB8();
    func_86502848();
    func_865019E4();
    func_87802528();
    func_878029C0();
    func_87801684(0, 0, NULL);
    func_87801754(0, 0, NULL);
}

void func_86501E9C(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('MINI');

    func_80005E40(0x18000, 0);
    sp24 = func_80007444(0, 1, 3, 1, 2, 1);
    D_87B000E0 = func_8001E94C(0x16, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    FRAGMENT_LOAD(fragment31);

    func_86501AAC();
    func_80007678(sp24);
    func_86501668();
    func_86501828();
    func_86501964();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('MINI');

    func_87803118();
}

static s32 pad_D_86502E98 = 0;

s8 func_86501FC0(s32 arg0, s32 arg1) {
    static u16 D_86502EA0[4][8] = {
        { 0x0001, 0x0001, 0x0001, 0x0032, 0x0032, 0x0005, 0x0000, 0x0000 },
        { 0x0000, 0x0001, 0x0001, 0x0005, 0x0032, 0x0032, 0x0001, 0x0000 },
        { 0x0000, 0x0000, 0x0001, 0x0001, 0x0005, 0x005A, 0x001E, 0x0005 },
        { 0x0000, 0x0000, 0x0000, 0x0000, 0x0005, 0x001E, 0x005A, 0x000A },
    };

    static u16 D_86502EE0[4][13] = {
        { 0x0003, 0x0006, 0x0014, 0x0014, 0x0014, 0x0014, 0x000A, 0x0005, 0x0003, 0x0001, 0x0000, 0x0000, 0x0000 },
        { 0x0003, 0x0006, 0x0014, 0x0014, 0x0014, 0x0014, 0x000A, 0x000A, 0x0005, 0x0003, 0x0001, 0x0000, 0x0000 },
        { 0x0003, 0x0006, 0x0014, 0x0014, 0x0014, 0x0014, 0x000A, 0x000A, 0x000A, 0x0007, 0x0005, 0x0003, 0x0001 },
        { 0x0000, 0x0003, 0x0006, 0x000A, 0x0014, 0x0014, 0x0014, 0x0014, 0x000A, 0x000A, 0x0007, 0x0005, 0x0003 },
    };

    u8 i;
    u16 var_a0;
    u16 var_a2;
    u16* sp24;
    s8 sp23;
    u8 sp22;
    u16 temp_v0;

    if (arg1 == 0) {
        sp24 = D_86502EA0[arg0];
        sp23 = -1;
        sp22 = 8;
    } else if (arg1 == 1) {
        sp24 = D_86502EE0[arg0];
        sp23 = -8;
        sp22 = 0xD;
    }

    var_a0 = 0;

    for (i = 0; i < sp22; i++) {
        var_a0 += sp24[i];
    }

    temp_v0 = func_87B00050(var_a0);

    var_a2 = 0;
    for (i = 0; i < sp22; i++) {
        if ((temp_v0 >= var_a2) && (temp_v0 < (sp24[i] + var_a2))) {
            return i + sp23;
        }
        var_a2 += sp24[i];
    }

    return 0;
}
