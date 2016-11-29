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
			pp->dspf = 0 ;								// 0 : ��\��
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
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 0 ;								// �O�F��\��	1�F�\��
			pp->xsize = 100 ;							// �w�T�C�Y
			pp->ysize = 150 ;							// �x�T�C�Y
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
			break ;

	}
}


/*______________________________________________________*/
/*						����~�炷						*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActSnow( void )
{
	int no ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// �O�F��\��	1�F�\��
			pp->yp = 0 ;
			pp->xsize = 16 ;							// �w�T�C�Y
			pp->ysize = 16 ;							// �x�T�C�Y
			pp->yboff = 16 * 4 ;						// �x�I�t�Z�b�g
			pp->ymoff = 0 ;								// �x�}�X�N
			pp->xoff = -8 ;								// �w�}�X�N
			pp->yoff = -8 ;								// �x�}�X�N
			pp->yspd = 8 ;
			pp->idx = 11 ;								// �摜�ԍ�
			pp->mode = 1 ;								// �A�N�V�����Ǘ��ԍ�

			pp->xboff = 0 ;								// �w�I�t�Z�b�g
			pp->xmoff = 16 * 4 ;						// �w�}�X�N
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
			if ( no != -1 )								// �󂢂Ă�����
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
/*							 �w�i						*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActBg( void )
{
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// �O�F��\��	1�F�\��
			pp->xp = 0 ;								// �X�N���[���w���W
			pp->yp = -1280 ;							// �X�N���[���x���W
			pp->xsize = WINDOW_W ;						// �w�T�C�Y
			pp->ysize = WINDOW_H * 3 ;					// �x�T�C�Y
			pp->xboff = 0 ;								// �w�I�t�Z�b�g
			pp->yboff = 0 ;								// �x�I�t�Z�b�g
			pp->xmoff = 0 ;								// �w�}�X�N
			pp->ymoff = 0 ;								// �x�}�X�N
			pp->idx = 2 ;								// �摜�ԍ�

			pp->mode = 1 ;								// �A�N�V�����Ǘ��ԍ�
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
/*					  ���� �A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActBomb( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				���� �����Z�b�g
			*/
			pp->dspf = 1 ;
			pp->xsize = 80 ;
			pp->ysize = 80 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 80 ;
			pp->idx = 12 ;
			pp->xoff = -40 ;										// ���S�_�̕ύX X��
			pp->yoff = -40 ;										// ���S�_�̕ύX Y��

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



