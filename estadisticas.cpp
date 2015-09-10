#include <cstdio>
#include "ordenamiento.h"
#include "reportes.h"

void generarReporte(char tipo,int datosR[], double datosP[],
                       char datosL[], int cantDatos, int amplitud)
{
  int frecuencia;
  frecuencia = 0;
  putchar('\n');
  if (tipo == 'R'){
    int notaR;
    int total = 0;
    int modaCant = 0, modaNota;
    double promedio;
    ordenar(datosR,cantDatos);
    printf("%-8s%-10s\n","NOTA","FRECUENCIA");    
    notaR = datosR[0];
    for (int i = 0; i < cantDatos; i++){
      total += datosR[i];
      if (notaR == datosR[i])
        frecuencia++;
      else{
        printf(" %02d%10d\n",notaR,frecuencia);
        if (frecuencia >= modaCant){
          modaNota = notaR;
          modaCant = frecuencia;
        }
        frecuencia = 1;
        notaR = datosR[i];
      }
    }
    promedio = ((double) total )/ cantDatos;
    printf(" %02d%10d\n",notaR,frecuencia);
    printf("\nPROMEDIO: %4.2lf  MAYOR: %d  MENOR: %d   MODA: %d\n",\
            promedio,datosR[cantDatos-1], datosR[0], modaNota);
    
  } else if (tipo == 'P'){
    double inicio = 0;
    double fin = inicio + amplitud;
    ordenar(datosP,cantDatos);
    printf("RANGO DE NOTAS     FRECUENCIA\n");
    for (int i = 0; i < cantDatos; i++){
      if (fin >= 20) fin = 21;
      if ((datosP[i] >= inicio && datosP[i] < fin ) )
        frecuencia++;
      else{
        printf("  [%02d - %02d[    %9d\n",(int) inicio,(int) fin,frecuencia);
        frecuencia = 1;
        inicio += amplitud;
        fin += amplitud;
      }
    }
    if (fin >= 20)
      printf("  [%02d - 20]    %9d\n",(int) inicio, frecuencia);
    else
      printf("  [%02d - %02d[    %9d\n",(int) inicio,(int) fin,frecuencia);
    printf("\nMAYOR: %4.1lf  MENOR: %4.1lf\n",datosP[cantDatos-1],datosP[0]);
  } else if (tipo == 'L'){
    ordenar(datosL,cantDatos);
    char notaL = 'A';
    int modaCant = 0;
    char modaNota = 'A';
    printf("RESPUESTAS     FRECUENCA\n");
    for (int i = 0; i < cantDatos; i++){
      if (notaL == datosL[i])
        frecuencia++;
      else {
        printf("%5c%13s%2d\n",notaL," ",frecuencia);
        if (frecuencia >= modaCant){
          modaNota = notaL;
          modaCant = frecuencia;
        }
        frecuencia = 1;
        notaL++;
      }
    }
    printf("%5c%13s%2d\n",notaL," ",frecuencia);
    printf("\nMODA:  %c\n",modaNota);
  } else
    printf("ERROR!!!\n");
}
