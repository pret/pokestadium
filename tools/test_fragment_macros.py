"""Check fragment aliases and linker-token expansion without a ROM or MIPS toolchain."""

from pathlib import Path
import re
import subprocess
import unittest


ROOT = Path(__file__).resolve().parents[1]
ALIAS_PATTERN = re.compile(r"^#define (FRAGMENT_[A-Z0-9_]+) (fragment\d+)$", re.MULTILINE)


def preprocess(source):
    """Expand only the macro headers, using the build's host preprocessor."""
    result = subprocess.run(
        ["cpp", "-P", "-I", str(ROOT / "include"), "-"],
        input=source,
        text=True,
        capture_output=True,
        check=True,
    )
    return re.sub(r"\s+", "", result.stdout)


class FragmentMacroTests(unittest.TestCase):
    """Aliases must preserve every legacy expression, including queued calls."""

    def test_all_segments_have_unique_aliases(self):
        """Cover each US linker segment exactly once."""
        aliases = ALIAS_PATTERN.findall((ROOT / "include/fragments.h").read_text())
        segments = set(re.findall(
            r"^  - name: (fragment\d+)$",
            (ROOT / "yamls/us/rom.yaml").read_text(),
            re.MULTILINE,
        ))
        self.assertEqual(len(aliases), len(segments))
        self.assertEqual(len({alias for alias, _ in aliases}), len(segments))
        self.assertEqual({segment for _, segment in aliases}, segments)

    def test_aliases_follow_versioned_source_modules(self):
        """Check existing segments; Japan omits some US fragment modules."""
        aliases = ALIAS_PATTERN.findall((ROOT / "include/fragments.h").read_text())
        module_names = {
            "FRAGMENT_PROFESSOR_OAK_LAB": "pokemon_lab",
            "FRAGMENT_HALL_OF_FAME": "victory_palace",
        }
        for config in sorted((ROOT / "yamls").glob("*/rom.yaml")):
            segments = dict(re.findall(
                r"^  - name: (fragment\d+)\n(.*?)(?=^  - name:|\Z)",
                config.read_text(),
                re.MULTILINE | re.DOTALL,
            ))
            self.assertTrue(set(segments) <= {segment for _, segment in aliases})
            self.assertTrue(segments)
            for alias, segment in aliases:
                if segment not in segments:
                    continue
                module = module_names.get(alias, alias.removeprefix("FRAGMENT_").lower())
                with self.subTest(version=config.parent.name, alias=alias):
                    self.assertIn(f"fragments/{module}/", segments[segment])

    def test_aliases_expand_like_legacy_tokens(self):
        """Compare alias and raw-token expansions with the original expressions."""
        aliases = ALIAS_PATTERN.findall((ROOT / "include/fragments.h").read_text())
        for alias, segment in aliases:
            expressions = [
                (f"FRAGMENT_ID({alias})",
                 f"((((u32){segment}_TEXT_START & 0x0FF00000) >> 0x14) - 0x10)"),
                (f"FRAGMENT_LOAD({alias})",
                 f"(Fragment_Load(FRAGMENT_ID({segment}), "
                 f"{segment}_ROM_START, {segment}_relocs_ROM_END))"),
                (f"FRAGMENT_LOAD_AND_CALL({alias}, first, second)",
                 f"(Fragment_LoadAndCall(FRAGMENT_ID({segment}), "
                 f"{segment}_ROM_START, {segment}_relocs_ROM_END, first, second))"),
                (f"FRAGMENT_LOAD_AND_CALL2({alias}, first, second)",
                 f"(Fragment_QueueCall(FRAGMENT_ID({segment}), "
                 f"{segment}_ROM_START, {segment}_relocs_ROM_END, first, second))"),
            ]
            for actual, expected in expressions:
                with self.subTest(alias=alias, expression=actual):
                    self.assertEqual(
                        preprocess(f'#include "macros.h"\n{actual}\n'),
                        preprocess(f'#include "macros.h"\n{expected}\n'),
                    )
                    self.assertEqual(
                        preprocess(f'#include "macros.h"\n{actual.replace(alias, segment)}\n'),
                        preprocess(f'#include "macros.h"\n{expected}\n'),
                    )

    def test_non_fragment_asset_token_still_expands(self):
        """Preserve the asset-token use of FRAGMENT_ID in the reward screen."""
        self.assertEqual(
            preprocess('#include "macros.h"\nFRAGMENT_ID(_798CD0)\n'),
            "((((u32)_798CD0_TEXT_START&0x0FF00000)>>0x14)-0x10)",
        )

    def test_load_sites_use_semantic_aliases(self):
        """Reject numbered tokens or undefined aliases at C loader macro sites."""
        calls = re.compile(r"\bFRAGMENT_LOAD(?:_AND_CALL2?)?\(\s*(\w+)")
        aliases = dict(ALIAS_PATTERN.findall((ROOT / "include/fragments.h").read_text()))
        count = 0
        for path in (ROOT / "src").rglob("*.c"):
            for argument in calls.findall(path.read_text()):
                with self.subTest(path=str(path.relative_to(ROOT)), argument=argument):
                    self.assertIn(argument, aliases)
                count += 1
        self.assertGreater(count, 0)


if __name__ == "__main__":
    unittest.main()
