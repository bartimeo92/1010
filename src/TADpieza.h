/*
 * TADpieza.h
 *
 *  Created on: 12/02/2017
 *      Author: solis
 */

#ifndef TADPIEZA_H_
#define TADPIEZA_H_
#include <cstdlib>

namespace std {

struct pieza{
	int ancho;
	int alto;
	int color;
};

/*
 * PRE={}
 * POST={incicializa p}
 * COMP=O(1)
 */

void inicializarPieza(pieza &p);

/*
 * PRE={}
 * POST={Devuelve el alto de la pieza p}
 * COMP=O(1)
 */
int obtenerAlto(pieza p);
/*
 * PRE={}
 * POST={Devuelve el ancho de la pieza p}
 * COMP=O(1)
 */
int obtenerAncho(pieza p);
/*
 * PRE={}
 * POST={Deveuleve el color de la pieza p}
 * COMP=O(1)
 */
int obtenerColor(pieza p);

} /* namespace std */


#endif /* TADPIEZA_H_ */
