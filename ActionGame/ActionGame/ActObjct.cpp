/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   Object ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*						BooÇÃÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActBoo( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 0 ;								// 0 : îÒï\é¶
			pp->xsize = 80 ;							// ÇwÉTÉCÉY
			pp->ysize = 80 ;							// ÇxÉTÉCÉY
			pp->xboff = 0 ;								// ÇwÉIÉtÉZÉbÉg
			pp->yboff = 0 ;								// ÇxÉIÉtÉZÉbÉg
			pp->xmoff = 0 ;								// ÇwÉ}ÉXÉN
			pp->ymoff = 80 ;							// ÇxÉ}ÉXÉN
			pp->xoff = -40 ;							// ÇwÉ}ÉXÉN
			pp->yoff = 0 ;								// ÇxÉ}ÉXÉN
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
			pp->xmoff = pp->xboff ;								// ÇwÉ}ÉXÉN
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
/*						íÖínÇÃÉAÉNÉVÉáÉì				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActStep( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 0 ;
			pp->xsize = 80 ;							// ÇwÉTÉCÉY
			pp->ysize = 80 ;							// ÇxÉTÉCÉY
			pp->xboff = 0 ;								// ÇwÉIÉtÉZÉbÉg
			pp->yboff = 0 ;								// ÇxÉIÉtÉZÉbÉg
			pp->xmoff = 0 ;								// ÇwÉ}ÉXÉN
			pp->ymoff = 80 ;							// ÇxÉ}ÉXÉN
			pp->xoff = -40 ;							// ÇwÉ}ÉXÉN
			pp->yoff = 0 ;								// ÇxÉ}ÉXÉN
			pp->idx = 9 ;
			pp->mode = 1 ;
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->xboff = pp->cnt * 80 + 240 ;
			pp->xmoff = pp->xboff ;						// ÇwÉ}ÉXÉN
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
/*						ìyä«ÇÃîzíu						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActHole( void )
{
	int HoleTbl[4][3] = {
		{  50 , 100 , 100 } ,							// 0î‘ÇÃìyä«
		{ 750 , 100 ,   0 } ,							// 1î‘ÇÃìyä«
		{  50 , 578 , 100 } ,							// 2î‘ÇÃìyä«
		{ 750 , 578 ,   0 } ,							// 3î‘ÇÃìyä«
	} ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ÇOÅFîÒï\é¶	1ÅFï\é¶
			pp->xsize = 100 ;							// ÇwÉTÉCÉY
			pp->ysize = 100 ;							// ÇxÉTÉCÉY
			pp->yboff = 0 ;								// ÇxÉIÉtÉZÉbÉg
			pp->ymoff = 100 ;							// ÇxÉ}ÉXÉN
			pp->xoff = -50 ;							// ÇwÉ}ÉXÉN
			pp->yoff = -100 ;							// ÇxÉ}ÉXÉN
			pp->idx = 8 ;								// âÊëúî‘çÜ
			pp->mode = 1 ;								// ÉAÉNÉVÉáÉìä«óùî‘çÜ

			pp->xp = (double)HoleTbl[pp->cnt][0] ;		// ÉXÉNÉäÅ[ÉìÇwç¿ïW
			pp->yp = (double)HoleTbl[pp->cnt][1] ;		// ÉXÉNÉäÅ[ÉìÇxç¿ïW
			pp->xboff = HoleTbl[pp->cnt][2] ;			// ÇwÉIÉtÉZÉbÉg
			pp->xmoff = HoleTbl[pp->cnt][2] ;			// ÇwÉ}ÉXÉN
			break ;

		case 1 :
			break ;

	}
}

/*______________________________________________________*/
/*						ìyä«ÇÃîzíu						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActHole2( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 0 ;								// ÇOÅFîÒï\é¶	1ÅFï\é¶
			pp->xsize = 100 ;							// ÇwÉTÉCÉY
			pp->ysize = 150 ;							// ÇxÉTÉCÉY
			pp->yboff = 0 ;								// ÇxÉIÉtÉZÉbÉg
			pp->ymoff = 0 ;								// ÇxÉ}ÉXÉN
			pp->xoff = -50 ;							// ÇwÉ}ÉXÉN
			pp->yoff = -150 ;							// ÇxÉ}ÉXÉN
			pp->idx = 10 ;								// âÊëúî‘çÜ
			pp->mode = 1 ;								// ÉAÉNÉVÉáÉìä«óùî‘çÜ

			pp->xp = (double)400 ;						// ÉXÉNÉäÅ[ÉìÇwç¿ïW
			pp->yp = (double)676 ;						// ÉXÉNÉäÅ[ÉìÇxç¿ïW
			pp->xboff = 0 ;								// ÇwÉIÉtÉZÉbÉg
			pp->xmoff = 100 ;							// ÇwÉ}ÉXÉN
			pp->cnt = 0 ;
			break ;

		case 1 :
			break ;

	}
}

/*______________________________________________________*/
/*						ê·Çç~ÇÁÇ∑						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActSnow( void )
{
	int no ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ÇOÅFîÒï\é¶	1ÅFï\é¶
			pp->yp = 0 ;
			pp->xsize = 16 ;							// ÇwÉTÉCÉY
			pp->ysize = 16 ;							// ÇxÉTÉCÉY
			pp->yboff = 16 * 4 ;						// ÇxÉIÉtÉZÉbÉg
			pp->ymoff = 0 ;								// ÇxÉ}ÉXÉN
			pp->xoff = -8 ;								// ÇwÉ}ÉXÉN
			pp->yoff = -8 ;								// ÇxÉ}ÉXÉN
			pp->yspd = 8 ;
			pp->idx = 11 ;								// âÊëúî‘çÜ
			pp->mode = 1 ;								// ÉAÉNÉVÉáÉìä«óùî‘çÜ

			pp->xboff = 0 ;								// ÇwÉIÉtÉZÉbÉg
			pp->xmoff = 16 * 4 ;						// ÇwÉ}ÉXÉN
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
			if ( no != -1 )								// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
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
/*							 îwåi						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActBg( void )
{
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ÇOÅFîÒï\é¶	1ÅFï\é¶
			pp->xp = 0 ;								// ÉXÉNÉäÅ[ÉìÇwç¿ïW
			pp->yp = -1280 ;							// ÉXÉNÉäÅ[ÉìÇxç¿ïW
			pp->xsize = WINDOW_W ;						// ÇwÉTÉCÉY
			pp->ysize = WINDOW_H * 3 ;					// ÇxÉTÉCÉY
			pp->xboff = 0 ;								// ÇwÉIÉtÉZÉbÉg
			pp->yboff = 0 ;								// ÇxÉIÉtÉZÉbÉg
			pp->xmoff = 0 ;								// ÇwÉ}ÉXÉN
			pp->ymoff = 0 ;								// ÇxÉ}ÉXÉN
			pp->idx = 2 ;								// âÊëúî‘çÜ

			pp->mode = 1 ;								// ÉAÉNÉVÉáÉìä«óùî‘çÜ
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
/*					  îöî≠ ÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActBomb( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				îöî≠ èâä˙ÉZÉbÉg
			*/
			pp->dspf = 1 ;
			pp->xsize = 80 ;
			pp->ysize = 80 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 80 ;
			pp->idx = 12 ;
			pp->xoff = -40 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -40 ;										// íÜêSì_ÇÃïœçX Yé≤

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

/*______________________________________________________*/
/*					  îöî≠ ÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActSBom( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				îöî≠ èâä˙ÉZÉbÉg
			*/
			pp->dspf = 1 ;
			pp->xsize = 32 ;
			pp->ysize = 32 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 32 ;
			pp->idx = 13 ;
			pp->xoff = -16 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -16 ;										// íÜêSì_ÇÃïœçX Yé≤

			pp->mode = 1 ;

			pp->pchg[0] = 0 ;
//			mciSendString( TEXT("play SE_BOMB1 from 0 notify") , NULL , 0 , hwnd ) ;// bomb
			break ;

		case 1 :
			pp->pchg[0]++ ;
			if ( pp->pchg[0] < 12 )
			{
				pp->xboff = pp->pchg[0] * 32 ;
				pp->xmoff = pp->pchg[0] * 32 ;
			}
			else
			{
				pp->idno = 0 ;
				pp->mode = 0 ;
			}
			break ;
	}

}

/*______________________________________________________*/
/*							çUåÇ						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActAttack( void )
{
	int no ;
	int i ;
	int px , py ;
	int el , er , eu , ed ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ÇOÅFîÒï\é¶	1ÅFï\é¶
			pp->xsize = 16 ;							// ÇwÉTÉCÉY
			pp->ysize = 16 ;							// ÇxÉTÉCÉY
			pp->yboff = 16 * 6 ;						// ÇxÉIÉtÉZÉbÉg
			pp->ymoff = 16 * 6 ;						// ÇxÉ}ÉXÉN
			pp->xoff = -8 ;								// ÇwÉ}ÉXÉN
			pp->yoff = -8 ;								// ÇxÉ}ÉXÉN
			pp->yspd = 8 ;
			pp->idx = 11 ;								// âÊëúî‘çÜ
			pp->mode = 1 ;								// ÉAÉNÉVÉáÉìä«óùî‘çÜ

			pp->xboff = 0 ;								// ÇwÉIÉtÉZÉbÉg
			pp->xmoff = 16 * 4 ;						// ÇwÉ}ÉXÉN
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->xp += pp->xspd ;

			if ( (pp->xp < 0) || (pp->xp > WINDOW_W) )
			{
				pp->idno = 0 ;
			}

			py = (int)pp->yp ;
			px = (int)pp->xp ;
			for ( i = 0 ; i < MAXENE ; i++ )
			{
				if ( obj[O_ENE+i].idno != 0 )
				{
					el = (int)obj[O_ENE+i].xp - 20 ;
					er = (int)obj[O_ENE+i].xp + 20 ;
					eu = (int)obj[O_ENE+i].yp - 50 ;
					ed = (int)obj[O_ENE+i].yp ;

					if ( (px > el) && (px < er) && (py > eu) && (py < ed) )
					{
						if ( obj[O_ENE+i].mode == 8 )
						{
							obj[O_ENE+i].mode = 9 ;
							pp->idno = 0 ;

							no = ObjSearch( O_BOMB , MAXBOM ) ;
							if ( no != -1 )										// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
							{
								obj[no].idno = ID_SBOM ;
								obj[no].mode = 0 ;
								obj[no].xp = pp->xp ;
								obj[no].yp = pp->yp ;
							}
						}

						if ( obj[O_ENE+i].mode == 2 )
						{
							obj[O_ENE+i].mode = 12 ;
							pp->idno = 0 ;

							no = ObjSearch( O_BOMB , MAXBOM ) ;
							if ( no != -1 )										// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
							{
								obj[no].idno = ID_SBOM ;
								obj[no].mode = 0 ;
								obj[no].xp = pp->xp ;
								obj[no].yp = pp->yp ;
							}
						}

					}
				}
			}
			break ;

	}

}



