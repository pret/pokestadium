import os
import tempfile
import unittest
from pathlib import Path

import header_dependents as h


def write(root, rel, text):
    path = Path(root) / rel
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)
    return path


class HeaderDependentsTest(unittest.TestCase):
    def test_transitive_dependents(self):
        with tempfile.TemporaryDirectory() as d:
            write(d, "include/a.h", "")
            write(d, "include/b.h", '#include "a.h"\n')
            write(d, "src/uses_b.c", '#include "b.h"\n')
            write(d, "src/direct.c", "#include <a.h>\n")
            write(d, "src/unrelated.c", '#include "other.h"\n')
            names = [p.name for p in h.dependents(Path(d), ["a.h"])]
            self.assertEqual(sorted(names), ["b.h", "direct.c", "uses_b.c"])

    def test_cycle_terminates(self):
        with tempfile.TemporaryDirectory() as d:
            write(d, "include/a.h", '#include "b.h"\n')
            write(d, "include/b.h", '#include "a.h"\n')
            write(d, "src/x.c", '#include "a.h"\n')
            self.assertEqual(sorted(p.name for p in h.dependents(Path(d), ["a.h"])), ["a.h", "b.h", "x.c"])

    def test_changes_and_needs_full(self):
        with tempfile.TemporaryDirectory() as s, tempfile.TemporaryDirectory() as w:
            write(s, "same.h", "x"); write(w, "same.h", "x")
            write(s, "edit.h", "new"); write(w, "edit.h", "old")
            write(s, "added.h", "n")
            write(w, "gone.h", "o")
            self.assertEqual(h.changes(Path(s), Path(w)), ["added.h", "edit.h", "gone.h"])
        self.assertFalse(h.needs_full(["a.h", "sub/b.h"]))
        self.assertTrue(h.needs_full(["a.h", "macro.inc"]))
        self.assertTrue(h.needs_full(["trig_tables.inc.c"]))

    def test_touch_updates_mtime(self):
        with tempfile.TemporaryDirectory() as d:
            write(d, "include/a.h", "")
            c = write(d, "src/x.c", '#include "a.h"\n')
            os.utime(c, (1, 1))
            h.main(["h", "touch", d, "a.h"])
            self.assertGreater(c.stat().st_mtime, 1000)


if __name__ == "__main__":
    unittest.main()
