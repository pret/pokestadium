#include "n64_logo.h"
#include "src/save_data.h"
#include "src/gb_data.h"
#include "src/ui_graphics.h"
#include "src/text_system.h"
#include "src/3D140.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/audio_channel.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/memory.h"
#include "src/stage_loader.h"

void N64Logo_DrawLogoTexture(void) {
    s32 var_t4;
    u8* var_t5;
    u32 tmp = 0xF;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gDPPipeSync(gDisplayListHead++);

    var_t5 = D_2000000;
    for (var_t4 = 0x40; var_t4 < 0xB0; var_t4 += 0x10, var_t5 += 0x1000) {
        gDPLoadTextureBlock(gDisplayListHead++, var_t5, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 7, 4, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, 0x0180, var_t4 << 2, 0x037C, (var_t4 + tmp) << 2, G_TX_RENDERTILE, 0, 0,
                            0x1000, 0x0400);
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);
}

s32 N64Logo_DrawFrame(UNUSED u8 arg0) {
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 1);
    N64Logo_DrawLogoTexture();

    return 0;
}

void N64Logo_WaitForElapsed(u64 arg0) {
    u32 temp_ret = 0xF;

    while (temp_ret < 0xF4240) {
        temp_ret = __ull_div(__ll_mul(osGetTime() - arg0, 0x40), 0xBB8);
    }
}

void N64Logo_ScanGbSavePorts(void) {
    main_pool_push_state('GPAK');

    GbSave_ScanAllPorts();

    main_pool_pop_state('GPAK');
}

s32 N64Logo_Main(UNUSED s32 arg0, UNUSED s32 arg1) {
    u64 sp30;
    unk_func_80007444* sp2C;
    u16 sp2A;

    main_pool_push_state('LOGO');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp2C = StageContext_Allocate(0, 1, 2, 0, 2, 1);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, n64_logo_texture, 0);

    Save_EnsureBankLoaded(2);
    StageContext_Activate(sp2C);
    StageFade_Start(1);
    BgStage_RunUntilCondition(3, N64Logo_DrawFrame);
    Text_InitStringTables();
    Text_LoadPlayerLabels();
    Text_LoadNameTable();
    Save_GetOptionsField02(&sp2A);

    if (sp2A & 1) {
        Audio_SetMonoOutput(1);
    } else {
        Audio_SetMonoOutput(0);
    }

    if (sp2A & 2) {
        Audio_SetVoiceEnabled(0);
    } else {
        Audio_SetVoiceEnabled(1);
    }

    Audio_PlaySoundEffectById(SFX_N64_LOGO);
    sp30 = osGetTime();
    N64Logo_ScanGbSavePorts();
    N64Logo_WaitForElapsed(sp30);
    StageFade_Start(0x10);
    BgStage_RunUntilCondition(0x10, N64Logo_DrawFrame);
    StageContext_Deactivate();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('LOGO');
    return 2;
}
