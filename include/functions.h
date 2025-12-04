#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"

void func_80057FD0(void *, int);
s32 func_8005A990(OSPiHandle *);

// 517A0.s
void func_80050BA0(s32, void*);

// 49190.s
void func_80048904(s32, s32, s32);
void func_80048590(s32, s32, void*, s16*);
void func_80048684(void*, s16, s32, s16*);

// bcopy.s
void _bcopy(void* src, void* dst, s32);

// C030.s
s32 func_8000B4C4(void);

// Yay0.s
void Yay0_Decompress(void* src, void* dst);

// DDC0.s
void func_8000D564(void);

// exception_set.s
void set_watch_lohi(s32);

u32 osGetCount(void);
OSIntMask osSetIntMask(OSIntMask);

unsigned long long __ull_rshift(unsigned long long a0, unsigned long long a1);
unsigned long long __ull_rem(unsigned long long a0, unsigned long long a1);
unsigned long long __ull_div(unsigned long long a0, unsigned long long a1);
unsigned long long __ll_lshift(unsigned long long a0, unsigned long long a1);
long long __ll_rem(unsigned long long a0, long long a1);
long long __ll_div(long long a0, long long a1);
unsigned long long __ll_mul(unsigned long long a0, unsigned long long a1);
void __ull_divremi(unsigned long long* div, unsigned long long* rem, unsigned long long a2, unsigned short a3);
long long __ll_mod(long long a0, long long a1);
long long __ll_rshift(long long a0, long long a1);

f32 abs_asm(f32);

f32 __cosf(f32);
f32 __sinf(f32);

#endif
