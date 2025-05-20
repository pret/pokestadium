#ifndef _3FB0_H_
#define _3FB0_H_

#include "global.h"
#include "5580.h"
#include "C970.h"
#include "CE80.h"
#include "src/memmap.h"
#include "src/memory.h"

typedef struct ret_func_8000484C {
	/* 0x00 */ char unk00[0x90];
	/* 0x90 */ s32 unk_90;
} ret_func_8000484C; // size >= 0x94

typedef struct PERSSZP {
    /* 0x00 */ char magic[0x8]; // PERS-SZP
    /* 0x08 */ u32 header_size;
    /* 0x0C */ u32 decompressed_size1; // How do these differ?
    /* 0x10 */ u32 decompressed_size2;
    /* 0x14 */ u32 unk_14;
} PERSSZP; // sze = 0x18

typedef struct PRESJPEG {
    /* 0x00 */ char magic[0x8]; // PRESJPEG
    /* 0x08 */ u32 unk_08; // header size? always 0x10
    /* 0x0C */ u32 unk_0C; 
} PRESJPEG; // size = 0x10

typedef struct Yay0 {
    /* 0x00 */ char magic[0x4]; // Yay0
    /* 0x04 */ u32 decompressed_size;
    /* 0x08 */ u32 link_table_offset;
    /* 0x0C */ u32 byte_chunk_offset;
} Yay0; // size = 0x10

typedef struct BinArchive {
    union {
        struct {
            /* 0x00 */ u16 unk_00;
            /* 0x02 */ u16 unk_02;
        };
        s32 raw;
    };
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ u32 total_size;
    /* 0x0C */ u32 num_files;
} BinArchive; // size = 0x10

typedef struct BinArchiveFile {
    /* 0x00 */ u32 offset;
    /* 0x04 */ u32 size;
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ char unk0C[0x4];
} BinArchiveFile; // size = 0x10

typedef struct unk_func_800041C0 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} unk_func_800041C0; // size >= 0x8

typedef struct unk_func_80003680_sp300 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0x2];
    /* 0x04 */ s16 width;
    /* 0x06 */ s16 height;
    /* 0x08 */ u8* quantization_table;
    /* 0x0C */ u8* huffman_table;
    /* 0x10 */ u8* start_of_frame;
    /* 0x14 */ u8* start_of_scan;
} unk_func_80003680_sp300; // size = 0x18

typedef struct unk_func_80003680_sp90 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} unk_func_80003680_sp90; // size >= 0x18

typedef void (*ret_func_80004454)(void);

s32 func_800033B0(u8* arg0);
void func_800033C8(unk_func_80003680_sp300* arg0, u8* arg1);
void func_80003558(UnkStruct80001380* arg0, unk_func_80003680_sp90* arg1);
void func_80003608(unk_func_80003680_sp27* arg0, unk_func_80003680_spB0* arg1, unk_func_80003680_sp300* arg2);
void func_80003648(unk_func_80003680_sp90* arg0, u8(arg1)[2][0x80], unk_func_80003680_sp300* arg2);
s32 func_80003680(u32 addr, s32 arg1, u8* arg2);
void func_80003860(void);
void func_80003890(u8* in_header, u8* memory);
void func_80003964(u8* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_80003A14(u8* arg0, s16 arg1, s16 arg2, s32 arg3);
s32 func_80003B04(s16 arg0);
void func_80003B30(u32 arg0, u32 arg1, u32 arg2, s32 arg3);
void func_80003BE0(u8* arg0, u8* arg1, u8* arg2);
void* func_80003C80(u8* addr, PRESJPEG* arg1, s32 side);
s32 func_80003D18(s32 arg0, PERSSZP* arg1, s32 side);
u32* func_80003D64(u8* arg0, s32 arg1, u32 arg2, s32 arg3);
void* func_80003DC4(u8* romStart, u8* romEnd, s32 arg2, s32 arg3);
void* func_80003F54(unk_func_800041C0* arg0, s32 arg1);
unk_func_800041C0* func_80004098(unk_func_800041C0* arg0, s32 arg1, s32 arg2);
unk_func_800041C0* func_800040EC(unk_func_800041C0* arg0, u32 arg1, u32 offset, u32 size);
void func_800041C0(s32 arg0, s32 arg1, s32 arg2);
void func_80004200(u32 block_addr, u32 addr);
u8* func_80004258(s32 id, u8* rom_start, u8* rom_end, s32 arg3);
MainPoolBlock* func_800042E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80004364(u32 base_addr, u32 addr);
void func_800043BC(s32 arg0, Fragment* addr);
ret_func_80004454 func_80004454(s32 arg0, u8* romStart, u8* romEnd);
void* func_800044A8(s32 arg0, s32 arg1, s32 arg2);
BinArchive* func_800044F4(u8* romStart, u8* romEnd, s32 arg2, s32 arg3);
void* func_80004660(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800047A4(void* arg0);
Fragment* func_800047C4(BinArchive* arg0, BinArchiveFile* arg1);
void* func_80004804(BinArchive* arg0, BinArchiveFile* arg1);
void* func_8000484C(BinArchive* archive, s32 file_number);
s32 func_8000495C(BinArchive* archive, s32 file_number);

#endif // _3FB0_H_
