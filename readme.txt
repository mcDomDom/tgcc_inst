TOWNS-gcc �N���X�R���p�C����

���ɂ���l��TOWNS-gpp(TOWNS-gcc)������y�[�W
(http://anikun.kutami.jp/towns-gcc/)�Ō��J����Ă���
TOWNS-gcc�𗘗p����Windows�N���X�R���p�C�����ł��B
Windws���TOWNS OS�œ��삷��exp�t�@�C�����쐬�ł��܂��B
���I���W�i���ƈقȂ�Ag++�͎g�p�ł��܂���B
TOWNS-gpp (TOWNS-gcc) �̒��쌠�͂��ꂼ����쐬������҂ɋA�����܂��B

�y�C���X�g�[���菇�z
1.Windows��œ��삷��gcc�R���p�C���Ƃ���
  Jason Stevens�l��djgpp_v2�𗘗p���Ă��܂��B
  ���L�����N���djgpp_v2_gcc2723_djgppv201_01_01_2020.7z��
  tgcc_inst.cmd�Ɠ��t�H���_���ɕۑ����Ă��������B(�W�J�͕s�v�ł�)
  https://sourceforge.net/projects/crossdjgppv2/files/latest/download

2.lzh�t�@�C���̓W�J�p��LHA32.exe���K�v�ɂȂ�܂��B
  vector���LHA32���_�E�����[�h���A1.�Ɠ����t�H���_��LHA32.exe��z�u���Ă��������B
  https://www.vector.co.jp/soft/win95/util/se347175.html
  ���_�E�����[�h�����lha267.exe��LHA���ȓW�J���ɂȂ̂ł����A
    Win16�A�v���̂悤��64bit��Windows�ł͓W�J�ł��܂���B
    WinRAR���œW�J���Ă��������B

3.�R�}���h�v�����v�g���t�H���_���̉��L�o�b�`�t�@�C�������s���Ă��������B
  tgcc_inst.cmd �C���X�g�[����
  ���C���X�g�[���斖���ɂ�\��t�^���Ȃ��ł��������B

  ��. tgcc_inst.cmd c:\tgcc
  
4.�C���X�g�[������������ƃR�}���h�v�����v�g��
  �u�C���X�g�[�����������܂����v�̃��b�Z�[�W���\������܂��B

�y���s�菇�z
�C���X�g�[����t�H���_�ɂ���tgcc.cmd�t�@�C�������s���邩�A
�R�}���h�v�����v�g����env.cmd�����s���Ă��������B

test�t�H���_���ɂ͊e���C�u�����̃T���v���\�[�X���W�߂Ă��܂��B
tbld draw����exp�t�@�C�����r���h�ł��܂��B

�ȒP�R���p�C���p�Ɍ��XTOWNS GCC�ɂ��������L�o�b�`�t�@�C����p�ӂ��Ă���܂��B
gcce.bat �R���p�C���̂� �\�t�g�E�F�A�ɂ�镂�������_���Z
gccf.bat �R���p�C���̂� FPU�ɂ�镂�������_���Z
glde.bat �����N�̂� �\�t�g�E�F�A�ɂ�镂�������_���Z(libce/libme�������N)
gldf.bat �����N�̂� FPU�ɂ�镂�������_���Z(libc/libm�������N)
gcle.bat �R���p�C���������N �\�t�g�E�F�A�ɂ�镂�������_���Z
gclf.bat �R���p�C���������N �\�t�g�E�F�A�ɂ�镂�������_���Z

�N���X�R���p�C�����ł͉��L�o�b�`�t�@�C�����p�ӂ��Ă���܂��B
tcc.cmd �R���p�C���̂� �\�t�g�E�F�A�ɂ�镂�������_���Z
tld.cmd �����N�̂� �\�t�g�E�F�A�ɂ�镂�������_���Z(libce/libme�������N)
tbld.cmd �R���p�C���������N �\�t�g�E�F�A�ɂ�镂�������_���Z

�y�⑫�z
�\�z�������͔�����y�[�W�Ō��J����Ă���ŐV�ł�GCC�R���p�C����
TOWNS��p���C�u����(libtn.lzh)�A
���A�����[�hBIOS�p���C�u����(libsys.lzh)
�������𖳑ʂɎg�p���Ȃ�malloc(tgpalloc.lzh)����
�g�ݍ��񂾊��ƂȂ�܂��B
libtn.a�ɂ͍ŐV�ł�sndlib.lzh���̃I�u�W�F�N�g��g�ݍ��ݍςł��B
�܂��Aegb.h�̃w�b�_�t�@�C�����p�ӂ��܂����B
���̍\���ł̓��C�u�����̃h�L�������g���e���C�u�����̃\�[�X�t�H���_��
�U��΂��Ă����̂ŁAdoc�t�H���_�ɂ܂Ƃ߂Ă���܂��B
�T���v���\�[�X��draw.c��egbtest.c�œ���m�F���܂������A
���̋@�\���K�͂ȃ\�[�X�ł̓���͖����؂ł��B

�C���X�g�[������������ƃC���X�g�[�����t�H���_����TOWNS�t�H���_��
�쐻����܂����A���̃t�H���_����USR�ȉ���TOWNS���@��Ìy���Ɏ����Ă�����
���̂܂�TOWNS-gcc�����삵�܂��B
������ł�g++�g�p�\�ł��B

�E.c�\�[�X����.exp�t�@�C�������̗���͈ȉ��̒ʂ�
1.djgpp_v2��gcc�R���p�C����.c�\�[�X����gas�p��.s�\�[�X�𐶐�
2.i386-linux-aout�Ή�������as-new.exe��.s�\�[�X����.o�𐶐�
3.ld_towns��.o��crt0.o�⃉�C�u�����ƃ����N���A.bin�𐶐�
4.genexp3��.bin����exp�`���𐶐�

�Edjgpp_v2��GCC�R���p�C����2.7.2.3�ƌÂ��ł����A������ւ�̃o�[�W�����łȂ���
  �o�͂����A�Z���u���R�[�h�ɗ]�v�ȃX�^�[�g�A�b�v�R�[�h���ǉ�����Ă��܂��܂��B

�Ebin�t�H���_�ȉ��̃o�C�i��(as-new��)��MinGW��(https://sourceforge.net/projects/mingw/)�ɂ�
  binutils-2.25.1�����L�菇�ō쐬���܂����B
  ./configure --host=i686-pc-mingw32 --build=i686-pc-mingw32 --target=i386-linux-aout --enable-targets=i386-linux-elf,i386-coff,i386-aout
  make -j12
  ��as-new.exe��������-new���t���Ă�����̂�-new�������������O�Ƀ��l�[�����܂����B

�Eld_towns��TOWNS�pGNU CD��TOWNS\BINUTY��LD�֘A�\�[�X�����Ƃ�Visual Studio 2010�Ńr���h���܂����B
  ���̂��I���W�i���ƈقȂ�t�@�C������������錻�ۂ����������̂Ŏ኱�ύX���Ă��܂��B

�Egenexp3��TOWNS�pGNU CD��TOWNS\BETA_REL\GCCTOOL�̃\�[�X�������ύX���AVisual Studio 2010�Ńr���h���܂����B


�y����m�F���z
Windows 10 Professional 64bit 21H2
���Ԃ�Windows 7�ȍ~��64bit/32bit��Windows�œ��삷��Ǝv���܂��B

�y�Ō�Ɂz
X68000�ɂ͂������l���쐬���ꂽ�N���X�J���� xdev68k ������A�����Ȃ��Ǝv���Ă��܂�����
TOWNS�ɂ����ɂ���l���A�[�J�C�u��ێ��������Ă���������TOWNS-gcc������A
���Ƃ�Windows���ł����p�ł��Ȃ������s���낵�Ă̌��ʂł��B
�A�[�J�C�u�̔z�z�����������������ɂ���l�A
30���N��TOWNS-gcc�𐮔����ꂽ���X�A
FM TOWNS�G�~�����[�^�Ìy���J�����ꂽ�R��@���l�A
djgpp_v2�����J���Ă���������Jason Stevens�l�A
���̑������̃t���[�\�t�g�E�F�A��җl�Ɋ��ӂ������܂��B

�ǂނ��
