#ifndef __MYLIB_H__
#define __MYLIB_H__

/* SOBRECARGA DE OPERADORES!!*/
#include <iostream>
#include "mystruct.h"
using namespace std;

istream & operator >> (istream &, int[]);
ostream & operator << (ostream &, int[]);

istream & operator >> (istream &, struct TArreglo&);
ostream & operator << (ostream &, struct TArreglo);

void operator += (struct TArreglo&, struct TArreglo);

#endif
