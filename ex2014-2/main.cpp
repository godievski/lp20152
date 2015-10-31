/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 7 de octubre de 2015, 07:28 PM
 */

#include "libAutores.h"
#include "libLibros.h"
#include "reporte.h"

using namespace std;

/*
 * 
 */
int
main (int argc, char** argv)
{
    void *autores, *libros;
    
    leerAutores(autores);
//    printAut(autores);
    leerLibros(libros, autores);
//    printLib(libros);
//    printAut(autores);
    reporteFinal(autores, libros);
    
    return 0;
}

