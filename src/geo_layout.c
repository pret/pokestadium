#include "geo_layout.h"
#include "src/geo_node.h"
#include "src/matrix.h"
#include "src/util.h"

static GeoLayoutCommandProc GeoLayoutJumpTable[] = {
    geo_layout_cmd_branch_and_link,
    geo_layout_cmd_end,
    geo_layout_cmd_jump,
    geo_layout_cmd_branch,
    geo_layout_cmd_return,
    geo_layout_cmd_open_node,
    geo_layout_cmd_close_node,
    geo_layout_cmd_attach_node,
    geo_layout_cmd_set_callback,
    geo_layout_cmd_create_container,
    geo_layout_cmd_create_reference,
    geo_layout_cmd_create_camera,
    geo_layout_cmd_create_type3,
    geo_layout_cmd_create_type4,
    geo_layout_cmd_create_ortho,
    geo_layout_cmd_create_perspective,
    geo_layout_cmd_create_background,
    geo_layout_cmd_create_clear_depth,
    geo_layout_cmd_noop,
    geo_layout_cmd_create_fog,
    geo_layout_cmd_create_light,
    geo_layout_cmd_skip,
    geo_layout_cmd_create_ambient_light,
    geo_layout_cmd_create_shadow_context,
    geo_layout_cmd_create_shadow,
    geo_layout_cmd_create_cull_distance,
    geo_layout_cmd_create_switch_case,
    geo_layout_cmd_create_translate_rotate,
    geo_layout_cmd_create_translate,
    geo_layout_cmd_create_animated_part,
    geo_layout_cmd_create_display_list_part,
    geo_layout_cmd_create_model_part,
    geo_layout_cmd_create_display_list_matrix,
    geo_layout_cmd_create_scale,
    geo_layout_cmd_create_display_list,
    geo_layout_cmd_create_shadow_texture,
    geo_layout_cmd_create_anchor,
    geo_layout_cmd_set_node_flag4,
    geo_layout_cmd_create_group,
};

static MemoryBlock* gGraphNodePool;
static GraphNode* gCurRootGraphNode;
static u32 gGeoLayoutStack[16];
static GraphNode* gCurGraphNodeList[32];
static s16 gCurGraphNodeIndex;
static s16 gGeoLayoutStackIndex;
static s16 D_800ABDFC;
static s16 gGeoLayoutReturnIndex;
static u8* gGeoLayoutCommand;

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

void register_graph_node(GraphNode* arg0) {
    if (arg0 != NULL) {
        gCurGraphNodeList[gCurGraphNodeIndex] = arg0;
        if (gCurGraphNodeIndex == 0) {
            if (gCurRootGraphNode == NULL) {
                gCurRootGraphNode = arg0;
            }
        } else {
            GraphNode_AppendChild(gCurGraphNodeList[gCurGraphNodeIndex - 1], arg0);
        }
    }
}

void geo_layout_cmd_attach_node(void) {
    unk_D_800ABE00_cmd7* cmd = (unk_D_800ABE00_cmd7*)gGeoLayoutCommand;

    register_graph_node(&cmd->unk_04->node);

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd7);
}

void geo_layout_cmd_set_callback(void) {
    unk_D_800ABE00_cmd8* cmd = (unk_D_800ABE00_cmd8*)gGeoLayoutCommand;

    if (gCurGraphNodeList[gCurGraphNodeIndex] != NULL) {
        GeoNode_SetCallback(gCurGraphNodeList[gCurGraphNodeIndex], cmd->unk_04, cmd->unk_08);
    }

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd8);
}

void geo_layout_cmd_create_container(void) {
    register_graph_node(GeoNode_CreateContainer(gGraphNodePool, NULL));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd9);
}

void geo_layout_cmd_create_reference(void) {
    unk_D_800ABE00_cmdA* cmd = (unk_D_800ABE00_cmdA*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateWithReference(gGraphNodePool, NULL, cmd->unk_04));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdA);
}

void geo_layout_cmd_create_camera(void) {
    unk_D_800ABE00_cmdB* cmd = (unk_D_800ABE00_cmdB*)gGeoLayoutCommand;
    unk_D_86002F34_00C* temp_v0 =
        GeoNode_CreateCamera(gGraphNodePool, NULL, cmd->unk_04, cmd->unk_06, cmd->unk_08, cmd->unk_0A);

    if (temp_v0 != NULL) {
        temp_v0->unk_24.fovy = cmd->unk_02;
        Vec3f_FromVec3s(&temp_v0->unk_60.at, &cmd->unk_0C);
        Camera_ComputeEyeFromAngles(&temp_v0->unk_60.at, &temp_v0->unk_60.eye, cmd->unk_16, (cmd->unk_12 << 0xF) / 180,
                      (cmd->unk_14 << 0xF) / 180);
    }

    register_graph_node(&temp_v0->node);

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdB);
}

void geo_layout_cmd_create_type3(void) {
    unk_D_800ABE00_cmdC* cmd = (unk_D_800ABE00_cmdC*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateType3(gGraphNodePool, NULL, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdC);
}

void geo_layout_cmd_create_type4(void) {
    unk_D_800ABE00_cmdD* cmd = (unk_D_800ABE00_cmdD*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateType4(gGraphNodePool, NULL, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdD);
}

void geo_layout_cmd_create_ortho(void) {
    unk_D_800ABE00_cmdE* cmd = (unk_D_800ABE00_cmdE*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateOrtho(gGraphNodePool, NULL, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdE);
}

void geo_layout_cmd_create_perspective(void) {
    unk_D_800ABE00_cmdF* cmd = (unk_D_800ABE00_cmdF*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreatePerspective(gGraphNodePool, NULL, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmdF);
}

void geo_layout_cmd_create_background(void) {
    unk_D_800ABE00_cmd10* cmd = (unk_D_800ABE00_cmd10*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateBackground(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_02, cmd->unk_03));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd10);
}

void geo_layout_cmd_create_clear_depth(void) {
    register_graph_node(GeoNode_CreateClearDepth(gGraphNodePool, NULL));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd11);
}

void geo_layout_cmd_noop(void) {
}

void geo_layout_cmd_create_fog(void) {
    unk_D_800ABE00_cmd13* cmd = (unk_D_800ABE00_cmd13*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateFog(gGraphNodePool, NULL, cmd->unk_04, cmd->unk_06, cmd->r, cmd->g, cmd->b, 0xFF));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd13);
}

void geo_layout_cmd_create_light(void) {
    unk_D_800ABE00_cmd14* cmd = (unk_D_800ABE00_cmd14*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateLight(gGraphNodePool, NULL, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, cmd->r,
                                cmd->g, cmd->b, cmd->a));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd14);
}

void geo_layout_cmd_skip(void) {
    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd15);
}

void geo_layout_cmd_create_ambient_light(void) {
    unk_D_800ABE00_cmd16* cmd = (unk_D_800ABE00_cmd16*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateAmbientLight(gGraphNodePool, NULL, cmd->r, cmd->g, cmd->b));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd16);
}

void geo_layout_cmd_create_shadow_context(void) {
    unk_D_800ABE00_cmd17* cmd = (unk_D_800ABE00_cmd17*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateShadowContext(gGraphNodePool, NULL, cmd->unk_02, cmd->unk_08, cmd->unk_04, cmd->unk_0C, cmd->unk_06,
                                cmd->unk_10));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd17);
}

void geo_layout_cmd_create_shadow(void) {
    unk_D_800ABE00_cmd18* cmd = (unk_D_800ABE00_cmd18*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateShadow(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_06, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd18);
}

void geo_layout_cmd_create_cull_distance(void) {
    unk_D_800ABE00_cmd19* cmd = (unk_D_800ABE00_cmd19*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateCullDistance(gGraphNodePool, NULL, cmd->unk_04, cmd->unk_06));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd19);
}

void geo_layout_cmd_create_switch_case(void) {
    unk_D_800ABE00_cmd1A* cmd = (unk_D_800ABE00_cmd1A*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateSwitchCase(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1A);
}

void geo_layout_cmd_create_translate_rotate(void) {
    Vec3s sp30;
    Vec3f sp24;
    UNUSED s32 pad;
    unk_D_800ABE00_cmd1B* cmd = (unk_D_800ABE00_cmd1B*)gGeoLayoutCommand;

    Vec3f_FromVec3s(&sp24, &cmd->unk_0A);
    Vec3s_SetComponents(&sp30, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, (cmd->unk_08 << 0xF) / 180);
    register_graph_node(GeoNode_CreateTranslateRotate(gGraphNodePool, NULL, &sp24, &sp30));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1B);
}

void geo_layout_cmd_create_translate(void) {
    Vec3f sp24;
    unk_D_800ABE00_cmd1C* cmd = (unk_D_800ABE00_cmd1C*)gGeoLayoutCommand;

    sp24.x = cmd->unk_04 / 65536.0f;
    sp24.y = cmd->unk_08 / 65536.0f;
    sp24.z = cmd->unk_0C / 65536.0f;
    register_graph_node(GeoNode_CreateTranslate(gGraphNodePool, NULL, &sp24));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1C);
}

void geo_layout_cmd_create_animated_part(void) {
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

    register_graph_node(
        GeoNode_CreateAnimatedPart(gGraphNodePool, NULL, cmd->unk_01, var_a3, cmd->unk_03, &cmd->unk_04, &cmd->unk_0A, &sp3C));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1D);
}

void geo_layout_cmd_create_display_list_part(void) {
    unk_D_800ABE00_cmd1E* cmd = (unk_D_800ABE00_cmd1E*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateDisplayListPart(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1E);
}

void geo_layout_cmd_create_model_part(void) {
    Vec3s sp40;
    Vec3f sp34;
    Vec3f sp28;
    DisplayObject* tmp;
    unk_D_800ABE00_cmd1F* cmd = (unk_D_800ABE00_cmd1F*)gGeoLayoutCommand;

    Vec3f_FromVec3s(&sp34, &cmd->unk_0A);

    sp28.x = cmd->unk_10 / 100.0f;
    sp28.y = cmd->unk_12 / 100.0f;
    sp28.z = cmd->unk_14 / 100.0f;

    Vec3s_SetComponents(&sp40, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, (cmd->unk_08 << 0xF) / 180);
    tmp = GeoNode_CreateModelPart(gGraphNodePool, NULL, cmd->unk_02, &sp34, &sp40, &sp28);
    register_graph_node(tmp);

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd1F);
}

void geo_layout_cmd_create_display_list_matrix(void) {
    Vec3f sp34;
    Vec3s sp2C;
    unk_D_86002F34_alt8* tmp;
    unk_D_800ABE00_cmd20* cmd = (unk_D_800ABE00_cmd20*)gGeoLayoutCommand;

    Vec3f_FromVec3s(&sp34, &cmd->unk_0A);
    Vec3s_SetComponents(&sp2C, (cmd->unk_04 << 0xF) / 180, (cmd->unk_06 << 0xF) / 180, (cmd->unk_08 << 0xF) / 180);
    tmp = GeoNode_CreateDisplayListMatrixFromTransform(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_10, &sp34, &sp2C);
    register_graph_node(tmp);

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd20);
}

void geo_layout_cmd_create_scale(void) {
    Vec3f sp2C;
    unk_D_86002F34_alt9* tmp;
    unk_D_800ABE00_cmd21* cmd = (unk_D_800ABE00_cmd21*)gGeoLayoutCommand;

    Vec3f_FromVec3s(&sp2C, &cmd->unk_02);
    tmp = GeoNode_CreateScale(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_0C, &sp2C, cmd->unk_08 / 65536.0f);
    register_graph_node(tmp);

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd21);
}

void geo_layout_cmd_create_display_list(void) {
    unk_D_800ABE00_cmd22* cmd = (unk_D_800ABE00_cmd22*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateDisplayList(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_04));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd22);
}

void geo_layout_cmd_create_shadow_texture(void) {
    unk_D_800ABE00_cmd23* cmd = (unk_D_800ABE00_cmd23*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateShadowTexture(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_02, cmd->unk_04, cmd->unk_08, cmd->unk_0A,
                                cmd->r, cmd->g, cmd->b, cmd->a));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd23);
}

void geo_layout_cmd_create_anchor(void) {
    unk_D_800ABE00_cmd24* cmd = (unk_D_800ABE00_cmd24*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateAnchor(gGraphNodePool, NULL, cmd->unk_02));

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd24);
}

void geo_layout_cmd_set_node_flag4(void) {
    unk_D_800ABE00_cmd25* cmd = (unk_D_800ABE00_cmd25*)gGeoLayoutCommand;

    if (gCurGraphNodeList[gCurGraphNodeIndex] != NULL) {
        gCurGraphNodeList[gCurGraphNodeIndex]->renderFlags |= 4;
    }

    gGeoLayoutCommand += sizeof(unk_D_800ABE00_cmd25);
}

void geo_layout_cmd_create_group(void) {
    unk_D_800ABE00_cmd26* cmd = (unk_D_800ABE00_cmd26*)gGeoLayoutCommand;

    register_graph_node(GeoNode_CreateGroup(gGraphNodePool, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_06, cmd->unk_08, cmd->unk_0A,
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
