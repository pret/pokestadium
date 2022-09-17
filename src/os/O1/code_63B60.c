#include "common.h"

extern s32 D_8007A860;
extern s32 D_8007A868;

s32 func_80062F60(void) {
    if (D_8007A860 == 0) {
        return 0;
    } 
    return D_8007A868;
}
