#include <cstdlib>
#include <cstdio>
#include "numGBases.h"

int main ()
{
	char c[100] = {0};
	char d[100] = {0};
	char e[100] = {0};
	int	rpta = 0;
  rpta = lee (10, c);
  rpta = lee (10, d);
	printf("%d\n",rpta);
	imprime (c);
	putchar('\n');
	imprime (d);
	putchar('\n');
	suma (10,c,d,e);

	putchar('\n');
}
