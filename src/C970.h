#ifndef _C970_H_
#define _C970_H_

#include "global.h"

typedef struct JpegHuffmanTable {
    /* 0x00 */ u8 codeOffs[16];
    /* 0x10 */ u16 codesA[16];
    /* 0x30 */ u16 codesB[16];
    /* 0x50 */ u8* symbols;
} JpegHuffmanTable; // size = 0x54

void func_8000BD70(u8* in_quantization_tables, u8* out_quantization_tables, s32 num_tables);
s32 func_8000C02C(u8*, JpegHuffmanTable*, u8*, u16*, s32);
u16 func_8000BEC8(u8* data, JpegHuffmanTable* ht, u16* codes);

#endif // _C970_H_
