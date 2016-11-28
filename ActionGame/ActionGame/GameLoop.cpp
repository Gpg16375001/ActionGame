/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   ゲームループ													*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*						何もしない関数					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void GameNull( void )
{
}

/*______________________________________________________*/
/*						ゲーム開始						*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void GameAInit( void )
{

	gmode = GM_I_TITLE ;								// タイトルの初期セットへ移動する

	/* >> デバッグ << */
	gmode = GM_I_GAME ;

}

/*______________________________________________________*/
/*					タイトルの初期セット				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void GameITitle( void )
{
	obj[O_TITLE].idno = ID_TITLE ;						// タイトル (背景) の呼び出し
	obj[O_TITLE].mode = 0 ;								// タイトル (背景) の初期セットの呼び出し

	obj[O_START].idno = ID_START ;						// スタート (文字) の呼び出し
	obj[O_START].mode = 0 ;								// スタート (文字) の初期セットの呼び出し 

	gmode = GM_M_TITLE ;								// タイトルに移動
}

/*______________________________________________________*/
/*						タイトル中						*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void GameMTitle( void )
{
	if ( obj[O_START].idno == 0 )						// スタートが消えたとき ( SPACE KEY が押されると消える )
	{
		gmode = GM_E_TITLE ;							// タイトル終了へ移動
	}
}

/*______________________________________________________*/
/*						タイトル終了					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void GameETitle( void )
{
	obj[O_TITLE].idno = 0;								// タイトル (背景) を消す
	obj[O_TITLE].mode = 0 ;								// タイトル (背景) の初期セットの呼び出し

	obj[O_START].idno = 0 ;								// スタート (文字) を消す
	obj[O_START].mode = 0 ;								// スタート (文字) の初期セットの呼び出し

	gmode = GM_I_GAME ;									// ゲーム開始する
}

/*______________________________________________________*/
/*					  ゲーム初期セット					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void GameIGame( void )
{
	obj[O_BG].idno = ID_BG ;							// 背景の呼び出し
	obj[O_BG].mode = 0 ;								// 背景の初期セットの呼び出し

	obj[O_PLY].idno = ID_PLY ;							// プレイヤーの呼び出し
	obj[O_PLY].mode = 0 ;								// プレイヤーの初期セットの呼び出し

	obj[O_HOLE+0].idno = ID_HOLE ;						// 背景の呼び出し
	obj[O_HOLE+0].mode = 0 ;							// 背景の初期セットの呼び出し
	obj[O_HOLE+0].cnt = 0 ;								// 背景の初期セットの呼び出し

	obj[O_HOLE+1].idno = ID_HOLE ;						// 背景の呼び出し
	obj[O_HOLE+1].mode = 0 ;							// 背景の初期セットの呼び出し
	obj[O_HOLE+1].cnt = 1 ;								// 背景の初期セットの呼び出し

	obj[O_HOLE+2].idno = ID_HOLE ;						// 背景の呼び出し
	obj[O_HOLE+2].mode = 0 ;							// 背景の初期セットの呼び出し
	obj[O_HOLE+2].cnt = 2;								// 背景の初期セットの呼び出し

	obj[O_HOLE+3].idno = ID_HOLE ;						// 背景の呼び出し
	obj[O_HOLE+3].mode = 0 ;							// 背景の初期セットの呼び出し
	obj[O_HOLE+3].cnt = 3 ;								// 背景の初期セットの呼び出し

	obj[O_BOO].idno = ID_BOO ;							// 背景の呼び出し
	obj[O_BOO].mode = 0 ;								// 背景の初期セットの呼び出し

	EnemySet( ) ;
	BlockSet( ) ;										// ブロックの配置

	gmode = GM_M_GAME ;									// ゲーム開始する
}

/*______________________________________________________*/
/*						  ゲーム中						*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void GameMGame( void )
{

}

/*______________________________________________________*/
/*						ゲーム終了時					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void GameEGame( void )
{
}

/*______________________________________________________*/
/*					 ゲームジャンプ用					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
TBLJP GameJpTbl[ ] = {
	GameAInit ,											//  00 : 全部の初期化
	GameITitle ,										//  01 : タイトルの初期セット
	GameMTitle ,										//  02 : タイトルの最中
	GameETitle ,										//  03 : タイトル終了時
	GameNull ,											//  04 : 
	GameIGame ,											//  05 : ゲームの初期セット
	GameMGame ,											//  06 : ゲームの最中
	GameEGame ,											//  07 : ゲーム終了時
	GameNull ,											//  08 : 
	GameNull ,											//  09 : 
	GameNull ,											//  10 : 
	GameNull ,											//  11 : 
	GameNull ,											//  12 : 
	GameNull ,											//  13 : 
	GameNull ,											//  14 : 
	GameNull ,											//  15 : 
} ;

/*______________________________________________________*/
/*						ゲームループ					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void GameLoop( void )
{
	GameJpTbl[ gmode ]( ) ;								// それぞれの関数へジャンプする
}



