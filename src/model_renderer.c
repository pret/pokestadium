#include "global.h"
#include "model_renderer.h"
#include "geo_node.h"
#include "model_animation.h"
#include "matrix.h"
#include "model_animation_events.h"
#include "battle_hud.h"
#include "gb_data.h"
#include "display_object_textures.h"
#include "game_state.h"
#include "dp_intro.h"
#include "hal_libc.h"
#include "src/geo_render.h"

struct DisplayNodeHeader D_800AC840;
struct DisplayNodeHeader D_800AC858;

void ModelRenderer_InitDisplayRoots(void) {
    GeoNode_CreateContainer(0, &D_800AC840);
    GeoNode_CreateContainer(0, &D_800AC858);
}

void ModelRenderer_AttachDisplayObject(DisplayObject* arg0) {
    GeoNode_CreateModelPart(NULL, arg0, 0, &D_8006F050, &D_8006F05C, &D_8006F064);
    GraphNode_AppendChild(&D_800AC840, &arg0->node);
    arg0->effectSlot = 0;
    arg0->node.flags &= ~1;
}

void ModelRenderer_AttachSecondaryDisplayObject(DisplayObject* arg0) {
    GeoNode_CreateModelPart(NULL, arg0, 0, &D_8006F050, &D_8006F05C, &D_8006F064);
    GraphNode_AppendChild(&D_800AC858, &arg0->node);
    arg0->node.flags &= ~1;
}

void Model_InitDisplayObject(DisplayObject* display_object, s16 root_id, s16 object_type, ModelNodeView* child) {
    GraphNode_AppendChild(&display_object->node, child);
    MtxF_Identity(&display_object->matrix);
    display_object->rootId = root_id;
    display_object->objectType = object_type;

    display_object->lodFraction = 0xFF;
    display_object->textureMode = 0;

    display_object->node.flags |= 0x1;

    display_object->node.renderFlags &= ~0x4;
    display_object->node.renderFlags |= 0x20;
    display_object->node.renderFlags |= 0x40;
    display_object->node.renderFlags &= ~0x2;

    display_object->fogColor.rgba = 0xFFFFFF00;
    display_object->textureTint.rgba = 0xFFFFFF00;
    display_object->transformAnim.animationId = -1;
    display_object->transformAnim.data = NULL;
    display_object->eventTrack.trackId = -1;
    display_object->eventTrack.data = NULL;

    display_object->node.renderFlags &= ~0x8;

    if (object_type > 0) {
        ModelAnim_StartDisplayObjectAnimation(display_object);
    }
}

void ModelRenderer_ClearDisplayObject(DisplayObject* arg0) {
    arg0->node.children = NULL;
    arg0->node.flags &= ~1;
}

s32 ModelAnim_SetAnimation(DisplayObject* arg0, s32 arg1) {
    ModelAssetNode* tmp = arg0->node.children;
    ModelAnimationBank* temp_v0 = tmp->getAnimationBank(0, 0);

    if (arg1 == -1) {
        ModelAnim_ClearTransformChannel(arg0);
    } else if (arg1 < temp_v0->transformCount) {
        ModelAnim_BindTransformCurve(arg0, arg1, temp_v0->transformTracks[arg1], 0x10000);
        return 1;
    }

    return 0;
}

s32 ModelAnim_SetEventTrack(DisplayObject* arg0, s32 arg1) {
    ModelAssetNode* temp_v0 = arg0->node.children;
    ModelAnimationBank* temp_v1 = temp_v0->getAnimationBank(0, 0);

    if (arg1 == -1) {
        ModelAnim_ClearEventTrack(arg0);
    } else if (arg1 < temp_v1->eventTrackCount) {
        ModelAnim_BindEventTrack(arg0, arg1, temp_v1->eventTracks[arg1]);
        return 1;
    }

    return 0;
}

void Model_SetMaterialColor(DisplayObject* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    Color_SetRGBA(&arg0->fogColor, arg1, arg2, arg3, arg4);
}

void Model_SetMaterialAlpha(DisplayObject* arg0, u8 arg1) {
    arg0->lodFraction = arg1;
}

void Model_SetMaterialTextureMode(DisplayObject* arg0, u8 arg1) {
    arg0->textureMode = arg1;
}

ModelAnimationBank* ModelAnim_GetAnimationRecord(DisplayObject* arg0, s32 arg1) {
    ModelAnimationBank* var_v1 = NULL;

    if (arg0 == NULL) {
        arg0 = D_8006F09C;
    }

    if (arg0 != NULL) {
        ModelAssetNode* tmp = arg0->node.children;

        var_v1 = tmp->getAnimationBank(arg1, 0);
    }

    return var_v1;
}

arg1_func_80010CA8* Model_ComputeSizeVariant(arg1_func_80010CA8* arg0, BattleMon* arg1) {
    UNUSED s32 pad;
    char sp38[0xB];
    arg1_func_80010CA8 sp34;
    unk_D_8006FF00* sp30;
    UNUSED s32 pad2;
    u8 var_a0;
    s8* var_v1;

    sp30 = &D_8006FF00[arg1->unk_00.unk_00 - 1];
    sp34.raw = 0;

    Text_CopySpeciesName(sp38, arg1->unk_00.unk_00);

    if (HAL_Strcmp(arg1->unk_30, sp38) != 0) {
        var_a0 = ((arg1->unk_0E >> 8) & 0xFF) + (arg1->unk_0E & 0xFF);

        if (1) {}

        var_v1 = arg1->unk_30;
        while (*var_v1) {
            var_a0 += *var_v1++ & 0xFF;
            var_a0 += 0;
        }

        var_v1 = arg1->unk_3B;
        while (*var_v1) {
            var_a0 += *var_v1++ & 0xFF;
            var_a0 += 0;
        }

        sp34.unk_00 = ((((sp30->unk_12 - sp30->unk_10) << 6) * var_a0) / 255) + (sp30->unk_10 << 6);
    }

    *arg0 = sp34;
    return arg0;
}

void Model_ComputeSizeVariantFromRecord(arg1_func_80010CA8* arg0, unk_func_8001C014* arg1, u16 arg2) {
    BattleMon stack;

    stack.unk_00.unk_00 = arg2;
    stack.unk_0E = arg1->unk_02;

    _bcopy(arg1->unk_04, stack.unk_30, 0x10);
    _bcopy(arg1->unk_14, stack.unk_3B, 0x10);
    Model_ComputeSizeVariant(arg0, &stack);
}

void Trainer_RequestPokeIcon(BattleSessionTeams* arg0) {
    arg1_func_80010CA8 sp2C;
    s16 sp2A;
    TeamRoster* temp_a1;

    sp2A = arg0->unk_02;
    sp2C.raw = 0;
    if (!(arg0->unk_00 & 0x40) && (arg0->unk_00 & 0x80)) {
        temp_a1 = arg0->unk_04;
        if ((temp_a1 != NULL) && (sp2A == arg0->unk_04->unk_000)) {
            Model_ComputeSizeVariant(&sp2C, (BattleMon*)arg0->unk_04);
            if ((sp2A == 0x19) && (arg0->unk_04->unk_01C[0].unk_30[6] & 0x80)) {
                sp2A = 0x99;
            }
        }
        if (!(arg0->unk_10->flags & 4)) {
            while (Display_IsFrameReady() == 0) {}
        }
        PokeIcon_RequestFrameLoad(arg0->unk_10, (u16) sp2A, sp2C);
        arg0->unk_00 |= 0x40;
        arg0->unk_00 &= ~0x10;

        if (arg0->unk_00 & 0x20) {
            PokeIcon_WaitFrameLoad(arg0->unk_10);
            arg0->unk_14 = arg0->unk_10->loadedModel;
            arg0->unk_00 &= ~0xE0;
        }
    }
}

void PokeIcon_PollFrameLoadForObject(unk_func_8001C248* arg0) {
    if (PokeIcon_PollFrameLoad(arg0->node.callback)) {
        arg0->node.callbackArg = arg0->node.callback->loadedModel;
        arg0->node.type &= ~0xE0;
        arg0->node.type |= 0x10;
    }
}

void PokeIcon_WaitFrameLoadForObject(unk_func_8001C248* arg0) {
    if (arg0->node.type & 0x40 && PokeIcon_WaitFrameLoad(arg0->node.callback) != 0) {
        arg0->node.callbackArg = arg0->node.callback->loadedModel;
        arg0->node.type &= ~0xE0;
        arg0->node.type |= 0x10;
    }
}

void PokeIcon_RequestBackgroundForObject(unk_func_8001C248* arg0) {
    if (!(arg0->unk_01D & 0x40) && (arg0->unk_01D & 0x80)) {
        PokeIcon_RequestBackgroundLoad(arg0->node.callback, arg0->unk_020, arg0->unk_024);
        arg0->unk_01D |= 0x40;
        arg0->unk_01D &= ~0x10;
        if (arg0->unk_01D & 0x20) {
            PokeIcon_WaitBackgroundLoad(arg0->node.callback);
            arg0->unk_024 = arg0->node.callback->loadedBackground;
            arg0->unk_01D &= ~0xE0;
        }
    }
}

void PokeIcon_PollBackgroundForObject(unk_func_8001C248* arg0) {
    if (PokeIcon_PollBackgroundLoad(arg0->node.callback) != 0) {
        arg0->unk_024 = arg0->node.callback->loadedBackground;
        arg0->unk_01D &= ~0xE0;
        arg0->unk_01D |= 0x10;
    }
}
