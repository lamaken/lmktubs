/*
 * GameData.cpp
 *
 *  Created on: 19/07/2011
 *      Author: alex
 */

#include "GameData.h"
#include "Core.h"

GameData::GameData() {


}

GameData::~GameData() {

}
void GameData::endGame(){
	
	//end game to true
	swapGameEnd();

	//cargamos las puntuaciones
	Core::singleton().gameScene().gameEnded().loadFileRecords();
	Core::singleton().gameScene().gameEnded().showlevel=level;

	switch(gameType){
	case _1P:
		
		if(Core::singleton().gameScene().gameEnded().checkRecord(gameType,level,A1P.getPoints(),A1P.getTime()))
		{
			Core::singleton().gameScene().gameEnded().enterNewRecord("Player1");	
		}

		break;

	case _2P:
		
			Core::singleton().gameScene().gameEnded().checkTwoPlayersRecord(gameType,level,A1P.getPoints(),A1P.getTime(),gameType,level,A2P.getPoints(),A2P.getTime());

			break;
	case _CPU:
				
				if(Core::singleton().gameScene().gameEnded().checkRecord(gameType,level,ACPU.getPoints(),ACPU.getTime()))
				{
				Core::singleton().gameScene().gameEnded().enterNewRecord("Computer");
				}
			
				
				if(Core::singleton().gameScene().gameEnded().checkRecord(gameType,level,A1P.getPoints(),A1P.getTime()))
				{
				Core::singleton().gameScene().gameEnded().enterNewRecord("Player1");
				}
				


			break;
	default:
			//error gametype not found
			break;
	}
	
}
void GameData::nextLevel(){


	Core::singleton().gameScene().resetUniqueBall();

	this->sublevel ++;
	this->gameCounter=0;
	switch(gameType){
	case _1P:
			A1P.resetBalls();//las eliminamos
			for(int n=0;n<sublevel+1;n++)A1P.addBall();
			break;
	case _2P:
			A1P.resetBalls();
			A2P.resetBalls();
			
			if(A1P.getLives()>0)for(int n=0;n<sublevel+1;n++)A1P.addBall();
			if(A2P.getLives()>0)for(int n=0;n<sublevel+1;n++)A2P.addBall();

			break;
	case _CPU:
			A1P.resetBalls();
			ACPU.resetBalls();
			
			if(A1P.getLives()>0)for(int n=0;n<sublevel+1;n++)A1P.addBall();
			if(ACPU.getLives()>0)for(int n=0;n<sublevel+1;n++)ACPU.addBall();
			break;
	default:
			//error gametype not found
			break;
	}

}

void GameData::createGame(int level,int gtype){

	this->level = level;
	this->sublevel =0 ;
	this->gameType = gtype;
	this->velocity=0;
	this->gameCounter=0;
	this->m_paused=true;
	this->m_gameEnded=false;

	switch(gameType){
	case _1P:
			numAvatars=1;
			A1P.init();
			A1P.addBall();
			A1P.setColor(1.0,0.6,0.2);
			break;
	case _2P:
			numAvatars=2;
			A1P.init();
			A1P.addBall();
			A1P.setColor(1.0,0.6,0.2);
			
			A2P.init();
			A2P.addBall();
			A2P.setColor(0.0,0.6,0.0);
			break;
	case _CPU:
			numAvatars=2;
			A1P.init();
			A1P.addBall();
			A1P.setColor(1.0,0.6,0.2);
			
			ACPU.init();
			ACPU.addBall();
			ACPU.setColor(0.0,0.6,0.0);
			break;
	default:
			//error gametype not found
			break;
	}

}

//controla el recorregut pel circuit
void GameData::logica(){
	
	
	
	
	
	switch(gameType){
	case _1P:
			//one player.//////////////////////
			if(A1P.getLives()>0){
				
				if(A1P.getBalls().size()==0){
					Core::singleton().gameScene().gameData().swapPaused();
					Core::singleton().gameScene().pause().setText("Press SPACE to next level");
					nextLevel();
				}
				else A1P.logica();
			}else{
				//endgame player1solo
				
				endGame();

			}
			//one player.//////////////////////
			break;
	case _2P:
			//two players.//////////////////////
			if(A1P.getLives()>0){	
							
				A1P.logica();

				

			}else{

				if(!A1P.isDead()){
					A1P.setDead(true);
				 	A1P.getBalls().clear();
					
					if(!A2P.isDead()){//si el segon no esta mort
						Core::singleton().soundManager().playBye();
						}

					}
			}

			if(A2P.getLives()>0){   
				A2P.logica();
				
				
			}else{
				//endgame player2
				//addrecord
				if(!A2P.isDead()){
					A2P.setDead(true);
					A2P.getBalls().clear();
					if(!A1P.isDead()){//si el primer no esta mort
						Core::singleton().soundManager().playBye();
						}

					}
			}
			
			//si ja no queden pilotes ni pel player 1 ni pel 2 pasem al seguent joc
			if((A1P.getBalls().size()==0)&&(A2P.getBalls().size()==0)){
				Core::singleton().gameScene().gameData().swapPaused();
				Core::singleton().gameScene().pause().setText("Press SPACE to next level");
				nextLevel();//si un dels dos esta mort passem al seguent nivell
			}


			if((A1P.getLives()==0)&&(A2P.getLives()==0)){	//si no queden vides passem al menu
				endGame();
			}

			///////////
			//actualitzem tots els ids
			///////////


			//two players.//////////////////////
			break;
	case _CPU:
			////////////////// LOGICA CPU
		if(A1P.getLives()>0){	
							
				A1P.logica();

				

			}else{

				if(!A1P.isDead()){
					A1P.setDead(true);
				 	A1P.getBalls().clear();
					
					if(ACPU.isDead()){//si el segon no esta mort
						Core::singleton().soundManager().playBye();
						}

					}
			}

			if(ACPU.getLives()>0){   

				ACPU.checkToSwap();
				//de tots els gates que el seguent es un path kill
				//de la posicio mes elevada swap
				//sino, si seguent es saved swap

				ACPU.logica();
				
				
			}else{
				//endgame player2
				//addrecord
				if(!ACPU.isDead()){
					ACPU.setDead(true);
					ACPU.getBalls().clear();
					if(!A1P.isDead()){//si el primer no esta mort
						Core::singleton().soundManager().playBye();
						}

					}
			}
			
			//si ja no queden pilotes ni pel player 1 ni pel 2 pasem al seguent joc
			if((A1P.getBalls().size()==0)&&(ACPU.getBalls().size()==0)){
				Core::singleton().gameScene().gameData().swapPaused();
				Core::singleton().gameScene().pause().setText("Press SPACE to next level");
				nextLevel();//si un dels dos esta mort passem al seguent nivell
			}


			if((A1P.getLives()==0)&&(ACPU.getLives()==0)){	//si no queden vides passem al menu
				endGame();
			}

			////////////////// LOGICA CPU
			break;
	default:

			
			//error gametype not found
			break;
	}
		
}



/////// aumenta una posicio als avatars
void GameData::update(){

	
	gameCounter++;

	switch(gameType){
	case _1P:
			//one player.//////////////////////
			if(A1P.getLives()>0){
				A1P.update();
			}else{
			}

			//one player.//////////////////////
			break;
	case _2P:
			if(A1P.getLives()>0){
				A1P.update();
			}else{
			}
			if(A2P.getLives()>0){
				A2P.update();
			}else{
			}
			//deprecated updateUniques();
			break;
	case _CPU:
			if(A1P.getLives()>0){
				A1P.update();
			}else{
			}
			if(ACPU.getLives()>0){
				ACPU.update();
			}else{
			}
			break;
	default:
			//error gametype not found
			break;
	}
	
}



/*
//mira si la bola que li passem pot avan�ar
//deprecated
bool GameData::canUpdate(list<Ball>::iterator it){
		
	bool canMove=true;
	int gopactual;//gate o path actual

	if(it->getSemafor()==0)gopactual=it->actualPath();
	else gopactual=it->actualGate();
	
					
	int newpos= it->position()+1;
	int ofs1 = newpos-50;
	int ofs2 = newpos+50;

	if(ofs1<0)ofs1=0;
	if(ofs2>MAX)ofs2=MAX;


	switch(gameType){
	case _1P:
			//one player.//////////////////////
			if(A1P.getLives()>0)
			for (list<Ball>::iterator it2 = A1P.getBalls().begin(); it2 != A1P.getBalls().end(); it2++){
				
			if(it2->getUnique()>it->getUnique()){

				if(it2->getSemafor()==0){
					if(it2->actualPath()==gopactual){ //si es troben en el mateix path
						if( (ofs1<=it2->position())&&(it2->position()<=ofs2)   )	canMove=false;
					}
				
				}else{
					if(it2->actualGate()==gopactual){ //si es troben en el mateix path
						if( (ofs1<=it2->position())&&(it2->position()<=ofs2)   )	canMove=false;
					}
				}
			}	
			}
			//one player.//////////////////////
			break;
	case _2P:
		if(A1P.getLives()>0)
		for (list<Ball>::iterator it2 = A1P.getBalls().begin(); it2 != A1P.getBalls().end(); it2++){
				
			if(it2->getUnique()>it->getUnique()){

				if(it2->getSemafor()==0){
					if(it2->actualPath()==gopactual){ //si es troben en el mateix path
						if( (ofs1<=it2->position())&&(it2->position()<=ofs2)   )	canMove=false;
					}
				
				}else{
					if(it2->actualGate()==gopactual){ //si es troben en el mateix path
						if( (ofs1<=it2->position())&&(it2->position()<=ofs2)   )	canMove=false;
					}
				}
			}	
			}
		if(A2P.getLives()>0)
		for (list<Ball>::iterator it2 = A2P.getBalls().begin(); it2 != A2P.getBalls().end(); it2++){
				
			if(it2->getUnique()>it->getUnique()){

				if(it2->getSemafor()==0){
					if(it2->actualPath()==gopactual){ //si es troben en el mateix path
						if( (ofs1<=it2->position())&&(it2->position()<=ofs2)   )	canMove=false;
					}
				
				}else{
					if(it2->actualGate()==gopactual){ //si es troben en el mateix path
						if( (ofs2<=it2->position())&&(it2->position()<=ofs2)   )	canMove=false;
					}
				}
			}	
			}
		
			break;
	case _CPU:
			break;
	default:
			//error gametype not found
			break;
	}
	//canMove=true;
	return canMove;
}


void GameData::updateUniques(){

	
	int gopactual;//gate o path actual
	
	int unique=0;

	switch(gameType){


	case _1P:
			//one player.//////////////////////
			if(A1P.getLives()>0)
			for (list<Ball>::iterator it2 = A1P.getBalls().begin(); it2 != A1P.getBalls().end(); it2++){
				
				if(it2->getSemafor()==0)gopactual=it2->actualPath();
				else gopactual=it2->actualGate();
		
				it2->setUnique((gopactual+1)*33+(unique++));
					
				
				
			}
			//one player.//////////////////////
			break;
	case _2P:
			
			if(A1P.getLives()>0)
			for (list<Ball>::iterator it2 = A1P.getBalls().begin(); it2 != A1P.getBalls().end(); it2++){

			if(it2->getSemafor()==0)gopactual=it2->actualPath();
			else gopactual=it2->actualGate();				
			
			it2->setUnique((gopactual+1)*33+(unique++));
				
			}
		
			if(A2P.getLives()>0)
			for (list<Ball>::iterator it2 = A2P.getBalls().begin(); it2 != A2P.getBalls().end(); it2++){

				if(it2->getSemafor()==0)gopactual=it2->actualPath();
				else gopactual=it2->actualGate();
				
				it2->setUnique((gopactual+1)*33+(unique++));	
			}
			break;
	case _CPU:
			break;
	default:
			//error gametype not found
			break;
	}

}
*/
