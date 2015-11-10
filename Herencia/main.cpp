/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 10 de noviembre de 2015, 09:15 AM
 */

#include <cstdlib>
#include "Circulo.h"
#include "Cilindro.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Circulo c;
    
    c.SetRadio(5.46);
    c.imprime();
    cout << "\nArea= " << c.area() << endl;
    
    Cilindro cil;
    cil.SetRadio(4.4);
    cil.setAltura(5.5);
    cil.imprime();
    cout << "\nArea cilindro= " << cil.area() << endl;
    cout << "\nVolumen cilindro= " << cil.volumen() << endl;
    cout << "\nArea de la base = " << cil.Circulo::area() << endl;
    
    return 0;
}

