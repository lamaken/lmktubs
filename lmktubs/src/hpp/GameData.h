/*
 * GameData.h
 *
 *  Created on: 19/07/2011
 *      Author: alex
 */

#ifndef GAMEDATA_H_
#define GAMEDATA_H_

#include "Avatar.h"


#define _1P 0	// ONE PLAYER
#define _2P 1	// TWO PLAYERS
#define _CPU 2  // ONE PLAYER VERSUS CPU




class GameData {
public:
	GameData();
	virtual ~GameData();

	void createGame(int level,int gtype);
	void start();
	void update();
	void logica();
	void showHud();


	void control(int a);

	//bool canUpdate(list<Ball>::iterator it);

	Avatar &Player1(){return A1P;}
	Avatar &Player2(){return A2P;}
	Avatar &CPU(){return ACPU;}

	bool paused(){return m_paused;}
	bool isgameEnded(){return m_gameEnded;}
	void swapPaused(){m_paused=!m_paused;}
	void swapGameEnd(){m_gameEnded=!m_gameEnded;}


	int getGameType(){return gameType;}
	int numAvatars;
	int gameCounter;
	int getSublevel(){return sublevel;}
	void endGame();//passa a endgame

private:
	int level;
	int sublevel;
	int velocity;
	bool m_gameEnded;//if end game


	int gameType;
	Avatar A1P;
	Avatar A2P;
	Avatar ACPU;

	//void updateUniques();
	void nextLevel();//si todo ok,, pasa al siguiente nivel
	bool m_paused;
};

#endif /* GAMEDATA_H_ */
