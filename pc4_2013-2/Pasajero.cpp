/* 
 * File:   Pasajero.cpp
 * Author: Usuario
 * 
 * Created on 19 de noviembre de 2015, 03:57 PM
 */

#include "Pasajero.h"
#include <cstdlib>
#include <cstring>

Pasajero::Pasajero() {
    nombre = NULL;
    destino = NULL;
}

Pasajero::~Pasajero() {
    delete [] nombre;
    delete [] destino;
}

void Pasajero::SetDni(int dni) {
    this->dni = dni;
}

int Pasajero::GetDni() const {
    return dni;
}

void Pasajero::SetDestino(char* destino) {
    this->destino = new char[strlen(destino) + 1];
    strcpy(this->destino, destino);
}

void Pasajero::GetDestino(char* destino) const {
    strcpy(destino, this->destino);
}

void Pasajero::SetNombre(char* nombre) {
    this->nombre = new char[strlen(nombre)+ 1];
    strcpy(this->nombre, nombre);
}

void Pasajero::GetNombre(char* nombre) const {
    strcpy(nombre, this->nombre);
}

