# Build options can be changed by modifying the makefile or by building with 'make SETTING=value'.
# It is also possible to override the settings in Defaults in a file called .make_options as 'SETTING=value'.

-include .make_options

MAKEFLAGS += --no-builtin-rules

# Ensure the build fails if a piped command fails
SHELL = /bin/bash
.SHELLFLAGS = -o pipefail -c

# OS Detection
ifeq ($(OS),Windows_NT)
$(error Native Windows is currently unsupported for building this repository, use WSL instead c:)
else
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S),Linux)
    DETECTED_OS = linux
    MAKE = make
    VENV_BIN_DIR = bin
  endif
  ifeq ($(UNAME_S),Darwin)
    DETECTED_OS = macos
    MAKE = gmake
    VENV_BIN_DIR = bin
  endif
endif

#### Defaults ####
# Target game version. Currently only the following version is supported:
#   us   N64 US (default)
VERSION ?= us
# If COMPARE is 1, check the output md5sum after building
COMPARE ?= 1
# If NON_MATCHING is 1, define the NON_MATCHING C flag when building
NON_MATCHING ?= 0
# if WERROR is 1, pass -Werror to CC_CHECK, so warnings would be treated as errors
WERROR ?= 0
# Keep .mdebug section in build
KEEP_MDEBUG ?= 1
# Check code syntax with host compiler
RUN_CC_CHECK ?= 1
CC_CHECK_COMP ?= gcc
# Dump build object files
OBJDUMP_BUILD ?= 0
# Number of threads to compress with
N_THREADS ?= $(shell nproc)
# Not meant to be used by normal users. Toggles some options to improve the use of the warning checker system
WARNINGS_CHECK ?= 0
# Disassembles matched functions and migrated data as well
FULL_DISASM ?= 0
# Python virtual environment
VENV ?= .venv
# Python interpreter
PYTHON ?= $(VENV)/$(VENV_BIN_DIR)/python3
# Emulator w/ flags
N64_EMULATOR ?=
# Set prefix to mips binutils binaries (mips-linux-gnu-ld => 'mips-linux-gnu-') - Change at your own risk!
# In nearly all cases, not having 'mips-linux-gnu-*' binaries on the PATH is indicative of missing dependencies
MIPS_BINUTILS_PREFIX ?= mips-linux-gnu-
PRINT = printf

PREPROCESS :=

# Whether to hide commands or not
VERBOSE ?= 0
ifeq ($(VERBOSE),0)
  V := @
endif

# Whether to colorize build messages
COLOR ?= 1

TARGET  := pokestadium

# Run at the start of the build
ifeq ($(filter clean distclean setup extract venv rom run all diff-init,$(MAKECMDGOALS)),)
  $(info ==== Build Options ====)
  $(info Version:        $(VERSION))
  $(info Microcode:      f3dex)
  $(info Target:         $(TARGET))
  ifeq ($(COMPARE),1)
    $(info Compare ROM:    yes)
  else
    $(info Compare ROM:    no)
  endif
  ifeq ($(NON_MATCHING),1)
    $(info Build Matching: no)
  else
    $(info Build Matching: yes)
  endif
  $(info =======================)
endif

BASEROM_DIR := baseroms/$(VERSION)
BASEROM     := $(BASEROM_DIR)/baserom.z64

ULTRALIB_VERSION     := I_P
ULTRALIB_TARGET      := libultra_rom

### Output ###

BUILD_DIR := build
ROM       := $(BUILD_DIR)/$(TARGET)-$(VERSION).z64
ELF       := $(ROM:.z64=.elf)
MAP       := $(ROM:.z64=.map)
LDSCRIPT  := $(ROM:.z64=.ld)


#### Setup ####

BUILD_DEFINES ?=

ifeq ($(VERSION),us)
  BUILD_DEFINES   += -DVERSION_US=1
else
$(error Invalid VERSION variable detected. Please use 'us')
endif


ifeq ($(NON_MATCHING),1)
  BUILD_DEFINES   += -DNON_MATCHING -DAVOID_UB
  COMPARE  := 0
endif

MAKE = make
CPPFLAGS += -fno-dollars-in-identifiers -P
LDFLAGS  := --no-check-sections --accept-unknown-input-arch --emit-relocs --whole-archive

ifeq ($(DETECTED_OS), macos)
  CPPFLAGS += -xc++
endif

#### Tools ####
ifneq ($(shell type $(MIPS_BINUTILS_PREFIX)ld >/dev/null 2>/dev/null; echo $$?), 0)
$(error Unable to find $(MIPS_BINUTILS_PREFIX)ld. Please install or build MIPS binutils, commonly mips-linux-gnu. (or set MIPS_BINUTILS_PREFIX if your MIPS binutils install uses another prefix))
endif


CC              := tools/ido/$(DETECTED_OS)/7.1/cc
CC_OLD          := tools/ido/$(DETECTED_OS)/5.3/cc

AS              := $(MIPS_BINUTILS_PREFIX)as
LD              := $(MIPS_BINUTILS_PREFIX)ld
OBJCOPY         := $(MIPS_BINUTILS_PREFIX)objcopy
OBJDUMP         := $(MIPS_BINUTILS_PREFIX)objdump
NM              := $(MIPS_BINUTILS_PREFIX)nm

AR              := ar
CPP             := cpp
ICONV           := iconv
CAT             := cat

ASM_PROC        := $(PYTHON) tools/asm-processor/build.py
ASM_PROC_FLAGS  := --input-enc=utf-8 --output-enc=euc-jp --convert-statics=global-with-filename

SPLAT           := $(PYTHON) -m splat split
SPLAT_YAML      := $(TARGET)-$(VERSION).yaml

ENCRYPT_LIBLEO  := $(PYTHON) tools/encrypt_libleo.py
EXTRACT_ASSETS  := tools/extract_assets.sh

IINC := -Iinclude -Isrc -Isrc/libnaudio -Iassets/$(VERSION) -I. -I$(BUILD_DIR)
IINC += -Ilib/ultralib/include -Ilib/ultralib/include/PR -Ilib/ultralib/include/ido
IINC += -Iinclude/

ifeq ($(KEEP_MDEBUG),0)
  RM_MDEBUG = $(OBJCOPY) --remove-section .mdebug $@
else
  RM_MDEBUG = @:
endif

# Check code syntax with host compiler
CHECK_WARNINGS := -Wall -Wextra -Wimplicit-fallthrough -Wno-unknown-pragmas -Wno-missing-braces -Wno-sign-compare -Wno-uninitialized -Wno-unused-label -Wno-int-conversion -Wno-incompatible-function-pointer-types -Wno-return-mismatch
# Have CC_CHECK pretend to be a MIPS compiler
MIPS_BUILTIN_DEFS := -DMIPSEB -D_MIPS_FPSET=16 -D_MIPS_ISA=2 -D_ABIO32=1 -D_MIPS_SIM=_ABIO32 -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32
ifneq ($(RUN_CC_CHECK),0)
#   The -MMD flags additionaly creates a .d file with the same name as the .o file.
  CC_CHECK          := $(CC_CHECK_COMP)
  CC_CHECK_FLAGS    := -MMD -MP -fno-builtin -fsyntax-only -funsigned-char -fdiagnostics-color -std=gnu89 -m32 -DNON_MATCHING -DAVOID_UB -DCC_CHECK
  ifneq ($(WERROR), 0)
    CHECK_WARNINGS  += -Werror
  endif
else
  CC_CHECK          := @:
endif


CFLAGS          += -G 0 -non_shared -Xcpluscomm -nostdinc -Wab,-r4300_mul

WARNINGS         := -fullwarn -verbose -woff 624,649,838,712,516,513,596,564,594
ASFLAGS          := -march=vr4300 -32 -G0
COMMON_DEFINES   := -D_MIPS_SZLONG=32
GBI_DEFINES      := -DF3DEX_GBI_2
RELEASE_DEFINES  := -DNDEBUG -D_FINALROM -DN_MICRO
AS_DEFINES       := -DMIPSEB -D_LANGUAGE_ASSEMBLY -D_ULTRA64
C_DEFINES        := -DLANGUAGE_C -D_LANGUAGE_C
LIBULTRA_DEFINES := -DBUILD_VERSION=VERSION_$(ULTRALIB_VERSION)
ENDIAN           := -EB

OPTFLAGS        := -O2
MIPS_VERSION    := -mips2
ICONV_FLAGS     := --from-code=UTF-8 --to-code=EUC-JP

# Use relocations and abi fpr names in the dump
OBJDUMP_FLAGS := --disassemble --reloc --disassemble-zeroes -Mreg-names=32 -Mno-aliases

ifneq ($(OBJDUMP_BUILD), 0)
  OBJDUMP_CMD = $(OBJDUMP) $(OBJDUMP_FLAGS) $@ > $(@:.o=.s)
  OBJCOPY_BIN = $(OBJCOPY) -O binary $@ $@.bin
  LIBDUMP_CMD = $(AR) xo --output $(@:.a=) $@
else
  OBJDUMP_CMD = @:
  OBJCOPY_BIN = @:
  LIBDUMP_CMD = @:
endif

SPLAT_FLAGS ?=
ifneq ($(WARNINGS_CHECK), 0)
  SPLAT_FLAGS += --stdout-only
endif

ifneq ($(FULL_DISASM), 0)
  SPLAT_FLAGS += --disassemble-all
endif

#### Files ####

$(shell mkdir -p asm/$(VERSION) assets/$(VERSION) linker_scripts/$(VERSION)/auto)

ULTRALIB_DIR  := lib/ultralib
ULTRALIB_LIB  := $(ULTRALIB_DIR)/build/$(ULTRALIB_VERSION)/$(ULTRALIB_TARGET)/$(ULTRALIB_TARGET).a
LIBULTRA_DIR  := lib/libultra
LIBULTRA_LIB  := $(BUILD_DIR)/$(LIBULTRA_DIR).a

SRC_DIRS      := $(shell find src -type d)
ASM_DIRS      := $(shell find asm/$(VERSION) -type d -not -path "asm/$(VERSION)/nonmatchings/*" -not -path "asm/$(VERSION)/lib/*")
ASSET_DIRS    := $(shell find assets/$(VERSION) -type d)
LIB_DIRS      := $(foreach f, $(LIBULTRA_DIR), $f)

C_FILES       := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES       := $(foreach dir,$(ASM_DIRS) $(SRC_DIRS),$(wildcard $(dir)/*.s))
BIN_FILES     := $(foreach dir,$(ASSET_DIRS),$(wildcard $(dir)/*.bin))
O_FILES       := $(foreach f,$(C_FILES:.c=.o),$(BUILD_DIR)/$f) \
                 $(foreach f,$(S_FILES:.s=.o),$(BUILD_DIR)/$f) \
                 $(foreach f,$(BIN_FILES:.bin=.o),$(BUILD_DIR)/$f)

ASSET_PNGS := $(foreach dir,$(ASSET_DIRS),$(wildcard $(dir)/*.png))
ASSET_BINS := $(foreach f,$(ASSET_PNGS:.png=.bin),$(BUILD_DIR)/$f)
ASSET_INC_C := $(foreach f,$(ASSET_PNGS:.png=.inc.c),$(BUILD_DIR)/$f)


# Automatic dependency files
DEP_FILES := $(O_FILES:.o=.d) \
             $(O_FILES:.o=.asmproc.d)

# create build directories
$(shell mkdir -p $(BUILD_DIR)/linker_scripts/$(VERSION) $(BUILD_DIR)/linker_scripts/$(VERSION)/auto $(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(ASSET_DIRS) $(LIB_DIRS),$(BUILD_DIR)/$(dir)))


# directory flags
build/src/boot/O2/%.o: OPTFLAGS := -O2
build/src/boot/libc/%.o: OPTFLAGS := -O2
build/src/boot/libc64/%.o: OPTFLAGS := -O2
build/src/boot/libm/%.o: OPTFLAGS := -O2
build/src/boot/libu64/%.o: OPTFLAGS := -O2

# per-file flags

build/src/boot/fault.o: CFLAGS += -trapuv
build/src/boot/fault_drawer.o: CFLAGS += -trapuv
build/src/C030.o: OPTFLAGS += -Wo,-loopunroll,0
build/src/hal_libc.o: CFLAGS += -signed

build/src/libleo/%.o: CC := $(CC_OLD)

build/src/D470.o: CC := $(CC_OLD)
build/src/D470.o: OPTFLAGS := -O0
build/src/D470.o: MIPS_VERSION := -mips1

ifeq ($(COLOR),1)
NO_COL  := \033[0m
RED     := \033[0;31m
GREEN   := \033[0;32m
BLUE    := \033[0;34m
YELLOW  := \033[0;33m
BLINK   := \033[33;5m
endif

# Common build print status function
define print
  @$(PRINT) "$(GREEN)$(1) $(YELLOW)$(2)$(GREEN) -> $(BLUE)$(3)$(NO_COL)\n"
endef

DECOMP_POKESTADIUM := $(filter-out src/libleo/%,$(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c)))
DECOMP_POKESTADIUM_FILTERED := $(patsubst %.c,%.o,$(addprefix build/,$(shell find $(DECOMP_POKESTADIUM) -type f -exec grep -l "GLOBAL_ASM" {} \;)))

# only run asm processor on files that need it.
$(DECOMP_POKESTADIUM_FILTERED): CC := $(ASM_PROC) $(ASM_PROC_FLAGS) $(CC) -- $(AS) $(ASFLAGS) --

$(BUILD_DIR)/src/%.o: PREPROCESS := ./tools/preprocess.sh -i $(ICONV) --

###################### Ugly hacksz #############################

# This is unsanitary to do, -but-, because this file is encrypted we cant have splat decrypt it
# on split. This requires us to include this manually, but it needs to be in the dependency
# list. So we add it.
O_FILES += build/src/libleo/bootstrap.s.o

#### Main Targets ###

rom: $(ROM)
	@$(PRINT) "$(RED)Building ROM...\n$(NO_COL)"
ifneq ($(COMPARE),0)
	@md5sum $(ROM)
	@md5sum -c $(BASEROM_DIR)/checksum.md5
endif

clean:
	@$(PRINT) "$(RED)Cleaning ROM build files...\n$(NO_COL)"
	$(V)$(RM) -r $(BUILD_DIR)

libclean:
	@$(PRINT) "$(RED)Cleaning libultra build files...\n$(NO_COL)"
	$(V)$(MAKE) -C lib/ultralib clean VERSION=$(ULTRALIB_VERSION) TARGET=$(ULTRALIB_TARGET)
	$(V)$(RM) -rf $(BUILD_DIR)/lib
	$(V)$(RM) -r build/$(TARGET)-$(VERSION).elf
	$(V)$(RM) -r build/$(TARGET)-$(VERSION).ld
	$(V)$(RM) -r build/$(TARGET)-$(VERSION).map
	$(V)$(RM) -r build/$(TARGET)-$(VERSION).z64

distclean: clean libclean
	@$(PRINT) "$(RED)Performing full source distribution clean...\n$(NO_COL)"
	$(V)$(RM) -r $(BUILD_DIR) asm/ assets/ .splat/
	$(V)$(RM) -r linker_scripts/$(VERSION)/auto $(LDSCRIPT)
	$(V)$(MAKE) -C tools distclean

venv:
	@$(PRINT) "$(RED)Testing venv and setting up python requirements...\n$(NO_COL)"
	$(V)test -d $(VENV) || python3 -m venv $(VENV)
	$(V)$(PYTHON) -m ensurepip --upgrade
	$(V)$(PYTHON) -m pip install -U pip
	$(V)$(PYTHON) -m pip install -U -r requirements.txt

setup:
	@$(PRINT) "$(RED)Setting up tools...\n$(NO_COL)"
	$(V)$(MAKE) -C tools WARNINGS_CHECK=$(WARNINGS_CHECK)

extract:
	@$(PRINT) "$(YELLOW)Running ROM extraction...\n$(NO_COL)"
	$(V)$(RM) -r asm/$(VERSION) assets/$(VERSION)
	$(V)$(CAT) yamls/$(VERSION)/header.yaml yamls/$(VERSION)/rom.yaml > $(SPLAT_YAML)
	$(V)$(SPLAT) $(SPLAT_FLAGS) $(SPLAT_YAML)
	$(V)$(EXTRACT_ASSETS)

lib: $(ULTRALIB_LIB)

diff-init: rom
	$(RM) -r expected/
	mkdir -p expected/
	cp -r $(BUILD_DIR) expected/$(BUILD_DIR)

init: distclean
	$(MAKE) venv
	$(MAKE) setup
	$(MAKE) extract
	$(MAKE) diff-init

run: $(ROM)
ifeq ($(N64_EMULATOR),)
	$(error Emulator path not set. Set N64_EMULATOR in the Makefile, .make_options, or define it as an environment variable)
endif
	$(N64_EMULATOR) $<

.PHONY: all rom clean libclean distclean venv setup extract lib diff-init init run
.DEFAULT_GOAL := rom
# Prevent removing intermediate files
.SECONDARY:


#### Various Recipes ####

$(ROM): $(ELF)
	$(call print,Building ROM:,$<,$@)
	$(V)$(OBJCOPY) -O binary --gap-fill=0xFF $< $@
	$(V)$(ENCRYPT_LIBLEO) $@ $(MAP)

# TODO: update rom header checksum

# TODO: avoid using auto/undefined
$(ELF): $(O_FILES) $(LIBULTRA_LIB) $(LDSCRIPT) $(BUILD_DIR)/linker_scripts/$(VERSION)/hardware_regs.ld $(BUILD_DIR)/linker_scripts/$(VERSION)/undefined_syms.ld $(BUILD_DIR)/linker_scripts/$(VERSION)/unused_syms.ld $(BUILD_DIR)/linker_scripts/common_undef_syms.ld $(BUILD_DIR)/linker_scripts/$(VERSION)/auto/undefined_syms_auto.ld $(BUILD_DIR)/linker_scripts/$(VERSION)/auto/undefined_funcs_auto.ld
	@$(PRINT) "$(GREEN)Linking ELF file:  $(BLUE)$@ $(NO_COL)\n"
	$(V)$(LD) $(LDFLAGS) -T $(LDSCRIPT) \
		-T $(BUILD_DIR)/linker_scripts/$(VERSION)/hardware_regs.ld -T $(BUILD_DIR)/linker_scripts/$(VERSION)/undefined_syms.ld \
		-T $(BUILD_DIR)/linker_scripts/$(VERSION)/unused_syms.ld -T $(BUILD_DIR)/linker_scripts/common_undef_syms.ld \
		-T $(BUILD_DIR)/linker_scripts/$(VERSION)/auto/undefined_syms_auto.ld -T $(BUILD_DIR)/linker_scripts/$(VERSION)/auto/undefined_funcs_auto.ld \
		-Map $(MAP) $(LIBULTRA_LIB) -o $@

$(LDSCRIPT): linker_scripts/$(VERSION)/$(TARGET).ld
	$(call print,Copying linker script to build dir:,$<,$@)
	$(V)cp $< $@

$(BUILD_DIR)/%.ld: %.ld
	$(call print,Preprocessing linker script:,$<,$@)
	$(V)$(CPP) $(CPPFLAGS) $(BUILD_DEFINES) $(IINC) $< > $@

$(LIBULTRA_LIB): $(ULTRALIB_LIB)
	$(call print,Archiving libultra lib:,$<,$@)
	$(V)cp $< $@
	$(V)$(LIBDUMP_CMD)

$(ULTRALIB_LIB):
	@$(PRINT) "$(GREEN)Making libultra:  $(BLUE)$@ $(NO_COL)\n"
	$(V)$(MAKE) -C lib/ultralib VERSION=$(ULTRALIB_VERSION) TARGET=$(ULTRALIB_TARGET) FIXUPS=1 CROSS=$(MIPS_BINUTILS_PREFIX) CC=../../$(CC_OLD) VERBOSE=$(VERBOSE) COLOR=$(COLOR)

$(BUILD_DIR)/%.o: %.bin
	$(call print,Binning object:,$<,$@)
	$(V)$(OBJCOPY) -I binary -O elf32-big $< $@

$(BUILD_DIR)/%.o: %.s
	$(call print,Assembling:,$<,$@)
	$(V)$(ICONV) $(ICONV_FLAGS) $< | $(AS) $(ASFLAGS) $(ENDIAN) $(IINC) -I $(dir $*) -o $@
	$(V)$(OBJDUMP_CMD)

$(BUILD_DIR)/%.o: %.c
	$(call print,Compiling:,$<,$@)
	$(V)$(CC_CHECK) $(CC_CHECK_FLAGS) $(IINC) -I $(dir $*) $(CHECK_WARNINGS) $(BUILD_DEFINES) $(COMMON_DEFINES) $(RELEASE_DEFINES) $(GBI_DEFINES) $(LIBULTRA_DEFINES) $(C_DEFINES) $(MIPS_BUILTIN_DEFS) -o $@ $<
	$(V)$(PREPROCESS) $(CC) -c $(CFLAGS) $(BUILD_DEFINES) $(IINC) $(WARNINGS) $(MIPS_VERSION) $(ENDIAN) $(COMMON_DEFINES) $(RELEASE_DEFINES) $(GBI_DEFINES) $(LIBULTRA_DEFINES) $(C_DEFINES) $(OPTFLAGS) -o $@ $<
	$(V)$(OBJDUMP_CMD)
	$(V)$(RM_MDEBUG)

# Add these as a dependency for .o files
asset_files: $(ASSET_INC_C)
$(O_FILES): | asset_files
.PHONY: asset_files

-include $(DEP_FILES)

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
