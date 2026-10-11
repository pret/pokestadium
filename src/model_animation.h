#ifndef _17300_H_
#define _17300_H_

#include "global.h"

typedef struct unk_D_800ABCC0_008 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
} unk_D_800ABCC0_008; // size = 0xA

typedef struct unk_D_800ABCC0 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ TransformAnimData* unk_04;
    /* 0x08 */ unk_D_800ABCC0_008* unk_08;
    /* 0x0C */ s16* unk_0C;
    /* 0x10 */ s16* unk_10;
    /* 0x14 */ s16* unk_14;
} unk_D_800ABCC0; // size = 0x18

f32 ModelAnim_EvaluateTranslationChannel(unk_D_800ABCC0* arg0, s32 arg1);
s16 ModelAnim_EvaluateRotationChannel(unk_D_800ABCC0* arg0, s32 arg1);
f32 ModelAnim_EvaluateScaleChannel(unk_D_800ABCC0* arg0, s32 arg1);
f32 ModelAnim_InterpolateKeyframe(Vec3s* arg0, s16 arg1, s16 arg2);
f32 ModelAnim_EvaluateTranslationCurve(unk_D_800ABCC0* arg0, s32 arg1);
s16 ModelAnim_EvaluateRotationCurve(unk_D_800ABCC0* arg0, s32 arg1);
f32 ModelAnim_EvaluateScaleCurve(unk_D_800ABCC0* arg0, s32 arg1);
void ModelAnim_ResetCurveContext(void);
void ModelAnim_BeginCurveContext(TransformAnimState* arg0, u16 arg1, s32 arg2);
void ModelAnim_EndCurveContext(void);
void ModelAnim_EvaluateJointTransform(Vec3f* arg0, Vec3s* arg1, Vec3f* arg2, s32 arg3);
void ModelAnim_ClearTransformChannel(DisplayObject* arg0);
s32 ModelAnim_BindTransformCurve(DisplayObject* arg0, s16 arg1, void* arg2, s32 arg3);
s32 ModelAnim_SetSpeed(DisplayObject* arg0, s32 arg1);
void ModelAnim_SetFrame(DisplayObject* arg0, s16 arg1);
s32 ModelAnim_HasCrossedFrame(DisplayObject* arg0, s16 arg1);
s32 ModelAnim_IsAnimationDone(DisplayObject* arg0);
s32 ModelAnim_IsFinished(DisplayObject* arg0);


#endif // _17300_H_
