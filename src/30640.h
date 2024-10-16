#ifndef _30640_H_
#define _30640_H_

#include "global.h"
#include "1C720.h"

typedef struct unk_D_83407AC8 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03[11];
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
    /* 0x10 */ u8 unk_10;
} unk_D_83407AC8; // size >= 0x12

typedef struct unk_D_83402EE0_070 {
    /* 0x00 */ char unk00[0x1A];
} unk_D_83402EE0_070; // size = 0x1A

void func_8002FA40(void);
void func_8003107C(unk_D_83402EE0_070*, unk_func_80026268_arg0*);
void func_80031140(unk_func_80026268_arg0*, unk_D_83407AC8*);
f32 func_80031A6C(f32);
void func_80031EF4(MtxF*, MtxF*);
void func_80032034(MtxF* arg0, Vec3f* arg1);

#endif // _30640_H_
