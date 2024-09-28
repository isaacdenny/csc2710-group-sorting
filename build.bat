@echo off

REM Create a new directory for the build output
mkdir output

REM Compile the SDL2 game source code
g++ .\src\*.cpp -o output\program_output.exe

REM Check if the compilation was successful
if %ERRORLEVEL% == 0 (
    echo Compilation successful.
) else (
    echo Compilation failed.
)
