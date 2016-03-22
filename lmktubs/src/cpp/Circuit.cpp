/*
 * Circuit.cpp
 *
 *  Created on: 11/07/2011
 *      Author: alex
 */

#include "Circuit.h"
#include <iostream>

#define MAXPATHS 150
#define MAXGATES 150

Circuit::Circuit() {

}

Circuit::~Circuit() {
}

bool Circuit::loadCircuit(int level){

	Paths.clear();
	Gates.clear();
	switch (level){
		case 1:
			loadOne();
			break;
		case 2:
			loadTwo();
			break;
		case 3:
			loadThree();
			break;
		default:break;
	}
	
	return(true);
}

void Circuit::pushPath(Path p, string id){
	p.num=(int) Paths.size();
	p.setId(id);
	Paths.push_back(p);
}
void Circuit::pushGate(Path p, string id, unsigned int active, unsigned int maxgates){
	p.num=(int) Gates.size();
	p.setActiveGate(active);
	p.setId(id);
	p.setNumGroup(maxgates);
	Gates.push_back(p);




}
void Circuit::loadTwo(){

	Path p[MAXPATHS];

	p[0].addStart(0.9,0);
	p[0].addCell(0.6,0);
	pushPath(p[0],"a");

	p[1].addCell(0.3,0.25);
	p[1].addCell(0,0.55);
	p[1].addCell(0.35,0.8);
	p[1].addCell(0.8,0.65);
	p[1].addCell(0.8,0.45);
	p[1].addCell(0.245,0.45);
    pushPath(p[1],"b");


	p[2].addCell(0.4,0.0);
	p[2].addCell(0.1,0.0);
	pushPath(p[2],"c");

	p[3].addCell(0.1,0.0);
	p[3].addCell(-0.2,0.0);
	pushPath(p[3],"d");

	p[4].addCell(-0.2,0.0);
	p[4].addCell(-0.35,0.0);
	pushPath(p[4],"e");
	
	p[5].addCell(0.155,0.45);
	p[5].addCell(-0.2,0.45);
	pushPath(p[5],"f");

	p[6].addCell(-0.2,0.45);
	p[6].addCell(-0.45,0.45);
	pushPath(p[6],"g");

	p[7].addCell(-0.8,0.45);
	p[7].addKill(-0.9,0.45);//				<--------MUERTE SI LLEGA AQUI
	pushPath(p[7],"h");

	p[8].addCell(-0.2,0.2);
	p[8].addCell(0,0.3);
	p[8].addCell(-0.2,0.45);
	pushPath(p[8],"i");


	p[9].addCell(-0.85,0.2);
	p[9].addCell(-0.85,-0.15);
	p[9].addCell(-0.65,-0.4);
	pushPath(p[9],"j");

	p[10].addCell(-0.65,-0.4);
	p[10].addCell(-0.55,-0.5);
	p[10].addCell(-0.4,-0.55);
	pushPath(p[10],"k");

	p[11].addCell(-0.5,0);
	p[11].addCell(-0.65,0);
	p[11].addCell(-0.65,-0.4);
	pushPath(p[11],"l");

	p[12].addCell(-0.2,-0.45);
	p[12].addCell(0,-0.25);
	p[12].addCell(-0.2,0);
	pushPath(p[12],"m");

	p[13].addCell(-0.3,-0.75);
	p[13].addCell(-0.35,-0.85);
	p[13].addCell(-0.6,-0.85);
	pushPath(p[13],"n");

	p[14].addCell(0.15,-0.2);
	p[14].addCell(0.2,-0.1);
	p[14].addCell(0.1,0);
	pushPath(p[14],"o");

	p[15].addCell(0.35,-0.3);
	p[15].addCell(0.3,-0.35);
	pushPath(p[15],"p");

	p[16].addCell(0.4,-0.25);
	p[16].addCell(0.35,-0.3);
	pushPath(p[16],"q");

	p[17].addCell(0.3,-0.65);
	p[17].addCell(0.55,-0.2);
	p[17].addCell(0.35,-0.3);
	pushPath(p[17],"r");

	p[18].addCell(-0.55,-0.95);
	p[18].addCell(0.2,-0.9);
	p[18].addCell(0.3,-0.65);
	pushPath(p[18],"s");

	p[19].addCell(-0.7,-0.85);
	p[19].addEnd(-0.9,-0.85);//				<<----------------- saved si llega aqui
	pushPath(p[19],"t");




	Path g[MAXGATES];//gates o compuertas
	g[0].addCell(0.6,0.0);
	g[0].addCell(0.3,0.25);

	g[1].addCell(0.6,0.0);
	g[1].addCell(0.4,0.0);

	g[2].addCell(0.6,0.0);
	g[2].addCell(0.4,-0.25);

	pushGate(g[0],"gA",1,3);//els gates amb el mateix nom s'intercanvien al premer una tecla
	pushGate(g[1],"gA",1,3);
	pushGate(g[2],"gA",1,3);

	g[3].addCell(0.3,-0.35);
	g[3].addCell(0.1,-0.45);
	g[3].addCell(0.15,-0.2);

	g[4].addCell(0.3,-0.35);
	g[4].addCell(-0.1,-0.85);
	g[4].addCell(0.3,-0.65);

	pushGate(g[3],"gP",0,2);//els gates amb el mateix nom s'intercanvien al premer una tecla
	pushGate(g[4],"gP",0,2);

	g[5].addCell(-0.45,0.45);
	g[5].addCell(-0.8,0.45);

	g[6].addCell(-0.45,0.45);
	g[6].addCell(-0.85,0.45);
	g[6].addCell(-0.85,0.2);

	pushGate(g[5],"gG",0,2);//els gates amb el mateix nom s'intercanvien al premer una tecla
	pushGate(g[6],"gG",0,2);


	g[7].addCell(-0.35,0.0);
	g[7].addCell(-0.55,0.0);
	g[7].addCell(-0.2,0.2);

	g[8].addCell(-0.35,0.0);
	g[8].addCell(-0.5,0);

	pushGate(g[7],"gE",0,2);//els gates amb el mateix nom s'intercanvien al premer una tecla
	pushGate(g[8],"gE",0,2);


	g[9].addCell(-0.4,-0.55);
	g[9].addCell(-0.3,-0.55);
	g[9].addCell(-0.2,-0.45);

	g[10].addCell(-0.4,-0.55);
	g[10].addCell(-0.25,-0.6);
	g[10].addCell(-0.3,-0.75);

	pushGate(g[9],"gK",0,2);//els gates amb el mateix nom s'intercanvien al premer una tecla
	pushGate(g[10],"gK",0,2);


	g[11].addCell(-0.6,-0.85);
	g[11].addCell(-0.7,-0.85);

	g[12].addCell(-0.6,-0.85);
	g[12].addCell(-0.7,-0.85);
	g[12].addCell(-0.7,-0.95);
	g[12].addCell(-0.55,-0.95);

	pushGate(g[11],"gN",0,2);//els gates amb el mateix nom s'intercanvien al premer una tecla
	pushGate(g[12],"gN",0,2);



//followers (andeva!)


	getPathById("a")->setNextGate(getGateById("gA",1)->num);
	getPathById("a")->setNextGate(getGateById("gA",2)->num);
	getPathById("a")->setNextGate(getGateById("gA",0)->num);
	
	getGateById("gA",0)->setNextPath(getPathById("b")->num);
	getPathById("b")->setNextPath(getPathById("f")->num);
	getPathById("f")->setNextPath(getPathById("g")->num);

	getPathById("g")->setNextGate(getGateById("gG",0)->num);
	getPathById("g")->setNextGate(getGateById("gG",1)->num);
	
	getGateById("gG",0)->setNextPath(getPathById("h")->num);
	getPathById("h")->setNextPath(getPathById("a")->num);		//<<<<<<<<<<<<<<< muerte
	getGateById("gG",1)->setNextPath(getPathById("j")->num);
	getPathById("j")->setNextPath(getPathById("k")->num);

	getPathById("k")->setNextGate(getGateById("gK",0)->num);
	getPathById("k")->setNextGate(getGateById("gK",1)->num);
	getGateById("gK",0)->setNextPath(getPathById("m")->num);
	getPathById("m")->setNextPath(getPathById("e")->num);		
	getGateById("gK",1)->setNextPath(getPathById("n")->num);
	getPathById("n")->setNextGate(getGateById("gN",0)->num);
	getPathById("n")->setNextGate(getGateById("gN",1)->num);


	
	getGateById("gN",0)->setNextPath(getPathById("t")->num);
	getGateById("gN",1)->setNextPath(getPathById("s")->num);

	getPathById("s")->setNextPath(getPathById("r")->num);


	getGateById("gA",1)->setNextPath(getPathById("c")->num);
	getPathById("c")->setNextPath(getPathById("d")->num);
	getPathById("d")->setNextPath(getPathById("e")->num);

	getPathById("e")->setNextGate(getGateById("gE",0)->num);
	getPathById("e")->setNextGate(getGateById("gE",1)->num);
	
	getGateById("gE",0)->setNextPath(getPathById("i")->num);
	getPathById("i")->setNextPath(getPathById("g")->num);

	getGateById("gE",1)->setNextPath(getPathById("l")->num);
	getPathById("l")->setNextPath(getPathById("k")->num);

	getGateById("gA",2)->setNextPath(getPathById("q")->num);

	getPathById("q")->setNextPath(getPathById("p")->num);
	
	getPathById("p")->setNextGate(getGateById("gP",0)->num);
	getPathById("p")->setNextGate(getGateById("gP",1)->num);
	
	getGateById("gP",1)->setNextPath(getPathById("r")->num);
	getPathById("r")->setNextPath(getPathById("p")->num);
	getGateById("gP",0)->setNextPath(getPathById("o")->num);
	getPathById("o")->setNextPath(getPathById("d")->num);

	getPathById("t")->setNextPath(FINAL_CIRCUIT);//d->a

}
void Circuit::loadOne(){

	Path p[MAXPATHS];

	p[0].addStart(-0.9,0);
	p[0].addCell(-0.4,-0.0);
	pushPath(p[0],"a");

	p[1].addCell(-0.4,-0.0);
	p[1].addCell(-0.1,-0.0);
	pushPath(p[1],"b");

	p[2].addCell(0.0,0.2);
	p[2].addCell(0.5,0.2);
	p[2].addCell(0.5,0.2);
	p[2].addCell(0.7,0.4);
	p[2].addCell(0.5,0.6);
	p[2].addCell(0.0,0.6);
	p[2].addCell(-1,0.6);
	p[2].addCell(-0.4,0);
	pushPath(p[2],"c");

	p[3].addCell(0.0,-0.2);
	p[3].addCell(0.5,-0.2);
	//p[3].addCell(0.7,0.0);
	p[3].addCell(0.5,0.0);
	pushPath(p[3],"d");


    p[4].addCell(0.7,0);
	p[4].addEnd(0.9,0);
	pushPath(p[4],"f");

	p[5].addCell(0.65,0.15);
	//p[5].addCell(0.8,0.15);
	p[5].addKill(0.9,0.6);
	pushPath(p[5],"e");



	Path g[MAXGATES];//gates o compuertas
	
	
	g[0].addCell(-0.1,-0.0);
	g[0].addCell(0.0,0.2);

	g[1].addCell(-0.1,-0.0);
	g[1].addCell(0.0,-0.2);

	pushGate(g[0],"gA",0,2);//els gates amb el mateix nom s'intercanvien al premer una tecla
	pushGate(g[1],"gA",0,2);
	

	g[2].addCell(0.5,0.0);
	g[2].addCell(0.7,0);

	g[3].addCell(0.5,0.0);
	g[3].addCell(0.65,0.15);
	
	
	pushGate(g[2],"gB",0,2);
	pushGate(g[3],"gB",0,2);

	getPathById("a")->setNextPath(getPathById("b")->num);//a->b


	getPathById("b")->setNextGate(getGateById("gA",0)->num);//b->gA 1
	getPathById("b")->setNextGate(getGateById("gA",1)->num);//b->gA 2

	getGateById("gA",0)->setNextPath(getPathById("c")->num);//gA,0 -> c
	getPathById("c")->setNextPath(getPathById("b")->num);//c->b

	getPathById("e")->setNextPath(getPathById("a")->num);//si muerte vuelve a empezar

	getGateById("gA",1)->setNextPath(getPathById("d")->num);//b->c

	getPathById("d")->setNextGate(getGateById("gB",0)->num);
	getGateById("gB",0)->setNextPath(getPathById("f")->num);//gA,0 -> c

	getPathById("d")->setNextGate(getGateById("gB",1)->num);
	getGateById("gB",1)->setNextPath(getPathById("e")->num);//gA,0 -> c
	
	getPathById("f")->setNextPath(FINAL_CIRCUIT);//d->a
	


}
void Circuit::loadThree(){

	Path p[MAXPATHS];

	p[0].addStart(0,0.9);
	p[0].addCell(0,0.7);
	pushPath(p[0],"a");

	p[1].addCell(0,0.7);
	p[1].addCell(0,0.55);
	pushPath(p[1],"b");

	p[2].addCell(-0.25,0.4);
	p[2].addCell(-0.45,0.35);
	pushPath(p[2],"c");

	p[3].addCell(0,0.4);
	p[3].addCell(-0.45,-0.2);
	pushPath(p[3],"d");
	
	p[4].addCell(0.25,0.4);
	p[4].addCell(0.35,0.45);
	p[4].addCell(0.35,0.7);
	pushPath(p[4],"e");

	p[5].addCell(0.5,0.85);
	p[5].addCell(0.95,0.85);
	pushPath(p[5],"f");

	p[6].addCell(0.5,0.6);
	p[6].addCell(0.5,0.4);
	pushPath(p[6],"g");

	p[7].addCell(0.5,0.4);
	p[7].addCell(0.5,0.25);
	pushPath(p[7],"h");

	p[8].addCell(0.7,0.4);
	p[8].addCell(0.6,0.55);
	p[8].addCell(0.5,0.4);
	pushPath(p[8],"i");

	p[9].addCell(0.7,0.25);
	p[9].addCell(0.7,0.4);
	pushPath(p[9],"j");

	p[10].addCell(0.8,0.25);
	p[10].addCell(0.7,0.4);
	pushPath(p[10],"k");

	p[11].addCell(0.9,0.3);
	p[11].addCell(0.9,0.85);
	p[11].addCell(0.95,0.85);
	pushPath(p[11],"l");

	p[12].addCell(0.5,0);
	p[12].addCell(0.55,-0.7);
	pushPath(p[12],"m");

/////

	p[13].addCell(0.25,-0.25);
	p[13].addCell(0.55,-0.7);
	pushPath(p[13],"n");

	
	p[14].addCell(0,-0.3);
	p[14].addCell(-0.3,-0.75);
	p[14].addCell(-0.55,-0.4);
	pushPath(p[14],"�");

	
	
	
	p[15].addCell(-0.65,-0.25);
	p[15].addCell(-0.8,0.15);
	pushPath(p[15],"o");

	p[16].addCell(-0.8,-0.35);
	p[16].addCell(-0.95,-0.2);
	p[16].addCell(-0.8,0.15);
	pushPath(p[16],"p");

	p[17].addCell(-0.8,-0.5);
	p[17].addKill(-0.95,-0.55);   ///////// <<<<<<<<  one kill
	pushPath(p[17],"q");

	p[18].addCell(0.4,0.15);
	p[18].addCell(0.2,0);
	pushPath(p[18],"r");

	p[19].addCell(-0.8,0.3);
	p[19].addCell(-0.7,0.7);
	p[19].addCell(-0.4,0.85);
	pushPath(p[19],"s");

	p[20].addCell(-0.9,0.85);
	p[20].addCell(-0.4,0.85);
	pushPath(p[20],"t");

	p[21].addCell(-0.4,0.85);
	p[21].addCell(-0.1,0.85);
	p[21].addCell(0,0.7);
	pushPath(p[21],"u");

	p[22].addCell(-0.45,0.15);
	p[22].addCell(-0.45,-0.2);
	pushPath(p[22],"v");

	p[23].addCell(-0.45,-0.2);
	p[23].addCell(-0.7,-0.4);
	pushPath(p[23],"w");

	p[24].addCell(-0.6,0.3);
	p[24].addKill(-1,0.15);  //////////////// dead
	pushPath(p[24],"x");          

	p[25].addCell(0.85,-0.6);
	p[25].addCell(0.9,0);	
	pushPath(p[25],"y");

	p[26].addCell(0.6,-0.9);
	p[26].addEnd(0.35,-0.9);
	pushPath(p[26],"z");



	Path g[MAXGATES];//gates o compuertas
	g[0].addCell(0,0.55);
	g[0].addCell(-0.25,0.4);

	g[1].addCell(0,0.55);
	g[1].addCell(0,0.4);

	g[2].addCell(0,0.55);
	g[2].addCell(0.1,0.4);
	g[2].addCell(0.25,0.4);

	pushGate(g[0],"gB",0,3);//els gates amb el mateix nom s'intercanvien al premer una tecla
	pushGate(g[1],"gB",0,3);
	pushGate(g[2],"gB",0,3);



    g[3].addCell(-0.45,0.35);
	g[3].addCell(-0.6,0.3);

	g[4].addCell(-0.45,0.35);
	g[4].addCell(-0.45,0.15);

	pushGate(g[3],"gC",0,2);
	pushGate(g[4],"gC",0,2);



	g[5].addCell(0.55,-0.7);
	g[5].addCell(0.8,-0.75);
	g[5].addCell(0.85,-0.6);

	g[6].addCell(0.55,-0.7);
	g[6].addCell(0.75,-0.8);
	g[6].addCell(0.6,-0.9);

	pushGate(g[5],"gN",0,2);
	pushGate(g[6],"gN",0,2);


	g[7].addCell(0.5,0.25);
	g[7].addCell(0.4,0.15);

	g[8].addCell(0.5,0.25);
	g[8].addCell(0.5,0);

	g[9].addCell(0.5,0.25);
	g[9].addCell(0.6,0.05);
	g[9].addCell(0.7,0.25);

	pushGate(g[7],"gH",0,3);
	pushGate(g[8],"gH",0,3);
	pushGate(g[9],"gH",0,3);




	g[10].addCell(0.2,0);
	g[10].addCell(0,-0.3);

	g[11].addCell(0.2,0);
	g[11].addCell(0.15,-0.15);
	g[11].addCell(0.25,-0.25);

	pushGate(g[10],"gR",0,2);
	pushGate(g[11],"gR",0,2);


	g[12].addCell(0.35,0.7);
	g[12].addCell(0.35,0.85);
	g[12].addCell(0.5,0.85);

	g[13].addCell(0.35,0.7);
	g[13].addCell(0.5,0.7);
	g[13].addCell(0.5,0.6);

	pushGate(g[12],"gE",0,2);
	pushGate(g[13],"gE",0,2);


	g[14].addCell(-0.7,-0.4);
	g[14].addCell(-0.8,-0.35);

	g[15].addCell(-0.7,-0.4);
	g[15].addCell(-0.8,-0.5);

	pushGate(g[14],"gW",0,2);
	pushGate(g[15],"gW",0,2);


    g[16].addCell(0.9,0);
	g[16].addCell(0.8,0.25);

	g[17].addCell(0.9,0);
	g[17].addCell(0.9,0.3);

	pushGate(g[16],"gY",0,2);
	pushGate(g[17],"gY",0,2);




	getPathById("a")->setNextPath(getPathById("b")->num);//a->b
	getPathById("b")->setNextGate(getGateById("gB",0)->num);
	getGateById("gB",0)->setNextPath(getPathById("c")->num);
	
	getPathById("c")->setNextGate(getGateById("gC",0)->num);
	getGateById("gC",0)->setNextPath(getPathById("x")->num);
	getPathById("x")->setNextPath(getPathById("a")->num);//

	getPathById("c")->setNextGate(getGateById("gC",1)->num);
	getGateById("gC",1)->setNextPath(getPathById("v")->num);
	getPathById("v")->setNextPath(getPathById("w")->num);//
	getPathById("w")->setNextGate(getGateById("gW",0)->num);
	getGateById("gW",0)->setNextPath(getPathById("p")->num);
	getPathById("p")->setNextPath(getPathById("s")->num);//
	getPathById("s")->setNextPath(getPathById("u")->num);//
	getPathById("u")->setNextPath(getPathById("b")->num);//

	getPathById("w")->setNextGate(getGateById("gW",1)->num);
	getGateById("gW",1)->setNextPath(getPathById("q")->num);
	getPathById("q")->setNextPath(getPathById("a")->num);//


	getPathById("b")->setNextGate(getGateById("gB",1)->num);
	getGateById("gB",1)->setNextPath(getPathById("d")->num);
	getPathById("d")->setNextPath(getPathById("w")->num);//


	getPathById("b")->setNextGate(getGateById("gB",2)->num);
	getGateById("gB",2)->setNextPath(getPathById("e")->num);

	getPathById("e")->setNextGate(getGateById("gE",0)->num);
	getGateById("gE",0)->setNextPath(getPathById("f")->num);
	getPathById("f")->setNextPath(getPathById("t")->num);//

	getPathById("t")->setNextPath(getPathById("u")->num);//
	getPathById("u")->setNextPath(getPathById("b")->num);//

	getPathById("e")->setNextGate(getGateById("gE",1)->num);

	getGateById("gE",1)->setNextPath(getPathById("g")->num);
	getPathById("g")->setNextPath(getPathById("h")->num);//

	getPathById("h")->setNextGate(getGateById("gH",0)->num);
	getGateById("gH",0)->setNextPath(getPathById("r")->num);

	getPathById("r")->setNextGate(getGateById("gR",0)->num);

	getGateById("gR",0)->setNextPath(getPathById("�")->num);
	getPathById("�")->setNextPath(getPathById("o")->num);//
	getPathById("o")->setNextPath(getPathById("s")->num);//

	getGateById("gR",1)->setNextPath(getPathById("n")->num);

	getPathById("m")->setNextGate(getGateById("gN",0)->num);
	getPathById("m")->setNextGate(getGateById("gN",1)->num);
	
	getPathById("n")->setNextGate(getGateById("gN",0)->num);
	getGateById("gN",0)->setNextPath(getPathById("y")->num);

	getPathById("n")->setNextGate(getGateById("gN",1)->num);
	getGateById("gN",1)->setNextPath(getPathById("z")->num);


	getPathById("y")->setNextGate(getGateById("gY",0)->num);
	getGateById("gY",0)->setNextPath(getPathById("k")->num);
	getPathById("k")->setNextPath(getPathById("i")->num);//
	getPathById("i")->setNextPath(getPathById("h")->num);//

	getGateById("gY",1)->setNextPath(getPathById("l")->num);
	getPathById("l")->setNextPath(getPathById("t")->num);//

	getGateById("gH",2)->setNextPath(getPathById("j")->num);
	getPathById("j")->setNextPath(getPathById("i")->num);//

	



	getPathById("y")->setNextGate(getGateById("gY",1)->num);


	getPathById("r")->setNextGate(getGateById("gR",1)->num);

	getPathById("h")->setNextGate(getGateById("gH",1)->num);
	getGateById("gH",1)->setNextPath(getPathById("m")->num);

	getPathById("h")->setNextGate(getGateById("gH",2)->num);



	getPathById("z")->setNextPath(FINAL_CIRCUIT);//d->a



    
	}
list<Cell> Circuit::allCellsFromPath(int i){
	list<Cell> ret;
	int kk=0;
	for (list<Path>::iterator it = Paths.begin(); it != Paths.end(); it++){
		if(i==kk++){
		for(list<Cell>::iterator it2 = it->cellsPath.begin();it2!=it->cellsPath.end();it2++){
			ret.push_back(*it2);
		}}
	}
	return(ret);
}

list<Cell> Circuit::allCellsFromGate(int i){
	list<Cell> ret;
	ret.clear();
	int kk=0;
	
	int j=0;


	for (list<Path>::iterator it = Gates.begin(); it != Gates.end(); it++){
		if(i==kk){
			if(j==it->getActiveGate()){
				for(list<Cell>::iterator it2 = it->cellsPath.begin();it2!=it->cellsPath.end();it2++){
					ret.push_back(*it2);
				}	
			}
		}
		kk++;
		j++;
		if(j==it->getNumGroup())j=0;
	}
	
	return(ret);
}

void Circuit::swapGates(){
	for (list<Path>::iterator it = Paths.begin(); it != Paths.end(); it++){
		it->swapGates();
	}
	for (list<Path>::iterator it = Gates.begin(); it != Gates.end(); it++){
		it->swapGates();
	}
}


Path *Circuit::getPathById(string id){
	for (list<Path>::iterator it = Paths.begin(); it != Paths.end(); it++){
		if(id==it->getId())return(&*it);
	}
	return(NULL);
}
Path Circuit::getPathAt(int i){//retorna el path posicionat a "i" de la llista
	Path p;
	p.setId("ERROR:Circuit::getPath() not found.");
	for (list<Path>::iterator it = Paths.begin(); it != Paths.end(); it++){
			if(it->num==i)p=*it;
		}
	return(p);
}

Path *Circuit::getGateById(string id,int i){
	int n=0;
	for (list<Path>::iterator it = Gates.begin(); it != Gates.end(); it++){
		if(id==it->getId()){
			if(n++==i)return(&*it);
		}
	}
	return(NULL);
}
Path Circuit::getGateAt(int i){//retorna el path posicionat a "i" de la llista
	Path p;
	p.setId("ERROR:Circuit::getGate() not found.");
	for (list<Path>::iterator it = Gates.begin(); it != Gates.end(); it++){
			if(it->num==i)p=*it;
		}
	return(p);
}

