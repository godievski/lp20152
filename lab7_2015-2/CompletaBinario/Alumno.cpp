/* 
 * File:   Alumno.cpp
 * Author: alulab14
 * 
 * Created on 6 de noviembre de 2015, 08:03 AM
 */

/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#include "Alumno.h"
#include <iostream>
using namespace std;


Alumno::Alumno() {
    promedio = 0;
    creditos = 0;
    anIn = 0; //Año de inicio
    semIn = 0; //Semestre que inicio
    anFin = 0; //Año de egresó
    semFin = 0; //Semestre que egresó
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetPromedio(double promedio) {
    this->promedio = promedio;
}

double Alumno::GetPromedio() const {
    return promedio;
}

void Alumno::SetSemFin(int semFin) {
    this->semFin = semFin;
}

int Alumno::GetSemFin() const {
    return semFin;
}

void Alumno::SetAnFin(int anFin) {
    this->anFin = anFin;
}

int Alumno::GetAnFin() const {
    return anFin;
}

void Alumno::SetSemIn(int semIn) {
    this->semIn = semIn;
}

int Alumno::GetSemIn() const {
    return semIn;
}

void Alumno::SetAnIn(int anIn) {
    this->anIn = anIn;
}

int Alumno::GetAnIn() const {
    return anIn;
}

void Alumno::SetNombre(char* n) {
    strcpy(nombre, n);
}

void Alumno::GetNombre(char *n) const {
    strcpy(n,nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::SetEspecialidad(char *e) {
    strcpy(especialidad, e);
}

void Alumno::GetEspecialidad(char *e) const {
    strcpy(e,especialidad);
}

void Alumno::mostrar(void) const
{
    cout << codigo << " " << nombre << " " << especialidad << endl;
    cout << anIn << "-" << semIn << "   ";
    cout << anFin << "-" << semFin << endl;
    cout << "Promedio: <" << promedio << ">" << endl;
    cout << "Creditos totales: " << creditos << endl;
    cout << "------------------------------------------------\n";
}