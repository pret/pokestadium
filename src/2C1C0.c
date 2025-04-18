#include "2C1C0.h"
#include "src/22630.h"
#include "src/232C0.h"
#include "src/26820.h"
#include "src/2C1C0.h"
#include "src/3FB0.h"
#include "src/hal_libc.h"
#include "src/math_util.h"
#include "src/memory.h"
#include "src/controller.h"

u8 D_80075680[3] = { 1, 15, 30 };
static s16 D_80075684 = 0;

void func_8002B5C0(unk_D_800AE540_1194* arg0) {
    arg0->unk_00 = 0;
    arg0->unk_01 = 0;
    arg0->unk_02 = 0;
    arg0->unk_04 = 0;
    arg0->unk_14 = 0;
    arg0->unk_08[0] = 0;
    arg0->unk_08[1] = 0;
    arg0->unk_1D = 0;
    arg0->unk_20 = 0;
    arg0->unk_1E = 0;
}

void func_8002B5EC(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 j;

    func_8002B5C0(&D_800AE540.unk_1194[0]);
    func_8002B5C0(&D_800AE540.unk_1194[1]);

    D_800AE540.unk_0000 = arg0;
    D_800AE540.unk_0001 = arg1;
    D_800AE540.unk_0002 = arg2;
    D_800AE540.unk_0003 = 1;

    D_800AE540.unk_11ED = 0;
    D_800AE540.unk_11EE = 0;
    D_800AE540.unk_11EF = 0;
    D_800AE540.unk_11F4 = 0;
    D_800AE540.unk_11F5 = 0;
    D_800AE540.unk_11F3 = 0;
    D_800AE540.unk_11F6 = 0;
    D_800AE540.unk_11EC = 0;

    for (i = 0; i < 4; i++) {
        D_800AE540.unk_0004[i].unk_000 = 0;
    }

    for (i = 0; i < 2; i++) {
        if (1) {
            for (j = 0; j < 4; j++) {
                D_800AE540.unk_11E4[i][j] = 0xFF;
            }
        }
    }
}

void func_8002B6BC(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_800AE540.unk_11E4[i][j] = 0xFF;
        }
    }

    D_800AE540.unk_0003 = 1;
    D_800AE540.unk_11F3 = 0;
}

unk_D_800AE540_0004* func_8002B700(s32 arg0, s16 arg1, char* arg2, char* arg3) {
    s32 i;
    unk_D_800AE540_0874* sp20;
    unk_D_800AE540_0004* sp1C = NULL;

    for (i = 0; i < 4; i++) {
        if ((D_800AE540.unk_0004 + i)->unk_000 == 0) {
            sp1C = &D_800AE540.unk_0004[i];
            sp20 = &D_800AE540.unk_0874[i];
            break;
        }
    }

    if (sp1C != NULL) {
        if (arg0 == -1) {
            sp1C->unk_000 = 3;
            sp1C->unk_001 = 1;
            sp1C->controller = &gControllers[0];
        } else {
            sp1C->unk_000 = 1;
            sp1C->unk_001 = arg0;
            sp1C->controller = &gControllers[arg0];
        }

        sp1C->unk_018 = 0;
        sp1C->unk_214 = sp20;
        sp1C->unk_002 = 0;

        sp20->unk_000 = 0;
        sp20->unk_002 = 0;
        sp20->unk_003 = 1;

        HAL_Strcpy(sp1C->unk_008, arg2);
        HAL_Strcpy(sp20->unk_014, arg2);
        HAL_Strcpy(sp20->unk_220, arg3);
    }
    return sp1C;
}

void func_8002B840(s32 arg0, unk_D_800AE540_0004* arg1) {
    unk_D_800AE540_1194* temp_v0 = &D_800AE540.unk_1194[arg0];
    u8 idx = temp_v0->unk_01;

    if (idx < 2) {
        temp_v0->unk_08[idx] = arg1;
        temp_v0->unk_01++;
    }
}

void func_8002B888(unk_D_800AE540_0004* arg0, unk_func_80026268_arg0* arg1) {
    unk_D_800AE540_0874* ptr = arg0->unk_214;
    s32 tmp = arg0->unk_002;

    if (tmp < 6) {
        arg0->unk_01C[tmp] = *arg1;
        ptr->unk_028[tmp] = *arg1;

        arg0->unk_002 = tmp + 1;
        ptr->unk_002 = tmp + 1;
    }
}

unk_func_80026268_arg0* func_8002B924(unk_func_80026268_arg0* arg0, u8 arg1, s16 arg2) {
    arg0->unk_00.unk_00 = arg1;
    arg0->unk_04 = 0;
    arg0->unk_05 = 0;

    arg0->unk_06 = D_80070FA0[arg1 - 1].unk_06;
    arg0->unk_07 = D_80070FA0[arg1 - 1].unk_07;

    arg0->unk_14 = 0x6400;
    arg0->unk_16 = 0x6400;
    arg0->unk_18 = 0x6400;
    arg0->unk_1A = 0x6400;
    arg0->unk_1C = 0x6400;

    arg0->unk_08 = 0;

    arg0->unk_09[0] = 0;
    arg0->unk_09[1] = 0;
    arg0->unk_09[2] = 0;
    arg0->unk_09[3] = 0;

    arg0->unk_0E = 0x7CF;
    arg0->unk_1E = 0xFFFF;

    arg0->unk_20[0] = 5;
    arg0->unk_20[1] = 5;
    arg0->unk_20[2] = 5;
    arg0->unk_20[3] = 5;

    arg0->unk_52 = 0;
    arg0->unk_53 = 0;
    arg0->unk_10 = func_800224B8(arg1, arg2);

    func_80022338(arg0);

    arg0->unk_02 = arg0->unk_26;

    func_80021CA4(arg0->unk_30, arg1);
    HAL_Strcpy(arg0->unk_3B, func_8002311C(0));
    return arg0;
}

void func_8002BA34(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 spD6;
    s32 spD0;
    s32 spCC;
    unk_func_80026268_arg0 sp78;
    unk_func_80026268_arg0 sp24;

    switch (arg0) {
        case 0:
            spD6 = 0x32;
            break;

        case 3:
            spD6 = 0x32;
            break;

        case 4:
            spD6 = 0x1E;
            break;

        case 5:
            spD6 = 0x19;
            break;

        case 6:
            spD6 = 0x64;
            break;

        case 7:
            spD6 = 0x64;
            break;
    }

    func_8002B5EC(0x10, arg0, arg1);

    spD0 = func_8002B700(0, 0, func_8002311C(1), func_8002311C(2));
    spCC = func_8002B700(1, 0, func_8002311C(1), func_8002311C(2));

    func_8002B888(spD0, func_8002B924(&sp78, arg2, spD6));
    func_8002B888(spCC, func_8002B924(&sp24, arg3, spD6));

    func_8002B840(0, spD0);
    func_8002B840(1, spCC);
}

void func_8002BB7C(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    unk_func_80026268_arg0 sp48;
    unk_func_80022C28_ret* temp_v0;
    unk_D_800AE540_0004* temp_s4;
    char sp34[11];

    func_80023AF8(arg2);
    func_800251B0(arg2, &sp34);

    temp_s4 = func_8002B700(arg1, 0, &sp34, func_8002311C(1));
    temp_v0 = func_80022C28(0x20, arg2, 0, 0);

    if (temp_v0 != NULL) {
        for (i = 0; i < 6; i++) {
            if (func_80022E18(&sp48, 1, temp_v0) == 0) {
                break;
            }

            func_8002B888(temp_s4, &sp48);
        }

        func_80022D8C(temp_v0);
    }

    func_8002B840(arg0, temp_s4);
}

void func_8002BC64(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    main_pool_push_state('RIVL');

    func_8002B5EC(0, 3, 0);

    if (arg0 > 0) {
        func_8002BB7C(0, arg0 - 1, arg0 - 1);
    }

    if (arg1 > 0) {
        func_8002BB7C(0, arg1 - 1, arg1 - 1);
    }

    if (arg2 > 0) {
        func_8002BB7C(1, arg2 - 1, arg2 - 1);
    }

    if (arg3 > 0) {
        func_8002BB7C(1, arg3 - 1, arg3 - 1);
    }

    main_pool_pop_state('RIVL');
}

s32 func_8002BD14(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800AE540.unk_0003 - 1; i++) {
        if (arg0 == D_800AE540.unk_11E4[0][i]) {
            return 1;
        }
    }

    return 0;
}

s32 func_8002BD60(s32 arg0) {
    s32 var_s0;
    s32 var_s1;
    s32 sp24;
    u8 temp_v1;

    var_s0 = -1;

    sp24 = (arg0 - D_800AE540.unk_0003) + 1;
    if (D_800AE540.unk_0003 == 1) {
        return 0;
    }

    temp_v1 = D_800AE540.unk_11E4[0][D_800AE540.unk_0003 - 1];
    if (temp_v1 != 0xFF) {
        return temp_v1;
    }

    var_s1 = osGetCount() & 0xF;
    while (var_s1 > 0) {
        MathUtil_Random16();
        var_s1--;
    }

    var_s1 = MathUtil_Random16() % sp24;
    while (var_s1 >= 0) {
        var_s0++;
        while (func_8002BD14(var_s0) != 0) {
            var_s0++;
        }
        var_s1--;
    }

    return var_s0;
}

s16 func_8002BE70(void) {
    s16 i;
    s16 var_v1 = 0;
    unk_func_80026268_arg0* var_v0;

    var_v0 = &D_800AE540.unk_1194[0].unk_08[0]->unk_214->unk_028[0];

    for (i = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_214->unk_002; i++, var_v0++) {
        if (var_v1 < var_v0->unk_24) {
            var_v1 = var_v0->unk_24;
        }
    }

    return var_v1;
}

void func_8002BEC8(s16 arg0) {
    s16 i;
    unk_func_80026268_arg0* var_s0;
    unk_func_80026268_arg0* var_s1;

    if (arg0 < 0x33) {
        return;
    }

    var_s0 = D_800AE540.unk_1194[1].unk_08[0]->unk_01C;
    var_s1 = D_800AE540.unk_1194[1].unk_08[0]->unk_214->unk_028;

    for (i = 0; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; i++, var_s1++, var_s0++) {
        var_s0->unk_24 = arg0;
        var_s0->unk_10 = func_800224B8(var_s0->unk_00.unk_00, arg0);
        func_80022338(var_s0);
        var_s0->unk_02 = var_s0->unk_26;

        *var_s1 = *var_s0;
    }
}

typedef struct unk_func_8002BFC4_004 {
    /* 0x000 */ char unk_00[0x4];
    /* 0x004 */ char unk04[0x8];
    /* 0x00C */ char unk_0C[0x4];
    /* 0x010 */ char unk10[0x24];
    /* 0x034 */ u16 unk_34;
    /* 0x036 */ u16 unk_36;
    /* 0x038 */ unk_func_80026268_arg0 unk_38[1];
} unk_func_8002BFC4_004; // size >= 0x8C

typedef struct unk_func_8002BFC4 {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ unk_func_8002BFC4_004 unk_004;
    /* 0x090 */ char unk090[0x1A0];
} unk_func_8002BFC4; // size = 0x230

void func_8002BFC4(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 i;
    s16 var_a1;
    unk_D_800AE540_0004* temp_s3;
    s32 var_s0;
    unk_func_8002BFC4_004* temp_s2;
    unk_func_80026268_arg0* var_s1;
    unk_func_8002BFC4* ptr;
    unk_func_8002BFC4* temp_v1;

    temp_s3 = D_800AE540.unk_1194[arg0].unk_08[0];
    if (D_800AE540.unk_11F2 != 0) {
        arg1 += 0x1F;
    }

    ptr = func_8000484C(D_800AF738, arg1);
    ptr += arg2;

    temp_s2 = &ptr->unk_004;

    D_800AE540.unk_11E4[0][D_800AE540.unk_0003 - 1] = arg2;

    temp_s3->unk_018 = temp_s2->unk_34;
    temp_s3->unk_002 = 0;

    for (i = 0; i < temp_s2->unk_36; i++) {
        func_8002B888(temp_s3, &temp_s2->unk_38[i]);
    }

    HAL_Strcpy(temp_s3->unk_008, temp_s2->unk_00);
    HAL_Strcpy(temp_s3->unk_214->unk_014, temp_s2->unk_00);
    HAL_Strcpy(temp_s3->unk_214->unk_220, temp_s2->unk_0C);

    temp_s3->unk_214->unk_003 = (temp_s2->unk_34 >> 8) & 0xFF;

    if (arg3 != 0) {
        func_8002BEC8(func_8002BE70());
    }
}

void func_8002C128(void) {
    s16 var_s0 = D_800AE540.unk_0003 - 1;
    s16 sp24 = D_800AE540.unk_0002;

    if ((D_800AE540.unk_0000 == 2) && (D_800AE540.unk_11F2 != 0)) {
        var_s0 = func_8002BD60(8);
    } else if ((D_800AE540.unk_0000 == 7) && (sp24 == 9)) {
        switch (D_800AE540.unk_11F0) {
            case 0x1:
                var_s0 = 4;
                break;

            case 0x2:
                var_s0 = 5;
                break;

            case 0x3:
                var_s0 = 3;
                break;

            case 0x99:
                var_s0 = 0;
                break;

            case 0xB0:
                var_s0 = 2;
                break;

            case 0xB1:
                var_s0 = 1;
                break;

            default:
                var_s0 = 6;
                break;
        }
    }

    main_pool_push_state('RIVL');

    D_800AF738 = func_800044F4(0x898000, NULL, 1, 0);

    switch (D_800AE540.unk_0000) {
        case 1:
            func_8002BFC4(1, 6, var_s0, 0);
            break;

        case 2:
            func_8002BFC4(1, 7, var_s0, 0);
            break;

        case 3:
            func_8002BFC4(1, sp24 + 8, var_s0, 0);
            break;

        case 4:
            func_8002BFC4(1, 0, var_s0, 0);
            break;

        case 5:
            func_8002BFC4(1, 1, var_s0, 0);
            break;

        case 6:
            func_8002BFC4(1, sp24 + 2, var_s0, 0);
            break;

        case 7:
            func_8002BFC4(1, sp24 + 0xC, var_s0, 1);
            break;

        case 8:
            func_8002BFC4(1, 0x16, var_s0, 0);
            break;
    }

    main_pool_pop_state('RIVL');
}

void func_8002C394(s16 arg0) {
    main_pool_push_state('RIVL');

    D_800AF738 = func_800044F4(0x898000, NULL, 1, 0);
    func_8002B5EC(9, 6, 0);

    if (arg0 == 1) {
        func_8002B840(0, func_8002B700(0, 0, "1P", func_8002311C(1)));
        func_8002B840(1, func_8002B700(-1, 0, "COM", func_8002311C(3)));
    } else {
        func_8002B840(0, func_8002B700(0, 0, "1P", func_8002311C(1)));
        func_8002B840(1, func_8002B700(1, 0, "2P", func_8002311C(1)));
    }

    if (D_80075684 == 0) {
        func_8002BFC4(0, 0x1D, 0, 0);
        func_8002BFC4(1, 0x1D, 1, 0);
    } else {
        func_8002BFC4(0, 0x1D, 1, 0);
        func_8002BFC4(1, 0x1D, 0, 0);
    }

    D_80075684 ^= 1;

    main_pool_pop_state('RIVL');
}

void func_8002C538(void) {
    unk_func_800281D4 sp20;
    unk_D_800AE540_0874* sp1C = D_800AE540.unk_1194[0].unk_08[0]->unk_214;

    sp20.unk_00 = D_800AE540.unk_0000;
    sp20.unk_01 = D_800AE540.unk_0002;
    sp20.unk_02 = D_800AE540.unk_0003;
    sp20.unk_04 = D_800AE540.unk_11F3;
    sp20.unk_03 = D_800AE540.unk_11F2;

    sp20.unk_0D = D_800AE540.unk_11F0;
    sp20.unk_0E = D_800AE540.unk_1194[0].unk_08[0]->unk_018;

    _bcopy(D_800AE540.unk_11E4[0], &sp20.unk_05, 8);
    func_80021C20(&sp20.unk_10, &D_800AE540.unk_1194[0].unk_08[0]->unk_008);
    func_800281D4(&sp20, sp1C->unk_028, sp1C->unk_002);
    func_80026684(0x15, 0);
}

s32 func_8002C5E8(void) {
    unk_func_800281D4 sp250;
    unk_func_80026268_arg0 sp58[6];
    s32 i;
    char sp44[0x10];
    s32 temp_v0;
    u16 tmp;

    temp_v0 = func_80028320(&sp250, sp58);
    if (temp_v0 != -1) {
        func_8002B5EC(sp250.unk_00, sp250.unk_00, sp250.unk_01);

        _bcopy(sp250.unk_05, D_800AE540.unk_11E4[0], 8);
        D_800AE540.unk_0003 = sp250.unk_02;
        D_800AE540.unk_11F3 = sp250.unk_04;
        D_800AE540.unk_11F2 = sp250.unk_03;
        D_800AE540.unk_11F0 = sp250.unk_0D;
        tmp = sp250.unk_0E;

        func_80021B5C(sp44, sp250.unk_10);
        func_8002B840(0, func_8002B700(0, tmp, sp44, sp44));
        func_8002B840(1, func_8002B700(-1, tmp, "COM", func_8002311C(3)));

        for (i = 0; i < temp_v0; i++) {
            func_8002B888(D_800AE540.unk_1194[0].unk_08[0], &sp58[i]);
        }

        D_800AE540.unk_11F5 |= 3;
    }
    return (temp_v0 + 1) != 0;
}
