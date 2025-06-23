#ifndef HEADER_TP_H_INCLUDED
#define HEADER_TP_H_INCLUDED
#include <string>
#include "rlutil.h"


using namespace std;

int tirarDado(int n );

void mostrar_menu();

void mostrar_creditos();

void mostrar_estadisticas(int puntaje_delGanador, string nombre_delGanador, bool primera_jugadaHecha);

void declara_jugadores (string &player1, string &player2);

void empieza_primero (string &player1, string &player2);

void tirada_dadosObjetivo(int &valor_Objetivo, string tirador);

void mostrar_dadosStock (int stock, int dadosStock_delJugador[]);

void ofrecerDadoExtra(string nombreJugador, int &stockJugador, int &stockOponente);

bool dadoYaFueElegido(int dado, int posicionesElegidas[], int cantidadElegidos);

void seleccionar_dados(int &posicion_dadoElegido, int posiciones_deDadosElegidos[], int &cantDadosElegida, int &sumaDadosSeleccionados, int &stockJugador, int dadosJugador[], string nombreJugador, int &stockOponente, int objetivo , bool &fue_penalizado);

void procesarTiradaExitosa(string nombreJugador, int &stockJugador, int &stockOponente, int sumaDadosSeleccionados, int &cantDadosElegida, int posiciones_deDadosElegidos[] , int &puntosJugador);

void turnoJugador (string nombreJugador , int &stockJugador , int dadosJugador[], int objetivo, int &stockOponente, int &puntosJugador );

void victoriaAutomatica(string &nombrePlayer , int &puntosPlayer);

void victoriaPorPuntos( string ganador, string perdedor, int puntosGanador, int puntosPerdedor , int &puntaje_delGanador, string &nombre_delGanador );

void opcion_0_cero(bool &seguir_jugando);

#endif // HEADER_TP_H_INCLUDED
