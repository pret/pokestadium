#ifndef MATH_H
#define MATH_H

#include "PR/ultratypes.h"

#define M_SQRT2 1.41421356237309504880f
#define M_SQRT1_2 0.70710678118654752440f	/* 1/sqrt(2) */
#define FLT_MAX 340282346638528859811704183484516925440.0f
#define SHT_MAX 32767.0f
#define SHT_MINV (1.0f / SHT_MAX)

extern long long __d_to_ll(double d);
extern long long __f_to_ll(float f);
extern unsigned long long __d_to_ull(double d);
extern unsigned long long __f_to_ull(float f);
extern double __ll_to_d(long long s);
extern float __ll_to_f(long long s);
extern double __ull_to_d(unsigned long long u);
extern float __ull_to_f(unsigned long long u);

typedef float MtxF_t[4][4];
typedef union {
    MtxF_t mf;
    struct {
        float xx, yx, zx, wx,
              xy, yy, zy, wy,
              xz, yz, zz, wz,
              xw, yw, zw, ww;
    };
} MtxF;

typedef struct Vec3f {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Vec3f; // size = 0xC

typedef struct Vec3s {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} Vec3s; // size = 0x6

#endif
