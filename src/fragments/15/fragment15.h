#ifndef _FRAGMENT15_H_
#define _FRAGMENT15_H_

#include "global.h"
#include "src/controller.h"
#include "src/1C720.h"

typedef struct unk_D_8690B2F8 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} unk_D_8690B2F8; // size >= 0x10

typedef struct unk_D_8690A710 {
    /* 0x000 */ char unk000[0x4];
    /* 0x004 */ f32 unk_004;
    /* 0x008 */ f32 unk_008;
    /* 0x00C */ s32 unk_00C;
    /* 0x010 */ char unk010[0x4];
    /* 0x014 */ u8 unk_014;
    /* 0x015 */ char unk015[0x16F];
} unk_D_8690A710; // size = 0x184

typedef struct unk_D_8690B350 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
} unk_D_8690B350; // size = 0x10

typedef struct unk_D_8690B360 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
} unk_D_8690B360; // size = 0x18

typedef struct unk_D_8690B308 {
    /* 0x00 */ s16 unk_00[8];
    /* 0x18 */ f32 unk_10;
    /* 0x1C */ f32 unk_14;
    /* 0x20 */ f32 unk_18;
    /* 0x24 */ f32 unk_1C;
    /* 0x28 */ f32 unk_20;
    /* 0x2C */ f32 unk_24;
    /* 0x30 */ f32 unk_28;
    /* 0x34 */ f32 unk_2C;
    /* 0x38 */ s16 unk_30;
    /* 0x3A */ s16 unk_32;
    /* 0x3C */ s16 unk_34;
    /* 0x3E */ s16 unk_36;
} unk_D_8690B308; // size >= 0x38

typedef struct unk_D_8690B3C0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} unk_D_8690B3C0; // size >= 0x10

extern u8 D_5001950[];
extern u8 D_5003AE8[];

extern Vec3f D_86908C20;
extern Vec3f D_86908C2C;
extern Vec3f D_86908C38;
extern Vec3f D_86908C44;
extern char* D_86908C58[];
extern Color_RGB8 D_86908C98;
extern Color_RGB8 D_86908C9C;

extern const char D_8690A520[];
extern const char D_8690A52C[];
extern const char D_8690A538[];
extern const char D_8690A544[];
extern const char D_8690A550[];
extern const char D_8690A55C[];
extern const char D_8690A568[];
extern const char D_8690A574[];
extern const char D_8690A584[];
extern const char D_8690A594[];
extern const char D_8690A5A0[];
extern const char D_8690A5AC[];
extern const char D_8690A5B8[];
extern const char D_8690A5C8[];
extern const char D_8690A5D8[];
extern const char D_8690A5E8[];

extern char** D_8690A678;
extern f32 D_8690A708;
extern unk_D_8690A710* D_8690A710;
extern unk_D_8690B2F8 D_8690B2F8;
extern unk_D_8690B308 D_8690B308;
extern s32 D_8690B344;
extern s32 D_8690B348;
extern unk_D_8690B350 D_8690B350;
extern unk_D_8690B360 D_8690B360;

extern s32 D_8690B384;
extern s32 D_8690B388;
extern s32 D_8690B380;
extern s32 D_8690B38C;
extern Controller D_8690B390;
extern unk_D_8690B3C0 D_8690B3C0;
extern s8 D_8690B3D0[255];

s32 func_86900020(s32 arg0, GraphNode* arg1);
s32 func_86900088(s32 arg0, GraphNode* arg1);
s32 func_869000F4(s32 arg0, GraphNode* arg1);
void func_86900110(u8 arg0, u8 arg1, u8 arg2);
void func_86900188(void);
unk_D_86002F58_004_000_010_024* func_86900244(unk_func_80026268_arg0* arg0);
void func_869002AC(void);
void func_86900410(void);
void func_86900484(s32 arg0);
void func_8690060C(void);
void func_869006DC(f32* arg0, f32* arg1, s16* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s16 arg7);
void func_8690079C(void);
void func_869009E8(Controller* arg0, Controller* arg1);
void func_86900A14(void);
void func_86900B04(f32* arg0, f32* arg1, s16 arg2, s16 arg3);
void func_86900B6C(void);
void func_86900B9C(void);
void func_86900CF4(void);
void func_86900D78(void);
void func_86900DE0(void);
void func_86900FFC(u16 arg0);
s32 func_86901044(void);
void func_86901384(void);
s32 func_86901558(void);
s32 func_8690172C(void);
s32 func_869017D0(void);
s32 func_869018A0(void);
s32 func_8690193C(void);
s32 func_869019BC(void);
void func_86901A44(void);
void func_86901B28(void);
void func_86901ECC(void);
void func_86901FB4(void);
void func_86902004(s32 arg0);
s32 func_86902098(s32 arg0, UNUSED s32 arg1);

f32 func_86902230(Vec3f arg0, Vec3f arg1);
f32 func_86902294(f32 arg0);
f32 func_869022D8(Vec3f arg0, Vec3f arg1);
void func_8690232C(void);
void func_86902334(void);
void func_869024B4(void);
void func_869025BC(void);
s32 func_8690274C(void);
void func_86902814(Vec3f* arg0, MtxF* arg1);
void func_86902890(s16 arg0);
void func_86902AE8(void);
void func_86902E6C(Vec3f* arg0, Vec3f* arg1, Vec3f arg2, f32 arg3, s32 arg4);
void func_8690325C(Vec3f* arg0, Vec3f* arg1, Vec3f arg2, f32 arg3);
void func_8690351C(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3, s32 arg4);
void func_869035F4(Vec3f* arg0, Vec3f* arg1);
void func_86903888(Vec3f* arg0, Vec3f* arg1, s32 arg2);
void func_86903D80(void);

void func_869073D8(char*);
void func_86907858(s32);
void func_86907B78(void);
void func_86907D94(void);
void func_86908418(void);
void func_86908668(void);
void func_869089AC(void);


#endif // _FRAGMENT15_H_
