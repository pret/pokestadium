#include "particle_math.h"

static Gfx D_8140DA50[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPNoOp(),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK),
    gsSPClearGeometryMode(G_FOG | G_LIGHTING),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_8140DAE0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPSetAlphaDither(G_AD_PATTERN),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK),
    gsSPEndDisplayList(),
};

Gfx D_8140DB30[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK),
    gsSPClearGeometryMode(G_FOG | G_LIGHTING),
    gsSPEndDisplayList(),
};

static Gfx D_8140DB80[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPEndDisplayList(),
};

Gfx gDL_ItemIcon[] = {
    gsSPDisplayList(D_8140DB80),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_PASS2),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

static Gfx D_8140DBD0[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};

Gfx D_8140DC00[] = {
    gsSPDisplayList(D_8140DBD0),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

static Gfx D_8140DC20[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_PASS2),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};

Gfx D_8140DC58[] = {
    gsSPDisplayList(D_8140DC20),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
    gsSPEndDisplayList(),
};

Gfx D_8140DC78[] = {
    gsSPDisplayList(D_8140DC20),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
    gsSPEndDisplayList(),
};

Gfx D_8140DC98[] = {
    gsSPDisplayList(D_8140DC20),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetRenderMode(G_RM_PASS, G_RM_CLD_SURF2),
    gsSPEndDisplayList(),
};

Gfx D_8140DCB8[] = {
    gsSPDisplayList(D_8140DC20),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
    gsSPEndDisplayList(),
};

Gfx D_8140DCD8[] = {
    gsSPDisplayList(D_8140DC20),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
    gsSPEndDisplayList(),
};

Gfx D_8140DCF8[] = {
    gsSPDisplayList(D_8140DC20),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_XLU_SURF2),
    gsSPEndDisplayList(),
};

Gfx D_8140DD18[] = {
    gsSPDisplayList(D_8140DC20),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_XLU_SURF2),
    gsSPEndDisplayList(),
};

Gfx D_8140DD38[] = {
    gsSPDisplayList(D_8140DC20),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsSPEndDisplayList(),
};

Gfx D_8140DD58[] = {
    gsSPDisplayList(D_8140DC20),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsSPEndDisplayList(),
};

Gfx gDL_BeginUIOverlay[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};

Gfx gDL_EndColorFill[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};

Gfx gDL_BeginColorFill[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PASS2),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_XLU_SURF2),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPEndDisplayList(),
};

static Gfx D_8140DE30[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_COPY),
    gsSPEndDisplayList(),
};

static Gfx D_8140DE48[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPEndDisplayList(),
};

static Gfx D_8140DE60[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPEndDisplayList(),
};

Vtx D_8140DE78[] = {
    VTX(-4, -4, 0, 0, 224, 0xFF, 0xFF, 0xFF, 0xFF), VTX(3, -4, 0, 224, 224, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(3, 3, 0, 224, 0, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-4, 3, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-4, -8, 0, 0, 480, 0xFF, 0xFF, 0xFF, 0xFF), VTX(3, -8, 0, 224, 480, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(3, 7, 0, 224, 0, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-4, 7, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140DEF8[] = {
    VTX(-8, -8, 0, 0, 480, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(7, -8, 0, 480, 480, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(7, 7, 0, 480, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-8, 7, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-8, -8, 0, 480, 480, 0xFF, 0xFF, 0xFF, 0xFF), VTX(7, -8, 0, 0, 480, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(7, 7, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-8, 7, 0, 480, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx gVtx_UI_TriangleSmall[] = {
    VTX(0, 0, 0, 224, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(7, 255, 0, 480, 8160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-8, 255, 0, 0, 8160, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx gVtx_UI_TriangleLarge[] = {
    VTX(0, 0, 0, 224, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(31, 255, 0, 480, 8160, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 255, 0, 0, 8160, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140DFD8[] = {
    VTX(-12, -12, 0, 0, 736, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(11, -12, 0, 736, 736, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(11, 11, 0, 736, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-12, 11, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140E018[] = {
    VTX(-16, -16, 0, 0, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, -16, 0, 992, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 15, 0, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140E058[] = {
    VTX(-16, 0, 0, 0, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 0, 0, 992, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 31, 0, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 31, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx gVtx_UI_RectVertical[] = {
    VTX(0, -16, 0, 0, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(31, -16, 0, 992, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(31, 15, 0, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140E0D8[] = {
    VTX(0, 18, 0, 480, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, -9, 0, 992, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, -9, 0, 0, 992, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140E108[] = {
    VTX(-16, -16, 0, 0, 992, 0xFF, 0x00, 0x00, 0xFF),
    VTX(15, -16, 0, 992, 992, 0xFF, 0xFF, 0x00, 0xFF),
    VTX(15, 15, 0, 992, 0, 0x00, 0xFF, 0x00, 0xFF),
    VTX(-16, 15, 0, 0, 0, 0x00, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140E148[] = {
    VTX(0, 18, 0, 480, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, -9, 0, 992, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, -9, 0, 0, 992, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140E178[] = {
    VTX(-16, -32, 0, 0, 2016, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, -32, 0, 992, 2016, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 31, 0, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 31, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140E1B8[] = {
    VTX(-16, 0, 0, 0, 2016, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 0, 0, 992, 2016, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 63, 0, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 63, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140E1F8[] = {
    VTX(-16, -16, 0, 0, 2016, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, -16, 0, 992, 2016, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 15, 0, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx gVtx_UI_ComplexQuad[] = {
    VTX(-16, -48, 0, 0, 3040, 0xFF, 0xFF, 0xFF, 0xFF), VTX(15, -48, 0, 992, 3040, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(15, 47, 0, 992, 0, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(-16, 47, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -16, 0, 0, 992, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(31, -16, 0, 2016, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(31, 15, 0, 2016, 0, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-32, 15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140E2B8[] = {
    VTX(-32, -32, 0, 0, 2016, 0xFF, 0xFF, 0xFF, 0xFF), VTX(31, -32, 0, 2016, 2016, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(31, 31, 0, 2016, 0, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-32, 31, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 0, 0, 0, 992, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(31, 0, 0, 2016, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(31, 31, 0, 2016, 0, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-32, 31, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -31, 0, 0, 992, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(31, -31, 0, 2016, 992, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(31, 0, 0, 2016, 0, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(-32, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

Vtx D_8140E378[] = {
    VTX(-64, 0, 63, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(63, 0, 63, 4064, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(63, 0, -64, 4064, 4064, 0x00, 0x00, 0x78, 0xFF),
    VTX(-64, 0, -64, 0, 4064, 0x00, 0x00, 0x78, 0xFF),
};

Vtx gFullscreenQuadVtx[] = {
    VTX(-160, -120, 0, 0, 1024, 0x00, 0x00, 0x78, 0xFF),
    VTX(160, -120, 0, 1024, 1024, 0x00, 0x00, 0x78, 0xFF),
    VTX(160, 120, 0, 1024, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-160, 120, 0, 0, 0, 0x00, 0x00, 0x78, 0xFF),
};

static Gfx D_8140E3F8[] = {
    gsSP1Triangle(0, 1, 2, 0),
    gsSPEndDisplayList(),
};

static Gfx D_8140E408[] = {
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx gDL_PanelBackground[] = {
    gsSPVertex(D_8140E148, 4, 0),
    gsSPDisplayList(D_8140E3F8),
    gsSPEndDisplayList(),
};

Gfx D_8140E430[] = {
    gsSPVertex(D_8140DEF8, 4, 0),
    gsSPDisplayList(D_8140E408),
    gsSPEndDisplayList(),
};

Gfx D_8140E448[] = {
    gsSPVertex(D_8140E018, 4, 0),
    gsSPDisplayList(D_8140E408),
    gsSPEndDisplayList(),
};

void ParticleGfx_PipeSync(void) {
    gDPPipeSync(gDisplayListHead++);
}

void ParticleGfx_SetTextureState(void) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
}

s32 ParticleGfx_TextureSizeLog2(s32 size) {
    s32 size_log2 = 0;

    do {
        size_log2++;
        size /= 2;
    } while (size != 1);

    return size_log2;
}

void ParticleGfx_NoopStub2(void) {
}

void ParticleGfx_NoopStub3(void) {
}

void ParticleGfx_NoopStub4(void) {
}

void ParticleGfx_NoopStub5(void) {
}

void ParticleGfx_NoopStub6(void) {
}

void ParticleGfx_NoopStub7(void) {
}

void ParticleGfx_NoopStub8(void) {
}

void ParticleGfx_NoopStub9(void) {
}

void ParticleGfx_LoadTextureBlock32(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                   s32 shiftt) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, fmt, G_IM_SIZ_32b, width, height, 0, cms, cmt, masks, maskt,
                        shifts, shiftt);
}

void ParticleGfx_LoadTextureTile32(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                   s32 shiftt) {
    gDPLoadTextureTile(gDisplayListHead++, texture, fmt, G_IM_SIZ_32b, width, 0, 0, 0, width - 1, height - 1, 0, cms,
                       cmt, masks, maskt, shifts, shiftt);
}

void ParticleGfx_LoadTextureBlock16(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                   s32 shiftt) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, fmt, G_IM_SIZ_16b, width, height, 0, cms, cmt, masks, maskt,
                        shifts, shiftt);
}

void ParticleGfx_LoadTextureTile16(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                   s32 shiftt) {
    gDPLoadTextureTile(gDisplayListHead++, texture, fmt, G_IM_SIZ_16b, width, 0, 0, 0, width - 1, height - 1, 0, cms,
                       cmt, masks, maskt, shifts, shiftt);
}

void ParticleGfx_LoadTextureBlock8(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                   s32 shiftt) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, fmt, G_IM_SIZ_8b, width, height, 0, cms, cmt, masks, maskt, shifts,
                        shiftt);
}

void ParticleGfx_LoadTextureTile8(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                   s32 shiftt) {
    gDPLoadTextureTile(gDisplayListHead++, texture, fmt, G_IM_SIZ_8b, width, 0, 0, 0, width - 1, height - 1, 0, cms,
                       cmt, masks, maskt, shifts, shiftt);
}

void ParticleGfx_LoadTextureBlock4(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                   s32 shiftt) {
    gDPLoadTextureBlock_4b(gDisplayListHead++, texture, fmt, width, height, 0, cms, cmt, masks, maskt, shifts, shiftt);
}

void ParticleGfx_LoadTextureTile4(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                   s32 shiftt) {
    gDPLoadTextureTile_4b(gDisplayListHead++, texture, fmt, width, 0, 0, 0, width - 1, height - 1, 0, cms, cmt, masks,
                          maskt, shifts, shiftt);
}

void ParticleGfx_LoadTextureMultiBlock4(u8* texture, s32 tmem, s32 rtile, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks,
                   s32 maskt, s32 shifts, s32 shiftt) {
    gDPLoadMultiBlock_4b(gDisplayListHead++, texture, tmem, rtile, fmt, width, height, 0, cms, cmt, masks, maskt,
                         shifts, shiftt);
}

void ParticleGfx_LoadTextureRgba32(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureBlock32(texture, G_IM_FMT_RGBA, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureTileRgba32(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureTile32(texture, G_IM_FMT_RGBA, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureRgba16(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureBlock16(texture, G_IM_FMT_RGBA, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureRgba16Dual(u8* texture1, u8* texture2, s32 width, s32 height) {
    gDPLoadMultiTile(gDisplayListHead++, texture1, 0x000, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height,
                     0, 0, width - 1, height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gDPLoadMultiTile(gDisplayListHead++, texture2, 0x100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0, 0,
                     width - 1, height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                     G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureRgba16WrapS(u8* texture, s32 width, s32 height) {
    s32 masks = ParticleGfx_TextureSizeLog2(width);

    ParticleGfx_LoadTextureBlock16(texture, G_IM_FMT_RGBA, width, height, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, masks,
                  G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureRgba16WrapT(u8* texture, s32 width, s32 height) {
    s32 maskt = ParticleGfx_TextureSizeLog2(height);

    ParticleGfx_LoadTextureBlock16(texture, G_IM_FMT_RGBA, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_WRAP,
                  G_TX_NOMASK, maskt, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureRgba16WrapST(u8* texture, s32 width, s32 height) {
    s32 masks = ParticleGfx_TextureSizeLog2(width);
    s32 maskt = ParticleGfx_TextureSizeLog2(height);

    ParticleGfx_LoadTextureBlock16(texture, G_IM_FMT_RGBA, width, height, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, masks, maskt,
                  G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureRgba16WrapSWithMask(u8* texture, s32 width, s32 height, s32 masks) {
    ParticleGfx_LoadTextureBlock16(texture, G_IM_FMT_RGBA, width, height, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, masks,
                  G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureTileRgba16(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureTile16(texture, G_IM_FMT_RGBA, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureIa16(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureBlock16(texture, G_IM_FMT_IA, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureTileIa16(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureTile16(texture, G_IM_FMT_IA, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureIa8(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureBlock8(texture, G_IM_FMT_IA, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureTileIa8(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureTile8(texture, G_IM_FMT_IA, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureIa8WrapST(u8* texture, s32 width, s32 height) {
    s32 masks = ParticleGfx_TextureSizeLog2(width);
    s32 maskt = ParticleGfx_TextureSizeLog2(height);

    ParticleGfx_LoadTextureBlock8(texture, G_IM_FMT_IA, width, height, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, masks, maskt,
                  G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureI8(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureBlock8(texture, G_IM_FMT_I, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureI8WrapST(u8* texture, s32 width, s32 height) {
    s32 masks = ParticleGfx_TextureSizeLog2(width);
    s32 maskt = ParticleGfx_TextureSizeLog2(height);

    ParticleGfx_LoadTextureBlock8(texture, G_IM_FMT_I, width, height, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, masks, maskt,
                  G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureTileI8(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureTile8(texture, G_IM_FMT_I, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureI8Alias(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureI8(texture, width, height);
}

void ParticleGfx_LoadTextureTileI8Alias(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureTileI8(texture, width, height);
}

void ParticleGfx_LoadTextureTileIa4(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureTile4(texture, G_IM_FMT_IA, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureTileI4(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureTile4(texture, G_IM_FMT_I, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureIa4(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureBlock4(texture, G_IM_FMT_IA, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureI4(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureBlock4(texture, G_IM_FMT_I, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureI4WrapST(u8* texture, s32 width, s32 height) {
    s32 masks = ParticleGfx_TextureSizeLog2(width);
    s32 maskt = ParticleGfx_TextureSizeLog2(height);

    ParticleGfx_LoadTextureBlock4(texture, G_IM_FMT_I, width, height, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, masks, maskt,
                  G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureI4Alias(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureI4(texture, width, height);
}

void ParticleGfx_LoadTextureTileI4Alias(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureTileI4(texture, width, height);
}

void ParticleGfx_LoadTextureI4WrapS(u8* texture, s32 width, s32 height) {
    s32 masks = ParticleGfx_TextureSizeLog2(width);

    ParticleGfx_LoadTextureBlock4(texture, G_IM_FMT_I, width, height, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, masks,
                  G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureI4WrapSTNoMirror(u8* texture, s32 width, s32 height) {
    s32 masks = ParticleGfx_TextureSizeLog2(width);
    s32 maskt = ParticleGfx_TextureSizeLog2(height);

    ParticleGfx_LoadTextureBlock4(texture, G_IM_FMT_I, width, height, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, masks,
                  maskt, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureI4MultiBlockWrapST(u8* texture, s32 width, s32 height) {
    s32 tmem = 0x100;
    s32 rtile = 1;
    s32 masks = ParticleGfx_TextureSizeLog2(width);
    s32 maskt = ParticleGfx_TextureSizeLog2(height);

    ParticleGfx_LoadTextureMultiBlock4(texture, tmem, rtile, G_IM_FMT_I, width, height, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                  masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureI4MultiBlockWrapSTWithShift(u8* texture, s32 width, s32 height, s32 shifts, s32 shiftt) {
    s32 tmem = 0x100;
    s32 rtile = 1;
    s32 masks = ParticleGfx_TextureSizeLog2(width);
    s32 maskt = ParticleGfx_TextureSizeLog2(height);

    ParticleGfx_LoadTextureMultiBlock4(texture, tmem, rtile, G_IM_FMT_I, width, height, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                  masks, maskt, shifts, shiftt);
}

void ParticleGfx_LoadTextureCi8(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureBlock8(texture, G_IM_FMT_CI, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureCi8WrapSWithMask(u8* texture, s32 width, s32 height, s32 masks) {
    ParticleGfx_LoadTextureBlock8(texture, G_IM_FMT_CI, width, height, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, masks,
                  G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureTileCi8(u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureTile8(texture, G_IM_FMT_CI, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void ParticleGfx_LoadTextureDualRgba16I8(u8* texture1, u8* texture2, s32 width, s32 height) {
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

    gDPLoadMultiBlock(gDisplayListHead++, texture2, 0x100, G_TX_RENDERTILE, G_IM_FMT_I, G_IM_SIZ_8b, width, height, 0,
                      G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                      G_TX_NOLOD);

    gDPLoadTextureBlock(gDisplayListHead++, texture1, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0,
                        G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gDPSetTile(gDisplayListHead++, G_IM_FMT_I, G_IM_SIZ_8b, ((width) + 7) >> 3, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

    gDPSetTileSize(gDisplayListHead++, 1, 0, 0, (width - 1) << 2, (height - 1) << 2);
}

void ParticleGfx_DrawQuadVertices(Vtx* arg0) {
    gSPVertex(gDisplayListHead++, arg0, 4, 0);
    gSPDisplayList(gDisplayListHead++, D_8140E408);
}

void ParticleGfx_NoopStub10(void) {
}

void ParticleGfx_DrawTransformedQuad(Vec3f arg0, Vec3s arg1, f32 arg2, Vtx* arg3) {
    ParticleGfx_PushTransformMatrix(arg0, arg1, arg2);

    gSPVertex(gDisplayListHead++, arg3, 4, 0);
    gSPDisplayList(gDisplayListHead++, D_8140E408);
}

void ParticleGfx_DrawTransformedQuadYScaled(Vec3f arg0, Vec3s arg1, f32 arg3, Vtx* arg4) {
    ParticleGfx_PushTransformMatrixYScaled(arg0, arg1, arg3);

    gSPVertex(gDisplayListHead++, arg4, 4, 0);
    gSPDisplayList(gDisplayListHead++, D_8140E408);
}

void ParticleGfx_DrawTransformedQuadXYScaled(Vec3f arg0, Vec3s arg1, f32 arg2, f32 arg3, Vtx* arg4) {
    ParticleGfx_PushTransformMatrixXYScaled(arg0, arg1, arg2, arg3);

    gSPVertex(gDisplayListHead++, arg4, 4, 0);
    gSPDisplayList(gDisplayListHead++, D_8140E408);
}

void ParticleGfx_DrawTransformedTriangle(Vec3f arg0, Vec3s arg1, f32 arg2, Vtx* arg3) {
    ParticleGfx_PushTransformMatrix(arg0, arg1, arg2);

    gSPVertex(gDisplayListHead++, arg3, 3, 0);
    gSPDisplayList(gDisplayListHead++, D_8140E3F8);
}

void ParticleGfx_DrawModelQuad(CameraNode* arg0, Vec3f arg1, f32 arg2, Vtx* arg3) {
    ParticleGfx_PushBillboardMatrix(arg0, arg1, arg2);

    gSPVertex(gDisplayListHead++, arg3, 4, 0);
    gSPDisplayList(gDisplayListHead++, D_8140E408);
}

void ParticleGfx_DrawModelQuadRotated(CameraNode* arg0, Vec3f arg1, f32 arg2, Vtx* arg3, s16 arg4) {
    ParticleGfx_PushBillboardRotatedMatrix(arg0, arg1, arg2, arg4);

    gSPVertex(gDisplayListHead++, arg3, 4, 0);
    gSPDisplayList(gDisplayListHead++, D_8140E408);
}

void ParticleGfx_DrawModelQuadYScaled(CameraNode* arg0, Vec3f arg1, f32 arg2, Vtx* arg3) {
    ParticleGfx_PushBillboardMatrixYScaled(arg0, arg1, arg2);

    gSPVertex(gDisplayListHead++, arg3, 4, 0);
    gSPDisplayList(gDisplayListHead++, D_8140E408);
}

void ParticleGfx_DrawModelQuadRotatedYScaled(CameraNode* arg0, Vec3f arg1, f32 arg2, Vtx* arg3, s16 arg4) {
    ParticleGfx_PushBillboardRotatedMatrixYScaled(arg0, arg1, arg2, arg4);

    gSPVertex(gDisplayListHead++, arg3, 4, 0);
    gSPDisplayList(gDisplayListHead++, D_8140E408);
}

void ParticleGfx_DrawModelTriangle(CameraNode* arg0, Vec3f arg1, f32 arg2, Vtx* arg3) {
    ParticleGfx_PushBillboardMatrix(arg0, arg1, arg2);

    gSPVertex(gDisplayListHead++, arg3, 3, 0);
    gSPDisplayList(gDisplayListHead++, D_8140E3F8);
}

void ParticleGfx_DrawModelTriangleRotated(CameraNode* arg0, Vec3f arg1, f32 arg2, Vtx* arg3, s16 arg4) {
    ParticleGfx_PushBillboardRotatedMatrix(arg0, arg1, arg2, arg4);

    gSPVertex(gDisplayListHead++, arg3, 3, 0);
    gSPDisplayList(gDisplayListHead++, D_8140E3F8);
}

void ParticleGfx_DrawI8TextureAtlas(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 i;
    s32 j;
    s32 var_s4 = 0;
    u8* var_s3 = texture;

    for (i = 0; i < arg3 / height; i++) {
        for (j = 0; j < arg2 / width; j++) {
            ParticleGfx_LoadTextureI8(var_s3, width, height);

            gSPVertex(gDisplayListHead++, &vtx[var_s4], 4, 0);
            gSPDisplayList(gDisplayListHead++, D_8140E408);

            var_s3 += width * height;
            var_s4 += 4;
        }
    }

    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
}

void ParticleGfx_DrawIa16TextureAtlas(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 i;
    s32 j;
    s32 var_s4 = 0;
    u8* var_s3 = texture;

    for (i = 0; i < arg3 / height; i++) {
        for (j = 0; j < arg2 / width; j++) {
            ParticleGfx_LoadTextureIa16(var_s3, width, height);

            gSPVertex(gDisplayListHead++, &vtx[var_s4], 4, 0);
            gSPDisplayList(gDisplayListHead++, D_8140E408);

            var_s3 += (width * height) * 2;
            var_s4 += 4;
        }
    }

    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
}

void ParticleGfx_DrawIa8TextureAtlas(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 i;
    s32 j;
    s32 var_s4 = 0;
    u8* var_s3 = texture;

    for (i = 0; i < arg3 / height; i++) {
        for (j = 0; j < arg2 / width; j++) {
            ParticleGfx_LoadTextureIa8(var_s3, width, height);

            gSPVertex(gDisplayListHead++, &vtx[var_s4], 4, 0);
            gSPDisplayList(gDisplayListHead++, D_8140E408);

            var_s3 += width * height;
            var_s4 += 4;
        }
    }

    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
}

void ParticleGfx_DrawI4TextureAtlas(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 i;
    s32 j;
    s32 var_s4 = 0;
    u8* var_s3 = texture;

    for (i = 0; i < arg3 / height; i++) {
        for (j = 0; j < arg2 / width; j++) {
            ParticleGfx_LoadTextureI4(var_s3, width, height);

            gSPVertex(gDisplayListHead++, &vtx[var_s4], 4, 0);
            gSPDisplayList(gDisplayListHead++, D_8140E408);

            var_s3 += (width * height) / 2;
            var_s4 += 4;
        }
    }

    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
}

void ParticleGfx_DrawI4TextureAtlasTiled(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 i;
    s32 j;
    s32 var_s4 = 0;
    u8* var_s3 = texture;

    for (i = 0; i < arg3 / height; i++) {
        for (j = 0; j < arg2 / width; j++) {
            ParticleGfx_LoadTextureTileI4(var_s3, width, height);

            gSPVertex(gDisplayListHead++, &vtx[var_s4], 4, 0);
            gSPDisplayList(gDisplayListHead++, D_8140E408);

            var_s3 += (width * height) / 2;
            var_s4 += 4;
        }
    }

    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
}

void ParticleGfx_SetPrimColor(u8 r, u8 g, u8 b, u8 a) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, r, g, b, a);
}

void ParticleGfx_SetEnvColor(u8 r, u8 g, u8 b, u8 a) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, r, g, b, a);
}

void ParticleGfx_SetFogColor(u8 r, u8 g, u8 b, u8 a) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetFogColor(gDisplayListHead++, r, g, b, a);
}

void ParticleGfx_SetBlendColor(u8 r, u8 g, u8 b, u8 a) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetBlendColor(gDisplayListHead++, r, g, b, a);
}

void ParticleGfx_SetPrimColorTextureCombine(u8 r, u8 g, u8 b, u8 a) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, r, g, b, a);
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0,
                      COMBINED);
}

void ParticleGfx_SetTextureAlphaCombine(u8 a) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, a);
    gDPSetCombineLERP(gDisplayListHead++, SHADE, 0, TEXEL0, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0,
                      COMBINED);
}

void ParticleGfx_SetPrimEnvColorCombine(u8 prim_r, u8 prim_g, u8 prim_b, u8 env_r, u8 env_g, u8 env_b, u8 prim_a) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, prim_r, prim_g, prim_b, prim_a);
    gDPSetEnvColor(gDisplayListHead++, env_r, env_g, env_b, 0);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0,
                      COMBINED, 0, 0, 0, COMBINED);
}

void ParticleGfx_SetPrimEnvNoiseCombine(u8 prim_r, u8 prim_g, u8 prim_b, u8 env_r, u8 env_g, u8 env_b, u8 prim_a) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, prim_r, prim_g, prim_b, prim_a);
    gDPSetEnvColor(gDisplayListHead++, env_r, env_g, env_b, 255);
    gDPSetCombineLERP(gDisplayListHead++, NOISE, 0, ENV_ALPHA, 0, 0, 0, 0, TEXEL0, PRIMITIVE, ENVIRONMENT, COMBINED,
                      ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0);
}

void ParticleGfx_SetPrimEnvColorShadeCombine(u8 prim_r, u8 prim_g, u8 prim_b, u8 prim_a, u8 env_r, u8 env_g, u8 env_b, u8 env_a) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, prim_r, prim_g, prim_b, prim_a);
    gDPSetEnvColor(gDisplayListHead++, env_r, env_g, env_b, env_a);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                      COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
}

void ParticleGfx_SetPrimEnvLodCombine(u8 l, u8 prim_r, u8 prim_g, u8 prim_b, u8 prim_a, u8 env_r, u8 env_g, u8 env_b) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetPrimColor(gDisplayListHead++, 0, l, prim_r, prim_g, prim_b, prim_a);
    gDPSetEnvColor(gDisplayListHead++, env_r, env_g, env_b, 0);
    gDPSetCombineLERP(gDisplayListHead++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0,
                      PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0);
}

void ParticleGfx_SetPrimEnvLodTextureCombine(u8 l, u8 prim_r, u8 prim_g, u8 prim_b, u8 prim_a, u8 env_r, u8 env_g, u8 env_b) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetPrimColor(gDisplayListHead++, 0, l, prim_r, prim_g, prim_b, prim_a);
    gDPSetEnvColor(gDisplayListHead++, env_r, env_g, env_b, 0);
    gDPSetCombineLERP(gDisplayListHead++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, PRIMITIVE,
                      ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0);
}

u32 ParticleGfx_GetFrameDivisor(s32 arg0) {
    u32 ret = gParticleFrameCounter;

    switch (arg0) {
        case 2:
            ret = gParticleFrameDiv2;
            break;

        case 3:
            ret = gParticleFrameDiv3;
            break;

        case 4:
            ret = gParticleFrameDiv4;
            break;
    }

    return ret;
}

void ParticleGfx_SetAnimatedTileSize(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, arg0 * gParticleFrameCounter, -arg1 * gParticleFrameCounter,
                   (((arg0 * gParticleFrameCounter) + arg2) - 1) << 2, (((-arg1 * gParticleFrameCounter) + arg3) - 1) << 2);
}

void ParticleGfx_SetAnimatedAuxTileSize(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    gDPSetTileSize(gDisplayListHead++, 1, arg0 * gParticleFrameCounter, -arg1 * gParticleFrameCounter,
                   (((arg0 * gParticleFrameCounter) + arg2) - 1) << 2, (((-arg1 * gParticleFrameCounter) + arg3) - 1) << 2);
}

void ParticleGfx_SetAnimatedTileSizeOnList(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    gDPSetTileSize(gfx, G_TX_RENDERTILE, arg1 * gParticleFrameCounter, -arg2 * gParticleFrameCounter, (((arg1 * gParticleFrameCounter) + arg3) - 1) << 2,
                   (((-arg2 * gParticleFrameCounter) + arg4) - 1) << 2);
}

void ParticleGfx_SetAnimatedAuxTileSizeOnList(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    gDPSetTileSize(gfx, 1, arg1 * gParticleFrameCounter, -arg2 * gParticleFrameCounter, (((arg1 * gParticleFrameCounter) + arg3) - 1) << 2,
                   (((-arg2 * gParticleFrameCounter) + arg4) - 1) << 2);
}

void ParticleGfx_SetPartiallyAnimatedTileSize(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    gDPSetTileSize(gfx, G_TX_RENDERTILE, arg1, -arg2 * gParticleFrameCounter, ((arg3 + arg1) - 1) << 2,
                   (((-arg2 * gParticleFrameCounter) + arg4) - 1) << 2);
}

void ParticleGfx_SetPartiallyAnimatedAuxTileSize(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    gDPSetTileSize(gfx, 1, arg1, -arg2 * gParticleFrameCounter, ((arg3 + arg1) - 1) << 2,
                   (((-arg2 * gParticleFrameCounter) + arg4) - 1) << 2);
}

void ParticleGfx_SetFrameIndexedTileSize(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u32 temp_v0 = ParticleGfx_GetFrameDivisor(arg7);
    s32 temp_v1 = arg1 + (arg3 * temp_v0);
    s32 temp_a0 = arg2 - (arg4 * temp_v0);

    gDPSetTileSize(gfx, G_TX_RENDERTILE, temp_v1, temp_a0, ((temp_v1 + arg5) - 1) << 2, ((temp_a0 + arg6) - 1) << 2);
}

void ParticleGfx_SetFrameIndexedAuxTileSize(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u32 temp_v0 = ParticleGfx_GetFrameDivisor(arg7);
    s32 temp_v1 = arg1 + (arg3 * temp_v0);
    s32 temp_a0 = arg2 - (arg4 * temp_v0);

    gDPSetTileSize(gfx, 1, arg1 + (arg3 * temp_v0), arg2 - (arg4 * temp_v0), ((temp_v1 + arg5) - 1) << 2,
                   ((temp_a0 + arg6) - 1) << 2);
}

Gfx* ParticleGfx_LoadTextureBlock4ToList(Gfx* gfx, u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt,
                   s32 shifts, s32 shiftt) {
    gDPLoadTextureBlock_4b(gfx++, texture, fmt, width, height, 0, cms, cmt, masks, maskt, shifts, shiftt);
    return gfx;
}

void ParticleGfx_LoadTextureI4ToList(Gfx* gfx, u8* texture, s32 width, s32 height) {
    ParticleGfx_LoadTextureBlock4ToList(gfx, texture, G_IM_FMT_I, width, height, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                  G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

Gfx* ParticleGfx_LoadDescriptorTexture(Gfx* arg0, u8* texture, arg1_func_81407874_014_004* arg2, s32 tmem, s32 rtile) {
    switch (arg2->unk_04->fmt) {
        case G_IM_FMT_RGBA:
            switch (arg2->unk_04->size) {
                case G_IM_SIZ_16b:
                    gDPLoadMultiTile(arg0++, texture, tmem, rtile, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg2->unk_04->width,
                                     arg2->unk_04->height, 0, 0, arg2->unk_04->width - 1, arg2->unk_04->height - 1, 0,
                                     arg2->unk_04->cms, arg2->unk_04->cmt, arg2->unk_04->masks, arg2->unk_04->maskt,
                                     arg2->unk_04->shfits, arg2->unk_04->shiftt);
                    break;
            }
            break;

        case G_IM_FMT_IA:
            switch (arg2->unk_04->size) {
                case G_IM_SIZ_8b:
                    gDPLoadMultiTile(arg0++, texture, tmem, rtile, G_IM_FMT_IA, G_IM_SIZ_8b, arg2->unk_04->width,
                                     arg2->unk_04->height, 0, 0, arg2->unk_04->width - 1, arg2->unk_04->height - 1, 0,
                                     arg2->unk_04->cms, arg2->unk_04->cmt, arg2->unk_04->masks, arg2->unk_04->maskt,
                                     arg2->unk_04->shfits, arg2->unk_04->shiftt);
                    break;

                case G_IM_SIZ_16b:
                    gDPLoadMultiTile(arg0++, texture, tmem, rtile, G_IM_FMT_IA, G_IM_SIZ_16b, arg2->unk_04->width,
                                     arg2->unk_04->height, 0, 0, arg2->unk_04->width - 1, arg2->unk_04->height - 1, 0,
                                     arg2->unk_04->cms, arg2->unk_04->cmt, arg2->unk_04->masks, arg2->unk_04->maskt,
                                     arg2->unk_04->shfits, arg2->unk_04->shiftt);
                    break;
            }
            break;

        case G_IM_FMT_I:
            switch (arg2->unk_04->size) {
                case G_IM_SIZ_4b:
                    gDPLoadMultiTile_4b(arg0++, texture, tmem, rtile, G_IM_FMT_I, arg2->unk_04->width,
                                        arg2->unk_04->height, 0, 0, arg2->unk_04->width - 1, arg2->unk_04->height - 1,
                                        0, arg2->unk_04->cms, arg2->unk_04->cmt, arg2->unk_04->masks,
                                        arg2->unk_04->maskt, arg2->unk_04->shfits, arg2->unk_04->shiftt);
                    break;

                case G_IM_SIZ_8b:
                    gDPLoadMultiTile(arg0++, texture, tmem, rtile, G_IM_FMT_I, G_IM_SIZ_8b, arg2->unk_04->width,
                                     arg2->unk_04->height, 0, 0, arg2->unk_04->width - 1, arg2->unk_04->height - 1, 0,
                                     arg2->unk_04->cms, arg2->unk_04->cmt, arg2->unk_04->masks, arg2->unk_04->maskt,
                                     arg2->unk_04->shfits, arg2->unk_04->shiftt);
                    break;
            }
            break;
    }

    return arg0;
}

Gfx* ParticleGfx_LoadDescriptorTextureAndTile(Gfx* arg0, arg1_func_81407874_014_004* arg1, s32 tmem, s32 rtile) {
    u8* texture;
    u32 ret;

    texture = NULL;
    if (arg1->unk_0C != NULL) {
        ret = ParticleGfx_GetFrameDivisor(arg1->unk_0C->unk_06) % arg1->unk_0C->unk_04;
        texture = arg1->unk_0C->unk_00.texture[ret];
    } else if (arg1->unk_00 != NULL) {
        texture = arg1->unk_00;
    }

    if (texture != NULL) {
        arg0 = ParticleGfx_LoadDescriptorTexture(arg0, texture, arg1, tmem, rtile);
    }

    if (arg1->unk_08 != NULL) {
        switch (rtile) {
            case G_TX_RENDERTILE:
                ParticleGfx_SetFrameIndexedTileSize(arg0++, arg1->unk_08->unk_00, arg1->unk_08->unk_02, arg1->unk_08->unk_04,
                              arg1->unk_08->unk_06, arg1->unk_04->width, arg1->unk_04->height, arg1->unk_08->unk_08);
                break;

            case 1:
                ParticleGfx_SetFrameIndexedAuxTileSize(arg0++, arg1->unk_08->unk_00, arg1->unk_08->unk_02, arg1->unk_08->unk_04,
                              arg1->unk_08->unk_06, arg1->unk_04->width, arg1->unk_04->height, arg1->unk_08->unk_08);
                break;
        }
    }

    return arg0;
}

Gfx* ParticleGfx_LoadPrimaryDescriptorTexture(Gfx* arg0, arg1_func_81407874_014* arg1) {
    return ParticleGfx_LoadDescriptorTextureAndTile(arg0, arg1->unk_00, 0, G_TX_RENDERTILE);
}

Gfx* ParticleGfx_LoadSecondaryDescriptorTexture(Gfx* arg0, arg1_func_81407874_014* arg1) {
    s32 var_a2 = 0;

    if (arg1->unk_04->unk_00 != arg1->unk_00->unk_00) {
        var_a2 = 0x100;
    }
    return ParticleGfx_LoadDescriptorTextureAndTile(arg0, arg1->unk_04, var_a2, 1);
}

void ParticleGfx_SetCombineModeFromDescriptor(Gfx* arg0, arg1_func_81407874_014_000_010* arg1) {
    gDPSetCombine(arg0++,
                  GCCc0w0(arg1->unk_00, arg1->unk_02, arg1->unk_04, arg1->unk_06) | GCCc1w0(arg1->unk_08, arg1->unk_0A),

                  GCCc0w1(arg1->unk_01, arg1->unk_03, arg1->unk_05, arg1->unk_07) |
                      GCCc1w1(arg1->unk_09, arg1->unk_0C, arg1->unk_0E, arg1->unk_0B, arg1->unk_0D, arg1->unk_0F));
}

Gfx* func_81407590(Gfx* arg0, arg1_func_81407874_014* arg1) {
    arg1_func_81407874_014_000* var_a3;
    arg1_func_81407874_014_004* sp20;
    arg1_func_81407874_014_000_018_000_000* temp_v0;
    arg1_func_81407874_014_000_014_000_000* temp_v1;
    Color_RGBA8_u32 color;
    u32 ret;
    s16 sp1c;
    s16 sp18;
    s16 sp14;
    s16 sp10;

    var_a3 = arg1->unk_00;
    sp20 = arg1->unk_04;

    if (var_a3 != NULL) {
        if (var_a3->unk_10 != NULL) {
            ParticleGfx_SetCombineModeFromDescriptor(arg0++, var_a3->unk_10);
        }

        if (var_a3->unk_14 != NULL) {
            if (var_a3->unk_14->unk_04 == 0) {
                color.rgba = var_a3->unk_14->unk_00.color.rgba;
                sp1c = color.rgba >> 0x18;
                sp18 = color.rgba >> 0x10;
                sp14 = color.rgba >> 0x8;
                sp10 = color.rgba;

                gDPPipeSync(arg0++);
                gDPSetPrimColor(arg0++, 0, 0xFF, sp1c, sp18, sp14, sp10);
            } else {
                ret = ParticleGfx_GetFrameDivisor(var_a3->unk_14->unk_06) % var_a3->unk_14->unk_04;
                temp_v1 = &var_a3->unk_14->unk_00.ptr5[ret];

                gDPPipeSync(arg0++);
                gDPSetPrimColor(arg0++, 0, temp_v1->l, temp_v1->color.r, temp_v1->color.g, temp_v1->color.b,
                                temp_v1->color.a);
            }
        }

        if (var_a3->unk_18 != NULL) {
            if (var_a3->unk_18->unk_04 == 0) {
                gDPSetColor(arg0++, G_SETENVCOLOR, var_a3->unk_18->unk_00.color.rgba);
            } else {
                ret = ParticleGfx_GetFrameDivisor(var_a3->unk_18->unk_06) % var_a3->unk_18->unk_04;
                temp_v0 = &var_a3->unk_18->unk_00.ptr4[ret];

                gDPSetEnvColor(arg0++, temp_v0->color.r, temp_v0->color.g, temp_v0->color.b, temp_v0->color.a);
            }
        }

        if (var_a3->unk_1C != NULL) {
            gSPSetGeometryMode(arg0++, G_TEXTURE_GEN);
            gSPTexture(arg0++, var_a3->unk_1C->unk_00, var_a3->unk_1C->unk_02, 0, G_TX_RENDERTILE, G_ON);
        }
#if !defined(VERSION_JP)
        // JP has neither the full-scale gSPTexture used when unk_1C is NULL and unk_04 is
        // set, nor the G_TT_NONE TLUT reset for unk_04 != 0.
        else if (var_a3->unk_04 != 0) {
            gSPTexture(arg0++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        }

        if (var_a3->unk_04 != 0) {
            gDPSetTextureLUT(arg0++, G_TT_NONE);
        }
#endif

        arg0 = ParticleGfx_LoadPrimaryDescriptorTexture(arg0, arg1);
    }

    if (sp20 != NULL) {
        arg0 = ParticleGfx_LoadSecondaryDescriptorTexture(arg0, arg1);
    }

    return arg0;
}

void ParticleGfx_GraphNodeBuildDescriptorMaterialList(s32 arg0, arg1_func_87903D64* arg1) {
    if (arg0 == 5) {
        arg1_func_81407874_014* tmp = arg1->unk_14;

        gDisplayListHead = func_81407590(gDisplayListHead, tmp);
    }
}
