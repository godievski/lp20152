/* 
 * File:   Persona.cpp
 * Author: Usuario
 * 
 * Created on 3 de noviembre de 2015, 08:31 AM
 */

#include "Persona.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetNombre(char* nombre) {
    strcpy(this->nombre, nombre);
}

void Persona::GetNombre(char* nombre) const {
    strcpy(nombre, this->nombre);
}

void Persona::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Persona::GetCodigo() const {
    return codigo;
}

void Persona::imprime() const {
    cout << setw(10) << codigo << setw(40) << nombre << setw(10) << sueldo;
    cout << endl;
}