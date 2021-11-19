#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <SDL/SDL.h>
#include "super.h"
//#include "joy.h"

#define JESSICA 0
#define KIKO 1

//ANIMATIONS
#define A_STAND 0
#define A_WALK 1
#define A_JUMP 2
#define A_DEAD 3
#define A_WIN 4

//PLAYER STATES
#define STAND 10
#define WALK_LEFT 11
#define WALK_RIGHT 12
#define JUMP 13
#define DEAD 14
#define WIN 15

//LOOK
#define LOOK_RIGHT 0
#define LOOK_LEFT 1 



typedef struct{

	int p_type;//puede ser JESSICA o KIKO
	int w,h;//ancho y alto de sprite de player
	float x,y,z;//posicion player
	int numframes;//cantidad de frames de animacion
	int delay;//delay de animacion
	char img_path[200];
	SE_image *p_img;//imagen de player con frames de animacion
	SE_ani *p_anim;//animacion de player
	SE_sprite *p_spr;//sprite de player	
	int state;//estado de player	
	int look;//hacia donde está mirando
	int nlives;//numero de vidas
	int score;//puntuacion
	int anim[10];/*array de animaciones 0:stand initial frame
										1:stand end frame
 										2:walk initial frame
										3:walk end frame
										4:jump initial frame
										5:jump end frame
										6:dead initial frame
										7:dead end frame
										8:win initial frame
										9:win end frame*/
	
}S_player;

S_player *S_create_player(const char *path);//crea el player

void S_player_action_set(S_player *pl, int action);//setea la accion: STAND, WALK, JUMP, DEAD, WIN

int S_move_player(S_player *pl, SE_input_state *st, SE_input_joystick *joy);

void S_draw_player(S_player *pl);//dibuja player

void S_clean_player(S_player *pl);




















#endif
