/*______________________________________________________________________________________________________________*/
/*																												*/
/*												ƒ^ƒCƒgƒ‹ƒAƒNƒVƒ‡ƒ“												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					ƒ^ƒCƒgƒ‹‚ÌƒAƒNƒVƒ‡ƒ“				*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActTitle( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ‚OF”ñ•\Ž¦	1F•\Ž¦
			pp->xp = 0 ;								// ƒXƒNƒŠ[ƒ“‚wÀ•W
			pp->yp = 0 ;								// ƒXƒNƒŠ[ƒ“‚xÀ•W
			pp->xsize = WINDOW_W ;						// ‚wƒTƒCƒY
			pp->ysize = WINDOW_H ;						// ‚xƒTƒCƒY
			pp->xboff = 0 ;								// ‚wƒIƒtƒZƒbƒg
			pp->yboff = 0 ;								// ‚xƒIƒtƒZƒbƒg
			pp->xmoff = 0 ;								// ‚wƒ}ƒXƒN
			pp->ymoff = 0 ;								// ‚xƒ}ƒXƒN
			pp->idx = 0 ;								// ‰æ‘œ”Ô†

			pp->mode = 1 ;								// ƒAƒNƒVƒ‡ƒ“ŠÇ—”Ô†
			break ;

		case 1 :
			break ;

	}

}

/*______________________________________________________*/
/*					ƒXƒ^[ƒg‚ÌƒAƒNƒVƒ‡ƒ“				*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActStart( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ‚OF”ñ•\Ž¦	1F•\Ž¦
			pp->xp = WINDOW_W / 2 ;						// ƒXƒNƒŠ[ƒ“‚wÀ•W
			pp->yp = 480 ;								// ƒXƒNƒŠ[ƒ“‚xÀ•W
			pp->xsize = 256 ;							// ‚wƒTƒCƒY
			pp->ysize = 40 ;							// ‚xƒTƒCƒY
			pp->xboff = 0 ;								// ‚wƒIƒtƒZƒbƒg
			pp->yboff = 0 ;								// ‚xƒIƒtƒZƒbƒg
			pp->xmoff = 0 ;								// ‚wƒ}ƒXƒN
			pp->ymoff = 40 ;							// ‚xƒ}ƒXƒN
			pp->xoff = -128 ;							// ‚w’†S“_
			pp->yoff = -20 ;							// ‚x’†S“_
			pp->idx = 1 ;								// ‰æ‘œ”Ô†

			pp->mode = 1 ;								// ƒAƒNƒVƒ‡ƒ“ŠÇ—”Ô†
			pp->pchg[4] = 0 ;
			pp->pchg[2] = 0 ;
			break ;

		case 1 :
			/*
				“_–Å‚³‚¹‚éƒvƒƒOƒ‰ƒ€
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

			if (GetKeyState(VK_SPACE) < 0)				// SPACE KEY ‚ª‰Ÿ‚³‚ê‚½‚Æ‚«
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



