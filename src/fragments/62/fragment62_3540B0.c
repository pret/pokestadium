#include "fragment62.h"
#include "src/6A40.h"

static unk_D_843ACA10 D_843ACA10[4];

static Gfx D_84389A00[] = {
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

void func_843697F0(void) {
    s32 i;
    s32 j;
    unk_D_843ACA10* var_v0 = &D_843ACA10[0];
    unk_D_843ACA10_01C* var_a0;

    for (i = 0; i < 4; i++, var_v0++) {
        var_v0->unk_000 = 0;
        var_v0->unk_002 = 0;
        var_v0->unk_004 = 0;
        var_v0->unk_418 = 0.16f;

        var_a0 = &var_v0->unk_01C[0];
        for (j = 0; j < 15; j++, var_a0++) {
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

void func_84369950(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9,
                   f32 argA, f32 argB, f32 argC, s16 argD) {
    s32 i;
    s32 j;
    unk_D_843ACA10* var_v1;
    unk_D_843ACA10_01C* var_s0;
    Vec3f sp64;
    Vec3f sp58;

    sp64.x = arg0;
    sp64.y = arg1;
    sp64.z = arg2;
    sp58.x = arg3;
    sp58.y = arg4;
    sp58.z = arg5;

    var_v1 = &D_843ACA10[0];
    for (i = 0; i < 4; i++, var_v1++) {
        if (var_v1->unk_000 == 0) {
            var_v1->unk_000 = 1;
            var_v1->unk_002 = 0;
            var_v1->unk_004 = argD;
            var_v1->unk_008.r = arg6;
            var_v1->unk_008.g = arg7;
            var_v1->unk_008.b = arg8;
            var_v1->unk_010 = argA;

            if (func_8432FA0C() == 0xD) {
                var_v1->unk_418 = 0.08f;
                var_v1->unk_00C = argC * 0.5f;
            } else {
                var_v1->unk_418 = 0.16f;
                var_v1->unk_00C = argC;
            }

            var_v1->unk_018 = func_8432FD70(sp64, 2);
            if (arg3 < 0.0) {
                var_v1->unk_006 = -1;
            } else {
                var_v1->unk_006 = 1;
            }

            var_s0 = &var_v1->unk_01C[0];
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

void func_84369BF0(f32 arg0, Vec3f* arg1, f32 arg2) {
    UNUSED MtxF sp70;
    MtxF sp30;
    UNUSED s32 pad;

    guRotateF(sp30.mf, (arg0 * 360.0) / 6.2831854820251465, 1.0f, 0.0f, 0.0f);
    guMtxXFMF(sp30.mf, 0.0f, 0.0f, arg2, &arg1->x, &arg1->y, &arg1->z);
}

void func_84369C80(unk_D_843ACA10* arg0) {
    s32 i;
    unk_D_843ACA10_01C* var_s0 = &arg0->unk_01C[0];

    for (i = 0; i < 15; i++, var_s0++) {
        if (i == 0) {
            var_s0->unk_24 = var_s0->unk_04;
            var_s0->unk_28 = var_s0->unk_08;

            var_s0->unk_2C = var_s0->unk_0C;
            var_s0->unk_38 = var_s0->unk_18;

            var_s0->unk_0C.x += var_s0->unk_18.x;
            var_s0->unk_0C.y += var_s0->unk_18.y;
            var_s0->unk_0C.z += var_s0->unk_18.z;

            var_s0->unk_08 += arg0->unk_010;
            if (arg0->unk_006 > 0) {
                var_s0->unk_18.x += 0.4;
                if (var_s0->unk_18.x > 20.0) {
                    var_s0->unk_18.x = 20.0f;
                }
            } else {
                var_s0->unk_18.x -= 0.4;
                if (var_s0->unk_18.x < -20.0) {
                    var_s0->unk_18.x = -20.0f;
                }
            }

            func_8432FDF0(arg0->unk_018, var_s0->unk_0C);

            var_s0->unk_04 += 2.0;
            if (arg0->unk_00C < var_s0->unk_04) {
                var_s0->unk_04 = arg0->unk_00C;
            }
        } else {
            var_s0->unk_24 = var_s0->unk_04;
            var_s0->unk_28 = var_s0->unk_08;

            var_s0->unk_2C = var_s0->unk_0C;
            var_s0->unk_38 = var_s0->unk_18;

            var_s0->unk_0C = var_s0[-1].unk_2C;
            var_s0->unk_08 = var_s0[-1].unk_28;
            var_s0->unk_18 = var_s0[-1].unk_38;
            var_s0->unk_04 = var_s0[-1].unk_24;
        }
    }
}

s32 func_84369F0C(void) {
    s32 i;
    unk_D_843ACA10* var_s0 = &D_843ACA10[0];

    for (i = 0; i < 4; i++, var_s0++) {
        if (var_s0->unk_000 == 1) {
            var_s0->unk_002 += 1;
            if (var_s0->unk_004 < var_s0->unk_002) {
                var_s0->unk_000 = 0;
            } else {
                func_84369C80(var_s0);
            }
        }
    }

    return 0;
}

Gfx* func_84369FA0(Gfx* arg0) {
    s32 i;
    s32 j;
    s32 k;
    unk_D_843ACA10_01C* temp_s0;
    unk_D_843ACA10* var_s5;
    Vtx* var_s0;
    Vec3f sp154;
    UNUSED s32 pad[15];
    Mtx* temp_v0;
    Mtx sp100;
    Mtx spC0;
    s16 var_s3;

    var_s5 = &D_843ACA10[0];
    for (i = 0; i < 4; i++, var_s5++) {
        if (var_s5->unk_000 == 1) {
            temp_s0 = &var_s5->unk_01C[0];
            if (temp_s0->unk_0C.y > 0.0f) {
                temp_v0 = func_80005F5C(sizeof(Mtx) * 1);
                guTranslate(temp_v0, temp_s0->unk_0C.x, temp_s0->unk_0C.y, temp_s0->unk_0C.z);
                guRotateRPY(&sp100, (temp_s0->unk_08 * -360.0f * var_s5->unk_006) / 6.2831854820251465,
                            0x5A - (var_s5->unk_006 * 0x5A), 0.0f);
                guMtxCatL(&sp100, temp_v0, temp_v0);
                guScale(&spC0, var_s5->unk_418, var_s5->unk_418, var_s5->unk_418);
                guMtxCatL(&spC0, temp_v0, temp_v0);

                gSPMatrix(arg0++, temp_v0, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                gSPDisplayList(arg0++, D_8438A980);
                gSPPopMatrix(arg0++, G_MTX_MODELVIEW);
            }

            var_s5->unk_014 = func_80005F5C(sizeof(Vtx) * 30);

            var_s0 = var_s5->unk_014;
            for (j = 0; j < 15; j++) {
                func_84369BF0(temp_s0->unk_08, &sp154, temp_s0->unk_04);

                var_s3 = temp_s0->unk_0C.y + sp154.y;
                if (var_s3 < 0) {
                    var_s3 = 0;
                }

                var_s0->v.ob[0] = temp_s0->unk_0C.x + sp154.x;
                var_s0->v.ob[1] = var_s3;
                var_s0->v.ob[2] = temp_s0->unk_0C.z + sp154.z;
                var_s0->v.cn[0] = var_s5->unk_008.r;
                var_s0->v.cn[1] = var_s5->unk_008.g;
                var_s0->v.cn[2] = var_s5->unk_008.b;
                var_s0->v.cn[3] = temp_s0->unk_00;
                var_s0++;

                func_84369BF0(temp_s0->unk_08 + 3.1415927f, &sp154, temp_s0->unk_04);

                var_s3 = temp_s0->unk_0C.y + sp154.y;
                if (var_s3 < 0) {
                    var_s3 = 0;
                }

                var_s0->v.ob[0] = temp_s0->unk_0C.x + sp154.x;
                var_s0->v.ob[1] = var_s3;
                var_s0->v.ob[2] = temp_s0->unk_0C.z + sp154.z;
                var_s0->v.cn[0] = var_s5->unk_008.r;
                var_s0->v.cn[1] = var_s5->unk_008.g;
                var_s0->v.cn[2] = var_s5->unk_008.b;
                var_s0->v.cn[3] = temp_s0->unk_00;
                var_s0++;

                temp_s0++;
            }

            var_s0 = var_s5->unk_014;

            gSPDisplayList(arg0++, D_84389A00);

            for (k = 0; k < 14; k++) {
                gSPVertex(arg0++, var_s0, 4, 0);
                gSP2Triangles(arg0++, 0, 2, 1, 0, 2, 3, 1, 0);
                var_s0 += 2;
            }
        }
    }

    return arg0;
}
