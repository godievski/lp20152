/* 
 * File:   main.cpp
 * Author: Miguel Guanira
 *
 * Created on 19 de junio de 2009, 10:16 PM
 *
 * Ejemplo de operador sobrecargado unario (++)
 * devuelve un objeto de la clase en la que
 * se define. La sobrecarga implica su uso como
 * prefijo y como sufijo
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "A.h"

int main(void){
    A a1(2), a2(3), a3;

    printf("Inicialmente : \n");
    printf("A1 : %7.2f\n",a1.getX());
    printf("A2 : %7.2f\n\n",a2.getX());

    a3 = ++a1;
    printf("Como prefijo A3 = ++A1 :\n");
    printf("A1 : %7.2f\n", a1.getX());
    printf("A3 : %7.2f\n\n", a3.getX());

    a3 = a2++;
    printf("Como sufijo  A3 = A2++:\n");
    printf("A2 : %7.2f\n", a2.getX());
    printf("A3 : %7.2f\n", a3.getX());
    return (EXIT_SUCCESS);
}
/* Al ejecutar este programa se muestra:
    Inicialmente :
    A1 :    2.00
    A2 :    3.00

    Como prefijo A3 = ++A1 :
    A1 :    4.00
    A3 :    4.00

    Como sufijo  A3 = A2++:
    A2 :    9.00
    A3 :    3.00
*/

