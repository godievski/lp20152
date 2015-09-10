#include <cstdio>
#include <cstdlib>

void printDate (int dd, int mm, int aa, int n)
{
	if (dd < 10)
		printf("0%d",dd);
	else
		printf("%d",dd);
	if (mm < 10)
		printf("/0%d/%d",mm,aa);
	else
		printf("/%d/%d",mm,aa);
	if (n)
		printf("\n");
}

void printNegativo (int n)
{
	int len = 0;
	int aux = n;
	while (aux > 0){
		len++;
		aux = aux / 10;
	}
	for (int i = 0; i < 17 - len + 1; i++) putchar(' ');
	printf("(%d)\n",n);
}

void printSaldoFinal (double n)
{
	int aux = n;
	int len = 0;
	if (n > 0)
		printf("Saldo final: %20.2lf \n\n",n);
	else{
		while (aux > 0){
			len++;
			aux = aux / 10;
		}
		for (int i = 0; i < 7 - len + 1; i++) putchar(' ');
		printf("Saldo final:");
		printf("%10.2lf \n\n",n);
	}
}

int main ()
{
	char c,c2;
	double saldoIni;
	int dd,mm,aa,rpta;
	int dep, ret;
	int totalDep, cantDep;
	int totalRet, cantRet;
	double promDep, promRet;
	char finNum;
	int fin;
	bool finCuenta;

	c2 = '*';

	while (1) {
		//Datos de la cuenta
		finCuenta = 0;
		printf("Cuenta No:     ");
		if (c2 != '*') printf("%c%c",c,c2);

		totalDep = totalRet = cantRet= cantDep = 0;
		while (1){
			scanf("%c",&c);
			if (c == ' ') break;
			printf("%c",c);
		}
		putchar('\n');
		scanf("%*d");
		
		printf("Cliente:     ");
		while (1) {
			scanf("%c",&c);
			if (c == ' ') break;
			printf("%c",c);
		}
		putchar('\n');
		
		//Saldo de la cuenta
		scanf("%lf",&saldoIni);
		printf("Saldo Inicial:     %-10.2lf\n",saldoIni);
		printf("Movimientos\n");
		rpta = 0;

		while (1){
			if (rpta)
				rpta = scanf("%d/%d",&mm,&aa);
			else
				rpta = scanf("%d/%d/%d",&dd,&mm,&aa);

			if (rpta == 3 || rpta == 2){
				printDate(dd,mm,aa,1);
			}
			if (rpta == 0){
				while (1){
					scanf("%*d");
					scanf("%c%c",&c,&c2);
					if (c2 != ' ' ) {
						finCuenta = true;
						break;
					}
					if (c == 'D'){
						while (fin = scanf("%d%c",&dep,&finNum)){
							if (finNum != '/'){
								cantDep++;
								totalDep += dep;
								printf("%20d\n",dep);
							}
							else{
								rpta = 1;
								dd = dep;
								break;
							}
						}
					}
					else if (c == 'R'){
						while (fin = scanf("%d%c",&ret,&finNum)){
							if (finNum != '/'){
								cantRet++;
								totalRet += ret;
								printNegativo(ret);
								//printf("(%20d)\n",ret);
							}
							else{
								rpta = 1;
								dd = ret;
								break;
							}
							if (fin == EOF){
								finCuenta = true;
								break;
							}
						}
					}
					if (rpta) break;
					if (fin == EOF)	break;
				}
			} 
			if (finCuenta) {
				printf("Resumen\n");
				printf("%-15s%-10s%10d\n","Depositos","Total:",totalDep);
				promDep = ( double ) totalDep / cantDep;
				printf("%-15s%-10s%10.2lf\n"," ","Promedio:",promDep);
				printf("%-15s%-10s%10d\n","Retiros","Total:",totalRet);
				promRet = (double ) totalRet/cantRet;
				printf("%-15s%-10s%10.2lf\n"," ","Promedio:",promRet);
				printSaldoFinal(saldoIni + promDep - promRet);
//				printf("Saldo final: %20.2lf \n\n",saldoIni + promDep - promRet);
				break;
			}
			if (fin == EOF)	break;
		}
		if (fin == EOF)	break;
	}

	return 0;
}
