/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 21 de octubre de 2015, 08:50 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int codigo;
    char *nombre;
    double sueldo;
    
    ifstream arch ("datos.txt", ios::in);
    if (!arch){
        cerr << "El archivo no se pudo abrir. :(" << endl;
        exit (1);
    }
    nombre = new char[200];
    
    while(arch.getline(nombre, 200)){
        cout << nombre << endl;
    }
    return 0;
}

