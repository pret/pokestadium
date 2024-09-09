#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"

void func_80057FD0(void *, int);
s32 func_8005A990(OSPiHandle *);

// bcopy.s
void _bcopy(void *, void *, u32);

// 5580.s
void func_80004CC0(OSThread *, s32, s32);
void func_80004CF4(void *); // types unknown
void func_80004D20(void *); // types unknown
void func_800052B4(void);
void func_80005328(void *); // types unknown

// C030.s
s32 func_8000B4C4(void);

// Yay0.s
void Yay0_Decompress(void* src, void* dst);

// D470.s
void func_8000C8F8(void);
void func_8000CEE4(s32, s32, void *, OSMesgQueue *);
void func_8000D0B4(s32, s32, s32, void *, s32, OSMesgQueue *);

// DDC0.s
void func_8000D564(void);

// E570.s
void func_8000D970(OSPfs *);

// exception_set.s
void set_watch_lohi(s32);

u32 osGetCount(void);

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

#endif
