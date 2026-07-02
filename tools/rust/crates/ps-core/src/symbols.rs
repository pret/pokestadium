//! Parser for `linker_scripts/<version>/symbol_addrs*.txt`.
//!
//! Lines look like `name = 0xADDR;` with an optional trailing comment carrying
//! space-separated `key:value` attributes, e.g. `// type:func size:0x40`.

use std::collections::HashMap;
use std::fs;
use std::path::Path;

use anyhow::{Context, Result};
use regex::Regex;

/// A single symbol from a `symbol_addrs` file.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Symbol {
    pub name: String,
    pub addr: u64,
    /// Attributes parsed from the trailing `// key:value ...` comment.
    pub attrs: HashMap<String, String>,
}

impl Symbol {
    /// Returns true when the symbol's `type` attribute is `func`.
    pub fn is_func(&self) -> bool {
        self.attrs.get("type").map(|s| s == "func").unwrap_or(false)
    }
}

/// Parse a single `symbol_addrs` file into a name → [`Symbol`] map.
pub fn parse_file(path: &Path) -> Result<HashMap<String, Symbol>> {
    let text = fs::read_to_string(path).with_context(|| format!("reading {}", path.display()))?;
    Ok(parse_str(&text))
}

/// Parse several `symbol_addrs` files, merging them into one map.
///
/// Later files override earlier ones on name collision. Missing files are
/// skipped silently so callers can pass an optimistic list.
pub fn parse_files(paths: &[&Path]) -> Result<HashMap<String, Symbol>> {
    let mut out = HashMap::new();
    for path in paths {
        if !path.exists() {
            continue;
        }
        out.extend(parse_file(path)?);
    }
    Ok(out)
}

/// Parse the textual contents of a `symbol_addrs` file.
pub fn parse_str(text: &str) -> HashMap<String, Symbol> {
    // name = 0xADDR;  [// comment]
    let re = Regex::new(r"^\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*0x([0-9A-Fa-f]+)\s*;(.*)$")
        .expect("valid regex");
    let mut out = HashMap::new();
    for line in text.lines() {
        if let Some(caps) = re.captures(line) {
            let name = caps[1].to_string();
            let addr = u64::from_str_radix(&caps[2], 16).unwrap_or(0);
            let attrs = parse_attrs(&caps[3]);
            out.insert(name.clone(), Symbol { name, addr, attrs });
        }
    }
    out
}

fn parse_attrs(rest: &str) -> HashMap<String, String> {
    let mut attrs = HashMap::new();
    if let Some(idx) = rest.find("//") {
        for tok in rest[idx + 2..].split_whitespace() {
            if let Some((k, v)) = tok.split_once(':') {
                attrs.insert(k.to_string(), v.to_string());
            }
        }
    }
    attrs
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parses_plain_and_commented() {
        let text = "\
Main = 0x80000530; // type:func
LEOcommand_que = 0x80100638; // allow_duplicated:True
mseq_tbl = 0x80101090;
";
        let map = parse_str(text);
        assert_eq!(map.len(), 3);
        assert_eq!(map["Main"].addr, 0x80000530);
        assert!(map["Main"].is_func());
        assert!(!map["mseq_tbl"].is_func());
        assert_eq!(map["LEOcommand_que"].attrs["allow_duplicated"], "True");
    }
}
