#include <ultra64.h>
#include "memory.h"

// seems to allocate a pool area, and init it's MainPool struct?
// the other file is memory_main.c but this one is memory.c?

/**
 * Allocate a memory pool from the main pool. This pool supports arbitrary
 * order for allocation/freeing.
 * Return NULL if there is not enough space in the main pool.
 */
struct MemoryPool* mem_pool_try_init(u32 size, s32 side) {
    struct MainPoolBlock* block;
    struct MemoryPool* ret;

    size = ALIGN4(size);
    block = main_pool_alloc(size, side);
    if (block != NULL) {
        ret = mem_pool_init(block, size);
    }
    return ret; //! UB: Uninitialized return if the earlier call is not done.
}

/**
 * Perform the actual mem pool init. This is called by the earlier function.
 * In earlier EAD titles, this was part of mem_pool_try_init.
 */
// TODO: This function is strange, it cant be using MemoryPool, as it allocates
// more variables than the MemoryPool struct, and it doesnt line up. Whats going
// on with these structs?
struct MainPool* mem_pool_init(struct MainPool* pool, s32 size) {
    s32 aligned_size =
        ALIGN4(size - 3) - 0x28; // whats the deal with 0x28? this size doesnt match any known pool struct.
    void* listHeadL = &pool->listHeadL;

    pool->available = aligned_size;
    pool->start = listHeadL;
    pool->end = listHeadL;
    pool->listHeadL = NULL;
    pool->listHeadR = aligned_size;
    osCreateMesgQueue(&pool->queue, &pool->msgs[0], 1);
    osSendMesg(&pool->queue, NULL, 0);
    return pool;
}

/**
 * Allocate from a memory pool. Return NULL if there is not enough space.
 */
void* mem_pool_alloc(struct MainPool* node, s32 size) {
    struct MemoryBlock* freeBlock;
    void* addr;

    osRecvMesg(&node->queue, 0, 1);

    addr = NULL;
    size = ALIGN4(size) + sizeof(struct MemoryBlock);
    freeBlock = (struct MemoryBlock*)&node->end;

    while (freeBlock->next != NULL) {
        if (freeBlock->next->size >= size) {
            addr = (u8*)freeBlock->next + sizeof(struct MemoryBlock); // get data after header
            if (freeBlock->next->size - size <= sizeof(struct MemoryBlock)) {
                freeBlock->next = freeBlock->next->next;
            } else {
                struct MemoryBlock* newBlock = (struct MemoryBlock*)((u8*)freeBlock->next + size);
                newBlock->size = freeBlock->next->size - size; // set size
                newBlock->next = freeBlock->next->next;
                freeBlock->next->size = size; // set size
                freeBlock->next = newBlock;
            }
            break;
        }
        freeBlock = freeBlock->next;
    }
    osSendMesg(&node->queue, 0, 0);
    return addr;
}

/**
 * Free a block that was allocated using mem_pool_alloc.
 */
void mem_pool_free(struct MemoryPool* pool, void* addr) {
    struct MemoryBlock* block;
    struct MemoryBlock* freeList;

    if (addr != NULL) {
        osRecvMesg(&pool->queue, NULL, 1);
        block = (struct MemoryBlock*)((u8*)addr - sizeof(struct MemoryBlock));
        freeList = pool->freeList.next;
        if (pool->freeList.next == NULL) {
            pool->freeList.next = block;
            block->next = NULL;
        } else if (block < pool->freeList.next) {
            if ((u32)pool->freeList.next == ((u32)block + (u32)block->size)) {
                block->size += ((u32)freeList->size);
                block->next = freeList->next;
                pool->freeList.next = block;
            } else {
                block->next = pool->freeList.next;
                pool->freeList.next = block;
            }
        } else {
            while (freeList->next != NULL) {
                if (freeList < block && block < freeList->next) {
                    break;
                }
                freeList = freeList->next;
            }
            if (((u32)freeList + (u32)freeList->size) == (u32)block) {
                freeList->size += block->size;
                block = freeList;
            } else {
                block->next = freeList->next;
                freeList->next = block;
            }
            if (block->next != NULL && (u32)block->next == ((u32)block + (u32)block->size)) {
                block->size = (u32)block->size + (u32)block->next->size;
                block->next = block->next->next;
            }
        }
        osSendMesg(&pool->queue, NULL, 0);
    }
}

void* func_80002D10(u32 size, s32 side) {
    struct MainPoolBlock* block;
    void* ptr = NULL;

    size = ALIGN4(size);
    ptr = 0;
    block = main_pool_alloc(size, side);
    if (block != NULL) {
        ptr = func_80002DA4(block, size);
    }
    return ptr;
}

void func_80002D60(struct MemoryBlock* block) {
    s32 size = ALIGN16(block->size + 0x10);

    main_pool_realloc(block, size);
    block->next = (void*)(size - 0x10);
}

void* func_80002DA4(struct MainPoolState* block, s32 size) {
    void* temp_v1 = (void*)((u8*)block + 0x10);

    block->listHeadL = 0;
    block->freeSpace = ((size & ~3) - 0x10); // this doesnt match an ALIGN4 macro or whatnot
    block->listHeadR = temp_v1;
    block->prev = temp_v1;
    return block;
}

s32 func_80002DCC(struct MainPoolState* state, s32 arg1, s32 arg2) {
    s32 temp_a2;
    s32 temp_a3;
    s32 var_v0;
    s32 ret = 0;

    if (arg2 > 0) {
        var_v0 = (((s32)state->prev + (s32)arg2) - 1) & ~(arg2 - 1);
    } else {
        var_v0 = state->prev;
    }
    temp_a2 = (var_v0 - (s32)state->prev) + arg1;
    if (temp_a2 > 0) {
        temp_a3 = (s32)state->listHeadL + temp_a2;
        if ((s32)state->freeSpace >= temp_a3) {
            ret = var_v0;
            state->prev = (s32)((s32)state->prev + temp_a2);
            state->listHeadL = temp_a3;
        }
    }
    return ret;
}

void func_80002E3C(struct MainPoolState* state, s32 size) {
    if ((s32)state->freeSpace >= size) {
        state->listHeadL = size;
        state->prev = (void*)((s32)state->listHeadR + size);
    }
}

void func_80002E64(struct MainPoolState* state) {
    void* mem = (u8*)((u32)state + sizeof(struct MainPoolState));

    state->listHeadL = 0;
    state->listHeadR = mem;
    state->prev = mem;
}
