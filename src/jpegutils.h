#ifndef JPEGUTILS_H
#define JPEGUTILS_H

#include "global.h"

typedef struct JpegHuffmanTable {
    /* 0x00 */ u8 codeOffs[16];
    /* 0x10 */ u16 codesA[16];
    /* 0x30 */ u16 codesB[16];
    /* 0x50 */ u8* symbols;
} JpegHuffmanTable; // size = 0x54

typedef struct JpegQuantizationTable {
    /* 0x00 */ u16 table[8*8];
} JpegQuantizationTable; // size = 0x80

void JpegUtils_ProcessQuantizationTable(u8* dqt, JpegQuantizationTable* qt, u8 num_tables);
s32 JpegUtils_ProcessHuffmanTable(u8*, JpegHuffmanTable*, u8*, u16*, u8);
u16 JpegUtils_SetHuffmanTable(u8* data, JpegHuffmanTable* ht, u16* codes);

#endif // JPEGUTILS_H
