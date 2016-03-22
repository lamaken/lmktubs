/*
 * IScene.h
 *
 *  Created on: 11/07/2011
 *      Author: alex
 */

#ifndef ISCENE_H_
#define ISCENE_H_
class IScene
	{
	public:
		virtual void init()=0;
		virtual void draw()=0;
		virtual void leave()=0;
		virtual void update(double elapseTime)=0;
		virtual void keyboard(unsigned char key, int x, int y)=0;
		virtual void pressMouse(int button, int state, int x, int y)=0;
	};
#endif
