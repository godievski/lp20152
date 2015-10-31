/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 27 de octubre de 2015, 09:03 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "ClaseRect.h"
/*
 * 
 */
int main(int argc, char** argv) {

    ClaseRect r;
    r.set_altura(10.34);
    r.set_base(2.1);
    
    r.imprimeDatos();
    cout <<"Perimetro: " << r.perimetro() << endl;
    cout << "Area: " << r.area() << endl;
    
    r.leeDatos();
    r.imprimeDatos();
    return 0;
}

