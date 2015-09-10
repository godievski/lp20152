#include <iostream>
using namespace std;
#include "mylib.h"


#include <cstdio>
#include <cstdlib>

int main ()
{
  int d1,d2,d3;
  cout<<"Ingrese tres valores: \n";
  cin>>d1>>d2>>d3;
  cout<<"El valor maximo es: "<<maximo(d1,d2,d3)<<endl;
  cout<<endl;
  
  double f1,f2,f3;
  cout<<"Ingrese tres valores: \n";
  cin>>f1>>f2>>f3;
  cout<<"El valor maximo es: "<<maximo(f1,f2,f3)<<endl;
  cout<<endl;

  char c1,c2,c3;
  cout<<"Ingrese tres caracteres: \n";
  cin>>c1>>c2>>c3;
  cout<<"El valor maximo es: "<<maximo(c1,c2,c3)<<endl;
  cout<<endl;

  return 777;
}
