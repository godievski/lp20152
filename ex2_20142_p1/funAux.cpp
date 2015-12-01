
#include "funAux.h"

#include <cctype>

void separaPalabras(char* linea, char** palabras, int& cantPal)
{
    cantPal = 0;
    if (!isblank(linea[0])){
        palabras[0] = linea;
        cantPal++;
    }
    for (int i = 1; linea[i]; i++){
        if (!isblank(linea[i]) && (isblank(linea[i-1]) || linea[i-1] == 0)){
            palabras[cantPal] = &(linea[i]);
            cantPal++;
        }
        if (!isblank(linea[i]) && isblank(linea[i+1])){
            linea[i+1] = 0;
            i++;
        }
    }
}
