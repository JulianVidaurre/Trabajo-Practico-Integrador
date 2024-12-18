#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include "rlutil.h"

using namespace std;


void lanzarDados(int vecDados[]) {
    int i;
    for (i = 0; i < 6; i++) {
        //int valDado = 0;
        //while(valDado < 1 | valDado > 6){
        //    cout << "Ingreso valor dado del 1 al 6 numero " << (i + 1) << endl;
        //    cin >> valDado;
        //}
        //vecDados[i] = valDado;
        vecDados[i] = rand() % 6 + 1;
    }
}

void mostrarDados(int vecDados[]) {
    int i;
    cout << "Valores de los dados: ";
    for (i = 0; i < 6; i++) {
        cout << vecDados[i] << " ";
    }
    cout << endl;
}

int calcularPuntaje(int vecDados[]) {
    int vecConteo[7] = {0};
    int i;
    for (i = 0; i < 6; i++) {
        vecConteo[vecDados[i]]++;
    }

    bool esEscalera = true;
    for (i = 1; i <= 6; ++i) {
        if (vecConteo[i] != 1) {
            esEscalera = false;
            break;
        }
    }
    if (esEscalera) {
        cout << endl;
        cout << "  ESCALERA!" << endl;
        return 100;
    }

    int primerDado = vecDados[0];
    bool todosIguales = true;
    for (i = 0; i < 6; i++) {
        if (vecDados[i] != primerDado) {
            todosIguales = false;
            break;
        }
    }
    if (todosIguales) {
        if (primerDado == 6) {
            cout << "¡Sexteto de 6! Puntaje reseteado a 0." << endl;
            return -1;
        } else {
            cout << "Sexteto de " << primerDado << ": " << primerDado * 10 << " puntos." << endl;
            return primerDado * 10;
        }
    }

    int suma = 0;
    for (int i = 0; i < 6; i++) {
        suma += vecDados[i];
    }
    cout << "Suma de dados: " << suma << " puntos." << endl;
    return suma;
}

void mostrarPantallaTurno(int ronda, string jugadorActual, int puntaje1, string nombre1, int puntaje2 = -1, string nombre2 = "") {
    system("cls");
    cout << "--------------------------------" << endl;
    cout << "         RONDA N" << char(248) << " " << ronda << endl;
    cout << "    PROXIMO TURNO: " << jugadorActual << endl;
    cout << endl;
    cout << "PUNTAJE " << nombre1 << ": " << puntaje1 << " PUNTOS" << endl;
    if (puntaje2 != -1) {
        cout << "PUNTAJE " << nombre2 << ": " << puntaje2 << " PUNTOS" << endl;
    }
    cout << "--------------------------------" << endl;
    cout << "\nPRESIONAR UNA TECLA PARA CONTINUAR..." << endl;
    rlutil::anykey();
}

int unJugador() {
    string nombre;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    int dados[6];
    int puntajeTotal = 0;
    int maxPuntajeRonda = 0;
    int ronda = 1;
    int i;

    while (puntajeTotal < 100) {

        maxPuntajeRonda = 0;

        for (i = 1; i <= 3; ++i) {
            system("cls");
            cout << "TURNO DE: " << nombre << " | RONDA N" << char(248) << " " << ronda << " | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda << " PUNTOS" << endl;
            cout << "LANZAMIENTO N" << char(248) << " " << i << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << endl;
            lanzarDados(dados);
            mostrarDados(dados);
            int puntaje = calcularPuntaje(dados);
            if (puntaje == 100) {
                puntajeTotal = 100;
                break;
            } else if (puntaje == -1) {
                puntajeTotal = 0;
                maxPuntajeRonda = 0;
                break;
            } else {
                if (puntaje > maxPuntajeRonda) {
                    maxPuntajeRonda = puntaje;
                }
            }
            cout << endl;
            rlutil::anykey("Presiona una tecla para ver el siguiente lanzamiento...");
            cout << endl;
        }

        puntajeTotal += maxPuntajeRonda;

        if (puntajeTotal >= 100) {
            system("cls");
            cout << "FELICIDADES " << nombre << "! GANASTE LA PARTIDA!" << endl;
            cout << "PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
            cout << "NUMERO DE RONDAS: " << ronda << " RONDAS" << endl;
            break;
        }
        mostrarPantallaTurno(ronda, nombre, puntajeTotal, nombre);
        ronda++;
    }

    return puntajeTotal;
}

int dosJugadores(){
    string nombreJ1;
    cout << "Ingrese el nombre del primer jugador: ";
    cin >> nombreJ1;
    system("cls");
    string nombreJ2;
    cout << "Ingrese el nombre del segundo jugador: ";
    cin >> nombreJ2;
    int dadosJ1[6];
    int dadosJ2[6];
    int puntajeTotalJ1 = 0;
    int puntajeTotalJ2 = 0;
    int maxPuntajeRondaJ1 = 0;
    int maxPuntajeRondaJ2 = 0;
    int ronda = 1;
    int puntajeJ1;
    int puntajej2;
    int i;

    while(puntajeTotalJ1 < 100 && puntajeTotalJ2 <100) {
        maxPuntajeRondaJ1 = 0;

        for(i = 1; i <= 3; ++i) {
            system("cls");
            cout << "TURNO DE: "<< nombreJ1 << " | RONDA N" << char(248) << " " << ronda << " | PUNTAJE TOTAL: " << puntajeTotalJ1 << " PUNTOS" << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRondaJ1 << " PUNTOS" << endl;
            cout << "LANZAMIENTO N" << char(248) <<  " " << i << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << endl;
            lanzarDados(dadosJ1);
            mostrarDados(dadosJ1);
            puntajeJ1 = calcularPuntaje(dadosJ1);
            if (puntajeJ1 == 100) {
                puntajeTotalJ1 = 100;
                break;
            } else {
                if (puntajeJ1 > maxPuntajeRondaJ1) {
                    maxPuntajeRondaJ1 = puntajeJ1;
                 }
            }
            cout << endl;
            rlutil::anykey("Presione una tecla para ver el siguiente lanzamiento...");
            cout << endl;

        }

        puntajeTotalJ1 += maxPuntajeRondaJ1;
        mostrarPantallaTurno(ronda, nombreJ2, puntajeTotalJ1, nombreJ1, puntajeTotalJ2, nombreJ2);
        maxPuntajeRondaJ2 = 0;

        for(i = 1; i <= 3; ++i) {
            system("cls");
            cout << "TURNO DE: " << nombreJ2 << " | RONDA N" << char(248) << " " << ronda << " | PUNTAJE TOTAL: " << puntajeTotalJ2 << " PUNTOS" << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRondaJ2 << " PUNTOS" << endl;
            cout << "LANZAMIENTO N" << char(248) <<  " " << i << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << endl;
            lanzarDados(dadosJ2);
            mostrarDados(dadosJ2);
            puntajej2 = calcularPuntaje(dadosJ2);
            if (puntajej2 == 100) {
                 puntajeTotalJ2 = 100;
                 break;
            } else {
                if(puntajej2 > maxPuntajeRondaJ2) {
                     maxPuntajeRondaJ2 = puntajej2;
                }
            }
            cout << endl;
            rlutil::anykey("Presiona una tecla para ver el siguiente lanzamiento...");
            cout << endl;

        }

        puntajeTotalJ2 += maxPuntajeRondaJ2;
        mostrarPantallaTurno(ronda, nombreJ1, puntajeTotalJ1, nombreJ1, puntajeTotalJ2, nombreJ2);

        if (puntajeTotalJ1 >= 100) {
            system("cls");
            cout << "FELICIDADES " << nombreJ1 << "! GANASTE LA PARTIDA!" << endl;
            cout << "PUNTAJE TOTAL: " << puntajeTotalJ1 << " PUNTOS" << endl;
            cout << "NUMERO DE RONDAS: " << ronda << " RONDAS" << endl;
            break;
        }

        if (puntajeTotalJ2 >= 100) {
            system("cls");
            cout << "FELICIDADES " << nombreJ2 << "! GANASTE LA PARTIDA!" << endl;
            cout << "PUNTAJE TOTAL: " << puntajeTotalJ2 << " PUNTOS" << endl;
            cout << "NUMERO DE RONDAS: " << ronda << " RONDAS" << endl;
            break;
        }

        ronda++;
        rlutil::anykey("Presiona una tecla para continuar a la siguiente ronda...");
        cout << endl;

    }

    if (puntajeTotalJ1 > puntajeTotalJ2) {
        return puntajeTotalJ1;
    } else {
        return puntajeTotalJ2;
    }

}


#endif
