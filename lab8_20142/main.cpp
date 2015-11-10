/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 5 de noviembre de 2015, 03:17 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

#include "RegistroPersonal.h"

/*
 * 
 */
int main(int argc, char** argv) {

    fstream arch;
    
    inicializar(arch);
     
    cargarMedicos(arch);
   
    listar(arch);
    return 0;
}

