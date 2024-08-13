#!/usr/bin/env python3

import sys
import re

with open(sys.argv[1], "r") as f:
    fd = f.read()

funcs = re.findall("(^[a-zA-Z0-9*_]+ .*\(.*\)) {$", fd, re.MULTILINE)
for func in funcs:
    print(func + ";")
