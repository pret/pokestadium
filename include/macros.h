#ifndef _MACROS_H_
#define _MACROS_H_


#ifndef __sgi
#define GLOBAL_ASM(...)
#endif

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))


#endif
