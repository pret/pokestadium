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

Acmd *n_alAuxBusPull(s32 sampleOffset, Acmd *p) 
{
  Acmd        *ptr = p;
  N_ALAuxBus   *m = (N_ALAuxBus *)n_syn->auxBus;
  N_PVoice    **sources = m->sources;
  s32         i;

#ifndef N_MICRO
  aClearBuffer(ptr++, AL_AUX_L_OUT, FIXED_SAMPLE<<1);
  aClearBuffer(ptr++, AL_AUX_R_OUT, FIXED_SAMPLE<<1);
#else
  aClearBuffer(ptr++, N_AL_AUX_L_OUT, N_AL_DIVIDED<<1);
#endif

  for (i = 0; i < m->sourceCount; i++)
    ptr = n_alEnvmixerPull(sources[i],sampleOffset,ptr);
  return ptr;
}

