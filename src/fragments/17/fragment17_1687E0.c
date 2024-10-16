#include "fragment17.h"
#include "src/1CF30.h"
#include "src/6BC0.h"

static Gfx D_86B0DFD0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM),
    gsDPSetPrimColor(0, 0, 5, 5, 5, 255),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_NONE),
    gsSPEndDisplayList(),
};

static Gfx D_86B0E018[] = {
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsSPSetGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING),
    gsSPEndDisplayList(),
};

unk_D_86B0C160 D_86B0E040[] = {
    {
        0,
        0,
        0,
        0,
        12743,
        0.0f,
        10.0f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        4.0f,
        0.15000000596046448f,
        0.009999999776482582f,
        30.0f,
    },
    {
        0,
        0,
        0,
        0,
        0,
        0.0f,
        10.0f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        3.0f,
        0.15000000596046448f,
        0.009999999776482582f,
        200.0f,
    },
    {
        0,
        0,
        0,
        7281,
        16384,
        0.0f,
        10.0f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        3.5f,
        0.15000000596046448f,
        0.009999999776482582f,
        200.0f,
    },
    {
        0,
        0,
        0,
        25486,
        9102,
        0.0f,
        10.0f,
        0,
        0,
        0,
        0,
        -380,
        0.5f,
        4.0f,
        0.15000000596046448f,
        0.009999999776482582f,
        200.0f,
    },
    {
        0,
        12743,
        0,
        -3640,
        9102,
        3.0f,
        10.0f,
        0,
        0,
        0,
        1820,
        0,
        0.0f,
        3.5f,
        0.15000000596046448f,
        0.009999999776482582f,
        200.0f,
    },
    {
        0,
        0,
        0,
        14563,
        0,
        0.0f,
        10.0f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        4.0f,
        0.15000000596046448f,
        0.009999999776482582f,
        200.0f,
    },
    {
        -7282,
        0,
        0,
        25486,
        14563,
        2.0f,
        10.0f,
        0,
        0,
        0,
        0,
        -198,
        0.5f,
        4.0f,
        0.15000000596046448f,
        0.009999999776482582f,
        200.0f,
    },
    {
        0,
        0,
        0,
        -3640,
        23665,
        0.0f,
        10.0f,
        0,
        0,
        0,
        1820,
        0,
        0.0f,
        3.5f,
        0.15000000596046448f,
        0.009999999776482582f,
        200.0f,
    },
    {
        0,
        0,
        0,
        14563,
        0,
        0.0f,
        10.0f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        4.0f,
        0.15000000596046448f,
        0.009999999776482582f,
        200.0f,
    },
    {
        0,
        0,
        0,
        -3640,
        0,
        0.0f,
        7.0f,
        0,
        0,
        0,
        1820,
        0,
        0.0f,
        3.5f,
        0.15000000596046448f,
        0.009999999776482582f,
        200.0f,
    },
};

static s16 D_86B106A0;
static s16 D_86B106A2;
static s16 D_86B106A4;

void func_86B08E50(s32 arg0, s32 arg1) {
    D_86B106A0 = arg0;
    D_86B106A4 = arg1;

    if ((D_86B106A0 == 0) || ((D_86B106A0 != 1) && (D_86B106A0 != 2) && (D_86B106A0 == 3))) {
        D_86B106A2 = 0x140;
    } else {
        D_86B106A2 = 0;
    }
}

s32 func_86B08EA8(void) {
    return D_86B106A0;
}

void func_86B08EB4(void) {
    s16 tmp = D_86B106A2;

    switch (D_86B106A0) {
        case 2:
            if (tmp < 0x140) {
                tmp += D_86B106A4;
            } else {
                D_86B106A0 = 0;
            }
            break;

        case 3:
            if (tmp > 0) {
                tmp -= D_86B106A4;
            } else {
                D_86B106A0 = 1;
            }

            if (tmp < 0) {
                tmp = 0;
            }
            break;
    }

    D_86B106A2 = tmp;
}

Gfx* func_86B08F48(Gfx* gfx, u32 arg1) {
    s32 idx1 = arg1 % 2;
    s32 idx2 = (arg1 + 1) % 2;
    s32 i;
    s16 xl;
    s16 yl;

    gSPDisplayList(gfx++, D_86B0DFD0);

    gDPLoadTextureBlock_4b(gfx++, D_3000000, G_IM_FMT_I, 12, 48, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gDPPipeSync(gfx++);

    for (i = idx1; i < 5; i += 2) {
        xl = (D_86B106A2 * 2) - 0x140;
        yl = (i * 0x30);

        gSPScisTextureRectangle(gfx++, xl << 2, yl << 2, (xl + 0x280) << 2, (yl + 24) << 2, 0, 0, 0, 1 << 6, 1 << 10);
        gSPScisTextureRectangle(gfx++, xl << 2, (yl + 24) << 2, (xl + 0x280) << 2, (yl + 48) << 2, 0, 0, 0, 1 << 6,
                                1 << 10);
    }

    for (i = idx2; i < 5; i += 2) {
        xl = -D_86B106A2 * 2;
        yl = (i * 0x30);

        gSPScisTextureRectangle(gfx++, xl << 2, yl << 2, (xl + 0x280) << 2, (yl + 24) << 2, 0, 0x500, 0, -(1 << 6),
                                1 << 10);
        gSPScisTextureRectangle(gfx++, xl << 2, (yl + 24) << 2, (xl + 0x280) << 2, (yl + 48) << 2, 0, 0x500, 0,
                                -(1 << 6), 1 << 10);
    }

    gSPDisplayList(gfx++, D_86B0E018);

    return gfx;
}

void func_86B095C4(void) {
    Gfx* var_a0 = gDisplayListHead;

    if (D_86B106A0 != 0) {
        if (D_86B106A0 == 2) {
            var_a0 = func_86B08F48(var_a0, 0);
        } else {
            var_a0 = func_86B08F48(var_a0, 1);
        }
    }
    gDisplayListHead = var_a0;
}

void func_86B0961C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    unk_D_800A7440 sp30;

    func_80005FC0(&sp30, arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);

    if (func_80006030(&sp30) != 0) {
        if (arg6 != 0) {
            arg4 += ((sp30.x1 - arg0) * arg6) >> 5;
        }

        if (arg7 != 0) {
            arg5 += ((sp30.y2 - arg1) * arg7) >> 5;
        }

        sp30.y1 += 1;
        sp30.x2 += 1;

        gSPTextureRectangle(gDisplayListHead++, sp30.x1 << 2, sp30.y2 << 2, sp30.y1 << 2, sp30.x2 << 2, G_TX_RENDERTILE,
                            arg4, arg5, arg6, arg7);
    }
}

void func_86B097B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, UNUSED s32 arg5) {
    gDPLoadTextureTile(gDisplayListHead++, arg4, G_IM_FMT_IA, G_IM_SIZ_8b, arg2, arg3, 0, 0, arg2 - 1, arg3 - 1, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    func_86B0961C(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0x400);
}

void func_86B09928(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, unk_D_86B0DAE0_000* arg5) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                      PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetEnvColor(gDisplayListHead++, (u8)arg5->unk_06, (u8)arg5->unk_08, (u8)arg5->unk_0A, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, (u8)arg5->unk_00, (u8)arg5->unk_02, (u8)arg5->unk_04, 255);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    func_86B097B0(arg1, arg2, arg3, arg4, arg0, arg3);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_86B09AD8(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg1, arg2, arg3, arg4, arg0, arg3, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}
