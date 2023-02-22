TOWNS-gcc クロスコンパイル環境

あにくん様のTOWNS-gpp(TOWNS-gcc)非公式ページ
(http://anikun.kutami.jp/towns-gcc/)で公開されている
TOWNS-gccを利用したWindowsクロスコンパイル環境です。
Windws上でTOWNS OSで動作するexpファイルを作成できます。
※オリジナルと異なり、g++は使用できません。
TOWNS-gpp (TOWNS-gcc) の著作権はそれぞれを作成した作者に帰属します。

【インストール手順】
1.Windows上で動作するgccコンパイラとして
  Jason Stevens様のdjgpp_v2を利用しています。
  下記リンクよりdjgpp_v2_gcc2723_djgppv201_01_01_2020.7zを
  tgcc_inst.cmdと同フォルダ内に保存してください。(展開は不要です)
  https://sourceforge.net/projects/crossdjgppv2/files/latest/download

2.lzhファイルの展開用にLHA32.exeが必要になります。
  vectorよりLHA32をダウンロードし、1.と同じフォルダにLHA32.exeを配置してください。
  https://www.vector.co.jp/soft/win95/util/se347175.html
  ※ダウンロードされるlha267.exeはLHA自己展開書庫なのですが、
    Win16アプリのようで64bit版Windowsでは展開できません。
    WinRAR等で展開してください。

3.コマンドプロンプトよりフォルダ内の下記バッチファイルを実行してください。
  tgcc_inst.cmd インストール先
  ※インストール先末尾には\を付与しないでください。

  例. tgcc_inst.cmd c:\tgcc
  
4.インストールが完了するとコマンドプロンプトに
  「インストールが完了しました」のメッセージが表示されます。

【実行手順】
インストール先フォルダにあるtgcc.cmdファイルを実行するか、
コマンドプロンプトからenv.cmdを実行してください。

testフォルダ内には各ライブラリのサンプルソースを集めています。
tbld draw等でexpファイルをビルドできます。

簡単コンパイル用に元々TOWNS GCCにあった下記バッチファイルを用意してあります。
gcce.bat コンパイルのみ ソフトウェアによる浮動小数点演算
gccf.bat コンパイルのみ FPUによる浮動小数点演算
glde.bat リンクのみ ソフトウェアによる浮動小数点演算(libce/libmeをリンク)
gldf.bat リンクのみ FPUによる浮動小数点演算(libc/libmをリンク)
gcle.bat コンパイル＆リンク ソフトウェアによる浮動小数点演算
gclf.bat コンパイル＆リンク ソフトウェアによる浮動小数点演算

クロスコンパイル環境では下記バッチファイルも用意してあります。
tcc.cmd コンパイルのみ ソフトウェアによる浮動小数点演算
tld.cmd リンクのみ ソフトウェアによる浮動小数点演算(libce/libmeをリンク)
tbld.cmd コンパイル＆リンク ソフトウェアによる浮動小数点演算

【補足】
構築される環境は非公式ページで公開されている最新版のGCCコンパイラと
TOWNS専用ライブラリ(libtn.lzh)、
リアルモードBIOS用ライブラリ(libsys.lzh)
メモリを無駄に使用しないmalloc(tgpalloc.lzh)等を
組み込んだ環境となります。
libtn.aには最新版のsndlib.lzh内のオブジェクトを組み込み済です。
また、egb.hのヘッダファイルも用意しました。
元の構成ではライブラリのドキュメントが各ライブラリのソースフォルダに
散らばっていたので、docフォルダにまとめてあります。
サンプルソースのdraw.cとegbtest.cで動作確認しましたが、
他の機能や大規模なソースでの動作は未検証です。

インストールが完了するとインストール元フォルダ内にTOWNSフォルダが
作製されますが、このフォルダ内のUSR以下をTOWNS実機や津軽等に持っていくと
そのままTOWNS-gccが動作します。
こちらではg++使用可能です。

・.cソースから.expファイル生成の流れは以下の通り
1.djgpp_v2のgccコンパイラで.cソースからgas用の.sソースを生成
2.i386-linux-aout対応させたas-new.exeで.sソースから.oを生成
3.ld_townsで.oをcrt0.oやライブラリとリンクし、.binを生成
4.genexp3で.binからexp形式を生成

・djgpp_v2のGCCコンパイラは2.7.2.3と古いですが、ここらへんのバージョンでないと
  出力されるアセンブラコードに余計なスタートアップコードが追加されてしまいます。

・binフォルダ以下のバイナリ(as-new等)はMinGW環境(https://sourceforge.net/projects/mingw/)にて
  binutils-2.25.1を下記手順で作成しました。
  ./configure --host=i686-pc-mingw32 --build=i686-pc-mingw32 --target=i386-linux-aout --enable-targets=i386-linux-elf,i386-coff,i386-aout
  make -j12
  →as-new.exe等末尾に-newが付いているものは-newを除去した名前にリネームしました。

・ld_townsはTOWNS用GNU CDのTOWNS\BINUTYのLD関連ソースをもとにVisual Studio 2010でビルドしました。
  何故かオリジナルと異なるファイルが生成される現象が発生したので若干変更しています。

・genexp3はTOWNS用GNU CDのTOWNS\BETA_REL\GCCTOOLのソースを少し変更し、Visual Studio 2010でビルドしました。


【動作確認環境】
Windows 10 Professional 64bit 21H2
たぶんWindows 7以降の64bit/32bit版Windowsで動作すると思います。

【最後に】
X68000にはよっしん様が作成されたクロス開発環境 xdev68k があり、いいなぁと思っていましたが
TOWNSにもあにくん様がアーカイブを保持し続けていただいたTOWNS-gccがあり、
何とかWindows環境でも利用できないか試行錯誤しての結果です。
アーカイブの配布を許可いただいたあにくん様、
30数年にTOWNS-gccを整備された方々、
FM TOWNSエミュレータ津軽を開発された山川機長様、
djgpp_v2を公開していただいたJason Stevens様、
その他多くのフリーソフトウェア作者様に感謝いたします。

どむやま
