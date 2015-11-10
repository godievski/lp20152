/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 6 de noviembre de 2015, 09:30 AM
 */

/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#include <cstdlib>
#include "AdministradorDeArchivos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    AdministradorDeArchivos adm(argv[1], argv[2]);
    
    adm.actualizarArchivo();
    
    adm.motrarArchivo();
    
    return 0;
}

