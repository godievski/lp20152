#include <cstdio>
#include <cstdlib>

#define MAX 100

int lee (int base, char numG[])
{
	int i = MAX;
	char c;
	bool positivo = true;
	while (1){
		c = getchar();
		if (c == '-'){
			positivo = false;
			break;
		}
		else if (c == EOF) return EOF;
		else if ((c - '0') < base && (c - '0') >= 0){
			numG[i] = c - '0';
			i--;
			break;
		} else if ((c - '0') >= base && (c - '0')< 10)
			return 0;
	}

	while (1){
		c = getchar();
		if ((c - '0') >= base && (c - '0') < 10){
			return 0;
		} else if ((c - '0') < base && (c - '0') >= 0){
			numG[i] = c - '0';
			i--;
		} else
			break;
	}
	if (i < 0)
		return 2;
	if (positivo)
		numG[i] = '+';
	else
		numG[i] = '-';
	return 1;
}

int imprime (char numG[])
{
	int n = 0;
	while (numG[n] != '+' && numG[n] != '-'){
		n++;
	}
	if (numG[n] == '-')
		printf("-");
	for (int i = MAX; i > n; i--){
		printf("%d",numG[i]);
	}
}

int suma (int base, char numG1[], char numG2[], char resp[])
{
	int i=0,j = 0;
	char carry = 0;
	while (numG1[i] != '+' && numG1[i] != '-'){
		i++;
	}
	while (numG2[j] != '+' && numG2[j] != '-'){
		j++;
	}
	n = MAX;
	if ((numG1[i] == '+' && numG2[j] == '+') || (numG1[i] == '-' && numG2[j] == '-')){
		while (i<= MAX || j <= MAX){
			if (i > MAX)
				
		}
	}	
	
	printf("%c %c\n",numG1[i],numG2[j]);
	return 0;
}







