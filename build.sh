#!/bin/bash

libs="-luser32 -lopengl32 -lgdi32"
warnings="-Wno-writable-strings -Wno-format-security -Wno-deprecated-declarations"
includes="-Ithird_party -Ithird_party/include"

clang++ $includes -g src/main.cpp -oparadox.exe $libs $warnings