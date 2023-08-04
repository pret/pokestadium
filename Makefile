BASEROM = baserom.z64
TARGET = pokestadium
NON_MATCHING ?= 0
RUN_CC_CHECK ?= 1
WERROR ?= 0

# Fail early if baserom does not exist
ifeq ($(wildcard $(BASEROM)),)
$(error Baserom `$(BASEROM)' not found.)
endif

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  HOST_OS := linux
else ifeq ($(UNAME_S),Darwin)
  HOST_OS := macos
else
  $(error Unsupported host/building OS <$(UNAME_S)>)
endif

BUILD_DIR := build
ROM := $(TARGET).z64
ELF := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT := $(TARGET).ld
LD_MAP := $(BUILD_DIR)/$(TARGET).map
ASM_DIRS := asm asm/os asm/libleo asm/libultra asm/libultra/os asm/libultra/io asm/libultra/gu asm/libultra/libc asm/libultra/al asm/data
DATA_DIRS := bin assets
SRC_DIRS := $(shell find src -type d)

C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
DATA_FILES := $(foreach dir,$(DATA_DIRS),$(wildcard $(dir)/*.bin))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.c.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.s.o)) \
           $(foreach file,$(DATA_FILES),$(BUILD_DIR)/$(file:.bin=.bin.o)) \

DECOMP_C_OBJS := $(filter %.c.o,$(filter-out $(BUILD_DIR)/src/libultra%,$(O_FILES)))
DECOMP_POKE_STADIUM := $(filter %.c.o,$(filter-out $(BUILD_DIR)/src/libleo%,$(DECOMP_C_OBJS)))
DECOMP_LIBLEO := $(filter $(BUILD_DIR)/src/libleo/%.c.o,$(O_FILES))

DEP_FILES := $(O_FILES:.o=.d) $(DECOMP_C_OBJS:.o=.asmproc.d)

SPLAT_YAML := splat.yaml
SPLAT = $(PYTHON) tools/n64splat/split.py $(SPLAT_YAML)

##################### Compiler Options #######################
findcmd = $(shell type $(1) >/dev/null 2>/dev/null; echo $$?)

ifeq ($(call findcmd,mips-linux-gnu-ld),0)
  CROSS := mips-linux-gnu-
else ifeq ($(call findcmd,mips64-elf-ld),0)
  CROSS := mips64-elf-
else ifeq ($(call findcmd,mips-elf-ld),0)
  CROSS := mips-elf-
else
  $(error Missing cross compilation toolchain)
endif

AS = $(CROSS)as
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
ifeq ($(HOST_OS),macos)
  CPP := clang -E -P -x c
else
  CPP := cpp
endif

#CC         := $(QEMU_IRIX) -L tools/ido7.1_compiler tools/ido7.1_compiler/usr/bin/cc
#CC_OLD     := $(QEMU_IRIX) -L tools/ido5.3_compiler tools/ido5.3_compiler/usr/bin/cc

CC = tools/ido_recomp/$(HOST_OS)/7.1/cc
CC_OLD = tools/ido_recomp/$(HOST_OS)/5.3/cc
ASMPROC = python3 tools/asmproc/build.py
ASMPROC_FLAGS :=

MIPS_VERSION := -mips2

OPTFLAGS := -O2

OBJDUMP_FLAGS := -d -r -z -Mreg-names=32

# include locations
INC_DIRS := include include/PR include/audio .
IINCS := $(foreach d,$(INC_DIRS),-I$d)
# defines for SGI IDO
CDEFS := -D_LANGUAGE_C -DF3DEX_GBI_2 -DNDEBUG 

ifneq ($(RUN_CC_CHECK),0)
  CHECK_WARNINGS := -Wall -Wextra
  CHECK_DEFS := -D_MIPS_SZLONG=32 -DNON_MATCHING
  CHECK_FLAGS := -fno-builtin -funsigned-char -fdiagnostics-color -std=gnu89 $(CDEFS) $(CHECK_DEFS) $(IINCS) -nostdinc
  CC_CHECK := gcc -fsyntax-only

  ifeq ($(HOST_OS),linux)
    CC_CHECK += -m32
  endif

  ifneq ($(WERROR),0)
    CHECK_WARNINGS += -Werror
  endif
else
  CC_CHECK := @:
endif

######################## Flags #############################

ASFLAGS = -EB -mtune=vr4300 -march=vr4300 $(IINCS) -32

# we support Microsoft extensions such as anonymous structs, which the compiler does support but warns for their usage. Surpress the warnings with -woff.
CFLAGS  = -G 0 -non_shared -Xfullwarn -Xcpluscomm $(IINCS) -Wab,-r4300_mul $(CDEFS) -woff 649,838,712,807 $(MIPS_VERSION)

LDFLAGS = -T undefined_syms.txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(BUILD_DIR)/$(TARGET).map --no-check-sections


######################## Targets #############################

$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(DATA_DIRS) $(COMPRESSED_DIRS) $(MAP_DIRS) $(BGM_DIRS),$(shell mkdir -p build/$(dir)))

# The reimplementations of the string functions need to treat char as signed.
build/src/hal_libc.c.o: CFLAGS += -signed

# Libultra O1 files
build/src/libultra/os/sendmesg.c.o: OPTFLAGS := -O1
build/src/libultra/os/stopthread.c.o: OPTFLAGS := -O1
build/src/libultra/os/recvmesg.c.o: OPTFLAGS := -O1
build/src/libultra/os/destroythread.c.o: OPTFLAGS := -O1
build/src/libultra/os/dequeuethread.c.o: OPTFLAGS := -O1
build/src/libultra/os/createthread.c.o: OPTFLAGS := -O1
build/src/libultra/os/virtualtophysical.c.o: OPTFLAGS := -O1
build/src/libultra/os/initialize.c.o: OPTFLAGS := -O1
build/src/libultra/os/epilinkhandle.c.o: OPTFLAGS := -O1
build/src/libultra/os/getmemsize.c.o: OPTFLAGS := -O1
build/src/libultra/os/seteventmesg.c.o: OPTFLAGS := -O1
build/src/libultra/os/createmesgqueue.c.o: OPTFLAGS := -O1
build/src/libultra/os/jammesg.c.o: OPTFLAGS := -O1
build/src/libultra/os/setthreadpri.c.o: OPTFLAGS := -O1
build/src/libultra/os/gettime.c.o: OPTFLAGS := -O1
build/src/libultra/os/timerintr.c.o: OPTFLAGS := -O1
build/src/libultra/os/setglobalintmask.c.o: OPTFLAGS := -O1
build/src/libultra/os/resetglobalintmask.c.o: OPTFLAGS := -O1
build/src/libultra/os/settime.c.o: OPTFLAGS := -O1
build/src/libultra/os/yieldthread.c.o: OPTFLAGS := -O1
build/src/libultra/os/settimer.c.o: OPTFLAGS := -O1
build/src/libultra/os/startthread.c.o: OPTFLAGS := -O1
build/src/libultra/os/sethwinterrupt.c.o: OPTFLAGS := -O1
build/src/libultra/io/pigetcmdq.c.o: OPTFLAGS := -O1
build/src/libultra/io/sptask.c.o: OPTFLAGS := -O1
build/src/libultra/io/controller.c.o: OPTFLAGS := -O1
build/src/libultra/io/conteeplongread.c.o: OPTFLAGS := -O1
build/src/libultra/io/viblack.c.o: OPTFLAGS := -O1
build/src/libultra/io/visetmode.c.o: OPTFLAGS := -O1
build/src/libultra/io/virepeatline.c.o: OPTFLAGS := -O1
build/src/libultra/io/pfsisplug.c.o: OPTFLAGS := -O1
build/src/libultra/io/epidma.c.o: OPTFLAGS := -O1
build/src/libultra/io/dpctr.c.o: OPTFLAGS := -O1
build/src/libultra/io/conteeplongwrite.c.o: OPTFLAGS := -O1
build/src/libultra/io/si.c.o: OPTFLAGS := -O1
build/src/libultra/io/sp.c.o: OPTFLAGS := -O1
build/src/libultra/io/viswapbuf.c.o: OPTFLAGS := -O1
build/src/libultra/io/sptaskyielded.c.o: OPTFLAGS := -O1
build/src/libultra/io/vi.c.o: OPTFLAGS := -O1
build/src/libultra/io/visetevent.c.o: OPTFLAGS := -O1
build/src/libultra/io/aisetnextbuf.c.o: OPTFLAGS := -O1
build/src/libultra/io/ai.c.o: OPTFLAGS := -O1
build/src/libultra/io/vigetcurrframebuf.c.o: OPTFLAGS := -O1
build/src/libultra/io/spsetpc.c.o: OPTFLAGS := -O1
build/src/libultra/libc/ll.c.o: OPTFLAGS := -O1
build/src/libultra/libc/ll.c.o: MIPS_VERSION := -mips3 -32
build/src/libultra/libc/llcvt.c.o: OPTFLAGS := -O1
build/src/libultra/libc/llcvt.c.o: MIPS_VERSION := -mips3 -32

# cheap hack. TODO: Make the override better
build/src/libultra/io/gbpakpower.c.o: OPTFLAGS += -Wo,-loopunroll,0
build/src/libultra/io/gbpakinit.c.o: OPTFLAGS += -Wo,-loopunroll,0
build/src/libultra/io/gbpakselectbank.c.o: OPTFLAGS += -Wo,-loopunroll,0

build/src/C030.c.o: OPTFLAGS += -Wo,-loopunroll,0

# Libultra misc
build/src/libultra/gu/scale.c.o: CC := $(CC_OLD)
build/src/libultra/gu/scale.c.o: OPTFLAGS := -O3
build/src/libultra/gu/translate.c.o: CC := $(CC_OLD)
build/src/libultra/gu/translate.c.o: OPTFLAGS := -O3
build/src/libultra/gu/mtxcatf.c.o: CC := $(CC_OLD)
build/src/libultra/gu/mtxcatf.c.o: OPTFLAGS := -O3
build/src/libultra/gu/mtxcatl.c.o: CC := $(CC_OLD)
build/src/libultra/gu/mtxcatl.c.o: OPTFLAGS := -O3
build/src/libultra/gu/rotateRPY.c.o: CC := $(CC_OLD)
build/src/libultra/gu/rotateRPY.c.o: OPTFLAGS := -O3
build/src/libultra/gu/rotate.c.o: CC := $(CC_OLD)
build/src/libultra/gu/rotate.c.o: OPTFLAGS := -O3
build/src/libultra/gu/ortho.c.o: CC := $(CC_OLD)
build/src/libultra/gu/ortho.c.o: OPTFLAGS := -O3
build/src/libultra/gu/sinf.c.o: CC := $(CC_OLD)
build/src/libultra/gu/cosf.c.o: CC := $(CC_OLD)
build/src/libultra/gu/random.c.o: CC := $(CC_OLD)
build/src/libultra/libc/xprintf.c.o: CC := $(CC_OLD)
build/src/libultra/libc/xprintf.c.o: OPTFLAGS := -O3
build/src/libultra/libc/xldtob.c.o: CC := $(CC_OLD)
build/src/libultra/libc/xldtob.c.o: OPTFLAGS := -O3
build/src/libultra/libc/xlitob.c.o: CC := $(CC_OLD)
build/src/libultra/libc/xlitob.c.o: OPTFLAGS := -O3
build/src/libultra/libc/string.c.o: CC := $(CC_OLD)
build/src/libultra/libc/string.c.o: OPTFLAGS := -O3
build/src/libultra/io/controller.c.o: CC := $(CC_OLD)
build/src/libultra/io/contreaddata.c.o: CC := $(CC_OLD)
build/src/libultra/io/devmgr.c.o: CC := $(CC_OLD)
build/src/libultra/os/initialize.c.o: CC := $(CC_OLD)
build/src/libultra/io/pfsgetstatus.c.o: CC := $(CC_OLD)
build/src/libultra/io/epiread.c.o: CC := $(CC_OLD)
build/src/libultra/al/reverb.c.o: CC := $(CC_OLD)
build/src/libultra/al/bnkf.c.o: CC := $(CC_OLD)
build/src/libultra/al/bnkf.c.o: OPTFLAGS := -O3
build/src/libultra/al/load.c.o: CC := $(CC_OLD)
build/src/libultra/al/load.c.o: OPTFLAGS := -O3
build/src/libultra/al/synthesizer.c.o: CC := $(CC_OLD)
build/src/libultra/al/drvrNew.c.o: CC := $(CC_OLD)
build/src/libultra/al/mainbus.c.o: CC := $(CC_OLD)
build/src/libultra/al/mainbus.c.o: OPTFLAGS := -O3
build/src/libultra/al/auxbus.c.o: CC := $(CC_OLD)
build/src/libultra/al/auxbus.c.o: OPTFLAGS := -O3
build/src/libultra/al/env.c.o: CC := $(CC_OLD)
build/src/libultra/al/resample.c.o: CC := $(CC_OLD)
build/src/libultra/al/resample.c.o: OPTFLAGS := -O3
build/src/libultra/al/save.c.o: CC := $(CC_OLD)
build/src/libultra/al/heapalloc.c.o: CC := $(CC_OLD)
build/src/libultra/gu/mtxutil.c.o: CC := $(CC_OLD)
build/src/libultra/gu/mtxutil.c.o: OPTFLAGS := -O3
build/src/libultra/io/pfsisplug.c.o: CC := $(CC_OLD)
build/src/libultra/io/conteepprobe.c.o: CC := $(CC_OLD)
build/src/libultra/io/conteepwrite.c.o: CC := $(CC_OLD)
build/src/libultra/io/conteepread.c.o: CC := $(CC_OLD)
build/src/libultra/io/contpfs.c.o: CC := $(CC_OLD)
build/src/libultra/io/viswapcontext.c.o: CC := $(CC_OLD)
build/src/libultra/io/contramwrite.c.o: CC := $(CC_OLD)
build/src/libultra/io/contramread.c.o: CC := $(CC_OLD)
build/src/libultra/io/crc.c.o: CC := $(CC_OLD)
build/src/libultra/libc/ldiv.c.o: CC := $(CC_OLD)
build/src/libultra/io/vimgr.c.o: CC := $(CC_OLD)
build/src/libultra/io/visetxscale.c.o: CC := $(CC_OLD)
build/src/libultra/io/visetxscale.c.o: OPTFLAGS := -O1
build/src/libultra/io/visetyscale.c.o: CC := $(CC_OLD)
build/src/libultra/io/visetyscale.c.o: OPTFLAGS := -O1
build/src/libultra/al/synallocfx.c.o: CC := $(CC_OLD)
build/src/libultra/al/synallocfx.c.o: OPTFLAGS := -O3

build/src/libultra/io/gbpakcheckconnector.c.o: CC := $(CC_OLD)
build/src/libultra/io/gbpakreadid.c.o: CC := $(CC_OLD)
build/src/libultra/io/gbpakreadwrite.c.o: CC := $(CC_OLD)
build/src/libultra/io/gbpakselectbank.c.o: CC := $(CC_OLD)

# run ASM-processor on non-libultra source files
$(DECOMP_POKE_STADIUM): CC := $(ASMPROC) $(ASMPROC_FLAGS) $(CC) -- $(AS) $(ASFLAGS) --
$(DECOMP_LIBLEO): CC := $(ASMPROC) $(ASMPROC_FLAGS) $(CC_OLD) -- $(AS) $(ASFLAGS) --

# turn off syntax checking errors for libultra
build/src/libultra/al/%.c.o: CHECK_WARNINGS := -w
build/src/libultra/gu/%.c.o: CHECK_WARNINGS := -w
build/src/libultra/io/%.c.o: CHECK_WARNINGS := -w
build/src/libultra/libc/%.c.o: CHECK_WARNINGS := -w
build/src/libultra/os/%.c.o: CHECK_WARNINGS := -w

######################## Build #############################

default: all

LD_SCRIPT = $(TARGET).ld

all: $(BUILD_DIR) $(BUILD_DIR)/$(ROM) verify

distclean:
	rm -rf asm bin assets $(BUILD_DIR) undefined_syms_auto.txt undefined_funcs_auto.txt

clean:
	rm -rf $(BUILD_DIR)

submodules:
	git submodule update --init --recursive

split:
	rm -rf $(DATA_DIRS) $(ASM_DIRS) && ./tools/n64splat/split.py $(SPLAT_YAML)

setup: distclean submodules split
	
$(BUILD_DIR):
	echo $(C_FILES)
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	@mkdir -p $(shell dirname $@)
	$(CPP) -P -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary

$(BUILD_DIR)/$(TARGET).elf: $(O_FILES) $(BUILD_DIR)/$(LD_SCRIPT)
	@$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.c.o: %.c
	$(CC_CHECK) $(CHECK_FLAGS) $(CHECK_WARNINGS) -MMD -MP -MT $@ -MF $(@:.o=.d) $<
	$(CC) -c $(CFLAGS) $(OPTFLAGS) -o $@ $<

$(BUILD_DIR)/src/libultra/libc/ll.c.o: src/libultra/libc/ll.c
	$(CC) -c $(CFLAGS) $(OPTFLAGS) -o $@ $<
	python3 tools/set_o32abi_bit.py $@
	@$(OBJDUMP) $(OBJDUMP_FLAGS) $@ > $(@:.o=.s)

$(BUILD_DIR)/src/libultra/libc/llcvt.c.o: src/libultra/libc/llcvt.c
	$(CC) -c $(CFLAGS) $(OPTFLAGS) -o $@ $<
	python3 tools/set_o32abi_bit.py $@
	@$(OBJDUMP) $(OBJDUMP_FLAGS) $@ > $(@:.o=.s)

$(BUILD_DIR)/%.s.o: %.s
	iconv --from UTF-8 --to EUC-JP $^ | $(AS) $(ASFLAGS) -o $@

$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o $@ $<

# final z64 updates checksum
$(BUILD_DIR)/$(ROM): $(BUILD_DIR)/$(TARGET).bin
	@cp $< $@

verify: $(BUILD_DIR)/$(ROM)
	md5sum -c checksum.md5

.PHONY: all clean distclean default split setup

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

-include $(DEP_FILES)
