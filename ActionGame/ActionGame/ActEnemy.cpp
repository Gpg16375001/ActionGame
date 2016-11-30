/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   ENEMY ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

#define EXSPD		6.0									// �G�l�~�[�̃X�s�[�h

/*______________________________________________________*/
/*		0		   �G�l�~�[�̏����Z�b�g					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeInit( void )
{
	pp->dspf = 1 ;										// �O�F��\��	1�F�\��
	pp->xspd = 0 ;										// Xspeed �̏�����
	pp->yspd = 0 ;										// Yspeed �̏�����
	pp->xsize = 80 ;									// �w�T�C�Y
	pp->ysize = 80 ;									// �x�T�C�Y
	pp->xboff = 0 ;										// �w�I�t�Z�b�g
	pp->yboff = 0 ;										// �x�I�t�Z�b�g
	pp->xmoff = 0 ;										// �w�}�X�N
	pp->ymoff = 80 ;									// �x�}�X�N
	pp->xoff = -40 ;									// �w���S�_
	pp->yoff = -76 ;									// �x���S�_
	pp->idx = 6 ;										// �摜�ԍ�
	pp->timer = 0 ;

	pp->mode = 1 ;										// �A�N�V�����Ǘ��ԍ�

}

/*______________________________________________________*/
/*		1		   �G�l�~�[ ��~�����Ƃ�				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeStopW( BOOL lr )
{
		pp->lrflg = lr ;								// 0:�� �� 1:�E ������
		pp->mode = 2 ;									// �������̃��[�h��
		pp->pchg[0] = 0 ;								// �^�C�}�[�̏�����
		pp->pchg[1] = 0 ;								// �J�E���^�̏����� �A�j���[�V�����p
}

void AeStop( void ) 
{
	ActWarp( ) ;

	/*
		�G�l�~�[�v�l�v���O����
	*/
	if ( ((rand( ) % 80) == 1) || (pp->timer != 0) )
	{
		pp->timer++ ;
		if ( pp->timer > 80 )
		{
			pp->timer = 0 ;
		}
	}
	else if ( pp->xp > obj[O_PLY].xp )
	{
		AeStopW( 0 ) ;									// �A�j���[�V������~�֐���
		pp->xspd = -EXSPD ;								// ��
	}
	else
	{
		AeStopW( 1 ) ;									// �A�j���[�V������~�֐���
		pp->xspd = EXSPD ;								// �E
	}

	/*
		�����̃`�F�b�N
	*/
	if ( (FootCheck( ) == 0) && (pp->pchg[4] != 1) )	// �����̃`�F�b�N �����Ȃ�������
	{
		pp->mode = 11 ;									// �������̃��[�h��
	}
	else
	{
		if ( edflg != -1 )								// 
		{
			pp->mode = 7 ;

			if ( bp->xp < edflg )
			{
				pp->xspd = -4.0 ;
			}
			else
			{
				pp->xspd = 4.0 ;
			}
		}
	}

}

/*______________________________________________________*/
/*		2		   �G�l�~�[ �����Ă�Ƃ�				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeWalk( void ) 
{
//	BBcheck( ) ;
	ActWarp( ) ;

	/*
		�G�l�~�[�v�l�v���O����
	*/
	if ( (rand( ) % 80) == 1 )
	{
		pp->mode = 1 ;
	}
	if ( ((rand( ) % 30) == 1) && (pp->xp > 320) && (pp->xp < 384) && (pp->lrflg == 0)
		|| ((rand( ) % 30) == 1) && (pp->xp > 416) && (pp->xp < 480) && (pp->lrflg == 1) )
	{
		pp->mode = 3 ;
	}

	// ���ړ�
	pp->xp += pp->xspd ;								// �������ɓ���

	if ( (FootCheck( ) == 0) && (pp->pchg[4] != 1) )	// �����̃`�F�b�N �����Ȃ�������
	{
		pp->mode = 11 ;									// �������̃��[�h��
	}
	else
	{
		if ( edflg != -1 )
		{
			pp->mode = 7 ;

			if ( bp->xp < edflg )
			{
				pp->xspd = -4.0 ;
			}
			else
			{
				pp->xspd = 4.0 ;
			}
		}
	}

	/*
		�����Ă���Ƃ�
	*/
	pp->pchg[0]-- ;										// �^�C�}�[���J�E���g�_�E��
	if ( (pp->pchg[0] <= 0) )							// �^�C�}�[�̃J�E���g�� 0�ȉ��ɂȂ�����
	{
		pp->pchg[0] = 2 ;								// �A�j���[�V�����̃^�C�}�[�Z�b�g
		pp->pchg[1]++ ;									// ���̃C���X�g�Ɉڂ�
		if ( pp->pchg[1] >= 4 )							// �A�j���[�V�������I�������
		{
			pp->pchg[1] = 0 ;							// �ŏ��̊G�ɖ߂�
		}
		pp->xboff = (pp->pchg[1] * 80) + 320 ;			// �x�[�X�̃C���X�g�̈ʒu������
		pp->xmoff = (pp->pchg[1] * 80) + 320 ;			// �}�X�N�̃C���X�g�̈ʒu������
	}

}

/*______________________________________________________*/
/*		3	   �G�l�~�[ �W�����v�̏����Z�b�g			*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeIJump( void )
{
	pp->yspd = -15.0 ;									// ������ɏ�����ǉ�
	pp->xboff = 640 ;									// �x�[�X���W�����v�̊G�ɂ���
	pp->xmoff = 640 ;									// �}�X�N���W�����v�̊G�ɂ���

	if ( pp->mode != 12 )
	{
		pp->mode = 4 ;									// ���[�h���W�����v����
	}
	else
	{
		pp->mode = 13 ;
	}

}

/*______________________________________________________*/
/*		4		   �G�l�~�[ �W�����v��					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeJump( void )
{
	double yp ;

	if ( pp->mode != 13 )
	{
		pp->yspd += 0.6 ;								// �d��

		if ( pp->yspd > 2.0 )							// �������x�� 2.0 �ȏ�̎�
		{
			pp->xboff = 720 ;							// �x�[�X�𗎉����̊G�ɂ���
			pp->xmoff = pp->xboff ;						// �}�X�N�𗎉����̊G�ɂ���
		}
	}
	else
	{
		pp->yspd += 0.8 ;								// �d��

		if ( obj[O_PLY].lrflg == 0 )
		{
			pp->xspd = -4.0 ;
		}
		else
		{
			pp->xspd = 4.0 ;
		}
		pp->xboff = 800 ;								// �x�[�X�����ꒆ�̊G�ɂ���
		pp->xmoff = pp->xboff ;							// �}�X�N�����ꒆ�̊G�ɂ���

	}
	pp->yp += pp->yspd ;								// �c�����ɓ���
	/*
		�W�����v���̉��ړ�
	*/
	pp->xp += pp->xspd ;								// �������ɓ���

	/*
		����̂����蔻��
		��Ƀu���b�N
	*/
	if ( HeadCheck( ) != 0 )							// �V��ɓ����������ǂ���
	{
		pp->yspd *= -0.8 ;								// �˂����Ƃ����
	}

	/*
		�����̂����蔻��
		�u���b�N��n�ʂȂ�
	*/
	yp = FootCheck( ) ;									// �������`�F�b�N����
	if ( yp != 0 )										// �����ɉ�����������
	{
		pp->yp = (double)yp ;							// Y���W�����̑����ŌŒ肷��
		pp->mode = 1 ;									// ���[�h���~����
		pp->yspd = 0 ;									// Yspeed ������������
		pp->xboff = 0 ;									// �x�[�X���~���̊G�ɂ���
		pp->xmoff = pp->xboff ;							// �}�X�N���~���̊G�ɂ���
	}

}

/*______________________________________________________*/
/*		5		   �G�l�~�[ �U���̏����Z�b�g			*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeIAttack( void )
{

}

/*______________________________________________________*/
/*		6			�G�l�~�[ �U����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeAttack( void )
{

}

/*______________________________________________________*/
/*		7		  �G�l�~�[ �U�����ꂽ�Ƃ�				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeIDamege( void )
{
	pp->yspd = -5.0 ;									// ������ɏ�����ǉ�
	pp->xboff = 800 ;									// �x�[�X������̊G�ɂ���
	pp->xmoff = pp->xboff ;								// �}�X�N������̊G�ɂ���
	pp->pchg[0] = 90 ;

	pp->mode = 8 ;										// ���[�h���W�����v����
	
}

/*______________________________________________________*/
/*		8		  �G�l�~�[ �U�����ꂽ�Ƃ�				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeDamege( void )
{
	double yp ;

	pp->xp += pp->xspd ;

	pp->yspd += 0.5 ;
	pp->yp += pp->yspd ;

	/*
		�����̂����蔻��
		�u���b�N��n�ʂȂ�
	*/
	yp = FootCheck( ) ;									// �������`�F�b�N����
	if ( yp != 0 )										// �����ɉ�����������
	{
		pp->yp = (double)yp ;							// Y���W�����̑����ŌŒ肷��
		pp->xspd = 0 ;									// Xspeed ������������
		pp->yspd = 0 ;									// Yspeed ������������

		pp->pchg[0]-- ;
		pp->dspf = 0 ;
		if ( pp->pchg[0] > 15 )
		{
			if ( (pp->pchg[0] & 0x07) < 4 )
			{
				pp->dspf = 1 ;
			}
		}
		else
		{
			if ( pp->pchg[0] < 0 )
			{
				pp->mode = 1 ;							// ���[�h���~����
				pp->dspf = 1 ;
				pp->xboff = 0 ;							// �x�[�X���~���̊G�ɂ���
				pp->xmoff = pp->xboff ;					// �}�X�N���~���̊G�ɂ���
			}
			else
			{
				pp->dspf = pp->pchg[0] & 1 ;
			}
		}
	}
}

/*______________________________________________________*/
/*		9	 �G�l�~�[ ���񂾂Ƃ��̏����Z�b�g			*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeIOut( void )
{
	int no ;

	pp->dspf = 1 ;
	pp->yspd = -10.0 ;									// Yspeed ������������
	pp->xboff = 80 * 11 ;								// �x�[�X�𗎉����̊G�ɂ���
	pp->xmoff = 80 * 11 ;								// �}�X�N�𗎉����̊G�ɂ���

	no = ObjSearch( O_BOMB , MAXBOM ) ;
	if ( no != -1 )										// �󂢂Ă�����
	{
		obj[no].idno = ID_BOMB ;
		obj[no].mode = 0 ;
		obj[no].xp = pp->xp ;
		obj[no].yp = pp->yp - 40 ;
	}
	pp->mode = 10 ;										// ���[�h���W�����v����

}

/*______________________________________________________*/
/*		10		  �G�l�~�[ ���񂾂Ƃ�					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeOut( void )
{
	pp->yspd += 1.0 ;
	pp->yp += pp->yspd ;

	if ( pp->yp >= 700 )
	{
		pp->idno = 0 ;
	}
}

/*______________________________________________________*/
/*		11		  �@ �G�l�~�[ ������					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AeIDown( void )
{
	pp->yspd = 0 ;										// Yspeed ������������
	pp->xboff = 720 ;									// �x�[�X�𗎉����̊G�ɂ���
	pp->xmoff = 720 ;									// �}�X�N�𗎉����̊G�ɂ���

	pp->mode = 4 ;										// ���[�h���W�����v����

}



TBLJP ActETbl[ ] =
{
	AeInit ,											// 0  :	�����Z�b�g
	AeStop ,											// 1  : ��~��
	AeWalk ,											// 2  : ������
	AeIJump ,											// 3  : �W�����v�����Z�b�g
	AeJump ,											// 4  : �W�����v��
	AeIAttack ,											// 5  : �U���̏����Z�b�g
	AeAttack ,											// 6  : �U����
	AeIDamege ,											// 7  : �_���[�W�����Z�b�g
	AeDamege ,											// 8  : �_���[�W�󂯂�
	AeIOut ,											// 9  : ���S�����Z�b�g
	AeOut ,												// 10 : ���S
	AeIDown ,											// 11 : ���������Z�b�g
	AeIJump ,											// 12 : �ʏ펞���� �����Z�b�g
	AeJump ,											// 13 : �ʏ펞����
} ;

/*______________________________________________________*/
/*				    �G�l�~�[�̃A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActEnemy( void )
{
	ActETbl[pp->mode]( ) ;								// �G�l�~�[�̃A�N�V�����̃e�[�u���W�����v

	if ( pp->lrflg == 0 )								// ���������� (����) ����Ƃ�
	{
		pp->idx = 6 ;									// �������̉摜�ɕς���
	}
	else												// �E�������� (����) ����Ƃ�
	{
		pp->idx = 7 ;									// �������̉摜�ɕς���
	}

}

/*______________________________________________________*/
/*						�G�l�~�[�̃Z�b�g				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void EnemySet( void )
{
	int y , x ;
	int no ;

	for ( y = 0 ; y < 18 ; y++ )
	{
		for ( x = 0 ; x < 25 ; x++ )
		{
			no = ObjSearch( O_ENE , MAXENE ) ;
			if ( map[y][x] == 8 )						// ���Ă� MAP �̍��W�ɉ��������Ă���Ƃ�
			{
				obj[no].idno = ID_ENE ;					// ���̏ꏊ�ɃG�l�~�[������
				obj[no].mode = 0 ;						// MODE �������Z�b�g�ɂ���
					
				obj[no].xp = x * 32 ;					// X ���W�����킹��
				obj[no].yp = y * 32 + 32 ;				// Y ���W�����킹��
			}
		}
	}

}


