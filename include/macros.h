#ifndef _MACROS_H_
#define _MACROS_H_

#define true 1
#define false 0

#ifndef __sgi
#define GLOBAL_ASM(...)
#endif

#ifdef _LANGUAGE_C
#define HW_REG(reg, type) *(volatile type*)((reg) | 0xA0000000)
#endif

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

#define SQ(x) ((x) * (x))
#define ROUND(x) (s32)(((x) >= 0.0) ? ((x) + 0.5) : ((x) - 0.5))

#define assert

// global typings
typedef unsigned long uintptr_t;

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#endif
