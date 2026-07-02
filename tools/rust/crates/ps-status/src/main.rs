//! `ps-status` — report the status of functions still pending decompilation.
//!
//! Two modes share one binary:
//!
//! * **build-free** (default): enumerate pending functions by scanning
//!   `#pragma GLOBAL_ASM(...)` in `src/`, cross-referencing
//!   `linker_scripts/<version>/symbol_addrs_code.txt` for addresses. Needs no
//!   build.
//! * **build-aware** (when `build/pokestadium-<version>.map` exists, or forced
//!   with `--build-aware`): add per-folder byte sizes and match percentages,
//!   replicating the metric of `progress.py`.

use std::collections::BTreeMap;
use std::path::{Path, PathBuf};
use std::process::ExitCode;

use anyhow::{bail, Result};
use ps_core::{globalasm, symbols, DEFAULT_VERSION};

mod buildaware;

struct Args {
    version: String,
    root: PathBuf,
    json: bool,
    list: bool,
    build_aware: Option<bool>,
}

fn parse_args() -> Result<Args> {
    let mut version = DEFAULT_VERSION.to_string();
    let mut root = PathBuf::from(".");
    let mut json = false;
    let mut list = false;
    let mut build_aware = None;

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
            "--json" => json = true,
            "--list" => list = true,
            "--build-aware" => build_aware = Some(true),
            "--build-free" => build_aware = Some(false),
            "-h" | "--help" => {
                print_help();
                std::process::exit(0);
            }
            other => bail!("unknown argument: {other}"),
        }
    }
    Ok(Args {
        version,
        root,
        json,
        list,
        build_aware,
    })
}

fn print_help() {
    println!(
        "ps-status — status of functions pending decompilation\n\n\
USAGE:\n    ps-status [OPTIONS]\n\n\
OPTIONS:\n\
    -v, --version <VER>   Game version (default: us)\n\
        --root <DIR>      Repository root (default: .)\n\
        --build-aware     Force build-aware mode (requires build/*.map)\n\
        --build-free      Force build-free mode\n\
        --list            List every pending function with its address\n\
        --json            Emit JSON instead of a table\n\
    -h, --help            Show this help"
    );
}

fn main() -> ExitCode {
    ps_core::reset_sigpipe();
    match run() {
        Ok(()) => ExitCode::SUCCESS,
        Err(e) => {
            eprintln!("ps-status: {e:#}");
            ExitCode::FAILURE
        }
    }
}

fn run() -> Result<()> {
    let args = parse_args()?;
    let map_path = args
        .root
        .join("build")
        .join(format!("pokestadium-{}.map", args.version));

    let want_build_aware = match args.build_aware {
        Some(v) => v,
        None => map_path.exists(),
    };

    if want_build_aware {
        if !map_path.exists() {
            bail!(
                "build-aware mode requested but {} does not exist (run `make` and `make diff-init` first)",
                map_path.display()
            );
        }
        buildaware::run(&args.root, &args.version, &map_path, args.json)
    } else {
        run_build_free(&args, &map_path)
    }
}

fn run_build_free(args: &Args, map_path: &Path) -> Result<()> {
    let src_root = args.root.join("src");
    let entries = globalasm::scan(&src_root)?;

    let sym_path = args
        .root
        .join("linker_scripts")
        .join(&args.version)
        .join("symbol_addrs_code.txt");
    let syms = symbols::parse_files(&[sym_path.as_path()])?;

    // Group by file_stem, preserving deterministic order.
    let mut by_file: BTreeMap<String, Vec<(String, Option<u64>)>> = BTreeMap::new();
    for e in &entries {
        let addr = syms.get(&e.func).map(|s| s.addr);
        by_file
            .entry(e.file_stem.clone())
            .or_default()
            .push((e.func.clone(), addr));
    }

    let total = entries.len();
    let file_count = by_file.len();

    if args.json {
        print_build_free_json(total, &by_file);
        return Ok(());
    }

    println!("Pending functions (build-free): {total} across {file_count} files");
    if !map_path.exists() {
        println!("(no build/*.map found — run with `--build-aware` after `make` for byte metrics)");
    }
    println!();

    // Per-file table, most functions first (ties broken by name for determinism).
    let mut rows: Vec<(&String, usize)> = by_file.iter().map(|(k, v)| (k, v.len())).collect();
    rows.sort_by(|a, b| b.1.cmp(&a.1).then_with(|| a.0.cmp(b.0)));

    println!("By file (most functions first):");
    for (file, n) in &rows {
        println!("  {file:<20} {n:>4}");
    }
    println!();
    println!("Total pending functions: {total}");

    if args.list {
        println!();
        println!("Functions:");
        for (file, funcs) in &by_file {
            for (func, addr) in funcs {
                match addr {
                    Some(a) => println!("  {file:<16} {func:<32} 0x{a:08X}"),
                    None => println!("  {file:<16} {func:<32} (no address)"),
                }
            }
        }
    }

    Ok(())
}

fn print_build_free_json(total: usize, by_file: &BTreeMap<String, Vec<(String, Option<u64>)>>) {
    use serde::Serialize;

    #[derive(Serialize)]
    struct FuncOut {
        func: String,
        address: Option<String>,
    }
    #[derive(Serialize)]
    struct FileOut {
        file: String,
        pending: usize,
        functions: Vec<FuncOut>,
    }
    #[derive(Serialize)]
    struct Root {
        mode: &'static str,
        total_pending: usize,
        files: Vec<FileOut>,
    }

    let mut files: Vec<FileOut> = by_file
        .iter()
        .map(|(file, funcs)| FileOut {
            file: file.clone(),
            pending: funcs.len(),
            functions: funcs
                .iter()
                .map(|(func, addr)| FuncOut {
                    func: func.clone(),
                    address: addr.map(|a| format!("0x{a:08X}")),
                })
                .collect(),
        })
        .collect();
    files.sort_by(|a, b| b.pending.cmp(&a.pending).then_with(|| a.file.cmp(&b.file)));

    let root = Root {
        mode: "build-free",
        total_pending: total,
        files,
    };
    println!("{}", serde_json::to_string_pretty(&root).unwrap());
}
