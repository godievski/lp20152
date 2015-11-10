/* 
 * File:   main.cpp
 * Author: Miguel Guanira
 *
 * Created on 21 de junio de 2009, 10:06 PM
 */

#include <stdlib.h>
#include <stdio.h>
#include "Quebrado.h"

int main(void) {
    Quebrado a(2,3), b(5,6), c, d;
    int p = 3;

    printf("A = ");
    a.muestra();
    printf("\n");

    printf("B = ");
    b.muestra();
    printf("\n");

    d = c = a;

    printf("C = ");
    c.muestra();
    printf("\n");

    printf("D = ");
    d.muestra();
    printf("\n");

    c = a + b;
    printf("C = A + B = ");
    c.simplifica();
    c.muestra();
    printf("\n");

    d += b;
    printf("D += B = ");
    d.muestra();
    printf("\n");

    d = a + Quebrado(p,1);
    printf("D = A + p = ");
    d.muestra();
    printf("\n");

    d = Quebrado(p) + a;
    printf("D = p + A = ");
    d.muestra();
    printf("\n");

    float f;
    f = float(a);
    printf("f = %f\n", f);

    return (EXIT_SUCCESS);
}

