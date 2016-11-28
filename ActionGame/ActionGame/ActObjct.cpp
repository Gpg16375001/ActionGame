/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   Object ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

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


