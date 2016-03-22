/*
 * Circuit.h
 *
 *  Created on: 11/07/2011
 *      Author: alex
 */

#ifndef CIRCUIT_H_
#define CIRCUIT_H_

#include "Path.h"



class Circuit {
public:
	Circuit();
	virtual ~Circuit();
	bool loadCircuit(int level);
	int numPaths(){return((int)Paths.size());}
	int numGates(){return((int)Gates.size());}
//	int width;
//	int height;

	list<Cell> allCellsFromPath(int i);
	list<Cell> allCellsFromGate(int i);


	Path getPathAt(int i);//retorna path que es troba en posicio i de l'array
	Path *getPathById(string id);//retorna path amb identificador = id

	Path getGateAt(int i);//retorna path que es troba en posicio i de l'array
	Path *getGateById(string id, int i);//retorna path amb identificador = id

	void swapGates();

private:
	void calcDimensions();
	void loadOne();
	void loadTwo();
	void loadThree();

	void pushPath(Path p, string id);
	void pushGate(Path p, string id, unsigned int active,unsigned int maxgates);
	list <Path> Paths;
	list <Path> Gates;

};

#endif /* CIRCUIT_H_ */
