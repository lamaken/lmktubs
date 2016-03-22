#include "Fonts.h"
#include "SOIL.h"

#include <iostream>
#include <cstring>


Fonts::Fonts(void)
	{
	
	}

Fonts::~Fonts(void)
	{
	}
void Fonts::init(){
	m_textureId_fonts = SOIL_load_OGL_texture(
										"resources/images/font.png",
										SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	red=1;	green=1;	blue=1;
}
void Fonts::mostra_text(char cadena[], float x, float y){
    unsigned int tmp;

	glEnable(GL_TEXTURE_2D);

    for(tmp=0; tmp < strlen(cadena); tmp++) {         
		drawLetter(cadena[tmp], x + tmp*28, y);
	}

	
	glDisable(GL_TEXTURE_2D);
}

void Fonts::drawLetter(char c,int x, int y)
{
 int w=16;
 int inix=0;
 int iniy=12;
 char fonts[]= "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[#]^_`abcdefghijklmnopqrstuvwxyz{|}~ �";
 for(int n=0;n<80;n++){
	if(inix==w){
	 iniy--;
	 inix=0;
 }
 if(fonts[n]==c){
	glDrawChar(inix,iniy,x,y);
 }
 inix++;
 }
}

void Fonts::glDrawChar(int w,int h, int x, int y){
	float xi,yi,xf,yf;
	float ratio;
	ratio=0.0625;
	xi=w*ratio;
	yi=h*ratio;
	xf = xi + ratio;
	yf = yi + ratio;
	
	glBindTexture(GL_TEXTURE_2D,m_textureId_fonts);
	glColor3f(red,green,blue);
	glBegin(GL_QUADS);
		glTexCoord2f(xi,yf);	glVertex2i(x+0,y+50);
		glTexCoord2f(xf,yf);	glVertex2i(x+50,y+50);
		glTexCoord2f(xf,yi);	glVertex2i(x+50,y+0);	
		glTexCoord2f(xi,yi);	glVertex2i(x+0,y+0);
	glEnd();
	glColor4f(1.0,1.0,1.0,1.0);
	
}
