#ifndef _FRAGMENT62_H_
#define _FRAGMENT62_H_

#include "global.h"
#include "src/29BA0.h"
#include "src/6BC0.h"
#include "src/stage_loader.h"
#include "src/fragments/17/fragment17.h"

typedef struct unk_D_84390010_654_038_044 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk01[0x5];
} unk_D_84390010_654_038_044; // size = 0x6

typedef struct unk_D_84390010_654_038 {
    /* 0x00 */ char unk00[0xB];
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ char unk14[0x1];
    /* 0x15 */ u8 unk_15;
    /* 0x16 */ u8 unk_16[9];
    /* 0x1F */ u8 unk_1F[4];
    /* 0x23 */ char unk23[0x3];
    /* 0x26 */ u8 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ char unk2A[0x8];
    /* 0x32 */ u8 unk_32[4];
    /* 0x36 */ char unk36[0xE];
    /* 0x44 */ unk_D_84390010_654_038_044 unk_44;
    /* 0x4A */ char unk4A[0x2];
    /* 0x4C */ u8 unk_4C;
    /* 0x4D */ u8 unk_4D;
    /* 0x4E */ u8 unk_4E;
    /* 0x4F */ u8 unk_4F;
    /* 0x50 */ char unk50[0x2];
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk53[0x3];
    /* 0x56 */ u8 unk_56;
    /* 0x57 */ char unk57[0x1];
    /* 0x58 */ u8 unk_58;
    /* 0x59 */ char unk59[0x1];
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
    /* 0x168 */ char unk168[0x1];
    /* 0x169 */ u8 unk_169;
    /* 0x16A */ s16 unk_16A;
    /* 0x16C */ s16 unk_16C;
    /* 0x16E */ char unk16E[0x2];
} unk_D_84390010_168; // size = 0x170

typedef struct unk_D_84390010_654 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u32 unk_18;
    /* 0x1C */ u8 unk_1C;
    /* 0x1E */ u16 unk_1E;
    /* 0x20 */ char unk20[0xA];
    /* 0x2A */ u8 unk_2A;
    /* 0x2B */ u8 unk_2B;
    /* 0x2C */ u8 unk_2C;
    /* 0x2D */ u8 unk_2D;
    /* 0x2E */ u8 unk_2E;
    /* 0x2F */ u8 unk_2F;
    /* 0x30 */ u16 unk_30;
    /* 0x32 */ char unk32[0x2];
    /* 0x34 */ u16 unk_34;
    /* 0x36 */ u16 unk_36;
    /* 0x38 */ unk_D_84390010_654_038 unk_38;
    /* 0x9C */ unk_D_84390010_654_09C unk_9C;
    /* 0xAC */ unk_D_84390010_654_0AC unk_AC;
    /* 0xBC */ s16 unk_BC;
    /* 0xBE */ s16 unk_BE;
    /* 0xC0 */ char unkC0[1];
    /* 0xC1 */ u8 unk_C1[4];
    /* 0xC8 */ Controller* unk_C8;
} unk_D_84390010_654; // size = 0xCC

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
    /* 0x3C */ char unk3C[0x6C];
    /* 0xA8 */ Vec3f unk_A8;
    /* 0xB4 */ Vec3f unk_B4;
} unk_D_84390010_728_0168; // size >= 0xC0

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
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s8 unk_08[4];
    /* 0x0C */ char unk0C[0x3C];
    /* 0x48 */ s8 unk_48[4];
    /* 0x4C */ char unk4C[0x3C];
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
    /* 0x19 */ u8 unk_19;
    /* 0x1A */ u8 unk_1A;
    /* 0x1B */ u8 unk_1B;
    /* 0x1C */ char unk1C[4];
} unk_D_84390048; // size = 0x20

typedef struct unk_D_84390010_448 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ unk_D_84390048 unk_24;
    /* 0x44 */ s16 unk_44;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ char unk48[0x4];
    /* 0x4C */ f32 unk_4C;
} unk_D_84390010_448; // size >= 0x50

typedef struct unk_D_84390010 {
    /* 0x000 */ unk_D_86002F58_004_000 unk_000;
    /* 0x168 */ unk_D_84390010_168 unk_168[2];
    /* 0x448 */ unk_D_84390010_448 unk_448;
    /* 0x498 */ f32 unk_498;
    /* 0x49C */ f32 unk_49C;
    /* 0x4A0 */ f32 unk_4A0;
    /* 0x4A4 */ s16 unk_4A4;
    /* 0x4A6 */ s16 unk_4A6;
    /* 0x4A8 */ s16 unk_4A8;
    /* 0x4AC */ s32 unk_4AC;
    /* 0x4B0 */ s32 unk_4B0;
    /* 0x4B4 */ s32 unk_4B4;
    /* 0x4B8 */ s32 unk_4B8;
    /* 0x4BC */ char unk4BC[0x4];
    /* 0x4C0 */ s32 unk_4C0;
    /* 0x4C4 */ s32 unk_4C4;
    /* 0x4C8 */ s32 unk_4C8;
    /* 0x4CC */ Vec3f unk_4CC;
    /* 0x4D8 */ Vec3f unk_4D8;
    /* 0x4E4 */ f32 unk_4E4;
    /* 0x4E8 */ u8 unk_4E8;
    /* 0x4E9 */ u8 unk_4E9;
    /* 0x4EC */ unk_D_86002F58_004_000 unk_4EC;
    /* 0x654 */ unk_D_84390010_654 unk_654;
    /* 0x720 */ unk_D_800AE540_1194* unk_720;
    /* 0x724 */ unk_D_800AE540_0004* unk_724;
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
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
} unk_D_8438E7B0_A50; // size = 0x10

typedef struct unk_D_8438E7B0 {
    /* 0x000 */ unk_D_8438E7B0_A50 unk_000[165];
    /* 0xA50 */ unk_D_8438E7B0_A50 unk_A50;
    /* 0xA60 */ char unkA60[0x10];
    /* 0xA70 */ unk_D_8438E7B0_A50 unk_A70;
    /* 0xA80 */ unk_D_8438E7B0_A50 unk_A80;
    /* 0xA90 */ char unkA90[0x60];
    /* 0xAF0 */ unk_D_8438E7B0_A50 unk_AF0;
    /* 0xB00 */ unk_D_8438E7B0_A50 unk_B00;
    /* 0xB10 */ unk_D_8438E7B0_A50 unk_B10;
    /* 0xB20 */ unk_D_8438E7B0_A50 unk_B20;
    /* 0xB30 */ char unkB30[0xB0];
} unk_D_8438E7B0; // size = 0xBE0

typedef struct unk_D_84390240_000 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ s8 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ u8 unk_1A;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ char unk28[0x2];
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ u8 unk_54;
    /* 0x56 */ s16 unk_56;
    /* 0x58 */ s16 unk_58;
    /* 0x5A */ char unk5A[0x2];
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ char unk64[0x4];
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ u8 unk_78;
    /* 0x7A */ s16 unk_7A;
    /* 0x7C */ char unk7C[0x8];
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ char unk88[0xC];
    /* 0x94 */ Vec3f unk_94;
    /* 0xA0 */ Vec3f unk_A0;
    /* 0xAC */ char unkAC[0xC];
    /* 0xB8 */ Vec3f unk_B8;
    /* 0xC4 */ Vec3f unk_C4;
    /* 0xD0 */ Vec3f unk_D0;
    /* 0xDC */ unk_D_86002F34_00C* unk_DC;
} unk_D_84390240_000; // size = 0xE0

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
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
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
    /* 0x00 */Vec3f unk_00;
    /* 0x0C */s16 unk_0C;
    /* 0x0E */s16 unk_0E;
    /* 0x10 */char unk10[0x2];
    /* 0x12 */s16 unk_12;
    /* 0x14 */s16 unk_14;
    /* 0x18 */f32 unk_18;
    /* 0x1C */f32 unk_1C;
    /* 0x20 */s16 unk_20;
    /* 0x22 */s16 unk_22;
    /* 0x24 */char unk24[0x2];
    /* 0x26 */s16 unk_26;
    /* 0x28 */s16 unk_28;
    /* 0x2C */f32 unk_2C;
    /* 0x30 */f32 unk_30;
    /* 0x34 */f32 unk_34;
    /* 0x38 */f32 unk_38;
    /* 0x3C */f32 unk_3C;
} unk_D_843901B0; // size >= 0x40

typedef struct unk_D_843901A0_4C8 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ Vec3f unk_14;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ s16 unk_2A;
} unk_D_843901A0_4C8; // size = 0x2C

typedef struct unk_D_843901A0 {
    /* 0x000 */ u8 unk_000;
    /* 0x004 */ s32 unk_004;
    /* 0x008 */ u8 unk_008[4];
    /* 0x00C */ char unk00C[0x3C];
    /* 0x048 */ u8 unk_048[64];
    /* 0x088 */ s8 unk_088[64];
    /* 0x0C8 */ s8 unk_0C8[64];
    /* 0x148 */ s8 unk_108[64];
    /* 0x148 */ s8 unk_148[64];
    /* 0x188 */ s8 unk_188[64];
    /* 0x1C8 */ s8 unk_1C8[64];
    /* 0x208 */ s8 unk_208[64];
    /* 0x248 */ s8 unk_248[64];
    /* 0x288 */ s8 unk_288[64];
    /* 0x2C8 */ s8 unk_2C8[64];
    /* 0x2C8 */ s8 unk_308[64];
    /* 0x348 */ s8 unk_348[64];
    /* 0x388 */ s8 unk_388[64];
    /* 0x3C8 */ s8 unk_3C8[64];
    /* 0x408 */ s8 unk_408[64];
    /* 0x448 */ s8 unk_448[2][64];
    /* 0x4C8 */ unk_D_843901A0_4C8 unk_4C8;
} unk_D_843901A0; // size = 0x4F4

typedef struct unk_D_84385790 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Color_RGBA8 unk_04;
} unk_D_84385790; // size = 0x8

extern unk_D_8438E7B0* D_84384570[];
extern unk_D_8438FF70* D_84384578[];
extern unk_D_8438FF70* D_84384580[];
extern unk_D_84384588* D_84384588[];
extern u8 D_84384590[];
extern u8 D_843845F0;
extern u8 D_843845F4;
extern u8 D_843845F8;
extern u8 D_843845FC[];

extern s16 D_84384670[];
extern unk_D_843847BC D_843847BC[2];
extern unk_D_86B0C160 D_843847EC[3];
extern unk_D_86B0C160 D_84384888[2];
extern unk_D_86B0C160 D_843848F0;
extern unk_D_86B0C160 D_84384924;
extern unk_D_86B0C160 D_84384958;
extern unk_D_86B0C160 D_8438498C;
extern unk_D_86B0C160 D_843849C0[];
extern unk_D_86B0C160 D_84384AF8;
extern unk_D_86B0C160 D_84384B2C[];
extern Vec3f D_84384C30[];
extern unk_D_84385384_func D_84385380;
extern unk_D_84385384 D_84385384[];
extern Vec3f D_84385B90;
extern Vec3f D_84385B9C;
extern u32 D_84385BC0[];



extern u8 D_843C4DA4;
extern unk_D_843C4DEC D_843C4DEC;
//extern unk_D_843C4E44 D_843C4E44;
extern u8 D_843C4E44;
extern u8 D_843C4E45;
extern u16 D_843C4DC4;
extern u8* D_8438E778;
extern u8* D_8438E77C;




extern unk_D_84390010* D_84390010[2];
extern unk_D_84390010* D_84390018;
extern unk_D_84390010* D_8439001C;
extern unk_D_84390028 D_84390028[2];
extern f32 D_843900A8[];
extern char** D_843900B0;
extern char** D_843900B4;
extern char** D_843900B8;
extern char** D_843900BC;
extern char** D_843900C0;
extern f32 D_84390124;
extern f32 D_84390128;
extern u8 D_84390134;
extern s32 D_84390174;
extern unk_D_84390178 D_84390178;
extern Vec3f D_84390190;
extern unk_D_843901A0* D_843901A0;
extern unk_D_843901B0 D_843901B0;
extern unk_D_84390010* D_84390200;
extern unk_D_84390010* D_84390204;
extern s32 D_8439022C;
extern s32 D_84390230;
extern s32 D_84390234;
extern unk_D_84390240 D_84390240;
extern s32 D_84390288;

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

s32 func_84307AE0(u8 arg0, u8* arg1, s32 arg2);
unk_func_80026268_arg0* func_84307B28(unk_D_84390010* arg0);
s32 func_84307B60(unk_D_84390010* arg0);
f32 func_84307BAC(unk_D_84390010* arg0);
f32 func_84307BD8(unk_D_84390010* arg0);
f32 func_84307C04(unk_D_84390010* arg0);
f32 func_84307C30(unk_D_84390010* arg0);
void func_84307C5C(unk_D_84390010* arg0);
f32 func_84307DE0(unk_D_84390010* arg0);
void func_84307EAC(unk_D_84390010* arg0, f32 arg1);
s32 func_84307EC4(unk_D_84390010* arg0);
s32 func_84307EE0(unk_D_84390010* arg0);
s32 func_84307F00(unk_D_84390010* arg0);
u8 func_84307F24(unk_D_84390010* arg0);
u8 func_84307F68(unk_D_84390010* arg0);
s16 func_84307FAC(unk_D_84390010* arg0);
s32 func_84307FE0(unk_D_84390010* arg0);
f32 func_84308014(unk_D_84390010* arg0);
f32 func_84308058(unk_D_84390010* arg0);
s16 func_8430808C(unk_D_84390010* arg0);
void func_84308094(unk_D_84390010* arg0, Vec3f* arg1);
void func_84308148(unk_D_84390010* arg0, Vec3s* arg1);
u16 func_84308164(unk_D_84390010* arg0);
s16 func_84308190(unk_D_84390010* arg0);
s16 func_843081A4(s32 arg0);
s16 func_843081BC(unk_D_84390010* arg0);
u8 func_843081C4(unk_D_84390010* arg0);
void func_843081D4(unk_D_84390010* arg0, Vec3f* arg1);
void func_843081F0(unk_D_84390010* arg0, Vec3f* arg1);
void func_843083A0(unk_D_84390010* arg0, Vec3f* arg1);
void func_84308520(unk_D_84390010* arg0, Vec3f* arg1);
f32 func_84308548(unk_D_84390010* arg0);
f32 func_84308598(unk_D_84390010* arg0);
unk_D_86002F58_004_000_004* func_843085C4(unk_D_84390010* arg0, s32 arg1);
s32 func_843085E0(unk_D_84390010* arg0, UNUSED s32 arg1);
char* func_843085F0(unk_D_84390010* arg0);
u8* func_8430862C(unk_D_84390010* arg0);
void func_84308654(unk_D_84390010* arg0, s32 arg1, s32 arg2);
void func_84308660(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_843087F8(unk_D_84390010* arg0);
void func_8430897C(unk_D_84390010* arg0);
void func_843089DC(unk_D_84390010* arg0, s32 arg1);
void func_843089F4(unk_D_84390010* arg0, s32 arg1);
void func_843089FC(unk_D_84390010* arg0, Controller* arg1);
void func_84308A04(unk_D_84390010* arg0, s32 arg1);
s32 func_84308A4C(unk_D_84390010* arg0);
s32 func_84308BD0(unk_D_84390010* arg0);
s32 func_84308D54(unk_D_84390010* arg0);
u8 func_84308D90(unk_D_84390010* arg0);
s32 func_84308D98(unk_D_84390010* arg0);
void func_84308DB8(unk_D_84390010* arg0, unk_D_84390010* arg1, s32 arg2, s32 arg3);
void func_84308ED4(unk_D_84390010* arg0, unk_D_84390010_728* arg1, s16 arg2);
void func_84308F94(unk_D_84390010* arg0, s16 arg1);
void func_84309110(unk_D_84390010* arg0);
void func_84309168(unk_D_84390010* arg0);
void func_8430920C(unk_D_84390010* arg0);
void func_843092B4(unk_D_84390010* arg0);
void func_84309328(unk_D_84390010* arg0);
void func_84309368(unk_D_84390010* arg0);


void func_843093F0(unk_D_84390010* arg0, f32 arg1, s16 arg2);
void func_84309448(unk_D_84390010* arg0, unk_D_84390010* arg1, f32 arg2, f32 arg3, s32 arg4);
void func_843095A4(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5);
void func_843096EC(unk_D_84390010* arg0);
void func_84309780(unk_D_84390010* arg0);
void func_84309874(unk_D_84390010* arg0);
void func_84309A24(unk_D_84390010* arg0);
s32 func_84309B0C(unk_D_84390010* arg0);
void func_84309C50(unk_D_84390010* arg0);
void func_84309D78(unk_D_84390010* arg0, s16 arg1);
void func_84309F0C(unk_D_84390010* arg0);
void func_84309F30(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_84309FD4(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A090(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A0E4(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A17C(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A22C(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A280(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A308(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A390(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A3E4(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A464(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A4E0(UNUSED unk_D_84390010* arg0, UNUSED unk_D_84390010* arg1);
void func_8430A4EC(unk_D_84390010* arg0, unk_D_84390010* arg1);
s32 func_8430A558(unk_D_84390010* arg0, s16 arg1, s16 arg2);
void func_8430A5D4(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A618(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A6AC(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A7BC(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A828(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A848(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430A8DC(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430AA18(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430AA84(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430AB00(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430ABF0(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430AD10(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430AD7C(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430ADE8(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430AE3C(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430AE90(unk_D_84390010* arg0);
void func_8430AF08(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430AF80(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B104(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B158(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B1B8(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B244(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B298(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B2AC(unk_D_84390010* arg0, UNUSED unk_D_84390010* arg1);
void func_8430B374(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B3C8(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B40C(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B550(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B68C(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B6F8(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B734(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B8FC(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B950(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430B968(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430BAB8(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430BB0C(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430BB24(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430BBE4(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430BC38(UNUSED unk_D_84390010* arg0, UNUSED unk_D_84390010* arg1);
void func_8430BC44(s32 arg0);
void func_8430BD9C(unk_D_84390010* arg0, u8 arg1, u8 arg2);
void func_8430BDB0(unk_D_84390010* arg0);
void func_8430BDBC(unk_D_84390010* arg0, f32 arg1, s16 arg2);
void func_8430BE08(unk_D_84390010* arg0, unk_D_84390010* arg1, f32 arg2, f32 arg3, s32 arg4);
void func_8430BEC0(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430BF3C(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430BFB0(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430C004(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430C010(s32 arg0);


void func_8430C070(Vec3f* arg0, Vec3f* arg1, f32* arg2, s16* arg3, s16* arg4);
Vec3f* func_8430C120(Vec3f* arg0);
Vec3f* func_8430C138(Vec3f* arg0, Vec3f* arg1, f32 arg2, s16 arg3);
void func_8430C19C(Vec3f* arg0, f32 arg1, s16 arg2);
Vec3f* func_8430C1E4(Vec3f* arg0, Vec3f* arg1);
Vec3s* func_8430C204(Vec3s* arg0, Vec3s* arg1);
Vec3f* func_8430C224(Vec3f* arg0, f32 arg1, f32 arg2, f32 arg3);
s16 func_8430C260(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
f32 func_8430C2A4(Vec3f arg0, Vec3f arg1);
f32 func_8430C308(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
s32 func_8430C384(f32 arg0);
u16 func_8430C414(s32 arg0);
s32 func_8430C4F8(s16* arg0, s16 arg1, s16 arg2);
s32 func_8430C59C(s16* arg0, s16 arg1, f32 arg2);
void func_8430C718(f32* arg0, f32 arg1, f32 arg2);
void func_8430C780(s16* arg0, s16 arg1, s16 arg2);
void func_8430C7B4(u16* arg0, u16 arg1, s16 arg2);
void func_8430C7E4(f32* arg0, f32 arg1);
void func_8430C8A0(f32* arg0, f32 arg1);
void func_8430C97C(f32* arg0, f32 arg1);
void func_8430CA4C(f32* arg0, f32 arg1);
void func_8430CB3C(f32* arg0, f32 arg1);


void func_8430CC20(void);
void func_8430CC84(void);
s32 func_8430CCC8(void);
s32 func_8430CD0C(void);
s32 func_8430CDAC(s32 arg0, s32 arg1);
s32 func_8430CE00(void);
s32 func_8430D02C(void);
s32 func_8430D124(void);
void func_8430D268(void);
s32 func_8430D294(void);
void func_8430D30C(void);
s32 func_8430D334(unk_D_84390010* arg0);
void func_8430D364(void);
s32 func_8430D434(unk_D_84390010* arg0);
s32 func_8430D574(unk_D_84390010* arg0, s32 arg1);
void func_8430D5BC(unk_D_84390010* arg0);
void func_8430D638(unk_D_84390010* arg0);
void func_8430D6D0(unk_D_84390010* arg0);
void func_8430D710(s32 arg0);
void func_8430D814(void);
s32 func_8430D8C4(unk_D_84390010* arg0);
s32 func_8430D9EC(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430DB58(unk_D_84390010* arg0, UNUSED unk_D_84390010* arg1);
void func_8430DBA0(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430DCD4(unk_D_84390010* arg0, unk_D_84390010* arg1);
s32 func_8430DE20(unk_D_84390010* arg0, unk_D_84390010* arg1);
s32 func_8430DFCC(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430E1CC(unk_D_84390010* arg0);
void func_8430E490(unk_D_84390010* arg0);
s32 func_8430E504(unk_D_84390010* arg0);
void func_8430E580(unk_D_84390010* arg0);
void func_8430E5AC(unk_D_84390010* arg0, s32 arg1);
void func_8430E72C(unk_D_84390010* arg0, Controller* arg1);
void func_8430E8E8(unk_D_84390010* arg0);
void func_8430EB1C(unk_D_84390010* arg0);
s32 func_8430EBA8(unk_D_84390010* arg0);
s32 func_8430ED88(unk_D_84390010* arg0);
void func_8430EE50(unk_D_84390010* arg0);
void func_8430EF4C(unk_D_84390010* arg0);
s32 func_8430F044(unk_D_84390010* arg0, UNUSED Controller* arg1);
void func_8430F080(unk_D_84390010* arg0);
void func_8430F0C0(unk_D_84390010* arg0);
s32 func_8430F27C(unk_D_84390010* arg0);
s32 func_8430F350(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430F458(void);
void func_8430F4AC(void);
void func_8430F500(void);
void func_8430F598(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430F5F4(void);
void func_8430F794(unk_D_84390010* arg0, unk_D_84390010* arg1);
void func_8430F8B8(void);
void func_8430FB20(void);
void func_8430FB68(void);


void func_8430FC10(void);
void func_8430FC28(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_8430FF8C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5);
void func_84310334(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5);
void func_84310360(void);
void func_84310368(s32 arg0, s32 arg1, f32 arg2, s32 arg3);
void func_843109EC(void);
void func_843109F4(s32 arg0, s32 arg1, s32 arg2);
void func_84310B9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_84310CE4(s16 arg0, s16 arg1, s32 arg2, char* arg3, s32 arg4);
void func_84310DC4(s16 arg0, s16 arg1, s32 arg2, u8* arg3, s32 arg4, s32 arg5);
void func_84310FA4(unk_D_84390010* arg0, unk_D_800AE540_0004* arg1, s16 arg2, s16 arg3, s32 arg4, u16 arg5, s32 arg6);
void func_84311048(unk_D_84390010* arg0, unk_func_80026268_arg0* arg1, unk_D_84385790* arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA);
s32 func_843112C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4);
void func_84311420(void);
void func_84311428(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_843116D8(s16 arg0, s16 arg1);
void func_843118A8(s16 arg0, s16 arg1);
void func_84311A38(unk_D_84390010* arg0, s16 arg1, s16 arg2);
void func_84311F30(unk_D_84390010* arg0, s16 arg1, s16 arg2, u16 arg3, s32 arg4);
void func_843128A0(unk_D_84390010* arg0, s16 arg1, s16 arg2, u16 arg3, s32 arg4);
void func_84313148(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_843133B4(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_843135B8(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_84313750(s32 arg0, s32 arg1, char* arg2);
s32 func_8431379C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_84313908(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_84313A74(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_8431493C(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_84314B20(s16 arg0, s16 arg1, char* arg2);
void func_84314B6C(unk_D_84390010* arg0, unk_D_800AE540_0004* arg1, unk_func_80026268_arg0* arg2, s32 arg3, s32 arg4, s32 arg5);
void func_84314F60(unk_D_84390010* arg0, unk_D_800AE540_0004* arg1, unk_func_80026268_arg0* arg2, s32 arg3, s32 arg4, s32 arg5);
void func_8431524C(unk_D_84390010* arg0, unk_D_800AE540_0004* arg1, s16 arg2, s16 arg3, s32 arg4);
void func_84315550(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_8431595C(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_84315ADC(s32 arg0, s16 arg1, s16 arg2, char* arg3);
s32 func_84315BC0(char* arg0, s16 arg1, s16 arg2);
void func_84315C28(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2, Vec3f arg3);
void func_84315D88(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2);
s32 func_84315EC0(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2);
void func_84315FAC(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2, Vec3f arg3);
void func_843160C0(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2);
s32 func_843161F8(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2);
void func_843162E4(s32 arg0, s16 arg1, s16 arg2, char* arg3);
void func_843163C8(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_84316610(void);
void func_84316640(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);
void func_843167D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, s32 arg5);
void func_8431694C(void);
void func_84317004(void);
void func_8431712C(void);
void func_843172A0(unk_D_84390010* arg0, unk_D_84390010_654* arg1);
void func_84317558(unk_D_84390010* arg0, unk_D_84390010_654* arg1);


void func_84317810(void);
void func_8431790C(void);
void func_84317940(s8* arg0, s8* arg1, ...);
void func_843179F4(s8* arg0, s8 arg1);
void func_84317AA8(char* arg0, s32 arg1);
void func_84317B38(void);
void func_84317B40(void);
void func_84317BDC(void);
void func_84317EDC(void);
void func_843180AC(void);
void func_843184E4(s32 arg0);
void func_843184FC(void);
void func_84318514(s8* arg0);
void func_84318640(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2);
s32 func_84318CE4(unk_D_843901A0_4C8* arg0);
void func_843190A8(s16 arg0, s16 arg1);
void func_843193F4(unk_D_84390010* arg0);
void func_84319408(unk_D_84390010* arg0, s32 arg1);
void func_843194A0(unk_D_84390010* arg0);
void func_84319564(void);
void func_8431962C(void);
void func_84319668(void);
void func_843196A4(void);


s32 func_843197A0(void);
s32 func_84319878(UNUSED unk_D_84390010* arg0, unk_D_86002F34_00C* arg1);
s32 func_843198EC(UNUSED unk_D_84390010* arg0, UNUSED unk_D_86002F34_00C* arg1);
void func_8431995C(unk_D_86002F34_00C* arg0);
void func_84319AE8(unk_D_86002F34_00C* arg0);
void func_84319C58(unk_D_86002F34_00C* arg0, s32 arg1);
void func_84319F10(unk_D_86002F34_00C* arg0, s32 arg1);
void func_8431A024(unk_D_86002F34_00C* arg0, s32 arg1);
void func_8431A098(unk_D_86002F34_00C* arg0);
void func_8431A130(unk_D_86002F34_00C* arg0);
void func_8431A1C8(unk_D_86002F34_00C* arg0);
void func_8431A2C8(unk_D_86002F34_00C* arg0, s32 arg1);
void func_8431A4C4(unk_D_86002F34_00C* arg0);
void func_8431A718(unk_D_86002F34_00C* arg0);
void func_8431A780(unk_D_86002F34_00C* arg0);
void func_8431A7B8(unk_D_86002F34_00C* arg0);
void func_8431A8B0(unk_D_86002F34_00C* arg0);
void func_8431A94C(unk_D_86002F34_00C* arg0);
void func_8431A9E0(unk_D_86002F34_00C* arg0);
void func_8431AA3C(unk_D_86002F34_00C* arg0);
void func_8431AA78(unk_D_86002F34_00C* arg0);
void func_8431AAAC(unk_D_86002F34_00C* arg0);
void func_8431AAFC(unk_D_86002F34_00C* arg0);


f32 func_8431AD20(unk_D_84390010* arg0, f32 arg1, f32 arg2);
s32 func_8431AD68(s32 arg0);
s32 func_8431ADAC(s32 arg0);
s32 func_8431ADF0(s32 arg0);
s32 func_8431AE20(s32 arg0);
void func_8431AE4C(s32 arg0);
void func_8431AE5C(void);
void func_8431AE6C(void);
void func_8431AE7C(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5, s16 arg6);
void func_8431AED8(unk_D_84390010* arg0, Vec3f* arg1);
void func_8431AF58(unk_D_84390010* arg0, Vec3f* arg1, s32 arg2);
void func_8431AFB4(s32 arg0, s32 arg1);
void func_8431AFD0(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2);
void func_8431AFE4(s32 arg0, u16 arg1);
void func_8431B004(void);
void func_8431B078(unk_D_84390010* arg0);
void func_8431B174(unk_D_86002F34_00C* arg0);
void func_8431B290(UNUSED unk_D_84390010* arg0);
s32 func_8431B2B8(s16 arg0, s16 arg1);
s32 func_8431B34C(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2);
s32 func_8431B42C(UNUSED unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2);
void func_8431B4C0(s16 arg0, s16 arg1, f32 arg2);
void func_8431B500(unk_D_86002F34_00C* arg0, s32 arg1);
void func_8431B830(unk_D_86002F34_00C* arg0);
void func_8431B858(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1);
void func_8431BA5C(void);
void func_8431BAB4(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1, Vec3f arg2, s16 arg3, s16 arg4, f32 arg5, f32 arg6);
void func_8431BB24(unk_D_86002F34_00C* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5);
void func_8431BB80(unk_D_86002F34_00C* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5);
void func_8431BBDC(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4);
void func_8431BC38(unk_D_86002F34_00C* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5);
void func_8431BCA4(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4);
void func_8431BD10(UNUSED unk_D_86002F34_00C* arg0);
void func_8431BD18(f32* arg0, f32* arg1);
void func_8431BD94(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, UNUSED f32 arg2);
void func_8431C594(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431C71C(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431C750(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431C784(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431C7A4(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
s32 func_8431C8E0(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431CB54(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431CC38(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431CCFC(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431CEF0(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, UNUSED s32 arg2);
void func_8431CFA4(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
s32 func_8431D048(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
s32 func_8431D118(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2, s32 arg3);
s32 func_8431D318(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431D5C8(UNUSED unk_D_86002F34_00C* arg0);
void func_8431D5D0(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2);
void func_8431D704(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_8431D750(f32 arg0, f32 arg1);
void func_8431D764(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_8431D7B0(f32 arg0, f32 arg1);
void func_8431D7C4(f32 arg0, f32 arg1);
void func_8431D7D8(unk_D_86B0C160* arg0, unk_D_86002F34_00C* arg1, unk_D_84390010* arg2);
void func_8431D968(unk_D_86B0C160* arg0, unk_D_86002F34_00C* arg1);
s32 func_8431DA38(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
s32 func_8431DBEC(UNUSED unk_D_86002F34_00C* arg0);
void func_8431DC78(unk_D_86002F34_00C* arg0, s32 arg1);
s32 func_8431DE30(unk_D_86002F34_00C* arg0, s32 arg1);
void func_8431DF98(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431E118(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431E1DC(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2);
void func_8431E368(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2);
void func_8431E4DC(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2);
void func_8431E63C(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2);
void func_8431E7D0(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2);
void func_8431E90C(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2);
void func_8431EA1C(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2, s32 arg3);
void func_8431EAB8(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431EBD0(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431ECEC(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431EE08(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431EF54(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431F050(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2);
void func_8431F194(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1);
void func_8431F290(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1, s32 arg2, s32 arg3);
void func_8431F420(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1, s32 arg2);
void func_8431F500(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1, s32 arg2);


void func_8431F610(unk_D_84390010* arg0);
void func_8431F680(void);
s32 func_8431F690(unk_D_84390010* arg0);
s32 func_8431F7B0(unk_D_84390010* arg0);
s32 func_8431F888(unk_D_84390010* arg0);
s32 func_8431F998(unk_D_84390010* arg0);
s32 func_8431FAB4(void);
void func_8431FC74(void);
void func_8431FCC4(void);
s32 func_8431FCCC(unk_D_84390010* arg0);
void func_8431FF18(void);
void func_8431FF28(void);
void func_8431FF3C(UNUSED unk_D_86002F34_00C* arg0, s32 arg1);
void func_8431FF5C(unk_D_86002F34_00C* arg0);
void func_8431FF70(unk_D_86002F34_00C* arg0);
s32 func_8431FF8C(unk_D_84390010* arg0);
s32 func_8431FFD0(unk_D_84390010* arg0);
s32 func_84320020(unk_D_84390010* arg0);
s32 func_84320064(unk_D_84390010* arg0);
s32 func_843200B4(unk_D_84390010* arg0);
void func_84320108(void);
void func_843202A0(void);
s32 func_84320400(void);
void func_8432056C(void);
s32 func_84320658(s32 arg0);
s32 func_843206B8(s32 arg0);
s32 func_84320710(s32 arg0);
void func_84320768(unk_D_86002F34_00C* arg0);
void func_8432079C(u8 arg0);
void func_84320864(void);
void func_843208B0(void);
s32 func_84320A8C(void);
void func_84320B48(void);
void func_84320C38(unk_D_86002F34_00C* arg0);
void func_84320CEC(unk_D_86002F34_00C* arg0);
void func_84320E54(unk_D_86002F34_00C* arg0);
s32 func_84320EA0(void);
s32 func_8432103C(void);
s32 func_843210BC(void);
void func_8432113C(void);
void func_84321184(unk_D_86002F34_00C* arg0);
void func_84321208(unk_D_86002F34_00C* arg0);
s32 func_84321594(unk_D_84390010* arg0);
void func_84321698(unk_D_86002F34_00C* arg0);
void func_84321860(unk_D_86002F34_00C* arg0);
void func_84321A40(unk_D_86002F34_00C* arg0);
void func_84321AAC(unk_D_86002F34_00C* arg0);
void func_84321B54(unk_D_86002F34_00C* arg0);
void func_84321D34(UNUSED unk_D_86002F34_00C* arg0);
void func_84321D3C(unk_D_86002F34_00C* arg0);
void func_84321F2C(UNUSED unk_D_86002F34_00C* arg0);
void func_84321F74(UNUSED unk_D_86002F34_00C* arg0);
void func_84321FB8(unk_D_86002F34_00C* arg0);
void func_843221A8(unk_D_86002F34_00C* arg0);
void func_84322284(UNUSED unk_D_86002F34_00C* arg0);
void func_84322350(unk_D_86002F34_00C* arg0);
void func_843223FC(unk_D_84390010* arg0);
void func_843224C8(unk_D_86002F34_00C* arg0);
void func_84322600(unk_D_86002F34_00C* arg0);
void func_84322640(unk_D_86002F34_00C* arg0);
void func_84322698(unk_D_84390010* arg0);
void func_843226A4(UNUSED unk_D_86002F34_00C* arg0);
void func_843226E0(unk_D_86002F34_00C* arg0);
s32 func_843229A4(unk_D_86002F34_00C* arg0);
void func_84322B04(unk_D_86002F34_00C* arg0);
void func_84322E70(unk_D_86002F34_00C* arg0);
void func_843230D8(unk_D_86002F34_00C* arg0, s32 arg1);
s32 func_843233E0(unk_D_86002F34_00C* arg0, s32 arg1);
void func_843234A0(UNUSED unk_D_86002F34_00C* arg0);
s32 func_843234FC(UNUSED unk_D_86002F34_00C* arg0);
void func_84323538(unk_D_86002F34_00C* arg0);
void func_843235F4(unk_D_86002F34_00C* arg0);
void func_84323740(unk_D_86002F34_00C* arg0);
void func_84323808(unk_D_86002F34_00C* arg0);
void func_84323928(unk_D_86002F34_00C* arg0);
void func_843239EC(unk_D_86002F34_00C* arg0);
void func_84323AFC(unk_D_84390010* arg0);
s32 func_84323B2C(unk_D_84390010* arg0);
void func_84323B50(unk_D_86002F34_00C* arg0, s32* arg1, s32* arg2);
void func_84323BCC(unk_D_86002F34_00C* arg0);
void func_84323CE4(unk_D_86002F34_00C* arg0);
void func_84323E44(unk_D_86002F34_00C* arg0);
void func_84323FA0(unk_D_86002F34_00C* arg0);
void func_84324404(void);
void func_8432440C(void);
void func_84324414(unk_D_86002F34_00C* arg0);
void func_843248B8(unk_D_86002F34_00C* arg0);
void func_84324988(unk_D_86002F34_00C* arg0);
void func_843249F8(unk_D_86002F34_00C* arg0);
s32 func_84324A68(void);
void func_84324C28(unk_D_86002F34_00C* arg0);
void func_84324F1C(unk_D_86002F34_00C* arg0);
void func_84325080(unk_D_86002F34_00C* arg0);
void func_843251D4(unk_D_86002F34_00C* arg0);
void func_843255DC(unk_D_86002F34_00C* arg0);
void func_84325724(unk_D_86002F34_00C* arg0);
void func_84325A10(unk_D_86002F34_00C* arg0);
s32 func_84325CAC(unk_D_84390010* arg0);
void func_84325CDC(unk_D_86002F34_00C* arg0);
void func_84325E94(unk_D_86002F34_00C* arg0);
void func_843261CC(unk_D_86002F34_00C* arg0);
void func_84326460(unk_D_86002F34_00C* arg0);
void func_84326570(unk_D_86002F34_00C* arg0);
void func_843266D4(unk_D_86002F34_00C* arg0);
void func_8432691C(unk_D_86002F34_00C* arg0);
void func_84326A70(void);
void func_84326A78(UNUSED unk_D_86002F34_00C* arg0);
void func_84326AC4(unk_D_86002F34_00C* arg0);
void func_84326CB4(unk_D_86002F34_00C* arg0);
void func_84326E84(unk_D_86002F34_00C* arg0);
void func_8432734C(unk_D_86002F34_00C* arg0);
void func_843275F8(unk_D_86002F34_00C* arg0);
void func_84327720(unk_D_86002F34_00C* arg0);
void func_84327B90(unk_D_86002F34_00C* arg0);
void func_84327D98(unk_D_84390010* arg0);
void func_84327DC0(unk_D_86002F34_00C* arg0);
void func_84328250(unk_D_86002F34_00C* arg0);
void func_84328734(unk_D_86002F34_00C* arg0);


void func_84328990(unk_D_86002F34_00C* arg0);
void func_84328A70(UNUSED unk_D_86002F34_00C* arg0);
void func_84328B30(UNUSED unk_D_86002F34_00C* arg0);
void func_84328BF0(unk_D_86002F34_00C* arg0);
void func_84328D70(unk_D_86002F34_00C* arg0);
void func_84328EC0(UNUSED unk_D_86002F34_00C* arg0);
void func_84328F2C(unk_D_86002F34_00C* arg0);
void func_843290A0(unk_D_86002F34_00C* arg0);
void func_84329164(unk_D_86002F34_00C* arg0);
void func_843292D8(unk_D_86002F34_00C* arg0);
void func_843293A8(UNUSED unk_D_86002F34_00C* arg0);
void func_843293B0(void);
void func_843293B8(unk_D_86002F34_00C* arg0);


void func_843294A0(unk_D_86002F34_00C* arg0);
void func_843295D0(unk_D_86002F34_00C* arg0);
void func_843296B8(unk_D_86002F34_00C* arg0, UNUSED unk_D_84390010* arg1, UNUSED unk_D_84390010* arg2);
void func_843297AC(void);
void func_843297E8(UNUSED unk_D_86002F34_00C* arg0);
void func_843297F0(UNUSED unk_D_86002F34_00C* arg0);
void func_843297F8(unk_D_86002F34_00C* arg0);
void func_84329858(unk_D_86002F34_00C* arg0);
void func_84329B04(unk_D_86002F34_00C* arg0);
void func_84329DB8(unk_D_86002F34_00C* arg0);
u16 func_84329DFC(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1, unk_D_84390010* a2, s16 arg3, f32 arg4);
u16 func_8432A024(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1, unk_D_84390010* a2, s16 arg3, f32 arg4);
void func_8432A2D4(unk_D_86002F34_00C* arg0);
void func_8432A398(unk_D_86002F34_00C* arg0);
void func_8432A414(void);
void func_8432A41C(void);
void func_8432A448(void);
void func_8432A4B0(void);
void func_8432A510(void);
void func_8432A578(unk_D_86002F34_00C* arg0);
void func_8432ABBC(unk_D_86002F34_00C* arg0);
void func_8432ADD8(unk_D_86002F34_00C* arg0);
s32 func_8432AEE4(s32 arg0, unk_D_86002F34_00C* arg1);


void func_8432AF70(unk_D_84390010*);
void func_8432B0E4(unk_D_84390010*);
void func_8432B13C(unk_D_84390010*);
void func_8432B1BC(unk_D_84390010*);
void func_8432B228(unk_D_84390010*);
void func_8432B38C(unk_D_84390010*);
void func_8432B448(unk_D_84390010*);
void func_8432B490(void);
void func_8432B4B0(void);
void func_8432B4D0(void);
void func_8432B4F0(void);
void func_8432B510(unk_D_84390010*, s16);
void func_8432B554(unk_D_84390010*);
void func_8432B588(unk_D_84390010*);
void func_8432B5B8(unk_D_84390010*, unk_D_84390010_654_038*, s32);
void func_8432B604(void);
void func_8432B704(void);
void func_8432B808(void);
void func_8432BBC0(void);
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
void func_8432E8BC(void);
void func_8432E9D8(s32);
void func_8432F9B4(void);
f32 func_8435E158(f32, f32, f32*);
f32 func_8435FCD0(void);
void func_8436EEF0(s32, s32);
s32 func_8436EF48(void);
void func_8436EF54(void);
void func_8436F664(void);
s32 func_8436F6D8(void);
void func_8436F9D8(s32, s32);
u16 func_8436FC7C(unk_D_84390010*, unk_D_84390010*);
void func_84370ADC(unk_D_84390010*);
void func_84370B7C(unk_D_84390010*);
void func_8437345C(void);
void func_84373570(unk_D_84390010*);
void func_843831A0(unk_D_800AE540_0004*, unk_D_800AE540_0004*, unk_D_800AE540_0004*, s32, u8*, s32, s32);
void func_8438363C(s32, s32, s32);
s32 func_84383B5C(s32);
s32 func_843841C4(s32, s32);

#endif // _FRAGMENT62_H_
