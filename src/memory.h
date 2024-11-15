#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <ultra64.h>
#include <macros.h>

#define MEMORY_POOL_LEFT  0
#define MEMORY_POOL_RIGHT 1

struct MainPoolBlock;

typedef void (*AllocateFunc)(struct MainPoolBlock*, u32);

typedef struct MainPoolBlock {
    /* 0x00 */ struct MainPoolBlock *prev;
    /* 0x04 */ struct MainPoolBlock *next;
    /* 0x08 */ AllocateFunc func;
    /* 0x0C */ s32 arg; // passed into func as the 2nd argument.
} MainPoolBlock; // size = 0x10

// structs for the main pool.
typedef struct MainPoolState {
    /* 0x00 */ s32 freeSpace;
    /* 0x04 */ MainPoolBlock *listHeadL;
    /* 0x08 */ MainPoolBlock *listHeadR;
    /* 0x0C */ struct MainPoolState *prev;
} MainPoolState;

typedef struct MainPool {
    /* 0x00 */ OSMesg msgs[1];
    /* 0x04 */ OSMesgQueue queue;
    /* 0x1C */ size_t available;
    /* 0x20 */ MainPoolBlock *start;
    /* 0x24 */ MainPoolBlock *end;
    /* 0x28 */ MainPoolBlock *listHeadL;
    /* 0x2C */ MainPoolBlock *listHeadR;
    /* 0x30 */ struct MainPoolState *mainState;
} MainPool;

// structs used for the smaller pools allocated from the global pool.
typedef struct MemoryBlock {
    /* 0x00 */ struct MemoryBlock *next;
    /* 0x04 */ u32 size;
} MemoryBlock;

typedef struct MemoryPool {
    /* 0x00 */ OSMesg msgs[1];
    /* 0x04 */ OSMesgQueue queue;
    /* 0x1C */ size_t available;
    /* 0x20 */ struct MemoryBlock *firstBlock;
    /* 0x24 */ struct MemoryBlock freeList;
} MemoryPool;

// memory_main.c
void main_pool_init(void *start, void *end);
void *main_pool_alloc_from_pool(u32 size, u32 side);
u32 main_pool_free(void *addr, u32 runBlockFunc);
void *main_pool_alloc_with_func(u32 size, s32 side, s32 arg, AllocateFunc func);
void *main_pool_alloc(u32 size, s32 side);
u32 main_pool_try_free(void *addr);
void *main_pool_realloc(void *addr, size_t size);
u32 main_pool_get_available(void);
u32 main_pool_push_state(u32 arg);
u32 main_pool_pop_state(u32 arg);
void *main_pool_search(uintptr_t addr, s32 *argPtr);
void main_pool_set_func(void *block, s32 arg, AllocateFunc func);
size_t main_pool_get_block_dist(MainPoolBlock *block);
MainPool*main_pool_get_pool(void);

// memory.c
MemoryPool *mem_pool_try_init(u32 size, s32 side);
MainPool* mem_pool_init(MainPool* pool, s32 size);
void *mem_pool_alloc(MainPool* node, s32 size);

void mem_pool_free(MemoryPool* pool, void* addr);
void *func_80002D10(u32 size, s32 side);
void func_80002D60(struct MemoryBlock* block);
void* func_80002DA4(struct MainPoolState* block, s32 size);
void* func_80002DCC(struct MainPoolState* state, s32 arg1, s32 arg2);
void func_80002E3C(struct MainPoolState* state, s32 size);
void func_80002E64(struct MainPoolState* state);

#endif /* _MEMORY_H_ */
