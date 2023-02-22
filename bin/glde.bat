rem ** ソフトウェアによる浮動小数点演算 **
%GCCROOT%/bin/ld_towns -N -S -o %TMP%/_tmp.bin %LIBRARY_PATH%/crt0.o %1.o -L%LIBRARY_PATH% -lTN -lce -lme -lpc 
if errorlevel 1 goto exit
genexp  %1.bin %1.exp
:exit
