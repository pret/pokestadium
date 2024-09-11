#include "490A0.h"
#include "src/38BB0.h"
#include "src/45720.h"
#include "src/3D140.h"
#include "src/373A0.h"

void func_800484A0(s32 arg0) {
    func_80039354(arg0);
}

s32 func_800484C0(s32 arg0) {
    return func_80039204(arg0);
}

s32 func_800484E0(void) {
    s32 i;
    s32 temp_v0;
    s32 var_s1;

    var_s1 = 0;
    if (D_800FC818 != D_800FC814) {
        var_s1 = D_800FC814 - D_800FC818;
    }

    for (i = 0; i < 2; i++) {
        if (func_80044E54(i) != 0) {
            var_s1 += 100;
        }
    }

    temp_v0 = func_8003D494();
    if (temp_v0 != 0) {
        var_s1 += temp_v0 * 1000;
    }

    return var_s1;
}

s32 func_80048574(void) {
    return D_800FC818;
}

s32 func_80048580(void) {
    return D_800FC81C;
}
