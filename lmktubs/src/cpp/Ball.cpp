/*
 * Ball.cpp
 *
 *  Created on: 19/07/2011
 *      Author: alex
 */

#include "Ball.h"


Ball::Ball() {
	r=1.0;
	g=1.0;
	b=1.0;;
reset();
	}
void Ball::reset(){
	m_actualPath=0;	//en quin path es troba la pilota
	m_actualGate=0;   //en quin gate es troba la pilota
	m_position=0;		//posicio relativa de la pilota
	sem=0;			//semafor 0:path 1:gate

	}
Ball::~Ball() {
 }

