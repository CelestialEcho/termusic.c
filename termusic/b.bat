@echo off
mkdir bin >nul 2>nul
gcc -std=c11 -Iinclude main.c -o bin/o.exe 
