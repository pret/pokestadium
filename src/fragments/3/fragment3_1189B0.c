#include "fragment3.h"
#include "include/libc/math.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/1C720.h"
#include "src/20330.h"
#include "src/3FB0.h"
#include "src/controller.h"
#include "src/fragments/2/fragment2.h"

extern s16 D_87903DA4;
extern s16 D_87903DA8;
extern s16 D_87903DAC;
extern s16 D_87903DC0;
extern s16 D_87903DC4;
extern s16 D_87903DC8;
extern s16 D_87903DCC;
extern s16 D_87903DD0;

extern s16 D_87906040;
extern s16 D_87906044;
extern s16 D_87906048;
extern s16 D_8790604A;

extern s16 D_87906060;
extern s16 D_87906062;
extern s16 D_87906064;
extern s16 D_87906066;
extern Vec3s D_8790606C;
extern s16 D_87906072;
extern s16 D_87906076;
extern s16 D_87906078;
extern f32 D_8790607C;
extern f32 D_87906080;
extern Vec3f D_87906088;
extern s8 D_879060C4;
extern s8 D_879060C5;
extern s8 D_879060C6;
extern s8 D_879060C7;
extern s16 D_879060C8;


ret_func_80004454 func_87900020(void) {
    return func_87900020;
}

void func_8790002C(unk_func_8790002C* arg0, unk_func_8790002C* arg1) {
    sqrtf(SQ(arg1->unk_19C - arg0->unk_19C) + SQ(arg1->unk_1A4 - arg0->unk_1A4));
}

void func_87900070(unk_func_8790002C* arg0, unk_func_8790002C* arg1) {
    sqrtf(SQ(arg1->unk_19C - arg0->unk_19C) + SQ(arg1->unk_1A0 - arg0->unk_1A0) + SQ(arg1->unk_1A4 - arg0->unk_1A4));
}

s32 func_879000C4(unk_func_8790002C* arg0, unk_func_8790002C* arg1) {
    f32 var_fv0 = arg1->unk_19C - arg0->unk_19C;
    f32 var_fv1 = arg1->unk_1A0 - arg0->unk_1A0;
    f32 var_fa0 = arg1->unk_1A4 - arg0->unk_1A4;
    f32 var_fa1 = (arg0->unk_288 * arg0->unk_170) + (arg1->unk_288 * arg1->unk_170);
    s32 ret = 0;

    if (var_fv0 < 0.0f) {
        var_fv0 = -var_fv0;
    }

    if (var_fv1 < 0.0f) {
        var_fv1 = -var_fv1;
    }

    if (var_fa0 < 0.0f) {
        var_fa0 = -var_fa0;
    }

    if (var_fa1 < 0.0f) {
        var_fa1 = -var_fa1;
    }

    if (CB(var_fa0) < ((CB(var_fa1) - CB(var_fv0)) - CB(var_fv1))) {
        ret = 1;
    }

    return ret;
}

s32 func_879001A4(unk_func_8790002C* arg0, unk_func_8790002C* arg1) {
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fs0;
    f32 var_fv0;
    f32 var_fv1;
    f32 tmp;
    s32 var_v1;

    var_fv0 = arg1->unk_19C - arg0->unk_19C;
    var_fv1 = arg1->unk_1A0 - arg0->unk_1A0;
    var_fa0 = arg1->unk_1A4 - arg0->unk_1A4;
    var_v1 = 0;

    var_fa1 = (arg0->unk_288 * arg0->unk_170) + (arg1->unk_288 * arg1->unk_170);
    var_fs0 = ((arg0->unk_28C * arg0->unk_170) + (arg1->unk_28C * arg1->unk_170)) * 0.5f;

    var_fv0 = ABS(var_fv0);
    var_fv1 = ABS(var_fv1);
    var_fa0 = ABS(var_fa0);
    var_fa1 = ABS(var_fa1);
    var_fs0 = ABS(var_fs0);
    tmp = var_fs0 - var_fv1;

    if ((SQ(var_fa0) < (SQ(var_fa1) - SQ(var_fv0))) && (tmp > 0)) {
        var_v1 = 1;
    }

    return var_v1;
}

void func_879002B8(unk_func_8790002C* arg0, s16 arg1, s16 arg2, s16 arg3) {
    arg0->unk_248 = 1;
    arg0->unk_24A = arg1;
    arg0->unk_24C = arg2;
    arg0->unk_26A = arg3;
    arg0->unk_26C = 0;
    arg0->unk_26E = 0;
}

void func_879002FC(unk_func_8790002C* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_248 = 1;
    arg0->unk_24A = arg1;
    arg0->unk_24C = arg2;
    arg0->unk_26A = arg3;
    arg0->unk_26C = 0;
    arg0->unk_26E = arg4;
}

void func_87900344(unk_func_8790002C* arg0, s16 arg1, s16 arg2, s16 arg3) {
    arg0->unk_248 = 1;
    arg0->unk_24A = arg1;
    arg0->unk_24C = arg2;
    arg0->unk_26A = arg3;
    arg0->unk_26C = 1;
}

s32 func_87900384(unk_func_8790002C* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_248 == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_879003A0(unk_func_8790002C* arg0) {
    switch (arg0->unk_248) {
        case 1:
            func_8001BD04(&arg0->unk_000, arg0->unk_24A);
            if (arg0->unk_26C != 0) {
                func_800173DC(&arg0->unk_000, 0, arg0->unk_000.unk_040.unk_04, -0x10000);
                func_80017464(&arg0->unk_000, arg0->unk_000.unk_040.unk_04->unk_0A - 1);
            } else {
                func_800173DC(&arg0->unk_000, 0, arg0->unk_000.unk_040.unk_04, 0x10000);
                func_80017464(&arg0->unk_000, arg0->unk_26E);
                func_80017788(&arg0->unk_000);
                if (arg0->unk_24C != -1) {
                    func_8001BD9C(&arg0->unk_000, arg0->unk_24C);
                    func_80017804(&arg0->unk_000, arg0->unk_26E);
                }
            }
            arg0->unk_248++;
            break;

        case 2:
            if (arg0->unk_26C == 0) {
                if (func_800174E4(&arg0->unk_000) != 0) {
                    arg0->unk_248++;
                }
            } else {
                if (arg0->unk_000.unk_040.unk_08 == 0) {
                    arg0->unk_248++;
                }
            }
            break;

        case 3:
            if (arg0->unk_26A != 0) {
                func_8001BD04(&arg0->unk_000, 0);
            }
            arg0->unk_248 = 0;
            break;
    }
}

void func_879004F8(unk_D_86002F58_004_000* arg0) {
    func_80017464(arg0, arg0->unk_040.unk_04->unk_0A - 1);
}

void func_87900528(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_87900558(void) {
    D_87906044 = 0;
}

void func_87900564(unk_func_8790002C* arg0) {
    arg0->unk_1C0 = 0.0f;
    arg0->unk_1A8 = 0.0f;
    arg0->unk_190 = 0.0f;
    arg0->unk_1C4 = 0.0f;
    arg0->unk_1AC = 0.0f;
    arg0->unk_194 = 0.0f;
    arg0->unk_1C8 = 0.0f;
    arg0->unk_1B0 = 0.0f;
    arg0->unk_198 = 0.0f;
}

void func_87900594(unk_func_8790002C* arg0) {
    arg0->unk_1A8 = 0.0f;
    arg0->unk_1AC = 0.0f;
    arg0->unk_1B0 = 0.0f;
}

void func_879005AC(unk_func_8790002C* arg0) {
    arg0->unk_1C0 = 0.0f;
    arg0->unk_1C4 = 0.0f;
    arg0->unk_1C8 = 0.0f;
}

void func_879005C4(unk_func_8790002C* arg0) {
    arg0->unk_1FC = arg0->unk_1FC - arg0->unk_210;
    arg0->unk_1C0 = arg0->unk_1C0 + arg0->unk_1F8;
    arg0->unk_1C4 = arg0->unk_1C4 + (arg0->unk_1FC - arg0->unk_210);
    arg0->unk_1C8 = arg0->unk_1C8 + arg0->unk_200;
}

void func_8790060C(unk_func_8790002C* arg0) {
    arg0->unk_214 = arg0->unk_216 = arg0->unk_218 = 0;
    arg0->unk_21A = arg0->unk_21C = arg0->unk_21E = 0;
    arg0->unk_220 = arg0->unk_222 = arg0->unk_224 = 0;
    arg0->unk_226 = arg0->unk_228 = arg0->unk_22A = 0;
    arg0->unk_22C = arg0->unk_22E = arg0->unk_230 = 0;
    arg0->unk_232 = arg0->unk_234 = arg0->unk_236 = 0;
    arg0->unk_23E = arg0->unk_240 = arg0->unk_242 = arg0->unk_248 = 0;

    arg0->unk_254 = 0;
    arg0->unk_272 = 0;
    arg0->unk_238 = 0;
    arg0->unk_25A = 0;
    arg0->unk_2A8 = 0;
    arg0->unk_2A4 = 0;
    arg0->unk_2A2 = 0;
    arg0->unk_29A = 0;
    arg0->unk_2AA = 0;
    arg0->unk_29C = 0;
    arg0->unk_2A0 = 0;
    arg0->unk_29E = 0;
    arg0->unk_296 = 0;
    arg0->unk_298 = 0;

    arg0->unk_16C = arg0->unk_170 = arg0->unk_174 = 1.0f;

    arg0->unk_198 = 0.0f;
    arg0->unk_194 = 0.0f;
    arg0->unk_190 = 0.0f;
    arg0->unk_1B0 = 0.0f;
    arg0->unk_1AC = 0.0f;
    arg0->unk_1A8 = 0.0f;
    arg0->unk_1BC = 0.0f;
    arg0->unk_1B8 = 0.0f;
    arg0->unk_1B4 = 0.0f;
    arg0->unk_1C8 = 0.0f;
    arg0->unk_1C4 = 0.0f;
    arg0->unk_1C0 = 0.0f;
    arg0->unk_1D4 = 0.0f;
    arg0->unk_1D0 = 0.0f;
    arg0->unk_1CC = 0.0f;
    arg0->unk_1E4 = 0.0f;
    arg0->unk_210 = 0.0f;
    arg0->unk_20C = 0.0f;
    arg0->unk_208 = 0.0f;
    arg0->unk_204 = 0.0f;
    arg0->unk_200 = 0.0f;
    arg0->unk_1FC = 0.0f;
    arg0->unk_1F8 = 0.0f;
    arg0->unk_1F4 = 0.0f;
    arg0->unk_1F0 = 0.0f;
    arg0->unk_1EC = 0.0f;
    arg0->unk_284 = 0.0f;
    arg0->unk_280 = 0.0f;
    arg0->unk_27C = 0.0f;
    arg0->unk_274 = 0.0f;

    arg0->unk_260 = arg0->unk_262 = arg0->unk_264 = arg0->unk_266 = 0;
    arg0->unk_290 = arg0->unk_292 = arg0->unk_294 = 0;
}

void func_87900770(unk_func_8790002C* arg0) {
    arg0->unk_190 = arg0->unk_19C = arg0->unk_1A8 + arg0->unk_1C0;
    arg0->unk_194 = arg0->unk_1A0 = arg0->unk_1AC + arg0->unk_1C4;
    arg0->unk_198 = arg0->unk_1A4 = arg0->unk_1B0 + arg0->unk_1C8;

    arg0->unk_1A0 = arg0->unk_1A0 + arg0->unk_1E4;

    arg0->unk_214 = arg0->unk_21A + arg0->unk_226 + arg0->unk_232;
    arg0->unk_216 = arg0->unk_21C + arg0->unk_228 + arg0->unk_234;
    arg0->unk_218 = arg0->unk_21E + arg0->unk_22A + arg0->unk_236;
}

void func_87900808(unk_func_8790002C* arg0) {
    arg0->unk_000.unk_030.x = arg0->unk_16C;
    arg0->unk_000.unk_030.y = arg0->unk_170;
    arg0->unk_000.unk_030.z = arg0->unk_174;

    arg0->unk_000.unk_024.x = arg0->unk_190;
    arg0->unk_000.unk_024.y = arg0->unk_194;
    arg0->unk_000.unk_024.z = arg0->unk_198;

    arg0->unk_000.unk_01E.x = arg0->unk_214;
    arg0->unk_000.unk_01E.y = arg0->unk_216;
    arg0->unk_000.unk_01E.z = arg0->unk_218;
}

void func_87900854(void) {
    s16* ptr = D_8780FA30;

    D_87903DA4 = 0;
    D_87903DA8 = 0;
    D_87903DAC = 0;
    D_87906040 = 0;
    D_87906048 = 0;
    D_8790604A = 0;
    D_87903DC0 = 0;
    D_87903DC4 = 0;
    D_87903DC8 = 0;
    D_87903DCC = 0;
    D_87903DD0 = 0;
    D_87906072 = 0;

    func_878029C0();
    func_87802528();

    D_879060C4 = ptr[0];
    D_879060C5 = ptr[1];
    D_879060C6 = ptr[2];
    D_879060C7 = ptr[3];

    D_879060C8 = 0xFF;
}

void func_87900920(void) {
    D_8790607C = D_87906064;
    D_87906080 = D_87906066;

    D_87906088.x = D_8790606C.x;
    D_87906088.y = D_8790606C.y;
    D_87906088.z = D_8790606C.z;

    D_87906076 = D_87906060;
    D_87906078 = D_87906062;
}

void func_879009B4(void) {
    D_87906064 = D_8790607C;
    D_87906066 = D_87906080;

    D_8790606C.x = D_87906088.x;
    D_8790606C.y = D_87906088.y;
    D_8790606C.z = D_87906088.z;

    D_87906060 = D_87906076;
    D_87906062 = D_87906078;
}
