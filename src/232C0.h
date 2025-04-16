#ifndef _232C0_H_
#define _232C0_H_

#include "global.h"
#include "memory.h"
#include "29BA0.h"
#include "2D340.h"
#include "22630.h"

typedef enum {
    POKEMON_ROM_NONE = 0,
    POKEMON_ROM_RED = 1,
    POKEMON_ROM_GREEN = 2,
    POKEMON_ROM_BLUE = 3,
    POKEMON_ROM_YELLOW = 7,
} PokemonRomType;

typedef struct func_800253F4_arg1 {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001;
    /* 0x002 */ u16 unk_002;
    /* 0x004 */ char unk_004[11];
    /* 0x00F */ unk_D_800AC910_050_9AC unk_00F;
} func_800253F4_arg1; // size >= 0x1A3

typedef struct unk_func_800228F0 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ char unk_04[16];
    /* 0x14 */ char unk_14[16];
} unk_func_800228F0; // size >= 0x28

u16 func_800226C0(s32 arg0, u32 arg1);
void func_80022734(unk_func_80026268_arg0* arg0);
void func_800228B0(unk_func_80026268_arg0* arg0);
s32 func_800228F0(unk_func_800228F0*, u16);
void func_80022978(unk_func_80026268_arg0* arg0, s16 arg1, u8 arg2);
s32 func_80022A04(u16* arg0, unk_D_800AC910_040* arg1);
u8 func_80022A28(s32 arg0);
u8 func_80022A38(s32 arg0);
s32 func_80022A60(s32 arg0);
u8 func_80022A88(s32 arg0);
u8 func_80022A98(s32 arg0);
s32 func_80022AA8(s32 arg0);
s32 func_80022ACC(s32 arg0);
void func_80022AF0(unk_func_80022C28_ret* arg0);
void func_80022B88(unk_func_80022C28_ret* arg0);
unk_func_80022C28_ret* func_80022C28(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
unk_func_80022C28_ret* func_80022CC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, char* arg4, u16 arg5);
s32 func_80022D24(unk_func_80022C28_ret* arg0);
s32 func_80022D8C(unk_func_80022C28_ret* arg0);
s32 func_80022DF4(unk_func_80022C28_ret*, u8);
s32 func_80022E18(u8* arg0, s32 arg1, unk_func_80022C28_ret* arg2);
s32 func_80022F24(u8* arg0, s32 arg1, unk_func_80022C28_ret* arg2);
void func_80023068(void);
char* func_8002311C(s32 arg0);
s32 func_80023130(u8* arg0);
s32 func_80023230(u8* arg0, u8* arg1);
void func_800232A0(u8* arg0, u8* arg1);
s32 func_800232D0(u8* arg0, s32 arg1);
s8 func_80023324(s32 arg0);
s32 func_800233F4(s32 arg0);
s32 func_80023480(s32 arg0);
s32 func_80023658(s32 arg0);
s32 func_80023740(s32 arg0, s32 arg1);
s32 func_800237C8(s32 arg0, s32 arg1);
void func_800238D8(UNUSED MainPoolBlock* arg0, u32 arg1);
void func_80023990(s32 arg0);
s32 func_80023A04(s32 arg0);
s32 func_80023AF8(s32 arg0);
s32 func_80023B7C(s32 arg0);
s32 func_80023D60(s32 arg0);
s32 func_80023E34(s32 arg0);
void func_80023F78(s32 arg0);
void func_80024040(s32 arg0);
s32 func_800240A0(void);
void func_80024208(s32 arg0);
s32 func_80024270(s32 arg0);
s32 func_8002431C(s32 arg0);
s32 func_800243D8(s32 arg0);
void func_8002447C(s32 arg0);
void func_800244F4(s32 arg0);
unk_D_800AC910_050_B40_000* func_80024528(s32 arg0, s32 arg1);
void func_80024624(unk_func_80026268_arg0* arg0, s32 arg1, s32 arg2);
void func_800246F8(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2);
void func_800247C4(unk_func_80026268_arg0* arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80024884(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_80024948(s32 arg0, s32 arg1);
void func_80024978(s32 arg0, s32 arg1, s32 arg2);
s32 func_800249B0(s32 arg0);
s32 func_800249FC(s32 arg0);
s32 func_80024A48(s32 arg0, s32 arg1, s32 arg2);
void func_80024AE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80024BC4(s32 arg0, s32 arg1, s32 arg2);
s32 func_80024CB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_80026268_arg0* arg4);
s32 func_80024DAC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_88205880_00D0* arg4);
s32 func_80024EF4(void);
s32 func_80024F00(s32 arg0);
s32 func_80024F24(s32 arg0);
s32 func_80024F68(s32 arg0);
s32 func_80024F8C(s32 arg0);
s32 func_80024FB0(s32 arg0);
void func_80025040(s32 arg0, unk_D_800AC910_040* arg1);
s32 func_80025084(s32 arg0);
void func_800250E0(s32 arg0, u16 arg1);
s32 func_8002513C(s32 arg0);
char* func_800251B0(s32 arg0, char* arg1);
char* func_80025210(s32 arg0, char* arg1);
char* func_8002526C(s32 arg0, char* arg1);
char* func_800252CC(s32 arg0, char* arg1);
s32 func_80025328(s32 arg0);
s32 func_80025370(s32 arg0);
s32 func_8002539C(s32 arg0);
s32 func_800253C8(s32 arg0);
s32 func_800253F4(s32 arg0, func_800253F4_arg1* arg1);
void func_80025498(char* arg0, s32 arg1, u8* arg2);
void func_80025540(s32 arg0);
s32 func_8002564C(s32 arg0, s32 arg1);
void func_800256F4(s32 arg0, s32 arg1, s32 arg2);
s32 func_80025840(s32 arg0);
s32 func_80025988(s32 arg0);
s32 func_80025AD0(s32 arg0);

#endif // _232C0_H_
