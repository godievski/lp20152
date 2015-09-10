/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 4 de septiembre de 2015, 07:57 AM
 */

#include <cstdlib>
#include <cstdio>
#include "mylib.h"

#define MAX_NOM 30
#define MAX_LIN 90

int main(int argc, char** argv) {
    
    char c; //Para leer el nombre del empleado
    char fin; //detectar el fin de linea
    int cantCar;
    int codigo, anexo;
    int dd,mm,aa; //fecha
    double tiempo,tiempoParcial,tiempoTotal;
    int rpta;
    bool finEmp,finFecha;
    int ddI,mmI,aaI,ddF,mmF,aaF; //fecha inicio (I) y fecha fin (F)
    int fechaI,fechaF,fecha; //fechas
    int ddMax=0,mmMax=0,aaMax=0; //fecha donde hace más llamadas
    double tiempoMax; //tiempo maximo de llamadas en un dia
    int cantDias;    
    int rptaFecha;
    
    
    scanf("%d/%d/%d",&ddI,&mmI,&aaI);
    fechaI = aaI*10000 + mmI*100 + ddI;
    scanf("%d/%d/%d",&ddF,&mmF,&aaF);
    fechaF = aaF*10000 + mmF*100 + ddF;
    printf("          RESUMEN DE LLAMADAS TELEFÓNICAS entre la fecha %02d/%02d/%d y %02d/%02d/%d\n",ddI,mmI,aaI,ddF,mmF,aaF);
    impLinea('=',MAX_LIN);
    printf("%-10s%-30s%-10s%-10s%20s\n","Código","EMPLEADO","ANEXO","FECHA","  TIEMPOS");   
    
    while ((rpta = scanf("%d",&codigo)) != EOF){
        scanf("%*d");
        cantCar = 0;
        cantDias = 0;
        tiempoTotal = 0.0;
        tiempoMax = 0.0;
        impLinea('-',MAX_LIN);
        printf("%-10d",codigo);
        while (scanf("%d",&anexo) != 1){
						while ((c = getchar()) != ' '){
							putchar(c);
							cantCar++;
						}
            putchar(' ');
            cantCar++;
        }
        for (int i=0;i<MAX_NOM - cantCar;i++) putchar(' ');
        printf("%-10d",anexo);
        finEmp = false;
        finFecha = false;
				cantDias = 0;
        while (1){    
            tiempoParcial = 0.0;
                        
            rptaFecha = scanf("%d/%d/%d",&dd,&mm,&aa);
            if (rptaFecha == 2){
              aa = mm;
              mm = dd;
              dd = (int) tiempo;
            }
            scanf("%lf",&tiempo);
            fecha = aa*10000 + mm*100 + dd;
            if (tiempoMax != 0){
              for(int i = 0; i < 50 ; i++) putchar(' ');
            }
            if (fechaI <= fecha && fecha <= fechaF){
              printf("%02d/%02d/%d%20.2lf\n",dd,mm,aa,tiempo);
              tiempoParcial += tiempo;
              tiempoTotal += tiempo;
              cantDias++;
            }
            
            while (1){
                rpta = scanf("%lf%c",&tiempo,&fin);
                if (fin == '\n') {
                    finEmp = true;
                    if (fechaI <= fecha && fecha <= fechaF){
                        printf("%80.2lf\n",tiempo);
                        tiempoParcial += tiempo;
                        tiempoTotal += tiempo;
												impTiempoParcial(tiempoMax, tiempoParcial, ddMax, mmMax, aaMax,dd, mm, aa);
                    }
                    break;
                } else if (fin == '/') {
										if (fechaI <= fecha && fecha <= fechaF)
											impTiempoParcial(tiempoMax, tiempoParcial, ddMax, mmMax, aaMax,dd, mm, aa);
                    finFecha = true;
                    break;
                } else if (rpta == EOF)
                    break;
                else if (fechaI <= fecha && fecha <= fechaF){
                    tiempoParcial += tiempo;
                    printf("%80.2lf\n",tiempo);
                    tiempoTotal += tiempo;
                }
            }
            if (finEmp) {
                finFecha = false;
                if (cantDias == 0) putchar('\n');
                impLinea('*',MAX_LIN);
                printf("Resumen:\n");
                printf("  Tiempo total de llamadas: %10.2lf segundos ",tiempoTotal);
                impTiempo(tiempoTotal);
                putchar('\n');
                printf("  Dias contabilizados: %d \n",cantDias);
								if (cantDias == 0){
									printf("  Promedio: 0");	
									impTiempo(0.0);
								}
								else{
									printf("  Promedio: %10.2lf ", tiempoTotal/cantDias);
									impTiempo(tiempoTotal/cantDias);
								}                
                putchar('\n');
                printf("  Dia que mas llamo: %02d/%02d/%02d     ",ddMax,mmMax,aaMax);
                printf("Total del dia: %10.2lf ",tiempoMax);
                impTiempo(tiempoMax);
                putchar('\n');
                break;
            }  
            
        }
    }
    
    impLinea('=',MAX_LIN);
    
    return 0;
}


