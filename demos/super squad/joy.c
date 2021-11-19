#include "joy.h"


SDL_Event event;
Uint8 *keys;


S_joystick *S_create_joystick()
{

	S_joystick *j;
	j = (S_joystick*)malloc(sizeof(S_joystick));
	j->button_left = FALSE;
	j->button_right = FALSE;
	j->button_1 = FALSE;
	j->button_2 = FALSE; 
	j->button_3 = FALSE;

}

void S_manage_keys(S_joystick *joy)
{
	
	while( SDL_PollEvent( &event ) )
	{
        switch( event.type )
		{
            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
                    case SDLK_LEFT:
                        joy->button_left = TRUE;
                        break;
                    case SDLK_RIGHT:
                        joy->button_right = TRUE;
                        break;
                    default:
                        break;
                }
                break;
            
            case SDL_KEYUP:
                switch( event.key.keysym.sym ){
                    case SDLK_LEFT:
                        joy->button_left = FALSE;
                        break;
                    case SDLK_RIGHT:
                        joy->button_right = FALSE;
                        break;
                    default:
                        break;
                }
                break;
           

            default:
                break;

			
        }
    }



}
