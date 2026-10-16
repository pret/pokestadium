#!/usr/bin/env python3
"""Recursively unpack extracted Stadium assets without changing build inputs."""

import argparse
import hashlib
import json
import os
import struct
import sys
from pathlib import Path

MAX_FILE_SIZE = 256 * 1024 * 1024
MAX_TOTAL_SIZE = 1024 * 1024 * 1024
MAX_DEPTH = 16
VERSIONS = ("us", "us_rev1", "us_rev2", "jp", "eu", "eu_rev1", "fr", "de", "es", "it")


def archive_members(data):
    """Recognize the BinArchive layout used by tools/unpack_asset.py.

    The prefix alone also occurs in ordinary data, so require a complete,
    bounded table before treating it as an archive. Unknown layouts stay raw.
    Member aliases and overlapping ranges are allowed by this reader.
    """
    if len(data) < 16 or data[:3] != b"\0\0\0" or data[4:8] != b"\0" * 4:
        return None
    total_size, count = struct.unpack_from(">II", data, 8)
    table_end = 16 + count * 16
    if not count or not table_end <= total_size <= len(data):
        return None
    members = []
    for index in range(count):
        offset, size = struct.unpack_from(">II", data, 16 + index * 16)
        if offset < table_end or offset + size > total_size:
            return None
        members.append((offset, size))
    return members


def decompress_yay0(data):
    """Use the same decoder as the existing repository tools, with size limits."""
    if len(data) < 16 or data[:4] != b"Yay0":
        raise ValueError("missing or truncated Yay0 header")
    expected_size = struct.unpack_from(">I", data, 4)[0]
    if expected_size > MAX_FILE_SIZE:
        raise ValueError("Yay0 output exceeds the 256 MiB per-file limit")
    try:
        import crunch64  # pylint: disable=import-outside-toplevel
    except ImportError as error:
        raise ValueError(
            "crunch64 is required; use the repository Python environment "
            "or install requirements.txt"
        ) from error
    try:
        decoded = bytes(crunch64.yay0.decompress(data))
    except Exception as error:  # pylint: disable=broad-exception-caught
        raise ValueError(f"Yay0 decompression failed: {error}") from error
    if len(decoded) != expected_size:
        raise ValueError("Yay0 decompressed size does not match its header")
    return decoded


class Unpacker:
    """Plan decoded leaves in memory before writing any outputs."""

    def __init__(self):
        self.files = {}
        self.records = []
        self.total_size = 0

    def unpack(self, data, destination, source, steps=(), depth=0):
        """Peel recognized wrappers and archives; preserve other payloads."""
        if depth > MAX_DEPTH:
            raise ValueError(f"{source}: nesting exceeds {MAX_DEPTH} levels")
        if len(data) > MAX_FILE_SIZE:
            raise ValueError(f"{source}: input exceeds 256 MiB")
        if data.startswith((b"PERS-SZP", b"PRESJPEG")):
            magic = data[:8].decode("ascii")
            minimum = 24 if magic == "PERS-SZP" else 16
            if len(data) < minimum:
                raise ValueError(f"{source}: truncated {magic} header")
            header_size = struct.unpack_from(">I", data, 8)[0]
            if not minimum <= header_size < len(data):
                raise ValueError(f"{source}: invalid {magic} header size")
            payload = data[header_size:]
            if magic == "PERS-SZP":
                payload = decompress_yay0(payload)
                self.unpack(payload, destination, source, steps + (magic, "Yay0"), depth + 1)
            else:
                # Like extract_presjpeg.py, strip the wrapper, not JPEG-decode it.
                self.add_file(destination.with_suffix(".jpeg"), payload, source, steps + (magic,))
            return
        if data.startswith(b"Yay0"):
            self.unpack(decompress_yay0(data), destination, source, steps + ("Yay0",), depth + 1)
            return
        members = archive_members(data)
        if members is not None:
            for index, (offset, size) in enumerate(members):
                self.unpack(
                    data[offset : offset + size],
                    destination.with_suffix("") / f"{index}.bin",
                    source,
                    steps + (f"BinArchive[{index}]",),
                    depth + 1,
                )
            return
        self.add_file(destination, data, source, steps)

    def add_file(self, destination, data, source, steps):
        """Record an output and its provenance, rejecting path collisions."""
        name = destination.as_posix()
        if name in self.files:
            raise ValueError(f"multiple assets resolve to {name}")
        self.total_size += len(data)
        if self.total_size > MAX_TOTAL_SIZE:
            raise ValueError("decoded output exceeds the 1 GiB total limit")
        self.files[name] = data
        self.records.append(
            {
                "source": source,
                "output": name,
                "steps": list(steps),
                "kind": "decoded" if steps else "raw",
                "size": len(data),
                "sha256": hashlib.sha256(data).hexdigest(),
            }
        )


def inside(path, parent):
    """Return whether a resolved path is within another path (Python 3.8+)."""
    return path == parent or parent in path.parents


def write_outputs(output, files):
    """Preflight conflicts, then write new files; identical reruns are safe."""
    for name, data in files.items():
        target = output / name
        if not inside(target.resolve(), output):
            raise ValueError(f"output symlink escapes destination: {target}")
        for parent in target.parents:
            if parent == output.parent:
                break
            if parent.exists() and not parent.is_dir():
                raise ValueError(f"output parent is not a directory: {parent}")
        if target.exists() and (not target.is_file() or target.read_bytes() != data):
            raise ValueError(
                f"output already exists with different contents: {target}; "
                "choose a fresh --output directory"
            )
    for name, data in files.items():
        target = output / name
        if target.exists():
            continue
        target.parent.mkdir(parents=True, exist_ok=True)
        with target.open("xb") as stream:
            stream.write(data)


def main(arguments=None):
    """Command-line entry point."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--version", choices=VERSIONS, default=os.environ.get("VERSION", "us"))
    parser.add_argument(
        "--repo",
        type=Path,
        default=Path(__file__).resolve().parents[1],
        help="repository root (default: script's parent repo)",
    )
    parser.add_argument(
        "--assets", type=Path, help="packed input directory (default: assets/VERSION)"
    )
    parser.add_argument(
        "--output",
        type=Path,
        help="destination (default: assets/exported/VERSION with --media; "
        "assets/unpacked/VERSION otherwise)",
    )
    parser.add_argument(
        "--media",
        action="store_true",
        help="also export PNG, animated GLB, WAV, and UTF-8 text (US 1.0)",
    )
    parser.add_argument(
        "--media-types",
        default="textures,models,audio,text",
        help="comma-separated subset of textures,models,audio,text",
    )
    parser.add_argument("--rom", type=Path, help="US 1.0 ROM for audio export")
    parser.add_argument(
        "--fetch-model-tools",
        action="store_true",
        help="download two hash-verified, revision-pinned model decoder modules",
    )
    parser.add_argument(
        "--model-tools", type=Path, help="existing pinned model_extract/pipeline directory"
    )
    parser.add_argument(
        "--texture-manifest", type=Path, help="additional texture recipe JSON array"
    )
    parser.add_argument(
        "--text-encoding",
        default="latin-1",
        help="source text encoding (US 1.0 defaults to latin-1)",
    )
    options = parser.parse_args(arguments)
    repo = options.repo.resolve()
    source = (options.assets or repo / "assets" / options.version).resolve()
    output_kind = "exported" if options.media else "unpacked"
    output = (options.output or repo / "assets" / output_kind / options.version).resolve()
    try:
        # Top-level bins are the Splat build inputs. Their subdirectories contain
        # generated views from extract_assets.sh and must not be extracted twice.
        inputs = sorted(source.glob("*.bin"))
        if not inputs:
            raise ValueError(f"no packed .bin assets in {source}; run make init first")
        if inside(output, source) or inside(source, output):
            raise ValueError("input and output directories must not overlap")
        unpacker = Unpacker()
        sources = []
        for path in inputs:
            if path.is_symlink():
                raise ValueError(f"refusing symlink input: {path}")
            if path.stat().st_size > MAX_FILE_SIZE:
                raise ValueError(f"{path}: input exceeds 256 MiB")
            data = path.read_bytes()
            sources.append(
                {"path": path.name, "size": len(data), "sha256": hashlib.sha256(data).hexdigest()}
            )
            unpacker.unpack(data, Path(path.name), path.name)
        media_success = True
        container_count = len(unpacker.files)
        if options.media:
            from export_asset_media import MediaExporter  # pylint: disable=import-outside-toplevel

            media_success = MediaExporter(unpacker, repo, options).run()
        manifest = {
            "schema": 1,
            "version": options.version,
            "sources": sources,
            "outputs": unpacker.records,
            "limits": {
                "depth": MAX_DEPTH,
                "file_bytes": MAX_FILE_SIZE,
                "total_bytes": MAX_TOTAL_SIZE,
            },
            "note": "Raw leaves are preserved. With --media, standard files and "
            "explicit format-coverage limits are listed in media/coverage.json.",
        }
        files = dict(unpacker.files)
        files["manifest.json"] = (json.dumps(manifest, indent=2) + "\n").encode()
        write_outputs(output, files)
        decoded = sum(record["kind"] == "decoded" for record in unpacker.records)
        print(
            f"Read {len(inputs)} packed assets; wrote {len(unpacker.files)} leaves "
            f"({decoded} unpacked/decoded, {len(unpacker.files) - decoded} raw)."
        )
        print(f"Output: {output}\nManifest: {output / 'manifest.json'}")
        if options.media:
            print(
                f"Container leaves: {container_count}; media files: "
                f"{len(unpacker.files) - container_count}"
            )
        return 0 if media_success else 2
    except (OSError, ValueError, ImportError, LookupError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
