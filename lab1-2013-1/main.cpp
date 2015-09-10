#include <cstdio>
#include <cstdlib>
#include "mylib.h"

#define MAX_NOM 30

int main ()
{
	int opcion;
	int dia,mes,ano;
	int hh,mm,ss,hhF,mmF,ssF;
	int fechaAnt,fecha;
	double cantLluviaDia, cantLluvia,cantTotalLluvia;
	int tiempo, tiempoDia,tiempoTotal;
	int diaI,mesI,anoI,diaF,mesF,anoF;
	int rptaFecha;
	char c;
	int cantCar;

	scanf("%d",&opcion);
	scanf("%*d");
	while (1){
		cantCar = 0;
		if (opcion == 1){
			while ((c = getchar()) != ','){
				putchar(c);
				cantCar++;
			}
			while (getchar() != ':');
		} else if (opcion == 2){
			while (getchar() != ',');
			getchar();
			while ((c = getchar()) != ','){
				putchar(c);
				cantCar++;
			}
			while (getchar() != ':');
		} else {
			while (getchar() != ',');
			while (getchar() != ',');
			getchar();
			while ((c = getchar()) != ':'){
				putchar(c);
				cantCar++;
			}
		}
		for (int i = 0; i < MAX_NOM - cantCar; i++) putchar(' ');
		printf("%7s%20s%20s\n","Fecha","Tiempo Total","Cantidad de lluvia");

		cantLluviaDia = 0.0;
		cantTotalLluvia = 0.0;
		tiempoDia = tiempoTotal = 0;
		fechaAnt = 0;

		while (rptaFecha = scanf("%d/%d/%d",&dia,&mes,&ano)){
			if (rptaFecha == 2){
				ano = mes;
				mes = dia;
				dia = 1;
				
			} else if (rptaFecha == 1){
				ano = dia;
				mes = 1;
				dia = 1;
			} else if (rptaFecha == EOF) break;

			fecha = ano*10000 + mes*100 + dia;
			if (fechaAnt == 0){
				diaI = dia;
				mesI = mes;
				anoI = ano;
			}

			scanf("%d:%d:%d",&hh,&mm,&ss); //Hora inicio
			scanf("%d:%d:%d",&hhF,&mmF,&ssF); //Hora fin
			scanf("%lf",&cantLluvia); //Cantidad de lluvia

			tiempo = calcTiempo(hhF,mmF,ssF,hh,mm,ss);
			tiempoTotal += tiempo;
			cantTotalLluvia += cantLluvia;
			if (fecha == fechaAnt){
				tiempoDia += tiempo;
				cantLluviaDia += cantLluvia;
			} else {
				if (fechaAnt != 0)
					printDatosFecha(fechaAnt,tiempoDia,cantLluviaDia);
				tiempoDia = tiempo;
				cantLluviaDia = cantLluvia;
			}
			fechaAnt = fecha;
		}
		diaF = dia;
		mesF = mes;
		anoF = ano;
		printDatosFecha(fechaAnt,tiempoDia,cantLluviaDia);
		printPeriodo(diaI,mesI,anoI,diaF,mesF,anoF,tiempoTotal,cantTotalLluvia);
		putchar('\n'); 		putchar('\n');
		if (rptaFecha == EOF) break;
	}
	
	return 0;
}
