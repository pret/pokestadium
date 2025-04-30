#include "fragment16.h"
#include "src/11BA0.h"
#include "src/12D80.h"
#include "src/geo_layout.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/4BDC0.h"
#include "src/50860.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/dp_intro.h"
#include "src/fragments/34/fragment34.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_86A02700 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ Color_RGB8 unk_03[4];
} unk_D_86A02700; // size = 0x10

static unk_D_8690A610 D_86A06170;
static struct GraphNode D_86A06190;
static struct GraphNode D_86A061A8;
static struct GraphNode D_86A061C0;
static s8 D_86A061D8;
static u8 D_86A061D9;
static BinArchive* D_86A061DC;
static Color_RGBA8_u32 D_86A061E0;
static GraphNode* D_86A061E4;
static unk_D_86002F34_00C* D_86A061E8;
static s16 D_86A061EC;
static s16 D_86A061EE;
static s16 D_86A061F0;
static s32 pad_D_86A061F8[2];
static unk_D_800AC870* D_86A06200;
static s32 pad_D_86A06208[2];
u8 D_86A06210;
u8 D_86A06211;
u8 D_86A06212;
unk_D_86A03014* D_86A06214;
char** D_86A06218;
u32 D_86A0621C;
u16 D_86A06220;
u16 D_86A06222;
Vec3f D_86A06228;
f32 D_86A06234;
Vec3f D_86A06238;
f32 D_86A06244;
Vec3f D_86A06248;
unk_D_86002F34_00C* D_86A06254;
s16 D_86A06258;
s16* D_86A0625C;

unk_D_86A025A0 D_86A025A0[9] = {
    {
        0x00,
        0x00,
        0x0528,
    },
    {
        0x00,
        0x01,
        0x0438,
    },
    {
        0x00,
        0x02,
        0x0438,
    },
    {
        0x00,
        0x03,
        0x0438,
    },
    {
        0x00,
        0x04,
        0x0438,
    },
    {
        0x00,
        0x05,
        0x0438,
    },
    {
        0x00,
        0x06,
        0x0528,
    },
    {
        0x00,
        0x07,
        0x0438,
    },
    {
        0xFF,
        0x00,
        0x0000,
    },
};
u8 D_86A025C4 = 0;
u32 D_86A025C8 = 0;
u16 D_86A025CC = 0;
u32 D_86A025D0[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E,    0x00000000, 0x014000F0,  0x0000000F, 0x00000000,  0x00000000,
    0x05000000, 0x0D000000, 0x05000000,    0x07000000, &D_86A06170, 0x14000000, 0x002D0019,  0xFFFFFF28,
    0x16646464, 0x0F000002, 0x05000000,    0x1F00FFFF, 0x00000000,  0x00000000, 0x00000000,  0x00640064,
    0x00640000, 0x08000000, func_86A00020, 0x00000000, 0x05000000,  0x07000000, &D_86A06190, 0x06000000,
    0x06000000, 0x0F000003, 0x05000000,    0x1F00FFFF, 0x00000000,  0x00000000, 0x00000000,  0x00640064,
    0x00640000, 0x08000000, func_86A00020, 0x00000000, 0x05000000,  0x07000000, &D_86A061A8, 0x06000000,
    0x06000000, 0x0F000002, 0x05000000,    0x1F00FFFF, 0x00000000,  0x00000000, 0x00000000,  0x00640064,
    0x00640000, 0x08000000, func_86A00020, 0x00000000, 0x05000000,  0x07000000, &D_86A061C0, 0x06000000,
    0x06000000, 0x0F000003, 0x05000000,    0x0A000000, &D_800AC840, 0x06000000, 0x06000000,  0x06000000,
    0x06000000, 0x01000000,
};

s32 func_86A00020(s32 arg0, GraphNode* arg1) {
    unk_D_86002F58_004_000* ptr = (unk_D_86002F58_004_000*)arg1;

    if (arg0 == 2) {
        ptr->unk_03C.rgba = D_86A061E0.rgba;
    }
    return 0;
}

void func_86A0003C(u8 r, u8 g, u8 b) {
    u8 v = r & g & b;

    D_86A061E0.r = r;
    D_86A061E0.g = g;
    D_86A061E0.b = b;

    if (v == 0xFF) {
        if (D_86A06170.unk_00.unk_14 == 1) {
            D_86A06170.unk_00.unk_01 |= 1;
        }
    } else {
        D_86A06170.unk_00.unk_01 &= ~1;
    }
}

void func_86A000B4(s8 arg0, u8 arg1) {
    MemoryBlock* sp2C;
    FragmentEntry sp28;
    u32* temp_v0;
    unk_D_8690A610_018* temp_v0_4;

    while (func_80001C90() == 0) {}

    func_8001103C(NULL, &D_86A06190);
    func_8001103C(NULL, &D_86A061A8);
    func_8001103C(NULL, &D_86A061C0);

    main_pool_pop_state('BACK');

    main_pool_push_state('BACK');

    sp28 = func_8000484C(D_86A061DC, arg0);
    sp2C = func_80002D10(main_pool_get_available(), 0);

    temp_v0 = sp28(0, 0);
    if (temp_v0 != NULL) {
        func_80012094(&D_86A06190, process_geo_layout(sp2C, temp_v0));
    }

    temp_v0 = sp28(1, 0);
    if (temp_v0 != NULL) {
        func_80012094(&D_86A061A8, process_geo_layout(sp2C, temp_v0));
    }

    temp_v0 = sp28(3, 0);
    if (temp_v0 != NULL) {
        func_80012094(&D_86A061C0, process_geo_layout(sp2C, temp_v0));
    }

    D_86A025C8 = sp28(2, 0);
    func_80002D60(sp2C);

    temp_v0_4 = sp28(4, 0);
    if (temp_v0_4 == NULL) {
        D_86A06170.unk_00.unk_14 = 0;
        D_86A06170.unk_00.unk_01 &= ~1;
    } else {
        D_86A06170.unk_18.unk_00 = temp_v0_4->unk_00;
        D_86A06170.unk_18.unk_02 = temp_v0_4->unk_02;
        D_86A06170.unk_18.unk_04.rgba = temp_v0_4->unk_04.rgba;
        D_86A06170.unk_00.unk_14 = 1;
    }

    func_86A0003C(0xFF, 0xFF, 0xFF);

    if (arg1 < 6) {
        func_86A01CF0(&D_86A061EC, &D_86A061EE, &D_86A061F0, D_86A061E8, D_86A025A0[D_86A025C4].unk_02, arg0, arg1);
    } else if (arg1 < 9) {
        func_86A01CF0(&D_86A061EC, &D_86A061EE, &D_86A061F0, D_86A061E8, D_86A025A0[D_86A025C4].unk_02, arg0, arg1);
    } else if (arg1 < 0xF) {
        if (D_86A025C4 == 7) {
            func_86A018D0(D_86A061E8, D_86A025A0[D_86A025C4].unk_02 - 0x28, arg0, arg1);
        } else {
            func_86A018D0(D_86A061E8, D_86A025A0[D_86A025C4].unk_02, arg0, arg1);
        }
    } else {
        D_86A061E8->unk_60.at.y = D_86A03170[arg0][D_86A061D9].unk_10;
        D_86A061F0 = D_86A03170[arg0][D_86A061D9].unk_08;
    }
}

void func_86A00434(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_86A00464(void) {
    if (D_86A061D9 < 6) {
        func_80010354(&D_86A061E8->unk_60.at, &D_86A061E8->unk_60.eye, D_86A061F0, D_86A061EC, D_86A061EE);
    } else if (D_86A061D9 < 9) {
        func_80010354(&D_86A06248, &D_86A061E8->unk_60.eye, D_86A061F0, D_86A061EC, D_86A061EE);
        func_80010354(&D_86A06248, &D_86A061E8->unk_60.at, D_86A061F0 + 500.0f, D_86A061EC, D_86A061EE);
    }
}

void func_86A0056C(void) {
    u8 temp_v1_2;

    if (D_86A025A0[D_86A025C4].unk_00 != -1) {
        if (D_86A025CC < 8) {
            temp_v1_2 = (s8)ROUND_MAX(((-(f32)D_86A025CC / 8) + 1.0f) * 255.0f);
            if (temp_v1_2 != 0) {
                func_8001F504(0, 0, 0x140, 0xF0, 0, 0, 0, temp_v1_2);
            }
        } else {
            if ((D_86A025A0[D_86A025C4].unk_02 - 0x28) < D_86A025CC) {
                s32 tmp = D_86A025A0[D_86A025C4].unk_02;

                temp_v1_2 = (s32)ROUND_MAX((((D_86A025CC - tmp) + 0x28) * 255.0f) / 40.0f);
                if (temp_v1_2 != 0) {
                    func_8001F504(0, 0, 0x140, 0xF0, 0, 0, 0, temp_v1_2);
                }
            }
        }
    }
}

void func_86A00720(u8 arg0) {
    if ((arg0 == 1) || (arg0 == 2)) {
        func_86A0056C();
        if ((D_86A025C4 != 0) || (D_86A025CC >= 0xF0)) {
            func_86A014F0();
        }
    }
}

void func_86A00788(u8 arg0) {
    func_800079C4();

    if ((D_86A025C8 == -1) || (D_86A025C8 == 0)) {
        func_8000699C(&gDisplayListHead, 1);
    } else if (D_86A025C8 < 0x10000) {
        func_8000699C(&gDisplayListHead, D_86A025C8);
    } else {
        func_8000699C(&gDisplayListHead, 0xA6BF);
    }

    if (arg0 == 0) {
        func_86A0240C(0);
    } else {
        func_80015094(D_86A061E4);
        func_86A00720(arg0);
    }

    func_80007778();
}

void func_86A00840(void) {
    u8 i;
    u8 j;
    u8 sp35;
    s32 var_s1;

    func_8004B9C4(0x1E);

    for (i = 0; i < 3; i++) {
        var_s1 = sp35;

        switch (i) {
            case 0:
                sp35 = 0x1E;
                func_80006C6C(sp35);
                var_s1 = 0x1E;
                break;

            case 1:
                sp35 = 0x5A;
                var_s1 = sp35;
                break;

            case 2:
                sp35 = 0x78;
                func_80006CB4(sp35);
                var_s1 = sp35;
                break;

            default:
                var_s1 = sp35;
                break;
        }

        for (j = 0; j < var_s1; j++) {
            func_86A00434();
            func_86A00788(0);
        }
    }
}

void func_86A0092C(s32 arg0) {
    static u8 D_86A026F8 = 0;

    s32 var_s6 = 1;

    func_800077B4(0x3C);
    func_80006C6C(0xB4);

    if (arg0 != 0) {
        func_8004B1CC(0x42);
    } else {
        func_8004B1CC(0x43);
    }

    func_86A021C0(&D_86A061D8, &D_86A061D9);
    func_86A000B4(D_86A061D8, D_86A061D9);

    while (var_s6 != 0) {
        func_86A01490();
        func_8140C5D0();

        if (D_86A025A0[D_86A025C4].unk_02 != 0) {
            if (D_86A025A0[D_86A025C4].unk_00 != -1) {
                if (D_86A061D9 < 9) {
                    func_86A02164();
                } else {
                    func_86A01BEC();
                }
            }

            if (D_86A025CC >= D_86A025A0[D_86A025C4].unk_02) {
                D_86A025C4++;
                if (D_86A025A0[D_86A025C4].unk_02 != 0) {
                    D_86A025A0[D_86A025C4].unk_02 =
                        D_86A025A0[D_86A025C4 - 1].unk_02 + (D_86A025A0[D_86A025C4].unk_02 - D_86A025CC);
                }

                D_86A025CC = 0;

                if (D_86A025A0[D_86A025C4].unk_00 != -1) {
                    func_86A021C0(&D_86A061D8, &D_86A061D9);
                    func_86A000B4(D_86A061D8, D_86A061D9);
                } else {
                    D_86A061D8 = -1;
                    D_86A025C8 = 0;

                    func_8001103C(NULL, &D_86A06190);
                    func_8001103C(NULL, &D_86A061A8);
                    func_8001103C(NULL, &D_86A061C0);

                    D_86A06170.unk_00.unk_01 &= ~1;
                    if (D_86A025A0[D_86A025C4].unk_02 == 0) {
                        main_pool_pop_state('BACK');
                    }
                }
            } else if ((D_86A025C4 == 3) && (D_86A026F8 < 2) &&
                       (D_86A025CC >= (((D_86A025A0[D_86A025C4].unk_02 * (D_86A026F8 + 1)) / 3) - 1))) {
                func_86A021C0(&D_86A061D8, &D_86A061D9);
                func_86A000B4(D_86A061D8, 0xFF);
                D_86A026F8++;
            }
        }

        func_86A00434();
        func_86A00464();

        if (D_86A05B50 >= 0x2D1) {
            var_s6 = 0;
        } else if ((D_86A05B50 >= 0x169) &&
                   ((gPlayer1Controller->buttonPressed & 0x1000) || (gPlayer1Controller->buttonPressed & 0x8000))) {
            var_s6 = 0;
        }

        func_86A00788(1);

        if (D_86A025A0[D_86A025C4].unk_02 != 0) {
            D_86A025CC += D_86A06210;
        }
    }
}

static s32 pad_D_86A026FC = 0;
unk_D_86A02700 D_86A02700[] = {
    {
        0,
        0,
        {
            { 0xFF, 0, 0xE6 },
            { 0xFF, 0xC8, 0xFF },
            { 0, 0x46, 0xFF },
            { 0x64, 0xFF, 0xFF },
        },
    },
    {
        8,
        0xFF,
        {
            { 0xFF, 0xC8, 0xFF },
            { 0xFF, 0xFF, 0xFF },
            { 0x64, 0xFF, 0xFF },
            { 0xFF, 0xFF, 0xFF },
        },
    },
    {
        0x1E,
        0xFF,
        {
            { 0xFF, 0, 0xFF },
            { 0xFF, 0xC8, 0xFF },
            { 0, 0x46, 0xFF },
            { 0x64, 0xFF, 0xFF },
        },
    },
    {
        0x153,
        0xFF,
        {
            { 0xFF, 0, 0xFF },
            { 0xFF, 0xC8, 0xFF },
            { 0, 0x46, 0xFF },
            { 0x64, 0xFF, 0xFF },
        },
    },
    {
        0x167,
        0,
        {
            { 0xFF, 0, 0xE6 },
            { 0xFF, 0xC8, 0xFF },
            { 0, 0x46, 0xFF },
            { 0x64, 0xFF, 0xFF },
        },
    },
};

static unk_D_86A02750 D_86A02750[] = {
    {
        0,
        { &D_86A05B60, &D_86A05B64 },
    },
    {
        1,
        { &D_86A05B68, &D_86A05B6C },
    },
    {
        0,
        { &D_86A05B70, &D_86A05B74 },
    },
    {
        1,
        { &D_86A05B78, &D_86A05B7C },
    },
    {
        0,
        { &D_86A05B80, &D_86A05B84 },
    },
    {
        1,
        { &D_86A05B88, &D_86A05B8C },
    },
    {
        0,
        { &D_86A05B90, &D_86A05B94 },
    },
    {
        1,
        { &D_86A05B98, &D_86A05B9C },
    },
    {
        0,
        { &D_86A05BA0, &D_86A05BA4 },
    },
    {
        1,
        { &D_86A05BA8, &D_86A05BAC },
    },
    {
        0,
        { &D_86A05BB0, &D_86A05BB4 },
    },
    {
        1,
        { &D_86A05BB8, &D_86A05BBC },
    },
    {
        0,
        { &D_86A05BC0, &D_86A05BC4 },
    },
    {
        1,
        { &D_86A05BC8, &D_86A05BCC },
    },
    {
        0,
        { &D_86A05BD0, &D_86A05BD4 },
    },
    {
        1,
        { &D_86A05BD8, &D_86A05BDC },
    },
    {
        0,
        { &D_86A05BE0, &D_86A05BE4 },
    },
    {
        1,
        { &D_86A05BE8, &D_86A05BEC },
    },
    {
        1,
        { &D_86A05BF0, &D_86A05BF4 },
    },
    {
        1,
        { &D_86A05BF8, &D_86A05BFC },
    },
    {
        0,
        { &D_86A05C00, &D_86A05C04 },
    },
    {
        1,
        { &D_86A05C08, &D_86A05C0C },
    },
    {
        0,
        { &D_86A05C10, &D_86A05C14 },
    },
    {
        1,
        { &D_86A05C18, &D_86A05C1C },
    },
    {
        0,
        { &D_86A05C20, &D_86A05C24 },
    },
    {
        1,
        { &D_86A05C28, &D_86A05C2C },
    },
    {
        0,
        { &D_86A05C30, &D_86A05C34 },
    },
    {
        1,
        { &D_86A05C38, &D_86A05C3C },
    },
    {
        1,
        { &D_86A05C40, &D_86A05C44 },
    },
    {
        1,
        { &D_86A05C48, &D_86A05C4C },
    },
    {
        1,
        { &D_86A05C50, &D_86A05C54 },
    },
    {
        1,
        { &D_86A05C58, &D_86A05C5C },
    },
    {
        0,
        { &D_86A05C60, &D_86A05C64 },
    },
    {
        1,
        { &D_86A05C68, &D_86A05C6C },
    },
    {
        1,
        { &D_86A05C70, &D_86A05C74 },
    },
    {
        1,
        { &D_86A05C78, &D_86A05C7C },
    },
    {
        1,
        { &D_86A05C80, &D_86A05C84 },
    },
    {
        0,
        { &D_86A05C88, &D_86A05C8C },
    },
    {
        1,
        { &D_86A05C90, &D_86A05C94 },
    },
    {
        1,
        { &D_86A05C98, &D_86A05C9C },
    },
    {
        0,
        { &D_86A05CA0, &D_86A05CA4 },
    },
    {
        1,
        { &D_86A05CA8, &D_86A05CAC },
    },
    {
        1,
        { &D_86A05CB0, &D_86A05CB4 },
    },
    {
        1,
        { &D_86A05CB8, &D_86A05CBC },
    },
    {
        1,
        { &D_86A05CC0, &D_86A05CC4 },
    },
    {
        1,
        { &D_86A05CC8, &D_86A05CCC },
    },
    {
        1,
        { &D_86A05CD0, &D_86A05CD4 },
    },
    {
        1,
        { &D_86A05CD8, &D_86A05CDC },
    },
    {
        1,
        { &D_86A05CE0, &D_86A05CE4 },
    },
    {
        0,
        { &D_86A05CE8, &D_86A05CEC },
    },
    {
        1,
        { &D_86A05CF0, &D_86A05CF4 },
    },
    {
        1,
        { &D_86A05CF8, &D_86A05CFC },
    },
    {
        1,
        { &D_86A05D00, &D_86A05D04 },
    },
    {
        1,
        { &D_86A05D08, &D_86A05D0C },
    },
    {
        1,
        { &D_86A05D10, &D_86A05D14 },
    },
    {
        1,
        { &D_86A05D18, &D_86A05D1C },
    },
    {
        1,
        { &D_86A05D20, &D_86A05D24 },
    },
    {
        1,
        { &D_86A05D28, &D_86A05D2C },
    },
    {
        0,
        { &D_86A05D30, &D_86A05D34 },
    },
    {
        1,
        { &D_86A05D38, &D_86A05D3C },
    },
    {
        1,
        { &D_86A05D40, &D_86A05D44 },
    },
    {
        1,
        { &D_86A05D48, &D_86A05D4C },
    },
    {
        1,
        { &D_86A05D50, &D_86A05D54 },
    },
    {
        1,
        { &D_86A05D58, &D_86A05D5C },
    },
    {
        1,
        { &D_86A05D60, &D_86A05D64 },
    },
    {
        1,
        { &D_86A05D68, &D_86A05D6C },
    },
    {
        1,
        { &D_86A05D70, &D_86A05D74 },
    },
    {
        0,
        { &D_86A05D78, &D_86A05D7C },
    },
    {
        1,
        { &D_86A05D80, &D_86A05D84 },
    },
    {
        1,
        { &D_86A05D88, &D_86A05D8C },
    },
    {
        1,
        { &D_86A05D90, &D_86A05D94 },
    },
    {
        1,
        { &D_86A05D98, &D_86A05D9C },
    },
    {
        1,
        { &D_86A05DA0, &D_86A05DA4 },
    },
    {
        1,
        { &D_86A05DA8, &D_86A05DAC },
    },
    {
        1,
        { &D_86A05DB0, &D_86A05DB4 },
    },
    {
        1,
        { &D_86A05DB8, &D_86A05DBC },
    },
    {
        0,
        { &D_86A05DC0, &D_86A05DC4 },
    },
    {
        1,
        { &D_86A05DC8, &D_86A05DCC },
    },
    {
        1,
        { &D_86A05DD0, &D_86A05DD4 },
    },
    {
        1,
        { &D_86A05DD8, &D_86A05DDC },
    },
    {
        1,
        { &D_86A05DE0, &D_86A05DE4 },
    },
    {
        1,
        { &D_86A05DE8, &D_86A05DEC },
    },
    {
        1,
        { &D_86A05DF0, &D_86A05DF4 },
    },
    {
        1,
        { &D_86A05DF8, &D_86A05DFC },
    },
    {
        1,
        { &D_86A05E00, &D_86A05E04 },
    },
    {
        0,
        { &D_86A05E08, &D_86A05E0C },
    },
    {
        1,
        { &D_86A05E10, &D_86A05E14 },
    },
    {
        1,
        { &D_86A05E18, &D_86A05E1C },
    },
    {
        1,
        { &D_86A05E20, &D_86A05E24 },
    },
    {
        0,
        { &D_86A05E28, &D_86A05E2C },
    },
    {
        1,
        { &D_86A05E30, &D_86A05E34 },
    },
    {
        0,
        { &D_86A05E38, &D_86A05E3C },
    },
    {
        1,
        { &D_86A05E40, &D_86A05E44 },
    },
    {
        1,
        { &D_86A05E48, &D_86A05E4C },
    },
    {
        0,
        { &D_86A05E50, &D_86A05E54 },
    },
    {
        1,
        { &D_86A05E58, &D_86A05E5C },
    },
    {
        0,
        { &D_86A05E60, &D_86A05E64 },
    },
    {
        1,
        { &D_86A05E68, &D_86A05E6C },
    },
    {
        1,
        { &D_86A05E70, &D_86A05E74 },
    },
    {
        0,
        { &D_86A05E78, &D_86A05E7C },
    },
    {
        1,
        { &D_86A05E80, &D_86A05E84 },
    },
    {
        0,
        { &D_86A05E88, &D_86A05E8C },
    },
    {
        1,
        { &D_86A05E90, &D_86A05E94 },
    },
    {
        1,
        { &D_86A05E98, &D_86A05E9C },
    },
    {
        0,
        { &D_86A05EA0, &D_86A05EA4 },
    },
    {
        1,
        { &D_86A05EA8, &D_86A05EAC },
    },
    {
        1,
        { &D_86A05EB0, &D_86A05EB4 },
    },
    {
        1,
        { &D_86A05EB8, &D_86A05EBC },
    },
    {
        0,
        { &D_86A05EC0, &D_86A05EC4 },
    },
    {
        1,
        { &D_86A05EC8, &D_86A05ECC },
    },
    {
        0,
        { &D_86A05ED0, &D_86A05ED4 },
    },
    {
        1,
        { &D_86A05ED8, &D_86A05EDC },
    },
    {
        0,
        { &D_86A05EE0, &D_86A05EE4 },
    },
    {
        1,
        { &D_86A05EE8, &D_86A05EEC },
    },
    {
        1,
        { &D_86A05EF0, &D_86A05EF4 },
    },
    {
        0,
        { &D_86A05EF8, &D_86A05EFC },
    },
    {
        1,
        { &D_86A05F00, &D_86A05F04 },
    },
    {
        1,
        { &D_86A05F08, &D_86A05F0C },
    },
    {
        1,
        { &D_86A05F10, &D_86A05F14 },
    },
    {
        1,
        { &D_86A05F18, &D_86A05F1C },
    },
    {
        1,
        { &D_86A05F20, &D_86A05F24 },
    },
    {
        0,
        { &D_86A05F28, &D_86A05F2C },
    },
    {
        1,
        { &D_86A05F30, &D_86A05F34 },
    },
    {
        1,
        { &D_86A05F38, &D_86A05F3C },
    },
    {
        1,
        { &D_86A05F40, &D_86A05F44 },
    },
    {
        1,
        { &D_86A05F48, &D_86A05F4C },
    },
    {
        2,
        { &D_86A05F50, &D_86A05F54 },
    },
    {
        1,
        { &D_86A05F58, &D_86A05F5C },
    },
    {
        1,
        { &D_86A05F60, &D_86A05F64 },
    },
    {
        1,
        { &D_86A05F68, &D_86A05F6C },
    },
    {
        0,
        { &D_86A05F70, &D_86A05F74 },
    },
    {
        1,
        { &D_86A05F78, &D_86A05F7C },
    },
    {
        1,
        { &D_86A05F80, &D_86A05F84 },
    },
    {
        1,
        { &D_86A05F88, &D_86A05F8C },
    },
    {
        1,
        { &D_86A05F90, &D_86A05F94 },
    },
    {
        1,
        { &D_86A05F98, &D_86A05F9C },
    },
    {
        1,
        { &D_86A05FA0, &D_86A05FA4 },
    },
    {
        0,
        { &D_86A05FA8, &D_86A05FAC },
    },
    {
        1,
        { &D_86A05FB0, &D_86A05FB4 },
    },
    {
        0,
        { &D_86A05FB8, &D_86A05FBC },
    },
    {
        1,
        { &D_86A05FC0, &D_86A05FC4 },
    },
    {
        0,
        { &D_86A05FC8, &D_86A05FCC },
    },
    {
        1,
        { &D_86A05FD0, &D_86A05FD4 },
    },
    {
        1,
        { &D_86A05FD8, &D_86A05FDC },
    },
    {
        1,
        { &D_86A05FE0, &D_86A05FE4 },
    },
    {
        1,
        { &D_86A05FE8, &D_86A05FEC },
    },
    {
        0,
        { &D_86A05FF0, &D_86A05FF4 },
    },
    {
        1,
        { &D_86A05FF8, &D_86A05FFC },
    },
    {
        1,
        { &D_86A06000, &D_86A06004 },
    },
    {
        1,
        { &D_86A06008, &D_86A0600C },
    },
    {
        1,
        { &D_86A06010, &D_86A06014 },
    },
    {
        0,
        { &D_86A06018, &D_86A0601C },
    },
    {
        1,
        { &D_86A06020, &D_86A06024 },
    },
    {
        1,
        { &D_86A06028, &D_86A0602C },
    },
    {
        1,
        { &D_86A06030, &D_86A06034 },
    },
    {
        2,
        { &D_86A06038, &D_86A0603C },
    },
    {
        1,
        { &D_86A06040, &D_86A06044 },
    },
    {
        1,
        { &D_86A06048, &D_86A0604C },
    },
    {
        1,
        { &D_86A06050, &D_86A06054 },
    },
    {
        1,
        { &D_86A06058, &D_86A0605C },
    },
    {
        1,
        { &D_86A06060, &D_86A06064 },
    },
    {
        1,
        { &D_86A06068, &D_86A0606C },
    },
    {
        0,
        { &D_86A06070, &D_86A06074 },
    },
    {
        1,
        { &D_86A06078, &D_86A0607C },
    },
    {
        1,
        { &D_86A06080, &D_86A06084 },
    },
    {
        1,
        { &D_86A06088, &D_86A0608C },
    },
    {
        1,
        { &D_86A06090, &D_86A06094 },
    },
    {
        1,
        { &D_86A06098, &D_86A0609C },
    },
    {
        0,
        { &D_86A060A0, &D_86A060A4 },
    },
    {
        1,
        { &D_86A060A8, &D_86A060AC },
    },
    {
        1,
        { &D_86A060B0, &D_86A060B4 },
    },
    {
        0,
        { &D_86A060B8, &D_86A060BC },
    },
    {
        1,
        { &D_86A060C0, &D_86A060C4 },
    },
    {
        0,
        { &D_86A060C8, &D_86A060CC },
    },
    {
        1,
        { &D_86A060D0, &D_86A060D4 },
    },
    {
        1,
        { &D_86A060D8, &D_86A060DC },
    },
    {
        1,
        { &D_86A060E0, &D_86A060E4 },
    },
    {
        0,
        { &D_86A060E8, &D_86A060EC },
    },
    {
        1,
        { &D_86A060F0, &D_86A060F4 },
    },
    {
        1,
        { &D_86A060F8, &D_86A060FC },
    },
    {
        0,
        { &D_86A06100, &D_86A06104 },
    },
    {
        1,
        { &D_86A06108, &D_86A0610C },
    },
    {
        1,
        { &D_86A06110, &D_86A06114 },
    },
    {
        1,
        { &D_86A06118, &D_86A0611C },
    },
    {
        1,
        { &D_86A06120, &D_86A06124 },
    },
    {
        0,
        { &D_86A06128, &D_86A0612C },
    },
    {
        1,
        { &D_86A06130, &D_86A06134 },
    },
};

unk_D_86A03014 D_86A03014[29] = {
    {
        0,
        360,
        40,
        6,
        D_86A02750,
    },
    {
        0,
        360,
        40,
        6,
        NULL,
    },
    {
        0,
        368,
        48,
        8,
        NULL,
    },
    {
        0,
        352,
        40,
        6,
        NULL,
    },
    {
        0,
        360,
        40,
        6,
        NULL,
    },
    {
        0,
        368,
        48,
        5,
        NULL,
    },
    {
        0,
        352,
        40,
        3,
        NULL,
    },
    {
        0,
        360,
        40,
        9,
        NULL,
    },
    {
        0,
        368,
        48,
        9,
        NULL,
    },
    {
        0,
        352,
        40,
        9,
        NULL,
    },
    {
        0,
        360,
        40,
        9,
        NULL,
    },
    {
        0,
        368,
        48,
        9,
        NULL,
    },
    {
        0,
        232,
        40,
        4,
        NULL,
    },
    {
        0,
        240,
        40,
        5,
        NULL,
    },
    {
        0,
        240,
        40,
        5,
        NULL,
    },
    {
        0,
        368,
        48,
        9,
        NULL,
    },
    {
        0,
        352,
        40,
        7,
        NULL,
    },
    {
        0,
        360,
        40,
        6,
        NULL,
    },
    {
        0,
        368,
        48,
        9,
        NULL,
    },
    {
        0,
        352,
        40,
        9,
        NULL,
    },
    {
        0,
        240,
        40,
        2,
        NULL,
    },
    {
        0,
        360,
        40,
        10,
        NULL,
    },
    {
        0,
        368,
        48,
        11,
        NULL,
    },
    {
        0,
        352,
        40,
        9,
        NULL,
    },
    {
        0,
        360,
        40,
        9,
        NULL,
    },
    {
        0,
        360,
        40,
        5,
        NULL,
    },
    {
        0,
        240,
        40,
        2,
        NULL,
    },
    {
        0,
        0,
        40,
        0,
        NULL,
    },
    {
        0,
        0,
        0,
        0,
        NULL,
    },
};

void func_86A00C90(void) {
    u8 i;

    func_8004FC60(1, 0x78);
    func_8004FC60(2, 0x78);
    func_80006CB4(0x78);

    for (i = 0; i < 120; i++) {
        func_86A00434();
        func_86A00788(2);
    }

    func_800077B4(0x3C);
}

void func_86A00D00(void) {
    D_86A061E8 = D_86A061E4->unk_0C;
    D_86A061EC = 0x100;
    D_86A061EE = 0;
    D_86A061F0 = 0x78;

    D_86A061E8->unk_24.near = 50.0f;
    D_86A061E8->unk_24.far = 6400.0f;
    func_80010354(&D_86A061E8->unk_60.at, &D_86A061E8->unk_60.eye, D_86A061F0, D_86A061EC, D_86A061EE);
}

void func_86A00DAC(s32 arg0) {
    MemoryBlock* sp2C;
    MemoryBlock* temp_v0;

    D_86A061DC = ASSET_LOAD2(stadium_models, 1, 1);
    func_800113F8(0, &D_86A06170, 0x3C0, 0x3E8, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001103C(NULL, &D_86A06190);
    func_8001103C(NULL, &D_86A061A8);
    func_8001103C(NULL, &D_86A061C0);
    func_86A0003C(0xFF, 0xFF, 0xFF);
    sp2C = func_80002D10(main_pool_get_available(), 0);
    D_86A061E4 = process_geo_layout(sp2C, &D_86A025D0);
    func_80002D60(sp2C);
    func_8001BB20();
    func_86A00D00();
    func_86A013C8(1, arg0, D_86A03014);
    D_86A061D8 = -1;

    main_pool_push_state('BACK');
}

s32 func_86A00ED8(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('ROLE');

    func_80005E40(0x10000, 0);
    sp24 = func_80007444(0, 1, 3, 1, 1, 1);
    D_86A06200 = func_8001E94C(4, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, kids_club_game_ui, 0);
    FRAGMENT_LOAD(fragment31);

    func_86A00DAC(arg1);
    func_80007678(sp24);
    func_86A00840();
    func_86A0092C(arg1);
    func_86A00C90();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('ROLE');

    return 0;
}

s32 func_86A01020(Color_RGBA8_u32* arg0, u16 arg1, u16 arg2, u8 arg3) {
    u8 i;
    u8 j;
    u8 temp_fv1;

    if (arg1 >= (arg2 - arg3)) {
        return 0;
    }

    D_86A02700[3].unk_00 = (arg2 - arg3) - 0x15;
    D_86A02700[4].unk_00 = (arg2 - arg3) - 1;

    for (i = 0; i < 5; i++) {
        if (arg1 == D_86A02700[i].unk_00) {
            for (j = 0; j < 4; j++) {
                func_8000E840(&arg0[j], D_86A02700[i].unk_03[j].r, D_86A02700[i].unk_03[j].g, D_86A02700[i].unk_03[j].b,
                              D_86A02700[i].unk_02);
            }
            break;
        }

        if ((D_86A02700[i].unk_00 < arg1) && (arg1 < D_86A02700[i + 1].unk_00)) {
            temp_fv1 =
                (s32)ROUND_MAX((((D_86A02700[i + 1].unk_02 - D_86A02700[i].unk_02) * (arg1 - D_86A02700[i].unk_00)) /
                                (f32)(D_86A02700[i + 1].unk_00 - D_86A02700[i].unk_00)) +
                               D_86A02700[i].unk_02);

            for (j = 0; j < 4; j++) {
                arg0[j].r = (s32)ROUND_MAX(
                    (((D_86A02700[i + 1].unk_03[j].r - D_86A02700[i].unk_03[j].r) * (arg1 - D_86A02700[i].unk_00)) /
                     (f32)(D_86A02700[i + 1].unk_00 - D_86A02700[i].unk_00)) +
                    D_86A02700[i].unk_03[j].r);
                arg0[j].g = (s32)ROUND_MAX(
                    (((D_86A02700[i + 1].unk_03[j].g - D_86A02700[i].unk_03[j].g) * (arg1 - D_86A02700[i].unk_00)) /
                     (f32)(D_86A02700[i + 1].unk_00 - D_86A02700[i].unk_00)) +
                    D_86A02700[i].unk_03[j].g);
                arg0[j].b = (s32)ROUND_MAX(
                    (((D_86A02700[i + 1].unk_03[j].b - D_86A02700[i].unk_03[j].b) * (arg1 - D_86A02700[i].unk_00)) /
                     (f32)(D_86A02700[i + 1].unk_00 - D_86A02700[i].unk_00)) +
                    D_86A02700[i].unk_03[j].b);
                arg0[j].a = temp_fv1;
            }

            break;
        }
    }
    return 1;
}

#ifdef NON_MATCHING
// Needs the in-fucntion static but that breaks bss ordering
void func_86A013C8(u8 arg0, u8 arg1, unk_D_86A03014* arg2) {
    static char** D_86A06218;

    u16 i;
    u16 sp2C;
    unk_D_86A02750* ptr;

    sp2C = func_86A018C0();
    func_8002D510();
    D_86A06218 = func_8002D5AC(0x2D);

    for (i = 0, ptr = D_86A02750; i < sp2C; i++, ptr++) {
        ptr->unk_04[0] = func_8002D7C0(NULL, 0, D_86A06218, i);
    }

    D_86A06210 = arg0;
    D_86A06211 = 0;
    D_86A06212 = 0;
    D_86A06214 = arg2;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/16/fragment16_158A00/func_86A013C8.s")
#endif

#ifdef NON_MATCHING
void func_86A01490(void) {
    static u32 D_86A0621C;

    s32 temp_v0 = D_800A6CF4.unk_20;

    if (D_86A06212 == 0) {
        D_86A06212 = 1;
    } else if (D_86A0621C < temp_v0) {
        D_86A06210 = temp_v0 - D_86A0621C;
    } else {
        D_86A06210 = temp_v0 - D_86A0621C;
    }
    D_86A0621C = temp_v0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/16/fragment16_158A00/func_86A01490.s")
#endif

void func_86A014F0(void) {
    u8 var_a1;
    u8 var_s0;
    u8 var_s1;
    u8 i;
    s32 var_s5;
    Color_RGBA8_u32 sp60[4];
    u16 var_s11;
    unk_D_86A02750* ptr;
    unk_D_86A03014 sp4C;

    if (D_86A06214 == NULL) {
        func_86A0240C(1);
        return;
    }

    var_s0 = 0;
    var_s1 = 0;

    if (func_86A01020(sp60, D_86A06214->unk_00, D_86A06214->unk_02, D_86A06214->unk_04) != 0) {
        func_8001F3F4();
        func_8001F470();
        func_8001EBE0(4, 0);

        var_s5 = 0;

        func_8001F324(sp60[0].r, sp60[0].g, sp60[0].b, sp60[0].a);
        func_8001F36C(sp60[1].r, sp60[1].g, sp60[1].b, sp60[1].a);

        ptr = D_86A06214->unk_08;
        for (i = 0; i < D_86A06214->unk_05; i++, ptr++) {
            switch (ptr->unk_00) {
                case 0:
                    var_s0++;
                    break;

                case 2:
                    var_s1++;
                    break;
            }
        }

        if (var_s0 >= 2) {
            var_a1 = ((var_s0 * 4) + (var_s0 * 0xC) + (var_s1 * 0xA)) - 0xC;
        } else {
            var_a1 = (var_s0 * 4) + (var_s1 * 0xA);
        }

        var_s11 = (((-((D_86A06214->unk_05 - var_s1) * 0x11) - var_a1) + 0xF0) / 2) & 0xFFFF;

        for (i = 0, ptr = D_86A06214->unk_08; i < D_86A06214->unk_05; i++, ptr++) {
            if (ptr->unk_00 == 2) {
                var_s11 += 0xA;
                continue;
            }

            if (var_s5 != ptr->unk_00) {
                switch (ptr->unk_00) {
                    case 0:
                        func_8001F324(sp60[0].r, sp60[0].g, sp60[0].b, sp60[0].a);
                        func_8001F36C(sp60[1].r, sp60[1].g, sp60[1].b, sp60[1].a);
                        var_s5 = 0;
                        var_s11 += 0xC;
                        break;

                    case 1:
                        func_8001F324(sp60[2].r, sp60[2].g, sp60[2].b, sp60[2].a);
                        func_8001F36C(sp60[3].r, sp60[3].g, sp60[3].b, sp60[3].a);
                        var_s5 = 1;
                        var_s11 += 4;
                        break;
                }
            }

            func_8001F1E8(0xA0 - (func_8001F5B0(0, 0, ptr->unk_04[D_86A06211]) / 2), (var_s11 * 4) >> 2,
                          ptr->unk_04[D_86A06211]);
            var_s11 += 0x11;
        }

        func_8001F4C4();
        func_8001F444();
    }

    D_86A06214->unk_00 = D_86A06214->unk_00 + D_86A06210;
    if (D_86A06214->unk_00 >= D_86A06214->unk_02) {
        sp4C = *D_86A06214;

        D_86A06214++;

        D_86A06214->unk_08 = &sp4C.unk_08[sp4C.unk_05];
        if (D_86A06214->unk_02 == 0) {
            D_86A06214 = NULL;
        } else {
            D_86A06214->unk_02 = (D_86A06214->unk_02 - sp4C.unk_00) + sp4C.unk_02;
            D_86A06214->unk_00 = 0;
        }
    }
}
