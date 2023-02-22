rem ** ソフトウェアによる浮動小数点演算 **
%GCCROOT%/bin/cpp  -D__GNUC__ -DTOWNS -I. -I %C_INCLUDE_PATH% %1.c %1.i
if errorlevel 1 goto exit
%GCCROOT%/bin/cc1 -O -quiet -msoft-float %1.i
if errorlevel 1 goto exit
%GCCROOT%/bin/as -o %1.o %1.s
:exit
