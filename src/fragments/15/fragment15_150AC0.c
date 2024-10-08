#include "fragment15.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/2E110.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/F420.h"

const char D_8690A520[] = "FREE BATTLE";
const char D_8690A52C[] = "POK\xE9 CUP";
const char D_8690A538[] = "POK\xE9 CUP2";
const char D_8690A544[] = "PETIT CUP";
const char D_8690A550[] = "PIKA CUP";
const char D_8690A55C[] = "PRIME CUP";
const char D_8690A568[] = "PEWTER GYM";
const char D_8690A574[] = "CERULEAN GYM";
const char D_8690A584[] = "VERMILION GYM";
const char D_8690A594[] = "CELADON GYM";
const char D_8690A5A0[] = "FUCHSIA GYM";
const char D_8690A5AC[] = "SAFFRON GYM";
const char D_8690A5B8[] = "CINNABAR GYM";
const char D_8690A5C8[] = "VIRIDIAN GYM";
const char D_8690A5D8[] = "VS ELITE FOUR";
const char D_8690A5E8[] = "VS MEWTWO";

extern u8 D_50002A0[];
extern u8 D_50003F0[];
extern u8 D_5000BA0[];
extern u8 D_5000C90[];
extern u8 D_50011D0[];
extern u8 D_5001680[];
extern u8 D_50017E8[];
extern u8 D_5001950[];
extern u8 D_5003AE8[];

void func_86904070(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    unk_D_80068BB0* temp_s1 = func_8000648C();
    Vtx* temp_s2 = func_80005F5C(sizeof(Vtx) * 4);
    Mtx* sp84 = func_80005F5C(sizeof(Mtx) * 1);
    Vp* sp80 = func_80005F5C(sizeof(Vp) * 1);

    func_8001E6E8(sp80, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp80 & 0x1FFFFFFF);

    guOrtho(sp84, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    func_8001E680(&temp_s2[0], arg0, arg1, -1, 0, 0, 0, 0, 0, arg4);
    func_8001E680(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, 0, 0, 0, arg4);
    func_8001E680(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);
    func_8001E680(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_FOG | G_LIGHTING);
    gSPSetGeometryMode(gDisplayListHead++, G_SHADE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)sp84 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}

void func_869043F4(void) {
}

void func_869043FC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 var_s2;
    s16 var_s3;
    s16 sp4C;
    s16 sp48;

    if (arg2 >= 0x10) {
        var_s3 = 8;
    } else {
        var_s3 = arg2 / 2;
    }

    if (arg3 >= 0x10) {
        var_s2 = 8;
    } else {
        var_s2 = arg3 / 2;
    }

    sp4C = arg2 - (var_s3 * 2);
    sp48 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A60, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028AA0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20289E0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A20, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3,
                  0x2000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((sp4C > 0) && (sp48 > 0)) {
        func_8001C604(arg0 + var_s3, arg1, sp4C, var_s2, arg4, arg5, arg6, arg7);
        func_8001C604(arg0, (arg1 + var_s3), arg2, sp48, arg4, arg5, arg6, arg7);
        func_8001C604(arg0 + var_s3, (arg1 + var_s3) + sp48, sp4C, var_s2, arg4, arg5, arg6, arg7);
    } else if (sp4C > 0) {
        func_8001C604(arg0 + var_s3, arg1, sp4C, arg3, arg4, arg5, arg6, arg7);
    } else if (sp48 > 0) {
        func_8001C604(arg0, arg1 + var_s2, arg2, sp48, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_86904BFC(void) {
}

void func_86904C04(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
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

void func_86904D98(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8* arg4, s16 arg5) {
    gDPLoadTextureTile(gDisplayListHead++, arg4, G_IM_FMT_IA, G_IM_SIZ_8b, arg2, 0, 0, 0, arg2 - 1, arg3 - 1, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 3, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_86904C04(arg0, arg1, arg2, arg3, D_8690B360.unk_02 << 5, 0, 0x400, 0x400);
}

void func_86904F2C(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_FOG | G_LIGHTING);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0,
                      COMBINED, 0, 0, 0, COMBINED);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 95, 55, 0, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);

    func_86904D98(arg1, arg2, arg3, arg4, arg0, arg3);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_869050C8(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    Vec3s spD8;
    Vec3f spCC;
    Vec3f spC0;
    UNUSED s32 pad;
    unk_D_80068BB0* spB8;
    Vtx* spB4;
    MtxF* spB0;
    Mtx* spAC;
    MtxF* spA8;
    Vp* spA4;

    spB8 = func_8000648C();
    spB4 = func_80005F5C(sizeof(Vtx) * 4);
    spB0 = func_80005F5C(sizeof(MtxF) * 1);
    spAC = func_80005F5C(sizeof(Mtx) * 1);
    spA8 = func_80005F5C(sizeof(MtxF) * 1);
    spA4 = func_80005F5C(sizeof(Vp) * 1);

    func_8000EB70(&spD8, 0, 0, D_8690B360.unk_06);

    func_8000E88C(&spCC, (f32)arg1 + (arg3 / 2), (f32)arg2 + arg4, 0.0f);
    func_8000E88C(&spC0, 1.0f, 1.0f, 1.0f);
    func_8000F2C4(spA8, &spCC, &spD8);
    func_8000FDE4(spA8, spA8, &spC0);
    func_80010090(spB0, spA8);
    func_8001E6E8(spA4, spB8->width, spB8->height);

    gSPViewport(gDisplayListHead++, (u32)spA4 & 0x1FFFFFFF);

    guOrtho(spAC, 0.5f, spB8->width - 0.5f, spB8->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    func_8001E680(&spB4[0], -(arg3 / 2), -arg4, -1, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spB4[1], (arg3 / 2), -arg4, -1, arg3 << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spB4[2], -(arg3 / 2), 0, -1, 0, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spB4[3], (arg3 / 2), 0, -1, arg3 << 5, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    if (D_8690B360.unk_06 == 0) {
        gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
        gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    } else {
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    }

    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureTile(gDisplayListHead++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg3, 0, 0, 0, arg3 - 1, arg4 - 1, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)spAC & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)spB0 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)spB4 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
    gSPDisplayList(gDisplayListHead++, D_8006F630);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

#ifdef NON_MATCHING
void func_86905734(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u8 arg6) {
    f32 a1;
    f32 a2;
    s16 spF8[4];
    s16 spF0[4];
    unk_D_80068BB0* spEC;
    Vtx* spE8;
    Mtx* spE4;
    Vp* spE0;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    s32 tmp1;

    spEC = func_8000648C();
    spE8 = func_80005F5C(sizeof(Vtx) * 4);
    spE4 = func_80005F5C(sizeof(Mtx) * 1);
    spE0 = func_80005F5C(sizeof(Vp) * 1);

    sp64 = arg1;
    sp5C = arg2;

    spF8[0] = ((-(arg3 / 2) * COSS(arg5)) - (SINS(arg5) * -arg4)) + sp64;
    spF0[0] = (COSS(arg5) * -arg4) + (-(arg3 / 2) * SINS(arg5)) + sp5C;

    spF8[1] = (((arg3 / 2) * COSS(arg5)) - (SINS(arg5) * -arg4)) + sp64;
    spF0[1] = (COSS(arg5) * -arg4) + ((arg3 / 2) * SINS(arg5)) + sp5C;

    spF8[2] = (-(arg3 / 2) * COSS(arg5)) + sp64;
    spF0[2] = (-(arg3 / 2) * SINS(arg5)) + sp5C;

    spF8[3] = ((arg3 / 2) * COSS(arg5)) + sp64;
    spF0[3] = ((arg3 / 2) * SINS(arg5)) + sp5C;

    func_8001E6E8(spE0, spEC->width, spEC->height);

    gSPViewport(gDisplayListHead++, (u32)spE0 & 0x1FFFFFFF);

    guOrtho(spE4, 0.5f, spEC->width - 0.5f, spEC->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    func_8001E680(&spE8[0], spF8[0], spF0[0], -1, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spE8[1], spF8[1], spF0[1], -1, arg3 << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spE8[2], spF8[2], spF0[2], -1, 0, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spE8[3], spF8[3], spF0[3], -1, arg3 << 5, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);

    if (arg6 == 0) {
        gDPLoadTextureBlock(gDisplayListHead++, arg0, G_IM_FMT_IA, G_IM_SIZ_8b, arg3, arg4, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_FOG | G_LIGHTING);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0,
                      COMBINED, 0, 0, 0, COMBINED);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)spE4 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(gDisplayListHead++, (u32)spE8 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}
#else
void func_86905734(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u8 arg6);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/15/fragment15_150AC0/func_86905734.s")
#endif

void func_86905F24(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u8 arg6) {
    f32 a1;
    f32 a2;
    s16 spE0[4];
    s16 spD8[4];
    unk_D_80068BB0* spD4;
    Vtx* spD0;
    Mtx* spCC;
    Vp* spC8;

    spD4 = func_8000648C();
    spD0 = func_80005F5C(sizeof(Vtx) * 4);
    spCC = func_80005F5C(sizeof(Mtx) * 1);
    spC8 = func_80005F5C(sizeof(Vp) * 1);

    a1 = arg1;
    a2 = arg2;

    spE0[0] = (COSS(arg5) * -12.0f) + a1;
    spD8[0] = (SINS(arg5) * -12.0f) + a2;

    spE0[1] = (COSS(arg5) * 12.0f) + a1;
    spD8[1] = (SINS(arg5) * 12.0f) + a2;

    spE0[2] = ((COSS(arg5) * -12.0f) - (SINS(arg5) * 56.0f)) + a1;
    spD8[2] = (((SINS(arg5) * -12.0f) + COSS(arg5) * 56.0f)) + a2;

    spE0[3] = ((COSS(arg5) * 12.0f) - (SINS(arg5) * 56.0f)) + a1;
    spD8[3] = (((SINS(arg5) * 12.0f) + COSS(arg5) * 56.0f)) + a2;

    func_8001E6E8(spC8, spD4->width, spD4->height);

    gSPViewport(gDisplayListHead++, (u32)spC8 & 0x1FFFFFFF);

    guOrtho(spCC, 0.5f, spD4->width - 0.5f, spD4->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    func_8001E680(&spD0[0], spE0[0], spD8[0], -1, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spD0[1], spE0[1], spD8[1], -1, arg3 << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spD0[2], spE0[2], spD8[2], -1, 0, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spD0[3], spE0[3], spD8[3], -1, arg3 << 5, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);

    if (arg6 == 0) {
        gDPLoadTextureBlock(gDisplayListHead++, arg0, G_IM_FMT_IA, G_IM_SIZ_8b, arg3, arg4, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_FOG | G_LIGHTING);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0,
                      COMBINED, 0, 0, 0, COMBINED);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    gSPMatrix(gDisplayListHead++, (u32)spCC & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(gDisplayListHead++, (u32)spD0 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void func_869066C4(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u8 arg6) {
    f32 temp_fv0;
    f32 temp_fv1;
    s16 spE0[4];
    s16 spD8[4];
    unk_D_80068BB0* spD4;
    Vtx* spD0;
    Mtx* spCC;
    Vp* spC8;

    spD4 = func_8000648C();
    spD0 = func_80005F5C(sizeof(Vtx) * 4);
    spCC = func_80005F5C(sizeof(Mtx) * 1);
    spC8 = func_80005F5C(sizeof(Vp) * 1);

    temp_fv0 = arg1;
    temp_fv1 = arg2;

    spE0[0] = (COSS(arg5 + 0xC000) * -12.0f) + temp_fv0;
    spD8[0] = (SINS(arg5 + 0xC000) * -12.0f) + temp_fv1;

    spE0[1] = (COSS(arg5 + 0xC000) * 12.0f) + temp_fv0;
    spD8[1] = (SINS(arg5 + 0xC000) * 12.0f) + temp_fv1;

    spE0[2] = ((COSS(arg5 + 0xC000) * -12.0f) - (SINS(arg5 + 0xC000) * 56.0f)) + temp_fv0;
    spD8[2] = ((SINS(arg5 + 0xC000) * -12.0f) + (COSS(arg5 + 0xC000) * 56.0f)) + temp_fv1;

    spE0[3] = ((COSS(arg5 + 0xC000) * 12.0f) - (SINS(arg5 + 0xC000) * 56.0f)) + temp_fv0;
    spD8[3] = ((SINS(arg5 + 0xC000) * 12.0f) + (COSS(arg5 + 0xC000) * 56.0f)) + temp_fv1;

    func_8001E6E8(spC8, spD4->width, spD4->height);

    gSPViewport(gDisplayListHead++, (u32)spC8 & 0x1FFFFFFF);

    guOrtho(spCC, 0.5f, spD4->width - 0.5f, spD4->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    func_8001E680(&spD0[0], spE0[0], spD8[0], -1, arg3 << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spD0[1], spE0[1], spD8[1], -1, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spD0[2], spE0[2], spD8[2], -1, arg3 << 5, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&spD0[3], spE0[3], spD8[3], -1, 0, arg4 << 5, 0xFF, 0xFF, 0xFF, 0xFF);

    if (arg6 == 0) {
        gDPLoadTextureBlock(gDisplayListHead++, arg0, G_IM_FMT_IA, G_IM_SIZ_8b, arg3, arg4, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_FOG | G_LIGHTING);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0,
                      COMBINED, 0, 0, 0, COMBINED);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    gSPMatrix(gDisplayListHead++, (u32)spCC & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(gDisplayListHead++, (u32)spD0 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void func_86906E70(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 argA, u8 argB, u8 argC) {
    unk_D_80068BB0* temp_s1 = func_8000648C();
    Vtx* temp_s2 = func_80005F5C(sizeof(Vtx) * 4);
    Mtx* spAC = func_80005F5C(sizeof(Mtx) * 1);
    Vp* spA8 = func_80005F5C(sizeof(Vp));

    func_8001E6E8(spA8, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)spA8 & 0x1FFFFFFF);

    guOrtho(spAC, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    func_8001E680(&temp_s2[0], arg1, arg2, -1, argC << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&temp_s2[1], arg1 + arg3, arg2, -1, argB << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&temp_s2[2], arg1, arg2 + arg4, -1, argC << 5, arg6 << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&temp_s2[3], arg1 + arg3, arg2 + arg4, -1, argB << 5, arg6 << 5, 0xFF, 0xFF, 0xFF, 0xFF);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_POINT);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureTile(gDisplayListHead++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg5, 0, arg7, arg8, arg9 - 1, argA - 1,
                       0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)spAC & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
    gSPDisplayList(gDisplayListHead++, D_8006F630);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void func_869073D8(char* arg0) {
    Color_RGB8 sp4C;
    Color_RGB8 sp48;
    s32 sp44;
    UNUSED s16 pad2;
    s16 sp40;

    if (D_8690A710->unk_014 != 0) {
        sp44 = func_8001F5B0(0x10, 0, arg0);

        if (D_8690A710->unk_014 == 1) {
            func_86906E70(&D_5001950, 0x3C, 0xAE, 0x22, 0x2B, 0x64, 0x2B, 0, 0, 0x22, 0x2B, 0x21, 0);
            func_86906E70(&D_5001950, 0x5E, 0xAE, 0x22, 0x2B, 0x64, 0x2B, 0x22, 0, 0x44, 0x2B, 0x43, 0x22);
            func_86906E70(&D_5001950, 0x80, 0xAE, 0x20, 0x2B, 0x64, 0x2B, 0x44, 0, 0x64, 0x2B, 0x63, 0x44);
            func_86906E70(&D_5001950, 0xE2, 0xAE, 0x22, 0x2B, 0x64, 0x2B, 0, 0, 0x22, 0x2B, 0, 0x21);
            func_86906E70(&D_5001950, 0xC0, 0xAE, 0x22, 0x2B, 0x64, 0x2B, 0x22, 0, 0x44, 0x2B, 0x22, 0x43);
            func_86906E70(&D_5001950, 0xA0, 0xAE, 0x20, 0x2B, 0x64, 0x2B, 0x44, 0, 0x64, 0x2B, 0x44, 0x63);
            // clang-format off
            sp4C.r = 0xF0; sp4C.g = 0x78; sp4C.b = 0x6E;
            sp48.r = 0xF0; sp48.g = 0xF0; sp48.b = 0x78;
            // clang-format on
            sp40 = 5;
        } else {
            func_86906E70(&D_5003AE8, 0x4C, 0xAE, 0x20, 0x28, 0x20, 0x28, 0, 0, 0x20, 0x28, 0x1F, 0);
            func_86906E70(&D_5003AE8, 0x6C, 0xAE, 0x68, 0x28, 0x20, 0x28, 0x1C, 0, 0x20, 0x2B, 0x87, 0x20);
            func_86906E70(&D_5003AE8, 0xD4, 0xAE, 0x20, 0x28, 0x20, 0x28, 0, 0, 0x20, 0x28, 0, 0x20);
            // clang-format off
            sp4C.r = 0xDC; sp4C.g = 0xFF; sp4C.b = 0xDC;
            sp48.r = 0x78; sp48.g = 0xB4; sp48.b = 0xFF;
            // clang-format on
            sp40 = 7;
        }

        func_8001F3F4();
        func_8001F470();
        func_8001EBE0(0x10, 0);
        func_8001F324(sp4C.r, sp4C.g, sp4C.b, 0xFF);
        func_8001F36C(sp48.r, sp48.g, sp48.b, 0xFF);
        func_8001F1E8(0xA0 - (sp44 / 2), sp40 + 0xAE, arg0);
        func_8001F4C4();
        func_8001F444();
        func_86904070(0x50, 0xAC, 0xA0, 0x2D, 0);
    }
}

void func_86907858(UNUSED s32 arg0) {
    s32 i;
    s32 var_v1;

    if (D_8690B380 != 0) {
        func_869043FC(0x55, 0x20, 0x96, 0x8C, 0, 0, 0x8C, 0x64);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        if (D_8690B384 != 0) {
            var_v1 = 0xFF;
        } else {
            var_v1 = 0x37;
        }

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, var_v1);

        func_8001CADC(0x93, 0x20, 0x18, 0xF, &D_50017E8, 0x18, 0);

        if ((D_8690B38C - 4) != D_8690B384) {
            var_v1 = 0xFF;
        } else {
            var_v1 = 0x37;
        }

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, var_v1);

        func_8001CADC(0x93, 0x9C, 0x18, 0xF, &D_5001680, 0x18, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
        gSPDisplayList(gDisplayListHead++, D_8006F5A0);

        func_8001D560(0x59, (D_8690B388 * 0x14) + 0x35, 0x18, 0xE, D_5000000, &D_50002A0, 0x18, 0x100000);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        func_8001F3F4();
        func_8001EBE0(4, 0);

        for (i = D_8690B384; i < D_8690B384 + 5; i++) {
            if (D_8690B388 == (i - D_8690B384)) {
                func_8001F324(0xFF, 0xFF, 0, 0xFF);
            } else {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_8001F1E8(0xA0 - (func_8001F5B0(4, 0, D_86908C58[i]) / 2), ((i - D_8690B384) * 0x14) + 0x36,
                          D_86908C58[i]);
        }

        func_8001F444();
        func_86904070(0x4D, 0x34, 0xA6, 0x88, 0);
    }
}

void func_86907B78(void) {
    s32 sp3C;
    s32 sp38;
    Color_RGB8 sp34 = D_86908C98;
    Color_RGB8 sp30 = D_86908C9C;

    if (D_8690B348 >= 3) {
        func_86904070(0, 0, 0x140, 0xF0, D_8690B350.unk_04);
    }

    if (D_8690B348 == 4) {
        if (D_8690B350.unk_0E < 0x15) {
            func_8002053C(D_8690B350.unk_08, D_8690B350.unk_0A - (D_8690B350.unk_0E / 2), D_8690B350.unk_0C,
                          D_8690B350.unk_0E, &sp34, &sp34);
        } else {
            func_8002053C(D_8690B350.unk_08, D_8690B350.unk_0A - (D_8690B350.unk_0E / 2), D_8690B350.unk_0C,
                          D_8690B350.unk_0E, &sp34, &sp30);
        }

        if (D_8690B350.unk_0E >= 0x1F) {
            func_8001F3F4();
            func_8001EBE0(4, 0);
            sp3C = func_8001F5B0(4, 0, func_8002D7C0(NULL, 0, D_8690A678, 0));
            sp38 = func_8002D7C0(NULL, 0, D_8690A678, 0);
            func_8001F1E8((D_8690B350.unk_08 - (sp3C / 2)) + (D_8690B350.unk_0C / 2), D_8690B350.unk_0A - 8, sp38);
            func_8001F444();
        }
    }
}

s16 func_86907D38(s16 arg0) {
    if ((arg0 - D_8690B360.unk_04) <= (D_8690B360.unk_0C + 15.0f)) {
        return 1000;
    }
    return arg0 - D_8690B360.unk_04;
}

void func_86907D94(void) {
    s16 sp4E = D_8690B360.unk_0C;
    char sp40[12];
    char sp34[12];
    s16 sp32;
    s16 sp24 = sp4E + 0x17;

    if (D_8690B348 >= 2) {
        return;
    }

    func_86904F2C(D_5000BA0, func_86907D38(sp24 + 8), 0x18, 8, 0x1E);
    func_86904F2C(D_5000BA0, func_86907D38(sp24 + 0x10), 0x18, 8, 0x1E);

    if (D_8690B348 == 0) {
        if (D_8690B360.unk_00 == 0) {
            sprintf(&sp40, "%d", 0x18 - D_8690B344);

            func_8001F3F4();
            func_8001EBE0(2, 0);

            if ((0x18 - D_8690B344) >= 0xB) {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0, 0, 0xFF);
            }

            sp32 = 0;
            if ((0x18 - D_8690B344) < 0xA) {
                sp32 = 3;
            }

            func_8001F1E8(sp24 + sp32 + 9, 0x21, &sp40);
            func_8001F444();
        } else {
            sprintf(&sp40, "%d", 0x19 - D_8690B344);
            sprintf(&sp34, "%d", 0x18 - D_8690B344);

            func_8001F3F4();
            func_8001EBE0(2, 0);

            if ((0x19 - D_8690B344) >= 0xB) {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0, 0, 0xFF);
            }

            sp32 = 0;
            if ((0x18 - D_8690B344) < 0xA) {
                sp32 = 3;
            }

            func_8001F1E8((sp24 - D_8690B360.unk_00) + sp32 + 0x1D, 0x21, &sp40);

            if ((0x18 - D_8690B344) >= 0xB) {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0, 0, 0xFF);
            }

            sp32 = 0;
            if ((0x18 - D_8690B344) < 0xA) {
                sp32 = 3;
            }

            func_8001F1E8((sp24 - D_8690B360.unk_00) + sp32 + 9, 0x21, &sp34);
            func_8001F444();
        }
    } else if (D_8690B360.unk_00 == 0) {
        if (D_8690B344 != 0) {
            sprintf(&sp40, "%d", 0x18 - D_8690B344);

            func_8001F3F4();
            func_8001EBE0(2, 0);

            if ((0x18 - D_8690B344) >= 0xB) {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0, 0, 0xFF);
            }

            sp32 = 0;
            if ((0x18 - D_8690B344) < 0xA) {
                sp32 = 3;
            }

            func_8001F1E8(sp24 + sp32 + 9, 0x21, &sp40);
            func_8001F444();
        }
    } else {
        sprintf(&sp40, "%d", 0x17 - D_8690B344);
        sprintf(&sp34, "%d", 0x18 - D_8690B344);

        func_8001F3F4();
        func_8001EBE0(2, 0);

        if ((0x19 - D_8690B344) >= 0xB) {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            func_8001F324(0xFF, 0, 0, 0xFF);
        }

        sp32 = 0;
        if ((0x18 - D_8690B344) < 0xA) {
            sp32 = 3;
        }

        func_8001F1E8((sp24 + D_8690B360.unk_00 + sp32) - 0xB, 0x21, &sp40);

        if ((0x18 - D_8690B344) >= 0xB) {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            func_8001F324(0xFF, 0, 0, 0xFF);
        }

        sp32 = 0;
        if ((0x18 - D_8690B344) < 0xA) {
            sp32 = 3;
        }

        func_8001F1E8(sp24 + D_8690B360.unk_00 + sp32 + 9, 0x21, &sp34);
        func_8001F444();
    }

    func_869050C8(D_50003F0, sp4E, 0x13, 0x18, 0x29);
    func_86904F2C(D_5000BA0, func_86907D38(sp24), 0x18, 8, 0x1E);
    func_86904F2C(D_5000BA0, func_86907D38(sp24 + 0x18), 0x18, 8, 0x1E);
    func_86904F2C(D_5000BA0, func_86907D38(sp24 + 0x20), 0x18, 8, 0x1E);
    func_86904F2C(D_5000BA0, func_86907D38(sp24 + 0x28), 0x18, 8, 0x1E);
}

void func_86908418(void) {
    s16 sp30 = D_8690B360.unk_0C;
    s16 sp2E;

    if (D_8690B348 < 2) {
        return;
    }

    sp2E = sp30 + 0x17;

    if (func_86907D38(sp2E + 0) != 0x3E8) {
        func_86904F2C(D_5000BA0, func_86907D38(sp2E + 0), 0x18, 8, 0x1E);
    }

    if (func_86907D38(sp2E + 8) != 0x3E8) {
        func_86904F2C(D_5000BA0, func_86907D38(sp2E + 8), 0x18, 8, 0x1E);
    }

    if (func_86907D38(sp2E + 0x10) != 0x3E8) {
        func_86904F2C(D_5000BA0, func_86907D38(sp2E + 0x10), 0x18, 8, 0x1E);
    }

    if (func_86907D38(sp2E + 0x18) != 0x3E8) {
        func_86904F2C(D_5000BA0, func_86907D38(sp2E + 0x18), 0x18, 8, 0x1E);
    }

    if (func_86907D38(sp2E + 0x20) != 0x3E8) {
        func_86904F2C(D_5000BA0, func_86907D38(sp2E + 0x20), 0x18, 8, 0x1E);
    }

    if (func_86907D38(sp2E + 0x28) != 0x3E8) {
        func_86904F2C(D_5000BA0, func_86907D38(sp2E + 0x28), 0x18, 8, 0x1E);
    }

    func_869050C8(D_50003F0, sp30, 0x13, 0x18, 0x29);
}

void func_86908668(void) {
    if (D_8690B348 == 0) {
        func_86905734(&D_50011D0, D_8690B308.unk_00[0], D_8690B308.unk_00[4], 0x30, 0x19, 0, 0);
        func_86905734(&D_50011D0, D_8690B308.unk_00[1], D_8690B308.unk_00[5], 0x30, 0x19, 0x4000, 1);
        func_86905734(&D_50011D0, D_8690B308.unk_00[2], D_8690B308.unk_00[6], 0x30, 0x19, -0x8000, 1);
        func_86905734(&D_50011D0, D_8690B308.unk_00[3], D_8690B308.unk_00[7], 0x30, 0x19, -0x4000, 1);
        func_86905F24(&D_5000C90, D_8690B308.unk_10, D_8690B308.unk_20, 0x18, 0x38, 0, 0);
        func_869066C4(&D_5000C90, D_8690B308.unk_10, D_8690B308.unk_20, 0x18, 0x38, 0, 1);
        func_86905F24(&D_5000C90, D_8690B308.unk_14, D_8690B308.unk_24, 0x18, 0x38, 0x4000, 1);
        func_869066C4(&D_5000C90, D_8690B308.unk_14, D_8690B308.unk_24, 0x18, 0x38, 0x4000, 1);
        func_86905F24(&D_5000C90, D_8690B308.unk_18, D_8690B308.unk_28, 0x18, 0x38, -0x8000, 1);
        func_869066C4(&D_5000C90, D_8690B308.unk_18, D_8690B308.unk_28, 0x18, 0x38, -0x8000, 1);
        func_86905F24(&D_5000C90, D_8690B308.unk_1C, D_8690B308.unk_2C, 0x18, 0x38, -0x4000, 1);
        func_869066C4(&D_5000C90, D_8690B308.unk_1C, D_8690B308.unk_2C, 0x18, 0x38, -0x4000, 1);
    }
}

void func_869089AC(void) {
    if (D_8690B3C0.unk_00 != 0xFF) {
        func_869043FC(0x3C, 0x9B - (D_8690B3C0.unk_0C / 2), D_8690B3C0.unk_08, D_8690B3C0.unk_0C, 0, 0, 0x9B, 0x7D);
        func_8001F3F4();
        func_8001EBE0(2, 0);
        func_8001F3B4(0xC);
        func_8001F1E8(0x46, 0x9F - (D_8690B3C0.unk_0C / 2), D_8690B3D0);
        func_8001F444();
    }
}
