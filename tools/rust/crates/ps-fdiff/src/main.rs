//! `ps-fdiff` — non-interactive per-function assembly diff.
//!
//! Rust equivalent of the non-interactive `./diff.py -mwo <func>` flow: locate a
//! function in the built `.map`, read its bytes from both the built ROM (`myimg`)
//! and the baserom (`baseimg`), disassemble each, and show a side-by-side diff
//! with differing lines highlighted.
//!
//! Scope (v1): word-by-word alignment (correct when both sides have the same
//! length, the common case while iterating toward a match). The interactive TUI,
//! scoring and insertion/deletion alignment of `diff.py` are out of scope.

use std::io::IsTerminal;
use std::path::PathBuf;
use std::process::ExitCode;

use anyhow::{bail, Context, Result};
use ps_core::disasm;
use ps_core::mapfile::MapFile;
use ps_core::rom::Rom;
use ps_core::DEFAULT_VERSION;

const RED: &str = "\x1b[31m";
const GREEN: &str = "\x1b[32m";
const RESET: &str = "\x1b[0m";

enum ColorMode {
    Auto,
    Always,
    Never,
}

struct Args {
    func: String,
    version: String,
    root: PathBuf,
    color: ColorMode,
}

fn parse_args() -> Result<Args> {
    let mut func: Option<String> = None;
    let mut version = DEFAULT_VERSION.to_string();
    let mut root = PathBuf::from(".");
    let mut color = ColorMode::Auto;

    let mut it = std::env::args().skip(1);
    while let Some(arg) = it.next() {
        match arg.as_str() {
            "-v" | "--version" => {
                version = it
                    .next()
                    .ok_or_else(|| anyhow::anyhow!("--version needs a value"))?;
            }
            "--root" => {
                root = PathBuf::from(
                    it.next()
                        .ok_or_else(|| anyhow::anyhow!("--root needs a value"))?,
                );
            }
            "--color" => {
                color = match it.next().as_deref() {
                    Some("always") => ColorMode::Always,
                    Some("never") => ColorMode::Never,
                    Some("auto") | None => ColorMode::Auto,
                    Some(o) => bail!("invalid --color value: {o}"),
                };
            }
            "-h" | "--help" => {
                println!(
                    "ps-fdiff — per-function asm diff (built ROM vs baserom)\n\n\
USAGE:\n    ps-fdiff [OPTIONS] <FUNCTION>\n\n\
OPTIONS:\n\
    -v, --version <VER>   Game version (default: us)\n\
        --root <DIR>      Repository root (default: .)\n\
        --color <WHEN>    always | never | auto (default: auto)\n\
    -h, --help            Show this help"
                );
                std::process::exit(0);
            }
            other if !other.starts_with('-') => func = Some(other.to_string()),
            other => bail!("unknown argument: {other}"),
        }
    }

    let func = func.ok_or_else(|| anyhow::anyhow!("a function name is required (see --help)"))?;
    Ok(Args {
        func,
        version,
        root,
        color,
    })
}

fn main() -> ExitCode {
    ps_core::reset_sigpipe();
    match run() {
        Ok(true) => ExitCode::SUCCESS,
        Ok(false) => ExitCode::from(1), // functions differ
        Err(e) => {
            eprintln!("ps-fdiff: {e:#}");
            ExitCode::from(2) // trouble (function not found, missing files, ...)
        }
    }
}

/// Returns Ok(true) when the function matches, Ok(false) when it differs.
fn run() -> Result<bool> {
    let args = parse_args()?;
    let build = args.root.join("build");
    let myimg = build.join(format!("pokestadium-{}.z64", args.version));
    let map_path = build.join(format!("pokestadium-{}.map", args.version));
    let baseimg = args
        .root
        .join("baseroms")
        .join(&args.version)
        .join("baserom.z64");

    for p in [&myimg, &map_path, &baseimg] {
        if !p.exists() {
            bail!("missing {} (run `make` first)", p.display());
        }
    }

    let map = MapFile::read(&map_path)?;
    let sym = map
        .symbol_by_name(&args.func)
        .with_context(|| format!("function {} not found in {}", args.func, map_path.display()))?;
    let vrom = sym
        .vrom
        .ok_or_else(|| anyhow::anyhow!("no ROM offset (vrom) for {} in the map", args.func))?;
    let size = sym.size;
    if size == 0 {
        bail!("function {} has zero size in the map", args.func);
    }

    let my = Rom::read(&myimg)?;
    let base = Rom::read(&baseimg)?;

    let use_color = match args.color {
        ColorMode::Always => true,
        ColorMode::Never => false,
        ColorMode::Auto => std::io::stdout().is_terminal(),
    };

    println!(
        "{} @ vram 0x{:08X}, rom 0x{:X}, size 0x{:X}",
        sym.name, sym.vram, vrom, size
    );
    println!("{:<44}CURRENT (build)", "TARGET (baserom)");

    let words = (size / 4) as usize;
    let mut all_match = true;
    for i in 0..words {
        let off = vrom as usize + i * 4;
        let vram = (sym.vram + (i as u64) * 4) as u32;
        let base_word = base.word_be(off);
        let my_word = my.word_be(off);
        let base_txt = base_word
            .map(|w| disasm::disassemble_word(w, vram, &map))
            .unwrap_or_else(|| "<eof>".to_string());
        let my_txt = my_word
            .map(|w| disasm::disassemble_word(w, vram, &map))
            .unwrap_or_else(|| "<eof>".to_string());
        let differ = base_word != my_word;
        if differ {
            all_match = false;
        }
        print_row(vram, &base_txt, &my_txt, differ, use_color);
    }

    println!();
    if all_match {
        println!("MATCH: {} is byte-identical.", sym.name);
    } else {
        println!("DIFF: {} does not match.", sym.name);
    }
    Ok(all_match)
}

fn print_row(vram: u32, base: &str, cur: &str, differ: bool, color: bool) {
    let marker = if differ { "|" } else { " " };
    let left = format!("{base:<40}");
    if color && differ {
        println!("0x{vram:08X}  {RED}{left}{RESET} {marker} {GREEN}{cur}{RESET}");
    } else {
        println!("0x{vram:08X}  {left} {marker} {cur}");
    }
}
