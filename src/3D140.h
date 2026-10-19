#ifndef _3D140_H_
#define _3D140_H_

#include "global.h"

typedef struct CachedMoveData {
    /* 0x00 */ u8 lastMove;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
} CachedMoveData; // size = 0x6

typedef struct BattleMonRuntime {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0x2];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk06[0x5];
    /* 0x0B */ u8 id;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ u8 unk_14;
    /* 0x15 */ u8 unk_15;
    /* 0x16 */ u8 unk_16[9];
    /* 0x1F */ u8 moves[4];
    /* 0x23 */ char unk23[0x1];
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ u8 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ u16 unk_30;
    /* 0x32 */ u8 unk_32[4];
    /* 0x36 */ u16 unk_36;
    /* 0x38 */ u16 unk_38;
    /* 0x3A */ u16 unk_3A;
    /* 0x3C */ u16 unk_3C;
    /* 0x3E */ u16 unk_3E;
    /* 0x40 */ char unk40[0x4];
    /* 0x44 */ CachedMoveData moveCache;
    /* 0x4A */ u8 unk_4A;
    /* 0x4B */ u8 unk_4B;
    /* 0x4C */ u8 unk_4C;
    /* 0x4D */ u8 unk_4D;
    /* 0x4E */ u8 unk_4E;
    /* 0x4F */ u8 unk_4F;
    /* 0x50 */ u8 unk_50;
    /* 0x51 */ u8 unk_51;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
    /* 0x54 */ u16 unk_54;
    /* 0x56 */ u8 unk_56;
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ u8 unk_58;
    /* 0x59 */ u8 unk_59;
    /* 0x5A */ u8 usedMove;
    /* 0x5B */ u8 unk_5B;
    /* 0x5C */ u8 unk_5C[6];
    /* 0x62 */ char unk62[0x2];
} BattleMonRuntime; // size = 0x64

typedef struct amConfig {
    /* 0x00 */ u32 outputRate;
    /* 0x04 */ u32 framesPerField;
    /* 0x08 */ u32 maxACMDSize;
} amConfig; // size = 0xC

extern s32 mus_active_fade_handle;
extern f32 mus_fade_start_volume;
extern u8 mus_fade_target_volume;
extern f32 mus_fade_step_rate;
extern f32 D_80077DD4;
extern f32 D_80077DD8;
extern f32 D_80077DDC;
extern f32 D_80077DE0;
extern u8 mus_sound_effect_blocked;

extern BattleMonRuntime* D_800FCB18[4];

void amCreateAudioMgr(ALSynConfig*, amConfig*, u32, s32, s32);
OSTask* Audio_CreateFrameTask(OSTask*);
void __clearAudioDMA(void);
void Cry_PlayFromPokedex(s32);
void func_8003D32C(void);
s32 Cry_IsPlaying(void);
s32 Audio_SetEnabled(s32);
void Audio_SetVoiceEnabled(s32);
void Audio_SetChannelGroupCounts(u8, u8, u8, u8);
void Audio_ConfigureChannelGroups(u8, u8, u8, u8);
void Audio_SelectModeMusic(u32 arg0, u32 arg1);
void func_8003DB84(s32 arg0);
void func_8003EB40(s32, BattleMonRuntime*);
void func_8003F1AC(u32);
void func_8003F4C0(u32);
void Audio_QueuePendingSoundId(u32 arg0);
void func_8003F660(s32);
void func_80040A70(BattleMonRuntime* arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800414B8(s32);
void Audio_StartBattleMusicSequence(void);
void Audio_StartResultMusicSequence(void);
void Audio_UpdateBattleAudioFrame(void);
void func_80041A98(void);
void Audio_RemoveLastQueuedSequenceId(void);
void Audio_QueueSequenceId(u32 arg0);
void Audio_SwapSoundCandidates(u8* arg0, u8* arg1);
u16 Audio_FilterRecentSoundId(u16 arg0);
void Audio_RecordRecentSoundId(u16 arg0);
void Audio_RemoveRecentSoundAt(u16 arg0);
u32 Audio_SelectSoundAvoidingRecent(u16* arg0);
void Audio_QueueSoundAvoidingRecent(u16* arg0);

#endif // _3D140_H_
