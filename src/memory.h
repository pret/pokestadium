#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <PR/ultratypes.h>
#include <PR/os.h>
#include <macros.h>

#define MEMORY_POOL_LEFT  0
#define MEMORY_POOL_RIGHT 1

struct MainPoolState {
    /* 0x00 */ u32 freeSpace;
    /* 0x04 */ struct MainPoolBlock *listHeadL;
    /* 0x08 */ struct MainPoolBlock *listHeadR;
    /* 0x0C */ struct MainPoolState *prev;
};

struct MainPoolBlock {
    /* 0x00 */ struct MainPoolBlock *prev;
    /* 0x04 */ struct MainPoolBlock *next;
    /* 0x08 */ void (*func)(struct MainPoolBlock *block, s32 arg);
    /* 0x0C */ s32 arg; // passed into func as the 2nd argument.
};

struct MainPool {
    /* 0x00 */ OSMesg msgs[1];
    /* 0x04 */ OSMesgQueue queue;
    /* 0x1C */ size_t available;
    /* 0x20 */ struct MainPoolBlock *start;
    /* 0x24 */ struct MainPoolBlock *end;
    /* 0x28 */ struct MainPoolBlock *listHeadL;
    /* 0x2C */ struct MainPoolBlock *listHeadR;
    /* 0x30 */ struct MainPoolState *mainState;
};

// functions
void main_pool_init(void *start, void *end);
struct MainPoolBlock *main_pool_alloc(u32 size, u32 side);
u32 main_pool_free(void *addr, u32 runBlockFunc);
struct MainPoolBlock *main_pool_alloc_node(u32 size, s32 side, s32 arg, void *func);
struct MainPoolBlock *main_pool_alloc_node_no_func(u32 size, s32 side);
u32 main_pool_try_free(struct MainPoolBlock *addr);
struct MainPoolBlock *main_pool_realloc(void *addr, size_t size);
u32 main_pool_get_available(void);
u32 main_pool_push_state(u32 arg);
u32 main_pool_pop_state(u32 arg);
void *main_pool_search(uintptr_t addr, s32 *argPtr);
void main_pool_set_func(void *block, s32 arg, void *func);
uintptr_t main_pool_get_block_dist(struct MainPoolBlock *block);
struct MainPool *main_pool_get_pool(void);

#endif /* _MEMORY_H_ */
