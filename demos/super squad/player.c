#include "player.h"


int velx = 0; 
int ciclos_joy = 0;
int flag_anim = 0;
int gravity = 9;

S_player *S_create_player(const char *path)
{
	
	S_player *pl;
	pl = (S_player*)malloc(sizeof(S_player));
	pl->w = 0;
	pl->h = 0;
	pl->x = 0;
	pl->y = 0;
	pl->z = 0;
	pl->state = 0;
	pl->nlives = 0;
	pl->score = 0;

	SE_image *tmp_img;
	SE_ani *tmp_anim;
	SE_sprite *tmp_spr;

	FILE *arch;
	char line[200];
	char tag[20];
	char value[180];
	int v;
	int box[4];

	int tex_w, tex_h;//dimensiones de la textura
	int nimg_x, nimg_y;//numero de imagenes en x e y en la textura
	
	arch = fopen(path,"r");

	while(!feof(arch))
	{
		
		fgets(line, 200, arch);
		
		sscanf(line,"%[^ =]%*[ =]%[^=\n]",tag,value);
			
		/*printf("%s",tag);*/
		v = atoi(value);
		/*printf("%d",v);*/

		if(strcmp(tag,"PLAYER_TYPE") == 0)
		{
			printf("%s",tag);

			printf("%s",value);

			if(strcmp(value,"JESSICA") == 0)
			{
				printf("%s",value);
				pl->p_type = 0;
			}else if(strcmp(value,"KIKO") == 0){
				printf("%s",value);
				pl->p_type = 1;
			}
			printf("%d",pl->p_type);
		}
		
		if(strcmp(tag,"PLAYER_W") == 0) pl->w = v;
		if(strcmp(tag,"PLAYER_H") == 0) pl->h = v;
		if(strcmp(tag,"TEXT_W") == 0) tex_w = v;
		if(strcmp(tag,"TEXT_H") == 0) tex_h = v;
		if(strcmp(tag,"FRAME_X") == 0) nimg_x = v;
		if(strcmp(tag,"FRAME_Y") == 0) nimg_y = v;
		if(strcmp(tag,"INIT_X") == 0) pl->x = v;
		if(strcmp(tag,"INIT_Y") == 0) pl->y = v;
		if(strcmp(tag,"INIT_Z") == 0) pl->y = v;
		if(strcmp(tag,"IMG_PATH") == 0) strcpy(pl->img_path, value);
		if(strcmp(tag,"N_FRAMES") == 0) pl->numframes = v;
		if(strcmp(tag,"DELAY") == 0) pl->delay = v;
		if(strcmp(tag,"STAND_IFR") == 0) pl->anim[0] = v;
		if(strcmp(tag,"STAND_EFR") == 0) pl->anim[1] = v;
		if(strcmp(tag,"WALK_IFR") == 0) pl->anim[2] = v;
		if(strcmp(tag,"WALK_EFR") == 0) pl->anim[3] = v;
		if(strcmp(tag,"JUMP_IFR") == 0) pl->anim[4] = v;
		if(strcmp(tag,"JUMP_EFR") == 0) pl->anim[5] = v;
		if(strcmp(tag,"DEAD_IFR") == 0) pl->anim[6] = v;
		if(strcmp(tag,"DEAD_EFR") == 0) pl->anim[7] = v;
		if(strcmp(tag,"WIN_IFR") == 0) pl->anim[8] = v;
		if(strcmp(tag,"WIN_EFR") == 0) pl->anim[9] = v;
		if(strcmp(tag,"BOX_X") == 0) box[0] = v;
		if(strcmp(tag,"BOX_Y") == 0) box[1] = v;
		if(strcmp(tag,"BOX_W") == 0) box[2] = v;
		if(strcmp(tag,"BOX_H") == 0) box[3] = v;																																																																																																																

		v = 0;
		memset(line,0,200);
		memset(tag,0,20);
		memset(value,0,180);
	
	}

	fclose(arch);

	tmp_img = SE_image_load(pl->img_path);
	pl->p_img = tmp_img;
	tmp_anim = SE_ani_init(pl->w, pl->h, pl->numframes);
	SE_ani_create_from_img(tmp_anim, tmp_img, nimg_x, nimg_y, pl->delay);
	pl->p_anim = tmp_anim;
 	tmp_spr = SE_sprite_init(ANI);
	SE_sprite_ani_add(tmp_spr, tmp_anim);	
	SE_sprite_box_init(tmp_spr,1);
	SE_sprite_box_set(tmp_spr,0,box[0],box[1],box[2],box[3]);
	pl->p_spr = tmp_spr;


}

void S_player_action_set(S_player *pl, int action)
{

	switch(action){
	case A_STAND: 
		SE_animator_initend_set(pl->p_spr->ator, pl->anim[0], pl->anim[1]);
		break;
	case A_WALK: 	
		SE_animator_initend_set(pl->p_spr->ator, pl->anim[2], pl->anim[3]);
		break;
	case A_JUMP: 
		SE_animator_initend_set(pl->p_spr->ator, pl->anim[4], pl->anim[5]);
		break;
	case A_DEAD: 
		SE_animator_initend_set(pl->p_spr->ator, pl->anim[6], pl->anim[7]);
		break;
	case A_WIN: 
		SE_animator_initend_set(pl->p_spr->ator, pl->anim[8], pl->anim[9]);
		break;
	default: 
		SE_animator_initend_set(pl->p_spr->ator, pl->anim[0], pl->anim[1]);
	}
}

void S_draw_player(S_player *pl)
{

	SE_sprite_draw(pl->p_spr, pl->x, pl->y, pl->z);

}



int S_move_player(S_player *pl, SE_input_state *st, SE_input_joystick *joy)
{

	if(st=SE_input_poll(&joy))
	{

		if(st->buttons & JOY_LEFT) 
		{
			velx = -5;
			if(flag_anim == 0)
			{
				flag_anim = 1;
				S_player_action_set(pl, A_WALK);
			}
		}

		if(st->buttons & JOY_RIGHT) 
		{
			velx = 5;
			if(flag_anim == 0)
			{
				flag_anim = 1;
				S_player_action_set(pl, A_WALK);
			}
		}

		if (!(st->buttons & JOY_LEFT) && !(st->buttons & JOY_RIGHT))
		{
			velx = 0;
			if(flag_anim == 1)
			{
				flag_anim = 0;
				S_player_action_set(pl, A_STAND);
			}
			
		}

		if(st->buttons & SE_QUIT){
			return 1;
		} 

		pl->x += velx; 

	}

	return 0;	

}

void S_clean_player(S_player *pl)
{

		SE_sprite_clean(pl->p_spr);
		SE_ani_clean(pl->p_anim);
		SE_image_clean(pl->p_img);
		free(pl);

}
