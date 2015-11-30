/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 28 de noviembre de 2015, 10:03 PM
 */

#include <cstdlib>
#include <fstream>
using namespace std;
#include "Tablero.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Tablero mytab;
    ifstream fichas ("Fichas.txt", ios::in);
    if (!fichas){
        cerr << "ERROR\n";
        exit(1);
    }
    
    mytab.leerFichas(fichas);
    
    ifstream mov ("Movimientos.txt", ios::in);
    if (!mov){
        cerr << "ERROR\n";
        exit(1);
    }
    mytab.leerMovimientos(mov);
    
    mytab.impTablero();
    return 0;
}

