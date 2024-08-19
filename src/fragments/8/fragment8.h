#ifndef _FRAGMENT8_H_
#define _FRAGMENT8_H_

#include "global.h"

typedef struct unk_D_86204720 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ unk_D_86002F58_004 unk_004;
    /* 0x16C */ s32 unk_16C;
    /* 0x170 */ s16 unk_170;
    /* 0x172 */ s8 unk_172[6];
    /* 0x178 */ s16 unk_178;
    /* 0x17A */ u16 unk_17A;
} unk_D_86204720; // size = 0x17C

typedef struct unk_D_86203E50 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ char pad4[4];
    /* 0x008 */ unk_D_86002F58_004 unk_008;
    /* 0x170 */ u16 unk_170;
    /* 0x172 */ char pad172[2];
    /* 0x174 */ f32 unk_174;
    /* 0x178 */ f32 unk_178;
    /* 0x17C */ f32 unk_17C;
    /* 0x180 */ f32 unk_180;
    /* 0x184 */ f32 unk_184;
    /* 0x188 */ f32 unk_188;
    /* 0x18C */ f32 unk_18C;
    /* 0x190 */ f32 unk_190;
    /* 0x194 */ f32 unk_194;
    /* 0x198 */ f32 unk_198;
    /* 0x19C */ s16 unk_19C;
    /* 0x19E */ s16 unk_19E;
    /* 0x1A0 */ s16 unk_1A0;
    /* 0x1A2 */ s16 unk_1A2;
    /* 0x1A4 */ f32 unk_1A4;
    /* 0x1A8 */ f32 unk_1A8;
    /* 0x1AC */ s16 unk_1AC;
    /* 0x1AE */ s16 unk_1AE;
    /* 0x1B0 */ s16 unk_1B0;
    /* 0x1B2 */ s16 unk_1B2;
    /* 0x1B4 */ s16 unk_1B4;
    /* 0x1B6 */ char pad1B6[0x12];
    /* 0x1C8 */ u16 unk_1C8;
    /* 0x1CA */ char pad1CA[6];
} unk_D_86203E50; // size = 0x1D0

void func_86200020(unk_D_86203E50* arg0);
void func_86200034(void);
void func_862002EC(void);
void func_862002F4(void);
void func_862004D8(void);
void func_86200528(void);
void func_86200620(void);
void func_86200938(void);
void func_86200940(s32 arg0);
void func_86200EC4(s32 arg0);
s32 func_862011E8(void);
void func_862013C0(void);
void func_862015A0(unk_D_86203E50* arg0);
void func_862015C8(unk_D_86203E50* arg0);
s32 func_86201640(unk_D_86203E50* arg0, unk_D_86204720* arg1);
void func_86201770(unk_D_86203E50* arg0);
void func_86201814(unk_D_86203E50* arg0, s32 arg1);
void func_86201900(unk_D_86203E50* arg0);
s16 func_86201CD8(void);
void func_862022CC(void);
void func_862023F8(void);
void func_86202C7C(void);
void func_86202D5C(void);
void func_86202EE4(void);
void func_86202F3C(void);
void func_86202FA4(s32 arg0);
void func_86203008(void);
void func_862030D0(void);
void func_86203380(void);
void func_8620369C(s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT8_H_
