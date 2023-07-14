#include <ultra64.h>
#include "libleo/internal.h"

s32 LeoSetRTC(LEOCmd* cmdBlock, LEODiskTime* RTCdata, OSMesgQueue* mq) {
  if (!__leoActive) {
    return -1;
  }
  if (leoVerifyRTC(RTCdata->yearhi, RTCdata->yearlo) != 0) {
    osSendMesg(mq, (void *)LEO_SENSE_ILLEGAL_TIMER_VALUE, 1);
    return 0;
  }
  cmdBlock->header.command = LEO_COMMAND_SET_TIMER;
  cmdBlock->header.reserve1 = 0;
  cmdBlock->header.control = 0;
  cmdBlock->header.reserve3 = 0;
  _bcopy(RTCdata, &cmdBlock->data.time, 8);
  if (mq != NULL) {
    cmdBlock->header.control |= LEO_CONTROL_POST;
    cmdBlock->header.post = mq;
  }
  leoCommand(cmdBlock);
  return 0;
}

#ifdef NON_MATCHING
/*
 * The "year" is expressed in 4 digits with the high 2 digits being yearhi and low 2 digits being yearlo. 2023 = 0x20, 0x23
 * The "hour" member uses the 24-hour clock.
 * Return 0 if year is between ranges from 1996 to 2095
 */
// https://decomp.me/scratch/NUHIy
s32 leoVerifyRTC(u8 yearhi, u8 yearlo) {
  u32 year;
  if (((yearlo & 0xF) >= 0xA) || ((yearlo & 0xF0) >= 0x91) || ((yearhi & 0xF) >= 0xA) || ((yearhi & 0xF0) >= 0x91)) {
    return  1;
  }
  year = (((yearhi - ((yearhi >> 4) * 6)) * 0x64) + yearlo) - ((yearlo >> 4) * 6);
  if ((year < 0x7CCU) || (year >= 0x830U)) {
    return 1;
  }
  return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libleo/setrtc/leoVerifyRTC.s")
#endif
