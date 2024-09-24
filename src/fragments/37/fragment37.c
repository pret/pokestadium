#include "fragment37.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/29BA0.h"
#include "src/26820.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/4F410.h"
#include "src/6A40.h"
#include "src/DDC0.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/math_util.h"

typedef struct unk_D_82202FE4 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s8 unk_06;
    /* 0x07 */ s8 unk_07;
    /* 0x08 */ s8 unk_08;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ Color_RGBA8 unk_0A;
} unk_D_82202FE4; // size = 0xE

typedef struct unk_D_82203160_006 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
} unk_D_82203160_006; // size = 0x6

typedef struct unk_D_82203160 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ unk_D_82203160_006 unk_0C[4];
} unk_D_82203160; // size = 0x24

typedef struct unk_D_82203150 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ Color_RGBA8 unk_08;
} unk_D_82203150; // size >= 0xC

static s16 D_82202FA0 = 0;

static s16 D_82202FA4 = 0;

static s16 D_82202FA8[] = {
    STATE_STADIUM_MENU,   STATE_FREE_BATTLE, STATE_GYM_LEADER_CASTLE, STATE_VS_MEWTWO,   STATE_KIDS_CLUB,
    STATE_VICTORY_PALACE, STATE_POKEMON_LAB, STATE_GB_TOWER,          STATE_MENU_SELECT,
};

static u8* D_82202FBC[] = {
    0x03006E60, 0x0300D060, 0x03013260, 0x03019460, 0x0301F660,
    0x03025860, 0x0302BA60, 0x03031C60, 0x03037E60, 0x0303E060,
};

static unk_D_82202FE4 D_82202FE4[9] = {
    { 0x012C, 0x00B9, 0x004B, 0x03, 0x04, 0x06, 0x07, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x0208, 0x0118, 0x004B, 0x07, 0x08, 0x04, 0x08, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x006E, 0x005A, 0x0041, 0x08, 0x06, 0x08, 0x03, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x012C, 0x0041, 0x0041, 0x08, 0x00, 0x02, 0x07, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x015E, 0x013B, 0x0050, 0x00, 0x08, 0x05, 0x01, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x00BE, 0x014A, 0x0046, 0x06, 0x08, 0x08, 0x04, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x0078, 0x00E6, 0x0041, 0x02, 0x05, 0x08, 0x00, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x01FE, 0x0096, 0x0041, 0x03, 0x01, 0x00, 0x08, { 0x32, 0x50, 0x96, 0x00 } },
    { 0x012C, 0x00B9, 0x000A, 0x08, 0x08, 0x08, 0x08, { 0x32, 0x50, 0x96, 0x00 } },
};

static u8* D_82203064[] = { 0x03005000, 0x03005A20, 0x03006440, 0x03005A20 };

static s32 D_822030F0;
static BinArchive* D_822030F4;
static Vp D_822030F8;
static Mtx D_82203108;
static u8* D_82203148;
static u8* D_8220314C;
static unk_D_82203150 D_82203150;
static unk_D_82203160 D_82203160[3];
static s32 pad_D_822031D0[0x2];
static s16 D_822031D8;
static s16 D_822031DA;
static s16 D_822031DC;
static unk_func_80027FA0 D_822031E0;
static unk_func_8002A728 D_822031E8;

s32 func_82200020(s32 arg0) {
    u32 temp_a0 = osSetIntMask(1);

    if (!(HW_REG(PI_STATUS_REG, u32) & 3) && ((*(u32*)0xB0000D10 & 0xFFFF) != 0x400)) {
        arg0 = -0x40;
    }

    osSetIntMask(temp_a0);
    return arg0;
}

void func_82200088(u8* arg0, u8* arg1, u8 arg2) {
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

Vtx* func_82200424(void) {
    Vtx* temp_v0;
    s16 temp_s0;
    s16 temp_s6;
    s16 temp_s7;
    u8 temp_s2;
    u8 temp_s3;
    u8 temp_s4;
    u8 temp_s5;

    temp_s6 = D_82203150.unk_00;
    temp_s7 = D_82203150.unk_02;
    temp_s0 = D_82203150.unk_04;
    temp_s2 = D_82203150.unk_08.r;
    temp_s3 = D_82203150.unk_08.g;
    temp_s4 = D_82203150.unk_08.b;
    temp_s5 = D_82203150.unk_08.a;

    temp_v0 = func_80005F5C(sizeof(Vtx) * 8);

    if (temp_v0 != NULL) {
        func_8001E680(&temp_v0[0], temp_s6 - temp_s0, temp_s7 - temp_s0, -1, 0, 0, temp_s2, temp_s3, temp_s4, temp_s5);
        func_8001E680(&temp_v0[1], temp_s6 - temp_s0, temp_s7 + temp_s0, -1, 0, 0x7E0, temp_s2, temp_s3, temp_s4,
                      temp_s5);
        func_8001E680(&temp_v0[2], temp_s6 + temp_s0, temp_s7 + temp_s0, -1, 0x7E0, 0x7E0, temp_s2, temp_s3, temp_s4,
                      temp_s5);
        func_8001E680(&temp_v0[3], temp_s6 + temp_s0, temp_s7 - temp_s0, -1, 0x7E0, 0, temp_s2, temp_s3, temp_s4,
                      temp_s5);

        func_8001E680(&temp_v0[4], temp_s6 - 0x7D0, temp_s7 - 0x7D0, -1, 0, 0, temp_s2, temp_s3, temp_s4, temp_s5);
        func_8001E680(&temp_v0[5], temp_s6 - 0x7D0, temp_s7 + 0x7D0, -1, 0, 0, temp_s2, temp_s3, temp_s4, temp_s5);
        func_8001E680(&temp_v0[6], temp_s6 + 0x7D0, temp_s7 + 0x7D0, -1, 0, 0, temp_s2, temp_s3, temp_s4, temp_s5);
        func_8001E680(&temp_v0[7], temp_s6 + 0x7D0, temp_s7 - 0x7D0, -1, 0, 0, temp_s2, temp_s3, temp_s4, temp_s5);
    }

    return temp_v0;
}

void func_82200690(void) {
    Vtx* temp_v0;

    if (D_82203150.unk_08.a <= 0) {
        return;
    }

    temp_v0 = func_82200424();

    if (temp_v0 != 0) {
        gDPPipeSync(gDisplayListHead++);

        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, D_82203150.unk_06);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, SHADE, ENV_ALPHA, SHADE, 0, 0, 0, SHADE, ENVIRONMENT, SHADE,
                          ENV_ALPHA, SHADE, 0, 0, 0, SHADE);

        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 8, 0);
        gSP2Triangles(gDisplayListHead++, 0, 4, 1, 0, 1, 4, 5, 0);
        gSP2Triangles(gDisplayListHead++, 1, 5, 2, 0, 2, 5, 6, 0);
        gSP2Triangles(gDisplayListHead++, 2, 6, 7, 0, 2, 7, 3, 0);
        gSP2Triangles(gDisplayListHead++, 3, 4, 0, 0, 3, 7, 4, 0);

        gDPPipeSync(gDisplayListHead++);

        gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
        gDPSetRenderMode(gDisplayListHead++, G_RM_PASS, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, SHADE, ENV_ALPHA, SHADE, 1, TEXEL0, ENVIRONMENT, TEXEL0, 0,
                          0, 0, COMBINED, COMBINED, 0, SHADE, 0);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);

        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

        gDPLoadTextureBlock(gDisplayListHead++, D_3000000, G_IM_FMT_I, G_IM_SIZ_8b, 64, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                            G_TX_MIRROR | G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    }
}

void func_82200A5C(void) {
    s32 i;
    s32 j;
    s16 temp_fv0;
    s16 var_v0 = D_82203160[0].unk_08;

    for (i = 0; i < 3; i++) {
        for (j = 4; j >= 0; j--) {
            D_82203160[i].unk_0C[j + 1] = D_82203160[i].unk_0C[j];
        }

        temp_fv0 = (D_82203160[0].unk_06 * D_82203160[0].unk_04) / 100;

        D_82203160[i].unk_0C[0].unk_00 = D_82203160[0].unk_00 + (COSS((var_v0)) * temp_fv0);
        D_82203160[i].unk_0C[0].unk_02 = D_82203160[0].unk_02 + (SINS((var_v0)) * temp_fv0);
        D_82203160[i].unk_0C[0].unk_04 = (D_82203160[0].unk_06 * 0x48) / 100;

        var_v0 -= 0x5555;
    }
}

void func_82200BF4(s32 arg0) {
    s32 i;

    D_82203160[0].unk_00 = D_82202FE4[arg0].unk_00;
    D_82203160[0].unk_02 = D_82202FE4[arg0].unk_02;
    D_82203160[0].unk_04 = D_82202FE4[arg0].unk_04;
    D_82203160[0].unk_06 = 0x64;
    D_82203160[0].unk_0A = 0;
    D_82203160[0].unk_08 = 0;

    for (i = 0; i < 6; i++) {
        func_82200A5C();
        D_82203160[0].unk_08 -= 0x800;
    }
}

Vtx* func_82200C8C(s16 arg0, s16 arg1, s16 arg2, Color_RGBA8 arg3) {
    s16 sp44;
    Vtx* temp_v0;

    temp_v0 = func_80005F5C(sizeof(Vtx) * 8);
    if (temp_v0 != NULL) {
        sp44 = arg2 / 2;

        func_8001E680(&temp_v0[0], arg0 - sp44, arg1 - sp44, -1, 0, 0, arg3.r, arg3.g, arg3.b, arg3.a);
        func_8001E680(&temp_v0[1], arg0 - sp44, arg1 + sp44, -1, 0, 0x480, arg3.r, arg3.g, arg3.b, arg3.a);
        func_8001E680(&temp_v0[2], arg0 + sp44, arg1 + sp44, -1, 0x480, 0x480, arg3.r, arg3.g, arg3.b, arg3.a);
        func_8001E680(&temp_v0[3], arg0 + sp44, arg1 - sp44, -1, 0x480, 0, arg3.r, arg3.g, arg3.b, arg3.a);
    }

    return temp_v0;
}

void func_82200E34(s16 arg0, s16 arg1, s16 arg2, u8* arg3, Color_RGBA8 arg4) {
    Vtx* temp_v0 = func_82200C8C(arg0, arg1, arg2, arg4);

    if (temp_v0 != NULL) {
        gDPLoadTextureBlock(gDisplayListHead++, arg3, G_IM_FMT_RGBA, G_IM_SIZ_16b, 36, 36, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
    }
}

void func_82200FB0(u8* arg0) {
    Color_RGBA8 sp5C;
    s16 i;
    s16 j;
    s16 temp_s1;
    s16 temp_s3;
    s16 temp_s4;

    for (i = 5; i >= 0; i--) {
        for (j = 0; j < 3; j++) {
            temp_s1 = D_82203160[j].unk_0C[i].unk_04;
            temp_s3 = D_82203160[j].unk_0C[i].unk_00;
            temp_s4 = D_82203160[j].unk_0C[i].unk_02;

            if (temp_s1 != 0) {
                if (i == 0) {
                    func_8000E840(&sp5C, 0xFF, 0xFF, 0xFF, 0xFF);
                } else {
                    func_8000E840(&sp5C, 0xFF, 0xFF, 0x64, 0xA0 - (i * 30));
                }
                func_82200E34(temp_s3, temp_s4, temp_s1, arg0, sp5C);
            }
        }
    }
}

void func_82201108(void) {
    if (D_822031D8 != 8) {
        func_82200A5C();

        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

        func_82200FB0(D_82203064[D_82203160->unk_0A / 2]);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);

        D_82203160->unk_08 -= 0x800;
        D_82203160->unk_0A = (D_82203160->unk_0A + 2) % 8;
    }
}

void func_822012E8(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 i;
    u8* var_s2;

    if (arg3 != 8) {
        if (arg3 == 7) {
            arg3 += D_822031E8.unk_00;
        }
        var_s2 = D_82202FBC[arg3];

        gSPDisplayList(gDisplayListHead++, D_8006F518);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg2);

        for (i = 0; i < 16; i++) {
            func_8001C6AC(arg0, arg1 + (i * 4), 0xC4, 4, var_s2 + (i * 0x620), 0xC4, 0);
        }

        if ((D_800AE540.unk_11F2 != 0) && ((arg3 == 0) || (arg3 == 2) || (arg3 == 3))) {
            func_8001C6AC(arg0 - 0x20, arg1 + 0xD, 0x24, 0x24, D_20144E0, 0x24, 0);
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }
}

void func_822014C0(void) {
}

void func_822014C8(s16 arg0, s16 arg1, s16 arg2) {
    static s16 D_82203074 = 1;
    static s16 D_82203078 = 1;

    s16 sp1E;

    if (arg0 == 2) {
        sp1E = (D_822031DC * 0x2A) + 3;
        func_822012E8(arg1, (arg2 + (D_82203074 / 4)) - 5, 0xFF - sp1E, D_822031DA);
        func_822012E8(arg1, (arg2 + (D_82203074 / 4)) - 5, sp1E, D_822031D8);
    } else if ((arg0 != 8) && (arg0 != 0)) {
        func_822012E8(arg1, (arg2 + (D_82203074 / 4)) - 5, 0xFF, D_822031D8);
    }

    D_82203074 += D_82203078;
    if (D_82203074 == 0) {
        D_82203078 = 1;
    }

    if (D_82203074 == 0x2B) {
        D_82203078 = -1;
    }
}

void func_82201654(s16 arg0, s16 arg1) {
    static u32 D_8220307C[] = {
        0x03044C60, 0x03045020, 0x030453E0, 0x030457A0, 0x03045B60, 0x03045F20, 0x030462E0,
        0x030466A0, 0x03046A60, 0x03046E20, 0x030471E0, 0x030475A0, 0x03047960, 0x03047D20,
        0x030480E0, 0x030484A0, 0x03048860, 0x030493A0, 0x03048FE0, 0x03048C20,
    };
    static s16 D_822030CC = 0;

    if (D_822031E0.unk_07 != 0) {
        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetEnvColor(gDisplayListHead++, 0, 100, 255, 255);

        if (D_800AE540.unk_11F5 & 4) {
            gDPSetPrimColor(gDisplayListHead++, 0, 0xFF, 255, 255, 255, D_82202FA0);
        } else {
            gDPSetPrimColor(gDisplayListHead++, 0, 0xFF, 255, 255, 255, 255);
        }

        gDPLoadTextureBlock_4b(gDisplayListHead++, D_8220307C[D_822030CC], G_IM_FMT_I, 48, 40, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);

        func_8001C330(arg0 - 0x28, arg1 - 0x28, 0x50, 0x50, 0, 0, 0x200, 0x200, 0);

        D_822030CC = (D_822030CC + 1) % 20;
    }
}

void func_822018D4(s16 arg0, s16 arg1, s16 arg2) {
    if ((D_822031E0.unk_07 == 0) || (arg2 <= 0)) {
        return;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3044260, G_IM_FMT_I, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    if (1) {}

    func_8001C330(arg0 - (arg2 / 2), arg1 - (arg2 / 2), arg2, arg2, 0, 0, 0x10000 / arg2, 0x10000 / arg2, 0);
}

#ifdef NON_MATCHING
void func_82201AC8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 sp54;
    s16 sp4C;
    s16 var_s2;
    s16 var_s3;
    s16 sp50;

    if (arg2 >= 0x10) {
        var_s3 = 8;
    } else {
        var_s3 = arg2 / 2;
    }
    sp4C = 0x2000 / var_s3;

    if (arg3 >= 0x10) {
        var_s2 = 8;
    } else {
        var_s2 = arg3 / 2;
    }
    sp50 = 0x2000 / var_s2;

    sp54 = (arg0 + arg2) - var_s3;

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A60, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, sp4C, sp50, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028AA0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(sp54, arg1, var_s3, var_s2, 0, 0, sp4C, sp50, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20289E0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, sp4C, sp50, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A20, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(sp54, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, sp4C, sp50, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    sp54 = arg3 - (var_s2 * 2);
    sp50 = arg2 - (var_s3 * 2);

    if ((sp50 > 0) && (sp54 > 0)) {
        func_8001C604(arg0 + var_s3, arg1, sp50, var_s2, arg4, arg5, arg6, arg7);
        func_8001C604(arg0, arg1 + var_s3, arg2, sp54, arg4, arg5, arg6, arg7);
        func_8001C604(arg0 + var_s3, arg1 + var_s3 + sp54, sp50, var_s2, arg4, arg5, arg6, arg7);
    } else if (sp50 > 0) {
        func_8001C604(arg0 + var_s3, arg1, sp50, arg3, arg4, arg5, arg6, arg7);
    } else if (sp54 > 0) {
        func_8001C604(arg0, arg1 + var_s2, arg2, sp54, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/37/fragment37/func_82201AC8.s")
#endif

void func_822022C8(s32 arg0) {
    func_82201AC8(0x38, 0x17C, 0x210, 0x3C, 0x1E, 0x1E, 0x82, 0x96);

    if (arg0 != 0) {
        func_8001F3F4();
        func_8001EBE0(8, 0);
        func_8001F3B4(0x18);
        func_8001F1E8(0x5B, 0x182, func_8002D7C0(NULL, 0, D_822030F0, D_822031D8));
        func_8001F444();
    }
}

void func_82202374(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

s32 func_822023A4(void) {
    s8 var_s0 = 8;
    s32 var_t1 = 1;

    D_82203160->unk_00 = D_82202FE4[D_822031D8].unk_00;
    D_82203160->unk_02 = D_82202FE4[D_822031D8].unk_02;
    D_82203160->unk_04 = D_82202FE4[D_822031D8].unk_04;
    D_82203160->unk_06 = 0x64;

    D_82203150.unk_00 = D_82202FE4[D_822031D8].unk_00;
    D_82203150.unk_02 = D_82202FE4[D_822031D8].unk_02;
    D_82203150.unk_08 = D_82202FE4[D_822031D8].unk_0A;
    D_82203150.unk_06 = 0;
    D_82203150.unk_04 = 0x12C;

    if (D_80068BA0->unk_08 & 0x8000) {
        if (D_822031D8 == 3) {
            func_8004E810(0x96, 8);
        }
        func_80048B90(0x33);
        func_80048B90(0x16);
        var_t1 = 3;
    } else if (D_80068BA0->unk_08 & 0x4000) {
        func_8000D23C(0x28);
        func_80048B90(3);
        var_t1 = 4;
    } else if (D_80068BA0->unk_08 & 0x800) {
        var_s0 = D_82202FE4[D_822031D8].unk_06;
    } else if (D_80068BA0->unk_08 & 0x400) {
        var_s0 = D_82202FE4[D_822031D8].unk_07;
    } else if (D_80068BA0->unk_08 & 0x200) {
        var_s0 = D_82202FE4[D_822031D8].unk_08;
    } else if (D_80068BA0->unk_08 & 0x100) {
        var_s0 = D_82202FE4[D_822031D8].unk_09;
    }

    if (var_s0 != 8) {
        func_80048B90(0x32);
        var_t1 = 2;
        D_822031DA = D_822031D8;
        D_822031D8 = var_s0;
        D_822031DC = 0;
    }

    return var_t1;
}

s16 func_82202520(void) {
    s32 var_v1;
    s32 v8_0;
    s32 v8_2;
    s32 v8_4;
    s32 vA_0;
    s32 vA_2;
    s32 vA_4;

    vA_0 = D_82202FE4[D_822031DA].unk_00;
    vA_2 = D_82202FE4[D_822031DA].unk_02;
    vA_4 = D_82202FE4[D_822031DA].unk_04;
    v8_0 = D_82202FE4[D_822031D8].unk_00;
    v8_2 = D_82202FE4[D_822031D8].unk_02;
    v8_4 = D_82202FE4[D_822031D8].unk_04;

    D_822031DC++;

    D_82203160->unk_00 = (((v8_0 - vA_0) * D_822031DC) / 6) + vA_0;
    D_82203160->unk_02 = (((v8_2 - vA_2) * D_822031DC) / 6) + vA_2;
    D_82203160->unk_04 = (((v8_4 - vA_4) * D_822031DC) / 6) + vA_4;
    D_82203160->unk_06 = 0x64;
    D_82203160->unk_08 += 0x800;

    if (D_822031DC == 6) {
        var_v1 = 1;
    } else {
        var_v1 = 2;
    }

    return var_v1;
}

s32 func_8220263C(void) {
    s32 var_v1 = 3;

    if (D_82203160->unk_06 >= 0xB) {
        D_82203160->unk_06 -= 5;
    } else {
        D_82203160->unk_06 = 0;
        if (D_822031D8 == 3) {
            func_8000D278(0x20);
            var_v1 = 6;
        } else {
            if (D_822031D8 != 7) {
                func_8000D278(0x28);
            }
            var_v1 = 5;
        }
    }
    return var_v1;
}

s32 func_822026BC(void) {
    s16 var_a1 = 5;

    if (D_82203150.unk_08.a < 0xFA) {
        D_82203150.unk_08.a += 0x19;
    } else if (D_82203150.unk_06 < 0xFF) {
        D_82203150.unk_08.a = 0xFF;
        D_82203150.unk_06 += 0x19;
        if (D_82203150.unk_06 >= 0xFF) {
            D_82203150.unk_06 = 0xFF;
            func_80007990(1);
            func_80006CB4(1);
            var_a1 = 5;
        }
    } else {
        var_a1 = func_82200020(7);
    }
    return var_a1;
}

s32 func_82202758(void) {
    s16 var_a1 = 6;

    if (D_82202FA4 < 0x200) {
        D_82202FA4 += 0x40;
    } else if (D_82202FA4 == 0x200) {
        D_82202FA4 += 0x40;
        func_80007990(0xFFFF);
        func_80006CB4(2);
        var_a1 = 6;
    } else if (D_82202FA4 < 0x280) {
        D_82202FA4 += 0x40;
        if (D_82202FA4 == 0x280) {
            var_a1 = 7;
        }
    }
    return var_a1;
}

s32 func_822027E8(void) {
    s32 temp_v0 = func_80007604();
    s16 var_v1 = 4;

    switch (temp_v0) {
        case 0:
            func_80007990(0xFFFF);
            func_80006CB4(0x10);
            var_v1 = 4;
            break;

        case 1:
            D_822031D8 = 8;
            var_v1 = 7;
            break;
    }

    return var_v1;
}

void func_82202850(void) {
    guOrtho(&D_82203108, 0.0f, 640.0f, 480.0f, 0.0f, -2.0f, 2.0f, 1.0f);
    func_8001E6E8(&D_822030F8, 0x280, 0x1E0);

    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPViewport(gDisplayListHead++, (u32)&D_822030F8 & 0x1FFFFFFF);
    gSPMatrix(gDisplayListHead++, (u32)&D_82203108 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void func_82202980(s16 arg0) {
    func_800079C4();
    func_82202850();

    if (D_82202FA0 == 0) {
        func_8001D924(D_82203148);
    } else if (D_82202FA0 == 0xFF) {
        func_8001D924(D_8220314C);
    } else {
        func_82200088(D_82203148, D_8220314C, D_82202FA0);
    }

    func_82201654(0x12C, 0x41);
    func_82201108();
    func_822014C8(arg0, 0x194, 0x28);
    func_822018D4(0x12C, 0x41, D_82202FA4);
    func_82200690();

    if ((arg0 == 1) || (arg0 == 2)) {
        func_822022C8(arg0 == 1);
    }

    func_80007778();
}

s32 func_82202A6C(void) {
    s16 var_v1 = 8;

    D_822031D8 = 8;
    if (func_80007604() == 0) {
        D_82202FA0 += 4;
        if (D_82202FA0 == 0x100) {
            D_800AE540.unk_11F5 &= 0xFFFB;
            D_82202FA0 = 0xFF;
            D_822031DA = 8;
            D_822031D8 = 0;
            var_v1 = 2;
        }
    }
    return var_v1;
}

void func_82202AFC(void) {
    func_82200BF4(D_822031D8);
    func_8000D1F0(0x50);
    func_80006C6C(0xA);

    while (func_80007604() != 0) {
        func_82202374();
        func_82202980(0);
    }
}

void func_82202B60(void) {
    s16 i;

    i = 2;
    if (D_800AE540.unk_11F5 & 4) {
        func_8004E810(0x96, 7);
        i = 8;
    }

    if (D_822031E0.unk_07 == 0) {
        D_82202FE4[0].unk_06 = 8;
        D_82202FE4[2].unk_09 = 8;
        D_82202FE4[7].unk_06 = 8;
    }

    D_822031DA = 8;
    D_822031D8 = 0;

    while (i != 7) {
        func_82202374();

        switch (i) {
            case 1:
                i = func_822023A4();
                break;
            case 2:
                i = func_82202520();
                break;

            case 3:
                i = func_8220263C();
                break;

            case 4:
                i = func_822027E8();
                break;

            case 5:
                i = func_822026BC();
                break;

            case 6:
                i = func_82202758();
                break;

            case 8:
                i = func_82202A6C();
                break;
        }

        func_82202980(i);
    }
}

void func_82202CB8(void) {
    D_822030F4 = ASSET_LOAD2(backgrounds, backgrounds, 1, 1);

    if (D_822031E8.unk_00 == 2) {
        if (D_800AE540.unk_11F2 == 0) {
            D_82203148 = func_8000484C(D_822030F4, 1);
            D_8220314C = func_8000484C(D_822030F4, 2);
        } else {
            D_8220314C = D_82203148 = func_8000484C(D_822030F4, 2);
        }
    } else if (D_822031E8.unk_00 == 1) {
        D_8220314C = D_82203148 = func_8000484C(D_822030F4, 0x13);
    } else {
        D_8220314C = D_82203148 = func_8000484C(D_822030F4, 0x12);
    }
}

s32 func_82202DC4(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('LAND');

    func_80005E40(0x10000, 0);
    sp24 = func_80007444(1, 0, 2, 0, 2, 1);
    func_8001E94C(0x1C, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, area_select_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);

    func_8002D510();
    D_822030F0 = func_8002D5AC(0x17);
    func_80028AFC(2);
    func_80027F24(&D_822031E8);
    func_80027FA0(&D_822031E0, D_800AE540.unk_11F2);
    func_82202CB8();
    D_822031D8 = 8;

    if ((D_822031E0.unk_07 != 0) && !(D_800AE540.unk_11F5 & 4) && !(D_822031E0.unk_00 & 0x100)) {
        D_82202FA0 = 0xFF;
    }

    func_80007678(sp24);
    func_82202AFC();
    func_82202B60();
    func_800076C0();
    func_80005EAC();

    main_pool_pop_state('LAND');

    return D_82202FA8[D_822031D8];
}
