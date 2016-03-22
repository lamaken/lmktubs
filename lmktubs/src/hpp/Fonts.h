#ifndef __Fonts__
#define __Fonts__
#include "MyGL.h"
class Fonts
	{
	public:
		Fonts(void);
		~Fonts(void);

	private:
		void glDrawChar(int w,int h, int x, int y);
		void drawLetter(char c,int x, int y);
		GLuint m_textureId_fonts;

		float red;
		float green;
		float blue;
	
	public:	
		void mostra_text(char cadena[], float x, float y); 
		
		void init();
		void setColor(float r, float g, float b){red=r;green=g;blue=b;}

		
	};
#endif