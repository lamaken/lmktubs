/*
 * Hud.h
 *
 *  Created on: 22/07/2011
 *      Author: alex
 */

#ifndef HUD_H_
#define HUD_H_


class Hud {
public:
	Hud();
	virtual ~Hud();

	void draw();
	void init();
	void incTime(float elapsedtime);
	int getTimeHud(){return ((int) timeHud);}

private:

	void drawTime();
	void drawDataPlayer1();
	void drawDataPlayer2();
	void drawDataCPU();


	float timeHud;
	
};

#endif /* HUD_H_ */
