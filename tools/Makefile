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

all: $(PROGRAMS) rust

# Build the Rust matching tools (ps-status, ps-firstdiff, ps-fdiff). Skipped
# with a warning when cargo is unavailable so the C-only workflow still works.
rust:
	@if command -v cargo >/dev/null 2>&1; then \
		echo "Building Rust matching tools..."; \
		cargo build --release --manifest-path rust/Cargo.toml; \
	else \
		echo "WARNING: cargo not found; skipping Rust tools (ps-status, ps-firstdiff, ps-fdiff)."; \
		echo "         Install Rust from https://rustup.rs to build them."; \
	fi

clean:
	$(V)rm -Rf $(PROGRAMS) $(BUILD_DIR)
	$(V)command -v cargo >/dev/null 2>&1 && cargo clean --manifest-path rust/Cargo.toml || true

distclean: clean

vtxdis: vtxdis.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY: all clean distclean default rust
