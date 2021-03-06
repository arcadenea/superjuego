#include <stdio.h>
#include <stdlib.h>
//#include <SDL/SDL.h>
#include "super.h"



SDL_Event event;

/*creamos la estructura para almacenar la imagen*/
SE_image *image00;
SE_image *image01;
SE_image *image02;
SE_image *image03;
SE_image *image04;
SE_image *image05;
SE_image *image06;
SE_image *image07;
SE_image *image08;

/*creamos las animaciones*/
SE_ani *ani00;
SE_ani *ani01;
SE_ani *ani02;
SE_ani *ani03;
SE_ani *ani04;
SE_ani *ani05;
SE_ani *ani06;
SE_ani *ani07;

/*creamos el tileset*/
SE_tileset *tset;

/*creamos el tilemap*/
SE_tilemap *timap;

/*sprite del pinguino*/
SE_image *ipingu;
SE_ani *apingu;
SE_sprite *spingu;

SE_camera *camara;


void cargarcosas()
{

	/*cargamos la imagen en la estructura definida*/
	image00 = SE_image_load("tile00.png");
	image01 = SE_image_load("tile01.png");
	image02 = SE_image_load("tile02.png");
	image03 = SE_image_load("tile03.png");
	image04 = SE_image_load("tile04.png");
	image05 = SE_image_load("tile05.png");
	image06 = SE_image_load("tile06.png");
	image07 = SE_image_load("tile07.png");
	image08 = SE_image_load("tile08.png");

	/*inicializamos las animaciones*/
	ani00 = SE_ani_init(32,32);
	ani01 = SE_ani_init(32,32);
	ani02 = SE_ani_init(32,32);
	ani03 = SE_ani_init(32,32);
	ani04 = SE_ani_init(32,32);
	ani05 = SE_ani_init(32,32);
	ani06 = SE_ani_init(32,32);
	ani07 = SE_ani_init(32,32);
	
	/*cargamos las animaciones con imagenes*/
	SE_ani_addframe(ani00,image00,10);
	SE_ani_addframe(ani01,image01,10);
	SE_ani_addframe(ani02,image02,10);
	SE_ani_addframe(ani03,image03,10);
	SE_ani_addframe(ani04,image04,10);
	SE_ani_addframe(ani05,image05,10);
	SE_ani_addframe(ani06,image06,100);
	SE_ani_addframe(ani06,image07,100);
	SE_ani_addframe(ani07,image08,10);

	/*inicializamos tileset*/
	tset = SE_tileset_init(32,32);

	/*cargamos el tileset con animaciones*/
	SE_tileset_animation_add(tset,ani00);
	SE_tileset_animation_add(tset,ani01);
	SE_tileset_animation_add(tset,ani02);
	SE_tileset_animation_add(tset,ani03);
	SE_tileset_animation_add(tset,ani04);
	SE_tileset_animation_add(tset,ani05);
	SE_tileset_animation_add(tset,ani06);
	SE_tileset_animation_add(tset,ani07);

	/*inicializamos tilemap*/
	timap = SE_tilemap_init(8,32,32,20,15);


	/*cargamos tilemap con el archivo de texto*/
	SE_tilemap_mapimage_load(timap,"mapimage.txt");
	SE_tilemap_mapcoll_bin_load(timap,"mapcoll.map");

	/*cargamos la imagen en la estructura definida*/
	ipingu = SE_image_load("run.png");

	/*iniciamos la animacion, con ancho y alto 128*/
	apingu = SE_ani_init(128,128);

	/*asignamos las imagenes como frames a la animacion*/
	SE_ani_addframe_segment(apingu,ipingu,100,0,0,128,128);
	SE_ani_addframe_segment(apingu,ipingu,100,128,0,128,128);

	/*inicializamos el sprite*/
	spingu = SE_sprite_init(apingu);

	/*agregamos caja de colision a sprite*/
	SE_sprite_box_add(spingu,0,0,128,128);
	
	/*camara*/
	camara = SE_camera_init(0,0,0,0,20,15);


}





int main(int argc,char* args[])
{

	Uint8 *keys;

	/*variable para salir*/
	int quit = 0;


	
	/*inicializamos la pantalla con la resolucion y la cantidad de colores*/
	SE_screen_init(640,480,16);

	/*llamamos a la funcion cargarcosas()*/
	cargarcosas();

	/*posicion del jugador*/
	int playerx = 0;
	int playery = 0;

	int coll = 0;	

	while(quit == 0)
	{
		
			/*limpiamos la pantalla con un color*/
			SE_screen_clear(0,0,0,0);

			//SE_tilemap_draw(timap,tset,playerx,playery,0);

			SE_camera_tilearea_draw(timap,tset,camara,0,0,0);

			SE_sprite_draw_fx(spingu,playerx,playery,0,128,128,1,1,0,0,0,1,1,1,1);

			/*flipamos el cuadro*/
			SE_screen_flip();


			keys=SDL_GetKeyState(NULL);

			if (keys[SDLK_UP]) 
			{
				playery -= 1;
				coll = SE_camera_tilearea_collision(timap,spingu->box,camara,0,0,playerx,playery);
				printf("%d",coll);		
				if(coll > 0)playery += 1;
				coll = 0;
			}
			if (keys[SDLK_DOWN]) 
			{
				playery += 1;
				coll = SE_camera_tilearea_collision(timap,spingu->box,camara,0,0,playerx,playery);		
				if(coll > 0)playery -= 1;
				coll = 0;
			}
			if (keys[SDLK_LEFT]) 
			{
				playerx -= 1;
				coll = SE_camera_tilearea_collision(timap,spingu->box,camara,0,0,playerx,playery);		
				if(coll > 0)playerx += 1;
				coll = 0;
			}
			if (keys[SDLK_RIGHT]) 
			{
				playerx += 1;
				coll = SE_camera_tilearea_collision(timap,spingu->box,camara,0,0,playerx,playery);		
				if(coll > 0)playerx -= 1;
				coll = 0;
			}
			
			/*trocito de codigo de SDL que usamos para detectar si se cierra la ventana*/	
			while( SDL_PollEvent( &event ) )
	        	{
			
				if( event.type == SDL_QUIT )
				{
					quit = 1;
				}
			

			}


			

			
				

			
		
	}

return 0;







}
