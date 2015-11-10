/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 9 de noviembre de 2015, 11:11 AM
 */

#include <cstdlib>
#include <cstdio>

#define N 9

using namespace std;

/*
 * 
 */
int resolvertabla(char tabla[N][N]);

int buscarCasillavacia(char tabla[N][N], int &i, int &j);

int compruebaTabla(char tabla[N][N], int i, int j, int n);

void imprimir (char tabla[N][N]);

void reconfig(char tabla[N][N],char noT[N][N]);

int main(int argc, char** argv) {
    
    char tabla[N][N] = { {0,9,0, 3,0,5, 2,0,0},
                          {0,0,5, 0,6,4, 0,0,0},
                          {7,6,0, 9,0,0, 0,0,0},
                          {0,2,0, 0,0,0, 5,0,0},
                          {0,0,0, 2,0,0, 4,0,0},
                          {4,0,0, 0,0,0, 0,0,8},
                          {9,0,0, 0,7,0, 0,0,0},
                          {0,5,0, 0,0,0, 8,6,2},
                          {0,1,0, 0,0,2, 0,4,0}};
    char tabla_Not[N][N] = { {1,0,0, 0,1,0, 0,0,0},
                             {0,0,0, 0,0,0, 0,0,0},
                             {0,0,1, 0,0,1, 0,0,0},
                             {1,0,1, 1,1,1, 0,1,1},
                             {0,0,1, 0,1,1, 0,1,1},
                             {0,0,1, 1,0,1, 0,0,0},
                             {0,0,0, 1,0,1, 0,0,0},
                             {0,0,0, 1,1,1, 0,0,0},
                             {1,0,1, 0,0,0, 0,0,0}};

    char tabla2[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    
    imprimir(tabla);
    
    resolvertabla(tabla);
    
    //imprimir(tabla);
    
    reconfig(tabla,tabla_Not);
    
    imprimir(tabla);
    
    return 0;
}

int resolvertabla (char tabla[N][N]){
    //system("CLS");
    int i,j;
    if (!buscarCasillavacia(tabla,i,j)) return 1;
    for (int k = 1; k <= 9; k++){
        if (compruebaTabla(tabla,i,j,k)){
            tabla[i][j] = k;
            if (resolvertabla(tabla)) return 1;
            tabla[i][j] = 0;
        }
    }
    return 0;
}

int buscarCasillavacia(char tabla[N][N], int &i, int &j)
{
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++){
            if (tabla[i][j] == 0) return 1;
        }
    return 0;
}

int compruebaTabla(char tabla[N][N],int i, int j, int n)
{
    /*COMPRUEBA FILA*/
    
    for (int col = 0; col < N; col++)
        if (tabla[i][col] == n) return 0;
    
    /*COMPRUEBA COLUMNA*/
    for (int fil = 0; fil < N; fil++)
        if (tabla[fil][j] == n ) return 0;
    
    /*COMPRUEBA CUADRADO*/
    int fila_c = (i / 3);
    fila_c = fila_c * 3;
    int col_c = (j / 3);
    col_c = col_c * 3;
    for (int f = fila_c; f < fila_c+3; f++)
        for (int c = col_c; c < col_c+3; c++)
            if (tabla[f][c] == n ) return 0;
        
    return 1;
}

void imprimir (char tabla[N][N])
{
    printf("-----------------------------\n");
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf("%d  ",tabla[i][j]);
            if ((j+1) % 3 == 0) printf("|");
        }
        printf("\n");
        if ((i+1) % 3 == 0)
            printf("-----------------------------\n");
    }
    printf("\n");
    printf("\n");
}

void reconfig(char tabla[N][N], char tabla_not[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (tabla_not[i][j]) tabla[i][j] = 0;
}
