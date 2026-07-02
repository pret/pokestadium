//! Parser for `#pragma GLOBAL_ASM(...)` directives in `src/**/*.c`.
//!
//! Each directive references a non-matching assembly file of the form
//! `asm/<version>/nonmatchings/<file_stem>/<func>.s`, which is the build-free
//! source of truth for the functions still pending decompilation.

use std::fs;
use std::path::{Path, PathBuf};

use anyhow::{Context, Result};
use regex::Regex;

/// A single `GLOBAL_ASM` reference: a function still included as raw assembly.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct GlobalAsmEntry {
    /// The C source file that contains the directive.
    pub c_file: PathBuf,
    /// The `<file_stem>` component of the asm path (e.g. `30640`, `2D340`).
    pub file_stem: String,
    /// The function name (asm file name without extension).
    pub func: String,
    /// The raw asm path as written in the directive.
    pub asm_path: String,
}

/// Scan a source root recursively for every `GLOBAL_ASM` directive.
///
/// Results are sorted by `(c_file, func)` for deterministic output.
pub fn scan(src_root: &Path) -> Result<Vec<GlobalAsmEntry>> {
    let re = Regex::new(r#"GLOBAL_ASM\("([^"]+)"\)"#).expect("valid regex");
    let mut c_files = Vec::new();
    collect_c_files(src_root, &mut c_files)
        .with_context(|| format!("scanning {} for .c files", src_root.display()))?;
    c_files.sort();

    let mut out = Vec::new();
    for c_file in c_files {
        let text =
            fs::read_to_string(&c_file).with_context(|| format!("reading {}", c_file.display()))?;
        for line in text.lines() {
            // Skip lines that are commented out (leading `//`).
            let trimmed = line.trim_start();
            if trimmed.starts_with("//") {
                continue;
            }
            if let Some(caps) = re.captures(line) {
                let asm_path = caps[1].to_string();
                if let Some((file_stem, func)) = split_asm_path(&asm_path) {
                    out.push(GlobalAsmEntry {
                        c_file: c_file.clone(),
                        file_stem,
                        func,
                        asm_path,
                    });
                }
            }
        }
    }
    out.sort_by_key(|a| (a.c_file.clone(), a.func.clone()));
    Ok(out)
}

/// Derive `(file_stem, func)` from an asm path.
///
/// Handles both `asm/us/nonmatchings/<stem>/<func>.s` and any path that ends in
/// `.../<stem>/<func>.s` by taking the last two path components.
fn split_asm_path(asm_path: &str) -> Option<(String, String)> {
    let path = Path::new(asm_path);
    let func = path.file_stem()?.to_str()?.to_string();
    let stem = path.parent()?.file_name()?.to_str()?.to_string();
    Some((stem, func))
}

fn collect_c_files(dir: &Path, out: &mut Vec<PathBuf>) -> Result<()> {
    for entry in fs::read_dir(dir)? {
        let entry = entry?;
        let path = entry.path();
        if path.is_dir() {
            collect_c_files(&path, out)?;
        } else if path.extension().and_then(|e| e.to_str()) == Some("c") {
            out.push(path);
        }
    }
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn splits_standard_path() {
        let (stem, func) = split_asm_path("asm/us/nonmatchings/30640/func_80030010.s").unwrap();
        assert_eq!(stem, "30640");
        assert_eq!(func, "func_80030010");
    }

    #[test]
    fn scans_directory() -> Result<()> {
        let dir = std::env::temp_dir().join(format!("psga-test-{}", std::process::id()));
        let sub = dir.join("sub");
        fs::create_dir_all(&sub)?;
        fs::write(
            sub.join("a.c"),
            "int x;\n#pragma GLOBAL_ASM(\"asm/us/nonmatchings/AAAA/func_1.s\")\n// #pragma GLOBAL_ASM(\"asm/us/nonmatchings/AAAA/commented.s\")\n",
        )?;
        let entries = scan(&dir)?;
        assert_eq!(entries.len(), 1);
        assert_eq!(entries[0].file_stem, "AAAA");
        assert_eq!(entries[0].func, "func_1");
        fs::remove_dir_all(&dir)?;
        Ok(())
    }
}
