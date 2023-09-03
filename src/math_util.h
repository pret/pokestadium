#ifndef _MATH_UTIL_H_
#define _MATH_UTIL_H_

extern f32 gSineTable[];
extern f32 gCosineTable[0x1000];
extern s16 gArctanTable[0x401];

u16 MathUtil_Atan2Lookup(f32 y, f32 x);
s16 MathUtil_Atan2s(f32 y, f32 x);
s32 MathUtil_Random16(void);
f32 MathUtil_Random_ZeroOne(void);

#endif // _MATH_UTIL_H_
