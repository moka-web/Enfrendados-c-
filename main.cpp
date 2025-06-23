#include <iostream>
#include "Header.tp.h"
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include <iostream>

using namespace std;



int main()
{

    srand(time(0));

    int opcion, valor_Objetivo = 0;
    int roundNumber = 0;
    int dados_Stock_Player1[12] = {};
    int dados_Stock_Player2[12] = {};
    int cant_stock_player1 = 6;
    int cant_stock_player2 = 6;
    int puntos_player1 = 0;
    int puntos_player2 = 0;
    int puntaje_delGanador;
    bool seguir_jugando= true;
    bool primera_jugadaHecha = false;

    string player1, player2, nombre_delGanador;
   

    do
    {

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

        
            cout << endl;
            cout << "Jugador 1: " << player1 << ". Va a tirar primero!" << endl
                 << endl;
            cout << "Jugador 2: " << player2 << ". Va a tirar segundo!" << endl
                 << endl;
            rlutil::anykey();
            rlutil::cls();

            
            //bool finaliza_automaticamente = false;

            while ( roundNumber < 3 && cant_stock_player1 > 0 && cant_stock_player2 > 0)
            { 

                roundNumber++;

                cout << "\n========= RONDA " << roundNumber << " =========\n"
                     << endl;

            
                cout << "Turno de: " << player1 << " || " << puntos_player1 <<" puntos." <<endl;

                if ( cant_stock_player2 != 0 ) 
                {

                    turnoJugador(player1, cant_stock_player1, dados_Stock_Player1, valor_Objetivo, cant_stock_player2, puntos_player1);

                    
                    cout << "Stock actual de " << player1 << ": " << cant_stock_player1 << endl;
                    cout << "Stock actual de " << player2 << ": " << cant_stock_player2 << endl;
                    //cout <<endl;
                    cout << "=================================================================================================================" << endl;
                
                }
                
                rlutil::anykey();

            
                if ( cant_stock_player1 != 0)
                {
                    
                    cout <<endl;
                    cout << "Turno de: " << player2 <<" || " <<puntos_player1 <<" puntos." << endl;

                    turnoJugador(player2, cant_stock_player2, dados_Stock_Player2, valor_Objetivo, cant_stock_player1,puntos_player2);

                    cout << "Stock actual de " << player1 << " : " << cant_stock_player1 << endl;
                    cout << "Stock actual de " << player2 << " : " << cant_stock_player2 << endl;
                    cout << "=================================================================================================================" << endl;
            
            
                }
                    
                rlutil::anykey();

            }

            rlutil::cls();
            primera_jugadaHecha = true;

            // VICTORIA POR PUNTOS
          

            if (puntos_player1 > puntos_player2)
            {
            
              victoriaPorPuntos(player1,player2,puntos_player1,puntos_player2,puntaje_delGanador,nombre_delGanador);
            
            }
            else if (puntos_player1 < puntos_player2)
            {
              victoriaPorPuntos( player2,player1,puntos_player2,puntos_player1,puntaje_delGanador,nombre_delGanador );
            }
            else //la unica opcion que queda por descarte es si ambos tuvieron el mismo puntaje
            {
                cout << "Ambos jugadores tuvieron el mismo puntaje. EL juego queda EMPATADO." <<endl;
            }


            if (cant_stock_player1 == 0 )
            {

               victoriaAutomatica(player1, puntos_player1);

            }else if (cant_stock_player2 == 0 )
            {
                victoriaAutomatica(player2,puntos_player2) ; 

            }
            

        
            rlutil::anykey();
            rlutil::cls();

            //Todos los contadores vuelven a cero cuando termina un juego, permitiendo jugar de nuevo
            roundNumber = 0;
            cant_stock_player1 = 6;
            cant_stock_player2 = 6;
            puntos_player1 = 0;
            puntos_player2 = 0;

        }

        break;

        case 2:

            mostrar_estadisticas(puntaje_delGanador, nombre_delGanador, primera_jugadaHecha);
            rlutil::anykey();
            rlutil::cls();

            break;

        case 3:

            mostrar_creditos();
            rlutil::anykey();
            rlutil::cls();

            break;

        case 0:
            opcion_0_cero(seguir_jugando);
            break;
        }
    } while (seguir_jugando == true);

    return 0;
}
