/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 29 de septiembre de 2015, 02:13 PM
 */

#include "mylib.h"
#include "mytest.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *medicos;
    void *pacientes;
    
    leeDatos(medicos, pacientes);
    //printMedicos(medicos);
    impInforme(medicos, pacientes);
    //printMedicos(medicos);
    return 0;
}

