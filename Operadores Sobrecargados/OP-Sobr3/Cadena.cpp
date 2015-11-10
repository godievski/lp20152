#include <string.h>
#include <stdio.h>
#include "Cadena.h"

void Cadena::setCadena(char *c){
    cad = new char[strlen(c)+1];
    strcpy(cad,c);
}

char *Cadena::getCadena(void){
    char *aux = new char[strlen(cad)+1];
    strcpy(aux, cad);
    return aux;
}

void Cadena::operator +(Cadena c){
    char *aux= new char [strlen(cad)+strlen(c.cad)+1];
    strcpy(aux,cad);
    delete cad;
    cad=aux;
    strcat(cad, c.cad);
}

void Cadena::imprimeCad(void){
    printf("Cadena = %s\n",cad);
}

