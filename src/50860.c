#include "50860.h"
#include "45720.h"
#include "38BB0.h"
#include "3D140.h"

void func_8004FC60(s32 arg0, s32 arg1) {
    s32 i;

    if (arg0 & 4) {
        for (i = 0; i < 2; i++) {
            func_80044D78(i, arg1);
        }
        arg0 &= ~4;
    }
    func_8003916C(arg0, arg1);
}

void func_8004FCD8(s32 arg0) {
    s32 i;

    D_8007840C = 0;
    func_8003DB84(0);
    func_8004FC60(3, arg0);

    for (i = 0; i < 2; i++) {
        func_80044D78(i, arg0);
    }
}

void func_8004FD44(void) {
    func_8004FCD8(1);
}

void func_8004FD64(s32 arg0) {
    func_8004FCD8(arg0);
}
