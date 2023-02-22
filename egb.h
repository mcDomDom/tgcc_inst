/*
�� TOWNS�pGCC���C�u���� ------ �O���t�C�b�NBIOS��


(1)EGB BIOS�R�[���֐�
   � ����*���t���Ă���ȊO�́AHigh-C�̃��C�u�����ƌ݊�� �݊����C�u������
     T-BIOS�̃R�[���ƈ�Έ�Ή����Ă���B�֐��̌��[���l]�́CT-BIOS�̃t�@��
     �N�V�����ԍ�(AH���W�X�^�ɐݒ肷��l,16�i)�ł���B
*/

/*
	egb_s1.OBJGPP
	(setup operation);
*/

/* �O���t�B�b�NBIOS�̏����� [00]	*/
int	EGB_init( char *w, int size);

	
/*	��ʃ��[�h�̐ݒ� [01]	*/
int	EGB_resolution( char *w, int page, int mode );

/*	���zRAM��ʃ��[�h�̐ݒ� */
int	EGB_resolutionRAM( char *w, int page, int pixel, int width, int height, char *ram );

/*	�\���J�n�ʒu�̐ݒ� [02]	*/
int	EGB_displayStart( char *w, int mode, int x, int y );

/*	�\����ʂ̉�ʘg���̈ړ� High-C���C�u������݊� [02]	*/
int	EGB_displayOffset( char *w, int sx, int sy );

/*	VRAM���̕\���̈�̊J�n���W High-C���C�u������݊� [02]	*/
int	EGB_screenOffset( char *w, int sx, int sy );

/*	��ʂ̊g�� High-C���C�u������݊� [02]	*/
int	EGB_screenZoom( char *w, int wx, int wy );

/*	��ʂ̑傫���ݒ� High-C���C�u������݊� [02]	*/
int	EGB_screenWidth( char *w, int wx, int wy );

/*	�r���[�|�[�g�ݒ�  [03]	*/
int	EGB_viewport( char *w, char *param );

/*	�r���[�|�[�g�ݒ� High-C���C�u������݊�  [03]	*/
int	EGB_viewportRect( char *w, int sx, int sy, int ex, int ey );

/*	�p���b�g�̐ݒ�  [04]	*/
int	EGB_palette( char *w, int syncf, char *param );

/*	1�̃p���b�g�ݒ� High-C���C�u������݊�  [04]	*/
int	EGB_setPalette( char *w, int num, int g, int r, int b );

/*	�������݃y�[�W�̐ݒ�  [05]	*/
int	EGB_writePage( char *w, int page );

/*	�\���y�[�W�̐ݒ�  [06]	*/
int	EGB_displayPage( char *w, int prior, int page );

/*
	egb_s2.o
*/
/*	�`��F�̐ݒ�(�p���b�g�R�[�h) [07]	*/
int	EGB_color( char *w, int mode, int color );
/*	�O�i�F�̐ݒ�(�p���b�g�R�[�h) High-C���C�u������݊� [07]	*/
int	EGB_foreColor( char *w, int col );
/*	�w�i�F�̐ݒ�(�p���b�g�R�[�h) High-C���C�u������݊� [07]	*/
int	EGB_backColor( char *w, int col );
/*	�ʓh��F�̐ݒ�(�p���b�g�R�[�h) High-C���C�u������݊� [07]	*/
int	EGB_paintColor( char *w, int col );
/*	���ߐF�̐ݒ�(�p���b�g�R�[�h) High-C���C�u������݊� [07]	*/
int	EGB_transColor( char *w, int col );
/*	�`��F�̐ݒ�(IGRB�R�[�h) [08]	*/
int	EGB_colorIGRB( char *w, int mode, int col );
/*	�O�i�F�̐ݒ�(IGRB�R�[�h) High-C���C�u������݊� [08]	*/
int	EGB_foreColorIGRB( char *w, int col );
/*	�w�i�F�̐ݒ�(IGRB�R�[�h) High-C���C�u������݊� [08]	*/
int	EGB_backColorIGRB( char *w, int col );
/*	�ʓh��F�̐ݒ�(IGRB�R�[�h) High-C���C�u������݊� [08]	*/
int	EGB_paintColorIGRB( char *w, int col );
/*	���ߐF�̐ݒ�(IGRB�R�[�h) High-C���C�u������݊� [08]	*/
int	EGB_transColorIGRB( char *w, int col );
/*	Pastel���[�h�`��̍��F�� [09]	*/
int	EGB_pastel( char *w, int level );
/*	�`�惂�[�h�̐ݒ�   [0A]	*/
int	EGB_writeMode( int mode );

/*
	egb_s3.o
*/
/*	�����p�^�[���̐ݒ� [0B]	*/
int	EGB_linePattern( char *w, int mode, int  pattern );
/*	�y�C���g���[�h�̐ݒ�  [0C]	*/
int	EGB_paintMode( char *w, int mode );
/*	�n�b�`���O�p�^�[���ݒ� [0D]	*/
int	EGB_hatchingPattern( char *w, int mode, int x, int y, char *pat );
/*	�^�C���p�^�[���ݒ� [0E]	*/
int	EGB_tilePattern( char *w, int mode, int x, int y, char *pat );
/*	��ʃ}�X�N�̈�̐ݒ�  [0F]	*/
int	EGB_maskRegion( char *w,char *pat );
/*	�}�X�N���[�h�̐ݒ�  [10]	*/
int	EGB_mask( char *w, int mode );
/*	�}�X�N�r�b�g�̐ݒ� [14]	*/
int	EGB_maskBit( char *w, int bit );

/*
egb_s4.o
*/
/*	�`��y���̃��[�h�ݒ� [11]	*/
int	EGB_pen( char *w, int penmode );
/*	�`��y���̑����ݒ� [12]	*/
int	EGB_penSize( char *w, int pensize );
/*	�`��y���`���`  [13]	*/
int	EGB_penStyle( char *w, char *pattern );

/*
egb_s5.o
*/
/*	���������̐ݒ� [15]	*/
int	EGB_textDirection( char *w, int dir );
/*	�����\�������̐ݒ� [16]	*/
int	EGB_textDisplayDirection( char *w, int dir );
/*	�����ԋ󔒂̐ݒ� [17]	*/
int	EGB_textSpace( char *w, int space );
/*	�����g�嗦�̐ݒ� [18]	*/
int	EGB_textZoom( char *w, int mode, int  x, int  y );
/*	���̂̐ݒ� [19]	*/
int	EGB_fontStyle( char *w, int style);
/*	���������̈ꊇ�ݒ� High-C���C�u������݊� [**]	*/
int	EGB_textAttrib( char *w, int mx, int my, int style, int dir, int ddir, int space );
/*	�X�[�p�[�C���|�[�Y [1A]	*/
int	EGB_superImpose( char *w, int mode );
/*	�f�B�W�^�C�Y  [1B]	*/
int	EGB_digitize( char *w, int mode);

/*
	(block operation);
	egb_b1.o
*/
/*	VRAM�̈�̏��� [20]	*/
int	EGB_clearScreen( char *w );
/*	�r���[�|�[�g�̈�̏��� [21]	*/
int	EGB_partClearScreen( char *w );
/*	VRAM�̃_�C���N�g�[���N���A High-C���C�u������݊� [**]	*/
int	EGB_clearVRAM( int page );

/*
	egb_b2.o
*/
/*	��`�̈�ǂ݂���(�F�w��) [22]	*/
int	EGB_getBlockColor( char *w, char *param );
/*	��`�̈揑������(�F�w��) [23]	*/
int	EGB_putBlockColor( char *w, int clip, char *param );
/*	��`�̈�ǂ݂���(�t���J���[) [24]	*/
int	EGB_getBlock( char *w, char *param );
/*	��`�̈揑������(�t���J���[) [25]	*/
int	EGB_putBlock( char *w, int clip, char *param );
/*	��`�̈�ǂ݂���(�Y�[���t) [26]	*/
int	EGB_getBlockZoom( char *w, char *param );
/*	��`�̈揑������(�Y�[���t) [27]	*/
int	EGB_putBlockZoom( char *w, int clip, char *param );

/*
	egb_b3.o
*/
/*	��`�̈�Ǎ�(�F�w��) High-C���C�u������݊� [22]	*/
int	EGB_getRectColor( char *w, char *buf,int sx, int sy, int ex, int ey, int color);
/*	��`�̈揑������(�F�w��) High-C���C�u������݊� [23]	*/
int	EGB_putRectColor( char *w, int clip, char *buf, int sx, int sy, int ex, int ey);
/*	��`�̈�Ǎ�(�t���J���[) High-C���C�u������݊� [24]	*/
int	EGB_getRect( char *w, char *buf, int sx, int sy, int ex, int ey );
/*	��`�̈揑������ High-C���C�u������݊� [25]	*/
int	EGB_putRect( char *w, int clip, char *buf, int sx, int sy, int ex, int ey );

/*
	egb_b4.o
*/
/*	�O���t�B�b�N�J�[�\�� [28]	*/
int	EGB_graphicCursor(int clip, char *param);
/*	�}�X�N�f�[�^�̏������� [29]	*/
int	EGB_maskData( char *w, int clip, char *param );
/*	�S��ʃX�N���[�� [2A]	*/
int	EGB_scroll( char *w, int mode, int dx, int dy );
/*	�����X�N���[�� [2B]	*/
int	EGB_partScroll( char *w, int mode, int dx, int dy, char *param );

/*
	egb_b5.o
*/
/*	�̈�ݒ� [2C]	*/
int	EGB_region( char *w, int *in, int *work, int *x, int *y, int *x2, int *y2, char *poly );
/*	��ʂ̕��� [2D]	*/
int	EGB_copy( char *w, int mode, char *param, char *work );
/*	��ʂ̉�] [2E]	*/
int	EGB_rotate( char *w,int mode, char *param,  char *work );
/*	��ʂ̂ڂ��� [2F]	*/
int	EGB_resolve( char *w, char *work );

/*
	 (grahics operation);
	egb_g1.o
*/
/*	�|�C���g [40]	*/
int	EGB_pset( char *w, char *parm );
/*	�A������ [41]	*/
int	EGB_connect( char *w, char *param);
/*	�s�A������ [42]	*/
int	EGB_unConnect( char *w, char *param );
/*	�|���S�� [43]	*/
int	EGB_polygon( char *w, char *param );
/*	��` [46]	*/
int	EGB_rectangle( char *w, char *param );
/*	�~ [47]		*/
int	EGB_circle( char *w, char *param );

/*
	egb_g2.o
*/
/*	��]���p�` [44]	*/
int	EGB_rotatePolygon( char *w, char *param );
/*	�O�p�` [45]	*/
int	EGB_triangle( char *w, char *param );
/*	�~�� [48]	*/
int	EGB_arc( char *w, char *param );
/*	��` [49]	*/
int	EGB_fan( char *w, char *param );
/*	�ȉ~ [4A]	*/
int	EGB_ellipse( char *w, char *param );
/*	�ȉ~�� [4B]	*/
int	EGB_ellipticArc( char *w, char *param );
/*	�Ȑ�` [4C]	*/
int	EGB_ellipticFan( char *w, char *param );
/*	�|�`(�ʉ�3�_�w��) [50]	*/
int	EGB_bow( char *w, char *param );
/*	�|�`(���a�w��) [51]	*/
int	EGB_semiBow( char *w, char *param );

/*
	egb_g3.o
*/
/*	�y�C���g(���E�F�w��) [4D]	*/
int	EGB_paint( char *w, char *param );
/*	�y�C���g(�F�ύX) [4E]	*/
int	EGB_closePaint( char *w, char *param );
/*	�|�C���g�F�𓾂� [4F]	*/
int	EGB_point( char *w, int mode, int x, int y , int *result);

/*
	egb_g4.o
*/
/*	��_�`�� High-C���C�u������݊� [40]	*/
int	EGB_singlePset( char *w, int x, int y );
/*	��{���`�� High-C���C�u������݊� [41]	*/
int	EGB_singleLine( char *w, int sx, int sy, int ex, int ey );
/*	�l�p��`�� High-C���C�u������݊� [46]	*/
int	EGB_box( char *w, int sx, int sy, int ex, int ey );
/*	�܂��`�� High-C���C�u������݊� [47]	*/
int	EGB_maru( char *w, int x, int y, int r );

/*
	 (font operation);
	egb_f1.o
*/
/*	���������� [60]	*/
int	EGB_sjisString( char *w, char *param );
/*	�ǉ�����������) [61]	*/
int	EGB_connectSjisString( char *w, char *param );
/*	JIS8�r�b�g������ [62]	*/
int	EGB_asciiString( char *w, int font, char *param );
/*	�ǉ�JIS������ [63]	*/
int	EGB_connectAsciiString( char *w, int font, char *param );
/*	JIS�R�[�h������ [64]	*/
int	EGB_jisString( char *w, char *param );
/*	�ǉ�JIS�R�[�h������  [65]	*/
int	EGB_connectJisString( char *w, char *param );
/*	�C�ӕ����\�� [66]	*/
int	EGB_anyChar( char *w, int wx, int wy,  char *pattern );

/*
	egb_f2.o
*/
/*	������̕\�� High-C���C�u������݊� [60]	*/
int	EGB_putSjis( char *w, int x, int y,  char *str );
/*	������̒ǉ��\�� High-C���C�u������݊� [61]	*/
int	EGB_putSjisAdd( char *w, char *str );


/*
(2)�O���t�B�b�N���̊֐�

escreen.o
*/

/*
	��ʂ�MS-DOS�݊����[�h�ɂ��郋�[�`���ł��B�v���O������MS-DOS����N������
	�ꍇ�ɁA�Ō�ɌĂяo���Ă��������B���̃��[�`���ŉ�ʂ�ݒ肷��ƁA�ʏ��
	MS-DOS�̉�ʂɖ߂邱�Ƃ��ł��܂��B
*/
void screenterm( char *w );
