/* 
 * File:   ClaseRect.cpp
 * Author: Usuario
 * 
 * Created on 27 de octubre de 2015, 09:14 AM
 */
#include <iostream>
#include "ClaseRect.h"
using namespace std;

void ClaseRect::set_base(double v)
{
    base = v;
}

double ClaseRect::get_base(void)
{
    return base;
}

void ClaseRect::set_altura(double v)
{
    altura = v;
}

double ClaseRect::get_altura(void)
{
    return altura;
}

void ClaseRect::leeDatos(void)
{
    cout<<"Ingrese la base y la altura: ";
    cin>>base>>altura;
}

void ClaseRect::imprimeDatos(void)
{
    cout << "Base:   " << base << endl;
    cout << "Altura: " << altura << endl;
}

double ClaseRect::area(void)
{
    return altura*base;
}

double ClaseRect::perimetro(void)
{
    return 2*(altura+base);
}