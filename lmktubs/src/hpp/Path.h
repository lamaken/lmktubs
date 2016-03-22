/*
 * Path.h
 *
 *  Created on: 11/07/2011
 *      Author: alex
 */

#ifndef PATH_H_
#define PATH_H_

#include "Cell.h"
#include <iostream>


#define FINAL_CIRCUIT -1

class Path {
public:
	Path();
	virtual ~Path();

	void addStart(double x, double y);//inicio del circuito
	void addEnd(double x, double y);//final del circuito
	void addKill(double x, double y);//final del circuito

	void addCell(double x, double y);//recta horitzontal est
	void addGate(double x, double y);//la continuacion es un gate


	void setNextPath(int np){next=np;IsPath();}
	void setNextGate(int np){numgroupgates++;nextGates.push_back(np);IsGate();}

	string getId(){return m_id;}
	void setId(string id){m_id=id;}

	int getNextPath(){return next;}
	int getNextGate();

	void swapGates(){activeGate++;if(activeGate>=numgroupgates)activeGate=0;}

	int getActiveGate(){return activeGate;}
	void setActiveGate(int ag){activeGate=ag;}
	void setNumGroup(int numg){numgroupgates=numg;}
	int getNumGroup(){return(numgroupgates);}

	bool nextIsGate(){return(m_nextisgate);}
	bool nextIsPath(){return(m_nextispath);}



	typeEndCell getBeginType(){	return cellsPath.begin()->getTypeEnd();}//only paths


	typeEndCell getEndType(){
		 list <Cell>::iterator c1_Iter;
		 c1_Iter = cellsPath.end( );
		 c1_Iter--;
		 return c1_Iter->getTypeEnd();
	}//only paths

	Cell getEndCell(){
		list <Cell>::iterator c1_Iter;
		 c1_Iter = cellsPath.end( );
		 c1_Iter--;
		 return *c1_Iter;
	}


	int num;//numero consecutiu que te el path ordenat segons creacio
	list <Cell> cellsPath;
	list <int> nextGates;//gates que formen el path

private:
	string m_id;//indentificador del path
	int next;
	int prev;

	void IsGate(){m_nextisgate=true;m_nextispath=false;}
	void IsPath(){m_nextisgate=false;m_nextispath=true;}

	bool m_nextispath;
	bool m_nextisgate;

	void setPositionXY(Cell *c,double x,double y);

	
	int activeGate;  //gate de gates que esta actiu
	int numgroupgates;//cuants gates per grup


};

#endif /* PATH_H_ */
