//============================================================================
// Name        : uex1010.cpp
// Author      : Profesores de la asignatura IP/FO
// Version     : Curso 16/17
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include "entorno.h"
#include<iostream>
#include "TADjuego.h"

using namespace std;
void geenerarPieza(void){

	int dimension=1+rand()%3;
	entornoPintarPieza(Zona1, dimension,dimension, COLOR_AZUL);
	entornoPintarPieza(Zona2, 1,1+rand()%3, COLOR_FUCSIA);
	entornoPintarPieza(Zona3, 1+rand()%3,1, COLOR_MARRON);
}


void pruebasBasicas(){
	int tamanio, maxPuntos, numPiezas;
	int fila, col;
	bool salir;
	TipoTecla tecla;

	if (entornoCargarConfiguracion(tamanio, maxPuntos, numPiezas)) {
		entornoIniciar(tamanio);
	}
	fila = 0;
	col = 0;
	entornoActivarCasilla(fila, col);
	salir = false;

	geenerarPieza();
	while (!salir) {

		tecla = entornoLeerTecla();
		switch (tecla) {

		case TEnter:
			entornoColorearCasilla(fila, col, COLOR_VERDE);
			break;
		case TDerecha:
			entornoDesactivarCasilla(fila, col);
			if (col < tamanio - 1)
				col++;
			else
				col = 0;
			entornoActivarCasilla(fila, col);
			break;
		case TIzquierda:
			entornoDesactivarCasilla(fila, col);
			if (col > 0)
				col--;
			else
				col = tamanio - 1;
			entornoActivarCasilla(fila, col);
			break;
		case TArriba:
			entornoDesactivarCasilla(fila, col);
			if (fila > 0)
				fila--;
			else
				fila = tamanio - 1;
			entornoActivarCasilla(fila, col);
			break;
		case TAbajo:
			entornoDesactivarCasilla(fila, col);
			if (fila < tamanio - 1)
				fila++;
			else
				fila = 0;
			entornoActivarCasilla(fila, col);
			break;
		case TSalir:
			salir = true;
			break;
		case TUno:
			break;
		case TDos:
			break;
		case TTres:
			break;
		case TX:
			break;
		case TNada:
			break;

		}

	}

	entornoMostrarMensajeFin("      Adios");
	entornoPausa(3.0);
	entornoTerminar();
}
int main() {
	srand(time(NULL));
	juego();
	//pruebasBasicas();
	return 0;
}
