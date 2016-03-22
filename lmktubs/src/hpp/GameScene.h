/*
 * GameScene.h
 *
 *  Created on: 19/07/2011
 *      Author: alex
 */

#ifndef __GameScene__
#define __GameScene__


#include "Hud.h"
#include "IScene.h"
#include "Circuit.h"
#include "BezierCurve.h"
#include "GameData.h"
#include "PauseMessage.h"
#include "GameEnded.h"



class GameScene	: public IScene
{
public:
	GameScene(void);
	~GameScene(void);

public:
	//heredadas de la interficie
	void init();
	void draw();
	void leave();
	void keyboard(unsigned char key, int x, int y);
	void pressMouse(int button, int state, int x, int y);
	void update(double timeElapsed);

	void startGame(int level,int gametype, bool showScore);

	//propias para el juego
	void createBezierCircuit();
	int uniqueBall();
	void resetUniqueBall(){m_uniqueBall=0;}
	Circuit& circuit() { return m_circuit; }
	Hud& getHud(){return hud;}
	GameData& gameData() { return m_gameData; }
	PauseMessage& pause(){return m_pause;}
	GameEnded& gameEnded(){return m_gameEnded;}
	
	


private:
	

	BezierCurve trenAlk;
	Circuit m_circuit;
	GameData m_gameData;
	Hud hud;
	PauseMessage m_pause;

	GameEnded m_gameEnded;

	int m_uniqueBall;

	int level;
	int gametype;
};

#endif // __GameScene__
