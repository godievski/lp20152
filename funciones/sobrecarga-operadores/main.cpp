//#include <cstdlib>
//#include <cstdio>

#include <iostream>
#include <iomanip>
using namespace std;

#include "mylib.h"
#include "mystruct.h"
/*
 * Valor devuelto    operator    + (t1, t2);
 */

int main ()
{
  struct TArreglo a, b;
  cin >> a;
  cin >> b;

  a += b;

  cout <<a;
  cout <<b;

	return 777;
}
