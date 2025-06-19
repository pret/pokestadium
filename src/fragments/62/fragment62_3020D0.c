#include "fragment62.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/225A0.h"
#include "src/29BA0.h"
#include "src/2E110.h"
#include "src/3D140.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "stdarg.h"

unk_D_843901A0* D_843901A0;

static u8 D_84385990[] = { 0xE, 0x4A };
static u8 D_84385994[] = { 0x60, 0x69, 0x75, 0x78, 0x85 };
static u8 D_8438599C[] = { 0x61, 0x64, 0x66, 0x68, 0x8C };
static u8 D_843859A4[] = {
    1,    0xA,  0xB,  0x11, 0x13, 0x14, 0x15, 0x1E, 0x22, 0x23, 0x25, 0x27, 0x2B, 0x2C, 0x2D, 0x2E,
    0x2F, 0x40, 0x44, 0x46, 0x47, 0x51, 0x59, 0x5A, 0x5B, 0x5C, 0x67, 0x6A, 0x6B, 0x6E, 0x6F, 0x76,
    0x7A, 0x80, 0x84, 0x8B, 0x8D, 0x91, 0x94, 0x96, 0x97, 0x9A, 0x9C, 0x9F, 0xA3, 0xA4,
};

void func_84317810(void) {
    D_843901A0->unk_088[0] = 0;
    D_843901A0->unk_088[1] = 0;
    D_843901A0->unk_0C8[0] = 0;
    D_843901A0->unk_0C8[1] = 0;
    D_843901A0->unk_108[0] = 0;
    D_843901A0->unk_108[1] = 0;
    D_843901A0->unk_148[0] = 0;
    D_843901A0->unk_148[1] = 0;
    D_843901A0->unk_188[0] = 0;
    D_843901A0->unk_188[1] = 0;
    D_843901A0->unk_1C8[0] = 0;
    D_843901A0->unk_1C8[1] = 0;
    D_843901A0->unk_448[0][0] = 0;
    D_843901A0->unk_448[0][1] = 0;
    D_843901A0->unk_448[1][0] = 0;
    D_843901A0->unk_448[1][1] = 0;
    D_843901A0->unk_208[0] = 0;
    D_843901A0->unk_208[1] = 0;
    D_843901A0->unk_308[0] = 0;
    D_843901A0->unk_308[1] = 0;
    D_843901A0->unk_2C8[0] = 0;
    D_843901A0->unk_2C8[1] = 0;
    D_843901A0->unk_348[0] = 0;
    D_843901A0->unk_348[1] = 0;
    D_843901A0->unk_388[0] = 0;
    D_843901A0->unk_388[1] = 0;
    D_843901A0->unk_3C8[0] = 0;
    D_843901A0->unk_3C8[1] = 0;
    D_843901A0->unk_408[0] = 0;
    D_843901A0->unk_408[1] = 0;
}

void func_8431790C(void) {
    D_843901A0->unk_004 = 0;
    D_843901A0->unk_048[0] = 0;
    D_843901A0->unk_048[1] = 0;
    D_843901A0->unk_008[0] = 0;
    D_843901A0->unk_008[1] = 0;
}

#ifdef NON_MATCHING
void func_84317940(s8* arg0, s8* arg1, ...) {
    va_list args;
    s8** temp_v1;
    s32 var_v0;
    s8* var_a3;

    var_v0 = 0;
    temp_v1 = &args;

    while (*arg1 != '\x00') {
        if (*arg1 != 0x25) {
            arg0[var_v0++] = *arg1;
        } else {
            arg1++;
            if (*arg1 == 0x73) {
                temp_v1 = ALIGN4((s32)temp_v1);
                var_a3 = *(s8**)temp_v1;
                temp_v1++;

                while (*var_a3 != 0) {
                    arg0[var_v0] = *var_a3;
                    var_a3++;
                    var_v0++;
                }
            }
        }
        arg1++;
    }
    arg0[var_v0] = '\x00';
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/62/fragment62_3020D0/func_84317940.s")
#endif

void func_843179F4(s8* arg0, s8 arg1) {
    u8 tmp = arg1;
    *arg0 = arg1;

    if (tmp >= 0x80) {
        if ((tmp - 0x80) >= 0xB) {
            func_8002D7C0(arg0 + 1, 0x40, D_843900B0, tmp - 0x48);
        } else {
            func_8002D7C0(arg0 + 1, 0x40, D_843900B0, tmp - 0x49);
        }
    } else {
        func_8002D7C0(arg0 + 1, 0x40, D_843900B0, D_84385BC0[arg1]);
    }
}

void func_84317AA8(char* arg0, s32 arg1) {
    UNUSED s32 pad[3];
    unk_D_84390010_654* sp28 = &D_84390010[arg1]->unk_654;
    UNUSED s32 pad2[2];

    func_8431790C();
    D_843901A0->unk_000 = D_84390010[arg1]->unk_720->unk_08[sp28->unk_2B]->unk_001;
    func_84317940(D_843901A0->unk_048, arg0 + 1);
    *arg0 = 0;
}

void func_84317B38(void) {
}

void func_84317B40(void) {
    unk_D_84390010* ptr1 = D_84390010[0];
    unk_D_84390010* ptr2 = D_84390010[1];

    if ((D_800AE540.unk_0000 != 0x10) && (D_84390240.unk_00->unk_30 == 0)) {
        func_8431595C(ptr1, 0x15, 0xF, ptr1->unk_720->unk_08[ptr1->unk_728.unk_16C]->unk_001);
        func_8431595C(ptr2, 0xE1, 0xF, ptr2->unk_720->unk_08[ptr2->unk_728.unk_16C]->unk_001);
    }
}

void func_84317BDC(void) {
    u32 sp1C;
    unk_D_800FCB18* sp18 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;

    sp18->unk_58 = sp18->unk_44.unk_00;

    if (func_84307AE0(sp18->unk_44.unk_00, D_84385990, 2) != 0) {
        sp1C = 0;
    } else if (func_84307AE0(sp18->unk_44.unk_00, D_84385994, 5) != 0) {
        sp1C = 1;
    } else if (func_84307AE0(sp18->unk_44.unk_00, D_8438599C, 5) != 0) {
        sp1C = 2;
    } else if (func_84307AE0(sp18->unk_44.unk_00, D_843859A4, 0x2E) != 0) {
        sp1C = 3;
    } else {
        sp1C = 4;
    }

    if ((sp18->unk_44.unk_00 == 0x76) || (sp18->unk_44.unk_00 == 0x77)) {
        func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
        func_8002D5D4(0x1D, func_843085F0(D_84390010[D_84390240.unk_00->unk_2C]));

        switch (sp1C) {
            case 0:
                func_843179F4(D_843901A0->unk_388, 0x14);
                break;

            case 1:
                func_843179F4(D_843901A0->unk_388, 0x15);
                break;

            case 2:
                func_843179F4(D_843901A0->unk_388, 0x16);
                break;

            case 3:
                func_843179F4(D_843901A0->unk_388, 0x17);
                break;

            case 4:
                func_843179F4(D_843901A0->unk_388, 0x18);
                break;
        }
    } else {
        func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
        func_8002D5D4(0x1D, func_843085F0(D_84390010[D_84390240.unk_00->unk_2C]));

        switch (sp1C) {
            case 0:
                func_843179F4(D_843901A0->unk_0C8, 0x14);
                break;

            case 1:
                func_843179F4(D_843901A0->unk_0C8, 0x15);
                break;

            case 2:
                func_843179F4(D_843901A0->unk_0C8, 0x16);
                break;

            case 3:
                func_843179F4(D_843901A0->unk_0C8, 0x17);
                break;

            case 4:
                func_843179F4(D_843901A0->unk_0C8, 0x18);
                break;
        }
    }
}

void func_84317EDC(void) {
    u32 sp24;
    UNUSED s32 pad;
    unk_D_800FCB18* sp1C = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;

    if (func_84307AE0(sp1C->unk_5A, D_84385990, 2) != 0) {
        sp24 = 0;
    } else if (func_84307AE0(sp1C->unk_5A, D_84385994, 5) != 0) {
        sp24 = 1;
    } else if (func_84307AE0(sp1C->unk_5A, D_8438599C, 5) != 0) {
        sp24 = 2;
    } else if (func_84307AE0(sp1C->unk_5A, D_843859A4, 0x2E) != 0) {
        sp24 = 3;
    } else {
        sp24 = 4;
    }

    func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
    func_8002D5D4(0x1D, func_843085F0(D_84390010[D_84390240.unk_00->unk_2C]));

    switch (sp24) {
        case 0:
            func_843179F4(D_843901A0->unk_0C8, 0x14);
            break;

        case 1:
            func_843179F4(D_843901A0->unk_0C8, 0x15);
            break;

        case 2:
            func_843179F4(D_843901A0->unk_0C8, 0x16);
            break;

        case 3:
            func_843179F4(D_843901A0->unk_0C8, 0x17);
            break;

        case 4:
            func_843179F4(D_843901A0->unk_0C8, 0x18);
            break;
    }
}

void func_843180AC(void) {
    s32 sp2C;
    s32 tmp;
    unk_D_800FCB18* sp24;

    sp24 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;

    if (func_84307AE0(sp24->unk_5A, D_84385990, 2) != 0) {
        sp2C = 0;
    } else if (func_84307AE0(sp24->unk_5A, D_84385994, 5) != 0) {
        sp2C = 1;
    } else if (func_84307AE0(sp24->unk_5A, D_8438599C, 5) != 0) {
        sp2C = 2;
    } else if (func_84307AE0(sp24->unk_5A, D_843859A4, 0x2E) != 0) {
        sp2C = 3;
    } else {
        sp2C = 4;
    }

    if (sp24->unk_5A == 0x76) {
        do {
            tmp = func_8436F6D8();
        } while ((tmp == 0) || (tmp >= 0xA5) || tmp == 0x76);

        sp24->unk_5A = tmp;

        func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
        func_8002D5D4(0x1D, func_843085F0(D_84390010[D_84390240.unk_00->unk_2C]));

        switch (sp2C) {
            case 0:
                func_843179F4(D_843901A0->unk_0C8, 0x14);
                break;

            case 1:
                func_843179F4(D_843901A0->unk_0C8, 0x15);
                break;

            case 2:
                func_843179F4(D_843901A0->unk_0C8, 0x16);
                break;

            case 3:
                func_843179F4(D_843901A0->unk_0C8, 0x17);
                break;

            case 4:
                func_843179F4(D_843901A0->unk_0C8, 0x18);
                break;
        }

        sp24->unk_5A = 0x76;

        func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
        func_8002D5D4(0x1D, func_843085F0(D_84390010[D_84390240.unk_00->unk_2C]));

        switch (sp2C) {
            case 0:
                func_843179F4(D_843901A0->unk_388, 0x14);
                break;

            case 1:
                func_843179F4(D_843901A0->unk_388, 0x15);
                break;

            case 2:
                func_843179F4(D_843901A0->unk_388, 0x16);
                break;

            case 3:
                func_843179F4(D_843901A0->unk_388, 0x17);
                break;

            case 4:
                func_843179F4(D_843901A0->unk_388, 0x18);
                break;
        }
    } else {
        func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
        func_8002D5D4(0x1D, func_843085F0(D_84390010[D_84390240.unk_00->unk_2C]));

        switch (sp2C) {
            case 0:
                func_843179F4(D_843901A0->unk_0C8, 0x14);
                break;

            case 1:
                func_843179F4(D_843901A0->unk_0C8, 0x15);
                break;

            case 2:
                func_843179F4(D_843901A0->unk_0C8, 0x16);
                break;

            case 3:
                func_843179F4(D_843901A0->unk_0C8, 0x17);
                break;

            case 4:
                func_843179F4(D_843901A0->unk_0C8, 0x18);
                break;
        }
    }
}

void func_843184E4(s32 arg0) {
    unk_D_843901A0_4C8* ptr = &D_843901A0->unk_4C8;

    ptr->unk_00 = 0;
    ptr->unk_04 = arg0;
}

void func_843184FC(void) {
    unk_D_843901A0_4C8* ptr = &D_843901A0->unk_4C8;

    ptr->unk_00 = 0xFF;
}

void func_84318514(s8* arg0) {
    s32 temp_v0;

    if (arg0[1] == '\x00') {
        return;
    }

    temp_v0 = arg0[0] & 0x7F;

    if ((arg0[0] & 0x80) == '\x00') {
        func_8003F624(arg0[0]);
    } else if (temp_v0 == 'Q') {
        func_8003F624(0xBC);
    } else if (temp_v0 == 'R') {
        func_8003F624(0xB5);
    } else if (temp_v0 == 'S') {
        func_8003F624(0xB6);
    } else if (temp_v0 == 'T') {
        func_8003F624(0xB7);
    } else if (temp_v0 == 'U') {
        func_8003F624(0xB8);
    } else if (temp_v0 == 'V') {
        func_8003F624(0xB9);
    } else if (temp_v0 == 'W') {
        func_8003F624(0xBA);
    } else if (temp_v0 == 'X') {
        func_8003F624(0xBB);
    } else {
        func_8003F624(temp_v0 + 0x64);
    }
}

void func_84318640(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2) {
    UNUSED s32 pad;
    s32 temp_s1;

    if (1) {}

    switch (arg0->unk_04) {
        case 0:
            if (func_84315BC0(&D_843901A0->unk_388[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (func_84315BC0(&D_843901A0->unk_0C8[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (func_84315BC0(&D_843901A0->unk_188[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }
            break;

        case 3:
            if (func_84315BC0(&D_843901A0->unk_088[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (func_84315BC0(&D_843901A0->unk_148[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (func_84315BC0(&D_843901A0->unk_208[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }
            break;

        case 1:
            if (func_84315BC0(&D_843901A0->unk_3C8[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (func_84315BC0(&D_843901A0->unk_088[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (func_84315BC0(&D_843901A0->unk_148[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if ((arg0->unk_10 < 3) &&
                (func_84315BC0(&D_843901A0->unk_208[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0)) {
                arg0->unk_10 += 1;
            }
            break;

        case 2:
            if (func_84315BC0(&D_843901A0->unk_088[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (func_84315BC0(&D_843901A0->unk_148[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }

            if (func_84315BC0(&D_843901A0->unk_208[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3) != 0) {
                arg0->unk_10 += 1;
            }
            break;

        case 4:
            func_84315BC0(&D_843901A0->unk_248[1], arg1 + 4, arg2 + 3);
            break;

        case 5:
            func_84315BC0(&D_843901A0->unk_288[1], arg1 + 4, arg2 + 3);
            break;

        case 6:
            func_84315BC0(&D_843901A0->unk_408[1], arg1 + 4, arg2 + 3);
            break;

        case 7:
            func_84315BC0(&D_843901A0->unk_348[1], arg1 + 4, arg2 + 3);
            func_84315BC0(&D_843901A0->unk_2C8[1], arg1 + 4, arg2 + 0x10);
            break;

        case 8:
            func_84315BC0(&D_843901A0->unk_448[arg0->unk_0C][1], arg1 + 4, arg2 + 3);
            break;

        case 9:
        case 10:
            func_84315BC0(&D_843901A0->unk_1C8[1], arg1 + 4, arg2 + 3);
            break;

        case 11:
            func_84315BC0(&D_843901A0->unk_088[1], arg1 + 4, arg2 + 3);
            break;

        case 12:
            func_84315BC0(&D_843901A0->unk_088[1], arg1 + 4, arg2 + 3);
            break;

        case 13:
            temp_s1 = func_8001F5B0(1, 0, func_8002D7C0(NULL, 0, D_843900B0, 0xA4)) / 2;
            func_84315BC0(func_8002D7C0(NULL, 0, D_843900B0, 0xA4), 0xA1 - temp_s1, 0x71);
            break;

        case 14:
            func_84317004();
            break;

        case 15:
            func_84315BC0(&D_843901A0->unk_088[1], arg1 + 4, arg2 + (arg0->unk_10 * 0xC) + 3);
            break;
    }

    arg0->unk_10 = 0;
}

s32 func_84318CE4(unk_D_843901A0_4C8* arg0) {
    unk_D_843901A0* temp_v0;
    s32 tmp;

    arg0->unk_10 = 0;

    switch (arg0->unk_04) {
        case 0:
            if ((D_843901A0->unk_0C8[1] == 0) && (D_843901A0->unk_388[1] == 0) && (D_843901A0->unk_188[1] == 0)) {
                arg0->unk_00 = 0xFF;
                return 1;
            }

            arg0->unk_0C = D_84390240.unk_00->unk_2C;
            if (D_843901A0->unk_0C8[1] != 0) {
                func_84318514(D_843901A0->unk_0C8);
            }

            if (D_843901A0->unk_388[1] != 0) {
                func_84318514(D_843901A0->unk_388);
            }

            if (D_843901A0->unk_188[1] != 0) {
                func_84318514(D_843901A0->unk_188);
            }
            arg0->unk_00 += 1;
            break;

        case 1:
        case 3:
            arg0->unk_0C = D_84390240.unk_00->unk_2C;
            func_84318514(D_843901A0->unk_088);
            func_84318514(D_843901A0->unk_148);
            func_84318514(D_843901A0->unk_208);
            func_84318514(D_843901A0->unk_3C8);
            func_84318514(D_843901A0->unk_308);
            if ((D_843901A0->unk_088[1] == 0) && (D_843901A0->unk_148[1] == 0) && (D_843901A0->unk_208[1] == 0) &&
                (D_843901A0->unk_3C8[1] == 0) && (D_843901A0->unk_308[1] == 0)) {
                arg0->unk_00 = 0xFF;
                return 1;
            }
            arg0->unk_00 += 1;
            break;

        case 2:
            arg0->unk_0C = D_84390240.unk_00->unk_2C;
            func_84318514(D_843901A0->unk_088);
            func_84318514(D_843901A0->unk_148);
            func_84318514(D_843901A0->unk_208);
            if ((D_843901A0->unk_088[1] == 0) && (D_843901A0->unk_148[1] == 0) && (D_843901A0->unk_208[1] == 0)) {
                arg0->unk_00 = 0xFF;
                return 1;
            }
            arg0->unk_00 += 1;
            break;

        case 15:
            arg0->unk_0C = D_84390240.unk_00->unk_2C;
            func_84318514(D_843901A0->unk_088);
            if (D_843901A0->unk_088[1] == 0) {
                arg0->unk_00 = 0xFF;
                return 1;
            }
            arg0->unk_00 += 1;
            break;

        case 8:
            if (D_843901A0->unk_448[arg0->unk_0C][1] == 0) {
                arg0->unk_00 = 0xFF;
                return 1;
            }
            tmp = D_84390240.unk_00->unk_2C == 0;
            arg0->unk_00 += 1;
            arg0->unk_0C = tmp;
            break;

        case 9:
            tmp = D_84390240.unk_00->unk_2C == 0;
            arg0->unk_00 += 1;
            arg0->unk_0C = tmp;
            break;

        case 4:
        case 5:
        case 6:
            func_84318514(D_843901A0->unk_248);
            func_84318514(D_843901A0->unk_288);
            func_84318514(D_843901A0->unk_408);
            arg0->unk_00 += 1;
            break;

        case 14:
            D_84390190.z = 0.0f;
            D_84390190.x = 321.0f;
            D_84390190.y = 160.0f;
            arg0->unk_0C = D_84390240.unk_00->unk_2C;
            arg0->unk_00 += 1;
            break;

        default:
            arg0->unk_0C = D_84390240.unk_00->unk_2C;
            arg0->unk_00 += 1;
            break;
    }
    return 0;
}

void func_843190A8(s16 arg0, s16 arg1) {
    unk_D_843901A0_4C8* temp_s0 = &D_843901A0->unk_4C8;

    if (D_800AE540.unk_0000 == 0x10) {
        return;
    }

    switch (temp_s0->unk_00) {
        case 0:
            temp_s0->unk_08 = 0;
            if (temp_s0->unk_04 == 0xD) {
                func_843160C0(temp_s0, 0xA0, 0x78);
                temp_s0->unk_00++;
            } else if (temp_s0->unk_04 == 0xE) {
                func_84318CE4(temp_s0);
            } else if (func_84318CE4(temp_s0) == 0) {
                func_84315D88(temp_s0, arg0, arg1);
            }
            break;

        case 1:
            if (temp_s0->unk_04 == 0xD) {
                if (func_843161F8(temp_s0, 0xA0, 0x78) != 0) {
                    func_84318640(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);
                    temp_s0->unk_00++;
                }
            } else {
                if (temp_s0->unk_04 == 0xE) {
                    func_8003F660(func_84308D98(D_84390010[temp_s0->unk_0C]));
                    func_84318640(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);
                    temp_s0->unk_00++;
                } else if (func_84315EC0(temp_s0, arg0, arg1) != 0) {
                    func_8003F660(func_84308D98(D_84390010[temp_s0->unk_0C]));
                    func_84318640(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);
                    temp_s0->unk_00++;
                }
            }
            break;

        case 2:
            if (temp_s0->unk_04 == 0xD) {
                func_843161F8(temp_s0, 0xA0, 0x78);
                func_84318640(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);

                temp_s0->unk_08++;
                if (temp_s0->unk_08 == 0x46) {
                    temp_s0->unk_00++;
                }
            } else {
                if (temp_s0->unk_04 == 0xE) {
                    func_84318640(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);
                } else {
                    func_84315EC0(temp_s0, arg0, arg1);
                    func_84318640(temp_s0, temp_s0->unk_14.x, temp_s0->unk_14.y);

                    temp_s0->unk_08++;
                    if (temp_s0->unk_08 == 0x2D) {
                        temp_s0->unk_00++;
                    }
                }
            }
            break;
    }
}

void func_843193F4(unk_D_84390010* arg0) {
    arg0->unk_8C4.unk_00 = 0;
    arg0->unk_8C4.unk_04 = 0;
    arg0->unk_8C4.unk_48[0] = 0;
    arg0->unk_8C4.unk_08[0] = 0;
}

void func_84319408(unk_D_84390010* arg0, s32 arg1) {
    D_843901A0->unk_000 = arg0->unk_720->unk_08[arg0->unk_654.unk_2C]->unk_001;
    arg0->unk_8C4.unk_00 = 1;
    func_8002D5D4(0x19, arg0->unk_724->unk_01C[arg0->unk_654.unk_08].unk_30);
    func_8002D7C0(arg0->unk_8C4.unk_48, 0x40, D_843900B0, arg1);
}

void func_843194A0(unk_D_84390010* arg0) {
    unk_D_800AE540_0004* temp_t0 = arg0->unk_720->unk_08[arg0->unk_654.unk_2C];

    if (arg0->unk_8C4.unk_48[arg0->unk_8C4.unk_04] != '\x00') {
        arg0->unk_8C4.unk_08[arg0->unk_8C4.unk_04] = arg0->unk_8C4.unk_48[arg0->unk_8C4.unk_04];
        arg0->unk_8C4.unk_04++;
    }

    if (arg0->unk_8C4.unk_48[arg0->unk_8C4.unk_04] != '\x00') {
        arg0->unk_8C4.unk_08[arg0->unk_8C4.unk_04] = arg0->unk_8C4.unk_48[arg0->unk_8C4.unk_04];
        arg0->unk_8C4.unk_04++;
    }

    arg0->unk_8C4.unk_08[arg0->unk_8C4.unk_04] = '\x00';

    if (arg0->unk_8C4.unk_48[0] != 0) {
        if (arg0 == D_84390018) {
            func_843162E4(temp_t0->unk_001, 0x5F, 0xE, &arg0->unk_8C4.unk_08);
        } else {
            func_843162E4(temp_t0->unk_001, 0x17, 0xBB, &arg0->unk_8C4.unk_08);
        }
    }
}

void func_84319564(void) {
    unk_D_84390010_654* sp1C = &D_84390010[0]->unk_654;
    unk_D_84390010_654* sp18 = &D_84390010[1]->unk_654;

    if ((D_800AE540.unk_11ED != 0) && (D_84390010[1]->unk_728.unk_168->unk_1C == 0x103) &&
        (D_84390010[0]->unk_728.unk_168->unk_1C == 0x17)) {
        func_843118A8(0x101, 0x64);
        if (D_84390134 == 0) {
            if (sp1C->unk_10 != 3) {
                func_843116D8(0x46, 0x4D);
            }

            if (sp18->unk_10 != 3) {
                func_843116D8(0xE8, 0x96);
            }
        }
    }
}

void func_8431962C(void) {
    D_843901A0 = main_pool_alloc(sizeof(unk_D_843901A0), 0);
    bzero(D_843901A0, sizeof(unk_D_843901A0));
}

void func_84319668(void) {
    D_843901A0->unk_004 = 0;
    D_843901A0->unk_008[D_843901A0->unk_004] = 0;
    func_8431790C();
}

void func_843196A4(void) {
    unk_D_84390010_654* sp1C = &D_84390010[0]->unk_654;
    unk_D_84390010_654* sp18 = &D_84390010[1]->unk_654;

    if (1) {}

    func_843190A8(0xA0, 0xC8);

    if (D_800AE540.unk_0000 == 0x10) {
        func_8431712C();
        func_8431694C();
    }

    switch (D_84390240.unk_00->unk_1C) {
        case 1:
            func_843172A0(D_84390010[0], sp1C);
            func_84317558(D_84390010[1], sp18);
            func_843194A0(D_84390010[0]);
            func_843194A0(D_84390010[1]);
            func_84319564();
            func_84316610();
            break;

        case 2:
            func_84317B40();
            func_84316610();
            break;
    }
}
