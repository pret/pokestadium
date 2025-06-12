#include "fragment62.h"
#include "src/32D10.h"
#include "src/6A40.h"

static unk_D_843C2C00 D_843C2C00[4];

static Gfx D_84389C70[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

void func_8436BE70(void) {
    s32 i;
    s32 j;
    unk_D_843C2C00* var_v0 = &D_843C2C00[0];
    unk_D_843C2C00_0B0* var_a0;

    for (i = 0; i < 4; i++, var_v0++) {
        var_v0->unk_000 = 0;
        var_v0->unk_002 = 0;
        var_v0->unk_004 = 0;

        var_a0 = &var_v0->unk_0B0[0];
        for (j = 0; j < 10; j++, var_a0++) {
            var_a0->unk_00 = 0;
            var_a0->unk_04 = 0;
            var_a0->unk_08 = 1.0f;
            var_a0->unk_0C = 0.0f;
            var_a0->unk_10.x = 0.0f;
            var_a0->unk_10.y = 0.0f;
            var_a0->unk_10.z = 0.0f;
            var_a0->unk_1C = 0.0f;
            var_a0->unk_20 = 0.0f;
            var_a0->unk_24 = 0.0f;
        }
    }
}

void func_8436BFB8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9,
                   f32 argA, s16 argB, s32 argC, s32 argD, s16 argE, s16 argF, s16 arg10, s16 arg11, s16 arg12,
                   s16 arg13, s16 arg14, s16 arg15, unk_D_843C2C00_024* arg16, unk_D_843C2C00_024* arg17, u8 arg18,
                   u8 arg19, u8 arg1A, u8 arg1B, u8 arg1C, u8 arg1D, u8 arg1E, u8 arg1F, u8 arg20, u8 arg21, u8 arg22,
                   u8 arg23, u8 arg24) {
    unk_D_843C2C00* var_v0;
    unk_D_843C2C00_0B0* var_a0;
    s32 i;
    s32 j;
    Vec3f sp3C;
    Vec3f sp30;

    sp3C.x = arg0;
    sp3C.y = arg1;
    sp3C.z = arg2;

    sp30.x = arg3;
    sp30.y = arg4;
    sp30.z = arg5;

    var_v0 = &D_843C2C00[0];
    for (i = 0; i < 4; i++, var_v0++) {
        if (var_v0->unk_000 == 0) {
            var_v0->unk_000 = 1;
            var_v0->unk_002 = 0;
            var_v0->unk_004 = argB;
            var_v0->unk_008 = argA;
            var_v0->unk_010 = arg7;
            var_v0->unk_014 = arg8;
            var_v0->unk_00C = arg6;
            var_v0->unk_01C = argC;
            var_v0->unk_020 = argD;

            var_v0->unk_064.unk_00 = 0;
            var_v0->unk_064.unk_02 = 0;
            var_v0->unk_070.unk_00 = 0;
            var_v0->unk_070.unk_02 = 0;

            var_v0->unk_064.unk_04 = argE;
            var_v0->unk_064.unk_06 = argF;
            var_v0->unk_070.unk_04 = arg12;
            var_v0->unk_070.unk_06 = arg13;

            var_v0->unk_064.unk_08 = arg10;
            var_v0->unk_064.unk_0A = arg11;
            var_v0->unk_070.unk_08 = arg14;
            var_v0->unk_070.unk_0A = arg15;

            var_v0->unk_024 = *arg16;
            var_v0->unk_044 = *arg17;

            var_v0->unk_07C.unk_00.r = arg18;
            var_v0->unk_07C.unk_00.g = arg19;
            var_v0->unk_07C.unk_00.b = arg1A;
            var_v0->unk_07C.unk_00.a = arg1B;

            var_v0->unk_07C.unk_04 = arg1C;

            var_v0->unk_081.unk_00.r = arg1D;
            var_v0->unk_081.unk_00.g = arg1E;
            var_v0->unk_081.unk_00.b = arg1F;
            var_v0->unk_081.unk_00.a = arg20;

            var_v0->unk_086.r = arg21;
            var_v0->unk_086.g = arg22;
            var_v0->unk_086.b = arg23;
            var_v0->unk_086.a = arg24;

            var_v0->unk_08C = 1.0f;
            var_v0->unk_090 = 1.0f;
            var_v0->unk_094 = 0x41;

            var_a0 = &var_v0->unk_0B0[0];
            for (j = 0; j < 10; j++, var_a0++) {
                var_a0->unk_00 = j;
                var_a0->unk_04 = 0xFF;
                var_a0->unk_08 = arg9;
                var_a0->unk_0C = 0.0f;
                var_a0->unk_10 = sp3C;
                var_a0->unk_1C = sp30.x * arg8;
                var_a0->unk_20 = sp30.y * arg8;
                var_a0->unk_24 = sp30.z * arg8;
            }
            break;
        }
    }
}

void func_8436C344(f32 arg0, Vec3f* arg1, f32 arg2) {
    UNUSED MtxF sp70;
    MtxF sp30;
    UNUSED s32 pad;

    guRotateF(sp30.mf, (360.0f * arg0) / 6.2831855f, 1.0f, 0.0f, 0.0f);
    guMtxXFMF(sp30.mf, 0.0f, 0.0f, arg2, &arg1->x, &arg1->y, &arg1->z);
}

void func_8436C3CC(unk_D_843C2C00* arg0) {
    unk_D_843C2C00_0B0* var_v0;
    UNUSED s32 pad;
    s32 i;
    Vec3f sp58;
    Vec3f sp4C;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 var_fv0;
    f32 var_fv1;

    func_8432FBBC(&sp58);
    func_8432FC14(&sp4C);
    if (sp4C.y > 200.0f) {
        sp4C.y = 200.0f;
    }

    var_v0 = &arg0->unk_0B0[0];
    for (i = 0; i < 10; i++, var_v0++) {
        if (arg0->unk_002 < arg0->unk_004) {
            temp_fa1 = ((f32)arg0->unk_002 * i) / 9.0f;
            var_fv0 = arg0->unk_004 - 1;
            var_fv1 = temp_fa1 / var_fv0;
            temp_fa0 = 1.0f - var_fv1;
        } else {
            temp_fa1 = i;

            var_fv1 = temp_fa1 / 9.0f;
            temp_fa0 = 1.0f - var_fv1;
        }

        var_v0->unk_10.x = (sp58.x * temp_fa0) + (sp4C.x * var_fv1);
        var_v0->unk_10.y = (sp58.y * temp_fa0) + (sp4C.y * var_fv1);
        var_v0->unk_10.z = (sp58.z * temp_fa0) + (sp4C.z * var_fv1);

        var_v0->unk_0C += arg0->unk_00C;

        if (i == 0) {
            var_v0->unk_08 = 1.0f;
        } else if (i == 9) {
            if (arg0->unk_002 < 5) {
                var_v0->unk_08 = 1.0f;
            } else {
                var_v0->unk_08 += 0.5f;
                if (arg0->unk_008 * 1.0f < var_v0->unk_08) {
                    var_v0->unk_08 = arg0->unk_008 * 1.0f;
                }
            }
        } else if (i == 1) {
            var_v0->unk_08 += arg0->unk_010;
            if (arg0->unk_008 * 0.5f < var_v0->unk_08) {
                var_v0->unk_08 = arg0->unk_008 * 0.5f;
            }
        } else if (i == 2) {
            var_v0->unk_08 += arg0->unk_010;
            if (arg0->unk_008 * 0.75f < var_v0->unk_08) {
                var_v0->unk_08 = arg0->unk_008 * 0.75f;
            }
        } else {
            var_v0->unk_08 += arg0->unk_010;
            if (arg0->unk_008 * 1.0f < var_v0->unk_08) {
                var_v0->unk_08 = arg0->unk_008 * 1.0f;
            }
        }
    }
}

s32 func_8436C62C(void) {
    s32 i;
    unk_D_843C2C00* var_s0 = &D_843C2C00[0];

    for (i = 0; i < 4; i++, var_s0++) {
        if (var_s0->unk_000 == 1) {
            var_s0->unk_002 += 1;
            func_8436C3CC(var_s0);
        }
    }

    return 0;
}

#define TRIANGLES(gfx)                                                                                        \
    {                                                                                                         \
        s32 j, k;                                                                                             \
        for (j = 0; j < 2; j++)                                                                               \
            for (k = 0; k < 4; k++)                                                                           \
                gSP2Triangles(gfx++, (j * 4) + k, (j * 4) + (k + 9), (j * 4) + (k + 1), 0, (j * 4) + (k + 9), \
                              (j * 4) + (k + 10), (j * 4) + (k + 1), 0);                                      \
    }

#ifdef NON_MATCHING
Gfx* func_8436C6A4(Gfx* arg0, unk_D_843C2C00* arg1, s16 arg2, s16 arg3) {
    s32 i;
    s32 j;
    Vtx* sp44;
    s32 k;
    unk_D_84389CE0* temp_v0;
    unk_D_84389CE0* temp_v1;
    u8 a1;
    u8 a2;
    s16 tmp;

    temp_v1 = &arg1->unk_07C;
    temp_v0 = &arg1->unk_081;

    if (func_8432E8B0() == 1) {
        if (arg1->unk_094 >= arg1->unk_002) {
            arg1->unk_002 = arg1->unk_094 + 1;
        }
    }

    if (arg3 == 0) {
        if (arg1->unk_094 < arg1->unk_002) {
            tmp = arg1->unk_002 - arg1->unk_094;

            arg1->unk_08C = 1.0f - tmp * 0.1f;
            arg1->unk_090 = 1.0f - tmp * 0.1f;

            if (tmp * 0.1f > 1.0f) {
                arg1->unk_08C = 0.0f;
            }

            if (arg1->unk_090 < 0.0f) {
                arg1->unk_090 = 0.0f;
            }
        }
    }

    a1 = temp_v1->unk_00.a * arg1->unk_08C;
    a2 = temp_v0->unk_00.a * arg1->unk_090;

    gDPSetPrimColor(arg0++, 0, temp_v1->unk_04, temp_v1->unk_00.r, temp_v1->unk_00.g, temp_v1->unk_00.b, a1);
    gDPSetEnvColor(arg0++, temp_v0->unk_00.r, temp_v0->unk_00.g, temp_v0->unk_00.b, a2);

    sp44 = arg1->unk_018;
    for (i = 0; i < 9; i++) {
        gSPVertex(arg0++, sp44, 18, 0);
        TRIANGLES(arg0);
        sp44 += 9;
    }

    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/62/fragment62_356730/func_8436C6A4.s")
#endif

Gfx* func_8436CB60(Gfx* arg0, unk_D_843C2C00* arg1) {
    unk_D_843C2C00_064* ptr;

    ptr = &arg1->unk_064;
    gDPLoadTextureTile_4b(arg0++, D_843920C0[arg1->unk_01C], G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, ptr->unk_08, ptr->unk_0A);
    gDPSetTileSize(arg0++, G_TX_RENDERTILE, ptr->unk_00, ptr->unk_02, (ptr->unk_00 + 31) << 2, (ptr->unk_02 + 31) << 2);

    ptr = &arg1->unk_070;
    gDPLoadMultiTile_4b(arg0++, D_843920C0[arg1->unk_020], 0x0100, 1, G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, ptr->unk_08, ptr->unk_0A);
    gDPSetTileSize(arg0++, 1, ptr->unk_00, ptr->unk_02, (ptr->unk_00 + 31) << 2, (ptr->unk_02 + 31) << 2);

    return arg0;
}

Gfx* func_8436CE34(Gfx* arg0) {
    s32 i;
    s32 j;
    s32 k;
    unk_D_843C2C00* var_fp;
    unk_D_843C2C00_0B0* var_s2;
    Vec3f sp100;
    Vec3f spF4;
    Vec3f spE8;
    Vec3f spDC;
    unk_D_86002F34_00C* spD8;
    UNUSED s32 pad[3];
    Vtx* var_s0;

    spD8 = func_8432FD64();
    var_fp = &D_843C2C00[0];

    for (i = 0; i < 4; i++, var_fp++) {
        if (var_fp->unk_000 == 1) {
            if (func_800325AC() == 0) {
                var_fp->unk_064.unk_00 += var_fp->unk_064.unk_04;
                var_fp->unk_064.unk_02 += var_fp->unk_064.unk_06;
                var_fp->unk_070.unk_00 += var_fp->unk_070.unk_04;
                var_fp->unk_070.unk_02 += var_fp->unk_070.unk_06;
            }

            var_s2 = &var_fp->unk_0B0[0];

            var_fp->unk_018 = func_80005F5C(sizeof(Vtx) * 90);

            var_s0 = var_fp->unk_018;
            for (j = 0; j < 10; j++, var_s2++) {
                for (k = 0; k < 9; k++) {
                    func_8436C344(var_s2->unk_0C + ((2.0f * (k % 8) * 3.1415927f) / 8), &sp100, var_s2->unk_08);
                    var_s0->v.ob[0] = var_s2->unk_10.x + sp100.x;
                    var_s0->v.ob[1] = var_s2->unk_10.y + sp100.y;
                    var_s0->v.ob[2] = var_s2->unk_10.z + sp100.z;

                    var_s0->v.tc[0] = (k * 0x400) / 8;
                    var_s0->v.tc[1] = (j * 0x400) / 10;

                    var_s0->v.cn[0] = 0;
                    var_s0->v.cn[1] = 0;
                    var_s0->v.cn[2] = 0;
                    var_s0->v.cn[3] = 0;

                    var_s0++;
                }
            }

            if ((var_fp->unk_086.r | var_fp->unk_086.g | var_fp->unk_086.b | var_fp->unk_086.a) != 0) {
                spE8 = var_fp->unk_0B0[9].unk_10;
                spF4 = var_fp->unk_0B0[0].unk_10;
                spDC.x = spD8->unk_60.eye.x;
                spDC.y = spD8->unk_60.eye.y;
                spDC.z = spD8->unk_60.eye.z;
                arg0 = func_84367660(arg0, &spF4, &spE8, &spDC, 20.0f, var_fp->unk_086.r, var_fp->unk_086.g,
                                     var_fp->unk_086.b, var_fp->unk_086.a * var_fp->unk_08C);
            }

            gSPDisplayList(arg0++, D_84389C70);

            func_800327CC(
                arg0++, var_fp->unk_024.unk_00, var_fp->unk_024.unk_04, var_fp->unk_024.unk_08, var_fp->unk_024.unk_0C,
                var_fp->unk_024.unk_10, var_fp->unk_024.unk_14, var_fp->unk_024.unk_18, var_fp->unk_024.unk_1C,
                var_fp->unk_044.unk_00, var_fp->unk_044.unk_04, var_fp->unk_044.unk_08, var_fp->unk_044.unk_0C,
                var_fp->unk_044.unk_10, var_fp->unk_044.unk_14, var_fp->unk_044.unk_18, var_fp->unk_044.unk_1C);

            arg0 = func_8436CB60(arg0, var_fp);

            gDPSetPrimColor(arg0++, 0, var_fp->unk_07C.unk_04, var_fp->unk_07C.unk_00.r, var_fp->unk_07C.unk_00.g,
                            var_fp->unk_07C.unk_00.b, var_fp->unk_07C.unk_00.a);
            gDPSetEnvColor(arg0++, var_fp->unk_081.unk_00.r, var_fp->unk_081.unk_00.g, var_fp->unk_081.unk_00.b,
                           var_fp->unk_081.unk_00.a);
            gSPClearGeometryMode(arg0++, G_CULL_BOTH);
            gSPSetGeometryMode(arg0++, G_CULL_FRONT);
            gDPPipeSync(arg0++);

            arg0 = func_8436C6A4(arg0, var_fp, i, 0);

            gSPClearGeometryMode(arg0++, G_CULL_BOTH);
            gSPSetGeometryMode(arg0++, G_CULL_BACK);
            gDPPipeSync(arg0++);

            arg0 = func_8436C6A4(arg0, var_fp, i, 1);
        }
    }

    return arg0;
}
