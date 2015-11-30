/* 
 * File:   Ficha.cpp
 * Author: Usuario
 * 
 * Created on 28 de noviembre de 2015, 10:03 PM
 */

#include "Ficha.h"
#include <cstring>

void Ficha::mover(int cant, char t)
{
    this->fila = (this->columna += cant);
}

void Ficha::setTipo(char tipo) {
    this->tipo = tipo;
}

char Ficha::getTipo() const {
    return tipo;
}

void Ficha::setColumna(int columna) {
    this->columna = columna;
}

int Ficha::getColumna() const {
    return columna;
}

void Ficha::setFila(int fila) {
    this->fila = fila;
}

int Ficha::getFila() const {
    return fila;
}

void Ficha::setId(char* id) {
    strcpy(this->id, id);
}

void Ficha::getId(char* id) const {
    strcpy(id, this->id);
}
