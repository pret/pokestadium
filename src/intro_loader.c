#include <ultra64.h>
#include <macros.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunknown-pragmas"

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
    // these pointers are all probably to a 4 member struct?
    /* 0x20 */ struct UnkNodeThing *unk20;
    /* 0x24 */ struct UnkNodeThing *unk24;
    /* 0x28 */ struct UnkNodeThing *unk28;
    /* 0x2C */ struct UnkNodeThing *unk2C;
    /* 0x30 */ struct UnkNodeThing *unk30;
}; // sizeof >= 0x34

extern struct Unk800A6070 D_800A6070;
// D_800A6074 is 0x04 queue;
// D_800A608C is field 0x1C of above;


void func_800022C0(void *arg0, void *arg1) {
    D_800A6070.unk20 = (void *)(ALIGN16((uintptr_t)arg0) + 0x10);
    D_800A6070.unk24 = (void *)(((uintptr_t)arg1 & ~0xF) - 0x10);
    D_800A6070.unk1C = (uintptr_t)D_800A6070.unk24 - (uintptr_t)D_800A6070.unk20;
    D_800A6070.unk30 = NULL;

    D_800A6070.unk28 = D_800A6070.unk20 - 1;
    D_800A6070.unk28->unk00 = NULL;
    D_800A6070.unk28->unk04 = NULL;
    D_800A6070.unk28->unk08 = NULL;
    D_800A6070.unk28->unk0C = 0;

    D_800A6070.unk2C = D_800A6070.unk24;
    D_800A6070.unk2C->unk00 = NULL;
    D_800A6070.unk2C->unk04 = NULL;
    D_800A6070.unk28->unk08 = NULL;
    D_800A6070.unk28->unk0C = 0;

    osCreateMesgQueue(&D_800A6070.queue, D_800A6070.msgs, ARRAY_COUNT(D_800A6070.msgs));
    osSendMesg(&D_800A6070.queue, NULL, OS_MESG_NOBLOCK);
}

struct UnkNodeThing *func_80002380(u32 arg0, s32 arg1) {
    struct UnkNodeThing *node;
    struct UnkNodeThing *ret;

    arg0 = ALIGN16(arg0) + sizeof(struct UnkNodeThing);
    ret = NULL;
    if ((arg0 != 0) && (D_800A6070.unk1C >= (uintptr_t)arg0)) {
        if (arg1 == 0) {
            D_800A6070.unk1C -= (uintptr_t)arg0;
            node = (void *)((uintptr_t)D_800A6070.unk28 + (uintptr_t)arg0);
            D_800A6070.unk28->unk04 = node;
            node->unk00 = D_800A6070.unk28;
            node->unk04 = NULL;
            node->unk08 = 0;
            node->unk0C = 0;
            ret = D_800A6070.unk28;
            D_800A6070.unk28 = node;
            ret =  ret + 1;
        } else if (arg1 == 1) {
            D_800A6070.unk1C -= (uintptr_t)arg0;
            node = (void *)((uintptr_t)D_800A6070.unk2C - (uintptr_t)arg0);
            D_800A6070.unk2C->unk00 = node;
            node->unk04 = D_800A6070.unk2C;
            node->unk00 = NULL;
            node->unk08 = 0;
            node->unk0C = 0;
            D_800A6070.unk2C = node;
            ret = node + 1;
        }
    }
    return ret;
}

uintptr_t func_80002764(void);
uintptr_t func_80002430(struct UnkNodeThing *arg0, s32 arg1);

#ifdef NON_MATCHING
uintptr_t func_80002430(struct UnkNodeThing *arg0, s32 arg1) {
    // struct UnkNodeThing *node;
    struct UnkNodeThing *otherNode;
    struct UnkNodeThing *prev;
    uintptr_t priorAddr;

    priorAddr = (uintptr_t)(arg0 - 1); // v1

    if (priorAddr < (uintptr_t)D_800A6070.unk28) {
        do {
            prev = D_800A6070.unk28->unk00; // t6
            D_800A6070.unk28 = prev;
            if (arg1) {
                if (prev->unk08 != NULL) {
                    prev->unk08(prev + 1, prev->unk0C);
                }
            }
            D_800A6070.unk1C = D_800A6070.unk1C + (uintptr_t)D_800A6070.unk28->unk04 - (uintptr_t)D_800A6070.unk28;
            D_800A6070.unk28->unk04 = NULL;
        } while (priorAddr != (uintptr_t)D_800A6070.unk28);
    } else {
        otherNode = D_800A6070.unk2C;
        if (priorAddr >= (uintptr_t)otherNode && priorAddr >= (uintptr_t)otherNode) {
            do {
                if (arg1) {
                    if (otherNode->unk08 != NULL) {
                        otherNode->unk08(otherNode + 1, otherNode->unk0C);
                        otherNode = D_800A6070.unk2C;
                    }
                }
                prev = otherNode->unk04;
                D_800A6070.unk2C = prev;
                D_800A6070.unk1C = D_800A6070.unk1C + (uintptr_t)prev - (uintptr_t)prev->unk00;
                prev->unk00 = NULL;
                otherNode = D_800A6070.unk2C;
            } while (priorAddr >= (uintptr_t)otherNode);
        }
    }

    return func_80002764();
}

#else
#pragma GLOBAL_ASM("src/nonmatchings/intro_loader/func_80002430.s")
#endif

void func_80002A14(struct UnkNodeThing *, s32, void *);

struct UnkNodeThing *func_8000254C(u32 arg0, s32 arg1, s32 arg2, void *arg3) {
    struct UnkNodeThing *node;

    osRecvMesg(&D_800A6070.queue, NULL, OS_MESG_BLOCK);
    node = func_80002380(arg0, arg1);
    if (node != NULL) {
        func_80002A14(node, arg2, arg3);
    }
    osSendMesg(&D_800A6070.queue, NULL, OS_MESG_NOBLOCK);
    
    return node;
}

struct UnkNodeThing *func_800025C4(u32 arg0, s32 arg1) {
    struct UnkNodeThing *node;

    osRecvMesg(&D_800A6070.queue, NULL, OS_MESG_BLOCK);
    node = func_80002380(arg0, arg1);
    osSendMesg(&D_800A6070.queue, NULL, OS_MESG_NOBLOCK);
    return node;
}

void func_80002620(struct UnkNodeThing *arg0) {
    if (arg0 != NULL) {
        osRecvMesg(&D_800A6070.queue, NULL, OS_MESG_BLOCK);
        func_80002430(arg0, 1);
        osSendMesg(&D_800A6070.queue, NULL, OS_MESG_NOBLOCK);
    }
    func_80002764();
}

struct UnkNodeThing *func_80002680(struct UnkNodeThing *arg0, uintptr_t arg1);
#ifdef NON_MATCHING
struct UnkNodeThing *func_80002680(struct UnkNodeThing *arg0, uintptr_t arg1) {
    uintptr_t diff;
    struct UnkNodeThing *sp28;
    struct UnkNodeThing *prior;
    struct UnkNodeThing *priorPrev;
    s32 sp20;
    void *sp1C;


    sp28 = NULL;
    osRecvMesg(&D_800A6070.queue, NULL, OS_MESG_BLOCK);
    // temp_v1 = arg0 - 0x10;
    prior = arg0 - 1;
    // temp_a0 = temp_v1->unk4;
    priorPrev = prior->unk04;
    // temp_v0 = temp_a0 - arg0;
    diff = (uintptr_t)priorPrev - (uintptr_t)arg0;

    if (D_800A6070.unk28 == priorPrev) {
        // uintptr_t aligned;

        // temp_a3 = (arg1 + 0xF) & ~0xF;
        // aligned = ALIGN16(arg1);
        arg1 = ALIGN16(arg1);
        // if (temp_v0 < temp_a3) {
        if (diff >= arg1 || D_800A6070.unk1C >= (arg1 - diff)) {
            sp20 = prior->unk0C;
            sp1C = prior->unk08;
            func_80002430(arg0, 0);
            sp28 = func_80002380(arg1, 0);
            func_80002A14(sp28, sp20, sp1C);
        }
    }
    osSendMesg(&D_800A6070.queue, NULL, OS_MESG_NOBLOCK);
    return sp28;
}
#else
#pragma GLOBAL_ASM("src/nonmatchings/intro_loader/func_80002680.s")
#endif

// this is a weird type, so maybe it should be cast into UnkNodeThing?
uintptr_t func_80002764(void) {
    s32 val = (s32)D_800A6070.unk1C - sizeof(struct UnkNodeThing);

    if (val < 0) {
        val = 0;
    }

    return val;
}

void func_80002784(s32 arg0) {
    struct UnkNodeThing *node;
    struct UnkNodeThing *sp20; // prev?
    struct UnkNodeThing *sp1C; // data?
    uintptr_t sp18; // next? 

    osRecvMesg(&D_800A6070.queue, NULL, OS_MESG_BLOCK);
    sp18 = D_800A6070.unk1C;
    sp20 = D_800A6070.unk28;
    sp1C = D_800A6070.unk2C;
    node = func_80002380(0x10, 0);
    if (node != NULL) {
        (node-1)->unk0C = arg0;
        node->unk0C = (uintptr_t)D_800A6070.unk30;
        node->unk00 = (struct UnkNodeThing *) sp18;
        node->unk04 = sp20;
        node->unk08 = (void *) sp1C;
        D_800A6070.unk30 = node;
    }
    osSendMesg(&D_800A6070.queue, NULL, OS_MESG_NOBLOCK);
    func_80002764();
}

void func_80002838(struct UnkNodeThing *arg0) {
    struct UnkNodeThing *node;
    struct UnkNodeThing *s0;
    void *s2, *s3;

    s0 = arg0;
    osRecvMesg(&D_800A6070.queue, NULL, OS_MESG_BLOCK);
    while (TRUE) {
        node = D_800A6070.unk30;
        s2 = node->unk04;
        s3 = node->unk08;
        D_800A6070.unk1C = (uintptr_t)node->unk00;
        D_800A6070.unk30 = INT2VOID(node->unk0C);

        if (s0 == NULL) { break; }
        // odd non-matching, but it works
        node = node - 1;
        if ((uintptr_t)s0 == (uintptr_t)node->unk0C) { break; }
        if (D_800A6070.unk30 == NULL) { break; }
    }

    s0 = D_800A6070.unk2C;
    while ((uintptr_t)s3 > (uintptr_t)s0) {
        if (s0->unk08 != NULL) {
            s0->unk08(s0 + 1, s0->unk0C);
        }
        s0 = s0->unk04;
    }

    s0 = D_800A6070.unk28->unk00;
    while ((uintptr_t)s2 <= (uintptr_t)s0) {
        if (s0->unk08 != NULL) {
            s0->unk08(s0 + 1, s0->unk0C);
        }
        s0 = s0->unk00;
    }

    D_800A6070.unk28 = s2;
    D_800A6070.unk2C = s3;
    osSendMesg(&D_800A6070.queue, NULL, OS_MESG_NOBLOCK);
    func_80002764();
}

#ifdef MIPS_TO_C
struct UnkNodeThing *func_80002960(uintptr_t arg0, s32 *arg1) {
    struct UnkNodeThing *node; // v0?
    struct UnkNodeThing *otherNode;

    node = D_800A6070.unk28->unk00;
    while (node != NULL) {
        otherNode = node->unk04;
        if (arg0 >= (uintptr_t)(node + 1) && arg0 < (uintptr_t)otherNode) {
            if (arg1 != NULL) {
                *arg1 = node->unk0C;
            }
            return (node + 1);
        }
        node = node->unk00;
    }
    // L800029B8
    node = D_800A6070.unk2C;
    otherNode = node->unk04;
    while (otherNode != NULL) {
        if (arg0 >= (uintptr_t)(node + 1) && arg0 < (uintptr_t)otherNode) {
            if (arg1 != NULL) {
                *arg1 = node->unk0C;
            }
            return node + 1;
        }
        node = otherNode;
        otherNode = otherNode->unk04;
    }
    // L80002A08
    return NULL;
}
#else
#pragma GLOBAL_ASM("src/nonmatchings/intro_loader/func_80002960.s")
#endif

void func_80002A14(struct UnkNodeThing *arg0, s32 arg1, void *arg2) {
    struct UnkNodeThing *node = INT2VOID((uintptr_t)arg0 - sizeof(struct UnkNodeThing));
    node->unk08 = arg2;
    node->unk0C = arg1;
}

uintptr_t func_80002A24(struct UnkNodeThing *arg0) {
    struct UnkNodeThing *prior = arg0 - 1;

    return (uintptr_t)prior->unk04 - (uintptr_t)arg0;
}

struct Unk800A6070 *func_80002A30(void) {
    return &D_800A6070;
}

#pragma GCC diagnostic pop
