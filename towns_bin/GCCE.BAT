rem ** ソフトウェアによる浮動小数点演算 **
run386 -nocrt %GCCROOT%/usr/bin/cpp  -D__GNUC__ -DTOWNS -I. -I %GCCROOT%/usr/include %1.c %1.i
if errorlevel 1 goto exit
run386 -nocrt %GCCROOT%/usr/bin/cc1 -O -quiet -msoft-float %1.i
if errorlevel 1 goto exit
run386 -nocrt %GCCROOT%/usr/bin/gas -o %1.o %1.s
:exit
