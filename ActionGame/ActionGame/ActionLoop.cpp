/*______________________________________________________________________________________________________________*/
/*																												*/
/*												アクションループ												*/
/*______________________________________________________________________________________________________________*/

#include <windows.h>
#include "Def.h"
#include "Work.h"


/*______________________________________________________*/
/*						何もしない関数					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActNull( void ){		}

TBLJP ActJpTbl[ ] = {
	ActNull ,											//  00 : 
	ActTitle ,											//  01 : タイトルのアクション
	ActStart ,											//  02 : スタートのアクション
	ActNull ,											//  03 : 
	ActBg ,												//  04 : 背景のアクション
	ActNull ,											//  05 : 
	ActPlayer ,											//  06 : プレイヤーのアクション
	ActNull ,											//  07 : 
	ActEnemy ,											//  08 : エネミーのアクション
	ActNull ,											//  09 : 
	ActHole ,											//  10 : 土管のアクション
	ActNull ,											//  11 : 
	ActAttack ,											//  12 : 攻撃時
	ActStep ,											//  13 : 着地のアクション
	ActBoo ,											//  14 : 煙のアクション
	ActSnow ,											//  15 : 雪のアクション
	ActBomb ,											//  16 : 爆発のアクション
	ActSBom ,											//  17 : 
} ;

/*______________________________________________________*/
/*					  アクションループ					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActionLoop( void )
{
	int i ;

	for ( i = 0 ; i < MAXOBJ ; i++ )					// オブジェクトを全部見る
	{
		if ( obj[i].idno != 0 )							// obj[] に何か入っているとき
		{
			pp = &obj[i] ;								// ポインタに入れる
			ActJpTbl[ pp->idno ]( ) ;					// テーブルジャンプする
		}
	}

	for ( i = 0 ; i < MAXBLK ; i++ )					// 全部のブロックを見る
	{
		if ( blk[i].idno != 0 )							// blk[] に何か入っているとき
		{
			bp = &blk[i] ;								// ポインタに入れる
			ActBlock( ) ;								// ブロックアクションの関数へ行く
		}
	}
}



