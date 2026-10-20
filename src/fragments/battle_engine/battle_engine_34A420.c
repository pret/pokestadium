#include "battle_engine.h"
#include "src/gallery.h"
#include "src/gfx_buffer.h"
#include "src/math_util.h"
#include "include/math.h"

typedef struct Strip400State {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ s16 unk_2A;
    /* 0x2C */ Vtx* unk_2C;
    /* 0x30 */ Color_RGB8 unk_30;
    /* 0x33 */ Color_RGB8 unk_33;
} Strip400State; // size = 0x38

typedef struct Strip400Node {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} Strip400Node; // size = 0x10

static Strip400State sTrailState;
static Strip400Node sTrailPoints[400];
static s32 pad_D_84398F48[2];
static Radial20 D_84398F50[10];

static Gfx D_84389060[] = {
    gsSPEndDisplayList(),
};

static u32 D_84389068[] = {
    0x08080808, 0x08080808, 0x0D0D0D0D, 0x0D0D0D0D, 0x2F2F2F2F, 0x2F2F2F2F, 0x6F6F6F6F, 0x6F6F6F6F,
    0x9F9F9F9F, 0x9F9F9F9F, 0xDFDFDFDF, 0xDFDFDFDF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xDFDFDFDF, 0xDFDFDFDF, 0x9F9F9F9F, 0x9F9F9F9F,
    0x6F6F6F6F, 0x6F6F6F6F, 0x2F2F2F2F, 0x2F2F2F2F, 0x0D0D0D0D, 0x0D0D0D0D, 0x08080808, 0x08080808,
};

void Radial20_Init(f32 arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9) {
    Strip400State* ptr1 = &sTrailState;
    Strip400Node* ptr2;
    s32 i;

    ptr1->unk_00 = 0;
    ptr1->unk_02 = 0;
    ptr1->unk_04 = 0;
    ptr1->unk_06 = 0x46;
    ptr1->unk_08 = arg0;
    ptr1->unk_0C = arg1;
    ptr1->unk_10 = arg2;
    ptr1->unk_14 = arg3 * 40.0;
    ptr1->unk_18 = arg3 * 20.0;
    ptr1->unk_1C = 0.0f;
    ptr1->unk_20 = arg3;
    ptr1->unk_24 = 1.0f;
    ptr1->unk_28 = 0;
    ptr1->unk_2A = 0;
    ptr1->unk_30.r = arg4;
    ptr1->unk_30.g = arg5;
    ptr1->unk_30.b = arg6;
    ptr1->unk_33.r = arg7;
    ptr1->unk_33.g = arg8;
    ptr1->unk_33.b = arg9;

    ptr2 = &sTrailPoints[0];
    for (i = 0; i < 400; i++, ptr2++) {
        ptr2->unk_00 = arg0;
        ptr2->unk_04 = arg1;
        ptr2->unk_08 = arg2;
        ptr2->unk_0C = ptr1->unk_14;
    }
}

f32 Strip400_GetTailFadeRatio(void) {
    Strip400State* ptr = &sTrailState;
    f32 tmp;
    s32 tmp2 = ptr->unk_00;

    if (tmp2 < (ptr->unk_06 - 0x34)) {
        return 1.0f;
    }

    if (ptr->unk_18 == 0.0f) {
        return 1.0f;
    }

    tmp = (sTrailPoints[ptr->unk_06 * 0].unk_0C * 2.0f) / (ptr->unk_14 + ptr->unk_18);
    return tmp;
}

s32 Radial20_Update(void) {
    s32 i;
    f32 spB8;
    f32 temp_fs0_2;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_ft0;
    f32 var_fs1;
    Strip400Node* var_s0;
    Strip400State* ptr = &sTrailState;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 tmp2;
    s32 tmp00;
    Vec3f sp7C;

    ptr->unk_00++;
    if (ptr->unk_06 < ptr->unk_00) {
        return -1;
    }

    if ((ptr->unk_06 - 0x28) < ptr->unk_00) {
        ptr->unk_00 = ptr->unk_06 - 0x34;
        ptr->unk_02++;
        if (ptr->unk_02 >= 0x15) {
            return -1;
        }
    } else if (ptr->unk_00 < 0x1E) {
        ptr->unk_2A += 10;
        if (ptr->unk_2A > 0xC8) {
            ptr->unk_2A = 0xC8;
        }
    }

    BattleAnim_GetCurrentOwnerBonePosition(&sp7C);
    sp98 = sp7C.x;
    sp94 = sp7C.y;
    sp90 = sp7C.z;

    ptr->unk_28 += 6;
    if (ptr->unk_28 > 0xC8) {
        ptr->unk_28 = 0xC8;
    }

    if (((ptr->unk_06 - 0x34) < ptr->unk_00) && (ptr->unk_00 < (ptr->unk_06 - 0x28))) {
        ptr->unk_24 -= 0.1;
        if (ptr->unk_24 < 0.25) {
            ptr->unk_24 = 0.25f;
        }
    }

    var_s0 = &sTrailPoints[0];

    for (i = 0; i < ptr->unk_28; i++) {
        tmp00 = ptr->unk_00;

        if ((ptr->unk_06 - 0x28) < tmp00) {
            var_s0->unk_0C -= 6.0;
            if (var_s0->unk_0C < ptr->unk_18) {
                var_s0->unk_0C = ptr->unk_18;
            }
            // M_PI * 80
            var_fs1 = __sinf((((ptr->unk_00 + i) % 200) * 251.327419281005859) / 200.0) * 0.1;
        } else if ((ptr->unk_06 - 0x2D) < tmp00) {
            var_fs1 = __sinf((((ptr->unk_00 + i) % 200) * 251.327419281005859) / 200.0) + 2.0;
            var_s0->unk_0C += var_fs1;
        } else if ((ptr->unk_06 - 0x34) < tmp00) {
            var_s0->unk_0C -= 8.0;
            if (var_s0->unk_0C < ptr->unk_18) {
                var_s0->unk_0C = ptr->unk_18;
            }
            var_fs1 = __sinf((((ptr->unk_00 + i) % 200) * 251.327419281005859) / 200.0) * 0.1;
        } else {
            // M_PI * 60
            var_fs1 = __sinf((((ptr->unk_00 + i) % 200) * 188.495564460754395) / 200.0);
            var_s0->unk_0C += var_fs1;
        }

        tmp2 = var_s0->unk_0C;

        // M_PI * 22
        temp_fs4 = (((tmp00 + i) % 200) * 69.1150403022766113) / 200.0;
        // M_PI * 4
        temp_fs5 = (((tmp00 + i) % 200) * 12.566370964050293) / 200.0;

        spB8 = (__sinf(temp_fs4) * tmp2) + sp98;
        temp_fs0_2 = (__sinf(temp_fs5) * (0.7 * tmp2)) + sp94;
        temp_ft0 = __cosf(temp_fs4) * tmp2 + sp90;

        var_s0->unk_08 = temp_ft0;
        var_s0->unk_04 = temp_fs0_2 + var_fs1;
        var_s0->unk_00 = spB8;
        var_s0++;

        var_s0->unk_00 = spB8;
        var_s0->unk_04 = (2.0 * __sinf(temp_fs5 * 3.0)) + temp_fs0_2 + var_fs1;
        var_s0->unk_08 = temp_ft0;
        var_s0++;
    }

    return 0;
}

Gfx* Strip400_Draw(Gfx* arg0) {
    static Gfx D_843890E8[] = {
        gsDPPipeSync(),
        gsDPSetCycleType(G_CYC_1CYCLE),
        gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                              G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
        gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
        gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
        gsDPPipeSync(),
        gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
        gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT,
                           TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0),
        gsDPSetColorDither(G_CD_NOISE),
        gsDPLoadTextureBlock(D_84389068, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                             G_TX_NOMIRROR | G_TX_WRAP, 3, 4, G_TX_NOLOD, G_TX_NOLOD),
        gsDPPipeSync(),
        gsSPEndDisplayList(),
    };

    Vtx* vtx;
    s32 i;
    Strip400Node* var_a0;
    Strip400State* ptr = &sTrailState;

    if (ptr->unk_28 < 2) {
        return arg0;
    }
    ptr->unk_2C = Gfx_AllocDisplayList(ptr->unk_28 * 2 * sizeof(Vtx));
    vtx = ptr->unk_2C;
    var_a0 = &sTrailPoints[0];

    for (i = 0; i < ptr->unk_28; i++) {
        vtx->v.ob[0] = var_a0->unk_00;
        if (var_a0->unk_04 > 0.0) {
            vtx->v.ob[1] = var_a0->unk_04;
        } else {
            vtx->v.ob[1] = 0;
        }
        vtx->v.ob[2] = var_a0->unk_08;

        vtx->v.tc[0] = (i * 8) << 5;
        vtx->v.tc[1] = 0;

        vtx++;
        var_a0++;

        vtx->v.ob[0] = var_a0->unk_00;
        if (var_a0->unk_04 > 0.0) {
            vtx->v.ob[1] = var_a0->unk_04;
        } else {
            vtx->v.ob[1] = 0;
        }
        vtx->v.ob[2] = var_a0->unk_08;

        vtx->v.tc[0] = (i * 8) << 5;
        vtx->v.tc[1] = 0x200;

        vtx++;
        var_a0++;
    }

    gSPDisplayList(arg0++, D_843890E8);
    gDPSetPrimColor(arg0++, 0, 0, ptr->unk_30.r, ptr->unk_30.g, ptr->unk_30.b, 200);
    gDPSetEnvColor(arg0++, ptr->unk_33.r, ptr->unk_33.g, ptr->unk_33.b, 0);

    vtx = ptr->unk_2C;
    for (i = 0; i < ptr->unk_28 - 1; i++) {
        gSPVertex(arg0++, vtx, 4, 0);
        gSP2Triangles(arg0++, 0, 2, 1, 0, 2, 3, 1, 0);
        vtx += 2;
    }

    return arg0;
}

void Radial20_ResetPool(void) {
    s16 temp_v0;
    s32 i;
    s32 j;
    Radial20* var_a2;
    Radial20Node* var_v1;

    temp_v0 = AuxiliaryEffect_Alloc();
    var_a2 = &D_84398F50[0];

    for (i = 0; i < 10; i++) {
        var_a2->unk_000 = 0;
        var_a2->unk_004 = 0;
        var_a2->unk_006 = 0;

        var_v1 = &var_a2->unk_048[0];
        for (j = 0; j < 20; j++, var_v1++) {
            var_v1->unk_00 = 0.0f;
            var_v1->unk_04 = 0;
            var_v1->unk_08 = 1.0f;
            var_v1->unk_0C = 0.0f;
            var_v1->unk_10.x = 0.0f;
            var_v1->unk_10.y = 0.0f;
            var_v1->unk_10.z = 0.0f;
            var_v1->unk_1C.x = 0.0f;
            var_v1->unk_1C.y = 0.0f;
            var_v1->unk_1C.z = 0.0f;
        }

        var_a2->unk_002 = temp_v0;
        var_a2++;
    }
}

void Radial20_VariantA(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 argA, f32 argB, f32 argC, f32 argD, s16 argE) {
    Radial20* var_v0;
    Radial20Node* var_a1_2;
    s32 i;
    s32 j;
    Vec3f sp14;
    Vec3f sp8;

    sp14.x = arg0;
    sp14.y = arg1;
    sp14.z = arg2;
    sp8.x = arg3;
    sp8.y = arg4;
    sp8.z = arg5;

    var_v0 = &D_84398F50[0];

    for (i = 0; i < 10; i++, var_v0++) {
        if (var_v0->unk_000 == 0) {
            var_v0->unk_000 = 1;
            var_v0->unk_004 = 0;
            var_v0->unk_006 = argE;
            var_v0->unk_008 = arg6;
            var_v0->unk_00A.r = arg7;
            var_v0->unk_00A.g = arg8;
            var_v0->unk_00A.b = arg9;
            var_v0->unk_00A.a = argA;
            var_v0->unk_014 = argD;
            var_v0->unk_018 = argB;

            // clang-format off
            for (j = 0; j < 3; j++) { var_v0->unk_038[j] = 0; }
            // clang-format on

            var_a1_2 = &var_v0->unk_048[0];
            for (j = 0; j < 20; j++) {
                var_a1_2->unk_00 = j;
                if (j == 0) {
                    var_a1_2->unk_04 = 0xFF;
                } else {
                    var_a1_2->unk_04 = (argA * (0x13 - j)) / 20;
                }
                var_a1_2->unk_08 = argC;
                var_a1_2->unk_0C = 0.0f;
                var_a1_2->unk_10 = sp14;
                var_a1_2->unk_1C = sp8;
                var_a1_2++;
            }
            break;
        }
    }
}

void Radial20_VariantB(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 argA, f32 argB, f32 argC, f32 argD, s16 argE) {
    Radial20* var_v0;
    Radial20Node* var_v1_2;
    s32 i;
    s32 j;
    Vec3f spC;
    Vec3f sp0;

    spC.x = arg0;
    spC.y = arg1;
    spC.z = arg2;
    sp0.x = arg3;
    sp0.y = arg4;
    sp0.z = arg5;

    var_v0 = &D_84398F50[0];

    for (i = 0; i < 10; i++, var_v0++) {
        if (var_v0->unk_000 == 0) {
            var_v0->unk_000 = 1;
            var_v0->unk_004 = 0;
            var_v0->unk_006 = argE;
            var_v0->unk_008 = arg6;
            var_v0->unk_00A.r = arg7;
            var_v0->unk_00A.g = arg8;
            var_v0->unk_00A.b = arg9;
            var_v0->unk_014 = argD;
            var_v0->unk_018 = argB;

            var_v1_2 = &var_v0->unk_048[0];
            for (j = 0; j < 20; j++, var_v1_2++) {
                var_v1_2->unk_00 = j;
                var_v1_2->unk_04 = argA;
                var_v1_2->unk_08 = argC;
                var_v1_2->unk_0C = 0.0f;
                var_v1_2->unk_10 = spC;
                var_v1_2->unk_1C = sp0;
            }
            break;
        }
    }
}

void Radial20_VariantC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 argA, u8 argB, u8 argC, u8 argD, f32 argE, f32 argF, f32 arg10, s16 arg11) {
    Radial20* var_v0;
    Radial20Node* var_s0;
    s32 i;
    s32 j;
    Vec3f spBC;
    Vec3f spB0;
    s32 temp_fp;
    s32 temp_s2;
    s32 spA4;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s7;
    s32 tmp;

    spBC.x = arg0;
    spBC.y = arg1;
    spBC.z = arg2;
    spB0.x = arg3;
    spB0.y = arg4;
    spB0.z = arg5;

    var_v0 = &D_84398F50[0];

    for (i = 0; i < 10; i++, var_v0++) {
        if (var_v0->unk_000 == 0) {
            var_s0 = &var_v0->unk_048[0];

            var_v0->unk_000 = 1;
            var_v0->unk_004 = 0;
            var_v0->unk_006 = arg11;
            var_v0->unk_008 = arg6;
            var_v0->unk_00A.r = arg7;
            var_v0->unk_00A.g = arg8;
            var_v0->unk_00A.b = arg9;
            var_v0->unk_00A.a = argA;
            var_v0->unk_00E.r = argB;
            var_v0->unk_00E.g = argC;
            var_v0->unk_00E.b = argD;
            var_v0->unk_014 = arg10;
            var_v0->unk_018 = argE;

            temp_s7 = (guRandom() % 20) + 2;
            temp_fp = (guRandom() % 10) + 4;
            spA4 = (guRandom() % 20) + 2;
            temp_s4 = (guRandom() % 10) + 4;

            for (j = 0, temp_s3 = temp_s7, temp_s2 = spA4; j < 20; j++) {
                var_s0->unk_00 = j;
                var_s0->unk_04 = argA;
                var_s0->unk_08 = argF;
                var_s0->unk_0C = 0.0f;
                var_s0->unk_10 = spBC;
                var_s0->unk_1C = spB0;

                var_s0->unk_1C.y += 2.0 * __sinf(((temp_s3 % temp_fp) * TWO_PI) / temp_fp) *
                                    __sinf(((temp_s2 % (temp_s4 + 0x14)) * TWO_PI) / (temp_s4 + 0x14));
                var_s0->unk_1C.z += 0.5 * __sinf(((temp_s2 % temp_s4) * TWO_PI) / temp_s4);
                tmp = j * 0.5;
                var_s0->unk_10.x += var_s0->unk_1C.x * ((j * 0.5) - tmp);

                temp_s2++;
                temp_s3++;
                var_s0++;
            }
            break;
        }
    }
}

void Radial20_VariantD(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 argA, u8 argB, u8 argC, u8 argD, f32 argE, f32 argF, f32 arg10, s16 arg11) {
    Radial20* var_v0;
    Radial20Node* var_s0;
    s32 i;
    s32 j;
    Vec3f spBC;
    Vec3f spB0;
    s32 temp_fp;
    s32 temp_s2;
    s32 spA4;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s7;
    s32 tmp;

    spBC.x = arg0;
    spBC.y = arg1;
    spBC.z = arg2;
    spB0.x = arg3;
    spB0.y = arg4;
    spB0.z = arg5;

    var_v0 = &D_84398F50[0];

    for (i = 0; i < 10; i++, var_v0++) {
        if (var_v0->unk_000 == 0) {
            var_s0 = &var_v0->unk_048[0];

            var_v0->unk_000 = 1;
            var_v0->unk_004 = 0;
            var_v0->unk_006 = arg11;
            var_v0->unk_008 = arg6;
            var_v0->unk_00A.r = arg7;
            var_v0->unk_00A.g = arg8;
            var_v0->unk_00A.b = arg9;
            var_v0->unk_00A.a = argA;
            var_v0->unk_00E.r = argB;
            var_v0->unk_00E.g = argC;
            var_v0->unk_00E.b = argD;
            var_v0->unk_014 = arg10;
            var_v0->unk_018 = argE;

            temp_s7 = (guRandom() % 20) + 2;
            temp_fp = (guRandom() % 10) + 4;
            spA4 = (guRandom() % 20) + 2;
            temp_s4 = (guRandom() % 10) + 4;

            for (j = 0, temp_s3 = temp_s7, temp_s2 = spA4; j < 20; j++) {
                var_s0->unk_00 = j;
                var_s0->unk_04 = argA;
                var_s0->unk_08 = argF;
                var_s0->unk_0C = 0.0f;
                var_s0->unk_10 = spBC;
                var_s0->unk_1C = spB0;

                var_s0->unk_1C.z += 2.5 * __sinf(((temp_s3 % temp_fp) * TWO_PI) / temp_fp) *
                                    __sinf(((temp_s2 % (temp_s4 + 0x14)) * TWO_PI) / (temp_s4 + 0x14));
                var_s0->unk_1C.y += 0.5 * __sinf(((temp_s2 % temp_s4) * TWO_PI) / temp_s4);
                tmp = j * 0.5;
                var_s0->unk_10.x += var_s0->unk_1C.x * ((j * 0.5) - tmp);

                temp_s2++;
                temp_s3++;
                var_s0++;
            }
            break;
        }
    }
}

void Radial20_VariantE(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s16 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 argA, f32 argB, f32 argC, f32 argD, s16 argE) {
    Radial20* var_v0;
    Radial20Node* var_s0;
    s32 i;
    s32 j;
    Vec3f spBC;
    Vec3f spB0;
    s32 temp_fp;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;

    spBC.x = arg0;
    spBC.y = arg1;
    spBC.z = arg2;
    spB0.x = arg3;
    spB0.y = arg4;
    spB0.z = arg5;

    var_v0 = &D_84398F50[0];

    for (i = 0; i < 10; i++, var_v0++) {
        if (var_v0->unk_000 == 0) {
            var_s0 = &var_v0->unk_048[0];

            var_v0->unk_000 = 1;
            var_v0->unk_004 = 0;
            var_v0->unk_006 = argE;
            var_v0->unk_008 = arg6;
            var_v0->unk_00A.r = arg7;
            var_v0->unk_00A.g = arg8;
            var_v0->unk_00A.b = arg9;
            var_v0->unk_014 = argD;
            var_v0->unk_018 = argB;

            temp_s5 = RAND(20) + 2;
            temp_s7 = RAND(10) + 4;
            temp_s6 = RAND(20) + 2;
            temp_fp = RAND(10) + 4;

            for (j = 0; j < 20; j++) {
                var_s0->unk_00 = j;
                var_s0->unk_04 = argA;
                var_s0->unk_08 = argC;
                var_s0->unk_0C = 0.0f;
                var_s0->unk_10 = spBC;

                var_s0->unk_10.y += 5.0 * __sinf((((temp_s5 + j) % temp_s7) * TWO_PI) / temp_s7) *
                                    __sinf((((temp_s6 + j) % (temp_fp + 20)) * TWO_PI) / (temp_fp + 20));
                var_s0->unk_10.z += 5.0 * __cosf((((temp_s5 + j) % temp_s7) * TWO_PI) / temp_s7) *
                                    __cosf((((temp_s6 + j) % (temp_fp + 20)) * TWO_PI) / (temp_fp + 20));
                var_s0->unk_1C = spB0;

                var_s0->unk_10.x += var_s0->unk_1C.x * ((j * 0.5) - (s32)(j * 0.5));

                var_s0++;
            }
            break;
        }
    }
}

void Radial20_RotateVertexOffset(f32 arg0, UNUSED Vec3f* arg1, Vec3f* arg2, f32 arg3, UNUSED f32 arg4, UNUSED f32 arg5,
                   UNUSED f32 arg6) {
    UNUSED MtxF pad;
    MtxF sp30;
    UNUSED s32 pad2[2];

    guRotateF(sp30.mf, (arg0 * 360.0) / TWO_PI, 1.0f, 0.0f, 0.0f);
    guMtxXFMF(sp30.mf, 0.0f, 0.0f, arg3, &arg2->x, &arg2->y, &arg2->z);
}

void Radial20_UpdateNode(Radial20* arg0) {
    Radial20Node* var_v0;
    UNUSED s32 pad;
    s32 i;
    Vec3f sp28;

    BattleAnim_GetSecondaryOwnerAnchorPosition(&sp28);

    switch (arg0->unk_008) {
        case 0:
            var_v0 = &arg0->unk_048[0];
            for (i = 0; i < 20; i++, var_v0++) {
                if (var_v0->unk_00 > 0.0) {
                    var_v0->unk_00 -= 1.0;
                } else {
                    var_v0->unk_10.x += var_v0->unk_1C.x;
                    var_v0->unk_10.y += var_v0->unk_1C.y;
                    var_v0->unk_10.z += var_v0->unk_1C.z;
                    var_v0->unk_0C += arg0->unk_018;

                    var_v0->unk_08 += 1.0;
                    if (arg0->unk_014 < var_v0->unk_08) {
                        var_v0->unk_08 = arg0->unk_014;
                    }
                }
            }
            break;

        case 3:
            var_v0 = &arg0->unk_048[0];
            for (i = 0; i < 20; i++, var_v0++) {
                if (var_v0->unk_00 > 0.0) {
                    var_v0->unk_10 = sp28;
                    var_v0->unk_00 -= 1.0;
                } else {
                    var_v0->unk_10.x += var_v0->unk_1C.x;
                    var_v0->unk_10.y += var_v0->unk_1C.y;
                    var_v0->unk_10.z += var_v0->unk_1C.z;

                    var_v0->unk_0C += arg0->unk_018;

                    if (var_v0->unk_1C.x > 1.0) {
                        var_v0->unk_1C.x -= 0.1;
                    }

                    if (var_v0->unk_1C.x < -1.0) {
                        var_v0->unk_1C.x += 0.1;
                    }

                    var_v0->unk_1C.y -= 0.2;
                    if (var_v0->unk_1C.y < -1.0) {
                        var_v0->unk_1C.y = -1.0f;
                    }

                    if (var_v0->unk_10.y < 0.0) {
                        var_v0->unk_10.y = 0.0f;
                    }
                }
            }
            break;

        default:
            var_v0 = &arg0->unk_048[0];
            for (i = 0; i < 20; i++, var_v0++) {
                if (var_v0->unk_00 > 0.0) {
                    var_v0->unk_10 = sp28;
                    var_v0->unk_00 -= 1.0;
                } else {
                    var_v0->unk_10.x += var_v0->unk_1C.x;
                    var_v0->unk_10.y = sp28.y;
                    var_v0->unk_10.z = sp28.z;

                    var_v0->unk_0C += arg0->unk_018;
                    var_v0->unk_08 += 1.0;

                    if (arg0->unk_014 < var_v0->unk_08) {
                        var_v0->unk_08 = arg0->unk_014;
                    }
                }
            }
            break;

        case 6:
            var_v0 = &arg0->unk_048[0];
            for (i = 0; i < 20; i++, var_v0++) {
                if (var_v0->unk_00 > 0.0) {
                    var_v0->unk_10 = sp28;
                    var_v0->unk_00 -= 1.0;
                } else {
                    var_v0->unk_10.x += var_v0->unk_1C.x;
                    var_v0->unk_10.y += var_v0->unk_1C.y;
                    var_v0->unk_10.z += var_v0->unk_1C.z;

                    var_v0->unk_0C += arg0->unk_018;
                    var_v0->unk_08 += 1.0;

                    if (arg0->unk_014 < var_v0->unk_08) {
                        var_v0->unk_08 = arg0->unk_014;
                    }
                }
            }
            break;

        case 7:
        case 8:
            var_v0 = &arg0->unk_048[0];
            for (i = 0; i < 20; i++, var_v0++) {
                if (var_v0->unk_00 > 0.0) {
                    var_v0->unk_00 -= 1.0;
                } else {
                    var_v0->unk_10.x += var_v0->unk_1C.x;
                    var_v0->unk_10.y += var_v0->unk_1C.y;
                    var_v0->unk_10.z += var_v0->unk_1C.z;

                    var_v0->unk_0C += arg0->unk_018;
                    var_v0->unk_08 += 1.0;

                    if (arg0->unk_014 < var_v0->unk_08) {
                        var_v0->unk_08 = arg0->unk_014;
                    }
                }
            }
            break;

        case 2:
        case 4:
            var_v0 = &arg0->unk_048[0];
            for (i = 0; i < 20; i++, var_v0++) {
                if (var_v0->unk_00 > 0.0) {
                    var_v0->unk_00 -= 1.0;
                } else {
                    var_v0->unk_10.x += var_v0->unk_1C.x;
                    var_v0->unk_10.y += var_v0->unk_1C.y;
                    var_v0->unk_10.z += var_v0->unk_1C.z;

                    var_v0->unk_0C += arg0->unk_018;
                    var_v0->unk_08 += 1.0;

                    if (arg0->unk_014 < var_v0->unk_08) {
                        var_v0->unk_08 = arg0->unk_014;
                    }
                }
            }
            break;
    }
}

s32 Radial20_IsComplete(void) {
    s32 i;
    s32 var_s2 = 0;
    Radial20* var_s0 = D_84398F50;

    for (i = 0; i < 10; i++, var_s0++) {
        if (var_s0->unk_000 == 1) {
            var_s0->unk_004++;
            if (var_s0->unk_006 < var_s0->unk_004) {
                var_s0->unk_000 = 0;
                if (var_s0->unk_008 == 8) {}
            } else {
                Radial20_UpdateNode(var_s0);
                var_s2++;
            }
            AuxiliaryEffect_Update(var_s0->unk_002);
        }
    }

    if (var_s2 > 0) {
        return 0;
    }
    return -1;
}

static s32 pad_D_84389178[2] = { 0, 0 };

static Gfx D_84389180[] = {
    gsSPEndDisplayList(),
};

static u32 D_84389188[] = {
    0x08080808, 0x08080808, 0x0D0D0D0D, 0x0D0D0D0D, 0x2F2F2F2F, 0x2F2F2F2F, 0x6F6F6F6F, 0x6F6F6F6F,
    0x9F9F9F9F, 0x9F9F9F9F, 0xDFDFDFDF, 0xDFDFDFDF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xDFDFDFDF, 0xDFDFDFDF, 0x9F9F9F9F, 0x9F9F9F9F,
    0x6F6F6F6F, 0x6F6F6F6F, 0x2F2F2F2F, 0x2F2F2F2F, 0x0D0D0D0D, 0x0D0D0D0D, 0x08080808, 0x08080808,
};

Gfx* Radial20_Draw(Gfx* arg0) {
    static Gfx D_84389208[] = {
        gsDPPipeSync(),
        gsDPSetCycleType(G_CYC_1CYCLE),
        gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                              G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
        gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
        gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
        gsDPPipeSync(),
        gsDPSetRenderMode(G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2),
        gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT,
                           TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0),
        gsDPSetColorDither(G_CD_NOISE),
        gsDPLoadTextureBlock(D_84389068, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                             G_TX_NOMIRROR | G_TX_WRAP, 3, 4, G_TX_NOLOD, G_TX_NOLOD),
        gsSPEndDisplayList(),
    };
    static Gfx D_84389290[] = {
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
    static u8 D_843892E0[] = { 0xFF, 0, 0xFF };
    static u8 D_843892E4[] = { 0x20, 0x20, 0xFF };
    static u8 D_843892E8[] = { 0, 0xFF, 0 };
    static f32 D_843892EC[] = { 1.0f, 1.73205f, 1.0f };

    s32 i;
    s32 x;
    s32 j;
    s32 y;
    Radial20* sp1B4;
    Radial20Node* var_s2;
    Vtx* vtx;
    Vec3f sp1A0;

    sp1B4 = D_84398F50;

    for (i = 0; i < 10; i++) {
        if (sp1B4->unk_000 == 1) {
            var_s2 = &sp1B4->unk_048[0];

            switch (sp1B4->unk_008) {
                case 0:
                case 3:
                    vtx = Gfx_AllocDisplayList(sizeof(Vtx) * 40);
                    sp1B4->unk_01C = vtx;

                    for (j = 0; j < 20; j++, vtx++) {
                        Radial20_RotateVertexOffset(var_s2->unk_0C, &var_s2->unk_1C, &sp1A0, var_s2->unk_08, 1.0f, 0.0f, 0.0f);

                        vtx->v.ob[0] = var_s2->unk_10.x + sp1A0.x;
                        vtx->v.ob[1] = var_s2->unk_10.y + sp1A0.y;
                        vtx->v.ob[2] = var_s2->unk_10.z + sp1A0.z;
                        vtx->v.tc[0] = (j * 8) << 5;
                        vtx->v.tc[1] = 0;
                        vtx++;

                        if (var_s2->unk_00 <= 0.0) {
                            Radial20_RotateVertexOffset(var_s2->unk_0C + M_PI_F, &var_s2->unk_1C, &sp1A0, var_s2->unk_08, 1.0f, 0.0f,
                                          0.0f);
                        }

                        vtx->v.ob[0] = var_s2->unk_10.x + sp1A0.x;
                        vtx->v.ob[1] = var_s2->unk_10.y + sp1A0.y;
                        vtx->v.ob[2] = var_s2->unk_10.z + sp1A0.z;
                        vtx->v.tc[0] = (j * 8) << 5;
                        vtx->v.tc[1] = 0x200;
                        var_s2++;
                    }
                    break;

                case 1:
                    vtx = Gfx_AllocDisplayList(sizeof(Vtx) * 60);
                    sp1B4->unk_01C = vtx;

                    for (j = 0; j < 20; j++, vtx++) {
                        Radial20_RotateVertexOffset(var_s2->unk_0C, &var_s2->unk_1C, &sp1A0, var_s2->unk_08, 1.0f, 0.0f, 0.0f);

                        vtx->v.ob[0] = var_s2->unk_10.x + sp1A0.x;
                        vtx->v.ob[1] = var_s2->unk_10.y + sp1A0.y;
                        vtx->v.ob[2] = var_s2->unk_10.z + sp1A0.z;
                        vtx->v.cn[0] = 0xFF;
                        vtx->v.cn[1] = 0x40;
                        vtx->v.cn[2] = 0x40;
                        vtx->v.cn[3] = var_s2->unk_04;
                        vtx++;

                        if (var_s2->unk_00 <= 0.0) {
                            Radial20_RotateVertexOffset(var_s2->unk_0C + TWO_THIRDS_PI, &var_s2->unk_1C, &sp1A0, var_s2->unk_08, 1.0f,
                                          0.0f, 0.0f);
                        }

                        vtx->v.ob[0] = var_s2->unk_10.x + sp1A0.x;
                        vtx->v.ob[1] = var_s2->unk_10.y + sp1A0.y;
                        vtx->v.ob[2] = var_s2->unk_10.z + sp1A0.z;
                        vtx->v.cn[0] = 0;
                        vtx->v.cn[1] = 0xA0;
                        vtx->v.cn[2] = 0xFF;
                        vtx->v.cn[3] = var_s2->unk_04;
                        vtx++;

                        if (var_s2->unk_00 <= 0.0) {
                            Radial20_RotateVertexOffset(var_s2->unk_0C + TWO_THIRDS_PI * 2, &var_s2->unk_1C, &sp1A0, var_s2->unk_08, 1.0f,
                                          0.0f, 0.0f);
                        }

                        vtx->v.ob[0] = var_s2->unk_10.x + sp1A0.x;
                        vtx->v.ob[1] = var_s2->unk_10.y + sp1A0.y;
                        vtx->v.ob[2] = var_s2->unk_10.z + sp1A0.z;
                        vtx->v.cn[0] = 0xFF;
                        vtx->v.cn[1] = 0xFF;
                        vtx->v.cn[2] = 0;
                        vtx->v.cn[3] = var_s2->unk_04;
                        var_s2++;
                    }
                    break;

                case 5:
                    vtx = Gfx_AllocDisplayList(sizeof(Vtx) * 60);
                    sp1B4->unk_01C = vtx;

                    for (j = 0; j < 20; j++, vtx++) {
                        Radial20_RotateVertexOffset(var_s2->unk_0C, &var_s2->unk_1C, &sp1A0, var_s2->unk_08, 1.0f, 0.0f, 0.0f);

                        vtx->v.ob[0] = var_s2->unk_10.x + sp1A0.x;
                        vtx->v.ob[1] = var_s2->unk_10.y + sp1A0.y;
                        vtx->v.ob[2] = var_s2->unk_10.z + sp1A0.z;
                        vtx->v.cn[0] = sp1B4->unk_00A.r;
                        vtx->v.cn[1] = sp1B4->unk_00A.g;
                        vtx->v.cn[2] = sp1B4->unk_00A.b;
                        vtx->v.cn[3] = var_s2->unk_04;
                        vtx++;

                        if (var_s2->unk_00 <= 0.0) {
                            Radial20_RotateVertexOffset(var_s2->unk_0C + TWO_THIRDS_PI, &var_s2->unk_1C, &sp1A0, var_s2->unk_08, 1.0f,
                                          0.0f, 0.0f);
                        }

                        vtx->v.ob[0] = var_s2->unk_10.x + sp1A0.x;
                        vtx->v.ob[1] = var_s2->unk_10.y + sp1A0.y;
                        vtx->v.ob[2] = var_s2->unk_10.z + sp1A0.z;
                        vtx->v.cn[0] = sp1B4->unk_00A.r;
                        vtx->v.cn[1] = sp1B4->unk_00A.g;
                        vtx->v.cn[2] = sp1B4->unk_00A.b;
                        vtx->v.cn[3] = var_s2->unk_04;
                        vtx++;

                        if (var_s2->unk_00 <= 0.0) {
                            Radial20_RotateVertexOffset(var_s2->unk_0C + TWO_THIRDS_PI * 2, &var_s2->unk_1C, &sp1A0, var_s2->unk_08, 1.0f,
                                          0.0f, 0.0f);
                        }

                        vtx->v.ob[0] = var_s2->unk_10.x + sp1A0.x;
                        vtx->v.ob[1] = var_s2->unk_10.y + sp1A0.y;
                        vtx->v.ob[2] = var_s2->unk_10.z + sp1A0.z;
                        vtx->v.cn[0] = sp1B4->unk_00A.r;
                        vtx->v.cn[1] = sp1B4->unk_00A.g;
                        vtx->v.cn[2] = sp1B4->unk_00A.b;
                        vtx->v.cn[3] = var_s2->unk_04;
                        var_s2++;
                    }
                    break;

                case 6:
                case 7:
                    vtx = Gfx_AllocDisplayList(sizeof(Vtx) * 20 * 6);
                    sp1B4->unk_01C = vtx;

                    for (j = 0; j < 20; j++, var_s2++) {
                        for (x = 0; x < 6; x++) {
                            Radial20_RotateVertexOffset(var_s2->unk_0C + ((2.0 * x * M_PI_F) / 6.0), &var_s2->unk_1C, &sp1A0,
                                          var_s2->unk_08, 1.0f, 0.0f, 0.0f);

                            vtx->v.ob[0] = var_s2->unk_10.x + sp1A0.x;
                            vtx->v.ob[1] = var_s2->unk_10.y + sp1A0.y;
                            vtx->v.ob[2] = var_s2->unk_10.z + sp1A0.z;
                            vtx->v.cn[0] = sp1B4->unk_00A.r;
                            vtx->v.cn[1] = sp1B4->unk_00A.g;
                            vtx->v.cn[2] = sp1B4->unk_00A.b;
                            vtx->v.cn[3] = 0x64;
                            vtx++;
                        }
                    }
                    break;

                case 8:
                    vtx = Gfx_AllocDisplayList(sizeof(Vtx) * 20 * 3 * 3);
                    sp1B4->unk_01C = vtx;

                    for (j = 0; j < 20; j++, var_s2++) {
                        for (x = 0; x < 3; x++) {
                            for (y = 0; y < 3; y++) {
                                f32 x1, y1, z1;

                                Radial20_RotateVertexOffset(var_s2->unk_0C + ((TWO_PI_F * y) / 12.0f) + ((TWO_PI_F * x) / 3.0f),
                                              &var_s2->unk_1C, &sp1A0, D_843892EC[y] * var_s2->unk_08, 1.0f, 0.0f, 0.0f);

                                x1 = var_s2->unk_10.x + sp1A0.x;
                                y1 = var_s2->unk_10.y + sp1A0.y;
                                z1 = var_s2->unk_10.z + sp1A0.z;

                                vtx->v.ob[0] = x1;
                                vtx->v.ob[1] = y1;
                                vtx->v.ob[2] = z1;

                                if ((y == 0) && (RAND(100) == 0)) {
                                    AuxiliaryEffect_Spawn(sp1B4->unk_002, x1, y1, z1, 0xA, 0.75f);
                                }

                                vtx->v.cn[0] = ((D_843892E0[x] * (0xFF - var_s2->unk_04)) + (var_s2->unk_04 * 0xFF)) / 255;
                                vtx->v.cn[1] = ((D_843892E4[x] * (0xFF - var_s2->unk_04)) + (var_s2->unk_04 * 0xFF)) / 255;
                                vtx->v.cn[2] = ((D_843892E8[x] * (0xFF - var_s2->unk_04)) + (var_s2->unk_04 * 0xFF)) / 255;
                                vtx->v.cn[3] = var_s2->unk_04;
                                vtx++;
                            }
                        }
                    }
                    break;

                case 2:
                case 4:
                    vtx = Gfx_AllocDisplayList(sizeof(Vtx) * 20 * 15);
                    sp1B4->unk_01C = vtx;

                    for (j = 0; j < 20; j++, var_s2++) {
                        for (x = 0; x < 15; x++) {
                            if (var_s2->unk_00 <= 0.0) {
                                Radial20_RotateVertexOffset(var_s2->unk_0C + ((2.0 * x * M_PI_F) / 15.0), &var_s2->unk_1C, &sp1A0,
                                              var_s2->unk_08, 1.0f, 0.0f, 0.0f);
                            }

                            vtx->v.ob[0] = var_s2->unk_10.x + sp1A0.x;
                            vtx->v.ob[1] = var_s2->unk_10.y + sp1A0.y;
                            vtx->v.ob[2] = var_s2->unk_10.z + sp1A0.z;
                            vtx->v.cn[0] = sp1B4->unk_00A.r;
                            vtx->v.cn[1] = sp1B4->unk_00A.g;
                            vtx->v.cn[2] = sp1B4->unk_00A.b;
                            vtx->v.cn[3] = var_s2->unk_04;
                            vtx++;
                        }
                    }
                    break;

                default:
                    break;
            }

            vtx = sp1B4->unk_01C;
            for (x = 0; x < 19; x++) {
                switch (sp1B4->unk_008) {
                    case 0:
                    case 3:
                        gSPDisplayList(arg0++, D_84389208);
                        gDPSetPrimColor(arg0++, 0, 0, sp1B4->unk_00A.r, sp1B4->unk_00A.g, sp1B4->unk_00A.b,
                                        sp1B4->unk_00A.a);
                        gDPSetEnvColor(arg0++, sp1B4->unk_00E.r, sp1B4->unk_00E.g, sp1B4->unk_00E.b, 0);
                        gSPVertex(arg0++, vtx, 4, 0);
                        gSP2Triangles(arg0++, 0, 2, 1, 0, 2, 3, 1, 0);
                        vtx += 2;
                        break;

                    default:
                        gSPDisplayList(arg0++, D_84389290);
                        gSPClearGeometryMode(arg0++, G_CULL_BOTH);
                        gSPSetGeometryMode(arg0++, G_CULL_FRONT);
                        gSPVertex(arg0++, vtx, 6, 0);
                        gSP2Triangles(arg0++, 0, 3, 1, 0, 3, 4, 1, 0);
                        gSP2Triangles(arg0++, 1, 4, 2, 0, 4, 5, 2, 0);
                        gSP2Triangles(arg0++, 2, 5, 0, 0, 5, 3, 0, 0);
                        vtx += 3;
                        break;

                    case 6:
                    case 7:
                        gSPDisplayList(arg0++, D_84389290);
                        gSPClearGeometryMode(arg0++, G_CULL_BOTH);
                        gSPSetGeometryMode(arg0++, G_CULL_FRONT);
                        gSPVertex(arg0++, vtx, 12, 0);

                        for (j = 0; j < 5; j++) {
                            gSP2Triangles(arg0++, j + 0, j + 6, j + 1, 0, j + 1, j + 6, j + 7, 0);
                        }

                        gSP2Triangles(arg0++, 5, 11, 0, 0, 0, 11, 6, 0);
                        vtx += 6;
                        break;

                    case 2:
                    case 4:
                        gSPDisplayList(arg0++, D_84389290);
                        gSPVertex(arg0++, vtx, 30, 0);

                        for (j = 0; j < 14; j++) {
                            gSP2Triangles(arg0++, j + 0, j + 15, j + 1, 0, j + 15, j + 16, j + 1, 0);
                        }

                        gSP2Triangles(arg0++, 14, 29, 0, 0, 29, 15, 0, 0);
                        vtx += 15;
                        break;

                    case 8:
                        gSPDisplayList(arg0++, D_84389290);
                        gSPClearGeometryMode(arg0++, G_CULL_BOTH);
                        gSPSetGeometryMode(arg0++, G_CULL_FRONT);
                        gSPVertex(arg0++, vtx, 18, 0);

                        for (j = 0; j < 3; j++) {
                            u8 idx = j * 3;
                            gSP2Triangles(arg0++, idx + 0, idx + 9, idx + 1, 0, idx + 1, idx + 9, idx + 10, 0);
                            gSP2Triangles(arg0++, idx + 1, idx + 10, idx + 2, 0, idx + 2, idx + 10, idx + 11, 0);
                            gSP2Triangles(arg0++, idx + 2, idx + 11, idx + 0, 0, idx + 0, idx + 11, idx + 9, 0);
                        }

                        vtx += 9;
                        break;
                }
            }

            vtx = sp1B4->unk_01C;
            for (x = 0; x < 19; x++) {
                switch (sp1B4->unk_008) {
                    case 0:
                    case 2:
                    case 3:
                    case 4:
                        break;

                    default:
                    case 1:
                    case 5:
                        gSPDisplayList(arg0++, D_84389290);
                        gSPClearGeometryMode(arg0++, G_CULL_BOTH);
                        gSPSetGeometryMode(arg0++, G_CULL_BACK);
                        gSPVertex(arg0++, vtx, 6, 0);
                        gSP2Triangles(arg0++, 0, 3, 1, 0, 3, 4, 1, 0);
                        gSP2Triangles(arg0++, 1, 4, 2, 0, 4, 5, 2, 0);
                        gSP2Triangles(arg0++, 2, 5, 0, 0, 5, 3, 0, 0);
                        vtx += 3;
                        break;

                    case 6:
                    case 7:
                        gSPDisplayList(arg0++, D_84389290);
                        gSPClearGeometryMode(arg0++, G_CULL_BOTH);
                        gSPSetGeometryMode(arg0++, G_CULL_BACK);
                        gSPVertex(arg0++, vtx, 12, 0);

                        for (j = 0; j < 5; j++) {
                            gSP2Triangles(arg0++, j + 0, j + 6, j + 1, 0, j + 1, j + 6, j + 7, 0);
                        }

                        gSP2Triangles(arg0++, 5, 11, 0, 0, 0, 11, 6, 0);
                        vtx += 6;
                        break;

                    case 8:
                        gSPDisplayList(arg0++, D_84389290);
                        gSPClearGeometryMode(arg0++, G_CULL_BOTH);
                        gSPSetGeometryMode(arg0++, G_CULL_BACK);
                        gSPVertex(arg0++, vtx, 18, 0);

                        for (j = 0; j < 3; j++) {
                            u8 idx = j * 3;
                            gSP2Triangles(arg0++, idx + 0, idx + 9, idx + 1, 0, idx + 1, idx + 9, idx + 10, 0);
                            gSP2Triangles(arg0++, idx + 1, idx + 10, idx + 2, 0, idx + 2, idx + 10, idx + 11, 0);
                            gSP2Triangles(arg0++, idx + 2, idx + 11, idx + 0, 0, idx + 0, idx + 11, idx + 9, 0);
                        }

                        vtx += 9;
                        break;
                }
            }

            vtx = sp1B4->unk_01C;
            switch (sp1B4->unk_008) {
                case 8:
                    gSPDisplayList(arg0++, D_84389290);
                    gSPClearGeometryMode(arg0++, G_CULL_BOTH);
                    gSPVertex(arg0++, vtx, 9, 0);
                    gSP2Triangles(arg0++, 2, 1, 0, 0, 5, 4, 3, 0);
                    gSP1Triangle(arg0++, 8, 7, 6, 0);
                    break;
            }
            arg0 = AuxiliaryEffect_Draw(sp1B4->unk_002, arg0);
        }
        sp1B4++;
    }

    return arg0;
}
