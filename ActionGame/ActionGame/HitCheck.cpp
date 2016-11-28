/*______________________________________________________________________________________________________________*/
/*																												*/
/*												  COLLISON CHECK												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*				  �����`�F�b�N �����蔻��				*/
/*			  0 : ���Ȃ�		���̑� : ���̍��W		*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
int FootCheck( void )
{
	int iRet = 0 ;										// �Ԃ�l
	int i ;												// blk[] �̃J�E���g�p
	int pl , py , pr ;									// PLAYER �̂����蔻��
	int bl , br , bu , bd ;								// BLOCK �̂����蔻��

	edflg = -1 ;

	/*
		�W�����v���Ă�Ƃ�
	*/
	if ( pp->yspd < 0.0 )								// ��ɓ����Ă���Ƃ�
	{
		return 0 ;										// �n�ʂ��Ȃ����ɂ���	( �W�����v���ɏ��ɏ���Ă��܂����� )
	}

	/*
		���n
	*/
	if ( pp->yp >= FLIMIT )								// �n�ʂ�艺�ɂȂ�����
	{
		return (int)FLIMIT ;							// �n�ʂ̍��W�𑗂�
	}

	/*
		�v���C���[�̂����蔻��
		 > 3�����蔻����Ƃ�
	*/
	py = (int)pp->yp ;									// �v���C���[�̒��S�_
	pl = (int)pp->xp - 15.0 ;							// �v���C���[�̍���
	pr = (int)pp->xp + 15.0 ;							// �v���C���[�̉E��

	/*
		�u���b�N�̂����蔻��
	*/
	for ( i = 0 ; i < MAXBLK ; i++ )					// BLOCK ��S������
	{
		if ( blk[i].idno == ID_BLOCK )					// ���ʂ̃u���b�N�������Ƃ�
		{
			bl = (int)blk[i].xp - 16.0 ;				// BLOCK �̍���
			br = (int)blk[i].xp + 16.0 ;				// BLOCK �̉E��
			bu = (int)blk[i].yp ;						// BLOCK �̏㑤
			bd = (int)blk[i].yp + 20 ;					// BLOCK �̉���

			if ( (py >= bu) && (py <= bd) )				// �㉺�̂����蔻��
			{
				if ( (pl >= bl) && (pl <= br) )			// �v���C���[�̉E���ƃu���b�N�̂����蔻��
				{
					iRet = (int)blk[i].yp ;				// �������� BLOCK �̍��W��n��

					if ( blk[i].yspd < 0.0 )
					{
						edflg = (int)blk[i].xp ;
					}
				}
				if ( (pr >= bl) && (pr <= br) )			// �v���C���[�̍����ƃu���b�N�̂����蔻��
				{
					iRet = (int)blk[i].yp ;				// �������� BLOCK �̍��W��n��

					if ( blk[i].yspd < 0.0 )
					{
						edflg = (int)blk[i].xp ;
					}
				}
			}
		}
	}

	return iRet ;										// �Ԃ�l�ŕԂ�
}


/*______________________________________________________*/
/*				  ����`�F�b�N �����蔻��				*/
/*			  0 : 		���̑� : 		*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
int HeadCheck( void )
{
	int iRet = 0 ;
	int i ;
	int x , y ;											// ����̂����蔻��
	int bl , br , bu , bd ;								// BLOCK �̔���p

	if ( pp->yspd > 0.0 )								// �������̎�
	{
		return 0 ;										// 0 ��Ԃ� ( �������͓���ɂ͉����Ȃ� )
	}

	/*
		�v���C���[�̂����蔻��
		 > 3�����蔻����Ƃ�
	*/
	y = (int)pp->yp - 70 ;								// �v���C���[�̒��S�_
	x = (int)pp->xp ;									// �v���C���[�̍���

	/*
		�u���b�N�̂����蔻��
	*/
	for ( i = 0 ; i < MAXBLK ; i++ )					// BLOCK ��S������
	{
		if ( blk[i].idno == ID_BLOCK )					// ���ʂ̃u���b�N�������Ƃ�
		{
			bl = (int)blk[i].xp - 16.0 ;				// BLOCK �̍���
			br = (int)blk[i].xp + 16.0 ;				// BLOCK �̉E��
			bu = (int)blk[i].yp + 16 ;					// BLOCK �̏㑤
			bd = (int)blk[i].yp + 32 ;					// BLOCK �̉���

			if ( (y >= bu) && (y <= bd) )				// �㉺�̂����蔻��
			{
				if ( (x >= bl) && (x <= br) )			// �v���C���[�̉E���ƃu���b�N�̂����蔻��
				{
					iRet = -1 ;							// �������� BLOCK �̍��W��n��

					if ( blk[i].mode == 1 )				// �������� BLOCK �������ĂȂ���
					{
						blk[i].mode = 2 ;				// �������� BLOCK �̃��[�h��ς���
					}
					break ;								// ���x��������Ȃ��̂Ŕ�����
				}
			}
		}
	}

	return iRet ;										// �Ԃ�l�ŕԂ�

}

/*______________________________________________________*/
/*				 �`�F�b�N �����蔻��				*/
/*			  0 : 		���̑� : 		*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void BBcheck( void )
{
	int pl , pr , pu , pd ;
	int el , er , eu , ed ;

	pl = (int)obj[O_PLY].xp - 15 ;
	pr = (int)obj[O_PLY].xp + 15 ;
	pu = (int)obj[O_PLY].yp - 60 ;
	pd = (int)obj[O_PLY].yp ;

	el = (int)pp->xp - 15 ;
	er = (int)pp->xp + 15 ;
	eu = (int)pp->yp - 60 ;
	ed = (int)pp->yp ;

	if ( (pl < er) && (pr > el) && (pu < ed) && (pd > eu) )
	{
		pp->mode = 3 ;
		obj[O_PLY].mode = 9 ;
	}

}

/*______________________________________________________*/
/*				 �U���`�F�b�N �����蔻��				*/
/*			  0 : 		���̑� : 						*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void PAcheck( void )
{
	int i ;
	int px , py ;
	int el , er , eu , ed ;

	py = (int)pp->yp - 30 ;
	if ( pp->lrflg == 0 )
	{
		px = (int)pp->xp - 50 ;
	}
	else
	{
		px = (int)pp->xp + 50 ;
	}

	for ( i = 0 ; i < 10 ; i++ )
	{
		if ( obj[O_ENE+i].idno != 0 )
		{
			el = (int)obj[O_ENE+i].xp - 20 ;
			er = (int)obj[O_ENE+i].xp + 20 ;
			eu = (int)obj[O_ENE+i].yp - 40 ;
			ed = (int)obj[O_ENE+i].yp ;


			if ( (px > el) && (px < er) && (py > eu) && (py < ed) )
			{
				if ( obj[O_ENE+i].mode == 8 )
				{
					obj[O_ENE+i].mode = 9 ;
				}

				if ( obj[O_ENE+i].mode == 2 )
				{
					obj[O_ENE+i].mode = 12 ;
				}

			}
		}
	}

}


