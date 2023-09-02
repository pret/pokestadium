#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"

// thread pris
#define THREAD_PRI_IDLE_INIT 100

// thread IDs
#define THREAD_ID_IDLE 1

#define POOL_END_4MB 0x80400000
#define POOL_END_6MB 0x80600000

/*
 * Dynamic heap with an indetermate amount of space. This pool can either end at 4MB or
 * 6MB depending on osMemSize, which is really strange as it should be using the whole
 * 8MB of the expansion pak.
 */
extern u8 gPool[1];

#endif
