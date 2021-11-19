#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "super.h"
#include "player.h"

SE_input_state *state;
SE_input_joystick *joystick;

int quit = 0;

S_player *js;

/*jessica*/
SE_image *j_img;
SE_ani *j_anim;
SE_sprite *j_spr;

/*robot*/
SE_image *r_img;
SE_ani *r_anim;
SE_sprite *r_spr;

/*tilemap*/
SE_image *s_tile;
SE_tileset *s_tset;
SE_tilemap *s_tmap;

/*fondo*/
SE_image *fondo_img;


void cargarcosas()
{
		
	js = S_create_player("data/jessica.txt");
	S_player_action_set(js, STAND);
				
	/*jessica*/	
	/*j_img = SE_image_load("jessica480.png");
	j_anim = SE_ani_init(32, 64, 8);
	SE_ani_create_from_img(j_anim, j_img, 4, 2, 10);
 	j_spr = SE_sprite_init(ANI);
	SE_sprite_ani_add(j_spr, j_anim);
	SE_animator_initend_set(j_spr->ator, 0, 2);
	SE_sprite_box_init(j_spr,1);
	SE_sprite_box_set(j_spr,0,0,0,32,64);*/

	/*robot*/
	r_img = SE_image_load("robot.png");
	r_anim = SE_ani_init(64, 64, 2);
	SE_ani_create_from_img(r_anim, r_img, 2, 1, 4);
 	r_spr = SE_sprite_init(ANI);
	SE_sprite_ani_add(r_spr, r_anim);
	SE_animator_initend_set(r_spr->ator, 0, 1);
	SE_sprite_box_init(r_spr, 1);
	SE_sprite_box_set(r_spr,0,0,0,64,64);

	/*tilemap*/
	s_tile = SE_image_load("data/tiles.png");
	s_tset = SE_tileset_init(2, 32, 32);
	SE_tileset_img_segment_add(s_tset, s_tile, 0, 0, 0);
	SE_tileset_img_segment_add(s_tset, s_tile, 1, 32, 0);

	s_tmap = SE_tilemap_init(s_tset, 2, 32, 32, 40, 22);

	SE_tilemap_maptile_load(s_tmap, "data/tilemap720.txt");

	/*fondo*/
	fondo_img = SE_image_load("data/fondo720.png");

}






int main(int argc,char* args[])
{
	quit = 0;

	int ciclos = 0;

	SE_screen_init(1280,720,32);

	/*seteamos el framerate a 60 cuadros*/
	SE_timer_setframerate(30); 

	/*llamamos a la funcion cargarsprites()*/
	cargarcosas();

	//S_joystick *joystick1;

	//joystick1 = S_create_joystick();	

	//SDL_EnableKeyRepeat( SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL );


	/*inicializamos el sistema de Input*/
	SE_input_init();
	printf("hay %d joysticks disponibles\n",SE_input_enum());
	joystick = SE_input_open(0);
	
	while(quit == 0)
	{
		
			//printf("%d\n",js->p_type);			

			/*limpiamos la pantalla con un color*/
			SE_screen_clear(1,1,1,1);

			SE_image_draw(fondo_img, 0, 0, 0);

			SE_tilemap_draw(s_tmap, 0, 0, 0);			
					
			quit = S_move_player(js, state, joystick);

			S_draw_player(js);

			SE_sprite_draw(r_spr, 300, 100, 0);

			/*flipamos el cuadro*/
			SE_screen_flip();
	
			/*controlamos el framerate con esta funcion*/
			SE_timer_waitframerate();

			

				if(quit == 1)
				{
					//SE_sprite_clean(j_spr);
					//SE_ani_clean(j_anim);
					//SE_image_clean(j_img);
					SE_sprite_clean(r_spr);
					SE_ani_clean(r_anim);
					SE_image_clean(r_img);		
					SE_tilemap_clean(s_tmap);
					SE_tileset_clean(s_tset);
					SE_image_clean(s_tile);
					SE_input_close();
				}
			

			
			
		
	}


return 0;







}
