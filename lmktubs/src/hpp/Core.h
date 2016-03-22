/*
 * Core.h
 *
 *  Created on: 11/07/2011
 *      Author: alex
 */

#ifndef CORE_H_
#define CORE_H_



#include "Fonts.h"

#include "GameScene.h"

#include "MenuScene.h"

#include "SceneManager.h"
#include "SoundManager.h"

#include "globals.h"


class Core {
private:
	// Constructor y destructor de la clase
	static Core instance;
	Core();
	~Core();

public:
	static Core& singleton();
	
public:
	void init();
	void drawScene();							//pinta escena
	void controlScene(float elapsedtime);		//actualiza escena
	void keyPressScene(unsigned char key, int x, int y);//prem tecla en escena
	void pressMouseScene(int button, int state, int x, int y);
	void soundInit();
	
	//Funciones para acceder a la escena y sus elementos
	SceneManager& sceneManager() { return m_sceneManager; }

	GameScene& gameScene() { return m_GameScene; }

	SoundManager& soundManager(){return m_soundManager;}

	Fonts& fonts(){return m_fonts; }

	int mouseX(){return m_mouseX;}
	int mouseY(){return m_mouseY;}
	void setMousePosition(int mx, int my){m_mouseX=mx;m_mouseY=my;}


private:
	
	SceneManager m_sceneManager;			//controladors d'escenes

	Fonts m_fonts;//per escriure per pantalla

	GameScene m_GameScene;					//escena del joc
	MenuScene m_MenuScene;					//escena del menu

	SoundManager m_soundManager;

	int m_mouseX;
	int m_mouseY;


};

#endif /* MYOPENGL_H_ */
