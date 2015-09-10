#include <cstdio>
#include <cstdlib>
#include "reportes.h"
#include "estadisticas.h"

#define MAX_LINE 100
#define MAX_LONG 1000

int main ()
{
  char c,cFin,tipoR;
  int rpta, rptaAmplitud;
  int codDocente, amplitud;
  int datosR[MAX_LONG];
  double datosP[MAX_LONG];
  char datosL[MAX_LONG];
  int cantDatos;
  bool nivelCurso;

  while (1){  //Nivel especialidad
    printChar('=',MAX_LINE);
    printf("Especialidad:  ");
    while ( (c = getchar()) != '\n' ){
      putchar(c);
    }
    putchar('\n');
    cFin = '0';
    while(1){ //Nivel docente
      printChar('-',MAX_LINE);
      printf("Docente:  ");
      scanf("%d",&codDocente);
      /*AGREGANDO CHAR CFIN PORQUE LEYO UN NUMERO*/
      codDocente = (cFin - '0')*10000000 + codDocente;

      scanf("%*d");
      while ( (c = getchar()) != '\n' ){
        printf("%c",c);
      }
      printf("  (%08d) \n",codDocente);
      nivelCurso = false;
      while (1){  //Nivel curso
        printChar('*',MAX_LINE);
        printf("Estadisticas del curso:  ");
        if (nivelCurso) putchar(cFin);
        while (1){
          c = getchar();
          if (c == ' ' || c == '\t') break;
          printf("%c",c);
        }
        printf(" - ");
        scanf("%*d");
        tipoR = getchar();
        if (tipoR == 'P') scanf("%*d");
        rptaAmplitud = scanf("(%d)",&amplitud);
        if (!rptaAmplitud) amplitud = 5;
        printTipo(tipoR);
        cantDatos = lecturaDatos(tipoR, datosR, datosP, datosL);
        generarReporte(tipoR, datosR, datosP, datosL, cantDatos, amplitud);
        cFin = getchar();
        if (cFin == '\n') break;
        else if (cFin >= '0' && cFin <= '9') break;
        else nivelCurso = true;
      }
      if (cFin == '\n') break;
    }
    if (cFin == '\n'){
      rpta = scanf("%*d");
      if (rpta == EOF) break;
    }
  }

  return 0;
}
