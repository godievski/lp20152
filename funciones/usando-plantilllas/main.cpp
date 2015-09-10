#include <cstdio>
#include <cstdlib>
#include "../plantillas/mylib.h"

int main ()
{
  double x, y, z, m;
  
  printf("Ingrese valores \'double\'\n");
  scanf("%lf %lf %lf",&x,&y,&z);
  m = maximo(x, y, z);
  printf("Maximo = %5.3lf\n",m);
  return 777;
}
