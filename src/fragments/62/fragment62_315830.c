#include "fragment62.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/1C720.h"

void func_8432AF70(unk_D_84390010* arg0) {
    UNUSED s32 pad[2];
    unk_func_80026268_arg0* ptr;
    unk_D_84390010_654* sp2C;
    unk_D_800FCB18* sp28;
    unk_D_8438E7B0_A50* sp20;
    s32 idx = func_84307F00(arg0);

    sp28 = &arg0->unk_654.unk_38;
    sp2C = &arg0->unk_654;
    ptr = &arg0->unk_724->unk_01C[sp2C->unk_08];
    sp20 = &D_84384570[idx]->unk_A80;

    if ((ptr->unk_05 & 0x20) && (sp2C->unk_34 & 2)) {
        arg0->unk_000.unk_000.unk_02 &= ~0x20;
    }

    if ((sp28->unk_15 & 0x20) && (ptr->unk_05 & 0x20) && !(sp2C->unk_34 & 2) &&
        ((arg0->unk_000.unk_040.unk_08 >> 0x10) >= 3)) {
        func_8001BD04(&arg0->unk_000, sp20->unk_00);
        func_80017464(&arg0->unk_000, 4);
        func_8001BD9C(&arg0->unk_000, sp20->unk_01);
        func_80017804(&arg0->unk_000, 3);
        arg0->unk_000.unk_000.unk_02 &= ~0x20;
        func_843061EC(arg0, 2);
        func_8432C7A0(1, arg0);
        func_8432BF88(arg0, 0x13);
    }
}

void func_8432B0A4(unk_D_84390010* arg0) {
    unk_D_8438E7B0_A50* ptr = &D_84384570[func_84307F00(arg0)]->unk_A50;

    func_8001BD04(&arg0->unk_000, ptr->unk_00);
}

void func_8432B0E4(unk_D_84390010* arg0) {
    if (arg0->unk_654.unk_34 & 2) {
        func_8432C80C(1, arg0);
        arg0->unk_000.unk_000.unk_02 |= 0x20;
        func_84306200(arg0, 2);
        func_8432B0A4(arg0);
    }
}

void func_8432B13C(unk_D_84390010* arg0) {
    unk_func_80026268_arg0* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    if (arg0->unk_654.unk_34 & 2) {
        ptr->unk_05 = 0;
        func_8432C80C(1, arg0);
        arg0->unk_000.unk_000.unk_02 |= 0x20;
        func_84306200(arg0, 2);
        func_8432B0A4(arg0);
    }
}

void func_8432B1BC(unk_D_84390010* arg0) {
    if ((arg0->unk_654.unk_34 & 2) && !(arg0->unk_654.unk_38.unk_15 & 0x20)) {
        func_8432C80C(1, arg0);
        arg0->unk_000.unk_000.unk_02 |= 0x20;
        func_84306200(arg0, 2);
        func_8432B0A4(arg0);
    }
}

void func_8432B228(unk_D_84390010* arg0) {
    unk_D_84390010_654* sp24 = &arg0->unk_654;
    unk_D_800FCB18* sp28 = &sp24->unk_38;
    unk_func_80026268_arg0* sp2C = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    if ((D_84390240.unk_00->unk_38 != 0xB) || (D_84390240.unk_00->unk_20 >= 6)) {
        if ((sp2C->unk_05 & 7) && (sp28->unk_15 & 7) && !(arg0->unk_654.unk_34 & 1)) {
            func_84305A74(arg0, 0xAF, 2);
            func_8432C7A0(3, arg0);
            func_8432BF88(arg0, 0x32);
            func_843061EC(arg0, 1);
        }

        if (!(sp2C->unk_05 & 7) && (sp24->unk_34 & 1)) {
            if (D_84384570[func_84307F00(arg0)]->unk_B81 == 0xFF) {
                sp24->unk_36 = 0;
                func_843058C4(arg0, 0xA5);
            } else {
                func_84305A74(arg0, 0xB8, 1);
            }
            func_8432C80C(3, arg0);
            func_84306200(arg0, 1);
        }
    }
}

void func_8432B38C(unk_D_84390010* arg0) {
    unk_func_80026268_arg0* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    if (arg0->unk_654.unk_34 & 1) {
        ptr->unk_05 = 0;
        if (D_84384570[func_84307F00(arg0)]->unk_B81 == 0xFF) {
            arg0->unk_654.unk_36 = 0;
            func_843058C4(arg0, 0xA5);
        } else {
            func_84305A74(arg0, 0xB8, 1);
        }
        func_8432C80C(3, arg0);
        func_84306200(arg0, 1);
    }
}

void func_8432B448(unk_D_84390010* arg0) {
    if (arg0->unk_654.unk_34 & 1) {
        func_8432C80C(3, arg0);
        func_84306200(arg0, 1);
    }
}
