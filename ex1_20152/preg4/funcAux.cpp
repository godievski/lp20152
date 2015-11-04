/*
 * NOMBRE: DIEGO ALONSO GUARDIA AYALA
 * CODIGO: 20125849
 * 
 */

#include <cstdio>

/*FUNCION PARA CALCULA LA CANTIDAD DE SEMESTRES ENTRE DOS SEMESTRES
 *LOS DOS PRIMEROS DATOS CORRESPONDEN AL AÑO Y NUMERO DE SEMESTRE INICIAL(INGRESO)
 *Y LOS DOS ULTIMOS CORRESPONDEN AL AÑO Y NUMERO DE SEMESTRE FINAL(EGRESO)*/

int calcCantSem (int anhoIng, int semIng, int anhoEgr, int semEgr)
{   
    int cantSem = 2 * (anhoEgr - anhoIng + 1);
    if (semEgr == 1) cantSem--;
    if (semIng == 2) cantSem--;
    return cantSem;
}

/*FUNCION PARA IMPRIMIR 'N' VECES UN CHAR 'C'
 *EL PARAMETRO LN RECIBE 1 SI SE QUIERE UN SALTO DE LINEA AL FINAL
 *O 0 (CERO) SI SE QUIERE OMITIR UN SALTO DE LINEA AL FINAL*/
void printNChar(char c, int n, int ln)
{
    for (int i = 0; i < n; i++)
        putchar(c);
    if (ln) putchar('\n');
}