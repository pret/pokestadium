#include "jpeg_stream.h"
#include "src/jpeg_stream.h"
#include "src/flash.h"
#include "src/dma.h"
#include "src/dp_intro.h"
#include "src/util.h"
#include "lib/ultralib/include/PR/leo.h"

typedef enum {
    JPEG_MARKER_START_OF_FRAME = 0xC0,
    JPEG_MARKER_HUFFMAN_TABLE = 0xC4,
    JPEG_MARKER_RESTART0 = 0xD0,
    JPEG_MARKER_RESTART7 = 0xD7,
    JPEG_MARKER_START_OF_IMAGE = 0xD8,
    JPEG_MARKER_END_OF_IMAGE = 0xD9,
    JPEG_MARKER_START_OF_SCAN = 0xDA,
    JPEG_MARKER_QUANTIZATION_TABLE = 0xDB,
} JpegStreamMarker;

static u8 D_800A60C0[0x200];
static OSMesgQueue D_800A62C0;
static OSMesg D_800A62D8;

s32 Jpeg_ReadBigEndianU16(u8* arg0) {
    return ((arg0[0] << 8) | arg0[1]) & 0xFFFF;
}

void Jpeg_ParseStreamMarkers(unk_func_80003680_sp300* arg0, u8* arg1) {
    s32 temp_v0_2;
    s32 var_s2;
    s32 var_v0;
    u8 temp_t6;
    s32 temp_v0;

    var_s2 = 1;
    arg0->unk_01 = 0;

    while (var_s2 != 0) {
        // JPEG data consists of streams, which are identified by a marker.
        // Each marker is in the form [0xFF, 0xID] where ID identifies the type of stream.
        if (*arg1++ == 0xFF) {
            temp_v0 = *arg1++;
            switch (temp_v0) {
                case 0:
                    break;

                case JPEG_MARKER_END_OF_IMAGE:
                    var_s2 = 0;
                    break;

                case JPEG_MARKER_QUANTIZATION_TABLE:
                    arg0->quantization_table = arg1 + 2;
                    arg1 += Jpeg_ReadBigEndianU16(arg1);
                    break;

                case JPEG_MARKER_HUFFMAN_TABLE:
                    arg0->huffman_table = arg1 + 2;
                    arg1 += Jpeg_ReadBigEndianU16(arg1);
                    break;

                case JPEG_MARKER_START_OF_FRAME:
                    arg0->start_of_frame = arg1 + 2;
                    arg1 += Jpeg_ReadBigEndianU16(arg1);
                    break;

                case JPEG_MARKER_START_OF_SCAN:
                    arg1 += Jpeg_ReadBigEndianU16(arg1);
                    arg0->start_of_scan = arg1;
                    break;

                case JPEG_MARKER_START_OF_IMAGE:
                    break;

                default:
                    if ((temp_v0 >= JPEG_MARKER_RESTART0) && (temp_v0 <= JPEG_MARKER_RESTART7)) {
                        arg0->unk_01 = 1;
                    } else {
                        arg1 += Jpeg_ReadBigEndianU16(arg1);
                    }
                    break;
            }
        }
    }

    // Checking the second component's ID,
    // this seems weird as it will break entirely if number of components is less than 3.
    // Looking at every JPEG used in the Stadium rom, no JPEGs use this ID, they're all 0x22.
    if (arg0->start_of_frame[7] == 0x21) {
        arg0->unk_00 = 0;
    } else {
        arg0->unk_00 = 2;
    }

    arg0->width = (arg0->start_of_frame[3] << 8) | arg0->start_of_frame[4];
    arg0->height = (arg0->start_of_frame[1] << 8) | arg0->start_of_frame[2];
}

extern u64 njpgdspMainTextStart[];
extern u64 njpgdspMainDataStart[];

void Jpeg_InitializeDspTask(UnkStruct80001380* arg0, unk_func_80003680_sp90* arg1) {
    arg0->task.t.type = 4;
    arg0->task.t.flags = 0;
    arg0->task.t.ucode_boot = rspbootTextStart;
    arg0->task.t.ucode_boot_size = (u32)_binary_assets_us_F3DEX2_bin_start - (u32)rspbootTextStart;
    arg0->task.t.ucode = njpgdspMainTextStart;
    arg0->task.t.ucode_size = 0x1000;
    arg0->task.t.ucode_data = njpgdspMainDataStart;
    arg0->task.t.ucode_data_size = 0x800;
    arg0->task.t.dram_stack = NULL;
    arg0->task.t.dram_stack_size = 0;
    arg0->task.t.output_buff = NULL;
    arg0->task.t.output_buff_size = NULL;
    arg0->task.t.data_ptr = arg1;
    arg0->task.t.data_size = 0x20;
    arg0->task.t.yield_data_ptr = D_800A60C0;
    arg0->task.t.yield_data_size = 0x200;

    osCreateMesgQueue(&arg0->queue, &arg0->mesg, 1);
}

void Jpeg_BuildDspInput(JpegDecoder* decoder, JpegHuffmanTable* hTable, unk_func_80003680_sp300* arg2) {
    decoder->imageData = arg2->start_of_scan;
    decoder->mode = arg2->unk_00;
    decoder->unk_05 = 2;
    decoder->hTablePtrs[0] = &hTable[0];
    decoder->hTablePtrs[1] = &hTable[2];
    decoder->hTablePtrs[2] = &hTable[1];
    decoder->hTablePtrs[3] = &hTable[3];
    decoder->unk_18 = arg2->unk_01;
}

void Jpeg_BuildDspOutput(unk_func_80003680_sp90* arg0, u8(arg1)[2][0x80], unk_func_80003680_sp300* arg2) {
    arg0->unk_00 = 0;
    arg0->unk_08 = arg2->unk_00;
    arg0->unk_04 = 1;
    arg0->unk_0C = (u32)&arg1[0] & 0x1FFFFFFF;
    arg0->unk_10 = (u32)&arg1[1] & 0x1FFFFFFF;
    arg0->unk_14 = (u32)&arg1[1] & 0x1FFFFFFF;
}

s32 Jpeg_DecodeImage(u32 addr, s32 arg1, u8* arg2) {
    UnkStruct80001380 sp318;
    unk_func_80003680_sp300 sp300;
    u8 sp200[2][0x80];
    JpegHuffmanTable spB0[4];
    u16* temp_s0;
    u8* temp_s3;
    unk_func_80003680_sp90 sp90;
    JpegDecoder sp74;
    JpegDecoderState sp60;
    u32 var_s1;
    s32 i;
    s32 j;
    s32 var_s4 = 0;
    s32 var_s2 = 0;

    temp_s3 = Util_Malloc(0x110);
    temp_s0 = Util_Malloc(0x210);

    Jpeg_ParseStreamMarkers(&sp300, arg2);
    JpegUtils_ProcessQuantizationTable(sp300.quantization_table, sp200, 2);
    JpegUtils_ProcessHuffmanTable(sp300.huffman_table, spB0, temp_s3, temp_s0, 4);

    Util_Free(temp_s0);
    Util_Free(temp_s3);

    Jpeg_BuildDspInput(&sp74, &spB0, &sp300);
    Jpeg_BuildDspOutput(&sp90, &sp200, &sp300);
    Jpeg_InitializeDspTask(&sp318, &sp90);

    while (Display_IsFrameReady() == 0) {}

    for (i = 0; i < sp300.height; i += 16) {
        for (j = 0; j < sp300.width; j += 16) {
            if (arg1 < (var_s2 + 0x300)) {
                return 0;
            }

            if (Jpeg_DecodeMcus(&sp74, addr, 1, var_s4, &sp60) != 0) {
                return 0;
            }

            sp90.unk_00 = addr & 0x1FFFFFFF;
            Sched_SubmitTask(&sp318, 1);
            var_s4 = 1;
            Sched_WaitForTaskMessage(&sp318);

            addr += 0x200;
            var_s2 += 0x200;
        }
    }

    return var_s2;
}

void Dma_InitializeCompletionQueue(void) {
    osCreateMesgQueue(&D_800A62C0, &D_800A62D8, 1);
}

void Yay0_DecompressAndRelocate(u8* in_header, u8* memory) {
    UNUSED s32 pad2;
    PERSSZP* header = in_header;
    u32* sp2C = (u32*)header + 6;
    UNUSED s32 pad;
    s32 sp24 = header->decompressed_size2 - header->decompressed_size1;
    u32 var_v0;

    osInvalICache(memory, header->decompressed_size2);
    osInvalDCache(memory, header->decompressed_size2);

    Yay0_Decompress(in_header + header->header_size, memory);

    for (var_v0 = 0; var_v0 < header->unk_14; var_v0++) {
        *(u32*)(memory + sp2C[1]) = sp2C[0];
        sp2C += 2;
    }

    if (sp24 != 0) {
        bzero(memory + header->decompressed_size1, sp24);
    }

    osWritebackDCache(memory, header->decompressed_size2);
}

void Dma_ReadChunks(u8* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_s0;
    OSMesgQueue* mesq = &D_800A62C0;

    for (; arg2 > 0; arg2 -= var_s0) {
        if (arg2 >= 0x1000) {
            var_s0 = 0x1000;
        } else {
            var_s0 = arg2;
        }

        Storage_QueueSramTransfer(arg3, arg0, arg1, var_s0, mesq, 0);
        osRecvMesg(mesq, NULL, 1);

        arg0 += var_s0;
        arg1 += var_s0;
    }
}

s32 Flash_ProgramPages(u8* arg0, s16 arg1, s16 arg2, s32 arg3) {
    OSMesg sp44;
    OSMesgQueue* mesq = &D_800A62C0;

    for (; arg2 > 0;) {
        Storage_QueueFlashTransfer(arg3, arg0, arg1, mesq, 0);
        osRecvMesg(mesq, &sp44, 1);

        if ((arg3 == 1) && (Flash_ProgramPage(arg1) != 0)) {
            return -1;
        }

        arg0 += 0x80;
        arg1++;
        arg2--;
    }

    return 0;
}

s32 Flash_EraseSectorByIndex(s16 arg0) {
    return Flash_EraseSector(arg0 << 7);
}

void Dma_WriteChunks(u32 write_start, u32 buffer_start, u32 buffer_end, s32 arg3) {
    s32 chunk_size;
    s32 buffer;
    OSMesgQueue* mesq = &D_800A62C0;

    for (buffer = buffer_end - buffer_start; buffer > 0; buffer -= chunk_size) {
        if (buffer >= 0x1000) {
            chunk_size = 0x1000;
        } else {
            chunk_size = buffer;
        }

        Storage_QueueRomRead(arg3, write_start, buffer_start, chunk_size, mesq, 0);
        osRecvMesg(mesq, NULL, 1);

        write_start += chunk_size;
        buffer_start += chunk_size;
    }
}

void Dma_CopyChunks(u8* arg0, u8* arg1, u8* arg2) {
    s32 var_s0;
    s32 var_s1;
    OSMesgQueue* mesq = &D_800A62C0;

    for (var_s1 = arg2 - arg1; var_s1 > 0; var_s1 -= var_s0) {
        if (var_s1 >= 0x1000) {
            var_s0 = 0x1000;
        } else {
            var_s0 = var_s1;
        }

        Storage_QueueRomWrite(arg0, arg1, var_s0, mesq, 0);
        osRecvMesg(mesq, NULL, 1);

        arg0 += var_s0;
        arg1 += var_s0;
    }
}

void* Jpeg_LoadDecodedImage(u8* addr, PRESJPEG* arg1, s32 side) {
    s32 new_addr = main_pool_alloc(arg1->unk_0C + 0x100, side);

    if (new_addr != NULL) {
        s32 size = Jpeg_DecodeImage(new_addr, arg1->unk_0C + 0x100, (u32)arg1 + arg1->unk_08);

        if (size == 0) {
            main_pool_try_free(new_addr);
            new_addr = NULL;
        } else if (side == 0) {
            main_pool_realloc(new_addr, size);
        }
    }

    main_pool_try_free(addr);

    return new_addr;
}

s32 Yay0_LoadDecompressedAsset(s32 arg0, PERSSZP* arg1, s32 side) {
    s32 vaddr = main_pool_alloc(arg1->decompressed_size2, side);

    if (vaddr != NULL) {
        Yay0_DecompressAndRelocate(arg1, vaddr);
    }

    main_pool_try_free(arg0);

    return vaddr;
}

u32* Asset_CopyUncompressed(u8* arg0, s32 arg1, u32 arg2, s32 arg3) {
    u32* sp1C = main_pool_alloc(arg2, arg3);

    if (sp1C != NULL) {
        Util_Memcpy(sp1C, arg0 + arg1, arg2 >> 2);
    }

    main_pool_try_free(arg0);

    return sp1C;
}

void* Asset_LoadCompressed(u8* romStart, u8* romEnd, s32 arg2, s32 arg3) {
    u32* addr;
    u32* newaddr;
    u32* ret;
    UNUSED s32 pad;
    int side;

    side = (arg2 == 0) ? MEMORY_POOL_RIGHT : MEMORY_POOL_LEFT;
    addr = main_pool_alloc(0x18, side);

    if (addr != NULL) {
        Dma_WriteChunks(addr, romStart, romStart + 0x18, arg3);
        if ((addr[0] == 'PERS') && (addr[1] == '-SZP')) {
            newaddr = main_pool_alloc(ALIGN16(romEnd - romStart), side);
            if (newaddr != NULL) {
                Dma_WriteChunks(newaddr, romStart, romEnd, arg3);
                ret = Yay0_LoadDecompressedAsset(newaddr, newaddr, arg2);
            }
        } else if ((addr[0] == 'PRES') && (addr[1] == 'JPEG')) {
            newaddr = main_pool_alloc(ALIGN16(romEnd - romStart), side);
            if (newaddr != NULL) {
                Dma_WriteChunks(newaddr, romStart, romEnd, arg3);
                ret = Jpeg_LoadDecodedImage(newaddr, newaddr, arg2);
            }
        } else {
            newaddr = main_pool_alloc(ALIGN16(romEnd - romStart), arg2);
            ret = newaddr;
            if (newaddr != NULL) {
                Dma_WriteChunks(ret, romStart, romEnd, arg3);
            }
        }
        main_pool_try_free(addr);
    }

    return ret;
}

void* Storage_LoadAssetByLbaRange(unk_func_800041C0* arg0, s32 arg1) {
    s32 sp44;
    u32* sp40;
    PERSSZP* temp_s0;
    s32 var_s0;
    u8* temp_v0;

    if (arg1 == 0) {
        var_s0 = 1;
    } else {
        var_s0 = 0;
    }

    LeoLBAToByte(arg0->unk_00, arg0->unk_02, &sp44);
    sp44 = ALIGN16(sp44);

    temp_v0 = main_pool_alloc(sp44, var_s0);

    if (temp_v0 != NULL) {
        temp_s0 = arg0->unk_04 + temp_v0;

        Storage_QueueDiskTransfer(0, temp_v0, arg0->unk_00, arg0->unk_02, &D_800A62C0, 0);
        osRecvMesg(&D_800A62C0, NULL, 1);

        if (((u32*)temp_s0->magic)[0] == 'PERS' && (((u32*)temp_s0->magic)[1] == '-SZP')) {
            sp40 = Yay0_LoadDecompressedAsset(temp_v0, temp_s0, arg1);
        } else if (((u32*)temp_s0->magic)[0] == 'PRES' && (((u32*)temp_s0->magic)[1] == 'JPEG')) {
            sp40 = Jpeg_LoadDecodedImage(temp_v0, temp_s0, arg1);
        } else {
            sp40 = Asset_CopyUncompressed(temp_v0, arg0->unk_04, arg0->unk_08, arg1);
        }
    }

    return sp40;
}

unk_func_800041C0* Storage_SetLbaRange(unk_func_800041C0* arg0, s32 arg1, s32 arg2) {
    arg0->unk_00 = arg1;
    arg0->unk_02 = arg2 - arg1;
    arg0->unk_04 = 0;

    LeoLBAToByte(arg0->unk_00, arg0->unk_02, &arg0->unk_08);

    return arg0;
}

unk_func_800041C0* Storage_SetByteRange(unk_func_800041C0* arg0, u32 arg1, u32 offset, u32 size) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    LeoByteToLBA(arg1, offset + 1, &sp28);
    sp28 -= 1;
    LeoByteToLBA(arg1, offset + size, &sp24);
    sp24 -= 1;

    if (sp28 > 0) {
        LeoLBAToByte(arg1, sp28, &sp2C);
    } else {
        sp2C = 0;
    }

    arg0->unk_00 = sp28 + arg1;
    arg0->unk_02 = (sp24 - sp28) + 1;
    arg0->unk_04 = offset - sp2C;
    arg0->unk_08 = size;

    return arg0;
}

void Storage_PrefetchLbaRange(s32 arg0, s32 arg1, s32 arg2) {
    unk_func_800041C0 sp1C;

    Storage_SetLbaRange(&sp1C, arg0, arg1);
    Storage_LoadAssetByLbaRange(&sp1C, arg2);
}

void Memmap_ClearSegmentOnBlockFree(u32 block_addr, u32 addr) {
    u32 base = addr & 0xFF000000;
    u32 sp1C = addr & 0xFFFFFF;

    if ((base == 0x82000000) && (Memmap_GetSegmentBaseVaddr(sp1C) == block_addr)) {
        Memmap_ClearSegmentMemmap(sp1C);
    }
}

u8* Asset_LoadToSegment(s32 id, u8* rom_start, u8* rom_end, s32 arg3) {
    u8* vaddr = Asset_LoadCompressed(rom_start, rom_end, arg3, 0);

    if ((vaddr != NULL) && (id > 0)) {
        Memmap_SetSegmentMap(id, vaddr, main_pool_get_block_dist(vaddr));
        main_pool_set_func(vaddr, id + 0x82000000, &Memmap_ClearSegmentOnBlockFree);
    }
    return vaddr;
}

MainPoolBlock* Asset_LoadToSegmentByLbaRange(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad;
    unk_func_800041C0 sp28;
    MainPoolBlock* temp_v0 = Storage_LoadAssetByLbaRange(Storage_SetLbaRange(&sp28, arg1, arg2), arg3);

    if ((temp_v0 != NULL) && (arg0 > 0)) {
        Memmap_SetSegmentMap(arg0, temp_v0, main_pool_get_block_dist(temp_v0));
        main_pool_set_func(temp_v0, arg0 + 0x82000000, Memmap_ClearSegmentOnBlockFree);
    }

    return temp_v0;
}

void Fragment_FreeCallback(u32 base_addr, u32 addr) {
    u32 sp1C;
    u32 temp_a0;

    if ((addr & 0xFF000000) == 0x81000000) {
        sp1C = addr & 0xFFFFFF;
        if (Memmap_GetFragmentBaseVaddr(sp1C) == base_addr) {
            Memmap_ClearFragmentMemmap(sp1C);
        }
    }
}

void Fragment_Register(s32 arg0, Fragment* addr) {
    UNUSED s32 pad;
    u32 sp20 = main_pool_get_block_dist(addr);

    main_pool_set_func(addr, arg0 + 0x81000000, &Fragment_FreeCallback);

    if (sp20 < addr->sizeInRam) {
        main_pool_realloc(addr, addr->sizeInRam);
        Memmap_RelocateFragment(arg0, addr);
    } else {
        Memmap_RelocateFragment(arg0, addr);
        main_pool_realloc(addr, addr->sizeInRam);
    }
}

ret_func_80004454 Fragment_Load(s32 arg0, u8* romStart, u8* romEnd) {
    void* addr = Asset_LoadCompressed(romStart, romEnd, 0, 0);

    if (addr != NULL) {
        Fragment_Register(arg0, (Fragment*)addr);
    }
    return addr;
}

void* Fragment_LoadByLbaRange(s32 arg0, s32 arg1, s32 arg2) {
    Fragment* sp2C;
    unk_func_800041C0 sp20;

    sp2C = Storage_LoadAssetByLbaRange(Storage_SetLbaRange(&sp20, arg1, arg2), 0);
    if (sp2C != NULL) {
        Fragment_Register(arg0, sp2C);
    }
    return sp2C;
}

BinArchive* BinArchive_Open(u8* romStart, u8* romEnd, s32 arg2, s32 arg3) {
    BinArchive* ret = NULL;
    u32 sp28;
    u32 sp28_2;
    u16* newaddr;

    switch (arg2) {
        case 0:
            newaddr = Asset_LoadCompressed(romStart, romEnd, 0, 0);
            ret = newaddr;
            if (newaddr != NULL) {
                newaddr[0] |= 1;
            }
            break;

        case 1:
            newaddr = Asset_LoadCompressed(romStart, romStart + 0x20, 0, 0);
            ret = newaddr;
            if (newaddr != NULL) {
                sp28 = (ret->num_files * 0x10) + 0x10;
                main_pool_try_free(ret);
                newaddr = Asset_LoadCompressed(romStart, romStart + sp28, 0, 0);
                ret = newaddr;
                if (newaddr != NULL) {
                    *newaddr |= 2;
                    if (arg3 == 1) {
                        *newaddr |= 4;
                    }
                }
            }
            break;

        case 2:
            newaddr = Asset_LoadCompressed(romStart, romStart + 0x20, 1, 0);
            ret = newaddr;
            if (newaddr != NULL) {
                sp28_2 = (ret->num_files * 0x10) + 0x10;
                main_pool_try_free(ret);
                newaddr = Asset_LoadCompressed(romStart, romStart + sp28_2, 1, 0);
                ret = newaddr;
                if ((newaddr != NULL) && (arg3 == 1)) {
                    *newaddr |= 4;
                }
            }
            break;
    }

    if (ret != NULL) {
        ret->unk_04 = romStart;
    }

    return ret;
}

void* BinArchive_LoadByLbaRange(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    BinArchive* var_a0;
    unk_func_800041C0 sp20;

    switch (arg2) {
        default:
            break;

        case 0:
            Storage_SetLbaRange(&sp20, arg0, arg1);
            var_a0 = Storage_LoadAssetByLbaRange(&sp20, 0);
            if (var_a0 != NULL) {
                main_pool_realloc(var_a0, var_a0->total_size);
                var_a0->unk_00 |= 1;
            }
            break;

        case 1:
            Storage_SetLbaRange(&sp20, arg0, arg0 + 1);
            var_a0 = Storage_LoadAssetByLbaRange(&sp20, 0);
            if (var_a0 != NULL) {
                main_pool_realloc(var_a0, (var_a0->num_files * sizeof(BinArchiveFile)) + sizeof(BinArchive));
                var_a0->unk_00 |= 2;
                if (arg3 == 1) {
                    var_a0->unk_00 |= 4;
                }
            }
            break;

        case 2:
            Storage_SetLbaRange(&sp20, arg0, arg0 + 1);
            var_a0 = Storage_LoadAssetByLbaRange(&sp20, 1);
            if (arg3 == 1) {
                var_a0->unk_00 |= 4;
            }
            break;
    }

    if (var_a0 != NULL) {
        var_a0->unk_00 |= 0x80;
        var_a0->unk_04 = arg0;
    }

    return var_a0;
}

void BinArchive_Free(void* arg0) {
    main_pool_try_free(arg0);
}

Fragment* BinArchive_LoadFileFromRom(BinArchive* arg0, BinArchiveFile* arg1) {
    u8* temp_a0 = arg0->unk_04 + arg1->offset;

    return Asset_LoadCompressed(temp_a0, arg1->size + temp_a0, 0, 0);
}

void* BinArchive_LoadFileBuffered(BinArchive* arg0, BinArchiveFile* arg1) {
    unk_func_800041C0 sp1C;

    Storage_SetByteRange(&sp1C, arg0->unk_04, arg1->offset, arg1->size);
    return Storage_LoadAssetByLbaRange(&sp1C, 0);
}

void* BinArchive_GetFile(BinArchive* archive, s32 file_number) {
    Fragment* var_a2 = NULL;
    UNUSED s32 pad;
    BinArchiveFile* sp18 = (u8*)archive + sizeof(BinArchive) + (file_number * sizeof(BinArchiveFile));

    if (file_number < archive->num_files) {
        if (archive->unk_00 & 1) {
            var_a2 = (u8*)archive + sp18->offset;
        } else if (!(archive->unk_00 & 4) && (sp18->unk_08 != NULL)) {
            var_a2 = sp18->unk_08;
        } else {
            if (archive->unk_00 & 0x80) {
                var_a2 = BinArchive_LoadFileBuffered(archive, sp18);
            } else {
                var_a2 = BinArchive_LoadFileFromRom(archive, sp18);
            }

            if (var_a2 != NULL) {
                if ((((u32*)var_a2->magic)[0] == 'FRAG') && (((u32*)var_a2->magic)[1] == 'MENT')) {
                    Fragment_Register(archive->unk_02, var_a2);
                }

                sp18->unk_08 = var_a2;
            }
        }
    }

    return var_a2;
}

s32 BinArchive_GetCachedFile(BinArchive* archive, s32 file_number) {
    BinArchiveFile* sp18 = (u8*)archive + sizeof(BinArchive) + (file_number * sizeof(BinArchiveFile));
    s32 var_v1 = 0;

    if (file_number < archive->num_files) {
        var_v1 = sp18->unk_08;
    }
    return var_v1;
}
