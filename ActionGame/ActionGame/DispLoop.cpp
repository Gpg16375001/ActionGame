/*______________________________________________________________________________________________________________*/
/*																												*/
/*													  描画ループ												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"


void DispLoop( void )
{
	HDC	hDC ;
	HDC hDCWork ;
	int i ;
	int x , y ;

	hDC = GetDC( hwnd );
	hDCWork = CreateCompatibleDC( hDC );

	/*
		オブジェクトの描画
	*/
	for ( i = 0 ; i < MAXOBJ ; i++ )
	{
		if ( (obj[i].idno != 0) && (obj[i].mode != 0) && (obj[i].dspf != 0) )
		{
			x = (int)obj[i].xp + obj[i].xoff ;
			y = (int)obj[i].yp + obj[i].yoff ;

			SelectObject ( hDCWork , hBmpTbl[obj[i].idx] ) ;
			BitBlt ( hDCBack, x , y , obj[i].xsize , obj[i].ysize , hDCWork, obj[i].xmoff, obj[i].ymoff, SRCAND ) ;
			BitBlt ( hDCBack, x , y , obj[i].xsize, obj[i].ysize , hDCWork, obj[i].xboff, obj[i].yboff, SRCPAINT ) ;
		}
	}

	/*
		ブロックの描画
	*/
	for ( i = 0 ; i < MAXBLK ; i++ )
	{
		if ( (blk[i].idno != 0) && (blk[i].mode != 0) && (blk[i].dspf != 0) )
		{
			SelectObject ( hDCWork , hBmpTbl[3] ) ;
			if ( blk[i].bno != 6 )
			{
				BitBlt ( hDCBack, (int)blk[i].xp - 16 ,(int)blk[i].yp , 32 , 32 ,  hDCWork , 0 , 128 , SRCAND ) ;
			}
			else
			{
				BitBlt ( hDCBack, (int)blk[i].xp - 16 ,(int)blk[i].yp , 32 , 32 ,  hDCWork , 0 , 160 , SRCAND ) ;
			}
			BitBlt ( hDCBack, (int)blk[i].xp - 16 , (int)blk[i].yp , 32 , 32 ,
			hDCWork , blk[i].xboff , blk[i].yboff , SRCPAINT ) ;
		}
	}

	DeleteDC ( hDCWork ) ;
	ReleaseDC( hwnd, hDC );
}



