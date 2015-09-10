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

int main ()
{
	char c,c2;
	double saldoIni;
	int dd,mm,aa,rpta;
	int dep, ret;
	char finNum;
	int fin;
	bool finCuenta;

	c2 = '*';

	while (1) {
		//Datos de la cuenta
		finCuenta = 0;
		if (c2 != '*') printf("%c%c",c,c2);

		while (1){
			scanf("%c",&c);
			if (c == ' ') break;
			printf("%c",c);
		}
		putchar('\n');
		scanf("%*d");
		while (1) {
			scanf("%c",&c);
			if (c == ' ') break;
			printf("%c",c);
		}
		putchar('\n');
		
		//Saldo de la cuenta
		scanf("%lf",&saldoIni);
		printf("%-10.2lf\n",saldoIni);
		
		int test = 0;		
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
					if (c2 != ' ') {
						finCuenta = true;
						break;
					}
					putchar(c);
					if (c == 'D'){
						while (fin = scanf("%d%c",&dep,&finNum)){
							if (finNum != '/')
								printf("%10d",dep);
							else{
								rpta = 1;
								dd = dep;
								break;
							}
						}
					}
					else if (c == 'R'){
						while (fin = scanf("%d%c",&ret,&finNum)){
							if (finNum != '/')
								printf("%10d",ret);
							else{
								rpta = 1;
								dd = ret;
								break;
							}
							if (fin == EOF)	break;
						}
					}
					putchar('\n');	
					if (rpta) break;
					if (fin == EOF)	break;
				}
			} 
			if (finCuenta) break;
			if (fin == EOF)	break;
		}
		if (fin == EOF)	break;
	}

	return 0;
}
