/*ORDENANDO!!!*/
#include <cstdio>
#include "reportes.h"

/*QUICKSORT*/
template <typename data>
void ordenar(data array[], int n)
{
  int pivote = n - 1;
  data aux;
  int i = 0, j = pivote - 1;
  if (n <= 1) return;

  while (i <= j){
    if (array[i] > array[pivote] && array[j] < array[pivote]){
      aux = array[i];
      array[i] = array[j];
      array[j] = aux;
      i++;
      j--;
    } 
    if (array[i] <= array[pivote])
      i++;
    if (array[j] >= array[pivote])
      j--;
  }

  aux = array[i];
  array[i] = array[pivote];
  array[pivote] = aux;

  ordenar(array, i);
  ordenar(&array[i], n - i);
}

template void ordenar(int [], int);
template void ordenar(double [], int);
template void ordenar(char [], int);
