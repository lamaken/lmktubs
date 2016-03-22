/*
 * Path.cpp
 *
 *  Created on: 11/07/2011
 *      Author: alex
 */

#include "Path.h"
#include <iostream>

Path::Path() {
	
	activeGate=0;
	numgroupgates=0;
	num=0;

}

Path::~Path() {
}

//inicio del circuito
void Path::addStart(double x, double y){
	Cell c;
	c.setTypeEnd(_START);
	setPositionXY(&c,x,y);
	cellsPath.push_back(c);

}

int Path::getNextGate(){
	int ret=-1;//not found
	int k=0;
	for (list<int>::iterator it = nextGates.begin(); it != nextGates.end(); it++){
		if(k++==activeGate)ret=*it;
	}
	return(ret);
}

//inicio del circuito
void Path::addGate(double x, double y){
	Cell c;
	setPositionXY(&c,x,y);
	cellsPath.push_back(c);
}

//inicio del circuito
void Path::addEnd(double x, double y){
	Cell c;
	setPositionXY(&c,x,y);
	c.setTypeEnd(_SAVED);
	cellsPath.push_back(c);
}

//inicio del circuito
void Path::addKill(double x, double y){
	Cell c;
	setPositionXY(&c,x,y);
	c.setTypeEnd(_KILLED);
	cellsPath.push_back(c);
}

//línea recta horitzontal cap a l'est
void Path::addCell(double x, double y) {
	Cell c;
	c.setTypeEnd(_NONE);
	setPositionXY(&c,x,y);
	cellsPath.push_back(c);
}
void Path::setPositionXY(Cell *c,double x,double y){
	c->setXY(x,y);
}

