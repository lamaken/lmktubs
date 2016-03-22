#include "SoundManager.h"
#include "globals.h"


	SoundManager::SoundManager(void){
	}

	SoundManager::~SoundManager(void){
	}

	void SoundManager::init(){

		FMOD_RESULT result;
		unsigned int version;
		FMOD_CAPS caps;
		FMOD_SPEAKERMODE speakerMode;

		checkError(FMOD::System_Create(&m_system));

		checkError(m_system->getVersion(&version));
		if(version<FMOD_VERSION){
			std::cout << "Versi�n err�nea" << std::endl;
			exit(-1);
		}
		//checkError(m_system->init(10, FMOD_INIT_NORMAL, 0));

		//checkError(m_system->getDriverCaps(0,&caps,0,0,&speakerMode));
		//if(caps&FMOD_CAPS_HARDWARE_EMULATED)checkError(m_system->setDSPBufferSize(1024,10));
		result = m_system->init(100,FMOD_INIT_NORMAL,0);
		if(result==FMOD_ERR_OUTPUT_CREATEBUFFER){
			checkError(m_system->setSpeakerMode(FMOD_SPEAKERMODE_STEREO));
			checkError(m_system->init(100,FMOD_INIT_NORMAL,0));
		}

		soundIndex=0;
	}

	void SoundManager::done(){
	}

	void SoundManager::update(){
		m_system->update();
	}

	void SoundManager::createSound(const std::string& name){
		FMOD::Sound* sound;
		std::string soundFile = SNDS_PATH+name;
		std::cout<<"loading..."<<soundFile<<std::endl;
		checkError(m_system->createSound(soundFile.c_str(),FMOD_3D,0,&sound));
		m_sounds[name] = sound;
		m_soundIndex[name] = soundIndex++;
	}

	
	int SoundManager::playSound(const std::string &name){
		FMOD::Sound *sound=m_sounds[name];
		FMOD::Channel* channel;
		checkError(m_system->playSound(FMOD_CHANNEL_FREE,sound,true,&channel));
		static int nextID=0;
		int id = nextID++;
		m_playingSounds[id] = channel;
		return(id);
	}

	FMOD::Channel* SoundManager::getChannel(int playId){
		if(m_playingSounds.find(playId)==m_playingSounds.end())
			return NULL;
		return m_playingSounds[playId];
	}
	void SoundManager::checkError(FMOD_RESULT result){
		if (FMOD_OK != result){
			std::cout << FMOD_ErrorString(result) << std::endl;
			exit(-1);
		}
	}
	void SoundManager::play(std::string name){
		if(m_soundIndex[name]!=0)getChannel(m_soundIndex[name])->stop();
		m_soundIndex[name]= playSound(name);
		getChannel(m_soundIndex[name])->setPaused(false);
	}

	void SoundManager::playKilled(){
		play(SND_KILLED);
	}

	void SoundManager::playOops(){
		play(SND_OHH);
	}
	void SoundManager::playSaved(){
		play(SND_SAVED);
	}

	void SoundManager::playYes(){
		play(SND_YES);
	}

	void SoundManager::playButton(){
		play(SND_BUTTON);
	}
	void SoundManager::playBye(){
		play(SND_BYE);

	}

	void SoundManager::playStart(){
		play(SND_START);
	}

	void SoundManager::playRecord(){
		play(SND_RECORD);
	}

