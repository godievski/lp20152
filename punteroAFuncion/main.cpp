/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 30 de septiembre de 2015, 09:30 AM
 */

#include <cstdlib>
#include <cstdio>
using namespace std;


int suma(int, int);
int resta(int, int);
int multiplica(int, int);

int operacion(int, int, int (*)(int, int));

/*
 * 
 */
int main(int argc, char** argv) {

    int (*pt) (int, int);
    
    pt = suma;
    printf("SUMA 4 + 5 = %d\n",pt(4,5));
    
    
    printf("\nRESTA 4 - 5 = %d\n",operacion(4,5,resta));
    

    printf("\nMULTIPLICA 4 * 5 = %d\n\n",operacion(4,5,multiplica));
    
    
    return 0;
}



/*FUNCIONES*/

int operacion(int a, int b, int (*f)(int, int))
{
    return f(a,b);
}

int suma (int a, int b)
{
    return a + b;
}

int resta (int a, int b)
{
    return a - b;
}

int multiplica (int a, int b)
{
    return a * b;
}