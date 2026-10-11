#include "global.h"
#include "geo_node.h"
#include "matrix.h"
#include "util.h"

void GeoNode_Init(GraphNode* arg0, u8 arg1) {
    if (arg0 != NULL) {
        arg0->type = arg1;
        arg0->flags = 0x11;
        arg0->renderFlags = 0;
        arg0->renderLayer = 0;
        arg0->prevSibling = arg0;
        arg0->nextSibling = arg0;
        arg0->children = NULL;
        arg0->callback = NULL;
        arg0->callbackArg = NULL;
    }
}

void GeoNode_SetCallback(GraphNode* arg0, GraphNodeCallback arg1, void* arg2) {
    if (arg1 != NULL) {
        arg1 = Util_ConvertAddrToVirtAddr(arg1);
    }

    if (arg0 != NULL) {
        arg0->callbackArg = arg2;
        arg0->callback = arg1;
        if (arg1 != NULL) {
            arg1(0, arg0);
        }
    }
}

GraphNode* GeoNode_CreateContainer(MainPoolState* arg0, GraphNode* arg1) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(struct GraphNode), 4);
    }

    if (arg1 != NULL) {
        GeoNode_Init(arg1, 0);
    }

    return arg1;
}

unk_D_86002F34_alt2* GeoNode_CreateWithReference(MainPoolState* arg0, unk_D_86002F34_alt2* arg1, GraphNode* arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt2), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        GeoNode_Init(arg1, 1);
    }

    return arg1;
}

unk_D_86002F34_00C* GeoNode_CreateCamera(MemoryBlock* arg0, unk_D_86002F34_00C* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_00C), 4);
    }

    if (arg1 != NULL) {
        GeoCamera_SetViewport(arg1, arg2, arg3, arg4, arg5);
        GeoCamera_SetPerspective(arg1, 30.0f, 100.0f, 12800.0f);
        GeoCamera_SetEyeAtUp(arg1, 0.0f, 512.0f, 4096.0f, 0.0f, 0.0f, 0.0f, 0);
        GeoCamera_SetBackground(arg1, 2, 0, 0, 0, 0);
        GeoNode_Init(arg1, 2);
    }
    return arg1;
}

unk_D_86002F34_alt13* GeoNode_CreateType3(MemoryBlock* arg0, unk_D_86002F34_alt13* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt13), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        GeoNode_Init(arg1, 3);
    }

    return arg1;
}

unk_D_86002F34_alt1* GeoNode_CreateType4(MemoryBlock* arg0, unk_D_86002F34_alt1* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt1), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = 0;
        GeoNode_Init(arg1, 4);
    }

    return arg1;
}

unk_D_86002F34_alt14* GeoNode_CreateOrtho(MainPoolState* arg0, unk_D_86002F34_alt14* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt14), 4);
    }

    if (arg1 != NULL) {
        GeoNode_Init(arg1, 5);
        arg1->node.renderFlags |= arg2 & 3;
    }

    return arg1;
}

unk_D_86002F34_alt15* GeoNode_CreatePerspective(MainPoolState* arg0, unk_D_86002F34_alt15* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt15), 4);
    }

    if (arg1 != NULL) {
        GeoNode_Init(arg1, 6);
        arg1->node.renderFlags |= arg2 & 3;
    }

    return arg1;
}

unk_D_86002F34_alt16* GeoNode_CreateBackground(MainPoolState* arg0, unk_D_86002F34_alt16* arg1, u8 arg2, u8 arg3, u8 arg4) {
    u32 temp_v0;

    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt16), 4);
    }

    if (arg1 != NULL) {
        temp_v0 = ((arg2 >> 3) << 0xB) | ((arg3 >> 3) << 6) | ((arg4 >> 3) << 1) | 1;
        arg1->unk_18 = (temp_v0 << 0x10) | temp_v0;
        GeoNode_Init(arg1, 7);
    }
    return arg1;
}

unk_D_86002F34_alt17* GeoNode_CreateClearDepth(MainPoolState* arg0, unk_D_86002F34_alt17* arg1) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt17), 4);
    }

    if (arg1 != NULL) {
        GeoNode_Init(arg1, 8);
    }

    return arg1;
}

unk_D_8690A610* GeoNode_CreateFog(s32 arg0, unk_D_8690A610* arg1, s16 arg2, s16 arg3, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != 0) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_8690A610), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18.unk_00 = arg2;
        arg1->unk_18.unk_02 = arg3;
        arg1->unk_18.unk_04.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        GeoNode_Init(arg1, 0xA);
    }

    return arg1;
}

unk_D_86002F34_alt18* GeoNode_CreateLight(MainPoolState* arg0, unk_D_86002F34_alt18* arg1, s16 arg2, s16 arg3, u8 r, u8 g,
                                    u8 b, u8 a) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt18), 4);
    }

    if (arg1 != NULL) {
        arg1->r = r;
        arg1->g = g;
        arg1->b = b;
        arg1->a = a;
        arg1->unk_1C = arg2;
        arg1->unk_1E = arg3;
        GeoNode_Init(arg1, 0xB);
    }

    return arg1;
}

unk_D_86002F34_alt19* GeoNode_CreateAmbientLight(MainPoolState* arg0, unk_D_86002F34_alt19* arg1, u8 r, u8 g, u8 b) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt19), 4);
    }

    if (arg1 != NULL) {
        arg1->r = r;
        arg1->g = g;
        arg1->b = b;
        GeoNode_Init(arg1, 0xD);
    }

    return arg1;
}

unk_D_86002F34* GeoNode_CreateShadowContext(MainPoolState* arg0, unk_D_86002F34* arg1, s32 arg2, unk_D_86002F34_018* arg3, s32 arg4,
                              unk_D_86002F34_01C* arg5, s32 arg6, Vtx* arg7) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg3;
        arg1->unk_1C = arg5;
        arg1->unk_20 = arg7;
        arg1->unk_24 = arg2;
        arg1->unk_25 = arg4;
        arg1->unk_26 = arg6;
        arg1->unk_28 = NULL;
        GeoNode_Init(arg1, 0xE);
    }

    return arg1;
}

unk_D_86002F34_alt12* GeoNode_CreateShadow(MainPoolState* arg0, unk_D_86002F34_alt12* arg1, s16 arg2, s16 arg3, s16 arg4,
                                    s16 arg5) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt12), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        arg1->unk_1C = arg4;
        arg1->unk_1E = arg5;
        GeoNode_Init(arg1, 0xF);
    }

    return arg1;
}

unk_D_86002F34_alt20* GeoNode_CreateCullDistance(MainPoolState* arg0, unk_D_86002F34_alt20* arg1, s16 arg2, s16 arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt20), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        GeoNode_Init(arg1, 0x10);
    }

    return arg1;
}

unk_D_86002F34_alt21* GeoNode_CreateSwitchCase(MainPoolState* arg0, unk_D_86002F34_alt21* arg1, s16 arg2, s16 arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt21), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        GeoNode_Init(arg1, 0x11);
    }

    return arg1;
}

unk_D_86002F34_alt5* GeoNode_CreateTranslateRotate(MainPoolState* arg0, unk_D_86002F34_alt5* arg1, Vec3f* arg2, Vec3s* arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt5), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg2;
        arg1->unk_24 = *arg3;
        GeoNode_Init(arg1, 0x12);
    }

    return arg1;
}

unk_D_86002F34_alt22* GeoNode_CreateTranslate(MainPoolState* arg0, unk_D_86002F34_alt22* arg1, Vec3f* arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt22), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg2;
        GeoNode_Init(arg1, 0x13);
    }

    return arg1;
}

unk_D_86002F34_alt6* GeoNode_CreateAnimatedPart(MainPoolState* arg0, unk_D_86002F34_alt6* arg1, s16 arg2, s16 arg3, s16 arg4,
                                   Vec3s* arg5, Vec3s* arg6, Vec3f* arg7) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt6), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg5;
        arg1->unk_1E = *arg6;
        arg1->unk_24 = *arg7;
        arg1->unk_30 = arg2;
        arg1->unk_31 = arg3;
        arg1->unk_32 = arg4;
        GeoNode_Init(arg1, 0x14);
    }

    return arg1;
}

unk_D_86002F34_alt7* GeoNode_CreateDisplayListPart(MainPoolState* arg0, unk_D_86002F34_alt7* arg1, s32 arg2, Gfx* arg3, s16 arg4) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt7), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg3;
        arg1->unk_1C = arg4;
        GeoNode_Init(arg1, 0x15);
        arg1->node.renderLayer = arg2;
    }

    return arg1;
}

DisplayObject* GeoNode_CreateModelPart(MainPoolState* arg0, DisplayObject* arg1, s16 arg2, Vec3f* arg3,
                                      Vec3s* arg4, Vec3f* arg5) {
    if (arg0 != 0) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(DisplayObject), 4);
    }

    if (arg1 != NULL) {
        arg1->rootId = 0;
        arg1->objectType = arg2;
        arg1->position = *arg3;
        arg1->scale = *arg5;
        arg1->rotation = *arg4;
        arg1->lodFraction = 0xFF;
        arg1->textureMode = 0;
        arg1->effectSlot = 0;
        arg1->fogColor.rgba = 0xFFFFFF00;
        arg1->textureTint.rgba = 0xFFFFFF00;
        arg1->transformAnim.animationId = 0;
        arg1->transformAnim.data = NULL;
        arg1->transformAnim.frameFixed = 0;
        arg1->transformAnim.speedFixed = 0x10000;
        arg1->transformAnim.lastRenderFrame = 0;
        arg1->eventTrack.trackId = 0;
        arg1->eventTrack.data = NULL;
        arg1->eventTrack.frame = 0;
        arg1->eventTrack.lastRenderFrame = 0;
        GeoNode_Init(&arg1->node, 0x16);
        arg1->node.renderFlags |= 0x60;
    }

    return arg1;
}

unk_D_86002F34_alt8* GeoNode_CreateDisplayListMatrix(MainPoolState* arg0, unk_D_86002F34_alt8* arg1, s32 arg2, Gfx* arg3, MtxF* arg4) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt8), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg3;
        if (arg4 == NULL) {
            MtxF_Identity(&arg1->unk_1C);
        } else {
            MtxF_Copy(&arg1->unk_1C, arg4);
        }
        GeoNode_Init(arg1, 0x17);
        arg1->node.renderLayer = arg2;
    }

    return arg1;
}

unk_D_86002F34_alt8* GeoNode_CreateDisplayListMatrixFromTransform(MainPoolState* arg0, unk_D_86002F34_alt8* arg1, s32 arg2, Gfx* arg3, Vec3f* arg4,
                                   Vec3s* arg5) {
    MtxF sp20;

    MtxF_SetRotationTranslationF(&sp20, arg4, arg5);
    return GeoNode_CreateDisplayListMatrix(arg0, arg1, arg2, arg3, &sp20);
}

unk_D_86002F34_alt9* GeoNode_CreateScale(MainPoolState* arg0, unk_D_86002F34_alt9* arg1, s32 arg2, Gfx* arg3, Vec3f* arg4,
                                   f32 arg5) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt9), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_1C = *arg4;
        arg1->unk_28 = arg5;
        arg1->unk_18 = arg3;
        GeoNode_Init(arg1, 0x18);
        arg1->node.renderLayer = arg2;
    }

    return arg1;
}

unk_func_80011B94* GeoNode_CreateDisplayList(MainPoolState* arg0, unk_func_80011B94* arg1, s32 arg2, Gfx* arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_func_80011B94), 4);
    }

    if (arg1 != NULL) {
        arg1->gfx = arg3;
        GeoNode_Init(arg1, 0x19);
        arg1->display_node_header.renderLayer = arg2;
    }

    return arg1;
}

unk_D_86002F34_alt10* GeoNode_CreateShadowTexture(MainPoolState* arg0, unk_D_86002F34_alt10* arg1, s16 arg2, s16 arg3, Gfx* arg4,
                                    s16 arg5, s16 arg6, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt10), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_22 = arg2;
        arg1->unk_20 = arg3;
        arg1->unk_18 = arg4;
        arg1->unk_1C = arg5;
        arg1->unk_1E = arg6;
        arg1->unk_24.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        GeoNode_Init(arg1, 0x1A);
    }

    return arg1;
}

unk_D_86002F34_alt23* GeoNode_CreateAnchor(MainPoolState* arg0, unk_D_86002F34_alt23* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt23), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        GeoNode_Init(arg1, 0x1B);
    }

    return arg1;
}

unk_D_86002F34_alt24* GeoNode_CreateGroup(MainPoolState* arg0, unk_D_86002F34_alt24* arg1, s32 arg2, s16 arg3, s16 arg4,
                                    s16 arg5, s16 arg6, s16 arg7, s16 arg8, s32 arg9, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(unk_D_86002F34_alt24), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_1C = arg3;
        arg1->unk_1E = arg4;
        arg1->unk_20 = arg5;
        arg1->unk_22 = arg6;
        arg1->unk_18 = arg7;
        arg1->unk_1A = arg8;
        arg1->unk_24 = arg9;
        arg1->unk_28.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        GeoNode_Init(arg1, 0x1C);
        arg1->node.renderLayer = arg2;
    }

    return arg1;
}

void GeoCamera_SetViewport(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_18.x = arg1;
    arg0->unk_18.y = arg2;
    arg0->unk_18.width = arg3;
    arg0->unk_18.height = arg4;

    arg0->unk_40.l = -arg3 * 0.5f;
    arg0->unk_40.r = arg3 * 0.5f;
    arg0->unk_40.t = arg4 * 0.5f;
    arg0->unk_40.b = -arg4 * 0.5f;
    arg0->unk_40.n = -2.0f;
    arg0->unk_40.f = 2.0f;
    arg0->unk_40.scale = 1.0f;
}

void GeoCamera_SetPerspective(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_24.aspect = (f32)arg0->unk_18.width / arg0->unk_18.height;
    arg0->unk_24.fovy = arg1;
    arg0->unk_24.near = arg2;
    arg0->unk_24.far = arg3;
    arg0->unk_24.scale = 1.0f;
}

void GeoCamera_SetEyeAtUp(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7) {
    unk_D_86002F34_00C_060* sp1C = &arg0->unk_60;
    f32 sp28 = arg4 - arg1;
    f32 sp24 = arg6 - arg3;
    f32 temp_fv1_2 = -1.0 / sqrtf(SQ(sp28) + SQ(sp24));

    sp28 *= temp_fv1_2;
    sp24 *= temp_fv1_2;

    Vec3f_SetComponentsDuplicate(&sp1C->eye, arg1, arg2, arg3);
    Vec3f_SetComponentsDuplicate(&sp1C->at, arg4, arg5, arg6);
    Vec3f_SetComponentsDuplicate(&sp1C->up, SINS(arg7) * sp24, COSS(arg7), -SINS(arg7) * sp28);
}

void GeoCamera_SetBackground(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5) {
    unk_D_86002F34_00C_0CC* ptr = &arg0->unk_CC;

    if (arg2 < 2) {
        if ((arg1 == 2) || (arg1 == 4)) {
            ptr->unk_00 = 0;
        } else {
            ptr->unk_00 = 1;
        }
    } else {
        ptr->unk_00 = arg1;
        ptr->unk_08 = arg2;
        ptr->unk_0A = 1;
        ptr->color.r = arg3;
        ptr->color.g = arg4;
        ptr->color.b = arg5;
    }
}

void GeoCamera_SetBackgroundTexture(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, s32 arg3, u32 arg4) {
    unk_D_86002F34_00C_0CC* ptr = &arg0->unk_CC;
    ptr->unk_0C = arg1;
    ptr->unk_0E = arg2;
    ptr->unk_10 = 0;
    ptr->unk_12 = 0;
    ptr->unk_14 = 0;
    ptr->unk_16 = 0;
    ptr->unk_18 = 0;
    ptr->unk_1A = 0;
    ptr->unk_02 = 0;
    ptr->texture = D_1000800;
}

void GraphNode_AppendChild(GraphNode* arg0, GraphNode* arg1) {
    GraphNode* temp_v0;
    GraphNode* temp_v1;

    if ((arg0 != NULL) && (arg1 != NULL)) {
        temp_v0 = arg0->children;
        if (temp_v0 == NULL) {
            arg0->children = arg1;
            arg1->prevSibling = arg1;
            arg1->nextSibling = arg1;
        } else {
            temp_v1 = temp_v0->prevSibling;
            arg1->nextSibling = temp_v0;
            arg1->prevSibling = temp_v1;
            temp_v0->prevSibling = arg1;
            temp_v1->nextSibling = arg1;
        }
    }
}

void GraphNode_RemoveChild(GraphNode* arg0, GraphNode* arg1) {
    arg1->prevSibling->nextSibling = arg1->nextSibling;
    arg1->nextSibling->prevSibling = arg1->prevSibling;
    if ((unk_D_86002F34_00C*)arg1 == arg0->children) {
        if (arg1 == arg1->nextSibling) {
            arg0->children = NULL;
            return;
        }
        arg0->children = (unk_D_86002F34_00C*)arg1->nextSibling;
    }
}

GraphNode* GraphNode_GetChildAtIndex(GraphNode* arg0, s32 arg1) {
    GraphNode* var_v1;
    s32 i;
    var_v1 = (GraphNode*)arg0->children;
    if (var_v1 != NULL) {
        for (i = 0; i < arg1; i++) {
            var_v1 = var_v1->nextSibling;
        }
    }
    return var_v1;
}
