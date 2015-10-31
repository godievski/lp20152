/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 20 de octubre de 2015, 09:10 AM
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>

void funcNumArgVar (char* cadF, ...)
{
    void *ptDato;
    ptDato = &cadF;
    ptDato = (char **)ptDato + 1;
    int *ptInt;
    double *ptDb;
    char **ptStr;
    char *ptCh;
    for(int i = 0; cadF[i]; i++){
        switch(cadF[i]){
            case 'd':
                ptInt = (int *) ptDato;
                printf("<%d>",*ptInt);
                ptDato = (int*) ptDato + 1;
                break;
            case 'f':
                ptDb = (double*) ptDato;
                printf("<%lf>",*ptDb);
                ptDato = (double*)ptDato + 1;
                break;
            case 's':
                ptStr = (char **) ptDato;
                printf("<%s>",*ptStr);
                ptDato = (char**)ptDato + 1;
                break;
            case 'c':
                ptCh = (char *) ptDato;
                printf("<%c>",*ptCh);
                ptDato = (int*) ptDato + 1;
                break;
            default:
                putchar(cadF[i]);
                break;
        }
    }
}

int main(int argc, char** argv) {

    int a = 456, b = 72;
    double f=3.75 , g = 65.875;
    char cad[20], *st, ch1 = 'A', ch2 = 'W';
    strcpy(cad, "Juan Lopez");
    st = new char[30];
    strcpy(st, "Ana Paula");
    
    funcNumArgVar("d c f s d f c s",a,ch1,f,cad,b,g,ch2,st);
    
    putchar('\n');
    return 0;
}

