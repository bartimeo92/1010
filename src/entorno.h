/**

	INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
	Curso 2016/2015

	Nombre: entorno.h
	Descripción: Especificación del TAD Entorno para el proyecto 1010!
	     	 	 Encargado del manejo de la interfaz del juego.
	     	 	 versión allegro 5
	Autor:	Profesores de las asignaturas
	Fecha:  18/09/2016

*/


#ifndef ENTORNO_H_
#define ENTORNO_H_

#include <string>
using namespace std;
// -------------------------------------------------------------
// Definicion de constantes públicas
// -------------------------------------------------------------


// Dimensiones máximas  del tablero

const int MAXTAMANO	= 10;


// -------------------------------------------------------------
// Definicion de tipos
// -------------------------------------------------------------

/**
 *   Este es el tipo devuelto por la operacion LeerTecla que indica la tecla
 *   de los cursores o teclas válidas que se ha pulsado
 */
enum TipoTecla {TNada, TEnter, TIzquierda, TDerecha, TArriba, TAbajo, TSalir,  TX, TUno, TDos, TTres};


/**
 *   Zonas en el entorno para imprimir mensajes. Existen 3 zonas delimitadas para imprimir un
 *   mensaje en la pantalla del entorno. Se pueden usar para imprimir mensajes de estado de
 *   diferentes tipos
 */
enum TipoZona {Zona1, Zona2, Zona3};

// colores de las piezas

const int COLOR_AZUL      = 1;
const int COLOR_VERDEPURO = 2;
const int COLOR_VERDE     = 3;
const int COLOR_FUCSIA    = 4;
const int COLOR_AMARILLO  = 5;
const int COLOR_MARRON    = 6;
const int COLOR_BLANCO    = 7;



// -------------------------------------------------------------
// Declaración de interfaz (módulos) PÚBLICA
// -------------------------------------------------------------


 /*
  *	PRE:  4 <= tam <= MAXTAMANO,
  *	POST: Inicia la pantalla de juego, incluyendo una rejilla cuadrada de tam*tam
  */
void entornoIniciar (int tam);


 /*
  *	POST: Libera los recursos usados por el entorno gráfico
  */
void entornoTerminar ();


 /*
  *	PRE: Archivo 1010!.cnf correcto y en la carpeta raíz del proyecto
  *	     (NO SE COMPRUEBAN ERRORES EN LOS DATOS)
  *	POST: Devuelve:
  *	         TRUE:  si se carga correctamente la configuración del juego,
  *		     FALSE: en caso contrario.
  *   PARÁMETROS:
  *		Si la configuración se lee de forma correcta se devolverá:
  *		   tamano:		  número de filas y columnas del tablero
  *		   maxPuntuación: puntuación maxima conseguido en el juego
  *		   numPiezas: 	  número de piezas a colocar
  *		Por defecto, el archivo 1010!.cnf se encuentra en el directorio  del proyecto
  */
bool entornoCargarConfiguracion ( int 	&tamano,
								  int   &maxPuntuacion,
								  int 	&numPiezas);



 /*
  * PRE:
  *	     (NO SE COMPRUEBAN ERRORES EN LOS DATOS)
  *	POST: Almacena en el fichero 1010! la configuracion actual del juego
  *  PARÁMETROS ENTRADA:
  *		   tamano:		  número de filas y columnas del tablero
  *		   maxPuntuación: puntuación maxima conseguido en el juego
  * 	   numPiezas: 	  número de piezas
  *	Por defecto, el archivo 1010!.cnf se encuentra en el directorio  del proyecto
  */
void entornoGuardarConfiguracion( 	int tamano,
									int maxPuntuacion,
									int numPiezas);


 /*
  * PRE: { 0 <= fila < MAXTAMANO }
  *      { 0 <= columna < MAXTAMANO}
  *      { 1 <=  color <= 6}
  * POST: Colorea la casilla que se encuentra en la posición (fila,columna) del color "color""
  */
void entornoColorearCasilla(int fila, int columna, int color);


/*
  *	PRE:  0 <= fila < MAXTAMANO,
  * PRE:  0 <= columna < MAXTAMANO,
  * POST: Borra el color de la casilla que se encuentra en la posición (fila, columna).
  */
void entornoBorrarCasilla(int fila, int columna);


 /*
  * PRE:  { zona pertenece al conjunto {Zona1, Zona2, Zona3} }
  *       { 0<= ancho <= 4 }
  *       { 0<= alto  <= 4 }
  *       { 1<= color <= 6 }
  * POST: Pinta, en el lugar indicado por zona, la pieza que aparece debajo de la cuadrícula para ser colocada
  */
void entornoPintarPieza(TipoZona zona, int ancho, int alto, int color);
/*
 * PRE:  { zona {Zona1, Zona2, Zona3} }
 *       { 0<= fila <= 4 }
 *       { 0<= col <= 4 }
 *       { 1<= color <= 6 }
 * POST: Pinta  una pieza de 1x1 el la fila y columna indicada en la zona,
 *       aparecerá debajo de la cuadrícula para ser colocada
 */
void entornoPintarPiezaCuadrada(TipoZona zona, int fila,  int col, int color);


 /*
  * PRE: { zona pertenece al conjunto {Zona1, Zona2, Zona3} }
  * POST: elimina de la pantalla la pieza que aparece debajo de la cuadrícula situada en la zona "zona"
  */
void entornoEliminarPieza(TipoZona zona);


  /*
   * PRE:  0 <= fila < MAXTAMANIO,
   * PRE:  0 <= columna < MAXTAMANIO,
   * POST: Enmarca la casilla que ocupa la posición (fila, columna) en un rectángulo azul.
   */
void entornoActivarCasilla(int fila, int columna);


  /*
   * PRE:  0 <= fila < MAXTAMANIO,
   * PRE:  0 <= columna < MAXTAMANIO,
   * POST: Elimina el marco de la casilla que ocupa la posición (fila, columna)
   */
void entornoDesactivarCasilla(int fila, int columna);


  /*
   * PRE:
   * POST: Muestra la puntuación maxima obtenida en partidas anteriores, en el marcador situado
   *       encima de la cuadrícula
   */
void entornoPuntuacionMaxima( int valor);


  /*
   * PRE:
   * POST: Muestra la puntuación actual, en el marcador situado
   *       encima de la cuadrícula
   */
void entornoPonerPuntuacion( int valor);


 /*
  * POST:Devuelve un valor enumerado de TipoTecla con la tecla que se ha pulsado
  */
TipoTecla entornoLeerTecla();


 /*
  * PRE: 	{zona pertenece al conjunto {Zona1, Zona2, Zona3}}
  * POST:	Escribe el mensaje, indicado por el parámetro msg, en el lugar de la pantalla indicado por zona
  */
void entornoMostrarMensaje (TipoZona zona, string msg);


 /*
  * POST: Muestra un mensaje, indicado por msg, en el centro de la rejilla para indicar que ha finalizado el juego
  */
void entornoMostrarMensajeFin (string msg);


 /*
  * PRE: 0 < pausa  (tiempo en segundos que dura la pausa)
  * POST: lleva a cabo una pausa en la ejecución del juego,
  * puede utilizarse para ralentizar algún movimiento sobre el tablero
  */
void entornoPausa(float pausa);


 /* PRE:
  * POST: convierte un número, indicado por el parámetro numero, a cadena de caracteres
  */
string toString(int numero);


#endif

