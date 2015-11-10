/* 
 * File:   main.cpp
 * Author: Miguel Guanira
 *
 * Created on 19 de junio de 2009, 09:54 PM
 *
 * Ejemplo de operador sobrecargado binario (+, - y +=)
 * devuelve un objeto y permite definir expresiones
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "Complejo.h"

int main(void) {
    Complejo a(1.5,2.3), b(5.2,4.7), c(1.1,0.4), d;

    d = a + b - c;
    printf("D = %7.2f + %7.2f i\n",d.getReal(), d.getImaginario());
    d = a += c;
    printf("A = %7.2f + %7.2f i\n", a.getReal(), a.getImaginario());
    printf("D = %7.2f + %7.2f i\n", d.getReal(), d.getImaginario());

    return (EXIT_SUCCESS);
}

/* Al ejecutar este programa se muestra:
    D =    5.60 +    6.60 i
    A =    2.60 +    2.70 i
    D =    2.60 +    2.70 i
*/