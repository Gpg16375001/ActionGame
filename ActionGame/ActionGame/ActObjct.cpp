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
			pp->dspf = 1 ;
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

