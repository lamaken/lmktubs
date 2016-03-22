/*
 * Avatar.h
 *
 *  Created on: 19/07/2011
 *      Author: alex
 */

#ifndef AVATAR_H_
#define AVATAR_H_


#include <list>
using namespace std;

#include "Ball.h"
#include "BezierCurve.h"

#include "Path.h"




#define INIT_LIVES 3



class Avatar {
public:
	Avatar();
	virtual ~Avatar();

	void setPoints(int npoints){points=npoints;}
	void setLives(int nlives){lives=nlives;}

	int getPoints(){return(points);}
	int getLives(){return(lives);}

	void init(){timeFromStart=0;points=0;lives=INIT_LIVES;}
	
	void resetBalls();

	Ball* getBallAt(int i);
	void addBall();
	void update();
	void logica();
	void reset();

	void setActualGate(int a);
	void setActualPath(int a);
	void setPosition(int a);

	list<Ball> &getBalls(){return balls;}

	//void draw();
	void setColor(float r,float g,float b);
	colorType &getcolor(){return color;}

	void updateBalls();
	int getTime(){return(timeFromStart);}
	void setTime(int tm){timeFromStart=tm;}
	bool isDead(){return m_dead;}
	void setDead(bool dead){m_dead=dead;}

	void checkToSwap();//IA

private:
	char *name;
	int points;			//punts aconseguits
	int lives;			//vides que li queden

	colorType color;

	list<Ball> balls;

	void KillBall(list<Ball>::iterator b);
	void SaveBall(list<Ball>::iterator b);

	list<list<Ball>::iterator> ballsToDelete;

	list<Path> buclepaths;

	int timeFromStart;
	bool m_dead;
};

#endif /* AVATAR_H_ */
