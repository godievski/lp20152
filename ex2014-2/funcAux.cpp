#include <cctype>
#include <cstdio>
#include "funcAux.h"

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
        if (!isblank(buffer[i]) && isblank(buffer[i+1])){
            buffer[i+1] = 0;
            i++;
        }
    }
}

void printNChar (char c, int n, int ln)
{
    for (int i = 0; i < n; i++) putchar(c);
    if (ln) putchar('\n');
}

void myQSort (void **array, int n, int (*funcCmp) (const void*, const void*))
{
    int i = 0;
    int piv = n - 1;
    int j = piv - 1;
    if (n <= 1) return;
    
    while (i <= j){
        if (funcCmp(array[piv],array[i]) < 0 
         && funcCmp(array[piv],array[j]) > 0){
            swap(array, i, j);
            i++;
            j--;
            continue;
        }
        if (funcCmp(array[piv],array[i]) >= 0)
            i++;
        if (funcCmp(array[piv],array[j]) <= 0)
            j--;
    }
    swap(array, piv, i);
    myQSort(array, i, funcCmp);
    myQSort(&(array[i]), n - i, funcCmp);
}

void swap (void **array, int i, int j)
{
    void *aux;
    aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}