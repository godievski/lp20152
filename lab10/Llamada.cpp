/* 
 * File:   Llamada.cpp
 * Author: alulab14
 * 
 * Created on 27 de noviembre de 2015, 07:58 AM
 */
/*
 NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * COD: 20125849
 */


#include "Llamada.h"
#include <cstring>

Llamada::Llamada() {
    tiempo = 0;
}

void Llamada::SetTiempo(double tiempo) {
    this->tiempo = tiempo;
}

double Llamada::GetTiempo() const {
    return tiempo;
}

void Llamada::SetNumero(char* n) {
    strcpy(numero, n);
}

void Llamada::GetNumero(char* n) const {
    strcpy(n, numero);
}

ifstream& operator >> (ifstream& in, Llamada& llam){
    in >> llam.numero >> llam.tiempo;
    return in;
}


Llamada& Llamada::operator = (Llamada& llam)
{
    tiempo = llam.tiempo;
    SetNumero(llam.numero);
    return *this;
}

int Llamada::operator == (Llamada& llam){
    return strcmp(numero, llam.numero) == 0;
}

int Llamada::operator > (Llamada &llam)
{
    return strcmp(numero, llam.numero) > 0;
}

void Llamada::operator += (Llamada &llam)
{
    tiempo += llam.tiempo;
}

ostream& operator << (ostream& cout, Llamada& llam)
{
    cout << right << setw(15) << llam.numero 
         << right << setw(10) << llam.tiempo << endl;
    return cout;
}