#include <ultra64.h>
#include "libleo/internal.h"

extern s32 currentCommand;
extern u32 asic_cur_status; // static?
extern u32 unit_atten; // static?

s32 osEPiWriteIo(OSPiHandle *, u32 , u32 );

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunknown-pragmas"

u8 leoAnalize_asic_status(void) {
  u32 curr_stat;

  osEPiReadIo(LEOPiInfo, LEO_STATUS, &asic_cur_status);

  if ((curr_stat = asic_cur_status ^ 0x1000000) & 0x1C3FFFF) {
    if (curr_stat & 0x1C1FFFF) {
      LEOdrive_flag = 0;
    }
    if (curr_stat & LEO_STATUS_PRESENCE_MASK) {
      return 41;
    }
    if ((curr_stat & 0xC00000) == LEO_STATUS_BUSY_STATE) {
      return LEO_SENSE_COMMAND_PHASE_ERROR;
    }
    if (curr_stat & LEO_STATUS_RESET_STATE) {
      unit_atten |= 2;
      return LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED;
    }
    if (curr_stat & LEO_STATUS_DISK_PRESENT) {
      return LEO_SENSE_EJECTED_ILLEGALLY_RESUME;
    }
    if (curr_stat & LEO_STATUS_DISK_CHANGE) {
      unit_atten |= 1;
      return LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED;
    }
    if (curr_stat & LEO_STATUS_MECHANIC_ERROR) {
      return LEO_SENSE_NO_SEEK_COMPLETE;
    }
  }
  return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
}

u8 leoChk_asic_ready(u32 asic_cmd) {
  u32 sense_code = leoAnalize_asic_status();

  switch (sense_code) {
    case LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED:
      if (asic_cmd == ASIC_CLR_CHGFLG) {
        return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
      }
    case LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED:
      if (!(asic_cur_status & LEO_STATUS_BUSY_STATE)) {
        if (asic_cmd == ASIC_CLR_RSTFLG) {
            return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
        }
        if (leoRecv_event_mesg(0) != 0) {
            return LEO_SENSE_WAITING_NMI;
        }
        osEPiWriteIo(LEOPiInfo, LEO_CMD, ASIC_CLR_RSTFLG);
        if (leoRecv_event_mesg(1) != 0) {
            return LEO_SENSE_WAITING_NMI;
        }
      }
    default:
      break;
    case LEO_SENSE_EJECTED_ILLEGALLY_RESUME:
      if (asic_cmd & ASIC_NEED_DISK_IN) {
        break;
      }
    case LEO_SENSE_NO_SEEK_COMPLETE:
      return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
  }
  return sense_code;
}

u8 leoChk_done_status(u32 asic_cmd) {
  u32 asic_data;
  u32 code = leoAnalize_asic_status();

  switch (code) {
    case 43:
    case 47:
      if (!(asic_cur_status & 0x800000)) {
        if (leoRecv_event_mesg(0) != 0) {
          return 37;
        }

        osEPiWriteIo(LEOPiInfo, 0x5000508, 0x90000);
        if (leoRecv_event_mesg(1) != 0) {
          return 37;
        }
      }
      break;

    case 49:
      if (asic_cmd & 1) {
        break;
      }
      return 0;

    case 21:
      osEPiWriteIo(LEOPiInfo, 0x5000500, 0);
      if (leoRecv_event_mesg(0) != 0) {
        return 37;
      }

      osEPiWriteIo(LEOPiInfo, 0x5000508, 0xC0000);
      if (leoRecv_event_mesg(1) != 0) {
        return 37;
      }

      osEPiReadIo(LEOPiInfo, 0x5000500, &asic_data);
      code = leoChk_asic_ready(0xC0000);
      if (code != 0) {
        return code;
      }

      if (asic_data & 0x10000) {
        return 2;
      }
      if (asic_data & 0x20000) {
        return 24;
      }
      if (asic_data & 0x40000) {
        return 1;
      }
      if (asic_data & 0x80000) {
        return 21;
      }
      if (asic_data & 0x200000) {
        return 11;
      }
      return 41;

    default:
        break;
  }
  return code;
}

u8 leoSend_asic_cmd_i(u32 asic_cmd, u32 asic_data) {
  u8 status = leoChk_asic_ready(asic_cmd);

  if (status != 0) {
    return LEOcur_command->header.sense = status;
  }
  osEPiWriteIo(LEOPiInfo, LEO_DATA, asic_data);
  if (leoRecv_event_mesg(0) != 0) {
    return LEOcur_command->header.sense = LEO_SENSE_WAITING_NMI;
  }
  osEPiWriteIo(LEOPiInfo, LEO_STATUS, asic_cmd);
  return 0;
}

u8 leoWait_mecha_cmd_done(u32 asic_cmd) {
  u32 done_stat;

  if (leoRecv_event_mesg(1)) {
    return LEO_SENSE_WAITING_NMI;
  }
  done_stat = leoChk_done_status(asic_cmd);
  if (done_stat != 0) {
    return done_stat;
  }
  return 0;
}

u8 leoSend_asic_cmd_w(u32 asic_cmd, u32 asic_data) {
  u32 wstatus = leoSend_asic_cmd_i(asic_cmd, asic_data);

  if (wstatus != 0) {
    return wstatus;
  }
  return leoWait_mecha_cmd_done(asic_cmd);
}

u8 leoSend_asic_cmd_w_nochkDiskChange(u32 asic_cmd, u32 asic_data) {
  u8 status;
  u32 done_stat;

  status = leoChk_asic_ready(asic_cmd);
  if ((status != LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED) && (status != 0)) {
    return LEOcur_command->header.sense = status;
  }

  osEPiWriteIo(LEOPiInfo, LEO_DATA, asic_data);
  if (leoRecv_event_mesg(0) != 0) {
    return LEOcur_command->header.sense = LEO_SENSE_WAITING_NMI;
  }

  osEPiWriteIo(LEOPiInfo, LEO_STATUS, asic_cmd);
  if (leoRecv_event_mesg(1) != 0) {
    return LEO_SENSE_WAITING_NMI;
  }

  done_stat = leoChk_done_status(asic_cmd);
  if ((done_stat != LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED) && (done_stat != 0)) {
    return done_stat;
  }
  return 0;
}

u8 leoDetect_index_w(void) {
  return leoSend_asic_cmd_w(ASIC_INDEX_LOCK_RETRY, 0);
}

u8 leoRecal_i(void) {
  return leoSend_asic_cmd_i(ASIC_RECAL, 0);
}

u8 leoRecal_w(void) {
  return leoSend_asic_cmd_w(ASIC_RECAL, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leomecha/leoSeek_i.s")

u8 leoSeek_w(void) {
  u8 sksense = leoSeek_i(0);

  if (sksense != 0) {
    return sksense;
  }

  return leoWait_mecha_cmd_done(ASIC_RD_SEEK);
}

s32 leoRecv_event_mesg(s32 control) {
  u32 done_mesg;

  if (osRecvMesg(&LEOevent_que, (OSMesg*)&done_mesg, control) == 0) {
    if (done_mesg == 0xA0000) {
      leoDrive_reset();
      return 0xFF;
    }
  }
  return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leomecha/leoChk_err_retry.s")

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leomecha/leoChk_cur_drvmode.s")

void leoDrive_reset() {
  osEPiWriteIo(LEOPiInfo, LEO_HARD_RESET, 0xAAAA0000);
}

u32 leoChkUnit_atten(void) {
  return unit_atten;
}

u32 leoRetUnit_atten(void) {
  if (unit_atten & 2) {
      return 43;
  }
  if (unit_atten & 1) {
      return 47;
  }
  return 0;
}

void leoClrUA_RESET(void) {
  unit_atten &= ~2;
}

void leoClrUA_MEDIUM_CHANGED(void) {
  unit_atten &= ~1;
}

void leoSetUA_MEDIUM_CHANGED(void) {
  unit_atten |= 1;
}

void leoInitUnit_atten(void) {
  unit_atten = 1;
}
