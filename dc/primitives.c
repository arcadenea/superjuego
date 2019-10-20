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

#include "primitives.h"




void SE_prim_drawpoint(float x,float y,float z,float red,float green,float blue,float alpha)
{
/*	glPushMatrix();

	glDisable( GL_TEXTURE_2D );

	glColor4f(red,green,blue,alpha);
	glBegin(GL_POINTS);
		glVertex3f(x,y,z);
	glEnd();

	glPopMatrix();*/

}

void SE_prim_drawline(float x1,float y1,float x2,float y2,float red,float green,float blue,float alpha)
{


/*	glPushMatrix();

	glDisable( GL_TEXTURE_2D );

	glColor4f(red,green,blue,alpha);
	glBegin(GL_LINES);
		glVertex2f(x1,y1); 
		glVertex2f(x2,y2);
	glEnd();

	glPopMatrix();*/

}

void SE_prim_drawrectangle(float x,float y,float z,float width,float height,int fill,float red,float green,float blue,float alpha)
{

/*	glPushMatrix();

	glDisable( GL_TEXTURE_2D );

	glTranslatef(x,y,z);
	glColor4f(red,green,blue,alpha);
	if(fill == 0)
	{
		glBegin(GL_LINE_LOOP);
	}else{
		glBegin(GL_QUADS);
	}
		glVertex2f(0,0);    
		glVertex2f(width,0);
		glVertex2f(width,height);
		glVertex2f(0,height);
	glEnd();



	glPopMatrix();*/



}

void SE_prim_drawcircle(float x,float y,float z,float radius,int sections,int fill,float red,float green,float blue,float alpha)
{

/*	glPushMatrix();

	glDisable( GL_TEXTURE_2D );

	int i;
	float twoPi = 2.0f * 3.14159f;
	glTranslatef(x,y,z);
	glColor4f(red,green,blue,alpha);
	if(fill == 0)
	{
		glBegin(GL_LINE_LOOP);
	}else{	
		glBegin(GL_TRIANGLE_FAN);
	}
	glVertex2f(0,0); 
	for(i = 0; i <= sections;i++) 
	{ 
		glVertex2f(radius * cos(i *  twoPi / sections), 
		radius* sin(i * twoPi / sections));
	}
	glEnd();


	glPopMatrix();*/

}




