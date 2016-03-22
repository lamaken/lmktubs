/*
 * Core.cpp
 *
 *  Created on: 11/07/2011
 *      Author: alex
 */

#include "Core.h"
#include <iostream>


Core Core::instance;

Core::Core() {

	
	
}

Core::~Core() {
}


Core& Core::singleton()
{
	return instance;
}

void Core::init(){
	fonts().init();


	m_sceneManager.registerScene("game",&m_GameScene);
	m_sceneManager.registerScene("menu",&m_MenuScene);
	m_sceneManager.changeTo("menu");

	soundInit();
}

void Core::controlScene(float elapsedtime){

	Core::singleton().sceneManager().current_scene().update(elapsedtime);

}

void Core::drawScene(){
	Core::singleton().sceneManager().current_scene().draw();

}

void Core::keyPressScene(unsigned char key, int x, int y){
	Core::singleton().sceneManager().current_scene().keyboard(key, x, y);
}


void Core::pressMouseScene(int button, int state, int x, int y){
	Core::singleton().sceneManager().current_scene().pressMouse(button, state, x, y);
}


void Core::soundInit(){
	soundManager().init();
	soundManager().createSound(SND_BUTTON);
	soundManager().createSound(SND_KILLED);
	soundManager().createSound(SND_MUSICA);
	soundManager().createSound(SND_SAVED);
	soundManager().createSound(SND_START);
	soundManager().createSound(SND_BYE);
	soundManager().createSound(SND_YES);
	soundManager().createSound(SND_OHH);
	soundManager().createSound(SND_RECORD);

	int tmp= soundManager().playSound(SND_MUSICA);
	soundManager().getChannel(tmp)->setVolume(0.2);
	soundManager().getChannel(tmp)->setPaused(false);
	soundManager().getChannel(tmp)->setMode(FMOD_LOOP_NORMAL);

	soundManager().sound_paused=true;


}
