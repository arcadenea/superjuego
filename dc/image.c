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

#include "image.h"


GLuint loadTexture(SDL_Surface *surface)
{


}


SE_image *SE_image_load(char *path)
{

	SE_image *img;
	int flags=0;
	int fnlen;

	printf("Cargando textura: %s\n",path);

	//plx_texture_t * txr;
	img = (SE_image*)malloc(sizeof(SE_image));
	
	fnlen = strlen(path);
	if (!strcasecmp(path + fnlen - 3, "kmg")) {
	
	flags=PVR_TXRLOAD_FMT_VQ|PVR_TXRLOAD_FMT_TWIDDLED;

	}
	img->texture = plx_txr_load(path, 1, flags);
	if (!img->texture)
		printf("no se pudo cargar la textura\n");

	
//	img->texture = txr;//loadTexture(temp);

	img->w = img->texture->w;
	img->h = img->texture->h;
	
	img->x = 0;
	img->y = 0;
//	img->z = 0;

	
/*	img->rotx = 0;
/	img->roty = 0;
	img->rotz = 0;

	img->r = 1.0;
	img->g = 1.0;
	img->b = 1.0;

	img->alpha = 1.0;*/
	
			//printf("x: %d\ny: %d\nancho: %d\nalto: %d\n",img->x,img->y,img->w,img->h);

	//SDL_FreeSurface(temp);
	return img;	

}




int SE_image_width(SE_image *img)
{

	return img->w;/*devuelve el ancho de la imagen*/

}

int SE_image_height(SE_image *img)
{

	return img->h;/*devuelve el alto de la imagen*/

}


void SE_image_segment_draw(SE_image *img,float xtex,float ytex,float wtex,float htex,float posx,float posy,float posz,
	float width_image,float height_image,float zoomx,float zoomy,float rotx,float roty,float rotz,
	float r,float g,float b,float alpha)
{

/*	float width = width_image * zoomx;
	float height = height_image * zoomy;

	float w = img->w;
	float h = img->h;


	if(w == 0)w = 1;
	if(h == 0)h = 1;


	float x1 = xtex/w;
	float y1 = ytex/h;
	float x2 = (xtex + wtex)/w;
	float y2 = (ytex + htex)/h;

	glPushMatrix();	

	glEnable( GL_TEXTURE_2D );		

	glTranslatef(width/2 ,height/2,posz);
	glTranslatef(posx,posy,posz);
	glRotatef(rotx,1,0,0);
	glRotatef(roty,0,1,0);
	glRotatef(rotz,0,0,1);

	glTranslatef(-width/2,-height/2,posz);




	glColor4f(r,g,b,alpha);
		
	glBindTexture(GL_TEXTURE_2D,img->texture);

	glBegin(GL_QUADS);

		glTexCoord2f(x1,y1);
		glVertex2f(0,0);    

		glTexCoord2f(x2,y1);
		glVertex2f(width,0);

		glTexCoord2f(x2,y2);
		glVertex2f(width,height);
    
		glTexCoord2f(x1,y2);
		glVertex2f(0,height);
	glEnd();


	glPopMatrix();

	SE_utils_logvertices(4);*/

}

void SE_image_full_draw(SE_image *img,float posx,float posy,float posz,float width_image,float height_image,
	float zoomx,float zoomy,float rotx,float roty,float rotz,float r,float g,float b,float alpha)
{
	

	SE_image_segment_draw(img,0,0,img->w,img->h,posx,posy,posz,width_image,height_image,zoomx,zoomy,rotx,roty,rotz,r,g,b,alpha);

}

void SE_image_draw(SE_image *img,float posx,float posy,float posz)
{

	SE_image_full_draw(img,posx,posy,posz,img->w,img->h,1,1,0,0,0,1,1,1,1);

}

void SE_image_clean(SE_image *img)
{

	free(img);
	if(img != 0)
	{
		printf("SE_screen:Error, no se pudo borrar puntero de imagen\n");
	}
	

}

