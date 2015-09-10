	
#include <cstdio>
#include "mylib.h"

int calcTiempo (int hhF, int mmF, int ssF, int hh, int mm, int ss)
{
	return hhF*3600 + mmF*60 + ssF - ( hh*3600 + mm*60 + ss);
}

void printDatosFecha (int fecha,int tiempoDia,double cantLluviaDia)
{
	int dia,mes,ano,fechaAux = fecha;
	int hh,mm,ss;
	ano = fechaAux / 10000;
	fechaAux = fechaAux % 1000;
	mes = fechaAux / 100;
	dia = fechaAux % 100;
	printf("%30s"," ");
	if (dia < 10)
		printf("0%d",dia);
	else
		printf("%d",dia);
	if (mes < 10)
		printf("/0%d/%d",mes,ano);
	else
		printf("/%d/%d",mes,ano);

	convertirTiempo (tiempoDia, &hh,&mm,&ss);
	printf("     ");
	if (hh < 10)
		printf("0%d",hh);
	else
		printf("%d",hh);
	if (mm < 10)
		printf(":0%d:",mm);
	else
		printf(":%d:",mm);
	if (ss < 10)
		printf("0%d",ss);
	else
		printf("%d",ss);
	printf("%15.2lf\n",cantLluviaDia)
}

void printPeriodo ( int diaI, int mesI, int anoI,
										int diaF, int mesF, int anoF,
										int tiempoTotal, double cantTotalLluvia)
{
	int hh,mm,ss;
	convertirTiempo (tiempoTotal, &hh,&mm,&ss);
	printf("Periodo       Inicio: %d/%d/%d   Fin: %d/%d/%d",diaI, mesI, anoI, diaF, mesF, anoF);
	printf("     Tiempo: %d:%d:%d    Cantidad: %10.2lf",hh,mm,ss,cantTotalLluvia);	
}

void convertirTiempo (int tiempo, int* hh, int* mm, int* ss)
{
	int tiempoAux = tiempo;
	*hh = tiempoAux / 3600;
	tiempoAux = tiempoAux - (*hh) * 3600;
	*mm = tiempoAux / 60;
	*ss = tiempoAux - (*mm) * 60;
}
