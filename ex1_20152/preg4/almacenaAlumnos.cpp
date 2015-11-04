/*
 * NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * CODIGO: 20125849
 * 
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include "almacenaSemestre.h"
#include "almacenaAlumnos.h"
#include "funcAux.h"

void * leeAlumnos (void)
{
    void *buffAlumnos[1000];
    int cantAlum = 0;
    char *nombre;
    int anhoIng, semIng, anhoEgr, semEgr;
    
    while (1){
        if ((nombre = leeNombre() ) == NULL) break;
        /*lee semestre de ingreso y egreso*/
        scanf("%d",&anhoIng);   scanf("%d",&semIng);
        scanf("%d",&anhoEgr);   scanf("%d",&semEgr);
        while (getchar() != '\n'); //para leer hasta el salto de linea y pasar a la sgte linea
        //Calcula la cantidad de semestre que estudió
        int cantSem = calcCantSem(anhoIng, semIng, anhoEgr, semEgr);
        guardarDatosIniciales(buffAlumnos, cantAlum, nombre,anhoIng, semIng, anhoEgr, semEgr, cantSem);
        void **reg = (void **) buffAlumnos[cantAlum];
        for (int i = 0; i < cantSem; i++){
            void *cursos = leerCursos();
            reg[i+3] = cursos;
        }
        cantAlum++;
    }
    void **arrayAlum = new void*[cantAlum + 1];
    for (int i = 0; i < cantAlum; i++)
        arrayAlum[i] = buffAlumnos[i];
    arrayAlum[cantAlum] = NULL;
    return (void *) arrayAlum;
}

char * leeNombre (void)
{
    /*FUNCION PARA LEER LA LINEA QUE CONTIENE UN NOMBRE Y DEVUELVE UNA DIRECCION
     *DE MEMORIA QUE CONTIENE EL NOMBRE SIN ESPACIOS ENTRE PALABRAS*/
    char buff[500], *palabras[10], buffNomb[500];
    int cantPal = 0;
    
    if (gets(buff) == NULL) return NULL;
    
    separaPalabras(buff, palabras, cantPal);
    strcpy(buffNomb, palabras[0]);
    for (int i = 1; i < cantPal; i++){
        strcat(buffNomb, " ");
        strcat(buffNomb, palabras[i]);
    }
    char *nombre = new char[strlen(buffNomb) + 1];
    strcpy(nombre, buffNomb);
    return nombre;
}

void guardarDatosIniciales (void **buffAlumnos, int cantAlum,
                            char *nombre, int anhoIng, int semIng,
                            int anhoEgr, int semEgr, int cantSem)
{
    /*CREA EL REGISTRO Y GUARDA LOS PRIMEROS DATOS DEL ALUMNO: SU NOMBRE,
     *AÑO QUE INGRESÓ Y EGRESÓ*/
    void **reg = new void*[cantSem + 3];
    reg[0] = nombre;
    
    int *semestreIng = new int;
    *semestreIng = anhoIng*10 + semIng;
    reg[1] = semestreIng;
    
    int *semestreEgr = new int;
    *semestreEgr = anhoEgr*10 + semEgr;
    reg[2] = semestreEgr;
    
    buffAlumnos[cantAlum] = reg;
}