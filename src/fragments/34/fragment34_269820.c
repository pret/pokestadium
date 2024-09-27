#include "fragment34.h"
#include "src/12D80.h"

unk_D_8140E728_01C D_8140E460 = { 3, func_8140C5BC };

void func_814078B0(unk_D_8140E720* arg0) {
    func_8140810C(arg0);
    func_81408BE0(arg0, 0.0f, 0.0f, 0.0f);
    func_81409888(arg0, 0.0f, 0.0f, 0.0f);
    func_814098A8(arg0, 0.0f, 0.0f, 0.0f);
    func_8140A03C(arg0, 0.0f, 0.0f, 0.0f);
    func_8140AECC(arg0, 0.0f, 0.0f, 0.0f);
    func_8140AD8C(arg0, 0.0f);
    func_8140ADA4(arg0, 0.0f);
    func_8140A270(arg0, 0, 0, 0);
    func_8140A348(arg0, 0, 0, 0);
    func_814083E8(arg0, 0);
    func_8140BCA8(arg0, 0);
    func_8140BE14(arg0, 0);
    func_8140BF38(arg0, 0);
    func_8140BF24(arg0, 0);
    func_8140BF10(arg0, 0);
    func_8140BED8(arg0, 0);
    func_8140BEEC(arg0, 0);
    func_8140BAC8(arg0, 0xFF, 0xFF, 0xFF);
    func_8140BB74(arg0, 0xFF, 0xFF, 0xFF);
    func_8140BC20(arg0, 0xFF);

    arg0->unk_1C = 1.0f;
    arg0->unk_28 = 1.0f;
}

unk_D_8140E720* func_81407A30(void) {
    s32 i;
    s32 var_v0 = D_8140E72C;
    unk_D_8140E720* var_a0 = &D_8140E720[var_v0];

    for (i = 0; i < 0x12C; i++) {
        if (var_a0->unk_D0 == 0) {
            break;
        }

        var_v0++;
        if (var_v0 >= 0x12C) {
            var_v0 = 0;
            var_a0 = &D_8140E720[0];
        } else {
            var_a0++;
        }
    }

    if (i >= 0x12C) {
        var_a0 = (unk_D_8140E720*)-1;
    } else {
        var_a0->unk_D0 = 1;

        func_814078B0(var_a0);

        D_8140E72C = var_v0 + 1;
        if (D_8140E72C >= 0x12C) {
            D_8140E72C = 0;
        }
    }

    return var_a0;
}

void func_81407B04(unk_D_8140E720* arg0) {
    if (arg0->prev != NULL) {
        arg0->prev->next = arg0->next;
    }

    if (arg0->next != NULL) {
        arg0->next->prev = arg0->prev;
    }

    arg0->prev = NULL;
    arg0->next = NULL;

    arg0->unk_D0 = 0;
}

unk_D_8140E720* func_81407B3C(void) {
    return func_81407A30();
}

unk_D_8140E720* func_81407B5C(u8 arg0) {
    s32 i;
    unk_D_8140E720* sp28;
    unk_D_8140E720* temp_v0;
    unk_D_8140E720* var_s0;

    sp28 = func_81407A30();

    if ((u32)sp28 != -1) {
        var_s0 = sp28;
        arg0--;

        for (i = 0; i < arg0; i++) {
            temp_v0 = func_81407A30();
            if ((u32)temp_v0 == -1) {
                break;
            }
            var_s0->next = temp_v0;
            temp_v0->prev = var_s0;
            var_s0 = temp_v0;
        }
    }

    return sp28;
}

unk_D_8140E720* func_81407BE4(f32 arg0, Vec3f arg1, Vec3s arg2, func_unk_D_8140E720_008 arg3, unk_D_8140E728_01C* arg4,
                              s16 arg5, s16 arg6, s16 arg7) {
    unk_D_8140E720* sp1C = func_81407B3C();

    if ((u32)sp1C != -1) {
        sp1C->unk_28 = arg0;

        func_81400930(&sp1C->unk_68, &arg1);
        func_8140094C(&sp1C->unk_94, &arg2);

        sp1C->unk_08 = arg3;
        sp1C->unk_0C = arg4;
        sp1C->unk_10 = 0;
        sp1C->unk_14 = 0;
        sp1C->unk_AC = arg5;
        sp1C->unk_CE = arg7;
        sp1C->unk_CD = arg6;
    }
    return sp1C;
}

unk_D_8140E720* func_81407C7C(unk_D_86002F58_004_000* arg0, func_unk_D_8140E720_008 arg1, unk_D_8140E728_01C* arg2,
                              s16 arg3, s16 arg4, s16 arg5) {
    unk_D_8140E720* sp1C = func_81407B3C();

    if ((u32)sp1C != -1) {
        if (arg4 == 0xFF) {
            sp1C->unk_38.x = arg0->unk_024.x;
            sp1C->unk_38.y = arg0->unk_024.y;
            sp1C->unk_38.z = arg0->unk_024.z;
        } else {
            func_80015390(arg0, arg4, &sp1C->unk_38);
        }

        sp1C->unk_94.x = arg0->unk_01E.x;
        sp1C->unk_94.y = arg0->unk_01E.y;
        sp1C->unk_94.z = arg0->unk_01E.z;

        sp1C->unk_08 = arg1;
        sp1C->unk_0C = arg2;

        sp1C->unk_10 = 0;
        sp1C->unk_14 = 0;

        sp1C->unk_AC = arg3;
        sp1C->unk_CE = arg5;
        sp1C->unk_CD = arg4;
    }
    return sp1C;
}

void func_81407D48(f32 arg0, Vec3f arg1, Vec3s arg2, func_unk_D_8140E720_008 arg3, unk_D_8140E728_01C* arg4, s16 arg5) {
    s32 i;

    for (i = 0; i < arg5; i++) {
        if ((u32)func_81407BE4(arg0, arg1, arg2, arg3, arg4, i, 0xFF, NULL) == -1) {
            break;
        }
    }
}

void func_81407E30(f32 arg0, Vec3f arg1, Vec3s arg2, func_unk_D_8140E720_008 arg3, unk_D_8140E728_01C* arg4, s16 arg5,
                   s16 arg6) {
    s32 i;

    for (i = 0; i < arg5; i++) {
        if ((u32)func_81407BE4(arg0, arg1, arg2, arg3, arg4, i, 0xFF, arg6) == -1) {
            break;
        }
    }
}

void func_81407F24(unk_D_86002F58_004_000* arg0, func_unk_D_8140E720_008 arg1, unk_D_8140E728_01C* arg2, s16 arg3,
                   s16 arg4) {
    s32 i;

    for (i = 0; i < arg3; i++) {
        if ((u32)func_81407C7C(arg0, arg1, arg2, i, arg4, 0) == -1) {
            break;
        }
    }
}

void func_81407FC8(unk_D_86002F58_004_000* arg0, func_unk_D_8140E720_008 arg1, unk_D_8140E728_01C* arg2, s16 arg3,
                   s16 arg4, s16 arg5) {
    s32 i;

    for (i = 0; i < arg3; i++) {
        if ((u32)func_81407C7C(arg0, arg1, arg2, i, arg4, arg5) == -1) {
            break;
        }
    }
}

s32 func_81408078(void) {
    s32 i;
    s32 var_v1 = 0;
    unk_D_8140E720* ptr = D_8140E720;

    for (i = 0; i < 0x12C; i++, ptr++) {
        if (ptr->unk_D0 != 0) {
            var_v1++;
        }
    }

    return var_v1;
}

s32 func_814080EC(void) {
    return func_81408078();
}

void func_8140810C(unk_D_8140E720* arg0) {
    arg0->unk_B2 = 1;
    arg0->unk_0C = &D_8140E460;
    arg0->unk_08 = NULL;
    arg0->unk_10 = 0;
    arg0->unk_14 = 0;
    arg0->unk_B8 = 0;
    func_814082B4(arg0, 4);
}

void func_81408150(unk_D_8140E720* arg0) {
    arg0->unk_B2 = 0;
}

void func_81408158(unk_D_8140E720* arg0) {
    arg0->unk_B2 = 0;

    arg0->unk_08 = NULL;
    arg0->unk_0C = NULL;

    func_81408A44(arg0);
}

s32 func_81408180(unk_D_8140E720* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_B2 == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8140819C(unk_D_8140E720* arg0) {
    s32 var_v1 = 0;

    if (arg0->unk_B2 >= 2) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_814081BC(unk_D_8140E720* arg0) {
    func_814082C4(arg0, 1);
    arg0->unk_B2++;
}

s32 func_814081F0(unk_D_8140E720* arg0, s16 arg1) {
    s32 sp1C = 0;

    if (func_81408308(arg0, 0x80) != 0) {
        func_814082B4(arg0, 0x80);
        arg0->unk_BC = arg1;
    }

    arg0->unk_BC--;
    if (arg0->unk_BC <= 0) {
        arg0->unk_BC = 0;
        func_814082C4(arg0, 0x80);
        sp1C = 1;
    }

    return sp1C;
}

s32 func_8140826C(unk_D_8140E720* arg0, s16 arg1) {
    s32 sp1C = func_814081F0(arg0, arg1);

    if (sp1C != 0) {
        func_814081BC(arg0);
    }
    return sp1C;
}

void func_814082B4(unk_D_8140E720* arg0, s32 arg1) {
    arg0->unk_18 |= arg1;
}

void func_814082C4(unk_D_8140E720* arg0, s32 arg1) {
    arg0->unk_18 &= ~arg1;
}

void func_814082D8(unk_D_8140E720* arg0, s32 arg1) {
    arg0->unk_18 ^= arg1;
}

s32 func_814082E8(unk_D_8140E720* arg0, s32 arg1) {
    s32 var_v1 = 0;

    if (arg0->unk_18 & arg1) {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_81408308(unk_D_8140E720* arg0, s32 arg1) {
    s32 var_v1 = 0;

    if (!(arg0->unk_18 & arg1)) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_81408328(unk_D_8140E720* arg0) {
    func_814082B4(arg0, 4);
}

void func_81408348(unk_D_8140E720* arg0) {
    func_814082C4(arg0, 4);
}

s32 func_81408368(unk_D_8140E720* arg0) {
    return func_814082E8(arg0, 4);
}

void func_81408388(unk_D_8140E720* arg0) {
    func_814082B4(arg0, 0x40);
}

void func_814083A8(unk_D_8140E720* arg0) {
    func_814082C4(arg0, 0x40);
}

void func_814083C8(unk_D_8140E720* arg0) {
    func_814082E8(arg0, 0x40);
}

void func_814083E8(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_C7 = arg1;
}

s32 func_814083FC(unk_D_8140E720* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s32 sp1C = 0;

    if (func_81408308(arg0, 1) != 0) {
        arg0->unk_B6 = arg4;
        arg0->unk_C7 = arg1;
        arg0->unk_C6 = arg5;
        func_814082B4(arg0, 1);
    } else {
        arg0->unk_B6--;
        if (arg0->unk_B6 <= 0) {
            arg0->unk_B6 = arg4;

            arg0->unk_C7 += arg3;
            if (arg2 < arg0->unk_C7) {
                if (arg0->unk_C6 > 0) {
                    arg0->unk_C6--;
                }

                if (arg0->unk_C6 == 0) {
                    arg0->unk_C7 = arg2;
                    sp1C = 1;
                } else {
                    arg0->unk_C7 = arg1;
                }
            }
        }
    }
    return sp1C;
}

s32 func_814084D8(unk_D_8140E720* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s32 sp24 = func_814083FC(arg0, arg1, arg2, arg3, arg4, arg5);

    if (sp24 != 0) {
        func_814081BC(arg0);
    }

    return sp24;
}

s32 func_81408548(unk_D_8140E720* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s32 sp1C = 0;

    if (func_81408308(arg0, 1) != 0) {
        arg0->unk_B6 = arg4;
        arg0->unk_C7 = arg1;
        arg0->unk_C6 = arg5;
        func_814082B4(arg0, 1);
    } else {
        arg0->unk_B6--;
        if (arg0->unk_B6 <= 0) {
            arg0->unk_B6 = arg4;

            arg0->unk_C7 -= arg3;
            if (arg0->unk_C7 < arg2) {
                if (arg0->unk_C6 > 0) {
                    arg0->unk_C6--;
                }

                if (arg0->unk_C6 == 0) {
                    arg0->unk_C7 = arg2;
                    sp1C = 1;
                } else {
                    arg0->unk_C7 = arg1;
                }
            }
        }
    }

    return sp1C;
}

s32 func_81408624(unk_D_8140E720* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s32 sp24 = func_81408548(arg0, arg1, arg2, arg3, arg4, arg5);

    if (sp24 != 0) {
        func_814081BC(arg0);
    }
    return sp24;
}

s32 func_81408694(unk_D_8140E720* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s32 sp24 = 0;

    if (func_81408308(arg0, 1) != 0) {
        arg0->unk_B6 = arg4;
        arg0->unk_C7 = arg1;
        arg0->unk_C6 = arg5;
        func_814082B4(arg0, 1);
        func_814082C4(arg0, 0x10);
    } else {
        arg0->unk_B6--;
        if (arg0->unk_B6 <= 0) {
            arg0->unk_B6 = arg4;

            if (func_81408308(arg0, 0x10) != 0) {
                arg0->unk_C7 += arg3;
                if (arg0->unk_C7 >= arg2) {
                    arg0->unk_C7 = arg2;
                    func_814082B4(arg0, 0x10);
                }
            } else {
                arg0->unk_C7 -= arg3;
                if (arg1 >= arg0->unk_C7) {
                    arg0->unk_C7 = arg1;
                    if (arg0->unk_C6 > 0) {
                        arg0->unk_C6--;
                    }

                    if (arg0->unk_C6 == 0) {
                        func_814082C4(arg0, 0x20);
                        func_814082C4(arg0, 1);
                        sp24 = 1;
                    } else {
                        func_814082C4(arg0, 0x10);
                        func_814082B4(arg0, 0x20);
                    }
                }
            }
        }
    }

    return sp24;
}

s32 func_814087F4(unk_D_8140E720* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s32 sp24 = func_81408694(arg0, arg1, arg2, arg3, arg4, arg5);

    if (sp24 != 0) {
        func_814081BC(arg0);
    }
    return sp24;
}

s32 func_81408864(unk_D_8140E720* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s32 sp24 = 0;

    if (func_81408308(arg0, 1) != 0) {
        arg0->unk_B6 = arg4;
        arg0->unk_C7 = arg1;
        arg0->unk_C6 = arg5;
        func_814082B4(arg0, 1);
        func_814082C4(arg0, 0x10);
    } else {
        arg0->unk_B6--;
        if (arg0->unk_B6 <= 0) {
            arg0->unk_B6 = arg4;
            if (func_81408308(arg0, 0x10) != 0) {
                arg0->unk_C7 -= arg3;
                if (arg2 >= arg0->unk_C7) {
                    arg0->unk_C7 = arg2;
                    func_814082B4(arg0, 0x10);
                }
            } else {
                arg0->unk_C7 += arg3;
                if (arg0->unk_C7 >= arg1) {
                    arg0->unk_C7 = arg1;
                    if (arg0->unk_C6 > 0) {
                        arg0->unk_C6--;
                    }

                    if (arg0->unk_C6 == 0) {
                        func_814082C4(arg0, 1);
                        sp24 = 1;
                    } else {
                        func_814082C4(arg0, 0x10);
                    }
                }
            }
        }
    }
    return sp24;
}

s32 func_814089AC(unk_D_8140E720* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    s32 sp24 = func_81408864(arg0, arg1, arg2, arg3, arg4, arg5);

    if (sp24 != 0) {
        func_814081BC(arg0);
    }
    return sp24;
}

void func_81408A1C(unk_D_8140E720* arg0) {
    arg0->unk_B8 = 1;
    func_814082C4(arg0, 2);
}

void func_81408A44(unk_D_8140E720* arg0) {
    arg0->unk_B8 = 0;
    func_814082C4(arg0, 2);
}

void func_81408A68(unk_D_8140E720* arg0) {
    arg0->unk_B8++;
}

s32 func_81408A78(unk_D_8140E720* arg0, s16 arg1) {
    s32 sp1C = 0;

    if (func_81408308(arg0, 2) != 0) {
        func_814082B4(arg0, 2);
        arg0->unk_BA = arg1;
    }

    arg0->unk_BA--;
    if (arg0->unk_BA < 0) {
        func_814082C4(arg0, 2);
        sp1C = 1;
    }
    return sp1C;
}

void func_81408AF0(unk_D_8140E720* arg0) {
    arg0->unk_2C.x = arg0->unk_68.x + arg0->unk_38.x + arg0->unk_50.x;
    arg0->unk_2C.y = arg0->unk_68.y + arg0->unk_38.y + arg0->unk_50.y;
    arg0->unk_2C.z = arg0->unk_68.z + arg0->unk_38.z + arg0->unk_50.z;

    if (arg0->unk_14 != NULL) {
        arg0->unk_14->unk_24.x = arg0->unk_2C.x;
        arg0->unk_14->unk_24.y = arg0->unk_2C.y;
        arg0->unk_14->unk_24.z = arg0->unk_2C.z;

        arg0->unk_14->unk_30.x = arg0->unk_1C;
        arg0->unk_14->unk_30.y = arg0->unk_1C;
        arg0->unk_14->unk_30.z = arg0->unk_1C;

        if (func_81408308(arg0, 0x200) != 0) {
            arg0->unk_14->unk_1E.x = arg0->unk_94.x;
            arg0->unk_14->unk_1E.y = arg0->unk_94.y;
            arg0->unk_14->unk_1E.z = arg0->unk_94.z;
        }
        arg0->unk_14->unk_1D = arg0->prim_a;
    }
}

void func_81408BE0(unk_D_8140E720* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_38.x = arg1 * D_8140E628.unk_00.y;
    arg0->unk_38.y = arg2 * D_8140E628.unk_00.y;
    arg0->unk_38.z = arg3 * D_8140E628.unk_00.y;
}

void func_81408C20(unk_D_8140E720* arg0, Vec3f arg1) {
    arg0->unk_38.x = arg1.x * D_8140E628.unk_00.y;
    arg0->unk_38.y = arg1.y * D_8140E628.unk_00.y;
    arg0->unk_38.z = arg1.z * D_8140E628.unk_00.y;
}

void func_81408C68(unk_D_8140E720* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_38.x = arg1;
    arg0->unk_38.y = arg2;
    arg0->unk_38.z = arg3;
}

void func_81408C88(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_38.x = arg1 * D_8140E628.unk_00.y;
}

void func_81408CA0(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_38.y = arg1 * D_8140E628.unk_00.y;
}

void func_81408CB8(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_38.z = arg1 * D_8140E628.unk_00.y;
}

void func_81408CD0(unk_D_8140E720* arg0, f32 arg1) {
    Vec3f sp1C;

    func_8140AB58(arg0, arg1, &sp1C);
    func_81408C20(arg0, sp1C);
}

void func_81408D24(unk_D_8140E720* arg0, f32 arg1) {
    Vec3f sp1C;

    func_8140AC70(arg0, arg1, &sp1C);
    func_81408C20(arg0, sp1C);
}

void func_81408D78(unk_D_8140E720* arg0, Vec3f arg1) {
    arg0->unk_38.x += arg1.x * D_8140E628.unk_00.y;
    arg0->unk_38.y += arg1.y * D_8140E628.unk_00.y;
    arg0->unk_38.z += arg1.z * D_8140E628.unk_00.y;
}

void func_81408DD8(unk_D_8140E720* arg0, Vec3f arg1) {
    arg0->unk_38.x += arg1.x;
    arg0->unk_38.y += arg1.y;
    arg0->unk_38.z += arg1.z;
}

void func_81408E18(unk_D_8140E720* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_38.x += arg1 * D_8140E628.unk_00.y;
    arg0->unk_38.y += arg2 * D_8140E628.unk_00.y;
    arg0->unk_38.z += arg3 * D_8140E628.unk_00.y;
}

void func_81408E70(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_38.x += arg1 * D_8140E628.unk_00.y;
}

void func_81408E90(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_38.y += arg1 * D_8140E628.unk_00.y;
}

void func_81408EB0(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_38.z += arg1 * D_8140E628.unk_00.y;
}

void func_81408ED0(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_38.x += arg1 * SINS(arg0->unk_94.y) * D_8140E628.unk_00.y;
    arg0->unk_38.z += arg1 * COSS(arg0->unk_94.y) * D_8140E628.unk_00.y;
}

void func_81408F38(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_38.x += arg1 * SINS(arg0->unk_94.y + 0x8000) * D_8140E628.unk_00.y;
    arg0->unk_38.z += arg1 * COSS(arg0->unk_94.y + 0x8000) * D_8140E628.unk_00.y;
}

void func_81408FAC(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_38.x += arg1 * SINS(arg0->unk_94.y + 0x4000) * D_8140E628.unk_00.y;
    arg0->unk_38.z += arg1 * COSS(arg0->unk_94.y + 0x4000) * D_8140E628.unk_00.y;
}

void func_8140901C(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_38.x += arg1 * SINS(arg0->unk_94.y - 0x4000) * D_8140E628.unk_00.y;
    arg0->unk_38.z += arg1 * COSS(arg0->unk_94.y - 0x4000) * D_8140E628.unk_00.y;
}

void func_8140908C(unk_D_8140E720* arg0, f32 arg1) {
    Vec3f sp1C;

    func_8140A9C8(arg0, arg1, &sp1C);
    arg0->unk_38.x += sp1C.x * D_8140E628.unk_00.y;
    arg0->unk_38.y += sp1C.y * D_8140E628.unk_00.y;
    arg0->unk_38.z += sp1C.z * D_8140E628.unk_00.y;
}

void func_8140910C(unk_D_8140E720* arg0, f32 arg1) {
    Vec3f sp1C;

    func_8140AB58(arg0, arg1, &sp1C);
    func_81408D78(arg0, sp1C);
}

void func_81409160(unk_D_8140E720* arg0, f32 arg1) {
    Vec3f sp1C;

    func_8140AC70(arg0, arg1, &sp1C);
    func_81408D78(arg0, sp1C);
}

void func_814091B4(unk_D_8140E720* arg0, Vec3f arg1) {
    Vec3f sp24;

    func_81400D00(&sp24, arg1, arg0->unk_94);
    func_81408D78(arg0, sp24);
}

void func_81409248(unk_D_8140E720* arg0, s32 arg1) {
    arg0->unk_38.x = func_81400B00(arg1) * D_8140E628.unk_00.y;
}

void func_81409288(unk_D_8140E720* arg0, s32 arg1) {
    arg0->unk_38.y = func_81400B00(arg1) * D_8140E628.unk_00.y;
}

void func_814092C8(unk_D_8140E720* arg0, s32 arg1) {
    arg0->unk_38.z = func_81400B00(arg1) * D_8140E628.unk_00.y;
}

void func_81409308(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    arg0->unk_38.x = (func_81400B00(arg1) * D_8140E628.unk_00.y) + arg2;
}

void func_8140935C(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    arg0->unk_38.y = (func_81400B00(arg1) * D_8140E628.unk_00.y) + arg2;
}

void func_814093B0(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    arg0->unk_38.z = (func_81400B00(arg1) * D_8140E628.unk_00.y) + arg2;
}

void func_81409404(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    f32 temp_fv0 = func_81400B00(arg1);

    if (temp_fv0 >= 0.0f) {
        arg0->unk_38.x = (temp_fv0 + arg2) * D_8140E628.unk_00.y;
    } else {
        arg0->unk_38.x = (temp_fv0 - arg2) * D_8140E628.unk_00.y;
    }
}

void func_8140948C(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    f32 temp_fv0 = func_81400B00(arg1);

    if (temp_fv0 >= 0.0f) {
        arg0->unk_38.y = (temp_fv0 + arg2) * D_8140E628.unk_00.y;
    } else {
        arg0->unk_38.y = (temp_fv0 - arg2) * D_8140E628.unk_00.y;
    }
}

void func_81409514(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    f32 temp_fv0 = func_81400B00(arg1);

    if (temp_fv0 >= 0.0f) {
        arg0->unk_38.z = (temp_fv0 + arg2) * D_8140E628.unk_00.y;
    } else {
        arg0->unk_38.z = (temp_fv0 - arg2) * D_8140E628.unk_00.y;
    }
}

void func_8140959C(unk_D_8140E720* arg0, s32 arg1, s32 arg2, s32 arg3) {
    Vec3f sp18;

    sp18.x = func_81400B00(arg1);
    sp18.y = func_81400B00(arg2);
    sp18.z = func_81400B00(arg3);

    arg0->unk_38.x = sp18.x * D_8140E628.unk_00.y;
    arg0->unk_38.y = sp18.y * D_8140E628.unk_00.y;
    arg0->unk_38.z = sp18.z * D_8140E628.unk_00.y;
}

void func_81409634(unk_D_8140E720* arg0, s32 arg1, s32 arg2, s32 arg3) {
    Vec3f sp1C;

    sp1C.x = func_81400A78(arg1);
    sp1C.y = func_81400A78(arg2);
    sp1C.z = func_81400A78(arg3);

    arg0->unk_38.x = sp1C.x * D_8140E628.unk_00.y;
    arg0->unk_38.y = sp1C.y * D_8140E628.unk_00.y;
    arg0->unk_38.z = sp1C.z * D_8140E628.unk_00.y;
}

void func_81409708(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    Vec3f sp2C;
    Vec3f sp20;

    sp2C.x = func_81400B00(arg1);
    sp2C.y = func_81400B00(arg2);
    sp2C.z = 0.0f;

    func_81400D00(&sp20, sp2C, arg0->unk_94);

    arg0->unk_38.x = sp20.x * D_8140E628.unk_00.y;
    arg0->unk_38.y = sp20.y * D_8140E628.unk_00.y;
    arg0->unk_38.z = sp20.z * D_8140E628.unk_00.y;
}

void func_814097D8(unk_D_8140E720* arg0, s32 arg1, s32 arg2, s32 arg3) {
    Vec3f sp24;

    sp24.x = func_81400B00(arg1);
    sp24.y = func_81400B00(arg2);
    sp24.z = func_81400B00(arg3);

    arg0->unk_38.x += sp24.x * D_8140E628.unk_00.y;
    arg0->unk_38.y += sp24.y * D_8140E628.unk_00.y;
    arg0->unk_38.z += sp24.z * D_8140E628.unk_00.y;
}

void func_81409888(unk_D_8140E720* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_68.x = arg1;
    arg0->unk_68.y = arg2;
    arg0->unk_68.z = arg3;
}

void func_814098A8(unk_D_8140E720* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_50.x = arg1 * D_8140E628.unk_00.y;
    arg0->unk_50.y = arg2 * D_8140E628.unk_00.y;
    arg0->unk_50.z = arg3 * D_8140E628.unk_00.y;
}

void func_814098E8(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_50.x = arg1 * D_8140E628.unk_00.y;
}

void func_81409900(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_50.y = arg1 * D_8140E628.unk_00.y;
}

void func_81409918(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_50.z = arg1 * D_8140E628.unk_00.y;
}

void func_81409930(unk_D_8140E720* arg0, f32 arg1) {
    func_814010D8(&arg0->unk_50, arg1 * D_8140E628.unk_00.y);
}

void func_81409968(unk_D_8140E720* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_50.x += arg1 * D_8140E628.unk_00.y;
    arg0->unk_50.y += arg2 * D_8140E628.unk_00.y;
    arg0->unk_50.z += arg3 * D_8140E628.unk_00.y;
}

void func_814099C0(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_50.x += arg1 * D_8140E628.unk_00.y;
}

void func_814099E0(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_50.y += arg1 * D_8140E628.unk_00.y;
}

void func_81409A00(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_50.z += arg1 * D_8140E628.unk_00.y;
}

void func_81409A20(unk_D_8140E720* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_50.x -= arg1 * D_8140E628.unk_00.y;
    arg0->unk_50.y -= arg2 * D_8140E628.unk_00.y;
    arg0->unk_50.z -= arg3 * D_8140E628.unk_00.y;
}

void func_81409A78(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_50.x -= arg1 * D_8140E628.unk_00.y;
}

void func_81409A98(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_50.y -= arg1 * D_8140E628.unk_00.y;
}

void func_81409AB8(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_50.z -= arg1 * D_8140E628.unk_00.y;
}

s32 func_81409AD8(unk_D_8140E720* arg0, f32 arg1) {
    return func_81400760(&arg0->unk_50.x, arg1 * D_8140E628.unk_00.y, arg0->unk_5C.x);
}

s32 func_81409B18(unk_D_8140E720* arg0, f32 arg1) {
    return func_81400760(&arg0->unk_50.y, arg1 * D_8140E628.unk_00.y, arg0->unk_5C.y);
}

s32 func_81409B58(unk_D_8140E720* arg0, f32 arg1) {
    return func_81400760(&arg0->unk_50.z, arg1 * D_8140E628.unk_00.y, arg0->unk_5C.z);
}

void func_81409B98(unk_D_8140E720* arg0) {
    arg0->unk_50.x = arg0->unk_7C.x;
    arg0->unk_50.y = arg0->unk_7C.y;
    arg0->unk_50.z = arg0->unk_7C.z;
}

void func_81409BB4(unk_D_8140E720* arg0) {
    arg0->unk_50.x = arg0->unk_7C.x;
    arg0->unk_50.z = arg0->unk_7C.z;
}

void func_81409BC8(unk_D_8140E720* arg0) {
    arg0->unk_50.x = arg0->unk_7C.x;
    arg0->unk_50.y = arg0->unk_7C.y;
}

void func_81409BDC(unk_D_8140E720* arg0) {
    arg0->unk_50.x += arg0->unk_7C.x;
    arg0->unk_50.y += arg0->unk_7C.y;
    arg0->unk_50.z += arg0->unk_7C.z;
}

void func_81409C10(unk_D_8140E720* arg0) {
    arg0->unk_50.x += arg0->unk_7C.x;
    arg0->unk_50.z += arg0->unk_7C.z;
}

void func_81409C34(unk_D_8140E720* arg0) {
    arg0->unk_50.x += arg0->unk_7C.x;
    arg0->unk_50.y += arg0->unk_7C.y;
}

void func_81409C58(unk_D_8140E720* arg0) {
    arg0->unk_50.x += arg0->unk_7C.x;
}

void func_81409C6C(unk_D_8140E720* arg0) {
    arg0->unk_50.y += arg0->unk_7C.y;
}

void func_81409C80(unk_D_8140E720* arg0) {
    arg0->unk_50.z += arg0->unk_7C.z;
}

void func_81409C94(unk_D_8140E720* arg0) {
    func_8140B278(arg0);
    func_81409BB4(arg0);
}

void func_81409CBC(unk_D_8140E720* arg0) {
    func_8140B278(arg0);
    func_81409C10(arg0);
}

void func_81409CE4(unk_D_8140E720* arg0) {
    func_8140B23C(arg0);
    func_81409C34(arg0);
}

void func_81409D0C(unk_D_8140E720* arg0) {
    func_8140B2B4(arg0);
    func_81409BDC(arg0);
}

void func_81409D34(unk_D_8140E720* arg0) {
    func_8140B330(arg0);
    func_81409BDC(arg0);
}

void func_81409D5C(unk_D_8140E720* arg0) {
    func_8140B3AC(arg0);
    func_81409BDC(arg0);
}

void func_81409D84(unk_D_8140E720* arg0) {
    func_8140B42C(arg0);
    func_81409BDC(arg0);
}

void func_81409DAC(unk_D_8140E720* arg0) {
    func_8140B568(arg0);
    func_81409BDC(arg0);
}

void func_81409DD4(unk_D_8140E720* arg0) {
    func_8140B4A0(arg0);
    func_81409BDC(arg0);
}

void func_81409DFC(unk_D_8140E720* arg0) {
    func_8140B638(arg0);
    func_81409BDC(arg0);
}

void func_81409E24(unk_D_8140E720* arg0) {
    func_8140B638(arg0);
    func_81409BDC(arg0);
}

void func_81409E4C(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = arg0->unk_74 * SINS(arg0->unk_94.y);
    arg0->unk_7C.z = arg0->unk_74 * COSS(arg0->unk_94.y);

    func_81409C10(arg0);
}

void func_81409EA0(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = arg0->unk_74 * SINS(arg0->unk_94.y + 0x8000);
    arg0->unk_7C.z = arg0->unk_74 * COSS(arg0->unk_94.y + 0x8000);

    func_81409C10(arg0);
}

void func_81409F00(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_7C.x = SINS(arg0->unk_94.y + 0x8000) * arg1;
    arg0->unk_7C.z = COSS(arg0->unk_94.y + 0x8000) * arg1;

    func_81409C10(arg0);
}

void func_81409F60(unk_D_8140E720* arg0) {
    arg0->unk_7C.y = arg0->unk_74;

    func_81409C6C(arg0);
}

s32 func_81409F84(unk_D_8140E720* arg0) {
    s32 sp1C = 0;

    arg0->unk_7C.y = -arg0->unk_74;
    func_81409C6C(arg0);

    if (arg0->unk_2C.y <= 0.0f) {
        sp1C = 1;
    }
    return sp1C;
}

s32 func_81409FD8(unk_D_8140E720* arg0) {
    s32 sp1C = 0;

    arg0->unk_74 += arg0->unk_78;
    arg0->unk_7C.y = -arg0->unk_74;

    func_81409C6C(arg0);

    if (arg0->unk_2C.y <= 0.0f) {
        sp1C = 1;
    }
    return sp1C;
}

void func_8140A03C(unk_D_8140E720* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_5C.x = arg1 * D_8140E628.unk_00.y;
    arg0->unk_5C.y = arg2 * D_8140E628.unk_00.y;
    arg0->unk_5C.z = arg3 * D_8140E628.unk_00.y;
}

void func_8140A07C(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_5C.x = arg1 * D_8140E628.unk_00.y;
}

void func_8140A094(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_5C.y = arg1 * D_8140E628.unk_00.y;
}

void func_8140A0AC(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_5C.z = arg1 * D_8140E628.unk_00.y;
}

s32 func_8140A0C4(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    return func_81400760(&arg0->unk_5C.y, arg1 * D_8140E628.unk_00.y, arg2 * D_8140E628.unk_00.y);
}

f32 func_8140A108(f32 arg0) {
    return arg0 * 0.4f;
}

void func_8140A11C(unk_D_8140E720* arg0, Vec3f arg1) {
    f32 sp24;
    f32 sp20;
    f32 temp_fa0;

    temp_fa0 = arg1.x - arg0->unk_38.x;
    sp20 = arg1.y - arg0->unk_38.y;
    sp24 = arg1.z - arg0->unk_38.z;

    if (!(temp_fa0 <= 0.01f) || !(temp_fa0 >= -0.01f)) {
        func_81400760(&arg0->unk_38.x, arg1.x, func_8140A108(temp_fa0));
    }

    if (!(sp20 <= 0.01f) || !(sp20 >= -0.01f)) {
        func_81400760(&arg0->unk_38.y, arg1.y, func_8140A108(sp20));
    }

    if (!(sp24 <= 0.01f) || !(sp24 >= -0.01f)) {
        func_81400760(&arg0->unk_38.z, arg1.z, func_8140A108(sp24));
    }
}

void func_8140A24C(unk_D_8140E720* arg0, Vec3s arg1) {
    arg0->unk_94.x = arg1.x;
    arg0->unk_94.y = arg1.y;
    arg0->unk_94.z = arg1.z;
}

void func_8140A270(unk_D_8140E720* arg0, s16 arg1, s16 arg2, s16 arg3) {
    arg0->unk_94.x = arg1;
    arg0->unk_94.y = arg2;
    arg0->unk_94.z = arg3;
}

void func_8140A2A4(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_94.x = arg1;
}

void func_8140A2B8(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_94.y = arg1;
}

void func_8140A2CC(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_94.z = arg1;
}

void func_8140A2E0(unk_D_8140E720* arg0) {
    arg0->unk_94.x += 0x8000;
    arg0->unk_94.y += 0x8000;
    arg0->unk_94.z += 0x8000;
}

void func_8140A30C(unk_D_8140E720* arg0) {
    arg0->unk_94.x += 0x8000;
}

void func_8140A320(unk_D_8140E720* arg0) {
    arg0->unk_94.y += 0x8000;
}

void func_8140A334(unk_D_8140E720* arg0) {
    arg0->unk_94.z += 0x8000;
}

void func_8140A348(unk_D_8140E720* arg0, s16 arg1, s16 arg2, s16 arg3) {
    arg0->unk_9A.x = arg1;
    arg0->unk_9A.y = arg2;
    arg0->unk_9A.z = arg3;
}

void func_8140A37C(unk_D_8140E720* arg0, Vec3s arg1) {
    arg0->unk_9A.x = arg1.x;
    arg0->unk_9A.y = arg1.y;
    arg0->unk_9A.z = arg1.z;
}

void func_8140A3A0(unk_D_8140E720* arg0, s16 arg1, s16 arg2) {
    arg0->unk_9A.x = arg1;
    arg0->unk_9A.y = arg2;
}

void func_8140A3C4(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_9A.x = arg1;
}

void func_8140A3D8(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_9A.y = arg1;
}

void func_8140A3EC(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_9A.z = arg1;
}

void func_8140A400(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_A0.x = arg1;
}

void func_8140A414(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_A0.y = arg1;
}

void func_8140A428(unk_D_8140E720* arg0, s16 arg1, s16 arg2) {
    func_8140A400(arg0, arg1);
    func_8140A414(arg0, arg2);
}

void func_8140A464(unk_D_8140E720* arg0) {
    arg0->unk_A0.x = arg0->unk_94.x;
    arg0->unk_A0.y = arg0->unk_94.y;
    arg0->unk_A0.z = arg0->unk_94.z;
}

void func_8140A480(unk_D_8140E720* arg0) {
    arg0->unk_94.x += arg0->unk_9A.x;
    arg0->unk_94.y += arg0->unk_9A.y;
    arg0->unk_94.z += arg0->unk_9A.z;
}

void func_8140A4B4(unk_D_8140E720* arg0) {
    arg0->unk_94.x += arg0->unk_9A.x;
}

void func_8140A4C8(unk_D_8140E720* arg0) {
    arg0->unk_94.y += arg0->unk_9A.y;
}

void func_8140A4DC(unk_D_8140E720* arg0) {
    arg0->unk_94.z += arg0->unk_9A.z;
}

void func_8140A4F0(unk_D_8140E720* arg0, Vec3s arg1) {
    arg0->unk_94.x += arg1.x;
    arg0->unk_94.y += arg1.y;
    arg0->unk_94.z += arg1.z;
}

void func_8140A52C(unk_D_8140E720* arg0, s16 arg1, s16 arg2, s16 arg3) {
    arg0->unk_94.x += arg1;
    arg0->unk_94.y += arg2;
    arg0->unk_94.z += arg3;
}

void func_8140A578(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_94.x += arg1;
}

void func_8140A594(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_94.y += arg1;
}

void func_8140A5B0(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_94.z += arg1;
}

void func_8140A5CC(unk_D_8140E720* arg0, s16 arg1, s16 arg2) {
    arg0->unk_A0.x += arg1;
    arg0->unk_A0.y += arg2;
}

void func_8140A600(unk_D_8140E720* arg0, Vec3s arg1) {
    arg0->unk_94.x -= arg1.x;
    arg0->unk_94.y -= arg1.y;
    arg0->unk_94.z -= arg1.z;
}

void func_8140A63C(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_94.x -= arg1;
}

void func_8140A658(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_94.y -= arg1;
}

void func_8140A674(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_94.z -= arg1;
}

void func_8140A690(unk_D_8140E720* arg0) {
    func_814005EC(&arg0->unk_94.x, arg0->unk_A0.x, arg0->unk_9A.x);
}

void func_8140A6BC(unk_D_8140E720* arg0) {
    func_814005EC(&arg0->unk_94.y, arg0->unk_A0.y, arg0->unk_9A.y);
}

void func_8140A6E8(unk_D_8140E720* arg0) {
    func_814005EC(&arg0->unk_94.z, arg0->unk_A0.z, arg0->unk_9A.z);
}

void func_8140A714(unk_D_8140E720* arg0) {
    func_8140A690(arg0);
    func_8140A6BC(arg0);
}

void func_8140A73C(unk_D_8140E720* arg0) {
    func_8140A690(arg0);
    func_8140A6BC(arg0);
    func_8140A6E8(arg0);
}

void func_8140A76C(unk_D_8140E720* arg0, s16 arg1, s16 arg2) {
    func_814005EC(&arg0->unk_94.x, arg1, arg2);
}

void func_8140A7A4(unk_D_8140E720* arg0, s16 arg1, s16 arg2) {
    func_814005EC(&arg0->unk_94.y, arg1, arg2);
}

s32 func_8140A7DC(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;
    s32 var_v0 = arg0->unk_94.x;

    if (arg1 < var_v0) {
        var_v0 -= arg2;
        if (arg1 >= var_v0) {
            var_v0 = arg1;
            var_v1 = 1;
        }
        arg0->unk_94.x = var_v0;
    }

    return var_v1;
}

s32 func_8140A810(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;
    s32 var_v0 = arg0->unk_94.y;

    if (arg1 < var_v0) {
        var_v0 -= arg2;
        if (arg1 >= var_v0) {
            var_v0 = arg1;
            var_v1 = 1;
        }
        arg0->unk_94.y = var_v0;
    }

    return var_v1;
}

s32 func_8140A844(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    s32 var_v0 = arg0->unk_94.z;
    s32 var_v1 = 0;

    if (arg1 < var_v0) {
        var_v0 -= arg2;
        if (arg1 >= var_v0) {
            var_v0 = arg1;
            var_v1 = 1;
        }
        arg0->unk_94.z = var_v0;
    }
    return var_v1;
}

void func_8140A878(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    func_8140A578(arg0, func_81400B00(arg1));
    func_8140A594(arg0, func_81400B00(arg2));
}

void func_8140A8C8(unk_D_8140E720* arg0, s32 arg1, s32 arg2) {
    func_8140A578(arg0, func_81400B28(arg1, 0x8000));
    func_8140A594(arg0, func_81400B00(arg2));
}

void func_8140A91C(unk_D_8140E720* arg0, s32 arg1) {
    func_8140A594(arg0, func_81400B00(arg1));
}

void func_8140A950(unk_D_8140E720* arg0, s32 arg1) {
    func_8140A594(arg0, func_81400B28(arg1, 0x8000));
}

void func_8140A988(unk_D_8140E720* arg0) {
    func_8140A578(arg0, func_81400B00(0x10000));
    func_8140A594(arg0, 0x4000);
}

void func_8140A9C8(unk_D_8140E720* arg0, f32 arg1, Vec3f* arg2) {
    arg2->x = SINS(arg0->unk_94.y) * arg1;
    arg2->y = 0.0f;
    arg2->z = COSS(arg0->unk_94.y) * arg1;
}

void func_8140AA18(unk_D_8140E720* arg0, f32 arg1, Vec3f* arg2) {
    arg2->x = arg1 * COSS(arg0->unk_94.x) * SINS(arg0->unk_94.y);
    arg2->y = -arg1 * SINS(arg0->unk_94.x);
    arg2->z = arg1 * COSS(arg0->unk_94.x) * COSS(arg0->unk_94.y);
}

void func_8140AAB8(unk_D_8140E720* arg0, f32 arg1, Vec3f* arg2) {
    arg2->x = arg1 * SINS(arg0->unk_94.x) * SINS(arg0->unk_94.z);
    arg2->y = -arg1 * SINS(arg0->unk_94.x) * COSS(arg0->unk_94.z);
    arg2->z = arg1 * COSS(arg0->unk_94.x);
}

void func_8140AB58(unk_D_8140E720* arg0, f32 arg1, Vec3f* arg2) {
    arg2->x = arg1 * (SINS(arg0->unk_94.x) * COSS(arg0->unk_94.y) * SINS(arg0->unk_94.z) +
                      COSS(arg0->unk_94.x) * SINS(arg0->unk_94.y));
    arg2->y = -arg1 * SINS(arg0->unk_94.x) * COSS(arg0->unk_94.z);
    arg2->z = arg1 * (COSS(arg0->unk_94.x) * COSS(arg0->unk_94.y) -
                      SINS(arg0->unk_94.x) * SINS(arg0->unk_94.y) * SINS(arg0->unk_94.z));
}

void func_8140AC70(unk_D_8140E720* arg0, f32 arg1, Vec3f* arg2) {
    arg2->x = arg1 * (SINS(arg0->unk_94.y) * COSS(arg0->unk_94.z) +
                      SINS(arg0->unk_94.x) * COSS(arg0->unk_94.y) * SINS(arg0->unk_94.z));
    arg2->y = arg1 * (SINS(arg0->unk_94.y) * SINS(arg0->unk_94.z) -
                      SINS(arg0->unk_94.x) * COSS(arg0->unk_94.y) * COSS(arg0->unk_94.z));
    arg2->z = arg1 * (COSS(arg0->unk_94.x) * COSS(arg0->unk_94.y));
}

void func_8140AD8C(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_74 = arg1 * D_8140E628.unk_00.y;
}

void func_8140ADA4(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_78 = arg1 * D_8140E628.unk_00.y;
}

s32 func_8140ADBC(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    return func_81400760(&arg0->unk_74, arg1 * D_8140E628.unk_00.y, arg2 * D_8140E628.unk_00.y);
}

s32 func_8140AE00(unk_D_8140E720* arg0, f32 arg1) {
    return func_81400760(&arg0->unk_74, arg1 * D_8140E628.unk_00.y, arg0->unk_78);
}

s32 func_8140AE40(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    return func_81400760(&arg0->unk_78, arg1 * D_8140E628.unk_00.y, arg2 * D_8140E628.unk_00.y);
}

void func_8140AE84(unk_D_8140E720* arg0, Vec3f arg1) {
    arg0->unk_7C.x = arg1.x * D_8140E628.unk_00.y;
    arg0->unk_7C.y = arg1.y * D_8140E628.unk_00.y;
    arg0->unk_7C.z = arg1.z * D_8140E628.unk_00.y;
}

void func_8140AECC(unk_D_8140E720* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_7C.x = arg1 * D_8140E628.unk_00.y;
    arg0->unk_7C.y = arg2 * D_8140E628.unk_00.y;
    arg0->unk_7C.z = arg3 * D_8140E628.unk_00.y;
}

void func_8140AF0C(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_7C.x = arg1 * D_8140E628.unk_00.y;
}

void func_8140AF24(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_7C.y = arg1 * D_8140E628.unk_00.y;
}

void func_8140AF3C(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_7C.z = arg1 * D_8140E628.unk_00.y;
}

s32 func_8140AF54(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    f32 temp_fv0;
    s32 var_v1 = 0;

    arg0->unk_7C.x += arg2 * D_8140E628.unk_00.y;

    temp_fv0 = arg1 * D_8140E628.unk_00.y;
    if (temp_fv0 <= arg0->unk_7C.x) {
        arg0->unk_7C.x = temp_fv0;
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8140AFA8(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    f32 temp_fv0;
    s32 var_v1 = 0;

    arg0->unk_7C.y += arg2 * D_8140E628.unk_00.y;

    temp_fv0 = arg1 * D_8140E628.unk_00.y;
    if (temp_fv0 <= arg0->unk_7C.y) {
        arg0->unk_7C.y = temp_fv0;
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8140AFFC(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    f32 temp_fv0;
    s32 var_v1 = 0;

    arg0->unk_7C.z += arg2 * D_8140E628.unk_00.y;

    temp_fv0 = arg1 * D_8140E628.unk_00.y;
    if (temp_fv0 <= arg0->unk_7C.z) {
        arg0->unk_7C.z = temp_fv0;
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8140B050(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    f32 temp_fv0;
    s32 var_v1 = 0;

    arg0->unk_7C.x -= arg2 * D_8140E628.unk_00.y;

    temp_fv0 = arg1 * D_8140E628.unk_00.y;
    if (arg0->unk_7C.x <= temp_fv0) {
        arg0->unk_7C.x = temp_fv0;
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8140B0A4(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    s32 var_v1 = 0;
    f32 temp_fv0;

    arg0->unk_7C.y -= arg2 * D_8140E628.unk_00.y;

    temp_fv0 = arg1 * D_8140E628.unk_00.y;
    if (arg0->unk_7C.y <= temp_fv0) {
        arg0->unk_7C.y = temp_fv0;
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8140B0F8(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    f32 temp_fv0;
    s32 var_v1 = 0;

    arg0->unk_7C.z -= arg2 * D_8140E628.unk_00.y;

    temp_fv0 = arg1 * D_8140E628.unk_00.y;
    if (arg0->unk_7C.z <= temp_fv0) {
        arg0->unk_7C.z = temp_fv0;
        var_v1 = 1;
    }
    return var_v1;
}

void func_8140B14C(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_7C.x *= arg1;
    arg0->unk_7C.y *= arg1;
    arg0->unk_7C.z *= arg1;
}

s32 func_8140B180(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    return func_81400760(&arg0->unk_7C.y, arg1 * D_8140E628.unk_00.y, arg2 * D_8140E628.unk_00.y);
}

void func_8140B1C4(unk_D_8140E720* arg0) {
    arg0->unk_7C.y = COSS(arg0->unk_94.x) * arg0->unk_74;
}

void func_8140B1EC(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = SINS(arg0->unk_94.y) * arg0->unk_74;
}

void func_8140B214(unk_D_8140E720* arg0) {
    arg0->unk_7C.z = COSS(arg0->unk_94.y) * arg0->unk_74;
}

void func_8140B23C(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = COSS(arg0->unk_94.z) * arg0->unk_74;
    arg0->unk_7C.y = SINS(arg0->unk_94.z) * arg0->unk_74;
}

void func_8140B278(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = SINS(arg0->unk_94.y) * arg0->unk_74;
    arg0->unk_7C.z = COSS(arg0->unk_94.y) * arg0->unk_74;
}

void func_8140B2B4(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = arg0->unk_74 * COSS(arg0->unk_94.x) * SINS(arg0->unk_94.y);
    arg0->unk_7C.y = -arg0->unk_74 * SINS(arg0->unk_94.x);
    arg0->unk_7C.z = arg0->unk_74 * COSS(arg0->unk_94.x) * COSS(arg0->unk_94.y);
}

void func_8140B330(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = arg0->unk_74 * SINS(arg0->unk_94.x) * SINS(arg0->unk_94.z);
    arg0->unk_7C.y = -arg0->unk_74 * SINS(arg0->unk_94.x) * COSS(arg0->unk_94.z);
    arg0->unk_7C.z = arg0->unk_74 * COSS(arg0->unk_94.x);
}

void func_8140B3AC(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = arg0->unk_74 * SINS(arg0->unk_94.y);
    arg0->unk_7C.y = -arg0->unk_74 * SINS(arg0->unk_94.x) * COSS(arg0->unk_94.y);
    arg0->unk_7C.z = arg0->unk_74 * COSS(arg0->unk_94.x) * COSS(arg0->unk_94.y);
}

void func_8140B42C(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = arg0->unk_74 * SINS(arg0->unk_94.y) * COSS(arg0->unk_94.z);
    arg0->unk_7C.y = arg0->unk_74 * SINS(arg0->unk_94.y) * SINS(arg0->unk_94.z);
    arg0->unk_7C.z = COSS(arg0->unk_94.y);
}

void func_8140B4A0(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = arg0->unk_74 * (COSS(arg0->unk_94.x) * SINS(arg0->unk_94.y) * COSS(arg0->unk_94.z) +
                                     SINS(arg0->unk_94.x) * SINS(arg0->unk_94.z));
    arg0->unk_7C.y = -arg0->unk_74 * (COSS(arg0->unk_94.x) * SINS(arg0->unk_94.y) * SINS(arg0->unk_94.z) -
                                      SINS(arg0->unk_94.x) * COSS(arg0->unk_94.z));
    arg0->unk_7C.z = arg0->unk_74 * (COSS(arg0->unk_94.x) * COSS(arg0->unk_94.y));
}

void func_8140B568(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = arg0->unk_74 * (SINS(arg0->unk_94.x) * COSS(arg0->unk_94.y) * SINS(arg0->unk_94.z) +
                                     COSS(arg0->unk_94.x) * SINS(arg0->unk_94.y));
    arg0->unk_7C.y = -arg0->unk_74 * SINS(arg0->unk_94.x) * COSS(arg0->unk_94.z);

    arg0->unk_7C.z = arg0->unk_74 * (-SINS(arg0->unk_94.x) * SINS(arg0->unk_94.y) * SINS(arg0->unk_94.z) +
                                     COSS(arg0->unk_94.x) * COSS(arg0->unk_94.y));
}

void func_8140B638(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = arg0->unk_74 * SINS(arg0->unk_94.y) * COSS(arg0->unk_94.z);
    arg0->unk_7C.y = arg0->unk_74 * (COSS(arg0->unk_94.x) * SINS(arg0->unk_94.y) * SINS(arg0->unk_94.z) -
                                     SINS(arg0->unk_94.x) * COSS(arg0->unk_94.y));
    arg0->unk_7C.z = arg0->unk_74 * (SINS(arg0->unk_94.x) * SINS(arg0->unk_94.y) * SINS(arg0->unk_94.z) +
                                     COSS(arg0->unk_94.x) * COSS(arg0->unk_94.y));
}

void func_8140B700(unk_D_8140E720* arg0) {
    arg0->unk_7C.x = arg0->unk_74 * (SINS(arg0->unk_94.y) * COSS(arg0->unk_94.z) +
                                     SINS(arg0->unk_94.x) * COSS(arg0->unk_94.y) * SINS(arg0->unk_94.z));
    arg0->unk_7C.y = arg0->unk_74 * (SINS(arg0->unk_94.y) * SINS(arg0->unk_94.z) -
                                     SINS(arg0->unk_94.x) * COSS(arg0->unk_94.y) * COSS(arg0->unk_94.z));
    arg0->unk_7C.z = arg0->unk_74 * (COSS(arg0->unk_94.x) * COSS(arg0->unk_94.y));
}

void func_8140B7C8(unk_D_8140E720* arg0, f32 arg1, s16 arg2) {
    f32 tmp1 = arg0->unk_50.x;
    f32 tmp2 = arg0->unk_50.z;

    arg0->unk_9A.y += arg2;

    arg0->unk_50.x = arg1 * D_8140E628.unk_00.y * SINS(arg0->unk_9A.y);
    arg0->unk_50.z = arg1 * D_8140E628.unk_00.y * COSS(arg0->unk_9A.y);

    arg0->unk_7C.x = arg0->unk_50.x - tmp1;
    arg0->unk_7C.z = arg0->unk_50.z - tmp2;
}

s32 func_8140B854(unk_D_8140E720* arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5) {
    s32 sp24 = 0;

    if (func_81408308(arg0, 2) != 0) {
        func_814082B4(arg0, 2);
        arg0->unk_50.x = arg0->unk_50.y = arg0->unk_50.z = 0.0f;
        arg0->unk_74 = arg3 * D_8140E628.unk_00.y;
        arg0->unk_7C.y = arg1 * D_8140E628.unk_00.y;
        arg0->unk_94.y = arg4;
        func_8140B278(arg0);
        arg0->unk_BA = arg5;
    }

    arg0->unk_BA--;
    if (arg0->unk_BA < 0) {
        sp24 = 1;
    } else {
        arg0->unk_7C.y -= arg2 * D_8140E628.unk_00.y;
        func_81409BDC(arg0);
    }

    return sp24;
}

void func_8140B938(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_1C = arg1 * D_8140E628.unk_00.y;
}

void func_8140B950(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_1C = arg1;
}

void func_8140B95C(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_20 = arg1 * D_8140E628.unk_00.y;
}

void func_8140B974(unk_D_8140E720* arg0, f32 arg1) {
    arg0->unk_24 = arg1 * D_8140E628.unk_00.y;
}

s32 func_8140B98C(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    return func_81400760(&arg0->unk_1C, arg1 * D_8140E628.unk_00.y, arg2 * D_8140E628.unk_00.y);
}

s32 func_8140B9D0(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    s32 sp1C = func_8140B98C(arg0, arg1, arg2);

    if (sp1C != 0) {
        func_814081BC(arg0);
    }
    return sp1C;
}

s32 func_8140BA1C(unk_D_8140E720* arg0) {
    return func_81400760(&arg0->unk_1C, arg0->unk_20, arg0->unk_24);
}

s32 func_8140BA48(unk_D_8140E720* arg0) {
    s32 sp1C = func_8140BA1C(arg0);

    if (sp1C != 0) {
        func_814081BC(arg0);
    }
    return sp1C;
}

s32 func_8140BA84(unk_D_8140E720* arg0, f32 arg1, f32 arg2) {
    return func_81400760(&arg0->unk_20, arg1 * D_8140E628.unk_00.y, arg2 * D_8140E628.unk_00.y);
}

void func_8140BAC8(unk_D_8140E720* arg0, u8 arg1, u8 arg2, u8 arg3) {
    arg0->prim_r = arg1;
    arg0->prim_g = arg2;
    arg0->prim_b = arg3;
}

s32 func_8140BAE4(unk_D_8140E720* arg0, u8 arg1, u8 arg2) {
    return func_814004D8(&arg0->prim_r, arg1, arg2);
}

s32 func_8140BB14(unk_D_8140E720* arg0, u8 arg1, u8 arg2) {
    return func_814004D8(&arg0->prim_g, arg1, arg2);
}

s32 func_8140BB44(unk_D_8140E720* arg0, u8 arg1, u8 arg2) {
    return func_814004D8(&arg0->prim_b, arg1, arg2);
}

void func_8140BB74(unk_D_8140E720* arg0, u8 arg1, u8 arg2, u8 arg3) {
    arg0->env_r = arg1;
    arg0->env_g = arg2;
    arg0->env_b = arg3;
}

s32 func_8140BB90(unk_D_8140E720* arg0, u8 arg1, u8 arg2) {
    return func_814004D8(&arg0->env_r, arg1, arg2);
}

s32 func_8140BBC0(unk_D_8140E720* arg0, u8 arg1, u8 arg2) {
    return func_814004D8(&arg0->env_b, arg1, arg2);
}

s32 func_8140BBF0(unk_D_8140E720* arg0, u8 arg1, u8 arg2) {
    return func_814004D8(&arg0->env_g, arg1, arg2);
}

void func_8140BC20(unk_D_8140E720* arg0, u8 arg1) {
    arg0->prim_a = arg1;
}

s32 func_8140BC2C(unk_D_8140E720* arg0, u8 arg1, u8 arg2) {
    return func_814004D8(&arg0->prim_a, arg1, arg2);
}

s32 func_8140BC5C(unk_D_8140E720* arg0, u8 arg1, u8 arg2) {
    s32 sp1C = func_8140BC2C(arg0, arg1, arg2);

    if (sp1C != 0) {
        func_814081BC(arg0);
    }
    return sp1C;
}

void func_8140BCA8(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_A6 = arg1;
}

s16 func_8140BCBC(unk_D_8140E720* arg0) {
    return arg0->unk_A6;
}

s32 func_8140BCC4(unk_D_8140E720* arg0, s16 arg1, s16 arg2) {
    s32 var_v1 = 0;

    arg0->unk_A6 -= arg2;
    if (arg1 >= arg0->unk_A6) {
        arg0->unk_A6 = arg1;
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8140BD08(unk_D_8140E720* arg0, s16 arg1) {
    return func_8140BCC4(arg0, 0, arg1);
}

s32 func_8140BD34(unk_D_8140E720* arg0, s16 arg1) {
    s32 sp1C = func_8140BCC4(arg0, 0, arg1);

    if (sp1C != 0) {
        func_814081BC(arg0);
    }
    return sp1C;
}

s32 func_8140BD80(unk_D_8140E720* arg0, s16 arg1) {
    return func_8140BCC4(arg0, arg1, 1);
}

s32 func_8140BDAC(unk_D_8140E720* arg0) {
    return func_8140BCC4(arg0, 0, 1);
}

s32 func_8140BDD0(unk_D_8140E720* arg0) {
    s32 sp1C = func_8140BCC4(arg0, 0, 1);

    if (sp1C != 0) {
        func_814081BC(arg0);
    }
    return sp1C;
}

void func_8140BE14(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_A8 = arg1;
}

s16 func_8140BE28(unk_D_8140E720* arg0) {
    return arg0->unk_A8;
}

s32 func_8140BE30(unk_D_8140E720* arg0, s16 arg1) {
    s32 var_v1 = 0;

    arg0->unk_A8--;
    if (arg1 >= arg0->unk_A8) {
        arg0->unk_A8 = arg1;
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_8140BE6C(unk_D_8140E720* arg0) {
    return func_8140BE30(arg0, 0);
}

s32 func_8140BE8C(unk_D_8140E720* arg0) {
    s32 sp1C = func_8140BE30(arg0, 0);

    if (sp1C != 0) {
        func_814081BC(arg0);
    }
    return sp1C;
}

void func_8140BECC(unk_D_8140E720* arg0, u8 arg1) {
    arg0->unk_CA = arg1;
}

void func_8140BED8(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_AC = arg1;
}

void func_8140BEEC(unk_D_8140E720* arg0, u8 arg1) {
    arg0->unk_CF = arg1;
}

void func_8140BEF8(unk_D_8140E720* arg0, u8 arg1) {
    arg0->unk_CF = arg1;
}

void func_8140BF04(unk_D_8140E720* arg0, u8 arg1) {
    arg0->unk_CC = arg1;
}

void func_8140BF10(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_AA = arg1;
}

void func_8140BF24(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_CE = arg1;
}

void func_8140BF38(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_CD = arg1;
}

void func_8140BF4C(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_AE = arg1;
}

s32 func_8140BF60(unk_D_8140E720* arg0, s16 arg1, s16 arg2) {
    return func_81400550(&arg0->unk_AE, arg1, arg2);
}

s32 func_8140BF98(unk_D_8140E720* arg0, s16 arg1, s16 arg2) {
    s32 sp1C = func_8140BF60(arg0, arg1, arg2);

    if (sp1C != 0) {
        func_814081BC(arg0);
    }
    return sp1C;
}

void func_8140BFEC(unk_D_8140E720* arg0, s16 arg1) {
    arg0->unk_B0 = arg1;
}

s32 func_8140C000(unk_D_8140E720* arg0, s16 arg1, s16 arg2) {
    return func_81400550(&arg0->unk_B0, arg1, arg2);
}

s16 func_8140C038(unk_D_8140E720* arg0) {
    return arg0->unk_AC;
}

u8 func_8140C040(unk_D_8140E720* arg0) {
    return arg0->unk_CE;
}

u8 func_8140C048(unk_D_8140E720* arg0) {
    return arg0->unk_CD;
}

s16 func_8140C050(unk_D_8140E720* arg0) {
    return arg0->unk_AE;
}

s16 func_8140C058(unk_D_8140E720* arg0) {
    s32 tmp = arg0->unk_CF;
    return tmp;
}

s16 func_8140C068(unk_D_8140E720* arg0) {
    return arg0->unk_AA;
}

void func_8140C070(unk_D_8140E720* arg0, s16 arg1) {
    if ((u32)arg0 != -1) {
        func_8140BED8(arg0, arg1);
    }
}

void func_8140C0A4(unk_D_8140E720* arg0, u8 arg1) {
    if ((u32)arg0 != -1) {
        func_8140BEEC(arg0, arg1);
    }
}

void func_8140C0D4(unk_D_8140E720* arg0, s16 arg1) {
    if ((u32)arg0 != -1) {
        func_8140BCA8(arg0, arg1);
    }
}

void func_8140C108(unk_D_8140E720* arg0, s16 arg1) {
    if ((u32)arg0 != -1) {
        func_8140BE14(arg0, arg1);
    }
}

void func_8140C13C(unk_D_8140E720* arg0, u8 arg1) {
    if ((u32)arg0 != -1) {
        arg0->unk_CE = arg1;
    }
}

void func_8140C158(unk_D_8140E720* arg0, u8 arg1) {
    if ((u32)arg0 != -1) {
        arg0->unk_CD = arg1;
    }
}

void func_8140C174(unk_D_8140E720* arg0, s16 arg1) {
    if ((u32)arg0 != -1) {
        arg0->unk_AA = arg1;
    }
}

void func_8140C194(unk_D_8140E720* arg0, u8 arg1) {
    if ((u32)arg0 != -1) {
        func_8140BC20(arg0, arg1);
    }
}

void func_8140C1C4(unk_D_8140E720* arg0, s16 arg1) {
    if ((u32)arg0 != -1) {
        arg0->unk_AE = arg1;
    }
}

void func_8140C1E4(unk_D_8140E720* arg0, s16 arg1) {
    if ((u32)arg0 != -1) {
        arg0->unk_B0 = arg1;
    }
}

void func_8140C204(unk_D_86002F34_00C* arg0) {
    s32 i;
    unk_D_8140E720* var_s0;
    unk_D_8140E720* var_s2 = D_8140E720;

    for (i = 0; i < 0x12C; i++, var_s2++) {
        if ((var_s2->unk_D0 != 0) && (var_s2->prev == NULL) && (func_81408308(var_s2, 8) != 0)) {
            func_8140C4CC(var_s2);
            var_s0 = var_s2;
            while (var_s0 != NULL) {
                if ((func_814082E8(var_s0, 4) != 0) && (var_s0->unk_B2 >= 2)) {
                    func_8140C530(var_s0, arg0);
                }
                var_s0 = var_s0->next;
            }
        }
    }
}

void func_8140C2D8(unk_D_86002F34_00C* arg0) {
    s32 i;
    unk_D_8140E720* var_s0 = D_8140E720;

    for (i = 0; i < 0x12C; i++, var_s0++) {
        if ((var_s0->unk_D0 != 0) && (func_814082E8(var_s0, 8) != 0)) {
            func_8140C4CC(var_s0);
            if ((func_814082E8(var_s0, 4) != 0) && (var_s0->unk_B2 >= 2)) {
                func_8140C530(var_s0, arg0);
            }
        }
    }
}

void func_8140C384(s16 arg0) {
    switch (arg0) {
        case 0:
            gSPDisplayList(gDisplayListHead++, D_8140DD58);
            break;

        case 2:
            gSPDisplayList(gDisplayListHead++, D_8140DC78);
            break;

        case 1:
            gSPDisplayList(gDisplayListHead++, D_8140DCD8);
            break;

        case 3:
            gSPDisplayList(gDisplayListHead++, D_8140DC00);
            break;
    }
}

void func_8140C468(unk_D_8140E720* arg0, unk_D_8140E728_01C_004_1* arg1) {
    switch (arg1->unk_01) {
        case 0:
            arg1->unk_04(arg0, arg1->unk_0C.arg, arg1);
            break;

        case 1:
            arg1->unk_04(arg0, arg1->unk_0C.s->arg, arg1);
            break;
    }
}

void func_8140C4CC(unk_D_8140E720* arg0) {
    UNUSED s32 pad;
    unk_D_8140E728_01C_004_1* sp18 = arg0->unk_0C->unk_04.a;

    if (arg0->unk_0C->unk_00 == 1) {
        func_8140C384(sp18->unk_02);
        if (sp18->unk_00 == 1) {
            func_8140C468(arg0, sp18);
        }
    }
}

void func_8140C530(unk_D_8140E720* arg0, unk_D_86002F34_00C* arg1) {
    UNUSED s32 pad;
    unk_D_8140E728_01C_004_1* sp18 = arg0->unk_0C->unk_04.a;

    switch (arg0->unk_0C->unk_00) {
        case 1:
            if (sp18->unk_00 == 0) {
                func_8140C468(arg0, sp18);
            }
            sp18->unk_08(arg0, arg1, sp18);
            break;

        case 3:
            arg0->unk_0C->unk_04.func(arg0, arg1);
            break;
    }
}

void func_8140C5BC(UNUSED unk_D_8140E720* arg0, UNUSED unk_D_86002F34_00C* arg1) {
}
