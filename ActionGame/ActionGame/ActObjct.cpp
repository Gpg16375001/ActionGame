/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   Object ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*						Boo‚ÌƒAƒNƒVƒ‡ƒ“					*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActBoo( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 0 ;
			pp->xsize = 80 ;							// ‚wƒTƒCƒY
			pp->ysize = 80 ;							// ‚xƒTƒCƒY
			pp->xboff = 0 ;								// ‚wƒIƒtƒZƒbƒg
			pp->yboff = 0 ;								// ‚xƒIƒtƒZƒbƒg
			pp->xmoff = 0 ;								// ‚wƒ}ƒXƒN
			pp->ymoff = 80 ;							// ‚xƒ}ƒXƒN
			pp->xoff = -40 ;							// ‚wƒ}ƒXƒN
			pp->yoff = 0 ;								// ‚xƒ}ƒXƒN
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
			pp->xmoff = pp->xboff ;								// ‚wƒ}ƒXƒN
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
/*						’…’n‚ÌƒAƒNƒVƒ‡ƒ“				*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActStep( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 0 ;
			pp->xsize = 80 ;							// ‚wƒTƒCƒY
			pp->ysize = 80 ;							// ‚xƒTƒCƒY
			pp->xboff = 0 ;								// ‚wƒIƒtƒZƒbƒg
			pp->yboff = 0 ;								// ‚xƒIƒtƒZƒbƒg
			pp->xmoff = 0 ;								// ‚wƒ}ƒXƒN
			pp->ymoff = 80 ;							// ‚xƒ}ƒXƒN
			pp->xoff = -40 ;							// ‚wƒ}ƒXƒN
			pp->yoff = 0 ;								// ‚xƒ}ƒXƒN
			pp->idx = 9 ;
			pp->mode = 1 ;
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->xboff = pp->cnt * 80 + 240 ;
			pp->xmoff = pp->xboff ;						// ‚wƒ}ƒXƒN
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
/*						“yŠÇ‚Ì”z’u						*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActHole( void )
{
	int HoleTbl[4][3] = {
		{  50 , 100 , 100 } ,							// 0”Ô‚Ì“yŠÇ
		{ 750 , 100 ,   0 } ,							// 1”Ô‚Ì“yŠÇ
		{  50 , 578 , 100 } ,							// 2”Ô‚Ì“yŠÇ
		{ 750 , 578 ,   0 } ,							// 3”Ô‚Ì“yŠÇ
	} ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ‚OF”ñ•\Ž¦	1F•\Ž¦
			pp->xsize = 100 ;							// ‚wƒTƒCƒY
			pp->ysize = 100 ;							// ‚xƒTƒCƒY
			pp->yboff = 0 ;								// ‚xƒIƒtƒZƒbƒg
			pp->ymoff = 100 ;							// ‚xƒ}ƒXƒN
			pp->xoff = -50 ;							// ‚wƒ}ƒXƒN
			pp->yoff = -100 ;							// ‚xƒ}ƒXƒN
			pp->idx = 8 ;								// ‰æ‘œ”Ô†
			pp->mode = 1 ;								// ƒAƒNƒVƒ‡ƒ“ŠÇ—”Ô†

			pp->xp = (double)HoleTbl[pp->cnt][0] ;		// ƒXƒNƒŠ[ƒ“‚wÀ•W
			pp->yp = (double)HoleTbl[pp->cnt][1] ;		// ƒXƒNƒŠ[ƒ“‚xÀ•W
			pp->xboff = HoleTbl[pp->cnt][2] ;			// ‚wƒIƒtƒZƒbƒg
			pp->xmoff = HoleTbl[pp->cnt][2] ;			// ‚wƒ}ƒXƒN
			break ;

		case 1 :
			break ;

	}
}

/*______________________________________________________*/
/*						“yŠÇ‚Ì”z’u						*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActHole2( void )
{
	double xm , ym ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ‚OF”ñ•\Ž¦	1F•\Ž¦
			pp->xsize = 100 ;							// ‚wƒTƒCƒY
			pp->ysize = 150 ;							// ‚xƒTƒCƒY
			xdk = 100 ;
			ydk = 150 ;
			pp->yboff = 0 ;								// ‚xƒIƒtƒZƒbƒg
			pp->ymoff = 0 ;								// ‚xƒ}ƒXƒN
			pp->xoff = -50 ;							// ‚wƒ}ƒXƒN
			pp->yoff = -150 ;							// ‚xƒ}ƒXƒN
			pp->idx = 10 ;								// ‰æ‘œ”Ô†
			pp->mode = 1 ;								// ƒAƒNƒVƒ‡ƒ“ŠÇ—”Ô†

			pp->xp = (double)400 ;						// ƒXƒNƒŠ[ƒ“‚wÀ•W
			pp->yp = (double)676 ;						// ƒXƒNƒŠ[ƒ“‚xÀ•W
			pp->xboff = 0 ;								// ‚wƒIƒtƒZƒbƒg
			pp->xmoff = 100 ;							// ‚wƒ}ƒXƒN
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->cnt -= 10 ;
			xm = pp->xp ;
			ym = pp->yp ;
			xdk = cos( 3.14 / 180 * pp->cnt ) * 40.0 ;		// *”¼Œa
			ydk = sin( 3.14 / 180 * pp->cnt ) * 40.0 ;

			xdk += xm ;
			ydk += ym ;
			break ;

	}
}


