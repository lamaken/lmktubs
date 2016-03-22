/*
 * PauseMessage.cpp
 *
 *  Created on: 22/07/2011
 *      Author: alex
 */

#include "PauseMessage.h"
#include "Core.h"
#include "SOIL.h"
#include <cstdio>

PauseMessage::PauseMessage(void)
	{
	sprintf(message, "Press SPACE to resume");
	}

PauseMessage::~PauseMessage(void)
	{
	}
void PauseMessage::loadPausePNG(){
	m_textureId_pause = SOIL_load_OGL_texture("resources/images/pausa.png",SOIL_LOAD_AUTO,	SOIL_CREATE_NEW_ID,	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}
void PauseMessage::init(){
	loadPausePNG();
	}

void PauseMessage::setText(char* text){
	 sprintf(message, "%s", text);
}

void PauseMessage::draw(){
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1500, 0.0, 1500);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glEnable(GL_BLEND);
	glBlendFunc( GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA );
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_textureId_pause);
	glBegin(GL_QUADS);
			glTexCoord2f(0,1);glVertex2i(0,1500);
			glTexCoord2f(1,1);glVertex2i(1500,1500);
			glTexCoord2f(1,0);glVertex2i(1500,0);
			glTexCoord2f(0,0);glVertex2i(0,0);
	glEnd();
	
	Core::singleton().fonts().setColor(0.0,1.0,1.0);
	Core::singleton().fonts().mostra_text(message,440,800);

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	

	glMatrixMode(GL_MODELVIEW);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

}

void PauseMessage::keypress(){
	
}
