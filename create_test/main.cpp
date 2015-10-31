/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 7 de octubre de 2015, 08:05 PM
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>


void printRandomChar (char c);

void desordenar (int *buffCod, int cantCod);

void create_one (void);

void create_two (void);

int main(int argc, char** argv) {
    
    //create_one();
    create_two();
    return 0;
}

void printRandomChar (char c)
{
    int n = rand() % 4 + 3;
    for (int i = 0; i < n; i ++) putchar(c);
}

void create_two (void)
{
    int buffCod[100];
    int cantCod = 0;
    int cod;
    char buff[1000];
    
    while (1){
        if (scanf("%d",&cod) == 0) break;
        buffCod[cantCod] = cod;
        cantCod++;
        gets(buff);
        printf("%d%s\n",cod,buff);
    }
    
    desordenar(buffCod, cantCod);
    
    int j=0;
    while (1){
        if (gets(buff) == NULL) break;
        printf("%s     ",buff);
        if (j == cantCod) j = 0;
        printf("%d\n",buffCod[j]);
        j++;
    }
    
}

void desordenar (int *buffCod, int cantCod)
{
    int ind;
    int aux;
    for (int i = 0; i < cantCod; i++){
        ind = rand() % cantCod;
        aux = buffCod[ind];
        buffCod[ind] = buffCod[i];
        buffCod[i] = aux;
    }
    
}
void create_one (void)
{
    char c;
    
    while (1){
        c = getchar();
        if (c <= '9' && c >= '0') break;
        if (isblank(c)) printRandomChar(' ');
        putchar(c);
    }
    putchar(c);
    
    while (1){
        c = getchar();
        if (c == EOF) break;
        if (isblank(c)) printRandomChar(' ');
        putchar(c); 
    }
    
}