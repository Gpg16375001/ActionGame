/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																												*/
/*												�E�B���h�v���V�[�W���[											*/
/*																												*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

#include <windows.h>
#include "resource.h"
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					�G���g���|�C���g					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
int APIENTRY WinMain ( HINSTANCE hInstance ,
					   HINSTANCE hPrevInstance ,
					   LPSTR lpCmdLine ,
					   int nCmdShow )
{
	WNDCLASSEX wcex ;
	HWND hWnd ;
	MSG msg ;
	RECT sPos ;

	SetRect( &sPos , 0 , 0 , WINDOW_W , WINDOW_H ) ;
	AdjustWindowRect( &sPos , WS_OVERLAPPEDWINDOW , FALSE ) ;

	wcex.cbSize = sizeof ( WNDCLASSEX ) ;
	wcex.style = CS_HREDRAW | CS_VREDRAW ;
	wcex.lpfnWndProc = ( WNDPROC ) WndProc ;
	wcex.cbClsExtra = 0 ;
	wcex.cbWndExtra = 0 ;
	wcex.hInstance = hInstance ;
	wcex.hIcon = LoadIcon ( NULL , IDI_APPLICATION ) ;
	wcex.hCursor = LoadCursor ( NULL , IDC_ARROW ) ;
	wcex.hbrBackground = ( HBRUSH )( COLOR_WINDOW + 1 ) ;
	wcex.lpszMenuName = NULL ;
	wcex.lpszClassName = TEXT( "ModelApp" ) ;
	wcex.hIconSm = LoadIcon ( NULL , IDI_APPLICATION ) ;

	RegisterClassEx ( &wcex ) ;

	hWnd = CreateWindow ( wcex.lpszClassName ,
		TEXT( "�A�N�V�����Q�[��" ) ,
		WS_OVERLAPPEDWINDOW ,
		CW_USEDEFAULT ,
		CW_USEDEFAULT ,
		sPos.right - sPos.left ,
		sPos.bottom - sPos.top ,
		NULL ,
		NULL ,
		hInstance ,
		NULL ) ;

	hwnd = hWnd ;

	ShowWindow ( hWnd , nCmdShow ) ;
	UpdateWindow ( hWnd ) ;


	while ( GetMessage ( &msg , NULL , 0 , 0 ) )
	{
		TranslateMessage ( &msg ) ;
		DispatchMessage ( &msg ) ;
	}

	return msg.wParam ;
}

/*______________________________________________________*/
/*				   �E�B���h�E�v���V�[�W��				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
LRESULT CALLBACK WndProc ( HWND hWnd ,
						    UINT message ,
							WPARAM wParam ,
							LPARAM lParam )
{
	static HINSTANCE	hInst ;
	HBITMAP				hBitmap ;
	PAINTSTRUCT			ps ;
	HDC					hDC ;
	TCHAR				s[50] ;

	switch ( message )
	{
		case WM_CREATE :
			hInst = ( HINSTANCE )GetWindowLong( hWnd , GWL_HINSTANCE ) ;
			hBmpTbl[0] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_TITLE) ) ;		// �^�C�g��
			hBmpTbl[1] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_START) ) ;		// �X�^�[�g�̕���
			hBmpTbl[2] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_BG) ) ;		// �w�i
			hBmpTbl[3] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_BLOCK) ) ;		// �u���b�N
			hBmpTbl[4] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_LPLAYER) ) ;	// �v���C���[	( ������ )
			hBmpTbl[5] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_RPLAYER) ) ;	// �v���C���[	( �E���� )
			hBmpTbl[6] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_LENEMY) ) ;	// �G�l�~�[		( ������ )
			hBmpTbl[7] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_RENEMY) ) ;	// �G�l�~�[		( �E���� )
			hBmpTbl[8] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_HOLE) ) ;		// �y��
			hBmpTbl[9] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_OBJ) ) ;		// OBJ
			hBmpTbl[10] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_HOLE2) ) ;	// �y��2
			hBmpTbl[11] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_SHOTS) ) ;	// �e�̃C���X�g

			hDC = GetDC ( hWnd ) ;
			hDCBack = CreateCompatibleDC ( hDC ) ;
			hBitmap = CreateCompatibleBitmap ( hDC , WINDOW_W , WINDOW_H ) ;
			SelectObject ( hDCBack , hBitmap ) ;
			DeleteObject ( hBitmap ) ;
			ReleaseDC ( hWnd , hDC ) ;

			gmode = GM_I_ALL ;							// �S�̂̏����Z�b�g�Ɉړ�

			SetTimer ( hWnd , 1 , 50 , NULL ) ;
			break ;

		case WM_TIMER :
			if ( tmf == 0 )								// �������I���܂ŕ`�悵�����Ȃ��悤�ɂ��邽��
			{
				tmf++ ;									// �������I���܂ŕ`�悵�����Ȃ��悤�ɂ���ϐ�
				GameLoop( ) ;							// �Q�[���S�̂̏���
				ActionLoop( ) ;							// �A�N�V�����S�̂̏���
				DispLoop( ) ;
				InvalidateRect( hWnd, NULL, FALSE ) ;
			}
			break ;

		case WM_PAINT :
			hDC = BeginPaint ( hWnd , &ps ) ;
			BitBlt ( hDC , 0 , 0 , WINDOW_W , WINDOW_H , hDCBack , 0 , 0 , SRCCOPY ) ;

			wsprintf( s , TEXT("gmode = %04d") , gmode ) ;
			TextOut( hDC , 0 , 0 , s , lstrlen(s) ) ;
			wsprintf( s , TEXT("gmode = %04d") , obj[O_PLY].pchg[4] ) ;
			TextOut( hDC , 0 , 20 , s , lstrlen(s) ) ;

			tmf = 0;
			EndPaint ( hWnd , &ps ) ;
			break ;

		case WM_DESTROY :
			DeleteDC( hDCBack ) ;						//����ʂ̍폜
			//�r�b�g�}�b�v�̍폜
			DeleteObject( hBmpTbl[0] ) ;
			DeleteObject( hBmpTbl[1] ) ;
			DeleteObject( hBmpTbl[2] ) ;
			DeleteObject( hBmpTbl[3] ) ;
			DeleteObject( hBmpTbl[4] ) ;
			DeleteObject( hBmpTbl[5] ) ;
			DeleteObject( hBmpTbl[6] ) ;
			DeleteObject( hBmpTbl[7] ) ;
			DeleteObject( hBmpTbl[8] ) ;
			DeleteObject( hBmpTbl[9] ) ;
			DeleteObject( hBmpTbl[10] ) ;
			DeleteObject( hBmpTbl[11] ) ;

			KillTimer( hWnd, 1 ) ;			//�^�C�}�̍폜
			PostQuitMessage ( 0 ) ;
			break ;
			
		default :
			return DefWindowProc ( hWnd , message , wParam , lParam ) ;
	}

	return 0 ;
}



