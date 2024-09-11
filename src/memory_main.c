#include "global.h"
#include <macros.h>
#include "memory.h"

static struct MainPool sMemPool;

/**
 * Initialize the main memory pool. This pool is conceptually a pair of stacks
 * that grow inward from the left and right. It therefore only supports
 * freeing the object that was most recently allocated from a side.
 */
void main_pool_init(void* start, void* end) {
    sMemPool.start = (void*)(ALIGN16((uintptr_t)start) + 16);
    sMemPool.end = (void*)(ALIGN16((uintptr_t)end - 15) - 16);
    sMemPool.available = (uintptr_t)sMemPool.end - (uintptr_t)sMemPool.start;
    sMemPool.mainState = NULL;

    sMemPool.listHeadL = ((u8*)sMemPool.start - sizeof(MainPoolBlock));
    sMemPool.listHeadL->prev = NULL;
    sMemPool.listHeadL->next = NULL;
    sMemPool.listHeadL->func = NULL;
    sMemPool.listHeadL->arg = '\0';

    sMemPool.listHeadR = sMemPool.end;
    sMemPool.listHeadR->prev = NULL;
    sMemPool.listHeadR->next = NULL;
    sMemPool.listHeadL->func = NULL;
    sMemPool.listHeadL->arg = '\0';

    osCreateMesgQueue(&sMemPool.queue, sMemPool.msgs, ARRAY_COUNT(sMemPool.msgs));
    osSendMesg(&sMemPool.queue, NULL, OS_MESG_NOBLOCK);
}

/**
 * Allocate a block of memory from the pool of given size, and from the
 * specified side of the pool (MEMORY_POOL_LEFT or MEMORY_POOL_RIGHT).
 * If there is not enough space, return NULL.
 */
void* main_pool_alloc_from_pool(u32 size, u32 side) {
    MainPoolBlock* newListHead;
    void* addr = NULL;

    size = ALIGN16(size) + sizeof(MainPoolBlock);

    // do we have enough space?
    if (size > 0 && size <= sMemPool.available) {
        if (side == MEMORY_POOL_LEFT) {
            // reduce available size.
            sMemPool.available -= size;
            newListHead = (void*)((uintptr_t)sMemPool.listHeadL + size);
            sMemPool.listHeadL->next = newListHead;
            newListHead->prev = sMemPool.listHeadL;
            newListHead->next = NULL;
            newListHead->func = NULL;
            newListHead->arg = '\0';
            addr = ((u8*)sMemPool.listHeadL + sizeof(MainPoolBlock));
            sMemPool.listHeadL = newListHead;
        } else if (side == MEMORY_POOL_RIGHT) {
            // reduce available size.
            sMemPool.available -= size;
            newListHead = (void*)((uintptr_t)sMemPool.listHeadR - size);
            sMemPool.listHeadR->prev = newListHead;
            newListHead->next = sMemPool.listHeadR;
            newListHead->prev = NULL;
            newListHead->func = NULL;
            newListHead->arg = '\0';
            sMemPool.listHeadR = newListHead;
            addr = ((u8*)newListHead + sizeof(MainPoolBlock));
        }
    }
    return addr;
}

/**
 * Free a block of memory that was allocated from the pool. The block must be
 * the most recently allocated block from its end of the pool, otherwise all
 * newer blocks are freed as well.
 * Return the amount of free space left in the pool.
 */
u32 main_pool_free(void* addr, u32 runBlockFunc) {
    MainPoolBlock* block = (MainPoolBlock*)((u8*)addr - sizeof(MainPoolBlock));
    MainPoolBlock* oldListHead = (MainPoolBlock*)((u8*)addr - sizeof(MainPoolBlock));

    if (oldListHead < sMemPool.listHeadL) {
        do {
            block = (sMemPool.listHeadL = sMemPool.listHeadL->prev);
            if (runBlockFunc) {
                // TODO: Fakematch
                AllocateFunc func = block->func;
                if (func != 0) {
                    block->func((u8*)block + sizeof(MainPoolBlock), block->arg);
                    // TODO: fake here too
                    if ((!(&sMemPool)) && (!(&sMemPool))) {}
                }
            }
            sMemPool.available += ((uintptr_t)sMemPool.listHeadL->next - (uintptr_t)sMemPool.listHeadL);
            sMemPool.listHeadL->next = NULL;
        } while (oldListHead != sMemPool.listHeadL);
    } else {
        block = sMemPool.listHeadR;
        if (oldListHead >= block && oldListHead >= block) {
            do {
                if (runBlockFunc) {
                    AllocateFunc func = block->func;
                    if (func != NULL) {
                        func((u8*)block + sizeof(MainPoolBlock), block->arg);
                        block = sMemPool.listHeadR;
                    }
                }
                block = (sMemPool.listHeadR = block->next);
                sMemPool.available += ((uintptr_t)block - (uintptr_t)block->prev);
                block->prev = NULL;
                block = sMemPool.listHeadR;
            } while (oldListHead >= sMemPool.listHeadR);
        }
    }

    return main_pool_get_available();
}

/**
 * Manually allocate and initialize a block given a size and side and its
 * function+arguments.
 */
void* main_pool_alloc_with_func(u32 size, s32 side, s32 arg, AllocateFunc func) {
    MainPoolBlock* addr;

    osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);
    addr = main_pool_alloc_from_pool(size, side);
    if (addr != NULL) {
        main_pool_set_func(addr, arg, func);
    }
    osSendMesg(&sMemPool.queue, NULL, OS_MESG_NOBLOCK);

    return addr;
}

/**
 * Same as above but no function/argument is set.
 */
void* main_pool_alloc(u32 size, s32 side) {
    MainPoolBlock* node;

    osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);
    node = main_pool_alloc_from_pool(size, side);
    osSendMesg(&sMemPool.queue, NULL, OS_MESG_NOBLOCK);

    return node;
}

/**
 * Tries to free a block of memory that was allocated from the pool. Return
 * the new available amount of the pool.
 */
u32 main_pool_try_free(void* addr) {
    if (addr != NULL) {
        osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);
        main_pool_free(addr, TRUE);
        osSendMesg(&sMemPool.queue, NULL, OS_MESG_NOBLOCK);
    }

    return main_pool_get_available();
}

/**
 * Resize a block of memory that was allocated from the left side of the pool.
 * If the block is increasing in size, it must be the most recently allocated
 * block from the left side.
 * The block does not move.
 */
void* main_pool_realloc(void* addr, size_t size) {
    MainPoolBlock* prior = (MainPoolBlock*)((u8*)addr - sizeof(MainPoolBlock));
    void* newaddr = NULL;

    osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);

    // most recently allocated block?
    if (prior->next == sMemPool.listHeadL) {
        size_t diff = ((uintptr_t)prior->next - (uintptr_t)addr);
        size = ALIGN16(size);

        // is there enough room to expand/realloc the area?
        if (diff >= size || sMemPool.available >= (size - diff)) {
            s32 arg = prior->arg;
            AllocateFunc func = prior->func;
            main_pool_free(addr, FALSE); // do not run the func as we are merely reallocating it.
            newaddr = main_pool_alloc_from_pool(size, MEMORY_POOL_LEFT);
            main_pool_set_func(newaddr, arg, func);
        }
    }
    osSendMesg(&sMemPool.queue, NULL, OS_MESG_NOBLOCK);
    return newaddr;
}

/**
 * Return the amount of available memory to use in the pool.
 */
u32 main_pool_get_available(void) {
    // account for the block struct. Any newly allocated pools have this struct as its "true"
    // header, so subtract the size to get the real amount of available space.
    s32 available = sMemPool.available - sizeof(MainPoolBlock);

    // if it was less than 0, then we do not have enough to allocate a single pool. Floor the
    // practical amount of available space to 0.
    if (available < 0) {
        available = 0;
    }

    return available;
}

/**
 * Push pool state, to be restored later. Return the amount of free space left
 * in the pool.
 */
u32 main_pool_push_state(u32 arg) {
    struct MainPoolState* state;
    MainPoolBlock* listHeadL;
    MainPoolBlock* listHeadR;
    uintptr_t available;

    osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);

    // retrieve the space and head pointers.
    available = sMemPool.available;
    listHeadL = sMemPool.listHeadL;
    listHeadR = sMemPool.listHeadR;

    /**
     * We are essentially allocating a block that looks like this:
     *
     * struct AllocatedBlock {
     *     MainPoolBlock block;
     *     struct MainPoolState state; <---- the pointer is pointing here.
     * };
     */
    state = main_pool_alloc_from_pool(sizeof(struct MainPoolState), MEMORY_POOL_LEFT);
    if (state != NULL) {
        /**
         * Why is this line here? What this line is doing is backing the pointer up to the
         * previous block before the state. In the block alloc function, addr is determined
         * by the head plus the size of the block struct, meaning it is returning the
         * pointer to the head.
         */
        ((MainPoolBlock*)((u8*)state - sizeof(MainPoolBlock)))->arg = arg;

        // now that the previous block's argument is set, set the newly allocated state's
        // fields.
        state->prev = sMemPool.mainState;
        state->freeSpace = available;
        state->listHeadL = listHeadL;
        state->listHeadR = listHeadR;

        // add the newly allocated state.
        sMemPool.mainState = state;
    }
    osSendMesg(&sMemPool.queue, NULL, OS_MESG_NOBLOCK);
    return main_pool_get_available();
}

/**
 * Restore pool state from a previous call to main_pool_push_state. Return the
 * amount of free space left in the pool.
 */
u32 main_pool_pop_state(u32 arg) {
    struct MainPoolState* node;
    MainPoolBlock* argptr;
    void* listHeadL;
    void* listHeadR;
    struct MainPoolState* state;

    osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);

    do {
        node = sMemPool.mainState;
        listHeadL = node->listHeadL;
        listHeadR = node->listHeadR;
        sMemPool.available = node->freeSpace;
        sMemPool.mainState = node->prev;

        // was the argument passed in blank?
        if (arg == '\0') {
            break;
        }

        /**
         * Odd reuse of the variable, but what this is doing is backing the ptr up to the
         * pool block. Thus, to check the arg variable on the pool block located before the state,
         * we will need to cast the next if check.
         */
        node = (void*)((u8*)node - sizeof(struct MainPoolState));

        if (arg == (uintptr_t)((MainPoolBlock*)node)->arg) {
            // we found the block with the matching string! That means we are now at the
            // beginning of the pool area and can begin to run the function loops. Break.
            break;
        }
    } while (sMemPool.mainState != NULL);

    /**
     * For every block pool in the main pool being popped, try to run the function set by its
     * main pool state. Repeat until we have cleared the right pool side.
     */
    argptr = sMemPool.listHeadR;
    while ((uintptr_t)listHeadR > (uintptr_t)argptr) {
        if (argptr->func != NULL) {
            argptr->func((u8*)argptr + sizeof(MainPoolBlock), argptr->arg);
        }
        argptr = argptr->next;
    }

    /**
     * Same as above, but for the left side.
     */
    argptr = sMemPool.listHeadL->prev;
    while ((uintptr_t)listHeadL <= (uintptr_t)argptr) {
        if (argptr->func != NULL) {
            argptr->func((u8*)argptr + sizeof(MainPoolBlock), argptr->arg);
        }
        argptr = argptr->prev;
    }

    // set the new left and right sides and queue and return.
    sMemPool.listHeadL = listHeadL;
    sMemPool.listHeadR = listHeadR;
    osSendMesg(&sMemPool.queue, NULL, OS_MESG_NOBLOCK);
    return main_pool_get_available();
}

/*
 * Unused function. Seems at first glance to check for an address within some
 * range, and then return the pointer to its data after the block. Perhaps?
 * Without this being called, its hard to tell the correct context of this
 * function.
 */
void* main_pool_search(uintptr_t addr, s32* argPtr) {
    MainPoolBlock* node;
    MainPoolBlock* otherNode;

    node = sMemPool.listHeadL->prev;
    while (node != NULL) {
        int isAddrLater = (addr >= ((uintptr_t)((u8*)node + sizeof(MainPoolBlock))));
        otherNode = node->next;
        // seems to be checking for an addr within a block region? Since this function
        // is unused, we wont be able to check for the intended context of what could
        // call this function.
        if (isAddrLater && addr < ((uintptr_t)otherNode & 0xFFFFFFFF)) {
            if (argPtr != NULL) {
                *argPtr = node->arg;
            }
            // return the pointer to its block contents.
            return (void*)((u8*)(node) + sizeof(MainPoolBlock));
        }
        node = node->prev;
    }

    // we've searched thr prev linked list. Now lets go through the next linked list.
    node = sMemPool.listHeadR;
    otherNode = node->next;
    while (otherNode != NULL) {
        int isAddrLater = (addr >= ((uintptr_t)((u8*)node + sizeof(MainPoolBlock))));
        MainPoolBlock* new_var = otherNode; // bit of a fakematch to force the move reload.
        // same as above.
        if (isAddrLater && (addr < ((uintptr_t)new_var & 0xFFFFFFFF))) {
            if (argPtr != NULL) {
                *argPtr = node->arg;
            }
            // return the pointer to its block contents.
            return (void*)((u8*)(node) + sizeof(MainPoolBlock));
        }
        otherNode = (node = otherNode)->next;
    }

    return NULL;
}

/**
 * Set the block function and its argument(s) for a given block.
 */
void main_pool_set_func(void* block, s32 arg, AllocateFunc func) {
    MainPoolBlock* node = (void*)((uintptr_t)block - sizeof(MainPoolBlock));
    node->func = func;
    node->arg = arg;
}

/**
 * Get the distance offset from the block's state listHeadL pointer to the current block.
 */
size_t main_pool_get_block_dist(MainPoolBlock* block) {
    struct MainPoolState* state = ((u8*)block - sizeof(MainPoolBlock));

    return (size_t)((uintptr_t)state->listHeadL - (uintptr_t)block);
}

/**
 * Return the pointer to the static memory pool area.
 */
struct MainPool* main_pool_get_pool(void) {
    return &sMemPool;
}
