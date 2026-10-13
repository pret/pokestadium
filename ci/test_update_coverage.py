#!/usr/bin/env python3
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from update_coverage import active_pragmas  # noqa: E402


def pragma(name):
    return f'#pragma GLOBAL_ASM("asm/us/nonmatchings/x/{name}.s")\n'


class ActivePragmas(unittest.TestCase):
    def test_other_version_branch_is_not_a_us_owner(self):
        text = "#if defined(VERSION_US_REV2)\n" + pragma("rev2") + "#else\nvoid f(void) {}\n#endif\n" + pragma("plain")
        self.assertEqual(active_pragmas(text), ["plain"])
        self.assertEqual(active_pragmas(text, frozenset({"VERSION_US", "VERSION_US_REV2"})), ["rev2", "plain"])

    def test_else_ifndef_and_elif(self):
        text = (
            "#ifndef VERSION_JP\n" + pragma("a") + "#elif defined(VERSION_PAL)\n" + pragma("b") + "#endif\n"
            "#if !defined(VERSION_US) || defined(VERSION_JP)\n" + pragma("c") + "#else\n" + pragma("d") + "#endif\n"
        )
        self.assertEqual(active_pragmas(text), ["a", "d"])

    def test_undecidable_condition_counts_as_active(self):
        self.assertEqual(active_pragmas("#if FOO > 3\n" + pragma("x") + "#endif\n"), ["x"])

    def test_nested_inactive_branch_hides_inner_pragmas(self):
        text = "#if defined(VERSION_JP)\n#if 1\n" + pragma("n") + "#endif\n#endif\n"
        self.assertEqual(active_pragmas(text), [])


if __name__ == "__main__":
    unittest.main()
