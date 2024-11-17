#ifndef _22630_H_
#define _22630_H_

#include "global.h"
#include "memory.h"
#include "29BA0.h"
#include "2D340.h"

typedef enum {
    POKEMON_ROM_NONE = 0,
    POKEMON_ROM_RED = 1,
    POKEMON_ROM_GREEN = 2,
    POKEMON_ROM_BLUE = 3,
    POKEMON_ROM_YELLOW = 7,
} PokemonRomType;

typedef struct unk_D_80070F84 {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ char unk01[0x4];
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ char unk0B[0x4];
    /* 0x0F */ u8 unk_0F[1];
    /* 0x10 */ char unk10[0x3];
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ char unk14[0x3];
} unk_D_80070F84; // size = 0x17

extern unk_D_80070F84 D_80070F84[];
extern unk_D_80070F84 D_80070FA0[];

typedef struct unk_D_800AE4E8_004_1_000_010 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01[2];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08[4];
    /* 0x0C */ u8 unk_0C[2];
    /* 0x0E */ u8 unk_0E[3];
    /* 0x11 */ u8 unk_11[2];
    /* 0x13 */ u8 unk_13[2];
    /* 0x15 */ u8 unk_15[2];
    /* 0x17 */ u8 unk_17[2];
    /* 0x19 */ u8 unk_19[2];
    /* 0x1B */ u8 unk_1B[2];
    /* 0x1D */ u8 unk_1D[4];
    /* 0x21 */ u8 unk_21[11];
    /* 0x2C */ u8 unk_2C[11];
} unk_D_800AE4E8_004_1_000_010; // size = 0x37

typedef struct unk_func_80022C28_ret {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ char unk05[0x3];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk_func_80022C28_ret; // size = 0xC

typedef struct unk_func_8820BE14_sp {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk01[0x3];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ char unk05[0x1];
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ u8 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x0E */ s32 unk_10;
    /* 0x0E */ s16 unk_14;
    /* 0x0E */ s16 unk_16;
    /* 0x0E */ s16 unk_18;
    /* 0x0E */ s16 unk_1A;
    /* 0x0E */ s16 unk_1C;
    /* 0x0E */ s16 unk_1E;
    /* 0x20 */ char unk20[0x4];
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ char unk26[0xA];
    /* 0x30 */ char unk_30[11];
    /* 0x3B */ char unk_3B[11];
    /* 0x46 */ char unk46[0xC];
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
} unk_func_8820BE14_sp; // size = 0x54

u16 func_80021A30(u8* arg0);
u32 func_80021A48(u8* arg0);
void func_80021A68(u8* arg0, s32 arg1);
void func_80021A78(u8* arg0, s32 arg1);
char* func_80021A90(char* arg0, char* arg1);
void func_80021B5C(char*, char*);
char* func_80021B7C(char* arg0, char* arg1);
void func_80021C20(char*, char*);
char* func_80021C40(char* arg0, char* arg1);
char* func_80021C80(char* arg0, char* arg1);
char* func_80021CA4(char* arg0, s32 arg1);
char* func_80021CE0(s32 arg0, s8* arg1);
void func_80021D9C(unk_func_80026268_arg0* arg0, unk_D_800AE4E8_004_1_000_010* arg1);
void func_80021F04(unk_func_80026268_arg0* arg0, unk_D_800AE4E8_004_1_000_010* arg1);
u16 func_80022084(u16 arg0);
u16 func_800220CC(s32 arg0, u16 arg1);
u32 func_80022170(s32 arg0, s32 arg1, u16 arg2, u16 arg3, s32 arg4);
void func_80022338(unk_func_80026268_arg0* arg0);
u32 func_800224B8(s32 arg0, u16 arg1);
u16 func_800226C0(s32 arg0, u32 arg1);
void func_80022734(unk_func_8820BE14_sp*);
void func_800228B0(unk_func_8820BE14_sp*);
s8 func_80022A28(s32);
u8 func_80022A38(s32 arg0);
u8 func_80022A60(s32 arg0);
unk_func_80022C28_ret* func_80022C28(s32, s32, s32, s32);
unk_func_80022C28_ret* func_80022CC0(s32, s32, s32, s32, char*, s32);
s32 func_80022D24(unk_func_80022C28_ret*);
s32 func_80022D8C(unk_func_80022C28_ret*);
s32 func_80022E18(unk_func_80026268_arg0*, s32, unk_func_80022C28_ret*);
s32 func_80022F24(unk_func_88205880_00D0*, s32, unk_func_80022C28_ret*);
void func_80023068(void);
char* func_8002311C(s32 arg0);
s32 func_80023130(u8* arg0);
s32 func_80023230(u8* arg0, u8* arg1);
s8 func_80023324(s32 arg0);
s32 func_80023480(s32 arg0);
void func_800238D8(UNUSED MainPoolBlock* arg0, u32 arg1);
void func_80023990(s32 arg0);
s32 func_80023A04(s32 arg0);
void func_80023AF8(s32);
void func_80023D60(s32);
void func_80023F78(s32 arg0);
void func_80024040(s32 arg0);
s32 func_800240A0(void);
void func_80024208(s32);
s32 func_80024A48(s32, s32, s32);
s32 func_80024EF4(void);
s32 func_80024F00(s32);
u8 func_80024F68(s32);
s32 func_80024FB0(s32 arg0);
s32 func_80025084(s32);
s32 func_8002513C(s32);
char* func_800251B0(s32, s8*);
s32 func_80025370(s32);
s32 func_8002539C(s32);
void func_80025540(s32);
void func_800256F4(s32, s32, s32);
void func_80026E4C(s32);

#endif // _6BC0_H_
