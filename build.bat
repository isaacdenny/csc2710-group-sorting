@echo off

REM Create a new directory for the build output
mkdir output

REM Compile the SDL2 game source code
g++ .\src\*.cpp -o output\program_output.exe ^
    -I.\libs\SDL2-2.30.7\include ^
    -I.\libs\SDL2_ttf-2.22.0\include ^
    -L.\libs\SDL2-2.30.7\lib\x86 ^
    -L.\libs\SDL2_ttf-2.22.0\lib\x86 ^
    -lSDL2 -lSDL2main -lSDL2_ttf

REM Check if the compilation was successful
if %ERRORLEVEL% == 0 (
    echo Compilation successful.

    REM Copy SDL2 DLL files to the output directory
    copy .\libs\SDL2-2.30.7\lib\x86\*.dll output\
    copy .\libs\SDL2_ttf-2.22.0\lib\x86\*.dll output\
    echo DLL files copied to output directory.
) else (
    echo Compilation failed.
)
