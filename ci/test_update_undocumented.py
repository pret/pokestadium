import tempfile
import unittest
from pathlib import Path

import update_undocumented as u


def make_repo(root: Path) -> None:
    sym = root / "linker_scripts/us"
    sym.mkdir(parents=True)
    (sym / "symbol_addrs.txt").write_text(
        "gThing = 0x80000010; // size:0x4\nD_80000020 = 0x80000020; // type:u8\n")
    (sym / "symbol_addrs_code.txt").write_text(
        "Main = 0x80001530; // type:func\n"
        "func_80001600 = 0x80001600; // type:func\n"
        "func_80001700 = 0x80001700; // type:func\n")
    (sym / "symbol_addrs_ultralib.txt").write_text("")
    (root / "src").mkdir()
    (root / "src/a.c").write_text(
        "extern u8 D_80000020; extern u8 D_80000030; extern u8 jtbl_80000040[];\n"
        "/* Does the thing. */\n"
        "void f(void) { func_80001600(); func_80001600(); Main(); }\n"
        "\n"
        "s32 g(s32 a)\n{\n    s32 temp_v0 = a; /* } */\n    return temp_v0;\n}\n"
        "void h(s32 arg0, s32 count)\n{\n    if (1) { }\n    *(s32 *)(base + 0x10) = 1;\n}\n")
    (root / "include").mkdir()
    (root / "include/s.h").write_text(
        "typedef struct Foo {\n    s32 unk_00;\n    u8 pad[3];\n    f32 speed;\n    u16 bits : 4;\n} Foo;\n")


class UndocumentedTest(unittest.TestCase):
    def test_counts(self):
        with tempfile.TemporaryDirectory() as d:
            root = Path(d)
            make_repo(root)
            r = u.Report(root)
            self.assertEqual((r.func_total, r.func_undoc), (3, 2))
            # gThing, D_80000020 from tables; D_80000030, jtbl_80000040 from src only.
            self.assertEqual((r.var_total, r.var_undoc), (4, 3))
            # 3 defs (f documented, g and h not); 1 func_, 3 D_/jtbl_; g uses temp_v0.
            self.assertEqual((r.defs, r.doc, r.local_funcs), (3, 1, 1))
            self.assertEqual(r.by_file["src/a.c"], (3, 1, 1, 3, 1, 1, 1))
            self.assertEqual((r.arg_funcs, r.raw_offsets), (1, 1))
            self.assertEqual(r.structs, [("include/s.h", "Foo", 4, 2)])
            self.assertEqual((r.struct_total, r.structs_generic), (1, 1))

    def test_render_and_check(self):
        with tempfile.TemporaryDirectory() as d:
            root = Path(d)
            make_repo(root)
            text = u.render(u.Report(root))
            self.assertIn("**1 / 3 (33.3%)**", text)
            self.assertIn("| `src/a.c` | 3 | 2 | 1 | 3 | 1 | 1 | 1 |", text)
            self.assertIn("**1 / 3 (33.3%)**", text)

    def test_struct_fields(self):
        got = u.struct_defs("struct { u8 a; struct { s32 unk_4; } in; u8 field_8; };")
        self.assertEqual(got[0][1:], (3, 2))

    def test_placeholder(self):
        self.assertTrue(u.is_placeholder("func_8012ABCD"))
        self.assertFalse(u.is_placeholder("func_8012ABCD_extra"))
        self.assertFalse(u.is_placeholder("gThing"))


if __name__ == "__main__":
    unittest.main()
