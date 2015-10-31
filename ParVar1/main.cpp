/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 20 de octubre de 2015, 08:57 AM
 */

#include <cstdlib>
#include <cstdio>
using namespace std;


int suma (int numDat, ...)
{
    int *ptDato, s =0;
    ptDato = &numDat;
    ptDato++;
    for (int i =0; i < numDat; i++){
        s += *ptDato;
        ptDato++;
    }
    return s;
}

int main(int argc, char** argv) {

    int s;
    s = suma(3, 12, 67, 99);
    printf("Suma = %d\n\n",s);
    
    s = suma(6, 12, 67, 99,134,82,37);
    printf("Suma2 = %d\n\n",s);
    return 0;
}

