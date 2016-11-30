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
	int no ;
	int pl , py , pr ;									// PLAYER のあたり判定
	int bl , br , bu , bd ;								// BLOCK のあたり判定

	edflg = -1 ;


	/*
		着地
	*/
	if ( (pp->yspd > 0.0) && (pp->yp >= FLIMIT) )		// 上に動いているとき
	{
		no = ObjSearch( O_BOO , MAXBOO ) ;
		if ( no != -1 )									// 空いていたら
		{
			obj[no].idno = ID_STEP ;
			obj[no].mode = 0 ;
			obj[no].xp = pp->xp ;
			obj[no].yp = pp->yp - 82 ;
		}
	}

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
	pl = (int)(pp->xp - 15.0) ;							// プレイヤーの左足
	pr = (int)(pp->xp + 15.0) ;							// プレイヤーの右足

	/*
		ブロックのあたり判定
	*/
	for ( i = 0 ; i < MAXBLK ; i++ )					// BLOCK を全部見る
	{
		if ( blk[i].idno == ID_BLOCK )					// 普通のブロックだったとき
		{
			bl = (int)(blk[i].xp - 16.0) ;				// BLOCK の左側
			br = (int)(blk[i].xp + 16.0) ;				// BLOCK の右側
			bu = (int)blk[i].yp ;						// BLOCK の上側
			bd = (int)(blk[i].yp + 20) ;				// BLOCK の下側

			if ( (py >= bu) && (py <= bd) )				// 上下のあたり判定
			{
				if ( (pl >= bl) && (pl <= br) )			// プレイヤーの右足とブロックのあたり判定
				{
					iRet = (int)blk[i].yp ;				// 当たった BLOCK の座標を渡す

					if ( blk[i].yspd < 0.0 )
					{
						edflg = (int)blk[i].xp ;
					}

					/*
						着地 煙アクション
					*/
					if ( pp->yspd > 0.0 )				// 上に動いているとき
					{
						no = ObjSearch( O_BOO , MAXBOO ) ;
						if ( no != -1 )					// 空いていたら
						{
							obj[no].idno = ID_STEP ;
							obj[no].mode = 0 ;
							obj[no].xp = pp->xp ;
							obj[no].yp = pp->yp - 82 ;
						}
					}
				}
				if ( (pr >= bl) && (pr <= br) )			// プレイヤーの左足とブロックのあたり判定
				{
					iRet = (int)blk[i].yp ;				// 当たった BLOCK の座標を渡す

					if ( blk[i].yspd < 0.0 )
					{
						edflg = (int)blk[i].xp ;
					}

					/*
						着地
					*/
					if ( pp->yspd > 0.0 )				// 上に動いているとき
					{
						no = ObjSearch( O_BOO , MAXBOO ) ;
						if ( no != -1 )					// 空いていたら
						{
							obj[no].idno = ID_STEP ;
							obj[no].mode = 0 ;
							obj[no].xp = pp->xp ;
							obj[no].yp = pp->yp - 82 ;
						}
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
	int pl , py , pr ;									// 頭上のあたり判定
	int bl , br , bu , bd ;								// BLOCK の判定用

	if ( pp->yspd > 0.0 )								// 落下中の時
	{
		return 0 ;										// 0 を返す ( 落下中は頭上には何もない )
	}

	/*
		プレイヤーのあたり判定
		 > 3つあたり判定をとる
	*/
	py = (int)(pp->yp - 70) ;							// プレイヤーの中心点	頭
	pl = (int)(pp->xp - 15.0) ;							// プレイヤーの左		頭
	pr = (int)(pp->xp + 15.0) ;							// プレイヤーの右		頭

	/*
		ブロックのあたり判定
	*/
	for ( i = 0 ; i < MAXBLK ; i++ )					// BLOCK を全部見る
	{
		if ( blk[i].idno == ID_BLOCK )					// 普通のブロックだったとき
		{
			bl = (int)(blk[i].xp - 16.0) ;				// BLOCK の左側
			br = (int)(blk[i].xp + 16.0) ;				// BLOCK の右側
			bu = (int)(blk[i].yp + 16) ;				// BLOCK の上側
			bd = (int)(blk[i].yp + 32) ;				// BLOCK の下側

			if ( (py >= bu) && (py <= bd) )				// 上下のあたり判定
			{
				if ( (pl >= bl) && (pl <= br) )			// プレイヤーの右足とブロックのあたり判定
				{
					iRet = -1 ;							// 当たった BLOCK の座標を渡す

					if ( blk[i].mode == 1 )				// 当たった BLOCK が動いてない時
					{
						blk[i].mode = 2 ;				// 当たった BLOCK のモードを変える
					}
					break ;								// 何度も当たらないので抜ける
				}
				if ( (pr >= bl) && (pr <= br) )			// プレイヤーの左足とブロックのあたり判定
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
/*				  体チェック あたり判定					*/
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
/*				  体とブロックのあたり判定				*/
/*			  0 : 		その他 : 		*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
int Body_Block( void )
{
	int iRet = 0 ;										// 返り値
	int y ;
	int i ;												// blk[] のカウント用
	int no ;
	int bl , br , bu , bd ;								// BLOCK のあたり判定
	int pl , py , pr ;									// PLAYER のあたり判定
	int plc[2][4][3] = {								// PLAYER のあたり判定
		// 0 : 左向きの時
		{
//			{ left , right , ypos },
			{ 16 , 28 , 60 },
			{ 19 , 32 , 43 },
			{ 23 , 21 , 26 },
			{  4 , 20 , 12 },
		} ,

		// 1 : 右向きの時
		{
//			{ left , right , ypos },
			{ 28 , 16 , 60 },
			{ 32 , 19 , 43 },
			{ 21 , 23 , 26 },
			{ 20 ,  4 , 12 },
		} ,
	} ;

	for ( y = 0 ; y < 4 ; y++ )
	{
		/*
			プレイヤーのあたり判定
			 > 3x4つあたり判定をとる
		*/
		pl = (int)(pp->xp - plc[pp->lrflg][y][1]) ;
		pr = (int)(pp->xp + plc[pp->lrflg][y][2]) ;
		py = (int)(pp->yp - plc[pp->lrflg][y][3]) ;			// プレイヤーの中心点

		/*
			ブロックのあたり判定
		*/
		for ( i = 0 ; i < MAXBLK ; i++ )					// BLOCK を全部見る
		{
			if ( blk[i].idno == ID_BLOCK )					// 普通のブロックだったとき
			{
			
				bl = (int)(blk[i].xp - 16) ;				// BLOCK の左側
				br = (int)(blk[i].xp + 16 );				// BLOCK の右側
				bu = (int)blk[i].yp ;						// BLOCK の上側
				bd = (int)(blk[i].yp + 32) ;				// BLOCK の下側

				if ( (py >= bu) && (py <= bd) )				// 上下のあたり判定
				{
					if ( (pl >= bl) && (pl <= br) )			// プレイヤーの右とブロックのあたり判定
					{
						iRet = (int)blk[i].xp ;				// 当たった BLOCK の座標を渡す
					}
					if ( (pr >= bl) && (pr <= br) )			// プレイヤーの左とブロックのあたり判定
					{
						iRet = (int)blk[i].xp ;				// 当たった BLOCK の座標を渡す
					}
				}
			}
		}
	}

	return iRet ;											// 返り値で返す
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
		px = (int)pp->xp ;
	}
	else
	{
		px = (int)pp->xp ;
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


/*______________________________________________________*/
/*				  足元チェック あたり判定				*/
/*			  0 : 床なし		その他 : 床の座標		*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void FootHitCheck( void )
{
	int i ;
	int pl , py , pr ;									// PLAYER のあたり判定

	int Holeup[][4] = {
//		{ up , down , left , right } ,
		{  70 , 128 ,   0 ,  96 } ,						// 左上の 0番 の土管
		{  70 , 128 , 704 , 800 } ,						// 右上の 1番 の土管
		{ 550 , 580 ,   0 ,  96 } ,						// 左上の 2番 の土管
		{ 550 , 580 , 704 , 800 } ,						// 右上の 3番 の土管
	} ;

	/*
		プレイヤーのあたり判定
		 > 3つあたり判定をとる
	*/
	py = (int)pp->yp ;									// プレイヤーの中心点
	pl = (int)(pp->xp - 15.0) ;							// プレイヤーの左足
	pr = (int)(pp->xp + 15.0) ;							// プレイヤーの右足

	/*
		土管の中のあたり判定
	*/
	for ( i = 0 ; i < 4 ; i++ )
	{
		if ( (py >= Holeup[i][0]) && (py <= Holeup[i][1]) && (pp->mode != 4) )	// 上下のあたり判定
		{
			if ( (i == 0) || (i == 1) )
			{
				// 左側に入るとき
				if ( (pl >= Holeup[0][2]) && (pl <= Holeup[0][3])
					|| (pr >= Holeup[1][2]) && (pr <= Holeup[1][3]) ) // プレイヤー  の右足とブロックのあたり判定
				{
					pp->yp = 86 ;						// 当たった BLOCK の座標を渡す
					pp->pchg[4] = 1 ;					// 土管の中かどうかのフラグ			
				}
				else
				{
					pp->pchg[4] = 0 ;					// 土管の中かどうかのフラグ			
				}
			}

			if ( (i == 2) || (i == 3) )
			{
				// 左側に入るとき
				if ( (pl >= Holeup[2][2]) && (pl <= Holeup[2][3])
					|| (pr >= Holeup[3][2]) && (pr <= Holeup[3][3]) )	// プレイヤーの右足とブロックのあたり判定
				{
					pp->yp = 566 ;						// 当たった BLOCK の座標を渡す
					pp->pchg[4] = 1 ;					// 土管の中かどうかのフラグ			
				}
				else
				{
					pp->pchg[4] = 0 ;					// 土管の中かどうかのフラグ			
				}
			}
			pp->yspd = 0 ;
		}
	}
	
	/*
		土管のあたり判定
		上下左右
	*/
	if ( (pl <= 96) && (py >= (96 - 100)) && (py <= 42) )
	{
		pp->yp = 96 - 100 ;
		pp->mode = 2 ;
	}

	if ( (pr >= 704) && (py >= (96 - 100)) && (py <= 42) )
	{
		pp->yp = 96 - 100 ;
		pp->mode = 2 ;
	}

	if ( (pl <= 128 - 8) && ((py - 70) >= (576 - 120)) && ((py - 70) <= (576 - 90)) )
	{
		pp->xspd = 0 ;
		pp->xp = 128 ;
	}

	if ( (pr >= 672 + 8) && ((py - 70) >= (576 - 120)) && ((py - 70) <= (576 - 90)) )
	{
		pp->xspd = 0 ;
		pp->xp = 672 ;
	}

}


