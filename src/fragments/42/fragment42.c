#include "fragment42.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/2E110.h"
#include "src/20470.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/4BDC0.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/C030.h"
#include "src/controller.h"
#include "src/fragments/43/fragment43.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_833031B4 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16* unk_0C;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s32 unk_14;
} unk_D_833031B4; // size = 0x18

typedef struct unk_D_83303180 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ s16 unk_08;
} unk_D_83303180; // size = 0xC

static s32 D_833032E0;
static s32 D_833032E4;
static unk_D_83407B38 D_833032E8;
static BinArchive* D_8330339C;
static s32 D_833033A0;
static unk_D_83403C60 D_833033A8;
static s32 D_83303434;
static s32 D_83303438;
static s32 D_8330343C;
static s32 D_83303440;
static s32 D_83303444;

static unk_D_83303180 D_83303180[] = {
    { NULL, 0x30, 0x23, 0 },
    { D_03002A40, 0x20, 0x24, 7 },
    { NULL, 0x30, 0x23, 8 },
};

static s16 D_833031A4[] = { 0x11 };
static s16 D_833031A8[] = { 0x12 };
static s16 D_833031AC[] = { 0x13 };
static s16 D_833031B0[] = { -1, 0x15 };

static unk_D_833031B4 D_833031B4[] = {
    {
        D_03001000,
        48,
        35,
        5,
        11,
        NULL,
        1,
        0,
        28,
    },
    {
        D_3001D20,
        48,
        35,
        6,
        12,
        D_833031A4,
        1,
        0,
        28,
    },
    {
        D_03002A40,
        32,
        36,
        7,
        13,
        D_833031A8,
        1,
        0,
        28,
    },
    {
        NULL,
        48,
        35,
        8,
        14,
        D_833031AC,
        1,
        0,
        28,
    },
    {
        D_03003340,
        32,
        36,
        61,
        62,
        NULL,
        1,
        0,
        2,
    },
    {
        D_03003C40,
        32,
        36,
        -1,
        -1,
        D_833031B0,
        1,
        0,
        28,
    },
    {
        NULL,
        0,
        0,
        10,
        16,
        NULL,
        2,
        0,
        3,
    },
};
static s16 D_8330325C[2] = { 0x108, 0x108 };
static s16 D_83303260[2] = { 0x5C, 0x5C };
static s16 D_83303264[2] = { 0x98, 0x4C };
static s16 D_83303268[2] = { 0x7A, 0x3D };
static s32 D_8330326C[] = { 5, 3, 3, 0, 0, 7, 8 };

void func_83300020(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg7);

    func_8001CADC(arg0 - 7, arg1 - 7, 8, 8, &D_300BE40, 8, 0);
    func_8001CADC((arg0 + arg2) - 1, arg1 - 7, 8, 8, &D_300BE80, 8, 0);
    func_8001C330(arg0 + 1, arg1 - 7, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    func_8001CADC(arg0 - 7, (arg1 + arg3) - 1, 8, 8, &D_300BEC0, 8, 0);
    func_8001C330(arg0 - 7, arg1 + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);
    func_8001CADC((arg0 + arg2) - 1, (arg1 + arg3) - 1, 8, 8, &D_300BF00, 8, 0);
    func_8001C330(arg0 + 1, (arg1 + arg3) - 1, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 1, arg1 + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    func_8001C604(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

unk_D_83407B38* func_83300300(void) {
    unk_D_83407B38* ret;

    if (D_83407AE4 == 0) {
        ret = &D_833032E8;
    } else {
        ret = &D_83407B38;
    }
    return ret;
}

void func_8330032C(void) {
    unk_D_833031B4* ptr;
    s32 sp28;
    s32 i;
    s32 sp20;
    s16 sp1C[2];
    u8* sp18;
    s32 var_v0;

    sp28 = func_83400704(D_83403C60, 0x24, 1);
    if (D_83407AE4 == 0) {
        sp1C[1] = 0xF;
        sp1C[0] = 0x14;
        var_v0 = func_83400704(D_83407ABC, 4, 1);
        sp20 = 4;
        sp18 = D_3004540;
    } else {
        sp1C[1] = 0x3F;
        sp1C[0] = 0x40;
        var_v0 = func_83400704(D_83407AC0, 0x10, 1);
        sp20 = 0x10;
        sp18 = D_3005260;
    }

    ptr = &D_833031B4[0];

    for (i = 0; i < 7; i++, ptr++) {
        switch (i) {
            case 1:
            case 2:
                if (sp28 > 0) {
                    ptr->unk_12 = 0;
                } else {
                    ptr->unk_12 = 1;
                }
                break;

            case 3:
                if (var_v0 > 0) {
                    ptr->unk_12 = 0;
                } else {
                    ptr->unk_12 = 1;
                }
                ptr->unk_00 = sp18;
                break;

            case 5:
                if (D_83407AE8 == 0) {
                    ptr->unk_08 = 9;
                    ptr->unk_0A = sp1C[1];
                } else {
                    ptr->unk_08 = 0x44;
                    ptr->unk_0A = 0x46;
                }

                D_833031B0[0] = sp1C[0];

                if ((var_v0 < sp20) && (D_83407AE8 == 0)) {
                    ptr->unk_12 = 1;
                } else if (D_8330343C == 0) {
                    ptr->unk_12 = 2;
                } else {
                    ptr->unk_12 = 0;
                }
                break;

            default:
                ptr->unk_12 = 0;
                break;
        }
    }
}

s32 func_833005CC(void) {
    s32 sp1C = 0;

    if (func_83400334() != 0) {
        D_833032E4 = 6;
        func_83402CE4(3, gPlayer1Controller);
        D_83303438 = 4;
    } else {
        sp1C = 1;
    }
    return sp1C;
}

s32 func_83300628(void) {
    s32 sp2C;
    s32 sp28;
    unk_D_833031B4* sp24;
    s32 sp20;
    s32 sp1C;

    sp2C = 0;
    sp28 = 0;
    sp20 = D_83407AE8;
    sp1C = D_83402E28;

    if (func_8003181C(func_83300300()->unk_20, 0x25) != -1) {
        return 0;
    }

    if (gPlayer1Controller->buttonPressed & 0x800) {
        D_83402E28--;
        if (D_83402E28 < 0) {
            D_83402E28 = 6;
        }
    } else if (gPlayer1Controller->buttonPressed & 0x400) {
        D_83402E28++;
        if (D_83402E28 >= 7) {
            D_83402E28 = 0;
        }
    } else if (gPlayer1Controller->buttonPressed & 0x4000) {
        sp2C = 1;
        D_83402E28 = 6;
    }

    if (sp1C != D_83402E28) {
        func_80048B90(1);
    }

    sp24 = &D_833031B4[D_83402E28];

    if (sp1C != D_83402E28) {
        D_833033A0 = 0;
        D_83303444 = 0;
    }

    if ((D_83407AEC != 0) && (D_83303444 == 0)) {
        if ((gPlayer1Controller->buttonDown & 0x20) && (gPlayer1Controller->buttonDown & 0x10) && (D_83402E28 == 5)) {
            D_83407AE8 = 1;
        } else {
            D_83407AE8 = 0;
        }
    }

    if (sp20 != D_83407AE8) {
        D_833033A0 = 0;
        func_8330032C();
    }

    if (sp2C != 0) {
        if (func_833005CC() != 0) {
            sp28 = 1;
        }
        func_80048B90(sp24->unk_14);
    } else if (gPlayer1Controller->buttonPressed & 0x8000) {
        if (sp24->unk_12 == 0) {
            switch (D_83402E28) {
                default:
                    sp28 = 1;
                    break;

                case 3:
                    D_833032E0 = 2;
                    D_833032E4 = 3;
                    break;

                case 4:
                    D_83407AE4 ^= 1;
                    func_8330032C();
                    break;

                case 5:
                    if (D_83407AE8 != 0) {
                        sp28 = 2;
                    } else {
                        D_833032E4 = 5;
                        D_83303434 = 0;
                    }
                    break;

                case 6:
                    if (func_833005CC() != 0) {
                        sp28 = 1;
                    }
                    break;
            }
            func_80048B90(sp24->unk_14);
        } else if ((D_83402E28 == 5) && (D_83407AE8 != 0)) {
            sp28 = 2;
            func_80048B90(sp24->unk_14);
        } else {
            D_833033A0 = 1;
            func_80048B90(8);
        }
    }
    return sp28;
}

void func_83300938(void) {
    D_833032E0 = 0;
    D_833032E4 = 1;
    func_834006BC(&D_83407B30);
}

s32 func_83300970(unk_D_83407B38* arg0) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    unk_func_80031270* sp38;
    UNUSED s32 pad[2];
    s32 idx;
    unk_func_80031270* sp28;

    sp4C = 0;
    sp48 = arg0->unk_00;
    func_83402210(arg0, &sp44, &sp40, sp48);
    if (func_8003181C(arg0->unk_20, 0x25) != -1) {
        return 0;
    }

    if (gPlayer1Controller->buttonPressed & 0x800) {
        sp40--;
        if (sp40 < 0) {
            sp40 = arg0->unk_1C - 1;
        }
    }

    if (gPlayer1Controller->buttonPressed & 0x400) {
        sp40++;
        if (sp40 >= arg0->unk_1C) {
            sp40 = 0;
        }
    }

    if (gPlayer1Controller->buttonPressed & 0x200) {
        sp44--;
        if (sp44 < 0) {
            sp44 = arg0->unk_18 - 1;
        }
    }

    if (gPlayer1Controller->buttonPressed & 0x100) {
        sp44++;
        if (sp44 >= arg0->unk_18) {
            sp44 = 0;
        }
    }

    arg0->unk_00 = func_83402280(arg0, sp44, sp40);
    if (arg0->unk_00 != sp48) {
        func_80048B90(1);
    }

    if (gPlayer1Controller->buttonPressed & 0x8000) {
        sp3C = (arg0->unk_08 * arg0->unk_14) + arg0->unk_00;
        sp38 = arg0->unk_20[sp3C];
        if (arg0->unk_04 == -1) {
            if (func_800317D8(sp38) != 0) {
                arg0->unk_04 = sp3C;
                arg0->unk_B0->unk_18 = sp38->unk_18;
                arg0->unk_B0->unk_00 = 0;
                func_80048B90(2);
            } else {
                func_80048B90(8);
            }
        } else {
            if ((arg0->unk_04 >= 0) && (arg0->unk_04 < arg0->unk_14)) {
                if (sp3C != arg0->unk_04) {
                    sp38->unk_00 = 0;
                    arg0->unk_20[arg0->unk_04]->unk_00 = 0;
                    func_83400590(sp38->unk_18, arg0->unk_B0->unk_18);
                    func_80048B90(0x29);
                } else {
                    func_80048B90(3);
                }
            } else {
                if (func_83400660(arg0->unk_B0->unk_18, sp38->unk_18) == 0) {
                    func_80048B90(0x31);
                    D_833032E4 = 4;

                    D_833033A8 = *sp38->unk_18;
                    *sp38->unk_18 = *arg0->unk_B0->unk_18;

                    sp38->unk_00 = 0;
                } else {
                    func_80048B90(3);
                    func_83300938();
                }
            }
            arg0->unk_04 = -1;
        }
    } else if (gPlayer1Controller->buttonPressed & 0x4000) {
        if (arg0->unk_04 == -1) {
            D_833032E0 = 0;
            D_833032E4 = 1;
        } else {
            if (arg0->unk_04 >= 4) {
                func_834006BC(&D_83407B30);
                D_833032E0 = 0;
                D_833032E4 = 1;
            }
            arg0->unk_04 = -1;
        }
        func_80048B90(3);
    } else if (gPlayer1Controller->buttonPressed & 4) {
        idx = (arg0->unk_08 * arg0->unk_14) + arg0->unk_00;
        if (arg0->unk_04 == -1) {
            sp28 = arg0->unk_20[idx];
        } else {
            sp28 = arg0->unk_B0;
        }

        if ((arg0->unk_04 == -1) && (func_800317D8(sp28) != 0)) {
            sp4C = 1;
            func_80048B90(0x19);
            func_83400694(sp28->unk_18);
        } else {
            func_80048B90(8);
        }
    }

    return sp4C;
}

void func_83300D80(u16* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6) {
    s32 temp_fa0;
    s32 temp_fa0_2;
    s32 temp_fv1;
    s32 temp_fv1_2;
    s32 tmp = G_TX_NOMIRROR | G_TX_CLAMP;

    if ((arg5 == 0.0f) || (arg6 == 0.0f)) {
        return;
    }

    gDPLoadTextureTile(gDisplayListHead++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg3, 0, 0, 0, arg3, arg4 - 1, 0, tmp,
                       tmp, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    temp_fv1 = ROUND_MAX(arg3 * arg5);
    temp_fa0 = ROUND_MAX(arg4 * arg6);
    temp_fv1_2 = ROUND_MAX(arg3 * (arg5 - 1.0f) * 0.5f);
    temp_fv1_2 = -temp_fv1_2;
    temp_fa0_2 = ROUND_MAX(arg4 * (arg6 - 1.0f) * 0.5f);

    func_8001C330(arg1 + temp_fv1_2, arg2 - temp_fa0_2, temp_fv1, temp_fa0, 0, 0, 1024.0f / arg5, 1024.0f / arg6, 0);
}

#ifdef NON_MATCHING
void func_83301090(void) {
    static s16 D_83303288 = 0;
    static s16 D_8330328C = 0x3200;

    f32 temp_fs0;
    f32 temp_fs1;
    s32 temp_s2;
    s32 temp_t0;
    char* temp_v0_4;
    s32 i;
    u8 tmp;
    u8 tmp2;
    u8 r;

    temp_fs0 = (SINS(D_83303288) * 0.2f) + 1.0f;
    temp_fs1 = (SINS(D_83303288 + D_8330328C) * 0.2f) + 1.0f;

    D_83303288 += 0x2000;

    for (i = 0; i < 7; i++) {
        tmp = (D_833031B4[i].unk_12 == 0) ? 0xFF : 0x40;

        if (D_833031B4[i].unk_10 == 1) {
            func_83300020(0x46, 0x4E + i * 0x36, 0x7F, 0x18, 0x1E, 0x1E, 0x82, tmp);
        } else {
            func_83300020(0x46, 0x4E + i * 0x36, 0x7F, 0x18, 0x1E, 0x64, 0x1E, tmp);
        }
    }

    func_833023D8(func_83300300());

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 7; i++) {
        temp_t0 = 0xC - D_833031B4[i].unk_04;

        if (D_833031B4[i].unk_12 == 0) {
            r = 0xFF;
        } else {
            r = 0x40;
        }

        if (D_833031B4[i].unk_00 != NULL) {
            gDPPipeSync(gDisplayListHead++);

            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, r);

            if ((i == D_83402E28) && (D_833031B4[i].unk_12 == 0)) {
                func_83300D80(D_833031B4[i].unk_00, temp_t0 + 0x46, (i * 0x36) + 0x48, D_833031B4[i].unk_04,
                              D_833031B4[i].unk_06, temp_fs0, temp_fs1);
            } else {
                func_8340144C(D_833031B4[i].unk_00, temp_t0 + 0x46, (i * 0x36) + 0x48, D_833031B4[i].unk_04,
                              D_833031B4[i].unk_06, 0);
            }
        }
    }

    func_8001F3F4();
    func_8001EBE0(8, 0);

    for (i = 0; i < 7; i++) {
        temp_v0_4 = func_83402374(D_833031B4[i].unk_08);
        temp_s2 = ((0x73 - func_8001F5B0(0, 0, temp_v0_4)) / 2) + 0xC;
        tmp2 = (D_833031B4[i].unk_12 == 0) ? 0xFFu : 0x40u;

        func_8001F324(0xFF, 0xFF, 0xFF, tmp2);
        func_8001F1E8(temp_s2 + 0x46, 0x50 + i * 0x36, temp_v0_4);
    }

    func_8001F444();
}
#else
static s16 D_83303288 = 0;
static s16 D_8330328C = 0x3200;
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/42/fragment42/func_83301090.s")
#endif

void func_833013C4(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp3C;
    UNUSED s32 pad;
    char* sp34;
    Color_RGBA8 sp30 = { 0x9A, 0x37, 0x54, 0xFF };
    Color_RGBA8 sp2C = { 0xC3, 0x54, 0x84, 0xFF };
    unk_D_83303180* sp20;

    func_83401110(arg0, arg1, 0x186, &sp30, &sp2C);

    if ((D_833032E0 != 0) && (D_833032E0 != 2)) {
        sp20 = &D_83303180[arg2];
    } else if (D_83407AE4 == 0) {
        sp20 = &D_83303180[arg2];
        do {
            sp20->unk_00 = D_3004540;
        } while (0);
    } else {
        sp20 = &D_83303180[arg2];
        sp20->unk_00 = D_3005260;
    }

    if (sp20->unk_00 != NULL) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_8340144C(sp20->unk_00, arg0 + 0x10, arg1 - 1, sp20->unk_04, sp20->unk_06, 0);
    }

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    sp34 = func_83402374(sp20->unk_08);
    sp3C = (0x186 - func_8001F5B0(0, 0, sp34)) / 2;
    func_8001F324(0, 0, 0, 0xFF);
    func_8001F1E8(arg0 + sp3C + 2, arg1 + 5, sp34);
    func_8001F324(0xFF, 0xFF, 0x77, 0xFF);
    func_8001F1E8(arg0 + sp3C, arg1 + 3, sp34);
    func_8001F444();
}

void func_833015C8(unk_D_83407B38* arg0, s32 arg1, s32 arg2) {
    unk_D_833031B4* temp_v1 = &D_833031B4[D_83402E28];
    char* sp18 = NULL;

    switch (D_833032E0) {
        case 0:
            if (D_833032E4 == 5) {
                switch (D_83303434) {
                    case 0:
                        if (D_83407AE8 == 0) {
                            sp18 = func_83402374(0x1B);
                        } else {
                            sp18 = func_83402374(0x45);
                        }
                        break;

                    case 1:
                        sp18 = func_83402374(0x1D);
                }
                break;
            } else if ((D_833033A0 != 0) && (temp_v1->unk_0C != NULL)) {
                sp18 = func_83402374(temp_v1->unk_0C[temp_v1->unk_12 - 1]);
            } else {
                sp18 = func_83402374(temp_v1->unk_0A);
            }
            break;

        case 1:
            if (D_833032E4 == 4) {
                sp18 = func_83402374(0x17);
            } else {
                sp18 = func_83402374(0x16);
            }
            break;

        case 2:
            if (arg0->unk_04 == -1) {
                sp18 = func_83402374(0x19);
            } else {
                sp18 = func_83402374(0x1A);
            }
            break;
    }

    func_834008DC(arg1, arg2, 0x186, 0x4C);

    if (sp18 != NULL) {
        if (1) {}
        if (1) {}
        if (1) {}
        func_8001F3F4();
        func_8001EBE0(8, 0);
        func_8001F3B4(0x14);
        func_8001F1E8(arg1 + 0xA, arg2 + 8, sp18);
        func_8001F444();
    }
}

void func_833017BC(s32 arg0, s32 arg1) {
    unk_D_83407B38* temp_v0_2;
    unk_D_86002F58_004_000_010* sp30;

    switch (arg0) {
        case 1:
            D_833032E0 = 1;
            break;

        case 2:
            D_833032E0 = 2;
            break;

        default:
            D_833032E0 = 0;
            break;
    }

    D_833032E4 = 0;
    D_83303438 = -1;
    D_833033A0 = 0;
    D_83303434 = 0;
    D_83303444 = 0;

    if (arg1 == 0) {
        D_83407AE8 = 0;
    } else {
        D_83407AE8 = 1;
        D_83303444 = 1;
    }

    if (func_8000B4C4() != 0) {
        D_8330343C = 1;
    } else {
        D_8330343C = 0;
    }

    func_83400524();
    func_8330032C();
    func_8001BB20();
    sp30 = func_80019760(5);
    func_83401D68(&D_833032E8, 0x3C, 0x2D, 4, 2, sp30, D_8330339C, D_83407ABC, 4, 1);
    func_83402298(&D_83407B38, sp30, D_8330339C);

    if (D_833032E0 == 1) {
        temp_v0_2 = func_83300300();
        temp_v0_2->unk_04 = 0x400;
        temp_v0_2->unk_B0->unk_18 = &D_83403C60[D_83407B30.unk_04];
        temp_v0_2->unk_B0->unk_00 = 0;
    } else if (D_833032E0 == 2) {
        func_834021EC(&D_833032E8, &D_83407B00);
        func_834021EC(&D_83407B38, &D_83407B08);
    }

    func_834028C4();
}

void func_83301998(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGBA8* arg4, Color_RGBA8* arg5) {
    unk_D_80068BB0* temp_s1 = func_8000648C();
    Vtx* temp_s2 = func_80005F5C(sizeof(Vtx) * 4);
    Mtx* sp84 = func_80005F5C(sizeof(Mtx) * 1);
    Vp* sp80 = func_80005F5C(sizeof(Vp) * 1);

    func_8001E6E8(sp80, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp80 & 0x1FFFFFFF);

    guOrtho(sp84, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    func_8001E680(&temp_s2[0], arg0, arg1, -1, 0, 0, arg4->r, arg4->g, arg4->b, arg4->a);
    func_8001E680(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, arg5->r, arg5->g, arg5->b, arg5->a);
    func_8001E680(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, arg4->r, arg4->g, arg4->b, arg4->a);
    func_8001E680(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, arg5->r, arg5->g, arg5->b, arg5->a);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                 G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)sp84 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}

void func_83301D74(void) {
    static Color_RGBA8 D_83303298 = { 0, 0, 0, 0xFF };
    static Color_RGBA8 D_8330329C = { 0, 0, 0, 0 };
    static s32 D_833032A0 = 0xBE;
    static s32 D_833032A4 = 0xFA;

    s32 var_ra;
    Color_RGBA8 sp80 = D_83303298;
    Color_RGBA8 sp7C = D_8330329C;

    if (D_83303438 > 0) {
        D_83303438--;
    }

    if (D_83303438 == 0) {
        var_ra = 0x12C;
    } else {
        var_ra = 0x280;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0, ENVIRONMENT,
                      PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 40, 40, 55, 255);
    gDPSetEnvColor(gDisplayListHead++, 150, 95, 110, 255);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3000000, G_IM_FMT_I, 128, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 7, 6, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(D_833032A0, 0, var_ra - D_833032A0, 0x1E0, 0, 0, 0x400, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
    gSPDisplayList(gDisplayListHead++, D_8006F4C0);
    gDPSetFillColor(gDisplayListHead++, 0x00000001);
    gDPFillRectangle(gDisplayListHead++, 0, 0, D_833032A0 - 1, 479);
    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_83301998(D_833032A0, 0, D_833032A4 - D_833032A0, 0x1E0, &sp80, &sp7C);
}

#ifdef NON_MATCHING
void func_83302068(unk_D_83407B38* arg0) {
    s32 sp8C;
    s32 sp78;
    s32 sp74;
    s32 sp68;
    s32 sp64;
    s16 temp_fp;
    s16 temp_s4;
    s16 temp_s5;
    s32 temp_s0;
    s32 var_s6;
    unk_func_80031270* temp_s1;
    s32 i;
    s32 j;
    s32 tmp1;
    s32 tmp2;
    s32 tmp3;
    s32 tmp4;
    s32 new_var3;

    temp_fp = D_8330325C[D_83407AE4];
    temp_s4 = D_83303264[D_83407AE4];
    temp_s5 = D_83303268[D_83407AE4];
    sp8C = D_83303260[D_83407AE4];

    if (D_83407AE4 == 0) {
        var_s6 = 4;
    } else {
        var_s6 = 1;
    }

    for (i = 0; i < arg0->unk_14; i++) {
        temp_s0 = (arg0->unk_08 * arg0->unk_14) + i;
        func_83402210(arg0, &sp78, &sp74, i);
        temp_s1 = arg0->unk_20[temp_s0];

        if ((i != arg0->unk_04) && (func_800317D8(temp_s1) != 0) && (temp_s1->unk_00 == 2)) {
            for (j = 0; j < var_s6; j++) {
                func_834018C0(temp_s1->unk_08->img_p, (temp_s4 * sp78) + temp_fp + ((temp_s4 / 2) * (j % 2)),
                              (temp_s5 * sp74) + sp8C + ((temp_s5 / 2) * (j / 2)), temp_s1->unk_04, temp_s1->unk_06, 8,
                              1);
            }
        }
    }

    if (arg0->unk_04 != -1) {
        func_83402210(arg0, &sp68, &sp64, arg0->unk_00);
        temp_s1 = arg0->unk_B0;
        if ((func_800317D8(temp_s1) != 0) && (temp_s1->unk_00 == 2)) {
            for (j = 0; j < var_s6; j++) {
                func_83401818((temp_s4 * sp68) + temp_fp + ((temp_s4 / 2) * (j % 2)),
                              (temp_s5 * sp64) + sp8C + ((temp_s5 / 2) * (j / 2)), temp_s1->unk_04, temp_s1->unk_06);

                func_834018C0(temp_s1->unk_08->img_p, ((temp_s4 * sp68) + temp_fp + ((temp_s4 / 2) * (j % 2))) - 0x10,
                              ((temp_s5 * sp64) + sp8C + ((temp_s5 / 2) * (j / 2))) - 0x10, temp_s1->unk_04,
                              temp_s1->unk_06, 8, 1);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/42/fragment42/func_83302068.s")
#endif

void func_833023D8(unk_D_83407B38* arg0) {
    unk_func_80031270* temp_s0;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 var_a2;
    s32 var_a3;
    s32 var_v0;

    sp50 = D_8330325C[D_83407AE4];
    sp4C = D_83303260[D_83407AE4];
    sp48 = D_83303264[D_83407AE4];
    sp44 = D_83303268[D_83407AE4];
    temp_s0 = arg0->unk_B0;
    func_83402210(arg0, &sp58, &sp54, arg0->unk_00);

    switch (D_833032E0) {
        case 0:
            gSPDisplayList(gDisplayListHead++, D_8006F518);
            func_83401B48(0x3E, (D_83402E28 * 0x36) + 0x46, 0x8F, 0x28);
            break;

        case 2:
            gSPDisplayList(gDisplayListHead++, D_8006F518);

            if (arg0->unk_04 == -1) {
                var_v0 = 0;
            } else {
                var_v0 = -0x10;
            }

            if (D_83407AE4 == 0) {
                var_a2 = (temp_s0->unk_04 * 2) + 0x18;
                var_a3 = (temp_s0->unk_06 * 2) + 0x18;
            } else {
                var_a2 = temp_s0->unk_04 + 8;
                var_a3 = temp_s0->unk_06 + 8;
            }
            func_83401B48(((sp48 * sp58) + sp50 + var_v0) - 4, ((sp44 * sp54) + sp4C + var_v0) - 4, var_a2, var_a3);
            break;

        case 1:
            if ((arg0->unk_04 != -1) && (func_800317D8(temp_s0) != 0) && (temp_s0->unk_00 == 2)) {
                gSPDisplayList(gDisplayListHead++, D_8006F518);

                if (D_83407AE4 == 0) {
                    var_a2 = (temp_s0->unk_04 * 2) + 0x18;
                    var_a3 = (temp_s0->unk_06 * 2) + 0x18;
                } else {
                    var_a2 = temp_s0->unk_04 + 8;
                    var_a3 = temp_s0->unk_06 + 8;
                }
                func_83401B48(((sp48 * sp58) + sp50) - 0x14, ((sp44 * sp54) + sp4C) - 0x14, var_a2, var_a3);
            }
            break;
    }
}

void func_8330267C(s32 arg0) {
    s8* sp2C;
    s32 temp_v1;

    sp2C = func_83402374(0x3C);
    temp_v1 = ((0x186 - func_8001F5B0(0, 0, sp2C)) / 2) + 0xD5;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(temp_v1 - 0x20, arg0 - 2, 0x18, 0x18, D_30099B8, 0x18, 0);
    func_8001F3F4();
    func_8001EBE0(8, 0);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F1E8(temp_v1, arg0, sp2C);
    func_8001F444();
}

void func_8330277C(void) {
    UNUSED s32 pad;
    unk_D_83407B38* sp18 = func_83300300();

    func_800079C4();
    func_83301D74();
    func_833013C4(0xD5, 0x24, D_833032E0);
    func_83302068(sp18);
    func_83301090();

    if ((D_833032E0 == 2) && (sp18->unk_04 == -1)) {
        func_8330267C(0x158);
    }

    func_833015C8(sp18, 0xD5, 0x172);
    func_834028D0(1);
    func_80007778();
}

void func_83302820(unk_D_83407B38* arg0) {
    s32 var_a2 = 0;
    s32 idx = (arg0->unk_08 * arg0->unk_14) + arg0->unk_00;
    unk_func_80031270* temp_v1 = arg0->unk_20[idx];

    if (gPlayer1Controller->buttonPressed & 0x8000) {
        func_80048B90(0x29);
        var_a2 = 1;
        func_8330032C();
    } else if (gPlayer1Controller->buttonPressed & 0x4000) {
        *temp_v1->unk_18 = D_833033A8;
        temp_v1->unk_00 = 0;
        func_80048B90(3);
        var_a2 = 1;
    }

    if (var_a2 != 0) {
        func_83300938();
    }
}

void func_833028FC(void) {
    static s32 D_833032A8 = 0;

    if (D_833033A0 != 0) {
        if (D_833032A8 > 0) {
            D_833032A8--;
            if (D_833032A8 == 0) {
                D_83303434 = 1;
                func_80048B90(8);
            }
        }
    }

    if (D_833032A8 <= 0) {
        if (gPlayer1Controller->buttonPressed & 0x8000) {
            func_80048B90(0x1C);
            func_83400410(1, D_8330343C);
            if (D_8330343C != 0) {
                func_8000B6FC(0x5A);
            }
            D_833033A0 = 1;
            D_833032A8 = 4;
        } else if (gPlayer1Controller->buttonPressed & 0x4000) {
            func_80048B90(3);
            D_833032E4 = 1;
            D_833033A0 = 0;
            D_83303434 = 0;
        }
    }
}

void func_833029F0(void) {
    s16 temp_v0;
    s32 var_a2;

    temp_v0 = func_83402DC8(3);
    if (temp_v0 != -1) {
        var_a2 = 0;
        if (temp_v0 == -2) {
            temp_v0 = 2;
        }

        switch (temp_v0) {
            case 0:
                D_833032E4 = 7;
                func_83402CE4(4, gPlayer1Controller);
                var_a2 = 0;
                D_83303440 = 6;
                break;

            case 1:
                var_a2 = 1;
                break;

            default:
                D_833032E4 = 1;
                break;
        }

        if (var_a2 != 0) {
            D_833032E4 = 8;
            func_80007990(0xFFFF);
            func_80006CB4(0xF);
            if (D_8330326C[D_83402E28] == 8) {
                func_8004B9C4(0xF);
            }
        }
    }
}

void func_83302ACC(void) {
    D_83303440--;
    if (D_83303440 <= 0) {
        func_83402D74(4);
        func_83400410(0, D_8330343C);
        D_833032E4 = 8;
        func_80007990(0xFFFF);
        func_80006CB4(0xF);
        if (D_8330326C[D_83402E28] == 8) {
            func_8004B9C4(0xF);
        }
    }
}

s32 func_83302B5C(void) {
    static s32 D_833032AC = 2;

    s32 temp_v0_2;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    unk_D_833031B4* sp1C;
    s32 sp18;

    sp28 = 1;
    sp24 = D_833032E4;
    sp20 = D_83407AE4;
    sp1C = &D_833031B4[D_83402E28];

    switch (D_833032E4) {
        case 0:
            if (func_80007604() == 0) {
                D_833032AC--;
                if (D_833032AC <= 0) {
                    switch (D_833032E0) {
                        case 0:
                            if (D_83407AE8 != 0) {
                                if (sp1C->unk_12 == 0) {
                                    D_833032E4 = 5;
                                    D_83303434 = 0;
                                } else {
                                    D_833032E4 = 1;
                                    D_833033A0 = 1;
                                    func_80048B90(8);
                                }
                            } else {
                                D_833032E4 = 1;
                            }
                            break;

                        case 1:
                            D_833032E4 = 2;
                            break;

                        case 2:
                            D_833032E4 = 3;
                            break;
                    }
                }
            }
            break;

        case 1:
            temp_v0_2 = func_83300628();
            if (temp_v0_2 != 0) {
                D_833032E4 = 8;
                if (temp_v0_2 == 2) {
                    func_80007990(1);
                    sp18 = 8;
                } else {
                    sp18 = 0xF;
                    if (sp18) {}
                    func_80007990(0xFFFF);
                }
                func_80006CB4(sp18);
                if (D_8330326C[D_83402E28] == 8) {
                    func_8004B9C4(sp18);
                }
            }

            if (D_833032E4 != 1) {
                D_83303438 = -1;
            }
            break;

        case 2:
        case 3:
            if (func_83300970(func_83300300()) != 0) {
                D_833032E4 = 8;
                func_80007990(1);
                func_80006CB4(1);
            }
            break;

        case 4:
            func_83302820(func_83300300());
            break;

        case 5:
            func_833028FC();
            break;

        case 6:
            func_833029F0();
            break;

        case 7:
            func_83302ACC();
            break;

        case 8:
            if (func_80007604() == 1) {
                sp28 = 0;
            }
            break;
    }

    if (((sp24 != D_833032E4) && (D_833032E4 == 1)) || (sp20 != D_83407AE4)) {
        D_83303438 = 4;
    }
    return sp28;
}

void func_83302E3C(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_83302E6C(void) {
    s32 var_a0;

    if (D_833032E0 == 2) {
        var_a0 = 1;
    } else {
        var_a0 = 7;
    }
    func_80006C6C(var_a0);

    do {
        func_83302E3C();

        if ((func_83402C6C() != 0) && (D_83303438 == 0)) {
            D_83303438 = -1;
        }

        switch (D_833032E4) {
            case 0:
            case 8:
                break;

            default:
                func_83401FD0(func_83300300());
                break;
        }

        func_8330277C();
        func_834020D8();
    } while (func_83302B5C() != 0);
}

s32 func_83302F48(void) {
    s32 sp1C = D_8330326C[D_83402E28];

    if (func_834006A0(0) != NULL) {
        sp1C = 4;
    }

    if (D_83402E28 == 2) {
        D_83407B30.unk_00 = 1;
    }

    func_834021D8(&D_833032E8, &D_83407B00);
    func_834021D8(&D_83407B38, &D_83407B08);

    return sp1C;
}

void func_83302FD8(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('SNAP');

    func_80005E40(0x20000, 0);
    sp24 = func_80007444(1, 0, 2, 0, 2, 1);
    func_8001E94C(0x18, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, gallery_ui, 0);
    ASSET_LOAD(D_5000000, snap_mode_ui, 0);

    FRAGMENT_LOAD(fragment31);

    func_8001987C();
    D_8330339C = ASSET_LOAD2(stadium_models, 1, 1);
    func_8002D510();
    func_83402340();
    func_833017BC(arg0, arg1);
    func_80007678(sp24);
    func_83302E6C();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('SNAP');

    func_83302F48();
}
