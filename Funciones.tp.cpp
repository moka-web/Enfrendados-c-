// Defino lo que hacen las funciones de Header.tp
// Defino lo que hacen las funciones de Header.tp
#include "Header.tp.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rlutil.h"
#include <limits>
using namespace std;

int tirarDado(int n)
{
    return rand() % n + 1;
};
//////////////////////////////////////////////////////////////
void mostrar_menu()
{

    cout << "Version de final" << endl;
    cout << R"(

            _____ _   _ ____________ _____ _   _______  ___ ______ _____ _____
           |  ___| \ | ||  ___| ___ \  ___| \ | |  _  \/ _ \|  _  \  _  /  ___|
           | |__ |  \| || |_  | |_/ / |__ |  \| | | | / /_\ \ | | | | | \ `--.
           |  __|| . ` ||  _| |    /|  __|| . ` | | | |  _  | | | | | | |`--. \
           | |___| |\  || |   | |\ \| |___| |\  | |/ /| | | | |/ /\ \_/ /\__/ /
           \____/\_| \_/\_|   \_| \_\____/\_| \_/___/ \_| |_/___/  \___/\____/
           )";
    cout << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << "-----------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << endl;
};
//////////////////////////////////////////////////////////////
void mostrar_creditos()
{
    cout << "\n ==========================================\n";
    cout << " |             CRDITOS                  |\n";
    cout << " ==========================================\n";
    cout << "\n Trabajo Pr ctico Integrador Programaci¢n\n\n";
    cout << " Grupo 10\n\n";
    cout << " Juan Alvarez Ruiz, 31785 " << endl;
    cout << " Delfina Sarkis, 32463 " << endl;
    cout << " Tomas Juarez, 32308 " << endl;
    cout << "\n\n A¤o: 2025" << endl;
    cout << " ==========================================\n\n";
};
//////////////////////////////////////////////////////////////
void mostrar_estadisticas(int puntaje_delGanador, string nombre_delGanador, bool primera_jugadaHecha)
{

    bool primer_puntaje = false;

    if (primera_jugadaHecha)
    { // si ya se hizo una jugada

        if (!primer_puntaje)
        {
            cout << "El puntaje mas alto lo hizo el jugador " << nombre_delGanador << "." << endl;
            cout << endl;
            cout << "Obtuvo un total de " << puntaje_delGanador << " puntos." << endl;
        }
        else
        {
            cout << "El puntaje mas alto lo hizo el jugador " << nombre_delGanador << "." << endl;
            cout << endl;
            cout << "Obtuvo un total de " << puntaje_delGanador << " puntos." << endl;
        }
    }
    else
    {
        cout << "Todavia no se realizo ninguna partida." << endl;
    }
};
//////////////////////////////////////////////////////////////
void declara_jugadores(string &player1, string &player2)
{
    /*player1 = "JD";
    player2 = "TOMAS";*/

    cout << "Ingrese el nombre de los jugadores" << endl
         << endl;
    cin >> player1;
    cout << endl
         << "y" << endl
         << endl;
    cin >> player2;
    cout << endl;
    cout << "Ahora cada jugador tirara los dados para saber quien empieza primero." << endl;
    cout << endl;
    rlutil::anykey();
    rlutil::cls();
};
//////////////////////////////////////////////////////////////
void empieza_primero(string &player1, string &player2)
{
    int dadoPlayer1, dadoPlayer2;
    string aux;
    do
    {
        dadoPlayer1 = tirarDado(6);
        cout << "Dado de " << player1 << " es " << dadoPlayer1 << endl
             << endl;
        dadoPlayer2 = tirarDado(6);
        cout << "Dado de " << player2 << " es " << dadoPlayer2 << endl;
        if (dadoPlayer1 > dadoPlayer2)
        {
            // no hace nada, lo deja como esta
        }
        else
        { // dadoPlayer1 < dadoPlayer2, el player 1 pasara a ser el player 2
            aux = player1;
            player1 = player2;
            player2 = aux;
        }
        if (dadoPlayer1 == dadoPlayer2)
        {
            cout << endl;
            cout << "Empatados, deben tirar de nuevo." << endl;
            cout << endl;
        }
    } while (dadoPlayer1 == dadoPlayer2);
};
//////////////////////////////////////////////////////////////
void tirada_dadosObjetivo(int &valor_Objetivo, string tirador)
{
    int dado_Objetivo1, dado_Objetivo2;
    cout << tirador << " ha lanzando los dados objetivo!" << endl
         << endl;
    dado_Objetivo1 = tirarDado(12);
    dado_Objetivo2 = tirarDado(12);
    valor_Objetivo = dado_Objetivo1 + dado_Objetivo2;


    cout << "Primer dado objetivo: " << dado_Objetivo1 << endl
         << endl;
    cout << "Segundo dado objetivo: " << dado_Objetivo2 << endl;
    cout << endl;
    cout << "El valor objetivo es: [" << valor_Objetivo << "]" << endl;
    cout << endl;
};
//////////////////////////////////////////////////////////////
void mostrar_dadosStock(int stock, int dadosStock_delJugador[])
{
    int i;
    for (i = 0; i < stock; i++)
    {
        if (i >= 0 && i < stock - 1)
        {
            dadosStock_delJugador[i] = tirarDado(6);
            cout << "[" << dadosStock_delJugador[i] << "]" << " - ";
        }
        else
        {
            dadosStock_delJugador[i] = tirarDado(6);
            cout << "[" << dadosStock_delJugador[i] << "]" /*<<" - "*/;
        }
    }
    cout << endl
         << endl;
    cout << "Posiciones:  ";

    for (i = 0; i < stock; i++)
    {
        if (i >= 0 && i < stock - 1)
        {
            cout << i + 1 << "  -  ";
        }
        else
        {
            cout << i + 1 << endl;
        }
    }
};
//////////////////////////////////////////////////////////////
void ofrecerDadoExtra(string nombreJugador, int &stockJugador, int &stockOponente)
{

    cout << nombreJugador << " solo tiene 1 dado. ¿Desea pedir un dado al oponente? (s/n): ";
    char respuesta;
    cin >> respuesta;

    if (respuesta == 's' && stockOponente > 1)
    {
        stockJugador++;
        stockOponente--;
        cout << "Se transfirió 1 dado del oponente." << endl;
    }
    else
    {
        cout << "No se puede transferir dados." << endl;
    }
}
//////////////////////////////////////////////////////////////
bool dadoYaFueElegido(int dado, int posicion_deDadosElegidos[], int cantidadElegidos)
{

    for (int i = 0; i < cantidadElegidos; i++)
    {

        if (dado == posicion_deDadosElegidos[i])
        {
            return true;
        }
    }
    return false;
};
//////////////////////////////////////////////////////////////
bool limpiarEntradaChar(char &entrada) {

    if (std::cin.fail()) {
        std::cin.clear(); // limpia el estado de error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpia el búfer
        entrada = ' '; // valor neutro
        rlutil::setColor(rlutil::RED);
        std::cout << "\nEntrada inválida. Intentá de nuevo.\n";
        rlutil::setColor(rlutil::WHITE);
        return false;
    }

    // limpia caracteres sobrantes del búfer (por si escriben "saaa")
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;

}
//////////////////////////////////////////////////////////////
bool limpiarEntradaInt(int &entrada) {

    if (cin.fail()) {
    
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        rlutil::setColor(rlutil::RED);
        cout << "entrada invalida ingrese un nuevo numero";
        
        entrada = -1 ; 
        
        rlutil::setColor(rlutil::WHITE);
        return false;

    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

void seleccionar_dados(int &posicion_dadoElegido, int posiciones_deDadosElegidos[], int &cantDadosElegida, int &sumaDadosSeleccionados, int &stockJugador, int dadosJugador[], string nombreJugador, int &stockOponente, /*JD*/ bool &fue_penalizado)   
{
    //////////////// seleccion de dados ////////////////

    bool continuarEligiendo = true;
    bool ingresoValido ;
    bool fue_elegido;
   
    do
    {
        // ingresa el dado que quiere elegir

        do
        {       

             cin >> posicion_dadoElegido;
             ingresoValido = limpiarEntradaInt(posicion_dadoElegido);

        } while ( ingresoValido == false);

        
        fue_elegido = dadoYaFueElegido(posicion_dadoElegido, posiciones_deDadosElegidos, cantDadosElegida);

        
        if (posicion_dadoElegido == 0)
        {
            cout << endl;
            cout << "NO HA REALIZADO UNA TIRADA EXISTOSA" << endl;

            if (stockOponente > 1)
            {
                stockJugador++;
                stockOponente--;
                rlutil::setColor(rlutil::RED);
                cout << "PENALIZACION: Se le suma un dado, " << nombreJugador << " ahora tiene " << stockJugador << " dados." << endl;
                rlutil::setColor(rlutil::WHITE);
                cout << "=================================================================================================================" << endl;
                fue_penalizado = true;
            }
            else
            {
                cout << "El oponente no tiene sufientes dados. NO SERA PENALIZADO." << endl;
            }

            continuarEligiendo = false; 
        }

        if ( posicion_dadoElegido >= 1 && posicion_dadoElegido <= stockJugador && fue_elegido == false )
        {

        // si elige un dado que no fue elegido, se agrega al vector posicion de dados elegidos
        posiciones_deDadosElegidos[cantDadosElegida] = posicion_dadoElegido;
        cantDadosElegida++;

        int valorDado = dadosJugador[posicion_dadoElegido - 1];
        sumaDadosSeleccionados += valorDado;

        cout << " `--> [" << valorDado << "]  /// ";


                if (cantDadosElegida > stockJugador)
                {
                    rlutil::setColor(rlutil::LIGHTBLUE);
                    cout << "Ya eligio todos sus dados stock." << endl
                        << endl;
                    rlutil::setColor(rlutil::WHITE);
                    continuarEligiendo = false; 
                    // te corta el ciclo de elegir dados cuando ya hayas elegido todos
                }
                else
                {

                    char seguir_eligiendo;
                    bool eleccion_valida = false;

                    do
                    {
                        rlutil::setColor(rlutil::YELLOW);

                        cout << "Desea seguir eligiendo? s para SI | n para NO.  ";

                        rlutil::setColor(rlutil::WHITE);
                        cin >> seguir_eligiendo;

                        // solo se puede ingresar s o n, cualquier otro ingreso rompe todo, arreglar eso al final

                        
                            if (!limpiarEntradaChar(seguir_eligiendo)) {

                                eleccion_valida = false;
                                cout << "entro en la limpiada del cin ";
                                continue;

                            }  // Si la entrada es inválida, no sigue procesando el resto de las condiciones


                        if (seguir_eligiendo == 's')
                        {
                            continuarEligiendo = true; // si quiere seguir eligiendo
                            eleccion_valida = true;
                        }
                        else if (seguir_eligiendo == 'n')
                        {
                            continuarEligiendo = false; // no quiere seguir eligiendo
                            eleccion_valida = true;
                        }
                        else
                        {
                            cout << endl;
                            rlutil::setColor(rlutil::RED);
                            cout << "Opcion invalida.  ";
                            rlutil::setColor(rlutil::WHITE);
                            eleccion_valida = false;
                        }
                        cout << endl;


                    } while (!eleccion_valida);
                }
    }
    else if (fue_elegido == true)
    {
        cout << "Ya eligió ese número, elija otro." << endl
             << endl;
    }
    else
    {
        rlutil::setColor(rlutil::RED);
        cout << "No es una opción válida. Elija de nuevo." << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << endl;
    }
}
while (continuarEligiendo);
  
};
//////////////////////////////////////////////////////////////
void procesarTiradaExitosa(string nombreJugador, int &stockJugador, int &stockOponente, int sumaDadosSeleccionados, int &cantDadosElegida, int posiciones_deDadosElegidos[], int &puntosJugador)
{
    int dadosARestar = cantDadosElegida;
    int puntaje = cantDadosElegida * sumaDadosSeleccionados;
    puntosJugador += puntaje;

    cout << endl;

    rlutil::setColor(rlutil::GREEN);
    cout << "Felicidades hizo una TIRADA EXITOSA con " << cantDadosElegida << " dados." << endl;
    rlutil::setColor(rlutil::WHITE);

    cout << "PUNTAJE ACTUAL: " << puntosJugador << endl;

    stockJugador -= dadosARestar;

    for (int i = 0; i < 12; i++)
    {
        posiciones_deDadosElegidos[i] = 0;
    }

    cout << "Se le sumaran " << cantDadosElegida << " al stock del oponente." << endl
         << endl;
    cout << "Al jugador " << nombreJugador << " ahora le quedan " << stockJugador << " dados." << endl
         << endl;

    stockOponente += cantDadosElegida;
    cantDadosElegida = 0;

    // victoria automática

    if (stockJugador == 0)
    {

        rlutil::setColor(rlutil::LIGHTBLUE);
        cout << nombreJugador << " se quedó sin dados y GANA AUTOMÁTICAMENTE!" << endl;
        rlutil::setColor(rlutil::WHITE);
        puntosJugador += 10000; // asigna 10.000 puntos por victoria automática
        // cambie 10.000 a 10000, con 10.000 solo suma 10 puntos, tal vez sea por el ide
        cout << "PUNTOS ACTUALES: " << puntosJugador << endl;


    }


    cout << "=================================================================================================================" << endl;
}
//////////////////////////////////////////////////////////////
void turnoJugador(string nombreJugador, int &stockJugador, int dadosJugador[], int objetivo, int &stockOponente, int &puntosJugador)
{

    // bool finalizo_conCero;

    tirada_dadosObjetivo(objetivo, nombreJugador);

    /*if (stockJugador == 1)
    {
        ofrecerDadoExtra(nombreJugador, stockJugador, stockOponente);
    }*/

    //////////////// MOSTRAR DADOS DEL JUGADOR ///////////////

    cout << "cantidad de dados stock " << stockJugador << endl;
    cout << endl;
    cout << "Valores:    ";

    mostrar_dadosStock(stockJugador, dadosJugador);

    cout << endl;

    //////////////// SELECCION DE DADOS  ///////////////

    cout << "Elija los dados a sumar para llegar al numero objetivo [" << objetivo << "]" << endl;
    cout << endl;
    cout << "Seleccione los dados de acuerdo a su posicion del 1 al " << stockJugador << " | 0 para finalizar la ronda como NO EXITOSA." << endl;
    cout << endl;

    int sumaDadosSeleccionados = 0;
    int posicion_dadoElegido, cantDadosElegida = 0;
    int posiciones_deDadosElegidos[12] = {};

    bool fue_penalizado = false;

    seleccionar_dados(
        posicion_dadoElegido,
        posiciones_deDadosElegidos,
        cantDadosElegida,
        sumaDadosSeleccionados,
        stockJugador,
        dadosJugador,
        nombreJugador,
        stockOponente,
        fue_penalizado
    );

    //////////////// FIN SELECCION DE DADOS ////////////////

    // cout << endl;

    if (!fue_penalizado)
    {
        cout << "Suma de los dados elegidos: " << sumaDadosSeleccionados << endl;
        cout << "=================================================================================================================" << endl;
    }

    ////////////////// COMPROBAR TIRADA EXITOS  ////////////////////////////////

    if (sumaDadosSeleccionados == objetivo)
    {
        procesarTiradaExitosa(
            nombreJugador,
            stockJugador,
            stockOponente,
            sumaDadosSeleccionados,
            cantDadosElegida,
            posiciones_deDadosElegidos,
            puntosJugador);
    }
    else if (!fue_penalizado)
    {
        if (stockOponente > 1)
        {
            cout << endl;
            cout << "No ha llegado al valor objetivo." << endl;
            stockJugador++;
            stockOponente--;
            rlutil::setColor(rlutil::RED);
            cout << "PENALIZACION: Se le suma un dado, " << nombreJugador << " ahora tiene " << stockJugador << " dados." << endl
                 << endl;
            ;
            rlutil::setColor(rlutil::WHITE);
            cout << "=================================================================================================================" << endl;
        }
    }
};
//////////////////////////////////////////////////////////////
void victoriaAutomatica(string &nombrePlayer , int &puntosPlayer){

                rlutil::setColor(rlutil::LIGHTBLUE);
                cout << nombrePlayer << " se quedó sin dados y GANA AUTOMÁTICAMENTE!" << endl;
                rlutil::setColor(rlutil::WHITE);
                puntosPlayer += 10000; // asigna 10.000 puntos por victoria automática
                // cambie 10.000 a 10000, con 10.000 solo suma 10 puntos, tal vez sea por el ide
                cout << "PUNTOS ACTUALES: " << puntosPlayer << endl;
            
            }

//////////////////////////////////////////////////////////////            
void victoriaPorPuntos( string ganador, string perdedor, int puntosGanador, int puntosPerdedor , int &puntaje_delGanador, string &nombre_delGanador ){
                        
                        puntaje_delGanador = puntosGanador;
                        nombre_delGanador = ganador;

                        cout << "El jugador " << ganador << " ha ganado con " << puntosGanador << " puntos!" << endl;
                        cout <<endl;
                        cout << "El jugador " << perdedor << " ha quedado con " << puntosPerdedor << " puntos." << endl;

                }
//////////////////////////////////////////////////////////////
void opcion_0_cero(bool &seguir_jugando)
{
    char opcion_salirSIoNO;
    bool ingreso_correcto;
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    cout << "Seguro que desea salir?" << endl;
    cout << endl;
    cout << "s para SI | n para NO y volver al menu principal" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    do
    {
        cin >> opcion_salirSIoNO;

        if (opcion_salirSIoNO == 's')
        {
            cout << endl;
            cout << "Gracias vuelva prontos!!" << endl;
            seguir_jugando = false; // no quiere seguir jugando
            ingreso_correcto = true;
        }
        else if (opcion_salirSIoNO == 'n')
        {
            rlutil::cls();
            seguir_jugando = true; // si quiere seguir jugando
            ingreso_correcto = true;
        }
        else
        {
            rlutil::setColor(rlutil::RED);
            cout << "Opcion invalida." << endl;
            rlutil::setColor(rlutil::WHITE);
            ingreso_correcto = false;
        }
    } while (ingreso_correcto == false);
};

