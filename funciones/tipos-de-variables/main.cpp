#include <cstdio>
#include <cstdlib>

/*Probando 'globabilidad'/'localidad' de las variables */

int a = 5;

/*Variables estaticas!*/
void f(void)
{
	int c = 3;
	static int d = 3;
	printf("C= %d   D= %d\n",c,d);
	c++;
	d++;
}


int main ()
{
	printf("A: %d\n",a);
	int a = 6;
	printf("A: %d\n",a);
	while (1){
		int a;		
		a = 3;
		printf("A: %d\n",a);
		break;
	}
	printf("A: %d\n",a);
	for (int i = 0; i < 5; i++){
		f();
	}
	return 0;
}
