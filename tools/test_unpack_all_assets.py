"""Regression tests for the non-destructive bulk asset unpacker."""

import contextlib
import hashlib
import io
import json
import struct
import tempfile
import unittest
from pathlib import Path

import crunch64

from unpack_all_assets import Unpacker, archive_members, main


def archive(*members):
    """Build a BinArchive fixture, including the stadium_models flag byte."""
    offset = 16 + len(members) * 16
    table = bytearray()
    for member in members:
        table.extend(struct.pack(">IIII", offset, len(member), 0, 0))
        offset += len(member)
    return struct.pack(">IIII", 1, 0, offset, len(members)) + table + b"".join(members)


def persszp(payload):
    """Build the wrapper used by the existing PERS-SZP reader."""
    return (
        b"PERS-SZP"
        + struct.pack(">IIII", 24, len(payload), len(payload), 0)
        + bytes(crunch64.yay0.compress(payload))
    )


class UnpackTests(unittest.TestCase):
    """Exercise format handling, failure behavior, and input preservation."""

    def test_nested_formats(self):
        """Nested archives and both compression wrappers reach decoded leaves."""
        jpeg = b"\xff\xd8fixture\xff\xd9"
        wrapped_jpeg = b"PRESJPEG" + struct.pack(">II", 16, 0) + jpeg
        payload = archive(
            persszp(archive(b"FRAGMENT-example", wrapped_jpeg)),
            bytes(crunch64.yay0.compress(b"raw Yay0")),
        )
        unpacker = Unpacker()
        unpacker.unpack(payload, Path("models.bin"), "models.bin")
        self.assertEqual(
            unpacker.files,
            {
                "models/0/0.bin": b"FRAGMENT-example",
                "models/0/1.jpeg": jpeg,
                "models/1.bin": b"raw Yay0",
            },
        )

    def test_short_empty_and_unknown_are_preserved(self):
        """Unrecognized and empty inputs are valid raw leaves."""
        for payload in (b"", b"\0", b"\0" * 64, b"unknown audio"):
            with self.subTest(payload=payload):
                unpacker = Unpacker()
                unpacker.unpack(payload, Path("raw.bin"), "raw.bin")
                self.assertEqual(unpacker.files["raw.bin"], payload)

    def test_invalid_archive_bounds_remain_raw(self):
        """An archive-like prefix cannot authorize out-of-bounds slicing."""
        payload = bytearray(archive(b"example"))
        struct.pack_into(">I", payload, 16, len(payload) + 1)
        self.assertIsNone(archive_members(payload))

    def test_invalid_wrapper_and_compression_fail(self):
        """Recognized but malformed wrappers must produce an error."""
        for payload in (b"PERS-SZP", b"PRESJPEG" + b"\0" * 8, b"Yay0"):
            with self.subTest(payload=payload), self.assertRaises(ValueError):
                Unpacker().unpack(payload, Path("bad.bin"), "bad.bin")

    def test_nesting_limit(self):
        """Recursive archives cannot exhaust the Python call stack."""
        payload = b"end"
        for _ in range(18):
            payload = archive(payload)
        with self.assertRaisesRegex(ValueError, "nesting"):
            Unpacker().unpack(payload, Path("deep.bin"), "deep.bin")

    def test_decompression_size_limit(self):
        """Reject excessive output sizes before calling the native decoder."""
        payload = b"Yay0" + struct.pack(">III", 300 * 1024 * 1024, 16, 16)
        with self.assertRaisesRegex(ValueError, "limit"):
            Unpacker().unpack(payload, Path("large.bin"), "large.bin")

    def run_cli(self, arguments):
        """Silence expected CLI output for assertions."""
        with contextlib.redirect_stdout(io.StringIO()), contextlib.redirect_stderr(io.StringIO()):
            return main(arguments)

    def test_cli_preserves_inputs_and_reruns(self):
        """The CLI is non-destructive and ignores existing inspection views."""
        with tempfile.TemporaryDirectory() as temporary:
            repo = Path(temporary)
            source = repo / "assets" / "us"
            source.mkdir(parents=True)
            packed = source / "test.bin"
            packed.write_bytes(archive(persszp(b"decoded"), b"opaque"))
            digest = hashlib.sha256(packed.read_bytes()).hexdigest()
            # Existing extracted views must not become duplicate inputs.
            (source / "test").mkdir()
            (source / "test" / "0.bin").write_bytes(b"old view")
            arguments = ["--repo", str(repo), "--version", "us"]
            self.assertEqual(self.run_cli(arguments), 0)
            self.assertEqual(self.run_cli(arguments), 0)
            self.assertEqual(hashlib.sha256(packed.read_bytes()).hexdigest(), digest)
            output = repo / "assets" / "unpacked" / "us"
            self.assertEqual((output / "test" / "0.bin").read_bytes(), b"decoded")
            manifest = json.loads((output / "manifest.json").read_text())
            self.assertEqual(len(manifest["sources"]), 1)
            self.assertEqual(len(manifest["outputs"]), 2)

    def test_conflict_is_detected_before_writing(self):
        """A changed existing output blocks the entire write phase."""
        with tempfile.TemporaryDirectory() as temporary:
            repo = Path(temporary)
            source = repo / "assets" / "us"
            source.mkdir(parents=True)
            (source / "a.bin").write_bytes(b"new")
            (source / "z.bin").write_bytes(b"original")
            output = repo / "assets" / "unpacked" / "us"
            output.mkdir(parents=True)
            (output / "z.bin").write_bytes(b"user edit")
            self.assertEqual(self.run_cli(["--repo", str(repo)]), 1)
            self.assertFalse((output / "a.bin").exists())
            self.assertEqual((output / "z.bin").read_bytes(), b"user edit")

    def test_missing_inputs_and_overlap(self):
        """Bad input directories and overlapping outputs fail cleanly."""
        with tempfile.TemporaryDirectory() as temporary:
            repo = Path(temporary)
            self.assertEqual(self.run_cli(["--repo", str(repo)]), 1)
            source = repo / "assets" / "us"
            source.mkdir(parents=True)
            (source / "raw.bin").write_bytes(b"raw")
            self.assertEqual(
                self.run_cli(
                    [
                        "--repo",
                        str(repo),
                        "--output",
                        str(source / "decoded"),
                    ]
                ),
                1,
            )

    def test_output_symlink_escape(self):
        """A preexisting output symlink cannot redirect files outside the tree."""
        with tempfile.TemporaryDirectory() as temporary:
            repo = Path(temporary)
            source = repo / "assets" / "us"
            source.mkdir(parents=True)
            (source / "raw.bin").write_bytes(archive(b"raw"))
            output = repo / "assets" / "unpacked" / "us"
            output.mkdir(parents=True)
            outside = repo / "outside"
            outside.mkdir()
            (output / "raw").symlink_to(outside, target_is_directory=True)
            self.assertEqual(self.run_cli(["--repo", str(repo)]), 1)
            self.assertFalse((outside / "0.bin").exists())


if __name__ == "__main__":
    unittest.main()
