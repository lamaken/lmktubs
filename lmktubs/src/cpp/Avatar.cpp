/*
 * Avatar.cpp
 *
 *  Created on: 19/07/2011
 *      Author: alex
 */

#include "Avatar.h"
#include "Core.h"
#include "BezierCurve.h"
#include "Cell.h"


void Avatar::KillBall(list<Ball>::iterator b){
		
	if(lives>1){
		 Core::singleton().soundManager().playKilled();
	}else{
		Core::singleton().soundManager().playOops();
		setTime(Core::singleton().gameScene().getHud().getTimeHud());
		}
	lives--;
}

void Avatar::SaveBall(list<Ball>::iterator b){
		
	//when last ball
	if(balls.size()>1){
		Core::singleton().soundManager().playSaved();

	}else{
	//when still remain more balls
		Core::singleton().soundManager().playYes();
	}
	ballsToDelete.push_back(b);
	points+=10*this->getLives();
}




void
Avatar::setColor(float r, float g, float b){
	color[0]=r;
	color[1]=g;
	color[2]=b;

	for (list<Ball>::iterator ball = balls.begin(); ball != balls.end(); ball++){
			ball->setColor(color[0],color[1],color[2]);
	}
}
void Avatar::reset(){
	balls.clear();
	ballsToDelete.clear();
	points=0;			//punts aconseguits
	lives=INIT_LIVES;			//vides que li queden
}


void Avatar::resetBalls(){
	balls.clear();
	ballsToDelete.clear();
}

Avatar::Avatar() {
	balls.clear();
	ballsToDelete.clear();
	

}
void Avatar::addBall(){
		Ball newBall;
		newBall.setUnique(Core::singleton().gameScene().uniqueBall());
		int rnd = rand() % 200 + 1;
		newBall.delay=newBall.getUnique()*rnd;
		balls.push_back(newBall);}

Avatar::~Avatar() {
}

void Avatar::updateBalls(){

	//elimina les que estan a la llista de balls to delete
	for (	list<list<Ball>::iterator>::iterator it = ballsToDelete.begin();
			it != ballsToDelete.end();
			it++){
		balls.erase(*it);
	}
	ballsToDelete.clear();
}
Ball *Avatar::getBallAt(int i){
	int n=0;
	for (list<Ball>::iterator it = balls.begin(); it != balls.end(); it++){
			if(n++==i)return(&*it);
		}
	return(NULL);
}

//la logica hauria d'estar en un arxiu del IA
void Avatar::logica() {

	Path p;
	int offs;
	int actualPath;
	typeEndCell typeEnd;
	typeEndCell typeBegin;
	bool needUpdateBalls = false;


	for (list<Ball>::iterator ball = balls.begin(); ball != balls.end(); ball++) {


		offs = ball->position();

		if (offs >= MAX) { //max balls per path

		////////guardo paths per on va passant
			if(ball->getSemafor()==0){
				this->buclepaths.push_back(Core::singleton().gameScene().circuit().getPathAt(ball->actualPath()));
			}else{
					this->buclepaths.push_back(Core::singleton().gameScene().circuit().getGateAt(ball->actualGate()));
			}
		/////////

			actualPath = ball->actualPath();

			if (actualPath != FINAL_CIRCUIT) {

				//calculem el seguent path o gate que ha d'agafar
				if (ball->getSemafor() == 0) {
					p = Core::singleton().gameScene().circuit().getPathAt(actualPath);
				} else {
					p = Core::singleton().gameScene().circuit().getGateAt(
							ball->actualGate());
				}

				////mirem si passa alguna cosa
				if (ball->getSemafor() == 0) {
					typeBegin = Core::singleton().gameScene().circuit().getPathAt(
							ball->actualPath()).getBeginType();
					typeEnd = Core::singleton().gameScene().circuit().getPathAt(
							ball->actualPath()).getEndType();

					switch (typeBegin) {
					case _START:
							Core::singleton().soundManager().playStart();
						break;
					case  _NONE:
						//this->setPoints(this->getPoints()+1);
						break;
					default:
						break;
					}

				switch (typeEnd) {
					case _SAVED:
						this->SaveBall(ball);
						needUpdateBalls = true;
						break;
					case _KILLED:
						this->KillBall(ball);
						needUpdateBalls = true;
						break;
					case  _NONE:
						//this->setPoints(this->getPoints()+1);
						break;
					default:
						//cout << "end not defined" << endl;
						break;
					}
				}

				/////////////////////////////////////////// update ball
				if (p.nextIsPath()) {
					ball->setActualPath(p.getNextPath());
					ball->setSemafor(0);
				} else {
					ball->setActualGate(p.getNextGate());
					ball->setSemafor(1);
				}
				ball->setPosition(0);
				///////////////////////////////////////// update ball

			}

			if (ball->actualPath() == -1) {//torna a començar
				ball->setActualPath(0);
			}
		}

	}

	if (needUpdateBalls)
		this->updateBalls();//eliminem les boles mortes i finalitzades


}
void Avatar::update(){
	for (list<Ball>::iterator it = balls.begin(); it != balls.end(); it++){


		//TODO: calcul del retard

		if(it->delay<Core::singleton().gameScene().gameData().gameCounter)
		{
//				if(Core::singleton().gameScene().gameData().canUpdate(it)){
					it->setPosition(it->position()+1);
		//}
		}			
	}
}
void Avatar::setPosition(int a){
	for (list<Ball>::iterator it = balls.begin(); it != balls.end(); it++){
			it->setPosition(a);
		}
}

void Avatar::setActualGate(int a){
	for (list<Ball>::iterator it = balls.begin(); it != balls.end(); it++){
			it->setActualGate(a);

		}
}
void Avatar::setActualPath(int a){

	for (list<Ball>::iterator it = balls.begin(); it != balls.end(); it++){
			it->setActualPath(a);

		}
}

void Avatar::checkToSwap(){//IA




	//RECUPERA LA BOLA QUE ESTA MES LUNY EN EL PATH
	int max=0;
	int id=-1;
	Path p;
	int i=0;
	static int counter=0;

	
	bool swap=false;
	//aqui miramos si entra en un bucle
	for (list<Ball>::iterator it = balls.begin(); it != balls.end(); it++){
		for (list<Path>::iterator it2 = buclepaths.begin(); it2 != buclepaths.end(); it2++){
			if(it->getSemafor()==0){
				if( it2->getId() == Core::singleton().gameScene().circuit().getPathAt(it->actualPath()).getId() ){
					swap=true;	
					counter++;
				}
			}
			else {
				if(it2->getId()==Core::singleton().gameScene().circuit().getGateAt(it->actualGate()).getId()){
					swap=true;
					counter++;
				}
			}
		}
		id++;
	}

	
	if((swap)&&(counter>1200)){
		buclepaths.clear();	
		if(Core::singleton().gameScene().getHud().getTimeHud()%2==0){
				Core::singleton().gameScene().keyboard('s',0,0);	
			}
		counter=0;
	}
	
	id=-1;
	


	//aqui buscamos la salida
	Path path;
	Path gate;
	int num=-1;

	for (list<Ball>::iterator it = balls.begin(); it != balls.end(); it++){
			if(it->getSemafor()==0)
				{	
				path = Core::singleton().gameScene().circuit().getPathAt(it->actualPath());


					for (list<int>::iterator it2 = path.nextGates.begin(); it2 != path.nextGates.end(); it2++){

						gate = Core::singleton().gameScene().circuit().getGateAt(*it2);

						if ( Core::singleton().gameScene().circuit().getPathAt( gate.getNextPath() ).getEndCell().getTypeEnd()==_SAVED ) {
							num = gate.getActiveGate();
							}
						}
				} 
		}
	if(num>=0){
		for (int k=0;k<num;k++)Core::singleton().gameScene().keyboard('s',0,0);	
	}
	


	//aqui miramos si el siguiente es la muerte
	for (list<Ball>::iterator it = balls.begin(); it != balls.end(); it++){
		if((it->position()>max)&&(it->getSemafor()==1)){//la mes gran que estigui en un gate
			max = it->position();
			id =i;// it->getUnique();
		}
		i++;
	}
	if(id!=-1){
		if(Core::singleton().gameScene().circuit().getPathAt(Core::singleton().gameScene().circuit().getGateAt(getBallAt(id)->actualGate()).getNextPath()).getEndCell().getTypeEnd()==_KILLED){
			
			if(Core::singleton().gameScene().getHud().getTimeHud()%2==0){
				Core::singleton().gameScene().keyboard('s',0,0);	
			}
			
		}
	}

	}
