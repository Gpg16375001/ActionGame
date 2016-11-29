/*______________________________________________________________________________________________________________*/
/*																												*/
/*										  �f�t�@�C�� �v���g�^�C�v�錾											*/
/*______________________________________________________________________________________________________________*/

/* ____ DEFINE ____ */
#define	MAXOBJ			300		// �X�v���C�g�̐�
#define WINDOW_W		800		// �E�B���h�E�̕�
#define WINDOW_H		640		// �E�B���h�E�̍���
#define FLIMIT			576.0	// �n�ʂ̈ʒu

#define MAXBLK			450		// �u���b�N�̍ő吔

#define GM_I_ALL		0		// �S���̏����Z�b�g
#define GM_I_TITLE		1		// �^�C�g���̏����Z�b�g
#define GM_M_TITLE		2		// �^�C�g����
#define GM_E_TITLE		3		// �^�C�g���I��
#define GM_I_GAME		5		// �Q�[�������Z�b�g
#define GM_M_GAME		6		// �Q�[����

#define O_TITLE			0		// �^�C�g���̔w�i
#define O_START			1		// �X�^�[�g�̕���
#define O_BG			0		// �Q�[���w�i
#define O_PLY			10		// �v���C���[
#define O_ENE			20		// �G�l�~�[
#define O_HOLE			80		// �y��
#define O_BOO			90		// ��
#define O_SNOW			180		// ��
#define O_BOMB			280		// ����

#define MAXBOO			10		// boo
#define MAXBOM			10		// ����
#define MAXSNOW			100		// ��
#define MAXENE			5		// �G�l�~�[�̍ő吔

#define ID_BLOCK		1		// �u���b�N��ID
#define ID_TITLE		1		// �^�C�g����ID
#define ID_START		2		// �X�^�[�g������ID
#define ID_BG			4		// �Q�[���w�i��ID
#define ID_PLY			6		// �v���C���[��ID
#define ID_ENE			8		// �G�l�~�[��ID
#define ID_HOLE			10		// �y�ǂ�ID
#define ID_STEP			13		// ����ID
#define ID_BOO			14		// ����ID
#define ID_HOLE2		15		// �y��2��ID
#define ID_SNOW			15		// ���ID
#define ID_BOMB			16		// ������ID

/* ____ �\���̐錾 ____ */
typedef struct {
	int idno ;					// ���ʔԍ�
	int mode ;					// �A�N�V�����Ǘ��ԍ�
	BOOL dspf ;					// �O�F��\��	1�F�\��
	double xp ;					// �X�N���[���w���W
	double yp ;					// �X�N���[���x���W
	int xsize ;					// �w�T�C�Y
	int ysize ;					// �x�T�C�Y
	int xboff ;					// �w�I�t�Z�b�g
	int yboff ;					// �x�I�t�Z�b�g
	int xmoff ;					// �w�}�X�N
	int ymoff ;					// �x�}�X�N
	int idx ;					// �摜�ԍ�
	int xoff ;					// ���S�_ X���W
	int yoff ;					// ���S�_ Y���W
	int pchg[5] ;
	double xspd ;
	double yspd ;
	BOOL lrflg ;
	int cnt ;
	int timer ;
	double ysave ;
} DT ;

typedef struct {
	int idno ;					// ���ʔԍ�
	int mode ;					// �A�N�V�����Ǘ��ԍ�
	BOOL dspf ;					// �O�F��\��	1�F�\��
	double xp ;					// �X�N���[���w���W
	double yp ;					// �X�N���[���x���W
	int xboff ;					// �w�I�t�Z�b�g
	int yboff ;					// �x�I�t�Z�b�g
	int pchg[5] ;				// 
	double xspd ;				// X speed
	double yspd ;				// Y speed
	int bno ;					// �u���b�N�̃i���o�[
	double ys ;					// �����̈ʒu���o���Ƃ��p
	double ysave ;
} BT ;

/* ____ �e�[�u���W�����v ____ */
typedef void ( *TBLJP )( void ) ;

/* ____ �v���g�^�C�v�錾 ____ */
LRESULT CALLBACK WndProc ( HWND , UINT , WPARAM , LPARAM ) ;
void GameLoop( void ) ;
void ActionLoop( void ) ;
void DispLoop( void ) ;
void ActTitle( void ) ;
void ActStart( void ) ;
void ActBg( void ) ;
void BlockSet( void ) ;
void ActBlock( void ) ;
void ActPlayer( void ) ;
int FootCheck( void ) ;
int HeadCheck( void ) ;
void ActEnemy( void ) ;
void ActHole( void ) ;
void ActWarp( void ) ;
void EnemySet( void ) ;
void BBcheck( void ) ;
void PAcheck( void ) ;
void FootHitCheck( void ) ;
void ActBoo( void ) ;
int ObjSearch( int , int ) ;
void ActStep( void ) ;
int Body_Block( void ) ;
void ActHole2( void ) ;
void ActSnow( void ) ;
void ActBomb( void ) ;


