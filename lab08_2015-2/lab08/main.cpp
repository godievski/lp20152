/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 13 de noviembre de 2015, 07:57 AM
 */

/*
 * Nombres: DIEGO ALONSO GUARDIA AYALA
 * Codigo: 20125849
 */

#include <cstdlib>
#include "Cadena.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    /*CONSTRUCTORES*/
    Cadena c;
    cout << "Longitud de cadena c: " << c.length() << endl;
    
    Cadena c1 (10);
    cout << "Longitud de cadena c1: " << c1.length() << endl;
    
    Cadena c2 ("Hola mundo!");
    c2.print();
    cout << endl;
    
    Cadena c3 = "Hola mundo x2!";
    c3.print();
    cout << endl;
    
    /*ASIGNACIONES*/
    Cadena cad1, cad2, cad3, cad4;
    cad1.assign("3 + 2");
    cad2.assign(cad1);
    cad3 = " + 1";
    cad4 = cad3;
    cout << "Cad1: ";
    cad1.print();
    cout << endl;
    
    cout << "Cad2: ";
    cad2.print();
    cout << endl;
    
    cout << "Cad3: ";
    cad3.print();
    cout << endl;
    
    cout << "Cad4: ";
    cad4.print();
    cout << endl;
    
    /*OTROS METODOS*/
    cad1.append(" + 999");
    cout << "Cad1: ";
    cad1.print();
    cout << endl;
    
    cad2.append(cad3);
    cout << "Cad2: ";
    cad2.print();
    cout << endl;
    
    cad1.swap(cad2);
    cout << "Swap: \n" << "Cad1: ";
    cad1.print();
    cout << endl;
    cout << "Cad2: ";
    cad2.print();
    cout << endl;
    
    /*OPERADORES SOBRECARGADOS*/
    Cadena d1, d2, d3;
    d1 = "Parte1";
    d2 = "Parte2";
    d3 = d1 + d2;
    cout << "Cadena d3: ";
    d3.print();
    cout << endl;
    
    cout << "d1 == Parte1 ?: " << d1.compare("Parte1") << endl;
    cout << "d2 == d1 ?: " << d2.compare(d1) << endl;
    cout << "d1 == d2 ?: " << (d1 == d2) << endl;
    cout << "d1 < d2 ?: " << (d1 < d2) << endl;
    cout << "d1 > d2 ?: " << (d1 > d2) << endl;
    
    return 0;
}

