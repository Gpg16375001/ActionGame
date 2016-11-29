/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   Object ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*						Booのアクション					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActBoo( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 0 ;								// 0 : 非表示
			pp->xsize = 80 ;							// Ｘサイズ
			pp->ysize = 80 ;							// Ｙサイズ
			pp->xboff = 0 ;								// Ｘオフセット
			pp->yboff = 0 ;								// Ｙオフセット
			pp->xmoff = 0 ;								// Ｘマスク
			pp->ymoff = 80 ;							// Ｙマスク
			pp->xoff = -40 ;							// Ｘマスク
			pp->yoff = 0 ;								// Ｙマスク
			pp->idx = 9 ;
			pp->mode = 1 ;
			pp->cnt = 0 ;
			pp->timer = 2 ;
			break ;

		case 1 :
			pp->timer-- ;
			if ( pp->timer < 0 )
			{
				pp->dspf = 1 ;
				pp->timer = 0 ;
				pp->mode = 2 ;
			}
			break ;

		case 2 :
			pp->xboff = pp->cnt * 80 ;
			pp->xmoff = pp->xboff ;								// Ｘマスク
			pp->cnt++ ;
			if ( pp->cnt > 3 )
			{
				pp->idno = 0 ;
				pp->mode = 0 ;
			}
			break ;
	}
}

/*______________________________________________________*/
/*						着地のアクション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActStep( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 0 ;
			pp->xsize = 80 ;							// Ｘサイズ
			pp->ysize = 80 ;							// Ｙサイズ
			pp->xboff = 0 ;								// Ｘオフセット
			pp->yboff = 0 ;								// Ｙオフセット
			pp->xmoff = 0 ;								// Ｘマスク
			pp->ymoff = 80 ;							// Ｙマスク
			pp->xoff = -40 ;							// Ｘマスク
			pp->yoff = 0 ;								// Ｙマスク
			pp->idx = 9 ;
			pp->mode = 1 ;
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->xboff = pp->cnt * 80 + 240 ;
			pp->xmoff = pp->xboff ;						// Ｘマスク
			pp->dspf = 1 ;
			pp->cnt++ ;
			if ( pp->cnt > 2 )
			{
				pp->idno = 0 ;
				pp->mode = 0 ;
			}
			break ;
	}
}

/*______________________________________________________*/
/*						土管の配置						*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActHole( void )
{
	int HoleTbl[4][3] = {
		{  50 , 100 , 100 } ,							// 0番の土管
		{ 750 , 100 ,   0 } ,							// 1番の土管
		{  50 , 578 , 100 } ,							// 2番の土管
		{ 750 , 578 ,   0 } ,							// 3番の土管
	} ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ０：非表示	1：表示
			pp->xsize = 100 ;							// Ｘサイズ
			pp->ysize = 100 ;							// Ｙサイズ
			pp->yboff = 0 ;								// Ｙオフセット
			pp->ymoff = 100 ;							// Ｙマスク
			pp->xoff = -50 ;							// Ｘマスク
			pp->yoff = -100 ;							// Ｙマスク
			pp->idx = 8 ;								// 画像番号
			pp->mode = 1 ;								// アクション管理番号

			pp->xp = (double)HoleTbl[pp->cnt][0] ;		// スクリーンＸ座標
			pp->yp = (double)HoleTbl[pp->cnt][1] ;		// スクリーンＹ座標
			pp->xboff = HoleTbl[pp->cnt][2] ;			// Ｘオフセット
			pp->xmoff = HoleTbl[pp->cnt][2] ;			// Ｘマスク
			break ;

		case 1 :
			break ;

	}
}

/*______________________________________________________*/
/*						土管の配置						*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActHole2( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 0 ;								// ０：非表示	1：表示
			pp->xsize = 100 ;							// Ｘサイズ
			pp->ysize = 150 ;							// Ｙサイズ
			pp->yboff = 0 ;								// Ｙオフセット
			pp->ymoff = 0 ;								// Ｙマスク
			pp->xoff = -50 ;							// Ｘマスク
			pp->yoff = -150 ;							// Ｙマスク
			pp->idx = 10 ;								// 画像番号
			pp->mode = 1 ;								// アクション管理番号

			pp->xp = (double)400 ;						// スクリーンＸ座標
			pp->yp = (double)676 ;						// スクリーンＹ座標
			pp->xboff = 0 ;								// Ｘオフセット
			pp->xmoff = 100 ;							// Ｘマスク
			pp->cnt = 0 ;
			break ;

		case 1 :
			break ;

	}
}


/*______________________________________________________*/
/*						雪を降らす						*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActSnow( void )
{
	int no ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ０：非表示	1：表示
			pp->yp = 0 ;
			pp->xsize = 16 ;							// Ｘサイズ
			pp->ysize = 16 ;							// Ｙサイズ
			pp->yboff = 16 * 4 ;						// Ｙオフセット
			pp->ymoff = 0 ;								// Ｙマスク
			pp->xoff = -8 ;								// Ｘマスク
			pp->yoff = -8 ;								// Ｙマスク
			pp->yspd = 8 ;
			pp->idx = 11 ;								// 画像番号
			pp->mode = 1 ;								// アクション管理番号

			pp->xboff = 0 ;								// Ｘオフセット
			pp->xmoff = 16 * 4 ;						// Ｘマスク
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->xp += pp->xspd ;
			pp->yp += pp->yspd ;
			if ( (rand( ) % 50) == 0 )
			{
				pp->mode = 2 ;
				if ( rand( ) & 1 )
				{
					pp->xspd = 0.4 ;
				}
				else
				{
					pp->xspd = -0.4 ;
				}
			}

			if ( pp->yp > FLIMIT )
			{
				pp->mode = 0 ;
				pp->idno = 0 ;
			}
			break ;

		case 2 :
			no = ObjSearch( O_SNOW , MAXSNOW ) ;
			if ( no != -1 )								// 空いていたら
			{
				obj[no].idno = ID_SNOW ;
				obj[no].mode = 0 ;
				obj[no].xp = (rand( ) % 800) + 0 ;
				obj[no].timer = 100 ;
			}
			pp->mode = 1 ;
			break ;

	}
}

/*______________________________________________________*/
/*							 背景						*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActBg( void )
{
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ０：非表示	1：表示
			pp->xp = 0 ;								// スクリーンＸ座標
			pp->yp = -1280 ;							// スクリーンＹ座標
			pp->xsize = WINDOW_W ;						// Ｘサイズ
			pp->ysize = WINDOW_H * 3 ;					// Ｙサイズ
			pp->xboff = 0 ;								// Ｘオフセット
			pp->yboff = 0 ;								// Ｙオフセット
			pp->xmoff = 0 ;								// Ｘマスク
			pp->ymoff = 0 ;								// Ｙマスク
			pp->idx = 2 ;								// 画像番号

			pp->mode = 1 ;								// アクション管理番号
			break ;

		case 1 :
/*
			if ( (obj[O_PLY].yp <= 200) && (obj[O_PLY].yspd < 0) )
			{
				for ( i = 0 ; i < MAXOBJ ; i++ )
				{
					if ( (obj[i].idno != 0) && (obj[i].mode != 0) && (obj[i].dspf != 0) )
					{
						obj[i].yp -= obj[O_PLY].yspd ;
					}
				}

				for ( i = 0 ; i < MAXBLK ; i++ )
				{
					if ( (blk[i].idno != 0) && (blk[i].mode != 0) && (blk[i].dspf != 0) )
					{
						blk[i].yp -= obj[O_PLY].yspd ;
					}
				}
				sflg = 1 ;
			}

			if ( (obj[O_PLY].yp >= WINDOW_H - 200) && (obj[O_PLY].yspd > 0) && (sflg == 1) )
			{
				for ( i = 0 ; i < MAXOBJ ; i++ )
				{
					if ( (obj[i].idno != 0) && (obj[i].mode != 0) && (obj[i].dspf != 0) )
					{
						obj[i].yp -= obj[O_PLY].yspd ;
					}
				}

				for ( i = 0 ; i < MAXBLK ; i++ )
				{
					if ( (blk[i].idno != 0) && (blk[i].mode != 0) && (blk[i].dspf != 0) )
					{
						blk[i].yp -= obj[O_PLY].yspd ;
					}
				}
				if ( obj[O_BG].yp <= -1280 )
				{
					sflg = 0 ;
				}
			}
*/
			break ;

	}

}

/*______________________________________________________*/
/*					  爆発 アクション					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActBomb( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				爆発 初期セット
			*/
			pp->dspf = 1 ;
			pp->xsize = 80 ;
			pp->ysize = 80 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 80 ;
			pp->idx = 12 ;
			pp->xoff = -40 ;										// 中心点の変更 X軸
			pp->yoff = -40 ;										// 中心点の変更 Y軸

			pp->mode = 1 ;

			pp->pchg[0] = 0 ;
//			mciSendString( TEXT("play SE_BOMB1 from 0 notify") , NULL , 0 , hwnd ) ;// bomb
			break ;

		case 1 :
			pp->pchg[0]++ ;
			if ( pp->pchg[0] < 12 )
			{
				pp->xboff = pp->pchg[0] * 80 ;
				pp->xmoff = pp->pchg[0] * 80 ;
			}
			else
			{
				pp->idno = 0 ;
				pp->mode = 0 ;
			}
			break ;
	}

}



