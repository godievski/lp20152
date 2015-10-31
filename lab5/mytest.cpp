/*MY TEST*/
#include <cstdio>



void printMedicos (void *medicos)
{
    void **arrayM = (void **) medicos;
    
    for (int i=0; arrayM[i]; i++){
        void **reg = (void **) arrayM[i];
        char *nombre = (char *) reg[0];
        double *sueldo = (double *) reg[1];
        int *cant = (int *) reg[2];
        printf("Nombre: %s  Sueldo: %10.2lf Cantidad: %d\n",nombre, *sueldo, *cant);
    }
} 
