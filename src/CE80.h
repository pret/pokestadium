#ifndef _CE80_H_
#define _CE80_H_

#include "global.h"
#include "C970.h"

typedef struct unk_func_80003680_sp27 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x08 */ unk_func_80003680_spB0* unk_08;
    /* 0x0C */ unk_func_80003680_spB0* unk_0C;
    /* 0x10 */ unk_func_80003680_spB0* unk_10;
    /* 0x14 */ unk_func_80003680_spB0* unk_14;
    /* 0x18 */ s8 unk_18;
} unk_func_80003680_sp27; // size == 0x1C

typedef struct unk_func_80003680_sp60 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
} unk_func_80003680_sp60; // size = 0x14

s32 func_8000C280(unk_func_80003680_sp27*, u32, u32, u8, unk_func_80003680_sp60*);
s32 func_8000C4A8(unk_func_80003680_spB0*, unk_func_80003680_spB0*, s16*, s16*);
s32 func_8000C644(unk_func_80003680_spB0*, s16*, s8*);
u16 func_8000C780(u8);

#endif // _CE80_H_
