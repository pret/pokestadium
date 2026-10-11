#include "model_animation.h"
#include "src/util.h"
#include "src/matrix.h"
#include "src/model_animation_events.h"

typedef struct unk_func_80016B30_arg0 {
    /* 0x00 */ Vec3s vec;
    /* 0x06 */ s16 unk_06;
} unk_func_80016B30_arg0; // size = 0x8

static unk_D_800ABCC0 D_800ABCC0[2];
static s32 D_800ABCF0;

f32 ModelAnim_EvaluateTranslationChannel(unk_D_800ABCC0* arg0, s32 arg1) {
    f32 ret;
    s32 var_a2;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];

    if (temp_v0->unk_00 == 1) {
        ret = temp_v0->unk_04 / 1000.0f;
    } else {
        if (arg0->unk_02 < temp_v0->unk_00) {
            var_a2 = temp_v0->unk_04 + arg0->unk_02;
        } else {
            var_a2 = (temp_v0->unk_04 + temp_v0->unk_00) - 1;
        }

        ret = arg0->unk_0C[var_a2] / 1000.0f;
    }

    return ret;
}

s16 ModelAnim_EvaluateRotationChannel(unk_D_800ABCC0* arg0, s32 arg1) {
    s32 var_a1;
    s16 var_v1;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];

    if (temp_v0->unk_01 == 1) {
        var_v1 = temp_v0->unk_06 * 0x10;
    } else {
        if (arg0->unk_02 < temp_v0->unk_01) {
            var_a1 = temp_v0->unk_06 + arg0->unk_02;
        } else {
            var_a1 = (temp_v0->unk_06 + temp_v0->unk_01) - 1;
        }
        var_v1 = PackedBits_ReadSigned(arg0->unk_10, var_a1, 0xC) * 0x10;
    }
    return var_v1;
}

f32 ModelAnim_EvaluateScaleChannel(unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    s16 var_a2;
    s32 var_a1;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];

    if (temp_v0->unk_02 == 1) {
        if (arg0->unk_01 & 4) {
            var_fv1 = (s16)temp_v0->unk_08;
        } else {
            var_a2 = temp_v0->unk_08 * 0x10;
            var_fv1 = var_a2 >> 4;
        }
    } else {
        if (arg0->unk_02 < temp_v0->unk_02) {
            var_a1 = temp_v0->unk_08 + arg0->unk_02;
        } else {
            var_a1 = (temp_v0->unk_08 + temp_v0->unk_02) - 1;
        }

        if (arg0->unk_01 & 4) {
            var_fv1 = PackedBits_ReadSigned(arg0->unk_14, var_a1, 0x10);
        } else {
            var_fv1 = PackedBits_ReadSigned(arg0->unk_14, var_a1, 0xC);
        }
    }

    return var_fv1;
}

f32 ModelAnim_InterpolateKeyframe(Vec3s* arg0, s16 arg1, s16 arg2) {
    f32 y;
    s32 i;
    f32 x;
    f32 var_fv1;

    if (arg0->x >= arg2) {
        var_fv1 = arg0->y;
    } else {
        if (arg2 >= arg0[arg1 - 1].x) {
            var_fv1 = arg0[arg1 - 1].y;
        } else {
            for (i = 0; i < arg1 - 2; i++) {
                if (arg2 < arg0[i + 1].x) {
                    break;
                }
            }

            x = (arg2 - arg0[i].x) / 30.0f;
            y = 30.0f / (arg0[i + 1].x - arg0[i].x);

            var_fv1 = (arg0[i].y * (((2.0f * x * x * x * y * y * y) - 3.0f * x * x * y * y) + 1.0f))
                    + (arg0[i + 1].y * ((-2.0f * x * x * x * y * y * y) + 3.0f * x * x * y * y))
                    + (arg0[i].z * ((x * x * x * y * y - (2.0f * x * x * y)) + x))
                    + (arg0[i + 1].z * (x * x * x * y * y - (x * x * y)));
        }
    }
    return var_fv1;
}

f32 ModelAnim_InterpolateKeyframeTangent(unk_func_80016B30_arg0* arg0, s16 arg1, s16 arg2) {
    f32 y;
    s32 i;
    f32 x;
    f32 var_fv1;

    if (arg0->vec.x >= arg2) {
        var_fv1 = arg0->vec.y;
    } else {
        if (arg2 >= arg0[arg1 - 1].vec.x) {
            var_fv1 = arg0[arg1 - 1].vec.y;
        } else {
            for (i = 0; i < arg1 - 2; i++) {
                if (arg2 < arg0[i + 1].vec.x) {
                    break;
                }
            }

            x = (arg2 - arg0[i].vec.x) / 30.0f;
            y = 30.0f / (arg0[i + 1].vec.x - arg0[i].vec.x);

            var_fv1 = (arg0[i].vec.y * (((2.0f * x * x * x * y * y * y) - 3.0f * x * x * y * y) + 1.0f))
                    + (arg0[i + 1].vec.y * ((-2.0f * x * x * x * y * y * y) + 3.0f * x * x * y * y))
                    + (arg0[i].unk_06 * ((x * x * x * y * y - (2.0f * x * x * y)) + x))
                    + (arg0[i + 1].vec.z * (x * x * x * y * y - (x * x * y)));
        }
    }
    return var_fv1;
}

f32 ModelAnim_EvaluateTranslationCurve(unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];
    s16* tmp;

    if (temp_v0->unk_00 < 2) {
        var_fv1 = (s16)temp_v0->unk_04 / 100.0f;
    } else {
        tmp = &arg0->unk_0C[temp_v0->unk_04];
        if (temp_v0->unk_03 & 4) {
            var_fv1 = ModelAnim_InterpolateKeyframeTangent(tmp, temp_v0->unk_00, arg0->unk_02) / 100.0f;
        } else {
            var_fv1 = ModelAnim_InterpolateKeyframe(tmp, temp_v0->unk_00, arg0->unk_02) / 100.0f;
        }
    }
    return var_fv1;
}

s16 ModelAnim_EvaluateRotationCurve(unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    s16* temp_a0;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];

    if (temp_v0->unk_01 < 2) {
        var_fv1 = (s16)temp_v0->unk_06 / 10.0f;
    } else {
        temp_a0 = &arg0->unk_10[temp_v0->unk_06];
        if (temp_v0->unk_03 & 2) {
            var_fv1 = ModelAnim_InterpolateKeyframeTangent(temp_a0, temp_v0->unk_01, arg0->unk_02) / 10.0f;
        } else {
            var_fv1 = ModelAnim_InterpolateKeyframe(temp_a0, temp_v0->unk_01, arg0->unk_02) / 10.0f;
        }
    }

    while (var_fv1 < 0.0f) {
        var_fv1 += 360.0f;
    }

    while (var_fv1 >= 360.0f) {
        var_fv1 -= 360.0f;
    }

    return (var_fv1 / 360.0f) * 65536.0f;
}

f32 ModelAnim_EvaluateScaleCurve(unk_D_800ABCC0* arg0, s32 arg1) {
    s16* temp_a0;
    f32 var_fv0;
    f32 var_fv1;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];

    if (temp_v0->unk_02 < 2) {
        var_fv1 = (s16)temp_v0->unk_08;
    } else {
        temp_a0 = &arg0->unk_14[temp_v0->unk_08];
        if (temp_v0->unk_03 & 1) {
            var_fv0 = ModelAnim_InterpolateKeyframeTangent(temp_a0, temp_v0->unk_02, arg0->unk_02);
        } else {
            var_fv0 = ModelAnim_InterpolateKeyframe(temp_a0, temp_v0->unk_02, arg0->unk_02);
        }
        var_fv1 = var_fv0;
    }
    return var_fv1;
}

typedef union AnimFixedFrame {
    struct {
        s16 whole;
        s16 fraction; // low 16 bits; signed declaration retained for matching
    };
    s32 raw;
} AnimFixedFrame; // size = 0x4

typedef struct TransformAnimRaw {
    /* 0x00 */ s16 animationId;
    /* 0x04 */ TransformAnimData* data;
    /* 0x08 */ AnimFixedFrame frameFixed;
    /* 0x0C */ s32 speedFixed;
    /* 0x10 */ char unk10[0x2];
    /* 0x12 */ u16 lastRenderFrame;
} TransformAnimRaw; // size >= 0x14

s32 ModelAnim_AdvanceCurveFrame(TransformAnimRaw* arg0, u16 arg1) {
    AnimFixedFrame spC;
    AnimFixedFrame* ptr;
    TransformAnimData* temp_v0;

    ptr = &spC;
    temp_v0 = arg0->data;
    spC.raw = arg0->frameFixed.raw;
    if (arg0->lastRenderFrame != arg1) {
        spC.raw += arg0->speedFixed;
        if (arg0->speedFixed >= 0) {
            if (ptr->whole >= temp_v0->endFrame) {
                if (temp_v0->flags & 2) {
                    ptr->whole = temp_v0->endFrame - 1;
                } else {
                    ptr->whole = temp_v0->loopStart;
                }
            }
        } else {
            if (ptr->whole < temp_v0->loopStart) {
                if (temp_v0->flags & 2) {
                    ptr->whole = temp_v0->loopStart;
                } else {
                    ptr->whole = temp_v0->endFrame - 1;
                }
            }
        }
    }

    return spC.raw;
}

void ModelAnim_ResetCurveContext(void) {
    D_800ABCF0 = -1;
}

void ModelAnim_BeginCurveContext(TransformAnimState* arg0, u16 arg1, s32 arg2) {
    TransformAnimData* temp_s1;
    unk_D_800ABCC0* temp_s0;

    temp_s1 = arg0->data;

    D_800ABCF0++;
    if (D_800ABCF0 < 2) {
        temp_s0 = &D_800ABCC0[D_800ABCF0];
        if (arg0->data != NULL) {
            if (arg2 != 0) {
                arg0->frameFixed = ModelAnim_AdvanceCurveFrame(arg0, arg1);
            }

            arg0->lastRenderFrame = arg1;

            temp_s0->unk_00 = 1;
            temp_s0->unk_01 = arg0->data->flags;
            temp_s0->unk_02 = arg0->frameFixed >> 0x10;
            temp_s0->unk_04 = temp_s1;
            temp_s0->unk_08 = Util_ConvertAddrToVirtAddr(temp_s1->channelTable);
            temp_s0->unk_0C = Util_ConvertAddrToVirtAddr(temp_s1->translationData);
            temp_s0->unk_10 = Util_ConvertAddrToVirtAddr(temp_s1->rotationData);
            temp_s0->unk_14 = Util_ConvertAddrToVirtAddr(temp_s1->scaleData);

            if (temp_s0->unk_02 < 0) {
                temp_s0->unk_02 = 0;
            }
        } else {
            temp_s0->unk_00 = 0;
        }
    }
}

void ModelAnim_EndCurveContext(void) {
    if (D_800ABCF0 >= 0) {
        D_800ABCF0--;
    }
}

void ModelAnim_EvaluateJointTransform(Vec3f* arg0, Vec3s* arg1, Vec3f* arg2, s32 arg3) {
    if ((D_800ABCF0 >= 0) && (D_800ABCF0 < 2)) {
        unk_D_800ABCC0* temp_s0 = &D_800ABCC0[D_800ABCF0];

        if ((temp_s0->unk_00 == 1) && (arg3 >= 0) && (arg3 + 2 < temp_s0->unk_04->channelCount)) {
            if (temp_s0->unk_01 & 8) {
                arg0->x = ModelAnim_EvaluateScaleCurve(temp_s0, arg3 + 0);
                arg0->y = ModelAnim_EvaluateScaleCurve(temp_s0, arg3 + 1);
                arg0->z = ModelAnim_EvaluateScaleCurve(temp_s0, arg3 + 2);

                arg1->x = ModelAnim_EvaluateRotationCurve(temp_s0, arg3 + 0);
                arg1->y = ModelAnim_EvaluateRotationCurve(temp_s0, arg3 + 1);
                arg1->z = ModelAnim_EvaluateRotationCurve(temp_s0, arg3 + 2);

                arg2->x = ModelAnim_EvaluateTranslationCurve(temp_s0, arg3 + 0);
                arg2->y = ModelAnim_EvaluateTranslationCurve(temp_s0, arg3 + 1);
                arg2->z = ModelAnim_EvaluateTranslationCurve(temp_s0, arg3 + 2);
            } else {
                arg0->x = ModelAnim_EvaluateScaleChannel(temp_s0, arg3 + 0);
                arg0->y = ModelAnim_EvaluateScaleChannel(temp_s0, arg3 + 1);
                arg0->z = ModelAnim_EvaluateScaleChannel(temp_s0, arg3 + 2);

                arg1->x = ModelAnim_EvaluateRotationChannel(temp_s0, arg3 + 0);
                arg1->y = ModelAnim_EvaluateRotationChannel(temp_s0, arg3 + 1);
                arg1->z = ModelAnim_EvaluateRotationChannel(temp_s0, arg3 + 2);

                arg2->x = ModelAnim_EvaluateTranslationChannel(temp_s0, arg3 + 0);
                arg2->y = ModelAnim_EvaluateTranslationChannel(temp_s0, arg3 + 1);
                arg2->z = ModelAnim_EvaluateTranslationChannel(temp_s0, arg3 + 2);
            }
        }
    }
}

void ModelAnim_ClearTransformChannel(DisplayObject* arg0) {
    arg0->transformAnim.animationId = -1;
    arg0->transformAnim.data = NULL;
}

s32 ModelAnim_BindTransformCurve(DisplayObject* arg0, s16 arg1, void* arg2, s32 arg3) {
    TransformAnimData* temp_v0 = Util_ConvertAddrToVirtAddr(arg2);
    TransformAnimState* ptr = &arg0->transformAnim;

    if ((temp_v0 != ptr->data) || (arg1 != ptr->animationId)) {
        ptr->animationId = arg1;
        ptr->data = temp_v0;
        ptr->frameFixed = (temp_v0->startFrame << 0x10) - arg3;
    }

    ptr->speedFixed = arg3;
    return ptr->frameFixed >> 0x10;
}

s32 ModelAnim_SetSpeed(DisplayObject* arg0, s32 arg1) {
    arg0->transformAnim.speedFixed = arg1;
    return arg0->transformAnim.frameFixed >> 0x10;
}

void ModelAnim_SetFrame(DisplayObject* arg0, s16 arg1) {
    arg0->transformAnim.frameFixed = (arg1 << 0x10) - arg0->transformAnim.speedFixed;
}

s32 ModelAnim_HasCrossedFrame(DisplayObject* arg0, s16 arg1) {
    TransformAnimState* ptr = &arg0->transformAnim;
    s32 temp_v0 = ptr->frameFixed + ptr->speedFixed;
    s32 arg = arg1 << 0x10;
    s32 var_a2;
    s32 v = ptr->speedFixed;

    if (v >= 0) {
        var_a2 = ptr->frameFixed < arg;
        if (var_a2 != 0) {
            var_a2 = temp_v0 >= arg;
        }
    } else {
        var_a2 = (arg < ptr->frameFixed);
        if (var_a2 != 0) {
            var_a2 = arg >= temp_v0;
        }
    }

    return var_a2;
}

s32 ModelAnim_IsAnimationDone(DisplayObject* arg0) {
    return ModelAnim_HasCrossedFrame(arg0, arg0->transformAnim.data->endFrame - 1);
}

s32 ModelAnim_IsFinished(DisplayObject* arg0) {
    return arg0->transformAnim.frameFixed >= ((arg0->transformAnim.data->endFrame - 1) << 0x10);
}
