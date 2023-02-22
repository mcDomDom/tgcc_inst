@echo off
gcc -x c -S -msoft-float %1.c
if %ERRORLEVEL% neq 0 (
	echo gcc fail %ERRORLEVEL%
)
as %1.s -o %1.o
