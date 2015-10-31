/* 
 * File:   ClsCursos.cpp
 * Author: Usuario
 * 
 * Created on 29 de octubre de 2015, 09:56 AM
 */

#include "ClsCursos.h"
#include <cstring>
#include <fstream>
using namespace std;

ClsCursos::ClsCursos() {
}

ClsCursos::ClsCursos (char* nombre, char* codigo, double creditos) {
    SetNombre(nombre);
    SetCodigo(codigo);
    SetCreditos(creditos);
}

ClsCursos::ClsCursos(const ClsCursos& orig) {
}

ClsCursos::~ClsCursos() {
}

void ClsCursos::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double ClsCursos::GetCreditos() const {
    return creditos;
}

void ClsCursos::SetNombre(char* nombre) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);    
//    this->nombre = nombre;
}

char* ClsCursos::GetNombre(char* nombre) const {
    strcpy(nombre, this->nombre);
    return nombre;
}

void ClsCursos::SetCodigo(char* codigo) {
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
    //this->codigo = codigo;
}

char* ClsCursos::GetCodigo(char *codigo) const {
    strcpy(codigo, this->codigo);
    return codigo;
}

void ClsCursos::impDatos (ofstream & archOut)
{
    char nombre[100];
    char codigo[20];
    double creditos;
    GetNombre(nombre);
    GetCodigo(codigo);
    creditos = GetCreditos();
    archOut << "Codigo: " << codigo << endl;
    archOut << "Cursos: " << nombre << endl;
    archOut << "Creditos: " << creditos << endl;
    archOut << "--------------------------------------------------" << endl;
}