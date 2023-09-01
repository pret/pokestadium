#include <ultra64.h>
#include <macros.h>
#include "memory.h"

static struct MainPool sMemPool;

/**
 * Initialize the main memory pool. This pool is conceptually a pair of stacks
 * that grow inward from the left and right. It therefore only supports
 * freeing the object that was most recently allocated from a side.
 */
void main_pool_init(void *start, void *end) {
    sMemPool.start     = (void *)(ALIGN16((uintptr_t)start) + 16);
    sMemPool.end       = (void *)(ALIGN16((uintptr_t)end - 15) - 16);
    sMemPool.available = (uintptr_t)sMemPool.end - (uintptr_t)sMemPool.start;
    sMemPool.mainState = NULL;

    sMemPool.listHeadL = ((u8*)sMemPool.start - sizeof(struct MainPoolBlock));
    sMemPool.listHeadL->prev = NULL;
    sMemPool.listHeadL->next = NULL;
    sMemPool.listHeadL->func = NULL;
    sMemPool.listHeadL->arg  = 0;

    sMemPool.listHeadR = sMemPool.end;
    sMemPool.listHeadR->prev = NULL;
    sMemPool.listHeadR->next = NULL;
    sMemPool.listHeadL->func = NULL;
    sMemPool.listHeadL->arg  = 0;

    osCreateMesgQueue(&sMemPool.queue, sMemPool.msgs, ARRAY_COUNT(sMemPool.msgs));
    osSendMesg(&sMemPool.queue, NULL, OS_MESG_NOBLOCK);
}

/**
 * Allocate a block of memory from the pool of given size, and from the
 * specified side of the pool (MEMORY_POOL_LEFT or MEMORY_POOL_RIGHT).
 * If there is not enough space, return NULL.
 */
void *main_pool_alloc(u32 size, u32 side) {
    struct MainPoolBlock *newListHead;
    void *addr = NULL;

    size = ALIGN16(size) + sizeof(struct MainPoolBlock);
    if (size != 0 && sMemPool.available >= size) {
        if (side == MEMORY_POOL_LEFT) {
            sMemPool.available -= size;
            newListHead = (void *)((uintptr_t)sMemPool.listHeadL + size);
            sMemPool.listHeadL->next = newListHead;
            newListHead->prev = sMemPool.listHeadL;
            newListHead->next = NULL;
            newListHead->func = 0;
            newListHead->arg = 0;
            addr = ((u8*)sMemPool.listHeadL + sizeof(struct MainPoolBlock));
            sMemPool.listHeadL = newListHead;
        } else if (side == MEMORY_POOL_RIGHT) {
            sMemPool.available -= size;
            newListHead = (void *)((uintptr_t)sMemPool.listHeadR - size);
            sMemPool.listHeadR->prev = newListHead;
            newListHead->next = sMemPool.listHeadR;
            newListHead->prev = NULL;
            newListHead->func = 0;
            newListHead->arg = 0;
            sMemPool.listHeadR = newListHead;
            addr = ((u8*)newListHead + sizeof(struct MainPoolBlock));
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
u32 main_pool_free(void *addr, u32 runBlockFunc) {
    struct MainPoolBlock *block = (struct MainPoolBlock *)((u8 *)addr - sizeof(struct MainPoolBlock));
    struct MainPoolBlock *oldListHead = (struct MainPoolBlock *)((u8 *)addr - sizeof(struct MainPoolBlock));

    if (oldListHead < sMemPool.listHeadL) {
        do {
            block = (sMemPool.listHeadL = sMemPool.listHeadL->prev);
            if (runBlockFunc) {
                // TODO: Fakematch
                void (*func)(struct MainPoolBlock *, u32) = block->func;
                if (func != 0) {
                    block->func(block + 1, block->arg); 
                    // TODO: fake here too
                    if ((!(&sMemPool)) && (!(&sMemPool)))
                    {
                    }
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
                    void (*func)(struct MainPoolBlock *, u32) = block->func;
                    if (func != NULL) {
                        func(block + 1, block->arg);
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
void *main_pool_alloc_node(u32 size, s32 side, s32 arg, void *func) {
    struct MainPoolBlock *node;

    osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);
    node = main_pool_alloc(size, side);
    if (node != NULL) {
        main_pool_set_func(node, arg, func);
    }
    osSendMesg(&sMemPool.queue, NULL, OS_MESG_NOBLOCK);
    
    return node;
}

/**
 * Same as above but no function/argument is set.
 */
void *main_pool_alloc_node_no_func(u32 size, s32 side) {
    struct MainPoolBlock *node;

    osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);
    node = main_pool_alloc(size, side);
    osSendMesg(&sMemPool.queue, NULL, OS_MESG_NOBLOCK);

    return node;
}

/**
 * Tries to free a block of memory that was allocated from the pool. Return
 * the new available amount of the pool.
 */
u32 main_pool_try_free(struct MainPoolBlock *addr) {
    if (addr != NULL) {
        osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);
        main_pool_free(addr, 1);
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
void *main_pool_realloc(void *addr, size_t size) {
    struct MainPoolBlock *prior = (struct MainPoolBlock *)((u8 *)addr - sizeof(struct MainPoolBlock));
    void *newaddr = NULL;

    osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);

    if (prior->next == sMemPool.listHeadL) {
        size_t diff = ((uintptr_t)prior->next - (uintptr_t)addr);
        size = ALIGN16(size);
        if (diff >= size || sMemPool.available >= (size - diff)) {
            s32 arg = prior->arg;
            void *func = prior->func;
            main_pool_free(addr, 0);
            newaddr = main_pool_alloc(size, MEMORY_POOL_LEFT);
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
    s32 available = sMemPool.available - sizeof(struct MainPoolBlock);

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
    struct MainPoolState *state;
    struct MainPoolBlock *listHeadL;
    struct MainPoolBlock *listHeadR;
    uintptr_t available;

    osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);

    // retrieve the space and head pointers.
    available = sMemPool.available;
    listHeadL = sMemPool.listHeadL;
    listHeadR = sMemPool.listHeadR;

    state = main_pool_alloc(sizeof(struct MainPoolState), MEMORY_POOL_LEFT);
    if (state != NULL) {
        /**
         * Why is this line here? What this line is doing is backing the pointer up to the
         * previous block before this one. in the block alloc function, addr is determined 
         * by the head plus the size of the block struct, meaning it is returning the
         * pointer to the head.
         */
        ((struct MainPoolBlock *)((u8*)state-sizeof(struct MainPoolBlock)))->arg = arg;

        // now that the previous block's argument is set, set the newly allocated state's
        // fields.
        state->prev      = sMemPool.mainState;
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
    struct MainPoolState *node;
    struct MainPoolBlock *argptr;
    void *listHeadL;
    void *listHeadR;
    struct MainPoolState *state;

    argptr = (u32)arg;
    osRecvMesg(&sMemPool.queue, NULL, OS_MESG_BLOCK);

    do {
        node = sMemPool.mainState;
        listHeadL = node->listHeadL;
        listHeadR = node->listHeadR;
        sMemPool.available = node->freeSpace;
        sMemPool.mainState = node->prev;

        // was the argument passed in 0?
        if (argptr == 0) { 
            break; 
        }

        // odd reuse of the variable, but what this is doing is backing the ptr up to the
        // pool block. Thus, to check the arg variable on the pool block located before the state, 
        // we will need to cast the next if check.
        node = (void*)((u8*)node - sizeof(struct MainPoolState));

        if ((uintptr_t)argptr == (uintptr_t)((struct MainPoolBlock *)node)->arg) { 
            // we found the block with the matching string! break.
            break; 
        }
    } while(sMemPool.mainState != NULL);

    argptr = sMemPool.listHeadR;
    while ((uintptr_t)listHeadR > (uintptr_t)argptr) {
        if (argptr->func != NULL) {
            argptr->func(argptr + 1, argptr->arg);
        }
        argptr = argptr->next;
    }

    argptr = sMemPool.listHeadL->prev;
    while ((uintptr_t)listHeadL <= (uintptr_t)argptr) {
        if (argptr->func != NULL) {
            argptr->func(argptr + 1, argptr->arg);
        }
        argptr = argptr->prev;
    }

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
void *main_pool_search(uintptr_t addr, s32 *argPtr) {
    struct MainPoolBlock *node;
    struct MainPoolBlock *otherNode;

    node = sMemPool.listHeadL->prev;
    while (node != NULL) {
        int isAddrLater = (addr >= ((uintptr_t) ((u8*)node + sizeof(struct MainPoolBlock))));
        otherNode = node->next;
        // seems to be checking for an addr within a block region? Since this function
        // is unused, we wont be able to check for the intended context of what could
        // call this function.
        if (isAddrLater && addr < ((uintptr_t)otherNode & 0xFFFFFFFF)) {
            if (argPtr != NULL) {
               *argPtr = node->arg;
            }
            // return the pointer to its block contents.
            return (void*)((u8*)(node) + sizeof(struct MainPoolBlock));
        }
        node = node->prev;
    }

    // we've searched thr prev linked list. Now lets go through the next linked list.
    node = sMemPool.listHeadR;
    otherNode = node->next;
    while (otherNode != NULL) {
        int isAddrLater = (addr >= ((uintptr_t) ((u8*)node + sizeof(struct MainPoolBlock))));
        struct MainPoolBlock *new_var = otherNode; // bit of a fakematch to force the move reload.
        // same as above.
        if (isAddrLater && (addr < ((uintptr_t)new_var & 0xFFFFFFFF))) {
            if (argPtr != NULL) {
               *argPtr = node->arg;
            }
            // return the pointer to its block contents.
            return (void*)((u8*)(node) + sizeof(struct MainPoolBlock));
        }
        otherNode = (node = otherNode)->next;
    }

    return NULL;
}

/**
 * Set the block function and its argument(s) for a given block.
 */
void main_pool_set_func(void *block, s32 arg, void *func) {
    struct MainPoolBlock *node = (void*)((uintptr_t)block - sizeof(struct MainPoolBlock));
    node->func = func;
    node->arg = arg;
}

/**
 * Get the distance offset from the block's state listHeadL pointer to the current block.
 */
size_t main_pool_get_block_dist(struct MainPoolBlock *block) {
    struct MainPoolState *state = ((u8*)block - sizeof(struct MainPoolBlock));

    return (size_t)((uintptr_t)state->listHeadL - (uintptr_t)block);
}

/**
 * Return the pointer to the static memory pool area.
 */
struct MainPool *main_pool_get_pool(void) {
    return &sMemPool;
}
