/*
 * Hud.cpp
 *
 *  Created on: 22/07/2011
 *      Author: alex
 */

#include "Hud.h"
#include "Core.h"
#include "MyGL.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdio>


Hud::Hud() {

}

Hud::~Hud() {
}
void Hud::init() {
	timeHud=0;
}
void Hud::incTime(float elapsedtime){
timeHud+=elapsedtime;
}

void Hud::drawTime()  {
	char ctime[200];
	char chour[5];
	char cmin[5];
	char csec[5];

	int itime, hour, min, sec;

	itime = (int) timeHud;

	hour = itime / 3600;
	itime = itime % 3600;
	min = itime / 60;
	itime = itime % 60;
	sec = itime;

	if(hour<10)sprintf(chour, "0%d", hour);
	else sprintf(chour, "%d", hour);
	
	if(min<10)sprintf(cmin, "0%d", min);
	else sprintf(cmin, "%d", min);

	if(sec<10)sprintf(csec, "0%d", sec);
	else sprintf(csec, "%d", sec);





	sprintf(ctime, "%s:%s:%s", chour, cmin, csec);
	Core::singleton().fonts().mostra_text(ctime,400,50);
}

void Hud::drawDataPlayer1()  {
	char data[200];

	Core::singleton().fonts().setColor(1,0.6,0.2);
	
	sprintf(data, "%d", Core::singleton().gameScene().gameData().Player1().getLives());
	Core::singleton().fonts().mostra_text(data, 100.0, 80.0);
	
	sprintf(data, "%d �", Core::singleton().gameScene().gameData().Player1().getPoints());
	Core::singleton().fonts().mostra_text(data, 100.0, 35.0);

	sprintf(data, "%d", Core::singleton().gameScene().gameData().Player1().getBalls().size());
	Core::singleton().fonts().mostra_text(data, 100.0, 1022.0);

	if(Core::singleton().gameScene().gameData().Player1().getLives()==0){
		Core::singleton().fonts().setColor(1,0,0);
		Core::singleton().fonts().mostra_text("�dead!", 170.0, 60.0);
	}else
	if(Core::singleton().gameScene().gameData().Player1().getBalls().size()==0){
		Core::singleton().fonts().setColor(1,1,0);
		Core::singleton().fonts().mostra_text("�done!", 170.0, 60.0);
	}

	Core::singleton().fonts().setColor(1,1,1);
}

void Hud::drawDataPlayer2()  {
	char data[200];
	Core::singleton().fonts().setColor(0,1,0);
	sprintf(data, "%d", Core::singleton().gameScene().gameData().Player2().getLives());
	Core::singleton().fonts().mostra_text(data, 750.0, 80.0);
	
	sprintf(data, "%d �", Core::singleton().gameScene().gameData().Player2().getPoints());
	Core::singleton().fonts().mostra_text(data, 750.0, 35.0);

	sprintf(data, "%d", Core::singleton().gameScene().gameData().Player2().getBalls().size());
	Core::singleton().fonts().mostra_text(data, 840.0, 1022.0);

	if(Core::singleton().gameScene().gameData().Player2().getLives()==0){
		Core::singleton().fonts().setColor(1,0,0);
		Core::singleton().fonts().mostra_text("�dead!", 830.0, 60.0);
	}else
	if(Core::singleton().gameScene().gameData().Player2().getBalls().size()==0){
		Core::singleton().fonts().setColor(1,1,0);
		Core::singleton().fonts().mostra_text("�done!", 830.0, 60.0);
	}

	Core::singleton().fonts().setColor(1,1,1);
}

void Hud::drawDataCPU()  {
	char data[200];
	Core::singleton().fonts().setColor(0,1,0);
	sprintf(data, "%d", Core::singleton().gameScene().gameData().CPU().getLives());
	Core::singleton().fonts().mostra_text(data, 750.0, 80.0);
	
	sprintf(data, "%d �", Core::singleton().gameScene().gameData().CPU().getPoints());
	Core::singleton().fonts().mostra_text(data, 750.0, 35.0);

	sprintf(data, "%d", Core::singleton().gameScene().gameData().CPU().getBalls().size());
	Core::singleton().fonts().mostra_text(data, 840.0, 1022.0);

	if(Core::singleton().gameScene().gameData().CPU().getLives()==0){
		Core::singleton().fonts().setColor(1,0,0);
		Core::singleton().fonts().mostra_text("�dead!", 830.0, 60.0);
	}else
	if(Core::singleton().gameScene().gameData().CPU().getBalls().size()==0){
		Core::singleton().fonts().setColor(1,1,0);
		Core::singleton().fonts().mostra_text("�done!", 830.0, 60.0);
	}

	Core::singleton().fonts().setColor(1,1,1);
}

void Hud::draw() {
	int typeGame = Core::singleton().gameScene().gameData().getGameType();

	//abrimos
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, 1100, 0.0, 1100);//para que las letras sean mas peque�as
		
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glEnable(GL_BLEND);
		glBlendFunc( GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA );



	switch (typeGame) {
	    case _1P:
				drawDataPlayer1();
		break;
	    case _2P:
		 		drawDataPlayer1();
				drawDataPlayer2();
		break;
	    case _CPU:
				drawDataPlayer1();
				drawDataCPU();
		break;
	}
		
	
	
	drawTime();

		////////cerramos
		glDisable(GL_BLEND);
		glMatrixMode(GL_MODELVIEW);

		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

}
