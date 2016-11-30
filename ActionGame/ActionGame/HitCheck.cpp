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
	int no ;
	int pl , py , pr ;									// PLAYER �̂����蔻��
	int bl , br , bu , bd ;								// BLOCK �̂����蔻��

	edflg = -1 ;


	/*
		���n
	*/
	if ( (pp->yspd > 0.0) && (pp->yp >= FLIMIT) )		// ��ɓ����Ă���Ƃ�
	{
		no = ObjSearch( O_BOO , MAXBOO ) ;
		if ( no != -1 )									// �󂢂Ă�����
		{
			obj[no].idno = ID_STEP ;
			obj[no].mode = 0 ;
			obj[no].xp = pp->xp ;
			obj[no].yp = pp->yp - 82 ;
		}
	}

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
	pl = (int)(pp->xp - 15.0) ;							// �v���C���[�̍���
	pr = (int)(pp->xp + 15.0) ;							// �v���C���[�̉E��

	/*
		�u���b�N�̂����蔻��
	*/
	for ( i = 0 ; i < MAXBLK ; i++ )					// BLOCK ��S������
	{
		if ( blk[i].idno == ID_BLOCK )					// ���ʂ̃u���b�N�������Ƃ�
		{
			bl = (int)(blk[i].xp - 16.0) ;				// BLOCK �̍���
			br = (int)(blk[i].xp + 16.0) ;				// BLOCK �̉E��
			bu = (int)blk[i].yp ;						// BLOCK �̏㑤
			bd = (int)(blk[i].yp + 20) ;				// BLOCK �̉���

			if ( (py >= bu) && (py <= bd) )				// �㉺�̂����蔻��
			{
				if ( (pl >= bl) && (pl <= br) )			// �v���C���[�̉E���ƃu���b�N�̂����蔻��
				{
					iRet = (int)blk[i].yp ;				// �������� BLOCK �̍��W��n��

					if ( blk[i].yspd < 0.0 )
					{
						edflg = (int)blk[i].xp ;
					}

					/*
						���n ���A�N�V����
					*/
					if ( pp->yspd > 0.0 )				// ��ɓ����Ă���Ƃ�
					{
						no = ObjSearch( O_BOO , MAXBOO ) ;
						if ( no != -1 )					// �󂢂Ă�����
						{
							obj[no].idno = ID_STEP ;
							obj[no].mode = 0 ;
							obj[no].xp = pp->xp ;
							obj[no].yp = pp->yp - 82 ;
						}
					}
				}
				if ( (pr >= bl) && (pr <= br) )			// �v���C���[�̍����ƃu���b�N�̂����蔻��
				{
					iRet = (int)blk[i].yp ;				// �������� BLOCK �̍��W��n��

					if ( blk[i].yspd < 0.0 )
					{
						edflg = (int)blk[i].xp ;
					}

					/*
						���n
					*/
					if ( pp->yspd > 0.0 )				// ��ɓ����Ă���Ƃ�
					{
						no = ObjSearch( O_BOO , MAXBOO ) ;
						if ( no != -1 )					// �󂢂Ă�����
						{
							obj[no].idno = ID_STEP ;
							obj[no].mode = 0 ;
							obj[no].xp = pp->xp ;
							obj[no].yp = pp->yp - 82 ;
						}
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
	int pl , py , pr ;									// ����̂����蔻��
	int bl , br , bu , bd ;								// BLOCK �̔���p

	if ( pp->yspd > 0.0 )								// �������̎�
	{
		return 0 ;										// 0 ��Ԃ� ( �������͓���ɂ͉����Ȃ� )
	}

	/*
		�v���C���[�̂����蔻��
		 > 3�����蔻����Ƃ�
	*/
	py = (int)(pp->yp - 70) ;							// �v���C���[�̒��S�_	��
	pl = (int)(pp->xp - 15.0) ;							// �v���C���[�̍�		��
	pr = (int)(pp->xp + 15.0) ;							// �v���C���[�̉E		��

	/*
		�u���b�N�̂����蔻��
	*/
	for ( i = 0 ; i < MAXBLK ; i++ )					// BLOCK ��S������
	{
		if ( blk[i].idno == ID_BLOCK )					// ���ʂ̃u���b�N�������Ƃ�
		{
			bl = (int)(blk[i].xp - 16.0) ;				// BLOCK �̍���
			br = (int)(blk[i].xp + 16.0) ;				// BLOCK �̉E��
			bu = (int)(blk[i].yp + 16) ;				// BLOCK �̏㑤
			bd = (int)(blk[i].yp + 32) ;				// BLOCK �̉���

			if ( (py >= bu) && (py <= bd) )				// �㉺�̂����蔻��
			{
				if ( (pl >= bl) && (pl <= br) )			// �v���C���[�̉E���ƃu���b�N�̂����蔻��
				{
					iRet = -1 ;							// �������� BLOCK �̍��W��n��

					if ( blk[i].mode == 1 )				// �������� BLOCK �������ĂȂ���
					{
						blk[i].mode = 2 ;				// �������� BLOCK �̃��[�h��ς���
					}
					break ;								// ���x��������Ȃ��̂Ŕ�����
				}
				if ( (pr >= bl) && (pr <= br) )			// �v���C���[�̍����ƃu���b�N�̂����蔻��
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
/*				  �̃`�F�b�N �����蔻��					*/
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
/*				  �̂ƃu���b�N�̂����蔻��				*/
/*			  0 : 		���̑� : 		*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
int Body_Block( void )
{
	int iRet = 0 ;										// �Ԃ�l
	int y ;
	int i ;												// blk[] �̃J�E���g�p
	int no ;
	int bl , br , bu , bd ;								// BLOCK �̂����蔻��
	int pl , py , pr ;									// PLAYER �̂����蔻��
	int plc[2][4][3] = {								// PLAYER �̂����蔻��
		// 0 : �������̎�
		{
//			{ left , right , ypos },
			{ 16 , 28 , 60 },
			{ 19 , 32 , 43 },
			{ 23 , 21 , 26 },
			{  4 , 20 , 12 },
		} ,

		// 1 : �E�����̎�
		{
//			{ left , right , ypos },
			{ 28 , 16 , 60 },
			{ 32 , 19 , 43 },
			{ 21 , 23 , 26 },
			{ 20 ,  4 , 12 },
		} ,
	} ;

	for ( y = 0 ; y < 4 ; y++ )
	{
		/*
			�v���C���[�̂����蔻��
			 > 3x4�����蔻����Ƃ�
		*/
		pl = (int)(pp->xp - plc[pp->lrflg][y][1]) ;
		pr = (int)(pp->xp + plc[pp->lrflg][y][2]) ;
		py = (int)(pp->yp - plc[pp->lrflg][y][3]) ;			// �v���C���[�̒��S�_

		/*
			�u���b�N�̂����蔻��
		*/
		for ( i = 0 ; i < MAXBLK ; i++ )					// BLOCK ��S������
		{
			if ( blk[i].idno == ID_BLOCK )					// ���ʂ̃u���b�N�������Ƃ�
			{
			
				bl = (int)(blk[i].xp - 16) ;				// BLOCK �̍���
				br = (int)(blk[i].xp + 16 );				// BLOCK �̉E��
				bu = (int)blk[i].yp ;						// BLOCK �̏㑤
				bd = (int)(blk[i].yp + 32) ;				// BLOCK �̉���

				if ( (py >= bu) && (py <= bd) )				// �㉺�̂����蔻��
				{
					if ( (pl >= bl) && (pl <= br) )			// �v���C���[�̉E�ƃu���b�N�̂����蔻��
					{
						iRet = (int)blk[i].xp ;				// �������� BLOCK �̍��W��n��
					}
					if ( (pr >= bl) && (pr <= br) )			// �v���C���[�̍��ƃu���b�N�̂����蔻��
					{
						iRet = (int)blk[i].xp ;				// �������� BLOCK �̍��W��n��
					}
				}
			}
		}
	}

	return iRet ;											// �Ԃ�l�ŕԂ�
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
		px = (int)pp->xp ;
	}
	else
	{
		px = (int)pp->xp ;
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


/*______________________________________________________*/
/*				  �����`�F�b�N �����蔻��				*/
/*			  0 : ���Ȃ�		���̑� : ���̍��W		*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void FootHitCheck( void )
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
		�y�ǂ̒��̂����蔻��
	*/
	for ( i = 0 ; i < 4 ; i++ )
	{
		if ( (py >= Holeup[i][0]) && (py <= Holeup[i][1]) && (pp->mode != 4) )	// �㉺�̂����蔻��
		{
			if ( (i == 0) || (i == 1) )
			{
				// �����ɓ���Ƃ�
				if ( (pl >= Holeup[0][2]) && (pl <= Holeup[0][3])
					|| (pr >= Holeup[1][2]) && (pr <= Holeup[1][3]) ) // �v���C���[  �̉E���ƃu���b�N�̂����蔻��
				{
					pp->yp = 86 ;						// �������� BLOCK �̍��W��n��
					pp->pchg[4] = 1 ;					// �y�ǂ̒����ǂ����̃t���O			
				}
				else
				{
					pp->pchg[4] = 0 ;					// �y�ǂ̒����ǂ����̃t���O			
				}
			}

			if ( (i == 2) || (i == 3) )
			{
				// �����ɓ���Ƃ�
				if ( (pl >= Holeup[2][2]) && (pl <= Holeup[2][3])
					|| (pr >= Holeup[3][2]) && (pr <= Holeup[3][3]) )	// �v���C���[�̉E���ƃu���b�N�̂����蔻��
				{
					pp->yp = 566 ;						// �������� BLOCK �̍��W��n��
					pp->pchg[4] = 1 ;					// �y�ǂ̒����ǂ����̃t���O			
				}
				else
				{
					pp->pchg[4] = 0 ;					// �y�ǂ̒����ǂ����̃t���O			
				}
			}
			pp->yspd = 0 ;
		}
	}
	
	/*
		�y�ǂ̂����蔻��
		�㉺���E
	*/
	if ( (pl <= 96) && (py >= (96 - 100)) && (py <= 42) )
	{
		pp->yp = 96 - 100 ;
		pp->mode = 2 ;
	}

	if ( (pr >= 704) && (py >= (96 - 100)) && (py <= 42) )
	{
		pp->yp = 96 - 100 ;
		pp->mode = 2 ;
	}

	if ( (pl <= 128 - 8) && ((py - 70) >= (576 - 120)) && ((py - 70) <= (576 - 90)) )
	{
		pp->xspd = 0 ;
		pp->xp = 128 ;
	}

	if ( (pr >= 672 + 8) && ((py - 70) >= (576 - 120)) && ((py - 70) <= (576 - 90)) )
	{
		pp->xspd = 0 ;
		pp->xp = 672 ;
	}

}


