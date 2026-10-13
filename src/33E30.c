#include "33E30.h"
#include "src/gallery.h"
#include "src/gfx_buffer.h"
#include "src/geo_render.h"

static Gfx D_800762F0[] = {
    gsSPEndDisplayList(),
};

static Vtx D_800762F8[] = {
    VTX(0, 0, 0, 0, 0, 0x88, 0x00, 0x00, 0x80),
    VTX(-5, 15, 0, 0, 0, 0x88, 0x00, 0x00, 0x80),
    VTX(5, 15, 0, 0, 0, 0x88, 0x00, 0x00, 0x80),
};

static u8 D_80076328[] = {
    0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77,
};

static Gfx D_80076330[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPLoadTextureBlock_4b(D_80076328, G_IM_FMT_I, 4, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 2, 2,
                            G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsSPVertex(D_800762F8, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPEndDisplayList(),
};

// Format strings for the debug matrix dumps that func_80033230 and func_80033264
// once printed; the calls were optimized out, leaving the literals behind.
const char D_8007C580[0x8] = "0x%08x ";
const char D_8007C588[0x4] = "\n";
const char D_8007C58C[0x4] = "\n";
const char D_8007C590[0xC] = "%10.4f  ";
const char D_8007C59C[0x4] = "\n";
const char D_8007C5A0[0x4] = "\n";
const char D_8007C5A4[0x4] = "";
const char D_8007C5A8[0x4] = "";
const char D_8007C5AC[0x4] = "";

#if defined(VERSION_US_REV2)
#pragma GLOBAL_ASM("asm/us/nonmatchings/33E30/func_80033230.s")
#else
void func_80033230(s32 arg0) {
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 2; j++) {}
    }
}
#endif

#if defined(VERSION_US_REV2)
#pragma GLOBAL_ASM("asm/us/nonmatchings/33E30/func_80033264.s")
#pragma GLOBAL_ASM("asm/us/nonmatchings/33E30/func_80033318_us_rev2.s")
#else
void func_80033264(s32 arg0) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 0; j++) {}
    }
}
#endif

Gfx* Gfx_DrawTriangleMarker(Gfx* arg0, Vec3f* arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 arg6) {
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    Mtx* sp138;
    Mtx spF8;
    Mtx spB8;
    Mtx sp78;
    UNUSED s32 pad;
    MtxF sp34;

    sp144 = arg1->x;
    sp140 = arg1->y;
    sp13C = arg1->z;

    MtxF_ExtractScale(&sp34, &D_8006F088->unk_60.mtxf);
    guMtxF2L(&sp34, &sp78);
    guScale(&spB8, arg6, arg6, arg6);
    guTranslate(&spF8, sp144, sp140, sp13C);
    sp138 = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    guMtxCatL(&spB8, &spF8, sp138);
    guMtxCatL(&sp78, sp138, sp138);

    gSPMatrix(arg0++, sp138, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(arg0++, 0, 0, arg2, arg3, arg4, arg5);
    gSPDisplayList(arg0++, D_80076330);
    gSPPopMatrix(arg0++, G_MTX_MODELVIEW);

    return arg0;
}
