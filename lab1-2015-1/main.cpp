#include <cstdio>
#include <cstdlib>
#include "mylib.h"

#define MAX_NOMB 30

int main ()
{
	int codigo, numCar, edad;
	int numBlancos;
	int respondidas, correctas, incorrectas;
	int respAlum, respCorr;
	char c;
	double nota;
	
	
	printf("        ALUMNO  CALIFICACIONES\n");
	impLin('*',100);
	printf("Codigo      Nombre                         Edad    Respondidas   Correctas   Incorrectas   Nota\n");
	impLin('-',100);
	
	while (scanf("%d",&codigo) != EOF){
		printf("%-12d",codigo);

		numCar = 0;
		while (scanf("%d",&edad) == 0){
			while ((c=getchar()) != ' '){
				putchar(c);
				numCar++;
			}
			putchar(' ');
			numCar++;
		}

		numBlancos = MAX_NOMB - numCar;
		for (int i = 0; i < numBlancos; i++) putchar(' ');
		printf("%4d", edad);

		respondidas = correctas = incorrectas = 0;
		nota = 0.0;

		while (getchar() != '\n'){
			scanf("%*d");
			respCorr = leeRomano();
			scanf ("%d",&respAlum);
			respondidas++;
			correctas += respCorr == respAlum;
			incorrectas += respCorr != respAlum;
			nota += (respCorr == respAlum) - 0.25*(respCorr != respAlum);
		}
		printf("%10d%15d%15d%10.2lf\n",respondidas, correctas, incorrectas, nota);
	}


	return 0;
}
