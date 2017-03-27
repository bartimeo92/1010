/*
 * TADtablero.cpp
 *
 *  Created on: 12/02/2017
 *      Author: solis
 */

#include "TADtablero.h"

namespace std {

void inicializarTablero(tablero &t, int tamanio){
	t.tamano=tamanio;
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			t.m[i][j]=false;
		}
	}
}

bool puedoPonerPieza(tablero t, pieza p, int fila, int columna){
	int i;
	int j;
	bool puedo=true;
	for(i=columna;i<obtenerAncho(p)&&puedo;i++){
		for(j=fila;j<obtenerAlto(p)&&puedo;j++){
			if(t.m[i][j]){
				puedo=false;
			}

		}
	}
	return puedo;
}

bool estaDone(tablero t, pieza p){
	int i, j;
	bool done=true;
	for(i=0;i<t.tamano && !done;i++){
		for(j=0;j<t.tamano && !done;j++){
			if(puedoPonerPieza(t,p, j, i)){
				done=false;
			}

		}
	}
	return done;
}

void ponerPieza(tablero &t, pieza p, int columna, int fila){
	int i, j;
	for(i=columna;i<obtenerAncho(p);i++){
		for(j=fila;j<obtenerAlto(p);j++){
			t.m[i][j]=true;
		}
	}

}
bool filaLlena(tablero t, int fila){
	bool llena=true;
	for(int i=0;i<t.tamano && llena;i++){
		if(!t.m[i][fila]){
			llena=false;
		}
	}
	return llena;
}
void borrarFila(tablero &t, int fila){
	for(int i=0;i<t.tamano;i++){
		t.m[i][fila]=false;
	}
}
int purga(tablero &t){
	int filasBorradas;
	for (int j=0;j<t.tamano;j++){
		if(filaLlena(t,j)){
			borrarFila(t, j);
			filasBorradas++;
		}
	}
	return filasBorradas;
}
} /* namespace std */
