#include "fragment62.h"
#include "src/6A40.h"

static unk_D_843AA880 D_843AA880[4];

static Vtx D_843898B0[] = {
    VTX(-30, 0, -20, 2048, 0, 0xFF, 0xFF, 0xFF, 0xC8),
    VTX(10, 0, -20, 0, 0, 0xFF, 0xFF, 0xFF, 0xC8),
    VTX(-30, 0, 20, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xC8),
    VTX(10, 0, 20, 0, 2048, 0xFF, 0xFF, 0xFF, 0xC8),
};
static Gfx D_843898F0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
    gsDPSetCombineMode(G_CC_BLENDIA, G_CC_BLENDIA),
    gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsSPVertex(0x843898B0, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSPEndDisplayList(),
};
static Gfx D_84389958[] = {
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

void func_84367CB0(void) {
    s32 i;
    s32 j;
    f32 temp_fa0;
    unk_D_843AA880* var_a2;
    unk_D_843AA880_034* var_v0;

    temp_fa0 = func_8432FCD4() * 0.75f;
    var_a2 = &D_843AA880[0];

    for (i = 0; i < 4; i++, var_a2++) {
        var_a2->unk_000 = 0;
        var_a2->unk_002 = 0;
        var_a2->unk_004 = 0;
        var_a2->unk_00C = temp_fa0;

        var_v0 = &var_a2->unk_034[0];
        for (j = 0; j < 15; j++, var_v0++) {
            var_v0->unk_00 = 0;
            var_v0->unk_04 = 1.0f;
            var_v0->unk_08 = 0.0f;
            var_v0->unk_0C.z = var_v0->unk_0C.y = var_v0->unk_0C.x = 0.0f;
            var_v0->unk_18.z = var_v0->unk_18.y = var_v0->unk_18.x = 0.0f;
        }
    }
}

void func_84367E2C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9,
                   f32 argA, f32 argB, f32 argC, s16 argD) {
    unk_D_843AA880* var_v1;
    unk_D_843AA880_034* var_s0;
    s32 i;
    s32 j;
    Vec3f sp64;
    Vec3f sp58;

    sp64.x = arg0;
    sp64.y = arg1;
    sp64.z = arg2;
    var_v1 = &D_843AA880[0];

    for (i = 0; i < 4; i++, var_v1++) {
        if (var_v1->unk_000 == 0) {
            f32 tmp = var_v1->unk_00C;

            var_v1->unk_000 = 1;
            var_v1->unk_002 = 0;

            var_v1->unk_004 = argD;
            var_v1->unk_008.r = arg6;
            var_v1->unk_008.g = arg7;
            var_v1->unk_008.b = arg8;
            var_v1->unk_01C = sp64;
            var_v1->unk_010 = argC;
            var_v1->unk_014 = argA;

            sp58.x = arg3;
            sp58.y = arg4 * tmp;
            sp58.z = arg5 * tmp;

            if (arg3 < 0.0) {
                var_v1->unk_006 = -1;
            } else {
                var_v1->unk_006 = 1;
            }

            var_s0 = &var_v1->unk_034[0];
            for (j = 0; j < 15; j++, var_s0++) {
                var_s0->unk_00 = (arg9 * (0xE - j)) / 15;
                var_s0->unk_04 = argB;
                var_s0->unk_08 = (RAND(120) * 6.2831855f) / 120.0;
                var_s0->unk_0C = sp64;
                var_s0->unk_18 = sp58;
            }
            break;
        }
    }
}

void func_84368080(f32 arg0, Vec3f* arg1, f32 arg2, f32 arg3) {
    MtxF spB0;
    MtxF sp70;
    MtxF sp30;
    UNUSED s32 pad;

    guScaleF(sp30.mf, arg3, arg3, arg3);
    guRotateF(sp70.mf, (arg0 * 360.0) / 6.2831854820251465, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp30.mf, sp70.mf, spB0.mf);
    guMtxXFMF(spB0.mf, 0.0f, 0.0f, arg2, &arg1->x, &arg1->y, &arg1->z);
}

void func_84368140(unk_D_843AA880* arg0) {
    unk_D_843AA880_034* var_v0 = &arg0->unk_034[0];
    s32 i;
    f32 temp_fa0;
    f32 temp_fa1;

    for (i = 0; i < 15; i++, var_v0++) {
        if (i == 0) {
            var_v0->unk_24 = var_v0->unk_04;
            var_v0->unk_28 = var_v0->unk_08;
            var_v0->unk_2C = var_v0->unk_0C;
            var_v0->unk_38 = var_v0->unk_18;

            var_v0->unk_0C.x += var_v0->unk_18.x;
            var_v0->unk_0C.y += var_v0->unk_18.y;
            var_v0->unk_0C.z += var_v0->unk_18.z;

            var_v0->unk_08 += arg0->unk_014;
            if (arg0->unk_006 < 0) {
                var_v0->unk_18.x += 1.5;
                if (var_v0->unk_18.x > 20.0) {
                    var_v0->unk_18.x = 20.0f;
                }
            } else {
                var_v0->unk_18.x -= 1.5;
                if (var_v0->unk_18.x < -20.0) {
                    var_v0->unk_18.x = -20.0f;
                }
            }

            if (arg0->unk_002 < 0xF) {
                temp_fa0 = ((0xF - arg0->unk_002) * 0.03) / 15.0;
                temp_fa1 = (arg0->unk_002 * 0.15) / 15.0;
                var_v0->unk_18.y += (arg0->unk_01C.y - var_v0->unk_0C.y) * temp_fa0;
                var_v0->unk_18.z += (arg0->unk_01C.z - var_v0->unk_0C.z) * temp_fa0;
                var_v0->unk_0C.y += (arg0->unk_01C.y - var_v0->unk_0C.y) * temp_fa1;
                var_v0->unk_0C.z += (arg0->unk_01C.z - var_v0->unk_0C.z) * temp_fa1;
            } else {
                var_v0->unk_18.y += (arg0->unk_01C.y - var_v0->unk_0C.y) * 0.03;
                var_v0->unk_18.z += (arg0->unk_01C.z - var_v0->unk_0C.z) * 0.03;
                var_v0->unk_0C.y += (arg0->unk_01C.y - var_v0->unk_0C.y) * 0.15;
                var_v0->unk_0C.z += (arg0->unk_01C.z - var_v0->unk_0C.z) * 0.15;
            }

            var_v0->unk_04 += 2.0;
            if (arg0->unk_010 < var_v0->unk_04) {
                var_v0->unk_04 = arg0->unk_010;
            }
        } else {
            var_v0->unk_24 = var_v0->unk_04;
            var_v0->unk_28 = var_v0->unk_08;

            var_v0->unk_2C = var_v0->unk_0C;
            var_v0->unk_38 = var_v0->unk_18;

            var_v0->unk_0C = var_v0[-1].unk_2C;
            var_v0->unk_08 = var_v0[-1].unk_28;
            var_v0->unk_18 = var_v0[-1].unk_38;
            var_v0->unk_04 = var_v0[-1].unk_24;
        }
    }
}

s32 func_843684CC(void) {
    s32 i;
    unk_D_843AA880* var_s0 = &D_843AA880[0];

    for (i = 0; i < 4; i++, var_s0++) {
        if (var_s0->unk_000 == 1) {
            var_s0->unk_002 += 1;
            if (var_s0->unk_004 < var_s0->unk_002) {
                var_s0->unk_000 = 0;
            } else {
                func_84368140(var_s0);
            }
        }
    }

    return 0;
}

Gfx* func_84368560(Gfx* arg0) {
    s32 i;
    s32 j;
    s32 k;
    unk_D_843AA880* var_s4;
    unk_D_843AA880_034* temp_s0;
    Mtx* temp_v0;
    Vec3f sp134;
    Vtx* var_s0;
    Mtx spF0;
    Mtx spB0;
    s16 var_s3;
    UNUSED s32 pad;

    gDPPipeSync(arg0++);
    gDPLoadTextureBlock_4b(arg0++, D_843920C0[0x49], G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    var_s4 = &D_843AA880[0];
    for (i = 0; i < 4; i++, var_s4++) {
        if (var_s4->unk_000 == 1) {
            guScale(&spB0, var_s4->unk_00C, var_s4->unk_00C, var_s4->unk_00C);
            temp_s0 = &var_s4->unk_034[0];

            if (temp_s0->unk_0C.y > 0.0f) {
                temp_v0 = func_80005F5C(sizeof(Mtx) * 1);
                guTranslate(temp_v0, temp_s0->unk_0C.x, temp_s0->unk_0C.y, temp_s0->unk_0C.z);
                guRotateRPY(&spF0, (temp_s0->unk_08 * -360.0f * var_s4->unk_006) / 6.2831854820251465,
                            (var_s4->unk_006 * 0x5A) + 0x5A, 0.0f);
                guMtxCatL(&spF0, temp_v0, temp_v0);
                guMtxCatL(&spB0, temp_v0, temp_v0);

                gSPMatrix(arg0++, temp_v0, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                gSPDisplayList(arg0++, D_843898F0);
                gSPPopMatrix(arg0++, G_MTX_MODELVIEW);
            }

            var_s4->unk_018 = func_80005F5C(sizeof(Vtx) * 30);
            var_s0 = var_s4->unk_018;

            for (j = 0; j < 15; j++) {
                func_84368080(temp_s0->unk_08, &sp134, temp_s0->unk_04, var_s4->unk_00C);
                var_s3 = temp_s0->unk_0C.y + sp134.y;
                if (var_s3 < 0) {
                    var_s3 = 0;
                }

                var_s0->v.ob[0] = temp_s0->unk_0C.x + sp134.x;
                var_s0->v.ob[1] = var_s3;
                var_s0->v.ob[2] = temp_s0->unk_0C.z + sp134.z;
                var_s0->v.cn[0] = var_s4->unk_008.r;
                var_s0->v.cn[1] = var_s4->unk_008.g;
                var_s0->v.cn[2] = var_s4->unk_008.b;
                var_s0->v.cn[3] = temp_s0->unk_00;
                var_s0++;

                func_84368080(temp_s0->unk_08 + M_PI_F, &sp134, temp_s0->unk_04, var_s4->unk_00C);

                var_s3 = temp_s0->unk_0C.y + sp134.y;
                if (var_s3 < 0) {
                    var_s3 = 0;
                }
                var_s0->v.ob[0] = temp_s0->unk_0C.x + sp134.x;
                var_s0->v.ob[1] = var_s3;
                var_s0->v.ob[2] = temp_s0->unk_0C.z + sp134.z;
                var_s0->v.cn[0] = var_s4->unk_008.r;
                var_s0->v.cn[1] = var_s4->unk_008.g;
                var_s0->v.cn[2] = var_s4->unk_008.b;
                var_s0->v.cn[3] = temp_s0->unk_00;
                var_s0++;

                temp_s0++;
            }

            var_s0 = var_s4->unk_018;

            gSPDisplayList(arg0++, D_84389958);

            for (k = 0; k < 14; k++) {
                gSPVertex(arg0++, var_s0, 4, 0);
                gSP2Triangles(arg0++, 0, 2, 1, 0, 2, 3, 1, 0);
                var_s0 += 2;
            }
        }
    }

    return arg0;
}
