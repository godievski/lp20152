/*
 * NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * CODIGO: 20125849
 * 
 */

#include <cstdlib>
#include "almacenaSemestre.h"
#include <cstdio>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    void *cursos;
    cursos = leerCursos();
    
    void **arrayCursos = (void **) cursos;
    char **listaCod = (char **) arrayCursos[0];
    double *listaCred = (double *) arrayCursos[1];
    int *listaNota = (int *) arrayCursos[2];
    for (int i = 0; listaCod[i]; i++){
        printf("<%s> %2.1lf %d\n",listaCod[i], listaCred[i], listaNota[i]);
    }
    
    return 0;
}

