/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   ���̑� ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*				    	���[�v����						*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
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

	// 0�Ԗڂ̓y�� ( ���� )
	if ( (pp->xp > 0) && (pp->xp < 32) && (pp->yp > 64) && (pp->yp < 160) )
	{
		// �E����3�Ԗڂ̓y�ǂɔ��
		pp->xp = 736.0 ;								// �E���̍��W
		pp->yp = FLIMIT ;								// �n�ʂ̍��W
	}

	// 1�Ԗڂ̓y�� ( �E�� )
	if ( (pp->xp > 768.0) && (pp->xp < WINDOW_W) && (pp->yp > 64) && (pp->yp < 160) )
	{
		// ������2�Ԗڂ̓y�ǂɔ��
		pp->xp = 64.0 ;									// �����̍��W
		pp->yp = FLIMIT ;								// �n�ʂ̍��W
	}

	// 2�Ԗڂ̓y�� ( ���� )
	if ( (pp->xp > 0) && (pp->xp < 32) && (pp->yp > (FLIMIT-32)) && (pp->yp < (FLIMIT+32)) )
	{
		// �E���2�Ԗڂ̓y�ǂɔ��
		pp->xp = 736.0 ;								// �E���̍��W
		pp->yp = 96.0 ;									// ��̃u���b�N���̍��W
	}

	// 3�Ԗڂ̓y�� ( �E�� )
	if ( (pp->xp > 768.0) && (pp->xp < WINDOW_W) && (pp->yp > (FLIMIT-32)) && (pp->yp < (FLIMIT+32)) )
	{
		// �����0�Ԗڂ̓y�ǂɔ��
		pp->xp = 64.0 ;									// �����̍��W
		pp->yp = 96.0 ;									// ��̃u���b�N���̍��W
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
/*				  �󂫃I�u�W�F�N�g �T�[�`				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
int ObjSearch( int st , int tm )
{
	int no = -1 ;												// �����Z�b�g

	for (  ; st < (st+tm) ; st++ )								// �w��l�܂ŃJ�E���g
	{
		if ( obj[st].idno == 0 )								// �`�悳��ĂȂ� idnum
		{
			no = st ;											// no �� ���̔z�� ������
			return no ;											// no ��Ԃ�
		}
	}

	return no ;													// no ��Ԃ�

}


