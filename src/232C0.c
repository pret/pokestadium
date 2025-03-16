#include "232C0.h"
#include "src/26820.h"
#include "src/2E110.h"
#include "src/gb_tower.h"
#include "src/hal_libc.h"
#include "src/util.h"

extern unk_D_800AC910 D_800AC910[4];
extern u32 D_800ACA70;
extern u8 D_800ACA74;
extern u8 D_800ACA75;
extern unk_D_800AC910_050 D_800ACA78;

extern u8 D_80073267[];
extern u8 D_800732FF[];

extern char D_800AC890[][0x20];

u16 func_800226C0(s32 arg0, u32 arg1) {
    s32 i;

    for (i = 1; i < 100; i++) {
        if (arg1 < func_800224B8(arg0, i + 1)) {
            break;
        }
    }

    return i;
}

void func_80022734(unk_func_80026268_arg0* arg0) {
    extern unk_D_80072B00 D_80072B00[];

    s32 i;
    s32 temp_a3;
    s32 var_v0;
    s32 idx;

    func_80022338(arg0);
    arg0->unk_05 = 0;
    arg0->unk_02 = arg0->unk_26;

    for (i = 0; i < 4; i++) {
        if (arg0->unk_09[i] != 0) {
            temp_a3 = (arg0->unk_20[i] >> 6) & 3;
            var_v0 = D_80072B00[arg0->unk_09[i] - 1].unk_05;

            if (var_v0 >= 0x28) {
                var_v0 = var_v0 + (temp_a3 * 7);
            } else {
                var_v0 = var_v0 + ((var_v0 / 5) * temp_a3);
            }

            arg0->unk_20[i] = (temp_a3 << 6) + var_v0;
        }
    }
}

void func_800228B0(unk_func_80026268_arg0* arg0) {
    UNUSED s32 pad;
    char sp18[11];

    func_80021B7C(&sp18, &arg0->unk_3B);
    _bcopy(&sp18, arg0->unk_46, 0xB);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/232C0/func_800228F0.s")

void func_80022978(unk_func_80026268_arg0* arg0, s16 arg1, u8 arg2) {
    unk_D_800AE4E8_004_2_0DC0_002 sp24;

    if (arg2) {
        sp24.unk_00 = arg1 + 0x80;
    } else {
        sp24.unk_00 = arg1;
    }
    sp24.unk_01 = arg0->unk_24;
    sp24.unk_02 = arg0->unk_0E;
    func_80021B7C(sp24.unk_04, arg0->unk_30);
    func_80021B7C(sp24.unk_0F, arg0->unk_3B);
    func_80027C24(0x13, 0, arg0->unk_00.unk_00 - 1, &sp24);
}

s32 func_80022A04(u16* arg0, unk_D_800AC910_040* arg1) {
    return !bcmp(arg0, arg1, 0xD);
}

u8 func_80022A28(s32 arg0) {
    extern u8 D_80073230[];

    return D_80073230[arg0];
}

u8 func_80022A38(s32 arg0) {
    if ((arg0 <= 0) || (arg0 > 151)) {
        return 0;
    }

    return D_80073267[arg0];
}

s32 func_80022A60(s32 arg0) {
    if ((arg0 <= 0) || (arg0 > 190)) {
        return 152;
    }

    return D_800732FF[arg0];
}

u8 func_80022A88(s32 arg0) {
    extern u8 D_800733BF[];

    return D_800733BF[arg0];
}

u8 func_80022A98(s32 arg0) {
    extern u8 D_80073457[];

    return D_80073457[arg0];
}

s32 func_80022AA8(s32 arg0) {
    extern u8 D_800734EF[];

    if (arg0 == 0) {
        return 0;
    }
    return D_800734EF[arg0] + 1;
}

s32 func_80022ACC(s32 arg0) {
    extern u8 D_80073597[];

    if (arg0 == 0) {
        return 0;
    }

    return D_80073597[arg0] + 1;
}

void func_80022AF0(unk_func_80022C28_ret* arg0) {
    if (arg0->unk_00 == 1) {
        arg0->unk_04 |= 1;
        func_800276F0(arg0->unk_01, arg0->unk_03, 0);
    }

    arg0->unk_05 = func_80027108(arg0->unk_01);
    arg0->unk_06 = func_800270AC(arg0->unk_01);
    arg0->unk_08 = func_800275E0(arg0->unk_01, arg0->unk_03);

    if (arg0->unk_00 == 2) {
        arg0->unk_0A = arg0->unk_08;
    } else {
        arg0->unk_0A = 0;
    }
}

void func_80022B88(unk_func_80022C28_ret* arg0) {
    if (arg0->unk_00 == 1) {
        arg0->unk_04 |= 1;
        func_80024AE0(arg0->unk_01, arg0->unk_02, arg0->unk_03, 0);
    }

    arg0->unk_05 = func_800249FC(arg0->unk_01);
    arg0->unk_06 = func_800249B0(arg0->unk_01);
    arg0->unk_08 = func_80024A48(arg0->unk_01, arg0->unk_02, arg0->unk_03);

    if (arg0->unk_00 == 2) {
        arg0->unk_0A = arg0->unk_08;
    } else {
        arg0->unk_0A = 0;
    }
}

unk_func_80022C28_ret* func_80022C28(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    unk_func_80022C28_ret* sp1C;

    sp1C = Util_Malloc(sizeof(unk_func_80022C28_ret));
    if (sp1C != NULL) {
        sp1C->unk_00 = arg3;
        sp1C->unk_01 = arg0;
        sp1C->unk_02 = arg1;
        sp1C->unk_03 = arg2;
        sp1C->unk_04 = 0;

        switch (arg0 & 0xF0) {
            case 16:
                func_80022AF0(sp1C);
                break;

            case 32:
                func_80022B88(sp1C);
                break;
        }
    }

    return sp1C;
}

unk_func_80022C28_ret* func_80022CC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, char* arg4, u16 arg5) {
    unk_func_80022C28_ret* sp24;
    unk_func_80022C28_ret* temp_v0;
    unk_func_80022C28_ret* var_v1;

    sp24 = func_80022C28(arg0, arg1, arg2, 1);
    if ((sp24 != NULL) && (arg0 & 0xF0)) {
        func_80027430(arg0, arg2, arg3, arg4, arg5);
    }
    return sp24;
}

s32 func_80022D24(unk_func_80022C28_ret* arg0) {
    s32 sp1C = 0;

    if ((arg0->unk_01 & 0x10) && (arg0->unk_04 & 1)) {
        func_8002685C(arg0->unk_01, arg0->unk_03);
        sp1C = 1;
    }

    Util_Free(arg0);

    return sp1C;
}

s32 func_80022D8C(unk_func_80022C28_ret* arg0) {
    s32 sp1C = 0;

    if ((arg0->unk_01 & 0x10) && (arg0->unk_04 & 1)) {
        func_80026684(arg0->unk_01, arg0->unk_03);
        sp1C = 1;
    }

    Util_Free(arg0);

    return sp1C;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/232C0/func_80022DF4.s")

s32 func_80022E18(u8* arg0, s32 arg1, unk_func_80022C28_ret* arg2) {
    s32 var_s3;
    s32 var_s4;
    s32 var_v1;
    s32 tmp;

    var_s4 = 0;
    var_s3 = arg1 - 1;
    tmp = arg1 > 0;

    if (tmp) {}

    if (tmp != 0) {
        for (; arg2->unk_0A < arg2->unk_08;) {
            var_v1 = 0;
            switch (arg2->unk_01 & 0xF0) {
                case 16:
                    var_v1 = func_8002797C(arg2->unk_01, arg2->unk_03, arg2->unk_0A, arg0);
                    break;

                case 32:
                    var_v1 = func_80024CB0(arg2->unk_01, arg2->unk_02, arg2->unk_03, arg2->unk_0A, arg0);
                    break;
            }

            tmp = var_s3 > 0;
            if (var_v1 == 0) {
                break;
            }

            arg2->unk_0A++;
            var_s3 -= 1;
            var_s4 += 1;
            arg0 += arg2->unk_05;

            if (!tmp) {
                break;
            }
        }
    }
    return var_s4;
}

s32 func_80022F24(u8* arg0, s32 arg1, unk_func_80022C28_ret* arg2) {
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 tmp;

    var_s5 = 0;
    var_s4 = arg1 - 1;
    tmp = arg1 > 0;

    if (tmp) {}

    if (tmp) {
        for (; arg2->unk_0A < arg2->unk_06;) {
            var_s2 = 0;
            switch (arg2->unk_01 & 0xF0) {
                case 16:
                    var_s2 = func_80027C24(arg2->unk_01, arg2->unk_03, arg2->unk_0A, arg0);
                    arg2->unk_08 = func_800275E0(arg2->unk_01, arg2->unk_03);
                    break;

                case 32:
                    var_s2 = func_80024DAC(arg2->unk_01, arg2->unk_02, arg2->unk_03, arg2->unk_0A, arg0);
                    arg2->unk_08 = func_80024A48(arg2->unk_01, arg2->unk_02, arg2->unk_03);
                    break;
            }

            tmp = var_s4 > 0;
            if (var_s2 == 0) {
                break;
            }

            var_s4 -= 1;
            arg2->unk_0A++;
            var_s5 += 1;
            arg0 += arg2->unk_05;
            arg2->unk_04 |= 1;

            if (!tmp) {
                break;
            }
        }
    }

    return var_s5;
}

void func_80023068(void) {
    char** sp1C = func_8002D5AC(0x11);

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

void func_800232A0(u8* arg0, u8* arg1) {
    s32 var_v0 = 0;

    while (arg0 < arg1) {
        var_v0 += *arg0++;
    }

    *arg1 = 0xFF - (var_v0 & 0xFF);
}

s32 func_800232D0(u8* arg0, s32 arg1) {
    u8* var_v0 = D_800ACA78.unk_000;

    while (arg1-- > 0) {
        if (*arg0++ != *var_v0++) {
            return 0;
        }
    }

    return 1;
}

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

s32 func_800233F4(s32 arg0) {
    UNUSED s32 pad;
    s32 sp18 = 0;

    if ((func_8000AEBC(arg0, &D_800ACA78, 0x2580, sizeof(unk_D_800AC910_050)) == 0) &&
        (func_80023230(&D_800ACA78.unk_018, &D_800ACA78.unk_FA0.unk_03) != 0)) {
        sp18 = D_800ACA78.unk_FA0.unk_03 == D_800AC910[arg0].unk_04;
    }
    return sp18;
}

s32 func_80023480(s32 arg0) {
    s32 i;
    s32 sp30;
    unk_D_800AC910_050* temp_s4 = D_800AC910[arg0].unk_50;

    sp30 = NULL;

    if (func_8000AEBC(arg0, temp_s4, 0x2580, sizeof(unk_D_800AC910_050)) == 0) {
        for (i = 0; i < 3; i++) {
            sp30 = func_80023230(&temp_s4->unk_018, &temp_s4->unk_FA0.unk_03);
            if (sp30 != 0) {
                if (D_800AC910[arg0].unk_00 & 0x20) {
                    D_800AC910[arg0].unk_04 = temp_s4->unk_FA0.unk_03;
                    D_800AC910[arg0].unk_00 = D_800AC910[arg0].unk_00 & ~0x20;
                } else {
                    sp30 = D_800AC910[arg0].unk_04 == temp_s4->unk_FA0.unk_03;
                }
                return sp30;
            }
        }
    }

    return sp30;
}

s32 func_80023574(s32 arg0) {
    s32 i;
    unk_D_800AC910* temp_s3;
    unk_D_800AC910_050* temp_s1 = D_800AC910[arg0].unk_50;

    func_800232A0(temp_s1->unk_018, &temp_s1->unk_FA0.unk_03);
    D_800AC910[arg0].unk_04 = temp_s1->unk_FA0.unk_03;

    for (i = 0; i < 4; i++) {
        if ((func_8000AF40(arg0, temp_s1, 0x2580, sizeof(unk_D_800AC910_050)) == 0) &&
            (func_8000AEBC(arg0, &D_800ACA78, 0x2580, sizeof(unk_D_800AC910_050)) == 0) &&
            (func_800232D0(temp_s1, sizeof(unk_D_800AC910_050)) != 0)) {
            return 1;
        }
    }
    return 0;
}

s32 func_80023658(s32 arg0) {
    unk_D_800AC910_050* temp_s3 = D_800AC910[arg0].unk_50;
    s32 i;

    func_800232A0(&temp_s3->unk_018, &temp_s3->unk_FA0.unk_03);
    temp_s3->unk_FA0.unk_03 ^= 0xFF;

    for (i = 0; i < 4; i++) {
        if ((func_8000AF40(arg0, &temp_s3->unk_FA0, 0x3520, sizeof(unk_D_800AC910_050_FA0)) == 0) &&
            (func_8000AEBC(arg0, &D_800ACA78, 0x3520, sizeof(unk_D_800AC910_050_FA0)) == 0) &&
            (func_800232D0(&temp_s3->unk_FA0, sizeof(unk_D_800AC910_050_FA0)) != 0)) {
            return 1;
        }
    }
    return 0;
}

s32 func_80023740(s32 arg0, s32 arg1) {
    UNUSED s32 pad[2];
    unk_D_800AC910_054_000_000* sp1C = &D_800AC910[arg0].unk_54->unk_0000[arg1];

    return func_8000AEBC(arg0, sp1C, (arg1 == 0) ? 0x4000 : 0x6000, 0x1A60) == 0;
}

s32 func_800237C8(s32 arg0, s32 arg1) {
    s32 var_v0;
    unk_D_800AC910_054_000* temp_s2 = &D_800AC910[arg0].unk_54->unk_0000[arg1];
    s32 i;

    if (arg1 == 0) {
        var_v0 = 0x4000;
    } else {
        var_v0 = 0x6000;
    }

    var_v0 &= 0xFFFF;

    for (i = 0; i < 4; i++) {
        if ((func_8000AF40(arg0, temp_s2, var_v0, 0x1A60) == 0) &&
            (func_8000AEBC(arg0, &D_800ACA78, var_v0, 0x1A60) == 0) && (func_800232D0(temp_s2, 0x1A60) != 0)) {
            return 1;
        }
    }
    return 0;
}

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
        if (func_8000A798(arg0, &sp2F, D_800AC910[arg0].unk_19) == 0) {
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

s32 func_80023AF8(s32 arg0) {
    s32 sp1C = 0;

    if (((1 << arg0) & D_800ACA70) && (D_800AC910[arg0].unk_03 == 0)) {
        sp1C = func_80023A04(arg0);
        if (sp1C == 0) {
            func_8002B274(arg0, 2);
        }
    }

    return sp1C;
}

s32 func_80023B7C(s32 arg0) {
    u8 sp37;
    s32 i;
    s32 sp2C;

    sp2C = 0;

    if (!(D_800AC910[arg0].unk_00 & 1)) {
        return 0;
    }

    if (D_800AC910[arg0].unk_00 & 2) {
        return 1;
    }

    D_800AC910[arg0].unk_54 = main_pool_alloc_with_func(sizeof(unk_D_800AC910_054), 0, arg0 + 'BOX0', func_800238D8);

    if (D_800AC910[arg0].unk_54 != NULL) {
        D_800AC910[arg0].unk_00 |= 2;
        if (func_8002513C(arg0) > 0) {
            if (func_8000A798(arg0, &sp37, D_800AC910[arg0].unk_19) == 0) {
                func_8002B274(arg0, 2);
            }

            if (func_80023740(arg0, 0) != 0) {
                sp2C = func_80023740(arg0, 1);
            }

            if (func_8000A888(arg0, sp37) == 0) {
                func_8002B274(arg0, 2);
            }

            if (sp2C == 0) {
                main_pool_try_free(D_800AC910[arg0].unk_54);
            }
        } else {
            HAL_Memset(D_800AC910[arg0].unk_54, 0xFF, sizeof(unk_D_800AC910_054));

            for (i = 0; i < 6; i++) {
                D_800AC910[arg0].unk_54->unk_0000[0].unk_0000[i].unk_000.unk_000 = 0;
                D_800AC910[arg0].unk_54->unk_0000[1].unk_0000[i].unk_000.unk_000 = 0;
            }

            sp2C = 1;
        }
    }
    return sp2C;
}

s32 func_80023D60(s32 arg0) {
    u8 sp2F;
    s32 temp_s1 = 0;

    if ((1 << arg0) & D_800ACA70) {
        if (D_800AC910[arg0].unk_03 == 0) {
            if (func_8000A798(arg0, &sp2F, D_800AC910[arg0].unk_19) == 0) {
                func_8002B274(arg0, 2);
            }

            temp_s1 = func_80023AF8(arg0);
            temp_s1 &= func_80023B7C(arg0);

            if (func_8000A888(arg0, sp2F) == 0) {
                func_8002B274(arg0, 2);
            }

            if (temp_s1 != 0) {
                func_80025540(arg0);
            }
        }
    }

    return temp_s1;
}

s32 func_80023E34(s32 arg0) {
    extern u8 D_8007364C[];

    s32 sp24 = 0;

    switch (D_8007364C[arg0]) {
        case 0:
            func_8000A888(arg0, 0);
            D_8007364C[arg0] += 1;
            // fallthrough

        case 1:
            if (func_8000AC7C(arg0) != 0) {
                D_8007364C[arg0] += 1;
            }
            break;

        case 2:
            if (func_8000ACF4(arg0) != 0) {
                D_8007364C[arg0] += 1;
            }
            sp24 = 1;
            break;

        case 3:
            if (func_8000AD68(arg0) != 0) {
                sp24 = 3;
                if (func_80023324(arg0) == D_800AC910[arg0].unk_02) {
                    if (func_8000AE28(arg0, D_800AC910[arg0].unk_19) != 0) {
                        sp24 = 2;
                    }
                }
            }
            D_8007364C[arg0] = 0;
            break;
    }
    return sp24;
}

void func_80023F78(s32 arg0) {
    D_800AC910[arg0].unk_00 &= ~0x7000;

    if (func_80023A04(arg0) != 0) {
        func_80024FB0(arg0);
        func_80023990(arg0);
        D_800AC910[arg0].unk_05 = D_800AC910[arg0].unk_50->unk_9AC.unk_000;

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

s32 func_800240A0(void) {
    s32 i;
    s32 j;
    s32 temp_v0 = func_8000AA7C();

    D_800ACA74 = temp_v0 & 0xFF;
    D_800ACA75 = (temp_v0 >> 0x10) & 0xFF;
    D_800ACA70 = 0;

    for (i = 0; i < 4; i++) {
        unk_D_800AC910* var_s0 = &D_800AC910[i];
        u64* temp;

        var_s0->unk_00 = 0x20;
        var_s0->unk_50 = NULL;
        var_s0->unk_54 = NULL;
        var_s0->unk_03 = 1;
        var_s0->unk_02 = 0;
        var_s0->unk_05 = 0;

        temp = &var_s0->unk_40;
        *temp++ = 0x500000000000;
        *temp++ = 0;

        if (D_800ACA75 & (1 << i)) {
            var_s0->unk_03 = 2;
            var_s0->unk_02 = func_80023324(i);
            if (var_s0->unk_02) {
                D_800ACA70 |= (1 << i);
                if (func_8000A6D8(i, var_s0->unk_19) == 0) {
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

void func_80024208(s32 arg0) {
    u16 temp_v0 = func_80021A30(&D_800AC910[arg0].unk_50->unk_2CC);

    if (!(temp_v0 & 0x8000)) {
        func_80021A68(&D_800AC910[arg0].unk_50->unk_2CC, temp_v0 | 0x8000);
    }
}

s32 func_80024270(s32 arg0) {
    u8 sp2F;
    s32 sp28 = 0;

    if (D_800AC910[arg0].unk_00 & 2) {
        if (func_8000A798(arg0, &sp2F, D_800AC910[arg0].unk_19) == 0) {
            func_8002B274(arg0, 2);
        }

        sp28 = func_800237C8(arg0, 0);

        if (sp28 != 0) {
            sp28 = func_800237C8(arg0, 1);
        }
        sp28 &= func_8000A888(arg0, sp2F);
    }
    return sp28;
}

s32 func_8002431C(s32 arg0) {
    u8 sp2F;
    s32 sp28 = 0;

    if (D_800AC910[arg0].unk_00 & 1) {
        if (func_8000A798(arg0, &sp2F, D_800AC910[arg0].unk_19) == 0) {
            func_8002B274(arg0, 2);
        }

        sp28 = func_80023574(arg0);
        sp28 &= func_8000A888(arg0, sp2F);

        if (sp28 != 0) {
            func_80024FB0(arg0);
            D_800AC910[arg0].unk_05 = D_800AC910[arg0].unk_50->unk_9AC.unk_000;
        }
    }
    return sp28;
}

s32 func_800243D8(s32 arg0) {
    u8 sp2F;
    s32 sp28;

    if (func_8000A798(arg0, &sp2F, D_800AC910[arg0].unk_19) == 0) {
        func_8002B274(arg0, 2);
    }

    sp28 = func_80023658(arg0);

    if (sp28 != 0) {
        sp28 = func_80024270(arg0);
        if (sp28 != 0) {
            sp28 = func_8002431C(arg0);
        }
    }

    sp28 &= func_8000A888(arg0, sp2F);
    return sp28;
}

void func_8002447C(s32 arg0) {
    u8 sp27;

    if (func_8000A798(arg0, &sp27, D_800AC910[arg0].unk_19) == 0) {
        func_8002B274(arg0, 2);
    }

    if (func_800233F4(arg0) == 0) {
        func_8002B274(arg0, 1);
    }
}

void func_800244F4(s32 arg0) {
    if (func_8000A888(arg0, 0) == 0) {
        func_8002B274(arg0, 2);
    }
}

unk_D_800AC910_050_B40_000* func_80024528(s32 arg0, s32 arg1) {
    unk_D_800AC910_050_B40_000* sp1C = NULL;
    s32 temp_v0 = func_8002513C(arg0);

    if (temp_v0 > 0) {
        if (arg1 == (temp_v0 - 1)) {
            sp1C = &D_800AC910[arg0].unk_50[0].unk_B40;
        } else if (arg1 < 6) {
            sp1C = &D_800AC910[arg0].unk_54->unk_0000[0].unk_0000[arg1].unk_000;
        } else {
            sp1C = &D_800AC910[arg0].unk_54->unk_0000[0].unk_0000[arg1].unk_014;
        }
    }
    return sp1C;
}

void func_80024624(unk_func_80026268_arg0* arg0, s32 arg1, s32 arg2) {
    unk_D_800AC910_050_9AC* ptr2 = &D_800AC910[arg1].unk_50->unk_9AC;

    func_80021E90(arg0, &ptr2->unk_008[arg2]);
    func_80022338(arg0);

    arg0->unk_52 = 0;
    arg0->unk_53 = 0;
    arg0->unk_25 = 0;

    _bcopy(ptr2->unk_110[arg2], arg0->unk_46, 0xB);
    func_80021C40(arg0->unk_30, ptr2->unk_152[arg2]);
    func_80021C40(arg0->unk_3B, ptr2->unk_110[arg2]);
}

void func_800246F8(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2) {
    unk_D_800AC910_050_9AC* sp24 = &D_800AC910[arg1].unk_50->unk_9AC;

    func_80022010(arg0, &sp24->unk_008[arg2]);
    func_80021B7C(sp24->unk_152[arg2], arg0->unk_000[0].unk_30);
    _bcopy(arg0->unk_000[0].unk_46, sp24->unk_110[arg2], 0xB);
    sp24->unk_001[arg2] = sp24->unk_008[arg2].unk_00.unk_00;
}

void func_800247C4(unk_func_80026268_arg0* arg0, s32 arg1, s32 arg2, s32 arg3) {
    unk_D_800AC910_050_B40* sp2C = (unk_D_800AC910_050_B40*)func_80024528(arg1, arg2);

    if (sp2C != NULL) {
        func_80021D9C(arg0, &sp2C->unk_016[arg3]);
        func_80022338(arg0);

        arg0->unk_52 = 0;
        arg0->unk_53 = 0;
        arg0->unk_25 = 0;

        _bcopy(sp2C->unk_2AA[arg3], arg0->unk_46, 0xB);
        func_80021C40(arg0->unk_30, sp2C->unk_386[arg3]);
        func_80021C40(arg0->unk_3B, sp2C->unk_2AA[arg3]);
    }
}

void func_80024884(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3) {
    unk_D_800AC910_050_B40* sp2C = func_80024528(arg1, arg2);

    if (sp2C != NULL) {
        arg0->unk_000[0].unk_04 = arg0->unk_000[0].unk_24;
        func_80021F04(arg0->unk_000, &sp2C->unk_016[arg3]);
        func_80021C20(sp2C->unk_386[arg3], arg0->unk_000[0].unk_30);
        _bcopy(arg0->unk_000[0].unk_46, sp2C->unk_2AA[arg3], 0xB);
        sp2C->unk_000.unk_001[arg3] = sp2C->unk_016[arg3].unk_00;
    }
}

s32 func_80024948(s32 arg0, s32 arg1) {
    s32 sp1C = 0;
    unk_D_800AC910_050_B40_000* temp_v0 = func_80024528(arg0, arg1);

    if (temp_v0 != NULL) {
        sp1C = temp_v0->unk_000;
    }
    return sp1C;
}

void func_80024978(s32 arg0, s32 arg1, s32 arg2) {
    unk_D_800AC910_050_B40_000* temp_v0 = func_80024528(arg0, arg1);

    if (temp_v0 != NULL) {
        temp_v0->unk_000 = arg2;
        temp_v0->unk_001[arg2] = 0xFF;
    }
}

s32 func_800249B0(s32 arg0) {
    s32 ret = 0;

    switch (arg0) {
        case 32:
            ret = 6;
            break;

        case 33:
            ret = 0x1E;
            break;

        case 34:
            ret = 0x32;
            break;

        case 35:
            ret = 0x14;
            break;
    }

    return ret;
}

s32 func_800249FC(s32 arg0) {
    s32 ret = 0;

    switch (arg0) {
        case 32:
            ret = 0x54;
            break;
        case 33:
            ret = 0x54;
            break;
        case 34:
            ret = 2;
            break;
        case 35:
            ret = 2;
            break;
    }
    return ret;
}

s32 func_80024A48(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;
    unk_D_800AC910_050* ptr = D_800AC910[arg1].unk_50;

    switch (arg0) {
        case 32:
            var_v1 = ptr->unk_9AC.unk_000;
            break;

        case 33:
            var_v1 = func_80024948(arg1, arg2);
            break;

        case 34:
            var_v1 = ptr->unk_266;
            break;

        case 35:
            var_v1 = ptr->unk_049;
            break;
    }
    return var_v1;
}

void func_80024AE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    unk_D_800AC910_050* sp1C = D_800AC910[arg1].unk_50;

    if (arg3 < func_80024A48(arg0, arg1, arg2)) {
        switch (arg0) {
            case 32:
                sp1C->unk_9AC.unk_000 = arg3;
                sp1C->unk_9AC.unk_001[arg3] = 0xFF;
                break;

            case 33:
                func_80024978(arg1, arg2, arg3);
                break;

            case 34:
                sp1C->unk_266 = arg3;
                sp1C->unk_267[arg3].unk_00 = 0xFF;
                break;

            case 35:
                sp1C->unk_049 = arg3;
                sp1C->unk_04A[arg3].unk_00 = 0xFF;
                break;
        }
    }
}

void func_80024BC4(s32 arg0, s32 arg1, s32 arg2) {
    unk_D_800AC910_050* sp1C = D_800AC910[arg1].unk_50;
    s32 sp18 = func_80024A48(arg0, arg1, arg2);

    if (sp18 < func_800249B0(arg0)) {
        sp18++;

        switch (arg0) {
            case 32:
                sp1C->unk_9AC.unk_000 = sp18;
                sp1C->unk_9AC.unk_001[sp18] = 0xFF;
                break;

            case 33:
                func_80024978(arg1, arg2, sp18);
                break;

            case 34:
                sp1C->unk_266 = sp18;
                sp1C->unk_267[sp18].unk_00 = 0xFF;
                break;

            case 35:
                sp1C->unk_049 = sp18;
                sp1C->unk_04A[sp18].unk_00 = 0xFF;
                break;
        }
    }
}

s32 func_80024CB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_80026268_arg0* arg4) {
    s32 sp1C = 0;

    if (arg3 < func_80024A48(arg0, arg1, arg2)) {
        unk_D_800AC910_050* temp_v0 = D_800AC910[arg1].unk_50;

        switch (arg0) {
            case 32:
                func_80024624(arg4, arg1, arg3);
                break;

            case 33:
                func_800247C4(arg4, arg1, arg2, arg3);
                break;

            case 35:
                arg4->unk_00 = temp_v0->unk_04A[arg3];
                break;

            case 34:
                arg4->unk_00 = temp_v0->unk_267[arg3];
                break;
        }
        sp1C = 1;
    }
    return sp1C;
}

s32 func_80024DAC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_88205880_00D0* arg4) {
    s32 sp2C = 0;
    s32 sp28 = func_800249B0(arg0);
    s32 sp24 = func_80024A48(arg0, arg1, arg2);

    if ((arg3 < sp24) || ((arg3 == sp24) && (arg3 < sp28))) {
        unk_D_800AC910_050* ptr = D_800AC910[arg1].unk_50;

        switch (arg0) {
            case 32:
                func_800246F8(arg4, arg1, arg3);
                break;

            case 33:
                func_80024884(arg4, arg1, arg2, arg3);
                break;

            case 35:
                ptr->unk_04A[arg3] = arg4->unk_000[0].unk_00;
                break;

            case 34:
                ptr->unk_267[arg3] = arg4->unk_000[0].unk_00;
                break;
        }

        if (arg3 == sp24) {
            func_80024BC4(arg0, arg1, arg2);
        }

        sp2C = 1;
    }
    return sp2C;
}

s32 func_80024EF4(void) {
    return D_800ACA70;
}

s32 func_80024F00(s32 arg0) {
    return D_800AC910[arg0].unk_03;
}

s32 func_80024F24(s32 arg0) {
    s32 temp_v0 = 1 << arg0;

    if (!(D_800ACA74 & temp_v0)) {
        return 1;
    }

    if (!(D_800ACA75 & temp_v0)) {
        return 2;
    }

    return 0;
}

s32 func_80024F68(s32 arg0) {
    return D_800AC910[arg0].unk_02;
}

s32 func_80024F8C(s32 arg0) {
    return D_800AC910[arg0].unk_05;
}

s32 func_80024FB0(s32 arg0) {
    if (!(D_800AC910[arg0].unk_00 & 1)) {
        return 0;
    }

    D_800AC910[arg0].unk_40.unk_00 = func_80021A30(&D_800AC910[arg0].unk_50->unk_085);
    _bcopy(&D_800AC910[arg0].unk_50->unk_018, &D_800AC910[arg0].unk_40.unk_02, 0xB);
    bzero(D_800AC910[arg0].unk_40.unk_0D, 3);
    return 1;
}

void func_80025040(s32 arg0, unk_D_800AC910_040* arg1) {
    u64* ptr = &D_800AC910[arg0].unk_40;
    u64* ptr2 = arg1;

    *ptr2++ = *ptr++;
    *ptr2++ = *ptr++;
}

s32 func_80025084(s32 arg0) {
    if (!(D_800AC910[arg0].unk_00 & 1)) {
        return -1;
    }
    return func_80021A30(&D_800AC910[arg0].unk_50->unk_085);
}

void func_800250E0(s32 arg0, u16 arg1) {
    if (D_800AC910[arg0].unk_00 & 1) {
        func_80021A68(&D_800AC910[arg0].unk_50->unk_085, arg1);
    }
}

s32 func_8002513C(s32 arg0) {
    s32 temp_a0;
    s32 phi_v1 = -1;

    if (D_800AC910[arg0].unk_00 & 1) {
        temp_a0 = func_80021A30(&D_800AC910[arg0].unk_50->unk_2CC) >> 8;
        if (temp_a0 & 0x80) {
            phi_v1 = (temp_a0 & 0x7F) + 1;
        } else {
            phi_v1 = 0;
        }
    }
    return phi_v1;
}

char* func_800251B0(s32 arg0, char* arg1) {
    if (!(D_800AC910[arg0].unk_00 & 1)) {
        return NULL;
    }
    return func_80021C40(arg1, &D_800AC910[arg0].unk_50->unk_018);
}

char* func_80025210(s32 arg0, char* arg1) {
    if (!(D_800AC910[arg0].unk_00 & 1)) {
        return NULL;
    }
    return func_80021B7C(&D_800AC910[arg0].unk_50->unk_018, arg1);
}

char* func_8002526C(s32 arg0, char* arg1) {
    if (!(D_800AC910[arg0].unk_00 & 1)) {
        return NULL;
    }
    return func_80021C40(arg1, &D_800AC910[arg0].unk_50->unk_076);
}

char* func_800252CC(s32 arg0, char* arg1) {
    if (!(D_800AC910[arg0].unk_00 & 1)) {
        return NULL;
    }
    return func_80021B7C(&D_800AC910[arg0].unk_50->unk_076, arg1);
}

s32 func_80025328(s32 arg0) {
    if (!(D_800AC910[arg0].unk_00 & 1)) {
        return -1;
    }
    return D_800AC910[arg0].unk_50->unk_441;
}

s32 func_80025370(s32 arg0) {
    return (D_800AC910[arg0].unk_00 & 0x4000) != 0;
}

s32 func_8002539C(s32 arg0) {
    return (D_800AC910[arg0].unk_00 & 0x2000) != 0;
}

s32 func_800253C8(s32 arg0) {
    return (D_800AC910[arg0].unk_00 & 0x1000) != 0;
}

s32 func_800253F4(s32 arg0, func_800253F4_arg1* arg1) {
    s32 temp_v1 = (D_800AC910[arg0].unk_00 & 1) != 0;

    if (temp_v1 != 0) {
        arg1->unk_000 = D_800AC910[arg0].unk_02;
        arg1->unk_001 = D_800AC910[arg0].unk_04;
        arg1->unk_002 = D_800AC910[arg0].unk_40.unk_00;

        _bcopy(D_800AC910[arg0].unk_40.unk_02, arg1->unk_004, sizeof(arg1->unk_004));
        _bcopy(&D_800AC910[arg0].unk_50->unk_9AC, (u8*)arg1 + 0xF, sizeof(unk_D_800AC910_050_9AC));
    }
    return temp_v1;
}

void func_80025498(char* arg0, s32 arg1, u8* arg2) {
    s32 temp_v0;
    s32 h;

    while (arg1-- > 0) {
        temp_v0 = func_80022A60(*arg2++);
        if (0x98 != temp_v0) {
            temp_v0++;
            temp_v0--;
            temp_v0--;
            h = temp_v0 / 8;
            arg0[h] |= (1 << (temp_v0 % 8));
        }
    }
}

void func_80025540(s32 arg0) {
    unk_D_800AC910* ptr = &D_800AC910[arg0];
    unk_D_800AC910_050* temp_s0 = ptr->unk_50;
    u8* ptr6 = ptr->unk_06;
    unk_D_800AC910_054_000* ptr541 = &ptr->unk_54->unk_0000[0];
    unk_D_800AC910_054_000* ptr542 = &ptr->unk_54->unk_0000[1];
    s32 i;

    for (i = 0; i < 19; i++) {
        ptr6[i] = 0;
    }

    func_80025498(ptr6, temp_s0->unk_9AC.unk_000, temp_s0->unk_9AC.unk_001);
    func_80025498(ptr6, temp_s0->unk_B40.unk_000.unk_000, temp_s0->unk_B40.unk_000.unk_001);

    for (i = 0; i < 6; i++) {
        func_80025498(ptr6, ptr541->unk_0000[i].unk_000.unk_000, ptr541->unk_0000[i].unk_000.unk_001);
        func_80025498(ptr6, ptr542->unk_0000[i].unk_000.unk_000, ptr542->unk_0000[i].unk_000.unk_001);
    }
}

s32 func_8002564C(s32 arg0, s32 arg1) {
    s32 temp_t1;
    s32 temp_t2;
    u8* ptr23;
    u8* ptr36;

    if ((arg1 > 0) && (arg1 < 0x98)) {
        ptr23 = D_800AC910[arg0].unk_50->unk_023;
        ptr36 = D_800AC910[arg0].unk_50->unk_036;

        temp_t1 = (arg1 - 1) / 8;
        temp_t2 = (arg1 - 1) % 8;

        return ((ptr23[temp_t1] >> temp_t2) & 1) + ((ptr36[temp_t1] >> temp_t2) & 1) +
               ((D_800AC910[arg0].unk_06[temp_t1] >> temp_t2) & 1);
    }
    return 0;
}

void func_800256F4(s32 arg0, s32 arg1, s32 arg2) {
    u8* temp_a3;
    u8* temp_v0;
    s32 var_a2;
    s32 var_a3;
    u8* temp_v1;

    if ((arg1 > 0) && (arg1 < 0x98)) {
        temp_v0 = D_800AC910[arg0].unk_50->unk_023;
        temp_a3 = D_800AC910[arg0].unk_50->unk_036;
        temp_v1 = &D_800AC910[arg0].unk_06;

        var_a2 = (arg1 - 1) / 8;
        var_a3 = (arg1 - 1) % 8;

        if (arg2 > 0) {
            temp_a3[var_a2] |= (1 << var_a3);
        } else {
            temp_a3[var_a2] &= ~(1 << var_a3);
        }

        if (arg2 >= 2) {
            temp_v0[var_a2] |= (1 << var_a3);
        } else {
            temp_v0[var_a2] &= ~(1 << var_a3);
        }

        if (arg2 >= 3) {
            temp_v1[var_a2] |= (1 << var_a3);
        } else {
            temp_v1[var_a2] &= ~(1 << var_a3);
        }
    }
}

s32 func_80025840(s32 arg0) {
    s32 i;
    s32 temp_v1 = 0;

    for (i = 0; i < 0x97; i++) {
        temp_v1 += (D_800AC910[arg0].unk_50->unk_036[i / 8] >> (i % 8)) & 1;
    }

    return temp_v1;
}

s32 func_80025988(s32 arg0) {
    s32 i;
    s32 temp_v1 = 0;

    for (i = 0; i < 0x97; i++) {
        temp_v1 += (D_800AC910[arg0].unk_50->unk_023[i / 8] >> (i % 8)) & 1;
    }

    return temp_v1;
}

s32 func_80025AD0(s32 arg0) {
    s32 i;
    s32 temp_v1 = 0;

    for (i = 0; i < 0x97; i++) {
        temp_v1 += (D_800AC910[arg0].unk_06[i / 8] >> (i % 8)) & 1;
    }

    return temp_v1;
}
