#include "title.h"

int exittitle;

SE_image *bgtitle;
SE_image *eco;
SE_image *tjess;
SE_image *tkiko;
SE_image *ftitleimg;

SE_font *fonttitle;

float trans_start;
float dstart;

SE_timer *ttotal;

float alphatitle;

void init_var_title()
{

	exittitle = 0;

	trans_start = 0;
	dstart = 0.001;
	alphatitle = 0;



}



void load_images_title()
{


	bgtitle = SE_image_load("assets/images/bgtitle.png");
        SE_image_size(bgtitle,640,480);
	eco = SE_image_load("assets/images/eco.png");
        SE_image_size(eco,445,354);
	tjess = SE_image_load("assets/images/tjess.png");
        SE_image_size(tjess,383,319);
	tkiko = SE_image_load("assets/images/tkiko.png");
        SE_image_size(tkiko,198,350);
	ftitleimg = SE_image_load("assets/images/font256.png");
	fonttitle = SE_font_create(ftitleimg,16,16,16,16);
	SE_font_settings(fonttitle,10);

}

void clean_images_title()
{

	SE_image_clean(bgtitle);
	SE_image_clean(eco);	
	SE_image_clean(tjess);
	SE_image_clean(tkiko);	
	SE_image_clean(ftitleimg);	

}






void screentitle()
{


	

	SE_image_draw(bgtitle,0,0,50);
	SE_image_full_draw(eco,100,-20,0,1,1,0,0,0,1,1,1,1);
	SE_image_draw(tkiko,-30,130,100);
	SE_image_draw(tjess,350,190,100);
		
	if(trans_start >= 1)dstart = -0.01;
	if(trans_start <= 0)dstart = 0.01;
		

	trans_start += dstart;

	SE_font_draw(fonttitle,"PRESS START",240,400,0,1,1,1,0,0,1,1,1,trans_start);
	
	SE_drawrectangle(0,0,0,640,480,1,1,1,1,alphatitle);
	

	

	if(exittitle == 1)
	{
				
		
		alphatitle += 0.01;
				
	}
	
		


}

