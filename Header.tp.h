#ifndef HEADER_TP_H_INCLUDED
#define HEADER_TP_H_INCLUDED
#include <string>
#include "rlutil.h"

using namespace std;

//Defines las funciones
//1

int tirarDado(int n );

void tirada_dadosObjetivo(int &valor_Objetivo, string tirador);

void mostrar_menu();

void declara_jugadores (string &player1, string &player2);

void empieza_primero (string &player1, string &player2);

void mostrar_dadosStock (int stock, int dadosStock_delJugador[]);

bool dadoYaFueElegido(int dado, int posicionesElegidas[], int cantidadElegidos);

void turnoJugador (string nombreJugador , int &stockJugador , int dadosJugador[], int objetivo, int &stockOponente, int &puntosJugador);

void opcion_0_cero(bool &seguir_jugando);


#endif // HEADER_TP_H_INCLUDED
