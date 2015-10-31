/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 21 de octubre de 2015, 09:46 AM
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
    ofstream archB ("datos.bin", ios::out | ios::binary);
    int cod; //code
    char name[MAX_NAME]; //name
    double sal; //salary
    
    if (!archB){
        cerr << "It has a virus!!! :(" << endl;
        exit (1);
    }
    
    while (cin >> cod){
        while (cin.get()!='\n');
        cin.getline(name, MAX_NAME);
        cin>>sal;
        archB.write(reinterpret_cast < const char * > (&cod), sizeof(int));
        //archB.write(reinterpret_cast < const char * > name, sizeof(char)*MAX_NAME);
        archB.write(reinterpret_cast < const char * > (name), sizeof(name));
        archB.write(reinterpret_cast < const char * > (&sal), sizeof(double));
    }
    
    
    return 0;
}

