#!/bin/bash

libs=-luser32
warnings="-Wno-writable-strings -Wno-format-security"
includes="-Ithird_party -Ithird_party/include"

clang++ -g src/main.cpp -oparadox.exe $libs $warnings
