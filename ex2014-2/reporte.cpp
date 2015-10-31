#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "funcAux.h"
#include "reporte.h"

void reporteFinal (void *autores, void *libros)
{
    ordenarAutores(autores, comparaRegXCod);
    ordenarListaLibros(autores, comparaCodStr);
    printf("CATALAGO DE AUTORES:\n");
    printNChar('=',80);
    
    void **arrayAut = (void **) autores;
    for (int i = 0; arrayAut[i]; i++){
        void **reg = (void **) arrayAut[i];
        int *cod = (int *) reg[0];
        char *nomb = (char *) reg[1];
        char **listaLib = (char **) reg[2];
        printf("%02d) %d %s\n",i+1,*cod,nomb);
        impListaLib(listaLib,libros);
        printNChar('-',80);
    }
}

void ordenarAutores(void *autores, int (*comparaRegXCod) (const void*, const void*))
{
    int cant = 0;
    void **arrayAut = (void **) autores;
    for (cant = 0; arrayAut[cant]; cant++);
    myQSort(arrayAut, cant, comparaRegXCod);
}

int comparaRegXCod(const void*r1, const void*r2)
{
    void **reg1 = (void **) r1, **reg2 = (void **) r2;
    int *cod1 = (int *) reg1[0], *cod2 = (int *) reg2[0];
    return *cod1 - *cod2;
}

void ordenarListaLibros(void *autores, int (*comparaCodStr) (const void*, const void*))
{
    int cantLib;
    void **arrayAut = (void **) autores;
    for (int i=0; arrayAut[i]; i++){
        void **reg = (void **) arrayAut[i];
        char **listaAut = (char **) reg[2];
        cantLib = 0;
        for (cantLib=0; listaAut[cantLib]; cantLib++);
        myQSort((void **) reg[2], cantLib, comparaCodStr);
    }
}

int comparaCodStr(const void*c1, const void*c2)
{
    char *cod1 = (char *) c1, *cod2 = (char *) c2;
    return strcmp(cod1, cod2);
}

void impListaLib(char **listaLib, void *libros)
{
    printf("    Libros:\n");
    printf("      ");
    printf("%-10s %-40s %-8s\n","Codigo", "Titulo", "Precio");
    for(int i = 0; listaLib[i]; i++){
        char *nombLib;
        double *precio;
        buscaNombYPrec(libros, listaLib[i], nombLib, precio);
        printf("      ");
        printf("%-10s %-40s %-5.2lf\n",listaLib[i],nombLib,*precio);
    }
}

void buscaNombYPrec (void *libros, char *codLib, char *&nombLib, double *&precLib)
{
    void **arrayLib = (void **) libros;
    for (int i=0; arrayLib[i]; i++){
        void **reg = (void **) arrayLib[i];
        char *cod = (char *) reg[0];
        if (strcmp(cod, codLib) == 0){
            nombLib = (char *) reg[1];
            precLib = (double *) reg[2];
            break;
        }
    }
}