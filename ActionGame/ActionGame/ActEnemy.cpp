/*______________________________________________________________________________________________________________*/
/*																												*/
/*												   ENEMY ACTION												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"

#define EXSPD		6.0									// ÉGÉlÉ~Å[ÇÃÉXÉsÅ[Éh

/*______________________________________________________*/
/*		0		   ÉGÉlÉ~Å[ÇÃèâä˙ÉZÉbÉg					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeInit( void )
{
	pp->dspf = 1 ;										// ÇOÅFîÒï\é¶	1ÅFï\é¶
	pp->xspd = 0 ;										// Xspeed ÇÃèâä˙âª
	pp->yspd = 0 ;										// Yspeed ÇÃèâä˙âª
	pp->xsize = 80 ;									// ÇwÉTÉCÉY
	pp->ysize = 80 ;									// ÇxÉTÉCÉY
	pp->xboff = 0 ;										// ÇwÉIÉtÉZÉbÉg
	pp->yboff = 0 ;										// ÇxÉIÉtÉZÉbÉg
	pp->xmoff = 0 ;										// ÇwÉ}ÉXÉN
	pp->ymoff = 80 ;									// ÇxÉ}ÉXÉN
	pp->xoff = -40 ;									// ÇwíÜêSì_
	pp->yoff = -76 ;									// ÇxíÜêSì_
	pp->idx = 6 ;										// âÊëúî‘çÜ

	pp->mode = 1 ;										// ÉAÉNÉVÉáÉìä«óùî‘çÜ

}

/*______________________________________________________*/
/*		1		   ÉGÉlÉ~Å[ í‚é~ÇµÇΩÇ∆Ç´				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeStopW( BOOL lr )
{
		pp->lrflg = lr ;								// 0:ç∂ Ç© 1:âE Ç™ì¸ÇÈ
		pp->mode = 2 ;									// ï‡Ç´íÜÇÃÉÇÅ[ÉhÇ÷
		pp->pchg[0] = 0 ;								// É^ÉCÉ}Å[ÇÃèâä˙âª
		pp->pchg[1] = 0 ;								// ÉJÉEÉìÉ^ÇÃèâä˙âª ÉAÉjÉÅÅ[ÉVÉáÉìóp
}

void AeStop( void ) 
{
	ActWarp( ) ;

	if ( pp->xp > obj[O_PLY].xp )
	{
		AeStopW( 0 ) ;									// ÉAÉjÉÅÅ[ÉVÉáÉìí‚é~ä÷êîÇ÷
		pp->xspd = -EXSPD ;
	}
	else
	{
		AeStopW( 1 ) ;									// ÉAÉjÉÅÅ[ÉVÉáÉìí‚é~ä÷êîÇ÷
		pp->xspd = EXSPD ;
	}

	if ( (FootCheck( ) == 0) && (pp->pchg[4] != 1) )							// ë´å≥ÇÃÉ`ÉFÉbÉN âΩÇ‡Ç»Ç©Ç¡ÇΩéû
	{
		pp->mode = 11 ;									// óéâ∫íÜÇÃÉÇÅ[ÉhÇ÷
	}
	else
	{
		if ( edflg != -1 )								// 
		{
			pp->mode = 7 ;

			if ( bp->xp < edflg )
			{
				pp->xspd = -4.0 ;
			}
			else
			{
				pp->xspd = 4.0 ;
			}
		}
	}

}

/*______________________________________________________*/
/*		2		   ÉGÉlÉ~Å[ ï‡Ç¢ÇƒÇÈÇ∆Ç´				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeWalk( void ) 
{
//	BBcheck( ) ;
	ActWarp( ) ;

	if ( (rand( ) % 50) == 1 )
	{
		pp->mode = 1 ;
	}

	// â°à⁄ìÆ
	pp->xp += pp->xspd ;								// â°ï˚å¸Ç…ìÆÇ≠

	if ( (FootCheck( ) == 0) && (pp->pchg[4] != 1) )							// ë´å≥ÇÃÉ`ÉFÉbÉN âΩÇ‡Ç»Ç©Ç¡ÇΩéû
	{
		pp->mode = 11 ;									// óéâ∫íÜÇÃÉÇÅ[ÉhÇ÷
	}
	else
	{
		if ( edflg != -1 )
		{
			pp->mode = 7 ;

			if ( bp->xp < edflg )
			{
				pp->xspd = -4.0 ;
			}
			else
			{
				pp->xspd = 4.0 ;
			}
		}
	}

}

/*______________________________________________________*/
/*		3	   ÉGÉlÉ~Å[ ÉWÉÉÉìÉvÇÃèâä˙ÉZÉbÉg			*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeIJump( void )
{
	pp->yspd = -14.0 ;									// è„ï˚å¸Ç…èâë¨Çí«â¡
	pp->xboff = 640 ;									// ÉxÅ[ÉXÇÉWÉÉÉìÉvÇÃäGÇ…Ç∑ÇÈ
	pp->xmoff = 640 ;									// É}ÉXÉNÇÉWÉÉÉìÉvÇÃäGÇ…Ç∑ÇÈ

	if ( pp->mode != 12 )
	{
		pp->mode = 4 ;										// ÉÇÅ[ÉhÇÉWÉÉÉìÉvíÜÇ÷
	}
	else
	{
		pp->mode = 13 ;
	}

}

/*______________________________________________________*/
/*		4		   ÉGÉlÉ~Å[ ÉWÉÉÉìÉvíÜ					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeJump( void )
{
	double yp ;

	if ( pp->mode != 13 )
	{
		pp->yspd += 0.5 ;								// èdóÕ

		if ( pp->yspd > 2.0 )							// óéâ∫ë¨ìxÇ™ 2.0 à»è„ÇÃéû
		{
			pp->xboff = 720 ;							// ÉxÅ[ÉXÇóéâ∫íÜÇÃäGÇ…Ç∑ÇÈ
			pp->xmoff = pp->xboff ;						// É}ÉXÉNÇóéâ∫íÜÇÃäGÇ…Ç∑ÇÈ
		}
	}
	else
	{
		pp->yspd += 0.8 ;								// èdóÕ

		if ( obj[O_PLY].lrflg == 0 )
		{
			pp->xspd = -4.0 ;
		}
		else
		{
			pp->xspd = 4.0 ;
		}
		pp->xboff = 800 ;								// ÉxÅ[ÉXÇÇ‚ÇÁÇÍíÜÇÃäGÇ…Ç∑ÇÈ
		pp->xmoff = pp->xboff ;							// É}ÉXÉNÇÇ‚ÇÁÇÍíÜÇÃäGÇ…Ç∑ÇÈ

	}
	pp->yp += pp->yspd ;								// ècï˚å¸Ç…ìÆÇ≠
	/*
		ÉWÉÉÉìÉvíÜÇÃâ°à⁄ìÆ
	*/
	pp->xp += pp->xspd ;								// â°ï˚å¸Ç…ìÆÇ≠

	/*
		ì™è„ÇÃÇ†ÇΩÇËîªíË
		éÂÇ…ÉuÉçÉbÉN
	*/
	if ( HeadCheck( ) != 0 )							// ìVà‰Ç…ìñÇΩÇ¡ÇΩÇ©Ç«Ç§Ç©
	{
		pp->yspd *= -0.8 ;								// ìÀÇ´óéÇ∆Ç≥ÇÍÇÈ
	}

	/*
		ë´å≥ÇÃÇ†ÇΩÇËîªíË
		ÉuÉçÉbÉNÇ‚ínñ Ç»Ç«
	*/
	yp = FootCheck( ) ;									// ë´å≥ÇÉ`ÉFÉbÉNÇ∑ÇÈ
	if ( yp != 0 )										// ë´å≥Ç…âΩÇ©Ç†Ç¡ÇΩéû
	{
		pp->yp = (double)yp ;							// Yç¿ïWÇÇªÇÃë´å≥Ç≈å≈íËÇ∑ÇÈ
		pp->mode = 1 ;									// ÉÇÅ[ÉhÇí‚é~íÜÇ÷
		pp->yspd = 0 ;									// Yspeed Çèâä˙âªÇ∑ÇÈ
		pp->xboff = 0 ;									// ÉxÅ[ÉXÇí‚é~íÜÇÃäGÇ…Ç∑ÇÈ
		pp->xmoff = pp->xboff ;							// É}ÉXÉNÇí‚é~íÜÇÃäGÇ…Ç∑ÇÈ
	}

}

/*______________________________________________________*/
/*		5		   ÉGÉlÉ~Å[ çUåÇÇÃèâä˙ÉZÉbÉg			*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeIAttack( void )
{

}

/*______________________________________________________*/
/*		6			ÉGÉlÉ~Å[ çUåÇíÜ					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeAttack( void )
{

}

/*______________________________________________________*/
/*		7		  ÉGÉlÉ~Å[ çUåÇÇ≥ÇÍÇΩÇ∆Ç´				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeIDamege( void )
{
	pp->yspd = -5.0 ;									// è„ï˚å¸Ç…èâë¨Çí«â¡
	pp->xboff = 800 ;									// ÉxÅ[ÉXÇÇ‚ÇÁÇÍÇÃäGÇ…Ç∑ÇÈ
	pp->xmoff = pp->xboff ;								// É}ÉXÉNÇÇ‚ÇÁÇÍÇÃäGÇ…Ç∑ÇÈ
	pp->pchg[0] = 500 ;

	pp->mode = 8 ;										// ÉÇÅ[ÉhÇÉWÉÉÉìÉvíÜÇ÷
	
}

/*______________________________________________________*/
/*		8		  ÉGÉlÉ~Å[ çUåÇÇ≥ÇÍÇΩÇ∆Ç´				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeDamege( void )
{
	double yp ;

	pp->xp += pp->xspd ;

	pp->yspd += 0.5 ;
	pp->yp += pp->yspd ;

	/*
		ë´å≥ÇÃÇ†ÇΩÇËîªíË
		ÉuÉçÉbÉNÇ‚ínñ Ç»Ç«
	*/
	yp = FootCheck( ) ;									// ë´å≥ÇÉ`ÉFÉbÉNÇ∑ÇÈ
	if ( yp != 0 )										// ë´å≥Ç…âΩÇ©Ç†Ç¡ÇΩéû
	{
		pp->yp = (double)yp ;							// Yç¿ïWÇÇªÇÃë´å≥Ç≈å≈íËÇ∑ÇÈ
		pp->xspd = 0 ;									// Xspeed Çèâä˙âªÇ∑ÇÈ
		pp->yspd = 0 ;									// Yspeed Çèâä˙âªÇ∑ÇÈ

		pp->pchg[0]-- ;
		pp->dspf = 0 ;
		if ( pp->pchg[0] > 40 )
		{
			if ( (pp->pchg[0] & 0x07) < 4 )
			{
				pp->dspf = 1 ;
			}
		}
		else
		{
			if ( pp->pchg[0] < 0 )
			{
				pp->mode = 1 ;							// ÉÇÅ[ÉhÇí‚é~íÜÇ÷
				pp->dspf = 1 ;
				pp->xboff = 0 ;							// ÉxÅ[ÉXÇí‚é~íÜÇÃäGÇ…Ç∑ÇÈ
				pp->xmoff = pp->xboff ;					// É}ÉXÉNÇí‚é~íÜÇÃäGÇ…Ç∑ÇÈ
			}
			else
			{
				pp->dspf = pp->pchg[0] & 1 ;
			}
		}
	}
}

/*______________________________________________________*/
/*		9	 ÉGÉlÉ~Å[ éÄÇÒÇæÇ∆Ç´ÇÃèâä˙ÉZÉbÉg			*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeIOut( void )
{
	pp->dspf = 1 ;
	pp->yspd = -10.0 ;									// Yspeed Çèâä˙âªÇ∑ÇÈ
	pp->xboff = 80 * 11 ;								// ÉxÅ[ÉXÇóéâ∫íÜÇÃäGÇ…Ç∑ÇÈ
	pp->xmoff = 80 * 11 ;								// É}ÉXÉNÇóéâ∫íÜÇÃäGÇ…Ç∑ÇÈ

	pp->mode = 10 ;										// ÉÇÅ[ÉhÇÉWÉÉÉìÉvíÜÇ÷

}

/*______________________________________________________*/
/*		10		  ÉGÉlÉ~Å[ éÄÇÒÇæÇ∆Ç´					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeOut( void )
{
	pp->yspd += 1.0 ;
	pp->yp += pp->yspd ;

}

/*______________________________________________________*/
/*		11		  Å@ ÉGÉlÉ~Å[ óéâ∫íÜ					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void AeIDown( void )
{
	pp->yspd = 0 ;										// Yspeed Çèâä˙âªÇ∑ÇÈ
	pp->xboff = 720 ;									// ÉxÅ[ÉXÇóéâ∫íÜÇÃäGÇ…Ç∑ÇÈ
	pp->xmoff = 720 ;									// É}ÉXÉNÇóéâ∫íÜÇÃäGÇ…Ç∑ÇÈ

	pp->mode = 4 ;										// ÉÇÅ[ÉhÇÉWÉÉÉìÉvíÜÇ÷

}



TBLJP ActETbl[ ] =
{
	AeInit ,											// 0  :	èâä˙ÉZÉbÉg
	AeStop ,											// 1  : í‚é~íÜ
	AeWalk ,											// 2  : ï‡Ç´íÜ
	AeIJump ,											// 3  : ÉWÉÉÉìÉvèâä˙ÉZÉbÉg
	AeJump ,											// 4  : ÉWÉÉÉìÉvíÜ
	AeIAttack ,											// 5  : çUåÇÇÃèâä˙ÉZÉbÉg
	AeAttack ,											// 6  : çUåÇíÜ
	AeIDamege ,											// 7  : É_ÉÅÅ[ÉWèâä˙ÉZÉbÉg
	AeDamege ,											// 8  : É_ÉÅÅ[ÉWéÛÇØÇÈ
	AeIOut ,											// 9  : éÄñSèâä˙ÉZÉbÉg
	AeOut ,												// 10 : éÄñS
	AeIDown ,											// 11 : óéâ∫èâä˙ÉZÉbÉg
	AeIJump ,											// 12 : í èÌéûÇ‚ÇÁÇÍ èâä˙ÉZÉbÉg
	AeJump ,											// 13 : í èÌéûÇ‚ÇÁÇÍ
} ;

/*______________________________________________________*/
/*				    ÉGÉlÉ~Å[ÇÃÉAÉNÉVÉáÉì				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActEnemy( void )
{
	ActETbl[pp->mode]( ) ;								// ÉGÉlÉ~Å[ÇÃÉAÉNÉVÉáÉìÇÃÉeÅ[ÉuÉãÉWÉÉÉìÉv

	if ( pp->lrflg == 0 )								// ç∂Çå¸Ç¢Çƒ (ì¸óÕ) Ç¢ÇÈÇ∆Ç´
	{
		pp->idx = 6 ;									// ç∂å¸Ç´ÇÃâÊëúÇ…ïœÇ¶ÇÈ
	}
	else												// âEÇå¸Ç¢Çƒ (ì¸óÕ) Ç¢ÇÈÇ∆Ç´
	{
		pp->idx = 7 ;									// ç∂å¸Ç´ÇÃâÊëúÇ…ïœÇ¶ÇÈ
	}

	/*
		ï‡Ç¢ÇƒÇ¢ÇÈÇ∆Ç´
	*/
	pp->pchg[0]-- ;										// É^ÉCÉ}Å[ÇÉJÉEÉìÉgÉ_ÉEÉì
	if ( (pp->pchg[0] <= 0) && (pp->mode != 4)			// É^ÉCÉ}Å[ÇÃÉJÉEÉìÉgÇ™ 0à»â∫Ç…Ç»Ç¡ÇΩÇÁ
			&& (pp->mode != 13) )
	{
		pp->pchg[0] = 2 ;								// ÉAÉjÉÅÅ[ÉVÉáÉìÇÃÉ^ÉCÉ}Å[ÉZÉbÉg
		pp->pchg[1]++ ;									// éüÇÃÉCÉâÉXÉgÇ…à⁄ÇÈ
		if ( pp->pchg[1] >= 4 )							// ÉAÉjÉÅÅ[ÉVÉáÉìÇ™èIÇÌÇ¡ÇΩÇÁ
		{
			pp->pchg[1] = 0 ;							// ç≈èâÇÃäGÇ…ñﬂÇ∑
		}
		pp->xboff = (pp->pchg[1] * 80) + 320 ;			// ÉxÅ[ÉXÇÃÉCÉâÉXÉgÇÃà íuÇì¸ÇÍÇÈ
		pp->xmoff = (pp->pchg[1] * 80) + 320 ;			// É}ÉXÉNÇÃÉCÉâÉXÉgÇÃà íuÇì¸ÇÍÇÈ

	}

}

/*______________________________________________________*/
/*						ÉGÉlÉ~Å[ÇÃÉZÉbÉg				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void EnemySet( void )
{
	int y , x ;
	int i ;

	i = 0 ;												// i ÇÃèâä˙ÉZÉbÉg
	for ( y = 0 ; y < 18 ; y++ )
	{
		for ( x = 0 ; x < 25 ; x++ )
		{
			if ( map[y][x] == 8 )						// å©ÇƒÇÈ MAP ÇÃç¿ïWÇ…âΩÇ©ì¸Ç¡ÇƒÇ¢ÇÈÇ∆Ç´
			{
				obj[O_ENE+i].idno = ID_ENE ;			// ÇªÇÃèÍèäÇ…ÉGÉlÉ~Å[Çì¸ÇÍÇÈ
				obj[O_ENE+i].mode = 0 ;					// MODE Çèâä˙ÉZÉbÉgÇ…Ç∑ÇÈ

				obj[O_ENE+i].xp = x * 32 ;				// X ç¿ïWÇçáÇÌÇπÇÈ
				obj[O_ENE+i].yp = y * 32 + 32 ;			// Y ç¿ïWÇçáÇÌÇπÇÈ

				i++ ;									// i ÇÉCÉìÉNÉäÉÅÉìÉg	éüÇÃÉGÉlÉ~Å[Çå©ÇÈÇΩÇﬂ
			}
		}
	}

}


