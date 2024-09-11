#include "22630.h"
#include "include/string.h"
#include "src/22630.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/2E110.h"
#include "src/gb_tower.h"
#include "src/hal_libc.h"
#include "src/util.h"

typedef struct unk_D_80070F84 {
    /* 0x00 */ char unk00[0x6];
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ char unk0B[0x8];
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ char unk14[0x3];
} unk_D_80070F84; // size = 0x17

typedef struct unk_D_800AC910_50 {
    /* 0x000 */ char unk000[0x18];
    /* 0x018 */ u8 unk_018[11];
    /* 0x023 */ char unk023[0x62];
    /* 0x085 */ u8 unk_085;
    /* 0x086 */ char unk086[0x4];
    /* 0x08A */ u8 unk_08A;
    /* 0x08B */ char unk08B[0x3EC];
    /* 0x477 */ s8 unk_477;
    /* 0x478 */ char unk478[0xA5];
    /* 0x51D */ s8 unk_51D;
    /* 0x51E */ char unk51E[0x48E];
    /* 0x9AC */ u8 unk_9AC;
    /* 0x9AB */ char unk9AB[0x5F6];
    /* 0xFA1 */ u8 unk_FA1;
    /* 0xFA2 */ char unkFA2[0x1E];
} unk_D_800AC910_50; // size = 0xFC0

typedef struct unk_D_800AC910_40 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[11];
} unk_D_800AC910_40;

typedef struct unk_D_800AC910 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk06[0x13];
    /* 0x19 */ u8 unk_019[0x20];
    /* 0x39 */ char unk39[0x7];
    /* 0x40 */ u16 unk_40;
    /* 0x42 */ char unk_42[11];
    /* 0x4D */ u8 unk_4D[2];
    /* 0x50 */ unk_D_800AC910_50* unk_50;
    /* 0x54 */ void* unk_54;
} unk_D_800AC910; // size = 0x58

extern unk_D_80070F84 D_80070F84[];

extern unk_D_800AC910 D_800AC910[];
extern u32 D_800ACA70;
extern u8 D_800ACA74;
extern u8 D_800ACA75;

extern u8 D_80073267[];
extern u8 D_800732FF[];

extern char D_800AC890[][0x20];

u16 func_80021A30(u8* arg0) {
    return (arg0[0] << 8) | arg0[1];
}

u32 func_80021A48(u8* arg0) {
    return (arg0[0] << 0x10) | (arg0[1] << 8) | arg0[2];
}

void func_80021A68(u8* arg0, s32 arg1) {
    arg0[0] = (arg1 >> 8) & 0xFF;
    arg0[1] = arg1 & 0xFF;
}

void func_80021A78(u8* arg0, s32 arg1) {
    arg0[0] = (arg1 >> 0x10) & 0xFF;
    arg0[1] = (arg1 >> 8) & 0xFF;
    arg0[2] = (arg1)&0xFF;
}

char* func_80021A90(char* arg0, char* arg1) {
    extern s8 D_80073030[];

    char* sp34 = arg0;
    char* sp18;
    char* temp_s1 = func_8002311C(1);

    while (*arg1 != 'P') {
        if (*arg1 == ']') {
            memcpy(arg0, temp_s1, strlen(temp_s1) + 1);
            arg0 += strlen(temp_s1);
        } else {
            *arg0++ = D_80073030[*arg1];
        }
        arg1++;
    }

    *arg0++ = '\x0';

    return sp34;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80021B5C.s")

char* func_80021B7C(char* arg0, char* arg1) {
    extern u8 D_80073130[];

    char* sp1C = arg0;
    char* sp18 = arg1;

    if (HAL_Strcmp(sp18, func_8002311C(1)) == 0) {
        *arg0++ = ']';
    } else {
        while (*sp18 != 0) {
            *arg0++ = D_80073130[*sp18++];
        }
    }

    *arg0++ = 'P';

    return sp1C;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80021C20.s")

void func_80021C40(char* arg0, char* arg1) {
    char sp1C[11];

    _bcopy(arg1, sp1C, 0xA);

    sp1C[10] = 'P';

    func_80021A90(arg0, sp1C);
}

extern char D_8006FEE8[][0x1C];

char* func_80021C80(char* arg0, char* arg1) {
    HAL_Strcpy(arg0, arg1);
    return arg0;
}

char* func_80021CA4(char* arg0, u32 arg1) {
    func_80021C80(arg0, (char*)*(u32*)D_8006FEE8[arg1]);
    return arg0;
}

#ifdef NON_MATCHING
char* func_80021CE0(s32 arg0, s8* arg1) {
    extern char* D_80072EE0[];

    if ((arg0 > 0) && (arg0 < 0x54)) {
        HAL_Strcpy(arg1, D_80072EE0[arg0 - 1]);
    } else if ((arg0 >= 0xC4) && (arg0 < 0xC9)) {
        sprintf(arg1, "ひでんマシン%02d", arg0 - 0xC3, arg0);
    } else if ((arg0 >= 0xC9) && (arg0 < 0xFF)) {
        sprintf(arg1, "わざマシン%02d", arg0 - 0xC8, arg0);
    } else {
        HAL_Strcpy(arg1, D_80072EE0[6]);
    }

    return arg1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80021CE0.s")
#endif

void func_80021D9C(unk_func_80026268_arg0* arg0, unk_D_800AE4E8_004_1_000_010* arg1) {
    arg0->unk_00 = func_80022A60(arg1->unk_00);
    arg0->unk_01 = arg1->unk_00;
    arg0->unk_02 = func_80021A30(arg1->unk_01);

    arg0->unk_04 = arg1->unk_03;
    arg0->unk_05 = arg1->unk_04;
    arg0->unk_06 = arg1->unk_05;
    arg0->unk_07 = arg1->unk_06;
    arg0->unk_08 = arg1->unk_07;

    arg0->unk_0E = func_80021A30(arg1->unk_0C);
    arg0->unk_10 = func_80021A48(arg1->unk_0E);
    arg0->unk_14 = func_80021A30(arg1->unk_11);
    arg0->unk_16 = func_80021A30(arg1->unk_13);
    arg0->unk_18 = func_80021A30(arg1->unk_15);
    arg0->unk_1A = func_80021A30(arg1->unk_17);
    arg0->unk_1C = func_80021A30(arg1->unk_19);
    arg0->unk_1E = func_80021A30(arg1->unk_1B);

    memcpy(arg0->unk_09, arg1->unk_08, 4);
    memcpy(arg0->unk_20, arg1->unk_1D, 4);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80021E90.s")

void func_80021F04(unk_func_80026268_arg0* arg0, unk_D_800AE4E8_004_1_000_010* arg1) {
    if (func_80022A38(arg0->unk_00) & 0xFF) {
        arg1->unk_00 = func_80022A38(arg0->unk_00);
    } else {
        arg1->unk_00 = arg0->unk_01;
    }

    func_80021A68(arg1->unk_01, arg0->unk_02);

    arg1->unk_03 = arg0->unk_04;
    arg1->unk_04 = arg0->unk_05;
    arg1->unk_05 = arg0->unk_06;
    arg1->unk_06 = arg0->unk_07;
    arg1->unk_07 = arg0->unk_08;

    func_80021A68(arg1->unk_0C, arg0->unk_0E);
    func_80021A78(arg1->unk_0E, arg0->unk_10);
    func_80021A68(arg1->unk_11, arg0->unk_14);
    func_80021A68(arg1->unk_13, arg0->unk_16);
    func_80021A68(arg1->unk_15, arg0->unk_18);
    func_80021A68(arg1->unk_17, arg0->unk_1A);
    func_80021A68(arg1->unk_19, arg0->unk_1C);
    func_80021A68(arg1->unk_1B, arg0->unk_1E);

    memcpy(arg1->unk_08, arg0->unk_09, 4);
    memcpy(arg1->unk_1D, arg0->unk_20, 4);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022010.s")

u16 func_80022084(u16 arg0) {
    u16 i;

    for (i = 1; i < 255; i++) {
        if (SQ(i) >= arg0) {
            break;
        }
    }
    return i;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800220C4.s")

#ifdef NON_MATCHING
u16 func_800220CC(s32 arg0, u16 arg1) {
    u16 sp6;

    switch (arg0) {
        case 1:
            sp6 = ((arg1 & 0x1000) >> 9) | ((arg1 & 0x100) >> 6) | ((arg1 & 0x10) >> 3) | (arg1 & 1);
            break;

        case 2:
            sp6 = (arg1 >> 0xC) & 0xF;
            break;

        case 3:
            sp6 = (arg1 >> 8) & 0xF;
            break;

        case 4:
            sp6 = (arg1 >> 4) & 0xF;
            break;

        case 5:
            sp6 = arg1 & 0xF;
            break;
    }

    return sp6;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800220CC.s")
#endif

#ifdef NON_MATCHING
u32 func_80022170(s32 arg0, s32 arg1, u16 arg2, u16 arg3, s32 arg4) {
    u16 sp1C;
    u16 sp24;
    u16 sp22;

    switch (arg0) {
        case 1:
            sp24 = D_80070F84[arg1].unk_06;
            break;

        case 2:
            sp24 = D_80070F84[arg1].unk_07;
            break;

        case 3:
            sp24 = D_80070F84[arg1].unk_08;
            break;

        case 4:
            sp24 = D_80070F84[arg1].unk_09;
            break;

        case 5:
            sp24 = D_80070F84[arg1].unk_0A;
            break;
    }

    sp22 = func_800220CC(arg0, arg4);

    sp1C = (((func_80022084(arg2) / 4) + ((sp24 + sp22) * 2)) * arg3) / 100;
    if (arg0 == 1) {
        sp1C += arg3 + 10;
    } else {
        sp1C += 5;
    }

    if (sp1C > 999) {
        sp1C = 999;
    }

    return sp1C;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022170.s")
#endif

void func_80022338(unk_func_80026268_arg0* arg0) {
    arg0->unk_24 = func_800226C0(arg0->unk_00, arg0->unk_10);
    arg0->unk_26 = func_80022170(1, arg0->unk_00, arg0->unk_14, arg0->unk_24, arg0->unk_1E);
    arg0->unk_28 = func_80022170(2, arg0->unk_00, arg0->unk_16, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2A = func_80022170(3, arg0->unk_00, arg0->unk_18, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2C = func_80022170(4, arg0->unk_00, arg0->unk_1A, arg0->unk_24, arg0->unk_1E);
    arg0->unk_2E = func_80022170(5, arg0->unk_00, arg0->unk_1C, arg0->unk_24, arg0->unk_1E);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_8002240C.s")

#ifdef NON_MATCHING
u32 func_800224B8(s32 arg0, u16 arg1) {
    u32 sp4;

    switch (D_80070F84[arg0].unk_13) {
        case 0:
            sp4 = arg1 * arg1 * arg1;
            break;

        case 1:
            sp4 = (((arg1 * arg1 * arg1 * 3) / 4) + (arg1 * 0xA * arg1)) - 0x1E;
            break;

        case 2:
            sp4 = (((arg1 * arg1 * arg1 * 3) / 4) + (arg1 * 0x14 * arg1)) - 0x1E;
            break;

        case 3:
            sp4 = ((((arg1 * arg1 * arg1 * 6) / 5) - (arg1 * 0xF * arg1)) + (arg1 * 0x64)) - 0x8C;
            break;

        case 4:
            sp4 = (arg1 * arg1 * arg1 * 4) / 5;
            break;

        case 5:
            sp4 = (arg1 * arg1 * arg1 * 5) / 4;
            break;
    }

    return sp4;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800224B8.s")
#endif

u16 func_800226C0(s32 arg0, u32 arg1) {
    s32 i;

    for (i = 1; i < 100; i++) {
        if (arg1 < func_800224B8(arg0, i + 1)) {
            break;
        }
    }

    return i;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022734.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800228B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800228F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022978.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022A04.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022A28.s")

u8 func_80022A38(s32 arg0) {
    if ((arg0 <= 0) || (arg0 > 151)) {
        return 0;
    }

    return D_80073267[arg0];
}

u8 func_80022A60(s32 arg0) {
    if ((arg0 <= 0) || (arg0 > 190)) {
        return 152;
    }

    return D_800732FF[arg0];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022A88.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022A98.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022AA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022ACC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022AF0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022B88.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022C28.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022CC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022D24.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022D8C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022DF4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022E18.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80022F24.s")

void func_80023068(void) {
    s32 sp1C = func_8002D5AC(0x11);

    HAL_Strcpy(D_800AC890[0], func_8002D7C0(NULL, 0, sp1C, 0));
    HAL_Strcpy(D_800AC890[1], func_8002D7C0(NULL, 0, sp1C, 1));
    HAL_Strcpy(D_800AC890[2], func_8002D7C0(NULL, 0, sp1C, 2));
    HAL_Strcpy(D_800AC890[3], func_8002D7C0(NULL, 0, sp1C, 3));
}

char* func_8002311C(s32 arg0) {
    return D_800AC890[arg0];
}

s32 func_80023130(u8* arg0) {
    s32 i;

    for (i = 0; i < 11; i++) {
        if (*arg0++ == 'P') {
            return 1;
        }
    }

    return 0;
}

s32 func_80023230(u8* arg0, u8* arg1) {
    s32 sp1C = 0;
    s32 sp18 = 0;

    if (func_80023130(arg0) != 0) {
        while (arg1 >= arg0) {
            sp18 += *arg0++;
        }
        sp1C = (sp18 & 0xFF) == 0xFF;
    }

    return sp1C;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800232A0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800232D0.s")

#ifdef NON_MATCHING
s8 func_80023324(s32 arg0) {
    // Only part of the rom header,
    // osGbpakReadId reads from 0x100 but this reads from 0x120
    typedef struct RomHeader {
        /* 0x00 */ char nintendo_chr[0x14];
        /* 0x14 */ char game_title[16];
        /* 0x24 */ u16 company_code;
        /* 0x26 */ u8 body_code;
        /* 0x27 */ u8 cart_type;
        /* 0x28 */ u8 rom_size;
        /* 0x29 */ u8 ram_size;
        /* 0x2A */ s8 country_code;
        /* 0x2B */ u8 fixed2;
        /* 0x2C */ u8 version;
        /* 0x2D */ u8 isum;
        /* 0x2E */ u16 sum;
        /* 0x30 */ char unk30[0x30];
    } RomHeader; // size = 0x60

    RomHeader sp28;
    s8 var_s0 = POKEMON_ROM_NONE;

    if ((func_8000B1C4(arg0, &sp28, 0x120, 0x60) == 0) && (sp28.country_code == 1)) {
        sp28.game_title[7] = '\x0';
        sp28.game_title[16] = '\x0';

        if (HAL_Strcmp(&sp28.game_title[0], "POKEMON") == 0) {
            if (HAL_Strcmp(&sp28.game_title[8], "RED") == 0) {
                var_s0 = POKEMON_ROM_RED;
            } else if (HAL_Strcmp(&sp28.game_title[8], "GREEN") == 0) {
                var_s0 = POKEMON_ROM_GREEN;
            } else if (HAL_Strcmp(&sp28.game_title[8], "BLUE") == 0) {
                var_s0 = POKEMON_ROM_BLUE;
            } else if (HAL_Strcmp(&sp28.game_title[8], "YELLOW") == 0) {
                var_s0 = POKEMON_ROM_YELLOW;
            }
        }
    }

    return var_s0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80023324.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800233F4.s")

s32 func_80023480(s32 arg0) {
    s32 i;
    s32 sp30;
    unk_D_800AC910_50* temp_s4 = D_800AC910[arg0].unk_50;

    sp30 = NULL;

    if (func_8000AEBC(arg0, temp_s4, 0x2580, 0xFC0) == 0) {
        for (i = 0; i < 3; i++) {
            sp30 = func_80023230(&temp_s4->unk_018, &temp_s4->unk_FA1);
            if (sp30 != 0) {
                if (D_800AC910[arg0].unk_00 & 0x20) {
                    D_800AC910[arg0].unk_04 = temp_s4->unk_FA1;
                    D_800AC910[arg0].unk_00 = D_800AC910[arg0].unk_00 & ~0x20;
                } else {
                    sp30 = D_800AC910[arg0].unk_04 == temp_s4->unk_FA1;
                }
                return sp30;
            }
        }
    }

    return sp30;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80023574.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80023658.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80023740.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800237C8.s")

void func_800238D8(UNUSED MainPoolBlock* arg0, u32 arg1) {
    unk_D_800AC910* ptr;

    if ((arg1 >= 'DAT0') && (arg1 < 'DAT4')) {
        ptr = D_800AC910 + (arg1 - 'DAT0');

        ptr->unk_50 = NULL;
        ptr->unk_00 &= ~0x9;
    } else if ((arg1 >= 'BOX0') && (arg1 < 'BOX4')) {
        ptr = D_800AC910 + (arg1 - 'BOX0');

        ptr->unk_54 = NULL;
        ptr->unk_00 &= ~0x12;
    }
}

void func_80023990(s32 arg0) {
    extern u8 D_80073640[12];

    s32 i;
    s32 temp_t1 = D_800AC910[arg0].unk_50->unk_08A;

    D_800AC910[arg0].unk_00 &= ~0x4000;

    for (i = 0; i < 12; i++) {
        if (D_80073640[i] == temp_t1) {
            D_800AC910[arg0].unk_00 |= 0x4000;
            break;
        }
    }
}

s32 func_80023A04(s32 arg0) {
    u8 sp2F;
    s32 sp28 = 0;

    if (D_800AC910[arg0].unk_00 & 1) {
        return 1;
    }

    D_800AC910[arg0].unk_50 = main_pool_alloc_with_func(0xFC0, 0, arg0 + 'DAT0', func_800238D8);

    if (D_800AC910[arg0].unk_50 != NULL) {
        D_800AC910[arg0].unk_00 |= 1;
        if (func_8000A798(arg0, &sp2F, D_800AC910[arg0].unk_019) == 0) {
            func_8002B274(arg0, 2);
        }

        sp28 = func_80023480(arg0);
        if (func_8000A888(arg0, sp2F) == 0) {
            func_8002B274(arg0, 2);
        }

        if (sp28 == 0) {
            main_pool_try_free(D_800AC910[arg0].unk_50);
        }
    }

    return sp28;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80023AF8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80023B7C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80023D60.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80023E34.s")

void func_80023F78(s32 arg0) {
    D_800AC910[arg0].unk_00 &= ~0x7000;

    if (func_80023A04(arg0) != 0) {
        func_80024FB0(arg0);
        func_80023990(arg0);
        D_800AC910[arg0].unk_05 = D_800AC910[arg0].unk_50->unk_9AC;

        if (D_800AC910[arg0].unk_50->unk_477 & 0x20) {
            D_800AC910[arg0].unk_00 |= 0x2000;
        }

        if (D_800AC910[arg0].unk_50->unk_51D & 1) {
            D_800AC910[arg0].unk_00 |= 0x1000;
        }

        D_800AC910[arg0].unk_03 = 0;
    } else {
        D_800AC910[arg0].unk_03 = 3;
    }
}

void func_80024040(s32 arg0) {
    if ((1 << arg0) & D_800ACA70) {
        D_800AC910[arg0].unk_00 |= 0x20;
        func_80023F78(arg0);
    }
}

#ifdef NON_MATHCING
s32 func_800240A0(void) {
    s32 i;
    s32 j;
    s32 temp_s2;
    s32 var_s1;
    s32 temp_v0;
    s8 temp_v0_2;
    unk_D_800AC910* var_s0;

    temp_v0 = func_8000AA7C();
    D_800ACA74 = temp_v0;
    D_800ACA75 = temp_v0 >> 0x10;
    D_800ACA70 = 0;

    for (i = 0; i < 4; i++) {
        var_s0 = &D_800AC910[i];

        var_s0->unk_00 = 0x20;
        var_s0->unk_50 = NULL;
        var_s0->unk_54 = NULL;
        var_s0->unk_03 = 1;
        var_s0->unk_02 = 0;
        var_s0->unk_05 = 0;

        var_s0->unk_40 = 0x5000;

        for (j = 0; j < 11; j++) {
            var_s0->unk_42[j] = '\x00';
        }
        /*
        var_s0->unk_42[0] = '\x00';
        var_s0->unk_42[1] = '\x00';
        var_s0->unk_42[2] = '\x00';
        var_s0->unk_42[3] = '\x00';
        var_s0->unk_42[4] = '\x00';
        var_s0->unk_42[5] = '\x00';
        var_s0->unk_42[7] = '\x00';
        var_s0->unk_42[8] = '\x00';
        var_s0->unk_42[9] = '\x00';
        var_s0->unk_42[10] = '\x00';
        */

        var_s0->unk_4D[0] = '\x00';
        var_s0->unk_4D[1] = '\x00';

        if (D_800ACA75 & (1 << i)) {
            var_s0->unk_03 = 2;
            var_s0->unk_02 = func_80023324(i);
            if (var_s0->unk_02 & 0xFF) {
                D_800ACA70 |= (1 << i);
                if (func_8000A6D8(i, var_s0->unk_019) == 0) {
                    func_8002B274(i, 2);
                }
                func_80023F78(i);
            }
            func_8000A888(i, 0);
        }
    }

    if (D_800ACA74 != 0) {
        func_8000B318(D_800ACA70);
    }

    return D_800ACA70;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800240A0.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024208.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024270.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_8002431C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800243D8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_8002447C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800244F4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024528.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024624.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800246F8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800247C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024884.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024948.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024978.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800249B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800249FC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024A48.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024AE0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024BC4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024CB0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024DAC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024EF4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024F00.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024F24.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024F68.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80024F8C.s")

s32 func_80024FB0(s32 arg0) {
    if (!(D_800AC910[arg0].unk_00 & 1)) {
        return 0;
    }

    D_800AC910[arg0].unk_40 = func_80021A30(&D_800AC910[arg0].unk_50->unk_085);
    _bcopy(&D_800AC910[arg0].unk_50->unk_018, &D_800AC910[arg0].unk_42, 0xB);
    bzero(D_800AC910[arg0].unk_4D, 3);
    return 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80025040.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80025084.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800250E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_8002513C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800251B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80025210.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_8002526C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800252CC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80025328.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80025370.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_8002539C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800253C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800253F4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80025498.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80025540.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_8002564C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_800256F4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80025840.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80025988.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/22630/func_80025AD0.s")
