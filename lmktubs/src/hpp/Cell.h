/*
 * Cell.h
 *
 *  Created on: 11/07/2011
 *      Author: alex
 */

#ifndef CELL_H_
#define CELL_H_

#include <list>
#include <string>



using namespace std;

enum typeEndCell {_KILLED,_SAVED,_START,_NONE};

//desplaçament dels punts a dibuixar en funcio del rectangle de joc que marca el fons
//0->1
#define _top 0.05
#define _left -0.01
#define _width 0.80
#define _height 0.67

class Cell {
public:
	Cell();
	virtual ~Cell();

public:

	void setXY(double x,double y){this->x=_left+(x*_width) ;this->y=_top+(y*_height);}
	void setTypeEnd(typeEndCell typeend){endCell=typeend;}
	typeEndCell getTypeEnd(){return(endCell);}

	//screen position
	double x;
	double y;

private:	
	
	typeEndCell endCell;
};

#endif /* CELL_H_ */
