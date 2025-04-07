#include "2E460.h"
#include "src/20330.h"
#include "src/22630.h"
#include "src/232C0.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/49790.h"
#include "src/6A40.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static OSMesgQueue D_800AF750;
static s32 D_800AF768;

static Color_RGBA8 D_800758A0[] = {
    { 0xF0, 0xF0, 0xF0, 0xFF },
    { 0xE1, 0xE1, 0xE1, 0xFF },
};

static u32 D_800758A8[] = {
    D_04001878, D_040018E0, D_04001948, D_040019B0, D_04001A18, D_04001A80, D_04001AF0,
    D_04001B58, D_04001BC0, D_04001C28, 0x10,       0x10,       0x10,       D_4001010,
};

unk_func_88500020 D_800758E0 = {
    0x00000014,
    0x00000014,
    0x00000014,
    D_4001C90,
};

unk_func_88500020 D_800758F0[] = {
    {
        0x00000014,
        0x00000014,
        0x00000014,
        D_4001FB8,
    },
    {
        0x00000018,
        0x00000018,
        0x00000018,
        D_4006AB8,
    },
};

void func_8002D860(unk_func_8002D860* arg0, s32 arg1) {
    if (func_80024F00(arg1) != 0) {
        arg0->unk_00 = 1;
    } else {
        arg0->unk_00 = 0;
        arg0->unk_08 = func_80025084(arg1);
        func_800251B0(arg1, &arg0[1]);
    }
    arg0->unk_04 = func_80024F68(arg1);
}

void func_8002D8C8(unk_func_88500020* arg0, s32 arg1, s32 a2) {
    s32 temp_lo;
    s32 var_t0;
    u8* var_s2;
    s32 i;
    s32 arg2;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    temp_lo = 0x1000 / (arg0->unk_00 * 2);
    var_s2 = arg0->unk_0C;
    arg2 = a2;
    i = arg0->unk_04;

    while (i > 0) {
        if (temp_lo < i) {
            var_t0 = temp_lo;
        } else {
            var_t0 = i;
        }

        gDPLoadTextureBlock(gDisplayListHead++, var_s2, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg0->unk_00, var_t0, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, arg1 << 2, arg2 << 2, ((arg1 + arg0->unk_08) - 1) << 2,
                            ((arg2 + var_t0) - 1) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

        i -= var_t0;
        arg2 += var_t0;
        var_s2 += var_t0 * arg0->unk_00 * 2;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
}

s32 func_8002DCB8(unk_func_8002DCB8_arg0* arg0, s32 arg1) {
    s32 ret = 0;

    switch (arg1) {
        case 0x800:
            func_80048B90(1);
            if (arg0->unk_04 == 0) {
                arg0->unk_04 += arg0->unk_08;
            }
            arg0->unk_04--;
            ret = 1;
            break;

        case 0x400:
            func_80048B90(1);
            if (arg0->unk_04 >= (arg0->unk_08 - 1)) {
                arg0->unk_04 -= arg0->unk_08;
            }
            arg0->unk_04++;
            ret = 1;
            break;
    }

    return ret;
}

s32 func_8002DD64(s32 arg0) {
    s32 sp1C = func_8001F750() & 0xFFFF;

    func_8002DCB8(arg0, sp1C);
    return sp1C;
}

s32 func_8002DD98(unk_func_8002DD98_arg0* arg0, s32 arg1) {
    s32 ret = 0;

    switch (arg1) {
        case 0x200:
            func_80048B90(1);
            if (arg0->unk_04 == 0) {
                arg0->unk_04 += arg0->unk_08;
            }
            arg0->unk_04--;
            ret = 1;
            break;

        case 0x100:
            func_80048B90(1);
            if (arg0->unk_04 >= (arg0->unk_08 - 1)) {
                arg0->unk_04 -= arg0->unk_08;
            }
            arg0->unk_04++;
            ret = 1;
            break;
    }

    return ret;
}

s32 func_8002DE44(unk_func_8002DD98_arg0* arg0) {
    s32 sp1C = func_8001F750() & 0xFFFF;

    func_8002DD98(arg0, sp1C);
    return sp1C;
}

void func_8002DE78(unk_func_8002DE78_arg0* arg0) {
    s32 temp_v0 = func_8001F750();
    s32 sp18 = arg0->unk_0C;

    if (gPlayer1Controller->buttonDown & 0x2000) {
        sp18 = ((arg0->unk_08 - arg0->unk_04) + 1) / 10;
    }

    switch (temp_v0) {
        case 0x800:
            func_80048B90(1);
            if (arg0->unk_00 - sp18 < arg0->unk_04) {
                arg0->unk_00 = arg0->unk_04;
            } else {
                arg0->unk_00 -= sp18;
            }
            break;

        case 0x400:
            func_80048B90(1);
            if (arg0->unk_08 < arg0->unk_00 + sp18) {
                arg0->unk_00 = arg0->unk_08;
            } else {
                arg0->unk_00 += sp18;
            }
            break;
    }
}

s32 func_8002DF68(unk_func_8830867C_044_038_030* arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a2;
    s32 var_t1;
    s32 i;

    var_t1 = 0;
    var_a2 = 1;

    for (i = arg0->unk_10; i > 0; i--) {
        var_a2 *= 10;
    }

    switch (arg1) {
        case 0x200:
            temp_v0 = arg0->unk_10 + 1;
            if (temp_v0 < arg0->unk_0C) {
                arg0->unk_10 = temp_v0;
                func_80048B90(1);
                var_t1 = 9;
            } else {
                var_t1 = 8;
            }
            break;

        case 0x100:
            if (arg0->unk_10 > 0) {
                arg0->unk_10--;
                func_80048B90(1);
                var_t1 = 9;
            } else {
                var_t1 = 8;
            }
            break;

        case 0x800:
            if (arg0->unk_00 == arg0->unk_08) {
                arg0->unk_00 = arg0->unk_00 - ((arg0->unk_00 / var_a2) * var_a2);
                if (arg0->unk_00 < arg0->unk_04) {
                    arg0->unk_00 = arg0->unk_04;
                }
            } else {
                arg0->unk_00 += var_a2;
                if (arg0->unk_08 < arg0->unk_00) {
                    arg0->unk_00 = arg0->unk_08;
                }
            }
            func_80048B90(1);
            var_t1 = 9;
            break;

        case 0x400:
            if (arg0->unk_00 == arg0->unk_04) {
                arg0->unk_00 = arg0->unk_08;
            } else {
                arg0->unk_00 -= var_a2;
                if (arg0->unk_00 < arg0->unk_04) {
                    arg0->unk_00 = arg0->unk_04;
                }
            }
            func_80048B90(1);
            var_t1 = 9;
            break;
    }
    return var_t1;
}

s32 func_8002E0F4(unk_func_8820E99C_030_030* arg0) {
    s32 sp1C = func_8001F750() & 0xFFFF;

    func_8002DF68(arg0, sp1C);
    return sp1C;
}

s32 func_8002E128(unk_func_8002E128_arg0* arg0) {
    s32 sp1C = func_8001F750() & 0xFFFF;
    s32 sp18 = arg0->unk_0C;

    if (sp1C != 0) {
        func_80048B90(1);

        switch (sp1C) {
            case 0x200:
                sp18 *= 0xA;

            case 0x800:
                if (arg0->unk_00 >= arg0->unk_08) {
                    arg0->unk_00 = arg0->unk_04;
                } else if (arg0->unk_08 < (arg0->unk_00 + sp18)) {
                    arg0->unk_00 = arg0->unk_08;
                } else {
                    arg0->unk_00 = arg0->unk_00 + sp18;
                }
                break;

            case 0x100:
                sp18 *= 0xA;

            case 0x400:
                if (arg0->unk_04 >= arg0->unk_00) {
                    arg0->unk_00 = arg0->unk_08;
                } else if ((arg0->unk_00 - sp18) < arg0->unk_04) {
                    arg0->unk_00 = arg0->unk_04;
                } else {
                    arg0->unk_00 = arg0->unk_00 - sp18;
                }
                break;
        }
    }

    return sp1C;
}

void func_8002E244(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 temp_lo;
    s32 var_s3;
    s32 var_t5 = 0x05F5E100;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    var_s3 = 0;

    for (i = 9; i > 0;) {
        temp_lo = arg2 / var_t5;
        i--;

        if ((temp_lo != 0) || (var_s3 != 0) || (i == 0)) {
            var_s3 = 1;

            gDPLoadTextureBlock(gDisplayListHead++, D_800758A8[temp_lo], G_IM_FMT_IA, G_IM_SIZ_8b, 8, 12, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + 8) << 2, (arg1 + 0xC) << 2,
                                G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
            arg0 += 9;
        }

        arg2 %= var_t5;
        var_t5 /= 10;
    }
}

void func_8002E5A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_t0 = 1;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    while (arg3 > 0) {
        arg3--;
        if ((arg2 > 0) || (var_t0 != 0)) {
            gDPLoadTextureBlock(gDisplayListHead++, D_800758A8[arg2 % 10], G_IM_FMT_IA, G_IM_SIZ_8b, 8, 12, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, (arg0 + (arg3 * 9)) << 2, arg1 << 2, ((arg0 + (arg3 * 9)) + 8) << 2,
                                (arg1 + 0xC) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        }
        arg2 /= 10;
        var_t0 = 0;
    }
}

void func_8002E8E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    while (arg3 > 0) {
        arg3--;
        gDPLoadTextureBlock(gDisplayListHead++, D_800758A8[arg2 % 10], G_IM_FMT_IA, G_IM_SIZ_8b, 8, 12, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (arg0 + (arg3 * 9)) << 2, arg1 << 2, ((arg0 + (arg3 * 9)) + 8) << 2,
                            (arg1 + 0xC) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        arg2 /= 10;
    }
}

s32 func_8002EBD8(unk_func_8002EBD8_arg0* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_08 & 0x4000) {
        var_v1 = -1;
    } else if (arg0->unk_08 & 0x8000) {
        var_v1 = 1;
    }

    return var_v1;
}

s32 func_8002EC08(s32 arg0) {
    static s32 D_80075910[] = { 0, 0, 1, 2, 0, 0, 0, 3, 0, 0, 0, 0 };

    return D_80075910[arg0];
}

Color_RGBA8 func_8002EC1C(Color_RGBA8 arg0, f32 arg1) {
    static Color_RGBA8 D_80075940 = { 0xC8, 0xC8, 0xC8, 0xFF };

    Color_RGBA8 sp4;

    sp4.r = (s32)((arg0.r - D_80075940.r) * arg1) + D_80075940.r;
    sp4.g = (s32)((arg0.g - D_80075940.g) * arg1) + D_80075940.g;
    sp4.b = (s32)((arg0.b - D_80075940.b) * arg1) + D_80075940.b;
    sp4.a = arg0.a;

    return sp4;
}

static u8 pad_D_80075944[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

s32 func_8002ECDC(unk_func_80026268_arg0* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (arg0->unk_09[i] == 0) {
            break;
        }
    }

    return i;
}

ret_func_8002ED08* func_8002ED08(s32 arg0) {
    if ((arg0 <= 0) || (arg0 >= 0xA6)) {
        return NULL;
    }
    return &D_80072338[arg0 - 1];
}

unk_D_80072B00* func_8002ED40(s32 arg0) {
    if ((arg0 <= 0) || (arg0 >= 0xA6)) {
        return NULL;
    }
    return &D_80072B00[arg0 - 1];
}

s32 func_8002ED78(unk_func_80026268_arg0* arg0, s32 arg1) {
    s32 temp_v0 = arg0->unk_00.unk_00 - 1;
    s32 var_v1;

    if (arg1 == 1) {
        if (D_80070FA0[temp_v0].unk_06 == D_80070FA0[temp_v0].unk_07) {
            return -1;
        }
        var_v1 = D_80070FA0[temp_v0].unk_07;
    } else {
        var_v1 = D_80070FA0[temp_v0].unk_06;
    }
    return var_v1;
}

s32 func_8002EDEC(s32 arg0) {
    s32 ret;

    if (arg0 >= 0x14) {
        ret = arg0 - 0xC;
    } else if (arg0 >= 7) {
        ret = arg0 - 1;
    } else {
        ret = arg0;
    }

    return ret;
}

s32 func_8002EE1C(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp1C;

    switch (arg0) {
        case 32:
        case 33:
        case 34:
        case 35:
            sp1C = func_80024A48(arg0, arg1, arg2);
            break;

        case 16:
        case 17:
        case 18:
            sp1C = func_800275E0(arg0, arg2);
            break;
    }
    return sp1C;
}

void func_8002EE78(void) {
    osCreateMesgQueue(&D_800AF750, &D_800AF768, 1);
}

void func_8002EEA8(OSMesg arg0) {
    osSendMesg(&D_800AF750, arg0, 1);
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_8002EEEC(void) {
    osSendMesg(&D_800AF750, NULL, 1);
}

void func_8002EF18(OSMesg arg0) {
    osRecvMesg(&D_800AF750, arg0, 1);
}

void func_8002EF44(void) {
    s32 game_state;
    s32 var_s4;

    FRAGMENT_LOAD_AND_CALL(fragment33, 1, 0);

    if (func_80029080() == -1) {
        gCurrentGameState = STATE_AREA_SELECT;
        return;
    }

    var_s4 = 0;
    game_state = STATE_POKEMON_LAB;

    do {
        if (game_state == STATE_POKEMON_LAB) {
            main_pool_push_state('PLAB');

            if (func_80029080() != -1) {
                func_80028AFC(3);
                func_80023D60(func_80029080());
            }

            func_80005E40(0x16000, 0);
            func_80007678(func_80007444(1, 1, 2, 0, 2, 1));

            FRAGMENT_LOAD_AND_CALL2(fragment22, var_s4, 0);

            while ((game_state == STATE_POKEMON_LAB) && (D_800AE520.unk_00 != 0)) {
                D_800AE520.unk_00 = 0;
                game_state = func_80029008(D_800AE520.fragment_id, D_800AE520.rom_start, D_800AE520.rom_end,
                                           D_800AE520.arg0, D_800AE520.arg1);
            }

            func_800076C0();
            func_80005EAC();

            main_pool_pop_state('PLAB');
        } else {
            switch (game_state) {
                case 0x10000:
                    FRAGMENT_LOAD_AND_CALL(fragment41, 0, 0);
                    var_s4 = 2;
                    game_state = STATE_POKEMON_LAB;
                    break;

                case 0x10001:
                    FRAGMENT_LOAD_AND_CALL(fragment33, 0, 0);
                    var_s4 = 1;
                    game_state = STATE_POKEMON_LAB;
                    break;
            }
        }
    } while (game_state != STATE_AREA_SELECT);

    gCurrentGameState = STATE_AREA_SELECT;
}

s32 func_8002F1C0(s32 arg0) {
    static u8 D_80075950[] = {
        5,    6,    8,    9,    0x1F, 0x29, 0x2A, 0x2B, 0x2D, 0x30, 0x3F, 0x40, 0x45,
        0x46, 0x47, 0x48, 0x49, 0x4A, 0x4C, 0x4D, 0x4E, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8,
    };

    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80075950); i++) {
        if (arg0 == D_80075950[i]) {
            return 1;
        }
    }

    return 0;
}

s32 func_8002F264(s32 arg0) {
    s32 sp1C = 0;

    if (func_8002F1C0(arg0) != 0) {
        sp1C = 1;
    }
    return sp1C;
}

unk_D_8007596C D_8007596C[] = {
    { 0x0000, 0x0000 }, { 0x00CC, 0x0096 }, { 0x012F, 0x0122 }, { 0x025F, 0x08A2 }, { 0x00C8, 0x00BE },
    { 0x0133, 0x01A4 }, { 0x01FB, 0x07D0 }, { 0x006C, 0x00C8 }, { 0x012F, 0x01F4 }, { 0x01F7, 0x0762 },
    { 0x0064, 0x003C }, { 0x00CC, 0x00DC }, { 0x0133, 0x02C6 }, { 0x0064, 0x0046 }, { 0x00C8, 0x00DC },
    { 0x012F, 0x028A }, { 0x0064, 0x0028 }, { 0x0133, 0x0294 }, { 0x019B, 0x0366 }, { 0x0064, 0x0050 },
    { 0x00CC, 0x019A }, { 0x0064, 0x0028 }, { 0x0137, 0x0348 }, { 0x025F, 0x0096 }, { 0x0452, 0x0596 },
    { 0x0068, 0x0082 }, { 0x00CF, 0x0294 }, { 0x00C8, 0x0104 }, { 0x012F, 0x028A }, { 0x0068, 0x0096 },
    { 0x00CF, 0x01B8 }, { 0x0193, 0x0528 }, { 0x006C, 0x00C8 }, { 0x00D3, 0x01AE }, { 0x0197, 0x055A },
    { 0x00C8, 0x00AA }, { 0x0193, 0x0370 }, { 0x00C8, 0x00DC }, { 0x0133, 0x01B8 }, { 0x006C, 0x0078 },
    { 0x012F, 0x0104 }, { 0x00CF, 0x00AA }, { 0x01F7, 0x04BA }, { 0x006C, 0x0078 }, { 0x00CF, 0x00BE },
    { 0x0137, 0x019A }, { 0x0064, 0x0078 }, { 0x012F, 0x028A }, { 0x012F, 0x0294 }, { 0x019B, 0x0118 },
    { 0x0008, 0x0014 }, { 0x00CC, 0x02DA }, { 0x0068, 0x005A }, { 0x012F, 0x02C6 }, { 0x00CF, 0x01AE },
    { 0x01FB, 0x069A }, { 0x006C, 0x026C }, { 0x012F, 0x02C6 }, { 0x00CC, 0x01A4 }, { 0x025B, 0x0D5C },
    { 0x00C8, 0x010E }, { 0x012F, 0x01B8 }, { 0x0193, 0x04A6 }, { 0x00D3, 0x01AE }, { 0x0193, 0x04E2 },
    { 0x019B, 0x0424 }, { 0x00CF, 0x01AE }, { 0x019B, 0x060E }, { 0x01F7, 0x0B36 }, { 0x00CC, 0x005A },
    { 0x012F, 0x008C }, { 0x01FB, 0x0154 }, { 0x00D3, 0x03E8 }, { 0x01F7, 0x04BA }, { 0x0068, 0x01B8 },
    { 0x012F, 0x0910 }, { 0x0197, 0x19DC }, { 0x012F, 0x0294 }, { 0x01FB, 0x082A }, { 0x0137, 0x0316 },
    { 0x01F7, 0x06C2 }, { 0x0064, 0x0082 }, { 0x012F, 0x0528 }, { 0x00CF, 0x014A }, { 0x0197, 0x035C },
    { 0x01FF, 0x0758 }, { 0x0133, 0x07BC }, { 0x01FB, 0x0A5A }, { 0x00D3, 0x0294 }, { 0x0137, 0x0294 },
    { 0x0064, 0x005A }, { 0x019B, 0x0B68 }, { 0x0193, 0x0002 }, { 0x01F7, 0x0002 }, { 0x019B, 0x037A },
    { 0x0AFA, 0x1216 }, { 0x012F, 0x02C6 }, { 0x01F7, 0x0686 }, { 0x0068, 0x008C }, { 0x0193, 0x0528 },
    { 0x006C, 0x00E6 }, { 0x0137, 0x05BE }, { 0x0068, 0x003C }, { 0x025F, 0x0A5A }, { 0x0068, 0x008C },
    { 0x012F, 0x03DE }, { 0x019B, 0x044C }, { 0x0197, 0x0456 }, { 0x0137, 0x05A0 }, { 0x00C8, 0x0014 },
    { 0x0137, 0x00D2 }, { 0x012F, 0x09EC }, { 0x025B, 0x0A5A }, { 0x0133, 0x02F8 }, { 0x012F, 0x0302 },
    { 0x02BF, 0x06E0 }, { 0x0068, 0x00B4 }, { 0x0137, 0x0226 }, { 0x00C8, 0x014A }, { 0x0193, 0x035C },
    { 0x00CF, 0x02F8 }, { 0x0133, 0x06E0 }, { 0x0193, 0x04B0 }, { 0x019B, 0x04CE }, { 0x0197, 0x0384 },
    { 0x0133, 0x0294 }, { 0x0193, 0x03D4 }, { 0x019B, 0x04BA }, { 0x0197, 0x079E }, { 0x00D3, 0x00DC },
    { 0x0838, 0x143C }, { 0x0322, 0x12F2 }, { 0x0064, 0x005A }, { 0x0064, 0x008C }, { 0x012F, 0x0280 },
    { 0x00CF, 0x021C }, { 0x00D3, 0x0226 }, { 0x00CF, 0x0320 }, { 0x0068, 0x00AA }, { 0x012F, 0x0302 },
    { 0x006C, 0x00FA }, { 0x0193, 0x037A }, { 0x01FF, 0x0514 }, { 0x0263, 0x279C }, { 0x01FB, 0x04C4 },
    { 0x01F7, 0x0488 }, { 0x025F, 0x0528 }, { 0x01FF, 0x0046 }, { 0x0515, 0x0168 }, { 0x02BF, 0x1216 },
    { 0x025F, 0x0A82 }, { 0x0068, 0x005A }, { 0, 0 },
};

s32 D_80075BD0[] = {
    0x00000000, 0x00000B90, 0x00001720, 0x000022B0, 0x00002E40, 0x000039D0, 0x00004560, 0x000050F0, 0x00005C80,
    0x00006810, 0x000073A0, 0x00007F30, 0x00008AC0, 0x00009650, 0x0000A1E0, 0x0000AD70, 0x0000B900, 0x0000C490,
    0x0000D020, 0x0000DBB0, 0x0000E740, 0x0000F2D0, 0x0000FE60, 0x000109F0, 0x00011580, 0x00012110, 0x00012CA0,
    0x00013830, 0x000143C0, 0x00014F50, 0x00015AE0, 0x00016670, 0x00017200, 0x00017D90, 0x00018920, 0x000194B0,
    0x0001A040, 0x0001ABD0, 0x0001B760, 0x0001C2F0, 0x0001CE80, 0x0001DA10, 0x0001E5A0, 0x0001F130, 0x0001FCC0,
    0x00020850, 0x000213E0, 0x00021F70, 0x00022B00, 0x00023690, 0x00024220, 0x00024DB0, 0x00025940, 0x000264D0,
    0x00027060, 0x00027BF0, 0x00028780, 0x00029310, 0x00029EA0, 0x0002AA30, 0x0002B5C0, 0x0002C150, 0x0002CCE0,
    0x0002D870, 0x0002E400, 0x0002EF90, 0x0002FB20, 0x000306B0, 0x00031240, 0x00031DD0, 0x00032960, 0x000334F0,
    0x00034080, 0x00034C10, 0x000357A0, 0x00036330, 0x00036EC0, 0x00037A50, 0x000385E0, 0x00039170, 0x00039D00,
    0x0003A890, 0x0003B420, 0x0003BFB0, 0x0003CB40, 0x0003D6D0, 0x0003E260, 0x0003EDF0, 0x0003F980, 0x00040510,
    0x000410A0, 0x00041C30, 0x000427C0, 0x00043350, 0x00043EE0, 0x00044A70, 0x00045600, 0x00046190, 0x00046D20,
    0x000478B0, 0x00048440, 0x00048FD0, 0x00049B60, 0x0004A6F0, 0x0004B280, 0x0004BE10, 0x0004C9A0, 0x0004D530,
    0x0004E0C0, 0x0004EC50, 0x0004F7E0, 0x00050370, 0x00050F00, 0x00051A90, 0x00052620, 0x000531B0, 0x00053D40,
    0x000548D0, 0x00055460, 0x00055FF0, 0x00056B80, 0x00057710, 0x000582A0, 0x00058E30, 0x000599C0, 0x0005A550,
    0x0005B0E0, 0x0005BC70, 0x0005C800, 0x0005D390, 0x0005DF20, 0x0005EAB0, 0x0005F640, 0x000601D0, 0x00060D60,
    0x000618F0, 0x00062480, 0x00063010, 0x00063BA0, 0x00064730, 0x000652C0, 0x00065E50, 0x000669E0, 0x00067570,
    0x00068100, 0x00068C90, 0x00069820, 0x0006A3B0, 0x0006AF40, 0x0006BAD0, 0x0006C660, 0x0006D1F0, 0x0006DD80,
    0x00000000, 0x00000000, 0x00000000,
};
