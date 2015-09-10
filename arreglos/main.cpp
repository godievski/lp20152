#include <cstdio>
#include <cstdlib>


void f(int x[][5])
{
	printf("%d\n",x[0][1]);
}

int main ()
{
	int a[10], b[50];
	int c[45][5];
	a[0] = 1;
	b[0] = 2;
	c[0][1] = 999;
	f(c);
	return 777;
}
