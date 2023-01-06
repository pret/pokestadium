#ifndef _SRC_INTRO_LOADER_H_
#define _SRC_INTRO_LOADER_H_

#include <PR/ultratypes.h>
#include <PR/os.h>
#include <macros.h>

struct UnkNodeThing {
    /* 0x00 */ struct UnkNodeThing *unk00;
    /* 0x04 */ struct UnkNodeThing *unk04;
    // this looks like it can be any type of pointer? 
    // or are there multiple list node types in a union?
    /* 0x08 */ void (*unk08)(struct UnkNodeThing *, s32);
    /* 0x0C */ s32 unk0C;
}; // sizeof == 0x10

// "known" types for +08 and +0C:
// fn pointer
//  void (*unk08)(struct UnkNodeThing *, s32
//  s32 unk0C
// more nodes
//  struct UnkNodeThing *unk08
//  struct UnkNodeThing *unk0C

struct Unk800A6070 {
    /* 0x00 */ OSMesg msgs[1];
    /* 0x04 */ OSMesgQueue queue;
    /* 0x1C */ uintptr_t unk1C;
    // these pointers might be to different variants of this struct
    // or, they could be to different lists...
    /* 0x20 */ struct UnkNodeThing *unk20;
    /* 0x24 */ struct UnkNodeThing *unk24;
    /* 0x28 */ struct UnkNodeThing *unk28;
    /* 0x2C */ struct UnkNodeThing *unk2C;
    /* 0x30 */ struct UnkNodeThing *unk30;
}; // sizeof >= 0x34

// functions
void func_800022C0(void *arg0, void *arg1);
struct UnkNodeThing *func_8000254C(u32 arg0, s32 arg1, s32 arg2, void *arg3);
struct UnkNodeThing *func_800025C4(u32 arg0, s32 arg1);
void func_80002620(struct UnkNodeThing *arg0);
struct UnkNodeThing *func_80002680(struct UnkNodeThing *arg0, uintptr_t arg1);
uintptr_t func_80002764(void);
void func_80002784(s32 arg0);
void func_80002838(struct UnkNodeThing *arg0);
void func_80002A14(struct UnkNodeThing *, s32, void *);
uintptr_t func_80002A24(struct UnkNodeThing *arg0);
struct Unk800A6070 *func_80002A30(void);

#endif /* _SRC_INTRO_LOADER_H_ */
