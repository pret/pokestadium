#include "fragment17.h"
#include "src/1CF30.h"
#include "src/2E110.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/controller.h"

void func_86B01C00(u8* arg0) {
    s32 i;
    s32 j;

    if (D_86B0E5DC == 0) {
        return;
    }

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGB, G_CC_DECALRGB);

    gDPPipeSync(gDisplayListHead++);

    if (0) {}

    for (i = 0; i < 15; i++) {
        for (j = 0; j < 20; j++, arg0 += 0x200) {
            func_8001C6AC(j * 16, i * 16, 0x10, 0x10, arg0, 0x10, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_86B01D8C(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, u8 arg6) {
    unk_D_80068BB0* temp_s1 = func_8000648C();
    Vtx* temp_s2 = func_80005F5C(sizeof(Vtx) * 4);
    Mtx* spCC = func_80005F5C(sizeof(Mtx) * 1);
    Vp* spC8 = func_80005F5C(sizeof(Vp));

    func_8001E6E8(spC8, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)spC8 & 0x1FFFFFFF);

    guOrtho(spCC, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    func_8001E680(&temp_s2[0], arg1, arg2, -1, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&temp_s2[1], arg1 + arg3, arg2, -1, arg5 << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&temp_s2[2], arg1, arg2 + arg4, -1, 0, arg6 << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001E680(&temp_s2[3], arg1 + arg3, arg2 + arg4, -1, arg5 << 5, arg6 << 5, 0xFF, 0xFF, 0xFF, 0xFF);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                 G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING |
                                                 0x0040F9FA);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gDPSetTextureLOD(gDisplayListHead++, G_TL_TILE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)spCC & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDPLoadTextureTile(gDisplayListHead++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg5, arg6, 0, 0, arg5 - 1, arg6 - 1, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void func_86B02348(void) {
    static s32 D_86B0BD50 = 0;

    s32 sp24;
    s16 temp_s0;

    if (!(Cont_GetControllerBits() & 1)) {
        sp24 = func_8001F5B0(4, 0, func_8002D7C0(NULL, 0, D_86B0E5E0, 0));
        temp_s0 = 0x50 - D_86B0BD50;
        if (D_86B0E5DC != 1) {
            gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 16, 0, 304, 240);

            func_8001F3F4();
            func_8001EBE0(4, 0);
            func_8001F1E8(temp_s0, 0xB3, func_8002D7C0(NULL, 0, D_86B0E5E0, 0));

            temp_s0 += sp24 + 0x1E;
            if (temp_s0 < 0x140) {
                func_8001F1E8(temp_s0, 0xB3, func_8002D7C0(NULL, 0, D_86B0E5E0, 0));
            }

            func_8001F444();

            gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);

            D_86B0BD50++;
            if (D_86B0BD50 >= (sp24 + 0x50)) {
                D_86B0BD50 = 0x32;
            }
        }
    }
}
