#include "fragment62.h"
#include "src/17300.h"
#include "src/1C720.h"
#include "src/334D0.h"
#include "src/F420.h"

void func_843074A0(unk_D_84390010* arg0) {
    func_80017464(&arg0->unk_728.unk_000, arg0->unk_728.unk_180);
    func_8001BD04(&arg0->unk_728.unk_000, arg0->unk_728.unk_17C);
    func_8430753C(arg0->unk_728.unk_168);
}

void func_843074EC(unk_D_84390010* arg0) {
    arg0->unk_728.unk_170 = 0;
}

void func_843074F4(unk_D_84390010* arg0) {
    arg0->unk_728.unk_170 = 1;
}

void func_84307500(void) {
    D_84390010[0]->unk_728.unk_170 = 0;
    D_84390010[1]->unk_728.unk_170 = 0;
}

void func_8430751C(void) {
    D_84390010[0]->unk_728.unk_170 = 1;
    D_84390010[1]->unk_728.unk_170 = 1;
}

void func_8430753C(unk_D_84390010_728_0168* arg0) {
    arg0->unk_00.unk_01 |= 0x10;
}

void func_8430754C(unk_D_84390010* arg0) {
    s32 var_v0;

    if (arg0 == D_84390010[0]) {
        var_v0 = 0;
    } else {
        var_v0 = 1;
    }

    arg0->unk_728.unk_168->unk_20 = D_843847BC[var_v0].unk_04;
    arg0->unk_728.unk_168->unk_1C = D_843847BC[var_v0].unk_00;
    arg0->unk_728.unk_168->unk_1E = D_843847BC[var_v0].unk_02;

    arg0->unk_728.unk_178 = D_843847BC[var_v0].unk_14;

    arg0->unk_728.unk_168->unk_34 = D_843847BC[var_v0].unk_0C;
    arg0->unk_728.unk_168->unk_38 = D_843847BC[var_v0].unk_10;
    arg0->unk_728.unk_168->unk_2C = D_843847BC[var_v0].unk_08;
}

void func_843075D0(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    if (D_84390240.unk_00->unk_1C == 1) {
        func_8430751C();
    } else {
        func_84307500();
    }
    func_8430754C(arg0);
    func_8430754C(arg1);
}

void func_84307630(void) {
}

void func_84307638(unk_D_84390010* arg0) {
    s32 temp_v0;
    unk_D_84390010_728_0168* sp30;
    f32 tmp;
    f32 tmp2;

    sp30 = arg0->unk_728.unk_168;
    temp_v0 = func_84307F00(arg0);

    arg0->unk_728.unk_184 = D_84384578[temp_v0]->unk_0C;
    if (D_84384578[temp_v0]->unk_10 == 0xFF) {
        arg0->unk_728.unk_186 = D_84384578[temp_v0]->unk_0E * arg0->unk_728.unk_178;
        tmp = D_84384578[temp_v0]->unk_00.z * arg0->unk_728.unk_178;
    } else {
        arg0->unk_728.unk_186 = D_84384578[temp_v0]->unk_0E;
        tmp = D_84384578[temp_v0]->unk_00.z;
    }

    arg0->unk_728.unk_190 = tmp;
    arg0->unk_728.unk_188 = D_84384578[temp_v0]->unk_00.x;
    arg0->unk_728.unk_180 = D_84384578[temp_v0]->unk_12;
    tmp2 = D_84384578[temp_v0]->unk_00.y;
    arg0->unk_728.unk_194 = tmp2;

    func_8431AE7C(sp30, 
                  arg0->unk_728.unk_000.unk_024.x + arg0->unk_728.unk_190, 
                  arg0->unk_728.unk_000.unk_024.y + tmp2, 
                  arg0->unk_728.unk_000.unk_024.z, 
                  arg0->unk_728.unk_188, arg0->unk_728.unk_184, arg0->unk_728.unk_186);
}

void func_84307748(unk_D_84390010* arg0) {
    func_84307638(arg0);
}

void func_84307768(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, unk_D_86002F34_00C* arg2, unk_D_84390010* arg3) {
    arg1->unk_728.unk_168 = arg0;
    arg3->unk_728.unk_168 = arg2;
    func_843075D0(arg1, arg3);
    func_84307748(arg1);
    func_84307748(arg3);
}

void func_843077B0(unk_D_84390010* arg0, s32 arg1) {
    s16 var_a0;
    unk_D_84390010_728_0168* temp_v0;

    arg0->unk_728.unk_168->unk_00.unk_01 |= 1;
    arg0->unk_728.unk_000.unk_000.unk_01 |= 1;

    if (arg0->unk_728.unk_178 == 1) {
        if ((arg0->unk_728.unk_168->unk_1C == -0x48) && !(arg0->unk_654.unk_34 & 0x800)) {
            func_843074A0(arg0);
        }

        if ((func_800328D8(0) != 0) && (arg0->unk_728.unk_18C == 0)) {
            arg0->unk_728.unk_18C = 2;
            func_800328D0(0);
        }
        arg0->unk_728.unk_168->unk_1C = func_8001046C(arg0->unk_728.unk_168->unk_1C, 0x17, arg1, arg1);
    } else {
        if ((arg0->unk_728.unk_168->unk_1C == 0x15F) && !(arg0->unk_654.unk_34 & 0x800)) {
            func_843074A0(arg0);
        }

        arg0->unk_728.unk_168->unk_1C = func_8001046C(arg0->unk_728.unk_168->unk_1C, 0x103, arg1, arg1);

        if ((func_800328D8(1) != 0) && (arg0->unk_728.unk_18C == 0)) {
            arg0->unk_728.unk_18C = 2;
            func_800328D0(1);
        }
    }
}

void func_843078F4(unk_D_84390010* arg0, s32 arg1) {
    if (arg0->unk_728.unk_178 == 1) {
        arg0->unk_728.unk_18C = 0;
        arg0->unk_728.unk_168->unk_1C = func_8001046C(arg0->unk_728.unk_168->unk_1C, -0x48, arg1, arg1);
        if (arg0->unk_728.unk_168->unk_1C == -0x48) {
            arg0->unk_728.unk_168->unk_00.unk_01 &= ~1;
            arg0->unk_728.unk_000.unk_000.unk_01 &= ~1;
        }
    } else {
        arg0->unk_728.unk_18C = 0;
        arg0->unk_728.unk_168->unk_1C = func_8001046C(arg0->unk_728.unk_168->unk_1C, 0x15F, arg1, arg1);
        if (arg0->unk_728.unk_168->unk_1C == 0x15F) {
            arg0->unk_728.unk_168->unk_00.unk_01 &= ~1;
            arg0->unk_728.unk_000.unk_000.unk_01 &= ~1;
        }
    }
}

void func_843079C4(unk_D_84390010* arg0) {
    switch (arg0->unk_728.unk_170) {
        case 0:
            func_843078F4(arg0, 9);
            break;

        case 1:
            func_843077B0(arg0, 9);
            break;
    }
}

void func_84307A14(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    if (D_800AE540.unk_0000 != 0x10) {
        func_843079C4(arg0);
        func_843079C4(arg1);
    }
}

s32 func_84307A50(s32 arg0, unk_D_86002F34_00C* arg1, unk_D_86002F34_00C* arg2) {
    switch (arg0) {
        case 0:
            func_84307630();
            break;

        case 1:
        case 2:
            func_84307A14(D_84390010[0], D_84390010[1]);
            break;

        case 3:
            func_84307768(arg1, D_84390010[0], arg2, D_84390010[1]);
            break;
    }
    return 0;
}
