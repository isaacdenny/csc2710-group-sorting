#!/bin/bash

# Compile the SDL2 game source code
g++ ./src/*.cpp -o output

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. You can run the output with ./output"
else
    echo "Compilation failed."
fi
