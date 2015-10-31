/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 27 de octubre de 2015, 08:56 AM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout << "Hola mundo" << endl;
    
    fstream archB ("datos.bin", ios::in | ios::out | ios::binary);
    int tamArch, tamReg, numReg;
    double sal;
    
     if (!archB){
        cerr << "It has a virus!!! :(" << endl;
        exit (1);
    }
    
    tamReg = sizeof(int) + sizeof(char) * 40 + sizeof(double);
    archB.seekg(0, ios::end);
    tamArch = archB.tellg();
    archB.seekg(0, ios::beg);
    numReg = tamArch / tamReg;
    
    cout << numReg << " " << tamArch << " " << tamReg << endl;
    
    return 0;
    int desplazamientoReg = sizeof(int) + sizeof(char) * 40;
    for (int i = 0; i < numReg; i++){
        archB.seekg(desplazamientoReg, ios::cur);
        archB.read(reinterpret_cast< char* > (&sal), sizeof(double));
        sal *=2;
        archB.seekg(-sizeof(double),ios::cur);
        archB.write(reinterpret_cast< const char * >(&sal), sizeof(double));
    }
    archB.close();
    
    return 0;
}

