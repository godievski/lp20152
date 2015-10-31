/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 6 de octubre de 2015, 10:41 AM
 */

#include "mylib.h"

int
main (int argc, char** argv)
{
  void *cursos, *alumnos, *egresados;
  
  leerDatos(cursos, alumnos);
  agregarNotas(alumnos);
  separacionDeEgresados(cursos, alumnos, egresados);
  
  return 0;
}

