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
    /// Whether this directive sits behind a `NON_MATCHING` guard — i.e. it is
    /// compiled *out* of a `make NON_MATCHING=1` build because a C implementation
    /// takes its place. `false` means "bare": the asm is assembled even under
    /// `NON_MATCHING`, so the function has no C body yet.
    pub guarded: bool,
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
        // Preprocessor-conditional stack: for each open `#if*`, whether the
        // current branch is *active* in a `NON_MATCHING` build. A `GLOBAL_ASM`
        // is "bare" (unguarded) when every enclosing frame is active under
        // NON_MATCHING — i.e. it would still be assembled — and "guarded" when
        // any enclosing frame is inactive (a C body replaces it).
        let mut stack: Vec<CondFrame> = Vec::new();
        for line in text.lines() {
            let trimmed = line.trim_start();
            if trimmed.starts_with("//") {
                continue;
            }
            // GLOBAL_ASM arrives as a `#pragma` line, so match it before treating
            // the line as a plain preprocessor directive. Its guard state is the
            // current conditional context.
            if let Some(caps) = re.captures(line) {
                let asm_path = caps[1].to_string();
                if let Some((file_stem, func)) = split_asm_path(&asm_path) {
                    let compiled_when_non_matching = stack.iter().all(|f| f.active_non_matching);
                    out.push(GlobalAsmEntry {
                        c_file: c_file.clone(),
                        file_stem,
                        func,
                        asm_path,
                        guarded: !compiled_when_non_matching,
                    });
                }
                continue;
            }
            if trimmed.starts_with('#') {
                update_cond_stack(trimmed, &mut stack);
            }
        }
    }
    out.sort_by_key(|a| (a.c_file.clone(), a.func.clone()));
    Ok(out)
}

/// One open preprocessor conditional, tracking whether its current branch is
/// compiled when `NON_MATCHING` is defined.
struct CondFrame {
    /// Whether the current branch (`#if`/`#else`) is active under NON_MATCHING.
    active_non_matching: bool,
    /// Whether this conditional is controlled by the `NON_MATCHING` macro. Only
    /// such frames flip meaningfully on `#else`; unrelated `#if`s stay neutral.
    touches_non_matching: bool,
}

/// Apply a preprocessor directive line to the conditional stack.
fn update_cond_stack(directive: &str, stack: &mut Vec<CondFrame>) {
    // Normalize `# ifdef` -> `ifdef`, collapse spaces.
    let body = directive.trim_start_matches('#').trim_start();
    let mut it = body.split_whitespace();
    let Some(kw) = it.next() else { return };
    let rest = body[kw.len()..].trim();

    match kw {
        "ifdef" => {
            // #ifdef NON_MATCHING: the if-branch is active under NON_MATCHING.
            // A non-NON_MATCHING #ifdef is neutral (also active). Either way: true.
            stack.push(CondFrame {
                active_non_matching: true,
                touches_non_matching: rest == "NON_MATCHING",
            });
        }
        "ifndef" => {
            let touches = rest == "NON_MATCHING";
            stack.push(CondFrame {
                // #ifndef NON_MATCHING: the if-branch is inactive under NON_MATCHING.
                active_non_matching: !touches,
                touches_non_matching: touches,
            });
        }
        "if" => {
            // Recognize `defined(NON_MATCHING)` / `!defined(NON_MATCHING)`.
            let compact: String = rest.chars().filter(|c| !c.is_whitespace()).collect();
            let (touches, active) = if compact.contains("!defined(NON_MATCHING)") {
                (true, false)
            } else if compact.contains("defined(NON_MATCHING)") {
                (true, true)
            } else {
                (false, true)
            };
            stack.push(CondFrame {
                active_non_matching: active,
                touches_non_matching: touches,
            });
        }
        "else" => {
            if let Some(f) = stack.last_mut() {
                if f.touches_non_matching {
                    f.active_non_matching = !f.active_non_matching;
                }
            }
        }
        "elif" => {
            // Approximate: an #elif branch of a NON_MATCHING frame is treated as
            // inactive under NON_MATCHING (the #if branch owned the match sense).
            if let Some(f) = stack.last_mut() {
                if f.touches_non_matching {
                    f.active_non_matching = false;
                }
            }
        }
        "endif" => {
            stack.pop();
        }
        _ => {}
    }
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
        // A directive with no NON_MATCHING guard is "bare".
        assert!(!entries[0].guarded);
        fs::remove_dir_all(&dir)?;
        Ok(())
    }

    #[test]
    fn detects_non_matching_guard() -> Result<()> {
        let dir = std::env::temp_dir().join(format!("psga-guard-{}", std::process::id()));
        fs::create_dir_all(&dir)?;
        // `guarded_fn` has a C body under #ifdef NON_MATCHING and asm in #else;
        // `bare_fn` is unconditional.
        fs::write(
            dir.join("f.c"),
            concat!(
                "#ifdef NON_MATCHING\n",
                "void guarded_fn(void) {}\n",
                "#else\n",
                "#pragma GLOBAL_ASM(\"asm/us/nonmatchings/F/guarded_fn.s\")\n",
                "#endif\n",
                "#pragma GLOBAL_ASM(\"asm/us/nonmatchings/F/bare_fn.s\")\n",
                "#ifndef NON_MATCHING\n",
                "#pragma GLOBAL_ASM(\"asm/us/nonmatchings/F/guarded2.s\")\n",
                "#else\n",
                "void guarded2(void) {}\n",
                "#endif\n",
            ),
        )?;
        let entries = scan(&dir)?;
        let g = entries.iter().find(|e| e.func == "guarded_fn").unwrap();
        let b = entries.iter().find(|e| e.func == "bare_fn").unwrap();
        let g2 = entries.iter().find(|e| e.func == "guarded2").unwrap();
        assert!(g.guarded, "asm in #else of #ifdef NON_MATCHING is guarded");
        assert!(!b.guarded, "unconditional asm is bare");
        assert!(g2.guarded, "asm in #ifndef NON_MATCHING branch is guarded");
        fs::remove_dir_all(&dir)?;
        Ok(())
    }
}
