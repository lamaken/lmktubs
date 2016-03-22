/*
 * GameEnded.h
 *
 *  Created on: 22/07/2011
 *      Author: alex
 */

#ifndef GAMEENDED_H_
#define GAMEENDED_H_


#include <list>
#include <iostream>

using namespace std;

#define NUMCIRCUITS 3
#define FILE_NAME "resources/scores/top10.score"


struct top10score
{
	char playerName[10];
	int type;
	int level;
	int points;
	int counter;
};

 
bool compare(top10score first,top10score second);

class GameEnded
	{
	public:
		GameEnded(void);
		~GameEnded(void);

		void drawS();
		void drawScores();
		void drawRecord();

		void keypress(unsigned char key);
		void saveFileRecord();
		void loadFileRecords();
		void init();
		void prepare();
		
		bool checkRecord(int typef, int level, int points, int counter);
		void checkTwoPlayersRecord(int typef, int level, int points, int counter,int typef2, int level2, int points2, int counter2);



		void enterNewRecord(char *name);

		void refreshtop10();

		void update(float elapsedtime);
		
		void sort();
		int showlevel;//circuit que mostra
	private:
		
		
		void loadEndPNG();
		int numplayerrecord;

		list<top10score> toSort;
		int m_textureId_scores;
		int m_textureId_newrecord;

		top10score data2;
		top10score data3;


		//////////
		int r_type;
		int r_level;
		int r_points;
		int r_counter;
		char r_player[10];

		bool newrecord;
		char nick[10];
		
		float wait;//temps que mostra la pantalla de records

	};
#endif