/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 18 de septiembre de 2015, 08:35 AM
 */

#include <cstdlib>
#include <cstdio>

#include "mylib.h"

#define MAX_FLUJO 50
#define MAX_NOMBRE 40


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    double tasa;
    double inversion;
    double flujo[MAX_FLUJO] = {0};
    char c;
    int espacios,cantidad;
    double mi_tir;
    int rpta;
    
    scanf("%lf",&tasa);
    printf("Tasa de corte: %4.2lf\n",tasa);
    printf("%-30s     %10s     %10s","PROYECTO", "TIR", "COMENTARIOS\n");
    
    while(1){
        espacios = 0;
        while (scanf("%lf",&inversion) == 0){
					while (1){
	          c = getchar();
	          putchar(c);
	          espacios++;
						if (c == ' ' || c == '\t') break;
					}
        }
        for (int i = 0; i < MAX_NOMBRE - espacios; i++) putchar(' ');
        cantidad = 0;
        while (1){
            scanf("%lf%c",&flujo[cantidad],&c);
            cantidad++;
            if (c=='\n') break;
            
        }
        mi_tir = tir (flujo, inversion, cantidad);
        printf("%5.2lf     ",mi_tir);
        if (mi_tir >= tasa) printf("APROBADO\n");
        else printf("RECHAZADO\n");
        if (scanf("%*d") == EOF) break; //determina el fin de archivo
    }
   
    
    return 0;
}


