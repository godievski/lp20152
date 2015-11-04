/*
 * NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * CODIGO: 20125849
 * 
 */

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "almacenaSemestre.h"
#include <cstring>

#define INCREMENTO 5

void* leerCursos (void)
{
    char buffer[1000], *palabras[200];
    int cantPal;
    //SE CREA EL ARREGLO 
    void** arrayCursos = new void*[3];
    //SE INICIALIZAN CADA SUBARREGLO
    char **listaCod = new char*[INCREMENTO];
    listaCod[0] = NULL;
    arrayCursos[0] = listaCod;
    double *listaCred = new double[INCREMENTO];
    listaCred[0] = -1;
    arrayCursos[1] = listaCred;
    int *listaNota = new int[INCREMENTO];
    listaNota[0] = -1;
    arrayCursos[2] = listaNota;
    int tamCur = INCREMENTO, cantCur = 1;
    
    gets(buffer);
    separaPalabras(buffer, palabras, cantPal);
    for (int i = 0; i < cantPal; i += 3){
        char *codigo = new char[strlen(palabras[i]) + 1];
        strcpy(codigo, palabras[i]);
        double creditos = atof(palabras[i+1]);
        int nota = atoi(palabras[i+2]);
        guardarCurso(arrayCursos, tamCur, cantCur, codigo, creditos, nota);
    }
    
    return (void *) arrayCursos;
}

void separaPalabras (char *buffer, char **palabras, int &cantPal)
{
    cantPal = 0;
    
    if (!isblank(buffer[0])){
        palabras[0] = buffer;
        cantPal++;
    }
    
    for (int i = 1; buffer[i]; i++){
        if (!isblank(buffer[i]) && (isblank(buffer[i-1]) || buffer[i-1] == 0)){
            palabras[cantPal] = &buffer[i];
            cantPal++;
        }
        if (!isblank(buffer[i]) && isblank(buffer[i+1]) ){
            buffer[i+1] = 0;
            i++;
        }
    }
}

void guardarCurso(void **arrayCursos, int &tamCur, int &cantCur,
                    char *codigo, double creditos, int nota)
{
    if (tamCur == cantCur)
        aumentarTam(arrayCursos, tamCur, cantCur);
    char **listaCod = (char **) arrayCursos[0];
    double *listaCred = (double *) arrayCursos[1];
    int *listaNota = (int *) arrayCursos[2];
    listaCod[cantCur - 1] = codigo;
    listaCod[cantCur] = NULL;
    listaCred[cantCur - 1] = creditos;
    listaCred[cantCur] = -1;
    listaNota[cantCur - 1] = nota;
    listaNota[cantCur] = -1;
    cantCur++;
}

void aumentarTam(void **arrayCursos, int &tamCur, int cantCur)
{
    char **listaCod = (char **) arrayCursos[0], **auxCod;
    double *listaCred = (double *) arrayCursos[1], *auxCred;
    int *listaNota = (int *) arrayCursos[2], *auxNota;
    
    tamCur += INCREMENTO;
    auxCod = new char*[tamCur];
    auxCred = new double[tamCur];
    auxNota = new int[tamCur];
    
    for (int i = 0; i < cantCur; i++){
        auxCod[i] = listaCod[i];
        auxCred[i] = listaCred[i];
        auxNota[i] = listaNota[i];
    }
    delete []listaCod;
    delete []listaCred;
    delete []listaNota;
    arrayCursos[0] = auxCod;
    arrayCursos[1] = auxCred;
    arrayCursos[2] = auxNota;
}

double promedio (void*cursos)
{
    void **arrayCursos = (void **) cursos;
    double total = 0, totalCred = 0;;
    double *listaCred = (double *) arrayCursos[1];
    int *listaNota = (int *) arrayCursos[2];
    
    for (int i = 0; listaCred[i] != -1; i++){
        total += listaCred[i] * listaNota[i];
        totalCred += listaCred[i];
    }
    return total / totalCred;
}