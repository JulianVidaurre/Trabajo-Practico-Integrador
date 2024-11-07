#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include "rlutil.h"

using namespace std;

void lanzarDados(int vecDados[]) {
    int i;
    for (i = 0; i < 6; i++) {
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
        cout << "  ESCALERA! GANASTE LA PARTIDA!" << endl;
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

void jugarUnJugador() {
    string nombre;
    cout << "Ingrese su nombre: ";
    cin >> nombre;

    int puntajeTotal = 0;
    int maxPuntajeRonda = 0;
    int ronda = 1;

    srand(time(0));

    while (puntajeTotal < 100) {

        maxPuntajeRonda = 0;

        for (int lanzamiento = 1; lanzamiento <= 3; ++lanzamiento) {
            system("cls");
            cout << "TURNO DE " << nombre << " | RONDA N" << char(248) << " " << ronda << " | PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda << " PUNTOS" << endl;
            cout << "LANZAMIENTO N" << char(248) << " " << lanzamiento << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << endl;
            int dados[6];
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
            cout << "FELICIDADES " << nombre << ", GANASTE LA PARTIDA CON " << puntajeTotal << " PUNTOS EN " << ronda << " RONDAS!" << endl;
            break;
        }

        ronda++;
        rlutil::anykey("Presiona una tecla para continuar a la siguiente ronda...");
        cout << endl;
    }
}

#endif
