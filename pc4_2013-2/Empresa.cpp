/* 
 * File:   Empresa.cpp
 * Author: Usuario
 * 
 * Created on 19 de noviembre de 2015, 02:46 PM
 */

#include "Empresa.h"
#include <cstdlib>
#include <cstring>

Empresa::Empresa() {
    nombre = NULL;
    direccion = NULL;
    numBuses = 0;
    ruc = 0;
}

Empresa::~Empresa() {
    delete [] nombre;
    delete [] direccion;
}

void Empresa::leerRutas (ifstream &arch)
{
    char buffLinea[500];
    numBuses = 0;
    while (arch.getline(buffLinea, 500))
    {
        char *palabras[50];
        int cantPal = 0;
        separaPalabras(buffLinea, palabras, cantPal);
        flota[numBuses].SetPlaca(palabras[0]);
        flota[numBuses].SetChofer(palabras[1]);
        flota[numBuses].SetNumAsientos(atoi(palabras[cantPal-1]));
        flota[numBuses].SetRuta(&(palabras[2]),cantPal - 3);
        flota[numBuses].SetPasajeros(cantPal - 3);
        numBuses++;
    }
}
    
void Empresa::leerPasajeros (ifstream &arch)
{
    int dni;
    char buffLinea[500];
    Pasajero *pasajero;
    while (arch.getline(buffLinea,500))
    {
        pasajero = new Pasajero;
        char *palabras[5];
        int cantPal = 0;
        separaPalabras(buffLinea,palabras,cantPal);
        dni = atoi(palabras[0]);
        pasajero->SetNombre(palabras[1]);
        pasajero->SetDestino(palabras[2]);
        pasajero->SetDni(dni);
        agregarPasajero(pasajero);
    }
}
    
void Empresa::impReporte (void)
{
    cout << "\t\t\t\t Lista de Pasajeros\n";
    cout << " Empresa:  " << nombre << endl;
    cout << " Ruc:      " << ruc << endl;
    cout << " Direcion: " << direccion << endl;
    for (int i = 0; i < numBuses; i++){
        printNChar('=',50);
        cout << "Vehiculo Num " << i + 1 << endl;
        flota[i].impDatos();
    }
}

void Empresa::setDireccion(char* direccion) {
    this->direccion = new char[strlen(direccion) + 1];
    strcpy(this->direccion, direccion);
}

void Empresa::setRuc(int ruc) {
    this->ruc = ruc;
}

void Empresa::setNombre(char* nombre) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}
void Empresa::separaPalabras(char *linea, char **palabras,int& cantPal)
{
    cantPal = 0;
    if (!isblank(linea[0])){
        palabras[0] = linea;
        cantPal++;
    }
    for (int i = 1; linea[i]; i++){
        if (!isblank(linea[i]) && (isblank(linea[i-1]) || linea[i-1] == 0)){
            palabras[cantPal] = &(linea[i]);
            cantPal++;
        }
        if (!isblank(linea[i]) && isblank(linea[i+1])){
            linea[i+1] = 0;
            i++;
        }
    }
}

void Empresa::printNChar(char c, int n, int ln)
{
    for (int i = 0; i < n; i++)
        cout << c;
    if (ln)
        cout << endl;
}

void Empresa::agregarPasajero(Pasajero* pasajero)
{
    char buffDestino[50];
    pasajero->GetDestino(buffDestino);
    int indFlota, indDest;
    int inicioBus = 0;
    while (1){
        if (!buscarFlotaDestino(buffDestino,inicioBus, indFlota, indDest)){
            cerr << "No se encontro una flota disponible. " 
                 << "No se agrego pasajero DNI: "
                 << pasajero->GetDni() << endl;
            break;
        }
        if (flota[indFlota].disponibilidad()){
            flota[indFlota].agregarPasajero(pasajero, indDest);
            break;
        } else
            inicioBus = indFlota + 1;
    }
}

int Empresa::buscarFlotaDestino (char* destino, int iniBus,
                                 int& indFlota, int& indDest)
{
    int i;
    for (i = iniBus; i < numBuses; i++){
        if (flota[i].verificaDestino(destino, indDest)){
            indFlota = i;
            return 1;
        }
    }
    return 0;
}