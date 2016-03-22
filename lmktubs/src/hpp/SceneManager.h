/*
 * GameData.h
 *
 *  Created on: 19/07/2011
 *      Author: alex
 */

#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "IScene.h"
#include <iostream>
#include <map>
#include <string>

class SceneManager
	{
	public:
		SceneManager(void);
		~SceneManager(void);
	private:
		std::map<std::string, IScene*> m_scenes;
		
		IScene* m_current;

	public:
		IScene& current_scene() { return *m_current; }

		void registerScene(const std::string& name,IScene* scene);
		void changeTo(const std::string& name);
		void update(double timeElapsed);
	};

#endif