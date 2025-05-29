#include "fragment62.h"
#include "src/1C720.h"

void func_84331DA0(unk_D_8140E720* arg0) {
    func_8432FEEC(arg0);
    func_814081BC(arg0);
}

void func_84331DC8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84331DA0(arg0);
            break;

        case 2:
            if (func_8140D7C8(arg0, arg0->unk_CF, func_8140C068(arg0)) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408158(arg0);
            break;
    }

    func_8432FEC4(arg0);
}

void func_84331E64(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BF4C(arg0, arg0->unk_A6);
    func_814081BC(arg0);
}

void func_84331EAC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84331E64(arg0);
            break;

        case 2:
            if (func_8140BF60(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408158(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void func_84331F64(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BF4C(arg0, arg0->unk_CE);
    func_814081BC(arg0);
}

void func_84331FAC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84331F64(arg0);
            break;

        case 2:
            if (func_8140BF60(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_8140BDD0(arg0);
            break;

        case 4:
            if (func_8140BF60(arg0, 0, arg0->unk_AA) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void func_8433209C(void) {
}

void func_843320A4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84331F64(arg0);
            break;

        case 2:
            func_8140BDD0(arg0);
            break;

        case 3:
            if (func_8140BF60(arg0, 0, arg0->unk_AA) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void func_84332174(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BF4C(arg0, arg0->unk_A6);
    func_814081BC(arg0);
}

void func_843321BC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84332174(arg0);
            break;

        case 2:
            if (func_8140D7C8(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                func_8140BF4C(arg0, 0);
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void func_8433227C(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BF4C(arg0, arg0->unk_A6);
    func_814081BC(arg0);
}

void func_843322C4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433227C(arg0);
            break;

        case 2:
            if (func_8140D7C8(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void func_8433237C(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BF4C(arg0, 0);
    func_814081BC(arg0);
}

void func_843323BC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433237C(arg0);
            break;

        case 2:
            func_8140BF98(arg0, arg0->unk_A6, arg0->unk_CE);
            break;

        case 3:
            if (func_8140D7C8(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_8140BF98(arg0, 0, arg0->unk_CE);
            break;

        case 5:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void func_843324A4(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BF4C(arg0, arg0->unk_A6);
    func_814081BC(arg0);
}

void func_843324EC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843324A4(arg0);
            break;

        case 2:
            if (func_8140D7C8(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_8140BF98(arg0, 0, arg0->unk_CE);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void func_843325C4(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BF4C(arg0, 0);
    func_814081BC(arg0);
}

void func_84332604(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843325C4(arg0);
            break;

        case 2:
            if (func_8140BF60(arg0, arg0->unk_A6, arg0->unk_CE) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            if (func_8140D7C8(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->unk_AE);
    }
}

void func_843326EC(unk_D_8140E720* arg0) {
    func_8140D530(arg0, D_8140E538[func_81400A78(6)]);
    func_8140BEEC(arg0, D_8140E538[func_81400A78(6)]);
    func_8140BC20(arg0, arg0->unk_CD);

    if (arg0->unk_AA == 0) {
        arg0->unk_AA = 1;
    }

    func_8140BCA8(arg0, 0xFF / arg0->unk_AA);
    func_814081BC(arg0);
}

void func_843327B8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843326EC(arg0);
            break;

        case 2:
            func_8140D7C8(arg0, arg0->unk_CF, arg0->unk_AA);
            if (func_8140BDAC(arg0) != 0) {
                func_8140BCA8(arg0, 0xFF / arg0->unk_AA);
                func_8140BEEC(arg0, D_8140E538[func_81400A78(6)]);
            }
            func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
            break;
    }
}

void func_843328A8(unk_D_8140E720* arg0) {
    func_8140D530(arg0, D_8140E538[0]);
    func_8140BF4C(arg0, 1);
    func_8140BEEC(arg0, D_8140E538[1]);
    func_8140BC20(arg0, arg0->unk_CD);

    if (arg0->unk_AA == 0) {
        arg0->unk_AA = 1;
    }

    func_8140BE14(arg0, 0xFF / arg0->unk_AA);
    func_814081BC(arg0);
}

void func_84332964(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843328A8(arg0);
            break;

        case 2:
            func_8140BDD0(arg0);
            if (func_8140BE6C(arg0) != 0) {
                func_8140BE14(arg0, 0xFF / arg0->unk_AA);
                arg0->unk_AE = (arg0->unk_AE + 1) % 6;
                func_8140BEEC(arg0, D_8140E538[arg0->unk_AE]);
            }
            func_8140D7C8(arg0, arg0->unk_CF, arg0->unk_AA);
            func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
            break;

        case 3:
            if (func_8140BC2C(arg0, 0, 8) != 0) {
                func_814081BC(arg0);
            }
            func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84332AD8(unk_D_8140E720* arg0) {
    arg0->prim_a = arg0->unk_A6;
    func_814081BC(arg0);
}

void func_84332AFC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84332AD8(arg0);
            break;

        case 2:
            if (func_8140BC2C(arg0, arg0->unk_CD, arg0->unk_AA) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8001BE78(&arg0->unk_10->unk_000, arg0->prim_a);
    }
}

void func_84332BA4(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0);
    func_814081BC(arg0);
}

void func_84332BE4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84332BA4(arg0);
            break;

        case 2:
            func_8140BC2C(arg0, 0x80, 4);
            break;

        case 3:
            if (func_8140BC2C(arg0, 0, 8) != 0) {
                func_81408158(arg0);
            }
            break;
    }

    func_8001BE34(&arg0->unk_10->unk_000, arg0->prim_r, arg0->prim_g, arg0->prim_b, arg0->prim_a);
}

void func_84332C90(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0);
    func_814081BC(arg0);
}

void func_84332CD0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84332C90(arg0);
            break;

        case 2:
            func_8140BC5C(arg0, arg0->unk_CD, arg0->unk_AA);
            break;

        case 3:
            func_8140BDD0(arg0);
            break;

        case 4:
            if (func_8140BC2C(arg0, 0, arg0->unk_AA) != 0) {
                func_81408150(arg0);
            }
            break;
    }
}

void func_84332D68(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, arg0->unk_CD);
    func_814081BC(arg0);
}

void func_84332DB0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84332D68(arg0);
            break;

        case 2:
            func_8140BDD0(arg0);
            break;

        case 3:
            if (func_8140BC2C(arg0, 0, arg0->unk_AA) != 0) {
                func_81408150(arg0);
            }
            break;
    }
}

void func_84332E2C(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0);
    func_814081BC(arg0);
}

void func_84332E6C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84332E2C(arg0);
            break;

        case 2:
            func_8140BC5C(arg0, arg0->unk_CD, arg0->unk_AA);
            break;

        case 3:
            if (func_8140BDAC(arg0) != 0) {
                func_81408150(arg0);
            }
            break;
    }
}

void func_84332EE8(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, arg0->unk_CD);
    func_814081BC(arg0);
}

void func_84332F30(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84332EE8(arg0);
            break;

        case 2:
            if (func_8140BDAC(arg0) != 0) {
                func_81408158(arg0);
            }
            break;
    }
}

void func_84332F90(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_84332FD0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84332F90(arg0);
            break;

        case 2:
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140D7C8(arg0, arg0->unk_CD, arg0->unk_AA);
            if (func_8140BC2C(arg0, 0, arg0->unk_AA) != 0) {
                func_81408150(arg0);
            }
            break;
    }
}

void func_84333060(unk_D_8140E720* arg0) {
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0);
    func_814081BC(arg0);
}

void func_843330A0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84333060(arg0);
            break;

        case 2:
            func_8140D7C8(arg0, arg0->unk_CD, arg0->unk_AA);
            func_8140BC5C(arg0, 0xFF, arg0->unk_AA);
            break;

        case 3:
            if (func_8140BDAC(arg0) != 0) {
                func_81408150(arg0);
            }
            break;
    }
}
