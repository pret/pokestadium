#ifndef _1C720_H_
#define _1C720_H_

#include "global.h"
#include "src/game_state.h"

typedef struct unk_func_8001C014 {
	/* 0x00 */ char unk_00[0x2];
	/* 0x02 */ u16 unk_02;
	/* 0x04 */ s8 unk_04[0x10];
	/* 0x14 */ s8 unk_14[0x10];
} unk_func_8001C014; // size >= 0x24

typedef struct unk_func_8001C248 {
    /* 0x000 */ DisplayNodeHeader node;
    /* 0x018 */ s16 unk_018;
    /* 0x01A */ s16 unk_01A;
    /* 0x01C */ u8 unk_01C;
    /* 0x01D */ u8 unk_01D;
    /* 0x01E */ char unk01E[0x2];
    /* 0x020 */ s32 unk_020;
    /* 0x024 */ s32* unk_024;
} unk_func_8001C248; // size >= 0x28

void ModelRenderer_InitDisplayRoots(void);
void ModelRenderer_AttachDisplayObject(DisplayObject* arg0);
void ModelRenderer_AttachSecondaryDisplayObject(DisplayObject* arg0);
void Model_InitDisplayObject(DisplayObject* display_object, s16 root_id, s16 object_type, ModelNodeView* child);
void ModelRenderer_ClearDisplayObject(DisplayObject* arg0);
s32 ModelAnim_SetAnimation(DisplayObject* arg0, s32 arg1);
s32 ModelAnim_SetEventTrack(DisplayObject* arg0, s32 arg1);
void Model_SetMaterialColor(DisplayObject* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
void Model_SetMaterialAlpha(DisplayObject* arg0, u8 arg1);
void Model_SetMaterialTextureMode(DisplayObject* arg0, u8 arg1);
ModelAnimationBank* ModelAnim_GetAnimationRecord(DisplayObject* arg0, s32 arg1);
arg1_func_80010CA8* Model_ComputeSizeVariant(arg1_func_80010CA8* arg0, BattleMon* arg1);
void Model_ComputeSizeVariantFromRecord(arg1_func_80010CA8* arg0, unk_func_8001C014* arg1, u16 arg2);
void Trainer_RequestPokeIcon(BattleSessionTeams* arg0);
void PokeIcon_PollFrameLoadForObject(unk_func_8001C248* arg0);
void PokeIcon_WaitFrameLoadForObject(unk_func_8001C248* arg0);
void PokeIcon_RequestBackgroundForObject(unk_func_8001C248* arg0);
void PokeIcon_PollBackgroundForObject(unk_func_8001C248* arg0);

#endif // _1C720_H_
