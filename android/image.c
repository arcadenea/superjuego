#include "image.h"

int vertindex=0;

uint loadTexture(SDL_Surface *surface)
{

	uint texture;
	int w, h;
	SDL_Surface *image;
	SDL_Rect area;
	Uint32 saved_flags;
	Uint8  saved_alpha;

	/*verifica si el ancho de la imagen es potencia de 2*/
	if(SE_utils_powerof2(surface->w) == 0) 
	{		
		printf("SE_screen: Advertencia, el ancho de la imagen no es potencia de 2\n");
		fflush(stdout);
	}
    	/*verifica si el alto de la imagen es potencia de 2*/
	if(SE_utils_powerof2(surface->h) == 0) 
	{	
		printf("SE_screen: Advertencia, el alto de la imagen no es potencia de 2\n");
		fflush(stdout);
	}
	w = surface->w;
	h = surface->h;
	
	
	image = SDL_CreateRGBSurface(
			SDL_SWSURFACE,
			w, h,
			32,
	#if SDL_BYTEORDER == SDL_LIL_ENDIAN /* OpenGL RGBA masks */
			0x000000FF, 
			0x0000FF00, 
			0x00FF0000, 
			0xFF000000
	#else
			0xFF000000,
			0x00FF0000, 
			0x0000FF00, 
			0x000000FF
	#endif
		       );
	if ( image == NULL ) {
		return 0;
	}

	/* Save the alpha blending attributes */
	saved_flags = surface->flags&(SDL_SRCALPHA|SDL_RLEACCELOK);
	saved_alpha = surface->format->alpha;
	if ( (saved_flags & SDL_SRCALPHA) == SDL_SRCALPHA ) {
		SDL_SetAlpha(surface, 0, 0);
	}

	/* Copy the surface into the GL texture image */
	area.x = 0;
	area.y = 0;
	area.w = surface->w;
	area.h = surface->h;
	SDL_BlitSurface(surface, &area, image, &area);

	/* Restore the alpha blending attributes */
	if ( (saved_flags & SDL_SRCALPHA) == SDL_SRCALPHA ) {
		SDL_SetAlpha(surface, saved_flags, saved_alpha);
	}

	/* Create an OpenGL texture for the image */
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,
		     0,
		     GL_RGBA,
		     w, h,
		     0,
		     GL_RGBA,
		     GL_UNSIGNED_BYTE,
		     image->pixels);
	SDL_FreeSurface(image); /* No longer needed */

	return texture;


}


SE_image *SE_image_load(const char *path)
{
	
	SE_image *img;
	img = (SE_image*)malloc(sizeof(SE_image));
	
	SDL_Surface *temp; 

	printf("SE_image:Cargando textura: %s\n",path);

	if((temp = IMG_Load(path)) == NULL)
	{
		printf("SE_image:Error, no se pudo cargar la imagen\n");
	}
	
	img->texture = loadTexture(temp);

	img->width = temp->w;
	img->height = temp->h;			
	
	SDL_FreeSurface(temp);
	return img;
}

int SE_image_getcounter()
{
	
return vertindex;
}

void SE_image_resetcounter()
{
vertindex=0;
}


void SE_image_segment_draw_fx(SE_image *img,float xtex,float ytex,float wtex,float htex,float posx,float posy,float posz,
	float width_image,float height_image,float zoomx,float zoomy,float rotx,float roty,float rotz,
	float r,float g,float b,float alpha)
{


	float width = wtex * zoomx;
	float height = htex * zoomy;

	float w = img->width;
	float h = img->height;


	if(w == 0)w = 1;
	if(h == 0)h = 1;


	float x1 = xtex/w;
	float y1 = ytex/h;
	float x2 = (xtex + wtex)/w;
	float y2 = (ytex + htex)/h;


//    glEnableClientState(GL_COLOR_ARRAY);

//	glPushMatrix();	

/*	glTranslatef(width/2 ,height/2,posz);
	glTranslatef(posx,posy,posz);
	glRotatef(rotx,1,0,0);
	glRotatef(roty,0,1,0);
	glRotatef(rotz,0,0,1);
	glTranslatef(-width/2,-height/2,posz);*/

/*	//0
	vsprite[vertindex]=x1;
	vsprite[vertindex+1]=y1;
	//1
	vsprite[vertindex+2]=x2;
	vsprite[vertindex+3]=y1;
	//2
	vsprite[vertindex+4]=x2;
	vsprite[vertindex+5]=y2;
	//3
	vsprite[vertindex+6]=x1;
	vsprite[vertindex+7]=y2;


	//0
	tsprite[vertindex]=0.0f;
	tsprite[vertindex+1]=0.0f;
	//1
	tsprite[vertindex+2]=width;
	tsprite[vertindex+3]=0.0f;
	//2
	tsprite[vertindex+4]=width;
	tsprite[vertindex+5]=height;
	//3
	tsprite[vertindex+6]=0.0f;
	tsprite[vertindex+7]=height;*/



	//vert1
/*	vsprite[0] = x1;
	vsprite[1] = y1;

	tsprite[0] = 0;
	tsprite[1] = 0;

	//vert2
	vsprite[2] = x2;
	vsprite[3] = y1;

	tsprite[2] = width;
	tsprite[3] = 0;

	//vert3
	vsprite[4] = x2;
	vsprite[5] = y2;

	tsprite[4] = width;
	tsprite[5] = height;

	//vert4
	vsprite[6] = x1;
	vsprite[7] = y2;

	tsprite[6] = 0;
	tsprite[7] = height;*/

	glEnable(GL_TEXTURE_2D);


/*	GLfloat tsprite[] = { 0.0f, 0.0f,
						  1.0f, 0.0f,
						  1.0f, 1.0f,
						  0.0f, 1.0f };*/

	GLfloat tsprite[] = { x1, y1,
	                      x2, y1,
						  x2, y2,
						  x1, y2 };
/*
		GLfloat vertices[] = { x, screenHeight - y,
							 x, screenHeight - (y + height),
							 x + width, screenHeight - (y + height),
							 x + width, screenHeight - y };

*/

	GLfloat vsprite[] = { posx, posy,
							 posx, (posy + height),
							 posx + width, (posy + height),
							 posx + width, posy };

/*	GLfloat vsprite[] = { posx, 480 - posy,
							 posx, 480 - (posy + height),
							 posx + width, 480 - (posy + height),
							 posx + width, 480 - posy };*/

//	glColor4f(r,g,b,alpha);/*alpha blending*/

//restaurar opengl android
//glEnable(GL_TEXTURE_2D);
/*glActiveTexture(GL_TEXTURE0);
glClientActiveTexture(GL_TEXTURE0);*/
//glBindTexture(GL_TEXTURE_2D, your_texture_id);

		glBindTexture(GL_TEXTURE_2D, img->texture);

//restaurar opengl android
/*glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
glEnable(GL_BLEND);
glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glEnableClientState(GL_COLOR_ARRAY);*/


	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(2, GL_FLOAT, 0, vsprite);
		glTexCoordPointer(2, GL_FLOAT, 0, tsprite);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);


    vertindex=0;


	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

 //   glDisableClientState(GL_COLOR_ARRAY);
		//glDrawArrays(GL_TRIANGLE_FAN, 0, 4); // You may just replace all your GL_QUADS with GL_TRIANGLE_FAN and it will draw absolutely identically with same coordinates, if you have just 4 coords.



	SE_utils_logvertices(4);

}

void SE_image_segment_draw_wh(SE_image *img,float xtex,float ytex,float wtex,float htex,float posx,float posy,float posz,float width,float height)
{

	SE_image_segment_draw_fx(img,xtex,ytex,wtex,htex,posx,posy,posz,width,height,1,1,0,0,0,1,1,1,1);

}


void SE_image_segment_draw(SE_image *img,float xtex,float ytex,float wtex,float htex,float posx,float posy,float posz)
{

	SE_image_segment_draw_fx(img,xtex,ytex,wtex,htex,posx,posy,posz,wtex,htex,1,1,0,0,0,1,1,1,1);

}


void SE_image_draw_fx(SE_image *img,float posx,float posy,float posz,float width_image,float height_image,
	float zoomx,float zoomy,float rotx,float roty,float rotz,float r,float g,float b,float alpha)
{
	

	SE_image_segment_draw_fx(img,0,0,img->width,img->height,posx,posy,posz,width_image,height_image,zoomx,zoomy,rotx,roty,rotz,r,g,b,alpha);

}

void SE_image_draw_wh(SE_image *img,float posx,float posy,float posz,float width,float height)
{

	SE_image_draw_fx(img,posx,posy,posz,width,height,1,1,0,0,0,1,1,1,1);

}

void SE_image_draw(SE_image *img,float posx,float posy,float posz)
{

	SE_image_draw_fx(img,posx,posy,posz,img->width,img->height,1,1,0,0,0,1,1,1,1);

}

void SE_image_segment_draw_transf(SE_image *img,SE_transf *tr,float xtex,float ytex,float wtex,float htex)
{

	SE_image_segment_draw_fx(img,
							 xtex,ytex,wtex,htex,
							 tr->x,tr->y,tr->z,
							 tr->width,tr->height,
							 tr->zoomx,tr->zoomy,
							 tr->rotx,tr->roty,tr->rotz,
							 tr->r,tr->g,tr->b,
							 tr->alpha);

}

void SE_image_draw_transf(SE_image *img,SE_transf *tr)
{

	SE_image_draw_fx(img,
					 tr->x,tr->y,tr->z,
					 tr->width,tr->height,
					 tr->zoomx,tr->zoomy,
					 tr->rotx,tr->roty,tr->rotz,
					 tr->r,tr->g,tr->b,
					 tr->alpha);

}

void SE_image_clean(SE_image *img)
{

	free(img);
	printf("SE_image:se elimino puntero de imagen\n");
	
}

