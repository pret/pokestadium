#ifndef _18480_H_
#define _18480_H_

#include "global.h"
#include "src/memory.h"
#include "src/11BA0.h"

#define GEO_CMD_FLAGS_RESET 0
#define GEO_CMD_FLAGS_SET   1
#define GEO_CMD_FLAGS_CLEAR 2

#define CMD_SIZE_SHIFT (sizeof(void *) >> 3)
#define CMD_PROCESS_OFFSET(offset) (((offset) & 3) | (((offset) & ~3) << CMD_SIZE_SHIFT))

#define cur_geo_cmd_u8(offset) \
    (gGeoLayoutCommand[CMD_PROCESS_OFFSET(offset)])

#define cur_geo_cmd_s16(offset) \
    (*(s16 *) &gGeoLayoutCommand[CMD_PROCESS_OFFSET(offset)])

#define cur_geo_cmd_s32(offset) \
    (*(s32 *) &gGeoLayoutCommand[CMD_PROCESS_OFFSET(offset)])

#define cur_geo_cmd_u32(offset) \
    (*(u32 *) &gGeoLayoutCommand[CMD_PROCESS_OFFSET(offset)])

#define cur_geo_cmd_ptr(offset) \
    (*(void **) &gGeoLayoutCommand[CMD_PROCESS_OFFSET(offset)])

typedef void (*GeoLayoutCommandProc)(void);

typedef struct unk_D_800ABE00_cmd0 {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u8* unk_04;
} unk_D_800ABE00_cmd0; // size = 0x8

typedef struct unk_D_800ABE00_cmd1 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd1; // size = 0x4

typedef struct unk_D_800ABE00_cmd2 {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ u8* unk_04;
} unk_D_800ABE00_cmd2; // size = 0x8

typedef struct unk_D_800ABE00_cmd3 {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ u8* unk_04;
} unk_D_800ABE00_cmd3; // size = 0x8

typedef struct unk_D_800ABE00_cmd4 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd4; // size = 0x4

typedef struct unk_D_800ABE00_cmd5 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd5; // size = 0x4

typedef struct unk_D_800ABE00_cmd6 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd6; // size = 0x4

typedef struct unk_D_800ABE00_cmd7 {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ unk_D_8690A610* unk_04;
} unk_D_800ABE00_cmd7; // size = 0x8

typedef struct unk_D_800ABE00_cmd8 {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ func_D_86002F34_000_010 unk_04;
    /* 0x08 */ unk_D_86002F34_000_014* unk_08;
} unk_D_800ABE00_cmd8; // size = 0xC

typedef struct unk_D_800ABE00_cmd9 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd9; // size = 0x4

typedef struct unk_D_800ABE00_cmdA {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ struct GraphNode* unk_04;
} unk_D_800ABE00_cmdA; // size = 0x8

typedef struct unk_D_800ABE00_cmdB {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ Vec3s unk_0C;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
} unk_D_800ABE00_cmdB; // size = 0x18

typedef struct unk_D_800ABE00_cmdC {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmdC; // size = 0x4

typedef struct unk_D_800ABE00_cmdD {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmdD; // size = 0x4

typedef struct unk_D_800ABE00_cmdE {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmdE; // size = 0x4

typedef struct unk_D_800ABE00_cmdF {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmdF; // size = 0x4

typedef struct unk_D_800ABE00_cmd10 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
} unk_D_800ABE00_cmd10; // size = 0x4

typedef struct unk_D_800ABE00_cmd11 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd11; // size = 0x4

typedef struct unk_D_800ABE00_cmd12 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd12; // size = 0x4

typedef struct unk_D_800ABE00_cmd13 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 r;
    /* 0x02 */ u8 g;
    /* 0x03 */ u8 b;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} unk_D_800ABE00_cmd13; // size = 0x8

typedef struct unk_D_800ABE00_cmd14 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[0x3];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 r;
    /* 0x09 */ u8 g;
    /* 0x0A */ u8 b;
    /* 0x0B */ u8 a;
} unk_D_800ABE00_cmd14; // size = 0xC

typedef struct unk_D_800ABE00_cmd15 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[0xB];
} unk_D_800ABE00_cmd15; // size = 0xC

typedef struct unk_D_800ABE00_cmd16 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 r;
    /* 0x02 */ u8 g;
    /* 0x03 */ u8 b;
} unk_D_800ABE00_cmd16; // size = 0x4

typedef struct unk_D_800ABE00_cmd17 {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ unk_D_86002F34_018* unk_08;
    /* 0x0C */ unk_D_86002F34_01C* unk_0C;
    /* 0x10 */ Vtx* unk_10;
} unk_D_800ABE00_cmd17; // size = 0x14

typedef struct unk_D_800ABE00_cmd18 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} unk_D_800ABE00_cmd18; // size = 0x8

typedef struct unk_D_800ABE00_cmd19 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[0x3];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} unk_D_800ABE00_cmd19; // size = 0x8

typedef struct unk_D_800ABE00_cmd1A {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmd1A; // size = 0x4

typedef struct unk_D_800ABE00_cmd1B {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[0x3];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ Vec3s unk_0A;
} unk_D_800ABE00_cmd1B; // size = 0x10

typedef struct unk_D_800ABE00_cmd1C {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[0x3];
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ u32 unk_0C;
} unk_D_800ABE00_cmd1C; // size = 0x10

typedef struct unk_D_800ABE00_cmd1D {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ Vec3s unk_04;
    /* 0x0A */ Vec3s unk_0A;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ u32 unk_18;
} unk_D_800ABE00_cmd1D; // size = 0x1C

typedef struct unk_D_800ABE00_cmd1E {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ Gfx* unk_04;
} unk_D_800ABE00_cmd1E; // size = 0x8

typedef struct unk_D_800ABE00_cmd1F {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ Vec3s unk_0A;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ char pad[0x2];
} unk_D_800ABE00_cmd1F; // size = 0x18

typedef struct unk_D_800ABE00_cmd20 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ Vec3s unk_0A;
    /* 0x10 */ Gfx* unk_10;
} unk_D_800ABE00_cmd20; // size = 0x14

typedef struct unk_D_800ABE00_cmd21 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ Vec3s unk_02;
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ Gfx* unk_0C;
} unk_D_800ABE00_cmd21; // size = 0x10

typedef struct unk_D_800ABE00_cmd22 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x04 */ Gfx* unk_04;
} unk_D_800ABE00_cmd22; // size = 0x8

typedef struct unk_D_800ABE00_cmd23 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ Gfx* unk_04;
    /* 0x07 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ u8 r;
    /* 0x0D */ u8 g;
    /* 0x0E */ u8 b;
    /* 0x0F */ u8 a;
} unk_D_800ABE00_cmd23; // size = 0x10

typedef struct unk_D_800ABE00_cmd24 {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
} unk_D_800ABE00_cmd24; // size = 0x4

typedef struct unk_D_800ABE00_cmd25 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
} unk_D_800ABE00_cmd25; // size = 0x4

typedef struct unk_D_800ABE00_cmd26 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8 r;
    /* 0x11 */ u8 g;
    /* 0x12 */ u8 b;
    /* 0x13 */ u8 a;
} unk_D_800ABE00_cmd26; // size = 0x14

void geo_layout_cmd_branch_and_link(void); // cmd  0
void geo_layout_cmd_end(void); // cmd  1
void geo_layout_cmd_jump(void); // cmd  2
void geo_layout_cmd_branch(void); // cmd  3
void geo_layout_cmd_return(void); // cmd  4
void geo_layout_cmd_open_node(void); // cmd  5
void geo_layout_cmd_close_node(void); // cmd  6
void func_80017B28(void); // cmd  7
void func_80017B60(void); // cmd  8
void func_80017BBC(void); // cmd  9
void func_80017BFC(void); // cmd 10
void func_80017C48(void); // cmd 11
void func_80017D94(void); // cmd 12
void func_80017DE0(void); // cmd 13
void func_80017E2C(void); // cmd 14
void func_80017E78(void); // cmd 15
void func_80017EC4(void); // cmd 16
void func_80017F1C(void); // cmd 17
void func_80017F5C(void); // cmd 18
void func_80017F64(void); // cmd 19
void func_80017FD4(void); // cmd 20
void func_800180BC(void); // cmd 21
void func_800180D4(void); // cmd 22
void func_8001812C(void); // cmd 23
void func_8001819C(void); // cmd 24
void func_800181FC(void); // cmd 25
void func_8001824C(void); // cmd 26
void func_8001829C(void); // cmd 27
void func_800183C4(void); // cmd 28
void func_80018490(void); // cmd 29
void func_800185A8(void); // cmd 30
void func_80018600(void); // cmd 31
void func_8001878C(void); // cmd 32
void func_800188C8(void); // cmd 33
void func_80018968(void); // cmd 34
void func_800189B8(void); // cmd 35
void func_80018A40(void); // cmd 36
void func_80018A8C(void); // cmd 37
void func_80018AD0(void); // cmd 38
struct GraphNode* process_geo_layout(MemoryBlock*, void*);

#endif // _18480_H_
