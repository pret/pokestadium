#include <ultra64.h>
#include "libleo/internal.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"

s32 LeoCJCreateLeoManager(OSPri comPri, OSPri intPri, OSMesg *cmdBuf, s32 cmdMsgCnt) {
  OSPiHandle* driveRomHandle;
  OSPiHandle* leoDiskHandle;
  UNUSED volatile LEOCmdInquiry cmdBlockInq;
  UNUSED volatile LEOCmd cmdBlockID;
  LEODiskID thisID;
  u32 stat;
  u32 data;

  if (__leoActive) {
    return LEO_ERROR_GOOD;
  }

  if (!LeoDriveExist()) {
    return LEO_ERROR_DEVICE_COMMUNICATION_FAILURE;
  }

  leoDiskHandle = osLeoDiskInit();
  driveRomHandle = osDriveRomInit();
  __leoActive = 1;

  __osSetHWIntrRoutine(1, __osLeoInterrupt, leoDiskStack);
  leoInitialize(comPri, intPri, cmdBuf, cmdMsgCnt);

  if (osResetType == 1) {
    __leoSetReset();
  }

  cmdBlockInq.header.command = 2;
  cmdBlockInq.header.reserve1 = 0;
  cmdBlockInq.header.control = 0;
  cmdBlockInq.header.reserve3 = 0;
  leoCommand((void*)&cmdBlockInq);

  {
    volatile s32 dummy = (u32) &cmdBlockInq & 0xFFFFFF;

    while (dummy > 0) {
        dummy -= ((u32)__leoSetReset & 0xFFFFFF) | 0x403DF4;
    }
  }

  while (cmdBlockInq.header.status == 8);

  if (cmdBlockInq.header.status != 0) {
    return cmdBlockInq.header.sense;
  }

  __leoVersion.driver = cmdBlockInq.version;
  __leoVersion.drive = 6;
  __leoVersion.deviceType = cmdBlockInq.dev_type;
  __leoVersion.ndevices = cmdBlockInq.dev_num;

  stat = __leoVersion.driver & 0xF;
  if (stat == 4) {
    LEO_country_code = 0;
  } else if ((stat == 3) || (stat == 1)) {
    volatile u32 dummy;

    osEPiReadIo(driveRomHandle, 0x9FF00, &data);
    data = ((data & 0xFF000000) >> 0x18);
    dummy = 0x3ED98F23;
    if (data != 0xC3) {
        while (1) {}
    }

    dummy *= data;
    dummy -= (u32)&cmdBlockInq;
    LEO_country_code = -0x17B72CEA;
  } else {
    while (1) {}
  }

  return LEO_ERROR_GOOD;
}
