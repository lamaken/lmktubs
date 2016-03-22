#pragma once

#include "IScene.h"
#include "MenuScene.h"

enum screenMenu {_MAIN,_LEVEL,_SCORE};


class MenuScene : public IScene
	{
	public:
		MenuScene(void);
		~MenuScene(void);

		void init();	
		void draw();	
		void leave();
		void update(double timeElapsed);
		void keyboard(unsigned char key, int x, int y);	
		void pressMouse(int button, int state, int x, int y);

	private:
		void drawMenu();
		int m_textureId_menu;
		
		screenMenu whereWeAre;//main, select level, save score
		int level;//selection level
		int typeGame;//0:SOLO 1:2PLAYERS 2:VSCPU
		int selected;//select option

	};
