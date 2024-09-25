#!/bin/bash

# Compile the SDL2 game source code
g++ ./src/*.cpp -o output \
    -I./libs/SDL2-2.30.7/include \
    -L./libs/SDL2-2.30.7/lib/x86 \
    -lSDL2main -lSDL2

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. You can run the output with ./output"
else
    echo "Compilation failed."
fi
