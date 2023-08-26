#include <ultra64.h>
#include <macros.h>
#include "memory.h"

extern struct MainPool gMemPool; // gMemPool

/**
 * Initialize the main memory pool. This pool is conceptually a pair of stacks
 * that grow inward from the left and right. It therefore only supports
 * freeing the object that was most recently allocated from a side.
 */
void main_pool_init(void *start, void *end) {
    gMemPool.start     = (void *)(ALIGN16((uintptr_t)start) + 16);
    gMemPool.end       = (void *)(ALIGN16((uintptr_t)end - 15) - 16);
    gMemPool.available = (uintptr_t)gMemPool.end - (uintptr_t)gMemPool.start;
    gMemPool.mainState = NULL;

    gMemPool.listHeadL = ((u8*)gMemPool.start - sizeof(struct MainPoolBlock));
    gMemPool.listHeadL->prev = NULL;
    gMemPool.listHeadL->next = NULL;
    gMemPool.listHeadL->func = NULL;
    gMemPool.listHeadL->arg  = 0;

    gMemPool.listHeadR = gMemPool.end;
    gMemPool.listHeadR->prev = NULL;
    gMemPool.listHeadR->next = NULL;
    gMemPool.listHeadL->func = NULL;
    gMemPool.listHeadL->arg  = 0;

    osCreateMesgQueue(&gMemPool.queue, gMemPool.msgs, ARRAY_COUNT(gMemPool.msgs));
    osSendMesg(&gMemPool.queue, NULL, OS_MESG_NOBLOCK);
}

/**
 * Allocate a block of memory from the pool of given size, and from the
 * specified side of the pool (MEMORY_POOL_LEFT or MEMORY_POOL_RIGHT).
 * If there is not enough space, return NULL.
 */
struct MainPoolBlock *main_pool_alloc(u32 size, u32 side) {
    struct MainPoolBlock *newListHead;
    void *addr = NULL;

    size = ALIGN16(size) + sizeof(struct MainPoolBlock);
    if (size != 0 && gMemPool.available >= size) {
        if (side == MEMORY_POOL_LEFT) {
            gMemPool.available -= size;
            newListHead = (void *)((uintptr_t)gMemPool.listHeadL + size);
            gMemPool.listHeadL->next = newListHead;
            newListHead->prev = gMemPool.listHeadL;
            newListHead->next = NULL;
            newListHead->func = 0;
            newListHead->arg = 0;
            addr = ((u8*)gMemPool.listHeadL + sizeof(struct MainPoolBlock));
            gMemPool.listHeadL = newListHead;
        } else if (side == MEMORY_POOL_RIGHT) {
            gMemPool.available -= size;
            newListHead = (void *)((uintptr_t)gMemPool.listHeadR - size);
            gMemPool.listHeadR->prev = newListHead;
            newListHead->next = gMemPool.listHeadR;
            newListHead->prev = NULL;
            newListHead->func = 0;
            newListHead->arg = 0;
            gMemPool.listHeadR = newListHead;
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

    if (oldListHead < gMemPool.listHeadL) {
        do {
            block = (gMemPool.listHeadL = gMemPool.listHeadL->prev);
            if (runBlockFunc) {
                // TODO: Fakematch
                void (*func)(struct MainPoolBlock *, u32) = block->func;
                if (func != 0) {
                    block->func(block + 1, block->arg); 
                    // TODO: fake here too
                    if ((!(&gMemPool)) && (!(&gMemPool)))
                    {
                    }
                }
            }
            gMemPool.available += ((uintptr_t)gMemPool.listHeadL->next - (uintptr_t)gMemPool.listHeadL);
            gMemPool.listHeadL->next = NULL;
        } while (oldListHead != gMemPool.listHeadL);
    } else {
        block = gMemPool.listHeadR;
        if (oldListHead >= block && oldListHead >= block) {
            do {
                if (runBlockFunc) {
                    void (*func)(struct MainPoolBlock *, u32) = block->func;
                    if (func != NULL) {
                        func(block + 1, block->arg);
                        block = gMemPool.listHeadR;
                    }
                }
                block = (gMemPool.listHeadR = block->next);
                gMemPool.available += ((uintptr_t)block - (uintptr_t)block->prev);
                block->prev = NULL;
                block = gMemPool.listHeadR;
            } while (oldListHead >= gMemPool.listHeadR);
        }
    }

    return main_pool_get_available();
}

/**
 * Manually allocate and initialize a block given a size and side and its
 * function+arguments.
 */
struct MainPoolBlock *main_pool_alloc_node(u32 size, s32 side, s32 arg, void *func) {
    struct MainPoolBlock *node;

    osRecvMesg(&gMemPool.queue, NULL, OS_MESG_BLOCK);
    node = main_pool_alloc(size, side);
    if (node != NULL) {
        main_pool_set_func(node, arg, func);
    }
    osSendMesg(&gMemPool.queue, NULL, OS_MESG_NOBLOCK);
    
    return node;
}

/**
 * Same as above but no function/argument is set.
 */
struct MainPoolBlock *main_pool_alloc_node_no_func(u32 size, s32 side) {
    struct MainPoolBlock *node;

    osRecvMesg(&gMemPool.queue, NULL, OS_MESG_BLOCK);
    node = main_pool_alloc(size, side);
    osSendMesg(&gMemPool.queue, NULL, OS_MESG_NOBLOCK);

    return node;
}

/**
 * Tries to free a block of memory that was allocated from the pool. Return
 * the new available amount of the pool.
 */
u32 main_pool_try_free(struct MainPoolBlock *addr) {
    if (addr != NULL) {
        osRecvMesg(&gMemPool.queue, NULL, OS_MESG_BLOCK);
        main_pool_free(addr, 1);
        osSendMesg(&gMemPool.queue, NULL, OS_MESG_NOBLOCK);
    }

    return main_pool_get_available();
}

/**
 * Resize a block of memory that was allocated from the left side of the pool.
 * If the block is increasing in size, it must be the most recently allocated
 * block from the left side.
 * The block does not move.
 */
struct MainPoolBlock *main_pool_realloc(void *addr, size_t size) {
    struct MainPoolBlock *prior = (struct MainPoolBlock *)((u8 *)addr - sizeof(struct MainPoolBlock));
    void *newaddr = NULL;

    osRecvMesg(&gMemPool.queue, NULL, OS_MESG_BLOCK);

    if (prior->next == gMemPool.listHeadL) {
        size_t diff = ((uintptr_t)prior->next - (uintptr_t)addr);
        size = ALIGN16(size);
        if (diff >= size || gMemPool.available >= (size - diff)) {
            s32 arg = prior->arg;
            void *func = prior->func;
            main_pool_free(addr, 0);
            newaddr = main_pool_alloc(size, 0);
            main_pool_set_func(newaddr, arg, func);
        }
    }
    osSendMesg(&gMemPool.queue, NULL, OS_MESG_NOBLOCK);
    return newaddr;
}

/**
 * Return the amount of available memory to use in the pool.
 */
u32 main_pool_get_available(void) {
    s32 available = gMemPool.available - sizeof(struct MainPoolBlock);

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

    osRecvMesg(&gMemPool.queue, NULL, OS_MESG_BLOCK);

    // retrieve the space and head pointers.
    available = gMemPool.available;
    listHeadL = gMemPool.listHeadL;
    listHeadR = gMemPool.listHeadR;

    state = (void*)main_pool_alloc(sizeof(struct MainPoolState), 0);
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
        state->prev      = gMemPool.mainState;
        state->freeSpace = available;
        state->listHeadL = listHeadL;
        state->listHeadR = listHeadR;

        // add the newly allocated state.
        gMemPool.mainState = state;
    }
    osSendMesg(&gMemPool.queue, NULL, OS_MESG_NOBLOCK);
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
    osRecvMesg(&gMemPool.queue, NULL, OS_MESG_BLOCK);

    do {
        node = gMemPool.mainState;
        listHeadL = node->listHeadL;
        listHeadR = node->listHeadR;
        gMemPool.available = node->freeSpace;
        gMemPool.mainState = node->prev;

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
    } while(gMemPool.mainState != NULL);

    argptr = gMemPool.listHeadR;
    while ((uintptr_t)listHeadR > (uintptr_t)argptr) {
        if (argptr->func != NULL) {
            argptr->func(argptr + 1, argptr->arg);
        }
        argptr = argptr->next;
    }

    argptr = gMemPool.listHeadL->prev;
    while ((uintptr_t)listHeadL <= (uintptr_t)argptr) {
        if (argptr->func != NULL) {
            argptr->func(argptr + 1, argptr->arg);
        }
        argptr = argptr->prev;
    }

    gMemPool.listHeadL = listHeadL;
    gMemPool.listHeadR = listHeadR;
    osSendMesg(&gMemPool.queue, NULL, OS_MESG_NOBLOCK);
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

    node = gMemPool.listHeadL->prev;
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
    node = gMemPool.listHeadR;
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
uintptr_t main_pool_get_block_dist(struct MainPoolBlock *block) {
    struct MainPoolState *state = ((u8*)block - sizeof(struct MainPoolBlock));

    return (uintptr_t)state->listHeadL - (uintptr_t)block;
}

/**
 * Return the pointer to the static memory pool area.
 */
struct MainPool *main_pool_get_pool(void) {
    return &gMemPool;
}
