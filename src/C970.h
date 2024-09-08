#ifndef _C970_H_
#define _C970_H_

#include "global.h"

typedef struct unk_func_80003680_spB0 {
    /* 0x00 */ char unk00[0x54];
} unk_func_80003680_spB0; // size = 0x54

void func_8000BD70(u8* in_quantization_tables, u8* out_quantization_tables, s32 num_tables);
void func_8000C02C(u8* in_huffman_table, unk_func_80003680_spB0*, u8*, u8*, s32);

#endif // _C970_H_
