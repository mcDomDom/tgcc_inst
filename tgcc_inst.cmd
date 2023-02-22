@echo off

set INST_DIR=%1

mkdir %INST_DIR%

rem INSTALL.EXEの処理を実行
:INSTALL
rmdir /s /q WK
rmdir /s /q TOWNS
mkdir TOWNS
.\lha32.exe x tgp245_1.lzh WK\
echo binbin展開
rem pause

rem dup_source_data
mkdir TOWNS\usr\lib
mkdir TOWNS\usr\bin
mkdir TOWNS\usr\include
mkdir TOWNS\usr\doc
rem TOWNS GAS・ライブラリ・インクルードの展開
.\lha32.exe x /r2 gnucd2x1.lzh TOWNS\ usr/lib/*.* usr/include/*.* usr/doc/*.*
.\lha32.exe x gnucd2x1.lzh TOWNS\ usr/bin/gas.exp
rem BATファイルも展開
.\lha32.exe x gnucd2x1.lzh TOWNS\ usr/bin/*.bat
.\lha32.exe x gnucd2s3.lzh TOWNS\usr\
echo gcc cd展開
rem pause

rem ajust_source_dir
rmdir /s /q TOWNS\usr\libsrc\bmathemu
echo bmathemu削除完了
rem pause

rem 不要ファイルの削除
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
echo 不要ファイル削除完了
rem pause

rem patch_source_file
.\patch.exe -d TOWNS\usr -p1 <WK\libsrc.dif 
.\patch.exe -d TOWNS\usr -p1 <WK\include.dif 
.\patch.exe -d TOWNS\usr -p1 <WK\doc.dif 
.\patch.exe -d TOWNS\usr -p1 <WK\lib.dif 
echo libsrc/include/doc/libパッチ完了
rem libc.a/libce.aのパッチ
.\patch.exe --binary -p1 TOWNS\usr\lib\libc.a  <libc.a.patch
.\patch.exe --binary -p1 TOWNS\usr\lib\libce.a <libce.a.patch
echo libc.a/libce.aパッチ完了
rem libc/libce以外のライブラリ
.\lha32.exe x WK\libbin.lzh TOWNS\usr\lib\
rem TOWNS GCC本体
.\lha32.exe x WK\binbin.lzh TOWNS\usr\bin\
echo TOWNSライブラリとGCC本体展開完了
rem pause

rem install_gpp
if exist djdev110.zip (
	.\unzip.exe -x djdev110.zip -d WK\ CPLUSINC/*.*
	mkdir TOWNS\usr\include\cc
	copy WK\cplusinc\*.* TOWNS\usr\include\cc
	rmdir /s /q WK\cplusinc
	echo djdev110展開完了
	rem pause
)
if exist DJLSR110.ZIP (
	.\unzip.exe -x -d TOWNS\usr DJLSR110.ZIP LIBSRC/GPL/*.*
	.\patch.exe -d TOWNS\usr -p1 <WK\libgpp.dif
	echo DJLSR110展開完了
	rem pause
)
if exist TGP245_2.LZH (
	.\lha32.exe e TGP245_2.LZH TOWNS\usr\bin\
	echo TGP245_2展開完了
	rem pause
)

echo この段階でINSTALLの処理は完了
rem pause

rem TOWNSライブラリ・ソース 中身古いのでTESTフォルダだけ展開
mkdir TOWNS\usr\test 
.\lha32.exe x gnucd2s4.lzh TOWNS\usr\ LIBTOWNS/TEST/*.*
copy /y TOWNS\usr\LIBTOWNS\TEST\*.* TOWNS\usr\test\
rmdir /q /s TOWNS\usr\LIBTOWNS
echo GNU CDのTOWNSライブラリ・ソース展開完了
rem pause

rem libtn.lzh内のcdplay.c等壊れているので古いものを先に展開
.\lha32.exe x rlib1.lzh TOWNS\usr\libsrc\ SAMPLE/*.*
copy /y TOWNS\usr\libsrc\SAMPLE\* TOWNS\usr\TEST\
rmdir /q /s TOWNS\usr\libsrc\SAMPLE
echo rlibのサンプル展開完了
rem pause

rem TOWNSライブラリ・ソース最新版
.\lha32.exe x libtn.lzh TOWNS\usr\libsrc\
rem NEWフォルダ以下に修正されたEGB関連のソースあるので上書き
move /y TOWNS\usr\libsrc\NEW\*.S TOWNS\usr\libsrc\LIB_EGB\
rmdir /q /s TOWNS\usr\libsrc\NEW
move /y TOWNS\usr\libsrc\LIBTN.A TOWNS\usr\LIB\LIBTN.A
del TOWNS\usr\libsrc\LIB_MOS\CDDUMP.*
del TOWNS\usr\libsrc\LIB_MOS\DRAW.C
echo TOWNSライブラリ・ソースを最新に更新
rem pause

rem ヘッダファイルをincludeに移動
copy /y TOWNS\usr\libsrc\amathemu\cmath.h TOWNS\usr\include\
move /y TOWNS\usr\libsrc\LIB_MOS\CDR.h TOWNS\usr\include\
move /y TOWNS\usr\libsrc\LIB_MOS\MOS.h TOWNS\usr\include\
move /y TOWNS\usr\libsrc\LIB_SPR\FNT.h TOWNS\usr\include\
move /y TOWNS\usr\libsrc\LIB_SPR\SPR.h TOWNS\usr\include\

rem サンプルプログラムをtestに移動
move %INST_DIR%\libsrc\LIB_MOS\cddump.c TOWNS\usr\test\
move %INST_DIR%\libsrc\LIB_MOS\cdplay.* TOWNS\usr\test\
move %INST_DIR%\libsrc\LIB_MOS\draw.c   TOWNS\usr\test\

rem EGB High-C互換性を高めるための追加ヘッダファイル
.\lha32.exe x egb.lzh WK\
rem egb.hを自作egb.hの先頭に追加する
copy WK\egb.h+egb.h TOWNS\usr\include\egb.h

rem リアルモードBIOS用ライブラリ
.\lha32.exe x libsys.lzh TOWNS\usr\libsrc\
move /y TOWNS\usr\libsrc\libsys.a TOWNS\usr\lib\

rem MOS/SNDライブラリ
.\lha32.exe x sndlib.lzh TOWNS\usr\libsrc\LIB_MOS\
move /y TOWNS\usr\libsrc\LIB_MOS\SNDTST.* TOWNS\usr\TEST\
rem SND High-C互換性を高めるための追加ヘッダファイル
.\lha32.exe x snd.lzh WK\
rem snd.hを既にあるsnd.hの先頭に追加する
copy /y WK\snd.h+TOWNS\usr\libsrc\LIB_MOS\SND.h TOWNS\usr\include\snd.h
del TOWNS\usr\libsrc\LIB_MOS\SND.h
move /y TOWNS\usr\libsrc\LIB_MOS\MOS.h TOWNS\usr\include\

rem libTN.a内のファイルをsndlibの.oファイルで更新
.\bin\ar rvs towns\usr\lib\LIBTN.A towns\usr\LIBSRC\LIB_MOS\*.o --target=a.out-i386

rem MALLOCを無駄遣いしない版に置き換え
.\lha32.exe x tgpalloc.lzh TOWNS\usr\LIBSRC\LIBC\
rem .\bin\ar rvs towns\usr\lib\libc.a  towns\usr\LIBSRC\LIBC\malloc.o --target=a.out-i386
rem .\bin\ar rvs towns\usr\lib\libce.a towns\usr\LIBSRC\LIBC\malloc.o --target=a.out-i386

rem GCCを2.7.2に更新
.\lha32.exe x gcc272.lzh TOWNS\usr\bin\
move /y TOWNS\usr\bin\LIBGCC.A TOWNS\usr\lib\
echo gnu-cc.cfgに-lgccpu -msoft-float -mno-fp-ret-in-387を追加する

rem nlink.expを展開
.\lha32.exe x nk213.lzh TOWNS\usr\bin\

rem genexpをgenexp3に変更したバッチファイルをコピー
copy /y towns_bin\* TOWNS\usr\bin\

rem 各種ドキュメントをDOCフォルダに移動
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
echo ここまででTOWNS版GCCの環境構築完了
rem pause

echo クロスコンパイル環境の構築
rem TOWNS版GCCの中身を全コピー
xcopy /sy TOWNS\usr\* %INST_DIR%\
rem 全ファイル名小文字変換
for /R %INST_DIR% %%i in (*) do call :makelower %%i
echo 小文字変換終了
rem pause

rem djgpp_v2から必要なファイルのみコピー
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
rem i386-aout対応のモジュールを上書きコピー
copy /y bin\* %INST_DIR%\bin\

rem djgpp_v2起動用バッチファイル
copy /y tgcc.cmd %INST_DIR%\
type envadd.txt >> %INST_DIR%\env.cmd

echo インストールが完了しました
echo クロスコンパイル環境を起動するにはエクスプローラーから
echo %INST_DIR%\tgcc.cmd を実行してください
pause
exit /b

rem 
:makelower
set file=%1
set str=%1
for %%i in (a b c d e f g h i j k l m n o p q r s t u v w x y z) ^
do call set str=%%str:%%i=%%i%%
move "%1" "%str%"
