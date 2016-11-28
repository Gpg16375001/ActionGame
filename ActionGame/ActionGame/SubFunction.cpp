/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   ‚»‚Ì‘¼ ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*				    	ƒ[ƒvˆ—						*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActWarp( void )
{
	if ( pp->xp < 0 )
	{
		pp->xp = WINDOW_W - 10 ;
	}
	if ( pp->xp > WINDOW_W )
	{
		pp->xp = 10 ;
	}

	// 0”Ô–Ú‚Ì“yŠÇ ( ¶ã )
	if ( (pp->xp > 0) && (pp->xp < 32) && (pp->yp > 64) && (pp->yp < 160) )
	{
		// ‰E‰º‚Ì3”Ô–Ú‚Ì“yŠÇ‚É”ò‚Ô
		pp->xp = 736.0 ;								// ‰E‘¤‚ÌÀ•W
		pp->yp = FLIMIT ;								// ’n–Ê‚ÌÀ•W
	}

	// 1”Ô–Ú‚Ì“yŠÇ ( ‰Eã )
	if ( (pp->xp > 768.0) && (pp->xp < WINDOW_W) && (pp->yp > 64) && (pp->yp < 160) )
	{
		// ¶‰º‚Ì2”Ô–Ú‚Ì“yŠÇ‚É”ò‚Ô
		pp->xp = 64.0 ;									// ¶‘¤‚ÌÀ•W
		pp->yp = FLIMIT ;								// ’n–Ê‚ÌÀ•W
	}

	// 2”Ô–Ú‚Ì“yŠÇ ( ¶‰º )
	if ( (pp->xp > 0) && (pp->xp < 32) && (pp->yp > (FLIMIT-32)) && (pp->yp < (FLIMIT+32)) )
	{
		// ‰Eã‚Ì2”Ô–Ú‚Ì“yŠÇ‚É”ò‚Ô
		pp->xp = 736.0 ;								// ‰E‘¤‚ÌÀ•W
		pp->yp = 96.0 ;									// ã‚ÌƒuƒƒbƒN°‚ÌÀ•W
	}

	// 3”Ô–Ú‚Ì“yŠÇ ( ‰E‰º )
	if ( (pp->xp > 768.0) && (pp->xp < WINDOW_W) && (pp->yp > (FLIMIT-32)) && (pp->yp < (FLIMIT+32)) )
	{
		// ¶ã‚Ì0”Ô–Ú‚Ì“yŠÇ‚É”ò‚Ô
		pp->xp = 64.0 ;									// ¶‘¤‚ÌÀ•W
		pp->yp = 96.0 ;									// ã‚ÌƒuƒƒbƒN°‚ÌÀ•W
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



