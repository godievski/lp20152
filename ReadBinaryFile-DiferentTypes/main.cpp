/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 21 de octubre de 2015, 09:54 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_NAME 40

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archB ("datos.bin", ios::in | ios::binary);
    int cod;
    char name[MAX_NAME];
    double sal;
    
    if (!archB){
        cerr << "It has a virus!!! :(" << endl;
        exit (1);
    }
    
    archB.read(reinterpret_cast < char * > (&cod), sizeof(int));
    
    while (archB && !archB.eof()){
        archB.read(reinterpret_cast < char * > (name), sizeof(name));
        archB.read(reinterpret_cast < char * > (&sal), sizeof(double));
        
        cout << cod << " " << name << " " << sal << endl;
        
        archB.read(reinterpret_cast < char * > (&cod), sizeof(int));
    }
    return 0;
}
