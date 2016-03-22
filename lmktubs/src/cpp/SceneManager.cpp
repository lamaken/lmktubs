/*
 * SceneManager.cpp
 *
 *  Created on: 11/07/2011
 *      Author: alex
 */

#include "SceneManager.h"

SceneManager::SceneManager(void)
	{
	}

SceneManager::~SceneManager(void)
	{
	}
void SceneManager::registerScene(const std::string& name,IScene *scene){
	m_scenes[name]=scene;
	}
void SceneManager::changeTo(const std::string& name){
	if(m_current!=NULL)m_current->leave();
	m_current=m_scenes[name];
	m_current->init();
	}
void SceneManager::update(double timeElapsed){
	if(m_current!=NULL)m_current->update(timeElapsed);
	}