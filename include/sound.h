#ifndef _SOUND_H
#define _SOUND_H

#include <ultra64.h>
#include <PR/libaudio.h>

typedef struct SoundBank {
  /* 0x00 */ char header_name[16]; // N64 PtrTablesV2\x0
  /* 0x10 */ u32 flags;
  /* 0x14 */ char wbk_name[12];
  /* 0x20 */ s32 count;
  /* 0x24 */ char* basenote;
  /* 0x28 */ f32* detune;
  /* 0x2C */ ALWaveTable** wave_list;
} SoundBank; // size = 0x30

#endif
