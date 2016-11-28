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
	int i ;
	int pl , py , pr ;									// PLAYER �̂����蔻��

	int Holeup[][4] = {
//		{ up , down , left , right } ,
		{  70 , 128 ,   0 ,  96 } ,						// ����� 0�� �̓y��
		{  70 , 128 , 704 , 800 } ,						// �E��� 1�� �̓y��
		{ 550 , 580 ,   0 ,  96 } ,						// ����� 2�� �̓y��
		{ 550 , 580 , 704 , 800 } ,						// �E��� 3�� �̓y��
	} ;

	/*
		�v���C���[�̂����蔻��
		 > 3�����蔻����Ƃ�
	*/
	py = (int)pp->yp ;									// �v���C���[�̒��S�_
	pl = (int)(pp->xp - 15.0) ;							// �v���C���[�̍���
	pr = (int)(pp->xp + 15.0) ;							// �v���C���[�̉E��

	/*
		�y�ǂ̂����蔻��
	*/
	for ( i = 0 ; i < 4 ; i++ )
	{
		if ( (py >= Holeup[i][0]) && (py <= Holeup[i][1]) )	// �㉺�̂����蔻��
		{
			if ( (i == 0) || (i == 1) )
			{
				// �����ɓ���Ƃ�
				if ( (pl >= Holeup[0][2]) && (pl <= Holeup[0][3])
					|| (pr >= Holeup[1][2]) && (pr <= Holeup[1][3]) )	  // �v���C���[  �̉E���ƃu���b�N�̂����蔻��
				{
					pp->yp = 86 ;							// �������� BLOCK �̍��W��n��
					pp->pchg[4] = 1 ;						// �y�ǂ̒����ǂ����̃t���O			
				}
				else
				{
					pp->pchg[4] = 0 ;						// �y�ǂ̒����ǂ����̃t���O			
				}
			}

			if ( (i == 2) || (i == 3) )
			{
				// �����ɓ���Ƃ�
				if ( (pl >= Holeup[2][2]) && (pl <= Holeup[2][3])
					|| (pr >= Holeup[3][2]) && (pr <= Holeup[3][3]) )	// �v���C���[�̉E���ƃu���b�N�̂����蔻��
				{
					pp->yp = 566 ;							// �������� BLOCK �̍��W��n��
					pp->pchg[4] = 1 ;						// �y�ǂ̒����ǂ����̃t���O			
				}
				else
				{
					pp->pchg[4] = 0 ;						// �y�ǂ̒����ǂ����̃t���O			
				}
			}
			pp->yspd = 0 ;
		}
	}

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



