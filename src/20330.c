#include "global.h"
#include "20330.h"

static s32 pad_D_800AC880[0x2];
static s32 D_800AC888;
static Controller* D_800AC88C;

void func_8001F730(void) {
}

void func_8001F738(Controller* arg0) {
    D_800AC888 = 0xA;
    D_800AC88C = arg0;
}

s32 func_8001F750(void) {
    if (D_800AC88C->buttonPressed & 0x800) {
        D_800AC888 = 0xA;
        return 0x800;
    }

    if (D_800AC88C->buttonPressed & 0x400) {
        D_800AC888 = 0xA;
        return 0x400;
    }

    if (D_800AC88C->buttonPressed & 0x200) {
        D_800AC888 = 0xA;
        return 0x200;
    }

    if (D_800AC88C->buttonPressed & 0x100) {
        D_800AC888 = 0xA;
        return 0x100;
    }

    D_800AC888--;
    if (D_800AC888 <= 0) {
        D_800AC888 = 0;

        // clang-format off
        if (D_800AC88C->buttonDown & 0x800) {
            D_800AC888 = 2; return 0x800;
        }
        // clang-format on

        if (D_800AC88C->buttonDown & 0x400) {
            D_800AC888 = 2;
            return 0x400;
        }

        if (D_800AC88C->buttonDown & 0x200) {
            D_800AC888 = 2;
            return 0x200;
        }

        if (D_800AC88C->buttonDown & 0x100) {
            D_800AC888 = 2;
            return 0x100;
        }
    }

    return 0;
}
