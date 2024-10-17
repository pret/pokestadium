#include "geo_layout.h"
#include "src/11BA0.h"
#include "src/F420.h"
#include "src/util.h"

extern GeoLayoutCommandProc GeoLayoutJumpTable[];

extern MemoryBlock* gGraphNodePool;
extern unk_D_86002F34* gCurRootGraphNode;
extern u32 gGeoLayoutStack[];
extern GraphNode* gCurGraphNodeList[32];
extern s16 gCurGraphNodeIndex;
extern s16 gGeoLayoutStackIndex;
extern s16 gGeoLayoutReturnIndex;
extern u8* gGeoLayoutCommand;

/*
  0x00: Branch and store return address
   cmd+0x04: void *branchTarget
*/
void geo_layout_cmd_branch_and_link(void) {
    u8* cmd = (void*)gGeoLayoutCommand;

    cmd += 0;

    gGeoLayoutStack[gGeoLayoutStackIndex++] = (uintptr_t)(cmd + CMD_PROCESS_OFFSET(8));
    gGeoLayoutStack[gGeoLayoutStackIndex++] = (gCurGraphNodeIndex << 16) + gGeoLayoutReturnIndex;
    gGeoLayoutReturnIndex = gGeoLayoutStackIndex;
    gGeoLayoutCommand = Util_ConvertAddrToVirtAddr(cur_geo_cmd_ptr(0x04));
}

// 0x01: Terminate geo layout
void geo_layout_cmd_end(void) {
    gGeoLayoutStackIndex = gGeoLayoutReturnIndex;
    gGeoLayoutReturnIndex = gGeoLayoutStack[--gGeoLayoutStackIndex] & 0xFFFF;
    gCurGraphNodeIndex = gGeoLayoutStack[gGeoLayoutStackIndex] >> 16;
    gGeoLayoutCommand = (u8*)gGeoLayoutStack[--gGeoLayoutStackIndex];
}

/*
  0x02: Jump to address
    cmd+0x04: void *jumpTarget
*/
void geo_layout_cmd_jump(void) {
    u8* cmd = (void*)gGeoLayoutCommand;

    cmd += 0;

    gGeoLayoutCommand = Util_ConvertAddrToVirtAddr(cur_geo_cmd_ptr(0x04));
}

/*
  0x03: Branch
    cmd+0x04: void *branchTarget
*/
void geo_layout_cmd_branch(void) {
    u8* cmd = (void*)gGeoLayoutCommand;

    cmd += 0;

    // unlike in sm64, this argument doesnt seem to be optional.
    gGeoLayoutStack[gGeoLayoutStackIndex++] = (uintptr_t)(cmd + CMD_PROCESS_OFFSET(8));
    gGeoLayoutCommand = Util_ConvertAddrToVirtAddr(cur_geo_cmd_ptr(0x04));
}

// 0x04: Return from branch
void geo_layout_cmd_return(void) {
    gGeoLayoutCommand = (u8*)gGeoLayoutStack[--gGeoLayoutStackIndex];
}

// 0x05: Open node
void geo_layout_cmd_open_node(void) {
    gCurGraphNodeList[gCurGraphNodeIndex + 1] = gCurGraphNodeList[gCurGraphNodeIndex];
    gCurGraphNodeIndex++;
    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

// 0x06: Close node
void geo_layout_cmd_close_node(void) {
    gCurGraphNodeIndex--;
    gGeoLayoutCommand += 0x04 << CMD_SIZE_SHIFT;
}

void func_80017AC4(GraphNode* arg0) {
    if (arg0 != NULL) {
        gCurGraphNodeList[gCurGraphNodeIndex] = arg0;
        if (gCurGraphNodeIndex == 0) {
            if (gCurRootGraphNode == NULL) {
                gCurRootGraphNode = arg0;
            }
        } else {
            func_80012094(gCurGraphNodeList[gCurGraphNodeIndex - 1], arg0);
        }
    }
}

void func_80017B28(void) {
    unk_D_800ABE00_cmd7* cmd = (unk_D_800ABE00_cmd7*)gGeoLayoutCommand;

    func_80017AC4(&cmd->unk_04->unk_00);

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd7);
}

void func_80017B60(void) {
    unk_D_800ABE00_cmd8* cmd = (unk_D_800ABE00_cmd8*)gGeoLayoutCommand;

    if (gCurGraphNodeList[gCurGraphNodeIndex] != NULL) {
        func_80010FDC(gCurGraphNodeList[gCurGraphNodeIndex], cmd->unk_04, cmd->unk_08);
    }

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd8);
}

void func_80017BBC(void) {
    func_80017AC4(func_8001103C(gGraphNodePool, NULL));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd9);
}

void func_80017BFC(void) {
    unk_D_800ABE00_cmdA* cmd = (unk_D_800ABE00_cmdA*)gGeoLayoutCommand;

    func_80017AC4(func_80011088(gGraphNodePool, NULL, cmd->unk_04));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdA);
}

void func_80017C48(void) {
    unk_D_800ABE00_cmdB* cmd = (unk_D_800ABE00_cmdB*)gGeoLayoutCommand;
    unk_D_86002F34_00C* temp_v0 =
        func_800110E0(gGraphNodePool, NULL, cmd->unk_04, cmd->unk_06, cmd->unk_08, cmd->unk_0A);

    if (temp_v0 != NULL) {
        temp_v0->unk_24.fovy = cmd->unk_02;
        func_8000E990(&temp_v0->unk_60.at, &cmd->unk_0C);
        func_80010354(&temp_v0->unk_60.at, &temp_v0->unk_60.eye, cmd->unk_16, (cmd->unk_12 << 0xF) / 180,
                      (cmd->unk_14 << 0xF) / 180);
    }

    func_80017AC4(&temp_v0->unk_00);

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdB);
}

void func_80017D94(void) {
    unk_D_800ABE00_cmdC* cmd = (unk_D_800ABE00_cmdC*)gGeoLayoutCommand;

    func_80017AC4(func_800111A4(gGraphNodePool, NULL, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdC);
}

void func_80017DE0(void) {
    unk_D_800ABE00_cmdD* cmd = (unk_D_800ABE00_cmdD*)gGeoLayoutCommand;

    func_80017AC4(func_800111FC(gGraphNodePool, NULL, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdD);
}

void func_80017E2C(void) {
    unk_D_800ABE00_cmdE* cmd = (unk_D_800ABE00_cmdE*)gGeoLayoutCommand;

    func_80017AC4(func_80011258(gGraphNodePool, NULL, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdE);
}

void func_80017E78(void) {
    unk_D_800ABE00_cmdF* cmd = (unk_D_800ABE00_cmdF*)gGeoLayoutCommand;

    func_80017AC4(func_800112BC(gGraphNodePool, NULL, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdF);
}

void func_80017EC4(void) {
    unk_D_800ABE00_cmd10* cmd = (unk_D_800ABE00_cmd10*)gGeoLayoutCommand;

    func_80017AC4(func_80011320(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_02, cmd->unk_03));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd10);
}

void func_80017F1C(void) {
    func_80017AC4(func_800113AC(gGraphNodePool, NULL));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd11);
}

void func_80017F5C(void) {
}

void func_80017F64(void) {
    unk_D_800ABE00_cmd13* cmd = (unk_D_800ABE00_cmd13*)gGeoLayoutCommand;

    func_80017AC4(func_800113F8(gGraphNodePool, NULL, cmd->unk_04, cmd->unk_06, cmd->r, cmd->g, cmd->b, 0xFF));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd13);
}

void func_80017FD4(void) {
    unk_D_800ABE00_cmd14* cmd = (unk_D_800ABE00_cmd14*)gGeoLayoutCommand;

    func_80017AC4(func_80011484(gGraphNodePool, NULL, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, cmd->r,
                                cmd->g, cmd->b, cmd->a));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd14);
}

void func_800180BC(void) {
    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd15);
}

void func_800180D4(void) {
    unk_D_800ABE00_cmd16* cmd = (unk_D_800ABE00_cmd16*)gGeoLayoutCommand;

    func_80017AC4(func_80011504(gGraphNodePool, NULL, cmd->r, cmd->g, cmd->b));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd16);
}

void func_8001812C(void) {
    unk_D_800ABE00_cmd17* cmd = (unk_D_800ABE00_cmd17*)gGeoLayoutCommand;

    func_80017AC4(func_8001156C(gGraphNodePool, NULL, cmd->unk_02, cmd->unk_08, cmd->unk_04, cmd->unk_0C, cmd->unk_06,
                                cmd->unk_10));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd17);
}

void func_8001819C(void) {
    unk_D_800ABE00_cmd18* cmd = (unk_D_800ABE00_cmd18*)gGeoLayoutCommand;

    func_80017AC4(func_800115F0(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_06, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd18);
}

void func_800181FC(void) {
    unk_D_800ABE00_cmd19* cmd = (unk_D_800ABE00_cmd19*)gGeoLayoutCommand;

    func_80017AC4(func_80011660(gGraphNodePool, NULL, cmd->unk_04, cmd->unk_06));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd19);
}

void func_8001824C(void) {
    unk_D_800ABE00_cmd1A* cmd = (unk_D_800ABE00_cmd1A*)gGeoLayoutCommand;

    func_80017AC4(func_800116C0(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1A);
}

void func_8001829C(void) {
    Vec3s sp30;
    Vec3f sp24;
    UNUSED s32 pad;
    unk_D_800ABE00_cmd1B* cmd = (unk_D_800ABE00_cmd1B*)gGeoLayoutCommand;

    func_8000E990(&sp24, &cmd->unk_0A);
    func_8000EB70(&sp30, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, (cmd->unk_08 << 0xF) / 180);
    func_80017AC4(func_80011720(gGraphNodePool, NULL, &sp24, &sp30));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1B);
}

void func_800183C4(void) {
    Vec3f sp24;
    unk_D_800ABE00_cmd1C* cmd = (unk_D_800ABE00_cmd1C*)gGeoLayoutCommand;

    sp24.x = cmd->unk_04 / 65536.0f;
    sp24.y = cmd->unk_08 / 65536.0f;
    sp24.z = cmd->unk_0C / 65536.0f;
    func_80017AC4(func_800117A8(gGraphNodePool, NULL, &sp24));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1C);
}

void func_80018490(void) {
    Vec3f sp3C;
    s16 var_a3 = 1;
    unk_D_800ABE00_cmd1D* cmd = (unk_D_800ABE00_cmd1D*)gGeoLayoutCommand;

    sp3C.x = cmd->unk_10 / 65536.0f;
    sp3C.y = cmd->unk_14 / 65536.0f;
    sp3C.z = cmd->unk_18 / 65536.0f;

    if (cmd->unk_02 & 1) {
        var_a3 = 0;
    }

    if (cmd->unk_02 & 2) {
        var_a3 |= 2;
    }

    func_80017AC4(
        func_80011814(gGraphNodePool, NULL, cmd->unk_01, var_a3, cmd->unk_03, &cmd->unk_04, &cmd->unk_0A, &sp3C));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1D);
}

void func_800185A8(void) {
    unk_D_800ABE00_cmd1E* cmd = (unk_D_800ABE00_cmd1E*)gGeoLayoutCommand;

    func_80017AC4(func_800118D0(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1E);
}

void func_80018600(void) {
    Vec3s sp40;
    Vec3f sp34;
    Vec3f sp28;
    unk_D_86002F58_004_000* tmp;
    unk_D_800ABE00_cmd1F* cmd = (unk_D_800ABE00_cmd1F*)gGeoLayoutCommand;

    func_8000E990(&sp34, &cmd->unk_0A);

    sp28.x = cmd->unk_10 / 100.0f;
    sp28.y = cmd->unk_12 / 100.0f;
    sp28.z = cmd->unk_14 / 100.0f;

    func_8000EB70(&sp40, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, (cmd->unk_08 << 0xF) / 180);
    tmp = func_80011938(gGraphNodePool, NULL, cmd->unk_02, &sp34, &sp40, &sp28);
    func_80017AC4(tmp);

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1F);
}

void func_8001878C(void) {
    Vec3f sp34;
    Vec3s sp2C;
    unk_D_86002F34_alt8* tmp;
    unk_D_800ABE00_cmd20* cmd = (unk_D_800ABE00_cmd20*)gGeoLayoutCommand;

    func_8000E990(&sp34, &cmd->unk_0A);
    func_8000EB70(&sp2C, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, (cmd->unk_08 << 0xF) / 180);
    tmp = func_80011ABC(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_10, &sp34, &sp2C);
    func_80017AC4(tmp);

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd20);
}

void func_800188C8(void) {
    Vec3f sp2C;
    unk_D_86002F34_alt9* tmp;
    unk_D_800ABE00_cmd21* cmd = (unk_D_800ABE00_cmd21*)gGeoLayoutCommand;

    func_8000E990(&sp2C, &cmd->unk_02);
    tmp = func_80011B10(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_0C, &sp2C, cmd->unk_08 / 65536.0f);
    func_80017AC4(tmp);

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd21);
}

void func_80018968(void) {
    unk_D_800ABE00_cmd22* cmd = (unk_D_800ABE00_cmd22*)gGeoLayoutCommand;

    func_80017AC4(func_80011B94(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_04));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd22);
}

void func_800189B8(void) {
    unk_D_800ABE00_cmd23* cmd = (unk_D_800ABE00_cmd23*)gGeoLayoutCommand;

    func_80017AC4(func_80011BF4(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_02, cmd->unk_04, cmd->unk_08, cmd->unk_0A,
                                cmd->r, cmd->g, cmd->b, cmd->a));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd23);
}

void func_80018A40(void) {
    unk_D_800ABE00_cmd24* cmd = (unk_D_800ABE00_cmd24*)gGeoLayoutCommand;

    func_80017AC4(func_80011C98(gGraphNodePool, NULL, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd24);
}

void func_80018A8C(void) {
    unk_D_800ABE00_cmd25* cmd = (unk_D_800ABE00_cmd25*)gGeoLayoutCommand;

    if (gCurGraphNodeList[gCurGraphNodeIndex] != NULL) {
        gCurGraphNodeList[gCurGraphNodeIndex]->unk_02 |= 4;
    }

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd25);
}

void func_80018AD0(void) {
    unk_D_800ABE00_cmd26* cmd = (unk_D_800ABE00_cmd26*)gGeoLayoutCommand;

    func_80017AC4(func_80011CF0(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_06, cmd->unk_08, cmd->unk_0A,
                                cmd->unk_02, cmd->unk_03, cmd->unk_0C, cmd->r, cmd->g, cmd->b, cmd->a));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd26);
}

GraphNode* process_geo_layout(MemoryBlock* pool, void* segptr) {
    // set by register_scene_graph_node when gCurGraphNodeIndex is 0
    // and gCurRootGraphNode is NULL
    gCurRootGraphNode = NULL;

    // gGeoNumViews seems to have been removed in this version of geo_script.c
    gCurGraphNodeIndex = 0;

    gGeoLayoutStackIndex = 2;
    gGeoLayoutReturnIndex = 2; // stack index is often copied here?

    gGeoLayoutCommand = Util_ConvertAddrToVirtAddr(segptr);

    gGraphNodePool = pool;

    gCurGraphNodeList[0] = 0;

    gGeoLayoutStack[0] = 0;
    gGeoLayoutStack[1] = 0;

    while (gGeoLayoutCommand != NULL) {
        GeoLayoutJumpTable[gGeoLayoutCommand[0x00]]();
    }

    return gCurRootGraphNode;
}
