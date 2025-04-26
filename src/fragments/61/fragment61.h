#ifndef _FRAGMENT61_H_
#define _FRAGMENT61_H_

#include "global.h"
#include "src/11BA0.h"
#include "src/1AB70.h"
#include "src/fragments/47/fragment47.h"

struct unk_D_842168A0;
struct unk_D_84229EB0;

typedef struct unk_D_8423D3A8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ unk_D_800A7440 unk_0E;
    /* 0x16 */ unk_D_800A7440 unk_16;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ unk_D_86002F58_004_000_010* unk_24;
    /* 0x28 */ unk_func_8001B1FC* unk_28;
    /* 0x2C */ unk_D_838067F0_0168_0000* unk_2C;
} unk_D_8423D3A8; // size >= 0x30

typedef struct unk_D_842168A0_13608 {
    /* 0x00 */ char unk04[0x4];
} unk_D_842168A0_13608; // size >= 0x4

typedef struct unk_D_84229EB0_00024 {
    /* 0x0000 */ unk_D_838067F0_0168_0000 unk_0000[6];
    /* 0x4D10 */ u16 unk_4D10;
    /* 0x4D12 */ char unk_4D12[2];
    /* 0x4D14 */ char unk4D14[0xA];
    /* 0x4D1E */ s16 unk_4D1E;
    /* 0x4D20 */ s16 unk_4D20;
    /* 0x4D24 */ struct unk_D_84229EB0_00024* unk_4D24;
    /* 0x4D28 */ struct unk_D_84229EB0_00024* unk_4D28;
    /* 0x4D2C */ char unk4D2C[0x4];
} unk_D_84229EB0_00024; // size = 0x4D30

typedef struct unk_D_84211B50 {
    /* 0x0000 */ u8 unk_0000;
    /* 0x0001 */ u8 unk_0001;
    /* 0x0002 */ u8 unk_0002;
    /* 0x0003 */ u8 unk_0003;
    /* 0x0004 */ u8 unk_0004;
    /* 0x0006 */ s16 unk_0006;
    /* 0x0008 */ s16 unk_0008;
    /* 0x000A */ s16 unk_000A;
    /* 0x000C */ s16 unk_000C;
    /* 0x000E */ s16 unk_000E;
    /* 0x0010 */ s16 unk_0010;
    /* 0x0012 */ s16 unk_0012;
    /* 0x0014 */ s16 unk_0014;
    /* 0x0016 */ s16 unk_0016;
    /* 0x0018 */ s16 unk_0018;
    /* 0x001A */ s16 unk_001A;
    /* 0x001C */ u16 unk_001C;
    /* 0x001E */ char unk_001E[2];
    /* 0x0020 */ char unk0020[0x10];
    /* 0x0030 */ unk_D_838067F0_0168_0000 unk_0030[6];
    /* 0x4D40 */ struct unk_D_842168A0* unk_4D40;
    /* 0x4D44 */ unk_D_8423D3A8* unk_4D44;
    /* 0x4D48 */ struct unk_D_84229EB0* unk_4D48;
} unk_D_84211B50; // size = 0x4D4C

typedef struct unk_D_842168A0_0013C {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ unk_func_80026268_arg0 unk_04[1];
} unk_D_842168A0_0013C; // size >= 0x58

typedef struct unk_D_842168A0 {
    /* 0x00000 */ u8 unk_00000;
    /* 0x00001 */ u8 unk_00001;
    /* 0x00002 */ u8 unk_00002;
    /* 0x00003 */ u8 unk_00003;
    /* 0x00004 */ u8 unk_00004;
    /* 0x00005 */ u8 unk_00005;
    /* 0x00006 */ u8 unk_00006;
    /* 0x00007 */ u8 unk_00007;
    /* 0x00008 */ u8 unk_00008;
    /* 0x00009 */ u8 unk_00009;
    /* 0x0000A */ s16 unk_0000A;
    /* 0x0000C */ s16 unk_0000C;
    /* 0x0000E */ s16 unk_0000E;
    /* 0x00010 */ s16 unk_00010;
    /* 0x00012 */ s16 unk_00012;
    /* 0x00014 */ s16 unk_00014;
    /* 0x00016 */ s16 unk_00016;
    /* 0x00018 */ s16 unk_00018;
    /* 0x0001A */ s16 unk_0001A;
    /* 0x0001C */ unk_D_838067F0_003C unk_0001C[13];
    /* 0x0013A */ char unk0013A[0x2];
    /* 0x0013C */ unk_D_842168A0_0013C* unk_0013C;
    /* 0x00140 */ unk_D_838067F0_0168* unk_00140;
    /* 0x00144 */ char unk00144[0x4];
    /* 0x00148 */ unk_D_838067F0_0168 unk_00148[8];
    /* 0x13608 */ unk_D_84211B50* unk_13608;
    /* 0x1360C */ unk_D_8423D3A8* unk_1360C;
} unk_D_842168A0; // size = 0x13610

typedef struct unk_D_84229EB0 {
    /* 0x00000 */ u8 unk_00000;
    /* 0x00001 */ u8 unk_00001;
    /* 0x00002 */ u8 unk_00002;
    /* 0x00003 */ u8 unk_00003;
    /* 0x00004 */ u8 unk_00004;
    /* 0x00005 */ s8 unk_00005;
    /* 0x00006 */ s16 unk_00006;
    /* 0x00008 */ s16 unk_00008;
    /* 0x0000A */ s16 unk_0000A;
    /* 0x0000C */ u8 unk_0000C;
    /* 0x0000D */ u8 unk_0000D;
    /* 0x0000E */ s16 unk_0000E;
    /* 0x00010 */ s16 unk_00010;
    /* 0x00012 */ s16 unk_00012;
    /* 0x00014 */ s16 unk_00014;
    /* 0x00016 */ s16 unk_00016;
    /* 0x00018 */ s16 unk_00018;
    /* 0x0001A */ s16 unk_0001A;
    /* 0x0001C */ s16 unk_0001C;
    /* 0x0001E */ u8 unk_0001E;
    /* 0x0001F */ u8 unk_0001F;
    /* 0x00020 */ u8 unk_00020;
    /* 0x00024 */ unk_D_84229EB0_00024* unk_00024;
    /* 0x00028 */ unk_D_84229EB0_00024 unk_00028[3];
    /* 0x0E7B8 */ char unk0E7B8[0x4D30];
    /* 0x134E8 */ unk_D_84211B50* unk_134E8;
    /* 0x134EC */ unk_D_842168A0* unk_134EC;
    /* 0x134F0 */ unk_D_8423D3A8* unk_134F0;
    /* 0x134F4 */ char unk134F4[0x4];
} unk_D_84229EB0; // size = 0x134F8

typedef struct unk_D_8423D3D8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ unk_D_800AE540_0004* unk_04;
} unk_D_8423D3D8; // size = 0x8

typedef struct unk_D_84211704 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s8 unk_0A;
    /* 0x0B */ s8 unk_0B;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u16 unk_0E;
} unk_D_84211704; // size = 0x10

s32 func_84200020(s32 arg0);
char* func_84200088(s32 arg0);
char* func_842000C0(s32 arg0);
char* func_842000F8(s32 arg0);
char* func_84200130(s32 arg0);
char* func_84200160(s32 arg0);
char* func_84200190(char* arg0, s32 arg1, s32 arg2);
void func_842001B8(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_84200420(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_84200738(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_8420092C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_8420112C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_8420192C(s16 arg0, s16 arg1);
void func_84201A00(s16 arg0, s16 arg1);
void func_84201AD4(s16 arg0, s16 arg1, s16 arg2);
void func_84201BC4(s16 arg0, s16 arg1, s16 arg2, Color_RGBA8* arg3, Color_RGBA8* arg4);
void func_84201D6C(void);
void func_84201E70(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_84201F04(s16 arg0, s16 arg1, s16 arg2);
void func_84202208(void);
s32 func_84202284(void);
s16 func_842023E4(void);
void func_842024DC(s16 arg0, s16 arg1);
void func_84202718(UNUSED s16 arg0, s16 arg1, s16 arg2);
s16 func_84202844(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_84202974(UNUSED s16 arg0, UNUSED s32 arg1);
void func_84202A64(s16 arg0, s32 arg1, s16 arg2);
void func_84202AF4(s16 arg0, s16 arg1, s16 arg2);
void func_84202C20(void);
void func_84202D18(unk_D_8423D3D8* arg0, s16 arg1);
s32 func_84202EB0(unk_D_8423D3D8* arg0, s16 arg1);
void func_8420305C(s32 arg0);
void func_84203100(void);
void func_8420318C(s16 arg0, s16 arg1);
s32 func_84203210(void);
s32 func_842034E4(void);
void func_842037AC(void);
void func_842039B4(void);
void func_84203AB8(void);
s32 func_84203BBC(void);
void func_84203C90(void);
void func_84203D74(void);
s32 func_84203E6C(s32 arg0, UNUSED s32 arg1);

s32 func_84204070(s32 arg0, unk_func_80011B94* arg1);
void func_84204210(void);
void func_84204294(s32 arg0);
void func_8420448C(void);
void func_84204660(s32 arg0, s16 arg1, s16 arg2);
void func_84204760(s32 arg0);
void func_84204934(s16 arg0, f32 arg1);
void func_84204A3C(s16 arg0, f32 arg1);
void func_84204B50(void);
void func_84204BF8(void);
void func_84204C9C(void);
void func_84204D5C(void);
void func_84204E0C(void);
void func_84204F78(void);
void func_842050CC(void);
void func_84205200(void);
void func_8420545C(void);
void func_8420563C(void);
s32 func_8420570C(void);
void func_842057AC(void);
void func_8420594C(void);
void func_84205B3C(void);
s32 func_84205C18(s16 arg0);
s32 func_84205D48(s16 arg0, s32 arg1);
s16 func_84205E54(void);

void func_84205E80(s16 arg0, s16 arg1, s32 arg2);
void func_84205F18(unk_D_84211B50* arg0, s16 arg1, s16 arg2);
void func_84206144(unk_D_84211B50* arg0);
void func_842062D4(unk_D_84211B50* arg0, s32 arg1);
void func_842068DC(unk_D_84211B50* arg0);
s32 func_84206990(unk_D_84211B50* arg0);
s32 func_84206A68(unk_D_84211B50* arg0);
void func_84206BC4(unk_D_84211B50* arg0);
void func_84206BDC(unk_D_84211B50* arg0);
void func_84206BF0(unk_D_84211B50* a0);
void func_84206D10(unk_D_84211B50* arg0);
void func_84206DE8(unk_D_84211B50* arg0);
void func_84206E88(unk_D_84211B50* arg0);
void func_84206EE0(unk_D_84211B50* arg0);
void func_84206F1C(unk_D_84211B50* arg0);
void func_84206F64(unk_D_84211B50* arg0);
void func_84206FB0(unk_D_84211B50* arg0);
void func_84206FF8(unk_D_84211B50* arg0);
void func_84207040(unk_D_84211B50* arg0);
void func_84207190(unk_D_84211B50* arg0);
void func_8420720C(unk_D_84211B50* arg0);
void func_842073A4(unk_D_84211B50* arg0);
void func_84207530(unk_D_84211B50* arg0);
void func_84207634(unk_D_84211B50* arg0);
void func_842076A0(unk_D_84211B50* arg0);
void func_842076F8(unk_D_84211B50* arg0);
s32 func_8420776C(unk_D_84211B50* arg0);
s32 func_842078C0(unk_D_84211B50* arg0, unk_D_842168A0* arg1, unk_D_8423D3A8* arg2, unk_D_84229EB0* arg3, s16 arg4, u16 arg5,
                  char* arg6, s16 arg7, s16 arg8, s16 arg9);
s32 func_842079B4(unk_D_84211B50* arg0, s16 arg1);
s32 func_842079F0(unk_D_84211B50*);
s32 func_84207A1C(unk_D_84211B50*);
s32 func_84207AAC(unk_D_84211B50*);
s32 func_84207BD4(unk_D_84211B50*, unk_D_838067F0_0168_0000*);
s32 func_84207D5C(unk_D_84211B50*);
s32 func_84207E3C(unk_D_84211B50*, unk_D_838067F0_0168_0000*);
s32 func_8420804C(unk_D_84211B50*, unk_D_838067F0_0168_0000*);
s32 func_842081A8(unk_D_84211B50* arg0);
void func_842081B4(unk_D_84211B50* arg0, unk_func_80026268_arg0* arg1, s16 arg2);

void func_84209340(unk_D_842168A0*, s32);
s32 func_8420AF1C(unk_D_842168A0*, unk_D_84211B50*, unk_D_8423D3A8*, s16, s16, s16, s16, s16, unk_D_842168A0_0013C*);
s32 func_8420B0C8(unk_D_842168A0*);
s32 func_8420B1D0(unk_D_842168A0*, s16);
s32 func_8420B20C(unk_D_842168A0*);
s32 func_8420B238(unk_D_842168A0*);
void func_8420B264(unk_D_842168A0*);
s32 func_8420B334(unk_D_842168A0*);
s32 func_8420B37C(unk_D_842168A0*);

void func_8420B390(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s8* arg4);
void func_8420B40C(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_8420B5A4(s16 arg0, s16 arg1, s16 arg2);
void func_8420B71C(s16 arg0, s16 arg1, s32 arg2);
s16 func_8420B870(s16 arg0, s16 arg1, char* arg2);
void func_8420B8CC(unk_D_8423D3A8* arg0, s32 arg1);
void func_8420C360(unk_D_8423D3A8* arg0);
void func_8420C368(unk_D_8423D3A8* arg0);
void func_8420C484(unk_D_8423D3A8* arg0);
void func_8420C4DC(unk_D_8423D3A8* arg0);
s32 func_8420C504(unk_D_8423D3A8* arg0);
s32 func_8420C580(unk_D_8423D3A8* arg0);
s32 func_8420C60C(unk_D_8423D3A8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5,
    unk_D_838067F0_0168_0000* arg6, s16 arg7);
s32 func_8420C6D8(unk_D_8423D3A8* arg0, s16 arg1, s16 arg2, unk_D_838067F0_0168_0000* arg3);
s32 func_8420C788(unk_D_8423D3A8* arg0);
void func_8420C7B0(s16 arg0, s16 arg1, s16 arg2, char* arg3);
void func_8420C844(unk_D_84211704* arg0);
void func_8420C930(unk_D_84211704* arg0);
void func_8420CA00(unk_D_84211704* arg0);
void func_8420CAD0(unk_D_84211704* arg0);
void func_8420CBA0(unk_D_84211704* arg0);
void func_8420CC54(unk_D_84211704* arg0);
void func_8420CCAC(unk_D_84211704* arg0);
void func_8420CE24(unk_D_84211704* arg0);
void func_8420CFC4(unk_D_84211704* arg0);
void func_8420D144(unk_D_84211704* arg0);
void func_8420D2BC(unk_D_84211704* arg0);
void func_8420D370(unk_D_84211704* arg0, s16 arg1);
void func_8420D464(unk_D_84211704* arg0, s16 arg1);
void func_8420D4F8(s32 arg0);
void func_8420D75C(void);
void func_8420D938(void);
void func_8420D978(void);
s32 func_8420D9B0(void);
s32 func_8420DA28(s16 arg0, Controller* arg1);
s32 func_8420DAF4(s16 arg0);
s16 func_8420DB48(s16 arg0);
s32 func_8420DBA0(unk_D_84229EB0_00024* arg0);
void func_8420DC78(unk_D_84229EB0_00024* arg0);
void func_8420DD14(unk_D_84229EB0* arg0, s16 arg1, s16 arg2, unk_D_84229EB0_00024* arg3);
void func_8420E46C(s16 arg0, s16 arg1);
void func_8420E63C(unk_D_84229EB0* arg0);
void func_8420EA88(unk_D_84229EB0* arg0);
void func_8420EB7C(unk_D_84229EB0* arg0);
void func_8420ED0C(unk_D_84229EB0* arg0);
void func_8420EE54(unk_D_84229EB0* arg0, s32 arg1);
unk_D_84229EB0_00024* func_8420F1BC(unk_D_84229EB0_00024* arg0, s32 arg1);
unk_D_84229EB0_00024* func_8420F1E0(unk_D_84229EB0_00024* arg0, s32 arg1);
s32 func_8420F204(unk_D_84229EB0_00024* arg0, s16 arg1);
void func_8420F37C(unk_D_84229EB0* arg0);
void func_8420F4FC(unk_D_84229EB0* arg0);
void func_8420F524(unk_D_84229EB0* arg0);
void func_8420F53C(unk_D_84229EB0* arg0);
void func_8420F598(unk_D_84229EB0* arg0);
void func_8420F5F0(unk_D_84229EB0* arg0);
void func_8420F654(unk_D_84229EB0* arg0);
void func_8420F754(unk_D_84229EB0* arg0);
void func_8420F86C(unk_D_84229EB0* arg0);
void func_8420F9C8(unk_D_84229EB0* arg0);
void func_8420FA88(unk_D_84229EB0* arg0);
void func_8420FB4C(unk_D_84229EB0* arg0);
void func_8420FC0C(unk_D_84229EB0* arg0);
void func_8420FCCC(unk_D_84229EB0* arg0);
void func_8420FDDC(unk_D_84229EB0* arg0);
void func_8420FE50(unk_D_84229EB0* arg0);
void func_8420FE90(unk_D_84229EB0* arg0);
void func_8420FEC0(unk_D_84229EB0* arg0);
void func_8420FFB0(unk_D_84229EB0* arg0);
void func_8421009C(unk_D_84229EB0* arg0);
void func_8421015C(unk_D_84229EB0* arg0);
void func_84210328(unk_D_84229EB0* arg0);
void func_8421059C(unk_D_84229EB0* arg0);
void func_84210668(unk_D_84229EB0* arg0);
s32 func_842106FC(unk_D_84229EB0* arg0);
s32 func_8421089C(unk_D_84229EB0* arg0, unk_D_84211B50* arg1, unk_D_842168A0* arg2, unk_D_8423D3A8* arg3,
                  s16 arg4, s16 arg5, s16 arg6, s16 arg7);
s32 func_84210A18(unk_D_84229EB0* arg0);
s32 func_84210A48(unk_D_84229EB0* arg0, u16 arg1, char* arg2, unk_D_838067F0_0168_0000* arg3);
s32 func_84210B54(unk_D_84229EB0* arg0);
s32 func_84210B60(unk_D_84229EB0* arg0, unk_D_84229EB0_00024** arg1);
void func_84210C80(unk_D_84229EB0* arg0, s16 arg1);

#endif // _FRAGMENT61_H_
