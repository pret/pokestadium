#include "global.h"
#include "1C720.h"
#include "11BA0.h"
#include "17300.h"
#include "E890.h"
#include "18140.h"
#include "32D10.h"
#include "22630.h"
#include "dp_intro.h"
#include "hal_libc.h"

void func_8001BB20(void) {
    func_8001103C(0, &D_800AC840);
    func_8001103C(0, &D_800AC858);
}

void func_8001BB58(unk_D_86002F58_004_000* arg0) {
    func_80011938(NULL, arg0, 0, &D_8006F050, &D_8006F05C, &D_8006F064);
    func_80012094(&D_800AC840, &arg0->unk_000);
    arg0->unk_0A6 = 0;
    arg0->unk_000.unk_01 &= ~1;
}

void func_8001BBC8(unk_D_86002F58_004_000* arg0) {
    func_80011938(NULL, arg0, 0, &D_8006F050, &D_8006F05C, &D_8006F064);
    func_80012094(&D_800AC858, &arg0->unk_000);
    arg0->unk_000.unk_01 &= ~1;
}

void func_8001BC34(unk_D_86002F58_004_000* arg0, s16 arg1, s16 arg2, unk_D_86002F58_004_000_004* arg3) {
    func_80012094(&arg0->unk_000, arg3);
    func_8000ED98(&arg0->unk_060);
    arg0->unk_018 = arg1;
    arg0->unk_01A = arg2;

    arg0->unk_01D = 0xFF;
    arg0->unk_01C = 0;

    arg0->unk_000.unk_01 |= 0x1;

    arg0->unk_000.unk_02 &= ~0x4;
    arg0->unk_000.unk_02 |= 0x20;
    arg0->unk_000.unk_02 |= 0x40;
    arg0->unk_000.unk_02 &= ~0x2;

    arg0->unk_0A0 = -0x100;
    arg0->unk_03C = -0x100;
    arg0->unk_040 = -1;
    arg0->unk_044 = 0;
    arg0->unk_054 = -1;
    arg0->unk_058 = 0;

    arg0->unk_000.unk_02 &= ~0x8;

    if (arg2 > 0) {
        func_8003260C(arg0);
    }
}

void func_8001BCF0(unk_D_86002F58_004_000* arg0) {
    arg0->unk_000.unk_0C = NULL;
    arg0->unk_000.unk_01 &= ~1;
}

s32 func_8001BD04(unk_D_86002F58_004_000* arg0, s32 arg1) {
    unk_D_86002F58_004_000_00C* tmp = arg0->unk_000.unk_0C;
    unk_D_86002F58_004_000_00C_028* temp_v0 = tmp->unk_28(0, 0);

    if (arg1 == -1) {
        func_800173CC(arg0);
    } else if (arg1 < temp_v0->unk_04) {
        func_800173DC(arg0, arg1, temp_v0->unk_0C[arg1], 0x10000);
        return 1;
    }

    return 0;
}

s32 func_8001BD9C(unk_D_86002F58_004_000* arg0, s32 arg1) {
    unk_D_86002F58_004_000_00C* temp_v0 = arg0->unk_000.unk_0C;
    unk_D_86002F58_004_000_00C_028* temp_v1 = temp_v0->unk_28(0, 0);

    if (arg1 == -1) {
        func_80017788(arg0);
    } else if (arg1 < temp_v1->unk_05) {
        func_80017798(arg0, arg1, temp_v1->unk_10[arg1], arg1);
        return 1;
    }

    return 0;
}

void func_8001BE34(unk_D_86002F58_004_000* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    func_8000E840(&arg0->unk_0A0, arg1, arg2, arg3, arg4);
}

void func_8001BE78(unk_D_86002F58_004_000* arg0, u8 arg1) {
    arg0->unk_01D = arg1;
}

void func_8001BE84(unk_D_86002F58_004_000* arg0, u8 arg1) {
    arg0->unk_01C = arg1;
}

unk_D_86002F58_004_000_00C_028* func_8001BE90(unk_D_86002F58_004_000* arg0, s32 arg1) {
    unk_D_86002F58_004_000_00C_028* var_v1 = NULL;

    if (arg0 == NULL) {
        arg0 = D_8006F09C;
    }

    if (arg0 != NULL) {
        unk_D_86002F58_004_000_00C* tmp = arg0->unk_000.unk_0C;

        var_v1 = tmp->unk_28(arg1, 0);
    }

    return var_v1;
}

#ifdef NON_MATCHING
void func_8001BEE8(s32* arg0, unk_func_8001BEE8* arg1) {
    char sp38[0xB];
    s32 sp34;
    unk_D_8006FF00* sp30;
    UNUSED unk_func_8001BEE8* sp20;
    UNUSED s32 i;
    u8 var_a0;
    char* var_v1;
    s8 t;
    s32* test;
    test = arg0;

    sp30 = &D_8006FF00[arg1->unk_00 - 1];
    sp34 = 0;

    func_80021CA4(sp38, arg1->unk_00);

    if (HAL_Strcmp(arg1->unk_30, sp38) != 0) {
        var_a0 = (arg1->unk_0E >> 8) + arg1->unk_0E;

        var_v1 = arg1->unk_30;
        while (*var_v1 != 0) {
            t = *var_v1++;
            var_a0 += t;
        }

        var_v1 = arg1->unk_3B;
        while (*var_v1 != 0) {
            t = *var_v1++;
            var_a0 += t;
            do {
                var_a0 += t;
            } while (0);
        }

        *(s16*)&sp34 = ((((sp30->unk_12 - sp30->unk_10) << 6) * var_a0) / 255) + (sp30->unk_10 << 6);
    }

    *test = sp34;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/1C720/func_8001BEE8.s")
#endif

void func_8001C014(s32* arg0, unk_func_8001C014* arg1, u16 arg2) {
    unk_func_8001BEE8 stack;

    stack.unk_00 = arg2;
    stack.unk_0E = arg1->unk_02;

    _bcopy(arg1->unk_04, stack.unk_30, 0x10);
    _bcopy(arg1->unk_14, stack.unk_3B, 0x10);
    func_8001BEE8(arg0, &stack);
}

#ifdef NON_MATCHING
typedef struct stack_func_8001C07C {
    /* 0x00 */ s32 unk_00;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0C */ s32 unk_0C;
} stack_func_8001C07C; // size == 0x30

void func_8001C07C(unk_func_8001C07C_arg0* arg0) {
    stack_func_8001C07C stack;

    stack.unk_08 = arg0->unk_02;
    stack.unk_0C = 0;

    if (!(arg0->unk_00 & 0x40) && (arg0->unk_00 & 0x80)) {
        if (arg0->unk_04 != NULL && stack.unk_08 == arg0->unk_04->unk_00) {
            func_8001BEE8(&stack.unk_0C, arg0->unk_04);
            if ((stack.unk_08 == 0x19) && (arg0->unk_04->unk_52 & 0x80)) {
                stack.unk_08 = 0x99;
            }
        }

        if (!(arg0->unk_10->unk_00 & 4)) {
            while (func_80001C90() == 0) {}
        }

        stack.unk_00 = stack.unk_0C;
        func_800198E4(arg0->unk_10, stack.unk_08, stack.unk_0C);

        arg0->unk_00 |= 0x40;
        arg0->unk_00 &= ~0x10;

        if (arg0->unk_00 & 0x20) {
            func_80019CA8(arg0->unk_10);
            arg0->unk_14 = arg0->unk_10->unk_24;
            arg0->unk_00 &= ~0xE0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/1C720/func_8001C07C.s")
#endif

void func_8001C198(unk_func_8001C248* arg0) {
    if (func_80019C08(arg0->unk_010, arg0)) {
        arg0->unk_014 = arg0->unk_010->unk_24;
        arg0->unk_000 &= ~0xE0;
        arg0->unk_000 |= 0x10;
    }
}

void func_8001C1E8(unk_func_8001C248* arg0) {
    if (arg0->unk_000 & 0x40 && func_80019CA8(arg0->unk_010) != 0) {
        arg0->unk_014 = arg0->unk_010->unk_24;
        arg0->unk_000 &= ~0xE0;
        arg0->unk_000 |= 0x10;
    }
}

void func_8001C248(unk_func_8001C248* arg0) {
    if (!(arg0->unk_01D & 0x40) && (arg0->unk_01D & 0x80)) {
        func_80019A7C(arg0->unk_010, arg0->unk_020, arg0->unk_024, arg0);
        arg0->unk_01D |= 0x40;
        arg0->unk_01D &= ~0x10;
        if (arg0->unk_01D & 0x20) {
            func_80019CE0(arg0->unk_010);
            arg0->unk_024 = arg0->unk_010->unk_28;
            arg0->unk_01D &= ~0xE0;
        }
    }
}

void func_8001C2D8(unk_func_8001C248* arg0) {
    if (func_80019C58(arg0->unk_010, arg0) != 0) {
        arg0->unk_024 = arg0->unk_010->unk_28;
        arg0->unk_01D &= ~0xE0;
        arg0->unk_01D |= 0x10;
    }
}
