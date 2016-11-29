/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																												*/
/*												ウィンドプロシージャー											*/
/*																												*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

#include <windows.h>
#include "resource.h"
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					エントリポイント					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
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
		TEXT( "アクションゲーム" ) ,
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
/*				   ウィンドウプロシージャ				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
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
			hBmpTbl[0] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_TITLE) ) ;		// タイトル
			hBmpTbl[1] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_START) ) ;		// スタートの文字
			hBmpTbl[2] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_BG) ) ;		// 背景
			hBmpTbl[3] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_BLOCK) ) ;		// ブロック
			hBmpTbl[4] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_LPLAYER) ) ;	// プレイヤー	( 左向き )
			hBmpTbl[5] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_RPLAYER) ) ;	// プレイヤー	( 右向き )
			hBmpTbl[6] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_LENEMY) ) ;	// エネミー		( 左向き )
			hBmpTbl[7] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_RENEMY) ) ;	// エネミー		( 右向き )
			hBmpTbl[8] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_HOLE) ) ;		// 土管
			hBmpTbl[9] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_OBJ) ) ;		// OBJ
			hBmpTbl[10] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_HOLE2) ) ;	// 土管2
			hBmpTbl[11] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_SHOTS) ) ;	// 弾のイラスト

			hDC = GetDC ( hWnd ) ;
			hDCBack = CreateCompatibleDC ( hDC ) ;
			hBitmap = CreateCompatibleBitmap ( hDC , WINDOW_W , WINDOW_H ) ;
			SelectObject ( hDCBack , hBitmap ) ;
			DeleteObject ( hBitmap ) ;
			ReleaseDC ( hWnd , hDC ) ;

			gmode = GM_I_ALL ;							// 全体の初期セットに移動

			SetTimer ( hWnd , 1 , 50 , NULL ) ;
			break ;

		case WM_TIMER :
			if ( tmf == 0 )								// 処理が終わるまで描画し直さないようにするため
			{
				tmf++ ;									// 処理が終わるまで描画し直さないようにする変数
				GameLoop( ) ;							// ゲーム全体の処理
				ActionLoop( ) ;							// アクション全体の処理
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
			DeleteDC( hDCBack ) ;						//裏画面の削除
			//ビットマップの削除
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

			KillTimer( hWnd, 1 ) ;			//タイマの削除
			PostQuitMessage ( 0 ) ;
			break ;
			
		default :
			return DefWindowProc ( hWnd , message , wParam , lParam ) ;
	}

	return 0 ;
}



