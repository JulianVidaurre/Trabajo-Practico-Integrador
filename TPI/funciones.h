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
        cout << "ESCALERA! GANASTE LA PARTIDA!" << endl;
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

#endif
