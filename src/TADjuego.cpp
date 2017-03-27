/*
 * TADjuego.cpp
 *
 *  Created on: 19/02/2017
 *      Author: solis
 */

#include "TADjuego.h"

namespace std {

void juego(){
	int tamanio, maxPuntos, numPiezas;
	int punt=0;
		int fila, col;
		bool salir;
		TipoTecla tecla;

		if (entornoCargarConfiguracion(tamanio, maxPuntos, numPiezas)) {
			entornoIniciar(tamanio);
		}
		tablero t;
		pieza p;
		inicializarTablero(t,tamanio);
		inicializarPieza(p);
		entornoPintarPieza(Zona1, obtenerAncho(p), obtenerAlto(p), obtenerColor(p));
		fila = 0;
		col = 0;
		entornoActivarCasilla(fila, col);
		salir = false;

		while (!salir) {

			tecla = entornoLeerTecla();
			switch (tecla) {

			case TEnter:
				if(puedoPonerPieza(t, p, fila, col)){
					ponerPieza(t, p, fila, col);
					punt=punt+obtenerAlto(p)+obtenerAncho(p);
					for(int i=col;i<obtenerAncho(p);i++){
						for(int j=fila;j<obtenerAlto(p);j++){
							entornoColorearCasilla(j, i, obtenerColor(p));
						}

					}
					inicializarPieza(p);
					entornoEliminarPieza(Zona1);
					entornoPintarPieza(Zona1, obtenerAncho(p), obtenerAlto(p), obtenerColor(p));
					punt=punt+purga(t)*t.tamano;
					entornoPonerPuntuacion(punt);
				}
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

		entornoMostrarMensajeFin("      Estás muy done");
		entornoPausa(3.0);
		entornoTerminar();
	}
}
 /* namespace std */
