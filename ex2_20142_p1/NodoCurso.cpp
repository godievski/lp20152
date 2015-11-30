/* 
 * File:   NodoCurso.cpp
 * Author: Usuario
 * 
 * Created on 30 de noviembre de 2015, 09:50 AM
 */

#include "NodoCurso.h"
#include <cstdlib>
#include <cstring>

NodoCurso::NodoCurso() {
    codigo = nombre = NULL;
    inicio = fin = NULL;
    longitud = 0;
    sgte = NULL;
}

NodoCurso::NodoCurso(char*codigo, char*nombre, double creditos){
    this->codigo = new char[strlen(codigo)+1];
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->codigo, codigo);
    strcpy(this->nombre, nombre);
    this->creditos = creditos;
    inicio = fin = NULL;
    longitud = 0;
    sgte = NULL;
}

ostream& operator << (ostream& cout, NodoCurso* curso)
{
    cout.precision(1);
    cout << "CODIGO: " << curso->codigo << endl;
    cout << "NOMBRE: " << curso->nombre << endl;
    cout << "CREDITOS: " << fixed << setw(5) << curso->creditos << endl;
    return cout;
}