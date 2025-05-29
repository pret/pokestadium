#!/usr/bin/env python3

import sys
import re

with open(sys.argv[1], "r") as f:
    fd = f.read()
"""
funcs = re.findall("(^[a-zA-Z0-9*_]+ .*\(.*?\)) {", fd, re.MULTILINE | re.DOTALL)
for func in funcs:
    print(func + ";")
"""

func_re = re.compile(
    r'''
    ^\s*                                                     # line start
    (?!if\b|for\b|while\b|switch\b|case\b|return\b)          # skip control statements
    (?:(?:static|inline|extern|const|volatile)\s+)*          # qualifiers (optional)
    [A-Za-z_][\w\s\*\d]*?                                    # return type (rough)
    \s+                                                      # space
    (?P<name>[A-Za-z_]\w*)                                   # function name
    \s*                                                      # optional space
    \(                                                       # '('
        (?:[^(){}]|\([^()]*\))*?                             # arguments (allows nested ())
    \)                                                       # ')'
    \s*                                                      # optional space/newlines
    (?=\{)                                                   # next non-space char is '{'
    ''',
    re.MULTILINE | re.DOTALL | re.VERBOSE)

for m in func_re.finditer(fd):
    print(" ".join(m.group(0).split()) + ";")    # collapse whitespace, add semicolon

