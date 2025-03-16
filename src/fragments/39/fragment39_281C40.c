#include "fragment39.h"
#include "src/fragments/2/fragment2.h"
#include "26820.h"

void func_82505FA0(void) {
    D_8780FA28 = func_800280C4() & 0xFF;
}

void func_82505FC8(s16 arg0) {
    D_87806338 = arg0;
}

void func_82505FE0(s16 arg0) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        D_8780FA68[i] = 0;
    }

    switch (arg0) {
        case 0:
            D_87806338 = -1;
            D_8780FA2A = 0;
            D_8780FA2C = 0;

            for (i = 0; i < 4; i++) {
                D_8780FA30[i] = 1;
            }

            D_8780FA38 = 1;
            D_8780FA3A = 3;

            for (i = 0; i < 4; i++) {
                D_8780FA40[i] = 0;
            }

            D_8780FA48 = 0;
            // clang-format off
            for (i = 0; i < 9; i++) { D_8780FA50[i] = 0; }
            // clang-format on
            break;

        case 1:
        case 4:
            break;
    }
}

s16 func_825060E0(void) {
    u32 var_a2;
    s32 i;
    s16 sp24[9];

    var_a2 = 0;

    for (i = 0; i < 9; i++) {
        if (D_8780FA50[i] == 0) {
            sp24[var_a2++] = i;
        }
    }

    if (var_a2 == 0) {
        var_a2 = 9;

        for (i = 0; i < 9; i++) {
            D_8780FA50[i] = 0;
            sp24[i] = i;
        }
    }

    return sp24[func_878001E8(var_a2)];
}
