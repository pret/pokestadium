#ifndef _FRAGMENT39_H_
#define _FRAGMENT39_H_

#include "global.h"
#include "6BC0.h"

typedef struct unk_D_82508B00 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk_D_82508B00; // size = 0xC

typedef struct unk_D_8250A288 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
} unk_D_8250A288; // size >= 0xA

typedef struct unk_D_82508B30_03C {
    /* 0x00 */ char unk00[0x1];
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0x12];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk18[0x6];
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ Vec3f unk_24;
    /* 0x30 */ Vec3f unk_30;
} unk_D_82508B30_03C; // size >= 0x3C

typedef struct unk_D_8250A228 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x08 */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E[4];
    /* 0x16 */ char unk16[0x16];
    /* 0x2C */ struct unk_D_8250A228* unk_2C;
    /* 0x30 */ struct unk_D_8250A228* unk_30;
    /* 0x34 */ struct unk_D_8250A228* unk_34;
    /* 0x38 */ unk_D_80068BB0* unk_38;
    /* 0x3C */ unk_D_82508B30_03C unk_3C;
} unk_D_8250A228; // size >= 0x78

typedef struct unk_D_82508B30 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ u16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x004 */ u16 unk_006;
    /* 0x008 */ s16 unk_008;
    /* 0x00A */ s16 unk_00A;
    /* 0x00C */ s16 unk_00C;
    /* 0x00E */ s16 unk_00E[4];
    /* 0x018 */ f32 unk_018;
    /* 0x01C */ f32 unk_01C;
    /* 0x020 */ Vec3f unk_020;
    /* 0x02C */ unk_D_8250A228* unk_02C;
    /* 0x030 */ unk_D_8250A228* unk_030;
    /* 0x034 */ s32 unk_034;
    /* 0x034 */ s32 unk_038;
    /* 0x03C */ unk_D_82508B30_03C unk_03C;
    /* 0x078 */ char unk078[0x12C];
} unk_D_82508B30; // size = 0x1A4

typedef struct unk_D_8250A308 {
    /* 0x000 */ unk_D_86002F58_004_000 unk_000;
    /* 0x168 */ s16 unk_168;
    /* 0x16A */ s16 unk_16A;
    /* 0x16C */ s16 unk_16C;
    /* 0x16E */ s16 unk_16E;
    /* 0x170 */ s16 unk_170;
} unk_D_8250A308; // size = 0x174

typedef struct unk_D_8250A480 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0A */ s16 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char** unk_14;
} unk_D_8250A480; // size = 0x18

typedef struct unk_D_8250A498 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ char** unk_14;
} unk_D_8250A498; // size = 0x18

extern unk_D_800AC870* D_8250A304;

s32 func_82500020(s32 arg0, GraphNode* arg1);
s32 func_825001B4(s32 arg0, GraphNode* arg1);
s32 func_82500388(s32 arg0, GraphNode* arg1);
s32 func_8250042C(s32 arg0, GraphNode* arg1);
void func_82500804(void);
void func_8250088C(unk_D_86002F58_004_000* a0);
s32 func_82500BD8(s32 arg0, GraphNode* arg1);
void func_82500C98(void);
void func_82500D14(void);
void func_82500EE8(void);
s32 func_82500F20(void);
s32 func_82500F94(s32 arg0);
s32 func_82500FD0(s16 arg0, s32 arg1);
void func_82501034(void);
void func_82501064(unk_D_82508B30* arg0);
void func_825010A8(unk_D_82508B30* arg0);
void func_825014B0(unk_D_82508B30* arg0);
unk_D_8250A228* func_825017F0(void);
unk_D_8250A228* func_8250182C(s16 arg0, s16 arg1, GraphNode* arg2);
void func_82501AE4(unk_D_8250A228* arg0, unk_D_8250A228* arg1);
void func_82501B04(unk_D_8250A228* arg0, unk_D_8250A228* arg1);
void func_82501B18(unk_D_8250A228* arg0, s16 arg1);
void func_82501C88(unk_D_8250A228* arg0, s16 arg1, s32 arg2);
s32 func_82501CBC(unk_D_8250A228* arg0, s16 arg1);
void func_82501D08(unk_D_82508B30* arg0);
s32 func_82501D70(unk_D_8250A228* arg0, s16 arg1);
s32 func_82501DC8(unk_D_82508B30* arg0);
void func_82501ED0(void);
void func_825023D4(void);
void func_82502400(void);
void func_8250244C(s16 arg0, s16 arg1);
void func_825024C4(s16 arg0, s16 arg1);
void func_8250281C(void);
void func_82502BB0(void);
void func_82502C78(void);
void func_82502F44(void);
void func_82502FAC(void);
void func_82503020(void);
void func_825031FC(void);
void func_825032BC(void);
void func_82503574(void);
void func_825039AC(void);
s32 func_82503C50(s16* arg0, s16 arg1);
s32 func_82503F00(s16* arg0, s16 arg1);
void func_8250416C(void);
void func_825042A4(void);
void func_82504370(s16 arg0, s16 arg1);
void func_825045C0(void);
s32 func_825046AC(s32 arg0, s32 arg1);

void func_82504820(char** arg0);
s32 func_82504838(void);
void func_82504844(s16 arg0);
void func_82504930(unk_D_8250A480* arg0);
void func_82504A08(unk_D_8250A480* arg0);
void func_82504A68(unk_D_8250A480* arg0);
void func_82504B38(void);
void func_82504BB4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_825053B4(s16 arg0, s16 arg1, s8* arg2, f32 arg3, s16 arg4);
void func_825054F4(void);
void func_82505720(char** arg0);
void func_825057A0(void);
void func_825057A8(s16 arg0);
void func_82505874(s16 arg0, s16 arg1);
void func_82505998(unk_D_8250A498* arg0);
void func_82505A70(unk_D_8250A498* arg0);
void func_82505AB8(unk_D_8250A498* arg0);
void func_82505B94(void);
void func_82505C10(void);

void func_82505FA0(void);
void func_82505FC8(s16);
void func_82505FE0(s16);
s16 func_825060E0(void);

#endif // _FRAGMENT39_H_

