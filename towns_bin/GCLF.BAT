rem ** FPU Ç…ÇÊÇÈïÇìÆè¨êîì_ââéZ **
run386 -nocrt %GCCROOT%/usr/bin/cpp  -D__GNUC__ -DTOWNS -I. -I %GCCROOT%/usr/include %1.c %1.i
if errorlevel 1 goto exit
run386 -nocrt %GCCROOT%/usr/bin/cc1 -O -m80387 -quiet %1.i
if errorlevel 1 goto exit
run386 -nocrt %GCCROOT%/usr/bin/gas -o %1.o %1.s
if errorlevel 1 goto exit
run386 -nocrt %GCCROOT%/usr/bin/ld -N -S -o %1.bin %GCCROOT%/usr/lib/crt0.o %1.o -L%GCCROOT%/usr/lib -lTN -lc -lme -lpc 
if errorlevel 1 goto exit
run386 -nocrt %GCCROOT%/usr/bin/genexp3  %1.bin %1.exp
:exit
