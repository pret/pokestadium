#include "fragment65.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/4CBC0.h"
#include "src/DDC0.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static char** D_84A03130;
static char** D_84A03134;
static unk_D_84A03138 D_84A03138[4];
static BinArchive* D_84A03168;
static BinArchive* D_84A0316C;
static BinArchive* D_84A03170;
static u8* D_84A03174;
static u8* D_84A03178;
static u8* D_84A0317C;
static unk_func_80027FA0 D_84A03180;
static s16 D_84A03188;

static unk_D_84A02F00 D_84A02F00[] = {
    {
        0x00,      0x00, 154, 390,  118, 362, 96, 278, 48, 70, -32768, 0, 0, 0, 2, { 0x96, 0x64, 0xFF, 0x00 },
        D_3000000, 0,    30,  NULL,
    },
    {
        0x01,      0x00, 238, 416,  210, 392, 184, 304, 48, 70, -32768, 3, 0, 1, 3, { 0x00, 0x9B, 0xFF, 0x00 },
        D_3000D20, 1,    31,  NULL,
    },
    {
        0x02,      0x00, 322, 386,  282, 362, 248, 274, 48, 70, -32768, 4, 2, 2, 0, { 0xFF, 0x5F, 0x0F, 0x00 },
        D_3001A40, 2,    32,  NULL,
    },
    {
        0x03,      0x00, 270, 304,  256, 282, 234, 190, 48, 70, -32768, 5, 3, 5, 0, { 0x8C, 0x37, 0xFF, 0x00 },
        D_3002760, 3,    33,  NULL,
    },
    {
        0x04,      0x00, 214, 286,  188, 266, 168, 180, 48, 70, -32768, 6, 4, 6, 4, { 0xFF, 0x37, 0xFF, 0x00 },
        D_3003480, 4,    34,  NULL,
    },
    {
        0x05,      0x00, 164, 178,  160, 170, 116, 96, 48, 70, -32768, 7, 5, 0, 7, { 0xCD, 0x91, 0x00, 0x00 },
        D_30041A0, 5,    35,  NULL,
    },
    {
        0x06,      0x00, 284, 148,  290, 138, 250, 78, 48, 70, -32768, 0, 8, 6, 8, { 0xFF, 0x00, 0x00, 0x00 },
        D_3004EC0, 6,    36,  NULL,
    },
    {
        0x07,      0x00, 364, 243,  330, 214, 306, 110, 48, 70, -32768, 7, 0, 7, 9, { 0x37, 0xFF, 0xFF, 0x00 },
        D_3005BE0, 7,    37,  NULL,
    },
    {
        0x08,      0x00, 0,  0,    418, 204, 390, 102, 48, 70, -32768, 0, 0, 0, 0, { 0xC8, 0xFF, 0x00, 0x00 },
        D_3006900, -1,   -1, NULL,
    },
    {
        0x09,      0x00, 190, 384,  174, 424, 180, 394, 40, 27, -32768, 0, 0, 0, 0, { 0xFF, 0x64, 0x00, 0x00 },
        D_3008E50, -1,   9,   NULL,
    },
    {
        0x0A,      0x00, 446, 216,  374, 210, 356, 128, 72, 43, -32768, 12, 10, 10, 0, { 0xFF, 0x64, 0x00, 0x00 },
        D_3007620, 10,   10,  NULL,
    },
    {
        0x0B,      0x00, 0,  0,    312, 148, 274, 68, 72, 43, -32768, 0, 11, 0, 0, { 0x00, 0x64, 0xC8, 0x00 },
        D_3008238, -1,   11, NULL,
    },
};

static s16 D_84A030E0 = 0;
static s16 D_84A030E4 = 0;
static s16 D_84A030E8 = 0xFF;
static s16 D_84A030EC = 0;
static s16 D_84A030F0 = 0;

void func_84A00020(u8* arg0, u8* arg1, u8 arg2) {
    s32 i;
    s32 j;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 640, 480);
    gDPSetCombineLERP(gDisplayListHead++, TEXEL1, TEXEL0, ENV_ALPHA, TEXEL0, TEXEL1, TEXEL0, ENVIRONMENT, TEXEL0, 0, 0,
                      0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg2);

    gDPPipeSync(gDisplayListHead++);

    for (i = 0; i < 0x1E0; i += 0x20) {
        for (j = 0; j < 0x280; j += 0x20) {
            gDPLoadTextureBlock(gDisplayListHead++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gDPLoadMultiBlock(gDisplayListHead++, arg1, 0x0100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                              G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                              G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, j << 2, i << 2, (j + 0x20) << 2, (i + 0x20) << 2, G_TX_RENDERTILE,
                                0, 0, 0x0200, 0x0200);
            arg0 += 0x200;
            arg1 += 0x200;
        }
    }
}

void func_84A003BC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8* arg5, f32 arg6) {
    UNUSED s32 pad;

    gDPLoadTextureBlock(gDisplayListHead++, arg5, G_IM_FMT_RGBA, G_IM_SIZ_16b, (s32)(arg4 / arg6), (s32)(arg3 / arg6),
                        0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 1024.0f / arg6, 1024.0f / arg6, 0);
}

void func_84A00630(void) {
}

void func_84A00638(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, f32 arg5) {
    UNUSED s32 pad;

    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_IA, G_IM_SIZ_8b, (s32)(arg2 / arg5), (s32)(arg3 / arg5), 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, 1024.0f / arg5, 1024.0f / arg5, 0);
}

void func_84A008A8(void) {
    char sp40[0x100];
    UNUSED s32 pad2;
    s16 sp3A;
    UNUSED s32 pad;
    s16 temp_v0;

    if (D_84A030EC >= 0x10) {
        sp3A = 0xF0 - (D_84A030EC / 2);
        func_80020754(0x78, sp3A, 0x190, D_84A030EC);
        func_8001F504(0x7F, sp3A + 7, 0x182, D_84A030EC - 0xE, 0x14, 0x32, 0x64, 0x96);

        if (D_84A030EC == 0x50) {
            func_8001F3F4();
            func_8001EBE0(8, 0);
            func_8001F3B4(0x18);

            if (D_84A030E0 == 7) {
                func_8001F1E8(0x88, sp3A + 0x10, func_8002D7C0(NULL, 0, D_84A03130, 0xC));
            } else if (D_84A030E0 == 0xA) {
                func_8001F1E8(0x88, sp3A + 0x10, func_8002D7C0(NULL, 0, D_84A03130, 0xD));
            } else {
                temp_v0 = D_84A02F00[D_84A030E0].unk_22;
                if (temp_v0 >= 0x1E) {
                    func_8002D5D4(0x24, func_8002D7C0(NULL, 0, D_84A03134, temp_v0));
                } else if (temp_v0 >= 0) {
                    func_8002D5D4(0x24, func_8002D7C0(NULL, 0, D_84A03130, temp_v0));
                } else {
                    func_8002D5D4(0x24, " ");
                }

                temp_v0 = D_84A02F00[D_84A030E0 + 1].unk_22;
                if (temp_v0 >= 0x1E) {
                    func_8002D5D4(0x29, func_8002D7C0(NULL, 0, D_84A03134, temp_v0));
                } else if (temp_v0 >= 0) {
                    func_8002D5D4(0x29, func_8002D7C0(NULL, 0, D_84A03130, temp_v0));
                } else {
                    func_8002D5D4(0x29, " ");
                }
                func_8001F1E8(0x88, sp3A + 0x10, func_8002D7C0(sp40, sizeof(sp40), D_84A03130, 0xE));
            }
            func_8001F444();
        }
    }
}

void func_84A00B44(void) {
    UNUSED s32 pad[3];
    s32 i;
    char* var_s0;
    unk_D_84A02F00* sp58 = &D_84A02F00[D_84A030E0];

    for (i = 0; i < 4; i++) {
        if (D_84A03138[i].unk_00 != 0) {
            s16 tmp = D_84A03138[i].unk_02;

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            func_84A003BC(tmp, 0xF0, 0x80, 0x40, 0x80, D_3009290, 2.0f);
            func_84A003BC(tmp, 0x130, 0x80, 0x40, 0x80, D_300A290, 2.0f);
            func_84A003BC(tmp, 0x170, 0x80, 0x40, 0x80, D_300B290, 2.0f);
            func_84A003BC(tmp + 8, 0x138, 0x70, 0x38, 0x80, D_84A03138[i].unk_04 + 0x208, 2.0f);
            func_84A003BC(tmp + 8, 0x170, 0x70, 0x38, 0x80, D_84A03138[i].unk_04 + 0x1008, 2.0f);

            gSPDisplayList(gDisplayListHead++, D_8006F630);

            func_8001F3F4();

            if ((D_84A030E0 >= 8) || (i == 3)) {
                func_8001EBE0(8, 0);

                if (sp58->unk_20 >= 0) {
                    var_s0 = func_8002D7C0(NULL, 0, D_84A03130, sp58->unk_20);
                } else {
                    var_s0 = " ";
                }

                func_8001F1E8((tmp - (func_8001F5B0(8, 0, var_s0) / 2)) + 0x40, 0xF4, var_s0);
            }

            func_8001EBE0(4, 0);

            if ((i == 3) && (D_84A030E0 < 8)) {
                func_8001F1E8(tmp + 8, 0x10C, func_8002D7C0(NULL, 0, D_84A03130, 8));
            } else {
                func_8001F1E8(tmp + 8, 0x10C, func_8002D7C0(NULL, 0, D_84A03130, 0xF));
            }

            func_8001EBE0(0x10, 0);
            func_8001F1E8((tmp - (func_8001F5B0(0x10, 0, D_84A03138[i].unk_08) / 2)) + 0x40, 0x11C,
                          D_84A03138[i].unk_08);
            func_8001F444();
        }
    }
}

void func_84A00E98(void) {
    static s16 D_84A030F4 = 0;
    static s16 D_84A030F8 = 1;

    s16 i;
    s16 var_s1 = (D_84A030F4 / 4) + 0x22;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 9; i++) {
        func_8001C6AC(0x24, var_s1, 0xE4, 8, D_3011A30 + i * 0xE40, 0xE4, 0);
        var_s1 += 8;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_84A030F4 += D_84A030F8;
    if (D_84A030F4 == 0) {
        D_84A030F8 = 1;
    }

    if (D_84A030F4 == 0x23) {
        D_84A030F8 = -1;
    }
}

void func_84A00FEC(void) {
    s32 i;
    s32 var_a0;
    s32 var_s2;
    unk_D_84A02F00* var_s0;

    if (D_84A030E0 < 9) {
        var_s0 = &D_84A02F00[0];
        var_s2 = 9;
    } else {
        var_s0 = &D_84A02F00[9];
        var_s2 = 3;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0,
                      PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    for (; var_s2 > 0; var_s2--, var_s0++) {
        if (var_s0->unk_01 != 0) {
            var_a0 = 0xFF;
            if (var_s0->unk_01 == 1) {
                var_a0 = (s32)((COSS(var_s0->unk_12) + 1.0f) * 96.0f);
                var_a0 += 0x3F;
                var_s0->unk_12 += 0x200;
            } else {
                var_s0->unk_12 = 0;
                var_s0->unk_01--;
            }

            gDPSetEnvColor(gDisplayListHead++, var_s0->unk_18.r, var_s0->unk_18.g, var_s0->unk_18.b, var_a0);

            if (var_s0->unk_00 == 9) {
                gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 0, 255);
            } else {
                gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
            }

            func_84A00638(var_s0->unk_0A, var_s0->unk_0C, var_s0->unk_0E * 2, var_s0->unk_10 * 2, var_s0->unk_1C, 2.0f);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84A012B8(void) {
    s32 var_s2;
    char* var_s0;
    unk_D_84A02F00* var_s1;
    s16 tmp;

    if (D_84A030E0 < 9) {
        var_s1 = &D_84A02F00[0];
        var_s2 = 8;
    } else {
        var_s1 = &D_84A02F00[9];
        var_s2 = 3;
    }

    func_8001F3F4();
    func_8001F470();
    func_8001EBE0(4, 0);
    func_8001F36C(0x50, 0x64, 0xDC, 0xFF);

    for (; var_s2 > 0; var_s2--, var_s1++) {
        if (var_s1->unk_01 != 0) {
            if (var_s1->unk_22 >= 0x1E) {
                var_s0 = func_8002D7C0(NULL, 0, D_84A03134, var_s1->unk_22);
            } else if (var_s1->unk_22 >= 0) {
                var_s0 = func_8002D7C0(NULL, 0, D_84A03130, var_s1->unk_22);
            } else {
                var_s0 = " ";
            }
            tmp = var_s1->unk_02 - (func_8001F5B0(4, 0, var_s0) / 2);
            func_8001F1E8(tmp, var_s1->unk_04, var_s0);
        }
    }

    func_8001F4C4();
    func_8001F444();
}

void func_84A01424(unk_D_84A02F00* arg0, u8 arg1, u8 arg2) {
    char* sp54;

    if (arg0->unk_24 != NULL) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg1);

        func_84A003BC(0x1F6, 0x160, 0x60, 0x30, 0x60, arg0->unk_24, 1.5f);
        func_84A003BC(0x1F6, 0x190, 0x60, 0x30, 0x60, arg0->unk_24 + 0x1000, 1.5f);

        gSPDisplayList(gDisplayListHead++, D_8006F558);
        gDPSetEnvColor(gDisplayListHead++, arg0->unk_18.r, arg0->unk_18.g, arg0->unk_18.b, (arg2 * 0x96) / 255);

        func_8001CCF8(0x166, 0x174, 0x10, 0x4C, D_300C290, 0x10, 0);
        func_8001C330(0x176, 0x174, 0x80, 0x4C, 0x1E0, 0, 0, 0x400, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        func_8001F3F4();
        func_8001F470();
        func_8001F324(0x8C, 0x90, 0x90, arg2);
        func_8001F36C(0xFF, 0xFF, 0xFF, arg2);
        func_8001EBE0(8, 0);

        if (arg0->unk_20 >= 0) {
            sp54 = func_8002D7C0(NULL, 0, D_84A03130, arg0->unk_20);
        } else {
            sp54 = " ";
        }
        func_8001F1E8(0x1AE - (func_8001F5B0(8, 0, sp54) / 2), 0x17A, sp54);
        func_8001EBE0(0x20, 0);

        if (arg0->unk_22 >= 0x1E) {
            sp54 = func_8002D7C0(NULL, 0, D_84A03134, arg0->unk_22);
        } else if (arg0->unk_22 >= 0) {
            sp54 = func_8002D7C0(NULL, 0, D_84A03130, arg0->unk_22);
        } else {
            sp54 = " ";
        }

        func_8001F1E8(0x1AE - (func_8001F5B0(0x20, 0, sp54) / 2), 0x196, sp54);
        func_8001F4C4();
        func_8001F444();
    }
}

void func_84A01770(unk_D_84A02F00* arg0, u8 arg1, u8 arg2) {
    char* var_s0;

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg1);

    func_84A003BC(0x1D6, 0x13E, 0x80, 0x1A, 0x80, arg0->unk_24, 1.28f);
    func_84A003BC(0x1D6, 0x158, 0x80, 0x1A, 0x80, arg0->unk_24 + 0xFA0, 1.28f);
    func_84A003BC(0x1D6, 0x172, 0x80, 0x1A, 0x80, arg0->unk_24 + 0x1F40, 1.28f);
    func_84A003BC(0x1D6, 0x18C, 0x80, 0x1A, 0x80, arg0->unk_24 + 0x2EE0, 1.28f);
    func_84A003BC(0x1D6, 0x1A6, 0x80, 0x1A, 0x80, arg0->unk_24 + 0x3E80, 1.28f);

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, arg0->unk_18.r, arg0->unk_18.g, arg0->unk_18.b, (arg2 * 0x96) / 255);
    gDPLoadTextureBlock(gDisplayListHead++, D_300C290, G_IM_FMT_IA, G_IM_SIZ_16b, 16, 76, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(0x15A, 0x174, 0x10, 0x4C, 0, 0, 0x400, 0x400, 0);
    func_8001C330(0x16A, 0x174, 0x6C, 0x4C, 0x1E0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001F470();
    func_8001F324(0x8C, 0x90, 0x90, arg2);
    func_8001F36C(0xFF, 0xFF, 0xFF, arg2);
    func_8001EBE0(0x10, 0);

    if (arg0->unk_22 >= 0x1E) {
        var_s0 = func_8002D7C0(NULL, 0, D_84A03134, arg0->unk_22);
    } else if (arg0->unk_22 >= 0) {
        var_s0 = func_8002D7C0(NULL, 0, D_84A03130, arg0->unk_22);
    } else {
        var_s0 = " ";
    }

    func_8001F1E8(0x198 - (func_8001F5B0(0x10, 0, var_s0) / 2), 0x196, var_s0);
    func_8001F4C4();
    func_8001F444();
}

void func_84A01BAC(void) {
    u8 sp1F;

    if (D_84A030E8 > 0) {
        if (D_84A030E8 < 0xFF) {
            if (D_84A030E0 == 0xA) {
                func_84A01770(&D_84A02F00[D_84A030E0], D_84A030E8, D_84A030E8);
            } else {
                func_84A01424(&D_84A02F00[D_84A030E0], D_84A030E8, D_84A030E8);
            }
        } else if (D_84A030E4 == 0) {
            if (D_84A030E0 == 0xA) {
                func_84A01770(&D_84A02F00[D_84A030E0], 0xFF, 0xFF);
            } else {
                func_84A01424(&D_84A02F00[D_84A030E0], 0xFF, 0xFF);
            }
        } else {
            sp1F = ((D_84A030E4 * 0xFF) / 4) & 0xFF;
            if (D_84A030E0 == 0xA) {
                func_84A01770(&D_84A02F00[D_84A030E0], 0xFF, 0xFF - sp1F);
            } else {
                func_84A01424(&D_84A02F00[D_84A030E0], 0xFF, 0xFF - sp1F);
            }

            if (D_84A03188 == 0xA) {
                func_84A01770(&D_84A02F00[D_84A03188], sp1F, sp1F);
            } else {
                func_84A01424(&D_84A02F00[D_84A03188], sp1F, sp1F);
            }
        }
    }
}

void func_84A01DAC(void) {
    s16 sp1E;
    s16 sp1C;
    unk_D_84A02F00* temp_a1 = &D_84A02F00[D_84A030E0];

    if (D_84A030E4 == 0) {
        sp1E = temp_a1->unk_06 - 0x20;
        sp1C = temp_a1->unk_08 - 0xD;
    } else {
        sp1E = ((((D_84A02F00[D_84A03188].unk_06 - temp_a1->unk_06) * D_84A030E4) / 4) + temp_a1->unk_06) - 0x20;
        sp1C = ((((D_84A02F00[D_84A03188].unk_08 - temp_a1->unk_08) * D_84A030E4) / 4) + temp_a1->unk_08) - 0xD;

        D_84A030E4--;
        if ((D_84A030E4 == 0) && ((D_84A030E0 == 8) || (D_84A030E0 == 9))) {
            func_80007990(1);
            func_80006CB4(8);
        }
    }

    func_80020928(sp1E - 3, sp1C);
}

void func_84A01EE0(void) {
    func_800079C4();

    if (D_84A030E0 < 9) {
        if (D_84A030F0 == 0) {
            func_8001D924(D_84A03174);
        } else if (D_84A030F0 == 0xFF) {
            func_8001D924(D_84A03178);
        } else {
            func_84A00020(D_84A03174, D_84A03178, D_84A030F0);
            if (D_84A030F0 < 0xFF) {
                D_84A030F0 += 5;
            }
        }
    } else {
        func_8001D924(D_84A0317C);
        D_84A030F0 = 0xFF;
    }

    if (D_800AE540.unk_11F2 == 1) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_8001C6AC(0x22C, 0x28, 0x24, 0x24, D_3019C38, 0x24, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }

    func_84A00FEC();
    func_84A012B8();
    func_84A01BAC();
    func_84A01DAC();
    func_84A00B44();
    func_84A00E98();
    func_84A008A8();
    func_80007778();
}

s32 func_84A02074(void) {
    return 0;
}

s32 func_84A0207C(void) {
    s16 var_s4;
    s16 var_s1;
    s16 var_s3;
    unk_D_84A02F00* temp_s0;

    var_s4 = 0x1E;
    var_s3 = 2;

    while (var_s3 == 2) {
        var_s1 = -1;
        temp_s0 = &D_84A02F00[D_84A030E0];

        func_800290B4();

        if (func_84A02074() == 0) {
            if (func_80007604() == 0) {
                if (D_84A030E4 == 0) {
                    D_84A03188 = D_84A030E0;
                    if (D_84A030E0 == 0xB) {
                        var_s4--;
                        if (var_s4 == 0) {
                            var_s3 = 3;
                        }
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
                        func_80048B90(2);
                        var_s3 = 3;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
                        func_80048B90(3);
                        if (temp_s0->unk_00 >= 0xA) {
                            D_84A030E0 = 9;
                            D_84A030E4 = 3;
                        } else {
                            var_s3 = 1;
                        }
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP) && (temp_s0->unk_14 != 0)) {
                        var_s1 = temp_s0->unk_14 - 1;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN) && (temp_s0->unk_15 != 0)) {
                        var_s1 = temp_s0->unk_15 - 1;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT) && (temp_s0->unk_16 != 0)) {
                        var_s1 = temp_s0->unk_16 - 1;
                    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT) && (temp_s0->unk_17 != 0)) {
                        var_s1 = temp_s0->unk_17 - 1;
                    }

                    if ((var_s1 >= 0) && (D_84A02F00[var_s1].unk_01 != 0)) {
                        func_80048B90(1);
                        D_84A030E0 = var_s1;
                        D_84A030E4 = 3;
                    }
                }
            } else if (func_80007604() == 1) {
                if (D_84A030E0 == 8) {
                    D_84A030E0 = 0xA;
                }

                if (D_84A030E0 == 9) {
                    D_84A030E0 = 7;
                }
                func_80006C6C(8);
            }
        }
        func_84A01EE0();
    }
    return var_s3;
}

void func_84A02304(void) {
    s32 i;
    s32 var_a1;
    s32 var_s7;
    TrainerData* var_s1;
    s32 portrait_file_idx;

    if (D_84A030E0 == 0xB) {
        var_s7 = 1;
    } else {
        var_s7 = 4;
    }

    if (D_84A030E0 < 8) {
        var_a1 = D_84A030E0 + 0xC;
    } else {
        var_a1 = D_84A030E0 + 0xA;
    }

    if (D_800AE540.unk_11F2 != 0) {
        var_a1 += 0x1F;
    }

    var_s1 = func_8000484C(D_84A03168, var_a1);

    for (i = 0; i < var_s7; i++) {
        portrait_file_idx = (var_s1[i].gfx_file_idx >> 8) & 0xFF;
        D_84A03138[i].unk_00 = 1;
        D_84A03138[i].unk_02 = 0x280;
        D_84A03138[i].unk_08 = var_s1[i].name1;
        D_84A03138[i].unk_04 = func_8000484C(D_84A0316C, portrait_file_idx);
    }
}

void func_84A02410(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_84A03138[i].unk_00 = 0;
    }
}

void func_84A02434(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 i;

    while (arg2-- > 0) {
        for (i = arg0; i <= arg1; i++) {
            D_84A03138[i].unk_02 += arg3;
        }
        func_800290B4();
        func_84A01EE0();
    }
}

s32 func_84A02580(void) {
    s16 i;
    s32 var_s1;
    s32 var_s1_2 = 0;

    main_pool_push_state('itro');

    func_84A02304();
    func_8000D278(8);

    for (i = 3; i >= 0; i--) {
        D_84A030E8 = i << 6;
        func_800290B4();
        func_84A01EE0();
    }

    func_8000D1F0(0x2B);
    if (D_84A030E0 == 0xB) {
        func_84A02434(0, 0, 6, -0x40);
    } else {
        func_84A02434(0, 3, 3, -0x40);
        func_84A02434(0, 2, 2, -0x40);
        func_84A02434(0, 1, 2, -0x40);
        func_84A02434(0, 0, 2, -0x40);
    }

    while (var_s1_2 == 0) {
        func_800290B4();
        func_84A01EE0();
        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            var_s1_2 = 1;
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            if (D_84A030E0 == 0xB) {
                var_s1_2 = 1;
            } else {
                var_s1_2 = 2;
            }
        }
    }

    if (var_s1_2 == 1) {
        func_80048B90(0x1C);
        var_s1 = 0;
        if (D_84A030E0 == 0xB) {
            func_84A02434(0, 0, 6, -0x40);
        } else {
            func_84A02434(3, 3, 2, -0x40);
            func_84A02434(2, 3, 2, -0x40);
            func_84A02434(1, 3, 2, -0x40);
            func_84A02434(0, 3, 3, -0x40);
        }
        func_84A02410();
        func_84A01EE0();
    } else {
        func_80048B90(3);
        var_s1 = 2;
        func_8000D278(0x12);
        if (D_84A030E0 == 0xB) {
            func_84A02434(0, 0, 6, 0x40);
        } else {
            func_84A02434(0, 0, 2, 0x40);
            func_84A02434(0, 1, 2, 0x40);
            func_84A02434(0, 2, 2, 0x40);
            func_84A02434(0, 3, 3, 0x40);
        }
        func_84A02410();

        if (D_84A03180.unk_04 < 8) {
            func_8000D1F0(0x2A);
        } else {
            func_8000D1F0(0x27);
        }

        for (i = 1; i < 5; i++) {
            D_84A030E8 = (i << 6) - 1;
            func_800290B4();
            func_84A01EE0();
        }
    }

    main_pool_pop_state('itro');

    return var_s1;
}

s32 func_84A02898(void) {
    s16 i;

    if (D_800AE540.unk_0002 == 7) {
        func_8004DF94(0x01100015, 0, 0);
        D_84A030F0 = 5;
    }

    for (i = 1; i < 5; i++) {
        D_84A030EC = i * 0x14;
        func_800290B4();
        func_84A01EE0();
    }

    do {
        func_800290B4();
        func_84A01EE0();
    } while (!BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B));

    func_80048B90(0x01100011);

    if (D_800AE540.unk_0002 == 8) {
        D_84A02F00[11].unk_01 = 0x3C;
    } else {
        D_84A02F00[D_84A03180.unk_04].unk_01 = 0x3C;
    }

    if (D_84A03180.unk_04 == 8) {
        D_84A02F00[9].unk_01 = 0x3C;
        D_84A02F00[10].unk_01 = 0x3C;
    }

    for (i = 3; i >= 0; i--) {
        D_84A030EC = i * 0x14;
        func_800290B4();
        func_84A01EE0();
    }

    D_84A03188 = D_84A030E0;
    D_84A030E0 += 1;
    D_84A030E4 = 3;
    return 2;
}

s16 func_84A02A34(s16 arg0) {
    s16 i;

    if (func_80007604() == 1) {
        func_80006C6C(8);
        for (i = 0; i < 9; i++) {
            func_800290B4();
            func_84A01EE0();
        }
    }

    while ((arg0 != 0) && (arg0 != 1)) {
        switch (arg0) {
            case 2:
                arg0 = func_84A0207C();
                break;

            case 3:
                arg0 = func_84A02580();
                break;

            case 4:
                arg0 = func_84A02898();
                break;
        }
    }

    D_800AE540.unk_0003 = 1;
    if (D_84A030E0 < 8) {
        D_800AE540.unk_0002 = D_84A030E0;
    } else {
        D_800AE540.unk_0002 = D_84A030E0 - 2;
    }
    return arg0;
}

s16 func_84A02B70(s16 arg0) {
    s16 i;
    s16 sp2C = 2;
    s16 var_v1 = D_84A03180.unk_04;

    if (D_800AE540.unk_0002 < 8) {
        D_84A030E0 = D_800AE540.unk_0002;
    } else {
        D_84A030E0 = D_800AE540.unk_0002 + 2;
    }

    if (arg0 == 1) {
        sp2C = 4;
        if (D_800AE540.unk_0002 < 8) {
            var_v1--;
        }
    }

    if (var_v1 >= 8) {
        D_84A030F0 = 0xFF;
    } else {
        D_84A030F0 = 0;
    }

    for (i = 0; i <= var_v1; i++) {
        D_84A02F00[i].unk_01 = 1;
    }

    if (D_84A02F00[8].unk_01 != 0) {
        D_84A02F00[9].unk_01 = 1;
        D_84A02F00[10].unk_01 = 1;
    }

    for (i = 0; i < 4; i++) {
        D_84A03138[i].unk_00 = 0;
    }

    for (i = 0; i < 8; i++) {
        D_84A02F00[i].unk_24 = func_8000484C(D_84A0316C, i + 2);
    }

    D_84A02F00[10].unk_24 = D_300CC10;
    D_84A02F00[11].unk_24 = func_8000484C(D_84A0316C, 0xE);
    return sp2C;
}

s32 func_84A02D14(s32 arg0, UNUSED s32 arg1) {
    s16 sp1E;

    main_pool_push_state('PNLV');

    func_8001E94C(0x3C, 0);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, gym_leader_castle_ui, 0);
    func_8002D510();
    D_84A03130 = func_8002D5AC(0x19);
    D_84A03134 = func_8002D5AC(0x22);
    func_80028AFC(2);
    func_80027FA0(&D_84A03180, D_800AE540.unk_11F2);
    D_84A03168 = func_800044F4(0x898000, NULL, 1, 1);
    D_84A0316C = ASSET_LOAD2(battle_portraits, 1, 1);
    D_84A03170 = ASSET_LOAD2(backgrounds, 1, 1);
    D_84A03174 = func_8000484C(D_84A03170, 0xD);
    D_84A03178 = func_8000484C(D_84A03170, 0x10);
    D_84A0317C = func_8000484C(D_84A03170, 0xE);
    func_80007754();

    sp1E = func_84A02B70(arg0);
    if (D_84A03180.unk_04 < 8) {
        func_8000D1F0(0x2A);
    } else {
        func_8000D1F0(0x27);
    }

    sp1E = func_84A02A34(sp1E);
    func_8000771C();
    func_8001E9CC();

    main_pool_pop_state('PNLV');
    return sp1E == 0;
}
