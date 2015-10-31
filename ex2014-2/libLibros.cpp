#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "libLibros.h"
#include "funcAux.h"

#define INCREMENTO 5

void leerLibros (void *&libros, void *autores)
{
    void *buffLib[200];
    int codAut, cantLib = 0;
    double *precio;
    char *codLib, *nombLib;
    int tam[200], cant[200];
    
    while (1){
        if (leeLibro(codLib, nombLib, precio, codAut) == NULL) break;
        guardarEnLibros(buffLib, cantLib, codLib, nombLib, precio);
        guardarEnAutores(autores, codAut, tam, cant, codLib);
    }
    
    void **arrayLib = new void*[cantLib + 1];
    for (int i = 0; i < cantLib; i++)
        arrayLib[i] = buffLib[i];
    arrayLib[cantLib] = NULL;
    libros = arrayLib;
}

void * leeLibro(char *&codLib, char *&nombLib, double *&precio, int &codAut)
{
    char buffer[200], *palabras[20];
    char buffNomb[200];
    int cantPal;
    
    if (gets(buffer) == NULL) return NULL;
    
    separaPalabras(buffer, palabras, cantPal);
    
    codLib = new char[strlen(palabras[0]) + 1];
    strcpy(codLib, palabras[0]);
    
    strcpy(buffNomb, palabras[1]);
    for (int i = 2; i < cantPal - 2; i++){
        strcat(buffNomb, " ");
        strcat(buffNomb, palabras[i]);
    }
    nombLib = new char[strlen(buffNomb) + 1];
    strcpy(nombLib, buffNomb);
    
    precio = new double;
    *precio = atof(palabras[cantPal - 2]);
    
    codAut = atoi(palabras[cantPal -1]);
    return (void *) codLib;
}

void guardarEnLibros(void **buffLib, int &cantLib,
                    char *codLib, char *nombLib, double *precio)
{
    void **reg = new void*[3];
    reg[0] = codLib;
    reg[1] = nombLib;
    reg[2] = precio;
    buffLib[cantLib] = reg;
    cantLib++;
}


void guardarEnAutores(void *autores, int codAut, int *tam, int *cant, char *codLib)
{
    void **arrayAut = (void **) autores;
    int ind = buscarAutor(autores, codAut);
    void **reg = (void **) arrayAut[ind];
    char **listaLib;
    
    if (reg[2] == NULL){
        listaLib = new char*[INCREMENTO];
        listaLib[0] = NULL;
        reg[2] = listaLib;
        tam[ind] = INCREMENTO;
        cant[ind] = 1;
    } else {
        if (tam[ind] == cant[ind])
            aumentarTamListaLib (autores, ind, tam, cant);
        listaLib = (char **) reg[2];
        listaLib[cant[ind] - 1] = codLib;
        listaLib[cant[ind]] = NULL;
        cant[ind] += 1;
    }
}

int buscarAutor (void *autores, int codAut)
{
    void **arrayAut = (void **) autores;
    int ind= 0;
    for (ind = 0; arrayAut[ind]; ind++){
        void **reg = (void **) arrayAut[ind];
        int *cod = (int *) reg[0];
        if (codAut == *cod) break;
    }
    return ind;
}

void aumentarTamListaLib (void *autores, int ind, int *tam, int *cant)
{
    void **arrayAut = (void **) autores;
    void **reg = (void **) arrayAut[ind];
    tam[ind] += INCREMENTO;
    char **listaLibAux = new char*[tam[ind]];
    char **listaLib = (char **) reg[2];
    for (int i = 0; i < cant[ind]; i++)
        listaLibAux[i] = listaLib[i];
    delete[]listaLib;
    reg[2] = listaLibAux;
}

void printLib (void *libros)
{
    void **arrayLib = (void **) libros;
    for (int i = 0; arrayLib[i]; i++){
        void **reg = (void **) arrayLib[i];
        char *cod = (char *) reg[0], *nomb = (char *) reg[1];
        double *precio = (double *) reg[2];
        printf("Codigo: %-8s  Titulo: <%-30s> Precio: %4.2lf\n",cod,nomb,*precio);
    }
    printNChar('*',80);
}






