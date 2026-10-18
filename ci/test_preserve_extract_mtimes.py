import os
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

SCRIPT = Path(__file__).with_name("preserve_extract_mtimes.py")
OLD_TIME = 1_000_000_000


def write(root, rel, text, mtime=None):
    path = Path(root) / rel
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)
    if mtime is not None:
        os.utime(path, (mtime, mtime))
    return path


class PreserveExtractMtimesTest(unittest.TestCase):
    def run_script(self, old, root, version="us", paths=("asm/us", "assets/us")):
        return subprocess.run(
            [sys.executable, str(SCRIPT), "--old", old, "--root", root,
             "--version", version, *paths],
            capture_output=True, text=True,
        )

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.old = os.path.join(self.tmp.name, "old")
        self.root = os.path.join(self.tmp.name, "root")

    def tearDown(self):
        self.tmp.cleanup()

    def test_identical_file_keeps_old_mtime_and_changed_file_does_not(self):
        write(self.old, "asm/us/a.s", "same", OLD_TIME)
        write(self.old, "asm/us/b.s", "before", OLD_TIME)
        a = write(self.root, "asm/us/a.s", "same")
        b = write(self.root, "asm/us/b.s", "after")
        result = self.run_script(self.old, self.root)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(int(a.stat().st_mtime), OLD_TIME)
        self.assertGreater(int(b.stat().st_mtime), OLD_TIME)

    def test_new_file_is_left_alone(self):
        new = write(self.root, "asm/us/new.s", "x")
        before = new.stat().st_mtime
        self.assertEqual(self.run_script(self.old, self.root).returncode, 0)
        self.assertEqual(new.stat().st_mtime, before)

    def test_c_file_is_touched_when_its_global_asm_changed(self):
        write(self.old, "asm/us/nonmatchings/f.s", "before", OLD_TIME)
        write(self.root, "asm/us/nonmatchings/f.s", "after")
        write(self.old, "asm/us/nonmatchings/g.s", "same", OLD_TIME)
        write(self.root, "asm/us/nonmatchings/g.s", "same")
        changed = write(self.root, "src/changed.c",
                        '#pragma GLOBAL_ASM("asm/us/nonmatchings/f.s")\n', OLD_TIME)
        unchanged = write(self.root, "src/unchanged.c",
                          '#pragma GLOBAL_ASM("asm/us/nonmatchings/g.s")\n', OLD_TIME)
        self.assertEqual(self.run_script(self.old, self.root).returncode, 0)
        self.assertGreater(int(changed.stat().st_mtime), OLD_TIME)
        self.assertEqual(int(unchanged.stat().st_mtime), OLD_TIME)

    def test_global_asm_path_maps_to_the_requested_version(self):
        write(self.old, "asm/eu/nonmatchings/f.s", "before", OLD_TIME)
        write(self.root, "asm/eu/nonmatchings/f.s", "after")
        c = write(self.root, "src/x.c",
                  '#pragma GLOBAL_ASM("asm/us/nonmatchings/f.s")\n', OLD_TIME)
        result = self.run_script(self.old, self.root, "eu", ("asm/eu",))
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertGreater(int(c.stat().st_mtime), OLD_TIME)

    def test_missing_global_asm_target_touches_the_c_file(self):
        write(self.root, "asm/us/keep.s", "x")
        c = write(self.root, "src/x.c",
                  '#pragma GLOBAL_ASM("asm/us/nonmatchings/gone.s")\n', OLD_TIME)
        self.assertEqual(self.run_script(self.old, self.root).returncode, 0)
        self.assertGreater(int(c.stat().st_mtime), OLD_TIME)

    def test_changed_generated_header_asks_for_a_full_rebuild(self):
        write(self.old, "assets/us/tbl.h", "before", OLD_TIME)
        write(self.root, "assets/us/tbl.h", "after")
        self.assertEqual(self.run_script(self.old, self.root).returncode, 3)

    def test_unchanged_generated_header_does_not(self):
        write(self.old, "assets/us/tbl.h", "same", OLD_TIME)
        write(self.root, "assets/us/tbl.h", "same")
        self.assertEqual(self.run_script(self.old, self.root).returncode, 0)


if __name__ == "__main__":
    unittest.main()
