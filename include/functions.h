#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"

extern void func_80057FD0(void *, int);
extern s32 func_8005A990(OSPiHandle *);

// bcopy.s
extern void _bcopy(void *, void *, u32);

// 3FB0.s
extern void func_80003B30(void *, s32, s32, s32); // types unknown

// 5580.s
extern void func_80004CC0(OSThread *, s32, s32);
extern void func_80004CF4(void *); // types unknown
extern void func_80004D20(void *); // types unknown
extern void func_800052B4(void);
extern void func_800053B4(void *, s32); // types unknown
extern void func_80005328(void *); // types unknown

// 6BC0.s
extern u32 func_80006314(s32, s32, s32, s32, s32); // types unknown

// 75F0.s
extern void HAL_Printf(s32 x, s32 y, char *str, ...);

// C030.s
extern s32 func_8000B4C4(void);

// Yay0.s
extern void Yay0_Decompress(void* src, void* dst);

// D470.s
extern void func_8000C8F8(void);
extern void func_8000CEE4(s32, s32, void *, OSMesgQueue *);
extern void func_8000D0B4(s32, s32, s32, void *, s32, OSMesgQueue *);

// DDC0.s
extern void func_8000D564(void);

// E570.s
extern void func_8000D970(OSPfs *);

// 29BA0.s
extern void func_8002B274(s32, s32);

// exception_set.s
extern void set_watch_lohi(s32);

#endif
