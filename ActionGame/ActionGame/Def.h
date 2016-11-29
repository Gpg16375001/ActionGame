/*______________________________________________________________________________________________________________*/
/*																												*/
/*										  デファイン プロトタイプ宣言											*/
/*______________________________________________________________________________________________________________*/

/* ____ DEFINE ____ */
#define	MAXOBJ			300		// スプライトの数
#define WINDOW_W		800		// ウィンドウの幅
#define WINDOW_H		640		// ウィンドウの高さ
#define FLIMIT			576.0	// 地面の位置

#define MAXBLK			450		// ブロックの最大数

#define GM_I_ALL		0		// 全部の初期セット
#define GM_I_TITLE		1		// タイトルの初期セット
#define GM_M_TITLE		2		// タイトル中
#define GM_E_TITLE		3		// タイトル終了
#define GM_I_GAME		5		// ゲーム初期セット
#define GM_M_GAME		6		// ゲーム中

#define O_TITLE			0		// タイトルの背景
#define O_START			1		// スタートの文字
#define O_BG			0		// ゲーム背景
#define O_PLY			10		// プレイヤー
#define O_ENE			20		// エネミー
#define O_HOLE			80		// 土管
#define O_BOO			90		// 煙
#define O_SNOW			180		// 雪
#define O_BOMB			280		// 爆発

#define MAXBOO			10		// boo
#define MAXBOM			10		// 爆発
#define MAXSNOW			100		// 雪
#define MAXENE			5		// エネミーの最大数

#define ID_BLOCK		1		// ブロックのID
#define ID_TITLE		1		// タイトルのID
#define ID_START		2		// スタート文字のID
#define ID_BG			4		// ゲーム背景のID
#define ID_PLY			6		// プレイヤーのID
#define ID_ENE			8		// エネミーのID
#define ID_HOLE			10		// 土管のID
#define ID_STEP			13		// 煙のID
#define ID_BOO			14		// 煙のID
#define ID_HOLE2		15		// 土管2のID
#define ID_SNOW			15		// 雪のID
#define ID_BOMB			16		// 爆発のID

/* ____ 構造体宣言 ____ */
typedef struct {
	int idno ;					// 識別番号
	int mode ;					// アクション管理番号
	BOOL dspf ;					// ０：非表示	1：表示
	double xp ;					// スクリーンＸ座標
	double yp ;					// スクリーンＹ座標
	int xsize ;					// Ｘサイズ
	int ysize ;					// Ｙサイズ
	int xboff ;					// Ｘオフセット
	int yboff ;					// Ｙオフセット
	int xmoff ;					// Ｘマスク
	int ymoff ;					// Ｙマスク
	int idx ;					// 画像番号
	int xoff ;					// 中心点 X座標
	int yoff ;					// 中心点 Y座標
	int pchg[5] ;
	double xspd ;
	double yspd ;
	BOOL lrflg ;
	int cnt ;
	int timer ;
	double ysave ;
} DT ;

typedef struct {
	int idno ;					// 識別番号
	int mode ;					// アクション管理番号
	BOOL dspf ;					// ０：非表示	1：表示
	double xp ;					// スクリーンＸ座標
	double yp ;					// スクリーンＹ座標
	int xboff ;					// Ｘオフセット
	int yboff ;					// Ｙオフセット
	int pchg[5] ;				// 
	double xspd ;				// X speed
	double yspd ;				// Y speed
	int bno ;					// ブロックのナンバー
	double ys ;					// 自分の位置を覚えとく用
	double ysave ;
} BT ;

/* ____ テーブルジャンプ ____ */
typedef void ( *TBLJP )( void ) ;

/* ____ プロトタイプ宣言 ____ */
LRESULT CALLBACK WndProc ( HWND , UINT , WPARAM , LPARAM ) ;
void GameLoop( void ) ;
void ActionLoop( void ) ;
void DispLoop( void ) ;
void ActTitle( void ) ;
void ActStart( void ) ;
void ActBg( void ) ;
void BlockSet( void ) ;
void ActBlock( void ) ;
void ActPlayer( void ) ;
int FootCheck( void ) ;
int HeadCheck( void ) ;
void ActEnemy( void ) ;
void ActHole( void ) ;
void ActWarp( void ) ;
void EnemySet( void ) ;
void BBcheck( void ) ;
void PAcheck( void ) ;
void FootHitCheck( void ) ;
void ActBoo( void ) ;
int ObjSearch( int , int ) ;
void ActStep( void ) ;
int Body_Block( void ) ;
void ActHole2( void ) ;
void ActSnow( void ) ;
void ActBomb( void ) ;


