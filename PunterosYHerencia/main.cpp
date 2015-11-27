/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 17 de noviembre de 2015, 08:16 AM
 */

#include <cstdlib>
#include "Base.h"
#include "Derivada.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Base* b;
    b = new Derivada;
    
    b->leerDatos();
    b->mostrarDatos();
    
    return 0;
}

