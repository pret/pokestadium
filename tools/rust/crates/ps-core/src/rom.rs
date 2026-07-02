//! Big-endian `.z64` ROM reader with optional md5 verification.

use std::fs;
use std::path::Path;

use anyhow::{bail, Context, Result};
use md5::{Digest, Md5};

/// A ROM image loaded into memory.
pub struct Rom {
    pub bytes: Vec<u8>,
}

impl Rom {
    pub fn read(path: &Path) -> Result<Rom> {
        let bytes = fs::read(path).with_context(|| format!("reading ROM {}", path.display()))?;
        Ok(Rom { bytes })
    }

    pub fn len(&self) -> usize {
        self.bytes.len()
    }

    pub fn is_empty(&self) -> bool {
        self.bytes.is_empty()
    }

    /// Lowercase hex md5 of the whole ROM.
    pub fn md5_hex(&self) -> String {
        let mut hasher = Md5::new();
        hasher.update(&self.bytes);
        let digest = hasher.finalize();
        digest.iter().map(|b| format!("{b:02x}")).collect()
    }

    /// Read a big-endian 32-bit word at a byte offset.
    pub fn word_be(&self, offset: usize) -> Option<u32> {
        let b = self.bytes.get(offset..offset + 4)?;
        Some(u32::from_be_bytes([b[0], b[1], b[2], b[3]]))
    }
}

/// Verify a ROM against an `md5sum`-style checksum file (`<hash>  <name>`).
///
/// Returns `Ok(())` when the ROM's md5 matches any hash listed in the file.
pub fn verify_against_md5_file(rom: &Rom, checksum_path: &Path) -> Result<()> {
    let text = fs::read_to_string(checksum_path)
        .with_context(|| format!("reading {}", checksum_path.display()))?;
    let actual = rom.md5_hex();
    for line in text.lines() {
        if let Some(expected) = line.split_whitespace().next() {
            if expected.eq_ignore_ascii_case(&actual) {
                return Ok(());
            }
        }
    }
    bail!(
        "md5 mismatch: ROM is {actual}, not listed in {}",
        checksum_path.display()
    );
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn md5_and_word() {
        let rom = Rom {
            bytes: vec![0x80, 0x00, 0x05, 0x30, 0xde, 0xad, 0xbe, 0xef],
        };
        assert_eq!(rom.word_be(0), Some(0x80000530));
        assert_eq!(rom.word_be(4), Some(0xdeadbeef));
        assert_eq!(rom.word_be(6), None);
        // md5 of these 8 bytes
        assert_eq!(rom.md5_hex().len(), 32);
    }
}
