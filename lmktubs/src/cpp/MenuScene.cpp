#include "MenuScene.h"
#include "Core.h"
#include "MyGL.h"

#include "SOIL.h"

MenuScene::MenuScene(void)
	{
	}


MenuScene::~MenuScene(void)
	{
	}


void MenuScene::leave()
{

	}
void MenuScene::init()
{
	m_textureId_menu = SOIL_load_OGL_texture(
										"resources/images/menu.png",
										SOIL_LOAD_AUTO,
										SOIL_CREATE_NEW_ID,
										SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	selected=0;
	whereWeAre=_MAIN;
} 
void MenuScene::drawMenu() {
	
	//fons
	

	glBindTexture(GL_TEXTURE_2D, m_textureId_menu);
	glBegin(GL_QUADS);
			glTexCoord2f(0,1);glVertex2i(0,1000);
			glTexCoord2f(1,1);glVertex2i(1000,1000);
			glTexCoord2f(1,0);glVertex2i(1000,0);
			glTexCoord2f(0,0);glVertex2i(0,0);
	glEnd();




	if (whereWeAre==_MAIN){	

	
	if(selected==0){
		Core::singleton().fonts().setColor(0.0,1.0,0.0);
		Core::singleton().fonts().mostra_text("> ONE PLAYER <",250,400);
		}
	else {
		Core::singleton().fonts().setColor(1.0,1.0,1.0);
		Core::singleton().fonts().mostra_text("  ONE PLAYER  ",250,400);
		}
	
	if(selected==1){
		Core::singleton().fonts().setColor(0.0,1.0,0);
		Core::singleton().fonts().mostra_text("> TWO PLAYERS <",240,350);
		}
	else {
		Core::singleton().fonts().setColor(1.0,1.0,1.0);
		Core::singleton().fonts().mostra_text("  TWO PLAYERS  ",240,350);
		}
	
	if(selected==2){
		Core::singleton().fonts().setColor(0.0,1.0,0);
		Core::singleton().fonts().mostra_text("> VERSUS COMPUTER <",200,300);
		}
	else {
		Core::singleton().fonts().setColor(1.0,1.0,1.0);
		Core::singleton().fonts().mostra_text("  VERSUS COMPUTER  ",200,300);
		}
	
	if(selected==3){
		Core::singleton().fonts().setColor(0.0,1.0,0.0);
		Core::singleton().fonts().mostra_text("> TOP 10 <",300,250);
		}
	else {
		Core::singleton().fonts().setColor(1,1.0,1.0);
		Core::singleton().fonts().mostra_text("  TOP 10  ",300,250);
		}
	

	if(selected==4){
		Core::singleton().fonts().setColor(0.0,1.0,0.0);
		Core::singleton().fonts().mostra_text("> EXIT <",340,150);
		}
	else {
		Core::singleton().fonts().setColor(1,1.0,1.0);
		Core::singleton().fonts().mostra_text("  EXIT  ",340,150);
		}
		}

if (whereWeAre==_LEVEL){	
	
	Core::singleton().fonts().setColor(1.0,1.0,0.0);
	switch(typeGame){
		case 0:
				Core::singleton().fonts().mostra_text("  ONE PLAYER",250,500);
				break;
		case 1:
				Core::singleton().fonts().mostra_text("  TWO PLAYERS",240,500);
				break;
		case 2:
				Core::singleton().fonts().mostra_text("  VERSUS COMPUTER",200,500);
				break;

		
		
		}

	if(selected==1){
	Core::singleton().fonts().setColor(0.0,1.0,0.0);
	Core::singleton().fonts().mostra_text("> CIRCUIT 1 <",270,400);
	}
	else {Core::singleton().fonts().setColor(1.0,1.0,1.0);
	Core::singleton().fonts().mostra_text("  CIRCUIT 1  ",270,400);
	}
	
	if(selected==2){
	Core::singleton().fonts().setColor(0.0,1.0,0.0);
	Core::singleton().fonts().mostra_text("> CIRCUIT 2 <",270,350);
	}
	else {Core::singleton().fonts().setColor(1.0,1.0,1.0);
	Core::singleton().fonts().mostra_text("  CIRCUIT 2  ",270,350);
	}

	if(selected==3){
	Core::singleton().fonts().setColor(0.0,1.0,0.0);
	Core::singleton().fonts().mostra_text("> CIRCUIT 3 <",270,300);
	}
	else {Core::singleton().fonts().setColor(1.0,1.0,1.0);
	Core::singleton().fonts().mostra_text("  CIRCUIT 3  ",270,300);
	}
/*
	if(selected==4){
	Core::singleton().fonts().setColor(0.0,1.0,0.0);
	Core::singleton().fonts().mostra_text("> CIRCUIT 4 <",270,250);
	}
	else {Core::singleton().fonts().setColor(1.0,1.0,1.0);
	Core::singleton().fonts().mostra_text("  CIRCUIT 4  ",270,250);
	}

*/	
 
	if(selected==0){
		Core::singleton().fonts().setColor(0.0,1.0,0.0);
		Core::singleton().fonts().mostra_text("> MENU <",340,150);
		}
	else {
		Core::singleton().fonts().setColor(1,1.0,1.0);
		Core::singleton().fonts().mostra_text("  MENU  ",340,150);
		}
	}

Core::singleton().fonts().setColor(1.0,1.0,1.0);
}

// Dibujar los componentes
void MenuScene::draw() 
{
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
	drawMenu();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glMatrixMode(GL_MODELVIEW);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
}

void MenuScene::update(double elapseTime){	
	int mx = Core::singleton().mouseX();
	int my = Core::singleton().mouseY();
if (whereWeAre==_MAIN){	
	
		if ( (mx>100)&&(mx<400)&&(my>286)&&(my<300) )selected=0;//1P
		else if ( (mx>100)&&(mx<400)&&(my>312)&&(my<326) )selected=1;//2P
		else if ( (mx>100)&&(mx<400)&&(my>338)&&(my<358) )selected=2;//1PVSCOM
		else if ( (mx>100)&&(mx<400)&&(my>364)&&(my<384) )selected=3;//TOP 10
		else if ( (mx>100)&&(mx<400)&&(my>417)&&(my<437) )selected=4;//EXIT
		else selected=-1;
	}
if (whereWeAre==_LEVEL){	

//select circuits

	if ( (mx>100)&&(mx<400)&&(my>286)&&(my<300) )selected=1;
	else if ( (mx>100)&&(mx<400)&&(my>312)&&(my<326) )selected=2;
	else if ( (mx>100)&&(mx<400)&&(my>338)&&(my<358) )selected=3;
	//else if ( (mx>100)&&(mx<400)&&(my>364)&&(my<384) )selected=4;
	else if ( (mx>100)&&(mx<400)&&(my>410)&&(my<432) )selected=0;
	else selected=-1;
}


if(selected==-1)glutSetCursor(GLUT_CURSOR_INHERIT);
else glutSetCursor(GLUT_CURSOR_CROSSHAIR);
}

//Funciones para gestionar los buffers de teclado y raton
void MenuScene::keyboard(unsigned char key, int x, int y)
{
	//selected++;
	//if(selected>3)selected=0;
}

void MenuScene::pressMouse(int button, int state, int x, int y){
	
	if(state==0){//click

		Core::singleton().soundManager().playButton();


if (whereWeAre==_MAIN){	
	
		switch (selected){
			case 0:
					whereWeAre=_LEVEL;
					typeGame=0;
					selected=0;
					break;
			case 1:	whereWeAre=_LEVEL;
					typeGame=1;
					selected=0;
					break;
			case 2:	whereWeAre=_LEVEL;
					typeGame=2;
					selected=0;
					break;
			case 3:	Core::singleton().sceneManager().changeTo("game");
					Core::singleton().gameScene().startGame(selected,typeGame,true);
					selected=0;
					break;

			case 4: cout<<endl<<"bye!"<<endl;
					exit(0);
					break;
			default:break;
		}
	}
	else if (whereWeAre==_LEVEL){	
	
		switch (selected){
			case 1:
					Core::singleton().sceneManager().changeTo("game");
					Core::singleton().gameScene().startGame(selected,typeGame,false);
					selected=0;
					break;
			case 2: Core::singleton().sceneManager().changeTo("game");
					Core::singleton().gameScene().startGame(selected,typeGame,false);
					selected=0;
					break;
			case 3:	Core::singleton().sceneManager().changeTo("game");
					Core::singleton().gameScene().startGame(selected,typeGame,false);
					selected=0;
					break;
			case 4:	selected=0;
					break;

			case 0:whereWeAre=_MAIN;
					selected=0;break;
			default:break;
		}

	}
	}
}
