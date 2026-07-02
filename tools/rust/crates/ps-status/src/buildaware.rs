//! Build-aware mode: per-folder byte sizes and match percentages derived from
//! the linker `.map`, a direct port of the algorithm in `progress.py`.
//!
//! For each `.text` symbol the map lists, the function is considered
//! *undecomped* when either the whole-file asm (`asm/<v>/<file>.s`) or the
//! per-function asm (`asm/<v>/nonmatchings/<file>/<func>.s`) still exists on
//! disk; otherwise it is *decomped*. Sizes come from the map.

use std::collections::BTreeMap;
use std::path::{Path, PathBuf};

use anyhow::Result;
use ps_core::mapfile::MapFile;

#[derive(Default, Clone)]
struct Stats {
    decomped: u64,
    undecomped: u64,
}

impl Stats {
    fn total(&self) -> u64 {
        self.decomped + self.undecomped
    }
    fn percent(&self) -> f64 {
        let t = self.total();
        if t == 0 {
            0.0
        } else {
            self.decomped as f64 / t as f64 * 100.0
        }
    }
}

pub fn run(root: &Path, version: &str, map_path: &Path, json: bool) -> Result<()> {
    let mf = MapFile::read(map_path)?;
    let asm_path = root.join("asm").join(version);
    let nonmatchings = asm_path.join("nonmatchings");

    let mut total = Stats::default();
    let mut per_folder: BTreeMap<String, Stats> = BTreeMap::new();

    for sym in mf.text_symbols() {
        // progress.py removes the version component from the path, then uses
        // parts[2] as the folder and parts[2:] as the file path.
        let parts: Vec<String> = sym
            .filepath
            .components()
            .map(|c| c.as_os_str().to_string_lossy().into_owned())
            .filter(|p| p != version)
            .collect();
        if parts.len() <= 2 {
            continue;
        }

        let mut folder = parts[2].clone();
        if folder == "fragments" && parts.len() > 3 {
            folder = format!("fragments/{}", parts[3]);
        }
        if let Some(idx) = folder.find(".a") {
            folder = folder[..idx].to_string();
        }
        if folder == "ultralib" {
            folder = "libultra".to_string();
        }

        // originalFilePath = parts[2:], with every suffix stripped.
        let mut file_path = PathBuf::new();
        for p in &parts[2..] {
            file_path.push(p);
        }
        let extensionless = strip_all_suffixes(&file_path);

        let whole_file_asm = asm_path.join(&extensionless).with_extension("s");
        let whole_undecomped = whole_file_asm.exists();
        let func_asm = nonmatchings
            .join(&extensionless)
            .join(format!("{}.s", sym.name));

        let entry = per_folder.entry(folder).or_default();
        if whole_undecomped || func_asm.exists() {
            total.undecomped += sym.size;
            entry.undecomped += sym.size;
        } else {
            total.decomped += sym.size;
            entry.decomped += sym.size;
        }
    }

    if json {
        print_json(&total, &per_folder);
    } else {
        print_table(&total, &per_folder);
    }
    Ok(())
}

/// Repeatedly drop the file extension (`a.b.o` -> `a`).
fn strip_all_suffixes(path: &Path) -> PathBuf {
    let mut p = path.to_path_buf();
    while p.extension().is_some() {
        p.set_extension("");
    }
    p
}

fn print_table(total: &Stats, per_folder: &BTreeMap<String, Stats>) {
    // Priority: most undecomped bytes first.
    let mut rows: Vec<(&String, &Stats)> = per_folder.iter().collect();
    rows.sort_by(|a, b| {
        b.1.undecomped
            .cmp(&a.1.undecomped)
            .then_with(|| a.0.cmp(b.0))
    });

    println!("Progress by folder (build-aware, bytes):");
    println!(
        "  {:<24} {:>10} {:>10} {:>10} {:>8}",
        "folder", "decomp", "undecomp", "total", "%"
    );
    for (folder, s) in rows {
        println!(
            "  {:<24} {:>10} {:>10} {:>10} {:>7.2}%",
            folder,
            s.decomped,
            s.undecomped,
            s.total(),
            s.percent()
        );
    }
    println!();
    println!(
        "TOTAL: {} / {} bytes decompiled ({:.4}%)",
        total.decomped,
        total.total(),
        total.percent()
    );
}

fn print_json(total: &Stats, per_folder: &BTreeMap<String, Stats>) {
    use serde::Serialize;

    #[derive(Serialize)]
    struct FolderOut {
        folder: String,
        decomped_bytes: u64,
        undecomped_bytes: u64,
        total_bytes: u64,
        percent: f64,
    }
    #[derive(Serialize)]
    struct Root {
        mode: &'static str,
        decomped_bytes: u64,
        undecomped_bytes: u64,
        total_bytes: u64,
        percent: f64,
        folders: Vec<FolderOut>,
    }

    let mut folders: Vec<FolderOut> = per_folder
        .iter()
        .map(|(folder, s)| FolderOut {
            folder: folder.clone(),
            decomped_bytes: s.decomped,
            undecomped_bytes: s.undecomped,
            total_bytes: s.total(),
            percent: s.percent(),
        })
        .collect();
    folders.sort_by(|a, b| {
        b.undecomped_bytes
            .cmp(&a.undecomped_bytes)
            .then_with(|| a.folder.cmp(&b.folder))
    });

    let root = Root {
        mode: "build-aware",
        decomped_bytes: total.decomped,
        undecomped_bytes: total.undecomped,
        total_bytes: total.total(),
        percent: total.percent(),
        folders,
    };
    println!("{}", serde_json::to_string_pretty(&root).unwrap());
}
