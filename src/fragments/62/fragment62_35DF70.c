#include "fragment62.h"
#include "src/2E110.h"

typedef void (*func_D_8438AE50)(void);

static const char D_8438DC80[] = "は\nこんらんした";
static const char D_8438DC90[] = "SP %d\n";
static const char D_8438DC98[] = "index %d  step %d\n";
static const char D_8438DCAC[] = "index %d  step %d\n";
static const char D_8438DCC0[] = "index %d\n";
static const char D_8438DCCC[] = "paramStep %d index %d  step %d\n";
static const char D_8438DCEC[] = "\n%%%%%%%%%%%%%%%%%%%%%%%\n";
static const char D_8438DD08[] = "INDEX %d   WARIKOMI %d\n";
static const char D_8438DD20[] = "%%%%%%%%%%%%%%%%%%%%%%%\n\n";
static const char D_8438DD3C[] = "FAIL\n";
static const char D_8438DD44[] = "index %d\n";
static const char D_8438DD50[] = "index %d\n";
static const char D_8438DD5C[] = "FAIL\n";
static const char D_8438DD64[] = "FAIL2\n";
static const char D_8438DD6C[] = "FAIL3\n";
static const char D_8438DD74[] = "offp->count1 %d\n";
static const char D_8438DD88[] = "\n\n";
static const char D_8438DD8C[] = "******** spAttackMain ********\n";
static const char D_8438DDAC[] = "!!!! SPATTACK Num %d!!!!\n";
static const char D_8438DDC8[] = "******** spAttackMainEnd ********\n";

static char* D_8438AE50 = D_8438DC80;
static func_D_8438AE50 D_8438AE54[] = {
    func_84373754, func_84373A30, func_84373D04, func_84373E60, func_84373E60, func_84373E60, func_84373E24,
    func_84373D04, NULL,          func_843744F0, func_843744F0, func_843744F0, func_843744F0, func_843744F0,
    func_843744F0, func_84375D78, NULL,          func_8437483C, func_8437483C, func_8437483C, func_8437483C,
    func_8437483C, func_8437483C, func_84375DA4, func_84375E6C, func_84374C9C, func_84374D08, func_84374D58,
    func_84374E08, func_84374E08, func_84374EE4, func_84373754, func_84373A30, func_84373E60, func_84373E60,
    func_84373E60, func_84374EE4, func_84374FD4, func_84375038, NULL,          NULL,          func_843751F8,
    func_84375038, func_84374E08, NULL,          func_843752C0, func_84375384, func_84375424, func_843755E8,
    func_843744F0, func_843744F0, func_843744F0, func_843744F0, func_843744F0, func_843744F0, func_8437600C,
    func_84376258, func_8437483C, func_8437483C, func_8437483C, func_8437483C, func_8437483C, func_8437483C,
    func_843765E8, func_843765E8, func_84373A30, func_84375700, func_8437483C, func_8437483C, func_8437483C,
    func_8437483C, func_8437483C, func_8437483C, func_8437483C, func_8437483C, func_84375508, func_84374E08,
    NULL,          func_84375894, func_843759C4, func_843759DC, func_843759F4, NULL,          func_84375B1C,
    func_84375C24, func_84375C60, NULL,
};

u16 func_843736B0(u16* arg0, u16 arg1, u8 arg2) {
    *arg0 = (arg1 * D_8438ACB8[arg2 - 1].unk_00) / D_8438ACB8[arg2 - 1].unk_01;

    if (*arg0 == 0) {
        *arg0 = 1;
    }

    if (*arg0 > 999) {
        *arg0 = 999;
    }

    return *arg0;
}

void func_84373754(void) {
    s32 sp24;
    s32 var_v1;

    D_84390240.unk_00->unk_48 = 0x16;
    sp24 = D_843C523C->unk_4D & 0x20;
    D_843C523C->unk_4D &= ~0x20;

    if (sp24 == 0) {
        if (D_843C523C->unk_15 & 7) {
            D_843C4E44 = 0;
            func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
            func_843179F4(D_843901A0->unk_088, -0x80);
            return;
        }

        if (D_843C523C->unk_15 == 0) {
            func_843708CC();
            if ((D_843C4DA4 == 0) &&
                ((func_84308BD0(D_84390010[!D_84390240.unk_00->unk_2C]) == 0) || (D_8438AC60[0] == 2))) {
                goto block_9;
            }
        }
        D_843C4DC4 = 0;
        D_843C4DA4 = 1;
        D_843C4E44 = 0;
        func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_088, -0x7F);
        return;
    }

block_9:
    if ((func_84308BD0(D_84390010[!D_84390240.unk_00->unk_2C]) != 0) && (D_8438AC60[0] != 2)) {
        D_843C4E44 = 0;
        func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_088, -0x7F);
        if ((sp24 != 0) && (D_8438AC60[0] == 1)) {
            D_843C523C->unk_4D |= 0x20;
        }
    } else {
        do {
            if (D_8438AC60[0] == 2) {
                var_v1 = func_8436F6D8() & 7;
            } else {
                var_v1 = func_8436F6D8() & 3;
            }
        } while (var_v1 == 0);
        D_843C4DA4 = 0;
        D_843C523C->unk_15 = var_v1;
        func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_088, -0x7E);
    }
}

void func_84373A30(void) {
    char* sp1C = D_843901A0->unk_088;

    if (!(D_843C523C->unk_4D & 0x10) && (D_843C523C->unk_15 == 0) && (D_843C523C->unk_16[6] != 3) &&
        (D_843C523C->unk_16[7] != 3)) {
        switch (D_843C5238->unk_44.unk_01) {
            case 2:
                if (D_84390240.unk_00->unk_48 != 0x18) {
                    D_84390240.unk_00->unk_48 = 0;
                    sp1C = D_843901A0->unk_208;
                } else {
                    sp1C = D_843901A0->unk_308;
                }

                if (func_8436F6D8() >= 0x34) {
                    return;
                }
                break;

            case 33:
                D_84390240.unk_00->unk_48 = 0;
                sp1C = D_843901A0->unk_208;
                if (func_8436F6D8() >= 0x67) {
                    return;
                }
                break;

            default:
                D_84390240.unk_00->unk_48 = 0x16;
                D_843C4DEC = 0xA;
                func_843708CC();
                if (D_843C4DA4 != 0) {
                    func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
                    func_843179F4(sp1C, -0x7D);
                    return;
                }
                break;
        }

        D_843C523C->unk_15 |= 8;
        if (D_843C5238->unk_44.unk_00 == 0x5C) {
            D_843C523C->unk_4E |= 1;
            D_843C523C->unk_51 = 0;
            func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
            func_843179F4(sp1C, -0x7C);
        } else {
            func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
            func_843179F4(sp1C, -0x7B);
        }
    } else if (D_843C5238->unk_44.unk_01 == 0x42) {
        if (D_84390240.unk_00->unk_48 != 0x18) {
            D_843C4DA4 = 1;
            D_84390240.unk_00->unk_48 = 0x16;
            D_843C4E44 = 0;
        }
        func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
        func_843179F4(sp1C, -0x7A);
    }
}

void func_84373D04(void) {
    D_843C4DC4 /= 2;
    if (D_843C4DC4 == 0) {
        D_843C4DC4 = 1;
    }

    if (D_843C5238->unk_28 < D_843C5238->unk_0C + D_843C4DC4) {
        D_843C5238->unk_0C = D_843C5238->unk_28;
    } else {
        D_843C5238->unk_0C += D_843C4DC4;
    }

    if (D_843C5238->unk_44.unk_01 == 8) {
        func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_208, -0x79);
    } else {
        func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_208, -0x78);
    }
}

void func_84373E24(void) {
    D_84390240.unk_00->unk_48 = 0x1E;
    D_843C5238->unk_0C = 0;
    D_843C5238->unk_15 = 0;
    D_843C5238->unk_4D &= ~0x80;
}

void func_84373E60(void) {
    unk_D_800FCB18* temp_a2 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654.unk_38;
    unk_D_84390010_654* temp_a0 = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654;

    if (D_843C523C->unk_4D & 0x10) {
        return;
    }

    if (D_843C523C->unk_15 != 0) {
        if ((D_843C523C->unk_15 & 0x20) && (D_843C5238->unk_44.unk_03 == 0x14)) {
            D_843C523C->unk_15 = 0;
            if (temp_a0->unk_14 != 4) {
                temp_a2->unk_5A = temp_a2->unk_1F[temp_a0->unk_0C];
            } else {
                temp_a0->unk_14 = 0;
                temp_a0->unk_0C = 0;
                temp_a2->unk_5A = 0xA5;
            }
            func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
            func_843179F4(D_843901A0->unk_088, -0x77);
        }
        return;
    }

    if ((D_843C523C->unk_16[6] != (*D_843C5238).unk_44.unk_03) &&
        (D_843C523C->unk_16[7] != (*D_843C5238).unk_44.unk_03)) {
        if ((D_843C5238->unk_44.unk_01 < 7) || ((D_8438AC60[0] != 2) && (D_843C5238->unk_44.unk_00 == 0x3B))) {
            if (func_8436F6D8() >= 0x1A) {
                return;
            }
        } else if (func_8436F6D8() >= 0x4D) {
            return;
        }

        switch (D_843C5238->unk_44.unk_01) {
            case 4:
            case 34:
                D_843C523C->unk_15 = 0x10;
                func_84370B44(D_84390010[!D_84390240.unk_00->unk_2C]);
                func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
                func_843179F4(D_843901A0->unk_208, -0x76);
                break;

            case 5:
            case 35:
                if (func_84308A4C(D_84390010[!D_84390240.unk_00->unk_2C]) == 0) {
                    D_843C523C->unk_4D &= ~0x20;
                    D_843C523C->unk_15 = 0x20;
                    func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
                    func_843179F4(D_843901A0->unk_208, -0x75);
                }
                break;

            case 6:
            case 36:
                D_843C523C->unk_15 = 0x40;
                func_84370B0C(D_84390010[!D_84390240.unk_00->unk_2C]);
                func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
                func_843179F4(D_843901A0->unk_208, -0x74);
                break;
        }
    }
}

void func_843741C4(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 var_a3;
    u16* sp1C;
    u16* sp18;

    D_84390240.unk_00->unk_4C = 0xA;

    var_a3 = 1;
    sp24 = D_843C5238->unk_44.unk_01 - 0xA;

    if (sp24 >= 8) {
        var_a3 = 2;
        sp24 -= 0x28;
    }

    if (D_843C5238->unk_5C[sp24] != 0xD) {
        D_843C5238->unk_5C[sp24] += var_a3;
        if (D_843C5238->unk_5C[sp24] >= 0xE) {
            D_843C5238->unk_5C[var_a3] = 0xD;
        }

        sp28 = 0;
        sp2C = 0;

        if (sp24 < 4) {
            switch (sp24) {
                case 0:
                    sp18 = &D_843C5238->unk_38;
                    sp1C = &D_843C5238->unk_2A;
                    sp2C = 1;
                    break;

                case 1:
                    sp18 = &D_843C5238->unk_3A;
                    sp1C = &D_843C5238->unk_2C;
                    break;

                case 2:
                    sp18 = &D_843C5238->unk_3C;
                    sp1C = &D_843C5238->unk_2E;
                    sp28 = 1;
                    break;

                case 3:
                    sp18 = &D_843C5238->unk_3E;
                    sp1C = &D_843C5238->unk_30;
                    break;
            }

            if (*sp1C != 0x3E7) {
                *sp1C = (*sp18 * D_8438ACB8[D_843C5238->unk_5C[sp24] - 1].unk_00) /
                        D_8438ACB8[D_843C5238->unk_5C[sp24] - 1].unk_01;
                if (*sp1C >= 0x3E8) {
                    *sp1C = 0x3E7;
                }
            } else {
                goto block_29;
            }
        }

        if (D_843C5238->unk_44.unk_00 == 0x6B) {
            D_843C5238->unk_56 = 1;
        }

        if (var_a3 == 2) {
            func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
            func_843179F4(D_843901A0->unk_2C8, sp24 + 0x8D);
        } else {
            func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
            func_843179F4(D_843901A0->unk_2C8, sp24 + 0x93);
        }

        if ((sp28 != 0) || (D_8438AC60[0] != 1)) {
            func_84370B0C(D_84390010[!D_84390240.unk_00->unk_2C]);
        }

        if ((sp2C != 0) || (D_8438AC60[0] != 1)) {
            func_84370B44(D_84390010[!D_84390240.unk_00->unk_2C]);
        }
    } else {
    block_29:
        func_843179F4(D_843901A0->unk_2C8, -0x67);
    }
}

void func_843744F0(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 var_a3;
    u16* sp1C;
    u16* sp18;

    if (D_843C5238->unk_44.unk_00 == 0x6E) {
        D_84390240.unk_00->unk_48 = 0x26;
    } else {
        D_84390240.unk_00->unk_48 = 7;
    }

    var_a3 = 1;
    sp24 = D_843C5238->unk_44.unk_01 - 0xA;
    if (sp24 >= 8) {
        var_a3 = 2;
        sp24 -= 0x28;
    }

    if (D_843C5238->unk_5C[sp24] != 0xD) {
        D_843C5238->unk_5C[sp24] += var_a3;
        if (D_843C5238->unk_5C[sp24] >= 0xE) {
            D_843C5238->unk_5C[sp24] = 0xD;
        }

        sp28 = 0;
        sp2C = 0;

        if (sp24 < 4) {
            switch (sp24) {
                case 0:
                    sp18 = &D_843C5238->unk_38;
                    sp1C = &D_843C5238->unk_2A;
                    sp2C = 1;
                    break;

                case 1:
                    sp18 = &D_843C5238->unk_3A;
                    sp1C = &D_843C5238->unk_2C;
                    break;

                case 2:
                    sp18 = &D_843C5238->unk_3C;
                    sp1C = &D_843C5238->unk_2E;
                    sp28 = 1;
                    break;

                case 3:
                    sp18 = &D_843C5238->unk_3E;
                    sp1C = &D_843C5238->unk_30;
                    break;
            }

            if (*sp1C != 0x3E7) {
                *sp1C = (*sp18 * D_8438ACB8[D_843C5238->unk_5C[sp24] - 1].unk_00) /
                        D_8438ACB8[D_843C5238->unk_5C[sp24] - 1].unk_01;
                if (*sp1C >= 0x3E8) {
                    *sp1C = 0x3E7;
                }
            } else {
                goto block_32;
            }
        }

        if (D_843C5238->unk_44.unk_00 == 0x6B) {
            D_843C5238->unk_56 = 1;
        }

        if (var_a3 == 2) {
            func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
            func_843179F4(D_843901A0->unk_088, sp24 + 0x8D);
        } else {
            func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
            func_843179F4(D_843901A0->unk_088, sp24 + 0x93);
        }

        if ((sp28 != 0) || (D_8438AC60[0] != 1)) {
            func_84370B0C(D_84390010[D_84390240.unk_00->unk_2C]);
        }

        if ((sp2C != 0) || (D_8438AC60[0] != 1)) {
            func_84370B44(D_84390010[D_84390240.unk_00->unk_2C]);
        }
    } else {
    block_32:
        D_843C4E45 = 0;
        func_843179F4(D_843901A0->unk_088, -0x67);
    }
}

void func_8437483C(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    u16* sp1C;
    u16* sp18;

    if (D_843C5238->unk_44.unk_01 < 0x44) {
        D_84390240.unk_00->unk_48 = 0x1A;
    } else {
        D_84390240.unk_00->unk_1A = 3;
    }

    if (D_843C523C->unk_4D & 0x10) {
        goto end;
    }

    sp24 = D_843C5238->unk_44.unk_01;
    sp20 = 1;

    if (sp24 >= 0x44) {
        if (func_8436F6D8() < 0x55) {
            sp24 -= 0x44;
            goto block_14;
        }
    } else {
        func_843708CC();

        if (D_843C4DA4 != 0) {
            goto end;
        }

        if (D_843C523C->unk_4C & 0x40) {
            goto end;
        }

        sp24 -= 0x12;
        if (sp24 >= 9) {
            sp20 = 2;
            sp24 -= 0x28;
        }

    block_14:
        if (D_843C523C->unk_5C[sp24] != 1) {
            D_843C523C->unk_5C[sp24] -= sp20;
            if (D_843C523C->unk_5C[sp24] <= 0) {
                D_843C523C->unk_5C[sp24] = 1;
            }

            sp28 = 0;
            sp2C = 0;

            if (sp24 < 4) {
                switch (sp24) {
                    case 0:
                        sp2C = 1;
                        sp18 = &D_843C523C->unk_38;
                        sp1C = &D_843C523C->unk_2A;
                        break;

                    case 1:
                        sp18 = &D_843C523C->unk_3A;
                        sp1C = &D_843C523C->unk_2C;
                        break;

                    case 2:
                        sp28 = 1;
                        sp18 = &D_843C523C->unk_3C;
                        sp1C = &D_843C523C->unk_2E;
                        break;

                    case 3:
                        sp18 = &D_843C523C->unk_3E;
                        sp1C = &D_843C523C->unk_30;
                        break;
                }

                if (*sp1C != 1) {
                    *sp1C = (*sp18 * D_8438ACB8[D_843C523C->unk_5C[sp24] - 1].unk_00) /
                            D_8438ACB8[D_843C523C->unk_5C[sp24] - 1].unk_01;
                    if (*sp1C == 0) {
                        *sp1C = 1;
                    }
                } else {
                    goto block_39;
                }
            }

            if (sp20 == 2) {
                func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
                func_843179F4(D_843901A0->unk_208, sp24 + 0x9A);
            } else {
                func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
                func_843179F4(D_843901A0->unk_208, sp24 + 0xA0);
            }

            if ((sp28 != 0) || (D_8438AC60[0] != 1)) {
                func_84370B0C(D_84390010[!D_84390240.unk_00->unk_2C]);
            }

            if ((sp2C != 0) || (D_8438AC60[0] != 1)) {
                func_84370B44(D_84390010[!D_84390240.unk_00->unk_2C]);
            }
            return;
        }
    }

block_39:
    if (D_843C5238->unk_44.unk_01 < 0x44) {
        D_843C4E44 = 0;
        D_843C4E45 = 0;
        func_843179F4(D_843901A0->unk_088, -0x5A);
        return;
    }

end:
    if (D_843C5238->unk_44.unk_01 < 0x44) {
        D_843C4E44 = 0;
        D_843C4E45 = 0;
        if (D_843C4DA9 == 0) {
            func_843179F4(D_843901A0->unk_088, -0x59);
        }
    } else {
        D_843C4E45 = 0;
    }
}

void func_84374C9C(void) {
    D_84390240.unk_00->unk_48 = 0x1B;
    D_843C5238->unk_44.unk_01 = 0;
    D_843C5238->unk_4C |= 1;
    D_843C5238->unk_54 = 0;
    D_843C5238->unk_4F = (func_8436F6D8() & 1) + 2;
}

void func_84374D08(void) {
    D_843C5238->unk_44.unk_01 = 0;
    D_843C5238->unk_4C |= 2;
    D_843C5238->unk_4F = (func_8436F6D8() & 1) + 2;
}

void func_84374D58(void) {
    if (D_843C5238->unk_44.unk_00 == 0x64) {
        D_84390240.unk_00->unk_48 = 0x27;
        func_843179F4(D_843901A0->unk_088, -0x53);
        return;
    }
    D_84390240.unk_00->unk_48 = 8;
    func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
    func_843179F4(D_843901A0->unk_088, -0x52);
}

void func_84374E08(void) {
    s32 var_v1;

    if (!(D_843C5238->unk_4C & 4)) {
        D_843C5238->unk_4C |= 4;

        switch (D_843C5238->unk_44.unk_01) {
            case 0x4D:
                D_843C5238->unk_44.unk_01 = 2;

            case 0x2C:
                D_843C5238->unk_54 = 2;
                D_843C5238->unk_4F = D_843C5238->unk_54;
                break;

            default:
                var_v1 = func_8436F6D8() & 3;
                if (var_v1 >= 2) {
                    var_v1 = func_8436F6D8() & 3;
                }
                D_843C5238->unk_4F = D_843C5238->unk_54 = var_v1 + 2;
                break;
        }

        D_8439022C = D_843C5238->unk_54 - 1;
        D_84390240.unk_00->unk_48 = 0x18;
    }
}

void func_84374EE4(void) {
    if (!(D_843C523C->unk_4D & 0x10)) {
        if (D_8438AC60[0] == 1) {
            if (D_843C5238->unk_44.unk_01 == 0x1F) {
                if (func_8436F6D8() >= 0x1A) {
                    return;
                }
            } else if (func_8436F6D8() >= 0x4D) {
                return;
            }
        } else {
            D_843C523C->unk_4D &= ~0x20;
            if (D_843C5238->unk_44.unk_01 == 0x1F) {
                if (func_8436F6D8() >= 0x1A) {
                    return;
                }
            } else if (func_8436F6D8() >= 0x4D) {
                return;
            }
        }
        D_843C523C->unk_4C |= 8;
    }
}

void func_84374FD4(void) {
    D_843C4DC4 = 0;
    D_843C4DA5 = 0xFF;
    if (D_843C5238->unk_2E < D_843C523C->unk_2E) {
        D_843C4DA4 = 1;
        return;
    }
    D_843C4DC4 = 0xFFFF;
    D_843C4DA5 = 2;
}

void func_84375038(void) {
    D_84390240.unk_00->unk_48 = 0xE;
    D_843C5238->unk_4C |= 0x10;

    if ((D_843C5238->unk_44.unk_01 == 0x2B) || (D_843C5238->unk_44.unk_00 == 0x5B)) {
        D_843C5238->unk_4C |= 0x40;
        if (D_843C5238->unk_44.unk_00 == 0x5B) {
            D_84390240.unk_00->unk_48 = 0xD;
        }

        if (D_843C5238->unk_44.unk_01 == 0x2B) {
            D_84390240.unk_00->unk_48 = 0xC;
        }
    }

    func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));

    switch (D_843C5238->unk_44.unk_00) {
        case 0xD:
            func_843179F4(D_843901A0->unk_0C8, -0x51);
            break;

        case 0x4C:
            func_843179F4(D_843901A0->unk_0C8, -0x50);
            break;

        case 0x82:
            func_843179F4(D_843901A0->unk_0C8, -0x4F);
            break;

        case 0x8F:
            func_843179F4(D_843901A0->unk_0C8, -0x4E);
            break;

        case 0x13:
            func_843179F4(D_843901A0->unk_148, -0x4D);
            break;

        case 0x5B:
            func_843179F4(D_843901A0->unk_148, -0x4C);
            break;
    }
}

void func_843751F8(void) {
    s32 var_v1;

    if (!(D_843C5238->unk_4C & 0x20) && ((D_8438AC60[0] != 1) || (D_843C5238->unk_44.unk_03 != 0) ||
                                         ((D_843C523C->unk_16[6] != 8) && (D_843C523C->unk_16[7] != 8)))) {
        D_843C523C->unk_4D &= 0xFFDF;
        D_843C5238->unk_4C |= 0x20;
        var_v1 = func_8436F6D8() & 3;
        if (var_v1 >= 2) {
            var_v1 = func_8436F6D8() & 3;
        }
        D_843C5238->unk_4F = var_v1 + 1;
    }
}

void func_843752C0(void) {
    if (D_843C5238->unk_4D & 2) {
        D_84390240.unk_00->unk_48 = 7;
        func_843179F4(D_843901A0->unk_088, -0x4B);
        return;
    }
    D_84390240.unk_00->unk_48 = 7;
    D_843C5238->unk_4D |= 2;
    func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
    func_843179F4(D_843901A0->unk_088, -0x4A);
}

void func_84375384(void) {
    D_84390240.unk_00->unk_48 = 7;
    if (D_843C5238->unk_4D & 4) {
        func_843179F4(D_843901A0->unk_088, -0x49);
        return;
    }
    D_843C5238->unk_4D |= 4;
    func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
    func_843179F4(D_843901A0->unk_088, -0x48);
}

void func_84375424(void) {
    s32 var_v1;

    D_843C5238->unk_12 = D_843C5238->unk_0C;

    if (D_843C5238->unk_44.unk_00 == 0xA5) {
        var_v1 = D_843C4DC4 >> 1;
    } else {
        var_v1 = D_843C4DC4 >> 2;
    }

    if (var_v1 == 0) {
        var_v1 += 1;
    }

    if (D_843C5238->unk_12 < var_v1) {
        D_843C5238->unk_12 = 0;
    } else {
        D_843C5238->unk_12 -= var_v1;
    }

    D_843C523C->unk_12 = D_843C523C->unk_0C;
    func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
    func_843179F4(D_843901A0->unk_408, -0x47);
    D_84390240.unk_00->unk_48 = 9;
}

void func_84375508(void) {
    if (!(D_843C523C->unk_4D & 0x10) && (func_8436F6D8() < 0x1A) && !(D_843C523C->unk_4C & 0x80)) {
        D_84390240.unk_00->unk_1A = 3;
        D_843C4E45 = 0;
        D_843C523C->unk_4C |= 0x80;
        D_843C523C->unk_50 = (func_8436F6D8() & 3) + 2;
        func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_208, -0x46);
    }
}

void func_843755E8(void) {
    D_84390240.unk_00->unk_48 = 0x16;
    D_843C4E44 = 0;

    if (!(D_843C523C->unk_4D & 0x10)) {
        func_843708CC();
        if ((D_843C4DA4 == 0) && !(D_843C523C->unk_4C & 0x80)) {
            D_843C4E44 = 1;
            D_843C523C->unk_4C |= 0x80;
            D_843C523C->unk_50 = (func_8436F6D8() & 3) + 2;
            func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
            func_843179F4(D_843901A0->unk_088, -0x45);
            return;
        }
    }

    if (D_843C4DA9 == 0) {
        func_843179F4(D_843901A0->unk_088, -0x44);
    }
}

void func_84375700(void) {
    D_84390240.unk_00->unk_48 = 0x16;
    if (D_843C523C->unk_15 == 0) {
        if ((D_843C5238->unk_44.unk_03 != 0x17) || ((D_843C523C->unk_16[6] != 4) && (D_843C523C->unk_16[7] != 4))) {
            func_843708CC();
            if (D_843C4DA4 == 0) {
                D_843C523C->unk_15 |= 0x40;
                func_84370B0C(D_84390010[!D_84390240.unk_00->unk_2C]);
                func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
                func_843179F4(D_843901A0->unk_088, -0x43);
                return;
            }
        } else {
            D_84390240.unk_00->unk_48 = 8;
            D_843C4E44 = 0;
            func_843179F4(D_843901A0->unk_088, -0x42);
            return;
        }
    }

    D_84390240.unk_00->unk_48 = 8;
    D_843C4E44 = 0;
    func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
    func_843179F4(D_843901A0->unk_088, -0x41);
}

void func_84375894(void) {
    s32 temp_v1;

    D_84390240.unk_00->unk_48 = 0x1C;
    if (D_843C5238->unk_4D & 0x10) {
        func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_088, -0x2A);
        return;
    }

    temp_v1 = D_843C5238->unk_28 >> 2;
    if (temp_v1 >= D_843C5238->unk_0C) {
        func_843179F4(D_843901A0->unk_088, -0x29);
        return;
    }

    D_84390240.unk_00->unk_48 = 0x19;
    D_843C5238->unk_59 = temp_v1;
    D_843C5238->unk_0C -= temp_v1;
    D_843C5238->unk_4D |= 0x10;
    func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
    func_843179F4(D_843901A0->unk_088, -0x28);
}

void func_843759C4(void) {
    D_843C5238->unk_4D |= 0x20;
}

void func_843759DC(void) {
    D_843C5238->unk_4D |= 0x40;
}

void func_843759F4(void) {
    unk_D_84390010_654* sp24 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;
    s32 var_t0;
    u8 temp_v0;

    D_84390240.unk_00->unk_48 = 7;
    func_843708CC();

    if ((D_843C4DA4 == 0) && !(D_843C523C->unk_4C & 0x40)) {
        D_843C4DAA = 1;
        do {
            var_t0 = func_8430C414(4);
            if (var_t0 >= 4) {
                var_t0 = 3;
            }
            temp_v0 = D_843C523C->unk_1F[var_t0];
        } while (temp_v0 == 0);

        D_843C5238->unk_1F[sp24->unk_0C] = temp_v0;
        func_8002D5D4(0x1E, func_8002D7C0(NULL, 0, D_843900B8, D_843C523C->unk_1F[var_t0] - 1));
        func_843179F4(D_843901A0->unk_088, -0x40);
        return;
    }

    func_843179F4(D_843901A0->unk_088, -0x3F);
}

void func_84375B1C(void) {
    func_843708CC();

    if ((D_843C4DA4 == 0) && (D_843C523C->unk_16[6] != 0x16) && (D_843C523C->unk_16[7] != 0x16)) {
        if (!(D_843C523C->unk_4D & 0x80)) {
            D_843C523C->unk_4D |= 0x80;
            func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
            func_843179F4(D_843901A0->unk_088, -0x3E);
            return;
        }
    }

    D_84390240.unk_00->unk_48 = 8;
    func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
    func_843179F4(D_843901A0->unk_088, -0x3D);
}

void func_84375C24(void) {
    D_84390240.unk_00->unk_48 = 7;
    func_843179F4(D_843901A0->unk_088, -0x3C);
}

void func_84375C60(void) {
    s32 sp24;
    s32 temp_v1;

    func_843708CC();

    if (D_843C4DA4 == 0) {
        D_84390240.unk_00->unk_48 = 0x20;
        if (D_843C523C->unk_52 == 0) {
            do {
                sp24 = func_8436F6D8() & 3;
            } while (D_843C523C->unk_1F[sp24] == 0);
            temp_v1 = (func_8436F6D8() & 7) + 1;
            D_843C523C->unk_52 = (sp24 * 0x10) + temp_v1;
            D_843C523C->unk_57 = D_843C523C->unk_1F[sp24];
            func_8002D5D4(0x1E, func_8002D7C0(NULL, 0, D_843900B8, D_843C523C->unk_57 - 1));
            func_843179F4(D_843901A0->unk_088, -0x3B);
            return;
        }
    }

    D_84390240.unk_00->unk_48 = 8;
    func_843179F4(D_843901A0->unk_088, -0x3A);
}

void func_84375D78(void) {
    func_843179F4(D_843901A0->unk_088, -0x39);
}

void func_84375DA4(void) {
    D_84390240.unk_00->unk_48 = 7;
    if (!(D_843C523C->unk_4C & 0x40)) {
        D_843C5238->unk_16[6] = D_843C523C->unk_16[6];
        D_843C5238->unk_16[7] = D_843C523C->unk_16[7];
        func_8002D5D4(0x19, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_088, -0x38);
    } else {
        func_843179F4(D_843901A0->unk_088, -0x37);
    }
}

void func_84375E6C(void) {
    s32 i;
    unk_D_800FCB18* temp_t0 = &D_84390010[0]->unk_654.unk_38;
    unk_D_800FCB18* temp_a3 = &D_84390010[1]->unk_654.unk_38;

    D_84390240.unk_00->unk_48 = 0x1D;

    for (i = 0; i < 8; i++) {
        temp_t0->unk_5C[i] = 7;
        temp_a3->unk_5C[i] = 7;
    }

    temp_t0->unk_2A = temp_t0->unk_38;
    temp_t0->unk_2C = temp_t0->unk_3A;
    temp_t0->unk_2E = temp_t0->unk_3C;
    temp_t0->unk_30 = temp_t0->unk_3E;
    temp_a3->unk_2A = temp_a3->unk_38;
    temp_a3->unk_2C = temp_a3->unk_3A;
    temp_a3->unk_2E = temp_a3->unk_3C;
    temp_a3->unk_30 = temp_a3->unk_3E;

    if ((D_843C523C->unk_15 & 0x27) && !(D_843C523C->unk_4C & 0x10)) {
        D_843C523C->unk_5A = 0xFE;
    }

    D_843C523C->unk_15 = 0;
    // clang-format off
    if (D_8438AC60[0] == 1) { D_843C5238->unk_15 = 0; }
    // clang-format on

    temp_t0->unk_52 = temp_a3->unk_52 = 0;
    temp_t0->unk_57 = temp_a3->unk_57 = 0;
    temp_t0->unk_4C &= ~0x80;
    temp_t0->unk_4D &= 0x78;
    temp_t0->unk_4E &= 8;
    temp_a3->unk_4C &= ~0x80;
    temp_a3->unk_4D &= 0x78;
    temp_a3->unk_4E &= 8;
    D_843C5238->unk_56 = 0;
    D_843C523C->unk_56 = 0;

    func_843179F4(D_843901A0->unk_088, -0x36);
}

void func_8437600C(void) {
    u8 temp_v0;
    unk_D_84390010_654* temp_a1;
    unk_D_800FCB18* temp_a2;

    temp_a1 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;
    temp_a2 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;

    D_84390240.unk_00->unk_48 = 0x15;
    if (D_843C5238->unk_0C != D_843C5238->unk_28) {
        if (D_843C5238->unk_44.unk_00 == 0x9C) {
            temp_v0 = D_843C5238->unk_15;

            D_843C5238->unk_15 = 2;
            temp_a2->unk_16[temp_a1->unk_08 + temp_a1->unk_2B * 3] = 2;

            if (temp_v0 != 0) {
                if (D_8438AC60[0] == 1) {
                    D_843C5238->unk_4E &= ~1;
                    func_843736B0(&D_843C5238->unk_2A, D_843C5238->unk_38, D_843C5238->unk_5C[0]);
                    func_843736B0(&D_843C5238->unk_2E, D_843C5238->unk_3C, D_843C5238->unk_5C[2]);
                }
                func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
                func_843179F4(D_843901A0->unk_088, -0x35);
            } else {
                func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
                func_843179F4(D_843901A0->unk_088, -0x34);
            }
            D_843C5238->unk_0C += D_843C5238->unk_28;
        } else {
            D_843C5238->unk_0C += D_843C5238->unk_28 / 2;
        }

        if (D_843C5238->unk_28 < D_843C5238->unk_0C) {
            D_843C5238->unk_0C = D_843C5238->unk_28;
        }

        func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_148, -0x33);
        return;
    }

    D_84390240.unk_00->unk_48 = 0x1C;
    D_843C4DA4 = 1;
    func_843179F4(D_843901A0->unk_088, -0x32);
}

void func_84376258(void) {
    s32 i;
    unk_D_84390010_654* sp20;
    unk_D_84390010_654* sp1C;
    unk_D_800FCB18* ptr;

    sp20 = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654;
    sp1C = &D_84390010[!D_84390240.unk_00->unk_2C]->unk_654;

    if ((D_8438AC60[0] == 1) && ((((D_843C523C->unk_4E & 8) == 0) && (D_843C523C->unk_0B == 0x84)) ||
                                 (((D_843C523C->unk_4E & 8) != 0) && (sp1C->unk_BE == 0x84)))) {
        D_84390240.unk_00->unk_48 = 0x1C;
        func_8002D5D4(0x1B, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_088, -0x2F);
        return;
    }

    ptr = D_843C5238;
    if (!(ptr->unk_4C & 0x40) &&
        ((D_8438AC60[0] != 1) || (D_843C523C->unk_1F[0] != 0x90) || (D_843C523C->unk_1F[1] != 0))) {
        D_84390240.unk_00->unk_48 = 0xF;
        func_8002D5D4(0x1B, func_8430862C(D_84390010[!D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_148, -0x31);
        D_843C5238->unk_4E |= 8;

        if (D_843C523C->unk_4E & 8) {
            sp20->unk_BE = sp1C->unk_BE;
        } else {
            sp20->unk_BE = D_843C523C->unk_0B;
        }

        D_843C5238->unk_16[6] = D_843C523C->unk_16[6];
        D_843C5238->unk_16[7] = D_843C523C->unk_16[7];
        D_843C5238->unk_1F[0] = D_843C523C->unk_1F[0];
        D_843C5238->unk_1F[1] = D_843C523C->unk_1F[1];
        D_843C5238->unk_1F[2] = D_843C523C->unk_1F[2];
        D_843C5238->unk_1F[3] = D_843C523C->unk_1F[3];
        D_843C5238->unk_24 = D_843C523C->unk_24;
        D_843C5238->unk_2A = D_843C523C->unk_2A;
        D_843C5238->unk_2C = D_843C523C->unk_2C;
        D_843C5238->unk_2E = D_843C523C->unk_2E;
        D_843C5238->unk_30 = D_843C523C->unk_30;

        for (i = 0; i < 4; i++) {
            if (D_843C523C->unk_1F[i] == 0) {
                break;
            }
            D_843C5238->unk_32[i] = 5;
        }

        D_843C5238->unk_38 = D_843C523C->unk_38;
        D_843C5238->unk_3A = D_843C523C->unk_3A;
        D_843C5238->unk_3C = D_843C523C->unk_3C;
        D_843C5238->unk_3E = D_843C523C->unk_3E;

        for (i = 0; i < 8; i++) {
            D_843C5238->unk_5C[i] = D_843C523C->unk_5C[i];
        }
        return;
    }

    D_84390240.unk_00->unk_48 = 0x1C;
    func_843179F4(D_843901A0->unk_088, -0x30);
}

void func_843765E8(void) {
    D_84390240.unk_00->unk_48 = 7;
    if (D_843C5238->unk_44.unk_01 == 0x40) {
        if (!(D_843C5238->unk_4E & 2)) {
            D_843C5238->unk_4E |= 2;
            func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
            func_843179F4(D_843901A0->unk_088, -0x2E);
        } else {
            func_843179F4(D_843901A0->unk_088, -0x2D);
        }
    } else if (!(D_843C5238->unk_4E & 4)) {
        D_843C5238->unk_4E |= 4;
        func_8002D5D4(0x19, func_8430862C(D_84390010[D_84390240.unk_00->unk_2C]));
        func_843179F4(D_843901A0->unk_088, -0x2C);
    } else {
        func_843179F4(D_843901A0->unk_088, -0x2B);
    }
}

void func_8437670C(void) {
    unk_D_800FCB18* ptr = &D_84390010[D_84390240.unk_00->unk_2C]->unk_654.unk_38;
    s32 idx = ptr->unk_44.unk_01;

    if (D_8438AE54[idx - 1] != NULL) {
        D_8438AE54[idx - 1]();
    }
}

void func_84376768(void) {
    func_8437670C();
}
