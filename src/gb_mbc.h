#ifndef _SRC_GB_MBC_H_
#define _SRC_GB_MBC_H_

#include "global.h"

s32 osGbmbcRamEnable(OSPfs*);
s32 osGbmbcSelectRamBank(OSPfs*, u8);
s32 osGbmbcReadWrite(OSPfs*, u16, u32, u8*, u32);

#endif /* _SRC_GB_MBC_H_ */
