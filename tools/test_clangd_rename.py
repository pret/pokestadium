"""Exercise real clangd cross-file rename with unopened C consumers."""

from contextlib import ExitStack
import json
from pathlib import Path
import queue
import shutil
import subprocess
import tempfile
import threading
import time
import unittest

from clangd_config import ROOT, database_entries, refresh_database


class LanguageClient:
    """Minimal synchronous LSP client; notifications are consumed while waiting."""

    def __init__(self, root, unlimited=True):
        self.messages = queue.Queue()
        self.sequence = 0
        self.errors = tempfile.TemporaryFile()
        arguments = ["clangd", "--background-index", "-j=2", "--log=error"]
        if unlimited:
            arguments.append("--rename-file-limit=0")
        # This server spans multiple requests and is explicitly reaped by close().
        self.process = subprocess.Popen(  # pylint: disable=consider-using-with
            arguments, cwd=root, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
            stderr=self.errors,
        )
        self.reader = threading.Thread(target=self.read_messages, daemon=True)
        self.reader.start()
        self.request("initialize", {
            "processId": None, "rootUri": root.as_uri(),
            "capabilities": {},
            "workspaceFolders": [{"uri": root.as_uri(), "name": "rename fixture"}],
        })
        self.send("initialized", {})

    def read_messages(self):
        """Decode Content-Length frames without blocking the server's output."""
        try:
            while True:
                headers = {}
                while True:
                    line = self.process.stdout.readline()
                    if not line:
                        return
                    if line == b"\r\n":
                        break
                    key, value = line.decode("ascii").split(":", 1)
                    headers[key.lower()] = value.strip()
                length = int(headers["content-length"])
                payload = self.process.stdout.read(length)
                self.messages.put(json.loads(payload))
        except (OSError, ValueError) as error:
            self.messages.put({"reader_error": str(error)})

    def send(self, method, params, request_id=None):
        """Send a request or notification."""
        message = {"jsonrpc": "2.0", "method": method, "params": params}
        if request_id is not None:
            message["id"] = request_id
        payload = json.dumps(message).encode("utf-8")
        self.process.stdin.write(
            f"Content-Length: {len(payload)}\r\n\r\n".encode("ascii") + payload)
        self.process.stdin.flush()

    def request(self, method, params):
        """Wait for one response, with a bounded deadline."""
        self.sequence += 1
        request_id = self.sequence
        self.send(method, params, request_id)
        deadline = time.monotonic() + 30
        while time.monotonic() < deadline:
            try:
                message = self.messages.get(
                    timeout=max(0.01, deadline - time.monotonic()))
            except queue.Empty:
                break
            if "reader_error" in message:
                raise AssertionError(message)
            if message.get("id") == request_id:
                return message
        raise AssertionError(f"clangd timed out during {method}")

    def close(self):
        """Reap the language server and close all pipes, even on assertion error."""
        if self.process.poll() is None:
            self.process.terminate()
            try:
                self.process.wait(timeout=5)
            except subprocess.TimeoutExpired:
                self.process.kill()
                self.process.wait()
        self.reader.join(timeout=5)
        self.process.stdin.close()
        self.process.stdout.close()
        self.errors.close()


@unittest.skipUnless(shutil.which("clangd"), "clangd is not on PATH")
class RenameTests(unittest.TestCase):
    """A shared-field rename must reach closed files and preserve other types."""

    def setUp(self):
        self.resources = ExitStack()
        self.addCleanup(self.resources.close)
        self.root = Path(self.resources.enter_context(
            tempfile.TemporaryDirectory(prefix="clangd rename ")))
        subprocess.run(["git", "init", "-q", str(self.root)], check=True)
        (self.root / "src").mkdir()
        (self.root / "compile_flags.txt").write_text(
            "-std=gnu89\n-Isrc\n", encoding="utf-8")
        (self.root / ".clangd").write_text(
            "CompileFlags:\n  CompilationDatabase: build/clangd\n"
            "Index:\n  Background: Build\n", encoding="utf-8")
        self.header = self.root / "src/shared.h"
        self.header.write_text(
            "struct Subject { int oldField; };\n"
            "struct Other { int oldField; };\n", encoding="utf-8")
        self.expected = {self.header.as_uri(): 21}
        for number in range(56):
            source = self.root / f"src/consumer_{number}.c"
            source.write_text(
                '#include "shared.h"\n'
                f"int consumer_{number}(struct Subject *value, struct Other *other) {{\n"
                "    return value->oldField + other->oldField;\n"
                "}\n", encoding="utf-8")
            self.expected[source.as_uri()] = 18
        refresh_database(self.root)

    def open_header(self, unlimited=True):
        """Open only the header; no C consumer is ever sent through didOpen."""
        client = LanguageClient(self.root, unlimited)
        self.addCleanup(client.close)
        client.send("textDocument/didOpen", {"textDocument": {
            "uri": self.header.as_uri(), "languageId": "c", "version": 1,
            "text": self.header.read_text(encoding="utf-8"),
        }})
        return client

    def wait_for_index(self, client):
        """Independent expected fixture inventory is the index-completion gate."""
        deadline = time.monotonic() + 60
        response = {}
        while time.monotonic() < deadline:
            response = client.request("textDocument/references", {
                "textDocument": {"uri": self.header.as_uri()},
                "position": {"line": 0, "character": 22},
                "context": {"includeDeclaration": True},
            })
            locations = response.get("result") or []
            if len(locations) == len(self.expected) and {
                    location["uri"] for location in locations} == set(self.expected):
                return
            time.sleep(0.2)
        self.fail(f"Index never covered all unopened consumers: {response}")

    def rename(self, client):
        """Request a semantic rename at Subject.oldField, not Other.oldField."""
        return client.request("textDocument/rename", {
            "textDocument": {"uri": self.header.as_uri()},
            "position": {"line": 0, "character": 22},
            "newName": "renamedField",
        })

    def test_rename_reaches_more_than_50_unopened_files(self):
        """The selected field changes everywhere without touching its namesake."""
        client = self.open_header()
        self.wait_for_index(client)
        response = self.rename(client)
        self.assertNotIn("error", response, response)
        changes = response["result"].get("changes", {})
        for operation in response["result"].get("documentChanges", []):
            changes[operation["textDocument"]["uri"]] = operation["edits"]
        self.assertEqual(set(changes), set(self.expected))
        for uri, edits in changes.items():
            with self.subTest(uri=uri):
                self.assertEqual(len(edits), 1)
                self.assertEqual(edits[0]["newText"], "renamedField")
                self.assertEqual(edits[0]["range"]["start"], {
                    "line": 0 if uri == self.header.as_uri() else 2,
                    "character": self.expected[uri],
                })

    def test_default_file_limit_rejects_the_same_indexed_rename(self):
        """The workspace's unlimited flag is a functional requirement."""
        client = self.open_header(unlimited=False)
        self.wait_for_index(client)
        response = self.rename(client)
        self.assertIn("error", response, response)
        self.assertRegex(response["error"]["message"].lower(), r"limit|too many|50")

    def test_moved_source_is_covered_after_database_refresh_and_restart(self):
        """A source-layout change needs a current database and fresh live index."""
        client = self.open_header()
        self.wait_for_index(client)
        client.close()
        previous = self.root / "src/consumer_0.c"
        moved = self.root / "src/moved_consumer.c"
        previous.rename(moved)
        del self.expected[previous.as_uri()]
        self.expected[moved.as_uri()] = 18
        refresh_database(self.root)
        restarted = self.open_header()
        self.wait_for_index(restarted)
        response = self.rename(restarted)
        self.assertNotIn("error", response, response)
        changes = response["result"].get("changes", {})
        for operation in response["result"].get("documentChanges", []):
            changes[operation["textDocument"]["uri"]] = operation["edits"]
        self.assertEqual(set(changes), set(self.expected))
        self.assertIn(moved.as_uri(), changes)
        self.assertNotIn(previous.as_uri(), changes)


@unittest.skipUnless(shutil.which("clang"), "clang is not on PATH")
class ParseTests(unittest.TestCase):
    """Enumerating a file is weaker than successfully parsing its contents."""

    def test_all_game_translation_units_parse_in_default_view(self):
        """Verify the database flags against the actual current source inventory."""
        failures = []
        for entry in database_entries(ROOT, "us"):
            arguments = [arg for arg in entry["arguments"] if arg != "-c"]
            result = subprocess.run(
                [*arguments, "-fsyntax-only", "-Wno-unknown-warning-option"],
                cwd=entry["directory"], capture_output=True, text=True, check=False,
            )
            if result.returncode:
                failures.append(f'{entry["file"]}:\n{result.stderr}')
        self.assertFalse(failures, "\n".join(failures))


if __name__ == "__main__":
    unittest.main()
