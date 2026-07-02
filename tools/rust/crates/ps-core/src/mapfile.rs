//! Minimal parser for GNU `ld` map files (`build/pokestadium-<version>.map`).
//!
//! This reimplements only the parts of the Python `mapfile_parser` that the
//! matching tools use: `.text` symbols with their sizes, grouped by object
//! file, plus a vram → containing-symbol lookup used to resolve `jal` targets.
//!
//! Symbol sizes are derived the usual way: within a single section
//! contribution, each symbol's size is the distance to the next symbol, and the
//! last symbol runs to the end of the contribution.

use std::fs;
use std::path::{Path, PathBuf};

use anyhow::{Context, Result};

/// A function/symbol read from the map, with a computed size.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct MapSymbol {
    pub name: String,
    pub vram: u64,
    pub size: u64,
    /// ROM offset (LMA-derived), when the section had a `load address`.
    pub vrom: Option<u64>,
    /// Output section type, e.g. `.text`, `.data`, `.rodata`.
    pub section_type: String,
    /// Object file this symbol was contributed by.
    pub filepath: PathBuf,
}

/// A parsed map file: a flat, address-sorted list of symbols.
#[derive(Debug, Clone, Default)]
pub struct MapFile {
    pub symbols: Vec<MapSymbol>,
}

/// One raw section contribution line: ` .text  0xVRAM  0xSIZE  path.o`.
struct Contribution {
    section_type: String,
    vram: u64,
    size: u64,
    filepath: PathBuf,
    /// Enclosing output section's vram and load address (LMA), when known.
    sec_vram: Option<u64>,
    sec_lma: Option<u64>,
    // (vram, name) for each symbol under this contribution, in file order.
    syms: Vec<(u64, String)>,
}

fn section_type_of(section: &str) -> String {
    // ".text.func" -> ".text"; ".text" -> ".text".
    let mut parts = section.trim_start_matches('.').splitn(2, '.');
    match parts.next() {
        Some(first) if !first.is_empty() => format!(".{first}"),
        _ => section.to_string(),
    }
}

fn parse_hex(tok: &str) -> Option<u64> {
    let t = tok.strip_prefix("0x").or_else(|| tok.strip_prefix("0X"))?;
    u64::from_str_radix(t, 16).ok()
}

/// Parse the textual contents of a GNU ld map file.
pub fn parse_str(text: &str) -> MapFile {
    let mut contributions: Vec<Contribution> = Vec::new();
    // Current output section's vram/lma, taken from a `load address` line. Used
    // to derive each symbol's vrom (ROM offset).
    let mut sec_vram: Option<u64> = None;
    let mut sec_lma: Option<u64> = None;

    for raw in text.lines() {
        if raw.is_empty() {
            continue;
        }
        let line = raw.trim_start();
        if line.starts_with("*fill*") || line.starts_with('*') {
            continue;
        }
        let tokens: Vec<&str> = line.split_whitespace().collect();

        // Output-section header carrying a load address, in either the inline
        // form `.text 0xVRAM 0xSIZE load address 0xLMA` or the wrapped form
        // `0xVRAM 0xSIZE load address 0xLMA`. Resets the current section.
        if let Some(pos) = tokens.iter().position(|t| *t == "address") {
            if pos > 0 && tokens.get(pos - 1) == Some(&"load") {
                let first_hex = tokens.iter().find_map(|t| parse_hex(t));
                let lma = tokens.get(pos + 1).and_then(|t| parse_hex(t));
                sec_vram = first_hex;
                sec_lma = lma;
                continue;
            }
        }

        // A column-0 output-section header without a load address (e.g. `.bss`)
        // resets the section context so stale LMAs don't leak across sections.
        if !raw.starts_with(' ') {
            if tokens.first().map(|t| t.starts_with('.')).unwrap_or(false) {
                sec_vram = None;
                sec_lma = None;
            }
            continue;
        }

        // Contribution: `<section> 0xVRAM 0xSIZE <path>` where <section> starts
        // with '.', the two numbers are hex, and the last token looks like a file.
        if tokens.len() >= 4 && tokens[0].starts_with('.') {
            if let (Some(vram), Some(size)) = (parse_hex(tokens[1]), parse_hex(tokens[2])) {
                let filepath = tokens[tokens.len() - 1];
                if looks_like_object(filepath) {
                    contributions.push(Contribution {
                        section_type: section_type_of(tokens[0]),
                        vram,
                        size,
                        filepath: PathBuf::from(filepath),
                        sec_vram,
                        sec_lma,
                        syms: Vec::new(),
                    });
                    continue;
                }
            }
        }

        // Symbol: `0xVRAM <name>` (exactly two tokens, first is hex).
        if tokens.len() == 2 {
            if let Some(vram) = parse_hex(tokens[0]) {
                let name = tokens[1];
                if is_symbol_name(name) {
                    if let Some(cur) = contributions.last_mut() {
                        cur.syms.push((vram, name.to_string()));
                    }
                }
            }
        }
    }

    MapFile {
        symbols: finalize(contributions),
    }
}

fn looks_like_object(path: &str) -> bool {
    path.ends_with(".o") || path.contains(".a(") || path.ends_with(".a")
}

fn is_symbol_name(name: &str) -> bool {
    let mut chars = name.chars();
    match chars.next() {
        Some(c) if c.is_ascii_alphabetic() || c == '_' || c == '$' => {}
        _ => return false,
    }
    name.chars()
        .all(|c| c.is_ascii_alphanumeric() || c == '_' || c == '$' || c == '.')
}

/// Turn contributions into sized symbols.
fn finalize(contributions: Vec<Contribution>) -> Vec<MapSymbol> {
    let mut out = Vec::new();
    for c in contributions {
        let end = c.vram.saturating_add(c.size);
        for (i, (vram, name)) in c.syms.iter().enumerate() {
            let next = c.syms.get(i + 1).map(|(v, _)| *v).unwrap_or(end);
            let size = next.saturating_sub(*vram);
            // vrom = section_lma + (vram - section_vram), when the section had a
            // load address. Only meaningful for allocated-in-ROM sections.
            let vrom = match (c.sec_vram, c.sec_lma) {
                (Some(sv), Some(lma)) if *vram >= sv => Some(lma + (*vram - sv)),
                _ => None,
            };
            out.push(MapSymbol {
                name: name.clone(),
                vram: *vram,
                size,
                vrom,
                section_type: c.section_type.clone(),
                filepath: c.filepath.clone(),
            });
        }
    }
    out.sort_by_key(|s| s.vram);
    out
}

impl MapFile {
    /// Read and parse a map file from disk.
    pub fn read(path: &Path) -> Result<MapFile> {
        let text =
            fs::read_to_string(path).with_context(|| format!("reading map {}", path.display()))?;
        Ok(parse_str(&text))
    }

    /// Symbols in the `.text` section only.
    pub fn text_symbols(&self) -> impl Iterator<Item = &MapSymbol> {
        self.symbols.iter().filter(|s| s.section_type == ".text")
    }

    /// Find the closest symbol at or before `addr` (the one whose range most
    /// likely contains it). Symbols are sorted by vram.
    pub fn symbol_containing_vram(&self, addr: u64) -> Option<&MapSymbol> {
        let idx = match self.symbols.binary_search_by_key(&addr, |s| s.vram) {
            Ok(i) => i,
            Err(0) => return None,
            Err(i) => i - 1,
        };
        Some(&self.symbols[idx])
    }

    /// Find a symbol by exact vram start.
    pub fn symbol_at_vram(&self, addr: u64) -> Option<&MapSymbol> {
        self.symbols.iter().find(|s| s.vram == addr)
    }

    /// Find a symbol by name.
    pub fn symbol_by_name(&self, name: &str) -> Option<&MapSymbol> {
        self.symbols.iter().find(|s| s.name == name)
    }

    /// Find the `.text` symbol whose `[vrom, vrom+size)` range contains a ROM
    /// byte offset. Used by first-diff to name the function at a diffing offset.
    pub fn symbol_containing_vrom(&self, offset: u64) -> Option<&MapSymbol> {
        self.symbols
            .iter()
            .filter(|s| s.section_type == ".text")
            .filter_map(|s| s.vrom.map(|v| (v, s)))
            .filter(|(v, s)| offset >= *v && offset < v + s.size.max(1))
            .max_by_key(|(v, _)| *v)
            .map(|(_, s)| s)
    }

    /// Resolve a `jal`/jump target the way `first_diff.py` does: match a symbol
    /// by vram first, then by vrom (the Python constructs instructions with a
    /// zero vram, so targets land in the low/vrom range).
    pub fn symbol_by_vram_or_vrom(&self, addr: u64) -> Option<&MapSymbol> {
        self.symbol_at_vram(addr)
            .or_else(|| self.symbols.iter().find(|s| s.vrom == Some(addr)))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    const SAMPLE: &str = "\
Linker script and memory map

.text           0x0000000080000000     0x120 load address 0x0000000000001000
 .text          0x0000000080000000       0x80 build/src/us/main.o
                0x0000000080000000                Main
                0x0000000080000040                func_80000040
 .text          0x0000000080000080       0xa0 build/asm/us/entry.o
                0x0000000080000080                entrypoint
.data           0x0000000080000120       0x10 load address 0x0000000000001120
 .data          0x0000000080000120       0x10 build/src/us/main.o
                0x0000000080000120                some_data
";

    #[test]
    fn parses_sizes_and_sections() {
        let mf = parse_str(SAMPLE);
        let text: Vec<_> = mf.text_symbols().collect();
        assert_eq!(text.len(), 3);

        let main = mf.symbol_at_vram(0x80000000).unwrap();
        assert_eq!(main.name, "Main");
        assert_eq!(main.size, 0x40); // next symbol at +0x40

        let f = mf.symbol_at_vram(0x80000040).unwrap();
        assert_eq!(f.size, 0x40); // runs to end of the 0x80-byte contribution

        let entry = mf.symbol_at_vram(0x80000080).unwrap();
        assert_eq!(entry.size, 0xa0); // whole contribution

        // .data symbol is excluded from text_symbols
        assert!(mf.symbol_at_vram(0x80000120).unwrap().section_type == ".data");
    }

    #[test]
    fn containing_vram_lookup() {
        let mf = parse_str(SAMPLE);
        assert_eq!(mf.symbol_containing_vram(0x80000010).unwrap().name, "Main");
        assert_eq!(
            mf.symbol_containing_vram(0x80000044).unwrap().name,
            "func_80000040"
        );
    }

    #[test]
    fn vrom_from_load_address() {
        let mf = parse_str(SAMPLE);
        // vram 0x80000000 -> lma 0x1000; +0x40 for func_80000040.
        assert_eq!(mf.symbol_at_vram(0x80000000).unwrap().vrom, Some(0x1000));
        assert_eq!(mf.symbol_at_vram(0x80000040).unwrap().vrom, Some(0x1040));
        assert_eq!(mf.symbol_at_vram(0x80000080).unwrap().vrom, Some(0x1080));
        // ROM offset 0x1044 lands inside func_80000040 (0x1040..0x1080).
        assert_eq!(
            mf.symbol_containing_vrom(0x1044).unwrap().name,
            "func_80000040"
        );
    }
}
