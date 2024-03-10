#!/bin/bash

timestamp=$(date +%s)

libs="-luser32 -lopengl32 -lgdi32"
warnings="-Wno-writable-strings -Wno-format-security -Wno-deprecated-declarations -Wno-switch"
includes="-Ithird_party -Ithird_party/Include"

clang++ $includes -g src/main.cpp -oparadox.exe $libs $warnings 


rm -f game* # Remove old game* files
clang++ -g "src/game.cpp" -shared -o game$timestamp.dll  $warnings
mv game$timestamp.dll game.dll