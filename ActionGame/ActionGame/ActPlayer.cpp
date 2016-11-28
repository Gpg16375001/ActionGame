/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   PLAYER ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

#define PXSPD		8.0									// �v���C���[��s�ҁ[��

/*______________________________________________________*/
/*		0		  �v���C���[�̏����Z�b�g				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AInit( void )
{
	pp->dspf = 1 ;										// �O�F��\��	1�F�\��
	pp->xp = 400.0 ;									// �X�N���[���w���W
	pp->yp = FLIMIT ;									// �X�N���[���x���W
	pp->xsize = 80 ;									// �w�T�C�Y
	pp->ysize = 80 ;									// �x�T�C�Y
	pp->xboff = 0 ;										// �w�I�t�Z�b�g
	pp->yboff = 0 ;										// �x�I�t�Z�b�g
	pp->xmoff = 0 ;										// �w�}�X�N
	pp->ymoff = 80 ;									// �x�}�X�N
	pp->xoff = -40 ;									// �w�}�X�N
	pp->yoff = -76 ;									// �x�}�X�N
	pp->idx = 4 ;										// �摜�ԍ�

	pp->mode = 1 ;										// �A�N�V�����Ǘ��ԍ�

}

/*______________________________________________________*/
/*		1		  �v���C���[ ��~�����Ƃ�				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AStopW( BOOL lr )
{
		pp->lrflg = lr ;								// 0:�� �� 1:�E ������
		pp->mode = 2 ;									// �������̃��[�h��
		pp->pchg[0] = 0 ;								// �^�C�}�[�̏�����
		pp->pchg[1] = 0 ;								// �J�E���^�̏����� �A�j���[�V�����p
}

void AStop( void ) 
{
	ActWarp( ) ;

	if ( GetKeyState(VK_LEFT) < 0 )						// ���������ꂽ�Ƃ�
	{
		AStopW( 0 ) ;									// �A�j���[�V������~�֐���
	}

	if ( GetKeyState(VK_RIGHT) < 0 )					// �E�������ꂽ�Ƃ�
	{
		AStopW( 1 ) ;									// �A�j���[�V������~�֐���
	}

	if ( (GetKeyState(VK_SPACE) < 0) && (pp->pchg[4] != 1) )// SPACE KEY �������ꂽ��
	{
		pp->mode = 3 ;									// �W�����v�̃��[�h��
	}

	if ( GetKeyState(VK_SHIFT) < 0 )					// SPACE KEY �������ꂽ��
	{
		pp->mode = 5 ;									// �U���̃��[�h��
	}

}

/*______________________________________________________*/
/*		2		  �v���C���[ �����Ă�Ƃ�				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AWalk( void ) 
{
	pp->xspd = 0 ;										// Xspeed �̏�����
	pp->yspd = 0 ;										// Yspeed �̏�����

	ActWarp( ) ;
	
	if ( GetKeyState(VK_LEFT) < 0 )						// ���������ꂽ�Ƃ�
	{
		pp->lrflg = 0 ;									// 0:�� ������
		pp->xspd = -PXSPD ;								// ���ɐi��
	}

	if ( GetKeyState(VK_RIGHT) < 0 )					// �E�������ꂽ�Ƃ�
	{
		pp->lrflg = 1 ;									// 1:�E ������
		pp->xspd = PXSPD ;								// �E�ɐi��
	}

	if ( (GetKeyState(VK_SPACE) < 0) && (pp->pchg[4] != 1) )// SPACE KEY �������ꂽ�Ƃ�
	{
		pp->mode = 3 ;									// ���[�h���W�����v��
	}

	if ( GetKeyState(VK_SHIFT) < 0 )					// SPACE KEY �������ꂽ��
	{
		pp->mode = 5 ;									// �U���̃��[�h��
	}

	pp->xp += pp->xspd ;								// �������ɓ���
	if ( pp->xspd == 0.0 )								// X�X�s�[�h�� 0 �̎�
	{
		pp->mode = 1 ;									// ���[�h���~����
		pp->xboff = 0 ;									// �x�[�X���~���̊G�ɂ���
		pp->xmoff = 0 ;									// �}�X�N���~���̊G�ɂ���
	}

	if ( (FootCheck( ) == 0) && (pp->pchg[4] != 1) )	// �����̃`�F�b�N �����Ȃ�������
	{
		pp->mode = 11 ;									// �������̃��[�h��
	}

}

/*______________________________________________________*/
/*		3	 �v���C���[ �W�����v�̏����Z�b�g			*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AIJump( void )
{
	pp->yspd = -16.0 ;									// ������ɏ�����ǉ�
	pp->xboff = 640 + 80 ;								// �x�[�X���W�����v�̊G�ɂ���
	pp->xmoff = 640 + 80 ;								// �}�X�N���W�����v�̊G�ɂ���

	obj[O_BOO].idno = ID_BOO ;
	obj[O_BOO].xp = pp->xp ;
	obj[O_BOO].yp = pp->yp - 50 ;

	pp->mode = 4 ;										// ���[�h���W�����v����

}

/*______________________________________________________*/
/*		4		  �v���C���[ �W�����v��					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AJump( void )
{
	double yp ;

		ActWarp( ) ;

	pp->yspd += 0.7 ;									// �d��
	pp->yp += pp->yspd ;								// �c�����ɓ���
	if ( pp->yspd > 2.0 )								// �������x�� 2.0 �ȏ�̎�
	{
		pp->xboff = 720 ;								// �x�[�X�𗎉����̊G�ɂ���
		pp->xmoff = pp->xboff ;							// �}�X�N�𗎉����̊G�ɂ���
	}

	/*
		�W�����v���̉��ړ�
	*/
	pp->xspd = 0 ;										// Xspeed �̏�����
	if ( GetKeyState(VK_LEFT) < 0 )						// ���������ꂽ�Ƃ�
	{
		pp->xspd = -PXSPD ;								// ���ɐi��
	}
	if ( GetKeyState(VK_RIGHT) < 0 )					// �E�������ꂽ�Ƃ�
	{
		pp->xspd = PXSPD ;								// �E�ɐi��
	}
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
		pp->yp = yp ;									// Y���W�����̑����ŌŒ肷��
		pp->mode = 1 ;									// ���[�h���~����
		pp->yspd = 0 ;									// Yspeed ������������
		pp->xboff = 0 ;									// �x�[�X���~���̊G�ɂ���
		pp->xmoff = pp->xboff ;							// �}�X�N���~���̊G�ɂ���
	}

}

/*______________________________________________________*/
/*		5		 �v���C���[ �U���̏����Z�b�g			*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AIAttack( void )
{
	pp->yspd = -16.0 ;									// ������ɏ�����ǉ�
	pp->xsize = 96 ;
	pp->xboff = 960 ;									// �x�[�X���W�����v�̊G�ɂ���
	pp->xmoff = 960 ;									// �}�X�N���W�����v�̊G�ɂ���

	pp->mode = 6 ;										// ���[�h���U������
	pp->pchg[0] = 20 ;

}

/*______________________________________________________*/
/*		6			�v���C���[ �U����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AAttack( void )
{
	PAcheck( ) ;										// �U��

	pp->pchg[0]-- ;
	if ( pp->pchg[0] == 10 )
	{
		pp->xboff = 1054 ;								// �x�[�X���W�����v�̊G�ɂ���
		pp->xmoff = pp->xboff ;							// �}�X�N���W�����v�̊G�ɂ���
	}

	if ( pp->pchg[0] <= 0 )
	{
		pp->xsize = 80 ;
		pp->mode = 1 ;
	}

}

/*______________________________________________________*/
/*		7		  �v���C���[ �U�����ꂽ�Ƃ�				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AIDamege( void )
{

}

/*______________________________________________________*/
/*		8		  �v���C���[ �U�����ꂽ�Ƃ�				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ADamege( void )
{

}

/*______________________________________________________*/
/*		9	�v���C���[ ���񂾂Ƃ��̏����Z�b�g			*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AIOut( void )
{
	pp->yspd = -10.0 ;									// Yspeed ������������
	pp->xboff = 80 * 11 ;								// �x�[�X�𗎉����̊G�ɂ���
	pp->xmoff = 80 * 11 ;								// �}�X�N�𗎉����̊G�ɂ���

	pp->mode = 10 ;										// ���[�h���W�����v����

}

/*______________________________________________________*/
/*		10		  �v���C���[ ���񂾂Ƃ�					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AOut( void )
{
	pp->yspd += 1.0 ;
	pp->yp += pp->yspd ;
}

/*______________________________________________________*/
/*		11		  �@�v���C���[ ������					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void AIDown( void )
{
	pp->yspd = 0 ;										// Yspeed ������������
	pp->xboff = 720 ;									// �x�[�X�𗎉����̊G�ɂ���
	pp->xmoff = 720 ;									// �}�X�N�𗎉����̊G�ɂ���

	pp->mode = 4 ;										// ���[�h���W�����v����

}


TBLJP ActPTbl[ ] =
{
	AInit ,												// 0  :	�����Z�b�g
	AStop ,												// 1  : ��~��
	AWalk ,												// 2  : ������
	AIJump ,											// 3  : �W�����v�����Z�b�g
	AJump ,												// 4  : �W�����v��
	AIAttack ,											// 5  : �U���̏����Z�b�g
	AAttack ,											// 6  : �U����
	AIDamege ,											// 7  : �_���[�W�����Z�b�g
	ADamege ,											// 8  : �_���[�W�󂯂�
	AIOut ,												// 9  : ���S�����Z�b�g
	AOut ,												// 10 : ���S
	AIDown ,											// 11 : ���������Z�b�g
} ;

/*______________________________________________________*/
/*				  �v���C���[�̃A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActPlayer( void )
{
	ActPTbl[pp->mode]( ) ;								// �v���C���[�̃A�N�V�����̃e�[�u���W�����v

	FootHitCheck( ) ;
	if ( pp->lrflg == 0 )								// ���������� (����) ����Ƃ�
	{
		pp->idx = 4 ;									// �������̉摜�ɕς���
	}
	else												// �E�������� (����) ����Ƃ�
	{
		pp->idx = 5 ;									// �������̉摜�ɕς���
	}

	/*
		�����Ă���Ƃ�
	*/
	pp->pchg[0]-- ;										// �^�C�}�[���J�E���g�_�E��
	if ( pp->pchg[0] <= 0 )								// �^�C�}�[�̃J�E���g�� 0�ȉ��ɂȂ�����
	{
		pp->pchg[0] = 2 ;								// �A�j���[�V�����̃^�C�}�[�Z�b�g
		pp->pchg[1]++ ;									// ���̃C���X�g�Ɉڂ�
		if ( pp->pchg[1] >= 4 )							// �A�j���[�V�������I�������
		{
			pp->pchg[1] = 0 ;							// �ŏ��̊G�ɖ߂�
		}

		if ( ( GetKeyState(VK_LEFT) < 0 ) && (pp->mode != 4) || ( GetKeyState(VK_RIGHT) < 0 ) && (pp->mode != 4) )
		{
			pp->xboff = (pp->pchg[1] * 80) + 320 ;		// �x�[�X�̃C���X�g�̈ʒu������
			pp->xmoff = (pp->pchg[1] * 80) + 320 ;		// �}�X�N�̃C���X�g�̈ʒu������
		}
		else if ( pp->mode != 4 )
		{
			pp->xboff = (pp->pchg[1] * 80) ;			// �x�[�X�̃C���X�g�̈ʒu������
			pp->xmoff = (pp->pchg[1] * 80) ;			// �}�X�N�̃C���X�g�̈ʒu������
		}
	}


}


