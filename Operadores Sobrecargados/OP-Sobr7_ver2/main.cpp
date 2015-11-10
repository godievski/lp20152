/* 
 * File:   main.cpp
 * Author: Miguel Guanira
 *
 * Created on 22 de junio de 2009, 03:55 PM
 */

#include <stdlib.h>
#include <stdio.h>
#include "B.h"

int main(void) {
    B Ob;

    printf("Ingrese datos : ");
    while (1){
        int p;
        scanf("%d", &p);
        if (p <= 0) break;
        Ob.ingresa(p);
    }

    printf("Datos leidos : \n");

    for (int i=0; i<Ob.getCant(); i++)
        printf("%d\n", Ob[i]);

    printf("%d\n",Ob(3,5));
    return (EXIT_SUCCESS);
}

/* Al ejecutar el programa se obtiene :
    Ingrese datos : 23 65 121 3 72 190 2 32 -1
    Datos leidos :
    23
    65
    121
    3
    72
    190
    2
    32
    29
 */

