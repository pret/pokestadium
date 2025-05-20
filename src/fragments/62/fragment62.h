#ifndef _FRAGMENT62_H_
#define _FRAGMENT62_H_

#include "global.h"
#include "src/29BA0.h"
#include "src/6BC0.h"
#include "src/stage_loader.h"

typedef struct unk_D_84390010_654_038_044 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk01[0x5];
} unk_D_84390010_654_038_044; // size = 0x6

typedef struct unk_D_84390010_654_038 {
    /* 0x00 */ char unk00[0xB];
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ char unk0C[0x9];
    /* 0x15 */ u8 unk_15;
    /* 0x16 */ char unk16[0x9];
    /* 0x1F */ u8 unk_1F[4];
    /* 0x23 */ char unk23[0x3];
    /* 0x26 */ u8 unk_26;
    /* 0x27 */ char unk27[0x1D];
    /* 0x44 */ unk_D_84390010_654_038_044 unk_44;
    /* 0x4A */ char unk4A[0x2];
    /* 0x4C */ u8 unk_4C;
    /* 0x4D */ char unk4D[0xD];
    /* 0x5A */ u8 unk_5A;
    /* 0x5B */ char unk5B[0x9];
} unk_D_84390010_654_038; // size = 0x64

typedef struct unk_D_84390010_654_09C {
    /* 0x00 */ char unk00[0x10];
} unk_D_84390010_654_09C; // size = 0x10

typedef struct unk_D_84390010_654_0AC {
    /* 0x00 */ char unk00[0x10];
} unk_D_84390010_654_0AC; // size = 0x10

typedef struct unk_D_84390010_168 {
    /* 0x000 */ unk_D_86002F58_004_000 unk_000;
    /* 0x168 */ char unk168[0x8];
} unk_D_84390010_168; // size = 0x170

typedef struct unk_D_84390010_654 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk0C[0xC];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ char unk1C[0xF];
    /* 0x2B */ u8 unk_2B;
    /* 0x2C */ u8 unk_2C;
    /* 0x2D */ u8 unk_2D;
    /* 0x2E */ u8 unk_2E;
    /* 0x2F */ char unk2F[0x5];
    /* 0x34 */ u16 unk_34;
    /* 0x36 */ u16 unk_36;
    /* 0x38 */ unk_D_84390010_654_038 unk_38;
    /* 0x9C */ unk_D_84390010_654_09C unk_9C;
    /* 0xAC */ unk_D_84390010_654_0AC unk_AC;
    /* 0xBC */ s16 unk_BC;
    /* 0xBE */ char unkBE[0x3];
    /* 0xC1 */ u8 unk_C1[4];
    /* 0xC5 */ char unkC5[0x7];
} unk_D_84390010_654; // size = 0xCC

typedef struct unk_D_84390010_724_01C {
    /* 0x00 */ char unk00[0x5];
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk06[0x2];
} unk_D_84390010_724_01C; // size >= 0x8

typedef struct unk_D_84390010_724 {
    /* 0x00 */ char unk00[0x1C];
    /* 0x1C */ unk_D_84390010_724_01C unk_1C;
    /* 0x24 */ char unk24[0x30];
} unk_D_84390010_724; // size = 0x54

typedef struct unk_D_84390010_728_0168 {
    /* 0x00 */ unk_D_86002F58_004_000_000 unk_00;
    /* 0x18 */ char unk18[0x4];
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ char unk22[0xA];
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ char unk30[0x4];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
} unk_D_84390010_728_0168; // size >= 0x3C

typedef struct unk_D_84390010_728 {
    /* 0x000 */ unk_D_86002F58_004_000 unk_000;
    /* 0x168 */ unk_D_84390010_728_0168* unk_168;
    /* 0x16C */ s32 unk_16C;
    /* 0x170 */ s32 unk_170;
    /* 0x174 */ char unk174[0x4];
    /* 0x178 */ s32 unk_178;
    /* 0x17C */ s32 unk_17C;
    /* 0x180 */ s32 unk_180;
    /* 0x184 */ s16 unk_184;
    /* 0x186 */ s16 unk_186;
    /* 0x188 */ f32 unk_188;
    /* 0x18C */ s32 unk_18C;
    /* 0x190 */ f32 unk_190;
    /* 0x194 */ f32 unk_194;
    /* 0x198 */ char unk198[0x4];
} unk_D_84390010_728; // size = 0x19C

typedef struct unk_D_84390010_8C4 {
    /* 0x00 */ char unk00[0x88];
} unk_D_84390010_8C4; // size = 0x88

typedef struct unk_D_84390010_94C {
    /* 0x00 */ u8 unk_00[10];
    /* 0x0A */ u8 unk_0A[4];
    /* 0x0E */ char unk0E[0x12];
} unk_D_84390010_94C; // size = 0x20

typedef struct unk_D_84390048 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ u8 unk_18;
    /* 0x18 */ u8 unk_19;
    /* 0x18 */ u8 unk_1A;
    /* 0x18 */ u8 unk_1B;
    /* 0x1C */ char unk1C[4];
} unk_D_84390048; // size = 0x20

typedef struct unk_D_84390010 {
    /* 0x000 */ unk_D_86002F58_004_000 unk_000;
    /* 0x168 */ unk_D_84390010_168 unk_168[2];
    /* 0x448 */ Vec3f unk_448;
    /* 0x454 */ Vec3f unk_454;
    /* 0x460 */ char unk460[0xC];
    /* 0x46C */ unk_D_84390048 unk_46C;
    /* 0x48C */ char unk48C[0x24];
    /* 0x4B0 */ s32 unk_4B0;
    /* 0x4B4 */ s32 unk_4B4;
    /* 0x4B8 */ char unk4B8[0x8];
    /* 0x4C0 */ s32 unk_4C0;
    /* 0x4C4 */ s32 unk_4C4;
    /* 0x4C8 */ s32 unk_4C8;
    /* 0x4CC */ char unk4CC[0x20];
    /* 0x4EC */ unk_D_86002F58_004_000 unk_4EC;
    /* 0x654 */ unk_D_84390010_654 unk_654;
    /* 0x720 */ unk_D_800AE540_1194* unk_720;
    /* 0x724 */ unk_D_84390010_724* unk_724;
    /* 0x728 */ unk_D_84390010_728 unk_728;
    /* 0x8C4 */ unk_D_84390010_8C4 unk_8C4;
    /* 0x94C */ unk_D_84390010_94C unk_94C;
    /* 0x96C */ unk_D_84390010_94C unk_96C;
    /* 0x98C */ unk_D_84390010_94C unk_98C;
    /* 0x9AC */ unk_D_84390010_94C unk_9AC;
    /* 0x9CC */ unk_D_84390010_94C unk_9CC;
    /* 0x9EC */ unk_D_84390010_94C unk_9EC;
} unk_D_84390010; // size = 0xA0C

typedef struct unk_D_8438E7B0_A50 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ char unk03[0x1];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ char unk0D[0x3];
} unk_D_8438E7B0_A50; // size = 0x10

typedef struct unk_D_8438E7B0 {
    /* 0x000 */ unk_D_8438E7B0_A50 unk_000[165];
    /* 0xA50 */ unk_D_8438E7B0_A50 unk_A50;
    /* 0xA60 */ char unkA60[0x10];
    /* 0xA70 */ unk_D_8438E7B0_A50 unk_A70;
    /* 0xA80 */ unk_D_8438E7B0_A50 unk_A80;
    /* 0xA90 */ char unkA90[0x70];
    /* 0xB00 */ unk_D_8438E7B0_A50 unk_B00;
    /* 0xB10 */ char unkB10[0x10];
    /* 0xB20 */ unk_D_8438E7B0_A50 unk_B20;
    /* 0xB30 */ char unkB30[0xB0];
} unk_D_8438E7B0; // size = 0xBE0

typedef struct unk_D_84390240_000 {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk18[0x4];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ char unk20[0x28];
    /* 0x48 */ s32 unk_48;
} unk_D_84390240_000; // size >= 0x4C

typedef struct unk_D_84390240 {
    /* 0x00 */ unk_D_84390240_000* unk_00;
    /* 0x04 */ char unk04[0x3C];
} unk_D_84390240; // size = 0x40

typedef void (*unk_D_84385384_func)(unk_D_84390010*);

typedef struct unk_D_84385384 {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ unk_D_84385384_func unk_04[7];
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
} unk_D_84385384; // size = 0x2C

typedef struct unk_D_843C4E44 {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001;
    /* 0x3F2 */ char unk02[0x3F2];
} unk_D_843C4E44; // size >= 0x3F4

typedef struct unk_D_843C4DEC {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk04[0x54];
} unk_D_843C4DEC; // size = 0x58

typedef struct unk_D_84390068 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_D_84385384_func unk_04;
} unk_D_84390068; // size = 0x8

typedef struct unk_D_84384588 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0xE];
} unk_D_84384588; // size = 0x10

typedef struct unk_D_84390178 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk04[0x14];
} unk_D_84390178; // size >= 0x18

typedef struct unk_D_8438FF70 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ char unk14[0xC];
} unk_D_8438FF70; // size = 0x20

typedef struct unk_D_84390028 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ char unk0C[0x4];
} unk_D_84390028; // size = 0x10

typedef struct unk_D_84384608 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 unk_04;
} unk_D_84384608; // size = 0x8

typedef struct unk_D_843847BC {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s16 unk_14;
} unk_D_843847BC; // size = 0x18

typedef struct unk_D_843901B0 {
    /* 0x00 */char unk00[0x40];
} unk_D_843901B0; // size >= 0x40

extern u8* D_8438E778;
extern u8* D_8438E77C;
extern u8 D_843C4DA4;
extern unk_D_843C4DEC D_843C4DEC;
//extern unk_D_843C4E44 D_843C4E44;
extern u8 D_843C4E44;
extern u8 D_843C4E45;

extern unk_D_84390010* D_84390010[2];
extern unk_D_84390028 D_84390028[2];

extern unk_D_8438FF70* D_84384578[];
extern unk_D_843847BC D_843847BC[2];
extern unk_D_84390010* D_84390018;
extern unk_D_84390010* D_8439001C;
extern unk_D_84390240 D_84390240;

s32 func_84300020(s32 arg0, GraphNode* arg1);
s32 func_84300058(s32 arg0, unk_D_86002F34_alt18* arg1);
s32 func_843000C0(s32 arg0, unk_D_86002F34_alt18* arg1);
s32 func_8430012C(s32 arg0, unk_D_86002F58_004_000* arg1);
void func_84300184(u8 arg0, u8 arg1, u8 arg2);
void func_843001FC(f32 arg0);
u16 func_84300208(u16 arg0);
void func_84300340(void);
void func_84300750(GraphNode* arg0, unk_D_80068BB0* arg1);
void func_84300810(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_84300938(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, s32 arg5);
void func_84300B34(GraphNode* arg0, unk_D_80068BB0* arg1);
void func_84300D44(void);
void func_84300DC0(void);
void func_84300E78(void);
void func_84300E80(void);
s32 func_84300E88(s32 arg0);
s32 func_84300FBC(s32 arg0);
void func_84301094(void);
s32 func_843010EC(s32 arg0);
void func_8430123C(u8* arg0, s32 arg1);
void func_8430128C(void);
void func_843013E4(unk_D_800AE540_1194* arg0, unk_D_86002F30* arg1);
void func_84301430(unk_func_80007444* arg0);
void func_84301A24(void);
s32 func_84301A2C(s32 arg0, unk_D_800AE540* arg1);

void func_84301B00(void);
void func_84301B48(unk_D_84390010* arg0, s32 arg1);
void func_84301B84(unk_D_84390010* arg0, s32 arg1);
void func_84301BEC(unk_D_84390010* arg0, s32 arg1);
void func_84301C54(unk_D_84390010* arg0, s32 arg1);
void func_84301CBC(unk_D_84390010* arg0);
void func_84301D08(unk_D_84390010* arg0);
void func_84301DDC(unk_D_84390010* arg0);
void func_84301EEC(unk_D_84390010* arg0);
void func_84301EF4(unk_D_84390010* arg0);
void func_84301F2C(unk_D_84390010* arg0);
void func_84301F80(unk_D_84390010* arg0);
s32 func_84301FB0(unk_D_84390010* arg0);
s32 func_84301FC0(unk_D_84390010* arg0);
s32 func_84301FF0(unk_D_84390010* arg0);
s32 func_84302000(unk_D_84390010* arg0);
void func_8430203C(unk_D_84390010* arg0);
void func_843020B0(unk_D_84390010* arg0);
void func_843020F4(unk_D_84390010* arg0);
void func_84302128(unk_D_84390010* arg0);
void func_84302148(unk_D_84390010* arg0);
s32 func_84302194(u16 arg0, u8* arg1, s32 arg2);
void func_843021E8(unk_D_84390010* arg0, u16 arg1, unk_D_84390010_94C* arg2, unk_D_84390010_94C* arg3);
void func_8430245C(unk_D_84390010* arg0);
void func_8430255C(u8 arg0, u32 arg1);
void func_843025BC(s32 arg0, unk_D_84390010_94C* arg1, unk_D_84390010_94C* arg2);
void func_84302658(unk_D_84390010* arg0, s32 arg1);
void func_843029D0(unk_D_84390010* arg0);
void func_84302A78(unk_D_84390010* arg0);
void func_84302C34(unk_D_84390010* arg0);
void func_84302EF0(unk_D_84390010* arg0);
void func_8430305C(unk_D_84390010* arg0);
void func_843031A0(unk_D_84390010* arg0);
void func_84303208(unk_D_84390010* arg0);
void func_8430334C(unk_D_84390010* arg0);
void func_843033E0(unk_D_84390010* arg0);
void func_843034D8(unk_D_84390010* arg0);
void func_84303674(unk_D_84390010* arg0);
void func_843037CC(unk_D_84390010* arg0);
void func_84303A48(unk_D_84390010* arg0);
void func_84303BB8(unk_D_84390010* arg0);
void func_84303CB4(unk_D_84390010* arg0);
s32 func_84303D50(unk_D_84390010* arg0);
s32 func_84303DEC(unk_D_84390010* arg0);
void func_84303E58(unk_D_84390010* arg0);
void func_84303ECC(unk_D_84390010* arg0);
void func_84304114(unk_D_84390010* arg0);
void func_84304210(unk_D_84390010* arg0);
void func_843043FC(unk_D_84390010* arg0);
void func_843045DC(unk_D_84390010* arg0);
void func_843046BC(unk_D_84390010* arg0);
void func_84304758(unk_D_84390010* arg0);
void func_84304800(unk_D_84390010* arg0);
void func_84304834(unk_D_84390010* arg0);
void func_843048C8(unk_D_84390010* arg0);
void func_843049FC(unk_D_84390010* arg0);
void func_84304ACC(unk_D_84390010* arg0);
void func_84304B50(unk_D_84390010* arg0);
void func_84304C20(unk_D_84390010* arg0);
void func_84304C8C(unk_D_84390010* arg0);
void func_84304D84(unk_D_84390010* arg0);
void func_84304F54(unk_D_84390010* arg0);
void func_8430506C(unk_D_84390010* arg0);
void func_843052C0(unk_D_84390010* arg0);
s32 func_84305458(unk_D_84390010* arg0);
void func_843054F0(unk_D_84390010* arg0);
void func_843055E0(unk_D_84390010* arg0);
void func_843056DC(unk_D_84390010* arg0);
void func_843056E4(unk_D_84390010* arg0, unk_D_84385384_func arg1);
void func_84305728(unk_D_84390010* arg0);
void func_84305760(unk_D_84390010* arg0, s32 arg1);
void func_84305808(void);
void func_843058A8(unk_D_84390010* arg0);
void func_843058C4(unk_D_84390010* arg0, s32 arg1);
s32 func_843059C0(unk_D_84390010* arg0, s32 arg1, s32 arg2);
void func_84305A74(unk_D_84390010* arg0, s32 arg1, s32 arg2);
s32 func_84305AFC(unk_D_84390010* arg0);
s32 func_84305B6C(unk_D_84390010* arg0, s32 arg1);
s32 func_84305BD8(unk_D_84390010* arg0, s32 arg1);
s32 func_84305CAC(unk_D_84390010* arg0, s32 arg1);
s32 func_84305E54(unk_D_84390010* arg0, s32 arg1);
s32 func_8430602C(unk_D_84390010* arg0, s32 arg1);
void func_843060EC(unk_D_84390010* arg0);
void func_843061EC(unk_D_84390010* arg0, u16 arg1);
s32 func_84306200(unk_D_84390010* arg0, u16 arg1);
void func_84306218(unk_D_84390010* arg0);
void func_843062F0(void);
void func_84306470(unk_D_84390010* arg0);
void func_84306584(unk_D_84390010* arg0);
void func_843065C4(unk_D_84390010* arg0);
void func_8430663C(unk_D_84390010* arg0);
void func_843066E0(unk_D_84390010* arg0);
void func_84306914(unk_D_84390010* arg0);
void func_84306A68(unk_D_84390010* arg0);
void func_84306AF0(unk_D_800AE540_1194* arg0, s32 arg1);
void func_84306BC4(unk_D_800AE540_1194* arg0);
void func_84306C1C(unk_D_84390010* arg0);
void func_84306C8C(unk_D_84390010* arg0);
void func_84306DA8(unk_D_84390010* arg0);
void func_84306E80(unk_D_84390010* arg0, s32* arg1);
void func_84306FB8(unk_D_84390010* arg0);
void func_84307078(unk_D_800AE540_1194* arg0);
void func_843071B8(unk_D_84390010* arg0, unk_D_84390010* arg1, s32 arg2);
void func_84307220(unk_D_800AE540_1194* arg0);
void func_8430732C(unk_D_84390010* arg0, unk_D_84390010* arg1);
s32 func_84307394(s32 arg0, unk_D_800AE540_1194* arg1);
void func_84307414(unk_D_84390010* arg0);
void func_8430741C(unk_D_84390010* arg0);
void func_84307424(unk_D_84390010* arg0);
void func_8430742C(unk_D_84390010* arg0);
void func_84307434(unk_D_84390010* arg0);
void func_8430743C(unk_D_84390010* arg0);
void func_84307444(unk_D_84390010* arg0);
void func_8430744C(unk_D_84390010* arg0);
void func_84307454(unk_D_84390010* arg0);
void func_8430745C(unk_D_84390010* arg0);
void func_84307464(unk_D_84390010* arg0);
void func_8430746C(unk_D_84390010* arg0);
void func_84307474(unk_D_84390010* arg0, s32 arg1);
void func_84307480(unk_D_84390010* arg0, s32 arg1);
void func_8430748C(unk_D_84390010* arg0);


void func_843074A0(unk_D_84390010* arg0);
void func_843074EC(unk_D_84390010* arg0);
void func_843074F4(unk_D_84390010* arg0);
void func_84307500(void);
void func_8430751C(void);
void func_8430753C(unk_D_84390010_728_0168* arg0);
void func_8430754C(unk_D_84390010* arg0);
void func_843075D0(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_84307630(void);
void func_84307638(unk_D_84390010* arg0);
void func_84307748(unk_D_84390010* arg0);
void func_84307768(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, unk_D_86002F34_00C* arg2, unk_D_84390010* arg3);
void func_843077B0(unk_D_84390010* arg0, s32 arg1);
void func_843078F4(unk_D_84390010* arg0, s32 arg1);
void func_843079C4(unk_D_84390010* arg0);
void func_84307A14(unk_D_84390010* arg0, unk_D_84390010* arg1);
s32 func_84307A50(s32 arg0, unk_D_86002F34_00C* arg1, unk_D_86002F34_00C* arg2);


s32 func_84307AE0(u8, u8*, s32);
s32 func_84307B60(unk_D_84390010*);
f32 func_84307BAC(unk_D_84390010*);
void func_84307C5C(unk_D_84390010*);
s32 func_84307F00(unk_D_84390010*);
u8 func_84307F24(unk_D_84390010*);
u8 func_84307F68(unk_D_84390010*);
s16 func_84307FAC(unk_D_84390010*);
s32 func_84307FE0(unk_D_84390010*);
s16 func_8430808C(unk_D_84390010*);
void func_84308654(unk_D_84390010*, s32, s32);
unk_D_86002F58_004_000_004* func_843085C4(unk_D_84390010*, s32);
s16 func_843085E0(unk_D_84390010*, s32);
void func_84308660(unk_D_84390010*, unk_D_84390010*);
void func_843089DC(unk_D_84390010*, s32);
void func_843089F4(unk_D_84390010*, s32);
void func_843089FC(unk_D_84390010*, Controller*);
void func_8430920C(unk_D_84390010*);
void func_843092B4(unk_D_84390010* arg0);
void func_843096EC(unk_D_84390010*);
void func_8430BC44(s32);
s32 func_8430C1E4(Vec3f*, Vec3f*);
u16 func_8430C414(s32);
void func_8430D814(void);

void func_843184FC(void);

void func_843193F4(unk_D_84390010*);
void func_8431962C(void);
void func_84319668(void);
void func_843196A4(void);
s32 func_8431ADAC(s32);
void func_8431AE7C(unk_D_84390010_728_0168*, f32, f32, f32, f32, s16, s16);
void func_8431AFB4(s32, s32);
void func_8431B290(unk_D_84390010*, unk_D_84390010_654_038*);


s32 func_8432AEE4(s32, unk_D_86002F34_00C*);
void func_8432AF70(unk_D_84390010*);
void func_8432B228(unk_D_84390010*);
void func_8432B510(unk_D_84390010*, s16);
void func_8432B554(unk_D_84390010*);
void func_8432B5B8(unk_D_84390010*, unk_D_84390010_654_038*, s32);
void func_8432B604(void);
void func_8432B704(void);
void func_8432BF88(unk_D_84390010*, s32);
void func_8432C5D4(s32, unk_D_84390010*, unk_D_84390010*, s16, s16);
void func_8432C604(s32, unk_D_84390010*, unk_D_84390010*, s16, s16);
void func_8432C654(s32, unk_D_84390010*, unk_D_84390010*, s16, s16);
void func_8432C68C(s32, unk_D_84390010*, unk_D_84390010*, s32, s32);
void func_8432C6C4(s32, unk_D_84390010*);
void func_8432C7A0(s32, unk_D_84390010*);
void func_8432C80C(s32, unk_D_84390010*);
void func_8432C958(unk_D_800AE540_1194*, s16);
void func_8432C9C0(unk_D_800AE540_1194*, s16);
void func_8432CAA8(unk_D_800AE540_1194*);
void func_8432D0D8(s32, unk_D_86002F34_00C*);
void func_8432E9D8(s32);

void func_843831A0(unk_D_800AE540_0004*, unk_D_800AE540_0004*, unk_D_800AE540_0004*, s32, u8*, s32, s32);




#endif // _FRAGMENT62_H_
