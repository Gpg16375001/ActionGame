/*______________________________________________________________________________________________________________*/
/*																												*/
/*											 外部参照 グローバル宣言											*/
/*______________________________________________________________________________________________________________*/

extern HDC			hDCBack;				// 裏画面のデバイスコンテキスト	
extern HBITMAP		hBmpTbl[20];			// ビットマップロード用
extern HWND			hwnd ;					// ウインドウハンドル
extern u_short		tmf ;					// １タイマー処理チェックフラグ
extern DT			obj[MAXOBJ] ;			// 最大オブジェクト数
extern DT			*pp ;					// オブジェクト用のポインタ変数

extern BT			blk[MAXBLK] ;			// 最大オブジェクト数
extern BT			*bp ;					// ブロック用のポインタ変数

extern int			gmode ;					// ゲーム管理モード
extern int			edflg ;
extern double		xdk , ydk ;					// 土管向き

extern unsigned char map[18][25] ;


