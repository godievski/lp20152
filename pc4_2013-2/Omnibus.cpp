/* 
 * File:   Omnibus.cpp
 * Author: Usuario
 * 
 * Created on 19 de noviembre de 2015, 02:46 PM
 */

#include "Omnibus.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

Omnibus::Omnibus() {
    pasajeros = NULL;
    cantPas = 0;
}

Omnibus::~Omnibus() {
    if (this->pasajeros){
        void **arrayPas = (void **) this->pasajeros;
        for (int i = 0; arrayPas[i]; i++){
            void **PasXDest = (void **) arrayPas[i];
            if (PasXDest){
                for (int j = 0; PasXDest[j]; j++){
                    Pasajero* pas;
                    pas = (Pasajero*) PasXDest[j];
                    delete pas;
                }
            }
            delete PasXDest;
        }
        delete arrayPas;
    }
}

void Omnibus::SetPasajeros(int n)
{
    void** arrayPas = new void*[n+1];
    for (int i = 0; i < n; i++){
        void **pasXDest = new void*[GetNumAsientos()+1];
        pasXDest[0] = NULL;
        arrayPas[i] = pasXDest;
    }
    arrayPas[n] = NULL;
    this->pasajeros = arrayPas;
}

void Omnibus::agregarPasajero(Pasajero* pasajero, int ind)
{
    void** arrayPas = (void **) this->pasajeros;
    void** pasXDest = (void **) arrayPas[ind];
    int i = 0;
    for (i = 0; pasXDest[i]; i++);
    pasXDest[i] = pasajero;
    pasXDest[i+1] = NULL;
    cantPas++;
}

int Omnibus::disponibilidad (void)
{
    return cantPas < GetNumAsientos();
}

int Omnibus::verificaDestino (char* destino, int& indDest)
{
    char** rutaTemp;
    rutaTemp = GetRuta();
    for (indDest = 0; rutaTemp[indDest]; indDest++){
        if (strcmp(destino,rutaTemp[indDest]) == 0){
            return 1;
        }
    }
    return 0;
}

void Omnibus::impDatos (void)
{
    char placa[20], chofer[100], nombPas[100], destino[50];
    int dni;
    this->GetPlaca(placa);
    this->GetChofer(chofer);
    cout << " Placa: " << placa << endl;
    cout << " Chofer: " << chofer << endl;
    cout << " Ruta: ";
    this->impRuta();
    cout << endl;
    cout << " Pasajeros:\n";
    if (!pasajeros || cantPas == 0)
        cout << " NO HAY NINGUN PASAJERO REGISTRADO.\n";
    else{
        void** arrayPas = (void **) pasajeros;
        for (int i = 0; arrayPas[i]; i++){
            void **pasXDest = (void**) arrayPas[i];
            this->GetRuta(destino, i);
            cout << destino << ": (" << this->cantPas << '/' <<this->GetNumAsientos() << ')' << endl;
            cout << " Num " << "DNI          " << "Nombre" << endl; 
            Pasajero *pas;
            for (int j = 0; pasXDest[j];j++){
                pas = (Pasajero *) pasXDest[j];
                dni = pas->GetDni();
                pas->GetNombre(nombPas);
                cout << setw(3) << j+1 << setw(10) << dni << nombPas << endl;
            }
            cout << endl;
        }
    }
}