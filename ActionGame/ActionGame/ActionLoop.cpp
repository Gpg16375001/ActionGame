/*______________________________________________________________________________________________________________*/
/*																												*/
/*												�A�N�V�������[�v												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"


/*______________________________________________________*/
/*						�������Ȃ��֐�					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActNull( void ){		}

TBLJP ActJpTbl[ ] = {
	ActNull ,											//  00 : 
	ActTitle ,											//  01 : �^�C�g���̃A�N�V����
	ActStart ,											//  02 : �X�^�[�g�̃A�N�V����
	ActNull ,											//  03 : 
	ActBg ,												//  04 : �w�i�̃A�N�V����
	ActNull ,											//  05 : 
	ActPlayer ,											//  06 : �v���C���[�̃A�N�V����
	ActNull ,											//  07 : 
	ActEnemy ,											//  08 : �G�l�~�[�̃A�N�V����
	ActNull ,											//  09 : 
	ActHole ,											//  10 : �y�ǂ̃A�N�V����
	ActNull ,											//  11 : 
	ActNull ,											//  12 : 
	ActNull ,											//  13 : 
	ActNull ,											//  14 : 
	ActNull ,											//  15 : 
} ;

/*______________________________________________________*/
/*					  �A�N�V�������[�v					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActionLoop( void )
{
	int i ;

	for ( i = 0 ; i < MAXOBJ ; i++ )					// �I�u�W�F�N�g��S������
	{
		if ( obj[i].idno != 0 )							// obj[] �ɉ��������Ă���Ƃ�
		{
			pp = &obj[i] ;								// �|�C���^�ɓ����
			ActJpTbl[ pp->idno ]( ) ;					// �e�[�u���W�����v����
		}
	}

	for ( i = 0 ; i < MAXBLK ; i++ )					// �S���̃u���b�N������
	{
		if ( blk[i].idno != 0 )							// blk[] �ɉ��������Ă���Ƃ�
		{
			bp = &blk[i] ;								// �|�C���^�ɓ����
			ActBlock( ) ;								// �u���b�N�A�N�V�����̊֐��֍s��
		}
	}
}



