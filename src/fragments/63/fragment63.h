#ifndef _FRAGMENT63_H_
#define _FRAGMENT63_H_

#include "global.h"
#include "src/3FB0.h"
#include "src/1AB70.h"
#include "src/geo_layout.h"

typedef struct unk_D_84B19910_002 {
    /* 0x02 */ s16 unk_00;
    /* 0x04 */ s16 unk_02;
    /* 0x06 */ s16 unk_04;
} unk_D_84B19910_002; 

typedef struct unk_D_84B19910 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ unk_D_84B19910_002 unk_02;
    ///* 0x02 */ s16 unk_02;
    ///* 0x04 */ s16 unk_04;
    ///* 0x06 */ s16 unk_06;
} unk_D_84B19910; // size = 0x8

typedef struct unk_D_84B1A598 {
    /* 0x0000 */ char unk0000[0x1];
    /* 0x0001 */ u8 unk_0001;
    /* 0x0002 */ u8 unk_0002;
    /* 0x0003 */ u8 unk_0003;
    /* 0x0004 */ GraphNode* unk_0004;
    /* 0x0008 */ unk_D_86002F58_004_000 unk_0008[128];
    /* 0xB408 */ BinArchive* unk_B408;
    /* 0xB40C */ BinArchive* unk_B40C;
} unk_D_84B1A598; // size >= 0xB410

typedef struct unk_D_84B2665C {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk06[0x2];
} unk_D_84B2665C; // size >= 0x8

typedef struct unk_D_84B259A8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02[5];
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ void* unk_10;
    /* 0x14 */ void* unk_14;
    /* 0x18 */ void* unk_18;
    /* 0x1C */ void* unk_1C;
    /* 0x20 */ unk_D_86002F58_004_000* unk_20;
    /* 0x24 */ unk_D_86002F34* unk_24;
    /* 0x28 */ unk_D_86002F34* unk_28;
    /* 0x2C */ unk_D_86002F34* unk_2C;
    /* 0x30 */ unk_D_86002F34* unk_30;
    /* 0x34 */ unk_D_86002F34* unk_34;
    /* 0x38 */ unk_D_86002F34* unk_38;
    /* 0x3C */ char unk3C[0x4];
} unk_D_84B259A8; // size >= 0x40

typedef struct unk_D_84B259E8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ unk_D_86002F58_004_000* unk_08;
    /* 0x0C */ GraphNode* unk_0C;
    /* 0x10 */ u8* unk_10[4];
    /* 0x20 */ char unk20[0x10];
    /* 0x30 */ unk_D_80068BB0* unk_30[4];
} unk_D_84B259E8; // size >= 0x40

typedef struct unk_D_84B25A58 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x04 */ unk_D_86002F58_004_000* unk_04;
    /* 0x08 */ unk_D_86002F34* unk_08;
    /* 0x0C */ unk_D_86002F34* unk_0C;
    /* 0x10 */ unk_D_86002F34* unk_10;
    /* 0x14 */ unk_D_86002F34* unk_14;
    /* 0x18 */ unk_D_86002F34* unk_18;
    /* 0x1C */ unk_func_8001A024* unk_1C;
    /* 0x20 */ u16 (*unk_20)[0x640];
    /* 0x24 */ unk_D_80068BB0* unk_24;
    /* 0x28 */ unk_D_80068BB0* unk_28;
    /* 0x2C */ u8 unk_2C[12];
} unk_D_84B25A58; // size = 0x38

typedef struct unk_D_84B25A90 {
    /* 0x00 */ u8 unk_00;
    /* 0x00 */ u8 unk_01;
    /* 0x04 */ unk_D_86002F58_004_000* unk_04;
    /* 0x08 */ unk_D_86002F34* unk_08;
    /* 0x0C */ unk_D_86002F34* unk_0C;
    /* 0x10 */ unk_D_86002F34* unk_10;
    /* 0x14 */ unk_D_86002F34* unk_14;
    /* 0x18 */ unk_D_86002F34* unk_18;
    /* 0x1C */ u8* unk_1C;
    /* 0x20 */ u8* unk_20;
    /* 0x24 */ u8** unk_24;
    /* 0x28 */ s8 unk_28[4];
    /* 0x2C */ char unk2C[0x4];
} unk_D_84B25A90; // size = 0x30

typedef struct unk_D_84B25AC0_000 {
    /* 0x00 */ unk_D_86002F58_004_000* unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ Color_RGB8 unk_08;
    /* 0x0C */ u8* unk_0C;
} unk_D_84B25AC0_000; // size = 0x10

typedef struct unk_D_84B25AC0_0A0 {
    /* 0x00 */ unk_D_86002F58_004_000* unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ Color_RGBA8 unk_0A;
} unk_D_84B25AC0_0A0; // size = 0x10

typedef struct unk_D_84B25AC0 {
    /* 0x000 */ unk_D_84B25AC0_000 unk_000[10];
    /* 0x0A0 */ unk_D_84B25AC0_0A0 unk_0A0[10][8];
    /* 0x5A0 */ u8 unk_5A0;
    /* 0x5A1 */ s8 unk_5A1;
    /* 0x5A2 */ s8 unk_5A2;
    /* 0x5A3 */ s8 unk_5A3;
    /* 0x5A4 */ f32 unk_5A4;
    /* 0x5A8 */ unk_D_86002F58_004_000* unk_5A8;
    /* 0x5AC */ unk_D_86002F58_004_000* unk_5AC;
    /* 0x5B0 */ unk_D_86002F34* unk_5B0;
    /* 0x5B4 */ unk_D_86002F34* unk_5B4;
    /* 0x5B8 */ unk_D_86002F34* unk_5B8;
    /* 0x5BC */ char unk5BC[0x4];
} unk_D_84B25AC0; // size = 0x5C0

typedef struct unk_D_84B26640_010_010 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x04 */ unk_D_86002F58_004_000* unk_04;
    /* 0x08 */ unk_D_86002F34* unk_08;
} unk_D_84B26640_010; // size = 0xC

typedef struct unk_D_84B26640 {
    /* 0x00 */ unk_D_84B26640_010 unk_00;
    /* 0x00 */ char unk0C[0x4];
    /* 0x00 */ unk_D_84B26640_010 unk_10;
    /* 0x00 */ unk_D_84B2665C unk_1C;
    /* 0x00 */ unk_D_84B2665C unk_28;
} unk_D_84B26640; // size = 0x30

typedef struct unk_func_84B067B4 {
    /* 0x000 */ char unk00[0x10];
    /* 0x010 */ char unk_010[4];
    /* 0x014 */ char unk14[0x24];
    /* 0x038 */ u16 unk_038;
    /* 0x03A */ char unk03A[0x1F6];
} unk_func_84B067B4; // size = 0x230

typedef struct unk_D_84B17550 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
} unk_D_84B17550; // size = 0x12

extern unk_D_8006FF00 D_84B17620[];
extern unk_D_8006FF00 D_84B186C0[];

void func_84B00020(void);
void func_84B000F0(void);
void func_84B001D8(void);
void func_84B00280(void);
char* func_84B0037C(s32);
char* func_84B003AC(char* arg0, s32 arg1, u32 arg2);
s32 func_84B003D4(s32 arg0, unk_D_86002F34_alt8* arg1);
void func_84B00404(unk_D_86002F58_004_000* arg0);
void func_84B00478(void);
void func_84B0053C(s16, s16, s16, s16, u8, u8, u8, u8);
void func_84B00D3C(unk_D_80068BB0*, s16, u8*, u8*);
void func_84B0117C(s16 arg0);
void func_84B01474(s16 arg0);
void func_84B014DC(void);
void func_84B01538(void);
s32 func_84B01578(void);
void func_84B016F4(void);
void func_84B0174C(void);
s32 func_84B017AC(void);
void func_84B01994(void);
void func_84B01AA0(void);
void func_84B01B40(void);
void func_84B01C2C(void);
void func_84B01DBC(void);
void func_84B01F94(void);
void func_84B0204C(void);
void func_84B02188(void);
void func_84B021FC(void);
s32 func_84B022A0(void);
s32 func_84B023C0(void);
s32 func_84B02474(void);
s32 func_84B025D0(void);
s32 func_84B02654(void);
s32 func_84B02984(void);
s32 func_84B02C40(void);
u8 func_84B02DF8(void);
s32 func_84B02E5C(void);
s32 func_84B02F60(void);
void func_84B03064(void);
s32 func_84B03194(s32 arg0, UNUSED s32 arg1);

s16 func_84B033E0(void);
void func_84B0345C(unk_D_84B19910* arg0);
void func_84B03814(unk_D_84B19910* arg0);
void func_84B038F8(unk_D_84B19910* arg0);

s32 func_84B03A10(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B03AB4(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B03B58(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B03C20(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B03CC4(s32 arg0, unk_D_86002F34_alt5* arg1);
void func_84B03D08(unk_D_84B259A8* arg0, s16 arg1);
void func_84B03D74(unk_D_84B259A8* arg0, s16 arg1);
void func_84B03F10(unk_D_84B259A8* arg0, s16 arg1);
void func_84B040AC(unk_D_84B259A8* arg0, s16 arg1);
void func_84B04364(unk_D_84B259A8* arg0, s16 arg1);
void func_84B04628(unk_D_84B259A8* arg0);
void func_84B04798(unk_D_84B259A8* arg0);
void func_84B0492C(unk_D_84B259A8* arg0);
void func_84B04A7C(unk_D_84B259A8* arg0);
void func_84B04AE4(unk_D_84B259A8* arg0, s16 arg1, s16 arg2);
void func_84B04B5C(unk_D_84B259A8* arg0, s16 arg1, s16 arg2, s16 arg3);
void func_84B04CCC(unk_D_84B259A8* arg0, s16 arg1);
void func_84B04DB0(unk_D_84B259A8* arg0, s16 arg1);
void func_84B04E94(unk_D_84B259A8* arg0, s16 arg1);
void func_84B04F78(unk_D_84B259A8* arg0, unk_D_86002F58_004_000* arg1);
void func_84B0509C(unk_D_84B259A8* arg0);
void func_84B050AC(unk_D_84B259A8* arg0, unk_D_86002F58_004_000* arg1);
void func_84B05184(unk_D_84B259A8* arg0);
void func_84B0535C(unk_D_84B259A8* arg0);
void func_84B053F4(unk_D_84B259A8* arg0);
void func_84B055B8(unk_D_86002F34* arg0, Color_RGBA8* arg1, Color_RGBA8* arg2);
void func_84B05668(unk_D_84B259A8* arg0);
void func_84B05728(unk_D_84B259A8* arg0);
s32 func_84B05760(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B05844(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B05A2C(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B05B04(s32 arg0, unk_func_80011B94* arg1);
void func_84B05CE0(s32 arg0);
void func_84B05DD0(unk_D_84B259E8* arg0);
void func_84B05E64(unk_D_84B259E8* arg0);
void func_84B05F18(unk_D_84B259E8* arg0);
void func_84B05FCC(unk_D_84B259E8* arg0);
void func_84B06204(unk_D_84B259E8* arg0);
void func_84B062E4(unk_D_84B259E8* arg0);
void func_84B06364(unk_D_84B259E8* arg0, unk_D_86002F58_004_000* arg1, s16 arg2);
void func_84B064FC(unk_D_84B259E8* arg0, s16 arg1, char* arg2);
s32 func_84B06720(s32* arg0);
void func_84B067B4(unk_D_84B259E8* arg0, BinArchive* arg1, BinArchive* arg2);
void func_84B06A54(unk_D_84B259E8* arg0, BinArchive* arg1, BinArchive* arg2);

s32 func_84B06B50(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B06C7C(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B06E08(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B06ED0(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B06F60(unk_D_84B25A28* arg0, s16 arg1);
void func_84B07058(unk_D_84B25A28* arg0, s16 arg1);
s32 func_84B070EC(unk_D_84B25A28* arg0, s16 arg1);
s32 func_84B071C0(unk_D_84B25A28* arg0, s16 arg1);
void func_84B07294(unk_D_84B25A28* arg0);
void func_84B07370(unk_D_84B25A28* arg0);
void func_84B073D8(unk_D_84B25A28* arg0);
void func_84B07428(unk_D_84B25A28* arg0);
void func_84B07560(unk_D_84B25A28* arg0);
void func_84B07758(unk_D_84B25A28* arg0, BinArchive* arg1);
void func_84B07848(unk_D_84B25A28* arg0);
void func_84B07978(unk_D_84B25A28* arg0);
s32 func_84B07AB8(unk_D_84B25A28* arg0, unk_D_86002F58_004_000* arg1);
void func_84B07CF8(unk_D_84B25A28* arg0, unk_D_86002F34_00C* arg1);

s32 func_84B07EB0(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B07F78(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B080F4(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B08230(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B083D8(s32 arg0, unk_func_80011B94* arg1);
void func_84B0852C(unk_D_84B25A58* arg0, s32 arg1);
void func_84B08694(unk_D_84B25A58* arg0, s32 arg1);
void func_84B08858(unk_D_84B25A58* arg0, s32 arg1);
void func_84B08954(unk_D_84B25A58* arg0, s32 arg1);
void func_84B08A90(unk_D_84B25A58* arg0);
void func_84B08BFC(unk_D_84B25A58* arg0);
void func_84B08D54(unk_D_84B25A58* arg0);
void func_84B08F7C(unk_D_84B25A58* arg0);
void func_84B091A0(unk_D_84B25A58* arg0, s16 arg1);
void func_84B09268(unk_D_84B25A58* arg0, s16 arg1);
void func_84B09354(unk_D_84B25A58* arg0, s16 arg1);
void func_84B09444(unk_D_84B25A58* arg0, s16 arg1);
void func_84B09534(unk_D_84B25A58* arg0, s16 arg1);
void func_84B0962C(unk_D_84B25A58* arg0, s16 arg1);
void func_84B09720(unk_D_84B25A58* arg0, s16 arg1);
void func_84B099D8(unk_D_84B25A58* arg0, s16 arg1);
void func_84B09F60(unk_D_84B25A58* arg0);
void func_84B0A18C(unk_D_84B25A58* arg0);
void func_84B0A1F4(unk_D_84B25A58* arg0);
void func_84B0A244(unk_D_84B25A58* arg0);
void func_84B0A36C(unk_D_84B25A58* arg0);
void func_84B0A544(unk_D_84B25A58* arg0, BinArchive* arg1);
s32 func_84B0A634(unk_D_84B25A58* arg0, unk_D_86002F58_004_000* arg1);
void func_84B0A738(unk_D_84B25A58* arg0);
void func_84B0A82C(unk_D_84B25A58* arg0);
void func_84B0A9D0(unk_D_84B25A58* arg0);

s32 func_84B0AC60(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B0AD48(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B0AE30(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B0AF48(s32 arg0, unk_func_80011B94* arg1);
void func_84B0B054(void);
void func_84B0B05C(unk_D_84B25A90* arg0);
void func_84B0B228(unk_D_84B25A90* arg0);
void func_84B0B6EC(unk_D_84B25A90* arg0, unk_D_86002F58_004_000* arg1, s16 arg2);
void func_84B0B7F4(unk_D_84B25A90* arg0);
void func_84B0B984(unk_D_84B25A90* arg0);
void func_84B0BBEC(unk_D_84B25A90* arg0);
void func_84B0BC6C(unk_D_84B25A90* arg0, unk_D_86002F58_004_000* arg1);
void func_84B0BDCC(unk_D_84B25A90* arg0);
void func_84B0BE28(unk_D_84B25A90* arg0);

s32 func_84B0BF10(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B0BFE4(s32 arg0, unk_func_80011B94* arg1);
s32 func_84B0C094(s32 arg0, unk_func_80011B94* arg1);
void func_84B0C174(unk_D_84B25AC0_000* arg0, unk_D_86002F34* arg1, s16 arg2, s16 arg3, s16 arg4);
void func_84B0C278(unk_D_84B25AC0_000* arg0);
s32 func_84B0C3A4(s32 arg0, unk_func_80011B94* arg1);
void func_84B0C45C(unk_D_84B25AC0_0A0* arg0, unk_D_86002F34* arg1, s16 arg2, s16 arg3, s16 arg4);
void func_84B0C534(unk_D_84B25AC0_0A0* arg0, unk_D_84B25AC0_0A0* arg1);
void func_84B0C5E4(unk_D_84B25AC0_0A0* arg0, unk_D_84B25AC0_0A0* arg1, s16 arg2);
void func_84B0C6B4(unk_D_84B25AC0_0A0* arg0, unk_D_86002F34* arg1, Vec3f* arg2);
void func_84B0C7D0(unk_D_84B25AC0_0A0* arg0);
void func_84B0CA34(unk_D_84B25AC0_0A0* arg0);
void func_84B0CACC(unk_D_84B25AC0_0A0* arg0);
void func_84B0CBCC(unk_D_84B25AC0_0A0* arg0);
void func_84B0CC7C(unk_D_84B25AC0_0A0* arg0);
void func_84B0CCFC(unk_D_84B25AC0* arg0);
void func_84B0CDEC(unk_D_84B25AC0* arg0);
void func_84B0D194(unk_D_84B25AC0* arg0);
void func_84B0D31C(unk_D_84B25AC0* arg0);
void func_84B0D3E4(unk_D_84B25AC0* arg0);
void func_84B0D450(unk_D_84B25AC0* arg0);
void func_84B0D4B4(unk_D_84B25AC0* arg0);
void func_84B0D54C(unk_D_84B25AC0* arg0, unk_D_86002F58_004_000* arg1, unk_D_86002F58_004_000* arg2);
void func_84B0D718(unk_D_84B25AC0* arg0);
void func_84B0D7A8(unk_D_84B25AC0* arg0, s8 arg1, s8 arg2);
void func_84B0D870(unk_D_84B26640_010* arg0);
void func_84B0D878(unk_D_84B26640_010* arg0);
void func_84B0D8F0(unk_D_84B26640_010* arg0);
void func_84B0D970(unk_D_84B26640_010* arg0);
void func_84B0D9D8(unk_D_84B26640_010* arg0, unk_D_86002F58_004_000* arg1);
void func_84B0DA90(unk_D_84B26640_010* arg0);
void func_84B0DAA4(unk_D_84B26640_010* arg0, u8 arg1);
void func_84B0DB30(unk_D_84B2665C* arg0, s16 arg1, s16 arg2);
void func_84B0DD5C(unk_D_84B2665C* arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s8* arg5);
void func_84B0DE04(unk_D_84B2665C* arg0, unk_D_84B17550* arg1);
void func_84B0DF70(unk_D_84B2665C* arg0, unk_D_84B17550* arg1);
void func_84B0E198(unk_D_84B2665C* arg0, unk_D_84B17550* arg1);
void func_84B0E2D8(unk_D_84B2665C* arg0, unk_D_84B17550* arg1);
void func_84B0E424(unk_D_84B2665C* arg0, unk_D_84B17550* arg1);
void func_84B0E50C(unk_D_84B2665C* arg0, unk_D_84B17550* arg1);
void func_84B0E718(unk_D_84B2665C* arg0, unk_D_84B17550* arg1);
void func_84B0E948(s16 arg0, s16 arg1, unk_D_800AE540_1194* arg2);
void func_84B0EC18(unk_D_800AE540_1194* arg0);
void func_84B0ECE8(unk_D_84B2665C* arg0, unk_D_84B17550* arg1);
void func_84B0EF14(unk_D_84B2665C* arg0, unk_D_84B17550* arg1);
void func_84B0F464(unk_D_84B2665C* arg0);
void func_84B0F6C4(unk_D_84B2665C* arg0);
void func_84B0F888(unk_D_84B2665C* arg0);
void func_84B0F8BC(unk_D_84B2665C* arg0);
void func_84B0F8E8(unk_D_84B2665C* arg0);
void func_84B0F950(unk_D_84B2665C* arg0, s16 arg1);
void func_84B0FACC(unk_D_84B2665C* arg0);
s32 func_84B0FADC(unk_D_84B2665C* arg0);


#endif // _FRAGMENT63_H_
