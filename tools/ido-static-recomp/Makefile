# Build options can be changed by modifying the makefile or by building with 'make SETTING=value'.
# It is also possible to override the settings in Defaults in a file called .make_options as 'SETTING=value'.

-include .make_options

#### Defaults ####

# select the version and binaries of IDO toolchain to recompile
VERSION ?= 7.1
# if WERROR is 1, pass -Werror to CC, so warnings would be treated as errors
WERROR ?= 0
# if RELEASE is 1 strip binaries as well as enable optimizations
RELEASE ?= 0
# On Mac, set this to `universal` to build universal (x86+ARM) binaries
TARGET ?= native
# Set to 1 to build with sanitization enabled
# N.B. cannot be used for `make setup` at the moment due to recomp.cpp not respecting it
ASAN ?= 0

ifeq ($(VERSION),7.1)
  IDO_VERSION := IDO71
# copt currently does not build
  IDO_TC      := cc acpp as0 as1 cfe ugen ujoin uld umerge uopt usplit upas edgcpfe NCC
  IDO_LIBS    :=
else ifeq ($(VERSION),5.3)
  IDO_VERSION := IDO53
  IDO_TC      := cc strip acpp as0 as1 cfe copt ugen ujoin uld umerge uopt usplit ld upas c++filt
  IDO_LIBS    := crt1.o crtn.o libc.so libc.so.1 libexc.so libgen.so libm.so
else
$(error Unknown or unsupported IDO version - $(VERSION))
endif


# -- determine the host environment and target
# | Host  | Targets           |
# |-------|-------------------|
# | macOS | native, universal |
# | linux | native            |
# | win   | native            |

UNAME_S := $(shell uname -s)
UNAME_P := $(shell uname -p)

MAKE   := make
ifeq ($(OS),Windows_NT)
  DETECTED_OS := windows
else ifeq ($(UNAME_S),Linux)
  DETECTED_OS := linux
else ifeq ($(UNAME_S),Darwin)
  DETECTED_OS := macos
  MAKE := gmake
  CPPFLAGS += -xc++
else ifeq ($(UNAME_S),FreeBSD)
  DETECTED_OS := freebsd
  MAKE := gmake
else
  $(error Unsupported host OS for Makefile)
endif

# check if in a git repository
ifeq ($(shell git rev-parse --is-inside-work-tree >/dev/null 2>/dev/null; echo $$?),0)
  PACKAGE_VERSION := $(shell LC_ALL=C git --git-dir .git describe --tags --always --dirty)
endif

# Get the current date and time in ISO 8601 format
DATETIME := $(shell date +'%F %T UTC%z')

$(info Package version $(PACKAGE_VERSION))
$(info Build date $(DATETIME))


RABBITIZER := tools/rabbitizer
RABBITIZER_LIB := $(RABBITIZER)/build/librabbitizerpp.a

CC    := gcc
CXX   := g++
STRIP := strip

CSTD         ?= -std=c11
CFLAGS       ?= -MMD -fno-strict-aliasing -I.
CXXSTD       ?= -std=c++17
CXXFLAGS     ?= -MMD
WARNINGS     ?= -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS      ?= -lm
RECOMP_FLAGS ?=

ifneq ($(WERROR),0)
  WARNINGS += -Werror
endif

ifeq ($(RELEASE),1)
  OPTFLAGS     ?= -Os
  RAB_DEBUG    := 0
else
  OPTFLAGS     ?= -O0 -ggdb3
  STRIP := @:
  RAB_DEBUG    := 1
endif

ifneq ($(ASAN),0)
  CFLAGS      += -fsanitize=address -fsanitize=pointer-compare -fsanitize=pointer-subtract -fsanitize=undefined -fno-sanitize-recover=all
  CXXFLAGS    += -fsanitize=address -fsanitize=pointer-compare -fsanitize=pointer-subtract -fsanitize=undefined -fno-sanitize-recover=all
endif

ifeq ($(DETECTED_OS),freebsd)
  LDFLAGS     += -lexecinfo
endif

ifeq ($(DETECTED_OS),windows)
  CXXFLAGS     += -static
endif

# -- Build Directories
# designed to work with Make 3.81 (macOS/last GPL-2 version)
# https://ismail.badawi.io/blog/automatic-directory-creation-in-make/
BUILD_BASE ?= build
BUILD_DIR  := $(BUILD_BASE)/$(VERSION)
BUILT_BIN  := $(BUILD_DIR)/out


# -- Location of original IDO binaries
IRIX_BASE    ?= ido
IRIX_USR_DIR ?= $(IRIX_BASE)/$(VERSION)/usr

# -- IRIX toolchain error messages and libraries for linking
RUNTIME_DEPS    := $(BUILT_BIN)/err.english.cc $(foreach lib,$(IDO_LIBS),$(BUILT_BIN)/$(lib))

RECOMP_ELF      := $(BUILD_BASE)/recomp.elf

TARGET_BINARIES := $(foreach binary,$(IDO_TC),$(BUILT_BIN)/$(binary))

# create build directories
$(shell mkdir -p $(BUILT_BIN))

# per-file flags
# 5.3 ugen relies on UB stack reads
# to emulate, pass the conservative flag to `recomp`
$(BUILD_BASE)/5.3/ugen.c: RECOMP_FLAGS := --conservative

$(RECOMP_ELF): CXXFLAGS  += -I$(RABBITIZER)/include -I$(RABBITIZER)/cplusplus/include
$(RECOMP_ELF): LDFLAGS   += -L$(RABBITIZER)/build -lrabbitizerpp

ifneq ($(DETECTED_OS),windows)
# For traceback
$(RECOMP_ELF): LDFLAGS   += -ldl
endif
ifeq ($(DETECTED_OS),linux)
# For traceback
$(RECOMP_ELF): LDFLAGS   += -Wl,-export-dynamic
endif

LIBC_WARNINGS := $(WARNINGS) -Wno-unused-parameter -Wno-deprecated-declarations

LIBC_IMPLS    := libc_impl_53 libc_impl_71
LIBC_IMPL     := libc_impl_$(subst .,,$(VERSION))

%/libc_impl_53.o: CFLAGS += -DIDO53
%/libc_impl_71.o: CFLAGS += -DIDO71

# edgcpfe 7.1 uses libc 5.3
%/7.1/out/edgcpfe:: LIBC_IMPL := libc_impl_53

#### Main Targets ###

all: $(TARGET_BINARIES) $(RUNTIME_DEPS)

# Build the recompiler binary on a separate step.
# Currently this is needed to avoid Windows and Linux ARM CIs from dying.
setup:
	$(MAKE) -C $(RABBITIZER) static CC=$(CC) CXX=$(CXX) DEBUG=$(RAB_DEBUG)
	$(MAKE) $(RECOMP_ELF)

clean:
	$(RM) -r $(BUILD_DIR)

distclean:
	$(RM) -r $(BUILD_BASE)
	$(MAKE) -C $(RABBITIZER) distclean

# Build only the C files (dependencies set below)
c_files:

.PHONY: all setup clean distclean c_files
.DEFAULT_GOAL := all
# Prevent removing intermediate files
.SECONDARY:


#### Various Recipes ####

$(BUILD_BASE)/%.elf: %.cpp
	$(CXX) $(CXXSTD) $(OPTFLAGS) $(CXXFLAGS) $(WARNINGS) -o $@ $^ $(LDFLAGS)


# Set the recompiler binary as a dependency of every generated `.c` file to
# allow quick iterations when developing new features and fixes.

$(BUILD_DIR)/%.c: $(IRIX_USR_DIR)/lib/% $(RECOMP_ELF)
	$(RECOMP_ELF) $(RECOMP_FLAGS) $< > $@ || ($(RM) -f $@ && false)

# cc and strip are special and are stored in the `bin` folder instead of the `lib` one
$(BUILD_DIR)/%.c: $(IRIX_USR_DIR)/bin/% $(RECOMP_ELF)
	$(RECOMP_ELF) $(RECOMP_FLAGS) $< > $@ || ($(RM) -f $@ && false)

# IDO c++ files are in a different subfolder (`lib/DCC` and `lib/c++`)
$(BUILD_DIR)/%.c: $(IRIX_USR_DIR)/lib/DCC/% $(RECOMP_ELF)
	$(RECOMP_ELF) $(RECOMP_FLAGS) $< > $@ || ($(RM) -f $@ && false)

# IDO c++ files are in a different subfolder (`lib/DCC` and `lib/c++`)
$(BUILD_DIR)/%.c: $(IRIX_USR_DIR)/lib/c++/% $(RECOMP_ELF)
	$(RECOMP_ELF) $(RECOMP_FLAGS) $< > $@ || ($(RM) -f $@ && false)


$(BUILT_BIN)/%.cc: $(IRIX_USR_DIR)/lib/%.cc
	cp $^ $@

$(BUILT_BIN)/%.o: $(IRIX_USR_DIR)/lib/%.o
	cp $^ $@

$(BUILT_BIN)/%.so: $(IRIX_USR_DIR)/lib/%.so
	cp $^ $@

$(BUILT_BIN)/%.so.1: $(IRIX_USR_DIR)/lib/%.so.1
	cp $^ $@


# NCC 7.1 is just a renamed cc
$(BUILD_BASE)/7.1/out/NCC: $(BUILD_BASE)/7.1/out/cc
	cp $^ $@


# Template to compile libc_impl and output binaries
# $(1): target name (or "default" if it's the only target)
# $(2): target flags
define compile_template

ifeq ($(1),default)
  TARGET_DIR-$(1)      := $(BUILD_DIR)
else
  TARGET_DIR-$(1)      := $(BUILD_DIR)/$(1)
endif

TARGET_BIN-$(1)        := $$(TARGET_DIR-$(1))/out
TARGET_FLAGS-$(1)      := $(2)

# NCC is filtered out since it isn't an actual program, but a symlink to cc
LIBC_IMPL_O_FILES-$(1) := $(foreach libc_impl,$(LIBC_IMPLS),$$(TARGET_DIR-$(1))/$(libc_impl).o)
PROGRAM_O_FILES-$(1)   := $(foreach binary,$(filter-out NCC,$(IDO_TC)),$$(TARGET_DIR-$(1))/$(binary).o)
PROGRAM_C_FILES-$(1)   := $$(PROGRAM_O_FILES-$(1):.o=.c)
O_FILES-$(1)           := $$(LIBC_IMPL_O_FILES-$(1)) $$(PROGRAM_O_FILES-$(1))

# create build directories
$$(shell mkdir -p $$(TARGET_BIN-$(1)))

c_files: $$(PROGRAM_C_FILES-$(1))

$$(TARGET_BIN-$(1))/%: $$(TARGET_DIR-$(1))/%.o $$(TARGET_DIR-$(1))/version_info.o $$(LIBC_IMPL_O_FILES-$(1)) | $$(RUNTIME_DEPS)
	$$(CC) $$(CSTD) $$(OPTFLAGS) $$(CFLAGS) $$(TARGET_FLAGS-$(1)) -o $$@ $$< $$(TARGET_DIR-$(1))/version_info.o $$(TARGET_DIR-$(1))/$$(LIBC_IMPL).o $$(LDFLAGS)
	$$(STRIP) $$@

$$(TARGET_DIR-$(1))/%.o: $$(BUILD_DIR)/%.c
	$$(CC) -c $$(CSTD) $$(OPTFLAGS) $$(CFLAGS) $$(TARGET_FLAGS-$(1)) -o $$@ $$<

$$(TARGET_DIR-$(1))/libc_impl_%.o: libc_impl.c
	$$(CC) -c $$(CSTD) $$(OPTFLAGS) $$(CFLAGS) $$(LIBC_WARNINGS) $$(TARGET_FLAGS-$(1)) -o $$@ $$<

# Rebuild version info if the recomp binary or libc_impl are updated
$$(TARGET_DIR-$(1))/version_info.o: version_info.c $$(RECOMP_ELF) $$(LIBC_IMPL_O_FILES-$(1))
	$$(CC) -c $$(CSTD) $$(OPTFLAGS) $$(CFLAGS) -D$$(IDO_VERSION) -DPACKAGE_VERSION="\"$$(PACKAGE_VERSION)\"" -DDATETIME="\"$$(DATETIME)\"" $$(TARGET_FLAGS-$(1)) -o $$@ $$<

# Automatic dependency files
-include $$(O_FILES-$(1):.o=.d)

endef


ifeq ($(TARGET),universal)
# Build universal binaries on macOS
$(eval $(call compile_template,arm64-apple-macos11,-target arm64-apple-macos11))
$(eval $(call compile_template,x86_64-apple-macos10.14,-target x86_64-apple-macos10.14))

$(BUILT_BIN)/%: $(BUILD_DIR)/arm64-apple-macos11/out/% $(BUILD_DIR)/x86_64-apple-macos10.14/out/%
	lipo -create -output $@ $^
else
# Normal build
$(eval $(call compile_template,default,))
endif


# Remove built-in rules
MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

# --- Debugging
# run `make print-VARIABLE` to debug that variable
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
