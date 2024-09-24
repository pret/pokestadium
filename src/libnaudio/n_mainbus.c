/*====================================================================
 *
 * Copyright 1993, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

#include "n_synthInternals.h"
#include "../45720.h"

// This function appears to be different than the stock n_alMainBusPull.

extern u8 D_800FC824;
extern u8 D_80077D98;
extern u8* D_800FC6D8;
extern u32 D_800FD6F0;

Acmd* n_alMainBusPull(s32 sampleOffset, Acmd* p) {
    Acmd* ptr = p;
    s32 i;

    aClearBuffer(ptr++, N_AL_MAIN_L_OUT, N_AL_DIVIDED << 1);

    ptr = (n_syn->mainBus->filter.handler)(sampleOffset, ptr);

    aMix(ptr++, 0, 0x7fff, N_AL_AUX_L_OUT, N_AL_MAIN_L_OUT);
    aMix(ptr++, 0, 0x7fff, N_AL_AUX_R_OUT, N_AL_MAIN_R_OUT);

    if (D_800FC824 != 0) {
        aClearBuffer(ptr++, 0x7C0, 0x2E0);
        n_aLoadBuffer(ptr++, 0x170, 0x7C0, osVirtualToPhysical(&D_800FC6D8[D_800FD6F0 * 2]));
        n_aLoadBuffer(ptr++, 0x170, 0x930, osVirtualToPhysical(&D_800FC6D8[D_800FD6F0 * 2]));

        D_800FD6F0 += 0xB8;
        if (D_800FD6F0 >= 0xB80) {
            D_800FD6F0 = 0;
        }
        aMix(ptr++, 0, 0x7fff, N_AL_AUX_L_OUT, N_AL_MAIN_L_OUT);
        aMix(ptr++, 0, 0x7fff, N_AL_AUX_R_OUT, N_AL_MAIN_R_OUT);
        aClearBuffer(ptr++, 0x7C0, 0x2E0);
    }

    if (D_80077D98 != 0) {
        for (i = 0; i < 2; i++) {
            aClearBuffer(ptr++, 0x7C0, 0x2E0);
            n_aLoadBuffer(ptr++, 0x170, 0x7C0, osVirtualToPhysical(D_800FCF28[i]->unk_000 + D_800FCF30[i]));
            n_aLoadBuffer(ptr++, 0x170, 0x930, osVirtualToPhysical(D_800FCF28[i]->unk_000 + D_800FCF30[i]));

            D_800FCF30[i] += 0xB8;
            if (D_800FCF30[i] >= 0x8A0) {
                D_800FCF30[i] = 0;
            }

            aMix(ptr++, 0, 0x7fff, N_AL_AUX_L_OUT, N_AL_MAIN_L_OUT);
            aMix(ptr++, 0, 0x7fff, N_AL_AUX_R_OUT, N_AL_MAIN_R_OUT);
        }
    }

    return ptr;
}
