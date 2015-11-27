/* 
 * File:   Vehiculo.cpp
 * Author: Usuario
 * 
 * Created on 19 de noviembre de 2015, 02:46 PM
 */

#include "Vehiculo.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;


Vehiculo::Vehiculo() {
    chofer = NULL;
    placa = NULL;
    ruta = NULL;
    numAsientos = 0;
}

Vehiculo::~Vehiculo() {
    delete [] chofer;
    delete [] placa;
    if (ruta)
        for (int i = 0; ruta[i]; i++)
            delete [] ruta[i];
    delete [] ruta;
}

void Vehiculo::SetNumAsientos(int numAsientos) {
    this->numAsientos = numAsientos;
}

int Vehiculo::GetNumAsientos() const {
    return numAsientos;
}

void Vehiculo::SetChofer(char* chofer) {
    this->chofer = new char[strlen(chofer)+1];
    strcpy(this->chofer, chofer);
}

void Vehiculo::GetChofer(char* chofer) const {
    strcpy(chofer, this->chofer);
}

void Vehiculo::SetPlaca(char* placa) {
    this->placa = new char[strlen(placa) + 1];
    strcpy(this->placa, placa);
}

void Vehiculo::GetPlaca(char* placa) const {
    strcpy(placa, this->placa);
}

void Vehiculo::SetRuta(char** ruta, int cant)
{
    this->ruta = new char*[cant+1];
    for (int i = 0; i < cant; i++){
        this->ruta[i] = new char[strlen(ruta[i])+1];
        strcpy(this->ruta[i],ruta[i]);
    }
    this->ruta[cant] = NULL;
}

void Vehiculo::GetRuta(char* lugar, int ind)
{
    if (!ruta){
        lugar[0] = 0;
    } else {
        strcpy(lugar, ruta[ind]);
    }
}

void Vehiculo::impRuta (void)
{
    if (!ruta)
        return;
    if (!ruta[0])
        return;
    cout << ruta[0];
    for (int i = 1; ruta[i]; i++)
        cout << " - " << ruta[i];
}

char** Vehiculo::GetRuta (void)
{
    return ruta;
}