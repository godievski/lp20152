/* 
 * File:   ClaseRect.cpp
 * Author: Usuario
 * 
 * Created on 27 de octubre de 2015, 09:46 AM
 */

#include "ClaseRect.h"
#include <cstring>

void ClaseRect::SetAltura(double altura) {
    this->altura = altura;
}

double ClaseRect::GetAltura() const {
    return altura;
}

void ClaseRect::SetBase(double base) {
    this->base = base;
}

double ClaseRect::GetBase() const {
    return base;
}

void ClaseRect::SetNombre(char* ptNom) {
    nombre = new char[strlen(ptNom) + 1];
    strcpy(nombre, ptNom);
}

char* ClaseRect::GetNombre(char *ptNom) const {
    strcpy(ptNom, nombre);
    return ptNom;
}