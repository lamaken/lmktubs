/*
 * GameEnded.cpp
 *
 *  Created on: 22/07/2011
 *      Author: alex
 */

#include "GameEnded.h"
#include "Core.h"

#include <string>
#include <iostream>
#include <cstring>
#include <stdio.h>

#include "SOIL.h"

GameEnded::GameEnded(void)
	{
	
	}

GameEnded::~GameEnded(void)
	{
	}
void GameEnded::loadEndPNG(){
	m_textureId_scores = SOIL_load_OGL_texture("resources/images/score.png",SOIL_LOAD_AUTO,	SOIL_CREATE_NEW_ID,	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	m_textureId_newrecord = SOIL_load_OGL_texture("resources/images/newrecord.png",SOIL_LOAD_AUTO,	SOIL_CREATE_NEW_ID,	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

}
void GameEnded::init(){
	loadEndPNG();
	toSort.clear();
	showlevel=1;
	wait=0;
	loadFileRecords();

}

void GameEnded::prepare(){
	top10score data;

	//reset all to 0
	for(int level=1;level<=NUMCIRCUITS;level++){
		for(int top=0;top<10;top++){
			sprintf(data.playerName, "void");
			data.level=level;
			data.counter=99999;
			data.points=0;
			data.type=0;

			toSort.push_back(data);
		}
	}	
	
}


void GameEnded::loadFileRecords(){
	FILE* input;
	input = fopen(FILE_NAME, "rb");
	if(input==NULL){
		cout<<"Scores data not found. Creating a void file."<<endl;
		prepare();
	}
	else{
			top10score data;
			toSort.clear();
			for(int k=0;k<NUMCIRCUITS*10;k++)
			{
			 fread(&data, sizeof(data), 1, input);
			 toSort.push_back(data);
			}
			
			fclose(input);
		}
}

bool GameEnded::checkRecord(int typef, int level, int points, int counter){
	
	r_type = typef;
	r_level = level;
	r_points = points;
	r_counter = counter;
	newrecord=false;
	numplayerrecord=0;

	if (points>0){//com a minim fagi mes de 0 punts
	for (list<top10score>::iterator it = toSort.begin(); it != toSort.end(); it++){
		
		if(it->level==level){
			if(points>it->points){
				newrecord=true;
				return(true);
			}
			if(points==it->points){
				if(it->counter>counter){
					newrecord=true; 
					return(true);}
			}
		}
		
		}	
	}
	return(false);
}

bool compare(top10score first,top10score second){
		
	if(first.level>=second.level){
		if(first.level==second.level){
		if(first.points>=second.points){
			if(first.points==second.points){
				if(first.counter<=second.counter)return true;
				else return false;
			}else return true;
		}else return false;
		}else return false;
	}else return true;
	
	
}

//solo pone los 10 primeros para cada nivel
void GameEnded::refreshtop10(){

	list<top10score> finish;
	int level=0;
	int top = 0;
	finish.clear();
	for (list<top10score>::iterator it = toSort.begin(); it != toSort.end(); it++){
	
		
		if(it->level==(level+1)){
			
			finish.push_back(*it);
			top++;
			if(top>9){
				level++;
				top=0;
			}	
		}
	}
	toSort.clear();
	for (list<top10score>::iterator it = finish.begin(); it != finish.end(); it++){
		toSort.push_back(*it);
	}
}


void GameEnded::enterNewRecord(char *name){

	Core::singleton().soundManager().playRecord();
	sprintf(nick,name);
	sprintf(data2.playerName, name);
	sprintf(r_player, name);
	data2.type = r_type;
	data2.level = r_level;
	data2.points = r_points;
	data2.counter = r_counter;
	newrecord=true;
	int k=0;
	if(0==strcmp(name,"Computer")){
			toSort.push_back(data2);
			k = toSort.size();
			sort();
			k = toSort.size();
			refreshtop10();
			k = toSort.size();
			saveFileRecord();
			k = toSort.size();
			newrecord=false;
		}
	
}



void GameEnded::saveFileRecord(){
	FILE* output;
	output = fopen(FILE_NAME, "wb");
	top10score top;
	for (list<top10score>::iterator it = toSort.begin(); it != toSort.end(); it++){
			top = *it;		
			fwrite(&top, sizeof(top), 1, output);
	}
	fclose(output);
}


void GameEnded::drawRecord(){
    glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1000, 0.0, 1000);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glEnable(GL_BLEND);
	glBlendFunc( GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA );
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_textureId_newrecord);
	glBegin(GL_QUADS);
			glTexCoord2f(0,1);glVertex2i(0,1000);
			glTexCoord2f(1,1);glVertex2i(1000,1000);
			glTexCoord2f(1,0);glVertex2i(1000,0);
			glTexCoord2f(0,0);glVertex2i(0,0);
	glEnd();
	
	char nik[100];
	if(((int)wait)%2==0)sprintf(nik, "%s|", nick);
	else sprintf(nik, "%s", nick);

	Core::singleton().fonts().setColor(1,1,0);
	Core::singleton().fonts().mostra_text(nik,400,525);


	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	

	glMatrixMode(GL_MODELVIEW);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
}

void GameEnded::drawScores(){
int top=0;

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1000, 0.0, 1000);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glEnable(GL_BLEND);
	glBlendFunc( GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA );
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_textureId_scores);
	glBegin(GL_QUADS);
			glTexCoord2f(0,1);glVertex2i(0,1000);
			glTexCoord2f(1,1);glVertex2i(1000,1000);
			glTexCoord2f(1,0);glVertex2i(1000,0);
			glTexCoord2f(0,0);glVertex2i(0,0);
	glEnd();
	
char name[10];
char type[10];
char points[15];
char time[200];

int y=0;



sprintf(name,"CIRCUIT %d",showlevel);
Core::singleton().fonts().setColor(1,1,0);
Core::singleton().fonts().mostra_text(name,370,520);




for (list<top10score>::iterator it = toSort.begin(); it != toSort.end(); it++){

		if(top>9){
			top=0;	
		}
		
		sprintf(name,"%s",it->playerName);
		switch(it->type){
			case _1P:sprintf(type,"1P ");break;
			case _2P:sprintf(type,"2P ");break;
			case _CPU:sprintf(type,"CPU");break;
			default:sprintf(type,"Error");break;
		}

		
		char chour[5];
		char cmin[5];
		char csec[5];

		int itime, hour, min, sec;

		itime = (int) it->counter;

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

		
		sprintf(time, "%s:%s:%s", chour, cmin, csec);
		
		sprintf(points, "%d", it->points);
		
		if((it->level==showlevel)&&(it->points>0)){
			
			Core::singleton().fonts().setColor(1,1,1);
			Core::singleton().fonts().mostra_text(type,70,430-(y*30));
			Core::singleton().fonts().setColor(1,1,1);
			Core::singleton().fonts().mostra_text(name,170,430-(y*30));
			Core::singleton().fonts().setColor(1,1,1);
			Core::singleton().fonts().mostra_text(points,400,430-(y*30));
			Core::singleton().fonts().setColor(1,1,1);
			Core::singleton().fonts().mostra_text(time,650,430-(y*30));
			y++;	
		}
		
		top++;
	}

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	glMatrixMode(GL_MODELVIEW);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
}


void GameEnded::keypress(unsigned char key){

	if(!newrecord){
		if(key==27)Core::singleton().sceneManager().changeTo("menu");
		else wait=100;
	}else{

		if(strlen(nick)>0)if(key==8){
			nick[strlen(nick)-1] ='\0';
		}
		if(strlen(nick)<8){
		if (( (key>=97)&&(key<=122) )||
			((key>=65)&&(key<=90))){
				nick[strlen(nick)] =key;
				nick[strlen(nick)+1] ='\0';

				}

		}

		if(key==13){
			if(numplayerrecord<=1){
				sprintf(data2.playerName,nick);
				toSort.push_back(data2);
				
				sort();
				refreshtop10();
				int k = toSort.size();
				saveFileRecord();	
				newrecord=false;
			
			}

			if(numplayerrecord==2){
				sprintf(data3.playerName,nick);
				toSort.push_back(data3);	
				sort();
				refreshtop10();
				saveFileRecord();	
				newrecord=false;
			};

			if(numplayerrecord==3){
				sprintf(data2.playerName,nick);
				toSort.push_back(data2);
				sort();
				refreshtop10();
				saveFileRecord();
				sprintf(nick,data3.playerName);
				numplayerrecord=2;
				sprintf(nick,"Player2");
				
			}
			
			
		}
	}
	
}


void GameEnded::sort(){
	
	toSort.sort(compare);
	
}

void GameEnded::update(float elapsedtime){
	wait+=elapsedtime;
	if(wait>15){
			if(showlevel>=NUMCIRCUITS){
				showlevel=0;
			}
			showlevel++;
			wait=0;
	}
}


void GameEnded::checkTwoPlayersRecord(int typef, int level, int points, int counter,int typef2, int level2, int points2, int counter2){

	int a=0;
	newrecord=false;
	if(checkRecord(typef,level,points,counter)){
		
		sprintf(nick,"Player1");
		sprintf(data2.playerName, "Player1");
		data2.type = typef;
		data2.level = level;
		data2.points = points;
		data2.counter = counter;
		a+=1;
		newrecord=true;
	}
	
	if(checkRecord(typef2,level2,points2,counter2)){	
		sprintf(nick,"Player1");
		sprintf(data3.playerName, "Player2");
		data3.type = typef2;
		data3.level = level2;
		data3.points = points2;
		data3.counter = counter2;	
		a+=2;
		newrecord=true;
	}
	numplayerrecord=a;//1:1player 2:2player 3:los dos a la vez

}



void GameEnded::drawS(){

	if(newrecord){
		drawRecord();
	}else{

		drawScores();
	}
}
