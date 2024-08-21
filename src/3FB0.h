#ifndef _3FB0_H_
#define _3FB0_H_

#include "global.h"

typedef struct ret_func_8000484C {
	/* 0x00 */ char unk00[0x90];
	/* 0x90 */ s32 unk_90;
} ret_func_8000484C; // size >= 0x94

void* func_80003DC4(void* romStart, void* romEnd, s32 arg2, s32 arg3);
s32 func_80004258(s32 id, void* arg1, void* arg2, s32 arg3);
void *func_80004454(s32 arg0, void* romStart, void* romEnd);
void* func_800044F4(uintptr_t romStart, uintptr_t romEnd, s32 arg2, s32 arg3);
ret_func_8000484C* func_8000484C(void*, s32);

#endif // _3FB0_H_
