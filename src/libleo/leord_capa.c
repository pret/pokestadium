#include <ultra64.h>
#include "libleo/internal.h"

// static?
const u16 LEORAM_START_LBA[] = {
    0x05A2, 0x07C6, 0x09EA, 0x0C0E, 0x0E32, 0x1010, 0x10DC,
};
// static?
const s32 LEORAM_BYTE[] = {
	0x024A9DC0, 0x01C226C0, 0x01450F00, 0x00D35680, 0x006CFD40, 0x001DA240, 0x00000000,
};

void leoRd_capacity(void) {
    if (LEOcur_command->header.control & LEO_CONTROL_WRT) {
        LEOcur_command->data.readwrite.lba = LEORAM_START_LBA[LEOdisk_type] - 0x18;
        LEOcur_command->data.readwrite.xfer_blks = LEO_LBA_MAX;
        LEOcur_command->data.readwrite.buff_ptr = LEORAM_BYTE[LEOdisk_type];
    } else {
        LEOcur_command->data.readwrite.lba = 0;
        LEOcur_command->data.readwrite.xfer_blks = LEO_LBA_MAX;
        LEOcur_command->data.readwrite.buff_ptr = 0x3D78F40; // Total capacity, approx. 64.45 MB
    }
    LEOcur_command->header.status = LEO_STATUS_GOOD;
}
