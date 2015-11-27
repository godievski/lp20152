/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 13 de noviembre de 2015, 09:04 AM
 */

/*
 * Nombres: DIEGO ALONSO GUARDIA AYALA
 * Codigo: 20125849
 */

#include <cstdlib>
#include <fstream>
#include "funAux.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Cadena personas[100];
    int cant = 0;
    ifstream arch ("personas.txt", ios::in);
    if (!arch){
        cerr << "Error: No se abrio el archivo\n";
        exit(1);
    }
    
    leeNombres(arch, personas, cant);
    ordenaNombres(personas, cant);
    impNombres(personas, cant);
    return 0;
}

