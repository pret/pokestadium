#include "model_animation_events.h"
#include "src/util.h"

static unk_D_800ABD00 D_800ABD00[2];
static s32 D_800ABD20;

s32 ModelAnim_ResolveEventIndex(s32 arg0, unk_func_80017540_arg1* arg1, s32 arg2) {
    unk_func_80017540_arg1* temp_v0 = &arg1[arg2];
    s32 ret;

    if (arg0 < temp_v0->unk_00) {
        ret = arg0 + temp_v0->unk_02;
    } else {
        ret = (temp_v0->unk_02 + temp_v0->unk_00) - 1;
    }
    return ret;
}

s16 ModelAnim_AdvanceEventFrame(EventTrackState* arg0, u16 arg1) {
    s16 var_v1;
    EventTrackData* temp_v0;

    var_v1 = arg0->frame;
    temp_v0 = arg0->data;

    if (arg0->lastRenderFrame != arg1) {
        var_v1 += 1;
        if (var_v1 >= temp_v0->endFrame) {
            if (temp_v0->flags & 2) {
                var_v1 = temp_v0->endFrame - 1;
            } else {
                var_v1 = temp_v0->loopStart;
            }
        }
    }
    return var_v1;
}

void ModelAnim_ResetEventContext(void) {
    D_800ABD20 = -1;
}

void ModelAnim_BeginEventContext(EventTrackState* arg0, u16 arg1, s32 arg2) {
    EventTrackData* sp24;
    unk_D_800ABD00* temp_s0;

    sp24 = arg0->data;
    D_800ABD20++;
    if (D_800ABD20 < 2) {
        temp_s0 = &D_800ABD00[D_800ABD20];
        if (arg0->data != NULL) {
            if (arg2 != 0) {
                arg0->frame = ModelAnim_AdvanceEventFrame(arg0, arg1);
            }
            arg0->lastRenderFrame = arg1;
            temp_s0->unk_00 = 1;
            temp_s0->unk_02 = arg0->frame;
            temp_s0->unk_04 = sp24;
            temp_s0->unk_08 = Util_ConvertAddrToVirtAddr(sp24->trackTable);
            temp_s0->unk_0C = Util_ConvertAddrToVirtAddr(sp24->frameValues);
            if (temp_s0->unk_02 < 0) {
                temp_s0->unk_02 = 0;
            }
        } else {
            temp_s0->unk_00 = 0;
        }
    }
}

void ModelAnim_EndEventContext(void) {
    if (D_800ABD20 >= 0) {
        D_800ABD20--;
    }
}

void ModelAnim_GetEventAtFrame(unk_D_86002F34_alt11_018** arg0, unk_D_86002F34_alt11_018* arg1, s32 arg2) {
    unk_D_800ABD00* sp1C;

    if ((D_800ABD20 >= 0) && (D_800ABD20 < 2)) {
        sp1C = &D_800ABD00[D_800ABD20];
        if ((sp1C->unk_00 == 1) && (arg2 >= 0) && (arg2 < sp1C->unk_04->trackCount)) {
            *arg0 = &arg1[((u8*)sp1C->unk_0C)[ModelAnim_ResolveEventIndex(sp1C->unk_02, sp1C->unk_08, arg2)]];
        }
    }
}

void ModelAnim_ClearEventTrack(DisplayObject* arg0) {
    arg0->eventTrack.trackId = -1;
    arg0->eventTrack.data = 0;
}

s16 ModelAnim_BindEventTrack(DisplayObject* arg0, s16 arg1, s32 arg2) {
    EventTrackData* temp_v0 = Util_ConvertAddrToVirtAddr(arg2);
    EventTrackState* ptr = &arg0->eventTrack;

    if ((temp_v0 != ptr->data) || (arg1 != ptr->trackId)) {
        ptr->trackId = arg1;
        ptr->data = temp_v0;
        ptr->frame = temp_v0->startFrame - 1;
    }

    return ptr->frame;
}

void ModelAnim_SetEventFrame(DisplayObject* arg0, s16 arg1) {
    arg0->eventTrack.frame = arg1 - 1;
}

s32 ModelAnim_IsEventFrame(DisplayObject* arg0, s16 arg1) {
    return (arg0->eventTrack.frame + 1) == arg1;
}

s32 ModelAnim_IsEventTrackNearEnd(DisplayObject* arg0) {
    return (arg0->eventTrack.frame + 2) == arg0->eventTrack.data->endFrame;
}

s32 ModelAnim_IsEventTrackDone(DisplayObject* arg0) {
    return (arg0->eventTrack.frame + 1) == arg0->eventTrack.data->endFrame;
}
