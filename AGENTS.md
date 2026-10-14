# Agent instructions

Read `CONTRIBUTING.md` before making changes. Follow its naming, terminology, comment, and number-formatting rules.

## Do not assume shared conversational context

Repository comments and documentation must make sense to someone who has not read your conversation with the human directing you. That includes another agent, a reviewer, and a maintainer returning a month later. Write for that reader, not as a reply to the latest message.

State what the code does, why a name is justified, or which concrete limitation remains. Do not leave a rebuttal to an earlier misconception without explaining the underlying operation.

### Describe the code, not the correction

These examples illustrate comment style; they are not instructions to rename symbols or change behavior.

| Avoid | Prefer |
|---|---|
| `// Not fade progress.` | `// Set when clearedModes reaches 0xF8; enables navigation to Mewtwo.` |
| `// Not the active speed.` | `// Tower unlock tier: 0 = normal, 1 = Doduo, 2 = Dodrio.` |
| `// This is not a layout repair.` | `// FAKE: the loops access six afterimages, but this four-element declaration gives overlapping 0x24-byte trails.` |
| `// No self-linked list has been established.` | `// Word carried into/out of GB Tower by State_GbTower; its pointer role is unknown.` |

Avoid phrases such as "as discussed," "the user clarified," "we fixed this," "the previous assumption," and "retain this for now" in source comments. Those phrases belong in a conversation or, when useful, a commit/PR explanation that identifies the actual before/after change.

Negative statements are fine when they express a useful invariant or a specific evidence limit. "Entry 8 is a blocked-neighbor sentinel, not a selectable area" explains both roles. "Not what we thought earlier" explains neither.

### Leave an inspectable reason

- **Names:** connect the proposed meaning to a producer, consumer, command, decoded texture/string, or other concrete evidence. An existing name or a successful ROM comparison does not by itself establish semantic correctness.
- **Cross-file behavior:** identify the relevant function and use the `//@{path}` convention from `CONTRIBUTING.md` for source cross-references.
- **Unknowns:** name the unresolved question and the operation that is known. Do not invent semantics to eliminate an `unk_*` name.
- **Verification:** distinguish inspected source, decoded ROM data, runtime observations, and inference. Record the tested revision and target when documenting test results; old results do not automatically cover new edits.

For example, "images" alone does not explain a field's role. A comment such as the following gives the reader an operation to inspect:

```c
// Color-buffer descriptors with optional depth buffers; GfxImage_SetRenderTarget
// passes their img_p to gDPSetColorImage as the RDP color destination.
//@src/gfx_rect.c
```

Keep comments concise. Put a long evidence chain in repository documentation with identifiable paths, symbols, and revisions rather than copying a chat transcript into the source. Do not repeat obvious code or add a disclaimer to every annotation.

### One-month readability check

Before finishing, read the changed comments and documentation without mentally supplying the conversation. Can a reader tell what object or operation each claim describes, find its evidence, and distinguish known behavior from an unresolved interpretation? Rewrite anything that depends on remembering a question, an old mistake, or who "we" referred to.
