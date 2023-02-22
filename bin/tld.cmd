@echo off
ld_towns -N -S -o %1.bin crt0.o %1.o -lce -lt -lme -lpc
echo ld_towns ret=%ERRORLEVEL%
genexp3 %1.bin %1.exp
