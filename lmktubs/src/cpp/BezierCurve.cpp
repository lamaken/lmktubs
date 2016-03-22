/*
 * BezierCurve.cpp
 *
 *  Created on: 12/07/2011
 *      Author: alex
 */

#include "BezierCurve.h"
#include "Core.h"
#include "SOIL.h"
#include <iostream>


void BezierCurve::putDead(float x, float y){



	x = (1000/2)+(1000/2*x);
	y = (1000/2)+(1000/2*y);

	x-=20;
	y-=20;

	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1000, 0.0, 1000);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glEnable(GL_BLEND);
	glBlendFunc( GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA );
	
	glEnable(GL_TEXTURE_2D);
	///////

	glBindTexture(GL_TEXTURE_2D,m_textureId_dead);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
		glTexCoord2f(0,1);	glVertex2i(x+0,y+64);
		glTexCoord2f(1,1);	glVertex2i(x+64,y+64);
		glTexCoord2f(1,0);	glVertex2i(x+64,y+0);	
		glTexCoord2f(0,0);	glVertex2i(x+0,y+0);
	glEnd();
	glColor4f(1.0,1.0,1.0,1.0);

	//////////
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glMatrixMode(GL_MODELVIEW);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	////////////
}
void BezierCurve::putSaved(float x, float y){

	/////////	
	x = (1000/2)+(1000/2*x);
	y = (1000/2)+(1000/2*y);
	x-=20;
	y-=20;

	/////////
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1000, 0.0, 1000);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glEnable(GL_BLEND);
	glBlendFunc( GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA );
	
	glEnable(GL_TEXTURE_2D);
	///////
	glBindTexture(GL_TEXTURE_2D,m_textureId_save);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
		glTexCoord2f(0,1);	glVertex2i(x+0,y+64);
		glTexCoord2f(1,1);	glVertex2i(x+64,y+64);
		glTexCoord2f(1,0);	glVertex2i(x+64,y+0);	
		glTexCoord2f(0,0);	glVertex2i(x+0,y+0);
	glEnd();
	glColor4f(1.0,1.0,1.0,1.0);
	//////////
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glMatrixMode(GL_MODELVIEW);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	////////////

}

void BezierCurve::drawFondo(){
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, S_WIDTH, 0.0, S_HEIGHT);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glEnable(GL_BLEND);
	glBlendFunc( GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA );
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_textureId_fondo);
	glBegin(GL_QUADS);
			glTexCoord2f(0,1);glVertex2i(0,512);
			glTexCoord2f(1,1);glVertex2i(512,512);
			glTexCoord2f(1,0);glVertex2i(512,0);
			glTexCoord2f(0,0);glVertex2i(0,0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glMatrixMode(GL_MODELVIEW);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();


}

void BezierCurve::creaJoc(){
	
	
	
	////load texture fondo
		if(Core::singleton().gameScene().gameData().getGameType()==_1P){
			m_textureId_fondo = SOIL_load_OGL_texture("resources/images/fondo1P.png",SOIL_LOAD_AUTO,	SOIL_CREATE_NEW_ID,	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
		}
		else{
			m_textureId_fondo = SOIL_load_OGL_texture("resources/images/fondo2P.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
		}
	
	m_textureId_dead = SOIL_load_OGL_texture("resources/images/dead.png",SOIL_LOAD_AUTO,	SOIL_CREATE_NEW_ID,	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);//icono calavera
	m_textureId_save = SOIL_load_OGL_texture("resources/images/casa.png",SOIL_LOAD_AUTO,	SOIL_CREATE_NEW_ID,	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);//icono casa

	
	
	
	if(Core::singleton().gameScene().gameData().getGameType()==_1P){
		Core::singleton().gameScene().gameData().Player1().setActualPath(0);
		Core::singleton().gameScene().gameData().Player1().setActualGate(0);
		Core::singleton().gameScene().gameData().Player1().setPosition(0);
	}

	if(Core::singleton().gameScene().gameData().getGameType()==_2P){
		Core::singleton().gameScene().gameData().Player1().setActualPath(0);
		Core::singleton().gameScene().gameData().Player1().setActualGate(0);
		Core::singleton().gameScene().gameData().Player1().setPosition(0);

		Core::singleton().gameScene().gameData().Player2().setActualPath(0);
		Core::singleton().gameScene().gameData().Player2().setActualGate(0);
		Core::singleton().gameScene().gameData().Player2().setPosition(50);

	}

	if(Core::singleton().gameScene().gameData().getGameType()==_CPU){
		Core::singleton().gameScene().gameData().Player1().setActualPath(0);
		Core::singleton().gameScene().gameData().Player1().setActualGate(0);
		Core::singleton().gameScene().gameData().Player1().setPosition(0);

		Core::singleton().gameScene().gameData().CPU().setActualPath(0);
		Core::singleton().gameScene().gameData().CPU().setActualGate(0);
		Core::singleton().gameScene().gameData().CPU().setPosition(50);

	}



	time=0;
}

void BezierCurve::creaTontets(){

	cPaths[0] = 0.25;
	cPaths[1] = 0.25;
	cPaths[2] = 0.25;// color del circuit


	cGates[0] = 0.35;
	cGates[1] = 0.35;
	cGates[2] = 0.35;// color dels gates


		for (int a=0;a<MAXAVATARS;a++){
			avatar[a]=0;
			actualPath[a]=0;
			sem[a]=0;

			acolor[a][0] = 1;
			acolor[a][1] = 1;
			acolor[a][2] = 1;
		}
		time=0;
	}


BezierCurve::BezierCurve() {


}
BezierCurve::~BezierCurve() {


}


void BezierCurve::drawPaths ()
{
 glCallList(DISP_PATHS);
}

void BezierCurve::drawGates ()
{
	glCallList(DISP_GATES);
}

void BezierCurve::displayListsGates (GLfloatPointArray P[MAXPATHS])
{
		glDeleteLists(DISP_GATES, 1);
	    glNewList(DISP_GATES, GL_COMPILE);
		int i, num;
		

		glLineWidth ( LINE_WEIGHT );
		glColor3fv(cGates);
		for (num = 0; num < numGates; num++) {
			glBegin(GL_LINE_STRIP);
			for (i = 0; i < P[num].num-1; i++) {
				// TODO Xapuza para no pinte gate en 0,0
				if((P[num].pt[i].x!=0)&&(P[num].pt[i].y!=0))
				glVertex2f(P[num].pt[i].x, P[num].pt[i].y);
			}
			glEnd();
		}

		glEndList();
}

//***************** BEZIER Curve subprograms
// Read the control points
void BezierCurve::readControlPointsFromPaths (Circuit &c,GLfloatPointArray &P,int i)
{
	int n=0;
	list<Cell> cells;
	cells = c.allCellsFromPath(i);
	for (list<Cell>::iterator it = cells.begin(); it != cells.end(); it++) {
		P.pt[n].x = it->x;
		P.pt[n].y = it->y;
		n++;
	}
	P.num = n;
}
void BezierCurve::readControlPointsFromGates (Circuit &c,GLfloatPointArray &P,int i)
{
	int n=0;
	list<Cell> cells;
	cells = c.allCellsFromGate(i);

	for (list<Cell>::iterator it = cells.begin(); it != cells.end(); it++) {

		P.pt[n].x = it->x;
		P.pt[n].y = it->y;
		n++;
	}
	P.num = n;

}
//helper routines - compute the coefficient
void BezierCurve::ComputeCoeff (int n)
{ int j,k;
  for (k=0;k<=n;k++)
  { //compute n! / (k!*(n-k)!)
	coef[k] = 1;
    for (j = n;j>=k+1;j--)
    	coef[k] *=j;
    for (j = n-k;j>=2;j--)
    	coef[k] /= j;
  }
}

// compute the blending value
float BezierCurve::BlendingValue (int n, int k, float t)
{ int j;
  float bv;
  // compute  c[k]*t^k * (1-t)^(n-k)
  bv = coef[k];
  for (j=1; j<=k;j++)
    bv *= t;
  for (j = 1;j<=n-k;j++)
    bv *= (1-t);
  return bv;
}

// compute one point on the Bezier curve - fixed value of t
void BezierCurve::ComputePoint (float t, int n, GLfloatPoint & p,
				   GLfloatPointArray ctrlPts)
{ int k;
  float b;
  p.x = 0.0;
  p.y = 0.0;
  for (k = 0; k<=n;k++)
  {  b = BlendingValue (n,k,t);
     p.x += ctrlPts.pt[k].x*b;
     p.y += ctrlPts.pt[k].y*b;
  }
}

// compute the array of Bezier points - drawing done separately
void BezierCurve::Bezier ( GLfloatPointArray controlPts, int numInter,
			  GLfloatPointArray & curve)
{ // there are numContPts+1 control points and numInter t values to evaluate the curve
  int k;
  float t;
  ComputeCoeff (controlPts.num-1);
  curve.num = numInter+1;
  for (k=0; k<=numInter; k++)
  { t = (float) k / (float) numInter;
    ComputePoint (t, controlPts.num-1,curve.pt[k],controlPts);
  }
}

void BezierCurve::create(){


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	creaTontets();
	creaJoc();



	numPaths = Core::singleton().gameScene().circuit().numPaths();
	for (int i = 0; i < numPaths; i++) {
		// read control points and draw them in red big points
		readControlPointsFromPaths(Core::singleton().gameScene().circuit(), ControlPts, i);
		// Compute the Bezier curve points and draw
		Bezier(ControlPts, MAX, circuitCurve[i]);
	}
	displayListsPath (circuitCurve);

	numGates = Core::singleton().gameScene().circuit().numGates();
	for (int i = 0; i < numGates; i++) {
		// read control points and draw them in red big points
		readControlPointsFromGates(Core::singleton().gameScene().circuit(), ControlPts, i);
		// Compute the Bezier curve points and draw
		Bezier(ControlPts, MAX, gatesCurve[i]);
	}
	displayListsGates(gatesCurve);




}

void BezierCurve::displayListsPath(GLfloatPointArray P[MAXPATHS]){
	glNewList(DISP_PATHS, GL_COMPILE);
	int i, num;

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

	glColor3fv(cPaths);
	glPointSize(LINE_WEIGHT);
	
	glBegin(GL_POINTS);
	for (num = 0; num < numPaths; num++) {

		for (i = 0; i < P[num].num - 1; i++) {
	
			glVertex2f(P[num].pt[i].x, P[num].pt[i].y);
			
		}
	}

	glEnd();
	glEndList();
}

void BezierCurve::swapGates(){

	Core::singleton().gameScene().circuit().swapGates();


	/////////////////cpu
	for (int i = 0; i < numGates; i++)
	{
		// read control points
		readControlPointsFromGates(Core::singleton().gameScene().circuit(), ControlPts,i);
		// Compute the Bezier curve points and draw
		Bezier(ControlPts, MAX, gatesCurve[i]);
	}
	displayListsGates(gatesCurve);
}


void BezierCurve::swapGatesCPU(){
	for (int a = 0; a < MAXAVATARS; a++) {
		actualGate[a]=Core::singleton().gameScene().circuit().getPathAt(actualPath[a]).getNextGate();
	}
}
void BezierCurve::swapGatesPLAYERS(){

	/////////////players

	if(Core::singleton().gameScene().gameData().getGameType()==_1P){

		int numBalls=Core::singleton().gameScene().gameData().Player1().getBalls().size();

		for(int k=0;k< numBalls;k++){
			int actualpath =Core::singleton().gameScene().gameData().Player1().getBallAt(k)->actualPath();
			int actualgate =Core::singleton().gameScene().circuit().getPathAt(actualpath).getNextGate();
			Core::singleton().gameScene().gameData().Player1().getBallAt(k)->setActualGate(actualgate);
		}
	}


   if(Core::singleton().gameScene().gameData().getGameType()==_2P){
	   for (int a = 0; a < MAXAVATARS; a++) {
	   		actualGate[a]=Core::singleton().gameScene().circuit().getPathAt(actualPath[a]).getNextGate();
	   	}
		int numBalls1=Core::singleton().gameScene().gameData().Player1().getBalls().size();

		for(int k=0;k< numBalls1;k++){
			int actualpath =Core::singleton().gameScene().gameData().Player1().getBallAt(k)->actualPath();
			int actualgate =Core::singleton().gameScene().circuit().getPathAt(actualpath).getNextGate();
			Core::singleton().gameScene().gameData().Player1().getBallAt(k)->setActualGate(actualgate);
		}

	   int numBalls2=Core::singleton().gameScene().gameData().Player2().getBalls().size();

		for(int k=0;k< numBalls2;k++){
			int actualpath =Core::singleton().gameScene().gameData().Player2().getBallAt(k)->actualPath();
			int actualgate =Core::singleton().gameScene().circuit().getPathAt(actualpath).getNextGate();
			Core::singleton().gameScene().gameData().Player2().getBallAt(k)->setActualGate(actualgate);
		}

	}

	if(Core::singleton().gameScene().gameData().getGameType()==_CPU){

		int numBalls1=Core::singleton().gameScene().gameData().Player1().getBalls().size();

		for(int k=0;k< numBalls1;k++){
			int actualpath =Core::singleton().gameScene().gameData().Player1().getBallAt(k)->actualPath();
			int actualgate =Core::singleton().gameScene().circuit().getPathAt(actualpath).getNextGate();
			Core::singleton().gameScene().gameData().Player1().getBallAt(k)->setActualGate(actualgate);
		}
		for (int a = 0; a < MAXAVATARS; a++) {
				actualGate[a]=Core::singleton().gameScene().circuit().getPathAt(actualPath[a]).getNextGate();
			}
	   int numBalls2=Core::singleton().gameScene().gameData().CPU().getBalls().size();

		for(int k=0;k< numBalls2;k++){
			int actualpath =Core::singleton().gameScene().gameData().CPU().getBallAt(k)->actualPath();
			int actualgate =Core::singleton().gameScene().circuit().getPathAt(actualpath).getNextGate();
			Core::singleton().gameScene().gameData().CPU().getBallAt(k)->setActualGate(actualgate);
		}

	}


}


void BezierCurve::drawPilotaTONTA(GLfloatPointArray P[MAXPATHS],GLfloatPointArray G[MAXPATHS]) {
	//hi posem la piloteta

	double py;
	double px;
	
	
	glPointSize(8);
	glBegin(GL_POINTS);
	
	for (int a = 0; a < MAXAVATARS; a++) {
		if (actualPath[a] != FINAL_CIRCUIT) {
			if (sem[a] == 0) {
				px = P[actualPath[a]].pt[avatar[a]].x;
				py = P[actualPath[a]].pt[avatar[a]].y;
			} else {
				px = G[actualGate[a]].pt[avatar[a]].x;
				py = G[actualGate[a]].pt[avatar[a]].y;

			}
		} else {
			px = -1;
			py = -1;

		}
		glColor3fv(acolor[a]);
		glVertex2f(px,py);
		
		
	}
	glEnd();
	
}

//ALGOTIMO DE SEGUIMIENTO DEL CIRCUITO
void BezierCurve::drawPilotaLLESTA() {
	//hi posem la piloteta
	int numballs;
	int actualpath;


	float px=0,py=0;

/////////////////////////////////// oneplayer

if(Core::singleton().gameScene().gameData().getGameType()==_1P){


	glColor3fv(Core::singleton().gameScene().gameData().Player1().getcolor());
	glPointSize(BALL_WEIGTH );
	glBegin(GL_POINTS);
	
		numballs =Core::singleton().gameScene().gameData().Player1().getBalls().size();

		for(int b=0;b<numballs;b++){

			Ball *ball = Core::singleton().gameScene().gameData().Player1().getBallAt(b);
			actualpath= ball->actualPath();

			if(actualpath!=FINAL_CIRCUIT){
				if(ball->getSemafor()==0){//if is in a path
					px = this->circuitCurve[actualpath].pt[ball->position()].x;
					py = this->circuitCurve[actualpath].pt[ball->position()].y;
				}else{//if is in a gate
					px = this->gatesCurve[ball->actualGate()].pt[ball->position()].x;	//if gate
					py = this->gatesCurve[ball->actualGate()].pt[ball->position()].y;
				}
			}

			glVertex2f(px,py);
		}
		glEnd();
		
}
////////////////////// one player


/////////////////////////////////// twoplayers

if(Core::singleton().gameScene().gameData().getGameType()==_2P){

	glPushMatrix();
	
	glPointSize(BALL_WEIGTH);
	glBegin(GL_POINTS);
	glColor3fv(Core::singleton().gameScene().gameData().Player1().getcolor());

		numballs =Core::singleton().gameScene().gameData().Player1().getBalls().size();

		for(int b=0;b<numballs;b++){

			Ball *ball = Core::singleton().gameScene().gameData().Player1().getBallAt(b);
			actualpath= ball->actualPath();

			if(actualpath!=FINAL_CIRCUIT){
				if(ball->getSemafor()==0){//if is in a path
					px = this->circuitCurve[actualpath].pt[ball->position()].x;
					py = this->circuitCurve[actualpath].pt[ball->position()].y;
				}else{//if is in a gate
					px = this->gatesCurve[ball->actualGate()].pt[ball->position()].x;	//if gate
					py = this->gatesCurve[ball->actualGate()].pt[ball->position()].y;
				}
			}

			glVertex2f(px,py);
		}
	glEnd();
	
	glPopMatrix();
	glPushMatrix();

	
	glPointSize(BALL_WEIGTH );
	glBegin(GL_POINTS);
	glColor3fv(Core::singleton().gameScene().gameData().Player2().getcolor());
		numballs =Core::singleton().gameScene().gameData().Player2().getBalls().size();

		for(int b=0;b<numballs;b++){

			Ball *ball = Core::singleton().gameScene().gameData().Player2().getBallAt(b);
			actualpath= ball->actualPath();

			if(actualpath!=FINAL_CIRCUIT){
				if(ball->getSemafor()==0){//if is in a path
					px = this->circuitCurve[actualpath].pt[ball->position()].x;
					py = this->circuitCurve[actualpath].pt[ball->position()].y;
				}else{//if is in a gate
					px = this->gatesCurve[ball->actualGate()].pt[ball->position()].x;	//if gate
					py = this->gatesCurve[ball->actualGate()].pt[ball->position()].y;
				}
			}

			glVertex2f(px,py);
		}
		glEnd();
		glPopMatrix();
	}

////////////////////// two player


/////////////////////////////////// VERSUS CPU

if(Core::singleton().gameScene().gameData().getGameType()==_CPU){

	glPushMatrix();
	
	glPointSize(BALL_WEIGTH);
	glBegin(GL_POINTS);
	glColor3fv(Core::singleton().gameScene().gameData().Player1().getcolor());

		numballs =Core::singleton().gameScene().gameData().Player1().getBalls().size();

		for(int b=0;b<numballs;b++){

			Ball *ball = Core::singleton().gameScene().gameData().Player1().getBallAt(b);
			actualpath= ball->actualPath();

			if(actualpath!=FINAL_CIRCUIT){
				if(ball->getSemafor()==0){//if is in a path
					px = this->circuitCurve[actualpath].pt[ball->position()].x;
					py = this->circuitCurve[actualpath].pt[ball->position()].y;
				}else{//if is in a gate
					px = this->gatesCurve[ball->actualGate()].pt[ball->position()].x;	//if gate
					py = this->gatesCurve[ball->actualGate()].pt[ball->position()].y;
				}
			}

			glVertex2f(px,py);
		}
	glEnd();
	
	glPopMatrix();
	glPushMatrix();

	
	glPointSize(BALL_WEIGTH );
	glBegin(GL_POINTS);
	glColor3fv(Core::singleton().gameScene().gameData().CPU().getcolor());
		numballs =Core::singleton().gameScene().gameData().CPU().getBalls().size();

		for(int b=0;b<numballs;b++){

			Ball *ball = Core::singleton().gameScene().gameData().CPU().getBallAt(b);
			actualpath= ball->actualPath();

			if(actualpath!=FINAL_CIRCUIT){
				if(ball->getSemafor()==0){//if is in a path
					px = this->circuitCurve[actualpath].pt[ball->position()].x;
					py = this->circuitCurve[actualpath].pt[ball->position()].y;
				}else{//if is in a gate
					px = this->gatesCurve[ball->actualGate()].pt[ball->position()].x;	//if gate
					py = this->gatesCurve[ball->actualGate()].pt[ball->position()].y;
				}
			}

			glVertex2f(px,py);
		}
		glEnd();
		glPopMatrix();
	}

////////////////////// VERSUS CPU


}

void BezierCurve::controlCPU(float elapsedtime) {

	static int espera = 0;

	Path p;
	time += elapsedtime;
	espera++;
	for (int a = 0; a < MAXAVATARS; a++) {
		if ((time > 0.2) && (espera > (a+1) * 200)) {

			avatar[a] += 1;//*(elapsedtime);//pilota
			if (avatar[a] >= MAX) {
				if (actualPath[a] != FINAL_CIRCUIT) {
					if (sem[a] == 0)
						p
								= Core::singleton().gameScene().circuit().getPathAt(
										actualPath[a]);
					else
						p
								= Core::singleton().gameScene().circuit().getGateAt(
										actualGate[a]);


					if (p.nextIsPath()) {
						actualPath[a] = p.getNextPath();
						sem[a] = 0;
					} else {
						actualGate[a] = p.getNextGate();
						sem[a] = 1;
					}

				}
				avatar[a] = 0;
				if (actualPath[a] == -1)
					actualPath[a] = 0;
			}

		}

	}


}



void BezierCurve::update()
{
	Core::singleton().gameScene().gameData().logica();


}


void BezierCurve::controlPLAYERS(float elapsedtime) {

	time+=elapsedtime;
	if (time >VELOCITY_AVATARS) {
		Core::singleton().gameScene().gameData().update();
		time=0;
	}


}
void BezierCurve::drawIcons(){
	
	for (int p=0;p<Core::singleton().gameScene().circuit().numPaths();p++){
		Path path = Core::singleton().gameScene().circuit().getPathAt(p);
		if(path.getEndType()==_KILLED){
			putDead(path.getEndCell().x,path.getEndCell().y);
		}
		if(path.getEndType()==_SAVED){
			putSaved(path.getEndCell().x,path.getEndCell().y);
		}

	}
	
	
}
void BezierCurve::draw()
{
	drawFondo();
	drawPaths();
    drawGates ();
	
	
	//pinta les pilotes del joc
	drawPilotaLLESTA();

	//pinta una pilota que despista
	//   drawPilotaTONTA(circuitCurve,gatesCurve);

	drawIcons();//icons de dead y se house 
	
	
	
}

