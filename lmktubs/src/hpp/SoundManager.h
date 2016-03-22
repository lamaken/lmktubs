/*
 * SoundManager.h
 *
 *  Created on: 11/07/2011
 *      Author: alex
 */

#ifndef SOUNDMANAGER_H_
#define SOUNDMANAGER_H_

#include <fmod.hpp>
#include <fmod_errors.h>
#include <map>
#include <string>

class SoundManager
	{
	public:
		SoundManager(void);
		~SoundManager(void);

	public:
		void init();
		void done();
		void update();
		void createSound(const std::string& name);
		int playSound(const std::string& name);
		FMOD::Channel* getChannel(int playId);

		bool sound_paused;
		int s_musica;
		int s_musica1;
		int s_musica2;
		int s_saved;

		//game
		void playKilled();
		void playOops();
		void playSaved();
		void playYes();

		void playBye();
		void playStart();
		void playRecord();


		//menu
		void playButton();
	



	private:
		void play(std::string name);
		int soundIndex;
		
	private:
		static void checkError(FMOD_RESULT result);
		FMOD::System* m_system;
		std::map<std::string,FMOD::Sound*> m_sounds;
		std::map<std::string,int> m_soundIndex;
		std::map<int, FMOD::Channel*> m_playingSounds;

	};
#endif
