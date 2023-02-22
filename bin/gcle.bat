rem ** ソフトウェアによる浮動小数点演算 **
%GCCROOT%/bin/cpp  -D__GNUC__ -DTOWNS -I. -I %C_INCLUDE_PATH% %1.c %1.i
if errorlevel 1 goto exit
%GCCROOT%/bin/cc1 -O -quiet -msoft-float %1.i
if errorlevel 1 goto exit
%GCCROOT%/bin/as -o %1.o %1.s
if errorlevel 1 goto exit
%GCCROOT%/bin/ld_towns -N -S -o %1.bin %LIBRARY_PATH%/crt0.o %1.o -L%LIBRARY_PATH% -lTN -lce -lme -lpc 
if errorlevel 1 goto exit
genexp3 %1.bin %1.exp
:exit
