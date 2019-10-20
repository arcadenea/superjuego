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

#include "render.h"

#ifdef TARGET_DREAMCAST

#else
SDL_Surface *screen;
#endif
int screen_width,screen_height;
int vertindex;

pvr_init_params_t params = {
	/* Enable opaque and translucent polygons with size 16 */
	{ PVR_BINSIZE_16, PVR_BINSIZE_0, PVR_BINSIZE_16, PVR_BINSIZE_0, PVR_BINSIZE_0 },
	
	/* Vertex buffer size 512K */
	512*1024
};


void SE_screen_fullscreen(int fs)
{

//	if(fs) SDL_WM_ToggleFullScreen(screen);

}


int SE_screen_init(int width,int height,int bpp)
{

	//hack, inicializar bien, "como se debe"
	//pvr_init_defaults();
	
	vid_set_mode(DM_640x480_VGA, PM_RGB565);
	if (pvr_init(&params) < 0)
		return -1;

	screen_width=width;
	screen_height=height;

	//
	//pvr_init_defaults();


	// Setup the frame COMENTADO TEMPORALMENTE O SINO NO ARRANCA EL LXDREAM
	//pvr_wait_ready();

//	pvr_scene_begin();
	/*pvr_list_begin(PVR_LIST_OP_POLY);
	pvr_list_finish();
	pvr_list_begin(PVR_LIST_PT_POLY);
	pvr_list_finish();*/
//	pvr_list_begin(PVR_LIST_TR_POLY);
	

	/* Init matrices */
//	plx_mat3d_init();                    /* Clear internal to an identity matrix */
//	plx_mat3d_mode(PLX_MAT_PROJECTION);  /** Projection (frustum, screenview) matrix */
//	plx_mat3d_identity();                /** Load an identity matrix */
//	plx_mat3d_perspective(45.0f, 640.0f / 480.0f, 100.0f, 0.1f);  // (float angle, float aspect, float znear, float zfar);
//	plx_mat3d_mode(PLX_MAT_MODELVIEW);   /** Modelview (rotate, scale) matrix */
	

	/*internal vertex buffer*/
    vertices=(SE_nodo *)malloc(sizeof(SE_nodo)*1000);
	vertindex=0;
	
	return 1;
	
}

void SE_screen_enable2d()							
{
			
}

void SE_screen_disable2d()							
{
						
}




void SE_screen_clear(float r,float g,float b,float a)
{
	pvr_set_bg_color(r,g,b);
}



void SE_screen_flip()
{

//	SDL_GL_SwapBuffers();/*flipea la escena*/

}

void SE_screen_rotate(float rotx,float roty,float rotz,float pointx,float pointy,float pointz)
{

/*	glLoadIdentity();

	glTranslatef(pointx,pointy,pointz);
	glRotatef(rotx,1,0,0);
	glRotatef(roty,0,1,0);
	glRotatef(rotz,0,0,1);
	glTranslatef(-pointx,-pointy,-pointz);*/



} 

void SE_screen_scale(float zoomx,float zoomy,float zoomz)
{
	
	
//	glScalef(zoomx,zoomy,zoomz);


}

void SE_screen_resettransform()
{

//	glLoadIdentity();

}





