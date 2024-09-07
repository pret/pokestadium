#ifndef _3FB0_H_
#define _3FB0_H_

#include "global.h"

typedef struct ret_func_8000484C {
	/* 0x00 */ char unk00[0x90];
	/* 0x90 */ s32 unk_90;
} ret_func_8000484C; // size >= 0x94

// PERS-SZP header
typedef struct UnkInputStruct80003D18 {
    char filler0[0x10];
    u32 unk10;
} UnkInputStruct80003D18;

// PERSJPEG header
typedef struct UnkInputStruct80003C80 {
    char filler0[0x8];
    u32 unk8;
    u32 unkC;
} UnkInputStruct80003C80;

s32 func_80003C80(s32 arg0, UnkInputStruct80003C80* arg1, s32 side);
s32 func_80003D18(s32 arg0, UnkInputStruct80003D18* arg1, s32 side);
void* func_80003DC4(u8* romStart, u8* romEnd, s32 arg2, s32 arg3);
s32 func_80004258(s32 id, u8* rom_start, u8* rom_end, s32 arg3);
void* func_80004454(s32 arg0, u8* romStart, u8* romEnd);
void* func_800044F4(u8* romStart, u8* romEnd, s32 arg2, s32 arg3);

#endif // _3FB0_H_
