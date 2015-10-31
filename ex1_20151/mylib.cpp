#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include "mylib.h"

#define MAX_BUFFER 500
#define MAX_CODART 7
#define INCREMENTO 5

void leeDatos (void *&vendedores)
{
    int *codV, cant, numVend = 0, *acumulado[MAX_BUFFER] = {NULL};
    char *nombV, *codA, **codArt[MAX_BUFFER] = {NULL};
    int tam[500] = {0}, numD[500] = {0}; 
    void* buffV[MAX_BUFFER], **vend;
    
    while (1){
        if (leeVenta(codV, nombV, codA, cant) == NULL) break;
        agregar(codV,nombV,codA,cant,buffV,numVend,
                codArt, acumulado, tam, numD);
    }
    vend = new void*[numVend+1];
    for (int i=0; i<numVend; i++){
        vend[i] = buffV[i];
        void **reg = (void **) vend[i];
        reg[2] = codArt[i];
        reg[3] = acumulado[i];
    }
    vend[numVend] = NULL;
    vendedores = vend;
}

void * leeVenta(int *&codV, char *&nombV, char*&codA, int &cant)
{
    char cad[MAX_BUFFER], *pal[50], buff[MAX_BUFFER];
    int numPal;
    
    if (gets(cad) == NULL) return NULL;
    separaPalabras(cad, pal, numPal);
    
    codV = new int;
    *codV = atoi(pal[0]);
    
    cant = atoi(pal[numPal-1]);
    
    codA = new char[MAX_CODART];
    strcpy(codA, pal[numPal - 2]);
    
    strcpy(buff,pal[1]);
    for (int i=2; i < numPal-2; i++){
        strcat(buff,"/");
        strcat(buff,pal[i]);
    }
    nombV = new char[strlen(buff) + 1];
    strcpy(nombV, buff);
    
}

void agregar (int *codV, char *nombV, char *codA, int cant,
              void *buffV[], int &numVend, char**codArt[],
              int *acumulado[], int tam[], int numD[])
{
    int ind = buscarVendedor(codV, buffV, numVend);
    if (ind == numVend){ //No lo encontramos
        buffV[ind] = crearReg(codV, nombV);
        numVend++;
    } else {
        delete[]codV;
        delete[]nombV;
    }
    agregarVenta(ind, codA, cant, codArt, acumulado, tam, numD);
}

int buscarVendedor (int *codV, void *buffV[], int numVend)
{
    int indice, *codigo;
    void **reg;
    for (indice = 0; indice < numVend; indice++){
        reg = (void **) buffV[indice];
        codigo = (int *) reg[0];
        if (*codigo == *codV) break;
    }
    return indice;
}

void *crearReg (int *codV, char *nombV)
{
    void **reg = new void*[4];
    
    reg[0] = codV;
    reg[1] = nombV;
    reg[2] = reg[3] = NULL;
    return reg;
}

void agregarVenta (int ind, char *codA, int cant, char **codArt[],
                   int *acumulado[], int tam[], int numD[])
{
    int i;
    if (codArt[ind] == NULL){
        codArt[ind] = new char*[INCREMENTO];
        acumulado[ind] = new int[INCREMENTO];
        codArt[ind][0] = NULL;
        tam[ind] = INCREMENTO;
        numD[ind] = 1;
    }
    for (i = 0; codArt[ind][i]; i++)
        if (strcmp(codA, codArt[ind][i]) == 0) break;
    if (codArt[ind][i] != NULL){ // lo encontré
        acumulado[ind][i] += cant;
        delete []codA;
    } else {
        if (numD[ind] == tam[ind]) //no lo encontré y está lleno
            aumentarEspacios(codArt[ind],acumulado[ind], tam[ind], numD[ind]);
        //agrega el numero producto
        codArt[ind][i] = codA;
        acumulado[ind][i] = cant;
        codArt[ind][i+1] = NULL;
        numD[ind]++;
    }
}

void aumentarEspacios( char **&codArt, int *&acumulado, int &tam, int &numD)
{
    char **auxCA;
    int *auxAcum;
    
    tam += INCREMENTO;
    auxCA = new char*[tam];
    auxAcum = new int[tam];
    for (int i = 0; i < numD; i++){
        auxCA[i] = codArt[i];
        auxAcum[i] = acumulado[i];
    }
    delete[]codArt;
    delete[]acumulado;
    codArt = auxCA;
    acumulado = auxAcum;
}

void separaPalabras (char *cadena, char**palabras,int &numPal)
{
    numPal=0;

    if(!isblank(cadena[0])){
        palabras[0]=cadena;
        numPal++;
    }

    for(int i=1; cadena[i]; i++){
    // verificamos si empieza una palabra
        if (!isblank(cadena[i]) && (isblank(cadena[i-1]) || cadena[i-1]==0) ){
            palabras[numPal]=&cadena[i];
            numPal++;
        }
    //Verificamos el fin de una palabra
        if (!isblank(cadena[i]) && isblank(cadena[i+1])){
            cadena[i+1]=0;
            i++;
        }
    }
}


void reporteDeVentas (void *vendedores)
{
    void **vend = (void **)vendedores;
    
    for (int i = 0; vend[i]; i++){
        impVendedor(vend[i]);
    }
} 

void impVendedor (void *vend)
{
    void **reg = (void **) vend;
    int *codV = (int *) reg[0];
    char *nombV = (char *) reg[1];
    char **codA = (char **) reg[2];
    int *acum = (int *) reg[3];
    
    printf("Codigo: %d\n", *codV);
    printf("Nombre: %s\n", nombV);
    for (int i=0; codA[i]; i++){
        printf("    %-20s %14d\n",codA[i],acum[i]);
    }
}
