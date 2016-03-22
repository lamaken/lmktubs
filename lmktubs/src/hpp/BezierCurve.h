/*
 * BezierCurve.h
 *
 *  Created on: 12/07/2011
 *      Author: alex
 */

#ifndef BEZIERCURVE_H_
#define BEZIERCURVE_H_

//

#include "MyGL.h"

#include "Circuit.h"
#include <cmath>

//************ Data structure
struct GLfloatPoint
{ GLfloat x,y;
};

const int MAX = 100;//quants punts per path
class GLfloatPointArray
{
public:
  int num;
  GLfloatPoint pt[MAX];
};

//***************** subprograms
typedef GLfloat colorType[3];

const int MAXCONTPTS = 50;//quants controls points per path
const int MAXPATHS = 100;//quants paths en un circuit

const int MAXAVATARS = 2;//quantes boles

const GLuint DISP_PATHS=1;//DISPLAY LIST FOR DE PATH
const GLuint DISP_GATES=2;//DISPLAY LIST FOR DE PATH

const int LINE_WEIGHT = 9;//gruix del cirucuit
const int BALL_WEIGTH = 8;


#define S_WIDTH 512 ////para la imagen de fondo
#define S_HEIGHT 512 ///

#define VELOCITY_AVATARS 0.00000025//interval de temps que incrementa posicions



class BezierCurve {
public:
	BezierCurve();
	virtual ~BezierCurve();


	void create();

	void swapGates();	//swap and refresh gates
	void swapGatesCPU();   //refresh cpu gates
	void swapGatesPLAYERS();//refresh players gates



	void controlCPU(float elapsedtime);					//logica
	void controlPLAYERS(float elapsedtime);				//logica
	void draw();//pinta escena

	void update();//actualiza desplaçament




	int numPaths;
	int numGates;



private:
	void drawPaths ();
	void displayListsPath(GLfloatPointArray P[]);
	void displayListsGates(GLfloatPointArray P[]);
	void drawGates ();
	void readControlPointsFromPaths (Circuit &c,GLfloatPointArray &P, int i);
	void readControlPointsFromGates (Circuit &c,GLfloatPointArray &P, int i);
	void ComputeCoeff (int n);
	float BlendingValue (int n, int k, float t);;
	void ComputePoint (float t, int n, GLfloatPoint & p,GLfloatPointArray ctrlPts);
	void Bezier ( GLfloatPointArray controlPts, int numInter, GLfloatPointArray & curve);

	void drawAvatar(double px,double py,float r, float g, float b);
	void drawPilotaTONTA(GLfloatPointArray P[],GLfloatPointArray G[]);

	void creaTontets();
	void creaJoc();
	void drawFondo();
	
	void drawIcons();
	void putDead(float x, float y);
	void putSaved(float x, float y);


	void drawPilotaLLESTA();


	int coef[MAXCONTPTS];   // the binomial coefficients

	int actualPath[MAXAVATARS];//path que es trba avat
	int actualGate[MAXAVATARS];//gate que es troba avatar
	int avatar[MAXAVATARS];//posicio del avatar
	int sem[MAXAVATARS];//si lavatar es troba en gate o path

	int actualavatar;

	float time;


	colorType acolor[MAXAVATARS];//avatars colors


	colorType cPaths;// color del circuit
	colorType cGates;// color dels gates


	GLfloatPointArray circuitCurve[MAXPATHS];
	GLfloatPointArray gatesCurve[MAXPATHS];

	GLfloatPointArray ControlPts;

	GLuint m_textureId_fondo;//fons del circuit
	GLuint m_textureId_dead;//icono calavera
	GLuint m_textureId_save;//icono casa


};

#endif /* BEZIERCURVE_H_ */
