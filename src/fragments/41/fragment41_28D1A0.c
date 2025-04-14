#include "fragment41.h"
#include "src/19840.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/225A0.h"
#include "src/22630.h"
#include "src/2E110.h"
#include "src/49790.h"
#include "src/memory.h"

static unk_D_82F20A10 D_82F20A10;
static s16 D_82F20A38;

void func_82F052F0(unk_D_82F144D0* arg0, u8* arg1, s16 arg2, s16 arg3) {
    unk_D_82F20A10* ptr = &D_82F20A10;

    main_pool_push_state('BBRD');

    ptr->unk_00 = 1;
    ptr->unk_02 = -1;
    ptr->unk_04 = arg2;
    ptr->unk_06 = arg3;
    ptr->unk_0C = 0;
    ptr->unk_0E = 0;
    ptr->unk_08 = arg2;
    ptr->unk_0A = arg3;
    ptr->unk_10 = 6;
    ptr->unk_14 = arg1;
    ptr->unk_18 = arg0;
    ptr->unk_1C = NULL;
    ptr->unk_20 = func_80019760(1);
    ptr->unk_24 = func_8001B1FC(ptr->unk_20, 0xE4, 0xA0, 0, 0, 0xE0, 0xA0, D_3014468);
    ptr->unk_24->unk_00 &= ~2;
    func_8001B2D8(ptr->unk_24, ptr->unk_14, 0x108D);
    func_80048B90(4);
}

void func_82F053F8(unk_D_82F20A10* arg0) {
    arg0->unk_10--;
    arg0->unk_04 = 0x38 - (((0x38 - arg0->unk_08) * arg0->unk_10) / 6);
    arg0->unk_06 = 0x70 - (((0x70 - arg0->unk_0A) * arg0->unk_10) / 6);
    arg0->unk_0C = 0x210 - ((arg0->unk_10 * 0x210) / 6);
    arg0->unk_0E = 0x148 - ((arg0->unk_10 * 0x148) / 6);
    if (arg0->unk_10 <= 0) {
        arg0->unk_00 = 2;
        arg0->unk_02 = 4;
        D_82F20A38 = 0;
    }
}

void func_82F05560(unk_D_82F20A10* arg0) {
    static Controller** D_82F13C10[] = {
        &gPlayer1Controller,
        &gPlayer1Controller,
        &gPlayer1Controller,
        &gPlayer1Controller,
    };

    s16 tmp;
    s32 var_t0;
    Controller* temp_a3;

    arg0->unk_1C = func_8001B9D4(arg0->unk_24);
    temp_a3 = *D_82F13C10[arg0->unk_18->unk_000E];
    var_t0 = 0;
    tmp = D_82F20A38;

    if (temp_a3->buttonPressed & 0x200) {
        D_82F20A38--;
        if (D_82F20A38 < 0) {
            D_82F20A38 = 0;
        }
    }

    if (temp_a3->buttonPressed & 0x100) {
        D_82F20A38++;
        if (D_82F20A38 >= 2) {
            D_82F20A38 = 1;
        }
    }

    if (D_82F20A38 != tmp) {
        func_80048B90(1);
        var_t0 = 0;
    }

    if (temp_a3->buttonPressed & 0x8000) {
        var_t0 = 1;
    } else if (temp_a3->buttonPressed & 0x4000) {
        var_t0 = 1;
        D_82F20A38 = 1;
    }

    if (var_t0 != 0) {
        arg0->unk_00 = 3;
        arg0->unk_02 = -1;
        arg0->unk_10 = 6;
        arg0->unk_1C = 0;
        if (D_82F20A38 == 0) {
            arg0->unk_18->unk_0020 = 1;
            func_80048B90(2);
        } else {
            arg0->unk_18->unk_0020 = 0;
            func_80048B90(3);
        }
    }
}

void func_82F056D0(unk_D_82F20A10* arg0) {
    arg0->unk_10--;
    arg0->unk_04 = arg0->unk_08 - (((arg0->unk_08 - 0x38) * arg0->unk_10) / 6);
    arg0->unk_06 = arg0->unk_0A - (((arg0->unk_0A - 0x70) * arg0->unk_10) / 6);
    arg0->unk_0C = (arg0->unk_10 * 0x210) / 6;
    arg0->unk_0E = (arg0->unk_10 * 0x148) / 6;

    if (arg0->unk_10 <= 0) {
        arg0->unk_00 = 0;
        main_pool_pop_state('BBRD');
    }
}

void func_82F05828(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6) {
    s32 color = RGBA5551(arg4, arg5, arg6, 1);

    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (color << 0x10) | color);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);
}

void func_82F05920(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, 255);

    func_8001CADC(arg0, arg1, 8, 8, D_30387B0, 8, 0);
    func_8001CADC((arg0 + arg2) - 8, arg1, 8, 8, D_30387F0, 8, 0);
    func_8001C330(arg0 + 8, arg1, arg2 - 0x10, 8, 0, 0, 0, 0x400, 0);
    func_8001CADC(arg0, (arg1 + arg3) - 8, 8, 8, D_3038830, 8, 0);
    func_8001C330(arg0, arg1 + 8, 8, arg3 - 0x10, 0, 0, 0x400, 0, 0);
    func_8001CADC((arg0 + arg2) - 8, (arg1 + arg3) - 8, 8, 8, D_3038870, 8, 0);
    func_8001C330(arg0 + 8, (arg1 + arg3) - 8, arg2 - 0x10, 8, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 8, arg1 + 8, 8, arg3 - 0x10, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F4C0);

    func_82F05828(arg0 + 8, arg1 + 8, arg2 - 0x10, arg3 - 0x10, arg4, arg5, arg6);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_82F05C50(s16 arg0, s16 arg1, s32 arg2) {
    s32 temp_v0_3;
    s16 var_a3;
    s16 i;

    if (arg2 != 0) {
        gDPPipeSync(gDisplayListHead++);
        gDPSetBlendColor(gDisplayListHead++, 0, 0, 0, 128);

        for (i = 0; i < 0xA0; i += 8) {
            temp_v0_3 = 0xA0 - i;
            if (temp_v0_3 < 8) {
                var_a3 = temp_v0_3;
            } else {
                var_a3 = 8;
            }
            func_8001C6AC(arg0, arg1 + i, 0xE0, var_a3, (i * 0x1C8) + arg2, 0xE4, 0x200000);
        }
    }
}

void func_82F05D74(s16 arg0, s16 arg1, s16 arg2) {
    static u8* D_82F13C20[] = {
        D_302F6E0, D_302F740, D_302F7A0, D_302F800, D_302F860, D_302F8C0, D_302F928, D_302F988, D_302F9E8, D_302FA48,
    };

    s32 i;
    s32 var_s0;
    s16 var_s4;

    arg2 %= 100;
    var_s0 = 0xA;
    var_s4 = 0;

    for (i = 0; i < 2; i++) {
        s32 temp_lo = arg2 / var_s0;

        if ((temp_lo != 0) || (var_s4 != 0) || (i == 1)) {
            func_8001CADC(arg0, arg1, 8, 0xC, D_82F13C20[temp_lo], 8, 0);
            var_s4 = 1;
        }

        arg0 += 9;
        arg2 %= var_s0;
        var_s0 /= 10;
    }
}

s32 func_82F05F20(s32 arg0) {
    s32 var_v1 = 0;

    if ((arg0 <= 0) || (arg0 >= 0xA6)) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_82F05F40(unk_D_82F20A10* arg0) {
    static Color_RGBA8 D_82F13C48 = { 0xFF, 0xFF, 0xFF, 0xFF };
    static Color_RGB8 D_82F13C4C = { 0x82, 0x1E, 0x1E };
    static Color_RGB8 D_82F13C50 = { 0x96, 0x64, 0x1E };
    static s16 D_82F13C54[] = { 0x122, 0x136, 0x1C, 8 };
    static s16 D_82F13C5C[] = { 0xD3, 0xED, 0x107, 0xED };
    static s16 D_82F13C64[] = { 0x15E, 0x1BA };
    static u8* D_82F13C68[] = {
        D_303E330, D_303FC30, D_3040590, D_3040270, D_303F910, D_303F5F0, D_3040590, D_303FF50,
        D_3040BD0, D_303E650, D_303E970, D_303EFB0, D_303F2D0, D_30408B0, D_303EC90, D_3040EF0,
    };

    s32 i;
    Color_RGB8* var_v0;
    s16 temp_s0;
    s16 temp_s1_2;
    s32 temp_s1_3;
    unk_func_80026268_arg0* sp11C;
    unk_D_80072B00* ptr;
    UNUSED s32 pad;
    char sp94[128];
    char* sp8C[2];
    s32 temp_v0_5;
    s32 var_t0;
    s32 sp80;

    sp8C[0] = func_8002D7C0(NULL, 0, D_82F13B70, 0x12);
    sp8C[1] = func_8002D7C0(NULL, 0, D_82F13B70, 0x13);
    sp11C = arg0->unk_14;
    func_82F022DC(arg0->unk_04, arg0->unk_06, arg0->unk_0C, arg0->unk_0E);

    if ((arg0->unk_0C == 0x210) && (arg0->unk_0E == 0x148)) {
        if (arg0->unk_18->unk_0010 == 0) {
            var_v0 = &D_82F13C4C;
        } else {
            var_v0 = &D_82F13C50;
        }

        if (arg0->unk_02 != 0) {
            func_82F05920(arg0->unk_04, arg0->unk_06, 0x210, 0x24, var_v0->r, var_v0->g, var_v0->b);
            func_82F05920(arg0->unk_04 + 0xE0, arg0->unk_06 + 0x24, 0x130, 0x1C, 0x3C, 0x3C, 0x82);
            func_82F05920(arg0->unk_04 + 0xE0, arg0->unk_06 + 0x40, 0x130, 0x84, 0x3C, 0x3C, 0x82);
            func_82F05920(arg0->unk_04, arg0->unk_06 + 0xC4, 0x210, 0x60, 0x3C, 0x3C, 0x82);
        }

        func_82F05920(arg0->unk_04, arg0->unk_06 + 0x124, 0x210, 0x24, 0x28, 0x28, 0x64);
        func_80020B88(arg0->unk_04 + 0x140, arg0->unk_06 + 0x5A, 0x94, sp11C->unk_02, sp11C->unk_26);

        gSPDisplayList(gDisplayListHead++, D_8006F4E0);

        func_8001C6AC(arg0->unk_04 + 0xF8, arg0->unk_06 + 0xD0, 0x1C, 0x1A, D_302DE68, 0x1C, 0x200000);
        func_8001C6AC(arg0->unk_04 + 0xE2, arg0->unk_06 + 0xEA, 0x1C, 0x1A, D_302E9C8, 0x1C, 0x200000);
        func_8001C6AC(arg0->unk_04 + 0x110, arg0->unk_06 + 0xEA, 0x1C, 0x1A, D_302EF78, 0x1C, 0x200000);
        func_8001C6AC(arg0->unk_04 + 0xF8, arg0->unk_06 + 0x104, 0x1C, 0x1A, D_302E418, 0x1C, 0x200000);

        for (i = 0; i < 4; i++) {
            if (sp11C->unk_09[i] == 0) {
                break;
            }

            if (func_82F05F20(sp11C->unk_09[i]) == 0) {
                func_8001C6AC(D_82F13C54[i] + arg0->unk_04, D_82F13C5C[i] + arg0->unk_06, 0x14, 0x14,
                              D_82F13C68[D_80072338[sp11C->unk_09[i] - 1].unk_01], 0x14, 0x200000);
            }
        }

        func_82F05C50(arg0->unk_04, arg0->unk_06 + 0x24, arg0->unk_1C);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        for (i = 0; i < 4; i++) {
            if (sp11C->unk_09[i] == 0) {
                break;
            }

            if (func_82F05F20(sp11C->unk_09[i]) == 0) {
                ptr = &D_80072B00[sp11C->unk_09[i] - 1];

                var_t0 = ptr->unk_05 / 5;
                if (var_t0 >= 7) {
                    var_t0 = 7;
                }

                sp80 = ((sp11C->unk_20[i] >> 6) * var_t0) + ptr->unk_05;
                func_8001CADC(D_82F13C54[i] + arg0->unk_04 + 0xB6, D_82F13C5C[i] + arg0->unk_06 + 6, 8, 0xC, D_302F528,
                              8, 0);
                func_82F05D74(D_82F13C54[i] + arg0->unk_04 + 0xA4, D_82F13C5C[i] + arg0->unk_06 + 6,
                              sp11C->unk_20[i] & 0x3F);
                func_82F05D74(D_82F13C54[i] + arg0->unk_04 + 0xC0, D_82F13C5C[i] + arg0->unk_06 + 6, sp80);
            }
        }

        func_8001F3F4();
        func_8001EBE0(0x10, 0);
        func_8001F1E8(arg0->unk_04 + 0x10, arg0->unk_06 + 6, sp11C->unk_30);
        func_8001EBE0(0x10, 0);
        func_8001F1E8(arg0->unk_04 + 0xA0, arg0->unk_06 + 6, "%s%d", func_8002D7C0(NULL, 0, D_82F13B74, 0x15),
                      sp11C->unk_24);
        func_8001EBE0(8, 0);
        func_8001F1E8(arg0->unk_04 + 0x12E, arg0->unk_06 + 8, "%s%03d", func_8002D7C0(NULL, 0, D_82F13B74, 0x16),
                      sp11C->unk_00.unk_00);
        func_8001EBE0(8, 0);
        func_8001F1E8(arg0->unk_04 + 0x19C, arg0->unk_06 + 8, func_82F00020(sp11C->unk_00.unk_00));

        temp_s0 = func_800219FC(sp11C->unk_06);
        temp_s1_2 = func_800219FC(sp11C->unk_07);

        func_8001EBE0(8, 0);
        func_8001F1E8(arg0->unk_04 + 0xE4, arg0->unk_06 + 0x28, func_8002D7C0(NULL, 0, D_82F13B70, 0xC));
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F1E8(arg0->unk_04 + 0x120, arg0->unk_06 + 0x28, "1/");
        func_8001F324(D_80071D88[temp_s0].color.r, D_80071D88[temp_s0].color.g, D_80071D88[temp_s0].color.b, 0xFF);
        func_8001F1E8(arg0->unk_04 + 0x13E, arg0->unk_06 + 0x28, "%s", func_82F00090(sp11C->unk_06));

        if (sp11C->unk_06 != sp11C->unk_07) {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F1E8(arg0->unk_04 + 0x19E, arg0->unk_06 + 0x28, "2/");
            func_8001F324(D_80071D88[temp_s1_2].color.r, D_80071D88[temp_s1_2].color.g, D_80071D88[temp_s1_2].color.b,
                          0xFF);
            func_8001F1E8(arg0->unk_04 + 0x1BC, arg0->unk_06 + 0x28, "%s", func_82F00090(sp11C->unk_07));
        }

        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001EBE0(8, 0);
        func_8001F1E8(arg0->unk_04 + 0x144, arg0->unk_06 + 0x44, func_8002D7C0(NULL, 0, D_82F13B74, 8));
        func_8001EBE0(8, 0);
        sprintf(sp94, "%d", sp11C->unk_26);
        func_8001F1E8((arg0->unk_04 - func_8001F5B0(0, 0, sp94)) + 0x1D0, arg0->unk_06 + 0x44, sp94);
        temp_s1_3 = 0x1D0 - func_8001F5B0(0, 0, "999");
        sprintf(sp94, "/");
        temp_v0_5 = func_8001F5B0(0, 0, sp94);
        func_8001F1E8((arg0->unk_04 + temp_s1_3) - temp_v0_5, arg0->unk_06 + 0x44, sp94);
        temp_s1_3 -= temp_v0_5;
        sprintf(sp94, "%d", sp11C->unk_02);
        func_8001F1E8((arg0->unk_04 + temp_s1_3) - func_8001F5B0(0, 0, sp94), arg0->unk_06 + 0x44, sp94);
        func_8001EBE0(8, 0);
        func_8001F1E8(arg0->unk_04 + 0x144, arg0->unk_06 + 0x6A, func_8002D7C0(NULL, 0, D_82F13B70, 0xD));
        func_8001F1E8(arg0->unk_04 + 0x144, arg0->unk_06 + 0x80, func_8002D7C0(NULL, 0, D_82F13B70, 0xE));
        func_8001F1E8(arg0->unk_04 + 0x144, arg0->unk_06 + 0x96, func_8002D7C0(NULL, 0, D_82F13B70, 0xF));
        func_8001F1E8(arg0->unk_04 + 0x144, arg0->unk_06 + 0xAC, func_8002D7C0(NULL, 0, D_82F13B70, 0x10));
        func_8001EBE0(8, 0);

        sprintf(sp94, "%d", sp11C->unk_28);
        func_8001F1E8((arg0->unk_04 - func_8001F5B0(0, 0, sp94)) + 0x1D0, arg0->unk_06 + 0x6A, sp94);
        sprintf(sp94, "%d", sp11C->unk_2A);
        func_8001F1E8((arg0->unk_04 - func_8001F5B0(0, 0, sp94)) + 0x1D0, arg0->unk_06 + 0x80, sp94);
        sprintf(sp94, "%d", sp11C->unk_2C);
        func_8001F1E8((arg0->unk_04 - func_8001F5B0(0, 0, sp94)) + 0x1D0, arg0->unk_06 + 0x96, sp94);
        sprintf(sp94, "%d", sp11C->unk_2E);
        func_8001F1E8((arg0->unk_04 - func_8001F5B0(0, 0, sp94)) + 0x1D0, arg0->unk_06 + 0xAC, sp94);
        func_8001EBE0(8, 0);

        {
            char* sp74;
            Color_RGB8* sp70;
            Color_RGBA8 sp6C;
            s32 j;

            for (i = 0; i < 4; i++) {
                sp6C = D_82F13C48;

                if (sp11C->unk_09[i] == 0) {
                    break;
                }

                if (func_82F05F20(sp11C->unk_09[i]) == 0) {
                    sp70 = &D_80071D88[D_80072338[sp11C->unk_09[i] - 1].unk_01].color;
                    sp74 = func_82F00058(sp11C->unk_09[i]);
                } else {
                    // "？？？？？？？"
                    static const char D_29C080[] = { 0xA1, 0xA9, 0xA1, 0xA9, 0xA1, 0xA9, 0xA1,
                                                     0xA9, 0xA1, 0xA9, 0xA1, 0xA9, 0xA1, 0xA9 };
                    sp70 = &sp6C;
                    sp74 = D_29C080;
                }
                func_8001F324(sp70->r, sp70->g, sp70->b, 0xFF);
                func_8001F1E8(D_82F13C54[i] + arg0->unk_04 + 0x18, D_82F13C5C[i] + arg0->unk_06, sp74);
            }

            func_8001EBE0(0x10, 0);
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F1E8(arg0->unk_04 + 0x10, arg0->unk_06 + 0x12A, func_8002D7C0(NULL, 0, D_82F13B70, 0x11));

            for (i = 0; i < 2; i++) {
                func_8001F1E8(arg0->unk_04 + D_82F13C64[i], arg0->unk_06 + 0x12A, sp8C[i]);
            }

            func_8001F444();

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            {
                s16 sp60[2];

                for (j = 0; j < 2; j++) {
                    sp60[j] = func_8001F5B0(0, 0, sp8C[j]);
                }

                func_82F02CE8((D_82F13C64[D_82F20A38] + arg0->unk_04) - 8, arg0->unk_06 + 0x128,
                              sp60[D_82F20A38] + 0x10, 0x1E);
            }
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        if (arg0->unk_02 > 0) {
            arg0->unk_02--;
        }
    }
}

void func_82F06D50(void) {
    D_82F20A10.unk_00 = 0;
    D_82F20A10.unk_04 = 0;
    D_82F20A10.unk_06 = 0;
    D_82F20A10.unk_0C = 0;
    D_82F20A10.unk_0E = 0;
    D_82F20A10.unk_10 = 0;
    D_82F20A10.unk_14 = NULL;
    D_82F20A10.unk_18 = NULL;
    D_82F20A10.unk_1C = 0;
    D_82F20A10.unk_20 = NULL;
    D_82F20A10.unk_24 = NULL;
}

void func_82F06D88(void) {
    unk_D_82F20A10* ptr = &D_82F20A10;

    if (ptr->unk_00) {
        switch (ptr->unk_00) {
            case 1:
                func_82F053F8(&D_82F20A10);
                break;

            case 2:
                func_82F05560(&D_82F20A10);
                break;

            case 3:
                func_82F056D0(&D_82F20A10);
                break;
        }
    }
}

void func_82F06E04(void) {
    if (D_82F20A10.unk_00 != 0) {
        func_82F05F40(&D_82F20A10);
    }
}

s32 func_82F06E38(void) {
    return D_82F20A10.unk_00;
}
