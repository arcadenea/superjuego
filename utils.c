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

#include "utils.h"

int SE_utils_powerof2(int number)
{

	if(number & (number-1) != 0)
	{
		return 0;
	}else{
		return 1;
	}
	
}


void SE_utils_log(const char *message)
{
	printf("LOG:%s\n",message);
}


void SE_utils_logvertices(int verts)
{
	vertices+=verts;
}


void SE_utils_logvertices_init()
{
	vertices=0;
}


int SE_utils_vertices()
{
	return vertices;
}




