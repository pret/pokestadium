#include "fragment62.h"
#include "src/6A40.h"

static unk_D_843ADA80 D_843ADA80[50];

static Gfx D_84389A50[] = {
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
static Vtx D_84389AA0[] = {
    VTX(-6, 0, -6, 2048, 0, 0xFF, 0xFF, 0xFF, 0x14),
    VTX(6, 0, -6, 0, 0, 0xFF, 0xFF, 0xFF, 0x14),
    VTX(-6, 0, 6, 2048, 2048, 0xFF, 0xFF, 0xFF, 0x14),
    VTX(6, 0, 6, 0, 2048, 0xFF, 0xFF, 0xFF, 0x14),
};
Gfx D_84389AE0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPPipeSync(),
    gsSPVertex(D_84389AA0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSPEndDisplayList(),
};

void func_8436A410(void) {
    unk_D_843ADA80* var_v0 = &D_843ADA80[0];
    unk_D_843ADA80_040* var_a0;
    s32 i;
    s32 j;

    for (i = 0; i < 50; i++, var_v0++) {
        var_v0->unk_000 = 0;
        var_v0->unk_004 = 0;
        var_v0->unk_006 = 0;

        var_a0 = &var_v0->unk_040[0];

        for (j = 0; j < 10; j++, var_a0++) {
            var_a0->unk_00 = 0;
            var_a0->unk_04 = 1.0f;
            var_a0->unk_08 = 0.0f;

            var_a0->unk_0C.x = 0.0f;
            var_a0->unk_0C.y = 0.0f;
            var_a0->unk_0C.z = 0.0f;
            var_a0->unk_18.x = 0.0f;
            var_a0->unk_18.y = 0.0f;
            var_a0->unk_18.z = 0.0f;
        }
    }
}

void func_8436A540(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9,
                   f32 argA, f32 argB, f32 argC, s16 argD) {
    unk_D_843ADA80* var_v1;
    unk_D_843ADA80_040* var_s0;
    s32 i;
    s32 j;
    Vec3f sp7C;
    Vec3f sp70;
    Vec3f sp64;
    f32 temp_fv1;

    temp_fv1 = func_8432FCD4() * 0.5f;

    sp7C.x = arg0;
    sp7C.y = (80.0f * temp_fv1) + arg1;
    sp7C.z = arg2;

    sp70.x = arg3;
    sp70.y = arg4;
    sp70.z = arg5;

    sp64.x = 0.0f;
    sp64.y = temp_fv1 * -2.0;
    sp64.z = 0.0f;

    var_v1 = &D_843ADA80[0];

    for (i = 0; i < 50; i++, var_v1++) {
        if (var_v1->unk_000 == 0) {
            var_v1->unk_000 = 1;
            var_v1->unk_002 = 0;
            var_v1->unk_004 = 0;
            var_v1->unk_006 = argD;
            var_v1->unk_00A.r = arg6;
            var_v1->unk_00A.g = arg7;
            var_v1->unk_00A.b = arg8;
            var_v1->unk_024 = sp7C;
            var_v1->unk_014 = argC;
            var_v1->unk_018 = argA;
            var_v1->unk_010 = temp_fv1;

            if (arg0 > 0.0) {
                var_v1->unk_008 = -1;
            } else {
                var_v1->unk_008 = 1;
            }

            var_s0 = var_v1->unk_040;
            for (j = 0; j < 10; j++, var_s0++) {
                var_s0->unk_00 = (arg9 * (9 - j)) / 10;
                var_s0->unk_04 = argB;
                var_s0->unk_08 = (RAND(120) * 6.2831855f) / 120.0;
                var_s0->unk_0C = sp7C;
                var_s0->unk_18 = sp70;
                var_s0->unk_24 = sp64;
            }
            break;
        }
    }
}

void func_8436A808(f32 arg0, Vec3f* arg1, f32 arg2) {
    MtxF sp30;
    f32 temp_fv0 = (arg0 * 360.0) / 6.2831854820251465;

    guRotateRPYF(sp30.mf, 90.0f, temp_fv0, temp_fv0);
    guMtxXFMF(sp30.mf, 0.0f, 0.0f, arg2, &arg1->x, &arg1->y, &arg1->z);
}

void func_8436A890(unk_D_843ADA80* arg0) {
    s32 i;
    f32 temp_fs3 = arg0->unk_010;
    unk_D_843ADA80_040* var_s0 = &arg0->unk_040[0];

    for (i = 0; i < 10; i++, var_s0++) {
        if (i == 0) {
            var_s0->unk_30 = var_s0->unk_04;
            var_s0->unk_34 = var_s0->unk_08;
            var_s0->unk_38 = var_s0->unk_0C;
            var_s0->unk_44 = var_s0->unk_18;

            switch (arg0->unk_002) {
                case 0:
                    var_s0->unk_0C.x += var_s0->unk_24.x;
                    var_s0->unk_0C.y += var_s0->unk_24.y;
                    var_s0->unk_0C.z += var_s0->unk_24.z;
                    var_s0->unk_08 += arg0->unk_018;
                    var_s0->unk_24.x += __sinf(var_s0->unk_08) * temp_fs3;
                    var_s0->unk_24.z += __cosf(var_s0->unk_08) * temp_fs3;
                    if (arg0->unk_004 >= 0x15) {
                        arg0->unk_002 = 1;
                        arg0->unk_004 = 0;
                    }
                    break;

                case 1:
                    var_s0->unk_0C.x += var_s0->unk_18.x;
                    var_s0->unk_0C.y += var_s0->unk_18.y;
                    var_s0->unk_0C.z += var_s0->unk_18.z;
                    var_s0->unk_08 += arg0->unk_018;
                    if (arg0->unk_008 > 0) {
                        var_s0->unk_18.x += 2.0;
                        if (var_s0->unk_18.x > 20.0) {
                            var_s0->unk_18.x = 20.0f;
                        }
                    } else {
                        var_s0->unk_18.x -= 2.0;
                        if (var_s0->unk_18.x < -20.0) {
                            var_s0->unk_18.x = -20.0f;
                        }
                    }
                    break;
            }

            var_s0->unk_04 += 2.0;
            if (arg0->unk_014 < var_s0->unk_04) {
                var_s0->unk_04 = arg0->unk_014;
            }
        } else {
            var_s0->unk_30 = var_s0->unk_04;
            var_s0->unk_34 = var_s0->unk_08;

            var_s0->unk_38 = var_s0->unk_0C;
            var_s0->unk_44 = var_s0->unk_18;

            var_s0->unk_0C = var_s0[-1].unk_38;
            var_s0->unk_08 = var_s0[-1].unk_34;
            var_s0->unk_18 = var_s0[-1].unk_44;
            var_s0->unk_04 = var_s0[-1].unk_30;
        }
    }
}

s32 func_8436ABA8(void) {
    s32 i;
    unk_D_843ADA80* var_s0 = &D_843ADA80[0];

    for (i = 0; i < 50; i++, var_s0++) {
        if (var_s0->unk_000 == 1) {
            var_s0->unk_004++;
            if ((var_s0->unk_002 == 1) && (var_s0->unk_006 < var_s0->unk_004)) {
                var_s0->unk_000 = 0;
            } else {
                func_8436A890(var_s0);
            }
        }
    }
    return 0;
}

Gfx* func_8436AC44(Gfx* arg0) {
    s32 i;
    s32 j;
    s32 k;
    unk_D_843ADA80_040* temp_s0;
    unk_D_843ADA80* var_s5;
    Vtx* var_s0;
    Vec3f sp184;
    UNUSED s32 pad[15];
    Mtx* temp_v0;
    Mtx sp100;
    Mtx spC0;
    f32 temp_fs1;
    s16 var_s3;
    f32 tmp;

    gDPLoadTextureBlock(arg0++, D_843920C0[0x1E], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    var_s5 = &D_843ADA80[0];
    for (i = 0; i < 50; i++, var_s5++) {
        if (var_s5->unk_000 == 1) {
            temp_s0 = &var_s5->unk_040[0];
            tmp = var_s5->unk_010;
            if (temp_s0->unk_0C.y > 0.0f) {
                temp_fs1 = (temp_s0->unk_08 * 360.0f) / 6.2831854820251465;
                temp_v0 = func_80005F5C(sizeof(Mtx) * 1);
                guTranslate(temp_v0, temp_s0->unk_0C.x, temp_s0->unk_0C.y, temp_s0->unk_0C.z);
                guRotateRPY(&sp100, 90.0f, temp_fs1, temp_fs1);
                guMtxCatL(&sp100, temp_v0, temp_v0);
                guScale(&spC0, tmp, tmp, tmp);
                guMtxCatL(&spC0, temp_v0, temp_v0);

                gSPMatrix(arg0++, temp_v0, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                gSPDisplayList(arg0++, D_84389AE0);
                gSPPopMatrix(arg0++, G_MTX_MODELVIEW);
            }

            var_s5->unk_020 = func_80005F5C(0x140);

            var_s0 = var_s5->unk_020;
            for (j = 0; j < 10; j++) {
                func_8436A808(temp_s0->unk_08, &sp184, temp_s0->unk_04 * tmp);

                var_s3 = temp_s0->unk_0C.y + sp184.y;
                if (var_s3 < 0) {
                    var_s3 = 0;
                }

                var_s0->v.ob[0] = temp_s0->unk_0C.x + sp184.x;
                var_s0->v.ob[1] = var_s3;
                var_s0->v.ob[2] = temp_s0->unk_0C.z + sp184.z;
                var_s0->v.cn[0] = var_s5->unk_00A.r;
                var_s0->v.cn[1] = var_s5->unk_00A.g;
                var_s0->v.cn[2] = var_s5->unk_00A.b;
                var_s0->v.cn[3] = temp_s0->unk_00;
                var_s0++;

                func_8436A808(temp_s0->unk_08 + 3.1415927f, &sp184, temp_s0->unk_04 * tmp);

                var_s3 = temp_s0->unk_0C.y + sp184.y;
                if (var_s3 < 0) {
                    var_s3 = 0;
                }

                var_s0->v.ob[0] = temp_s0->unk_0C.x + sp184.x;
                var_s0->v.ob[1] = var_s3;
                var_s0->v.ob[2] = temp_s0->unk_0C.z + sp184.z;
                var_s0->v.cn[0] = var_s5->unk_00A.r;
                var_s0->v.cn[1] = var_s5->unk_00A.g;
                var_s0->v.cn[2] = var_s5->unk_00A.b;
                var_s0->v.cn[3] = temp_s0->unk_00;
                var_s0++;

                temp_s0++;
            }

            var_s0 = var_s5->unk_020;

            gSPDisplayList(arg0++, D_84389A50);

            for (k = 0; k < 9; k++) {
                gSPVertex(arg0++, var_s0, 4, 0);
                gSP2Triangles(arg0++, 0, 2, 1, 0, 2, 3, 1, 0);
                var_s0 += 2;
            }
        }
    }

    return arg0;
}
