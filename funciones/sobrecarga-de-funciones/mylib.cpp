#include <cstdlib>
#include <cstdio>

void lee (int &x)
{
	scanf("%d", &x);
}

void imp (int x)
{
	printf("Valor leído: %d\n",x);
}

void lee (int x[], int &n)
{
	n = 0;
	while (scanf("%d",&x[n]) != 0) n++;
}

void imp (int x[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d) %d\n",i,x[i]);
}
