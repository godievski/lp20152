/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 3 de noviembre de 2015, 08:30 AM
 */

#include "Persona.h"
#include "ManejaArchivo.h"

int main(int argc, char** argv) {

    ManejaArchivo ma("datos.bin");
    ma.incrementarSueldo(5);
    ma.mostrarArch();
    return 0;
}

