#ifndef _FRAGMENT3_H_
#define _FRAGMENT3_H_

#include "global.h"
#include "src/fragments/34/fragment34.h"
#include "src/3FB0.h"
#include "src/controller.h"

typedef struct unk_func_8790002C {
    /* 0x000 */ unk_D_86002F58_004_000 unk_000;
    /* 0x168 */ unk_D_86002F30* unk_168;
    /* 0x16C */ Vec3f unk_16C;
    /* 0x178 */ char unk178[0x18];
    /* 0x190 */ Vec3f unk_190;
    /* 0x19C */ Vec3f unk_19C;
    /* 0x1A8 */ Vec3f unk_1A8;
    /* 0x1B4 */ Vec3f unk_1B4;
    /* 0x1C0 */ Vec3f unk_1C0;
    /* 0x1CC */ f32 unk_1CC;
    /* 0x1D0 */ f32 unk_1D0;
    /* 0x1D4 */ f32 unk_1D4;
    /* 0x1D8 */ Vec3f unk_1D8;
    /* 0x1E4 */ f32 unk_1E4;
    /* 0x1E8 */ char unk1E8[0x4];
    /* 0x1EC */ f32 unk_1EC;
    /* 0x1F0 */ f32 unk_1F0;
    /* 0x1F4 */ f32 unk_1F4;
    /* 0x1F8 */ f32 unk_1F8;
    /* 0x1FC */ f32 unk_1FC;
    /* 0x200 */ f32 unk_200;
    /* 0x204 */ f32 unk_204;
    /* 0x208 */ f32 unk_208;
    /* 0x20C */ f32 unk_20C;
    /* 0x210 */ f32 unk_210;
    /* 0x214 */ Vec3s unk_214;
    /* 0x21A */ s16 unk_21A;
    /* 0x21C */ s16 unk_21C;
    /* 0x21E */ s16 unk_21E;
    /* 0x220 */ s16 unk_220;
    /* 0x222 */ s16 unk_222;
    /* 0x224 */ s16 unk_224;
    /* 0x226 */ s16 unk_226;
    /* 0x228 */ s16 unk_228;
    /* 0x22A */ s16 unk_22A;
    /* 0x22C */ s16 unk_22C;
    /* 0x22E */ s16 unk_22E;
    /* 0x230 */ s16 unk_230;
    /* 0x232 */ s16 unk_232;
    /* 0x234 */ s16 unk_234;
    /* 0x236 */ s16 unk_236;
    /* 0x238 */ s16 unk_238;
    /* 0x23A */ s16 unk_23A;
    /* 0x23A */ s16 unk_23C;
    /* 0x23E */ s16 unk_23E;
    /* 0x240 */ s16 unk_240;
    /* 0x242 */ s16 unk_242;
    /* 0x244 */ s16 unk_244;
    /* 0x246 */ char unk246[0x2];
    /* 0x248 */ s16 unk_248;
    /* 0x24A */ s16 unk_24A;
    /* 0x24C */ s16 unk_24C;
    /* 0x24E */ char unk24E[0x6];
    /* 0x254 */ s32 unk_254;
    /* 0x258 */ s16 unk_258;
    /* 0x25A */ s16 unk_25A;
    /* 0x25C */ s16 unk_25C;
    /* 0x25E */ s16 unk_25E;
    /* 0x260 */ s16 unk_260;
    /* 0x262 */ s16 unk_262;
    /* 0x264 */ s16 unk_264;
    /* 0x264 */ s16 unk_266;
    /* 0x268 */ s16 unk_268;
    /* 0x26A */ s16 unk_26A;
    /* 0x26C */ s16 unk_26C;
    /* 0x26E */ s16 unk_26E;
    /* 0x270 */ s16 unk_270;
    /* 0x272 */ s16 unk_272;
    /* 0x274 */ f32 unk_274;
    /* 0x278 */ char unk278[0x4];
    /* 0x27C */ f32 unk_27C;
    /* 0x280 */ f32 unk_280;
    /* 0x284 */ f32 unk_284;
    /* 0x288 */ f32 unk_288;
    /* 0x28C */ f32 unk_28C;
    /* 0x290 */ s16 unk_290;
    /* 0x292 */ s16 unk_292;
    /* 0x294 */ s16 unk_294;
    /* 0x296 */ s16 unk_296;
    /* 0x298 */ s16 unk_298;
    /* 0x29A */ s16 unk_29A;
    /* 0x29C */ s16 unk_29C;
    /* 0x29E */ s16 unk_29E;
    /* 0x2A0 */ s16 unk_2A0;
    /* 0x2A2 */ s16 unk_2A2;
    /* 0x2A4 */ s16 unk_2A4;
    /* 0x2A6 */ s16 unk_2A6;
    /* 0x2A8 */ s16 unk_2A8;
    /* 0x2AA */ s16 unk_2AA;
    /* 0x2AC */ s16 unk_2AC;
    /* 0x2AE */ s16 unk_2AE;
    /* 0x2B0 */ s16 unk_2B0;
    /* 0x2B2 */ s16 unk_2B2;
} unk_func_8790002C; // size = 0x2B4

// Possibly unk_D_86002F34_alt7, unk_D_86002F34_alt8, 
// unk_D_86002F34_alt9 or unk_D_86002F34_alt2
typedef struct arg1_func_87902F80 {
    /* 0x00 */ struct GraphNode unk_00;
    /* 0x18 */ Gfx* unk_18;
} arg1_func_87902F80; // size >= 0x1C

typedef struct unk_D_87903E00 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ void* unk_08;
    /* 0x0C */ u32* unk_0C;
} unk_D_87903E00; // size = 0x10

typedef struct unk_D_87903E10 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_D_87903E00* unk_04;
} unk_D_87903E10; // size = 0x8

extern s16 D_87903DA0;
extern s16 D_87903DA4;
extern s16 D_87903DA8;
extern s16 D_87903DAC;
extern s16 D_87903DBC;
extern s16 D_87903DC0;
extern s16 D_87903DC4;
extern s16 D_87903DC8;
extern s16 D_87903DCC;
extern s16 D_87903DD0;
extern s16 D_87903DD4;

extern unk_D_87903E10 D_87903E10;
extern unk_D_87903E10 D_87903E28;
extern unk_D_87903E10 D_87903E40;
extern unk_D_87903E10 D_87903E58;
extern s16 D_87906040;
extern s16 D_87906042;
extern s16 D_87906044;
extern s16 D_87906046;
extern s16 D_87906048;
extern s16 D_8790604A;
extern unk_D_86002F34_00C* D_87906050;
extern unk_D_86002F34_00C* D_87906054;
extern s16 D_87906060;
extern s16 D_87906062;
extern s16 D_87906064;
extern s16 D_87906066;
extern s16 D_87906068;
extern s16 D_8790606A;
extern Vec3s D_8790606C;
extern s16 D_87906072;
extern s16 D_87906076;
extern s16 D_87906078;
extern f32 D_8790607C;
extern f32 D_87906080;
extern Vec3f D_87906088;
extern s16 D_87906094;
extern s16 D_87906096;
extern s16 D_87906098;
extern s16 D_8790609A;
extern Vec3s D_8790609C;

extern s16 D_879060A2;
extern s16 D_879060A4;
extern s16 D_879060A6;
extern s16 D_879060A8;
extern Vec3s D_879060AC;

extern s16 D_87903DB0;
extern s16 D_87903DB8;
extern Controller* D_879060BC;
extern s16 D_879060C0;
extern s16 D_879060C2;
extern s8 D_879060C4[4];
extern s16 D_879060C8;
extern s16 D_879060CA;

extern Vec3f D_879060E0;
extern Vec3f D_87906100;
extern Vec3f D_87906110;

ret_func_80004454 func_87900020(void);
void func_8790002C(unk_func_8790002C* arg0, unk_func_8790002C* arg1);
void func_87900070(unk_func_8790002C* arg0, unk_func_8790002C* arg1);
s32 func_879000C4(unk_func_8790002C* arg0, unk_func_8790002C* arg1);
s32 func_879001A4(unk_func_8790002C* arg0, unk_func_8790002C* arg1);
void func_879002B8(unk_func_8790002C* arg0, s16 arg1, s16 arg2, s16 arg3);
void func_879002FC(unk_func_8790002C* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_87900344(unk_func_8790002C* arg0, s16 arg1, s16 arg2, s16 arg3);
s32 func_87900384(unk_func_8790002C* arg0);
void func_879003A0(unk_func_8790002C* arg0);
void func_879004F8(unk_D_86002F58_004_000* arg0);
void func_87900528(void);
void func_87900558(void);
void func_87900564(unk_func_8790002C* arg0);
void func_87900594(unk_func_8790002C* arg0);
void func_879005AC(unk_func_8790002C* arg0);
void func_879005C4(unk_func_8790002C* arg0);
void func_8790060C(unk_func_8790002C* arg0);
void func_87900770(unk_func_8790002C* arg0);
void func_87900808(unk_func_8790002C* arg0);
void func_87900854(void);
void func_87900920(void);
void func_879009B4(void);

void func_87900A50(void);
void func_87900B64(void);
s32 func_87900C5C(void);
void func_87900F44(void);
void func_879010A4(void);
void func_87901200(void);

void func_87901620(void);
s32 func_8790168C(void);
void func_87901720(unk_D_8140E728* arg0);
void func_87901804(s32 arg0, f32 arg1, Vec3f arg2, func_unk_D_8140E720_008 arg3, unk_D_8140E728_01C* arg4, s16 arg5, u8 arg6, u8 arg7);
void func_879018B0(s32 arg0, s32 arg1, s8 arg2, f32 arg3, Vec3f arg4, func_unk_D_8140E720_008 arg7, unk_D_8140E728_01C* arg8, s16 arg9, u8 argA, u8 argB);
void func_87901958(unk_D_8140E720* arg0, unk_D_8140E728* arg1, s16 arg2);
void func_87901A28(unk_D_8140E728* arg0);
void func_87901ADC(unk_D_8140E728* arg0);
void func_87901B08(void);
void func_87901BB0(unk_D_8140E720* arg0);
void func_87901BD4(unk_D_8140E720* arg0);
void func_87901C20(void);
void func_87901C98(void);
void func_87901DA0(unk_D_8140E720* arg0);
void func_87901F04(unk_D_8140E720* arg0);
void func_87901FA0(unk_D_8140E720* arg0);
void func_87902068(unk_D_8140E720* arg0);
void func_8790215C(unk_D_8140E720* arg0);
void func_87902224(unk_D_8140E720* arg0);
void func_87902318(unk_D_8140E720* arg0);
void func_879023EC(unk_D_8140E720* arg0);
void func_879024DC(unk_D_8140E720* arg0);
void func_87902608(unk_D_8140E720* arg0);
void func_879026D8(unk_D_8140E720* arg0);
void func_879027F0(unk_D_8140E720* arg0);
void func_879028E0(unk_D_8140E720* arg0);
void func_879029F0(unk_D_8140E720* arg0);
void func_87902AE0(unk_D_8140E720* arg0);
void func_87902C9C(unk_D_8140E720* arg0);
void func_87902D3C(Gfx* arg0, unk_D_86002F34_000_014* arg1, UNUSED u16 arg2);
void func_87902F80(s32 arg0, arg1_func_87902F80* arg1);
void func_87902FC8(Gfx* arg0, unk_D_86002F34_000_014* arg1, UNUSED u16 arg2);
void func_8790320C(s32 arg0, arg1_func_87902F80* arg1);

void func_87903260(void);
void func_87903294(void);
void func_879032BC(s16 arg0);
void func_87903358(s16 arg0, s16 arg1);
void func_879033FC(unk_func_8790002C* arg0);
void func_8790354C(void);

void func_87903600(void);
void func_879036B4(unk_func_8790002C* arg0);
void func_8790370C(void);
void func_879037D0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6);
void func_87903838(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6);
void func_879038AC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6);
Gfx* func_87903920(Gfx* arg0, arg1_func_87903D64_014* arg1);
void func_87903D64(s32 arg0, arg1_func_87903D64* arg1);

#endif // _FRAGMENT3_H_
