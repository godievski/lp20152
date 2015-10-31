/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 27 de octubre de 2015, 09:46 AM
 */

#include "ClaseRect.h"
#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

ostream & operator << (ostream &, ClaseRect &);

istream & operator >> (istream &, ClaseRect &);

int main(int argc, char** argv) {

    ClaseRect r;
    cin >> r;
    cout << r;
    
    return 0;
}

ostream & operator << (ostream &write, ClaseRect &rect)
{
    char n[100];
    write << "Nombre: " << rect.GetNombre(n) << endl;
    write << "Base: " << rect.GetBase() << endl;
    write << "Altura: " << rect.GetAltura() << endl;
    return write;
}

istream & operator >> (istream &lee, ClaseRect &rect)
{
    char n[100];
    double b, a;
    cout << "Ingrese nombre: ";
    lee.getline(n,100);
    rect.SetNombre(n);
    cout << "Ingrese base:y altura: ";
    lee >> b >> a;
    rect.SetBase(b);
    rect.SetAltura(a);
    return lee;
}

