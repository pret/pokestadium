#include "fragment8.h"
#include "src/12D80.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/18480.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/6BC0.h"
#include "src/4BDC0.h"
#include "src/6A40.h"
#include "src/F420.h"
#include "src/4BA90.h"
#include "src/490A0.h"
#include "src/30640.h"
#include "src/controller.h"
#include "src/fragments/2/fragment2.h"
#include "src/fragments/4/fragment4.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_86203CEC {
    /* 0x0 */ void* unk_00;
    /* 0x4 */ s16 unk_04;
    /* 0x6 */ s16 unk_06;
} unk_D_86203CEC; // size = 0x8

static u32 D_862038C0[] = {
    0xFFFFFFD8, 0xFFFFFF65, 0x00000056, 0x00000097, 0xA4CFA4B7, 0xA4ECA5B3, 0xA5E9A5C3, 0xA5BF0000, 0xA1A1A1A1,
    0xA1A1A1A1, 0xA4F2A4EC, 0xA4F3A4C0, 0xA4B7A4C6, 0xA1A1A4CF, 0xA4B7A4ED, 0xA4A6A1A3, 0x00000000, 0xA5CFA1BC,
    0xA5C9A5EB, 0xA4CFA1A1, 0xA1A1A1A1, 0xA1A1A1A1, 0xA1A1A1A1, 0xA4CE20A4, 0xA6A4A8A4, 0xF2A1A1A4, 0xAAA4B7A4,
    0xC6000000, 0xA5B8A5E3, 0xA5F3A5D7, 0xA4C7A1A1, 0xA4C8A4D3, 0xA4B3A4A8, 0xA4E8A4A6, 0xA1A30000, 0xA4A4A4C1,
    0xA4D0A4F3, 0xA4B5A4AD, 0xA4CBA1A1, 0xA5B4A1BC, 0xA5EBA4B7, 0xA4BFA4D2, 0xA4C8A4AC, 0xA1A1A4AB, 0xA4C1A1A3,
    0x00000000, 0xA4CFA4B7, 0xA4EB0000, 0xA4C9A4A6, 0xA4C1A4E3, 0xA4AF0000, 0xA4CFA4F3, 0xA4C6A4A4, 0x00000000,
    0xA4D2A4B2, 0x00000000, 0xA4CFA4CA, 0x00000000, 0xA4A2A4BF, 0xA4DE0000, 0xA4E9A4AF, 0xA4B7A4E7, 0xA4A60000,
    0xA4C1A4E5, 0xA4A6A4B7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x000A0005, 0x00020000,
};

static f32 D_86203BA0[4][10] = {
    { 5.5f, 10.5f, 15.5f, 20.5f, 23.79999924f, 27.10000038f, 30.5f, 35.5f, 40.5f, 45.5f },
    { 5.5f, 8.5f, 17.5f, 19.5f, 24.5f, 26.5f, 34.5f, 37.5f, 45.5f, 47.5f },
    { 5.5f, 7.5f, 9.5f, 17.5f, 27.5f, 29.5f, 31.5f, 42.5f, 44.5f, 46.5f },
    { 60.0f, 61.0f, 62.0f, 63.0f, 64.0f, 65.0f, 66.0f, 67.0f, 68.0f, 69.0f },
};

static u32 D_86203C40[] = {
    0x001C000E, 0xFFFFFFFF, 0x0000FFFF, 0x0062000E, 0xFFFFFFFF, 0x00FF00FF, 0x00A8000E,
    0xFFFFFFFF, 0xFF0000FF, 0x00EE000E, 0xFFFFFFFF, 0xFFFF00FF, 0x00000000,
};

static unk_func_87801684 D_86203C74[] = {
    {
        0x303ED80,
        0x02,
    },
    {
        0x303F180,
        0x02,
    },
    {
        0x303F580,
        0x02,
    },
    {
        0x303F180,
        0x02,
    },
    {
        0x0,
        0x0,
    },
};

static unk_func_87801684 D_86203C9C[] = {
    {
        0x3040580,
        0x12,
    },
    {
        0x3040980,
        0x02,
    },
    { 0x3040D80, 0x08 },
    {
        0x3040980,
        0x02,
    },
    { 0x0, 0x0 },
};

static unk_func_87801684 D_86203CC4[] = {
    { 0x03042E00, 0x0E }, { 0x03044360, 0x02 }, { 0x03044A80, 0x06 }, { 0x03044360, 0x02 }, { 0, 0 },
};

static unk_D_86203CEC D_86203CEC[] = {
    { D_87A01190, 0x0019, 0x000F },
    { D_87A01178, 0x0019, 0x0014 },
    { D_87A01180, 0x001E, 0x0028 },
    { D_87A011A4, 0x0028, 0x005A },
};

static u32 D_86203D0C[] = {
    0x0C00FFFF,       (u32)&D_5000000, 0x0B00001E,      0x00000000,      0x014000F0,      0x0000000F,
    0x00000000,       0x00000000,      (u32)&D_5000000, 0x0D000000,      (u32)&D_5000000, 0x14000000,
    0x002B0012,       0xFFFFFF32,      0x16FFFFFF,      0x0F000003,      (u32)&D_5000000, 0x0A000000,
    (u32)&D_800AC840, (u32)&D_6000000, (u32)&D_6000000, (u32)&D_6000000, (u32)&D_3000000, 0x87806398,
    (u32)&D_6000000,  (u32)&D_1000000, 0xFFFFFFFF,      0x0505FFFF,      0x0505FFFF,      0xFFFFFFFF,
    0xFFFFFFFF,       0x05FF05FF,      0x05FF05FF,      0xFFFFFFFF,      0xFFFFFFFF,      0xFF0505FF,
    0xFF0505FF,       0xFFFFFFFF,      0xFFFFFFFF,      0xFFFF05FF,      0xFFFF05FF,      0xFFFFFFFF,
};

// Unused rodata strings
const char D_86203DC0[] = " %dP";
const char D_86203DC8[] = "%s";

static unk_D_86002F30* D_86203E30;
static unk_D_86002F30* D_86203E34;
static unk_D_86002F34* D_86203E38;
static unk_D_86002F34_00C* D_86203E3C;
static s16 D_86203E40;
static s16 D_86203E42;
static s16 D_86203E44;
static u16 D_86203E46;
static s32 D_86203E48;
static s16 D_86203E4C;
static unk_D_86203E50 D_86203E50[4];
static unk_D_86203E50* D_86204590;
static unk_D_86002F58_004_000* D_86204594;
static unk_D_86002F58_004_000 D_86204598;
static s16 D_86204700;
static u32 D_86204704;
static s16 D_86204708;
static s16 D_8620470A;
static s16 D_8620470C;
static s16 D_8620470E;
static f32 D_86204710;
static unk_D_800AC870* D_86204714;
static s16 D_86204718;
static s16 D_8620471A;
static s16 D_8620471C;
static unk_D_86204720 D_86204720[4][10];
static unk_D_86204720* D_86208280;
static s32 D_86208288[4];
static s32 D_86208298;
static s16 D_8620829C;
u32 D_862082A0[4];

void func_86200020(unk_D_86203E50* arg0) {
    arg0->unk_002 = D_8780FA38 + 1;
}

void func_86200034(void) {
    UNUSED s32 pad[3];
    MtxF spDC;
    Mtx sp98;
    s32 i;
    UNUSED s32 pad2[1];

    func_80031EF4(&spDC, &D_86203E3C->unk_60.mtxf);
    guMtxF2L(spDC.mf, &sp98);

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;
        if (D_86204590->unk_19E == 2) {
            switch (D_86204590->unk_1B2) {
                case 0:
                    gDisplayListHead = func_87A00098(gDisplayListHead, &sp98, -(i - 1.5f) * 40.0f, 5.0f, 30.0f, 0.25f,
                                                     &D_4000008, 0x20, 0x20);
                    break;

                case 1:
                    gDisplayListHead = func_87A00098(gDisplayListHead, &sp98, -(i - 1.5f) * 40.0f, 5.0f, 30.0f, 0.25f,
                                                     &D_4000810, 0x20, 0x20);
                    break;

                case 2:
                    gDisplayListHead = func_87A00098(gDisplayListHead, &sp98, -(i - 1.5f) * 40.0f, 5.0f, 30.0f, 0.25f,
                                                     &D_4001018, 0x20, 0x20);
                    break;

                case 3:
                    gDisplayListHead = func_87A00098(gDisplayListHead, &sp98, -(i - 1.5f) * 40.0f, 5.0f, 30.0f, 0.25f,
                                                     &D_4001820, 0x20, 0x20);
                    break;
            }
        }
    }
}

void func_862002EC(void) {
}

void func_862002F4(void) {
    UNUSED s32 pad[2];
    s32 i;
    unk_D_86203CEC* temp_s0;
    u16 sp60[4];
    f32 temp_fv0;
    f32 temp_fv1;

    sp60[0] = D_80068BA0->unk_08;
    sp60[1] = D_80068BA4->unk_08;
    sp60[2] = D_80068BA8->unk_08;
    sp60[3] = D_80068BAC->unk_08;

    if (D_86203E48 == 2) {
        for (i = 0; i < 4; i++) {
            D_86204590 = &D_86203E50[i];

            if (D_86204590->unk_002 == 0) {
                D_86204590->unk_170 = sp60[i];
            } else {
                D_86204590->unk_170 = 0;
                if (D_86204590->unk_002 > 0) {
                    temp_s0 = &D_86203CEC[D_86204590->unk_002 - 1];

                    if (func_878001E8(0x64) < temp_s0->unk_04) {
                        D_86204590->unk_170 |= 0x8000;
                    }

                    if (func_878001E8(0x64) < temp_s0->unk_06) {
                        temp_fv0 = D_86204590->unk_1A8;
                        temp_fv1 = D_86204590->unk_1A4;
                        if (((temp_fv0 + 10.0f) < temp_fv1) && (temp_fv1 < (temp_fv0 + 20.0f))) {
                            D_86204590->unk_170 |= 0x800;
                        }
                    }
                }
            }
        }

        return;
    }

    for (i = 0; i < 4; i++) {
        D_86203E50[i].unk_170 = sp60[i];
    }
}

void func_862004D8(void) {
    D_8620471A = 0;
    if (func_80007604() == 0) {
        D_8620471A = 1;
        Cont_StartReadInputs();
        Cont_ReadInputs();
        func_8001F730();
        func_862002F4();
    }
}

void func_86200528(void) {
    D_8620829C = 0;
    D_86203E3C = D_86203E38->unk_00.unk_0C;

    func_87A00020(D_86203E3C);
    D_86203E40 = 0x1300;
    D_86203E42 = -0x6700;
    D_86203E44 = 0x14A;

    D_86203E3C->unk_24.near = 50.0f;
    D_86203E3C->unk_24.far = 6400.0f;
    D_86203E3C->unk_24.fovy = 30.0f;

    D_86203E3C->unk_60.at.x = 0.0f;
    D_86203E3C->unk_60.at.y = 0.0f;
    D_86203E3C->unk_60.at.z = 5.0f;

    func_80010354(&D_86203E3C->unk_60.at, &D_86203E3C->unk_60.eye, D_86203E44, D_86203E40, D_86203E42);
}

void func_86200620(void) {
    switch (D_86203E48) {
        case 0:
            D_86203E40 = 0xD00;
            D_86203E42 = -0x1D00;
            D_86203E44 = 0x1F4;
            break;

        case 1:
            if (D_86203E40 > 0x1300) {
                D_86203E40 -= 0x20;
            }

            if (D_86203E42 > 0x9900u) {
                D_86203E42 -= 0x100;
                if (D_86203E42 < 0x9900u) {
                    D_86203E42 = -0x6700;
                }
            }

            if (D_86203E44 > 0x14A) {
                D_86203E44 -= 2;
            }
            break;

        case 2:
            if (D_8780FC94 == 0) {
                if (D_86203E44 > 0x14A) {
                    D_86203E44 -= 2;
                }

                D_86203E42 += 0x20;
                if ((u16)D_86203E42 < 0xC000) {
                    D_86203E40 += 0xA;

                    if (D_86203E40 > 0x1500) {
                        D_86203E40 = 0x1500;
                    }
                } else if ((D_86203E40 & 0xFFFF) > 0xA00) {
                    D_86203E40 -= 0xA;
                }
            }
            break;

        case 3:
        case 4:
            if (D_86203E44 > 0xF0) {
                D_86203E44 -= 1;
                if (D_86203E44 < 0xF0) {
                    D_86203E44 = 0xF0;
                }
            }

            if ((D_86203E40 & 0xFFFF) > 0x2FC) {
                D_86203E40 -= 0x1E;
                if ((D_86203E40 & 0xFFFF) < 0x2FC) {
                    D_86203E40 = 0x2FC;
                }
            }
            D_86203E42 += 0x40;
            break;

        case 5:
            D_86203E42 += 0x60;
            break;

        default:
            break;
    }

    if (D_86203E40 > 0x3F00) {
        D_86203E40 = 0x3F00;
    }

    if (D_86203E40 < 0) {
        D_86203E40 = 0;
    }

    if (D_86203E44 < 0x32) {
        D_86203E44 = 0x32;
    }

    func_80010354(&D_86203E3C->unk_60.at, &D_86203E3C->unk_60.eye, D_86203E44, D_86203E40, D_86203E42);
}

void func_86200938(void) {
}

void func_86200940(s32 arg0) {
    UNUSED s32 pad;
    UNUSED u8 sp50[3] = { 0, 0, 30 };
    UNUSED u8 sp4C[3] = { 0, 0, 150 };
    s32 sp48;
    s32 sp44;
    char* sp40;
    s32 sp3C;
    s32 sp38;
    char* sp34;

    func_8001F3F4();
    func_8001F444();

    if (arg0 == 0) {
        func_80020460(0x18, 0x16, 0x110, 0x90, 0x15);
        func_80020460(0x18, 0xA5, 0x110, 0x36, 0x14B);
    }

    func_8001F3F4();

    switch (arg0) {
        case 1:
        case 2:
        case 3:
        case 4:
            break;

        case 0:
            func_8001F470();
            func_8001EBE0(2, 0);
            func_8001F3B4(0xC);
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F36C(0xF9, 0xF4, 0, 0xFF);
            func_8001F1E8(0xA0 - (func_878013D4(D_86204714, func_8002D7C0(NULL, 0, D_87806330, 0x23)) / 2), 0x20,
                          func_8002D7C0(NULL, 0, D_87806330, 0x23));
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F36C(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F1E8(0x28, 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x24));
            func_8001F1E8(0x28, 0x4C, func_8002D7C0(NULL, 0, D_87806330, 0x25));
            func_8001F1E8(0x28, 0x70, func_8002D7C0(NULL, 0, D_87806330, 0x26));
            func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
            func_8001F36C(0x50, 0x50, 0xFF, 0xFF);

            sp40 = func_8002D7C0(NULL, 0, D_87806330, 0x5F);
            func_87801290(&sp48, &sp44, func_8002D7C0(NULL, 0, D_87806330, 0x24), sp40, 0xC);
            if (sp48 >= 0) {
                func_8001F1E8(sp48 + 0x28, sp44 + 0x34, sp40);
            }

            func_8001F324(0xE6, 0xD2, 0xFF, 0xFF);
            func_8001F36C(0x82, 0x50, 0xD2, 0xFF);

            sp34 = func_8002D7C0(NULL, 0, D_87806330, 0x61);
            func_87801290(&sp3C, &sp38, func_8002D7C0(NULL, 0, D_87806330, 0x25), sp34, 0xC);
            if (sp3C >= 0) {
                func_8001F1E8(sp3C + 0x28, sp38 + 0x4C, sp34);
            }

            func_8001F324(0xE6, 0xD2, 0xFF, 0xFF);
            func_8001F36C(0x82, 0x50, 0xD2, 0xFF);
            func_8001F1E8(0x8C, 0xB0, func_8002D7C0(NULL, 0, D_87806330, 0x19));
            func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
            func_8001F36C(0x50, 0x50, 0xFF, 0xFF);
            func_8001F1E8(0xFC, 0xB0, func_8002D7C0(NULL, 0, D_87806330, 0x27));
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F36C(0xFF, 0x80, 0x80, 0xFF);
            func_8001F1E8(0xA2, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x14));
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F36C(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F1E8(0x75, 0xB0, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
            func_8001F1E8(0xE5, 0xB0, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
            func_8001F1E8(0x8B, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
            func_8001F4C4();
            break;
    }

    func_8001F444();

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (arg0 == 0) {
        func_87801C8C(0x56, 0xAC, D_86203CC4);
        func_87801684(0xCC, 0xB0, D_86203C74);
        func_87801824(0x74, 0xC6, D_86203C9C);
        func_87801F48(2, 0x19, 0xA6);
    } else if (D_86204718 == 1) {
        func_878021B4(0x1E, 0x17);
    }
}

void func_86200EC4(s32 arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_862082A0[i] = D_86203E50[i].unk_190 * 36.0f;
    }

    func_800079C4();
    func_8000699C(&gDisplayListHead, 1);

    if (D_8780FC94 == 0) {
        func_80015348();
    }

    func_878025D0();
    func_80015094(D_86203E38);
    gDisplayListHead = func_87A0002C(gDisplayListHead);
    func_86200034();

    if (D_8780FC98 == 0) {
        func_86200940(arg0);
    }

    if (D_86204718 == 0) {
        func_87804FD4();
    } else {
        func_8780005C();
    }

    func_80007778();
    D_86203E46++;
}

s32 func_862011E8(void) {
    s32 i;
    s32 var_s1_3;

    func_800077B4(0xA);
    func_80006C6C(0x10);

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;
        func_8001BD04(D_86204594, 0);
        func_80017788(D_86204594);
        D_86204594->unk_040.unk_0C = 0x10000;
        D_86204594->unk_040.unk_08 = func_878001E8(0x14) << 0x10;
    }

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        if ((D_8780FA30[i] == 0) && (D_86204718 == 0)) {
            D_86204590->unk_002 = 0;
        } else {
            func_86200020(D_86204590);
        }
    }

    D_86203E48 = 0;
    if (D_86204718 == 0) {
        var_s1_3 = 1;
    } else {
        func_86200620();
        func_86200EC4(D_86203E48);
        return 0;
    }

    while (var_s1_3 == 1) {
        func_862004D8();
        func_86200620();
        if (D_8620471A == 1) {
            if (D_80068BA0->unk_08 & 0x1000) {
                var_s1_3 = 0;
            }

            if ((D_8780FA2A == 0) && (D_80068BA0->unk_08 & 0x4000)) {
                func_80048B90(3);
                func_87802EB8(2);
                return -1;
            }
        }
        func_86200EC4(D_86203E48);
    }

    return 0;
}

void func_862013C0(void) {
    s32 i;

    func_80006C6C(0x10);

    for (i = 0; i < 4; i++) {
        func_8001BD04(&D_86203E50[i].unk_008, 0);
    }

    D_86204700 = 1;
    func_8780295C(1);
    D_86203E48 = 1;

    while (D_86204700 == 1) {
        switch (func_87802974()) {
            case 1:
            case 2:
            case 3:
                func_87A010D4(0x60001, 0, 0);
                break;
            case 0:
                D_86204700 = 0;
                break;
        }

        func_862004D8();

        if ((D_86204718 == 1) && (func_80007604() == 0) &&
            ((D_80068BA0->unk_08 | D_80068BA4->unk_08 | D_80068BA8->unk_08 | (D_80068BAC->unk_08 != 0)) != 0)) {
            func_80006CB4(0x1E);
            func_8004B094(0x1E);
            D_86204700 = 0;

            for (i = 0; i < 30; i++) {
                func_86200620();
                func_86200EC4(D_86203E48);
            }

            while (func_800484E0() != 0) {
                func_86200620();
                func_86200EC4(D_86203E48);
            }

            func_8004B154();
            func_87802EB8(2);
        }

        func_86200620();
        func_86200EC4(D_86203E48);
    }
}

void func_862015A0(unk_D_86203E50* arg0) {
    f32 temp_fv0 = arg0->unk_178 - 30.0f;

    arg0->unk_008.unk_024.z = temp_fv0;
    arg0->unk_194 = temp_fv0 / 3.0f;
}

void func_862015C8(unk_D_86203E50* arg0) {
    arg0->unk_19C = 0;
    arg0->unk_180 = 30.0f;
    arg0->unk_184 = 30.0f;
    arg0->unk_17C = 5.0f;
    arg0->unk_188 = 3.0f;
    arg0->unk_174 = 0.0f;
    arg0->unk_178 = 0.0f;
    arg0->unk_198 = -1.0f;
    func_862015A0(arg0);
    arg0->unk_190 = 0.0f - arg0->unk_194;
}

s32 func_86201640(unk_D_86203E50* arg0, unk_D_86204720* arg1) {
    f32 temp_fv0;
    f32 temp_fv1;

    arg0->unk_1A4 = -1.0f;

    if ((arg1->unk_000 == 0) || (arg1->unk_002 == 0) || (arg1->unk_002 >= 2)) {
        return 0;
    }

    temp_fv0 = 30.0f - (arg1->unk_004.unk_040.unk_08 / 111411.2f);
    temp_fv1 = arg0->unk_008.unk_024.z / 3.0f;

    arg0->unk_1A8 = temp_fv1;
    arg0->unk_1A4 = temp_fv0;

    if ((temp_fv0 <= temp_fv1 - 3.0f) && (arg0->unk_19C == 1) && (arg0->unk_008.unk_040.unk_08 >= 0xC0001) &&
        (arg1->unk_170 == 0)) {
        arg1->unk_170 = 1;
    }

    if ((temp_fv0 <= temp_fv1 - 3.0f) || ((temp_fv1 + 3.0f) <= temp_fv0)) {
        return 0;
    }

    if (arg0->unk_19C == 1) {
        if ((arg0->unk_008.unk_040.unk_08 >= 0x20001) && (arg0->unk_008.unk_040.unk_08 < 0x100000)) {
            return 0;
        }
    }
    arg1->unk_170 = 1;
    return -1;
}

void func_86201770(unk_D_86203E50* arg0) {
    arg0->unk_008.unk_040.unk_0C = (arg0->unk_178 * 196608.0f) / arg0->unk_180;
}

void func_86201814(unk_D_86203E50* arg0, s32 arg1) {
    unk_D_86002F58_004_000* temp_s0 = &arg0->unk_008;

    switch (arg1) {
        case 3:
            arg0->unk_19C = 3;
            func_8001BD04(temp_s0, 0);
            temp_s0->unk_040.unk_0C = 0x10000;
            break;

        case 0:
            arg0->unk_19C = 0;
            func_8001BD04(temp_s0, 1);
            func_86201770(arg0);
            break;

        case 1:
            arg0->unk_19C = 1;
            func_8001BD04(temp_s0, 2);
            temp_s0->unk_040.unk_0C = 0x10000;
            func_87A010D4(0x60003, arg0->unk_000, 0);
            break;

        case 2:
            arg0->unk_19C = 2;
            func_8001BD04(temp_s0, 3);
            temp_s0->unk_040.unk_0C = 0x10000;
            func_87A010D4(0x60004, arg0->unk_000, 0);
            break;
    }
}

#ifdef NON_MATCHING
void func_86201900(unk_D_86203E50* arg0) {
    s32 i;
    f32 sp64;
    f32 temp_fs1;
    u32 temp_v0;
    unk_D_86002F58_004_000* temp_s1;
    s32 arg0_unk000 = arg0->unk_000;

    for (i = 0; i < 10; i++) {
        f32 unk_190;
        D_86208280 = &D_86204720[arg0_unk000][i];
        D_86208280->unk_000 = 0;

        temp_fs1 = D_86203BA0[D_8620471C][i];
        sp64 = temp_fs1 * 10.44f * 1.7f - 30.0f;
        temp_s1 = &D_86204720[arg0_unk000][i].unk_004;
        unk_190 = arg0->unk_190;

        // if ((sp64 >= unk_190) || (unk_190 >= (sp64 + 67.64706f))) {
        //	continue;
        // }

        if ((sp64 >= unk_190) && (unk_190 >= (sp64 + 67.64706f))) {

            switch (D_86208280->unk_002) {
                case 0:
                    if ((unk_190 - sp64) < 5.0f) {
                        D_86208280->unk_002 = 1;
                        func_8001BC34(temp_s1, 0, 0xB0, D_86203E34->unk_08->unk_00[arg0_unk000]);
                    }
                    break;

                case 2:
                    D_86208280->unk_17A++;
                    if (D_86208280->unk_17A >= 5) {
                        D_86208280->unk_17A = 0;
                        D_86208280->unk_002 = 3;
                    }
                    break;

                case 3:
                    D_86208280->unk_17A++;
                    if (D_86208280->unk_17A >= 5) {
                        D_86208280->unk_17A = 0;
                        D_86208280->unk_002 = 2;
                    }
                    break;
            }

            if ((D_86208280->unk_002 > 0) && ((unk_190 - sp64) > 64.70588f)) {
                D_86208280->unk_002 = 0;
                func_8001BCF0(temp_s1);
            }

            if (D_86208280->unk_002 >= 2) {
                D_86208280->unk_178++;
                if (D_86208280->unk_178 >= 0x1F) {
                    D_86208280->unk_002 = 0;
                    func_8001BCF0(temp_s1);
                }
            }

            temp_v0 = ((unk_190 - temp_fs1 * 10.44f * 1.7f) + 30.0f) * 1.7f * 65536.0f;
            temp_s1->unk_040.unk_08 = (D_86208280->unk_16C + temp_v0) >> 1;
            D_86208280->unk_16C = temp_v0;

            if (D_86208280->unk_002 == 1) {
                func_8001BD04(temp_s1, 0);
                temp_s1->unk_01D = 0xFF;
            } else if (D_86208280->unk_002 == 3) {
                func_8001BD04(temp_s1, 0);
                temp_s1->unk_01D = 0x80;
            } else if ((D_86208280->unk_002 == 0) || (D_86208280->unk_002 == 2)) {
                temp_s1->unk_040.unk_08 = 0x730000;
            }

            temp_s1->unk_040.unk_0C = 0;
            D_86208280->unk_000 = 1;
        }
    }

    if (arg0) {}
}
#else
void func_86201900(unk_D_86203E50* arg0);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/8/fragment8/func_86201900.s")
#endif

s16 func_86201CD8(void) {
    s32 i;
    s32 j;
    s16 sp86;
    UNUSED s32 pad1[2];
    f32 var_fa0;

    sp86 = 0;

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;

        D_86204590->unk_1A0 = 0;

        if (D_86204590->unk_178 < D_86204590->unk_174) {
            var_fa0 = D_86204590->unk_174 - D_86204590->unk_178;
            if (var_fa0 < 1.0f) {
                D_86204590->unk_178 += var_fa0;
            } else {
                D_86204590->unk_178 += 1.0f;
            }
        } else if (D_86204590->unk_174 < D_86204590->unk_178) {
            var_fa0 = D_86204590->unk_178 - D_86204590->unk_174;
            if (var_fa0 < 1.0f) {
                D_86204590->unk_178 -= var_fa0;
            } else {
                D_86204590->unk_178 -= 1.0f;
            }
        }

        if (D_86204590->unk_19E == 0) {
            switch (D_86204590->unk_19C) {
                case 0:
                    if (D_86204590->unk_170 & 0x800) {
                        func_86201814(D_86204590, 1);
                    } else {
                        if (D_86204590->unk_170 & 0x8000) {
                            D_86204590->unk_174 += D_86204590->unk_188;
                            if (D_86204590->unk_174 < D_86204590->unk_184) {
                                D_86204590->unk_174 = D_86204590->unk_184;
                            }
                        }

                        D_86204590->unk_174 -= (D_86204590->unk_188 / 10.0f);

                        if (D_86204590->unk_180 < D_86204590->unk_174) {
                            D_86204590->unk_174 = D_86204590->unk_180;
                            D_86204590->unk_1A2 = 5;
                        } else {
                            D_86204590->unk_1A2 -= 1;
                            if (D_86204590->unk_1A2 < 0) {
                                D_86204590->unk_1A2 = 0;
                            }
                        }

                        if (D_86204590->unk_174 < 0.0f) {
                            D_86204590->unk_174 = 0.0f;
                        }

                        func_86201770(D_86204590);
                    }

                    if (D_86204590->unk_174 <= D_86204590->unk_17C) {
                        func_86201814(D_86204590, 3);
                    }
                    break;

                case 1:
                    if (func_80017514(D_86204594) != 0) {
                        func_86201814(D_86204590, 0);
                    }
                    break;

                case 2:
                    D_86204590->unk_174 = 0.0f;
                    if (func_80017514(D_86204594) != 0) {
                        func_86201814(D_86204590, 3);
                    }
                    break;

                case 3:
                    D_86204590->unk_174 = 0.0f;
                    if (D_86204590->unk_170 & 0x8000) {
                        D_86204590->unk_174 = D_86204590->unk_184;
                        func_86201814(D_86204590, 0);
                    }
                    break;
            }

            D_86204590->unk_18C = D_86204590->unk_190;
            D_86204590->unk_190 += D_86204590->unk_178 * 0.05f;

            func_862015A0(D_86204590);

            for (j = 0; j < 10; j++) {
                D_86208280 = &D_86204720[i][j];

                if ((D_86208280->unk_002 == 1) && (func_86201640(D_86204590, D_86208280) != 0)) {
                    func_86201814(D_86204590, 2);
                    D_86208280->unk_002 = 2;
                    D_86208280->unk_17A = 0;
                    D_86204590->unk_1AC += 1;
                }
            }

            if (D_86204590->unk_190 + D_86204590->unk_194 >= 885.0f) {
                var_fa0 = 0.0f;
                if (D_86204590->unk_178 > 0.0f) {
                    f32 var_fa1 = (885.0f - D_86204590->unk_18C);

                    var_fa0 = var_fa1 / (D_86204590->unk_178 * 0.05f);
                }

                D_86204590->unk_198 = D_86204704 + var_fa0;
                D_86204590->unk_19E = 1;
                D_86204590->unk_174 = D_86204590->unk_180;
                D_86204590->unk_178 = D_86204590->unk_174;

                func_8001BD04(D_86204594, 2);
                D_86204594->unk_040.unk_0C = 0x10000;

                switch (D_86208298) {
                    case 0:
                        func_87A010D4(0x60006, D_86204590->unk_000, 0);
                        break;

                    case 3:
                        func_87A010D4(0x60008, D_86204590->unk_000, 0);
                        break;

                    default:
                        func_87A010D4(0x60007, D_86204590->unk_000, 0);
                        break;
                }

                D_86208288[D_86208298] = i;
                D_86208298++;
                D_86204590->unk_1A0 = 1;
                sp86++;
            } else {
                D_86204590->unk_18C = D_86204590->unk_190 + D_86204590->unk_194;
            }
        } else {
            D_86204590->unk_190 += D_86204590->unk_178 * 0.05f;

            if (D_86204590->unk_190 > 910.0f) {
                D_86204590->unk_190 = 910.0f;
                D_86204590->unk_19E = 2;
            }

            func_862015A0(D_86204590);

            if (func_80017514(D_86204594) != 0) {
                func_8001BD04(D_86204594, 0);
                D_86204594->unk_040.unk_08 = 0;
                D_86204594->unk_040.unk_0C = 0x10000;
            }
        }
    }

    return sp86;
}

void func_862022CC(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;

        if (D_86204590->unk_19E == 1) {
            D_86204590->unk_190 += D_86204590->unk_178 * 0.05f;
            if (D_86204590->unk_190 > 910.0f) {
                D_86204590->unk_190 = 910.0f;
                D_86204590->unk_19E = 2;
            }

            func_862015A0(D_86204590);

            if (func_80017514(D_86204594) != 0) {
                func_8001BD04(D_86204594, 0);
                D_86204594->unk_040.unk_08 = 0;
                D_86204594->unk_040.unk_0C = 0x10000;
            }
        }
    }
}

void func_862023F8(void) {
    s32 spA4;
    s32 i;
    s32 j;
    s16 temp_s1_2;
    s16 var_s3;
    unk_D_86002F58_004_000* var_s2;
    unk_D_86203E50* temp_s1;
    s16 var_v0_2;
    s16 sp8C;
    unk_D_86203E50* temp_v1;
    unk_D_86203E50* sp78[4];
    unk_D_86203E50* var_s0_3;

    spA4 = 1;

    for (i = 0; i < 4; i++) {
        temp_s1 = &D_86203E50[i];
        var_s2 = &temp_s1->unk_008;

        func_8001BD04(var_s2, 1);
        func_80017788(var_s2);
        var_s2->unk_040.unk_08 = (func_878001E8(5) * 0x3) << 0x10;
        func_862015C8(temp_s1);
        temp_s1->unk_1C8 = 0;
        temp_s1->unk_1B2 = 4;
        temp_s1->unk_19E = 0;
        temp_s1->unk_198 = -1.0f;
    }

    D_86204704 = 0;
    D_86203E4C = 0;
    func_87A010D4(0x60002, 0, 0);
    D_86203E48 = 2;
    D_86203E46 = 0;

    sp8C = 0;
    D_86204710 = 99999.0f;

    while (spA4 != 0) {
        func_862004D8();
        func_86200620();

        if (D_8780FC92 != 0) {
            return;
        }

        if (D_8780FC94 == 0) {
            if (D_86204704 >= 0x708) {
                spA4 = 0;
            }

            if (D_86204718 == 1) {
                if ((D_80068BA0->unk_08 != 0) && (sp8C == 0)) {
                    D_86204704 = 0x1C2;
                    sp8C = 1;
                }

                if (D_86204704 == 0x1C2) {
                    func_80006CB4(0x1E);
                    func_8004B094(0x1E);
                }

                if (D_86204704 >= 0x1E0) {
                    func_87802EB8(2);
                    spA4 = 0;
                }
            }

            if (D_86204704 == 0xF) {
                func_8004B1CC(0x19);
            }

            temp_s1_2 = func_86201CD8();

            for (i = 0; i < 4; i++) {
                func_86201900(&D_86203E50[i]);
            }

            if (temp_s1_2 > 0) {
                var_v0_2 = 0;
                for (i = 0; i < 4; i++) {
                    var_s0_3 = &D_86203E50[i];
                    if (var_s0_3->unk_1A0 == 1) {
                        f32 tmp = var_s0_3->unk_198;

                        if (tmp < D_86204710) {
                            D_86204710 = tmp;
                        }
                        sp78[var_v0_2++] = var_s0_3;
                    }
                }

                if (temp_s1_2 == 1) {
                    sp78[0]->unk_1B2 = D_86203E4C;
                    sp78[0]->unk_1A0 = 0;
                } else {
                    for (i = 0; i < temp_s1_2 - 1; i++) {
                        for (j = i + 1; j < temp_s1_2; j++) {
                            if (sp78[j]->unk_198 < sp78[i]->unk_198) {
                                temp_v1 = sp78[j];
                                sp78[j] = sp78[i];
                                sp78[i] = temp_v1;
                            }
                        }
                    }

                    sp78[0]->unk_1B2 = D_86203E4C;
                    for (i = 1; i < temp_s1_2; i++) {
                        if (sp78[i - 1]->unk_198 < sp78[i]->unk_198) {
                            D_86203E4C++;
                        }
                        sp78[i]->unk_1B2 = D_86203E4C;
                    }

                    for (i = 0; i < temp_s1_2; i++) {
                        sp78[i]->unk_1A0 = 0;
                    }
                }

                D_86203E4C++;
            }

            var_s3 = 0;
            for (i = 0; i < 4; i++) {
                if (D_86203E50[i].unk_19E == 2) {
                    var_s3++;
                }
            }

            if (var_s3 >= 4) {
                spA4 = 0;
            }

            D_86204704++;
        }

        func_86200EC4(D_86203E48);
    }

    var_s3 = 0;
    for (i = 0; i < 4; i++) {
        if (D_86203E50[i].unk_19E == 1) {
            var_s3++;
        }
    }

    while (var_s3 > 0) {
        func_862004D8();
        func_86200620();
        if (D_8780FC92 == 0) {
            if (D_8780FC94 == 0) {
                var_s3 = 0;
                func_862022CC();

                for (i = 0; i < 4; i++) {
                    func_86201900(&D_86203E50[i]);
                }

                for (i = 0; i < 4; i++) {
                    if (D_86203E50[i].unk_19E == 1) {
                        var_s3++;
                    }
                }
            }

            func_86200EC4(D_86203E48);
        } else {
            return;
        }
    }

    var_s3 = 0;
    D_86204708 = 0;

    for (i = 0; i < 4; i++) {
        temp_s1 = &D_86203E50[i];

        if ((temp_s1->unk_19E > 0) && (temp_s1->unk_1B2 == 0)) {
            func_87802F00(i);
            D_86204708++;
            temp_s1->unk_1C8 = 1;
            if (temp_s1->unk_002 == 0) {
                var_s3 = 1;
            }
        }
    }

    if (D_86204708 != 1) {
        D_8620470A = 1;
    } else if (var_s3 == 1) {
        func_8004B1CC(0xBD);
    } else {
        func_8004B1CC(0xBE);
    }
}

#ifdef NON_MATCHING
void func_86202C7C(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;

        if (((D_86204590->unk_19E <= 0) || (D_86204590->unk_1C8 != 1)) &&
            ((func_80017514(D_86204594) != 0) || (D_86204594->unk_040.unk_08 >= 0x340000))) {
            func_8001BD04(D_86204594, 5);
            D_86204594->unk_040.unk_08 = 0x270000;
        }
    }
}
#else
void func_86202C7C(void);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/8/fragment8/func_86202C7C.s")
#endif

void func_86202D5C(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        D_86204594 = &D_86204590->unk_008;
        if ((D_86204590->unk_19E > 0) && (D_86204590->unk_1C8 == 1)) {
            func_8001BD04(D_86204594, 4);
            D_86204594->unk_040.unk_0C = 0x10000;
        } else {
            func_8001BD04(D_86204594, 5);
            D_86204594->unk_040.unk_08 = 0;
            D_86204594->unk_040.unk_0C = 0x10000;
            func_8001BD9C(D_86204594, 0);
        }
    }

    while (D_8780FC94 != 0) {
        func_862004D8();
        func_86200EC4(D_86203E48);
    }

    func_87802EB8(1);
    D_86203E48 = 3;

    for (i = 0; i < 120; i++) {
        func_862004D8();
        func_86200620();
        func_86200EC4(D_86203E48);
    }

    for (i = 0; i < 30; i++) {
        func_862004D8();
        func_86200620();
        func_86200EC4(D_86203E48);
    }
}

void func_86202EE4(void) {
    while (func_800484E0() != 0) {
        func_862004D8();
        func_86200EC4(D_86203E48);
    }
    func_8004B154();
}

void func_86202F3C(void) {
    s32 i;

    func_8004B9C4(0x1E);
    func_80006CB4(0x1E);

    for (i = 0; i < 30; i++) {
        func_862004D8();
        func_86200EC4(D_86203E48);
    }
}

void func_86202FA4(s32 arg0) {
    s32 i;

    D_86203E48 = 6;

    for (i = 0; i < arg0; i++) {
        func_862004D8();
        func_86200EC4(D_86203E48);
    }
}

void func_86203008(void) {
    D_86203E48 = 5;

    while (D_8780FC96 == 0) {
        if ((D_8780FA2A == 1) && (D_8620470E > 0)) {
            D_8620470E -= 0xA;
            if (D_8620470E < 0) {
                D_8620470E = 0;
            }
        }

        func_862004D8();
        func_86200620();
        func_86202C7C();
        func_86200EC4(D_86203E48);
    }
}

void func_862030D0(void) {
    s32 i;
    s32 j;
    MemoryBlock* temp_v0 = func_80002D10(main_pool_get_available(), 0);
    unk_D_86002F58_004_000* temp_s0;

    D_86203E38 = func_80018B70(temp_v0, &D_86203D0C);
    func_80002D60(temp_v0);
    func_8001BB20();
    func_8001987C();
    D_8620470E = 0xFF;
    D_8620471A = 0;
    D_86203E30 = func_80019D18(0xB8);
    func_8001BB58(&D_86204598);
    func_8001BC34(&D_86204598, 0, 0xB8, D_86203E30->unk_08->unk_00[0]);
    D_86204598.unk_024.y = -26.0f;
    D_86203E30 = func_80019D18(0xAF);

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        temp_s0 = &D_86204590->unk_008;
        D_86204590->unk_000 = i;

        func_86200020(D_86204590);
        func_8001BB58(temp_s0);
        func_8001BC34(temp_s0, 0, 0xAF, D_86203E30->unk_08->unk_00[0]);
        temp_s0->unk_024.x = -(i - 1.5f) * 40.0f;
        temp_s0->unk_024.y = 0.0f;
        temp_s0->unk_030.x = 1.0f;
        temp_s0->unk_030.y = 1.0f;
        temp_s0->unk_030.z = 1.0f;
        func_8001BD04(temp_s0, 0);
        func_80017788(temp_s0);
        func_862015C8(D_86204590);
        temp_s0->unk_040.unk_0C = 0x20000;
    }

    D_86203E34 = func_80019D18(0xB0);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 10; j++) {
            D_86208280 = &D_86204720[i][j];
            temp_s0 = &D_86208280->unk_004;

            func_8001BB58(temp_s0);

            D_86208280->unk_000 = 0;
            D_86208280->unk_002 = 0;
            temp_s0->unk_024.x = -(i - 1.5f) * 40.0f;
            temp_s0->unk_024.y = -25.0f;
            temp_s0->unk_040.unk_08 = 0x730000;
            temp_s0->unk_040.unk_0C = 0;
        }
    }

    func_86200528();
    func_87802528();
}

void func_86203380(void) {
    s32 i;
    s32 j;
    unk_D_86002F58_004_000* temp_s0;

    D_86208298 = 0;
    D_8620470A = 0;
    D_8620471C = func_878001E8(3);

    for (i = 0; i < 4; i++) {
        D_86204590 = &D_86203E50[i];
        temp_s0 = &D_86204590->unk_008;

        D_86204590->unk_000 = i;
        D_86204590->unk_19E = 0;
        func_86200020(D_86204590);
        D_86204590->unk_1A2 = 0;
        D_86204590->unk_1AE = 0;
        D_86204590->unk_1B0 = 0;
        D_86204590->unk_1AC = 0;
        D_86204590->unk_1B2 = 4;
        D_86204590->unk_1B4 = 0;
        D_86204590->unk_170 = 0;
        func_862015C8(D_86204590);
        temp_s0->unk_024.x = -(i - 1.5f) * 40.0f;
        temp_s0->unk_024.y = 0.0f;
        temp_s0->unk_030.x = 1.0f;
        temp_s0->unk_030.y = 1.0f;
        temp_s0->unk_030.z = 1.0f;
        temp_s0->unk_040.unk_0C = 0x20000;
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 10; j++) {
            D_86208280 = &D_86204720[i][j];
            temp_s0 = &D_86208280->unk_004;

            D_86208280->unk_000 = 0;
            D_86208280->unk_002 = 0;
            D_86208280->unk_178 = 0;
            D_86208280->unk_170 = 0;
            temp_s0->unk_024.x = -(i - 1.5f) * 40.0f;
            temp_s0->unk_024.y = -25.0f;
            temp_s0->unk_040.unk_08 = 0x730000;
            temp_s0->unk_040.unk_0C = 0;
        }
    }
}

void func_8620369C(s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    if (arg0 == 1) {
        D_86204718 = 1;
        func_878010C8(3);
    } else {
        D_86204718 = 0;
    }

    main_pool_push_state('MINI');

    func_80005E40(0x10000, 0);

    sp24 = func_80007444(0, 0, 3, 1, 2, 1);
    D_86204714 = func_8001E94C(0x16, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_4000000, run_rattata_run_flag_gfx, 0);
    FRAGMENT_LOAD(fragment31);

    func_80004454((((u32)&D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, _5C7A70_ROM_END);

    func_862030D0();
    func_878029C0();
    func_80007678(sp24);
    func_86203380();

    if (func_862011E8() != -1) {
        func_8004B9C4(0x3C);
        func_86202FA4(5);
        func_862013C0();
        func_862023F8();
        if ((D_8780FC92 == 0) && (D_86204718 == 0)) {
            func_86202D5C();
            func_86203008();
        }
    }

    if (D_86204718 == 0) {
        func_86202F3C();
    } else {
        func_86202EE4();
    }

    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('MINI');

    func_87803118();
}
