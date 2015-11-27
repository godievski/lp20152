/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 19 de noviembre de 2015, 02:45 PM
 */

#include <cstdlib>
#include "Empresa.h"
#include <fstream>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Empresa godie;
    
    godie.setDireccion("El Limbo");
    godie.setNombre("Matasanos S.A.C.");
    godie.setRuc(666999666);
    
    ifstream archRutas ("Rutas.txt", ios::in);
    if (!archRutas){
        cerr << "Error al abrir archivo Rutas.txt\n";
        exit(1);
    }
    godie.leerRutas(archRutas);
    
    ifstream archPas ("Pasajeros2.txt", ios::in);
    if (!archPas){
        cerr << "Error al abrir el archivo Pasajeros.txt\n";
        exit(1);
    }
    godie.leerPasajeros(archPas);
    
    godie.impReporte();
    
    return 0;
}

