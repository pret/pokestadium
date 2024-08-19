#include "fragment4.h"
#include "src/fragments/2/fragment2.h"
#include "src/6A40.h"
#include "src/4CBC0.h"

u32 D_87A01110[] = {
    0xA5B2A1BC, 0xA5E0A4CE, 0xA4BBA4C4, 0xA4E1A4A4, 0x00000000, 0xA3C1A5DC, 0xA5BFA5F3, 0x00000000, 0xA4B8A4E5,
    0xA4A6A4B8, 0xA5ADA1BC, 0x00000000, 0xA5B2A1BC, 0xA5E0A4F2, 0xA4CFA4B8, 0xA4E1A4EB, 0x00000000, 0xA5B8A5E3,
    0xA5F3A5D7, 0x00000000, 0xA1A6A1A6, 0xA1A60000, 0xA5B2A5C3, 0xA5C8A4C0, 0xA4BCA1AA, 0x00000000,
};

u32 D_87A01178[] = {
    0xA5B5A5C8,
    0xA5B70000,
};

u32 D_87A01180[] = {
    0xA5ABA5B9,
    0xA5DF0000,
    0xA5BFA5B1,
    0xA5B70000,
};

u32 D_87A01190[] = {
    0xA5E0A5B5, 0xA5B70000, 0xA5B3A5B8, 0xA5EDA5A6, 0x00000000,
};

u32 D_87A011A4[] = {
    0xA5B7A5B2, 0xA5EB0000, 0xA4CEA4AB, 0xA4C10000, 0xA4D2A4AD, 0xA4EFA4B1, 0x00000000,
};

static Vtx D_87A011C0[] = {
    VTX(-25, 25, 0, 0, 0, 0x00, 0x00, 0x00, 0xFF),
    VTX(-25, -25, 0, 0, 2048, 0x00, 0x00, 0x00, 0xFF),
    VTX(25, -25, 0, 2048, 2048, 0x00, 0x00, 0x00, 0xFF),
    VTX(25, 25, 0, 2048, 0, 0x00, 0x00, 0x00, 0xFF),
};

static Gfx D_87A01200[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | G_RM_PASS,
                      AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL |
                          GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsSPTexture(0x7FFF, 0x7FFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPVertex(D_87A011C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

static Vtx D_87A01268[] = {
    VTX(-50, 25, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, -25, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, -25, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 25, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Gfx D_87A012A8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | G_RM_PASS,
                      AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL |
                          GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_PASS2),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

// Is this real?
static u8 pad_D_87A01300[0x30];
static unk_D_86002F34_00C* D_87A01330;

void func_87A00020(unk_D_86002F34_00C* arg0) {
    D_87A01330 = arg0;
}

Gfx* func_87A0002C(Gfx* arg0) {
    gSPPerspNormalize(arg0++, D_87A01330->unk_028);
    gSPMatrix(arg0++, (u32)D_87A01330->unk_024 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(arg0++, (u32)D_87A01330->unk_060 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    return arg0;
}

Gfx* func_87A00098(Gfx* arg0, Mtx* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, void* arg6, s32 arg7, s32 arg8) {
    Mtx spD8;
    Mtx sp98;
    UNUSED Mtx sp58;
    Mtx* temp_s1 = (Mtx*)func_80005F5C(sizeof(Mtx));

    guTranslate(&spD8, arg2, arg3, arg4);
    guScale(&sp98, arg5, arg5, arg5);
    guMtxCatL(&sp98, &spD8, temp_s1);
    guMtxCatL(arg1, temp_s1, temp_s1);

    gDPLoadTextureTile(arg0++, arg6, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg7, arg7, 0, 0, arg7 - 1, arg8 - 1, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPMatrix(arg0++, temp_s1, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(arg0++, D_87A01200);
    gSPPopMatrix(arg0++, G_MTX_MODELVIEW);

    return arg0;
}

Gfx* func_87A00268(Gfx* arg0, Mtx* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8,
                   u8* arg9) {
    s32 i;
    Mtx spE8;
    Mtx spA8;
    UNUSED Mtx sp68;
    Mtx* temp_s1;
    Vtx* temp_v0;
    Vtx* ptr1;

    temp_s1 = func_80005F5C(sizeof(Mtx) * 1);
    temp_v0 = func_80005F5C(sizeof(Vtx) * 4);

    ptr1 = temp_v0;
    for (i = 0; i < 4; i++, ptr1++, arg9 += 4) {
        *ptr1 = D_87A01268[i];

        ptr1->v.cn[0] = arg9[0];
        ptr1->v.cn[1] = arg9[1];
        ptr1->v.cn[2] = arg9[2];
        ptr1->v.cn[3] = arg9[3];
    }

    guTranslate(&spE8, arg2, arg3, arg4);
    guScale(&spA8, arg5, arg5, arg5);
    guMtxCatL(&spA8, &spE8, temp_s1);
    guMtxCatL(arg1, temp_s1, temp_s1);

    gDPPipeSync(arg0++);
    gDPLoadTextureTile(arg0++, arg6, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg7, arg7, 0, 0, arg7 - 1, arg8 - 1, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPMatrix(arg0++, temp_s1, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(arg0++, D_87A012A8);
    gSPVertex(arg0++, temp_v0, 4, 0);
    gSP2Triangles(arg0++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSPPopMatrix(arg0++, G_MTX_MODELVIEW);

    return arg0;
}

void func_87A005BC(u32* arg0, s16 arg1, s16 arg2, f32 arg3) {
    Gfx* gfx = gDisplayListHead;

    if (arg3 != 0.0f) {
        u16 arg_1 = arg1 << 2;
        u16 arg_2 = arg2 << 2;
        u16 new_var3 = (arg_1 + (128.0f * arg3));
        u16 new_var2 = arg_2 + (96.0f * arg3);
        u16 new_var = 1024.0f / arg3;

        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPSetTextureLOD(gfx++, G_TL_TILE);
        gDPSetTextureFilter(gfx++, G_TF_BILERP);
        gDPSetTextureConvert(gfx++, G_TC_FILT);
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        gDPSetTexturePersp(gfx++, G_TP_NONE);

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, arg_1, arg_2, (u16)new_var3, (u16)new_var2, G_TX_RENDERTILE, 0, 0, new_var, new_var);

        gDisplayListHead = gfx;
    }
}

void func_87A009F0(s32 arg0) {
    s32 i;
    Gfx* gfx = gDisplayListHead;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_ZBUFFER);
    gSPClearGeometryMode(gfx++, G_ZBUFFER - 1);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);

    for (i = 0; i < 40; i++) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, arg0 + (i * 0xF00), G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 6, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, 0, (i * 6) << 2, 0x0500, ((i + 1) * 6) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
    }

    gDisplayListHead = gfx;
}

#ifdef NON_MATCHING
void func_87A00DB8(s32 arg0) {
    Gfx* gfx = gDisplayListHead;
    s32 i;
    s32 j;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_ZBUFFER);
    gSPClearGeometryMode(gfx++, G_ZBUFFER - 1);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);

    for (i = 0; i < 15; i++) {
        s32 sp44 = arg0 + ((i * 0x14) << 9);

        for (j = 0; j < 20; j++, sp44 += 0x200) {
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, sp44, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (j * 0x10) << 2, (i * 0x10) << 2, ((j + 1) * 0x10) << 2, ((i + 1) * 0x10) << 2,
                                G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        }
    }

    gDisplayListHead = gfx;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/4/fragment4/func_87A00DB8.s")
#endif

typedef void (*ret_func_87A010C8)(void);

ret_func_87A010C8 func_87A010C8(void) {
    return func_87A010C8;
}

s32 func_87A010D4(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret = 0;

    if (D_8780FC92 == 0) {
        ret = func_8004D9B0(arg0, arg1, arg2);
    }

    return ret;
}
