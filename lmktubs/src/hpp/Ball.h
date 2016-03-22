/*
 * Ball.h
 *
 *  Created on: 19/07/2011
 *      Author: alex
 */

#ifndef BALL_H_
#define BALL_H_

#include <iostream>


class Ball {
public:
	Ball();
	virtual ~Ball();

	int update();
	void reset();//la resetea
	int actualPath(){return m_actualPath;}
	int actualGate(){return m_actualGate;}
	int position(){return m_position;}
	void setColor(float re,float gr,float bl){r=re;g=gr;b=bl;;}
	void setActualPath(int path){m_actualPath=path;}
	void setActualGate(int gate){m_actualGate=gate;}
	void setPosition(int pos){m_position=pos;}
	int getSemafor(){return sem;}
	void setUnique(int u){unique=u;}
	int getUnique(){return unique;}
	void setSemafor(int new_semafor){sem=new_semafor;}
	int delay;          //temps d'espera abans de sortir al circuit
	

private:
	int m_actualPath;	//en quin path es troba la pilota
	int m_actualGate;   //en quin gate es troba la pilota
	int m_position;		//posicio relativa de la pilota
	int sem;			//semafor 0:path 1:gate
	float r,g,b;
	int unique;//id unic de la ball
};

#endif /* BALL_H_ */
