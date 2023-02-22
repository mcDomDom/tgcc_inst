@echo off

set INST_DIR=%1

mkdir %INST_DIR%

rem INSTALL.EXE�̏��������s
:INSTALL
rmdir /s /q WK
rmdir /s /q TOWNS
mkdir TOWNS
.\lha32.exe x tgp245_1.lzh WK\
echo binbin�W�J
rem pause

rem dup_source_data
mkdir TOWNS\usr\lib
mkdir TOWNS\usr\bin
mkdir TOWNS\usr\include
mkdir TOWNS\usr\doc
rem TOWNS GAS�E���C�u�����E�C���N���[�h�̓W�J
.\lha32.exe x /r2 gnucd2x1.lzh TOWNS\ usr/lib/*.* usr/include/*.* usr/doc/*.*
.\lha32.exe x gnucd2x1.lzh TOWNS\ usr/bin/gas.exp
rem BAT�t�@�C�����W�J
.\lha32.exe x gnucd2x1.lzh TOWNS\ usr/bin/*.bat
.\lha32.exe x gnucd2s3.lzh TOWNS\usr\
echo gcc cd�W�J
rem pause

rem ajust_source_dir
rmdir /s /q TOWNS\usr\libsrc\bmathemu
echo bmathemu�폜����
rem pause

rem �s�v�t�@�C���̍폜
rem del_waste_file
rem rmdir /s /q TOWNS\usr\bin
del /q TOWNS\usr\libsrc\emuobj\*.a
del /q TOWNS\usr\libsrc\emuobj\*.def
del /q TOWNS\usr\libsrc\emuobj\*.cfg
del /q TOWNS\usr\libsrc\fpuobj\*.a
del /q TOWNS\usr\libsrc\fpuobj\*.def
del /q TOWNS\usr\libsrc\fpuobj\*.cfg
del /q TOWNS\usr\libsrc\emu\cmpdf2.c
del /q TOWNS\usr\libsrc\emu\cmpsf2.c
del /q TOWNS\usr\libsrc\emu\diffs.bat
del /q TOWNS\usr\libsrc\int\bdiv.s
del /q TOWNS\usr\libsrc\int\udivdi3.s
del /q TOWNS\usr\libsrc\libc\bcmp.c
del /q TOWNS\usr\libsrc\libc\bcopy.c
del /q TOWNS\usr\libsrc\libc\bzero.c
del /q TOWNS\usr\libsrc\libc\index.c
del /q TOWNS\usr\libsrc\libc\memchr.c
del /q TOWNS\usr\libsrc\libc\memcmp.c
del /q TOWNS\usr\libsrc\libc\memcpy.c
del /q TOWNS\usr\libsrc\libc\memmove.c
del /q TOWNS\usr\libsrc\libc\memset.c
del /q TOWNS\usr\libsrc\libc\rindex.c
del /q TOWNS\usr\libsrc\libc\strcat.c
del /q TOWNS\usr\libsrc\libc\strchr.c
del /q TOWNS\usr\libsrc\libc\strlen.c
del /q TOWNS\usr\libsrc\libc\strncmp.c
del /q TOWNS\usr\libsrc\libc\strncpy.c
del /q TOWNS\usr\libsrc\libc\strrchr.c
del /q TOWNS\usr\libsrc\libc\strset.c
del /q TOWNS\usr\lib\libgpp.a
del /q TOWNS\usr\lib\libt.a
del /q TOWNS\usr\lib\libme.a
del /q TOWNS\usr\lib\bison.*
del /q TOWNS\usr\readme.*
echo �s�v�t�@�C���폜����
rem pause

rem patch_source_file
.\patch.exe -d TOWNS\usr -p1 <WK\libsrc.dif 
.\patch.exe -d TOWNS\usr -p1 <WK\include.dif 
.\patch.exe -d TOWNS\usr -p1 <WK\doc.dif 
.\patch.exe -d TOWNS\usr -p1 <WK\lib.dif 
echo libsrc/include/doc/lib�p�b�`����
rem libc.a/libce.a�̃p�b�`
.\patch.exe --binary -p1 TOWNS\usr\lib\libc.a  <libc.a.patch
.\patch.exe --binary -p1 TOWNS\usr\lib\libce.a <libce.a.patch
echo libc.a/libce.a�p�b�`����
rem libc/libce�ȊO�̃��C�u����
.\lha32.exe x WK\libbin.lzh TOWNS\usr\lib\
rem TOWNS GCC�{��
.\lha32.exe x WK\binbin.lzh TOWNS\usr\bin\
echo TOWNS���C�u������GCC�{�̓W�J����
rem pause

rem install_gpp
if exist djdev110.zip (
	.\unzip.exe -x djdev110.zip -d WK\ CPLUSINC/*.*
	mkdir TOWNS\usr\include\cc
	copy WK\cplusinc\*.* TOWNS\usr\include\cc
	rmdir /s /q WK\cplusinc
	echo djdev110�W�J����
	rem pause
)
if exist DJLSR110.ZIP (
	.\unzip.exe -x -d TOWNS\usr DJLSR110.ZIP LIBSRC/GPL/*.*
	.\patch.exe -d TOWNS\usr -p1 <WK\libgpp.dif
	echo DJLSR110�W�J����
	rem pause
)
if exist TGP245_2.LZH (
	.\lha32.exe e TGP245_2.LZH TOWNS\usr\bin\
	echo TGP245_2�W�J����
	rem pause
)

echo ���̒i�K��INSTALL�̏����͊���
rem pause

rem TOWNS���C�u�����E�\�[�X ���g�Â��̂�TEST�t�H���_�����W�J
mkdir TOWNS\usr\test 
.\lha32.exe x gnucd2s4.lzh TOWNS\usr\ LIBTOWNS/TEST/*.*
copy /y TOWNS\usr\LIBTOWNS\TEST\*.* TOWNS\usr\test\
rmdir /q /s TOWNS\usr\LIBTOWNS
echo GNU CD��TOWNS���C�u�����E�\�[�X�W�J����
rem pause

rem libtn.lzh����cdplay.c�����Ă���̂ŌÂ����̂��ɓW�J
.\lha32.exe x rlib1.lzh TOWNS\usr\libsrc\ SAMPLE/*.*
copy /y TOWNS\usr\libsrc\SAMPLE\* TOWNS\usr\TEST\
rmdir /q /s TOWNS\usr\libsrc\SAMPLE
echo rlib�̃T���v���W�J����
rem pause

rem TOWNS���C�u�����E�\�[�X�ŐV��
.\lha32.exe x libtn.lzh TOWNS\usr\libsrc\
rem NEW�t�H���_�ȉ��ɏC�����ꂽEGB�֘A�̃\�[�X����̂ŏ㏑��
move /y TOWNS\usr\libsrc\NEW\*.S TOWNS\usr\libsrc\LIB_EGB\
rmdir /q /s TOWNS\usr\libsrc\NEW
move /y TOWNS\usr\libsrc\LIBTN.A TOWNS\usr\LIB\LIBTN.A
del TOWNS\usr\libsrc\LIB_MOS\CDDUMP.*
del TOWNS\usr\libsrc\LIB_MOS\DRAW.C
echo TOWNS���C�u�����E�\�[�X���ŐV�ɍX�V
rem pause

rem �w�b�_�t�@�C����include�Ɉړ�
copy /y TOWNS\usr\libsrc\amathemu\cmath.h TOWNS\usr\include\
move /y TOWNS\usr\libsrc\LIB_MOS\CDR.h TOWNS\usr\include\
move /y TOWNS\usr\libsrc\LIB_MOS\MOS.h TOWNS\usr\include\
move /y TOWNS\usr\libsrc\LIB_SPR\FNT.h TOWNS\usr\include\
move /y TOWNS\usr\libsrc\LIB_SPR\SPR.h TOWNS\usr\include\

rem �T���v���v���O������test�Ɉړ�
move %INST_DIR%\libsrc\LIB_MOS\cddump.c TOWNS\usr\test\
move %INST_DIR%\libsrc\LIB_MOS\cdplay.* TOWNS\usr\test\
move %INST_DIR%\libsrc\LIB_MOS\draw.c   TOWNS\usr\test\

rem EGB High-C�݊��������߂邽�߂̒ǉ��w�b�_�t�@�C��
.\lha32.exe x egb.lzh WK\
rem egb.h������egb.h�̐擪�ɒǉ�����
copy WK\egb.h+egb.h TOWNS\usr\include\egb.h

rem ���A�����[�hBIOS�p���C�u����
.\lha32.exe x libsys.lzh TOWNS\usr\libsrc\
move /y TOWNS\usr\libsrc\libsys.a TOWNS\usr\lib\

rem MOS/SND���C�u����
.\lha32.exe x sndlib.lzh TOWNS\usr\libsrc\LIB_MOS\
move /y TOWNS\usr\libsrc\LIB_MOS\SNDTST.* TOWNS\usr\TEST\
rem SND High-C�݊��������߂邽�߂̒ǉ��w�b�_�t�@�C��
.\lha32.exe x snd.lzh WK\
rem snd.h�����ɂ���snd.h�̐擪�ɒǉ�����
copy /y WK\snd.h+TOWNS\usr\libsrc\LIB_MOS\SND.h TOWNS\usr\include\snd.h
del TOWNS\usr\libsrc\LIB_MOS\SND.h
move /y TOWNS\usr\libsrc\LIB_MOS\MOS.h TOWNS\usr\include\

rem libTN.a���̃t�@�C����sndlib��.o�t�@�C���ōX�V
.\bin\ar rvs towns\usr\lib\LIBTN.A towns\usr\LIBSRC\LIB_MOS\*.o --target=a.out-i386

rem MALLOC�𖳑ʌ������Ȃ��łɒu������
.\lha32.exe x tgpalloc.lzh TOWNS\usr\LIBSRC\LIBC\
rem .\bin\ar rvs towns\usr\lib\libc.a  towns\usr\LIBSRC\LIBC\malloc.o --target=a.out-i386
rem .\bin\ar rvs towns\usr\lib\libce.a towns\usr\LIBSRC\LIBC\malloc.o --target=a.out-i386

rem GCC��2.7.2�ɍX�V
.\lha32.exe x gcc272.lzh TOWNS\usr\bin\
move /y TOWNS\usr\bin\LIBGCC.A TOWNS\usr\lib\
echo gnu-cc.cfg��-lgccpu -msoft-float -mno-fp-ret-in-387��ǉ�����

rem nlink.exp��W�J
.\lha32.exe x nk213.lzh TOWNS\usr\bin\

rem genexp��genexp3�ɕύX�����o�b�`�t�@�C�����R�s�[
copy /y towns_bin\* TOWNS\usr\bin\

rem �e��h�L�������g��DOC�t�H���_�Ɉړ�
move TOWNS\usr\LIBSRC\SYSINFO.DOC         TOWNS\usr\doc\
move TOWNS\usr\LIBSRC\LIB_EGB\README.DOC  TOWNS\usr\doc\LIB_EGB.DOC
move TOWNS\usr\LIBSRC\LIB_EGB\LIBT.DOC    TOWNS\usr\doc\
move TOWNS\usr\LIBSRC\LIB_IO\LIBIO.DOC    TOWNS\usr\doc\
move TOWNS\usr\LIBSRC\LIB_MOS\CDR.DOC     TOWNS\usr\doc\
move TOWNS\usr\LIBSRC\LIB_MOS\KYB.DOC     TOWNS\usr\doc\
move TOWNS\usr\LIBSRC\LIB_MOS\MOS.DOC     TOWNS\usr\doc\
move TOWNS\usr\LIBSRC\LIB_MOS\README.DOC  TOWNS\usr\doc\LIB_MOS.DOC
move TOWNS\usr\LIBSRC\LIB_MOS\SND.DOC     TOWNS\usr\doc\
move TOWNS\usr\LIBSRC\LIB_SPR\BIOS.DOC    TOWNS\usr\doc\
move TOWNS\usr\LIBSRC\LIBC\README.DOC     TOWNS\usr\doc\MALLOC.DOC
move TOWNS\usr\LIBSRC\AMATHEMU\README.DOC TOWNS\usr\doc\AMATHEMU.DOC
move TOWNS\usr\LIBSRC\MATHFPU\MATH.DOC    TOWNS\usr\doc\
echo �����܂ł�TOWNS��GCC�̊��\�z����
rem pause

echo �N���X�R���p�C�����̍\�z
rem TOWNS��GCC�̒��g��S�R�s�[
xcopy /sy TOWNS\usr\* %INST_DIR%\
rem �S�t�@�C�����������ϊ�
for /R %INST_DIR% %%i in (*) do call :makelower %%i
echo �������ϊ��I��
rem pause

rem djgpp_v2����K�v�ȃt�@�C���̂݃R�s�[
rmdir /s /q %INST_DIR%\bin
mkdir %INST_DIR%\bin\
rmdir /s /q djgpp_v2
.\7za.exe x djgpp_v2_gcc2723_djgppv201_01_01_2020.7z djgpp_v2/env.cmd djgpp_v2/bin
copy /y djgpp_v2\env.cmd %INST_DIR%\
copy /y djgpp_v2\bin\cc1.exe %INST_DIR%\bin\
copy /y djgpp_v2\bin\cpp.exe %INST_DIR%\bin\
copy /y djgpp_v2\bin\gcc.exe %INST_DIR%\bin\
copy /y djgpp_v2\bin\make.exe %INST_DIR%\bin\
copy /y djgpp_v2\bin\touch.exe %INST_DIR%\bin\
copy /y djgpp_v2\bin\*.dll %INST_DIR%\bin\
rem i386-aout�Ή��̃��W���[�����㏑���R�s�[
copy /y bin\* %INST_DIR%\bin\

rem djgpp_v2�N���p�o�b�`�t�@�C��
copy /y tgcc.cmd %INST_DIR%\
type envadd.txt >> %INST_DIR%\env.cmd

echo �C���X�g�[�����������܂���
echo �N���X�R���p�C�������N������ɂ̓G�N�X�v���[���[����
echo %INST_DIR%\tgcc.cmd �����s���Ă�������
pause
exit /b

rem 
:makelower
set file=%1
set str=%1
for %%i in (a b c d e f g h i j k l m n o p q r s t u v w x y z) ^
do call set str=%%str:%%i=%%i%%
move "%1" "%str%"
