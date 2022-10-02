#include "common.h"

extern s32 D_8007A860;
extern s32 D_8007A868;

// TODO: This returns an OSMesgQueue pointer. D_8007A860 should
// be __osPiDevMgr.active and D_8007A868 should be
// __osPiDevMgr.cmdQueue.
s32 osPiGetCmdQueue(void) {
    if (D_8007A860 == 0) {
        return 0;
    } 
    return D_8007A868;
}
