/*BUSQUEDA Y ORDENACION*/
#include <cstring>
#include "myfunc.h"

/*PRIVATE'S HEADERS*/
void _myQuickSort (void **, int);

void swap (void **, int, int);

/*PUBLIC*/
int buscarEnArray (void *datos, char *palabra)
{
    void **arrayDatos = (void **) datos;
    void **reg;
    int indice;
    for (indice = 0; arrayDatos[indice]; indice++){
        reg = (void **) arrayDatos[indice];
        char *dato = (char *) reg[0];
        if (strcmp(dato, palabra) == 0) break;
    }
    return indice;
}

void myQuickSort (void *datos)
{
  int cant;
  void **arrayDatos = (void **) datos;
  
  for (cant = 0; arrayDatos[cant]; cant++);
  
  _myQuickSort (arrayDatos, cant);
}


/*PRIVATE*/
void _myQuickSort (void **arrayDatos, int cant)
{
  void **reg, *aux;
  char *datoPivo, *datoI, *datoJ;
  
  
  int pivote = cant - 1;
  int i = 0, j = pivote - 1;
  
  if (cant <= 1) return;
  
  reg = (void **) arrayDatos[pivote];
  datoPivo = (char *) reg[0];
  while ( i <= j){
      reg = (void **) arrayDatos[i];
      datoI = (char *) reg[0];
      reg = (void **) arrayDatos[j];
      datoJ = (char *) reg[0];
      if (strcmp(datoI,datoPivo) == 1 && strcmp(datoPivo,datoJ) == 1){
          swap(arrayDatos, i, j);
          i++;
          j--;
          continue;
      }
      if (strcmp(datoPivo, datoI) >= 0)
        i++;
      if (strcmp(datoJ, datoPivo) >= 0)
        j--;
  }
  swap(arrayDatos, i, pivote);

  _myQuickSort(arrayDatos,i);
  _myQuickSort(&arrayDatos[i],cant-i);
  
}

void swap (void **array, int i, int j)
{
  void *aux;
  aux = array[i];
  array[i] = array[j];
  array[j] = aux;
}