#include <iostream>
#include <iomanip>
using namespace std;
#include "mystruct.h"

istream & operator >> (istream &in, int x[])
{
  int n = 0;
  cout << "Ingrese los valores: \n";
  while (in>>x[n])
    n++;
  x[n] = 0;
  return in;
}

ostream & operator << (ostream &out, int x[])
{
  cout<<"Datos del arreglo: "<<endl;
  for (int i=0; x[i];i++)
    out<<setw(3)<<i<<") "<<setw(8)<<x[i]<<endl;

  return out;
}

istream & operator >> (istream &in, struct TArreglo &dato)
{
  dato.n = 0;
  cout << "Ingrese los valores: \n";
  while (1){
    in>>dato.arr[dato.n];
    if (dato.arr[dato.n] == 0) break;
    dato.n++;
  }
  return in;
}

ostream & operator << (ostream &out, struct TArreglo dato)
{
  cout<<"Datos del arreglo: "<<endl;
  for (int i=0; i<dato.n;i++)
    out<<setw(3)<<i<<") "<<setw(8)<<dato.arr[i]<<endl;

  return out;
}

void operator += (struct TArreglo &a, struct TArreglo b)
{
  int i = a.n, j = 0;
  a.n += b.n;
  for (;j<b.n;j++, i++)
    a.arr[i] = b.arr[j];
}

