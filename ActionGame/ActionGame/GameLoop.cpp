/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   ÉQÅ[ÉÄÉãÅ[Év													*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*						âΩÇ‡ÇµÇ»Ç¢ä÷êî					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void GameNull( void )
{
}

/*______________________________________________________*/
/*						ÉQÅ[ÉÄäJén						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void GameAInit( void )
{

	gmode = GM_I_TITLE ;								// É^ÉCÉgÉãÇÃèâä˙ÉZÉbÉgÇ÷à⁄ìÆÇ∑ÇÈ

	/* >> ÉfÉoÉbÉO << */
	gmode = GM_I_GAME ;

}

/*______________________________________________________*/
/*					É^ÉCÉgÉãÇÃèâä˙ÉZÉbÉg				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void GameITitle( void )
{
	obj[O_TITLE].idno = ID_TITLE ;						// É^ÉCÉgÉã (îwåi) ÇÃåƒÇ—èoÇµ
	obj[O_TITLE].mode = 0 ;								// É^ÉCÉgÉã (îwåi) ÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ

	obj[O_START].idno = ID_START ;						// ÉXÉ^Å[Ég (ï∂éö) ÇÃåƒÇ—èoÇµ
	obj[O_START].mode = 0 ;								// ÉXÉ^Å[Ég (ï∂éö) ÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ 

	gmode = GM_M_TITLE ;								// É^ÉCÉgÉãÇ…à⁄ìÆ
}

/*______________________________________________________*/
/*						É^ÉCÉgÉãíÜ						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void GameMTitle( void )
{
	if ( obj[O_START].idno == 0 )						// ÉXÉ^Å[ÉgÇ™è¡Ç¶ÇΩÇ∆Ç´ ( SPACE KEY Ç™âüÇ≥ÇÍÇÈÇ∆è¡Ç¶ÇÈ )
	{
		gmode = GM_E_TITLE ;							// É^ÉCÉgÉãèIóπÇ÷à⁄ìÆ
	}
}

/*______________________________________________________*/
/*						É^ÉCÉgÉãèIóπ					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void GameETitle( void )
{
	obj[O_TITLE].idno = 0;								// É^ÉCÉgÉã (îwåi) Çè¡Ç∑
	obj[O_TITLE].mode = 0 ;								// É^ÉCÉgÉã (îwåi) ÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ

	obj[O_START].idno = 0 ;								// ÉXÉ^Å[Ég (ï∂éö) Çè¡Ç∑
	obj[O_START].mode = 0 ;								// ÉXÉ^Å[Ég (ï∂éö) ÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ

	gmode = GM_I_GAME ;									// ÉQÅ[ÉÄäJénÇ∑ÇÈ
}

/*______________________________________________________*/
/*					  ÉQÅ[ÉÄèâä˙ÉZÉbÉg					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void GameIGame( void )
{
	obj[O_BG].idno = ID_BG ;							// îwåiÇÃåƒÇ—èoÇµ
	obj[O_BG].mode = 0 ;								// îwåiÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ

	obj[O_PLY].idno = ID_PLY ;							// ÉvÉåÉCÉÑÅ[ÇÃåƒÇ—èoÇµ
	obj[O_PLY].mode = 0 ;								// ÉvÉåÉCÉÑÅ[ÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ

	obj[O_HOLE+0].idno = ID_HOLE ;							// îwåiÇÃåƒÇ—èoÇµ
	obj[O_HOLE+0].mode = 0 ;								// îwåiÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ
	obj[O_HOLE+0].cnt = 0 ;								// îwåiÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ

	obj[O_HOLE+1].idno = ID_HOLE ;							// îwåiÇÃåƒÇ—èoÇµ
	obj[O_HOLE+1].mode = 0 ;								// îwåiÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ
	obj[O_HOLE+1].cnt = 1 ;								// îwåiÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ

	obj[O_HOLE+2].idno = ID_HOLE ;							// îwåiÇÃåƒÇ—èoÇµ
	obj[O_HOLE+2].mode = 0 ;								// îwåiÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ
	obj[O_HOLE+2].cnt = 2;								// îwåiÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ

	obj[O_HOLE+3].idno = ID_HOLE ;							// îwåiÇÃåƒÇ—èoÇµ
	obj[O_HOLE+3].mode = 0 ;								// îwåiÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ
	obj[O_HOLE+3].cnt = 3 ;								// îwåiÇÃèâä˙ÉZÉbÉgÇÃåƒÇ—èoÇµ

	EnemySet( ) ;
	BlockSet( ) ;										// ÉuÉçÉbÉNÇÃîzíu

	gmode = GM_M_GAME ;									// ÉQÅ[ÉÄäJénÇ∑ÇÈ
}

/*______________________________________________________*/
/*						  ÉQÅ[ÉÄíÜ						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void GameMGame( void )
{

}

/*______________________________________________________*/
/*						ÉQÅ[ÉÄèIóπéû					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void GameEGame( void )
{
}

/*______________________________________________________*/
/*					 ÉQÅ[ÉÄÉWÉÉÉìÉvóp					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
TBLJP GameJpTbl[ ] = {
	GameAInit ,											//  00 : ëSïîÇÃèâä˙âª
	GameITitle ,										//  01 : É^ÉCÉgÉãÇÃèâä˙ÉZÉbÉg
	GameMTitle ,										//  02 : É^ÉCÉgÉãÇÃç≈íÜ
	GameETitle ,										//  03 : É^ÉCÉgÉãèIóπéû
	GameNull ,											//  04 : 
	GameIGame ,											//  05 : ÉQÅ[ÉÄÇÃèâä˙ÉZÉbÉg
	GameMGame ,											//  06 : ÉQÅ[ÉÄÇÃç≈íÜ
	GameEGame ,											//  07 : ÉQÅ[ÉÄèIóπéû
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
/*						ÉQÅ[ÉÄÉãÅ[Év					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void GameLoop( void )
{
	GameJpTbl[ gmode ]( ) ;								// ÇªÇÍÇºÇÍÇÃä÷êîÇ÷ÉWÉÉÉìÉvÇ∑ÇÈ
}



