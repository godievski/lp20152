/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 21 de octubre de 2015, 09:12 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archB ("datos.bin", ios::in | ios::binary);
    int dato[20];
    
    if (!archB){
        cerr << "El archivo tiene VIRUS! :(" << endl;
        exit (1);
    }
    
    archB.seekg(0, ios::end);
    int numReg = archB.tellg() / sizeof(int);
    
    archB.seekg(0, ios::beg);
//    archB.read(reinterpret_cast < char * > (&dato), sizeof(int)*numReg);
    for (int i = 0; i < numReg; i++)
        archB.read(reinterpret_cast < char * > (&dato[i]), sizeof(int));
    for (int i = 0; i < numReg; i ++)
        cout << dato[i] << endl;
    
    return 0;
}

