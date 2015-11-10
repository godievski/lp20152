/* 
 * File:   Medico.cpp
 * Author: Usuario
 * 
 * Created on 5 de noviembre de 2015, 03:21 PM
 */

#include "Medico.h"

Medico::Medico(int cod) {
    codigo = cod;
    sueldo = 0;
    for (int i = 0; i < MAX_NOMBRE; i++)
        nombre[i] = apellido[i] = especialidad[i] = 0;
}

void Medico::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Medico::GetSueldo() const {
    return sueldo;
}

void Medico::SetEspecialidad(char* esp) {
    if (!esp)
        strcpy(especialidad, esp);
}

void Medico::GetEspecialidad(char *esp) const {
    strcpy(esp, especialidad);
}

void Medico::SetApellido(char* ap) {
    if (!ap)
        strcpy(apellido, ap);
}

void Medico::GetApellido(char* ap) const {
    strcpy(ap, apellido);
}

void Medico::SetNombre(char *nom) {
    if (!nom)
        strcpy(nombre, nom);
}

void Medico::GetNombre(char* nom) const {
    strcpy(nom, nombre);
}

int Medico::GetCodigo() const {
    return codigo;
}

void Medico::imprime (void) const {
    cout << "Codigo: " << codigo << endl;
    cout << "Nombre y Apellido: " << nombre << " " << apellido << endl;
    cout << "Especialidad: " << especialidad << endl;
    cout << "Sueldo: " << sueldo << endl;
    cout << "----------------------------------------------------------\n";
}

