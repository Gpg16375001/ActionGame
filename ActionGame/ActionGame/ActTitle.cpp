/*______________________________________________________________________________________________________________*/
/*																												*/
/*												タイトルアクション												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					タイトルのアクション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActTitle( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ０：非表示	1：表示
			pp->xp = 0 ;								// スクリーンＸ座標
			pp->yp = 0 ;								// スクリーンＹ座標
			pp->xsize = WINDOW_W ;						// Ｘサイズ
			pp->ysize = WINDOW_H ;						// Ｙサイズ
			pp->xboff = 0 ;								// Ｘオフセット
			pp->yboff = 0 ;								// Ｙオフセット
			pp->xmoff = 0 ;								// Ｘマスク
			pp->ymoff = 0 ;								// Ｙマスク
			pp->idx = 0 ;								// 画像番号

			pp->mode = 1 ;								// アクション管理番号
			break ;

		case 1 :
			break ;

	}

}

/*______________________________________________________*/
/*					スタートのアクション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActStart( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ０：非表示	1：表示
			pp->xp = WINDOW_W / 2 ;						// スクリーンＸ座標
			pp->yp = 480 ;								// スクリーンＹ座標
			pp->xsize = 256 ;							// Ｘサイズ
			pp->ysize = 40 ;							// Ｙサイズ
			pp->xboff = 0 ;								// Ｘオフセット
			pp->yboff = 0 ;								// Ｙオフセット
			pp->xmoff = 0 ;								// Ｘマスク
			pp->ymoff = 40 ;							// Ｙマスク
			pp->xoff = -128 ;							// Ｘ中心点
			pp->yoff = -20 ;							// Ｙ中心点
			pp->idx = 1 ;								// 画像番号

			pp->mode = 1 ;								// アクション管理番号
			pp->pchg[4] = 0 ;
			pp->pchg[2] = 0 ;
			break ;

		case 1 :
			/*
				点滅させるプログラム
			*/
			if ( pp->pchg[4] > 40 )
			{
				pp->dspf = 1 ;
				pp->pchg[4] = 0 ;
			}
			if ( pp->pchg[4] > 20 )
			{
				pp->dspf = 0 ;
			}
			pp->pchg[4] += 3 ;

			if (GetKeyState(VK_SPACE) < 0)				// SPACE KEY が押されたとき
			{
				pp->pchg[4] = 0 ;
				pp->mode = 2 ;
				pp->pchg[2] = 10 ;
			}
			break ;

		case 2 :
			if ( pp->pchg[4] > 40 )
			{
				pp->dspf = 1 ;
				pp->pchg[4] = 0 ;
			}
			if ( pp->pchg[4] > 20 )
			{
				pp->dspf = 0 ;
			}

			pp->pchg[2]-- ;
			if ( pp->pchg[2] <= 0 )
			{
				pp->pchg[2] = 0 ;
				pp->idno = 0 ;
			}

			pp->pchg[4] += 25 ;
			break ;

	}

}



