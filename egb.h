/*
● TOWNS用GCCライブラリ ------ グラフイックBIOS編


(1)EGB BIOSコール関数
   ･ 頭に*が付いている以外は、High-Cのライブラリと互換｡ 互換ライブラリは
     T-BIOSのコールと一対一対応している。関数の後の[数値]は，T-BIOSのファン
     クション番号(AHレジスタに設定する値,16進)である。
*/

/*
	egb_s1.OBJGPP
	(setup operation);
*/

/* グラフィックBIOSの初期化 [00]	*/
int	EGB_init( char *w, int size);

	
/*	画面モードの設定 [01]	*/
int	EGB_resolution( char *w, int page, int mode );

/*	仮想RAM画面モードの設定 */
int	EGB_resolutionRAM( char *w, int page, int pixel, int width, int height, char *ram );

/*	表示開始位置の設定 [02]	*/
int	EGB_displayStart( char *w, int mode, int x, int y );

/*	表示画面の画面枠内の移動 High-Cライブラリ非互換 [02]	*/
int	EGB_displayOffset( char *w, int sx, int sy );

/*	VRAM中の表示領域の開始座標 High-Cライブラリ非互換 [02]	*/
int	EGB_screenOffset( char *w, int sx, int sy );

/*	画面の拡大 High-Cライブラリ非互換 [02]	*/
int	EGB_screenZoom( char *w, int wx, int wy );

/*	画面の大きさ設定 High-Cライブラリ非互換 [02]	*/
int	EGB_screenWidth( char *w, int wx, int wy );

/*	ビューポート設定  [03]	*/
int	EGB_viewport( char *w, char *param );

/*	ビューポート設定 High-Cライブラリ非互換  [03]	*/
int	EGB_viewportRect( char *w, int sx, int sy, int ex, int ey );

/*	パレットの設定  [04]	*/
int	EGB_palette( char *w, int syncf, char *param );

/*	1つのパレット設定 High-Cライブラリ非互換  [04]	*/
int	EGB_setPalette( char *w, int num, int g, int r, int b );

/*	書き込みページの設定  [05]	*/
int	EGB_writePage( char *w, int page );

/*	表示ページの設定  [06]	*/
int	EGB_displayPage( char *w, int prior, int page );

/*
	egb_s2.o
*/
/*	描画色の設定(パレットコード) [07]	*/
int	EGB_color( char *w, int mode, int color );
/*	前景色の設定(パレットコード) High-Cライブラリ非互換 [07]	*/
int	EGB_foreColor( char *w, int col );
/*	背景色の設定(パレットコード) High-Cライブラリ非互換 [07]	*/
int	EGB_backColor( char *w, int col );
/*	面塗り色の設定(パレットコード) High-Cライブラリ非互換 [07]	*/
int	EGB_paintColor( char *w, int col );
/*	透過色の設定(パレットコード) High-Cライブラリ非互換 [07]	*/
int	EGB_transColor( char *w, int col );
/*	描画色の設定(IGRBコード) [08]	*/
int	EGB_colorIGRB( char *w, int mode, int col );
/*	前景色の設定(IGRBコード) High-Cライブラリ非互換 [08]	*/
int	EGB_foreColorIGRB( char *w, int col );
/*	背景色の設定(IGRBコード) High-Cライブラリ非互換 [08]	*/
int	EGB_backColorIGRB( char *w, int col );
/*	面塗り色の設定(IGRBコード) High-Cライブラリ非互換 [08]	*/
int	EGB_paintColorIGRB( char *w, int col );
/*	透過色の設定(IGRBコード) High-Cライブラリ非互換 [08]	*/
int	EGB_transColorIGRB( char *w, int col );
/*	Pastelモード描画の混色比 [09]	*/
int	EGB_pastel( char *w, int level );
/*	描画モードの設定   [0A]	*/
int	EGB_writeMode( int mode );

/*
	egb_s3.o
*/
/*	線分パターンの設定 [0B]	*/
int	EGB_linePattern( char *w, int mode, int  pattern );
/*	ペイントモードの設定  [0C]	*/
int	EGB_paintMode( char *w, int mode );
/*	ハッチングパターン設定 [0D]	*/
int	EGB_hatchingPattern( char *w, int mode, int x, int y, char *pat );
/*	タイルパターン設定 [0E]	*/
int	EGB_tilePattern( char *w, int mode, int x, int y, char *pat );
/*	画面マスク領域の設定  [0F]	*/
int	EGB_maskRegion( char *w,char *pat );
/*	マスクモードの設定  [10]	*/
int	EGB_mask( char *w, int mode );
/*	マスクビットの設定 [14]	*/
int	EGB_maskBit( char *w, int bit );

/*
egb_s4.o
*/
/*	描画ペンのモード設定 [11]	*/
int	EGB_pen( char *w, int penmode );
/*	描画ペンの太さ設定 [12]	*/
int	EGB_penSize( char *w, int pensize );
/*	描画ペン形状定義  [13]	*/
int	EGB_penStyle( char *w, char *pattern );

/*
egb_s5.o
*/
/*	文字方向の設定 [15]	*/
int	EGB_textDirection( char *w, int dir );
/*	文字表示方向の設定 [16]	*/
int	EGB_textDisplayDirection( char *w, int dir );
/*	文字間空白の設定 [17]	*/
int	EGB_textSpace( char *w, int space );
/*	文字拡大率の設定 [18]	*/
int	EGB_textZoom( char *w, int mode, int  x, int  y );
/*	字体の設定 [19]	*/
int	EGB_fontStyle( char *w, int style);
/*	文字属性の一括設定 High-Cライブラリ非互換 [**]	*/
int	EGB_textAttrib( char *w, int mx, int my, int style, int dir, int ddir, int space );
/*	スーパーインポーズ [1A]	*/
int	EGB_superImpose( char *w, int mode );
/*	ディジタイズ  [1B]	*/
int	EGB_digitize( char *w, int mode);

/*
	(block operation);
	egb_b1.o
*/
/*	VRAM領域の消去 [20]	*/
int	EGB_clearScreen( char *w );
/*	ビューポート領域の消去 [21]	*/
int	EGB_partClearScreen( char *w );
/*	VRAMのダイレクトゼロクリア High-Cライブラリ非互換 [**]	*/
int	EGB_clearVRAM( int page );

/*
	egb_b2.o
*/
/*	矩形領域読みだし(色指定) [22]	*/
int	EGB_getBlockColor( char *w, char *param );
/*	矩形領域書き込み(色指定) [23]	*/
int	EGB_putBlockColor( char *w, int clip, char *param );
/*	矩形領域読みだし(フルカラー) [24]	*/
int	EGB_getBlock( char *w, char *param );
/*	矩形領域書き込み(フルカラー) [25]	*/
int	EGB_putBlock( char *w, int clip, char *param );
/*	矩形領域読みだし(ズーム付) [26]	*/
int	EGB_getBlockZoom( char *w, char *param );
/*	矩形領域書き込み(ズーム付) [27]	*/
int	EGB_putBlockZoom( char *w, int clip, char *param );

/*
	egb_b3.o
*/
/*	矩形領域読込(色指定) High-Cライブラリ非互換 [22]	*/
int	EGB_getRectColor( char *w, char *buf,int sx, int sy, int ex, int ey, int color);
/*	矩形領域書き込み(色指定) High-Cライブラリ非互換 [23]	*/
int	EGB_putRectColor( char *w, int clip, char *buf, int sx, int sy, int ex, int ey);
/*	矩形領域読込(フルカラー) High-Cライブラリ非互換 [24]	*/
int	EGB_getRect( char *w, char *buf, int sx, int sy, int ex, int ey );
/*	矩形領域書き込み High-Cライブラリ非互換 [25]	*/
int	EGB_putRect( char *w, int clip, char *buf, int sx, int sy, int ex, int ey );

/*
	egb_b4.o
*/
/*	グラフィックカーソル [28]	*/
int	EGB_graphicCursor(int clip, char *param);
/*	マスクデータの書き込み [29]	*/
int	EGB_maskData( char *w, int clip, char *param );
/*	全画面スクロール [2A]	*/
int	EGB_scroll( char *w, int mode, int dx, int dy );
/*	部分スクロール [2B]	*/
int	EGB_partScroll( char *w, int mode, int dx, int dy, char *param );

/*
	egb_b5.o
*/
/*	領域設定 [2C]	*/
int	EGB_region( char *w, int *in, int *work, int *x, int *y, int *x2, int *y2, char *poly );
/*	画面の複写 [2D]	*/
int	EGB_copy( char *w, int mode, char *param, char *work );
/*	画面の回転 [2E]	*/
int	EGB_rotate( char *w,int mode, char *param,  char *work );
/*	画面のぼかし [2F]	*/
int	EGB_resolve( char *w, char *work );

/*
	 (grahics operation);
	egb_g1.o
*/
/*	ポイント [40]	*/
int	EGB_pset( char *w, char *parm );
/*	連続線分 [41]	*/
int	EGB_connect( char *w, char *param);
/*	不連続線分 [42]	*/
int	EGB_unConnect( char *w, char *param );
/*	ポリゴン [43]	*/
int	EGB_polygon( char *w, char *param );
/*	矩形 [46]	*/
int	EGB_rectangle( char *w, char *param );
/*	円 [47]		*/
int	EGB_circle( char *w, char *param );

/*
	egb_g2.o
*/
/*	回転多角形 [44]	*/
int	EGB_rotatePolygon( char *w, char *param );
/*	三角形 [45]	*/
int	EGB_triangle( char *w, char *param );
/*	円弧 [48]	*/
int	EGB_arc( char *w, char *param );
/*	扇形 [49]	*/
int	EGB_fan( char *w, char *param );
/*	楕円 [4A]	*/
int	EGB_ellipse( char *w, char *param );
/*	楕円弧 [4B]	*/
int	EGB_ellipticArc( char *w, char *param );
/*	楕扇形 [4C]	*/
int	EGB_ellipticFan( char *w, char *param );
/*	弓形(通過3点指定) [50]	*/
int	EGB_bow( char *w, char *param );
/*	弓形(半径指定) [51]	*/
int	EGB_semiBow( char *w, char *param );

/*
	egb_g3.o
*/
/*	ペイント(境界色指定) [4D]	*/
int	EGB_paint( char *w, char *param );
/*	ペイント(色変更) [4E]	*/
int	EGB_closePaint( char *w, char *param );
/*	ポイント色を得る [4F]	*/
int	EGB_point( char *w, int mode, int x, int y , int *result);

/*
	egb_g4.o
*/
/*	一点描画 High-Cライブラリ非互換 [40]	*/
int	EGB_singlePset( char *w, int x, int y );
/*	一本線描画 High-Cライブラリ非互換 [41]	*/
int	EGB_singleLine( char *w, int sx, int sy, int ex, int ey );
/*	四角を描く High-Cライブラリ非互換 [46]	*/
int	EGB_box( char *w, int sx, int sy, int ex, int ey );
/*	まるを描く High-Cライブラリ非互換 [47]	*/
int	EGB_maru( char *w, int x, int y, int r );

/*
	 (font operation);
	egb_f1.o
*/
/*	漢字文字列 [60]	*/
int	EGB_sjisString( char *w, char *param );
/*	追加漢字文字列) [61]	*/
int	EGB_connectSjisString( char *w, char *param );
/*	JIS8ビット文字列 [62]	*/
int	EGB_asciiString( char *w, int font, char *param );
/*	追加JIS文字列 [63]	*/
int	EGB_connectAsciiString( char *w, int font, char *param );
/*	JISコード文字列 [64]	*/
int	EGB_jisString( char *w, char *param );
/*	追加JISコード文字列  [65]	*/
int	EGB_connectJisString( char *w, char *param );
/*	任意文字表示 [66]	*/
int	EGB_anyChar( char *w, int wx, int wy,  char *pattern );

/*
	egb_f2.o
*/
/*	文字列の表示 High-Cライブラリ非互換 [60]	*/
int	EGB_putSjis( char *w, int x, int y,  char *str );
/*	文字列の追加表示 High-Cライブラリ非互換 [61]	*/
int	EGB_putSjisAdd( char *w, char *str );


/*
(2)グラフィック回りの関数

escreen.o
*/

/*
	画面をMS-DOS互換モードにするルーチンです。プログラムをMS-DOSから起動する
	場合に、最後に呼び出してください。このルーチンで画面を設定すると、通常の
	MS-DOSの画面に戻ることができます。
*/
void screenterm( char *w );
