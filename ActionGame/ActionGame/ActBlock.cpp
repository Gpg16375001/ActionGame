/*______________________________________________________________________________________________________________*/
/*																												*/
/*												�u���b�N�̏���													*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					  �u���b�N�̃Z�b�g					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void BlockSet( void )
{
	int y , x ;
	int i ;

	i = 0 ;												// i �̏����Z�b�g
	for ( y = 0 ; y < 18 ; y++ )
	{
		for ( x = 0 ; x < 25 ; x++ )
		{
			if ( (map[y][x] != 0) && (map[y][x] != 8) )	// ���Ă� MAP �̍��W�ɉ��������Ă���Ƃ�
			{
				blk[i].idno = ID_BLOCK ;				// ���̏ꏊ�Ƀu���b�N������
				blk[i].mode = 0 ;						// MODE �������Z�b�g�ɂ���
				blk[i].bno = map[y][x] ;				// BLOCK NUMBER �Ƀ}�b�v�ɓ����Ă��鐔�l������
														//  > �f�̃u���b�N�̐F��ς��邽��
				blk[i].xp = x * 32 + 16 ;				// X ���W�����킹��
				blk[i].yp = y * 32 ;					// Y ���W�����킹��

				i++ ;									// i ���C���N�������g	���̃u���b�N�����邽��
			}
		}
	}

}

/*______________________________________________________*/
/*					 BLOCK �̃A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActBlock( void )
{
	switch ( bp->mode )
	{
		case 0:
			bp->yspd = 0 ;
			bp->mode = 1 ;
			bp->dspf = 1 ;								// �O�F��\��	1�F�\��
			bp->xboff = 0 ;								// �w�I�t�Z�b�g	anim
			bp->yboff = (bp->bno -1) * 32 ;				// �x�I�t�Z�b�g
			break ;

		case 1 :
			break ;

		case 2 :
			bp->pchg[0] = 0 ;							// BLOCK �A�j���@�J�E���g
			bp->ys = bp->yp ;							// �����̈ʒu���o���Ă���
			bp->yspd = -4.0 ;							// ��ɓ���

			bp->mode = 3 ;								// ���[�h�ύX
			break ;

		case 3 :
			bp->yspd += 0.5 ;							// �d��
			bp->yp += bp->yspd ;						// �c�����ɓ���
			if ( bp->yp >= bp->ys )						// BLOCK �����̈ʒu�ɖ߂�����
			{
				bp->yspd = 0 ;
				bp->yp = bp->ys ;						// BLOCK �����̈ʒu�ɖ߂� ( �����\�������邽�� )
				bp->mode = 0 ;							// mode ��ʏ��Ԃɖ߂�
				bp->pchg[0] = 0 ;						// �J�E���g��0�ɖ߂�
			}

			bp->pchg[0]++ ;								// �J�E���g�A�b�v�@���̃C���X�g�ɍs������
			if ( bp->pchg[0] >= 6 )						// 6 ���傫���Ȃ�����
			{
				bp->pchg[0] = 0 ;						// 0 �ɖ߂�
			}
			bp->xboff = bp->pchg[0] * 32 ;				// ���̃C���X�g��`��
			break ;

	}
}


