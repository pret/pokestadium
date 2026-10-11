#include "geo_render.h"
#include "src/geo_render.h"
#include "src/graphics_textures.h"
#include "src/graphics_textures.h"
#include "src/model_animation.h"
#include "src/model_animation_events.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/battle_hud.h"
#include "src/matrix.h"
#include "src/memmap.h"
#include "src/util.h"

typedef void (*func_D_8006F0A4)(GraphNode* arg0);

typedef struct unk_D_800AA8C8 {
    /* 0x0000 */ MtxF unk_0000[64];
    /* 0x1000 */ MtxF* unk_1000[32];
    /* 0x1080 */ s8 unk_1080[32];
    /* 0x10A0 */ s32 unk_10A0;
} unk_D_800AA8C8; // size >= 0x10A4

s32 D_8006F080 = 0;
u16 D_8006F084 = 0;
unk_D_86002F34_00C* D_8006F088 = NULL;
unk_D_86002F34_alt1* D_8006F08C = NULL;
unk_D_86002F34_alt1* D_8006F090 = NULL;
unk_D_86002F34_00C* D_8006F094 = NULL;
unk_D_86002F34_alt1* D_8006F098 = NULL;
DisplayObject* D_8006F09C = NULL;
unk_D_86002F34_alt11* D_8006F0A0 = NULL;
static func_D_8006F0A4 D_8006F0A4[] = {
    Geo_ProcessNodeChildren, Geo_NodeReference, Geo_NodeCamera, Geo_NodeType3Pass, Geo_NodeModelRoot, Geo_NodeOrtho, Geo_NodePerspective,
    Geo_NodeBackground, Geo_NodeClearDepth, Geo_NodeType9Empty, Geo_NodeFog, func_80013D34, Geo_NodeType12Empty, Geo_NodeAmbientLight,
    Geo_NodeShadowContext, Geo_NodeShadow, Geo_NodeCullDistance, Geo_NodeSwitchCase, Geo_NodeTranslateRotate, Geo_NodeTranslate, Geo_NodeAnimatedPart,
    Geo_NodeDisplayListPart, Geo_NodeModelPart, Geo_NodeDisplayListMatrix, Geo_NodeScale, Geo_NodeDisplayList, Geo_NodeShadowTexture, Geo_NodeAnchor,
    Geo_NodeGroup, NULL,          NULL,
};

static s32 D_8006F120 = 0;

static u32 D_8006F124[4][9] = {
    {
        0x3024000,
        0x3024000,
        0x3024000,
        0x3024000,
        0x3027008,
        0x104240,
        0x104240,
        0x104240,
        0x104240,
    },
    {
        0x3124370,
        0x112230,
        0x112E10,
        0x112230,
        0x113238,
        0x104A50,
        0x104E50,
        0x104A50,
        0x104A70,
    },
    {
        0x3024000,
        0x112048,
        0x112048,
        0x112048,
        0x113048,
        0x1041C8,
        0x1041C8,
        0x1041C8,
        0x1041C8,
    },
    {
        0x3124370,
        0x112078,
        0x112D58,
        0x112478,
        0x113078,
        0x1049D8,
        0x104DD8,
        0x1045D8,
        0x1049F8,
    },
};

static u8 D_8006F1B4[15][16] = {
    { 0x1F, 0x1F, 0x1F, 3, 7, 7, 7, 3, 0, 0x1F, 4, 0x1F, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 7, 7, 7, 1, 0, 0x1F, 4, 0x1F, 0, 7, 6, 7 },
    { 1, 3, 8, 3, 7, 7, 3, 7, 0, 0x1F, 4, 0x1F, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 7, 7, 7, 3, 0, 0x1F, 4, 0x1F, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 1, 7, 3, 7, 0, 0x1F, 4, 0x1F, 0, 7, 6, 7 },
    { 0x1F, 0x1F, 0x1F, 3, 7, 7, 7, 3, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 7, 7, 7, 1, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 3, 8, 3, 7, 7, 3, 7, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 7, 7, 7, 3, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 1, 7, 3, 7, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 0x1F, 0x1F, 0x1F, 4, 7, 7, 7, 4, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 4, 0x1F, 7, 7, 7, 1, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 4, 8, 4, 7, 7, 3, 7, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 4, 0x1F, 7, 7, 7, 4, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 4, 0x1F, 1, 7, 4, 7, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
};

static s16 D_8006F2A4[] = { 16, 8, 4, 2, 0, 0 };

static s32 D_800AA6C0;
static MtxF* D_800AA6C8[8];
static u8 pad_D_800AA6E8[0x1E0];
static unk_D_800AA8C8 D_800AA8C8;
static unk_D_800AB970 D_800AB970;
static s32 D_800ABB00;
static s32 D_800ABB04;
static s32 D_800ABB08;
static unk_D_800ABB10 D_800ABB10;
static unk_D_800ABB28 D_800ABB28[10];
static unk_D_800ABB28* D_800ABCB8;
static s32 D_800ABCBC;

void GeoRender_InitMatrixStack(void) {
    D_800AA8C8.unk_10A0 = 0;
    D_800AA8C8.unk_1080[0] = 0;
    MtxF_Identity(&D_800AA8C8.unk_0000[0]);
    D_800AA8C8.unk_1000[0] = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    MtxF_ToFixed(D_800AA8C8.unk_1000[0], D_800AA8C8.unk_0000);
}

void GeoRender_CommitMatrix(void) {
    D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0] = 0;
    D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0] = Gfx_AllocDisplayList(sizeof(MtxF) * 1);
    MtxF_ToFixed(D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0], &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
}

void GeoRender_SetMatrix(MtxF* arg0) {
    MtxF_Copy(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0], arg0);
    D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0] = 0;
    D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0] = Gfx_AllocDisplayList(sizeof(MtxF) * 1);
    MtxF_ToFixed(D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0], &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
}

void GeoRender_PushMultipliedMatrix(MtxF* arg0) {
    MtxF* temp_a0;

    D_800AA8C8.unk_10A0++;
    temp_a0 = &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0];

    MtxF_Multiply(&temp_a0[0], arg0, &temp_a0[-1]);
    D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0] = 0;
    D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0] = Gfx_AllocDisplayList(sizeof(MtxF) * 1);
    MtxF_ToFixed(D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0], &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
}

void GeoRender_PushScaledMatrix(Vec3f* arg0) {
    MtxF* temp_a0;

    D_800AA8C8.unk_10A0++;
    temp_a0 = &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0];

    MtxF_ScaleRows(&temp_a0[0], &temp_a0[-1], arg0);

    D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0] = 0;
    D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0] = Gfx_AllocDisplayList(sizeof(MtxF) * 1);

    MtxF_ToFixed(D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0], &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
}

MtxF* GeoRender_GetRelativeMatrix(s32 arg0) {
    MtxF* var_v1 = NULL;

    if (arg0 <= 0) {
        var_v1 = &(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0])[arg0];
    }

    return var_v1;
}

MtxF* GeoRender_GetMatrix(s32 arg0) {
    MtxF* var_v1 = NULL;

    if ((arg0 >= 0) && (arg0 < 0x20)) {
        var_v1 = &D_800AA8C8.unk_0000[arg0];
    }

    return var_v1;
}

void GeoRender_ResetTransformStack(void) {
    D_800AB970.unk_180 = 0;
    D_800AB970.unk_000[0] = D_8006F064;
}

void GeoRender_PushScale(Vec3f* arg0) {
    D_800AB970.unk_000[D_800AB970.unk_180 + 1].x = D_800AB970.unk_000[D_800AB970.unk_180].x * arg0->x;
    D_800AB970.unk_000[D_800AB970.unk_180 + 1].y = D_800AB970.unk_000[D_800AB970.unk_180].y * arg0->y;
    D_800AB970.unk_000[D_800AB970.unk_180 + 1].z = D_800AB970.unk_000[D_800AB970.unk_180].z * arg0->z;

    D_800AB970.unk_180++;
}

Vtx* GeoOverlay_BuildFadeQuad(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1) {
    u8 sp47;
    Vtx* temp_v0 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);

    if (temp_v0 != NULL) {
        switch (arg0->unk_00) {
            case 1:
                sp47 = 0xFF;
                break;

            case 2:
                sp47 = 0xFF - ((arg0->unk_0A * 0xFF) / arg0->unk_08);
                break;

            case 3:
                sp47 = (arg0->unk_0A * 0xFF) / arg0->unk_08;
                break;
        }

        Gfx_SetVertexAttributes(&temp_v0[0], arg1->l, arg1->t, -1, 0, 0, arg0->color.r, arg0->color.g, arg0->color.b, sp47);
        Gfx_SetVertexAttributes(&temp_v0[1], arg1->l, arg1->b, -1, 0, 0, arg0->color.r, arg0->color.g, arg0->color.b, sp47);
        Gfx_SetVertexAttributes(&temp_v0[2], arg1->r, arg1->b, -1, 0, 0, arg0->color.r, arg0->color.g, arg0->color.b, sp47);
        Gfx_SetVertexAttributes(&temp_v0[3], arg1->r, arg1->t, -1, 0, 0, arg0->color.r, arg0->color.g, arg0->color.b, sp47);
    }

    return temp_v0;
}

void GeoOverlay_DrawFadeQuad(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1) {
    Vtx* temp_v0 = GeoOverlay_BuildFadeQuad(arg0, arg1);

    if (temp_v0 != NULL) {
        gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
    }

    if (arg0->unk_00 != 1) {
        arg0->unk_0A++;
        if (arg0->unk_0A == arg0->unk_08) {
            if (arg0->unk_00 == 2) {
                arg0->unk_00 = 0;
            } else {
                arg0->unk_00 = 1;
            }
        }
    }
}

#pragma SWAP_FUNCTION_WORDS(func_80012870, 0xD0, 0xAFB80024, 0x00063403)
void func_80012870(Vtx* arg0, unk_D_86002F34_00C_0CC* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6,
                   s16 arg7) {
    f32 temp_fa0;
    f32 temp_fv1;
    u16 idx = arg1->unk_18;
    f32 a4;
    f32 a5;
    s16 tmp1;
    s16 tmp2;

    a4 = arg4;
    temp_fv1 = COSS(idx);
    temp_fa0 = SINS(idx);
    a5 = arg5;

    tmp1 = ((a4 * temp_fv1) - (temp_fa0 * a5));
    tmp2 = ((temp_fv1 * a5) + (a4 * temp_fa0));

    Gfx_SetVertexAttributes(arg0, tmp1 + arg2, tmp2 + arg3, -1, arg6 * 32, arg7 * 32, arg1->color.r, arg1->color.g, arg1->color.b,
                  0xFF);
}

Vtx* GeoOverlay_BuildRotatingQuad(unk_D_86002F34_00C_0CC* arg0) {
    Vtx* temp_v0 = Gfx_AllocDisplayList(sizeof(Vtx) * 8);
    Vtx* temp_s0;
    s16 temp_s2;
    s16 temp_s4;
    s16 temp_s5;

    if (temp_v0 != NULL) {
        temp_s0 = temp_v0;

        temp_s4 = arg0->unk_10 + (((arg0->unk_14 - arg0->unk_10) * arg0->unk_0A) / arg0->unk_08);
        temp_s5 = arg0->unk_12 + (((arg0->unk_16 - arg0->unk_12) * arg0->unk_0A) / arg0->unk_08);
        temp_s2 = arg0->unk_0C + (((arg0->unk_0E - arg0->unk_0C) * arg0->unk_0A) / arg0->unk_08);

        if (arg0->unk_00 == 2) {
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -temp_s2, -temp_s2, -0x1F, 0x3F);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, temp_s2, -temp_s2, 0x1F, 0x3F);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, temp_s2, temp_s2, 0x1F, 0);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -temp_s2, temp_s2, -0x1F, 0);
        } else {
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -temp_s2, -temp_s2, 0, 0x3F);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, temp_s2, -temp_s2, 0x3F, 0x3F);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, temp_s2, temp_s2, 0x3F, 0);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -temp_s2, temp_s2, 0, 0);
        }

        func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -0x7D0, -0x7D0, 0, 0);
        func_80012870(temp_s0++, arg0, temp_s4, temp_s5, 0x7D0, -0x7D0, 0, 0);
        func_80012870(temp_s0++, arg0, temp_s4, temp_s5, 0x7D0, 0x7D0, 0, 0);
        func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -0x7D0, 0x7D0, 0, 0);
    }

    arg0->unk_18 += arg0->unk_1A;
    return temp_v0;
}

void GeoOverlay_DrawRotatingQuad(unk_D_86002F34_00C_0CC* arg0, UNUSED unk_D_86002F34_00C_040* arg1) {
    Vtx* temp_v0 = GeoOverlay_BuildRotatingQuad(arg0);

    if (temp_v0 != 0) {
        gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);

        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 8, 0);
        gSP2Triangles(gDisplayListHead++, 0, 4, 1, 0, 1, 4, 5, 0);
        gSP2Triangles(gDisplayListHead++, 1, 5, 2, 0, 2, 5, 6, 0);
        gSP2Triangles(gDisplayListHead++, 2, 6, 7, 0, 2, 7, 3, 0);
        gSP2Triangles(gDisplayListHead++, 3, 4, 0, 0, 3, 7, 4, 0);

        gDPPipeSync(gDisplayListHead++);

        gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);

        if (arg0->unk_02 == 0) {
            gDPLoadTextureBlock(gDisplayListHead++, arg0->texture, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
        } else {
            gDPLoadTextureBlock(gDisplayListHead++, arg0->texture, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 64, 0,
                                G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
        }

        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);

        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    }

    arg0->unk_0A++;
    if (arg0->unk_0A == arg0->unk_08) {
        if (arg0->unk_00 == 4) {
            arg0->unk_00 = 0;
        } else {
            arg0->unk_00 = 1;
        }
    }
}

void GeoOverlay_Draw(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1) {
    if (arg0->unk_00 != 0) {
        gDPPipeSync(gDisplayListHead++);

        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
        gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
        gSPMatrix(gDisplayListHead++, (u32)arg1->mtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        if ((arg0->unk_00 == 1) || (arg0->unk_00 == 2) || (arg0->unk_00 == 3)) {
            GeoOverlay_DrawFadeQuad(arg0, arg1);
        } else {
            GeoOverlay_DrawRotatingQuad(arg0, arg1);
        }

        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    }
}

void Geo_ProcessNodeChildren(GraphNode* arg0) {
    GraphNode* temp_s2 = arg0->children;
    GraphNode* var_s0 = temp_s2;

    if (temp_s2 != NULL) {
        do {
            if (var_s0->flags & 1) {
                D_800AA6C0 = 0;
                if (var_s0->callback != NULL) {
                    D_800AA6C0 = var_s0->callback(2, var_s0);
                }
                D_8006F0A4[var_s0->type](var_s0);
            }
            var_s0 = var_s0->nextSibling;
        } while (var_s0 != temp_s2);
    }
}

void Geo_NodeReference(GraphNode* arg0) {
    UNUSED s32 pad;
    GraphNode* temp_a1 = ((unk_D_86002F34*)arg0)->unk_18;

    if ((temp_a1 != NULL) && (temp_a1->flags & 1)) {
        D_800AA6C0 = 0;
        if (temp_a1->callback != NULL) {
            D_800AA6C0 = temp_a1->callback(2, temp_a1);
        }
        D_8006F0A4[temp_a1->type](temp_a1);
    }

    Geo_ProcessNodeChildren(arg0);
}

void Geo_NodeCamera(GraphNode* arg0) {
    UNUSED MtxF pad_mtx;
    unk_D_86002F34_00C* arg = (unk_D_86002F34_00C*)arg0;
    unk_D_86002F34_00C_040* temp_s2 = &arg->unk_40;
    unk_D_86002F34_00C_060* temp_s1 = &arg->unk_60;
    unk_D_86002F34_00C_024* sp48 = &arg->unk_24;
    unk_D_86002F34_00C_018* temp_s0 = &arg->unk_18;

    temp_s0->vp = Gfx_AllocDisplayList(sizeof(Vp) * 1);
    temp_s2->mtx = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    sp48->mtx = Gfx_AllocDisplayList(sizeof(MtxF) * 1);
    temp_s1->p_mtxf = Gfx_AllocDisplayList(sizeof(MtxF) * 1);
    temp_s1->lookat = Gfx_AllocDisplayList(sizeof(LookAt) * 1);

    temp_s0->vp->vp.vtrans[0] = (temp_s0->x * 4) + (temp_s0->width * 2);
    temp_s0->vp->vp.vtrans[1] = (temp_s0->y * 4) + (temp_s0->height * 2);
    temp_s0->vp->vp.vtrans[2] = 0x1FF;

    temp_s0->vp->vp.vscale[0] = temp_s0->width * 2;
    temp_s0->vp->vp.vscale[1] = temp_s0->height * 2;
    temp_s0->vp->vp.vscale[2] = 0x1FF;

    gSPViewport(gDisplayListHead++, (u32)temp_s0->vp & 0x1FFFFFFF);
    gDPSetScissorFrac(gDisplayListHead++, G_SC_NON_INTERLACE, temp_s0->x * 4.0f, temp_s0->y * 4.0f,
                      (temp_s0->x + temp_s0->width) * 4.0f, (temp_s0->y + temp_s0->height) * 4.0f);

    guOrtho(temp_s2->mtx, temp_s2->l, temp_s2->r, temp_s2->b, temp_s2->t, temp_s2->n, temp_s2->f, temp_s2->scale);
    guPerspective(sp48->mtx, &sp48->perspNorm, sp48->fovy, sp48->aspect, sp48->near, sp48->far, sp48->scale);
    guLookAtReflectF(&temp_s1->mtxf, temp_s1->lookat, temp_s1->eye.x, temp_s1->eye.y, temp_s1->eye.z, temp_s1->at.x,
                     temp_s1->at.y, temp_s1->at.z, temp_s1->up.x, temp_s1->up.y, temp_s1->up.z);
    MtxF_ToFixed(temp_s1->p_mtxf, &temp_s1->mtxf);

    D_8006F088 = arg;
    if ((arg->unk_CC.unk_00 != 1) && (arg->node.children != NULL)) {
        Geo_ProcessNodeChildren(&arg->node);
    }
    GeoOverlay_Draw(&arg->unk_CC, temp_s2);
    Gfx_ApplyScissorRect(&gDisplayListHead);
    D_8006F088 = NULL;
}

void Geo_NodeType3Pass(GraphNode* arg0) {
    D_8006F08C = arg0;
    Geo_ProcessNodeChildren(arg0);
    D_8006F08C = NULL;
}

void Geo_NodeModelRoot(GraphNode* arg0) {
    unk_D_86002F34_alt1* arg = (unk_D_86002F34_alt1*)arg0;

    if (arg->node.children != NULL) {
        arg->unk_1D = 0;
        arg->unk_20 = -1;
        arg->lights = Gfx_AllocDisplayList(sizeof(Lights7));
        arg->unk_1C = 0;
        arg->lights->a.l.col[0] = 0;
        arg->lights->a.l.col[1] = 0;
        arg->lights->a.l.col[2] = 0;

        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                                     G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
        gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
        gSPTexture(gDisplayListHead++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);

        ModelAnim_ResetCurveContext();
        ModelAnim_ResetEventContext();
        GeoRender_InitMatrixStack();
        GeoRender_ResetTransformStack();

        gSPMatrix(gDisplayListHead++, (u32)D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0] & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        D_8006F090 = arg;
        Geo_ProcessNodeChildren(arg0);
        D_8006F090 = NULL;
    }

    arg->unk_1A = D_8006F084;
}

void Geo_NodeModelPartRoot(GraphNode* arg0) {
    unk_D_86002F34_00C* arg = (unk_D_86002F34_00C*)arg0;

    if ((D_8006F094 == NULL) && (arg->node.children != NULL)) {
        D_8006F094 = arg;
        GeoRender_InitMaterialState(arg->node.renderFlags & 3, D_8006F080);
        Geo_ProcessNodeChildren(arg0);
        GeoRender_FlushMaterialSlots();
        D_8006F094 = NULL;
    }
}

void Geo_NodeOrtho(GraphNode* arg0) {
    if ((D_8006F094 == NULL) && (arg0->children != NULL)) {
        gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
        gSPMatrix(gDisplayListHead++, (u32)D_8006F088->unk_40.mtx & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

        Geo_NodeModelPartRoot(arg0);
    }
}

void Geo_NodePerspective(GraphNode* arg0) {
    if ((D_8006F094 == NULL) && (arg0->children != NULL)) {
        gSPLookAt(gDisplayListHead++, (u32)&D_8006F088->unk_60.lookat->l & 0x1FFFFFFF);

        gSPPerspNormalize(gDisplayListHead++, D_8006F088->unk_24.perspNorm);

        gSPMatrix(gDisplayListHead++, (u32)D_8006F088->unk_24.mtx & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(gDisplayListHead++, (u32)D_8006F088->unk_60.p_mtxf & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

        Geo_NodeModelPartRoot(arg0);
    }
}

void Geo_NodeBackground(GraphNode* arg0) {
    unk_D_86002F34_alt2* arg = (unk_D_86002F34_alt2*)arg0;
    unk_D_86002F34_00C_018* ptr = &D_8006F088->unk_18;

    GfxImage_FillRectangle(&gDisplayListHead, ptr->x, ptr->y, ptr->width, ptr->height, arg->unk_18);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
}

void Geo_NodeClearDepth(UNUSED GraphNode* arg0) {
    unk_D_86002F34_00C_018* ptr = &D_8006F088->unk_18;

    GfxImage_ClearDepthRectangle(&gDisplayListHead, ptr->x, ptr->y, ptr->width, ptr->height);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
}

void Geo_NodeType9Empty(UNUSED GraphNode* arg0) {
}

void Geo_NodeFog(GraphNode* arg0) {
    unk_D_86002F34_alt3* arg = (unk_D_86002F34_alt3*)arg0;

    D_8006F090->unk_1D = 1;
    D_8006F090->unk_20 = arg->unk_1C;

    gSPFogPosition(gDisplayListHead++, arg->unk_18, arg->unk_1A);
    gSPSetGeometryMode(gDisplayListHead++, G_FOG);
    gDPSetColor(gDisplayListHead++, G_SETFOGCOLOR, arg->unk_1C);
}

void func_80013D34(GraphNode* arg0) {
    unk_D_86002F34_alt4* arg = (unk_D_86002F34_alt4*)arg0;
    Light* light;
    Ambient* ambient;

    if (D_8006F090->unk_1C >= 7) {
        return;
    }

    light = &D_8006F090->lights->l[D_8006F090->unk_1C];
    ambient = &D_8006F090->lights->a;

    *(u32*)light->l.col = arg->unk_18.rgba;
    *(u32*)light->l.colc = arg->unk_18.rgba;

    light->l.dir[0] = (120.0f * COSS(arg->unk_1C)) * SINS(arg->unk_1E);
    light->l.dir[1] = (120.0f) * SINS(arg->unk_1C);
    light->l.dir[2] = (120.0f * COSS(arg->unk_1C)) * COSS(arg->unk_1E);

    ambient->l.col[0] += ((arg->unk_18.r * arg->unk_18.a) / 100);
    if (ambient->l.col[0] > 0xFF) {
        ambient->l.col[0] = 0xFF;
    }

    ambient->l.col[1] += ((arg->unk_18.g * arg->unk_18.a) / 100);
    if (ambient->l.col[1] > 0xFF) {
        ambient->l.col[1] = 0xFF;
    }

    ambient->l.col[2] += ((arg->unk_18.b * arg->unk_18.a) / 100);
    if (ambient->l.col[2] > 0xFF) {
        ambient->l.col[2] = 0xFF;
    }

    D_8006F090->unk_1C++;
}


void Geo_NodeType12Empty(UNUSED GraphNode* arg0) {
}

void Geo_NodeAmbientLight(GraphNode* arg0) {
    unk_D_86002F34_alt4* arg = (unk_D_86002F34_alt4*)arg0;
    s32 i;
    Lights7* lights;

    lights = D_8006F090->lights;
    if ((arg->unk_18.r == 0xFF) && (arg->unk_18.g == 0xFF) && (arg->unk_18.b == 0xFF)) {
        lights->a.l.colc[0] = lights->a.l.col[0];
        lights->a.l.colc[1] = lights->a.l.col[1];
        lights->a.l.colc[2] = lights->a.l.col[2];
    } else {
        lights->a.l.colc[0] = lights->a.l.col[0] = arg->unk_18.r;
        lights->a.l.colc[1] = lights->a.l.col[1] = arg->unk_18.g;
        lights->a.l.colc[2] = lights->a.l.col[2] = arg->unk_18.b;
    }

    gSPSetGeometryMode(gDisplayListHead++, G_LIGHTING);
    gMoveWd(gDisplayListHead++, 2, 0, D_8006F090->unk_1C * 0x18);

    for (i = 0; i < D_8006F090->unk_1C; i++) {
        gSPLight(gDisplayListHead++, &D_8006F090->lights->l[i], i + 1);
    }

    gSPLight(gDisplayListHead++, D_8006F090->lights, i + 1);
}

void Geo_NodeShadowContext(GraphNode* arg0) {
    unk_D_86002F34_alt11* arg = (unk_D_86002F34_alt11*)arg0;
    MtxF* temp_v0 = &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0];
    Vec3f sp2C;
    Vec3s sp24;

    if (D_8006F09C->node.renderFlags & 2) {
        Vec3f_SetComponentsDuplicate(&sp2C, temp_v0->xw, 0.0f, temp_v0->zw);
        Vec3s_SetComponents(&sp24, 0, D_8006F09C->rotation.y, 0);
        MtxF_SetRotationTranslationF(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 1], &sp2C, &sp24);

        D_800AA8C8.unk_10A0++;

        GeoRender_CommitMatrix();
        GeoRender_SubmitMaterial(0, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        GeoRender_SubmitDisplayList(D_1002590, 1);

        D_800AA8C8.unk_10A0--;
    }

    D_8006F0A0 = arg;
    Geo_ProcessNodeChildren(arg0);
    D_8006F0A0 = NULL;
}

void Geo_NodeCullDistance(GraphNode* arg0) {
    unk_D_86002F34_alt3* arg = (unk_D_86002F34_alt3*)arg0;
    MtxF* mtx2 = &D_8006F088->unk_60.mtxf;
    f32 a = D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0].mf[3][0];
    f32 b = D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0].mf[3][1];
    f32 c = D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0].mf[3][2];
    s16 temp_ft5 = ((a * mtx2->mf[0][2]) + (b * mtx2->mf[1][2]) + (c * mtx2->mf[2][2])) + mtx2->mf[3][2];

    if ((temp_ft5 >= arg->unk_18) && (temp_ft5 < arg->unk_1A)) {
        Geo_ProcessNodeChildren(arg0);
    }
}

void Geo_NodeSwitchCase(GraphNode* arg0) {
    unk_D_86002F34_alt3* arg = (unk_D_86002F34_alt3*)arg0;
    s32 i;
    GraphNode* var_a1 = arg->node.children;

    if (var_a1 != NULL) {
        for (i = 0; i < arg->unk_1A; i++) {
            var_a1 = var_a1->nextSibling;
        }
    }

    if (var_a1->flags & 1) {
        D_8006F0A4[var_a1->type](var_a1);
    }
}

void Geo_NodeTranslateRotate(GraphNode* arg0) {
    MtxF sp20;
    unk_D_86002F34_alt5* arg = (unk_D_86002F34_alt5*)arg0;

    MtxF_SetRotationTranslationF(&sp20, &arg->unk_18, &arg->unk_24);
    GeoRender_PushMultipliedMatrix(&sp20);
    Geo_ProcessNodeChildren(arg0);

    D_800AA8C8.unk_10A0--;
}

void Geo_NodeTranslate(GraphNode* arg0) {
    unk_D_86002F34_alt5* arg = (unk_D_86002F34_alt5*)arg0;

    GeoRender_PushScaledMatrix(&arg->unk_18);
    Geo_ProcessNodeChildren(arg0);

    D_800AA8C8.unk_10A0--;
}

void Geo_NodeAnimatedPart(GraphNode* arg0) {
    Vec3s sp90;
    Vec3f sp84;
    Vec3f sp78;
    MtxF sp38;
    unk_D_86002F34_alt6* arg = (unk_D_86002F34_alt6*)arg0;
    s32 sp30;

    sp30 = 0;
    sp90 = arg->unk_1E;
    sp78 = arg->unk_24;

    Vec3f_FromVec3s(&sp84, &arg->unk_18);
    ModelAnim_EvaluateJointTransform(&sp84, &sp90, &sp78, arg->unk_32 * 3);

    if (arg->unk_31 & 2) {
        MtxF_BuildTransform(&sp38, &sp84, &sp90, &sp78, &D_8006F088->unk_60.mtxf, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
        D_800AA8C8.unk_10A0++;
        GeoRender_SetMatrix(&sp38);
    } else if (arg->unk_31 & 1) {
        MtxF_SetRotationScaleTranslation(&sp38, &sp84, &sp90, &sp78);
        GeoRender_PushMultipliedMatrix(&sp38);
    } else {
        MtxF_SetRotationAndScaledTranslation(&sp38, &sp84, &sp90, &D_800AB970.unk_000[D_800AB970.unk_180]);

        D_800AA8C8.unk_10A0++;

        GeoRender_PushScale(&sp78);
        if (D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0 - 1] == 1) {
            MtxF_Multiply(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 32], &sp38,
                          &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 31]);
        } else {
            MtxF_Multiply(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 32], &sp38,
                          &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 - 1]);
        }
        MtxF_ScaleRows(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0], &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 32],
                      &D_800AB970.unk_000[D_800AB970.unk_180]);
        GeoRender_CommitMatrix();
        D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0] = 1;
        sp30 = 1;
    }

    D_800AA6C8[arg->unk_30] = D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0];
    Geo_ProcessNodeChildren(arg0);
    D_800AA6C8[arg->unk_30] = NULL;
    D_800AA8C8.unk_10A0--;

    if (sp30 != 0) {
        D_800AB970.unk_180--;
    }
}

void Geo_NodeDisplayListPart(GraphNode* arg0) {
    unk_D_86002F34_alt7* arg = (unk_D_86002F34_alt7*)arg0;

    if (arg->unk_18 != NULL) {
        GeoRender_SubmitMaterial(arg->node.renderLayer, D_800AA6C8[arg->unk_1C]);
        GeoRender_SubmitDisplayList(arg->unk_18, (arg->node.renderFlags & 4) != 0);
    }

    Geo_ProcessNodeChildren(arg0);
}

void Geo_NodeModelPart(GraphNode* arg0) {
    MtxF sp38;
    Color_RGBA8_u32 sp34;
    DisplayObject* arg = (DisplayObject*)arg0;

    if (D_8006F090->unk_18 == arg->rootId) {
        arg->anchorCount = 0;
        ModelAnim_BeginCurveContext(&arg->transformAnim, D_8006F084, (arg->node.renderFlags & 0x20) != 0);
        ModelAnim_BeginEventContext(&arg->eventTrack, D_8006F084, (arg->node.renderFlags & 0x20) != 0);

        if (arg->node.renderFlags & 0x10) {
            MtxF_Multiply(&sp38, &arg->matrix, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
        } else if (arg->node.renderFlags & 8) {
            MtxF_ApplyScaleTransform(&sp38, &D_8006F088->unk_60.mtxf, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0], &arg->position,
                          1.0f);
        } else if (arg->node.renderFlags & 0x80) {
            MtxF_SetRotationAndTransformTranslation(&sp38, &arg->position, &arg->rotation);
            MtxF_Multiply(&sp38, &sp38, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
        } else {
            MtxF_SetRotationTranslationF(&sp38, &arg->position, &arg->rotation);
            MtxF_Multiply(&sp38, &sp38, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
        }

        MtxF_ScaleRows(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 1], &sp38, &arg->scale);

        if (!(arg->node.renderFlags & 4)) {
            D_800AA8C8.unk_10A0++;

            GeoRender_CommitMatrix();
            D_8006F09C = arg0;

            GeoRender_SetMaterialParams(arg->fogColor, arg->lodFraction, arg->textureMode);

            if ((D_8006F08C->unk_18 < 0) && (arg->objectType > 0)) {
                ModelAnim_UpdateDisplayObjectAnimation(arg->effectSlot, arg->objectType);
                Geo_ProcessNodeChildren(arg0);
                ModelAnim_FinalizeDisplayObjectAnimation(arg->effectSlot, arg->objectType);
            } else {
                Geo_ProcessNodeChildren(arg0);
            }

            sp34.rgba = 0xFFFFFF00;
            GeoRender_SetMaterialParams(sp34, 0xFF, 0);
            D_8006F09C = NULL;
        }

        ModelAnim_EndCurveContext();
        ModelAnim_EndEventContext();
        D_800AA8C8.unk_10A0 -= 1;
    }
}

void Geo_NodeDisplayListMatrix(GraphNode* arg0) {
    unk_D_86002F34_alt8* arg = (unk_D_86002F34_alt8*)arg0;

    GeoRender_PushMultipliedMatrix(&arg->unk_1C);

    if ((arg->unk_18 != NULL) || (arg->node.callback != NULL)) {
        GeoRender_SubmitMaterial(arg->node.renderLayer, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        if (arg->node.callback != NULL) {
            arg->node.callback(5, arg0);
        }
        GeoRender_SubmitDisplayList(arg->unk_18, (arg->node.renderFlags & 4) != 0);
    }
    Geo_ProcessNodeChildren(arg0);
    D_800AA8C8.unk_10A0--;
}

void Geo_NodeScale(GraphNode* arg0) {
    MtxF sp30;
    unk_D_86002F34_alt9* arg = (unk_D_86002F34_alt9*)arg0;

    MtxF_ApplyScaleTransform(&sp30, &D_8006F088->unk_60.mtxf, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0], &arg->unk_1C,
                  arg->unk_28);
    D_800AA8C8.unk_10A0++;
    GeoRender_SetMatrix(&sp30);

    if ((arg->unk_18 != NULL) || (arg->node.callback != NULL)) {
        GeoRender_SubmitMaterial(arg->node.renderLayer, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        if (arg->node.callback != NULL) {
            arg->node.callback(5, arg0);
        }
        GeoRender_SubmitDisplayList(arg->unk_18, (arg->node.renderFlags & 4) != 0);
    }

    Geo_ProcessNodeChildren(arg0);
    D_800AA8C8.unk_10A0--;
}

void Geo_NodeDisplayList(GraphNode* arg0) {
    unk_D_86002F34_alt9* arg = (unk_D_86002F34_alt9*)arg0;

    if ((arg->unk_18 != NULL) || (arg->node.callback != NULL)) {
        GeoRender_SubmitMaterial(arg->node.renderLayer, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        if (arg->node.callback != NULL) {
            arg->node.callback(5, arg0);
        }
        GeoRender_SubmitDisplayList(arg->unk_18, (arg->node.renderFlags & 4) != 0);
    }
    Geo_ProcessNodeChildren(arg0);
}

void Geo_NodeShadowTexture(GraphNode* arg0) {
    Color_RGBA8_u32 sp44;
    unk_D_86002F34_alt10* arg = (unk_D_86002F34_alt10*)arg0;
    unk_D_86002F34_alt11_018* sp3C;
    unk_D_86002F34_alt11_018* sp38;
    s32 sp34;

    sp3C = NULL;
    sp38 = NULL;
    sp34 = arg->unk_18;

    if (arg->unk_22 == 1) {
        sp44.rgba = 0xFFFFFFFF;
    } else {
        sp44.rgba = arg->unk_24.rgba;
    }

    if (arg->unk_1C >= 0) {
        sp3C = &D_8006F0A0->unk_18[arg->unk_1C];
    }

    if (arg->unk_1E >= 0) {
        sp38 = &D_8006F0A0->unk_1C[arg->unk_1E];
    }

    if (D_8006F09C != NULL) {
        sp44.r = (sp44.r * D_8006F09C->textureTint.r) / 255;
        sp44.g = (sp44.g * D_8006F09C->textureTint.g) / 255;
        sp44.b = (sp44.b * D_8006F09C->textureTint.b) / 255;
    }

    ModelAnim_GetEventAtFrame(&sp3C, D_8006F0A0->unk_18, arg->unk_20);
    GeoRender_SetMaterialTexture(arg->unk_22, sp44, sp3C, sp38, sp34);
    Geo_ProcessNodeChildren(arg0);
}

void GeoRender_RecordAnchorPosition(s32 arg0) {
    MtxF* temp_a1;
    ModelAnchor* ptr;

    if (D_8006F09C != NULL) {
        if (D_8006F09C->anchorCount < 0xC) {
            ptr = &D_8006F09C->anchors[D_8006F09C->anchorCount++];
            temp_a1 = &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0];

            ptr->id = arg0;
            ptr->position.x = temp_a1->mf[3][0];
            ptr->position.y = temp_a1->mf[3][1];
            ptr->position.z = temp_a1->mf[3][2];
        }
    }
}

void Geo_NodeAnchor(GraphNode* arg0) {
    unk_D_86002F34_alt3* arg = (unk_D_86002F34_alt3*)arg0;

    GeoRender_RecordAnchorPosition(arg->unk_18);
    Geo_ProcessNodeChildren(arg0);
}

void Geo_NodeGroup(GraphNode* arg0) {
    Geo_ProcessNodeChildren(arg0);
}

void Geo_NodeShadow(GraphNode* arg0) {
    Vec3f sp9C;
    Vec3f sp90;
    Vec3f sp84;
    f32 sp80;
    MtxF sp40;
    MtxF* sp3C;
    unk_D_86002F34_alt12* arg = (unk_D_86002F34_alt12*)arg0;
    Gfx* temp_s1;

    sp3C = &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0];
    temp_s1 = Gfx_AllocDisplayList(sizeof(Gfx) * 2);

    if (GeoRender_FindAnchorPosition(D_8006F09C, 0x64, NULL) == 0) {
        GeoRender_RecordAnchorPosition(0x64);
    }

    Vec3f_SetComponentsDuplicate(&sp9C, sp3C->mf[3][0], sp3C->mf[3][1] + arg->unk_1E, sp3C->mf[3][2]);
    sp9C.y = 0.0f;

    if (D_8006F09C->node.renderFlags & 0x40) {
        Vec3f_SetComponentsDuplicate(&sp90, 0.0f, 1.0f, 0.0f);
        MtxF_GetScale(sp3C, &sp84);

        sp80 = 1.0f - ((sp3C->mf[3][1] - sp9C.y) / 1000.0f);
        if (sp80 < 0.5f) {
            sp80 = 0.5f;
        }

        if (sp80 > 1.0f) {
            sp80 = 1.0f;
        }

        sp84.x *= (arg->unk_1A / 100.0f) * sp80;
        sp84.z *= (arg->unk_1C / 100.0f) * sp80;
        MtxF_SetOrthonormalBasis(&sp40, &sp90, &sp9C, D_8006F09C->rotation.y);
        MtxF_ScaleRows(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 1], &sp40, &sp84);

        D_800AA8C8.unk_10A0++;
        GeoRender_CommitMatrix();

        if (arg->unk_18 == 0) {
            gSPBranchList(&temp_s1[1], Util_ConvertAddrToVirtAddr(D_1002480));
        } else {
            gSPBranchList(&temp_s1[1], Util_ConvertAddrToVirtAddr(D_1002508));
        }
        gDPSetEnvColor(&temp_s1[0], 0, 0, 0, (s32)(150.0f * sp80));

        if (D_8006F09C->node.renderFlags & 2) {
            GeoRender_SubmitMaterial(6, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        } else {
            GeoRender_SubmitMaterial(5, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        }

        gDPSetFogColor(gDisplayListHead++, 255, 255, 255, 0);
        gDPSetPrimColor(gDisplayListHead++, 0, D_8006F09C->lodFraction, 255, 255, 255, 255);

        GeoRender_SubmitDisplayList((u32)temp_s1 & 0x1FFFFFFF, 1);
        Geo_ProcessNodeChildren(arg0);

        D_800AA8C8.unk_10A0--;
    }
}

void Geo_RenderRootNode(GraphNode* node) {
    unk_D_86002F34_alt1* arg = (unk_D_86002F34_alt1*)node;

    if (node->flags & 1) {
        gDPPipeSync(gDisplayListHead++);

        gDPSetTextureLOD(gDisplayListHead++, G_TL_TILE);
        gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
        gDPSetTextureDetail(gDisplayListHead++, G_TD_CLAMP);
        gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);
        gDPSetCombineKey(gDisplayListHead++, G_CK_NONE);
        gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
        gDPSetColorDither(gDisplayListHead++, G_CD_MAGICSQ);
        gDPSetAlphaDither(gDisplayListHead++, G_AD_PATTERN);

        D_8006F08C = arg;
        Geo_ProcessNodeChildren(node);
        D_8006F08C = NULL;
    }

    D_8006F080 = 0;
}

void Geo_ProcessCallbacks(GraphNode* arg0, s32 arg1) {
    GraphNode* var_s1 = arg0;
    GraphNode** var_s0;

    do {
        if (var_s1->callback != NULL) {
            var_s1->callback(arg1, var_s1);
        }

        if (var_s1->children != NULL) {
            switch (var_s1->type) {
                default:
                    var_s0 = NULL;
                    break;

                case 2:
                    var_s0 = &D_8006F088;
                    break;

                case 4:
                    var_s0 = &D_8006F090;
                    break;

                case 6:
                    var_s0 = &D_8006F098;
                    break;

                case 0x16:
                    var_s0 = &D_8006F09C;
                    break;
            }

            if (var_s0 != NULL) {
                *var_s0 = var_s1;
            }

            Geo_ProcessCallbacks(var_s1->children, arg1);

            if (var_s0 != NULL) {
                *var_s0 = NULL;
            }
        }

        var_s1 = var_s1->nextSibling;
    } while (var_s1 != arg0);
}

void GeoRender_SetMode(s32 arg0) {
    D_8006F080 = arg0;
}

void GeoRender_AdvanceFrameCounter(void) {
    D_8006F084++;
}

s32 GeoRender_IsModelFrameCurrent(void) {
    s32 var_v1 = 1;

    if (D_8006F090 != NULL) {
        var_v1 = D_8006F090->unk_1A == D_8006F084;
    }
    return var_v1;
}

Vec3f* GeoRender_FindAnchorPosition(DisplayObject* arg0, s16 arg1, Vec3f* arg2) {
    s32 i;
    s32 var_v0;
    u8 temp_v1;
    DisplayObject* var_a2;

    for (i = 0; i < arg0->anchorCount; i++) {
        if (arg1 == arg0->anchors[i].id) {
            if (arg2 != NULL) {
                *arg2 = arg0->anchors[i].position;
            }
            return &arg0->anchors[i].position;
        }
    }

    return NULL;
}

void GeoRender_SetCombineMode(Gfx* arg0, arg1_func_81407874_014_000_010* arg1) {
    gDPSetCombine(arg0++,
                  GCCc0w0(arg1->unk_00, arg1->unk_02, arg1->unk_04, arg1->unk_06) | GCCc1w0(arg1->unk_08, arg1->unk_0A),

                  GCCc0w1(arg1->unk_01, arg1->unk_03, arg1->unk_05, arg1->unk_07) |
                      GCCc1w1(arg1->unk_09, arg1->unk_0C, arg1->unk_0E, arg1->unk_0B, arg1->unk_0D, arg1->unk_0F));
}

void GeoRender_SyncMaterialState(void) {
    if (D_800ABB08 == 0) {
        D_800ABB08 = 1;

        gDPPipeSync(gDisplayListHead++);
    }
}

void GeoRender_SetRenderMode(void) {
    s32 var_v0 = D_8006F124[D_800ABB00][D_800ABCB8->unk_24];

    D_800ABB08 = 1;

    gDPPipeSync(gDisplayListHead++);

    D_800ABCB8->unk_14.rgba = 0x00000000;

    gDPSetColor(gDisplayListHead++, G_SETFOGCOLOR, D_8006F090->unk_20);

    if ((D_800ABB04 & 1) && (D_800ABB00 == 1) && (D_800ABCB8->unk_24 == 5)) {
        var_v0 = 0x107A58;
    }

    if (D_8006F090->unk_1D != 0) {
        gDPSetRenderMode(gDisplayListHead++, var_v0, 0xC8000000);
    } else {
        gDPSetRenderMode(gDisplayListHead++, var_v0, 0x0C080000);
    }
}

void GeoRender_ApplyMaterialState(void) {
    Color_RGBA8_u32 sp1C;

    sp1C.rgba = D_800ABCB8->unk_10.rgba;

    D_800ABCB8->unk_18 = NULL;
    D_800ABCB8->unk_1C = NULL;
    D_800ABCB8->unk_0C = NULL;
    D_800ABCB8->unk_27 = 0;
    D_800ABB08 = 1;

    gDPPipeSync(gDisplayListHead++);
    gDPSetPrimColor(gDisplayListHead++, 0, D_800ABCB8->unk_26, sp1C.r, sp1C.g, sp1C.b, sp1C.a);
    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);

    GeoRender_SetCombineMode(gDisplayListHead++, D_8006F1B4[D_800ABCB8->unk_25]);

    gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gSPClearGeometryMode(gDisplayListHead++, G_FOG | G_TEXTURE_GEN);

    gSPLookAt(gDisplayListHead++, (u32)&D_8006F088->unk_60.lookat->l & 0x1FFFFFFF);

    if (D_8006F090->unk_1D != 0) {
        gSPSetGeometryMode(gDisplayListHead++, G_FOG);
    }
}

void GeoRender_SetFogColor(unk_D_800ABB10* arg0) {
    if (arg0->unk_08.rgba != D_800ABCB8->unk_14.rgba) {
        GeoRender_SyncMaterialState();

        gDPSetColor(gDisplayListHead++, G_SETFOGCOLOR, arg0->unk_08.rgba);
        gDPSetRenderMode(gDisplayListHead++, D_8006F124[D_800ABB00][D_800ABCB8->unk_24], 0xC4000000);

        D_800ABCB8->unk_14.rgba = arg0->unk_08.rgba;
    }
}

void GeoRender_RestoreRenderMode(UNUSED unk_D_800ABB10* arg0) {
    if (D_800ABCB8->unk_14.rgba & 0xFF) {
        GeoRender_SetRenderMode();
    }
}

void GeoRender_SetPrimitiveColor(unk_D_800ABB10* arg0) {
    if ((arg0->unk_04.rgba != D_800ABCB8->unk_10.rgba) || (arg0->unk_01 != D_800ABCB8->unk_26)) {
        GeoRender_SyncMaterialState();

        gDPSetPrimColor(gDisplayListHead++, 0, arg0->unk_01, arg0->unk_04.r, arg0->unk_04.g, arg0->unk_04.b,
                        arg0->unk_04.a);

        D_800ABCB8->unk_10.rgba = arg0->unk_04.rgba;
        D_800ABCB8->unk_26 = arg0->unk_01;
    }
}

void GeoRender_SetCombineTableEntry(unk_D_800ABB10* arg0) {
    if (arg0->unk_00 != D_800ABCB8->unk_25) {
        GeoRender_SyncMaterialState();
        GeoRender_SetCombineMode(gDisplayListHead++, D_8006F1B4[arg0->unk_00]);
        D_800ABCB8->unk_25 = arg0->unk_00;
    }
}

void GeoRender_DisableTexture(UNUSED unk_D_800ABB10* arg0) {
    if (D_800ABCB8->unk_18 != NULL) {
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    }

    D_800ABCB8->unk_18 = NULL;
    D_800ABCB8->unk_1C = NULL;
    D_800ABCB8->unk_20 = NULL;
}

void GeoRender_BindTexture(unk_D_800ABB10* arg0) {
    unk_D_86002F34_alt11_018* temp_t0;
    s32 var_a3;

    if (D_800ABCB8->unk_18 == NULL) {
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }

    if ((arg0->unk_0C != D_800ABCB8->unk_18) || (arg0->unk_14 != D_800ABCB8->unk_20)) {
        temp_t0 = arg0->unk_0C;

        if (arg0->unk_10 != NULL) {
            gSPDisplayList(gDisplayListHead++, arg0->unk_10->unk_08);
        } else {
            gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
        }

        if (temp_t0->unk_01 == 0) {
            if ((temp_t0->unk_02 % D_8006F2A4[0]) == 0) {
                gDPSetTextureImage(gDisplayListHead++, temp_t0->fmt, G_IM_SIZ_16b, 1, temp_t0->texture);
            } else {
                gDPSetTextureImage(gDisplayListHead++, temp_t0->fmt, G_IM_SIZ_8b, temp_t0->unk_02 >> 1,
                                   temp_t0->texture);
            }
        } else if ((temp_t0->unk_02 % D_8006F2A4[temp_t0->unk_01]) == 0) {
            if (temp_t0->unk_01 == 3) {
                var_a3 = 3;
            } else {
                var_a3 = 2;
            }

            gDPSetTextureImage(gDisplayListHead++, temp_t0->fmt, var_a3, 1, temp_t0->texture);
        } else {
            gDPSetTextureImage(gDisplayListHead++, temp_t0->fmt, temp_t0->unk_01, temp_t0->unk_02, temp_t0->texture);
        }

        gSPDisplayList(gDisplayListHead++, arg0->unk_14);
    }

    D_800ABCB8->unk_18 = arg0->unk_0C;
    D_800ABCB8->unk_1C = arg0->unk_10;
    D_800ABCB8->unk_20 = arg0->unk_14;
}

void GeoRender_EnableTextureGeneration(UNUSED unk_D_800ABB10* arg0) {
    if (D_800ABCB8->unk_27 == 0) {
        gDPLoadTextureBlock(gDisplayListHead++, D_1001800, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 1, 1);
        gSPTexture(gDisplayListHead++, 0x1194, 0x1194, 0, G_TX_RENDERTILE, G_ON);

        gSPSetGeometryMode(gDisplayListHead++, G_TEXTURE_GEN);
        gSPClearGeometryMode(gDisplayListHead++, G_TEXTURE_GEN_LINEAR);
        gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIDECALA, G_CC_PASS2);

        D_800ABCB8->unk_27 = 1;
    }
}

void GeoRender_SelectMaterialSlot(s16 arg0) {
    if (arg0 == D_800ABCBC) {
        return;
    }

    D_800ABCB8->unk_08 = gDisplayListHead;

    gSPBranchList(gDisplayListHead++, NULL);

    D_800ABCBC = arg0;
    D_800ABCB8 = &D_800ABB28[D_800ABCBC];

    if (D_800ABCB8->unk_04 == NULL) {
        D_800ABCB8->unk_04 = gDisplayListHead;
    } else if (D_800ABCB8->unk_08 != NULL) {
        gSPBranchList(D_800ABCB8->unk_08, gDisplayListHead);
    }
}

void GeoRender_SetTextureMode(s16 arg0) {
    if (((arg0 > 0) && (arg0 < 4)) || (arg0 == 0x84) || (arg0 == 6)) {
        D_800ABB10.unk_03 = D_800ABB10.unk_02;
    } else {
        D_800ABB10.unk_03 = 0;
    }
}

s16 GeoRender_NormalizeTextureFormat(s16 arg0) {
    s16 var_v1 = arg0 & 0xF;

    if (D_800ABB10.unk_01 < 0xFF) {
        switch (var_v1) {
            case 1:
                var_v1 = 8;
                break;
            case 2:
                var_v1 = 6;
                break;
            case 3:
                var_v1 = 7;
                break;
            case 4:
                var_v1 = 5;
                break;
        }
    }

    return var_v1;
}

void GeoRender_SubmitMaterial(s16 arg0, MtxF* arg1) {
    if ((D_8006F120 != 0) && !(D_800ABB04 & 2) && (D_800ABB10.unk_01 > 0)) {
        GeoRender_SetTextureMode(arg0);
        GeoRender_SelectMaterialSlot(GeoRender_NormalizeTextureFormat(arg0));
        D_800ABB08 = 0;

        if (D_800ABCB8->unk_00 == 0) {
            GeoRender_SetRenderMode();
            GeoRender_ApplyMaterialState();
            D_800ABCB8->unk_00 = 1;
        }

        if (D_800ABB10.unk_08.rgba & 0xFF) {
            GeoRender_SetFogColor(&D_800ABB10);
        } else {
            GeoRender_RestoreRenderMode(&D_800ABB10);
        }

        if (D_800ABB10.unk_03 != 0) {
            GeoRender_EnableTextureGeneration(&D_800ABB10);
        } else {
            if (D_800ABCB8->unk_27 == 1) {
                GeoRender_ApplyMaterialState();
            }

            if (D_800ABB10.unk_0C != 0) {
                GeoRender_BindTexture(&D_800ABB10);
            } else {
                GeoRender_DisableTexture(&D_800ABB10);
            }

            GeoRender_SetPrimitiveColor(&D_800ABB10);
            GeoRender_SetCombineTableEntry(&D_800ABB10);
        }

        if (arg1 != D_800ABCB8->unk_0C) {
            D_800ABCB8->unk_0C = arg1;
            gSPMatrix(gDisplayListHead++, (u32)arg1 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        }
    }
}

void GeoRender_SubmitDisplayList(Gfx* arg0, s32 arg1) {
    if ((D_8006F120 != 0) && !(D_800ABB04 & 2) && (D_800ABB10.unk_01 > 0)) {
        if (arg0 != NULL) {
            if (((u32)arg0 >= 0x81000000) && ((u32)arg0 < 0x90000000)) {
                gSPDisplayList(gDisplayListHead++, Memmap_GetFragmentVaddr((u32)arg0));
            } else {
                gSPDisplayList(gDisplayListHead++, arg0);
            }
        }

        if (arg1 != 0) {
            GeoRender_ApplyMaterialState();
        }
    }
}

void GeoRender_SetMaterialParams(Color_RGBA8_u32 arg0, u8 arg1, u32 arg2) {
    D_800ABB10.unk_08.rgba = arg0.rgba;
    D_800ABB10.unk_01 = arg1;
    D_800ABB10.unk_02 = arg2;
}

void GeoRender_SetMaterialTexture(s32 arg0, Color_RGBA8_u32 arg1, unk_D_86002F34_alt11_018* arg2, unk_D_86002F34_alt11_018* arg3,
                   s32 arg4) {
    D_800ABB10.unk_00 = arg0;
    D_800ABB10.unk_04.rgba = arg1.rgba;
    D_800ABB10.unk_0C = arg2;
    D_800ABB10.unk_10 = arg3;
    D_800ABB10.unk_14 = arg4;
}

void GeoRender_InitMaterialState(s32 arg0, s32 arg1) {
    s32 i;
    unk_D_800ABB28* ptr = D_800ABB28;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);

    if (arg0 & 1) {
        gSPSetGeometryMode(gDisplayListHead++, G_ZBUFFER);
    } else {
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER);
    }

    for (i = 0; i < 10; i++, ptr++) {
        ptr->unk_04 = NULL;
        ptr->unk_08 = NULL;

        ptr->unk_00 = 0;
        ptr->unk_0C = 0;

        ptr->unk_10.rgba = 0xFFFFFFFF;
        ptr->unk_14.rgba = 0xFFFFFF00;

        ptr->unk_18 = NULL;
        ptr->unk_1C = NULL;
        ptr->unk_20 = NULL;

        ptr->unk_24 = i;
        ptr->unk_25 = 0;
        ptr->unk_27 = 0;
        ptr->unk_26 = 0xFF;
    }

    D_800ABB10.unk_00 = 0;
    D_800ABB10.unk_01 = 0xFF;
    D_800ABB10.unk_02 = 0;
    D_800ABB10.unk_03 = 0;
    D_800ABB10.unk_04.rgba = -1;
    D_800ABB10.unk_08.rgba = 0xFFFFFF00;
    D_800ABB10.unk_0C = 0;
    D_800ABB10.unk_10 = 0;
    D_800ABB10.unk_14 = 0;

    D_800ABB00 = arg0;
    D_800ABB04 = arg1;

    D_800ABB28[0].unk_04 = gDisplayListHead;

    D_800ABCBC = 0;
    D_800ABCB8 = D_800ABB28;

    D_8006F120 = 1;
}

void GeoRender_FlushMaterialSlots(void) {
    s32 sp1C = 0;
    Gfx* temp_t0;
    s32 temp_v0;

    GeoRender_SelectMaterialSlot(9);

    if (D_800ABB28[0].unk_08 != NULL) {
        while (sp1C < 9) {
            temp_v0 = sp1C + 1;
            temp_t0 = D_800ABB28[sp1C].unk_08;
            sp1C++;

            while (D_800ABB28[temp_v0].unk_04 == NULL) {
                temp_v0 = sp1C + 1;
                sp1C++;
            }

            gSPBranchList(temp_t0, D_800ABB28[sp1C].unk_04);
        }
    }

    GeoRender_ApplyMaterialState();

    if (D_800ABB00 & 1) {
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER);
    }

    D_8006F120 = 0;
}
