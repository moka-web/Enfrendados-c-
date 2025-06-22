#include <iostream>
#include "Header.tp.h"
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include <iostream>
using namespace std;

int main()
{
    // inicializa la semilla
    srand(time(0));

    int opcion, valor_Objetivo = 0, roundNumber = 0;

    int dados_Stock_Player1[12] = {}; // Cada jugador tendra
    int dados_Stock_Player2[12] = {};
    int cant_stock_player1 = 6;
    int cant_stock_player2 = 6;
    int puntos_player1 = 0;
    int puntos_player2 = 0;
    bool seguir_jugando;  //?

    string player1, player2, primero_enTirar, segundo_enTirar;

   

    do
    {
        
        seguir_jugando= true; 
        
        mostrar_menu();
        cin >> opcion;
        rlutil::cls();

        switch (opcion)

        {
        case 1:
        {
            // ingresa nombre jugadores
            declara_jugadores(player1, player2);

            // se asigna player1 y player2 y muestra por pantalla cual de los va a tirar primero.
            empieza_primero(player1, player2);

            // La siguiente salida se puede hacer en una funcion, no lo veo necesario ya que solo
            // se va a mostrar una vez

            cout << endl;
            cout << "Jugador 1: " << player1 << ". Va a tirar primero!" << endl
                 << endl;
            cout << "Jugador 2: " << player2 << ". Va a tirar segundo!" << endl
                 << endl;
            rlutil::anykey();
            rlutil::cls();

            // esta es la funcion del juego
            // el juego corta si si se superan las 3 rondas
            // o si la suma de dados alcanza el numero objetivo

            //rondas 

            while (roundNumber < 3 && cant_stock_player1 > 0 && cant_stock_player2 > 0)
            {
                roundNumber++;

                // tirada_dadosObjetivo(valor_Objetivo, player1);

                cout << "\n========= RONDA " << roundNumber << " =========\n"
                     << endl;

                // Turno del jugador 1
                cout << "Turno de: " << player1 << endl;

                turnoJugador(player1, cant_stock_player1, dados_Stock_Player1, valor_Objetivo, cant_stock_player2, puntos_player1);

                // Turno del jugador 2
                cout << "Turno de: " << player2 << endl;

                turnoJugador(player2, cant_stock_player2, dados_Stock_Player2, valor_Objetivo, cant_stock_player1,puntos_player2);
            }



            // EMPATE POR PUNTOS
           if(puntos_player1 == puntos_player2){

                cout << "EMPATE! Ambos jugadores han quedado con " << puntos_player1 << " puntos!" << endl;
                cout << "El stock de ambos jugadores es: " << cant_stock_player1 << endl;
                cout << "El stock de ambos jugadores es: " << cant_stock_player2 << endl;

            
            }
            
            // VICTORIA POR PUNTOS
            if (puntos_player1 > puntos_player2)
            {
                cout << "El jugador " << player1 << " ha ganado con " << puntos_player1 << " puntos!" << endl;
                cout << "El jugador " << player2 << " ha quedado con " << puntos_player2 << " puntos." << endl;
            }
            else
            {
                cout << "El jugador " << player2 << " ha ganado con " << puntos_player2 << " puntos!" << endl;
                cout << "El jugador " << player1 << " ha quedado con " << puntos_player1 << " puntos." << endl;
            }

            

            // VICTORIA AUTOMATICA
              if (cant_stock_player1 == 0)
              {
                // hacer una funcion que reciba por parametro el nombre del jugador y el stock
              }else if (cant_stock_player2 == 0)
              {
                /* code */
              }

             rlutil::anykey();
        }

        break;

        case 2:
        {

            cout << "estadisticas" << endl;
            rlutil::anykey();
        }
            
            break;
        case 3:
            {
                cout << " creditos " << endl;
                rlutil::anykey();
            }
            break;

        case 0:
            {

                opcion_0_cero(seguir_jugando);
            

            }

                break;
        
        }

    } while (seguir_jugando == true);

    return 0;
}
