/* 
 * File:   ManejaArchivo.cpp
 * Author: Usuario
 * 
 * Created on 3 de noviembre de 2015, 08:50 AM
 */

#include "ManejaArchivo.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include <cstdlib>


ManejaArchivo::ManejaArchivo() {
    nombreArch = NULL;
}

ManejaArchivo::ManejaArchivo(char* nomb) {
    nombreArch = new char[strlen(nomb) + 1];
    strcpy(nombreArch, nomb);
}

ManejaArchivo::ManejaArchivo(char* nomb, char c) {
    nombreArch = new char[strlen(nomb) + 1];
    strcpy(nombreArch, nomb);
    if (c == 'c')
        crearArchivo();
    else if (c == 'm')
        mostrarArch();
}

ManejaArchivo::~ManejaArchivo() {
}

void ManejaArchivo::crearArchivo(void){
    if (!nombreArch){
        cerr << "No se colocó nombre al archivo\n";
        exit(1);
    }
    
    ofstream arch(nombreArch, ios::out | ios::binary);
    if (!arch){
        cerr << "Yiyi ez mid!" << endl;
        exit(1);
    }
    int cod;
    char nombre[40];
    double suel;
    while (cin >> cod){
        while (cin.get() != '\n');
        cin.getline(nombre, 40);
        cin >> suel;
        per.SetCodigo(cod);
        per.SetNombre(nombre);
        per.SetSueldo(suel);
        arch.write(reinterpret_cast < const char * > (&per), sizeof(per));
    }
    arch.close();
}

void ManejaArchivo::mostrarArch (void){
    if (!nombreArch){
        cerr << "No se colocó nombre al archivo\n";
        exit(1);
    }
    
    ifstream arch(nombreArch, ios::in | ios::binary);
    if (!arch){
        cerr << "Yiyi ez mid!" << endl;
        exit(1);
    }
    
    int tamArch, numReg;
    arch.seekg(0, ios::end);
    tamArch = arch.tellg();
    arch.seekg(0, ios::beg);
    numReg = tamArch / sizeof(per);
    for (int i=0; i < numReg; i++){
        arch.read(reinterpret_cast < char * > (&per), sizeof(per));
        per.imprime();
    }
    arch.close();
}

void ManejaArchivo::incrementarSueldo (double inc) {
    if (!nombreArch){
        cerr << "No se colocó nombre al archivo\n";
        exit(1);
    }
    
    fstream arch(nombreArch, ios::in | ios::out | ios::binary);
    if (!arch){
        cerr << "Yiyi ez mid!" << endl;
        exit(1);
    }
    
    int tamArch, numReg;
    double suel;
    arch.seekg(0, ios::end);
    tamArch = arch.tellg();
    arch.seekg(0, ios::beg);
    numReg = tamArch / sizeof(per);
    for (int i=0; i < numReg; i++){
        //arch.seekg(i*sizeof(per),ios::beg);
        arch.read(reinterpret_cast < char * > (&per), sizeof(per));
        suel = per.GetSueldo();
        per.SetSueldo(suel*inc);
        arch.seekg(i*sizeof(per),ios::beg);
        arch.write(reinterpret_cast < const char * > (&per), sizeof(per));
    }
    arch.close();
}