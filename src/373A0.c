#include "373A0.h"
#include "src/4CBC0.h"
#include "src/373A0.h"
#include "src/3D140.h"
#include "src/38BB0.h"
#include "src/4B940.h"
#include "src/4BA90.h"
#include "src/50CC0.h"
#include "src/4F410.h"
#include "src/485C0.h"

typedef struct unk_D_80077970 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0x3];
} unk_D_80077970; // size = 0x5

static unk_D_80077970 D_80077970[151] = {
    { 1, 1, { 0, 0x52, 4 } },    { 1, 1, { 0, 0x58, 0x36 } }, { 2, 2, { 0, 0x1A, 0x3C } }, { 1, 1, { 0, 0, 0 } },
    { 1, 1, { 0, 0x54, 0x3C } }, { 2, 2, { 1, 0x2E, 0xA } },  { 1, 1, { 0, 0x5C, 0 } },    { 1, 1, { 0, 0x44, 0x52 } },
    { 2, 2, { 0, 0x22, 0x36 } }, { 1, 1, { 0, 0x98, 0 } },    { 1, 1, { 0, 0x32, 0xA4 } }, { 1, 1, { 0, 0, 0 } },
    { 1, 1, { 0, 0x32, 0x9E } }, { 1, 1, { 0, 0xC, 0 } },     { 1, 1, { 0, 0x12, 0 } },    { 1, 1, { 0, 0x8C, 0x24 } },
    { 1, 1, { 0, 0x8C, 0x24 } }, { 2, 1, { 0, 0x8C, 0x24 } }, { 1, 1, { 0, 0x54, 0 } },    { 1, 1, { 0, 0x50, 0x34 } },
    { 0, 1, { 0, 0x3C, 0 } },    { 9, 1, { 0, 0x28, 0x10 } }, { 2, 1, { 0, 0x76, 0x94 } }, { 2, 2, { 0, 0x72, 0x3C } },
    { 1, 0, { 0, 0x4E, 0x3C } }, { 1, 1, { 0, 0x7E, 0x72 } }, { 1, 1, { 0, 0, 0x7E } },    { 1, 1, { 0, 0x3C, 0 } },
    { 1, 1, { 0, 0x34, 0x16 } }, { 1, 1, { 0, 0x3C, 0x5A } }, { 2, 2, { 0, 0, 0 } },       { 1, 1, { 0, 8, 0xA } },
    { 1, 1, { 0, 0x6E, 0x64 } }, { 2, 2, { 0, 0x40, 0 } },    { 1, 0, { 0, 0x54, 0x7E } }, { 1, 0, { 0, 0x2C, 0x66 } },
    { 1, 0, { 0, 0x72, 0x98 } }, { 1, 1, { 0, 0x2A, 0x78 } }, { 9, 0, { 0, 0x92, 0x2C } }, { 1, 1, { 0, 0x52, 0x3C } },
    { 1, 1, { 0, 0x46, 0 } },    { 2, 2, { 0, 0x54, 0x4A } }, { 0, 0, { 0, 0x38, 0x1E } }, { 1, 1, { 0, 0, 0x38 } },
    { 9, 1, { 0, 0x50, 0x7E } }, { 1, 1, { 0, 0x6E, 0 } },    { 1, 1, { 0, 0x8E, 0 } },    { 1, 1, { 0, 0x38, 0xBA } },
    { 2, 1, { 0, 0x3A, 0x36 } }, { 0, 0, { 0, 0x3C, 0x5E } }, { 0, 1, { 0, 0x3C, 0x54 } }, { 1, 1, { 0, 0x24, 0x88 } },
    { 2, 1, { 0, 0x5A, 8 } },    { 1, 1, { 0, 0x5A, 0 } },    { 2, 1, { 0, 0x38, 0x64 } }, { 1, 1, { 0, 0x64, 0x54 } },
    { 1, 1, { 0, 0, 0 } },       { 1, 1, { 0, 0x42, 0x18 } }, { 2, 1, { 0, 0x6A, 0x16 } }, { 1, 0, { 0, 0x32, 0x60 } },
    { 1, 1, { 0, 0xA4, 0x42 } }, { 2, 1, { 0, 0x38, 0x86 } }, { 1, 1, { 0, -0x34, 0 } },   { 1, 1, { 0, 0x5A, 0x6C } },
    { 2, 1, { 0, 0x46, 0 } },    { 1, 1, { 0, 0x14, 0xAE } }, { 2, 1, { 0, 0x64, 0x32 } }, { 2, 2, { 0, 0x6C, 0xB0 } },
    { 0, 1, { 0, 0x28, 0x92 } }, { 1, 1, { 0, 0x24, 0x34 } }, { 2, 1, { 0, 0x16, 0 } },    { 1, 1, { 0, 0x30, 0x9E } },
    { 2, 2, { 0, 0x20, 0 } },    { 2, 1, { 0, 0x7A, 0x7C } }, { 2, 2, { 0, 0, 0xC } },     { 2, 2, { 0, 0x3C, 0x2E } },
    { 1, 0, { 0, 0, 0 } },       { 2, 1, { 0, 0x28, 0x10 } }, { 2, 1, { 0, 0, 0x98 } },    { 2, 1, { 0, 0, 0x80 } },
    { 1, 1, { 0, 0x6A, 0x1A } }, { 1, 1, { 0, 0, 0x1A } },    { 1, 1, { 0, 0x64, 0xC } },  { 1, 1, { 0, 0, 0 } },
    { 2, 1, { 0, 0x28, 0 } },    { 1, 1, { 0, 0x54, 0x72 } }, { 2, 1, { 0, 0x6A, 0 } },    { 9, 2, { 0, 0x44, 0 } },
    { 9, 2, { 0, 0x40, 0x2A } }, { 1, 1, { 0, 0x7E, 0 } },    { 2, 2, { 0, 0, 0x7C } },    { 0, 1, { 0, 0x3E, 0x2E } },
    { 0, 2, { 0, 0x32, 0x33 } }, { 0, 2, { 0, 0x38, 0x32 } }, { 2, 2, { 0, 0x30, 0x3A } }, { 1, 1, { 0, 0x34, 0 } },
    { 2, 1, { 0, 0, 0 } },       { 1, 1, { 0, 0x58, 0 } },    { 1, 1, { 0, 0x46, 0 } },    { 9, 1, { 0, 0, 0 } },
    { 9, 1, { 0, 0x28, 0x36 } }, { 1, 1, { 0, 0x44, 0x2A } }, { 2, 1, { 0, 0x60, 0 } },    { 1, 1, { 0, 0xB4, 0x36 } },
    { 1, 1, { 0, 0x14, 0 } },    { 2, 1, { 0, 0x10, 0x72 } }, { 2, 1, { 0, 0x40, 0xB6 } }, { 2, 1, { 0, 0x3E, 0x2C } },
    { 1, 1, { 0, 0x50, 0x78 } }, { 2, 2, { 0, 0x20, 0x3C } }, { 2, 1, { 0, 0x4C, 0x3C } }, { 2, 2, { 0, 0x36, 0xC } },
    { 1, 0, { 0, 0x1E, 0 } },    { 1, 1, { 0, 0, 0x51 } },    { 2, 1, { 0, 0x8C, 0x22 } }, { 0, 0, { 0, 0x5C, 0x6E } },
    { 1, 1, { 0, 0x5A, 0x6E } }, { 1, 0, { 0, 0x7C, 0 } },    { 1, 1, { 0, 0, 0 } },       { 1, 1, { 0, 0x28, 0 } },
    { 1, 1, { 0, 0x1A, 0x64 } }, { 1, 1, { 0, 0x62, 0 } },    { 1, 1, { 0, 0x14, 0x1A } }, { 9, 1, { 0, 0x4A, 0 } },
    { 2, 1, { 0, 0xA, 0x5E } },  { 2, 2, { 0, 0x2E, 0 } },    { 1, 1, { 0, 0x14, 0 } },    { 2, 2, { 0, 0x8C, 0x62 } },
    { 0, 1, { 0, 0, 0x64 } },    { 2, 2, { 0, 0x8C, 0x1E } }, { 2, 1, { 0, 0x28, 0x82 } }, { 9, 0, { 0, 0, 0 } },
    { 1, 0, { 0, 0, 0x3C } },    { 1, 0, { 0, 0, 6 } },       { 1, 0, { 0, 0x40, 0xC } },  { 1, 0, { 0, 0x18, 0x8E } },
    { 1, 1, { 0, 0x3C, 0xE } },  { 1, 1, { 0, 0, 0 } },       { 1, 1, { 0, 0, 0x34 } },    { 1, 1, { 0, 0x32, 0x12 } },
    { 1, 1, { 0, 0x50, 0x42 } }, { 9, 2, { 0, 0x28, 0 } },    { 2, 1, { 0, 0x3C, 0x82 } }, { 2, 1, { 0, 0x32, 0x2A } },
    { 2, 1, { 0, 0x38, 0x2E } }, { 2, 1, { 0, 0x1E, 0x2A } }, { 2, 0, { 0, 0x23, 0x18 } }, { 2, 1, { 0, 0x28, 0 } },
    { 2, 1, { 0, 0x6C, 0 } },    { 2, 1, { 0, 0x64, 0xA } },  { 0, 0, { 0, 0x82, 0 } },
};

static s32 D_80077C64 = 0;
static s32 D_80077C68 = 0;
static s32 D_80077C6C = 0;
static s32 D_80077C70 = 0;
static s32 D_80077C74 = 0;
static s32 D_80077C78 = 0;

u8 D_800B32A0[0x493E0];
u32* D_800FC680;
u8* D_800FC684;
u8* D_800FC688;
u8* D_800FC68C;
u8* D_800FC690;
u8 pad_D_800FC694[4];
u8* D_800FC698[3];
u8* D_800FC6A4;
u8* D_800FC6A8;
u8* D_800FC6AC;
u8* D_800FC6B0[3];
u8* D_800FC6C0[3];
unk_D_800FC6CC* D_800FC6CC;
u8* D_800FC6D0;
u32* D_800FC6D4;
u8* D_800FC6D8;
u8* D_800FC6DC;
u32* D_800FC6E0;
File1Header* D_800FC6E4;
ALSeqFile* D_800FC6E8;
File2SubHeader1* D_800FC6EC;
File2SubHeader2* D_800FC6F0;
ALSeqFile* D_800FC6F4;
ALSeqFile* D_800FC6F8;
File2SubHeader2* D_800FC6FC;
ALSeqFile* D_800FC700;
ALSeqFile* D_800FC704;
ALSeqFile* D_800FC708;
s32 pad_D_800FC70C;
s32 pad_D_800FC710;
ALSeqFile* D_800FC714;
u8 pad_D_800FC718[0x80];
u32* D_800FC798;

s32 func_800367A0(u32 arg0, s32 arg1, s32 arg2) {
    static s32 D_80077C7C = 0;

    UNUSED s32 pad;
    u32 sp40;
    u32 var_v0;
    s32 sp38;
    s32 sp34;
    UNUSED s32 pad2;
    volatile s32 sp2C;
    u32 sp20;

    sp20 = arg0 & 0xFFFF0000;
    sp38 = 0x80;

    if (sp20 != D_80079014) {
        sp40 = D_800FC6F4->seqArray[0].offset;
        func_8004ADB0(sp40, D_800FC798, 0xC);
        func_80037360(D_800FC798, sp40, 3);
        func_8004ADB0(D_800FC798[0], D_800FC6DC, D_800FC798[1] - D_800FC798[0]);
        func_80050B40(D_800FC6DC, D_800FC6A8, 0xBB8);
        func_800397BC(D_800FC6A8);
        func_8004ADB0(D_800FC798[1], D_800FC6DC, D_800FC798[2] - D_800FC798[1]);
        func_80050B40(D_800FC6DC, D_800FC6A4, 0x1388);
        func_8003979C(D_800FC6A4, D_800FC798[2]);
    }

    D_80079014 = sp20;

    switch (arg0) {
        case 0x0:
            if (func_80039354(D_80077C64) != 0) {
                return 0;
            }

            switch (arg1) {
                case 1:
                    sp34 = 1;
                    break;

                case 2:
                    sp34 = 2;
                    break;

                default:
                    return 0;
            }

            D_80077C64 = func_80039024(D_800FC6A4, D_800FC6A8, sp34, 0x70, 0x80, -1);
            sp2C = D_80077C64;
            break;

        case 0x1:
            if (arg1 < -0x5A) {
                arg1 = -0x5A;
            } else if (arg1 >= 0x5B) {
                arg1 = 0x5A;
            }

            do {
                var_v0 = (arg1 + 0x5A) * 1.4111111f;
            } while (0);

            if (var_v0 > 0xFE) {
                var_v0 = 0xFE;
            }
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 3, 0x80, var_v0, -1);
            break;

        case 0x2:
            if (func_80039354(D_80077C6C) != 0) {
                func_800392A8(D_80077C6C, 0x14);
                D_80077C6C = 0;
            }
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 4, 0x80, 0x80, -1);
            break;

        case 0x3:
            D_80077C6C = func_80039024(D_800FC6A4, D_800FC6A8, 5, 0x80, 0x80, -1);
            sp2C = D_80077C6C;
            break;

        case 0x4:
            switch (arg1) {
                case 1:
                    sp34 = 1;
                    break;
                case 2:
                    sp34 = 2;
                    break;

                default:
                    return 0;
            }
            D_80077C68 = func_80039024(D_800FC6A4, D_800FC6A8, sp34, 0x80, 0x80, -1);
            sp2C = D_80077C68;
            break;

        case 0x6:
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 6, 0x80, 0x80, -1);
            break;

        case 0x7:
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 7, 0x80, 0x80, -1);
            break;

        case 0x8:
            return 0;

        case 0x33:
            if (arg1 >= 0x98) {
                arg1 = 3;
            }

            if ((arg1 > 0) && (arg1 < 0x98)) {
                arg1--;
            } else {
                arg1 = 0;
            }

            switch (D_80077970[arg1].unk_00) {
                case 0:
                    return 0;

                case 1:
                    sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 7, 0x80, 0x80, -1);
                    break;

                case 2:
                    sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 6, 0x80, 0x80, -1);
                    break;

                default:
                    return 0;
            }
            break;

        case 0x32:
            if (arg1 == 0xC8) {
                return func_80039024(D_800FC6A4, D_800FC6A8, 0x20, 0x80, 0x80, -1);
            }

            if (arg1 >= 0x98) {
                arg1 = 2;
            }

            if ((arg1 > 0) && (arg1 < 0x98)) {
                arg1--;
            } else {
                arg1 = 0;
            }

            switch (D_80077970[arg1].unk_01) {
                case 0:
                    sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 0xB, 0x80, 0x80, -1);
                    break;

                case 1:
                    sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 0xA, 0x80, 0x80, -1);
                    break;

                case 2:
                    sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 9, 0x80, 0x80, -1);
                    break;
            }
            break;

        case 0x12:
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 0xC, 0x80, 0x80, -1);
            break;

        case 0x13:
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 0xD, 0x80, 0x80, -1);
            break;

        case 0x14:
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 0xE, 0x80, 0x80, -1);
            break;

        case 0x28:
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 0xF, 0x80, 0x80, -1);
            break;

        case 0x5A:
            switch (arg1) {
                case 1:
                    sp34 = 0x12;
                    break;

                case 2:
                    sp34 = 0x13;
                    break;

                default:
                    return 0;
            }

            D_80077C74 = func_80039024(D_800FC6A4, D_800FC6A8, sp34, 0x80, 0x80, -1);
            break;

        case 0x5B:
            switch (arg1) {
                case 1:
                    break;

                case 2:
                    return 0;

                default:
                    return 0;
            }
            D_80077C78 = func_80039024(D_800FC6A4, D_800FC6A8, 0x14, 0x80, 0x80, -1);
            break;

        case 0x15:
            switch (arg1) {
                case 1:
                    sp34 = 0x10;
                    break;

                case 2:
                    sp34 = 0x11;
                    break;

                default:
                    return 0;
            }
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, sp34, 0x80, 0x80, 0x80);
            break;

        case 0x16:
            switch (arg1) {
                case 1:
                    sp34 = 0x16;
                    break;

                case 2:
                    sp34 = 0x17;
                    break;

                default:
                    return 0;
            }

            if (func_80039354(D_80077C7C) != 0) {
                D_80077C7C = 0;
                sp2C = D_80077C7C;
            } else {
                D_80077C7C = func_80039024(D_800FC6A4, D_800FC6A8, sp34, 0x80, 0x80, 0x80);
                sp2C = D_80077C7C;
            }
            break;

        case 0x3C:
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 0x18, 0x80, 0x80, -1);
            break;

        case 0x3D:
            switch (arg1) {
                case 3:
                    sp34 = 0x19;
                    break;

                case 2:
                    sp34 = 0x1A;
                    break;

                case 1:
                    sp34 = 0x1B;
                    break;

                case 0:
                    sp34 = 0x1C;
                    sp38 = 0xFF;
                    break;

                default:
                    return 0;
            }
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, sp34, sp38, 0x80, -1);
            break;

        case 0x3E:
            if (arg1 < 11) {
                if (arg1 == 1 || arg1 == 2) {
                    sp34 = 0x1D;
                } else {
                    sp34 = 0x1E;
                }
            } else {
                return 0;
            }
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, sp34, 0xFF, 0x80, -1);
            break;

        case 0x3F:
            sp2C = func_80039024(D_800FC6A4, D_800FC6A8, 0x1F, 0x80, 0x80, -1);
            break;

        case 0x1E:
            sp2C = func_800479C0(0xA6, 1, 0);
            break;

        case 0x1F:
            sp2C = func_800479C0(0xA6, 1, 1);
            break;

        case 0x20:
            sp2C = func_800479C0(0xA6, 1, 2);
            break;

        case 0x21:
            sp2C = func_800479C0(0xA6, 1, 3);
            break;

        case 0x22:
            sp2C = func_800479C0(0xA6, 1, 4);
            break;

        case 0x23:
            sp2C = func_800479C0(0xA6, 1, 5);
            break;

        default:
            return 0;
    }

    return sp2C;
}

s32 func_80037234(s32 arg0, s32 arg1) {
    switch (arg0) {
        case 0x0:
            if (arg1 == 0) {
                arg1 = 1;
            }
            func_800392A8(D_80077C64, arg1);
            D_80077C64 = 0;
            break;

        case 0x4:
            if (arg1 == 0) {
                arg1 = 1;
            }
            func_800392A8(D_80077C68, arg1);
            break;

        case 0x3:
            func_800392A8(D_80077C6C, 0x3C);
            D_80077C6C = 0;
            break;

        case 0xA1:
            func_800392A8(D_80077C70, 0x78);
            D_80077C70 = 0;
            break;

        case 0x5A:
            func_800392A8(D_80077C74, 0x5A);
            D_80077C74 = 0;
            break;

        case 0x5B:
            func_800392A8(D_80077C78, 0x5A);
            D_80077C78 = 0;
            break;

        default:
            return 0;
    }

    return 1;
}

void func_8003733C(void) {
}

void func_80037340(void* arg0) {
    func_8003CADC(arg0);
}

void func_80037360(u32* arg0, u32 arg1, s32 arg2) {
    u32 i;

    for (i = 0; i < arg2; i++, arg0++) {
        *arg0 += arg1;
    }
}

s32 func_800373D8(void) {
    s32 i;
    FileHeaders* sp78;
    UNUSED s32 pad[3];
    u32 num_files;
    sp38_func_800373D8 sp38;

    sp38.unk_00 = 0x18;
    sp38.unk_04 = 0x34;
    sp38.unk_08 = 0x18;
    sp38.unk_0C = D_800B32A0;
    sp38.unk_10 = 0x493E0;
    sp38.unk_14 = 0x100;
    sp38.unk_18 = 0x7D00;
    sp38.unk_1C = 0x440;
    sp38.unk_20 = 1;
    sp38.unk_24 = 0x30;
    sp38.unk_28 = 0x400;
    sp38.unk_2C = 0x400;

    func_80038B68(&sp38);
    func_8004AD40(2);

    D_800FC6DC = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x61A8);
    D_800FC798 = alHeapDBAlloc(NULL, 0, D_800FC810, 8, 4);
    D_800FC6E0 = alHeapDBAlloc(NULL, 0, D_800FC810, 7, 4);

    // Copy rom data from 0x15C0000 into D_800FC6E0
    func_8004ADB0(&D_15C0000, D_800FC6E0, sizeof(u8*) * 7);
    // Add the address 0x15C0000 to every offset (besides the first which is the total size)
    // to make absolute offsets.
    func_80037360(&D_800FC6E0[1], &D_15C0000, 6);
    sp78 = D_800FC798;
    // Copy data from the offset at 0x15C0004 into sp78, a sub-header for this "archive,"
    // specifying the size of the header and number of files etc. Header at 0x15C0020
    func_8004ADB0(D_800FC6E0[1], sp78, 0xC);
    num_files = sp78->file1.num_files;
    // Allocate vram, copy rom bytes, and add address to make absolute,
    // for all of the first archive's files, including header.
    D_800FC6E4 = alHeapDBAlloc(NULL, 0, D_800FC810, (0xC / sizeof(u32)) + num_files, sizeof(u32));
    func_8004ADB0(D_800FC6E0[1], D_800FC6E4, 0xC + (num_files * 4));
    // Update just the first 2 pointers from the header,
    // pointer to first file, and pointer to N64 wave tables.
    func_80037360(&D_800FC6E4->offset1, D_800FC6E0[1], 2);
    // Make absolute all the offsets after the header, for the archive files at 0x15C002C
    func_80037360(D_800FC6E4->files, D_800FC6E0[1], num_files);
    // Copy the first file into D_800FC6DC. What is this?
    // Yay0 compressed at 0x15C0160
    func_8004ADB0(D_800FC6E4->offset1, D_800FC6DC, D_800FC6E4->wave_tables_offset - D_800FC6E4->offset1);

    // Decompressed first file memory.
    D_800FC684 = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x4120);

    // Decompress first file Yay0 from D_800FC6DC, into D_800FC684
    func_80050B40(D_800FC6DC, D_800FC684, 0x4120);

    // ??
    func_8003979C(D_800FC684, D_800FC6E4->wave_tables_offset);

    D_800FC680 = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x98D8);

    // Load second archive header at 0x16F27E0
    func_8004ADB0(D_800FC6E0[2], sp78, 4 + 4);
    num_files = sp78->seq.seqCount;
    // Memory to hold archive toc
    D_800FC6E8 = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 4 + (num_files * sizeof(ALSeqData)));
    // Read the alSeqFile into D_800FC6E8
    func_8004ADB0(D_800FC6E0[2], D_800FC6E8, 4 + (num_files * sizeof(ALSeqData)));
    // Initialise the memory as an alSeqFile
    alSeqFileNew(D_800FC6E8, D_800FC6E0[2]);

    // Read the first archive sub header from 0x16F2804, into D_800FC6EC
    D_800FC6EC = alHeapDBAlloc(NULL, 0, D_800FC810, 3, 4);
    func_8004ADB0(D_800FC6E8->seqArray[0].offset, D_800FC6EC, sizeof(File2SubHeader1));
    func_80037360(D_800FC6EC, D_800FC6E8->seqArray[0].offset, sizeof(File2SubHeader1) / sizeof(u32));

    // Read the first file from the sub header into D_800FC6DC (0x16F2814)
    func_8004ADB0(D_800FC6EC->offset1, D_800FC6DC, D_800FC6EC->offset2 - D_800FC6EC->offset1);
    // Decompress the yay0 file into D_800FC688
    D_800FC688 = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0xBB8);
    func_80050B40(D_800FC6DC, D_800FC688, 0xBB8);
    // ???
    func_800397BC(D_800FC688);

    // Read the second file from the sub header into D_800FC6DC (0x16F2BD0)
    func_8004ADB0(D_800FC6EC->offset2, D_800FC6DC, D_800FC6EC->wave_tables_offset - D_800FC6EC->offset2);
    // Decompress the yay0 file into D_800FC688
    D_800FC68C = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x157C);
    func_80050B40(D_800FC6DC, D_800FC68C, 0x157C);
    // ???
    func_8003979C(D_800FC68C, D_800FC6EC->wave_tables_offset);

    // Read archive 2 sub file 2 (0x1722F74)
    func_8004ADB0(D_800FC6E8->seqArray[1].offset, sp78, sizeof(File2SubHeader2));
    num_files = sp78->file2sub2.num_files;

    D_800FC6F0 = alHeapDBAlloc(NULL, 0, D_800FC810, 4, (sizeof(File2SubHeader2) / sizeof(u32)) + num_files);
    func_8004ADB0(D_800FC6E8->seqArray[1].offset, D_800FC6F0, sizeof(File2SubHeader2) + (num_files * sizeof(u32)));
    func_80037360(&D_800FC6F0->offset1, D_800FC6E8->seqArray[1].offset, num_files + 2);
    func_8004ADB0(D_800FC6F0->offset1, D_800FC6DC, D_800FC6F0->wave_tables_offset - D_800FC6F0->offset1);
    // Decompress the yay0 file into D_800FC688
    D_800FC690 = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x2EE0);
    func_80050B40(D_800FC6DC, D_800FC690, 0x2EE0);
    // ???
    func_8003979C(D_800FC690, D_800FC6F0->wave_tables_offset);

    D_800FC698[0] = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x258);
    D_800FC698[1] = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x258);
    D_800FC698[2] = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x258);

    // Read the second seq array (0x17C9C24)
    func_8004ADB0(D_800FC6E8->seqArray[2].offset, sp78, sizeof(File2SubHeader2));
    num_files = sp78->file2sub2.num_files;

    D_800FC6FC = alHeapDBAlloc(NULL, 0, D_800FC810, 4, num_files + 3);
    func_8004ADB0(D_800FC6E8->seqArray[2].offset, D_800FC6FC, sizeof(File2SubHeader2) + (num_files * sizeof(u32)));
    func_80037360(&D_800FC6FC->offset1, D_800FC6E8->seqArray[2].offset, num_files + 2);
    func_8004ADB0(D_800FC6FC->offset1, D_800FC6DC, D_800FC6FC->wave_tables_offset - D_800FC6FC->offset1);
    D_800FC6AC = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x9C4);
    // Decompress
    func_80050B40(D_800FC6DC, D_800FC6AC, 0x9C4);
    func_8003979C(D_800FC6AC, D_800FC6FC->wave_tables_offset);

    D_800FC6B0[0] = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x3E8);
    D_800FC6B0[1] = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x3E8);
    D_800FC6B0[2] = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x3E8);

    // Read seq header from 0x17DC304
    func_8004ADB0(D_800FC6E8->seqArray[3].offset, sp78, 4 + 4);
    num_files = sp78->seq.seqCount;

    D_800FC6F4 = alHeapDBAlloc(NULL, 0, D_800FC810, 4, 4 + (num_files * sizeof(ALSeqData)));
    func_8004ADB0(D_800FC6E8->seqArray[3].offset, D_800FC6F4, 4 + (num_files * sizeof(ALSeqData)));
    alSeqFileNew(D_800FC6F4, D_800FC6E8->seqArray[3].offset);

    // Load second seq header from 0x1850C20
    func_8004ADB0(D_800FC6F4->seqArray[1].offset, sp78, 4 + 4);
    num_files = sp78->seq.seqCount;

    D_800FC6F8 = alHeapDBAlloc(NULL, 0, D_800FC810, 4, 4 + (num_files * sizeof(ALSeqData)));
    func_8004ADB0(D_800FC6F4->seqArray[1].offset, D_800FC6F8, 4 + (num_files * sizeof(ALSeqData)));
    alSeqFileNew(D_800FC6F8, D_800FC6F4->seqArray[1].offset);

    D_800FC6A4 = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x1388);
    D_800FC6A8 = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0xBB8);

    // load third archive from the main list, archive is at 0x1978820
    func_8004ADB0(D_800FC6E0[3], sp78, 4 + 4);
    num_files = sp78->seq.seqCount;

    D_800FC700 = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 4 + (num_files * sizeof(ALSeqData)));
    func_8004ADB0(D_800FC6E0[3], D_800FC700, 4 + (num_files * sizeof(ALSeqData)));
    alSeqFileNew(D_800FC700, D_800FC6E0[3]);

    // load fourth archive from the main list, archive is at 0x197C1E0
    func_8004ADB0(D_800FC6E0[4], sp78, 4 + 4);
    num_files = sp78->seq.seqCount;

    D_800FC704 = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 4 + (num_files * sizeof(ALSeqData)));
    func_8004ADB0(D_800FC6E0[4], D_800FC704, 4 + (num_files * sizeof(ALSeqData)));
    alSeqFileNew(D_800FC704, D_800FC6E0[4]);

    D_800FC6C0[0] = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x44C);
    D_800FC6C0[1] = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x44C);
    D_800FC6C0[2] = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 0x44C);

    // load the fourth archive's first seq, at 0x197C1FC
    func_8004ADB0(D_800FC704->seqArray[0].offset, sp78, 4 + 4);
    num_files = sp78->seq.seqCount;
    D_800FC708 = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 4 + (num_files * sizeof(ALSeqData)));
    func_8004ADB0(D_800FC704->seqArray[0].offset, D_800FC708, 4 + (num_files * sizeof(ALSeqData)));
    alSeqFileNew(D_800FC708, D_800FC704->seqArray[0].offset);

    D_80079364 = 0;

    // load the fourth archive's third seq at 0x1A2AD20
    func_8004ADB0(D_800FC704->seqArray[2].offset, sp78, 4 + 4);
    num_files = sp78->seq.seqCount;
    D_800FC714 = alHeapDBAlloc(NULL, 0, D_800FC810, 1, 4 + (num_files * sizeof(ALSeqData)));
    func_8004ADB0(D_800FC704->seqArray[2].offset, D_800FC714, 4 + (num_files * sizeof(ALSeqData)));
    alSeqFileNew(D_800FC714, D_800FC704->seqArray[2].offset);

    D_800FC6D8 = alHeapDBAlloc(NULL, 0, D_800FC810, 0xB80, 2);

    // load the 5th main archive at 0x1FBA260
    D_800FC6D4 = alHeapDBAlloc(NULL, 0, D_800FC810, 0x1388, 1);
    func_8004ADB0(D_800FC6E0[5], D_800FC6D4, D_800FC6E0[6] - D_800FC6E0[5]);

    // load the 6th main archive at 0x1FBB220
    D_800FC6CC = alHeapDBAlloc(NULL, 0, D_800FC810, 0x100, 1);
    func_8004ADB0(D_800FC6E0[6], D_800FC6CC, 0x100);

    for (i = 0; i < 32; i++) {
        D_800FC6CC[i].unk_00 += D_800FC6E0[6];
    }

    D_800FC6D0 = alHeapDBAlloc(NULL, 0, D_800FC810, 0x2328, 1);

    func_8004AE90(2, 2);
    func_8004AE90(1, 3);

    D_800FC820 = 0;

    return D_800FC810->cur - D_800FC810->base;
}

static s32 pad_D_80077C80 = 0;
