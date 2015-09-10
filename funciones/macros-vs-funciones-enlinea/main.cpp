#include <cstdio>
#include <cstdlib>

/*MACROS*/
#define F(x, y) 2*x-y

/*FUNCIONES ENLINEA
/*PALABRA CLAVE: inline
/*Se omite el inline cuando la funcion es muy grande, tiene recursión
 */
inline int f(int x, int y)
{
	return x * y;
}

int main()
{
	printf("/*MACROS VS FUNCIONES EN LINEA*/\n");
	do {
		printf("Hello world!\n");
	} while (0);

	int a = 3,b = 5;
	double c = 3.2, d =5.5;
	printf("Primero: %d\n",F(a,b));
	printf("Seungdo: %10.4lf\n",F(c,d));
	return 0;
}
