#include "fragment62.h"
#include "src/6A40.h"

static unk_D_843A22C0 D_843A22C0[40];

static Vtx D_84389690[] = {
    VTX(-10, 0, -10, 2048, 0, 0xFF, 0xFF, 0xFF, 0xC8),
    VTX(10, 0, -10, 0, 0, 0xFF, 0xFF, 0xFF, 0xC8),
    VTX(-10, 0, 10, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xC8),
    VTX(10, 0, 10, 0, 2048, 0xFF, 0xFF, 0xFF, 0xC8),
};
static Gfx D_843896D0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetColorDither(G_CD_NOISE),
    gsSPEndDisplayList(),
};
static Gfx D_84389720[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
    gsDPSetCombineMode(G_CC_BLENDIA, G_CC_BLENDIA),
    gsDPSetEnvColor(255, 255, 64, 255),
    gsSPVertex(D_84389690, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSPEndDisplayList(),
};

void func_84366A10(void) {
    unk_D_843A22C0* var_v0;
    unk_D_843A22C0_038* var_a0;
    s32 i;
    s32 j;

    var_v0 = &D_843A22C0[0];
    for (i = 0; i < 40; i++, var_v0++) {
        var_v0->unk_000 = 0;
        var_v0->unk_004 = 0;
        var_v0->unk_006 = 0;

        var_a0 = &var_v0->unk_038[0];
        for (j = 0; j < 10; j++, var_a0++) {
            var_a0->unk_00 = 0.0f;
            var_a0->unk_04 = 0;
            var_a0->unk_08 = 0.0f;
            var_a0->unk_0C.z = var_a0->unk_0C.y = var_a0->unk_0C.x = 0.0f;
            var_a0->unk_18.z = var_a0->unk_18.y = var_a0->unk_18.x = 0.0f;
        }
    }
}

void func_84366B38(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9,
                   f32 argA, s16 argB) {
    unk_D_843A22C0* var_v1;
    unk_D_843A22C0_038* var_s0;
    s32 i;
    s32 j;
    Vec3f sp74;
    Vec3f sp68;
    Vec3f sp5C;
    f32 temp_fv0;

    temp_fv0 = func_8432FCD4();

    sp74.x = arg0;
    sp74.y = arg1 + 10.0f + 25.0f;
    sp74.z = arg2;

    sp68.x = arg3;
    sp68.y = arg4;
    sp68.z = arg5;

    sp5C.x = 0.0f;
    sp5C.y = -1.0f;
    sp5C.z = 0.0f;

    var_v1 = &D_843A22C0[0];

    for (i = 0; i < 40; i++, var_v1++) {
        if (var_v1->unk_000 == 0) {
            var_v1->unk_000 = 1;
            var_v1->unk_002 = 0;
            var_v1->unk_004 = 0;
            var_v1->unk_006 = argB;
            var_v1->unk_00A.r = arg6;
            var_v1->unk_00A.g = arg7;
            var_v1->unk_00A.b = arg8;
            var_v1->unk_010 = temp_fv0 * 0.5f;
            var_v1->unk_014 = argA;

            if (arg0 > 0) {
                var_v1->unk_008 = -1;
            } else {
                var_v1->unk_008 = 1;
            }

            var_s0 = &var_v1->unk_038[0];
            for (j = 0; j < 10; j++, var_s0++) {
                var_s0->unk_00 = j;
                var_s0->unk_04 = (arg9 * (9 - j)) / 10;
                var_s0->unk_08 = (RAND(100) * 6.2831854820251465) / 100.0;
                var_s0->unk_0C = sp74;
                var_s0->unk_18 = sp68;
                var_s0->unk_24 = sp5C;
            }
            break;
        }
    }
}

void func_84366DCC(f32 arg0, Vec3f* arg1, f32 arg2) {
    MtxF sp30;

    guRotateRPYF(sp30.mf, 90.0f, (arg0 * 360.0) / 6.2831854820251465, (arg0 * 360.0) / 6.2831854820251465);
    guMtxXFMF(sp30.mf, 0.0f, 0.0f, arg2, &arg1->x, &arg1->y, &arg1->z);
}

void func_84366E54(unk_D_843A22C0* arg0) {
    s32 i;
    s32 j;
    Vtx* var_a1;
    Vtx* var_a2;
    unk_D_843A22C0_038* var_v0;
    unk_D_843A22C0_038* var_v1;

    var_v0 = &arg0->unk_038[9];
    for (i = 0; i < 9; i++, var_v0--) {
        var_a1 = &var_v0[0].unk_30[0];
        var_a2 = &var_v0[-1].unk_30[0];
        for (j = 0; j < 2; j++) {
            *var_a1++ = *var_a2++;
        }
    }

    var_v1 = &arg0->unk_038[0];
    switch (arg0->unk_002) {
        case 0:
            var_v1->unk_0C.y += var_v1->unk_24.y;
            if (arg0->unk_004 >= 0xB) {
                arg0->unk_002 = 1;
            }
            var_v1->unk_08 += 2.0 * arg0->unk_014;
            break;

        case 1:
            var_v1->unk_0C.x += var_v1->unk_18.x;
            var_v1->unk_0C.y += var_v1->unk_18.y;
            var_v1->unk_0C.z += var_v1->unk_18.z;

            if (arg0->unk_008 > 0) {
                var_v1->unk_18.x += 2.0;
                if (var_v1->unk_18.x > 20.0) {
                    var_v1->unk_18.x = 20.0f;
                }
            } else {
                var_v1->unk_18.x -= 2.0;
                if (var_v1->unk_18.x < -20.0) {
                    var_v1->unk_18.x = -20.0f;
                }
            }
            var_v1->unk_08 += arg0->unk_014;
            break;
    }
}

s32 func_84367014(void) {
    s32 i;
    s32 var_s2 = 0;
    unk_D_843A22C0* var_s0 = &D_843A22C0[0];

    for (i = 0; i < 40; i++, var_s0++) {
        if (var_s0->unk_000 == 1) {
            var_s0->unk_004 += 1;
            if ((var_s0->unk_006 + 0xA) < var_s0->unk_004) {
                var_s0->unk_000 = 0;
            } else {
                func_84366E54(var_s0);
                var_s2++;
            }
        }
    }

    if (var_s2 > 0) {
        return 0;
    }
    return -1;
}

Gfx* func_843670C8(Gfx* arg0) {
    s32 i;
    unk_D_843A22C0* var_s5;
    unk_D_843A22C0_038* temp_s0;
    s32 k;
    s32 j;
    Mtx* temp_s1;
    Vec3f sp13C;
    Vtx* vtx;
    Mtx spF8;
    Mtx spB8;
    f32 spB4;
    Vtx* vtx2;
    f32 tmp;

    gDPLoadTextureBlock_4b(arg0++, D_843920C0[0x10], G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    var_s5 = &D_843A22C0[0];
    for (i = 0; i < 40; i++, var_s5++) {
        if (var_s5->unk_000 == 1) {
            temp_s0 = &var_s5->unk_038[0];
            tmp = var_s5->unk_010;

            temp_s1 = func_80005F5C(sizeof(Mtx) * 1);

            spB4 = (temp_s0->unk_08 * 360.0) / 6.2831854820251465;
            guTranslate(temp_s1, temp_s0->unk_0C.x, temp_s0->unk_0C.y, temp_s0->unk_0C.z);

            if (var_s5->unk_002 == 0) {
                guRotateRPY(&spF8, 90.0f, spB4, 0.0f);
            } else {
                guRotateRPY(&spF8, 90.0f, spB4, spB4);
            }

            guMtxCatL(&spF8, temp_s1, temp_s1);
            guScale(&spB8, tmp, tmp, tmp);
            guMtxCatL(&spB8, temp_s1, temp_s1);

            gSPMatrix(arg0++, temp_s1, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(arg0++, D_84389720);
            gSPPopMatrix(arg0++, G_MTX_MODELVIEW);

            var_s5->unk_018 = func_80005F5C(sizeof(Vtx) * 20);
            vtx = var_s5->unk_018;

            for (j = 0; j < 10; j++, temp_s0++) {
                if ((j == 0) || (var_s5->unk_004 < 2)) {
                    for (k = 0, vtx2 = &temp_s0->unk_30[0]; k < 2; k++) {
                        if (temp_s0->unk_00 <= 0.0) {
                            func_84366DCC(temp_s0->unk_08 + ((2.0 * k * 3.1415927410125732) / 2), &sp13C,
                                          (10.0f * tmp) * 0.8f);
                        }

                        vtx->v.ob[0] = temp_s0->unk_0C.x + sp13C.x;
                        vtx->v.ob[1] = temp_s0->unk_0C.y + sp13C.y;
                        vtx->v.ob[2] = temp_s0->unk_0C.z + sp13C.z;

                        vtx->v.cn[0] = var_s5->unk_00A.r;
                        vtx->v.cn[1] = var_s5->unk_00A.g;
                        vtx->v.cn[2] = var_s5->unk_00A.b;
                        vtx->v.cn[3] = temp_s0->unk_04;

                        *vtx2++ = *vtx++;
                    }
                } else {
                    for (k = 0, vtx2 = &temp_s0->unk_30[0]; k < 2; k++) {
                        *vtx = *vtx2++;
                        vtx->v.cn[3] = temp_s0->unk_04;

                        vtx++;
                    }
                }
            }

            if (var_s5->unk_002 == 1) {
                vtx = var_s5->unk_018;

                for (k = 0; k < 9; k++) {
                    gSPDisplayList(arg0++, D_843896D0);
                    gSPVertex(arg0++, vtx, 4, 0);
                    gSP2Triangles(arg0++, 0, 1, 2, 0, 1, 3, 2, 0);

                    vtx += 2;
                }
            }
        }
    }

    return arg0;
}
