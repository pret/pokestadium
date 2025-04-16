#ifndef _FRAGMENT47_H_
#define _FRAGMENT47_H_

#include "global.h"
#include "src/30640.h"
#include "src/geo_layout.h"
#include "src/fragments/43/fragment43.h"

typedef struct unk_D_8380565C {
    /* 0x000 */ u32 unk_000;
    /* 0x004 */ unk_func_80026268_arg0 unk_004[3];
    /* 0x100 */ char unk100[0x6E4];
    /* 0x7E4 */ unk_func_80026268_arg0 unk_7E4;
} unk_D_8380565C; // size >= 0x838

typedef struct unk_D_838067F0_0168_0000 {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001;
    /* 0x002 */ u8 unk_002;
    /* 0x003 */ u8 unk_003;
    /* 0x004 */ unk_func_80026268_arg0 unk_004[3];
    /* 0x100 */ char unk100[0xBD8];
} unk_D_838067F0_0168_0000; // size = 0xCD8

typedef struct unk_D_838067F0_0168 {
    /* 0x0000 */ unk_D_838067F0_0168_0000 unk_0000[3];
    /* 0x2688 */ struct unk_D_838067F0_0168* unk_2688;
    /* 0x268C */ struct unk_D_838067F0_0168* unk_268C;
    /* 0x2690 */ s16 unk_2690;
    /* 0x2692 */ s16 unk_2692;
    /* 0x2694 */ char unk2694[0x4];
} unk_D_838067F0_0168; // size = 0x2698

typedef struct unk_D_838067F0_003C {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u8 unk_02[1];
    /* 0x03 */ char unk03[0x13];
} unk_D_838067F0_003C; // size = 0x16

typedef struct unk_D_838067F0 {
    /* 0x0000 */ s32 unk_0000;
    /* 0x0004 */ s32 unk_0004;
    /* 0x0008 */ s32 unk_0008;
    /* 0x000C */ s32 unk_000C;
    /* 0x0010 */ s32 unk_0010;
    /* 0x0014 */ s32 unk_0014;
    /* 0x0018 */ s32 unk_0018;
    /* 0x001C */ s32 unk_001C;
    /* 0x0020 */ s32 unk_0020;
    /* 0x0024 */ s32 unk_0024;
    /* 0x0028 */ s32 unk_0028;
    /* 0x002C */ s32 unk_002C;
    /* 0x0030 */ s32 unk_0030;
    /* 0x0034 */ s32 unk_0034;
    /* 0x0038 */ s32 unk_0038;
    /* 0x003C */ unk_D_838067F0_003C unk_003C[13];
    /* 0x015C */ unk_D_8380565C* unk_015C;
    /* 0x0160 */ unk_D_838067F0_0168* unk_0160;
    /* 0x0164 */ char unk0164[0x4];
    /* 0x0168 */ unk_D_838067F0_0168 unk_0168[12];
} unk_D_838067F0; // size = 0x1D088

void func_83800020(s32 arg0);
void func_8380008C(s32 arg0);
void func_83800098(s32 arg0, s32 arg1);
void func_83800120(void);
void func_83800218(void);
void func_83800294(s32 arg0);
void func_83800320(void);
s32 func_838003B4(void);
void func_83800610(void);
void func_83800640(void);
s32 func_83800698(void);
s32 func_83800730(s32 arg0, s32 arg1);

s32 func_83800900(s32 arg0, GraphNode* arg1);
void func_83800AA0(s32 arg0, f32 arg1);
void func_83800BA8(s32 arg0, f32 arg1);
void func_83800CB0(void);
void func_83800D8C(void);
void func_83800EFC(void);
void func_8380101C(void);
s32 func_83801190(s32 arg0);
void func_83801248(void);
void func_83801398(void);
void func_8380142C(void);
void func_838014B8(void);
void func_83801554(void);
void func_838015F4(void);
void func_83801744(void);
void func_83801988(void);
void func_83801AE0(void);
void func_83801C94(void);
void func_83801D64(void);
void func_83801E00(void);
void func_83801E84(s32 arg0, s16 arg1, s32 arg2);
void func_83801F84(s32 arg0);
void func_8380217C(void);
void func_838022C8(s32 arg0);
s32 func_8380248C(void);

void func_838024C0(unk_D_83407B18_008* arg0);
s32 func_838024EC(void);
void func_8380252C(s32 arg0, s32 arg1, unk_D_8380565C* arg2);
s32 func_83802548(unk_D_838067F0* arg0, s32 arg1);
void func_83802660(unk_D_838067F0* arg0, unk_func_80026268_arg0* arg1);
s32 func_83802700(unk_D_838067F0* arg0, unk_D_838067F0_0168* arg1, s32 arg2, unk_D_8380565C* arg3);
s32 func_838029D4(s32 arg0, unk_D_83407B18_008* arg1);
void func_83802C0C(unk_D_838067F0* arg0);
unk_D_838067F0_0168* func_83802C74(unk_D_838067F0_0168* arg0, s32 arg1);
void func_83802C98(unk_D_838067F0* arg0);
void func_83802D64(unk_D_838067F0* arg0);
void func_83802D98(unk_D_838067F0* arg0);
void func_83802EE8(unk_D_838067F0* arg0);
void func_83803038(unk_D_838067F0* arg0);
void func_838030A8(unk_D_838067F0* arg0);
void func_8380311C(unk_D_838067F0* arg0);
void func_838031F0(unk_D_838067F0* arg0);
void func_838032C8(unk_D_838067F0* arg0);
void func_838033DC(unk_D_838067F0* arg0);
void func_83803438(unk_D_838067F0* arg0);
void func_83803488(void);
void func_8380355C(s16 arg0, s16 arg1, s16 arg2);
void func_8380369C(s16 arg0, s16 arg1, u8* arg2, s16 arg3);
void func_83803748(unk_D_838067F0* arg0);
void func_83803A80(s32 arg0, s32 arg1, unk_D_838067F0* arg2);
s32 func_83803E94(unk_D_838067F0* arg0);
s32 func_83803F04(unk_D_838067F0_0168* arg0);
void func_83803F34(s32 arg0, s32 arg1, unk_D_838067F0_0168* arg2);
void func_8380419C(s32 arg0, s32 arg1, unk_D_838067F0_0168* arg2);
void func_838043F8(s32 arg0);

#endif // _FRAGMENT47_H_
