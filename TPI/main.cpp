#include <iostream>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"

using namespace std;

int main() {
    srand(time(0));

    int maxPuntaje = 0;
    int opcion = 0;

    while (opcion != 4) {
        system("cls");
        cout << "------ MENU PRINCIPAL ------" << endl;
        cout << "1. UN JUGADOR" << endl;
        cout << "2. DOS JUGADORES" << endl;
        cout << "3. PUNTUACION MAS ALTA" << endl;
        cout << "4. SALIR" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                system("cls");
                int puntaje1;
                puntaje1 = unJugador();
                if (puntaje1 > maxPuntaje) {
                    maxPuntaje = puntaje1;
                }
                system("pause");
                break;
            case 2:
                system("cls");
                int puntaje2;
                puntaje2 = dosJugadores();
                if (puntaje2 > maxPuntaje) {
                    maxPuntaje = puntaje2;
                }
                system("pause");
                break;
            case 3:
                system("cls");
                if (maxPuntaje > 0) {
                    cout << "LA MAXIMA PUNTUACION ES " << maxPuntaje << " PUNTOS" << endl;
                } else {
                    cout << "AUN NO HAY PUNTUACIONES REGISTRADAS." << endl;
                }
                system("pause");
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
