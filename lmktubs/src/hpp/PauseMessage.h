/*
 * PauseMessage.h
 *
 *  Created on: 22/07/2011
 *      Author: alex
 */

#ifndef PAUSEMESSAGE_H_
#define PAUSEMESSAGE_H_

#include <string>

class PauseMessage
	{
	public:
		PauseMessage(void);
		~PauseMessage(void);
		void draw();
		void setText(char *text);
		void keypress();
		void init();


	private:
		void loadPausePNG();
		int m_textureId_pause;
		char message[100];
	};
#endif