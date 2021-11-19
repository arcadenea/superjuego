#ifndef JOY_H_
#define JOY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include "super.h"

#define TRUE 1
#define FALSE 0



typedef struct{

	int button_left;
	int button_right;
	int button_1;
	int button_2; 
	int button_3;

}S_joystick;

S_joystick *S_create_joystick();

void S_manage_keys(S_joystick *joy);

















#endif
