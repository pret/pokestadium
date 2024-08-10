#include "global.h"

void func_800491C0(s32 arg0);
void func_8004FD90(void);

extern s32 D_80078580;

extern void* D_80078584;

void func_80042920(void* arg0, s32 arg1) {
    if (D_80078580 == 0) {
        D_80078580 = arg0;
        if (D_80078584 == NULL) {
            D_80078584 = arg0;
            func_800491C0(arg1);
        }
    }
}

void func_8004296C(void) {
    if (D_80078580 != 0) {
        func_8004FD90();
        D_80078580 = 0;
        D_80078584 = 0;
    }
}
