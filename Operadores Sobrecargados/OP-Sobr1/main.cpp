/* 
 * File:   main.cpp
 * Author: Miguel
 *
 * Created on 17 de junio de 2009, 10:55 PM
 */

#include <stdlib.h>
#include <stdio.h>
#include "Reloj.h"

/*
 * #include <iostream>
 * #include <iomanip>
 *
 */
int main(void) {
    Reloj R(10, 59, 56);

    for (int i=0; i<10; ++i,++R){
        // i++ incremente en 1 i
        // ++R incrementa en 1 segundo el Reloj
        printf("%4d %4d %4d\n", R.Hora(), R.Minuto(), R.Segundo());
        //cout <<setw(4)<< R.Hora() <<setw(4)<< R.Minuto() <<setw(4)<< R.Segundo() << endl;
    }
    return (EXIT_SUCCESS);
}


/* Al ejecutar este programa se muestra:

     10  59  56
     10  59  57              
     10  59  58              
     10  59  59
     11   0   0
     11   0   1
     11   0   2
     11   0   3
     11   0   4
     11   0   5
*/