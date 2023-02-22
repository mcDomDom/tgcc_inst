@echo off
gcc -x c -S -msoft-float %1.c
if %ERRORLEVEL% neq 0 (
	echo gcc fail %ERRORLEVEL%
)
as %1.s -o %1.o
if %ERRORLEVEL% neq 0 (
	echo as fail %ERRORLEVEL%
)
rem sndtst.c‚Å‚Í‰½ŒÌ‚©libtn‚Ì‘O‚Élibce‚ª‚ ‚é‚Æstrchr“™‚ªundefined‚É‚È‚é‚Ì‚Å—v’ˆÓ
ld_towns -N -S -o %1.bin %LIBRARY_PATH%/crt0.o %1.o -L %LIBRARY_PATH% -ltn -lce -lme -lpc
if %ERRORLEVEL% neq 0 (
	echo ld_towns fail %ERRORLEVEL%
)
genexp3 %1.bin %1.exp
if %ERRORLEVEL% neq 0 (
	echo genexp3 fail %ERRORLEVEL%
)
