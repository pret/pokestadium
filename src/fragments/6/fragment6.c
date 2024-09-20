#include "global.h"
#include "src/memory.h"
#include "src/3FB0.h"
#include "src/6A40.h"
#include "src/stage_loader.h"
#include "src/1CF30.h"
#include "src/4BDC0.h"
#include "src/fragments/2/fragment2.h"
#include "src/fragments/4/fragment4.h"
#include "src/fragments/6/fragment6.h"
#include "src/18480.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/32D10.h"
#include "src/49790.h"
#include "src/controller.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/6BC0.h"
#include "src/2E110.h"
#include "src/E890.h"
#include "src/12D80.h"
#include "src/17300.h"

typedef struct unk_D_86002920 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk_D_86002920; // size = 0xC

static unk_D_86002920 D_86002920[31] = {
    { 0x87A0, 0x1190, 0x0032, 0x0028, 0x0005, 0x0000 }, { 0x87A0, 0x1178, 0x004B, 0x0037, 0x0014, 0x0000 },
    { 0x87A0, 0x1180, 0x005C, 0x003C, 0x001E, 0x0000 }, { 0x87A0, 0x11A4, 0x0063, 0x005A, 0x0028, 0x0000 },
    { 0xFFFF, 0xFFE2, 0xFFFF, 0xFFF5, 0x0000, 0x0007 }, { 0x0000, 0x0019, 0x000D, 0x000D, 0x000B, 0x000C },
    { 0x000F, 0x000F, 0x000D, 0x000E, 0x0011, 0x0011 }, { 0x000F, 0x0010, 0x0013, 0x0013, 0x0011, 0x0012 },
    { 0xA5B3, 0xA5A4, 0xA5AD, 0xA5F3, 0xA5B0, 0xA4CE }, { 0xA4CF, 0xA4CD, 0xA4EB, 0xA4C7, 0xA5DD, 0xA5F3 },
    { 0x0000, 0x0000, 0xA1A1, 0xA1A1, 0xA1A1, 0xA1A1 }, { 0xA4C7, 0xA1A1, 0xA5B8, 0xA5E3, 0xA5F3, 0xA5D7 },
    { 0xA4B7, 0xA4C6, 0xA1A1, 0xA4A6, 0xA4A8, 0xA4CE }, { 0xA5AB, 0xA5A6, 0xA5F3, 0xA5BF, 0xA1BC, 0xA4F2 },
    { 0x0000, 0x0000, 0xA4BF, 0xA4AF, 0xA4B5, 0xA4F3 }, { 0xA1A1, 0xA4BF, 0xA4BF, 0xA4A4, 0xA4BF, 0xA4D2 },
    { 0xA4C8, 0xA4AC, 0xA1A1, 0xA4AB, 0xA4C1, 0xA1A3 }, { 0x0000, 0x0000, 0xA1A1, 0xA1A1, 0xA1A1, 0xA1A1 },
    { 0xA4F2, 0xA1A1, 0xA4CA, 0xA4AC, 0xA4AF, 0xA1A1 }, { 0xA4AA, 0xA4B5, 0xA4CA, 0xA4A4, 0xA4C8, 0xA1A1 },
    { 0xA5AB, 0xA5A6, 0xA5F3, 0xA5BF, 0xA1BC, 0xA4DE }, { 0xA4C7, 0x0000, 0xA4C8, 0xA4C9, 0xA4AB, 0xA4CA },
    { 0xA4A4, 0xA4E8, 0xA1A3, 0x0000, 0xA4C1, 0xA4E3 }, { 0xA4AF, 0xA4C1, 0xA4B9, 0xA4EB, 0xA1A1, 0xA5BF },
    { 0xA5A4, 0xA5DF, 0xA5F3, 0xA5B0, 0xA4CB, 0xA4A2 }, { 0xA4EF, 0xA4BB, 0xA4C6, 0xA1A1, 0xA5C6, 0xA5F3 },
    { 0xA5DD, 0xA4E8, 0xA4AF, 0x0000, 0xA5DC, 0xA5BF }, { 0xA5F3, 0xA4F2, 0xA4AA, 0xA4B9, 0xA4CE, 0xA4AC },
    { 0xA1A1, 0xA4B8, 0xA4E7, 0xA4A6, 0xA4BA, 0xA4CB }, { 0xA5B8, 0xA5E3, 0xA5F3, 0xA5D7, 0xA4B9, 0xA4EB },
    { 0xA5B3, 0xA5C4, 0xA4C0, 0xA1A3, 0x0000, 0x0000 },
};

static f32 D_86002A94 = 50.0f;

typedef struct unk_D_86002A98 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk_D_86002A98; // size = 0xC

static unk_D_86002A98 D_86002A98[4] = {
    { 0x0014, 0x00D7, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF },
    { 0x005A, 0x00D7, 0xFFFF, 0xFFFF, 0x00FF, 0x00FF },
    { 0x00A0, 0x00D7, 0xFFFF, 0xFFFF, 0xFF00, 0x00FF },
    { 0x00E6, 0x00D7, 0xFFFF, 0xFFFF, 0xFFFF, 0x00FF },
};

static unk_func_87801684 D_86002AC8[] = {
    {
        0x0303ED80,
        0x000E,
    },
    {
        0x0303F180,
        0x0002,
    },
    {
        0x0303F580,
        0x0006,
    },
    {
        0x0303F180,
        0x0002,
    },
    {
        NULL,
        0x0000,
    },
};

static unk_func_87801684 D_86002AF0[] = {
    {
        0x03040580,
        0x0012,
    },
    {
        0x03040980,
        0x0002,
    },
    {
        0x03040D80,
        0x0008,
    },
    {
        0x03040980,
        0x0002,
    },
    {
        NULL,
        0x0000,
    },
};

static u32 D_86002B18[] = {
    0x0C00FFFF, (u32)&D_5000000,  0x0B00001E,      0x00000000,      0x014000F0,      0x0000000F,
    0x00000000, 0x00000000,       (u32)&D_5000000, 0x0D000000,      (u32)&D_5000000, 0x0F000002,
    0x14000000, 0x002B0012,       0xFFFFFF32,      0x16FFFFFF,      0x0F000003,      (u32)&D_5000000,
    0x0A000000, (u32)&D_800AC840, (u32)&D_6000000, (u32)&D_6000000, (u32)&D_6000000, (u32)&D_3000000,
    0x87806398, (u32)&D_6000000,  (u32)&D_1000000,
};

static unk_D_86002F30* D_86002F30;
static unk_D_86002F34* D_86002F34;
static unk_D_86002F34_00C* D_86002F38;
static s16 D_86002F3C;
static s16 D_86002F3E;
static s16 D_86002F40;
static u16 D_86002F42;
static s16 D_86002F44;
static s32 D_86002F48;
static s16 D_86002F4C;
static s32 D_86002F50;

typedef struct unk_D_86002F58_004 {
    /* 0x000 */ unk_D_86002F58_004_000 unk_000;
    /* 0x168 */ s16 unk_168;
    /* 0x16A */ u16 unk_16A;
    /* 0x16C */ s16 unk_16C;
} unk_D_86002F58_004; // size = 0x170

typedef struct unk_D_86002F58 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ char pad2[2];
    /* 0x004 */ unk_D_86002F58_004 unk_004;
    /* 0x174 */ u16 unk_174;
    /* 0x176 */ u16 unk_176[2];
    /* 0x17A */ u16 unk_17A;
    /* 0x17C */ u16 unk_17C[2];
    /* 0x180 */ char pad180[2];
    /* 0x182 */ s16 unk_182;
    /* 0x184 */ s16 unk_184;
    /* 0x186 */ s16 unk_186;
    /* 0x188 */ s16 unk_188;
    /* 0x18A */ s16 unk_18A;
    /* 0x18C */ s16 unk_18C;
    /* 0x18E */ char pad18E[2];
} unk_D_86002F58; // size = 0x190

static unk_D_86002F58 D_86002F58[4];
static unk_D_86002F58_004 D_86003598[4];
static u32 D_86003B58;
static unk_D_86002F58* D_86003B5C;
static unk_D_86002F58_004* D_86003B60;
static unk_D_86002F58_004* D_86003B64;
static s16 D_86003B68;
static s16 D_86003B6A;
static s16 D_86003B70[4];
static s16 D_86003B78;
static unk_D_800AC870* D_86003B7C;
static s32 D_86003B80;
static unk_D_86002F58_004_000 D_86003B84[4];

void func_86000020(void) {
    s32 i;
    s32 j;

    D_86002F58[0].unk_17A = D_80068BA0->unk_08;
    D_86002F58[1].unk_17A = D_80068BA4->unk_08;
    D_86002F58[2].unk_17A = D_80068BA8->unk_08;
    D_86002F58[3].unk_17A = D_80068BAC->unk_08;

    D_86002F58[0].unk_174 = D_80068BA0->unk_06;
    D_86002F58[1].unk_174 = D_80068BA4->unk_06;
    D_86002F58[2].unk_174 = D_80068BA8->unk_06;
    D_86002F58[3].unk_174 = D_80068BAC->unk_06;

    for (i = 0; i < 4; i++) {
        D_86003B5C = &D_86002F58[i];

        if (D_86003B5C->unk_000 == 0) {
            s32 temp = D_86002F48;

            if ((temp != 0) && (temp != 2) && (temp != 3) && (temp != 5)) {
                D_86003B5C->unk_174 = 0;
                D_86003B5C->unk_17A = 0;
            }
        } else if (D_86002F48 == 2) {
            switch (D_86003B5C->unk_004.unk_168) {
                case 0:
                case 12:
                case 13:
                    if (func_878001E8(0x64) < D_86002920[D_8780FA38].unk_06) {
                        D_86003B5C->unk_17A = 0x8000;
                    }
                    break;

                case 5:
                case 7:
                    if (func_878001E8(0x64) < D_86002920[D_8780FA38].unk_04) {
                        D_86003B5C->unk_174 = 0x8000;
                    }
                    break;

                case 8:
                    if ((D_86003B5C->unk_004.unk_000.unk_040.unk_08 > 0x90000) &&
                        (func_878001E8(0x64) < D_86002920[D_8780FA38].unk_08)) {
                        D_86003B5C->unk_17A = 0x8000;
                    }
                    break;

                case 9:
                    if ((D_86003B5C->unk_004.unk_000.unk_040.unk_08 > 0xD0000) &&
                        (func_878001E8(0x64) < D_86002920[D_8780FA38].unk_08)) {
                        D_86003B5C->unk_17A = 0x8000;
                    }
                    break;

                case 10:
                    if ((D_86003B5C->unk_004.unk_000.unk_040.unk_08 > 0xB0000) &&
                        (func_878001E8(0x64) < D_86002920[D_8780FA38].unk_08)) {
                        D_86003B5C->unk_17A = 0x8000;
                    }
                    break;

                case 11:
                    if ((D_86003B5C->unk_004.unk_000.unk_040.unk_08 > 0xF0000) &&
                        (func_878001E8(0x64) < D_86002920[D_8780FA38].unk_08)) {
                        D_86003B5C->unk_17A = 0x8000;
                    }
                    break;
            }
        }
    }

    if (D_86002F48 == 2) {
        for (j = 0; j < 4; j++) {
            D_86003B5C = &D_86002F58[j];

            for (i = 1; i > 0; i--) {
                D_86003B5C->unk_176[i] = D_86003B5C->unk_176[i - 1];
                D_86003B5C->unk_17C[i] = D_86003B5C->unk_17C[i - 1];
            }
            D_86003B5C->unk_176[0] = D_86003B5C->unk_174;
            D_86003B5C->unk_17C[0] = D_86003B5C->unk_17A;
        }
    } else {
        for (j = 0; j < 4; j++) {
            D_86003B5C = &D_86002F58[j];

            for (i = 0; i < 2; i++) {
                D_86003B5C->unk_176[i] = 0;
                D_86003B5C->unk_17C[i] = 0;
            }
        }
    }
}

s32 func_86000410(void) {
    if (func_80007604() != 0) {
        return -1;
    }

    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();

    if (D_8780FC94 != 1) {
        func_86000020();
    }

    return 0;
}

void func_86000478(void) {
    D_86002F38 = D_86002F34->unk_00.unk_0C;
    func_87A00020(D_86002F38);
    D_86002F3C = 0x600;
    D_86002F3E = 0;
    D_86002F40 = 1000;

    D_86002F38->unk_24.near = 100.0f;
    D_86002F38->unk_24.far = 12800.0f;
    D_86002F38->unk_24.fovy = 10.0f;

    D_86002F38->unk_60.at.x = 0.0f;
    D_86002F38->unk_60.at.y = 70.0f;
    D_86002F38->unk_60.at.z = 0.0f;

    func_80010354(&D_86002F38->unk_60.at, &D_86002F38->unk_60.eye, D_86002F40, D_86002F3C, D_86002F3E);
}

void func_86000564(void) {
    func_80010354(&D_86002F38->unk_60.at, &D_86002F38->unk_60.eye, D_86002F40, D_86002F3C, D_86002F3E);
}

#ifdef NON_MATCHING
void func_860005B8(s32 arg0) {
    s32 i;
    UNUSED u8 sp68[] = {
        0,
        0,
        30,
    };
    UNUSED u8 sp64[] = {
        0,
        0,
        150,
    };

    if (arg0 != 0) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_86002F4C);

        for (i = 0; i < 4; i++) {
            unk_D_86002A98* tmp = &D_86002A98[i];

            if (D_86002F58[i].unk_000 == 0) {
                func_87801644(i, tmp->unk_00, tmp->unk_02, 0.75f);
            } else {
                func_87801644(-1 - i, tmp->unk_00, tmp->unk_02, 0.75f);
            }
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }

    if (arg0 == 0) {
        func_80020460(0x18, 0x16, 0x110, 0x90, 0x15);
        func_80020460(0x18, 0xA5, 0x110, 0x36, 0x14B);
    }

    func_8001F3F4();

    switch (arg0) {
        s32 sp50;
        s32 sp4C;
        char* temp_s0_2;

        case 1:
        case 2:
        case 3:
            break;

        case 0:
            func_8001F470();
            func_8001EBE0(2, 0);
            func_8001F3B4(0xC);
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F36C(0xF9, 0xF4, 0, 0xFF);
            func_8001F1E8(0xA0 - (func_878013D4(D_86003B7C, func_8002D7C0(NULL, 0, D_87806330, 0x15)) / 2), 0x20,
                          func_8002D7C0(NULL, 0, D_87806330, 0x15));
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F36C(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F1E8(0x28, 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x16));
            func_8001F1E8(0x28, 0x58, func_8002D7C0(NULL, 0, D_87806330, 0x17));
            func_8001F1E8(0x28, 0x7C, func_8002D7C0(NULL, 0, D_87806330, 0x18));
            func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
            func_8001F36C(0x50, 0x50, 0xFF, 0xFF);

            temp_s0_2 = func_8002D7C0(NULL, 0, D_87806330, 0x5F);

            func_87801290(&sp50, &sp4C, func_8002D7C0(NULL, 0, D_87806330, 0x16), temp_s0_2, 0xC);
            if (sp50 >= 0) {
                func_8001F1E8(sp50 + 0x28, sp4C + 0x34, temp_s0_2);
            }

            func_87801290(&sp50, &sp4C, func_8002D7C0(NULL, 0, D_87806330, 0x17), temp_s0_2, 0xC);
            if (sp50 >= 0) {
                func_8001F1E8(sp50 + 0x28, sp4C + 0x58, temp_s0_2);
            }

            func_87801290(&sp50, &sp4C, func_8002D7C0(NULL, 0, D_87806330, 0x18), temp_s0_2, 0xC);
            if (sp50 >= 0) {
                func_8001F1E8(sp50 + 0x28, sp4C + 0x7C, temp_s0_2);
            }

            func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
            func_8001F36C(0x50, 0x50, 0xFF, 0xFF);
            func_8001F1E8(0xA2, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x19));
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F36C(0xFF, 0x80, 0x80, 0xFF);
            func_8001F1E8(0xA2, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x14));
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F36C(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F1E8(0x8B, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
            func_8001F1E8(0x8B, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
            func_8001F4C4();
            break;

        case 4:
            func_8001F470();
            func_8001EBE0(0x20, -2);
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F36C(0x1E, 0x1E, 0xFF, 0xFF);
            func_8001F1E8(0xA0 - (func_878013D4(D_86003B7C, func_8002D7C0(NULL, 0, D_87806330, 0x5A)) / 2), 0x64,
                          func_8002D7C0(NULL, 0, D_87806330, 0x5A));
            func_8001F4C4();
            break;
    }

    func_8001F444();

    if (arg0 == 0) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);
        func_87801684(0x74, 0xB0, D_86002AC8);
        func_87801824(0x74, 0xC6, D_86002AF0);
        func_87801F48(2, 0x19, 0xA6);
    }
}
#else
static u8 D_86002B84[] = {
    0,
    0,
    30,
};
static u8 D_86002B88[] = {
    0,
    0,
    150,
};
void func_860005B8(s32 arg0);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/6/fragment6/func_860005B8.s")
#endif

static Gfx D_86002B90[] = {
    gsSPEndDisplayList(),
};

static u32 D_86002B98[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000A000F, 0x00140014, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000A, 0x00190021, 0x002A0033, 0x0036003B, 0x00000000, 0x00000000,
    0x00000000, 0x0000000A, 0x0019002A, 0x003B004B, 0x00550060, 0x00640067, 0x00000000, 0x00000000, 0x00000000,
    0x00140025, 0x003B0052, 0x00670076, 0x0082008B, 0x00900094, 0x00000000, 0x00000000, 0x00000014, 0x002F0046,
    0x00600079, 0x008D009F, 0x00A900B1, 0x00B600B9, 0x00000000, 0x00000000, 0x00140033, 0x0052006D, 0x0088009F,
    0x00B100C1, 0x00CA00D1, 0x00D400D6, 0x00000000, 0x00000014, 0x002F0052, 0x0071008D, 0x00A900BE, 0x00CF00D9,
    0x00E200E6, 0x00EA00EA, 0x00000000, 0x000A0025, 0x0046006D, 0x008D00AD, 0x00C400D6, 0x00E300EC, 0x00F100F4,
    0x00F600F7, 0x00000000, 0x0019003B, 0x00600088, 0x00A900C4, 0x00D900E6, 0x00F000F6, 0x00F900FB, 0x00FC00FC,
    0x0000000A, 0x002A0052, 0x0079009F, 0x00BE00D6, 0x00E600F2, 0x00F800FC, 0x00FD00FE, 0x00FE00FE, 0x00000019,
    0x003B0067, 0x008D00B1, 0x00CF00E3, 0x00F000F8, 0x00FC00FE, 0x00FE00FF, 0x00FF00FF, 0x00000021, 0x004B0076,
    0x009F00C1, 0x00D900EC, 0x00F600FC, 0x00FE00FE, 0x00FF00FF, 0x00FF00FF, 0x000A002A, 0x00550082, 0x00A900CA,
    0x00E200F1, 0x00F900FD, 0x00FE00FF, 0x00FF00FF, 0x00FF00FF, 0x000F0033, 0x0060008B, 0x00B100D1, 0x00E600F4,
    0x00FB00FE, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00140036, 0x00640090, 0x00B600D4, 0x00EA00F6, 0x00FC00FE,
    0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x0014003B, 0x00670094, 0x00B900D6, 0x00EA00F7, 0x00FC00FE, 0x00FF00FF,
    0x00FF00FF, 0x00FF00FF,
};

static Vtx D_86002D98[] = {
    VTX(-25, 0, -25, 0, 0, 0x00, 0x00, 0x00, 0xFF),
    VTX(-25, 0, 25, 0, 1024, 0x00, 0x00, 0x00, 0xFF),
    VTX(25, 0, 25, 1024, 1024, 0x00, 0x00, 0x00, 0xFF),
    VTX(25, 0, -25, 1024, 0, 0x00, 0x00, 0x00, 0xFF),
};

static Gfx D_86002DD8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_ZBUFFER),
    gsDPSetCombineMode(G_CC_MODULATEIA_PRIM, G_CC_PASS2),
    gsDPSetPrimColor(0, 0, 0, 0, 0, 200),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureBlock(D_86002B98, G_IM_FMT_IA, G_IM_SIZ_16b, 16, 16, 0, G_TX_MIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_86002D98, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

void func_86000C10(void) {
}

void func_86000C18(void) {
    Gfx* gfx = gDisplayListHead;
    Mtx* var_s1 = (Mtx*)func_80005F5C(sizeof(MtxF) * 4);
    Mtx sp100;
    Mtx spC0;
    UNUSED Mtx sp80;
    f32 temp_f20;
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86003B60 = &D_86002F58[i].unk_004;
        temp_f20 = (410.0f - D_86003B60->unk_000.unk_0A8[0].unk_04.y) / 510.0f;
        guTranslate(&sp100, D_86003B60->unk_000.unk_0A8[0].unk_04.x, 0.0f, 0.0f);
        guScale(&spC0, temp_f20, temp_f20, temp_f20);
        guMtxCatL(&spC0, &sp100, var_s1);

        gSPMatrix(gfx++, var_s1, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, D_86002DD8);
        gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
        var_s1++;
    }

    gDisplayListHead = gfx;
}

void func_86000D88(s32 arg0) {
    func_800079C4();
    func_800067E4(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    func_87A00DB8(D_86002F50);

    if (D_8780FC94 != 1) {
        func_80015348();
    }

    func_878025D0();
    func_80015094(D_86002F34);
    gDisplayListHead = func_87A0002C(gDisplayListHead);
    func_86000C18();

    if (D_8780FC98 == 0) {
        func_860005B8(arg0);
    }

    func_87804FD4();
    func_80007778();

    D_86002F42++;
}

void func_86000E54(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86003B60 = D_86003B64 = &D_86003598[i];

        if (D_86003B60->unk_000.unk_024.y > 140.0f) {
            D_86003B60->unk_000.unk_024.y -= 2.0f;
        }

        switch (D_86003B64->unk_16C) {
            case 0:
                if (D_86003B60->unk_000.unk_01E.y < 0x800) {
                    D_86003B60->unk_000.unk_01E.y += 0x400;
                } else {
                    D_86003B64->unk_16C = 1;
                }
                break;

            case 1:
                if (D_86003B60->unk_000.unk_01E.y > 0) {
                    D_86003B60->unk_000.unk_01E.y -= 0x200;
                } else {
                    D_86003B64->unk_16C = 2;
                }
                break;

            case 2:
            default:
                D_86003B60->unk_000.unk_01E.y = 0;
                break;
        }
    }
}

s32 func_86000FD4(void) {
    s32 var_s0_2;
    s32 i;

    func_800077B4(0xA);
    func_80006C6C(0x10);

    for (i = 0; i < 4; i++) {
        D_86003B5C = &D_86002F58[i];
        D_86003B60 = &D_86003B5C->unk_004;
        func_8001BD04(&D_86003B60->unk_000, 0);
        D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
        D_86003B60->unk_000.unk_040.unk_08 = (func_878001E8(0x14) << 0x10);
        D_86003B70[i] = 0;
    }

    for (i = 0; i < 4; i++) {
        D_86003B5C = &D_86002F58[i];
        D_86003B5C->unk_000 = (D_8780FA30[i] == 0) ? 0 : D_8780FA38 + 1;
    }

    D_86002F48 = 0;

    var_s0_2 = true;
    while (var_s0_2 == true) {
        if (func_86000410() == 0) {
            if (D_80068BA0->unk_08 & 0x1000) {
                var_s0_2 = false;
            }

            if ((D_8780FA2A == 0) && (D_80068BA0->unk_08 & 0x4000)) {
                func_80048B90(3);
                func_87802EB8(2);
                return -1;
            }
        }

        func_86000D88(D_86002F48);
    }

    return 0;
}

void func_86001204(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86003B5C = &D_86002F58[i];
        D_86003B60 = &D_86003B5C->unk_004;
        func_8001BD04(&D_86003B60->unk_000, 0);
        D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
        D_86003B60->unk_000.unk_040.unk_08 = func_878001E8(0x14) << 0x10;
        D_86003B70[i] = 0;
    }

    D_86003B68 = 1;
    D_86003B6A = 90;
    func_8780295C(1);
    D_86002F48 = 1;

    while (D_86003B68 == 1) {
        switch (func_87802974()) {
            case 1:
            case 2:
            case 3:
                func_87A010D4(0x20001, 0, 0);
                break;

            case 0:
                D_86003B68 = 0;
                break;
        }

        func_86000E54();
        func_86000410();
        func_86000D88(D_86002F48);
    }
}

void func_86001360(s16 arg0) {
    switch (arg0) {
        case 0:
        case 1:
            func_87A010D4(0x20006, D_86003B5C->unk_18A + 1, 4);
            break;

        case 2:
            func_87A010D4(0x20005, D_86003B5C->unk_18A + 1, 4);
            break;

        default:
            func_87A010D4(0x20004, D_86003B5C->unk_18A + 1, 4);
            break;
    }

    D_86003B5C->unk_004.unk_168 = 5;
    D_86003B5C->unk_004.unk_16A = arg0;

    func_8001BD04(&D_86003B60->unk_000, 8);

    D_86003B60->unk_000.unk_040.unk_08 = 0;
    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
}

void func_86001464(void) {
    D_86003B5C->unk_004.unk_168 = 6;
    func_8001BD04(&D_86003B60->unk_000, 9);
    D_86003B60->unk_000.unk_040.unk_08 = 0;
    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
}

void func_860014B8(void) {
    D_86003B5C->unk_004.unk_168 = 7;
    func_8001BD04(&D_86003B60->unk_000, 0xA);
    D_86003B60->unk_000.unk_040.unk_08 = 0;
    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
}

void func_8600150C(void) {
    D_86003B5C->unk_004.unk_168 = 8;
    func_8001BD04(&D_86003B60->unk_000, 0xB);
    D_86003B60->unk_000.unk_040.unk_08 = 0;
    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
}

void func_86001560(void) {
    D_86003B5C->unk_004.unk_168 = 9;
    func_8001BD04(&D_86003B60->unk_000, 0xC);
    D_86003B60->unk_000.unk_040.unk_08 = 0;
    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
}

void func_860015B4(void) {
    D_86003B5C->unk_004.unk_168 = 0xA;
    func_8001BD04(&D_86003B60->unk_000, 0xD);
    D_86003B60->unk_000.unk_040.unk_08 = 0;
    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
}

void func_86001608(void) {
    D_86003B5C->unk_004.unk_168 = 0xB;
    func_8001BD04(&D_86003B60->unk_000, 0xE);
    D_86003B60->unk_000.unk_040.unk_08 = 0;
    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
}

void func_8600165C(s32 arg0) {
    s32 i;

    D_86003B70[arg0] = 0;

    for (i = 0; i < 2; i++) {
        if (D_86003B5C->unk_17C[i] & 0x8000) {
            func_86001360(i);
            return;
        }
    }

    D_86003B5C->unk_004.unk_168 = 0xC;
    func_8001BD04(&D_86003B60->unk_000, 5);
    D_86003B60->unk_000.unk_040.unk_08 = 0;
    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
}

void func_860016FC(s32 arg0) {
    D_86003B70[arg0] = 0;
    D_86003B5C->unk_004.unk_168 = 0xD;
    func_8001BD04(&D_86003B60->unk_000, 6);
    D_86003B60->unk_000.unk_040.unk_08 = 0;
    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
}

void func_86001760(s32 arg0) {
    D_86003B70[arg0] = 0;
    D_86003B5C->unk_004.unk_168 = 0;
    func_8001BD04(&D_86003B60->unk_000, 0);
    D_86003B60->unk_000.unk_040.unk_08 = 0;
    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
}

void func_860017C0(s32 arg0) {
    D_86003B5C = &D_86002F58[arg0];
    D_86003B64 = &D_86003598[arg0];
    D_86003B60 = &D_86003B5C->unk_004;

    if (D_8780FC94 != 1) {
        switch (D_86003B5C->unk_004.unk_168) {
            case 12:
                if (D_86003B5C->unk_17C[1] & 0x8000) {
                    func_86001360(2);
                } else if (func_80017514(&D_86003B60->unk_000)) {
                    func_860016FC(arg0);
                }
                break;

            case 13:
                if (D_86003B5C->unk_17C[1] & 0x8000) {
                    func_86001360(3);
                } else if (func_80017514(&D_86003B60->unk_000)) {
                    func_86001760(arg0);
                }
                break;

            case 0:
                if (D_86003B5C->unk_17C[1] & 0x8000) {
                    if (D_86003B5C->unk_18C == 1) {
                        func_86001360(2);
                        D_86003B5C->unk_18C = 0;
                    } else {
                        func_86001360(4);
                    }
                }
                break;

            case 5:
                if (func_80017514(&D_86003B60->unk_000)) {
                    if (D_86003B5C->unk_176[1] & 0x8000) {
                        func_860014B8();
                    } else {
                        func_86001464();
                    }
                }
                break;

            case 7:
                if (func_80017514(&D_86003B60->unk_000)) {
                    if (D_86003B5C->unk_176[1] & 0x8000) {
                        s16 tmp = D_86003B5C->unk_004.unk_16A;

                        if (tmp < 2) {
                            func_860015B4();
                        } else if (tmp == 2) {
                            func_86001560();
                        } else {
                            func_86001608();
                        }
                    } else {
                        func_8600150C();
                    }
                }
                break;

            case 6:
            case 8:
            case 9:
            case 10:
            case 11:
                if (func_80017514(&D_86003B60->unk_000)) {
                    func_8600165C(arg0);
                }
                break;

            case 1:
                if (func_80017514(&D_86003B60->unk_000)) {
                    func_8001BD04(&D_86003B60->unk_000, 7);
                    D_86003B60->unk_000.unk_040.unk_08 = 0;
                    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
                }
                break;

            default:
                if (func_80017514(&D_86003B60->unk_000)) {
                    func_8001BD04(&D_86003B60->unk_000, 0);
                    D_86003B60->unk_000.unk_040.unk_08 = 0;
                    D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
                    D_86003B70[arg0] = 0;
                }
                break;
        }

        if (((D_86003B5C->unk_004.unk_168 == 9) && ((D_86003B60->unk_000.unk_040.unk_08 >> 0x10) == 2)) ||
            ((D_86003B5C->unk_004.unk_168 == 10) && ((D_86003B60->unk_000.unk_040.unk_08 >> 0x10) == 2)) ||
            ((D_86003B5C->unk_004.unk_168 == 11) && ((D_86003B60->unk_000.unk_040.unk_08 >> 0x10) == 2))) {
            if (D_86003B70[arg0] == 0) {
                D_86003B64->unk_16A++;
                D_86003B70[arg0] = 1;
                func_8001BD04(&D_86003B64->unk_000, 0);
                D_86003B64->unk_000.unk_040.unk_0C = 0x10000;
                D_86003B64->unk_000.unk_040.unk_08 = 0;
                func_87A010D4(0x20008, arg0, 4);
            }
        }

        if (D_8780FC94 != 1) {
            func_80032244(arg0, D_86003B64->unk_16A);
        }

        if (D_86003B5C->unk_188 > 0) {
            D_86003B5C->unk_188--;
            if (D_86003B5C->unk_188 == 0) {
                func_8001BE34(&D_86003B5C->unk_004.unk_000, 0xFF, 0xFF, 0xFF, 0);
            }
        }
    }
}

void func_86001C90(void) {
    s32 i;
    s32 temp_lo;
    s32 temp_v1;
    s32 var_s6 = 1;

    func_87A010D4(0x20002, 0, 0);

    for (i = 0; i < 4; i++) {
        D_86003B5C = &D_86002F58[i];
        D_86003B60 = &D_86003B5C->unk_004;

        D_86003B5C->unk_004.unk_168 = 0;
        func_8001BD04(&D_86003B60->unk_000, 0);
        D_86003B60->unk_000.unk_040.unk_0C = 0x10000;

        D_86003B70[i] = 0;

        D_86003B5C->unk_18C = 1;
    }

    D_86003B58 = 0;
    D_86003B78 = 0;
    D_86002F48 = 2;

    while (var_s6 != 0) {
        func_86000410();
        func_86000564();

        if (D_86003B58 == 0xF) {
            func_8004B1CC(10);
        }

        if (D_8780FC94 != 1) {
            for (i = 0; i < 4; i++) {
                func_860017C0(i);
            }

            func_86000E54();

            D_86003B58++;
            if (D_86003B58 >= 0x258) {
                func_87A010D4(0x20009, 0, 0);
                var_s6 = 0;
            } else {
                temp_v1 = 0x258 - D_86003B58;
                if ((temp_v1 % 30) == 0) {
                    temp_lo = temp_v1 / 30;
                    if ((temp_lo < 6) && (temp_lo > 0)) {
                        func_87A010D4(0x2000A, 0, 0);
                        if (1) {}
                        if (1) {}
                        if (1) {}
                    }
                }
            }
        }

        if (D_8780FC92 != 0) {
            var_s6 = 0;
        }

        func_86000D88(D_86002F48);
    }

    func_8004B9C4(0xA);
}

s32 func_86001EEC(void) {
    s32 var_v0 = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86003B5C = &D_86002F58[i];
        switch (D_86003B5C->unk_004.unk_168) {
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
                break;

            default:
                var_v0++;
                break;
        }
    }

    if (var_v0 == 4) {
        return 1;
    }

    return 0;
}

void func_86001F64(void) {
    s32 i;
    s32 j;
    s32 var_s1;
    s32 var_s5;

    var_s5 = 1;
    D_86002F48 = 3;
    var_s1 = 1;

    while (var_s1 != 0) {
        func_86000410();
        func_86000564();

        for (i = 0; i < 4; i++) {
            func_860017C0(i);
        }

        if (func_86001EEC() != 0) {
            var_s1 = 0;
        }

        func_86000D88(D_86002F48);

        if (D_8780FC92 != 0) {
            return;
        }
    }

    D_86003B80 = 0;

    for (i = 0; i < 4; i++) {
        if (D_86003598[i].unk_16A >= D_86003B80) {
            D_86003B80 = D_86003598[i].unk_16A;
        }
    }

    D_86002F44 = 0;

    for (i = 0; i < 4; i++) {
        if ((D_86003B80 == D_86003598[i].unk_16A) && (D_86003B80 != 0)) {
            func_87802F00(i);
            D_86002F44++;
        }
    }

    for (i = 0; i < 4; i++) {
        D_86003B5C = &D_86002F58[i];
        D_86003B60 = &D_86003B5C->unk_004;
        if ((D_86003B80 == D_86003598[i].unk_16A) && (D_86003B80 > 0)) {
            D_86003B5C->unk_004.unk_168 = 1;
            func_8001BD04(&D_86003B60->unk_000, 7);
            D_86003B60->unk_000.unk_040.unk_08 = 0;
        } else {
            D_86003B5C->unk_004.unk_168 = 2;
            func_8001BD04(&D_86003B60->unk_000, 0);
            D_86003B60->unk_000.unk_040.unk_08 = func_878001E8(5) << 0x10;
        }
        D_86003B60->unk_000.unk_040.unk_0C = 0x10000;
    }

    j = 30;
    while (j > 0) {
        func_86000410();
        func_86000564();

        for (i = 0; i < 4; i++) {
            func_860017C0(i);
        }

        func_86000D88(D_86002F48);

        if (D_8780FC92 != 0) {
            return;
        }

        if (D_8780FC94 != 1) {
            j -= 1;
        }
    }

    func_87802EB8(1);

    while (var_s5 != 0) {
        func_86000410();
        func_86000564();

        for (i = 0; i < 4; i++) {
            func_860017C0(i);
        }

        for (i = 0; i < 4; i++) {
            D_86003B5C = &D_86002F58[i];
            if (D_86003B5C->unk_17A & 0x8000) {
                var_s5 = 0;
            }
        }

        func_86000D88(D_86002F48);

        if (D_8780FC92 != 0) {
            return;
        }
    }
}

void func_86002264(void) {
    s32 i;
    s32 j;

    func_8004B9C4(30);
    func_80006CB4(30);

    for (i = 0; i < 30; i++) {
        func_86000410();

        for (j = 0; j < 4; j++) {
            func_860017C0(j);
        }

        func_86000D88(D_86002F48);
    }
}

void func_860022F8(s32 arg0) {
    s32 i;

    D_86002F48 = 6;

    for (i = 0; i < arg0; i++) {
        func_86000410();
        func_86000D88(D_86002F48);
    }
}

void func_8600235C(void) {
    s32 i;

    D_86002F48 = 5;

    while (D_8780FC96 == 0) {
        if ((D_8780FA2A == 1) && (D_86002F4C > 0)) {
            D_86002F4C -= 10;
            if (D_86002F4C < 0) {
                D_86002F4C = 0;
            }
        }

        for (i = 0; i < 4; i++) {
            func_860017C0(i);
        }

        func_86000410();
        func_86000D88(D_86002F48);
    }
}

void func_86002440(void) {
    s32 i;
    MemoryBlock* temp_v0;

    temp_v0 = (MemoryBlock*)func_80002D10(main_pool_get_available(), 0);
    D_86002F34 = (unk_D_86002F34*)func_80018B70(temp_v0, D_86002B18);
    func_80002D60(temp_v0);
    func_8001BB20();
    func_8001987C();
    D_86002F4C = 0xFF;
    D_86002F30 = (unk_D_86002F30*)func_80019D18(0xAD);

    for (i = 0; i < 4; i++) {
        D_86003B5C = &D_86002F58[i];
        D_86003B60 = &D_86003B5C->unk_004;

        func_8001BB58(&D_86003B60->unk_000);
        func_8001BC34(&D_86003B60->unk_000, 0, 0xAD, D_86002F30->unk_08->unk_00[0]);

        D_86003B60->unk_000.unk_024.x = (i - 1.5f) * D_86002A94;

        D_86003B60->unk_000.unk_024.y = 0.0f;
        D_86003B60->unk_000.unk_024.z = 0.0f;
        D_86003B60->unk_000.unk_030.x = 0.8f;
        D_86003B60->unk_000.unk_030.y = 0.8f;
        D_86003B60->unk_000.unk_030.z = 0.8f;

        D_86003B5C->unk_182 = 0;
        D_86003B5C->unk_184 = 0;
        D_86003B5C->unk_186 = 0;
        D_86003B5C->unk_188 = 0;
        D_86003B5C->unk_18A = i;

        if (i == 0) {
            D_86003B5C->unk_000 = 0;
        } else {
            D_86003B5C->unk_000 = D_8780FA38 + 1;
        }

        func_8001BD04(&D_86003B60->unk_000, 0);

        D_86003B60->unk_000.unk_040.unk_08 = func_878001E8(5) << 0x10;
        D_86003B60->unk_000.unk_01E.y = -0x2800;
    }

    D_86002F30 = (unk_D_86002F30*)func_80019D18(0xAE);

    for (i = 0; i < 4; i++) {
        D_86003B64 = &D_86003598[i];
        D_86003B60 = D_86003B64;

        func_8001BB58(&D_86003B60->unk_000);
        func_8001BC34(&D_86003B60->unk_000, 0, 0xAE, D_86002F30->unk_08->unk_00[0]);
        D_86003B60->unk_000.unk_024.x = (i - 1.5f) * D_86002A94;
        D_86003B60->unk_000.unk_024.z = 0.0f;
        D_86003B60->unk_000.unk_024.y = 200.0f;
        D_86003B60->unk_000.unk_01E.y = -0x8000;
        D_86003B60->unk_000.unk_030.x = 1.4f;
        D_86003B60->unk_000.unk_030.y = 1.4f;
        D_86003B60->unk_000.unk_030.z = 1.4f;
        D_86003B64->unk_168 = 0;
        D_86003B64->unk_16A = 0;
        D_86003B64->unk_16C = 0;
        func_80032110(i, 0);
        D_86003B64->unk_000.unk_0A6 = i;
        func_8001BD04(&D_86003B60->unk_000, 0);
        func_800173CC(&D_86003B60->unk_000);
    }

    D_86002F50 = func_80004258(0, (void*)&D_124570, (void*)fragment7_ROM_START, 0);
    func_86000478();
    func_87802528();
}

void func_86002778(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('MINI');

    func_80005E40(0x20000, 0);
    sp24 = (unk_func_80007444*)func_80007444(0, 1, 3, 1, 2, 1);
    D_86003B7C = func_8001E94C(0x36, 0);

    ASSET_LOAD(D_1000000, _4BD6B0, 0);
    FRAGMENT_LOAD(func_80004454, fragment31);

    func_80004454((((u32)D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, _5C7A70_ROM_END);

    func_86002440();
    func_878029C0();
    func_80007678(sp24);

    if (func_86000FD4() != -1) {
        func_8004B9C4(0x3C);
        func_860022F8(5);
        func_86001204();
        func_86001C90();

        if (D_8780FC92 == 0) {
            func_86001F64();
        }

        if (D_8780FC92 == 0) {
            func_8600235C();
        }
    }

    func_86002264();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('MINI');

    func_87803118();
}
