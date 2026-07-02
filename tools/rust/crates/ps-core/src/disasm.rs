//! Thin wrapper over the `rabbitizer` MIPS disassembler.
//!
//! Mirrors the behaviour of `tools/first_diff.py::decodeInstruction`: decode a
//! 32-bit word and, when it is a function call (`jal`) with an embedded address,
//! resolve that address against the map file so the disassembly shows the symbol
//! name instead of a raw value.

use rabbitizer::{InstrCategory, Instruction};

use crate::mapfile::MapFile;

/// Disassemble one instruction word located at `vram`.
///
/// When the instruction is a `jal`/jump-with-address, its target is looked up in
/// `map` and substituted as an immediate override.
pub fn disassemble_word(word: u32, vram: u32, map: &MapFile) -> String {
    let instr = Instruction::new(word, vram, InstrCategory::CPU);

    let mut imm_override: Option<String> = None;
    if instr.is_jump_with_address() {
        let target = instr.instr_index_as_vram() as u64;
        if let Some(sym) = map.symbol_by_vram_or_vrom(target) {
            imm_override = Some(sym.name.clone());
        }
    }

    instr.disassemble(imm_override.as_deref(), -20)
}

/// Disassemble a word without map-based symbol resolution.
pub fn disassemble_word_plain(word: u32, vram: u32) -> String {
    let instr = Instruction::new(word, vram, InstrCategory::CPU);
    instr.disassemble(None, 0)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn decodes_nop() {
        // 0x00000000 is `nop`.
        let s = disassemble_word_plain(0x00000000, 0x80000000);
        assert!(s.contains("nop"), "got: {s}");
    }

    #[test]
    fn decodes_jal_and_resolves_symbol() {
        // jal to 0x80000530 == 0x0C000000 | (0x80000530 >> 2 & 0x3FFFFFF)
        let target = 0x80000530u32;
        let word = 0x0C000000 | ((target >> 2) & 0x03FF_FFFF);
        let mf = crate::mapfile::parse_str(
            "\n .text 0x0000000080000530 0x40 build/src/us/main.o\n                0x0000000080000530                Main\n",
        );
        let s = disassemble_word(word, 0x80001000, &mf);
        assert!(s.contains("jal"), "got: {s}");
        assert!(s.contains("Main"), "expected symbol name, got: {s}");
    }
}
