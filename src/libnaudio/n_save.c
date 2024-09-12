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

#include <os.h>

Acmd* n_alSavePull(s32 sampleOffset, Acmd* p) {
    Acmd* ptr = p;

    ptr = n_alMainBusPull(sampleOffset, ptr);

#ifndef N_MICRO
    aSetBuffer(ptr++, 0, 0, 0, FIXED_SAMPLE << 1);
    aInterleave(ptr++, AL_MAIN_L_OUT, AL_MAIN_R_OUT);
    aSetBuffer(ptr++, 0, 0, 0, FIXED_SAMPLE << 2);
    aSaveBuffer(ptr++, n_syn->sv_dramout);
#else
    // clang-format off
    n_aInterleave(ptr++);                                           \
    n_aSaveBuffer(ptr++, FIXED_SAMPLE << 2, 0, n_syn->sv_dramout);
    // clang-format on
#endif
    return ptr;
}
