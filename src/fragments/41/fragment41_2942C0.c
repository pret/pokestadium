#include "fragment41.h"
#include "src/17300.h"
#include "src/19840.h"
#include "src/1AB70.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/22630.h"
#include "src/232C0.h"
#include "src/2E110.h"
#include "src/49790.h"
#include "src/6BC0.h"
#include "src/math_util.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static unk_D_82F21140 D_82F21140;
static unk_D_80068BB0* D_82F2115C;
static unk_D_82F21160 D_82F21160[2];
static unk_D_82F211A0 D_82F211A0[2];
static unk_D_82F21238 D_82F21238;

void func_82F0C410(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s32 arg8) {
    gSPScisTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + arg2) << 2, (arg1 + arg3) << 2, 0, arg4,
                            arg5, arg6, arg7);
}

void func_82F0C630(void) {
    unk_D_82F211A0* var_v1;
    s32 i;

    for (i = 0, var_v1 = &D_82F211A0[0]; i < 2; i++, var_v1++) {
        var_v1->unk_00 = 0;
    }
}

void func_82F0C658(s32 arg0, s16 arg1) {
    s32 i;
    unk_D_82F211A0* temp_v0 = &D_82F211A0[arg0];

    temp_v0->unk_00 = arg1;

    switch (arg1) {
        case 1:
            temp_v0->unk_02 = (arg0 * 0x5A) + 0xFA;
            temp_v0->unk_04 = 0x5A;
            temp_v0->unk_06 = 0x28;
            temp_v0->unk_0C = 0;
            temp_v0->unk_0E = 0;

            for (i = 0; i < 10; i++) {
                temp_v0->unk_10[i].unk_00 = temp_v0->unk_10[i].unk_02 = 0;
                temp_v0->unk_10[i].unk_04 = 0;
            }
            break;

        case 2:
            temp_v0->unk_06 = 0x1E;
            temp_v0->unk_0A = 0;
            temp_v0->unk_0C = 0xFF;
            break;

        case 3:
            temp_v0->unk_06 = 0;
            temp_v0->unk_0A = 0;
            temp_v0->unk_08 = 0;
            temp_v0->unk_0C = 0xFF;
            break;
    }
}

void func_82F0C784(unk_D_82F211A0* arg0) {
    arg0->unk_06--;
    arg0->unk_0C = 0xFF - ((arg0->unk_06 * 0xFF) / 40);
    if (arg0->unk_06 <= 0) {
        func_82F0C658(arg0 - D_82F211A0, 2);
    }
}

void func_82F0C7FC(unk_D_82F211A0* arg0) {
    s32 sp1C;

    if (arg0->unk_06 > 0) {
        arg0->unk_06--;
    }

    arg0->unk_0A += 0x200;

    arg0->unk_0C = ROUND_MAX(((COSS(arg0->unk_0A) * 0.5f) + 0.5f) * 255.0f);

    if ((arg0->unk_06 <= 0) && (arg0->unk_0C >= 0xFF)) {
        sp1C = arg0 - D_82F211A0;
        func_82F0C658(sp1C, 3);
        if (sp1C == 0) {
            func_80048B90(0x01200006);
        }
    }
}

void func_82F0C8EC(unk_D_82F211A0* arg0) {
    s32 i;
    unk_D_82F211A0_010* var_v0 = NULL;

    for (i = 0; i < 10; i++) {
        if (arg0->unk_10[i].unk_04 == 0) {
            break;
        }
    }

    if (i < 10) {
        var_v0 = &arg0->unk_10[i];
    }

    if (var_v0 != NULL) {
        var_v0->unk_00 = arg0->unk_02;
        var_v0->unk_02 = arg0->unk_04;
        var_v0->unk_04 = 0x14;
        arg0->unk_0E++;
    }
}

void func_82F0C958(unk_D_82F211A0* arg0) {
    s32 i;
    unk_D_82F211A0_010* ptr;

    for (i = 0, ptr = &arg0->unk_10[0]; i < 10; i++, ptr++) {
        if (ptr->unk_04 != 0) {
            ptr->unk_04--;
            if (ptr->unk_04 <= 0) {
                arg0->unk_0E--;
            }
        }
    }
}

void func_82F0CA7C(unk_D_82F211A0* arg0) {
    s32 idx = arg0 - D_82F211A0;

    if (arg0->unk_0E > 0) {
        func_82F0C958(arg0);
    }

    if ((arg0->unk_02 < 0xA0) || (arg0->unk_02 >= 0x1C3)) {
        if (arg0->unk_0E == 0) {
            arg0->unk_00 = 0;
            func_82F0EFC4(idx ^ 1, 6);
        }
    } else {
        if (arg0->unk_06 > 0) {
            arg0->unk_06--;
        }

        if ((arg0->unk_06 == 0) && (arg0->unk_0E < 0xA)) {
            func_82F0C8EC(arg0);
            arg0->unk_06 = 2;
        }

        if (idx != 0) {
            arg0->unk_08--;
        } else {
            arg0->unk_08++;
        }

        arg0->unk_02 += arg0->unk_08;
    }
}

void func_82F0CB90(void) {
    s32 i;
    unk_D_82F211A0* var_s0 = &D_82F211A0[0];

    for (i = 0; i < 2; i++, var_s0++) {
        switch (var_s0->unk_00) {
            case 1:
                func_82F0C784(var_s0);
                break;

            case 2:
                func_82F0C7FC(var_s0);
                break;

            case 3:
                func_82F0CA7C(var_s0);
                break;
        }
    }
}

void func_82F0CC3C(void) {
    s32 i;
    s32 j;
    s32 sp84 = 0;
    s16 var_s0;
    u16* temp_s0;
    unk_D_82F211A0* var_s4;
    s16 v;
    s16 tmp;

    for (i = 0, var_s4 = &D_82F211A0[0]; i < 2; i++, var_s4++) {
        if (var_s4->unk_00 != 0) {
            temp_s0 = func_82F05198(i);

            if (sp84 == 0) {
                sp84 = 1;
                func_800060E0(&gDisplayListHead, 0xEC, 0x50, 0xAA, 0x50);
            }

            gDPPipeSync(gDisplayListHead++);

            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, var_s4->unk_0C);
            gDPLoadTextureBlock(gDisplayListHead++, temp_s0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 40, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            v = 60;

            if (var_s4->unk_00 == 1) {
                for (j = 0; j < v; j++) {
                    var_s0 = ((MathUtil_Random16() % 33) * var_s4->unk_06) / 40;
                    if (MathUtil_Random16() & 0x8000) {
                        var_s0 = -var_s0;
                    }
                    func_8001C330(var_s4->unk_02 + var_s0, var_s4->unk_04 + j, 0x3C, 1, 0,
                                  ROUND_MAX((j * 32.0f) / 1.5f), 0x2AB, 0x2AB, 0);
                }
            } else {
                func_8001C330(var_s4->unk_02, var_s4->unk_04, 0x3C, 0x3C, 0, 0, 0x2AB, 0x2AB, 0);
            }

            if (var_s4->unk_0E == 0) {
            } else {
                for (j = 0; j < 10; j++) {
                    if (var_s4->unk_10[j].unk_04 == 0) {
                        continue;
                    }

                    tmp = (var_s4->unk_10[j].unk_04 * 0xFF) / 20;

                    gDPPipeSync(gDisplayListHead++);
                    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, tmp);

                    func_8001C330(var_s4->unk_10[j].unk_00, var_s4->unk_10[j].unk_02, 0x3C, 0x3C, 0, 0, 0x2AB, 0x2AB,
                                  0);
                }
            }
        }
    }

    if (sp84 != 0) {
        func_800060E0(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
    }
}

void func_82F0D084(void) {
    D_82F21238.unk_02 = 0;
}

void func_82F0D090(unk_D_82F21238* arg0, s32 arg1) {
    arg0->unk_28 = func_80019760(1);
    arg0->unk_2C = func_8001B1FC(arg0->unk_28, 0xC0, 0xC0, 0, 0, 0xC0, 0xC0, NULL);
    arg0->unk_2C->unk_00 &= ~2;
    func_8001B2D8(arg0->unk_2C, arg0->unk_24, 1);

    if (arg1 != 0) {
        arg0->unk_06 = 2;
        arg0->unk_2C->unk_00 &= ~4;
    } else {
        arg0->unk_06 = 1;
        arg0->unk_2C->unk_00 |= 4;
    }
    func_8001BD04(arg0->unk_2C->unk_24, arg0->unk_06);
}

void func_82F0D160(s16 arg0) {
    unk_func_82F00838_sp30 sp20;
    unk_D_82F21238* ptr = &D_82F21238;

    main_pool_push_state('intr');
    func_82F0525C(arg0, &sp20);
    D_82F21238.unk_00 = arg0;
    D_82F21238.unk_02 = 1;
    D_82F21238.unk_04 = sp20.unk_02;
    D_82F21238.unk_06 = 1;
    D_82F21238.unk_08 = 0;
    ptr->unk_0A = MathUtil_Random16() % 2;
    ptr->unk_0C = 0;
    ptr->unk_0E = 0x140;
    ptr->unk_10 = 0xC4;
    ptr->unk_12 = 0;
    ptr->unk_14 = 0;
    ptr->unk_16 = 0xFF;
    ptr->unk_20 = 0;
    ptr->unk_24 = &sp20.unk_0C[sp20.unk_06];
    func_82F0D090(&D_82F21238, 0);
    ptr->unk_30.unk_00 = ptr->unk_30.unk_02 = 0;
    ptr->unk_30.unk_04 = ptr->unk_30.unk_06 = -1;

    func_80048B90(4);
    func_800256F4(ptr->unk_04, ptr->unk_24->unk_00.unk_00, 3);
}

void func_82F0D27C(unk_D_82F21238* arg0) {
    unk_D_86002F58_004_000* sp24 = arg0->unk_2C->unk_24;

    if ((func_80017514(sp24) != 0) && (arg0->unk_06 == 2)) {
        arg0->unk_06 = 1;
        arg0->unk_2C->unk_00 |= 4;
        func_8001BD04(sp24, arg0->unk_06);
    }
    arg0->unk_20 = func_8001B9D4(arg0->unk_2C);
}

void func_82F0D2F4(unk_D_82F21238* arg0) {
    if (arg0->unk_12 < 0xC0) {
        arg0->unk_12 += 0x20;
        if (arg0->unk_12 >= 0xC1) {
            arg0->unk_12 = 0xC0;
        }
    } else {
        arg0->unk_14 += 0x20;
        if (arg0->unk_14 >= 0xC1) {
            arg0->unk_14 = 0xC0;
        }
    }

    arg0->unk_0E = ((arg0->unk_12 * -0x60) / 192) + 0x140;
    arg0->unk_10 = ((arg0->unk_14 * -0x60) / 192) + 0xC4;

    func_82F0D27C(arg0);

    if ((arg0->unk_12 == 0xC0) && (arg0->unk_14 == 0xC0)) {
        arg0->unk_02 = 2;
        arg0->unk_0C = 0;
        arg0->unk_0E = 0xE0;
        arg0->unk_10 = 0x64;
    }
}

s32 func_82F0D3F4(s32 arg0) {
    s32 var_v1 = 0;

    if ((arg0 == 0x40) || (arg0 == 0x43) || (arg0 == 0x4B) || (arg0 == 0x5D)) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_82F0D428(unk_D_82F21238* arg0) {
    func_82F0D27C(arg0);

    if (arg0->unk_08 != 0) {
        arg0->unk_0C -= 1;
        if (arg0->unk_0C <= 0) {
            arg0->unk_0C = 0;
        } else {
            return;
        }
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        if (func_82F0D3F4(arg0->unk_24->unk_00.unk_00) != 0) {
            arg0->unk_02 = 3;
            arg0->unk_08 = 1;
            arg0->unk_0C = 0x3C;
            arg0->unk_18 = 0;
            arg0->unk_1A = 0x800;
            arg0->unk_1C = 0;
            func_80048B90(2);
            func_80048B90(0x01200007);
        } else {
            arg0->unk_02 = 6;
            arg0->unk_0C = 0xA;
            if (arg0->unk_08 != 0) {
                func_80048B90(0x01200009);
            } else {
                func_80048B90(2);
            }
        }
    }
}

void func_82F0D51C(unk_D_82F21238* arg0) {
    arg0->unk_0C--;
    func_82F0D27C(arg0);
    arg0->unk_16 = (arg0->unk_0C * 0xFF) / 60;

    switch (arg0->unk_0A) {
        case 1:
            break;

        case 0:
            arg0->unk_1C = ((0x3C - arg0->unk_0C) * 0xF0) / 60;
            arg0->unk_1A = 0x1000 - ((arg0->unk_0C << 0xB) / 60);
            arg0->unk_18 += 0x1000;
            break;
    }

    if (arg0->unk_0C <= 0) {
        arg0->unk_02 = 4;
        arg0->unk_0C = 1;
        arg0->unk_16 = 0;
        arg0->unk_20 = 0;
    }
}

s32 func_82F0D64C(s16 arg0, s8* arg1) {
    s32 sp64;
    s8* var_v1;
    char sp20[64];

    sp64 = 1;
    func_80021C80(sp20, func_82F00020(arg0));

    var_v1 = sp20;
    while (*var_v1 != '\x00') {
        if (*var_v1 != *arg1) {
            sp64 = 0;
            break;
        }
        var_v1++;
        arg1++;
    }

    return sp64;
}

void func_82F0D6D0(s16 arg0, unk_func_80026268_arg0* arg1) {
    s16 sp2E = 0;

    if (func_82F0D3F4(arg1->unk_00.unk_00) != 0) {
        sp2E = arg1->unk_00.unk_00;
        arg1->unk_00.unk_00++;
    }

    if (sp2E != 0) {
        if (func_82F0D64C(sp2E, arg1->unk_30) != 0) {
            func_80021C80(arg1->unk_30, func_82F00020(arg1->unk_00.unk_00));
        }
        func_80022338(arg1);
        func_800256F4(arg0, arg1->unk_00.unk_00, 3);
    }
}

void func_82F0D76C(unk_D_82F21238* arg0) {
    arg0->unk_0C--;
    if (arg0->unk_0C <= 0) {
        main_pool_pop_state('intr');
        main_pool_push_state('intr');

        arg0->unk_02 = 5;
        arg0->unk_0C = 0x3C;
        arg0->unk_16 = 0;
        if (arg0->unk_0A == 0) {
            arg0->unk_1C = 0xF0;
        }
        arg0->unk_20 = 0;
        func_82F0D6D0(arg0->unk_04, arg0->unk_24);
        func_82F05210(arg0->unk_00, arg0->unk_24);
        func_82F0D090(arg0, 1);
        arg0->unk_30.unk_00 = 0x38;
        arg0->unk_30.unk_02 = 0x168;
        arg0->unk_30.unk_04 = 0x210;
        arg0->unk_30.unk_06 = 0;
        func_80048B90(0x01200008);
    }
}

void func_82F0D834(unk_D_82F21238* arg0) {
    s16 var_v1;
    unk_D_82F20A40_00E* ptr = &arg0->unk_30;

    func_82F0D27C(arg0);
    arg0->unk_0C--;
    arg0->unk_16 = ((0x3C - arg0->unk_0C) * 0xFF) / 60;

    switch (arg0->unk_0A) {
        case 1:
            break;

        case 0:
            arg0->unk_1C = (arg0->unk_0C * 0xF0) / 60;
            arg0->unk_1A = 0x800 - ((arg0->unk_0C * -0x800) / 60);
            arg0->unk_18 += 0x1000;
            break;
    }

    var_v1 = arg0->unk_0C;
    if (var_v1 >= 0xB) {
        var_v1 = 0xA;
    }

    ptr->unk_00 = 0x38 - (var_v1 * 0) / 10;
    ptr->unk_02 = 0x154 - ((var_v1 * -0x14) / 10);
    ptr->unk_04 = 0x210 - (var_v1 * 0) / 10;
    ptr->unk_06 = 0x28 - ((var_v1 * 0x28) / 10);

    if (arg0->unk_0C <= 0) {
        arg0->unk_02 = 2;
        arg0->unk_0C = 0x5A;
        arg0->unk_16 = 0xFF;
    }
}

void func_82F0DA60(unk_D_82F21238* arg0) {
    unk_D_82F20A40_00E* temp_v0_2 = &arg0->unk_30;

    if (arg0->unk_0C > 0) {
        arg0->unk_0C--;
    }

    if (arg0->unk_30.unk_04 != -1) {
        temp_v0_2->unk_00 = 0x38 - ((arg0->unk_0C * 0) / 10);
        temp_v0_2->unk_02 = 0x168 - ((arg0->unk_0C * 0x14) / 10);
        temp_v0_2->unk_04 = 0x210 - ((arg0->unk_0C * 0) / 10);
        temp_v0_2->unk_06 = -((arg0->unk_0C * -0x28) / 10);
    }

    if (arg0->unk_14 > 0) {
        arg0->unk_14 -= 0x20;
        if (arg0->unk_14 < 0) {
            arg0->unk_14 = 0;
        }
    } else {
        arg0->unk_12 -= 0x20;
        if (arg0->unk_12 < 0) {
            arg0->unk_12 = 0;
        }
    }

    arg0->unk_0E = ((arg0->unk_12 * -0x60) / 192) + 0x140;
    arg0->unk_10 = ((arg0->unk_14 * -0x60) / 192) + 0xC4;
    func_82F0D27C(arg0);

    if ((arg0->unk_12 == 0) && (arg0->unk_14 == 0)) {
        if (arg0->unk_0C <= 0) {
            arg0->unk_02 = 0;
            arg0->unk_0C = 0;
            arg0->unk_20 = 0;

            temp_v0_2->unk_00 = temp_v0_2->unk_02 = 0;
            temp_v0_2->unk_04 = temp_v0_2->unk_06 = -1;

            main_pool_pop_state('intr');
        }
    }
}

void func_82F0DCF4(void) {
    switch (D_82F21238.unk_02) {
        case 0:
            break;

        case 1:
            func_82F0D2F4(&D_82F21238);
            break;

        case 2:
            func_82F0D428(&D_82F21238);
            break;

        case 3:
            func_82F0D51C(&D_82F21238);
            break;

        case 4:
            func_82F0D76C(&D_82F21238);
            break;

        case 5:
            func_82F0D834(&D_82F21238);
            break;

        case 6:
            func_82F0DA60(&D_82F21238);
            break;
    }
}

void func_82F0DD90(s16 arg0, s16 arg1, s16 arg2) {
    static Gfx D_82F13F90[] = {
        gsDPPipeSync(),
        gsDPSetCycleType(G_CYC_2CYCLE),
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsDPSetCombineLERP(TEXEL0, TEXEL1, PRIM_LOD_FRAC, TEXEL1, TEXEL0, TEXEL1, PRIM_LOD_FRAC, TEXEL1, PRIMITIVE,
                           ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, ENVIRONMENT),
        gsDPSetPrimColor(0, 0x80, 0, 0, 255, 0),
        gsSPEndDisplayList(),
    };
    static f32 D_82F13FC0 = 0.0f;
    static f32 D_82F13FC4 = 0.0f;
    static f32 D_82F13FC8 = 0.0f;
    static f32 D_82F13FCC = 0.0f;

    UNUSED s32 pad[2];
    f32 temp_fa0;
    f32 temp_fa4;
    f32 temp_fa8;
    f32 temp_faC;

    gSPDisplayList(gDisplayListHead++, D_82F13F90);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 50, (arg2 << 7) / 255);

    gDPLoadMultiBlock_4b(gDisplayListHead++, D_3026368, 0x0100, 1, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 1, G_TX_NOLOD);
    temp_fa0 = D_82F13FC0 + 31.0f;
    temp_fa4 = D_82F13FC4 + 31.0f;
    gDPSetTileSize(gDisplayListHead++, 1, D_82F13FC0 * 4.0f, D_82F13FC4 * 4.0f, temp_fa0 * 4.0f, temp_fa4 * 4.0f);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3026168, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, 1);
    temp_fa8 = D_82F13FC8 + 31.0f;
    temp_faC = D_82F13FCC + 31.0f;
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, D_82F13FC8 * 4.0f, D_82F13FCC * 4.0f, temp_fa8 * 4.0f,
                   temp_faC * 4.0f);

    func_82F0C410(arg0, arg1, 0xC0, 0xC0, 0, 0, 0xAB, 0xAB, 0x100000);

    D_82F13FC0 -= 0.25f;
    if (D_82F13FC0 < 0.0f) {
        D_82F13FC0 += 32.0f;
    }

    D_82F13FC4 -= 0.25f;
    if (D_82F13FC4 < 0.0f) {
        D_82F13FC4 += 32.0f;
    }

    D_82F13FC8 += 0.25f;
    if (D_82F13FC8 >= 32.0f) {
        D_82F13FC8 -= 32.0f;
    }

    D_82F13FCC -= 0.5f;
    if (D_82F13FCC < 0.0f) {
        D_82F13FCC += 32.0f;
    }
}

void func_82F0E5C8(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 tmp = (arg1 + (arg3 / 2)) - 8;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg0 - 0xD, arg1 - 0xD, 0x10, 0x10, D_3026568, 0x10, 0);
    func_8001C330(arg0 - 0xD, arg1 + 3, 0x10, (arg3 / 2) - 3, 0, 0x1E0, 0x400, 0, 0);
    func_8001C6AC((arg0 + arg2) - 3, arg1 - 0xD, 0x10, 0x10, D_3026768, 0x10, 0);
    func_8001C330(arg0 + 3, arg1 - 0xD, arg2 - 6, 0x10, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 3, arg1 + 3, 0x10, (arg3 / 2) - 3, 0, 0x1E0, 0x400, 0, 0);
    func_8001C6AC(arg0 - 0xD, (arg1 + arg3) - 3, 0x10, 0x10, D_3026D68, 0x10, 0);

    func_8001C330(arg0 - 0xD, tmp + 8, 0x10, (arg3 / 2) - 3, 0, 0, 0x400, 0, 0);
    func_8001C6AC((arg0 + arg2) - 3, (arg1 + arg3) - 3, 0x10, 0x10, D_3026F68, 0x10, 0);
    func_8001C330(arg0 + 3, (arg1 + arg3) - 3, arg2 - 6, 0x10, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 3, tmp + 8, 0x10, (arg3 / 2) - 3, 0, 0, 0x400, 0, 0);

    if (arg3 >= 0x10) {
        func_8001C6AC(arg0 - 0xD, tmp, 0x10, 0x10, D_3026968, 0x10, 0);
        func_8001C6AC((arg0 + arg2) - 3, tmp, 0x10, 0x10, D_3026B68, 0x10, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82F0E97C(unk_D_82F21238* arg0) {
    UNUSED s32 pad;
    s16 i;
    s32 sp5C;
    s16 var_a0;
    s16 var_s2;
    s16 var_s3;

    sp5C = 0;
    if (arg0->unk_0A == 1) {
        sp5C = 1;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg0->unk_16);

    if (sp5C != 0) {
        gDPSetAlphaCompare(gDisplayListHead++, G_AC_DITHER);
    }

    var_s3 = 8;
    if ((arg0->unk_02 == 3) || (arg0->unk_02 == 5)) {
        var_s3 = 1;
    }

    for (i = 0; i < 0xC0; i += var_s3) {
        var_s2 = CLAMP_MIN(0xC0 - i, var_s3);

        gDPLoadTextureTile(gDisplayListHead++, arg0->unk_20 + (i * 0x180), G_IM_FMT_RGBA, G_IM_SIZ_16b, 192, 0, 0, 0,
                           191, var_s2 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        if (var_s3 != 1) {
            var_a0 = 0xE0;
        } else {
            var_a0 = (s16)(SINS(arg0->unk_18 + (arg0->unk_1A * i)) * arg0->unk_1C) + 0xE0;
        }
        func_8001C330(var_a0, i + 0x64, 0xC0, var_s2, 0, 0, 0x400, 0x400, 0);
    }

    if (sp5C != 0) {
        gDPPipeSync(gDisplayListHead++);
        gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
    }
}

void func_82F0ECA4(void) {
}

void func_82F0ECAC(unk_D_82F20A40_00E* arg0, unk_func_80026268_arg0* arg1) {
    s16 spC6;
    s8 sp44[0x80];
    char* sp40;
    char* sp3C;
    char* sp38;
    s16 tmp1;

    sp44[0] = '\x00';
    sp3C = NULL;
    sp40 = NULL;

    if (func_82F0D3F4(arg1->unk_00.unk_00 - 1) != 0) {
        sp40 = func_82F00020(arg1->unk_00.unk_00 - 1);
        sp3C = func_82F00020(arg1->unk_00.unk_00);
    }

    if (sp40 != NULL) {
        func_8002D5D4(0x21, sp40);
        func_8002D5D4(0x22, sp3C);
        sp38 = func_8002D7C0(sp44, 0x80, D_82F13B70, 0x19);
    }

    if ((sp44[0] != '\x00') && ((arg0->unk_04 != 0x210) || (arg0->unk_06 != 0))) {
        func_82F037EC(arg0->unk_00, arg0->unk_02, arg0->unk_04, arg0->unk_06, 0x1E, 0x1E, 0x82, 0xFF);
        if ((arg0->unk_04 == 0x210) && (arg0->unk_06 == 0x28)) {
            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            spC6 = arg0->unk_00 + (arg0->unk_04 / 2);
            tmp1 = func_8001F5B0(0, 0, sp38) / 2;
            func_8001F1E8(spC6 - tmp1, arg0->unk_02 + 8, sp38);
            func_8001F444();
        }
    }
}

void func_82F0EE58(void) {
    unk_D_82F21238* ptr = &D_82F21238;
    UNUSED s32 pad;
    s32 sp24;

    if (ptr->unk_02 != 0) {
        sp24 = 0;
        if (ptr->unk_12 > 0) {
            if (ptr->unk_14 > 0) {
                sp24 = 1;
                func_800060E0(&gDisplayListHead, ptr->unk_0E, ptr->unk_10, ptr->unk_12, ptr->unk_14);
                if (ptr->unk_20 != 0) {
                    func_82F0E97C(&D_82F21238);
                }
                func_82F0DD90(0xE0, 0x64, ptr->unk_16);
            }
        }

        if (sp24 != 0) {
            func_800060E0(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
        }

        func_82F0E5C8(ptr->unk_0E, ptr->unk_10, ptr->unk_12, ptr->unk_14);

        if (ptr->unk_30.unk_04 != -1) {
            func_82F0ECAC(&ptr->unk_30, ptr->unk_24);
        }
    }
}

void func_82F0EF68(void) {
    s32 i;
    unk_D_82F21160* var_v1;

    for (i = 0, var_v1 = &D_82F21160[0]; i < 2; i++, var_v1++) {
        var_v1->unk_00 = 0;
        var_v1->unk_02 = 0;
        var_v1->unk_04 = 0;
        var_v1->unk_06 = 0;
        var_v1->unk_08 = 0;
        var_v1->unk_0A = 0;
        var_v1->unk_0C = 0;
        var_v1->unk_0E = 0;
        var_v1->unk_10 = 0;
        var_v1->unk_12 = 0;
        var_v1->unk_14 = 0.0f;
        var_v1->unk_18 = 0.0f;
        var_v1->unk_1C = 0.0f;
    }
}

void func_82F0EFC4(s32 arg0, s16 arg1) {
    static s16 D_82F13FD0[] = { 0x64, 0x2C8 };
    static s16 D_82F13FD4[] = { 0x50, 0x236, 0, 0, 0x3F80, 0 };

    unk_D_82F21160* temp_v0 = &D_82F21160[arg0];

    temp_v0->unk_00 = arg1;

    switch (arg1) {
        case 1:
            temp_v0->unk_02 = D_82F13FD0[arg0];
            temp_v0->unk_04 = D_82F21140.unk_02 + temp_v0->unk_02;
            temp_v0->unk_06 = 0xFA;
            temp_v0->unk_08 = temp_v0->unk_04 - 0x40;
            temp_v0->unk_0A = 0xAE;
            temp_v0->unk_0C = 0x80;
            temp_v0->unk_0E = 0x48;
            temp_v0->unk_10 = 0;
            temp_v0->unk_12 = 0;
            temp_v0->unk_14 = 1.0f;
            temp_v0->unk_18 = 0.0f;
            temp_v0->unk_1C = 9.0f;
            break;

        case 2:
            temp_v0->unk_08 = 0;
            temp_v0->unk_0A = 0;
            temp_v0->unk_0C = 0;
            temp_v0->unk_0E = 0;
            temp_v0->unk_06 = 0xBE;
            break;

        case 3:
            temp_v0->unk_08 = 0;
            temp_v0->unk_0A = 0;
            temp_v0->unk_0C = 0;
            temp_v0->unk_0E = 0;
            temp_v0->unk_10 = D_82F21140.unk_18;
            break;

        case 4:
            if (arg0 == 0) {
                temp_v0->unk_02 = 0x50;
            } else {
                temp_v0->unk_02 = 0x236;
            }
            temp_v0->unk_04 = D_82F21140.unk_02 + temp_v0->unk_02;
            temp_v0->unk_14 = 0.75f;
            break;

        case 5:
            temp_v0->unk_12 = 0;
            temp_v0->unk_08 = temp_v0->unk_04 - 0x40;
            if (temp_v0->unk_08 < 0) {
                temp_v0->unk_08 = 0;
            }
            temp_v0->unk_0A = 0xC2;
            temp_v0->unk_0C = 0x80;
            temp_v0->unk_0E = 0x3C;
            break;

        case 6:
            temp_v0->unk_02 = D_82F13FD4[arg0];
            temp_v0->unk_04 = D_82F21140.unk_02 + temp_v0->unk_02;
            temp_v0->unk_06 = 0xA0;
            temp_v0->unk_08 = temp_v0->unk_04 - 0x40;
            if (temp_v0->unk_08 < 0) {
                temp_v0->unk_08 = 0;
            }
            temp_v0->unk_0A = 0xC2;
            temp_v0->unk_0C = 0x80;
            temp_v0->unk_0E = 0x3C;
            temp_v0->unk_10 = 0;
            temp_v0->unk_12 = 0;
            temp_v0->unk_14 = 0.75f;
            temp_v0->unk_18 = 0.0f;
            temp_v0->unk_1C = 1.0f;
            break;

        case 8:
            temp_v0->unk_02 = D_82F13FD4[arg0];
            temp_v0->unk_04 = D_82F21140.unk_02 + temp_v0->unk_02;
            temp_v0->unk_06 = 0xA0;
            temp_v0->unk_08 = temp_v0->unk_04 - 0x40;
            if (temp_v0->unk_08 < 0) {
                temp_v0->unk_08 = 0;
            }
            temp_v0->unk_0A = 0xC2;
            temp_v0->unk_0C = 0x80;
            temp_v0->unk_0E = 0x3C;
            temp_v0->unk_10 = 0;
            temp_v0->unk_12 = 0;
            temp_v0->unk_14 = 0.75f;
            temp_v0->unk_18 = 0.0f;
            temp_v0->unk_1C = 1.0f;
            break;
    }
}

void func_82F0F260(unk_D_82F21160* arg0) {
    arg0->unk_06 -= 2;
    if (arg0->unk_06 < 0xBF) {
        func_82F0EFC4(arg0 - D_82F21160, 2);
    }
}

void func_82F0F2AC(unk_D_82F21160* arg0) {
    arg0->unk_04 = D_82F21140.unk_02 + arg0->unk_02;
    arg0->unk_06 = (s16)ROUND_MAX(SINS(arg0->unk_12) * 3.0f) + 0xBE;

    arg0->unk_12 += 0x800;

    arg0->unk_1C -= 0.2f;
    if (arg0->unk_1C < 1.0f) {
        arg0->unk_1C = 1.0f;
    }
}

void func_82F0F374(unk_D_82F21160* arg0) {
    f32 one = 1.0f;
    s16 var_v0;
    s16 tmp1;
    s32 temp_a1;
    s32 temp_a3;
    f32 tmpf1;

    var_v0 = D_82F21140.unk_18;
    if (arg0->unk_10 < var_v0) {
        var_v0 = 0;
    }
    temp_a1 = (var_v0 * -0x14);

    temp_a3 = arg0 - D_82F21160;
    if (temp_a3 == 0) {
        arg0->unk_02 = ((var_v0 * 0x14) / arg0->unk_10) + 0x50;
    } else {
        arg0->unk_02 = ((var_v0 * 0x92) / arg0->unk_10) + 0x236;
    }

    arg0->unk_04 = D_82F21140.unk_02 + arg0->unk_02;

    tmp1 = (temp_a1 / arg0->unk_10) + 0xD2;
    tmpf1 = (((var_v0 * one) / arg0->unk_10) + 2.0f);

    arg0->unk_06 = (s16)ROUND_MAX(SINS(arg0->unk_12) * tmpf1) + tmp1;

    arg0->unk_12 += 0x800;
    arg0->unk_14 = ((var_v0 * 0.25f) / arg0->unk_10) + 0.75f;

    if (temp_a1 >= -0x13) {
        func_82F0EFC4(temp_a3, 4);
    }
}

void func_82F0F578(unk_D_82F21160* arg0) {
    arg0->unk_04 = D_82F21140.unk_02 + arg0->unk_02;
    arg0->unk_06 = (s16)ROUND_MAX(2.0f * SINS(arg0->unk_12)) + 0xD2;
    arg0->unk_12 += 0x800;
}

void func_82F0F600(unk_D_82F21160* arg0) {
    arg0->unk_04 = D_82F21140.unk_02 + arg0->unk_02;
    arg0->unk_12--;
    arg0->unk_06 += arg0->unk_12;
    if (arg0->unk_06 < 0x79) {
        arg0->unk_00 = 0;
        arg0->unk_06 = 0x78;
    }
}

void func_82F0F654(unk_D_82F21160* arg0) {
    s16 idx;

    arg0->unk_12++;
    arg0->unk_06 += arg0->unk_12;
    if (arg0->unk_06 >= 0xD2) {
        arg0->unk_00 = 7;
        arg0->unk_06 = 0xD2;
        arg0->unk_18 = MathUtil_Random16() % 16;
        arg0->unk_12 = MathUtil_Random16();
        idx = arg0 - D_82F21160;
        if (idx == 0) {
            D_82F21140.unk_0C &= ~0x40;
        }
    }
}

void func_82F0F714(unk_D_82F21160* arg0) {
    arg0->unk_04 = D_82F21140.unk_02 + arg0->unk_02;
    arg0->unk_06 = (s16)ROUND_MAX(2.0f * SINS(arg0->unk_12)) + 0xD2;
    arg0->unk_12 += 0x800;
}

void func_82F0F79C(unk_D_82F21160* arg0) {
    if (arg0->unk_1C < 9.0f) {
        arg0->unk_04 = D_82F21140.unk_02 + arg0->unk_02;
        arg0->unk_06 = (s16)ROUND_MAX(2.0f * SINS(arg0->unk_12)) + 0xD2;
        arg0->unk_12 += 0x800;

        arg0->unk_1C += 0.2f;
        if (arg0->unk_1C >= 9.0f) {
            arg0->unk_1C = 9.0f;
        }
    } else {
        arg0->unk_1C = 9.0f;
        arg0->unk_06 += 2;
        if (arg0->unk_06 >= 0x104) {
            arg0->unk_00 = 0;
            arg0->unk_06 = 0;
        }
    }
}

void func_82F0F89C(void) {
    s32 var_s1;
    unk_D_82F21160* var_s0;
    s32 i;

    var_s0 = D_82F21160;

    for (i = 0; i < 2; i++, var_s0++) {
        var_s1 = 1;

        switch (var_s0->unk_00) {
            case 0:
                var_s1 = 0;
                break;

            case 1:
                func_82F0F260(var_s0);
                break;

            case 2:
                func_82F0F2AC(var_s0);
                break;

            case 3:
                func_82F0F374(var_s0);
                break;

            case 4:
                func_82F0F578(var_s0);
                break;

            case 5:
                func_82F0F600(var_s0);
                break;

            case 6:
                func_82F0F654(var_s0);
                break;

            case 7:
                func_82F0F714(var_s0);
                break;

            case 8:
                func_82F0F79C(var_s0);
                break;
        }

        if (var_s1 != 0) {
            s32 tmp;

            var_s0->unk_18 += var_s0->unk_1C;

            tmp = var_s0->unk_18;
            tmp /= 16;

            var_s0->unk_18 -= (tmp * 0x10);
        }
    }
}

void func_82F0F9E0(s16 arg0, s16 arg1, f32 arg2, s16 arg3) {
    static u8* D_82F13FE0[] = {
        D_300D868, D_300EA68, D_300FC68, D_3010E68, D_3012068, D_3013268, D_3013268, D_3013268,
        D_3013268, D_3013268, D_3013268, D_3013268, D_3012068, D_3010E68, D_300FC68, D_300EA68,
    };

    s32 i;
    s16 var_fv0_4;
    s16 sp60;
    s16 sp5E;
    s16 sp5C;
    f32 var_fv0;
    u8* var_s2;

    if ((arg0 < 0x281) && (arg0 >= -0x30) && (arg1 < 0x1E1)) {
        sp60 = 0;
        if (arg1 >= -0x30) {
            var_fv0 = arg2;
            if ((arg3 >= 0xC) && (arg3 < 0x10)) {
                sp60 = 0x600;
                var_fv0 = 0.0f - arg2;
            }

            sp5E = ROUND_MAX(1024.0f / var_fv0);
            sp5C = ROUND_MAX(1024.0f / arg2);
            var_fv0_4 = ROUND_MAX(24.0f * arg2);

            var_s2 = D_82F13FE0[arg3];
            for (i = 0; i < 2; i++) {
                gDPLoadTextureBlock(gDisplayListHead++, var_s2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 24, 0,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);

                func_82F0C410(arg0, arg1 + (var_fv0_4 * i), 0x30, 0x18, sp60, 0, sp5E, sp5C, 0);
                var_s2 += 0x900;
            }
        }
    }
}

void func_82F0FCC0(void) {
    s32 i;
    s32 var_s3 = 0;
    unk_D_82F21160* var_s0;

    for (i = 0, var_s0 = D_82F21160; i < 2; i++, var_s0++) {
        if (var_s0->unk_00 == 0) {
            continue;
        }

        if ((var_s0->unk_0C != 0) && (var_s0->unk_0E != 0)) {
            var_s3 = 1;
            var_s0->unk_08 = var_s0->unk_04 - 0x40;
            if (var_s0->unk_08 < 0) {
                var_s0->unk_08 = 0;
            }
            func_800060E0(&gDisplayListHead, var_s0->unk_08, var_s0->unk_0A, var_s0->unk_0C, var_s0->unk_0E);
        }

        func_82F0F9E0(var_s0->unk_04, var_s0->unk_06, var_s0->unk_14, var_s0->unk_18);
    }

    if (var_s3 != 0) {
        func_800060E0(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
    }
}

s32 func_82F0FDCC(void) {
    s32 var_v1 = 0;

    if (D_82F21140.unk_0E != 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_82F0FDEC(s16 arg0) {
    UNUSED s32 pad;
    unk_D_82F21140* ptr = &D_82F21140;
    unk_D_82F21160* ptr2;
    s32 i;
    u16 tmp = 0;

    if (arg0 < 0x12) {
        ptr->unk_00 = arg0;
    }

    switch (arg0) {
        case 0:
            ptr->unk_02 = -0x14;
            ptr->unk_04 = 0x18;
            ptr->unk_10 = 1.5f;
            ptr->unk_06 = 0xB4;
            ptr->unk_08 = 0xE4;
            ptr->unk_0A = 0xAA;
            ptr->unk_0E = -1;
            ptr->unk_14 = 0x80;
            ptr->unk_16 = 0x40;
            ptr->unk_0C = tmp;
            ptr->unk_0C |= 0x1F;
            break;

        case 1:
            ptr->unk_18 = 0x1E;
            ptr->unk_0C |= 0x20;
            func_80048B90(0x01200002);
            break;

        case 2:
        case 4:
            ptr->unk_18 = 0xA;
            break;

        case 3:
            ptr->unk_18 = 2;
            break;

        case 6:
            ptr->unk_18 = 0xA;
            break;

        case 7:
            ptr->unk_18 = 2;
            break;

        case 8:
        case 9:
            ptr->unk_18 = 0xA;

            ptr2 = &D_82F21160[0];
            for (i = 0; i < 2; i++, ptr2++) {
                if (ptr2->unk_00 != 0) {
                    func_82F0EFC4(i, 3);
                }
            }
            break;

        case 11:
            func_82F0EFC4(0, 8);
            func_82F0EFC4(1, 8);
            break;

        case 12:
            ptr->unk_18 = 0xA;
            break;

        case 14:
            ptr->unk_18 = 0xA;
            break;

        case 16:
            ptr->unk_18 = 0xA;
            break;

        case 5:
        case 17:
            ptr->unk_18 = 0x1E;
            break;

        case 19:
            func_82F0EFC4(0, 1);
            func_80048B90(0x01200004);
            break;

        case 20:
            func_82F0EFC4(1, 1);
            func_80048B90(0x01200004);
            break;

        case 21:
            if (1) {}
            if (1) {}
            func_82F0EFC4(0, 5);
            func_82F0EFC4(1, 5);
            break;
    }
}

void func_82F10034(unk_D_82F21140* arg0) {
    if (func_82F07A74() != 0) {
        switch (func_82F07A74()) {
            case 1:
            case 11:
                arg0->unk_0E = -1;
                arg0->unk_0C |= 0x1E;
                break;

            default:
                arg0->unk_0C &= ~0x1E;
                break;
        }
    } else if (func_82F0C16C() != 0) {
        switch (func_82F0C16C()) {
            case 1:
            case 8:
                arg0->unk_0E = -1;
                arg0->unk_0C |= 0x1E;
                break;

            default:
                arg0->unk_0C &= ~0x1E;
                break;
        }
    } else {
        arg0->unk_0E = -1;
        arg0->unk_0C |= 0x1E;
    }
}

void func_82F10110(unk_D_82F21140* arg0) {
    arg0->unk_18--;
    arg0->unk_14 = ((arg0->unk_18 * 0x60) / 30) + 0x20;
    arg0->unk_16 = ((arg0->unk_18 * -0x40) / 30) + 0x80;
    if (arg0->unk_18 <= 0) {
        func_82F0FDEC(2);
    }
}

void func_82F101C8(unk_D_82F21140* arg0) {
    s16 var_v0;

    arg0->unk_18--;
    var_v0 = arg0->unk_18;
    if (arg0->unk_00 == 4) {
        var_v0 = 0xA - var_v0;
    }

    arg0->unk_02 = ((var_v0 * -0xAE) / 10) + 0x9A;
    arg0->unk_04 = ((var_v0 * 0x43) / 10) - 0x2B;
    arg0->unk_10 = ((var_v0 * -0.39999998f) / 10) + 1.9f;
    arg0->unk_0A = ((var_v0 * 3) / 10) + 0xA7;

    if (arg0->unk_18 <= 0) {
        if (arg0->unk_00 == 4) {
            func_82F0FDEC(5);
        } else {
            func_82F0FDEC(3);
        }
    }
}

void func_82F10348(unk_D_82F21140* arg0) {
    if (arg0->unk_18 > 0) {
        arg0->unk_18--;
    }

    switch (func_82F018F8()) {
        case 3:
            break;

        case 2:
        case 4:
            if (arg0->unk_0E == -1) {
                arg0->unk_0E = 2;
            }
            arg0->unk_0C &= ~1;
            break;

        case 1:
            arg0->unk_0C &= ~0x1E;
            break;

        default:
            arg0->unk_0E = -1;
            arg0->unk_0C |= 0x1F;
            break;
    }

    if (func_82F13964(4) != 0) {
        func_82F0FDEC(6);
    }
}

void func_82F10400(unk_D_82F21140* arg0) {
    arg0->unk_18--;
    arg0->unk_02 = ((arg0->unk_18 * 0x1F8) / 10) - 0x15E;
    if (arg0->unk_18 <= 0) {
        func_82F0FDEC(7);
    }
}

void func_82F10454(unk_D_82F21140* arg0) {
    if (arg0->unk_18 > 0) {
        arg0->unk_18--;
    }

    switch (func_82F018F8()) {
        case 3:
            break;

        case 2:
        case 4:
            if (arg0->unk_0E == -1) {
                arg0->unk_0E = 2;
            }
            arg0->unk_0C &= ~1;
            break;

        case 1:
            arg0->unk_0C &= ~0x1E;
            break;

        default:
            arg0->unk_0E = -1;
            arg0->unk_0C |= 0x1F;
            break;
    }

    if (func_82F13964(5) != 0) {
        func_82F0FDEC(9);
    }
}

void func_82F1050C(unk_D_82F21140* arg0) {
    arg0->unk_18--;
    arg0->unk_02 = ((arg0->unk_18 * -0x14A) / 10) - 0x14;
    arg0->unk_04 = ((arg0->unk_18 * -0x43) / 10) + 0x18;
    arg0->unk_10 = ((arg0->unk_18 * 0.39999998f) / 10.0f) + 1.5f;
    arg0->unk_0A = ((arg0->unk_18 * -3) / 10) + 0xAA;

    if (arg0->unk_18 <= 0) {
        if (arg0->unk_00 == 8) {
            func_82F0FDEC(5);
        } else {
            func_82F0FDEC(0xA);
        }
    }
}

void func_82F10674(unk_D_82F21140* arg0) {
    if (func_82F0C16C() == 2) {
        arg0->unk_0C &= ~0x10;
        arg0->unk_0C &= ~2;
    } else {
        arg0->unk_0C |= 0x12;
    }

    if (func_82F13964(7) != 0) {
        if (!(arg0->unk_0C & 0x40)) {
            arg0->unk_0C |= 0x40;
            func_82F0C658(0, 1);
            func_82F0C658(1, 1);
            func_80048B90(0x01200005);
        }
    }
}

void func_82F10710(unk_D_82F21140* arg0) {
    if (func_82F13964(7) != 0) {
        func_82F0FDEC(5);
    }
}

void func_82F10744(unk_D_82F21140* arg0) {
    s16 var_v1 = arg0->unk_18;

    arg0->unk_18--;
    if (var_v1 < 0) {
        var_v1 = 0;
    }

    arg0->unk_02 = ((var_v1 * -0x1E4) / 10) + 0x1D0;
    arg0->unk_04 = ((var_v1 * 0) / 10) + 0x18;
    if (arg0->unk_18 < -5) {
        func_82F0FDEC(0xD);
        func_82F0D160(0);
    }
}

void func_82F10818(unk_D_82F21140* arg0) {
    if (func_82F13964(0xB) != 0) {
        func_82F0FDEC(0xE);
    }
}

void func_82F1084C(unk_D_82F21140* arg0) {
    s16 var_v1 = arg0->unk_18;

    arg0->unk_18--;
    if (var_v1 < 0) {
        var_v1 = 0;
    }

    arg0->unk_02 = ((var_v1 * 0x3A0) / 10) - 0x1D0;
    arg0->unk_04 = ((var_v1 * 0) / 10) + 0x18;
    if (arg0->unk_18 < -5) {
        func_82F0FDEC(0xF);
        func_82F0D160(1);
    }
}

void func_82F1091C(unk_D_82F21140* arg0) {
    if (func_82F13964(0xB) != 0) {
        func_82F0FDEC(0x10);
    }
}

void func_82F10950(unk_D_82F21140* arg0) {
    arg0->unk_18--;
    arg0->unk_02 = ((arg0->unk_18 * -0x1BC) / 10) - 0x14;
    arg0->unk_04 = ((arg0->unk_18 * 0) / 10) + 0x18;
    if (arg0->unk_18 <= 0) {
        func_82F0FDEC(0x11);
        func_82F0EFC4(0, 8);
        func_82F0EFC4(1, 8);
    }
}

void func_82F10A24(unk_D_82F21140* arg0) {
    s32 i;

    if (arg0->unk_00 == 5) {
        for (i = 0; i < 2; i++) {
            if (D_82F21160[i].unk_00 == 4) {
                func_82F0EFC4(i, 8);
            }
        }

        if ((D_82F21160->unk_00 != 0) || (D_82F21160[1].unk_00 != 0)) {
            return;
        }
    } else if ((arg0->unk_00 == 0x11) && (func_82F13964(9) == 0)) {
        return;
    }

    if (arg0->unk_0C & 0x20) {
        arg0->unk_0C &= ~0x20;
        func_80048B90(0x01200003);
    }

    arg0->unk_18--;
    arg0->unk_14 = ((arg0->unk_18 * -0x60) / 30) + 0x80;
    arg0->unk_16 = ((arg0->unk_18 << 6) / 30) + 0x40;
    if (arg0->unk_18 <= 0) {
        func_82F0FDEC(0);
    }
}

#ifdef NON_MATCHING
void func_82F10BB4(s16 arg0, s16 arg1, f32 arg2) {
    s16 sp58;
    s16 temp_ft1;
    s16 temp_ft2;
    s32 temp_ft0;
    s32 i;
    s32 var_s2;
    u8* var_s6 = D_3000008;

    temp_ft2 = ROUND_MAX(228.0f * arg2);
    temp_ft1 = ROUND_MAX(19.0f * arg2);
    temp_ft0 = ROUND_MAX(1024.0f / arg2);
    sp58 = ROUND_MAX(-1024.0f / arg2);

    for (i = 0, var_s2 = arg1; i < 11; i++, var_s2 += temp_ft1, var_s6 += 0x876) {
        gDPLoadTextureTile_4b(gDisplayListHead++, var_s6, G_IM_FMT_I, 228, 0, 0, 0, 227, 18, 0,
                              G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                              G_TX_NOLOD, G_TX_NOLOD);

        func_82F0C410(arg0, var_s2, temp_ft2, temp_ft1, 0, 0, temp_ft0, temp_ft0, 0);
        func_82F0C410(arg0 + temp_ft2, var_s2, temp_ft2, temp_ft1, 0x1C60, 0, sp58, temp_ft0, 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/41/fragment41_2942C0/func_82F10BB4.s")
#endif

void func_82F10ED0(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s16 sp6E;
    s16 sp6C;
    s16 sp6A;
    s16 sp68;
    s16 sp66;
    s32 temp_fv1_4;
    s32 sp5C;

    sp6E = ROUND_MAX(48.0f * arg2);
    sp6C = ROUND_MAX(30.0f * arg2);
    sp6A = ROUND_MAX(arg3 * arg2);
    sp68 = ROUND_MAX(arg4 * arg2);
    sp66 = ROUND_MAX(arg5 * arg2);
    sp5C = ROUND_MAX(1024.0f / arg2);
    temp_fv1_4 = ROUND_MAX(-1024.0f / arg2);

    gDPLoadTextureTile_4b(gDisplayListHead++, D_3005D28, G_IM_FMT_I, 48, 0, 0, 0, 47, 29, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                          G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_82F0C410(arg0 + sp6A, arg1 + sp66, sp6E, sp6C, 0, 0, sp5C, sp5C, 0);
    func_82F0C410(arg0 + sp68, arg1 + sp66, sp6E, sp6C, 0x5E0, 0, temp_fv1_4, sp5C, 0);
}

void func_82F11264(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s16 sp6E;
    s16 sp6C;
    s16 sp6A;
    s16 sp68;
    s16 sp66;
    s32 temp_fv1_4;
    s32 sp5C;

    sp6E = ROUND_MAX(24.0f * arg2);
    sp6C = ROUND_MAX(30.0f * arg2);
    sp6A = ROUND_MAX(arg3 * arg2);
    sp68 = ROUND_MAX(arg4 * arg2);
    sp66 = ROUND_MAX(arg5 * arg2);
    sp5C = ROUND_MAX(1024.0f / arg2);
    temp_fv1_4 = ROUND_MAX(-1024.0f / arg2);

    gDPLoadTextureTile_4b(gDisplayListHead++, D_300D108, G_IM_FMT_I, 24, 0, 0, 0, 23, 29, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                          G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_82F0C410(arg0 + sp6A, arg1 + sp66, sp6E, sp6C, 0, 0, sp5C, sp5C, 0);
    func_82F0C410(arg0 + sp68, arg1 + sp66, sp6E, sp6C, 0x2E0, 0, temp_fv1_4, sp5C, 0);
}

void func_82F115F8(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s16 sp6E;
    s16 sp6C;
    s16 sp6A;
    s16 sp68;
    s16 sp66;
    s32 temp_fv1_4;
    s32 sp5C;

    sp6E = ROUND_MAX(16.0f * arg2);
    sp6C = ROUND_MAX(14.0f * arg2);
    sp6A = ROUND_MAX(arg3 * arg2);
    sp68 = ROUND_MAX(arg4 * arg2);
    sp66 = ROUND_MAX(arg5 * arg2);
    sp5C = ROUND_MAX(1024.0f / arg2);
    temp_fv1_4 = ROUND_MAX(-1024.0f / arg2);

    gDPLoadTextureTile_4b(gDisplayListHead++, D_300D278, G_IM_FMT_I, 16, 0, 0, 0, 15, 13, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                          G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_82F0C410(arg0 + sp6A, arg1 + sp66, sp6E, sp6C, 0, 0, sp5C, sp5C, 0);
    func_82F0C410(arg0 + sp68, arg1 + sp66, sp6E, sp6C, 0x1E0, 0, temp_fv1_4, sp5C, 0);
}

void func_82F1198C(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s16 spB6;
    s16 i;
    s32 sp60;
    u8* var_s5;
    s16 temp_fa0;
    s16 temp_fa0_2;
    s16 temp_fv1_2;
    s16 var_s4;
    s16 var_t3;
    s16 temp_ft0;
    s32 temp_ft1;

    spB6 = ROUND_MAX(100.0f * arg2);
    temp_fa0 = ROUND_MAX(arg3 * arg2);
    temp_fv1_2 = ROUND_MAX(arg4 * arg2);
    temp_fa0_2 = ROUND_MAX(arg5 * arg2);
    temp_ft1 = ROUND_MAX(1024.0f / arg2);
    sp60 = ROUND_MAX(-1024.0f / arg2);

    var_s4 = 0;
    var_s5 = D_3006000;
    var_t3 = 0;
    for (i = 0x83; i > 0;) {
        if ((i - 0x48) >= 0) {
            var_t3 = 0x48;
        } else {
            var_t3 = i;
        }

        gDPLoadTextureTile_4b(gDisplayListHead++, var_s5, G_IM_FMT_I, 100, 0, 0, 0, 99, var_t3, 0,
                              G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                              G_TX_NOLOD, G_TX_NOLOD);

        i -= var_t3;
        temp_ft0 = var_t3 * arg2;
        func_82F0C410(arg0 + temp_fa0, arg1 + temp_fa0_2 + var_s4, spB6, temp_ft0, 0, 0, temp_ft1, temp_ft1, 0);
        func_82F0C410(arg0 + temp_fv1_2, arg1 + temp_fa0_2 + var_s4, spB6, temp_ft0, 0xC60, 0, sp60, temp_ft1, 0);
        var_s5 += 0xE10;
        var_s4 += temp_ft0;
    }
}

void func_82F11D68(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    static Gfx D_82F14020[] = {
        gsDPPipeSync(),
        gsDPSetCycleType(G_CYC_2CYCLE),
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsDPSetCombineLERP(NOISE, 0, TEXEL1, 0, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT,
                           0, 0, 0, COMBINED),
        gsDPSetEnvColor(200, 255, 255, 255),
        gsSPEndDisplayList(),
    };

    s16 spE6;
    s16 i;
    s32 sp6C;
    s32 sp60;
    u8* var_fp;
    u8* var_s7;
    s16 temp_fa0;
    s16 temp_fv1_2;
    s16 temp_fv1_3;
    s16 var_ra;
    s16 var_s6;
    s16 temp_ft0;

    spE6 = ROUND_MAX(100.0f * arg2);
    if (1) {}
    temp_fv1_2 = ROUND_MAX(arg3 * arg2);
    temp_fa0 = ROUND_MAX(arg4 * arg2);
    temp_fv1_3 = ROUND_MAX(arg5 * arg2);
    sp6C = ROUND_MAX(1024.0f / arg2);
    sp60 = ROUND_MAX(-1024.0f / arg2);

    var_s6 = 0;
    var_s7 = D_3009DC8;
    var_fp = D_300B768;
    i = 0x83;

    gSPDisplayList(gDisplayListHead++, D_82F14020);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 100, 100, 255, arg6);

    for (; i > 0;) {
        if ((i - 0x20) >= 0) {
            var_ra = 0x20;
        } else {
            var_ra = i;
        }

        gDPLoadMultiTile_4b(gDisplayListHead++, var_fp, 0x0100, 1, G_IM_FMT_I, 100, 0, 0, 0, 99, var_ra, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        i -= var_ra;
        temp_ft0 = var_ra * arg2;

        gDPLoadMultiTile_4b(gDisplayListHead++, var_s7, 0x0000, G_TX_RENDERTILE, G_IM_FMT_I, 100, 0, 0, 0, 99, var_ra,
                            0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        func_82F0C410(arg0 + temp_fv1_2, arg1 + temp_fv1_3 + var_s6, spE6, temp_ft0, 0, 0, sp6C, sp6C, 0x100000);
        func_82F0C410(arg0 + temp_fa0, arg1 + temp_fv1_3 + var_s6, spE6, temp_ft0, 0xC60, 0, sp60, sp6C, 0x100000);
        var_s7 += 0x640;
        var_fp += 0x640;
        var_s6 += temp_ft0;
    }
}

void func_82F1228C(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s16 sp76;
    s16 sp74;
    s16 sp72;
    s16 sp70;
    s16 sp6E;
    UNUSED s32 pad;
    s16 sp5C;
    s32 sp60;

    sp76 = ROUND_MAX(64.0f * arg2);
    sp74 = ROUND_MAX(64.0f * arg2);
    sp72 = ROUND_MAX(arg3 * arg2);
    sp70 = ROUND_MAX(arg4 * arg2);
    sp6E = ROUND_MAX(arg5 * arg2);
    sp60 = ROUND_MAX(1024.0f / arg2);
    sp5C = ROUND_MAX(-1024.0f / arg2);

    gDPLoadTextureTile_4b(gDisplayListHead++, D_30079A0, G_IM_FMT_I, 64, 0, 0, 0, 63, 63, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                          G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_82F0C410(arg0 + sp72, arg1 + sp6E, sp76, sp74, 0, 0, sp60, sp60, 0);
    func_82F0C410(arg0 + sp70, arg1 + sp6E, sp76, sp74, 0x7E0, 0, sp5C, sp60, 0);
}

void func_82F12614(void) {
    static f32 D_82F14050 = 0.0f;
    static f32 D_82F14054 = 0.0f;
    static f32 D_82F14058 = 0.0f;
    static f32 D_82F1405C = 0.0f;
    static Gfx D_82F14060[] = {
        gsDPPipeSync(),
        gsDPSetCycleType(G_CYC_2CYCLE),
        gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
        gsDPSetCombineLERP(TEXEL0, TEXEL1, PRIM_LOD_FRAC, TEXEL1, 0, 0, 0, PRIMITIVE, PRIMITIVE, ENVIRONMENT, COMBINED,
                           ENVIRONMENT, 0, 0, 0, COMBINED),
        gsDPSetPrimColor(0, 0x80, 55, 255, 255, 255),
        gsDPSetEnvColor(0, 0, 255, 255),
        gsSPEndDisplayList(),
    };

    f32 temp_fa0;
    f32 temp_fa4;
    f32 temp_fa8;
    f32 temp_faC;

    func_80006498(&gDisplayListHead, D_82F2115C);

    gSPDisplayList(gDisplayListHead++, D_82F14060);

    gDPLoadMultiBlock_4b(gDisplayListHead++, D_3009BC0, 0x0100, 1, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, 1);

    temp_fa8 = D_82F14058 + 31.0f;
    temp_faC = D_82F1405C + 31.0f;
    if (1) {}
    gDPSetTileSize(gDisplayListHead++, 1, D_82F14058 * 4.0f, D_82F1405C * 4.0f, temp_fa8 * 4.0f, temp_faC * 4.0f);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30099B8, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, 2);

    temp_fa0 = D_82F14050 + 31.0f;
    temp_fa4 = D_82F14054 + 31.0f;
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, D_82F14050 * 4.0f, D_82F14054 * 4.0f, temp_fa0 * 4.0f,
                   temp_fa4 * 4.0f);

    func_8001C330(0, 0, 0x20, 0x20, 0, 0, 0x400, 0x400, 0x100000);

    D_82F14050 += 0.75f;
    if (D_82F14050 >= 32.0f) {
        D_82F14050 -= 32.0f;
    }

    D_82F14054 += 5.75f;
    if (D_82F14054 >= 32.0f) {
        D_82F14054 -= 32.0f;
    }

    D_82F1405C -= 2.5f;
    if (D_82F1405C < 0.0f) {
        D_82F1405C += 32.0f;
    }

    gDPPipeSync(gDisplayListHead++);

    func_800079C4();
}

void func_82F12DE4(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5) {
    static Gfx D_82F14098[] = {
        gsDPPipeSync(),
        gsDPSetCycleType(G_CYC_2CYCLE),
        gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
        gsDPSetCombineLERP(0, 0, 0, TEXEL1, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
        gsDPSetEnvColor(0, 0, 0, 60),
        gsSPEndDisplayList(),
    };

    s16 sp96;
    s16 sp94;
    s16 sp92;
    s16 sp90;
    s16 sp8E;
    UNUSED s32 pad;
    s32 temp_fa0_3;
    s32 sp80;

    func_82F12614();

    sp96 = ROUND_MAX(64.0f * arg2);
    sp94 = ROUND_MAX(64.0f * arg2);
    sp92 = ROUND_MAX(arg3 * arg2);
    sp90 = ROUND_MAX(arg4 * arg2);
    sp8E = ROUND_MAX(arg5 * arg2);
    sp80 = ROUND_MAX(1024.0f / arg2);
    temp_fa0_3 = ROUND_MAX(-1024.0f / arg2);

    gSPDisplayList(gDisplayListHead++, D_82F14098);
    gDPLoadMultiBlock(gDisplayListHead++, D_82F2115C->img_p, 0x0100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                      G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 1, 1);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30081A8, G_IM_FMT_I, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_82F0C410(arg0 + sp92, arg1 + sp8E, sp96, sp94, 0, 0, sp80, sp80, 0x100000);
    func_82F0C410(arg0 + sp90, arg1 + sp8E, sp96, sp94, 0x7E0, 0, temp_fa0_3, sp80, 0x100000);
}

void func_82F13278(void) {
    func_82F0FDEC(0);
    func_82F0EF68();
    func_82F0C630();
    func_82F0D084();
    D_82F2115C = func_80006314(0, 2, 0x20, 0x20, 1);
}

void func_82F132D0(void) {
    switch (D_82F21140.unk_00) {
        case 0:
            func_82F10034(&D_82F21140);
            break;

        case 1:
            func_82F10110(&D_82F21140);
            break;

        case 2:
        case 4:
            func_82F101C8(&D_82F21140);
            break;

        case 3:
            func_82F10348(&D_82F21140);
            break;

        case 6:
            func_82F10400(&D_82F21140);
            break;

        case 7:
            func_82F10454(&D_82F21140);
            break;

        case 8:
        case 9:
            func_82F1050C(&D_82F21140);
            break;

        case 10:
            func_82F10674(&D_82F21140);
            break;

        case 11:
            func_82F10710(&D_82F21140);
            break;

        case 12:
            func_82F10744(&D_82F21140);
            break;

        case 13:
            func_82F10818(&D_82F21140);
            break;

        case 14:
            func_82F1084C(&D_82F21140);
            break;

        case 15:
            func_82F1091C(&D_82F21140);
            break;

        case 16:
            func_82F10950(&D_82F21140);
            break;

        case 5:
        case 17:
            func_82F10A24(&D_82F21140);
            break;
    }
    func_82F0F89C();
    func_82F0CB90();
    func_82F0DCF4();
}

void func_82F13414(void) {
    unk_D_82F21140* ptr = &D_82F21140;
    u8 sp83;
    s32 var_v0_2;
    s32 tmp1;

    if (ptr->unk_0E > 0) {
        ptr->unk_0E--;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, ptr->unk_14, ptr->unk_14, ptr->unk_14, 255);

    func_82F10BB4(ptr->unk_02, ptr->unk_04, ptr->unk_10);
    tmp1 = D_82F14424 & 0x3F;
    sp83 = (ptr->unk_16 * tmp1) / 63u;
    if (D_82F14424 & 0x40) {
        sp83 = ptr->unk_16 - sp83;
    }

    if (ptr->unk_0C & 1) {
        if (func_82F00524() == 1) {
            tmp1 = D_82F14424 & 3;
            sp83 = (tmp1 * 0xFF) / 3u;
            if (D_82F14424 & 4) {
                sp83 = 0xFF - sp83;
            }
        }
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    if (ptr->unk_0C & 0x10) {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sp83);
        func_82F10ED0(ptr->unk_02, ptr->unk_04, ptr->unk_10, ptr->unk_06, ptr->unk_08, ptr->unk_0A);
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    func_82F0FCC0();
    func_82F0CC3C();

    tmp1 = D_82F14424 & 0x3F;
    sp83 = (tmp1 * 0xFF) / 63u;
    if (D_82F14424 & 0x40) {
        sp83 = 0xFF - sp83;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sp83);

    tmp1 = D_82F14424 & 0x3F;
    sp83 = ((tmp1) << 7) / 63u;
    if (D_82F14424 & 0x40) {
        sp83 = 0x80 - sp83;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sp83);

    if (ptr->unk_0C & 2) {
        func_82F11264(ptr->unk_02, ptr->unk_04, ptr->unk_10, 0xB4, 0xFA, 0x73);
    }

    if (ptr->unk_0C & 4) {
        func_82F115F8(ptr->unk_02, ptr->unk_04, ptr->unk_10, 0xD4, 0xE4, 2);
    }

    if (ptr->unk_0C & 4) {
        if (ptr->unk_0C & 0x40) {
            var_v0_2 = 0x64;
        } else {
            var_v0_2 = 0x32;
        }
        func_82F11D68(ptr->unk_02, ptr->unk_04, ptr->unk_10, 0x81, 0xE5, 0, var_v0_2);

        gSPDisplayList(gDisplayListHead++, D_8006F518);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sp83);

        if (!(ptr->unk_0C & 0x40)) {
            func_82F1198C(ptr->unk_02, ptr->unk_04, ptr->unk_10, 0x81, 0xE5, 0);
        }
    }

    if (ptr->unk_0C & 8) {
        if (ptr->unk_0C & 0x20) {
            func_82F12DE4(ptr->unk_02, ptr->unk_04, ptr->unk_10, 0x23, 0x164, 0x68);
        } else {
            func_82F1228C(ptr->unk_02, ptr->unk_04, ptr->unk_10, 0x23, 0x164, 0x68);
        }
    }

    func_82F0EE58();
    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

s32 func_82F13964(s16 arg0) {
    unk_D_82F21160* ptr = &D_82F21160[0];
    s32 var_v1 = 0;

    switch (arg0) {
        case 1:
            if ((D_82F21140.unk_00 == 3) && (D_82F21140.unk_18 == 0)) {
                var_v1 = 1;
            }
            break;

        case 2:
            if ((D_82F21140.unk_00 == 7) && (D_82F21140.unk_18 == 0)) {
                var_v1 = 1;
            }
            break;

        case 3:
            if (D_82F21140.unk_00 == 0) {
                var_v1 = 1;
            }
            break;

        case 4:
            if ((D_82F21160[0].unk_00 == 2) && (ptr[0].unk_1C <= 1.0f)) {
                var_v1 = 1;
            }
            break;

        case 5:
            if ((D_82F21160[1].unk_00 == 2) && (ptr[1].unk_1C <= 1.0f)) {
                var_v1 = 1;
            }
            break;

        case 6:
            if (D_82F21140.unk_00 == 0xA) {
                var_v1 = 1;
            }
            break;

        case 8:
            if ((D_82F21160[0].unk_00 == 7) && (D_82F21160[1].unk_00 == 7)) {
                var_v1 = 1;
            }
            break;

        case 7:
        case 9:
            if ((D_82F21160[0].unk_00 == 0) && (D_82F21160[1].unk_00 == 0)) {
                var_v1 = 1;
            }
            break;

        case 10:
            if (D_82F21140.unk_00 == 0) {
                var_v1 = 1;
            }
            break;

        case 11:
            if (D_82F21238.unk_02 == 0) {
                var_v1 = 1;
            }
            break;

        case 12:
            if (D_82F21238.unk_02 == 2) {
                var_v1 = 1;
            }
            break;
    }

    return var_v1;
}

void func_82F13B4C(s16 arg0) {
    D_82F21140.unk_0E = arg0;
}

s16 func_82F13B64(void) {
    return D_82F21140.unk_00;
}
