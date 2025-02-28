#include "fragment23.h"
#include "src/1CF30.h"
#include "src/29BA0.h"
#include "src/3FB0.h"
#include "src/memory.h"
#include "src/stage_loader.h"

unk_D_800AC870* func_88200020(void) {
    unk_D_800AC870* sp1C;

    main_pool_push_state('TERM');

    sp1C = func_8001E94C(0x1C, 0);

    ASSET_LOAD(D_04000000, fragment29_misc_1, 0);
    FRAGMENT_LOAD(fragment26);
    FRAGMENT_LOAD(fragment29);

    func_80007754();
    return sp1C;
}

void func_882000E4(void) {
    func_8000771C();

    main_pool_pop_state('TERM');
}

s32 func_88200110(UNUSED s32 arg0, UNUSED s32 arg1) {
    func_8820C700(func_88200020(), 1);
    func_80007990(1);
    func_80006CB4(0xA);
    func_882000E4();

    FRAGMENT_LOAD_AND_CALL2(fragment22, 1, 0);
    return 0x25;
}

s32 func_88200190(s32 arg0, s32 arg1) {
    unk_D_800AC870* temp_s0;
    s32 var_s1;

    if (arg0 == 5) {
        return func_88200110(arg0, arg1);
    }
    temp_s0 = func_88200020();

    var_s1 = func_8820104C(arg0, arg1);
    while (var_s1 != 0) {
        switch (var_s1) {
            case 1:
                func_8820C700(temp_s0, 0);
                break;

            case 2:
                func_8821483C(temp_s0);
                break;

            case 3:
                func_88205F1C(temp_s0);
                break;
        }
        var_s1 = func_8820104C(var_s1, arg1);
    }

    func_882000E4();

    return 0x25;
}
