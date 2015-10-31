/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 21 de octubre de 2015, 08:39 AM
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
    
    ofstream arch ("datos.txt", ios::out);
    if (!arch){
        cerr << "El archivo no se pudo abrir. :(" << endl;
        exit (1);
    }
    nombre = new char[100];
    while (cin >> codigo){
        while(cin.get() != '\n');
        cin.getline(nombre, 100);
        cin >> sueldo;
        arch << codigo << " " << nombre << " " << sueldo << endl;
    }
    return 0;
}

