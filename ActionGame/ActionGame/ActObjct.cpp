/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   Object ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*						Boo�̃A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActBoo( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 0 ;
			pp->xsize = 80 ;							// �w�T�C�Y
			pp->ysize = 80 ;							// �x�T�C�Y
			pp->xboff = 0 ;								// �w�I�t�Z�b�g
			pp->yboff = 0 ;								// �x�I�t�Z�b�g
			pp->xmoff = 0 ;								// �w�}�X�N
			pp->ymoff = 80 ;							// �x�}�X�N
			pp->xoff = -40 ;							// �w�}�X�N
			pp->yoff = 0 ;								// �x�}�X�N
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
			pp->xmoff = pp->xboff ;								// �w�}�X�N
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
/*						���n�̃A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActStep( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 0 ;
			pp->xsize = 80 ;							// �w�T�C�Y
			pp->ysize = 80 ;							// �x�T�C�Y
			pp->xboff = 0 ;								// �w�I�t�Z�b�g
			pp->yboff = 0 ;								// �x�I�t�Z�b�g
			pp->xmoff = 0 ;								// �w�}�X�N
			pp->ymoff = 80 ;							// �x�}�X�N
			pp->xoff = -40 ;							// �w�}�X�N
			pp->yoff = 0 ;								// �x�}�X�N
			pp->idx = 9 ;
			pp->mode = 1 ;
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->xboff = pp->cnt * 80 + 240 ;
			pp->xmoff = pp->xboff ;						// �w�}�X�N
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


