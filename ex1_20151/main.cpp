/* 
 * File:   main.cpp
 * Author: Godievski
 *
 * Created on 29 de septiembre de 2015, 08:18 AM
 */

#include "mylib.h"

int main(int argc, char** argv) {
    void *vendedores;
    
    leeDatos(vendedores);
    reporteDeVentas(vendedores);
    
    return 0;
}

