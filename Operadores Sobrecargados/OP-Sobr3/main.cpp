/* 
 * File:   main.cpp
 * Author: Miguel Guanira
 *
 * Created on 19 de junio de 2009, 09:38 PM
 *
 * Ejemplo sencillo de operador sobrecargado binario (+)
 * permite concatenar una cadena atributo de un objeto
 * no devuelve valor.
*/
#include <stdlib.h>
#include "Cadena.h"


int main(void){
    Cadena c1,c2;
    c1.setCadena("Juan");
    c2.setCadena("Lopez");

    c1+c2;
    c1.imprimeCad();
    return (EXIT_SUCCESS);
}

/* Al ejecutar este programa se muestra:

    Cadena = JuanLopez

*/

