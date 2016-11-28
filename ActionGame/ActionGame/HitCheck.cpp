/*______________________________________________________________________________________________________________*/
/*																												*/
/*												  COLLISON CHECK												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*				  足元チェック あたり判定				*/
/*			  0 : 床なし		その他 : 床の座標		*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
int FootCheck( void )
{
	int iRet = 0 ;										// 返り値
	int i ;												// blk[] のカウント用
	int pl , py , pr ;									// PLAYER のあたり判定
	int bl , br , bu , bd ;								// BLOCK のあたり判定

	edflg = -1 ;

	/*
		ジャンプしてるとき
	*/
	if ( pp->yspd < 0.0 )								// 上に動いているとき
	{
		return 0 ;										// 地面がない事にする	( ジャンプ中に床に乗ってしまうため )
	}

	/*
		着地
	*/
	if ( pp->yp >= FLIMIT )								// 地面より下になった時
	{
		return (int)FLIMIT ;							// 地面の座標を送る
	}

	/*
		プレイヤーのあたり判定
		 > 3つあたり判定をとる
	*/
	py = (int)pp->yp ;									// プレイヤーの中心点
	pl = (int)pp->xp - 15.0 ;							// プレイヤーの左足
	pr = (int)pp->xp + 15.0 ;							// プレイヤーの右足

	/*
		ブロックのあたり判定
	*/
	for ( i = 0 ; i < MAXBLK ; i++ )					// BLOCK を全部見る
	{
		if ( blk[i].idno == ID_BLOCK )					// 普通のブロックだったとき
		{
			bl = (int)blk[i].xp - 16.0 ;				// BLOCK の左側
			br = (int)blk[i].xp + 16.0 ;				// BLOCK の右側
			bu = (int)blk[i].yp ;						// BLOCK の上側
			bd = (int)blk[i].yp + 20 ;					// BLOCK の下側

			if ( (py >= bu) && (py <= bd) )				// 上下のあたり判定
			{
				if ( (pl >= bl) && (pl <= br) )			// プレイヤーの右足とブロックのあたり判定
				{
					iRet = (int)blk[i].yp ;				// 当たった BLOCK の座標を渡す

					if ( blk[i].yspd < 0.0 )
					{
						edflg = (int)blk[i].xp ;
					}
				}
				if ( (pr >= bl) && (pr <= br) )			// プレイヤーの左足とブロックのあたり判定
				{
					iRet = (int)blk[i].yp ;				// 当たった BLOCK の座標を渡す

					if ( blk[i].yspd < 0.0 )
					{
						edflg = (int)blk[i].xp ;
					}
				}
			}
		}
	}

	return iRet ;										// 返り値で返す
}


/*______________________________________________________*/
/*				  頭上チェック あたり判定				*/
/*			  0 : 		その他 : 		*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
int HeadCheck( void )
{
	int iRet = 0 ;
	int i ;
	int x , y ;											// 頭上のあたり判定
	int bl , br , bu , bd ;								// BLOCK の判定用

	if ( pp->yspd > 0.0 )								// 落下中の時
	{
		return 0 ;										// 0 を返す ( 落下中は頭上には何もない )
	}

	/*
		プレイヤーのあたり判定
		 > 3つあたり判定をとる
	*/
	y = (int)pp->yp - 70 ;								// プレイヤーの中心点
	x = (int)pp->xp ;									// プレイヤーの左足

	/*
		ブロックのあたり判定
	*/
	for ( i = 0 ; i < MAXBLK ; i++ )					// BLOCK を全部見る
	{
		if ( blk[i].idno == ID_BLOCK )					// 普通のブロックだったとき
		{
			bl = (int)blk[i].xp - 16.0 ;				// BLOCK の左側
			br = (int)blk[i].xp + 16.0 ;				// BLOCK の右側
			bu = (int)blk[i].yp + 16 ;					// BLOCK の上側
			bd = (int)blk[i].yp + 32 ;					// BLOCK の下側

			if ( (y >= bu) && (y <= bd) )				// 上下のあたり判定
			{
				if ( (x >= bl) && (x <= br) )			// プレイヤーの右側とブロックのあたり判定
				{
					iRet = -1 ;							// 当たった BLOCK の座標を渡す

					if ( blk[i].mode == 1 )				// 当たった BLOCK が動いてない時
					{
						blk[i].mode = 2 ;				// 当たった BLOCK のモードを変える
					}
					break ;								// 何度も当たらないので抜ける
				}
			}
		}
	}

	return iRet ;										// 返り値で返す

}

/*______________________________________________________*/
/*				 チェック あたり判定				*/
/*			  0 : 		その他 : 		*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void BBcheck( void )
{
	int pl , pr , pu , pd ;
	int el , er , eu , ed ;

	pl = (int)obj[O_PLY].xp - 15 ;
	pr = (int)obj[O_PLY].xp + 15 ;
	pu = (int)obj[O_PLY].yp - 60 ;
	pd = (int)obj[O_PLY].yp ;

	el = (int)pp->xp - 15 ;
	er = (int)pp->xp + 15 ;
	eu = (int)pp->yp - 60 ;
	ed = (int)pp->yp ;

	if ( (pl < er) && (pr > el) && (pu < ed) && (pd > eu) )
	{
		pp->mode = 3 ;
		obj[O_PLY].mode = 9 ;
	}

}

/*______________________________________________________*/
/*				 攻撃チェック あたり判定				*/
/*			  0 : 		その他 : 						*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void PAcheck( void )
{
	int i ;
	int px , py ;
	int el , er , eu , ed ;

	py = (int)pp->yp - 30 ;
	if ( pp->lrflg == 0 )
	{
		px = (int)pp->xp - 50 ;
	}
	else
	{
		px = (int)pp->xp + 50 ;
	}

	for ( i = 0 ; i < 10 ; i++ )
	{
		if ( obj[O_ENE+i].idno != 0 )
		{
			el = (int)obj[O_ENE+i].xp - 20 ;
			er = (int)obj[O_ENE+i].xp + 20 ;
			eu = (int)obj[O_ENE+i].yp - 40 ;
			ed = (int)obj[O_ENE+i].yp ;


			if ( (px > el) && (px < er) && (py > eu) && (py < ed) )
			{
				if ( obj[O_ENE+i].mode == 8 )
				{
					obj[O_ENE+i].mode = 9 ;
				}

				if ( obj[O_ENE+i].mode == 2 )
				{
					obj[O_ENE+i].mode = 12 ;
				}

			}
		}
	}

}


