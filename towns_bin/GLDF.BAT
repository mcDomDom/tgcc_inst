rem ** FPU ‚É‚æ‚é•‚“®¬”“_‰‰Z **
run386 -nocrt %GCCROOT%/usr/bin/ld -N -S -o %1.bin %GCCROOT%/usr/lib/crt0.o %1.o -L%GCCROOT%/usr/lib -lTN -lc -lme -lpc 
if errorlevel 1 goto exit
run386 -nocrt %GCCROOT%/usr/bin/genexp3  %1.bin %1.exp
:exit
