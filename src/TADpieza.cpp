/*
 * TADpieza.cpp
 *
 *  Created on: 12/02/2017
 *      Author: solis
 */

#include "TADpieza.h"

namespace std {

void inicializarPieza(pieza &p){

	switch(rand()%9){
	case 0://1x1
		p.alto=1;
		p.ancho=1;
		p.color=1+rand()%5;
		break;
	case 1://2x2
		p.alto=2;
		p.ancho=2;
		p.color=1+rand()%5;
		break;
	case 2://3x3
		p.alto=3;
		p.ancho=3;
		p.color=1+rand()%5;
		break;
	case 3://4x1
		p.alto=4;
		p.ancho=1;
		p.color=1+rand()%5;
		break;
	case 4://3x1
		p.alto=1;
		p.ancho=3;
		p.color=1+rand()%5;
		break;
	case 5://2x1
		p.alto=1;
		p.ancho=2;
		p.color=1+rand()%5;
		break;

	case 6://1x4
		p.alto=4;
		p.ancho=1;
		p.color=1+rand()%5;
		break;
	case 7://1x3
		p.alto=3;
		p.ancho=1;
		p.color=1+rand()%5;
		break;
	case 8://1x2
		p.alto=2;
		p.ancho=1;
		p.color=1+rand()%5;
	}
}
int obtenerAncho(pieza p){return(p.ancho);}
int obtenerAlto(pieza p){return(p.alto);}
int obtenerColor(pieza p){return(p.color);}
} /* namespace std */
