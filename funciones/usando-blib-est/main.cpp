/*USANDO UNA BIBLIOTECA ESTÁTICA!!!*/

/* Añadir el directorio donde se trabaja y el archivo .a*/
/* ADDITIONAL LIBRARIES DIRECTORY
 * 
 */

#include <cstdlib>
#include <cstdio>
#include "BibEst.h"

int main ()
{
  int a,b,c,d;
  scanf("%d %d %d",&a,&b,&c);
  d = maximo (a, b, c);
  printf("Maximo: %d\n",d);
}
