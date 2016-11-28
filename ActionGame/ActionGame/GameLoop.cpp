/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   �Q�[�����[�v													*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*						�������Ȃ��֐�					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void GameNull( void )
{
}

/*______________________________________________________*/
/*						�Q�[���J�n						*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void GameAInit( void )
{

	gmode = GM_I_TITLE ;								// �^�C�g���̏����Z�b�g�ֈړ�����

	/* >> �f�o�b�O << */
	gmode = GM_I_GAME ;

}

/*______________________________________________________*/
/*					�^�C�g���̏����Z�b�g				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void GameITitle( void )
{
	obj[O_TITLE].idno = ID_TITLE ;						// �^�C�g�� (�w�i) �̌Ăяo��
	obj[O_TITLE].mode = 0 ;								// �^�C�g�� (�w�i) �̏����Z�b�g�̌Ăяo��

	obj[O_START].idno = ID_START ;						// �X�^�[�g (����) �̌Ăяo��
	obj[O_START].mode = 0 ;								// �X�^�[�g (����) �̏����Z�b�g�̌Ăяo�� 

	gmode = GM_M_TITLE ;								// �^�C�g���Ɉړ�
}

/*______________________________________________________*/
/*						�^�C�g����						*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void GameMTitle( void )
{
	if ( obj[O_START].idno == 0 )						// �X�^�[�g���������Ƃ� ( SPACE KEY ���������Ə����� )
	{
		gmode = GM_E_TITLE ;							// �^�C�g���I���ֈړ�
	}
}

/*______________________________________________________*/
/*						�^�C�g���I��					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void GameETitle( void )
{
	obj[O_TITLE].idno = 0;								// �^�C�g�� (�w�i) ������
	obj[O_TITLE].mode = 0 ;								// �^�C�g�� (�w�i) �̏����Z�b�g�̌Ăяo��

	obj[O_START].idno = 0 ;								// �X�^�[�g (����) ������
	obj[O_START].mode = 0 ;								// �X�^�[�g (����) �̏����Z�b�g�̌Ăяo��

	gmode = GM_I_GAME ;									// �Q�[���J�n����
}

/*______________________________________________________*/
/*					  �Q�[�������Z�b�g					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void GameIGame( void )
{
	obj[O_BG].idno = ID_BG ;							// �w�i�̌Ăяo��
	obj[O_BG].mode = 0 ;								// �w�i�̏����Z�b�g�̌Ăяo��

	obj[O_PLY].idno = ID_PLY ;							// �v���C���[�̌Ăяo��
	obj[O_PLY].mode = 0 ;								// �v���C���[�̏����Z�b�g�̌Ăяo��

	obj[O_HOLE+0].idno = ID_HOLE ;							// �w�i�̌Ăяo��
	obj[O_HOLE+0].mode = 0 ;								// �w�i�̏����Z�b�g�̌Ăяo��
	obj[O_HOLE+0].cnt = 0 ;								// �w�i�̏����Z�b�g�̌Ăяo��

	obj[O_HOLE+1].idno = ID_HOLE ;							// �w�i�̌Ăяo��
	obj[O_HOLE+1].mode = 0 ;								// �w�i�̏����Z�b�g�̌Ăяo��
	obj[O_HOLE+1].cnt = 1 ;								// �w�i�̏����Z�b�g�̌Ăяo��

	obj[O_HOLE+2].idno = ID_HOLE ;							// �w�i�̌Ăяo��
	obj[O_HOLE+2].mode = 0 ;								// �w�i�̏����Z�b�g�̌Ăяo��
	obj[O_HOLE+2].cnt = 2;								// �w�i�̏����Z�b�g�̌Ăяo��

	obj[O_HOLE+3].idno = ID_HOLE ;							// �w�i�̌Ăяo��
	obj[O_HOLE+3].mode = 0 ;								// �w�i�̏����Z�b�g�̌Ăяo��
	obj[O_HOLE+3].cnt = 3 ;								// �w�i�̏����Z�b�g�̌Ăяo��

	EnemySet( ) ;
	BlockSet( ) ;										// �u���b�N�̔z�u

	gmode = GM_M_GAME ;									// �Q�[���J�n����
}

/*______________________________________________________*/
/*						  �Q�[����						*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void GameMGame( void )
{

}

/*______________________________________________________*/
/*						�Q�[���I����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void GameEGame( void )
{
}

/*______________________________________________________*/
/*					 �Q�[���W�����v�p					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
TBLJP GameJpTbl[ ] = {
	GameAInit ,											//  00 : �S���̏�����
	GameITitle ,										//  01 : �^�C�g���̏����Z�b�g
	GameMTitle ,										//  02 : �^�C�g���̍Œ�
	GameETitle ,										//  03 : �^�C�g���I����
	GameNull ,											//  04 : 
	GameIGame ,											//  05 : �Q�[���̏����Z�b�g
	GameMGame ,											//  06 : �Q�[���̍Œ�
	GameEGame ,											//  07 : �Q�[���I����
	GameNull ,											//  08 : 
	GameNull ,											//  09 : 
	GameNull ,											//  10 : 
	GameNull ,											//  11 : 
	GameNull ,											//  12 : 
	GameNull ,											//  13 : 
	GameNull ,											//  14 : 
	GameNull ,											//  15 : 
} ;

/*______________________________________________________*/
/*						�Q�[�����[�v					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void GameLoop( void )
{
	GameJpTbl[ gmode ]( ) ;								// ���ꂼ��̊֐��փW�����v����
}



