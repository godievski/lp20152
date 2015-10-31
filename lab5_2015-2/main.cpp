/* 
 * File:   main.cpp
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 * Created on 2 de octubre de 2015, 07:58 AM
 */


#include "mylib.h"


int main(int argc, char** argv) {
    void *cursos;
    
    leerCursos(cursos);
    leeMatricula(cursos);
    listaDeClase(cursos);
    
    return 0;
}

