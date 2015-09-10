#include <cstdio>

void printArray (int a[], int n)
{
  printf("Array:\n");
  for (int i = 0; i < n; i++)
    printf("%d ",a[i]);
  putchar('\n');
}

void printArray (double a[], int n)
{
  printf("Array:\n");
  for (int i = 0; i < n; i++){
    printf("%3.1lf ",a[i]);
  }
  putchar('\n');
}

void printArray (char a[], int n)
{
  printf("Array:\n");
  for (int i = 0; i < n; i ++){
    putchar(a[i]);
    putchar(' ');
  }
  putchar('\n');
}

void printChar (char c, int n)
{
  for (int i = 0; i < n; i++)
    putchar(c);
  putchar('\n');
}

void printTipo (char c)
{
  if (c == 'R')
    printf("Practicas\n");
  else if ( c == 'P')
    printf("Promedios\n");
  else if ( c == 'L')
    printf("Controles de lectura\n");
  else
    printf("ERROR!!!\n");
}

int lecturaDatos (char tipo, int datosR[], double datosP[], char datosL[])
{
  int cantDatos = 0;
  char c,cFin;
  if (tipo == 'R'){
    while (1){
      scanf("%d%c",&datosR[cantDatos],&cFin);
      cantDatos++;
      if (cFin == '\n') break;
    }
  }
  else if ( tipo == 'P'){
    while (1){
      scanf("%lf%c",&datosP[cantDatos],&cFin);
      cantDatos++;
      if (cFin == '\n') break;
    }

  }
  else if ( tipo == 'L'){
    while (1){
      scanf("%*d");
      scanf("%c%c",&c,&cFin);
      datosL[cantDatos++] = c;
      if (cFin == '\n') break;
    }
  }
  else
    return 0;
   
  return cantDatos;
}
