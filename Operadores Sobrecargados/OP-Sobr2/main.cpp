/* 
 * File:   main.cpp
 * Author: Miguel Guanira
 *
 * Created on 19 de junio de 2009, 09:15 PM
 *
 * Ejemplo sencillo de operador sobrecargado binario (*)
 * Se sobrecarga dos veces el operador, la primra forma
 * devuelve el producto escalar de dos vectores (sólo un valor real),
 * la segunda multiplica un vector por un factor.
 */

#include <stdlib.h>
#include <stdio.h>
#include "Vector.h"

int main(void){
    Vector V1(10,20), V2(5,5);
    float prodEsc;

    prodEsc = V1*V2;
    printf("Producto escalar = %8.2f\n", prodEsc);

    V1*5;
    printf ("x= %8.2f\ny= %8.2f\n", V1.getX(), V1.getY());
    return (EXIT_SUCCESS);
}

/* Al ejecutar este programa se muestra:
   Producto escalar =   150.00
   x=    50.00
   y=   100.00
*/


