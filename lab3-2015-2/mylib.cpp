
/*NOMBRE: Diego Alonso Guardia Ayala*/
/*Codigo: 20125849*/

#define PRECISION 0.005

#include "mylib.h"
#include <cstdio>

double raizDeEcuacion (double f[], double i, int cantidad)
{
    double x = 1;
    double x_ant = 0;
    double fx;
    double pendiente;
    double fi;

    while (1){
        //funcion originial
        fx = 0.0;
        for (int j = 1; j <= cantidad; j ++){
            fi =  f[j-1] * potencia(x, j);
            fx = fx + fi;
        }
        fx = fx - i;       

        
        if (valorAbsoluto(fx) <= PRECISION) {
            break;
        }

        //derivada
        pendiente = 0;
        for (int j = 1; j <= cantidad; j++){
            pendiente += j * f[j-1] * potencia(x, j - 1);
        }
        
        x = ((-1)*fx / pendiente) + x;
    }
    
    return x;
}

double tir (double f[], double i, int cantidad)
{
    double rpta;
    double raiz;
    raiz = raizDeEcuacion(f,i,cantidad);
    rpta = (1 / raiz) - 1;
    return rpta*100;
}

double potencia (double base, int potencia)
{
    if (base == 0) return 0;
    if (potencia == 0) return 1;
    double rpta = 1;
    for (int i = 1; i <= potencia;i++)
        rpta *= base;
    return rpta;
}

double valorAbsoluto (double n)
{
    if (n >= 0) return n;
    else return n*(-1);
}
