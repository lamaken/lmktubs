//============================================================================
// Name        : lmktubs.cpp
// Author      : Alex Camps Mezquita
// Version     : 0.1
// Email       : acampsme@uoc.edu
// Description : Easy Game
//============================================================================


#include "Core.h"


#include <ctime>


using namespace std;

#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 512

int factorX=512;
int factorY=512;

void init(void)
{
 glPixelStorei(GL_UNPACK_ALIGNMENT,1);
 glClearColor(0.0,0.0,0.0,0.0);

 Core::singleton().init();

}
void mousePosition(int mx, int my){

	int posX=mx*512/factorX;
	int posY=my*512/factorY;

	
	Core::singleton().setMousePosition(posX,posY);
}

void pressMouse(int button, int state, int x, int y){

  Core::singleton().pressMouseScene(button,state,x,y);
}

void pressKey(unsigned char key, int x, int y){

	Core::singleton().keyPressScene(key, x, y);
}

//Esta funcion se llama cuando el sistema no hace nada
void idle()
{
	//Vamos a repintar cada cierto numero de frames
	//Miramos el reloj del sistema
	static clock_t lastTime = clock();
	
	clock_t now = clock();

	//Miramos cuanto tiempo ha pasado desde la ultima vez que se ha ejecutado esta funcion
	float elapsedTime = (float) (now - lastTime) / (float) 1000000;
	
	lastTime = now;

	//Llamamos al modulo de control a ver que acciones se han tomado
	Core::singleton().controlScene(elapsedTime);
	
	static float accumDraw = 0;
	accumDraw += elapsedTime;
	if(accumDraw>=0.004){
		glutPostRedisplay();
		accumDraw=0;
	}
}

void reshape(int w, int h)
{
	factorX=w;
	factorY=h;
	
	glViewport(0, 0, w, h);///margin for de hud
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	Core::singleton().drawScene();
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char** argv) {

cout<<"	----------------------------------------------"<<endl;
cout<<"	lmktubs v0.2 --------- linux version ---------"<<endl;
cout<<"	----------------------------------------------"<<endl;
cout<<"	  Mouse for the menus.              --------"<<endl;
cout<<"	  ESC returns to menu.              --------"<<endl;
cout<<"	  SPACE pause the game .            --------"<<endl;
cout<<"	  Any other key to swap the gates.  --------"<<endl;
cout<<"	----------------------------------------------"<<endl;
cout<<"	 Enjoy. ------------------------------------"<<endl;
cout<<"	----------------------------acampsme@uoc.edu-"<<endl;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
	glutInitWindowPosition(500,0);

	glutCreateWindow("lmktubs v0.2");
	init();

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(pressKey);
	glutMouseFunc(pressMouse);
	glutPassiveMotionFunc(mousePosition);
	glutMainLoop();




/* to reset scores
*/
/*	GameEnded end;
	
	end.init();
	//end.prepare();
	end.loadFileRecords();	
	if(end.checkRecord(0,3,30,10)){
			end.enterNewRecord("test");
			end.sort();
			end.refreshtop10();
		}
	
	end.draw();
*/
	//end.saveFileRecord();
	


	return 0;
}

