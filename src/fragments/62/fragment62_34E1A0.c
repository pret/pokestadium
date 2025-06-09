#include "fragment62.h"
#include "include/math.h"
#include "src/30640.h"
#include "src/6A40.h"

static unk_D_8439CA60 D_8439CA60;

static Lights2 D_84389300 = gdSPDefLights2(255, 255, 255, 255, 255, 255, 30, 30, 10, 255, 255, 255, 226, 30, 10);
static Gfx D_84389328[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_SHADE | G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH),
    gsSPSetLights2(D_84389300),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA2),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
    gsSPEndDisplayList(),
};
static Gfx D_843893A8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetColorDither(G_CD_NOISE),
    gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
    gsSPEndDisplayList(),
};

void func_843638E0(s16 arg0) {
    s32 i;
    s32 j;
    s16 tmp1;
    s16 tmp2;
    s16 tmp3;
    unk_D_8439CA60_0014* var_v0 = &D_8439CA60.unk_0014[0][0];

    D_8439CA60.unk_0000 = 0;
    D_8439CA60.unk_0002 = arg0;
    D_8439CA60.unk_0004 = 0;
    D_8439CA60.unk_0008 = 0.01f;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            tmp1 = i * 0x20;
            tmp3 = tmp1 * 0x10;
            tmp2 = j * 0x20;

            var_v0->unk_00 = (i * 9.0f) - 72.0f;
            var_v0->unk_04 = 1.0f;
            var_v0->unk_08 = (j * 7.0f) - 56.0f;

            var_v0->unk_18 = tmp1 * 0x10;
            var_v0->unk_1A = tmp2 * 0x10;

            var_v0++;
        }
    }
}

void func_84363A5C(s32 arg0, s32 arg1) {
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    UNUSED s32 pad;
    s16 sp46;

    sp6C = D_8439CA60.unk_0014[arg0][arg1].unk_00;
    sp68 = D_8439CA60.unk_0014[arg0][arg1].unk_04;
    sp64 = D_8439CA60.unk_0014[arg0][arg1].unk_08;
    sp84 = 0.0f;
    sp80 = 0.0f;
    sp7C = 0.0f;
    sp46 = 0;

    if ((arg0 > 0) && (arg1 >= 1)) {
        sp60 = D_8439CA60.unk_0014[arg0 - 1][arg1].unk_00 - sp6C;
        sp5C = D_8439CA60.unk_0014[arg0 - 1][arg1].unk_04 - sp68;
        sp58 = D_8439CA60.unk_0014[arg0 - 1][arg1].unk_08 - sp64;
        func_80031B04(&sp60, &sp5C, &sp58);
        sp54 = D_8439CA60.unk_0014[arg0][arg1 - 1].unk_00 - sp6C;
        sp50 = D_8439CA60.unk_0014[arg0][arg1 - 1].unk_04 - sp68;
        sp4C = D_8439CA60.unk_0014[arg0][arg1 - 1].unk_08 - sp64;
        func_80031B04(&sp54, &sp50, &sp4C);
        func_80031A94(sp60, sp5C, sp58, sp54, sp50, sp4C, &sp78, &sp74, &sp70);
        func_80031B04(&sp78, &sp74, &sp70);
        sp84 += sp78;
        sp80 += sp74;
        sp7C += sp70;
        sp46 = 1;
    }

    if ((0 < arg0) && (arg1 < 15)) {
        sp60 = D_8439CA60.unk_0014[arg0 - 1][arg1].unk_00 - sp6C;
        sp5C = D_8439CA60.unk_0014[arg0 - 1][arg1].unk_04 - sp68;
        sp58 = D_8439CA60.unk_0014[arg0 - 1][arg1].unk_08 - sp64;
        func_80031B04(&sp60, &sp5C, &sp58);
        sp54 = D_8439CA60.unk_0014[arg0][arg1 + 1].unk_00 - sp6C;
        sp50 = D_8439CA60.unk_0014[arg0][arg1 + 1].unk_04 - sp68;
        sp4C = D_8439CA60.unk_0014[arg0][arg1 + 1].unk_08 - sp64;
        func_80031B04(&sp54, &sp50, &sp4C);
        func_80031A94(sp60, sp5C, sp58, sp54, sp50, sp4C, &sp78, &sp74, &sp70);
        func_80031B04(&sp78, &sp74, &sp70);
        sp84 += sp78;
        sp80 += sp74;
        sp7C += sp70;
        sp46 += 1;
    }

    if ((arg0 < 15) && (arg1 >= 1)) {
        sp60 = D_8439CA60.unk_0014[arg0 + 1][arg1].unk_00 - sp6C;
        sp5C = D_8439CA60.unk_0014[arg0 + 1][arg1].unk_04 - sp68;
        sp58 = D_8439CA60.unk_0014[arg0 + 1][arg1].unk_08 - sp64;
        func_80031B04(&sp60, &sp5C, &sp58);
        sp54 = D_8439CA60.unk_0014[arg0][arg1 - 1].unk_00 - sp6C;
        sp50 = D_8439CA60.unk_0014[arg0][arg1 - 1].unk_04 - sp68;
        sp4C = D_8439CA60.unk_0014[arg0][arg1 - 1].unk_08 - sp64;
        func_80031B04(&sp54, &sp50, &sp4C);
        func_80031A94(sp60, sp5C, sp58, sp54, sp50, sp4C, &sp78, &sp74, &sp70);
        func_80031B04(&sp78, &sp74, &sp70);
        sp84 += sp78;
        sp80 += sp74;
        sp7C += sp70;
        sp46 += 1;
    }

    if ((arg0 < 15) && (arg1 < 15)) {
        sp60 = D_8439CA60.unk_0014[arg0 + 1][arg1].unk_00 - sp6C;
        sp5C = D_8439CA60.unk_0014[arg0 + 1][arg1].unk_04 - sp68;
        sp58 = D_8439CA60.unk_0014[arg0 + 1][arg1].unk_08 - sp64;
        func_80031B04(&sp60, &sp5C, &sp58);
        sp54 = D_8439CA60.unk_0014[arg0][arg1 + 1].unk_00 - sp6C;
        sp50 = D_8439CA60.unk_0014[arg0][arg1 + 1].unk_04 - sp68;
        sp4C = D_8439CA60.unk_0014[arg0][arg1 + 1].unk_08 - sp64;
        func_80031B04(&sp54, &sp50, &sp4C);
        func_80031A94(sp60, sp5C, sp58, sp54, sp50, sp4C, &sp78, &sp74, &sp70);
        func_80031B04(&sp78, &sp74, &sp70);
        sp84 -= sp78;
        sp80 -= sp74;
        sp7C -= sp70;
        sp46 += 1;
    }

    if (sp46 != 0) {
        if ((sp84 == 0.0) && (sp80 == 0.0) && (sp7C == 0.0)) {
            sp80 = 1.0f;
        } else {
            func_80031B04(&sp84, &sp80, &sp7C);
        }
        D_8439CA60.unk_0014[arg0][arg1].unk_0C = sp84;
        D_8439CA60.unk_0014[arg0][arg1].unk_10 = sp80;
        D_8439CA60.unk_0014[arg0][arg1].unk_14 = sp7C;
    }
}

void func_84363FF0(unk_D_8439CA60_0014* arg0, Vtx* arg1) {
    f32 r;
    f32 g;
    f32 b;

    arg1->v.ob[0] = arg0->unk_00;
    arg1->v.ob[1] = arg0->unk_04;
    arg1->v.ob[2] = arg0->unk_08;

    arg1->v.tc[0] = arg0->unk_18;
    arg1->v.tc[1] = arg0->unk_1A;

    r = arg0->unk_0C;
    g = arg0->unk_10;
    b = arg0->unk_14;

    arg1->v.cn[0] = (s32)(r * 120.0);
    arg1->v.cn[1] = (s32)(g * 120.0);
    arg1->v.cn[2] = (s32)(b * 120.0);
    arg1->v.cn[3] = D_8439CA60.unk_0004;
}

s32 func_843640A4(void) {
    unk_D_8439CA60_0014* var_s1;
    s32 i;
    s32 j;
    f32 temp_fv1_2;
    f32 tmp;

    D_8439CA60.unk_0000 = D_8439CA60.unk_0000 + 1;
    if (D_8439CA60.unk_0002 < D_8439CA60.unk_0000) {
        return -1;
    }
    if (D_8439CA60.unk_0000 < 0x1E) {
        D_8439CA60.unk_0004 += 0xA;
        if (D_8439CA60.unk_0004 >= 0x81) {
            D_8439CA60.unk_0004 = 0x80;
        }
    } else if ((D_8439CA60.unk_0002 - 0x1E) < D_8439CA60.unk_0000) {
        D_8439CA60.unk_0004 -= 0xA;
        if (D_8439CA60.unk_0004 < 0) {
            D_8439CA60.unk_0004 = 0;
        }
    }

    if (D_8439CA60.unk_0008 < 1.0) {
        D_8439CA60.unk_0008 += 0.05;
    }

    var_s1 = &D_8439CA60.unk_0014[0][0];
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            temp_fv1_2 = 1.0 - (sqrtf(SQ(var_s1->unk_00) + SQ(var_s1->unk_08)) / 101.8224f);
            tmp = __sinf((((f32)(D_8439CA60.unk_0000 % 20) / 20.0) + (3.0 * temp_fv1_2)) * 6.2831854820251465) *
                  ((f64)D_8439CA60.unk_0008 * temp_fv1_2);
            var_s1->unk_04 = tmp;
            var_s1++;
        }
    }

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            func_84363A5C(i, j);
        }
    }

    return 0;
}

void func_84364304(void) {
    unk_D_86002F34_00C* temp_v0;
    f32 tmp1;
    f32 tmp2;
    f32 tmp3;
    f32 tmp4;
    f32 tmp5;
    f32 tmp6;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;

    D_8439CA60.unk_0010 = func_80005F5C(sizeof(Mtx) * 1);
    temp_v0 = func_8432FD64();

    tmp4 = temp_v0->unk_60.at.x;
    tmp5 = temp_v0->unk_60.at.y;
    tmp6 = temp_v0->unk_60.at.z;

    tmp1 = temp_v0->unk_60.eye.x;
    tmp2 = temp_v0->unk_60.eye.y;
    tmp3 = temp_v0->unk_60.eye.z;

    sp5C = temp_v0->unk_24.fovy;
    sp68 = tmp4 - tmp1;
    sp64 = tmp5 - tmp2;
    sp60 = tmp6 - tmp3;

    func_80031B04(&sp68, &sp64, &sp60);

    temp_fv0 = sp5C / 30.0f;
    temp_fv1 = (140.0f * sp68) / temp_fv0;
    temp_fa0 = (140.0f * sp64) / temp_fv0;
    temp_fa1 = (140.0f * sp60) / temp_fv0;

    tmp4 += temp_fv1;
    tmp5 += temp_fa0;
    tmp6 += temp_fa1;

    tmp1 += temp_fv1;
    tmp2 += temp_fa0;
    tmp3 += temp_fa1;

    func_80031C6C(D_8439CA60.unk_0010, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6);
}

Gfx* func_84364428(Gfx* arg0) {
    s32 i;
    s32 j;
    unk_D_8439CA60_0014* var_s2;
    s32 var_s4;
    Vtx* vtx;
    s32 idx;

    var_s4 = 0;
    D_8439CA60.unk_000C = func_80005F5C(sizeof(Vtx) * 16 * 16);

    vtx = D_8439CA60.unk_000C;
    var_s2 = &D_8439CA60.unk_0014[0][0];
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            func_84363FF0(var_s2, vtx);
            var_s2++;
            vtx++;
        }
    }

    func_84364304();

    gDPLoadTextureBlock(arg0++, D_843920C0[0xA8], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gSPDisplayList(arg0++, D_84389328);
    gDPSetPrimColor(arg0++, 0, 0, 255, 255, 255, D_8439CA60.unk_0004);
    gSPMatrix(arg0++, D_8439CA60.unk_0010, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    vtx = D_8439CA60.unk_000C;
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            idx = (i + 0) * 16 + j;

            gSPVertex(arg0++, &vtx[idx + 0], 1, 0);
            gSPVertex(arg0++, &vtx[idx + 1], 1, 1);
            gSPVertex(arg0++, &vtx[((i + 1) * 16 + j) + (0 * 16) + 0], 1, 2);
            gSPVertex(arg0++, &vtx[idx + (1 * 16) + 1], 1, 3);

            if (!(var_s4 & 1)) {
                gSP2Triangles(arg0++, 1, 2, 0, 0, 1, 3, 2, 0);
            } else {
                gSP2Triangles(arg0++, 3, 2, 0, 0, 1, 3, 0, 0);
            }

            var_s4++;
        }
    }

    gSPPopMatrix(arg0++, G_MTX_MODELVIEW);
    return arg0;
}
