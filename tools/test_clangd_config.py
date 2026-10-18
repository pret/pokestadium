"""Check database coverage and automatic refresh without ROM/build dependencies."""

from contextlib import ExitStack, redirect_stdout
import io
import json
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch

import clangd_config
from clangd_config import (
    ROOT, VERSION_FLAGS, database_entries, refresh_database, selected_version,
)


class DatabaseTests(unittest.TestCase):
    """Exercise paths, changes, variants and fail-closed freshness checks."""

    def setUp(self):
        self.resources = ExitStack()
        self.addCleanup(self.resources.close)
        self.root = Path(self.resources.enter_context(
            tempfile.TemporaryDirectory(prefix="clangd config ")))
        subprocess.run(["git", "init", "-q", str(self.root)], check=True)
        (self.root / "src").mkdir()
        (self.root / "src/one.c").write_text("int original;\n", encoding="utf-8")
        (self.root / "compile_flags.txt").write_text(
            "-Isrc\n-std=gnu89\n", encoding="utf-8")

    def test_covers_existing_tracked_and_untracked_sources(self):
        """Deleted, ignored and textually included files are not separate TUs."""
        for name in ("two.c", "removed.c", "ignored.c", "table.inc.c"):
            (self.root / "src" / name).write_text("int value;\n", encoding="utf-8")
        subprocess.run(
            ["git", "-C", str(self.root), "add", "src/one.c", "src/removed.c"],
            check=True)
        (self.root / "src/removed.c").unlink()
        (self.root / ".gitignore").write_text("src/ignored.c\n", encoding="utf-8")
        entries = database_entries(self.root, "us")
        self.assertEqual(
            [Path(entry["file"]).name for entry in entries], ["one.c", "two.c"])
        self.assertEqual(entries[0]["directory"], str(self.root))
        self.assertEqual(entries[0]["arguments"][-1], str(self.root / "src/one.c"))
        self.assertIn("-Isrc", entries[0]["arguments"])
        self.assertIn("-DVERSION_US=1", entries[0]["arguments"])

    def test_identifier_rename_does_not_rewrite_json(self):
        """Source contents never enter the compilation database."""
        self.assertTrue(refresh_database(self.root)[0])
        database = self.root / "build/clangd/compile_commands.json"
        before = database.stat().st_mtime_ns
        (self.root / "src/one.c").write_text("int renamed;\n", encoding="utf-8")
        self.assertFalse(refresh_database(self.root)[0])
        self.assertEqual(database.stat().st_mtime_ns, before)

    def test_file_add_move_delete_and_flag_changes_refresh(self):
        """Watch refresh uses the working tree, not just the Git index."""
        refresh_database(self.root)
        source = self.root / "src/one.c"
        source.rename(self.root / "src/renamed file.c")
        self.assertTrue(refresh_database(self.root)[0])
        (self.root / "src/new.c").write_text("int added;\n", encoding="utf-8")
        self.assertTrue(refresh_database(self.root)[0])
        (self.root / "src/new.c").unlink()
        self.assertTrue(refresh_database(self.root)[0])
        with (self.root / "compile_flags.txt").open("a", encoding="utf-8") as flags:
            flags.write("-DCHANGED=1\n")
        self.assertTrue(refresh_database(self.root)[0])
        self.assertFalse(refresh_database(self.root)[0])

    def test_variant_selection_survives_watcher_refresh(self):
        """Automatic refresh must not silently revert a selected regional view."""
        refresh_database(self.root, "us_rev2")
        self.assertEqual(selected_version(self.root), "us_rev2")
        self.assertFalse(refresh_database(self.root)[0])
        database = self.root / "build/clangd/compile_commands.json"
        entries = json.loads(database.read_text(encoding="utf-8"))
        self.assertIn("-DVERSION_US_REV2=1", entries[0]["arguments"])
        self.assertNotIn("-DVERSION_US_REV1=1", entries[0]["arguments"])
        for version in VERSION_FLAGS:
            with self.subTest(version=version):
                self.assertIn(VERSION_FLAGS[version][0],
                              database_entries(self.root, version)[0]["arguments"])

    def test_check_is_read_only_and_detects_staleness(self):
        """Checking missing output must not create files."""
        self.assertTrue(refresh_database(self.root, check=True)[0])
        self.assertFalse((self.root / "build").exists())
        refresh_database(self.root)
        self.assertFalse(refresh_database(self.root, check=True)[0])
        (self.root / "src/new.c").write_text("int added;\n", encoding="utf-8")
        self.assertTrue(refresh_database(self.root, check=True)[0])

    def test_empty_source_inventory_is_an_error(self):
        """Do not replace a working database with an accidental empty index."""
        (self.root / "src/one.c").unlink()
        with self.assertRaisesRegex(ValueError, "No game C"):
            refresh_database(self.root)

    def test_watcher_refreshes_moved_files_and_preserves_variant(self):
        """Exercise the CLI watch loop, including its interruption handling."""
        refresh_database(self.root, "us_rev2")
        iterations = 0

        def change_inventory(_interval):
            nonlocal iterations
            iterations += 1
            if iterations == 1:
                (self.root / "src/one.c").rename(self.root / "src/moved.c")
            else:
                raise KeyboardInterrupt

        with patch.object(clangd_config, "ROOT", self.root), \
                patch.object(clangd_config.time, "sleep", change_inventory), \
                redirect_stdout(io.StringIO()):
            self.assertEqual(clangd_config.main(["--watch"]), 0)
        entries = json.loads(
            (self.root / "build/clangd/compile_commands.json").read_text(
                encoding="utf-8"))
        self.assertEqual(Path(entries[0]["file"]).name, "moved.c")
        self.assertIn("-DVERSION_US_REV2=1", entries[0]["arguments"])

    def test_real_repository_inventory_matches_git(self):
        """Every existing tracked game translation unit gets one command."""
        result = subprocess.run(
            ["git", "-C", str(ROOT), "ls-files", "-z", "--", "src"],
            check=True, capture_output=True, text=True)
        expected = {
            str(ROOT / name) for name in result.stdout.split("\0")
            if name.endswith(".c") and not name.endswith(".inc.c")
            and (ROOT / name).is_file()
        }
        entries = database_entries(ROOT, "us")
        self.assertTrue(expected)
        self.assertTrue(expected <= {entry["file"] for entry in entries})
        self.assertEqual(len(entries), len({entry["file"] for entry in entries}))


if __name__ == "__main__":
    unittest.main()
