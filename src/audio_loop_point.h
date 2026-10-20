#ifndef _4BDC0_H_
#define _4BDC0_H_

#include "global.h"

void Audio_FadeOutAll(s32);
s32 Audio_StartMusicTrack(s32 track_id);
s32 Audio_StartTrackForCategory(s32, s32);
s32 Audio_UpdateSpecialSequence(s32, u32);
u32 Audio_GetSpecialSequenceState(void);

#endif // _4BDC0_H_
