rem ** FPU ‚É‚æ‚é•‚“®¬”“_‰‰Z **
 %GCCROOT%/bin/ld_towns -N -S -o %1.bin %LIBRARY_PATH%/crt0.o %1.o -L%GCCROOT%/lib -lTN -lc -lme -lpc 
if errorlevel 1 goto exit
genexp  %1.bin %1.exp
:exit
