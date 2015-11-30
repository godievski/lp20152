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
#include <cstdlib>

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
    if (this != &llam){
        tiempo = llam.tiempo;
        SetNumero(llam.numero);
    }
    return *this;
}

int Llamada::operator == (Llamada& llam){
    return strcmp(numero, llam.numero) == 0;
}

int Llamada::operator > (Llamada &llam)
{
    char pp1[3] = {0}, pp2[3]={0}; //Codigo del pais
    char c1,c2; //Codigo de la ciudad
    int cmp;
    for (int i = 0; i < 2; i++){
        pp1[i] = numero[i];
        pp2[i] = llam.numero[i];
    }
    c1 = numero[2];
    c2 = llam.numero[2];
    if ((cmp = strcmp(pp1,pp2))==0){
      if (c1 == c2)
          return strcmp(&(numero[4]),&(llam.numero[4])) > 0;
      else
          return c1>c2;
    } else
        return cmp > 0;
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

int Llamada::GetCodPais(void)
{
    char c[3];
    c[0] = numero[0];
    c[1] = numero[1];
    c[2] = 0;
    return atoi(c);
}
