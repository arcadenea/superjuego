#include "game.h"

int coll = 0;

int collision_player_tilemap(S_player *pl, SE_tilemap *tm)
{

	//int SE_tilemap_collision(SE_tilemap *tm,float tm_posx,float tm_posy,SE_box *box,float box_posx,float box_posy);
	coll = SE_tilemap_collision(tm, pl->x, pl->y, pl->p_spr->box, pl->p_spr->box->x, pl->p_spr->box->y);

	if(coll > 0)
	{
		return 1;
	}

	return 0;	

}


