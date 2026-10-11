#!/usr/bin/env python3
"""Map a 5.3 uopt.c anchor (label or text) to the corresponding 7.1 location.

usage: align53.py <5.3 uopt.c> <7.1 uopt.c> <anchor> [<anchor> ...]

For each anchor (a label like ``L46faac`` or a literal line), find the enclosing
``f_*`` function in the 5.3 source, take the function of the same name in 7.1,
align the two bodies line by line with difflib after normalizing addresses,
labels and emulated constants, and print the 7.1 line the anchor maps to with a
little context. Used to port workbench (5.3) hooks into cdx71 (7.1); every
mapping is checked by hand against the printed context before it is used.
"""
import difflib
import re
import sys

FUNC = re.compile(r'^static [a-z0-9_ ]+\b(f_\w+|func_[0-9a-f]+)\(uint8_t \*mem[^)]*\) \{$')
NORM = [
    (re.compile(r'\bL[0-9a-f]{6}\b'), 'L'),
    (re.compile(r'0x1000[0-9a-f]{4}|0x1001[0-9a-f]{4}|0x1002[0-9a-f]{4}'), 'ADDR'),
    (re.compile(r'^// [bf]dead .*$'), '//dead'),
]


def functions(lines):
    out, name, start = {}, None, 0
    for i, l in enumerate(lines):
        m = FUNC.match(l)
        if m:
            if name: out[name] = (start, i)
            name, start = m.group(1), i
    if name: out[name] = (start, len(lines))
    return out


def norm(l):
    l = l.strip()
    for rx, rep in NORM: l = rx.sub(rep, l)
    return l


def main():
    a = open(sys.argv[1]).read().split('\n')
    b = open(sys.argv[2]).read().split('\n')
    fa, fb = functions(a), functions(b)
    for anchor in sys.argv[3:]:
        pat = anchor + ':' if re.fullmatch(r'L[0-9a-f]{6}', anchor) else anchor
        hits = [i for i, l in enumerate(a) if l.strip() == pat or (pat not in ('',) and pat in l and not re.fullmatch(r'L[0-9a-f]{6}', anchor))]
        if len(hits) != 1:
            print(f'== {anchor}: {len(hits)} hits in 5.3'); continue
        i = hits[0]
        fn = next((n for n, (s, e) in fa.items() if s <= i < e), None)
        if fn not in fb:
            print(f'== {anchor}: function {fn} not in 7.1'); continue
        s1, e1 = fa[fn]; s2, e2 = fb[fn]
        A = [norm(x) for x in a[s1:e1]]; B = [norm(x) for x in b[s2:e2]]
        sm = difflib.SequenceMatcher(None, A, B, autojunk=False)
        mapped = None
        for tag, i1, i2, j1, j2 in sm.get_opcodes():
            if i1 <= i - s1 < i2:
                mapped = (tag, j1 + (i - s1 - i1) if tag == 'equal' else j1)
                break
        if mapped is None:
            print(f'== {anchor}: unaligned'); continue
        tag, j = mapped
        k = s2 + j
        print(f'== {anchor} in {fn}: 5.3 line {i + 1} -> 7.1 line {k + 1} ({tag}); ratio {sm.ratio():.3f}')
        print('   5.3:', ' | '.join(x.strip() for x in a[i:i + 3]))
        print('   7.1:', ' | '.join(x.strip() for x in b[k:k + 3]))
        lab = next((b[t].strip() for t in range(k, s2, -1) if re.fullmatch(r'L[0-9a-f]{6}:', b[t].strip())), None)
        print('   nearest 7.1 label at/above:', lab)


if __name__ == '__main__':
    main()
