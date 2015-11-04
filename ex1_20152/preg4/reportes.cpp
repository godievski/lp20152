/*
 * NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * CODIGO: 20125849
 * 
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "reportes.h"
#include "funcAux.h"
#include "almacenaSemestre.h"

void reporte (void *alumnos, int anho, int sem)
{
    /*IMPRIME EL REPORTE SIN ORDENAR LOS DATOS*/
    void **arrayAlum = (void **) alumnos;
    printf("Semestre: %d - %d\n",anho, sem);
    printNChar('=',75);
    printf("Promedios ponderado obtenidos por los alumnos que cursaron ese semestre:\n");
    printNChar('-',75);
    printf("%-50s %-10s\n","Nombre","Promedio");
    printNChar('-',75);
    for (int i = 0; arrayAlum[i]; i++){
        void **reg = (void **) arrayAlum[i];
        char *nombre = (char *) reg[0];
        int *semestreIng = (int *) reg[1];
        int *semestreEgr = (int *) reg[2];
        int anhoIng = *semestreIng / 10, semIng = *semestreIng % 10;
        int semestre = anho * 10 + sem;
        if (semestre < *semestreIng || semestre > *semestreEgr) continue; //EL ALUMNO NO ESTUDIO EN ESTE SEMESTRE Y SE OMITE
        int indiceSem = calcCantSem(anhoIng,semIng,anho,sem) - 1;
        void* cursos = reg[3 + indiceSem];
        double promedioSem = promedio(cursos);
        printf("%-50s  %5.2lf\n",nombre, promedioSem);
    }
    printNChar('-',75);
}

void reporteOrdenado (void *alumnos, int anho, int semestre)
{
    /*PRIMERO ORDENA EL ARRAY ALUMNOS DE MENOR A MAYOR POR NOMBRE 
     *E IMPRIME UTILIZANDO LA FUNCION ANTERIOR REPORTE*/
    void **arrayAlum = (void **) alumnos;
    int cantAlum;
    for (cantAlum = 0; arrayAlum[cantAlum]; cantAlum++); //Para hallar la cantidad de alumnos
    qsort(arrayAlum, cantAlum, sizeof(void*), funcCompPorNomb);
    putchar('\n');
    reporte (alumnos, anho, semestre);
}

int funcCompPorNomb (const void*r1, const void *r2)
{
    /*ESTA FUNCION COMPARA LOS NOMBRES DE DOS REGISTROS UTILIZANDO LA FUNCION STRCMP*/
    void **reg1 = (void **) *(void **)r1, **reg2 = (void **) *(void **)r2;
    char *nomb1 = (char *) reg1[0], *nomb2 = (char *) reg2[0];
    return strcmp(nomb1,nomb2);
}

