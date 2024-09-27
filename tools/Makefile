CC := gcc
CXX := g++
CFLAGS := -I . -Wall -Wextra -Wno-unused-parameter -pedantic -std=c99 -O2 -s
CXXFLAGS := -I . -Wall -Wextra -std=c++17
LDFLAGS := -lm
PROGRAMS := vtxdis

ifeq ($(VERBOSE),0)
  V := @
endif

default: all

n64crc_SOURCES := vtxdis.c

all: $(PROGRAMS)

clean:
	$(V)rm -Rf $(PROGRAMS) $(BUILD_DIR)

distclean: clean

vtxdis: vtxdis.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY: all clean distclean default
