#include <cstdio>
#include <cstdlib>

//PARAMETRO POR VALOR
int funcion_por_valor ( int a)
{
	return a * 2;
}


//PARAMETRO POR REFERENCIA
int funcion_por_referencia (int & p)
{
	p = p * 2;
	return p;
}


int main ()
{
	int x = 4;
	int y;
	printf("X antes: %d\n",x);
  y =	funcion_por_valor (x);
	printf("X - Y despues: %d  %d\n",x, y);
	y = funcion_por_referencia (x);
	printf("X - Y despues: %d  %d\n",x, y);
	
	return 0;
}
