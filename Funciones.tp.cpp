// Defino lo que hacen las funciones de Header.tp
#include "Header.tp.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rlutil.h"
using namespace std;
// 1

int tirarDado(int n){
    return rand() % n + 1;};
//////////////////////////////////////////////////////////////
void mostrar_menu()
{

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
void declara_jugadores(string &player1, string &player2)
{
    player1 = "JD";
    player2 = "TOMAS";

    /*cout << "Ingrese el nombre de los jugadores" <<endl << endl;
    cin >> player1;
    cout <<endl <<"y" <<endl <<endl;
    cin >> player2;
    cout <<endl;
    cout <<"Ahora cada jugador tirara los dados para saber quien empieza primero." <<endl;
    cout <<endl;
    rlutil::anykey();
    rlutil::cls();*/
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
    /*if(stock > 10){

    }*/

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
void ofrecerDadoExtra(string nombreJugador, int &stockJugador, int &stockOponente){

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
    }}
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
char confirmarEleccion() {
    char eleccion;
    do {
        cout << "¿Desea seguir eligiendo? (s para SI | n para NO): ";
        cin >> eleccion;
        eleccion = tolower(eleccion);
    } while (eleccion != 's' && eleccion != 'n');

    return eleccion;
}
//////////////////////////////////////////////////////////////
void procesarTiradaExitosa(string nombreJugador, int &stockJugador, int &stockOponente, int sumaDadosSeleccionados, int &cantDadosElegida, int posiciones_deDadosElegidos[] , int &puntosJugador){
    int dadosARestar = cantDadosElegida;
    int puntaje = cantDadosElegida * sumaDadosSeleccionados;
    puntosJugador += puntaje;

    cout << endl;
    cout << "Felicidades hizo una TIRADA EXITOSA con " << cantDadosElegida << " dados." << endl;
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
        cout << "\n ¡" << nombreJugador << " se quedó sin dados y GANA AUTOMÁTICAMENTE!" << endl;
        puntosJugador += 10000; // asigna 10.000 puntos por victoria automática
        cout << "PUNTOS ACTUALES: " << puntosJugador << endl;
     
    }

    cout << "========================================================================" << endl
         << endl;}
//////////////////////////////////////////////////////////////

void procesarTiradaNoExitosa(
    int sumaDadosSeleccionados,
    int objetivo,
    string nombreJugador,
    int &stockJugador,
    int &stockOponente
) {
    cout << "\nTIRADA NO EXITOSA." << endl;
    cout << "Suma obtenida: " << sumaDadosSeleccionados << ", pero el objetivo era " << objetivo << "." << endl;
    cout << "Se le sumara un dado al jugador " << nombreJugador << "." << endl;

    if (stockOponente > 1) {
        stockJugador++;
        stockOponente--;
        cout << "PENALIZACIÓN: Se le suma un dado. " << nombreJugador << " ahora tiene " << stockJugador << " dados.\n";
    } else {
        cout << "No será penalizado.\n";
        cout << "El oponente no tiene suficientes dados para transferir.\n";
    }
}

//////////////////////////////////////////////////////////////
void seleccionar_dados(int &posicion_dadoElegido, int posiciones_deDadosElegidos[], int &cantDadosElegida, int &sumaDadosSeleccionados, int stockJugador, int dadosJugador[], string nombreJugador, int &stockOponente)
{

   
   bool continuarEligiendo = true;
    cout << "\nElija un dado del 1 al " << stockJugador << " o 0 para finalizar la ronda como NO EXITOSA\n" << endl;

    do {
        cin >> posicion_dadoElegido;

        bool fue_elegido = dadoYaFueElegido(posicion_dadoElegido, posiciones_deDadosElegidos, cantDadosElegida);

        if (posicion_dadoElegido == 0) {
            // Ronda no exitosa
            
            continuarEligiendo = false;
            
            cout << "\n Tirada NO EXITOSA. \n";
            cout << endl; 
            cout << "Suma de los dados elegidos: " << sumaDadosSeleccionados << endl;
            cout << "Se le sumara un dado al jugador " << nombreJugador << ".\n";
            cout << "Se le restara un dado al oponente.\n" << endl;
            
            stockJugador ++;
            stockOponente --;

        }
        else if (posicion_dadoElegido < 0 || posicion_dadoElegido > stockJugador) {
            // Penalización por valor inválido

            cout << "\nNO HA REALIZADO UNA TIRADA EXITOSA\n";


            if (stockOponente > 1) {

                stockJugador++;
                stockOponente--;

                cout << "PENALIZACIÓN: Se le suma un dado. " << nombreJugador << " ahora tiene " << stockJugador << " dados.\n";

            } else {

                cout << "No será penalizado.\n";

            }
        }
        else if (!fue_elegido) {
            // Dado válido y no repetido

            posiciones_deDadosElegidos[cantDadosElegida] = posicion_dadoElegido - 1;   // Guardar la posición del dado elegido (ajustado a índice 0)
            cantDadosElegida++;

            int valorDado = dadosJugador[posicion_dadoElegido - 1]; // obtener el valor del dado elegido

            sumaDadosSeleccionados += valorDado; // Sumar el valor del dado elegido a la suma total

            cout << " `--> [" << valorDado << "]  /// "; // Mostrar el valor del dado elegido
            cout << "Suma actual: " << sumaDadosSeleccionados << "\n";


                if (cantDadosElegida != stockJugador) {
                    
                    char seguir_eligiendo = confirmarEleccion();

                    continuarEligiendo = (seguir_eligiendo == 's'); // Continuar eligiendo si la respuesta es 's'

                    cout << endl;

                }else{
                    cout << "No puede elegir más dados que los disponibles en su stock." << endl;
                    continuarEligiendo = false; // Termina la selección si se supera el stock
                }; 
           


        }
        else {
            // Dado ya elegido
            cout << "Ya eligió ese número, elija otro.\n" << endl;
        }

    } while ( continuarEligiendo == true );

 
};
//////////////////////////////////////////////////////////////
void turnoJugador(string nombreJugador, int &stockJugador, int dadosJugador[], int objetivo, int &stockOponente , int &puntosJugador)
{

    tirada_dadosObjetivo(objetivo, nombreJugador);

    //////////////// MOSTRAR DADOS DEL JUGADOR ///////////////

    cout << "cantidad de dados stock " << stockJugador << endl;
    cout << endl;
    cout << "Valores:    ";

    mostrar_dadosStock(stockJugador, dadosJugador);

    cout << endl;

    //////////////// SELECCION DE DADOS  ///////////////

    cout << "Elija los dados a sumar para llegar al numero objetivo [" << objetivo << "]" << endl;
    cout << endl;
    cout << "Seleccione los dados de acuerdo a su posicion del 1 al " << stockJugador << "." << endl;
    cout << endl;
    cout << "La seleccion incorrecta de un dado sera penalizada como RONDA NO EXITOSA." << endl;
    cout << endl;
    cout << "Presione 0 para finalizar la ronda como NO EXITOSA" << endl;
    cout << endl;
    cout << "===============================================" << endl;
    cout << endl;

    int sumaDadosSeleccionados = 0;
    int posicion_dadoElegido, cantDadosElegida = 0;
    int posiciones_deDadosElegidos[12] = {};

    seleccionar_dados(
        posicion_dadoElegido,
        posiciones_deDadosElegidos,
        cantDadosElegida,
        sumaDadosSeleccionados,
        stockJugador,
        dadosJugador,
        nombreJugador,
        stockOponente
    );


        //////////////// FIN SELECCION DE DADOS ////////////////

    cout << endl;
    cout << "Suma de los dados elegidos: " << sumaDadosSeleccionados << endl;


    if (sumaDadosSeleccionados == objetivo  )
    {
        procesarTiradaExitosa(
            nombreJugador,
            stockJugador,
            stockOponente,
            sumaDadosSeleccionados,
            cantDadosElegida,
            posiciones_deDadosElegidos, puntosJugador);
    }

    if (sumaDadosSeleccionados != objetivo) {

      procesarTiradaNoExitosa(
        sumaDadosSeleccionados,
        objetivo,
        nombreJugador,
        stockJugador,
        stockOponente
    );
    }


    
};
//////////////////////////////////////////////////////////////
void opcion_0_cero(bool &seguir_jugando)
{
    char opcion_salirSIoNO;
    bool ingreso_correcto;
    rlutil::cls();
    cout << "Seguro que desea salir?" << endl;
    cout << endl;
    cout << "s para SI | n para NO y volver al menu principal" << endl;
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
            cout << "Opcion invalida." << endl;
            ingreso_correcto = false;
        }
    } while (ingreso_correcto == false);
};
