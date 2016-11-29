/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   Object ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

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

/*______________________________________________________*/
/*						�y�ǂ̔z�u						*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActHole( void )
{
	int HoleTbl[4][3] = {
		{  50 , 100 , 100 } ,							// 0�Ԃ̓y��
		{ 750 , 100 ,   0 } ,							// 1�Ԃ̓y��
		{  50 , 578 , 100 } ,							// 2�Ԃ̓y��
		{ 750 , 578 ,   0 } ,							// 3�Ԃ̓y��
	} ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// �O�F��\��	1�F�\��
			pp->xsize = 100 ;							// �w�T�C�Y
			pp->ysize = 100 ;							// �x�T�C�Y
			pp->yboff = 0 ;								// �x�I�t�Z�b�g
			pp->ymoff = 100 ;							// �x�}�X�N
			pp->xoff = -50 ;							// �w�}�X�N
			pp->yoff = -100 ;							// �x�}�X�N
			pp->idx = 8 ;								// �摜�ԍ�
			pp->mode = 1 ;								// �A�N�V�����Ǘ��ԍ�

			pp->xp = (double)HoleTbl[pp->cnt][0] ;		// �X�N���[���w���W
			pp->yp = (double)HoleTbl[pp->cnt][1] ;		// �X�N���[���x���W
			pp->xboff = HoleTbl[pp->cnt][2] ;			// �w�I�t�Z�b�g
			pp->xmoff = HoleTbl[pp->cnt][2] ;			// �w�}�X�N
			break ;

		case 1 :
			break ;

	}
}

/*______________________________________________________*/
/*						�y�ǂ̔z�u						*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActHole2( void )
{
	double xm , ym ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// �O�F��\��	1�F�\��
			pp->xsize = 100 ;							// �w�T�C�Y
			pp->ysize = 150 ;							// �x�T�C�Y
			xdk = 100 ;
			ydk = 150 ;
			pp->yboff = 0 ;								// �x�I�t�Z�b�g
			pp->ymoff = 0 ;								// �x�}�X�N
			pp->xoff = -50 ;							// �w�}�X�N
			pp->yoff = -150 ;							// �x�}�X�N
			pp->idx = 10 ;								// �摜�ԍ�
			pp->mode = 1 ;								// �A�N�V�����Ǘ��ԍ�

			pp->xp = (double)400 ;						// �X�N���[���w���W
			pp->yp = (double)676 ;						// �X�N���[���x���W
			pp->xboff = 0 ;								// �w�I�t�Z�b�g
			pp->xmoff = 100 ;							// �w�}�X�N
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->cnt -= 10 ;
			xm = pp->xp ;
			ym = pp->yp ;
			xdk = cos( 3.14 / 180 * pp->cnt ) * 40.0 ;		// *���a
			ydk = sin( 3.14 / 180 * pp->cnt ) * 40.0 ;

			xdk += xm ;
			ydk += ym ;
			break ;

	}
}


