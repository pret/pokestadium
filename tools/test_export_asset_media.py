"""Regression tests for standard texture, model, audio, and text exports."""

import argparse
import contextlib
import io
import json
import struct
import tempfile
import unittest
from pathlib import Path

from PIL import Image

from export_asset_media import (
    MediaExporter,
    address,
    c_calls,
    normalize_glb,
    numeric,
    source_textures,
    standard_normals,
    text_table,
    texture_png,
    wav_bytes,
)
from unpack_all_assets import Unpacker, main
from test_unpack_all_assets import archive


def pixels(png):
    """Decode a generated PNG through an independent image reader."""
    with Image.open(io.BytesIO(png)) as image:
        raw = image.convert("RGBA").tobytes()
        return [tuple(raw[index : index + 4]) for index in range(0, len(raw), 4)]


class TextureTests(unittest.TestCase):
    """Check pixel values, not just generated file signatures."""

    def test_rgba16_channels(self):
        """RGB5551 preserves primary colors and one-bit transparency."""
        data = struct.pack(">4H", 0xF801, 0x07C1, 0x003F, 0)
        self.assertEqual(
            pixels(texture_png(data, 0, 2, 2, "rgba16")),
            [
                (255, 0, 0, 255),
                (0, 255, 0, 255),
                (0, 0, 255, 255),
                (0, 0, 0, 0),
            ],
        )

    def test_rgba32(self):
        """RGBA32 preserves all four bytes exactly."""
        self.assertEqual(
            pixels(texture_png(b"\x01\x02\x03\x04", 0, 1, 1, "rgba32")), [(1, 2, 3, 4)]
        )

    def test_intensity_and_alpha(self):
        """I and IA formats follow the source texture component encodings."""
        for texture_format, data, expected in [
            ("i4", b"\xf0", [(255,) * 4, (0,) * 4]),
            ("i8", b"\x80\xff", [(128,) * 4, (255,) * 4]),
            ("ia4", b"\xf0", [(255, 255, 255, 255), (0, 0, 0, 0)]),
            ("ia8", b"\xf1\x1f", [(255, 255, 255, 17), (17, 17, 17, 255)]),
            ("ia16", b"\x80\x01\x01\x80", [(128, 128, 128, 1), (1, 1, 1, 128)]),
        ]:
            with self.subTest(texture_format=texture_format):
                self.assertEqual(pixels(texture_png(data, 0, 2, 1, texture_format)), expected)

    def test_ia4_bit_expansion(self):
        """Three-bit intensity expands by bit replication, not truncation."""
        self.assertEqual(
            pixels(texture_png(b"\x57", 0, 2, 1, "ia4")), [(73, 73, 73, 255), (109, 109, 109, 255)]
        )

    def test_ci_palettes(self):
        """CI4 and CI8 require and use explicit RGBA16 palette data."""
        palette = struct.pack(">2H", 0xF801, 0x003F)
        self.assertEqual(
            pixels(texture_png(b"\x01" + palette + b"\0" * 28, 0, 2, 1, "ci4", 1)),
            [(255, 0, 0, 255), (0, 0, 255, 255)],
        )
        data = b"\x00\x01" + palette + b"\0" * 508
        self.assertEqual(
            pixels(texture_png(data, 0, 2, 1, "ci8", 2)), [(255, 0, 0, 255), (0, 0, 255, 255)]
        )
        with self.assertRaises(ValueError):
            texture_png(b"\0", 0, 1, 1, "ci4")

    def test_bounds_and_formats(self):
        """Reject bad dimensions, ranges, and unknown formats."""
        for parameters in [
            (b"", 0, 1, 1, "rgba16"),
            (b"\0" * 4, -1, 1, 1, "rgba16"),
            (b"", 0, 0, 1, "rgba16"),
            (b"\0" * 4, 0, 1, 1, "guess"),
        ]:
            with self.subTest(parameters=parameters), self.assertRaises(ValueError):
                texture_png(*parameters)


class TextTests(unittest.TestCase):
    """Ensure text extraction is indexed and byte-preserving."""

    def test_latin1_tokens_newlines_and_bytes(self):
        """Accents, tokens, and control codes remain recoverable."""
        payload = b"Pok\xe9mon #20\n\x01"
        table = struct.pack(">II", 1, 8) + payload + b"\0"
        strings = text_table(table, "latin-1")
        self.assertEqual(strings[0]["text"], "Pokémon #20\n\x01")
        self.assertEqual(bytes.fromhex(strings[0]["raw_hex"]), payload)

    def test_bad_offsets_and_missing_terminators(self):
        """Malformed tables cannot read arbitrary data as a message."""
        for table in [
            b"",
            struct.pack(">I", 10),
            struct.pack(">II", 1, 4),
            struct.pack(">II", 1, 8) + b"unterminated",
        ]:
            with self.subTest(table=table), self.assertRaises(ValueError):
                text_table(table, "latin-1")


class ModelAudioTests(unittest.TestCase):
    """Check standard-format normalization and WAV metadata."""

    def test_normalized_model_copy(self):
        """Normal normalization does not change the raw model metadata."""
        model = {"prims": [{"nrm": [3, 0, 0, 0, 0, 0], "pos": [0, 0, 0]}]}
        converted = standard_normals(model)
        self.assertEqual(converted["prims"][0]["nrm"], [1, 0, 0, 0, 0, 1])
        self.assertEqual(model["prims"][0]["nrm"], [3, 0, 0, 0, 0, 0])

    def test_glb_animation_accessor(self):
        """Quantized backend animation outputs become standard float accessors."""
        document = {
            "asset": {"version": "2.0", "generator": "fixture"},
            "buffers": [{"byteLength": 8}],
            "bufferViews": [{"buffer": 0, "byteOffset": 0, "byteLength": 8}],
            "accessors": [
                {
                    "bufferView": 0,
                    "componentType": 5122,
                    "count": 1,
                    "type": "VEC4",
                    "normalized": True,
                }
            ],
            "animations": [
                {
                    "samplers": [{"output": 0}],
                    "channels": [{"sampler": 0, "target": {"path": "rotation"}}],
                }
            ],
        }
        encoded = json.dumps(document).encode()
        encoded += b" " * (-len(encoded) % 4)
        binary = struct.pack("<4h", 0, 0, 0, 32767)
        blob = (
            struct.pack("<III", 0x46546C67, 2, 28 + len(encoded) + len(binary))
            + struct.pack("<II", len(encoded), 0x4E4F534A)
            + encoded
            + struct.pack("<II", len(binary), 0x004E4942)
            + binary
        )
        converted = normalize_glb(blob)
        size = struct.unpack_from("<I", converted, 12)[0]
        parsed = json.loads(converted[20 : 20 + size])
        self.assertEqual(parsed["accessors"][0]["componentType"], 5126)
        self.assertNotIn("normalized", parsed["accessors"][0])
        self.assertEqual(struct.unpack_from("<I", converted, 8)[0], len(converted))

    def test_wav_pcm_rate_and_clipping(self):
        """WAV output is mono little-endian signed PCM with bounded samples."""
        import wave  # pylint: disable=import-outside-toplevel

        blob = wav_bytes([-40000, -1, 0, 40000], 16000)
        with wave.open(io.BytesIO(blob), "rb") as stream:
            self.assertEqual(stream.getframerate(), 16000)
            self.assertEqual(stream.getnchannels(), 1)
            self.assertEqual(stream.getsampwidth(), 2)
            self.assertEqual(struct.unpack("<4h", stream.readframes(4)), (-32768, -1, 0, 32767))
        with self.assertRaises(ValueError):
            wav_bytes([0], 0)


class SourceAndCoverageTests(unittest.TestCase):
    """Check source-backed texture discovery and coverage reporting."""

    def test_literal_resolvers(self):
        """Reject executable expressions while accepting segmented addresses."""
        self.assertEqual(address("(u8*) D_3005000"), 0x03005000)
        self.assertEqual(numeric("(0x20 * 2) + 4"), 68)
        with self.assertRaises(ValueError):
            numeric("function()")
        self.assertEqual(
            list(c_calls("draw(a, f(b, c), 3);", ["draw"]))[0][1], ["a", "f(b, c)", "3"]
        )

    def test_source_array_and_ambiguity(self):
        """A literal address array exports every candidate without index guessing."""
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src" / "fixture.c").write_text(
                "u32 frames[] = { 0x03000000, 0x03000010 };"
                "ASSET_LOAD(D_3000000, example, 0);"
                "gDPLoadTextureBlock_4b(dl++, frames[index], G_IM_FMT_I, 8, 4, 0);",
                encoding="utf-8",
            )
            recipes, unresolved = source_textures(root)
            self.assertEqual([item["offset"] for item in recipes], [0, 16])
            self.assertFalse(unresolved)
            self.assertTrue(all(item["asset"] == "example.bin" for item in recipes))

    def test_partial_coverage_is_not_complete(self):
        """Successful exports must still identify untouched input leaves."""
        unpacker = Unpacker()
        unpacker.add_file(Path("opaque.bin"), b"opaque", "opaque.bin", ())
        options = argparse.Namespace(
            media_types="text",
            version="us",
            text_encoding="latin-1",
        )
        exporter = MediaExporter(unpacker, Path("."), options)
        self.assertTrue(exporter.run())
        coverage = json.loads(unpacker.files["media/coverage.json"])
        self.assertFalse(coverage["complete"])
        self.assertIn("opaque.bin", coverage["leaves_without_media_output"])

    def test_media_cli_default_and_failure_status(self):
        """Media mode uses a separate tree and reports per-table failures."""
        with tempfile.TemporaryDirectory() as temporary:
            repo = Path(temporary)
            source = repo / "assets" / "us"
            source.mkdir(parents=True)
            (source / "textdata.bin").write_bytes(archive(b"bad"))
            with contextlib.redirect_stdout(io.StringIO()), contextlib.redirect_stderr(
                io.StringIO()
            ):
                status = main(["--repo", str(repo), "--media", "--media-types", "text"])
            self.assertEqual(status, 2)
            report = json.loads((repo / "assets/exported/us/media/coverage.json").read_text())
            self.assertEqual(len(report["failures"]), 1)
            self.assertFalse((repo / "assets/unpacked/us").exists())

    def test_wrong_audio_rom_rejected(self):
        """Hard-coded US audio offsets cannot be used on an unknown image."""
        with tempfile.TemporaryDirectory() as temporary:
            rom = Path(temporary) / "bad.z64"
            rom.write_bytes(b"not the expected ROM")
            options = argparse.Namespace(rom=rom, version="us")
            exporter = MediaExporter(Unpacker(), Path(temporary), options)
            with self.assertRaisesRegex(ValueError, "US 1.0"):
                exporter.export_audio()


if __name__ == "__main__":
    unittest.main()
