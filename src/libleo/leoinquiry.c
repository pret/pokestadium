#include <ultra64.h>
#include "libleo/internal.h"

void leoInquiry(void) {
    u32 asic_id;

    osEPiReadIo(LEOPiInfo, LEO_ID_REG, &asic_id);
    if (leoSend_asic_cmd_w(ASIC_READ_PROGRAM_VERSION, 0) == 0) {
        u32 asic_data;

        osEPiReadIo(LEOPiInfo, LEO_DATA, &asic_data);
        if (asic_data & LEO_STATUS_DISK_CHANGE) {
            asic_id |= LEO_STATUS_MOTOR_NOT_SPINNING;
        }
    }

    ((LEOCmdInquiry*)LEOcur_command)->dev_type = 0;
    ((LEOCmdInquiry*)LEOcur_command)->version = asic_id >> 0x10;
    ((LEOCmdInquiry*)LEOcur_command)->dev_num = 1;
    ((LEOCmdInquiry*)LEOcur_command)->leo_bios_ver = 0;
    LEOcur_command->header.status = LEO_STATUS_GOOD;
}
