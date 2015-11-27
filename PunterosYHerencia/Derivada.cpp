/* 
 * File:   Derivada.cpp
 * Author: Usuario
 * 
 * Created on 17 de noviembre de 2015, 08:20 AM
 */

#include "Derivada.h"


void Derivada::SetAt2(int at2) {
    this->at2 = at2;
}

int Derivada::GetAt2() const {
    return at2;
}

void Derivada::leerDatos(void)
{
    int at;
    cout << "ClaseDerivada (leerDatos): " << endl;
    cout << "Atributo 1: ";
    cin >> at;
    SetAt1(at);
    cout << "Atributo 2: ";
    cin >> at2;
}

void Derivada::mostrarDatos(void)
{
    cout << "ClaseDerivada (mostrarDatos): " << endl;
    cout << "Atributo1: " << GetAt1() << endl;
    cout << "Atributo2: " << at2 << endl;
}