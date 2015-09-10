/*  CREANDO BIBLIOTECAS ESTÁTICAS!!!  */

int maximo (int a, int b, int c)
{
  int max = a;
  max = max > b ? max : b;
  max = max > c ? max : c;
  return max;
}
