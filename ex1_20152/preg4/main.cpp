/*
 * NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * CODIGO: 20125849
 * 
 */

#include <cstdlib>
#include <cstdio>
#include "almacenaAlumnos.h"
#include "reportes.h"


/*
 * 
 */
int main(int argc, char** argv) {

    void *alumnos;
    int anho, semestre;
    
    //Se lee la primera linea con el semestre con el que se dará el reporte
    scanf("%d",&anho);
    scanf("%d",&semestre);
    while (getchar() != '\n'); //para leer hasta el salto de linea y pasar a la sgte linea
    alumnos = leeAlumnos();
    
    reporte(alumnos, anho, semestre);
    
    reporteOrdenado(alumnos, anho, semestre);
    
    return 0;
}

