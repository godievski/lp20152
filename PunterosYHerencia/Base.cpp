/* 
 * File:   Base.cpp
 * Author: Usuario
 * 
 * Created on 17 de noviembre de 2015, 08:17 AM
 */

#include "Base.h"


void Base::SetAt1(int at1) {
    this->at1 = at1;
}

int Base::GetAt1() const {
    return at1;
}


void Base::leerDatos(void)
{
    cout << "CLaseBase (leerDatos): " << endl;
    cout << "Atributo 1: ";
    cin >> at1;
}

void Base::mostrarDatos(void)
{
    cout << "ClaseBase (mostrarDatos): " << endl;
    cout << "Atributo1: " << at1 << endl;
}