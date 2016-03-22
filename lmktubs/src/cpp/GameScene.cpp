/*
 * GameScene.cpp
 *
 *  Created on: 19/07/2011
 *      Author: alex
 */


#include "GameScene.h"
#include "Core.h"

GameScene::GameScene()
{
}

GameScene::~GameScene(){
	}


void GameScene::leave()
{
 
}

void GameScene::startGame(int level,int gametype,bool showScore){

	
	m_gameData.createGame(level,gametype);
	m_circuit.loadCircuit(level);
	createBezierCircuit();
	trenAlk.create();
	hud.init();
	pause().init();
	pause().setText("Press SPACE to play");
	gameEnded().init();

	//si viene del menu solo quiere mostrar scores
	if(showScore){
		gameData().swapGameEnd();
		gameData().swapPaused();
	}
}


void GameScene::init()
{
	resetUniqueBall();//inciializamos contador de bolas identificativas
	m_gameData.Player1().reset();
	m_gameData.Player2().reset();
	m_gameData.CPU().reset();
	
	
} 
void GameScene::draw(){

	if(!m_gameData.isgameEnded()){

		if(!m_gameData.paused()){
			trenAlk.draw();
			hud.draw();
		}else{//paused
			trenAlk.draw();
			hud.draw();
			pause().draw();
		}
	}else{//game ended
		gameEnded().drawS();
		
	}
}



void GameScene::update(double elapsedtime){
	
	if(!m_gameData.isgameEnded()){
		if(!m_gameData.paused()){
				/////////// follow the circuit
				//trenAlk.controlCPU(elapsedtime); DISTRACTORES
				trenAlk.controlPLAYERS(elapsedtime);

				/////////// move all balls one step
				trenAlk.update();
				///////////
				hud.incTime(elapsedtime);
		}
		else{//game pause
				
		}
	}else{//game end
		m_gameEnded.update(elapsedtime);
	}
}

//Funciones para gestionar los buffers de teclado y raton
void GameScene::keyboard(unsigned char key, int x, int y)
{
	if(!m_gameData.isgameEnded()){
		if (key==' '){
			pause().setText("Press SPACE to resume");
			m_gameData.swapPaused();
		}
		else
		if (key==27){
			Core::singleton().sceneManager().changeTo("menu");
		}
		else
		if(!m_gameData.paused()){
			trenAlk.swapGates();
			//trenAlk.swapGatesCPU();
			trenAlk.swapGatesPLAYERS();
			}else{
				pause().keypress();
		}
	}else{//gameended
		gameEnded().keypress(key);	
	}
}


int GameScene::uniqueBall(){
	return m_uniqueBall++;
}


void GameScene::createBezierCircuit(){
	trenAlk.create();
	hud.init();
}

void GameScene::pressMouse(int button, int state, int x, int y){
	
}




