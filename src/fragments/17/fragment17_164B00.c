#include "fragment17.h"
#include "src/1CF30.h"
#include "src/6A40.h"
#include "src/6BC0.h"

void func_86B05170(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 width, u8 height, u8 uls, u8 ult, u8 lrs,
                   u8 lrt, u8 argB, u8 argC, unk_D_86B0DAE0* argD, s32 argE) {
    unk_D_80068BB0* temp_s1 = func_8000648C();
    Vtx* temp_s6 = func_80005F5C(sizeof(Vtx) * 4);
    Mtx* spD4 = func_80005F5C(sizeof(Mtx) * 1);
    Vp* temp_v0 = func_80005F5C(sizeof(Vp) * 1);

    func_8001E6E8(temp_v0, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF);

    guOrtho(spD4, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    if (argE != 0) {
        func_8001E680(&temp_s6[0], arg1, arg2, -1, argC << 5, 0, argD->unk_00.unk_12, argD->unk_00.unk_14,
                      argD->unk_00.unk_16, 0xFF);
        func_8001E680(&temp_s6[1], arg1 + arg3, arg2, -1, argB << 5, 0, argD->unk_00.unk_12, argD->unk_00.unk_14,
                      argD->unk_00.unk_16, 0xFF);
        func_8001E680(&temp_s6[2], arg1, arg2 + arg4, -1, argC << 5, height << 5, argD->unk_00.unk_0C,
                      argD->unk_00.unk_0E, argD->unk_00.unk_10, 0xFF);
        func_8001E680(&temp_s6[3], arg1 + arg3, arg2 + arg4, -1, argB << 5, height << 5, argD->unk_00.unk_0C,
                      argD->unk_00.unk_0E, argD->unk_00.unk_10, 0xFF);
    } else {
        func_8001E680(&temp_s6[0], arg1, arg2, -1, argC << 5, 0, argD->unk_00.unk_0C, argD->unk_00.unk_0E,
                      argD->unk_00.unk_10, 0xFF);
        func_8001E680(&temp_s6[1], arg1 + arg3, arg2, -1, argB << 5, 0, argD->unk_00.unk_0C, argD->unk_00.unk_0E,
                      argD->unk_00.unk_10, 0xFF);
        func_8001E680(&temp_s6[2], arg1, arg2 + arg4, -1, argC << 5, height << 5, argD->unk_00.unk_12,
                      argD->unk_00.unk_14, argD->unk_00.unk_16, 0xFF);
        func_8001E680(&temp_s6[3], arg1 + arg3, arg2 + arg4, -1, argB << 5, height << 5, argD->unk_00.unk_12,
                      argD->unk_00.unk_14, argD->unk_00.unk_16, 0xFF);
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0, COMBINED, 0,
                      SHADE, 0, 0, 0, 0, COMBINED);
    gDPSetRenderMode(gDisplayListHead++, G_RM_PASS, G_RM_XLU_SURF2);
    gDPSetEnvColor(gDisplayListHead++, argD->unk_00.unk_06, argD->unk_00.unk_08, argD->unk_00.unk_0A, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, argD->unk_00.unk_00, argD->unk_00.unk_02, argD->unk_00.unk_04, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureTile(gDisplayListHead++, arg0, G_IM_FMT_IA, G_IM_SIZ_8b, width, height, uls, ult, lrs - 1, lrt - 1, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)spD4 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s6 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
    gSPDisplayList(gDisplayListHead++, D_8006F630);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void func_86B05944(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    unk_D_80068BB0* temp_s1 = func_8000648C();
    Vtx* temp_s2 = func_80005F5C(sizeof(Vtx) * 4);
    Mtx* sp84 = func_80005F5C(sizeof(Mtx) * 1);
    Vp* sp80 = func_80005F5C(sizeof(Vp) * 1);

    func_8001E6E8(sp80, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp80 & 0x1FFFFFFF);

    guOrtho(sp84, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    func_8001E680(&temp_s2[0], arg0, arg1, -1, 0, 0, 0, 0, 0, arg4);
    func_8001E680(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, 0, 0, 0, arg4);
    func_8001E680(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);
    func_8001E680(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    gSPMatrix(gDisplayListHead++, (u32)sp84 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}
