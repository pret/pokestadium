//! Shared parsers and domain models for the Pokémon Stadium (US) matching tools.
//!
//! This crate is intentionally build-free at its core: the [`globalasm`] and
//! [`symbols`] parsers only need files that are committed to the repo (`src/`
//! and `linker_scripts/`). The `mapfile`, `rom` and `disasm` modules (added in
//! later phases) support the build-aware workflows (progress by bytes,
//! first-diff and per-function diff), which require `make` artifacts.

pub mod disasm;
pub mod globalasm;
pub mod mapfile;
pub mod rom;
pub mod symbols;

/// Default game version handled by these tools.
pub const DEFAULT_VERSION: &str = "us";

/// Restore the default `SIGPIPE` behaviour so these CLIs terminate silently when
/// their output is closed early (e.g. piped into `head`), like standard Unix
/// tools, instead of panicking on a broken pipe. Call once at the start of
/// `main`.
pub fn reset_sigpipe() {
    // Safety: setting a signal disposition to the default handler is sound.
    unsafe {
        libc::signal(libc::SIGPIPE, libc::SIG_DFL);
    }
}
