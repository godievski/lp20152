#include <cstdio>
#include "mylib.h"

void impLin(char c, int n)
{
	for (int i = 0; i < n;i++)
		putchar(c);
	putchar('\n');
}


int leeRomano(){
	char c, cAnt  = ' ';
	int valor, valorAnt = 0,repetidas, numRomano = 0;
	bool error = false;
	
	while ((c = getchar()) != ' ' && !error){
		if (cAnt == c) repetidas++;
		else repetidas = 0;
		cAnt = c;
		error = repetidas > 2;
		if (error) numRomano = 0;
		else {
			valor = valorRomano (c);
			if (valorAnt < valor)
				numRomano -= valorAnt;
			else
				numRomano += valorAnt;
			valorAnt = valor;
		}
	}
	numRomano += valor;
	return numRomano;
}

int valorRomano (char c)
{
	switch (c){
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	}
	return 0;
}
