#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "libAutores.h"
#include "funcAux.h"

void leerAutores (void *&autores)
{
    void *buffer[200];
    int cantAut = 0;
    int codigo;
    char *nombre;
    
    while (scanf("%d",&codigo) == 1){
        nombre = leerNombre();
        guardarDatos(buffer, cantAut, codigo, nombre);
    }
    void **arrayAut = new void*[cantAut+1];
    for (int i = 0; i < cantAut; i++)
        arrayAut[i] = buffer[i];
    arrayAut[cantAut] = NULL;
    autores = arrayAut;
}

char* leerNombre (void)
{
    char buffer[200], *palabras[10];
    char buffNomb[200], *nomb;
    int cantPal;
    gets(buffer);
    separaPalabras(buffer, palabras, cantPal);
    strcpy(buffNomb, palabras[0]);
    for (int i = 1; i < cantPal; i++){
        strcat(buffNomb, " ");
        strcat(buffNomb, palabras[i]);
    }
    nomb = new char[strlen(buffNomb) + 1];
    strcpy(nomb, buffNomb);
    return nomb;
}

void guardarDatos (void **buffer, int &cantAut, int codigo, char *nombre)
{
    void **reg = new void*[3];
    int *cod = new int;
    *cod = codigo;
    reg[0] = cod;
    reg[1] = nombre;
    reg[2] = NULL;
    buffer[cantAut] = reg;
    cantAut++;
}

void printAut (void *autores)
{
    void **arrayAut = (void **) autores;
    void **reg;
    
    for (int i = 0; arrayAut[i]; i++){
        reg = (void **) arrayAut[i];
        int *cod = (int *) reg[0];
        char *nomb = (char *) reg[1];
        printf("Codigo: %d Nombre: %s\n",*cod, nomb);
        if (reg[2] != NULL){
            char **listaLib = (char **) reg[2];
            for (int j = 0; listaLib[j]; j++)
                printf("    *%s\n",listaLib[j]);
        }
    }
    printNChar('*',80);
}