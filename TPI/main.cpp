#include <iostream>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"

using namespace std;



int main()
{
    int maxPuntaje = 0;
    int opcion = 0;

    while (opcion != 4) {

        cout << "------ MENU PRINCIPAL ------" << endl;
        cout << "1. UN JUGADOR" << endl;
        cout << "2. DOS JUGADORES" << endl;
        cout << "3. PUNTUACION MAS ALTA" << endl;
        cout << "4. SALIR" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;

        switch(opcion) {
            case 1:

                int puntaje1;
                puntaje1 = jugarUnJugador();
                if (puntaje1 > maxPuntaje) {
                    maxPuntaje = puntaje1;
                }

                break;
            case 2:

                int puntaje2;
                puntaje2 = dosJugadores();
                if (puntaje2 > maxPuntaje) {
                    maxPuntaje = puntaje2;
                }

                break;
            case 3:
                cout << "LA MAXIMA PUNTUACION ES " << maxPuntaje << endl;

                break;
            case 4:

                cout << "Gracias por jugar!" << endl;

                break;
            default:

                cout << "Opcion no valida. Intente de nuevo." << endl;

        }
    }
    return 0;
}

