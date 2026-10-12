import tempfile
import unittest
from pathlib import Path

from affected_versions import affected


def tree(**yamls):
    root = Path(tempfile.mkdtemp())
    for v, cs in yamls.items():
        d = root / "yamls" / v
        d.mkdir(parents=True)
        (d / "rom.yaml").write_text("".join(f"    - [0x{i:X}, c, {n}]\n" for i, n in enumerate(cs)))
    return root


class Affected(unittest.TestCase):
    def setUp(self):
        self.root = tree(us=["a", "b"], jp=["a"])

    def test_version_paths_gate_only_that_version(self):
        self.assertEqual(affected(self.root, ["yamls/jp/rom.yaml", "linker_scripts/jp/x.ld"]), ["jp"])

    def test_shared_source_gates_versions_that_build_it(self):
        self.assertEqual(affected(self.root, ["src/a.c"]), ["jp", "us"])
        self.assertEqual(affected(self.root, ["src/b.c"]), ["us"])

    def test_new_source_defaults_to_us(self):
        self.assertEqual(affected(self.root, ["src/new.c"]), ["us"])

    def test_docs_gate_nothing(self):
        self.assertEqual(affected(self.root, ["COVERAGE.md", "docs/regions/x.md"]), [])

    def test_build_system_gates_everything(self):
        self.assertEqual(affected(self.root, ["Makefile"]), ["jp", "us"])
        self.assertEqual(affected(self.root, ["linker_scripts/common_undef_syms.ld"]), ["jp", "us"])

    def test_unstarted_region_path_gates_nothing_buildable(self):
        (self.root / "ci").mkdir()
        (self.root / "ci/regions.json").write_text('{"fr": {}}')
        self.assertEqual(affected(self.root, ["baseroms/fr/checksum.md5"]), [])


if __name__ == "__main__":
    unittest.main()
