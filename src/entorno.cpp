/**

 INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
 Curso 2016/2017

 Nombre: entorno.cpp
 Descripción: Implementación del TAD Entorno para el proyecto 1010!
 Encargado del manejo de la interfaz del juego.
 Autor:	Profesores de las asignaturas
 Fecha:	25/11/2012
 Fecha última modificación: 10/11/2016 Allegro5

 */

#include "entorno.h"
#include <stdlib.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro5.h>


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

// -------------------------------------------------------------
// Definicion de constantes privadas
// -------------------------------------------------------------
// Definición de colores que usa el entorno


const int COLOR_ROJO      = 8;
const int COLOR_NEGRO     = 9;
const int COLOR_ROSA      = 10;
const int COLOR_NARANJA   = 11;
const int COLOR_GRIS      = 12;
const int COLOR_AZUL_CLARO= 13;


const int COLOR_LINEAS = COLOR_BLANCO;
const float GROSOR_LINEAS = 2.0;


const int ANCHO_VENTANA = 700;
const int ALTO_VENTANA  = 600;

// Definicón de constantes para posicionar los números en el tablero
const int DISTANCIA_COLS  = 35;  // Distancia entre columnas
const int DISTANCIA_FILAS = 35;  // Distancia entre filas
const int ORIGEN_X        = 20;  // Origen de las x
const int ORIGEN_Y        = 30 + 40;  // Origen de las y

// definicion de las constantes para posicionar los marcadores
const int FILA_MARCADOR = 100;
const int COL_MARCADOR  = 14;


ALLEGRO_DISPLAY *display;
ALLEGRO_FONT *font;

ALLEGRO_EVENT_QUEUE *colaEventos = NULL;


// Imágenes
ALLEGRO_BITMAP *logo;



// -------------------------------------------------------------
// Declaración de módulos PRIVADOS
// -------------------------------------------------------------

// convierte el número dado como parámetro de entrada a string (cadena)
string toString(int numero);

// define el color en función de los valores makecol - allegro library
ALLEGRO_COLOR makecolor2 (int color);

// Dibuja en la pantalla el borde de un tablero con el ancho indicado
void entornoPintarRejilla(int tamanio);


// -------------------------------------------------------------
// Definición de módulos PRIVADOS
// -------------------------------------------------------------

ALLEGRO_COLOR makecolor2(int color) {

	ALLEGRO_COLOR alColor;

	switch (color) {
	case COLOR_BLANCO:
		alColor = al_map_rgb (255, 255, 255);
		break;
	case COLOR_ROJO:
		alColor = al_map_rgb (255,   0,  0);
		break;
	case COLOR_NEGRO:
		alColor = al_map_rgb (0,    0,   0);
		break;
	case COLOR_AMARILLO:
		alColor = al_map_rgb (229, 239, 19);
		break;
	case COLOR_ROSA:
		alColor = al_map_rgb (222, 076, 138);
		break;
	case COLOR_AZUL:
		alColor = al_map_rgb (50,   50, 255);
		break;
	case COLOR_AZUL_CLARO:
		alColor = al_map_rgb (9,  179, 216);
		break;
	case COLOR_VERDEPURO:
		alColor = al_map_rgb (36,  231, 017);
		break;
	case COLOR_NARANJA:
		alColor = al_map_rgb (216, 075, 032);
		break;
	case COLOR_GRIS:
		alColor = al_map_rgb (200, 200, 200); // Gris claro
		break;
	case COLOR_MARRON:
		alColor = al_map_rgb (108, 59,  042);
		break;
	case COLOR_VERDE:
		alColor = al_map_rgb (0,   100,  0);
		break;
	case COLOR_FUCSIA:
		alColor = al_map_rgb (189, 17, 67);
		break;
	default:
		alColor = al_map_rgb (255, 255, 255);
		break; //color blanco
	}

	return alColor;
}

void entornoPintarRejilla(int tamano) {

	int i;
	int columnas    = tamano;
	int filas       = tamano;
	int nVecesMarco = 5; // número de veces que se repite el marco

	for (i = 1; i < nVecesMarco; i++) {
		al_draw_filled_rectangle( ORIGEN_X + i, ORIGEN_Y + i,
				ORIGEN_X + columnas * DISTANCIA_COLS + i,
				ORIGEN_Y + filas * DISTANCIA_FILAS + i,
				makecolor2(COLOR_GRIS));
	}

	// horizontales
	for (i = 0; i <= (columnas); i++) {
		al_draw_line( ORIGEN_X + 0 * DISTANCIA_COLS,
				ORIGEN_Y + i * DISTANCIA_FILAS,
				ORIGEN_X + columnas * DISTANCIA_COLS,
				ORIGEN_Y + i * DISTANCIA_FILAS, makecolor2(COLOR_LINEAS),GROSOR_LINEAS);
	}

	//verticales
	for (i = 0; i <= (filas); i++) {
		al_draw_line( ORIGEN_X + i * DISTANCIA_COLS,
				ORIGEN_Y + 0 * DISTANCIA_FILAS, ORIGEN_X + i * DISTANCIA_COLS,
				ORIGEN_Y + filas * DISTANCIA_FILAS, makecolor2(COLOR_LINEAS), GROSOR_LINEAS);
	}
	al_draw_bitmap(logo, FILA_MARCADOR + 60, COL_MARCADOR -10, 0);


	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO), 525,30,  ALLEGRO_ALIGN_CENTER,"*** 1010! ***");
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO), 525,50,  ALLEGRO_ALIGN_CENTER, "PROYECTO DE PROGRAMACIÓN");
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO), 400,80,  ALLEGRO_ALIGN_LEFT, "TECLAS: ");
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO), 400,100, ALLEGRO_ALIGN_LEFT, "Arriba : Flecha arriba");
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO), 400,120, ALLEGRO_ALIGN_LEFT, "Abajo  : Flecha abajo");
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO), 400,140, ALLEGRO_ALIGN_LEFT, "Drcha  : Flecha derecha");
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO), 400,160, ALLEGRO_ALIGN_LEFT, "Izqda   : Flecha izquierda");
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO), 400,190, ALLEGRO_ALIGN_LEFT, "Enter   : Colocar pieza");
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO), 400,210, ALLEGRO_ALIGN_LEFT, "Salir    : Escape");
	al_draw_text(font, makecolor2(COLOR_GRIS), 400,250,  ALLEGRO_ALIGN_LEFT, "TECLAS para ampliaciones: ");
	al_draw_text(font, makecolor2(COLOR_GRIS), 400,270, ALLEGRO_ALIGN_LEFT, "1 : Figura en zona 1");
	al_draw_text(font, makecolor2(COLOR_GRIS), 400,290, ALLEGRO_ALIGN_LEFT, "2 : Figura en zona 2");
	al_draw_text(font, makecolor2(COLOR_GRIS), 400,310, ALLEGRO_ALIGN_LEFT, "3 : Figura en zona 3");
	al_draw_text(font, makecolor2(COLOR_GRIS), 400,330, ALLEGRO_ALIGN_LEFT, "X : Rotar pieza");

}

void invertirFC(int &fila, int &columna) {
	int aux = columna;
	columna = fila;
	fila = aux;
}

// -------------------------------------------------------------
// Definición de la interfaz PÚBLICA
// -------------------------------------------------------------

void entornoIniciar(int tam) {

	// Iniciar el entorno

	if (al_init()){
	al_install_keyboard();

	al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_REQUIRE);
	al_set_new_display_flags (ALLEGRO_WINDOWED);

	display = al_create_display(ANCHO_VENTANA,ALTO_VENTANA);
	al_init_primitives_addon(); //

	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	// carga las fuentes con tamaño 18
	font = al_load_ttf_font("LiberationSansNarrow-Bold.ttf", 18, 0);
	logo = al_load_bitmap("copa.png");

    // borra la ventana con el color blanco
    al_clear_to_color(makecolor2(COLOR_BLANCO));
    al_set_window_title(display, "1010!");

    // se refresca la pantalla
    colaEventos = al_create_event_queue();
    al_register_event_source(colaEventos, al_get_keyboard_event_source());
	entornoPintarRejilla(tam);
    al_flip_display();

	}
}

void entornoTerminar(){

	al_destroy_display          (display);
	al_destroy_event_queue      (colaEventos);
	al_shutdown_primitives_addon();
	al_shutdown_font_addon      ();
	al_shutdown_ttf_addon       ();
	al_destroy_bitmap			(logo);

}

bool entornoCargarConfiguracion ( int &tamano, int &maxPuntuacion, int &numPiezas){

	bool leido;
	ifstream entrada;
	string cadena;
	entrada.open("1010!.cnf");
	if (entrada.is_open()) {
		getline(entrada, cadena);
		tamano = atoi(cadena.c_str());
		getline(entrada, cadena);
		maxPuntuacion = atoi(cadena.c_str());
		getline(entrada, cadena);
		numPiezas = atoi(cadena.c_str());
		leido = true;
		entrada.close();
	} else {
		cout
				<< "Fichero de configuración no encontrado (<proyecto>/1010!.cnf)."
				<< endl;
		cout << "Formato:" << endl;
		cout << "\t[Tamaño del tablero 4..10]" << endl;
		cout << "\t[puntuación maxima conseguida]" << endl;
		cout << "\t[número de piezas iniciales]" << endl;

		leido = false;
	}

	return leido;
}

void entornoGuardarConfiguracion( int tamano, int maxPuntuacion, int numPiezas){

	ofstream salida;
	salida.open("1010!.cnf");
	salida << tamano<<endl;
	salida<< maxPuntuacion<<endl;
	salida<<numPiezas<<endl;
	salida.close();

}

void entornoColorearCasilla(int fila, int columna, int color) {
	invertirFC(fila, columna);
	al_draw_filled_rectangle( ORIGEN_X + fila * DISTANCIA_COLS + 3,
				ORIGEN_Y + columna * DISTANCIA_FILAS + 3,
				ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS - 2,
				ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS - 2,
				makecolor2(color));
	al_flip_display();

}

void entornoBorrarCasilla(int fila, int columna) {
	invertirFC(fila, columna);
	al_draw_filled_rectangle( ORIGEN_X + fila * DISTANCIA_COLS + 3,
				ORIGEN_Y + columna * DISTANCIA_FILAS + 3,
				ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS - 2,
				ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS - 2,
				makecolor2(COLOR_GRIS));
	al_flip_display();
}


void entornoActivarCasilla(int fila, int columna) {
	int color = COLOR_AZUL_CLARO;
	invertirFC(fila, columna);

// vertical izquierda
	al_draw_line( ORIGEN_X + fila * DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS,
			ORIGEN_X + fila * DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS,
			makecolor2(color),GROSOR_LINEAS);
// horizontal arriba
	al_draw_line( ORIGEN_X + fila * DISTANCIA_FILAS ,
			ORIGEN_Y + columna * DISTANCIA_COLS ,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS ,
			ORIGEN_Y + columna * DISTANCIA_COLS ,
			makecolor2(color),GROSOR_LINEAS);

// vertical derecha
	al_draw_line( ORIGEN_X + fila * DISTANCIA_FILAS +DISTANCIA_FILAS ,
			ORIGEN_Y + columna * DISTANCIA_COLS ,
			ORIGEN_X + fila * DISTANCIA_FILAS +DISTANCIA_FILAS ,
			ORIGEN_Y + columna * DISTANCIA_COLS +DISTANCIA_COLS,
			makecolor2(color), GROSOR_LINEAS);
// horizontal abajo
	al_draw_line( ORIGEN_X + fila * DISTANCIA_FILAS ,
			ORIGEN_Y + columna * DISTANCIA_COLS +DISTANCIA_COLS,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS ,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS ,
			makecolor2(color), GROSOR_LINEAS);


	al_flip_display();
}

void entornoDesactivarCasilla(int fila, int columna) {

	invertirFC(fila, columna);

	// vertical izquierda
	al_draw_line(ORIGEN_X + fila * DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS,
			ORIGEN_X + fila * DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS,
			makecolor2(COLOR_LINEAS), GROSOR_LINEAS);
	// horizontal arriba
	al_draw_line(ORIGEN_X + fila * DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS, makecolor2(COLOR_LINEAS),
			GROSOR_LINEAS);

	// vertical derecha
	al_draw_line(ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS,
			makecolor2(COLOR_LINEAS), GROSOR_LINEAS);
	// horizontal abajo
	al_draw_line(ORIGEN_X + fila * DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS,
			ORIGEN_X + fila * DISTANCIA_FILAS + DISTANCIA_FILAS,
			ORIGEN_Y + columna * DISTANCIA_COLS + DISTANCIA_COLS,
			makecolor2(COLOR_LINEAS), GROSOR_LINEAS);

	al_flip_display();

}

void entornoPintarPieza(TipoZona zona, int ancho, int alto, int color) {

	int i;

	int fila;
	int col     = 480;
	int tam     =  15;
	string num;

	switch (zona) {
	case Zona1:
		fila = 90;
		num = "1";
		break;
	case Zona2:
		fila = 170;
		num = "2";
		break;
	case Zona3:
		fila = 250;
		num = "3";
		break;
	}
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO), fila -5, col -20, ALLEGRO_ALIGN_LEFT, num.c_str());
	al_draw_filled_rectangle(fila , col, fila+ ancho*tam, col+ alto*tam, makecolor2(color));
	// horizontales
	for (i = 1; i <(ancho); i++) {
		al_draw_line( fila + i * tam,col + 0 * tam, fila + i * tam,col + ancho * tam, makecolor2(COLOR_LINEAS), GROSOR_LINEAS);
	}
	//vertical
	for (i = 1; i < (alto); i++) {
		al_draw_line( fila + 0 * tam, col + i * tam , fila + alto * tam, col + i * tam, makecolor2(COLOR_LINEAS),GROSOR_LINEAS);
	}
	al_flip_display();
}

void entornoPintarPiezaCuadrada(TipoZona zona, int fila,  int col, int color){


	invertirFC(fila, col);

	int filaIni;
	int colIni   = 480;
	int tam     =  15;
	string num;

	switch (zona) {
	case Zona1:
		filaIni = 90;
		num = "1";
		break;
	case Zona2:
		filaIni = 170;
		num = "2";
		break;
	case Zona3:
		filaIni = 250;
		num = "3";
		break;
	}
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO), filaIni -5, colIni -20, ALLEGRO_ALIGN_LEFT, num.c_str());
	al_draw_filled_rectangle(filaIni+(fila*tam) + 1 , colIni+(col*tam)+1, filaIni+ (tam)+(fila*tam), colIni+ (tam)+(col*tam), makecolor2(color));

	al_flip_display();

}
void entornoEliminarPieza(TipoZona zona) {
	int fila;
	int col = 480;
	int tam = 60;
	switch (zona) {
	case Zona1:
		fila = 90;
		break;
	case Zona2:
		fila = 170;
		break;
	case Zona3:
		fila = 250;
		break;
	}
	al_draw_filled_rectangle(fila , col, fila + tam, col+ tam, makecolor2(COLOR_BLANCO));

}

void entornoMostrarMensaje(TipoZona zona, string msg) {
	int fila;
	int col = 380;
	switch (zona) {
	case Zona1:
		fila = 480;
		break;
	case Zona2:
		fila = 500;
		break;
	case Zona3:
		fila = 520;
		break;
	default:
		return;
	}
	al_draw_filled_rectangle(col -2 , fila,  col + 300,fila+20,  makecolor2(COLOR_BLANCO));
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO),col,fila, ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();

}

void entornoMostrarMensajeFin(string msg) {

	int i, j;
		for (i = 0, j = 0; i < 40 && j < 40; i += 4, j += 4) {
			al_draw_filled_rectangle(i + 220 , j + 240, 600 - i, 380 -j,  makecolor2(COLOR_AZUL_CLARO));
			al_draw_filled_rectangle(i + 222 , j + 242, 598 - i, 378 -j,  makecolor2(COLOR_BLANCO));
			usleep(25000); // 25 milisegundos
			al_flip_display();
		}

	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO),380,300, ALLEGRO_ALIGN_CENTRE, msg.c_str());
	al_flip_display();
}

void entornoPuntuacionMaxima(int valor) {
	al_draw_text(font, makecolor2(COLOR_VERDE),FILA_MARCADOR +140 , COL_MARCADOR +4  , ALLEGRO_ALIGN_LEFT, toString(valor).c_str());
	al_flip_display();
}


void entornoPonerPuntuacion(int valor) {
	al_draw_filled_rectangle(FILA_MARCADOR , COL_MARCADOR, FILA_MARCADOR+ 60, COL_MARCADOR+30, makecolor2(COLOR_BLANCO));
	al_draw_text(font, makecolor2(COLOR_AZUL_CLARO),FILA_MARCADOR + 20, COL_MARCADOR + 4  , ALLEGRO_ALIGN_LEFT, toString(valor).c_str());
	al_flip_display();

}


TipoTecla entornoLeerTecla() {

	TipoTecla tecla = TNada;
	ALLEGRO_EVENT evento;

	al_wait_for_event(colaEventos, &evento);

	if (evento.type == ALLEGRO_EVENT_KEY_UP) {
		switch (evento.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			tecla = TArriba;
			break;
		case ALLEGRO_KEY_DOWN:
			tecla = TAbajo;
			break;
		case ALLEGRO_KEY_LEFT:
			tecla = TIzquierda;
			break;
		case ALLEGRO_KEY_RIGHT:
			tecla = TDerecha;
			break;
		case ALLEGRO_KEY_ESCAPE:
			tecla = TSalir;
			break;
		case ALLEGRO_KEY_ENTER:
			tecla = TEnter;
			break;
		case ALLEGRO_KEY_1:
			tecla = TUno;
			break;
		case ALLEGRO_KEY_2:
			tecla = TDos;
			break;
		case ALLEGRO_KEY_3:
			tecla = TTres;
			break;
		case ALLEGRO_KEY_X:
			tecla = TX;
			break;
		default:
			tecla = TNada;
			break;
		}
	};

	return tecla;

}


void entornoPausa(float pausa) {
	al_rest(pausa);
}


string toString(int numero) {
	stringstream flujo;
	string cadena;
	flujo << numero;
	flujo >> cadena;
	return cadena;
}


