/*______________________________________________________________________________________________________________*/
/*																												*/
/*												�^�C�g���A�N�V����												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					�^�C�g���̃A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActTitle( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// �O�F��\��	1�F�\��
			pp->xp = 0 ;								// �X�N���[���w���W
			pp->yp = 0 ;								// �X�N���[���x���W
			pp->xsize = WINDOW_W ;						// �w�T�C�Y
			pp->ysize = WINDOW_H ;						// �x�T�C�Y
			pp->xboff = 0 ;								// �w�I�t�Z�b�g
			pp->yboff = 0 ;								// �x�I�t�Z�b�g
			pp->xmoff = 0 ;								// �w�}�X�N
			pp->ymoff = 0 ;								// �x�}�X�N
			pp->idx = 0 ;								// �摜�ԍ�

			pp->mode = 1 ;								// �A�N�V�����Ǘ��ԍ�
			break ;

		case 1 :
			break ;

	}

}

/*______________________________________________________*/
/*					�X�^�[�g�̃A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActStart( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// �O�F��\��	1�F�\��
			pp->xp = WINDOW_W / 2 ;						// �X�N���[���w���W
			pp->yp = 480 ;								// �X�N���[���x���W
			pp->xsize = 256 ;							// �w�T�C�Y
			pp->ysize = 40 ;							// �x�T�C�Y
			pp->xboff = 0 ;								// �w�I�t�Z�b�g
			pp->yboff = 0 ;								// �x�I�t�Z�b�g
			pp->xmoff = 0 ;								// �w�}�X�N
			pp->ymoff = 40 ;							// �x�}�X�N
			pp->xoff = -128 ;							// �w���S�_
			pp->yoff = -20 ;							// �x���S�_
			pp->idx = 1 ;								// �摜�ԍ�

			pp->mode = 1 ;								// �A�N�V�����Ǘ��ԍ�
			pp->pchg[4] = 0 ;
			pp->pchg[2] = 0 ;
			break ;

		case 1 :
			/*
				�_�ł�����v���O����
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

			if (GetKeyState(VK_SPACE) < 0)				// SPACE KEY �������ꂽ�Ƃ�
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

/*______________________________________________________________________________________________________________*/
/*																												*/
/*												 �w�i �A�N�V����												*/
/*______________________________________________________________________________________________________________*/

/*______________________________________________________*/
/*							 �w�i						*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActBg( void )
{
	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// �O�F��\��	1�F�\��
			pp->xp = 0 ;								// �X�N���[���w���W
			pp->yp = 0 ;								// �X�N���[���x���W
			pp->xsize = WINDOW_W ;						// �w�T�C�Y
			pp->ysize = WINDOW_H ;						// �x�T�C�Y
			pp->xboff = 0 ;								// �w�I�t�Z�b�g
			pp->yboff = 0 ;								// �x�I�t�Z�b�g
			pp->xmoff = 0 ;								// �w�}�X�N
			pp->ymoff = 0 ;								// �x�}�X�N
			pp->idx = 2 ;								// �摜�ԍ�

			pp->mode = 1 ;								// �A�N�V�����Ǘ��ԍ�
			break ;

		case 1 :
			break ;

	}

}


