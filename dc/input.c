/*
    Superjuego Engine
    Copyright (C) 2011 Jorge Luís Cabral y Gabriel Ernesto Cabral

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Contact: baigosoft@hotmail.com
*/


#include "input.h"

cont_state_t *state; //kos input struct
SE_input_state internal_input_state;

/*init input subsystem*/
int SE_input_init()
{

	SE_input_state internal_input_state;
	//seems like no input init is needed in kos
	return 1;

}

/*abrir joystick*/
SE_input_joystick *SE_input_open(int joyid)
{
	maple_device_t *cont;
	cont = maple_enum_type(joyid, MAPLE_FUNC_CONTROLLER);

	if (cont) {
        	return cont;
	}else{
		return 0;
	}

}

/*enumera la cantidad de joysticks disponibles
"prestado" del SDL de dreamcast*/
int SE_input_enum()
{
	int numdevs;
	int i;

	numdevs = 0;
	//Update KOS Maple
	int n = maple_enum_count();
	for (i=0;i<n;i++){
		maple_device_t *cont = maple_enum_type(i, MAPLE_FUNC_CONTROLLER);
		if (cont){
			//SYS_Joystick_addr[numdevs] = cont;
			numdevs++;
		}
	}
	return(numdevs);
}


SE_input_state *SE_input_poll(SE_input_joystick *joy)
{

	joy = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

	if (joy) {
		state = (cont_state_t *)maple_dev_status(joy);
		if (!state)
		    return 0;

		internal_input_state.buttons=state->buttons;
		
    	}
	return &internal_input_state;
}
