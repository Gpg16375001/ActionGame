/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   PLAYER ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

#define PXSPD		8.0									// ƒvƒŒƒCƒ„[‚Ìs‚Ò[‚Ç

/*______________________________________________________*/
/*		0		  ƒvƒŒƒCƒ„[‚Ì‰ŠúƒZƒbƒg				*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void AInit( void )
{
	pp->dspf = 1 ;										// ‚OF”ñ•\¦	1F•\¦
	pp->xp = 400.0 ;									// ƒXƒNƒŠ[ƒ“‚wÀ•W
	pp->yp = FLIMIT ;									// ƒXƒNƒŠ[ƒ“‚xÀ•W
	pp->xsize = 80 ;									// ‚wƒTƒCƒY
	pp->ysize = 80 ;									// ‚xƒTƒCƒY
	pp->xboff = 0 ;										// ‚wƒIƒtƒZƒbƒg
	pp->yboff = 0 ;										// ‚xƒIƒtƒZƒbƒg
	pp->xmoff = 0 ;										// ‚wƒ}ƒXƒN
	pp->ymoff = 80 ;									// ‚xƒ}ƒXƒN
	pp->xoff = -40 ;									// ‚wƒ}ƒXƒN
	pp->yoff = -76 ;									// ‚xƒ}ƒXƒN
	pp->idx = 4 ;										// ‰æ‘œ”Ô†

	pp->mode = 1 ;										// ƒAƒNƒVƒ‡ƒ“ŠÇ—”Ô†

}

/*______________________________________________________*/
/*		1		  ƒvƒŒƒCƒ„[ ’â~‚µ‚½‚Æ‚«				*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void AStopW( BOOL lr )
{
		pp->lrflg = lr ;								// 0:¶ ‚© 1:‰E ‚ª“ü‚é
		pp->mode = 2 ;									// •à‚«’†‚Ìƒ‚[ƒh‚Ö
		pp->pchg[0] = 0 ;								// ƒ^ƒCƒ}[‚Ì‰Šú‰»
		pp->pchg[1] = 0 ;								// ƒJƒEƒ“ƒ^‚Ì‰Šú‰» ƒAƒjƒ[ƒVƒ‡ƒ“—p
}

void AStop( void ) 
{
	ActWarp( ) ;

	if ( GetKeyState(VK_LEFT) < 0 )						// ¶‚ª‰Ÿ‚³‚ê‚½‚Æ‚«
	{
		AStopW( 0 ) ;									// ƒAƒjƒ[ƒVƒ‡ƒ“’â~ŠÖ”‚Ö
	}

	if ( GetKeyState(VK_RIGHT) < 0 )					// ‰E‚ª‰Ÿ‚³‚ê‚½‚Æ‚«
	{
		AStopW( 1 ) ;									// ƒAƒjƒ[ƒVƒ‡ƒ“’â~ŠÖ”‚Ö
	}

	if ( (GetKeyState(VK_SPACE) < 0) && (pp->pchg[4] != 1) )// SPACE KEY ‚ª‰Ÿ‚³‚ê‚½
	{
		pp->mode = 3 ;									// ƒWƒƒƒ“ƒv‚Ìƒ‚[ƒh‚Ö
	}

	if ( GetKeyState(VK_SHIFT) < 0 )					// SPACE KEY ‚ª‰Ÿ‚³‚ê‚½
	{
		pp->mode = 5 ;									// UŒ‚‚Ìƒ‚[ƒh‚Ö
	}

}

/*______________________________________________________*/
/*		2		  ƒvƒŒƒCƒ„[ •à‚¢‚Ä‚é‚Æ‚«				*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void AWalk( void ) 
{
	pp->xspd = 0 ;										// Xspeed ‚Ì‰Šú‰»
	pp->yspd = 0 ;										// Yspeed ‚Ì‰Šú‰»

	ActWarp( ) ;
	
	if ( GetKeyState(VK_LEFT) < 0 )						// ¶‚ª‰Ÿ‚³‚ê‚½‚Æ‚«
	{
		pp->lrflg = 0 ;									// 0:¶ ‚ğ“ü‚ê‚é
		pp->xspd = -PXSPD ;								// ¶‚Éi‚Ş
	}

	if ( GetKeyState(VK_RIGHT) < 0 )					// ‰E‚ª‰Ÿ‚³‚ê‚½‚Æ‚«
	{
		pp->lrflg = 1 ;									// 1:‰E ‚ğ“ü‚ê‚é
		pp->xspd = PXSPD ;								// ‰E‚Éi‚Ş
	}

	if ( (GetKeyState(VK_SPACE) < 0) && (pp->pchg[4] != 1) )// SPACE KEY ‚ª‰Ÿ‚³‚ê‚½‚Æ‚«
	{
		pp->mode = 3 ;									// ƒ‚[ƒh‚ğƒWƒƒƒ“ƒv‚Ö
	}

	if ( GetKeyState(VK_SHIFT) < 0 )					// SPACE KEY ‚ª‰Ÿ‚³‚ê‚½
	{
		pp->mode = 5 ;									// UŒ‚‚Ìƒ‚[ƒh‚Ö
	}

	pp->xp += pp->xspd ;								// ‰¡•ûŒü‚É“®‚­
	if ( pp->xspd == 0.0 )								// XƒXƒs[ƒh‚ª 0 ‚Ì
	{
		pp->mode = 1 ;									// ƒ‚[ƒh‚ğ’â~’†‚Ö
		pp->xboff = 0 ;									// ƒx[ƒX‚ğ’â~’†‚ÌŠG‚É‚·‚é
		pp->xmoff = 0 ;									// ƒ}ƒXƒN‚ğ’â~’†‚ÌŠG‚É‚·‚é
	}

	if ( (FootCheck( ) == 0) && (pp->pchg[4] != 1) )	// ‘«Œ³‚Ìƒ`ƒFƒbƒN ‰½‚à‚È‚©‚Á‚½
	{
		pp->mode = 11 ;									// —‰º’†‚Ìƒ‚[ƒh‚Ö
	}

}

/*______________________________________________________*/
/*		3	 ƒvƒŒƒCƒ„[ ƒWƒƒƒ“ƒv‚Ì‰ŠúƒZƒbƒg			*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void AIJump( void )
{
	pp->yspd = -16.0 ;									// ã•ûŒü‚É‰‘¬‚ğ’Ç‰Á
	pp->xboff = 640 + 80 ;								// ƒx[ƒX‚ğƒWƒƒƒ“ƒv‚ÌŠG‚É‚·‚é
	pp->xmoff = 640 + 80 ;								// ƒ}ƒXƒN‚ğƒWƒƒƒ“ƒv‚ÌŠG‚É‚·‚é

	obj[O_BOO].idno = ID_BOO ;
	obj[O_BOO].xp = pp->xp ;
	obj[O_BOO].yp = pp->yp - 50 ;

	pp->mode = 4 ;										// ƒ‚[ƒh‚ğƒWƒƒƒ“ƒv’†‚Ö

}

/*______________________________________________________*/
/*		4		  ƒvƒŒƒCƒ„[ ƒWƒƒƒ“ƒv’†					*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void AJump( void )
{
	double yp ;

		ActWarp( ) ;

	pp->yspd += 0.7 ;									// d—Í
	pp->yp += pp->yspd ;								// c•ûŒü‚É“®‚­
	if ( pp->yspd > 2.0 )								// —‰º‘¬“x‚ª 2.0 ˆÈã‚Ì
	{
		pp->xboff = 720 ;								// ƒx[ƒX‚ğ—‰º’†‚ÌŠG‚É‚·‚é
		pp->xmoff = pp->xboff ;							// ƒ}ƒXƒN‚ğ—‰º’†‚ÌŠG‚É‚·‚é
	}

	/*
		ƒWƒƒƒ“ƒv’†‚Ì‰¡ˆÚ“®
	*/
	pp->xspd = 0 ;										// Xspeed ‚Ì‰Šú‰»
	if ( GetKeyState(VK_LEFT) < 0 )						// ¶‚ª‰Ÿ‚³‚ê‚½‚Æ‚«
	{
		pp->xspd = -PXSPD ;								// ¶‚Éi‚Ş
	}
	if ( GetKeyState(VK_RIGHT) < 0 )					// ‰E‚ª‰Ÿ‚³‚ê‚½‚Æ‚«
	{
		pp->xspd = PXSPD ;								// ‰E‚Éi‚Ş
	}
	pp->xp += pp->xspd ;								// ‰¡•ûŒü‚É“®‚­

	/*
		“ªã‚Ì‚ ‚½‚è”»’è
		å‚ÉƒuƒƒbƒN
	*/
	if ( HeadCheck( ) != 0 )							// “Vˆä‚É“–‚½‚Á‚½‚©‚Ç‚¤‚©
	{
		pp->yspd *= -0.8 ;								// “Ë‚«—‚Æ‚³‚ê‚é
	}

	/*
		‘«Œ³‚Ì‚ ‚½‚è”»’è
		ƒuƒƒbƒN‚â’n–Ê‚È‚Ç
	*/
	yp = FootCheck( ) ;									// ‘«Œ³‚ğƒ`ƒFƒbƒN‚·‚é
	if ( yp != 0 )										// ‘«Œ³‚É‰½‚©‚ ‚Á‚½
	{
		pp->yp = yp ;									// YÀ•W‚ğ‚»‚Ì‘«Œ³‚ÅŒÅ’è‚·‚é
		pp->mode = 1 ;									// ƒ‚[ƒh‚ğ’â~’†‚Ö
		pp->yspd = 0 ;									// Yspeed ‚ğ‰Šú‰»‚·‚é
		pp->xboff = 0 ;									// ƒx[ƒX‚ğ’â~’†‚ÌŠG‚É‚·‚é
		pp->xmoff = pp->xboff ;							// ƒ}ƒXƒN‚ğ’â~’†‚ÌŠG‚É‚·‚é
	}

}

/*______________________________________________________*/
/*		5		 ƒvƒŒƒCƒ„[ UŒ‚‚Ì‰ŠúƒZƒbƒg			*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void AIAttack( void )
{
	pp->yspd = -16.0 ;									// ã•ûŒü‚É‰‘¬‚ğ’Ç‰Á
	pp->xsize = 96 ;
	pp->xboff = 960 ;									// ƒx[ƒX‚ğƒWƒƒƒ“ƒv‚ÌŠG‚É‚·‚é
	pp->xmoff = 960 ;									// ƒ}ƒXƒN‚ğƒWƒƒƒ“ƒv‚ÌŠG‚É‚·‚é

	pp->mode = 6 ;										// ƒ‚[ƒh‚ğUŒ‚’†‚Ö
	pp->pchg[0] = 20 ;

}

/*______________________________________________________*/
/*		6			ƒvƒŒƒCƒ„[ UŒ‚’†					*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void AAttack( void )
{
	PAcheck( ) ;										// UŒ‚

	pp->pchg[0]-- ;
	if ( pp->pchg[0] == 10 )
	{
		pp->xboff = 1054 ;								// ƒx[ƒX‚ğƒWƒƒƒ“ƒv‚ÌŠG‚É‚·‚é
		pp->xmoff = pp->xboff ;							// ƒ}ƒXƒN‚ğƒWƒƒƒ“ƒv‚ÌŠG‚É‚·‚é
	}

	if ( pp->pchg[0] <= 0 )
	{
		pp->xsize = 80 ;
		pp->mode = 1 ;
	}

}

/*______________________________________________________*/
/*		7		  ƒvƒŒƒCƒ„[ UŒ‚‚³‚ê‚½‚Æ‚«				*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void AIDamege( void )
{

}

/*______________________________________________________*/
/*		8		  ƒvƒŒƒCƒ„[ UŒ‚‚³‚ê‚½‚Æ‚«				*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ADamege( void )
{

}

/*______________________________________________________*/
/*		9	ƒvƒŒƒCƒ„[ €‚ñ‚¾‚Æ‚«‚Ì‰ŠúƒZƒbƒg			*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void AIOut( void )
{
	pp->yspd = -10.0 ;									// Yspeed ‚ğ‰Šú‰»‚·‚é
	pp->xboff = 80 * 11 ;								// ƒx[ƒX‚ğ—‰º’†‚ÌŠG‚É‚·‚é
	pp->xmoff = 80 * 11 ;								// ƒ}ƒXƒN‚ğ—‰º’†‚ÌŠG‚É‚·‚é

	pp->mode = 10 ;										// ƒ‚[ƒh‚ğƒWƒƒƒ“ƒv’†‚Ö

}

/*______________________________________________________*/
/*		10		  ƒvƒŒƒCƒ„[ €‚ñ‚¾‚Æ‚«					*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void AOut( void )
{
	pp->yspd += 1.0 ;
	pp->yp += pp->yspd ;
}

/*______________________________________________________*/
/*		11		  @ƒvƒŒƒCƒ„[ —‰º’†					*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void AIDown( void )
{
	pp->yspd = 0 ;										// Yspeed ‚ğ‰Šú‰»‚·‚é
	pp->xboff = 720 ;									// ƒx[ƒX‚ğ—‰º’†‚ÌŠG‚É‚·‚é
	pp->xmoff = 720 ;									// ƒ}ƒXƒN‚ğ—‰º’†‚ÌŠG‚É‚·‚é

	pp->mode = 4 ;										// ƒ‚[ƒh‚ğƒWƒƒƒ“ƒv’†‚Ö

}


TBLJP ActPTbl[ ] =
{
	AInit ,												// 0  :	‰ŠúƒZƒbƒg
	AStop ,												// 1  : ’â~’†
	AWalk ,												// 2  : •à‚«’†
	AIJump ,											// 3  : ƒWƒƒƒ“ƒv‰ŠúƒZƒbƒg
	AJump ,												// 4  : ƒWƒƒƒ“ƒv’†
	AIAttack ,											// 5  : UŒ‚‚Ì‰ŠúƒZƒbƒg
	AAttack ,											// 6  : UŒ‚’†
	AIDamege ,											// 7  : ƒ_ƒ[ƒW‰ŠúƒZƒbƒg
	ADamege ,											// 8  : ƒ_ƒ[ƒWó‚¯‚é
	AIOut ,												// 9  : €–S‰ŠúƒZƒbƒg
	AOut ,												// 10 : €–S
	AIDown ,											// 11 : —‰º‰ŠúƒZƒbƒg
} ;

/*______________________________________________________*/
/*				  ƒvƒŒƒCƒ„[‚ÌƒAƒNƒVƒ‡ƒ“				*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActPlayer( void )
{
	ActPTbl[pp->mode]( ) ;								// ƒvƒŒƒCƒ„[‚ÌƒAƒNƒVƒ‡ƒ“‚Ìƒe[ƒuƒ‹ƒWƒƒƒ“ƒv

	FootHitCheck( ) ;
	if ( pp->lrflg == 0 )								// ¶‚ğŒü‚¢‚Ä (“ü—Í) ‚¢‚é‚Æ‚«
	{
		pp->idx = 4 ;									// ¶Œü‚«‚Ì‰æ‘œ‚É•Ï‚¦‚é
	}
	else												// ‰E‚ğŒü‚¢‚Ä (“ü—Í) ‚¢‚é‚Æ‚«
	{
		pp->idx = 5 ;									// ¶Œü‚«‚Ì‰æ‘œ‚É•Ï‚¦‚é
	}

	/*
		•à‚¢‚Ä‚¢‚é‚Æ‚«
	*/
	pp->pchg[0]-- ;										// ƒ^ƒCƒ}[‚ğƒJƒEƒ“ƒgƒ_ƒEƒ“
	if ( pp->pchg[0] <= 0 )								// ƒ^ƒCƒ}[‚ÌƒJƒEƒ“ƒg‚ª 0ˆÈ‰º‚É‚È‚Á‚½‚ç
	{
		pp->pchg[0] = 2 ;								// ƒAƒjƒ[ƒVƒ‡ƒ“‚Ìƒ^ƒCƒ}[ƒZƒbƒg
		pp->pchg[1]++ ;									// Ÿ‚ÌƒCƒ‰ƒXƒg‚ÉˆÚ‚é
		if ( pp->pchg[1] >= 4 )							// ƒAƒjƒ[ƒVƒ‡ƒ“‚ªI‚í‚Á‚½‚ç
		{
			pp->pchg[1] = 0 ;							// Å‰‚ÌŠG‚É–ß‚·
		}

		if ( ( GetKeyState(VK_LEFT) < 0 ) && (pp->mode != 4) || ( GetKeyState(VK_RIGHT) < 0 ) && (pp->mode != 4) )
		{
			pp->xboff = (pp->pchg[1] * 80) + 320 ;		// ƒx[ƒX‚ÌƒCƒ‰ƒXƒg‚ÌˆÊ’u‚ğ“ü‚ê‚é
			pp->xmoff = (pp->pchg[1] * 80) + 320 ;		// ƒ}ƒXƒN‚ÌƒCƒ‰ƒXƒg‚ÌˆÊ’u‚ğ“ü‚ê‚é
		}
		else if ( pp->mode != 4 )
		{
			pp->xboff = (pp->pchg[1] * 80) ;			// ƒx[ƒX‚ÌƒCƒ‰ƒXƒg‚ÌˆÊ’u‚ğ“ü‚ê‚é
			pp->xmoff = (pp->pchg[1] * 80) ;			// ƒ}ƒXƒN‚ÌƒCƒ‰ƒXƒg‚ÌˆÊ’u‚ğ“ü‚ê‚é
		}
	}


}


