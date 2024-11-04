#include <iostream>

using namespace std;

int main()
{
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
                break;
            case 2:
                system("cls");
                break;
            case 3:
                system("cls");
                break;
            case 4:
                system("cls");
                cout << "Gracias por jugar!" << endl;
                break;
            default:
                system("cls");
                cout << "Opcion no valida. Intente de nuevo." << endl;
                system("pause");
        }
    }
    return 0;
}
