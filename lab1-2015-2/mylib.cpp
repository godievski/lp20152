/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#include <cstdio>

void impLinea(char c, int n)
{
    for (int i = 0; i < n; i++)
        putchar(c);
    putchar('\n');
}

void impTiempoParcial (double &tiempoMax, double tiempoParcial, int &ddMax, int &mmMax,
											 int &aaMax, int dd, int mm, int aa)
{
	for (int i = 0; i < 60; i++) putchar(' ');
  impLinea('-',20);
  for (int i = 0; i < 60; i++) putchar(' ');
  printf("%-10s%10.2lf\n","Total:",tiempoParcial);
	for (int i = 0; i < 60; i++) putchar(' ');
  impLinea('-',20);
  if (tiempoMax < tiempoParcial) {
  	tiempoMax = tiempoParcial;
    ddMax = dd;
    mmMax = mm;
  	aaMax = aa;
  }
}

void impTiempo (double tiempo)
{
	int hh, mm;
	double aux;
	double ss;

	hh = (int) (tiempo / 3600);
	aux = tiempo - hh*3600;
	mm = (int) (aux / 60);
	ss = aux - mm * 60;
	printf("(%02d:%02d:%02.1lf)",hh,mm,ss);
}
