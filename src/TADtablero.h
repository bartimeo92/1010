/*
 * TADtablero.h
 *
 *  Created on: 12/02/2017
 *      Author: solis
 */

#ifndef TADTABLERO_H_
#define TADTABLERO_H_
#include "TADpieza.h"

namespace std {
const int MAX=10;
typedef bool tipoMatriz[MAX][MAX];
struct tablero{
	int tamano;
	tipoMatriz m;
};
/*
 * PRE={0<tamanio<=10}
 * POST={inicializa t con la dimensión tamanio}
 * COMP=O(n²)
 */
void inicializarTablero(tablero &t, int tamanio);
/*
 * PRE={0<fila, columna<10}
 * POST={devuelve true si se puede colocar p en la posición (fila, columna)}
 * COMP=O(n²)
 */
bool puedoPonerPieza(tablero t, pieza p, int fila, int columna);
/*
 * PRE={}
 * POST={devuelve si estás done(si has perdido porque la pieza p no cabe en el tablero)}
 * COMP=O(n⁴)
 */
bool estaDone(tablero t, pieza p);
/*
 * PRE={0<=fila, columna<t.tamanio}
 * POST={pone la pieza p en la posición (fila, columna)}
 * COMP=O(n²)
 */
void ponerPieza(tablero &t, pieza p, int fila, int columna);
/*
 * PRE={0<=fila<t.tamano}
 * POST={devuelve true si la fila está llena}
 * COMP=O(n)
 */
bool filaLlena(tablero t, int fila);
/*
 * PRE={}
 * POST={}
 * COMP=O()
 */
void borrarFila(tablero &t, int fila);
/*
 * PRE={}
 * POST={purga el tablero de filas llenas}
 * COMP=O(n²)
 */
int purga(tablero &t);




} /* namespace std */

#endif /* TADTABLERO_H_ */
