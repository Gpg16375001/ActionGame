/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   ÇªÇÃëº ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*				    	ÉèÅ[Évèàóù						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActWarp( void )
{
	if ( pp->xp < 0 )
	{
		pp->xp = WINDOW_W - 10 ;
	}
	if ( pp->xp > WINDOW_W )
	{
		pp->xp = 10 ;
	}

	// 0î‘ñ⁄ÇÃìyä« ( ç∂è„ )
	if ( (pp->xp > 0) && (pp->xp < 32) && (pp->yp > 64) && (pp->yp < 160) )
	{
		// âEâ∫ÇÃ3î‘ñ⁄ÇÃìyä«Ç…îÚÇ‘
		pp->xp = 736.0 ;								// âEë§ÇÃç¿ïW
		pp->yp = FLIMIT ;								// ínñ ÇÃç¿ïW
	}

	// 1î‘ñ⁄ÇÃìyä« ( âEè„ )
	if ( (pp->xp > 768.0) && (pp->xp < WINDOW_W) && (pp->yp > 64) && (pp->yp < 160) )
	{
		// ç∂â∫ÇÃ2î‘ñ⁄ÇÃìyä«Ç…îÚÇ‘
		pp->xp = 64.0 ;									// ç∂ë§ÇÃç¿ïW
		pp->yp = FLIMIT ;								// ínñ ÇÃç¿ïW
	}

	// 2î‘ñ⁄ÇÃìyä« ( ç∂â∫ )
	if ( (pp->xp > 0) && (pp->xp < 32) && (pp->yp > (FLIMIT-32)) && (pp->yp < (FLIMIT+32)) )
	{
		// âEè„ÇÃ2î‘ñ⁄ÇÃìyä«Ç…îÚÇ‘
		pp->xp = 736.0 ;								// âEë§ÇÃç¿ïW
		pp->yp = 96.0 ;									// è„ÇÃÉuÉçÉbÉNè∞ÇÃç¿ïW
	}

	// 3î‘ñ⁄ÇÃìyä« ( âEâ∫ )
	if ( (pp->xp > 768.0) && (pp->xp < WINDOW_W) && (pp->yp > (FLIMIT-32)) && (pp->yp < (FLIMIT+32)) )
	{
		// ç∂è„ÇÃ0î‘ñ⁄ÇÃìyä«Ç…îÚÇ‘
		pp->xp = 64.0 ;									// ç∂ë§ÇÃç¿ïW
		pp->yp = 96.0 ;									// è„ÇÃÉuÉçÉbÉNè∞ÇÃç¿ïW
	}


}

/*______________________________________________________*/
/*						ìyä«ÇÃîzíu						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActHole( void )
{
	int HoleTbl[4][3] = {
		{  50 , 100 , 100 } ,							// 0î‘ÇÃìyä«
		{ 750 , 100 ,   0 } ,							// 1î‘ÇÃìyä«
		{  50 , 578 , 100 } ,							// 2î‘ÇÃìyä«
		{ 750 , 578 ,   0 } ,							// 3î‘ÇÃìyä«
	} ;

	switch ( pp->mode )
	{
		case 0 :
			pp->dspf = 1 ;								// ÇOÅFîÒï\é¶	1ÅFï\é¶
			pp->xsize = 100 ;							// ÇwÉTÉCÉY
			pp->ysize = 100 ;							// ÇxÉTÉCÉY
			pp->yboff = 0 ;								// ÇxÉIÉtÉZÉbÉg
			pp->ymoff = 100 ;							// ÇxÉ}ÉXÉN
			pp->xoff = -50 ;							// ÇwÉ}ÉXÉN
			pp->yoff = -100 ;							// ÇxÉ}ÉXÉN
			pp->idx = 8 ;								// âÊëúî‘çÜ
			pp->mode = 1 ;								// ÉAÉNÉVÉáÉìä«óùî‘çÜ

			pp->xp = (double)HoleTbl[pp->cnt][0] ;		// ÉXÉNÉäÅ[ÉìÇwç¿ïW
			pp->yp = (double)HoleTbl[pp->cnt][1] ;		// ÉXÉNÉäÅ[ÉìÇxç¿ïW
			pp->xboff = HoleTbl[pp->cnt][2] ;			// ÇwÉIÉtÉZÉbÉg
			pp->xmoff = HoleTbl[pp->cnt][2] ;			// ÇwÉ}ÉXÉN
			break ;

		case 1 :
			break ;

	}
}

/*______________________________________________________*/
/*				  ãÛÇ´ÉIÉuÉWÉFÉNÉg ÉTÅ[É`				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
int ObjSearch( int st , int tm )
{
	int no = -1 ;												// èâä˙ÉZÉbÉg

	for (  ; st < (st+tm) ; st++ )								// éwíËílÇ‹Ç≈ÉJÉEÉìÉg
	{
		if ( obj[st].idno == 0 )								// ï`âÊÇ≥ÇÍÇƒÇ»Ç¢ idnum
		{
			no = st ;											// no Ç… ÇªÇÃîzóÒ Çì¸ÇÍÇÈ
			return no ;											// no Çï‘Ç∑
		}
	}

	return no ;													// no Çï‘Ç∑

}


