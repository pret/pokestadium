//! `ps-firstdiff` — find the first difference(s) between the built ROM and the
//! expected ROM, a Rust port of `tools/first_diff.py`.
//!
//! For each differing 4-byte word it reports the ROM offset, the containing
//! function (resolved from the built `.map`), and the disassembly of both the
//! built and expected instruction, with `jal` targets resolved to symbol names.

use std::path::PathBuf;
use std::process::ExitCode;

use anyhow::{bail, Context, Result};
use ps_core::disasm;
use ps_core::mapfile::MapFile;
use ps_core::rom::Rom;
use ps_core::DEFAULT_VERSION;

struct Args {
    version: String,
    root: PathBuf,
    count: usize,
    add_colons: bool,
}

fn parse_args() -> Result<Args> {
    let mut version = DEFAULT_VERSION.to_string();
    let mut root = PathBuf::from(".");
    let mut count = 5usize;
    let mut add_colons = false;

    let mut it = std::env::args().skip(1);
    while let Some(arg) = it.next() {
        match arg.as_str() {
            "-c" | "--count" => {
                count = it
                    .next()
                    .ok_or_else(|| anyhow::anyhow!("--count needs a value"))?
                    .parse()
                    .context("parsing --count")?;
            }
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
            "-a" | "--add-colons" => add_colons = true,
            "-h" | "--help" => {
                println!(
                    "ps-firstdiff — first difference between built and expected ROM\n\n\
USAGE:\n    ps-firstdiff [OPTIONS]\n\n\
OPTIONS:\n\
    -c, --count <N>     Report up to N differing instructions (default: 5)\n\
    -v, --version <VER> Game version (default: us)\n\
    -a, --add-colons    Separate bytes with colons\n\
        --root <DIR>    Repository root (default: .)\n\
    -h, --help          Show this help"
                );
                std::process::exit(0);
            }
            other => bail!("unknown argument: {other}"),
        }
    }
    Ok(Args {
        version,
        root,
        count,
        add_colons,
    })
}

fn main() -> ExitCode {
    ps_core::reset_sigpipe();
    match run() {
        Ok(()) => ExitCode::SUCCESS,
        Err(e) => {
            eprintln!("ps-firstdiff: {e:#}");
            ExitCode::FAILURE
        }
    }
}

fn run() -> Result<()> {
    let args = parse_args()?;
    let rel_rom = PathBuf::from("build").join(format!("pokestadium-{}.z64", args.version));
    let rel_map = PathBuf::from("build").join(format!("pokestadium-{}.map", args.version));
    let built_rom = args.root.join(&rel_rom);
    let built_map = args.root.join(&rel_map);
    let expected_rom = args.root.join("expected").join(&rel_rom);
    let expected_map = args.root.join("expected").join(&rel_map);

    for p in [&built_rom, &built_map, &expected_rom, &expected_map] {
        if !p.exists() {
            bail!(
                "missing {} (run `make` and `make diff-init` first)",
                p.display()
            );
        }
    }

    let built = Rom::read(&built_rom)?;
    let expected = Rom::read(&expected_rom)?;
    let map = MapFile::read(&built_map)?;

    if built.len() != expected.len() {
        println!(
            "ROM size mismatch: built {} bytes, expected {} bytes",
            built.len(),
            expected.len()
        );
    }

    let common = built.len().min(expected.len());
    let mut found = 0usize;
    let mut offset = 0usize;
    while offset + 4 <= common {
        let a = built.word_be(offset).unwrap();
        let b = expected.word_be(offset).unwrap();
        if a != b {
            report_diff(offset as u64, a, b, &map, args.add_colons);
            found += 1;
            if found >= args.count {
                break;
            }
        }
        offset += 4;
    }

    if found == 0 && built.len() == expected.len() {
        println!("No differences found — ROMs match.");
    }
    Ok(())
}

fn report_diff(offset: u64, built_word: u32, expected_word: u32, map: &MapFile, add_colons: bool) {
    // Name the containing function and compute the vram of this word.
    let (loc, vram) = match map.symbol_containing_vrom(offset) {
        Some(sym) => {
            let vrom = sym.vrom.unwrap_or(offset);
            let delta = offset.saturating_sub(vrom);
            let vram = sym.vram + delta;
            (format!("{}+0x{:X}", sym.name, delta), vram as u32)
        }
        None => ("<unknown>".to_string(), 0u32),
    };

    println!("ROM 0x{offset:06X} ({loc}):");
    println!(
        "  built:    {}   {}",
        fmt_word(built_word, add_colons),
        disasm::disassemble_word(built_word, vram, map)
    );
    println!(
        "  expected: {}   {}",
        fmt_word(expected_word, add_colons),
        disasm::disassemble_word(expected_word, vram, map)
    );
}

fn fmt_word(word: u32, add_colons: bool) -> String {
    let b = word.to_be_bytes();
    if add_colons {
        format!("{:02X}:{:02X}:{:02X}:{:02X}", b[0], b[1], b[2], b[3])
    } else {
        format!("{:02X}{:02X}{:02X}{:02X}", b[0], b[1], b[2], b[3])
    }
}
