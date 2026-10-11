#include "battle_hud.h"
#include "model_renderer_callbacks.h"
#include "geo_render.h"
#include "src/util.h"
#include "src/memmap.h"
#include "src/fragments/particle_data_library/particle_data_library.h"

// .bss
u8 D_800AF770[8];
s16 D_800AF778[4];
s16 D_800AF780[4];
s16 D_800AF788[4];
s16 D_800AF790[4];
s16 D_800AF798[4];
s16 D_800AF7A0[4];
s32 D_800AF7A8;
s16 D_800AF7AC;
s16 D_800AF7AE;
s16 D_800AF7B0[2];
s16 D_800AF7B4[2];

void BattleHud_SetDigitRotationTargets(u8 arg0, s16 arg1) {
    D_800AF778[arg0] = 0x167 - ((arg1 % 10) * 0x24);
    D_800AF780[arg0] = 0x167 - (((arg1 / 10) % 10) * 0x24);
    D_800AF788[arg0] = 0x167 - (((arg1 / 100) % 10) * 0x24);
}

void BattleHud_ApproachDigitRotations(u8 arg0, s16 arg1) {
    s16 tmp;
    s16 tmp2;

    D_800AF790[arg0] = 0x167 - ((arg1 % 10) * 0x24);
    D_800AF798[arg0] = 0x167 - (((arg1 / 10) % 10) * 0x24);
    D_800AF7A0[arg0] = 0x167 - (((arg1 / 100) % 10) * 0x24);

    tmp2 = D_800AF790[arg0];
    tmp = D_800AF778[arg0];
    if (((tmp2 < 0x5A) && (tmp >= 0x10F)) || ((tmp < 0x5A) && (tmp2 >= 0x10F))) {
        if (tmp < tmp2) {
            D_800AF778[arg0] -= 6;
        }

        if (tmp2 < tmp) {
            D_800AF778[arg0] += 6;
        }
    } else {
        if (tmp < tmp2) {
            D_800AF778[arg0] += 6;
        }

        if (tmp2 < tmp) {
            D_800AF778[arg0] -= 6;
        }
    }

    if (D_800AF778[arg0] < 0) {
        D_800AF778[arg0] += 0x168;
    }

    if (D_800AF778[arg0] >= 0x168) {
        D_800AF778[arg0] -= 0x168;
    }

    tmp2 = D_800AF798[arg0];
    tmp = D_800AF780[arg0];
    if (((tmp2 < 0x5A) && (tmp >= 0x10F)) || ((tmp < 0x5A) && (tmp2 >= 0x10F))) {
        if (tmp < tmp2) {
            D_800AF780[arg0] -= 6;
        }

        if (tmp2 < tmp) {
            D_800AF780[arg0] += 6;
        }
    } else {
        if (tmp < tmp2) {
            D_800AF780[arg0] += 6;
        }

        if (tmp2 < tmp) {
            D_800AF780[arg0] -= 6;
        }
    }

    if (D_800AF780[arg0] < 0) {
        D_800AF780[arg0] += 0x168;
    }

    if (D_800AF780[arg0] >= 0x168) {
        D_800AF780[arg0] -= 0x168;
    }

    tmp2 = D_800AF7A0[arg0];
    tmp = D_800AF788[arg0];
    if (((tmp2 < 0x5A) && (tmp >= 0x10F)) || ((tmp < 0x5A) && (tmp2 >= 0x10F))) {
        if (tmp < tmp2) {
            D_800AF788[arg0] -= 6;
        }

        if (tmp2 < tmp) {
            D_800AF788[arg0] += 6;
        }
    } else {
        if (tmp < tmp2) {
            D_800AF788[arg0] += 6;
        }

        if (tmp2 < tmp) {
            D_800AF788[arg0] -= 6;
        }
    }

    if (D_800AF788[arg0] < 0) {
        D_800AF788[arg0] += 0x168;
    }

    if (D_800AF788[arg0] >= 0x168) {
        D_800AF788[arg0] -= 0x168;
    }
}

void ModelAnim_UpdateFrameChangeState(void) {
    D_800AF7AC = (D_800AF7A8 == D_8006F084) ? 1 : 0;
    D_800AF7A8 = D_8006F084;
}

s32 func_800325AC(void) {
    return 0;
}

u8 ModelRenderer_GetActiveMode(void) {
    u8 ret = *(u8*)Memmap_GetSegmentVaddr(&D_8006F09C->effectSlot);
    return ret;
}

s16 ModelRenderer_GetObjectType(void) {
    s16 ret = *(s16*)Util_ConvertAddrToVirtAddr(&D_8006F09C->objectType);
    return ret;
}

void ModelAnim_StartDisplayObjectAnimation(DisplayObject* arg0) {
    void (*func)(void*);
    s32 unk1A = arg0->objectType;
    s32 idx = arg0->effectSlot;

    D_800AF7AE = 0;

    if (unk1A < 0x98) {
        D_800AF7C0[idx & 1] = 0;
        ModelRenderer_ClearSlotModels(idx & 1);
        func = Util_ConvertAddrToVirtAddr(Particle31_ResetAllSlots);
        func(arg0);
    }
}

void ModelAnim_UpdateDisplayObjectAnimation(u32 arg0, u32 arg1) {
    s32 (*func)(void);

    D_800AF7B0[arg0 & 1] = 0;
    func = Util_ConvertAddrToVirtAddr(Particle31_ResetCounters);
    func();

    if ((arg0 < 2) && (arg1 != 0) && (arg1 < 0x98)) {
        switch (D_800AF7C0[arg0]) {
            default:
                D_800AF7C0[arg0] = 1;
                return;
            case 0:
                D_800AF7C0[arg0] = 1;
                return;
            case 1:
                D_800AF7C0[arg0] = 2;
                return;
            case 2:
                D_800AF7C0[arg0] = 3;
                break;
            case 3:
                break;
        }
    }
}

void ModelAnim_FinalizeDisplayObjectAnimation(u32 arg0, u32 arg1) {
    if (func_800325AC() == 0) {
        D_800AF7AE++;
    }

    if ((arg1 != 0) && (arg0 < 2)) {
        if (D_800AF7B0[arg0 & 1] == 0) {
            D_800AF7B4[arg0] = 0;
        } else {
            D_800AF7B4[arg0] = 1;
        }
    }
}

void Gfx_SetCombineMode(Gfx* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, s32 arg13, s32 arg14, s32 arg15, s32 arg16) {
    gDPSetCombine(arg0++, GCCc0w0(arg1, arg3, arg5, arg7) | GCCc1w0(arg9, arg11), GCCc0w1(arg2, arg4, arg6, arg8) | GCCc1w1(arg10, arg13, arg15, arg12, arg14, arg16));
}
