/*
 * Nombres: DIEGO ALONSO GUARDIA AYALA
 * Codigo: 20125849
 */
#include "funAux.h"

int obtieneNombres(char *buff, Cadena &,Cadena &,Cadena & );
int func_comp (const void*, const void*);

void leeNombres (ifstream &arch, Cadena *personas, int &cant)
{
    Cadena ap1(50);
    Cadena ap2(50);
    Cadena nomb(50);
    cant = 0;
    char buff[200];
    while (arch.getline(buff,200)){
        obtieneNombres(buff, ap1, ap2, nomb);
        ap1.append("/");
        ap2.append("/");
        personas[cant] = ap1 + ap2 + nomb;;
        cant++;
    }
}

void ordenaNombres (Cadena *personas, int cant)
{
    /*
     *
    qsort (personas, cant, sizeof(Cadena), func_comp);
    */
    /*MY QSORT*/
    int piv = cant - 1;
    int j = piv - 1;
    int i = 0;
    if (cant <= 1)
        return;
    while (i <= j){
        int cmpI, cmpJ;
        cmpI = personas[i] > personas[piv];
        cmpJ = personas[j] < personas[piv];
        if (cmpI && cmpJ){
            personas[i].swap(personas[j]);
            i++;
            j--;
            continue;
        }
        if (!cmpI)
            i++;
        if (!cmpJ)
            j--;
    }
    personas[i].swap(personas[piv]);
    ordenaNombres (personas, i);
    ordenaNombres (&(personas[i]), cant - i);
}

void impNombres (Cadena *personas, int cant)
{
    for (int i = 0; i < cant; i++){
        personas[i].print();
        cout << endl;
    }
}

int obtieneNombres (char *buff, Cadena &p1,Cadena &p2,Cadena &nomb)
{
    char *palabras[5];
    int cantPal = 0;
    if (!isblank(buff[0])){
        palabras[0] = buff;
        cantPal++;
    }
    for (int i = 1; buff[i]; i++){
        if (!isblank(buff[i]) && (isblank(buff[i-1]) || buff[i-1] == 0 ) ){
            palabras[cantPal] = &(buff[i]);
            cantPal++;
        }
        if (!isblank(buff[i]) && isblank(buff[i+1])){
            buff[i+1] = 0;
            i++;
        }
    }
    p1 = palabras[0];
    p2 = palabras[1];
    nomb = palabras[2];
}

int func_comp (const void*a, const void*b)
{
    return ((Cadena*)a)->compare(*(Cadena*)b);
}