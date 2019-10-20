#include "render.h"


SDL_Surface *screen;

int screen_width,screen_height;


void SE_screen_fullscreen(int fs)
{

	if(fs) SDL_WM_ToggleFullScreen(screen);

}

int SE_screen_init(int width,int height,int bpp)
{


	screen_width=width;
	screen_height=height;

  SDL_Init(SDL_INIT_VIDEO);

  screen = SDL_SetVideoMode(screen_width, screen_height, 16, SDL_OPENGL|SDL_RESIZABLE);
  if ( ! screen ) {
    fprintf(stderr, "Couldn't set GL video mode: %s\n", SDL_GetError());
    SDL_Quit();
    exit(2);
  }
  SDL_WM_SetCaption("Gears", "gears");


/*	if((SDL_Init( SDL_INIT_VIDEO )) < 0 )
	{
		printf("SE_screen:Error, no se puede inicializar el subsistema de video\n");
		return 0;
	}
	

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	
	if((screen = SDL_SetVideoMode(screen_width,screen_height,bpp,SDL_OPENGL)) < 0)
	{
		printf("SE_screen:Error, resolución %dx%dx%d no soportada\n",screen_width,screen_height,bpp);
		return 0;
	}*/

/*	glViewport(0, 0, screenWidth, screenHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0f, screenWidth, 0.0f, screenHeight, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);

	 glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	 glDisable(GL_DEPTH_TEST);*/

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

//	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glEnable( GL_TEXTURE_2D );


	glDisable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glBlendFunc( GL_SRC_ALPHA, GL_ONE );

	

	glViewport( 0, 0, screen_width, screen_height);
	
	//glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

	SE_screen_enable2d();

	return 1;
	
}

void SE_screen_enable2d()							
{

	glMatrixMode(GL_PROJECTION);				
	glPushMatrix();							
	glLoadIdentity();						
	glOrtho(0, screen_width, screen_height, 0, -100000, 100000);				
	glMatrixMode(GL_MODELVIEW);					
	glPushMatrix();							
	glLoadIdentity();

	
				
}

void SE_screen_disable2d()							
{
	glMatrixMode( GL_PROJECTION );					
	glPopMatrix();							
	glMatrixMode( GL_MODELVIEW );					
	glPopMatrix();					
}




void SE_screen_clear(float r,float g,float b,float a)
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glClearColor(r,g,b,a);

}



void SE_screen_flip()
{


	SDL_GL_SwapBuffers();

	SE_image_resetcounter();




}

void SE_screen_rotate(float rotx,float roty,float rotz,float pointx,float pointy,float pointz)
{

	glLoadIdentity();

	glTranslatef(pointx,pointy,pointz);
	glRotatef(rotx,1,0,0);
	glRotatef(roty,0,1,0);
	glRotatef(rotz,0,0,1);
	glTranslatef(-pointx,-pointy,-pointz);



} 

void SE_screen_scale(float zoomx,float zoomy,float zoomz)
{
	
	
	glScalef(zoomx,zoomy,zoomz);


}

void SE_screen_resettransform()
{

	glLoadIdentity();

}


