#!/usr/bin/env python3
"""Standard-media exporters used by unpack_all_assets.py.

Model decoding uses an explicitly selected external pipeline, not signature
scanning. Audio decoding reuses this repository's existing Numus/MORT tools.
"""

import ast
import base64
import hashlib
import importlib.util
import io
import json
import math
import re
import struct
import sys
import urllib.request
import wave
from collections import Counter
from pathlib import Path

MODEL_REVISION = "33dea39d52a36641bca9499ad8ad59774ac183ae"
MODEL_URL = (
    "https://raw.githubusercontent.com/scottcandy34/"
    f"DramaticShapeVoxelMod-latest/{MODEL_REVISION}/model_extract/pipeline/"
)
MODEL_HASHES = {
    "fragment.py": "5a7c0831826474c6e9afdea7c76d8ddbdea91d4b63791db82c596b497884aba5",
    "glb.py": "24b75de1260c3d3401ce2819a158354191b4da2f2dde4260d131c1db6e6c4f58",
}
US_MD5 = "ed1378bc12115f71209a77844965ba50"


def load_module(name, path):
    """Load a user-selected local module without changing its source."""
    spec = importlib.util.spec_from_file_location(name, path)
    if spec is None or spec.loader is None:
        raise ValueError(f"cannot load module: {path}")
    module = importlib.util.module_from_spec(spec)
    sys.modules[name] = module
    spec.loader.exec_module(module)
    return module


def model_tools(repo, selected, fetch):
    """Load pinned model tools, optionally downloading verified source once."""
    directory = selected or repo / "build" / "asset-export-tools" / MODEL_REVISION
    directory = directory.resolve()
    for name, digest in MODEL_HASHES.items():
        path = directory / name
        if not path.exists() and fetch and selected is None:
            print(f"Downloading pinned model decoder: {name}", flush=True)
            with urllib.request.urlopen(MODEL_URL + name, timeout=60) as response:
                source = response.read(1024 * 1024)
            if hashlib.sha256(source).hexdigest() != digest:
                raise ValueError(f"model tool checksum mismatch: {name}")
            directory.mkdir(parents=True, exist_ok=True)
            with path.open("xb") as stream:
                stream.write(source)
        if not path.is_file():
            raise ValueError(
                "model tools not found; use --fetch-model-tools to download the "
                "two pinned modules, or --model-tools <pipeline-directory>"
            )
        if hashlib.sha256(path.read_bytes()).hexdigest() != digest:
            raise ValueError(f"{path}: expected pinned model decoder {MODEL_REVISION}")
    return (
        load_module("_stadium_fragment_export", directory / "fragment.py"),
        load_module("_stadium_glb_export", directory / "glb.py"),
    )


def encode_png(width, height, rgba):
    """Encode RGBA pixels as a standard PNG."""
    from PIL import Image  # pylint: disable=import-outside-toplevel

    if width <= 0 or height <= 0 or width * height > 4 * 1024 * 1024:
        raise ValueError("invalid or excessive texture dimensions")
    if len(rgba) != width * height * 4:
        raise ValueError("decoded pixel count does not match texture dimensions")
    output = io.BytesIO()
    Image.frombytes("RGBA", (width, height), bytes(rgba)).save(output, format="PNG")
    return output.getvalue()


def rgba5551(value):
    """Expand N64 RGB5551 into eight-bit RGBA channels."""
    channels = [(value >> shift) & 31 for shift in (11, 6, 1)]
    return tuple((channel << 3) | (channel >> 2) for channel in channels) + (255 * (value & 1),)


def texture_png(data, offset, width, height, texture_format, palette_offset=None):
    """Decode an explicitly described linear N64 texture, without guessing."""
    bits = {
        "rgba16": 16,
        "rgba32": 32,
        "ia4": 4,
        "ia8": 8,
        "ia16": 16,
        "i4": 4,
        "i8": 8,
        "ci4": 4,
        "ci8": 8,
    }
    if texture_format not in bits:
        raise ValueError(f"unsupported texture format: {texture_format}")
    pixels = width * height
    if width <= 0 or height <= 0 or pixels > 4 * 1024 * 1024:
        raise ValueError("invalid or excessive texture dimensions")
    size = (pixels * bits[texture_format] + 7) // 8
    if offset < 0 or offset + size > len(data):
        raise ValueError("texture range is outside its asset")
    raw = data[offset : offset + size]
    palette = None
    if texture_format.startswith("ci"):
        count = 16 if texture_format == "ci4" else 256
        if palette_offset is None or not 0 <= palette_offset <= len(data) - count * 2:
            raise ValueError("CI texture needs a bounded RGBA16 palette_offset")
        palette = [
            rgba5551(struct.unpack_from(">H", data, palette_offset + i * 2)[0])
            for i in range(count)
        ]
    rgba = bytearray()
    for index in range(pixels):
        if bits[texture_format] == 4:
            value = (raw[index // 2] >> (4 if index % 2 == 0 else 0)) & 15
        elif bits[texture_format] == 8:
            value = raw[index]
        elif bits[texture_format] == 16:
            value = struct.unpack_from(">H", raw, index * 2)[0]
        else:
            rgba.extend(raw[index * 4 : index * 4 + 4])
            continue
        if palette is not None:
            color = palette[value]
        elif texture_format == "rgba16":
            color = rgba5551(value)
        elif texture_format == "ia16":
            color = (value >> 8,) * 3 + (value & 255,)
        elif texture_format == "ia8":
            color = (17 * (value >> 4),) * 3 + (17 * (value & 15),)
        elif texture_format == "ia4":
            intensity_bits = value >> 1
            intensity = (intensity_bits << 5) | (intensity_bits << 2) | (intensity_bits >> 1)
            color = (intensity,) * 3 + (255 * (value & 1),)
        else:
            intensity = value * 17 if texture_format == "i4" else value
            # RDP intensity formats supply intensity to both color and alpha.
            color = (intensity,) * 4
        rgba.extend(color)
    return encode_png(width, height, rgba)


def text_table(data, encoding):
    """Read a bounded count/relative-offset/NUL-terminated text table."""
    if len(data) < 4:
        raise ValueError("truncated string table")
    count = struct.unpack_from(">I", data)[0]
    if count > 100000 or 4 + count * 4 > len(data):
        raise ValueError("invalid string table count")
    strings = []
    for index in range(count):
        offset = struct.unpack_from(">I", data, 4 + index * 4)[0]
        if not 4 + count * 4 <= offset < len(data):
            raise ValueError(f"string {index}: invalid relative offset")
        end = data.find(b"\0", offset)
        if end < 0:
            raise ValueError(f"string {index}: missing NUL terminator")
        raw = data[offset:end]
        strings.append(
            {
                "index": index,
                "offset": offset,
                "text": raw.decode(encoding, errors="strict"),
                "raw_hex": raw.hex(),
            }
        )
    return strings


def numeric(expression):
    """Evaluate only integer literals and elementary constant arithmetic."""
    expression = re.sub(r"(?<=\d)[uUlL]+\b", "", expression.strip())
    node = ast.parse(expression, mode="eval").body

    def evaluate(item):
        if (
            isinstance(item, ast.Constant)
            and isinstance(item.value, int)
            and not isinstance(item.value, bool)
        ):
            return item.value
        if isinstance(item, ast.UnaryOp) and isinstance(item.op, (ast.USub, ast.UAdd)):
            value = evaluate(item.operand)
            return -value if isinstance(item.op, ast.USub) else value
        if isinstance(item, ast.BinOp):
            left, right = evaluate(item.left), evaluate(item.right)
            operations = {
                ast.Add: lambda: left + right,
                ast.Sub: lambda: left - right,
                ast.Mult: lambda: left * right,
                ast.FloorDiv: lambda: left // right,
            }
            if type(item.op) in operations:
                return operations[type(item.op)]()
        raise ValueError("not a literal integer expression")

    return evaluate(node)


def c_calls(text, names):
    """Yield complete argument lists for selected C calls, preserving offsets."""
    pattern = re.compile(r"\b(" + "|".join(re.escape(name) for name in names) + r")\s*\(")
    for match in pattern.finditer(text):
        start = match.end()
        level, argument_start, arguments = 1, start, []
        for position in range(start, len(text)):
            character = text[position]
            if character == "(":
                level += 1
            elif character == ")":
                level -= 1
                if not level:
                    arguments.append(text[argument_start:position].strip())
                    yield match.group(1), arguments, match.start()
                    break
            elif character == "," and level == 1:
                arguments.append(text[argument_start:position].strip())
                argument_start = position + 1


def address(expression):
    """Resolve a literal segmented address or legacy D_<hex> symbol only."""
    value = expression.strip()
    match = re.fullmatch(r"(?:\([^()]*\)\s*)*(?:D_([0-9A-Fa-f]{7,8})|(0x[0-9A-Fa-f]+))", value)
    if not match:
        raise ValueError("not a literal segmented address")
    return int(match.group(1) or match.group(2), 16)


def source_textures(repo):
    """Discover literal texture views and same-directory ASSET_LOAD mappings.

    This is intentionally a limited recognizer, not a C preprocessor. Ambiguous
    segment mappings, variables, indexed expressions and computed sizes are
    reported as unresolved instead of receiving guessed offsets or dimensions.
    """
    draw_formats = {
        "Rgba16": "rgba16",
        "Rgba32": "rgba32",
        "Ia8": "ia8",
        "Ia16": "ia16",
        "I4": "i4",
        "I8": "i8",
    }
    names = ["gDPLoadTextureBlock", "gDPLoadTextureBlock_4b"]
    names += ["Gfx_DrawTexture" + name for name in draw_formats]
    files, bindings = [], {}
    for path in sorted((repo / "src").rglob("*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        # Keep line numbers stable while removing comments.
        text = re.sub(
            r"/\*.*?\*/|//[^\n]*", lambda match: "\n" * match.group().count("\n"), text, flags=re.S
        )
        files.append((path, text))
        group = bindings.setdefault(path.parent, {})
        for _, arguments, _ in c_calls(text, ["ASSET_LOAD"]):
            if len(arguments) != 3:
                continue
            try:
                segment = address(arguments[0]) >> 24
            except ValueError:
                continue
            if re.fullmatch(r"[A-Za-z_]\w*", arguments[1]):
                group.setdefault(segment, set()).add(arguments[1])
    found, unresolved = [], []
    for path, text in files:
        group = bindings[path.parent]
        arrays = {}
        for match in re.finditer(r"\b(\w+)\s*\[[^\]]*\]\s*=\s*\{([^{}]*)\}", text, re.S):
            try:
                values = [address(item) for item in match.group(2).split(",") if item.strip()]
                if values and all(0 < value >> 24 < 16 for value in values):
                    arrays[match.group(1)] = values
            except ValueError:
                continue
        for name, args, at in c_calls(text, names):
            evidence = f"{path.relative_to(repo).as_posix()}:{text[:at].count(chr(10)) + 1}"
            try:
                if name.startswith("Gfx_DrawTexture"):
                    texture_format = draw_formats[name.removeprefix("Gfx_DrawTexture")]
                    pointer_expression = args[4]
                    width, height = numeric(args[5]), numeric(args[3])
                else:
                    pointer_expression = args[1]
                    fmt = args[2].removeprefix("G_IM_FMT_").lower()
                    if name.endswith("_4b"):
                        texture_format = fmt + "4"
                        width, height = numeric(args[3]), numeric(args[4])
                    else:
                        size = re.fullmatch(r"G_IM_SIZ_(4|8|16|32)b", args[3])
                        if size is None:
                            raise ValueError("unknown texel size")
                        texture_format = fmt + size.group(1)
                        width, height = numeric(args[4]), numeric(args[5])
                indexed = re.fullmatch(r"(\w+)\s*\[[^\]]+\]", pointer_expression)
                if indexed and indexed.group(1) in arrays:
                    pointers = arrays[indexed.group(1)]
                else:
                    pointers = [address(pointer_expression)]
                for pointer in pointers:
                    candidates = group.get(pointer >> 24, set())
                    if len(candidates) != 1:
                        raise ValueError("missing or ambiguous asset-to-segment mapping")
                    found.append(
                        {
                            "asset": next(iter(candidates)) + ".bin",
                            "offset": pointer & 0xFFFFFF,
                            "width": width,
                            "height": height,
                            "format": texture_format,
                            "evidence": evidence,
                            "view": "literal load/draw rectangle",
                        }
                    )
            except (ValueError, SyntaxError, IndexError, KeyError) as error:
                unresolved.append({"evidence": evidence, "call": name, "reason": str(error)})
    return found, unresolved


def normalize_glb(blob):
    """Convert normalized SHORT animation rotations to glTF-required FLOAT.

    The pinned backend emits normalized SHORT quaternions. Standard glTF
    animation outputs require FLOAT; append float data and redirect accessors.
    Preserve original geometry and all other backend data.
    """
    if blob[:4] != b"glTF" or struct.unpack_from("<I", blob, 4)[0] != 2:
        raise ValueError("model exporter did not produce GLB 2.0")
    json_length = struct.unpack_from("<I", blob, 12)[0]
    document = json.loads(blob[20 : 20 + json_length])
    binary_start = 20 + json_length + 8
    binary = bytearray(blob[binary_start:])
    changed = set()
    for animation in document.get("animations", []):
        for channel in animation["channels"]:
            if channel["target"]["path"] != "rotation":
                continue
            index = animation["samplers"][channel["sampler"]]["output"]
            if index in changed:
                continue
            accessor = document["accessors"][index]
            if accessor["componentType"] == 5126:
                continue
            if accessor["componentType"] != 5122 or not accessor.get("normalized"):
                raise ValueError("unexpected backend animation rotation representation")
            view = document["bufferViews"][accessor["bufferView"]]
            offset = view.get("byteOffset", 0) + accessor.get("byteOffset", 0)
            values = struct.unpack_from("<" + "h" * accessor["count"] * 4, binary, offset)
            floating = struct.pack(
                "<" + "f" * len(values), *(max(-1.0, value / 32767) for value in values)
            )
            binary.extend(b"\0" * (-len(binary) % 4))
            accessor["bufferView"] = len(document["bufferViews"])
            document["bufferViews"].append(
                {"buffer": 0, "byteOffset": len(binary), "byteLength": len(floating)}
            )
            binary.extend(floating)
            accessor["componentType"] = 5126
            accessor.pop("normalized", None)
            accessor.pop("byteOffset", None)
            changed.add(index)
    document["buffers"][0]["byteLength"] = len(binary)
    document["asset"]["generator"] += " + Stadium media exporter"
    encoded = json.dumps(document, separators=(",", ":")).encode()
    encoded += b" " * (-len(encoded) % 4)
    binary.extend(b"\0" * (-len(binary) % 4))
    size = 12 + 8 + len(encoded) + 8 + len(binary)
    return (
        struct.pack("<III", 0x46546C67, 2, size)
        + struct.pack("<II", len(encoded), 0x4E4F534A)
        + encoded
        + struct.pack("<II", len(binary), 0x004E4942)
        + binary
    )


def standard_normals(model):
    """Normalize game quantized normals for glTF, keeping raw JSON unchanged.

    Zero vectors receive a conventional +Z fallback so exported glTF normals are
    well formed. This is format normalization, not a claim about game lighting.
    """
    primitives = []
    for primitive in model["prims"]:
        normals = []
        for index in range(0, len(primitive["nrm"]), 3):
            vector = primitive["nrm"][index : index + 3]
            length = math.sqrt(sum(value * value for value in vector))
            normals.extend([value / length for value in vector] if length else [0, 0, 1])
        primitives.append(dict(primitive, nrm=normals))
    return dict(model, prims=primitives)


class MediaExporter:
    """Add standard files and an honest coverage inventory to an unpack plan."""

    def __init__(self, unpacker, repo, options):
        self.unpacker = unpacker
        self.repo = repo
        self.options = options
        self.leaves = dict(unpacker.files)
        self.outputs = []
        self.failures = []
        self.covered = set()
        self.details = {}

    def add(self, name, data, source, category):
        """Add a derived file using the container unpacker's collision checks."""
        destination = Path("media") / name
        self.unpacker.add_file(destination, data, source, ("media:" + category,))
        self.outputs.append(
            {
                "path": destination.as_posix(),
                "source": source,
                "category": category,
                "bytes": len(data),
            }
        )
        self.covered.add(source)

    def add_json(self, name, value, source, category):
        """Write human-readable UTF-8 JSON."""
        self.add(
            name,
            (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"),
            source,
            category,
        )

    def export_text(self):
        """Export every recognized textdata table to indexed JSON and UTF-8 TXT."""
        tables = {}
        for name, data in self.leaves.items():
            if not re.fullmatch(r"textdata/\d+\.bin", name):
                continue
            try:
                strings = text_table(data, self.options.text_encoding)
                table_number = Path(name).stem
                tables[table_number] = strings
                self.add_json(
                    f"text/tables/{table_number}.json",
                    {
                        "source": name,
                        "encoding": self.options.text_encoding,
                        "strings": strings,
                    },
                    name,
                    "text",
                )
                readable = "\n\n".join(
                    f"[{entry['index']}]\n"
                    + "".join(
                        (
                            char
                            if (32 <= ord(char) < 127 or ord(char) >= 160 or char in "\n\t")
                            else f"\\x{ord(char):02x}"
                        )
                        for char in entry["text"]
                    )
                    for entry in strings
                )
                self.add(
                    f"text/tables/{table_number}.txt",
                    (readable + "\n").encode("utf-8"),
                    name,
                    "text",
                )
            except (ValueError, UnicodeError) as error:
                self.failures.append({"source": name, "category": "text", "reason": str(error)})
        self.add_json(
            "text/all_tables.json",
            {
                "encoding": self.options.text_encoding,
                "tables": tables,
                "note": "Tokens and control bytes are not substituted. raw_hex preserves each string.",
            },
            "textdata.bin",
            "text",
        )

    def export_textures(self):
        """Export standard JPEGs, known icon images, and source-backed views."""
        from PIL import Image  # pylint: disable=import-outside-toplevel

        for name, data in self.leaves.items():
            if name.endswith(".jpeg"):
                try:
                    with Image.open(io.BytesIO(data)) as image:
                        rgba = image.convert("RGBA")
                        png = encode_png(rgba.width, rgba.height, rgba.tobytes())
                    self.add("images/" + str(Path(name).with_suffix(".png")), png, name, "images")
                except (OSError, ValueError) as error:
                    self.failures.append(
                        {"source": name, "category": "images", "reason": str(error)}
                    )
            elif re.fullmatch(r"pokemon_icons/\d+\.bin", name) and len(data) == 3200:
                self.add(
                    "textures/" + str(Path(name).with_suffix(".png")),
                    texture_png(data, 0, 40, 40, "rgba16"),
                    name,
                    "textures",
                )
        self.export_fonts()
        recipes, unresolved = source_textures(self.repo)
        # These dynamic array uses do not expose a direct address at the draw call.
        # Exact offsets and dimensions are from area_select.c's arrays and draw loops.
        if self.options.version == "us":
            recipes.append(
                {
                    "asset": "n64_logo_texture.bin",
                    "offset": 0,
                    "width": 128,
                    "height": 112,
                    "format": "rgba16",
                    "evidence": "src/fragments/n64_logo/n64_logo.c:N64Logo_DrawLogoTexture",
                }
            )
            recipes += [
                {
                    "asset": "area_select_ui.bin",
                    "offset": offset,
                    "width": 36,
                    "height": 36,
                    "format": "rgba16",
                    "evidence": "src/fragments/area_select/area_select.c:gAreaSelectSparkleTextures",
                }
                for offset in (0x5000, 0x5A20, 0x6440)
            ]
            recipes += [
                {
                    "asset": "area_select_ui.bin",
                    "offset": 0x6E60 + index * 0x6200,
                    "width": 196,
                    "height": 64,
                    "format": "rgba16",
                    "evidence": "src/fragments/area_select/area_select.c:gAreaSelectNameBannerTextures",
                }
                for index in range(10)
            ]
        if self.options.texture_manifest:
            recipes += json.loads(self.options.texture_manifest.read_text(encoding="utf-8"))
        done, records = set(), []
        for recipe in recipes:
            name = recipe["asset"]
            key = (
                name,
                recipe["offset"],
                recipe["width"],
                recipe["height"],
                recipe["format"],
                recipe.get("palette_offset"),
            )
            if key in done:
                continue
            done.add(key)
            # A single-file wrapper's output is <asset>.bin. A one-member archive
            # instead produces <asset>/0.bin; both come from the named source bin.
            leaf = name if name in self.leaves else str(Path(name).with_suffix("") / "0.bin")
            data = self.leaves.get(leaf)
            if data is None:
                unresolved.append({"recipe": recipe, "reason": "packed asset leaf unavailable"})
                continue
            try:
                png = texture_png(
                    data,
                    recipe["offset"],
                    recipe["width"],
                    recipe["height"],
                    recipe["format"],
                    recipe.get("palette_offset"),
                )
                destination = (
                    f"textures/{Path(name).stem}/"
                    f"{recipe['offset']:06X}_{recipe['width']}x{recipe['height']}_"
                    f"{recipe['format']}.png"
                )
                self.add(destination, png, leaf, "textures")
                records.append(dict(recipe, output="media/" + destination))
            except ValueError as error:
                unresolved.append({"recipe": recipe, "reason": str(error)})
        self.details["texture_views"] = records
        self.details["unresolved_source_texture_calls"] = unresolved
        self.details["texture_note"] = (
            "Views are exact described rectangles, sometimes tiles rather than full sprites. "
            "A texture output does not mean its entire input binary was converted."
        )

    def export_fonts(self):
        """Export all six font sizes as glyph PNGs and a packed atlas.

        Font_LoadSet points glyph data past the 0x90-byte advance table.
        Font_LoadSizes supplies the cell sizes; glyph 0x90 is the I8 overlay
        loaded separately by Font_DrawChar. Other cells use IA8.
        """
        from PIL import Image  # pylint: disable=import-outside-toplevel

        metrics = []
        sizes = [(16, 10), (16, 12), (16, 16), (24, 20), (24, 24), (32, 32)]
        for index, (width, height) in enumerate(sizes):
            name = f"fonts/{index}.bin"
            data = self.leaves.get(name)
            if data is None:
                continue
            count, remainder = divmod(len(data) - 144, width * height)
            if count != 145 or remainder:
                self.failures.append(
                    {"source": name, "category": "fonts", "reason": "unexpected font cell layout"}
                )
                continue
            atlas = Image.new("RGBA", (width * 16, height * 10))
            for glyph in range(count):
                texture_format = "i8" if glyph == 144 else "ia8"
                png = texture_png(data, 144 + glyph * width * height, width, height, texture_format)
                self.add(f"fonts/{index}/glyph_{glyph:03d}.png", png, name, "font-glyphs")
                with Image.open(io.BytesIO(png)) as image:
                    atlas.paste(image, ((glyph % 16) * width, (glyph // 16) * height))
            self.add(
                f"fonts/{index}/atlas.png",
                encode_png(atlas.width, atlas.height, atlas.tobytes()),
                name,
                "font-atlases",
            )
            metrics.append(
                {
                    "font": index,
                    "width": width,
                    "height": height,
                    "advance_bytes": list(data[:144]),
                    "glyph_count": count,
                    "atlas_columns": 16,
                    "atlas_rows": 10,
                }
            )
        self.add_json(
            "fonts/metrics.json",
            {
                "fonts": metrics,
                "evidence": "src/graphics_textures.c:Font_LoadSet/LoadSizes/DrawChar",
            },
            "fonts.bin",
            "font-metadata",
        )

    def export_models(self):
        """Export Pokémon model fragments to animated GLB, textures and JSON."""
        decoder, writer = model_tools(
            self.repo, self.options.model_tools, self.options.fetch_model_tools
        )
        self.details["model_backend"] = {
            "revision": MODEL_REVISION,
            "url": MODEL_URL,
            "sha256": MODEL_HASHES,
            "generated_effects": False,
        }
        records = []
        models = [
            (name, data)
            for name, data in self.leaves.items()
            if name.startswith("pokemon_models/") and data[8:16] == b"FRAGMENT"
        ]
        for number, (name, data) in enumerate(models):
            try:
                model = decoder.extract(data, name=name)
                for animation in model["anims"]:
                    animation["name"] = f"animation_{animation['index']:02d}"
                if not model["prims"]:
                    raise ValueError("model has no decoded mesh primitives")
                images = [
                    base64.b64decode(texture["png"].split(",", 1)[1], validate=True)
                    for texture in model["textures"]
                ]
                prefix = f"models/{Path(name).stem}"
                blob = normalize_glb(writer.build_glb(standard_normals(model), images))
                self.add(prefix + ".glb", blob, name, "models")
                for index, image in enumerate(images):
                    self.add(f"{prefix}_textures/{index:03d}.png", image, name, "model-textures")
                # Preserve expression/material tracks that standard glTF cannot
                # represent, alongside callbacks, skeleton and decoder warnings.
                self.add_json(prefix + ".json", model, name, "model-metadata")
                records.append(
                    {
                        "source": name,
                        "species": model["species"],
                        "meshes": len(model["prims"]),
                        "textures": len(images),
                        "animations": len(model["anims"]),
                        "warnings": model["warnings"],
                        "callbacks": model["fx"],
                    }
                )
            except Exception as error:  # pylint: disable=broad-exception-caught
                self.failures.append(
                    {
                        "source": name,
                        "category": "models",
                        "reason": f"{type(error).__name__}: {error}",
                    }
                )
            if number % 25 == 0:
                print(f"Models: {number + 1}/{len(models)}", flush=True)
        self.details["models"] = records

    def export_audio(self):
        """Reuse the repository's US 1.0 sample and announcer decoders."""
        rom_path = self.options.rom
        if rom_path is None:
            candidates = [
                self.repo / "build" / "pokestadium-us.z64",
                self.repo / "baseroms" / "us" / "baserom.z64",
            ]
            rom_path = next((path for path in candidates if path.is_file()), None)
        if rom_path is None:
            raise ValueError(
                "audio needs --rom <built-US-1.0-ROM> or the standard build/baserom path"
            )
        rom = rom_path.read_bytes()
        if self.options.version != "us" or hashlib.md5(rom).hexdigest() != US_MD5:
            raise ValueError("audio offsets are verified for US 1.0 only; refusing another ROM")
        directory = self.repo / "tools" / "audio"
        sys.path.insert(0, str(directory))
        try:
            numus = load_module("numus_audio", directory / "numus_audio.py")
            banks = load_module("_stadium_audio_extract", directory / "extract_audio.py")
            mort = load_module("mort_audio", directory / "mort_audio.py")
        finally:
            sys.path.pop(0)
        sample_records = []
        for raw_offset in banks.RAW_BANKS:
            twin = banks.find_twin(rom, raw_offset)
            wave_offset = rom.find(numus.WT_MAGIC, raw_offset, raw_offset + 0x40000)
            if twin is None or wave_offset < 0:
                raise ValueError(f"audio bank {raw_offset:X}: missing bank or wave table")
            bank = numus.parse_expanded_bank(twin[1])
            for index, sample in enumerate(bank.samples):
                encoded = rom[wave_offset + sample.base : wave_offset + sample.base + sample.length]
                if len(encoded) != sample.length:
                    raise ValueError("truncated sample payload")
                if len(encoded) < 9:
                    continue
                pcm = numus.decode_frames(sample.book, encoded, wrap_out=False)
                destination = f"audio/banks/{raw_offset:08X}/sample_{index:03d}.wav"
                self.add(
                    destination,
                    wav_bytes(pcm, numus.SYNTH_RATE),
                    f"ROM:0x{wave_offset + sample.base:X}",
                    "audio-samples",
                )
                sample_records.append(
                    {
                        "bank": bank.name,
                        "bank_offset": raw_offset,
                        "index": index,
                        "wav": "media/" + destination,
                        "sample_rate": numus.SYNTH_RATE,
                        "loop_start": sample.loop_start,
                        "loop_end": sample.loop_end,
                        "loop_count": sample.loop_count,
                        "samples": len(pcm),
                        "note": "32000 Hz engine-rate preview; instrument pitch can change playback rate.",
                    }
                )
            print(f"Audio bank: {raw_offset:08X} ({len(bank.samples)} descriptors)", flush=True)
        clips = mort.archive4_clips(rom)
        if sorted(clips) != sorted(clip for chain in mort.find_mort_chains(rom) for clip in chain):
            raise ValueError("announcer index and independent chain walk disagree")
        voice_records = []
        for index, (offset, frames, rate, words) in enumerate(clips):
            decoder = mort.MortDecoder(rom, offset)
            decoded = decoder.decode()
            if len(decoded) != frames * mort.SAMPLES_PER_FRAME or decoder.size() != words * 4:
                raise ValueError(f"announcer clip {index}: decoded length mismatch")
            pcm = [value - 65536 if value & 32768 else value for value in decoded]
            destination = f"audio/announcer/{index:04d}_{offset:08X}.wav"
            self.add(destination, wav_bytes(pcm, rate), f"ROM:0x{offset:X}", "audio-voices")
            voice_records.append(
                {
                    "offset": offset,
                    "sample_rate": rate,
                    "samples": len(pcm),
                    "wav": "media/" + destination,
                }
            )
            if index % 50 == 0:
                print(f"Announcer: {index + 1}/{len(clips)}", flush=True)
        self.add_json(
            "audio/index.json",
            {
                "rom_md5": US_MD5,
                "samples": sample_records,
                "voices": voice_records,
                "music_rendered": False,
            },
            "ROM:audio",
            "audio-index",
        )
        self.details["audio"] = {
            "sample_wavs": len(sample_records),
            "voice_wavs": len(voice_records),
            "music_note": "WAVs are samples and voice clips, not rendered sequenced music. "
            "No sequence-to-MIDI or soundtrack synthesis is implemented.",
        }

    def run(self):
        """Run selected exporters and record unconverted leaves."""
        selected = set(self.options.media_types.split(","))
        allowed = {"textures", "models", "audio", "text"}
        if not selected <= allowed:
            raise ValueError("--media-types accepts textures,models,audio,text")
        if self.options.version != "us":
            raise ValueError("standard-media recipes currently support US 1.0 only")
        for category, operation in (
            ("text", self.export_text),
            ("textures", self.export_textures),
            ("models", self.export_models),
            ("audio", self.export_audio),
        ):
            if category in selected:
                operation()
        self.add_json(
            "coverage.json",
            {
                "schema": 1,
                "selected": sorted(selected),
                "complete": False,
                "output_counts": dict(Counter(item["category"] for item in self.outputs)),
                "outputs": self.outputs.copy(),
                "failures": self.failures,
                "leaves_without_media_output": [
                    name for name in self.leaves if name not in self.covered
                ],
                "details": self.details,
                "limitations": [
                    "No claim that every byte/texture/model/audio/text resource has been decoded.",
                    "UI extraction is source/recipe-backed and partial; dynamic loads are unresolved.",
                    "Model GLB includes skeletal animations, but not material/expression switching; "
                    "those tracks remain in the model JSON.",
                    "glTF normals are normalized; zero vectors use +Z. Raw normals remain in model JSON.",
                    "Runtime callback effects are not synthesized or replaced with generated artwork.",
                    "Sequenced music is not rendered to WAV or exported to MIDI.",
                ],
            },
            "asset-export",
            "coverage",
        )
        counts = dict(Counter(item["category"] for item in self.outputs))
        print("Standard media: " + json.dumps(counts), flush=True)
        if self.failures:
            print(
                f"Media conversion failures: {len(self.failures)}; see media/coverage.json",
                file=sys.stderr,
            )
        return not self.failures


def wav_bytes(pcm, rate):
    """Encode mono 16-bit PCM as a standard little-endian WAV file."""
    if not 1 <= rate <= 192000:
        raise ValueError(f"invalid sample rate: {rate}")
    output = io.BytesIO()
    with wave.Wave_write(output) as stream:
        stream.setnchannels(1)
        stream.setsampwidth(2)
        stream.setframerate(rate)
        clipped = [max(-32768, min(32767, value)) for value in pcm]
        stream.writeframes(struct.pack("<" + "h" * len(clipped), *clipped))
    return output.getvalue()
